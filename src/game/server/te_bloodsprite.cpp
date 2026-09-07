// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_bloodsprite.cpp
// Functions: 11
// ============================================================

#include "game\server\te_bloodsprite.h"

//------------------------------------------------------------------------------
// Address: 0x1032E240
// Name: public: virtual class ServerClass __near * CTEBloodSprite::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBloodSprite::GetServerClass(CTEBloodSprite *this)
{
  return &g_CTEBloodSprite_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032E440
// Name: public: CTEBloodSprite::CTEBloodSprite(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEBloodSprite *__thiscall CTEBloodSprite::CTEBloodSprite(CTEBloodSprite *this, const char *name)
{
  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTEBloodSprite_vtbl *)&CTEBloodSprite::`vftable';
  if ( this->m_vecOrigin.m_Value.x != 0.0 || this->m_vecOrigin.m_Value.y != 0.0 || this->m_vecOrigin.m_Value.z != 0.0 )
  {
    this->m_vecOrigin.m_Value.x = 0.0;
    this->m_vecOrigin.m_Value.y = 0.0;
    this->m_vecOrigin.m_Value.z = 0.0;
  }
  if ( this->m_nSprayModel.m_Value != 0 )
    this->m_nSprayModel.m_Value = 0;
  if ( this->m_nDropModel.m_Value != 0 )
    this->m_nDropModel.m_Value = 0;
  if ( this->r.m_Value != 0 )
    this->r.m_Value = 0;
  if ( this->g.m_Value != 0 )
    this->g.m_Value = 0;
  if ( this->b.m_Value != 0 )
    this->b.m_Value = 0;
  if ( this->a.m_Value != 0 )
    this->a.m_Value = 0;
  if ( this->m_nSize.m_Value != 0 )
    this->m_nSize.m_Value = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1032E4D0
// Name: public: virtual void CTEBloodSprite::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBloodSprite::Test(
        CTEBloodSprite *this,
        CNetworkVectorBase<Vector,CTEBloodSprite::NetworkVar_m_vecOrigin> *current_origin,
        const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  if ( this->r.m_Value != 255 )
    this->r.m_Value = 255;
  if ( this->g.m_Value != 255 )
    this->g.m_Value = 255;
  if ( this->b.m_Value != 63 )
    this->b.m_Value = 63;
  if ( this->a.m_Value != 255 )
    this->a.m_Value = 255;
  if ( this->m_nSize.m_Value != 16 )
    this->m_nSize.m_Value = 16;
  if ( current_origin->m_Value.x != this->m_vecOrigin.m_Value.x
    || current_origin->m_Value.y != this->m_vecOrigin.m_Value.y
    || current_origin->m_Value.z != this->m_vecOrigin.m_Value.z )
  {
    this->m_vecOrigin = *current_origin;
  }
  if ( this->m_nSprayModel.m_Value != g_sModelIndexBloodSpray )
    this->m_nSprayModel.m_Value = g_sModelIndexBloodSpray;
  if ( this->m_nDropModel.m_Value != g_sModelIndexBloodDrop )
    this->m_nDropModel.m_Value = g_sModelIndexBloodDrop;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecOrigin.m_Value.x = (float)(forward.x * 50.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBloodSprite *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032E620
// Name: void TE_BloodSprite(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BloodSprite(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEBloodSprite::NetworkVar_m_vecOrigin> *org,
        CNetworkVectorBase<Vector,CTEBloodSprite::NetworkVar_m_vecDirection> *dir,
        int r,
        int g,
        int b,
        int a,
        int size)
{
  if ( org->m_Value.x != g_TEBloodSprite.m_vecOrigin.m_Value.x
    || org->m_Value.y != g_TEBloodSprite.m_vecOrigin.m_Value.y
    || org->m_Value.z != g_TEBloodSprite.m_vecOrigin.m_Value.z )
  {
    g_TEBloodSprite.m_vecOrigin = *org;
  }
  if ( dir->m_Value.x != g_TEBloodSprite.m_vecDirection.m_Value.x
    || dir->m_Value.y != g_TEBloodSprite.m_vecDirection.m_Value.y
    || dir->m_Value.z != g_TEBloodSprite.m_vecDirection.m_Value.z )
  {
    g_TEBloodSprite.m_vecDirection = *dir;
  }
  if ( g_TEBloodSprite.r.m_Value != r )
    g_TEBloodSprite.r.m_Value = r;
  if ( g_TEBloodSprite.g.m_Value != g )
    g_TEBloodSprite.g.m_Value = g;
  if ( g_TEBloodSprite.b.m_Value != b )
    g_TEBloodSprite.b.m_Value = b;
  if ( g_TEBloodSprite.a.m_Value != a )
    g_TEBloodSprite.a.m_Value = a;
  if ( g_TEBloodSprite.m_nSize.m_Value != size )
    g_TEBloodSprite.m_nSize.m_Value = size;
  if ( g_TEBloodSprite.m_nSprayModel.m_Value != g_sModelIndexBloodSpray )
    g_TEBloodSprite.m_nSprayModel.m_Value = g_sModelIndexBloodSpray;
  if ( g_TEBloodSprite.m_nDropModel.m_Value != g_sModelIndexBloodDrop )
    g_TEBloodSprite.m_nDropModel.m_Value = g_sModelIndexBloodDrop;
  CBaseTempEntity::Create(this: &g_TEBloodSprite, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416230
// Name: DT_TEBloodSprite::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodSprite::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBloodSprite::g_SendTable);
  return atexit(func: DT_TEBloodSprite::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416250
// Name: DT_TEBloodSprite::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodSprite::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBloodSprite::ignored>();
  DT_TEBloodSprite::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104220F0
// Name: DT_TEBloodSprite::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBloodSprite::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBloodSprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416260
// Name: _dynamic_initializer_for__g_TEBloodSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBloodSprite__()
{
  CTEBloodSprite::CTEBloodSprite(this: &g_TEBloodSprite, name: "Blood Sprite");
  return atexit(func: dynamic_atexit_destructor_for__g_TEBloodSprite__);
}

//------------------------------------------------------------------------------
// Address: 0x10416280
// Name: _dynamic_initializer_for__g_CTEBloodStream_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBloodStream_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBloodStream_ClassReg,
           pNetworkName: "CTEBloodStream",
           pTable: &DT_TEBloodStream::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422100
// Name: _dynamic_atexit_destructor_for__g_TEBloodSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBloodSprite__()
{
  g_TEBloodSprite.__vftable = (CTEBloodSprite_vtbl *)&CTEBloodSprite::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEBloodSprite);
}

//------------------------------------------------------------------------------
// Address: 0x10422120
// Name: _ServerClassInit_DT_TEBloodSprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBloodSprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_331;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
