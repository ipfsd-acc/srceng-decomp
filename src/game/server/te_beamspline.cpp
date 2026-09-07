// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beamspline.cpp
// Functions: 10
// ============================================================

#include "game\server\te_beamspline.h"

//------------------------------------------------------------------------------
// Address: 0x1032DE20
// Name: public: virtual class ServerClass __near * CTEBeamSpline::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamSpline::GetServerClass(CTEBeamSpline *this)
{
  return &g_CTEBeamSpline_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032DF40
// Name: public: virtual void CTEBeamSpline::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBeamSpline::Test(CTEBeamSpline *this, const Vector *current_origin, const QAngle *current_angles)
{
  __int64 v4; // xmm0_8
  const QAngle *v5; // edi
  float x; // xmm7_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  Vector *p_m_vecStart; // eax
  float *v11; // edi
  unsigned int v12; // ecx
  int m_Value; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  CBroadcastRecipientFilter filter; // [esp+Ch] [ebp-44h] BYREF
  Vector right; // [esp+2Ch] [ebp-24h] BYREF
  Vector forward; // [esp+38h] [ebp-18h] BYREF
  Vector m_vecStart; // [esp+44h] [ebp-Ch] BYREF
  int i; // [esp+58h] [ebp+8h]
  const QAngle *current_anglesa; // [esp+5Ch] [ebp+Ch]

  if ( this->m_nPoints.m_Value != 6 )
    this->m_nPoints.m_Value = 6;
  v4 = *(_QWORD *)&current_origin->x;
  v5 = nullptr;
  m_vecStart.z = current_origin->z;
  *(_QWORD *)&m_vecStart.x = v4;
  m_vecStart.z = m_vecStart.z + 24.0;
  AngleVectors(angles: current_angles, &forward, &right, up: nullptr);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  x = forward.x;
  v7 = (float)((float)(forward.x * 100.0) + m_vecStart.x) - (float)(right.x * 128.0);
  v8 = (float)((float)(forward.y * 100.0) + m_vecStart.y) - (float)(right.y * 128.0);
  v9 = (float)((float)(forward.z * 100.0) + m_vecStart.z) - (float)(right.z * 128.0);
  m_vecStart.x = v7;
  m_vecStart.y = v8;
  m_vecStart.z = v9;
  i = 0;
  if ( this->m_nPoints.m_Value > 0 )
  {
    current_anglesa = nullptr;
    do
    {
      p_m_vecStart = &m_vecStart;
      v11 = (float *)((char *)&this->m_vecPoints + (_DWORD)v5);
      v12 = 12;
      while ( *(_DWORD *)((char *)&p_m_vecStart->x + (char *)v11 - (char *)&m_vecStart) == LODWORD(p_m_vecStart->x) )
      {
        v12 -= 4;
        p_m_vecStart = (Vector *)((char *)p_m_vecStart + 4);
        if ( v12 < 4 )
          goto LABEL_10;
      }
      *v11 = v7;
      v11[1] = v8;
      v11[2] = v9;
LABEL_10:
      m_Value = this->m_nPoints.m_Value;
      v5 = ++current_anglesa;
      v14 = (float)(128 / m_Value);
      v15 = right.z * v14;
      v16 = (float)(right.x * v14) + v7;
      v17 = (float)(right.y * v14) + v8;
      v18 = 30.0 / (double)m_Value;
      v7 = (float)(x * v18) + v16;
      v8 = (float)(forward.y * v18) + v17;
      v9 = (float)(forward.z * v18) + (float)(v15 + v9);
      m_vecStart.x = v7;
      m_vecStart.y = v8;
      m_vecStart.z = v9;
      ++i;
    }
    while ( i < m_Value );
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBeamSpline *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032E160
// Name: void TE_BeamSpline(class IRecipientFilter __near &,float,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamSpline(IRecipientFilter *filter, float delay, int points, Vector *rgPoints)
{
  int v4; // eax
  Vector *v5; // eax
  int v6; // edi
  float *v7; // edi
  unsigned int v8; // edx
  _DWORD *p_x; // ecx
  float *p_z; // eax
  int v11; // [esp+8h] [ebp-Ch]
  int v12; // [esp+10h] [ebp-4h]

  if ( g_TEBeamSpline.m_nPoints.m_Value != points )
    g_TEBeamSpline.m_nPoints.m_Value = points;
  v4 = 0;
  if ( points <= 0 )
    goto LABEL_14;
  v5 = rgPoints;
  v6 = (char *)&g_TEBeamSpline.m_vecPoints - (char *)rgPoints;
  v11 = (char *)&g_TEBeamSpline.m_vecPoints.m_Value[0].z - (char *)rgPoints;
  v12 = points;
  while ( 1 )
  {
    v7 = (float *)((char *)&v5->x + v6);
    v8 = 12;
    p_x = (_DWORD *)&v5->x;
    while ( *(_DWORD *)((char *)p_x + (char *)v7 - (char *)v5) == *p_x )
    {
      v8 -= 4;
      ++p_x;
      if ( v8 < 4 )
        goto LABEL_11;
    }
    *v7 = v5->x;
    *(float *)((char *)v5 + v11 - 4) = v5->y;
    *(float *)((char *)&v5->x + v11) = v5->z;
LABEL_11:
    ++v5;
    if ( --v12 == 0 )
      break;
    v6 = (char *)&g_TEBeamSpline.m_vecPoints - (char *)rgPoints;
  }
  if ( points < 16 )
  {
    v4 = points;
LABEL_14:
    p_z = &g_TEBeamSpline.m_vecPoints.m_Value[v4].z;
    do
    {
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      p_z += 3;
    }
    while ( (int)p_z < (int)&g_SendProps_215[0].m_pMatchingRecvProp );
  }
  CBaseTempEntity::Create(this: &g_TEBeamSpline, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416180
// Name: DT_TEBeamSpline::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamSpline::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamSpline::g_SendTable);
  return atexit(func: DT_TEBeamSpline::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104161A0
// Name: DT_TEBeamSpline::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamSpline::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamSpline::ignored>();
  DT_TEBeamSpline::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104220A0
// Name: DT_TEBeamSpline::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamSpline::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamSpline::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104161B0
// Name: _dynamic_initializer_for__g_TEBeamSpline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamSpline__()
{
  float *p_z; // eax

  CBaseTempEntity::CBaseTempEntity(this: &g_TEBeamSpline, name: "BeamSpline");
  g_TEBeamSpline.__vftable = (CTEBeamSpline_vtbl *)&CTEBeamSpline::`vftable';
  p_z = &g_TEBeamSpline.m_vecPoints.m_Value[0].z;
  do
  {
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z += 3;
  }
  while ( (int)p_z < (int)&g_SendProps_215[0].m_pMatchingRecvProp );
  if ( g_TEBeamSpline.m_nPoints.m_Value != 0 )
    g_TEBeamSpline.m_nPoints.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamSpline__);
}

//------------------------------------------------------------------------------
// Address: 0x10416210
// Name: _dynamic_initializer_for__g_CTEBloodSprite_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBloodSprite_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBloodSprite_ClassReg,
           pNetworkName: "CTEBloodSprite",
           pTable: &DT_TEBloodSprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104220B0
// Name: _dynamic_atexit_destructor_for__g_TEBeamSpline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamSpline__()
{
  g_TEBeamSpline.__vftable = (CTEBeamSpline_vtbl *)&CTEBeamSpline::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEBeamSpline);
}

//------------------------------------------------------------------------------
// Address: 0x104220D0
// Name: _ServerClassInit_DT_TEBeamSpline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamSpline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_330;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
