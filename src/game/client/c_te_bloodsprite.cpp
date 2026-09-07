// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_bloodsprite.cpp
// Functions: 12
// ============================================================

#include "game\client\c_te_bloodsprite.h"

//------------------------------------------------------------------------------
// Address: 0x10255B30
// Name: public: virtual class ClientClass __near * C_TEBloodSprite::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBloodSprite::GetClientClass(C_TEBloodSprite *this)
{
  return &__g_C_TEBloodSpriteClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10255CB0
// Name: RecordBloodSprite
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordBloodSprite(
        int nSprayModelIndex@<ecx>,
        int nDropModelIndex@<eax>,
        const Vector *start,
        const Vector *direction,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a,
        int size)
{
  const struct model_t *v11; // esi
  const struct model_t *v12; // edi
  const char *value; // ebx
  const char *v14; // edi
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  Color clr; // [esp+10h] [ebp-4h]

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    clr._color[0] = r;
    clr._color[1] = g;
    clr._color[2] = b;
    clr._color[3] = a;
    if ( nSprayModelIndex != 0 )
      v11 = modelinfo->GetModel(this: modelinfo, a2: nSprayModelIndex);
    else
      v11 = nullptr;
    if ( nDropModelIndex != 0 )
      v12 = modelinfo->GetModel(this: modelinfo, a2: nDropModelIndex);
    else
      v12 = nullptr;
    if ( v11 != nullptr )
      value = modelinfo->GetModelName(this: modelinfo, a2: v11);
    else
      value = prType;
    if ( v12 != nullptr )
      v14 = modelinfo->GetModelName(this: modelinfo, a2: v12);
    else
      v14 = prType;
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v16 = KeyValues::KeyValues(this: v15, setName: "TempEntity");
    else
      v16 = nullptr;
    KeyValues::SetInt(this: v16, keyName: "te", value: 8);
    KeyValues::SetString(this: v16, keyName: "name", value: "TE_BloodSprite");
    KeyValues::SetFloat(this: v16, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v16, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v16, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v16, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v16, keyName: "directionx", value: direction->x);
    KeyValues::SetFloat(this: v16, keyName: "directiony", value: direction->y);
    KeyValues::SetFloat(this: v16, keyName: "directionz", value: direction->z);
    KeyValues::SetColor(this: v16, keyName: "color", value: clr);
    KeyValues::SetString(this: v16, keyName: "spraymodel", value);
    KeyValues::SetString(this: v16, keyName: "dropmodel", value: v14);
    KeyValues::SetInt(this: v16, keyName: "size", value: size);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v16);
    KeyValues::deleteThis(this: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10255EB0
// Name: void TE_BloodSprite(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_BloodSprite(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        const Vector *dir,
        int r,
        int g,
        int b,
        int a,
        int size)
{
  float v12; // xmm2_4
  float v13; // xmm3_4
  Vector offset; // [esp+3Ch] [ebp-Ch] BYREF

  v12 = dir->z * 4.0;
  v13 = org->x + (float)(dir->x * 4.0);
  offset.y = org->y + (float)(dir->y * 4.0);
  offset.z = org->z + v12;
  offset.x = v13;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))tempents->BloodSprite)(
    a1: tempents,
    a2: &offset,
    a3: r,
    a4: g,
    a5: b,
    a6: a,
    a7: g_sModelIndexBloodSpray,
    a8: g_sModelIndexBloodDrop,
    a9: (float)size,
    a10: a2,
    a11: a3,
    a12: a1);
  FX_Blood(a1: a, a2: (int)org, a3: (int)dir, pos: &offset, dir, (float)r, (float)g, (float)b, (float)a);
  RecordBloodSprite(
    start: org,
    direction: dir,
    r,
    g,
    b,
    a,
    nSprayModelIndex: g_sModelIndexBloodSpray,
    nDropModelIndex: g_sModelIndexBloodDrop,
    size);
}

//------------------------------------------------------------------------------
// Address: 0x10255FC0
// Name: public: virtual void C_TEBloodSprite::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TEBloodSprite::PostDataUpdate(
        C_TEBloodSprite *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        DataUpdateType_t updateType)
{
  float x; // xmm1_4
  float y; // xmm2_4
  int a; // edx
  float *p_z; // edi
  C_BaseTempEntity **p_m_pNextDynamic; // ebx
  Vector offset; // [esp+3Ch] [ebp-Ch] BYREF

  x = this->m_vecDirection.x;
  y = this->m_vecDirection.y;
  a = this->a;
  p_z = &this->m_vecOrigin.z;
  offset.x = (float)(this->m_vecOrigin.z * 4.0) + *(float *)&this->m_pNextDynamic;
  p_m_pNextDynamic = &this->m_pNextDynamic;
  offset.y = this->m_vecOrigin.x + (float)(x * 4.0);
  offset.z = this->m_vecOrigin.y + (float)(y * 4.0);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))tempents->BloodSprite)(
    a1: tempents,
    a2: &offset,
    a3: LODWORD(this->m_vecDirection.z),
    a4: this->r,
    a5: this->g,
    a6: this->b,
    a7: this->m_nDropModel,
    a8: a,
    a9: (float)this->m_nSprayModel,
    a10: a3,
    a11: a4,
    a12: a2);
  FX_Blood(
    a1: (int)p_m_pNextDynamic,
    a2: (int)p_z,
    a3: (int)this,
    pos: &offset,
    dir: (Vector *)&this->m_vecOrigin.z,
    r: (float)SLODWORD(this->m_vecDirection.z),
    g: (float)this->r,
    b: (float)this->g,
    a: (float)this->b);
  RecordBloodSprite(
    nSprayModelIndex: this->m_nDropModel,
    nDropModelIndex: this->a,
    start: (const Vector *)&this->m_pNextDynamic,
    direction: (const Vector *)&this->m_vecOrigin.z,
    r: LODWORD(this->m_vecDirection.z),
    g: this->r,
    b: this->g,
    a: this->b,
    size: this->m_nSprayModel);
}

//------------------------------------------------------------------------------
// Address: 0x102560D0
// Name: void TE_BloodSprite(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_BloodSprite(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IRecipientFilter *filter,
        float delay,
        KeyValues *pKeyValues)
{
  int Int; // eax
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  ITempEnts_vtbl *v10; // ecx
  Vector pos; // [esp+3Ch] [ebp-34h] BYREF
  Vector vecOrigin; // [esp+48h] [ebp-28h] BYREF
  Vector vecDirection; // [esp+54h] [ebp-1Ch] BYREF
  int nSize; // [esp+60h] [ebp-10h]
  Color c; // [esp+68h] [ebp-8h] BYREF
  Color defaultColor; // [esp+6Ch] [ebp-4h] BYREF

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "directionx", defaultValue: 0.0);
  vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "directiony", defaultValue: 0.0);
  vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "directionz", defaultValue: 0.0);
  defaultColor = 0;
  KeyValues::GetColor(this: pKeyValues, result: &c, keyName: "color", &defaultColor);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "size", defaultValue: 0);
  v7 = c._color[3];
  v8 = c._color[2];
  v9 = c._color[1];
  pos.x = (float)(vecDirection.x * 4.0) + vecOrigin.x;
  pos.y = (float)(vecDirection.y * 4.0) + vecOrigin.y;
  pos.z = (float)(vecDirection.z * 4.0) + vecOrigin.z;
  v10 = tempents->__vftable;
  nSize = Int;
  defaultColor = (Color)c._color[0];
  ((void (__thiscall *)(ITempEnts *, Vector *, _DWORD, _DWORD, _DWORD, _DWORD, int, int, float, int, int, int))v10->BloodSprite)(
    a1: tempents,
    a2: &pos,
    a3: c._color[0],
    a4: c._color[1],
    a5: c._color[2],
    a6: c._color[3],
    a7: g_sModelIndexBloodSpray,
    a8: g_sModelIndexBloodDrop,
    a9: (float)Int,
    a10: a2,
    a11: a3,
    a12: a1);
  FX_Blood(
    a1: v9,
    a2: v8,
    a3: v7,
    &pos,
    dir: &vecDirection,
    r: (float)*(int *)&defaultColor,
    g: (float)v9,
    b: (float)v8,
    a: (float)v7);
  RecordBloodSprite(
    start: &vecOrigin,
    direction: &vecDirection,
    r: *(_DWORD *)&defaultColor,
    g: v9,
    b: v8,
    a: v7,
    nSprayModelIndex: g_sModelIndexBloodSpray,
    nDropModelIndex: g_sModelIndexBloodDrop,
    size: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1042B6C0
// Name: DT_TEBloodSprite::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodSprite::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBloodSprite::g_RecvTable);
  return atexit(func: DT_TEBloodSprite::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B6E0
// Name: DT_TEBloodSprite::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodSprite::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBloodSprite::ignored>();
  DT_TEBloodSprite::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104368F0
// Name: DT_TEBloodSprite::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBloodSprite::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBloodSprite::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10255B40
// Name: _C_TEBloodSprite_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBloodSprite_CreateObject()
{
  return &_g_C_TEBloodSprite.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B6F0
// Name: _dynamic_initializer_for____g_C_TEBloodStream__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBloodStream__()
{
  C_TEParticleSystem::C_TEParticleSystem(this: &_g_C_TEBloodStream);
  _g_C_TEBloodStream.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBloodStream_vtbl *)&C_TEBloodStream::`vftable'{for `IClientUnknown'};
  _g_C_TEBloodStream.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBloodStream::`vftable'{for `IClientNetworkable'};
  _g_C_TEBloodStream.m_vecOrigin.x = 0.0;
  _g_C_TEBloodStream.m_vecOrigin.y = 0.0;
  _g_C_TEBloodStream.m_vecOrigin.z = 0.0;
  _g_C_TEBloodStream.m_vecDirection.x = 0.0;
  _g_C_TEBloodStream.m_vecDirection.y = 0.0;
  _g_C_TEBloodStream.m_vecDirection.z = 0.0;
  _g_C_TEBloodStream.a = 0;
  _g_C_TEBloodStream.b = 0;
  _g_C_TEBloodStream.g = 0;
  _g_C_TEBloodStream.r = 0;
  _g_C_TEBloodStream.m_nAmount = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBloodStream__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B770
// Name: _dynamic_initializer_for____g_C_TEBloodStreamClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBloodStreamClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBloodStreamClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBloodStreamClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436900
// Name: _dynamic_atexit_destructor_for____g_C_TEBloodSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBloodSprite__()
{
  _g_C_TEBloodSprite.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBloodSprite_vtbl *)&C_TEBloodSprite::`vftable'{for `IClientUnknown'};
  _g_C_TEBloodSprite.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBloodSprite::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEBloodSprite);
}
