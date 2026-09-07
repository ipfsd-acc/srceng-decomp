// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_spotlight_end.cpp
// Functions: 12
// ============================================================

#include "game\client\c_spotlight_end.h"

//------------------------------------------------------------------------------
// Address: 0x1008E2A0
// Name: public: virtual void C_SpotlightEnd::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpotlightEnd::OnDataChanged(C_SpotlightEnd *this, DataUpdateType_t updateType)
{
  if ( updateType == DATA_UPDATE_CREATED )
    (*(void (__stdcall **)(int))(*((_DWORD *)this - 2) + 456))(a1: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x1008E2D0
// Name: public: virtual class ClientClass __near * C_SpotlightEnd::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SpotlightEnd::GetClientClass(C_SpotlightEnd *this)
{
  return &__g_C_SpotlightEndClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1008E410
// Name: public: virtual void C_SpotlightEnd::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpotlightEnd::ClientThink(C_SpotlightEnd *this)
{
  unsigned __int8 index; // bl
  float v3; // xmm0_4
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  float v8; // xmm0_4
  int v9; // xmm1_4
  int v10; // xmm2_4
  int v11; // eax
  ColorRGBExp32 color; // [esp+14h] [ebp-8h]
  __int16 c_1; // [esp+19h] [ebp-3h]

  if ( *(float *)&this->m_CalcAbsoluteVelocityMutex.m_depth > 0.0 )
  {
    index = this->index;
    c_1 = *(_WORD *)((char *)&this->index + 1);
    v3 = (float)C_BaseEntity::GetRenderAlpha(this: (C_SpotlightEnd *)((char *)this - 12)) * 0.0039215689;
    v4 = (int)(float)((float)(unsigned __int8)c_1 * v3);
    v5 = (int)(float)((float)HIBYTE(c_1) * v3);
    color.r = (int)(float)((float)index * v3);
    color.g = v4;
    *(_WORD *)&color.b = (unsigned __int8)v5;
    if ( color.r != 0 || (_BYTE)v4 != 0 || (_BYTE)v5 != 0 )
    {
      v6 = *((_DWORD *)&this->m_bIsBlurred + 1);
      if ( v6 == 0 || *(_DWORD *)(v6 + 36) != DWORD1(this->m_pfnTouch) )
        *((_DWORD *)&this->m_bIsBlurred + 1) = effects->CL_AllocDlight(this: effects, a2: DWORD1(this->m_pfnTouch));
      *(float *)(*((_DWORD *)&this->m_bIsBlurred + 1) + 16) = *(float *)&this->m_CalcAbsoluteVelocityMutex.m_depth * 3.0;
      v7 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40))(a1: (char *)this - 12);
      v8 = *(float *)(v7 + 8);
      v9 = *(_DWORD *)v7;
      v10 = *(_DWORD *)(v7 + 4);
      v11 = *((_DWORD *)&this->m_bIsBlurred + 1);
      *(float *)(v11 + 12) = v8 + 5.0;
      *(_DWORD *)(v11 + 4) = v9;
      *(_DWORD *)(v11 + 8) = v10;
      *(float *)(*((_DWORD *)&this->m_bIsBlurred + 1) + 24) = *(float *)(gpGlobals.m_Index + 12) + 0.050000001;
      *(ColorRGBExp32 *)(*((_DWORD *)&this->m_bIsBlurred + 1) + 20) = color;
      (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 3) + 456))(a1: (char *)this - 12, a2: -996040704);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413A10
// Name: DT_SpotlightEnd::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpotlightEnd::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SpotlightEnd::g_RecvTable);
  return atexit(func: DT_SpotlightEnd::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413A30
// Name: DT_SpotlightEnd::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpotlightEnd::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SpotlightEnd::ignored>();
  DT_SpotlightEnd::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430BC0
// Name: DT_SpotlightEnd::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpotlightEnd::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SpotlightEnd::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1008E2E0
// Name: _C_SpotlightEnd_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SpotlightEnd_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x990u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_SpotlightEnd::`vftable'{for `IClientUnknown'};
  v3[1] = &C_SpotlightEnd::`vftable'{for `IClientRenderable'};
  v3[2] = &C_SpotlightEnd::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_SpotlightEnd::`vftable'{for `IClientThinkable'};
  v3[4] = &C_SpotlightEnd::`vftable';
  v3[610] = 0;
  v3[608] = 1120403456;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10413A40
// Name: _dynamic_initializer_for__r_drawsprites__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawsprites__()
{
  ConVar::ConVar(this: &r_drawsprites, pName: "r_drawsprites", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawsprites__);
}

//------------------------------------------------------------------------------
// Address: 0x10413A70
// Name: _dynamic_initializer_for__g_ClientsideSprites__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClientsideSprites__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClientsideSprites__);
}

//------------------------------------------------------------------------------
// Address: 0x10413A80
// Name: _dynamic_initializer_for____g_C_ParticlePerformanceMonitorClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ParticlePerformanceMonitorClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ParticlePerformanceMonitorClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ParticlePerformanceMonitorClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430BD0
// Name: _dynamic_atexit_destructor_for__r_drawsprites__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawsprites__()
{
  ConVar::~ConVar(this: &r_drawsprites);
}

//------------------------------------------------------------------------------
// Address: 0x10430BE0
// Name: _dynamic_atexit_destructor_for__g_ClientsideSprites__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientsideSprites__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ClientsideSprites);
}
