// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_sceneentity.cpp
// Functions: 43
// ============================================================

#include "game\client\c_sceneentity.h"

//------------------------------------------------------------------------------
// Address: 0x10033FC0
// Name: public: static void UtlVectorTemplate<class C_AnimationLayer,class CUtlMemory<class C_AnimationLayer,int>>::EnsureCapacity(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UtlVectorTemplate<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::EnsureCapacity(
        char *pStruct,
        int offsetToUtlVector,
        int len)
{
  CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::EnsureCapacity(
    this: (CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int> > *)&pStruct[offsetToUtlVector],
    num: len);
  memset(
    dst: *(_DWORD *)&pStruct[offsetToUtlVector] + 40 * *(_DWORD *)&pStruct[offsetToUtlVector + 12],
    value: nullptr,
    count: 40 * (*(_DWORD *)&pStruct[offsetToUtlVector + 4] - *(_DWORD *)&pStruct[offsetToUtlVector + 12]));
}

//------------------------------------------------------------------------------
// Address: 0x10087120
// Name: public: virtual class ClientClass __near * C_SceneEntity::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SceneEntity::GetClientClass(C_SceneEntity *this)
{
  return &__g_C_SceneEntityClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10087130
// Name: private: char const __near * C_SceneEntity::GetSceneFileName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_SceneEntity::GetSceneFileName(C_SceneEntity *this)
{
  const char *result; // eax
  int m_nSceneStringIndex; // [esp-4h] [ebp-8h]

  result = g_pStringTableClientSideChoreoScenes->GetString(
             this: g_pStringTableClientSideChoreoScenes,
             a2: this->m_nSceneStringIndex);
  if ( result == nullptr )
  {
    if ( bFirst )
    {
      m_nSceneStringIndex = this->m_nSceneStringIndex;
      bFirst = false;
      _Warning(a1: "GetSceneFilename() failed for scene index %d\n", m_nSceneStringIndex);
    }
    return prType;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10087180
// Name: public: virtual void C_SceneEntity::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::PreDataUpdate(C_SceneEntity *this, DataUpdateType_t updateType)
{
  C_BaseEntity::PreDataUpdate(this, updateType);
  LOBYTE(this->m_hActorList.m_Size) = *(&this->m_bIsBlurred + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100871A0
// Name: public: virtual void C_SceneEntity::DispatchEndSpeak(class CChoreoScene __near *,class C_BaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::DispatchEndSpeak(
        C_SceneEntity *this,
        CChoreoScene *scene,
        C_BaseFlex *actor,
        CChoreoEvent *event)
{
  if ( this->m_bClientOnly )
    C_BaseFlex::RemoveSceneEvent(this: actor, scene, event, fastKill: false);
}

//------------------------------------------------------------------------------
// Address: 0x100871D0
// Name: private: virtual void C_SceneEntity::DispatchStartSequence(class CChoreoScene __near *,class C_BaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::DispatchStartSequence(
        C_SceneEntity *this,
        CChoreoActor *scene,
        C_BaseFlex *actor,
        CChoreoEvent *event)
{
  bool v4; // al

  v4 = this->m_bClientOnly || this->m_bMultiplayer;
  C_BaseFlex::AddSceneEvent(this: actor, scene, event, pTarget: nullptr, bClientSide: v4, pSceneEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x10087210
// Name: private: virtual void C_SceneEntity::DispatchEndExpression(class CChoreoScene __near *,class C_BaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::DispatchEndExpression(
        C_SceneEntity *this,
        CChoreoScene *scene,
        C_BaseFlex *actor,
        CChoreoEvent *event)
{
  C_BaseFlex::RemoveSceneEvent(this: actor, scene, event, fastKill: false);
}

//------------------------------------------------------------------------------
// Address: 0x10087230
// Name: private: virtual void C_SceneEntity::DispatchStartGesture(class CChoreoScene __near *,class C_BaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::DispatchStartGesture(
        C_SceneEntity *this,
        CChoreoActor *scene,
        C_BaseFlex *actor,
        CChoreoEvent *event)
{
  char *Name; // eax
  bool v6; // al

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
  {
    v6 = this->m_bClientOnly || this->m_bMultiplayer;
    C_BaseFlex::AddSceneEvent(this: actor, scene, event, pTarget: nullptr, bClientSide: v6, pSceneEntity: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087290
// Name: private: virtual void C_SceneEntity::DispatchEndGesture(class CChoreoScene __near *,class C_BaseFlex __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::DispatchEndGesture(
        C_SceneEntity *this,
        CChoreoScene *scene,
        C_BaseFlex *actor,
        CChoreoEvent *event)
{
  char *Name; // eax

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
    C_BaseFlex::RemoveSceneEvent(this: actor, scene, event, fastKill: false);
}

//------------------------------------------------------------------------------
// Address: 0x100872D0
// Name: public: int mstudioseqdesc_t::anim(int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mstudioseqdesc_t::anim(mstudioseqdesc_t *this, int x, int y)
{
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // edx

  v3 = this->groupsize[0];
  v4 = x;
  if ( x >= v3 )
    v4 = v3 - 1;
  v5 = this->groupsize[1];
  v6 = y;
  if ( y >= v5 )
    v6 = v5 - 1;
  return *(__int16 *)((char *)&this->baseptr + 2 * v4 + 2 * v6 * v3 + this->animindexindex);
}

//------------------------------------------------------------------------------
// Address: 0x10087310
// Name: public: struct mstudioanimdesc_t __near & CStudioHdr::pAnimdesc(int)
// Source: json
//------------------------------------------------------------------------------
mstudioanimdesc_t *__thiscall CStudioHdr::pAnimdesc(CStudioHdr *this, int i)
{
  int v2; // edx
  const studiohdr_t *m_pStudioHdr; // ecx

  if ( this->m_pVModel != nullptr )
    return CStudioHdr::pAnimdesc_Internal(this, i);
  v2 = i;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( i < 0 || i >= m_pStudioHdr->numlocalanim )
    v2 = 0;
  return (mstudioanimdesc_t *)((char *)m_pStudioHdr + 100 * v2 + m_pStudioHdr->localanimindex);
}

//------------------------------------------------------------------------------
// Address: 0x10087350
// Name: void RecvProxy_ForcedClientTime(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_ForcedClientTime(const CRecvProxyData *pData, float *pStruct, float *pOut)
{
  *pOut = pData->m_Value.m_Float;
  pStruct[610] = pStruct[611];
}

//------------------------------------------------------------------------------
// Address: 0x10087370
// Name: private: bool C_SceneEntity::GetHWMorphSceneFileName(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_SceneEntity::GetHWMorphSceneFileName(C_SceneEntity *this, const char *pFilename, char *pHWMFilename)
{
  int m_nValue; // eax
  bool v5; // al
  const char *v6; // esi
  char szScene[260]; // [esp+4h] [ebp-208h] BYREF
  char szSceneHWM[260]; // [esp+108h] [ebp-104h] BYREF

  if ( mp_usehwmvcds.m_pParent != nullptr && (m_nValue = mp_usehwmvcds.m_pParent->m_Value.m_nValue) != 0 )
    v5 = m_nValue > 0;
  else
    v5 = g_pMaterialSystemHardwareConfig->HasFastVertexTextures(this: g_pMaterialSystemHardwareConfig);
  if ( !v5 || !this->m_bMultiplayer || pFilename == nullptr || *pFilename == 0 )
    return 0;
  if ( _V_strstr(s1: pFilename, search: "/high") != nullptr || _V_strstr(s1: pFilename, search: "\\high") != nullptr )
  {
    _V_strcpy(dest: pHWMFilename, src: pFilename);
    return 1;
  }
  else
  {
    _V_strcpy(dest: szScene, src: pFilename);
    szSceneHWM[0] = 0;
    v6 = strtok(string: szScene, control: "/\\");
    if ( v6 != nullptr )
    {
      while ( 1 )
      {
        if ( _V_stricmp(s1: v6, s2: "low") != 0 )
          V_strncat(pDest: szSceneHWM, pSrc: v6, destBufferSize: 0x104u, max_chars_to_copy: -1);
        else
          V_strncat(pDest: szSceneHWM, pSrc: "high", destBufferSize: 0x104u, max_chars_to_copy: -1);
        v6 = strtok(string: nullptr, control: "/\\");
        if ( v6 == nullptr )
          break;
        V_strncat(pDest: szSceneHWM, pSrc: "\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
      }
    }
    _V_strcpy(dest: pHWMFilename, src: szSceneHWM);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100874D0
// Name: private: void C_SceneEntity::DispatchProcessLoop(class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::DispatchProcessLoop(C_SceneEntity *this, CChoreoScene *scene, CChoreoEvent *event)
{
  char *Parameters; // eax
  int Count; // eax
  float backtime; // [esp+18h] [ebp+Ch]

  Parameters = CChoreoEvent::GetParameters(this: event);
  backtime = atof(nptr: Parameters);
  if ( CChoreoEvent::GetLoopCount(this: event) != -1 )
  {
    Count = CBaseAchievement::GetCount(this: event);
    if ( Count <= 0 )
      return;
    CChoreoEvent::SetNumLoopsRemaining(this: event, loops: Count - 1);
  }
  CChoreoScene::LoopToTime(this: scene, t: backtime);
  this->m_flCurrentTime = backtime;
  this->m_flForceClientTime = backtime;
}

//------------------------------------------------------------------------------
// Address: 0x10087540
// Name: public: virtual bool CChoreoStringPool::GetString(short,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoStringPool::GetString(CChoreoStringPool *this, int stringId, char *buff, int buffSize)
{
  char *v4; // eax

  v4 = (char *)scenefilecache->GetSceneString(this: scenefilecache, a2: stringId);
  if ( v4 != nullptr )
  {
    V_strncpy(pDest: buff, pSrc: v4, maxLen: buffSize);
    return 1;
  }
  else
  {
    V_strncpy(pDest: buff, pSrc: (char *)prType, maxLen: buffSize);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100875F0
// Name: public: virtual void C_SceneEntity::StopClientOnlyScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::StopClientOnlyScene(C_SceneEntity *this)
{
  CChoreoScene *m_pScene; // ecx
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  C_BaseFlex **v9; // eax

  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    CChoreoScene::ResetSimulation(this: m_pScene, forward: true, starttime: 0.0, endtime: 0.0);
    m_Index = this->m_hOwner.m_Index;
    if ( m_Index != -1 )
    {
      v4 = (unsigned __int16)m_Index;
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v6 = HIWORD(m_Index);
      if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
      {
        v7 = v4;
        v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
        v9 = (C_BaseFlex **)&g_pEntityList->m_EntPtrArray[v7];
        if ( v8 )
          C_BaseFlex::RemoveChoreoScene(this: *v9, scene: this->m_pScene);
        else
          C_BaseFlex::RemoveChoreoScene(this: nullptr, scene: this->m_pScene);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087680
// Name: private: class C_BaseFlex __near * C_SceneEntity::FindNamedActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_SceneEntity::FindNamedActor(C_SceneEntity *this, CChoreoActor *pChoreoActor)
{
  CChoreoScene *m_pScene; // ecx
  unsigned int m_Index; // edx
  int v6; // eax
  CEntInfo *v7; // esi
  unsigned int v8; // edx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  int ActorIndex; // eax

  m_pScene = this->m_pScene;
  if ( m_pScene == nullptr )
    return nullptr;
  m_Index = this->m_hOwner.m_Index;
  if ( m_Index != -1
    && (v6 = (unsigned __int16)m_Index,
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v8 = HIWORD(m_Index),
        v7->m_SerialNumber == v8)
    && v7->m_pEntity != nullptr )
  {
    v9 = v6;
    v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
    v11 = &g_pEntityList->m_EntPtrArray[v9];
    if ( v10 )
      return (C_BaseCombatWeapon *)v11->m_pEntity;
  }
  else
  {
    ActorIndex = CChoreoScene::FindActorIndex(this: m_pScene, actor: pChoreoActor);
    if ( ActorIndex >= 0 && ActorIndex < this->m_hActorList.m_Size )
      return CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hActorList.m_Memory.m_pMemory[ActorIndex]);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10087710
// Name: public: virtual void C_SceneEntity::EndEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::EndEvent(
        C_SceneEntity *this,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  char *Name; // eax
  C_BaseCombatWeapon *NamedActor; // edi
  CChoreoActor *Actor; // eax
  IClientModelRenderable_vtbl *v9; // edx
  C_SceneEntity *v10; // esi
  const char *v11; // eax
  char *Description; // eax
  int m_nSceneStringIndex; // [esp+Ch] [ebp-14h]
  const char *eventa; // [esp+30h] [ebp+10h]

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
  {
    NamedActor = nullptr;
    Actor = CChoreoEvent::GetActor(this: event);
    if ( Actor != nullptr )
      NamedActor = C_SceneEntity::FindNamedActor(this: (C_SceneEntity *)((char *)this - 2432), pChoreoActor: Actor);
    v9 = this->C_BaseEntity::IClientModelRenderable::__vftable;
    v10 = (C_SceneEntity *)((char *)this - 2432);
    v11 = g_pStringTableClientSideChoreoScenes->GetString(this: g_pStringTableClientSideChoreoScenes, a2: v9);
    if ( v11 != nullptr )
    {
      eventa = v11;
    }
    else
    {
      if ( bFirst )
      {
        m_nSceneStringIndex = v10->m_nSceneStringIndex;
        bFirst = false;
        _Warning(a1: "GetSceneFilename() failed for scene index %d\n", m_nSceneStringIndex);
      }
      eventa = prType;
    }
    Description = CChoreoEvent::GetDescription(this: event);
    Scene_Printf(pFormat: "%s : %8.2f:  finish %s\n", eventa, currenttime, Description);
    switch ( CChoreoEvent::GetType(this: event) )
    {
      case EXPRESSION:
        if ( NamedActor != nullptr )
          v10->DispatchEndExpression(this: v10, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
        break;
      case SPEAK:
        if ( LOBYTE(this->m_iClassname) != 0 && NamedActor != nullptr )
          v10->DispatchEndSpeak(this: v10, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
        break;
      case GESTURE:
        if ( NamedActor != nullptr )
          v10->DispatchEndGesture(this: v10, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
        break;
      case SEQUENCE:
        if ( NamedActor != nullptr )
          v10->DispatchEndSequence(this: v10, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
        break;
      case FLEXANIMATION:
        if ( NamedActor != nullptr )
          v10->DispatchEndFlexAnimation(this: v10, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087D50
// Name: private: void C_SceneEntity::ResetActorFlexesForScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::ResetActorFlexesForScene(C_SceneEntity *this)
{
  C_SceneEntity *v1; // esi
  int DetailModelCount; // eax
  int v3; // ecx
  CChoreoActor *Actor; // eax
  C_BaseCombatWeapon *NamedActor; // eax
  C_BaseFlex *v6; // edi
  CStudioHdr *m_pStudioHdr; // ebx
  LocalFlexController_t i; // esi
  int nActorCount; // [esp+10h] [ebp-Ch]
  int iActor; // [esp+18h] [ebp-4h]

  v1 = this;
  DetailModelCount = CDetailObjectSystem::GetDetailModelCount(this: this->m_pScene);
  v3 = 0;
  nActorCount = DetailModelCount;
  for ( iActor = 0; v3 < nActorCount; iActor = v3 )
  {
    Actor = CChoreoScene::GetActor(this: v1->m_pScene, actor: v3);
    if ( Actor != nullptr )
    {
      NamedActor = C_SceneEntity::FindNamedActor(this: v1, pChoreoActor: Actor);
      v6 = (C_BaseFlex *)NamedActor;
      if ( NamedActor != nullptr )
      {
        if ( NamedActor->m_pStudioHdr == nullptr
          && NamedActor->GetModel(this: &NamedActor->IClientRenderable) != nullptr )
        {
          C_BaseAnimating::LockStudioHdr(this: v6);
        }
        m_pStudioHdr = v6->m_pStudioHdr;
        if ( m_pStudioHdr != nullptr
          && m_pStudioHdr->m_pStudioHdr != nullptr
          && m_pStudioHdr->m_pStudioHdr->numflexdesc != 0 )
        {
          for ( i = DUMMY_NULL_FLEX_CONTROLLER; i < m_pStudioHdr->m_pStudioHdr->numflexcontrollers; ++i )
            C_BaseFlex::SetFlexWeight(this: v6, index: i, value: 0.0);
          ((void (__stdcall *)(_DWORD))v6->m_iv_flexWeight.Reset)(a1: *(_DWORD *)(gpGlobals.m_Index + 12));
          v1 = this;
        }
      }
    }
    v3 = iActor + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087E50
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087F80
// Name: public: static void UtlVectorTemplate<class CHandle<class C_BaseFlex>,class CUtlMemory<class CHandle<class C_BaseFlex>,int>>::EnsureCapacity(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UtlVectorTemplate<CHandle<C_BaseFlex>,CUtlMemory<CHandle<C_BaseFlex>,int>>::EnsureCapacity(
        char *pStruct,
        int offsetToUtlVector,
        int len)
{
  char *v3; // ebx
  void *v4; // edx
  void *v5; // eax
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // [esp-4h] [ebp-10h]

  v3 = &pStruct[offsetToUtlVector + 4];
  if ( *(_DWORD *)v3 < len && *(int *)&pStruct[offsetToUtlVector + 8] >= 0 )
  {
    v4 = *(void **)&pStruct[offsetToUtlVector];
    *(_DWORD *)v3 = len;
    v8 = 4 * len;
    if ( v4 != nullptr )
      v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v4, a3: v8);
    else
      v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v8);
    *(_DWORD *)&pStruct[offsetToUtlVector] = v5;
  }
  v6 = *(_DWORD *)&pStruct[offsetToUtlVector];
  v7 = *(_DWORD *)v3;
  *(_DWORD *)&pStruct[offsetToUtlVector + 16] = v6;
  memset(
    dst: v6 + 4 * *(_DWORD *)&pStruct[offsetToUtlVector + 12],
    value: nullptr,
    count: 4 * (v7 - *(_DWORD *)&pStruct[offsetToUtlVector + 12]));
}

//------------------------------------------------------------------------------
// Address: 0x100886A0
// Name: private: class CChoreoScene __near * C_SceneEntity::LoadScene(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoScene *__thiscall C_SceneEntity::LoadScene(C_SceneEntity *this, char *filename)
{
  CChoreoScene *result; // eax
  CChoreoScene *v4; // edi
  char *v5; // esi
  bool (__thiscall *GetSceneData)(ISceneFileCache *, const char *, unsigned __int8 *, unsigned int); // eax
  CChoreoScene *v7; // eax
  CChoreoScene *Scene; // esi
  IChoreoEventCallback *v9; // ebx
  IChoreoEventCallback *v10; // eax
  char loadfile[512]; // [esp+8h] [ebp-234h] BYREF
  CUtlBuffer buf; // [esp+208h] [ebp-34h] BYREF
  char *pBuffer; // [esp+238h] [ebp-4h]

  V_strncpy(pDest: loadfile, pSrc: filename, maxLen: 512);
  V_SetExtension(path: loadfile, extension: ".vcd", pathStringLength: 512);
  V_FixSlashes(pname: loadfile, separator: 92);
  result = (CChoreoScene *)scenefilecache->GetSceneBufferSize(this: scenefilecache, a2: loadfile);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = (char *)MemAlloc_Alloc(nSize: (unsigned int)result);
    GetSceneData = scenefilecache->GetSceneData;
    pBuffer = v5;
    if ( GetSceneData(this: scenefilecache, a2: filename, a3: (unsigned __int8 *)v5, a4: (unsigned int)v4) )
    {
      if ( IsBufferBinaryVCD(pBuffer: v5, bufferSize: (int)v4) )
      {
        v7 = (CChoreoScene *)MemAlloc_Alloc(nSize: 0x21Cu);
        if ( v7 != nullptr )
        {
          if ( this != nullptr )
            Scene = CChoreoScene::CChoreoScene(this: v7, callback: &this->IChoreoEventCallback);
          else
            Scene = CChoreoScene::CChoreoScene(this: v7, callback: nullptr);
        }
        else
        {
          Scene = nullptr;
        }
        CUtlBuffer::CUtlBuffer(this: &buf, pBuffer, nSize: (int)v4, nFlags: 8);
        if ( CChoreoScene::RestoreFromBinaryBuffer(
               this: Scene,
               &buf,
               filename: loadfile,
               pStringPool: &g_ChoreoStringPool) )
        {
          vgui::Panel::SetCursor(this: (vgui::Panel *)Scene, cursor: (unsigned int)Scene_Printf);
          if ( this != nullptr )
            v9 = &this->IChoreoEventCallback;
          else
            v9 = nullptr;
          CChoreoScene::SetEventCallbackInterface(this: Scene, callback: v9);
        }
        else
        {
          _Warning(a1: "Unable to restore binary scene '%s'\n", loadfile);
          if ( Scene != nullptr )
          {
            CChoreoScene::~CChoreoScene(this: Scene);
            C_BaseEntity::operator delete(pMem: Scene);
          }
          Scene = nullptr;
        }
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      }
      else
      {
        CSceneTokenProcessor::SetBuffer(
          this: (CTraceFilterSimple *)&g_TokenProcessor,
          pPassEntity: (const IHandleEntity *)v5);
        if ( this != nullptr )
          v10 = &this->IChoreoEventCallback;
        else
          v10 = nullptr;
        Scene = ChoreoLoadScene(
                  filename: loadfile,
                  callback: v10,
                  tokenizer: &g_TokenProcessor,
                  pfn: (void (*)(const char *, ...))Scene_Printf);
      }
      C_BaseEntity::operator delete(pMem: pBuffer);
      return Scene;
    }
    else
    {
      C_BaseEntity::operator delete(pMem: v5);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10088880
// Name: private: void C_SceneEntity::WipeQueuedEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::WipeQueuedEvents(C_SceneEntity *this)
{
  bool v2; // sf
  C_SceneEntity::QueuedEvents_t *m_pMemory; // ecx

  v2 = this->m_QueuedEvents.m_Memory.m_nGrowSize < 0;
  this->m_QueuedEvents.m_Size = 0;
  if ( v2 )
  {
    this->m_QueuedEvents.m_pElements = this->m_QueuedEvents.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_QueuedEvents.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_QueuedEvents.m_Memory.m_pMemory);
      this->m_QueuedEvents.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_QueuedEvents.m_Memory.m_pMemory;
    this->m_QueuedEvents.m_Memory.m_nAllocationCount = 0;
    this->m_QueuedEvents.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100888E0
// Name: public: C_SceneEntity::C_SceneEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_SceneEntity *__thiscall C_SceneEntity::C_SceneEntity(C_SceneEntity *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&IChoreoEventCallback::`vftable';
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SceneEntity_vtbl *)&C_SceneEntity::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SceneEntity::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SceneEntity::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SceneEntity::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SceneEntity::`vftable'{for `C_BaseEntity'};
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&C_SceneEntity::`vftable'{for `IChoreoEventCallback'};
  this->m_hActorList.m_Memory.m_pMemory = nullptr;
  this->m_hActorList.m_Memory.m_nAllocationCount = 0;
  this->m_hActorList.m_Memory.m_nGrowSize = 0;
  this->m_hActorList.m_Size = 0;
  this->m_hActorList.m_pElements = nullptr;
  this->m_QueuedEvents.m_Memory.m_pMemory = nullptr;
  this->m_QueuedEvents.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedEvents.m_Memory.m_nGrowSize = 0;
  this->m_QueuedEvents.m_Size = 0;
  this->m_QueuedEvents.m_pElements = nullptr;
  this->m_pScene = nullptr;
  this->m_bMultiplayer = false;
  this->m_hOwner.m_Index = -1;
  this->m_bClientOnly = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10088980
// Name: public: virtual void C_SceneEntity::DispatchStartSpeak(class CChoreoScene __near *,class C_BaseFlex __near *,class CChoreoEvent __near *,enum soundlevel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::DispatchStartSpeak(
        C_SceneEntity *this,
        CChoreoActor *scene,
        C_BaseFlex *actor,
        float event,
        float iSoundlevel)
{
  C_BasePlayer *LocalPlayer; // esi
  CChoreoEvent *v7; // esi
  double StartTime; // st7
  float v9; // xmm0_4
  char *Parameters; // eax
  IClientNetworkable_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  double v14; // st7
  double v15; // st7
  CChoreoEvent *v16; // xmm0_4
  CHud *Hud; // eax
  CHudCloseCaption *Element; // eax
  char lowercase[256]; // [esp+18h] [ebp-1A8h] BYREF
  char tok[64]; // [esp+118h] [ebp-A8h] BYREF
  CSingleUserRecipientFilter filter; // [esp+158h] [ebp-68h] BYREF
  EmitSound_t params; // [esp+178h] [ebp-48h] BYREF

  if ( this->m_bClientOnly && actor != nullptr )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    C_RecipientFilter::C_RecipientFilter(this: &filter);
    filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    C_RecipientFilter::AddRecipient(this: &filter, player: LocalPlayer);
    v7 = (CChoreoEvent *)LODWORD(event);
    StartTime = CChoreoEvent::GetStartTime(this: (CChoreoEvent *)LODWORD(event));
    v9 = *(float *)(gpGlobals.m_Index + 12);
    event = this->m_flCurrentTime - StartTime;
    params.m_hSoundScriptHandle = -1;
    params.m_pSoundName = nullptr;
    params.m_nFlags = 0;
    params.m_nPitch = 100;
    params.m_pOrigin = nullptr;
    params.m_pflSoundDuration = nullptr;
    *(_WORD *)&params.m_bWarnOnMissingCloseCaption = 0;
    params.m_nSpeakerEntity = -1;
    memset(&params.m_UtlVecSoundOrigin, 0, sizeof(params.m_UtlVecSoundOrigin));
    params.m_nSoundEntryVersion = 1;
    params.m_nChannel = 2;
    params.m_flVolume = 1.0;
    *(float *)&params.m_SoundLevel = iSoundlevel;
    params.m_flSoundTime = v9 - event;
    params.m_bEmitCloseCaption = false;
    Parameters = CChoreoEvent::GetParameters(this: v7);
    v11 = actor->C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable;
    params.m_pSoundName = Parameters;
    v12 = v11->entindex(this: &actor->IClientNetworkable);
    C_BaseEntity::EmitSound(&filter, iEntIndex: v12, &params);
    C_BaseFlex::AddSceneEvent(
      this: actor,
      scene,
      event: v7,
      pTarget: nullptr,
      bClientSide: this->m_bClientOnly,
      pSceneEntity: this);
    if ( CChoreoEvent::GetCloseCaptionType(this: v7) == CC_MASTER
      && CChoreoEvent::GetPlaybackCloseCaptionToken(this: v7, dest: tok, destlen: 64) != 0 )
    {
      CRC32_Init(pulCRC: (unsigned int *)&actor);
      V_strncpy(pDest: lowercase, pSrc: tok, maxLen: 256);
      _V_strlower(start: lowercase);
      v13 = _V_strlen(str: lowercase);
      CRC32_ProcessBuffer(pulCRC: (unsigned int *)&actor, pBuffer: lowercase, nBuffer: v13);
      CRC32_Final(pulCRC: (unsigned int *)&actor);
      iSoundlevel = CChoreoEvent::GetLastSlaveEndTime(this: v7);
      event = v7->GetDuration(this: v7);
      v14 = CChoreoEvent::GetStartTime(this: v7);
      v15 = iSoundlevel - v14;
      iSoundlevel = v15;
      if ( event <= v15 )
        v16 = (CChoreoEvent *)LODWORD(iSoundlevel);
      else
        v16 = (CChoreoEvent *)LODWORD(event);
      event = *(float *)&v16;
      Hud = GetHud(nSlot: 0);
      Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
      if ( Element != nullptr )
        CHudCloseCaption::ProcessCaption(
          this: Element,
          tokenname: lowercase,
          duration: event,
          fromplayer: false,
          direct: false);
    }
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&params.m_UtlVecSoundOrigin);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088B90
// Name: private: void C_SceneEntity::ClearSceneEvents(class CChoreoScene __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::ClearSceneEvents(C_SceneEntity *this, CChoreoScene *scene, BOOL canceled)
{
  int v4; // edi
  const char *v5; // eax
  CChoreoActor *Actor; // eax
  C_BaseFlex *NamedActor; // eax
  int m_nSceneStringIndex; // [esp+8h] [ebp-Ch]

  v4 = 0;
  if ( this->m_pScene != nullptr )
  {
    v5 = g_pStringTableClientSideChoreoScenes->GetString(
           this: g_pStringTableClientSideChoreoScenes,
           a2: this->m_nSceneStringIndex);
    if ( v5 == nullptr )
    {
      if ( bFirst )
      {
        m_nSceneStringIndex = this->m_nSceneStringIndex;
        bFirst = false;
        _Warning(a1: "GetSceneFilename() failed for scene index %d\n", m_nSceneStringIndex);
      }
      v5 = prType;
    }
    Scene_Printf(pFormat: "%s : %8.2f:  clearing events\n", v5, this->m_flCurrentTime);
    if ( CDetailObjectSystem::GetDetailModelCount(this: this->m_pScene) > 0 )
    {
      do
      {
        Actor = CChoreoScene::GetActor(this: this->m_pScene, actor: v4);
        NamedActor = (C_BaseFlex *)C_SceneEntity::FindNamedActor(this, pChoreoActor: Actor);
        if ( NamedActor != nullptr )
          C_BaseFlex::ClearSceneEvents(this: NamedActor, scene, canceled);
        ++v4;
      }
      while ( v4 < CDetailObjectSystem::GetDetailModelCount(this: this->m_pScene) );
    }
    this->m_QueuedEvents.m_Size = 0;
    if ( this->m_QueuedEvents.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_QueuedEvents.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_QueuedEvents.m_Memory.m_pMemory);
        this->m_QueuedEvents.m_Memory.m_pMemory = nullptr;
      }
      this->m_QueuedEvents.m_Memory.m_nAllocationCount = 0;
    }
    this->m_QueuedEvents.m_pElements = this->m_QueuedEvents.m_Memory.m_pMemory;
    this->m_flCurrentTime = this->m_flForceClientTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088CB0
// Name: private: void C_SceneEntity::UnloadScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::UnloadScene(C_SceneEntity *this)
{
  CChoreoScene *m_pScene; // eax
  int i; // edi
  CChoreoActor *Actor; // eax
  C_BaseFlex *NamedActor; // eax
  CChoreoScene *v6; // edi

  C_SceneEntity::WipeQueuedEvents(this);
  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    C_SceneEntity::ClearSceneEvents(this, scene: m_pScene, canceled: false);
    for ( i = 0; i < CDetailObjectSystem::GetDetailModelCount(this: this->m_pScene); ++i )
    {
      Actor = CChoreoScene::GetActor(this: this->m_pScene, actor: i);
      NamedActor = (C_BaseFlex *)C_SceneEntity::FindNamedActor(this, pChoreoActor: Actor);
      if ( NamedActor != nullptr )
        C_BaseFlex::RemoveChoreoScene(this: NamedActor, scene: this->m_pScene);
    }
  }
  v6 = this->m_pScene;
  if ( v6 != nullptr )
  {
    CChoreoScene::~CChoreoScene(this: this->m_pScene);
    C_BaseEntity::operator delete(pMem: v6);
  }
  this->m_pScene = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10088D40
// Name: private: void C_SceneEntity::QueueStartEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::QueueStartEvent(
        C_SceneEntity *this,
        unsigned int starttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  int m_Size; // esi
  int v5; // edx
  CChoreoEvent **p_event; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_QueuedEvents; // esi
  int v9; // edi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // ecx
  int v11; // eax
  int v12; // eax

  m_Size = this->m_QueuedEvents.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    m_nAllocationCount = this->m_QueuedEvents.m_Memory.m_nAllocationCount;
    p_m_QueuedEvents = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_QueuedEvents;
    v9 = this->m_QueuedEvents.m_Size;
    if ( v9 + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
        this: p_m_QueuedEvents,
        num: v9 - m_nAllocationCount + 1);
    ++p_m_QueuedEvents[1].m_pMemory;
    m_pMemory = p_m_QueuedEvents->m_pMemory;
    v11 = (int)p_m_QueuedEvents[1].m_pMemory - v9 - 1;
    p_m_QueuedEvents[1].m_nAllocationCount = (int)p_m_QueuedEvents->m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 12 * v11);
    v12 = (int)&p_m_QueuedEvents->m_pMemory[v9];
    if ( v12 != 0 )
    {
      *(_QWORD *)v12 = __PAIR64__((unsigned int)scene, starttime);
      *(_DWORD *)(v12 + 8) = event;
    }
  }
  else
  {
    p_event = &this->m_QueuedEvents.m_Memory.m_pMemory->event;
    while ( *(p_event - 1) != (CChoreoEvent *)scene || *p_event != event )
    {
      ++v5;
      p_event += 3;
      if ( v5 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088E70
// Name: public: static void UtlVectorTemplate<class CHandle<class C_BaseFlex>,class CUtlMemory<class CHandle<class C_BaseFlex>,int>>::ResizeUtlVector(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UtlVectorTemplate<CHandle<C_BaseFlex>,CUtlMemory<CHandle<C_BaseFlex>,int>>::ResizeUtlVector(
        char *pStruct,
        int offsetToUtlVector,
        int len)
{
  int *v3; // esi
  int v4; // eax
  int v5; // eax
  IMemAlloc_vtbl *v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // [esp-4h] [ebp-Ch]
  unsigned int v11; // [esp-4h] [ebp-Ch]

  v3 = (int *)&pStruct[offsetToUtlVector];
  v4 = *(_DWORD *)&pStruct[offsetToUtlVector + 12];
  if ( v4 >= len )
  {
    if ( v4 > len )
      v3[3] -= v4 - len;
  }
  else
  {
    CUtlVector<CHandle<C_BaseFlex>,CUtlMemory<CHandle<C_BaseFlex>,int>>::InsertMultipleBefore(
      this: (CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *)&pStruct[offsetToUtlVector],
      elem: v4,
      num: len - v4);
  }
  if ( v3[1] < len && v3[2] >= 0 )
  {
    v5 = *v3;
    v3[1] = len;
    v6 = _g_pMemAlloc->__vftable;
    v10 = 4 * len;
    if ( v5 != 0 )
      v7 = ((int (__stdcall *)(int, int))v6->Realloc_2)(a1: v5, a2: v10);
    else
      v7 = ((int (__stdcall *)(int))v6->Alloc_2)(a1: v10);
    *v3 = v7;
  }
  v8 = v3[3];
  v9 = *v3;
  v11 = 4 * (v3[1] - v8);
  v3[4] = *v3;
  memset(dst: v9 + 4 * v8, value: nullptr, count: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10088F70
// Name: public: virtual void C_SceneEntity::StartEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::StartEvent(
        C_SceneEntity *this,
        float currenttime,
        CChoreoScene *scene,
        CChoreoEvent *event)
{
  char *Name; // eax
  const char *v7; // eax
  const char *v8; // esi
  char *v9; // eax
  C_BaseCombatWeapon *NamedActor; // ebx
  CChoreoActor *Actor; // eax
  IClientModelRenderable_vtbl *v12; // edx
  C_SceneEntity *v13; // esi
  const char *v14; // eax
  char *Description; // eax
  const char *SceneFileName; // eax
  char *Parameters2; // eax
  int v18; // eax
  int m_nSceneStringIndex; // [esp+Ch] [ebp-14h]
  char *v20; // [esp+Ch] [ebp-14h]
  IClientModelRenderable_vtbl *v21; // [esp+10h] [ebp-10h]
  const char *eventa; // [esp+30h] [ebp+10h]

  Name = CChoreoEvent::GetName(this: event);
  if ( _V_stricmp(s1: Name, s2: "NULL") != 0 )
  {
    NamedActor = nullptr;
    Actor = CChoreoEvent::GetActor(this: event);
    if ( Actor == nullptr
      || (NamedActor = C_SceneEntity::FindNamedActor(this: (C_SceneEntity *)((char *)this - 2432), pChoreoActor: Actor)) != nullptr )
    {
      v12 = this->C_BaseEntity::IClientModelRenderable::__vftable;
      v13 = (C_SceneEntity *)((char *)this - 2432);
      v14 = g_pStringTableClientSideChoreoScenes->GetString(this: g_pStringTableClientSideChoreoScenes, a2: v12);
      if ( v14 != nullptr )
      {
        eventa = v14;
      }
      else
      {
        if ( bFirst )
        {
          m_nSceneStringIndex = v13->m_nSceneStringIndex;
          bFirst = false;
          _Warning(a1: "GetSceneFilename() failed for scene index %d\n", m_nSceneStringIndex);
        }
        eventa = prType;
      }
      Description = CChoreoEvent::GetDescription(this: event);
      Scene_Printf(pFormat: "%s : %8.2f:  start %s\n", eventa, currenttime, Description);
      if ( event != nullptr )
      {
        v20 = CChoreoEvent::GetDescription(this: event);
        SceneFileName = C_SceneEntity::GetSceneFileName(this: v13);
        BlackBox_Record(
          a1: (int)event,
          a2: (int)v13,
          type: "vcd",
          pFormat: "%s : %8.2f:  start %s",
          SceneFileName,
          currenttime,
          v20);
      }
      switch ( CChoreoEvent::GetType(this: event) )
      {
        case EXPRESSION:
          if ( NamedActor != nullptr )
            v13->DispatchStartExpression(this: v13, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
          break;
        case SPEAK:
          goto $LN5_11;
        case GESTURE:
          if ( NamedActor != nullptr )
            v13->DispatchStartGesture(this: v13, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
          break;
        case SEQUENCE:
          if ( NamedActor != nullptr )
            v13->DispatchStartSequence(this: v13, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
          break;
        case FLEXANIMATION:
          if ( NamedActor != nullptr )
            v13->DispatchStartFlexAnimation(this: v13, a2: scene, a3: (C_BaseFlex *)NamedActor, a4: event);
          break;
        case LOOP:
          C_SceneEntity::DispatchProcessLoop(this: v13, scene, event);
$LN5_11:
          if ( LOBYTE(this->m_iClassname) != 0 && NamedActor != nullptr )
          {
            if ( CChoreoEvent::GetParameters2(this: event) == nullptr
              || (Parameters2 = CChoreoEvent::GetParameters2(this: event), (v18 = atoi(nptr: Parameters2)) == 0) )
            {
              v18 = 80;
            }
            v13->DispatchStartSpeak(
              this: v13,
              a2: scene,
              a3: (C_BaseFlex *)NamedActor,
              a4: event,
              a5: (soundlevel_t)v18);
          }
          break;
        default:
          return;
      }
    }
    else
    {
      C_SceneEntity::QueueStartEvent(
        this: (C_SceneEntity *)((char *)this - 2432),
        starttime: LODWORD(currenttime),
        scene,
        event);
    }
  }
  else
  {
    v7 = g_pStringTableClientSideChoreoScenes->GetString(
           this: g_pStringTableClientSideChoreoScenes,
           a2: this->C_BaseEntity::IClientModelRenderable::__vftable);
    if ( v7 != nullptr )
    {
      v8 = v7;
    }
    else
    {
      if ( bFirst )
      {
        v21 = this->C_BaseEntity::IClientModelRenderable::__vftable;
        bFirst = false;
        _Warning(a1: "GetSceneFilename() failed for scene index %d\n", v21);
      }
      v8 = prType;
    }
    v9 = CChoreoEvent::GetDescription(this: event);
    Scene_Printf(pFormat: "%s : %8.2f:  ignored %s\n", v8, currenttime, v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089230
// Name: private: void C_SceneEntity::LoadSceneFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::LoadSceneFromFile(C_SceneEntity *this, char *filename)
{
  char szClientCmd[128]; // [esp+8h] [ebp-100h] BYREF
  char szSaveFileName[64]; // [esp+88h] [ebp-80h] BYREF
  char szVCDFileName[64]; // [esp+C8h] [ebp-40h] BYREF

  if ( scene_vcdautosave.m_pParent != nullptr && scene_vcdautosave.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !g_pFullFileSystem->IsDirectory(this: g_pFullFileSystem, a2: "SAVE\\faceposer", a3: "MOD") )
      g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: "SAVE\\faceposer", a3: "MOD");
    V_FileBase(in: filename, out: szVCDFileName, maxlen: 64);
    V_snprintf(pDest: szClientCmd, maxLen: 0x80u, pFormat: "save faceposer\\%s\n", szVCDFileName);
    V_snprintf(pDest: szSaveFileName, maxLen: 0x40u, pFormat: "SAVE\\faceposer\\%s.sav", szVCDFileName);
    if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szSaveFileName, a3: "MOD") )
      engine->ClientCmd(this: engine, a2: szClientCmd);
  }
  C_SceneEntity::UnloadScene(this);
  this->m_pScene = C_SceneEntity::LoadScene(this, filename);
}

//------------------------------------------------------------------------------
// Address: 0x100894D0
// Name: private: void C_SceneEntity::CheckQueuedEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::CheckQueuedEvents(C_SceneEntity *this)
{
  int m_Size; // edi
  C_SceneEntity::QueuedEvents_t *m_pMemory; // ebx
  int v4; // ecx
  C_SceneEntity::QueuedEvents_t *v5; // eoff
  int v6; // eax
  IChoreoEventCallback *v7; // edi
  CChoreoScene **p_scene; // esi
  CUtlVector<C_SceneEntity::QueuedEvents_t,CUtlMemory<C_SceneEntity::QueuedEvents_t,int> > events; // [esp+18h] [ebp-18h] BYREF
  int i; // [esp+2Ch] [ebp-4h]

  m_Size = this->m_QueuedEvents.m_Size;
  memset(&events, 0, sizeof(events));
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&events,
    elem: 0,
    num: m_Size);
  m_pMemory = events.m_Memory.m_pMemory;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &this->m_QueuedEvents.m_Memory.m_pMemory[v4];
      *(_QWORD *)&m_pMemory[v4].starttime = *(_QWORD *)&v5->starttime;
      m_pMemory[v4++].event = v5->event;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  v6 = events.m_Size;
  this->m_QueuedEvents.m_Size = 0;
  if ( v6 > 0 )
  {
    v7 = &this->IChoreoEventCallback;
    p_scene = &m_pMemory->scene;
    for ( i = v6; i != 0; --i )
    {
      ((void (__thiscall *)(IChoreoEventCallback *, _DWORD, CChoreoScene *, CChoreoScene *))v7->StartEvent)(
        a1: v7,
        a2: *(p_scene - 1),
        a3: *p_scene,
        a4: p_scene[1]);
      p_scene += 3;
    }
  }
  if ( events.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100895A0
// Name: public: virtual void C_SceneEntity::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::ClientThink(C_SceneEntity *this)
{
  char *v1; // esi
  C_SceneEntity *v2; // ecx

  v1 = (char *)this - 12;
  if ( this->m_hActorList.m_Size != 0 )
  {
    v2 = (C_SceneEntity *)((char *)this - 12);
    if ( v1[2436] != 0 )
    {
      C_SceneEntity::CheckQueuedEvents(this: v2);
      if ( v1[2437] == 0 )
      {
        CChoreoScene::Think(this: *((CChoreoScene **)v1 + 621), curtime: *((float *)v1 + 610));
        *((float *)v1 + 610) = *(float *)(gpGlobals.m_Index + 16) + *((float *)v1 + 610);
      }
    }
    else
    {
      C_SceneEntity::WipeQueuedEvents(this: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089610
// Name: private: void C_SceneEntity::PrefetchAnimBlocks(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::PrefetchAnimBlocks(C_SceneEntity *this, CChoreoScene *pScene)
{
  CChoreoScene *v2; // ebx
  int v3; // esi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v5; // edi
  CChoreoActor *Actor; // eax
  CChoreoActor *v7; // esi
  unsigned __int16 v8; // ax
  C_BaseFlex *NamedActor; // ebx
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // dx
  int v12; // ecx
  UtlRBTreeNode_t<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v14; // esi
  int v15; // edx
  CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t *p_m_Data; // esi
  char *Parameters; // eax
  int v18; // esi
  CStudioHdr *ModelPtr; // eax
  CStudioHdr *v20; // ebx
  mstudioseqdesc_t *v21; // esi
  bool v22; // cc
  int v23; // edi
  int v24; // ecx
  CChoreoEvent *v25; // edx
  int v26; // eax
  int v27; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  mstudioanimdesc_t *v29; // eax
  CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short> actorMap; // [esp+8h] [ebp-50h] BYREF
  CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t search; // [esp+24h] [ebp-34h] BYREF
  CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t insert; // [esp+2Ch] [ebp-2Ch] BYREF
  int iFrame; // [esp+34h] [ebp-24h] BYREF
  int iSequence; // [esp+38h] [ebp-20h]
  C_SceneEntity *v35; // [esp+3Ch] [ebp-1Ch]
  int i; // [esp+40h] [ebp-18h]
  int nResident; // [esp+44h] [ebp-14h]
  int nChecked; // [esp+48h] [ebp-10h]
  int j; // [esp+4Ch] [ebp-Ch] BYREF
  CChoreoEvent *pEvent; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = pScene;
  v3 = 0;
  v35 = this;
  if ( pScene != nullptr && this->m_bMultiplayer )
  {
    actorMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CChoreoActor *const *, CChoreoActor *const *))CDefOps<C_BaseEntity *>::LessFunc;
    memset(&actorMap.m_Tree.m_Elements, 0, sizeof(actorMap.m_Tree.m_Elements));
    *(_DWORD *)&actorMap.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&actorMap.m_Tree.m_FirstFree = -1;
    actorMap.m_Tree.m_pElements = nullptr;
    nResident = 0;
    nChecked = 0;
    i = 0;
    if ( CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)pScene) > 0 )
    {
      do
      {
        Event = CChoreoScene::GetEvent(this: v2, event: v3);
        v5 = Event;
        pEvent = Event;
        if ( Event != nullptr && (unsigned int)(CChoreoEvent::GetType(this: Event) - 6) <= 1 )
        {
          Actor = CChoreoEvent::GetActor(this: v5);
          v7 = Actor;
          if ( Actor != nullptr )
          {
            search.key = Actor;
            v8 = CUtlRBTree<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &actorMap.m_Tree,
                   &search);
            if ( v8 == 0xFFFF )
            {
              NamedActor = (C_BaseFlex *)C_SceneEntity::FindNamedActor(this: v35, pChoreoActor: v7);
              insert.key = v7;
              insert.elem = NamedActor;
              j = 0xFFFF;
              leftchild = false;
              CUtlRBTree<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
                this: &actorMap.m_Tree,
                &insert,
                parent: (unsigned __int16 *)&j,
                &leftchild);
              v10 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                      this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&actorMap,
                      a2: (const char *)v5);
              v11 = j;
              v12 = v10;
              m_pMemory = actorMap.m_Tree.m_Elements.m_pMemory;
              v14 = v12;
              actorMap.m_Tree.m_Elements.m_pMemory[v14].m_Right = -1;
              m_pMemory[v14].m_Left = -1;
              m_pMemory[v14].m_Tag = 0;
              m_pMemory[v14].m_Parent = v11;
              if ( v11 == 0xFFFF )
              {
                actorMap.m_Tree.m_Root = v12;
              }
              else
              {
                v15 = v11;
                if ( leftchild )
                  m_pMemory[v15].m_Left = v12;
                else
                  m_pMemory[v15].m_Right = v12;
              }
              CUtlRBTree<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
                this: &actorMap.m_Tree,
                elem: v12);
              ++actorMap.m_Tree.m_NumElements;
              v5 = pEvent;
              p_m_Data = &actorMap.m_Tree.m_Elements.m_pMemory[v14].m_Data;
              if ( p_m_Data != nullptr )
                *p_m_Data = insert;
            }
            else
            {
              NamedActor = actorMap.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
            }
            if ( NamedActor != nullptr )
            {
              Parameters = CChoreoEvent::GetParameters(this: v5);
              v18 = C_BaseAnimating::LookupSequence(this: NamedActor, label: Parameters);
              iSequence = v18;
              if ( v18 >= 0 )
              {
                ModelPtr = C_BaseAnimating::GetModelPtr(this: NamedActor);
                v20 = ModelPtr;
                if ( ModelPtr != nullptr )
                {
                  v21 = CStudioHdr::pSeqdesc(this: ModelPtr, iSequence: v18);
                  v22 = v21->groupsize[0] <= 0;
                  pEvent = nullptr;
                  if ( !v22 )
                  {
                    do
                    {
                      v23 = v21->groupsize[1];
                      v24 = 0;
                      for ( j = 0; v24 < v23; j = v24 )
                      {
                        v25 = pEvent;
                        v26 = v21->groupsize[0];
                        if ( (int)pEvent >= v26 )
                          v25 = (CChoreoEvent *)(v26 - 1);
                        if ( j >= v23 )
                          v24 = v23 - 1;
                        v27 = *(__int16 *)((char *)&v21->baseptr + 2 * ((_DWORD)v25 + v24 * v26) + v21->animindexindex);
                        if ( v20->m_pVModel != nullptr
                          && (v27 = CStudioHdr::iRelativeAnim_Internal(this: v20, baseseq: iSequence, relanim: v27),
                              v20->m_pVModel != nullptr) )
                        {
                          v29 = CStudioHdr::pAnimdesc_Internal(this: v20, i: v27);
                        }
                        else
                        {
                          m_pStudioHdr = v20->m_pStudioHdr;
                          if ( v27 < 0 || v27 >= m_pStudioHdr->numlocalanim )
                            v27 = 0;
                          v29 = (mstudioanimdesc_t *)((char *)m_pStudioHdr + 100 * v27 + m_pStudioHdr->localanimindex);
                        }
                        ++nChecked;
                        iFrame = 0;
                        if ( mstudioanimdesc_t::pAnim(this: v29, piFrame: &iFrame) != nullptr )
                          ++nResident;
                        v24 = j + 1;
                        v23 = v21->groupsize[1];
                      }
                      pEvent = (CChoreoEvent *)((char *)pEvent + 1);
                    }
                    while ( (int)pEvent < v21->groupsize[0] );
                  }
                }
              }
            }
            v2 = pScene;
          }
        }
        v3 = ++i;
      }
      while ( v3 < CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)v2) );
    }
    CUtlRBTree<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short,CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CChoreoActor *,C_BaseFlex *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &actorMap.m_Tree);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100898B0
// Name: public: virtual void C_SceneEntity::SetupClientOnlyScene(char const __near *,class C_BaseFlex __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::SetupClientOnlyScene(
        C_SceneEntity *this,
        const char *pszFilename,
        C_BaseFlex *pOwner,
        bool bMultiplayer)
{
  CChoreoScene *m_pScene; // ecx
  unsigned int m_Index; // ecx
  CChoreoScene *v7; // eax
  CChoreoScene *v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  C_BaseFlex *m_pEntity; // eax
  int i; // ebx
  unsigned int v13; // ecx
  C_BaseFlex **v14; // eax
  C_BaseFlex *v15; // edi
  CChoreoScene *v16; // eax
  CChoreoScene *v17; // ecx
  char szSceneHWM[128]; // [esp+18h] [ebp-120h] BYREF
  char szFilename[128]; // [esp+98h] [ebp-A0h] BYREF
  int types[6]; // [esp+118h] [ebp-20h] BYREF
  int typeList[2]; // [esp+130h] [ebp-8h] BYREF

  this->m_bIsPlayingBack = true;
  this->m_bMultiplayer = bMultiplayer;
  if ( pOwner != nullptr )
    this->m_hOwner.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
  else
    this->m_hOwner.m_Index = -1;
  this->m_bClientOnly = true;
  _V_strcpy(dest: szFilename, src: pszFilename);
  if ( C_SceneEntity::GetHWMorphSceneFileName(this, pFilename: szFilename, pHWMFilename: szSceneHWM) != 0 )
    _V_strcpy(dest: szFilename, src: szSceneHWM);
  if ( szFilename[0] != 0 )
  {
    C_SceneEntity::LoadSceneFromFile(this, filename: szFilename);
    m_pScene = this->m_pScene;
    if ( this->m_bMultiplayer )
    {
      if ( m_pScene != nullptr )
      {
        types[0] = 10;
        types[1] = 2;
        types[2] = 6;
        types[3] = 7;
        types[4] = 5;
        types[5] = 12;
        CChoreoScene::RemoveEventsExceptTypes(this: m_pScene, typeList: types, count: 6);
      }
      C_SceneEntity::PrefetchAnimBlocks(this, pScene: this->m_pScene);
    }
    else if ( m_pScene != nullptr )
    {
      typeList[0] = 10;
      typeList[1] = 2;
      CChoreoScene::RemoveEventsExceptTypes(this: m_pScene, typeList, count: 2);
    }
    ((void (__thiscall *)(C_SceneEntity *, int))this->SetNextClientThink)(a1: this, a2: -996040704);
  }
  m_Index = this->m_hOwner.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v7 = this->m_pScene;
    if ( v7 != nullptr )
    {
      C_SceneEntity::ClearSceneEvents(this, scene: v7, canceled: false);
      v8 = this->m_pScene;
      if ( this->m_bIsPlayingBack )
      {
        CChoreoScene::ResetSimulation(this: v8, forward: true, starttime: 0.0, endtime: 0.0);
        v9 = this->m_hOwner.m_Index;
        if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        {
          C_BaseFlex::StartChoreoScene(this: nullptr, scene: this->m_pScene);
          C_SceneEntity::ResetActorFlexesForScene(this);
        }
        else
        {
          C_BaseFlex::StartChoreoScene(
            this: (C_BaseFlex *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity,
            scene: this->m_pScene);
          C_SceneEntity::ResetActorFlexesForScene(this);
        }
      }
      else
      {
        CChoreoScene::ResetSimulation(this: v8, forward: true, starttime: 0.0, endtime: 0.0);
        v10 = this->m_hOwner.m_Index;
        if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          m_pEntity = nullptr;
        else
          m_pEntity = (C_BaseFlex *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
        C_BaseFlex::RemoveChoreoScene(this: m_pEntity, scene: this->m_pScene);
        C_SceneEntity::ResetActorFlexesForScene(this);
      }
    }
  }
  else
  {
    for ( i = 0; i < this->m_hActorList.m_Size; ++i )
    {
      v13 = this->m_hActorList.m_Memory.m_pMemory[i].m_Index;
      if ( v13 != -1 )
      {
        v14 = (C_BaseFlex **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v13];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber == HIWORD(v13) )
        {
          v15 = *v14;
          if ( *v14 != nullptr )
          {
            v16 = this->m_pScene;
            if ( v16 != nullptr )
            {
              C_SceneEntity::ClearSceneEvents(this, scene: v16, canceled: false);
              v17 = this->m_pScene;
              if ( this->m_bIsPlayingBack )
              {
                CChoreoScene::ResetSimulation(this: v17, forward: true, starttime: 0.0, endtime: 0.0);
                C_BaseFlex::StartChoreoScene(this: v15, scene: this->m_pScene);
              }
              else
              {
                CChoreoScene::ResetSimulation(this: v17, forward: true, starttime: 0.0, endtime: 0.0);
                C_BaseFlex::RemoveChoreoScene(this: v15, scene: this->m_pScene);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089BD0
// Name: public: virtual void C_SceneEntity::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SceneEntity::PostDataUpdate(C_SceneEntity *this, DataUpdateType_t updateType)
{
  const char *v3; // eax
  CChoreoScene *m_pElements; // ecx
  int i; // ebx
  unsigned int v6; // ecx
  C_BaseFlex **v7; // eax
  C_BaseFlex *v8; // edi
  CChoreoScene *v9; // eax
  CChoreoScene *v10; // ecx
  float endtime; // [esp+Ch] [ebp-238h]
  char szSceneHWM[260]; // [esp+1Ch] [ebp-228h] BYREF
  char szFilename[260]; // [esp+120h] [ebp-124h] BYREF
  int types[6]; // [esp+224h] [ebp-20h] BYREF
  int typeList[2]; // [esp+23Ch] [ebp-8h] BYREF

  C_BaseEntity::PostDataUpdate(this, updateType);
  v3 = g_pStringTableClientSideChoreoScenes->GetString(
         this: g_pStringTableClientSideChoreoScenes,
         a2: LODWORD(this->m_flCurrentTime));
  if ( v3 == nullptr )
  {
    if ( bFirst )
    {
      endtime = this->m_flCurrentTime;
      bFirst = false;
      _Warning(a1: "GetSceneFilename() failed for scene index %d\n", endtime);
    }
    v3 = prType;
  }
  _V_strcpy(dest: szFilename, src: v3);
  if ( C_SceneEntity::GetHWMorphSceneFileName(
         this: (C_SceneEntity *)((char *)this - 8),
         pFilename: szFilename,
         pHWMFilename: szSceneHWM) != 0 )
    _V_strcpy(dest: szFilename, src: szSceneHWM);
  if ( updateType == DATA_UPDATE_CREATED && szFilename[0] != 0 )
  {
    C_SceneEntity::LoadSceneFromFile(this: (C_SceneEntity *)((char *)this - 8), filename: szFilename);
    m_pElements = (CChoreoScene *)this->m_hActorList.m_pElements;
    if ( *(&this->m_bIsBlurred + 6) )
    {
      if ( m_pElements != nullptr )
      {
        types[0] = 10;
        types[1] = 2;
        types[2] = 6;
        types[3] = 7;
        types[4] = 5;
        types[5] = 12;
        CChoreoScene::RemoveEventsExceptTypes(this: m_pElements, typeList: types, count: 6);
      }
      C_SceneEntity::PrefetchAnimBlocks(
        this: (C_SceneEntity *)((char *)this - 8),
        pScene: (CChoreoScene *)this->m_hActorList.m_pElements);
    }
    else if ( m_pElements != nullptr )
    {
      typeList[0] = 10;
      typeList[1] = 2;
      CChoreoScene::RemoveEventsExceptTypes(this: m_pElements, typeList, count: 2);
    }
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 456))(a1: (char *)this - 8, a2: -996040704);
  }
  if ( LOBYTE(this->m_hActorList.m_Size) != *(&this->m_bIsBlurred + 4) )
  {
    for ( i = 0; i < this->m_hActorList.m_Memory.m_nAllocationCount; ++i )
    {
      v6 = *(_DWORD *)(*(_DWORD *)&this->m_bClientOnly + 4 * i);
      if ( v6 != -1 )
      {
        v7 = (C_BaseFlex **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v6];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6) )
        {
          v8 = *v7;
          if ( *v7 != nullptr )
          {
            v9 = (CChoreoScene *)this->m_hActorList.m_pElements;
            if ( v9 != nullptr )
            {
              C_SceneEntity::ClearSceneEvents(this: (C_SceneEntity *)((char *)this - 8), scene: v9, canceled: false);
              v10 = (CChoreoScene *)this->m_hActorList.m_pElements;
              if ( *(&this->m_bIsBlurred + 4) )
              {
                CChoreoScene::ResetSimulation(this: v10, forward: true, starttime: 0.0, endtime: 0.0);
                C_BaseFlex::StartChoreoScene(this: v8, scene: (CChoreoScene *)this->m_hActorList.m_pElements);
              }
              else
              {
                CChoreoScene::ResetSimulation(this: v10, forward: true, starttime: 0.0, endtime: 0.0);
                C_BaseFlex::RemoveChoreoScene(this: v8, scene: (CChoreoScene *)this->m_hActorList.m_pElements);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131F90
// Name: public: virtual short CChoreoStringPool::FindOrAddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoStringPool::FindOrAddString(C_BaseEntity *this, const char *pAttachmentName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104136C0
// Name: DT_SceneEntity::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SceneEntity::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SceneEntity::g_RecvTable);
  return atexit(func: DT_SceneEntity::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104136E0
// Name: DT_SceneEntity::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SceneEntity::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SceneEntity::ignored>();
  DT_SceneEntity::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430AC0
// Name: DT_SceneEntity::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SceneEntity::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SceneEntity::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10088F20
// Name: _C_SceneEntity_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SceneEntity_CreateObject(int entnum, int serialNum)
{
  C_SceneEntity *v2; // eax
  C_SceneEntity *v3; // eax
  C_SceneEntity *v4; // esi

  v2 = (C_SceneEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9D0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SceneEntity::C_SceneEntity(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104136F0
// Name: _dynamic_initializer_for__mp_usehwmvcds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_usehwmvcds__()
{
  ConVar::ConVar(
    this: &mp_usehwmvcds,
    pName: "mp_usehwmvcds",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable the use of the hw morph vcd(s). (-1 = never, 1 = always, 0 = based upon GPU)");
  return atexit(func: dynamic_atexit_destructor_for__mp_usehwmvcds__);
}

//------------------------------------------------------------------------------
// Address: 0x10430AD0
// Name: _dynamic_atexit_destructor_for__mp_usehwmvcds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_usehwmvcds__()
{
  ConVar::~ConVar(this: &mp_usehwmvcds);
}
