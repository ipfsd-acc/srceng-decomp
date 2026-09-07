// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmemdl.cpp
// Functions: 20
// ============================================================

#include "movieobjects\dmemdl.h"

//------------------------------------------------------------------------------
// Address: 0x00557260
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x00557270
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005573C0
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (const bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x00557450
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00557500
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00557580
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00557600
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00557750
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00557840
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00557870
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005578C0
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005578F0
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x00557940
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00557960
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x005772C0
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x005AD830
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0410
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AD860
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD870
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0420
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005AE400
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x005AE410
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (const int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (const int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (const int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (const int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (const float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005AE560
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x005AE5F0
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AE6A0
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005AE720
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005AE7A0
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AE8F0
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AE9E0
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AEA10
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AEA60
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005AEA90
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x005AEAE0
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AEB00
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x0067F020
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682920
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F050
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F060
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682930
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104F1170
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x104F1180
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x104F12D0
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x104F1360
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F1410
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x104F1490
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::SetUpBones(
        CDmeMDL *this@<ecx>,
        int a2@<edi>,
        const matrix3x4_t *shapeToWorld,
        matrix3x4_t *nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF
  int savedregs; // [esp+64h] [ebp+0h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    a2: (int)&savedregs,
    a3: a2,
    a4: (int)this,
    (CBoneSetup *)&rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104F1510
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  matrix3x4_t *numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = (matrix3x4_t *)pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, a2: (int)this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, a2: (int)this, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: nullptr);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F1660
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104F1750
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F1780
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F17D0
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFF);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x104F1800
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x104F1850
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104F1870
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x105C8080
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 0x6ECu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD2F0
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C80B0
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C80C0
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD300
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0055F980
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x0055F990
// Name: public: void CDmeMDL::DrawInEngine(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::DrawInEngine(CDmeMDL *this, bool bDrawInEngine)
{
  this->m_bDrawInEngine = bDrawInEngine;
}

//------------------------------------------------------------------------------
// Address: 0x0055FA00
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0055FB50
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (const bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x0055FBE0
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055FC90
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0055FD10
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0055FD90
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: &rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055FEE0
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0055FFD0
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00560000
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00560050
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00560080
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x005600D0
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005600F0
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x0059CB10
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F640
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059CB40
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059CB50
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F650
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005ADA10
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x005ADA20
// Name: public: void CDmeMDL::DrawInEngine(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::DrawInEngine(CDmeMDL *this, bool bDrawInEngine)
{
  this->m_bDrawInEngine = bDrawInEngine;
}

//------------------------------------------------------------------------------
// Address: 0x005ADA30
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x005ADA90
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005ADBE0
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x005ADC70
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ADD20
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005ADDA0
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005ADE20
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ADF70
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AE060
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE090
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE0E0
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005AE110
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x005AE160
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AE180
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x005F1C20
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4AD0
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F1C50
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1C60
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4AE0
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00518AF0
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x00518B00
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x00518C50
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x00518CE0
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00518D90
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00518E10
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00518E90
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00518FE0
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005190D0
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519100
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519150
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00519180
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x005191D0
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005191F0
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x0053C110
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x0056BC00
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB00
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056BC30
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BC40
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB10
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0051E440
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x0051E450
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x0051E4B0
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (const float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0051E600
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (const bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x0051E690
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E740
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0051E7C0
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0051E840
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E990
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051EA80
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051EAB0
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051EB00
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0051EB30
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x0051EB80
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051EBA0
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD10
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC30
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD40
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD50
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC40
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DBE50
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x005DBE60
// Name: public: void CDmeMDL::DrawInEngine(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::DrawInEngine(CDmeMDL *this, bool bDrawInEngine)
{
  this->m_bDrawInEngine = bDrawInEngine;
}

//------------------------------------------------------------------------------
// Address: 0x005DBE70
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (const int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (const int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (const int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (const int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (const float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005DBFD0
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x005DC060
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DC110
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005DC190
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005DC210
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DC360
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DC450
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DC480
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DC4D0
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005DC500
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x005DC550
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005DC570
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x006B0EC0
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5440
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0EF0
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0F00
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5450
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0051F560
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x0051F570
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x0051F5D0
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (const float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0051F720
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x0051F7B0
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F860
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0051F8E0
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0051F960
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FAB0
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051FBA0
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FBD0
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FC20
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0051FC50
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x0051FCA0
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051FCC0
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x0057DCF0
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580C10
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD20
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD30
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580C20
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A6960
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x005A6970
// Name: public: void CDmeMDL::DrawInEngine(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::DrawInEngine(CDmeMDL *this, bool bDrawInEngine)
{
  this->m_bDrawInEngine = bDrawInEngine;
}

//------------------------------------------------------------------------------
// Address: 0x005A6980
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x005A69E0
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x005A6B30
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x005A6BC0
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A6C70
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005A6CF0
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005A6D70
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A6EC0
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A6FB0
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6FE0
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7030
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005A7060
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x005A70B0
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005A70D0
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x005EAAD0
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED970
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EAB00
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAB10
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED980
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00527580
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x00527590
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x005275F0
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (const int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (const int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (const int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (const int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (const float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x00527740
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x005277D0
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00527880
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00527900
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00527980
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00527AD0
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00527BC0
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527BF0
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527C40
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00527C70
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x00527CC0
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00527CE0
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x0057B5A0
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 1772,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E320
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057B5D0
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B5E0
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E330
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062A3B0
// Name: public: unsigned short CDmeMDL::GetMDL(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDmeMDL::GetMDL(CDmeMDL *this)
{
  return CMDL::GetMDL(this: &this->m_MDL);
}

//------------------------------------------------------------------------------
// Address: 0x0062A3C0
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x0062A420
// Name: protected: void CDmeMDL::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::OnConstruction(CDmeMDL *this)
{
  CDmaColor *p_m_Color; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  Color value; // [esp+Ch] [ebp-4h] BYREF

  p_m_Color = &this->m_Color;
  *(_WORD *)&this->m_bDrawInEngine = 0;
  value = (Color)-1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  p_m_Color->m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "skin", type: AT_INT, pMemory: &this->m_nSkin);
  this->m_nSkin.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  value = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "body", type: AT_INT, pMemory: &this->m_nBody);
  this->m_nBody.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  value = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "sequence", type: AT_INT, pMemory: &this->m_nSequence);
  this->m_nSequence.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, (int *)&value);
  value = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "lod", type: AT_INT, pMemory: &this->m_nLOD);
  this->m_nLOD.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, (int *)&value);
  value = (Color)1106247680;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "playbackrate",
         type: AT_FLOAT,
         pMemory: &this->m_flPlaybackRate);
  this->m_flPlaybackRate.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, (float *)&value);
  value = 0;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_FLOAT, pMemory: &this->m_flTime);
  this->m_flTime.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  this->m_vecViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "viewTarget",
                                         type: AT_VECTOR3,
                                         pMemory: &this->m_vecViewTarget);
  this->m_bWorldSpaceViewTarget.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "worldSpaceViewTarget",
                                                 type: AT_BOOL,
                                                 pMemory: &this->m_bWorldSpaceViewTarget);
}

//------------------------------------------------------------------------------
// Address: 0x0062A570
// Name: public: void CDmeMDL::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetMDL(CDmeMDL *this, int handle)
{
  unsigned __int16 MDL; // ax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v5; // ecx
  int m_Storage; // [esp-4h] [ebp-30h]
  Vector vecMins; // [esp+8h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-18h] BYREF
  Vector vecLookAt; // [esp+20h] [ebp-Ch] BYREF

  CMDL::SetMDL(this: &this->m_MDL, h: handle);
  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins: &vecMins, pMaxs: &vecMaxs, h: MDL, nSequence: m_Storage);
  m_pAttribute = this->m_vecViewTarget.m_pAttribute;
  vecLookAt.x = 100.0;
  vecLookAt.y = 0.0;
  vecLookAt.z = vecMaxs.z;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &vecLookAt);
  v5 = this->m_bWorldSpaceViewTarget.m_pAttribute;
  HIBYTE(handle) = 0;
  CDmAttribute::SetValue<bool>(this: v5, value: (const bool *)&handle + 3);
}

//------------------------------------------------------------------------------
// Address: 0x0062A600
// Name: public: void CDmeMDL::GetBoundingBox(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *pMins, Vector *pMaxs)
{
  unsigned __int16 MDL; // ax
  int m_Storage; // [esp-4h] [ebp-58h]
  matrix3x4_t engineToDme; // [esp+Ch] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecMins; // [esp+48h] [ebp-Ch] BYREF

  m_Storage = this->m_nSequence.m_Storage;
  MDL = CMDL::GetMDL(this: &this->m_MDL);
  GetMDLBoundingBox(pMins, pMaxs, h: MDL, nSequence: m_Storage);
  if ( !this->m_bDrawInEngine )
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    TransformAABB(
      transform: &engineToDme,
      vecMinsIn: pMins,
      vecMaxsIn: pMaxs,
      vecMinsOut: &vecMins,
      vecMaxsOut: &vecMaxs);
    *pMins = vecMins;
    *pMaxs = vecMaxs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062A6B0
// Name: private: void CDmeMDL::UpdateMDL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::UpdateMDL(CDmeMDL *this)
{
  int m_Storage; // edx
  int v2; // eax
  double v3; // st7
  int v4; // edx
  int v5; // eax

  this->m_MDL.m_Color = this->m_Color.m_Storage;
  m_Storage = this->m_nSkin.m_Storage;
  this->m_MDL.m_flPlaybackRate = this->m_flPlaybackRate.m_Storage;
  v2 = this->m_nBody.m_Storage;
  v3 = this->m_flTime.m_Storage;
  this->m_MDL.m_nSkin = m_Storage;
  this->m_MDL.m_flTime = v3;
  v4 = this->m_nSequence.m_Storage;
  this->m_MDL.m_nBody = v2;
  v5 = this->m_nLOD.m_Storage;
  this->m_MDL.m_nSequence = v4;
  this->m_MDL.m_nLOD = v5;
  this->m_MDL.m_vecViewTarget = this->m_vecViewTarget.m_Storage;
  this->m_MDL.m_Color = this->m_Color.m_Storage;
  this->m_MDL.m_bWorldSpaceViewTarget = this->m_bWorldSpaceViewTarget.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0062A730
// Name: public: void CDmeMDL::SetUpBones(struct matrix3x4_t const __near &,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::SetUpBones(
        CDmeMDL *this,
        const matrix3x4_t *shapeToWorld,
        int nMaxBoneCount,
        matrix3x4_t *pOutputMatrices)
{
  matrix3x4_t engineToDme; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t rootToWorld; // [esp+34h] [ebp-30h] BYREF

  CDmeMDL::UpdateMDL(this);
  if ( this->m_bDrawInEngine )
  {
    MatrixCopy(in: shapeToWorld, out: &rootToWorld);
  }
  else
  {
    CDmeDag::EngineToDmeMatrix(&engineToDme, bZUp: this->m_bZUp);
    ConcatTransforms(in1: &engineToDme, in2: shapeToWorld, out: &rootToWorld);
  }
  CMDL::SetUpBones(
    this: &this->m_MDL,
    &rootToWorld,
    nMaxBoneCount,
    pBoneToWorld: pOutputMatrices,
    pPoseParameters: nullptr,
    pSequenceLayers: nullptr,
    nNumSequenceLayers: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0062A7B0
// Name: public: virtual void CDmeMDL::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMDL::Draw(
        CDmeMDL *this@<ecx>,
        int a2@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  studiohdr_t *StudioHdr; // ebx
  IMatRenderContext *v6; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  matrix3x4_t *v8; // ebx
  int numbones; // [esp-Ch] [ebp-28h]
  CMatRenderData<matrix3x4_t> rdPoseToWorld; // [esp+8h] [ebp-14h] BYREF
  studiohdr_t *pStudioHdr; // [esp+18h] [ebp-4h]

  CDmeMDL::UpdateMDL(this);
  StudioHdr = CMDL::GetStudioHdr(this: &this->m_MDL);
  pStudioHdr = StudioHdr;
  if ( StudioHdr != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CCW);
    LockRenderData = v6->LockRenderData;
    rdPoseToWorld.m_nCount = StudioHdr->numbones;
    rdPoseToWorld.m_pRenderContext = v6;
    v8 = (matrix3x4_t *)LockRenderData(this: v6, a2: 48 * rdPoseToWorld.m_nCount);
    numbones = pStudioHdr->numbones;
    rdPoseToWorld.m_pRenderData = v8;
    rdPoseToWorld.m_bNeedsUnlock = true;
    CDmeMDL::SetUpBones(this, shapeToWorld, nMaxBoneCount: numbones, pOutputMatrices: v8);
    CMDL::Draw(this: &this->m_MDL, rootToWorld: shapeToWorld, pBoneToWorld: v8, flags: 0);
    if ( !this->m_bDrawInEngine )
      v6->CullMode(this: v6, a2: MATERIAL_CULLMODE_CW);
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&rdPoseToWorld);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062A900
// Name: protected: CDmeMDL::CDmeMDL(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMDL *__thiscall CDmeMDL::CDmeMDL(
        CDmeMDL *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->__vftable = (CDmeMDL_vtbl *)&CDmeMDL::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nSkin.m_pAttribute = nullptr;
  this->m_nSkin.m_Storage = 0;
  this->m_nBody.m_pAttribute = nullptr;
  this->m_nBody.m_Storage = 0;
  this->m_nSequence.m_pAttribute = nullptr;
  this->m_nSequence.m_Storage = 0;
  this->m_nLOD.m_pAttribute = nullptr;
  this->m_nLOD.m_Storage = 0;
  this->m_flPlaybackRate = 0;
  this->m_flTime = 0;
  this->m_vecViewTarget.m_pAttribute = nullptr;
  this->m_vecViewTarget.m_Storage.x = 0.0;
  this->m_vecViewTarget.m_Storage.y = 0.0;
  this->m_vecViewTarget.m_Storage.z = 0.0;
  this->m_bWorldSpaceViewTarget.m_pAttribute = nullptr;
  this->m_bWorldSpaceViewTarget.m_Storage = false;
  CMDL::CMDL(this: &this->m_MDL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062A9F0
// Name: public: virtual bool CDmeMDL::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDL::IsA(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062AA20
// Name: public: virtual int CDmeMDL::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::GetInheritanceDepth(CDmeMDL *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDL::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062AA70
// Name: protected: virtual void CDmeMDL::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformDestruction(CDmeMDL *this)
{
  CMDL::SetMDL(this: &this->m_MDL, h: 0xFFFFu);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0062AAA0
// Name: protected: virtual int CDmeMDL::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDL::AllocatedSize(CDmeMDL *this)
{
  return 1772;
}

//------------------------------------------------------------------------------
// Address: 0x0062AAF0
// Name: protected: virtual void CDmeMDL::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::PerformConstruction(CDmeMDL *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeShape::OnConstruction(this);
  CDmeMDL::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062AB10
// Name: public: virtual void CDmeMDL::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDL::GetBoundingBox(CDmeMDL *this, Vector *min, Vector *max)
{
  CDmeMDL::GetBoundingBox(this, pMins: min, pMaxs: max);
}

//------------------------------------------------------------------------------
// Address: 0x006B94B0
// Name: _dynamic_initializer_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDL::s_Allocator,
    blockSize: 0x6ECu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDL pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD120
// Name: _dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDL::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDL::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B94E0
// Name: _dynamic_initializer_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDL_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDL_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B94F0
// Name: _dynamic_initializer_for__g_CDmeMDL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDL_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDL_Helper,
           classname: "DmeMDL",
           pFactory: &g_CDmeMDL_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD130
// Name: _dynamic_atexit_destructor_for__g_CDmeMDL_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDL_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMDL_Factory.m_CallBackList);
}

} // namespace vmap
