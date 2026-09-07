// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_sprite.cpp
// Functions: 12
// ============================================================

#include "game\client\c_te_sprite.h"

//------------------------------------------------------------------------------
// Address: 0x10265860
// Name: public: virtual class ClientClass __near * C_TESprite::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TESprite::GetClientClass(C_TESprite *this)
{
  return &__g_C_TESpriteClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10265950
// Name: RecordSprite
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordSprite(const Vector *start@<edi>, int nModelIndex@<eax>, float flScale, int nBrightness)
{
  const struct model_t *v5; // eax
  const char *value; // ebx
  KeyValues *v7; // eax
  KeyValues *v8; // esi

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    if ( nModelIndex != 0 && (v5 = modelinfo->GetModel(this: modelinfo, a2: nModelIndex)) != nullptr )
      value = modelinfo->GetModelName(this: modelinfo, a2: v5);
    else
      value = prType;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "TempEntity");
    else
      v8 = nullptr;
    KeyValues::SetInt(this: v8, keyName: "te", value: 12);
    KeyValues::SetString(this: v8, keyName: "name", value: "TE_Sprite");
    KeyValues::SetFloat(this: v8, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v8, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v8, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v8, keyName: "originz", value: start->z);
    KeyValues::SetString(this: v8, keyName: "model", value);
    KeyValues::SetFloat(this: v8, keyName: "scale", value: flScale);
    KeyValues::SetInt(this: v8, keyName: "brightness", value: nBrightness);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v8);
    KeyValues::deleteThis(this: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10265AA0
// Name: public: virtual void C_TESprite::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TESprite::PostDataUpdate(C_TESprite *this, DataUpdateType_t updateType)
{
  float v3; // xmm0_4
  C_BaseTempEntity **p_m_pNextDynamic; // edi

  v3 = (double)SLODWORD(this->m_fScale) * 0.00392156862745098;
  p_m_pNextDynamic = &this->m_pNextDynamic;
  ((void (__stdcall *)(C_BaseTempEntity **, Vector *, int, _DWORD, int, _DWORD, _DWORD, _DWORD, int, Vector *))tempents->TempSprite)(
    a1: &this->m_pNextDynamic,
    a2: &vec3_origin,
    a3: this->m_nModelIndex,
    a4: LODWORD(this->m_vecOrigin.z),
    a5: 5,
    a6: 0,
    a7: LODWORD(v3),
    a8: 0,
    a9: 256,
    a10: &vec3_origin);
  RecordSprite(
    start: (const Vector *)p_m_pNextDynamic,
    nModelIndex: LODWORD(this->m_vecOrigin.z),
    flScale: *(float *)&this->m_nModelIndex,
    nBrightness: LODWORD(this->m_fScale));
}

//------------------------------------------------------------------------------
// Address: 0x10265B20
// Name: void TE_Sprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Sprite(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float size,
        int brightness)
{
  float v6; // xmm0_4

  v6 = (double)brightness * 0.00392156862745098;
  ((void (__stdcall *)(const Vector *, Vector *, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, Vector *))tempents->TempSprite)(
    a1: pos,
    a2: &vec3_origin,
    a3: LODWORD(size),
    a4: modelindex,
    a5: 5,
    a6: 0,
    a7: LODWORD(v6),
    a8: 0,
    a9: 256,
    a10: &vec3_origin);
  RecordSprite(start: pos, nModelIndex: modelindex, flScale: size, nBrightness: brightness);
}

//------------------------------------------------------------------------------
// Address: 0x10265BD0
// Name: void TE_Sprite(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_Sprite(int a1@<edi>, int a2@<esi>, IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  const char *String; // eax
  int v6; // edi
  int Int; // esi
  float v8; // xmm0_4
  Vector vecOrigin; // [esp+38h] [ebp-10h] BYREF
  float flScale; // [esp+44h] [ebp-4h]

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "model", defaultValue: prType);
  if ( *String != 0 )
    v6 = modelinfo->GetModelIndex(this: modelinfo, a2: String);
  else
    v6 = 0;
  flScale = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 0.0);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "brightness", defaultValue: 0);
  v8 = (double)Int * 0.00392156862745098;
  ((void (__cdecl *)(Vector *, Vector *, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, Vector *, int, int))tempents->TempSprite)(
    a1: &vecOrigin,
    a2: &vec3_origin,
    a3: LODWORD(flScale),
    a4: v6,
    a5: 5,
    a6: 0,
    a7: LODWORD(v8),
    a8: 0,
    a9: 256,
    a10: &vec3_origin,
    a11: a1,
    a12: a2);
  RecordSprite(start: &vecOrigin, nModelIndex: v6, flScale, nBrightness: Int);
}

//------------------------------------------------------------------------------
// Address: 0x1042CD20
// Name: DT_TESprite::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESprite::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TESprite::g_RecvTable);
  return atexit(func: DT_TESprite::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CD40
// Name: DT_TESprite::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESprite::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TESprite::ignored>();
  DT_TESprite::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436EA0
// Name: DT_TESprite::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESprite::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TESprite::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10265870
// Name: _C_TESprite_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TESprite_CreateObject()
{
  return &_g_C_TESprite.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042CD50
// Name: _dynamic_initializer_for____g_C_TESpriteSpray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TESpriteSpray__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TESpriteSpray);
  _g_C_TESpriteSpray.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESpriteSpray_vtbl *)&C_TESpriteSpray::`vftable'{for `IClientUnknown'};
  _g_C_TESpriteSpray.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESpriteSpray::`vftable'{for `IClientNetworkable'};
  _g_C_TESpriteSpray.m_vecOrigin.x = 0.0;
  _g_C_TESpriteSpray.m_vecOrigin.y = 0.0;
  _g_C_TESpriteSpray.m_vecOrigin.z = 0.0;
  _g_C_TESpriteSpray.m_vecDirection.x = 0.0;
  _g_C_TESpriteSpray.m_vecDirection.y = 0.0;
  _g_C_TESpriteSpray.m_vecDirection.z = 0.0;
  _g_C_TESpriteSpray.m_nModelIndex = 0;
  _g_C_TESpriteSpray.m_fNoise = 0.0;
  _g_C_TESpriteSpray.m_nSpeed = 0;
  _g_C_TESpriteSpray.m_nCount = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TESpriteSpray__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CDD0
// Name: _dynamic_initializer_for____g_C_TESpriteSprayClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TESpriteSprayClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TESpriteSprayClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TESpriteSprayClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436EB0
// Name: _dynamic_atexit_destructor_for____g_C_TESprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TESprite__()
{
  _g_C_TESprite.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESprite_vtbl *)&C_TESprite::`vftable'{for `IClientUnknown'};
  _g_C_TESprite.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESprite::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TESprite);
}
