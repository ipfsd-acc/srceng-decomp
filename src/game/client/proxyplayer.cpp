// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/proxyplayer.cpp
// Functions: 25
// ============================================================

#include "game\client\proxyplayer.h"

//------------------------------------------------------------------------------
// Address: 0x10158930
// Name: public: virtual bool CPlayerProximityProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPlayerProximityProxy::Init(CPlayerProximityProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  char result; // al

  result = CResultProxy::Init(this, pMaterial, pKeyValues);
  if ( result != 0 )
  {
    this->m_Factor = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 0.0020000001);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158980
// Name: public: virtual bool CPlayerTeamMatchProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerTeamMatchProxy::Init(CPlayerTeamMatchProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  return CResultProxy::Init(this, pMaterial, pKeyValues) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101589A0
// Name: public: virtual void CPlayerTeamMatchProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerTeamMatchProxy::OnBind(CPlayerTeamMatchProxy *this, int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  C_BaseEntity *v3; // esi
  C_BasePlayer *LocalPlayer; // eax
  int v5; // ebx
  double v6; // xmm0_8

  if ( pC_BaseEntity != nullptr )
  {
    v3 = CResultProxy::BindArgToEntity(this, pArg: pC_BaseEntity);
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      v5 = LocalPlayer->GetTeamNumber(this: LocalPlayer);
      if ( v3->GetTeamNumber(this: v3) == v5 )
        v6 = 1.0;
      else
        v6 = 0.0;
      CResultProxy::SetFloatResult(this, result: COERCE_INT(v6));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158A10
// Name: public: virtual bool CPlayerViewProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPlayerViewProxy::Init(CPlayerViewProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  char result; // al

  result = CResultProxy::Init(this, pMaterial, pKeyValues);
  if ( result != 0 )
  {
    this->m_Factor = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 2.0);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158A60
// Name: public: virtual bool CPlayerPositionProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPlayerPositionProxy::Init(CPlayerPositionProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  char result; // al

  result = CResultProxy::Init(this, pMaterial, pKeyValues);
  if ( result != 0 )
  {
    this->m_Factor = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 0.0049999999);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158AB0
// Name: public: virtual void CPlayerLogoProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLogoProxy::OnBind(CPlayerLogoProxy *this, void *pC_BaseEntity)
{
  if ( (int)pC_BaseEntity > 0
    && (int)pC_BaseEntity <= *(_DWORD *)(gpGlobals.m_Index + 20)
    && this->m_pBaseTextureVar != nullptr )
  {
    this->OnLogoBindInternal(this, a2: (int)pC_BaseEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158AF0
// Name: public: virtual void CPlayerLogoOnModelProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLogoOnModelProxy::OnBind(
        CPlayerLogoOnModelProxy *this,
        int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  int v3; // eax
  int v4; // eax
  C_BaseEntity *RootMoveParent; // esi
  int v6; // eax

  if ( pC_BaseEntity != nullptr )
  {
    v3 = (**pC_BaseEntity)(a1: pC_BaseEntity);
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 28))(a1: v3);
    RootMoveParent = (C_BaseEntity *)v4;
    if ( v4 != 0 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 584))(a1: v4) == 0 )
        RootMoveParent = C_BaseEntity::GetRootMoveParent(this: RootMoveParent);
      if ( RootMoveParent != nullptr && RootMoveParent->IsPlayer(this: RootMoveParent) )
      {
        v6 = RootMoveParent->entindex(this: &RootMoveParent->IClientNetworkable);
        this->OnLogoBindInternal(this, a2: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158B60
// Name: public: virtual void CPlayerProximityProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerProximityProxy::OnBind(CPlayerProximityProxy *this, int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  C_BasePlayer *LocalPlayer; // eax
  float *v4; // esi
  float *v5; // eax
  C_BaseEntity *v6; // [esp+30h] [ebp-10h]

  if ( pC_BaseEntity != nullptr )
  {
    v6 = CResultProxy::BindArgToEntity(this, pArg: pC_BaseEntity);
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      v4 = (float *)LocalPlayer->WorldSpaceCenter(this: LocalPlayer);
      v5 = (float *)v6->WorldSpaceCenter(this: v6);
      CResultProxy::SetFloatResult(
        this,
        result: COERCE_INT(
          this->m_Factor
        * fsqrt(
            (float)((float)((float)(v5[1] - v4[1]) * (float)(v5[1] - v4[1]))
                  + (float)((float)(v5[2] - v4[2]) * (float)(v5[2] - v4[2])))
          + (float)((float)(*v5 - *v4) * (float)(*v5 - *v4)))));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158C20
// Name: CCPlayerProximityProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPlayerProximityProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x10u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CPlayerProximityProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10158C50
// Name: CCPlayerTeamMatchProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPlayerTeamMatchProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0xCu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CPlayerTeamMatchProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10158C80
// Name: public: virtual void CPlayerViewProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerViewProxy::OnBind(CPlayerViewProxy *this, C_BaseEntity *pC_BaseEntity)
{
  C_BasePlayer *LocalPlayer; // esi
  float *v4; // edi
  float *v5; // eax
  const QAngle *v6; // eax
  Vector forward; // [esp+10h] [ebp-18h] BYREF
  Vector delta; // [esp+1Ch] [ebp-Ch] BYREF
  C_BaseEntity *pEntity; // [esp+30h] [ebp+8h]

  if ( pC_BaseEntity != nullptr )
  {
    pEntity = CResultProxy::BindArgToEntity(this, pArg: pC_BaseEntity);
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      v4 = (float *)LocalPlayer->WorldSpaceCenter(this: LocalPlayer);
      v5 = (float *)pEntity->WorldSpaceCenter(this: pEntity);
      delta.x = *v5 - *v4;
      delta.y = v5[1] - v4[1];
      delta.z = v5[2] - v4[2];
      VectorNormalize(vec: &delta);
      v6 = LocalPlayer->GetAbsAngles(this: LocalPlayer);
      AngleVectors(angles: v6, &forward);
      CResultProxy::SetFloatResult(
        this,
        result: COERCE_INT(
          (float)((float)((float)(forward.x * delta.x) + (float)(forward.y * delta.y)) + (float)(forward.z * delta.z))
        * this->m_Factor));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158D60
// Name: CCPlayerViewProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPlayerViewProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x10u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CPlayerViewProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10158D90
// Name: public: virtual void CPlayerSpeedProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerSpeedProxy::OnBind(CPlayerSpeedProxy *this, void *pC_BaseEntity)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    CResultProxy::SetFloatResult(
      this,
      result: COERCE_INT(
        this->m_Factor
      * fsqrt(
          (float)((float)(LocalPlayer->m_vecVelocity.x * LocalPlayer->m_vecVelocity.x)
                + (float)(LocalPlayer->m_vecVelocity.y * LocalPlayer->m_vecVelocity.y))
        + (float)(LocalPlayer->m_vecVelocity.z * LocalPlayer->m_vecVelocity.z))));
}

//------------------------------------------------------------------------------
// Address: 0x10158E20
// Name: CCPlayerSpeedProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPlayerSpeedProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x10u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CPlayerSpeedProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10158E50
// Name: public: virtual void CPlayerPositionProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPositionProxy::OnBind(CPlayerPositionProxy *this, void *pC_BaseEntity)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v4; // ecx
  const Vector *(__thiscall *WorldSpaceCenter)(C_BaseEntity *); // eax
  float *v6; // eax
  IMaterialVar *m_pResult; // ecx
  Vector res; // [esp+4h] [ebp-10h] BYREF
  float m_Factor; // [esp+10h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v4 = LocalPlayer;
    WorldSpaceCenter = LocalPlayer->WorldSpaceCenter;
    m_Factor = this->m_Factor;
    v6 = (float *)WorldSpaceCenter(this: v4);
    m_pResult = this->m_pResult;
    res.x = *v6 * m_Factor;
    res.y = v6[1] * m_Factor;
    res.z = v6[2] * m_Factor;
    m_pResult->SetVecValue_4(this: m_pResult, a2: &res.x, a3: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158ED0
// Name: CCPlayerPositionProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPlayerPositionProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x10u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CPlayerPositionProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10158F00
// Name: public: virtual void CEntitySpeedProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySpeedProxy::OnBind(CEntitySpeedProxy *this, int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  C_BaseEntity *v3; // eax

  if ( pC_BaseEntity != nullptr )
  {
    v3 = CResultProxy::BindArgToEntity(this, pArg: pC_BaseEntity);
    ((void (__stdcall *)(_DWORD))this->m_pResult->SetFloatValue)(
      a1: fsqrt(
        (float)((float)(v3->m_vecVelocity.x * v3->m_vecVelocity.x) + (float)(v3->m_vecVelocity.y * v3->m_vecVelocity.y))
      + (float)(v3->m_vecVelocity.z * v3->m_vecVelocity.z)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158F90
// Name: CCEntitySpeedProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEntitySpeedProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0xCu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CEntitySpeedProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10158FC0
// Name: public: virtual void CEntityRandomProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityRandomProxy::OnBind(CEntityRandomProxy *this, int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  IMaterialVar_vtbl *v3; // edi
  float v4; // [esp+0h] [ebp-Ch]
  float pC_BaseEntitya; // [esp+14h] [ebp+8h]

  if ( pC_BaseEntity != nullptr )
  {
    pC_BaseEntitya = CResultProxy::BindArgToEntity(this, pArg: pC_BaseEntity)->m_flProxyRandomValue;
    v3 = this->m_pResult->CResultProxy::__vftable;
    v4 = CFloatInput::GetFloat(this: &this->m_Factor) * pC_BaseEntitya;
    ((void (__thiscall *)(IMaterialVar *, _DWORD))v3->SetFloatValue)(a1: this->m_pResult, a2: LODWORD(v4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159000
// Name: CCEntityRandomProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEntityRandomProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x18u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CEntityRandomProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10159030
// Name: public: virtual bool CPlayerLogoProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPlayerLogoProxy::Init(CPlayerLogoProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  IMaterialVar *v5; // eax
  bool v6; // zf
  ITexture *v8; // eax
  bool found; // [esp+7h] [ebp-1h] BYREF

  FindVar = pMaterial->FindVar;
  found = false;
  v5 = FindVar(this: pMaterial, a2: "$basetexture", a3: &found, a4: true);
  v6 = !found;
  this->m_pBaseTextureVar = v5;
  if ( v6 )
    return 0;
  v8 = materials->FindTexture(this: materials, a2: "decals/YBlood1", a3: "Decal textures", a4: 1, a5: 0);
  this->m_pDefaultTexture = v8;
  if ( v8 == nullptr || v8->IsError(this: v8) )
    return 0;
  this->m_pDefaultTexture->IncrementReferenceCount(this: this->m_pDefaultTexture);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10159D30
// Name: public: virtual void CPlayerLogoProxy::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLogoProxy::Release(CPlayerLogoProxy *this)
{
  int m_NumElements; // ebx
  int v3; // esi
  UtlRBTreeNode_t<CPlayerLogoProxy::PlayerLogo,unsigned short> *m_pMemory; // ecx
  ITexture *texture; // ecx

  if ( this->m_pDefaultTexture != nullptr )
    this->m_pDefaultTexture->DecrementReferenceCount(this: this->m_pDefaultTexture);
  m_NumElements = this->m_Logos.m_NumElements;
  v3 = 0;
  if ( this->m_Logos.m_NumElements != 0 )
  {
    do
    {
      m_pMemory = this->m_Logos.m_Elements.m_pMemory;
      if ( m_pMemory[(unsigned __int16)v3].m_Data.texture != nullptr )
      {
        texture = m_pMemory[(unsigned __int16)v3].m_Data.texture;
        texture->DecrementReferenceCount(this: texture);
      }
      ++v3;
    }
    while ( v3 < m_NumElements );
  }
  CUtlRBTree<CPlayerLogoProxy::PlayerLogo,unsigned short,bool (__cdecl *)(CPlayerLogoProxy::PlayerLogo const &,CPlayerLogoProxy::PlayerLogo const &),CUtlMemory<UtlRBTreeNode_t<CPlayerLogoProxy::PlayerLogo,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Logos);
  ((void (__thiscall *)(CPlayerLogoProxy *, int))this->dtr_IMaterialProxy)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10159D90
// Name: CCPlayerLogoProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPlayerLogoProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CPlayerLogoProxy::`vftable';
  result[2].__vftable = (IMaterialProxy_vtbl *)CDefOps<C_BaseEntity *>::LessFunc;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[5].__vftable = nullptr;
  LOWORD(result[6].__vftable) = -1;
  HIWORD(result[6].__vftable) = 0;
  LOWORD(result[7].__vftable) = -1;
  HIWORD(result[7].__vftable) = -1;
  result[8].__vftable = result[3].__vftable;
  result[9].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10159E10
// Name: CCPlayerLogoOnModelProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCPlayerLogoOnModelProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CPlayerLogoProxy::`vftable';
  result[2].__vftable = (IMaterialProxy_vtbl *)CDefOps<C_BaseEntity *>::LessFunc;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[5].__vftable = nullptr;
  LOWORD(result[6].__vftable) = -1;
  HIWORD(result[6].__vftable) = 0;
  LOWORD(result[7].__vftable) = -1;
  HIWORD(result[7].__vftable) = -1;
  result[8].__vftable = result[3].__vftable;
  result[9].__vftable = nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CPlayerLogoOnModelProxy::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10159EE0
// Name: protected: virtual void CPlayerLogoProxy::OnLogoBindInternal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerLogoProxy::OnLogoBindInternal(CPlayerLogoProxy *this, int playerindex)
{
  unsigned __int16 v3; // ax
  ITexture *v4; // eax
  ITexture *texture; // edi
  char crcfilename[512]; // [esp+4h] [ebp-2A8h] BYREF
  player_info_s info; // [esp+204h] [ebp-A8h] BYREF
  char logohex[16]; // [esp+294h] [ebp-18h] BYREF
  CPlayerLogoProxy::PlayerLogo logo; // [esp+2A4h] [ebp-8h] BYREF

  engine->GetPlayerInfo(this: engine, a2: playerindex, a3: &info);
  if ( info.customFiles[0] != 0 )
  {
    logo.crc = info.customFiles[0];
    logo.texture = nullptr;
    v3 = CUtlRBTree<CPlayerLogoProxy::PlayerLogo,unsigned short,bool (__cdecl *)(CPlayerLogoProxy::PlayerLogo const &,CPlayerLogoProxy::PlayerLogo const &),CUtlMemory<UtlRBTreeNode_t<CPlayerLogoProxy::PlayerLogo,unsigned short>,unsigned short>>::Find(
           this: &this->m_Logos,
           search: &logo);
    if ( v3 == 0xFFFF )
    {
      V_binarytohex(in: (const unsigned __int8 *)info.customFiles, inputbytes: 4, out: logohex, outsize: 0x10u);
      V_snprintf(pDest: crcfilename, maxLen: 0x200u, pFormat: "temp/%s", logohex);
      v4 = materials->FindTexture(this: materials, a2: crcfilename, a3: "Decal textures", a4: 0, a5: 0);
      texture = v4;
      if ( v4 != nullptr )
      {
        v4->IncrementReferenceCount(this: v4);
        logo.texture = texture;
      }
      CUtlRBTree<CPlayerLogoProxy::PlayerLogo,unsigned short,bool (__cdecl *)(CPlayerLogoProxy::PlayerLogo const &,CPlayerLogoProxy::PlayerLogo const &),CUtlMemory<UtlRBTreeNode_t<CPlayerLogoProxy::PlayerLogo,unsigned short>,unsigned short>>::Insert(
        this: &this->m_Logos,
        a2: (const char *)texture,
        insert: &logo);
    }
    else
    {
      texture = this->m_Logos.m_Elements.m_pMemory[v3].m_Data.texture;
    }
    if ( texture != nullptr )
    {
      this->m_pBaseTextureVar->SetTextureValue(this: this->m_pBaseTextureVar, a2: texture);
    }
    else if ( this->m_pDefaultTexture != nullptr )
    {
      this->m_pBaseTextureVar->SetTextureValue(this: this->m_pBaseTextureVar, a2: this->m_pDefaultTexture);
    }
  }
}
