// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_glowsprite.cpp
// Functions: 13
// ============================================================

#include "game\client\c_te_glowsprite.h"

//------------------------------------------------------------------------------
// Address: 0x1025AEB0
// Name: public: virtual class ClientClass __near * C_TEGlowSprite::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEGlowSprite::GetClientClass(C_TEGlowSprite *this)
{
  return &__g_C_TEGlowSpriteClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1025AFC0
// Name: RecordGlowSprite
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordGlowSprite(
        const Vector *start@<edi>,
        int nModelIndex@<eax>,
        float flDuration,
        float flSize,
        int nBrightness)
{
  const struct model_t *v6; // eax
  const char *value; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // esi

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    if ( nModelIndex != 0 && (v6 = modelinfo->GetModel(this: modelinfo, a2: nModelIndex)) != nullptr )
      value = modelinfo->GetModelName(this: modelinfo, a2: v6);
    else
      value = prType;
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "TempEntity");
    else
      v9 = nullptr;
    KeyValues::SetInt(this: v9, keyName: "te", value: 10);
    KeyValues::SetString(this: v9, keyName: "name", value: "TE_GlowSprite");
    KeyValues::SetFloat(this: v9, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v9, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v9, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v9, keyName: "originz", value: start->z);
    KeyValues::SetString(this: v9, keyName: "model", value);
    KeyValues::SetFloat(this: v9, keyName: "duration", value: flDuration);
    KeyValues::SetFloat(this: v9, keyName: "size", value: flSize);
    KeyValues::SetInt(this: v9, keyName: "brightness", value: nBrightness);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v9);
    KeyValues::deleteThis(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025B120
// Name: public: virtual void C_TEGlowSprite::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEGlowSprite::PostDataUpdate(C_TEGlowSprite *this, DataUpdateType_t updateType)
{
  float v3; // xmm0_4
  C_BaseTempEntity **p_m_pNextDynamic; // edi
  int v5; // eax

  v3 = (double)SLODWORD(this->m_fLife) * 0.00392156862745098;
  p_m_pNextDynamic = &this->m_pNextDynamic;
  v5 = ((int (__stdcall *)(C_BaseTempEntity **, Vector *, int, _DWORD, int, _DWORD, _DWORD, _DWORD, int, Vector *))tempents->TempSprite)(
         a1: &this->m_pNextDynamic,
         a2: &vec3_origin,
         a3: this->m_nModelIndex,
         a4: LODWORD(this->m_vecOrigin.z),
         a5: 5,
         a6: 0,
         a7: LODWORD(v3),
         a8: LODWORD(this->m_fScale),
         a9: 65792,
         a10: &vec3_origin);
  if ( v5 != 0 )
    *(_DWORD *)(v5 + 3300) = 1045220557;
  RecordGlowSprite(
    start: (const Vector *)p_m_pNextDynamic,
    nModelIndex: LODWORD(this->m_vecOrigin.z),
    flDuration: this->m_fScale,
    flSize: *(float *)&this->m_nModelIndex,
    nBrightness: LODWORD(this->m_fLife));
}

//------------------------------------------------------------------------------
// Address: 0x1025B1C0
// Name: void TE_GlowSprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_GlowSprite(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float life,
        float size,
        int brightness)
{
  float v7; // xmm0_4
  int v8; // eax

  v7 = (double)brightness * 0.00392156862745098;
  v8 = ((int (__stdcall *)(const Vector *, Vector *, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, Vector *))tempents->TempSprite)(
         a1: pos,
         a2: &vec3_origin,
         a3: LODWORD(size),
         a4: modelindex,
         a5: 5,
         a6: 0,
         a7: LODWORD(v7),
         a8: LODWORD(life),
         a9: 65792,
         a10: &vec3_origin);
  if ( v8 != 0 )
    *(_DWORD *)(v8 + 3300) = 1045220557;
  RecordGlowSprite(start: pos, nModelIndex: modelindex, flDuration: life, flSize: size, nBrightness: brightness);
}

//------------------------------------------------------------------------------
// Address: 0x1025B290
// Name: void TE_GlowSprite(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_GlowSprite(int a1@<edi>, int a2@<esi>, IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  const char *String; // eax
  int v6; // edi
  int Float; // esi
  float v8; // xmm0_4
  int v9; // eax
  Vector vecOrigin; // [esp+3Ch] [ebp-14h] BYREF
  float flDuration; // [esp+48h] [ebp-8h]
  float flSize; // [esp+4Ch] [ebp-4h]

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "model", defaultValue: prType);
  if ( *String != 0 )
    v6 = modelinfo->GetModelIndex(this: modelinfo, a2: String);
  else
    v6 = 0;
  flDuration = KeyValues::GetFloat(this: pKeyValues, keyName: "duration", defaultValue: 0.0);
  flSize = KeyValues::GetFloat(this: pKeyValues, keyName: "size", defaultValue: 0.0);
  Float = (int)KeyValues::GetFloat(this: pKeyValues, keyName: "brightness", defaultValue: 0.0);
  v8 = (double)Float * 0.00392156862745098;
  v9 = ((int (__stdcall *)(Vector *, Vector *, _DWORD, int, int, _DWORD, _DWORD, _DWORD, int, Vector *, int, int))tempents->TempSprite)(
         a1: &vecOrigin,
         a2: &vec3_origin,
         a3: LODWORD(flSize),
         a4: v6,
         a5: 5,
         a6: 0,
         a7: LODWORD(v8),
         a8: LODWORD(flDuration),
         a9: 65792,
         a10: &vec3_origin,
         a11: a1,
         a12: a2);
  if ( v9 != 0 )
    *(_DWORD *)(v9 + 3300) = 1045220557;
  RecordGlowSprite(start: &vecOrigin, nModelIndex: v6, flDuration, flSize, nBrightness: Float);
}

//------------------------------------------------------------------------------
// Address: 0x1042C3E0
// Name: DT_TEGlowSprite::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGlowSprite::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEGlowSprite::g_RecvTable);
  return atexit(func: DT_TEGlowSprite::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C400
// Name: DT_TEGlowSprite::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGlowSprite::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEGlowSprite::ignored>();
  DT_TEGlowSprite::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436BF0
// Name: DT_TEGlowSprite::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEGlowSprite::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEGlowSprite::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1025AEC0
// Name: _C_TEGlowSprite_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEGlowSprite_CreateObject()
{
  return &_g_C_TEGlowSprite.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C410
// Name: _dynamic_initializer_for____g_C_TEImpact__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEImpact__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEImpact);
  _g_C_TEImpact.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEImpact_vtbl *)&C_TEImpact::`vftable'{for `IClientUnknown'};
  _g_C_TEImpact.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEImpact::`vftable'{for `IClientNetworkable'};
  _g_C_TEImpact.m_vecOrigin.x = 0.0;
  _g_C_TEImpact.m_vecOrigin.y = 0.0;
  _g_C_TEImpact.m_vecOrigin.z = 0.0;
  _g_C_TEImpact.m_vecNormal.x = 0.0;
  _g_C_TEImpact.m_vecNormal.y = 0.0;
  _g_C_TEImpact.m_vecNormal.z = 0.0;
  _g_C_TEImpact.m_iType = -1;
  _g_C_TEImpact.m_ucFlags = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEImpact__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C480
// Name: _dynamic_initializer_for____g_C_TEImpactClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEImpactClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEImpactClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEImpactClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436C00
// Name: _dynamic_atexit_destructor_for____g_C_TEGlowSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEGlowSprite__()
{
  _g_C_TEGlowSprite.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEGlowSprite_vtbl *)&C_TEGlowSprite::`vftable'{for `IClientUnknown'};
  _g_C_TEGlowSprite.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEGlowSprite::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEGlowSprite);
}

//------------------------------------------------------------------------------
// Address: 0x10436C20
// Name: _dynamic_atexit_destructor_for____g_C_TEImpact__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEImpact__()
{
  _g_C_TEImpact.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEImpact_vtbl *)&C_TEImpact::`vftable'{for `IClientUnknown'};
  _g_C_TEImpact.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEImpact::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEImpact);
}
