// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physobj.cpp
// Functions: 110
// ============================================================

#include "game\server\physobj.h"

//------------------------------------------------------------------------------
// Address: 0x101AE5D0
// Name: public: virtual struct datamap_t __near * CPhysicsSpring::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsSpring::GetDataDescMap(CPhysicsSpring *this)
{
  return &CPhysicsSpring::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101AE5E0
// Name: bool GetSpringAttachments(class CBaseEntity __near *,class CBaseEntity __near * __near * const,class IPhysicsObject __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetSpringAttachments(CBaseEntity *pEntity, CBaseEntity **pAttachOut, IPhysicsObject **pAttachVPhysics)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  IPhysicsObject *v6; // esi
  CBaseEntity *v7; // eax
  int v8; // eax
  IPhysicsObject *v9; // esi

  v3 = __RTDynamicCast(
         inptr: pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CPhysicsSpring `RTTI Type Descriptor',
         isReference: 0);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  if ( v3[213] == 0 )
  {
    v6 = nullptr;
    goto LABEL_6;
  }
  v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v3[213] + 20))(a1: v3[213]);
  v6 = (IPhysicsObject *)v5;
  if ( v5 == 0 )
  {
LABEL_6:
    v7 = nullptr;
    goto LABEL_7;
  }
  v7 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 68))(a1: v5);
LABEL_7:
  *pAttachOut = v7;
  *pAttachVPhysics = v6;
  if ( v4[213] != 0 )
  {
    v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4[213] + 24))(a1: v4[213]);
    v9 = (IPhysicsObject *)v8;
    if ( v8 != 0 )
    {
      pAttachOut[1] = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 68))(a1: v8);
      pAttachVPhysics[1] = v9;
      return 1;
    }
  }
  else
  {
    v9 = nullptr;
  }
  pAttachOut[1] = nullptr;
  pAttachVPhysics[1] = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AE690
// Name: public: virtual int CPhysicsSpring::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsSpring::DrawDebugTextOverlays(CPhysicsSpring *this)
{
  int result; // eax
  int v3; // esi
  int v4; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Constant: %3.2f", this->m_tempConstant);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Length: %3.2f", this->m_tempLength);
    CBaseEntity::EntityText(this, text_offset: v4++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Damping: %3.2f", this->m_tempDamping);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AE7D0
// Name: public: virtual void CPhysicsSpring::NotifySystemEvent(class CBaseEntity __near *,enum notify_system_event_t,struct notify_system_event_params_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::NotifySystemEvent(
        CPhysicsSpring *this,
        CBaseEntity *pNotify,
        notify_system_event_t eventType,
        const notify_system_event_params_t *params)
{
  unsigned int tickcount; // eax
  IPhysicsSpring *m_pSpring; // esi
  IPhysicsObject *v6; // eax
  IPhysicsObject *v7; // [esp-14h] [ebp-14h]
  const notify_teleport_params_t *pTeleport; // [esp-10h] [ebp-10h]
  QAngle *p_prevAngles; // [esp-Ch] [ebp-Ch]
  bool physicsRotate; // [esp-8h] [ebp-8h]

  if ( eventType == NOTIFY_EVENT_TELEPORT )
  {
    tickcount = gpGlobals->tickcount;
    if ( tickcount != this->m_teleportTick )
    {
      this->m_teleportTick = tickcount;
      m_pSpring = this->m_pSpring;
      physicsRotate = params->pTeleport->physicsRotate;
      p_prevAngles = &params->pTeleport->prevAngles;
      pTeleport = params->pTeleport;
      v7 = m_pSpring->GetEndObject(this: m_pSpring);
      v6 = m_pSpring->GetStartObject(this: m_pSpring);
      PhysTeleportConstrainedEntity(
        pTeleportSource: pNotify,
        pObject0: v6,
        pObject1: v7,
        prevPosition: &pTeleport->prevOrigin,
        prevAngles: p_prevAngles,
        physicsRotate);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE830
// Name: public: virtual class ServerClass __near * CPhysBox::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPhysBox::GetServerClass(CPhysBox *this)
{
  return &g_CPhysBox_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101AE840
// Name: public: virtual struct datamap_t __near * CPhysBox::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysBox::GetDataDescMap(CPhysBox *this)
{
  return &CPhysBox::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101AE850
// Name: ShouldDampRotation
// Source: json
//------------------------------------------------------------------------------
bool __usercall ShouldDampRotation@<al>(const struct CPhysCollide *pCollide@<edx>, float a2@<ebp>)
{
  float v2; // xmm0_4
  int v3; // eax
  float v4; // xmm2_4
  float v6[3]; // [esp-Ch] [ebp-38h] BYREF
  Vector mins; // [esp+0h] [ebp-2Ch] BYREF
  float v8; // [esp+Ch] [ebp-20h]
  Vector maxs; // [esp+10h] [ebp-1Ch]
  Vector size; // [esp+1Ch] [ebp-10h]
  float retaddr; // [esp+2Ch] [ebp+0h]

  size.y = a2;
  size.z = retaddr;
  physcollision->CollideGetAABB(
    this: physcollision,
    a2: (Vector *)v6,
    a3: (Vector *)&mins.y,
    a4: pCollide,
    a5: &vec3_origin,
    a6: &vec3_angle);
  v2 = mins.y - v6[0];
  v3 = 0;
  maxs.x = mins.y - v6[0];
  maxs.y = mins.z - v6[1];
  maxs.z = v8 - v6[2];
  if ( (float)(mins.z - v6[1]) > (float)(mins.y - v6[0]) )
  {
    v2 = mins.z - v6[1];
    v3 = 1;
  }
  if ( (float)(v8 - v6[2]) > v2 )
  {
    v2 = v8 - v6[2];
    v3 = 2;
  }
  *((_DWORD *)&maxs.x + v3) = 0;
  size.x = maxs.y * maxs.y;
  v4 = fsqrt((float)((float)(maxs.y * maxs.y) + (float)(maxs.z * maxs.z)) + (float)(maxs.x * maxs.x));
  return v4 > 0.0 && (float)(v2 / v4) > 9.0;
}

//------------------------------------------------------------------------------
// Address: 0x101AE940
// Name: public: void CPhysBox::InputBecomeDebris(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputBecomeDebris(CPhysBox *this, inputdata_t *inputdata)
{
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101AE950
// Name: public: virtual struct datamap_t __near * CPhysExplosion::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysExplosion::GetDataDescMap(CPhysExplosion *this)
{
  return &CPhysExplosion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101AE960
// Name: public: virtual struct datamap_t __near * CPhysImpact::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysImpact::GetDataDescMap(CPhysImpact *this)
{
  return &CPhysImpact::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101AE970
// Name: public: virtual struct datamap_t __near * CPhysConvert::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysConvert::GetDataDescMap(CPhysConvert *this)
{
  return &CPhysConvert::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101AE980
// Name: public: virtual struct datamap_t __near * CPhysMagnet::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysMagnet::GetDataDescMap(CPhysMagnet *this)
{
  return &CPhysMagnet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101AE990
// Name: public: virtual class ServerClass __near * CPhysMagnet::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPhysMagnet::GetServerClass(CPhysMagnet *this)
{
  return &g_CPhysMagnet_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101AE9A0
// Name: public: void CPhysMagnet::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMagnet::InputTurnOn(CPhysMagnet *this, inputdata_t *inputdata)
{
  this->m_bActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x101AEA00
// Name: public: void CPhysicsSpring::InputSetSpringConstant(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::InputSetSpringConstant(CPhysicsSpring *this, inputdata_t *inputdata)
{
  const char *v2; // xmm0_4
  const char *pszValue; // xmm1_4

  v2 = nullptr;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  LODWORD(this->m_tempConstant) = pszValue;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    v2 = inputdata->value.iszVal.pszValue;
  ((void (__stdcall *)(const char *))this->m_pSpring->SetSpringConstant)(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101AEA50
// Name: public: void CPhysicsSpring::InputSetSpringDamping(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::InputSetSpringDamping(CPhysicsSpring *this, inputdata_t *inputdata)
{
  const char *v2; // xmm0_4
  const char *pszValue; // xmm1_4

  v2 = nullptr;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  LODWORD(this->m_tempDamping) = pszValue;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    v2 = inputdata->value.iszVal.pszValue;
  ((void (__stdcall *)(const char *))this->m_pSpring->SetSpringDamping)(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101AEAA0
// Name: public: void CPhysicsSpring::InputSetSpringLength(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::InputSetSpringLength(CPhysicsSpring *this, inputdata_t *inputdata)
{
  const char *v2; // xmm0_4
  const char *pszValue; // xmm1_4

  v2 = nullptr;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  LODWORD(this->m_tempLength) = pszValue;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    v2 = inputdata->value.iszVal.pszValue;
  ((void (__stdcall *)(const char *))this->m_pSpring->SetSpringLength)(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101AEAF0
// Name: public: virtual void CPhysicsSpring::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::DrawDebugGeometryOverlays(CPhysicsSpring *this)
{
  float m_tempLength; // xmm3_4
  Vector vLength; // [esp+10h] [ebp-30h] BYREF
  Vector vEndPos; // [esp+1Ch] [ebp-24h] BYREF
  Vector vSpringDir; // [esp+28h] [ebp-18h] BYREF
  Vector vStartPos; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_pSpring != nullptr )
  {
    if ( (this->m_debugOverlays & 4) != 0 )
    {
      this->m_pSpring->GetEndpoints(this: this->m_pSpring, a2: &vStartPos, a3: &vEndPos);
      vSpringDir.x = vEndPos.x - vStartPos.x;
      vSpringDir.y = vEndPos.y - vStartPos.y;
      vSpringDir.z = vEndPos.z - vStartPos.z;
      VectorNormalize(vec: &vSpringDir);
      m_tempLength = this->m_tempLength;
      vLength.x = (float)(vSpringDir.x * m_tempLength) + vStartPos.x;
      vLength.y = (float)(m_tempLength * vSpringDir.y) + vStartPos.y;
      vLength.z = (float)(vSpringDir.z * m_tempLength) + vStartPos.z;
      NDebugOverlay::Line(origin: &vStartPos, target: &vLength, r: 0, g: 0, b: 255, noDepthTest: 0, duration: 0.0);
      NDebugOverlay::Line(origin: &vLength, target: &vEndPos, r: 255, g: 0, b: 0, noDepthTest: 0, duration: 0.0);
    }
    CBaseEntity::DrawDebugGeometryOverlays(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AEC00
// Name: bool PointIsNearer(class IPhysicsObject __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PointIsNearer(IPhysicsObject *pObject1, const Vector *point1, const Vector *point2)
{
  Vector center; // [esp+0h] [ebp-Ch] BYREF

  pObject1->GetPosition(this: pObject1, a2: &center, a3: nullptr);
  return (float)((float)((float)((float)(center.x - point2->x) * (float)(center.x - point2->x))
                       + (float)((float)(center.y - point2->y) * (float)(center.y - point2->y)))
               + (float)((float)(center.z - point2->z) * (float)(center.z - point2->z))) > (float)((float)((float)((float)(center.x - point1->x) * (float)(center.x - point1->x)) + (float)((float)(center.y - point1->y) * (float)(center.y - point1->y)))
                                                                                                 + (float)((float)(center.z - point1->z) * (float)(center.z - point1->z)));
}

//------------------------------------------------------------------------------
// Address: 0x101AEC90
// Name: public: void CPhysicsSpring::GetSpringObjectConnections(struct string_t,struct string_t,class IPhysicsObject __near * __near *,class IPhysicsObject __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::GetSpringObjectConnections(
        CPhysicsSpring *this,
        string_t nameStart,
        string_t nameEnd,
        IPhysicsObject **pStart,
        IPhysicsObject **pEnd)
{
  const char *pszValue; // eax
  IPhysicsObject *PhysicsObjectByName; // esi
  const char *v8; // eax
  IPhysicsObject *v9; // eax
  IPhysicsObject *v10; // edi
  CBaseEntity *v11; // eax
  CBaseEntity *v12; // eax

  pszValue = nameStart.pszValue;
  if ( nameStart.pszValue == nullptr )
    pszValue = locale;
  PhysicsObjectByName = FindPhysicsObjectByName(pName: pszValue, pErrorEntity: this);
  v8 = nameEnd.pszValue;
  if ( nameEnd.pszValue == nullptr )
    v8 = locale;
  v9 = FindPhysicsObjectByName(pName: v8, pErrorEntity: this);
  v10 = v9;
  if ( PhysicsObjectByName != nullptr )
  {
    if ( v9 != nullptr )
    {
      v11 = (CBaseEntity *)PhysicsObjectByName->GetGameData(this: PhysicsObjectByName);
      if ( v11 != nullptr )
        g_pNotify->AddEntity(this: g_pNotify, a2: this, a3: v11);
      v12 = (CBaseEntity *)v10->GetGameData(this: v10);
      if ( v12 != nullptr )
        g_pNotify->AddEntity(this: g_pNotify, a2: this, a3: v12);
      *pStart = PhysicsObjectByName;
      *pEnd = v10;
    }
    else
    {
      *pStart = g_PhysWorldObject;
      *pEnd = PhysicsObjectByName;
    }
  }
  else
  {
    *pStart = g_PhysWorldObject;
    *pEnd = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AED60
// Name: public: virtual void CPhysicsSpring::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysicsSpring::Spawn(CPhysicsSpring *this@<ecx>, int a2@<ebp>)
{
  float v3; // xmm0_4
  _DWORD v4[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v4[0] = a2;
  v4[1] = retaddr;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)v4);
  this->m_start.x = this->m_vecAbsOrigin.x;
  this->m_start.y = this->m_vecAbsOrigin.y;
  this->m_start.z = this->m_vecAbsOrigin.z;
  if ( this->m_tempLength <= 0.0 )
  {
    v3 = this->m_end.x - this->m_start.x;
    this->m_tempLength = fsqrt(
                           (float)((float)((float)(this->m_end.y - this->m_start.y)
                                         * (float)(this->m_end.y - this->m_start.y))
                                 + (float)((float)(this->m_end.z - this->m_start.z)
                                         * (float)(this->m_end.z - this->m_start.z)))
                         + (float)(v3 * v3));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AEE40
// Name: public: virtual int CPhysBox::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysBox::DrawDebugTextOverlays(CPhysBox *this)
{
  int result; // eax
  int v3; // ebx
  IPhysicsObject *m_pPhysicsObject; // esi
  const char *MassEquivalent; // eax
  double v6; // st7
  double v7; // st7
  double v8; // [esp+8h] [ebp-218h]
  float flMass; // [esp+10h] [ebp-210h]
  const char *flMassa; // [esp+10h] [ebp-210h]
  char tempstr[512]; // [esp+20h] [ebp-200h] BYREF

  result = CBreakable::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 && this->m_pPhysicsObject != nullptr )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    flMass = m_pPhysicsObject->GetMass(this: m_pPhysicsObject);
    MassEquivalent = GetMassEquivalent(flMass);
    v6 = ((double (__thiscall *)(IPhysicsObject *, const char *))m_pPhysicsObject->GetMass)(
           a1: m_pPhysicsObject,
           a2: MassEquivalent);
    v7 = ((double (__thiscall *)(IPhysicsObject *, _DWORD, _DWORD))m_pPhysicsObject->GetMass)(
           a1: m_pPhysicsObject,
           a2: COERCE_UNSIGNED_INT64(v6 * 2.2),
           a3: HIDWORD(COERCE_UNSIGNED_INT64(v6 * 2.2)));
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Mass: %.2f kg / %.2f lb (%s)", v7, v8, flMassa);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEF00
// Name: public: void CPhysBox::InputWake(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputWake(CPhysBox *this, inputdata_t *inputdata)
{
  this->m_pPhysicsObject->Wake(this: this->m_pPhysicsObject);
}

//------------------------------------------------------------------------------
// Address: 0x101AEF10
// Name: public: void CPhysBox::InputSleep(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputSleep(CPhysBox *this, inputdata_t *inputdata)
{
  this->m_pPhysicsObject->Sleep(this: this->m_pPhysicsObject);
}

//------------------------------------------------------------------------------
// Address: 0x101AEF20
// Name: public: void CPhysBox::EnableMotion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::EnableMotion(CPhysBox *this)
{
  IPhysicsObject *m_pPhysicsObject; // edi

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: true);
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
  }
  this->m_damageToEnableMotion = 0;
  this->m_flForceToEnableMotion = 0.0;
  COutputEvent::FireOutput(this: &this->m_OnMotionEnabled, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101AEF70
// Name: public: void CPhysBox::InputDisableMotion(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputDisableMotion(CPhysBox *this, inputdata_t *inputdata)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101AEF90
// Name: public: void CPhysBox::InputDisableFloating(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputDisableFloating(CPhysBox *this, inputdata_t *inputdata)
{
  PhysEnableFloating(pObject: this->m_pPhysicsObject, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x101AEFB0
// Name: public: virtual void CPhysExplosion::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysExplosion::Spawn(CPhysExplosion *this)
{
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101AEFE0
// Name: public: class CBaseEntity __near * CPhysExplosion::FindEntity(class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CPhysExplosion::FindEntity(
        CPhysExplosion *this,
        CBaseEntity *pEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  const char *pszValue; // eax
  CBasePlayer *result; // eax
  float flRadius; // xmm0_4
  const char *v9; // eax
  float m_radius; // xmm0_4
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  CBaseEntity *pEntitya; // [esp+14h] [ebp+8h]
  CBaseEntity *pCallera; // [esp+1Ch] [ebp+10h]

  pszValue = this->m_targetEntityName.pszValue;
  if ( pszValue != nullptr )
  {
    result = CGlobalEntityList::FindEntityByName(
               this: &gEntList,
               pStartEntity: pEntity,
               szName: pszValue,
               pSearchingEntity: nullptr,
               pActivator,
               pCaller,
               pFilter: nullptr);
    if ( result == nullptr )
    {
      flRadius = this->m_radius;
      *(float *)&pEntitya = flRadius;
      if ( flRadius <= 0.0 )
      {
        flRadius = this->m_damage * 2.5;
        *(float *)&pEntitya = flRadius;
      }
      if ( (this->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        flRadius = *(float *)&pEntitya;
      }
      v9 = this->m_targetEntityName.pszValue;
      if ( v9 == nullptr )
        v9 = locale;
      return (CBasePlayer *)CGlobalEntityList::FindEntityByClassnameWithin(
                              this: &gEntList,
                              pStartEntity: pEntity,
                              szName: v9,
                              vecSrc: &this->m_vecAbsOrigin,
                              flRadius);
    }
  }
  else
  {
    m_radius = this->m_radius;
    *(float *)&pCallera = m_radius;
    if ( m_radius <= 0.0 )
    {
      m_radius = this->m_damage * 2.5;
      *(float *)&pCallera = m_radius;
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      m_radius = *(float *)&pCallera;
    }
    return (CBasePlayer *)CGlobalEntityList::FindEntityInSphere(
                            this: &gEntList,
                            pStartEntity: pEntity,
                            vecCenter: &this->m_vecAbsOrigin,
                            flRadius: m_radius);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF0F0
// Name: public: virtual int CPhysExplosion::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysExplosion::DrawDebugTextOverlays(CPhysExplosion *this)
{
  int result; // eax
  int v3; // esi
  const char *pszValue; // eax
  int v5; // esi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    magnitude: %f", this->m_damage);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    pszValue = this->m_targetEntityName.pszValue;
    v5 = v3 + 1;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    limit to: %s", pszValue);
    CBaseEntity::EntityText(this, text_offset: v5, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v5 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF1D0
// Name: public: virtual void CPhysImpact::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysImpact::Spawn(CPhysImpact *this)
{
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
  if ( this->m_distance == 0.0 )
    this->m_distance = 256.0;
}

//------------------------------------------------------------------------------
// Address: 0x101AF230
// Name: private: void CPhysImpact::PointAtEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysImpact::PointAtEntity(CPhysImpact *this)
{
  if ( this->m_directionEntityName.pszValue != nullptr )
    UTIL_PointAtNamedEntity(pDest: this, strTarget: this->m_directionEntityName);
}

//------------------------------------------------------------------------------
// Address: 0x101AF250
// Name: bool TransferPhysicsObject(class CBaseEntity __near *,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TransferPhysicsObject(CBaseEntity *pFrom, CBaseEntity *pTo, bool wakeUp)
{
  IPhysicsObject *m_pPhysicsObject; // esi

  m_pPhysicsObject = pFrom->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr || m_pPhysicsObject->IsStatic(this: pFrom->m_pPhysicsObject) )
    return 0;
  CBaseEntity::VPhysicsSwapObject(this: pFrom, pSwap: nullptr);
  m_pPhysicsObject->RemoveShadowController(this: m_pPhysicsObject);
  CBaseEntity::VPhysicsSetObject(this: pTo, pPhysics: m_pPhysicsObject);
  m_pPhysicsObject->SetGameData(this: m_pPhysicsObject, a2: pTo);
  pTo->VPhysicsUpdate(this: pTo, a2: m_pPhysicsObject);
  m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: true);
  m_pPhysicsObject->EnableGravity(this: m_pPhysicsObject, a2: true);
  m_pPhysicsObject->RecheckCollisionFilter(this: m_pPhysicsObject);
  if ( wakeUp )
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AF2E0
// Name: CreateSimplePhysicsObject
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall CreateSimplePhysicsObject@<eax>(
        CBaseEntity *pEntity@<esi>,
        bool createAsleep,
        bool createAsDebris)
{
  bool v3; // bl
  int v4; // eax
  const struct model_t *v5; // eax
  IServerNetworkable *EntityByName; // eax
  CBaseEntity *v7; // edi
  const char *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v3 = createAsleep;
  v4 = pEntity->GetModelIndex(this: pEntity);
  v5 = modelinfo->GetModel(this: modelinfo, a2: v4);
  if ( v5 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v5) == 1 )
    EntityByName = CreateEntityByName(className: "simple_physics_brush", iForceEdictIndex: -1, bNotify: true);
  else
    EntityByName = CreateEntityByName(className: "simple_physics_prop", iForceEdictIndex: -1, bNotify: true);
  v7 = (CBaseEntity *)EntityByName;
  v8 = *(const char **)((int (__thiscall *)(CBaseEntity *, bool *))pEntity->GetModelName)(
                         a1: pEntity,
                         a2: &createAsleep);
  if ( v8 == nullptr )
    v8 = locale;
  v7->KeyValue_4(this: v7, a2: "model", a3: v8);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  CBaseEntity::SetAbsOrigin(this: v7, absOrigin: &pEntity->m_vecAbsOrigin);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  CBaseEntity::SetAbsAngles(this: v7, absAngles: &pEntity->m_angAbsRotation);
  v7->Spawn(this: v7);
  if ( TransferPhysicsObject(pFrom: pEntity, pTo: v7, wakeUp: !v3) == 0 )
  {
    CBaseEntity::VPhysicsInitNormal(
      this: v7,
      solidType: SOLID_VPHYSICS,
      nSolidFlags: 0,
      createAsleep: v3,
      pSolid: nullptr);
    if ( createAsDebris )
      CBaseEntity::SetCollisionGroup(this: v7, collisionGroup: 1);
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101AF470
// Name: public: virtual void CPhysMagnet::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysMagnet::Precache(CRagdollProp *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  v3 = *(const char **)((int (__thiscall *)(CRagdollProp *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  CBaseAnimating::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x101AF5B0
// Name: public: virtual int CSimplePhysicsProp::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimplePhysicsProp::ObjectCaps(CSimplePhysicsProp *this)
{
  int v1; // esi
  vgui::ToggleButton *v2; // ecx

  v1 = CBaseEntity::ObjectCaps(this) | 0x40000000;
  if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v2) )
    return v1 | 1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101AF600
// Name: public: virtual void CInfoMassCenter::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoMassCenter::Spawn(CInfoMassCenter *this)
{
  const char *pszValue; // ecx
  masscenteroverride_t params; // [esp+4h] [ebp-20h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->m_target.pszValue != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    pszValue = this->m_target.pszValue;
    params.center = this->m_vecAbsOrigin;
    params.entityName.pszValue = pszValue;
    memset((void *)&params.axis, 0, 16);
    PhysSetMassCenterOverride(override: &params);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF690
// Name: public: virtual void CPhysicsSpring::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSpring::Activate(CPhysicsSpring *this)
{
  Vector *p_m_start; // ebx
  Vector *p_m_end; // edi
  __int64 v4; // xmm0_8
  float z; // ecx
  double y; // st7
  double v7; // st7
  char m_Value; // al
  float x; // xmm0_4
  const char *pszValue; // eax
  const char *v11; // ecx
  const char *DebugName; // eax
  const char *v13; // [esp-8h] [ebp-4Ch]
  const char *v14; // [esp-4h] [ebp-48h]
  springparams_t spring; // [esp+4h] [ebp-40h] BYREF
  Vector tmpVec; // [esp+30h] [ebp-14h]
  IPhysicsObject *pStart; // [esp+3Ch] [ebp-8h] BYREF
  IPhysicsObject *pEnd; // [esp+40h] [ebp-4h] BYREF

  CBaseEntity::Activate(this);
  if ( this->m_pSpring == nullptr )
  {
    CPhysicsSpring::GetSpringObjectConnections(
      this,
      nameStart: this->m_nameAttachStart,
      nameEnd: this->m_nameAttachEnd,
      &pStart,
      &pEnd);
    if ( pStart != nullptr && pEnd != nullptr && pStart != pEnd )
    {
      p_m_start = &this->m_start;
      p_m_end = &this->m_end;
      if ( !PointIsNearer(pObject1: pEnd, point1: &this->m_end, point2: &this->m_start) )
      {
        v4 = *(_QWORD *)&p_m_start->x;
        z = this->m_start.z;
        p_m_start->x = p_m_end->x;
        y = this->m_end.y;
        *(_QWORD *)&tmpVec.x = v4;
        this->m_start.y = y;
        v7 = this->m_end.z;
        tmpVec.z = z;
        this->m_start.z = v7;
        LODWORD(p_m_end->x) = v4;
        this->m_end.y = tmpVec.y;
        this->m_end.z = tmpVec.z;
      }
      memset(dst: (int)&spring, value: nullptr, count: sizeof(spring));
      m_Value = this->m_spawnflags.m_Value;
      spring.constant = this->m_tempConstant;
      spring.damping = this->m_tempDamping;
      spring.naturalLength = this->m_tempLength;
      spring.relativeDamping = this->m_tempRelativeDamping;
      spring.startPosition.x = p_m_start->x;
      spring.startPosition.y = this->m_start.y;
      spring.startPosition.z = this->m_start.z;
      x = p_m_end->x;
      spring.onlyStretch = m_Value & 1;
      spring.endPosition.x = x;
      spring.endPosition.y = this->m_end.y;
      spring.endPosition.z = this->m_end.z;
      spring.useLocalPositions = false;
      this->m_pSpring = physenv->CreateSpring(this: physenv, a2: pStart, a3: pEnd, a4: &spring);
    }
    else
    {
      pszValue = this->m_nameAttachEnd.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v11 = this->m_nameAttachStart.pszValue;
      if ( v11 == nullptr )
        v11 = locale;
      v14 = pszValue;
      v13 = v11;
      DebugName = CBaseEntity::GetDebugName(this);
      DevMsg(a1: "ERROR: Can't init spring %s from \"%s\" to \"%s\"\n", DebugName, v13, v14);
      UTIL_Remove(oldObj: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF8C0
// Name: public: virtual bool CPhysBox::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CPhysBox::CreateVPhysics@<al>(CPhysBox *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  float m_massScale; // xmm0_4
  IVModelInfo_vtbl *v5; // edi
  int v6; // eax
  vcollide_t *v7; // edi
  int v8; // ebx
  SolidType_t v9; // eax
  IPhysicsObject *inited; // eax
  IPhysicsObject *v11; // edi
  unsigned __int16 v12; // ax
  solid_t tmpSolid; // [esp+8h] [ebp-640h] BYREF
  int savedregs; // [esp+648h] [ebp+0h] BYREF

  v3 = this->GetModelIndex(this);
  PhysModelParseSolid(a1: a2, solid: &tmpSolid, pEntity: this, modelIndex: v3);
  m_massScale = this->m_massScale;
  if ( m_massScale > 0.0 )
    tmpSolid.params.mass = m_massScale * tmpSolid.params.mass;
  v5 = modelinfo->__vftable;
  v6 = this->GetModelIndex(this);
  v7 = v5->GetVCollide(this: modelinfo, a2: v6);
  PhysGetMassCenterOverride(a1: COERCE_FLOAT(&savedregs), pEntity: this, pCollide: v7, solidOut: &tmpSolid);
  PhysSolidOverride(solid: &tmpSolid, overrideScript: (char *)this->m_iszOverrideScript.pszValue);
  if ( tmpSolid.params.rotdamping < 1.0 && ShouldDampRotation(pCollide: *v7->solids, a2: COERCE_FLOAT(&savedregs)) )
    tmpSolid.params.rotdamping = 1.0;
  v8 = this->m_Collision.GetSolidFlags(this: &this->m_Collision);
  v9 = this->m_Collision.GetSolid(this: &this->m_Collision);
  inited = CBaseEntity::VPhysicsInitNormal(this, solidType: v9, nSolidFlags: v8, createAsleep: true, pSolid: &tmpSolid);
  v11 = inited;
  if ( this->m_damageType == 1 )
  {
    v12 = inited->GetGameFlags(this: inited);
    v11->SetGameFlags(this: v11, a2: v12 | 1);
  }
  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
    v11->Wake(this: v11);
  if ( (this->m_spawnflags.m_Value & 0x8000) != 0
    || this->m_damageToEnableMotion > 0
    || this->m_flForceToEnableMotion > 0.0 )
  {
    v11->EnableMotion(this: v11, a2: false);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AFA20
// Name: public: virtual int CPhysBox::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysBox::ObjectCaps(CPhysBox *this)
{
  int v2; // esi

  v2 = CBaseEntity::ObjectCaps(this) | 0x40000000;
  if ( (this->m_spawnflags.m_Value & 0x80000) != 0
    || (this->m_spawnflags.m_Value & 0x2000) == 0
    && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)((unsigned int)this->m_spawnflags.m_Value >> 19)) )
  {
    return v2 | 1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101AFA80
// Name: public: virtual void CPhysBox::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::Use(
        CPhysBox *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
  {
    if ( (this->m_spawnflags.m_Value & 0x80000) != 0 )
      COutputEvent::FireOutput(this: &this->m_OnPlayerUse, pActivator: this, pCaller: this, fDelay: 0.0);
    if ( (this->m_spawnflags.m_Value & 0x2000) == 0 )
      ((void (__thiscall *)(CBaseEntity *, CPhysBox *, int))pActivator->__vftable[2].NetworkStateChanged_m_nNextThinkTick)(
        a1: pActivator,
        a2: this,
        a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AFAF0
// Name: public: void CPhysBox::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputDisable(CPhysBox *this, inputdata_t *inputdata)
{
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101AFB20
// Name: public: void CPhysBox::InputEnableMotion(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputEnableMotion(CPhysBox *this, inputdata_t *inputdata)
{
  IPhysicsObject *m_pPhysicsObject; // edi

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: true);
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
  }
  this->m_damageToEnableMotion = 0;
  this->m_flForceToEnableMotion = 0.0;
  COutputEvent::FireOutput(this: &this->m_OnMotionEnabled, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101AFB70
// Name: public: virtual void CPhysBox::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::VPhysicsCollision(CPhysBox *this, int index, gamevcollisionevent_t *pEvent)
{
  BOOL v4; // eax
  IPhysicsObject **v5; // ebx
  void *v6; // eax

  CBreakable::VPhysicsCollision(this, index: *(float *)&index, (int)pEvent);
  v4 = index == 0;
  v5 = &pEvent->pObjects[v4];
  if ( this->m_flForceToEnableMotion != 0.0 )
  {
    v6 = pEvent->pObjects[v4]->GetGameData(this: pEvent->pObjects[v4]);
    if ( (v6 == nullptr
       || (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v6 + 336))(a1: v6) == 0
       || (this->m_spawnflags.m_Value & 0x800000) == 0)
      && ((double (__thiscall *)(IPhysicsObject *))(*v5)->GetMass)(a1: *v5) * pEvent->collisionSpeed >= this->m_flForceToEnableMotion )
    {
      CPhysBox::EnableMotion(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AFC00
// Name: public: virtual int CPhysBox::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysBox::OnTakeDamage(CPhysBox *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // ecx
  float m_flForceToEnableMotion; // xmm1_4
  int m_damageToEnableMotion; // eax
  int v9; // [esp+30h] [ebp-10h]

  if ( (this->m_iEFlags & 1) != 0 )
    return 0;
  v9 = CBreakable::OnTakeDamage(this, info);
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v5 = info->m_hAttacker.m_Index;
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    COutputEvent::FireOutput(this: &this->m_OnDamaged, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
  }
  if ( this->m_iHealth.m_Value > 0 )
  {
    m_flForceToEnableMotion = this->m_flForceToEnableMotion;
    if ( m_flForceToEnableMotion != 0.0
      && fsqrt(
           (float)((float)(info->m_vecDamageForce.y * info->m_vecDamageForce.y)
                 + (float)(info->m_vecDamageForce.x * info->m_vecDamageForce.x))
         + (float)(info->m_vecDamageForce.z * info->m_vecDamageForce.z)) >= m_flForceToEnableMotion
      && this->m_pPhysicsObject != nullptr )
    {
      CPhysBox::EnableMotion(this);
    }
    m_damageToEnableMotion = this->m_damageToEnableMotion;
    if ( m_damageToEnableMotion > 0 && this->m_iHealth.m_Value < m_damageToEnableMotion )
    {
      CPhysBox::EnableMotion(this);
      this->VPhysicsTakeDamage(this, a2: info);
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101AFD60
// Name: public: virtual bool CPhysBox::HasPreferredCarryAnglesForPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysBox::HasPreferredCarryAnglesForPlayer(CPhysBox *this, CBasePlayer *pPlayer)
{
  return *((_WORD *)this - 47) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AFD70
// Name: public: void CPhysImpact::InputImpact(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysImpact::InputImpact(CPhysImpact *this@<ecx>, int a2@<ebx>, int a3@<edi>, inputdata_t *inputdata)
{
  double m_distance; // xmm0_8
  unsigned int v6; // edx
  float v7; // xmm3_4
  float z; // eax
  CBaseEntity *m_pEnt; // edi
  IPhysicsObject *m_pPhysicsObject; // ebx
  unsigned int v11; // ecx
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CPhysImpact *); // eax
  unsigned int m_Index; // ecx
  int m_Value; // eax
  float m_damage; // xmm4_4
  double v16; // st7
  float x; // xmm1_4
  float y; // xmm2_4
  float v19; // xmm3_4
  float m_fValue; // xmm0_4
  void (__thiscall *ApplyForceOffset)(IPhysicsObject *, const Vector *, const Vector *); // edx
  CTakeDamageInfo info; // [esp+1Ch] [ebp-D8h] BYREF
  CGameTrace trace; // [esp+78h] [ebp-7Ch] BYREF
  Vector start; // [esp+CCh] [ebp-28h] BYREF
  Vector end; // [esp+D8h] [ebp-1Ch] BYREF
  Vector dir; // [esp+E4h] [ebp-10h] BYREF
  float damage; // [esp+F0h] [ebp-4h]
  IHandleEntity savedregs; // [esp+F4h] [ebp+0h] BYREF

  if ( this->m_directionEntityName.pszValue != nullptr )
    UTIL_PointAtNamedEntity(pDest: this, strTarget: this->m_directionEntityName);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, forward: &dir);
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
    m_distance = 56755.84086242099;
  else
    m_distance = this->m_distance;
  v6 = (unsigned int)this->m_iEFlags >> 11;
  v7 = m_distance;
  damage = v7;
  if ( (v6 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v7 = damage;
  }
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&start.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  start.z = z;
  end.y = start.y + (float)(dir.y * v7);
  end.x = start.x + (float)(dir.x * v7);
  end.z = z + (float)(dir.z * v7);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &start,
    vecAbsEnd: &end,
    mask: 0x46004003u,
    ignore: this,
    collisionGroup: 0,
    ptr: &trace);
  if ( debug_physimpact.m_pParent != nullptr && debug_physimpact.m_pParent->m_Value.m_nValue != 0 )
  {
    NDebugOverlay::Cross3D(position: &start, size: 24.0, r: 255, g: 255, b: 255, noDepthTest: 0, flDuration: 30.0);
    NDebugOverlay::Line(
      origin: &trace.startpos,
      target: &trace.endpos,
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: 0,
      duration: 30.0);
  }
  if ( trace.fraction != 1.0 )
  {
    if ( trace.startsolid )
    {
      trace.plane.normal.x = -dir.x;
      trace.plane.normal.y = -dir.y;
      trace.plane.normal.z = -dir.z;
    }
    m_pEnt = trace.m_pEnt;
    m_pPhysicsObject = trace.m_pEnt->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      CTakeDamageInfo::CTakeDamageInfo(this: &info);
      v11 = *(_DWORD *)((int (__thiscall *)(CPhysImpact *, int, int))this->GetRefEHandle)(a1: this, a2: a3, a3: a2);
      GetRefEHandle = this->GetRefEHandle;
      info.m_hAttacker.m_Index = v11;
      m_Index = GetRefEHandle(this)->m_Index;
      info.m_flDamage = 0.0;
      info.m_hInflictor.m_Index = m_Index;
      info.m_vecDamageForce = vec3_origin;
      info.m_bitsDamageType = 0;
      CBaseEntity::DispatchTraceAttack(this: m_pEnt, &info, vecDir: &dir, ptr: &trace);
      ApplyMultiDamage();
      m_Value = this->m_spawnflags.m_Value;
      if ( (m_Value & 3) != 0 )
        m_damage = this->m_damage;
      else
        m_damage = (float)(1.0 - trace.fraction) * this->m_damage;
      damage = m_damage;
      if ( (m_Value & 4) != 0 )
      {
        v16 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject);
        damage = v16 * damage;
        m_damage = damage;
      }
      if ( debug_physimpact.m_pParent != nullptr && debug_physimpact.m_pParent->m_Value.m_nValue != 0 )
      {
        end.y = trace.endpos.y + (float)(trace.plane.normal.y * -128.0);
        end.z = trace.endpos.z + (float)(trace.plane.normal.z * -128.0);
        end.x = trace.endpos.x + (float)(trace.plane.normal.x * -128.0);
        NDebugOverlay::Line(origin: &trace.endpos, target: &end, r: 255, g: 0, b: 0, noDepthTest: 0, duration: 30.0);
        m_damage = damage;
      }
      if ( (this->m_spawnflags.m_Value & 8) != 0 )
      {
        v19 = dir.z;
        y = dir.y;
        x = dir.x;
      }
      else
      {
        x = -trace.plane.normal.x;
        y = -trace.plane.normal.y;
        v19 = -trace.plane.normal.z;
        dir.x = -trace.plane.normal.x;
        dir.y = -trace.plane.normal.y;
        dir.z = -trace.plane.normal.z;
      }
      m_fValue = phys_pushscale.m_pParent->m_Value.m_fValue;
      ApplyForceOffset = m_pPhysicsObject->ApplyForceOffset;
      end.x = (float)(x * m_damage) * m_fValue;
      end.y = (float)(y * m_damage) * m_fValue;
      end.z = (float)(v19 * m_damage) * m_fValue;
      ApplyForceOffset(this: m_pPhysicsObject, a2: &end, a3: &trace.endpos);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B0150
// Name: public: void CPhysMagnet::DoMagnetSuck(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMagnet::DoMagnetSuck(CPhysMagnet *this, CBaseEntity *pOther)
{
  int v3; // eax
  int v4; // ecx
  CBaseEntity *v5; // esi
  IPhysicsObject *m_pPhysicsObject; // edi
  const Vector *v7; // eax
  const Vector *v8; // eax
  double v9; // st7
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  const Vector *AbsOrigin; // [esp-10h] [ebp-FCh]
  CBaseEntity *pEntities[20]; // [esp+10h] [ebp-DCh] BYREF
  CGameTrace tr; // [esp+60h] [ebp-8Ch] BYREF
  Vector vecCheckPos; // [esp+B4h] [ebp-38h] BYREF
  Vector vecSuckPoint; // [esp+C0h] [ebp-2Ch] BYREF
  float v16; // [esp+CCh] [ebp-20h]
  int iNumEntities; // [esp+D0h] [ebp-1Ch]
  int i; // [esp+D4h] [ebp-18h]
  CFlaggedEntitiesEnum pEnum; // [esp+D8h] [ebp-14h] BYREF
  IHandleEntity savedregs; // [esp+ECh] [ebp+0h] BYREF

  if ( (this->m_spawnflags.m_Value & 4) != 0 && this->m_bActive && this->m_flNextSuckTime <= gpGlobals->curtime )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    pEnum.m_listMax = 0;
    pEnum.m_flagMask = 0;
    pEnum.m_count = -1027604480;
    VectorTransform(in1: (const float *)&pEnum.m_listMax, in2: &this->m_rgflCoordinateFrame, out: &vecCheckPos.x);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    pEnum.m_listMax = 0;
    pEnum.m_flagMask = 0;
    pEnum.m_count = -1031798784;
    VectorTransform(in1: (const float *)&pEnum.m_listMax, in2: &this->m_rgflCoordinateFrame, out: &vecSuckPoint.x);
    CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &pEnum, pList: pEntities, listMax: 20, flagMask: 0);
    v3 = UTIL_EntitiesInSphere(center: &vecCheckPos, radius: 80.0, &pEnum);
    v4 = 0;
    iNumEntities = v3;
    for ( i = 0; v4 < iNumEntities; i = v4 )
    {
      v5 = pEntities[v4];
      if ( v5 != nullptr && v5 != pOther )
      {
        m_pPhysicsObject = v5->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr
          && v5->m_MoveType.m_Value == 6
          && ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: v5->m_pPhysicsObject) < 5000.0 )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: v5);
          v7 = CBaseEntity::GetAbsOrigin(this);
          UTIL_TraceLine(
            a1: &savedregs,
            a2: (int)v5,
            vecAbsStart: v7,
            vecAbsEnd: AbsOrigin,
            mask: 0x46004003u,
            ignore: this,
            collisionGroup: 0,
            ptr: &tr);
          if ( tr.fraction == 1.0 || tr.m_pEnt == v5 )
          {
            v8 = CBaseEntity::GetAbsOrigin(this: v5);
            *(float *)&pEnum.m_listMax = vecSuckPoint.x - v8->x;
            *(float *)&pEnum.m_flagMask = vecSuckPoint.y - v8->y;
            *(float *)&pEnum.m_count = vecSuckPoint.z - v8->z;
            VectorNormalize(vec: (Vector *)&pEnum.m_listMax);
            v9 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject);
            AddVelocity = m_pPhysicsObject->AddVelocity;
            v16 = v9 * 5.0;
            *(float *)&pEnum.m_listMax = *(float *)&pEnum.m_listMax * v16;
            *(float *)&pEnum.m_flagMask = *(float *)&pEnum.m_flagMask * v16;
            *(float *)&pEnum.m_count = *(float *)&pEnum.m_count * v16;
            AddVelocity(this: m_pPhysicsObject, a2: (const Vector *)&pEnum.m_listMax, a3: nullptr);
          }
        }
      }
      v4 = i + 1;
    }
    this->m_flNextSuckTime = gpGlobals->curtime + 2.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B0550
// Name: public: void CPhysBox::InputForceDrop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputForceDrop(CPhysBox *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax

  m_Index = this->m_hCarryingPlayer.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        ((void (__thiscall *)(IHandleEntity *, _DWORD))v8->m_pEntity->__vftable[146].GetRefEHandle)(
          a1: v8->m_pEntity,
          a2: 0);
      else
        (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1760))(a1: 0, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B05C0
// Name: public: virtual void CPhysBox::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::OnPhysGunPickup(CPhysBox *this, CBasePlayer *pPhysGunUser, PhysGunPickup_t reason)
{
  int v4; // ecx

  if ( reason == PUNTED_BY_CANNON )
    COutputEvent::FireOutput(
      this: (COutputEvent *)&this->m_Collision.m_vecSurroundingMaxs,
      pActivator: pPhysGunUser,
      pCaller: (CPhysBox *)((char *)this - 856),
      fDelay: 0.0);
  v4 = *((_DWORD *)this - 132);
  if ( v4 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4) == 0 )
  {
    if ( (*((_DWORD *)this - 24) & 0x20000) == 0 )
      return;
    CPhysBox::EnableMotion(this: (CPhysBox *)((char *)this - 856));
  }
  COutputEvent::FireOutput(
    this: (COutputEvent *)&this->m_Collision.m_vecSpecifiedSurroundingMaxs,
    pActivator: pPhysGunUser,
    pCaller: (CPhysBox *)((char *)this - 856),
    fDelay: 0.0);
  if ( reason != PUNTED_BY_CANNON )
  {
    if ( reason == PICKED_UP_BY_CANNON )
      COutputEvent::FireOutput(
        this: (COutputEvent *)&this->m_flNonShadowMass,
        pActivator: pPhysGunUser,
        pCaller: (CPhysBox *)((char *)this - 856),
        fDelay: 0.0);
    if ( pPhysGunUser != nullptr )
      LODWORD(this->m_rgflCoordinateFrame.m_flMatVal[1][0]) = pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
    else
      this->m_rgflCoordinateFrame.m_flMatVal[1][0] = NAN;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B0690
// Name: public: virtual void CPhysBox::OnPhysGunDrop(class CBasePlayer __near *,enum PhysGunDrop_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::OnPhysGunDrop(CPhysBox *this, CBasePlayer *pPhysGunUser, PhysGunDrop_t Reason)
{
  CBreakable::OnPhysGunPickup(this, pPhysGunUser, reason: Reason);
  this->m_rgflCoordinateFrame.m_flMatVal[1][0] = NAN;
  COutputEvent::FireOutput(
    this: (COutputEvent *)&this->m_vecBaseVelocity.m_Value.y,
    pActivator: pPhysGunUser,
    pCaller: (CPhysBox *)((char *)this - 856),
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101B06D0
// Name: public: virtual void CPhysMagnet::ConstraintBroken(class IPhysicsConstraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMagnet::ConstraintBroken(CPhysMagnet *this, IPhysicsConstraint *pConstraint)
{
  int v3; // esi
  CTimedEventMgr *m_pEventMgr; // edx
  unsigned int m_nAllocationCount; // eax
  unsigned int v6; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v8; // ecx
  IEventRegisterCallback *iCount; // [esp+10h] [ebp-4h]

  v3 = 0;
  iCount = this->m_Network.m_TimerEvent.m_pCallback;
  if ( (int)iCount > 0 )
  {
    m_pEventMgr = this->m_Network.m_TimerEvent.m_pEventMgr;
    while ( 1 )
    {
      m_nAllocationCount = m_pEventMgr->m_Events.m_heap.m_Memory.m_nAllocationCount;
      if ( m_nAllocationCount != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nAllocationCount].m_SerialNumber == HIWORD(m_nAllocationCount)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nAllocationCount].m_pEntity != nullptr
        && (IPhysicsConstraint *)m_pEventMgr->m_Events.m_heap.m_Memory.m_pMemory == pConstraint )
      {
        break;
      }
      ++v3;
      m_pEventMgr = (CTimedEventMgr *)((char *)m_pEventMgr + 8);
      if ( v3 >= (int)iCount )
        goto LABEL_18;
    }
    v6 = *(&this->m_Network.m_TimerEvent.m_pEventMgr->m_Events.m_heap.m_Memory.m_nAllocationCount + 2 * v3);
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    v8 = m_pEntity[82].__vftable;
    if ( v8 != nullptr )
      this->m_flPrevAnimTime = this->m_flPrevAnimTime
                             - ((double (__thiscall *)(IHandleEntity_vtbl *))*((_DWORD *)v8->dtr_IHandleEntity + 29))(a1: v8);
    if ( (int)this->m_Network.m_TimerEvent.m_pCallback - v3 - 1 > 0 )
      _V_memmove(
        dest: (char *)this->m_Network.m_TimerEvent.m_pEventMgr + 8 * v3,
        src: &this->m_Network.m_TimerEvent.m_pEventMgr->m_Events.m_heap.m_Memory.m_nGrowSize + 2 * v3,
        count: 8 * ((int)this->m_Network.m_TimerEvent.m_pCallback - v3 - 1));
    --this->m_Network.m_TimerEvent.m_pCallback;
  }
LABEL_18:
  COutputEvent::FireOutput(
    this: (COutputEvent *)&this->m_Network.m_PVSInfo,
    pActivator: (CPhysMagnet *)((char *)this - 1164),
    pCaller: (CPhysMagnet *)((char *)this - 1164),
    fDelay: 0.0);
  physenv->DestroyConstraint(this: physenv, a2: pConstraint);
}

//------------------------------------------------------------------------------
// Address: 0x101B0A00
// Name: public: void CPhysExplosion::Explode(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysExplosion::Explode(
        CPhysExplosion *this@<ecx>,
        float a2@<ebp>,
        CPhysExplosion *a3@<edi>,
        int a4@<esi>,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  CBasePlayer *i; // esi
  float *v8; // eax
  int m_Value; // ecx
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float z; // xmm2_4
  __int128 v14; // xmm0
  float m_radius; // xmm0_4
  __int64 v16; // xmm0_8
  Vector *(__thiscall *BodyTarget)(CBaseEntity *, Vector *, const Vector *, bool); // edx
  float m_flInnerRadius; // xmm1_4
  unsigned int v19; // ecx
  float x; // xmm2_4
  float y; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  const Vector *v26; // eax
  float flDamage; // xmm0_4
  float *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  unsigned int v33; // ecx
  float v34; // xmm0_4
  bool (__thiscall *IsPlayer)(CBaseEntity *); // eax
  bool v36; // al
  float m_damage; // xmm3_4
  int v38; // eax
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // edx
  int *v45; // [esp+38h] [ebp-1A4h]
  int v46; // [esp+40h] [ebp-19Ch] BYREF
  CGameTrace tr; // [esp+4Ch] [ebp-190h] BYREF
  CTakeDamageInfo info; // [esp+A4h] [ebp-138h] BYREF
  int v49; // [esp+108h] [ebp-D4h] BYREF
  int v50; // [esp+114h] [ebp-C8h] BYREF
  __int128 v51; // [esp+120h] [ebp-BCh]
  Vector v52; // [esp+138h] [ebp-A4h] BYREF
  QAngle v53; // [esp+144h] [ebp-98h] BYREF
  float v54[3]; // [esp+150h] [ebp-8Ch] BYREF
  Vector vecEndPos; // [esp+15Ch] [ebp-80h] BYREF
  Vector origin; // [esp+168h] [ebp-74h]
  float v57; // [esp+174h] [ebp-68h]
  float v58; // [esp+178h] [ebp-64h]
  float v59; // [esp+17Ch] [ebp-60h]
  Vector vecSpot; // [esp+180h] [ebp-5Ch] BYREF
  Vector vecPushDir; // [esp+18Ch] [ebp-50h] BYREF
  QAngle vecDeltaAngles; // [esp+198h] [ebp-44h] BYREF
  Vector vecDirToTarget; // [esp+1A4h] [ebp-38h] BYREF
  float dist; // [esp+1B0h] [ebp-2Ch]
  Vector vecStartPos; // [esp+1B4h] [ebp-28h] BYREF
  Vector vecOrigin; // [esp+1C0h] [ebp-1Ch]
  float flFalloff; // [esp+1CCh] [ebp-10h]
  Vector vecPush; // [esp+1D0h] [ebp-Ch] BYREF
  float retaddr; // [esp+1DCh] [ebp+0h]

  vecPush.x = a2;
  vecPush.y = retaddr;
  for ( i = CPhysExplosion::FindEntity(this, pEntity: nullptr, pActivator, pCaller);
        i != nullptr;
        i = CPhysExplosion::FindEntity(this, pEntity: i, pActivator, pCaller) )
  {
    if ( i->m_takedamage.m_Value != 0 && (i->m_MoveType.m_Value == 6 || i->m_pPhysicsObject != nullptr) )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecPush);
      vecStartPos = this->m_vecAbsOrigin;
      v8 = (float *)i->BodyTarget(this: i, result: (Vector *)&v50, a3: &vecStartPos, a4: true);
      m_Value = this->m_spawnflags.m_Value;
      v10 = *v8;
      v11 = v8[1];
      v12 = v8[2];
      v57 = *v8;
      v58 = v11;
      v59 = v12;
      if ( (m_Value & 4) != 0 )
      {
        z = v12;
        vecStartPos.z = v12;
      }
      else
      {
        z = vecStartPos.z;
      }
      v14 = 0;
      *(float *)&v14 = fsqrt(
                         (float)((float)((float)(vecStartPos.y - v11) * (float)(vecStartPos.y - v11))
                               + (float)((float)(z - v12) * (float)(z - v12)))
                       + (float)((float)(vecStartPos.x - v10) * (float)(vecStartPos.x - v10)));
      v51 = v14;
      m_radius = this->m_radius;
      if ( m_radius == 0.0 || m_radius >= *(float *)&v51 )
      {
        if ( (m_Value & 8) == 0 )
          goto LABEL_21;
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecPush);
        v16 = *(_QWORD *)&this->m_vecAbsOrigin.x;
        BodyTarget = i->BodyTarget;
        dist = this->m_vecAbsOrigin.z;
        *(_QWORD *)&vecDirToTarget.y = v16;
        ((void (__thiscall *)(CBasePlayer *, float *, float *, _DWORD, CPhysExplosion *, int, int *))BodyTarget)(
          a1: i,
          a2: v54,
          a3: &vecDirToTarget.y,
          a4: 0,
          a5: a3,
          a6: a4,
          a7: v45);
        if ( this->m_flInnerRadius != 0.0 )
        {
          vecDeltaAngles.x = v54[0] - vecDirToTarget.y;
          vecDeltaAngles.y = v54[1] - vecDirToTarget.z;
          vecDeltaAngles.z = v54[2] - dist;
          VectorNormalize(vec: (Vector *)&vecDeltaAngles);
          m_flInnerRadius = this->m_flInnerRadius;
          v19 = (unsigned int)this->m_iEFlags >> 11;
          x = vecDeltaAngles.x * m_flInnerRadius;
          y = vecDeltaAngles.y * m_flInnerRadius;
          v22 = vecDeltaAngles.z * m_flInnerRadius;
          origin.x = vecDeltaAngles.x * m_flInnerRadius;
          origin.y = vecDeltaAngles.y * m_flInnerRadius;
          origin.z = vecDeltaAngles.z * m_flInnerRadius;
          if ( (v19 & 1) != 0 )
          {
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecPush);
            v22 = origin.z;
            y = origin.y;
            x = origin.x;
          }
          v23 = y + this->m_vecAbsOrigin.y;
          v24 = this->m_vecAbsOrigin.x + x;
          v25 = this->m_vecAbsOrigin.z + v22;
          vecDirToTarget.y = v24;
          vecDirToTarget.z = v23;
          dist = v25;
        }
        v45 = &v46;
        a4 = 0;
        a3 = this;
        v26 = (const Vector *)((int (__thiscall *)(CBasePlayer *))i->BodyTarget)(a1: i);
        UTIL_TraceLine(
          a1: (const IHandleEntity *)&vecPush,
          a2: (int)i,
          vecAbsStart: (Vector *)&vecDirToTarget.y,
          vecAbsEnd: v26,
          mask: (unsigned int)&v49,
          ignore: (const IHandleEntity *)&vecDirToTarget.y,
          collisionGroup: 0,
          ptr: (CGameTrace *)0x400B);
        if ( tr.plane.normal.z >= 1.0 || *(CBasePlayer **)&tr.surface.surfaceProps == i )
        {
LABEL_21:
          flDamage = this->m_damage - (float)(*(float *)&v51 * 0.40000001);
          if ( flDamage < 1.0 )
            flDamage = 1.0;
          CTakeDamageInfo::CTakeDamageInfo(
            this: (CTakeDamageInfo *)&tr.m_pEnt,
            pInflictor: this,
            pAttacker: this,
            flDamage,
            bitsDamageType: 64,
            iKillType: 0,
            iObjectsPenetrated: 0);
          v52.x = v57 - vecStartPos.x;
          v52.y = v58 - vecStartPos.y;
          v52.z = v59 - vecStartPos.z;
          CalculateExplosiveDamageForce(
            info: (CTakeDamageInfo *)&tr.m_pEnt,
            vecDir: &v52,
            vecForceOrigin: &vecStartPos,
            flScale: 1.0);
          if ( (this->m_spawnflags.m_Value & 2) != 0 && i->IsPlayer(this: i) )
          {
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecPush);
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecPush);
            v28 = (float *)i->BodyTarget(
                             this: i,
                             result: (Vector *)&info.m_uiBulletID,
                             a3: &this->m_vecAbsOrigin,
                             a4: false);
            vecSpot.x = *v28 - this->m_vecAbsOrigin.x;
            vecSpot.y = v28[1] - this->m_vecAbsOrigin.y;
            vecSpot.z = v28[2] - this->m_vecAbsOrigin.z;
            vecDirToTarget.x = VectorNormalize(vec: &vecSpot);
            v29 = this->m_radius;
            v30 = v29 * 0.75;
            if ( v29 == (float)(v29 * 0.75) )
            {
              if ( (float)(vecDirToTarget.x - v30) < 0.0 )
                v31 = 0.0;
              else
                v31 = 1.0;
            }
            else
            {
              v32 = (float)(vecDirToTarget.x - v29) / (float)(v30 - v29);
              if ( v32 >= 0.0 )
              {
                if ( v32 > 1.0 )
                  v32 = 1.0;
              }
              else
              {
                v32 = 0.0;
              }
              v31 = v32;
            }
            v33 = (unsigned int)this->m_spawnflags.m_Value >> 4;
            vecOrigin.x = v31;
            if ( (v33 & 1) != 0 )
            {
              vecPushDir.x = (float)random->RandomInt(this: random, a2: -30, a3: 30);
              v34 = (float)random->RandomInt(this: random, a2: -30, a3: 30);
              IsPlayer = i->IsPlayer;
              vecPushDir.y = v34;
              vecPushDir.z = 0.0;
              v36 = IsPlayer(this: i);
              v53.x = this->m_angRotation.m_Value.x + vecPushDir.x;
              v53.y = this->m_angRotation.m_Value.y + vecPushDir.y;
              v53.z = this->m_angRotation.m_Value.z + vecPushDir.z;
              CBasePlayer::SnapEyeAngles(this: v36 ? i : nullptr, viewAngles: &v53);
              CBaseEntity::ViewPunch(this: i, angleOffset: (const QAngle *)&vecPushDir);
              v31 = vecOrigin.x;
            }
            m_damage = this->m_damage;
            v38 = i->m_fFlags.m_Value;
            v39 = (float)((float)(vecSpot.x * m_damage) * v31) * 2.0;
            v40 = (float)((float)(vecSpot.y * m_damage) * v31) * 2.0;
            v41 = (float)((float)(vecSpot.z * m_damage) * v31) * 2.0;
            vecOrigin.y = v39;
            vecOrigin.z = v40;
            flFalloff = v41;
            if ( (v38 & 0x1000000) != 0 )
            {
              v39 = v39 + i->m_vecBaseVelocity.m_Value.x;
              v40 = i->m_vecBaseVelocity.m_Value.y + v40;
              v41 = i->m_vecBaseVelocity.m_Value.z + v41;
              vecOrigin.y = v39;
              vecOrigin.z = v40;
              flFalloff = v41;
            }
            if ( v41 > 0.0 && (v38 & 1) != 0 )
            {
              CBaseEntity::SetGroundEntity(this: i, ground: nullptr);
              if ( (i->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&vecPush);
              v42 = i->m_vecAbsOrigin.z;
              *(_QWORD *)&vecEndPos.x = *(_QWORD *)&i->m_vecAbsOrigin.x;
              vecEndPos.z = v42 + 1.0;
              CBaseEntity::SetAbsOrigin(this: i, absOrigin: &vecEndPos);
              v39 = vecOrigin.y;
              v40 = vecOrigin.z;
              v41 = flFalloff;
            }
            if ( v39 != i->m_vecBaseVelocity.m_Value.x
              || v40 != i->m_vecBaseVelocity.m_Value.y
              || v41 != i->m_vecBaseVelocity.m_Value.z )
            {
              i->NetworkStateChanged_m_vecBaseVelocity(this: i, a2: &i->m_vecBaseVelocity);
              i->m_vecBaseVelocity.m_Value.x = vecOrigin.y;
              i->m_vecBaseVelocity.m_Value.y = vecOrigin.z;
              i->m_vecBaseVelocity.m_Value.z = flFalloff;
            }
            CBaseEntity::AddFlag(this: i, flags: 0x1000000);
            COutputEvent::FireOutput(this: &this->m_OnPushedPlayer, pActivator: this, pCaller: this, fDelay: 0.0);
          }
          else if ( (this->m_spawnflags.m_Value & 1) != 0 )
          {
            i->VPhysicsTakeDamage(this: i, a2: (const CTakeDamageInfo *)&tr.m_pEnt);
          }
          else
          {
            CBaseEntity::TakeDamage(this: i, a2: (int)i, inputInfo: (const CTakeDamageInfo *)&tr.m_pEnt);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B1120
// Name: public: virtual void CSimplePhysicsBrush::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysicsBrush::Spawn(CSimplePhysicsBrush *this)
{
  const char *v2; // eax
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = *(const char **)((int (__thiscall *)(CSimplePhysicsBrush *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  p_m_takedamage = &this->m_takedamage;
  if ( p_m_takedamage->m_Value != 1 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
      a1: p_m_takedamage - 554,
      a2: p_m_takedamage);
    p_m_takedamage->m_Value = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B1190
// Name: public: virtual void CSimplePhysicsProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysicsProp::Spawn(CSimplePhysicsProp *this)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  CBaseProp::Spawn(this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  p_m_takedamage = &this->m_takedamage;
  if ( p_m_takedamage->m_Value != 1 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *))(*(_DWORD *)&p_m_takedamage[-554].m_Value + 756))(
      a1: p_m_takedamage - 554,
      a2: p_m_takedamage);
    p_m_takedamage->m_Value = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B11E0
// Name: public: virtual void CPhysMagnet::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysMagnet::Spawn(CPhysMagnet *this@<ecx>, int a2@<edi>)
{
  const char *v3; // eax
  int v4; // eax
  float m_massScale; // xmm0_4
  SolidType_t v6; // eax
  int v7; // [esp-Ch] [ebp-658h]
  solid_t tmpSolid; // [esp+8h] [ebp-644h] BYREF
  _BYTE v9[4]; // [esp+648h] [ebp-4h] BYREF

  this->Precache(this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  v3 = *(const char **)((int (__thiscall *)(CPhysMagnet *, _BYTE *))this->GetModelName)(a1: this, a2: v9);
  if ( v3 == nullptr )
    v3 = locale;
  this->SetModel(this, a2: v3);
  if ( this->m_takedamage.m_Value != 1 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 1;
  }
  v4 = this->GetModelIndex(this);
  PhysModelParseSolid(a1: a2, solid: &tmpSolid, pEntity: this, modelIndex: v4);
  m_massScale = this->m_massScale;
  if ( m_massScale > 0.0 )
    tmpSolid.params.mass = m_massScale * tmpSolid.params.mass;
  PhysSolidOverride(solid: &tmpSolid, overrideScript: (char *)this->m_iszOverrideScript.pszValue);
  v7 = this->m_Collision.GetSolidFlags(this: &this->m_Collision);
  v6 = this->m_Collision.GetSolid(this: &this->m_Collision);
  CBaseEntity::VPhysicsInitNormal(this, solidType: v6, nSolidFlags: v7, createAsleep: true, pSolid: &tmpSolid);
  if ( (this->m_spawnflags.m_Value & 1) == 0 )
    this->m_pPhysicsObject->Wake(this: this->m_pPhysicsObject);
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
    this->m_pPhysicsObject->EnableMotion(this: this->m_pPhysicsObject, a2: false);
  this->m_bActive = true;
  this->m_pConstraintGroup = nullptr;
  this->m_flTotalMass = 0.0;
  this->m_flNextSuckTime = 0.0;
  vgui::ListViewPanel::Paint((vgui::ListViewPanel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101B1340
// Name: public: void CPhysMagnet::DetachAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMagnet::DetachAll(CPhysMagnet *this)
{
  int v2; // esi
  CHandle<CBaseEntity> *p_hEntity; // edx
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // ecx
  int iCount; // [esp+14h] [ebp-4h]

  v2 = 0;
  iCount = this->m_MagnettedEntities.m_Size;
  if ( iCount > 0 )
  {
    do
    {
      p_hEntity = &this->m_MagnettedEntities.m_Memory.m_pMemory[v2].hEntity;
      m_Index = p_hEntity->m_Index;
      if ( p_hEntity->m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v5 = p_hEntity->m_Index;
        if ( p_hEntity->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
        CBaseEntity::SetShadowCastDistance(this: m_pEntity, flDesiredDistance: 0.0, flDelay: 2.0);
      }
      physenv->DestroyConstraint(this: physenv, a2: this->m_MagnettedEntities.m_Memory.m_pMemory[v2++].pConstraint);
    }
    while ( v2 < iCount );
  }
  this->m_MagnettedEntities.m_Size = 0;
  if ( this->m_MagnettedEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MagnettedEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MagnettedEntities.m_Memory.m_pMemory);
      this->m_MagnettedEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_MagnettedEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_MagnettedEntities.m_pElements = this->m_MagnettedEntities.m_Memory.m_pMemory;
  this->m_flTotalMass = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101B1490
// Name: public: CPhysBox::CPhysBox(void)
// Source: json
//------------------------------------------------------------------------------
CPhysBox *__thiscall CPhysBox::CPhysBox(CPhysBox *this)
{
  CBreakable::CBreakable(this);
  this->CBreakable::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysBox_vtbl *)&CPhysBox::`vftable'{for `CBaseEntity'};
  this->CBreakable::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CPhysBox::`vftable'{for `IBreakableWithPropData'};
  this->CBreakable::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPhysBox::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_OnDamaged.m_Value.iVal = 0;
  this->m_OnDamaged.m_Value.eVal.m_Index = -1;
  this->m_OnDamaged.m_Value.fieldType = FIELD_VOID;
  this->m_OnAwakened.m_Value.iVal = 0;
  this->m_OnAwakened.m_Value.eVal.m_Index = -1;
  this->m_OnAwakened.m_Value.fieldType = FIELD_VOID;
  this->m_OnMotionEnabled.m_Value.iVal = 0;
  this->m_OnMotionEnabled.m_Value.eVal.m_Index = -1;
  this->m_OnMotionEnabled.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunPickup.m_Value.iVal = 0;
  this->m_OnPhysGunPickup.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunPickup.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunPunt.m_Value.iVal = 0;
  this->m_OnPhysGunPunt.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunPunt.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunOnlyPickup.m_Value.iVal = 0;
  this->m_OnPhysGunOnlyPickup.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunOnlyPickup.m_Value.fieldType = FIELD_VOID;
  this->m_OnPhysGunDrop.m_Value.iVal = 0;
  this->m_OnPhysGunDrop.m_Value.eVal.m_Index = -1;
  this->m_OnPhysGunDrop.m_Value.fieldType = FIELD_VOID;
  this->m_OnPlayerUse.m_Value.iVal = 0;
  this->m_OnPlayerUse.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerUse.m_Value.fieldType = FIELD_VOID;
  this->m_hCarryingPlayer.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B1560
// Name: public: virtual class QAngle CPhysBox::PreferredCarryAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CPhysBox::PreferredCarryAngles(CPhysBox *this, QAngle *result)
{
  __int64 v2; // xmm0_8
  int m_Value; // ecx

  v2 = *(_QWORD *)&this->m_fDataObjectTypes;
  m_Value = this->m_fFlags.m_Value;
  *(_QWORD *)&result->x = v2;
  LODWORD(result->z) = m_Value;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1580
// Name: public: virtual CPhysBox::~CPhysBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::~CPhysBox(CPhysBox *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPlayerUse);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunDrop);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunOnlyPickup);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunPunt);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPhysGunPickup);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnMotionEnabled);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnAwakened);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDamaged);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnHealthChanged);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnBreak);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B1600
// Name: public: virtual void CPhysBox::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysBox::Spawn(CPhysBox *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  int m_Value; // ebx
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // ebx
  int v7; // ebx
  CPhysBox *v8; // eax
  CBaseEdict *v9; // ecx
  const char *v10; // eax
  bool v11; // zf
  CPhysBox *v13; // [esp+0h] [ebp-4h] BYREF

  v13 = this;
  this->m_flDmgModBullet = func_breakdmg_bullet.m_pParent->m_Value.m_fValue;
  this->m_flDmgModClub = func_breakdmg_club.m_pParent->m_Value.m_fValue;
  this->m_flDmgModExplosive = func_breakdmg_explosive.m_pParent->m_Value.m_fValue;
  this->m_flDmgModFire = 1.0;
  CBreakable::ParsePropData(this);
  ((void (__thiscall *)(CPhysBox *, int, int, int))this->Precache)(a1: this, a2: a3, a3: a4, a4: a2);
  m_Value = this->m_iHealth.m_Value;
  if ( m_Value <= 0 )
    m_Value = 1;
  if ( this->m_iMaxHealth.m_Value != m_Value )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = m_Value;
  }
  p_m_takedamage = &this->m_takedamage;
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    if ( p_m_takedamage->m_Value != 1 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      p_m_takedamage->m_Value = 1;
    }
    v7 = this->m_spawnflags.m_Value | 0x400;
    if ( this->m_spawnflags.m_Value != v7 )
    {
      v8 = this;
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_spawnflags.m_Value = v7;
        goto LABEL_22;
      }
LABEL_17:
      v9 = &v8->m_Network.m_pPev->CBaseEdict;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: (_WORD)this + 760 - (_WORD)v8);
      this->m_spawnflags.m_Value = v7;
    }
  }
  else if ( this->m_iHealth.m_Value != 0 )
  {
    if ( p_m_takedamage->m_Value != 2 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      p_m_takedamage->m_Value = 2;
    }
  }
  else
  {
    if ( p_m_takedamage->m_Value != 1 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      p_m_takedamage->m_Value = 1;
    }
    v7 = this->m_spawnflags.m_Value | 0x400;
    if ( this->m_spawnflags.m_Value != v7 )
    {
      v8 = this;
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_spawnflags.m_Value = v7;
        goto LABEL_22;
      }
      goto LABEL_17;
    }
  }
LABEL_22:
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  v10 = *(const char **)((int (__thiscall *)(CPhysBox *, CPhysBox **))this->GetModelName)(a1: this, a2: &v13);
  if ( v10 == nullptr )
    v10 = locale;
  this->SetModel(this, a2: v10);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  if ( (this->m_spawnflags.m_Value & 0x4000) != 0 )
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  if ( (this->m_spawnflags.m_Value & 0x40000) != 0 )
    this->m_iEFlags |= 0x200000u;
  if ( this->m_bNotSolidToWorld )
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  this->CreateVPhysics(this);
  this->m_hCarryingPlayer.m_Index = -1;
  v11 = (this->m_spawnflags.m_Value & 1) == 0;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBreakable::BreakTouch;
  if ( !v11 )
    this->m_pfnTouch = nullptr;
  if ( this->m_impactEnergyScale == 0.0 )
    this->m_impactEnergyScale = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101B1860
// Name: public: void CPhysBox::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::InputEnable(CPhysBox *this, inputdata_t *inputdata)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
  v3 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B18D0
// Name: public: virtual void CPhysBox::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysBox::VPhysicsUpdate(CPhysBox *this, IPhysicsObject *pPhysics)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  const char *pszValue; // eax
  unsigned int v5; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v6; // eax
  CBaseEdict *m_Value; // ecx

  CBaseEntity::VPhysicsUpdate(this, pPhysics);
  p_m_spawnflags = &this->m_spawnflags;
  if ( (this->m_spawnflags.m_Value & 0x1000) != 0 && !pPhysics->IsAsleep(this: pPhysics) )
  {
    COutputEvent::FireOutput(this: &this->m_OnAwakened, pActivator: this, pCaller: this, fDelay: 0.0);
    pszValue = this->m_target.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    FireTargets(targetName: pszValue, pActivator: this, pCaller: this, useType: USE_TOGGLE, value: 0.0);
    v5 = p_m_spawnflags->m_Value & 0xFFFFEFFF;
    if ( p_m_spawnflags->m_Value != v5 )
    {
      v6 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v6[22].m_Value) |= 1u;
        p_m_spawnflags->m_Value = v5;
      }
      else
      {
        m_Value = (CBaseEdict *)v6[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B1990
// Name: public: void CPhysExplosion::InputExplode(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysExplosion::InputExplode(
        CPhysExplosion *this@<ecx>,
        CPhysExplosion *a2@<edi>,
        int a3@<esi>,
        inputdata_t *inputdata)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CPhysExplosion::Explode(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: a2,
    a4: a3,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller);
}

//------------------------------------------------------------------------------
// Address: 0x101B19B0
// Name: public: void CPhysExplosion::InputExplodeAndRemove(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysExplosion::InputExplodeAndRemove(
        CPhysExplosion *this@<ecx>,
        CPhysExplosion *a2@<edi>,
        inputdata_t *inputdata)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  CPhysExplosion::Explode(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: a2,
    a4: (int)this,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x101B19E0
// Name: public: void CPhysConvert::InputConvertTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysConvert::InputConvertTarget(
        CPhysConvert *this@<ecx>,
        const char *a2@<edi>,
        inputdata_t *inputdata)
{
  CPhysConvert *v3; // ebx
  char m_Value; // al
  CBaseEntity *pActivator; // edx
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  const char *v9; // ecx
  CBaseEntity *v10; // edi
  CBaseEntity *v11; // esi
  const char *v12; // esi
  const char *v13; // eax
  CBaseEntity *SimplePhysicsObject; // eax
  CBaseEntity *v15; // edi
  IPhysicsObject *m_pPhysicsObject; // ecx
  const char *v17; // edx
  CBaseEdict *v18; // ecx
  CBaseEntity *entlist[512]; // [esp+18h] [ebp-81Ch]
  char v21[4]; // [esp+818h] [ebp-1Ch] BYREF
  const char *v22; // [esp+81Ch] [ebp-18h]
  BOOL createAsDebris; // [esp+820h] [ebp-14h]
  CPhysConvert *v24; // [esp+824h] [ebp-10h]
  BOOL createAsleep; // [esp+828h] [ebp-Ch]
  int i; // [esp+82Ch] [ebp-8h]
  CBaseEntity *pSwap; // [esp+830h] [ebp-4h]
  int count; // [esp+83Ch] [ebp+8h]

  v3 = this;
  m_Value = this->m_spawnflags.m_Value;
  pActivator = inputdata->pActivator;
  LOBYTE(createAsDebris) = (this->m_spawnflags.m_Value & 2) != 0;
  v24 = this;
  LOBYTE(createAsleep) = m_Value & 1;
  COutputEvent::FireOutput(this: &v24->m_OnConvert, pActivator, pCaller: v24, fDelay: 0.0);
  pszValue = v3->m_swapModel.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  pSwap = CGlobalEntityList::FindEntityByName(
            this: &gEntList,
            pStartEntity: nullptr,
            szName: pszValue,
            pSearchingEntity: nullptr,
            pActivator: inputdata->pActivator,
            pCaller: inputdata->pCaller,
            pFilter: nullptr);
  EntityByName = nullptr;
  for ( count = 0; (unsigned int)count < 0x200; ++count )
  {
    v9 = v3->m_target.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName: v9,
                     pSearchingEntity: nullptr,
                     pActivator: inputdata->pActivator,
                     pCaller: inputdata->pCaller,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      break;
    entlist[count] = EntityByName;
  }
  v10 = pSwap;
  if ( pSwap != nullptr && count > 0 )
    count = 1;
  for ( i = 0; i < count; ++i )
  {
    v11 = entlist[i];
    if ( v11->m_MoveType.m_Value == 6 )
    {
      v12 = v11->m_iClassname.pszValue;
      if ( v12 == nullptr )
        v12 = locale;
      _Msg(a1: "ERROR phys_convert %s ! Already MOVETYPE_VPHYSICS\n", v12);
    }
    else
    {
      UnlinkFromParent(pRemove: entlist[i]);
      if ( v10 != nullptr )
      {
        ((void (__thiscall *)(CBaseEntity *, const char *))v11->VPhysicsDestroyObject)(a1: v11, a2);
        v13 = *(const char **)((int (__thiscall *)(CBaseEntity *, char *))v10->GetModelName)(a1: v10, a2: v21);
        if ( v13 == nullptr )
          v13 = locale;
        a2 = v13;
        ((void (__thiscall *)(CBaseEntity *))v11->SetModel)(a1: v11);
      }
      SimplePhysicsObject = CreateSimplePhysicsObject(pEntity: v11, createAsleep, createAsDebris);
      v15 = SimplePhysicsObject;
      if ( SimplePhysicsObject != nullptr )
      {
        if ( v3->m_flMassOverride > 0.0 )
        {
          m_pPhysicsObject = SimplePhysicsObject->m_pPhysicsObject;
          if ( m_pPhysicsObject != nullptr )
            ((void (__stdcall *)(_DWORD))m_pPhysicsObject->SetMass)(a1: LODWORD(v3->m_flMassOverride));
        }
        v17 = v11->m_iName.m_Value.pszValue;
        v22 = v17;
        if ( v15->m_iName.m_Value.pszValue != v17 )
        {
          if ( v15->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v15->m_Network + 76) |= 1u;
          }
          else
          {
            v18 = &v15->m_Network.m_pPev->CBaseEdict;
            if ( v18 != nullptr )
            {
              CBaseEdict::StateChanged(this: v18, offset: 0xCCu);
              v17 = v22;
            }
          }
          v15->m_iName.m_Value.pszValue = v17;
        }
        CGlobalEntityList::UpdateName(this: &gEntList, pEnt: v15);
        UTIL_TransferPoseParameters(pSourceEntity: v11, pDestEntity: v15);
        TransferChildren(pOldParent: v11, pNewParent: v15);
        CCollisionProperty::SetSolidFlags(this: &v11->m_Collision, flags: v11->m_Collision.m_usSolidFlags.m_Value | 4);
        CBaseEntity::AddEffects(this: v11, nEffects: 32);
        UTIL_Remove(oldObj: v11);
        v3 = v24;
      }
      v10 = pSwap;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B1C10
// Name: public: CPhysMagnet::CPhysMagnet(void)
// Source: json
//------------------------------------------------------------------------------
CPhysMagnet *__thiscall CPhysMagnet::CPhysMagnet(CPhysMagnet *this)
{
  CBaseAnimating::CBaseAnimating(this);
  this->IPhysicsConstraintEvent::__vftable = (IPhysicsConstraintEvent_vtbl *)&IPhysicsConstraintEvent::`vftable';
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysMagnet_vtbl *)&CPhysMagnet::`vftable'{for `CBaseAnimating'};
  this->IPhysicsConstraintEvent::__vftable = (IPhysicsConstraintEvent_vtbl *)&CPhysMagnet::`vftable'{for `IPhysicsConstraintEvent'};
  this->m_OnMagnetAttach.m_Value.iVal = 0;
  this->m_OnMagnetAttach.m_Value.eVal.m_Index = -1;
  this->m_OnMagnetAttach.m_Value.fieldType = FIELD_VOID;
  this->m_OnMagnetDetach.m_Value.iVal = 0;
  this->m_OnMagnetDetach.m_Value.eVal.m_Index = -1;
  this->m_OnMagnetDetach.m_Value.fieldType = FIELD_VOID;
  this->m_MagnettedEntities.m_Memory.m_pMemory = nullptr;
  this->m_MagnettedEntities.m_Memory.m_nAllocationCount = 0;
  this->m_MagnettedEntities.m_Memory.m_nGrowSize = 0;
  this->m_MagnettedEntities.m_Size = 0;
  this->m_MagnettedEntities.m_pElements = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B1C90
// Name: public: virtual void CPhysMagnet::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMagnet::VPhysicsCollision(CPhysMagnet *this, surfacedata_t *index, CBaseEntity *pEvent)
{
  BOOL v3; // ebx
  CBaseEntity *v5; // edi
  char v6; // cl
  int m_iMaxObjectsAttached; // eax
  const char *pszValue; // esi
  edict_t *v9; // eax
  char material; // al
  CBaseAnimating *v11; // eax
  CStudioHdr *ModelPtr; // eax
  const char *DefaultSurfaceProps; // eax
  IPhysicsObject *m_pPhysicsObject; // ebx
  int m_Size; // eax
  CHandle<CBaseEntity> *p_hEntity; // ecx
  IPhysicsObject *v17; // edi
  const CBaseHandle *v18; // eax
  unsigned int v19; // edx
  IPhysicsCollisionData *v20; // ecx
  float v21; // xmm1_4
  IPhysicsConstraint *v22; // eax
  float v23; // xmm1_4
  IPhysicsConstraint_vtbl *v24; // edx
  double v25; // st7
  constraint_fixedparams_t fixed; // [esp+28h] [ebp-78h] BYREF
  float v27; // [esp+70h] [ebp-30h]
  float v28; // [esp+74h] [ebp-2Ch]
  int v29; // [esp+78h] [ebp-28h]
  int v30; // [esp+7Ch] [ebp-24h]
  char v31; // [esp+80h] [ebp-20h]
  Vector vecCollisionPoint; // [esp+84h] [ebp-1Ch] BYREF
  CBaseEntity *pOther; // [esp+90h] [ebp-10h]
  int i; // [esp+94h] [ebp-Ch] BYREF
  unsigned int m_Index; // [esp+98h] [ebp-8h]
  CHandle<CBaseEntity> *v36; // [esp+9Ch] [ebp-4h]

  v3 = index == nullptr;
  v5 = *((CBaseEntity **)&pEvent->m_flSimulationTime.m_Value + v3);
  v6 = LOBYTE(v5->m_Collision.m_usSolidFlags.m_Value) >> 2;
  pOther = v5;
  if ( (v6 & 1) != 0 )
    return;
  this->m_bHasHitSomething = true;
  CPhysMagnet::DoMagnetSuck(this, pOther: *((CBaseEntity **)&pEvent->m_flSimulationTime.m_Value + v3));
  if ( !this->m_bActive )
    return;
  m_iMaxObjectsAttached = this->m_iMaxObjectsAttached;
  if ( m_iMaxObjectsAttached != 0 && m_iMaxObjectsAttached <= this->m_MagnettedEntities.m_Size )
    return;
  if ( (this->m_spawnflags.m_Value & 0x10) != 0
    && v5->m_iClassname.pszValue != "prop_vehicle_jeep"
    && CBaseEntity::ClassMatchesComplex(this: v5, pszClassOrWildcard: "prop_vehicle_jeep") == 0 )
  {
    if ( v5->m_takedamage.m_Value < 2u )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)&pEvent->__vftable + v3) + 40))(a1: *((_DWORD *)&pEvent->__vftable + v3)) != 0 )
      {
        UTIL_Remove(oldObj: v5);
      }
      else
      {
        pszValue = v5->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        v9 = CBaseEntity::entindex(this: v5);
        _Warning(a1: "CPhysMagnet %s:%d blocking magnet\n", pszValue, v9);
      }
    }
    else
    {
      CTakeDamageInfo::CTakeDamageInfo(
        this: (CTakeDamageInfo *)&fixed,
        pInflictor: this,
        pAttacker: this,
        flDamage: (float)v5->m_iHealth.m_Value,
        bitsDamageType: 2048,
        iKillType: 0,
        iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this: v5, a2: (int)this, inputInfo: (const CTakeDamageInfo *)&fixed);
    }
    return;
  }
  material = physprops->GetSurfaceData(this: physprops, a2: *((_DWORD *)&pEvent->m_pfnThink + v3))->game.material;
  if ( material != 77 && material != 80 )
  {
    if ( v5->GetBaseAnimating(this: v5) == nullptr )
      return;
    v11 = v5->GetBaseAnimating(this: v5);
    ModelPtr = CBaseAnimating::GetModelPtr(this: v11);
    DefaultSurfaceProps = Studio_GetDefaultSurfaceProps(pstudiohdr: ModelPtr);
    if ( V_strncmp(s1: DefaultSurfaceProps, s2: "metal", count: 5) != 0 )
      return;
  }
  m_pPhysicsObject = v5->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr
    || v5->m_MoveType.m_Value != 6
    || !m_pPhysicsObject->IsMoveable(this: v5->m_pPhysicsObject) )
  {
LABEL_31:
    CPhysMagnet::DoMagnetSuck(this, pOther: v5);
    COutputEvent::FireOutput(this: &this->m_OnMagnetAttach, pActivator: this, pCaller: this, fDelay: 0.0);
    CBaseEntity::VPhysicsCollision(this, index, pEvent);
    return;
  }
  m_Size = this->m_MagnettedEntities.m_Size;
  m_Index = 0;
  if ( m_Size <= 0 )
  {
LABEL_27:
    CBaseEntity::SetShadowCastDistance(this: v5, flDistance: 2048.0);
    v17 = this->m_pPhysicsObject;
    v18 = pOther->GetRefEHandle(this: pOther);
    v19 = (unsigned int)this->m_spawnflags.m_Value >> 3;
    m_Index = v18->m_Index;
    if ( (v19 & 1) != 0 )
    {
      v20 = *(IPhysicsCollisionData **)&pEvent->m_Network.m_PVSInfo.m_nHeadNode;
      v27 = this->m_forceLimit * 0.45454544;
      v21 = this->m_torqueLimit * 0.45454544;
      memset(&fixed.attachedRefXform.m_flMatVal[2][3], 0, 24);
      *(_DWORD *)&fixed.constraint.isActive = 1065353216;
      v29 = 1065353216;
      v30 = 1065353216;
      v31 = 1;
      v28 = v21;
      v20->GetContactPoint(this: v20, a2: &vecCollisionPoint);
      v17->WorldToLocal(this: v17, a2: (Vector *)&fixed.attachedRefXform.m_flMatVal[2][3], a3: &vecCollisionPoint);
      m_pPhysicsObject->WorldToLocal(
        this: m_pPhysicsObject,
        a2: (Vector *)&fixed.constraint.torqueLimit,
        a3: &vecCollisionPoint);
      v22 = physenv->CreateBallsocketConstraint(
              this: physenv,
              a2: v17,
              a3: m_pPhysicsObject,
              a4: 0,
              a5: &fixed.attachedRefXform.m_flMatVal[2][3]);
    }
    else
    {
      constraint_fixedparams_t::Defaults(this: (constraint_fixedparams_t *)&fixed.attachedRefXform.m_flMatVal[1][1]);
      constraint_fixedparams_t::InitWithCurrentObjectState(
        this: (constraint_fixedparams_t *)&fixed.attachedRefXform.m_flMatVal[1][1],
        pRef: v17,
        pAttached: m_pPhysicsObject);
      v27 = this->m_forceLimit * 0.45454544;
      v23 = this->m_torqueLimit * 0.45454544;
      *(_DWORD *)&fixed.constraint.isActive = 1065353216;
      v29 = 1065353216;
      v30 = 1065353216;
      v31 = 1;
      v28 = v23;
      v22 = physenv->CreateFixedConstraint(
              this: physenv,
              a2: v17,
              a3: m_pPhysicsObject,
              a4: 0,
              a5: &fixed.attachedRefXform.m_flMatVal[1][1]);
    }
    v24 = v22->__vftable;
    i = (int)v22;
    v24->SetGameData(this: v22, a2: this);
    CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
      this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&this->m_MagnettedEntities,
      elem: this->m_MagnettedEntities.m_Size,
      src: (const AI_NamespaceAddInfo_t *)&i);
    v25 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject);
    v5 = pOther;
    this->m_flTotalMass = v25 + this->m_flTotalMass;
    goto LABEL_31;
  }
  p_hEntity = &this->m_MagnettedEntities.m_Memory.m_pMemory->hEntity;
  v36 = p_hEntity;
  while ( !CHandle<CBaseEntity>::operator==(this: p_hEntity, val: v5) )
  {
    v36 += 2;
    if ( (signed int)++m_Index >= this->m_MagnettedEntities.m_Size )
      goto LABEL_27;
    p_hEntity = v36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B2070
// Name: public: void CPhysMagnet::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMagnet::InputTurnOff(CPhysMagnet *this, inputdata_t *inputdata)
{
  this->m_bActive = false;
  CPhysMagnet::DetachAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B2080
// Name: public: void CPhysMagnet::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMagnet::InputToggle(CPhysMagnet *this, inputdata_t *inputdata)
{
  if ( this->m_bActive )
  {
    this->m_bActive = false;
    CPhysMagnet::DetachAll(this);
  }
  else
  {
    this->m_bActive = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104078F0
// Name: CPhysicsSpring_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsSpring_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsSpring>();
  CPhysicsSpring_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407920
// Name: DT_PhysBox::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBox::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PhysBox::g_SendTable);
  return atexit(func: DT_PhysBox::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10407940
// Name: DT_PhysBox::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBox::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PhysBox::ignored>();
  DT_PhysBox::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407970
// Name: CPhysBox_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysBox_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysBox>();
  CPhysBox_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104079A0
// Name: CPhysExplosion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysExplosion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysExplosion>();
  CPhysExplosion_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104079D0
// Name: CPhysImpact_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysImpact_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysImpact>();
  CPhysImpact_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407A40
// Name: CPhysConvert_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysConvert_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysConvert>();
  CPhysConvert_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407A70
// Name: magnetted_objects_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *magnetted_objects_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<magnetted_objects_t>();
  magnetted_objects_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407A80
// Name: CPhysMagnet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysMagnet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysMagnet>();
  CPhysMagnet_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407AB0
// Name: DT_PhysMagnet::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysMagnet::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PhysMagnet::g_SendTable);
  return atexit(func: DT_PhysMagnet::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10407AD0
// Name: DT_PhysMagnet::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysMagnet::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PhysMagnet::ignored>();
  DT_PhysMagnet::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CF10
// Name: DT_PhysBox::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysBox::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PhysBox::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF20
// Name: DT_PhysMagnet::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysMagnet::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PhysMagnet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x101AF4B0
// Name: class CPhysicsSpring __near * _CreateEntityTemplate<class CPhysicsSpring>(class CPhysicsSpring __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysicsSpring *__cdecl _CreateEntityTemplate<CPhysicsSpring>(CPhysicsSpring *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[1].m_pfnThink = (void (__thiscall *)(CBaseEntity *))1125515264;
    v3[1].m_Network.__vftable = nullptr;
    v3[1].m_Network.__vftable = (IEventRegisterCallback_vtbl *)0x40000000;
    v3->__vftable = (CBaseEntity_vtbl *)&CPhysicsSpring::`vftable';
    v3[1].__vftable = nullptr;
    v3[1].m_Network.m_pOuter = (CBaseEntity *)1008981770;
    LOBYTE(v3[1].m_pfnMoveDone) = 0;
    *(_DWORD *)&v3[1].m_Network.m_PVSInfo.m_pClustersInline[2] = -1;
    v3->PostConstructor(this: v3, a2: className);
    return (CPhysicsSpring *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10407900
// Name: _dynamic_initializer_for__g_CPhysBox_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPhysBox_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPhysBox_ClassReg,
           pNetworkName: "CPhysBox",
           pTable: &DT_PhysBox::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10407980
// Name: _dynamic_initializer_for__env_physexplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_physexplosion__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysExplosion> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_physexplosion,
           a3: "env_physexplosion");
}

//------------------------------------------------------------------------------
// Address: 0x104079B0
// Name: _dynamic_initializer_for__env_physimpact__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_physimpact__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysImpact> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_physimpact,
           a3: "env_physimpact");
}

//------------------------------------------------------------------------------
// Address: 0x10407A90
// Name: _dynamic_initializer_for__g_CPhysMagnet_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPhysMagnet_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPhysMagnet_ClassReg,
           pNetworkName: "CPhysMagnet",
           pTable: &DT_PhysMagnet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF30
// Name: _ServerClassInit_DT_PhysMagnet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PhysMagnet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S10_3;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF50
// Name: _ServerClassInit_DT_PhysBox::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PhysBox::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_94;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF70
// Name: _DataMapInit_CPhysicsSpring__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsSpring__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_316);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF80
// Name: _DataMapInit_CPhysBox__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysBox__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_317);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF90
// Name: _DataMapInit_CPhysExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_318);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFA0
// Name: _DataMapInit_CPhysImpact__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysImpact__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_319);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFB0
// Name: _DataMapInit_CPhysConvert__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysConvert__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_320);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFC0
// Name: _DataMapInit_magnetted_objects_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_magnetted_objects_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_321);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFD0
// Name: _DataMapInit_CPhysMagnet__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysMagnet__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_322);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFE0
// Name: _dynamic_atexit_destructor_for__autoaim_max_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autoaim_max_dist__()
{
  ConVar::~ConVar(this: &autoaim_max_dist);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFF0
// Name: _dynamic_atexit_destructor_for__autoaim_max_deflect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autoaim_max_deflect__()
{
  ConVar::~ConVar(this: &autoaim_max_deflect);
}

//------------------------------------------------------------------------------
// Address: 0x1041D000
// Name: _dynamic_atexit_destructor_for__spec_freeze_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_freeze_time__()
{
  ConVar::~ConVar(this: &spec_freeze_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041D010
// Name: _dynamic_atexit_destructor_for__spec_freeze_traveltime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_freeze_traveltime__()
{
  ConVar::~ConVar(this: &spec_freeze_traveltime);
}

//------------------------------------------------------------------------------
// Address: 0x1041D020
// Name: _dynamic_atexit_destructor_for__sv_bonus_challenge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_bonus_challenge__()
{
  ConVar::~ConVar(this: &sv_bonus_challenge);
}

//------------------------------------------------------------------------------
// Address: 0x1041D030
// Name: _dynamic_atexit_destructor_for__sv_regeneration_wait_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_regeneration_wait_time__()
{
  ConVar::~ConVar(this: &sv_regeneration_wait_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041D040
// Name: _dynamic_atexit_destructor_for__old_armor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__old_armor__()
{
  ConVar::~ConVar(this: &old_armor);
}

//------------------------------------------------------------------------------
// Address: 0x1041D050
// Name: _dynamic_atexit_destructor_for__sv_noclipduringpause__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_noclipduringpause__()
{
  ConVar::~ConVar(this: &sv_noclipduringpause);
}

//------------------------------------------------------------------------------
// Address: 0x1041D060
// Name: _dynamic_atexit_destructor_for__sk_player_head__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_player_head__()
{
  ConVar::~ConVar(this: &sk_player_head);
}

//------------------------------------------------------------------------------
// Address: 0x1041D070
// Name: _dynamic_atexit_destructor_for__sk_player_chest__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_player_chest__()
{
  ConVar::~ConVar(this: &sk_player_chest);
}

//------------------------------------------------------------------------------
// Address: 0x1041D080
// Name: _dynamic_atexit_destructor_for__sk_player_stomach__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_player_stomach__()
{
  ConVar::~ConVar(this: &sk_player_stomach);
}

//------------------------------------------------------------------------------
// Address: 0x1041D090
// Name: _dynamic_atexit_destructor_for__sk_player_arm__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_player_arm__()
{
  ConVar::~ConVar(this: &sk_player_arm);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0A0
// Name: _dynamic_atexit_destructor_for__sk_player_leg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_player_leg__()
{
  ConVar::~ConVar(this: &sk_player_leg);
}
