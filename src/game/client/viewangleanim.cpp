// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/viewangleanim.cpp
// Functions: 15
// ============================================================

#include "game\client\viewangleanim.h"

//------------------------------------------------------------------------------
// Address: 0x10193080
// Name: void ResetViewAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetViewAngles()
{
  QAngle angles; // [esp+0h] [ebp-Ch] BYREF

  angles = vec3_angle;
  engine->SetViewAngles(this: engine, a2: &angles);
}

//------------------------------------------------------------------------------
// Address: 0x101930B0
// Name: viewanim_create
// Source: json
//------------------------------------------------------------------------------
void __cdecl viewanim_create(const CCommand *args)
{
  C_BaseEntity *EntityByName; // eax
  CViewAngleAnimation *v2; // esi

  if ( g_pTestAnimation != nullptr )
  {
    ((void (__thiscall *)(CViewAngleAnimation *, int))g_pTestAnimation->dtr_IHandleEntity)(a1: g_pTestAnimation, a2: 1);
    g_pTestAnimation = nullptr;
  }
  if ( args->m_nArgc > 1 )
    atoi(nptr: args->m_ppArgv[1]);
  EntityByName = CreateEntityByName(className: "viewangleanim");
  v2 = (CViewAngleAnimation *)__RTDynamicCast(
                                inptr: EntityByName,
                                VfDelta: 0,
                                SrcType: &C_BaseEntity `RTTI Type Descriptor',
                                TargetType: &CViewAngleAnimation `RTTI Type Descriptor',
                                isReference: 0);
  if ( v2 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "viewangleanim");
  g_pTestAnimation = v2;
  if ( v2 != nullptr )
    v2->Spawn(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10193150
// Name: public: virtual void CViewAngleAnimation::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewAngleAnimation::Spawn(CViewAngleAnimation *this)
{
  QAngle angles; // [esp+Ch] [ebp-10h] BYREF
  CBaseHandle result; // [esp+18h] [ebp-4h] BYREF

  this->m_iFlags = 0;
  engine->GetViewAngles(this: engine, a2: &angles);
  this->m_bFinished = true;
  CBaseEntityList::AddNonNetworkableEntity(this: (CBaseEntityList *)cl_entitylist.m_Index, &result, pEnt: this);
  ((void (__thiscall *)(CViewAngleAnimation *, int))this->SetNextClientThink)(a1: this, a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x101931B0
// Name: private: void CViewAngleAnimation::SetAngles(class QAngle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewAngleAnimation::SetAngles(CViewAngleAnimation *this, QAngle vecCalculatedAngles)
{
  int m_iFlags; // eax
  float x; // xmm1_4
  float m_fValue; // xmm0_4
  QAngle vecViewAngle; // [esp+4h] [ebp-Ch] BYREF

  if ( (this->m_iFlags & 1) != 0 )
  {
    vecCalculatedAngles.x = this->m_vecBaseAngles.x + vecCalculatedAngles.x;
    vecCalculatedAngles.y = this->m_vecBaseAngles.y + vecCalculatedAngles.y;
    vecCalculatedAngles.z = this->m_vecBaseAngles.z + vecCalculatedAngles.z;
  }
  engine->GetViewAngles(this: engine, a2: &vecViewAngle);
  m_iFlags = this->m_iFlags;
  if ( (m_iFlags & 2) != 0 )
  {
    x = vecViewAngle.x;
  }
  else
  {
    x = vecCalculatedAngles.x;
    vecViewAngle.x = vecCalculatedAngles.x;
  }
  if ( (m_iFlags & 4) == 0 )
    vecViewAngle.y = vecCalculatedAngles.y;
  if ( (m_iFlags & 8) == 0 )
    vecViewAngle.z = vecCalculatedAngles.z;
  LODWORD(m_fValue) = LODWORD(cl_pitchup.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
  if ( m_fValue <= x )
  {
    if ( x <= cl_pitchdown.m_pParent->m_Value.m_fValue )
      m_fValue = x;
    else
      m_fValue = cl_pitchdown.m_pParent->m_Value.m_fValue;
  }
  vecViewAngle.x = m_fValue;
  engine->SetViewAngles(this: engine, a2: &vecViewAngle);
}

//------------------------------------------------------------------------------
// Address: 0x10193290
// Name: public: void CViewAngleAnimation::SaveAsAnimFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewAngleAnimation::SaveAsAnimFile(CViewAngleAnimation *this, const char *pKeyFrameFileName)
{
  KeyValues *v3; // eax
  int v4; // esi
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  KeyValues *NewKey; // edi
  CViewAngleKeyFrame *v8; // eax
  IBaseFileSystem *v9; // eax
  char buf[64]; // [esp+24h] [ebp-48h] BYREF
  int c; // [esp+64h] [ebp-8h]
  KeyValues *pData; // [esp+68h] [ebp-4h]

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v4 = 0;
  if ( v3 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v3, setName: pKeyFrameFileName);
    pData = v5;
  }
  else
  {
    pData = nullptr;
    v5 = nullptr;
  }
  KeyValues::SetInt(this: v5, keyName: "flags", value: this->m_iFlags);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    KeyValues::KeyValues(this: v6, setName: "keyframe");
  c = this->m_KeyFrames.m_Size;
  if ( c > 0 )
  {
    do
    {
      NewKey = KeyValues::CreateNewKey(this: v5);
      v8 = this->m_KeyFrames.m_Memory.m_pMemory[v4];
      V_snprintf(
        pDest: buf,
        maxLen: 0x40u,
        pFormat: "%f %f %f",
        v8->m_vecAngles.x,
        v8->m_vecAngles.y,
        v8->m_vecAngles.z);
      KeyValues::SetString(this: NewKey, keyName: "angles", value: buf);
      KeyValues::SetFloat(this: NewKey, keyName: "time", value: this->m_KeyFrames.m_Memory.m_pMemory[v4]->m_flTime);
      KeyValues::SetInt(this: NewKey, keyName: "flags", value: this->m_KeyFrames.m_Memory.m_pMemory[v4]->m_iFlags);
      v5 = pData;
      ++v4;
    }
    while ( v4 < c );
  }
  if ( filesystem != nullptr )
    v9 = &filesystem->IBaseFileSystem;
  else
    v9 = nullptr;
  KeyValues::SaveToFile(this: v5, filesystem: v9, resourceName: pKeyFrameFileName, pathID: nullptr);
  KeyValues::deleteThis(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101933E0
// Name: public: void CViewAngleAnimation::RunAnimation(class QAngle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewAngleAnimation::RunAnimation(CViewAngleAnimation *this, QAngle angles)
{
  CViewAngleKeyFrame **m_pMemory; // edx
  int m_iFlags; // eax

  if ( this->m_KeyFrames.m_Size != 0 )
  {
    this->m_flAnimStartTime = *(float *)(gpGlobals.m_Index + 12);
    this->m_bFinished = false;
    this->m_vecBaseAngles = angles;
    m_pMemory = this->m_KeyFrames.m_Memory.m_pMemory;
    m_iFlags = (*m_pMemory)->m_iFlags;
    this->m_iFlags = m_iFlags;
    if ( (m_iFlags & 1) == 0 )
      (*m_pMemory)->m_vecAngles = angles;
  }
  else
  {
    _Warning(a1: "CViewAngleAnimation::RunAnimation called on an empty view animation\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193470
// Name: public: virtual void CViewAngleAnimation::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewAngleAnimation::ClientThink(CViewAngleAnimation *this)
{
  float xmm1_4_2; // xmm1_4
  float xmm0_4_2; // xmm0_4
  CViewAngleKeyFrame **m_pMemory; // edi
  int v5; // esi
  _DWORD *v6; // eax
  float v7; // xmm2_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  int v11; // eax
  float v12; // xmm2_4
  float y; // eax
  int v14; // eax
  float x; // ecx
  float t; // xmm1_4
  int v17; // ecx
  float v18; // xmm0_4
  int v19; // eax
  float *v20; // ecx
  int v21; // eax
  Vector out; // [esp+18h] [ebp-54h] BYREF
  Vector v1; // [esp+24h] [ebp-48h] BYREF
  Vector v2; // [esp+30h] [ebp-3Ch] BYREF
  QAngle vecCalculatedAngles; // [esp+3Ch] [ebp-30h]
  Vector v0; // [esp+48h] [ebp-24h] BYREF
  Vector v3; // [esp+54h] [ebp-18h] BYREF
  float flCurrentTime; // [esp+60h] [ebp-Ch]
  int v29; // [esp+64h] [ebp-8h]
  float flTime; // [esp+68h] [ebp-4h]

  if ( this->m_bIsBlurred )
    return;
  xmm1_4_2 = *(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_CalcAbsoluteVelocityMutex.m_depth;
  xmm0_4_2 = 0.0;
  flCurrentTime = xmm1_4_2;
  if ( xmm1_4_2 < 0.0 )
  {
    xmm1_4_2 = 0.001;
    flCurrentTime = 0.001;
  }
  m_pMemory = this->m_KeyFrames.m_Memory.m_pMemory;
  v5 = 0;
  flTime = 0.0;
  if ( (int)m_pMemory < 4 )
  {
LABEL_12:
    if ( v5 >= (int)m_pMemory )
    {
LABEL_21:
      if ( v5 > 0 )
        CViewAngleAnimation::SetAngles(
          this: (CViewAngleAnimation *)((char *)this - 12),
          vecCalculatedAngles: *(QAngle *)*(_DWORD *)(*((_DWORD *)&this->m_bIsBlurred + 1) + 4 * v5 - 4));
      y = this->m_vecBaseAngles.y;
      if ( y != 0.0 )
        ((void (*)(void))LODWORD(y))();
      this->m_bIsBlurred = true;
      return;
    }
    v11 = *((_DWORD *)&this->m_bIsBlurred + 1) + 4 * v5;
    while ( 1 )
    {
      v12 = *(float *)(*(_DWORD *)v11 + 12) + xmm0_4_2;
      if ( v12 > xmm1_4_2 )
        break;
      ++v5;
      v11 += 4;
      xmm0_4_2 = v12;
      if ( v5 >= (int)m_pMemory )
      {
        flTime = v12;
        goto LABEL_21;
      }
    }
  }
  else
  {
    v6 = (_DWORD *)(*((_DWORD *)&this->m_bIsBlurred + 1) + 8);
    while ( 1 )
    {
      v7 = *(float *)(*(v6 - 2) + 12) + xmm0_4_2;
      if ( v7 > xmm1_4_2 )
        break;
      xmm0_4_2 = *(float *)(*(v6 - 2) + 12) + xmm0_4_2;
      v8 = *(float *)(*(v6 - 1) + 12) + v7;
      if ( v8 > xmm1_4_2 )
      {
        ++v5;
        break;
      }
      xmm0_4_2 = v8;
      v9 = *(float *)(*v6 + 12) + v8;
      if ( v9 > xmm1_4_2 )
      {
        v5 += 2;
        break;
      }
      xmm0_4_2 = v9;
      v10 = *(float *)(v6[1] + 12) + v9;
      if ( v10 > xmm1_4_2 )
      {
        v5 += 3;
        break;
      }
      v5 += 4;
      v6 += 4;
      xmm0_4_2 = v10;
      if ( v5 >= (int)m_pMemory - 3 )
      {
        flTime = v10;
        goto LABEL_12;
      }
    }
  }
  flTime = xmm0_4_2;
  if ( v5 >= (int)m_pMemory )
    goto LABEL_21;
  v14 = *((_DWORD *)&this->m_bIsBlurred + 1);
  v29 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * v5) + 16);
  x = this->m_vecBaseAngles.x;
  if ( v29 != LODWORD(x) )
  {
    if ( (v29 & 1) != 0 && (LOBYTE(x) & 1) == 0 )
    {
      engine->GetViewAngles(this: engine, a2: (QAngle *)&this->m_KeyFrames.m_Memory.m_nGrowSize);
      xmm0_4_2 = flTime;
      xmm1_4_2 = flCurrentTime;
    }
    v14 = *((_DWORD *)&this->m_bIsBlurred + 1);
    this->m_vecBaseAngles.x = *(float *)(*(_DWORD *)(v14 + 4 * v5) + 16);
  }
  t = (float)(xmm1_4_2 - xmm0_4_2) / *(float *)(*(_DWORD *)(v14 + 4 * v5) + 12);
  v17 = v5 - 2;
  if ( v5 - 2 > 0 )
  {
    v0.x = **(float **)(v14 + 4 * v17);
    v0.y = *(float *)(*(_DWORD *)(v14 + 4 * v17) + 4);
    v18 = *(float *)(*(_DWORD *)(v14 + 4 * v17) + 8);
  }
  else
  {
    v0.x = **(float **)(v14 + 4 * v5 - 4);
    v0.y = *(float *)(*(_DWORD *)(v14 + 4 * v5 - 4) + 4);
    v18 = *(float *)(*(_DWORD *)(v14 + 4 * v5 - 4) + 8);
  }
  v0.z = v18;
  v1 = *(Vector *)*(_DWORD *)(v14 + 4 * v5 - 4);
  v2 = *(Vector *)*(_DWORD *)(v14 + 4 * v5);
  if ( v5 + 1 < (int)m_pMemory )
  {
    v20 = *(float **)(v14 + 4 * v5 + 4);
    v21 = v14 + 4 * v5 + 4;
    v3.x = *v20;
    v3.y = *(float *)(*(_DWORD *)v21 + 4);
    v19 = *(_DWORD *)v21;
  }
  else
  {
    v3.x = **(float **)(v14 + 4 * v5);
    v3.y = *(float *)(*(_DWORD *)(v14 + 4 * v5) + 4);
    v19 = *(_DWORD *)(v14 + 4 * v5);
  }
  v3.z = *(float *)(v19 + 8);
  Catmull_Rom_Spline(p1: &v0, p2: &v1, p3: &v2, p4: &v3, t, output: &out);
  vecCalculatedAngles = (QAngle)out;
  CViewAngleAnimation::SetAngles(this: (CViewAngleAnimation *)((char *)this - 12), vecCalculatedAngles: (QAngle)out);
}

//------------------------------------------------------------------------------
// Address: 0x10193770
// Name: void TestViewAnim(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestViewAnim()
{
  QAngle angles; // [esp+0h] [ebp-Ch] BYREF

  if ( g_pTestAnimation != nullptr )
  {
    engine->GetViewAngles(this: engine, a2: &angles);
    CViewAngleAnimation::RunAnimation(this: g_pTestAnimation, angles);
  }
  else
  {
    _Msg(a1: "No view anim created\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101937D0
// Name: viewanim_save
// Source: json
//------------------------------------------------------------------------------
void __cdecl viewanim_save(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    if ( g_pTestAnimation != nullptr )
    {
      v1 = prType;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      CViewAngleAnimation::SaveAsAnimFile(this: g_pTestAnimation, pKeyFrameFileName: v1);
    }
    else
    {
      _Msg(a1: "No view anim created\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193810
// Name: public: CViewAngleAnimation::CViewAngleAnimation(void)
// Source: json
//------------------------------------------------------------------------------
CViewAngleAnimation *__thiscall CViewAngleAnimation::CViewAngleAnimation(CViewAngleAnimation *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (CViewAngleAnimation_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CViewAngleAnimation::`vftable';
  this->m_KeyFrames.m_Memory.m_pMemory = nullptr;
  this->m_KeyFrames.m_Memory.m_nAllocationCount = 0;
  this->m_KeyFrames.m_Memory.m_nGrowSize = 0;
  this->m_KeyFrames.m_Size = 0;
  this->m_KeyFrames.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10193860
// Name: public: virtual CViewAngleAnimation::~CViewAngleAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewAngleAnimation::~CViewAngleAnimation(CViewAngleAnimation *this)
{
  int v2; // edi

  v2 = this->m_KeyFrames.m_Size - 1;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (CViewAngleAnimation_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&CViewAngleAnimation::`vftable'{for `IClientThinkable'};
  for ( this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CViewAngleAnimation::`vftable';
        v2 >= 0;
        --v2 )
  {
    C_BaseEntity::operator delete(pMem: this->m_KeyFrames.m_Memory.m_pMemory[v2]);
  }
  this->m_KeyFrames.m_Size = 0;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_KeyFrames);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x101938C0
// Name: CCViewAngleAnimationFactory
// Source: json
//------------------------------------------------------------------------------
CViewAngleAnimation *__cdecl CCViewAngleAnimationFactory()
{
  CViewAngleAnimation *v0; // eax

  v0 = (CViewAngleAnimation *)C_BaseEntity::operator new(stAllocateBlock: 0x9B0u);
  if ( v0 != nullptr )
    return CViewAngleAnimation::CViewAngleAnimation(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10193910
// Name: viewanim_addkeyframe
// Source: json
//------------------------------------------------------------------------------
void __usercall viewanim_addkeyframe(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CCommand *args)
{
  int m_nArgc; // eax
  int v5; // edi
  const char *v6; // esi
  float *v7; // eax
  float v8; // xmm0_4
  float *v9; // edi
  CViewAngleAnimation *v10; // eax
  CViewAngleAnimation *v11; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CViewAngleKeyFrame **m_pMemory; // ecx
  int v15; // eax
  float **v16; // ebx
  QAngle vecTarget; // [esp+Ch] [ebp-10h] BYREF
  float flDelay; // [esp+18h] [ebp-4h]

  if ( g_pTestAnimation != nullptr )
  {
    ((void (__thiscall *)(IVEngineClient *, QAngle *, int, int, int))engine->GetViewAngles)(
      a1: engine,
      a2: &vecTarget,
      a3: a2,
      a4: a3,
      a5: a1);
    m_nArgc = args->m_nArgc;
    flDelay = 0.2;
    if ( m_nArgc > 1 )
      flDelay = atof(nptr: args->m_ppArgv[1]);
    v5 = 0;
    if ( args->m_nArgc > 1 )
    {
      if ( args->m_nArgc > 2 )
        v6 = args->m_ppArgv[2];
      else
        v6 = prType;
      v5 = (int)atof(nptr: v6);
    }
    v7 = (float *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v7 != nullptr )
    {
      *(QAngle *)v7 = vecTarget;
      v8 = flDelay;
      *((_DWORD *)v7 + 4) = v5;
      v7[3] = v8;
      v9 = v7;
    }
    else
    {
      v9 = nullptr;
    }
    v10 = g_pTestAnimation;
    *v9 = *v9 - g_pTestAnimation->m_vecBaseAngles.x;
    v9[1] = v9[1] - v10->m_vecBaseAngles.y;
    v9[2] = v9[2] - v10->m_vecBaseAngles.z;
    v11 = g_pTestAnimation;
    m_Size = g_pTestAnimation->m_KeyFrames.m_Size;
    m_nAllocationCount = g_pTestAnimation->m_KeyFrames.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_pTestAnimation->m_KeyFrames,
        num: m_Size - m_nAllocationCount + 1);
    ++v11->m_KeyFrames.m_Size;
    m_pMemory = v11->m_KeyFrames.m_Memory.m_pMemory;
    v15 = v11->m_KeyFrames.m_Size - m_Size - 1;
    v11->m_KeyFrames.m_pElements = m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
    v16 = (float **)&v11->m_KeyFrames.m_Memory.m_pMemory[m_Size];
    if ( v16 != nullptr )
      *v16 = v9;
  }
  else
  {
    _Msg(a1: "No view anim created, use viewanim_create");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193AA0
// Name: public: void CViewAngleAnimation::LoadViewAnimFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewAngleAnimation::LoadViewAnimFile(CViewAngleAnimation *this, char *pKeyFrameFileName)
{
  CViewAngleAnimation *v2; // edi
  int v3; // esi
  CUtlMemory<vgui::TreeNode *,int> *p_m_KeyFrames; // esi
  KeyValues *v5; // ebx
  KeyValues *v6; // eax
  IBaseFileSystem *v7; // eax
  KeyValues *FirstSubKey; // ebx
  char *String; // eax
  int Int; // ebx
  float *v11; // eax
  float v12; // xmm0_4
  float *v13; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v16; // ecx
  int v17; // eax
  float **v18; // edi
  QAngle angles; // [esp+1Ch] [ebp-18h] BYREF
  float flTime; // [esp+28h] [ebp-Ch]
  CViewAngleAnimation *i; // [esp+2Ch] [ebp-8h]
  KeyValues *pData; // [esp+30h] [ebp-4h]
  KeyValues *pKey; // [esp+3Ch] [ebp+8h]

  v2 = this;
  v3 = this->m_KeyFrames.m_Size - 1;
  for ( i = this; v3 >= 0; --v3 )
    C_BaseEntity::operator delete(pMem: v2->m_KeyFrames.m_Memory.m_pMemory[v3]);
  p_m_KeyFrames = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_KeyFrames;
  v5 = nullptr;
  v2->m_KeyFrames.m_Size = 0;
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v5 = KeyValues::KeyValues(this: v6, setName: pKeyFrameFileName);
  pData = v5;
  if ( filesystem != nullptr )
    v7 = &filesystem->IBaseFileSystem;
  else
    v7 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v5,
         filesystem: v7,
         resourceName: pKeyFrameFileName,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
    pKey = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        String = KeyValues::GetString(this: FirstSubKey, keyName: "angles", defaultValue: "0 0 0");
        sscanf(string: String, format: "%f %f %f", &angles, &angles.y, &angles.z);
        flTime = KeyValues::GetFloat(this: FirstSubKey, keyName: "time", defaultValue: 0.001);
        Int = KeyValues::GetInt(this: FirstSubKey, keyName: "flags", defaultValue: 0);
        v11 = (float *)MemAlloc_Alloc(nSize: 0x14u);
        if ( v11 != nullptr )
        {
          *(QAngle *)v11 = angles;
          v12 = flTime;
          *((_DWORD *)v11 + 4) = Int;
          v11[3] = v12;
          v13 = v11;
        }
        else
        {
          v13 = nullptr;
        }
        *v13 = *v13 - v2->m_vecBaseAngles.x;
        v13[1] = v13[1] - v2->m_vecBaseAngles.y;
        v13[2] = v13[2] - v2->m_vecBaseAngles.z;
        m_pMemory = p_m_KeyFrames[1].m_pMemory;
        m_nAllocationCount = p_m_KeyFrames->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_KeyFrames, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_KeyFrames[1].m_pMemory;
        v16 = p_m_KeyFrames->m_pMemory;
        v17 = (char *)p_m_KeyFrames[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_KeyFrames[1].m_nAllocationCount = (int)p_m_KeyFrames->m_pMemory;
        if ( v17 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v16[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v16[(_DWORD)m_pMemory],
            count: 4 * v17);
        v18 = (float **)&p_m_KeyFrames->m_pMemory[(_DWORD)m_pMemory];
        if ( v18 != nullptr )
          *v18 = v13;
        pKey = KeyValues::GetNextKey(this: pKey);
        if ( pKey == nullptr )
          break;
        FirstSubKey = pKey;
        v2 = i;
      }
    }
    KeyValues::deleteThis(this: pData);
  }
  else
  {
    _Warning(a1: "CViewAngleAnimation::LoadViewAnimFile failed to load script %s\n", pKeyFrameFileName);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193CB0
// Name: viewanim_load
// Source: json
//------------------------------------------------------------------------------
void __cdecl viewanim_load(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    if ( g_pTestAnimation != nullptr )
    {
      v1 = prType;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      CViewAngleAnimation::LoadViewAnimFile(this: g_pTestAnimation, pKeyFrameFileName: v1);
    }
    else
    {
      _Msg(a1: "No view anim created\n");
    }
  }
}
