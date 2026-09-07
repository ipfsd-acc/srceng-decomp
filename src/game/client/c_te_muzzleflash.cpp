// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_muzzleflash.cpp
// Functions: 9
// ============================================================

#include "game\client\c_te_muzzleflash.h"

//------------------------------------------------------------------------------
// Address: 0x10262EB0
// Name: RecordMuzzleFlash
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordMuzzleFlash(const QAngle *angles@<edi>, const Vector *start, float scale, int type)
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
    KeyValues::SetInt(this: v5, keyName: "te", value: 3);
    KeyValues::SetString(this: v5, keyName: "name", value: "TE_MuzzleFlash");
    KeyValues::SetFloat(this: v5, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v5, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v5, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v5, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v5, keyName: "anglesx", value: angles->x);
    KeyValues::SetFloat(this: v5, keyName: "anglesy", value: angles->y);
    KeyValues::SetFloat(this: v5, keyName: "anglesz", value: angles->z);
    KeyValues::SetFloat(this: v5, keyName: "scale", value: scale);
    KeyValues::SetInt(this: v5, keyName: "type", value: type);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v5);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263000
// Name: public: virtual void C_TEMuzzleFlash::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEMuzzleFlash::PostDataUpdate(C_TEMuzzleFlash *this, DataUpdateType_t updateType)
{
  const QAngle *p_z; // edi

  p_z = (const QAngle *)&this->m_vecOrigin.z;
  ((void (__stdcall *)(C_BaseTempEntity **, float *, _DWORD, _DWORD))g_pEffects->MuzzleFlash)(
    a1: &this->m_pNextDynamic,
    a2: &this->m_vecOrigin.z,
    a3: LODWORD(this->m_vecAngles.z),
    a4: LODWORD(this->m_flScale));
  RecordMuzzleFlash(
    angles: p_z,
    start: (const Vector *)&this->m_pNextDynamic,
    scale: this->m_vecAngles.z,
    type: LODWORD(this->m_flScale));
}

//------------------------------------------------------------------------------
// Address: 0x10263050
// Name: void TE_MuzzleFlash(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_MuzzleFlash(
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        const QAngle *angles,
        float scale)
{
  ((void (__stdcall *)(const Vector *, const QAngle *, _DWORD, _DWORD))g_pEffects->MuzzleFlash)(
    a1: start,
    a2: angles,
    a3: LODWORD(scale),
    a4: 0);
  RecordMuzzleFlash(start, angles, scale, type: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102630A0
// Name: public: virtual class ClientClass __near * C_TEMuzzleFlash::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEMuzzleFlash::GetClientClass(C_TEMuzzleFlash *this)
{
  return &__g_C_TEMuzzleFlashClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042C790
// Name: DT_TEMuzzleFlash::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMuzzleFlash::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEMuzzleFlash::g_RecvTable);
  return atexit(func: DT_TEMuzzleFlash::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C7B0
// Name: DT_TEMuzzleFlash::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMuzzleFlash::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEMuzzleFlash::ignored>();
  DT_TEMuzzleFlash::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436D50
// Name: DT_TEMuzzleFlash::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEMuzzleFlash::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEMuzzleFlash::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102630B0
// Name: _C_TEMuzzleFlash_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEMuzzleFlash_CreateObject()
{
  return &_g_C_TEMuzzleFlash.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C7C0
// Name: _dynamic_initializer_for____g_C_TEParticleSystemClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEParticleSystemClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEParticleSystemClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEParticleSystemClientClass;
  return result;
}
