// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_largefunnel.cpp
// Functions: 8
// ============================================================

#include "game\client\c_te_largefunnel.h"

//------------------------------------------------------------------------------
// Address: 0x1025B620
// Name: public: virtual class ClientClass __near * C_TELargeFunnel::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TELargeFunnel::GetClientClass(C_TELargeFunnel *this)
{
  return &__g_C_TELargeFunnelClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1025B710
// Name: public: void C_TELargeFunnel::CreateFunnel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TELargeFunnel::CreateFunnel(C_TELargeFunnel *this)
{
  Vector *p_m_vecOrigin; // edi
  int v3; // ebx
  Particle *v4; // esi
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  char v8; // cl
  float vecDir; // [esp+14h] [ebp-20h]
  float vecDir_8; // [esp+1Ch] [ebp-18h]
  CParticleSubTexture *hMaterial; // [esp+20h] [ebp-14h]
  float v12; // [esp+24h] [ebp-10h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+2Ch] [ebp-8h] BYREF
  int i; // [esp+30h] [ebp-4h]

  CSimpleEmitter::Create(result: &pSimple, pDebugName: "TELargeFunnel");
  p_m_vecOrigin = &this->m_vecOrigin;
  CParticleEffect::SetSortOrigin(this: pSimple.m_pObj, vSortOrigin: p_m_vecOrigin);
  hMaterial = CParticleEffect::GetPMaterial(this: pSimple.m_pObj, name: "sprites/flare6");
  i = -256;
  do
  {
    v3 = -256;
    do
    {
      v4 = CParticleEffect::AddParticle(
             this: pSimple.m_pObj,
             particleSize: 0x3Cu,
             material: hMaterial,
             origin: p_m_vecOrigin);
      if ( v4 != nullptr )
      {
        v12 = (float)i;
        if ( this->m_nReversed != 0 )
        {
          vecDir = (float)i;
          v4->m_Pos.x = p_m_vecOrigin->x;
          v4->m_Pos.y = p_m_vecOrigin->y;
          v4->m_Pos.z = p_m_vecOrigin->z;
          vecDir_8 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                       a1: random,
                       a2: 1120403456,
                       a3: 1145569280);
          v5 = vecDir_8;
          v6 = (float)v3;
          v7 = vecDir;
          *(_WORD *)((char *)&v4[2].m_pPrev + 3) = 255;
        }
        else
        {
          v4->m_Pos.x = (float)i + p_m_vecOrigin->x;
          v4->m_Pos.y = (float)v3 + this->m_vecOrigin.y;
          v4->m_Pos.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                          a1: random,
                          a2: 1120403456,
                          a3: 1145569280)
                      + this->m_vecOrigin.z;
          v7 = p_m_vecOrigin->x - v4->m_Pos.x;
          v6 = p_m_vecOrigin->y - v4->m_Pos.y;
          v5 = p_m_vecOrigin->z - v4->m_Pos.z;
          *(_WORD *)((char *)&v4[2].m_pPrev + 3) = -256;
        }
        *(float *)&v4[1].m_pPrev = v7 * 0.25;
        *(float *)&v4[1].m_pNext = v6 * 0.25;
        *(float *)&v4[1].m_pSubTexture = v5 * 0.25;
        v4[1].m_Pos.z = 0.0;
        v4[1].m_Pos.y = 4.0;
        if ( random->RandomInt(this: random, a2: 0, a3: 10) >= 5 )
        {
          LOWORD(v4[2].m_pPrev) = -1;
          BYTE2(v4[2].m_pPrev) = -1;
          BYTE1(v4[2].m_pNext) = 15;
        }
        else
        {
          LOWORD(v4[2].m_pPrev) = -256;
          BYTE2(v4[2].m_pPrev) = 0;
          BYTE1(v4[2].m_pNext) = 4;
        }
        v8 = BYTE1(v4[2].m_pNext);
        v4[1].m_Pos.x = v12;
        BYTE2(v4[2].m_pNext) = v8;
        v4[2].m_pSubTexture = nullptr;
        HIBYTE(v4[2].m_pNext) = 0;
      }
      v3 += 24;
    }
    while ( v3 <= 256 );
    i += 24;
  }
  while ( i <= 256 );
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
}

//------------------------------------------------------------------------------
// Address: 0x1025B920
// Name: public: virtual void C_TELargeFunnel::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TELargeFunnel::PostDataUpdate(C_TELargeFunnel *this, DataUpdateType_t updateType)
{
  C_TELargeFunnel::CreateFunnel(this: (C_TELargeFunnel *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x1025B930
// Name: void TE_LargeFunnel(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_LargeFunnel(IRecipientFilter *filter, float delay, const Vector *pos, int modelindex, int reversed)
{
  float z; // xmm0_4

  _g_C_TELargeFunnel.m_vecOrigin.x = pos->x;
  _g_C_TELargeFunnel.m_vecOrigin.y = pos->y;
  z = pos->z;
  _g_C_TELargeFunnel.m_nReversed = reversed;
  _g_C_TELargeFunnel.m_vecOrigin.z = z;
  _g_C_TELargeFunnel.m_nModelIndex = modelindex;
  C_TELargeFunnel::CreateFunnel(this: &_g_C_TELargeFunnel);
}

//------------------------------------------------------------------------------
// Address: 0x1042C5C0
// Name: DT_TELargeFunnel::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TELargeFunnel::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TELargeFunnel::g_RecvTable);
  return atexit(func: DT_TELargeFunnel::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C5E0
// Name: DT_TELargeFunnel::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TELargeFunnel::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TELargeFunnel::ignored>();
  DT_TELargeFunnel::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436CA0
// Name: DT_TELargeFunnel::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TELargeFunnel::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TELargeFunnel::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1025B630
// Name: _C_TELargeFunnel_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TELargeFunnel_CreateObject()
{
  return &_g_C_TELargeFunnel.IClientNetworkable;
}
