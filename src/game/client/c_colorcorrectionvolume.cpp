// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_colorcorrectionvolume.cpp
// Functions: 12
// ============================================================

#include "game\client\c_colorcorrectionvolume.h"

//------------------------------------------------------------------------------
// Address: 0x100623E0
// Name: public: virtual class ClientClass __near * C_ColorCorrectionVolume::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ColorCorrectionVolume::GetClientClass(C_ColorCorrectionVolume *this)
{
  return &__g_C_ColorCorrectionVolumeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100624F0
// Name: public: virtual struct datamap_t __near * C_ColorCorrectionVolume::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_ColorCorrectionVolume::GetPredDescMap(C_ColorCorrectionVolume *this)
{
  return &C_ColorCorrectionVolume::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10062500
// Name: public: virtual void C_ColorCorrectionVolume::StartTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ColorCorrectionVolume::StartTouch(C_ColorCorrectionVolume *this, C_BaseEntity *pEntity)
{
  this->m_LastEnterTime = *(float *)(gpGlobals.m_Index + 12);
  this->m_LastEnterWeight = this->m_Weight;
}

//------------------------------------------------------------------------------
// Address: 0x10062520
// Name: public: virtual void C_ColorCorrectionVolume::EndTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ColorCorrectionVolume::EndTouch(C_ColorCorrectionVolume *this, C_BaseEntity *pEntity)
{
  this->m_LastExitTime = *(float *)(gpGlobals.m_Index + 12);
  this->m_LastExitWeight = this->m_Weight;
}

//------------------------------------------------------------------------------
// Address: 0x100625A0
// Name: public: virtual void C_ColorCorrectionVolume::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ColorCorrectionVolume::OnDataChanged(C_ColorCorrectionVolume *this, DataUpdateType_t updateType)
{
  const Vector *v3; // eax
  char name[260]; // [esp+8h] [ebp-208h] BYREF
  char cleanName[260]; // [esp+10Ch] [ebp-104h] BYREF

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED && *(_DWORD *)&this->m_lookupFilename[252] == 0 )
  {
    V_StripExtension(in: (char *)&this->m_FadeDuration, out: cleanName, outSize: 260);
    v3 = this->GetAbsOrigin(this);
    V_snprintf(pDest: name, maxLen: 0x104u, pFormat: "%s_%d", cleanName, v3);
    *(_DWORD *)&this->m_lookupFilename[252] = CColorCorrectionMgr::AddColorCorrectionVolume(
                                                this: g_pColorCorrectionMgr,
                                                pVolume: (C_ColorCorrectionVolume *)((char *)this - 8),
                                                pName: name,
                                                pFileName: (const char *)&this->m_FadeDuration);
    CCollisionProperty::SetSolid(this: (CCollisionProperty *)&this->m_hOldMoveParent, val: SOLID_BSP);
    CCollisionProperty::SetSolidFlags(this: (CCollisionProperty *)&this->m_hOldMoveParent, flags: 0xCu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062650
// Name: void UpdateColorCorrectionVolumes(class C_BasePlayer __near *,float,class C_ColorCorrectionVolume __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateColorCorrectionVolumes(
        C_BasePlayer *pPlayer,
        float ccScale,
        C_ColorCorrectionVolume **pList,
        int listCount)
{
  int i; // ebx
  C_ColorCorrectionVolume *v5; // esi
  const Vector *v6; // eax
  float m_LastEnterTime; // xmm3_4
  float m_LastExitTime; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  _BYTE v11[12]; // [esp+1Ch] [ebp-Ch] BYREF

  for ( i = 0; i < listCount; ++i )
  {
    v5 = pList[i];
    if ( pPlayer != nullptr )
    {
      v6 = pPlayer->EyePosition(this: pPlayer, result: v11);
      if ( CCollisionProperty::IsPointInBounds(this: &v5->m_Collision, vecWorldPt: v6) )
      {
        if ( v5->m_LastEnterTime <= v5->m_LastExitTime )
          v5->StartTouch(this: v5, a2: pPlayer);
      }
      else if ( v5->m_LastEnterTime > v5->m_LastExitTime )
      {
        v5->EndTouch(this: v5, a2: pPlayer);
      }
    }
    if ( v5->m_bEnabled )
    {
      m_LastEnterTime = v5->m_LastEnterTime;
      m_LastExitTime = v5->m_LastExitTime;
      if ( m_LastEnterTime <= m_LastExitTime )
      {
        if ( v5->m_Weight > 0.0 )
        {
          v10 = (float)((float)(*(float *)(gpGlobals.m_Index + 12) - m_LastExitTime)
                      / (float)(v5->m_FadeDuration * v5->m_LastExitWeight))
              + (float)(1.0 - v5->m_LastExitWeight);
          if ( v10 > 1.0 )
            v10 = 1.0;
          v5->m_Weight = 1.0 - v10;
        }
      }
      else if ( v5->m_Weight < 1.0 )
      {
        v9 = (float)((float)(*(float *)(gpGlobals.m_Index + 12) - m_LastEnterTime)
                   / (float)((float)(1.0 - v5->m_LastEnterWeight) * v5->m_FadeDuration))
           + v5->m_LastEnterWeight;
        if ( v9 > 1.0 )
          v9 = 1.0;
        v5->m_Weight = v9;
      }
    }
    else
    {
      v5->m_Weight = 0.0;
    }
    CColorCorrectionMgr::SetColorCorrectionWeight(
      this: g_pColorCorrectionMgr,
      h: v5->m_CCHandle,
      flWeight: v5->m_Weight * ccScale,
      bExclusive: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104118A0
// Name: DT_ColorCorrectionVolume::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrectionVolume::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ColorCorrectionVolume::g_RecvTable);
  return atexit(func: DT_ColorCorrectionVolume::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104118C0
// Name: DT_ColorCorrectionVolume::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrectionVolume::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ColorCorrectionVolume::ignored>();
  DT_ColorCorrectionVolume::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104118D0
// Name: C_ColorCorrectionVolume_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_ColorCorrectionVolume_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_ColorCorrectionVolume::m_PredMap.dataNumFields = 1;
  C_ColorCorrectionVolume::m_PredMap.dataDesc = (typedescription_t *)&unk_1059CF94;
}

//------------------------------------------------------------------------------
// Address: 0x10430120
// Name: DT_ColorCorrectionVolume::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ColorCorrectionVolume::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ColorCorrectionVolume::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100627F0
// Name: _C_ColorCorrectionVolume_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ColorCorrectionVolume_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xAE0u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3[608] = -1;
  *v3 = &C_ColorCorrectionVolume::`vftable'{for `IClientUnknown'};
  v3[1] = &C_ColorCorrectionVolume::`vftable'{for `IClientRenderable'};
  v3[2] = &C_ColorCorrectionVolume::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_ColorCorrectionVolume::`vftable'{for `IClientThinkable'};
  v3[4] = &C_ColorCorrectionVolume::`vftable';
  v3[695] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104118F0
// Name: _dynamic_initializer_for____g_C_DynamicLightClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_DynamicLightClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_DynamicLightClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_DynamicLightClientClass;
  return result;
}
