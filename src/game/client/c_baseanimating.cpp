// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_baseanimating.cpp
// Functions: 265
// ============================================================

#include "game\client\c_baseanimating.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: static void C_BaseAnimating::ShutdownBoneSetupThreadPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ShutdownBoneSetupThreadPool(vgui::PropertyPage *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001400
// Name: public: char const __near * CStudioHdr::name(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStudioHdr::name(CStudioHdr *this)
{
  const studiohdr_t *m_pStudioHdr; // edx
  int studiohdr2index; // eax
  int v3; // ecx
  char *v4; // eax
  int v5; // ecx

  m_pStudioHdr = this->m_pStudioHdr;
  studiohdr2index = this->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index == 0 )
    return m_pStudioHdr->name;
  v3 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8];
  v4 = (char *)m_pStudioHdr + studiohdr2index;
  if ( v3 == 0 || &v4[v3] == nullptr )
    return m_pStudioHdr->name;
  v5 = *((_DWORD *)v4 + 5);
  if ( v5 != 0 )
    return &v4[v5];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010C90
// Name: public: float C_BaseAnimating::SequenceDuration(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall C_BaseAnimating::SequenceDuration(C_BaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return C_BaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence);
}

//------------------------------------------------------------------------------
// Address: 0x10010D40
// Name: public: float C_BaseAnimating::SequenceDuration(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall C_BaseAnimating::SequenceDuration(C_BaseAnimating *this)
{
  int m_nSequence; // edi
  CStudioHdr *m_pStudioHdr; // eax

  m_nSequence = this->m_nSequence;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return C_BaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_nSequence);
}

//------------------------------------------------------------------------------
// Address: 0x100247A0
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100247F0
// Name: void __near * MemAlloc_ReallocAligned(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl MemAlloc_ReallocAligned(unsigned __int8 *ptr, unsigned int size, unsigned int align)
{
  void *v4; // ebx
  unsigned int v5; // esi
  unsigned __int8 *pResult; // [esp+10h] [ebp+10h]

  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( ((align - 1) & (unsigned int)ptr) != 0 )
    return nullptr;
  if ( ptr == nullptr )
    return (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  v4 = *(void **)(((unsigned int)ptr & 0xFFFFFFFC) - 4);
  v5 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v4);
  if ( v5 >= ptr - (_BYTE *)v4 + size )
    return ptr;
  pResult = (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  memcpy(dst: pResult, src: ptr, count: v5 - (ptr - (_BYTE *)v4));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x10024890
// Name: public: ShaderStencilState_t::ShaderStencilState_t(void)
// Source: json
//------------------------------------------------------------------------------
ShaderStencilState_t *__thiscall ShaderStencilState_t::ShaderStencilState_t(ShaderStencilState_t *this)
{
  this->m_ZFailOp = SHADER_STENCILOP_KEEP;
  this->m_FailOp = SHADER_STENCILOP_KEEP;
  this->m_PassOp = SHADER_STENCILOP_KEEP;
  this->m_bEnable = false;
  this->m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
  this->m_nReferenceValue = 0;
  this->m_nWriteMask = -1;
  this->m_nTestMask = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100248C0
// Name: public: bool CJob::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CJob::IsFinished(CJob *this)
{
  int m_status; // eax

  m_status = this->m_status;
  return m_status != 1 && m_status != 2 && m_status != 4;
}

//------------------------------------------------------------------------------
// Address: 0x100248E0
// Name: public: bool C_AnimationLayer::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_AnimationLayer::IsActive(C_AnimationLayer *this)
{
  return this->m_nOrder != 15;
}

//------------------------------------------------------------------------------
// Address: 0x10024960
// Name: public: virtual class ClientClass __near * C_BaseAnimating::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseAnimating::GetClientClass(C_BaseAnimating *this)
{
  return &__g_C_BaseAnimatingClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10024970
// Name: public: virtual struct datamap_t __near * C_BaseAnimating::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseAnimating::GetPredDescMap(C_BaseAnimating *this)
{
  return &C_BaseAnimating::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10024980
// Name: public: virtual struct datamap_t __near * C_ClientRagdoll::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_ClientRagdoll::GetDataDescMap(C_ClientRagdoll *this)
{
  return &C_ClientRagdoll::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10024990
// Name: public: virtual struct ScriptClassDesc_t __near * C_BaseAnimating::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall C_BaseAnimating::GetScriptDesc(C_BaseAnimating *this)
{
  return GetScriptDesc<C_BaseAnimating>(__formal: this);
}

//------------------------------------------------------------------------------
// Address: 0x100249B0
// Name: public: bool Vector::operator==(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::operator==(QAngle *this, const QAngle *src)
{
  return src->x == this->x && src->y == this->y && src->z == this->z;
}

//------------------------------------------------------------------------------
// Address: 0x100249F0
// Name: public: virtual void C_ClientRagdoll::OnPVSStatusChanged(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::OnPVSStatusChanged(C_ClientRagdoll *this, bool bInPVS)
{
  C_BaseEntity *v2; // ecx

  v2 = (C_ClientRagdoll *)((char *)this - 3256);
  if ( bInPVS )
    C_BaseEntity::CreateShadow(this: v2);
  else
    C_BaseEntity::DestroyShadow(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10024A20
// Name: public: virtual void C_ClientRagdoll::SUB_Remove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::SUB_Remove(C_ClientRagdoll *this)
{
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // edx

  SetNextClientThink = this->SetNextClientThink;
  this->m_bFadingOut = true;
  ((void (__stdcall *)(int))SetNextClientThink)(a1: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x10024A40
// Name: public: virtual int C_BaseAnimating::GetRenderFlags(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseAnimating::GetRenderFlags(C_BaseAnimating *this)
{
  IVModelInfoClient_vtbl *v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = modelinfo->__vftable;
  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 20))(a1: (char *)this - 4);
  v4 = ((int (__thiscall *)(C_BaseAnimating *, int))this->GetAbsOrigin)(a1: this, a2: v3);
  v5 = ((int (__thiscall *)(C_BaseAnimating *, int))this->KeyValue)(a1: this, a2: v4);
  v6 = ((int (__thiscall *)(C_BaseAnimating *, int))this->GetClientThinkable)(a1: this, a2: v5);
  return ((unsigned __int8 (__thiscall *)(IVModelInfoClient *, int))v2->IsUsingFBTexture)(a1: modelinfo, a2: v6) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10024AA0
// Name: private: void C_BaseAnimating::AddBaseAnimatingInterpolatedVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::AddBaseAnimatingInterpolatedVars(C_BaseAnimating *this)
{
  int v2; // edi

  C_BaseEntity::AddVar(
    this,
    data: this->m_flEncodedController,
    watcher: &this->m_iv_flEncodedController,
    type: 1,
    bSetup: true);
  v2 = 1;
  if ( this->m_bClientSideAnimation )
    v2 = 9;
  C_BaseEntity::AddVar(
    this,
    data: this->m_flPoseParameter,
    watcher: &this->m_iv_flPoseParameter,
    type: v2,
    bSetup: true);
  C_BaseEntity::AddVar(this, data: &this->m_flCycle, watcher: &this->m_iv_flCycle, type: v2, bSetup: true);
}

//------------------------------------------------------------------------------
// Address: 0x10024B10
// Name: public: virtual void C_BaseAnimating::GetBoneControllers(float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetBoneControllers(C_BaseAnimating *this, float *controllers)
{
  *(_OWORD *)controllers = *(_OWORD *)this->m_flEncodedController;
}

//------------------------------------------------------------------------------
// Address: 0x10024B40
// Name: public: virtual void C_BaseAnimating::GetPoseParameters(class CStudioHdr __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetPoseParameters(C_BaseAnimating *this, CStudioHdr *pStudioHdr, float *poseParameter)
{
  int v4; // esi
  float *m_flPoseParameter; // edi

  if ( pStudioHdr != nullptr )
  {
    v4 = 0;
    if ( CStudioHdr::GetNumPoseParameters(this: pStudioHdr) > 0 )
    {
      m_flPoseParameter = this->m_flPoseParameter;
      do
        poseParameter[v4++] = *m_flPoseParameter++;
      while ( v4 < CStudioHdr::GetNumPoseParameters(this: pStudioHdr) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024B80
// Name: float RemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapVal(float val, float A, float B, float C, float D)
{
  if ( A != B )
    return C + (D - C) * (val - A) / (B - A);
  if ( (float)(val - B) < 0.0 )
    return C;
  return D;
}

//------------------------------------------------------------------------------
// Address: 0x10024BF0
// Name: public: virtual bool C_BaseAnimating::RetrieveRagdollInfo(class Vector __near *,class Quaternion __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::RetrieveRagdollInfo(C_BaseAnimating *this, Vector *pos, Quaternion *q)
{
  RagdollInfo_t *m_pRagdollInfo; // eax
  int v4; // edi
  int v5; // esi
  int v6; // edx
  float *p_z; // eax
  RagdollInfo_t *v8; // ebx
  char *v9; // edx
  double v10; // st7
  int v11; // edx
  Vector *posa; // [esp+8h] [ebp+8h]

  if ( !this->m_bStoreRagdollInfo )
    return 0;
  m_pRagdollInfo = this->m_pRagdollInfo;
  if ( m_pRagdollInfo == nullptr || !m_pRagdollInfo->m_bActive )
    return 0;
  v4 = 0;
  if ( m_pRagdollInfo->m_nNumBones > 0 )
  {
    v5 = 0;
    v6 = -8 - (_DWORD)pos;
    p_z = &pos->z;
    for ( posa = (Vector *)(-8 - (_DWORD)pos); ; v6 = (int)posa )
    {
      v8 = this->m_pRagdollInfo;
      v9 = (char *)p_z + v6;
      v10 = *(float *)((char *)&v8->m_rgBonePos[0].x + (_DWORD)v9);
      v11 = (int)v8->m_rgBonePos + (_DWORD)v9;
      *(p_z - 2) = v10;
      ++v4;
      *(p_z - 1) = *(float *)(v11 + 4);
      p_z += 3;
      *(p_z - 3) = *(float *)(v11 + 8);
      q[v5] = this->m_pRagdollInfo->m_rgBoneQuaternion[v5];
      ++v5;
      if ( v4 >= this->m_pRagdollInfo->m_nNumBones )
        break;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024CB0
// Name: int VectorCompare(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorCompare(const Vector *v1, const Vector *v2)
{
  return v2->x == v1->x && v2->y == v1->y && v2->z == v1->z;
}

//------------------------------------------------------------------------------
// Address: 0x10024D00
// Name: protected: virtual bool C_BaseAnimating::CalcAttachments(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseAnimating::CalcAttachments(C_BaseAnimating *this)
{
  return ((bool (__stdcall *)(_DWORD, int, int, _DWORD))this->SetupBones)(
           a1: 0,
           a2: -1,
           a3: 512,
           a4: *(_DWORD *)(gpGlobals.m_Index + 12));
}

//------------------------------------------------------------------------------
// Address: 0x10024D30
// Name: public: virtual bool C_BaseAnimating::GetAttachment(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::GetAttachment(C_BaseAnimating *this, int number, Vector *origin)
{
  const Vector *v4; // eax
  double z; // st7
  matrix3x4_t attachmentToWorld; // [esp+4h] [ebp-30h] BYREF

  if ( this->GetAttachment(this: &this->IClientRenderable, a2: number, a3: &attachmentToWorld) )
  {
    origin->x = attachmentToWorld.m_flMatVal[0][3];
    origin->y = attachmentToWorld.m_flMatVal[1][3];
    origin->z = attachmentToWorld.m_flMatVal[2][3];
    return 1;
  }
  else
  {
    v4 = this->GetAbsOrigin(this);
    origin->x = v4->x;
    origin->y = v4->y;
    z = v4->z;
    origin->z = z;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024DB0
// Name: public: virtual class CMouthInfo __near * C_BaseAnimating::GetMouth(void)
// Source: json
//------------------------------------------------------------------------------
CMouthInfo *__thiscall C_BaseAnimating::GetMouth(C_BaseAnimating *this)
{
  return &this->m_mouth;
}

//------------------------------------------------------------------------------
// Address: 0x10024DC0
// Name: public: static void C_BaseAnimating::SetupBonesOnBaseAnimating(class C_BaseAnimating __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseAnimating::SetupBonesOnBaseAnimating(C_BaseAnimating **pBaseAnimating)
{
  int v1; // eax
  int v2; // esi
  void (__stdcall *v3)(_DWORD, int, int, _DWORD); // edx

  v1 = (int)*pBaseAnimating;
  if ( *pBaseAnimating != nullptr )
  {
    do
    {
      v2 = *(_DWORD *)(v1 + 2560);
      v3 = *(void (__stdcall **)(_DWORD, int, int, _DWORD))(*(_DWORD *)(v1 + 4) + 52);
      *(_DWORD *)(v1 + 2560) = 0;
      v3(a1: 0, a2: -1, a3: -1, a4: *(_DWORD *)(gpGlobals.m_Index + 12));
      v1 = v2;
    }
    while ( v2 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024E10
// Name: PreThreadedBoneSetup
// Source: json
//------------------------------------------------------------------------------
int PreThreadedBoneSetup()
{
  mdlcache->BeginCoarseLock(this: mdlcache);
  return ((int (__thiscall *)(IMDLCache *))mdlcache->BeginLock)(a1: mdlcache);
}

//------------------------------------------------------------------------------
// Address: 0x10024E30
// Name: PostThreadedBoneSetup
// Source: json
//------------------------------------------------------------------------------
int PostThreadedBoneSetup()
{
  mdlcache->EndLock(this: mdlcache);
  return ((int (__thiscall *)(IMDLCache *))mdlcache->EndCoarseLock)(a1: mdlcache);
}

//------------------------------------------------------------------------------
// Address: 0x10024E50
// Name: public: static void C_BaseAnimating::InitBoneSetupThreadPool(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseAnimating::InitBoneSetupThreadPool()
{
  g_pBoneSetupThreadPool = _g_pThreadPool;
}

//------------------------------------------------------------------------------
// Address: 0x10024E60
// Name: public: class C_BaseAnimating __near * C_BaseAnimating::FindFollowedEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseAnimating *__usercall C_BaseAnimating::FindFollowedEntity@<eax>(C_BaseAnimating *this@<ecx>, int a2@<esi>)
{
  C_BaseEntity *FollowedEntity; // eax
  C_BaseEntity *v4; // ebx
  IClientRenderable *v6; // esi
  int v7; // eax
  IVModelInfoClient_vtbl *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  IVModelInfoClient_vtbl *v16; // [esp+Ch] [ebp-4h]

  FollowedEntity = C_BaseEntity::GetFollowedEntity(this);
  v4 = FollowedEntity;
  if ( FollowedEntity == nullptr || FollowedEntity->IsDormant(this: &FollowedEntity->IClientNetworkable) )
    return nullptr;
  v6 = &v4->IClientRenderable;
  if ( v4->GetModel(this: &v4->IClientRenderable) != nullptr )
  {
    v16 = modelinfo->__vftable;
    v7 = (int)v6->GetModel(this: &v4->IClientRenderable);
    if ( v16->GetModelType(this: modelinfo, a2: (const struct model_t *)v7) == 3 )
    {
      return (C_BaseAnimating *)v4;
    }
    else
    {
      v8 = modelinfo->__vftable;
      v9 = ((int (__thiscall *)(IClientRenderable *, int))v6->GetModel)(a1: v6, a2);
      v10 = v8->GetModelType(this: modelinfo, a2: (const struct model_t *)v9);
      v11 = ((int (__thiscall *)(IClientRenderable *, int))v6->GetModel)(a1: v6, a2: v10);
      v12 = (int)v8->GetModelName(this: modelinfo, a2: (const struct model_t *)v11);
      v13 = ((int (__thiscall *)(IClientRenderable *, int))this->GetModel)(a1: &this->IClientRenderable, a2: v12);
      v14 = (int)v8->GetModelName(this: modelinfo, a2: (const struct model_t *)v13);
      _Warning(a1: "Attached %s (mod_studio) to %s (%d)\n", a2: v14);
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "mod_studio: MOVETYPE_FOLLOW with no model.\n", a2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024F50
// Name: public: void C_BaseAnimating::InvalidateBoneCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::InvalidateBoneCache(C_BaseAnimating *this)
{
  this->m_iMostRecentModelBoneCounter = g_iModelBoneCounter - 1;
  this->m_flLastBoneSetupTime = -3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x10024F70
// Name: public: static void C_BaseAnimating::InvalidateBoneCaches(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseAnimating::InvalidateBoneCaches()
{
  ++g_iModelBoneCounter;
}

//------------------------------------------------------------------------------
// Address: 0x10024F80
// Name: protected: virtual bool C_BaseAnimating::UpdateBlending(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::UpdateBlending(
        C_BaseAnimating *this,
        char flags,
        const RenderableInstance_t *instance)
{
  float v4; // xmm0_4
  float color[3]; // [esp+8h] [ebp-Ch] BYREF

  if ( (flags & 1) != 0 )
  {
    v4 = (float)instance->m_nAlpha * 0.0039215689;
    if ( v4 <= 0.0 )
      return 0;
    ((void (__stdcall *)(_DWORD))render->SetBlend)(a1: LODWORD(v4));
    this->GetColorModulation(this: &this->IClientRenderable, a2: color);
    render->SetColorModulation(this: render, a2: color);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025000
// Name: public: virtual bool C_BaseAnimating::GetRenderData(void __near *,enum ModelDataCategory_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseAnimating::GetRenderData(C_BaseAnimating *this, _DWORD *pData, ModelDataCategory_t nCategory)
{
  if ( nCategory != MODEL_DATA_LIGHTING_MODEL )
    return nCategory == MODEL_DATA_STENCIL
        && (*(bool (__thiscall **)(char *, _DWORD *))(*((_DWORD *)this - 4) + 868))(a1: (char *)this - 16, a2: pData);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 120))(a1: (char *)this - 12);
  *pData = 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10025050
// Name: protected: virtual bool C_BaseAnimating::ComputeStencilState(struct ShaderStencilState_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseAnimating::ComputeStencilState(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10025060
// Name: public: virtual bool C_BaseAnimating::DispatchMuzzleEffect(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::DispatchMuzzleEffect(C_BaseAnimating *this, const char *options, int isFirstPerson)
{
  int v4; // edi
  const char *v5; // ebx
  int v6; // eax
  _DWORD *v8; // eax
  char token[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = 0;
  v5 = nexttoken(token, str: options, sep: 32);
  if ( _V_stricmp(s1: token, s2: "COMBINE") != 0 )
  {
    if ( _V_stricmp(s1: token, s2: "SMG1") != 0 )
    {
      if ( _V_stricmp(s1: token, s2: "PISTOL") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "SHOTGUN") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "357") != 0 )
          {
            if ( _V_stricmp(s1: token, s2: "RPG") == 0 )
              v4 = 7;
          }
          else
          {
            v4 = 6;
          }
        }
        else
        {
          v4 = 1;
        }
      }
      else
      {
        v4 = 4;
      }
    }
    else
    {
      v4 = 2;
    }
  }
  else
  {
    v4 = 5;
  }
  nexttoken(token, str: v5, sep: 32);
  v6 = this->LookupAttachment(this: &this->IClientRenderable, a2: token);
  if ( v6 <= 0 )
    return 0;
  v8 = (_DWORD *)((int (__thiscall *)(C_BaseAnimating *, int, int))this->GetRefEHandle)(
                   a1: this,
                   a2: v6,
                   a3: isFirstPerson);
  ((void (__thiscall *)(ITempEnts *, int, _DWORD))tempents->MuzzleFlash_2)(a1: tempents, a2: v4, a3: *v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025180
// Name: public: bool C_BaseAnimating::IsRagdoll(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseAnimating::IsRagdoll(C_BaseAnimating *this)
{
  return this->m_pRagdoll != nullptr && this->m_bClientSideRagdoll;
}

//------------------------------------------------------------------------------
// Address: 0x100251A0
// Name: public: virtual class Vector C_BaseAnimating::GetThirdPersonViewPosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BaseAnimating::GetThirdPersonViewPosition(C_BaseAnimating *this, Vector *result)
{
  const Vector *v3; // edi
  const Vector *v4; // eax

  v3 = this->GetViewOffset(this);
  v4 = this->GetRenderOrigin(this: &this->IClientRenderable);
  result->x = v3->x + v4->x;
  result->y = v3->y + v4->y;
  result->z = v3->z + v4->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025200
// Name: public: virtual class Vector const __near & C_BaseAnimating::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseAnimating::GetRenderOrigin(C_BaseAnimating *this)
{
  if ( *((_DWORD *)&this->m_bIsBlurred + 1) != 0 && BYTE1(this->m_VisibilityBits.m_Ints[0]) != 0 )
    return (*(const Vector *(__thiscall **)(_DWORD))(**((_DWORD **)&this->m_bIsBlurred + 1) + 8))(a1: *((_DWORD *)&this->m_bIsBlurred + 1));
  if ( vec3_invalid.x == *(float *)&this->m_iEjectBrassAttachment
    && vec3_invalid.y == this->m_vecRenderOriginOverride.x
    && vec3_invalid.z == this->m_vecRenderOriginOverride.y )
  {
    return C_BaseEntity::GetRenderOrigin(this);
  }
  return (const Vector *)&this->m_iEjectBrassAttachment;
}

//------------------------------------------------------------------------------
// Address: 0x10025270
// Name: public: virtual class QAngle const __near & C_BaseAnimating::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BaseAnimating::GetRenderAngles(C_BaseAnimating *this)
{
  if ( *((_DWORD *)&this->m_bIsBlurred + 1) != 0 && BYTE1(this->m_VisibilityBits.m_Ints[0]) != 0 )
    return &vec3_angle;
  else
    return C_BaseEntity::GetRenderAngles(this);
}

//------------------------------------------------------------------------------
// Address: 0x10025290
// Name: public: virtual void C_BaseAnimating::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::OnPreDataChanged(C_BaseAnimating *this, DataUpdateType_t updateType)
{
  float v3; // eax
  int v4; // edx
  int v5; // eax
  char m_depth; // cl

  C_BaseEntity::OnPreDataChanged(this, type: updateType);
  v3 = COERCE_FLOAT((*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4));
  v4 = *((_DWORD *)this - 1);
  this->m_prevClientAnimTime = v3;
  v5 = (*(int (__thiscall **)(char *))(v4 + 148))(a1: (char *)this - 4);
  m_depth = this->m_BoneSetupLock.m_depth;
  *(_DWORD *)&this->m_bBonePolishSetup = v5;
  BYTE1(this->m_flOldEncodedController[2]) = m_depth;
}

//------------------------------------------------------------------------------
// Address: 0x100252E0
// Name: public: bool C_BaseAnimating::IsSequenceLooping(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::IsSequenceLooping(C_BaseAnimating *this, CStudioHdr *pStudioHdr, int iSequence)
{
  return GetSequenceFlags(pstudiohdr: pStudioHdr, sequence: iSequence) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025300
// Name: public: void C_BaseAnimating::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetSkin(C_BaseAnimating *this, int iSkin)
{
  if ( this->m_nSkin != iSkin )
  {
    this->m_nSkin = iSkin;
    C_BaseEntity::OnTranslucencyTypeChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025320
// Name: public: void C_BaseAnimating::SetBody(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetBody(C_BaseAnimating *this, int iBody)
{
  if ( this->m_nBody != iBody )
  {
    this->m_nBody = iBody;
    C_BaseEntity::OnTranslucencyTypeChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025340
// Name: public: int C_BaseAnimating::GetHitboxSet(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::GetHitboxSet(C_BaseAnimating *this)
{
  return this->m_nHitboxSet;
}

//------------------------------------------------------------------------------
// Address: 0x10025350
// Name: public: float C_BaseAnimating::SetPoseParameter(class CStudioHdr __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::SetPoseParameter(
        C_BaseAnimating *this,
        CStudioHdr *pStudioHdr,
        int iParameter,
        float flValue)
{
  double result; // st7

  if ( pStudioHdr == nullptr )
    return flValue;
  if ( iParameter < 0 )
    return flValue;
  result = Studio_SetPoseParameter(pStudioHdr, iParameter, flValue, ctlValue: &flValue);
  this->m_flPoseParameter[iParameter] = flValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100253B0
// Name: public: virtual void C_BaseAnimating::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::Clear(C_BaseAnimating *this)
{
  _V_memset(dest: &this->m_mouth, fill: 0, count: 60);
  C_BaseEntity::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x100253D0
// Name: private: virtual class ClientClass __near * C_BoneFollower::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BoneFollower::GetClientClass(C_BoneFollower *this)
{
  return &__g_C_BoneFollowerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100254F0
// Name: public: virtual int C_BoneFollower::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BoneFollower::DrawModel(C_BoneFollower *this, int flags, const RenderableInstance_t *instance)
{
  vcollide_t *v4; // ebx
  const QAngle *v5; // eax
  const Vector *v7; // [esp-Ch] [ebp-44h]
  matrix3x4_t matrix; // [esp+8h] [ebp-30h] BYREF

  v4 = modelinfo->GetVCollide(this: modelinfo, a2: *((_DWORD *)&this->m_bIsBlurred + 1));
  if ( v4 != nullptr )
  {
    v7 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
    v5 = (const QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 44))(a1: (char *)this - 4);
    AngleMatrix(angles: v5, position: v7, &matrix);
    engine->DebugDrawPhysCollide(
      this: engine,
      a2: v4->solids[this->m_modelIndex],
      a3: nullptr,
      a4: &matrix,
      a5: &debugColor);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025570
// Name: public: virtual void C_BaseAnimating::DoMuzzleFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::DoMuzzleFlash(C_BaseAnimating *this)
{
  this->m_nMuzzleFlashParity = (this->m_nMuzzleFlashParity + 1) & 3;
}

//------------------------------------------------------------------------------
// Address: 0x10025590
// Name: void DevMsgRT(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DevMsgRT(const char *pMsg, ...)
{
  va_list params; // [esp+Ch] [ebp+Ch] BYREF

  va_start(params, pMsg);
  if ( !engine->Con_IsVisible(this: engine) )
  {
    V_vsnprintf(pDest: string, maxLen: 1024, pFormat: pMsg, params);
    _DevMsg(a1: 1, a2: "%s");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100255E0
// Name: public: virtual void C_BaseAnimating::CleanupToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::CleanupToolRecordingState(C_BaseAnimating *this, KeyValues *msg)
{
  void *Ptr; // eax
  CBoneList *v4; // eax

  if ( ToolsEnabled() )
  {
    Ptr = KeyValues::GetPtr(this: msg, keyName: "baseanimating", defaultValue: nullptr);
    if ( Ptr != nullptr )
    {
      v4 = *((CBoneList **)Ptr + 34);
      if ( v4 != nullptr )
      {
        if ( v4 != &C_BaseAnimating::m_recordingBoneList )
        {
          CBoneList::Release(this: v4);
          CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: (int)msg);
          return;
        }
        C_BaseAnimating::m_bBoneListInUse = false;
      }
    }
    CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: (int)msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025640
// Name: public: void C_BaseAnimating::SetReceivedSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetReceivedSequence(C_BaseAnimating *this)
{
  this->m_bReceivedSequence = true;
}

//------------------------------------------------------------------------------
// Address: 0x10025650
// Name: public: virtual bool C_BaseAnimating::ShouldResetSequenceOnNewModel(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseAnimating::ShouldResetSequenceOnNewModel(C_BaseAnimating *this)
{
  return !this->m_bReceivedSequence;
}

//------------------------------------------------------------------------------
// Address: 0x10025660
// Name: public: void CInterpolatedVarArrayBase<float,1>::SetMaxCount(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::SetMaxCount(
        CInterpolatedVarArrayBase<float,1> *this,
        float flCurrentTime,
        int newmax)
{
  unsigned __int8 v3; // al
  bool v5; // cl
  float *v6; // eax
  unsigned __int8 *m_bLooping; // ecx

  v3 = newmax;
  v5 = newmax != this->m_nMaxCount;
  if ( newmax < 1 )
    v3 = 1;
  this->m_nMaxCount = v3;
  if ( v5 )
  {
    C_BaseEntity::operator delete(pMem: this->m_bLooping);
    C_BaseEntity::operator delete(pMem: this->m_LastNetworkedValue);
    this->m_bLooping = (unsigned __int8 *)MemAlloc_Alloc(nSize: this->m_nMaxCount);
    v6 = (float *)MemAlloc_Alloc(nSize: 4 * this->m_nMaxCount);
    m_bLooping = this->m_bLooping;
    this->m_LastNetworkedValue = v6;
    memset(dst: (int)m_bLooping, value: nullptr, count: this->m_nMaxCount);
    memset(dst: (int)this->m_LastNetworkedValue, value: nullptr, count: 4 * this->m_nMaxCount);
    ((void (__thiscall *)(CInterpolatedVarArrayBase<float,1> *, _DWORD))this->Reset)(
      a1: this,
      a2: LODWORD(flCurrentTime));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100257A0
// Name: public: void CUtlMemoryAligned<class matrix3x4a_t,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<matrix3x4a_t,16>::Grow(CUtlMemoryAligned<matrix3x4a_t,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  unsigned __int8 *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  matrix3x4a_t *v9; // ecx

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
    m_pMemory = (unsigned __int8 *)this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (matrix3x4a_t *)MemAlloc_ReallocAligned(ptr: m_pMemory, size: v7, align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (matrix3x4a_t *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        LODWORD(v9[-1].m_flMatVal[2][3]) = v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025890
// Name: public: CPASAttenuationFilter::CPASAttenuationFilter(class C_BaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
CPASAttenuationFilter *__thiscall CPASAttenuationFilter::CPASAttenuationFilter(
        CPASAttenuationFilter *this,
        C_BaseEntity *entity,
        float attenuation)
{
  const Vector *v4; // edi

  v4 = entity->GetAbsOrigin(this: entity);
  C_RecipientFilter::C_RecipientFilter(this);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this, origin: v4);
  this->__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100258D0
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100259A0
// Name: void RecvProxy_Sequence(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Sequence(const CRecvProxyData *pData, C_BaseEntity *pStruct, void *pOut)
{
  RecvProxy_Int32ToInt32(pData, pStruct, pOut);
  if ( pStruct != nullptr )
  {
    BYTE1(pStruct[1].m_nLastThinkTick) = 1;
    C_BaseEntity::UpdateVisibility(this: pStruct);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025D00
// Name: public: virtual void C_ClientRagdoll::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::ImpactTrace(
        C_ClientRagdoll *this,
        CGameTrace *pTrace,
        char iDamageType,
        char *pCustomImpactName)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float fraction; // xmm2_4
  float m_fValue; // xmm0_4
  Vector hitpos; // [esp+8h] [ebp-18h] BYREF
  Vector dir; // [esp+14h] [ebp-Ch] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr && m_pPhysicsObject->IsCollisionEnabled(this: this->m_pPhysicsObject) )
  {
    x = pTrace->startpos.x;
    y = pTrace->startpos.y;
    z = pTrace->startpos.z;
    v9 = pTrace->endpos.x - pTrace->startpos.x;
    v10 = pTrace->endpos.y - y;
    v11 = pTrace->endpos.z - z;
    dir.x = v9;
    dir.y = v10;
    dir.z = v11;
    if ( (iDamageType & 0x40) != 0 )
    {
      dir.x = v9 * 500.0;
      dir.y = v10 * 500.0;
      dir.z = v11 * 500.0;
      m_pPhysicsObject->ApplyForceCenter(this: m_pPhysicsObject, a2: &dir);
      CRagdoll::ResetRagdollSleepAfterTime(this: this->m_pRagdoll);
    }
    else
    {
      fraction = pTrace->fraction;
      hitpos.x = (float)(v9 * fraction) + x;
      hitpos.y = (float)(v10 * fraction) + y;
      hitpos.z = (float)(fraction * v11) + z;
      VectorNormalize(vec: &dir);
      m_fValue = RagdollImpactStrength.m_pParent->m_Value.m_fValue;
      dir.x = dir.x * m_fValue;
      dir.y = dir.y * m_fValue;
      dir.z = m_fValue * dir.z;
      m_pPhysicsObject->ApplyForceOffset(this: m_pPhysicsObject, a2: &dir, a3: &hitpos);
      CRagdoll::ResetRagdollSleepAfterTime(this: this->m_pRagdoll);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025E50
// Name: public: void C_ClientRagdoll::FadeOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::FadeOut(C_ClientRagdoll *this)
{
  int RenderAlpha; // ecx
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  float v5; // xmm0_4

  if ( this->m_bFadingOut )
  {
    RenderAlpha = C_BaseEntity::GetRenderAlpha(this);
    m_pParent = g_ragdoll_lvfadespeed.m_pParent;
    if ( !g_RagdollLVManager.m_bLowViolence )
      m_pParent = g_ragdoll_fadespeed.m_pParent;
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v5 = (float)RenderAlpha - (float)((float)m_nValue * *(float *)(gpGlobals.m_Index + 16));
    if ( v5 <= 0.0 )
      v5 = 0.0;
    C_BaseEntity::SetRenderMode(this, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
    C_BaseEntity::SetRenderAlpha(this, a: (int)v5);
    if ( (int)v5 == 0 )
      this->m_bReleaseRagdoll = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025ED0
// Name: public: virtual float C_ClientRagdoll::LastBoneChangedTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_ClientRagdoll::LastBoneChangedTime(C_ClientRagdoll *this)
{
  CRagdoll *m_pRagdoll; // eax

  m_pRagdoll = this->m_pRagdoll;
  if ( m_pRagdoll != nullptr )
    return m_pRagdoll->m_lastUpdate;
  else
    return -3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x10025F10
// Name: public: virtual int C_BaseAnimating::VPhysicsGetObjectList(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::VPhysicsGetObjectList(C_BaseAnimating *this, IPhysicsObject **pList, int listMax)
{
  int i; // esi

  if ( this->m_pRagdoll == nullptr || !this->m_bClientSideRagdoll )
    return C_BaseEntity::VPhysicsGetObjectList(this, pList, listMax);
  for ( i = 0; i < this->m_pRagdoll->RagdollBoneCount(this: this->m_pRagdoll); ++i )
  {
    if ( i >= listMax )
      break;
    pList[i] = this->m_pRagdoll->GetElement(this: this->m_pRagdoll, a2: i);
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10025F90
// Name: private: enum ShadowType_t C_BaseAnimating::GetShadowCastTypeForStudio(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
ShadowType_t __thiscall C_BaseAnimating::GetShadowCastTypeForStudio(C_BaseAnimating *this, CStudioHdr *pStudioHdr)
{
  int NumSeq_Internal; // eax
  ShadowType_t result; // eax

  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( NumSeq_Internal == 0 || this->m_pRagdoll != nullptr && this->m_bClientSideRagdoll )
    return SHADOWS_RENDER_TO_TEXTURE;
  if ( CStudioHdr::GetNumPoseParameters(this: pStudioHdr) > 0 || pStudioHdr->m_pStudioHdr->numbonecontrollers > 0 )
    return SHADOWS_RENDER_TO_TEXTURE_DYNAMIC;
  result = SHADOWS_RENDER_TO_TEXTURE_DYNAMIC;
  if ( pStudioHdr->m_pStudioHdr->numikchains <= 0 )
    return SHADOWS_RENDER_TO_TEXTURE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026010
// Name: private: void C_BaseAnimating::LockStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::LockStudioHdr(C_BaseAnimating *this)
{
  CThreadFastMutex *p_m_StudioHdrInitLock; // esi
  DWORD CurrentThreadId; // ecx
  const struct model_t *v4; // eax
  int v5; // eax
  const studiohdr_t *v6; // ebx
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr *v8; // eax
  CThreadFastMutex *generated_id_17; // [esp+Ch] [ebp-4h]

  p_m_StudioHdrInitLock = &this->m_StudioHdrInitLock;
  generated_id_17 = &this->m_StudioHdrInitLock;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_StudioHdrInitLock->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_StudioHdrInitLock, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_StudioHdrInitLock, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_StudioHdrInitLock->m_depth;
  }
  v4 = this->GetModel(this: &this->IClientRenderable);
  if ( v4 != nullptr )
  {
    v5 = ((int (__thiscall *)(IVModelInfoClient *, const struct model_t *))modelinfo->GetCacheHandle)(
           a1: modelinfo,
           a2: v4);
    this->m_hStudioHdr = v5;
    if ( (_WORD)v5 != 0xFFFF )
    {
      v6 = mdlcache->LockStudioHdr(this: mdlcache, a2: v5);
      m_pStudioHdr = nullptr;
      if ( this->m_pStudioHdr != nullptr )
      {
        m_pStudioHdr = this->m_pStudioHdr;
      }
      else
      {
        if ( v6 == nullptr )
        {
          this->m_hStudioHdr = -1;
LABEL_17:
          this->m_pStudioHdr = m_pStudioHdr;
          p_m_StudioHdrInitLock = generated_id_17;
          goto LABEL_18;
        }
        v8 = (CStudioHdr *)MemAlloc_Alloc(nSize: 0x64u);
        if ( v8 != nullptr )
        {
          m_pStudioHdr = CStudioHdr::CStudioHdr(this: v8);
          CStudioHdr::Init(this: m_pStudioHdr, pStudioHdr: v6, mdlcache: mdlcache);
        }
        else
        {
          m_pStudioHdr = nullptr;
          CStudioHdr::Init(this: nullptr, pStudioHdr: v6, mdlcache: mdlcache);
        }
      }
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pVModel != nullptr )
        ((void (__stdcall *)(_DWORD))mdlcache->LockStudioHdr)(a1: LOWORD(m_pStudioHdr->m_pStudioHdr->virtualModel));
      goto LABEL_17;
    }
  }
LABEL_18:
  if ( p_m_StudioHdrInitLock->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_StudioHdrInitLock, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10026140
// Name: private: void C_BaseAnimating::UnlockStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::UnlockStudioHdr(C_BaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // esi

  if ( this->m_pStudioHdr != nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
  {
    ((void (__stdcall *)(_DWORD))mdlcache->UnlockStudioHdr)(a1: this->m_hStudioHdr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pVModel != nullptr )
      ((void (__stdcall *)(_DWORD))mdlcache->UnlockStudioHdr)(a1: LOWORD(m_pStudioHdr->m_pStudioHdr->virtualModel));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100261A0
// Name: public: float C_BaseAnimating::ClampCycle(float,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::ClampCycle(C_BaseAnimating *this, float flCycle, bool isLooping)
{
  float v3; // xmm0_4
  float v5; // xmm0_4
  float flCyclea; // [esp+8h] [ebp+8h]

  if ( isLooping )
  {
    v3 = flCycle - (double)(int)flCycle;
    flCyclea = v3;
    if ( v3 < 0.0 )
      return (float)(v3 + 1.0);
  }
  else
  {
    v5 = 0.0;
    if ( flCycle >= 0.0 )
    {
      v5 = 0.99900001;
      if ( flCycle <= 0.99900001 )
        return flCycle;
    }
    return v5;
  }
  return flCyclea;
}

//------------------------------------------------------------------------------
// Address: 0x10026210
// Name: public: void C_BaseAnimating::GetCachedBoneMatrix(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetCachedBoneMatrix(C_BaseAnimating *this, int boneIndex, matrix3x4_t *out)
{
  MatrixCopy(in: &this->m_BoneAccessor.m_pBones[boneIndex], out);
}

//------------------------------------------------------------------------------
// Address: 0x10026240
// Name: float RemapValClamped(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapValClamped(float val, float A, float B, float C, float D)
{
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( A == B )
  {
    if ( (float)(val - B) < 0.0 )
      return C;
    else
      return D;
  }
  else
  {
    v6 = (float)(val - A) / (float)(B - A);
    v7 = 0.0;
    if ( v6 < 0.0 )
      return C + (D - C) * v7;
    v7 = 1.0;
    if ( v6 > 1.0 )
      return C + (D - C) * v7;
    else
      return C + (D - C) * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100262E0
// Name: public: virtual enum CollideType_t C_BaseAnimating::GetCollideType(void)
// Source: json
//------------------------------------------------------------------------------
CollideType_t __thiscall C_BaseAnimating::GetCollideType(C_BaseAnimating *this)
{
  if ( this->m_pRagdoll != nullptr && this->m_bClientSideRagdoll )
    return ENTITY_SHOULD_RESPOND;
  else
    return C_BaseEntity::GetCollideType(this);
}

//------------------------------------------------------------------------------
// Address: 0x10026300
// Name: public: void C_BaseAnimating::UnragdollBlend(class CStudioHdr __near *,class Vector __near * const,class Quaternion __near * const,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::UnragdollBlend(
        C_BaseAnimating *this,
        CStudioHdr *hdr,
        Vector *pos,
        Quaternion *q,
        float currentTime)
{
  int v5; // ebx
  RagdollInfo_t *m_pRagdollInfo; // eax
  float v7; // xmm0_4
  float t; // xmm0_4
  int v9; // xmm1_4
  int v11; // eax
  float *p_z; // esi
  RagdollInfo_t *v13; // edx
  char *v14; // eax
  float v15; // xmm2_4
  float *v16; // eax
  C_BaseAnimating *v17; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  float currentTimea; // [esp+30h] [ebp+14h]

  v5 = 0;
  v17 = this;
  if ( hdr != nullptr )
  {
    m_pRagdollInfo = this->m_pRagdollInfo;
    if ( m_pRagdollInfo != nullptr && m_pRagdollInfo->m_bActive )
    {
      v7 = currentTime - m_pRagdollInfo->m_flSaveTime;
      if ( v7 <= 0.2 )
      {
        t = v7 * 5.0;
        *(float *)&v9 = 0.0;
        if ( t < 0.0 || (*(float *)&v9 = 1.0, t > 1.0) )
          t = *(float *)&v9;
        currentTimea = t;
        i = 0;
        if ( hdr->m_pStudioHdr->numbones > 0 )
        {
          v11 = -8 - (_DWORD)pos;
          p_z = &pos->z;
          while ( 1 )
          {
            v13 = this->m_pRagdollInfo;
            v14 = (char *)p_z + v11;
            v15 = *(p_z - 2) - *(float *)((char *)&v13->m_rgBonePos[0].x + (_DWORD)v14);
            v16 = (float *)((char *)&v13->m_rgBonePos[0].x + (_DWORD)v14);
            *(p_z - 2) = (float)(v15 * t) + *v16;
            *(p_z - 1) = (float)((float)(*(p_z - 1) - v16[1]) * t) + v16[1];
            *p_z = (float)((float)(*p_z - v16[2]) * t) + v16[2];
            QuaternionSlerp(p: &this->m_pRagdollInfo->m_rgBoneQuaternion[v5], q, t, qt: q);
            p_z += 3;
            ++v5;
            ++q;
            if ( ++i >= hdr->m_pStudioHdr->numbones )
              break;
            t = currentTimea;
            this = v17;
            v11 = -8 - (_DWORD)pos;
          }
        }
      }
      else
      {
        m_pRagdollInfo->m_bActive = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026450
// Name: public: bool C_BaseAnimating::GetAttachmentLocal(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::GetAttachmentLocal(
        C_BaseAnimating *this,
        int iAttachment,
        Vector *origin,
        QAngle *angles)
{
  matrix3x4_t out; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t in2; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t attachmentToEntity; // [esp+64h] [ebp-30h] BYREF

  if ( !this->GetAttachment(this: &this->IClientRenderable, a2: iAttachment, a3: &in2) )
    return 0;
  C_BaseEntity::CalcAbsolutePosition(this);
  MatrixInvert(in: &this->m_rgflCoordinateFrame, &out);
  ConcatTransforms(in1: &out, &in2, out: &attachmentToEntity);
  origin->x = attachmentToEntity.m_flMatVal[0][3];
  origin->y = attachmentToEntity.m_flMatVal[1][3];
  origin->z = attachmentToEntity.m_flMatVal[2][3];
  MatrixAngles(src: (const VMatrix *)&attachmentToEntity, vAngles: angles);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100264F0
// Name: public: virtual int C_BaseAnimating::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::DrawModel(C_BaseAnimating *this, int flags, const RenderableInstance_t *instance)
{
  int v3; // esi
  C_BaseAnimating *v4; // edi
  C_BaseAnimating *v6; // edi
  int v7; // eax
  C_BaseAnimating *FollowedEntity; // eax
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-8h]
  int drawn; // [esp+10h] [ebp-4h]

  v3 = 0;
  v4 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseAnimating::DrawModel",
    a3: 0,
    a4: "Other_Model_Rendering",
    a5: false,
    a6: 4);
  if ( LOBYTE(v4->m_VisibilityBits.m_Ints[0]) == 0 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  drawn = 0;
  if ( r_drawothermodels.m_pParent != nullptr && r_drawothermodels.m_pParent->m_Value.m_nValue != 0 )
  {
    cacheCriticalSection = mdlcache;
    ((void (*)(void))mdlcache->BeginLock)();
    if ( r_drawothermodels.m_pParent != nullptr && r_drawothermodels.m_pParent->m_Value.m_nValue == 2 )
      v3 = 32;
    if ( (flags & 0x40000000) != 0 )
      v3 |= 0x40000000u;
    if ( (flags & 0x800) != 0 )
      v3 |= 0x800u;
    if ( (flags & 0x10000000) != 0 )
      v3 |= 0x10000000u;
    v4->GetTracerType(this: v4);
    v6 = (C_BaseAnimating *)((char *)v4 - 4);
    if ( C_BaseEntity::IsFollowingEntity(this: v6) )
    {
      FollowedEntity = C_BaseAnimating::FindFollowedEntity(this: v6, a2: v3);
      if ( FollowedEntity == nullptr
        || FollowedEntity->DrawModel(this: &FollowedEntity->IClientRenderable, a2: 0, a3: instance) == 0 )
      {
        goto LABEL_20;
      }
      v7 = v6->InternalDrawModel(this: v6, a2: v3 | 1, a3: instance);
    }
    else
    {
      v7 = v6->InternalDrawModel(this: v6, a2: flags | v3, a3: instance);
    }
    drawn = v7;
LABEL_20:
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    v4 = this;
  }
  C_BaseEntity::DrawBBoxVisualizations(this: (C_BaseAnimating *)((char *)v4 - 4));
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return drawn;
}

//------------------------------------------------------------------------------
// Address: 0x10026630
// Name: public: virtual class IClientModelRenderable __near * C_BaseAnimating::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__usercall C_BaseAnimating::GetClientModelRenderable@<eax>(C_BaseAnimating *this@<ecx>, int a2@<esi>)
{
  if ( LOBYTE(this->m_flFrozen) == 0
    || BYTE2(this->m_flLastEventCheck) != 0
    || r_drawothermodels.m_pParent == nullptr
    || r_drawothermodels.m_pParent->m_Value.m_nValue != 1
    || r_drawmodelstatsoverlay.m_pParent != nullptr && r_drawmodelstatsoverlay.m_pParent->m_Value.m_nValue != 0
    || mat_wireframe.m_pParent != nullptr && mat_wireframe.m_pParent->m_Value.m_nValue != 0 )
  {
    return nullptr;
  }
  if ( C_BaseEntity::IsFollowingEntity(this: (C_BaseAnimating *)((char *)this - 4))
    && C_BaseAnimating::FindFollowedEntity(this: (C_BaseAnimating *)((char *)this - 4), a2) == nullptr
    || this == (C_BaseAnimating *)4 )
  {
    return nullptr;
  }
  return &this->IClientThinkable;
}

//------------------------------------------------------------------------------
// Address: 0x100266B0
// Name: public: virtual void C_BaseAnimating::FireObsoleteEvent(class Vector const __near &,class QAngle const __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::FireObsoleteEvent(
        C_BaseAnimating *this,
        const Vector *origin,
        const QAngle *angles,
        int event,
        char *options)
{
  const char *v6; // edi
  const char *v7; // ebx
  int v8; // eax
  int v9; // edi
  int v10; // ebx
  unsigned int m_Index; // ecx
  int v12; // edi
  char *v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  ITempEnts_vtbl *v17; // esi
  int v18; // eax
  IEffects_vtbl *v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // [esp+0h] [ebp-1CCh]
  int SoundSourceIndex; // [esp+0h] [ebp-1CCh]
  unsigned int soundtime; // [esp+Ch] [ebp-1C0h]
  char effectFunc[128]; // [esp+20h] [ebp-1ACh] BYREF
  char token[128]; // [esp+A0h] [ebp-12Ch] BYREF
  CLocalPlayerFilter filter; // [esp+120h] [ebp-ACh] BYREF
  Vector vecForward; // [esp+140h] [ebp-8Ch] BYREF
  CEffectData data; // [esp+14Ch] [ebp-80h] BYREF
  CBaseHandle hEntity; // [esp+1B0h] [ebp-1Ch] BYREF
  Vector attachOrigin; // [esp+1B4h] [ebp-18h] BYREF
  QAngle attachAngles; // [esp+1C0h] [ebp-Ch] BYREF

  if ( event > 5001 )
  {
    if ( event > 9001 )
    {
      switch ( event )
      {
        case 9011:
        case 9021:
        case 9031:
        case 9041:
        case 9051:
        case 9061:
        case 9071:
        case 9081:
        case 9091:
          goto $LN31;
        default:
          return;
      }
    }
    else
    {
      if ( event == 9001 )
      {
$LN31:
        switch ( event )
        {
          case 9001:
            v21 = 0;
            goto LABEL_41;
          case 9011:
            v21 = 1;
            goto LABEL_41;
          case 9021:
            v21 = 2;
            goto LABEL_41;
          case 9031:
            v21 = 3;
            goto LABEL_41;
          case 9041:
            v21 = 4;
            goto LABEL_41;
          case 9051:
            v21 = 5;
            goto LABEL_41;
          case 9061:
            v21 = 6;
            goto LABEL_41;
          case 9071:
            v21 = 7;
            goto LABEL_41;
          case 9081:
            v21 = 8;
            goto LABEL_41;
          case 9091:
            v21 = 9;
LABEL_41:
            if ( this->m_Attachments.m_Size <= v21 )
              return;
            v12 = v21 + 1;
            this->GetAttachment_2(this: &this->IClientRenderable, a2: v21 + 1, a3: &attachOrigin, a4: &attachAngles);
            CEffectData::CEffectData(this: &data);
            data.m_vOrigin = attachOrigin;
            data.m_vAngles = attachAngles;
            AngleVectors(angles: &attachAngles, forward: &data.m_vNormal);
            m_Index = this->GetRefEHandle(this)->m_Index;
            v13 = options;
            break;
          default:
            return;
        }
        goto LABEL_43;
      }
      switch ( event )
      {
        case 5002:
          this->GetAttachment_2(this: &this->IClientRenderable, a2: 1, a3: &attachOrigin, a4: &attachAngles);
          AngleVectors(angles: &attachAngles, forward: &vecForward);
          v19 = g_pEffects->__vftable;
          v20 = atoi(nptr: options);
          v19->Sparks(this: g_pEffects, a2: &attachOrigin, a3: v20, a4: 1, a5: &vecForward);
          break;
        case 5003:
        case 5011:
        case 5013:
        case 5021:
        case 5023:
        case 5031:
        case 5033:
          goto $LN17;
        case 5004:
          CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
          if ( this->m_Attachments.m_Size <= 0 )
          {
            SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this);
            C_BaseEntity::EmitSound(
              &filter,
              iEntIndex: SoundSourceIndex,
              soundname: options,
              pOrigin: nullptr,
              soundtime: 0.0,
              duration: nullptr);
          }
          else
          {
            this->GetAttachment_2(this: &this->IClientRenderable, a2: 1, a3: &attachOrigin, a4: &attachAngles);
            v22 = C_BaseEntity::GetSoundSourceIndex(this);
            C_BaseEntity::EmitSound(
              &filter,
              iEntIndex: v22,
              soundname: options,
              pOrigin: &attachOrigin,
              soundtime: 0.0,
              duration: nullptr);
          }
          C_RecipientFilter::~C_RecipientFilter(this: &filter);
          break;
        default:
          return;
      }
    }
  }
  else if ( event == 5001 )
  {
$LN17:
    v14 = event - 5001;
    LOBYTE(event) = 1;
    switch ( v14 )
    {
      case 0:
        v15 = 0;
        goto LABEL_22;
      case 2:
        v15 = 0;
        LOBYTE(event) = 0;
        goto LABEL_22;
      case 10:
        v15 = 1;
        goto LABEL_22;
      case 12:
        v15 = 1;
        LOBYTE(event) = 0;
        goto LABEL_22;
      case 20:
        v15 = 2;
        goto LABEL_22;
      case 22:
        v15 = 2;
        LOBYTE(event) = 0;
        goto LABEL_22;
      case 30:
        goto $LN11;
      case 32:
        LOBYTE(event) = 0;
$LN11:
        v15 = 3;
LABEL_22:
        if ( this->m_Attachments.m_Size > v15 )
        {
          this->GetAttachment_2(this: &this->IClientRenderable, a2: v15 + 1, a3: &attachOrigin, a4: &attachAngles);
          v16 = render->GetViewEntity(this: render);
          CClientEntityList::EntIndexToHandle(
            this: (CClientEntityList *)cl_entitylist.m_Index,
            result: &hEntity,
            entnum: v16);
          soundtime = hEntity.m_Index;
          v17 = tempents->__vftable;
          v18 = atoi(nptr: options);
          ((void (__thiscall *)(ITempEnts *, Vector *, QAngle *, int, unsigned int, int))v17->MuzzleFlash)(
            a1: tempents,
            a2: &attachOrigin,
            a3: &attachAngles,
            a4: v18,
            a5: soundtime,
            a6: event);
        }
        break;
      default:
        return;
    }
  }
  else if ( event == 20 )
  {
    v6 = nexttoken(token, str: options, sep: 32);
    V_strncpy(pDest: effectFunc, pSrc: token, maxLen: 128);
    v7 = nexttoken(token, str: v6, sep: 32);
    v8 = isdigit(c: token[0]) != 0
       ? atoi(nptr: token)
       : this->LookupAttachment(this: &this->IClientRenderable, a2: token);
    v9 = v8;
    nexttoken(token, str: v7, sep: 32);
    v10 = atoi(nptr: token);
    if ( v9 != -1 && this->m_Attachments.m_Size >= v9 )
    {
      this->GetAttachment_2(this: &this->IClientRenderable, a2: v9, a3: &attachOrigin, a4: &attachAngles);
      CEffectData::CEffectData(this: &data);
      data.m_vOrigin = attachOrigin;
      data.m_vAngles = attachAngles;
      AngleVectors(angles: &attachAngles, forward: &data.m_vNormal);
      m_Index = this->GetRefEHandle(this)->m_Index;
      v12 = v9 + 1;
      data.m_fFlags = v10;
      v13 = effectFunc;
LABEL_43:
      data.m_hEntity.m_Index = m_Index;
      data.m_nAttachmentIndex = v12;
      DispatchEffect(pName: v13, &data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026C80
// Name: public: virtual bool C_BaseAnimating::IsSelfAnimating(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseAnimating::IsSelfAnimating(C_BaseAnimating *this)
{
  bool result; // al
  int m_MoveType; // eax

  result = true;
  if ( !this->m_bClientSideAnimation )
  {
    m_MoveType = this->m_MoveType;
    if ( m_MoveType == 3 || this->m_MoveType == 0 || m_MoveType == 2 || m_MoveType == 4 || m_MoveType == 5 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026CB0
// Name: public: void C_BaseAnimating::RagdollMoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::RagdollMoved(C_BaseAnimating *this)
{
  const Vector *v2; // eax
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF

  v2 = this->m_pRagdoll->GetRagdollOrigin(this: this->m_pRagdoll);
  C_BaseEntity::SetAbsOrigin(this, absOrigin: v2);
  C_BaseEntity::SetAbsAngles(this, absAngles: &vec3_angle);
  this->m_pRagdoll->GetRagdollBounds(this: this->m_pRagdoll, a2: &mins, a3: &maxs);
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, &mins, &maxs);
  C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 16);
}

//------------------------------------------------------------------------------
// Address: 0x10026D10
// Name: public: virtual void C_BaseAnimating::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::VPhysicsUpdate(C_BaseAnimating *this, IPhysicsObject *pPhysics)
{
  if ( this->m_pRagdoll != nullptr && this->m_bClientSideRagdoll )
  {
    this->m_pRagdoll->VPhysicsUpdate(this: this->m_pRagdoll, a2: pPhysics);
    C_BaseAnimating::RagdollMoved(this);
  }
  else
  {
    C_BaseEntity::VPhysicsUpdate(this, pPhysics);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026D60
// Name: public: virtual void C_BaseAnimating::NotifyShouldTransmit(enum ShouldTransmitState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::NotifyShouldTransmit(C_BaseAnimating *this, ShouldTransmitState_t state)
{
  float z; // edx

  C_BaseEntity::NotifyShouldTransmit(this, state);
  if ( state == SHOULDTRANSMIT_START )
  {
    LOBYTE(this->m_Attachments.m_pElements) = LOBYTE(this->m_flEncodedController[2]);
    z = this->m_vecPreRagdollMaxs.z;
    this->m_nResetEventsParity = this->m_nBody;
    *(float *)&this->m_Ropes.m_pElements = z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026DA0
// Name: public: virtual void C_BaseAnimating::UpdateClientSideAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::UpdateClientSideAnimation(C_BaseAnimating *this)
{
  if ( this->m_bClientSideAnimation && this->m_nSequence != -1 )
  {
    this->OnLatchInterpolatedVariables(this, a2: 1);
    ((void (__thiscall *)(C_BaseAnimating *, _DWORD))this->FrameAdvance)(a1: this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026DE0
// Name: public: virtual float C_BaseAnimating::GetSequenceCycleRate(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::GetSequenceCycleRate(C_BaseAnimating *this, CStudioHdr *pStudioHdr, int iSequence)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // eax
  mstudioseqdesc_t *v7; // eax

  if ( pStudioHdr == nullptr )
    return 0.0;
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v7 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: iSequence);
  }
  else
  {
    m_pStudioHdr = pStudioHdr->m_pStudioHdr;
    v6 = iSequence;
    if ( iSequence < 0 || iSequence >= m_pStudioHdr->numlocalseq )
      v6 = 0;
    v7 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v6 + m_pStudioHdr->localseqindex);
  }
  return Studio_CPS(pStudioHdr, seqdesc: v7, iSequence, poseParameter: this->m_flPoseParameter);
}

//------------------------------------------------------------------------------
// Address: 0x10026E50
// Name: public: float C_BaseAnimating::SequenceDuration(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::SequenceDuration(C_BaseAnimating *this, CStudioHdr *pStudioHdr, int iSequence)
{
  int NumSeq_Internal; // eax

  if ( pStudioHdr != nullptr )
  {
    if ( pStudioHdr->m_pVModel != nullptr )
      NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
    else
      NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( iSequence < NumSeq_Internal && iSequence >= 0 )
      return Studio_Duration(pStudioHdr, iSequence, poseParameter: this->m_flPoseParameter);
    _DevWarning(a1: 2, a2: "C_BaseAnimating::SequenceDuration( %d ) out of range\n", iSequence);
  }
  return 0.1;
}

//------------------------------------------------------------------------------
// Address: 0x10026EC0
// Name: public: int C_BaseAnimating::LookupPoseParameter(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::LookupPoseParameter(C_BaseAnimating *this, CStudioHdr *pstudiohdr, const char *szName)
{
  int v4; // esi
  const mstudioposeparamdesc_t *v5; // eax

  if ( pstudiohdr == nullptr )
    return -1;
  v4 = 0;
  if ( CStudioHdr::GetNumPoseParameters(this: pstudiohdr) <= 0 )
    return -1;
  while ( 1 )
  {
    v5 = CStudioHdr::pPoseParameter(this: pstudiohdr, i: v4);
    if ( _V_stricmp(s1: (const char *)v5 + v5->sznameindex, s2: szName) == 0 )
      break;
    if ( ++v4 >= CStudioHdr::GetNumPoseParameters(this: pstudiohdr) )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10026F20
// Name: public: float C_BaseAnimating::SetPoseParameter(class CStudioHdr __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::SetPoseParameter(
        C_BaseAnimating *this,
        CStudioHdr *pStudioHdr,
        const char *szName,
        float flValue)
{
  int v5; // eax
  int v6; // esi
  float v8; // [esp+14h] [ebp-4h]

  v8 = flValue;
  v5 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr: pStudioHdr, szName);
  v6 = v5;
  if ( pStudioHdr == nullptr )
    return flValue;
  if ( v5 >= 0 )
  {
    v8 = Studio_SetPoseParameter(pStudioHdr, iParameter: v5, flValue, ctlValue: &flValue);
    this->m_flPoseParameter[v6] = flValue;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10026FA0
// Name: public: void C_BaseAnimating::ClearRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ClearRagdoll(C_BaseAnimating *this)
{
  CRagdoll *m_pRagdoll; // ecx
  void (__thiscall *dtr_IRagdoll)(struct CRagdoll *); // edx

  m_pRagdoll = this->m_pRagdoll;
  if ( m_pRagdoll != nullptr )
  {
    dtr_IRagdoll = m_pRagdoll->dtr_IRagdoll;
    this->m_pRagdoll = nullptr;
    ((void (__thiscall *)(CRagdoll *, int))dtr_IRagdoll)(a1: m_pRagdoll, a2: 1);
    C_BaseEntity::VPhysicsSetObject(this, pPhysics: nullptr);
    if ( vec3_origin.x != this->m_vecPreRagdollMins.x
      || vec3_origin.y != this->m_vecPreRagdollMins.y
      || vec3_origin.z != this->m_vecPreRagdollMins.z
      || vec3_origin.x != this->m_vecPreRagdollMaxs.x
      || vec3_origin.y != this->m_vecPreRagdollMaxs.y
      || vec3_origin.z != this->m_vecPreRagdollMaxs.z )
    {
      CCollisionProperty::SetCollisionBounds(
        this: &this->m_Collision,
        mins: &this->m_vecPreRagdollMins,
        maxs: &this->m_vecPreRagdollMaxs);
    }
  }
  this->m_builtRagdoll = false;
}

//------------------------------------------------------------------------------
// Address: 0x10027050
// Name: public: enum ModelScaleType_t C_BaseAnimating::GetModelScaleType(void)const
// Source: json
//------------------------------------------------------------------------------
ModelScaleType_t __thiscall C_BaseAnimating::GetModelScaleType(C_BaseAnimating *this)
{
  return this->m_ScaleType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10027060
// Name: void VCollideWireframe_ChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VCollideWireframe_ChangeCallback()
{
  C_BaseEntity *i; // esi

  for ( i = CClientEntityList::FirstBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index);
        i != nullptr;
        i = CClientEntityList::NextBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, pEnt: i) )
  {
    C_BaseEntity::UpdateVisibility(this: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027090
// Name: public: virtual bool C_BoneFollower::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BoneFollower::ShouldDraw(C_BoneFollower *this)
{
  return vcollide_wireframe.m_pParent != nullptr && vcollide_wireframe.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100270B0
// Name: private: class CBoneList __near * C_BaseAnimating::RecordBones(class CStudioHdr __near *,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBoneList *__thiscall C_BaseAnimating::RecordBones(C_BaseAnimating *this, CStudioHdr *hdr, matrix3x4_t *pBoneState)
{
  int v5; // ebx
  const QAngle *v6; // eax
  CBoneList *v7; // esi
  const studiohdr_t *m_pStudioHdr; // eax
  Vector *m_vecPos; // edi
  _DWORD *p_z; // esi
  int v11; // ecx
  int v12; // ecx
  const Vector *v13; // [esp-Ch] [ebp-ACh]
  matrix3x4_t output; // [esp+4h] [ebp-9Ch] BYREF
  matrix3x4_t parentTransform; // [esp+34h] [ebp-6Ch] BYREF
  matrix3x4_t inverted; // [esp+64h] [ebp-3Ch] BYREF
  int v17; // [esp+94h] [ebp-Ch]
  const matrix3x4_t *in2; // [esp+98h] [ebp-8h]
  CBoneList *boneList; // [esp+9Ch] [ebp-4h]

  if ( !ToolsEnabled() )
    return nullptr;
  v5 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseAnimating::RecordBones",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v13 = this->GetRenderOrigin(this: &this->IClientRenderable);
  v6 = this->GetRenderAngles(this: &this->IClientRenderable);
  AngleMatrix(angles: v6, position: v13, matrix: &parentTransform);
  if ( C_BaseAnimating::m_bBoneListInUse )
  {
    v7 = CBoneList::Alloc();
    boneList = v7;
  }
  else
  {
    boneList = &C_BaseAnimating::m_recordingBoneList;
    v7 = &C_BaseAnimating::m_recordingBoneList;
  }
  C_BaseAnimating::m_bBoneListInUse = true;
  *((_WORD *)v7 + 1) ^= (*((_WORD *)v7 + 1) ^ LOWORD(hdr->m_pStudioHdr->numbones)) & 0x7FFF;
  m_pStudioHdr = hdr->m_pStudioHdr;
  if ( hdr->m_pStudioHdr->numbones > 0 )
  {
    m_vecPos = v7->m_vecPos;
    v17 = 0;
    in2 = pBoneState;
    p_z = (_DWORD *)&v7->m_quatRot[0].z;
    do
    {
      v11 = v17 + m_pStudioHdr->boneindex;
      if ( (*(int *)((_BYTE *)&m_pStudioHdr->boneindex + v11) & 0x7FF00) != 0 )
      {
        v12 = *(int *)((char *)&m_pStudioHdr->version + v11);
        if ( v12 == -1 )
          MatrixInvert(in: &parentTransform, out: &inverted);
        else
          MatrixInvert(in: &pBoneState[v12], out: &inverted);
        ConcatTransforms(in1: &inverted, in2, out: &output);
        MatrixAngles(matrix: &output, q: (Quaternion *)(p_z - 2), pos: m_vecPos);
      }
      else
      {
        *(p_z - 2) = 0;
        *(p_z - 1) = 0;
        *p_z = 0;
        p_z[1] = 1065353216;
        m_vecPos->x = 0.0;
        m_vecPos->y = 0.0;
        m_vecPos->z = 0.0;
      }
      m_pStudioHdr = hdr->m_pStudioHdr;
      v17 += 216;
      ++in2;
      ++v5;
      ++m_vecPos;
      p_z += 4;
    }
    while ( v5 < m_pStudioHdr->numbones );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return boneList;
}

//------------------------------------------------------------------------------
// Address: 0x10027390
// Name: public: static bool CMemberScriptBinding2<class C_BaseAnimating __near *,void (C_BaseAnimating::*)(char const __near *,float),void,char const __near *,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<C_BaseAnimating *,void (__thiscall C_BaseAnimating::*)(char const *,float),void,char const *,float>::Call(
        void (__stdcall *pFunction)(const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 2 || pReturn != nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = prType;
  pFunction(a1: m_int, a2: pArguments[1].m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100273D0
// Name: public: static bool CMemberScriptBinding0<class C_BaseAnimating __near *,bool (C_BaseAnimating::*)(void),bool>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<C_BaseAnimating *,bool (__thiscall C_BaseAnimating::*)(void),bool>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_char = pFunction();
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100274A0
// Name: public: class C_BaseEntity __near * C_BaseEntity::GetEffectEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::GetEffectEntity(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hEffectEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10027720
// Name: public: void CInterpolatedVarArrayBase<float,1>::ClearHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::ClearHistory(CInterpolatedVarArrayBase<float,1> *this)
{
  int v2; // ebx
  int m_maxElement; // ecx
  int v4; // eax
  CInterpolatedVarEntryBase<float,1> *v5; // esi

  v2 = 0;
  if ( this->m_VarHistory.m_count != 0 )
  {
    do
    {
      m_maxElement = this->m_VarHistory.m_maxElement;
      v4 = v2 + this->m_VarHistory.m_firstElement;
      if ( v4 >= m_maxElement )
        v4 -= m_maxElement;
      v5 = &this->m_VarHistory.m_pElements[v4];
      C_BaseEntity::operator delete(pMem: v5->value);
      v5->value = nullptr;
      v5->count = 0;
      ++v2;
    }
    while ( v2 < this->m_VarHistory.m_count );
  }
  *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10027770
// Name: public: virtual void C_ClientRagdoll::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::OnRestore(C_ClientRagdoll *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  const char *ModelName; // eax
  CStudioHdr *v4; // eax
  CRagdoll *m_pRagdoll; // edi
  ragdoll_t *p_m_ragdoll; // edi
  int m_fFlags; // eax
  C_BaseEntity *EffectEntity; // eax
  C_EntityFlame *v9; // eax
  IVModelInfoClient_vtbl *v10; // ebx
  vcollide_t *v11; // eax
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-18h]
  char ModelIndex; // [esp+10h] [ebp-14h]

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    goto LABEL_11;
  ModelName = C_BaseEntity::GetModelName(this);
  C_BaseEntity::SetModel(this, pModelName: ModelName);
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  v4 = this->m_pStudioHdr;
  if ( v4 != nullptr && v4->m_pStudioHdr != nullptr )
  {
LABEL_11:
    m_pRagdoll = this->m_pRagdoll;
    if ( m_pRagdoll != nullptr )
    {
      p_m_ragdoll = &m_pRagdoll->m_ragdoll;
      if ( p_m_ragdoll != nullptr && p_m_ragdoll->list[0].pObject != nullptr )
      {
        m_fFlags = this->m_fFlags;
        if ( (m_fFlags & 0x20000000) != 0 )
        {
          DissolveEffect(pTarget: this, flTime: this->m_flEffectTime);
        }
        else if ( (m_fFlags & 0x10000000) != 0 )
        {
          EffectEntity = C_BaseEntity::GetEffectEntity(this);
          __RTDynamicCast(
            inptr: EffectEntity,
            VfDelta: 0,
            SrcType: &C_BaseEntity `RTTI Type Descriptor',
            TargetType: &C_EntityFlame `RTTI Type Descriptor',
            isReference: 0);
          v9 = FireEffect(pTarget: this);
          C_BaseEntity::SetEffectEntity(this, pEffectEnt: v9);
        }
        C_BaseEntity::VPhysicsSetObject(this, pPhysics: nullptr);
        C_BaseEntity::VPhysicsSetObject(this, pPhysics: p_m_ragdoll->list[0].pObject);
        ((void (__stdcall *)(_DWORD, int, int, _DWORD))this->SetupBones)(
          a1: 0,
          a2: -1,
          a3: 524032,
          a4: *(_DWORD *)(gpGlobals.m_Index + 12));
        p_m_ragdoll->list[0].parentIndex = -1;
        p_m_ragdoll->list[0].originParentSpace.x = 0.0;
        p_m_ragdoll->list[0].originParentSpace.y = 0.0;
        p_m_ragdoll->list[0].originParentSpace.z = 0.0;
        v10 = modelinfo->__vftable;
        ModelIndex = C_BaseEntity::GetModelIndex(this);
        v13 = C_BaseEntity::GetModelIndex(this);
        v11 = (vcollide_t *)((int (__thiscall *)(IVModelInfoClient *))v10->GetVCollide)(a1: modelinfo);
        RagdollActivate(ragdoll: p_m_ragdoll, pCollide: v11, modelIndex: v13, bForceWake: ModelIndex);
        v12 = C_BaseEntity::GetModelIndex(this);
        RagdollSetupAnimatedFriction(a1: (int)this, pPhysEnv: physenv, ragdoll: p_m_ragdoll, iModelIndex: v12);
        CRagdoll::BuildRagdollBounds(this: this->m_pRagdoll, ent: this);
        C_BaseEntity::RemoveFromLeafSystem(this);
        C_BaseEntity::AddToLeafSystem(this, bRenderWithViewModels: false);
        C_BaseEntity::DestroyShadow(this);
        C_BaseEntity::CreateShadow(this);
        ((void (__thiscall *)(C_ClientRagdoll *, int, int))this->SetNextClientThink)(a1: this, a2: -996040704, a3: 1);
        if ( this->m_bFadeOut )
          CRagdollLRURetirement::MoveToTopOfLRU(
            this: &s_RagdollLRU,
            pRagdoll: this,
            bImportant: this->m_bImportant,
            flForcedRetireTime: 0.0);
        NoteRagdollCreationTick(pRagdoll: this);
        C_BaseEntity::OnRestore(this);
        C_BaseAnimating::RagdollMoved(this);
      }
      else
      {
        this->m_bReleaseRagdoll = true;
        this->m_pRagdoll = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100279B0
// Name: public: void C_ClientRagdoll::HandleAnimatedFriction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::HandleAnimatedFriction(C_ClientRagdoll *this)
{
  CRagdoll *m_pRagdoll; // ecx
  float *p_listCount; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  _DWORD *v10; // edi
  IPhysicsObject *m_pPhysicsObject; // ecx
  float flDeltaTime; // [esp+20h] [ebp-4h]
  float flDeltaTimea; // [esp+20h] [ebp-4h]

  if ( this->m_iFrictionAnimState != -2 )
  {
    m_pRagdoll = this->m_pRagdoll;
    if ( m_pRagdoll != nullptr )
    {
      p_listCount = (float *)&m_pRagdoll->m_ragdoll.listCount;
      v4 = ((int (*)(void))m_pRagdoll->RagdollBoneCount)();
      if ( p_listCount != nullptr )
      {
        switch ( this->m_iFrictionAnimState )
        {
          case 0xFFFFFFFF:
            v5 = (int)p_listCount[227];
            this->m_iMinFriction = v5;
            v6 = (int)p_listCount[228];
            this->m_iMaxFriction = v6;
            if ( v5 == 0 && v6 == 0 )
              goto LABEL_13;
            this->m_iFrictionAnimState = 0;
            v7 = p_listCount[229];
            this->m_flFrictionModTime = v7;
            this->m_flFrictionTime = *(float *)(gpGlobals.m_Index + 12) + v7;
            this->m_iCurrentFriction = v5;
            break;
          case 0:
            flDeltaTime = this->m_flFrictionTime - *(float *)(gpGlobals.m_Index + 12);
            this->m_iCurrentFriction = (int)RemapValClamped(
                                              val: flDeltaTime,
                                              A: this->m_flFrictionModTime,
                                              B: 0.0,
                                              C: (float)this->m_iMinFriction,
                                              D: (float)this->m_iMaxFriction);
            if ( flDeltaTime <= 0.0 )
            {
              v8 = p_listCount[231];
              this->m_flFrictionModTime = v8;
              this->m_flFrictionTime = *(float *)(gpGlobals.m_Index + 12) + v8;
              this->m_iFrictionAnimState = 1;
            }
            break;
          case 1:
            if ( *(float *)(gpGlobals.m_Index + 12) > this->m_flFrictionTime )
            {
              v9 = p_listCount[230];
              this->m_flFrictionModTime = v9;
              this->m_flFrictionTime = *(float *)(gpGlobals.m_Index + 12) + v9;
              this->m_iFrictionAnimState = 2;
            }
            break;
          case 2:
            flDeltaTimea = this->m_flFrictionTime - *(float *)(gpGlobals.m_Index + 12);
            this->m_iCurrentFriction = (int)RemapValClamped(
                                              val: flDeltaTimea,
                                              A: 0.0,
                                              B: this->m_flFrictionModTime,
                                              C: (float)this->m_iMinFriction,
                                              D: (float)this->m_iMaxFriction);
            if ( flDeltaTimea <= 0.0 )
LABEL_13:
              this->m_iFrictionAnimState = -2;
            break;
          default:
            break;
        }
        if ( v4 > 0 )
        {
          v10 = p_listCount + 7;
          do
          {
            if ( *v10 != 0 )
              (*(void (__thiscall **)(_DWORD, _DWORD, float))(*(_DWORD *)*v10 + 32))(
                a1: *v10,
                a2: 0,
                a3: (float)this->m_iCurrentFriction);
            v10 += 6;
            --v4;
          }
          while ( v4 != 0 );
        }
        m_pPhysicsObject = this->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr )
          m_pPhysicsObject->Wake(this: m_pPhysicsObject);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027C40
// Name: public: virtual void C_ClientRagdoll::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::ClientThink(C_ClientRagdoll *this)
{
  Vector *v2; // eax
  int m_depth; // ecx
  Vector vMins; // [esp+10h] [ebp-30h] BYREF
  Vector vMaxs; // [esp+1Ch] [ebp-24h] BYREF
  Vector origin; // [esp+28h] [ebp-18h] BYREF
  _DWORD v7[3]; // [esp+34h] [ebp-Ch] BYREF

  if ( LOBYTE(this->m_flFrictionModTime) == 1 )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 4))(a1: (char *)this - 4);
  }
  else
  {
    if ( g_debug_ragdoll_visualize.m_pParent != nullptr && g_debug_ragdoll_visualize.m_pParent->m_Value.m_nValue != 0 )
    {
      v2 = (Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)this->m_CalcAbsoluteVelocityMutex.m_depth + 8))(a1: this->m_CalcAbsoluteVelocityMutex.m_depth);
      m_depth = this->m_CalcAbsoluteVelocityMutex.m_depth;
      origin = *v2;
      (*(void (__thiscall **)(int, Vector *, Vector *))(*(_DWORD *)m_depth + 12))(a1: m_depth, a2: &vMins, a3: &vMaxs);
      memset(v7, 0, sizeof(v7));
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, _DWORD *, _DWORD, int, _DWORD, int, _DWORD))debugoverlay->AddBoxOverlay)(
        a1: debugoverlay,
        a2: &origin,
        a3: &vMins,
        a4: &vMaxs,
        a5: v7,
        a6: 0,
        a7: 255,
        a8: 0,
        a9: 16,
        a10: 0);
    }
    C_ClientRagdoll::HandleAnimatedFriction(this: (C_ClientRagdoll *)((char *)this - 12));
    C_ClientRagdoll::FadeOut(this: (C_ClientRagdoll *)((char *)this - 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027D00
// Name: public: virtual class IClientModelRenderable __near * C_ClientRagdoll::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__thiscall C_ClientRagdoll::GetClientModelRenderable(C_ClientRagdoll *this)
{
  if ( C_BaseAnimating::GetClientModelRenderable(this, a2: (int)this) == nullptr
    || (int)this->m_pIk > 0
    || this == (C_ClientRagdoll *)4 )
  {
    return nullptr;
  }
  else
  {
    return &this->IClientThinkable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027D30
// Name: private: virtual void C_BaseAnimatingGameSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimatingGameSystem::LevelShutdownPostEntity(C_BaseAnimatingGameSystem *this)
{
  g_iPreviousBoneCounter = -1;
  if ( g_PreviousBoneSetups.m_Size != 0 )
  {
    _Msg(a1: "%d entities in bone setup array. Should have been cleaned up by now\n", g_PreviousBoneSetups.m_Size);
    g_PreviousBoneSetups.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027D60
// Name: public: virtual enum ShadowType_t C_BaseAnimating::ShadowCastType(void)
// Source: json
//------------------------------------------------------------------------------
ShadowType_t __thiscall C_BaseAnimating::ShadowCastType(C_BaseAnimating *this)
{
  CStudioHdr *v2; // edi

  if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: (C_BaseAnimating *)((char *)this - 4));
  v2 = *(CStudioHdr **)&this->m_nOldMuzzleFlashParity;
  if ( v2 != nullptr
    && v2->m_pStudioHdr != nullptr
    && CStudioHdr::SequencesAvailable(this: *(CStudioHdr **)&this->m_nOldMuzzleFlashParity)
    && (this->m_nWaterType & 0x30) == 0
    && (cl_minimal_rtt_shadows.m_pParent == nullptr
     || cl_minimal_rtt_shadows.m_pParent->m_Value.m_nValue == 0
     || LOBYTE(this->m_pBoneMergeCache) != 0) )
  {
    return C_BaseAnimating::GetShadowCastTypeForStudio(this: (C_BaseAnimating *)((char *)this - 4), pStudioHdr: v2);
  }
  else
  {
    return SHADOWS_NONE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027DD0
// Name: private: void C_BaseAnimating::UpdateRelevantInterpolatedVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::UpdateRelevantInterpolatedVars(C_BaseAnimating *this)
{
  IMDLCache *v1; // edi
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *ModelPtr; // eax

  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( C_BaseEntity::GetPredictable(this) || this->IsClientCreated(this) )
    goto LABEL_11;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && (ModelPtr = C_BaseAnimating::GetModelPtr(this), CStudioHdr::SequencesAvailable(this: ModelPtr))
    && this->WantsInterpolatedVars(this) )
  {
    C_BaseAnimating::AddBaseAnimatingInterpolatedVars(this);
  }
  else
  {
LABEL_11:
    C_BaseEntity::RemoveVar(this, data: this->m_flEncodedController, bAssert: false);
    C_BaseEntity::RemoveVar(this, data: this->m_flPoseParameter, bAssert: false);
    C_BaseEntity::RemoveVar(this, data: &this->m_flCycle, bAssert: false);
  }
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10027EA0
// Name: public: int C_BaseAnimating::LookupBone(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::LookupBone(C_BaseAnimating *this, const char *szName)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return Studio_BoneIndexByName(pStudioHdr: m_pStudioHdr, pName: szName);
}

//------------------------------------------------------------------------------
// Address: 0x10027EF0
// Name: public: void C_BaseAnimating::GetBoneTransform(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetBoneTransform(C_BaseAnimating *this, int iBone, matrix3x4_t *pBoneToWorld)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && iBone >= 0
    && iBone < m_pStudioHdr->m_pStudioHdr->numbones )
  {
    if ( this->m_iMostRecentModelBoneCounter != g_iModelBoneCounter )
      ((void (__stdcall *)(_DWORD, int, int, _DWORD))this->SetupBones)(
        a1: 0,
        a2: -1,
        a3: 524032,
        a4: *(_DWORD *)(gpGlobals.m_Index + 12));
    MatrixCopy(in: &this->m_BoneAccessor.m_pBones[iBone], out: pBoneToWorld);
  }
  else
  {
    C_BaseEntity::CalcAbsolutePosition(this);
    MatrixCopy(in: &this->m_rgflCoordinateFrame, out: pBoneToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027FB0
// Name: public: void C_BaseAnimating::ScriptSetPoseParameter(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ScriptSetPoseParameter(C_BaseAnimating *this, const char *szName, float fValue)
{
  CStudioHdr *m_pStudioHdr; // edi
  int v5; // eax
  int v6; // ebx

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v5 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr: m_pStudioHdr, szName);
    v6 = v5;
    if ( v5 >= 0 )
    {
      Studio_SetPoseParameter(pStudioHdr: m_pStudioHdr, iParameter: v5, flValue: fValue, ctlValue: (float *)&szName);
      LODWORD(this->m_flPoseParameter[v6]) = szName;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028030
// Name: public: virtual void C_BaseAnimating::SaveRagdollInfo(int,struct matrix3x4_t const __near &,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SaveRagdollInfo(
        C_BaseAnimating *this,
        int numbones,
        matrix3x4a_t *cameraTransform,
        CBoneAccessor *pBoneToWorld)
{
  bool v5; // zf
  CStudioHdr *m_pStudioHdr; // edi
  RagdollInfo_t *v7; // eax
  int v8; // eax
  int v10; // ebx
  int v11; // edi
  int v12; // esi
  matrix3x4a_t *v13; // edx
  matrix3x4_t output; // [esp+8h] [ebp-68h] BYREF
  matrix3x4_t inverted; // [esp+38h] [ebp-38h] BYREF
  C_BaseAnimating *v16; // [esp+68h] [ebp-8h]
  int v17; // [esp+6Ch] [ebp-4h]
  _DWORD *numbonesa; // [esp+78h] [ebp+8h]

  v5 = this->m_pStudioHdr == nullptr;
  v16 = this;
  if ( v5 && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    if ( this->m_pRagdollInfo == nullptr )
    {
      v7 = (RagdollInfo_t *)MemAlloc_Alloc(nSize: 0x1C0Cu);
      this->m_pRagdollInfo = v7;
      if ( v7 == nullptr )
      {
        _Msg(a1: "Memory allocation of RagdollInfo_t failed!\n");
        return;
      }
      memset(dst: (unsigned __int8 *)v7, value: 0, count: sizeof(RagdollInfo_t));
    }
    v8 = (int)m_pStudioHdr->m_pStudioHdr + m_pStudioHdr->m_pStudioHdr->boneindex;
    this->m_pRagdollInfo->m_bActive = true;
    this->m_pRagdollInfo->m_flSaveTime = *(float *)(gpGlobals.m_Index + 12);
    this->m_pRagdollInfo->m_nNumBones = numbones;
    if ( numbones > 0 )
    {
      v10 = 0;
      v11 = 0;
      v12 = 0;
      numbonesa = (_DWORD *)(v8 + 4);
      v17 = numbones;
      do
      {
        if ( *numbonesa == -1 )
          v13 = cameraTransform;
        else
          v13 = &pBoneToWorld->m_pBones[*numbonesa];
        MatrixInvert(in: v13, out: &inverted);
        ConcatTransforms(in1: &inverted, in2: &pBoneToWorld->m_pBones[v12], out: &output);
        MatrixAngles(
          matrix: &output,
          q: &v16->m_pRagdollInfo->m_rgBoneQuaternion[v10],
          pos: &v16->m_pRagdollInfo->m_rgBonePos[v11]);
        numbonesa += 54;
        ++v12;
        ++v11;
        ++v10;
        --v17;
      }
      while ( v17 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028180
// Name: public: void C_BaseAnimating::MaintainSequenceTransitions(class IBoneSetup __near &,float,class Vector __near * const,class Quaternion __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::MaintainSequenceTransitions(
        C_BaseAnimating *this,
        IBoneSetup *boneSetup,
        float flCycle,
        Vector *pos,
        Quaternion *q)
{
  CStudioHdr *StudioHdr; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  CStudioHdr *v9; // eax
  int v10; // eax
  int v11; // eax
  C_AnimationLayer *m_pMemory; // esi
  double v13; // st7
  C_BaseAnimating_vtbl *v14; // ebx
  char *v15; // esi
  CStudioHdr *v16; // eax
  double v17; // st7
  int v18; // ebx
  CStudioHdr *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm0_4
  int m_nValue; // ebx
  int v23; // ebx
  CStudioHdr *v24; // eax
  const studiohdr_t *m_pStudioHdr; // eax
  int v26; // edx
  mstudioseqdesc_t *v27; // eax
  int flCurCycle; // [esp+14h] [ebp-38h]
  int flCurCycle_4; // [esp+18h] [ebp-34h]
  bool flCurPlaybackRate; // [esp+1Ch] [ebp-30h]
  bool flCurTime; // [esp+20h] [ebp-2Ch]
  float flCurTimea; // [esp+20h] [ebp-2Ch]
  int flCurTimeb; // [esp+20h] [ebp-2Ch]
  float v34; // [esp+30h] [ebp-1Ch]
  float v35; // [esp+34h] [ebp-18h]
  float dt; // [esp+38h] [ebp-14h]
  int i; // [esp+3Ch] [ebp-10h]
  int j; // [esp+40h] [ebp-Ch]
  float cycle; // [esp+44h] [ebp-8h]
  float flCycleb; // [esp+58h] [ebp+Ch]
  float flCyclea; // [esp+58h] [ebp+Ch]

  if ( IBoneSetup::GetStudioHdr(this: boneSetup) != nullptr )
  {
    if ( prediction->InPrediction(this: prediction) )
    {
      this->m_nPrevNewSequenceParity = this->m_nNewSequenceParity;
      return;
    }
    flCurTime = (this->m_fEffects & 8) == 0;
    flCurPlaybackRate = this->m_nNewSequenceParity != this->m_nPrevNewSequenceParity;
    flCurCycle_4 = this->m_nSequence;
    StudioHdr = IBoneSetup::GetStudioHdr(this: boneSetup);
    CSequenceTransitioner::CheckForSequenceChange(
      this: &this->m_SequenceTransitioner,
      hdr: StudioHdr,
      nCurSequence: flCurCycle_4,
      bForceNewSequence: flCurPlaybackRate,
      bInterpolate: flCurTime);
    v7 = 1.0 - this->m_flFrozen;
    this->m_nPrevNewSequenceParity = this->m_nNewSequenceParity;
    if ( v7 >= 0.0 )
    {
      if ( v7 > 1.0 )
        v7 = 1.0;
    }
    else
    {
      v7 = 0.0;
    }
    v8 = this->m_flPlaybackRate * v7;
    flCurTimea = *(float *)(gpGlobals.m_Index + 12);
    flCurCycle = this->m_nSequence;
    v9 = IBoneSetup::GetStudioHdr(this: boneSetup);
    CSequenceTransitioner::UpdateCurrent(
      this: &this->m_SequenceTransitioner,
      hdr: v9,
      nCurSequence: flCurCycle,
      flCurCycle: flCycle,
      flCurPlaybackRate: v8,
      flCurTime: flCurTimea);
    v10 = this->m_SequenceTransitioner.m_animationQueue.m_Size - 2;
    i = v10;
    if ( v10 >= 0 )
    {
      v11 = 40 * v10;
      for ( j = v11; ; v11 = j )
      {
        m_pMemory = this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_pMemory;
        v13 = *(float *)(gpGlobals.m_Index + 12) - *(float *)((char *)&m_pMemory->m_flLayerAnimtime + v11);
        v14 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        v15 = (char *)m_pMemory + v11;
        dt = v13;
        flCurTimeb = *((_DWORD *)v15 + 3);
        v35 = *((float *)v15 + 7);
        flCycleb = *((float *)v15 + 6);
        v16 = IBoneSetup::GetStudioHdr(this: boneSetup);
        v17 = ((double (__thiscall *)(C_BaseAnimating *, CStudioHdr *, int))v14->GetSequenceCycleRate)(
                a1: this,
                a2: v16,
                a3: flCurTimeb);
        v18 = *((_DWORD *)v15 + 3);
        flCyclea = v17 * (flCycleb * dt) + v35;
        v19 = IBoneSetup::GetStudioHdr(this: boneSetup);
        if ( (GetSequenceFlags(pstudiohdr: v19, sequence: v18) & 1) != 0 )
        {
          v20 = flCyclea - (double)(int)flCyclea;
          cycle = v20;
          if ( v20 >= 0.0 )
            goto LABEL_18;
          v21 = v20 + 1.0;
        }
        else
        {
          v21 = 0.0;
          if ( flCyclea >= 0.0 )
          {
            v21 = 0.99900001;
            if ( flCyclea <= 0.99900001 )
              v21 = flCyclea;
          }
        }
        cycle = v21;
LABEL_18:
        if ( r_sequence_debug.m_pParent != nullptr )
          m_nValue = r_sequence_debug.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( m_nValue == this->entindex(this: &this->IClientNetworkable) )
        {
          v23 = *((_DWORD *)v15 + 3);
          v34 = *((float *)v15 + 5);
          v24 = IBoneSetup::GetStudioHdr(this: boneSetup);
          if ( v24->m_pVModel != nullptr )
          {
            v27 = CStudioHdr::pSeqdesc_Internal(this: v24, i: v23);
          }
          else
          {
            m_pStudioHdr = v24->m_pStudioHdr;
            v26 = v23;
            if ( v23 < 0 || v23 >= m_pStudioHdr->numlocalseq )
              v26 = 0;
            v27 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v26 + m_pStudioHdr->localseqindex);
          }
          DevMsgRT(
            pMsg: "%8.4f : %30s : %5.3f : %4.2f  +\n",
            *(float *)(gpGlobals.m_Index + 12),
            (const char *)v27 + v27->szlabelindex,
            cycle,
            v34);
        }
        IBoneSetup::AccumulatePose(
          this: boneSetup,
          pos,
          q,
          sequence: *((_DWORD *)v15 + 3),
          cycle,
          flWeight: *((float *)v15 + 5),
          flTime: *(float *)(gpGlobals.m_Index + 12),
          pIKContext: this->m_pIk);
        j -= 40;
        if ( --i < 0 )
          return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028470
// Name: private: bool C_BaseAnimating::PutAttachment(int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::PutAttachment(C_BaseAnimating *this, int number, const matrix3x4_t *attachmentToWorld)
{
  float v3; // xmm7_4
  CAttachmentData *v4; // eax
  int v5; // edx
  float v6; // xmm4_4
  float v7; // xmm2_4

  if ( number < 1 || number > this->m_Attachments.m_Size )
    return 0;
  v3 = *(float *)(gpGlobals.m_Index + 16);
  v4 = &this->m_Attachments.m_Memory.m_pMemory[number - 1];
  if ( v3 > 0.0 && (v5 = (2 * *((_DWORD *)v4 + 18)) >> 1) > 0 && v5 == *(_DWORD *)(gpGlobals.m_Index + 4) - 1 )
  {
    v6 = (float)(1.0 / v3) * (float)(attachmentToWorld->m_flMatVal[1][3] - v4->m_AttachmentToWorld.m_flMatVal[1][3]);
    v7 = (float)(attachmentToWorld->m_flMatVal[2][3] - v4->m_AttachmentToWorld.m_flMatVal[2][3]) * (float)(1.0 / v3);
    v4->m_vOriginVelocity.x = (float)(1.0 / v3)
                            * (float)(attachmentToWorld->m_flMatVal[0][3] - v4->m_AttachmentToWorld.m_flMatVal[0][3]);
    v4->m_vOriginVelocity.y = v6;
    v4->m_vOriginVelocity.z = v7;
  }
  else
  {
    v4->m_vOriginVelocity.x = 0.0;
    v4->m_vOriginVelocity.y = 0.0;
    v4->m_vOriginVelocity.z = 0.0;
  }
  *((_DWORD *)v4 + 18) ^= (*((_DWORD *)v4 + 18) ^ *(_DWORD *)(gpGlobals.m_Index + 4)) & 0x7FFFFFFF;
  *((_BYTE *)v4 + 76) &= ~1u;
  v4->m_AttachmentToWorld = *attachmentToWorld;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028590
// Name: public: virtual void C_BaseAnimating::InvalidateAttachments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::InvalidateAttachments(C_BaseAnimating *this)
{
  int v1; // edx
  int v2; // esi

  v1 = 0;
  if ( this->m_Attachments.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      *((_DWORD *)&this->m_Attachments.m_Memory.m_pMemory[v2] + 18) |= 0x7FFFFFFFu;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_Attachments.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100285C0
// Name: private: void C_BaseAnimating::SetupBones_AttachmentHelper(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetupBones_AttachmentHelper(C_BaseAnimating *this, CStudioHdr *hdr)
{
  CStudioHdr *v2; // edi
  int v3; // esi
  const mstudioattachment_t *v4; // ebx
  int AttachmentBone; // eax
  int v6; // edi
  C_BaseAnimating *v7; // edi
  matrix3x4_t world; // [esp+4h] [ebp-4Ch] BYREF
  Vector vecWorldBonePos; // [esp+34h] [ebp-1Ch] BYREF
  Vector vecLocalBonePos; // [esp+40h] [ebp-10h] BYREF
  C_BaseAnimating *v11; // [esp+4Ch] [ebp-4h]

  v2 = hdr;
  v11 = this;
  if ( hdr != nullptr && CStudioHdr::GetNumAttachments(this: hdr) != 0 )
  {
    v3 = 0;
    if ( CStudioHdr::GetNumAttachments(this: hdr) > 0 )
    {
      while ( 1 )
      {
        v4 = CStudioHdr::pAttachment(this: v2, i: v3);
        AttachmentBone = CStudioHdr::GetAttachmentBone(this: v2, i: v3);
        v6 = AttachmentBone;
        if ( (v4->flags & 0x10000) != 0 )
        {
          MatrixGetColumn(in: &v4->local, column: 3, out: &vecLocalBonePos);
          VectorTransform(in1: &vecLocalBonePos.x, in2: &v11->m_BoneAccessor.m_pBones[v6], out: &vecWorldBonePos.x);
          SetIdentityMatrix(matrix: &world);
          MatrixSetColumn(in: &vecWorldBonePos, column: 3, out: &world);
          v7 = v11;
        }
        else
        {
          v7 = v11;
          ConcatTransforms(in1: &v11->m_BoneAccessor.m_pBones[AttachmentBone], in2: &v4->local, out: &world);
        }
        v7->FormatViewModelAttachment(this: v7, a2: v3++, a3: &world);
        C_BaseAnimating::PutAttachment(this: v7, number: v3, attachmentToWorld: &world);
        if ( v3 >= CStudioHdr::GetNumAttachments(this: hdr) )
          break;
        v2 = hdr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100286D0
// Name: public: virtual bool C_BaseAnimating::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::GetAttachment(C_BaseAnimating *this, int number, Vector *origin, QAngle *angles)
{
  int v5; // ecx
  int v6; // esi

  if ( number >= 1
    && number <= this->m_Attachments.m_Memory.m_nGrowSize
    && (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 864))(a1: (char *)this - 4) != 0 )
  {
    v5 = *(_DWORD *)&this->m_isJiggleBonesEnabled;
    v6 = v5 + 80 * number - 80;
    if ( (*(_BYTE *)(v5 + 80 * number - 4) & 1) == 0 )
    {
      MatrixAngles(src: (const VMatrix *)(v5 + 80 * number - 80), vAngles: (QAngle *)(v6 + 48));
      *(_BYTE *)(v6 + 76) |= 1u;
    }
    *angles = *(QAngle *)(v6 + 48);
    origin->x = *(float *)(v6 + 12);
    origin->y = *(float *)(v6 + 28);
    origin->z = *(float *)(v6 + 44);
    return 1;
  }
  else
  {
    *origin = *(Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
    *angles = *(QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 44))(a1: (char *)this - 4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100287A0
// Name: public: virtual bool C_BaseAnimating::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::GetAttachment(C_BaseAnimating *this, int number, matrix3x4_t *matrix)
{
  if ( number < 1
    || number > this->m_Attachments.m_Memory.m_nGrowSize
    || (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 864))(a1: (char *)this - 4) == 0 )
  {
    return 0;
  }
  *matrix = *(matrix3x4_t *)(*(_DWORD *)&this->m_isJiggleBonesEnabled + 80 * number - 80);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028830
// Name: public: virtual bool C_BaseAnimating::GetAttachmentVelocity(int,class Vector __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::GetAttachmentVelocity(
        C_BaseAnimating *this,
        int number,
        Vector *originVel,
        Quaternion *angleVel)
{
  if ( number < 1 || number > this->m_Attachments.m_Size || !this->CalcAttachments(this) )
    return 0;
  *originVel = this->m_Attachments.m_Memory.m_pMemory[number - 1].m_vOriginVelocity;
  angleVel->x = 0.0;
  angleVel->y = 0.0;
  angleVel->z = 0.0;
  angleVel->w = 0.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100288B0
// Name: public: virtual bool CTraceFilterSkipNPCsAndPlayers::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterSkipNPCsAndPlayers::ShouldHitEntity(
        CTraceFilterSkipNPCsAndPlayers *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  IHandleEntity *m_pEntity; // esi
  IHandleEntity_vtbl *v5; // ecx

  if ( CTraceFilterSimple::ShouldHitEntity(this, a2: (int)pServerEntity, pHandleEntity: pServerEntity, contentsMask) )
  {
    m_pEntity = (IHandleEntity *)((int (__thiscall *)(IHandleEntity *))pServerEntity->__vftable[2].SetRefEHandle)(a1: pServerEntity);
    if ( m_pEntity == nullptr )
      return 1;
    while ( m_pEntity->__vftable[49].GetRefEHandle(this: m_pEntity) == nullptr
         && m_pEntity->__vftable[48].GetRefEHandle(this: m_pEntity) == nullptr )
    {
      v5 = m_pEntity[189].__vftable;
      if ( v5 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != (unsigned int)v5 >> 16 )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      }
      if ( m_pEntity == nullptr )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10028940
// Name: public: bool C_BaseAnimating::GetPoseParameterRange(int,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::GetPoseParameterRange(
        C_BaseAnimating *this,
        int index,
        float *minValue,
        float *maxValue)
{
  CStudioHdr *m_pStudioHdr; // esi
  const mstudioposeparamdesc_t *v6; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && index >= 0
    && index < CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr) )
  {
    v6 = CStudioHdr::pPoseParameter(this: m_pStudioHdr, i: index);
    *minValue = v6->start;
    *maxValue = v6->end;
    return 1;
  }
  else
  {
    *minValue = 0.0;
    *maxValue = 1.0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100289D0
// Name: public: bool C_BaseAnimating::HitboxToWorldTransforms(struct matrix3x4_t __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::HitboxToWorldTransforms(C_BaseAnimating *this, matrix3x4_t **pHitboxToWorld)
{
  IMDLCache *v3; // edi
  CStudioHdr *m_pStudioHdr; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx

  if ( this->m_iMostRecentModelBoneCounter != g_iModelBoneCounter )
  {
    v3 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    if ( this->GetModel(this: &this->IClientRenderable) == nullptr )
      goto LABEL_3;
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr
      || m_pStudioHdr->m_pStudioHdr == nullptr
      || (v6 = (int)m_pStudioHdr->m_pStudioHdr + 12 * this->m_nHitboxSet + m_pStudioHdr->m_pStudioHdr->hitboxsetindex) == 0
      || *(_DWORD *)(v6 + 4) == 0 )
    {
LABEL_3:
      v3->EndLock(this: v3);
      return 0;
    }
    ((void (__thiscall *)(IClientRenderable *, _DWORD, int, int, _DWORD))this->SetupBones)(
      a1: &this->IClientRenderable,
      a2: 0,
      a3: -1,
      a4: 256,
      a5: *(_DWORD *)(gpGlobals.m_Index + 12));
    v3->EndLock(this: v3);
  }
  v7 = 0;
  if ( this->m_CachedBoneData.m_Size > 0 )
  {
    v8 = 0;
    do
      pHitboxToWorld[v7++] = &this->m_CachedBoneData.m_Memory.m_pMemory[v8++];
    while ( v7 < this->m_CachedBoneData.m_Size );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028AD0
// Name: public: virtual bool C_BaseAnimating::OnInternalDrawModel(struct ClientModelRenderInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::OnInternalDrawModel(C_BaseAnimating *this, ClientModelRenderInfo_t *pInfo)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hLightingOrigin.m_Index;
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
      pInfo->pLightingOrigin = (const Vector *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[3].SetRefEHandle)(a1: m_pEntity);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028B30
// Name: public: void C_BaseAnimating::DoInternalDrawModel(class IMatRenderContext __near *,struct ClientModelRenderInfo_t __near *,struct DrawModelState_t __near *,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::DoInternalDrawModel(
        C_BaseAnimating *this,
        IMatRenderContext *pRenderContext,
        ClientModelRenderInfo_t *pInfo,
        DrawModelState_t *pState,
        matrix3x4_t *pBoneToWorldArray)
{
  IVModelInfoClient_vtbl *v6; // edi
  int ModelIndex; // eax
  vcollide_t *v8; // eax
  vcollide_t *v9; // edi
  const QAngle *v10; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  const Vector *v12; // [esp-8h] [ebp-70h]
  matrix3x4_t v13; // [esp+8h] [ebp-60h] BYREF
  matrix3x4_t matrix; // [esp+38h] [ebp-30h] BYREF

  if ( pState != nullptr )
    modelrender->DrawModelExecute(this: modelrender, a2: pRenderContext, a3: pState, a4: pInfo, a5: pBoneToWorldArray);
  if ( vcollide_wireframe.m_pParent != nullptr && vcollide_wireframe.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_pRagdoll != nullptr && this->m_bClientSideRagdoll )
    {
      this->m_pRagdoll->DrawWireframe(this: this->m_pRagdoll);
    }
    else if ( this->m_Collision.m_nSolidType.m_Value != 0
           && (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0
           && this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_VPHYSICS )
    {
      v6 = modelinfo->__vftable;
      ModelIndex = C_BaseEntity::GetModelIndex(this);
      v8 = v6->GetVCollide(this: modelinfo, a2: ModelIndex);
      v9 = v8;
      if ( v8 != nullptr && (*(_WORD *)v8 & 0x7FFF) == 1 )
      {
        v12 = this->GetAbsOrigin(this);
        v10 = this->GetAbsAngles(this);
        AngleMatrix(angles: v10, position: v12, &matrix);
        engine->DebugDrawPhysCollide(this: engine, a2: *v9->solids, a3: nullptr, a4: &matrix, a5: &debugColor_0);
        m_pPhysicsObject = this->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr )
        {
          m_pPhysicsObject->GetPositionMatrix(this: m_pPhysicsObject, a2: &v13);
          engine->DebugDrawPhysCollide(this: engine, a2: *v9->solids, a3: nullptr, a4: &v13, a5: &debugColorPhys);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028C80
// Name: public: virtual void C_BaseAnimating::ProcessMuzzleFlashEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ProcessMuzzleFlashEvent(C_BaseAnimating *this)
{
  dlight_t *v2; // esi
  int v3; // eax
  QAngle dummyAngles; // [esp+4h] [ebp-18h] BYREF
  Vector vAttachment; // [esp+10h] [ebp-Ch] BYREF

  if ( muzzleflash_light.m_pParent != nullptr
    && muzzleflash_light.m_pParent->m_Value.m_nValue != 0
    && this->m_Attachments.m_Size > 0 )
  {
    this->GetAttachment_2(this: &this->IClientRenderable, a2: 1, a3: &vAttachment, a4: &dummyAngles);
    v2 = effects->CL_AllocElight(this: effects, a2: this->index + 0x40000000);
    v2->origin = vAttachment;
    v3 = random->RandomInt(this: random, a2: 32, a3: 64);
    v2->radius = (float)v3;
    v2->decay = (float)v3 * 20.0;
    v2->die = *(float *)(gpGlobals.m_Index + 12) + 0.050000001;
    v2->color = (ColorRGBExp32)88129791;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028D50
// Name: public: virtual int C_BaseAnimating::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::LookupAttachment(C_BaseAnimating *this, const char *pAttachmentName)
{
  C_BaseAnimating *v2; // esi
  const CStudioHdr *m_pStudioHdr; // esi

  v2 = (C_BaseAnimating *)((char *)this - 4);
  if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: v2);
  m_pStudioHdr = v2->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return Studio_FindAttachment(pStudioHdr: m_pStudioHdr, pAttachmentName) + 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10028DA0
// Name: public: void C_BaseAnimating::ClientSideAnimationChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ClientSideAnimationChanged(C_BaseAnimating *this)
{
  IMDLCache *v2; // edi
  clientanimating_t *v3; // ebx
  bool v4; // bl
  CStudioHdr *m_pStudioHdr; // eax
  int nCurSequence; // [esp+4h] [ebp-4h]

  if ( this->m_bClientSideAnimation && this->m_ClientSideAnimationListHandle != -1 )
  {
    v2 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    v3 = &g_ClientSideAnimationList.m_Memory.m_pMemory[this->m_ClientSideAnimationListHandle];
    v3->flags = this->ComputeClientSideAnimationFlags(this);
    v4 = (this->m_fEffects & 8) != 0;
    nCurSequence = this->m_nSequence;
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    CSequenceTransitioner::CheckForSequenceChange(
      this: &this->m_SequenceTransitioner,
      hdr: m_pStudioHdr,
      nCurSequence,
      bForceNewSequence: this->m_nNewSequenceParity != this->m_nPrevNewSequenceParity,
      bInterpolate: !v4);
    v2->EndLock(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028E80
// Name: public: virtual bool C_BaseAnimating::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseAnimating::TestCollision(
        C_BaseAnimating *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  if ( !ray->m_IsRay )
  {
    if ( (this->m_Collision.m_usSolidFlags.m_Value & 2) != 0 )
    {
      this->TestHitboxes(this, a2: ray, a3: fContentsMask, a4: tr);
      return true;
    }
    return false;
  }
  if ( (this->m_Collision.m_usSolidFlags.m_Value & 1) == 0 )
    return false;
  if ( !this->TestHitboxes(this, a2: ray, a3: fContentsMask, a4: tr) )
    return true;
  return tr->fraction < 1.0 || tr->allsolid || tr->startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x10028F10
// Name: public: void C_BaseAnimating::SetCycle(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetCycle(C_BaseAnimating *this, float flCycle)
{
  if ( this->m_flCycle.m_Val != flCycle )
  {
    this->m_flCycle.m_Val = flCycle;
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028F40
// Name: public: void C_BaseAnimating::ExtractBbox(int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ExtractBbox(C_BaseAnimating *this, int nSequence, Vector *mins, Vector *maxs)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  ExtractBbox(pstudiohdr: m_pStudioHdr, sequence: nSequence, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10028F90
// Name: public: float C_BaseAnimating::GetSequenceGroundSpeed(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge C_BaseAnimating::GetSequenceGroundSpeed@<st0>(
        C_BaseAnimating *this@<ecx>,
        int a2@<ebp>,
        CStudioHdr *pStudioHdr,
        int iSequence)
{
  int NumSeq_Internal; // eax
  __int128 v5; // xmm0
  __int128 v7; // [esp-20h] [ebp-2Ch] BYREF
  float v8; // [esp-8h] [ebp-14h]
  float v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+0h] [ebp-Ch]
  void *v11; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v10 = a2;
  v11 = retaddr;
  v8 = *(float *)&this;
  if ( pStudioHdr == nullptr )
    goto LABEL_10;
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( iSequence >= NumSeq_Internal || iSequence < 0 )
  {
    _DevWarning(a1: 2, a2: "C_BaseAnimating::SequenceDuration( %d ) out of range\n", iSequence);
LABEL_10:
    v9 = 0.1;
    goto LABEL_8;
  }
  v9 = Studio_Duration(pStudioHdr, iSequence, poseParameter: (const float *)(LODWORD(v8) + 2732));
  if ( v9 > 0.0 )
  {
LABEL_8:
    GetSequenceLinearMotion(
      pstudiohdr: pStudioHdr,
      iSequence,
      poseParameter: (const float *)(LODWORD(v8) + 2732),
      pVec: (Vector *)((char *)&v7 + 4));
    v8 = *((float *)&v7 + 1) * *((float *)&v7 + 1);
    v5 = 0;
    *(float *)&v5 = fsqrt(
                      (float)((float)(*((float *)&v7 + 1) * *((float *)&v7 + 1))
                            + (float)(*((float *)&v7 + 3) * *((float *)&v7 + 3)))
                    + (float)(*((float *)&v7 + 2) * *((float *)&v7 + 2)));
    v7 = v5;
    return *(float *)&v5 / v9;
  }
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100290A0
// Name: public: virtual float C_BaseAnimating::FrameAdvance(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::FrameAdvance(C_BaseAnimating *this, float flInterval)
{
  CStudioHdr *m_pStudioHdr; // edi
  float v5; // xmm0_4
  float m_flPlaybackRate; // xmm1_4
  C_BaseAnimating_vtbl *v7; // edx
  float (__thiscall *GetServerIntendedCycle)(C_BaseAnimating *); // eax
  float m_Val; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  int v13; // eax
  float v14; // xmm0_4
  float curtime; // [esp+28h] [ebp-Ch]
  float serverCycle; // [esp+2Ch] [ebp-8h]
  float addcycle; // [esp+30h] [ebp-4h]
  float addcyclea; // [esp+30h] [ebp-4h]
  float addcycleb; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0.0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0.0;
  curtime = *(float *)(gpGlobals.m_Index + 12);
  if ( flInterval == 0.0 )
  {
    flInterval = *(float *)(gpGlobals.m_Index + 12) - this->m_flAnimTime;
    if ( flInterval <= 0.001 )
      return 0.0;
  }
  if ( this->m_flAnimTime == 0.0 )
    flInterval = 0.0;
  addcycle = this->GetSequenceCycleRate(this, a2: m_pStudioHdr, a3: this->m_nSequence);
  v5 = 1.0 - this->m_flFrozen;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  m_flPlaybackRate = this->m_flPlaybackRate;
  v7 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  this->m_prevClientCycle = this->m_flCycle.m_Val;
  GetServerIntendedCycle = v7->GetServerIntendedCycle;
  this->m_prevClientAnimTime = this->m_flAnimTime;
  addcyclea = (float)(m_flPlaybackRate * v5) * (float)(addcycle * flInterval);
  if ( ((double (__thiscall *)(C_BaseAnimating *))GetServerIntendedCycle)(a1: this) != -1.0 )
  {
    serverCycle = this->GetServerIntendedCycle(this);
    m_Val = this->m_flCycle.m_Val;
    v10 = serverCycle - m_Val;
    if ( (float)(serverCycle - m_Val) >= -0.80000001 )
    {
      if ( (float)(serverCycle - m_Val) <= 0.0 )
      {
LABEL_22:
        ((void (__thiscall *)(C_BaseAnimating *, int))this->SetServerIntendedCycle)(a1: this, a2: -1082130432);
        goto LABEL_23;
      }
    }
    else
    {
      v10 = v10 + 1.0;
    }
    v11 = addcyclea;
    v12 = (float)(v10 + addcyclea) * 0.5;
    addcyclea = v12;
    if ( v12 > 0.1 )
    {
      v12 = 0.1;
      addcyclea = 0.1;
    }
    v13 = ((int (__thiscall *)(IClientNetworkable *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->entindex)(
            a1: &this->IClientNetworkable,
            a2: COERCE_UNSIGNED_INT64(m_Val),
            a3: HIDWORD(COERCE_UNSIGNED_INT64(m_Val)),
            a4: COERCE_UNSIGNED_INT64((float)(m_Val + v12)),
            a5: HIDWORD(COERCE_UNSIGNED_INT64((float)(m_Val + v12))),
            a6: COERCE_UNSIGNED_INT64((float)(m_Val + v11)),
            a7: HIDWORD(COERCE_UNSIGNED_INT64((float)(m_Val + v11))));
    _DevMsg(a1: 2, a2: "(%d): Cycle latch used to correct %.2f in to %.2f instead of %.2f.\n", a3: v13);
    goto LABEL_22;
  }
LABEL_23:
  v14 = this->m_flCycle.m_Val + addcyclea;
  this->m_flAnimTime = curtime;
  addcycleb = v14;
  if ( v14 < 0.0 )
  {
    if ( v14 < 1.0 )
    {
LABEL_28:
      if ( (GetSequenceFlags(pstudiohdr: m_pStudioHdr, sequence: this->m_nSequence) & 1) != 0 )
      {
        v14 = v14 - (double)(int)v14;
      }
      else
      {
        v14 = 0.0;
        if ( addcycleb >= 0.0 )
          v14 = 1.0;
      }
      this->m_bSequenceFinished = true;
      goto LABEL_33;
    }
LABEL_27:
    this->ReachedEndOfSequence(this);
    goto LABEL_28;
  }
  if ( v14 >= 1.0 )
    goto LABEL_27;
LABEL_33:
  if ( this->m_flCycle.m_Val != v14 )
  {
    this->m_flCycle.m_Val = v14;
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 8);
  }
  C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 8);
  this->m_flGroundSpeed = C_BaseAnimating::GetSequenceGroundSpeed(
                            this,
                            a2: (int)&savedregs,
                            pStudioHdr: m_pStudioHdr,
                            iSequence: this->m_nSequence);
  return flInterval;
}

//------------------------------------------------------------------------------
// Address: 0x10029380
// Name: public: int C_BaseAnimating::FindTransitionSequence(int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::FindTransitionSequence(
        C_BaseAnimating *this,
        int iCurrentSequence,
        int iGoalSequence,
        int piDir)
{
  CStudioHdr *m_pStudioHdr; // eax
  int result; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return -1;
  if ( piDir == 0 )
  {
    piDir = 1;
    result = FindTransitionSequence(pstudiohdr: m_pStudioHdr, iCurrentSequence, iGoalSequence, &piDir);
    if ( piDir == 1 )
      return result;
    return -1;
  }
  return FindTransitionSequence(pstudiohdr: m_pStudioHdr, iCurrentSequence, iGoalSequence, (int *)piDir);
}

//------------------------------------------------------------------------------
// Address: 0x10029400
// Name: public: void C_BaseAnimating::SetBodygroup(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetBodygroup(C_BaseAnimating *this, int iGroup, int iValue)
{
  int m_nBody; // ebx
  int *p_m_nBody; // edi
  CStudioHdr *m_pStudioHdr; // eax

  m_nBody = this->m_nBody;
  p_m_nBody = &this->m_nBody;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  SetBodygroup(pstudiohdr: m_pStudioHdr, body: p_m_nBody, iGroup, iValue);
  if ( m_nBody != *p_m_nBody )
    C_BaseEntity::OnTranslucencyTypeChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x10029470
// Name: public: int C_BaseAnimating::FindBodygroupByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::FindBodygroupByName(C_BaseAnimating *this, const char *name)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return FindBodygroupByName(pstudiohdr: m_pStudioHdr, name);
}

//------------------------------------------------------------------------------
// Address: 0x100294C0
// Name: public: int C_BaseAnimating::GetBodygroupCount(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::GetBodygroupCount(C_BaseAnimating *this, int iGroup)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return GetBodygroupCount(pstudiohdr: m_pStudioHdr, iGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10029510
// Name: public: int C_BaseAnimating::SelectWeightedSequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::SelectWeightedSequence(C_BaseAnimating *this, int activity)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return SelectWeightedSequence(pstudiohdr: m_pStudioHdr, activity, curSequence: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10029560
// Name: public: float C_BaseAnimating::GetPoseParameter(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::GetPoseParameter(C_BaseAnimating *this, int iParameter)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr && iParameter >= 0 )
    return Studio_GetPoseParameter(pStudioHdr: m_pStudioHdr, iParameter, ctlValue: this->m_flPoseParameter[iParameter]);
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100295C0
// Name: public: int C_BaseAnimating::LookupSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::LookupSequence(C_BaseAnimating *this, const char *label)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return LookupSequence(pstudiohdr: m_pStudioHdr, label);
}

//------------------------------------------------------------------------------
// Address: 0x10029610
// Name: public: virtual void C_BaseAnimating::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::Release(C_BaseAnimating *this)
{
  C_BaseAnimating::ClearRagdoll(this: (C_BaseAnimating *)((char *)this - 8));
  C_BaseEntity::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10029630
// Name: public: virtual float C_BaseAnimating::SetBoneController(int,float)
// Source: json
//------------------------------------------------------------------------------
float __thiscall C_BaseAnimating::SetBoneController(C_BaseAnimating *this, int iController, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  double v5; // st7
  float controller; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  controller = this->m_flEncodedController[iController];
  v5 = Studio_SetController(pStudioHdr: m_pStudioHdr, iController, flValue, ctlValue: &controller);
  this->m_flEncodedController[iController] = controller;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100296B0
// Name: public: virtual void C_BaseAnimating::GetAimEntOrigin(class IClientEntity __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetAimEntOrigin(
        C_BaseAnimating *this,
        IClientEntity *pAttachedTo,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v7; // esi
  float *v8; // eax
  const CBaseHandle *(__thiscall *GetRefEHandle)(IHandleEntity *); // edx
  CBoneMergeCache *m_pBoneMergeCache; // ecx

  if ( (this->m_fEffects & 1) != 0
    && (this->m_fEffects & 0x80) != 0
    && (m_Index = this->m_pMoveParent.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    v7 = m_pEntity + 1;
    v8 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity[1].SetRefEHandle)(a1: &m_pEntity[1]);
    pAbsOrigin->x = *v8;
    pAbsOrigin->y = v8[1];
    GetRefEHandle = v7->GetRefEHandle;
    pAbsOrigin->z = v8[2];
    *pAbsAngles = *(QAngle *)&GetRefEHandle(this: v7)->m_Index;
  }
  else
  {
    m_pBoneMergeCache = this->m_pBoneMergeCache;
    if ( m_pBoneMergeCache == nullptr
      || !CBoneMergeCache::GetAimEntOrigin(this: m_pBoneMergeCache, pAbsOrigin, pAbsAngles) )
    {
      C_BaseEntity::GetAimEntOrigin(this, pAttachedTo, pOrigin: pAbsOrigin, pAngles: pAbsAngles);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029770
// Name: public: char const __near * C_BaseAnimating::GetSequenceName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BaseAnimating::GetSequenceName(C_BaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( iSequence == -1 )
    return "Not Found!";
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return GetSequenceName(pstudiohdr: m_pStudioHdr, iSequence);
  else
    return "No model!";
}

//------------------------------------------------------------------------------
// Address: 0x100297E0
// Name: public: enum Activity C_BaseAnimating::GetSequenceActivity(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::GetSequenceActivity(C_BaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( iSequence == -1 )
    return -1;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return GetSequenceActivity(pstudiohdr: m_pStudioHdr, sequence: iSequence, pweight: nullptr);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10029840
// Name: public: bool C_BaseAnimating::ComputeHitboxSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::ComputeHitboxSurroundingBox(
        C_BaseAnimating *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v6; // esi
  double x; // xmm0_8
  float y; // xmm1_4
  float v11; // xmm0_4
  double v12; // xmm0_8
  double v13; // xmm1_8
  float z; // xmm1_4
  float v15; // xmm0_4
  double v16; // xmm0_8
  double v17; // xmm1_8
  float v18; // xmm1_4
  float v19; // xmm0_4
  double v20; // xmm0_8
  double v21; // xmm1_8
  float v22; // xmm1_4
  float v23; // xmm0_4
  double v24; // xmm0_8
  double v25; // xmm1_8
  float v26; // xmm1_4
  float v27; // xmm0_4
  double v28; // xmm0_8
  double v29; // xmm1_8
  matrix3x4_t *hitboxbones[256]; // [esp+4h] [ebp-418h] BYREF
  Vector vecBoxAbsMins; // [esp+404h] [ebp-18h] BYREF
  Vector vecBoxAbsMaxs; // [esp+410h] [ebp-Ch] BYREF
  Vector *pVecWorldMinsa; // [esp+424h] [ebp+8h]
  int i; // [esp+428h] [ebp+Ch]

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  v6 = (int)m_pStudioHdr->m_pStudioHdr + 12 * this->m_nHitboxSet + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
  if ( v6 == 0 || *(_DWORD *)(v6 + 4) == 0 )
    return 0;
  C_BaseAnimating::HitboxToWorldTransforms(this, pHitboxToWorld: hitboxbones);
  pVecWorldMins->x = 3.4028235e38;
  pVecWorldMins->y = 3.4028235e38;
  pVecWorldMins->z = 3.4028235e38;
  pVecWorldMaxs->x = -3.4028235e38;
  pVecWorldMaxs->y = -3.4028235e38;
  pVecWorldMaxs->z = -3.4028235e38;
  i = 0;
  if ( *(int *)(v6 + 4) > 0 )
  {
    pVecWorldMinsa = nullptr;
    do
    {
      TransformAABB(
        transform: hitboxbones[*(_DWORD *)((char *)&pVecWorldMinsa->x + v6 + *(_DWORD *)(v6 + 8))],
        vecMinsIn: (Vector *)((char *)&pVecWorldMinsa->z + v6 + *(_DWORD *)(v6 + 8)),
        vecMaxsIn: (Vector *)((char *)pVecWorldMinsa + v6 + *(_DWORD *)(v6 + 8) + 20),
        vecMinsOut: &vecBoxAbsMins,
        vecMaxsOut: &vecBoxAbsMaxs);
      x = pVecWorldMins->x;
      if ( x > vecBoxAbsMins.x )
        x = vecBoxAbsMins.x;
      y = vecBoxAbsMins.y;
      v11 = x;
      pVecWorldMins->x = v11;
      v12 = pVecWorldMins->y;
      v13 = y;
      if ( v12 > v13 )
        v12 = v13;
      z = vecBoxAbsMins.z;
      v15 = v12;
      pVecWorldMins->y = v15;
      v16 = pVecWorldMins->z;
      v17 = z;
      if ( v16 > v17 )
        v16 = v17;
      v18 = vecBoxAbsMaxs.x;
      v19 = v16;
      pVecWorldMins->z = v19;
      v20 = pVecWorldMaxs->x;
      v21 = v18;
      if ( v20 < v21 )
        v20 = v21;
      v22 = vecBoxAbsMaxs.y;
      v23 = v20;
      pVecWorldMaxs->x = v23;
      v24 = pVecWorldMaxs->y;
      v25 = v22;
      if ( v24 < v25 )
        v24 = v25;
      v26 = vecBoxAbsMaxs.z;
      v27 = v24;
      pVecWorldMaxs->y = v27;
      v28 = pVecWorldMaxs->z;
      v29 = v26;
      if ( v28 < v29 )
        v28 = v29;
      pVecWorldMinsa = (Vector *)((char *)pVecWorldMinsa + 68);
      pVecWorldMaxs->z = v28;
      ++i;
    }
    while ( i < *(_DWORD *)(v6 + 4) );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029A30
// Name: public: bool C_BaseAnimating::ComputeEntitySpaceHitboxSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::ComputeEntitySpaceHitboxSurroundingBox(
        C_BaseAnimating *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v6; // edi
  char *v8; // esi
  double x; // xmm0_8
  float y; // xmm1_4
  float v11; // xmm0_4
  double v12; // xmm0_8
  double v13; // xmm1_8
  float z; // xmm1_4
  float v15; // xmm0_4
  double v16; // xmm0_8
  double v17; // xmm1_8
  float v18; // xmm1_4
  float v19; // xmm0_4
  double v20; // xmm0_8
  double v21; // xmm1_8
  float v22; // xmm1_4
  float v23; // xmm0_4
  double v24; // xmm0_8
  double v25; // xmm1_8
  float v26; // xmm1_4
  float v27; // xmm0_4
  double v28; // xmm0_8
  double v29; // xmm1_8
  int v30; // eax
  matrix3x4_t *hitboxbones[256]; // [esp+4h] [ebp-47Ch] BYREF
  matrix3x4_t boneToEntity; // [esp+404h] [ebp-7Ch] BYREF
  matrix3x4_t worldToEntity; // [esp+434h] [ebp-4Ch] BYREF
  Vector vecBoxAbsMins; // [esp+464h] [ebp-1Ch] BYREF
  Vector vecBoxAbsMaxs; // [esp+470h] [ebp-10h] BYREF
  int i; // [esp+47Ch] [ebp-4h]
  Vector *pVecWorldMaxsa; // [esp+48Ch] [ebp+Ch]

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  v6 = (int)m_pStudioHdr->m_pStudioHdr + 12 * this->m_nHitboxSet + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
  if ( v6 == 0 || *(_DWORD *)(v6 + 4) == 0 )
    return 0;
  C_BaseAnimating::HitboxToWorldTransforms(this, pHitboxToWorld: hitboxbones);
  pVecWorldMins->x = 3.4028235e38;
  pVecWorldMins->y = 3.4028235e38;
  pVecWorldMins->z = 3.4028235e38;
  pVecWorldMaxs->x = -3.4028235e38;
  pVecWorldMaxs->y = -3.4028235e38;
  pVecWorldMaxs->z = -3.4028235e38;
  C_BaseEntity::CalcAbsolutePosition(this);
  MatrixInvert(in: &this->m_rgflCoordinateFrame, out: &worldToEntity);
  i = 0;
  if ( *(int *)(v6 + 4) > 0 )
  {
    pVecWorldMaxsa = nullptr;
    do
    {
      v8 = (char *)pVecWorldMaxsa + *(_DWORD *)(v6 + 8);
      ConcatTransforms(in1: &worldToEntity, in2: hitboxbones[*(_DWORD *)&v8[v6]], out: &boneToEntity);
      TransformAABB(
        transform: &boneToEntity,
        vecMinsIn: (const Vector *)&v8[v6 + 8],
        vecMaxsIn: (const Vector *)&v8[v6 + 20],
        vecMinsOut: &vecBoxAbsMins,
        vecMaxsOut: &vecBoxAbsMaxs);
      x = pVecWorldMins->x;
      if ( x > vecBoxAbsMins.x )
        x = vecBoxAbsMins.x;
      y = vecBoxAbsMins.y;
      v11 = x;
      pVecWorldMins->x = v11;
      v12 = pVecWorldMins->y;
      v13 = y;
      if ( v12 > v13 )
        v12 = v13;
      z = vecBoxAbsMins.z;
      v15 = v12;
      pVecWorldMins->y = v15;
      v16 = pVecWorldMins->z;
      v17 = z;
      if ( v16 > v17 )
        v16 = v17;
      v18 = vecBoxAbsMaxs.x;
      v19 = v16;
      pVecWorldMins->z = v19;
      v20 = pVecWorldMaxs->x;
      v21 = v18;
      if ( v20 < v21 )
        v20 = v21;
      v22 = vecBoxAbsMaxs.y;
      v23 = v20;
      pVecWorldMaxs->x = v23;
      v24 = pVecWorldMaxs->y;
      v25 = v22;
      if ( v24 < v25 )
        v24 = v25;
      v26 = vecBoxAbsMaxs.z;
      v27 = v24;
      pVecWorldMaxs->y = v27;
      v28 = pVecWorldMaxs->z;
      v29 = v26;
      if ( v28 < v29 )
        v28 = v29;
      pVecWorldMaxsa = (Vector *)((char *)pVecWorldMaxsa + 68);
      v30 = i + 1;
      pVecWorldMaxs->z = v28;
      i = v30;
    }
    while ( v30 < *(_DWORD *)(v6 + 4) );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029C40
// Name: public: float C_BaseAnimating::GetModelHierarchyScale(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::GetModelHierarchyScale(C_BaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_ScaleType.m_Value == HIERARCHICAL_MODEL_SCALE )
    return this->m_flModelScale.m_Value;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr->numbones == 1 )
    return this->m_flModelScale.m_Value;
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10029CC0
// Name: public: virtual bool C_BoneFollower::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BoneFollower::TestCollision(
        C_BoneFollower *this,
        const Ray_t *ray,
        unsigned int mask,
        CGameTrace *trace)
{
  vcollide_t *v5; // ebx
  bool v6; // zf
  const char *v7; // eax
  IVModelInfoClient_vtbl *v8; // edi
  int v9; // eax
  const char *v10; // eax
  char result; // al
  int v12; // eax
  int v13; // eax
  float fraction; // xmm0_4
  unsigned int m_Index; // esi
  struct CBaseEntity *m_pEntity; // eax
  const char *v17; // [esp-4h] [ebp-14h]
  IPhysicsCollision_vtbl *v18; // [esp+Ch] [ebp-4h]

  v5 = modelinfo->GetVCollide(this: modelinfo, a2: this->m_modelIndex);
  if ( v5 == nullptr )
  {
    v6 = !this->IsDormant(this: &this->IClientNetworkable);
    v7 = "dormant";
    if ( v6 )
      v7 = "active";
    v8 = modelinfo->__vftable;
    v9 = ((int (__thiscall *)(IVModelInfoClient *, int, const char *))modelinfo->GetModel)(
           a1: modelinfo,
           a2: this->m_modelIndex,
           a3: v7);
    v10 = v8->GetModelName(this: modelinfo, a2: (const struct model_t *)v9);
    DevWarning(
      a1: "Failed to get collision model (%d, %d), %s (%s)\n",
      this->m_modelIndex,
      this->m_solidIndex,
      v10,
      v17);
    return 0;
  }
  v18 = physcollision->__vftable;
  v12 = ((int (__thiscall *)(C_BoneFollower *, CGameTrace *))this->GetAbsAngles)(a1: this, a2: trace);
  v13 = ((int (__thiscall *)(C_BoneFollower *, int))this->GetAbsOrigin)(a1: this, a2: v12);
  ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, struct CPhysCollide *, int))v18->TraceBox_2)(
    a1: physcollision,
    a2: ray,
    a3: v5->solids[this->m_solidIndex],
    a4: v13);
  fraction = trace->fraction;
  if ( fraction >= 1.0 )
    return 0;
  m_Index = this->m_hOwnerEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (struct CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  trace->m_pEnt = m_pEntity;
  result = 0;
  trace->hitgroup = 0;
  trace->physicsbone = 0;
  if ( fraction < 1.0 || trace->allsolid || trace->startsolid )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029E00
// Name: public: void C_BaseAnimating::RemoveFromClientSideAnimationList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::RemoveFromClientSideAnimationList(C_BaseAnimating *this)
{
  unsigned int m_ClientSideAnimationListHandle; // eax
  int v2; // esi
  C_BaseAnimating *pAnimating; // ebx
  unsigned int v4; // eax
  unsigned int lastEntry_4; // [esp+4h] [ebp-8h]

  m_ClientSideAnimationListHandle = this->m_ClientSideAnimationListHandle;
  if ( m_ClientSideAnimationListHandle != -1 )
  {
    v2 = g_ClientSideAnimationList.m_Size - 1;
    if ( g_ClientSideAnimationList.m_Size - 1 == m_ClientSideAnimationListHandle )
    {
      if ( g_ClientSideAnimationList.m_Size > 0 )
      {
        --g_ClientSideAnimationList.m_Size;
        this->m_ClientSideAnimationListHandle = -1;
        return;
      }
    }
    else
    {
      pAnimating = g_ClientSideAnimationList.m_Memory.m_pMemory[v2].pAnimating;
      lastEntry_4 = g_ClientSideAnimationList.m_Memory.m_pMemory[v2].flags;
      if ( g_ClientSideAnimationList.m_Size > 0 )
        --g_ClientSideAnimationList.m_Size;
      pAnimating->m_ClientSideAnimationListHandle = this->m_ClientSideAnimationListHandle;
      v4 = this->m_ClientSideAnimationListHandle;
      g_ClientSideAnimationList.m_Memory.m_pMemory[v4].pAnimating = pAnimating;
      g_ClientSideAnimationList.m_Memory.m_pMemory[v4].flags = lastEntry_4;
    }
    this->m_ClientSideAnimationListHandle = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029EF0
// Name: public: static void C_BaseAnimating::UpdateClientSideAnimations(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseAnimating::UpdateClientSideAnimations()
{
  int v0; // esi
  int m_Size; // edi
  clientanimating_t *m_pMemory; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "UpdateClientSideAnimations",
    a3: 0,
    a4: "Client_Animation",
    a5: false,
    a6: 4);
  v0 = 0;
  m_Size = g_ClientSideAnimationList.m_Size;
  if ( g_ClientSideAnimationList.m_Size > 0 )
  {
    m_pMemory = g_ClientSideAnimationList.m_Memory.m_pMemory;
    do
    {
      if ( (m_pMemory[v0].flags & 1) != 0 )
      {
        m_pMemory[v0].pAnimating->UpdateClientSideAnimation(this: m_pMemory[v0].pAnimating);
        m_pMemory = g_ClientSideAnimationList.m_Memory.m_pMemory;
      }
      ++v0;
    }
    while ( v0 < m_Size );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10029F50
// Name: public: virtual void C_BaseAnimating::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetToolRecordingState(C_BaseAnimating *this, KeyValues *msg)
{
  CStudioHdr *m_pStudioHdr; // ebx
  int numbones; // eax
  void *v5; // esp
  IClientRenderable *v6; // edi
  bool v7; // al
  IClientThinkable *v8; // eax
  int v9; // [esp+14h] [ebp-14h]
  _BYTE v10[12]; // [esp+18h] [ebp-10h] BYREF
  matrix3x4a_t *pBones; // [esp+24h] [ebp-4h]

  if ( ToolsEnabled() )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "C_BaseAnimating::GetToolRecordingState",
      a3: 0,
      a4: "Tools",
      a5: false,
      a6: 4);
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      numbones = m_pStudioHdr->m_pStudioHdr->numbones;
    }
    else
    {
      m_pStudioHdr = nullptr;
      numbones = 1;
    }
    v5 = alloca(48 * numbones);
    v9 = *(_DWORD *)(gpGlobals.m_Index + 12);
    pBones = (matrix3x4a_t *)v10;
    v6 = &this->IClientRenderable;
    if ( m_pStudioHdr != nullptr )
      ((void (__thiscall *)(IClientRenderable *, _BYTE *, int, int, int))v6->SetupBones)(
        a1: &this->IClientRenderable,
        a2: v10,
        a3: m_pStudioHdr->m_pStudioHdr->numbones,
        a4: 524032,
        a5: v9);
    else
      ((void (__thiscall *)(IClientRenderable *, _DWORD, int, int, int))v6->SetupBones)(
        a1: &this->IClientRenderable,
        a2: 0,
        a3: -1,
        a4: 524032,
        a5: v9);
    C_BaseEntity::GetToolRecordingState(this, msg);
    if ( (_S10 & 1) == 0 )
    {
      _S10 |= 1u;
      *(_WORD *)&state.m_highLevelState.m_bClearIkTargets = 0;
      state.m_highLevelState.m_bShouldCreateIkContext = false;
      state.m_highLevelState.m_nNumPoseParams = 0;
      state.m_highLevelState.m_flCycle = 0.0;
      state.m_highLevelState.m_flPlaybackRate = 1.0;
      state.m_highLevelState.m_flCycleRate = 0.0;
      state.m_highLevelState.m_nFrameCount = 0;
      state.m_highLevelState.m_bInterpEffectActive = false;
    }
    state.m_nSkin = v6->GetSkin(this: &this->IClientRenderable);
    state.m_nBody = v6->GetBody(this: &this->IClientRenderable);
    state.m_nSequence = this->m_nSequence;
    if ( m_pStudioHdr != nullptr )
      state.m_pBoneList = C_BaseAnimating::RecordBones(this, hdr: m_pStudioHdr, pBoneState: pBones);
    else
      state.m_pBoneList = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "baseanimating", value: &state);
    v7 = this->IsViewModelOrAttachment(this);
    KeyValues::SetInt(this: msg, keyName: "viewmodel", value: v7);
    if ( this->IsViewModel(this) )
    {
      v8 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetClientThinkable(this);
      if ( v8 != nullptr )
        ((void (__thiscall *)(IClientThinkable *, KeyValues *))v8->__vftable[72].GetIClientUnknown)(a1: v8, a2: msg);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A140
// Name: public: enum LocalFlexController_t C_BaseAnimating::GetNumFlexControllers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::GetNumFlexControllers(C_BaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // esi

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return m_pStudioHdr->m_pStudioHdr->numflexcontrollers;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A180
// Name: public: char const __near * C_BaseAnimating::GetFlexControllerName(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BaseAnimating::GetFlexControllerName(
        C_BaseAnimating *this,
        LocalFlexController_t iFlexController)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return (char *)m_pStudioHdr->m_pStudioHdr
         + 20 * iFlexController
         + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex
         + *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->version
                  + 20 * iFlexController
                  + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002A1E0
// Name: public: void CInterpolatedVarArrayBase<float,1>::SetHistoryValuesForItem(int,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::SetHistoryValuesForItem(
        CInterpolatedVarArrayBase<float,1> *this,
        int item,
        float *value)
{
  int v3; // edx
  int m_maxElement; // esi
  int v5; // eax

  v3 = 0;
  if ( this->m_VarHistory.m_count != 0 )
  {
    do
    {
      m_maxElement = this->m_VarHistory.m_maxElement;
      v5 = v3 + this->m_VarHistory.m_firstElement;
      if ( v5 >= m_maxElement )
        v5 -= m_maxElement;
      this->m_VarHistory.m_pElements[v5].value[item] = *value;
      ++v3;
    }
    while ( v3 < this->m_VarHistory.m_count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A430
// Name: public: bool C_BaseAnimating::IsSequenceLooping(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::IsSequenceLooping(C_BaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return GetSequenceFlags(pstudiohdr: m_pStudioHdr, sequence: iSequence) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A4E0
// Name: public: virtual void C_ClientRagdoll::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::Release(C_ClientRagdoll *this)
{
  unsigned int m_DataChangeEventRef; // ecx
  IHandleEntity *m_pEntity; // eax

  m_DataChangeEventRef = this->m_DataChangeEventRef;
  if ( m_DataChangeEventRef != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_DataChangeEventRef].m_SerialNumber == HIWORD(m_DataChangeEventRef) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_DataChangeEventRef].m_pEntity;
    if ( m_pEntity != nullptr && ((int)m_pEntity[56].__vftable & 1) == 0 )
      C_BaseEntity::Remove(this: (C_BaseEntity *)m_pEntity);
  }
  if ( this->GetRenderAngles(this: &this->IClientRenderable) != (const QAngle *)0xFFFF )
    CClientThinkList::RemoveThinkable(this: &g_ClientThinkList, hEnt: LODWORD(this->m_flSpeed));
  CBaseEntityList::RemoveEntity(this: (CBaseEntityList *)cl_entitylist.m_Index, handle: LODWORD(this->m_flSpeed));
  ((void (__stdcall *)(int, _DWORD))partition->Remove_2)(a1: 140, a2: this->m_Collision.m_usSolidFlags.m_Value);
  C_BaseEntity::RemoveFromLeafSystem(this: (C_ClientRagdoll *)((char *)this - 8));
  C_BaseAnimating::ClearRagdoll(this: (C_ClientRagdoll *)((char *)this - 8));
  C_BaseEntity::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002A590
// Name: public: virtual void C_BaseAnimating::SetPredictable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetPredictable(C_BaseAnimating *this, bool state)
{
  C_BaseEntity::SetPredictable(this, state);
  C_BaseAnimating::UpdateRelevantInterpolatedVars(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002A5B0
// Name: public: void C_BaseAnimating::GetBonePosition(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetBonePosition(C_BaseAnimating *this, int iBone, Vector *origin, QAngle *angles)
{
  matrix3x4_t bonetoworld; // [esp+0h] [ebp-30h] BYREF

  C_BaseAnimating::GetBoneTransform(this, iBone, pBoneToWorld: &bonetoworld);
  MatrixAngles(src: (const VMatrix *)&bonetoworld, vAngles: angles);
  origin->x = bonetoworld.m_flMatVal[0][3];
  origin->y = bonetoworld.m_flMatVal[1][3];
  origin->z = bonetoworld.m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x1002A600
// Name: public: virtual void C_BaseAnimating::ApplyBoneMatrixTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ApplyBoneMatrixTransform(C_BaseAnimating *this, matrix3x4_t *transform)
{
  double ModelHierarchyScale; // st7
  const Vector *v4; // eax
  IClientRenderable_vtbl *v5; // edx
  float v6; // xmm2_4
  const Vector *(__thiscall *GetRenderOrigin)(IClientRenderable *); // eax
  float *v8; // eax
  float v9; // xmm0_4
  Vector pos; // [esp+4h] [ebp-10h] BYREF
  float scale; // [esp+10h] [ebp-4h]

  ModelHierarchyScale = C_BaseAnimating::GetModelHierarchyScale(this);
  scale = ModelHierarchyScale;
  if ( ModelHierarchyScale > 1.0000001 || scale < 0.99999988 )
  {
    MatrixGetColumn(in: transform, column: 3, out: &pos);
    v4 = this->GetRenderOrigin(this: &this->IClientRenderable);
    v5 = this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
    pos.x = pos.x - v4->x;
    pos.y = pos.y - v4->y;
    v6 = pos.z - v4->z;
    GetRenderOrigin = v5->GetRenderOrigin;
    pos.x = pos.x * scale;
    pos.y = pos.y * scale;
    pos.z = v6 * scale;
    v8 = (float *)GetRenderOrigin(this: &this->IClientRenderable);
    pos.x = *v8 + pos.x;
    pos.y = v8[1] + pos.y;
    pos.z = v8[2] + pos.z;
    MatrixSetColumn(in: &pos, column: 3, out: transform);
    v9 = scale;
    transform->m_flMatVal[0][0] = transform->m_flMatVal[0][0] * scale;
    transform->m_flMatVal[0][1] = transform->m_flMatVal[0][1] * v9;
    transform->m_flMatVal[0][2] = transform->m_flMatVal[0][2] * v9;
    transform->m_flMatVal[1][0] = transform->m_flMatVal[1][0] * v9;
    transform->m_flMatVal[1][1] = transform->m_flMatVal[1][1] * v9;
    transform->m_flMatVal[1][2] = transform->m_flMatVal[1][2] * v9;
    transform->m_flMatVal[2][0] = transform->m_flMatVal[2][0] * v9;
    transform->m_flMatVal[2][1] = transform->m_flMatVal[2][1] * v9;
    transform->m_flMatVal[2][2] = transform->m_flMatVal[2][2] * v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A770
// Name: public: void C_BaseAnimating::CreateUnragdollInfo(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::CreateUnragdollInfo(C_BaseAnimating *this, C_BaseAnimating *pRagdoll)
{
  CStudioHdr *m_pStudioHdr; // ebx
  RagdollInfo_t *m_pRagdollInfo; // eax
  const QAngle *v5; // eax
  RagdollInfo_t *v6; // eax
  int v7; // eax
  RagdollInfo_t *v8; // edx
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  const Vector *v12; // [esp-4h] [ebp-B4h]
  matrix3x4_t output; // [esp+10h] [ebp-A0h] BYREF
  matrix3x4_t parentTransform; // [esp+40h] [ebp-70h] BYREF
  matrix3x4_t inverted; // [esp+70h] [ebp-40h] BYREF
  CStudioHdr *v16; // [esp+A0h] [ebp-10h]
  int numbones; // [esp+A4h] [ebp-Ch]
  unsigned int v18; // [esp+A8h] [ebp-8h]
  unsigned int v19; // [esp+ACh] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  v16 = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    m_pRagdollInfo = this->m_pRagdollInfo;
    if ( m_pRagdollInfo == nullptr || !m_pRagdollInfo->m_bActive )
    {
      ((void (__stdcall *)(_DWORD, int, int, _DWORD))pRagdoll->SetupBones)(
        a1: 0,
        a2: -1,
        a3: 524032,
        a4: *(_DWORD *)(gpGlobals.m_Index + 12));
      pRagdoll->GetAbsAngles(this: pRagdoll);
      v12 = this->GetAbsOrigin(this);
      v5 = this->GetAbsAngles(this);
      AngleMatrix(angles: v5, position: v12, matrix: &parentTransform);
      if ( this->m_pRagdollInfo != nullptr
        || (v6 = (RagdollInfo_t *)MemAlloc_Alloc(nSize: 0x1C0Cu), this->m_pRagdollInfo = v6, v6 != nullptr) )
      {
        _V_memset(dest: this->m_pRagdollInfo, fill: 0, count: 7180);
        v7 = m_pStudioHdr->m_pStudioHdr->numbones;
        this->m_pRagdollInfo->m_bActive = true;
        this->m_pRagdollInfo->m_flSaveTime = *(float *)(gpGlobals.m_Index + 12);
        v8 = this->m_pRagdollInfo;
        v9 = 0;
        v10 = 0;
        numbones = v7;
        v8->m_nNumBones = v7;
        if ( v7 > 0 )
        {
          v18 = 0;
          v19 = 0;
          do
          {
            v11 = v16->m_boneParent.m_Memory.m_pMemory[v10];
            if ( v11 == -1 )
              MatrixInvert(in: &parentTransform, out: &inverted);
            else
              MatrixInvert(in: &pRagdoll->m_BoneAccessor.m_pBones[v11], out: &inverted);
            ConcatTransforms(in1: &inverted, in2: &pRagdoll->m_BoneAccessor.m_pBones[v9], out: &output);
            MatrixAngles(
              matrix: &output,
              q: &this->m_pRagdollInfo->m_rgBoneQuaternion[v18 / 0x10],
              pos: &this->m_pRagdollInfo->m_rgBonePos[v19 / 0xC]);
            v19 += 12;
            v18 += 16;
            ++v10;
            ++v9;
          }
          while ( v10 < numbones );
        }
      }
      else
      {
        _Msg(a1: "Memory allocation of RagdollInfo_t failed!\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A950
// Name: public: virtual void C_BaseAnimating::UpdateIKLocks(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::UpdateIKLocks(C_BaseAnimating *this, float currentTime)
{
  C_BaseAnimating *v2; // ebx
  CIKContext *m_pIk; // eax
  int m_Size; // eax
  CIKTarget *v5; // edi
  int Owner; // eax
  C_BaseEntity *BaseEntity; // esi
  int v8; // eax
  const Vector *v9; // [esp-10h] [ebp-20h]
  const QAngle *v10; // [esp-Ch] [ebp-1Ch]
  int i; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]

  v2 = this;
  m_pIk = this->m_pIk;
  if ( m_pIk != nullptr )
  {
    m_Size = m_pIk->m_target.m_Size;
    if ( m_Size > 0 )
    {
      v13 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v5 = (CIKTarget *)&v2->m_pIk->m_target.m_Memory.m_Memory[v13];
        if ( CIKTarget::IsActive(this: v5) && CIKTarget::GetOwner(this: v5) != -1 )
        {
          Owner = CIKTarget::GetOwner(this: v5);
          BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: Owner);
          if ( BaseEntity != nullptr )
          {
            v10 = BaseEntity->GetAbsAngles(this: BaseEntity);
            v9 = BaseEntity->GetAbsOrigin(this: BaseEntity);
            v8 = BaseEntity->entindex(this: &BaseEntity->IClientNetworkable);
            CIKTarget::UpdateOwner(this: v5, entindex: v8, pos: v9, angles: v10);
            v2 = this;
          }
        }
        v13 += 340;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AA00
// Name: public: virtual void C_BaseAnimating::CalculateIKLocks(float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_BaseAnimating::CalculateIKLocks(
        C_BaseAnimating *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        float currentTime)
{
  C_BaseAnimating *v5; // edi
  CIKContext *m_pIk; // eax
  int m_Size; // esi
  const QAngle *(__thiscall *GetRenderAngles)(IClientRenderable *); // edx
  const QAngle *v9; // eax
  CIKTarget *v10; // esi
  C_BaseEntity *i; // eax
  int v12; // eax
  int v13; // edi
  int v14; // eax
  __int128 v15; // xmm0
  float *v16; // eax
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  float floor; // xmm0_4
  float *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm5_4
  float height; // xmm2_4
  float v27; // xmm7_4
  float v28; // xmm2_4
  float radius; // xmm0_4
  IEngineTrace_vtbl *v30; // edi
  int v31; // eax
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  int v33; // edi
  int v34; // eax
  float v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  bool v43; // al
  CIKTarget *v44; // ecx
  const QAngle *v45; // eax
  float v46; // xmm0_4
  const QAngle *v47; // eax
  int m_CollisionGroup; // [esp+14h] [ebp-5ECh]
  const Vector *v50; // [esp+14h] [ebp-5ECh]
  const QAngle *v52; // [esp+18h] [ebp-5E8h]
  C_BaseEntity **v53; // [esp+1Ch] [ebp-5E4h] BYREF
  int v54; // [esp+20h] [ebp-5E0h]
  _DWORD *v55; // [esp+24h] [ebp-5DCh]
  CEntitySphereQuery sphere; // [esp+28h] [ebp-5D8h] BYREF
  Ray_t ray; // [esp+430h] [ebp-1D0h]
  float v58; // [esp+480h] [ebp-180h]
  QAngle v59; // [esp+488h] [ebp-178h] BYREF
  __int128 angles; // [esp+494h] [ebp-16Ch] OVERLAPPED
  _DWORD v61[3]; // [esp+4A4h] [ebp-15Ch] BYREF
  CTraceFilterSkipNPCsAndPlayers traceFilter; // [esp+4B0h] [ebp-150h] BYREF
  CGameTrace trace; // [esp+4C0h] [ebp-140h] BYREF
  float v64; // [esp+514h] [ebp-ECh]
  int v65; // [esp+518h] [ebp-E8h]
  Vector v66; // [esp+51Ch] [ebp-E4h] BYREF
  Vector estGround; // [esp+528h] [ebp-D8h] BYREF
  Vector v68; // [esp+534h] [ebp-CCh] BYREF
  Vector v69; // [esp+540h] [ebp-C0h] BYREF
  Vector v70; // [esp+54Ch] [ebp-B4h] BYREF
  Vector v71; // [esp+558h] [ebp-A8h] BYREF
  Vector v72; // [esp+564h] [ebp-9Ch] BYREF
  Vector v73; // [esp+570h] [ebp-90h] BYREF
  Vector origin; // [esp+57Ch] [ebp-84h]
  int v75; // [esp+588h] [ebp-78h]
  float v76; // [esp+58Ch] [ebp-74h]
  float v77; // [esp+590h] [ebp-70h]
  int curSuppressed; // [esp+594h] [ebp-6Ch]
  Vector v79; // [esp+598h] [ebp-68h] BYREF
  Vector tmp; // [esp+5A4h] [ebp-5Ch] BYREF
  Vector p1; // [esp+5B0h] [ebp-50h] BYREF
  Vector p2; // [esp+5BCh] [ebp-44h]
  int v83; // [esp+5C8h] [ebp-38h]
  float v84; // [esp+5CCh] [ebp-34h]
  float v85; // [esp+5D0h] [ebp-30h]
  int v86; // [esp+5D4h] [ebp-2Ch]
  float v87; // [esp+5D8h] [ebp-28h]
  float r; // [esp+5DCh] [ebp-24h]
  C_BaseAnimating *v89; // [esp+5E0h] [ebp-20h]
  float flDist; // [esp+5E4h] [ebp-1Ch]
  float minHeight; // [esp+5E8h] [ebp-18h] BYREF
  float v92; // [esp+5ECh] [ebp-14h]
  float maxHeight; // [esp+5F0h] [ebp-10h]
  Vector up; // [esp+5F4h] [ebp-Ch]
  float retaddr; // [esp+600h] [ebp+0h]

  up.x = a2;
  up.y = retaddr;
  v5 = this;
  m_pIk = this->m_pIk;
  v89 = this;
  if ( m_pIk != nullptr )
  {
    m_Size = m_pIk->m_target.m_Size;
    if ( m_Size != 0 )
    {
      v75 = ((int (__thiscall *)(ISpatialPartition *, int, int))partition->GetSuppressedLists)(
              a1: partition,
              a2: a3,
              a3: a4);
      partition->SuppressLists(this: partition, a2: 428, a3: false);
      C_BaseEntity::PushEnableAbsRecomputations(bEnable: false);
      m_CollisionGroup = v5->m_CollisionGroup;
      ray.m_Extents.y = 0.0;
      CTraceFilterSimple::CTraceFilterSimple(
        this: (CTraceFilterSimple *)v61,
        passedict: v5,
        collisionGroup: m_CollisionGroup,
        pExtraShouldHitFunc: nullptr);
      GetRenderAngles = v5->GetRenderAngles;
      v61[0] = &CTraceFilterSkipNPCsAndPlayers::`vftable';
      v9 = GetRenderAngles(this: &v5->IClientRenderable);
      AngleVectors(angles: v9, forward: nullptr, right: nullptr, up: (Vector *)&minHeight);
      r = 3.4028235e38;
      flDist = -3.4028235e38;
      if ( m_Size > 0 )
      {
        v86 = 0;
        v83 = m_Size;
        while ( 1 )
        {
          v10 = (CIKTarget *)&v5->m_pIk->m_target.m_Memory.m_Memory[v86];
          if ( !CIKTarget::IsActive(this: v10) )
            goto LABEL_44;
          if ( v10->type == 3 )
          {
            v16 = (float *)((int (__thiscall *)(IClientRenderable *, C_BaseEntity **, int, _DWORD *, int))v5->GetRenderOrigin)(
                             a1: &v5->IClientRenderable,
                             a2: v53,
                             a3: v54,
                             a4: v55,
                             a5: sphere.m_listIndex);
            v17 = v10->est.pos.x - *v16;
            v18 = v10->est.pos.y - v16[1];
            v19 = v10->est.pos.z - v16[2];
            GetAbsOrigin = v5->GetAbsOrigin;
            v58 = (float)(v92 * v18) * v92;
            origin.x = v17 - (float)((float)(minHeight * v17) * minHeight);
            floor = v10->est.floor;
            origin.y = v18 - v58;
            origin.z = v19 - (float)((float)(maxHeight * v19) * maxHeight);
            v76 = minHeight * floor;
            v77 = v92 * floor;
            *(float *)&curSuppressed = maxHeight * floor;
            v22 = (float *)GetAbsOrigin(this: v5);
            v23 = (float)(v22[2] + origin.z) + *(float *)&curSuppressed;
            v24 = (float)(v22[1] + origin.y) + v77;
            v25 = v76 + (float)(origin.x + *v22);
            height = v10->est.height;
            tmp.x = (float)(minHeight * height) + v25;
            tmp.y = (float)(v92 * height) + v24;
            v27 = maxHeight * height;
            LODWORD(v28) = LODWORD(height) ^ _mask__NegFloat_;
            tmp.z = v27 + v23;
            p2.x = v25;
            p2.y = v24;
            p2.z = v23;
            v66.x = v25;
            v66.y = v24;
            v66.z = v23;
            p1.x = (float)(v28 * minHeight) + v25;
            p1.y = (float)(v92 * v28) + v24;
            radius = v10->est.radius;
            p1.z = (float)(maxHeight * v28) + v23;
            if ( radius <= 1.0 )
              radius = 1.0;
            v85 = radius;
            v69.x = radius;
            v69.y = radius;
            v69.z = radius * 2.0;
            v84 = -radius;
            *(float *)&trace.hitbox = -radius;
            v64 = -radius;
            v65 = 0;
            Ray_t::Init(
              this: (Ray_t *)&sphere.m_pList[253],
              start: &tmp,
              end: &p1,
              mins: (const Vector *)&trace.hitbox,
              maxs: &v69);
            v30 = enginetrace->__vftable;
            sphere.m_listIndex = (int)&traceFilter.m_pPassEnt;
            v55 = v61;
            v31 = v89->PhysicsSolidMaskForEntity(this: v89);
            TraceRay = v30->TraceRay;
            v54 = v31;
            v53 = &sphere.m_pList[253];
            ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
            if ( *(_DWORD *)&trace.surface.surfaceProps != 0
              && *(_BYTE *)(*(_DWORD *)&trace.surface.surfaceProps + 592) == 7 )
            {
              v33 = *(_DWORD *)&trace.surface.surfaceProps + 8;
              v52 = (const QAngle *)(*(int (**)(void))(**(_DWORD **)&trace.surface.surfaceProps + 44))();
              v50 = (const Vector *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&trace.surface.surfaceProps + 40))(a1: *(_DWORD *)&trace.surface.surfaceProps);
              v34 = (*(int (__thiscall **)(int))(*(_DWORD *)v33 + 40))(a1: v33);
              CIKTarget::SetOwner(this: v10, entindex: v34, pos: v50, angles: v52);
            }
            else
            {
              CIKTarget::ClearOwner(this: v10);
            }
            if ( trace.plane.pad[1] == 0 )
              goto LABEL_48;
            v79.x = p2.x - v10->trace.closest.x;
            v79.y = p2.y - v10->trace.closest.y;
            v79.z = p2.z - v10->trace.closest.z;
            VectorNormalize(vec: &v79);
            v68.x = v85;
            v68.y = v85;
            v68.z = 1.0;
            estGround.x = v84;
            estGround.y = v84;
            estGround.z = 0.0;
            v35 = v10->est.height;
            v72.x = p2.x - (float)(v79.x * v35);
            v72.y = p2.y - (float)(v79.y * v35);
            v72.z = p2.z - (float)(v79.z * v35);
            Ray_t::Init(this: (Ray_t *)&sphere.m_pList[253], start: &v72, end: &v66, mins: &estGround, maxs: &v68);
            enginetrace->TraceRay(
              this: enginetrace,
              a2: (const Ray_t *)&sphere.m_pList[253],
              a3: 33570827u,
              a4: (ITraceFilter *)v61,
              a5: (CGameTrace *)&traceFilter.m_pPassEnt);
            if ( trace.plane.pad[1] != 0 )
              goto LABEL_49;
            LODWORD(v36) = LODWORD(v10->est.height) ^ _mask__NegFloat_;
            tmp = trace.startpos;
            p1.y = (float)(v92 * v36) + trace.startpos.y;
            v70.x = v85;
            v70.y = v85;
            v70.z = 1.0;
            v71.x = v84;
            v71.y = v84;
            p1.x = (float)(v36 * minHeight) + trace.startpos.x;
            p1.z = (float)(maxHeight * v36) + trace.startpos.z;
            v71.z = 0.0;
            Ray_t::Init(this: (Ray_t *)&sphere.m_pList[253], start: &tmp, end: &p1, mins: &v71, maxs: &v70);
            enginetrace->TraceRay(
              this: enginetrace,
              a2: (const Ray_t *)&sphere.m_pList[253],
              a3: 33570827u,
              a4: (ITraceFilter *)v61,
              a5: (CGameTrace *)&traceFilter.m_pPassEnt);
            if ( trace.plane.pad[1] != 0 )
            {
LABEL_49:
              if ( !CGameTrace::DidHitWorld(this: (CGameTrace *)&traceFilter.m_pPassEnt) )
              {
                v44 = v10;
LABEL_42:
                CIKTarget::IKFailed(this: v44);
                goto LABEL_44;
              }
              CIKTarget::SetPos(this: v10, pos: &trace.startpos);
              v47 = v89->GetRenderAngles(this: &v89->IClientRenderable);
              CIKTarget::SetAngles(this: v10, angles: v47);
              CIKTarget::SetOnWorld(this: v10, bOnWorld: true);
            }
            else
            {
LABEL_48:
              if ( CGameTrace::DidHitWorld(this: (CGameTrace *)&traceFilter.m_pPassEnt) )
              {
                v37 = (float)((float)(trace.endpos.y * v92) + (float)(trace.endpos.x * minHeight))
                    + (float)(trace.endpos.z * maxHeight);
                if ( v37 < 0.83200002 )
                {
                  v38 = trace.endpos.y - (float)(v92 * v37);
                  v39 = trace.endpos.z - (float)(maxHeight * v37);
                  v40 = trace.endpos.x - (float)(minHeight * v37);
                  v41 = fsqrt(0.30777597 / (float)((float)((float)(v38 * v38) + (float)(v40 * v40)) + (float)(v39 * v39)));
                  trace.endpos.x = (float)(v40 * v41) + (float)(minHeight * 0.83200002);
                  trace.endpos.y = (float)(v92 * 0.83200002) + (float)(v38 * v41);
                  trace.endpos.z = (float)(maxHeight * 0.83200002) + (float)(v39 * v41);
                }
                CIKTarget::SetPosWithNormalOffset(this: v10, pos: &trace.startpos, normal: &trace.endpos);
                CIKTarget::SetNormal(this: v10, normal: &trace.endpos);
                CIKTarget::SetOnWorld(this: v10, bOnWorld: true);
                if ( v10->est.release < 0.1 )
                {
                  v42 = (float)((float)(v10->est.pos.y * v92) + (float)(v10->est.pos.x * minHeight))
                      + (float)(v10->est.pos.z * maxHeight);
                  if ( r > v42 )
                    r = (float)((float)(v10->est.pos.y * v92) + (float)(v10->est.pos.x * minHeight))
                      + (float)(v10->est.pos.z * maxHeight);
                  if ( v42 > flDist )
                    flDist = v42;
                }
              }
              else
              {
                v43 = CGameTrace::DidHitNonWorldEntity(this: (CGameTrace *)&traceFilter.m_pPassEnt);
                v44 = v10;
                if ( !v43 )
                  goto LABEL_42;
                CIKTarget::SetPos(this: v10, pos: &trace.startpos);
                v45 = v89->GetRenderAngles(this: &v89->IClientRenderable);
                CIKTarget::SetAngles(this: v10, angles: v45);
                if ( v10->est.release < 0.1 )
                {
                  v46 = (float)((float)(v10->est.pos.y * v92) + (float)(v10->est.pos.x * minHeight))
                      + (float)(v10->est.pos.z * maxHeight);
                  if ( r > v46 )
                    r = (float)((float)(v10->est.pos.y * v92) + (float)(v10->est.pos.x * minHeight))
                      + (float)(v10->est.pos.z * maxHeight);
                  if ( v46 > flDist )
                    flDist = v46;
                }
              }
            }
          }
          else if ( v10->type == 5 )
          {
            v87 = v10->est.radius;
            CEntitySphereQuery::CEntitySphereQuery(
              this: (CEntitySphereQuery *)&v53,
              center: &v10->est.pos,
              radius: 64.0,
              flagMask: 0,
              partitionMask: 512);
            for ( i = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)&v53);
                  i != nullptr;
                  i = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)&v53) )
            {
              v12 = (int)i->GetBaseAnimating(this: i);
              if ( v12 != 0 )
              {
                v13 = v12 + 4;
                v14 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)(v12 + 4) + 132))(
                        a1: v12 + 4,
                        a2: v10->offset.pAttachmentName);
                if ( v14 > 0 )
                {
                  (*(void (__thiscall **)(int, int, Vector *, QAngle *))(*(_DWORD *)v13 + 140))(
                    a1: v13,
                    a2: v14,
                    a3: &v73,
                    a4: &v59);
                  v15 = 0;
                  *(float *)&v15 = fsqrt(
                                     (float)((float)((float)(v10->est.pos.y - v73.y) * (float)(v10->est.pos.y - v73.y))
                                           + (float)((float)(v10->est.pos.z - v73.z) * (float)(v10->est.pos.z - v73.z)))
                                   + (float)((float)(v10->est.pos.x - v73.x) * (float)(v10->est.pos.x - v73.x)));
                  angles = v15;
                  if ( *(float *)&v15 < v87 )
                  {
                    v87 = *(float *)&v15;
                    CIKTarget::SetPos(this: v10, pos: &v73);
                    CIKTarget::SetAngles(this: v10, angles: &v59);
                  }
                }
              }
              v53 = (C_BaseEntity **)((char *)v53 + 1);
            }
            if ( v87 >= v10->est.radius )
              CIKTarget::IKFailed(this: v10);
          }
LABEL_44:
          v86 += 340;
          if ( --v83 == 0 )
            break;
          v5 = v89;
        }
      }
      C_BaseEntity::PopEnableAbsRecomputations();
      partition->SuppressLists(this: partition, a2: v75, a3: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B3B0
// Name: public: virtual void C_BaseAnimating::ControlMouth(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ControlMouth(C_BaseAnimating *this, CStudioHdr *pstudiohdr)
{
  int v4; // edi
  float v5; // xmm0_4
  float raw; // [esp+10h] [ebp-Ch] BYREF
  float end; // [esp+14h] [ebp-8h] BYREF
  float start; // [esp+18h] [ebp-4h] BYREF
  float value; // [esp+24h] [ebp+8h]

  if ( this->m_mouth.m_needsEnvelope != 0 && pstudiohdr != nullptr )
  {
    v4 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr, szName: "mouth");
    if ( v4 != -1 )
    {
      v5 = (double)this->GetMouth(this)->mouthopen * 0.015625;
      value = v5;
      raw = v5;
      if ( v5 > 1.0 )
        value = 1.0;
      C_BaseAnimating::GetPoseParameterRange(this, index: v4, minValue: &start, maxValue: &end);
      C_BaseAnimating::SetPoseParameter(
        this,
        pStudioHdr: pstudiohdr,
        iParameter: v4,
        flValue: (float)((float)(1.0 - value) * start) + (float)(end * value));
      CInterpolatedVarArrayBase<float,1>::SetHistoryValuesForItem(
        this: &this->m_iv_flPoseParameter,
        item: v4,
        value: &raw);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B480
// Name: public: C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(C_BaseAnimating::AutoAllowBoneAccess *this)
{
  if ( (unsigned __int8)_ThreadInMainThread(a1: this) != 0 && g_BoneAccessStack.m_Size - 1 >= 0 )
    g_BoneAcessBase = g_BoneAccessStack.m_Memory.m_pMemory[--g_BoneAccessStack.m_Size];
}

//------------------------------------------------------------------------------
// Address: 0x1002B4E0
// Name: public: void C_BaseAnimating::DrawSkeleton(class CStudioHdr const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::DrawSkeleton(C_BaseAnimating *this, const CStudioHdr *pHdr, int iBoneMask)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  matrix3x4a_t *m_pBones; // ecx
  int v7; // eax
  Vector from; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector to; // [esp+28h] [ebp-10h] BYREF
  C_BaseAnimating *v10; // [esp+34h] [ebp-4h]

  v10 = this;
  if ( pHdr != nullptr )
  {
    v3 = 0;
    if ( pHdr->m_pStudioHdr->numbones > 0 )
    {
      v4 = 0;
      do
      {
        if ( (iBoneMask & pHdr->m_boneFlags.m_Memory.m_pMemory[v3]) != 0 )
        {
          ((void (__stdcall *)(matrix3x4a_t *, int, _DWORD))debugoverlay->AddCoordFrameOverlay)(
            a1: &v10->m_BoneAccessor.m_pBones[v4],
            a2: 1077936128,
            a3: 0);
          v5 = pHdr->m_boneParent.m_Memory.m_pMemory[v3];
          if ( v5 >= 0 )
          {
            m_pBones = v10->m_BoneAccessor.m_pBones;
            from.x = m_pBones[v4].m_flMatVal[0][3];
            from.y = m_pBones[v4].m_flMatVal[1][3];
            v7 = v5;
            from.z = m_pBones[v4].m_flMatVal[2][3];
            to.x = m_pBones[v7].m_flMatVal[0][3];
            to.y = m_pBones[v7].m_flMatVal[1][3];
            to.z = m_pBones[v7].m_flMatVal[2][3];
            ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
              a1: debugoverlay,
              a2: &from,
              a3: &to,
              a4: 0,
              a5: 255,
              a6: 255,
              a7: 1,
              a8: 0);
          }
        }
        ++v3;
        ++v4;
      }
      while ( v3 < pHdr->m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B5F0
// Name: public: virtual int C_BaseAnimating::InternalDrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__userpurge C_BaseAnimating::InternalDrawModel@<eax>(
        C_BaseAnimating *this@<ecx>,
        int a2@<ebx>,
        int flags,
        const RenderableInstance_t *instance)
{
  IClientRenderable *v5; // esi
  const struct model_t *result; // eax
  IVModelInfoClient_vtbl *v7; // ebx
  int v8; // eax
  CStudioHdr *m_pStudioHdr; // eax
  int v10; // eax
  IMatRenderContext *v11; // ebx
  IClientRenderable_vtbl *v12; // edx
  unsigned __int16 (__thiscall *GetModelInstance)(IClientRenderable *); // eax
  unsigned __int16 v14; // ax
  int index; // ecx
  IClientRenderable v16; // edx
  const struct model_t *(__thiscall *GetModel)(IClientRenderable *); // eax
  const struct model_t *v18; // eax
  IClientRenderable v19; // edx
  int v20; // eax
  IClientRenderable v21; // edx
  float v22; // xmm0_4
  const QAngle *(__thiscall *GetRenderAngles)(IClientRenderable *); // eax
  int v24; // eax
  IClientRenderable v25; // edx
  float v26; // xmm0_4
  int (__thiscall *GetSkin)(IClientRenderable *); // eax
  int v28; // eax
  int m_nHitboxSet; // edx
  C_BaseAnimating_vtbl *v30; // eax
  bool v31; // al
  float m_Value; // xmm0_4
  CStudioHdr *ModelPtr; // eax
  double ModelHierarchyScale; // st7
  matrix3x4_t *v35; // ecx
  matrix3x4_t *v36; // eax
  matrix3x4_t *v37; // eax
  ShaderStencilOp_t *p_m_FailOp; // eax
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // edx
  ClientModelRenderInfo_t info; // [esp+8h] [ebp-C8h] BYREF
  ShaderStencilState_t state; // [esp+ACh] [ebp-24h] BYREF
  matrix3x4_t *pBoneToWorld; // [esp+CCh] [ebp-4h] BYREF
  bool bMarkAsDrawn_3; // [esp+DBh] [ebp+Bh]
  bool bUsingStencil_3; // [esp+DFh] [ebp+Fh]

  v5 = &this->IClientRenderable;
  result = this->GetModel(this: &this->IClientRenderable);
  if ( result != nullptr )
  {
    v7 = modelinfo->__vftable;
    v8 = (int)v5->GetModel(this: v5);
    if ( v7->GetModelType(this: modelinfo, a2: (const struct model_t *)v8) == 3 )
    {
      if ( this->m_pStudioHdr == nullptr && v5->GetModel(this: v5) != nullptr )
        C_BaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
      {
        bUsingStencil_3 = false;
        v10 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
        v11 = (IMatRenderContext *)v10;
        if ( v10 != 0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
        if ( (flags & 0x40000800) == 0 && (flags & 1) != 0 )
        {
          ShaderStencilState_t::ShaderStencilState_t(this: &state);
          bUsingStencil_3 = this->ComputeStencilState(this, a2: &state);
          if ( bUsingStencil_3 )
            v11->SetStencilState(this: v11, a2: &state);
        }
        v12 = v5->__vftable;
        memset(&info.pModelToWorld, 0, 12);
        info.flags = flags;
        GetModelInstance = v12->GetModelInstance;
        info.pRenderable = v5;
        v14 = GetModelInstance(this: v5);
        index = this->index;
        v16.__vftable = v5->__vftable;
        info.instance = v14;
        GetModel = v16.GetModel;
        info.entity_index = index;
        v18 = GetModel(this: v5);
        v19.__vftable = v5->__vftable;
        info.pModel = v18;
        v20 = (int)v19.GetRenderOrigin(this: v5);
        v21.__vftable = v5->__vftable;
        info.origin.x = *(float *)v20;
        info.origin.y = *(float *)(v20 + 4);
        v22 = *(float *)(v20 + 8);
        GetRenderAngles = v21.GetRenderAngles;
        info.origin.z = v22;
        v24 = (int)GetRenderAngles(this: v5);
        v25.__vftable = v5->__vftable;
        info.angles.x = *(float *)v24;
        info.angles.y = *(float *)(v24 + 4);
        v26 = *(float *)(v24 + 8);
        GetSkin = v25.GetSkin;
        info.angles.z = v26;
        v28 = GetSkin(this: v5);
        m_nHitboxSet = this->m_nHitboxSet;
        info.body = this->m_nBody;
        info.skin = v28;
        v30 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        info.hitboxset = m_nHitboxSet;
        bMarkAsDrawn_3 = false;
        if ( v30->OnInternalDrawModel(this, a2: &info) )
        {
          if ( info.pModelToWorld == nullptr )
          {
            info.pModelToWorld = &info.modelToWorld;
            AngleMatrix(angles: &info.angles, position: &info.origin, matrix: &info.modelToWorld);
          }
          v11->AddRefRenderData(this: v11);
          v31 = modelrender->DrawModelSetup(
                  this: modelrender,
                  a2: v11,
                  a3: &info,
                  a4: (DrawModelState_t *)&state.m_FailOp,
                  a5: &pBoneToWorld);
          m_Value = this->m_flModelScale.m_Value;
          bMarkAsDrawn_3 = v31;
          if ( m_Value > 1.0000001 || m_Value < 0.99999988 )
          {
            ModelPtr = C_BaseAnimating::GetModelPtr(this);
            if ( ModelPtr != nullptr && pBoneToWorld != nullptr && ModelPtr->m_pStudioHdr->numbones == 1 )
            {
              ModelHierarchyScale = C_BaseAnimating::GetModelHierarchyScale(this);
              v35 = pBoneToWorld;
              pBoneToWorld->m_flMatVal[0][0] = pBoneToWorld->m_flMatVal[0][0] * ModelHierarchyScale;
              v35->m_flMatVal[0][1] = v35->m_flMatVal[0][1] * ModelHierarchyScale;
              v35->m_flMatVal[0][2] = v35->m_flMatVal[0][2] * ModelHierarchyScale;
              v36 = pBoneToWorld;
              pBoneToWorld->m_flMatVal[1][0] = pBoneToWorld->m_flMatVal[1][0] * ModelHierarchyScale;
              v36->m_flMatVal[1][1] = v36->m_flMatVal[1][1] * ModelHierarchyScale;
              v36->m_flMatVal[1][2] = v36->m_flMatVal[1][2] * ModelHierarchyScale;
              v37 = pBoneToWorld;
              pBoneToWorld->m_flMatVal[2][0] = pBoneToWorld->m_flMatVal[2][0] * ModelHierarchyScale;
              v37->m_flMatVal[2][1] = v37->m_flMatVal[2][1] * ModelHierarchyScale;
              v37->m_flMatVal[2][2] = ModelHierarchyScale * v37->m_flMatVal[2][2];
            }
          }
          if ( bMarkAsDrawn_3 && (info.flags & 1) != 0 )
            p_m_FailOp = &state.m_FailOp;
          else
            p_m_FailOp = nullptr;
          C_BaseAnimating::DoInternalDrawModel(
            this,
            pRenderContext: v11,
            pInfo: &info,
            pState: (DrawModelState_t *)p_m_FailOp,
            pBoneToWorldArray: pBoneToWorld);
          v11->ReleaseRenderData(this: v11);
        }
        if ( bUsingStencil_3 )
        {
          state.m_ZFailOp = SHADER_STENCILOP_KEEP;
          state.m_FailOp = SHADER_STENCILOP_KEEP;
          state.m_PassOp = SHADER_STENCILOP_KEEP;
          state.m_nWriteMask = -1;
          state.m_nTestMask = -1;
          SetStencilState = v11->SetStencilState;
          state.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
          state.m_nReferenceValue = 0;
          state.m_bEnable = false;
          SetStencilState(this: v11, a2: &state);
        }
        this->OnPostInternalDrawModel(this, a2: &info);
        if ( v11 != nullptr )
        {
          v11->EndRender(this: v11);
          v11->Release(this: v11);
        }
        return (const struct model_t *)bMarkAsDrawn_3;
      }
      else
      {
        return nullptr;
      }
    }
    else
    {
      return (const struct model_t *)C_BaseEntity::DrawModel(this: (C_BaseEntity *)v5, flags, instance);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B970
// Name: public: virtual void C_BaseAnimating::DoAnimationEvents(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::DoAnimationEvents(C_BaseAnimating *this, CStudioHdr *pStudioHdr)
{
  float m_Val; // xmm0_4
  int j; // eax
  char v5; // bl
  unsigned __int8 m_nMuzzleFlashParity; // al
  int m_nSequence; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v9; // ebx
  mstudioevent_for_client_server_t *EventIndexForSequence; // edi
  int m_nResetEventsParity; // eax
  bool v12; // zf
  int v13; // eax
  float v14; // xmm1_4
  float m_flPrevEventCycle; // xmm0_4
  int *p_type; // edi
  C_BaseAnimating_vtbl *v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  $E963F8FE9DC1729540139F392D973E98 *v21; // edi
  int v22; // eax
  float v23; // xmm0_4
  int event_highword; // eax
  C_BaseAnimating_vtbl *v25; // ebx
  int v26; // eax
  int v27; // eax
  mstudioevent_for_client_server_t *pevent; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int ia; // [esp+8h] [ebp-8h]
  float flEventCycle; // [esp+Ch] [ebp-4h]
  mstudioseqdesc_t *seqdesc; // [esp+18h] [ebp+8h]

  if ( this->m_nSequence != -1 )
  {
    m_Val = this->m_flCycle.m_Val;
    this->m_VisibilityBits.m_Ints[0] &= 1u;
    flEventCycle = m_Val;
    for ( j = 0; j >= 0; --j )
    {
      if ( this->m_VisibilityBits.m_Ints[j] != 0 )
        goto LABEL_16;
    }
    if ( this->IsViewModel(this) || this->IsMenuModel(this) )
    {
LABEL_16:
      v5 = 0;
    }
    else
    {
      v5 = 1;
      if ( !clienttools->IsInRecordingMode(this: clienttools) )
        return;
    }
    m_nMuzzleFlashParity = this->m_nMuzzleFlashParity;
    if ( this->m_nOldMuzzleFlashParity != m_nMuzzleFlashParity )
    {
      this->m_nOldMuzzleFlashParity = m_nMuzzleFlashParity;
      this->ProcessMuzzleFlashEvent(this);
    }
    if ( v5 == 0 )
    {
      m_nSequence = this->m_nSequence;
      if ( pStudioHdr->m_pVModel != nullptr )
      {
        seqdesc = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: this->m_nSequence);
        v9 = seqdesc;
      }
      else
      {
        m_pStudioHdr = pStudioHdr->m_pStudioHdr;
        if ( m_nSequence < 0 || m_nSequence >= m_pStudioHdr->numlocalseq )
          m_nSequence = 0;
        v9 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * m_nSequence + m_pStudioHdr->localseqindex);
        seqdesc = v9;
      }
      if ( v9->numevents != 0 )
      {
        EventIndexForSequence = GetEventIndexForSequence(seqdesc: v9);
        m_nResetEventsParity = this->m_nResetEventsParity;
        v12 = m_nResetEventsParity == this->m_nPrevResetEventsParity;
        this->m_nPrevResetEventsParity = m_nResetEventsParity;
        v13 = this->m_nSequence;
        pevent = EventIndexForSequence;
        if ( this->m_nEventSequence == v13 && v12 )
        {
          v14 = m_Val;
        }
        else
        {
          v14 = 0.0;
          this->m_nEventSequence = v13;
          flEventCycle = 0.0;
          this->m_flPrevEventCycle = -0.0099999998;
        }
        m_flPrevEventCycle = this->m_flPrevEventCycle;
        if ( v14 != m_flPrevEventCycle )
        {
          if ( m_flPrevEventCycle < v14 )
            goto LABEL_37;
          if ( (float)(m_flPrevEventCycle - v14) > 0.5 )
          {
            i = 0;
            if ( v9->numevents <= 0 )
              goto LABEL_36;
            p_type = &EventIndexForSequence->type;
            while ( 1 )
            {
              if ( (*p_type & 0x400) != 0 )
              {
                if ( (*p_type & 0x10) != 0 )
                  goto LABEL_32;
              }
              else if ( *(p_type - 1) >= 5000 )
              {
LABEL_32:
                if ( this->m_flPrevEventCycle < *((float *)p_type - 2) )
                {
                  v17 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
                  v18 = mstudioevent_for_client_server_t::Event(this: (mstudioevent_for_client_server_t *)(p_type - 2));
                  v19 = ((int (__thiscall *)(C_BaseAnimating *, int, int *))v17->GetAbsAngles)(
                          a1: this,
                          a2: v18,
                          a3: p_type + 1);
                  v20 = ((int (__thiscall *)(C_BaseAnimating *, int))this->GetAbsOrigin)(a1: this, a2: v19);
                  ((void (__thiscall *)(C_BaseAnimating *, int))v17->FireEvent)(a1: this, a2: v20);
                  v14 = flEventCycle;
                  v9 = seqdesc;
                }
              }
              p_type += 20;
              if ( ++i >= v9->numevents )
              {
                EventIndexForSequence = pevent;
LABEL_36:
                this->m_flPrevEventCycle = -0.0099999998;
LABEL_37:
                ia = 0;
                if ( v9->numevents > 0 )
                {
                  v21 = &EventIndexForSequence->___u1;
                  do
                  {
                    v22 = *(_DWORD *)&v21[2]._event_highword;
                    if ( (v22 & 0x400) != 0 )
                    {
                      if ( (v22 & 0x10) != 0 )
                        goto LABEL_43;
                    }
                    else if ( *(int *)&v21->_event_highword >= 5000 )
                    {
LABEL_43:
                      v23 = *(float *)&v21[-2]._event_highword;
                      if ( v23 > this->m_flPrevEventCycle && v14 >= v23 )
                      {
                        if ( (*(_DWORD *)&v21[2]._event_highword & 0x400) != 0 )
                          event_highword = v21->_event_highword;
                        else
                          event_highword = *(_DWORD *)&v21->_event_highword;
                        v25 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
                        v26 = ((int (__thiscall *)(C_BaseAnimating *, int, $E963F8FE9DC1729540139F392D973E98 *))this->GetAbsAngles)(
                                a1: this,
                                a2: event_highword,
                                a3: &v21[4]);
                        v27 = ((int (__thiscall *)(C_BaseAnimating *, int))this->GetAbsOrigin)(a1: this, a2: v26);
                        ((void (__thiscall *)(C_BaseAnimating *, int))v25->FireEvent)(a1: this, a2: v27);
                        v14 = flEventCycle;
                        v9 = seqdesc;
                      }
                    }
                    v21 += 40;
                    ++ia;
                  }
                  while ( ia < v9->numevents );
                }
                this->m_flPrevEventCycle = v14;
                return;
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BC20
// Name: public: virtual bool C_BaseAnimating::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::Interpolate(C_BaseAnimating *this, float flCurrentTime)
{
  int v3; // edi
  bool v4; // zf
  Vector oldOrigin; // [esp+4h] [ebp-20h] BYREF
  QAngle oldAngles; // [esp+10h] [ebp-14h] BYREF
  float flOldCycle; // [esp+1Ch] [ebp-8h]
  int bNoMoreChanges; // [esp+20h] [ebp-4h] BYREF

  if ( this->m_pRagdoll == nullptr )
  {
    v3 = 0;
    v4 = !this->m_bClientSideAnimation;
    flOldCycle = this->m_flCycle.m_Val;
    if ( v4 )
      *this->m_iv_flCycle.m_bLooping = C_BaseAnimating::IsSequenceLooping(this, iSequence: this->m_nSequence);
    if ( C_BaseEntity::BaseInterpolatePart1(this, currentTime: &flCurrentTime, &oldOrigin, &oldAngles, &bNoMoreChanges) != 0 )
    {
      if ( this->m_flCycle.m_Val != flOldCycle )
        v3 = 8;
      if ( bNoMoreChanges != 0 )
        C_BaseEntity::RemoveFromEntityList(this, listId: ENTITY_LIST_INTERPOLATE);
      C_BaseEntity::BaseInterpolatePart2(this, &oldOrigin, &oldAngles, nChangeFlags: v3);
    }
    else if ( bNoMoreChanges != 0 )
    {
      C_BaseEntity::RemoveFromEntityList(this, listId: ENTITY_LIST_INTERPOLATE);
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BCE0
// Name: public: virtual void C_BaseAnimating::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetRenderBounds(C_BaseAnimating *this, Vector *theMins, Vector *theMaxs)
{
  bool v3; // zf
  C_BaseAnimating *v4; // ebx
  Vector *v5; // edi
  Vector *v6; // esi
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v8; // esi
  float z; // ecx
  float v10; // eax
  __int64 v11; // xmm0_8
  float v12; // edx
  __int64 v13; // xmm0_8
  __int64 v14; // xmm0_8
  float v15; // ecx
  C_BaseAnimating *v16; // eax
  mstudioseqdesc_t *v17; // ebx
  double ModelHierarchyScale; // st7
  Vector v2; // [esp+Ch] [ebp-14h] BYREF
  C_BaseAnimating *v20; // [esp+18h] [ebp-8h]
  C_BaseAnimating *v21; // [esp+1Ch] [ebp-4h]

  v3 = *((_DWORD *)&this->m_bIsBlurred + 1) == 0;
  v4 = (C_BaseAnimating *)((char *)this - 4);
  v21 = this;
  v20 = (C_BaseAnimating *)((char *)this - 4);
  if ( v3 || !v4->m_bClientSideRagdoll )
  {
    if ( this->GetClientThinkable(this) != nullptr )
    {
      if ( v4->m_pStudioHdr == nullptr && v4->GetModel(this: &v4->IClientRenderable) != nullptr )
        C_BaseAnimating::LockStudioHdr(this: v4);
      m_pStudioHdr = v4->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr
        || m_pStudioHdr->m_pStudioHdr == nullptr
        || !CStudioHdr::SequencesAvailable(this: m_pStudioHdr)
        || *(_DWORD *)&v21->m_builtRagdoll == -1 )
      {
        *theMins = vec3_origin;
        *theMaxs = vec3_origin;
        return;
      }
      v8 = m_pStudioHdr->m_pStudioHdr;
      z = m_pStudioHdr->m_pStudioHdr->view_bbmin.z;
      *(_QWORD *)&v2.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->view_bbmin.x;
      v2.z = z;
      if ( VectorCompare(v1: &vec3_origin, &v2) != 0
        && (v10 = v8->view_bbmax.z,
            *(_QWORD *)&v2.x = *(_QWORD *)&v8->view_bbmax.x,
            v2.z = v10,
            VectorCompare(v1: &vec3_origin, &v2) != 0) )
      {
        v11 = *(_QWORD *)&v8->hull_min.x;
        v12 = v8->hull_min.z;
        v6 = theMins;
        *(_QWORD *)&v2.x = v11;
        LODWORD(theMins->x) = v11;
        theMins->y = v2.y;
        v2.z = v12;
        theMins->z = v12;
        v13 = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->hull_max.x;
        v2.z = m_pStudioHdr->m_pStudioHdr->hull_max.z;
      }
      else
      {
        v14 = *(_QWORD *)&v8->view_bbmin.x;
        v15 = v8->view_bbmin.z;
        v6 = theMins;
        *(_QWORD *)&v2.x = v14;
        LODWORD(theMins->x) = v14;
        theMins->y = v2.y;
        v2.z = v15;
        theMins->z = v15;
        v13 = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->view_bbmax.x;
        v2.z = m_pStudioHdr->m_pStudioHdr->view_bbmax.z;
      }
      v5 = theMaxs;
      v16 = v21;
      *(_QWORD *)&v2.x = v13;
      LODWORD(theMaxs->x) = v13;
      theMaxs->y = v2.y;
      theMaxs->z = v2.z;
      v17 = CStudioHdr::pSeqdesc(this: m_pStudioHdr, iSequence: *(_DWORD *)&v16->m_builtRagdoll);
      VectorMin(a: &v17->bbmin, b: v6, result: v6);
      VectorMax(a: &v17->bbmax, b: v5, result: v5);
      v4 = v20;
    }
    else
    {
      v6 = theMins;
      v5 = theMaxs;
      *theMins = vec3_origin;
      *theMaxs = vec3_origin;
    }
  }
  else
  {
    v5 = theMaxs;
    v6 = theMins;
    (*(void (__thiscall **)(_DWORD, Vector *, Vector *))(**((_DWORD **)&this->m_bIsBlurred + 1) + 12))(
      a1: *((_DWORD *)&this->m_bIsBlurred + 1),
      a2: theMins,
      a3: theMaxs);
    theMins->x = theMins->x - 5.0;
    theMins->y = theMins->y - 5.0;
    theMins->z = theMins->z - 5.0;
    theMaxs->x = theMaxs->x + 5.0;
    theMaxs->y = theMaxs->y + 5.0;
    theMaxs->z = theMaxs->z + 5.0;
  }
  ModelHierarchyScale = C_BaseAnimating::GetModelHierarchyScale(this: v4);
  v5->x = v5->x * ModelHierarchyScale;
  v5->y = ModelHierarchyScale * v5->y;
  v5->z = ModelHierarchyScale * v5->z;
  v6->x = v6->x * ModelHierarchyScale;
  v6->y = v6->y * ModelHierarchyScale;
  v6->z = ModelHierarchyScale * v6->z;
}

//------------------------------------------------------------------------------
// Address: 0x1002C000
// Name: public: virtual void C_BaseAnimating::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::PreDataUpdate(C_BaseAnimating *this, DataUpdateType_t updateType)
{
  int z_low; // eax
  float *p_m_InterpolationAmount; // eax
  int v5; // ecx
  double v6; // st7

  z_low = LODWORD(this->m_vecPreRagdollMaxs.z);
  this->m_iv_flCycle.m_InterpolationAmount = *(float *)&this->m_SequenceTransitioner.m_animationQueue.m_pElements;
  this->m_nPrevSkin = z_low;
  *(float *)&this->m_nPrevBody = C_BaseAnimating::GetModelHierarchyScale(this: (C_BaseAnimating *)((char *)this - 8));
  p_m_InterpolationAmount = &this->m_iv_flPoseParameter.m_InterpolationAmount;
  this->m_iv_flEncodedController.m_InterpolationAmount = *(float *)&this->m_nPrevNewSequenceParity;
  v5 = 3;
  this->m_iv_flEncodedController.m_pDebugName = (const char *)this->m_nPrevResetEventsParity;
  this->m_flOldEncodedController[0] = this->m_flEncodedController[0];
  this->m_flOldEncodedController[1] = this->m_flEncodedController[1];
  do
  {
    v6 = *(p_m_InterpolationAmount - 35);
    p_m_InterpolationAmount += 8;
    --v5;
    *(p_m_InterpolationAmount - 8) = v6;
    *(p_m_InterpolationAmount - 7) = *(p_m_InterpolationAmount - 42);
    *(p_m_InterpolationAmount - 6) = *(p_m_InterpolationAmount - 41);
    *(p_m_InterpolationAmount - 5) = *(p_m_InterpolationAmount - 40);
    *(p_m_InterpolationAmount - 4) = *(p_m_InterpolationAmount - 39);
    *(p_m_InterpolationAmount - 3) = *(p_m_InterpolationAmount - 38);
    *(p_m_InterpolationAmount - 2) = *(p_m_InterpolationAmount - 37);
    *(p_m_InterpolationAmount - 1) = *(p_m_InterpolationAmount - 36);
  }
  while ( v5 != 0 );
  C_BaseEntity::PreDataUpdate(this, updateType);
}

//------------------------------------------------------------------------------
// Address: 0x1002C0D0
// Name: public: void C_BaseAnimating::ForceSetupBonesAtTime(class matrix3x4a_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseAnimating::ForceSetupBonesAtTime(
        C_BaseAnimating *this@<ecx>,
        int a2@<esi>,
        matrix3x4a_t *pBonesOut,
        float flTime)
{
  C_BaseAnimating_vtbl *v5; // edx
  bool (__thiscall *Interpolate)(C_BaseEntity *, float); // eax
  float m_Val; // xmm4_4
  float m_prevClientCycle; // xmm2_4
  float m_prevClientAnimTime; // xmm3_4
  float m_flAnimTime; // xmm1_4
  float v11; // xmm0_4

  v5 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  this->m_iMostRecentModelBoneCounter = g_iModelBoneCounter - 1;
  Interpolate = v5->Interpolate;
  this->m_flLastBoneSetupTime = -3.4028235e38;
  ((void (__stdcall *)(_DWORD, int, C_BaseAnimating *))Interpolate)(a1: LODWORD(flTime), a2, a3: this);
  if ( this->m_bClientSideAnimation )
  {
    m_Val = this->m_flCycle.m_Val;
    m_prevClientCycle = this->m_prevClientCycle;
    if ( m_prevClientCycle > m_Val )
      m_prevClientCycle = m_prevClientCycle - 1.0;
    m_prevClientAnimTime = this->m_prevClientAnimTime;
    m_flAnimTime = this->m_flAnimTime;
    if ( m_prevClientAnimTime == m_flAnimTime )
    {
      if ( (float)(flTime - m_flAnimTime) < 0.0 )
        v11 = m_prevClientCycle;
      else
        v11 = this->m_flCycle.m_Val;
    }
    else
    {
      v11 = (float)((float)((float)(flTime - m_prevClientAnimTime) * (float)(m_Val - m_prevClientCycle))
                  / (float)(m_flAnimTime - m_prevClientAnimTime))
          + m_prevClientCycle;
    }
    if ( v11 >= 0.0 )
    {
      if ( v11 > 1.0 )
        v11 = 1.0;
    }
    else
    {
      v11 = 0.0;
    }
    if ( m_Val != v11 )
    {
      this->m_flCycle.m_Val = v11;
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 8);
    }
    ((void (__stdcall *)(matrix3x4a_t *, int, int))this->SetupBones)(a1: pBonesOut, a2: 256, a3: 524032);
    if ( this->m_flCycle.m_Val != flTime )
    {
      this->m_flCycle.m_Val = flTime;
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 8);
    }
  }
  else
  {
    ((void (__stdcall *)(matrix3x4a_t *, int, int))this->SetupBones)(a1: pBonesOut, a2: 256, a3: 524032);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C240
// Name: public: virtual void C_BaseAnimating::GetRagdollInitBoneArrays(class matrix3x4a_t __near *,class matrix3x4a_t __near *,class matrix3x4a_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::GetRagdollInitBoneArrays(
        C_BaseAnimating *this,
        matrix3x4a_t *pDeltaBones0,
        matrix3x4a_t *pDeltaBones1,
        matrix3x4a_t *pCurrentBones,
        float boneDt)
{
  double Time; // st7
  float ragdollCreateTime; // [esp+1Ch] [ebp+14h]

  C_BaseAnimating::ForceSetupBonesAtTime(
    this,
    a2: (int)this,
    pBonesOut: pDeltaBones0,
    flTime: *(float *)(gpGlobals.m_Index + 12) - boneDt);
  C_BaseAnimating::ForceSetupBonesAtTime(
    this,
    a2: (int)this,
    pBonesOut: pDeltaBones1,
    flTime: *(float *)(gpGlobals.m_Index + 12));
  Time = PhysGetSyncCreateTime();
  if ( Time == *(float *)(gpGlobals.m_Index + 12) )
  {
    memcpy(
      dst: (unsigned __int8 *)pCurrentBones,
      src: (unsigned __int8 *)this->m_CachedBoneData.m_Memory.m_pMemory,
      count: 48 * this->m_CachedBoneData.m_Size);
  }
  else
  {
    ragdollCreateTime = Time;
    C_BaseAnimating::ForceSetupBonesAtTime(this, a2: (int)this, pBonesOut: pCurrentBones, flTime: ragdollCreateTime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C2E0
// Name: public: virtual bool C_BaseAnimating::TestHitboxes(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::TestHitboxes(
        C_BaseAnimating *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  IMDLCache *v4; // edi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *m_pStudioHdr; // eax
  mstudiohitboxset_t *v8; // ebx
  const Vector *v9; // eax
  const studiohdr_t *v10; // ecx
  int v11; // eax
  IPhysicsObject *v12; // edi
  float flScale; // [esp+0h] [ebp-41Ch]
  matrix3x4_t *hitboxbones[256]; // [esp+14h] [ebp-408h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+414h] [ebp-8h]
  CStudioHdr *pStudioHdr; // [esp+418h] [ebp-4h]

  v4 = mdlcache;
  BeginLock = mdlcache->BeginLock;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  pStudioHdr = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && (v8 = (mstudiohitboxset_t *)((char *)m_pStudioHdr->m_pStudioHdr
                                  + 12 * this->m_nHitboxSet
                                  + m_pStudioHdr->m_pStudioHdr->hitboxsetindex)) != nullptr
    && v8->numhitboxes != 0
    && ray->m_IsRay )
  {
    C_BaseAnimating::HitboxToWorldTransforms(this, pHitboxToWorld: hitboxbones);
    flScale = C_BaseAnimating::GetModelHierarchyScale(this);
    v9 = this->GetRenderOrigin(this: &this->IClientRenderable);
    if ( TraceToStudio(
           pProps: physprops,
           ray,
           pStudioHdr,
           set: v8,
           hitboxbones,
           fContentsMask,
           vecOrigin: v9,
           flScale,
           tr) )
    {
      v10 = pStudioHdr->m_pStudioHdr;
      v11 = pStudioHdr->m_pStudioHdr->boneindex
          + 216 * *(int *)((char *)&v8->sznameindex + 68 * tr->hitbox + v8->hitboxindex);
      tr->surface.name = "**studio**";
      tr->surface.flags = 0x8000;
      tr->surface.surfaceProps = *(_WORD *)((char *)&v10->localanimindex + v11);
      if ( C_BaseAnimating::IsRagdoll(this) )
      {
        v12 = this->m_pRagdoll->GetElement(this: this->m_pRagdoll, a2: tr->physicsbone);
        if ( v12 != nullptr )
        {
          C_BaseEntity::VPhysicsSetObject(this, pPhysics: nullptr);
          C_BaseEntity::VPhysicsSetObject(this, pPhysics: v12);
        }
      }
    }
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 1;
  }
  else
  {
    v4->EndLock(this: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C470
// Name: public: void C_BaseAnimating::OnNewSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseAnimating::OnNewSequence(C_BaseAnimating *this@<ecx>, int a2@<ebp>)
{
  CStudioHdr *m_pStudioHdr; // edi
  int m_nSequence; // eax
  const studiohdr_t *v5; // edi
  mstudioseqdesc_t *v6; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    this->m_bSequenceLoops = GetSequenceFlags(pstudiohdr: m_pStudioHdr, sequence: this->m_nSequence) & 1;
    this->m_flGroundSpeed = C_BaseAnimating::GetSequenceGroundSpeed(
                              this,
                              a2,
                              pStudioHdr: m_pStudioHdr,
                              iSequence: this->m_nSequence);
    m_nSequence = this->m_nSequence;
    if ( m_pStudioHdr->m_pVModel != nullptr )
    {
      v6 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: this->m_nSequence);
      SetEventIndexForSequence(seqdesc: v6);
    }
    else
    {
      v5 = m_pStudioHdr->m_pStudioHdr;
      if ( m_nSequence < 0 || m_nSequence >= v5->numlocalseq )
        m_nSequence = 0;
      SetEventIndexForSequence(seqdesc: (mstudioseqdesc_t *)((char *)v5 + 212 * m_nSequence + v5->localseqindex));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C520
// Name: public: void C_BaseAnimating::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetSequence(C_BaseAnimating *this, int nSequence)
{
  int m_nValue; // edi
  const char *Classname; // eax
  const char *SequenceName; // [esp-4h] [ebp-Ch]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( this->m_nSequence != nSequence )
  {
    if ( r_debug_sequencesets.m_pParent != nullptr )
      m_nValue = r_debug_sequencesets.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue == this->entindex(this: &this->IClientNetworkable) )
    {
      SequenceName = C_BaseAnimating::GetSequenceName(this, iSequence: this->m_nSequence);
      Classname = C_BaseEntity::GetClassname(this);
      _Msg(a1: "%s : %s : SetSequence\n", Classname, SequenceName);
    }
    this->m_nSequence = nSequence;
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 48);
    if ( this->m_bClientSideAnimation )
      C_BaseAnimating::ClientSideAnimationChanged(this);
    C_BaseAnimating::OnNewSequence(this, a2: (int)&savedregs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C5B0
// Name: public: virtual void C_BaseAnimating::StudioFrameAdvance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::StudioFrameAdvance(C_BaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // edi
  float v3; // xmm0_4
  float v4; // xmm0_4
  float flNewCyclea; // [esp+4h] [ebp-4h]
  float flNewCycleb; // [esp+4h] [ebp-4h]
  float flNewCycle; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( !this->m_bClientSideAnimation )
  {
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v3 = *(float *)(gpGlobals.m_Index + 12) - this->m_flAnimTime;
      if ( v3 >= 0.2 )
        v3 = 0.2;
      if ( v3 > 0.001 )
      {
        flNewCyclea = ((double (__thiscall *)(C_BaseAnimating *, CStudioHdr *, int))this->GetSequenceCycleRate)(
                        a1: this,
                        a2: m_pStudioHdr,
                        a3: this->m_nSequence)
                    * v3;
        flNewCycleb = C_BaseAnimating::GetPlaybackRate(this) * flNewCyclea;
        v4 = this->m_flCycle.m_Val + flNewCycleb;
        this->m_flAnimTime = *(float *)(gpGlobals.m_Index + 12);
        flNewCycle = v4;
        if ( v4 < 0.0 || v4 >= 1.0 )
        {
          if ( (GetSequenceFlags(pstudiohdr: m_pStudioHdr, sequence: this->m_nSequence) & 1) != 0 )
          {
            v4 = v4 - (double)(int)v4;
          }
          else
          {
            v4 = 0.0;
            if ( flNewCycle >= 0.0 )
              v4 = 1.0;
          }
          this->m_bSequenceFinished = true;
        }
        if ( this->m_flCycle.m_Val != v4 )
        {
          this->m_flCycle.m_Val = v4;
          C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 8);
        }
        this->m_flGroundSpeed = C_BaseAnimating::GetSequenceGroundSpeed(
                                  this,
                                  a2: (int)&savedregs,
                                  pStudioHdr: m_pStudioHdr,
                                  iSequence: this->m_nSequence);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C720
// Name: public: void C_BaseAnimating::ResetSequenceInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ResetSequenceInfo(C_BaseAnimating *this)
{
  bool (__thiscall *IsPlayer)(C_BaseEntity *); // edx

  if ( this->m_nSequence == -1 )
    C_BaseAnimating::SetSequence(this, nSequence: 0);
  IsPlayer = this->IsPlayer;
  this->m_flPlaybackRate = 1.0;
  this->m_bSequenceFinished = false;
  this->m_flLastEventCheck = 0.0;
  if ( !IsPlayer(this) )
    this->m_nNewSequenceParity = ((unsigned __int8)this->m_nNewSequenceParity + 1) & 7;
  this->m_nResetEventsParity = ((unsigned __int8)this->m_nResetEventsParity + 1) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x1002C790
// Name: public: void C_BaseAnimating::DrawClientHitboxes(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::DrawClientHitboxes(C_BaseAnimating *this, float duration, bool monocolor)
{
  int v4; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  int v6; // edi
  int v7; // esi
  int v8; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // edx
  float v12; // xmm1_4
  matrix3x4_t pBoneToWorld; // [esp+10h] [ebp-5Ch] BYREF
  QAngle angles; // [esp+40h] [ebp-2Ch] BYREF
  Vector position; // [esp+4Ch] [ebp-20h] BYREF
  C_BaseAnimating *v16; // [esp+58h] [ebp-14h]
  int r; // [esp+5Ch] [ebp-10h]
  int g; // [esp+60h] [ebp-Ch]
  int b; // [esp+64h] [ebp-8h]
  int v20; // [esp+68h] [ebp-4h]

  v4 = 0;
  v16 = this;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v6 = (int)m_pStudioHdr->m_pStudioHdr + 12 * this->m_nHitboxSet + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
    if ( v6 != 0 )
    {
      r = 255;
      g = 0;
      b = 0;
      if ( *(int *)(v6 + 4) > 0 )
      {
        v20 = 0;
        do
        {
          v7 = v20 + *(_DWORD *)(v6 + 8);
          v8 = *(_DWORD *)(v7 + v6);
          v9 = v6 + v7;
          C_BaseAnimating::GetBoneTransform(this: v16, iBone: v8, &pBoneToWorld);
          MatrixAngles(src: (const VMatrix *)&pBoneToWorld, vAngles: &angles);
          position.x = pBoneToWorld.m_flMatVal[0][3];
          position.y = pBoneToWorld.m_flMatVal[1][3];
          position.z = pBoneToWorld.m_flMatVal[2][3];
          if ( !monocolor )
          {
            v10 = *(_DWORD *)(v9 + 4) % 8;
            v11 = (int)(float)(hullcolor[v10].y * 255.0);
            v12 = hullcolor[v10].z * 255.0;
            r = (int)(float)(hullcolor[v10].x * 255.0);
            g = v11;
            b = (int)v12;
          }
          ((void (__stdcall *)(Vector *, int, int, QAngle *, int, int, int, _DWORD, _DWORD))debugoverlay->AddBoxOverlay)(
            a1: &position,
            a2: v9 + 8,
            a3: v9 + 20,
            a4: &angles,
            a5: r,
            a6: g,
            a7: b,
            a8: 0,
            a9: LODWORD(duration));
          v20 += 68;
          ++v4;
        }
        while ( v4 < *(_DWORD *)(v6 + 4) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C910
// Name: float Lerp_Hermite<float>(float const __near &,float,float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Lerp_Hermite<float>(const float *__formal, float t, const float *p0, const float *p1, const float *p2)
{
  double v6; // st7
  float tCube; // [esp+0h] [ebp-10h]

  v6 = *p1;
  tCube = (float)(t * t) * t;
  return ((float)(tCube * 2.0) - (float)((float)(t * t) * 3.0) + 1.0) * v6
       + ((float)((float)(t * t) * 3.0) - (float)(tCube * 2.0)) * *p2
       + (tCube - ((float)(t * t) + (float)(t * t)) + t) * (v6 - *p0)
       + (tCube - (float)(t * t)) * (*p2 - v6);
}

//------------------------------------------------------------------------------
// Address: 0x1002C9B0
// Name: public: virtual void CInterpolatedVarArrayBase<float,1>::RestoreToLastNetworked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::RestoreToLastNetworked(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this)
{
  memcpy(
    dst: (unsigned __int8 *)this->m_pValue,
    src: (unsigned __int8 *)this->m_LastNetworkedValue,
    count: 4 * this->m_nMaxCount);
}

//------------------------------------------------------------------------------
// Address: 0x1002C9D0
// Name: protected: void CInterpolatedVarArrayBase<float,1>::_Interpolate(float __near *,float,struct CInterpolatedVarEntryBase<float,1> __near *,struct CInterpolatedVarEntryBase<float,1> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::_Interpolate(
        CInterpolatedVarArrayBase<float,1> *this,
        float *out,
        float frac,
        CInterpolatedVarEntryBase<float,1> *start,
        CInterpolatedVarEntryBase<float,1> *end)
{
  int v5; // edx
  float *v6; // eax
  int v7; // esi
  float *value; // eax
  char *v9; // esi
  char *v10; // edi
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4

  v5 = 0;
  if ( start == end )
  {
    if ( this->m_nMaxCount != 0 )
    {
      v6 = out;
      v7 = (char *)end->value - (char *)out;
      do
      {
        ++v5;
        *v6 = *(float *)((char *)v6 + v7);
        ++v6;
      }
      while ( v5 < this->m_nMaxCount );
    }
  }
  else if ( this->m_nMaxCount != 0 )
  {
    value = start->value;
    v9 = (char *)((char *)end->value - (char *)value);
    v10 = (char *)((char *)out - (char *)value);
    do
    {
      v11 = *(float *)((char *)value + (_DWORD)v9);
      if ( this->m_bLooping[v5] != 0 )
      {
        v12 = *value;
        if ( fabs(v11 - *value) >= 0.5 )
        {
          if ( v11 <= v12 )
            v11 = v11 + 1.0;
          else
            v12 = v12 + 1.0;
        }
        v13 = (float)((float)((float)(1.0 - frac) * v12) + (float)(v11 * frac))
            - (float)(int)(float)((float)((float)(1.0 - frac) * v12) + (float)(v11 * frac));
        if ( v13 < 0.0 )
          v13 = v13 + 1.0;
        *(float *)((char *)value + (_DWORD)v10) = v13;
      }
      else
      {
        *(float *)((char *)value + (_DWORD)v10) = (float)((float)(v11 - *value) * frac) + *value;
      }
      ++v5;
      ++value;
    }
    while ( v5 < this->m_nMaxCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CAD0
// Name: float LoopingLerp_Hermite<float>(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl LoopingLerp_Hermite<float>(float __formal, float t, float p0, float p1, float p2)
{
  float v5; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float s; // [esp+10h] [ebp+10h]

  v5 = p1;
  v6 = p0;
  if ( fabs(p1 - p0) > 0.5 )
  {
    if ( p1 <= p0 )
    {
      v5 = p1 + 1.0;
    }
    else
    {
      v6 = p0 + 1.0;
      p0 = p0 + 1.0;
    }
  }
  v7 = p2;
  if ( fabs(p2 - v5) > 0.5 )
  {
    if ( p2 <= v5 )
    {
      v7 = p2 + 1.0;
    }
    else
    {
      v5 = v5 + 1.0;
      if ( fabs(v5 - v6) > 0.5 )
      {
        if ( v5 <= v6 )
          v5 = v5 + 1.0;
        else
          p0 = v6 + 1.0;
      }
    }
  }
  v8 = (float)((float)((float)((float)((float)((float)((float)((float)(t * t) * t) * 2.0) - (float)((float)(t * t) * 3.0))
                                     + 1.0)
                             * v5)
                     + (float)((float)((float)((float)(t * t) * 3.0) - (float)((float)((float)(t * t) * t) * 2.0)) * v7))
             + (float)((float)((float)((float)((float)(t * t) * t) - (float)((float)(t * t) * 2.0)) + t)
                     * (float)(v5 - p0)))
     + (float)((float)((float)((float)(t * t) * t) - (float)(t * t)) * (float)(v7 - v5));
  v9 = v8 - (float)(int)v8;
  s = v9;
  if ( v9 < 0.0 )
    return (float)(v9 + 1.0);
  return s;
}

//------------------------------------------------------------------------------
// Address: 0x1002CC10
// Name: public: void CInterpolatedVarEntryBase<float,1>::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarEntryBase<float,1>::Init(
        CInterpolatedVarEntryBase<float,1> *this,
        unsigned int maxCount)
{
  if ( maxCount != 0 )
  {
    if ( maxCount != this->count )
    {
      C_BaseEntity::operator delete(pMem: this->value);
      this->value = nullptr;
      this->count = 0;
    }
    if ( this->value == nullptr )
    {
      this->count = maxCount;
      this->value = (float *)MemAlloc_Alloc(nSize: (unsigned __int64)maxCount >> 30 != 0 ? -1 : 4 * maxCount);
    }
  }
  else
  {
    C_BaseEntity::operator delete(pMem: this->value);
    this->value = nullptr;
    this->count = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CCE0
// Name: protected: void CInterpolatedVarArrayBase<float,1>::_Extrapolate(float __near *,struct CInterpolatedVarEntryBase<float,1> __near *,struct CInterpolatedVarEntryBase<float,1> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::_Extrapolate(
        CInterpolatedVarArrayBase<float,1> *this,
        float *pOut,
        CInterpolatedVarEntryBase<float,1> *pOld,
        CInterpolatedVarEntryBase<float,1> *pNew,
        float flDestinationTime,
        float flMaxExtrapolationAmount)
{
  float flChangeTime; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  int v9; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // eax
  double v13; // st7

  flChangeTime = pNew->flChangeTime;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(pOld->flChangeTime - pNew->flChangeTime) & _mask__AbsFloat_) < 0.001
    || flChangeTime >= flDestinationTime )
  {
    v12 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      do
      {
        v13 = pNew->value[v12++];
        pOut[v12 - 1] = v13;
      }
      while ( v12 < this->m_nMaxCount );
    }
  }
  else
  {
    v7 = flMaxExtrapolationAmount;
    if ( flMaxExtrapolationAmount > (float)(flDestinationTime - flChangeTime) )
      v7 = flDestinationTime - flChangeTime;
    v8 = flChangeTime - pOld->flChangeTime;
    v9 = 0;
    if ( this->m_nMaxCount != 0 )
    {
      v10 = (float)((float)(1.0 / v8) * v7) + 1.0;
      do
      {
        v11 = pOld->value[v9];
        pOut[v9] = (float)((float)(pNew->value[v9] - v11) * v10) + v11;
        ++v9;
      }
      while ( v9 < this->m_nMaxCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CDB0
// Name: public: void CInterpolatedVarArrayBase<float,1>::AddToHead(float,float const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::AddToHead(
        CInterpolatedVarArrayBase<float,1> *this,
        float changeTime,
        float *values,
        bool bFlushNewer)
{
  unsigned int m_firstElement; // eax
  unsigned int m_maxElement; // ecx
  unsigned __int16 m_count; // dx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *p_m_VarHistory; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // ebx
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  unsigned int m_nMaxCount; // edi
  int v29; // esi
  unsigned __int8 *v30; // esi
  int newslot; // [esp+10h] [ebp+10h]

  if ( bFlushNewer )
  {
    while ( this->m_VarHistory.m_count != 0 )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      if ( m_firstElement >= m_maxElement )
        m_firstElement -= m_maxElement;
      if ( (float)(this->m_VarHistory.m_pElements[m_firstElement].flChangeTime + 0.000099999997) <= changeTime )
        break;
      m_count = this->m_VarHistory.m_count;
      if ( m_count != 0 )
      {
        v8 = this->m_VarHistory.m_maxElement;
        v9 = this->m_VarHistory.m_firstElement + 1;
        if ( v9 >= v8 )
          LOWORD(v9) = v9 - v8;
        this->m_VarHistory.m_firstElement = v9;
        this->m_VarHistory.m_count = m_count - 1;
      }
    }
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v11 = this->m_VarHistory.m_maxElement;
    v12 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v13 = v12 + v11 - 1;
    if ( v13 >= v11 )
      LOWORD(v13) = v13 - v11;
    this->m_VarHistory.m_firstElement = v13;
    newslot = 0;
  }
  else
  {
    p_m_VarHistory = &this->m_VarHistory;
    CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
      this: &this->m_VarHistory,
      capSize: this->m_VarHistory.m_count + 1);
    v14 = this->m_VarHistory.m_maxElement;
    v15 = this->m_VarHistory.m_firstElement;
    ++this->m_VarHistory.m_count;
    v16 = v15 + v14 - 1;
    if ( v16 >= v14 )
      LOWORD(v16) = v16 - v14;
    v17 = 1;
    this->m_VarHistory.m_firstElement = v16;
    newslot = 0;
    if ( this->m_VarHistory.m_count > 1u )
    {
      do
      {
        v18 = this->m_VarHistory.m_maxElement;
        v19 = v17 + this->m_VarHistory.m_firstElement;
        if ( v19 >= v18 )
          v19 -= v18;
        if ( changeTime >= p_m_VarHistory->m_pElements[v19].flChangeTime )
          break;
        v20 = this->m_VarHistory.m_firstElement;
        v21 = v20 + v17;
        if ( v20 + v17 >= v18 )
          v21 -= v18;
        v22 = v20 + newslot;
        v23 = this->m_VarHistory.m_maxElement;
        if ( v22 >= v23 )
          v22 -= v23;
        v24 = (int)&p_m_VarHistory->m_pElements[v21];
        v25 = (int)&p_m_VarHistory->m_pElements[v22];
        *(_DWORD *)(v25 + 8) = *(_DWORD *)(v24 + 8);
        *(_DWORD *)(v25 + 4) = *(_DWORD *)(v24 + 4);
        *(float *)v25 = *(float *)v24;
        *(_DWORD *)(v24 + 8) = 0;
        *(_DWORD *)(v24 + 4) = 0;
        newslot = v17++;
      }
      while ( v17 < this->m_VarHistory.m_count );
    }
  }
  v26 = p_m_VarHistory->m_maxElement;
  v27 = newslot + p_m_VarHistory->m_firstElement;
  if ( v27 >= v26 )
    v27 -= v26;
  m_nMaxCount = this->m_nMaxCount;
  v29 = (int)&p_m_VarHistory->m_pElements[v27];
  *(float *)v29 = changeTime;
  if ( m_nMaxCount != 0 )
  {
    if ( m_nMaxCount != *(_DWORD *)(v29 + 4) )
    {
      C_BaseEntity::operator delete(pMem: *(void **)(v29 + 8));
      *(_DWORD *)(v29 + 8) = 0;
      *(_DWORD *)(v29 + 4) = 0;
    }
    if ( *(_DWORD *)(v29 + 8) == 0 )
    {
      *(_DWORD *)(v29 + 4) = m_nMaxCount;
      *(_DWORD *)(v29 + 8) = MemAlloc_Alloc(nSize: (unsigned __int64)m_nMaxCount >> 30 != 0 ? -1 : 4 * m_nMaxCount);
    }
  }
  else
  {
    C_BaseEntity::operator delete(pMem: *(void **)(v29 + 8));
    *(_DWORD *)(v29 + 8) = 0;
    *(_DWORD *)(v29 + 4) = 0;
  }
  v30 = *(unsigned __int8 **)(v29 + 8);
  if ( v30 != nullptr && m_nMaxCount != 0 )
    memcpy(dst: v30, src: (unsigned __int8 *)values, count: 4 * m_nMaxCount);
}

//------------------------------------------------------------------------------
// Address: 0x1002CFB0
// Name: protected: bool CInterpolatedVarArrayBase<float,1>::GetInterpolationInfo(class CInterpolatedVarArrayBase<float,1>::CInterpolationInfo __near *,float,float,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInterpolatedVarArrayBase<float,1>::GetInterpolationInfo(
        CInterpolatedVarArrayBase<float,1> *this,
        CInterpolatedVarArrayBase<float,1>::CInterpolationInfo *pInfo,
        float currentTime,
        float interpolation_amount,
        int *pNoMoreChanges)
{
  float v5; // xmm0_4
  int v6; // esi
  int m_maxElement; // edi
  int v8; // eax
  float flChangeTime; // xmm1_4
  int newer; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  int v17; // edi
  int v18; // eax
  int v19; // edi
  int m_firstElement; // ebx
  int v21; // eax
  int v22; // esi
  unsigned int v23; // edi
  float *value; // ecx
  int v25; // eax
  float *v26; // eax
  int v27; // edx
  unsigned int v28; // eax
  float *v29; // edi
  int v30; // edx
  float *v31; // ecx
  int older; // eax
  int v33; // [esp+0h] [ebp-4h]
  CInterpolatedVarEntryBase<float,1> *currentTimea; // [esp+10h] [ebp+Ch]
  unsigned int interpolation_amounta; // [esp+14h] [ebp+10h]

  v5 = currentTime - interpolation_amount;
  pInfo->m_bHermite = false;
  pInfo->frac = 0.0;
  pInfo->newer = -1;
  pInfo->older = -1;
  pInfo->oldest = -1;
  v6 = 0;
  if ( this->m_VarHistory.m_count == 0 )
  {
LABEL_7:
    newer = pInfo->newer;
    if ( newer == -1 )
    {
      older = pInfo->older;
      pInfo->newer = older;
      return older != -1;
    }
    else
    {
      pInfo->older = newer;
      return true;
    }
  }
  while ( 1 )
  {
    pInfo->older = v6;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v8 = v6 + this->m_VarHistory.m_firstElement;
    if ( v8 >= m_maxElement )
      v8 -= m_maxElement;
    flChangeTime = this->m_VarHistory.m_pElements[v8].flChangeTime;
    if ( flChangeTime == 0.0 )
      goto LABEL_7;
    if ( flChangeTime <= v5 )
      break;
    pInfo->newer = v6++;
    if ( v6 >= this->m_VarHistory.m_count )
      goto LABEL_7;
  }
  v12 = pInfo->newer;
  if ( v12 != -1 )
  {
    v13 = this->m_VarHistory.m_maxElement;
    v14 = v12 + this->m_VarHistory.m_firstElement;
    if ( v14 >= v13 )
      v14 -= v13;
    v15 = this->m_VarHistory.m_pElements[v14].flChangeTime - flChangeTime;
    if ( v15 > 0.000099999997 )
    {
      v16 = (float)(v5 - flChangeTime) / v15;
      pInfo->frac = v16;
      if ( v16 >= 2.0 )
        v16 = 2.0;
      pInfo->frac = v16;
      v17 = v6 + 1;
      if ( (this->m_fType & 0x10) == 0 && v17 >= 0 && v17 < this->m_VarHistory.m_count )
      {
        pInfo->oldest = v17;
        v18 = v17 + this->m_VarHistory.m_firstElement;
        v19 = this->m_VarHistory.m_maxElement;
        if ( v18 >= v19 )
          v18 -= v19;
        if ( (float)(flChangeTime - this->m_VarHistory.m_pElements[v18].flChangeTime) > 0.000099999997 )
          pInfo->m_bHermite = true;
      }
      if ( pNoMoreChanges != nullptr && v12 == (this->m_VarHistory.m_count != 0) - 1 )
      {
        m_firstElement = this->m_VarHistory.m_firstElement;
        v21 = m_firstElement + v6;
        v22 = this->m_VarHistory.m_maxElement;
        v23 = 4 * this->m_nMaxCount;
        interpolation_amounta = v23;
        if ( v21 >= v22 )
          v21 -= v22;
        currentTimea = this->m_VarHistory.m_pElements;
        value = currentTimea[v21].value;
        v25 = m_firstElement + pInfo->newer;
        v33 = v25;
        if ( v25 >= v22 )
          v25 -= v22;
        v26 = currentTimea[v25].value;
        if ( v23 >= 4 )
        {
          while ( *(_DWORD *)v26 == *(_DWORD *)value )
          {
            v23 -= 4;
            ++value;
            ++v26;
            if ( v23 < 4 )
              goto LABEL_35;
          }
          return true;
        }
LABEL_35:
        if ( v23 == 0
          || *(_BYTE *)value == *(_BYTE *)v26
          && (v23 <= 1
           || *((_BYTE *)value + 1) == *((_BYTE *)v26 + 1) && (v23 <= 2 || *((_BYTE *)value + 2) == *((_BYTE *)v26 + 2))) )
        {
          if ( !pInfo->m_bHermite )
            goto LABEL_55;
          v27 = m_firstElement + pInfo->oldest;
          v28 = interpolation_amounta;
          if ( v27 >= v22 )
            v27 -= v22;
          v29 = currentTimea[v27].value;
          v30 = v33;
          if ( v33 >= v22 )
            v30 = v33 - v22;
          v31 = currentTimea[v30].value;
          if ( interpolation_amounta >= 4 )
          {
            while ( *(_DWORD *)v31 == *(_DWORD *)v29 )
            {
              v28 -= 4;
              ++v29;
              ++v31;
              if ( v28 < 4 )
                goto LABEL_49;
            }
            return true;
          }
LABEL_49:
          if ( v28 == 0
            || *(_BYTE *)v29 == *(_BYTE *)v31
            && (v28 <= 1
             || *((_BYTE *)v29 + 1) == *((_BYTE *)v31 + 1) && (v28 <= 2 || *((_BYTE *)v29 + 2) == *((_BYTE *)v31 + 2))) )
          {
LABEL_55:
            *pNoMoreChanges = 1;
          }
        }
      }
    }
    return true;
  }
  pInfo->newer = v6;
  if ( pNoMoreChanges != nullptr )
    *pNoMoreChanges = 1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002D230
// Name: protected: void CInterpolatedVarArrayBase<float,1>::_Interpolate_Hermite(float __near *,float,struct CInterpolatedVarEntryBase<float,1> __near *,struct CInterpolatedVarEntryBase<float,1> __near *,struct CInterpolatedVarEntryBase<float,1> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::_Interpolate_Hermite(
        CInterpolatedVarArrayBase<float,1> *this,
        float *out,
        float frac,
        CInterpolatedVarEntryBase<float,1> *prev,
        CInterpolatedVarEntryBase<float,1> *start,
        CInterpolatedVarEntryBase<float,1> *end,
        bool looping)
{
  CInterpolatedVarArrayBase<float,1> *v7; // esi
  CInterpolatedVarEntryBase<float,1> *p_fixup; // ebx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  int v13; // eax
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float *value; // edx
  int v19; // ecx
  float v20; // xmm0_4
  int v21; // ecx
  float v22; // xmm2_4
  int v23; // ebx
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm2_4
  float *v34; // edx
  float v35; // xmm6_4
  unsigned int m_nMaxCount; // [esp-4h] [ebp-28h]
  CInterpolatedVarEntryBase<float,1> fixup; // [esp+Ch] [ebp-18h] BYREF
  CInterpolatedVarArrayBase<float,1> *v38; // [esp+18h] [ebp-Ch]
  float v39; // [esp+1Ch] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+23h] [ebp-1h] BYREF
  float preva; // [esp+34h] [ebp+10h]
  float starta; // [esp+38h] [ebp+14h]

  v7 = this;
  v38 = this;
  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  m_nMaxCount = v7->m_nMaxCount;
  memset(&fixup, 0, sizeof(fixup));
  CInterpolatedVarEntryBase<float,1>::Init(this: &fixup, maxCount: m_nMaxCount);
  p_fixup = prev;
  v10 = end->flChangeTime - start->flChangeTime;
  v11 = start->flChangeTime - prev->flChangeTime;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v10 - v11) & _mask__AbsFloat_) > 0.000099999997 && v11 > 0.000099999997 )
  {
    v12 = v10 / v11;
    v13 = 0;
    fixup.flChangeTime = start->flChangeTime - v10;
    if ( v7->m_nMaxCount != 0 )
    {
      do
      {
        if ( v7->m_bLooping[v13] != 0 )
        {
          if ( g_bHermiteFix )
          {
            fixup.value[v13] = prev->value[v13];
          }
          else
          {
            v14 = start->value[v13];
            v15 = prev->value[v13];
            if ( fabs(v14 - v15) >= 0.5 )
            {
              if ( v14 <= v15 )
                v14 = v14 + 1.0;
              else
                v15 = v15 + 1.0;
            }
            v16 = (float)((float)(1.0 - (float)(1.0 - v12)) * v15) + (float)((float)(1.0 - v12) * v14);
            v17 = v16 - (float)(int)v16;
            if ( v17 < 0.0 )
              v17 = v17 + 1.0;
            fixup.value[v13] = v17;
          }
        }
        else
        {
          value = prev->value;
          v19 = v13;
          if ( g_bHermiteFix )
            v20 = value[v19];
          else
            v20 = (float)((float)(start->value[v13] - value[v13]) * (float)(1.0 - v12)) + value[v13];
          fixup.value[v19] = v20;
        }
        ++v13;
      }
      while ( v13 < v7->m_nMaxCount );
    }
    p_fixup = &fixup;
  }
  v21 = 0;
  if ( v7->m_nMaxCount != 0 )
  {
    v22 = frac;
    v23 = (char *)p_fixup->value - (char *)out;
    v24 = v22 * v22;
    preva = v22 * v22;
    while ( 1 )
    {
      if ( v7->m_bLooping[v21] != 0 )
      {
        v25 = start->value[v21];
        v26 = end->value[v21];
        v27 = &out[v21];
        v28 = *(float *)((char *)v27 + v23);
        starta = v28;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v25 - v28) & _mask__AbsFloat_) > 0.5 )
        {
          if ( v25 <= v28 )
          {
            v25 = v25 + 1.0;
          }
          else
          {
            v28 = v28 + 1.0;
            starta = v28;
          }
        }
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v26 - v25) & _mask__AbsFloat_) > 0.5 )
        {
          if ( v26 <= v25 )
          {
            v26 = v26 + 1.0;
          }
          else
          {
            v25 = v25 + 1.0;
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v25 - v28) & _mask__AbsFloat_) > 0.5 )
            {
              if ( v25 <= v28 )
                v25 = v25 + 1.0;
              else
                starta = v28 + 1.0;
            }
          }
        }
        v29 = (float)((float)((float)((float)((float)((float)((float)(v24 * v22) * 2.0) - (float)(v24 * 3.0)) + 1.0)
                                    * v25)
                            + (float)((float)((float)(v24 * 3.0) - (float)((float)(v24 * v22) * 2.0)) * v26))
                    + (float)((float)((float)((float)(v24 * v22) - (float)(v24 * 2.0)) + frac) * (float)(v25 - starta)))
            + (float)((float)((float)(v24 * v22) - v24) * (float)(v26 - v25));
        v30 = v29 - (float)(int)v29;
        if ( v30 < 0.0 )
          v30 = v30 + 1.0;
        *v27 = v30;
      }
      else
      {
        v31 = &start->value[v21];
        v32 = v24 * v22;
        v33 = end->value[v21];
        v34 = &out[v21];
        v7 = v38;
        v39 = (float)(v32 - (float)(v24 * 2.0)) + frac;
        v35 = (float)((float)(v39 * (float)(*v31 - *(float *)((char *)v34 + v23)))
                    + (float)((float)((float)((float)((float)(v32 * 2.0) - (float)(v24 * 3.0)) + 1.0) * *v31)
                            + (float)((float)((float)(v24 * 3.0) - (float)(v32 * 2.0)) * v33)))
            + (float)((float)(v33 - *v31) * (float)(v32 - v24));
        v39 = (float)((float)(v32 * 2.0) - (float)(v24 * 3.0)) + 1.0;
        *v34 = v35;
      }
      v24 = preva;
      if ( ++v21 >= v7->m_nMaxCount )
        break;
      v22 = frac;
    }
  }
  C_BaseEntity::operator delete(pMem: fixup.value);
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x1002DDF0
// Name: public: CUtlMemoryAligned<class matrix3x4a_t,16>::~CUtlMemoryAligned<class matrix3x4a_t,16>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<matrix3x4a_t,16>::~CUtlMemoryAligned<matrix3x4a_t,16>(
        CUtlMemoryAligned<matrix3x4a_t,16> *this)
{
  bool v2; // sf

  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((int)this->m_pMemory & 0xFFFFFFFC) - 4));
      this->m_pMemory = nullptr;
    }
    v2 = this->m_nGrowSize < 0;
    this->m_nAllocationCount = 0;
    if ( !v2 )
    {
      if ( this->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
        this->m_pMemory = nullptr;
      }
      this->m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DFE0
// Name: public: virtual void CInterpolatedVarArrayBase<float,1>::Reset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::Reset(
        CInterpolatedVarArrayBase<float,1> *this,
        float flCurrentTime)
{
  float *m_pValue; // eax

  CInterpolatedVarArrayBase<float,1>::ClearHistory(this);
  m_pValue = this->m_pValue;
  if ( m_pValue != nullptr )
  {
    CInterpolatedVarArrayBase<float,1>::AddToHead(this, changeTime: flCurrentTime, values: m_pValue, bFlushNewer: false);
    CInterpolatedVarArrayBase<float,1>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    CInterpolatedVarArrayBase<float,1>::AddToHead(
      this,
      changeTime: flCurrentTime,
      values: this->m_pValue,
      bFlushNewer: false);
    memcpy(
      dst: (unsigned __int8 *)this->m_LastNetworkedValue,
      src: (unsigned __int8 *)this->m_pValue,
      count: 4 * this->m_nMaxCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E060
// Name: public: virtual void CInterpolatedVarArrayBase<float,1>::Copy(class IInterpolatedVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::Copy(
        CInterpolatedVarArrayBase<float,1> *this,
        IInterpolatedVar *pInSrc)
{
  CInterpolatedVarArrayBase<float,1> *v3; // eax
  CInterpolatedVarArrayBase<float,1> *v4; // ebx
  unsigned __int8 m_nMaxCount; // cl
  int v6; // eax
  int v7; // eax
  int m_maxElement; // ecx
  int v9; // eax
  int v10; // ecx
  CInterpolatedVarEntryBase<float,1> *v11; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  CInterpolatedVarEntryBase<float,1> *m_pElements; // eax
  unsigned __int8 *value; // ecx
  int v17; // ebx
  float *v18; // eax
  unsigned __int8 *v19; // esi
  unsigned __int8 *src; // [esp+8h] [ebp-Ch]
  CInterpolatedVarArrayBase<float,1> *pSrc; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = (CInterpolatedVarArrayBase<float,1> *)__RTDynamicCast(
                                               inptr: pInSrc,
                                               VfDelta: 0,
                                               SrcType: &IInterpolatedVar `RTTI Type Descriptor',
                                               TargetType: &CInterpolatedVarArrayBase<float,1> `RTTI Type Descriptor',
                                               isReference: 0);
  v4 = v3;
  pSrc = v3;
  if ( v3 != nullptr )
  {
    m_nMaxCount = this->m_nMaxCount;
    if ( v3->m_nMaxCount == m_nMaxCount )
    {
      v6 = 0;
      if ( m_nMaxCount != 0 )
      {
        do
        {
          this->m_LastNetworkedValue[v6] = v4->m_LastNetworkedValue[v6];
          this->m_bLooping[v6] = v4->m_bLooping[v6];
          ++v6;
        }
        while ( v6 < this->m_nMaxCount );
      }
      this->m_LastNetworkedTime = v4->m_LastNetworkedTime;
      *(_DWORD *)&this->m_VarHistory.m_firstElement = 0;
      i = 0;
      if ( v4->m_VarHistory.m_count != 0 )
      {
        while ( 1 )
        {
          CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
            this: &this->m_VarHistory,
            capSize: this->m_VarHistory.m_count + 1);
          v7 = this->m_VarHistory.m_firstElement + ++this->m_VarHistory.m_count - 1;
          m_maxElement = this->m_VarHistory.m_maxElement;
          if ( v7 >= m_maxElement )
            v7 -= m_maxElement;
          v9 = v7 + this->m_VarHistory.m_firstElement;
          v10 = this->m_VarHistory.m_maxElement;
          if ( v9 >= v10 )
            v9 -= v10;
          v11 = &this->m_VarHistory.m_pElements[v9];
          v12 = v4->m_VarHistory.m_maxElement;
          v13 = i + v4->m_VarHistory.m_firstElement;
          if ( v13 >= v12 )
            v13 -= v12;
          v14 = v13;
          m_pElements = v4->m_VarHistory.m_pElements;
          value = (unsigned __int8 *)m_pElements[v14].value;
          v17 = this->m_nMaxCount;
          v11->flChangeTime = m_pElements[v14].flChangeTime;
          src = value;
          if ( v17 == 0 )
            break;
          if ( v17 != v11->count )
          {
            C_BaseEntity::operator delete(pMem: v11->value);
            v11->value = nullptr;
            v11->count = 0;
          }
          if ( v11->value == nullptr )
          {
            v11->count = v17;
            v18 = (float *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v17 >> 30 != 0 ? -1 : 4 * v17);
            goto LABEL_20;
          }
LABEL_21:
          v19 = (unsigned __int8 *)v11->value;
          if ( v19 != nullptr && v17 != 0 )
            memcpy(dst: v19, src, count: 4 * v17);
          if ( ++i >= pSrc->m_VarHistory.m_count )
            return;
          v4 = pSrc;
        }
        C_BaseEntity::operator delete(pMem: v11->value);
        v18 = nullptr;
        v11->count = 0;
LABEL_20:
        v11->value = v18;
        goto LABEL_21;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E3E0
// Name: public: bool CInterpolatedVarArrayBase<float,1>::NoteChanged(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<float,1>::NoteChanged(
        CInterpolatedVarArrayBase<float,1> *this,
        float flCurrentTime,
        float flChangeTime,
        float interpolation_amount,
        bool bUpdateLastNetworkedValue)
{
  char v6; // bl
  unsigned int m_firstElement; // ecx
  unsigned int m_maxElement; // edx
  unsigned int v9; // eax
  float *m_pValue; // edi
  float *value; // ecx
  int v12; // ecx
  int v13; // edi
  int i; // edx
  int v15; // eax
  bool bRet; // [esp+1Bh] [ebp-1h]

  v6 = 1;
  bRet = true;
  if ( this->m_VarHistory.m_count != 0 )
  {
    m_firstElement = this->m_VarHistory.m_firstElement;
    m_maxElement = this->m_VarHistory.m_maxElement;
    v9 = 4 * this->m_nMaxCount;
    if ( m_firstElement >= m_maxElement )
      m_firstElement -= m_maxElement;
    m_pValue = this->m_pValue;
    value = this->m_VarHistory.m_pElements[m_firstElement].value;
    if ( v9 < 4 )
    {
LABEL_7:
      if ( v9 == 0
        || *(_BYTE *)value == *(_BYTE *)m_pValue
        && (v9 <= 1
         || *((_BYTE *)value + 1) == *((_BYTE *)m_pValue + 1)
         && (v9 <= 2 || *((_BYTE *)value + 2) == *((_BYTE *)m_pValue + 2))) )
      {
        v6 = 0;
        bRet = false;
      }
    }
    else
    {
      while ( *(_DWORD *)m_pValue == *(_DWORD *)value )
      {
        v9 -= 4;
        ++value;
        ++m_pValue;
        if ( v9 < 4 )
          goto LABEL_7;
      }
    }
  }
  CInterpolatedVarArrayBase<float,1>::AddToHead(
    this,
    changeTime: flChangeTime,
    values: this->m_pValue,
    bFlushNewer: true);
  if ( bUpdateLastNetworkedValue )
    this->NoteLastNetworkedValue(this);
  v12 = 0;
  if ( this->m_VarHistory.m_count == 0 )
    return v6;
  v13 = this->m_VarHistory.m_maxElement;
  for ( i = this->m_VarHistory.m_firstElement - v13; ; ++i )
  {
    v15 = v12 + this->m_VarHistory.m_firstElement;
    if ( v15 >= v13 )
      v15 = i;
    if ( (float)((float)(flCurrentTime - interpolation_amount) - 0.050000001) > this->m_VarHistory.m_pElements[v15].flChangeTime )
      break;
    if ( ++v12 >= this->m_VarHistory.m_count )
      return bRet;
  }
  if ( v12 + 3 >= this->m_VarHistory.m_count )
    return bRet;
  this->m_VarHistory.m_count = v12 + 3;
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x1002E500
// Name: public: int CInterpolatedVarArrayBase<float,1>::Interpolate(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<float,1>::Interpolate(
        CInterpolatedVarArrayBase<float,1> *this,
        float currentTime,
        float interpolation_amount)
{
  int m_firstElement; // eax
  int m_maxElement; // ecx
  int v6; // edx
  int v7; // eax
  int newer; // ebx
  int v9; // eax
  CInterpolatedVarEntryBase<float,1> *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  CInterpolatedVarEntryBase<float,1> *v16; // [esp+8h] [ebp-34h]
  float flMaxExtrapolationAmount; // [esp+10h] [ebp-2Ch]
  CInterpolatedVarArrayBase<float,1>::CInterpolationInfo info; // [esp+20h] [ebp-1Ch] BYREF
  int realOlder; // [esp+34h] [ebp-8h]
  int noMoreChanges; // [esp+38h] [ebp-4h] BYREF

  noMoreChanges = 0;
  if ( CInterpolatedVarArrayBase<float,1>::GetInterpolationInfo(
         this,
         pInfo: &info,
         currentTime,
         interpolation_amount,
         pNoMoreChanges: &noMoreChanges) )
  {
    if ( info.m_bHermite )
    {
      m_firstElement = this->m_VarHistory.m_firstElement;
      m_maxElement = this->m_VarHistory.m_maxElement;
      realOlder = m_firstElement + info.newer;
      if ( m_firstElement + info.newer >= m_maxElement )
        realOlder = m_firstElement + info.newer - m_maxElement;
      v6 = m_firstElement + info.older;
      if ( m_firstElement + info.older >= m_maxElement )
        v6 -= m_maxElement;
      v7 = info.oldest + m_firstElement;
      if ( v7 >= m_maxElement )
        v7 -= m_maxElement;
      CInterpolatedVarArrayBase<float,1>::_Interpolate_Hermite(
        this,
        out: this->m_pValue,
        frac: info.frac,
        prev: &this->m_VarHistory.m_pElements[v7],
        start: &this->m_VarHistory.m_pElements[v6],
        end: &this->m_VarHistory.m_pElements[realOlder],
        looping: false);
    }
    else
    {
      newer = info.newer;
      if ( info.newer == info.older
        && (v9 = info.newer + 1, realOlder = info.newer + 1, CInterpolationContext::s_bAllowExtrapolation)
        && v9 >= 0
        && v9 < this->m_VarHistory.m_count
        && CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
             this: &this->m_VarHistory,
             i: info.newer + 1)->flChangeTime != 0.0
        && interpolation_amount > 0.000001
        && this->m_LastNetworkedTime >= CInterpolationContext::s_flLastTimeStamp )
      {
        flMaxExtrapolationAmount = cl_extrapolate_amount.m_pParent->m_Value.m_fValue;
        v16 = CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](this: &this->m_VarHistory, i: newer);
        v10 = CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](this: &this->m_VarHistory, i: realOlder);
        CInterpolatedVarArrayBase<float,1>::_Extrapolate(
          this,
          pOut: this->m_pValue,
          pOld: v10,
          pNew: v16,
          flDestinationTime: currentTime - interpolation_amount,
          flMaxExtrapolationAmount);
      }
      else
      {
        v11 = this->m_VarHistory.m_firstElement;
        v12 = this->m_VarHistory.m_maxElement;
        v13 = v11 + newer;
        if ( v11 + newer >= v12 )
          v13 -= v12;
        v14 = info.older + v11;
        if ( v14 >= v12 )
          v14 -= v12;
        CInterpolatedVarArrayBase<float,1>::_Interpolate(
          this,
          out: this->m_pValue,
          frac: info.frac,
          start: &this->m_VarHistory.m_pElements[v14],
          end: &this->m_VarHistory.m_pElements[v13]);
      }
    }
    CInterpolatedVarArrayBase<QAngle,1>::RemoveEntriesPreviousTo(
      this,
      flTime: (float)(currentTime - interpolation_amount) - 0.050000001);
  }
  return noMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x1002E7F0
// Name: private: void C_BaseAnimating::TermRopes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::TermRopes(C_BaseAnimating *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *m_pMemory; // ecx
  int v4; // esi
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v5; // ecx

  m_Head = this->m_Ropes.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_Ropes.m_Memory.m_pMemory;
    do
    {
      v4 = (unsigned __int16)m_Head;
      C_BaseEntity::Remove(this: m_pMemory[v4].m_Element);
      m_pMemory = this->m_Ropes.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_Ropes);
  if ( this->m_Ropes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Ropes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Ropes.m_Memory.m_pMemory);
      this->m_Ropes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Ropes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Ropes.m_FirstFree = -1;
  v5 = this->m_Ropes.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Ropes.m_NumAlloced = -65536;
  this->m_Ropes.m_pElements = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002E8A0
// Name: public: bool C_BaseAnimating::InitAsClientRagdoll(struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::InitAsClientRagdoll(
        C_BaseAnimating *this,
        const matrix3x4_t *pDeltaBones0,
        const matrix3x4_t *pDeltaBones1,
        const matrix3x4_t *pCurrentBonePosition,
        float boneDt)
{
  CStudioHdr *m_pStudioHdr; // edi
  const Vector *(__thiscall *WorldAlignMins)(C_BaseEntity *); // edx
  float *v8; // eax
  const Vector *v9; // eax
  const QAngle *v10; // eax
  int v11; // eax
  C_BaseAnimating_vtbl *v12; // eax
  void (__thiscall *UpdatePartitionListEntry)(C_BaseEntity *); // edx
  const Vector *dt; // [esp+0h] [ebp-40h]
  matrix3x4_t parentTransform; // [esp+10h] [ebp-30h] BYREF

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr
    || m_pStudioHdr->m_pStudioHdr == nullptr
    || this->m_pRagdoll != nullptr
    || this->m_builtRagdoll )
  {
    return 0;
  }
  WorldAlignMins = this->WorldAlignMins;
  this->m_builtRagdoll = true;
  v8 = (float *)WorldAlignMins(this);
  this->m_vecPreRagdollMins.x = *v8;
  this->m_vecPreRagdollMins.y = v8[1];
  this->m_vecPreRagdollMins.z = v8[2];
  v9 = this->WorldAlignMaxs(this);
  this->m_vecPreRagdollMaxs.x = v9->x;
  this->m_vecPreRagdollMaxs.y = v9->y;
  this->m_vecPreRagdollMaxs.z = v9->z;
  C_BaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_flPlaybackRate = 1.0;
  this->m_pRagdoll = CreateRagdoll(
                       ent: this,
                       pstudiohdr: m_pStudioHdr,
                       forceVector: &this->m_vecForce,
                       forceBone: this->m_nForceBone,
                       pDeltaBones0,
                       pDeltaBones1,
                       pCurrentBonePosition,
                       dt: boneDt,
                       bFixedConstraints: false);
  C_BaseEntity::DestroyShadow(this);
  C_BaseEntity::CreateShadow(this);
  if ( this->m_bStoreRagdollInfo && this->m_pRagdoll != nullptr )
  {
    dt = this->GetAbsOrigin(this);
    v10 = this->GetAbsAngles(this);
    AngleMatrix(angles: v10, position: dt, matrix: &parentTransform);
    this->SaveRagdollInfo(
      this,
      a2: m_pStudioHdr->m_pStudioHdr->numbones,
      a3: &parentTransform,
      a4: &this->m_BoneAccessor);
  }
  this->m_nRestoreSequence = this->m_nSequence;
  v11 = C_BaseAnimating::SelectWeightedSequence(this, activity: 24);
  C_BaseAnimating::SetSequence(this, nSequence: v11);
  v12 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  this->m_nPrevSequence = this->m_nSequence;
  UpdatePartitionListEntry = v12->UpdatePartitionListEntry;
  this->m_flPlaybackRate = 0.0;
  UpdatePartitionListEntry(this);
  NoteRagdollCreationTick(pRagdoll: this);
  C_BaseEntity::UpdateVisibility(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002EA70
// Name: public: virtual void C_BaseAnimating::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::OnDataChanged(C_BaseAnimating *this, DataUpdateType_t updateType)
{
  IVModelInfoClient_vtbl *v3; // edi
  int ModelIndex; // eax
  int v5; // ebx
  CStudioHdr *m_Index; // eax
  C_BaseEntity *v7; // ecx
  _BYTE *m_iEyeAttachment; // eax
  unsigned int m_Size; // ecx
  bool modelchanged; // [esp+7h] [ebp-1h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( *(_DWORD *)&this->m_bIsBlurred != 0
    && LODWORD(this->m_vecPreRagdollMaxs.z) != this->m_SequenceTransitioner.m_animationQueue.m_Size )
  {
    C_BaseAnimating::SetSequence(
      this: (C_BaseAnimating *)((char *)this - 8),
      nSequence: this->m_SequenceTransitioner.m_animationQueue.m_Size);
    this->m_nPrevSequence = 0;
  }
  if ( *(_DWORD *)&this->m_bIsBlurred == 0 && LODWORD(this->m_flModelScale.m_Value) != -1 )
  {
    C_BaseAnimating::SetSequence(
      this: (C_BaseAnimating *)((char *)this - 8),
      nSequence: LODWORD(this->m_flModelScale.m_Value));
    this->m_flModelScale.m_Value = NAN;
  }
  if ( updateType == DATA_UPDATE_CREATED )
  {
    C_BaseAnimating::UpdateRelevantInterpolatedVars(this: (C_BaseAnimating *)((char *)this - 8));
    this->m_SequenceTransitioner.m_animationQueue.m_Size = -1;
    this->m_flModelScale.m_Value = NAN;
  }
  v3 = modelinfo->__vftable;
  ModelIndex = C_BaseEntity::GetModelIndex(this: (C_BaseAnimating *)((char *)this - 8));
  v5 = (int)v3->GetModel(this: modelinfo, a2: ModelIndex);
  modelchanged = v5 != (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 32))(a1: (char *)this - 4);
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( LODWORD(this->m_prevClientAnimTime) != (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4)
    || *(_DWORD *)&this->m_bBonePolishSetup != (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 148))(a1: (char *)this - 4) )
  {
    C_BaseEntity::OnTranslucencyTypeChanged(this: (C_BaseAnimating *)((char *)this - 8));
  }
  if ( updateType == DATA_UPDATE_CREATED || modelchanged )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 424))(a1: (char *)this - 8);
    if ( this->m_hLightingOrigin.m_Index == 0
      && (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 32))(a1: (char *)this - 4) != 0 )
    {
      C_BaseAnimating::LockStudioHdr(this: (C_BaseAnimating *)((char *)this - 8));
    }
    m_Index = (CStudioHdr *)this->m_hLightingOrigin.m_Index;
    if ( m_Index == nullptr || m_Index->m_pStudioHdr == nullptr )
      m_Index = nullptr;
    if ( C_BaseAnimating::LookupPoseParameter(
           this: (C_BaseAnimating *)((char *)this - 8),
           pstudiohdr: m_Index,
           szName: "mouth") != -1 )
      *(_WORD *)(&this->m_mouth.sndcount + 1) = 1;
  }
  if ( LODWORD(this->m_vecPreRagdollMaxs.z) != this->m_SequenceTransitioner.m_animationQueue.m_Size )
    C_BaseAnimating::OnNewSequence(this: (C_BaseAnimating *)((char *)this - 8), a2: (int)&savedregs);
  if ( modelchanged || LODWORD(this->m_vecPreRagdollMaxs.z) != this->m_SequenceTransitioner.m_animationQueue.m_Size )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this: (C_BaseAnimating *)((char *)this - 8), nChangeFlags: 48);
    this->m_SequenceTransitioner.m_animationQueue.m_Size = LODWORD(this->m_vecPreRagdollMaxs.z);
  }
  if ( LOBYTE(this->m_flOldEncodedController[2]) != 0
    && LOBYTE(this->m_BoneSetupLock.m_depth) != BYTE1(this->m_flOldEncodedController[2]) )
  {
    v7 = (C_BaseAnimating *)((char *)this - 8);
    if ( *(float *)&this->m_SequenceTransitioner.m_animationQueue.m_pElements != 0.0 )
    {
      v7[1].m_VarMap.m_Entries.m_Memory.m_nAllocationCount = 0;
      C_BaseEntity::InvalidatePhysicsRecursive(this: v7, nChangeFlags: 8);
    }
  }
  if ( *(&this->m_nOldRenderMode + 1) == 0 )
    goto LABEL_40;
  if ( LOBYTE(this->m_vecPreRagdollMaxs.y) == 0
    && (cl_disable_ragdolls.m_pParent == nullptr || cl_disable_ragdolls.m_pParent->m_Value.m_nValue == 0) )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 772))(a1: (char *)this - 8);
  }
  if ( *(&this->m_nOldRenderMode + 1) == 0 || LOBYTE(this->m_vecPreRagdollMaxs.y) != 1 )
  {
LABEL_40:
    if ( *(_DWORD *)&this->m_bIsBlurred == 0 )
      goto LABEL_42;
    goto LABEL_41;
  }
  if ( *(_DWORD *)&this->m_bIsBlurred == 0 )
  {
    C_BaseEntity::AddEffects(this: (C_BaseAnimating *)((char *)this - 8), nEffects: 32);
    goto LABEL_40;
  }
LABEL_41:
  if ( *(&this->m_nOldRenderMode + 1) == 0 )
  {
LABEL_44:
    C_BaseAnimating::ClearRagdoll(this: (C_BaseAnimating *)((char *)this - 8));
    goto LABEL_45;
  }
LABEL_42:
  if ( *(&this->m_nOldRenderMode + 1) == 0 && LOBYTE(this->m_vecPreRagdollMaxs.y) != 0 )
    goto LABEL_44;
LABEL_45:
  if ( (this->m_iEFlags & 8) != 0 )
  {
    m_iEyeAttachment = (_BYTE *)this->m_iEyeAttachment;
    if ( m_iEyeAttachment != nullptr && *m_iEyeAttachment != 0 )
    {
      _Msg(a1: "delete ragdoll due to nointerp\n");
      C_BaseEntity::operator delete(pMem: (void *)this->m_iEyeAttachment);
      this->m_iEyeAttachment = 0;
    }
    C_BaseEntity::AddToEntityList(this: (C_BaseAnimating *)((char *)this - 8), listId: ENTITY_LIST_SIMULATE);
  }
  m_Size = this->m_Attachments.m_Size;
  BYTE2(this->m_flGroundSpeed) = m_Size != -1
                              && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Size].m_SerialNumber == HIWORD(m_Size)
                              && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Size].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002ED60
// Name: public: virtual bool CInterpolatedVarArrayBase<float,1>::NoteChanged(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInterpolatedVarArrayBase<float,1>::NoteChanged(
        CInterpolatedVarArrayBase<float,1> *this,
        float flCurrentTime,
        float flChangeTime,
        bool bUpdateLastNetworkedValue)
{
  return CInterpolatedVarArrayBase<float,1>::NoteChanged(
           this,
           flCurrentTime,
           flChangeTime,
           interpolation_amount: this->m_InterpolationAmount,
           bUpdateLastNetworkedValue);
}

//------------------------------------------------------------------------------
// Address: 0x1002EDA0
// Name: public: virtual int CInterpolatedVarArrayBase<float,1>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<float,1>::Interpolate(
        CInterpolatedVarArrayBase<float,1> *this,
        float currentTime)
{
  return CInterpolatedVarArrayBase<float,1>::Interpolate(
           this,
           currentTime,
           interpolation_amount: this->m_InterpolationAmount);
}

//------------------------------------------------------------------------------
// Address: 0x1002F0D0
// Name: public: void C_BaseAnimating::InitModelEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::InitModelEffects(C_BaseAnimating *this)
{
  this->m_bInitModelEffects = true;
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  C_BaseAnimating::TermRopes(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002F0F0
// Name: public: CJiggleBones::CJiggleBones(void)
// Source: json
//------------------------------------------------------------------------------
CJiggleBones *__thiscall CJiggleBones::CJiggleBones(CJiggleBones *this)
{
  CJiggleBones *result; // eax
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // ecx

  result = this;
  this->m_jiggleBoneState.m_Memory.m_pMemory = nullptr;
  this->m_jiggleBoneState.m_Memory.m_nAllocationCount = 0;
  this->m_jiggleBoneState.m_Memory.m_nGrowSize = 0;
  this->m_jiggleBoneState.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_jiggleBoneState.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_jiggleBoneState.m_Memory.m_pMemory;
  *(_DWORD *)&result->m_jiggleBoneState.m_Head = -1;
  result->m_jiggleBoneState.m_NumAlloced = 0;
  result->m_jiggleBoneState.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F120
// Name: public: void C_BaseAnimating::MarkForThreadedBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::MarkForThreadedBoneSetup(C_BaseAnimating *this)
{
  bool v2; // zf
  DWORD CurrentThreadId; // eax
  int m_Size; // eax
  int v5; // esi
  C_BaseAnimating **m_pMemory; // ecx
  int v7; // eax
  C_BaseAnimating **v8; // eax

  if ( g_bDoThreadedBoneSetup
    && !g_bInThreadedBoneSetup
    && this->m_iMostRecentBoneSetupRequest != g_iPreviousBoneCounter
    && !this->IsViewModel(this)
    && this->m_iMostRecentBoneSetupRequest != g_iPreviousBoneCounter )
  {
    v2 = (_S8_1 & 1) == 0;
    this->m_iMostRecentBoneSetupRequest = g_iPreviousBoneCounter;
    if ( v2 )
    {
      _S8_1 |= 1u;
      autoMutex__.m_ownerID = 0;
      autoMutex__.m_depth = 0;
    }
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != autoMutex__.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++autoMutex__.m_depth;
    }
    m_Size = g_PreviousBoneSetups.m_Size;
    v5 = g_PreviousBoneSetups.m_Size;
    if ( g_PreviousBoneSetups.m_Size + 1 > g_PreviousBoneSetups.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PreviousBoneSetups,
        num: g_PreviousBoneSetups.m_Size - g_PreviousBoneSetups.m_Memory.m_nAllocationCount + 1);
      m_Size = g_PreviousBoneSetups.m_Size;
    }
    m_pMemory = g_PreviousBoneSetups.m_Memory.m_pMemory;
    g_PreviousBoneSetups.m_Size = m_Size + 1;
    v7 = m_Size - v5;
    g_PreviousBoneSetups.m_pElements = g_PreviousBoneSetups.m_Memory.m_pMemory;
    if ( v7 > 0 )
    {
      _V_memmove(
        dest: &g_PreviousBoneSetups.m_Memory.m_pMemory[v5 + 1],
        src: &g_PreviousBoneSetups.m_Memory.m_pMemory[v5],
        count: 4 * v7);
      m_pMemory = g_PreviousBoneSetups.m_Memory.m_pMemory;
    }
    v8 = &m_pMemory[v5];
    if ( v8 != nullptr )
      *v8 = this;
    if ( --autoMutex__.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F260
// Name: public: virtual bool C_BaseAnimating::SetupBones(class matrix3x4a_t __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge C_BaseAnimating::SetupBones@<al>(
        C_BaseAnimating *this@<ecx>,
        int a2@<ebp>,
        matrix3x4a_t *pBoneToWorldOut,
        int nMaxBones,
        C_BaseAnimating *boneMask,
        float currentTime)
{
  void *v6; // esp
  const char *v8; // eax
  bool v9; // zf
  bool bAllowBoneAccessForViewModels; // al
  const char *Classname; // eax
  DWORD v12; // eax
  int v13; // ecx
  int *v14; // edi
  matrix3x4_t *v15; // eax
  volatile signed __int32 v16; // edx
  const Vector *v17; // eax
  int *v18; // ecx
  matrix3x4_t *CurrentThreadId; // eax
  int m_WritableBones; // ecx
  const Vector *v21; // edx
  int v22; // ecx
  int v23; // eax
  unsigned int v24; // edi
  int v25; // edx
  double (__thiscall *v26)(char *); // eax
  _DWORD *v27; // eax
  int v28; // edx
  CStudioHdr *v29; // eax
  C_BaseAnimating_vtbl *v30; // edx
  const Vector *v31; // eax
  C_BaseAnimating_vtbl *v32; // edx
  const QAngle *v33; // eax
  int v34; // ecx
  matrix3x4a_t *v35; // eax
  const studiohdr_t *v36; // ecx
  int OnDelete; // eax
  int v38; // edx
  char *v39; // eax
  int v40; // ecx
  int (__thiscall *v41)(char *); // eax
  float *v42; // eax
  IVDebugOverlay_vtbl *v43; // edi
  int v44; // eax
  CIKContext *v45; // eax
  CIKContext *v46; // eax
  void (__thiscall *SetRefEHandle)(struct IClientUnknown *, const CBaseHandle *); // eax
  const Vector *v48; // eax
  C_BaseAnimating_vtbl *v49; // edx
  const QAngle *v50; // eax
  int m_nGrowSize; // eax
  volatile __int32 *v52; // eax
  volatile __int32 *v54; // eax
  volatile __int32 *v55; // eax
  Quaternion v56[256]; // [esp+58h] [ebp-1CACh] BYREF
  Vector v57[256]; // [esp+1058h] [ebp-CACh] BYREF
  matrix3x4_t v58; // [esp+1C58h] [ebp-ACh] BYREF
  CBoneBitList v59; // [esp+1C88h] [ebp-7Ch] BYREF
  float v60[3]; // [esp+1CB4h] [ebp-50h] BYREF
  float v61[3]; // [esp+1CC0h] [ebp-44h] BYREF
  float v62[3]; // [esp+1CCCh] [ebp-38h] BYREF
  float v63; // [esp+1CD8h] [ebp-2Ch]
  float v64; // [esp+1CDCh] [ebp-28h]
  float v65; // [esp+1CE0h] [ebp-24h]
  const Vector *p_m_WritableBones; // [esp+1CE4h] [ebp-20h]
  float flTime; // [esp+1CE8h] [ebp-1Ch]
  IClientRenderable *name; // [esp+1CECh] [ebp-18h]
  matrix3x4a_t *m_pElements; // [esp+1CF0h] [ebp-14h]
  vgui::PropertyPage *v70; // [esp+1CF4h] [ebp-10h]
  int v71; // [esp+1CF8h] [ebp-Ch]
  void *v72; // [esp+1CFCh] [ebp-8h]
  void *retaddr; // [esp+1D04h] [ebp+0h]
  int v74; // [esp+1D10h] [ebp+Ch]

  v71 = a2;
  v72 = retaddr;
  v6 = alloca(7336);
  v8 = "Client_Animation";
  if ( g_bInThreadedBoneSetup )
    v8 = "Client_Animation_Threaded";
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseAnimating::SetupBones",
    a3: 0,
    a4: v8,
    a5: false,
    a6: 4);
  if ( pBoneToWorldOut != nullptr && (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    v9 = (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 844))(a1: (char *)this - 4) == 0;
    bAllowBoneAccessForViewModels = g_BoneAcessBase.bAllowBoneAccessForViewModels;
    if ( v9 )
      bAllowBoneAccessForViewModels = g_BoneAcessBase.bAllowBoneAccessForNormalModels;
    if ( !bAllowBoneAccessForViewModels && *(float *)gpGlobals.m_Index >= (float)(lastWarning + 1.0) )
    {
      Classname = C_BaseEntity::GetClassname(this: (C_BaseAnimating *)((char *)this - 4));
      DevMsgRT(pMsg: "*** ERROR: Bone access not allowed (entity %i:%s)\n", HIDWORD(this->m_pfnTouch), Classname);
      lastWarning = *(float *)gpGlobals.m_Index;
    }
  }
  if ( *(_DWORD *)&this->m_builtRagdoll == -1 )
    goto LABEL_106;
  if ( boneMask == (C_BaseAnimating *)-1 )
    boneMask = this->m_pNextForThreadedBoneSetup;
  if ( cl_SetupAllBones.m_pParent != nullptr && cl_SetupAllBones.m_pParent->m_Value.m_nValue != 0 )
    boneMask = (C_BaseAnimating *)((unsigned int)boneMask | 0x7FF00);
  if ( C_BaseEntity::IsToolRecording(this: (C_BaseAnimating *)((char *)this - 4)) )
    boneMask = (C_BaseAnimating *)((unsigned int)boneMask | 0x7FF00);
  if ( !g_bInThreadedBoneSetup )
  {
    p_m_WritableBones = (const Vector *)&this->m_BoneAccessor.m_WritableBones;
    CurrentThreadId = (matrix3x4_t *)GetCurrentThreadId();
    m_WritableBones = this->m_BoneAccessor.m_WritableBones;
    m_pElements = (matrix3x4a_t *)CurrentThreadId;
    if ( CurrentThreadId == (matrix3x4_t *)m_WritableBones
      || (v18 = &this->m_BoneAccessor.m_WritableBones,
          _InterlockedCompareExchange(&this->m_BoneAccessor.m_WritableBones, (signed __int32)CurrentThreadId, 0) == 0) )
    {
      ++this->m_BoneSetupLock.m_ownerID;
      goto LABEL_31;
    }
    _mm_pause();
    v21 = (const Vector *)m_pElements;
    *(float *)&m_pElements = 0.0;
    name = (IClientRenderable *)v21;
    goto LABEL_30;
  }
  v12 = GetCurrentThreadId();
  v13 = this->m_BoneAccessor.m_WritableBones;
  v14 = &this->m_BoneAccessor.m_WritableBones;
  p_m_WritableBones = (const Vector *)&this->m_BoneAccessor.m_WritableBones;
  if ( v12 != v13 && _InterlockedCompareExchange(v14, v12, 0) != 0 )
  {
    v15 = (matrix3x4_t *)GetCurrentThreadId();
    v16 = *v14;
    m_pElements = (matrix3x4a_t *)v15;
    if ( v15 == (matrix3x4_t *)v16 || _InterlockedCompareExchange(v14, (signed __int32)v15, 0) == 0 )
    {
      ++this->m_BoneSetupLock.m_ownerID;
      goto LABEL_31;
    }
    _mm_pause();
    v17 = (const Vector *)m_pElements;
    *(float *)&m_pElements = 0.0;
    name = (IClientRenderable *)v17;
    v18 = &this->m_BoneAccessor.m_WritableBones;
LABEL_30:
    CThreadFastMutex::Lock(a1: v18, a2: name, a3: m_pElements);
    goto LABEL_31;
  }
  ++this->m_BoneSetupLock.m_ownerID;
LABEL_31:
  v22 = 0;
  v23 = 1024;
  while ( 1 )
  {
    v24 = (unsigned int)boneMask;
    if ( (v23 & (unsigned int)boneMask) != 0 )
      break;
    ++v22;
    v23 *= 2;
    if ( v22 >= 8 )
      goto LABEL_38;
  }
  v25 = 8 - v22;
  do
  {
    v24 |= v23;
    v23 *= 2;
    --v25;
  }
  while ( v25 != 0 );
  boneMask = (C_BaseAnimating *)v24;
LABEL_38:
  if ( C_BaseEntity::GetPredictable(this: (C_BaseAnimating *)((char *)this - 4))
    && prediction->InPrediction(this: prediction) )
  {
    currentTime = CPrediction::GetSavedTime(this: prediction);
  }
  if ( this->m_nForceBone != g_iModelBoneCounter )
  {
    v26 = *(double (__thiscall **)(char *))(*((_DWORD *)this - 1) + 880);
    m_pElements = this->m_CachedBoneData.m_pElements;
    if ( v26(a1: (char *)this - 4) >= *(float *)&m_pElements || *(float *)&m_pElements > currentTime )
    {
      this->m_BoneAccessor.m_pBones = nullptr;
      this->m_BoneAccessor.m_ReadableBones = 0;
      *(float *)&this->m_CachedBoneData.m_pElements = currentTime;
    }
    this->m_pNextForThreadedBoneSetup = (C_BaseAnimating *)this->m_iPrevBoneMask;
    this->m_iPrevBoneMask = 0;
    if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: (C_BaseAnimating *)((char *)this - 4));
    v27 = *(_DWORD **)&this->m_nOldMuzzleFlashParity;
    if ( v27 != nullptr && *v27 != 0 )
    {
      v27[22] = 0;
      v27[23] = 0;
      v27[24] = 0;
    }
  }
  C_BaseAnimating::MarkForThreadedBoneSetup(this: (C_BaseAnimating *)((char *)this - 4));
  this->m_iPrevBoneMask |= (unsigned int)boneMask;
  v28 = (int)this->m_BoneAccessor.m_pBones & (unsigned int)boneMask;
  this->m_nForceBone = g_iModelBoneCounter;
  if ( (C_BaseAnimating *)v28 != boneMask )
  {
    if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: (C_BaseAnimating *)((char *)this - 4));
    v29 = *(CStudioHdr **)&this->m_nOldMuzzleFlashParity;
    v70 = (vgui::PropertyPage *)v29;
    if ( v29 != nullptr && v29->m_pStudioHdr != nullptr && CStudioHdr::SequencesAvailable(this: v29) )
    {
      v30 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      *(float *)&m_pElements = COERCE_FLOAT(&v58);
      v31 = (const Vector *)((int (__thiscall *)(C_BaseAnimating *))v30->SetRefEHandle)(a1: this);
      v32 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      name = (IClientRenderable *)v31;
      v33 = (const QAngle *)v32->GetRefEHandle(this);
      AngleMatrix(angles: v33, position: (const Vector *)name, matrix: m_pElements);
      v34 = (int)this->m_pNextForThreadedBoneSetup | (unsigned int)boneMask;
      flTime = *(float *)&this->m_BoneAccessor.m_pBones;
      v35 = (matrix3x4a_t *)(v34 | LODWORD(flTime));
      m_pElements = (matrix3x4a_t *)(v34 | LODWORD(flTime));
      this->m_BoneAccessor.m_ReadableBones = v34 | LODWORD(flTime);
      this->m_BoneAccessor.m_pBones = v35;
      v74 = v34;
      if ( r_sequence_debug.m_pParent != nullptr && r_sequence_debug.m_pParent->m_Value.m_nValue == -1 )
      {
        ((void (__thiscall *)(C_BaseAnimating *, float *, float *))this->GetPredDescMap)(a1: this, a2: v61, a3: v62);
        v36 = (const studiohdr_t *)v70->__vftable;
        OnDelete = (int)v70->OnDelete;
        if ( OnDelete != 0
          && (v38 = *(_DWORD *)&v36->name[OnDelete + 8], v39 = (char *)v36 + OnDelete, v38 != 0)
          && &v39[v38] != nullptr )
        {
          v40 = *((_DWORD *)v39 + 5);
          if ( v40 != 0 )
            name = (IClientRenderable *)&v39[v40];
          else
            name = nullptr;
        }
        else
        {
          name = (IClientRenderable *)v36->name;
        }
        v41 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40);
        v63 = (float)(v62[0] + v61[0]) * 0.5;
        v64 = (float)(v62[1] + v61[1]) * 0.5;
        v65 = (float)(v62[2] + v61[2]) * 0.5;
        v42 = (float *)v41(a1: (char *)this - 4);
        v60[0] = *v42 + v63;
        v60[1] = v42[1] + v64;
        v60[2] = v42[2] + v65;
        v43 = debugoverlay->__vftable;
        v44 = ((int (__thiscall *)(IClientRenderable *, IClientRenderable *))this->GetBody)(
                a1: &this->IClientRenderable,
                a2: name);
        ((void (__cdecl *)(IVDebugOverlay *, float *, _DWORD, _DWORD, const char *, int))v43->AddTextOverlay)(
          a1: debugoverlay,
          a2: v60,
          a3: 0,
          a4: 0,
          a5: "%d:%s",
          a6: v44);
      }
      if ( ((int)v70->OnMove & 0x10) != 0 )
      {
        MatrixCopy(in: &v58, out: (matrix3x4_t *)this->m_BoneAccessor.m_pAnimating);
      }
      else
      {
        if ( !g_bInThreadedBoneSetup )
        {
          m_pElements = (matrix3x4a_t *)((char *)this - 4);
          C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v70);
        }
        LODWORD(this->m_flProxyRandomValue) |= 8u;
        if ( *(_DWORD *)&this->m_nMuzzleFlashParity != 0 )
          goto LABEL_81;
        if ( (int)v70->SetPaintBackgroundEnabled > 0 && (this->index & 2) == 0 )
        {
          v45 = (CIKContext *)MemAlloc_Alloc(nSize: 0x1070u);
          if ( v45 != nullptr )
            v46 = CIKContext::CIKContext(this: v45);
          else
            v46 = nullptr;
          *(_DWORD *)&this->m_nMuzzleFlashParity = v46;
        }
        if ( *(_DWORD *)&this->m_nMuzzleFlashParity != 0 )
        {
LABEL_81:
          if ( C_BaseEntity::Teleported(this: (C_BaseAnimating *)((char *)this - 4))
            || (*(_DWORD *)&this->m_nWaterType & 8) != 0 )
          {
            CIKContext::ClearTargets(this: *(CIKContext **)&this->m_nMuzzleFlashParity);
          }
          SetRefEHandle = this->SetRefEHandle;
          name = *(IClientRenderable **)(gpGlobals.m_Index + 4);
          flTime = currentTime;
          v48 = (const Vector *)((int (__thiscall *)(C_BaseAnimating *))SetRefEHandle)(a1: this);
          v49 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
          p_m_WritableBones = v48;
          v50 = (const QAngle *)v49->GetRefEHandle(this);
          CIKContext::Init(
            this: *(CIKContext **)&this->m_nMuzzleFlashParity,
            pStudioHdr: (const CStudioHdr *)v70,
            angles: v50,
            pos: p_m_WritableBones,
            flTime,
            iFramecounter: (int)name,
            boneMask: (int)m_pElements);
        }
        if ( this == (C_BaseAnimating *)4 )
          name = nullptr;
        else
          name = &this->IClientRenderable;
        ((void (__thiscall *)(IPoseDebugger *, IClientRenderable *, vgui::PropertyPage *, vgui::PropertyPage *))g_pPoseDebugger->StartBlending)(
          a1: g_pPoseDebugger,
          a2: name,
          a3: v70,
          a4: v70);
        (*(void (__thiscall **)(char *, matrix3x4a_t *, Vector *, Quaternion *, _DWORD, matrix3x4a_t *))(*((_DWORD *)this - 1) + 756))(
          a1: (char *)this - 4,
          a2: m_pElements,
          a3: v57,
          a4: v56,
          a5: LODWORD(currentTime),
          a6: m_pElements);
        v9 = *(_DWORD *)&this->m_nMuzzleFlashParity == 0;
        memset(&v59, 0, sizeof(v59));
        if ( !v9 && (*((_DWORD *)&this->m_bIsBlurred + 1) == 0 || BYTE1(this->m_VisibilityBits.m_Ints[0]) == 0) )
        {
          (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 1) + 708))(
            a1: (char *)this - 4,
            a2: LODWORD(currentTime));
          CIKContext::UpdateTargets(
            this: *(CIKContext **)&this->m_nMuzzleFlashParity,
            pos: v57,
            q: v56,
            boneToWorld: (matrix3x4a_t *)this->m_BoneAccessor.m_pAnimating,
            boneComputed: &v59);
          (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 1) + 712))(
            a1: (char *)this - 4,
            a2: LODWORD(currentTime));
          CIKContext::SolveDependencies(
            this: *(CIKContext **)&this->m_nMuzzleFlashParity,
            pos: v57,
            q: v56,
            boneToWorld: (matrix3x4a_t *)this->m_BoneAccessor.m_pAnimating,
            boneComputed: &v59);
        }
        (*(void (__thiscall **)(char *, CBoneBitList *, Vector *, Quaternion *, matrix3x4_t *, matrix3x4a_t *, CBoneBitList *))(*((_DWORD *)this - 1) + 700))(
          a1: (char *)this - 4,
          a2: &v59,
          a3: v57,
          a4: v56,
          a5: &v58,
          a6: m_pElements,
          a7: &v59);
        if ( enable_skeleton_draw.m_pParent != nullptr && enable_skeleton_draw.m_pParent->m_Value.m_nValue != 0 )
          C_BaseAnimating::DrawSkeleton(
            this: (C_BaseAnimating *)((char *)this - 4),
            pHdr: (const CStudioHdr *)v70,
            iBoneMask: v74);
        LODWORD(this->m_flProxyRandomValue) &= ~8u;
        (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 728))(a1: (char *)this - 4);
      }
      if ( (LOWORD(flTime) & 0x200) == 0 && (v74 & 0x200) != 0 )
        C_BaseAnimating::SetupBones_AttachmentHelper(
          this: (C_BaseAnimating *)((char *)this - 4),
          hdr: (CStudioHdr *)v70);
      goto LABEL_98;
    }
    v54 = (volatile __int32 *)p_m_WritableBones;
    v9 = LODWORD(p_m_WritableBones->y)-- == 1;
    if ( v9 )
      _InterlockedExchange(v54, 0);
LABEL_106:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
LABEL_98:
  if ( pBoneToWorldOut == nullptr )
  {
LABEL_101:
    v52 = (volatile __int32 *)p_m_WritableBones;
    v9 = LODWORD(p_m_WritableBones->y)-- == 1;
    if ( v9 )
      _InterlockedExchange(v52, 0);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  m_nGrowSize = this->m_CachedBoneData.m_Memory.m_nGrowSize;
  if ( nMaxBones >= m_nGrowSize )
  {
    memcpy(
      dst: (unsigned __int8 *)pBoneToWorldOut,
      src: *(unsigned __int8 **)&this->m_bForceRTTShadows,
      count: 48 * m_nGrowSize);
    goto LABEL_101;
  }
  m_pElements = (matrix3x4a_t *)this->m_CachedBoneData.m_Memory.m_nGrowSize;
  _Warning(a1: "SetupBones: invalid bone array size (%d - needs %d)\n", a2: nMaxBones);
  v55 = (volatile __int32 *)p_m_WritableBones;
  v9 = LODWORD(p_m_WritableBones->y)-- == 1;
  if ( v9 )
    _InterlockedExchange(v55, 0);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA00
// Name: public: static void C_BaseAnimating::PushAllowBoneAccess(bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseAnimating::PushAllowBoneAccess(
        bool bAllowForNormalModels,
        bool bAllowForViewModels,
        const char *tagPush)
{
  BoneAccess save; // [esp+0h] [ebp-8h] BYREF

  if ( (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    save = g_BoneAcessBase;
    CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_BoneAccessStack,
      elem: g_BoneAccessStack.m_Size,
      src: (const vgui::PropertySheet::Page_t *)&save);
    g_BoneAcessBase.bAllowBoneAccessForNormalModels = bAllowForNormalModels;
    g_BoneAcessBase.bAllowBoneAccessForViewModels = bAllowForViewModels;
    g_BoneAcessBase.tag = tagPush;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FA60
// Name: public: C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(bool,bool)
// Source: json
//------------------------------------------------------------------------------
C_BaseAnimating::AutoAllowBoneAccess *__thiscall C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
        C_BaseAnimating::AutoAllowBoneAccess *this,
        bool bAllowForNormalModels,
        bool bAllowForViewModels)
{
  vgui::PropertySheet::Page_t src; // [esp+4h] [ebp-8h] BYREF

  if ( (unsigned __int8)_ThreadInMainThread(a1: this) != 0 )
  {
    src = (vgui::PropertySheet::Page_t)g_BoneAcessBase;
    CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_BoneAccessStack,
      elem: g_BoneAccessStack.m_Size,
      &src);
    g_BoneAcessBase.bAllowBoneAccessForNormalModels = bAllowForNormalModels;
    g_BoneAcessBase.bAllowBoneAccessForViewModels = bAllowForViewModels;
    g_BoneAcessBase.tag = (const char *)1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002FAC0
// Name: void MaterialFootstepSound(class C_BaseAnimating __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialFootstepSound(C_BaseAnimating *pEnt, bool bLeftFoot, float flVolume)
{
  int (__thiscall *LookupAttachment)(IClientRenderable *, const char *); // edx
  int v4; // eax
  surfacedata_t *v5; // esi
  const char *v6; // eax
  int (__thiscall *entindex)(IClientNetworkable *); // edx
  int v8; // eax
  CGameTrace tr; // [esp+Ch] [ebp-E0h] BYREF
  QAngle angles; // [esp+60h] [ebp-8Ch] BYREF
  CPASAttenuationFilter filter; // [esp+6Ch] [ebp-80h] BYREF
  EmitSound_t params; // [esp+8Ch] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+D4h] [ebp-18h] BYREF
  Vector traceStart; // [esp+E0h] [ebp-Ch] BYREF

  LookupAttachment = pEnt->LookupAttachment;
  if ( bLeftFoot )
    v4 = ((int (__stdcall *)(const char *))LookupAttachment)(a1: "LeftFoot");
  else
    v4 = ((int (__stdcall *)(const char *))LookupAttachment)(a1: "RightFoot");
  if ( v4 != -1 )
  {
    pEnt->GetAttachment_2(this: &pEnt->IClientRenderable, a2: v4, a3: &traceStart, a4: &angles);
    vecAbsEnd.x = traceStart.x;
    vecAbsEnd.y = traceStart.y;
    vecAbsEnd.z = traceStart.z - 48.0;
    UTIL_TraceLine(vecAbsStart: &traceStart, &vecAbsEnd, mask: 0x600400Bu, ignore: pEnt, collisionGroup: 0, ptr: &tr);
    if ( tr.fraction < 1.0 && tr.m_pEnt != nullptr )
    {
      v5 = physprops->GetSurfaceData(this: physprops, a2: tr.surface.surfaceProps);
      if ( v5 != nullptr )
      {
        EmitSound_t::EmitSound_t(this: &params);
        if ( bLeftFoot )
          v6 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v5->sounds.runStepLeft);
        else
          v6 = (const char *)((int (__stdcall *)(_DWORD))physprops->GetString)(a1: v5->sounds.runStepRight);
        params.m_pSoundName = v6;
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: pEnt, attenuation: *(float *)&v6);
        entindex = pEnt->entindex;
        params.m_bWarnOnDirectWaveReference = true;
        params.m_flVolume = flVolume;
        v8 = entindex(this: &pEnt->IClientNetworkable);
        C_BaseEntity::EmitSound(&filter, iEntIndex: v8, &params);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FC10
// Name: public: virtual void C_BaseAnimating::FireEvent(class Vector const __near &,class QAngle const __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::FireEvent(
        C_BaseAnimating *this,
        const Vector *origin,
        const QAngle *angles,
        int event,
        const char *options)
{
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // ebx
  ParticleAttachment_t AttachTypeFromString; // edi
  int v10; // eax
  const char *v11; // edi
  int v12; // eax
  const char *v13; // edi
  int v14; // eax
  const char *v15; // edi
  const char *v16; // edi
  const char *v17; // edi
  int v18; // eax
  int v19; // edi
  int Effect; // eax
  int v21; // eax
  int BodygroupByName; // eax
  int v23; // eax
  const char *v24; // edi
  int v25; // edi
  int v26; // eax
  const char *v27; // edi
  const char *v28; // edi
  float flVolume; // xmm0_4
  int v30; // [esp+0h] [ebp-264h]
  int SoundSourceIndex; // [esp+0h] [ebp-264h]
  const Vector *v32; // [esp+8h] [ebp-25Ch]
  QAngle attachAngles; // [esp+20h] [ebp-244h] BYREF
  char pSoundName[256]; // [esp+2Ch] [ebp-238h] BYREF
  CLocalPlayerFilter filter; // [esp+12Ch] [ebp-138h] BYREF
  char szBodygroupName[256]; // [esp+14Ch] [ebp-118h] BYREF
  Vector attachOrigin; // [esp+24Ch] [ebp-18h] BYREF
  Vector vel; // [esp+258h] [ebp-Ch] BYREF
  CNewParticleEffect *iControlPoint; // [esp+274h] [ebp+10h]
  int iControlPointa; // [esp+274h] [ebp+10h]
  const char *iAttachType; // [esp+278h] [ebp+14h]
  ParticleAttachment_t iAttachTypea; // [esp+278h] [ebp+14h]
  ParticleAttachment_t iAttachTypeb; // [esp+278h] [ebp+14h]

  if ( event <= 5004 )
  {
    if ( event < 5001 )
    {
      switch ( event )
      {
        case 15:
          if ( !this->m_bSuppressAnimSounds )
          {
            CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
            if ( this->m_Attachments.m_Size <= 0 )
            {
              v32 = this->GetAbsOrigin(this);
              SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this);
              C_BaseEntity::EmitSound(
                &filter,
                iEntIndex: SoundSourceIndex,
                soundname: options,
                pOrigin: v32,
                soundtime: 0.0,
                duration: nullptr);
            }
            else
            {
              this->GetAttachment_2(this: &this->IClientRenderable, a2: 1, a3: &attachOrigin, a4: &attachAngles);
              v30 = C_BaseEntity::GetSoundSourceIndex(this);
              C_BaseEntity::EmitSound(
                &filter,
                iEntIndex: v30,
                soundname: options,
                pOrigin: &attachOrigin,
                soundtime: 0.0,
                duration: nullptr);
            }
            C_RecipientFilter::~C_RecipientFilter(this: &filter);
          }
          return;
        case 17:
          v21 = C_BaseEntity::GetSoundSourceIndex(this);
          C_BaseEntity::StopSound(iEntIndex: v21, soundname: options);
          return;
        case 20:
          goto $LN10_1;
        case 21:
          this->DispatchMuzzleEffect(this, a2: options, a3: true);
          return;
        case 22:
          this->DispatchMuzzleEffect(this, a2: options, a3: false);
          return;
        case 32:
          v6 = nexttoken(token: szBodygroupName, str: options, sep: 32);
          v7 = this->ModifyEventParticles(this, a2: szBodygroupName);
          V_strncpy(pDest: pSoundName, pSrc: v7, maxLen: 256);
          v8 = nexttoken(token: szBodygroupName, str: v6, sep: 32);
          AttachTypeFromString = GetAttachTypeFromString(pszString: szBodygroupName);
          if ( AttachTypeFromString == -1 )
            goto LABEL_18;
          iAttachType = nexttoken(token: szBodygroupName, str: v8, sep: 32);
          v10 = atoi(nptr: szBodygroupName);
          if ( szBodygroupName[0] != 48 && v10 == 0 )
          {
            v10 = this->LookupAttachment(this: &this->IClientRenderable, a2: szBodygroupName);
            if ( v10 == -1 )
              goto LABEL_22;
          }
          iControlPoint = CParticleProperty::Create(
                            this: &this->m_Particles,
                            pszParticleName: pSoundName,
                            iAttachType: AttachTypeFromString,
                            iAttachmentPoint: v10,
                            vecOriginOffset: vec3_origin,
                            matOffset: nullptr);
          v11 = nexttoken(token: szBodygroupName, str: iAttachType, sep: 32);
          if ( v11 != nullptr )
          {
            iAttachTypea = GetAttachTypeFromString(pszString: szBodygroupName);
            if ( iAttachTypea == -1 )
            {
LABEL_18:
              _Warning(
                a1: "Invalid attach type specified for particle effect anim event. Trying to spawn effect '%s' with attach type of '%s'\n",
                a2: pSoundName);
            }
            else
            {
              nexttoken(token: szBodygroupName, str: v11, sep: 32);
              v12 = atoi(nptr: szBodygroupName);
              if ( szBodygroupName[0] == 48
                || v12 != 0
                || this->LookupAttachment(this: &this->IClientRenderable, a2: szBodygroupName) != -1 )
              {
                CParticleProperty::AddControlPoint(
                  this: &this->m_Particles,
                  pEffect: iControlPoint,
                  iPoint: 1,
                  pEntity: this,
                  iAttachType: iAttachTypea,
                  pszAttachmentName: szBodygroupName,
                  vecOriginOffset: vec3_origin,
                  matOffset: nullptr);
              }
              else
              {
LABEL_22:
                _Warning(
                  a1: "Failed to find attachment point specified for particle effect anim event. Trying to spawn effect '%s' "
                  "on attachment named '%s'\n",
                  a2: pSoundName);
              }
            }
          }
          break;
        case 33:
          v13 = nexttoken(token: pSoundName, str: options, sep: 32);
          V_strncpy(pDest: szBodygroupName, pSrc: pSoundName, maxLen: 256);
          nexttoken(token: pSoundName, str: v13, sep: 32);
          v14 = _V_stricmp(s1: pSoundName, s2: "instantly");
          CParticleProperty::StopParticlesNamed(
            this: &this->m_Particles,
            pszEffectName: szBodygroupName,
            bForceRemoveInstantly: v14 == 0,
            nSplitScreenPlayerSlot: -1);
          return;
        case 34:
          v15 = nexttoken(token: szBodygroupName, str: options, sep: 32);
          V_strncpy(pDest: pSoundName, pSrc: szBodygroupName, maxLen: 256);
          v16 = nexttoken(token: szBodygroupName, str: v15, sep: 32);
          iControlPointa = atoi(nptr: szBodygroupName);
          v17 = nexttoken(token: szBodygroupName, str: v16, sep: 32);
          iAttachTypeb = GetAttachTypeFromString(pszString: szBodygroupName);
          if ( iAttachTypeb == -1 )
            goto LABEL_18;
          nexttoken(token: szBodygroupName, str: v17, sep: 32);
          v18 = atoi(nptr: szBodygroupName);
          v19 = v18;
          if ( szBodygroupName[0] != 48 && v18 == 0 )
          {
            v19 = this->LookupAttachment(this: &this->IClientRenderable, a2: szBodygroupName);
            if ( v19 == -1 )
              goto LABEL_22;
          }
          Effect = CParticleProperty::FindEffect(this: &this->m_Particles, pEffectName: pSoundName);
          if ( Effect == -1 )
            _Warning(
              a1: "Failed to find specified particle effect. Trying to add CP to '%s' on attachment named '%s'\n",
              a2: pSoundName);
          else
            CParticleProperty::AddControlPoint(
              this: &this->m_Particles,
              iEffectIndex: Effect,
              iPoint: iControlPointa,
              pEntity: this,
              iAttachType: iAttachTypeb,
              iAttachmentPoint: v19,
              vecOriginOffset: vec3_origin,
              matOffset: nullptr);
          break;
        case 37:
          BodygroupByName = C_BaseAnimating::FindBodygroupByName(this, name: options);
          if ( BodygroupByName >= 0 )
            C_BaseAnimating::SetBodygroup(this, iGroup: BodygroupByName, iValue: 1);
          return;
        case 38:
          v23 = C_BaseAnimating::FindBodygroupByName(this, name: options);
          if ( v23 >= 0 )
            C_BaseAnimating::SetBodygroup(this, iGroup: v23, iValue: 0);
          return;
        case 39:
          v24 = nexttoken(token: pSoundName, str: options, sep: 32);
          V_strncpy(pDest: szBodygroupName, pSrc: pSoundName, maxLen: 256);
          nexttoken(token: pSoundName, str: v24, sep: 32);
          v25 = atoi(nptr: pSoundName);
          v26 = C_BaseAnimating::FindBodygroupByName(this, name: szBodygroupName);
          if ( v26 >= 0 )
            C_BaseAnimating::SetBodygroup(this, iGroup: v26, iValue: v25);
          return;
        default:
          return;
      }
      return;
    }
$LN10_1:
    this->FireObsoleteEvent(this, a2: origin, a3: angles, a4: event, a5: options);
    return;
  }
  if ( event > 6004 )
  {
    if ( event > 9001 )
    {
      switch ( event )
      {
        case 9011:
        case 9021:
        case 9031:
        case 9041:
        case 9051:
        case 9061:
        case 9071:
        case 9081:
        case 9091:
          goto $LN10_1;
        default:
          return;
      }
    }
    else
    {
      if ( event == 9001 )
        goto $LN10_1;
      switch ( event )
      {
        case 6005:
          v28 = options;
          if ( options == nullptr || *options == 0 )
            v28 = "NPC_CombineS";
          this->EstimateAbsVelocity(this, a2: &vel);
          if ( (float)((float)(vel.y * vel.y) + (float)(vel.x * vel.x)) <= 22500.0 )
            V_snprintf(pDest: pSoundName, maxLen: 256, pFormat: "%s.FootstepRight", v28);
          else
            V_snprintf(pDest: pSoundName, maxLen: 256, pFormat: "%s.RunFootstepRight", v28);
          goto LABEL_60;
        case 6006:
          flVolume = 0.5;
          goto LABEL_71;
        case 6007:
          MaterialFootstepSound(pEnt: this, bLeftFoot: false, flVolume: 0.5);
          return;
        case 6008:
          flVolume = 1.0;
LABEL_71:
          MaterialFootstepSound(pEnt: this, bLeftFoot: true, flVolume);
          break;
        case 6009:
          MaterialFootstepSound(pEnt: this, bLeftFoot: false, flVolume: 1.0);
          break;
        default:
          return;
      }
    }
  }
  else if ( event == 6004 )
  {
    v27 = options;
    if ( options == nullptr || *options == 0 )
      v27 = "NPC_CombineS";
    this->EstimateAbsVelocity(this, a2: &vel);
    if ( (float)((float)(vel.y * vel.y) + (float)(vel.x * vel.x)) <= 22500.0 )
      V_snprintf(pDest: pSoundName, maxLen: 256, pFormat: "%s.FootstepLeft", v27);
    else
      V_snprintf(pDest: pSoundName, maxLen: 256, pFormat: "%s.RunFootstepLeft", v27);
LABEL_60:
    C_BaseEntity::EmitSound(this, soundname: pSoundName, soundtime: 0.0, duration: nullptr);
  }
  else
  {
    if ( event <= 5023 )
    {
      if ( event != 5023 && event != 5011 && event != 5013 && event != 5021 )
        return;
      goto $LN10_1;
    }
    if ( event == 5031 || event == 5033 )
      goto $LN10_1;
    if ( event == 6001 && this->m_Attachments.m_Size > 0 )
      DevWarning(a1: "Unhandled eject brass animevent\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030530
// Name: public: void C_BaseAnimating::SetModelScale(float,enum ModelScaleType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::SetModelScale(C_BaseAnimating *this, float scale, ModelScaleType_t scaleType)
{
  float m_Value; // xmm1_4

  m_Value = this->m_flModelScale.m_Value;
  if ( m_Value != scale || scaleType != this->m_ScaleType.m_Value )
  {
    if ( m_Value != scale )
      this->m_flModelScale.m_Value = scale;
    if ( this->m_ScaleType.m_Value != scaleType )
      this->m_ScaleType.m_Value = scaleType;
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100307C0
// Name: public: C_BaseAnimating::C_BaseAnimating(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseAnimating *__thiscall C_BaseAnimating::C_BaseAnimating(C_BaseAnimating *this)
{
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *m_pMemory; // edx
  int v3; // edi
  unsigned int v4; // ecx

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimating_vtbl *)&C_BaseAnimating::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseAnimating::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseAnimating::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseAnimating::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseAnimating::`vftable';
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_pMemory = nullptr;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_nAllocationCount = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_nGrowSize = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_Size = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_pElements = nullptr;
  this->m_flCycle.m_Val = 0.0;
  this->m_BoneAccessor.m_pAnimating = nullptr;
  this->m_BoneAccessor.m_pBones = nullptr;
  this->m_BoneAccessor.m_WritableBones = 0;
  this->m_BoneAccessor.m_ReadableBones = 0;
  this->m_BoneSetupLock.m_ownerID = 0;
  this->m_BoneSetupLock.m_depth = 0;
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
  this->m_Ropes.m_Memory.m_pMemory = nullptr;
  this->m_Ropes.m_Memory.m_nAllocationCount = 0;
  this->m_Ropes.m_Memory.m_nGrowSize = 0;
  this->m_Ropes.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Ropes.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_Ropes.m_Memory.m_pMemory;
  this->m_Ropes.m_NumAlloced = 0;
  *(_DWORD *)&this->m_Ropes.m_Head = -1;
  this->m_Ropes.m_pElements = m_pMemory;
  this->m_iv_flPoseParameter.__vftable = (CInterpolatedVarArray<float,24>_vtbl *)&CInterpolatedVarArrayBase<float,1>::`vftable';
  this->m_iv_flPoseParameter.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_flPoseParameter.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_flPoseParameter.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
    this: &this->m_iv_flPoseParameter.m_VarHistory,
    capSize: 4);
  this->m_iv_flPoseParameter.m_pDebugName = "C_BaseAnimating::m_iv_flPoseParameter";
  this->m_iv_flPoseParameter.m_pValue = nullptr;
  this->m_iv_flPoseParameter.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_flPoseParameter.m_fType = 1;
  this->m_iv_flPoseParameter.m_LastNetworkedTime = 0.0;
  this->m_iv_flPoseParameter.m_LastNetworkedValue = nullptr;
  this->m_iv_flPoseParameter.m_bLooping = nullptr;
  this->m_iv_flPoseParameter.__vftable = (CInterpolatedVarArray<float,24>_vtbl *)&CInterpolatedVarArray<float,24>::`vftable';
  CInterpolatedVarArrayBase<float,1>::SetMaxCount(this: &this->m_iv_flPoseParameter, flCurrentTime: 0.0, newmax: 24);
  this->m_iv_flEncodedController.__vftable = (CInterpolatedVarArray<float,4>_vtbl *)&CInterpolatedVarArrayBase<float,1>::`vftable';
  this->m_iv_flEncodedController.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_flEncodedController.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_flEncodedController.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,1>>::EnsureCapacity(
    this: &this->m_iv_flEncodedController.m_VarHistory,
    capSize: 4);
  this->m_iv_flEncodedController.m_pDebugName = "C_BaseAnimating::m_iv_flEncodedController";
  this->m_iv_flEncodedController.m_pValue = nullptr;
  this->m_iv_flEncodedController.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_flEncodedController.m_fType = 1;
  this->m_iv_flEncodedController.m_LastNetworkedTime = 0.0;
  this->m_iv_flEncodedController.m_LastNetworkedValue = nullptr;
  this->m_iv_flEncodedController.m_bLooping = nullptr;
  this->m_iv_flEncodedController.__vftable = (CInterpolatedVarArray<float,4>_vtbl *)&CInterpolatedVarArray<float,4>::`vftable';
  CInterpolatedVarArrayBase<float,1>::SetMaxCount(this: &this->m_iv_flEncodedController, flCurrentTime: 0.0, newmax: 4);
  this->m_iv_flCycle.__vftable = (CInterpolatedVar<CRangeCheckedVar<float,-2,2,0> >_vtbl *)&CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::`vftable';
  this->m_iv_flCycle.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_flCycle.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_flCycle.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0>>::EnsureCapacity(
    this: &this->m_iv_flCycle.m_VarHistory,
    capSize: 4);
  this->m_iv_flCycle.m_pDebugName = "C_BaseAnimating::m_iv_flCycle";
  this->m_iv_flCycle.m_pValue = nullptr;
  this->m_iv_flCycle.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_flCycle.m_fType = 1;
  this->m_iv_flCycle.m_LastNetworkedTime = 0.0;
  this->m_iv_flCycle.m_LastNetworkedValue = nullptr;
  this->m_iv_flCycle.m_bLooping = nullptr;
  this->m_iv_flCycle.__vftable = (CInterpolatedVar<CRangeCheckedVar<float,-2,2,0> >_vtbl *)&CInterpolatedVar<CRangeCheckedVar<float,-2,2,0>>::`vftable';
  CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::SetMaxCount(
    this: &this->m_iv_flCycle,
    flCurrentTime: 0.0,
    newmax: 1);
  this->m_CachedBoneData.m_Memory.m_pMemory = nullptr;
  this->m_CachedBoneData.m_Memory.m_nAllocationCount = 0;
  this->m_CachedBoneData.m_Memory.m_nGrowSize = 0;
  this->m_CachedBoneData.m_Size = 0;
  this->m_CachedBoneData.m_pElements = nullptr;
  this->m_Attachments.m_Memory.m_pMemory = nullptr;
  this->m_Attachments.m_Memory.m_nAllocationCount = 0;
  this->m_Attachments.m_Memory.m_nGrowSize = 0;
  this->m_Attachments.m_Size = 0;
  this->m_Attachments.m_pElements = nullptr;
  this->m_hLightingOrigin.m_Index = -1;
  this->m_StudioHdrInitLock.m_ownerID = 0;
  this->m_StudioHdrInitLock.m_depth = 0;
  this->m_ejectBrassEffect.m_pPrev = nullptr;
  this->m_ejectBrassEffect.m_pNext = nullptr;
  this->m_ejectBrassEffect.m_pObject = nullptr;
  this->m_iEjectBrassAttachment = -1;
  this->m_vecForce.x = 0.0;
  this->m_vecForce.y = 0.0;
  this->m_vecForce.z = 0.0;
  this->m_nForceBone = -1;
  C_BaseEntity::SetGlobalFadeScale(this, flFadeScale: 1.0);
  if ( this->m_ScaleType.m_Value != HIERARCHICAL_MODEL_SCALE )
    this->m_ScaleType.m_Value = HIERARCHICAL_MODEL_SCALE;
  this->m_ClientSideAnimationListHandle = -1;
  this->m_nPrevSequence = -1;
  this->m_nRestoreSequence = -1;
  this->m_bCanUseFastPath = false;
  this->m_bIsUsingRelativeLighting = false;
  this->m_bIsStaticProp = false;
  this->m_pRagdoll = nullptr;
  this->m_pClientsideRagdoll = nullptr;
  this->m_builtRagdoll = false;
  this->m_flEncodedController[0] = 0.0;
  this->m_flEncodedController[1] = 0.0;
  this->m_flEncodedController[2] = 0.0;
  this->m_flEncodedController[3] = 0.0;
  C_BaseEntity::AddVar(
    this,
    data: this->m_flEncodedController,
    watcher: &this->m_iv_flEncodedController,
    type: 1,
    bSetup: true);
  v3 = 1;
  if ( this->m_bClientSideAnimation )
    v3 = 9;
  C_BaseEntity::AddVar(
    this,
    data: this->m_flPoseParameter,
    watcher: &this->m_iv_flPoseParameter,
    type: v3,
    bSetup: true);
  C_BaseEntity::AddVar(this, data: &this->m_flCycle, watcher: &this->m_iv_flCycle, type: v3, bSetup: true);
  v4 = g_iPreviousBoneCounter;
  this->m_flLastBoneSetupTime = -3.4028235e38;
  this->m_pNextForThreadedBoneSetup = nullptr;
  this->m_iMostRecentModelBoneCounter = -1;
  this->m_iMostRecentBoneSetupRequest = v4 - 1;
  this->m_vecPreRagdollMins = vec3_origin;
  this->m_vecPreRagdollMaxs = vec3_origin;
  this->m_nEventSequence = -1;
  this->m_nPrevNewSequenceParity = -1;
  this->m_nPrevResetEventsParity = -1;
  this->m_bStoreRagdollInfo = false;
  this->m_pRagdollInfo = nullptr;
  this->m_flPlaybackRate = 1.0;
  this->m_pIk = nullptr;
  this->m_bClientSideAnimation = false;
  this->m_nOldMuzzleFlashParity = 0;
  this->m_nMuzzleFlashParity = 0;
  if ( this->m_flModelScale.m_Value != 1.0 )
    this->m_flModelScale.m_Value = 1.0;
  this->m_iEyeAttachment = 0;
  this->m_pStudioHdr = nullptr;
  this->m_bReceivedSequence = false;
  this->m_bBonePolishSetup = false;
  this->m_prevClientCycle = 0.0;
  this->m_prevClientAnimTime = 0.0;
  this->m_flOldModelScale = 0.0;
  this->m_hStudioHdr = -1;
  this->m_vecRenderOriginOverride = vec3_invalid;
  this->m_pJiggleBones = nullptr;
  this->m_isJiggleBonesEnabled = true;
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10030D30
// Name: public: virtual void C_BaseAnimating::BuildTransformations(class CStudioHdr __near *,class Vector __near *,class Quaternion __near * const,struct matrix3x4_t const __near &,int,class CBoneBitList __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_BaseAnimating::BuildTransformations(
        C_BaseAnimating *this@<ecx>,
        int a2@<ebp>,
        CStudioHdr *hdr,
        Vector *pos,
        Quaternion *q,
        const matrix3x4_t *cameraTransform,
        int boneMask,
        CBoneBitList *boneComputed)
{
  const char *v9; // eax
  mstudiobone_t *v10; // eax
  CRagdoll *m_pRagdoll; // ecx
  int v12; // edx
  CRagdoll *v13; // eax
  CBoneMergeCache *m_pBoneMergeCache; // edi
  CStudioHdr *v15; // edx
  const studiohdr_t *m_pStudioHdr; // eax
  unsigned int v17; // edi
  mstudiobone_t *v18; // ecx
  CBoneMergeCache *v19; // eax
  int v20; // eax
  CBoneMergeCache *v21; // eax
  CBoneMergeCache *v22; // eax
  CJiggleBones *m_pJiggleBones; // ecx
  int proctype; // eax
  CJiggleBones *v25; // eax
  CJiggleBones *v26; // eax
  CJiggleBones *v27; // ecx
  int v28; // eax
  const studiohdr_t *v29; // eax
  float m_Value; // xmm0_4
  float v31; // eax
  int v32; // ecx
  int *m_pMemory; // edx
  CBoneMergeCache *v34; // eax
  unsigned int v35; // edx
  int v36; // edi
  float *v37; // eax
  _BYTE v38[257]; // [esp+4Ch] [ebp-19Ch] OVERLAPPED BYREF
  matrix3x4a_t goalMX; // [esp+158h] [ebp-90h] BYREF
  matrix3x4a_t bonematrix; // [esp+188h] [ebp-60h] BYREF
  Vector boneOrigin; // [esp+1BCh] [ebp-2Ch]
  unsigned int v42; // [esp+1C8h] [ebp-20h] OVERLAPPED
  mstudiobone_t *v43; // [esp+1CCh] [ebp-1Ch]
  int oldWritableBones; // [esp+1D0h] [ebp-18h]
  C_BaseAnimating *p_m_BoneAccessor; // [esp+1D4h] [ebp-14h]
  mstudiobone_t *pbones; // [esp+1D8h] [ebp-10h]
  int i; // [esp+1DCh] [ebp-Ch]
  mstudiojigglebone_t *jiggleInfo; // [esp+1E0h] [ebp-8h]
  mstudiojigglebone_t *retaddr; // [esp+1E8h] [ebp+0h]

  i = a2;
  jiggleInfo = retaddr;
  v9 = "Client_Animation";
  if ( g_bInThreadedBoneSetup )
    v9 = "Client_Animation_Threaded";
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseAnimating::BuildTransformations",
    a3: 0,
    a4: v9,
    a5: false,
    a6: 4);
  if ( hdr != nullptr )
  {
    memset(dst: v38, value: 0, count: 0x100u);
    v10 = (mstudiobone_t *)((char *)hdr->m_pStudioHdr + hdr->m_pStudioHdr->boneindex);
    m_pRagdoll = this->m_pRagdoll;
    v43 = v10;
    HIBYTE(pbones) = 0;
    if ( m_pRagdoll != nullptr )
    {
      LODWORD(boneOrigin.z) = this->m_BoneAccessor.m_WritableBones;
      p_m_BoneAccessor = (C_BaseAnimating *)&this->m_BoneAccessor;
      oldWritableBones = (int)v38;
      this->m_BoneAccessor.m_WritableBones = 524032;
      this->m_BoneAccessor.m_ReadableBones = 524032;
      m_pRagdoll->RagdollBone(
        this: m_pRagdoll,
        a2: this,
        a3: v10,
        a4: hdr->m_pStudioHdr->numbones,
        a5: (bool *)oldWritableBones,
        a6: (CBoneAccessor *)p_m_BoneAccessor);
      v12 = oldWritableBones;
      v13 = this->m_pRagdoll;
      this->m_BoneAccessor.m_WritableBones = LODWORD(boneOrigin.z);
      this->m_BoneAccessor.m_ReadableBones = v12;
      HIBYTE(pbones) = !v13->m_ragdoll.allowStretch;
    }
    if ( (this->m_fEffects & 1) != 0 )
    {
      if ( this->m_pBoneMergeCache == nullptr )
      {
        v21 = (CBoneMergeCache *)MemAlloc_Alloc(nSize: 0x34u);
        if ( v21 != nullptr )
          v22 = CBoneMergeCache::CBoneMergeCache(this: v21);
        else
          v22 = nullptr;
        p_m_BoneAccessor = this;
        this->m_pBoneMergeCache = v22;
        CBoneMergeCache::Init(this: v22, pOwner: p_m_BoneAccessor);
      }
      CBoneMergeCache::MergeMatchingBones(this: this->m_pBoneMergeCache, boneMask);
    }
    else
    {
      m_pBoneMergeCache = this->m_pBoneMergeCache;
      if ( m_pBoneMergeCache != nullptr )
      {
        if ( m_pBoneMergeCache->m_BoneMergeBits.m_numInts > 1u )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBoneMergeCache->m_BoneMergeBits.m_pInt);
        m_pBoneMergeCache->m_BoneMergeBits.m_pInt = nullptr;
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pBoneMergeCache->m_MergedBones);
        C_BaseEntity::operator delete(pMem: m_pBoneMergeCache);
        this->m_pBoneMergeCache = nullptr;
      }
    }
    v15 = hdr;
    m_pStudioHdr = hdr->m_pStudioHdr;
    v17 = 0;
    p_m_BoneAccessor = nullptr;
    if ( m_pStudioHdr->numbones > 0 )
    {
      oldWritableBones = (int)q;
      v18 = v43;
      LODWORD(boneOrigin.y) = pos;
      v43 = (mstudiobone_t *)((char *)v43 + 4);
      v42 = 0;
      LODWORD(boneOrigin.z) = -4 - (_DWORD)v18;
      do
      {
        if ( (boneMask & v15->m_boneFlags.m_Memory.m_pMemory[v17]) != 0 )
        {
          v19 = this->m_pBoneMergeCache;
          if ( v19 == nullptr
            || v19->m_pOwnerHdr == nullptr
            || (v20 = (1 << (v17 & 0x1F)) & v19->m_BoneMergeBits.m_pInt[v17 >> 5],
                v17 = (unsigned int)p_m_BoneAccessor,
                v20 == 0) )
          {
            if ( v38[v17] != 0 )
            {
              this->ApplyBoneMatrixTransform(this, a2: &this->m_BoneAccessor.m_pBones[v42 / 0x30]);
              if ( HIBYTE(pbones) != 0 && v43->sznameindex != -1 )
              {
                VectorTransform(
                  in1: (const float *)LODWORD(boneOrigin.y),
                  in2: &this->m_BoneAccessor.m_pBones[v43->sznameindex],
                  out: &bonematrix.m_flMatVal[2][2]);
                MatrixSetColumn(
                  in: (const Vector *)&bonematrix.m_flMatVal[2][2],
                  column: 3,
                  out: &this->m_BoneAccessor.m_pBones[v42 / 0x30]);
              }
            }
            else if ( !CalcProceduralBone(pStudioHdr: hdr, iBone: v17, bonetoworld: &this->m_BoneAccessor) )
            {
              if ( ((1 << (v17 & 0x1F)) & boneComputed->m_Ints[v17 >> 5]) == 0 )
              {
                QuaternionMatrix(
                  q: (const Quaternion *)oldWritableBones,
                  pos: (const Vector *)LODWORD(boneOrigin.y),
                  matrix: (matrix3x4a_t *)&goalMX.m_flMatVal[2][1]);
                if ( (hdr->m_boneFlags.m_Memory.m_pMemory[v17] & 4) != 0
                  && (*((_BYTE *)&v43->proctype
                      + LODWORD(boneOrigin.z)
                      + hdr->m_pStudioHdr->boneindex
                      + (unsigned int)hdr->m_pStudioHdr)
                    & 5) != 0
                  && (r_jiggle_bones.m_pParent == nullptr || r_jiggle_bones.m_pParent->m_Value.m_nValue == 0) )
                {
                  m_pJiggleBones = this->m_pJiggleBones;
                  if ( m_pJiggleBones != nullptr )
                  {
                    CJiggleBones::`scalar deleting destructor'(this: m_pJiggleBones, a2: 1u);
                    this->m_pJiggleBones = nullptr;
                  }
                }
                if ( (hdr->m_boneFlags.m_Memory.m_pMemory[v17] & 4) != 0
                  && (*((_BYTE *)&v43->proctype
                      + LODWORD(boneOrigin.z)
                      + hdr->m_pStudioHdr->boneindex
                      + (unsigned int)hdr->m_pStudioHdr)
                    & 5) != 0
                  && r_jiggle_bones.m_pParent != nullptr
                  && r_jiggle_bones.m_pParent->m_Value.m_nValue != 0
                  && this->m_isJiggleBonesEnabled )
                {
                  if ( v43->sznameindex == -1 )
                    ConcatTransforms(
                      in1: cameraTransform,
                      in2: (matrix3x4a_t *)&goalMX.m_flMatVal[2][1],
                      out: (matrix3x4_t *)&v38[256]);
                  else
                    ConcatTransforms_Aligned(
                      m0: &this->m_BoneAccessor.m_pBones[v43->sznameindex],
                      m1: (matrix3x4a_t *)&goalMX.m_flMatVal[2][1],
                      out: (matrix3x4a_t *)&v38[256]);
                  proctype = v43->proctype;
                  if ( proctype != 0 )
                    p_m_BoneAccessor = (C_BaseAnimating *)((char *)v43 + proctype - 4);
                  else
                    p_m_BoneAccessor = nullptr;
                  if ( this->m_pJiggleBones == nullptr )
                  {
                    v25 = (CJiggleBones *)MemAlloc_Alloc(nSize: 0x1Cu);
                    if ( v25 != nullptr )
                      v26 = CJiggleBones::CJiggleBones(this: v25);
                    else
                      v26 = nullptr;
                    this->m_pJiggleBones = v26;
                  }
                  v27 = this->m_pJiggleBones;
                  p_m_BoneAccessor = (C_BaseAnimating *)&this->m_BoneAccessor.m_pBones[v42 / 0x30];
                  oldWritableBones = (int)&v38[256];
                  CJiggleBones::BuildJiggleTransformations(
                    this: v27,
                    boneIndex: v17,
                    currenttime: *(float *)(gpGlobals.m_Index + 12),
                    jiggleInfo: (const mstudiojigglebone_t *)p_m_BoneAccessor,
                    goalMX: (const matrix3x4_t *)&v38[256],
                    boneMX: (matrix3x4_t *)p_m_BoneAccessor);
                }
                else
                {
                  v28 = hdr->m_boneParent.m_Memory.m_pMemory[v17];
                  if ( v28 == -1 )
                    ConcatTransforms(
                      in1: cameraTransform,
                      in2: (matrix3x4a_t *)&goalMX.m_flMatVal[2][1],
                      out: &this->m_BoneAccessor.m_pBones[v42 / 0x30]);
                  else
                    ConcatTransforms_Aligned(
                      m0: &this->m_BoneAccessor.m_pBones[v28],
                      m1: (matrix3x4a_t *)&goalMX.m_flMatVal[2][1],
                      out: &this->m_BoneAccessor.m_pBones[v42 / 0x30]);
                }
              }
              if ( hdr->m_boneParent.m_Memory.m_pMemory[v17] == -1 )
                this->ApplyBoneMatrixTransform(this, a2: &this->m_BoneAccessor.m_pBones[v42 / 0x30]);
            }
          }
        }
        v15 = hdr;
        v29 = hdr->m_pStudioHdr;
        LODWORD(boneOrigin.y) += 12;
        oldWritableBones += 16;
        ++v43;
        v42 += 48;
        p_m_BoneAccessor = (C_BaseAnimating *)++v17;
      }
      while ( (signed int)v17 < v29->numbones );
    }
    m_Value = this->m_flModelScale.m_Value;
    if ( this->m_ScaleType.m_Value == NONHIERARCHICAL_MODEL_SCALE && m_Value > 1.0000001 || m_Value < 0.99999988 )
    {
      v31 = *(float *)&v15->m_pStudioHdr;
      v32 = 0;
      oldWritableBones = 0;
      boneOrigin.y = v31;
      if ( *(int *)(LODWORD(v31) + 156) > 0 )
      {
        m_pMemory = v15->m_boneFlags.m_Memory.m_pMemory;
        p_m_BoneAccessor = nullptr;
        LODWORD(boneOrigin.z) = m_pMemory;
        do
        {
          if ( (boneMask & *m_pMemory) != 0 )
          {
            v34 = this->m_pBoneMergeCache;
            if ( v34 == nullptr
              || v34->m_pOwnerHdr == nullptr
              || (v35 = v32,
                  v36 = 1 << (v32 & 0x1F),
                  v32 = oldWritableBones,
                  (v36 & v34->m_BoneMergeBits.m_pInt[v35 >> 5]) == 0) )
            {
              v37 = (float *)((char *)p_m_BoneAccessor + (unsigned int)this->m_BoneAccessor.m_pBones);
              *v37 = *v37 * m_Value;
              v37[1] = v37[1] * m_Value;
              v37[2] = m_Value * v37[2];
              v37[4] = v37[4] * m_Value;
              v37[5] = v37[5] * m_Value;
              v37[6] = v37[6] * m_Value;
              v37[8] = v37[8] * m_Value;
              v37[9] = v37[9] * m_Value;
              v37[10] = v37[10] * m_Value;
            }
          }
          p_m_BoneAccessor = (C_BaseAnimating *)((char *)p_m_BoneAccessor + 48);
          ++v32;
          m_pMemory = (int *)(LODWORD(boneOrigin.z) + 4);
          oldWritableBones = v32;
          LODWORD(boneOrigin.z) += 4;
        }
        while ( v32 < *(_DWORD *)(LODWORD(boneOrigin.y) + 156) );
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10031320
// Name: public: virtual bool C_BaseAnimating::GetSoundSpatialization(struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimating::GetSoundSpatialization(C_BaseAnimating *this, SpatializationInfo_t *info)
{
  SpatializationInfo_t *v3; // edi
  const Vector *v5; // eax
  float *p_x; // ecx
  IVModelInfoClient_vtbl *v7; // ebx
  int v8; // eax
  float *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  Vector mins; // [esp+8h] [ebp-18h] BYREF
  Vector maxs; // [esp+14h] [ebp-Ch] BYREF

  if ( (unsigned __int8)_ThreadInMainThread() != 0 )
  {
    *(BoneAccess *)&maxs.y = g_BoneAcessBase;
    CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_BoneAccessStack,
      elem: g_BoneAccessStack.m_Size,
      src: (const vgui::PropertySheet::Page_t *)&maxs.y);
    *(_WORD *)&g_BoneAcessBase.bAllowBoneAccessForNormalModels = 1;
    g_BoneAcessBase.tag = (const char *)1;
  }
  v3 = info;
  if ( C_BaseEntity::GetSoundSpatialization(this, info) )
  {
    C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: (C_BaseAnimating::AutoAllowBoneAccess *)&info + 3);
    if ( v3->pOrigin != nullptr && this->IsNPC(this) && this->m_pIk != nullptr )
    {
      v5 = this->GetAbsOrigin(this);
      p_x = &v3->pOrigin->x;
      *p_x = v5->x;
      p_x[1] = v5->y;
      p_x[2] = v5->z;
      v7 = modelinfo->__vftable;
      v8 = ((int (__thiscall *)(IClientRenderable *, Vector *, Vector *))this->GetModel)(
             a1: &this->IClientRenderable,
             a2: &mins,
             a3: &maxs);
      ((void (__thiscall *)(IVModelInfoClient *, int))v7->GetModelBounds)(a1: modelinfo, a2: v8);
      v9 = &v3->pOrigin->x;
      v10 = (float)((float)(maxs.y + mins.y) * 0.5) + v9[1];
      v11 = (float)((float)(maxs.z + mins.z) * 0.5) + v9[2];
      *v9 = (float)((float)(maxs.x + mins.x) * 0.5) + *v9;
      v9[1] = v10;
      v9[2] = v11;
    }
    return 1;
  }
  else
  {
    C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: (C_BaseAnimating::AutoAllowBoneAccess *)&info + 3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031460
// Name: public: virtual void C_BaseAnimating::EjectParticleBrass(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::EjectParticleBrass(C_BaseAnimating *this, const char *pEffectName, int iAttachment)
{
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CSheet> *p_m_ejectBrassEffect; // esi
  CNewParticleEffect *v5; // edi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *p_m_References; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // eax

  if ( cl_ejectbrass.m_pParent != nullptr && cl_ejectbrass.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pObject = this->m_ejectBrassEffect.m_pObject;
    if ( m_pObject != nullptr && this->m_iEjectBrassAttachment == iAttachment )
    {
      CParticleCollection::Restart(this: &m_pObject->CParticleCollection, eMode: RESTART_NORMAL);
    }
    else
    {
      this->m_iEjectBrassAttachment = iAttachment;
      p_m_ejectBrassEffect = (CUtlReference<CSheet> *)&this->m_ejectBrassEffect;
      v5 = CParticleProperty::Create(
             this: &this->m_Particles,
             pszParticleName: pEffectName,
             iAttachType: PATTACH_POINT_FOLLOW,
             iAttachmentPoint: iAttachment,
             vecOriginOffset: vec3_origin,
             matOffset: nullptr);
      p_m_References = &p_m_ejectBrassEffect->m_pObject->m_References;
      if ( p_m_References != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v5 )
      {
        if ( p_m_References != nullptr )
        {
          CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
            this: p_m_References + 232,
            which: p_m_ejectBrassEffect);
          p_m_ejectBrassEffect->m_pObject = nullptr;
        }
        p_m_ejectBrassEffect->m_pObject = (CSheet *)v5;
        if ( v5 != nullptr )
        {
          p_m_ejectBrassEffect->m_pNext = (CUtlReference<CSheet> *)v5->m_References.m_pHead;
          m_pHead = v5->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_ejectBrassEffect;
          p_m_ejectBrassEffect->m_pPrev = nullptr;
          v5->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_ejectBrassEffect;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031530
// Name: public: virtual void C_BaseAnimating::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::PostDataUpdate(C_BaseAnimating *this, DataUpdateType_t updateType)
{
  C_BaseAnimating *v3; // edi
  float m_InterpolationAmount; // xmm0_4
  int v5; // edx
  float *p_m_nPrevNewSequenceParity; // ecx
  bool v7; // dl
  int v8; // esi
  float *p_m_flPrevEventCycle; // ecx
  bool v10; // bl
  C_BaseAnimating *v11; // esi
  float m_Value; // xmm0_4
  CStudioHdr *m_pStudioHdr; // eax
  float v14; // xmm1_4
  int v15; // eax
  IMDLCache *v16; // esi
  CStudioHdr *v17; // eax
  vgui::PropertySheet::Page_t src; // [esp+10h] [ebp-Ch] BYREF
  C_BaseAnimating *v19; // [esp+18h] [ebp-4h]
  bool bBoneControllersChanged_3; // [esp+27h] [ebp+Bh]
  bool bBoneControllersChanged_3a; // [esp+27h] [ebp+Bh]

  v19 = this;
  C_BaseEntity::PostDataUpdate(this, updateType);
  v3 = (C_BaseAnimating *)((char *)this - 8);
  if ( LOBYTE(this->m_flOldEncodedController[2]) != 0 )
  {
    m_InterpolationAmount = this->m_iv_flCycle.m_InterpolationAmount;
    if ( v3->m_flCycle.m_Val != m_InterpolationAmount )
    {
      v3->m_flCycle.m_Val = m_InterpolationAmount;
      C_BaseEntity::InvalidatePhysicsRecursive(this: (C_BaseAnimating *)((char *)this - 8), nChangeFlags: 8);
    }
    if ( v3->m_ClientSideAnimationListHandle == -1 )
    {
      src.page = (vgui::Panel *)((char *)this - 8);
      *(_DWORD *)&src.contextMenu = 0;
      v3->m_ClientSideAnimationListHandle = CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
                                              this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_ClientSideAnimationList,
                                              elem: g_ClientSideAnimationList.m_Size,
                                              &src);
      C_BaseAnimating::ClientSideAnimationChanged(this: (C_BaseAnimating *)((char *)this - 8));
    }
  }
  else
  {
    C_BaseAnimating::RemoveFromClientSideAnimationList(this: (C_BaseAnimating *)((char *)this - 8));
  }
  bBoneControllersChanged_3 = false;
  v5 = 0;
  p_m_nPrevNewSequenceParity = (float *)&this->m_nPrevNewSequenceParity;
  do
  {
    if ( bBoneControllersChanged_3 )
      break;
    bBoneControllersChanged_3 = p_m_nPrevNewSequenceParity[128] != *p_m_nPrevNewSequenceParity;
    ++v5;
    ++p_m_nPrevNewSequenceParity;
  }
  while ( v5 < 4 );
  v7 = false;
  v8 = 0;
  p_m_flPrevEventCycle = &this->m_flPrevEventCycle;
  while ( !v7 )
  {
    if ( p_m_flPrevEventCycle[35] != *p_m_flPrevEventCycle
      || p_m_flPrevEventCycle[36] != p_m_flPrevEventCycle[1]
      || p_m_flPrevEventCycle[37] != p_m_flPrevEventCycle[2]
      || p_m_flPrevEventCycle[38] != p_m_flPrevEventCycle[3]
      || p_m_flPrevEventCycle[39] != p_m_flPrevEventCycle[4] )
    {
      v7 = true;
      break;
    }
    v7 = p_m_flPrevEventCycle[40] != p_m_flPrevEventCycle[5];
    v8 += 6;
    p_m_flPrevEventCycle += 6;
    if ( v8 >= 24 )
      break;
  }
  v10 = this->m_iv_flCycle.m_InterpolationAmount != *(float *)&this->m_SequenceTransitioner.m_animationQueue.m_pElements
     || bBoneControllersChanged_3
     || v7;
  v11 = v19;
  bBoneControllersChanged_3a = v19->m_nPrevSkin != LODWORD(v19->m_vecPreRagdollMaxs.z);
  if ( v3->m_ScaleType.m_Value != HIERARCHICAL_MODEL_SCALE )
  {
    if ( v3->m_pStudioHdr == nullptr && v3->GetModel(this: &v3->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: v3);
    m_pStudioHdr = v3->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr->numbones == 1 )
      m_Value = v3->m_flModelScale.m_Value;
    else
      m_Value = 1.0;
  }
  else
  {
    m_Value = v3->m_flModelScale.m_Value;
  }
  v14 = *(float *)&v11->m_nPrevBody;
  if ( v10 || bBoneControllersChanged_3a || v14 != m_Value )
  {
    v15 = v10 ? 8 : 0;
    if ( bBoneControllersChanged_3a )
      v15 |= 0x30u;
    if ( v14 != m_Value )
      v15 |= 0x10u;
    C_BaseEntity::InvalidatePhysicsRecursive(this: v3, nChangeFlags: v15);
    if ( (v10 || bBoneControllersChanged_3a) && LOBYTE(v11->m_flOldEncodedController[2]) != 0 )
      C_BaseAnimating::ClientSideAnimationChanged(this: v3);
  }
  if ( v11->m_nSkin != v11->m_nNewSequenceParity )
  {
    v16 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    if ( v3->m_pStudioHdr == nullptr && v3->GetModel(this: &v3->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: v3);
    v17 = v3->m_pStudioHdr;
    if ( v17 != nullptr && v17->m_pStudioHdr != nullptr && (v17->m_pStudioHdr->flags & 0x10) == 0 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)&v19->m_builtRagdoll + 20))(a1: *(_DWORD *)(gpGlobals.m_Index + 12));
    v16->EndLock(this: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031800
// Name: public: void C_BaseAnimating::CopySequenceTransitions(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::CopySequenceTransitions(C_BaseAnimating *this, C_BaseAnimating *pCopyFrom)
{
  CSequenceTransitioner *p_m_SequenceTransitioner; // esi
  int m_Size; // edi
  int v4; // edx
  C_AnimationLayer *m_pMemory; // eax
  __int64 v6; // xmm0_8
  _QWORD *p_m_flLayerAnimtime; // eax
  _QWORD *v8; // ecx

  p_m_SequenceTransitioner = &this->m_SequenceTransitioner;
  this->m_SequenceTransitioner.m_animationQueue.m_Size = 0;
  m_Size = pCopyFrom->m_SequenceTransitioner.m_animationQueue.m_Size;
  if ( this->m_SequenceTransitioner.m_animationQueue.m_Size < m_Size )
    CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::InsertMultipleBefore(
      this: &this->m_SequenceTransitioner.m_animationQueue,
      elem: this->m_SequenceTransitioner.m_animationQueue.m_Size,
      num: m_Size - this->m_SequenceTransitioner.m_animationQueue.m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      m_pMemory = pCopyFrom->m_SequenceTransitioner.m_animationQueue.m_Memory.m_pMemory;
      v6 = *(_QWORD *)&m_pMemory[v4].m_flLayerAnimtime;
      p_m_flLayerAnimtime = (_QWORD *)&m_pMemory[v4].m_flLayerAnimtime;
      v8 = (_QWORD *)&p_m_SequenceTransitioner->m_animationQueue.m_Memory.m_pMemory[v4].m_flLayerAnimtime;
      *v8 = v6;
      v8[1] = p_m_flLayerAnimtime[1];
      v8[2] = p_m_flLayerAnimtime[2];
      v8[3] = p_m_flLayerAnimtime[3];
      ++v4;
      --m_Size;
      v8[4] = p_m_flLayerAnimtime[4];
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031890
// Name: public: void C_BaseAnimating::ForceClientSideAnimationOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ForceClientSideAnimationOn(C_BaseAnimating *this)
{
  bool v2; // zf
  vgui::PropertySheet::Page_t src; // [esp+4h] [ebp-8h] BYREF

  v2 = this->m_ClientSideAnimationListHandle == -1;
  this->m_bClientSideAnimation = true;
  if ( v2 )
  {
    src.page = (vgui::Panel *)this;
    *(_DWORD *)&src.contextMenu = 0;
    this->m_ClientSideAnimationListHandle = CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
                                              this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_ClientSideAnimationList,
                                              elem: g_ClientSideAnimationList.m_Size,
                                              &src);
    C_BaseAnimating::ClientSideAnimationChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031BA0
// Name: private: void C_BaseAnimating::ParseModelEffects(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ParseModelEffects(C_BaseAnimating *this, KeyValues *modelKeyValues)
{
  C_BaseAnimating *v2; // esi
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // ebx
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *p_m_Ropes; // edi
  unsigned __int16 v6; // ax
  int v7; // esi
  _DWORD *p_m_Element; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  const char *String; // ebx
  const char *v12; // edi
  ParticleAttachment_t AttachTypeFromString; // esi
  int v14; // eax
  int v15; // edi
  float z; // edx
  CNewParticleEffect *v17; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // ecx
  KeyValues *v19; // eax
  KeyValues *NextKey; // esi
  const char *v21; // edi
  const char *v22; // ebx
  ParticleAttachment_t v23; // edi
  __int64 v24; // xmm0_8
  float v25; // edx
  const char *ModelName; // eax
  const char *v27; // eax
  const char *v28; // eax
  Vector v29; // [esp-10h] [ebp-6Ch]
  Vector v30; // [esp-10h] [ebp-6Ch]
  __int64 pVector; // [esp+Ch] [ebp-50h] BYREF
  float v32; // [esp+14h] [ebp-48h]
  Vector flVec; // [esp+18h] [ebp-44h] BYREF
  __int64 v34; // [esp+24h] [ebp-38h]
  float v35; // [esp+2Ch] [ebp-30h]
  Vector vecOffset; // [esp+30h] [ebp-2Ch]
  CUtlReference<CNewParticleEffect> hModelEffect; // [esp+3Ch] [ebp-20h] BYREF
  const char *pszAttachment; // [esp+48h] [ebp-14h]
  char *pString; // [esp+4Ch] [ebp-10h]
  int iControlPoint; // [esp+50h] [ebp-Ch]
  const char *pszParticleEffect; // [esp+54h] [ebp-8h]
  C_BaseEntity *pEntity; // [esp+58h] [ebp-4h]
  KeyValues *pSingleEffect; // [esp+64h] [ebp+8h]

  v2 = this;
  pEntity = this;
  Key = KeyValues::FindKey(this: modelKeyValues, keyName: "Cables", bCreate: false);
  if ( Key != nullptr )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
    if ( FirstSubKey != nullptr )
    {
      p_m_Ropes = &v2->m_Ropes;
      while ( 1 )
      {
        iControlPoint = (int)C_RopeKeyframe::CreateFromKeyValues(pEnt: v2, pValues: FirstSubKey);
        v6 = CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short>>::AllocInternal(
               this: p_m_Ropes,
               multilist: false);
        v7 = v6;
        if ( v6 != 0xFFFF )
        {
          CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
            this: p_m_Ropes,
            before: 0xFFFFu,
            elem: v6);
          p_m_Element = &p_m_Ropes->m_Memory.m_pMemory[v7].m_Element;
          if ( p_m_Element != nullptr )
            *p_m_Element = iControlPoint;
        }
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( FirstSubKey == nullptr )
          break;
        v2 = (C_BaseAnimating *)pEntity;
      }
    }
  }
  v9 = KeyValues::FindKey(this: modelKeyValues, keyName: "Particles", bCreate: false);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::GetFirstSubKey(this: v9);
    pSingleEffect = v10;
    if ( v10 != nullptr )
    {
      while ( 1 )
      {
        pszParticleEffect = KeyValues::GetString(this: v10, keyName: "name", defaultValue: prType);
        String = KeyValues::GetString(this: v10, keyName: "attachment_point", defaultValue: prType);
        v12 = KeyValues::GetString(this: v10, keyName: "attachment_type", defaultValue: prType);
        iControlPoint = (int)KeyValues::GetString(this: v10, keyName: "attachment_offset", defaultValue: prType);
        AttachTypeFromString = GetAttachTypeFromString(pszString: v12);
        if ( AttachTypeFromString == -1 )
        {
          ModelName = C_BaseEntity::GetModelName(this: pEntity);
          _Warning(
            a1: "Invalid attach type specified for particle effect in model '%s' keyvalues section. Trying to spawn effect '%"
            "s' with attach type of '%s'\n",
            a2: ModelName);
          return;
        }
        v14 = atoi(nptr: String);
        v15 = v14;
        if ( *String != 48 && v14 == 0 )
        {
          v15 = pEntity->LookupAttachment(this: &pEntity->IClientRenderable, a2: String);
          if ( v15 == -1 )
          {
            v27 = C_BaseEntity::GetModelName(this: pEntity);
            _Warning(
              a1: "Failed to find attachment point specified for particle effect in model '%s' keyvalues section. Trying to s"
              "pawn effect '%s' on attachment named '%s'\n",
              a2: v27);
            return;
          }
        }
        z = vec3_origin.z;
        *(_QWORD *)&vecOffset.x = *(_QWORD *)&vec3_origin.x;
        if ( iControlPoint != 0 )
        {
          UTIL_StringToVector(pVector: &flVec.x, pString: (const char *)iControlPoint);
          vecOffset = flVec;
          z = flVec.z;
        }
        memset(&hModelEffect, 0, sizeof(hModelEffect));
        *(_QWORD *)&v29.x = *(_QWORD *)&vecOffset.x;
        v29.z = z;
        v17 = CParticleProperty::Create(
                this: &pEntity->m_Particles,
                pszParticleName: pszParticleEffect,
                iAttachType: AttachTypeFromString,
                iAttachmentPoint: v15,
                vecOriginOffset: v29,
                matOffset: nullptr);
        if ( hModelEffect.m_pObject != v17 )
        {
          if ( hModelEffect.m_pObject != nullptr )
          {
            if ( hModelEffect.m_pPrev != nullptr )
            {
              hModelEffect.m_pPrev->m_pNext = hModelEffect.m_pNext;
              if ( hModelEffect.m_pNext != nullptr )
                hModelEffect.m_pNext->m_pPrev = hModelEffect.m_pPrev;
            }
            else if ( hModelEffect.m_pObject->m_References.m_pHead == &hModelEffect )
            {
              hModelEffect.m_pObject->m_References.m_pHead = hModelEffect.m_pNext;
              if ( hModelEffect.m_pNext != nullptr )
                hModelEffect.m_pNext->m_pPrev = nullptr;
            }
            hModelEffect.m_pPrev = nullptr;
            hModelEffect.m_pNext = nullptr;
          }
          hModelEffect.m_pObject = v17;
          if ( v17 != nullptr )
          {
            hModelEffect.m_pNext = v17->m_References.m_pHead;
            m_pHead = v17->m_References.m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = &hModelEffect;
            hModelEffect.m_pPrev = nullptr;
            v17->m_References.m_pHead = &hModelEffect;
          }
        }
        v19 = KeyValues::FindKey(this: pSingleEffect, keyName: "ControlPoints", bCreate: false);
        if ( v19 != nullptr )
        {
          NextKey = KeyValues::GetFirstSubKey(this: v19);
          if ( NextKey != nullptr )
            break;
        }
LABEL_42:
        if ( hModelEffect.m_pObject != nullptr )
        {
          if ( hModelEffect.m_pPrev != nullptr )
          {
            hModelEffect.m_pPrev->m_pNext = hModelEffect.m_pNext;
            if ( hModelEffect.m_pNext != nullptr )
              hModelEffect.m_pNext->m_pPrev = hModelEffect.m_pPrev;
          }
          else if ( hModelEffect.m_pObject->m_References.m_pHead == &hModelEffect )
          {
            hModelEffect.m_pObject->m_References.m_pHead = hModelEffect.m_pNext;
            if ( hModelEffect.m_pNext != nullptr )
              hModelEffect.m_pNext->m_pPrev = nullptr;
          }
          memset(&hModelEffect, 0, sizeof(hModelEffect));
        }
        pSingleEffect = KeyValues::GetNextKey(this: pSingleEffect);
        if ( pSingleEffect == nullptr )
          return;
        v10 = pSingleEffect;
      }
      while ( 1 )
      {
        v21 = KeyValues::GetString(this: NextKey, keyName: "cp_number", defaultValue: prType);
        pszAttachment = KeyValues::GetString(this: NextKey, keyName: "attachment_point", defaultValue: prType);
        v22 = KeyValues::GetString(this: NextKey, keyName: "attachment_type", defaultValue: prType);
        pString = (char *)KeyValues::GetString(this: NextKey, keyName: "attachment_offset", defaultValue: prType);
        iControlPoint = atoi(nptr: v21);
        v23 = GetAttachTypeFromString(pszString: v22);
        if ( v23 == -1 )
          break;
        v24 = *(_QWORD *)&vec3_origin.x;
        v25 = vec3_origin.z;
        v34 = *(_QWORD *)&vec3_origin.x;
        if ( pString != nullptr )
        {
          UTIL_StringToVector((float *)&pVector, pString);
          v34 = pVector;
          v35 = v32;
          v25 = v32;
          v24 = pVector;
        }
        if ( hModelEffect.m_pObject != nullptr )
        {
          *(_QWORD *)&v30.x = v24;
          v30.z = v25;
          if ( v23 == PATTACH_WORLDORIGIN )
            CParticleProperty::AddControlPoint(
              this: &pEntity->m_Particles,
              pEffect: hModelEffect.m_pObject,
              iPoint: iControlPoint,
              pEntity: nullptr,
              iAttachType: PATTACH_WORLDORIGIN,
              pszAttachmentName: nullptr,
              vecOriginOffset: v30,
              matOffset: nullptr);
          else
            CParticleProperty::AddControlPoint(
              this: &pEntity->m_Particles,
              pEffect: hModelEffect.m_pObject,
              iPoint: iControlPoint,
              pEntity,
              iAttachType: v23,
              pszAttachmentName: pszAttachment,
              vecOriginOffset: v30,
              matOffset: nullptr);
        }
        NextKey = KeyValues::GetNextKey(this: NextKey);
        if ( NextKey == nullptr )
          goto LABEL_42;
      }
      v28 = C_BaseEntity::GetModelName(this: pEntity);
      _Warning(
        a1: "Invalid attach type specified for particle effect in model '%s' keyvalues section. Trying to spawn effect '%s' w"
        "ith attach type of '%s'\n",
        a2: v28);
      if ( hModelEffect.m_pObject != nullptr )
      {
        if ( hModelEffect.m_pPrev != nullptr )
        {
          hModelEffect.m_pPrev->m_pNext = hModelEffect.m_pNext;
          if ( hModelEffect.m_pNext != nullptr )
            hModelEffect.m_pNext->m_pPrev = hModelEffect.m_pPrev;
        }
        else if ( hModelEffect.m_pObject->m_References.m_pHead == &hModelEffect )
        {
          hModelEffect.m_pObject->m_References.m_pHead = hModelEffect.m_pNext;
          if ( hModelEffect.m_pNext != nullptr )
            hModelEffect.m_pNext->m_pPrev = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032040
// Name: public: static void C_BaseAnimating::ThreadedBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseAnimating::ThreadedBoneSetup()
{
  int v0; // esi
  int m_Size; // eax
  int v2; // ebx
  C_BaseAnimating *v3; // edi
  int v4; // eax
  C_BaseAnimating *v5; // esi
  int i; // eax
  int v7; // eax
  int v8; // edi
  C_BaseAnimating **v9; // ecx
  int v10; // edi
  CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2> processor; // [esp+4h] [ebp-18h] BYREF

  v0 = 0;
  if ( g_pBoneSetupThreadPool != nullptr
    && g_pBoneSetupThreadPool->NumThreads(this: g_pBoneSetupThreadPool) != 0
    && cl_threaded_bone_setup.m_pParent != nullptr
    && cl_threaded_bone_setup.m_pParent->m_Value.m_nValue != 0 )
  {
    g_bDoThreadedBoneSetup = true;
    if ( g_PreviousBoneSetups.m_Size <= 1 )
    {
      ++g_iPreviousBoneCounter;
      g_PreviousBoneSetups.m_Size = 0;
    }
    else
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "C_BaseAnimating::ThreadedBoneSetup",
        a3: 0,
        a4: "Client_Animation_Threaded",
        a5: false,
        a6: 4);
      m_Size = g_PreviousBoneSetups.m_Size;
      v2 = g_PreviousBoneSetups.m_Size - 1;
      if ( g_PreviousBoneSetups.m_Size - 1 >= 0 )
      {
        while ( 1 )
        {
          v3 = g_PreviousBoneSetups.m_Memory.m_pMemory[v2];
          v4 = (int)v3->GetBoneSetupDependancy(this: v3);
          v5 = (C_BaseAnimating *)v4;
          if ( v4 != 0 )
          {
            for ( i = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 852))(a1: v4);
                  i != 0;
                  i = (*(int (__thiscall **)(int))(*(_DWORD *)i + 852))(a1: i) )
            {
              v5 = (C_BaseAnimating *)i;
            }
            v3->m_pNextForThreadedBoneSetup = v5->m_pNextForThreadedBoneSetup;
            v5->m_pNextForThreadedBoneSetup = v3;
            m_Size = g_PreviousBoneSetups.m_Size;
            if ( g_PreviousBoneSetups.m_Size > 0 )
            {
              if ( v2 != g_PreviousBoneSetups.m_Size - 1 )
              {
                g_PreviousBoneSetups.m_Memory.m_pMemory[v2] = g_PreviousBoneSetups.m_Memory.m_pMemory[g_PreviousBoneSetups.m_Size - 1];
                m_Size = g_PreviousBoneSetups.m_Size;
              }
              g_PreviousBoneSetups.m_Size = --m_Size;
            }
            if ( v5->m_iMostRecentBoneSetupRequest == g_iPreviousBoneCounter )
              goto LABEL_22;
            v5->m_iMostRecentBoneSetupRequest = g_iPreviousBoneCounter;
            v7 = g_PreviousBoneSetups.m_Size;
            v8 = g_PreviousBoneSetups.m_Size;
            if ( g_PreviousBoneSetups.m_Size + 1 > g_PreviousBoneSetups.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PreviousBoneSetups,
                num: g_PreviousBoneSetups.m_Size - g_PreviousBoneSetups.m_Memory.m_nAllocationCount + 1);
              v7 = g_PreviousBoneSetups.m_Size;
            }
            m_Size = v7 + 1;
            g_PreviousBoneSetups.m_Size = m_Size;
            g_PreviousBoneSetups.m_pElements = g_PreviousBoneSetups.m_Memory.m_pMemory;
            if ( m_Size - v8 - 1 > 0 )
            {
              _V_memmove(
                dest: &g_PreviousBoneSetups.m_Memory.m_pMemory[v8 + 1],
                src: &g_PreviousBoneSetups.m_Memory.m_pMemory[v8],
                count: 4 * (m_Size - v8 - 1));
              m_Size = g_PreviousBoneSetups.m_Size;
            }
            v9 = &g_PreviousBoneSetups.m_Memory.m_pMemory[v8];
            if ( v9 == nullptr )
              goto LABEL_22;
            *v9 = v5;
          }
          m_Size = g_PreviousBoneSetups.m_Size;
LABEL_22:
          if ( --v2 < 0 )
          {
            v0 = 0;
            break;
          }
        }
      }
      v10 = m_Size;
      g_bInThreadedBoneSetup = true;
      if ( cl_threaded_bone_setup.m_pParent != nullptr && cl_threaded_bone_setup.m_pParent->m_Value.m_nValue == 1 )
      {
        processor.m_pItems.m_value = nullptr;
        processor.m_pLimit = nullptr;
        _InterlockedExchange((volatile __int32 *)&processor.m_pItems, 0);
        processor.m_ItemProcessor.m_pfnProcess = C_BaseAnimating::SetupBonesOnBaseAnimating;
        processor.m_ItemProcessor.m_pfnBegin = (void (__cdecl *)())PreThreadedBoneSetup;
        processor.m_ItemProcessor.m_pfnEnd = (void (__cdecl *)())PostThreadedBoneSetup;
        CParallelProcessor<C_BaseAnimating *,CFuncJobItemProcessor<C_BaseAnimating *>,2>::Run(
          this: &processor,
          pItems: g_PreviousBoneSetups.m_Memory.m_pMemory,
          nItems: m_Size,
          nChunkSize: 1,
          nMaxParallel: 0x7FFFFFFF,
          pThreadPool: g_pBoneSetupThreadPool);
      }
      else if ( m_Size > 0 )
      {
        do
          C_BaseAnimating::SetupBonesOnBaseAnimating(pBaseAnimating: &g_PreviousBoneSetups.m_Memory.m_pMemory[v0++]);
        while ( v0 < v10 );
      }
      g_bInThreadedBoneSetup = false;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      ++g_iPreviousBoneCounter;
      g_PreviousBoneSetups.m_Size = 0;
    }
  }
  else
  {
    ++g_iPreviousBoneCounter;
    g_PreviousBoneSetups.m_Size = 0;
    g_bDoThreadedBoneSetup = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100322A0
// Name: public: class C_BaseAnimating __near * C_BaseAnimating::CreateRagdollCopy(void)
// Source: json
//------------------------------------------------------------------------------
C_ClientRagdoll *__usercall C_BaseAnimating::CreateRagdollCopy@<eax>(C_BaseAnimating *this@<ecx>, int a2@<ebx>)
{
  C_ClientRagdoll *result; // eax
  C_BaseAnimating *v4; // esi
  const struct model_t *v5; // eax
  const Vector *v6; // eax
  const QAngle *v7; // eax
  bool IsImportantNPC; // al
  unsigned __int8 r; // al
  unsigned __int8 b; // dl
  unsigned __int8 g; // cl
  unsigned __int8 RenderAlpha; // al
  int v13; // eax
  int v14; // eax
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // eax
  const char *v16; // eax
  float m_Value; // xmm0_4
  float v18; // xmm1_4
  ModelScaleType_t v19; // ecx
  float flForcedRetireTime; // [esp+14h] [ebp-10h]
  const char *pModelName; // [esp+20h] [ebp-4h]

  result = this->CreateClientRagdoll(this, a2: 0);
  v4 = result;
  if ( result != nullptr )
  {
    C_BaseAnimating::TermRopes(this);
    v5 = this->GetModel(this: &this->IClientRenderable);
    pModelName = modelinfo->GetModelName(this: modelinfo, a2: v5);
    if ( v4->InitializeAsClientEntity(this: v4, a2: pModelName, a3: false) )
    {
      C_BaseEntity::SnatchModelInstance(this, pToEntity: v4);
      v6 = (const Vector *)((int (__thiscall *)(C_BaseAnimating *, int))this->GetAbsOrigin)(a1: this, a2);
      C_BaseEntity::SetAbsOrigin(this: v4, absOrigin: v6);
      v7 = this->GetAbsAngles(this);
      C_BaseEntity::SetAbsAngles(this: v4, absAngles: v7);
      C_BaseAnimating::IgniteRagdoll(this: v4, pSource: this);
      C_BaseAnimating::TransferDissolveFrom(this: v4, pSource: this);
      v4->m_bInitModelEffects = true;
      C_BaseEntity::AddToEntityList(this: v4, listId: ENTITY_LIST_SIMULATE);
      C_BaseAnimating::TermRopes(this: v4);
      if ( this->AddRagdollToFadeQueue(this) )
      {
        IsImportantNPC = NPC_IsImportantNPC(pAnimating: this);
        BYTE1(v4[1].C_BaseEntity::IClientEntity::IClientRenderable::__vftable) = IsImportantNPC;
        CRagdollLRURetirement::MoveToTopOfLRU(
          this: &s_RagdollLRU,
          pRagdoll: v4,
          bImportant: IsImportantNPC,
          flForcedRetireTime: 0.0);
        LOBYTE(v4[1].C_BaseEntity::IClientEntity::IClientRenderable::__vftable) = 1;
      }
      this->m_builtRagdoll = true;
      C_BaseEntity::AddEffects(this, nEffects: 32);
      if ( (this->m_fEffects & 0x10) != 0 )
        C_BaseEntity::AddEffects(this: v4, nEffects: 16);
      v4->m_bClientSideRagdoll = true;
      C_BaseEntity::SetRenderMode(this: v4, nRenderMode: (RenderMode_t)this->m_nRenderMode, bForceUpdate: false);
      r = this->m_clrRender.m_Value.r;
      b = this->m_clrRender.m_Value.b;
      g = this->m_clrRender.m_Value.g;
      if ( v4->m_clrRender.m_Value.r != r )
        v4->m_clrRender.m_Value.r = r;
      if ( v4->m_clrRender.m_Value.g != g )
        v4->m_clrRender.m_Value.g = g;
      if ( v4->m_clrRender.m_Value.b != b )
        v4->m_clrRender.m_Value.b = b;
      RenderAlpha = C_BaseEntity::GetRenderAlpha(this);
      C_BaseEntity::SetRenderAlpha(this: v4, a: RenderAlpha);
      flForcedRetireTime = C_BaseEntity::GetGlobalFadeScale(this);
      C_BaseEntity::SetGlobalFadeScale(this: v4, flFadeScale: flForcedRetireTime);
      v13 = this->GetBody(this: &this->IClientRenderable);
      if ( v4->m_nBody != v13 )
      {
        v4->m_nBody = v13;
        C_BaseEntity::OnTranslucencyTypeChanged(this: v4);
      }
      v14 = this->GetSkin(this: &this->IClientRenderable);
      if ( v4->m_nSkin != v14 )
      {
        v4->m_nSkin = v14;
        C_BaseEntity::OnTranslucencyTypeChanged(this: v4);
      }
      v4->m_vecForce.x = this->m_vecForce.x;
      v4->m_vecForce.y = this->m_vecForce.y;
      v4->m_vecForce.z = this->m_vecForce.z;
      SetNextClientThink = v4->SetNextClientThink;
      v4->m_nForceBone = this->m_nForceBone;
      ((void (__thiscall *)(C_BaseAnimating *, int))SetNextClientThink)(a1: v4, a2: -996040704);
      v16 = AllocPooledString(pszValue: pModelName);
      C_BaseEntity::SetModelName(this: v4, name: v16);
      C_BaseAnimating::CopySequenceTransitions(this: v4, pCopyFrom: this);
      m_Value = this->m_flModelScale.m_Value;
      v18 = v4->m_flModelScale.m_Value;
      v19 = this->m_ScaleType.m_Value;
      if ( v18 != m_Value || v19 != v4->m_ScaleType.m_Value )
      {
        if ( v18 != m_Value )
          v4->m_flModelScale.m_Value = m_Value;
        if ( v4->m_ScaleType.m_Value != v19 )
          v4->m_ScaleType.m_Value = v19;
        C_BaseEntity::InvalidatePhysicsRecursive(this: v4, nChangeFlags: 16);
      }
      return (C_ClientRagdoll *)v4;
    }
    else
    {
      v4->Release(this: &v4->IClientNetworkable);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032520
// Name: public: virtual class C_BaseAnimating __near * C_BaseAnimating::BecomeRagdollOnClient(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
C_ClientRagdoll *__usercall C_BaseAnimating::BecomeRagdollOnClient@<eax>(
        C_BaseAnimating *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>)
{
  void *v3; // esp
  C_ClientRagdoll *result; // eax
  C_BaseAnimating_vtbl *v6; // eax
  matrix3x4_t v8[256]; // [esp+24h] [ebp-900Ch] BYREF
  matrix3x4_t v9[256]; // [esp+3024h] [ebp-600Ch] BYREF
  matrix3x4_t v10[255]; // [esp+6024h] [ebp-300Ch] BYREF
  matrix3x4_t *v11; // [esp+901Ch] [ebp-14h]
  int v12; // [esp+9020h] [ebp-10h]
  int v13; // [esp+9024h] [ebp-Ch]
  void *v14; // [esp+9028h] [ebp-8h]
  int v15; // [esp+902Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+9030h] [ebp+0h]

  v13 = a2;
  v14 = retaddr;
  v3 = alloca(36876);
  C_BaseEntity::MoveToLastReceivedPosition(this, force: true);
  ((void (__thiscall *)(C_BaseAnimating *, int))this->GetAbsOrigin)(a1: this, a2: a3);
  result = C_BaseAnimating::CreateRagdollCopy(this, a2: (int)&v15);
  this->m_pClientsideRagdoll = result;
  if ( result != nullptr )
  {
    v6 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v12 = 1036831949;
    v11 = v9;
    ((void (__thiscall *)(C_BaseAnimating *, matrix3x4_t *, matrix3x4_t *))v6->GetRagdollInitBoneArrays)(
      a1: this,
      a2: v8,
      a3: v10);
    C_BaseAnimating::InitAsClientRagdoll(
      this: this->m_pClientsideRagdoll,
      pDeltaBones0: v8,
      pDeltaBones1: v10,
      pCurrentBonePosition: v9,
      boneDt: 0.1);
    return (C_ClientRagdoll *)this->m_pClientsideRagdoll;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032710
// Name: private: void C_BaseAnimating::DelayedInitModelEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::DelayedInitModelEffects(C_BaseAnimating *this)
{
  KeyValues *v2; // eax
  IVModelInfoClient_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  const char *v7; // [esp-18h] [ebp-24h]
  KeyValues *modelKeyValues; // [esp+8h] [ebp-4h]

  this->m_bInitModelEffects = false;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    modelKeyValues = KeyValues::KeyValues(this: v2, setName: prType);
  else
    modelKeyValues = nullptr;
  v3 = modelinfo->__vftable;
  v7 = (const char *)this->GetModel(this: &this->IClientRenderable);
  v4 = ((int (__thiscall *)(IVModelInfoClient *))v3->GetModelKeyValueText)(a1: modelinfo);
  v5 = ((int (__thiscall *)(IClientRenderable *, int))this->GetModel)(a1: &this->IClientRenderable, a2: v4);
  v6 = v3->GetModelName(this: modelinfo, a2: (const struct model_t *)v5);
  if ( KeyValues::LoadFromBuffer(
         this: modelKeyValues,
         resourceName: v6,
         pBuffer: v7,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    C_BaseAnimating::ParseModelEffects(this, modelKeyValues);
  }
  KeyValues::deleteThis(this: modelKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x100327B0
// Name: public: virtual bool C_BaseAnimating::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseAnimating::Simulate(C_BaseAnimating *this)
{
  bool v2; // bl
  CStudioHdr *m_pStudioHdr; // edi

  v2 = !this->m_bIsStaticProp;
  if ( this->m_bInitModelEffects )
    C_BaseAnimating::DelayedInitModelEffects(this);
  if ( *(float *)(gpGlobals.m_Index + 16) != 0.0 )
  {
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr
      && m_pStudioHdr->m_pStudioHdr != nullptr
      && CStudioHdr::SequencesAvailable(this: this->m_pStudioHdr) )
    {
      if ( (m_pStudioHdr->m_pStudioHdr->flags & 0x100000) != 0 )
        v2 = false;
      else
        this->DoAnimationEvents(this, a2: m_pStudioHdr);
    }
  }
  if ( (this->m_fEffects & 8) != 0 )
    this->ResetLatched(this);
  if ( this->m_nSequence != -1 && this->m_pRagdoll != nullptr && !this->m_bClientSideRagdoll )
    C_BaseAnimating::ClearRagdoll(this);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10032880
// Name: void InitC_BaseAnimatingScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitC_BaseAnimatingScriptDesc()
{
  vgui::CTreeViewListControl *v0; // ecx
  ScriptFunctionBinding_t *v1; // esi
  ScriptFunctionBinding_t *v2; // eax

  if ( !bInitialized )
  {
    bInitialized = true;
    g_C_BaseAnimating_ScriptDesc.m_pszDescription = "Animating models client-side";
    g_C_BaseAnimating_ScriptDesc.m_pszScriptName = "C_BaseAnimating";
    g_C_BaseAnimating_ScriptDesc.m_pszClassname = "C_BaseAnimating";
    g_C_BaseAnimating_ScriptDesc.m_pBaseDesc = GetScriptDesc();
    g_C_BaseAnimating_ScriptDesc.pHelper = (IScriptInstanceHelper *)C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v0);
    v1 = &g_C_BaseAnimating_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                               this: &g_C_BaseAnimating_ScriptDesc.m_FunctionBindings,
                                                                               elem: g_C_BaseAnimating_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "Set the specified pose parameter to the specified value";
    v1->m_desc.m_pszScriptName = "SetPoseParameter";
    v1->m_desc.m_pszFunction = "ScriptSetPoseParameter";
    ScriptDeduceFunctionSignature<C_BaseAnimating *,C_BaseAnimating,void,char const *,float>(pDesc: &v1->m_desc);
    v1->m_pfnBinding = CMemberScriptBinding2<C_BaseAnimating *,void (__thiscall C_BaseAnimating::*)(char const *,float),void,char const *,float>::Call;
    v1->m_pFunction = C_BaseAnimating::ScriptSetPoseParameter;
    v1->m_flags = 1;
    v2 = &g_C_BaseAnimating_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                               this: &g_C_BaseAnimating_ScriptDesc.m_FunctionBindings,
                                                                               elem: g_C_BaseAnimating_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = "Ask whether the main sequence is done playing";
    v2->m_desc.m_pszScriptName = "IsSequenceFinished";
    v2->m_desc.m_pszFunction = "IsSequenceFinished";
    v2->m_desc.m_ReturnType = 6;
    v2->m_pfnBinding = CMemberScriptBinding0<C_BaseAnimating *,bool (__thiscall C_BaseAnimating::*)(void),bool>::Call;
    v2->m_pFunction = C_BaseAnimating::IsSequenceFinished;
    v2->m_flags = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100329B0
// Name: public: virtual void C_BaseAnimating::StandardBlendingRules(class CStudioHdr __near *,class Vector __near * const,class QuaternionAligned __near * const,float,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseAnimating::StandardBlendingRules(
        C_BaseAnimating *this@<ecx>,
        CBoneSetup *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CStudioHdr *hdr,
        Vector *pos,
        QuaternionAligned *q,
        float currentTime,
        int boneMask)
{
  void *v9; // esp
  bool v11; // zf
  int numlocalseq; // eax
  int v13; // eax
  int v14; // ecx
  const studiohdr_t *m_pStudioHdr; // edx
  int v16; // eax
  mstudioseqdesc_t *v17; // eax
  const QAngle *v18; // eax
  const Vector *v19; // [esp+18h] [ebp-111Ch]
  int flRealTime; // [esp+20h] [ebp-1114h]
  CIKContext v22; // [esp+38h] [ebp-10FCh] BYREF
  float v23[25]; // [esp+10A8h] [ebp-8Ch] BYREF
  float v24[4]; // [esp+110Ch] [ebp-28h] BYREF
  float cycle; // [esp+111Ch] [ebp-18h]
  int m_nSequence; // [esp+1120h] [ebp-14h]
  IBoneSetup v27[4]; // [esp+1124h] [ebp-10h] BYREF
  CBoneSetup *retaddr; // [esp+1134h] [ebp+0h]

  v27[1].m_pBoneSetup = a2;
  v27[2].m_pBoneSetup = retaddr;
  v9 = alloca(4344);
  if ( hdr != nullptr && CStudioHdr::SequencesAvailable(this: hdr) )
  {
    v11 = hdr->m_pVModel == nullptr;
    m_nSequence = this->m_nSequence;
    if ( v11 )
      numlocalseq = hdr->m_pStudioHdr->numlocalseq;
    else
      numlocalseq = CStudioHdr::GetNumSeq_Internal(this: hdr);
    if ( m_nSequence >= numlocalseq || this->m_nSequence == -1 )
      C_BaseAnimating::SetSequence(this, nSequence: 0);
    ((void (__thiscall *)(C_BaseAnimating *, CStudioHdr *, float *, int, int))this->GetPoseParameters)(
      a1: this,
      a2: hdr,
      a3: v23,
      a4: a3,
      a5: a4);
    cycle = this->m_flCycle.m_Val;
    if ( r_sequence_debug.m_pParent != nullptr )
      m_nSequence = r_sequence_debug.m_pParent->m_Value.m_nValue;
    else
      m_nSequence = 0;
    v13 = this->entindex(this: &this->IClientNetworkable);
    if ( m_nSequence == v13 )
    {
      v11 = hdr->m_pVModel == nullptr;
      v14 = this->m_nSequence;
      m_nSequence = v14;
      if ( v11 )
      {
        m_pStudioHdr = hdr->m_pStudioHdr;
        v16 = v14;
        if ( v14 < 0 || v14 >= m_pStudioHdr->numlocalseq )
          v16 = 0;
        v17 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v16 + m_pStudioHdr->localseqindex);
      }
      else
      {
        v17 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: v14);
        v14 = m_nSequence;
      }
      DevMsgRT(
        pMsg: "%8.4f : %30s(%d) : %5.3f : %4.2f\n",
        currentTime,
        (const char *)v17 + v17->szlabelindex,
        v14,
        cycle,
        1.0);
    }
    IBoneSetup::IBoneSetup(this: v27, pStudioHdr: hdr, boneMask, poseParameter: v23, pPoseDebugger: nullptr);
    IBoneSetup::InitPose(this: v27, pos, q);
    IBoneSetup::AccumulatePose(
      this: v27,
      pos,
      q,
      sequence: this->m_nSequence,
      cycle,
      flWeight: 1.0,
      flTime: currentTime,
      pIKContext: this->m_pIk);
    C_BaseAnimating::MaintainSequenceTransitions(this, boneSetup: v27, flCycle: cycle, pos, q);
    ((void (__thiscall *)(C_BaseAnimating *, IBoneSetup *, Vector *, QuaternionAligned *, _DWORD))this->AccumulateLayers)(
      a1: this,
      a2: v27,
      a3: pos,
      a4: q,
      a5: LODWORD(currentTime));
    CIKContext::CIKContext(this: &v22);
    flRealTime = *(_DWORD *)(gpGlobals.m_Index + 4);
    v19 = (const Vector *)((int (*)(void))this->GetRenderOrigin)();
    v18 = this->GetRenderAngles(this: &this->IClientRenderable);
    CIKContext::Init(
      this: &v22,
      pStudioHdr: hdr,
      angles: v18,
      pos: v19,
      flTime: currentTime,
      iFramecounter: flRealTime,
      boneMask);
    IBoneSetup::CalcAutoplaySequences(this: v27, pos, q, flRealTime: currentTime, pIKContext: &v22);
    if ( hdr->m_pStudioHdr->numbonecontrollers != 0 )
    {
      this->GetBoneControllers(this, a2: v24);
      IBoneSetup::CalcBoneAdj(this: v27, pos, q, controllers: v24);
    }
    C_BaseAnimating::UnragdollBlend(this, hdr, pos, q, currentTime);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v22.m_ikLock);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &v22.m_ikChainRule);
    v22.m_target.m_pElements = (CIKTarget *)&v22;
    v22.m_target.m_Size = 0;
    IBoneSetup::~IBoneSetup(this: v27);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032CE0
// Name: public: virtual class CStudioHdr __near * C_BaseAnimating::OnNewModel(void)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall C_BaseAnimating::OnNewModel(C_BaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // edi
  CJiggleBones *m_pJiggleBones; // edi
  CStudioHdr *v5; // eax
  CStudioHdr *v6; // ebx
  IVModelInfoClient_vtbl *v7; // edi
  const struct model_t *v8; // eax
  bool v9; // al
  CBoneMergeCache *m_pBoneMergeCache; // edi
  unsigned int v11; // ecx
  int v12; // edi
  const studiohdr_t *v13; // ecx
  matrix3x4a_t *m_pMemory; // eax
  CIKContext *m_pIk; // edi
  int m_Size; // edi
  int NumAttachments; // eax
  int v18; // edx
  int v19; // eax
  int NumPoseParameters; // eax
  int v21; // edi
  int v22; // edi
  int v23; // eax
  C_BaseAnimating_vtbl *v24; // edx
  int m_nValue; // edi
  int m_nSequence; // edi
  const char *SequenceName; // eax
  CStudioHdr *v28; // eax
  const char *Classname; // eax
  int numbones; // [esp+10h] [ebp-18h]
  const char *v31; // [esp+10h] [ebp-18h]
  float ctlValue; // [esp+20h] [ebp-8h] BYREF
  int boneControllerCount; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  C_BaseEntity::OnNewModel(this);
  this->m_bCanUseFastPath = false;
  if ( this->m_pStudioHdr != nullptr )
  {
    C_BaseAnimating::UnlockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr )
    {
      CStudioHdr::Term(this: this->m_pStudioHdr);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneParent);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneFlags);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
      C_BaseEntity::operator delete(pMem: m_pStudioHdr);
    }
    this->m_pStudioHdr = nullptr;
  }
  this->m_SequenceTransitioner.m_animationQueue.m_Size = 0;
  m_pJiggleBones = this->m_pJiggleBones;
  if ( m_pJiggleBones != nullptr )
  {
    CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_pJiggleBones->m_jiggleBoneState);
    if ( m_pJiggleBones->m_jiggleBoneState.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pJiggleBones->m_jiggleBoneState.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pJiggleBones->m_jiggleBoneState.m_Memory.m_pMemory);
        m_pJiggleBones->m_jiggleBoneState.m_Memory.m_pMemory = nullptr;
      }
      m_pJiggleBones->m_jiggleBoneState.m_Memory.m_nAllocationCount = 0;
    }
    C_BaseEntity::operator delete(pMem: m_pJiggleBones);
    this->m_pJiggleBones = nullptr;
  }
  if ( this->GetModel(this: &this->IClientRenderable) == nullptr )
    return nullptr;
  C_BaseAnimating::LockStudioHdr(this);
  C_BaseAnimating::UpdateRelevantInterpolatedVars(this);
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  v5 = this->m_pStudioHdr;
  if ( v5 == nullptr || v5->m_pStudioHdr == nullptr )
    return nullptr;
  v6 = this->m_pStudioHdr;
  this->m_bIsStaticProp = (v5->m_pStudioHdr->flags & 0x10) != 0;
  v7 = modelinfo->__vftable;
  v8 = this->GetModel(this: &this->IClientRenderable);
  v9 = v7->ModelHasMaterialProxy(this: modelinfo, a2: v8);
  m_pBoneMergeCache = this->m_pBoneMergeCache;
  v11 = g_iModelBoneCounter - 1;
  this->m_bCanUseFastPath = !v9;
  this->m_iMostRecentModelBoneCounter = v11;
  this->m_flLastBoneSetupTime = -3.4028235e38;
  if ( m_pBoneMergeCache != nullptr )
  {
    if ( m_pBoneMergeCache->m_BoneMergeBits.m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBoneMergeCache->m_BoneMergeBits.m_pInt);
    m_pBoneMergeCache->m_BoneMergeBits.m_pInt = nullptr;
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pBoneMergeCache->m_MergedBones);
    C_BaseEntity::operator delete(pMem: m_pBoneMergeCache);
    this->m_pBoneMergeCache = nullptr;
  }
  if ( this->m_CachedBoneData.m_Size != v6->m_pStudioHdr->numbones )
  {
    numbones = v6->m_pStudioHdr->numbones;
    this->m_CachedBoneData.m_Size = 0;
    CUtlVector<matrix3x4a_t,CUtlMemoryAligned<matrix3x4a_t,16>>::InsertMultipleBefore(
      this: &this->m_CachedBoneData,
      elem: 0,
      num: numbones);
    v12 = 0;
    if ( v6->m_pStudioHdr->numbones > 0 )
    {
      boneControllerCount = 0;
      do
      {
        SetIdentityMatrix(matrix: (matrix3x4_t *)((char *)this->m_CachedBoneData.m_Memory.m_pMemory + boneControllerCount));
        v13 = v6->m_pStudioHdr;
        boneControllerCount += 48;
        ++v12;
      }
      while ( v12 < v13->numbones );
    }
  }
  m_pMemory = this->m_CachedBoneData.m_Memory.m_pMemory;
  this->m_BoneAccessor.m_pAnimating = this;
  this->m_BoneAccessor.m_pBones = m_pMemory;
  m_pIk = this->m_pIk;
  if ( m_pIk != nullptr )
  {
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pIk->m_ikLock);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &m_pIk->m_ikChainRule);
    m_pIk->m_target.m_Size = 0;
    m_pIk->m_target.m_pElements = (CIKTarget *)m_pIk;
    C_BaseEntity::operator delete(pMem: m_pIk);
    this->m_pIk = nullptr;
  }
  m_Size = this->m_Attachments.m_Size;
  if ( m_Size != CStudioHdr::GetNumAttachments(this: v6) )
  {
    NumAttachments = CStudioHdr::GetNumAttachments(this: v6);
    this->m_Attachments.m_Size = 0;
    CUtlVector<CAttachmentData,CUtlMemory<CAttachmentData,int>>::InsertMultipleBefore(
      this: &this->m_Attachments,
      elem: 0,
      num: NumAttachments);
    v18 = 0;
    if ( this->m_Attachments.m_Size > 0 )
    {
      v19 = 0;
      do
      {
        *((_BYTE *)&this->m_Attachments.m_Memory.m_pMemory[v19] + 76) &= ~1u;
        *((_DWORD *)&this->m_Attachments.m_Memory.m_pMemory[v19] + 18) &= 0x80000000;
        ++v18;
        ++v19;
      }
      while ( v18 < this->m_Attachments.m_Size );
    }
  }
  NumPoseParameters = CStudioHdr::GetNumPoseParameters(this: v6);
  CInterpolatedVarArrayBase<float,1>::SetMaxCount(
    this: &this->m_iv_flPoseParameter,
    flCurrentTime: *(float *)(gpGlobals.m_Index + 12),
    newmax: NumPoseParameters);
  v21 = 0;
  if ( CStudioHdr::GetNumPoseParameters(this: v6) > 0 )
  {
    boneControllerCount = (int)this->m_flPoseParameter;
    do
    {
      this->m_iv_flPoseParameter.m_bLooping[v21] = CStudioHdr::pPoseParameter(this: v6, i: v21)->loop != 0.0;
      if ( this->index == -1 && v21 >= 0 )
      {
        Studio_SetPoseParameter(pStudioHdr: v6, iParameter: v21, flValue: 0.0, &ctlValue);
        *(float *)boneControllerCount = ctlValue;
      }
      boneControllerCount += 4;
      ++v21;
    }
    while ( v21 < CStudioHdr::GetNumPoseParameters(this: v6) );
  }
  boneControllerCount = v6->m_pStudioHdr->numbonecontrollers;
  if ( (unsigned int)boneControllerCount >= 4 )
    boneControllerCount = 4;
  CInterpolatedVarArrayBase<float,1>::SetMaxCount(
    this: &this->m_iv_flEncodedController,
    flCurrentTime: *(float *)(gpGlobals.m_Index + 12),
    newmax: boneControllerCount);
  v22 = 0;
  if ( boneControllerCount > 0 )
  {
    ctlValue = 0.0;
    do
    {
      this->m_iv_flEncodedController.m_bLooping[v22] = (*((_BYTE *)&v6->m_pStudioHdr->version
                                                        + v6->m_pStudioHdr->bonecontrollerindex
                                                        + LODWORD(ctlValue))
                                                      & 0x38) != 0;
      ((void (__thiscall *)(C_BaseAnimating *, int, _DWORD))this->SetBoneController)(a1: this, a2: v22, a3: 0);
      LODWORD(ctlValue) += 56;
      ++v22;
    }
    while ( v22 < boneControllerCount );
  }
  this->m_bInitModelEffects = true;
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  C_BaseAnimating::TermRopes(this);
  v23 = this->LookupAttachment(this: &this->IClientRenderable, a2: "eyes");
  v24 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  this->m_iEyeAttachment = v23;
  if ( v24->ShouldInterpolate(this) )
    C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_INTERPOLATE);
  if ( CStudioHdr::GetNumAttachments(this: v6) != 0 )
    this->m_iEFlags |= 0x40000u;
  if ( this->ShouldResetSequenceOnNewModel(this) && this->m_nSequence != 0 )
  {
    if ( r_debug_sequencesets.m_pParent != nullptr )
      m_nValue = r_debug_sequencesets.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue == this->entindex(this: &this->IClientNetworkable) )
    {
      m_nSequence = this->m_nSequence;
      if ( m_nSequence == -1 )
      {
        SequenceName = "Not Found!";
      }
      else
      {
        if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
          C_BaseAnimating::LockStudioHdr(this);
        v28 = this->m_pStudioHdr;
        if ( v28 != nullptr && v28->m_pStudioHdr != nullptr )
          SequenceName = GetSequenceName(pstudiohdr: v28, iSequence: m_nSequence);
        else
          SequenceName = "No model!";
      }
      v31 = SequenceName;
      Classname = C_BaseEntity::GetClassname(this);
      _Msg(a1: "%s : %s : SetSequence\n", Classname, v31);
    }
    this->m_nSequence = 0;
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 48);
    if ( this->m_bClientSideAnimation )
      C_BaseAnimating::ClientSideAnimationChanged(this);
    C_BaseAnimating::OnNewSequence(this, a2: (int)&savedregs);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10033200
// Name: public: virtual void C_BaseAnimating::ResetLatched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ResetLatched(C_BaseAnimating *this)
{
  CIKContext *m_pIk; // esi

  m_pIk = this->m_pIk;
  if ( m_pIk != nullptr )
  {
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pIk->m_ikLock);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &m_pIk->m_ikChainRule);
    m_pIk->m_target.m_Size = 0;
    m_pIk->m_target.m_pElements = (CIKTarget *)m_pIk;
    C_BaseEntity::operator delete(pMem: m_pIk);
    this->m_pIk = nullptr;
  }
  C_BaseEntity::ResetLatched(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033250
// Name: public: virtual C_BaseAnimating::~C_BaseAnimating(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::~C_BaseAnimating(C_BaseAnimating *this)
{
  unsigned int m_iMostRecentBoneSetupRequest; // eax
  int m_Size; // ecx
  int v4; // eax
  CIKContext *m_pIk; // edi
  CBoneMergeCache *m_pBoneMergeCache; // edi
  CStudioHdr *m_pStudioHdr; // edi
  CJiggleBones *m_pJiggleBones; // edi
  CNewParticleEffect *m_pObject; // eax
  matrix3x4a_t *m_pMemory; // eax
  CInterpolatedVarEntryBase<CRangeCheckedVar<float,-2,2,0>,0> *m_pElements; // eax

  m_iMostRecentBoneSetupRequest = this->m_iMostRecentBoneSetupRequest;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimating_vtbl *)&C_BaseAnimating::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseAnimating::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseAnimating::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseAnimating::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseAnimating::`vftable';
  if ( m_iMostRecentBoneSetupRequest == g_iPreviousBoneCounter )
  {
    m_Size = g_PreviousBoneSetups.m_Size;
    v4 = 0;
    if ( g_PreviousBoneSetups.m_Size > 0 )
    {
      while ( g_PreviousBoneSetups.m_Memory.m_pMemory[v4] != this )
      {
        if ( ++v4 >= g_PreviousBoneSetups.m_Size )
          goto LABEL_11;
      }
      if ( v4 != -1 && g_PreviousBoneSetups.m_Size > 0 )
      {
        if ( v4 != g_PreviousBoneSetups.m_Size - 1 )
        {
          g_PreviousBoneSetups.m_Memory.m_pMemory[v4] = g_PreviousBoneSetups.m_Memory.m_pMemory[g_PreviousBoneSetups.m_Size
                                                                                              - 1];
          m_Size = g_PreviousBoneSetups.m_Size;
        }
        g_PreviousBoneSetups.m_Size = m_Size - 1;
      }
    }
  }
LABEL_11:
  C_BaseAnimating::RemoveFromClientSideAnimationList(this);
  C_BaseAnimating::TermRopes(this);
  C_BaseEntity::operator delete(pMem: this->m_pRagdollInfo);
  m_pIk = this->m_pIk;
  if ( m_pIk != nullptr )
  {
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pIk->m_ikLock);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &m_pIk->m_ikChainRule);
    m_pIk->m_target.m_Size = 0;
    m_pIk->m_target.m_pElements = (CIKTarget *)m_pIk;
    C_BaseEntity::operator delete(pMem: m_pIk);
  }
  m_pBoneMergeCache = this->m_pBoneMergeCache;
  if ( m_pBoneMergeCache != nullptr )
  {
    if ( m_pBoneMergeCache->m_BoneMergeBits.m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBoneMergeCache->m_BoneMergeBits.m_pInt);
    m_pBoneMergeCache->m_BoneMergeBits.m_pInt = nullptr;
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pBoneMergeCache->m_MergedBones);
    C_BaseEntity::operator delete(pMem: m_pBoneMergeCache);
  }
  C_BaseAnimating::UnlockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    CStudioHdr::Term(this: this->m_pStudioHdr);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneParent);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneFlags);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
    C_BaseEntity::operator delete(pMem: m_pStudioHdr);
  }
  m_pJiggleBones = this->m_pJiggleBones;
  if ( m_pJiggleBones != nullptr )
  {
    CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_pJiggleBones->m_jiggleBoneState);
    if ( m_pJiggleBones->m_jiggleBoneState.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pJiggleBones->m_jiggleBoneState.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pJiggleBones->m_jiggleBoneState.m_Memory.m_pMemory);
        m_pJiggleBones->m_jiggleBoneState.m_Memory.m_pMemory = nullptr;
      }
      m_pJiggleBones->m_jiggleBoneState.m_Memory.m_nAllocationCount = 0;
    }
    C_BaseEntity::operator delete(pMem: m_pJiggleBones);
    this->m_pJiggleBones = nullptr;
  }
  m_pObject = this->m_ejectBrassEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)&this->m_ejectBrassEffect);
    this->m_ejectBrassEffect.m_pObject = nullptr;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Attachments);
  this->m_CachedBoneData.m_Size = 0;
  if ( this->m_CachedBoneData.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_CachedBoneData.m_Memory.m_pMemory;
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pMemory & 0xFFFFFFFC) - 4));
      this->m_CachedBoneData.m_Memory.m_pMemory = nullptr;
    }
    this->m_CachedBoneData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CachedBoneData.m_pElements = this->m_CachedBoneData.m_Memory.m_pMemory;
  CUtlMemoryAligned<matrix3x4a_t,16>::~CUtlMemoryAligned<matrix3x4a_t,16>(this: &this->m_CachedBoneData.m_Memory);
  this->m_iv_flCycle.__vftable = (CInterpolatedVar<CRangeCheckedVar<float,-2,2,0> >_vtbl *)&CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0>::`vftable';
  *(_DWORD *)&this->m_iv_flCycle.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_flCycle.m_bLooping);
  C_BaseEntity::operator delete(pMem: this->m_iv_flCycle.m_LastNetworkedValue);
  m_pElements = this->m_iv_flCycle.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value);
  this->m_iv_flCycle.m_VarHistory.m_pElements = nullptr;
  this->m_iv_flCycle.__vftable = (CInterpolatedVar<CRangeCheckedVar<float,-2,2,0> >_vtbl *)&IInterpolatedVar::`vftable';
  this->m_iv_flEncodedController.__vftable = (CInterpolatedVarArray<float,4>_vtbl *)&CInterpolatedVarArrayBase<float,1>::`vftable';
  CInterpolatedVarArrayBase<float,1>::ClearHistory(this: &this->m_iv_flEncodedController);
  C_BaseEntity::operator delete(pMem: this->m_iv_flEncodedController.m_bLooping);
  C_BaseEntity::operator delete(pMem: this->m_iv_flEncodedController.m_LastNetworkedValue);
  CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>::~CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>(this: &this->m_iv_flEncodedController.m_VarHistory);
  this->m_iv_flEncodedController.__vftable = (CInterpolatedVarArray<float,4>_vtbl *)&IInterpolatedVar::`vftable';
  this->m_iv_flPoseParameter.__vftable = (CInterpolatedVarArray<float,24>_vtbl *)&CInterpolatedVarArrayBase<float,1>::`vftable';
  CInterpolatedVarArrayBase<float,1>::ClearHistory(this: &this->m_iv_flPoseParameter);
  C_BaseEntity::operator delete(pMem: this->m_iv_flPoseParameter.m_bLooping);
  C_BaseEntity::operator delete(pMem: this->m_iv_flPoseParameter.m_LastNetworkedValue);
  CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>::~CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,1>>(this: &this->m_iv_flPoseParameter.m_VarHistory);
  this->m_iv_flPoseParameter.__vftable = (CInterpolatedVarArray<float,24>_vtbl *)&IInterpolatedVar::`vftable';
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_Ropes);
  if ( this->m_Ropes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Ropes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Ropes.m_Memory.m_pMemory);
      this->m_Ropes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Ropes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_mouth.m_nVoiceSources = 0;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SequenceTransitioner);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033590
// Name: public: C_ClientRagdoll::C_ClientRagdoll(bool,bool)
// Source: json
//------------------------------------------------------------------------------
C_ClientRagdoll *__thiscall C_ClientRagdoll::C_ClientRagdoll(C_ClientRagdoll *this, bool bRestoring, bool fullInit)
{
  CRagdoll *v4; // eax

  C_BaseAnimating::C_BaseAnimating(this);
  this->IPVSNotify::__vftable = (IPVSNotify_vtbl *)&IPVSNotify::`vftable';
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ClientRagdoll_vtbl *)&C_ClientRagdoll::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ClientRagdoll::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ClientRagdoll::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ClientRagdoll::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ClientRagdoll::`vftable'{for `C_BaseAnimating'};
  this->IPVSNotify::__vftable = (IPVSNotify_vtbl *)&C_ClientRagdoll::`vftable'{for `IPVSNotify'};
  this->m_iCurrentFriction = 0;
  this->m_iFrictionAnimState = -1;
  *(_WORD *)&this->m_bReleaseRagdoll = 0;
  *(_WORD *)&this->m_bFadeOut = 0;
  if ( fullInit )
  {
    C_BaseEntity::SetClassname(this, className: "client_ragdoll");
    if ( bRestoring )
    {
      v4 = (CRagdoll *)MemAlloc_Alloc(nSize: 0x3E4u);
      if ( v4 != nullptr )
      {
        this->m_pRagdoll = CRagdoll::CRagdoll(this: v4);
        return this;
      }
      this->m_pRagdoll = nullptr;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10033640
// Name: public: virtual int C_ClientRagdoll::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_ClientRagdoll::ObjectCaps(C_ClientRagdoll *this)
{
  return C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass((vgui::CTreeViewListControl *)this) | 0x400;
}

//------------------------------------------------------------------------------
// Address: 0x10033650
// Name: public: virtual class IPVSNotify __near * C_ClientRagdoll::GetPVSNotifyInterface(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_ClientRagdoll::GetPVSNotifyInterface(C_ClientRagdoll *this)
{
  if ( this == (C_ClientRagdoll *)4 )
    return nullptr;
  else
    return &this->m_vecRenderOriginOverride + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100336B0
// Name: public: virtual class C_ClientRagdoll __near * C_BaseAnimating::CreateClientRagdoll(bool)
// Source: json
//------------------------------------------------------------------------------
C_ClientRagdoll *__thiscall C_BaseAnimating::CreateClientRagdoll(C_BaseAnimating *this, bool bRestoring)
{
  C_ClientRagdoll *v2; // eax

  DevMsg(a1: "Creating ragdoll at tick %d\n", *(_DWORD *)(gpGlobals.m_Index + 24));
  v2 = (C_ClientRagdoll *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  if ( v2 != nullptr )
    return C_ClientRagdoll::C_ClientRagdoll(this: v2, bRestoring, fullInit: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100336F0
// Name: CC_ClientRagdollFactory
// Source: json
//------------------------------------------------------------------------------
C_ClientRagdoll *__cdecl CC_ClientRagdollFactory()
{
  C_ClientRagdoll *v0; // eax

  v0 = (C_ClientRagdoll *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  if ( v0 != nullptr )
    return C_ClientRagdoll::C_ClientRagdoll(this: v0, bRestoring: true, fullInit: true);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1015AB00
// Name: public: virtual void C_ClientRagdoll::SetupWeights(struct matrix3x4_t const __near *,int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ClientRagdoll::SetupWeights(
        C_ClientRagdoll *this,
        const matrix3x4_t *pBoneToWorld,
        int nFlexWeightCount,
        float *pFlexWeights,
        float *pFlexDelayedWeights)
{
  int v6; // eax
  CIKContext *m_pIk; // eax
  IVModelRender_vtbl *v8; // edi
  CStudioHdr *ModelPtr; // eax
  int v10; // [esp-4h] [ebp-58h]
  matrix3x4_t attToWorld; // [esp+Ch] [ebp-48h] BYREF
  Vector tmp; // [esp+3Ch] [ebp-18h] BYREF
  Vector local; // [esp+48h] [ebp-Ch] BYREF

  C_BaseEntity::PerformCustomPhysics(
    (vgui::MenuButton *)this,
    tx0: (int)pBoneToWorld,
    ty0: nFlexWeightCount,
    tx1: (int)pFlexWeights,
    ty1: (int)pFlexDelayedWeights);
  if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: (C_ClientRagdoll *)((char *)this - 4));
  v6 = *(_DWORD *)&this->m_nOldMuzzleFlashParity;
  if ( v6 != 0 && *(_DWORD *)v6 != 0 )
  {
    if ( *(_DWORD *)(*(_DWORD *)v6 + 260) != 0 )
    {
      memset(dst: (int)pFlexWeights, value: nullptr, count: 4 * nFlexWeightCount);
      if ( pFlexDelayedWeights != nullptr )
        memset(dst: (int)pFlexDelayedWeights, value: nullptr, count: 4 * nFlexWeightCount);
    }
    m_pIk = this->m_pIk;
    if ( (int)m_pIk > 0
      && ((unsigned __int8 (__thiscall *)(C_ClientRagdoll *, CIKContext *, matrix3x4_t *))this->Precache)(
           a1: this,
           a2: m_pIk,
           a3: &attToWorld) != 0 )
    {
      local.x = 1000.0;
      local.y = 0.0;
      local.z = 0.0;
      VectorTransform(in1: &local.x, in2: &attToWorld, out: &tmp.x);
      v8 = modelrender->__vftable;
      v10 = ((int (__thiscall *)(C_ClientRagdoll *, Vector *))this->GetAbsOrigin)(a1: this, a2: &tmp);
      ModelPtr = C_BaseAnimating::GetModelPtr(this: (C_ClientRagdoll *)((char *)this - 4));
      ((void (__thiscall *)(IVModelRender *, CStudioHdr *, int))v8->SetViewTarget)(
        a1: modelrender,
        a2: ModelPtr,
        a3: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AD30
// Name: public: struct CInterpolatedVarEntryBase<float,1> __near & CSimpleRingBuffer<struct CInterpolatedVarEntryBase<float,1>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CInterpolatedVarEntryBase<float,1> *__thiscall CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1>>::operator[](
        CSimpleRingBuffer<CInterpolatedVarEntryBase<float,1> > *this,
        int i)
{
  int v2; // eax
  int m_maxElement; // edx

  v2 = this->m_firstElement + i;
  m_maxElement = this->m_maxElement;
  if ( v2 >= m_maxElement )
    v2 -= m_maxElement;
  return &this->m_pElements[v2];
}

//------------------------------------------------------------------------------
// Address: 0x1015BB00
// Name: public: virtual void CInterpolatedVarArrayBase<float,1>::Setup(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::Setup(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        CRangeCheckedVar<float,-2,2,0> *pValue,
        unsigned __int8 type)
{
  this->m_pValue = pValue;
  this->m_fType = type;
}

//------------------------------------------------------------------------------
// Address: 0x1015BB20
// Name: public: virtual void CInterpolatedVarArrayBase<float,1>::SetInterpolationAmount(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInterpolatedVarArrayBase<float,1>::SetInterpolationAmount(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this,
        float seconds)
{
  this->m_InterpolationAmount = seconds;
}

//------------------------------------------------------------------------------
// Address: 0x1015BB70
// Name: public: virtual int CInterpolatedVarArrayBase<float,1>::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInterpolatedVarArrayBase<float,1>::GetType(
        CInterpolatedVarArrayBase<CRangeCheckedVar<float,-2,2,0>,0> *this)
{
  return this->m_fType;
}

//------------------------------------------------------------------------------
// Address: 0x10410560
// Name: DT_ServerAnimationData::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ServerAnimationData::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ServerAnimationData::g_RecvTable);
  return atexit(func: DT_ServerAnimationData::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410580
// Name: DT_ServerAnimationData::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ServerAnimationData::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ServerAnimationData::ignored>();
  DT_ServerAnimationData::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104105B0
// Name: DT_BaseAnimating::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimating::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseAnimating::g_RecvTable);
  return atexit(func: DT_BaseAnimating::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104105D0
// Name: DT_BaseAnimating::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimating::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseAnimating::ignored>();
  DT_BaseAnimating::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104105E0
// Name: C_BaseAnimating_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseAnimating_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseAnimating::m_PredMap.dataNumFields = 10;
  C_BaseAnimating::m_PredMap.dataDesc = (typedescription_t *)&unk_10598EC4;
}

//------------------------------------------------------------------------------
// Address: 0x10410630
// Name: C_ClientRagdoll_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_ClientRagdoll_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_ClientRagdoll>();
  C_ClientRagdoll_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410800
// Name: DT_BoneFollower::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BoneFollower::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BoneFollower::g_RecvTable);
  return atexit(func: DT_BoneFollower::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410820
// Name: DT_BoneFollower::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BoneFollower::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BoneFollower::ignored>();
  DT_BoneFollower::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042FA70
// Name: DT_ServerAnimationData::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ServerAnimationData::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ServerAnimationData::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA80
// Name: DT_BaseAnimating::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseAnimating::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseAnimating::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042FAF0
// Name: DT_BoneFollower::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BoneFollower::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BoneFollower::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100253E0
// Name: _C_BoneFollower_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BoneFollower_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_BoneFollower::`vftable'{for `IClientUnknown'};
  v3[1] = &C_BoneFollower::`vftable'{for `IClientRenderable'};
  v3[2] = &C_BoneFollower::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_BoneFollower::`vftable'{for `IClientThinkable'};
  v3[4] = &C_BoneFollower::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10410590
// Name: _dynamic_initializer_for____g_C_BaseAnimatingClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseAnimatingClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseAnimatingClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseAnimatingClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410600
// Name: _dynamic_initializer_for__g_Cclient_ragdollFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cclient_ragdollFoo__()
{
  CClassMap *ClassMap; // eax

  ClassMap = GetClassMap();
  return ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_ClientRagdoll *(__cdecl *)()))ClassMap->Add)(
           a1: ClassMap,
           a2: "client_ragdoll",
           a3: "C_ClientRagdoll",
           a4: 3416,
           a5: CC_ClientRagdollFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10410640
// Name: _dynamic_initializer_for__g_C_BaseAnimating_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_C_BaseAnimating_ScriptDesc__()
{
  InitC_BaseAnimatingScriptDesc();
  g_C_BaseAnimating_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_C_BaseAnimating_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_C_BaseAnimating_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x10410670
// Name: _dynamic_initializer_for__g_debug_ragdoll_visualize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_ragdoll_visualize__()
{
  ConVar::ConVar(
    this: &g_debug_ragdoll_visualize,
    pName: "g_debug_ragdoll_visualize",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_ragdoll_visualize__);
}

//------------------------------------------------------------------------------
// Address: 0x104106A0
// Name: _dynamic_initializer_for__g_ragdoll_fadespeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ragdoll_fadespeed__()
{
  ConVar::ConVar(this: &g_ragdoll_fadespeed, pName: "g_ragdoll_fadespeed", pDefaultValue: "600", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_ragdoll_fadespeed__);
}

//------------------------------------------------------------------------------
// Address: 0x104106D0
// Name: _dynamic_initializer_for__g_ragdoll_lvfadespeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ragdoll_lvfadespeed__()
{
  ConVar::ConVar(this: &g_ragdoll_lvfadespeed, pName: "g_ragdoll_lvfadespeed", pDefaultValue: "100", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_ragdoll_lvfadespeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10410700
// Name: _dynamic_initializer_for__g_PreviousBoneSetups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PreviousBoneSetups__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PreviousBoneSetups__);
}

//------------------------------------------------------------------------------
// Address: 0x10410710
// Name: _dynamic_initializer_for__g_BaseAnimatingGameSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BaseAnimatingGameSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_BaseAnimatingGameSystem, name: nullptr);
  g_BaseAnimatingGameSystem.__vftable = (C_BaseAnimatingGameSystem_vtbl *)&C_BaseAnimatingGameSystem::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_BaseAnimatingGameSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10410740
// Name: _dynamic_initializer_for__cl_threaded_bone_setup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_threaded_bone_setup__()
{
  ConVar::ConVar(
    this: &cl_threaded_bone_setup,
    pName: "cl_threaded_bone_setup",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable parallel processing of C_BaseAnimating::SetupBones()");
  return atexit(func: dynamic_atexit_destructor_for__cl_threaded_bone_setup__);
}

//------------------------------------------------------------------------------
// Address: 0x10410770
// Name: _dynamic_initializer_for__g_BoneAccessStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BoneAccessStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BoneAccessStack__);
}

//------------------------------------------------------------------------------
// Address: 0x10410780
// Name: _dynamic_initializer_for__r_drawothermodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawothermodels__()
{
  ConVar::ConVar(
    this: &r_drawothermodels,
    pName: "r_drawothermodels",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "0=Off, 1=Normal, 2=Wireframe");
  return atexit(func: dynamic_atexit_destructor_for__r_drawothermodels__);
}

//------------------------------------------------------------------------------
// Address: 0x104107B0
// Name: _dynamic_initializer_for__r_drawmodelstatsoverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawmodelstatsoverlay__()
{
  ConVar::ConVar(this: &r_drawmodelstatsoverlay, pName: "r_drawmodelstatsoverlay", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawmodelstatsoverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x104107E0
// Name: _dynamic_initializer_for____g_C_BoneFollowerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BoneFollowerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BoneFollowerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BoneFollowerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410830
// Name: _dynamic_initializer_for__C_BaseAnimating::m_recordingBoneList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBoneList *dynamic_initializer_for__C_BaseAnimating::m_recordingBoneList__()
{
  return CBoneList::CBoneList(this: &C_BaseAnimating::m_recordingBoneList);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA90
// Name: _dynamic_atexit_destructor_for__g_debug_ragdoll_visualize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_ragdoll_visualize__()
{
  ConVar::~ConVar(this: &g_debug_ragdoll_visualize);
}

//------------------------------------------------------------------------------
// Address: 0x1042FAA0
// Name: _dynamic_atexit_destructor_for__g_ragdoll_fadespeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ragdoll_fadespeed__()
{
  ConVar::~ConVar(this: &g_ragdoll_fadespeed);
}

//------------------------------------------------------------------------------
// Address: 0x1042FAB0
// Name: _dynamic_atexit_destructor_for__g_ragdoll_lvfadespeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ragdoll_lvfadespeed__()
{
  ConVar::~ConVar(this: &g_ragdoll_lvfadespeed);
}

//------------------------------------------------------------------------------
// Address: 0x1042FAC0
// Name: _dynamic_atexit_destructor_for__cl_threaded_bone_setup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_threaded_bone_setup__()
{
  ConVar::~ConVar(this: &cl_threaded_bone_setup);
}

//------------------------------------------------------------------------------
// Address: 0x1042FAD0
// Name: _dynamic_atexit_destructor_for__r_drawothermodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawothermodels__()
{
  ConVar::~ConVar(this: &r_drawothermodels);
}

//------------------------------------------------------------------------------
// Address: 0x1042FAE0
// Name: _dynamic_atexit_destructor_for__r_drawmodelstatsoverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawmodelstatsoverlay__()
{
  ConVar::~ConVar(this: &r_drawmodelstatsoverlay);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB00
// Name: _dynamic_atexit_destructor_for__g_BaseAnimatingGameSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BaseAnimatingGameSystem__()
{
  IGameSystem::~IGameSystem(this: &g_BaseAnimatingGameSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB10
// Name: _dynamic_atexit_destructor_for__g_ClientSideAnimationList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientSideAnimationList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ClientSideAnimationList);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB20
// Name: _dynamic_atexit_destructor_for__g_PreviousBoneSetups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PreviousBoneSetups__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PreviousBoneSetups);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB30
// Name: _dynamic_atexit_destructor_for__g_BoneAccessStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BoneAccessStack__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_BoneAccessStack);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB40
// Name: _DataMapInit_C_ClientRagdoll__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_ClientRagdoll__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB50
// Name: _dynamic_atexit_destructor_for__g_C_BaseAnimating_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_C_BaseAnimating_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_C_BaseAnimating_ScriptDesc.m_FunctionBindings);
}
