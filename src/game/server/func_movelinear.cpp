// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_movelinear.cpp
// Functions: 25
// ============================================================

#include "game\server\func_movelinear.h"

//------------------------------------------------------------------------------
// Address: 0x1013BEA0
// Name: public: virtual struct datamap_t __near * CFuncMoveLinear::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncMoveLinear::GetDataDescMap(CFuncMoveLinear *this)
{
  return &CFuncMoveLinear::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013BEB0
// Name: public: virtual class ServerClass __near * CFuncMoveLinear::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncMoveLinear::GetServerClass(CFuncMoveLinear *this)
{
  return &g_CFuncMoveLinear_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1013BEC0
// Name: public: virtual bool CFuncMoveLinear::ShouldSavePhysics(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFuncMoveLinear::ShouldSavePhysics(CFuncMoveLinear *this)
{
  return this == nullptr
      || this->m_iClassname.pszValue != "func_water_analog"
      && CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "func_water_analog") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013BF00
// Name: public: virtual void CFuncMoveLinear::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::Precache(CFuncMoveLinear *this)
{
  const char *pszValue; // eax
  const char *v3; // eax

  if ( this->m_soundStart.pszValue != nullptr )
  {
    pszValue = this->m_soundStart.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CBaseEntity::PrecacheScriptSound(soundname: pszValue);
  }
  if ( this->m_soundStop.pszValue != nullptr )
  {
    v3 = this->m_soundStop.pszValue;
    if ( v3 == nullptr )
      v3 = locale;
    CBaseEntity::PrecacheScriptSound(soundname: v3);
  }
  this->m_currentSound.pszValue = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013BF60
// Name: public: virtual void CFuncMoveLinear::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::Blocked(CFuncMoveLinear *this, CBaseEntity *pOther)
{
  float flDamage; // xmm0_4
  const CTakeDamageInfo *v3; // eax
  CTakeDamageInfo v4; // [esp+14h] [ebp-5Ch] BYREF

  flDamage = this->m_flBlockDamage;
  if ( flDamage != 0.0 )
  {
    if ( pOther->m_takedamage.m_Value == 1 )
    {
      if ( pOther->m_iClassname.pszValue == "gib"
        || CBaseEntity::ClassMatchesComplex(this: pOther, pszClassOrWildcard: "gib") != 0 )
      {
        UTIL_Remove(oldObj: pOther);
      }
    }
    else
    {
      v3 = CTakeDamageInfo::CTakeDamageInfo(
             this: &v4,
             pInflictor: this,
             pAttacker: this,
             flDamage,
             bitsDamageType: 1,
             iKillType: 0,
             iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this: pOther, a2: (int)pOther, inputInfo: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C0D0
// Name: public: virtual bool CFuncMoveLinear::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFuncMoveLinear::CreateVPhysics(CFuncMoveLinear *this)
{
  IPhysicsObject *inited; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v4; // edx
  IPhysicsObject *v5; // ebx
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v7; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v8; // edx
  fluidparams_t fluid; // [esp+4h] [ebp-38h] BYREF
  int v10; // [esp+38h] [ebp-4h]

  if ( this != nullptr
    && (this->m_iClassname.pszValue == "func_water_analog"
     || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "func_water_analog") != 0) )
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x20);
    inited = CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
    v4 = this->m_Collision.CBaseToggle::CBaseEntity::__vftable;
    fluid.damping = 0.0099999998;
    v5 = inited;
    OBBMaxs = v4->OBBMaxs;
    fluid.surfacePlane.x = 0.0;
    fluid.surfacePlane.y = 0.0;
    fluid.surfacePlane.z = 1.0;
    v7 = (int)OBBMaxs(this: &this->m_Collision);
    v8 = this->m_Collision.CBaseToggle::CBaseEntity::__vftable;
    v10 = v7 + 8;
    fluid.surfacePlane.w = (float)(v8->GetCollisionOrigin(this: &this->m_Collision)->z + *(float *)(v7 + 8)) - 1.0;
    memset((void *)&fluid.currentVelocity, 0, sizeof(fluid.currentVelocity));
    fluid.torqueFactor = 0.1;
    fluid.viscosityFactor = 0.0099999998;
    fluid.pGameData = this;
    fluid.contents = 32;
    this->m_pFluidController = physenv->CreateFluidController(this: physenv, a2: v5, a3: &fluid);
  }
  else if ( (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0 )
  {
    CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013C200
// Name: public: void CFuncMoveLinear::InputSetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::InputSetSpeed(CFuncMoveLinear *this, inputdata_t *inputdata)
{
  float flSpeed; // xmm3_4
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flSpeed = inputdata->value.flVal;
  else
    flSpeed = 0.0;
  this->m_flSpeed = flSpeed;
  if ( (float)((float)((float)((float)(this->m_vecFinalDest.m_Value.x - this->m_vecOrigin.m_Value.x)
                             * (float)(this->m_vecFinalDest.m_Value.x - this->m_vecOrigin.m_Value.x))
                     + (float)((float)(this->m_vecFinalDest.m_Value.y - this->m_vecOrigin.m_Value.y)
                             * (float)(this->m_vecFinalDest.m_Value.y - this->m_vecOrigin.m_Value.y)))
             + (float)((float)(this->m_vecFinalDest.m_Value.z - this->m_vecOrigin.m_Value.z)
                     * (float)(this->m_vecFinalDest.m_Value.z - this->m_vecOrigin.m_Value.z))) > 1.4210855e-14 )
  {
    if ( COERCE_FLOAT(LODWORD(flSpeed) & _mask__AbsFloat_) <= 0.00000011920929 )
    {
      this->m_flSpeed = 1.0;
      CBaseToggle::LinearMove(this, a2: (int)&savedregs, vecDest: &this->m_vecOrigin.m_Value, flSpeed: 1.0);
    }
    else
    {
      CBaseToggle::LinearMove(this, a2: (int)&savedregs, vecDest: &this->m_vecFinalDest.m_Value, flSpeed);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C2C0
// Name: public: virtual int CFuncMoveLinear::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall CFuncMoveLinear::DrawDebugTextOverlays@<eax>(CFuncMoveLinear *this@<ecx>, int a2@<ebp>)
{
  int result; // eax
  int v4; // edi
  float x; // xmm1_4
  float v6; // xmm3_4
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  int v10; // edi
  char v11[12]; // [esp+24h] [ebp-23Ch] BYREF
  __int128 tempstr_500; // [esp+224h] [ebp-3Ch] OVERLAPPED
  __int128 v13; // [esp+234h] [ebp-2Ch]
  float v14; // [esp+250h] [ebp-10h]
  int v15; // [esp+254h] [ebp-Ch]
  void *v16; // [esp+258h] [ebp-8h]
  void *retaddr; // [esp+260h] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  result = CBaseEntity::DrawDebugTextOverlays(this);
  v4 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    x = this->m_vecPosition1.x;
    v6 = (float)((float)((float)(this->m_vecPosition1.y - this->m_vecPosition2.y)
                       * (float)(this->m_vecPosition1.y - this->m_vecPosition2.y))
               + (float)((float)(this->m_vecPosition1.z - this->m_vecPosition2.z)
                       * (float)(this->m_vecPosition1.z - this->m_vecPosition2.z)))
       + (float)((float)(x - this->m_vecPosition2.x) * (float)(x - this->m_vecPosition2.x));
    v7 = 0;
    *(float *)&v7 = fsqrt(
                      (float)((float)((float)(this->m_vecPosition1.y - this->m_vecOrigin.m_Value.y)
                                    * (float)(this->m_vecPosition1.y - this->m_vecOrigin.m_Value.y))
                            + (float)((float)(this->m_vecPosition1.z - this->m_vecOrigin.m_Value.z)
                                    * (float)(this->m_vecPosition1.z - this->m_vecOrigin.m_Value.z)))
                    + (float)((float)(x - this->m_vecOrigin.m_Value.x) * (float)(x - this->m_vecOrigin.m_Value.x)));
    v8 = 0;
    v13 = v7;
    *(float *)&v8 = fsqrt(v6);
    tempstr_500 = v8;
    v14 = 1.0 / *(float *)&v8;
    V_snprintf(
      pDest: v11,
      maxLen: 512,
      pFormat: "Current Pos: %3.3f",
      (float)((float)(1.0 / *(float *)&v8) * *(float *)&v7));
    CBaseEntity::EntityText(this, text_offset: v4, text: v11, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    *(float *)&v7 = this->m_vecPosition1.x - this->m_vecFinalDest.m_Value.x;
    *(float *)&v8 = (float)((float)((float)(this->m_vecPosition1.y - this->m_vecFinalDest.m_Value.y)
                                  * (float)(this->m_vecPosition1.y - this->m_vecFinalDest.m_Value.y))
                          + (float)((float)(this->m_vecPosition1.z - this->m_vecFinalDest.m_Value.z)
                                  * (float)(this->m_vecPosition1.z - this->m_vecFinalDest.m_Value.z)))
                  + (float)(*(float *)&v7 * *(float *)&v7);
    v9 = 0;
    *(float *)&v9 = fsqrt(*(float *)&v8);
    v13 = v9;
    v10 = v4 + 1;
    V_snprintf(pDest: v11, maxLen: 512, pFormat: "Target Pos: %3.3f", (float)(v14 * *(float *)&v9));
    CBaseEntity::EntityText(this, text_offset: v10, text: v11, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v10 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013C4F0
// Name: public: virtual void CFuncMoveLinear::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFuncMoveLinear::Spawn(CFuncMoveLinear *this@<ecx>, int a2@<edi>)
{
  Vector *p_m_vecMoveDir; // edi
  const char *v4; // eax
  Vector *v5; // eax
  float z; // ecx
  float v7; // xmm0_4
  float m_flMoveDistance; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float m_flStartPosition; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  edict_t *m_pPev; // ecx
  void (__thiscall *Precache)(CBaseEntity *); // edx
  QAngle angMoveDir; // [esp+4h] [ebp-1Ch] BYREF
  Vector vecOBB; // [esp+10h] [ebp-10h]
  _BYTE v22[4]; // [esp+1Ch] [ebp-4h] BYREF

  p_m_vecMoveDir = &this->m_vecMoveDir;
  angMoveDir = (QAngle)this->m_vecMoveDir;
  AngleVectors(angles: &angMoveDir, forward: &this->m_vecMoveDir);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  v4 = *(const char **)((int (__thiscall *)(CFuncMoveLinear *, _BYTE *, int))this->GetModelName)(
                         a1: this,
                         a2: v22,
                         a3: a2);
  if ( v4 == nullptr )
    v4 = locale;
  this->SetModel(this, a2: v4);
  if ( this->m_flSpeed <= 0.0 )
    this->m_flSpeed = 100.0;
  if ( this->m_flMoveDistance <= 0.0 )
  {
    v5 = AllocTempVector();
    v5->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
    v5->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
    v5->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
    z = v5->z;
    *(_QWORD *)&vecOBB.x = *(_QWORD *)&v5->x;
    v7 = (float)(vecOBB.x - 2.0) * p_m_vecMoveDir->x;
    vecOBB.z = z;
    this->m_flMoveDistance = (float)((float)(fabs(p_m_vecMoveDir->y * (float)(vecOBB.y - 2.0)) + fabs(v7))
                                   + fabs(p_m_vecMoveDir->z * (float)(z - 2.0)))
                           - this->m_flLip;
  }
  m_flMoveDistance = this->m_flMoveDistance;
  v9 = p_m_vecMoveDir->y * m_flMoveDistance;
  v10 = p_m_vecMoveDir->z * m_flMoveDistance;
  m_flStartPosition = this->m_flStartPosition;
  v12 = this->m_vecOrigin.m_Value.y - (float)(v9 * m_flStartPosition);
  v13 = this->m_vecOrigin.m_Value.z;
  this->m_vecPosition1.x = this->m_vecOrigin.m_Value.x
                         - (float)((float)(this->m_flMoveDistance * p_m_vecMoveDir->x) * m_flStartPosition);
  this->m_vecPosition1.y = v12;
  this->m_vecPosition1.z = v13 - (float)(v10 * m_flStartPosition);
  v14 = this->m_flMoveDistance;
  v15 = (float)(p_m_vecMoveDir->y * v14) + this->m_vecPosition1.y;
  v16 = (float)(p_m_vecMoveDir->z * v14) + this->m_vecPosition1.z;
  this->m_vecPosition2.x = this->m_vecPosition1.x + (float)(v14 * p_m_vecMoveDir->x);
  this->m_vecPosition2.y = v15;
  this->m_vecPosition2.z = v16;
  if ( this->m_vecOrigin.m_Value.x != this->m_vecFinalDest.m_Value.x
    || this->m_vecOrigin.m_Value.y != this->m_vecFinalDest.m_Value.y
    || this->m_vecOrigin.m_Value.z != this->m_vecFinalDest.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A8u);
    }
    this->m_vecFinalDest.m_Value.x = this->m_vecOrigin.m_Value.x;
    this->m_vecFinalDest.m_Value.y = this->m_vecOrigin.m_Value.y;
    this->m_vecFinalDest.m_Value.z = this->m_vecOrigin.m_Value.z;
  }
  Precache = this->Precache;
  this->m_pfnTouch = nullptr;
  Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  if ( this->m_iClassname.pszValue == "func_water_analog"
    || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "func_water_analog") != 0 )
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x20);
  }
  if ( this->m_iClassname.pszValue != "func_water_analog"
    && CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "func_water_analog") == 0
    && (this->m_spawnflags.m_Value & 8) != 0 )
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  }
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013C8D0
// Name: public: void CFuncMoveLinear::MoveTo(class Vector,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::MoveTo(CFuncMoveLinear *this, Vector vPosition, float flSpeed)
{
  const char *pszValue; // eax
  const char *v5; // ecx
  edict_t *m_pPev; // eax
  const char *v7; // eax
  edict_t *v8; // eax
  IPhysicsFluidController *m_pFluidController; // ecx
  EmitSound_t ep; // [esp+Ch] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+54h] [ebp-20h] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( flSpeed != 0.0 )
  {
    pszValue = this->m_soundStart.pszValue;
    if ( pszValue != nullptr )
    {
      if ( this->m_currentSound.pszValue == pszValue )
      {
        v5 = this->m_soundStop.pszValue;
        if ( v5 == nullptr )
          v5 = locale;
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEntity::StopSound(
            iEntIndex: m_pPev - gpGlobals->pEdicts,
            iChannel: 4,
            pSample: v5,
            bIsStoppingSpeakerSound: 0);
        else
          CBaseEntity::StopSound(iEntIndex: 0, iChannel: 4, pSample: v5, bIsStoppingSpeakerSound: 0);
      }
      else
      {
        this->m_currentSound.pszValue = pszValue;
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
        EmitSound_t::EmitSound_t(this: &ep);
        v7 = this->m_soundStart.pszValue;
        ep.m_nChannel = 4;
        ep.m_pSoundName = v7;
        if ( v7 == nullptr )
          ep.m_pSoundName = locale;
        v8 = this->m_Network.m_pPev;
        ep.m_flVolume = 1.0;
        ep.m_SoundLevel = SNDLVL_NORM;
        if ( v8 != nullptr )
          v8 -= (int)gpGlobals->pEdicts;
        CBaseEntity::EmitSound(&filter, iEntIndex: (int)v8, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
    }
    CBaseToggle::LinearMove(this, a2: (int)&savedregs, vecDest: &vPosition, flSpeed);
    m_pFluidController = this->m_pFluidController;
    if ( m_pFluidController != nullptr )
      m_pFluidController->WakeAllSleepingObjects(this: m_pFluidController);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CA20
// Name: public: void CFuncMoveLinear::StopMoveSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::StopMoveSound(CFuncMoveLinear *this)
{
  const char *pszValue; // eax
  const char *v3; // ecx
  edict_t *m_pPev; // eax
  signed int v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  edict_t *v8; // eax
  signed int v9; // eax
  EmitSound_t ep; // [esp+10h] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+58h] [ebp-20h] BYREF

  pszValue = this->m_soundStart.pszValue;
  if ( pszValue != nullptr && this->m_currentSound.pszValue == pszValue )
  {
    v3 = this->m_soundStart.pszValue;
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v5 = m_pPev - gpGlobals->pEdicts;
    else
      v5 = 0;
    CBaseEntity::StopSound(iEntIndex: v5, iChannel: 4, pSample: v3, bIsStoppingSpeakerSound: 0);
  }
  v6 = this->m_soundStop.pszValue;
  if ( v6 != nullptr && this->m_currentSound.pszValue != v6 )
  {
    this->m_currentSound.pszValue = v6;
    CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_nSoundEntryVersion = 1;
    v7 = this->m_soundStop.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_hSoundScriptHandle = -1;
    ep.m_nChannel = 4;
    ep.m_pSoundName = v7;
    if ( v7 == nullptr )
      ep.m_pSoundName = locale;
    v8 = this->m_Network.m_pPev;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( v8 != nullptr )
      v9 = v8 - gpGlobals->pEdicts;
    else
      v9 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v9, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1013CB70
// Name: public: virtual void CFuncMoveLinear::MoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::MoveDone(CFuncMoveLinear *this)
{
  float x; // xmm0_4
  COutputEvent *p_m_OnFullyOpen; // ecx

  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFuncMoveLinear::StopMoveSound,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CBaseToggle::MoveDone(this);
  x = this->m_vecOrigin.m_Value.x;
  if ( this->m_vecPosition2.x == x
    && this->m_vecPosition2.y == this->m_vecOrigin.m_Value.y
    && this->m_vecPosition2.z == this->m_vecOrigin.m_Value.z )
  {
    p_m_OnFullyOpen = &this->m_OnFullyOpen;
LABEL_9:
    COutputEvent::FireOutput(this: p_m_OnFullyOpen, pActivator: this, pCaller: this, fDelay: 0.0);
    return;
  }
  if ( this->m_vecPosition1.x == x
    && this->m_vecPosition1.y == this->m_vecOrigin.m_Value.y
    && this->m_vecPosition1.z == this->m_vecOrigin.m_Value.z )
  {
    p_m_OnFullyOpen = &this->m_OnFullyClosed;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CC50
// Name: public: virtual void CFuncMoveLinear::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::Use(
        CFuncMoveLinear *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  float v5; // xmm6_4
  Vector v6; // 0:^24.12

  if ( useType == USE_SET )
  {
    v5 = value;
    if ( value > 1.0 )
      v5 = 1.0;
    v6.y = this->m_vecPosition1.y + (float)((float)(this->m_vecPosition2.y - this->m_vecPosition1.y) * v5);
    v6.z = this->m_vecPosition1.z + (float)((float)(this->m_vecPosition2.z - this->m_vecPosition1.z) * v5);
    v6.x = this->m_vecPosition1.x + (float)((float)(this->m_vecPosition2.x - this->m_vecPosition1.x) * v5);
    CFuncMoveLinear::MoveTo(
      this,
      vPosition: v6,
      flSpeed: fsqrt(
        (float)((float)((float)(v6.y - this->m_vecOrigin.m_Value.y) * (float)(v6.y - this->m_vecOrigin.m_Value.y))
              + (float)((float)(v6.z - this->m_vecOrigin.m_Value.z) * (float)(v6.z - this->m_vecOrigin.m_Value.z)))
      + (float)((float)(v6.x - this->m_vecOrigin.m_Value.x) * (float)(v6.x - this->m_vecOrigin.m_Value.x)))
    * 10.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CD60
// Name: public: void CFuncMoveLinear::InputOpen(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::InputOpen(CFuncMoveLinear *this, inputdata_t *inputdata)
{
  if ( this->m_vecPosition2.x != this->m_vecOrigin.m_Value.x
    || this->m_vecPosition2.y != this->m_vecOrigin.m_Value.y
    || this->m_vecPosition2.z != this->m_vecOrigin.m_Value.z )
  {
    CFuncMoveLinear::MoveTo(this, vPosition: this->m_vecPosition2, flSpeed: this->m_flSpeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CDD0
// Name: public: void CFuncMoveLinear::InputClose(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::InputClose(CFuncMoveLinear *this, inputdata_t *inputdata)
{
  if ( this->m_vecPosition1.x != this->m_vecOrigin.m_Value.x
    || this->m_vecPosition1.y != this->m_vecOrigin.m_Value.y
    || this->m_vecPosition1.z != this->m_vecOrigin.m_Value.z )
  {
    CFuncMoveLinear::MoveTo(this, vPosition: this->m_vecPosition1, flSpeed: this->m_flSpeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CE40
// Name: public: void CFuncMoveLinear::InputSetPosition(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncMoveLinear::InputSetPosition(CFuncMoveLinear *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  Vector v3; // [esp-Ch] [ebp-3Ch]
  __int64 v4; // [esp+18h] [ebp-18h]
  float v5; // [esp+20h] [ebp-10h]

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  *((float *)&v4 + 1) = this->m_vecPosition1.y
                      + (float)(flVal * (float)(this->m_vecPosition2.y - this->m_vecPosition1.y));
  v5 = this->m_vecPosition1.z + (float)(flVal * (float)(this->m_vecPosition2.z - this->m_vecPosition1.z));
  *(float *)&v4 = this->m_vecPosition1.x + (float)(flVal * (float)(this->m_vecPosition2.x - this->m_vecPosition1.x));
  if ( fsqrt(
         (float)((float)((float)(*((float *)&v4 + 1) - this->m_vecOrigin.m_Value.y)
                       * (float)(*((float *)&v4 + 1) - this->m_vecOrigin.m_Value.y))
               + (float)((float)(v5 - this->m_vecOrigin.m_Value.z) * (float)(v5 - this->m_vecOrigin.m_Value.z)))
       + (float)((float)(*(float *)&v4 - this->m_vecOrigin.m_Value.x)
               * (float)(*(float *)&v4 - this->m_vecOrigin.m_Value.x))) > 0.001 )
  {
    *(_QWORD *)&v3.x = v4;
    v3.z = this->m_vecPosition1.z + (float)(flVal * (float)(this->m_vecPosition2.z - this->m_vecPosition1.z));
    CFuncMoveLinear::MoveTo(this, vPosition: v3, flSpeed: this->m_flSpeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104040B0
// Name: CFuncMoveLinear_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncMoveLinear_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncMoveLinear>(__formal: nullptr);
  CFuncMoveLinear_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104040E0
// Name: DT_FuncMoveLinear::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMoveLinear::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncMoveLinear::g_SendTable);
  return atexit(func: DT_FuncMoveLinear::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10404100
// Name: DT_FuncMoveLinear::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncMoveLinear::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncMoveLinear::ignored>();
  DT_FuncMoveLinear::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B8C0
// Name: DT_FuncMoveLinear::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncMoveLinear::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncMoveLinear::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1013C830
// Name: class CFuncMoveLinear __near * _CreateEntityTemplate<class CFuncMoveLinear>(class CFuncMoveLinear __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFuncMoveLinear *__cdecl _CreateEntityTemplate<CFuncMoveLinear>(CFuncMoveLinear *newEnt, const char *className)
{
  CBaseToggle *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseToggle *)CBaseEntity::operator new(stAllocateBlock: 0x424u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseToggle::CBaseToggle(this: v2);
    *v3 = &CFuncMoveLinear::`vftable';
    v3[253] = 0;
    v3[256] = -1;
    v3[257] = 0;
    v3[259] = 0;
    v3[262] = -1;
    v3[263] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFuncMoveLinear *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CF80
// Name: struct datamap_t __near * DataMapInit<class CFuncMoveLinear>(class CFuncMoveLinear __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncMoveLinear>()
{
  if ( (_S2_121 & 1) == 0 )
  {
    _S2_121 |= 1u;
    nameHolder_220.m_pszBase = "CFuncMoveLinear";
    nameHolder_220.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_220.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_220.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_220.m_Names.m_Size = 0;
    nameHolder_220.m_Names.m_pElements = nullptr;
    nameHolder_220.m_nLenBase = 15;
    atexit(func: DataMapInit_CFuncMoveLinear__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncMoveLinear::m_DataMap.baseMap = &CBaseToggle::m_DataMap;
  if ( (_S2_121 & 2) == 0 )
  {
    _S2_121 |= 2u;
    *(_QWORD *)&dataDesc_209[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_209[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_209[12].override_count = 0;
    *(_QWORD *)dataDesc_209[12].flatOffset = 0;
    dataDesc_209[13].fieldSize = 1;
    dataDesc_209[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_209[12].flatGroup = 0;
    dataDesc_209[13].fieldType = FIELD_CUSTOM;
    dataDesc_209[13].fieldName = "m_OnFullyClosed";
    dataDesc_209[13].fieldOffset = 1036;
    dataDesc_209[13].flags = 22;
    dataDesc_209[13].externalName = "OnFullyClosed";
    dataDesc_209[13].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_209[13].inputFunc = 0;
    *(_QWORD *)&dataDesc_209[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_209[13].override_count = 0;
    *(_QWORD *)dataDesc_209[13].flatOffset = 0;
    *(_DWORD *)&dataDesc_209[13].flatGroup = 0;
    dataDesc_209[14].fieldType = FIELD_VOID;
    dataDesc_209[14].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_220,
                                   pszIdentifier: "StopMoveSound");
    dataDesc_209[14].fieldOffset = 0;
    *(_DWORD *)&dataDesc_209[14].fieldSize = 2097153;
    dataDesc_209[14].externalName = nullptr;
    dataDesc_209[14].pSaveRestoreOps = nullptr;
    dataDesc_209[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncMoveLinear::StopMoveSound;
    *(_QWORD *)&dataDesc_209[14].td = 0;
    *(_QWORD *)&dataDesc_209[14].override_field = 0;
    *(_QWORD *)&dataDesc_209[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_209[14].flatOffset[1] = 0;
  }
  CFuncMoveLinear::m_DataMap.dataNumFields = 14;
  CFuncMoveLinear::m_DataMap.dataDesc = &dataDesc_209[1];
  return &CFuncMoveLinear::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104040C0
// Name: _dynamic_initializer_for__g_CFuncMoveLinear_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFuncMoveLinear_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFuncMoveLinear_ClassReg,
           pNetworkName: "CFuncMoveLinear",
           pTable: &DT_FuncMoveLinear::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B8D0
// Name: _ServerClassInit_DT_FuncMoveLinear::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncMoveLinear::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_67;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B8F0
// Name: _DataMapInit_CFuncMoveLinear__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncMoveLinear__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_220);
}
