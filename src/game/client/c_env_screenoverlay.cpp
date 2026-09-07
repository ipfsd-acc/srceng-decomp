// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_env_screenoverlay.cpp
// Functions: 18
// ============================================================

#include "game\client\c_env_screenoverlay.h"

//------------------------------------------------------------------------------
// Address: 0x10069A30
// Name: public: virtual class ClientClass __near * C_EnvScreenOverlay::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvScreenOverlay::GetClientClass(C_EnvScreenOverlay *this)
{
  return &__g_C_EnvScreenOverlayClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10069B70
// Name: public: virtual void C_EnvScreenOverlay::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvScreenOverlay::PreDataUpdate(C_EnvScreenOverlay *this, DataUpdateType_t updateType)
{
  C_BaseEntity::PreDataUpdate(this, updateType);
  BYTE1(this->m_flStartTime) = LOBYTE(this->m_flStartTime);
}

//------------------------------------------------------------------------------
// Address: 0x10069B90
// Name: public: void C_EnvScreenOverlay::StopOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvScreenOverlay::StopOverlays(C_EnvScreenOverlay *this)
{
  ((void (__stdcall *)(int))this->SetNextClientThink)(a1: -1082130432);
  if ( this->m_bWasActive && !this->m_bIsActive )
    view->SetScreenOverlayMaterial(this: view, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10069BD0
// Name: public: virtual class ClientClass __near * C_EnvScreenEffect::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvScreenEffect::GetClientClass(C_EnvScreenEffect *this)
{
  return &__g_C_EnvScreenEffectClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10069CF0
// Name: public: void C_EnvScreenOverlay::StartCurrentOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvScreenOverlay::StartCurrentOverlay(C_EnvScreenOverlay *this)
{
  int m_iCurrentOverlay; // eax
  const char *v3; // edx
  float v4; // xmm0_4
  float v5; // xmm1_4
  IMaterial *v6; // edi
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // eax

  m_iCurrentOverlay = this->m_iCurrentOverlay;
  if ( m_iCurrentOverlay == 10
    || (v3 = this->m_iszOverlayNames[m_iCurrentOverlay],
        (C_EnvScreenOverlay *)((char *)this + 255 * m_iCurrentOverlay) == (C_EnvScreenOverlay *)-2432)
    || *v3 == 0 )
  {
    SetNextClientThink = this->SetNextClientThink;
    this->m_flStartTime = 0.0;
    ((void (__thiscall *)(C_EnvScreenOverlay *, int))SetNextClientThink)(a1: this, a2: -1082130432);
    if ( this->m_bWasActive && !this->m_bIsActive )
      view->SetScreenOverlayMaterial(this: view, a2: nullptr);
  }
  else
  {
    v4 = this->m_flOverlayTimes[m_iCurrentOverlay];
    v5 = -1.0;
    if ( v4 != -1.0 )
      v5 = *(float *)(gpGlobals.m_Index + 12) + v4;
    this->m_flCurrentOverlayTime = v5;
    v6 = materials->FindMaterial(this: materials, a2: v3, a3: "ClientEffect textures", a4: 0, a5: 0);
    if ( v6 == nullptr || v6->IsErrorMaterial(this: v6) )
    {
      _Warning(a1: "env_screenoverlay couldn't find overlay %s.\n", this->m_iszOverlayNames[this->m_iCurrentOverlay]);
      C_EnvScreenOverlay::StopOverlays(this);
    }
    else
    {
      view->SetScreenOverlayMaterial(this: view, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069E10
// Name: public: virtual void C_EnvScreenOverlay::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvScreenOverlay::ClientThink(C_EnvScreenOverlay *this)
{
  float v1; // xmm0_4

  v1 = *(float *)&this->m_bIsActive;
  if ( v1 != -1.0 && *(float *)(gpGlobals.m_Index + 12) > v1 )
  {
    ++this->m_iDesiredOverlay;
    C_EnvScreenOverlay::StartCurrentOverlay(this: (C_EnvScreenOverlay *)((char *)this - 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069EC0
// Name: public: virtual void C_EnvScreenEffect::ReceiveMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_EnvScreenEffect::ReceiveMessage(
        C_EnvScreenEffect *this@<ecx>,
        int a2@<edi>,
        int classID,
        bf_read *msg)
{
  C_EnvScreenEffect *v4; // ebx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v7; // esi
  int v8; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v11; // edx
  const unsigned int *v12; // esi
  unsigned int v13; // edi
  int v14; // edx
  const unsigned int *v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int v18; // edi
  int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // esi
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // esi
  KeyValues *v26; // eax
  KeyValues *v27; // esi
  int v28; // eax

  v4 = this;
  if ( classID != *(_DWORD *)(((int (__fastcall *)(C_EnvScreenEffect *))this->GetRefEHandle)(a1: this) + 20) )
  {
    C_BaseEntity::ReceiveMessage(this: v4, classID, msg);
    return;
  }
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = msg->m_nInBufWord;
    v7 = (unsigned __int8)m_nInBufWord;
    v8 = m_nBitsAvail - 8;
    msg->m_nBitsAvail = v8;
    if ( v8 != 0 )
    {
      msg->m_nInBufWord = m_nInBufWord >> 8;
    }
    else
    {
      m_pDataIn = msg->m_pDataIn;
      m_pBufferEnd = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v11 = *m_pDataIn;
        msg->m_pDataIn = m_pDataIn + 1;
        msg->m_nInBufWord = v11;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    goto LABEL_20;
  }
  v12 = msg->m_pBufferEnd;
  v13 = msg->m_nInBufWord;
  v14 = 8 - m_nBitsAvail;
  v15 = msg->m_pDataIn;
  if ( v15 == v12 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v15 > v12 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_17;
    }
    msg->m_nInBufWord = *v15;
  }
  msg->m_pDataIn = v15 + 1;
LABEL_17:
  if ( msg->m_bOverflow )
  {
    v7 = 0;
  }
  else
  {
    v16 = msg->m_nInBufWord;
    v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v14;
    v18 = v17 | v13;
    v4 = this;
    msg->m_nInBufWord = v16 >> v14;
    v7 = v18;
  }
LABEL_20:
  if ( v7 == 0 )
  {
    v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v26 == nullptr )
      return;
    v27 = KeyValues::KeyValues(this: v26, setName: "keys");
    if ( v27 == nullptr )
      return;
    v28 = *((_DWORD *)&v4->m_bIsBlurred + 1);
    if ( v28 == 1 )
    {
      KeyValues::SetFloat(this: v27, keyName: "duration", value: *(float *)&v4->m_bIsBlurred);
      KeyValues::SetInt(this: v27, keyName: "fadeout", value: 0);
      ((void (__thiscall *)(IScreenSpaceEffectManager *, const char *, KeyValues *, int))g_pScreenSpaceEffects->SetScreenSpaceEffectParams_2)(
        a1: g_pScreenSpaceEffects,
        a2: "episodic_intro",
        a3: v27,
        a4: a2);
    }
    else if ( v28 != 0 )
    {
      if ( v28 != 2 )
      {
LABEL_41:
        KeyValues::deleteThis(this: v27);
        return;
      }
      KeyValues::SetFloat(this: v27, keyName: "duration", value: *(float *)&v4->m_bIsBlurred);
      KeyValues::SetInt(this: v27, keyName: "fadeout", value: 0);
      ((void (__thiscall *)(IScreenSpaceEffectManager *, const char *, KeyValues *, int))g_pScreenSpaceEffects->SetScreenSpaceEffectParams_2)(
        a1: g_pScreenSpaceEffects,
        a2: "ep2_groggy",
        a3: v27,
        a4: a2);
    }
    else
    {
      KeyValues::SetFloat(this: v27, keyName: "duration", value: *(float *)&v4->m_bIsBlurred);
      ((void (__thiscall *)(IScreenSpaceEffectManager *, const char *, KeyValues *, int))g_pScreenSpaceEffects->SetScreenSpaceEffectParams_2)(
        a1: g_pScreenSpaceEffects,
        a2: "episodic_stun",
        a3: v27,
        a4: a2);
    }
    ((void (__thiscall *)(IScreenSpaceEffectManager *))g_pScreenSpaceEffects->EnableScreenSpaceEffect_2)(a1: g_pScreenSpaceEffects);
    goto LABEL_41;
  }
  if ( v7 == 1 )
  {
    v19 = *((_DWORD *)&v4->m_bIsBlurred + 1);
    if ( v19 == 1 )
    {
      v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v20 != nullptr )
      {
        v21 = KeyValues::KeyValues(this: v20, setName: "keys");
        v22 = v21;
        if ( v21 != nullptr )
        {
          KeyValues::SetFloat(this: v21, keyName: "duration", value: *(float *)&v4->m_bIsBlurred);
          KeyValues::SetInt(this: v22, keyName: "fadeout", value: 1);
          g_pScreenSpaceEffects->SetScreenSpaceEffectParams_2(
            this: g_pScreenSpaceEffects,
            a2: "episodic_intro",
            a3: v22);
        }
      }
    }
    else if ( v19 != 0 )
    {
      if ( v19 == 2 )
      {
        v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v23 != nullptr )
        {
          v24 = KeyValues::KeyValues(this: v23, setName: "keys");
          v25 = v24;
          if ( v24 != nullptr )
          {
            KeyValues::SetFloat(this: v24, keyName: "duration", value: *(float *)&v4->m_bIsBlurred);
            KeyValues::SetInt(this: v25, keyName: "fadeout", value: 1);
            g_pScreenSpaceEffects->SetScreenSpaceEffectParams_2(this: g_pScreenSpaceEffects, a2: "ep2_groggy", a3: v25);
          }
        }
      }
    }
    else
    {
      g_pScreenSpaceEffects->DisableScreenSpaceEffect_2(this: g_pScreenSpaceEffects, a2: "episodic_stun");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A200
// Name: public: void C_EnvScreenOverlay::StartOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvScreenOverlay::StartOverlays(C_EnvScreenOverlay *this)
{
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // edx
  int m_iDesiredOverlay; // eax

  this->m_iCurrentOverlay = 0;
  this->m_iCachedDesiredOverlay = 0;
  SetNextClientThink = this->SetNextClientThink;
  this->m_flCurrentOverlayTime = 0.0;
  ((void (__stdcall *)(int))SetNextClientThink)(a1: -996040704);
  C_EnvScreenOverlay::StartCurrentOverlay(this);
  m_iDesiredOverlay = this->m_iDesiredOverlay;
  if ( this->m_iCachedDesiredOverlay != m_iDesiredOverlay )
  {
    this->m_iCurrentOverlay = m_iDesiredOverlay;
    this->m_iCachedDesiredOverlay = m_iDesiredOverlay;
    C_EnvScreenOverlay::StartCurrentOverlay(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A260
// Name: public: virtual void C_EnvScreenOverlay::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvScreenOverlay::PostDataUpdate(C_EnvScreenOverlay *this, DataUpdateType_t updateType)
{
  float v3; // eax
  C_EnvScreenOverlay *v4; // ecx
  int v5; // eax
  bool *p_m_bIsBlurred; // esi
  int i; // edi

  C_BaseEntity::PostDataUpdate(this, updateType);
  if ( LOBYTE(this->m_flStartTime) != 0
    && this->m_flOverlayTimes[8] > 0.0
    && view->GetScreenOverlayMaterial(this: view) == nullptr )
  {
    C_EnvScreenOverlay::StartOverlays(this: (C_EnvScreenOverlay *)((char *)this - 8));
  }
  if ( this->m_flOverlayTimes[8] == -1.0 )
  {
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 456))(a1: (char *)this - 8, a2: -1082130432);
    if ( BYTE1(this->m_flStartTime) != 0 && LOBYTE(this->m_flStartTime) == 0 )
      view->SetScreenOverlayMaterial(this: view, a2: nullptr);
  }
  v3 = this->m_flOverlayTimes[9];
  v4 = (C_EnvScreenOverlay *)((char *)this - 8);
  if ( this->m_iDesiredOverlay != LODWORD(v3) )
  {
    *(float *)&v4->m_iCurrentOverlay = v3;
    *(float *)&v4->m_iCachedDesiredOverlay = v3;
    C_EnvScreenOverlay::StartCurrentOverlay(this: v4);
  }
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v5 = _CommandLine(a1: v4);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-makereslists") != 0 )
    {
      p_m_bIsBlurred = &this->m_bIsBlurred;
      for ( i = 10; i != 0; --i )
      {
        if ( p_m_bIsBlurred != nullptr && *p_m_bIsBlurred )
          materials->FindMaterial(
            this: materials,
            a2: (const char *)p_m_bIsBlurred,
            a3: "ClientEffect textures",
            a4: false,
            a5: nullptr);
        p_m_bIsBlurred += 255;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411DB0
// Name: DT_EnvScreenOverlay::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenOverlay::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvScreenOverlay::g_RecvTable);
  return atexit(func: DT_EnvScreenOverlay::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411DD0
// Name: DT_EnvScreenOverlay::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenOverlay::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvScreenOverlay::ignored>();
  DT_EnvScreenOverlay::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411E00
// Name: DT_EnvScreenEffect::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenEffect::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvScreenEffect::g_RecvTable);
  return atexit(func: DT_EnvScreenEffect::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411E20
// Name: DT_EnvScreenEffect::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvScreenEffect::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvScreenEffect::ignored>();
  DT_EnvScreenEffect::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430240
// Name: DT_EnvScreenOverlay::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvScreenOverlay::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvScreenOverlay::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430250
// Name: DT_EnvScreenEffect::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvScreenEffect::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvScreenEffect::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10069E50
// Name: _C_EnvScreenEffect_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvScreenEffect_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_EnvScreenEffect::`vftable'{for `IClientUnknown'};
  v3[1] = &C_EnvScreenEffect::`vftable'{for `IClientRenderable'};
  v3[2] = &C_EnvScreenEffect::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_EnvScreenEffect::`vftable'{for `IClientThinkable'};
  v3[4] = &C_EnvScreenEffect::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10411DE0
// Name: _dynamic_initializer_for____g_C_EnvScreenEffectClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvScreenEffectClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvScreenEffectClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvScreenEffectClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411E30
// Name: _dynamic_initializer_for____g_C_EnvTonemapControllerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvTonemapControllerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvTonemapControllerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvTonemapControllerClientClass;
  return result;
}
