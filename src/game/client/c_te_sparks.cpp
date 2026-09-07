// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_sparks.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_sparks.h"

//------------------------------------------------------------------------------
// Address: 0x10265580
// Name: RecordSparks
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordSparks(const Vector *direction@<edi>, const Vector *start, int nMagnitude, int nTrailLength)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "TempEntity");
    else
      v5 = nullptr;
    KeyValues::SetInt(this: v5, keyName: "te", value: 7);
    KeyValues::SetString(this: v5, keyName: "name", value: "TE_Sparks");
    KeyValues::SetFloat(this: v5, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v5, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v5, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v5, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v5, keyName: "directionx", value: direction->x);
    KeyValues::SetFloat(this: v5, keyName: "directiony", value: direction->y);
    KeyValues::SetFloat(this: v5, keyName: "directionz", value: direction->z);
    KeyValues::SetInt(this: v5, keyName: "magnitude", value: nMagnitude);
    KeyValues::SetInt(this: v5, keyName: "traillength", value: nTrailLength);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v5);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102656D0
// Name: public: virtual void C_TESparks::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TESparks::PostDataUpdate(C_TESparks *this, DataUpdateType_t updateType)
{
  int *p_m_nTrailLength; // edi

  p_m_nTrailLength = &this->m_nTrailLength;
  g_pEffects->Sparks(
    this: g_pEffects,
    a2: (const Vector *)&this->m_pNextDynamic,
    a3: LODWORD(this->m_vecOrigin.z),
    a4: this->m_nMagnitude,
    a5: (const Vector *)&this->m_nTrailLength);
  RecordSparks(
    direction: (const Vector *)p_m_nTrailLength,
    start: (const Vector *)&this->m_pNextDynamic,
    nMagnitude: LODWORD(this->m_vecOrigin.z),
    nTrailLength: this->m_nMagnitude);
}

//------------------------------------------------------------------------------
// Address: 0x10265710
// Name: void TE_Sparks(class IRecipientFilter __near &,float,class Vector const __near *,int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Sparks(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int nMagnitude,
        int nTrailLength,
        const Vector *pDir)
{
  g_pEffects->Sparks(this: g_pEffects, a2: pos, a3: nMagnitude, a4: nTrailLength, a5: pDir);
  RecordSparks(start: pos, nMagnitude, nTrailLength, direction: pDir);
}

//------------------------------------------------------------------------------
// Address: 0x10265750
// Name: public: virtual class ClientClass __near * C_TESparks::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TESparks::GetClientClass(C_TESparks *this)
{
  return &__g_C_TESparksClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042CC70
// Name: DT_TESparks::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESparks::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TESparks::g_RecvTable);
  return atexit(func: DT_TESparks::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CC90
// Name: DT_TESparks::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESparks::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TESparks::ignored>();
  DT_TESparks::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436E90
// Name: DT_TESparks::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESparks::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TESparks::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10265760
// Name: _C_TESparks_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TESparks_CreateObject()
{
  return &_g_C_TESparks.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042CCA0
// Name: _dynamic_initializer_for____g_C_TESprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TESprite__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TESprite);
  _g_C_TESprite.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESprite_vtbl *)&C_TESprite::`vftable'{for `IClientUnknown'};
  _g_C_TESprite.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESprite::`vftable'{for `IClientNetworkable'};
  _g_C_TESprite.m_vecOrigin.x = 0.0;
  _g_C_TESprite.m_vecOrigin.y = 0.0;
  _g_C_TESprite.m_vecOrigin.z = 0.0;
  _g_C_TESprite.m_nModelIndex = 0;
  _g_C_TESprite.m_fScale = 0.0;
  _g_C_TESprite.m_nBrightness = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TESprite__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CD00
// Name: _dynamic_initializer_for____g_C_TESpriteClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TESpriteClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TESpriteClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TESpriteClientClass;
  return result;
}
