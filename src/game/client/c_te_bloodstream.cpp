// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_bloodstream.cpp
// Functions: 12
// ============================================================

#include "game\client\c_te_bloodstream.h"

//------------------------------------------------------------------------------
// Address: 0x102562A0
// Name: public: virtual class ClientClass __near * C_TEBloodStream::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBloodStream::GetClientClass(C_TEBloodStream *this)
{
  return &__g_C_TEBloodStreamClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102563F0
// Name: RecordBloodStream
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordBloodStream(
        const Vector *direction@<edi>,
        const Vector *start,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a,
        int amount)
{
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  Color clr; // [esp+Ch] [ebp-4h]

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    clr._color[0] = r;
    clr._color[1] = g;
    clr._color[2] = b;
    clr._color[3] = a;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "TempEntity");
    else
      v8 = nullptr;
    KeyValues::SetInt(this: v8, keyName: "te", value: 15);
    KeyValues::SetString(this: v8, keyName: "name", value: "TE_BloodStream");
    KeyValues::SetFloat(this: v8, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v8, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v8, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v8, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v8, keyName: "directionx", value: direction->x);
    KeyValues::SetFloat(this: v8, keyName: "directiony", value: direction->y);
    KeyValues::SetFloat(this: v8, keyName: "directionz", value: direction->z);
    KeyValues::SetColor(this: v8, keyName: "color", value: clr);
    KeyValues::SetInt(this: v8, keyName: "amount", value: amount);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v8);
    KeyValues::deleteThis(this: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256560
// Name: void TE_BloodStream(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BloodStream(
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        const Vector *direction,
        int r,
        int g,
        int b,
        int a,
        int amount)
{
  int v9; // esi
  StandardParticle_t *v10; // edi
  double v11; // st7
  float v12; // xmm0_4
  float y; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  StandardParticle_t *v16; // eax
  StandardParticle_t *v17; // esi
  double v18; // st7
  float v19; // xmm1_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  float v21; // xmm0_4
  int v22; // eax
  int v23; // xmm0_4
  int i; // edi
  StandardParticle_t *v25; // eax
  StandardParticle_t *v26; // esi
  double v27; // st7
  unsigned __int8 v28; // dl
  float (__thiscall *v29)(IUniformRandomStream *, float, float); // eax
  double v30; // st7
  double v31; // st7
  float (__thiscall *v32)(IUniformRandomStream *, float, float); // eax
  double v33; // st7
  IUniformRandomStream_vtbl *v34; // edx
  double v35; // st7
  double v36; // st7
  float v37; // xmm3_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float dirCopy; // [esp+44h] [ebp-3Ch]
  float dirCopy_4; // [esp+48h] [ebp-38h]
  float dirCopy_8; // [esp+4Ch] [ebp-34h]
  Vector dir; // [esp+50h] [ebp-30h] BYREF
  float v45; // [esp+5Ch] [ebp-24h]
  float z; // [esp+60h] [ebp-20h]
  float x; // [esp+64h] [ebp-1Ch]
  int v48; // [esp+68h] [ebp-18h]
  int num; // [esp+6Ch] [ebp-14h]
  CSmartPtr<CTEParticleRenderer,CRefCountAccessor> pRen; // [esp+70h] [ebp-10h] BYREF
  float arc; // [esp+74h] [ebp-Ch]
  float v52; // [esp+78h] [ebp-8h]
  __int16 v53; // [esp+7Ch] [ebp-4h]
  unsigned __int8 v54; // [esp+7Eh] [ebp-2h]
  unsigned __int8 v55; // [esp+7Fh] [ebp-1h]

  v9 = amount;
  RecordBloodStream(start: org, direction, r, g, b, a, amount);
  CTEParticleRenderer::Create(result: &pRen, pDebugName: "TEBloodStream", vOrigin: org);
  if ( pRen.m_pObj != nullptr )
  {
    arc = 0.050000001;
    dir = *direction;
    VectorNormalize(vec: &dir);
    num = 100;
    do
    {
      v10 = CTEParticleRenderer::AddParticle(this: pRen.m_pObj);
      if ( v10 != nullptr )
      {
        v11 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1060320051,
                a3: 1065353216);
        v10->m_Color[1] = (int)(float)((float)g * 255.89999);
        v48 = (int)(v11 * (double)r * 255.89999);
        v10->m_Color[2] = (int)(float)((float)b * 255.89999);
        v10->m_Color[0] = v48;
        v10->m_Color[3] = (int)(float)((float)a * 255.89999);
        v10->m_Pos = *org;
        v10->m_Lifetime = 2.0;
        v12 = arc;
        v10->m_EffectData = 9;
        y = dir.y;
        v14 = dir.z - v12;
        v15 = v12 - 0.005;
        arc = v15;
        v10->m_Velocity.x = (float)v9 * dir.x;
        v10->m_Velocity.z = (float)v9 * v14;
        v10->m_Velocity.y = (float)v9 * y;
        v9 = (int)((double)v9 - 0.00001);
      }
      --num;
    }
    while ( *(float *)&num != 0.0 );
    arc = 0.075000003;
    if ( amount / 5 > 0 )
    {
      v48 = amount / 5;
      do
      {
        v16 = CTEParticleRenderer::AddParticle(this: pRen.m_pObj);
        v17 = v16;
        if ( v16 != nullptr )
        {
          v16->m_Lifetime = 3.0;
          v18 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1060320051,
                  a3: 1065353216);
          v17->m_Color[1] = (int)(float)((float)g * 255.89999);
          v55 = (int)(float)((float)g * 255.89999);
          num = (int)(v18 * (double)r * 255.89999);
          v17->m_Color[2] = (int)(float)((float)b * 255.89999);
          v17->m_Color[0] = num;
          v54 = (int)(float)((float)b * 255.89999);
          v19 = arc;
          v17->m_Color[3] = (int)(float)((float)a * 255.89999);
          HIBYTE(v53) = (int)(float)((float)a * 255.89999);
          v17->m_Pos = *org;
          v17->m_EffectData = 8;
          RandomFloat = random->RandomFloat;
          dirCopy = dir.x;
          dirCopy_4 = dir.y;
          dirCopy_8 = dir.z - v19;
          v21 = v19 - 0.005;
          arc = v21;
          *(float *)&num = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))RandomFloat)(
                             a1: random,
                             a2: 0,
                             a3: 1065353216);
          v22 = (int)(float)((float)amount * *(float *)&num);
          *(float *)&v23 = *(float *)&num * 1.7;
          num = v23;
          v45 = (float)v22;
          v17->m_Velocity.x = (float)v22 * (float)(dirCopy * *(float *)&v23);
          v17->m_Velocity.y = (float)v22 * (float)(dirCopy_4 * *(float *)&v23);
          v17->m_Velocity.z = (float)v22 * (float)(dirCopy_8 * *(float *)&v23);
          for ( i = 2; i != 0; --i )
          {
            v25 = CTEParticleRenderer::AddParticle(this: pRen.m_pObj);
            v26 = v25;
            if ( v25 != nullptr )
            {
              v25->m_Lifetime = 3.0;
              v27 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1060320051,
                      a3: 1065353216);
              v28 = v55;
              v26->m_Color[2] = v54;
              v26->m_Color[1] = v28;
              LODWORD(x) = (int)(v27 * 255.89999);
              v26->m_Color[0] = LOBYTE(x);
              v26->m_Color[3] = HIBYTE(v53);
              v29 = random->RandomFloat;
              v30 = org->y;
              z = org->z;
              v52 = v30;
              x = org->x;
              v31 = ((double (__stdcall *)(int, int))v29)(a1: -1082130432, a2: 1065353216);
              v32 = random->RandomFloat;
              x = v31 + x;
              v33 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v32)(
                      a1: random,
                      a2: -1082130432,
                      a3: 1065353216);
              v34 = random->__vftable;
              v52 = v33 + v52;
              v35 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v34->RandomFloat)(
                      a1: random,
                      a2: -1082130432,
                      a3: 1065353216);
              v36 = v35 + z;
              v37 = *(float *)&num;
              v38 = v45;
              v26->m_Pos.x = x;
              v26->m_Pos.y = v52;
              v26->m_Pos.z = v36;
              v26->m_EffectData = 8;
              v39 = dir.y * v37;
              v40 = (float)(dir.z - arc) * v37;
              v26->m_Velocity.x = v38 * (float)(dir.x * v37);
              v26->m_Velocity.y = v38 * v39;
              v26->m_Velocity.z = v38 * v40;
            }
          }
        }
        --v48;
      }
      while ( v48 != 0 );
    }
    if ( pRen.m_pObj != nullptr )
      CParticleEffect::Release(this: pRen.m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256AA0
// Name: public: virtual void C_TEBloodStream::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBloodStream::PostDataUpdate(C_TEBloodStream *this, DataUpdateType_t updateType)
{
  CBroadcastRecipientFilter filter; // [esp+24h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  C_RecipientFilter::AddAllPlayers(this: &filter);
  TE_BloodStream(
    &filter,
    delay: 0.0,
    org: (const Vector *)&this->m_pNextDynamic,
    direction: (const Vector *)&this->m_vecOrigin.z,
    r: LODWORD(this->m_vecDirection.z),
    g: this->r,
    b: this->g,
    a: this->b,
    amount: this->a);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10256B00
// Name: void TE_BloodStream(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BloodStream(IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  int Int; // eax
  Vector vecOrigin; // [esp+28h] [ebp-20h] BYREF
  Vector vecDirection; // [esp+34h] [ebp-14h] BYREF
  Color c; // [esp+40h] [ebp-8h] BYREF
  Color defaultColor; // [esp+44h] [ebp-4h] BYREF

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "directionx", defaultValue: 0.0);
  vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "directiony", defaultValue: 0.0);
  vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "directionz", defaultValue: 0.0);
  defaultColor = 0;
  KeyValues::GetColor(this: pKeyValues, result: &c, keyName: "color", &defaultColor);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "amount", defaultValue: 0);
  TE_BloodStream(
    filter,
    delay: 0.0,
    org: &vecOrigin,
    direction: &vecDirection,
    r: c._color[0],
    g: c._color[1],
    b: c._color[2],
    a: c._color[3],
    amount: Int);
}

//------------------------------------------------------------------------------
// Address: 0x1042B790
// Name: DT_TEBloodStream::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodStream::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBloodStream::g_RecvTable);
  return atexit(func: DT_TEBloodStream::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B7B0
// Name: DT_TEBloodStream::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodStream::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBloodStream::ignored>();
  DT_TEBloodStream::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436920
// Name: DT_TEBloodStream::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBloodStream::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBloodStream::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102562B0
// Name: _C_TEBloodStream_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBloodStream_CreateObject()
{
  return &_g_C_TEBloodStream.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B7C0
// Name: _dynamic_initializer_for____g_C_TEBreakModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBreakModel__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEBreakModel);
  _g_C_TEBreakModel.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBreakModel_vtbl *)&C_TEBreakModel::`vftable'{for `IClientUnknown'};
  _g_C_TEBreakModel.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBreakModel::`vftable'{for `IClientNetworkable'};
  _g_C_TEBreakModel.m_vecOrigin.x = 0.0;
  _g_C_TEBreakModel.m_vecOrigin.y = 0.0;
  _g_C_TEBreakModel.m_vecOrigin.z = 0.0;
  _g_C_TEBreakModel.m_angRotation.x = 0.0;
  _g_C_TEBreakModel.m_angRotation.y = 0.0;
  _g_C_TEBreakModel.m_angRotation.z = 0.0;
  _g_C_TEBreakModel.m_vecSize.x = 0.0;
  _g_C_TEBreakModel.m_vecSize.y = 0.0;
  _g_C_TEBreakModel.m_vecSize.z = 0.0;
  _g_C_TEBreakModel.m_vecVelocity.x = 0.0;
  _g_C_TEBreakModel.m_vecVelocity.y = 0.0;
  _g_C_TEBreakModel.m_vecVelocity.z = 0.0;
  _g_C_TEBreakModel.m_nModelIndex = 0;
  _g_C_TEBreakModel.m_nRandomization = 0;
  _g_C_TEBreakModel.m_nCount = 0;
  _g_C_TEBreakModel.m_fTime = 0.0;
  _g_C_TEBreakModel.m_nFlags = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBreakModel__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B870
// Name: _dynamic_initializer_for____g_C_TEBreakModelClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBreakModelClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBreakModelClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBreakModelClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436930
// Name: _dynamic_atexit_destructor_for____g_C_TEBloodStream__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBloodStream__()
{
  _g_C_TEBloodStream.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBloodStream_vtbl *)&C_TEBloodStream::`vftable'{for `IClientUnknown'};
  _g_C_TEBloodStream.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBloodStream::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEBloodStream);
}
