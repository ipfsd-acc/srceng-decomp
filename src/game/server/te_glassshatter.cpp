// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_glassshatter.cpp
// Functions: 11
// ============================================================

#include "game\server\te_glassshatter.h"

//------------------------------------------------------------------------------
// Address: 0x10331F90
// Name: public: virtual class ServerClass __near * CTEShatterSurface::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEShatterSurface::GetServerClass(CTEShatterSurface *this)
{
  return &g_CTEShatterSurface_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103322C0
// Name: public: CTEShatterSurface::CTEShatterSurface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEShatterSurface *__thiscall CTEShatterSurface::CTEShatterSurface(CTEShatterSurface *this, const char *name)
{
  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTEShatterSurface_vtbl *)&CTEShatterSurface::`vftable';
  if ( this->m_vecOrigin.m_Value.x != 0.0 || this->m_vecOrigin.m_Value.y != 0.0 || this->m_vecOrigin.m_Value.z != 0.0 )
  {
    this->m_vecOrigin.m_Value.x = 0.0;
    this->m_vecOrigin.m_Value.y = 0.0;
    this->m_vecOrigin.m_Value.z = 0.0;
  }
  if ( this->m_vecAngles.m_Value.x != 0.0 || this->m_vecAngles.m_Value.y != 0.0 || this->m_vecAngles.m_Value.z != 0.0 )
  {
    this->m_vecAngles.m_Value.x = 0.0;
    this->m_vecAngles.m_Value.y = 0.0;
    this->m_vecAngles.m_Value.z = 0.0;
  }
  if ( this->m_vecForce.m_Value.x != 0.0 || this->m_vecForce.m_Value.y != 0.0 || this->m_vecForce.m_Value.z != 0.0 )
  {
    this->m_vecForce.m_Value.x = 0.0;
    this->m_vecForce.m_Value.y = 0.0;
    this->m_vecForce.m_Value.z = 0.0;
  }
  if ( this->m_vecForcePos.m_Value.x != 0.0
    || this->m_vecForcePos.m_Value.y != 0.0
    || this->m_vecForcePos.m_Value.z != 0.0 )
  {
    this->m_vecForcePos.m_Value.x = 0.0;
    this->m_vecForcePos.m_Value.y = 0.0;
    this->m_vecForcePos.m_Value.z = 0.0;
  }
  if ( this->m_flWidth.m_Value != 16.0 )
    this->m_flWidth.m_Value = 16.0;
  if ( this->m_flHeight.m_Value != 16.0 )
    this->m_flHeight.m_Value = 16.0;
  if ( this->m_flShardSize.m_Value != 3.0 )
    this->m_flShardSize.m_Value = 3.0;
  if ( this->m_uchFrontColor.m_Value[0] != 0xFF )
    this->m_uchFrontColor.m_Value[0] = -1;
  if ( this->m_uchFrontColor.m_Value[1] != 0xFF )
    this->m_uchFrontColor.m_Value[1] = -1;
  if ( this->m_uchFrontColor.m_Value[2] != 0xFF )
    this->m_uchFrontColor.m_Value[2] = -1;
  if ( this->m_uchBackColor.m_Value[0] != 0xFF )
    this->m_uchBackColor.m_Value[0] = -1;
  if ( this->m_uchBackColor.m_Value[1] != 0xFF )
    this->m_uchBackColor.m_Value[1] = -1;
  if ( this->m_uchBackColor.m_Value[2] != 0xFF )
    this->m_uchBackColor.m_Value[2] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10332410
// Name: public: virtual void CTEShatterSurface::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEShatterSurface::Test(
        CTEShatterSurface *this,
        const Vector *current_origin,
        const QAngle *current_angles)
{
  CNetworkVectorBase<Vector,CTEShatterSurface::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  CGameTrace tr; // [esp+Ch] [ebp-8Ch] BYREF
  CBroadcastRecipientFilter filter; // [esp+60h] [ebp-38h] BYREF
  Vector vecEnd; // [esp+80h] [ebp-18h] BYREF
  Vector forward; // [esp+8Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  p_m_vecOrigin = &this->m_vecOrigin;
  if ( current_origin->x != this->m_vecOrigin.m_Value.x
    || current_origin->y != this->m_vecOrigin.m_Value.y
    || current_origin->z != this->m_vecOrigin.m_Value.z )
  {
    p_m_vecOrigin->m_Value.x = current_origin->x;
    this->m_vecOrigin.m_Value.y = current_origin->y;
    this->m_vecOrigin.m_Value.z = current_origin->z;
  }
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  x = forward.x;
  p_m_vecOrigin->m_Value.x = (float)(forward.x * 50.0) + p_m_vecOrigin->m_Value.x;
  y = forward.y;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  z = forward.z;
  v8 = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  this->m_vecOrigin.m_Value.z = v8;
  v9 = (float)(y * 1024.0) + this->m_vecOrigin.m_Value.y;
  vecEnd.x = (float)(x * 1024.0) + p_m_vecOrigin->m_Value.x;
  vecEnd.y = v9;
  vecEnd.z = (float)(z * 1024.0) + v8;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)p_m_vecOrigin,
    vecAbsStart: &this->m_vecOrigin.m_Value,
    vecAbsEnd: &vecEnd,
    mask: 0x400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  v10 = tr.endpos.z;
  v11 = tr.endpos.y;
  if ( tr.endpos.x != p_m_vecOrigin->m_Value.x
    || tr.endpos.y != this->m_vecOrigin.m_Value.y
    || tr.endpos.z != this->m_vecOrigin.m_Value.z )
  {
    p_m_vecOrigin->m_Value.x = tr.endpos.x;
    this->m_vecOrigin.m_Value.y = v11;
    this->m_vecOrigin.m_Value.z = v10;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEShatterSurface *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x103325A0
// Name: void TE_ShatterSurface(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,class Vector const __near *,class Vector const __near *,float,float,float,enum ShatterSurface_t,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ShatterSurface(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEShatterSurface::NetworkVar_m_vecOrigin> *pos,
        CNetworkVectorBase<QAngle,CTEShatterSurface::NetworkVar_m_vecAngles> *angle,
        CNetworkVectorBase<Vector,CTEShatterSurface::NetworkVar_m_vecForce> *force,
        CNetworkVectorBase<Vector,CTEShatterSurface::NetworkVar_m_vecForcePos> *forcepos,
        float width,
        float height,
        float shardsize,
        ShatterSurface_t surfacetype,
        unsigned __int8 front_r,
        unsigned __int8 front_g,
        unsigned __int8 front_b,
        unsigned __int8 back_r,
        unsigned __int8 back_g,
        unsigned __int8 back_b)
{
  if ( pos->m_Value.x != g_TEShatterSurface.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEShatterSurface.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEShatterSurface.m_vecOrigin.m_Value.z )
  {
    g_TEShatterSurface.m_vecOrigin = *pos;
  }
  if ( angle->m_Value.x != g_TEShatterSurface.m_vecAngles.m_Value.x
    || angle->m_Value.y != g_TEShatterSurface.m_vecAngles.m_Value.y
    || angle->m_Value.z != g_TEShatterSurface.m_vecAngles.m_Value.z )
  {
    g_TEShatterSurface.m_vecAngles = *angle;
  }
  if ( force->m_Value.x != g_TEShatterSurface.m_vecForce.m_Value.x
    || force->m_Value.y != g_TEShatterSurface.m_vecForce.m_Value.y
    || force->m_Value.z != g_TEShatterSurface.m_vecForce.m_Value.z )
  {
    g_TEShatterSurface.m_vecForce = *force;
  }
  if ( forcepos->m_Value.x != g_TEShatterSurface.m_vecForcePos.m_Value.x
    || forcepos->m_Value.y != g_TEShatterSurface.m_vecForcePos.m_Value.y
    || forcepos->m_Value.z != g_TEShatterSurface.m_vecForcePos.m_Value.z )
  {
    g_TEShatterSurface.m_vecForcePos = *forcepos;
  }
  if ( g_TEShatterSurface.m_flWidth.m_Value != width )
    g_TEShatterSurface.m_flWidth.m_Value = width;
  if ( g_TEShatterSurface.m_flHeight.m_Value != height )
    g_TEShatterSurface.m_flHeight.m_Value = height;
  if ( g_TEShatterSurface.m_flShardSize.m_Value != shardsize )
    g_TEShatterSurface.m_flShardSize.m_Value = shardsize;
  if ( g_TEShatterSurface.m_nSurfaceType.m_Value != surfacetype )
    g_TEShatterSurface.m_nSurfaceType.m_Value = surfacetype;
  if ( front_r != g_TEShatterSurface.m_uchFrontColor.m_Value[0] )
    g_TEShatterSurface.m_uchFrontColor.m_Value[0] = front_r;
  if ( front_g != g_TEShatterSurface.m_uchFrontColor.m_Value[1] )
    g_TEShatterSurface.m_uchFrontColor.m_Value[1] = front_g;
  if ( front_b != g_TEShatterSurface.m_uchFrontColor.m_Value[2] )
    g_TEShatterSurface.m_uchFrontColor.m_Value[2] = front_b;
  if ( back_r != g_TEShatterSurface.m_uchBackColor.m_Value[0] )
    g_TEShatterSurface.m_uchBackColor.m_Value[0] = back_r;
  if ( back_g != g_TEShatterSurface.m_uchBackColor.m_Value[1] )
    g_TEShatterSurface.m_uchBackColor.m_Value[1] = back_g;
  if ( back_b != g_TEShatterSurface.m_uchBackColor.m_Value[2] )
    g_TEShatterSurface.m_uchBackColor.m_Value[2] = back_b;
  CBaseTempEntity::Create(this: &g_TEShatterSurface, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416EB0
// Name: DT_TEShatterSurface::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShatterSurface::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEShatterSurface::g_SendTable);
  return atexit(func: DT_TEShatterSurface::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416ED0
// Name: DT_TEShatterSurface::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShatterSurface::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEShatterSurface::ignored>();
  DT_TEShatterSurface::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104225A0
// Name: DT_TEShatterSurface::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEShatterSurface::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEShatterSurface::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416EE0
// Name: _dynamic_initializer_for__g_TEShatterSurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEShatterSurface__()
{
  CTEShatterSurface::CTEShatterSurface(this: &g_TEShatterSurface, name: "Surface Shatter");
  return atexit(func: dynamic_atexit_destructor_for__g_TEShatterSurface__);
}

//------------------------------------------------------------------------------
// Address: 0x10416F00
// Name: _dynamic_initializer_for__g_CTEGlowSprite_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEGlowSprite_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEGlowSprite_ClassReg,
           pNetworkName: "CTEGlowSprite",
           pTable: &DT_TEGlowSprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104225B0
// Name: _dynamic_atexit_destructor_for__g_TEShatterSurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEShatterSurface__()
{
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEShatterSurface);
}

//------------------------------------------------------------------------------
// Address: 0x104225C0
// Name: _ServerClassInit_DT_TEShatterSurface::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEShatterSurface::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_346;
  for ( i = 15; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
