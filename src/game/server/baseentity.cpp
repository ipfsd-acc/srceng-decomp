// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/baseentity.cpp
// Functions: 370
// ============================================================

#include "game\server\baseentity.h"

//------------------------------------------------------------------------------
// Address: 0x10019640
// Name: public: class Vector const __near & CBaseEntity::ScriptGetBoundingMins(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptGetBoundingMins(CBaseEntity *this)
{
  return this->m_Collision.OBBMins(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x10086F00
// Name: public: static class CBaseEntity __near * CBaseEntity::Instance(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CBaseEntity::Instance(edict_t *pent)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx

  pEdicts = pent;
  if ( (pent != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
    && (m_pUnk = pEdicts->m_pUnk) != nullptr )
  {
    return m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B32A0
// Name: int CellFromCoord(int,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CellFromCoord(int cellwidth, float f)
{
  if ( f >= 0.0 )
    return (int)f / cellwidth + 0x4000 / cellwidth;
  else
    return (int)(float)(f + 16384.0) / cellwidth;
}

//------------------------------------------------------------------------------
// Address: 0x100B3360
// Name: public: virtual class ServerClass __near * CBaseEntity::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseEntity::GetServerClass(CBaseEntity *this)
{
  return &g_CBaseEntity_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100B3370
// Name: bool EntityNamesMatchCStrings(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EntityNamesMatchCStrings(const char *pszQuery, const char *pszNameToMatch)
{
  const char *v2; // esi
  char v3; // bl
  char v5; // al
  const char *pszQuerya; // [esp+14h] [ebp+8h]

  v2 = pszNameToMatch;
  v3 = *pszNameToMatch;
  if ( *pszNameToMatch != 0 )
  {
    while ( 1 )
    {
      v5 = *pszQuery;
      if ( *pszQuery == 0 )
        break;
      if ( v3 == v5 || (pszQuerya = (const char *)tolower(c: v5), (const char *)tolower(c: v3) == pszQuerya) )
      {
        v3 = *++v2;
        ++pszQuery;
        if ( v3 != 0 )
          continue;
      }
      goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    if ( *pszQuery != 0 )
      return *pszQuery == 42;
  }
  if ( *v2 == 0 )
    return 1;
  return *pszQuery == 42;
}

//------------------------------------------------------------------------------
// Address: 0x100B33D0
// Name: public: void CBaseEntity::SetCollisionBounds(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetCollisionBounds(CBaseEntity *this, const Vector *mins, const Vector *maxs)
{
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x100B33E0
// Name: public: class Vector const __near & CBaseEntity::ScriptGetBoundingMaxs(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptGetBoundingMaxs(CBaseEntity *this)
{
  return this->m_Collision.OBBMaxs(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x100B3400
// Name: public: void CBaseEntity::SetClassname(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetClassname(CBaseEntity *this, const char *className)
{
  this->m_iClassname.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&className).pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x100B3420
// Name: public: virtual class Vector CBaseEntity::BodyTarget(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseEntity::BodyTarget(CBaseEntity *this, Vector *result, const Vector *posSrc, bool bNoisy)
{
  const Vector *v4; // eax
  __int64 v5; // xmm0_8
  float z; // eax

  v4 = this->WorldSpaceCenter(this);
  v5 = *(_QWORD *)&v4->x;
  z = v4->z;
  *(_QWORD *)&result->x = v5;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3450
// Name: public: virtual class Vector CBaseEntity::HeadTarget(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseEntity::HeadTarget(CBaseEntity *this, Vector *result, const Vector *posSrc)
{
  this->EyePosition(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3470
// Name: public: void CBaseEntity::AddTimedOverlay(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddTimedOverlay(CBaseEntity *this, const char *msg, int endTime)
{
  TimedOverlay_t *v4; // esi
  unsigned int v5; // kr00_4
  char *v6; // eax

  v4 = (TimedOverlay_t *)operator new(nSize: 0x10u);
  v5 = strlen(msg);
  v6 = (char *)operator new(nSize: v5 + 1);
  v4->msg = v6;
  V_strncpy(pDest: v6, pSrc: msg, maxLen: v5 + 1);
  v4->msgEndTime = (int)(float)((float)endTime + gpGlobals->curtime);
  v4->msgStartTime = (int)gpGlobals->curtime;
  v4->pNextTimedOverlay = this->m_pTimedOverlay;
  this->m_pTimedOverlay = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B34F0
// Name: public: void CBaseEntity::EntityText(int,char const __near *,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::EntityText(
        CBaseEntity *this,
        int text_offset,
        const char *text,
        float duration,
        int r,
        int g,
        int b,
        int a)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi
  const Vector *v9; // edi
  float *v10; // eax
  const QAngle *(__thiscall *GetCollisionAngles)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float v12; // xmm2_4
  float *v13; // ecx
  const matrix3x4_t *v14; // eax
  float *v15; // eax
  Vector origin; // [esp+1Ch] [ebp-18h] BYREF
  Vector vecLocalCenter; // [esp+28h] [ebp-Ch] BYREF

  p_m_Collision = &this->m_Collision;
  v9 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
  v10 = (float *)p_m_Collision->OBBMins(this: p_m_Collision);
  vecLocalCenter.x = *v10 + v9->x;
  vecLocalCenter.y = v10[1] + v9->y;
  GetCollisionAngles = p_m_Collision->GetCollisionAngles;
  v12 = (float)(v10[2] + v9->z) * 0.5;
  vecLocalCenter.x = vecLocalCenter.x * 0.5;
  vecLocalCenter.y = vecLocalCenter.y * 0.5;
  vecLocalCenter.z = v12;
  v13 = (float *)GetCollisionAngles(this: p_m_Collision);
  if ( vec3_angle.x == *v13 && vec3_angle.y == v13[1] && vec3_angle.z == v13[2]
    || vec3_origin.x == vecLocalCenter.x && vec3_origin.y == vecLocalCenter.y && vec3_origin.z == vecLocalCenter.z )
  {
    v15 = (float *)p_m_Collision->GetCollisionOrigin(this: p_m_Collision);
    origin.x = *v15 + vecLocalCenter.x;
    origin.y = v15[1] + vecLocalCenter.y;
    origin.z = v15[2] + vecLocalCenter.z;
  }
  else
  {
    v14 = p_m_Collision->CollisionToWorldTransform(this: p_m_Collision);
    VectorTransform(in1: &vecLocalCenter.x, in2: v14, out: &origin.x);
  }
  NDebugOverlay::EntityTextAtPosition(&origin, text_offset, text, duration, r, g, b, a);
}

//------------------------------------------------------------------------------
// Address: 0x100B3660
// Name: private: void CBaseEntity::TransformStepData_ParentToParent(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::TransformStepData_ParentToParent(
        CBaseEntity *this,
        CBaseEntity *pOldParent,
        CBaseEntity *pNewParent)
{
  char *DataObject; // esi
  Quaternion *v4; // edi
  Vector *v5; // esi
  Quaternion *v6; // [esp-24h] [ebp-28h]

  DataObject = (char *)CBaseEntity::GetDataObject(this, type: 2);
  if ( DataObject != nullptr )
  {
    UTIL_ParentToWorldSpace(
      pEntity: pOldParent,
      vecPosition: (Vector *)(DataObject + 8),
      quat: (Quaternion *)(DataObject + 20));
    UTIL_WorldToParentSpace(
      pEntity: pNewParent,
      vecPosition: (Vector *)(DataObject + 8),
      quat: (Quaternion *)(DataObject + 20));
    v4 = (Quaternion *)(DataObject + 52);
    v6 = (Quaternion *)(DataObject + 52);
    v5 = (Vector *)(DataObject + 40);
    UTIL_ParentToWorldSpace(pEntity: pOldParent, vecPosition: v5, quat: v6);
    UTIL_WorldToParentSpace(pEntity: pNewParent, vecPosition: v5, quat: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B36C0
// Name: private: void CBaseEntity::TransformStepData_WorldToParent(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::TransformStepData_WorldToParent(CBaseEntity *this, CBaseEntity *pParent)
{
  char *DataObject; // esi

  DataObject = (char *)CBaseEntity::GetDataObject(this, type: 2);
  if ( DataObject != nullptr )
  {
    UTIL_WorldToParentSpace(
      pEntity: pParent,
      vecPosition: (Vector *)(DataObject + 8),
      quat: (Quaternion *)(DataObject + 20));
    UTIL_WorldToParentSpace(
      pEntity: pParent,
      vecPosition: (Vector *)(DataObject + 40),
      quat: (Quaternion *)(DataObject + 52));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3700
// Name: public: class CBaseEntityOutput __near * CBaseEntity::FindNamedOutput(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntityOutput *__userpurge CBaseEntity::FindNamedOutput@<eax>(
        CBaseEntity *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *pszOutput)
{
  CBaseEntityOutput *result; // eax
  CBaseEntityOutput *m_Index; // ecx
  int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  char *v11; // esi
  int fields; // [esp+0h] [ebp-Ch]
  datamap_t *dmap; // [esp+8h] [ebp-4h]

  if ( pszOutput == nullptr )
    return nullptr;
  result = (CBaseEntityOutput *)((int (__thiscall *)(CBaseEntity *, int, int, int))this->GetDataDescMap)(
                                  a1: this,
                                  a2: a3,
                                  a3: a4,
                                  a4: a2);
  m_Index = result;
  dmap = (datamap_t *)result;
  if ( result != nullptr )
  {
    while ( 1 )
    {
      v7 = LODWORD(m_Index->m_Value.vecVal[1]);
      v8 = 0;
      fields = v7;
      if ( v7 > 0 )
        break;
LABEL_13:
      dmap = (datamap_t *)m_Index->m_Value.eVal.m_Index;
      if ( dmap == nullptr )
        return nullptr;
      m_Index = (CBaseEntityOutput *)m_Index->m_Value.eVal.m_Index;
    }
    v9 = 0;
    while ( 1 )
    {
      v10 = v9 + m_Index->m_Value.iVal;
      if ( *(_DWORD *)v10 == 11 && (*(_BYTE *)(v10 + 14) & 0x10) != 0 )
      {
        v11 = (char *)this + *(_DWORD *)(v10 + 8);
        if ( _V_stricmp(s1: *(const char **)(v10 + 16), s2: pszOutput) == 0 )
          return (CBaseEntityOutput *)v11;
        m_Index = (CBaseEntityOutput *)dmap;
        v7 = fields;
      }
      ++v8;
      v9 += 60;
      if ( v8 >= v7 )
        goto LABEL_13;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B37B0
// Name: public: virtual struct datamap_t __near * CBaseEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseEntity::GetDataDescMap(CBaseEntity *this)
{
  return &CBaseEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100B37C0
// Name: public: virtual struct ScriptClassDesc_t __near * CBaseEntity::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CBaseEntity::GetScriptDesc(CBaseEntity *this)
{
  return GetScriptDesc(__formal: this);
}

//------------------------------------------------------------------------------
// Address: 0x100B37E0
// Name: public: virtual void CBaseEntity::VPhysicsFriction(class IPhysicsObject __near *,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VPhysicsFriction(
        CBaseEntity *this,
        IPhysicsObject *pObject,
        float energy,
        int surfaceProps,
        int surfacePropsHit)
{
  PhysFrictionSound(pEntity: this, pObject, energy, surfaceProps, surfacePropsHit);
}

//------------------------------------------------------------------------------
// Address: 0x100B3810
// Name: public: virtual bool CBaseEntity::VPhysicsIsFlesh(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::VPhysicsIsFlesh(CBaseEntity *this)
{
  int v1; // edi
  int v2; // esi
  int v3; // eax
  int material; // eax
  _DWORD v6[1024]; // [esp+8h] [ebp-1000h] BYREF

  v1 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v6, a3: 1024);
  v2 = 0;
  if ( v1 <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v6[v2] + 152))(a1: v6[v2]);
    material = physprops->GetSurfaceData(this: physprops, a2: v3)->game.material;
    if ( material == 65 || material == 70 || material == 66 || material == 72 )
      break;
    if ( ++v2 >= v1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B3890
// Name: public: virtual float CBaseEntity::GetAutoAimRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntity::GetAutoAimRadius(CBaseEntity *this)
{
  if ( g_pGameRules->GetAutoAimMode(this: g_pGameRules) == 2 )
    return 48.0;
  else
    return 24.0;
}

//------------------------------------------------------------------------------
// Address: 0x100B38C0
// Name: public: int CBaseEntity::ShouldToggle(enum USE_TYPE,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::ShouldToggle(CBaseEntity *this, USE_TYPE useType, int currentState)
{
  if ( useType == USE_TOGGLE || useType == USE_SET )
    return 1;
  if ( currentState != 0 )
  {
    if ( useType != USE_ON )
      return 1;
  }
  else if ( useType != USE_OFF )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B38F0
// Name: public: static void __near * CBaseEntity::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CBaseEntity::operator new(unsigned int stAllocateBlock)
{
  return calloc(count: 1u, size: stAllocateBlock);
}

//------------------------------------------------------------------------------
// Address: 0x100B3910
// Name: public: static void CBaseEntity::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::operator delete(void *pMem)
{
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x100B3920
// Name: char const __near * ScriptFieldTypeName(short)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ScriptFieldTypeName(__int16 eType)
{
  const char *result; // eax

  switch ( eType )
  {
    case 0:
      result = "void";
      break;
    case 1:
      result = "float";
      break;
    case 3:
      result = "vector";
      break;
    case 5:
      result = "integer";
      break;
    case 6:
      result = "boolean";
      break;
    case 8:
      result = "character";
      break;
    case 32:
      result = "cstring";
      break;
    case 33:
      result = "hscript";
      break;
    case 34:
      result = "variant";
      break;
    default:
      result = "unknown_script_type";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B39D0
// Name: public: bool CBaseEntity::ReadKeyField(char const __near *,class variant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBaseEntity::ReadKeyField@<al>(
        CBaseEntity *this@<ecx>,
        int a2@<edi>,
        const char *varName,
        variant_t *var)
{
  _DWORD *v5; // esi
  int v6; // edi
  int v7; // ebx
  int v8; // eax

  if ( varName == nullptr )
    return 0;
  v5 = (_DWORD *)((int (__thiscall *)(CBaseEntity *, int))this->GetDataDescMap)(a1: this, a2);
  if ( v5 == nullptr )
    return 0;
  while ( 1 )
  {
    v6 = 0;
    if ( (int)v5[1] > 0 )
      break;
LABEL_9:
    v5 = (_DWORD *)v5[3];
    if ( v5 == nullptr )
      return 0;
  }
  v7 = 0;
  while ( 1 )
  {
    v8 = v7 + *v5;
    if ( (*(_BYTE *)(v8 + 14) & 0x14) != 0 && _V_stricmp(s1: *(const char **)(v8 + 16), s2: varName) == 0 )
      break;
    ++v6;
    v7 += 60;
    if ( v6 >= v5[1] )
      goto LABEL_9;
  }
  variant_t::Set(this: var, ftype: *(_fieldtypes *)(*v5 + 60 * v6), data: (char *)this + *(_DWORD *)(*v5 + 60 * v6 + 8));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B3A70
// Name: public: ScriptVariant_t::operator class Vector const __near &(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall ScriptVariant_t::operator Vector const &(ScriptVariant_t *this)
{
  const Vector *result; // eax

  if ( (___B_1___BScriptVariant_t__QBEABVVector__XZ_51 & 1) == 0 )
  {
    ___B_1___BScriptVariant_t__QBEABVVector__XZ_51 |= 1u;
    _vecNull__1___BScriptVariant_t__QBEABVVector__XZ_4V2_A.x = 0.0;
    _vecNull__1___BScriptVariant_t__QBEABVVector__XZ_4V2_A.y = 0.0;
    _vecNull__1___BScriptVariant_t__QBEABVVector__XZ_4V2_A.z = 0.0;
  }
  result = (const Vector *)this->m_int;
  if ( this->m_int == 0 )
    return &_vecNull__1___BScriptVariant_t__QBEABVVector__XZ_4V2_A;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3AB0
// Name: public: bool ScriptVariant_t::AssignTo(float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScriptVariant_t::AssignTo(ScriptVariant_t *this, float *pDest)
{
  bool result; // al
  const char *v3; // eax

  switch ( this->m_type )
  {
    case 0:
      *pDest = 0.0;
      result = false;
      break;
    case 1:
      *pDest = this->m_float;
      result = true;
      break;
    case 5:
      *pDest = (float)this->m_int;
      result = true;
      break;
    case 6:
      *pDest = (float)(unsigned __int8)this->m_char;
      result = true;
      break;
    default:
      v3 = ScriptFieldTypeName(eType: this->m_type);
      DevWarning(a1: "No conversion from %s to float now\n", v3);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3B50
// Name: public: void CBaseEntity::InputClearParent(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputClearParent(CBaseEntity *this, inputdata_t *inputdata)
{
  this->SetParent(this, a2: nullptr, a3: -1);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B70
// Name: public: virtual bool CBaseEntity::IsMoving(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::IsMoving(CBaseEntity *this)
{
  Vector velocity; // [esp+0h] [ebp-Ch] BYREF

  this->GetVelocity(this, a2: &velocity, a3: nullptr);
  return vec3_origin.x != velocity.x || vec3_origin.y != velocity.y || vec3_origin.z != velocity.z;
}

//------------------------------------------------------------------------------
// Address: 0x100B3BD0
// Name: public: virtual void CBaseEntity::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetModel(CBaseEntity *this, const char *szModelName)
{
  int v3; // eax
  const struct model_t *v4; // eax

  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: szModelName);
  v4 = modelinfo->GetModel(this: modelinfo, a2: v3);
  if ( v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) != 1 )
    _Msg(a1: "Setting CBaseEntity to non-brush model %s\n", szModelName);
  UTIL_SetModel(pEntity: this, pModelName: szModelName);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C30
// Name: public: void CBaseEntity::InputSetTeam(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputSetTeam(CBaseEntity *this, inputdata_t *inputdata)
{
  if ( !this->IsPlayer(this) )
  {
    if ( inputdata->value.fieldType == FIELD_INTEGER )
      this->ChangeTeam(this, a2: inputdata->value.iVal);
    else
      this->ChangeTeam(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3C80
// Name: public: bool CBaseEntity::KeyValueFromString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::KeyValueFromString(CBaseEntity *this, const char *szKeyName, const char *szValue)
{
  return this->KeyValue_4(this, a2: szKeyName, a3: szValue);
}

//------------------------------------------------------------------------------
// Address: 0x100B3C90
// Name: public: bool CBaseEntity::KeyValueFromFloat(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::KeyValueFromFloat(CBaseEntity *this, const char *szKeyName, float flValue)
{
  return ((bool (__stdcall *)(const char *, _DWORD))this->KeyValue_3)(a1: szKeyName, a2: LODWORD(flValue));
}

//------------------------------------------------------------------------------
// Address: 0x100B3CB0
// Name: public: bool CBaseEntity::KeyValueFromInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::KeyValueFromInt(CBaseEntity *this, const char *szKeyName, int nValue)
{
  return this->KeyValue_2(this, a2: szKeyName, a3: nValue);
}

//------------------------------------------------------------------------------
// Address: 0x100B3CC0
// Name: public: bool CBaseEntity::KeyValueFromVector(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::KeyValueFromVector(CBaseEntity *this, const char *szKeyName, const Vector *vecValue)
{
  return this->KeyValue(this, a2: szKeyName, a3: vecValue);
}

//------------------------------------------------------------------------------
// Address: 0x100B3CD0
// Name: public: void CBaseEntity::SetSize(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetSize(CBaseEntity *this, const Vector *mins, const Vector *maxs)
{
  UTIL_SetSize(pEnt: this, vecMin: mins, vecMax: maxs);
}

//------------------------------------------------------------------------------
// Address: 0x100B3CF0
// Name: void ModelSoundsCache_PrecacheScriptSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ModelSoundsCache_PrecacheScriptSound(const char *soundname)
{
  CBaseEntity::PrecacheScriptSound(soundname);
}

//------------------------------------------------------------------------------
// Address: 0x100B3D00
// Name: public: void CBaseEntity::SUB_CallUseToggle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SUB_CallUseToggle(CBaseEntity *this)
{
  ((void (__stdcall *)(CBaseEntity *, CBaseEntity *, int, _DWORD))this->Use)(a1: this, a2: this, a3: 3, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B3D20
// Name: void CC_Ent_Name(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Name(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: CommandClient, name: v3, bit: 2);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: v1, name: locale, bit: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3D60
// Name: void CC_Ent_Text(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Text(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: CommandClient, name: v3, bit: 1);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: v1, name: locale, bit: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3DA0
// Name: void CC_Ent_BBox(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_BBox(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: CommandClient, name: v3, bit: 4);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: v1, name: locale, bit: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3DE0
// Name: void CC_Ent_AbsBox(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_AbsBox(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: CommandClient, name: v3, bit: 32);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: v1, name: locale, bit: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3E20
// Name: void CC_Ent_RBox(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_RBox(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: CommandClient, name: v3, bit: 64);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: v1, name: locale, bit: 64);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3E60
// Name: void CC_Ent_AttachmentPoints(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_AttachmentPoints(const CCommand *args)
{
  const char *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = locale;
  v3 = v1;
  CommandClient = UTIL_GetCommandClient();
  SetDebugBits(pPlayer: CommandClient, name: v3, bit: 256);
}

//------------------------------------------------------------------------------
// Address: 0x100B3E90
// Name: void CC_Ent_ViewOffset(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_ViewOffset(const CCommand *args)
{
  const char *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = locale;
  v3 = v1;
  CommandClient = UTIL_GetCommandClient();
  SetDebugBits(pPlayer: CommandClient, name: v3, bit: 0x40000000);
}

//------------------------------------------------------------------------------
// Address: 0x100B3EC0
// Name: public: class Vector const __near & CBaseEntity::ScriptEyePosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptEyePosition(CBaseEntity *this)
{
  _BYTE v2[12]; // [esp+0h] [ebp-Ch] BYREF

  if ( (`CBaseEntity::ScriptEyePosition'::`2'::`local static guard' & 1) == 0 )
    `CBaseEntity::ScriptEyePosition'::`2'::`local static guard' |= 1u;
  `CBaseEntity::ScriptEyePosition'::`2'::vec = *this->EyePosition(this, result: v2);
  return &`CBaseEntity::ScriptEyePosition'::`2'::vec;
}

//------------------------------------------------------------------------------
// Address: 0x100B3F20
// Name: public: void CBaseEntity::ScriptSetAngles(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ScriptSetAngles(CBaseEntity *this, float fPitch, float fYaw, float fRoll)
{
  void (__thiscall *Teleport)(CBaseEntity *, const Vector *, const QAngle *, const Vector *, bool); // eax
  QAngle angles; // [esp+0h] [ebp-Ch] BYREF

  Teleport = this->Teleport;
  angles.x = fPitch;
  angles.y = fYaw;
  angles.z = fRoll;
  Teleport(this, a2: nullptr, a3: &angles, a4: nullptr, a5: true);
}

//------------------------------------------------------------------------------
// Address: 0x100B3F60
// Name: public: void CBaseEntity::ScriptSetOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ScriptSetOrigin(CBaseEntity *this, const Vector *v)
{
  this->Teleport(this, a2: v, a3: nullptr, a4: nullptr, a5: true);
}

//------------------------------------------------------------------------------
// Address: 0x100B3F80
// Name: public: void CBaseEntity::ScriptSetForward(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ScriptSetForward(CBaseEntity *this, const Vector *v)
{
  QAngle angles; // [esp+4h] [ebp-Ch] BYREF

  VectorAngles(forward: v, &angles);
  this->Teleport(this, a2: nullptr, a3: &angles, a4: nullptr, a5: true);
}

//------------------------------------------------------------------------------
// Address: 0x100B3FC0
// Name: public: class Vector const __near & CBaseEntity::ScriptGetForward(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptGetForward(CBaseEntity *this)
{
  if ( (`CBaseEntity::ScriptGetForward'::`2'::`local static guard' & 1) == 0 )
    `CBaseEntity::ScriptGetForward'::`2'::`local static guard' |= 1u;
  this->GetVectors(this, a2: &`CBaseEntity::ScriptGetForward'::`2'::vecForward, a3: nullptr, a4: nullptr);
  return &`CBaseEntity::ScriptGetForward'::`2'::vecForward;
}

//------------------------------------------------------------------------------
// Address: 0x100B4000
// Name: public: class Vector const __near & CBaseEntity::ScriptGetLeft(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptGetLeft(CBaseEntity *this)
{
  if ( (`CBaseEntity::ScriptGetLeft'::`2'::`local static guard' & 1) == 0 )
    `CBaseEntity::ScriptGetLeft'::`2'::`local static guard' |= 1u;
  this->GetVectors(this, a2: nullptr, a3: &`CBaseEntity::ScriptGetLeft'::`2'::vecLeft, a4: nullptr);
  return &`CBaseEntity::ScriptGetLeft'::`2'::vecLeft;
}

//------------------------------------------------------------------------------
// Address: 0x100B4030
// Name: public: class Vector const __near & CBaseEntity::ScriptGetUp(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptGetUp(CBaseEntity *this)
{
  if ( (`CBaseEntity::ScriptGetUp'::`2'::`local static guard' & 1) == 0 )
    `CBaseEntity::ScriptGetUp'::`2'::`local static guard' |= 1u;
  this->GetVectors(this, a2: nullptr, a3: nullptr, a4: &`CBaseEntity::ScriptGetUp'::`2'::vecUp);
  return &`CBaseEntity::ScriptGetUp'::`2'::vecUp;
}

//------------------------------------------------------------------------------
// Address: 0x100B4060
// Name: void CC_Ent_Messages(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Messages(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: CommandClient, name: v3, bit: 16);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: v1, name: locale, bit: 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B40A0
// Name: void CC_Ent_Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Pause()
{
  if ( CBaseEntity::m_bDebugPause )
  {
    _Msg(a1: "Resuming entity I/O events\n");
    CBaseEntity::m_bDebugPause = false;
  }
  else
  {
    _Msg(a1: "Pausing entity I/O events\n");
    CBaseEntity::m_bDebugPause = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B40E0
// Name: public: static class CBaseEntity __near * CBaseEntity::Instance(int)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CBaseEntity::Instance(int iEnt)
{
  edict_t *pEdicts; // esi
  edict_t *v2; // eax
  IServerUnknown *m_pUnk; // ecx

  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v2 = (pEdicts[iEnt].m_fStateFlags & 2) == 0 ? &pEdicts[iEnt] : nullptr;
  else
    v2 = nullptr;
  if ( (v2 != nullptr || pEdicts != nullptr && (v2 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
    && (m_pUnk = v2->m_pUnk) != nullptr )
  {
    return m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4140
// Name: void CC_Ent_Picker(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Picker()
{
  CBaseEntity::m_bInDebugSelect = !CBaseEntity::m_bInDebugSelect;
  CBaseEntity::m_nDebugPlayer = UTIL_GetCommandClientIndex();
}

//------------------------------------------------------------------------------
// Address: 0x100B4160
// Name: void CC_Ent_Pivot(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Pivot(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: CommandClient, name: v3, bit: 8);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    SetDebugBits(pPlayer: v1, name: locale, bit: 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B41A0
// Name: void CC_Ent_Step(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Step(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax

  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = locale;
  v2 = atoi(nptr: v1);
  if ( v2 <= 0 )
    v2 = 1;
  CBaseEntity::m_nDebugSteps = v2;
}

//------------------------------------------------------------------------------
// Address: 0x100B41E0
// Name: public: struct model_t __near * CBaseEntity::GetModel(void)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CBaseEntity::GetModel(CBaseEntity *this)
{
  IVModelInfo_vtbl *v1; // esi
  int v2; // eax

  v1 = modelinfo->__vftable;
  v2 = this->GetModelIndex(this);
  return v1->GetModel(this: modelinfo, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100B4200
// Name: public: char const __near * CBaseEntity::ScriptGetModelName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::ScriptGetModelName(CBaseEntity *this)
{
  const char *result; // eax

  result = this->m_ModelName.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B4210
// Name: public: void CBaseEntity::SetLocalAngularVelocity(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetLocalAngularVelocity(CBaseEntity *this, const QAngle *vecAngVelocity)
{
  if ( vecAngVelocity->x != this->m_vecAngVelocity.x
    || vecAngVelocity->y != this->m_vecAngVelocity.y
    || vecAngVelocity->z != this->m_vecAngVelocity.z )
  {
    this->m_vecAngVelocity = *vecAngVelocity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4270
// Name: public: void CBaseEntity::ScriptSetLocalAngularVelocity(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ScriptSetLocalAngularVelocity(
        CBaseEntity *this,
        float pitchVel,
        float yawVel,
        float rollVel)
{
  if ( pitchVel != this->m_vecAngVelocity.x || yawVel != this->m_vecAngVelocity.y || rollVel != this->m_vecAngVelocity.z )
  {
    this->m_vecAngVelocity.x = pitchVel;
    this->m_vecAngVelocity.y = yawVel;
    this->m_vecAngVelocity.z = rollVel;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B42D0
// Name: public: class Vector const __near & CBaseEntity::ScriptGetLocalAngularVelocity(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptGetLocalAngularVelocity(CBaseEntity *this)
{
  QAngle qa; // 0:^0.12

  qa = this->m_vecAngVelocity;
  if ( (_S8_0 & 1) == 0 )
    _S8_0 |= 1u;
  v = (Vector)qa;
  return &v;
}

//------------------------------------------------------------------------------
// Address: 0x100B4330
// Name: public: bool CBaseEntity::IsFloating(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::IsFloating(CBaseEntity *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  int v3; // eax
  float flThickness; // [esp+0h] [ebp-10h] BYREF
  float flFriction; // [esp+4h] [ebp-Ch] BYREF
  float flElasticity; // [esp+8h] [ebp-8h] BYREF
  float flDensity; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_iEFlags & 0x80000) == 0 )
    return false;
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr )
    return false;
  v3 = m_pPhysicsObject->GetMaterialIndex(this: m_pPhysicsObject);
  physprops->GetPhysicsProperties(
    this: physprops,
    a2: v3,
    a3: &flDensity,
    a4: &flThickness,
    a5: &flFriction,
    a6: &flElasticity);
  return flDensity < 1000.0;
}

//------------------------------------------------------------------------------
// Address: 0x100B43A0
// Name: public: void CBaseEntity::RemoveAllDecals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RemoveAllDecals(CBaseEntity *this)
{
  EntityMessageBegin(entity: this, reliable: false);
  MessageWriteByte(iValue: 1);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x100B43C0
// Name: public: void CBaseEntity::InputFireUser1(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputFireUser1(CBaseEntity *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnUser1, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100B43F0
// Name: public: void CBaseEntity::InputFireUser2(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputFireUser2(CBaseEntity *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnUser2, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4420
// Name: public: void CBaseEntity::InputFireUser3(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputFireUser3(CBaseEntity *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnUser3, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4450
// Name: public: void CBaseEntity::InputFireUser4(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputFireUser4(CBaseEntity *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnUser4, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4480
// Name: public: void CBaseEntity::ConnectOutputToScript(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::ConnectOutputToScript(
        CBaseEntity *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pszOutput,
        const char *pszScriptFunc)
{
  const char *v5; // esi
  CBaseEntityOutput *NamedOutput; // edi
  CEventAction *m_ActionList; // esi
  const char *v8; // ebx
  const char *pszValue; // eax
  const char *v10; // eax
  CEventAction *v11; // eax
  CEventAction *v12; // esi

  v5 = pszOutput;
  NamedOutput = CBaseEntity::FindNamedOutput(this, a2, a3, a4: (int)pszOutput, pszOutput);
  if ( NamedOutput != nullptr )
  {
    AllocPooledString(pszValue: (const char *)&pszOutput);
    m_ActionList = NamedOutput->m_ActionList;
    v8 = pszScriptFunc;
    if ( m_ActionList != nullptr )
    {
      while ( 1 )
      {
        if ( m_ActionList->m_iTarget.pszValue == pszOutput
          && m_ActionList->m_flDelay == 0.0
          && m_ActionList->m_nTimesToFire == -1 )
        {
          pszValue = m_ActionList->m_iTargetInput.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          if ( _V_strcmp(s1: pszValue, s2: "CallScriptFunction") == 0 )
          {
            v10 = m_ActionList->m_iParameter.pszValue;
            if ( v10 == nullptr )
              v10 = locale;
            if ( _V_strcmp(s1: v10, s2: v8) == 0 )
              break;
          }
        }
        m_ActionList = m_ActionList->m_pNext;
        if ( m_ActionList == nullptr )
          goto LABEL_14;
      }
    }
    else
    {
LABEL_14:
      v11 = (CEventAction *)CEventAction::operator new(stAllocateBlock: 0x1Cu);
      if ( v11 != nullptr )
        v12 = CEventAction::CEventAction(this: v11, ActionData: nullptr);
      else
        v12 = nullptr;
      v12->m_iTarget.pszValue = pszOutput;
      v12->m_iTargetInput.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&pszScriptFunc).pszValue;
      v12->m_iParameter.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&pszScriptFunc).pszValue;
      CBaseEntityOutput::AddEventAction(this: NamedOutput, pEventAction: v12);
    }
  }
  else
  {
    _DevMsg(a1: 2, a2: "Script failed to find output \"%s\"\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4580
// Name: public: void CBaseEntity::DisconnectOutputFromScript(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::DisconnectOutputFromScript(
        CBaseEntity *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const char *pszOutput,
        const char *pszScriptFunc)
{
  const char *v5; // esi
  CBaseEntityOutput *NamedOutput; // edi
  CEventAction *m_ActionList; // esi
  const char *v8; // ebx
  const char *pszValue; // eax
  const char *v10; // eax

  v5 = pszOutput;
  NamedOutput = CBaseEntity::FindNamedOutput(this, a2, a3, a4: (int)pszOutput, pszOutput);
  if ( NamedOutput != nullptr )
  {
    AllocPooledString(pszValue: (const char *)&pszOutput);
    m_ActionList = NamedOutput->m_ActionList;
    if ( m_ActionList != nullptr )
    {
      v8 = pszScriptFunc;
      while ( 1 )
      {
        if ( m_ActionList->m_iTarget.pszValue == pszOutput
          && m_ActionList->m_flDelay == 0.0
          && m_ActionList->m_nTimesToFire == -1 )
        {
          pszValue = m_ActionList->m_iTargetInput.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          if ( _V_strcmp(s1: pszValue, s2: "CallScriptFunction") == 0 )
          {
            v10 = m_ActionList->m_iParameter.pszValue;
            if ( v10 == nullptr )
              v10 = locale;
            if ( _V_strcmp(s1: v10, s2: v8) == 0 )
              break;
          }
        }
        m_ActionList = m_ActionList->m_pNext;
        if ( m_ActionList == nullptr )
          return;
      }
      CBaseEntityOutput::RemoveEventAction(this: NamedOutput, pEventAction: m_ActionList);
      CEventAction::operator delete(pMem: m_ActionList);
    }
  }
  else
  {
    _DevMsg(a1: 2, a2: "Script failed to find output \"%s\"\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4650
// Name: public: char const __near * CBaseEntity::GetScriptId(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::GetScriptId(CBaseEntity *this)
{
  const char *result; // eax

  result = this->m_iszScriptThinkFunction.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B4660
// Name: public: void CBaseEntity::InputDispatchResponse(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputDispatchResponse(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      this->DispatchResponse(this, a2: locale);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  this->DispatchResponse(this, a2: iVal);
}

//------------------------------------------------------------------------------
// Address: 0x100B46B0
// Name: public: void CBaseEntity::InputDisableShadow(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputDisableShadow(CBaseEntity *this, inputdata_t *inputdata)
{
  CBaseEntity::AddEffects(this, nEffects: 16);
}

//------------------------------------------------------------------------------
// Address: 0x100B46C0
// Name: public: void CBaseEntity::InputDisableReceivingFlashlight(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputDisableReceivingFlashlight(CBaseEntity *this, inputdata_t *inputdata)
{
  CBaseEntity::AddEffects(this, nEffects: 0x2000);
}

//------------------------------------------------------------------------------
// Address: 0x100B46D0
// Name: public: void CBaseEntity::InputEnableDrawInFastReflection(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputEnableDrawInFastReflection(CBaseEntity *this, inputdata_t *inputdata)
{
  CBaseEntity::AddEffects(this, nEffects: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x100B46E0
// Name: public: void CBaseEntity::InputAddOutput(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputAddOutput(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  _BYTE *v5; // eax
  unsigned __int8 *v6; // esi
  _BYTE *v7; // eax
  char sOutputName[260]; // [esp+4h] [ebp-104h] BYREF

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  V_strncpy(pDest: sOutputName, pSrc: iVal, maxLen: 260);
  strchr(string: (unsigned __int8 *)sOutputName, chr: 0x20u);
  if ( v5 != nullptr )
  {
    v6 = v5 + 1;
    *v5 = 0;
    strchr(string: v5 + 1, chr: 0x3Au);
    while ( v7 != nullptr )
    {
      *v7 = 44;
      strchr(string: v6, chr: 0x3Au);
    }
    this->KeyValue_4(this, a2: sOutputName, a3: (const char *)v6);
  }
  else
  {
    _Warning(
      a1: "AddOutput input fired with bad string. Format: <output name> <targetname>,<inputname>,<parameter>,<delay>,<max tim"
      "es to fire (-1 == infinite)>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4790
// Name: void CC_Ent_Autoaim(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Autoaim(const CCommand *args)
{
  const char *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-8h] [ebp-8h]

  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = locale;
  v3 = v1;
  CommandClient = UTIL_GetCommandClient();
  SetDebugBits(pPlayer: CommandClient, name: v3, bit: 512);
}

//------------------------------------------------------------------------------
// Address: 0x100B47C0
// Name: public: virtual class CAI_BaseNPC __near * CBaseEntity::MyNPCPointer(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CBaseEntity::MyNPCPointer(CBaseEntity *this)
{
  return this->IsNPC(this) ? (CAI_BaseNPC *)this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B47E0
// Name: public: static void CBaseEntity::RemoveRecipientsIfNotCloseCaptioning(class CRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::RemoveRecipientsIfNotCloseCaptioning(CRecipientFilter *filter)
{
  int v2; // eax
  int v3; // eax
  edict_t *pEdicts; // esi
  int v5; // edi
  edict_t *v6; // eax
  IServerUnknown *m_pUnk; // ecx
  signed int v8; // esi
  const char *v9; // eax
  int i; // [esp+Ch] [ebp+8h]

  v2 = filter->GetRecipientCount(this: filter) - 1;
  i = v2;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      v3 = filter->GetRecipientIndex(this: filter, a2: v2);
      pEdicts = gpGlobals->pEdicts;
      v5 = v3;
      if ( pEdicts != nullptr )
        v6 = (pEdicts[v3].m_fStateFlags & 2) == 0 ? &pEdicts[v3] : nullptr;
      else
        v6 = nullptr;
      if ( v6 != nullptr || pEdicts != nullptr && (v6 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
      {
        m_pUnk = v6->m_pUnk;
        if ( m_pUnk != nullptr )
        {
          v8 = (signed int)m_pUnk->GetBaseEntity(this: m_pUnk);
          if ( v8 != 0 )
          {
            v9 = engine->GetClientConVarValue(this: engine, a2: v5, a3: "closecaption");
            if ( *v9 != 0 && atoi(nptr: v9) == 0 )
              CRecipientFilter::RemoveRecipient(this: filter, player: v8);
          }
        }
      }
      if ( --i < 0 )
        break;
      v2 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B48A0
// Name: public: virtual bool CServerOnlyPointEntity::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerOnlyPointEntity::KeyValue(CLogicalEntity *this, const char *szKeyName, const char *szValue)
{
  const char *pszValue; // eax

  if ( szKeyName != "mins"
    && _V_stricmp(s1: szKeyName, s2: "mins") != 0
    && szKeyName != "maxs"
    && _V_stricmp(s1: szKeyName, s2: "maxs") != 0 )
  {
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  }
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  _Warning(a1: "Warning! Can't specify mins/maxs for point entities! (%s)\n", pszValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100B4920
// Name: public: bool CBaseEntity::DoesHavePlayerChild(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::DoesHavePlayerChild(CBaseEntity *this)
{
  return HIWORD(this->m_iEFlags) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B4930
// Name: public: void CBaseEntity::SetNetworkQuantizeOriginAngAngles(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetNetworkQuantizeOriginAngAngles(CBaseEntity *this, bool bQuantize)
{
  this->m_bNetworkQuantizeOriginAndAngles = bQuantize;
}

//------------------------------------------------------------------------------
// Address: 0x100B4940
// Name: public: void CBaseEntity::NetworkQuantize(class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::NetworkQuantize(CBaseEntity *this, Vector *org, QAngle *angles)
{
  int i; // eax
  int j; // eax
  double v5; // st7

  if ( this->m_bNetworkQuantizeOriginAndAngles )
  {
    for ( i = 0; i < 3; ++i )
      *(&org->x + i) = (float)(int)(float)(*(&org->x + i) * 32.0) * 0.03125;
    for ( j = 0; j < 3; *((float *)angles + j - 1) = v5 * 0.043945312 )
      v5 = (double)(unsigned int)(__int64)(float)((float)((float)(unsigned __int16)(int)(float)(*(&angles->x + j++)
                                                                                              * 182.04445)
                                                        * 0.0054931641)
                                                * 22.755556);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4A40
// Name: public: bool CUtlCachedFileData<class CModelSoundsCache>::ManifestExists(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlCachedFileData<CModelSoundsCache>::ManifestExists(CUtlCachedFileData<CModelSoundsCache> *this)
{
  const char *v1; // eax
  char manifest_name[512]; // [esp+0h] [ebp-200h] BYREF

  v1 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v1, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD");
}

//------------------------------------------------------------------------------
// Address: 0x100B4C40
// Name: void SendProxy_AnimTime(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_AnimTime(const SendProp *pProp, float *pStruct, const void *pVarData, DVariant *pOut)
{
  signed int v4; // eax
  int v5; // esi
  int v6; // eax

  v4 = *((_DWORD *)pStruct + 6);
  v5 = (int)(float)((float)(pStruct[25] / gpGlobals->interval_per_tick) + 0.5);
  if ( v4 != 0 )
    v4 = (signed int)(v4 - (unsigned int)gpGlobals->pEdicts) >> 4;
  v6 = gpGlobals->nTimestampNetworkingBase
     * ((gpGlobals->tickcount - v4 % gpGlobals->nTimestampRandomizeWindow)
      / gpGlobals->nTimestampNetworkingBase);
  if ( v5 < v6 - 100 )
    pOut->m_Int = 0;
  else
    pOut->m_Int = (unsigned __int8)(v5 - v6);
}

//------------------------------------------------------------------------------
// Address: 0x100B4CB0
// Name: void SendProxy_SimulationTime(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_SimulationTime(const SendProp *pProp, float *pStruct, const void *pVarData, DVariant *pOut)
{
  signed int v4; // eax
  int v5; // esi
  int v6; // eax

  v4 = *((_DWORD *)pStruct + 6);
  v5 = (int)(float)((float)(pStruct[26] / gpGlobals->interval_per_tick) + 0.5);
  if ( v4 != 0 )
    v4 = (signed int)(v4 - (unsigned int)gpGlobals->pEdicts) >> 4;
  v6 = gpGlobals->nTimestampNetworkingBase
     * ((gpGlobals->tickcount - v4 % gpGlobals->nTimestampRandomizeWindow)
      / gpGlobals->nTimestampNetworkingBase);
  if ( v5 < v6 )
    pOut->m_Int = 0;
  else
    pOut->m_Int = (unsigned __int8)(v5 - v6);
}

//------------------------------------------------------------------------------
// Address: 0x100B4D20
// Name: public: float CBaseEntity::GetGlobalFadeScale(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntity::GetGlobalFadeScale(CBaseEntity *this)
{
  return this->m_flFadeScale.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100B4D30
// Name: public: virtual int CBaseEntity::VPhysicsTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBaseEntity::VPhysicsTakeDamage@<eax>(
        CBaseEntity *this@<ecx>,
        int a2@<edi>,
        const CTakeDamageInfo *info)
{
  int m_bitsDamageType; // eax
  float z; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  float v7; // edx
  float v8; // eax
  char v9; // al
  CBasePlayer *LocalPlayer; // eax
  double v11; // st7
  double v12; // st7
  int v14; // edi
  int v15; // esi
  _DWORD v16[1024]; // [esp+8h] [ebp-1018h] BYREF
  __int64 v17; // [esp+1008h] [ebp-18h]
  float v18; // [esp+1010h] [ebp-10h]
  __int64 v19; // [esp+1014h] [ebp-Ch] BYREF
  float v20; // [esp+101Ch] [ebp-4h]
  float v21; // [esp+1028h] [ebp+8h]

  if ( g_pGameRules->Damage_NoPhysicsForce(this: g_pGameRules, a2: info->m_bitsDamageType) )
    return 1;
  m_bitsDamageType = info->m_bitsDamageType;
  if ( m_bitsDamageType == 0 )
    return 1;
  if ( (m_bitsDamageType & 0x82) != 0 )
  {
    z = info->m_vecDamageForce.z;
    v19 = *(_QWORD *)&info->m_vecDamageForce.x;
    v20 = z;
    if ( *(float *)&v19 > -0.0099999998
      && *(float *)&v19 < 0.0099999998
      && *((float *)&v19 + 1) > -0.0099999998
      && *((float *)&v19 + 1) < 0.0099999998
      && v20 > -0.0099999998
      && v20 < 0.0099999998 )
    {
      return 1;
    }
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr )
    return 1;
  v7 = info->m_vecDamageForce.z;
  v8 = info->m_vecDamagePosition.z;
  v19 = *(_QWORD *)&info->m_vecDamageForce.x;
  v18 = v8;
  v20 = v7;
  v17 = *(_QWORD *)&info->m_vecDamagePosition.x;
  v9 = ((int (__thiscall *)(IPhysicsObject *, int))m_pPhysicsObject->GetGameFlags)(a1: m_pPhysicsObject, a2);
  if ( (v9 & 4) != 0 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
    {
      v11 = ((double (__thiscall *)(CBasePlayer *, IPhysicsObject *))LocalPlayer->GetHeldObjectMass)(
              a1: LocalPlayer,
              a2: this->m_pPhysicsObject);
      if ( v11 != 0.0 )
      {
        v21 = v11;
        v12 = ((double (__thiscall *)(IPhysicsObject *))this->m_pPhysicsObject->GetMass)(a1: this->m_pPhysicsObject)
            / v21;
        *(float *)&v19 = *(float *)&v19 * v12;
        *((float *)&v19 + 1) = *((float *)&v19 + 1) * v12;
        v20 = v12 * v20;
      }
    }
    goto LABEL_15;
  }
  if ( (v9 & 8) == 0
    || (v9 & 2) == 0
    || (v14 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v16, a3: 1024), v15 = 0, v14 <= 0) )
  {
LABEL_15:
    ((void (__thiscall *)(IPhysicsObject *, __int64 *))this->m_pPhysicsObject->ApplyForceOffset)(
      a1: this->m_pPhysicsObject,
      a2: &v19);
    return 1;
  }
  while ( ((*(int (__thiscall **)(_DWORD))(*(_DWORD *)v16[v15] + 76))(a1: v16[v15]) & 2) != 0 )
  {
    if ( ++v15 >= v14 )
      goto LABEL_15;
  }
  (*(void (__thiscall **)(_DWORD, __int64 *))(*(_DWORD *)v16[v15] + 244))(a1: v16[v15], a2: &v19);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B4EE0
// Name: public: virtual bool CBaseEntity::HasTarget(struct string_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::HasTarget(CBaseEntity *this, string_t targetname)
{
  const char *pszValue; // eax

  if ( targetname.pszValue == nullptr )
    return false;
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    return false;
  return targetname.pszValue == pszValue || _V_stricmp(s1: targetname.pszValue, s2: this->m_target.pszValue) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B4F20
// Name: public: class CBaseEntity __near * CBaseEntity::GetNextTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetNextTarget(CBaseEntity *this)
{
  CBaseEntity *result; // eax

  result = (CBaseEntity *)this->m_target.pszValue;
  if ( result != nullptr )
    return CGlobalEntityList::FindEntityByName(
             this: &gEntList,
             pStartEntity: nullptr,
             szName: (const char *)result,
             pSearchingEntity: nullptr,
             pActivator: nullptr,
             pCaller: nullptr,
             pFilter: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B4F50
// Name: class IScriptInstanceHelper __near * GetScriptInstanceHelper_CBaseEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntityScriptInstanceHelper *__cdecl GetScriptInstanceHelper_CBaseEntity()
{
  return &g_BaseEntityScriptInstanceHelper;
}

//------------------------------------------------------------------------------
// Address: 0x100B4F60
// Name: FindPhysicsBlocker
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall FindPhysicsBlocker@<eax>(
        Vector *p_normal@<ebx>,
        IPhysicsObject *pPhysics,
        physicspushlist_t *list,
        const Vector *pushVel)
{
  IPhysicsObject *v4; // edi
  IPhysicsFrictionSnapshot *v5; // esi
  bool (__thiscall *IsValid)(IPhysicsFrictionSnapshot *); // edx
  int v7; // eax
  int pushedCount; // edi
  int v9; // edx
  unsigned int v10; // eax
  CBaseEntity *m_pEntity; // ecx
  float v12; // xmm2_4
  Vector normal; // [esp+8h] [ebp-20h] BYREF
  float maxForce; // [esp+14h] [ebp-14h]
  CBaseEntity *pOtherEntity; // [esp+18h] [ebp-10h]
  CBaseEntity *pBlocker; // [esp+1Ch] [ebp-Ch]
  float v19; // [esp+20h] [ebp-8h]
  bool inList; // [esp+27h] [ebp-1h]

  v4 = pPhysics;
  v5 = pPhysics->CreateFrictionSnapshot(this: pPhysics);
  IsValid = v5->IsValid;
  pBlocker = nullptr;
  maxForce = 0.0;
  if ( IsValid(this: v5) )
  {
    do
    {
      v7 = ((int (__thiscall *)(IPhysicsFrictionSnapshot *, int, Vector *))v5->GetObject)(a1: v5, a2: 1, a3: p_normal);
      pOtherEntity = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 68))(a1: v7);
      pushedCount = list->pushedCount;
      v9 = 0;
      inList = false;
      if ( pushedCount > 0 )
      {
        LODWORD(v19) = list->pushedEnts;
        while ( 1 )
        {
          v10 = *(_DWORD *)LODWORD(v19);
          if ( *(_DWORD *)LODWORD(v19) == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
          }
          if ( pOtherEntity == m_pEntity )
            break;
          LODWORD(v19) += 4;
          if ( ++v9 >= pushedCount )
            goto LABEL_12;
        }
        inList = true;
      }
LABEL_12:
      p_normal = &normal;
      ((void (__thiscall *)(IPhysicsFrictionSnapshot *))v5->GetSurfaceNormal)(a1: v5);
      v19 = v5->GetNormalForce(this: v5);
      v12 = (float)((float)(pushVel->x * (float)(normal.x * v19)) + (float)((float)(v19 * normal.y) * pushVel->y))
          + (float)((float)(normal.z * v19) * pushVel->z);
      if ( pBlocker == nullptr || !inList && v12 > maxForce )
      {
        pBlocker = pOtherEntity;
        if ( !inList )
          maxForce = v12;
      }
      v5->NextFrictionData(this: v5);
    }
    while ( v5->IsValid(this: v5) );
    v4 = pPhysics;
  }
  v4->DestroyFrictionSnapshot(this: v4, a2: v5);
  return pBlocker;
}

//------------------------------------------------------------------------------
// Address: 0x100B50C0
// Name: public: void CBaseEntity::SetMoveDoneTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetMoveDoneTime(CBaseEntity *this, float flDelay)
{
  if ( flDelay < 0.0 )
    this->m_flMoveDoneTime = -1.0;
  else
    this->m_flMoveDoneTime = this->m_flLocalTime + flDelay;
  CBaseEntity::CheckHasGamePhysicsSimulation(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B5110
// Name: public: virtual int CBaseEntity::VPhysicsGetObjectList(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::VPhysicsGetObjectList(CBaseEntity *this, IPhysicsObject **pList, int listMax)
{
  IPhysicsObject *m_pPhysicsObject; // eax

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr || listMax <= 0 )
    return 0;
  *pList = m_pPhysicsObject;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B5140
// Name: public: virtual bool CBaseEntity::FVisible(class Vector const __near &,int,class CBaseEntity __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::FVisible(
        CBaseEntity *this,
        const Vector *vecTarget,
        unsigned int traceMask,
        CBaseEntity **ppBlocker)
{
  unsigned int v5; // edi
  CGameTrace tr; // [esp+4h] [ebp-74h] BYREF
  CTraceFilterLOS traceFilter; // [esp+58h] [ebp-20h] BYREF
  Vector vecLookerOrigin; // [esp+6Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+78h] [ebp+0h] BYREF

  this->EyePosition(this, result: &vecLookerOrigin);
  if ( ai_LOS_mode.m_pParent != nullptr && ai_LOS_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &vecLookerOrigin,
      vecAbsEnd: vecTarget,
      mask: traceMask,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
  }
  else
  {
    v5 = traceMask;
    if ( traceMask == 16449 )
      v5 = 33570881;
    if ( this->IsPlayer(this) )
      v5 = v5 & 0xFFFFDFBF | 0x2000;
    CTraceFilterLOS::CTraceFilterLOS(
      this: &traceFilter,
      pHandleEntity: this,
      collisionGroup: 0,
      pHandleEntity2: nullptr);
    UTIL_TraceLine(
      a1: (int)&savedregs,
      a2: (int)this,
      vecAbsStart: &vecLookerOrigin,
      vecAbsEnd: vecTarget,
      mask: v5,
      pFilter: &traceFilter,
      ptr: &tr);
  }
  if ( tr.fraction == 1.0 )
    return 1;
  if ( ppBlocker != nullptr )
    *ppBlocker = tr.m_pEnt;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B5210
// Name: public: virtual int CCollisionProperty::GetSolidFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetSolidFlags(CCollisionProperty *this)
{
  return this->m_usSolidFlags.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100B5220
// Name: private: bool CBaseEntity::NameMatchesComplex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::NameMatchesComplex(CBaseEntity *this, const char *pszNameOrWildcard)
{
  const char *pszValue; // eax

  if ( _V_stricmp(s1: "!player", s2: pszNameOrWildcard) == 0 )
    return this->IsPlayer(this);
  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
  {
    if ( *pszNameOrWildcard != 0 && *pszNameOrWildcard != 42 )
      return 0;
  }
  else if ( pszValue != pszNameOrWildcard )
  {
    return EntityNamesMatchCStrings(pszQuery: pszNameOrWildcard, pszNameToMatch: this->m_iName.m_Value.pszValue);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B5290
// Name: private: bool CBaseEntity::ClassMatchesComplex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::ClassMatchesComplex(CBaseEntity *this, const char *pszClassOrWildcard)
{
  const char *pszValue; // eax

  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
  {
    if ( *pszClassOrWildcard != 0 && *pszClassOrWildcard != 42 )
      return 0;
  }
  else if ( pszValue != pszClassOrWildcard )
  {
    return EntityNamesMatchCStrings(pszQuery: pszClassOrWildcard, pszNameToMatch: pszValue);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B52D0
// Name: public: int CBaseEntity::IsDormant(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::IsDormant(CBaseEntity *this)
{
  return (this->m_iEFlags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B52E0
// Name: public: virtual int CBaseEntity::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::Save(CBaseEntity *this, ISave *save)
{
  datamap_t *v3; // eax

  v3 = this->GetDataDescMap(this);
  return save->WriteAll(this: save, a2: this, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100B5300
// Name: public: virtual void CBaseEntity::OnParseMapDataFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::OnParseMapDataFinished(CBaseEntity *this)
{
  if ( this->m_bLagCompensate )
    lagcompensation->AddAdditionalEntity(this: lagcompensation, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100B5320
// Name: public: class CSkyCamera __near * CBaseEntity::GetEntitySkybox(void)
// Source: json
//------------------------------------------------------------------------------
CSkyCamera *__thiscall CBaseEntity::GetEntitySkybox(CBaseEntity *this)
{
  IVEngineServer_vtbl *v1; // esi
  const Vector *v2; // eax
  int v3; // edi
  CSkyCamera *SkyCameraList; // esi

  v1 = engine->__vftable;
  v2 = this->WorldSpaceCenter(this);
  v3 = v1->GetArea(this: engine, a2: v2);
  SkyCameraList = GetSkyCameraList();
  if ( SkyCameraList == nullptr )
    return nullptr;
  while ( engine->CheckAreasConnected(this: engine, a2: v3, a3: SkyCameraList->m_skyboxData.area.m_Value) == 0 )
  {
    SkyCameraList = SkyCameraList->m_pNext;
    if ( SkyCameraList == nullptr )
      return nullptr;
  }
  return SkyCameraList;
}

//------------------------------------------------------------------------------
// Address: 0x100B5380
// Name: public: char const __near * CBaseEntity::GetDebugName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::GetDebugName(CBaseEntity *this)
{
  const char *result; // eax
  CBaseEntity *v3; // ecx

  if ( this == nullptr )
    return "<<null>>";
  result = this->m_iName.m_Value.pszValue;
  if ( result == nullptr )
  {
    if ( this->IsPlayer(this) )
    {
      v3 = this->IsPlayer(this) ? this : nullptr;
      return v3->GetPlayerName(this: v3);
    }
    else
    {
      result = this->m_iClassname.pszValue;
      if ( result == nullptr )
        return locale;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B53E0
// Name: public: void CBaseEntity::DrawInputOverlay(char const __near *,class CBaseEntity __near *,class variant_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DrawInputOverlay(
        CBaseEntity *this,
        const char *szInputName,
        CBaseEntity *pCaller,
        variant_t Value)
{
  const char *DebugName; // eax
  int iVal; // ecx
  const char *v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  _fieldtypes fieldType; // ecx
  const char *v11; // eax
  const char *pszValue; // edi
  int v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // ebx
  const char *v17; // edi
  const char *v18; // esi
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // esi
  const char *v22; // eax
  const char *v23; // [esp+10h] [ebp-414h]
  const char *v24; // [esp+10h] [ebp-414h]
  char bigstring[1024]; // [esp+20h] [ebp-404h] BYREF
  CBaseEntity *v26; // [esp+420h] [ebp-4h]

  v26 = this;
  if ( Value.fieldType == FIELD_INTEGER )
  {
    if ( pCaller != nullptr )
    {
      DebugName = CBaseEntity::GetDebugName(this: pCaller);
      if ( Value.fieldType == FIELD_INTEGER )
        iVal = Value.iVal;
      else
        iVal = 0;
    }
    else
    {
      iVal = Value.iVal;
      DebugName = nullptr;
    }
    V_snprintf(
      pDest: bigstring,
      maxLen: 1024,
      pFormat: "%3.1f  (%s,%d) <-- (%s)\n",
      gpGlobals->curtime,
      szInputName,
      iVal,
      DebugName);
    goto LABEL_21;
  }
  if ( Value.fieldType == FIELD_STRING )
  {
    if ( pCaller != nullptr )
    {
      v7 = CBaseEntity::GetDebugName(this: pCaller);
      if ( Value.fieldType != FIELD_STRING )
      {
        v8 = variant_t::ToString(this: &Value);
LABEL_15:
        V_snprintf(
          pDest: bigstring,
          maxLen: 1024,
          pFormat: "%3.1f  (%s,%s) <-- (%s)\n",
          gpGlobals->curtime,
          szInputName,
          v8,
          v7);
        goto LABEL_21;
      }
    }
    else
    {
      v7 = nullptr;
    }
    v8 = (const char *)Value.iVal;
    if ( Value.iVal == 0 )
      v8 = locale;
    goto LABEL_15;
  }
  if ( pCaller != nullptr )
    v9 = CBaseEntity::GetDebugName(this: pCaller);
  else
    v9 = nullptr;
  V_snprintf(pDest: bigstring, maxLen: 1024, pFormat: "%3.1f  (%s) <-- (%s)\n", gpGlobals->curtime, szInputName, v9);
LABEL_21:
  CBaseEntity::AddTimedOverlay(this, msg: bigstring, endTime: 10);
  fieldType = Value.fieldType;
  if ( Value.fieldType == FIELD_INTEGER )
  {
    if ( pCaller != nullptr )
    {
      v11 = CBaseEntity::GetDebugName(this: pCaller);
      fieldType = Value.fieldType;
    }
    else
    {
      v11 = nullptr;
    }
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v23 = v11;
    v13 = fieldType != FIELD_INTEGER ? 0 : Value.iVal;
    v14 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "input: (%s,%d) -> (%s,%s), from (%s)\n", szInputName, v13, pszValue, v14, v23);
  }
  else if ( Value.fieldType == FIELD_STRING )
  {
    if ( pCaller != nullptr )
    {
      v15 = CBaseEntity::GetDebugName(this: pCaller);
      fieldType = Value.fieldType;
      v16 = v15;
    }
    else
    {
      v16 = nullptr;
    }
    v17 = v26->m_iClassname.pszValue;
    if ( v17 == nullptr )
      v17 = locale;
    if ( fieldType == FIELD_STRING )
    {
      v18 = (const char *)Value.iVal;
      if ( Value.iVal == 0 )
        v18 = locale;
    }
    else
    {
      v18 = variant_t::ToString(this: &Value);
    }
    v19 = CBaseEntity::GetDebugName(this: v26);
    _DevMsg(a1: 2, a2: "input: (%s,%s) -> (%s,%s), from (%s)\n", szInputName, v18, v17, v19, v16);
  }
  else
  {
    if ( pCaller != nullptr )
      v20 = CBaseEntity::GetDebugName(this: pCaller);
    else
      v20 = nullptr;
    v21 = this->m_iClassname.pszValue;
    if ( v21 == nullptr )
      v21 = locale;
    v24 = v20;
    v22 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "input: (%s) -> (%s,%s), from (%s)\n", szInputName, v21, v22, v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5610
// Name: public: void CBaseEntity::DrawOutputOverlay(class CEventAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DrawOutputOverlay(CBaseEntity *this, CEventAction *ev)
{
  float m_flDelay; // xmm0_4
  const char *pszValue; // eax
  const char *v5; // ecx
  const char *v6; // ecx
  float v7; // xmm0_4
  const char *v8; // eax
  const char *v9; // ecx
  const char *v10; // esi
  const char *v11; // eax
  const char *v12; // ecx
  const char *v13; // esi
  const char *DebugName; // eax
  const char *v15; // [esp+8h] [ebp-418h]
  const char *v16; // [esp+Ch] [ebp-414h]
  const char *v17; // [esp+10h] [ebp-410h]
  const char *v18; // [esp+14h] [ebp-40Ch]
  char bigstring[1024]; // [esp+20h] [ebp-400h] BYREF

  m_flDelay = ev->m_flDelay;
  pszValue = ev->m_iTarget.pszValue;
  if ( m_flDelay == 0.0 )
  {
    if ( pszValue == nullptr )
      pszValue = locale;
    v6 = ev->m_iTargetInput.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    V_snprintf(pDest: bigstring, maxLen: 1024, pFormat: "%3.1f  (%s) --> (%s)\n", gpGlobals->curtime, v6, pszValue);
  }
  else
  {
    if ( pszValue == nullptr )
      pszValue = locale;
    v5 = ev->m_iTargetInput.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    V_snprintf(
      pDest: bigstring,
      maxLen: 1024,
      pFormat: "%3.1f  (%s) --> (%s),%.1f) \n",
      gpGlobals->curtime,
      v5,
      pszValue,
      m_flDelay);
  }
  CBaseEntity::AddTimedOverlay(this, msg: bigstring, endTime: 10);
  v7 = ev->m_flDelay;
  v8 = ev->m_iTargetInput.pszValue;
  if ( v7 == 0.0 )
  {
    if ( v8 == nullptr )
      v8 = locale;
    v12 = ev->m_iTarget.pszValue;
    if ( ev->m_iTarget.pszValue == nullptr )
      v12 = locale;
    v13 = this->m_iClassname.pszValue;
    if ( v13 == nullptr )
      v13 = locale;
    v18 = v8;
    v17 = v12;
    DebugName = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "output: (%s,%s) -> (%s,%s)\n", v13, DebugName, v17, v18);
  }
  else
  {
    if ( v8 == nullptr )
      v8 = locale;
    v9 = ev->m_iTarget.pszValue;
    if ( ev->m_iTarget.pszValue == nullptr )
      v9 = locale;
    v10 = this->m_iClassname.pszValue;
    if ( v10 == nullptr )
      v10 = locale;
    v16 = v8;
    v15 = v9;
    v11 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "output: (%s,%s) -> (%s,%s,%.1f)\n", v10, v11, v15, v16, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5790
// Name: public: void CBaseEntity::InputSetDamageFilter(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputSetDamageFilter(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  const char *iVal; // eax
  CBaseEntity *EntityByName; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  iVal = (const char *)p_value->iVal;
  this->m_iszDamageFilterName.pszValue = iVal;
  if ( iVal != nullptr
    && (EntityByName = CGlobalEntityList::FindEntityByName(
                         this: &gEntList,
                         pStartEntity: nullptr,
                         szName: iVal,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr,
                         pFilter: nullptr)) != nullptr )
  {
    this->m_hDamageFilter.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  }
  else
  {
    this->m_hDamageFilter.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5800
// Name: public: class CTeam __near * CBaseEntity::GetTeam(void)const
// Source: json
//------------------------------------------------------------------------------
CTeam *__thiscall CBaseEntity::GetTeam(CBaseEntity *this)
{
  return GetGlobalTeam(iIndex: this->m_iTeamNum.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100B5810
// Name: public: bool CBaseEntity::InSameTeam(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::InSameTeam(CBaseEntity *this, CBaseEntity *pEntity)
{
  CTeam *GlobalTeam; // esi

  if ( pEntity == nullptr )
    return false;
  GlobalTeam = GetGlobalTeam(iIndex: pEntity->m_iTeamNum.m_Value);
  return GlobalTeam == GetGlobalTeam(iIndex: this->m_iTeamNum.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100B5850
// Name: public: char const __near * CBaseEntity::TeamID(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::TeamID(CBaseEntity *this)
{
  CTeam *GlobalTeam; // eax

  if ( GetGlobalTeam(iIndex: this->m_iTeamNum.m_Value) == nullptr )
    return locale;
  GlobalTeam = GetGlobalTeam(iIndex: this->m_iTeamNum.m_Value);
  return GlobalTeam->GetName(this: GlobalTeam);
}

//------------------------------------------------------------------------------
// Address: 0x100B5890
// Name: public: int CBaseEntity::GetTeamNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::GetTeamNumber(CBaseEntity *this)
{
  return this->m_iTeamNum.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100B58A0
// Name: class CStudioHdr __near * ModelSoundsCache_LoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__cdecl ModelSoundsCache_LoadModel(const char *filename)
{
  int v1; // eax
  const struct model_t *v2; // esi
  CStudioHdr *v3; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *result; // eax
  IMDLCache *v6; // [esp-8h] [ebp-Ch]

  v1 = engine->PrecacheModel(this: engine, a2: filename, a3: true);
  if ( v1 == -1 )
    return nullptr;
  v2 = modelinfo->GetModel(this: modelinfo, a2: v1);
  if ( v2 == nullptr )
    return nullptr;
  v3 = (CStudioHdr *)operator new(nSize: 0x64u);
  if ( v3 != nullptr )
  {
    v6 = mdlcache;
    v4 = modelinfo->GetStudiomodel(this: modelinfo, a2: v2);
    result = CStudioHdr::CStudioHdr(this: v3, pStudioHdr: v4, mdlcache: v6);
  }
  else
  {
    result = nullptr;
  }
  if ( result->m_pStudioHdr == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B5910
// Name: public: virtual void CBaseEntity::NetworkVar_m_Collision::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::NetworkVar_m_Collision::NetworkStateChanged(
        CBaseEntity::NetworkVar_m_Collision *this,
        void *pVar)
{
  char *v2; // eax
  CBaseEdict *v3; // ecx

  v2 = (char *)this - 228;
  if ( *((_BYTE *)this - 144) != 0 )
  {
    v2[88] |= 1u;
  }
  else
  {
    v3 = *((CBaseEdict **)v2 + 6);
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: v3, offset: (_WORD)pVar - (_WORD)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5940
// Name: public: struct HSCRIPT__ __near * CBaseEntity::ScriptGetModelKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseEntity::ScriptGetModelKeyValues(CBaseEntity *this)
{
  KeyValues *v2; // eax
  IVModelInfo_vtbl *v3; // edi
  int v4; // eax
  const struct model_t *v5; // eax
  const char *v6; // eax
  IVModelInfo_vtbl *v7; // ebx
  const char *v8; // edi
  int v9; // eax
  const struct model_t *v10; // eax
  const char *v11; // eax
  CScriptKeyValues *v12; // eax
  CScriptKeyValues *v13; // eax
  IScriptVM_vtbl *v14; // esi
  IScriptVM *v15; // edi
  ScriptClassDesc_t *Script; // eax
  CScriptKeyValues *v18; // [esp-4h] [ebp-10h]
  KeyValues *pModelKeyValues; // [esp+8h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    pModelKeyValues = KeyValues::KeyValues(this: v2, setName: locale);
  else
    pModelKeyValues = nullptr;
  v3 = modelinfo->__vftable;
  v4 = this->GetModelIndex(this);
  v5 = v3->GetModel(this: modelinfo, a2: v4);
  v6 = modelinfo->GetModelName(this: modelinfo, a2: v5);
  v7 = modelinfo->__vftable;
  v8 = v6;
  v9 = this->GetModelIndex(this);
  v10 = v7->GetModel(this: modelinfo, a2: v9);
  v11 = modelinfo->GetModelKeyValueText(this: modelinfo, a2: v10);
  if ( !KeyValues::LoadFromBuffer(
          this: pModelKeyValues,
          resourceName: v8,
          pBuffer: v11,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
    return nullptr;
  v12 = (CScriptKeyValues *)operator new(nSize: 4u);
  if ( v12 != nullptr )
    v13 = CScriptKeyValues::CScriptKeyValues(this: v12, pKeyValues: pModelKeyValues);
  else
    v13 = nullptr;
  this->m_pScriptModelKeyValues = v13;
  v14 = g_pScriptVM->__vftable;
  v18 = v13;
  v15 = g_pScriptVM;
  Script = GetScriptDesc<CScriptKeyValues>(__formal: v13);
  return v14->RegisterInstance(this: v15, a2: Script, a3: v18);
}

//------------------------------------------------------------------------------
// Address: 0x100B5A30
// Name: void ConsoleFireTargets(class CBasePlayer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConsoleFireTargets(CBasePlayer *pPlayer, const char *name)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // edi
  const char *DebugName; // eax

  if ( (name == locale || _V_stricmp(s1: name, s2: locale) == 0)
    && pPlayer != nullptr
    && (v2 = pPlayer->FindPickerEntity(this: pPlayer), v3 = v2, v2 != nullptr)
    && (v2->m_iEFlags & 1) == 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this: v2);
    _Msg(a1: "[%03d] Found: %s, firing\n", gpGlobals->tickcount % 1000, DebugName);
    ((void (__thiscall *)(CBaseEntity *, CBasePlayer *, CBasePlayer *, int, _DWORD))v3->Use)(
      a1: v3,
      a2: pPlayer,
      a3: pPlayer,
      a4: 3,
      a5: 0);
  }
  else
  {
    FireTargets(targetName: name, pActivator: pPlayer, pCaller: pPlayer, useType: USE_TOGGLE, value: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5AE0
// Name: void DumpScriptScope(class CBasePlayer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpScriptScope(CBasePlayer *pPlayer, const char *name)
{
  CBaseEntity *i; // esi
  const char *pszValue; // eax
  CBaseEntity *v4; // ecx
  HSCRIPT__ *v5; // eax
  HSCRIPT__ *v6; // ecx
  ScriptStatus_t (__thiscall *ExecuteFunction)(IScriptVM *, HSCRIPT__ *, ScriptVariant_t *, int, ScriptVariant_t *, HSCRIPT__ *, bool); // eax
  CBaseEntity *v8; // ecx
  HSCRIPT__ *v9; // [esp-20h] [ebp-34h]
  int v10; // [esp+4h] [ebp-10h] BYREF
  __int16 v11; // [esp+8h] [ebp-Ch]
  __int16 v12; // [esp+Ah] [ebp-Ah]
  HSCRIPT__ *v13; // [esp+Ch] [ebp-8h]
  __int16 v14; // [esp+10h] [ebp-4h]
  __int16 v15; // [esp+12h] [ebp-2h]

  for ( i = GetNextCommandEntity(pPlayer, name, ent: nullptr); i != nullptr; i = GetNextCommandEntity(
                                                                                   pPlayer,
                                                                                   name,
                                                                                   ent: i) )
  {
    pszValue = i->m_iName.m_Value.pszValue;
    if ( i->m_ScriptScope.m_hScope == (HSCRIPT__ *)-1 )
    {
      if ( pszValue == nullptr )
      {
        if ( i->IsPlayer(this: i) )
        {
          v8 = i->IsPlayer(this: i) ? i : nullptr;
          pszValue = v8->GetPlayerName(this: v8);
        }
        else
        {
          pszValue = i->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
        }
      }
      DevWarning(a1: "ent_script_dump: Entity %s has no script scope!\n", pszValue);
    }
    else
    {
      if ( pszValue == nullptr )
      {
        if ( i->IsPlayer(this: i) )
        {
          v4 = i->IsPlayer(this: i) ? i : nullptr;
          pszValue = v4->GetPlayerName(this: v4);
        }
        else
        {
          pszValue = i->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
        }
      }
      _Msg(a1: "----Script Dump for entity %s\n", pszValue);
      v5 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "__DumpScope", a3: 0);
      v6 = i->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? i->m_ScriptScope.m_hScope : nullptr;
      v12 = 0;
      v15 = 0;
      v11 = 5;
      v13 = v6;
      v14 = 33;
      v9 = v5;
      ExecuteFunction = g_pScriptVM->ExecuteFunction;
      v10 = 1;
      ExecuteFunction(this: g_pScriptVM, a2: v9, a3: (ScriptVariant_t *)&v10, a4: 2, a5: nullptr, a6: nullptr, a7: true);
      _Msg(a1: "----End Script Dump\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5C50
// Name: void CC_Ent_Script_Dump(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Script_Dump(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    DumpScriptScope(pPlayer: CommandClient, name: v3);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    DumpScriptScope(pPlayer: v1, name: locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5C90
// Name: public: class Vector const __near & CBaseEntity::ScriptGetAngles(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseEntity::ScriptGetAngles(CBaseEntity *this)
{
  float z; // edx

  if ( (`CBaseEntity::ScriptGetAngles'::`2'::`local static guard' & 1) == 0 )
    `CBaseEntity::ScriptGetAngles'::`2'::`local static guard' |= 1u;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  z = this->m_angAbsRotation.z;
  *(_QWORD *)&`CBaseEntity::ScriptGetAngles'::`2'::vec.x = *(_QWORD *)&this->m_angAbsRotation.x;
  `CBaseEntity::ScriptGetAngles'::`2'::vec.z = z;
  return &`CBaseEntity::ScriptGetAngles'::`2'::vec;
}

//------------------------------------------------------------------------------
// Address: 0x100B5D10
// Name: public: virtual void CBaseEntity::SetScriptOwnerEntity(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::SetScriptOwnerEntity(CBaseEntity *this@<ecx>, int a2@<esi>, HSCRIPT__ *hEntity)
{
  IScriptVM_vtbl *v4; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v6; // eax

  if ( hEntity != nullptr )
  {
    v4 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc(__formal: nullptr);
    v6 = (CBaseEntity *)((int (__thiscall *)(IScriptVM *, HSCRIPT__ *, ScriptClassDesc_t *, int))v4->GetInstanceValue)(
                          a1: g_pScriptVM,
                          a2: hEntity,
                          a3: ScriptDesc,
                          a4: a2);
    this->SetOwnerEntity(this, a2: v6);
  }
  else
  {
    this->SetOwnerEntity(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5D60
// Name: void CC_Ent_FireTarget(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_FireTarget(const CCommand *args)
{
  CBasePlayer *v1; // eax
  CBasePlayer *CommandClient; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  if ( args->m_nArgc > 1 )
  {
    v3 = args->m_ppArgv[1];
    CommandClient = UTIL_GetCommandClient();
    ConsoleFireTargets(pPlayer: CommandClient, name: v3);
  }
  else
  {
    v1 = UTIL_GetCommandClient();
    ConsoleFireTargets(pPlayer: v1, name: locale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5DA0
// Name: public: class CBaseEntity __near * CBaseEntity::FirstMoveChild(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::FirstMoveChild(CBaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100B5DD0
// Name: public: char const __near * CBaseEntity::GetPreTemplateName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseEntity::GetPreTemplateName(CBaseEntity *this)
{
  const char *pszValue; // eax
  char *v3; // eax
  const char *v4; // esi
  char *result; // eax
  const char *v6; // ecx
  int v7; // eax
  const char *v8; // ecx

  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v3 = _V_strrchr(s: pszValue, c: 38);
  v4 = this->m_iName.m_Value.pszValue;
  if ( v3 != nullptr )
  {
    v6 = v4;
    if ( v4 == nullptr )
      v6 = locale;
    if ( (unsigned int)(v3 - v6 + 1) <= 0x80 )
    {
      v8 = v4;
      if ( v4 == nullptr )
        v8 = locale;
      v7 = v3 - v8 + 1;
    }
    else
    {
      v7 = 128;
    }
    if ( v4 == nullptr )
      v4 = locale;
    V_strncpy(pDest: `CBaseEntity::GetPreTemplateName'::`4'::szStrippedName, pSrc: v4, maxLen: v7);
    return `CBaseEntity::GetPreTemplateName'::`4'::szStrippedName;
  }
  else
  {
    result = (char *)v4;
    if ( v4 == nullptr )
      return (char *)locale;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B5E50
// Name: UtlStringLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UtlStringLessFunc(CUtlString *lhs, CUtlString *rhs)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: rhs);
  v3 = CUtlString::operator char const *(this: lhs);
  return _V_stricmp(s1: v3, s2: v2) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B5E80
// Name: public: virtual void CEntFireAutoCompletionFunctor::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntFireAutoCompletionFunctor::CommandCallback(
        CEntFireAutoCompletionFunctor *this,
        const CCommand *command)
{
  CBasePlayer *CommandClient; // esi
  int v4; // ebx
  const char *v5; // esi
  const char *v6; // eax
  variant_t v7; // [esp-14h] [ebp-58h]
  float fireDelay; // [esp+0h] [ebp-44h]
  __int64 value_4; // [esp+20h] [ebp-24h]
  _fieldtypes value_16; // [esp+2Ch] [ebp-18h]
  char v11[4]; // [esp+30h] [ebp-14h] BYREF
  char v12[4]; // [esp+34h] [ebp-10h] BYREF
  char pszValue[4]; // [esp+38h] [ebp-Ch] BYREF
  int delay; // [esp+3Ch] [ebp-8h]
  CBaseEntity *pActivator; // [esp+40h] [ebp-4h]
  const char *target; // [esp+4Ch] [ebp+8h]

  CommandClient = UTIL_GetCommandClient();
  pActivator = CommandClient;
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    if ( command->m_nArgc >= 2 )
    {
      v4 = 0;
      v5 = "Use";
      value_16 = FIELD_VOID;
      delay = 0;
      target = *(const char **)AllocPooledString(pszValue).pszValue;
      if ( target == nullptr )
        target = locale;
      if ( gpGlobals->maxClients <= 1
        || _V_stricmp(s1: target, s2: "point_servercommand") != 0
        || !engine->IsDedicatedServer(this: engine) && pActivator == UTIL_GetListenServerHost() )
      {
        if ( command->m_nArgc >= 3 )
        {
          v5 = *(const char **)AllocPooledString(pszValue: v12).pszValue;
          if ( v5 == nullptr )
            v5 = locale;
        }
        if ( command->m_nArgc >= 4 )
        {
          v4 = *(_DWORD *)AllocPooledString(pszValue: v11).pszValue;
          value_16 = FIELD_STRING;
        }
        if ( command->m_nArgc >= 5 )
        {
          v6 = locale;
          if ( command->m_nArgc > 4 )
            v6 = command->m_ppArgv[4];
          delay = atoi(nptr: v6);
        }
        fireDelay = (float)delay;
        *(_QWORD *)(&v7.flVal + 1) = value_4;
        v7.iVal = v4;
        v7.eVal.m_Index = -1;
        v7.fieldType = value_16;
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target,
          targetInput: v5,
          Value: v7,
          fireDelay,
          pActivator,
          pCaller: pActivator,
          outputID: 0);
      }
    }
    else
    {
      ClientPrint(
        player: CommandClient,
        msg_dest: 2,
        msg_name: "Usage:\n   ent_fire <target> [action] [value] [delay]\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6030
// Name: void CC_Ent_CancelPendingEntFires(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_CancelPendingEntFires()
{
  CBasePlayer *CommandClient; // esi

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CommandClient = UTIL_GetCommandClient();
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
      CEventQueue::CancelEvents(this: &g_EventQueue, pCaller: CommandClient);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6070
// Name: void CC_Ent_Info(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CC_Ent_Info(int a1@<edi>, const CCommand *args)
{
  CBasePlayer *CommandClient; // ebx
  const char *v3; // eax
  CBaseEntity *EntityByName; // edi
  _DWORD *i; // esi
  int v6; // ebx
  int v7; // edi
  const char *v8; // eax
  datamap_t *j; // esi
  int v10; // ebx
  int v11; // edi
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  CBaseEntity *ent; // [esp+4h] [ebp-8h]
  CBasePlayer *player; // [esp+8h] [ebp-4h]

  CommandClient = UTIL_GetCommandClient();
  player = CommandClient;
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    if ( args->m_nArgc >= 2 )
    {
      v3 = locale;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      EntityByName = CreateEntityByName(className: v3, iForceEdictIndex: -1, bNotify: true);
      ent = EntityByName;
      if ( EntityByName != nullptr )
      {
        for ( i = (_DWORD *)((int (__thiscall *)(CBaseEntity *, int))EntityByName->GetDataDescMap)(
                              a1: EntityByName,
                              a2: a1); i != nullptr; i = (_DWORD *)i[3] )
        {
          v6 = 0;
          if ( (int)i[1] > 0 )
          {
            v7 = 0;
            do
            {
              if ( (*(_BYTE *)(*i + v7 + 14) & 0x10) != 0 )
              {
                v8 = UTIL_VarArgs(format: "  output: %s\n", *(const char **)(*i + v7 + 16));
                ClientPrint(
                  player,
                  msg_dest: 2,
                  msg_name: v8,
                  param1: nullptr,
                  param2: nullptr,
                  param3: nullptr,
                  param4: nullptr);
              }
              ++v6;
              v7 += 60;
            }
            while ( v6 < i[1] );
            EntityByName = ent;
          }
        }
        for ( j = EntityByName->GetDataDescMap(this: EntityByName); j != nullptr; j = j->baseMap )
        {
          v10 = 0;
          if ( j->dataNumFields > 0 )
          {
            v11 = 0;
            do
            {
              if ( (j->dataDesc[v11].flags & 8) != 0 )
              {
                v12 = UTIL_VarArgs(format: "  input: %s\n", j->dataDesc[v11].externalName);
                ClientPrint(
                  player,
                  msg_dest: 2,
                  msg_name: v12,
                  param1: nullptr,
                  param2: nullptr,
                  param3: nullptr,
                  param4: nullptr);
              }
              ++v10;
              ++v11;
            }
            while ( v10 < j->dataNumFields );
            EntityByName = ent;
          }
        }
        ((void (__thiscall *)(CBaseEntity *, int))EntityByName->dtr_IHandleEntity)(a1: EntityByName, a2: 1);
      }
      else
      {
        v13 = locale;
        if ( args->m_nArgc > 1 )
          v13 = args->m_ppArgv[1];
        v14 = UTIL_VarArgs(format: "no such entity %s\n", v13);
        ClientPrint(
          player: CommandClient,
          msg_dest: 2,
          msg_name: v14,
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
    else
    {
      ClientPrint(
        player: CommandClient,
        msg_dest: 2,
        msg_name: "Usage:\n   ent_info <class name>\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6200
// Name: public: void CBaseEntity::ComputeAbsPosition(class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ComputeAbsPosition(
        CBaseEntity *this,
        const Vector *vecLocalPosition,
        Vector *pAbsPosition)
{
  unsigned int m_Index; // ecx
  CBaseEntity **v4; // eax
  CBaseEntity *v5; // esi

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && (v4 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (v5 = *v4, *v4 != nullptr) )
  {
    if ( (v5->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v5);
    VectorTransform(in1: &vecLocalPosition->x, in2: &v5->m_rgflCoordinateFrame, out: &pAbsPosition->x);
  }
  else
  {
    *pAbsPosition = *vecLocalPosition;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6280
// Name: public: struct matrix3x4_t __near & CBaseEntity::GetParentToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__thiscall CBaseEntity::GetParentToWorldTransform(CBaseEntity *this, matrix3x4_t *tempMatrix)
{
  unsigned int m_Index; // ecx
  CBaseEntity **v4; // eax
  CBaseEntity *v5; // edi
  IMDLCache *v7; // esi
  int v8; // eax
  CBaseEntity *v9; // [esp+8h] [ebp-4h]

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  v9 = this;
  if ( m_Index == -1
    || (v4 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || (v5 = *v4, *v4 == nullptr) )
  {
    SetIdentityMatrix(matrix: tempMatrix);
    return tempMatrix;
  }
  if ( this->m_iParentAttachment.m_Value != 0 )
  {
    v7 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    v8 = (int)v5->GetBaseAnimating(this: v5);
    if ( v8 != 0
      && (*(unsigned __int8 (__thiscall **)(int, _DWORD, matrix3x4_t *))(*(_DWORD *)v8 + 856))(
           a1: v8,
           a2: v9->m_iParentAttachment.m_Value,
           a3: tempMatrix) != 0 )
    {
      v7->EndLock(this: v7);
      return tempMatrix;
    }
    v7->EndLock(this: v7);
  }
  if ( (v5->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v5);
  return &v5->m_rgflCoordinateFrame;
}

//------------------------------------------------------------------------------
// Address: 0x100B6360
// Name: public: void CBaseEntity::AddPoints(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddPoints(CBaseEntity *this, int score, bool bAllowNegativeScore)
{
  if ( this != nullptr && this->IsPlayer(this) )
    CBasePlayer::AddPoints((CBasePlayer *)this, score, bAllowNegativeScore);
}

//------------------------------------------------------------------------------
// Address: 0x100B6390
// Name: public: void CBaseEntity::AddPointsToTeam(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddPointsToTeam(CBaseEntity *this, int score, bool bAllowNegativeScore)
{
  if ( this != nullptr && this->IsPlayer(this) )
    CBasePlayer::AddPointsToTeam((CBasePlayer *)this, score, bAllowNegativeScore);
}

//------------------------------------------------------------------------------
// Address: 0x100B63C0
// Name: public: void CBaseEntity::ViewPunch(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ViewPunch(CBaseEntity *this, const QAngle *angleOffset)
{
  if ( this != nullptr && this->IsPlayer(this) )
    CBasePlayer::ViewPunch((CBasePlayer *)this, angleOffset);
}

//------------------------------------------------------------------------------
// Address: 0x100B63F0
// Name: public: struct HSCRIPT__ __near * CBaseEntity::GetScriptScope(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseEntity::GetScriptScope(CBaseEntity *this)
{
  return this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B6400
// Name: private: void CBaseEntity::ComputeStepSimulationNetwork(struct StepSimulationData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ComputeStepSimulationNetwork(CBaseEntity *this, float step)
{
  StepSimulationData *v2; // esi
  CAI_BaseNPC *v3; // ebx
  int tickcount; // eax
  bool v5; // zf
  Vector *v6; // eax
  float x; // xmm3_4
  float y; // xmm0_4
  float z; // xmm1_4
  int nTickCount; // ecx
  StepSimulationStep *p_m_Next; // edi
  int v12; // eax
  float t; // xmm2_4
  int v14; // eax
  int v15; // eax
  StepSimulationStep *p_m_Previous; // ebx
  int v17; // edx
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  CAI_BaseNPC *v21; // ecx
  float *p_x; // edi
  float v23; // xmm0_4
  float v24; // xmm1_4
  int m_cellwidth; // ebx
  int v26; // eax
  float *v27; // ecx
  int v28; // edi
  StepSimulationStep *p_m_Discontinuity; // ebx
  int v30; // eax
  float v31; // xmm1_4
  int v32; // edx
  int v33; // eax
  int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  Quaternion outangles; // [esp+1Ch] [ebp-2Ch] BYREF
  float v39; // [esp+2Ch] [ebp-1Ch] BYREF
  float v40; // [esp+30h] [ebp-18h] BYREF
  float v41; // [esp+34h] [ebp-14h]
  float minVal; // [esp+38h] [ebp-10h] BYREF
  float maxVal; // [esp+3Ch] [ebp-Ch] BYREF
  int v44; // [esp+40h] [ebp-8h]
  StepSimulationStep *pOlder; // [esp+44h] [ebp-4h]

  v2 = (StepSimulationData *)LODWORD(step);
  v3 = (CAI_BaseNPC *)this;
  pOlder = (StepSimulationStep *)this;
  if ( step == 0.0 )
    return;
  tickcount = gpGlobals->tickcount;
  if ( *(_DWORD *)(LODWORD(step) + 144) == tickcount )
    return;
  v5 = *(_BYTE *)LODWORD(step) == 0;
  *(_DWORD *)(LODWORD(step) + 144) = tickcount;
  if ( !v5 )
  {
    v6 = this->GetStepOrigin(this, result: &outangles.y);
    x = v2->m_Next.vecOrigin.x;
    v5 = x == v6->x;
    v41 = x;
    if ( !v5
      || (y = v2->m_Next.vecOrigin.y, v5 = y == v6->y, v40 = y, !v5)
      || (z = v2->m_Next.vecOrigin.z, v5 = z == v6->z, v39 = z, !v5) )
    {
      v2->m_bOriginActive = false;
      goto LABEL_25;
    }
    nTickCount = v2->m_Previous.nTickCount;
    p_m_Next = &v2->m_Next;
    v12 = v2->m_Next.nTickCount - nTickCount;
    t = 1.0;
    v44 = nTickCount;
    if ( v12 > 0 )
    {
      step = (float)(gpGlobals->tickcount - nTickCount) / (float)v12;
      maxVal = 1.0;
      minVal = 0.0;
      step = clamp<float,float,float>(val: &step, &minVal, &maxVal);
      t = step;
      x = v41;
      y = v40;
      z = v39;
      nTickCount = v44;
    }
    v14 = v2->m_Previous2.nTickCount;
    if ( v14 != 0 && v14 < nTickCount )
    {
      if ( step_spline.m_pParent == nullptr || step_spline.m_pParent->m_Value.m_nValue == 0 )
      {
        v15 = v2->m_Discontinuity.nTickCount;
        p_m_Previous = &v2->m_Previous;
        if ( v15 > v44 )
        {
          v17 = gpGlobals->tickcount;
          if ( v17 <= v15 )
            p_m_Next = &v2->m_Discontinuity;
          else
            p_m_Previous = &v2->m_Discontinuity;
          if ( p_m_Next->nTickCount - p_m_Previous->nTickCount > 0 )
          {
            step = (float)(v17 - p_m_Previous->nTickCount) / (float)(p_m_Next->nTickCount - p_m_Previous->nTickCount);
            v39 = 1.0;
            v40 = 0.0;
            step = clamp<float,float,float>(val: &step, minVal: &v40, maxVal: &v39);
            t = step;
          }
        }
        v18 = p_m_Next->vecOrigin.x;
        v19 = p_m_Next->vecOrigin.y - p_m_Previous->vecOrigin.y;
        v20 = p_m_Next->vecOrigin.z - p_m_Previous->vecOrigin.z;
        v21 = (CAI_BaseNPC *)pOlder;
        p_x = &v2->m_vecNetworkOrigin.x;
        v2->m_vecNetworkOrigin.x = (float)((float)(v18 - p_m_Previous->vecOrigin.x) * t) + p_m_Previous->vecOrigin.x;
        v2->m_vecNetworkOrigin.y = (float)(v19 * t) + p_m_Previous->vecOrigin.y;
        v2->m_vecNetworkOrigin.z = (float)(v20 * t) + p_m_Previous->vecOrigin.z;
        CHostage::NetworkStateChanged_m_iMaxHealth(this: v21);
        v3 = (CAI_BaseNPC *)pOlder;
        goto LABEL_24;
      }
      p_x = &v2->m_vecNetworkOrigin.x;
      Hermite_Spline(
        p0: &v2->m_Previous2.vecOrigin,
        p1: &v2->m_Previous.vecOrigin,
        p2: &v2->m_Next.vecOrigin,
        t,
        output: &v2->m_vecNetworkOrigin);
    }
    else
    {
      v23 = y - v2->m_Previous.vecOrigin.y;
      v24 = z - v2->m_Previous.vecOrigin.z;
      p_x = &v2->m_vecNetworkOrigin.x;
      v2->m_vecNetworkOrigin.x = (float)((float)(x - v2->m_Previous.vecOrigin.x) * t) + v2->m_Previous.vecOrigin.x;
      v2->m_vecNetworkOrigin.y = (float)(v23 * t) + v2->m_Previous.vecOrigin.y;
      v2->m_vecNetworkOrigin.z = (float)(v24 * t) + v2->m_Previous.vecOrigin.z;
    }
    CHostage::NetworkStateChanged_m_iMaxHealth(this: v3);
LABEL_24:
    m_cellwidth = v3->m_cellwidth;
    v2->m_networkCell[0] = CellFromCoord(cellwidth: m_cellwidth, f: *p_x);
    v2->m_networkCell[1] = CellFromCoord(cellwidth: m_cellwidth, f: v2->m_vecNetworkOrigin.y);
    v26 = CellFromCoord(cellwidth: m_cellwidth, f: v2->m_vecNetworkOrigin.z);
    v3 = (CAI_BaseNPC *)pOlder;
    v2->m_networkCell[2] = v26;
  }
LABEL_25:
  if ( !v2->m_bAnglesActive )
    return;
  v27 = (float *)v3->GetStepAngles(this: v3, result: (QAngle *)&outangles.y);
  if ( v2->m_angNextRotation.x != *v27 || v2->m_angNextRotation.y != v27[1] || v2->m_angNextRotation.z != v27[2] )
  {
    v2->m_bAnglesActive = false;
    return;
  }
  v28 = v2->m_Previous.nTickCount;
  p_m_Discontinuity = &v2->m_Next;
  v30 = v2->m_Next.nTickCount - v28;
  v31 = 1.0;
  if ( v30 > 0 )
  {
    v32 = gpGlobals->tickcount - v28;
    v39 = 1.0;
    step = (float)v32 / (float)v30;
    v40 = 0.0;
    step = clamp<float,float,float>(val: &step, minVal: &v40, maxVal: &v39);
    v31 = step;
  }
  v33 = v2->m_Previous2.nTickCount;
  if ( v33 != 0 && v33 < v28 )
  {
    if ( step_spline.m_pParent != nullptr && step_spline.m_pParent->m_Value.m_nValue != 0 )
    {
      Hermite_Spline(
        q0: &v2->m_Previous2.qRotation,
        q1: &v2->m_Previous.qRotation,
        q2: &v2->m_Next.qRotation,
        t: v31,
        output: &outangles);
      QuaternionAngles(q: &outangles, angles: &v2->m_angNetworkAngles);
      return;
    }
    pOlder = &v2->m_Previous;
    v34 = v2->m_Discontinuity.nTickCount;
    if ( v34 > v28 )
    {
      v35 = gpGlobals->tickcount;
      if ( v35 <= v34 )
        p_m_Discontinuity = &v2->m_Discontinuity;
      else
        pOlder = &v2->m_Discontinuity;
      v36 = pOlder->nTickCount;
      v37 = p_m_Discontinuity->nTickCount - pOlder->nTickCount;
      if ( v37 > 0 )
      {
        v39 = 1.0;
        step = (float)(v35 - v36) / (float)v37;
        v40 = 0.0;
        step = clamp<float,float,float>(val: &step, minVal: &v40, maxVal: &v39);
        v31 = step;
      }
    }
    QuaternionBlend(p: &pOlder->qRotation, q: &p_m_Discontinuity->qRotation, t: v31, qt: &outangles);
  }
  else
  {
    QuaternionBlend(p: &v2->m_Previous.qRotation, q: &v2->m_Next.qRotation, t: v31, qt: &outangles);
  }
  QuaternionAngles(q: &outangles, angles: &v2->m_angNetworkAngles);
}

//------------------------------------------------------------------------------
// Address: 0x100B68B0
// Name: public: bool CBaseEntity::UseStepSimulationNetworkOrigin(class Vector const __near * __near *,int __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::UseStepSimulationNetworkOrigin(CBaseEntity *this, const Vector **out_v, int *cell)
{
  char *DataObject; // esi

  if ( !g_bTestMoveTypeStepSimulation || this->m_MoveType.m_Value != 3 || !CBaseEntity::HasDataObjectType(this, type: 2) )
    return false;
  DataObject = (char *)CBaseEntity::GetDataObject(this, type: 2);
  CBaseEntity::ComputeStepSimulationNetwork(this, step: *(float *)&DataObject);
  *out_v = (const Vector *)(DataObject + 148);
  if ( cell != nullptr )
  {
    *cell = *((_DWORD *)DataObject + 40);
    cell[1] = *((_DWORD *)DataObject + 41);
    cell[2] = *((_DWORD *)DataObject + 42);
  }
  return *DataObject;
}

//------------------------------------------------------------------------------
// Address: 0x100B6930
// Name: public: bool CBaseEntity::AddStepDiscontinuity(float,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::AddStepDiscontinuity(
        CBaseEntity *this,
        float flTime,
        const Vector *vecOrigin,
        const QAngle *vecAngles)
{
  char *DataObject; // eax

  if ( this->m_MoveType.m_Value != 3 )
    return 0;
  if ( !CBaseEntity::HasDataObjectType(this, type: 2) )
    return 0;
  DataObject = (char *)CBaseEntity::GetDataObject(this, type: 2);
  if ( DataObject == nullptr )
    return 0;
  *((_DWORD *)DataObject + 17) = (int)(float)((float)(flTime / gpGlobals->interval_per_tick) + 0.5);
  *((Vector *)DataObject + 6) = *vecOrigin;
  AngleQuaternion(angles: vecAngles, outQuat: (Quaternion *)(DataObject + 84));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B69B0
// Name: private: virtual class Vector CBaseEntity::GetStepOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseEntity::GetStepOrigin(CBaseEntity *this, Vector *result)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
  z = this->m_vecOrigin.m_Value.z;
  *(_QWORD *)&result->x = v2;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B69D0
// Name: public: virtual void CBaseEntity::SetRefEHandle(class CBaseHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetRefEHandle(CBaseEntity *this, const CBaseHandle *handle)
{
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx

  m_Index = handle->m_Index;
  this->m_RefEHandle = (CBaseHandle)handle->m_Index;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev->m_NetworkSerialNumber = HIWORD(m_Index) & 0x3FF;
}

//------------------------------------------------------------------------------
// Address: 0x100B6A00
// Name: public: virtual bool CBaseEntity::SUB_AllowedToFade(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::SUB_AllowedToFade(CBaseEntity *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  bool result; // al
  CBasePlayer *LocalPlayer; // eax

  m_pPhysicsObject = this->m_pPhysicsObject;
  result = false;
  if ( m_pPhysicsObject == nullptr
    || (((int (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetGameFlags)(a1: m_pPhysicsObject) & 4) == 0
    && (this->m_iEFlags & 0x100000) == 0 )
  {
    if ( gpGlobals->maxClients != 1 )
      return true;
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer == nullptr || !LocalPlayer->FInViewCone(this: LocalPlayer, a2: this) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6A60
// Name: public: struct HSCRIPT__ __near * CBaseEntity::GetScriptInstance(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
HSCRIPT__ *__thiscall CBaseEntity::GetScriptInstance(CBaseEntity *this)
{
  void *v2; // esp
  const char *v3; // eax
  IScriptVM_vtbl *v4; // edi
  int v5; // eax
  HSCRIPT__ *v6; // eax
  const char *v7; // edx
  _DWORD v9[258]; // [esp-400h] [ebp-40Ch] BYREF
  char pszValue[4]; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_hScriptInstance == nullptr )
  {
    if ( this->m_iszScriptId.pszValue == nullptr )
    {
      v2 = alloca(1024);
      v3 = this->m_iName.m_Value.pszValue;
      if ( v3 == nullptr )
      {
        v3 = this->m_iClassname.pszValue;
        if ( v3 == nullptr )
          v3 = locale;
      }
      g_pScriptVM->GenerateUniqueKey(this: g_pScriptVM, a2: v3, a3: (char *)v9, a4: 1024);
      v9[255] = v9;
      this->m_iszScriptId.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
    }
    v4 = g_pScriptVM->__vftable;
    v5 = ((int (__thiscall *)(CBaseEntity *, CBaseEntity *))this->GetScriptDesc)(a1: this, a2: this);
    v6 = (HSCRIPT__ *)((int (__thiscall *)(IScriptVM *, int))v4->RegisterInstance)(a1: g_pScriptVM, a2: v5);
    this->m_hScriptInstance = v6;
    v7 = this->m_iszScriptId.pszValue;
    if ( v7 == nullptr )
      v7 = locale;
    g_pScriptVM->SetInstanceUniqeId(this: g_pScriptVM, a2: v6, a3: v7);
  }
  return this->m_hScriptInstance;
}

//------------------------------------------------------------------------------
// Address: 0x100B6B20
// Name: public: bool CBaseEntity::ValidateScriptScope(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::ValidateScriptScope(CBaseEntity *this)
{
  const char *pszValue; // eax
  HSCRIPT__ *v4; // eax
  const char *DebugName; // eax
  HSCRIPT__ *ScriptInstance; // eax
  HSCRIPT__ *m_hScope; // esi
  _DWORD v8[2]; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 )
    return 1;
  if ( scriptmanager == nullptr )
  {
    if ( _executeCount_1 < 1 )
    {
      ++_executeCount_1;
      DevMsg(a1: "Cannot execute script because scripting is disabled (-scripting)\n");
    }
    return 0;
  }
  if ( g_pScriptVM != nullptr )
  {
    CBaseEntity::GetScriptInstance(this);
    this->GetRefEHandle(this);
    pszValue = this->m_iszScriptId.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v4 = g_pScriptVM->CreateScope(this: g_pScriptVM, a2: pszValue, a3: 0);
    this->m_ScriptScope.m_hScope = v4;
    if ( v4 == nullptr )
    {
      DebugName = CBaseEntity::GetDebugName(this);
      DevMsg(a1: "%s couldn't create ScriptScope!\n", DebugName);
      return 0;
    }
    ScriptInstance = CBaseEntity::GetScriptInstance(this);
    m_hScope = this->m_ScriptScope.m_hScope;
    v8[0] = ScriptInstance;
    v8[1] = 33;
    g_pScriptVM->SetValue(
      this: g_pScriptVM,
      a2: (HSCRIPT__ *)((char *)m_hScope + 1) != nullptr ? m_hScope : nullptr,
      a3: "self",
      a4: (const ScriptVariant_t *)v8);
    return 1;
  }
  if ( _executeCount_0 >= 1 )
    return 0;
  ++_executeCount_0;
  DevMsg(a1: " Cannot execute script because there is no available VM\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B6C30
// Name: public: void CBaseEntity::RunPrecacheScripts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RunPrecacheScripts(CBaseEntity *this)
{
  HSCRIPT__ *v2; // esi

  if ( this->m_iszVScripts.pszValue != nullptr )
  {
    v2 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "DispatchPrecache", a3: this->m_ScriptScope.m_hScope);
    if ( v2 != nullptr )
    {
      g_pScriptVM->ExecuteFunction(
        this: g_pScriptVM,
        a2: v2,
        a3: nullptr,
        a4: 0,
        a5: nullptr,
        a6: this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr,
        a7: true);
      g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6CA0
// Name: public: void CBaseEntity::RunOnPostSpawnScripts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RunOnPostSpawnScripts(CBaseEntity *this)
{
  HSCRIPT__ *v2; // edi
  ScriptStatus_t (__thiscall *ExecuteFunction)(IScriptVM *, HSCRIPT__ *, ScriptVariant_t *, int, ScriptVariant_t *, HSCRIPT__ *, bool); // eax
  HSCRIPT__ *v4; // edi
  variant_t v5; // [esp+18h] [ebp-48h]
  __int64 variant_4; // [esp+48h] [ebp-18h]
  _DWORD v7[2]; // [esp+58h] [ebp-8h] BYREF

  if ( this->m_iszVScripts.pszValue != nullptr )
  {
    v2 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "ConnectOutputs", a3: 0);
    if ( v2 != nullptr )
    {
      v7[0] = this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr;
      ExecuteFunction = g_pScriptVM->ExecuteFunction;
      v7[1] = 33;
      ExecuteFunction(this: g_pScriptVM, a2: v2, a3: (ScriptVariant_t *)v7, a4: 1, a5: nullptr, a6: nullptr, a7: true);
      g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v2);
    }
    v4 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "DispatchOnPostSpawn", a3: this->m_ScriptScope.m_hScope);
    if ( v4 != nullptr )
    {
      *(_QWORD *)(&v5.flVal + 1) = variant_4;
      v5.iVal = (int)"DispatchOnPostSpawn";
      *(_QWORD *)&v5.eVal.m_Index = 0x2FFFFFFFFLL;
      CEventQueue::AddEvent(
        this: &g_EventQueue,
        target: this,
        targetInput: "CallScriptFunction",
        Value: v5,
        fireDelay: 0.0,
        pActivator: this,
        pCaller: this,
        outputID: 0);
      g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6DA0
// Name: bool AnyPlayersInHierarchy_R(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AnyPlayersInHierarchy_R(CBaseEntity *pEnt)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  unsigned int v4; // eax
  IHandleEntity *v5; // eax

  if ( pEnt->IsPlayer(this: pEnt) )
    return 1;
  m_Index = pEnt->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    while ( !AnyPlayersInHierarchy_R(pEnt: m_pEntity) )
    {
      v4 = m_pEntity->m_hMovePeer.m_Index;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        v5 = nullptr;
      else
        v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      m_pEntity = (CBaseEntity *)v5;
      if ( v5 == nullptr )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B6E40
// Name: void CC_Ent_Create(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CC_Ent_Create(int a1@<esi>, const CCommand *args)
{
  IMDLCache *v2; // ebx
  const char *v3; // eax
  CBaseEntity *EntityByName; // edi
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v7; // eax
  Vector *(__thiscall *v8)(CBaseEntity *, Vector *); // edx
  const Vector *v9; // eax
  void (__thiscall *Teleport)(CBaseEntity *, const Vector *, const QAngle *, const Vector *, bool); // edx
  CGameTrace tr; // [esp+8h] [ebp-94h] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-40h] BYREF
  Vector v13; // [esp+68h] [ebp-34h] BYREF
  Vector forward; // [esp+74h] [ebp-28h] BYREF
  unsigned int mask[3]; // [esp+80h] [ebp-1Ch] BYREF
  float v16; // [esp+8Ch] [ebp-10h]
  float v17; // [esp+90h] [ebp-Ch]
  float v18; // [esp+94h] [ebp-8h]
  BOOL allowPrecache; // [esp+98h] [ebp-4h]
  IHandleEntity savedregs; // [esp+9Ch] [ebp+0h] BYREF

  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  LOBYTE(allowPrecache) = CBaseEntity::IsPrecacheAllowed();
  CBaseEntity::SetAllowPrecache(allow: true);
  if ( args->m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  else
    v3 = locale;
  EntityByName = CreateEntityByName(className: v3, iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName != nullptr )
  {
    if ( EntityByName->IsPlayer(this: EntityByName) )
    {
      _Warning(a1: "Cannot ent_create players!\n");
      UTIL_Remove(oldObj: EntityByName);
    }
    else
    {
      ((void (__thiscall *)(CBaseEntity *, int))EntityByName->Precache)(a1: EntityByName, a2: a1);
      DispatchSpawn(pEntity: EntityByName, bRunVScripts: true);
      CommandClient = UTIL_GetCommandClient();
      CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
      EyePosition = CommandClient->EyePosition;
      v16 = forward.x * 56755.84;
      v17 = forward.y * 56755.84;
      v18 = forward.z * 56755.84;
      v7 = (float *)EyePosition(this: CommandClient, result: &v13);
      v8 = CommandClient->EyePosition;
      *(float *)mask = *v7 + v16;
      *(float *)&mask[1] = v7[1] + v17;
      *(float *)&mask[2] = v7[2] + v18;
      v9 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v8)(a1: CommandClient);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)CommandClient,
        vecAbsStart: v9,
        &vecAbsEnd,
        (unsigned int)mask,
        ignore: (const IHandleEntity *)0x200400B,
        collisionGroup: (int)CommandClient,
        ptr: nullptr);
      if ( tr.fraction != 1.0 )
      {
        Teleport = EntityByName->Teleport;
        tr.endpos.z = tr.endpos.z + 12.0;
        Teleport(this: EntityByName, a2: &tr.endpos, a3: nullptr, a4: nullptr, a5: true);
        UTIL_DropToFloor(pEntity: EntityByName, mask: 0x200400Bu, pIgnore: nullptr);
      }
    }
  }
  CBaseEntity::SetAllowPrecache(allow: allowPrecache);
  v2->EndLock(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100B6FF0
// Name: bool CC_GetCommandEnt(class CCommand const __near &,class CBaseEntity __near * __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CC_GetCommandEnt(const CCommand *args, CBaseEntity **ent, Vector *vecTargetPoint, QAngle *vecPlayerAngle)
{
  const char *v4; // eax
  int v5; // eax
  CBaseEntity *EntityByClassname; // eax
  const char *v7; // eax
  CBaseEntity *EntityByName; // eax
  const char *v9; // eax
  const char *v10; // edi
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v14; // eax
  Vector *(__thiscall *v15)(CBaseEntity *, Vector *); // edx
  const Vector *v16; // eax
  Vector tr_12; // [esp+14h] [ebp-84h]
  float tr_44; // [esp+34h] [ebp-64h]
  Vector vecAbsEnd; // [esp+5Ch] [ebp-3Ch] BYREF
  Vector v20; // [esp+68h] [ebp-30h] BYREF
  Vector forward; // [esp+74h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+80h] [ebp-18h] BYREF
  float v23; // [esp+8Ch] [ebp-Ch]
  float v24; // [esp+90h] [ebp-8h]
  float v25; // [esp+94h] [ebp-4h]
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  *ent = nullptr;
  v4 = locale;
  if ( args->m_nArgc > 1 )
    v4 = args->m_ppArgv[1];
  v5 = atoi(nptr: v4);
  if ( v5 != 0 )
  {
    EntityByClassname = CBaseEntity::Instance(iEnt: v5);
  }
  else
  {
    v7 = locale;
    if ( args->m_nArgc > 1 )
      v7 = args->m_ppArgv[1];
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: v7,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    *ent = EntityByName;
    if ( EntityByName != nullptr )
      goto LABEL_16;
    v9 = locale;
    if ( args->m_nArgc > 1 )
      v9 = args->m_ppArgv[1];
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: v9);
  }
  *ent = EntityByClassname;
  if ( EntityByClassname == nullptr )
  {
    if ( args->m_nArgc > 1 )
      v10 = args->m_ppArgv[1];
    else
      v10 = locale;
    _Msg(a1: "Couldn't find any entity named '%s'\n", v10);
    return 0;
  }
LABEL_16:
  CommandClient = UTIL_GetCommandClient();
  if ( vecTargetPoint != nullptr )
  {
    CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
    EyePosition = CommandClient->EyePosition;
    v23 = forward.x * 56755.84;
    v24 = forward.y * 56755.84;
    v25 = forward.z * 56755.84;
    v14 = (float *)EyePosition(this: CommandClient, result: &v20);
    v15 = CommandClient->EyePosition;
    *(float *)mask = *v14 + v23;
    *(float *)&mask[1] = v14[1] + v24;
    *(float *)&mask[2] = v14[2] + v25;
    v16 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v15)(a1: CommandClient);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)CommandClient,
      vecAbsStart: v16,
      &vecAbsEnd,
      (unsigned int)mask,
      ignore: (const IHandleEntity *)0x202400B,
      collisionGroup: (int)CommandClient,
      ptr: nullptr);
    if ( tr_44 != 1.0 )
      *vecTargetPoint = tr_12;
  }
  if ( vecPlayerAngle != nullptr )
    *vecPlayerAngle = *CommandClient->EyeAngles(this: CommandClient);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B71C0
// Name: void CC_Ent_Teleport(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Teleport(CBaseEntity *args)
{
  Vector vecTargetPoint; // [esp+0h] [ebp-Ch] BYREF

  if ( (int)args->__vftable >= 2 )
  {
    if ( CC_GetCommandEnt((const CCommand *)args, ent: &args, &vecTargetPoint, vecPlayerAngle: nullptr) != 0 )
      args->Teleport(this: args, a2: &vecTargetPoint, a3: nullptr, a4: nullptr, a5: true);
  }
  else
  {
    _Msg(a1: "Format: ent_teleport <entity name>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B72E0
// Name: public: static bool CMemberScriptBinding2<class CBaseEntity __near *,void (CBaseEntity::*)(char const __near *,char const __near *),void,char const __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *,char const *),void,char const *,char const *>::Call(
        void (__stdcall *pFunction)(const char *, const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // eax
  const char *m_int; // edx

  if ( nArguments != 2 || pReturn != nullptr || pContext == nullptr )
    return 0;
  m_pszString = pArguments[1].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pFunction(a1: m_int, a2: m_pszString);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7320
// Name: public: static bool CMemberScriptBinding0<class CBaseEntity __near *,char const __near * (CBaseEntity::*)(void),char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<CBaseEntity *,char const * (__thiscall CBaseEntity::*)(void),char const *>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 32;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7350
// Name: public: static bool CMemberScriptBinding2<class CBaseEntity __near *,float (CBaseEntity::*)(char const __near *,char const __near *),float,char const __near *,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CBaseEntity *,float (__thiscall CBaseEntity::*)(char const *,char const *),float,char const *,char const *>::Call(
        double (__stdcall *pFunction)(const char *, const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_pszString; // eax
  const char *m_int; // edx

  if ( nArguments != 2 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_pszString = pArguments[1].m_pszString;
  if ( m_pszString == nullptr )
    m_pszString = locale;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_float = pFunction(a1: m_int, a2: m_pszString);
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7430
// Name: public: static bool CMemberScriptBinding3<class CBaseEntity __near *,void (CBaseEntity::*)(float,float,float),void,float,float,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding3<CBaseEntity *,void (__thiscall CBaseEntity::*)(float,float,float),void,float,float,float>::Call(
        void (__stdcall *pFunction)(int, int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 3 || pReturn != nullptr || pContext == nullptr )
    return 0;
  pFunction(a1: pArguments->m_int, a2: pArguments[1].m_int, a3: pArguments[2].m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7510
// Name: public: static bool CMemberScriptBinding2<class CBaseEntity __near *,bool (CBaseEntity::*)(char const __near *,float),bool,char const __near *,float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CBaseEntity *,bool (__thiscall CBaseEntity::*)(char const *,float),bool,char const *,float>::Call(
        int (__stdcall *pFunction)(const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 2 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_char = pFunction(a1: m_int, a2: pArguments[1].m_int);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7560
// Name: public: static bool CMemberScriptBinding2<class CBaseEntity __near *,bool (CBaseEntity::*)(char const __near *,int),bool,char const __near *,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CBaseEntity *,bool (__thiscall CBaseEntity::*)(char const *,int),bool,char const *,int>::Call(
        int (__stdcall *pFunction)(const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 2 || pReturn == nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pReturn->m_char = pFunction(a1: m_int, a2: pArguments[1].m_int);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7880
// Name: public: int CBasePlayer::GetUserID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetUserID(CBasePlayer *this)
{
  return engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
}

//------------------------------------------------------------------------------
// Address: 0x100B78A0
// Name: void __near * SendProxy_ClientSideAnimation(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_ClientSideAnimation(const SendProp *pProp, const void *pStruct, const void *pVarData)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(const void *))(*(_DWORD *)pStruct + 212))(a1: pStruct);
  if ( v3 == 0 || *(_BYTE *)(v3 + 1060) != 0 )
    return nullptr;
  else
    return (void *)pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x100B7950
// Name: void SendProxy_Origin(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Origin(const SendProp *pProp, _BYTE *pStruct, const void *pData, DVariant *pOut)
{
  _BYTE *DataObject; // esi
  $5FB8512C96CD1B8867E59BA5A9F6C5D6 *v5; // eax

  if ( !g_bTestMoveTypeStepSimulation
    || pStruct[214] != 3
    || !CBaseEntity::HasDataObjectType(this: (CBaseEntity *)pStruct, type: 2)
    || (DataObject = CBaseEntity::GetDataObject(this: (CBaseEntity *)pStruct, type: 2),
        CBaseEntity::ComputeStepSimulationNetwork(this: (CBaseEntity *)pStruct, step: *(float *)&DataObject),
        v5 = ($5FB8512C96CD1B8867E59BA5A9F6C5D6 *)(DataObject + 148),
        *DataObject == 0) )
  {
    v5 = ($5FB8512C96CD1B8867E59BA5A9F6C5D6 *)(pStruct + 700);
  }
  pOut->___u0 = *v5;
}

//------------------------------------------------------------------------------
// Address: 0x100B79C0
// Name: void SendProxy_OriginXY(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_OriginXY(const SendProp *pProp, _BYTE *pStruct, const void *pData, DVariant *pOut)
{
  _BYTE *DataObject; // esi
  __int64 *v5; // eax

  if ( !g_bTestMoveTypeStepSimulation
    || pStruct[214] != 3
    || !CBaseEntity::HasDataObjectType(this: (CBaseEntity *)pStruct, type: 2)
    || (DataObject = CBaseEntity::GetDataObject(this: (CBaseEntity *)pStruct, type: 2),
        CBaseEntity::ComputeStepSimulationNetwork(this: (CBaseEntity *)pStruct, step: *(float *)&DataObject),
        v5 = (__int64 *)(DataObject + 148),
        *DataObject == 0) )
  {
    v5 = (__int64 *)(pStruct + 700);
  }
  pOut->m_Int64 = *v5;
}

//------------------------------------------------------------------------------
// Address: 0x100B7A20
// Name: void SendProxy_OriginZ(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_OriginZ(const SendProp *pProp, CBaseEntity *pStruct, const void *pData, DVariant *pOut)
{
  float *DataObject; // esi

  if ( g_bTestMoveTypeStepSimulation
    && pStruct->m_MoveType.m_Value == 3
    && CBaseEntity::HasDataObjectType(this: pStruct, type: 2)
    && (DataObject = (float *)CBaseEntity::GetDataObject(this: pStruct, type: 2),
        CBaseEntity::ComputeStepSimulationNetwork(this: pStruct, step: *(float *)&DataObject),
        *(_BYTE *)DataObject != 0) )
  {
    pOut->m_Float = DataObject[39];
  }
  else
  {
    pOut->m_Float = pStruct->m_vecOrigin.m_Value.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7A80
// Name: public: static void CBaseEntity::SendProxy_CellX(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SendProxy_CellX(const SendProp *pProp, CBaseEntity *pStruct, int *pData, DVariant *pOut)
{
  int cell[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( CBaseEntity::UseStepSimulationNetworkOrigin(this: pStruct, out_v: (const Vector **)&pStruct, cell) )
    pOut->m_Int = cell[0];
  else
    pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x100B7AC0
// Name: public: static void CBaseEntity::SendProxy_CellY(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SendProxy_CellY(const SendProp *pProp, CBaseEntity *pStruct, int *pData, DVariant *pOut)
{
  int cell[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( CBaseEntity::UseStepSimulationNetworkOrigin(this: pStruct, out_v: (const Vector **)&pStruct, cell) )
    pOut->m_Int = cell[1];
  else
    pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x100B7B00
// Name: public: static void CBaseEntity::SendProxy_CellZ(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SendProxy_CellZ(const SendProp *pProp, CBaseEntity *pStruct, int *pData, DVariant *pOut)
{
  int cell[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( CBaseEntity::UseStepSimulationNetworkOrigin(this: pStruct, out_v: (const Vector **)&pStruct, cell) )
    pOut->m_Int = cell[2];
  else
    pOut->m_Int = *pData;
}

//------------------------------------------------------------------------------
// Address: 0x100B7B40
// Name: public: static void CBaseEntity::SendProxy_CellOrigin(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SendProxy_CellOrigin(
        const SendProp *pProp,
        CBaseEntity *pStruct,
        const void *pData,
        DVariant *pOut)
{
  CBaseEntity *v4; // esi
  int m_Value; // edx
  int v6; // ebx
  float *p_x; // ecx
  int m_cellwidth; // esi
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  DVariant *v13; // edi
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  __int64 v17; // rax
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  int cell[3]; // [esp+Ch] [ebp-Ch] BYREF

  v4 = pStruct;
  if ( CBaseEntity::UseStepSimulationNetworkOrigin(this: pStruct, out_v: (const Vector **)&pStruct, cell) )
  {
    v6 = cell[1];
    m_Value = cell[0];
    p_x = (float *)pStruct;
  }
  else
  {
    m_Value = v4->m_cellX.m_Value;
    v6 = v4->m_cellY.m_Value;
    p_x = &v4->m_vecOrigin.m_Value.x;
    cell[2] = v4->m_cellZ.m_Value;
  }
  m_cellwidth = v4->m_cellwidth;
  v9 = *p_x;
  v10 = (float)(int)abs32(m_Value * m_cellwidth - 0x4000);
  if ( *p_x >= 0.0 )
    v11 = v9 - v10;
  else
    v11 = v10 + v9;
  v12 = (float)m_cellwidth;
  if ( v11 >= 0.0 )
  {
    if ( v11 > v12 )
      v11 = (float)m_cellwidth;
  }
  else
  {
    v11 = 0.0;
  }
  v13 = pOut;
  pOut->m_Float = v11;
  v14 = p_x[1];
  v15 = (float)(int)abs32(v6 * m_cellwidth - 0x4000);
  if ( v14 >= 0.0 )
    v16 = v14 - v15;
  else
    v16 = v15 + v14;
  if ( v16 >= 0.0 )
  {
    if ( v16 > v12 )
      v16 = (float)m_cellwidth;
  }
  else
  {
    v16 = 0.0;
  }
  v17 = cell[2] * m_cellwidth - 0x4000;
  v13->m_Vector[1] = v16;
  v18 = p_x[2];
  v19 = (float)(int)((HIDWORD(v17) ^ v17) - HIDWORD(v17));
  if ( v18 >= 0.0 )
    v20 = v18 - v19;
  else
    v20 = v19 + v18;
  if ( v20 >= 0.0 )
  {
    if ( v20 > v12 )
      v20 = (float)m_cellwidth;
    v13->m_Vector[2] = v20;
  }
  else
  {
    v13->m_Vector[2] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7C80
// Name: public: static void CBaseEntity::SendProxy_CellOriginXY(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SendProxy_CellOriginXY(
        const SendProp *pProp,
        CBaseEntity *pStruct,
        const void *pData,
        DVariant *pOut)
{
  CBaseEntity *v4; // esi
  int m_Value; // edx
  int v6; // ebx
  float *p_x; // edi
  int m_cellwidth; // ecx
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  DVariant *v13; // esi
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  int cell[3]; // [esp+Ch] [ebp-Ch] BYREF

  v4 = pStruct;
  if ( CBaseEntity::UseStepSimulationNetworkOrigin(this: pStruct, out_v: (const Vector **)&pStruct, cell) )
  {
    v6 = cell[1];
    m_Value = cell[0];
    p_x = (float *)pStruct;
  }
  else
  {
    m_Value = v4->m_cellX.m_Value;
    v6 = v4->m_cellY.m_Value;
    p_x = &v4->m_vecOrigin.m_Value.x;
  }
  m_cellwidth = v4->m_cellwidth;
  v9 = *p_x;
  v10 = (float)(int)abs32(m_Value * m_cellwidth - 0x4000);
  if ( *p_x >= 0.0 )
    v11 = v9 - v10;
  else
    v11 = v10 + v9;
  v12 = (float)m_cellwidth;
  if ( v11 >= 0.0 )
  {
    if ( v11 > v12 )
      v11 = (float)m_cellwidth;
  }
  else
  {
    v11 = 0.0;
  }
  v13 = pOut;
  pOut->m_Float = v11;
  v14 = p_x[1];
  v15 = (float)(int)abs32(v6 * m_cellwidth - 0x4000);
  if ( v14 >= 0.0 )
    v16 = v14 - v15;
  else
    v16 = v15 + v14;
  if ( v16 >= 0.0 )
  {
    if ( v16 <= v12 )
      v13->m_Vector[1] = v16;
    else
      v13->m_Vector[1] = v12;
  }
  else
  {
    v13->m_Vector[1] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7D70
// Name: public: static void CBaseEntity::SendProxy_CellOriginZ(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::SendProxy_CellOriginZ(
        const SendProp *pProp,
        CBaseEntity *pStruct,
        const void *pData,
        DVariant *pOut)
{
  CBaseEntity *v4; // esi
  int m_Value; // ecx
  CBaseEntity *p_m_vecOrigin; // eax
  float v7; // xmm1_4
  int m_cellwidth; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  int cell[3]; // [esp+4h] [ebp-Ch] BYREF

  v4 = pStruct;
  if ( CBaseEntity::UseStepSimulationNetworkOrigin(this: pStruct, out_v: (const Vector **)&pStruct, cell) )
  {
    m_Value = cell[2];
    p_m_vecOrigin = pStruct;
  }
  else
  {
    m_Value = v4->m_cellZ.m_Value;
    p_m_vecOrigin = (CBaseEntity *)&v4->m_vecOrigin;
  }
  v7 = *(float *)&p_m_vecOrigin->m_pfnThink;
  m_cellwidth = v4->m_cellwidth;
  v9 = (float)(int)abs32(m_Value * m_cellwidth - 0x4000);
  if ( v7 >= 0.0 )
    v10 = v7 - v9;
  else
    v10 = v9 + v7;
  v11 = (float)m_cellwidth;
  if ( v10 >= 0.0 )
  {
    if ( v10 <= v11 )
      pOut->m_Float = v10;
    else
      pOut->m_Float = v11;
  }
  else
  {
    pOut->m_Int = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7E10
// Name: void SendProxy_Angles(class SendProp const __near *,void const __near *,void const __near *,class DVariant __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Angles(const SendProp *pProp, CBaseEntity *pStruct, const void *pData, DVariant *pOut)
{
  char *DataObject; // esi
  float *p_x; // eax

  if ( !g_bTestMoveTypeStepSimulation
    || pStruct->m_MoveType.m_Value != 3
    || !CBaseEntity::HasDataObjectType(this: pStruct, type: 2)
    || (DataObject = (char *)CBaseEntity::GetDataObject(this: pStruct, type: 2),
        CBaseEntity::ComputeStepSimulationNetwork(this: pStruct, step: *(float *)&DataObject),
        p_x = (float *)(DataObject + 172),
        DataObject[1] == 0) )
  {
    p_x = &pStruct->m_angRotation.m_Value.x;
  }
  pOut->m_Float = (float)(unsigned __int16)(int)(float)(*p_x * 182.04445) * 0.0054931641;
  pOut->m_Vector[1] = (float)(unsigned __int16)(int)(float)(p_x[1] * 182.04445) * 0.0054931641;
  pOut->m_Vector[2] = (float)(unsigned __int16)(int)(float)(p_x[2] * 182.04445) * 0.0054931641;
}

//------------------------------------------------------------------------------
// Address: 0x100B84B0
// Name: public: virtual void CBaseEntity::PostConstructor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PostConstructor(CBaseEntity *this, const char *szClassname)
{
  CServerNetworkProperty *p_m_Network; // edi
  edict_t *m_pPev; // eax
  edict_t *v5; // eax

  p_m_Network = &this->m_Network;
  CServerNetworkProperty::CacheServerClass(this: &this->m_Network);
  if ( szClassname != nullptr )
    this->m_iClassname.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szClassname).pszValue;
  if ( (this->m_iEFlags & 0x200) != 0 )
  {
    CBaseEntityList::AddNonNetworkableEntity(this: &gEntList, result: (CBaseHandle *)&szClassname, pEnt: this);
    CGlobalEntityList::UpdateName(this: &gEntList, pHandleEnt: this, hEnt: (CBaseHandle)szClassname);
  }
  else
  {
    if ( (this->m_iEFlags & 0x400) == 0 )
    {
      CServerNetworkProperty::AttachEdict(this: p_m_Network, pRequiredEdict: g_pForceAttachEdict);
      g_pForceAttachEdict = nullptr;
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      CBaseEntityList::AddNetworkableEntity(
        this: &gEntList,
        result: (CBaseHandle *)&szClassname,
        pEnt: this,
        index: m_pPev - gpGlobals->pEdicts,
        iForcedSerialNum: -1);
      CGlobalEntityList::UpdateName(this: &gEntList, pHandleEnt: this, hEnt: (CBaseHandle)szClassname);
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        v5->m_pNetworkable = p_m_Network;
    }
    this->InitSharedVars(this);
  }
  CBaseEntity::CheckHasThinkFunction(this, isThinking: false);
  CBaseEntity::CheckHasGamePhysicsSimulation(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8590
// Name: public: bool CBaseEntity::IsFollowingEntity(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::IsFollowingEntity(CBaseEntity *this)
{
  unsigned int m_Index; // ecx
  BOOL result; // eax

  result = false;
  if ( (this->m_fEffects.m_Value & 1) != 0 && this->m_MoveType.m_Value == 0 )
  {
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B85E0
// Name: public: class CBaseEntity __near * CBaseEntity::GetFollowedEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetFollowedEntity(CBaseEntity *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax

  if ( (this->m_fEffects.m_Value & 1) != 0
    && this->m_MoveType.m_Value == 0
    && (m_Index = this->m_hMoveParent.m_Value.m_Index) != -1
    && (v2 = (unsigned __int16)m_Index,
        v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v4 = HIWORD(m_Index),
        v3->m_SerialNumber == v4)
    && v3->m_pEntity != nullptr
    && (v5 = v2, v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4, v7 = &g_pEntityList->m_EntPtrArray[v5], v6) )
  {
    return (CBaseEntity *)v7->m_pEntity;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8640
// Name: public: void CBaseEntity::DrawBBoxOverlay(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DrawBBoxOverlay(CBaseEntity *this, float flDuration)
{
  Vector center; // [esp+10h] [ebp-3Ch] BYREF
  Vector mins; // [esp+1Ch] [ebp-30h] BYREF
  Vector extents; // [esp+28h] [ebp-24h] BYREF
  Vector vecTriggerMins; // [esp+34h] [ebp-18h] BYREF
  Vector vecTriggerMaxs; // [esp+40h] [ebp-Ch] BYREF

  if ( this->m_Network.m_pPev != nullptr )
  {
    NDebugOverlay::EntityBounds(pEntity: this, r: 255, g: 100, b: 0, a: 0, flDuration);
    if ( SLOBYTE(this->m_Collision.m_usSolidFlags.m_Value) < 0 )
    {
      this->m_Collision.WorldSpaceTriggerBounds(this: &this->m_Collision, a2: &vecTriggerMins, a3: &vecTriggerMaxs);
      center.x = (float)(vecTriggerMaxs.x + vecTriggerMins.x) * 0.5;
      extents.x = vecTriggerMaxs.x - center.x;
      extents.y = vecTriggerMaxs.y - (float)((float)(vecTriggerMaxs.y + vecTriggerMins.y) * 0.5);
      extents.z = vecTriggerMaxs.z - (float)((float)(vecTriggerMaxs.z + vecTriggerMins.z) * 0.5);
      center.y = (float)(vecTriggerMaxs.y + vecTriggerMins.y) * 0.5;
      center.z = (float)(vecTriggerMaxs.z + vecTriggerMins.z) * 0.5;
      mins.x = -(float)(vecTriggerMaxs.x - center.x);
      mins.y = -extents.y;
      mins.z = -extents.z;
      NDebugOverlay::Box(origin: &center, &mins, maxs: &extents, r: 0, g: 255, b: 255, a: 0, flDuration);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8760
// Name: public: void CBaseEntity::DrawAbsBoxOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DrawAbsBoxOverlay(CBaseEntity *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  int v3; // edi
  int v4; // ebx
  Vector center; // [esp+18h] [ebp-3Ch] BYREF
  Vector mins; // [esp+24h] [ebp-30h] BYREF
  Vector extents; // [esp+30h] [ebp-24h] BYREF
  Vector vecSurroundMins; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecSurroundMaxs; // [esp+48h] [ebp-Ch] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  v3 = 0;
  v4 = 200;
  if ( m_pPhysicsObject != nullptr && m_pPhysicsObject->IsAsleep(this: m_pPhysicsObject) )
  {
    v3 = 90;
    v4 = 120;
  }
  if ( this->m_Network.m_pPev != nullptr )
  {
    this->m_Collision.WorldSpaceSurroundingBounds(this: &this->m_Collision, a2: &vecSurroundMins, a3: &vecSurroundMaxs);
    center.x = (float)(vecSurroundMaxs.x + vecSurroundMins.x) * 0.5;
    extents.x = vecSurroundMaxs.x - center.x;
    extents.y = vecSurroundMaxs.y - (float)((float)(vecSurroundMaxs.y + vecSurroundMins.y) * 0.5);
    extents.z = vecSurroundMaxs.z - (float)((float)(vecSurroundMaxs.z + vecSurroundMins.z) * 0.5);
    center.y = (float)(vecSurroundMaxs.y + vecSurroundMins.y) * 0.5;
    center.z = (float)(vecSurroundMaxs.z + vecSurroundMins.z) * 0.5;
    mins.x = -(float)(vecSurroundMaxs.x - center.x);
    mins.y = -extents.y;
    mins.z = -extents.z;
    NDebugOverlay::Box(origin: &center, &mins, maxs: &extents, r: v3, g: v4, b: 0, a: 0, flDuration: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8860
// Name: public: void CBaseEntity::DrawTimedOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DrawTimedOverlays(CBaseEntity *this)
{
  CBaseEntity *v1; // ebx
  bool v2; // zf
  const char *DebugName; // eax
  TimedOverlay_t *m_pTimedOverlay; // esi
  int v5; // edi
  TimedOverlay_t *pNextTimedOverlay; // eax
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // edi
  int v11; // edi
  int v12; // [esp+Ch] [ebp-224h]
  char tempstr[512]; // [esp+20h] [ebp-210h] BYREF
  TimedOverlay_t *pNextTO; // [esp+220h] [ebp-10h]
  CBaseEntity *v15; // [esp+224h] [ebp-Ch]
  TimedOverlay_t *pLastTO; // [esp+228h] [ebp-8h]
  int nCount; // [esp+22Ch] [ebp-4h]

  v1 = this;
  v2 = (this->m_debugOverlays & 0x10) == 0;
  v15 = this;
  if ( !v2 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "[%s]", DebugName);
    CBaseEntity::EntityText(this: v1, text_offset: 0, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
  }
  m_pTimedOverlay = v1->m_pTimedOverlay;
  v5 = 1;
  pLastTO = nullptr;
  nCount = 1;
  if ( m_pTimedOverlay != nullptr )
  {
    do
    {
      pNextTimedOverlay = m_pTimedOverlay->pNextTimedOverlay;
      pNextTO = pNextTimedOverlay;
      if ( (CBaseEntity::m_bDebugPause || gpGlobals->curtime <= (float)m_pTimedOverlay->msgEndTime) && v5 <= 10 )
      {
        v7 = 0;
        if ( !CBaseEntity::m_bDebugPause )
          v7 = (int)(float)((float)((float)(gpGlobals->curtime - (float)m_pTimedOverlay->msgStartTime)
                                  / (float)(m_pTimedOverlay->msgEndTime - m_pTimedOverlay->msgStartTime))
                          * 255.0);
        v8 = 145;
        v9 = 185;
        v10 = 145;
        if ( v7 < 50 )
        {
          v9 = 255;
          v8 = 205;
          v10 = 205;
        }
        if ( v7 < 0 )
          v7 = 0;
        v1 = v15;
        v12 = v10;
        v11 = nCount;
        CBaseEntity::EntityText(
          this: v15,
          text_offset: nCount,
          text: m_pTimedOverlay->msg,
          duration: 0.0,
          r: v9,
          g: v8,
          b: v12,
          a: 255 - v7);
        v5 = v11 + 1;
        nCount = v5;
        pLastTO = m_pTimedOverlay;
      }
      else
      {
        if ( pLastTO != nullptr )
          pLastTO->pNextTimedOverlay = pNextTimedOverlay;
        else
          v1->m_pTimedOverlay = pNextTimedOverlay;
        free(pMem: m_pTimedOverlay->msg);
        free(pMem: m_pTimedOverlay);
      }
      m_pTimedOverlay = pNextTO;
    }
    while ( pNextTO != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B89E0
// Name: public: void CBaseEntity::SetParent(struct string_t,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetParent(CBaseEntity *this, string_t newParent, CBaseEntity *pActivator, int iAttachment)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // edi
  const char *v7; // eax
  const char *v8; // esi
  const char *DebugName; // eax
  const char *v10; // ecx
  const char *v11; // esi
  const char *v12; // eax
  const char *v13; // [esp-4h] [ebp-10h]

  pszValue = newParent.pszValue;
  if ( newParent.pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v7 = newParent.pszValue;
  if ( newParent.pszValue != nullptr )
  {
    if ( EntityByName == nullptr )
    {
      v8 = this->m_iClassname.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      DebugName = CBaseEntity::GetDebugName(this);
      _Msg(a1: "Entity %s(%s) has bad parent %s\n", v8, DebugName, newParent.pszValue);
      return;
    }
  }
  else
  {
    v7 = locale;
  }
  if ( CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: EntityByName,
         szName: v7,
         pSearchingEntity: nullptr,
         pActivator,
         pCaller: nullptr,
         pFilter: nullptr) != nullptr )
  {
    v10 = newParent.pszValue;
    if ( newParent.pszValue == nullptr )
      v10 = locale;
    v11 = this->m_iClassname.pszValue;
    if ( v11 == nullptr )
      v11 = locale;
    v13 = v10;
    v12 = CBaseEntity::GetDebugName(this);
    _Msg(
      a1: "Entity %s(%s) is ambiguously parented to %s, because there is more than one entity by that name.\n",
      v11,
      v12,
      v13);
  }
  this->SetParent(this, a2: EntityByName, a3: iAttachment);
}

//------------------------------------------------------------------------------
// Address: 0x100B8AB0
// Name: public: void CBaseEntity::TakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::TakeDamage(CBaseEntity *this@<ecx>, int a2@<esi>, const CTakeDamageInfo *inputInfo)
{
  float z; // ecx
  float v5; // edx
  __int64 v6; // xmm0_8
  CBaseEntity *Attacker; // eax
  double v8; // st7
  CBaseEntity_vtbl *v9; // esi
  CBaseEntity *v10; // eax
  double v11; // st7
  int (__thiscall *OnTakeDamage)(CBaseEntity *, const CTakeDamageInfo *); // edx
  CTakeDamageInfo info; // [esp+4h] [ebp-68h] BYREF
  Vector v14; // [esp+60h] [ebp-Ch] BYREF

  if ( g_pGameRules != nullptr )
  {
    if ( ((unsigned __int8 (__thiscall *)(CGameRules *, int, int))g_pGameRules->Damage_NoPhysicsForce)(
           a1: g_pGameRules,
           a2: inputInfo->m_bitsDamageType,
           a3: a2) == 0
      && inputInfo->m_bitsDamageType != 0 )
    {
      if ( (z = inputInfo->m_vecDamageForce.z,
            *(_QWORD *)&v14.x = *(_QWORD *)&inputInfo->m_vecDamageForce.x,
            v14.z = z,
            vec3_origin.x == v14.x)
        && vec3_origin.y == v14.y
        && vec3_origin.z == v14.z
        || (v5 = inputInfo->m_vecDamagePosition.z,
            *(_QWORD *)&v14.x = *(_QWORD *)&inputInfo->m_vecDamagePosition.x,
            v14.z = v5,
            vec3_origin.x == v14.x)
        && vec3_origin.y == v14.y
        && vec3_origin.z == v14.z )
      {
        if ( ++warningCount < 10 )
        {
          *(_QWORD *)&v14.x = *(_QWORD *)&inputInfo->m_vecDamageForce.x;
          v14.z = z;
          if ( Vector::operator==(this: &v14, src: &vec3_origin) )
            DevWarning(a1: "CBaseEntity::TakeDamage:  with inputInfo.GetDamageForce() == vec3_origin\n");
          v6 = *(_QWORD *)&inputInfo->m_vecDamagePosition.x;
          v14.z = inputInfo->m_vecDamagePosition.z;
          *(_QWORD *)&v14.x = v6;
          if ( Vector::operator==(this: &v14, src: &vec3_origin) )
            DevWarning(a1: "CBaseEntity::TakeDamage:  with inputInfo.GetDamagePosition() == vec3_origin\n");
        }
      }
    }
    if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *))this->PassesDamageFilter)(a1: this) != 0
      && g_pGameRules->AllowDamage(this: g_pGameRules, a2: this, a3: inputInfo) )
    {
      if ( PhysIsInCallback() )
      {
        PhysCallbackDamage(pEntity: this, info: inputInfo);
      }
      else
      {
        CTakeDamageInfo::CTakeDamageInfo(this: &info, __that: inputInfo);
        if ( CTakeDamageInfo::GetAttacker(this: &info) != nullptr )
        {
          Attacker = CTakeDamageInfo::GetAttacker(this: &info);
          v8 = ((double (__thiscall *)(CBaseEntity *, CBaseEntity *))Attacker->GetAttackDamageScale)(
                 a1: Attacker,
                 a2: this);
          info.m_flDamage = v8 * info.m_flDamage;
        }
        v9 = this->__vftable;
        v10 = CTakeDamageInfo::GetAttacker(this: &info);
        v11 = ((double (__thiscall *)(CBaseEntity *, CBaseEntity *))v9->GetReceivedDamageScale)(a1: this, a2: v10);
        OnTakeDamage = this->OnTakeDamage;
        info.m_flDamage = v11 * info.m_flDamage;
        OnTakeDamage(this, a2: &info);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8C80
// Name: public: void CBaseEntity::SendOnKilledGameEvent(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::SendOnKilledGameEvent(CBaseEntity *this@<ecx>, int a2@<ebx>, const CTakeDamageInfo *info)
{
  IGameEvent *v4; // edi
  edict_t *m_pPev; // eax
  unsigned int m_Index; // ecx
  CBaseEntityList *v7; // edx
  int v8; // eax
  CEntInfo *v9; // esi
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // zf
  CEntInfo *v13; // eax
  IHandleEntity *m_pEntity; // eax
  signed int v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  CEntInfo *v18; // esi
  unsigned int v19; // ecx
  int v20; // eax
  CEntInfo *v21; // eax
  IHandleEntity *v22; // eax
  signed int v23; // eax

  v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "entity_killed", a3: 0, a4: 0);
  if ( v4 != nullptr )
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    ((void (__thiscall *)(IGameEvent *, const char *, edict_t *, int))v4->SetInt)(
      a1: v4,
      a2: "entindex_killed",
      a3: m_pPev,
      a4: a2);
    m_Index = info->m_hAttacker.m_Index;
    v7 = g_pEntityList;
    if ( m_Index != -1 )
    {
      v8 = (unsigned __int16)m_Index;
      v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v10 = HIWORD(m_Index);
      if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
      {
        v11 = v8;
        v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
        v13 = &g_pEntityList->m_EntPtrArray[v11];
        if ( v12 )
          m_pEntity = v13->m_pEntity;
        else
          m_pEntity = nullptr;
        v15 = (signed int)m_pEntity[6].__vftable;
        if ( v15 != 0 )
          v15 = (signed int)(v15 - (unsigned int)gpGlobals->pEdicts) >> 4;
        v4->SetInt(this: v4, a2: "entindex_attacker", a3: v15);
        v7 = g_pEntityList;
      }
    }
    v16 = info->m_hInflictor.m_Index;
    if ( v16 != -1 )
    {
      v17 = (unsigned __int16)v16;
      v18 = &v7->m_EntPtrArray[(unsigned __int16)v16];
      v19 = HIWORD(v16);
      if ( v18->m_SerialNumber == v19 && v18->m_pEntity != nullptr )
      {
        v20 = v17;
        v12 = v7->m_EntPtrArray[v20].m_SerialNumber == v19;
        v21 = &v7->m_EntPtrArray[v20];
        if ( v12 )
          v22 = v21->m_pEntity;
        else
          v22 = nullptr;
        v23 = (signed int)v22[6].__vftable;
        if ( v23 != 0 )
          v23 = (signed int)(v23 - (unsigned int)gpGlobals->pEdicts) >> 4;
        v4->SetInt(this: v4, a2: "entindex_inflictor", a3: v23);
      }
    }
    ((void (__thiscall *)(IGameEvent *, const char *))v4->SetInt)(a1: v4, a2: "damagebits");
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8E80
// Name: public: virtual int CBaseEntity::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::ObjectCaps(CBaseEntity *this)
{
  IVModelInfo_vtbl *v2; // edi
  int v3; // eax
  const struct model_t *v4; // eax
  bool v5; // bl
  unsigned int m_Index; // ecx
  CEntInfo *v7; // eax
  IHandleEntity *m_pEntity; // esi
  char v9; // al
  int v10; // edi

  v2 = modelinfo->__vftable;
  v3 = this->GetModelIndex(this);
  v4 = v2->GetModel(this: modelinfo, a2: v3);
  v5 = v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) == 1;
  m_Index = this->m_pParent.m_Index;
  if ( m_Index == -1 )
    return v5 ? 0 : 0x80;
  v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return v5 ? 0 : 0x80;
  m_pEntity = v7->m_pEntity;
  if ( v7->m_pEntity == nullptr )
    return v5 ? 0 : 0x80;
  v9 = (char)m_pEntity->__vftable[12].GetRefEHandle(this: m_pEntity);
  if ( v5 )
    v10 = v9 & 0xF;
  else
    v10 = v9 & 0x8F;
  if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
    return v10 | 0x80;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100B8F40
// Name: public: virtual void CBaseEntity::StartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::StartTouch(CBaseEntity *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_pParent.m_Index;
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
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      m_pEntity->__vftable[33].SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)pOther);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8FA0
// Name: public: virtual void CBaseEntity::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::Touch(CBaseEntity *this, CBaseEntity *pOther)
{
  void (__thiscall *m_pfnTouch)(CBaseEntity *, CBaseEntity *); // eax
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax

  m_pfnTouch = this->m_pfnTouch;
  if ( m_pfnTouch != nullptr )
    ((void (__stdcall *)(CBaseEntity *))m_pfnTouch)(a1: pOther);
  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        ((void (__thiscall *)(IHandleEntity *, CBaseEntity *))v10->m_pEntity->__vftable[33].GetRefEHandle)(
          a1: v10->m_pEntity,
          a2: pOther);
      else
        (*(void (__thiscall **)(_DWORD, CBaseEntity *))(MEMORY[0] + 404))(a1: 0, a2: pOther);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9020
// Name: public: virtual void CBaseEntity::EndTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::EndTouch(CBaseEntity *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_pParent.m_Index;
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
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      ((void (__thiscall *)(IHandleEntity *, CBaseEntity *))m_pEntity->__vftable[34].dtr_IHandleEntity)(
        a1: m_pEntity,
        a2: pOther);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9080
// Name: public: virtual void CBaseEntity::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::Blocked(CBaseEntity *this, CBaseEntity *pOther)
{
  void (__thiscall *m_pfnBlocked)(CBaseEntity *, CBaseEntity *); // eax
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax

  m_pfnBlocked = this->m_pfnBlocked;
  if ( m_pfnBlocked != nullptr )
    ((void (__stdcall *)(CBaseEntity *))m_pfnBlocked)(a1: pOther);
  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        ((void (__thiscall *)(IHandleEntity *, CBaseEntity *))v10->m_pEntity->__vftable[34].GetRefEHandle)(
          a1: v10->m_pEntity,
          a2: pOther);
      else
        (*(void (__thiscall **)(_DWORD, CBaseEntity *))(MEMORY[0] + 416))(a1: 0, a2: pOther);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9100
// Name: public: virtual void CBaseEntity::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::Use(
        CBaseEntity *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  void (__thiscall *m_pfnUse)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float); // eax
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // eax

  m_pfnUse = this->m_pfnUse;
  if ( m_pfnUse != nullptr )
  {
    ((void (__stdcall *)(CBaseEntity *, CBaseEntity *, USE_TYPE, _DWORD))m_pfnUse)(
      a1: pActivator,
      a2: pCaller,
      a3: useType,
      a4: LODWORD(value));
  }
  else
  {
    m_Index = this->m_pParent.m_Index;
    if ( m_Index != -1 )
    {
      v7 = (unsigned __int16)m_Index;
      v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v9 = HIWORD(m_Index);
      if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
      {
        v10 = v7;
        v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
        v12 = &g_pEntityList->m_EntPtrArray[v10];
        if ( v11 )
          m_pEntity = v12->m_pEntity;
        else
          m_pEntity = nullptr;
        ((void (__thiscall *)(IHandleEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, _DWORD))m_pEntity->__vftable[33].dtr_IHandleEntity)(
          a1: m_pEntity,
          a2: pActivator,
          a3: pCaller,
          a4: useType,
          a5: LODWORD(value));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B91A0
// Name: protected: void CBaseEntity::PhysicsRelinkChildren(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsRelinkChildren(CBaseEntity *this, float dt)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // esi
  IHandleEntity_vtbl *v4; // eax
  IHandleEntity_vtbl *v5; // eax

  m_Index = this->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  while ( m_pEntity != nullptr )
  {
    if ( BYTE2(m_pEntity[65].__vftable) != 0 && ((int)m_pEntity[65].__vftable & 4) == 0
      || ((int)m_pEntity[65].__vftable & 8) != 0 )
    {
      CBaseEntity::PhysicsTouchTriggers(this: (CBaseEntity *)m_pEntity, pPrevAbsOrigin: nullptr);
    }
    if ( BYTE2(m_pEntity[53].__vftable) != 6 )
      ((void (__thiscall *)(IHandleEntity *, _DWORD))m_pEntity->__vftable[52].GetRefEHandle)(
        a1: m_pEntity,
        a2: LODWORD(dt));
    v4 = m_pEntity[55].__vftable;
    if ( v4 != (IHandleEntity_vtbl *)-1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == (unsigned int)v4 >> 16
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity != nullptr )
    {
      CBaseEntity::PhysicsRelinkChildren(this: (CBaseEntity *)m_pEntity, dt);
    }
    v5 = m_pEntity[56].__vftable;
    if ( v5 == (IHandleEntity_vtbl *)-1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != (unsigned int)v5 >> 16 )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B92B0
// Name: public: virtual void CBaseEntity::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VPhysicsCollision(CBaseEntity *this, surfacedata_t *index, CBaseEntity *pEvent)
{
  BOOL v5; // ebx
  CBaseEntity *v6; // eax
  surfacedata_t *v7; // eax
  float deltaTime; // [esp+8h] [ebp-18h]
  float speed; // [esp+Ch] [ebp-14h]
  surfacedata_t *phit; // [esp+28h] [ebp+8h]
  CBaseEntity *pHitEntity; // [esp+2Ch] [ebp+Ch]

  v5 = index == nullptr;
  v6 = *((CBaseEntity **)&pEvent->m_flSimulationTime.m_Value + v5);
  pHitEntity = v6;
  if ( (this->m_MoveType.m_Value == 6 || v6->m_MoveType.m_Value == 6)
    && (*(float *)&pEvent->m_Network.m_pOuter >= 0.5 || v6 != this) )
  {
    phit = physprops->GetSurfaceData(this: physprops, a2: *((_DWORD *)&pEvent->m_pfnThink + v5));
    v7 = physprops->GetSurfaceData(this: physprops, a2: *((_DWORD *)&pEvent->m_pfnThink + (_DWORD)index));
    if ( phit->game.material != 88 && v7->game.material != 88 )
    {
      speed = *(float *)&pEvent->m_Network.m_pPev;
      deltaTime = *(float *)&pEvent->m_Network.m_pOuter;
      if ( pHitEntity == this )
        PhysCollisionSound(
          pEntity: this,
          pPhysObject: *((IPhysicsObject **)&pEvent->__vftable + (_DWORD)index),
          channel: 4,
          surfaceProps: *((_DWORD *)&pEvent->m_pfnThink + (_DWORD)index),
          surfacePropsHit: *((_DWORD *)&pEvent->m_pfnThink + v5),
          deltaTime,
          speed);
      else
        PhysCollisionSound(
          pEntity: this,
          pPhysObject: *((IPhysicsObject **)&pEvent->__vftable + (_DWORD)index),
          channel: 6,
          surfaceProps: *((_DWORD *)&pEvent->m_pfnThink + (_DWORD)index),
          surfacePropsHit: *((_DWORD *)&pEvent->m_pfnThink + v5),
          deltaTime,
          speed);
      PhysCollisionScreenShake((gamevcollisionevent_t *)pEvent, (int)index);
      PhysCollisionDust((gamevcollisionevent_t *)pEvent, phit);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B93A0
// Name: public: bool CBaseEntity::Intersects(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::Intersects(CBaseEntity *this, CBaseEntity *pOther)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // edi
  CBaseEntity::NetworkVar_m_Collision *v3; // esi
  const Vector *v4; // eax
  const QAngle *v6; // [esp-1Ch] [ebp-28h]
  const Vector *v7; // [esp-18h] [ebp-24h]
  const Vector *v8; // [esp-14h] [ebp-20h]
  const Vector *v9; // [esp-10h] [ebp-1Ch]
  const QAngle *v10; // [esp-Ch] [ebp-18h]
  const Vector *v11; // [esp-8h] [ebp-14h]
  const Vector *v12; // [esp-4h] [ebp-10h]

  if ( this->m_Network.m_pPev == nullptr || pOther->m_Network.m_pPev == nullptr )
    return false;
  p_m_Collision = &pOther->m_Collision;
  v3 = &this->m_Collision;
  v12 = pOther->m_Collision.OBBMaxs(this: &pOther->m_Collision);
  v11 = p_m_Collision->OBBMins(this: p_m_Collision);
  v10 = p_m_Collision->GetCollisionAngles(this: p_m_Collision);
  v9 = p_m_Collision->GetCollisionOrigin(this: p_m_Collision);
  v8 = v3->OBBMaxs(this: v3);
  v7 = v3->OBBMins(this: v3);
  v6 = v3->GetCollisionAngles(this: v3);
  v4 = v3->GetCollisionOrigin(this: v3);
  return IsOBBIntersectingOBB(
           vecOrigin1: v4,
           vecAngles1: v6,
           boxMin1: v7,
           boxMax1: v8,
           vecOrigin2: v9,
           vecAngles2: v10,
           boxMin2: v11,
           boxMax2: v12,
           flTolerance: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100B9430
// Name: public: virtual bool CBaseEntity::FVisible(class CBaseEntity __near *,int,class CBaseEntity __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::FVisible(
        CBaseEntity *this,
        CBaseEntity *pEntity,
        unsigned int traceMask,
        CBaseEntity **ppBlocker)
{
  unsigned int v5; // ebx
  CBaseEntity *v7; // eax
  CGameTrace tr; // [esp+8h] [ebp-80h] BYREF
  CTraceFilterLOS traceFilter; // [esp+5Ch] [ebp-2Ch] BYREF
  Vector vecLookerOrigin; // [esp+70h] [ebp-18h] BYREF
  Vector vecTargetOrigin; // [esp+7Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+88h] [ebp+0h] BYREF

  if ( (pEntity->m_fFlags.m_Value & 0x10000) == 0 )
  {
    this->EyePosition(this, result: &vecLookerOrigin);
    pEntity->EyePosition(this: pEntity, result: &vecTargetOrigin);
    if ( ai_LOS_mode.m_pParent != nullptr && ai_LOS_mode.m_pParent->m_Value.m_nValue != 0 )
    {
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)pEntity,
        vecAbsStart: &vecLookerOrigin,
        vecAbsEnd: &vecTargetOrigin,
        mask: traceMask,
        ignore: this,
        collisionGroup: 0,
        ptr: &tr);
    }
    else
    {
      v5 = traceMask;
      if ( traceMask == 16449 )
        v5 = 33570881;
      if ( this->IsPlayer(this) )
        v5 &= ~0x40u;
      CTraceFilterLOS::CTraceFilterLOS(
        this: &traceFilter,
        pHandleEntity: this,
        collisionGroup: 0,
        pHandleEntity2: pEntity);
      UTIL_TraceLine(
        a1: (int)&savedregs,
        a2: (int)pEntity,
        vecAbsStart: &vecLookerOrigin,
        vecAbsEnd: &vecTargetOrigin,
        mask: v5,
        pFilter: &traceFilter,
        ptr: &tr);
    }
    if ( tr.fraction == 1.0 && !tr.startsolid )
      return 1;
    if ( tr.m_pEnt == pEntity )
      return 1;
    if ( pEntity->IsPlayer(this: pEntity) )
    {
      v7 = (CBaseEntity *)pEntity->__vftable[1].GetDamageType(this: pEntity);
      if ( tr.m_pEnt == v7 )
        return 1;
    }
    if ( ppBlocker != nullptr )
      *ppBlocker = tr.m_pEnt;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B9550
// Name: void CC_AI_LOS_Debug(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_AI_LOS_Debug()
{
  int m_nValue; // esi
  CBaseEntity *i; // eax

  if ( ai_debug_los.m_pParent != nullptr )
    m_nValue = ai_debug_los.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    if ( m_nValue == 1 )
    {
      if ( i->m_Collision.m_nSolidType.m_Value == 0 || (i->m_Collision.m_usSolidFlags.m_Value & 4) != 0 )
      {
LABEL_11:
        i->m_debugOverlays &= ~0x80u;
        continue;
      }
      i->m_debugOverlays |= 0x80u;
    }
    else
    {
      if ( m_nValue != 2 )
        goto LABEL_11;
      i->m_debugOverlays |= 0x80u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B95C0
// Name: public: virtual bool CBaseEntity::IsViewable(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::IsViewable(CBaseEntity *this)
{
  if ( (this->m_fEffects.m_Value & 0x20) == 0 )
  {
    if ( CBaseEntity::IsBSPModel(this) )
    {
      if ( this->m_MoveType.m_Value != 0 )
        return 1;
    }
    else if ( this->GetModelIndex(this) != 0 )
    {
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B9600
// Name: public: int CBaseEntity::SetTransmitState(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::SetTransmitState(CBaseEntity *this, int nFlag)
{
  edict_t *m_pPev; // esi
  unsigned int v4; // edx
  edict_t *v5; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev == nullptr )
    return 0;
  v4 = m_pPev->m_fStateFlags & 0xFFFFFFC7;
  m_pPev->m_fStateFlags = nFlag | v4;
  if ( (((unsigned __int8)v4 ^ (unsigned __int8)(nFlag | v4)) & 0x10) != 0 )
  {
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
      v5 -= (int)gpGlobals->pEdicts;
    engine->NotifyEdictFlagsChange(this: engine, a2: (int)v5);
  }
  return m_pPev->m_fStateFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100B9650
// Name: public: virtual int CBaseEntity::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::UpdateTransmitState(CBaseEntity *this)
{
  unsigned int m_Index; // ecx
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
  {
    m_Index = this->m_hMoveChild.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      return CBaseEntity::SetTransmitState(this, nFlag: 16);
    }
  }
  if ( (this->m_iEFlags & 0x80) == 0
    && (this->GetModelIndex(this) == 0
     || *(_DWORD *)((int (__thiscall *)(CBaseEntity *, _BYTE *))this->GetModelName)(a1: this, a2: v4) == 0) )
  {
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
  }
  if ( this->GetModelIndex(this) == 1 || (this->m_iEFlags & 0x20000) != 0 )
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  return CBaseEntity::SetTransmitState(this, nFlag: 32);
}

//------------------------------------------------------------------------------
// Address: 0x100B9710
// Name: public: int CBaseEntity::DispatchUpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::DispatchUpdateTransmitState(CBaseEntity *this)
{
  edict_t *m_pPev; // eax
  int result; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( this->m_nTransmitStateOwnedCounter != 0 )
  {
    if ( m_pPev != nullptr )
      return m_pPev->m_fStateFlags;
    else
      return 0;
  }
  else
  {
    ++g_nInsideDispatchUpdateTransmitState;
    result = this->UpdateTransmitState(this);
    --g_nInsideDispatchUpdateTransmitState;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9740
// Name: public: virtual int CBaseEntity::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::ShouldTransmit(CBaseEntity *this, const CCheckTransmitInfo *pInfo)
{
  edict_t *m_pPev; // eax
  int m_fStateFlags; // eax
  int result; // eax
  CBaseEntity *v6; // edi
  CTeam *GlobalTeam; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( this->m_nTransmitStateOwnedCounter != 0 )
  {
    if ( m_pPev != nullptr )
      m_fStateFlags = m_pPev->m_fStateFlags;
    else
      LOBYTE(m_fStateFlags) = 0;
  }
  else
  {
    ++g_nInsideDispatchUpdateTransmitState;
    LOBYTE(m_fStateFlags) = this->UpdateTransmitState(this);
    --g_nInsideDispatchUpdateTransmitState;
  }
  if ( (m_fStateFlags & 0x20) != 0 )
    return 32;
  if ( (m_fStateFlags & 8) != 0 )
    return 8;
  if ( (m_fStateFlags & 0x10) != 0 )
    return 16;
  v6 = CBaseEntity::Instance(pent: pInfo->m_pClientEnt);
  if ( GetGlobalTeam(iIndex: v6->m_iTeamNum.m_Value) == nullptr )
    return 32;
  GlobalTeam = GetGlobalTeam(iIndex: v6->m_iTeamNum.m_Value);
  result = GlobalTeam->ShouldTransmitToPlayer(this: GlobalTeam, a2: (CBasePlayer *)v6, a3: this);
  if ( result == 0 )
    return 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B97F0
// Name: public: virtual void CBaseEntity::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetTransmit(CBaseEntity *this, CCheckTransmitInfo *pInfo, int bAlways)
{
  int m_pPev; // esi
  CBitVec<2048> *m_pTransmitEdict; // edx
  CServerNetworkProperty *NetworkParent; // eax
  int v8; // esi
  CBitVec<2048> *m_pTransmitAlways; // edx
  int v10; // eax
  int pInfoa; // [esp+14h] [ebp+8h]

  m_pPev = (int)this->m_Network.m_pPev;
  if ( m_pPev != 0 )
    m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
  m_pTransmitEdict = pInfo->m_pTransmitEdict;
  pInfoa = 1 << (m_pPev & 0x1F);
  if ( (pInfoa & m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    NetworkParent = CServerNetworkProperty::GetNetworkParent(this: &this->m_Network);
    v8 = m_pPev >> 5;
    pInfo->m_pTransmitEdict->m_Ints[v8] |= pInfoa;
    m_pTransmitAlways = pInfo->m_pTransmitAlways;
    if ( m_pTransmitAlways != nullptr )
    {
      if ( (_BYTE)bAlways == 0 && NetworkParent == nullptr )
      {
        CServerNetworkProperty::RecomputePVSInformation(this: &this->m_Network);
        return;
      }
      m_pTransmitAlways->m_Ints[v8] |= pInfoa;
    }
    if ( NetworkParent != nullptr )
    {
      v10 = (int)NetworkParent->GetBaseEntity(this: NetworkParent);
      (*(void (__thiscall **)(int, CCheckTransmitInfo *, int))(*(_DWORD *)v10 + 88))(a1: v10, a2: pInfo, a3: bAlways);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9890
// Name: public: void CBaseEntity::InputUse(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::InputUse(
        CBaseEntity *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        inputdata_t *inputdata)
{
  IGameEvent *v5; // esi
  int v6; // eax

  ((void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, int, _DWORD))this->Use)(
    a1: this,
    a2: inputdata->pActivator,
    a3: inputdata->pCaller,
    a4: inputdata->nOutputID,
    a5: 0);
  v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_use", a3: 0, a4: 0);
  if ( v5 != nullptr )
  {
    if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, int, int, int))inputdata->pActivator->IsPlayer)(
           a1: inputdata->pActivator,
           a2: a3,
           a3: a4,
           a4: a2) != 0 )
      v6 = engine->GetPlayerUserId(this: engine, a2: inputdata->pActivator->m_Network.m_pPev);
    else
      v6 = 0;
    v5->SetInt(this: v5, a2: "userid", a3: v6);
    ((void (__thiscall *)(IGameEvent *, const char *))v5->SetInt)(a1: v5, a2: "entity");
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9950
// Name: public: void CBaseEntity::InputKill(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputKill(CBaseEntity *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  IVEngineServer_vtbl *v5; // edi
  int v6; // eax
  char *v7; // eax

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v4->m_pEntity != nullptr )
    {
      v4->m_pEntity->__vftable[19].SetRefEHandle(this: v4->m_pEntity, a2: (const CBaseHandle *)this);
      this->SetOwnerEntity(this, a2: nullptr);
    }
  }
  if ( this->IsPlayer(this) )
  {
    v5 = engine->__vftable;
    v6 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v7 = UTIL_VarArgs(format: "kickid %d CBaseEntity::InputKill()\n", v6);
    v5->ServerCommand(this: engine, a2: v7);
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B99F0
// Name: public: void CBaseEntity::InputKillHierarchy(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputKillHierarchy(CBaseEntity *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v5; // eax
  IHandleEntity *v6; // esi
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx

  m_Index = this->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      v5 = m_pEntity->m_hMovePeer.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        v6 = nullptr;
      else
        v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      CBaseEntity::InputKillHierarchy(this: m_pEntity, inputdata);
      m_pEntity = (CBaseEntity *)v6;
    }
    while ( v6 != nullptr );
  }
  v7 = this->m_hOwnerEntity.m_Value.m_Index;
  if ( v7 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
  {
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    if ( v8 != nullptr )
    {
      v8->__vftable[19].SetRefEHandle(this: v8, a2: (const CBaseHandle *)this);
      this->SetOwnerEntity(this, a2: nullptr);
    }
  }
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x100B9AC0
// Name: public: virtual void CBaseEntity::NetworkVar_m_Collision::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::NetworkVar_m_Collision::NetworkStateChanged(CBaseEntity::NetworkVar_m_Collision *this)
{
  CBaseEdict *v1; // ecx

  if ( *((_BYTE *)this - 144) != 0 )
  {
    *((_BYTE *)this - 140) |= 1u;
  }
  else
  {
    v1 = *((CBaseEdict **)this - 51);
    if ( v1 != nullptr )
    {
      v1->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v1)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9AF0
// Name: void CC_Ent_Remove(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Remove(const CCommand *args)
{
  const char *v1; // eax
  CBasePlayer *CommandClient; // eax
  CBaseEntity *v3; // eax
  CBaseEntity *Ent; // edi
  const char *v5; // esi
  const char *DebugName; // eax
  const char *v7; // eax
  int v8; // eax
  const char *pszValue; // esi
  const char *v10; // eax
  const char *v11; // esi
  const char *v12; // eax
  const char *v13; // esi
  const char *v14; // eax

  if ( args->m_nArgc <= 1 || (v1 = args->m_ppArgv[1]) == locale || _V_stricmp(s1: v1, s2: locale) == 0 )
  {
    if ( UTIL_GetCommandClient() == nullptr )
      return;
    CommandClient = UTIL_GetCommandClient();
    v3 = CommandClient->FindPickerEntity(this: CommandClient);
    goto LABEL_6;
  }
  v7 = locale;
  if ( args->m_nArgc > 1 )
    v7 = args->m_ppArgv[1];
  v8 = atoi(nptr: v7);
  if ( v8 != 0 )
  {
    v3 = CBaseEntity::Instance(iEnt: v8);
LABEL_6:
    Ent = v3;
    goto LABEL_7;
  }
  Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  if ( Ent == nullptr )
    return;
  while ( 1 )
  {
    pszValue = Ent->m_iName.m_Value.pszValue;
    if ( pszValue != nullptr )
    {
      v10 = CCommand::operator[](this: args, nIndex: 1);
      if ( v10 == pszValue || _V_stricmp(s1: v10, s2: pszValue) == 0 )
        break;
    }
    v11 = Ent->m_iClassname.pszValue;
    if ( v11 != nullptr )
    {
      v12 = CCommand::operator[](this: args, nIndex: 1);
      if ( v12 == v11 || _V_stricmp(s1: v12, s2: v11) == 0 )
        break;
    }
    v13 = Ent->m_iClassname.pszValue;
    if ( v13 == nullptr )
      v13 = locale;
    v14 = CCommand::operator[](this: args, nIndex: 1);
    if ( v14 == v13 || _V_stricmp(s1: v14, s2: v13) == 0 )
      break;
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
    if ( Ent == nullptr )
      return;
  }
LABEL_7:
  if ( Ent != nullptr )
  {
    v5 = Ent->m_iClassname.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    DebugName = CBaseEntity::GetDebugName(this: Ent);
    _Msg(a1: "Removed %s(%s)\n", v5, DebugName);
    UTIL_Remove(oldObj: Ent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9C50
// Name: void CC_Ent_RemoveAll(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_RemoveAll(const CCommand *args)
{
  CBaseEntity *Ent; // esi
  const char *pszValue; // edi
  const char *v4; // eax
  const char *v5; // edi
  const char *v6; // eax
  const char *v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int iCount; // [esp+Ch] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    iCount = 0;
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
    if ( Ent == nullptr )
      goto LABEL_20;
    do
    {
      pszValue = Ent->m_iName.m_Value.pszValue;
      if ( pszValue != nullptr )
      {
        v4 = CCommand::operator[](this: args, nIndex: 1);
        if ( v4 == pszValue || _V_stricmp(s1: v4, s2: pszValue) == 0 )
          goto LABEL_14;
      }
      v5 = Ent->m_iClassname.pszValue;
      if ( v5 != nullptr )
      {
        v6 = CCommand::operator[](this: args, nIndex: 1);
        if ( v6 == v5 || _V_stricmp(s1: v6, s2: v5) == 0 )
          goto LABEL_14;
      }
      v7 = Ent->m_iClassname.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      v8 = CCommand::operator[](this: args, nIndex: 1);
      if ( v8 == v7 || _V_stricmp(s1: v8, s2: v7) == 0 )
      {
LABEL_14:
        UTIL_Remove(oldObj: Ent);
        ++iCount;
      }
      Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
    }
    while ( Ent != nullptr );
    if ( iCount != 0 )
    {
      v9 = locale;
      if ( args->m_nArgc > 1 )
        v9 = args->m_ppArgv[1];
      _Msg(a1: "Removed %d %s's\n", iCount, v9);
    }
    else
    {
LABEL_20:
      v10 = locale;
      if ( args->m_nArgc > 1 )
        v10 = args->m_ppArgv[1];
      _Msg(a1: "No %s found.\n", v10);
    }
  }
  else
  {
    _Msg(a1: "Removes all entities of the specified type\n\tArguments:   \t{entity_name} / {class_name}\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9D70
// Name: void CC_Find_Ent(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Find_Ent(const CCommand *args)
{
  CBaseEntity *i; // esi
  const char *pszValue; // ecx
  const char *v3; // edi
  signed int m_pPev; // eax
  const char *v5; // edx
  const char *v6; // ecx
  int iCount; // [esp+0h] [ebp-4h]
  const char *argsa; // [esp+Ch] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    iCount = 0;
    if ( args->m_nArgc > 1 )
      argsa = args->m_ppArgv[1];
    else
      argsa = locale;
    _Msg(a1: "Searching for entities with class/target name containing substring: '%s'\n", argsa);
    for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
          i != nullptr;
          i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
    {
      pszValue = i->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v3 = i->m_iName.m_Value.pszValue;
      if ( v3 == nullptr )
        v3 = locale;
      if ( pszValue != nullptr && *pszValue != 0 && V_stristr(pStr: pszValue, pSearch: argsa) != nullptr
        || v3 != nullptr && *v3 != 0 && V_stristr(pStr: v3, pSearch: argsa) != nullptr )
      {
        m_pPev = (signed int)i->m_Network.m_pPev;
        ++iCount;
        if ( m_pPev != 0 )
          m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        v5 = i->m_iName.m_Value.pszValue;
        if ( v5 == nullptr )
          v5 = locale;
        v6 = i->m_iClassname.pszValue;
        if ( v6 == nullptr )
          v6 = locale;
        _Msg(a1: "   '%s' : '%s' (entindex %d) \n", v6, v5, m_pPev);
      }
    }
    _Msg(a1: "Found %d matches.\n", iCount);
  }
  else
  {
    _Msg(a1: "Format: find_ent <substring>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9EA0
// Name: void CC_Find_Ent_Index(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Find_Ent_Index(const CCommand *args)
{
  const char *v1; // eax
  int v2; // esi
  CBaseEntity *v3; // eax
  const char *pszValue; // ecx
  const char *v5; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = locale;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    v3 = UTIL_EntityByIndex(entityIndex: v2);
    if ( v3 != nullptr )
    {
      pszValue = v3->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v5 = v3->m_iClassname.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      _Msg(a1: "   '%s' : '%s' (entindex %d) \n", v5, pszValue, v2);
    }
    else
    {
      _Msg(a1: "Found no entity at %d.\n", v2);
    }
  }
  else
  {
    _Msg(a1: "Format: find_ent_index <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9F30
// Name: void DumpEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpEntity(CBaseEntity *ent)
{
  datamap_t *j; // edi
  int v2; // ebx
  typedescription_t *dataDesc; // ecx
  const char *iVal; // eax
  IHandleEntity *m_pEntity; // eax
  const char *v6; // eax
  const char *v7; // eax
  char buf[256]; // [esp+14h] [ebp-118h] BYREF
  variant_t var; // [esp+114h] [ebp-18h] BYREF
  int i; // [esp+128h] [ebp-4h]

  for ( j = ent->GetDataDescMap(this: ent); j != nullptr; j = j->baseMap )
  {
    i = 0;
    if ( j->dataNumFields > 0 )
    {
      v2 = 0;
      do
      {
        dataDesc = j->dataDesc;
        var.iVal = 0;
        var.fieldType = FIELD_VOID;
        var.eVal.m_Index = -1;
        if ( CBaseEntity::ReadKeyField(this: ent, a2: (int)j, varName: dataDesc[v2].externalName, &var) != 0 )
        {
          buf[0] = 0;
          switch ( var.fieldType )
          {
            case FIELD_FLOAT:
              if ( var.fieldType == FIELD_FLOAT && var.flVal != 0.0 )
                V_snprintf(pDest: buf, maxLen: 256, pFormat: "%.2f", var.flVal);
              break;
            case FIELD_STRING:
              if ( var.fieldType == FIELD_STRING )
              {
                iVal = (const char *)var.iVal;
                if ( var.iVal == 0 )
                  iVal = locale;
              }
              else
              {
                iVal = variant_t::ToString(this: &var);
              }
              V_strncpy(pDest: buf, pSrc: iVal, maxLen: 256);
              break;
            case FIELD_INTEGER:
              if ( var.fieldType == FIELD_INTEGER && var.iVal != 0 )
                V_snprintf(pDest: buf, maxLen: 256, pFormat: "%d", var.iVal);
              break;
            case FIELD_EHANDLE:
              if ( var.fieldType == FIELD_EHANDLE )
              {
                if ( var.eVal.m_Index != -1
                  && g_pEntityList->m_EntPtrArray[LOWORD(var.eVal.m_Index)].m_SerialNumber == HIWORD(var.eVal.m_Index)
                  && g_pEntityList->m_EntPtrArray[LOWORD(var.eVal.m_Index)].m_pEntity != nullptr )
                {
                  if ( g_pEntityList->m_EntPtrArray[LOWORD(var.eVal.m_Index)].m_SerialNumber == HIWORD(var.eVal.m_Index) )
                    m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(var.eVal.m_Index)].m_pEntity;
                  else
                    m_pEntity = nullptr;
                  v6 = (const char *)m_pEntity[51].__vftable;
                  if ( v6 == nullptr )
                    v6 = locale;
                  V_snprintf(pDest: buf, maxLen: 256, pFormat: "%s", v6);
                }
              }
              else
              {
                if ( (`variant_t::Entity'::`4'::`local static guard' & 1) == 0 )
                  `variant_t::Entity'::`4'::`local static guard' |= 1u;
                `variant_t::Entity'::`4'::hNull.m_Index = -1;
              }
              break;
            default:
              break;
          }
          if ( _V_stricmp(s1: "parentname", s2: j->dataDesc[v2].externalName) != 0
            && _V_stricmp(s1: "targetname", s2: j->dataDesc[v2].externalName) != 0
            && buf[0] != 0 )
          {
            v7 = UTIL_VarArgs(format: "  %s: %s\n", j->dataDesc[v2].externalName, buf);
            _Msg(a1: v7);
          }
        }
        ++v2;
        ++i;
      }
      while ( i < j->dataNumFields );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA180
// Name: void CC_Ent_Dump(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Dump(const CCommand *args)
{
  CBasePlayer *CommandClient; // edi
  const char *v2; // eax
  CBaseEntity *NextCommandEntity; // esi
  const char *v4; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    if ( args->m_nArgc >= 2 )
    {
      v2 = CCommand::operator[](this: args, nIndex: 1);
      NextCommandEntity = GetNextCommandEntity(pPlayer: CommandClient, name: v2, ent: nullptr);
      if ( NextCommandEntity != nullptr )
      {
        do
        {
          DumpEntity(ent: NextCommandEntity);
          v4 = CCommand::operator[](this: args, nIndex: 1);
          NextCommandEntity = GetNextCommandEntity(pPlayer: CommandClient, name: v4, ent: NextCommandEntity);
        }
        while ( NextCommandEntity != nullptr );
      }
      else
      {
        ClientPrint(
          player: CommandClient,
          msg_dest: 2,
          msg_name: "ent_dump: no such entity",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
    else
    {
      ClientPrint(
        player: CommandClient,
        msg_dest: 2,
        msg_name: "Usage:\n   ent_dump <entity name/index/class>\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA230
// Name: public: void CBaseEntity::SetCheckUntouch(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetCheckUntouch(CBaseEntity *this, bool check)
{
  int m_iEFlags; // eax

  if ( check )
  {
    m_iEFlags = this->m_iEFlags;
    ++this->touchStamp;
    if ( (m_iEFlags & 0x1000000) == 0 )
    {
      this->m_iEFlags = m_iEFlags | 0x1000000;
      EntityTouch_Add(pEntity: this);
    }
  }
  else
  {
    this->m_iEFlags &= ~0x1000000u;
    EntityTouch_Remove(pEntity: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA280
// Name: public: void CBaseEntity::CalcAbsolutePosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseEntity::CalcAbsolutePosition(CBaseEntity *this@<ecx>, int a2@<ebp>)
{
  CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *p_m_angRotation; // edi
  unsigned int m_Index; // eax
  const matrix3x4_t *ParentToWorldTransform; // eax
  CBaseEntity *v6; // edi
  int v7; // [esp-Ch] [ebp-7Ch] BYREF
  matrix3x4a_t scratchSpace; // [esp+0h] [ebp-70h] BYREF
  CBaseEntity *m_pEntity; // [esp+60h] [ebp-10h]
  int v10; // [esp+64h] [ebp-Ch]
  void *v11; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  v10 = a2;
  v11 = retaddr;
  if ( (this->m_iEFlags & 0x800) != 0 )
  {
    this->m_iEFlags &= ~0x800u;
    p_m_angRotation = &this->m_angRotation;
    AngleMatrix(
      angles: &this->m_angRotation.m_Value,
      position: &this->m_vecOrigin.m_Value,
      matrix: &this->m_rgflCoordinateFrame);
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
    {
      ParentToWorldTransform = CBaseEntity::GetParentToWorldTransform(this, tempMatrix: (matrix3x4_t *)&v7);
      ConcatTransforms(
        in1: ParentToWorldTransform,
        in2: &this->m_rgflCoordinateFrame,
        out: (matrix3x4a_t *)&scratchSpace.m_flMatVal[2][1]);
      MatrixCopy(in: (matrix3x4a_t *)&scratchSpace.m_flMatVal[2][1], out: &this->m_rgflCoordinateFrame);
      MatrixGetColumn(in: &this->m_rgflCoordinateFrame, column: 3, out: &this->m_vecAbsOrigin);
      if ( vec3_angle.x == p_m_angRotation->m_Value.x
        && vec3_angle.y == this->m_angRotation.m_Value.y
        && vec3_angle.z == this->m_angRotation.m_Value.z
        && this->m_iParentAttachment.m_Value == 0 )
      {
        v6 = m_pEntity;
        if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: m_pEntity);
        this->m_angAbsRotation.x = v6->m_angAbsRotation.x;
        this->m_angAbsRotation.y = v6->m_angAbsRotation.y;
        this->m_angAbsRotation.z = v6->m_angAbsRotation.z;
      }
      else
      {
        MatrixAngles(
          a1: (int)this,
          src: (const VMatrix *)&this->m_rgflCoordinateFrame,
          vAngles: &this->m_angAbsRotation);
      }
    }
    else
    {
      this->m_vecAbsOrigin.x = this->m_vecOrigin.m_Value.x;
      this->m_vecAbsOrigin.y = this->m_vecOrigin.m_Value.y;
      this->m_vecAbsOrigin.z = this->m_vecOrigin.m_Value.z;
      this->m_angAbsRotation.x = p_m_angRotation->m_Value.x;
      this->m_angAbsRotation.y = this->m_angRotation.m_Value.y;
      this->m_angAbsRotation.z = this->m_angRotation.m_Value.z;
    }
    if ( CBaseEntity::HasDataObjectType(this, type: 4) )
      ReportPositionChanged(pMovedEntity: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA450
// Name: private: void CBaseEntity::CalcAbsoluteVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseEntity::CalcAbsoluteVelocity(CBaseEntity *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax
  CBaseEntity **v4; // ecx
  CBaseEntity *v5; // esi

  if ( (this->m_iEFlags & 0x1000) != 0 )
  {
    this->m_iEFlags &= ~0x1000u;
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && (v4 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (v5 = *v4, *v4 != nullptr) )
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: *v4, a2);
      VectorRotate(in1: &this->m_vecVelocity.m_Value.x, in2: &v5->m_rgflCoordinateFrame, out: &this->m_vecAbsVelocity.x);
      if ( (v5->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: v5);
      this->m_vecAbsVelocity.x = v5->m_vecAbsVelocity.x + this->m_vecAbsVelocity.x;
      this->m_vecAbsVelocity.y = v5->m_vecAbsVelocity.y + this->m_vecAbsVelocity.y;
      this->m_vecAbsVelocity.z = v5->m_vecAbsVelocity.z + this->m_vecAbsVelocity.z;
    }
    else
    {
      this->m_vecAbsVelocity.x = this->m_vecVelocity.m_Value.x;
      this->m_vecAbsVelocity.y = this->m_vecVelocity.m_Value.y;
      this->m_vecAbsVelocity.z = this->m_vecVelocity.m_Value.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA550
// Name: public: char const __near * CBaseEntity::GetContextValue(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::GetContextValue(CBaseEntity *this, int index)
{
  const char *result; // eax

  if ( index < 0 )
    return locale;
  if ( index >= this->m_ResponseContexts.m_Size )
    return locale;
  result = this->m_ResponseContexts.m_Memory.m_pMemory[index].m_iszValue.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BA580
// Name: public: int CBaseEntity::FindContextByName(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::FindContextByName(CBaseEntity *this, const char *name)
{
  int v3; // esi
  int i; // edi
  const char *pszValue; // eax
  int c; // [esp+Ch] [ebp-4h]

  v3 = 0;
  c = this->m_ResponseContexts.m_Size;
  if ( c <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    if ( v3 < 0
      || v3 >= this->m_ResponseContexts.m_Size
      || (pszValue = this->m_ResponseContexts.m_Memory.m_pMemory[i].m_iszName.pszValue) == nullptr )
    {
      pszValue = locale;
    }
    if ( name == pszValue || _V_stricmp(s1: name, s2: pszValue) == 0 )
      break;
    if ( ++v3 >= c )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100BA600
// Name: public: bool CBaseEntity::CallScriptFunction(char const __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::CallScriptFunction(
        CBaseEntity *this,
        const char *pFunctionName,
        ScriptVariant_t *pFunctionReturn)
{
  HSCRIPT__ *v5; // esi

  if ( CBaseEntity::ValidateScriptScope(this) != 0 )
  {
    v5 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: pFunctionName, a3: this->m_ScriptScope.m_hScope);
    if ( v5 != nullptr )
    {
      g_pScriptVM->ExecuteFunction(
        this: g_pScriptVM,
        a2: v5,
        a3: nullptr,
        a4: 0,
        a5: pFunctionReturn,
        a6: this->m_ScriptScope.m_hScope,
        a7: true);
      g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v5);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    DevMsg(a1: "\n***\nFAILED to create private ScriptScope. ABORTING script\n***\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA680
// Name: public: void CBaseEntity::ScriptThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ScriptThink(CBaseEntity *this)
{
  const char *pszValue; // eax
  float m_fValue; // xmm0_4
  const char *v4; // eax
  const char *DebugName; // eax
  const char *v6; // [esp+4h] [ebp-14h]
  ScriptVariant_t varThinkRetVal; // [esp+Ch] [ebp-Ch] BYREF
  float flThinkFrequency; // [esp+14h] [ebp-4h] BYREF

  *(_DWORD *)&varThinkRetVal.m_type = 0;
  varThinkRetVal.m_int = 0;
  pszValue = this->m_iszScriptThinkFunction.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( CBaseEntity::CallScriptFunction(this, pFunctionName: pszValue, pFunctionReturn: &varThinkRetVal) != 0 )
  {
    flThinkFrequency = 0.0;
    if ( ScriptVariant_t::AssignTo(this: &varThinkRetVal, pDest: &flThinkFrequency) )
      m_fValue = flThinkFrequency;
    else
      m_fValue = sv_script_think_interval.m_pParent->m_Value.m_fValue;
    CBaseEntity::ThinkSet(
      this,
      func: CBaseEntity::ScriptThink,
      thinkTime: gpGlobals->curtime + m_fValue,
      szContext: "ScriptThink");
  }
  else
  {
    v4 = this->m_iszScriptThinkFunction.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    v6 = v4;
    DebugName = CBaseEntity::GetDebugName(this);
    DevWarning(a1: "%s FAILED to call script think function %s!\n", DebugName, v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA730
// Name: public: struct HSCRIPT__ __near * CBaseEntity::ScriptGetMoveParent(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseEntity::ScriptGetMoveParent(CBaseEntity *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return CBaseEntity::GetScriptInstance(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA770
// Name: public: struct HSCRIPT__ __near * CBaseEntity::ScriptGetRootMoveParent(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseEntity::ScriptGetRootMoveParent(CBaseEntity *this)
{
  CBaseEntity *RootMoveParent; // eax

  RootMoveParent = CBaseEntity::GetRootMoveParent(this);
  if ( RootMoveParent != nullptr )
    return CBaseEntity::GetScriptInstance(this: RootMoveParent);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BA790
// Name: public: struct HSCRIPT__ __near * CBaseEntity::ScriptFirstMoveChild(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseEntity::ScriptFirstMoveChild(CBaseEntity *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_hMoveChild.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return CBaseEntity::GetScriptInstance(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA7D0
// Name: public: struct HSCRIPT__ __near * CBaseEntity::ScriptNextMovePeer(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseEntity::ScriptNextMovePeer(CBaseEntity *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_hMovePeer.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return CBaseEntity::GetScriptInstance(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA810
// Name: public: struct HSCRIPT__ __near * CBaseEntity::GetScriptOwnerEntity(void)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CBaseEntity::GetScriptOwnerEntity(CBaseEntity *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return CBaseEntity::GetScriptInstance(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA850
// Name: public: void CBaseEntity::RecalcHasPlayerChildBit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RecalcHasPlayerChildBit(CBaseEntity *this)
{
  if ( AnyPlayersInHierarchy_R(pEnt: this) != 0 )
    this->m_iEFlags |= 0x10000u;
  else
    this->m_iEFlags &= ~0x10000u;
}

//------------------------------------------------------------------------------
// Address: 0x100BA880
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseEntity::NetworkVar_m_hOwnerEntity>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hOwnerEntity>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hOwnerEntity> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hOwnerEntity> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 80;
    if ( *((_BYTE *)this - 236) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x140u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x100BB3E0
// Name: public: virtual int CBaseEntity::TakeHealth(float,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::TakeHealth(CBaseEntity *this, float flHealth, int bitsDamageType)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // esi
  int v4; // ebx
  int m_Value; // eax
  int v7; // edi
  int v8; // [esp+4h] [ebp-4h]

  if ( this->m_Network.m_pPev == nullptr || this->m_takedamage.m_Value < 2 )
    return 0;
  p_m_iHealth = &this->m_iHealth;
  v4 = this->GetMaxHealth(this);
  m_Value = p_m_iHealth->m_Value;
  v8 = p_m_iHealth->m_Value;
  if ( p_m_iHealth->m_Value >= v4 )
    return 0;
  v7 = m_Value + (int)flHealth;
  if ( m_Value != v7 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *, CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *))(p_m_iHealth[-132].m_Value + 732))(
      a1: p_m_iHealth - 132,
      a2: p_m_iHealth);
    p_m_iHealth->m_Value = v7;
  }
  if ( p_m_iHealth->m_Value > v4 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *, CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *))(p_m_iHealth[-132].m_Value + 732))(
      a1: p_m_iHealth - 132,
      a2: p_m_iHealth);
    p_m_iHealth->m_Value = v4;
  }
  return p_m_iHealth->m_Value - v8;
}

//------------------------------------------------------------------------------
// Address: 0x100BB480
// Name: public: virtual int CBaseEntity::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::OnTakeDamage(CBaseEntity *this, const CTakeDamageInfo *info)
{
  const CTakeDamageInfo *v3; // edi
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // edi
  const Vector *v12; // ebx
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  unsigned __int8 m_Value; // bl
  CBaseEntity *Inflictor; // eax
  float *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm3_4
  float *p_y; // ebx
  const Vector *v23; // eax
  float v24; // xmm0_4
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // ebx
  int v26; // edi
  Vector vecImpulse; // [esp+4h] [ebp-20h] BYREF
  Vector vecDir; // [esp+10h] [ebp-14h] BYREF
  float m_flDamage; // [esp+1Ch] [ebp-8h]
  float v31; // [esp+20h] [ebp-4h]

  if ( this->m_Network.m_pPev == nullptr || this->m_takedamage.m_Value == 0 )
    return 0;
  v3 = info;
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index != -1
    && (v5 = (unsigned __int16)m_Index,
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v7 = HIWORD(m_Index),
        v6->m_SerialNumber == v7)
    && v6->m_pEntity != nullptr )
  {
    v8 = v5;
    v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
    v10 = &g_pEntityList->m_EntPtrArray[v8];
    if ( v9 )
      m_pEntity = v10->m_pEntity;
    else
      m_pEntity = nullptr;
    v12 = this->WorldSpaceCenter(this);
    v13 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: m_pEntity);
    v14 = *v13 - v12->x;
    v15 = v13[1] - v12->y;
    v16 = v13[2] - v12->z;
    v3 = info;
  }
  else
  {
    v15 = 0.0;
    v14 = 1.0;
    v16 = 0.0;
  }
  g_vecAttackDir.x = v14;
  g_vecAttackDir.y = v15;
  g_vecAttackDir.z = v16;
  VectorNormalize(vec: &g_vecAttackDir);
  if ( this->m_iEFlags >= 0 )
  {
    m_Value = this->m_MoveType.m_Value;
    if ( m_Value == 6 )
    {
      this->VPhysicsTakeDamage(this, a2: v3);
    }
    else if ( CTakeDamageInfo::GetInflictor(this: v3) != nullptr
           && (m_Value == 2 || m_Value == 3)
           && (CTakeDamageInfo::GetAttacker(this: v3)->m_Collision.m_usSolidFlags.m_Value & 8) == 0 )
    {
      vecDir = *this->WorldSpaceCenter(this);
      Inflictor = CTakeDamageInfo::GetInflictor(this: v3);
      v19 = (float *)Inflictor->WorldSpaceCenter(this: Inflictor);
      v20 = v19[2];
      v21 = vecDir.x - *v19;
      vecDir.y = vecDir.y - v19[1];
      vecDir.x = v21;
      vecDir.z = vecDir.z - v20;
      VectorNormalize(vec: &vecDir);
      m_flDamage = v3->m_flDamage;
      p_y = &CBaseEntity::WorldAlignSize(this)->y;
      v31 = *p_y * CBaseEntity::WorldAlignSize(this)->x;
      v23 = CBaseEntity::WorldAlignSize(this);
      v24 = 73728.0 / (float)(v23->z * v31) * m_flDamage * 5.0;
      if ( v24 > 1000.0 )
        v24 = 1000.0;
      vecImpulse.x = vecDir.x * v24;
      vecImpulse.y = vecDir.y * v24;
      vecImpulse.z = vecDir.z * v24;
      CBaseEntity::ApplyAbsVelocityImpulse(this, &vecImpulse);
    }
  }
  if ( this->m_takedamage.m_Value == 1 )
    return 1;
  p_m_iHealth = &this->m_iHealth;
  v26 = this->m_iHealth.m_Value - (int)v3->m_flDamage;
  if ( this->m_iHealth.m_Value != v26 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = v26;
  }
  if ( p_m_iHealth->m_Value > 0 )
    return 1;
  this->Event_Killed(this, a2: info);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BB750
// Name: public: virtual void CBaseEntity::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::Event_Killed(CBaseEntity *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // ecx

  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        m_pEntity = v9->m_pEntity;
      else
        m_pEntity = nullptr;
      ((void (__thiscall *)(IHandleEntity *, CBaseEntity *, const CTakeDamageInfo *))m_pEntity->__vftable[23].SetRefEHandle)(
        a1: m_pEntity,
        a2: this,
        a3: info);
    }
  }
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  if ( this->m_lifeState.m_Value != 2 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 2;
  }
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x100BB810
// Name: private: virtual void CThinkContextsSaveDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThinkContextsSaveDataOps::Save(
        CThinkContextsSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  const SaveRestoreFieldInfo_t *v3; // edi
  _DWORD *pField; // ebx
  ISave *v5; // esi
  void (__thiscall *v6)(int *, _DWORD *, ISave *); // eax
  void (__thiscall *StartBlock)(ISave *); // eax
  _DWORD *v8; // edi
  void (__thiscall *WriteBool_2)(ISave *, const bool *, int); // edx
  ISave_vtbl *v10; // ebx
  int v11; // eax
  _DWORD v12[3]; // [esp+Ch] [ebp-18h] BYREF
  CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *pUtlVector; // [esp+18h] [ebp-Ch]
  CBaseEntity *pOwner; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v3 = fieldInfo;
  pField = fieldInfo->pField;
  pUtlVector = (CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *)fieldInfo->pField;
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>,10>::`vftable';
  }
  v5 = pSave;
  v12[1] = 0;
  v12[2] = 0;
  v6 = *(void (__thiscall **)(int *, _DWORD *, ISave *))`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::ops;
  v12[0] = pField;
  v6(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::ops,
    a2: v12,
    a3: pSave);
  StartBlock = v5->StartBlock;
  pOwner = (CBaseEntity *)v3->pOwner;
  StartBlock(this: v5);
  i = 0;
  if ( (int)pField[3] > 0 )
  {
    pSave = nullptr;
    do
    {
      v8 = (ISave_vtbl **)((char *)&pSave->__vftable + *pField);
      WriteBool_2 = v5->WriteBool_2;
      HIBYTE(fieldInfo) = *v8 != 0;
      WriteBool_2(this: v5, a2: (const bool *)&fieldInfo + 3, a3: 1);
      if ( HIBYTE(fieldInfo) != 0 )
      {
        v10 = v5->__vftable;
        v11 = ((int (__thiscall *)(CBaseEntity *, const char *, _DWORD *, int))pOwner->GetDataDescMap)(
                a1: pOwner,
                a2: "m_pfnThink",
                a3: v8,
                a4: 1);
        ((void (__thiscall *)(ISave *, int))v10->WriteFunction)(a1: v5, a2: v11);
        pField = &pUtlVector->m_Memory.m_pMemory;
      }
      pSave += 4;
      ++i;
    }
    while ( i < pField[3] );
  }
  v5->EndBlock(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100BB8F0
// Name: private: virtual void CThinkContextsSaveDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThinkContextsSaveDataOps::Restore(
        CThinkContextsSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  const SaveRestoreFieldInfo_t *v3; // edi
  _DWORD *pField; // ebx
  IRestore *v5; // esi
  void (__thiscall *v6)(int *, _DWORD *, IRestore *); // eax
  void (__thiscall *StartBlock)(IRestore *); // eax
  _DWORD *v8; // edi
  IRestore_vtbl *v9; // ebx
  int v10; // eax
  _DWORD v11[3]; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *pUtlVector; // [esp+18h] [ebp-10h]
  CBaseEntity *pOwner; // [esp+1Ch] [ebp-Ch]
  SaveRestoreRecordHeader_t header; // [esp+20h] [ebp-8h] BYREF
  int i; // [esp+24h] [ebp-4h]

  v3 = fieldInfo;
  pField = fieldInfo->pField;
  pUtlVector = (CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *)fieldInfo->pField;
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>,10>::`vftable';
  }
  v5 = pRestore;
  v11[1] = 0;
  v11[2] = 0;
  v6 = *(void (__thiscall **)(int *, _DWORD *, IRestore *))(`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::ops
                                                          + 4);
  v11[0] = pField;
  v6(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>>'::`2'::ops,
    a2: v11,
    a3: pRestore);
  StartBlock = v5->StartBlock;
  pOwner = (CBaseEntity *)v3->pOwner;
  StartBlock(this: v5);
  i = 0;
  if ( (int)pField[3] > 0 )
  {
    pRestore = nullptr;
    do
    {
      v5->ReadBool(this: v5, a2: (bool *)&fieldInfo + 3, a3: 1, a4: 0);
      v8 = (IRestore_vtbl **)((char *)&pRestore->__vftable + *pField);
      if ( HIBYTE(fieldInfo) != 0 )
      {
        v5->ReadHeader(this: v5, a2: &header);
        v9 = v5->__vftable;
        v10 = ((int (__thiscall *)(CBaseEntity *, _DWORD *, int, _DWORD))pOwner->GetDataDescMap)(
                a1: pOwner,
                a2: v8,
                a3: 1,
                a4: header.size);
        ((void (__thiscall *)(IRestore *, int))v9->ReadFunction)(a1: v5, a2: v10);
        pField = &pUtlVector->m_Memory.m_pMemory;
      }
      else
      {
        *v8 = 0;
      }
      pRestore += 4;
      ++i;
    }
    while ( i < pField[3] );
  }
  v5->EndBlock(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100BB9E0
// Name: public: virtual void CBaseEntity::OnSave(class IEntitySaveUtils __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::OnSave(CBaseEntity *this@<ecx>, int a2@<ebp>, IEntitySaveUtils *pUtils)
{
  CBaseEntity::CalcAbsolutePosition(this, a2);
  CBaseEntity::CalcAbsoluteVelocity(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100BBA00
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBA40
// Name: public: bool CBaseEntity::DetectInSkybox(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::DetectInSkybox(CBaseEntity *this)
{
  if ( CBaseEntity::GetEntitySkybox(this) != nullptr )
  {
    this->m_iEFlags |= 0x20000u;
    if ( this->m_nTransmitStateOwnedCounter == 0 )
    {
      ++g_nInsideDispatchUpdateTransmitState;
      this->UpdateTransmitState(this);
      --g_nInsideDispatchUpdateTransmitState;
    }
    return 1;
  }
  else
  {
    this->m_iEFlags &= ~0x20000u;
    if ( this->m_nTransmitStateOwnedCounter == 0 )
    {
      ++g_nInsideDispatchUpdateTransmitState;
      this->UpdateTransmitState(this);
      --g_nInsideDispatchUpdateTransmitState;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBAB0
// Name: public: void CBaseEntity::InputEnableDamageForces(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputEnableDamageForces(CBaseEntity *this, inputdata_t *inputdata)
{
  this->m_iEFlags &= ~0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x100BBAC0
// Name: public: void CBaseEntity::InputDisableDamageForces(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputDisableDamageForces(CBaseEntity *this, inputdata_t *inputdata)
{
  this->m_iEFlags |= 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x100BBAD0
// Name: public: void CBaseEntity::SetMaxHealth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetMaxHealth(CBaseEntity *this, int amt)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iMaxHealth> *p_m_iMaxHealth; // esi

  p_m_iMaxHealth = &this->m_iMaxHealth;
  if ( this->m_iMaxHealth.m_Value != amt )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    p_m_iMaxHealth->m_Value = amt;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBB10
// Name: public: void CBaseEntity::SetBaseVelocity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetBaseVelocity(CBaseEntity *this, const Vector *v)
{
  CNetworkVectorBase<Vector,CBaseEntity::NetworkVar_m_vecBaseVelocity> *p_m_vecBaseVelocity; // esi

  p_m_vecBaseVelocity = &this->m_vecBaseVelocity;
  if ( v->x != this->m_vecBaseVelocity.m_Value.x
    || v->y != this->m_vecBaseVelocity.m_Value.y
    || v->z != this->m_vecBaseVelocity.m_Value.z )
  {
    this->NetworkStateChanged_m_vecBaseVelocity(this, a2: &this->m_vecBaseVelocity);
    p_m_vecBaseVelocity->m_Value = *v;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBB80
// Name: public: void CBaseEntity::SetLocalVelocity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetLocalVelocity(CBaseEntity *this, const Vector *vecVelocity)
{
  CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecVelocity> *p_m_vecVelocity; // edi

  p_m_vecVelocity = &this->m_vecVelocity;
  if ( vecVelocity->x != this->m_vecVelocity.m_Value.x
    || vecVelocity->y != this->m_vecVelocity.m_Value.y
    || vecVelocity->z != this->m_vecVelocity.m_Value.z )
  {
    CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 4);
    (*(void (__thiscall **)(float *, CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecVelocity> *))(LODWORD(p_m_vecVelocity[-41].m_Value.z) + 716))(
      a1: &p_m_vecVelocity[-41].m_Value.z,
      a2: p_m_vecVelocity);
    (*(void (__thiscall **)(float *, float *))(LODWORD(p_m_vecVelocity[-41].m_Value.z) + 716))(
      a1: &p_m_vecVelocity[-41].m_Value.z,
      a2: &p_m_vecVelocity->m_Value.y);
    (*(void (__thiscall **)(float *, float *))(LODWORD(p_m_vecVelocity[-41].m_Value.z) + 716))(
      a1: &p_m_vecVelocity[-41].m_Value.z,
      a2: &p_m_vecVelocity->m_Value.z);
    p_m_vecVelocity->m_Value = *vecVelocity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBC40
// Name: protected: void CBaseEntity::RemoveExpiredConcepts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RemoveExpiredConcepts(CBaseEntity *this)
{
  int m_Size; // ecx
  int v3; // edi
  int v4; // ebx
  float m_fExpirationTime; // xmm0_4
  int c; // [esp+8h] [ebp-4h]

  m_Size = this->m_ResponseContexts.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( v3 < 0
        || v3 >= this->m_ResponseContexts.m_Size
        || (m_fExpirationTime = this->m_ResponseContexts.m_Memory.m_pMemory[v4].m_fExpirationTime) != 0.0
        && gpGlobals->curtime >= m_fExpirationTime )
      {
        if ( this->m_ResponseContexts.m_Size - v3 - 1 > 0 )
        {
          _V_memmove(
            dest: &this->m_ResponseContexts.m_Memory.m_pMemory[v4],
            src: &this->m_ResponseContexts.m_Memory.m_pMemory[v4 + 1],
            count: 12 * (this->m_ResponseContexts.m_Size - v3 - 1));
          m_Size = c;
        }
        --this->m_ResponseContexts.m_Size;
        --m_Size;
        --v3;
        c = m_Size;
        --v4;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBCE0
// Name: public: void CBaseEntity::InputRunScriptFile(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputRunScriptFile(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // esi

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( iVal != nullptr )
      v5 = iVal;
    else
      v5 = locale;
  }
  else
  {
    v5 = variant_t::ToString(this: p_value);
  }
  if ( CBaseEntity::ValidateScriptScope(this) != 0 )
    VScriptRunScript(
      pszScriptName: v5,
      hScope: this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr,
      bWarnMissing: true);
  else
    DevMsg(a1: "\n***\nFAILED to create private ScriptScope. ABORTING script\n***\n");
}

//------------------------------------------------------------------------------
// Address: 0x100BBD50
// Name: public: void CBaseEntity::InputCallScriptFunction(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputCallScriptFunction(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CBaseEntity::CallScriptFunction(this, pFunctionName: locale, pFunctionReturn: nullptr);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CBaseEntity::CallScriptFunction(this, pFunctionName: iVal, pFunctionReturn: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100BBD90
// Name: public: void CBaseEntity::InputRemoveContext(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputRemoveContext(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  int ContextByName; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  ContextByName = CBaseEntity::FindContextByName(this, name: iVal);
  if ( ContextByName != -1 )
  {
    if ( this->m_ResponseContexts.m_Size - ContextByName - 1 > 0 )
      _V_memmove(
        dest: &this->m_ResponseContexts.m_Memory.m_pMemory[ContextByName],
        src: &this->m_ResponseContexts.m_Memory.m_pMemory[ContextByName + 1],
        count: 12 * (this->m_ResponseContexts.m_Size - ContextByName - 1));
    --this->m_ResponseContexts.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBE00
// Name: public: void CBaseEntity::InputClearContext(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputClearContext(CBaseEntity *this, inputdata_t *inputdata)
{
  this->m_ResponseContexts.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BBE10
// Name: public: void CBaseEntity::SUB_Vanish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SUB_Vanish(CBaseEntity *this)
{
  int v2; // ebx
  CBasePlayer *v3; // edi
  float *v4; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm0_4
  Vector plForward; // [esp+18h] [ebp-18h] BYREF
  Vector corpseDir; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  v2 = 1;
  if ( gpGlobals->maxClients < 1 )
  {
LABEL_9:
    if ( this->m_iHealth.m_Value != 0 )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = 0;
    }
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  }
  else
  {
    while ( 1 )
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      if ( v3 != nullptr )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v4 = (float *)v3->WorldSpaceCenter(this: v3);
        y = this->m_vecAbsOrigin.y;
        z = this->m_vecAbsOrigin.z;
        corpseDir.x = this->m_vecAbsOrigin.x - *v4;
        corpseDir.y = y - v4[1];
        corpseDir.z = z - v4[2];
        v7 = (float)((float)(corpseDir.x * corpseDir.x) + (float)(corpseDir.y * corpseDir.y))
           + (float)(corpseDir.z * corpseDir.z);
        if ( v7 < 65536.0 )
          break;
        if ( v7 < 2250000.0 )
        {
          VectorNormalize(vec: &corpseDir);
          CBasePlayer::EyeVectors(this: v3, pForward: &plForward, pRight: nullptr, pUp: nullptr);
          if ( (float)((float)((float)(plForward.x * corpseDir.x) + (float)(plForward.y * corpseDir.y))
                     + (float)(corpseDir.z * plForward.z)) > 0.0 )
            break;
        }
      }
      if ( ++v2 > gpGlobals->maxClients )
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBF90
// Name: public: void CBaseEntity::SetFriction(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetFriction(CBaseEntity *this, float flFriction)
{
  CNetworkVarBase<float,CBaseEntity::NetworkVar_m_flFriction> *p_m_flFriction; // esi

  p_m_flFriction = &this->m_flFriction;
  if ( this->m_flFriction.m_Value != flFriction )
  {
    this->NetworkStateChanged_m_flFriction(this, a2: &this->m_flFriction);
    p_m_flFriction->m_Value = flFriction;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD420
// Name: public: void CBaseEntity::SetGlobalFadeScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetGlobalFadeScale(CBaseEntity *this, float flFadeScale)
{
  CNetworkVarBase<float,CBaseEntity::NetworkVar_m_flFadeScale> *p_m_flFadeScale; // esi
  edict_t *m_pPev; // ecx

  p_m_flFadeScale = &this->m_flFadeScale;
  if ( this->m_flFadeScale.m_Value != flFadeScale )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFadeScale->m_Value = flFadeScale;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x310u);
      p_m_flFadeScale->m_Value = flFadeScale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD480
// Name: public: void CBaseEntity::SendDebugPivotOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseEntity::SendDebugPivotOverlay(CBaseEntity *this@<ecx>, int a2@<ebp>)
{
  if ( this->m_Network.m_pPev != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    NDebugOverlay::Axis(
      position: &this->m_vecAbsOrigin,
      angles: &this->m_angAbsRotation,
      size: 20.0,
      noDepthTest: true,
      flDuration: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD4F0
// Name: public: void CBaseEntity::DrawVPhysicsObjectCenterAndContactPoints(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBaseEntity::DrawVPhysicsObjectCenterAndContactPoints(
        CBaseEntity *this@<ecx>,
        float a2@<ebp>,
        IPhysicsObject *obj)
{
  __int128 v4; // xmm0
  unsigned int v5; // ecx
  IPhysicsCollision_vtbl *v6; // edi
  int v7; // eax
  const Vector *v8; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v9; // edx
  float z; // xmm0_4
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  Vector v12; // [esp+38h] [ebp-68h] BYREF
  Vector axis; // [esp+44h] [ebp-5Ch] BYREF
  Vector worldPos; // [esp+50h] [ebp-50h] BYREF
  Vector massCenter; // [esp+5Ch] [ebp-44h] BYREF
  QAngle angles; // [esp+68h] [ebp-38h] BYREF
  __int128 pos; // [esp+74h] [ebp-2Ch] OVERLAPPED BYREF
  Vector mins; // [esp+84h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+90h] [ebp-10h] BYREF
  float retaddr; // [esp+A0h] [ebp+0h]

  maxs.y = a2;
  maxs.z = retaddr;
  if ( obj != nullptr )
  {
    obj->GetMassCenterLocalSpace(this: obj, result: &worldPos);
    obj->LocalToWorld(this: obj, a2: &axis, a3: &worldPos);
    NDebugOverlay::Cross3D(position: &axis, size: 12.0, r: 255, g: 0, b: 0, noDepthTest: false, flDuration: 0.0);
    DebugDrawContactPoints(pPhysics: obj);
    if ( this->m_MoveType.m_Value != 6 )
    {
      obj->GetPosition(this: obj, a2: (Vector *)&angles, a3: (QAngle *)&massCenter);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&maxs.y);
      v4 = 0;
      v5 = (unsigned int)this->m_iEFlags >> 11;
      *(float *)&v4 = fsqrt(
                        (float)((float)((float)(angles.y - this->m_vecAbsOrigin.y)
                                      * (float)(angles.y - this->m_vecAbsOrigin.y))
                              + (float)((float)(angles.z - this->m_vecAbsOrigin.z)
                                      * (float)(angles.z - this->m_vecAbsOrigin.z)))
                      + (float)((float)(angles.x - this->m_vecAbsOrigin.x) * (float)(angles.x - this->m_vecAbsOrigin.x)));
      pos = v4;
      if ( (v5 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&maxs.y);
      RotationDeltaAxisAngle(
        srcAngles: (const QAngle *)&massCenter,
        destAngles: &this->m_angAbsRotation,
        deltaAxis: &v12,
        deltaAngle: &maxs.x);
      if ( *(float *)&pos > 2.0 || COERCE_FLOAT(LODWORD(maxs.x) & _mask__AbsFloat_) > 2.0 )
      {
        if ( obj->GetCollide(this: obj) != nullptr )
        {
          v6 = physcollision->__vftable;
          v7 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *))obj->GetCollide)(
                 a1: obj,
                 a2: &vec3_origin,
                 a3: &vec3_angle);
          ((void (__thiscall *)(IPhysicsCollision *, char *, Vector *, int))v6->CollideGetAABB)(
            a1: physcollision,
            a2: (char *)&pos + 4,
            a3: &mins,
            a4: v7);
        }
        else
        {
          v8 = this->m_Collision.OBBMins(this: &this->m_Collision);
          v9 = this->m_Collision.__vftable;
          *(_QWORD *)((char *)&pos + 4) = *(_QWORD *)&v8->x;
          z = v8->z;
          OBBMins = v9->OBBMins;
          *((float *)&pos + 3) = z;
          mins = *OBBMins(this: &this->m_Collision);
        }
        NDebugOverlay::BoxAngles(
          origin: (const Vector *)&angles,
          mins: (const Vector *)((char *)&pos + 4),
          maxs: &mins,
          angles: (const QAngle *)&massCenter,
          r: 255,
          g: 255,
          b: 0,
          a: 16,
          duration: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD720
// Name: public: virtual void CBaseEntity::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DrawDebugGeometryOverlays(CBaseEntity *this)
{
  const char *DebugName; // eax
  int v3; // ebx
  int i; // edi
  CBaseCombatCharacter *v5; // ebx
  int v6; // edi
  int v7; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax
  double v9; // st7
  bool (__thiscall *ShouldAttractAutoAim)(CBaseEntity *, CBaseEntity *); // eax
  float v11; // xmm3_4
  IPhysicsObject *obj[1024]; // [esp+20h] [ebp-105Ch] BYREF
  QAngle angles; // [esp+1020h] [ebp-5Ch] BYREF
  Vector v14; // [esp+102Ch] [ebp-50h] BYREF
  Vector up; // [esp+1038h] [ebp-44h] BYREF
  Vector right; // [esp+1044h] [ebp-38h] BYREF
  Vector vec; // [esp+1050h] [ebp-2Ch] BYREF
  CBasePlayer *LocalPlayer; // [esp+105Ch] [ebp-20h]
  Vector origin; // [esp+1060h] [ebp-1Ch] BYREF
  Vector target; // [esp+106Ch] [ebp-10h] BYREF
  float v21; // [esp+1078h] [ebp-4h]
  int savedregs; // [esp+107Ch] [ebp+0h] BYREF

  CBaseEntity::DrawTimedOverlays(this);
  this->DrawDebugTextOverlays(this);
  if ( (this->m_debugOverlays & 2) != 0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    CBaseEntity::EntityText(this, text_offset: 0, text: DebugName, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
  }
  if ( (this->m_debugOverlays & 4) != 0 )
    CBaseEntity::DrawBBoxOverlay(this, flDuration: 0.0);
  if ( (this->m_debugOverlays & 0x20) != 0 )
    CBaseEntity::DrawAbsBoxOverlay(this);
  if ( (this->m_debugOverlays & 8) != 0 )
    CBaseEntity::SendDebugPivotOverlay(this, a2: (int)&savedregs);
  if ( (this->m_debugOverlays & 0xC) != 0 )
  {
    CBaseEntity::DrawVPhysicsObjectCenterAndContactPoints(
      this,
      a2: COERCE_FLOAT(&savedregs),
      obj: this->m_pPhysicsObject);
    v3 = this->VPhysicsGetObjectList(this, a2: obj, a3: 1024);
    for ( i = 0; i < v3; ++i )
      CBaseEntity::DrawVPhysicsObjectCenterAndContactPoints(this, a2: COERCE_FLOAT(&savedregs), obj: obj[i]);
  }
  if ( SLOBYTE(this->m_debugOverlays) < 0 && CBaseEntity::BlocksLOS(this) )
    NDebugOverlay::EntityBounds(pEntity: this, r: 255, g: 255, b: 255, a: 0, flDuration: 0.0);
  if ( (this->m_debugOverlays & 0x200) != 0
    && (this->m_fFlags.m_Value & 0x20000) != 0
    && gpGlobals->maxClients <= 1
    && UTIL_GetLocalPlayer() != nullptr )
  {
    this->GetAutoAimCenter(this, result: &origin);
    if ( gpGlobals->maxClients <= 1 )
    {
      LocalPlayer = UTIL_GetLocalPlayer();
      v5 = LocalPlayer;
    }
    else
    {
      v5 = nullptr;
    }
    v21 = this->GetAutoAimRadius(this);
    angles = *v5->EyeAngles(this: v5);
    AngleVectors(&angles, forward: nullptr, &right, &up);
    if ( (int)gpGlobals->curtime % 2 == 1 )
    {
      v6 = 255;
      v7 = 255;
      if ( CBaseCombatCharacter::GetActiveWeapon(this: v5) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v5);
        v9 = ((double (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->WeaponAutoAimScale)(a1: ActiveWeapon);
        v21 = v9 * v21;
      }
    }
    else
    {
      ShouldAttractAutoAim = this->ShouldAttractAutoAim;
      v6 = 0;
      LocalPlayer = nullptr;
      if ( ShouldAttractAutoAim(this, a2: v5) )
      {
        v7 = 0;
      }
      else
      {
        v7 = (int)LocalPlayer;
        v6 = 255;
      }
    }
    if ( v5->IsInAVehicle(this: v5) )
    {
      v11 = sv_vehicle_autoaim_scale.m_pParent->m_Value.m_fValue * v21;
      v21 = v11;
    }
    else
    {
      v11 = v21;
    }
    target.y = origin.y + (float)(right.y * v11);
    target.z = origin.z + (float)(right.z * v11);
    target.x = origin.x + (float)(right.x * v11);
    NDebugOverlay::Line(&origin, &target, r: 255, g: v6, b: v7, noDepthTest: true, duration: 0.1);
    target.y = origin.y - (float)(right.y * v21);
    target.z = origin.z - (float)(right.z * v21);
    target.x = origin.x - (float)(right.x * v21);
    NDebugOverlay::Line(&origin, &target, r: 255, g: v6, b: v7, noDepthTest: true, duration: 0.1);
    target.x = (float)(up.x * v21) + origin.x;
    target.y = (float)(up.y * v21) + origin.y;
    target.z = (float)(up.z * v21) + origin.z;
    NDebugOverlay::Line(&origin, &target, r: 255, g: v6, b: v7, noDepthTest: true, duration: 0.1);
    target.y = origin.y - (float)(up.y * v21);
    target.z = origin.z - (float)(up.z * v21);
    target.x = origin.x - (float)(up.x * v21);
    NDebugOverlay::Line(&origin, &target, r: 255, g: v6, b: v7, noDepthTest: true, duration: 0.1);
    vec.x = up.x + right.x;
    vec.y = up.y + right.y;
    vec.z = up.z + right.z;
    VectorNormalize(&vec);
    target.x = (float)(vec.x * v21) + origin.x;
    target.y = (float)(vec.y * v21) + origin.y;
    target.z = (float)(vec.z * v21) + origin.z;
    v14.x = origin.x - (float)(vec.x * v21);
    v14.y = origin.y - (float)(vec.y * v21);
    v14.z = origin.z - (float)(vec.z * v21);
    NDebugOverlay::Line(origin: &v14, &target, r: 255, g: v6, b: v7, noDepthTest: true, duration: 0.1);
    vec.x = right.x - up.x;
    vec.y = right.y - up.y;
    vec.z = right.z - up.z;
    VectorNormalize(&vec);
    v14.x = (float)(vec.x * v21) + origin.x;
    v14.y = (float)(vec.y * v21) + origin.y;
    v14.z = (float)(vec.z * v21) + origin.z;
    target.x = origin.x - (float)(vec.x * v21);
    target.y = origin.y - (float)(vec.y * v21);
    target.z = origin.z - (float)(vec.z * v21);
    NDebugOverlay::Line(origin: &target, target: &v14, r: 255, g: v6, b: v7, noDepthTest: true, duration: 0.1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDCD0
// Name: public: virtual int CBaseEntity::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::DrawDebugTextOverlays(CBaseEntity *this)
{
  int v2; // edi
  const char *pszValue; // eax
  edict_t *m_pPev; // edi
  const char *DebugName; // eax
  int v6; // edi
  float z; // ecx
  int v8; // edi
  float v9; // edx
  int v10; // edi
  int m_cellwidth; // ecx
  float x; // xmm1_4
  __int64 v13; // rax
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float y; // xmm2_4
  __int64 v18; // rax
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  __int64 v23; // rax
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // ecx
  int v27; // edi
  const char *v28; // eax
  unsigned int m_Index; // ecx
  int v30; // eax
  CEntInfo *v31; // edx
  unsigned int v32; // ecx
  int v33; // eax
  bool v34; // zf
  CBaseEntity **v35; // eax
  CBaseEntity *v36; // ecx
  const char *v37; // eax
  int m_Size; // eax
  int v39; // ebx
  int v40; // edx
  const char *v41; // ecx
  const char *v42; // eax
  int v43; // edi
  const Vector *v44; // eax
  const char *flDuration_4; // [esp+1Ch] [ebp-220h]
  char tempstr[512]; // [esp+28h] [ebp-214h] BYREF
  int i; // [esp+228h] [ebp-14h]
  int count; // [esp+22Ch] [ebp-10h] BYREF
  Vector vecOrigin; // [esp+230h] [ebp-Ch] BYREF
  int savedregs; // [esp+23Ch] [ebp+0h] BYREF

  v2 = 1;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    flDuration_4 = pszValue;
    DebugName = CBaseEntity::GetDebugName(this);
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "(%d) Name: %s (%s)", m_pPev, DebugName, flDuration_4);
    CBaseEntity::EntityText(this, text_offset: 1, text: tempstr, duration: 0.0, r: 0, g: 255, b: 0, a: 255);
    v6 = 2;
    if ( this->m_iGlobalname.pszValue != nullptr )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "GLOBALNAME: %s", this->m_iGlobalname.pszValue);
      CBaseEntity::EntityText(this, text_offset: 2, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      v6 = 3;
    }
    if ( debug_overlay_fullposition.m_pParent != nullptr && debug_overlay_fullposition.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      z = this->m_vecAbsOrigin.z;
      *(_QWORD *)&vecOrigin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
      vecOrigin.z = z;
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "pos: (%f, %f, %f)\n", vecOrigin.x, vecOrigin.y, z);
      CBaseEntity::EntityText(this, text_offset: v6, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      v8 = v6 + 1;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v9 = this->m_angAbsRotation.z;
      *(_QWORD *)&vecOrigin.x = *(_QWORD *)&this->m_angAbsRotation.x;
      vecOrigin.z = v9;
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "ang: (%f, %f, %f)\n", vecOrigin.x, vecOrigin.y, v9);
      CBaseEntity::EntityText(this, text_offset: v8, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      v10 = v8 + 1;
      V_snprintf(
        pDest: tempstr,
        maxLen: 512,
        pFormat: "cell: (%d, %d, %d)\n",
        this->m_cellX.m_Value,
        this->m_cellY.m_Value,
        this->m_cellZ.m_Value);
      CBaseEntity::EntityText(this, text_offset: v10, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      m_cellwidth = this->m_cellwidth;
      x = this->m_vecOrigin.m_Value.x;
      v13 = m_cellwidth * this->m_cellX.m_Value - 0x4000;
      v6 = v10 + 1;
      v14 = (float)(int)((HIDWORD(v13) ^ v13) - HIDWORD(v13));
      if ( x >= 0.0 )
        v15 = x - v14;
      else
        v15 = v14 + x;
      v16 = (float)m_cellwidth;
      if ( v15 >= 0.0 )
      {
        if ( v15 > v16 )
          v15 = (float)m_cellwidth;
      }
      else
      {
        v15 = 0.0;
      }
      y = this->m_vecOrigin.m_Value.y;
      v18 = m_cellwidth * this->m_cellY.m_Value - 0x4000;
      v19 = (float)(int)((HIDWORD(v18) ^ v18) - HIDWORD(v18));
      if ( y >= 0.0 )
        v20 = y - v19;
      else
        v20 = v19 + y;
      if ( v20 >= 0.0 )
      {
        if ( v20 <= v16 )
          v21 = v20;
        else
          v21 = (float)m_cellwidth;
      }
      else
      {
        v21 = 0.0;
      }
      v22 = this->m_vecOrigin.m_Value.z;
      v23 = m_cellwidth * this->m_cellZ.m_Value - 0x4000;
      v24 = (float)(int)((HIDWORD(v23) ^ v23) - HIDWORD(v23));
      if ( v22 >= 0.0 )
        v25 = v22 - v24;
      else
        v25 = v24 + v22;
      if ( v25 >= 0.0 )
      {
        if ( v25 > v16 )
          v25 = (float)m_cellwidth;
      }
      else
      {
        v25 = 0.0;
      }
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "celloffset: (%f, %f, %f)\n", v15, v21, v25);
      CBaseEntity::EntityText(this, text_offset: v6, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    else
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v26 = this->m_vecAbsOrigin.z;
      *(_QWORD *)&vecOrigin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
      vecOrigin.z = v26;
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Position: %0.3f, %0.3f, %0.3f\n", vecOrigin.x, vecOrigin.y, v26);
      CBaseEntity::EntityText(this, text_offset: v6, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    v27 = v6 + 1;
    if ( !CBaseEntity::BlocksLOS(this) )
      CBaseEntity::EntityText(
        this,
        text_offset: v27++,
        text: "Doesn't block LOS",
        duration: 0.0,
        r: 255,
        g: 255,
        b: 255,
        a: 255);
    if ( *(_DWORD *)((int (__thiscall *)(CBaseEntity *, int *))this->GetModelName)(a1: this, a2: &count) != 0
      || this->GetBaseAnimating(this) != nullptr )
    {
      v28 = *(const char **)((int (__thiscall *)(CBaseEntity *, int *))this->GetModelName)(a1: this, a2: &count);
      if ( v28 == nullptr )
        v28 = locale;
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Model:%s", v28);
      CBaseEntity::EntityText(this, text_offset: v27++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 0, a: 255);
    }
    m_Index = this->m_hDamageFilter.m_Index;
    if ( m_Index != -1 )
    {
      v30 = (unsigned __int16)m_Index;
      v31 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v32 = HIWORD(m_Index);
      if ( v31->m_SerialNumber == v32 && v31->m_pEntity != nullptr )
      {
        v33 = v30;
        v34 = g_pEntityList->m_EntPtrArray[v33].m_SerialNumber == v32;
        v35 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v33];
        if ( v34 )
          v36 = *v35;
        else
          v36 = nullptr;
        v37 = CBaseEntity::GetDebugName(this: v36);
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "DAMAGE FILTER:%s", v37);
        CBaseEntity::EntityText(this, text_offset: v27++, text: tempstr, duration: 0.0, r: 0, g: 255, b: 0, a: 255);
      }
    }
    if ( ent_show_contexts.m_pParent != nullptr && ent_show_contexts.m_pParent->m_Value.m_nValue != 0 )
    {
      m_Size = this->m_ResponseContexts.m_Size;
      count = m_Size;
      if ( m_Size != 0 )
      {
        v39 = 0;
        if ( m_Size > 0 )
        {
          v40 = 0;
          for ( i = 0; ; v40 = i )
          {
            if ( v39 < 0
              || v39 >= this->m_ResponseContexts.m_Size
              || (v41 = *(const char **)((char *)&this->m_ResponseContexts.m_Memory.m_pMemory->m_iszValue.pszValue + v40)) == nullptr )
            {
              v41 = locale;
            }
            if ( v39 < 0
              || v39 >= this->m_ResponseContexts.m_Size
              || (v42 = *(const char **)((char *)&this->m_ResponseContexts.m_Memory.m_pMemory->m_iszName.pszValue + v40)) == nullptr )
            {
              v42 = locale;
            }
            V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Context: %s:%s", v42, v41);
            CBaseEntity::EntityText(this, text_offset: v27, text: tempstr, duration: 0.0, r: 0, g: 255, b: 0, a: 255);
            i += 12;
            ++v39;
            ++v27;
            if ( v39 >= count )
              break;
          }
        }
      }
    }
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Flags :%d", this->m_fFlags.m_Value);
    CBaseEntity::EntityText(this, text_offset: v27, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v43 = v27 + 1;
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "Effects :%d (EF_NODRAW=%d)",
      this->m_fEffects.m_Value,
      this->m_fEffects.m_Value & 0x20);
    CBaseEntity::EntityText(this, text_offset: v43, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v2 = v43 + 1;
  }
  if ( (this->m_debugOverlays & 0x40000000) != 0 )
  {
    v44 = this->EyePosition(this, result: &vecOrigin);
    NDebugOverlay::Cross3D(position: v44, size: 16.0, r: 255, g: 0, b: 0, noDepthTest: true, flDuration: 0.050000001);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100BE440
// Name: ComputePushStartMatrix
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputePushStartMatrix(const pushblock_t *params@<eax>, matrix3x4_t *start, CBaseEntity *pEntity)
{
  physicspushlist_t *pList; // eax
  CBaseEntity *pRootParent; // edi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  CBaseEntity *v9; // edi
  float movetime; // xmm0_4
  unsigned int v11; // ecx
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  CBaseEntity *v18; // edi
  float v19; // xmm0_4
  unsigned int v20; // edx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  CBaseEntity *v27; // esi
  matrix3x4_t delta; // [esp+8h] [ebp-B4h] BYREF
  matrix3x4_t xform; // [esp+38h] [ebp-84h] BYREF
  matrix3x4_t srcInv; // [esp+68h] [ebp-54h] BYREF
  Vector localOrigin; // [esp+98h] [ebp-24h] BYREF
  QAngle localAngles; // [esp+A4h] [ebp-18h] BYREF
  float v33; // [esp+B0h] [ebp-Ch]
  float v34; // [esp+B4h] [ebp-8h]
  float v35; // [esp+B8h] [ebp-4h]
  int savedregs; // [esp+BCh] [ebp+0h] BYREF

  pList = params->pList;
  if ( pList != nullptr )
  {
    localOrigin = pList->localOrigin;
    localAngles = pList->localAngles;
  }
  else
  {
    pRootParent = params->pRootParent;
    if ( (pRootParent->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: params->pRootParent, a2: (int)&savedregs);
    x = pRootParent->m_vecAbsVelocity.x;
    y = pRootParent->m_vecAbsVelocity.y;
    z = pRootParent->m_vecAbsVelocity.z;
    v9 = params->pRootParent;
    movetime = params->movetime;
    v11 = (unsigned int)v9->m_iEFlags >> 11;
    v12 = x * movetime;
    v13 = y * movetime;
    v14 = z * movetime;
    v33 = v12;
    v34 = v13;
    v35 = v14;
    if ( (v11 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
      v14 = v35;
      v13 = v34;
      v12 = v33;
    }
    v15 = v9->m_vecAbsOrigin.x - v12;
    v16 = v9->m_vecAbsOrigin.y - v13;
    v17 = v9->m_vecAbsOrigin.z;
    v18 = params->pRootParent;
    localOrigin.x = v15;
    v19 = params->movetime;
    localOrigin.y = v16;
    localOrigin.z = v17 - v14;
    v20 = (unsigned int)v18->m_iEFlags >> 11;
    v21 = v19 * v18->m_vecAngVelocity.x;
    v22 = v18->m_vecAngVelocity.y * v19;
    v23 = v18->m_vecAngVelocity.z * v19;
    v33 = v21;
    v34 = v22;
    v35 = v23;
    if ( (v20 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v18, a2: (int)&savedregs);
      v23 = v35;
      v22 = v34;
      v21 = v33;
    }
    v24 = v18->m_angAbsRotation.x - v21;
    v25 = v18->m_angAbsRotation.y - v22;
    v26 = v18->m_angAbsRotation.z - v23;
    localAngles.x = v24;
    localAngles.y = v25;
    localAngles.z = v26;
  }
  AngleMatrix(angles: &localAngles, position: &localOrigin, matrix: &xform);
  v27 = params->pRootParent;
  if ( (v27->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v27, a2: (int)&savedregs);
  MatrixInvert(in: &v27->m_rgflCoordinateFrame, out: &srcInv);
  ConcatTransforms(in1: &xform, in2: &srcInv, out: &delta);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  ConcatTransforms(in1: &delta, in2: &pEntity->m_rgflCoordinateFrame, out: start);
}

//------------------------------------------------------------------------------
// Address: 0x100BE660
// Name: CheckPushedEntity
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CheckPushedEntity(CBaseEntity *pEntity@<esi>, float a2@<ebp>, const pushblock_t *a3)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  int (__thiscall *GetShadowPosition)(IPhysicsObject *, Vector *, QAngle *); // eax
  float z; // eax
  int v6; // eax
  float x; // xmm4_4
  float y; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  unsigned int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  __int128 v18; // xmm0
  float v19; // xmm0_4
  const QAngle *AbsAngles; // eax
  double v21; // st7
  Vector v22; // [esp+24h] [ebp-B4h] BYREF
  Vector targetAxis; // [esp+30h] [ebp-A8h] BYREF
  matrix3x4_t start; // [esp+3Ch] [ebp-9Ch] BYREF
  __int128 startAngles; // [esp+6Ch] [ebp-6Ch] OVERLAPPED BYREF
  Vector startPos; // [esp+7Ch] [ebp-5Ch] BYREF
  QAngle angles; // [esp+88h] [ebp-50h] BYREF
  Vector origin; // [esp+94h] [ebp-44h] BYREF
  Vector startAxis; // [esp+A0h] [ebp-38h] BYREF
  Vector axis; // [esp+ACh] [ebp-2Ch] BYREF
  QAngle targetRot; // [esp+B8h] [ebp-20h] BYREF
  float fraction; // [esp+C4h] [ebp-14h]
  float deltaTargetAngle; // [esp+C8h] [ebp-10h] BYREF
  float startAngle; // [esp+CCh] [ebp-Ch] BYREF
  void *v35; // [esp+D0h] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+D8h] [ebp+0h]

  startAngle = a2;
  v35 = retaddr;
  m_pPhysicsObject = pEntity->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr
    || !m_pPhysicsObject->IsMoveable(this: pEntity->m_pPhysicsObject)
    || m_pPhysicsObject->GetShadowController(this: m_pPhysicsObject) == nullptr )
  {
    return;
  }
  GetShadowPosition = m_pPhysicsObject->GetShadowPosition;
  HIBYTE(fraction) = 1;
  GetShadowPosition(this: m_pPhysicsObject, a2: (Vector *)&angles, a3: (QAngle *)&startPos);
  targetRot.x = -1.0;
  if ( pEntity != a3->pRootParent )
    goto LABEL_12;
  if ( vec3_angle.x == pEntity->m_vecAngVelocity.x
    && vec3_angle.y == pEntity->m_vecAngVelocity.y
    && vec3_angle.z == pEntity->m_vecAngVelocity.z )
  {
    HIBYTE(fraction) = 0;
  }
  if ( vec3_origin.x != pEntity->m_vecVelocity.m_Value.x
    || vec3_origin.y != pEntity->m_vecVelocity.m_Value.y
    || vec3_origin.z != pEntity->m_vecVelocity.m_Value.z )
  {
LABEL_12:
    if ( (pEntity->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: pEntity, a2: (int)&startAngle);
    z = pEntity->m_vecAbsVelocity.z;
    *(_QWORD *)&axis.x = *(_QWORD *)&pEntity->m_vecAbsVelocity.x;
    axis.z = z;
    targetRot.y = VectorNormalize(vec: &axis);
    v6 = (int)m_pPhysicsObject->GetShadowController(this: m_pPhysicsObject);
    (*(void (__thiscall **)(int, Vector *, _DWORD))(*(_DWORD *)v6 + 48))(a1: v6, a2: &origin, a3: 0);
    x = axis.x;
    y = axis.y;
    v9 = axis.z;
    v10 = (float)((float)(origin.y * axis.y) + (float)(axis.x * origin.x)) + (float)(origin.z * axis.z);
    v11 = (unsigned int)pEntity->m_iEFlags >> 11;
    v12 = (float)((float)(angles.y * axis.y) + (float)(angles.x * axis.x)) + (float)(angles.z * axis.z);
    targetRot.z = v10;
    deltaTargetAngle = v12;
    if ( (v11 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&startAngle);
      v9 = axis.z;
      y = axis.y;
      x = axis.x;
      v12 = deltaTargetAngle;
      v10 = targetRot.z;
    }
    if ( (float)(v10
               - (float)((float)((float)(pEntity->m_vecAbsOrigin.y * y) + (float)(pEntity->m_vecAbsOrigin.x * x))
                       + (float)(pEntity->m_vecAbsOrigin.z * v9))) > 1.0 )
    {
      ((void (__thiscall *)(CBaseEntity *, _DWORD))pEntity->UpdatePhysicsShadowToCurrentPosition)(a1: pEntity, a2: 0);
      goto LABEL_27;
    }
    v13 = v10 - v12;
    deltaTargetAngle = v10 - v12;
    if ( (float)(v10 - v12) <= 1.0 )
      goto LABEL_27;
    v14 = v10 - (float)(a3->movetime * targetRot.y);
    if ( pEntity == a3->pRootParent )
    {
      if ( a3->pList == nullptr )
        goto LABEL_24;
      v15 = pEntity->m_vecVelocity.m_Value.z;
      *(_QWORD *)&startAxis.x = *(_QWORD *)&pEntity->m_vecVelocity.m_Value.x;
      startAxis.z = v15;
      VectorNormalize(vec: &startAxis);
      v10 = targetRot.z;
      v14 = (float)((float)((float)((float)(a3->pList->localOrigin.y * startAxis.y)
                                  + (float)(startAxis.x * a3->pList->localOrigin.x))
                          + (float)(a3->pList->localOrigin.z * startAxis.z))
                  + targetRot.z)
          - (float)((float)((float)(pEntity->m_vecOrigin.m_Value.y * startAxis.y)
                          + (float)(pEntity->m_vecOrigin.m_Value.x * startAxis.x))
                  + (float)(pEntity->m_vecOrigin.m_Value.z * startAxis.z));
    }
    else
    {
      ComputePushStartMatrix(params: a3, start: (matrix3x4_t *)&targetAxis, pEntity);
      v14 = (float)((float)(start.m_flMatVal[1][0] * axis.y) + (float)(start.m_flMatVal[0][0] * axis.x))
          + (float)(start.m_flMatVal[2][0] * axis.z);
      v10 = targetRot.z;
    }
    v13 = deltaTargetAngle;
LABEL_24:
    v16 = v10 - v14;
    if ( v16 > 0.0 )
    {
      targetRot.x = v13 / v16;
      LODWORD(targetRot.y) = 1;
      deltaTargetAngle = 0.0;
      targetRot.x = clamp<float,int,int>(
                      val: &targetRot.x,
                      minVal: (const int *)&deltaTargetAngle,
                      maxVal: (const int *)&targetRot.y);
    }
    else
    {
      targetRot.x = 1.0;
    }
  }
LABEL_27:
  if ( HIBYTE(fraction) != 0 )
  {
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&startAngle);
    RotationDeltaAxisAngle(
      srcAngles: (const QAngle *)&startPos,
      destAngles: &pEntity->m_angAbsRotation,
      deltaAxis: &startAxis,
      deltaAngle: &deltaTargetAngle);
    if ( COERCE_FLOAT(LODWORD(deltaTargetAngle) & _mask__AbsFloat_) > 0.5 )
    {
      v17 = (int)m_pPhysicsObject->GetShadowController(this: m_pPhysicsObject);
      (*(void (__thiscall **)(int, _DWORD, Vector *))(*(_DWORD *)v17 + 48))(a1: v17, a2: 0, a3: &axis);
      RotationDeltaAxisAngle(
        srcAngles: (const QAngle *)&startPos,
        destAngles: (const QAngle *)&axis,
        deltaAxis: &v22,
        deltaAngle: &targetRot.y);
      if ( COERCE_FLOAT(LODWORD(targetRot.y) & _mask__AbsFloat_) <= 0.0099999998 )
      {
        ((void (__thiscall *)(CBaseEntity *, _DWORD))pEntity->UpdatePhysicsShadowToCurrentPosition)(a1: pEntity, a2: 0);
      }
      else
      {
        if ( pEntity == a3->pRootParent )
        {
          v18 = 0;
          *(float *)&v18 = fsqrt(
                             (float)((float)(pEntity->m_vecAngVelocity.x * pEntity->m_vecAngVelocity.x)
                                   + (float)(pEntity->m_vecAngVelocity.y * pEntity->m_vecAngVelocity.y))
                           + (float)(pEntity->m_vecAngVelocity.z * pEntity->m_vecAngVelocity.z));
          startAngles = v18;
          v19 = a3->movetime * *(float *)&v18;
        }
        else
        {
          ComputePushStartMatrix(params: a3, start: (matrix3x4_t *)&targetAxis, pEntity);
          MatrixAngles(
            matrix: (const matrix3x4_t *)&targetAxis,
            angles: (QAngle *)&start.m_flMatVal[2][1],
            position: (Vector *)((char *)&startAngles + 4));
          AbsAngles = CBaseEntity::GetAbsAngles(this: pEntity);
          RotationDeltaAxisAngle(
            srcAngles: (const QAngle *)&start.m_flMatVal[2][1],
            destAngles: AbsAngles,
            deltaAxis: &origin,
            deltaAngle: &targetRot.z);
          v19 = (float)((float)((float)(origin.y * startAxis.y) + (float)(startAxis.x * origin.x))
                      + (float)(origin.z * startAxis.z))
              * targetRot.z;
        }
        if ( v19 == 0.0 )
          targetRot.z = 1.0;
        else
          targetRot.z = fabs(deltaTargetAngle / v19);
        LODWORD(targetRot.y) = 1;
        deltaTargetAngle = 0.0;
        v21 = clamp<float,int,int>(
                val: &targetRot.z,
                minVal: (const int *)&deltaTargetAngle,
                maxVal: (const int *)&targetRot.y);
        targetRot.z = v21;
        if ( targetRot.x <= v21 )
          targetRot.x = targetRot.z;
      }
    }
  }
  if ( targetRot.x >= a3->moveBackFraction )
  {
    a3->moveBackFraction = targetRot.x;
    a3->pBlockedEntity = pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEC00
// Name: public: virtual void CBaseEntity::UpdatePhysicsShadowToCurrentPosition(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::UpdatePhysicsShadowToCurrentPosition(CBaseEntity *this, float deltaTime)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( this->m_MoveType.m_Value != 6 )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      ((void (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, _DWORD, _DWORD))m_pPhysicsObject->UpdateShadow)(
        a1: m_pPhysicsObject,
        a2: &this->m_vecAbsOrigin,
        a3: &this->m_angAbsRotation,
        a4: 0,
        a5: LODWORD(deltaTime));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEC70
// Name: public: bool CBaseEntity::IsInWorld(void)const
// Source: json
//------------------------------------------------------------------------------
bool __usercall CBaseEntity::IsInWorld@<al>(CBaseEntity *this@<ecx>, int a2@<ebp>)
{
  if ( this->m_Network.m_pPev == nullptr )
    return true;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  if ( this->m_vecAbsOrigin.x >= 16384.0 )
    return false;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  if ( this->m_vecAbsOrigin.y >= 16384.0 )
    return false;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  if ( this->m_vecAbsOrigin.z >= 16384.0 )
    return false;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  return this->m_vecAbsOrigin.x > -16384.0
      && CBaseEntity::GetAbsOrigin(this)->y > -16384.0
      && CBaseEntity::GetAbsOrigin(this)->z > -16384.0
      && CBaseEntity::GetAbsVelocity(this)->x < 2000.0
      && CBaseEntity::GetAbsVelocity(this)->y < 2000.0
      && CBaseEntity::GetAbsVelocity(this)->z < 2000.0
      && CBaseEntity::GetAbsVelocity(this)->x > -2000.0
      && CBaseEntity::GetAbsVelocity(this)->y > -2000.0
      && CBaseEntity::GetAbsVelocity(this)->z > -2000.0;
}

//------------------------------------------------------------------------------
// Address: 0x100BEDE0
// Name: public: virtual void CBaseEntity::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::OnRestore(CBaseEntity *this)
{
  int m_iEFlags; // eax
  unsigned int v3; // eax
  edict_t *m_pPev; // ecx
  unsigned int m_Index; // eax
  int v6; // edx
  unsigned int v7; // ebx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v9; // eax
  CBaseEntity *v10; // eax
  unsigned int v11; // eax
  int v12; // edx
  CBaseEntity *v13; // eax

  CGlobalEntityList::UpdateName(this: &gEntList, pEnt: this);
  SimThink_EntityChanged(pEntity: this);
  m_iEFlags = this->m_iEFlags;
  if ( (m_iEFlags & 0x1000000) != 0 )
  {
    ++this->touchStamp;
    v3 = m_iEFlags & 0xFEFFFFFF;
    this->m_iEFlags = v3;
    if ( (v3 & 0x1000000) == 0 )
    {
      this->m_iEFlags = v3 | 0x1000000;
      EntityTouch_Add(pEntity: this);
    }
  }
  CBaseEntity::sm_bDisableTouchFuncs = gpGlobals->eLoadType != MapLoad_Transition;
  CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
  CBaseEntity::sm_bDisableTouchFuncs = false;
  if ( (this->m_fFlags.m_Value & 0x40000000) != 0 )
  {
    if ( this->m_nRenderFX.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB4u);
      }
      this->m_nRenderFX.m_Value = 0;
    }
    CBaseEntity::AddEffects(this, nEffects: 32);
    CBaseEntity::RemoveFlag(this, flagsToRemove: 805306368);
  }
  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1 )
  {
    v6 = (unsigned __int16)m_Index;
    v7 = HIWORD(m_Index);
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == v7 )
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      else
        m_pEntity = nullptr;
      v9 = m_pEntity[55].__vftable;
      if ( v9 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != (unsigned int)v9 >> 16 )
      {
        v10 = nullptr;
      }
      else
      {
        v10 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      }
      if ( v10 != nullptr )
      {
        while ( v10 != this )
        {
          v11 = v10->m_hMovePeer.m_Index;
          if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
            v10 = nullptr;
          else
            v10 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
          if ( v10 == nullptr )
            goto LABEL_29;
        }
      }
      else
      {
LABEL_29:
        if ( v10 != this )
        {
          v12 = v6;
          if ( g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v7 )
            v13 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v12].m_pEntity;
          else
            v13 = nullptr;
          LinkChild(pParent: v13, pChild: this);
        }
      }
    }
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x100BEF90
// Name: public: virtual void CBaseEntity::SetOwnerEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetOwnerEntity(CBaseEntity *this, CBaseEntity *pOwner)
{
  unsigned int m_Index; // eax
  CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hOwnerEntity> *p_m_hOwnerEntity; // ecx
  CBaseEntity *m_pEntity; // edx

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  p_m_hOwnerEntity = &this->m_hOwnerEntity;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != pOwner )
  {
    CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hOwnerEntity>::Set(this: p_m_hOwnerEntity, val: pOwner);
    CBaseEntity::CollisionRulesChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEFF0
// Name: public: virtual void CBaseEntity::OnEntityEvent(enum EntityEvent_t,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::OnEntityEvent(CBaseEntity *this, EntityEvent_t event, void *pEventData)
{
  int v4; // ebx
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_nWaterLevel> *p_m_nWaterLevel; // edi

  if ( event != ENTITY_EVENT_WATER_TOUCH )
  {
    if ( event != ENTITY_EVENT_WATER_UNTOUCH )
      return;
    if ( pEventData == nullptr || ((unsigned __int8)pEventData & 0x20) != 0 )
      --this->m_nWaterTouch;
    if ( ((unsigned __int8)pEventData & 0x10) != 0 )
      --this->m_nSlimeTouch;
  }
  else
  {
    if ( pEventData == nullptr || ((unsigned __int8)pEventData & 0x20) != 0 )
      ++this->m_nWaterTouch;
    if ( ((unsigned __int8)pEventData & 0x10) != 0 )
      ++this->m_nSlimeTouch;
  }
  if ( this->m_MoveType.m_Value == 6 )
  {
    v4 = 0;
    if ( this->m_nWaterTouch != 0 )
      v4 = 32;
    if ( this->m_nSlimeTouch != 0 )
      v4 |= 0x10u;
    p_m_nWaterLevel = &this->m_nWaterLevel;
    if ( (v4 & 0x4030) != 0 )
    {
      if ( p_m_nWaterLevel->m_Value != 1 )
      {
        this->NetworkStateChanged_m_nWaterLevel(this, a2: &this->m_nWaterLevel);
        p_m_nWaterLevel->m_Value = 1;
      }
      CBaseEntity::SetWaterType(this, nType: v4);
    }
    else
    {
      if ( p_m_nWaterLevel->m_Value != 0 )
      {
        this->NetworkStateChanged_m_nWaterLevel(this, a2: &this->m_nWaterLevel);
        p_m_nWaterLevel->m_Value = 0;
      }
      CBaseEntity::SetWaterType(this, nType: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF0D0
// Name: public: virtual bool CBaseEntity::AcceptInput(char const __near *,class CBaseEntity __near *,class CBaseEntity __near *,class variant_t,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseEntity::AcceptInput(
        CBaseEntity *this,
        const char *szInputName,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        variant_t Value,
        int outputID)
{
  unsigned int v7; // eax
  unsigned int v8; // edx
  datamap_t *v9; // ebx
  bool v10; // cc
  int v11; // edi
  const char *pszValue; // eax
  CBaseEntity *v13; // ecx
  const char *iVal; // eax
  const char *v15; // edi
  const char *v16; // eax
  CBaseEntity *v17; // ecx
  const char *v18; // ecx
  const char *v19; // edi
  const char *v20; // eax
  const char *v21; // edi
  const char *v22; // eax
  CBaseEntity *v23; // ecx
  _fieldtypes fieldType; // ecx
  int v25; // edi
  _fieldtypes v26; // eax
  const char *v27; // ebx
  const char *v28; // edi
  const char *v29; // eax
  CBaseEntity *v30; // ecx
  const char *v31; // ecx
  typedescription_t *v33; // edi
  bool v34; // zf
  const ScriptVariant_t *p_y; // eax
  const ScriptVariant_t *v36; // eax
  edict_t *m_pPev; // ecx
  const char *v38; // esi
  const char *duration; // [esp+14h] [ebp-154h]
  const char *durationa; // [esp+14h] [ebp-154h]
  char szScriptFunctionName[256]; // [esp+24h] [ebp-144h] BYREF
  inputdata_t data; // [esp+124h] [ebp-44h] BYREF
  ScriptVariant_t functionReturn; // [esp+144h] [ebp-24h] BYREF
  Vector maxs; // [esp+14Ch] [ebp-1Ch] BYREF
  Vector mins; // [esp+158h] [ebp-10h] BYREF
  void (__thiscall *pfnInput)(CBaseEntity *, inputdata_t *); // [esp+164h] [ebp-4h]
  int savedregs; // [esp+168h] [ebp+0h] BYREF

  if ( ent_messages_draw.m_pParent != nullptr && ent_messages_draw.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( pCaller != nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (pCaller->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pCaller, a2: (int)&savedregs);
      NDebugOverlay::Line(
        origin: &pCaller->m_vecAbsOrigin,
        target: &this->m_vecAbsOrigin,
        r: 255,
        g: 255,
        b: 255,
        noDepthTest: false,
        duration: 3.0);
      v7 = (unsigned int)pCaller->m_iEFlags >> 11;
      maxs.x = 4.0;
      maxs.y = 4.0;
      maxs.z = 4.0;
      mins.x = -4.0;
      mins.y = -4.0;
      mins.z = -4.0;
      if ( (v7 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pCaller, a2: (int)&savedregs);
      NDebugOverlay::Box(origin: &pCaller->m_vecAbsOrigin, &mins, &maxs, r: 255, g: 0, b: 0, a: 0, flDuration: 3.0);
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Text(origin: &this->m_vecAbsOrigin, text: szInputName, bViewCheck: false, duration: 3.0);
    v8 = (unsigned int)this->m_iEFlags >> 11;
    maxs.x = 4.0;
    maxs.y = 4.0;
    maxs.z = 4.0;
    mins.x = -4.0;
    mins.y = -4.0;
    mins.z = -4.0;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, &mins, &maxs, r: 0, g: 255, b: 0, a: 0, flDuration: 3.0);
  }
  v9 = this->GetDataDescMap(this);
  if ( v9 == nullptr )
  {
LABEL_23:
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
    {
      if ( this->IsPlayer(this) )
      {
        v13 = this->IsPlayer(this) ? this : nullptr;
        pszValue = v13->GetPlayerName(this: v13);
      }
      else
      {
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
      }
    }
    v38 = this->m_iClassname.pszValue;
    if ( v38 == nullptr )
      v38 = locale;
    _DevMsg(a1: 2, a2: "unhandled input: (%s) -> (%s,%s)\n", szInputName, v38, pszValue);
    return 0;
  }
  while ( 1 )
  {
    v10 = v9->dataNumFields <= 0;
    pfnInput = nullptr;
    if ( !v10 )
      break;
LABEL_22:
    v9 = v9->baseMap;
    if ( v9 == nullptr )
      goto LABEL_23;
  }
  v11 = 0;
  while ( (v9->dataDesc[v11].flags & 8) == 0 || _V_stricmp(s1: v9->dataDesc[v11].externalName, s2: szInputName) != 0 )
  {
    ++v11;
    pfnInput = (void (__thiscall *)(CBaseEntity *, inputdata_t *))((char *)pfnInput + 1);
    if ( (int)pfnInput >= v9->dataNumFields )
      goto LABEL_22;
  }
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( pCaller != nullptr )
    {
      if ( Value.fieldType == FIELD_STRING )
      {
        iVal = (const char *)Value.iVal;
        if ( Value.iVal == 0 )
        {
          v15 = locale;
LABEL_34:
          v16 = this->m_iName.m_Value.pszValue;
          if ( v16 == nullptr )
          {
            if ( this->IsPlayer(this) )
            {
              v17 = this->IsPlayer(this) ? this : nullptr;
              v16 = v17->GetPlayerName(this: v17);
            }
            else
            {
              v16 = this->m_iClassname.pszValue;
              if ( v16 == nullptr )
                v16 = locale;
            }
          }
          v18 = pCaller->m_iName.m_Value.pszValue;
          if ( v18 == nullptr )
            v18 = locale;
          duration = v15;
          v19 = szInputName;
          V_snprintf(
            pDest: szScriptFunctionName,
            maxLen: 256,
            pFormat: "(%0.2f) input %s: %s.%s(%s)\n",
            gpGlobals->curtime,
            v18,
            v16,
            szInputName,
            duration);
LABEL_53:
          _DevMsg(a1: 2, a2: szScriptFunctionName);
          if ( (this->m_debugOverlays & 0x10) != 0 )
            CBaseEntity::DrawInputOverlay(this, szInputName: v19, pCaller, Value);
          goto LABEL_55;
        }
      }
      else
      {
        iVal = variant_t::ToString(this: &Value);
      }
      v15 = iVal;
      goto LABEL_34;
    }
    if ( Value.fieldType == FIELD_STRING )
    {
      v20 = (const char *)Value.iVal;
      if ( Value.iVal == 0 )
      {
        v21 = locale;
LABEL_47:
        v22 = this->m_iName.m_Value.pszValue;
        if ( v22 == nullptr )
        {
          if ( this->IsPlayer(this) )
          {
            v23 = this->IsPlayer(this) ? this : nullptr;
            v22 = v23->GetPlayerName(this: v23);
          }
          else
          {
            v22 = this->m_iClassname.pszValue;
            if ( v22 == nullptr )
              v22 = locale;
          }
        }
        durationa = v21;
        v19 = szInputName;
        V_snprintf(
          pDest: szScriptFunctionName,
          maxLen: 256,
          pFormat: "(%0.2f) input <NULL>: %s.%s(%s)\n",
          gpGlobals->curtime,
          v22,
          szInputName,
          durationa);
        goto LABEL_53;
      }
    }
    else
    {
      v20 = variant_t::ToString(this: &Value);
    }
    v21 = v20;
    goto LABEL_47;
  }
LABEL_55:
  fieldType = Value.fieldType;
  v25 = (int)pfnInput;
  v26 = v9->dataDesc[(_DWORD)pfnInput].fieldType;
  if ( Value.fieldType != v26 && (Value.fieldType != FIELD_VOID || v26 != FIELD_STRING) )
  {
    if ( !variant_t::Convert(this: &Value, newType: v9->dataDesc[(_DWORD)pfnInput].fieldType) )
    {
      if ( pCaller != nullptr )
      {
        if ( pCaller->m_iName.m_Value.pszValue != nullptr )
          v27 = pCaller->m_iName.m_Value.pszValue;
        else
          v27 = locale;
        if ( pCaller->m_iClassname.pszValue != nullptr )
          v28 = pCaller->m_iClassname.pszValue;
        else
          v28 = locale;
      }
      else
      {
        v27 = "<null>";
        v28 = "<null>";
      }
      v29 = this->m_iName.m_Value.pszValue;
      if ( v29 == nullptr )
      {
        if ( this->IsPlayer(this) )
        {
          v30 = this->IsPlayer(this) ? this : nullptr;
          v29 = v30->GetPlayerName(this: v30);
        }
        else
        {
          v29 = this->m_iClassname.pszValue;
          if ( v29 == nullptr )
            v29 = locale;
        }
      }
      v31 = this->m_iClassname.pszValue;
      if ( v31 == nullptr )
        v31 = locale;
      _Warning(
        a1: "!! ERROR: bad input/output link:\n!! %s(%s,%s) doesn't match type from %s(%s)\n",
        v31,
        v29,
        szInputName,
        v28,
        v27);
      return 0;
    }
    fieldType = Value.fieldType;
  }
  v33 = &v9->dataDesc[v25];
  pfnInput = v33->inputFunc;
  if ( pfnInput != nullptr )
  {
    data.value.fieldType = fieldType;
    v34 = this->m_ScriptScope.m_hScope == (HSCRIPT__ *)-1;
    *(_QWORD *)&data.value.bVal = *(_QWORD *)&Value.bVal;
    data.pActivator = pActivator;
    data.pCaller = pCaller;
    *((_QWORD *)&data.value.rgbaVal + 1) = *((_QWORD *)&Value.rgbaVal + 1);
    data.nOutputID = outputID;
    *(_DWORD *)&functionReturn.m_type = 0;
    functionReturn.m_int = 0;
    if ( v34 )
      goto LABEL_86;
    _V_strcpy(dest: szScriptFunctionName, src: "Input");
    V_strncat(pDest: szScriptFunctionName, pSrc: szInputName, destBufferSize: 0xFFu, max_chars_to_copy: -1);
    if ( pActivator != nullptr )
    {
      LODWORD(mins.y) = CBaseEntity::GetScriptInstance(this: pActivator);
      LODWORD(mins.z) = 33;
      p_y = (const ScriptVariant_t *)&mins.y;
    }
    else
    {
      maxs.z = 0.0;
      maxs.y = 0.0;
      p_y = (const ScriptVariant_t *)&maxs.y;
    }
    g_pScriptVM->SetValue(this: g_pScriptVM, a2: nullptr, a3: "activator", a4: p_y);
    if ( pCaller != nullptr )
    {
      LODWORD(maxs.y) = CBaseEntity::GetScriptInstance(this: pCaller);
      LODWORD(maxs.z) = 33;
      v36 = (const ScriptVariant_t *)&maxs.y;
    }
    else
    {
      mins.z = 0.0;
      mins.y = 0.0;
      v36 = (const ScriptVariant_t *)&mins.y;
    }
    g_pScriptVM->SetValue(this: g_pScriptVM, a2: nullptr, a3: "caller", a4: v36);
    if ( CBaseEntity::CallScriptFunction(this, pFunctionName: szScriptFunctionName, pFunctionReturn: &functionReturn) == 0
      || functionReturn.m_char != 0 )
    {
LABEL_86:
      pfnInput(this, a2: &data);
    }
    if ( this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 )
    {
      g_pScriptVM->ClearValue(this: g_pScriptVM, a2: nullptr, a3: "activator");
      g_pScriptVM->ClearValue(this: g_pScriptVM, a2: nullptr, a3: "caller");
      return 1;
    }
  }
  else if ( (v33->flags & 4) != 0 )
  {
    variant_t::SetOther(this: &Value, data: (char *)this + v33->fieldOffset);
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      return 1;
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BF7A0
// Name: public: void CBaseEntity::InputAlternativeSorting(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputAlternativeSorting(CBaseEntity *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CBaseEntity::NetworkVar_m_bAlternateSorting> *p_m_bAlternateSorting; // esi
  edict_t *m_pPev; // ecx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  p_m_bAlternateSorting = &this->m_bAlternateSorting;
  if ( this->m_bAlternateSorting.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bAlternateSorting->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1F7u);
      p_m_bAlternateSorting->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF800
// Name: public: void CBaseEntity::InputSetParent(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputSetParent(CBaseEntity *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  inputdata_t *v4; // ecx
  variant_t *p_value; // eax

  if ( this->m_iParentAttachment.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xD5u);
    }
    this->m_iParentAttachment.m_Value = 0;
  }
  v4 = inputdata;
  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  CBaseEntity::SetParent(this, newParent: p_value->iszVal, pActivator: v4->pActivator, iAttachment: -1);
}

//------------------------------------------------------------------------------
// Address: 0x100BF870
// Name: public: virtual void CBaseEntity::GetVelocity(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::GetVelocity(CBaseEntity *this, Vector *vVelocity, Vector *vAngVelocity)
{
  __int64 tmp; // [esp+4h] [ebp-Ch]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this->m_MoveType.m_Value == 6 && this->m_pPhysicsObject != nullptr )
  {
    this->m_pPhysicsObject->GetVelocity(this: this->m_pPhysicsObject, a2: vVelocity, a3: vAngVelocity);
  }
  else
  {
    if ( vVelocity != nullptr )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      *vVelocity = this->m_vecAbsVelocity;
    }
    if ( vAngVelocity != nullptr )
    {
      tmp = *(_QWORD *)&this->m_vecAngVelocity.x;
      vAngVelocity->x = this->m_vecAngVelocity.z;
      *(_QWORD *)&vAngVelocity->y = tmp;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF930
// Name: public: virtual void CBaseEntity::GetVectors(class Vector __near *,class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::GetVectors(CBaseEntity *this, Vector *pForward, Vector *pRight, Vector *pUp)
{
  matrix3x4_t *p_m_rgflCoordinateFrame; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  p_m_rgflCoordinateFrame = &this->m_rgflCoordinateFrame;
  if ( pForward != nullptr )
    MatrixGetColumn(in: &this->m_rgflCoordinateFrame, column: 0, out: pForward);
  if ( pRight != nullptr )
  {
    MatrixGetColumn(in: p_m_rgflCoordinateFrame, column: 1, out: pRight);
    pRight->x = pRight->x * -1.0;
    pRight->y = pRight->y * -1.0;
    pRight->z = pRight->z * -1.0;
  }
  if ( pUp != nullptr )
    MatrixGetColumn(in: p_m_rgflCoordinateFrame, column: 2, out: pUp);
}

//------------------------------------------------------------------------------
// Address: 0x100BF9C0
// Name: public: virtual void CBaseEntity::ChangeTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ChangeTeam(CBaseEntity *this, int iTeamNum)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iTeamNum> *p_m_iTeamNum; // esi
  edict_t *m_pPev; // ecx

  p_m_iTeamNum = &this->m_iTeamNum;
  if ( this->m_iTeamNum.m_Value != iTeamNum )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iTeamNum->m_Value = iTeamNum;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F4u);
      p_m_iTeamNum->m_Value = iTeamNum;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFA10
// Name: public: void CBaseEntity::SetShadowCastDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetShadowCastDistance(CBaseEntity *this, float flDistance)
{
  CNetworkVarBase<float,CBaseEntity::NetworkVar_m_flShadowCastDistance> *p_m_flShadowCastDistance; // esi
  edict_t *m_pPev; // ecx

  p_m_flShadowCastDistance = &this->m_flShadowCastDistance;
  if ( this->m_flShadowCastDistance.m_Value != flDistance )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flShadowCastDistance->m_Value = flDistance;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x314u);
      p_m_flShadowCastDistance->m_Value = flDistance;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFA70
// Name: public: void CBaseEntity::SetAbsVelocity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetAbsVelocity(CBaseEntity *this, const Vector *vecAbsVelocity)
{
  unsigned int m_Index; // eax
  CBaseEntity **v5; // ecx
  CBaseEntity *v6; // ebx
  float v7; // xmm1_4
  CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecVelocity> *v8; // esi
  float z; // xmm0_4
  float x; // xmm1_4
  CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecVelocity> *p_m_vecVelocity; // esi
  Vector vNew; // [esp+8h] [ebp-18h] BYREF
  Vector relVelocity; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF
  float vecAbsVelocitya; // [esp+28h] [ebp+8h]
  float vecAbsVelocityb; // [esp+28h] [ebp+8h]
  float vecAbsVelocityc; // [esp+28h] [ebp+8h]
  float vecAbsVelocityd; // [esp+28h] [ebp+8h]
  float vecAbsVelocitye; // [esp+28h] [ebp+8h]

  if ( vecAbsVelocity->x != this->m_vecAbsVelocity.x
    || vecAbsVelocity->y != this->m_vecAbsVelocity.y
    || vecAbsVelocity->z != this->m_vecAbsVelocity.z )
  {
    CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 4);
    this->m_iEFlags &= ~0x1000u;
    this->m_vecAbsVelocity = *vecAbsVelocity;
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && (v5 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (v6 = *v5, *v5 != nullptr) )
    {
      if ( (v6->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this: *v5, a2: (int)&savedregs);
      relVelocity.x = vecAbsVelocity->x - v6->m_vecAbsVelocity.x;
      relVelocity.y = vecAbsVelocity->y - v6->m_vecAbsVelocity.y;
      relVelocity.z = vecAbsVelocity->z - v6->m_vecAbsVelocity.z;
      if ( (v6->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
      VectorIRotate(in1: &relVelocity.x, in2: &v6->m_rgflCoordinateFrame, out: &vNew.x);
      x = this->m_vecVelocity.m_Value.x;
      p_m_vecVelocity = &this->m_vecVelocity;
      vecAbsVelocityc = vNew.x;
      if ( x != vNew.x )
      {
        (*(void (__thiscall **)(float *, CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecVelocity> *))(LODWORD(p_m_vecVelocity[-41].m_Value.z) + 716))(
          a1: &p_m_vecVelocity[-41].m_Value.z,
          a2: p_m_vecVelocity);
        p_m_vecVelocity->m_Value.x = vecAbsVelocityc;
      }
      vecAbsVelocityd = vNew.y;
      if ( p_m_vecVelocity->m_Value.y != vNew.y )
      {
        (*(void (__thiscall **)(float *, float *))(LODWORD(p_m_vecVelocity[-41].m_Value.z) + 716))(
          a1: &p_m_vecVelocity[-41].m_Value.z,
          a2: &p_m_vecVelocity->m_Value.y);
        p_m_vecVelocity->m_Value.y = vecAbsVelocityd;
      }
      vecAbsVelocitye = vNew.z;
      if ( p_m_vecVelocity->m_Value.z != vNew.z )
      {
        (*(void (__thiscall **)(float *, float *))(LODWORD(p_m_vecVelocity[-41].m_Value.z) + 716))(
          a1: &p_m_vecVelocity[-41].m_Value.z,
          a2: &p_m_vecVelocity->m_Value.z);
        p_m_vecVelocity->m_Value.z = vecAbsVelocitye;
      }
    }
    else
    {
      v7 = this->m_vecVelocity.m_Value.x;
      v8 = &this->m_vecVelocity;
      vecAbsVelocitya = vecAbsVelocity->x;
      if ( v7 != vecAbsVelocitya )
      {
        (*(void (__thiscall **)(float *, CNetworkVectorXYZBase<Vector,CBaseEntity::NetworkVar_m_vecVelocity> *))(LODWORD(v8[-41].m_Value.z) + 716))(
          a1: &v8[-41].m_Value.z,
          a2: v8);
        v8->m_Value.x = vecAbsVelocitya;
      }
      vecAbsVelocityb = vecAbsVelocity->y;
      if ( v8->m_Value.y != vecAbsVelocityb )
      {
        (*(void (__thiscall **)(float *, float *))(LODWORD(v8[-41].m_Value.z) + 716))(
          a1: &v8[-41].m_Value.z,
          a2: &v8->m_Value.y);
        v8->m_Value.y = vecAbsVelocityb;
      }
      z = vecAbsVelocity->z;
      if ( v8->m_Value.z != z )
      {
        (*(void (__thiscall **)(float *, float *))(LODWORD(v8[-41].m_Value.z) + 716))(
          a1: &v8[-41].m_Value.z,
          a2: &v8->m_Value.z);
        v8->m_Value.z = z;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFD00
// Name: public: void CBaseEntity::UpdateCell(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::UpdateCell(CBaseEntity *this)
{
  int v2; // ebx
  edict_t *m_pPev; // ecx
  int v4; // ebx
  edict_t *v5; // ecx
  int v6; // edi
  edict_t *v7; // ecx
  int cellwidth; // [esp+10h] [ebp-4h]

  cellwidth = this->m_cellwidth;
  v2 = CellFromCoord(cellwidth, f: this->m_vecOrigin.m_Value.x);
  if ( this->m_cellX.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2B0u);
    }
    this->m_cellX.m_Value = v2;
  }
  v4 = CellFromCoord(cellwidth, f: this->m_vecOrigin.m_Value.y);
  if ( this->m_cellY.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x2B4u);
    }
    this->m_cellY.m_Value = v4;
  }
  v6 = CellFromCoord(cellwidth, f: this->m_vecOrigin.m_Value.z);
  if ( this->m_cellZ.m_Value != v6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_cellZ.m_Value = v6;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x2B8u);
      this->m_cellZ.m_Value = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFE10
// Name: public: void CBaseEntity::SetSimulatedEveryTick(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetSimulatedEveryTick(CBaseEntity *this, bool sim)
{
  CNetworkVarBase<bool,CBaseEntity::NetworkVar_m_bSimulatedEveryTick> *p_m_bSimulatedEveryTick; // esi
  edict_t *m_pPev; // ecx

  p_m_bSimulatedEveryTick = &this->m_bSimulatedEveryTick;
  if ( this->m_bSimulatedEveryTick.m_Value != sim )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bSimulatedEveryTick->m_Value = sim;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1F5u);
      p_m_bSimulatedEveryTick->m_Value = sim;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFE60
// Name: public: void CBaseEntity::SetAnimatedEveryTick(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetAnimatedEveryTick(CBaseEntity *this, bool anim)
{
  CNetworkVarBase<bool,CBaseEntity::NetworkVar_m_bAnimatedEveryTick> *p_m_bAnimatedEveryTick; // esi
  edict_t *m_pPev; // ecx

  p_m_bAnimatedEveryTick = &this->m_bAnimatedEveryTick;
  if ( this->m_bAnimatedEveryTick.m_Value != anim )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bAnimatedEveryTick->m_Value = anim;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1F6u);
      p_m_bAnimatedEveryTick->m_Value = anim;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFEB0
// Name: public: void CBaseEntity::AppendContextToCriteria(class ResponseRules::CriteriaSet __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AppendContextToCriteria(
        CBaseEntity *this,
        ResponseRules::CriteriaSet *set,
        const char *prefix)
{
  CBaseEntity *v3; // edi
  int v4; // esi
  int v5; // ebx
  const char *pszValue; // eax
  const char *v7; // edi
  char sz[128]; // [esp+10h] [ebp-88h] BYREF
  CBaseEntity *v9; // [esp+90h] [ebp-8h]
  int c; // [esp+94h] [ebp-4h]

  v3 = this;
  v9 = this;
  CBaseEntity::RemoveExpiredConcepts(this);
  v4 = 0;
  c = v3->m_ResponseContexts.m_Size;
  if ( c > 0 )
  {
    v5 = 0;
    while ( 1 )
    {
      if ( v4 < 0
        || v4 >= v3->m_ResponseContexts.m_Size
        || (pszValue = v3->m_ResponseContexts.m_Memory.m_pMemory[v5].m_iszName.pszValue) == nullptr )
      {
        pszValue = locale;
      }
      if ( v4 < 0
        || v4 >= v3->m_ResponseContexts.m_Size
        || (v7 = v3->m_ResponseContexts.m_Memory.m_pMemory[v5].m_iszValue.pszValue) == nullptr )
      {
        v7 = locale;
      }
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "%s%s", prefix, pszValue);
      ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: sz, value: v7, weight: 1.0);
      ++v4;
      ++v5;
      if ( v4 >= c )
        break;
      v3 = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFF80
// Name: public: void CBaseEntity::InputEnableShadow(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputEnableShadow(CBaseEntity *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_fEffects> *p_m_fEffects; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_fEffects = &this->m_fEffects;
  v3 = this->m_fEffects.m_Value & 0xFFFFFFEF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fEffects->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      p_m_fEffects->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFFD0
// Name: public: void CBaseEntity::InputEnableReceivingFlashlight(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputEnableReceivingFlashlight(CBaseEntity *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_fEffects> *p_m_fEffects; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_fEffects = &this->m_fEffects;
  v3 = this->m_fEffects.m_Value & 0xFFFFDFFF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fEffects->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      p_m_fEffects->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0020
// Name: public: void CBaseEntity::InputDisableDrawInFastReflection(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputDisableDrawInFastReflection(CBaseEntity *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_fEffects> *p_m_fEffects; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_fEffects = &this->m_fEffects;
  v3 = this->m_fEffects.m_Value & 0xFFFFFBFF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fEffects->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      p_m_fEffects->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0070
// Name: public: void CBaseEntity::InputEnableDraw(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputEnableDraw(CBaseEntity *this, inputdata_t *inputdata)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

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
  if ( this->m_nTransmitStateOwnedCounter == 0 )
  {
    ++g_nInsideDispatchUpdateTransmitState;
    this->UpdateTransmitState(this);
    --g_nInsideDispatchUpdateTransmitState;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C00F0
// Name: public: void CBaseEntity::SUB_PerformFadeOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SUB_PerformFadeOut(CBaseEntity *this)
{
  float frametime; // xmm0_4
  edict_t *m_pPev; // ecx
  float v4; // xmm0_4
  int v5; // eax
  float a; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // ebx
  edict_t *v10; // ecx
  int dt; // [esp+0h] [ebp-4h]

  frametime = gpGlobals->frametime;
  dt = LODWORD(frametime);
  if ( frametime > 0.1 )
  {
    frametime = 0.1;
    dt = 1036831949;
  }
  if ( this->m_nRenderMode.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB5u);
        frametime = *(float *)&dt;
      }
    }
    this->m_nRenderMode.m_Value = 2;
  }
  v4 = frametime * 256.0;
  if ( v4 < 1.0 )
    v4 = 1.0;
  v5 = (int)v4;
  a = (float)this->m_clrRender.m_Value.a;
  v7 = (float)v5;
  if ( (float)-a <= (float)v5 )
  {
    if ( (float)-v7 <= (float)-a )
      v8 = 0.0;
    else
      v8 = a - v7;
  }
  else
  {
    v8 = a + v7;
  }
  v9 = (int)v8;
  if ( this->m_clrRender.m_Value.a != (unsigned __int8)(int)v8 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_clrRender.m_Value.a = v9;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0xB8u);
      this->m_clrRender.m_Value.a = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0200
// Name: public: void CBaseEntity::SUB_FadeOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SUB_FadeOut(CBaseEntity *this)
{
  edict_t *m_pPev; // ecx

  if ( this->SUB_AllowedToFade(this) )
  {
    CBaseEntity::SUB_PerformFadeOut(this);
    if ( this->m_clrRender.m_Value.a != 0 )
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    else
      UTIL_Remove(oldObj: this);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
    if ( this->m_clrRender.m_Value.a != 0xFF )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_clrRender.m_Value.a = -1;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
        this->m_clrRender.m_Value.a = -1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0310
// Name: public: bool CUtlCachedFileData<class CModelSoundsCache>::EntryExists(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlCachedFileData<CModelSoundsCache>::EntryExists(
        CUtlCachedFileData<CModelSoundsCache> *this,
        const char *filename)
{
  CUtlCachedFileData<CModelSoundsCache>::ElementType_t element; // [esp+4h] [ebp-10h] BYREF

  element.handle = nullptr;
  element.fileinfo = 0;
  element.diskfileinfo = -2;
  element.dataIndex = -1;
  element.handle = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: filename);
  return CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_Elements,
           search: &element) != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100C05E0
// Name: private: void CBaseEntity::ShadowCastDistThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ShadowCastDistThink(CBaseEntity *this)
{
  float m_flDesiredShadowCastDistance; // xmm0_4
  edict_t *m_pPev; // ecx

  m_flDesiredShadowCastDistance = this->m_flDesiredShadowCastDistance;
  if ( this->m_flShadowCastDistance.m_Value != m_flDesiredShadowCastDistance )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x314u);
    }
    this->m_flShadowCastDistance.m_Value = m_flDesiredShadowCastDistance;
  }
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: gpGlobals->curtime, szContext: "ShadowCastDistThink");
}

//------------------------------------------------------------------------------
// Address: 0x100C0660
// Name: public: void CBaseEntity::SetShadowCastDistance(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetShadowCastDistance(CBaseEntity *this, float flDesiredDistance, float flDelay)
{
  bool v3; // zf

  v3 = flDesiredDistance == this->m_flShadowCastDistance.m_Value;
  this->m_flDesiredShadowCastDistance = flDesiredDistance;
  if ( !v3 )
    CBaseEntity::ThinkSet(
      this,
      func: CBaseEntity::ShadowCastDistThink,
      thinkTime: gpGlobals->curtime + flDelay,
      szContext: "ShadowCastDistThink");
}

//------------------------------------------------------------------------------
// Address: 0x100C06B0
// Name: public: void CBaseEntity::SetMoveType(enum MoveType_t,enum MoveCollide_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetMoveType(CBaseEntity *this, MoveType_t val, MoveCollide_t moveCollide)
{
  unsigned __int8 m_Value; // al
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_MoveType> *p_m_MoveType; // edi
  edict_t *m_pPev; // ecx
  char v7; // dl
  char v8; // al
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_MoveType> *v9; // eax
  CBaseEdict *v10; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  edict_t *v13; // ecx

  m_Value = this->m_MoveType.m_Value;
  p_m_MoveType = &this->m_MoveType;
  if ( m_Value == val )
  {
    if ( this->m_MoveCollide.m_Value != (_BYTE)moveCollide )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_MoveCollide.m_Value = moveCollide;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xD7u);
        this->m_MoveCollide.m_Value = moveCollide;
      }
    }
  }
  else
  {
    if ( m_Value == 8 )
      this->m_iEFlags &= ~4u;
    v7 = val != MOVETYPE_PUSH && val != MOVETYPE_NONE && val != MOVETYPE_VPHYSICS && val != MOVETYPE_NOCLIP;
    v8 = m_Value != 7 && m_Value != 0 && m_Value != 6 && m_Value != 8;
    if ( v7 != v8 )
      CCollisionProperty::MarkPartitionHandleDirty(this: &this->m_Collision);
    if ( p_m_MoveType->m_Value != (_BYTE)val )
    {
      v9 = p_m_MoveType - 214;
      if ( p_m_MoveType[-130].m_Value != 0 )
      {
        v9[88].m_Value |= 1u;
      }
      else
      {
        v10 = *(CBaseEdict **)&v9[24].m_Value;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: v10, offset: 0xD6u);
      }
      p_m_MoveType->m_Value = val;
    }
    if ( this->m_MoveCollide.m_Value != (_BYTE)moveCollide )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v11 = this->m_Network.m_pPev;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0xD7u);
      }
      this->m_MoveCollide.m_Value = moveCollide;
    }
    CBaseEntity::CollisionRulesChanged(this);
    switch ( p_m_MoveType->m_Value )
    {
      case 2u:
        CBaseEntity::SetSimulatedEveryTick(this, sim: true);
        CBaseEntity::SetAnimatedEveryTick(this, anim: true);
        break;
      case 3u:
        CBaseEntity::SetSimulatedEveryTick(this, sim: g_bTestMoveTypeStepSimulation);
        CBaseEntity::SetAnimatedEveryTick(this, anim: false);
        break;
      case 4u:
      case 5u:
        CBaseEntity::UpdateWaterState(this);
        break;
      default:
        if ( !this->m_bSimulatedEveryTick.m_Value )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v12 = this->m_Network.m_pPev;
            if ( v12 != nullptr )
              CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x1F5u);
          }
          this->m_bSimulatedEveryTick.m_Value = true;
        }
        if ( this->m_bAnimatedEveryTick.m_Value )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v13 = this->m_Network.m_pPev;
            if ( v13 != nullptr )
              CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x1F6u);
          }
          this->m_bAnimatedEveryTick.m_Value = false;
        }
        break;
    }
    CBaseEntity::CheckStepSimulationChanged(this);
    CBaseEntity::CheckHasGamePhysicsSimulation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C08C0
// Name: public: void CBaseEntity::InputAlpha(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputAlpha(CBaseEntity *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  unsigned __int8 v3; // bl
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *p_m_clrRender; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType != FIELD_INTEGER )
  {
    LOBYTE(pszValue) = 0;
LABEL_6:
    v3 = (unsigned __int8)pszValue;
    goto LABEL_7;
  }
  pszValue = inputdata->value.iszVal.pszValue;
  if ( (int)pszValue < 0 )
  {
    v3 = 0;
    goto LABEL_7;
  }
  v3 = -1;
  if ( (int)pszValue <= 255 )
    goto LABEL_6;
LABEL_7:
  p_m_clrRender = &this->m_clrRender;
  if ( this->m_clrRender.m_Value.a != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_clrRender.m_Value.a = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
      p_m_clrRender->m_Value.a = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0930
// Name: public: void CBaseEntity::PostClientMessagesSent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PostClientMessagesSent(CBaseEntity *this)
{
  if ( (this->m_fEffects.m_Value & 8) != 0 )
    CBaseEntity::RemoveEffects(this, nEffects: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100C0950
// Name: BuildTeleportList_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildTeleportList_r(
        CBaseEntity *pTeleport,
        CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > *teleportList)
{
  unsigned int v2; // eax
  int m_iEFlags; // ecx
  int m_Size; // eax
  unsigned int m_Index; // esi
  CBaseEntity *m_pEntity; // esi
  unsigned int v7; // eax
  TeleportListEntry_t entry; // [esp+8h] [ebp-1Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v2 = (unsigned int)pTeleport->m_iEFlags >> 11;
  entry.pEntity = pTeleport;
  if ( (v2 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pTeleport, a2: (int)&savedregs);
  m_iEFlags = pTeleport->m_iEFlags;
  entry.prevAbsOrigin = pTeleport->m_vecAbsOrigin;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pTeleport, a2: (int)&savedregs);
  m_Size = teleportList->m_Size;
  entry.prevAbsAngles = pTeleport->m_angAbsRotation;
  CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(this: teleportList, elem: m_Size, src: &entry);
  m_Index = pTeleport->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  while ( m_pEntity != nullptr )
  {
    BuildTeleportList_r(pTeleport: m_pEntity, teleportList);
    v7 = m_pEntity->m_hMovePeer.m_Index;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0A60
// Name: void CC_Ent_SetName(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_SetName(const CCommand *args)
{
  const CCommand *v1; // ebx
  CBasePlayer *v2; // esi
  const char *v3; // eax
  CBasePlayer *CommandClient; // eax
  CBaseEntity *Ent; // edi
  const char *v6; // ecx
  const char *v7; // eax
  string_t v8; // eax
  const char *pszValue; // esi
  const char *v10; // eax
  const char *v11; // esi
  const char *v12; // eax
  const char *v13; // esi
  const char *v14; // eax

  v1 = args;
  if ( args->m_nArgc >= 1 )
  {
    if ( args->m_nArgc > 2 && (v3 = args->m_ppArgv[2]) != locale && _V_stricmp(s1: v3, s2: locale) != 0 )
    {
      Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
      if ( Ent == nullptr )
        return;
      while ( 1 )
      {
        pszValue = Ent->m_iName.m_Value.pszValue;
        if ( pszValue != nullptr )
        {
          v10 = CCommand::operator[](this: v1, nIndex: 1);
          if ( v10 == pszValue || _V_stricmp(s1: v10, s2: pszValue) == 0 )
            break;
        }
        v11 = Ent->m_iClassname.pszValue;
        if ( v11 != nullptr )
        {
          v12 = CCommand::operator[](this: v1, nIndex: 1);
          if ( v12 == v11 || _V_stricmp(s1: v12, s2: v11) == 0 )
            break;
        }
        v13 = Ent->m_iClassname.pszValue;
        if ( v13 == nullptr )
          v13 = locale;
        v14 = CCommand::operator[](this: v1, nIndex: 1);
        if ( v14 == v13 || _V_stricmp(s1: v14, s2: v13) == 0 )
          break;
        Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
        if ( Ent == nullptr )
          return;
      }
    }
    else
    {
      if ( UTIL_GetCommandClient() == nullptr )
        return;
      CommandClient = UTIL_GetCommandClient();
      Ent = CommandClient->FindPickerEntity(this: CommandClient);
    }
    if ( Ent != nullptr )
    {
      v6 = locale;
      if ( v1->m_nArgc > 1 )
        v6 = v1->m_ppArgv[1];
      v7 = Ent->m_iClassname.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      _Msg(a1: "Set the name of %s to %s\n", v7, v6);
      v8.pszValue = AllocPooledString(pszValue: (const char *)&args).pszValue;
      CBaseEntity::SetName(this: Ent, newName: *(string_t *)v8.pszValue);
    }
  }
  else
  {
    v2 = UTIL_GetCommandClient();
    if ( v2 != nullptr && v2->IsPlayer(this: v2) )
      ClientPrint(
        player: v2,
        msg_dest: 2,
        msg_name: "Usage:\n   ent_setname <new name> <entity name>\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0C00
// Name: public: void CBaseEntity::SetAbsOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetAbsOrigin(CBaseEntity *this, const Vector *absOrigin)
{
  unsigned int m_Index; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  const matrix3x4_t *ParentToWorldTransform; // eax
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  float curtime; // xmm0_4
  edict_t *v12; // ecx
  matrix3x4_t tempMat; // [esp+8h] [ebp-3Ch] BYREF
  Vector vecNewOrigin; // [esp+38h] [ebp-Ch] BYREF
  int savedregs; // [esp+44h] [ebp+0h] BYREF
  float absOrigina; // [esp+4Ch] [ebp+8h]

  CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( absOrigin->x != this->m_vecAbsOrigin.x
    || absOrigin->y != this->m_vecAbsOrigin.y
    || absOrigin->z != this->m_vecAbsOrigin.z )
  {
    CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
    this->m_iEFlags &= ~0x800u;
    this->m_vecAbsOrigin = *absOrigin;
    MatrixSetColumn(in: absOrigin, column: 3, out: &this->m_rgflCoordinateFrame);
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      ParentToWorldTransform = CBaseEntity::GetParentToWorldTransform(this, tempMatrix: &tempMat);
      VectorITransform(in1: &absOrigin->x, in2: ParentToWorldTransform, out: &vecNewOrigin.x);
      y = vecNewOrigin.y;
      x = vecNewOrigin.x;
    }
    else
    {
      x = absOrigin->x;
      y = absOrigin->y;
      z = absOrigin->z;
      vecNewOrigin.x = absOrigin->x;
      vecNewOrigin.y = y;
      vecNewOrigin.z = z;
    }
    if ( x != this->m_vecOrigin.m_Value.x
      || y != this->m_vecOrigin.m_Value.y
      || vecNewOrigin.z != this->m_vecOrigin.m_Value.z )
    {
      if ( this->m_vecOrigin.m_Value.x != x )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2BCu);
            y = vecNewOrigin.y;
          }
        }
        this->m_vecOrigin.m_Value.x = x;
      }
      if ( this->m_vecOrigin.m_Value.y != y )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v9 = this->m_Network.m_pPev;
          if ( v9 != nullptr )
            CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x2BCu);
        }
        this->m_vecOrigin.m_Value.y = y;
      }
      absOrigina = vecNewOrigin.z;
      if ( this->m_vecOrigin.m_Value.z != vecNewOrigin.z )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v10 = this->m_Network.m_pPev;
          if ( v10 != nullptr )
            CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x2C4u);
        }
        this->m_vecOrigin.m_Value.z = absOrigina;
      }
      curtime = gpGlobals->curtime;
      if ( this->m_flSimulationTime.m_Value != curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = this->m_Network.m_pPev;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x68u);
        }
        this->m_flSimulationTime.m_Value = curtime;
      }
      CBaseEntity::UpdateCell(this);
    }
    if ( CBaseEntity::HasDataObjectType(this, type: 4) )
      ReportPositionChanged(pMovedEntity: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0E80
// Name: public: void CBaseEntity::SetAbsAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetAbsAngles(CBaseEntity *this, const QAngle *absAngles)
{
  unsigned int m_Index; // eax
  CBaseEntity **v4; // ecx
  CBaseEntity *v5; // ebx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *p_m_angRotation; // edi
  edict_t *m_pPev; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  float curtime; // xmm0_4
  edict_t *v14; // ecx
  matrix3x4_t localMatrix; // [esp+8h] [ebp-6Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-3Ch] BYREF
  QAngle angNewRotation; // [esp+68h] [ebp-Ch] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF
  float absAnglesa; // [esp+7Ch] [ebp+8h]

  CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( absAngles->x != this->m_angAbsRotation.x
    || absAngles->y != this->m_angAbsRotation.y
    || absAngles->z != this->m_angAbsRotation.z )
  {
    CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
    this->m_iEFlags &= ~0x800u;
    this->m_angAbsRotation = *absAngles;
    AngleMatrix(angles: absAngles, matrix: &this->m_rgflCoordinateFrame);
    MatrixSetColumn(in: &this->m_vecAbsOrigin, column: 3, out: &this->m_rgflCoordinateFrame);
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && (v4 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (v5 = *v4, *v4 != nullptr) )
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: *v4, a2: (int)&savedregs);
      if ( v5->m_angAbsRotation.x == this->m_angAbsRotation.x
        && v5->m_angAbsRotation.y == this->m_angAbsRotation.y
        && v5->m_angAbsRotation.z == this->m_angAbsRotation.z )
      {
        x = 0.0;
        y = 0.0;
        memset((void *)&angNewRotation, 0, sizeof(angNewRotation));
      }
      else
      {
        if ( (v5->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
        MatrixInvert(in: &v5->m_rgflCoordinateFrame, out: &worldToParent);
        ConcatTransforms(in1: &worldToParent, in2: &this->m_rgflCoordinateFrame, out: &localMatrix);
        MatrixAngles(a1: (int)this, src: (const VMatrix *)&localMatrix, vAngles: &angNewRotation);
        y = angNewRotation.y;
        x = angNewRotation.x;
      }
    }
    else
    {
      x = absAngles->x;
      y = absAngles->y;
      z = absAngles->z;
      angNewRotation.x = absAngles->x;
      angNewRotation.y = y;
      angNewRotation.z = z;
    }
    p_m_angRotation = &this->m_angRotation;
    if ( x != this->m_angRotation.m_Value.x
      || y != this->m_angRotation.m_Value.y
      || angNewRotation.z != this->m_angRotation.m_Value.z )
    {
      if ( p_m_angRotation->m_Value.x != x )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2C8u);
            y = angNewRotation.y;
          }
        }
        p_m_angRotation->m_Value.x = x;
      }
      if ( this->m_angRotation.m_Value.y != y )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v11 = this->m_Network.m_pPev;
          if ( v11 != nullptr )
            CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x2CCu);
        }
        this->m_angRotation.m_Value.y = y;
      }
      absAnglesa = angNewRotation.z;
      if ( this->m_angRotation.m_Value.z != angNewRotation.z )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = this->m_Network.m_pPev;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x2D0u);
        }
        this->m_angRotation.m_Value.z = absAnglesa;
      }
      curtime = gpGlobals->curtime;
      if ( this->m_flSimulationTime.m_Value != curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flSimulationTime.m_Value = curtime;
        }
        else
        {
          v14 = this->m_Network.m_pPev;
          if ( v14 != nullptr )
            CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x68u);
          this->m_flSimulationTime.m_Value = curtime;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1190
// Name: public: void CBaseEntity::SetLocalOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetLocalOrigin(CBaseEntity *this, const Vector *origin)
{
  CNetworkVectorXY_SeparateZBase<Vector,CBaseEntity::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // edi
  char *p_z; // esi
  CBaseEdict *v4; // ecx
  CBaseEdict *v5; // ecx
  float curtime; // xmm0_4
  edict_t *m_pPev; // ecx

  if ( (LODWORD(origin->x) & 0x7F800000) != 0x7F800000
    && (LODWORD(origin->y) & 0x7F800000) != 0x7F800000
    && (LODWORD(origin->z) & 0x7F800000) != 0x7F800000 )
  {
    p_m_vecOrigin = &this->m_vecOrigin;
    if ( origin->x != this->m_vecOrigin.m_Value.x
      || origin->y != this->m_vecOrigin.m_Value.y
      || origin->z != this->m_vecOrigin.m_Value.z )
    {
      CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
      p_z = (char *)&p_m_vecOrigin[-59].m_Value.z;
      if ( LOBYTE(p_m_vecOrigin[-52].m_Value.z) != 0 )
      {
        p_z[88] |= 1u;
      }
      else
      {
        v4 = *((CBaseEdict **)p_z + 6);
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: v4, offset: 0x2BCu);
      }
      if ( p_z[84] != 0 )
      {
        p_z[88] |= 1u;
      }
      else
      {
        v5 = *((CBaseEdict **)p_z + 6);
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: v5, offset: 0x2C4u);
      }
      p_m_vecOrigin->m_Value = *origin;
      curtime = gpGlobals->curtime;
      if ( this->m_flSimulationTime.m_Value != curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x68u);
        }
        this->m_flSimulationTime.m_Value = curtime;
      }
      CBaseEntity::UpdateCell(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1300
// Name: public: void CBaseEntity::SetLocalAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetLocalAngles(CBaseEntity *this, const QAngle *angles)
{
  CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *p_m_angRotation; // edi
  char *p_z; // esi
  CBaseEdict *v4; // ecx
  CBaseEdict *v5; // ecx
  CBaseEdict *v6; // ecx
  float curtime; // xmm0_4
  edict_t *m_pPev; // ecx

  p_m_angRotation = &this->m_angRotation;
  if ( angles->x != this->m_angRotation.m_Value.x
    || angles->y != this->m_angRotation.m_Value.y
    || angles->z != this->m_angRotation.m_Value.z )
  {
    CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
    p_z = (char *)&p_m_angRotation[-60].m_Value.z;
    if ( LOBYTE(p_m_angRotation[-53].m_Value.z) != 0 )
    {
      p_z[88] |= 1u;
    }
    else
    {
      v4 = *((CBaseEdict **)p_z + 6);
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0x2C8u);
    }
    if ( p_z[84] != 0 )
    {
      p_z[88] |= 1u;
    }
    else
    {
      v5 = *((CBaseEdict **)p_z + 6);
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: 0x2CCu);
    }
    if ( p_z[84] != 0 )
    {
      p_z[88] |= 1u;
    }
    else
    {
      v6 = *((CBaseEdict **)p_z + 6);
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x2D0u);
    }
    p_m_angRotation->m_Value = *angles;
    curtime = gpGlobals->curtime;
    if ( this->m_flSimulationTime.m_Value != curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flSimulationTime.m_Value = curtime;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x68u);
        this->m_flSimulationTime.m_Value = curtime;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1430
// Name: public: virtual void CBaseEntity::ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CBaseEntity::ModifyOrAppendCriteria(
        CBaseEntity *this@<ecx>,
        float a2@<esi>,
        ResponseRules::CriteriaSet *set)
{
  int v4; // eax
  const char *v5; // eax
  const char *pszValue; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  float v11; // xmm0_4
  const char *v12; // eax
  int i; // esi
  GLOBALESTATE State; // eax
  const char *v15; // eax
  edict_t *pEdicts; // esi
  edict_t *v17; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v19; // eax
  float szGlobalName; // [esp+18h] [ebp+8h]
  const char *szGlobalNamea; // [esp+18h] [ebp+8h]

  v4 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: 100);
  v5 = UTIL_VarArgs(format: "%d", v4);
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "randomnum", value: v5, weight: a2);
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "map", value: pszValue, weight: 1.0);
  v8 = this->m_iClassname.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "classname", value: v8, weight: 1.0);
  v9 = this->m_iName.m_Value.pszValue;
  if ( v9 == nullptr )
    v9 = locale;
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "name", value: v9, weight: 1.0);
  v10 = UTIL_VarArgs(format: "%i", this->m_iHealth.m_Value);
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "health", value: v10, weight: 1.0);
  if ( this->GetMaxHealth(this) <= 0 )
  {
    v11 = 0.0;
  }
  else
  {
    szGlobalName = (float)this->m_iHealth.m_Value;
    v11 = szGlobalName / (float)this->GetMaxHealth(this);
  }
  v12 = UTIL_VarArgs(format: "%.3f", v11);
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "healthfrac", value: v12, weight: 1.0);
  for ( i = 0; i < GlobalEntity_GetNumGlobals(); ++i )
  {
    szGlobalNamea = GlobalEntity_GetName(globalIndex: i);
    State = GlobalEntity_GetState(globalIndex: i);
    v15 = UTIL_VarArgs(format: "%i", State);
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: szGlobalNamea, value: v15, weight: 1.0);
  }
  CBaseEntity::AppendContextToCriteria(this, set, prefix: locale);
  if ( hl2_episodic.m_pParent != nullptr && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "episodic", value: "1", weight: 1.0);
  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v17 = (pEdicts->m_fStateFlags & 2) == 0 ? pEdicts : nullptr;
  else
    v17 = nullptr;
  if ( v17 != nullptr || pEdicts != nullptr && (v17 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
  {
    m_pUnk = v17->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v19 = m_pUnk->GetBaseEntity(this: m_pUnk);
      if ( v19 != nullptr )
        CBaseEntity::AppendContextToCriteria(this: v19, set, prefix: "world");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1680
// Name: public: static void CBaseEntity::EmitSentenceByIndex(class IRecipientFilter __near &,int,int,int,float,enum soundlevel_t,int,int,class Vector const __near *,class Vector const __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::EmitSentenceByIndex(
        IRecipientFilter *filter,
        int iEntIndex,
        int iChannel,
        int iSentenceIndex,
        float flVolume,
        soundlevel_t iSoundlevel,
        int iFlags,
        int iPitch,
        const Vector *pOrigin,
        const Vector *pDirection,
        int bUpdatePositions,
        float soundtime)
{
  CUtlVector<Vector,CUtlMemory<Vector,int> > dummy; // [esp+30h] [ebp-14h] BYREF

  memset(&dummy, 0, sizeof(dummy));
  ((void (__stdcall *)(IRecipientFilter *, int, int, int, _DWORD, soundlevel_t, _DWORD, int, int, const Vector *, const Vector *, CUtlVector<Vector,CUtlMemory<Vector,int> > *, int, _DWORD, int))enginesound->EmitSentenceByIndex)(
    a1: filter,
    a2: iEntIndex,
    a3: iChannel,
    a4: iSentenceIndex,
    a5: LODWORD(flVolume),
    a6: iSoundlevel,
    a7: 0,
    a8: iFlags,
    a9: iPitch,
    a10: pOrigin,
    a11: pDirection,
    a12: &dummy,
    a13: bUpdatePositions,
    a14: LODWORD(soundtime),
    a15: -1);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dummy);
}

//------------------------------------------------------------------------------
// Address: 0x100C1700
// Name: public: void CBaseEntity::RemoveDeferred(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RemoveDeferred(CBaseEntity *this)
{
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100C1770
// Name: public: void CBaseEntity::SUB_StartFadeOut(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SUB_StartFadeOut(CBaseEntity *this, float delay, bool notSolid)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_FadeOut, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + delay, szContext: nullptr);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  if ( this->m_nRenderMode.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 0;
  }
  if ( notSolid )
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    if ( vec3_angle.x != this->m_vecAngVelocity.x
      || vec3_angle.y != this->m_vecAngVelocity.y
      || vec3_angle.z != this->m_vecAngVelocity.z )
    {
      this->m_vecAngVelocity = vec3_angle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C18A0
// Name: public: void CBaseEntity::SUB_StartFadeOutInstant(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SUB_StartFadeOutInstant(CBaseEntity *this)
{
  CBaseEntity::SUB_StartFadeOut(this, delay: 0.0, notSolid: true);
}

//------------------------------------------------------------------------------
// Address: 0x100C18C0
// Name: void CC_Ent_Orient(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Orient(CBaseEntity *args)
{
  CBaseEntity *v1; // edi
  CBaseEntity *v2; // esi
  bool v3; // zf
  QAngle vecPlayerAngles; // [esp+4h] [ebp-18h] BYREF
  QAngle vecEntAngles; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v1 = args;
  if ( (int)args->__vftable >= 2 )
  {
    if ( CC_GetCommandEnt((const CCommand *)args, ent: &args, vecTargetPoint: nullptr, vecPlayerAngle: &vecPlayerAngles) != 0 )
    {
      v2 = args;
      if ( (args->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: args, a2: (int)&savedregs);
      v3 = v1->__vftable == (CBaseEntity_vtbl *)3;
      vecEntAngles = v2->m_angAbsRotation;
      if ( !v3 || V_strncmp(s1: (const char *)v1[1].m_nSimulationTick, s2: "allangles", count: 9) != 0 )
      {
        vecEntAngles.y = vecPlayerAngles.y;
        CBaseEntity::SetAbsAngles(this: v2, absAngles: &vecEntAngles);
      }
      else
      {
        vecEntAngles = vecPlayerAngles;
        CBaseEntity::SetAbsAngles(this: v2, absAngles: &vecEntAngles);
      }
    }
  }
  else
  {
    _Msg(a1: "Format: ent_orient <entity name> <optional: allangles>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C22C0
// Name: public: void CUtlCachedFileData<class CModelSoundsCache>::SaveManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CModelSoundsCache>::SaveManifest(CUtlCachedFileData<CModelSoundsCache> *this)
{
  signed int m_Size; // esi
  CUtlCachedFileData<CModelSoundsCache> *v2; // ebx
  int Inorder; // edi
  signed int v4; // ebx
  CSortedCacheFile *m_pMemory; // ecx
  CSortedCacheFile *v6; // ebx
  int *p_index; // edi
  const char *v8; // eax
  const char *v9; // eax
  void *v10; // eax
  void *v11; // esi
  char fn[512]; // [esp+Ch] [ebp-660h] BYREF
  char path[512]; // [esp+20Ch] [ebp-460h] BYREF
  char manifest_name[512]; // [esp+40Ch] [ebp-260h] BYREF
  char v15; // [esp+60Ch] [ebp-60h] BYREF
  CUtlBuffer buf; // [esp+614h] [ebp-58h] BYREF
  CSortedCacheFile insert; // [esp+644h] [ebp-28h] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+64Ch] [ebp-20h] BYREF
  CUtlCachedFileData<CModelSoundsCache> *i; // [esp+668h] [ebp-4h]

  m_Size = 0;
  v2 = this;
  i = this;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &v2->m_Elements);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      insert.handle = v2->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      list.m_bNeedsSort = true;
      v4 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
          this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v4 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v4 + 1],
          src: &list.m_Memory.m_pMemory[v4],
          count: 8 * (m_Size - v4 - 1));
        m_pMemory = list.m_Memory.m_pMemory;
      }
      v6 = &m_pMemory[v4];
      if ( v6 != nullptr )
      {
        v6->handle = insert.handle;
        v6->index = Inorder;
      }
      Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &i->m_Elements,
                                    i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v2 = i;
    }
    if ( list.m_bNeedsSort && m_Size > 1 )
    {
      insert.handle = list.m_pLessContext;
      insert.index = (int)&v15;
      qsort_s(
        base: list.m_Memory.m_pMemory,
        num: m_Size,
        width: 8u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
        context: &insert);
    }
    v2 = i;
  }
  if ( m_Size > 0 )
  {
    p_index = &list.m_Memory.m_pMemory->index;
    for ( i = (CUtlCachedFileData<CModelSoundsCache> *)m_Size;
          i != nullptr;
          i = (CUtlCachedFileData<CModelSoundsCache> *)((char *)i - 1) )
    {
      ((void (__stdcall *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t *, char *, int))g_pFullFileSystem->String)(
        a1: &v2->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
        a2: fn,
        a3: 512);
      CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\r\n", fn);
      p_index += 2;
    }
  }
  v8 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v8, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v9 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v9, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD")
    && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD") )
  {
    g_pFullFileSystem->SetFileWritable(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: manifest_name,
      a3: true,
      a4: "MOD");
  }
  v10 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "wb", a4: 0);
  v11 = v10;
  if ( v10 != nullptr )
  {
    g_pFullFileSystem->Write(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: buf.m_Memory.m_pMemory,
      a3: buf.m_Put,
      a4: v10);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11);
  }
  else
  {
    _Warning(a1: "Unable to persist cache manifest '%s', check file permissions\n", manifest_name);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100C26D0
// Name: public: void CBaseEntity::StopFollowingEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::StopFollowingEntity(CBaseEntity *this)
{
  unsigned int m_Index; // eax

  if ( (this->m_fEffects.m_Value & 1) != 0 && this->m_MoveType.m_Value == 0 )
  {
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      this->SetParent(this, a2: nullptr, a3: -1);
      CBaseEntity::RemoveEffects(this, nEffects: 1);
      CCollisionProperty::SetSolidFlags(
        this: &this->m_Collision,
        flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
      CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
      CBaseEntity::CollisionRulesChanged(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2760
// Name: public: virtual void CBaseEntity::SetParent(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetParent(CBaseEntity *this, CBaseEntity *pParentEntity, int iAttachment)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v6; // eax
  CBaseEntityList *v7; // edi
  CBaseEntity *v8; // ecx
  unsigned int v9; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  char *DataObject; // edi
  int v14; // eax
  bool v15; // zf
  CEntInfo *v16; // eax
  IHandleEntity *v17; // eax
  CBaseEntity *RootMoveParent; // eax
  int v19; // eax
  struct CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  unsigned int v21; // eax
  CBaseEntity *v22; // ecx
  edict_t *m_pPev; // ecx
  float z; // edx
  IPhysicsObject *m_pPhysicsObject; // ecx
  const char *pszValue; // eax
  const char *DebugName; // eax
  const char *v28; // [esp+0h] [ebp-FCh]
  VMatrix tmp; // [esp+10h] [ebp-ECh] BYREF
  EntityMatrix childMatrix; // [esp+50h] [ebp-ACh] BYREF
  QAngle angles; // [esp+90h] [ebp-6Ch] BYREF
  EntityMatrix matrix; // [esp+9Ch] [ebp-60h] BYREF
  Vector localOrigin; // [esp+DCh] [ebp-20h] BYREF
  __int64 v34; // [esp+E8h] [ebp-14h]
  float v35; // [esp+F0h] [ebp-Ch]
  CBaseEntity *pEntity; // [esp+F4h] [ebp-8h]
  bool bWasNotParented; // [esp+FBh] [ebp-1h]

  if ( iAttachment == -1 )
    LOBYTE(iAttachment) = this->m_iParentAttachment.m_Value;
  m_Index = this->m_pParent.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  bWasNotParented = m_pEntity == nullptr;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    pEntity = nullptr;
  else
    pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  UnlinkFromParent(pRemove: this);
  if ( pParentEntity != nullptr )
    this->m_pParent.m_Index = pParentEntity->GetRefEHandle(this: pParentEntity)->m_Index;
  else
    this->m_pParent.m_Index = -1;
  v6 = this->m_pParent.m_Index;
  v7 = g_pEntityList;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v8 = nullptr;
  else
    v8 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  if ( v8 == this )
  {
    this->m_pParent.m_Index = -1;
    v7 = g_pEntityList;
  }
  v9 = this->m_pParent.m_Index;
  if ( v9 == -1
    || (v10 = (unsigned __int16)v9,
        v11 = &v7->m_EntPtrArray[(unsigned __int16)v9],
        v12 = HIWORD(v9),
        v11->m_SerialNumber != v12)
    || v11->m_pEntity == nullptr )
  {
    this->m_iParent.pszValue = nullptr;
    DataObject = (char *)CBaseEntity::GetDataObject(this, type: 2);
    if ( DataObject != nullptr )
    {
      UTIL_ParentToWorldSpace(pEntity, vecPosition: (Vector *)(DataObject + 8), quat: (Quaternion *)(DataObject + 20));
      UTIL_ParentToWorldSpace(pEntity, vecPosition: (Vector *)(DataObject + 40), quat: (Quaternion *)(DataObject + 52));
    }
    ((void (__thiscall *)(CBaseEntity *, _DWORD))this->UpdatePhysicsShadowToCurrentPosition)(a1: this, a2: 0);
    return;
  }
  v14 = v10;
  v15 = v7->m_EntPtrArray[v14].m_SerialNumber == v12;
  v16 = &v7->m_EntPtrArray[v14];
  if ( v15 )
    v17 = v16->m_pEntity;
  else
    v17 = nullptr;
  this->m_iParent.pszValue = (const char *)v17[51].__vftable;
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFEFF);
  if ( pParentEntity != nullptr )
  {
    RootMoveParent = CBaseEntity::GetRootMoveParent(this: pParentEntity);
    v19 = RootMoveParent->m_Collision.GetSolid(this: &RootMoveParent->m_Collision);
    p_m_Collision = &this->m_Collision;
    if ( v19 == 1 )
    {
      CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x100);
    }
    else if ( this->m_Collision.GetSolid(this: p_m_Collision) == SOLID_BSP )
    {
      CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
    }
  }
  if ( this->m_Network.m_pPev != nullptr )
  {
    v21 = this->m_pParent.m_Index;
    if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
      v22 = nullptr;
    else
      v22 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
    LinkChild(pParent: v22, pChild: this);
    if ( this->m_iParentAttachment.m_Value != (_BYTE)iAttachment )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xD5u);
      }
      this->m_iParentAttachment.m_Value = iAttachment;
    }
    EntityMatrix::InitFromEntity(this: &matrix, pEntity: pParentEntity, iAttachment: this->m_iParentAttachment.m_Value);
    EntityMatrix::InitFromEntityLocal(this: &childMatrix, entity: this);
    z = this->m_vecOrigin.m_Value.z;
    v34 = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
    v35 = z;
    localOrigin.x = (float)((float)(matrix.m[1][0] * (float)(*((float *)&v34 + 1) - matrix.m[1][3]))
                          + (float)(matrix.m[0][0] * (float)(*(float *)&v34 - matrix.m[0][3])))
                  + (float)(matrix.m[2][0] * (float)(z - matrix.m[2][3]));
    localOrigin.y = (float)((float)(matrix.m[1][1] * (float)(*((float *)&v34 + 1) - matrix.m[1][3]))
                          + (float)(matrix.m[0][1] * (float)(*(float *)&v34 - matrix.m[0][3])))
                  + (float)(matrix.m[2][1] * (float)(z - matrix.m[2][3]));
    localOrigin.z = (float)((float)(matrix.m[1][2] * (float)(*((float *)&v34 + 1) - matrix.m[1][3]))
                          + (float)(matrix.m[0][2] * (float)(*(float *)&v34 - matrix.m[0][3])))
                  + (float)(matrix.m[2][2] * (float)(z - matrix.m[2][3]));
    VMatrix::Transpose(this: &matrix, result: &tmp);
    VMatrix::MatrixMul(this: &tmp, vm: &childMatrix, out: &matrix);
    MatrixAngles(a1: (int)this, src: &matrix, vAngles: &angles);
    CBaseEntity::SetLocalAngles(this, &angles);
    UTIL_SetOrigin(entity: this, vecOrigin: &localOrigin, bFireTriggers: false);
    if ( bWasNotParented )
      CBaseEntity::TransformStepData_WorldToParent(this, pParent: this);
    else
      CBaseEntity::TransformStepData_ParentToParent(this, pOldParent: pEntity, pNewParent: this);
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr )
  {
LABEL_56:
    CBaseEntity::CollisionRulesChanged(this);
    return;
  }
  if ( !m_pPhysicsObject->IsStatic(this: m_pPhysicsObject) )
  {
    ((void (__thiscall *)(CBaseEntity *, _DWORD))this->UpdatePhysicsShadowToCurrentPosition)(a1: this, a2: 0);
    goto LABEL_56;
  }
  if ( this->m_pPhysicsObject->IsAttachedToConstraint(this: this->m_pPhysicsObject, a2: false) )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v28 = pszValue;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "SetParent on static object, all constraints attached to %s (%s)will now be broken!\n", DebugName, v28);
  }
  this->VPhysicsDestroyObject(this);
  CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: false, allowPhysicsRotation: false, pSolid: nullptr);
  CBaseEntity::CollisionRulesChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C2BA0
// Name: public: virtual void CBaseEntity::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::UpdateOnRemove(CBaseEntity *this)
{
  const char *pszValue; // eax
  int Index; // eax
  const char *v4; // eax
  const char *v5; // eax
  unsigned int v6; // ebx
  edict_t *m_pPev; // ecx
  const char *v8; // eax
  int i; // edi
  CBaseEntity **m_pMemory; // eax
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > childrenList; // [esp+Ch] [ebp-14h] BYREF

  g_bReceivedChainedUpdateOnRemove = true;
  this->StopLoopingSounds(this);
  if ( this->m_bLagCompensate )
    lagcompensation->RemoveAdditionalEntity(this: lagcompensation, a2: this);
  CGlobalEntityList::NotifyRemoveEntity(this: &gEntList, pBaseEnt: this);
  if ( this->m_Network.m_pPev != nullptr )
    CBaseEntity::AddFlag(this, flags: 0x8000000);
  pszValue = this->m_iGlobalname.pszValue;
  if ( pszValue != nullptr )
  {
    Index = GlobalEntity_GetIndex(pGlobalname: pszValue);
    GlobalEntity_SetState(globalIndex: Index, state: GLOBAL_DEAD);
  }
  if ( this->m_bForcePurgeFixedupStrings )
  {
    if ( this->m_iName.m_Value.pszValue != nullptr )
    {
      v4 = this->m_iName.m_Value.pszValue;
      if ( v4 == nullptr )
        v4 = locale;
      RemovePooledString(pszValue: v4);
    }
    if ( this->m_iszScriptId.pszValue != nullptr )
    {
      v5 = this->m_iszScriptId.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      RemovePooledString(pszValue: v5);
    }
  }
  this->VPhysicsDestroyObject(this);
  v6 = this->m_fEffects.m_Value & 0xFFFFFFFE;
  if ( this->m_fEffects.m_Value != v6 )
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
    this->m_fEffects.m_Value = v6;
  }
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  UnlinkFromParent(pRemove: this);
  memset(&childrenList, 0, sizeof(childrenList));
  GetAllChildren(pParent: this, list: &childrenList);
  if ( childrenList.m_Size != 0 )
  {
    v8 = this->m_iClassname.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    _DevMsg(a1: 2, a2: "Warning: Deleting orphaned children of %s\n", v8);
    for ( i = childrenList.m_Size - 1; i >= 0; --i )
      UTIL_Remove(oldObj: childrenList.m_Memory.m_pMemory[i]);
  }
  CBaseEntity::SetGroundEntity(this, ground: nullptr);
  if ( this->m_hScriptInstance != nullptr )
  {
    g_pScriptVM->RemoveInstance(this: g_pScriptVM, a2: this->m_hScriptInstance);
    this->m_hScriptInstance = nullptr;
  }
  m_pMemory = childrenList.m_Memory.m_pMemory;
  childrenList.m_Size = 0;
  if ( childrenList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( childrenList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: childrenList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      childrenList.m_Memory.m_pMemory = nullptr;
    }
    childrenList.m_Memory.m_nAllocationCount = 0;
  }
  childrenList.m_pElements = m_pMemory;
  if ( childrenList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100C2D80
// Name: public: void CBaseEntity::VPhysicsUpdatePusher(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::VPhysicsUpdatePusher(CBaseEntity *this, IPhysicsObject *pPhysics)
{
  physicspushlist_t *DataObject; // ebx
  bool v4; // al
  bool v5; // al
  int v6; // ecx
  CBaseEntity *v7; // xmm0_4
  CBaseEntity *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // ecx
  bool (__thiscall *GetContactPoint)(IPhysicsObject *, Vector *, IPhysicsObject **); // edx
  float *p_z; // esi
  CBaseEntity *v14; // eax
  const Vector *AbsOrigin; // eax
  CBaseEntity *v16; // eax
  float z; // edx
  float v18; // eax
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float m_flLocalTime; // xmm0_4
  float m_flMoveDoneTime; // xmm1_4
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > list; // [esp+0h] [ebp-64h] BYREF
  Vector origin; // [esp+14h] [ebp-50h] BYREF
  QAngle angles; // [esp+20h] [ebp-44h] BYREF
  pushblock_t params; // [esp+2Ch] [ebp-38h] BYREF
  Vector v29; // [esp+40h] [ebp-24h] BYREF
  CBaseEntity *pEntity; // [esp+4Ch] [ebp-18h]
  IPhysicsObject *pOther; // [esp+50h] [ebp-14h] BYREF
  float physLocalTime; // [esp+54h] [ebp-10h]
  int i; // [esp+58h] [ebp-Ch]
  CBaseEntity *pBlocked; // [esp+5Ch] [ebp-8h]
  bool checkrot; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  CHandle<CBaseEntity> *checkmove; // [esp+6Ch] [ebp+8h]
  bool checkmove_3; // [esp+6Fh] [ebp+Bh]

  *(float *)&pBlocked = this->m_flLocalTime - this->m_flVPhysicsUpdateLocalTime;
  if ( *(float *)&pBlocked > 0.0 && PhysIsFinalTick() )
  {
    if ( this->m_Collision.GetSolid(this: &this->m_Collision) != SOLID_BSP
      && pPhysics->GetShadowPosition(this: pPhysics, a2: &origin, a3: &angles) != 0 )
    {
      memset(&list, 0, sizeof(list));
      GetAllInHierarchy(pParent: this, &list);
      DataObject = nullptr;
      if ( CBaseEntity::HasDataObjectType(this, type: 5) )
        DataObject = (physicspushlist_t *)CBaseEntity::GetDataObject(this, type: 5);
      v4 = vec3_angle.x != this->m_vecAngVelocity.x
        || vec3_angle.y != this->m_vecAngVelocity.y
        || vec3_angle.z != this->m_vecAngVelocity.z;
      checkrot = v4;
      v5 = vec3_origin.x != this->m_vecVelocity.m_Value.x
        || vec3_origin.y != this->m_vecVelocity.m_Value.y
        || vec3_origin.z != this->m_vecVelocity.m_Value.z;
      checkmove_3 = v5;
      *(float *)&v6 = 0.0;
      params.moveBackFraction = 0.0;
      v7 = pBlocked;
      params.pRootParent = this;
      params.pList = DataObject;
      params.pBlockedEntity = nullptr;
      LODWORD(params.movetime) = pBlocked;
      *(float *)&i = 0.0;
      if ( list.m_Size > 0 )
      {
        do
        {
          v8 = list.m_Memory.m_pMemory[v6];
          if ( v8->m_Collision.m_nSolidType.m_Value != 0 && (v8->m_Collision.m_usSolidFlags.m_Value & 4) == 0 )
          {
            CheckPushedEntity(pEntity: v8, a2: COERCE_FLOAT(&savedregs), a3: &params);
            v7 = pBlocked;
            v6 = i;
          }
          i = ++v6;
        }
        while ( v6 < list.m_Size );
        if ( params.pBlockedEntity != nullptr )
        {
          v9 = params.moveBackFraction * *(float *)&v7;
          *(float *)&i = params.moveBackFraction * *(float *)&v7;
          if ( (float)(params.moveBackFraction * *(float *)&v7) > 0.0 )
          {
            v10 = (float)(*(float *)&v7 * 0.99000001) + this->m_flVPhysicsUpdateLocalTime;
            physLocalTime = this->m_flLocalTime - v9;
            if ( v10 >= physLocalTime )
            {
              m_pPhysicsObject = params.pBlockedEntity->m_pPhysicsObject;
              GetContactPoint = m_pPhysicsObject->GetContactPoint;
              *(float *)&pBlocked = 0.0;
              if ( GetContactPoint(this: m_pPhysicsObject, a2: nullptr, a3: &pOther) )
                *(float *)&pBlocked = COERCE_FLOAT((int)pOther->GetGameData(this: pOther));
              if ( DataObject != nullptr )
              {
                CBaseEntity::SetLocalOrigin(this, origin: &DataObject->localOrigin);
                CBaseEntity::SetLocalAngles(this, angles: &DataObject->localAngles);
                physLocalTime = DataObject->localMoveTime;
                *(float *)&i = 0.0;
                if ( DataObject->pushedCount > 0 )
                {
                  checkmove = DataObject->pushedEnts;
                  p_z = &DataObject->pushVec[0].z;
                  do
                  {
                    v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: checkmove);
                    pEntity = v14;
                    if ( v14 != nullptr )
                    {
                      AbsOrigin = CBaseEntity::GetAbsOrigin(this: v14);
                      *(float *)&params.pBlockedEntity = AbsOrigin->x - *(p_z - 2);
                      params.moveBackFraction = AbsOrigin->y - *(p_z - 1);
                      params.movetime = AbsOrigin->z - *p_z;
                      CBaseEntity::SetAbsOrigin(this: pEntity, absOrigin: (const Vector *)&params.pBlockedEntity);
                    }
                    ++checkmove;
                    p_z += 3;
                    ++i;
                  }
                  while ( i < DataObject->pushedCount );
                }
                *(float *)&v16 = COERCE_FLOAT(
                                   FindPhysicsBlocker(
                                     p_normal: (Vector *)DataObject,
                                     pPhysics: this->m_pPhysicsObject,
                                     list: DataObject,
                                     pushVel: DataObject->pushVec));
                if ( *(float *)&v16 != 0.0 )
                  pBlocked = v16;
              }
              else
              {
                z = this->m_vecOrigin.m_Value.z;
                v18 = this->m_angRotation.m_Value.z;
                *(_QWORD *)&v29.x = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
                *(_QWORD *)&params.pBlockedEntity = *(_QWORD *)&this->m_angRotation.m_Value.x;
                v29.z = z;
                params.movetime = v18;
                if ( checkmove_3 )
                {
                  v19 = this->m_vecVelocity.m_Value.z;
                  v20 = v29.x - (float)(this->m_vecVelocity.m_Value.x * *(float *)&i);
                  v29.y = v29.y - (float)(this->m_vecVelocity.m_Value.y * *(float *)&i);
                  v29.x = v20;
                  v29.z = v29.z - (float)(v19 * *(float *)&i);
                }
                if ( checkrot )
                {
                  v21 = this->m_vecAngVelocity.y * *(float *)&i;
                  v22 = this->m_vecAngVelocity.z * *(float *)&i;
                  *(float *)&params.pBlockedEntity = *(float *)&params.pBlockedEntity
                                                   - (float)(*(float *)&i * this->m_vecAngVelocity.x);
                  params.moveBackFraction = params.moveBackFraction - v21;
                  params.movetime = params.movetime - v22;
                }
                CBaseEntity::SetLocalOrigin(this, origin: &v29);
                CBaseEntity::SetLocalAngles(this, angles: (const QAngle *)&params.pBlockedEntity);
              }
              if ( *(float *)&pBlocked != 0.0 )
                this->Blocked(this, a2: pBlocked);
              this->m_flLocalTime = physLocalTime;
            }
          }
        }
      }
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
    }
    if ( CBaseEntity::HasDataObjectType(this, type: 5) )
      CBaseEntity::DestroyDataObject(this, type: 5);
    m_flLocalTime = this->m_flLocalTime;
    m_flMoveDoneTime = this->m_flMoveDoneTime;
    this->m_flVPhysicsUpdateLocalTime = m_flLocalTime;
    if ( m_flLocalTime >= m_flMoveDoneTime && m_flMoveDoneTime > 0.0 )
    {
      this->m_flMoveDoneTime = -1.0;
      CBaseEntity::CheckHasGamePhysicsSimulation(this);
      this->MoveDone(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C31F0
// Name: public: void CBaseEntity::MakeDormant(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::MakeDormant(CBaseEntity *this)
{
  this->m_iEFlags |= 2u;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  if ( this->m_Network.m_pPev != nullptr )
  {
    this->m_iEFlags |= 2u;
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    CBaseEntity::AddEffects(this, nEffects: 32);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3260
// Name: public: static class CBaseEntity __near * CBaseEntity::CreateNoSpawn(char const __near *,class Vector const __near &,class QAngle const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CBaseEntity::CreateNoSpawn(
        const char *szName,
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        CBaseEntity *pOwner)
{
  CBaseEntity *result; // eax
  CBaseEntity *v5; // esi

  result = CreateEntityByName(className: szName, iForceEdictIndex: -1, bNotify: false);
  v5 = result;
  if ( result != nullptr )
  {
    CBaseEntity::SetLocalOrigin(this: result, origin: vecOrigin);
    CBaseEntity::SetLocalAngles(this: v5, angles: vecAngles);
    v5->SetOwnerEntity(this: v5, a2: pOwner);
    CGlobalEntityList::NotifyCreateEntity(this: &gEntList, pEnt: v5);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C32B0
// Name: public: void CBaseEntity::InputColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputColor(CBaseEntity *this, inputdata_t *inputdata)
{
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: inputdata->value.iVal,
    gVal: BYTE1(inputdata->value.iszVal.pszValue),
    bVal: BYTE2(inputdata->value.iVal));
}

//------------------------------------------------------------------------------
// Address: 0x100C32E0
// Name: public: void CBaseEntity::SetParentAttachment(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetParentAttachment(
        CBaseEntity *this,
        const char *szInputName,
        const char *szAttachment,
        bool bMaintainOffset)
{
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  const char *v9; // edi
  const char *v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseAnimating *v14; // eax
  const char *v15; // edi
  const char *v16; // eax
  int v17; // eax
  unsigned __int8 v18; // bl
  const char *pszValue; // ebx
  const char *DebugName; // eax
  edict_t *m_pPev; // ecx
  unsigned int v22; // eax
  CBaseEntity *v23; // ecx

  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1
    && (v6 = (unsigned __int16)m_Index,
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v8 = HIWORD(m_Index),
        v7->m_SerialNumber == v8)
    && v7->m_pEntity != nullptr )
  {
    v11 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v8;
    v12 = &g_pEntityList->m_EntPtrArray[v6];
    if ( v11 )
      m_pEntity = v12->m_pEntity;
    else
      m_pEntity = nullptr;
    v14 = (CBaseAnimating *)m_pEntity->__vftable[17].GetRefEHandle(this: m_pEntity);
    if ( v14 != nullptr )
    {
      v17 = CBaseAnimating::LookupAttachment(this: v14, szName: szAttachment);
      v18 = v17;
      if ( v17 != 0 )
      {
        if ( this->m_iParentAttachment.m_Value != (_BYTE)v17 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xD5u);
          }
          this->m_iParentAttachment.m_Value = v18;
        }
        v22 = this->m_pParent.m_Index;
        if ( v22 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber != HIWORD(v22) )
          v23 = nullptr;
        else
          v23 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity;
        this->SetParent(this, a2: v23, a3: this->m_iParentAttachment.m_Value);
        CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
        if ( !bMaintainOffset )
        {
          CBaseEntity::SetLocalOrigin(this, origin: &vec3_origin);
          CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
        }
      }
      else
      {
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        DebugName = CBaseEntity::GetDebugName(this);
        _Warning(
          a1: "ERROR: Tried to %s for entity %s (%s), but it has no attachment named %s.\n",
          szInputName,
          pszValue,
          DebugName,
          szAttachment);
      }
    }
    else
    {
      v15 = this->m_iClassname.pszValue;
      if ( v15 == nullptr )
        v15 = locale;
      v16 = CBaseEntity::GetDebugName(this);
      _Warning(a1: "ERROR: Tried to %s for entity %s (%s), but its parent has no model.\n", szInputName, v15, v16);
    }
  }
  else
  {
    v9 = this->m_iClassname.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    v10 = CBaseEntity::GetDebugName(this);
    _Warning(a1: "ERROR: Tried to %s for entity %s (%s), but it has no parent.\n", szInputName, v9, v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3480
// Name: public: void CBaseEntity::InputSetParentAttachment(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputSetParentAttachment(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CBaseEntity::SetParentAttachment(
        this,
        szInputName: "SetParentAttachment",
        szAttachment: locale,
        bMaintainOffset: false);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CBaseEntity::SetParentAttachment(this, szInputName: "SetParentAttachment", szAttachment: iVal, bMaintainOffset: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C34D0
// Name: public: void CBaseEntity::InputSetParentAttachmentMaintainOffset(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputSetParentAttachmentMaintainOffset(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CBaseEntity::SetParentAttachment(
        this,
        szInputName: "SetParentAttachmentMaintainOffset",
        szAttachment: locale,
        bMaintainOffset: true);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CBaseEntity::SetParentAttachment(
    this,
    szInputName: "SetParentAttachmentMaintainOffset",
    szAttachment: iVal,
    bMaintainOffset: true);
}

//------------------------------------------------------------------------------
// Address: 0x100C3520
// Name: TeleportEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall TeleportEntity(
        TeleportListEntry_t *entry@<eax>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CBasePlayer *pSourceEntity,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        BOOL bUseSlowHighAccuracyContacts)
{
  float z; // ecx
  float v10; // edx
  CBasePlayer *pEntity; // esi
  __int64 v12; // xmm0_8
  CBaseEntity::NetworkVar_m_Collision_vtbl *v13; // eax
  int (__thiscall *GetSolidFlags)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  int v15; // eax
  IPhysicsObject *m_pPhysicsObject; // edi
  CBasePlayer_vtbl *v17; // eax
  void (__thiscall *ReportSystemEvent)(INotify *, CBaseEntity *, notify_system_event_t, const notify_system_event_params_t *); // edx
  Vector v20[2]; // [esp+0h] [ebp-40h] BYREF
  char v21; // [esp+18h] [ebp-28h]
  QAngle prevAngles; // [esp+1Ch] [ebp-24h]
  Vector prevOrigin; // [esp+28h] [ebp-18h]
  int nSolidFlags; // [esp+34h] [ebp-Ch]
  const QAngle *rotAngles; // [esp+38h] [ebp-8h]
  bool bEnablePhysCollision; // [esp+3Fh] [ebp-1h]
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  z = entry->prevAbsOrigin.z;
  v10 = entry->prevAbsAngles.z;
  pEntity = (CBasePlayer *)entry->pEntity;
  *(_QWORD *)&prevOrigin.x = *(_QWORD *)&entry->prevAbsOrigin.x;
  v12 = *(_QWORD *)&entry->prevAbsAngles.x;
  v13 = pEntity->m_Collision.CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::__vftable;
  prevOrigin.z = z;
  prevAngles.z = v10;
  GetSolidFlags = v13->GetSolidFlags;
  *(_QWORD *)&prevAngles.x = v12;
  v15 = ((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, int, int))GetSolidFlags)(
          a1: &pEntity->m_Collision,
          a2: a3,
          a3: a4,
          a4: a2);
  m_pPhysicsObject = pEntity->m_pPhysicsObject;
  nSolidFlags = v15;
  bEnablePhysCollision = false;
  if ( m_pPhysicsObject != nullptr && bUseSlowHighAccuracyContacts )
  {
    bEnablePhysCollision = m_pPhysicsObject->IsCollisionEnabled(this: m_pPhysicsObject);
    if ( bEnablePhysCollision )
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: false);
    CCollisionProperty::SetSolidFlags(
      this: &pEntity->m_Collision,
      flags: pEntity->m_Collision.m_usSolidFlags.m_Value | 4);
  }
  if ( pSourceEntity == pEntity )
  {
    if ( newAngles != nullptr )
    {
      CBaseEntity::SetLocalAngles(this: pEntity, angles: newAngles);
      if ( pEntity->IsPlayer(this: pEntity) )
        CBasePlayer::SnapEyeAngles(this: pEntity, viewAngles: newAngles);
    }
    if ( newVelocity != nullptr )
    {
      if ( m_pPhysicsObject == nullptr || pEntity->m_MoveType.m_Value != 6 )
        CBaseEntity::SetAbsVelocity(this: pEntity, vecAbsVelocity: newVelocity);
      CBaseEntity::SetBaseVelocity(this: pEntity, v: &vec3_origin);
    }
    if ( newPosition != nullptr )
    {
      CBaseEntity::AddEffects(this: pEntity, nEffects: 8);
      UTIL_SetOrigin(entity: pEntity, vecOrigin: newPosition, bFireTriggers: false);
    }
  }
  else
  {
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  }
  HIBYTE(pSourceEntity) = 0;
  if ( m_pPhysicsObject != nullptr )
  {
    if ( newVelocity != nullptr )
      m_pPhysicsObject->SetVelocity(this: m_pPhysicsObject, a2: newVelocity, a3: nullptr);
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    v17 = pEntity->__vftable;
    rotAngles = &pEntity->m_angAbsRotation;
    if ( v17->IsPlayer(this: pEntity) || pEntity->m_Collision.GetSolid(this: &pEntity->m_Collision) == SOLID_BBOX )
      rotAngles = &vec3_angle;
    else
      HIBYTE(pSourceEntity) = 1;
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    m_pPhysicsObject->SetPosition(
      this: m_pPhysicsObject,
      a2: &pEntity->m_vecAbsOrigin,
      a3: rotAngles,
      a4: bUseSlowHighAccuracyContacts);
  }
  v20[0] = prevOrigin;
  v21 = HIBYTE(pSourceEntity);
  pSourceEntity = (CBasePlayer *)v20;
  ReportSystemEvent = g_pNotify->ReportSystemEvent;
  v20[1] = (Vector)prevAngles;
  ReportSystemEvent(
    this: g_pNotify,
    a2: pEntity,
    a3: NOTIFY_EVENT_TELEPORT,
    a4: (const notify_system_event_params_t *)&pSourceEntity);
  if ( m_pPhysicsObject != nullptr && bUseSlowHighAccuracyContacts )
  {
    CCollisionProperty::SetSolidFlags(this: &pEntity->m_Collision, flags: nSolidFlags);
    if ( bEnablePhysCollision )
      m_pPhysicsObject->EnableCollisions(this: m_pPhysicsObject, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3760
// Name: public: virtual void CBaseEntity::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::Teleport(
        CBaseEntity *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        BOOL bUseSlowHighAccuracyContacts)
{
  int m_Size; // eax
  CBaseEntity **m_pMemory; // edx
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  CBaseEntity **v12; // eax
  int v13; // edi
  int v14; // eax
  void *DataObject; // eax
  TeleportListEntry_t *v16; // eax
  CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > teleportList; // [esp+4h] [ebp-1Ch] BYREF
  int v18; // [esp+18h] [ebp-8h]
  CBaseEntity *pSourceEntity; // [esp+1Ch] [ebp-4h]

  m_Size = g_TeleportStack.m_Size;
  m_pMemory = g_TeleportStack.m_Memory.m_pMemory;
  v8 = 0;
  pSourceEntity = this;
  if ( g_TeleportStack.m_Size <= 0 )
    goto LABEL_6;
  while ( g_TeleportStack.m_Memory.m_pMemory[v8] != this )
  {
    if ( ++v8 >= g_TeleportStack.m_Size )
      goto LABEL_6;
  }
  if ( v8 < 0 )
  {
LABEL_6:
    v9 = g_TeleportStack.m_Size;
    v18 = g_TeleportStack.m_Size;
    if ( g_TeleportStack.m_Size + 1 > g_TeleportStack.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_TeleportStack,
        num: g_TeleportStack.m_Size - g_TeleportStack.m_Memory.m_nAllocationCount + 1);
      m_Size = g_TeleportStack.m_Size;
      m_pMemory = g_TeleportStack.m_Memory.m_pMemory;
    }
    g_TeleportStack.m_Size = m_Size + 1;
    v10 = m_Size - v9;
    v11 = 0;
    g_TeleportStack.m_pElements = m_pMemory;
    if ( v10 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * v10);
      m_pMemory = g_TeleportStack.m_Memory.m_pMemory;
    }
    v12 = &m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = this;
    memset(&teleportList, 0, sizeof(teleportList));
    BuildTeleportList_r(pTeleport: this, &teleportList);
    if ( teleportList.m_Size > 0 )
    {
      v13 = 0;
      do
      {
        TeleportEntity(
          entry: &teleportList.m_Memory.m_pMemory[v13],
          a2: (int)newVelocity,
          a3: v13 * 28,
          a4: v11++,
          (CBasePlayer *)pSourceEntity,
          newPosition,
          newAngles,
          newVelocity,
          bUseSlowHighAccuracyContacts);
        ++v13;
      }
      while ( v11 < teleportList.m_Size );
      this = pSourceEntity;
      v9 = v18;
    }
    v14 = g_TeleportStack.m_Size;
    if ( g_TeleportStack.m_Size > 0 )
    {
      if ( v9 != g_TeleportStack.m_Size - 1 )
      {
        g_TeleportStack.m_Memory.m_pMemory[v9] = g_TeleportStack.m_Memory.m_pMemory[g_TeleportStack.m_Size - 1];
        v14 = g_TeleportStack.m_Size;
      }
      g_TeleportStack.m_Size = v14 - 1;
    }
    DataObject = CBaseEntity::GetDataObject(this, type: 2);
    if ( DataObject != nullptr )
      _V_memset(dest: DataObject, fill: 0, count: 184);
    v16 = teleportList.m_Memory.m_pMemory;
    teleportList.m_Size = 0;
    if ( teleportList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( teleportList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: teleportList.m_Memory.m_pMemory);
        v16 = nullptr;
        teleportList.m_Memory.m_pMemory = nullptr;
      }
      teleportList.m_Memory.m_nAllocationCount = 0;
    }
    teleportList.m_pElements = v16;
    if ( teleportList.m_Memory.m_nGrowSize >= 0 && v16 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C38E0
// Name: void ModelSoundsCache_FinishModel(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ModelSoundsCache_FinishModel(CStudioHdr *hdr)
{
  if ( hdr != nullptr )
  {
    CStudioHdr::Term(this: hdr);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hdr->m_boneParent);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hdr->m_boneFlags);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hdr->m_pStudioHdrCache);
    free(pMem: hdr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3920
// Name: public: void CBaseEntity::InputRunScript(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputRunScript(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // esi
  const char *DebugName; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( iVal != nullptr )
      v5 = iVal;
    else
      v5 = locale;
  }
  else
  {
    v5 = variant_t::ToString(this: p_value);
  }
  if ( CBaseEntity::ValidateScriptScope(this) != 0 )
  {
    if ( CScriptScopeT<CDefScriptScopeBase>::Run(
           this: &this->m_ScriptScope,
           pszScriptText: v5,
           pszScriptName: "InputRunScript") == SCRIPT_ERROR )
    {
      DebugName = CBaseEntity::GetDebugName(this);
      DevWarning(a1: " Entity %s encountered an error in RunScript()\n", DebugName);
    }
  }
  else
  {
    DevMsg(a1: "\n***\nFAILED to create private ScriptScope. ABORTING script\n***\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C39A0
// Name: public: void CBaseEntity::AddContext(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::AddContext(CBaseEntity *this, const char *contextName)
{
  const char *v2; // ebx
  CBaseEntity *v3; // edi
  const char *v4; // eax
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_ResponseContexts; // esi
  const char *v6; // eax
  float v7; // xmm0_4
  int ContextByName; // edi
  RR::CApplyContextOperator *v9; // eax
  int v10; // edi
  const char *m_Previous; // edx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v12; // ebx
  const char *v13; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v14; // ebx
  RR::CApplyContextOperator *Operator; // eax
  char *v16; // ecx
  int v17; // edx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  char key[128]; // [esp+8h] [ebp-170h] BYREF
  char value[128]; // [esp+88h] [ebp-F0h] BYREF
  char v26[64]; // [esp+108h] [ebp-70h] BYREF
  char v27; // [esp+148h] [ebp-30h] BYREF
  char v28; // [esp+14Ch] [ebp-2Ch] BYREF
  char pszValue[4]; // [esp+150h] [ebp-28h] BYREF
  char v30[4]; // [esp+154h] [ebp-24h] BYREF
  char v31[4]; // [esp+158h] [ebp-20h] BYREF
  __int64 v32; // [esp+15Ch] [ebp-1Ch]
  int v33; // [esp+164h] [ebp-14h]
  CBaseEntity *v34; // [esp+168h] [ebp-10h]
  int v35; // [esp+16Ch] [ebp-Ch]
  const char *p; // [esp+170h] [ebp-8h]
  float duration; // [esp+174h] [ebp-4h] BYREF

  v2 = contextName;
  v3 = this;
  v34 = this;
  v4 = contextName;
  if ( contextName != nullptr )
  {
    p_m_ResponseContexts = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_ResponseContexts;
    while ( 1 )
    {
      duration = 0.0;
      v6 = SplitContext(raw: v4, key, keylen: 128, value, valuelen: 128, &duration, entireContext: v2);
      v7 = duration;
      p = v6;
      if ( duration != 0.0 )
      {
        v7 = duration + gpGlobals->curtime;
        duration = v7;
      }
      v35 = LODWORD(v7);
      ContextByName = CBaseEntity::FindContextByName(this: v3, name: key);
      if ( ContextByName == -1 )
      {
        LODWORD(v32) = *(_DWORD *)AllocPooledString(pszValue: v31).pszValue;
        Operator = RR::CApplyContextOperator::FindOperator(pContextString: value);
        if ( Operator->Apply(this: Operator, a2: nullptr, a3: value, a4: v26, a5: 64) != 0 )
          v16 = &v27;
        else
          v16 = &v28;
        v17 = *(_DWORD *)AllocPooledString(pszValue: v16).pszValue;
        m_pMemory = p_m_ResponseContexts[1].m_pMemory;
        m_nAllocationCount = p_m_ResponseContexts->m_nAllocationCount;
        HIDWORD(v32) = v17;
        v33 = v35;
        if ( (int)&m_pMemory->m_Element + 1 > m_nAllocationCount )
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: p_m_ResponseContexts,
            num: (int)&m_pMemory->m_Element - m_nAllocationCount + 1);
        ++p_m_ResponseContexts[1].m_pMemory;
        v20 = p_m_ResponseContexts->m_pMemory;
        v21 = (char *)p_m_ResponseContexts[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_ResponseContexts[1].m_nAllocationCount = (int)p_m_ResponseContexts->m_pMemory;
        if ( v21 > 0 )
          _V_memmove(dest: &v20[(int)m_pMemory + 1], src: &v20[(_DWORD)m_pMemory], count: 12 * v21);
        v22 = (int)&p_m_ResponseContexts->m_pMemory[(_DWORD)m_pMemory];
        if ( v22 != 0 )
        {
          v23 = v33;
          *(_QWORD *)v22 = v32;
          *(_DWORD *)(v22 + 8) = v23;
        }
      }
      else
      {
        v9 = RR::CApplyContextOperator::FindOperator(pContextString: value);
        v10 = ContextByName;
        m_Previous = (const char *)p_m_ResponseContexts->m_pMemory[v10].m_Previous;
        if ( m_Previous == nullptr )
          m_Previous = locale;
        if ( v9->Apply(this: v9, a2: m_Previous, a3: value, a4: v26, a5: 64) != 0 )
        {
          v12 = p_m_ResponseContexts->m_pMemory;
          v12[v10].m_Previous = *(_DWORD *)AllocPooledString(pszValue).pszValue;
        }
        else
        {
          v13 = (const char *)p_m_ResponseContexts->m_pMemory[v10].m_Previous;
          if ( v13 == nullptr )
            v13 = locale;
          _Warning(a1: "RR: could not apply operator %s to prior value %s\n", value, v13);
          v14 = p_m_ResponseContexts->m_pMemory;
          v14[v10].m_Previous = *(_DWORD *)AllocPooledString(pszValue: v30).pszValue;
        }
        v2 = contextName;
        p_m_ResponseContexts->m_pMemory[v10].m_Next = v35;
      }
      if ( p == nullptr )
        break;
      v4 = p;
      v3 = v34;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3BD0
// Name: public: virtual void CBaseEntity::DispatchResponse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DispatchResponse(CBaseEntity *this, const char *conceptName)
{
  ResponseRules::IResponseSystem *v3; // edi
  CBasePlayer *LocalPlayer; // eax
  int v5; // edi
  edict_t *v6; // eax
  soundlevel_t SoundLevel; // [esp+18h] [ebp-210h]
  char response[256]; // [esp+3Ch] [ebp-1ECh] BYREF
  ResponseRules::CRR_Response result; // [esp+13Ch] [ebp-ECh] BYREF
  CPASAttenuationFilter filter; // [esp+1E4h] [ebp-44h] BYREF
  ResponseRules::CriteriaSet set; // [esp+204h] [ebp-24h] BYREF

  v3 = this->GetResponseSystem(this);
  if ( v3 != nullptr )
  {
    ResponseRules::CriteriaSet::CriteriaSet(this: &set);
    ResponseRules::CriteriaSet::AppendCriteria(this: &set, pCriteriaName: "concept", value: conceptName, weight: 5.0);
    this->ModifyOrAppendCriteria(this, a2: &set);
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
      LocalPlayer->ModifyOrAppendPlayerCriteria(this: LocalPlayer, a2: &set);
    ResponseRules::CRR_Response::CRR_Response(this: &result);
    if ( v3->FindBestResponse(this: v3, a2: &set, a3: &result, a4: nullptr) )
    {
      ResponseRules::CRR_Response::GetResponse(this: &result, buf: response, buflen: 0x100u);
      switch ( result.m_Type )
      {
        case 1u:
          CBaseEntity::EmitSound(this, soundname: response, soundtime: 0.0, duration: nullptr);
          break;
        case 2u:
          v5 = SENTENCEG_Lookup(sample: response);
          if ( v5 != -1 )
          {
            CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
            SoundLevel = ResponseRules::CRR_Response::GetSoundLevel(this: &result);
            v6 = CBaseEntity::entindex(this);
            CBaseEntity::EmitSentenceByIndex(
              &filter,
              iEntIndex: (int)v6,
              iChannel: 2,
              iSentenceIndex: v5,
              flVolume: 1.0,
              iSoundlevel: SoundLevel,
              iFlags: 0,
              iPitch: 100,
              pOrigin: nullptr,
              pDirection: nullptr,
              bUpdatePositions: 1,
              soundtime: 0.0);
            CRecipientFilter::~CRecipientFilter(this: &filter);
          }
          break;
        case 3u:
          InstancedScriptedScene(
            pActor: nullptr,
            pszScene: response,
            phSceneEnt: nullptr,
            flPostDelay: 0.0,
            bIsBackground: false,
            response: nullptr,
            bMultiplayer: false,
            filter: nullptr);
          break;
        case 6u:
          CAI_Expresser::FireEntIOFromResponse(response, pInitiator: this);
          break;
        default:
          break;
      }
    }
    ResponseRules::CRR_Response::~CRR_Response(this: &result);
    CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &set.m_Lookup);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3DB0
// Name: public: void CBaseEntity::DumpResponseCriteria(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DumpResponseCriteria(CBaseEntity *this)
{
  const char *pszValue; // eax
  CBaseEntity *v3; // ecx
  const char *v4; // ecx
  CBasePlayer *LocalPlayer; // eax
  ResponseRules::CriteriaSet set; // [esp+8h] [ebp-24h] BYREF

  _Msg(a1: "----------------------------------------------\n");
  if ( this != nullptr )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
    {
      if ( this->IsPlayer(this) )
      {
        v3 = this->IsPlayer(this) ? this : nullptr;
        pszValue = v3->GetPlayerName(this: v3);
      }
      else
      {
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
      }
    }
  }
  else
  {
    pszValue = "<<null>>";
  }
  v4 = this->m_iClassname.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  _Msg(a1: "RESPONSE CRITERIA FOR: %s (%s)\n", v4, pszValue);
  ResponseRules::CriteriaSet::CriteriaSet(this: &set);
  this->ModifyOrAppendCriteria(this, a2: &set);
  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer != nullptr )
    LocalPlayer->ModifyOrAppendPlayerCriteria(this: LocalPlayer, a2: &set);
  ResponseRules::CriteriaSet::Describe(this: &set);
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &set.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x100C3E80
// Name: void CC_Ent_Show_Response_Criteria(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Ent_Show_Response_Criteria(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBaseEntity *i; // esi
  CBasePlayer *v3; // eax
  const char *v4; // [esp-8h] [ebp-10h]
  const char *v5; // [esp-8h] [ebp-10h]

  v4 = CCommand::operator[](this: args, nIndex: 1);
  CommandClient = UTIL_GetCommandClient();
  for ( i = GetNextCommandEntity(pPlayer: CommandClient, name: v4, ent: nullptr);
        i != nullptr;
        i = GetNextCommandEntity(pPlayer: v3, name: v5, ent: i) )
  {
    CBaseEntity::DumpResponseCriteria(this: i);
    v5 = CCommand::operator[](this: args, nIndex: 1);
    v3 = UTIL_GetCommandClient();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3EE0
// Name: public: virtual void CBaseEntity::RunVScripts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::RunVScripts(CBaseEntity *this)
{
  int v2; // esi
  ScriptLanguage_t v3; // eax
  unsigned int j; // ebx
  CFmtStrN<256> *v5; // eax
  HSCRIPT__ *v6; // esi
  const char *pszValue; // eax
  const char *v8; // eax
  const char **v9; // ebx
  CBaseEntity *v10; // ecx
  const char *v11; // esi
  bool v12; // bl
  unsigned int k; // ebx
  CFmtStrN<256> *v14; // eax
  HSCRIPT__ *v15; // esi
  int m; // edi
  char **m_pMemory; // eax
  CFmtStrN<256> v18; // [esp+40h] [ebp-228h] BYREF
  char szScriptsList[256]; // [esp+14Ch] [ebp-11Ch] BYREF
  ScriptLanguage_t language; // [esp+24Ch] [ebp-1Ch]
  int i; // [esp+250h] [ebp-18h]
  CUtlStringList szScripts; // [esp+254h] [ebp-14h] BYREF

  v2 = 0;
  if ( this->m_iszVScripts.pszValue != nullptr )
  {
    CBaseEntity::ValidateScriptScope(this);
    v3 = g_pScriptVM->GetLanguage(this: g_pScriptVM);
    language = v3;
    for ( j = 0; j < 2; ++j )
    {
      if ( v3 == SL_SQUIRREL )
      {
        v5 = CFmtStrN<256>::CFmtStrN<256>(
               this: &v18,
               pszFormat: "%sCallChain <- CSimpleCallChainer(\"%s\", self.GetScriptScope(), true)",
               sCallChainFunctions[j],
               sCallChainFunctions[j]);
        v6 = g_pScriptVM->CompileScript(this: g_pScriptVM, a2: v5->m_szBuf, a3: 0);
        g_pScriptVM->Run_2(
          this: g_pScriptVM,
          a2: v6,
          a3: this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr,
          a4: true);
        g_pScriptVM->ReleaseScript(this: g_pScriptVM, a2: v6);
        v3 = language;
        v2 = 0;
      }
    }
    pszValue = this->m_iszVScripts.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _V_strcpy(dest: szScriptsList, src: pszValue);
    memset(&szScripts, 0, sizeof(szScripts));
    V_SplitString(pString: szScriptsList, pSeparator: " ", outStrings: &szScripts);
    i = 0;
    if ( szScripts.m_Size > 0 )
    {
      while ( 1 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 0) != 0 )
        {
          v8 = this->m_iName.m_Value.pszValue;
          v9 = (const char **)&szScripts.m_Memory.m_pMemory[v2];
          if ( v8 == nullptr )
          {
            if ( this->IsPlayer(this) )
            {
              v10 = this->IsPlayer(this) ? this : nullptr;
              v8 = v10->GetPlayerName(this: v10);
            }
            else
            {
              v8 = this->m_iClassname.pszValue;
              if ( v8 == nullptr )
                v8 = locale;
            }
          }
          _LoggingSystem_Log(a1: LOG_VScript, a2: 0, a3: "%s executing script: %s\n", v8, *v9);
        }
        v11 = szScripts.m_Memory.m_pMemory[v2];
        v12 = this == g_WorldEntity;
        if ( CBaseEntity::ValidateScriptScope(this) != 0 )
        {
          if ( v12 )
            VScriptRunScript(pszScriptName: v11, hScope: nullptr, bWarnMissing: false);
          else
            VScriptRunScript(
              pszScriptName: v11,
              hScope: this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr,
              bWarnMissing: true);
        }
        else
        {
          DevMsg(a1: "\n***\nFAILED to create private ScriptScope. ABORTING script\n***\n");
        }
        for ( k = 0; k < 2; ++k )
        {
          if ( language == SL_SQUIRREL )
          {
            v14 = CFmtStrN<256>::CFmtStrN<256>(
                    this: &v18,
                    pszFormat: "%sCallChain.PostScriptExecute()",
                    sCallChainFunctions[k]);
            v15 = g_pScriptVM->CompileScript(this: g_pScriptVM, a2: v14->m_szBuf, a3: 0);
            g_pScriptVM->Run_2(
              this: g_pScriptVM,
              a2: v15,
              a3: this->m_ScriptScope.m_hScope != (HSCRIPT__ *)-1 ? this->m_ScriptScope.m_hScope : nullptr,
              a4: true);
            g_pScriptVM->ReleaseScript(this: g_pScriptVM, a2: v15);
          }
        }
        if ( ++i >= szScripts.m_Size )
          break;
        v2 = i;
      }
    }
    if ( this->m_iszScriptThinkFunction.pszValue != nullptr )
      CBaseEntity::ThinkSet(
        this,
        func: CBaseEntity::ScriptThink,
        thinkTime: sv_script_think_interval.m_pParent->m_Value.m_fValue + gpGlobals->curtime,
        szContext: "ScriptThink");
    for ( m = 0; m < szScripts.m_Size; ++m )
      free(pMem: szScripts.m_Memory.m_pMemory[m]);
    m_pMemory = szScripts.m_Memory.m_pMemory;
    szScripts.m_Size = 0;
    if ( szScripts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( szScripts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: szScripts.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        szScripts.m_Memory.m_pMemory = nullptr;
      }
      szScripts.m_Memory.m_nAllocationCount = 0;
    }
    szScripts.m_pElements = m_pMemory;
    szScripts.m_Size = 0;
    if ( szScripts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        szScripts.m_Memory.m_pMemory = nullptr;
      }
      szScripts.m_Memory.m_nAllocationCount = 0;
    }
    szScripts.m_pElements = m_pMemory;
    if ( szScripts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4200
// Name: public: void CUtlCachedFileData<class CModelSoundsCache>::Save(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CModelSoundsCache>::Save(CUtlCachedFileData<CModelSoundsCache> *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  void *v7; // eax
  void *v8; // edi
  const char *v9; // eax
  int m_Size; // ebx
  int Inorder; // ecx
  CSortedCacheFile *v12; // eax
  CUtlCachedFileData<CModelSoundsCache>::ElementType_t *p_m_Data; // ebx
  int fileinfo; // eax
  CModelSoundsCache *v15; // ecx
  char fn[512]; // [esp+Ch] [ebp-470h] BYREF
  char path[512]; // [esp+20Ch] [ebp-270h] BYREF
  char v18; // [esp+40Ch] [ebp-70h] BYREF
  int inputBuffer; // [esp+410h] [ebp-6Ch] BYREF
  CUtlBuffer buf; // [esp+414h] [ebp-68h] BYREF
  int c; // [esp+444h] [ebp-38h] BYREF
  int j; // [esp+448h] [ebp-34h]
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+44Ch] [ebp-30h] BYREF
  CSortedCacheFile insert; // [esp+468h] [ebp-14h] BYREF
  int v; // [esp+470h] [ebp-Ch] BYREF
  int bufsize; // [esp+474h] [ebp-8h] BYREF
  int i; // [esp+478h] [ebp-4h]

  v2 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v2, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v3 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: "MOD") )
  {
    v4 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    if ( !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4, a3: "MOD") )
    {
      v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: true, a4: "MOD");
    }
  }
  v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6, a3: "wb", a4: 0);
  v8 = v7;
  if ( v7 != nullptr )
  {
    *((_BYTE *)this + 84) &= ~8u;
    v = 2;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v7);
    v = this->m_nVersion;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    v = this->m_uCurrentMetaChecksum;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    c = this->m_Elements.m_NumElements;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &c, a3: 4, a4: v8);
    m_Size = 0;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    memset(&list, 0, 25);
    Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements);
    i = Inorder;
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        insert.handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
        list.m_bNeedsSort = true;
        bufsize = m_Size;
        if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
            this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&list,
            num: m_Size - list.m_Memory.m_nAllocationCount + 1);
          m_Size = list.m_Size;
          Inorder = i;
        }
        ++m_Size;
        list.m_pElements = list.m_Memory.m_pMemory;
        list.m_Size = m_Size;
        if ( m_Size - bufsize - 1 > 0 )
        {
          _V_memmove(
            dest: &list.m_Memory.m_pMemory[bufsize + 1],
            src: &list.m_Memory.m_pMemory[bufsize],
            count: 8 * (m_Size - bufsize - 1));
          Inorder = i;
        }
        v12 = &list.m_Memory.m_pMemory[bufsize];
        if ( v12 != nullptr )
        {
          v12->handle = insert.handle;
          v12->index = Inorder;
        }
        i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_Elements,
                                i: Inorder);
        if ( i == 0xFFFF )
          break;
        Inorder = i;
      }
      if ( list.m_bNeedsSort && m_Size > 1 )
      {
        insert.handle = list.m_pLessContext;
        insert.index = (int)&v18;
        qsort_s(
          base: list.m_Memory.m_pMemory,
          num: m_Size,
          width: 8u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
          context: &insert);
      }
    }
    if ( m_Size > 0 )
    {
      i = (int)&list.m_Memory.m_pMemory->index;
      for ( j = m_Size; j != 0; --j )
      {
        p_m_Data = &this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)i].m_Data;
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
        g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)p_m_Data, a3: fn, a4: 512);
        CUtlBuffer::PutString(this: &buf, pString: fn);
        fileinfo = p_m_Data->fileinfo;
        insert.index = fileinfo;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%d", fileinfo);
        }
        else
        {
          inputBuffer = fileinfo;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &buf.m_Byteswap,
                outputBuffer: (int *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = insert.index;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        v15 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
        v15->Save(this: v15, a2: &buf);
        bufsize = buf.m_Put;
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v8);
        g_pFullFileSystem->Write(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: buf.m_Memory.m_pMemory,
          a3: bufsize,
          a4: v8);
        i += 8;
      }
    }
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    v9 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Warning(a1: "Unable to persist cache '%s', check file permissions\n", v9);
  }
  if ( (*((_BYTE *)this + 84) & 4) != 0 )
    CUtlCachedFileData<CModelSoundsCache>::SaveManifest(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C47C0
// Name: public: CBaseEntity::CBaseEntity(bool)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::CBaseEntity(CBaseEntity *this, bool bServerOnly)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  unsigned int m_Index; // eax

  this->__vftable = (CBaseEntity_vtbl *)&CBaseEntity::`vftable';
  CServerNetworkProperty::CServerNetworkProperty(this: &this->m_Network);
  this->m_aThinkFunctions.m_Memory.m_pMemory = nullptr;
  this->m_aThinkFunctions.m_Memory.m_nAllocationCount = 0;
  this->m_aThinkFunctions.m_Memory.m_nGrowSize = 0;
  this->m_aThinkFunctions.m_Size = 0;
  this->m_aThinkFunctions.m_pElements = nullptr;
  this->m_ResponseContexts.m_Memory.m_pMemory = nullptr;
  this->m_ResponseContexts.m_Memory.m_nAllocationCount = 0;
  this->m_ResponseContexts.m_Memory.m_nGrowSize = 0;
  this->m_ResponseContexts.m_Size = 0;
  this->m_ResponseContexts.m_pElements = nullptr;
  this->m_pParent.m_Index = -1;
  this->m_hMoveParent.m_Value.m_Index = -1;
  this->m_hMoveChild.m_Index = -1;
  this->m_hMovePeer.m_Index = -1;
  CCollisionProperty::CCollisionProperty(this: &this->m_Collision);
  this->m_Collision.__vftable = (CBaseEntity::NetworkVar_m_Collision_vtbl *)&CBaseEntity::NetworkVar_m_Collision::`vftable';
  this->m_hOwnerEntity.m_Value.m_Index = -1;
  this->m_hGroundEntity.m_Value.m_Index = -1;
  this->m_pBlocker.m_Index = -1;
  this->m_hDamageFilter.m_Index = -1;
  this->m_hPlayerSimulationOwner.m_Value.m_Index = -1;
  this->m_OnUser1.m_Value.iVal = 0;
  this->m_OnUser1.m_Value.eVal.m_Index = -1;
  this->m_OnUser1.m_Value.fieldType = FIELD_VOID;
  this->m_OnUser2.m_Value.iVal = 0;
  this->m_OnUser2.m_Value.eVal.m_Index = -1;
  this->m_OnUser2.m_Value.fieldType = FIELD_VOID;
  this->m_OnUser3.m_Value.iVal = 0;
  this->m_OnUser3.m_Value.eVal.m_Index = -1;
  this->m_OnUser3.m_Value.fieldType = FIELD_VOID;
  this->m_OnUser4.m_Value.iVal = 0;
  this->m_OnUser4.m_Value.eVal.m_Index = -1;
  this->m_OnUser4.m_Value.fieldType = FIELD_VOID;
  this->m_OnKilled.m_Value.iVal = 0;
  this->m_OnKilled.m_Value.eVal.m_Index = -1;
  this->m_OnKilled.m_Value.fieldType = FIELD_VOID;
  this->m_RefEHandle.m_Index = -1;
  this->m_hEffectEntity.m_Value.m_Index = -1;
  this->m_ScriptScope.m_hScope = (HSCRIPT__ *)-1;
  this->m_ScriptScope.m_flags = 0;
  this->m_ScriptScope.m_FuncHandles.m_Memory.m_pMemory = nullptr;
  this->m_ScriptScope.m_FuncHandles.m_Size = 0;
  this->m_ScriptScope.m_FuncHandles.m_pElements = nullptr;
  if ( this->m_cellbits.m_Value != 5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2ACu);
    }
    this->m_cellbits.m_Value = 5;
  }
  this->m_cellwidth = 32;
  CBaseEntity::UpdateCell(this);
  CBaseEntity::UpdateCell(this);
  if ( this->m_bAlternateSorting.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x1F7u);
    }
    this->m_bAlternateSorting.m_Value = false;
  }
  if ( this->m_CollisionGroup.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x144u);
    }
    this->m_CollisionGroup.m_Value = 0;
  }
  if ( this->m_iParentAttachment.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0xD5u);
    }
    this->m_iParentAttachment.m_Value = 0;
  }
  CCollisionProperty::Init(this: &this->m_Collision, pEntity: this);
  CServerNetworkProperty::Init(this: &this->m_Network, pEntity: this);
  this->m_bForcePurgeFixedupStrings = false;
  if ( this->m_fadeMinDist.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x308u);
    }
    this->m_fadeMinDist.m_Value = 0.0;
  }
  if ( this->m_fadeMaxDist.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x30Cu);
    }
    this->m_fadeMaxDist.m_Value = 0.0;
  }
  if ( this->m_flFadeScale.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x310u);
    }
    this->m_flFadeScale.m_Value = 0.0;
  }
  this->m_iEFlags |= 0xC40000u;
  this->m_debugOverlays = 0;
  this->m_pTimedOverlay = nullptr;
  this->m_pPhysicsObject = nullptr;
  if ( this->m_flElasticity.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x1B8u);
    }
    this->m_flElasticity.m_Value = 1.0;
  }
  this->m_flDesiredShadowCastDistance = 0.0;
  if ( this->m_flShadowCastDistance.m_Value != this->m_flDesiredShadowCastDistance )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x314u);
    }
    this->m_flShadowCastDistance.m_Value = this->m_flDesiredShadowCastDistance;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  this->m_iInitialTeamNum = 0;
  if ( this->m_iTeamNum.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x2F4u);
    }
    this->m_iTeamNum.m_Value = this->m_iInitialTeamNum;
  }
  this->m_nLastThinkTick = gpGlobals->tickcount;
  this->m_nSimulationTick = -1;
  SetIdentityMatrix(matrix: &this->m_rgflCoordinateFrame);
  this->m_pBlocker.m_Index = -1;
  *(_WORD *)&this->m_nWaterTouch = 0;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: 0);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hOwnerEntity>::Set(
      this: &this->m_hOwnerEntity,
      val: nullptr);
    CBaseEntity::CollisionRulesChanged(this);
  }
  this->m_iEFlags &= ~0x1000000u;
  EntityTouch_Remove(pEntity: this);
  CBaseEntity::SetModelIndex(this, index: 0);
  this->m_ModelName.pszValue = nullptr;
  if ( this->m_nTransmitStateOwnedCounter == 0 )
  {
    ++g_nInsideDispatchUpdateTransmitState;
    this->UpdateTransmitState(this);
    --g_nInsideDispatchUpdateTransmitState;
  }
  this->m_nTransmitStateOwnedCounter = 0;
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: &vec3_origin, maxs: &vec3_origin);
  CBaseEntity::ClearFlags(this);
  if ( this->m_flFriction.m_Value != 1.0 )
  {
    this->NetworkStateChanged_m_flFriction(this, a2: &this->m_flFriction);
    this->m_flFriction.m_Value = 1.0;
  }
  if ( bServerOnly )
    this->m_iEFlags |= 0x200u;
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  this->m_iEFlags |= 0x40000u;
  this->m_pNextByClass = nullptr;
  this->m_pPrevByClass = nullptr;
  this->m_bNetworkQuantizeOriginAndAngles = false;
  this->m_pEvent = nullptr;
  this->m_ListByClass = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C4D50
// Name: public: virtual CBaseEntity::~CBaseEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::~CBaseEntity(CBaseEntity *this)
{
  this->__vftable = (CBaseEntity_vtbl *)&CBaseEntity::`vftable';
  PhysCleanupFrictionSounds(pEntity: this);
  CBaseEntity::VPhysicsDestroyObject(this);
  g_bDisableEhandleAccess = false;
  CBaseEntity::PhysicsRemoveTouchedList(ent: this);
  CBaseEntity::PhysicsRemoveGroundList(ent: this);
  CBaseEntity::DestroyAllDataObjects(this);
  g_bDisableEhandleAccess = true;
  CBaseEntityList::RemoveEntity(this: &gEntList, handle: this->m_RefEHandle);
  CScriptScopeT<CDefScriptScopeBase>::Term(this: &this->m_ScriptScope);
  this->m_ScriptScope.m_FuncHandles.m_Size = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ScriptScope.m_FuncHandles.m_Memory.m_pMemory);
  this->m_ScriptScope.m_FuncHandles.m_Memory.m_pMemory = nullptr;
  this->m_ScriptScope.m_FuncHandles.m_pElements = nullptr;
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnKilled);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUser4);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUser3);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUser2);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUser1);
  CCollisionProperty::~CCollisionProperty(this: &this->m_Collision);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ResponseContexts);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_aThinkFunctions);
  CServerNetworkProperty::~CServerNetworkProperty(this: &this->m_Network);
  this->__vftable = (CBaseEntity_vtbl *)&IHandleEntity::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C4E40
// Name: public: virtual void CBaseEntity::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::Activate(CBaseEntity *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax

  if ( this->m_iInitialTeamNum != 0 )
    this->ChangeTeam(this, a2: this->m_iInitialTeamNum);
  pszValue = this->m_iszDamageFilterName.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
      this->m_hDamageFilter.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    else
      this->m_hDamageFilter.m_Index = -1;
  }
  if ( this->m_iszResponseContext.pszValue != nullptr )
    CBaseEntity::AddContext(this, contextName: this->m_iszResponseContext.pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x100C4EB0
// Name: public: static class CBaseEntity __near * CBaseEntity::Create(char const __near *,class Vector const __near &,class QAngle const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CBaseEntity::Create(
        const char *szName,
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        CBaseEntity *pOwner)
{
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v5; // esi

  EntityByName = CreateEntityByName(className: szName, iForceEdictIndex: -1, bNotify: false);
  v5 = EntityByName;
  if ( EntityByName != nullptr )
  {
    CBaseEntity::SetLocalOrigin(this: EntityByName, origin: vecOrigin);
    CBaseEntity::SetLocalAngles(this: v5, angles: vecAngles);
    v5->SetOwnerEntity(this: v5, a2: pOwner);
    CGlobalEntityList::NotifyCreateEntity(this: &gEntList, pEnt: v5);
    DispatchSpawn(pEntity: v5, bRunVScripts: true);
    return v5;
  }
  else
  {
    DispatchSpawn(pEntity: nullptr, bRunVScripts: true);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4F20
// Name: public: virtual void CModelSoundsCacheSaver::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelSoundsCacheSaver::LevelInitPostEntity(CModelSoundsCacheSaver *this)
{
  if ( (*((_BYTE *)&g_ModelSoundsCache + 84) & 8) != 0 )
    CUtlCachedFileData<CModelSoundsCache>::Save(this: &g_ModelSoundsCache);
}

//------------------------------------------------------------------------------
// Address: 0x100C4F70
// Name: public: void CBaseEntity::InputAddContext(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::InputAddContext(CBaseEntity *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
      CBaseEntity::AddContext(this, contextName: locale);
      return;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  CBaseEntity::AddContext(this, contextName: iVal);
}

//------------------------------------------------------------------------------
// Address: 0x100C4FB0
// Name: public: virtual CUtlCachedFileData<class CModelSoundsCache>::~CUtlCachedFileData<class CModelSoundsCache>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CModelSoundsCache>::~CUtlCachedFileData<CModelSoundsCache>(
        CUtlCachedFileData<CModelSoundsCache> *this)
{
  CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short> > *p_m_Elements; // esi
  int m_Size; // ecx
  int v4; // eax
  CModelSoundsCache *v5; // esi
  unsigned __int16 *m_pMemory; // eax
  CModelSoundsCache **v7; // eax
  CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short> > *v8; // [esp+Ch] [ebp-Ch]
  int c; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  p_m_Elements = &this->m_Elements;
  this->__vftable = (CUtlCachedFileData<CModelSoundsCache>_vtbl *)&CUtlCachedFileData<CModelSoundsCache>::`vftable';
  v8 = &this->m_Elements;
  CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
  m_Size = this->m_Data.m_Size;
  v4 = 0;
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v5 = this->m_Data.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr )
      {
        v5->sounds.m_Size = 0;
        if ( v5->sounds.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->sounds.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->sounds.m_Memory.m_pMemory);
            v5->sounds.m_Memory.m_pMemory = nullptr;
          }
          v5->sounds.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v5->sounds.m_Memory.m_pMemory;
        v5->sounds.m_pElements = m_pMemory;
        if ( v5->sounds.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v5->sounds.m_Memory.m_pMemory = nullptr;
          }
          v5->sounds.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v5);
        m_Size = c;
        v4 = i;
      }
      i = ++v4;
    }
    while ( v4 < m_Size );
    p_m_Elements = v8;
  }
  this->m_Data.m_Size = 0;
  this->m_sRepositoryFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_sRepositoryFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory);
      this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sRepositoryFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Data.m_Size = 0;
  if ( this->m_Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Data.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Data.m_Memory.m_pMemory);
      this->m_Data.m_Memory.m_pMemory = nullptr;
    }
    this->m_Data.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_Data.m_Memory.m_pMemory;
  this->m_Data.m_pElements = v7;
  if ( this->m_Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_Data.m_Memory.m_pMemory = nullptr;
    }
    this->m_Data.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: p_m_Elements);
  p_m_Elements->m_FirstFree = -1;
  if ( p_m_Elements->m_Elements.m_nGrowSize >= 0 )
  {
    if ( p_m_Elements->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Elements->m_Elements.m_pMemory);
      p_m_Elements->m_Elements.m_pMemory = nullptr;
    }
    p_m_Elements->m_Elements.m_nAllocationCount = 0;
  }
  p_m_Elements->m_LastAlloc.index = -1;
  if ( p_m_Elements->m_Elements.m_nGrowSize >= 0 )
  {
    if ( p_m_Elements->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Elements->m_Elements.m_pMemory);
      p_m_Elements->m_Elements.m_pMemory = nullptr;
    }
    p_m_Elements->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C51D0
// Name: private: int CUtlCachedFileData<class CModelSoundsCache>::GetIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlCachedFileData<CModelSoundsCache>::GetIndex(
        CUtlCachedFileData<CModelSoundsCache> *this,
        CModelSoundsCache *filename)
{
  int result; // eax
  CModelSoundsCache *v4; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CModelSoundsCache **m_pMemory; // ecx
  int v8; // eax
  CModelSoundsCache **v9; // eax
  CUtlCachedFileData<CModelSoundsCache>::ElementType_t element; // [esp+8h] [ebp-10h] BYREF
  CModelSoundsCache *data; // [esp+20h] [ebp+8h]

  element.handle = nullptr;
  element.fileinfo = 0;
  element.diskfileinfo = -2;
  element.dataIndex = -1;
  element.handle = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: filename);
  result = CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_Elements,
             search: &element);
  if ( (unsigned __int16)result == 0xFFFF )
  {
    v4 = (CModelSoundsCache *)operator new(nSize: 0x18u);
    if ( v4 != nullptr )
      data = CModelSoundsCache::CModelSoundsCache(this: v4);
    else
      data = nullptr;
    m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
    m_Size = this->m_Data.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Data.m_Size;
    m_pMemory = this->m_Data.m_Memory.m_pMemory;
    v8 = this->m_Data.m_Size - m_Size - 1;
    this->m_Data.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Data.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = data;
    result = CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::Insert(
               this: &this->m_Elements,
               a2: (const char *)m_Size,
               insert: &element);
    this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)result].m_Data.dataIndex = m_Size;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C52C0
// Name: private: void CUtlCachedFileData<class CModelSoundsCache>::InitSmallBuffer(void __near * __near &,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CModelSoundsCache>::InitSmallBuffer(
        CUtlCachedFileData<CModelSoundsCache> *this,
        void **fh,
        int fileSize,
        bool *deleteFile)
{
  int Int; // eax
  const char *v6; // eax
  int v7; // esi
  int v8; // esi
  CUtlCachedFileData<CModelSoundsCache>::ElementType_t *p_m_Data; // esi
  int v10; // eax
  CModelSoundsCache *v11; // ecx
  const char *v12; // eax
  const char *v13; // eax
  char elementFileName[512]; // [esp+Ch] [ebp-264h] BYREF
  CUtlBuffer loadBuf; // [esp+20Ch] [ebp-64h] BYREF
  CUtlBuffer buf; // [esp+23Ch] [ebp-34h] BYREF
  int cacheversion; // [esp+26Ch] [ebp-4h] BYREF
  bool *deleteFilea; // [esp+280h] [ebp+10h]

  *deleteFile = false;
  CUtlBuffer::CUtlBuffer(this: &loadBuf, growSize: 0, initSize: 0, nFlags: 0);
  g_pFullFileSystem->ReadToBuffer(this: g_pFullFileSystem, a2: *fh, a3: &loadBuf, a4: 0, a5: nullptr);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *fh);
  cacheversion = 0;
  CUtlBuffer::Get(this: &loadBuf, pMem: &cacheversion, size: 4);
  if ( cacheversion != 2 )
  {
    v13 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v13);
    goto LABEL_17;
  }
  if ( CUtlBuffer::GetInt(this: &loadBuf) != this->m_nVersion )
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to version change\n", v12);
    *deleteFile = true;
    goto LABEL_18;
  }
  Int = CUtlBuffer::GetInt(this: &loadBuf);
  if ( this->m_pfnMetaChecksum != nullptr && Int != this->m_uCurrentMetaChecksum )
  {
    v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v6);
LABEL_17:
    *deleteFile = true;
    goto LABEL_18;
  }
  v7 = CUtlBuffer::GetInt(this: &loadBuf);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( v7 > 0 )
  {
    for ( deleteFilea = (bool *)v7; deleteFilea != nullptr; --deleteFilea )
    {
      v8 = CUtlBuffer::GetInt(this: &loadBuf);
      memset(&buf.m_Get, 0, 9);
      buf.m_nOffset = 0;
      buf.m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
      CUtlBuffer::EnsureCapacity(this: &buf, num: v8);
      CUtlBuffer::Get(this: &loadBuf, pMem: buf.m_Memory.m_pMemory, size: v8);
      CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v8);
      CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
      p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CModelSoundsCache>::GetIndex(
                                                                            this,
                                                                            filename: (CModelSoundsCache *)elementFileName)].m_Data;
      v10 = CUtlBuffer::GetInt(this: &buf);
      p_m_Data->fileinfo = v10;
      if ( v10 == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
        p_m_Data->fileinfo = 0;
      v11 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
      v11->Restore(this: v11, a2: &buf);
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
LABEL_18:
  if ( loadBuf.m_Memory.m_nGrowSize >= 0 && loadBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100C54C0
// Name: private: void CUtlCachedFileData<class CModelSoundsCache>::InitLargeBuffer(void __near * __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CModelSoundsCache>::InitLargeBuffer(
        CUtlCachedFileData<CModelSoundsCache> *this,
        void **fh,
        bool *deleteFile)
{
  void **v3; // edi
  const char *v5; // eax
  int v6; // edi
  CUtlCachedFileData<CModelSoundsCache>::ElementType_t *p_m_Data; // edi
  int Int; // eax
  CModelSoundsCache *v9; // ecx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  void *v13; // [esp-4h] [ebp-258h]
  void *v14; // [esp-4h] [ebp-258h]
  void *v15; // [esp-4h] [ebp-258h]
  void *v16; // [esp-4h] [ebp-258h]
  void *v17; // [esp-4h] [ebp-258h]
  char elementFileName[512]; // [esp+Ch] [ebp-248h] BYREF
  CUtlBuffer buf; // [esp+20Ch] [ebp-48h] BYREF
  unsigned int cache_meta_checksum; // [esp+23Ch] [ebp-18h] BYREF
  int cacheversion; // [esp+240h] [ebp-14h] BYREF
  int i; // [esp+244h] [ebp-10h]
  int version; // [esp+248h] [ebp-Ch] BYREF
  int count; // [esp+24Ch] [ebp-8h] BYREF
  int bufsize; // [esp+250h] [ebp-4h] BYREF

  v3 = fh;
  *deleteFile = false;
  v13 = *fh;
  cacheversion = 0;
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cacheversion, a3: 4, a4: v13);
  if ( cacheversion == 2 )
  {
    v14 = *fh;
    version = 0;
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &version, a3: 4, a4: v14);
    if ( version == this->m_nVersion )
    {
      v15 = *fh;
      cache_meta_checksum = 0;
      g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cache_meta_checksum, a3: 4, a4: v15);
      if ( this->m_pfnMetaChecksum == nullptr || cache_meta_checksum == this->m_uCurrentMetaChecksum )
      {
        v16 = *fh;
        count = 0;
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &count, a3: 4, a4: v16);
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
        i = 0;
        if ( count > 0 )
        {
          while ( 1 )
          {
            v17 = *v3;
            bufsize = 0;
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v17);
            if ( bufsize > 1000000 )
              break;
            memset(&buf.m_Get, 0, 9);
            buf.m_nOffset = 0;
            buf.m_nMaxPut = -1;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
            CUtlBuffer::EnsureCapacity(this: &buf, num: bufsize);
            v6 = g_pFullFileSystem->Read(
                   this: &g_pFullFileSystem->IBaseFileSystem,
                   a2: buf.m_Memory.m_pMemory,
                   a3: bufsize,
                   a4: *v3);
            CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
            CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v6);
            CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
            p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CModelSoundsCache>::GetIndex(
                                                                                  this,
                                                                                  filename: (CModelSoundsCache *)elementFileName)].m_Data;
            Int = CUtlBuffer::GetInt(this: &buf);
            p_m_Data->fileinfo = Int;
            if ( Int == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
              p_m_Data->fileinfo = 0;
            v9 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
            v9->Restore(this: v9, a2: &buf);
            v3 = fh;
            if ( ++i >= count )
              goto LABEL_14;
          }
          v10 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
          _Msg(a1: "Discarding repository '%s' due to corruption\n", v10);
          *deleteFile = true;
        }
LABEL_14:
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      }
      else
      {
        v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
        _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v5);
        *deleteFile = true;
      }
    }
    else
    {
      v11 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      _Msg(a1: "Discarding repository '%s' due to version change\n", v11);
      *deleteFile = true;
    }
  }
  else
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v12);
    *deleteFile = true;
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *v3);
}

//------------------------------------------------------------------------------
// Address: 0x100C8BF0
// Name: void InitCBaseEntityScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCBaseEntityScriptDesc()
{
  ScriptFunctionBinding_t *v0; // esi
  ScriptFunctionBinding_t *v1; // esi
  ScriptFunctionBinding_t *v2; // eax
  ScriptFunctionBinding_t *v3; // esi
  ScriptFunctionBinding_t *v4; // eax
  ScriptFunctionBinding_t *v5; // esi
  ScriptFunctionBinding_t *v6; // esi
  ScriptFunctionBinding_t *v7; // eax
  ScriptFunctionBinding_t *v8; // esi
  ScriptFunctionBinding_t *v9; // esi
  ScriptFunctionBinding_t *v10; // esi
  ScriptFunctionBinding_t *v11; // eax
  ScriptFunctionBinding_t *v12; // eax
  ScriptFunctionBinding_t *v13; // eax
  ScriptFunctionBinding_t *v14; // eax
  ScriptFunctionBinding_t *v15; // esi
  ScriptFunctionBinding_t *v16; // esi
  ScriptFunctionBinding_t *v17; // eax
  ScriptFunctionBinding_t *v18; // eax
  ScriptFunctionBinding_t *v19; // eax
  ScriptFunctionBinding_t *v20; // esi
  ScriptFunctionBinding_t *v21; // eax
  ScriptFunctionBinding_t *v22; // esi
  ScriptFunctionBinding_t *v23; // esi
  ScriptFunctionBinding_t *v24; // eax
  ScriptFunctionBinding_t *v25; // eax
  ScriptFunctionBinding_t *v26; // eax
  ScriptFunctionBinding_t *v27; // esi
  ScriptFunctionBinding_t *v28; // eax
  ScriptFunctionBinding_t *v29; // esi
  ScriptFunctionBinding_t *v30; // eax
  ScriptFunctionBinding_t *v31; // eax
  ScriptFunctionBinding_t *v32; // eax
  ScriptFunctionBinding_t *v33; // esi
  ScriptFunctionBinding_t *v34; // eax
  ScriptFunctionBinding_t *v35; // esi
  ScriptFunctionBinding_t *v36; // eax
  ScriptFunctionBinding_t *v37; // eax
  ScriptFunctionBinding_t *v38; // eax
  ScriptFunctionBinding_t *v39; // eax
  ScriptFunctionBinding_t *v40; // esi
  ScriptFunctionBinding_t *v41; // esi
  ScriptFunctionBinding_t *v42; // esi
  ScriptFunctionBinding_t *v43; // esi
  ScriptFunctionBinding_t *v44; // eax
  ScriptFunctionBinding_t *v45; // eax
  ScriptFunctionBinding_t *v46; // eax
  ScriptFunctionBinding_t *v47; // eax
  ScriptFunctionBinding_t *v48; // eax
  ScriptFunctionBinding_t *v49; // esi
  ScriptFunctionBinding_t *v50; // eax

  if ( !bInitialized_0 )
  {
    g_CBaseEntity_ScriptDesc.m_pszScriptName = "CBaseEntity";
    g_CBaseEntity_ScriptDesc.m_pszClassname = "CBaseEntity";
    bInitialized_0 = true;
    g_CBaseEntity_ScriptDesc.m_pszDescription = "Root class of all server-side entities";
    g_CBaseEntity_ScriptDesc.m_pBaseDesc = nullptr;
    g_CBaseEntity_ScriptDesc.pHelper = &g_BaseEntityScriptInstanceHelper;
    v0 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "Adds an I/O connection that will call the named function when the specified output fires";
    v0->m_desc.m_pszScriptName = "ConnectOutput";
    v0->m_desc.m_pszFunction = "ConnectOutputToScript";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,char const *,char const *>(
      pDesc: &v0->m_desc,
      pObject: nullptr,
      pfnProxied: (void (__thiscall *)(CBaseEntity *, const char *, const char *))CBaseEntity::ConnectOutputToScript);
    v0->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *,char const *),void,char const *,char const *>::Call;
    v0->m_pFunction = CBaseEntity::ConnectOutputToScript;
    v0->m_flags = 1;
    v1 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "Removes a connected script function from an I/O event.";
    v1->m_desc.m_pszScriptName = "DisconnectOutput";
    v1->m_desc.m_pszFunction = "DisconnectOutputFromScript";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,char const *,char const *>(
      pDesc: &v1->m_desc,
      pObject: nullptr,
      pfnProxied: (void (__thiscall *)(CBaseEntity *, const char *, const char *))CBaseEntity::DisconnectOutputFromScript);
    v1->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *,char const *),void,char const *,char const *>::Call;
    v1->m_pFunction = CBaseEntity::DisconnectOutputFromScript;
    v1->m_flags = 1;
    v2 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = locale;
    v2->m_desc.m_pszScriptName = "GetHealth";
    v2->m_desc.m_pszFunction = "GetHealth";
    v2->m_desc.m_ReturnType = 5;
    v2->m_pfnBinding = CMemberScriptBinding0<CTriggerCamera *,int (__thiscall CTriggerCamera::*)(void),int>::Call;
    v2->m_pFunction = CBaseEntity::GetHealth;
    v2->m_flags = 1;
    v3 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v3->m_desc.m_pszDescription = locale;
    v3->m_desc.m_pszScriptName = "SetHealth";
    v3->m_desc.m_pszFunction = "SetHealth";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,int>(
      pDesc: &v3->m_desc,
      pObject: nullptr,
      pfnProxied:  __thiscall CBaseEntity::`vcall'{480,{flat}});
    v3->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v3->m_pFunction =  __thiscall CBaseEntity::`vcall'{480,{flat}};
    v3->m_flags = 1;
    v4 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v4->m_desc.m_pszDescription = locale;
    v4->m_desc.m_pszScriptName = "GetMaxHealth";
    v4->m_desc.m_pszFunction = "GetMaxHealth";
    v4->m_desc.m_ReturnType = 5;
    v4->m_pfnBinding = CMemberScriptBinding0<CTriggerCamera *,int (__thiscall CTriggerCamera::*)(void),int>::Call;
    v4->m_pFunction =  __thiscall CBaseEntity::`vcall'{476,{flat}};
    v4->m_flags = 1;
    v5 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v5->m_desc.m_pszDescription = locale;
    v5->m_desc.m_pszScriptName = "SetMaxHealth";
    v5->m_desc.m_pszFunction = "SetMaxHealth";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,int>(
      pDesc: &v5->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::SetMaxHealth);
    v5->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v5->m_pFunction = CBaseEntity::SetMaxHealth;
    v5->m_flags = 1;
    v6 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v6->m_desc.m_pszDescription = locale;
    v6->m_desc.m_pszScriptName = "SetModel";
    v6->m_desc.m_pszFunction = "SetModel";
    ScriptDeduceFunctionSignature<void,char const *>(
      pDesc: &v6->m_desc,
      pObject: nullptr,
      pfnProxied:  __thiscall CBaseEntity::`vcall'{104,{flat}});
    v6->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *),void,char const *>::Call;
    v6->m_pFunction =  __thiscall CBaseEntity::`vcall'{104,{flat}};
    v6->m_flags = 1;
    v7 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v7->m_desc.m_pszDescription = "Returns the name of the model";
    v7->m_desc.m_pszScriptName = "GetModelName";
    v7->m_desc.m_pszFunction = "ScriptGetModelName";
    v7->m_desc.m_ReturnType = 32;
    v7->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBaseEntity *,char const * (__thiscall CBaseEntity::*)(void),char const *>::Call;
    v7->m_pFunction = CBaseEntity::ScriptGetModelName;
    v7->m_flags = 1;
    v8 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v8->m_desc.m_pszDescription = "Plays a sound from this entity.";
    v8->m_desc.m_pszScriptName = "EmitSound";
    v8->m_desc.m_pszFunction = "ScriptEmitSound";
    ScriptDeduceFunctionSignature<void,char const *>(
      pDesc: &v8->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::ScriptEmitSound);
    v8->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *),void,char const *>::Call;
    v8->m_pFunction = CBaseEntity::ScriptEmitSound;
    v8->m_flags = 1;
    v9 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                           this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                           elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v9->m_desc.m_pszDescription = "Precache a sound for later playing.";
    v9->m_desc.m_pszScriptName = "PrecacheSoundScript";
    v9->m_desc.m_pszFunction = "VScriptPrecacheScriptSound";
    ScriptDeduceFunctionSignature<void,char const *>(
      pDesc: &v9->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::VScriptPrecacheScriptSound);
    v9->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *),void,char const *>::Call;
    v9->m_pFunction = CBaseEntity::VScriptPrecacheScriptSound;
    v9->m_flags = 1;
    v10 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v10->m_desc.m_pszDescription = "Returns float duration of the sound. Takes soundname and optional actormodelname.";
    v10->m_desc.m_pszScriptName = "GetSoundDuration";
    v10->m_desc.m_pszFunction = "ScriptSoundDuration";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,float,char const *,char const *>(
      pDesc: &v10->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::ScriptSoundDuration);
    v10->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CBaseEntity *,float (__thiscall CBaseEntity::*)(char const *,char const *),float,char const *,char const *>::Call;
    v10->m_pFunction = CBaseEntity::ScriptSoundDuration;
    v10->m_flags = 1;
    v11 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v11->m_desc.m_pszDescription = locale;
    v11->m_desc.m_pszScriptName = "GetClassname";
    v11->m_desc.m_pszFunction = "GetClassname";
    v11->m_desc.m_ReturnType = 32;
    v11->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBaseEntity *,char const * (__thiscall CBaseEntity::*)(void),char const *>::Call;
    v11->m_pFunction = CBaseEntity::GetClassname;
    v11->m_flags = 1;
    v12 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v12->m_desc.m_pszDescription = locale;
    v12->m_desc.m_pszScriptName = "GetName";
    v12->m_desc.m_pszFunction = "GetEntityNameAsCStr";
    v12->m_desc.m_ReturnType = 32;
    v12->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBaseEntity *,char const * (__thiscall CBaseEntity::*)(void),char const *>::Call;
    v12->m_pFunction = CBaseEntity::GetEntityNameAsCStr;
    v12->m_flags = 1;
    v13 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v13->m_desc.m_pszDescription = "Get the entity name stripped of template unique decoration";
    v13->m_desc.m_pszScriptName = "GetPreTemplateName";
    v13->m_desc.m_pszFunction = "GetPreTemplateName";
    v13->m_desc.m_ReturnType = 32;
    v13->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBaseEntity *,char const * (__thiscall CBaseEntity::*)(void),char const *>::Call;
    v13->m_pFunction = CBaseEntity::GetPreTemplateName;
    v13->m_flags = 1;
    v14 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v14->m_desc.m_pszDescription = locale;
    v14->m_desc.m_pszScriptName = "GetOrigin";
    v14->m_desc.m_pszFunction = "GetAbsOrigin";
    v14->m_desc.m_ReturnType = 3;
    v14->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v14->m_pFunction = CBaseEntity::GetAbsOrigin;
    v14->m_flags = 1;
    v15 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v15->m_desc.m_pszDescription = "SetAbsOrigin";
    v15->m_desc.m_pszScriptName = "SetAbsOrigin";
    v15->m_desc.m_pszFunction = "SetAbsOrigin";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,Vector const &>(
      pDesc: &v15->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::SetAbsOrigin);
    v15->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &),void,Vector const &>::Call;
    v15->m_pFunction = CBaseEntity::SetAbsOrigin;
    v15->m_flags = 1;
    v16 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v16->m_desc.m_pszDescription = locale;
    v16->m_desc.m_pszScriptName = "SetOrigin";
    v16->m_desc.m_pszFunction = "ScriptSetOrigin";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,Vector const &>(
      pDesc: &v16->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::ScriptSetOrigin);
    v16->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &),void,Vector const &>::Call;
    v16->m_pFunction = CBaseEntity::ScriptSetOrigin;
    v16->m_flags = 1;
    v17 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v17->m_desc.m_pszDescription = "Get the forward vector of the entity";
    v17->m_desc.m_pszScriptName = "GetForwardVector";
    v17->m_desc.m_pszFunction = "ScriptGetForward";
    v17->m_desc.m_ReturnType = 3;
    v17->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v17->m_pFunction = CBaseEntity::ScriptGetForward;
    v17->m_flags = 1;
    v18 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v18->m_desc.m_pszDescription = "Get the left vector of the entity";
    v18->m_desc.m_pszScriptName = "GetLeftVector";
    v18->m_desc.m_pszFunction = "ScriptGetLeft";
    v18->m_desc.m_ReturnType = 3;
    v18->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v18->m_pFunction = CBaseEntity::ScriptGetLeft;
    v18->m_flags = 1;
    v19 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v19->m_desc.m_pszDescription = "Get the up vector of the entity";
    v19->m_desc.m_pszScriptName = "GetUpVector";
    v19->m_desc.m_pszFunction = "ScriptGetUp";
    v19->m_desc.m_ReturnType = 3;
    v19->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v19->m_pFunction = CBaseEntity::ScriptGetUp;
    v19->m_flags = 1;
    v20 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v20->m_desc.m_pszDescription = "Set the orientation of the entity to have this forward vector";
    v20->m_desc.m_pszScriptName = "SetForwardVector";
    v20->m_desc.m_pszFunction = "ScriptSetForward";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,Vector const &>(
      pDesc: &v20->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::ScriptSetForward);
    v20->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &),void,Vector const &>::Call;
    v20->m_pFunction = CBaseEntity::ScriptSetForward;
    v20->m_flags = 1;
    v21 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v21->m_desc.m_pszDescription = locale;
    v21->m_desc.m_pszScriptName = "GetVelocity";
    v21->m_desc.m_pszFunction = "GetAbsVelocity";
    v21->m_desc.m_ReturnType = 3;
    v21->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v21->m_pFunction = CBaseEntity::GetAbsVelocity;
    v21->m_flags = 1;
    v22 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v22->m_desc.m_pszDescription = locale;
    v22->m_desc.m_pszScriptName = "SetVelocity";
    v22->m_desc.m_pszFunction = "SetAbsVelocity";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,Vector const &>(
      pDesc: &v22->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::SetAbsVelocity);
    v22->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &),void,Vector const &>::Call;
    v22->m_pFunction = CBaseEntity::SetAbsVelocity;
    v22->m_flags = 1;
    v23 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v23->m_desc.m_pszDescription = "Set the local angular velocity - takes float pitch,yaw,roll velocities";
    v23->m_desc.m_pszScriptName = "SetAngularVelocity";
    v23->m_desc.m_pszFunction = "ScriptSetLocalAngularVelocity";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,float,float,float>(
      pDesc: &v23->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::ScriptSetLocalAngularVelocity);
    v23->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding3<CBaseEntity *,void (__thiscall CBaseEntity::*)(float,float,float),void,float,float,float>::Call;
    v23->m_pFunction = CBaseEntity::ScriptSetLocalAngularVelocity;
    v23->m_flags = 1;
    v24 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v24->m_desc.m_pszDescription = "Get the local angular velocity - returns a vector of pitch,yaw,roll";
    v24->m_desc.m_pszScriptName = "GetAngularVelocity";
    v24->m_desc.m_pszFunction = "ScriptGetLocalAngularVelocity";
    v24->m_desc.m_ReturnType = 3;
    v24->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v24->m_pFunction = CBaseEntity::ScriptGetLocalAngularVelocity;
    v24->m_flags = 1;
    v25 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v25->m_desc.m_pszDescription = "Get vector to center of object - absolute coords";
    v25->m_desc.m_pszScriptName = "GetCenter";
    v25->m_desc.m_pszFunction = "WorldSpaceCenter";
    v25->m_desc.m_ReturnType = 3;
    v25->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v25->m_pFunction =  __thiscall CBaseEntity::`vcall'{588,{flat}};
    v25->m_flags = 1;
    v26 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v26->m_desc.m_pszDescription = "Get vector to eye position - absolute coords";
    v26->m_desc.m_pszScriptName = "EyePosition";
    v26->m_desc.m_pszFunction = "ScriptEyePosition";
    v26->m_desc.m_ReturnType = 3;
    v26->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v26->m_pFunction = CBaseEntity::ScriptEyePosition;
    v26->m_flags = 1;
    v27 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v27->m_desc.m_pszDescription = "Set entity pitch, yaw, roll";
    v27->m_desc.m_pszScriptName = "SetAngles";
    v27->m_desc.m_pszFunction = "ScriptSetAngles";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,float,float,float>(
      pDesc: &v27->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::ScriptSetAngles);
    v27->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding3<CBaseEntity *,void (__thiscall CBaseEntity::*)(float,float,float),void,float,float,float>::Call;
    v27->m_pFunction = CBaseEntity::ScriptSetAngles;
    v27->m_flags = 1;
    v28 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v28->m_desc.m_pszDescription = "Get entity pitch, yaw, roll as a vector";
    v28->m_desc.m_pszScriptName = "GetAngles";
    v28->m_desc.m_pszFunction = "ScriptGetAngles";
    v28->m_desc.m_ReturnType = 3;
    v28->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v28->m_pFunction = CBaseEntity::ScriptGetAngles;
    v28->m_flags = 1;
    v29 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v29->m_desc.m_pszDescription = locale;
    v29->m_desc.m_pszScriptName = "SetSize";
    v29->m_desc.m_pszFunction = "ScriptSetSize";
    ScriptDeduceFunctionSignature<CEnvEntityMaker *,CEnvEntityMaker,void,Vector const &,Vector const &>(
      pDesc: &v29->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::SetSize);
    v29->m_pfnBinding = CMemberScriptBinding2<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &,Vector const &),void,Vector const &,Vector const &>::Call;
    v29->m_pFunction = CBaseEntity::SetSize;
    v29->m_flags = 1;
    v30 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v30->m_desc.m_pszDescription = "Get a vector containing min bounds, centered on object";
    v30->m_desc.m_pszScriptName = "GetBoundingMins";
    v30->m_desc.m_pszFunction = "ScriptGetBoundingMins";
    v30->m_desc.m_ReturnType = 3;
    v30->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v30->m_pFunction = CBaseEntity::ScriptGetBoundingMins;
    v30->m_flags = 1;
    v31 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v31->m_desc.m_pszDescription = "Get a vector containing max bounds, centered on object";
    v31->m_desc.m_pszScriptName = "GetBoundingMaxs";
    v31->m_desc.m_pszFunction = "ScriptGetBoundingMaxs";
    v31->m_desc.m_ReturnType = 3;
    v31->m_pfnBinding = CMemberScriptBinding0<CBaseEntity *,Vector const & (__thiscall CBaseEntity::*)(void),Vector const &>::Call;
    v31->m_pFunction = CBaseEntity::ScriptGetBoundingMaxs;
    v31->m_flags = 1;
    v32 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v32->m_desc.m_pszDescription = locale;
    v32->m_desc.m_pszScriptName = "Destroy";
    v32->m_desc.m_pszFunction = "ScriptUtilRemove";
    v32->m_desc.m_ReturnType = 0;
    v32->m_pfnBinding = CMemberScriptBinding0<CEnvEntityMaker *,void (__thiscall CEnvEntityMaker::*)(void),void>::Call;
    v32->m_pFunction = CNullEntity::Spawn;
    v32->m_flags = 1;
    v33 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v33->m_desc.m_pszDescription = locale;
    v33->m_desc.m_pszScriptName = "SetOwner";
    v33->m_desc.m_pszFunction = "ScriptSetOwner";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,HSCRIPT__ *>(
      pDesc: &v33->m_desc,
      pObject: nullptr,
      pfnProxied: (void (__thiscall *)(CBaseEntity *, HSCRIPT__ *))CBaseEntity::SetScriptOwnerEntity);
    v33->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v33->m_pFunction = CBaseEntity::SetScriptOwnerEntity;
    v33->m_flags = 1;
    v34 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v34->m_desc.m_pszDescription = locale;
    v34->m_desc.m_pszScriptName = "GetTeam";
    v34->m_desc.m_pszFunction = "GetTeamNumber";
    v34->m_desc.m_ReturnType = 5;
    v34->m_pfnBinding = CMemberScriptBinding0<CTriggerCamera *,int (__thiscall CTriggerCamera::*)(void),int>::Call;
    v34->m_pFunction = CBaseEntity::GetTeamNumber;
    v34->m_flags = 1;
    v35 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v35->m_desc.m_pszDescription = locale;
    v35->m_desc.m_pszScriptName = "SetTeam";
    v35->m_desc.m_pszFunction = "ChangeTeam";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,int>(
      pDesc: &v35->m_desc,
      pObject: nullptr,
      pfnProxied:  __thiscall CBaseEntity::`vcall'{372,{flat}});
    v35->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v35->m_pFunction =  __thiscall CBaseEntity::`vcall'{372,{flat}};
    v35->m_flags = 1;
    v36 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v36->m_desc.m_pszDescription = "If in hierarchy, retrieves the entity's parent";
    v36->m_desc.m_pszScriptName = "GetMoveParent";
    v36->m_desc.m_pszFunction = "ScriptGetMoveParent";
    v36->m_desc.m_ReturnType = 33;
    v36->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v36->m_pFunction = CBaseEntity::ScriptGetMoveParent;
    v36->m_flags = 1;
    v37 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v37->m_desc.m_pszDescription = "If in hierarchy, walks up the hierarchy to find the root parent";
    v37->m_desc.m_pszScriptName = "GetRootMoveParent";
    v37->m_desc.m_pszFunction = "ScriptGetRootMoveParent";
    v37->m_desc.m_ReturnType = 33;
    v37->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v37->m_pFunction = CBaseEntity::ScriptGetRootMoveParent;
    v37->m_flags = 1;
    v38 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v38->m_desc.m_pszDescription = locale;
    v38->m_desc.m_pszScriptName = "FirstMoveChild";
    v38->m_desc.m_pszFunction = "ScriptFirstMoveChild";
    v38->m_desc.m_ReturnType = 33;
    v38->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v38->m_pFunction = CBaseEntity::ScriptFirstMoveChild;
    v38->m_flags = 1;
    v39 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v39->m_desc.m_pszDescription = locale;
    v39->m_desc.m_pszScriptName = "NextMovePeer";
    v39->m_desc.m_pszFunction = "ScriptNextMovePeer";
    v39->m_desc.m_ReturnType = 33;
    v39->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v39->m_pFunction = CBaseEntity::ScriptNextMovePeer;
    v39->m_flags = 1;
    v40 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v40->m_desc.m_pszDescription = "@";
    v40->m_desc.m_pszScriptName = "__KeyValueFromString";
    v40->m_desc.m_pszFunction = "KeyValueFromString";
    ScriptDeduceFunctionSignature<CSceneEntity *,CSceneEntity,bool,char const *,char const *>(
      pDesc: &v40->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::KeyValueFromString);
    v40->m_pfnBinding = CMemberScriptBinding2<CSceneEntity *,bool (__thiscall CSceneEntity::*)(char const *,char const *),bool,char const *,char const *>::Call;
    v40->m_pFunction = CBaseEntity::KeyValueFromString;
    v40->m_flags = 1;
    v41 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v41->m_desc.m_pszDescription = "@";
    v41->m_desc.m_pszScriptName = "__KeyValueFromFloat";
    v41->m_desc.m_pszFunction = "KeyValueFromFloat";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,bool,char const *,float>(
      pDesc: &v41->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::KeyValueFromFloat);
    v41->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CBaseEntity *,bool (__thiscall CBaseEntity::*)(char const *,float),bool,char const *,float>::Call;
    v41->m_pFunction = CBaseEntity::KeyValueFromFloat;
    v41->m_flags = 1;
    v42 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v42->m_desc.m_pszDescription = "@";
    v42->m_desc.m_pszScriptName = "__KeyValueFromInt";
    v42->m_desc.m_pszFunction = "KeyValueFromInt";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,bool,char const *,int>(
      pDesc: &v42->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::KeyValueFromInt);
    v42->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CBaseEntity *,bool (__thiscall CBaseEntity::*)(char const *,int),bool,char const *,int>::Call;
    v42->m_pFunction = CBaseEntity::KeyValueFromInt;
    v42->m_flags = 1;
    v43 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v43->m_desc.m_pszDescription = "@";
    v43->m_desc.m_pszScriptName = "__KeyValueFromVector";
    v43->m_desc.m_pszFunction = "KeyValueFromVector";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,bool,char const *,Vector const &>(
      pDesc: &v43->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseEntity::KeyValueFromVector);
    v43->m_pfnBinding = CMemberScriptBinding2<CBaseEntity *,bool (__thiscall CBaseEntity::*)(char const *,Vector const &),bool,char const *,Vector const &>::Call;
    v43->m_pFunction = CBaseEntity::KeyValueFromVector;
    v43->m_flags = 1;
    v44 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v44->m_desc.m_pszDescription = "Get a KeyValue class instance on this entity's model";
    v44->m_desc.m_pszScriptName = "GetModelKeyValues";
    v44->m_desc.m_pszFunction = "ScriptGetModelKeyValues";
    v44->m_desc.m_ReturnType = 33;
    v44->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v44->m_pFunction = CBaseEntity::ScriptGetModelKeyValues;
    v44->m_flags = 1;
    v45 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v45->m_desc.m_pszDescription = "Ensure that an entity's script scope has been created";
    v45->m_desc.m_pszScriptName = "ValidateScriptScope";
    v45->m_desc.m_pszFunction = "ValidateScriptScope";
    v45->m_desc.m_ReturnType = 6;
    v45->m_pfnBinding = CMemberScriptBinding0<CBasePlayer *,bool (__thiscall CBasePlayer::*)(void),bool>::Call;
    v45->m_pFunction = CBaseEntity::ValidateScriptScope;
    v45->m_flags = 1;
    v46 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v46->m_desc.m_pszDescription = "Retrieve the script-side data associated with an entity";
    v46->m_desc.m_pszScriptName = "GetScriptScope";
    v46->m_desc.m_pszFunction = "GetScriptScope";
    v46->m_desc.m_ReturnType = 33;
    v46->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v46->m_pFunction = CBaseEntity::GetScriptScope;
    v46->m_flags = 1;
    v47 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v47->m_desc.m_pszDescription = "Retrieve the unique identifier used to refer to the entity within the scripting system";
    v47->m_desc.m_pszScriptName = "GetScriptId";
    v47->m_desc.m_pszFunction = "GetScriptId";
    v47->m_desc.m_ReturnType = 32;
    v47->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CBaseEntity *,char const * (__thiscall CBaseEntity::*)(void),char const *>::Call;
    v47->m_pFunction = CBaseEntity::GetScriptId;
    v47->m_flags = 1;
    v48 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v48->m_desc.m_pszDescription = "Gets this entity's owner";
    v48->m_desc.m_pszScriptName = "GetOwner";
    v48->m_desc.m_pszFunction = "GetScriptOwnerEntity";
    v48->m_desc.m_ReturnType = 33;
    v48->m_pfnBinding = CMemberScriptBinding0<CScriptEntityIterator *,HSCRIPT__ * (__thiscall CScriptEntityIterator::*)(void),HSCRIPT__ *>::Call;
    v48->m_pFunction = CBaseEntity::GetScriptOwnerEntity;
    v48->m_flags = 1;
    v49 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v49->m_desc.m_pszDescription = "Sets this entity's owner";
    v49->m_desc.m_pszScriptName = "SetOwner";
    v49->m_desc.m_pszFunction = "SetScriptOwnerEntity";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,HSCRIPT__ *>(
      pDesc: &v49->m_desc,
      pObject: nullptr,
      pfnProxied:  __thiscall CBaseEntity::`vcall'{76,{flat}});
    v49->m_pfnBinding = CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v49->m_pFunction =  __thiscall CBaseEntity::`vcall'{76,{flat}};
    v49->m_flags = 1;
    v50 = &g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_CBaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v50->m_desc.m_pszDescription = locale;
    v50->m_flags = 1;
    v50->m_desc.m_pszScriptName = "entindex";
    v50->m_desc.m_pszFunction = "entindex";
    v50->m_desc.m_ReturnType = 5;
    v50->m_pfnBinding = CMemberScriptBinding0<CTriggerCamera *,int (__thiscall CTriggerCamera::*)(void),int>::Call;
    v50->m_pFunction = CBaseEntity::entindex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9B10
// Name: void ModelSoundsCacheShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ModelSoundsCacheShutdown()
{
  char v0; // al

  if ( !engine->IsCreatingXboxReslist(this: engine) && (*((_BYTE *)&g_ModelSoundsCache + 84) & 0x10) != 0 )
  {
    v0 = *((_BYTE *)&g_ModelSoundsCache + 84) & 0xEF;
    *((_BYTE *)&g_ModelSoundsCache + 84) = v0;
    if ( (v0 & 8) != 0 )
    {
      CUtlCachedFileData<CModelSoundsCache>::Save(this: &g_ModelSoundsCache);
      CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_ModelSoundsCache.m_Elements);
    }
    else
    {
      if ( (v0 & 4) != 0 && !CUtlCachedFileData<CModelSoundsCache>::ManifestExists(this: &g_ModelSoundsCache) )
        CUtlCachedFileData<CModelSoundsCache>::SaveManifest(this: &g_ModelSoundsCache);
      CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_ModelSoundsCache.m_Elements);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9B80
// Name: private: int CEntFireAutoCompletionFunctor::EntFire_AutoCompleteInput(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEntFireAutoCompletionFunctor::EntFire_AutoCompleteInput(
        CEntFireAutoCompletionFunctor *this,
        datamap_t *partial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  const char *v3; // edi
  char *result; // eax
  int v5; // esi
  int v6; // ebx
  CBaseEntity *EntityByName; // eax
  int v8; // edi
  int v9; // ebx
  typedescription_t *dataDesc; // esi
  __int16 flags; // ax
  int i; // ebx
  const char *v13; // eax
  CFmtStrN<256> *v14; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v18; // eax
  CUtlString *v19; // edi
  int m_NumElements; // esi
  CFmtStrN<256> v21; // [esp+8h] [ebp-444h] BYREF
  char buf[512]; // [esp+114h] [ebp-338h] BYREF
  char targetEntity[256]; // [esp+314h] [ebp-138h] BYREF
  int nInputNameLength; // [esp+414h] [ebp-38h]
  int c; // [esp+418h] [ebp-34h]
  CUtlRBTree<CUtlString,unsigned short,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short> > symbols; // [esp+41Ch] [ebp-30h] BYREF
  char *inputPartial; // [esp+438h] [ebp-14h]
  CUtlString command; // [esp+43Ch] [ebp-10h] BYREF
  datamap_t *dmap; // [esp+454h] [ebp+8h]
  datamap_t *dmapa; // [esp+454h] [ebp+8h]

  v3 = (const char *)partial;
  if ( _V_strstr(s1: (const char *)partial, search: "ent_fire") != nullptr )
    v3 = (char *)&partial->dataClassName + 1;
  result = _V_strstr(s1: v3, search: " ");
  dmap = (datamap_t *)result;
  if ( result != nullptr )
  {
    v5 = result - v3;
    v6 = _V_strlen(str: v3);
    targetEntity[0] = 0;
    V_strncat(pDest: targetEntity, pSrc: v3, destBufferSize: 0x100u, max_chars_to_copy: v5);
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: targetEntity,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      return nullptr;
    symbols.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))UtlStringLessFunc;
    memset(&symbols.m_Elements, 0, sizeof(symbols.m_Elements));
    *(_DWORD *)&symbols.m_Root = 0xFFFF;
    *(_DWORD *)&symbols.m_FirstFree = -1;
    symbols.m_pElements = nullptr;
    nInputNameLength = v6 - v5 - 1;
    if ( v6 <= v5 )
      inputPartial = nullptr;
    else
      inputPartial = (char *)&dmap->dataDesc + 1;
    dmapa = EntityByName->GetDataDescMap(this: EntityByName);
    if ( dmapa == nullptr )
      goto LABEL_31;
    while ( 1 )
    {
      if ( symbols.m_NumElements >= 0x40u )
        goto LABEL_31;
      v8 = 0;
      c = dmapa->dataNumFields;
      if ( c <= 0 )
        goto LABEL_30;
      v9 = 0;
      while ( 1 )
      {
        dataDesc = dmapa->dataDesc;
        flags = dmapa->dataDesc[v9].flags;
        if ( (flags & 8) != 0
          && (flags & 2) == 0
          && (inputPartial == nullptr
           || V_strnicmp(s1: inputPartial, s2: dataDesc[v9].externalName, n: nInputNameLength) == 0) )
        {
          break;
        }
LABEL_24:
        ++v8;
        ++v9;
        if ( v8 >= c )
          goto LABEL_30;
      }
      CUtlString::CUtlString(this: &command, pString: dataDesc[v9].externalName);
      if ( CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::Find(
             this: &symbols,
             search: &command) == 0xFFFF )
        CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::Insert(
          this: &symbols,
          insert: &command);
      command.m_Storage.m_nActualLength = 0;
      if ( symbols.m_NumElements < 0x40u )
        break;
      if ( command.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( command.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: command.m_Storage.m_Memory.m_pMemory);
          command.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        command.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
LABEL_30:
      dmapa = dmapa->baseMap;
      if ( dmapa == nullptr )
      {
LABEL_31:
        for ( i = (unsigned __int16)CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::FirstInorder(this: &symbols);
              i != 0xFFFF;
              i = (unsigned __int16)CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::NextInorder(
                                      this: &symbols,
                                      i) )
        {
          v13 = CUtlString::operator char const *(this: &symbols.m_Elements.m_pMemory[(unsigned __int16)i].m_Data);
          V_strncpy(pDest: buf, pSrc: v13, maxLen: 512);
          _V_strlower(start: buf);
          CUtlString::CUtlString(this: &command);
          v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v21, pszFormat: "%s %s %s", "ent_fire", targetEntity, buf);
          CUtlString::operator=(this: &command, src: v14->m_szBuf);
          m_Size = commands->m_Size;
          m_nAllocationCount = commands->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)commands,
              num: m_Size - m_nAllocationCount + 1);
          ++commands->m_Size;
          m_pMemory = commands->m_Memory.m_pMemory;
          v18 = commands->m_Size - m_Size - 1;
          commands->m_pElements = commands->m_Memory.m_pMemory;
          if ( v18 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v18);
          v19 = &commands->m_Memory.m_pMemory[m_Size];
          if ( v19 != nullptr )
            CUtlString::CUtlString(this: v19, string: &command);
          command.m_Storage.m_nActualLength = 0;
          if ( command.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( command.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: command.m_Storage.m_Memory.m_pMemory);
              command.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            command.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        m_NumElements = symbols.m_NumElements;
        CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::RemoveAll(this: &symbols);
        if ( symbols.m_Elements.m_nGrowSize >= 0 && symbols.m_Elements.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: symbols.m_Elements.m_pMemory);
        return (char *)m_NumElements;
      }
    }
    if ( command.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( command.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: command.m_Storage.m_Memory.m_pMemory);
        command.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      command.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    goto LABEL_24;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C9EE0
// Name: public: class CModelSoundsCache __near * CUtlCachedFileData<class CModelSoundsCache>::Get(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CModelSoundsCache *__thiscall CUtlCachedFileData<CModelSoundsCache>::Get(
        CUtlCachedFileData<CModelSoundsCache> *this,
        CModelSoundsCache *filename)
{
  unsigned __int16 Index; // ax
  UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short> *m_pMemory; // ecx
  int v5; // eax
  CUtlCachedFileData<CModelSoundsCache>::ElementType_t *p_m_Data; // esi
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem *v8; // ecx
  int v9; // eax
  CModelSoundsCache *v10; // ebx
  char v11; // al
  int cachefileinfo; // [esp+Ch] [ebp-4h]

  Index = CUtlCachedFileData<CModelSoundsCache>::GetIndex(this, filename);
  m_pMemory = this->m_Elements.m_Elements.m_pMemory;
  v5 = Index;
  p_m_Data = &m_pMemory[v5].m_Data;
  if ( m_pMemory[v5].m_Data.fileinfo == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
    m_pMemory[v5].m_Data.fileinfo = 0;
  cachefileinfo = m_pMemory[v5].m_Data.fileinfo;
  if ( m_pMemory[v5].m_Data.diskfileinfo == -2 )
  {
    if ( (*((_BYTE *)this + 84) & 1) != 0 )
    {
      m_pMemory[v5].m_Data.diskfileinfo = m_pMemory[v5].m_Data.fileinfo;
    }
    else
    {
      v7 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      v8 = &g_pFullFileSystem->IBaseFileSystem;
      if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
      {
        v9 = v7->Size(this: v8, a2: (const char *)filename, a3: "GAME");
        p_m_Data->diskfileinfo = v9;
        if ( v9 == -1 )
          p_m_Data->diskfileinfo = 0;
      }
      else
      {
        p_m_Data->diskfileinfo = v7->GetFileTime(this: v8, a2: (const char *)filename, a3: "GAME");
      }
    }
  }
  v10 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  if ( cachefileinfo != p_m_Data->diskfileinfo )
  {
    v11 = *((_BYTE *)this + 84);
    if ( (v11 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v11 | 8;
      v10->Rebuild(this: v10, a2: (const char *)filename);
    }
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100C9FA0
// Name: public: void CUtlCachedFileData<class CModelSoundsCache>::CheckDiskInfo(bool,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CModelSoundsCache>::CheckDiskInfo(
        CUtlCachedFileData<CModelSoundsCache> *this,
        bool forcerebuild,
        int cacheFileTime)
{
  CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short> > *p_m_Elements; // ecx
  int i; // esi
  CSortedCacheFile *v6; // esi
  int m_Size; // ebx
  int Inorder; // edx
  void *handle; // ecx
  int v10; // esi
  CSortedCacheFile *m_pMemory; // ecx
  _DWORD *p_handle; // esi
  int v13; // esi
  int *v14; // ebx
  int v15; // eax
  int *p_index; // ebx
  int v17; // eax
  UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short> *v18; // ecx
  int p_m_Data; // esi
  IBaseFileSystem *v20; // ecx
  int v21; // eax
  const char *v22; // [esp+0h] [ebp-238h]
  char fn[512]; // [esp+Ch] [ebp-22Ch] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+20Ch] [ebp-2Ch] BYREF
  int listEnd; // [esp+228h] [ebp-10h]
  int v26; // [esp+22Ch] [ebp-Ch]
  int pathIndex; // [esp+230h] [ebp-8h]
  bool bSteam; // [esp+237h] [ebp-1h]
  int bCheck; // [esp+240h] [ebp+8h]
  int *bChecka; // [esp+240h] [ebp+8h]
  bool bCheck_3; // [esp+243h] [ebp+Bh]

  p_m_Elements = &this->m_Elements;
  if ( forcerebuild )
  {
    for ( i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &this->m_Elements,
                                  i) )
    {
      g_pFullFileSystem->String(
        this: g_pFullFileSystem,
        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)i].m_Data,
        a3: fn,
        a4: 512);
      CUtlCachedFileData<CModelSoundsCache>::Get(this, filename: (CModelSoundsCache *)fn);
    }
    return;
  }
  v6 = nullptr;
  m_Size = 0;
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
  bCheck = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      pathIndex = (int)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data;
      listEnd = (int)handle;
      list.m_bNeedsSort = true;
      v10 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
          this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
        Inorder = bCheck;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v10 + 1],
          src: &list.m_Memory.m_pMemory[v10],
          count: 8 * (m_Size - v10 - 1));
        Inorder = bCheck;
        m_pMemory = list.m_Memory.m_pMemory;
      }
      p_handle = &m_pMemory[v10].handle;
      if ( p_handle != nullptr )
      {
        *p_handle = listEnd;
        p_handle[1] = Inorder;
      }
      if ( (*((_BYTE *)this + 84) & 1) != 0 && *(_DWORD *)(pathIndex + 8) == -2 )
        *(_DWORD *)(pathIndex + 8) = *(_DWORD *)(pathIndex + 4);
      bCheck = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                   this: &this->m_Elements,
                                   i: Inorder);
      if ( bCheck == 0xFFFF )
        break;
      Inorder = bCheck;
    }
    if ( m_Size != 0 && (*((_BYTE *)this + 84) & 1) == 0 )
    {
      v13 = 0;
      bSteam = g_pFullFileSystem->IsSteam(this: g_pFullFileSystem);
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          bChecka = &list.m_Memory.m_pMemory[v13].index;
          pathIndex = g_pFullFileSystem->GetPathIndex(
                        this: g_pFullFileSystem,
                        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)bChecka].m_Data);
          v26 = v13;
          if ( v13 < m_Size )
          {
            v14 = bChecka;
            do
            {
              v15 = g_pFullFileSystem->GetPathIndex(
                      this: g_pFullFileSystem,
                      a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)v14].m_Data);
              if ( v15 != pathIndex )
                break;
              v14 += 2;
              ++v26;
            }
            while ( v26 < list.m_Size );
          }
          p_index = &list.m_Memory.m_pMemory[v13].index;
          g_pFullFileSystem->String(
            this: g_pFullFileSystem,
            a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
            a3: fn,
            a4: 512);
          V_StripFilename(path: fn);
          bCheck_3 = true;
          if ( !bSteam )
            bCheck_3 = g_pFullFileSystem->GetPathTime(this: g_pFullFileSystem, a2: fn, a3: "GAME") > cacheFileTime;
          v17 = v26;
          if ( v13 < v26 )
          {
            pathIndex = v26 - v13;
            do
            {
              v18 = this->m_Elements.m_Elements.m_pMemory;
              p_m_Data = (int)&v18[*(unsigned __int16 *)p_index].m_Data;
              if ( v18[*(unsigned __int16 *)p_index].m_Data.diskfileinfo == -2 )
              {
                if ( bCheck_3 )
                {
                  ((void (__thiscall *)(IFileSystem *, int, char *, int, const char *))g_pFullFileSystem->String)(
                    a1: g_pFullFileSystem,
                    a2: p_m_Data,
                    a3: fn,
                    a4: 512,
                    a5: v22);
                  v20 = &g_pFullFileSystem->IBaseFileSystem;
                  v22 = "GAME";
                  if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
                  {
                    v21 = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->Size)(a1: v20, a2: fn);
                    *(_DWORD *)(p_m_Data + 8) = v21;
                    if ( v21 == -1 )
                      *(_DWORD *)(p_m_Data + 8) = 0;
                  }
                  else
                  {
                    *(_DWORD *)(p_m_Data + 8) = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->GetFileTime)(
                                                  a1: v20,
                                                  a2: fn);
                  }
                }
                else
                {
                  *(_DWORD *)(p_m_Data + 8) = *(_DWORD *)(p_m_Data + 4);
                }
              }
              p_index += 2;
              --pathIndex;
            }
            while ( pathIndex != 0 );
            v17 = v26;
          }
          v13 = v17 + 1;
          if ( v17 + 1 >= list.m_Size )
            break;
          m_Size = list.m_Size;
        }
      }
      if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      return;
    }
    v6 = list.m_Memory.m_pMemory;
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100CA300
// Name: public: static void CBaseEntity::PrecacheModelComponents(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseEntity::PrecacheModelComponents(bool (__cdecl *a1)(const char *)@<edi>, int nModelIndex)
{
  unsigned __int16 v2; // ax
  KeyValues *v3; // ebx
  const struct model_t *v4; // edi
  char *v5; // esi
  CModelSoundsCache *v6; // eax
  KeyValues *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  KeyValues *Key; // eax
  KeyValues *j; // esi
  KeyValues *v14; // eax
  const char *String; // eax
  const studiohdr_t *v16; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int numlocalseq; // ebx
  int NumSeq_Internal; // eax
  int v20; // edi
  int v21; // eax
  mstudioseqdesc_t *v22; // esi
  mstudioseqdesc_t *v23; // eax
  int v24; // edi
  int v25; // eax
  int v26; // edx
  char *v27; // eax
  int v28; // ebx
  char token[256]; // [esp+4h] [ebp-174h] BYREF
  CStudioHdr studioHdr; // [esp+104h] [ebp-74h] BYREF
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+168h] [ebp-10h] BYREF
  int i; // [esp+170h] [ebp-8h] BYREF
  int k; // [esp+174h] [ebp-4h]
  int nModelIndexa; // [esp+180h] [ebp+8h]

  search.key = nModelIndex;
  v2 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_ModelPrecacheSystem.m_RepeatCounts.m_Tree,
         &search);
  if ( v2 != 0xFFFF )
  {
    ++g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
    return;
  }
  v3 = nullptr;
  i = nModelIndex;
  k = 0;
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &g_ModelPrecacheSystem.m_RepeatCounts.m_Tree,
    insert: (const CUtlMap<int,int,unsigned short>::Node_t *)&i);
  v4 = modelinfo->GetModel(this: modelinfo, a2: nModelIndex);
  if ( v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) == 3 )
  {
    v5 = (char *)modelinfo->GetModelName(this: modelinfo, a2: v4);
    if ( !CUtlCachedFileData<CModelSoundsCache>::EntryExists(this: &g_ModelSoundsCache, filename: v5) )
    {
      V_ExtractFileExtension(path: v5, dest: (char *)&i, destSize: 8);
      if ( V_stristr(pStr: (char *)&i, pSearch: "mdl") == nullptr )
      {
        if ( (_BYTE)i != 0 )
          _Warning(a1: "Late precache of %s (file missing?)\n", v5);
        else
          _Warning(a1: "Precache of %s ambigious (no extension specified)\n", v5);
        return;
      }
      _DevMsg(a1: 2, a2: "Late precache of %s, need to rebuild modelsounds.cache\n", v5);
    }
    v6 = CUtlCachedFileData<CModelSoundsCache>::Get(this: &g_ModelSoundsCache, filename: (CModelSoundsCache *)v5);
    if ( v6 != nullptr )
      CModelSoundsCache::PrecacheSoundList(this: v6);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v3 = KeyValues::KeyValues(this: v7, setName: locale);
    v8 = modelinfo->GetModelKeyValueText(this: modelinfo, a2: v4);
    v9 = (const char *)((int (__thiscall *)(IVModelInfo *, const struct model_t *, const char *))modelinfo->GetModelName)(
                         a1: modelinfo,
                         a2: v4,
                         a3: v8);
    if ( KeyValues::LoadFromBuffer(
           this: v3,
           resourceName: v9,
           pBuffer: nullptr,
           pFileSystem: nullptr,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: a1) )
    {
      if ( (_S7_1 & 1) == 0 )
      {
        _S7_1 |= 1u;
        v10 = _KeyValuesSystem();
        keyParticles = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v10 + 12))(
                         a1: v10,
                         a2: "Particles",
                         a3: 1);
      }
      if ( (_S7_1 & 2) == 0 )
      {
        _S7_1 |= 2u;
        v11 = _KeyValuesSystem();
        keyName = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 12))(a1: v11, a2: "name", a3: 1);
      }
      Key = KeyValues::FindKey(this: v3, keySymbol: keyParticles);
      if ( Key != nullptr )
      {
        for ( j = KeyValues::GetFirstSubKey(this: Key); j != nullptr; j = KeyValues::GetNextKey(this: j) )
        {
          v14 = KeyValues::FindKey(this: j, keySymbol: keyName);
          if ( v14 != nullptr )
            String = KeyValues::GetString(this: v14, keyName: nullptr, defaultValue: locale);
          else
            String = locale;
          PrecacheParticleSystem(pParticleSystemName: String);
        }
      }
    }
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
    v16 = (const studiohdr_t *)((int (__thiscall *)(IVModelInfo *))modelinfo->GetStudiomodel)(a1: modelinfo);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v16, mdlcache: (IMDLCache *)v4);
    if ( studioHdr.m_pStudioHdr != nullptr )
    {
      VerifySequenceIndex(pstudiohdr: &studioHdr);
      if ( studioHdr.m_pVModel != nullptr )
      {
        NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: &studioHdr);
        m_pStudioHdr = studioHdr.m_pStudioHdr;
        numlocalseq = NumSeq_Internal;
      }
      else
      {
        m_pStudioHdr = studioHdr.m_pStudioHdr;
        numlocalseq = studioHdr.m_pStudioHdr->numlocalseq;
      }
      v20 = 0;
      search.elem = numlocalseq;
      for ( k = 0; v20 < numlocalseq; k = v20 )
      {
        if ( studioHdr.m_pVModel != nullptr )
        {
          v23 = CStudioHdr::pSeqdesc_Internal(this: &studioHdr, i: v20);
          m_pStudioHdr = studioHdr.m_pStudioHdr;
          v22 = v23;
        }
        else
        {
          v21 = v20;
          if ( v20 < 0 || v20 >= m_pStudioHdr->numlocalseq )
            v21 = 0;
          v22 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v21 + m_pStudioHdr->localseqindex);
        }
        if ( v22->numevents > 0 )
        {
          v24 = 0;
          nModelIndexa = v22->numevents;
          do
          {
            v25 = v24 + v22->eventindex;
            v26 = *(int *)((char *)&v22->szactivitynameindex + v25);
            v27 = (char *)v22 + v25;
            if ( (v26 & 0x400) != 0 )
              v28 = *((unsigned __int16 *)v27 + 3);
            else
              v28 = *((_DWORD *)v27 + 1);
            if ( ((v26 & 0x400) == 0 || (v26 & 0x10) != 0) && v28 == 32 )
            {
              nexttoken(token, str: v27 + 12, sep: 32);
              PrecacheParticleSystem(pParticleSystemName: token);
            }
            v24 += 80;
            --nModelIndexa;
          }
          while ( nModelIndexa != 0 );
          m_pStudioHdr = studioHdr.m_pStudioHdr;
          numlocalseq = search.elem;
          v20 = k;
        }
        ++v20;
      }
    }
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA670
// Name: public: static int CBaseEntity::PrecacheModel(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall CBaseEntity::PrecacheModel@<eax>(
        bool (__cdecl *a1)(const char *)@<edi>,
        const char *name,
        BOOL bPreload)
{
  int v3; // eax
  int v4; // esi

  if ( name != nullptr && *name != 0 )
  {
    if ( !CBaseEntity::IsPrecacheAllowed() && !engine->IsModelPrecached(this: engine, a2: name) )
      _Warning(a1: "Late precache of %s\n", name);
    v3 = engine->PrecacheModel(this: engine, a2: name, a3: bPreload);
    v4 = v3;
    if ( v3 != -1 )
      CBaseEntity::PrecacheModelComponents(a1, nModelIndex: v3);
    return v4;
  }
  else
  {
    _Msg(a1: "Attempting to precache model, but model name is NULL\n");
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA6F0
// Name: public: virtual int CEntFireAutoCompletionFunctor::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEntFireAutoCompletionFunctor::CommandCompletionCallback(
        CEntFireAutoCompletionFunctor *this,
        datamap_t *partial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  datamap_t *v5; // esi
  const char *v6; // edi
  CBaseEntity *Ent; // esi
  const char *pszValue; // eax
  const char *v9; // eax
  int i; // ebx
  const char *v11; // eax
  CFmtStrN<256> *v12; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v16; // eax
  CUtlString *v17; // edi
  int m_NumElements; // esi
  CFmtStrN<256> v19; // [esp+8h] [ebp-338h] BYREF
  char buf[512]; // [esp+114h] [ebp-22Ch] BYREF
  CUtlRBTree<CUtlString,unsigned short,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short> > symbols; // [esp+314h] [ebp-2Ch] BYREF
  CUtlString command; // [esp+330h] [ebp-10h] BYREF
  int checklen; // [esp+348h] [ebp+8h]

  if ( g_pGameRules == nullptr )
    return nullptr;
  v5 = partial;
  if ( _V_strstr(s1: (const char *)partial, search: "ent_fire") != nullptr )
    partial = (datamap_t *)((char *)partial + 9);
  if ( _V_strstr(s1: (const char *)partial, search: " ") != nullptr )
    return CEntFireAutoCompletionFunctor::EntFire_AutoCompleteInput(
             this: (CEntFireAutoCompletionFunctor *)((char *)this - 4),
             partial: v5,
             commands);
  v6 = (const char *)partial;
  checklen = _V_strlen(str: (const char *)partial);
  symbols.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))UtlStringLessFunc;
  memset(&symbols.m_Elements, 0, sizeof(symbols.m_Elements));
  *(_DWORD *)&symbols.m_Root = 0xFFFF;
  *(_DWORD *)&symbols.m_FirstFree = -1;
  symbols.m_pElements = nullptr;
  Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  if ( Ent == nullptr )
    goto LABEL_22;
  while ( 1 )
  {
    pszValue = Ent->m_iName.m_Value.pszValue;
    if ( pszValue != nullptr && V_strnicmp(s1: pszValue, s2: v6, n: checklen) == 0 )
      break;
LABEL_19:
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
    if ( Ent == nullptr )
      goto LABEL_22;
  }
  v9 = Ent->m_iName.m_Value.pszValue;
  if ( v9 == nullptr )
    v9 = locale;
  CUtlString::CUtlString(this: &command, pString: v9);
  if ( CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::Find(
         this: &symbols,
         search: &command) == 0xFFFF )
    CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::Insert(
      this: &symbols,
      insert: &command);
  if ( symbols.m_NumElements < 0x40u )
  {
    command.m_Storage.m_nActualLength = 0;
    if ( command.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( command.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: command.m_Storage.m_Memory.m_pMemory);
        command.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      command.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    goto LABEL_19;
  }
  CUtlString::~CUtlString(this: &command);
LABEL_22:
  for ( i = (unsigned __int16)CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::FirstInorder(this: &symbols);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::NextInorder(
                                this: &symbols,
                                i) )
  {
    v11 = CUtlString::operator char const *(this: &symbols.m_Elements.m_pMemory[(unsigned __int16)i].m_Data);
    V_strncpy(pDest: buf, pSrc: v11, maxLen: 512);
    _V_strlower(start: buf);
    CUtlString::CUtlString(this: &command);
    v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v19, pszFormat: "%s %s", "ent_fire", buf);
    CUtlString::operator=(this: &command, src: v12->m_szBuf);
    m_Size = commands->m_Size;
    m_nAllocationCount = commands->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)commands,
        num: m_Size - m_nAllocationCount + 1);
    ++commands->m_Size;
    m_pMemory = commands->m_Memory.m_pMemory;
    v16 = commands->m_Size - m_Size - 1;
    commands->m_pElements = commands->m_Memory.m_pMemory;
    if ( v16 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v16);
    v17 = &commands->m_Memory.m_pMemory[m_Size];
    if ( v17 != nullptr )
      CUtlString::CUtlString(this: v17, string: &command);
    command.m_Storage.m_nActualLength = 0;
    if ( command.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( command.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: command.m_Storage.m_Memory.m_pMemory);
        command.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      command.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
  }
  m_NumElements = symbols.m_NumElements;
  CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlString,unsigned short,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,unsigned short>,unsigned short>>(this: &symbols);
  return (char *)m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x100CA980
// Name: public: bool CUtlCachedFileData<class CModelSoundsCache>::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CUtlCachedFileData<CModelSoundsCache>::Init@<al>(
        CUtlCachedFileData<CModelSoundsCache> *this@<ecx>,
        const char *a2@<ebx>)
{
  char v3; // al
  int (*m_pfnMetaChecksum)(void); // eax
  unsigned int v6; // eax
  const char *v7; // eax
  void *v8; // edi
  char v9; // al
  const char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  int fileTime; // [esp+4h] [ebp-Ch]
  void *fh; // [esp+8h] [ebp-8h] BYREF
  bool deletefile; // [esp+Fh] [ebp-1h] BYREF

  v3 = *((_BYTE *)this + 84);
  if ( (v3 & 0x10) != 0 )
    return 1;
  *((_BYTE *)this + 84) = v3 | 0x10;
  if ( CUtlString::Length(this: &this->m_sRepositoryFileName) == 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1044E1CC, a2);
    return 0;
  }
  m_pfnMetaChecksum = (int (*)(void))this->m_pfnMetaChecksum;
  if ( m_pfnMetaChecksum != nullptr )
    v6 = m_pfnMetaChecksum();
  else
    v6 = 0;
  this->m_uCurrentMetaChecksum = v6;
  v7 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v8 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7, a3: "rb", a4: "MOD");
  fh = v8;
  if ( v8 != nullptr )
  {
    v10 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    fileTime = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10, a3: "MOD");
    v11 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    deletefile = false;
    if ( v11 <= 0x100000 )
      CUtlCachedFileData<CModelSoundsCache>::InitSmallBuffer(this, &fh, fileSize: v11, deleteFile: &deletefile);
    else
      CUtlCachedFileData<CModelSoundsCache>::InitLargeBuffer(this, &fh, deleteFile: &deletefile);
    if ( deletefile && (*((_BYTE *)this + 84) & 2) == 0 )
    {
      v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: v12, a3: "MOD");
      *((_BYTE *)this + 84) |= 8u;
    }
    CUtlCachedFileData<CModelSoundsCache>::CheckDiskInfo(this, forcerebuild: false, cacheFileTime: fileTime);
  }
  else
  {
    v9 = *((_BYTE *)this + 84);
    if ( (v9 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v9 | 8;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CAAB0
// Name: public: void CUtlCachedFileData<class CModelSoundsCache>::Reload(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlCachedFileData<CModelSoundsCache>::Reload(
        CUtlCachedFileData<CModelSoundsCache> *this@<ecx>,
        const char *a2@<ebx>)
{
  char v3; // al
  char v4; // al

  v3 = *((_BYTE *)this + 84);
  if ( (v3 & 0x10) != 0 )
  {
    v4 = v3 & 0xEF;
    *((_BYTE *)this + 84) = v4;
    if ( (v4 & 8) != 0 )
    {
      CUtlCachedFileData<CModelSoundsCache>::Save(this);
      CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
      CUtlCachedFileData<CModelSoundsCache>::Init(this, a2);
      return;
    }
    if ( (v4 & 4) != 0 && !CUtlCachedFileData<CModelSoundsCache>::ManifestExists(this) )
      CUtlCachedFileData<CModelSoundsCache>::SaveManifest(this);
    CUtlRBTree<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &,CUtlCachedFileData<CModelSoundsCache>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CModelSoundsCache>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
  }
  CUtlCachedFileData<CModelSoundsCache>::Init(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100CAB00
// Name: public: virtual int CBaseEntity::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CBaseEntity::Restore@<eax>(
        CBaseEntity *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>,
        IRestore *restore)
{
  datamap_t *v4; // eax
  CGameSaveRestoreInfo *v6; // eax
  unsigned int m_Index; // ecx
  Vector *p_vecLandmarkOffset; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  edict_t *m_pPev; // ecx
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  const char *v15; // eax
  const char *v16; // eax
  CBaseEntity_vtbl *v17; // edi
  int v18; // eax
  unsigned int v19; // ecx
  int v20; // eax
  CEntInfo *v21; // edx
  unsigned int v22; // ecx
  int v23; // eax
  bool v24; // zf
  CBaseEntity **v25; // eax
  CBaseEntity *v26; // eax
  __int64 parentSpaceOffset; // [esp+18h] [ebp-10h]
  float parentSpaceOffset_8; // [esp+20h] [ebp-8h]
  _BYTE v30[4]; // [esp+24h] [ebp-4h] BYREF
  int status; // [esp+30h] [ebp+8h]

  CCollisionProperty::DestroyPartitionHandle(this: &this->m_Collision);
  v4 = this->GetDataDescMap(this);
  status = restore->ReadAll(this: restore, a2: this, a3: v4);
  v6 = restore->GetGameSaveRestoreInfo(this: restore);
  parentSpaceOffset_8 = v6->modelSpaceOffset.z;
  m_Index = this->m_pParent.m_Index;
  parentSpaceOffset = *(_QWORD *)&v6->modelSpaceOffset.x;
  if ( m_Index == -1
    || (a2 = (bool (__cdecl *)(const char *))g_pEntityList,
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( v6->levelInfo.fUseLandmark != 0 )
      p_vecLandmarkOffset = &v6->levelInfo.vecLandmarkOffset;
    else
      p_vecLandmarkOffset = &vec3_origin;
    *(float *)&parentSpaceOffset = p_vecLandmarkOffset->x + *(float *)&parentSpaceOffset;
    *((float *)&parentSpaceOffset + 1) = *((float *)&parentSpaceOffset + 1) + p_vecLandmarkOffset->y;
    parentSpaceOffset_8 = p_vecLandmarkOffset->z + parentSpaceOffset_8;
  }
  MatrixSetColumn(in: &this->m_vecAbsOrigin, column: 3, out: &this->m_rgflCoordinateFrame);
  v9 = this->m_vecOrigin.m_Value.x + *(float *)&parentSpaceOffset;
  v10 = this->m_vecOrigin.m_Value.y + *((float *)&parentSpaceOffset + 1);
  v11 = this->m_vecOrigin.m_Value.z + parentSpaceOffset_8;
  if ( this->m_vecOrigin.m_Value.x != v9 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2BCu);
    }
    this->m_vecOrigin.m_Value.x = v9;
  }
  if ( this->m_vecOrigin.m_Value.y != v10 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x2BCu);
    }
    this->m_vecOrigin.m_Value.y = v10;
  }
  if ( this->m_vecOrigin.m_Value.z != v11 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x2C4u);
    }
    this->m_vecOrigin.m_Value.z = v11;
  }
  this->m_iEFlags &= ~0x8000u;
  CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
  if ( this->m_Network.m_pPev != nullptr
    && this->GetModelIndex(this) != 0
    && *(_DWORD *)((int (__thiscall *)(CBaseEntity *, _BYTE *))this->GetModelName)(a1: this, a2: v30) != 0
    && restore->GetPrecacheMode(this: restore) )
  {
    v15 = *(const char **)((int (__thiscall *)(CBaseEntity *, _BYTE *))this->GetModelName)(a1: this, a2: v30);
    if ( v15 == nullptr )
      v15 = locale;
    CBaseEntity::PrecacheModel(a1: a2, name: v15, bPreload: true);
    v16 = *(const char **)((int (__thiscall *)(CBaseEntity *, _BYTE *))this->GetModelName)(a1: this, a2: v30);
    if ( v16 == nullptr )
      v16 = locale;
    v17 = this->__vftable;
    v18 = modelinfo->GetModelIndex(this: modelinfo, a2: v16);
    v17->SetModelIndex(this, a2: v18);
  }
  v19 = this->m_hGroundEntity.m_Value.m_Index;
  if ( v19 != -1 )
  {
    v20 = (unsigned __int16)v19;
    v21 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v19];
    v22 = HIWORD(v19);
    if ( v21->m_SerialNumber == v22 && v21->m_pEntity != nullptr )
    {
      v23 = v20;
      v24 = g_pEntityList->m_EntPtrArray[v23].m_SerialNumber == v22;
      v25 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v23];
      if ( v24 )
        v26 = *v25;
      else
        v26 = nullptr;
      CBaseEntity::AddEntityToGroundList(this: v26, other: this);
    }
  }
  if ( (this->m_fEffects.m_Value & 8) != 0 )
    CBaseEntity::AddEffects(this, nEffects: 8);
  CBaseEntity::UpdateCell(this);
  return status;
}

//------------------------------------------------------------------------------
// Address: 0x100CAE10
// Name: void ClearModelSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ClearModelSoundsCache(const char *a1@<ebx>)
{
  if ( !engine->IsCreatingXboxReslist(this: engine) )
    CUtlCachedFileData<CModelSoundsCache>::Reload(this: &g_ModelSoundsCache, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100CAE30
// Name: bool ModelSoundsCacheInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall ModelSoundsCacheInit@<al>(const char *a1@<ebx>)
{
  if ( engine->IsCreatingXboxReslist(this: engine) )
    return 1;
  else
    return CUtlCachedFileData<CModelSoundsCache>::Init(this: &g_ModelSoundsCache, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10166630
// Name: public: virtual bool CBaseEntity::PassesDamageFilter(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::PassesDamageFilter(CBaseEntity *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hDamageFilter.m_Index;
  if ( m_Index == -1 )
    return true;
  v3 = (unsigned __int16)m_Index;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v5 = HIWORD(m_Index);
  if ( v4->m_SerialNumber != v5 || v4->m_pEntity == nullptr )
    return true;
  v6 = v3;
  v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
  v8 = &g_pEntityList->m_EntPtrArray[v6];
  if ( v7 )
    m_pEntity = v8->m_pEntity;
  else
    m_pEntity = nullptr;
  return ((bool (__thiscall *)(IHandleEntity *, const CTakeDamageInfo *))m_pEntity->__vftable[21].dtr_IHandleEntity)(
           a1: m_pEntity,
           a2: info);
}

//------------------------------------------------------------------------------
// Address: 0x10200160
// Name: private: virtual bool CThinkContextsSaveDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThinkContextsSaveDataOps::IsEmpty(
        CUtlVectorDataOps<CAI_InterestTarget,10> *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *((_DWORD *)fieldInfo->pField + 3) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103FF870
// Name: DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_AnimTimeMustBeFirst::g_SendTable);
  return atexit(func: DT_AnimTimeMustBeFirst::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF890
// Name: DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_AnimTimeMustBeFirst::ignored>(__formal: nullptr);
  DT_AnimTimeMustBeFirst::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF8C0
// Name: DT_BaseEntity::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseEntity::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseEntity::g_SendTable);
  return atexit(func: DT_BaseEntity::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF8E0
// Name: DT_BaseEntity::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseEntity::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseEntity::ignored>(__formal: nullptr);
  DT_BaseEntity::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF950
// Name: thinkfunc_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *thinkfunc_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<thinkfunc_t>();
  thinkfunc_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF960
// Name: ResponseContext_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ResponseContext_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ResponseContext_t>();
  ResponseContext_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF970
// Name: CBaseEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseEntity>(__formal: nullptr);
  CBaseEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419A40
// Name: DT_AnimTimeMustBeFirst::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_AnimTimeMustBeFirst::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_AnimTimeMustBeFirst::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419A50
// Name: DT_BaseEntity::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseEntity::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100C19A0
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,void,char const __near *,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,void (CBaseEntity::*)(char const __near *,char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,char const *,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 32;
}

//------------------------------------------------------------------------------
// Address: 0x100C1AA0
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,void,int>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,void (CBaseEntity::*)(int))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,int>(ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)5;
}

//------------------------------------------------------------------------------
// Address: 0x100C1B50
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,float,char const __near *,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,float (CBaseEntity::*)(char const __near *,char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,float,char const *,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 1;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 32;
}

//------------------------------------------------------------------------------
// Address: 0x100C1C50
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,void,class Vector const __near &>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,void (CBaseEntity::*)(class Vector const __near &))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,Vector const &>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)3;
}

//------------------------------------------------------------------------------
// Address: 0x100C1D00
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,void,float,float,float>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,void (CBaseEntity::*)(float,float,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,float,float,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 3 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 3;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 12);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 12);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  m_Size = pDesc->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 1;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 1;
  v14 = pDesc->m_Parameters.m_Size;
  v15 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v14 + 1 > v15 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v14 - v15 + 1);
  ++pDesc->m_Parameters.m_Size;
  v16 = p_m_Parameters->m_Memory.m_pMemory;
  v17 = pDesc->m_Parameters.m_Size - v14 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
  v18 = &p_m_Parameters->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C1E50
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,void,struct HSCRIPT__ __near *>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,void (CBaseEntity::*)(struct HSCRIPT__ __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,HSCRIPT__ *>(ScriptFuncDescriptor_t *pDesc)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&pDesc->m_Parameters;
  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 1 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_Parameters->m_pMemory;
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 1;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = ((int (__stdcall *)(vgui::TreeNode **, int))v3->Realloc_2)(a1: m_pMemory, a2: 4);
    else
      v4 = ((int (__stdcall *)(int))v3->Alloc_2)(a1: 4);
    p_m_Parameters->m_pMemory = (vgui::TreeNode **)v4;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  v7 = p_m_Parameters->m_pMemory;
  v8 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
  v9 = &p_m_Parameters->m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = (vgui::TreeNode *)33;
}

//------------------------------------------------------------------------------
// Address: 0x100C1F00
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,bool,char const __near *,float>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,bool (CBaseEntity::*)(char const __near *,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,bool,char const *,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 6;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C2000
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,bool,char const __near *,int>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,bool (CBaseEntity::*)(char const __near *,int))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,bool,char const *,int>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 6;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 5;
}

//------------------------------------------------------------------------------
// Address: 0x100C2100
// Name: void ScriptDeduceFunctionSignature<class CBaseEntity __near *,class CBaseEntity,bool,char const __near *,class Vector const __near &>(struct ScriptFuncDescriptor_t __near *,class CBaseEntity __near *,bool (CBaseEntity::*)(char const __near *,class Vector const __near &))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,bool,char const *,Vector const &>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 6;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 3;
}

//------------------------------------------------------------------------------
// Address: 0x100C5790
// Name: struct datamap_t __near * DataMapInit<class CBaseEntity>(class CBaseEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseEntity>()
{
  char *Name; // eax

  if ( (_S6_6 & 1) == 0 )
  {
    _S6_6 |= 1u;
    nameHolder_91.m_pszBase = "CBaseEntity";
    nameHolder_91.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_91.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_91.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_91.m_Names.m_Size = 0;
    nameHolder_91.m_Names.m_pElements = nullptr;
    nameHolder_91.m_nLenBase = 11;
    atexit(func: DataMapInit_CBaseEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseEntity::m_DataMap.baseMap = nullptr;
  if ( (_S6_6 & 2) == 0 )
  {
    _S6_6 |= 2u;
    dataDesc_88[24].pSaveRestoreOps = thinkcontextFuncs;
    dataDesc_88[24].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_88[24].td = 0;
    *(_QWORD *)&dataDesc_88[24].override_field = 0;
    *(_QWORD *)&dataDesc_88[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[24].flatOffset[1] = 0;
    dataDesc_88[25].fieldType = FIELD_CUSTOM;
    dataDesc_88[25].fieldName = "m_ResponseContexts";
    dataDesc_88[25].fieldOffset = 136;
    dataDesc_88[25].fieldSize = 1;
    dataDesc_88[25].flags = 2;
    dataDesc_88[25].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int>>,10>::`vftable';
    }
    dataDesc_88[26].fieldSize = 1;
    dataDesc_88[27].fieldSize = 1;
    dataDesc_88[27].flags = 2;
    dataDesc_88[28].fieldSize = 1;
    *(_QWORD *)dataDesc_88[26].flatOffset = 0;
    dataDesc_88[26].fieldType = FIELD_STRING;
    dataDesc_88[28].flags = 2;
    *(_QWORD *)dataDesc_88[27].flatOffset = 0;
    dataDesc_88[26].flags = 6;
    dataDesc_88[29].fieldSize = 1;
    *(_QWORD *)&dataDesc_88[25].td = 0;
    *(_QWORD *)&dataDesc_88[25].override_field = 0;
    *(_QWORD *)&dataDesc_88[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[25].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_88[28].flatOffset = 0;
    dataDesc_88[25].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<ResponseContext_t,CUtlMemory<ResponseContext_t,int>>>'::`2'::ops;
    dataDesc_88[25].inputFunc = nullptr;
    dataDesc_88[26].fieldName = "m_iszResponseContext";
    dataDesc_88[26].fieldOffset = 156;
    dataDesc_88[26].externalName = "ResponseContext";
    dataDesc_88[26].pSaveRestoreOps = nullptr;
    dataDesc_88[26].inputFunc = nullptr;
    dataDesc_88[26].td = nullptr;
    dataDesc_88[26].fieldSizeInBytes = 4;
    dataDesc_88[26].override_field = nullptr;
    dataDesc_88[26].override_count = 0;
    dataDesc_88[26].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[26].flatGroup = 0;
    dataDesc_88[27].fieldType = FIELD_FUNCTION;
    dataDesc_88[27].fieldName = "m_pfnThink";
    dataDesc_88[27].fieldOffset = 8;
    dataDesc_88[27].externalName = nullptr;
    dataDesc_88[27].pSaveRestoreOps = nullptr;
    dataDesc_88[27].inputFunc = nullptr;
    dataDesc_88[27].td = nullptr;
    dataDesc_88[27].fieldSizeInBytes = 4;
    dataDesc_88[27].override_field = nullptr;
    dataDesc_88[27].override_count = 0;
    dataDesc_88[27].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[27].flatGroup = 0;
    dataDesc_88[28].fieldType = FIELD_FUNCTION;
    dataDesc_88[28].fieldName = "m_pfnTouch";
    dataDesc_88[28].fieldOffset = 540;
    dataDesc_88[28].externalName = nullptr;
    dataDesc_88[28].pSaveRestoreOps = nullptr;
    dataDesc_88[28].inputFunc = nullptr;
    dataDesc_88[28].td = nullptr;
    dataDesc_88[28].fieldSizeInBytes = 4;
    dataDesc_88[28].override_field = nullptr;
    dataDesc_88[28].override_count = 0;
    dataDesc_88[28].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[28].flatGroup = 0;
    dataDesc_88[29].fieldType = FIELD_FUNCTION;
    dataDesc_88[29].fieldName = "m_pfnUse";
    dataDesc_88[29].fieldOffset = 544;
    dataDesc_88[29].flags = 2;
    dataDesc_88[29].externalName = nullptr;
    dataDesc_88[29].pSaveRestoreOps = nullptr;
    dataDesc_88[29].inputFunc = nullptr;
    dataDesc_88[29].td = nullptr;
    dataDesc_88[29].fieldSizeInBytes = 4;
    dataDesc_88[29].override_field = nullptr;
    dataDesc_88[29].override_count = 0;
    dataDesc_88[29].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[29].flatOffset = 0;
    dataDesc_88[30].fieldSize = 1;
    dataDesc_88[30].fieldType = FIELD_FUNCTION;
    dataDesc_88[30].flags = 2;
    dataDesc_88[31].fieldType = FIELD_FUNCTION;
    dataDesc_88[31].flags = 2;
    dataDesc_88[31].fieldSize = 1;
    dataDesc_88[32].fieldSize = 1;
    dataDesc_88[32].flags = 2;
    dataDesc_88[33].fieldSize = 1;
    *(_QWORD *)dataDesc_88[30].flatOffset = 0;
    dataDesc_88[33].flags = 2;
    *(_QWORD *)dataDesc_88[31].flatOffset = 0;
    dataDesc_88[34].fieldSize = 1;
    *(_QWORD *)dataDesc_88[32].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[29].flatGroup = 0;
    dataDesc_88[30].fieldName = "m_pfnBlocked";
    dataDesc_88[30].fieldOffset = 548;
    dataDesc_88[30].externalName = nullptr;
    dataDesc_88[30].pSaveRestoreOps = nullptr;
    dataDesc_88[30].inputFunc = nullptr;
    dataDesc_88[30].td = nullptr;
    dataDesc_88[30].fieldSizeInBytes = 4;
    dataDesc_88[30].override_field = nullptr;
    dataDesc_88[30].override_count = 0;
    dataDesc_88[30].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[30].flatGroup = 0;
    dataDesc_88[31].fieldName = "m_pfnMoveDone";
    dataDesc_88[31].fieldOffset = 4;
    dataDesc_88[31].externalName = nullptr;
    dataDesc_88[31].pSaveRestoreOps = nullptr;
    dataDesc_88[31].inputFunc = nullptr;
    dataDesc_88[31].td = nullptr;
    dataDesc_88[31].fieldSizeInBytes = 4;
    dataDesc_88[31].override_field = nullptr;
    dataDesc_88[31].override_count = 0;
    dataDesc_88[31].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[31].flatGroup = 0;
    dataDesc_88[32].fieldType = FIELD_CHARACTER;
    dataDesc_88[32].fieldName = "m_lifeState";
    dataDesc_88[32].fieldOffset = 553;
    dataDesc_88[32].externalName = nullptr;
    dataDesc_88[32].pSaveRestoreOps = nullptr;
    dataDesc_88[32].inputFunc = nullptr;
    dataDesc_88[32].td = nullptr;
    dataDesc_88[32].fieldSizeInBytes = 1;
    dataDesc_88[32].override_field = nullptr;
    dataDesc_88[32].override_count = 0;
    dataDesc_88[32].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[32].flatGroup = 0;
    dataDesc_88[33].fieldType = FIELD_CHARACTER;
    dataDesc_88[33].fieldName = "m_takedamage";
    dataDesc_88[33].fieldOffset = 554;
    dataDesc_88[33].externalName = nullptr;
    dataDesc_88[33].pSaveRestoreOps = nullptr;
    dataDesc_88[33].inputFunc = nullptr;
    dataDesc_88[33].td = nullptr;
    dataDesc_88[33].fieldSizeInBytes = 1;
    dataDesc_88[33].override_field = nullptr;
    dataDesc_88[33].override_count = 0;
    dataDesc_88[33].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[33].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[33].flatGroup = 0;
    dataDesc_88[34].fieldType = FIELD_INTEGER;
    dataDesc_88[34].fieldName = "m_iMaxHealth";
    dataDesc_88[34].fieldOffset = 524;
    dataDesc_88[34].flags = 6;
    dataDesc_88[34].externalName = "max_health";
    dataDesc_88[35].fieldSize = 1;
    dataDesc_88[35].flags = 6;
    *(_QWORD *)dataDesc_88[34].flatOffset = 0;
    dataDesc_88[36].fieldSize = 1;
    *(_QWORD *)dataDesc_88[35].flatOffset = 0;
    dataDesc_88[36].fieldType = FIELD_STRING;
    dataDesc_88[36].flags = 6;
    dataDesc_88[37].fieldType = FIELD_STRING;
    dataDesc_88[37].flags = 6;
    *(_QWORD *)dataDesc_88[36].flatOffset = 0;
    dataDesc_88[37].fieldSize = 1;
    dataDesc_88[38].fieldSize = 1;
    *(_QWORD *)dataDesc_88[37].flatOffset = 0;
    dataDesc_88[34].pSaveRestoreOps = nullptr;
    dataDesc_88[34].inputFunc = nullptr;
    dataDesc_88[34].td = nullptr;
    dataDesc_88[34].fieldSizeInBytes = 4;
    dataDesc_88[34].override_field = nullptr;
    dataDesc_88[34].override_count = 0;
    dataDesc_88[34].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[34].flatGroup = 0;
    dataDesc_88[35].fieldType = FIELD_INTEGER;
    dataDesc_88[35].fieldName = "m_iHealth";
    dataDesc_88[35].fieldOffset = 528;
    dataDesc_88[35].externalName = "health";
    dataDesc_88[35].pSaveRestoreOps = nullptr;
    dataDesc_88[35].inputFunc = nullptr;
    dataDesc_88[35].td = nullptr;
    dataDesc_88[35].fieldSizeInBytes = 4;
    dataDesc_88[35].override_field = nullptr;
    dataDesc_88[35].override_count = 0;
    dataDesc_88[35].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[35].flatGroup = 0;
    dataDesc_88[36].fieldName = "m_target";
    dataDesc_88[36].fieldOffset = 176;
    dataDesc_88[36].externalName = "target";
    dataDesc_88[36].pSaveRestoreOps = nullptr;
    dataDesc_88[36].inputFunc = nullptr;
    dataDesc_88[36].td = nullptr;
    dataDesc_88[36].fieldSizeInBytes = 4;
    dataDesc_88[36].override_field = nullptr;
    dataDesc_88[36].override_count = 0;
    dataDesc_88[36].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[36].flatGroup = 0;
    dataDesc_88[37].fieldName = "m_iszDamageFilterName";
    dataDesc_88[37].fieldOffset = 532;
    dataDesc_88[37].externalName = "damagefilter";
    dataDesc_88[37].pSaveRestoreOps = nullptr;
    dataDesc_88[37].inputFunc = nullptr;
    dataDesc_88[37].td = nullptr;
    dataDesc_88[37].fieldSizeInBytes = 4;
    dataDesc_88[37].override_field = nullptr;
    dataDesc_88[37].override_count = 0;
    dataDesc_88[37].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[37].flatGroup = 0;
    dataDesc_88[38].fieldType = FIELD_EHANDLE;
    dataDesc_88[38].fieldName = "m_hDamageFilter";
    dataDesc_88[38].fieldOffset = 536;
    dataDesc_88[38].flags = 2;
    dataDesc_88[38].externalName = nullptr;
    dataDesc_88[38].pSaveRestoreOps = nullptr;
    dataDesc_88[38].inputFunc = nullptr;
    dataDesc_88[38].td = nullptr;
    dataDesc_88[38].fieldSizeInBytes = 4;
    dataDesc_88[38].override_field = nullptr;
    dataDesc_88[38].override_count = 0;
    dataDesc_88[38].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[38].flatOffset = 0;
    dataDesc_88[39].fieldSize = 1;
    dataDesc_88[39].flags = 2;
    dataDesc_88[40].fieldSize = 1;
    dataDesc_88[40].flags = 3;
    dataDesc_88[41].fieldSize = 1;
    dataDesc_88[41].flags = 2;
    dataDesc_88[42].fieldSize = 1;
    *(_QWORD *)dataDesc_88[39].flatOffset = 0;
    dataDesc_88[42].flags = 3;
    *(_QWORD *)dataDesc_88[40].flatOffset = 0;
    dataDesc_88[43].fieldSize = 1;
    *(_QWORD *)dataDesc_88[41].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[38].flatGroup = 0;
    dataDesc_88[39].fieldType = FIELD_INTEGER;
    dataDesc_88[39].fieldName = "m_debugOverlays";
    dataDesc_88[39].fieldOffset = 804;
    dataDesc_88[39].externalName = nullptr;
    dataDesc_88[39].pSaveRestoreOps = nullptr;
    dataDesc_88[39].inputFunc = nullptr;
    dataDesc_88[39].td = nullptr;
    dataDesc_88[39].fieldSizeInBytes = 4;
    dataDesc_88[39].override_field = nullptr;
    dataDesc_88[39].override_count = 0;
    dataDesc_88[39].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[39].flatGroup = 0;
    dataDesc_88[40].fieldType = FIELD_EHANDLE;
    dataDesc_88[40].fieldName = "m_pParent";
    dataDesc_88[40].fieldOffset = 208;
    dataDesc_88[40].externalName = nullptr;
    dataDesc_88[40].pSaveRestoreOps = nullptr;
    dataDesc_88[40].inputFunc = nullptr;
    dataDesc_88[40].td = nullptr;
    dataDesc_88[40].fieldSizeInBytes = 4;
    dataDesc_88[40].override_field = nullptr;
    dataDesc_88[40].override_count = 0;
    dataDesc_88[40].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[40].flatGroup = 0;
    dataDesc_88[41].fieldType = FIELD_CHARACTER;
    dataDesc_88[41].fieldName = "m_iParentAttachment";
    dataDesc_88[41].fieldOffset = 213;
    dataDesc_88[41].externalName = nullptr;
    dataDesc_88[41].pSaveRestoreOps = nullptr;
    dataDesc_88[41].inputFunc = nullptr;
    dataDesc_88[41].td = nullptr;
    dataDesc_88[41].fieldSizeInBytes = 1;
    dataDesc_88[41].override_field = nullptr;
    dataDesc_88[41].override_count = 0;
    dataDesc_88[41].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[41].flatGroup = 0;
    dataDesc_88[42].fieldType = FIELD_EHANDLE;
    dataDesc_88[42].fieldName = "m_hMoveParent";
    dataDesc_88[42].fieldOffset = 216;
    dataDesc_88[42].externalName = nullptr;
    dataDesc_88[42].pSaveRestoreOps = nullptr;
    dataDesc_88[42].inputFunc = nullptr;
    dataDesc_88[42].td = nullptr;
    dataDesc_88[42].fieldSizeInBytes = 4;
    dataDesc_88[42].override_field = nullptr;
    dataDesc_88[42].override_count = 0;
    dataDesc_88[42].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[42].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[42].flatGroup = 0;
    dataDesc_88[43].fieldType = FIELD_EHANDLE;
    dataDesc_88[43].fieldName = "m_hMoveChild";
    dataDesc_88[43].fieldOffset = 220;
    dataDesc_88[43].flags = 3;
    dataDesc_88[43].externalName = nullptr;
    dataDesc_88[44].fieldSize = 1;
    dataDesc_88[44].flags = 3;
    dataDesc_88[45].fieldSize = 1;
    dataDesc_88[45].flags = 2;
    dataDesc_88[46].fieldType = FIELD_STRING;
    *(_QWORD *)dataDesc_88[43].flatOffset = 0;
    dataDesc_88[46].fieldSize = 1;
    *(_QWORD *)dataDesc_88[44].flatOffset = 0;
    dataDesc_88[46].flags = 2;
    *(_QWORD *)dataDesc_88[45].flatOffset = 0;
    dataDesc_88[47].fieldSize = 1;
    *(_QWORD *)dataDesc_88[46].flatOffset = 0;
    dataDesc_88[43].pSaveRestoreOps = nullptr;
    dataDesc_88[43].inputFunc = nullptr;
    dataDesc_88[43].td = nullptr;
    dataDesc_88[43].fieldSizeInBytes = 4;
    dataDesc_88[43].override_field = nullptr;
    dataDesc_88[43].override_count = 0;
    dataDesc_88[43].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[43].flatGroup = 0;
    dataDesc_88[44].fieldType = FIELD_EHANDLE;
    dataDesc_88[44].fieldName = "m_hMovePeer";
    dataDesc_88[44].fieldOffset = 224;
    dataDesc_88[44].externalName = nullptr;
    dataDesc_88[44].pSaveRestoreOps = nullptr;
    dataDesc_88[44].inputFunc = nullptr;
    dataDesc_88[44].td = nullptr;
    dataDesc_88[44].fieldSizeInBytes = 4;
    dataDesc_88[44].override_field = nullptr;
    dataDesc_88[44].override_count = 0;
    dataDesc_88[44].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[44].flatGroup = 0;
    dataDesc_88[45].fieldType = FIELD_INTEGER;
    dataDesc_88[45].fieldName = "m_iEFlags";
    dataDesc_88[45].fieldOffset = 196;
    dataDesc_88[45].externalName = nullptr;
    dataDesc_88[45].pSaveRestoreOps = nullptr;
    dataDesc_88[45].inputFunc = nullptr;
    dataDesc_88[45].td = nullptr;
    dataDesc_88[45].fieldSizeInBytes = 4;
    dataDesc_88[45].override_field = nullptr;
    dataDesc_88[45].override_count = 0;
    dataDesc_88[45].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[45].flatGroup = 0;
    dataDesc_88[46].fieldName = "m_iName";
    dataDesc_88[46].fieldOffset = 204;
    dataDesc_88[46].externalName = nullptr;
    dataDesc_88[46].pSaveRestoreOps = nullptr;
    dataDesc_88[46].inputFunc = nullptr;
    dataDesc_88[46].td = nullptr;
    dataDesc_88[46].fieldSizeInBytes = 4;
    dataDesc_88[46].override_field = nullptr;
    dataDesc_88[46].override_count = 0;
    dataDesc_88[46].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[46].flatGroup = 0;
    dataDesc_88[47].fieldType = FIELD_EMBEDDED;
    dataDesc_88[47].fieldName = "m_Collision";
    dataDesc_88[47].fieldOffset = 228;
    dataDesc_88[47].flags = 2;
    dataDesc_88[47].externalName = nullptr;
    dataDesc_88[47].pSaveRestoreOps = nullptr;
    dataDesc_88[47].inputFunc = nullptr;
    dataDesc_88[47].td = &CCollisionProperty::m_DataMap;
    dataDesc_88[47].fieldSizeInBytes = 92;
    dataDesc_88[47].override_field = nullptr;
    dataDesc_88[47].override_count = 0;
    dataDesc_88[47].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[47].flatOffset = 0;
    dataDesc_88[48].fieldSize = 1;
    dataDesc_88[48].flags = 2;
    dataDesc_88[49].fieldSize = 1;
    *(_QWORD *)dataDesc_88[48].flatOffset = 0;
    dataDesc_88[49].fieldType = FIELD_CHARACTER;
    dataDesc_88[49].flags = 6;
    dataDesc_88[50].fieldType = FIELD_CHARACTER;
    *(_QWORD *)dataDesc_88[49].flatOffset = 0;
    dataDesc_88[51].fieldType = FIELD_EHANDLE;
    dataDesc_88[50].fieldSize = 1;
    dataDesc_88[50].flags = 2;
    dataDesc_88[51].fieldSize = 1;
    *(_QWORD *)dataDesc_88[50].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[47].flatGroup = 0;
    dataDesc_88[48].fieldType = FIELD_EMBEDDED;
    dataDesc_88[48].fieldName = "m_Network";
    dataDesc_88[48].fieldOffset = 12;
    dataDesc_88[48].externalName = nullptr;
    dataDesc_88[48].pSaveRestoreOps = nullptr;
    dataDesc_88[48].inputFunc = nullptr;
    dataDesc_88[48].td = &CServerNetworkProperty::m_DataMap;
    dataDesc_88[48].fieldSizeInBytes = 80;
    dataDesc_88[48].override_field = nullptr;
    dataDesc_88[48].override_count = 0;
    dataDesc_88[48].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[48].flatGroup = 0;
    dataDesc_88[49].fieldName = "m_MoveType";
    dataDesc_88[49].fieldOffset = 214;
    dataDesc_88[49].externalName = "MoveType";
    dataDesc_88[49].pSaveRestoreOps = nullptr;
    dataDesc_88[49].inputFunc = nullptr;
    dataDesc_88[49].td = nullptr;
    dataDesc_88[49].fieldSizeInBytes = 1;
    dataDesc_88[49].override_field = nullptr;
    dataDesc_88[49].override_count = 0;
    dataDesc_88[49].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[49].flatGroup = 0;
    dataDesc_88[50].fieldName = "m_MoveCollide";
    dataDesc_88[50].fieldOffset = 215;
    dataDesc_88[50].externalName = nullptr;
    dataDesc_88[50].pSaveRestoreOps = nullptr;
    dataDesc_88[50].inputFunc = nullptr;
    dataDesc_88[50].td = nullptr;
    dataDesc_88[50].fieldSizeInBytes = 1;
    dataDesc_88[50].override_field = nullptr;
    dataDesc_88[50].override_count = 0;
    dataDesc_88[50].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[50].flatGroup = 0;
    dataDesc_88[51].fieldName = "m_hOwnerEntity";
    dataDesc_88[51].fieldOffset = 320;
    dataDesc_88[51].flags = 2;
    dataDesc_88[51].externalName = nullptr;
    dataDesc_88[51].pSaveRestoreOps = nullptr;
    dataDesc_88[51].inputFunc = nullptr;
    dataDesc_88[51].td = nullptr;
    dataDesc_88[51].fieldSizeInBytes = 4;
    dataDesc_88[51].override_field = nullptr;
    dataDesc_88[51].override_count = 0;
    dataDesc_88[51].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[51].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[51].flatGroup = 0;
    dataDesc_88[52].fieldType = FIELD_INTEGER;
    dataDesc_88[52].fieldName = "m_CollisionGroup";
    dataDesc_88[52].fieldOffset = 324;
    dataDesc_88[52].fieldSize = 1;
    dataDesc_88[52].flags = 6;
    dataDesc_88[52].externalName = "CollisionGroup";
    dataDesc_88[52].pSaveRestoreOps = nullptr;
    dataDesc_88[52].fieldTolerance = 0.0;
    dataDesc_88[52].inputFunc = nullptr;
    dataDesc_88[52].td = nullptr;
    dataDesc_88[52].fieldSizeInBytes = 4;
    dataDesc_88[52].override_field = nullptr;
    dataDesc_88[52].override_count = 0;
    *(_QWORD *)dataDesc_88[52].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[52].flatGroup = 0;
    dataDesc_88[53].fieldType = FIELD_CUSTOM;
    dataDesc_88[53].fieldName = "m_pPhysicsObject";
    dataDesc_88[53].fieldOffset = 328;
    dataDesc_88[53].fieldSize = 1;
    dataDesc_88[53].flags = 2;
    dataDesc_88[53].externalName = nullptr;
    dataDesc_88[53].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_88[54].fieldSize = 1;
    dataDesc_88[54].flags = 2;
    *(_QWORD *)dataDesc_88[54].flatOffset = 0;
    dataDesc_88[55].flags = 6;
    *(_QWORD *)&dataDesc_88[53].td = 0;
    *(_QWORD *)&dataDesc_88[53].override_field = 0;
    *(_QWORD *)&dataDesc_88[53].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[53].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_88[55].flatOffset = 0;
    dataDesc_88[53].inputFunc = nullptr;
    dataDesc_88[54].fieldType = FIELD_FLOAT;
    dataDesc_88[54].fieldName = "m_flElasticity";
    dataDesc_88[54].fieldOffset = 440;
    dataDesc_88[54].externalName = nullptr;
    dataDesc_88[54].pSaveRestoreOps = nullptr;
    dataDesc_88[54].inputFunc = nullptr;
    dataDesc_88[54].td = nullptr;
    dataDesc_88[54].fieldSizeInBytes = 4;
    dataDesc_88[54].override_field = nullptr;
    dataDesc_88[54].override_count = 0;
    dataDesc_88[54].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[54].flatGroup = 0;
    dataDesc_88[55].fieldType = FIELD_FLOAT;
    dataDesc_88[55].fieldName = "m_flShadowCastDistance";
    dataDesc_88[55].fieldOffset = 788;
    dataDesc_88[55].fieldSize = 1;
    dataDesc_88[55].externalName = "shadowcastdist";
    dataDesc_88[55].pSaveRestoreOps = nullptr;
    dataDesc_88[55].inputFunc = nullptr;
    dataDesc_88[55].td = nullptr;
    dataDesc_88[55].fieldSizeInBytes = 4;
    dataDesc_88[55].override_field = nullptr;
    dataDesc_88[55].override_count = 0;
    dataDesc_88[55].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[55].flatGroup = 0;
    dataDesc_88[56].fieldType = FIELD_FLOAT;
    dataDesc_88[56].fieldName = "m_flDesiredShadowCastDistance";
    dataDesc_88[56].fieldOffset = 792;
    dataDesc_88[56].fieldSize = 1;
    dataDesc_88[56].flags = 2;
    dataDesc_88[56].externalName = nullptr;
    dataDesc_88[56].pSaveRestoreOps = nullptr;
    dataDesc_88[56].inputFunc = nullptr;
    dataDesc_88[56].td = nullptr;
    dataDesc_88[56].fieldSizeInBytes = 4;
    dataDesc_88[56].override_field = nullptr;
    dataDesc_88[56].override_count = 0;
    dataDesc_88[56].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[56].flatOffset = 0;
    dataDesc_88[57].fieldSize = 1;
    dataDesc_88[57].flags = 14;
    *(_QWORD *)&dataDesc_88[57].override_field = 0;
    *(_QWORD *)&dataDesc_88[57].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[57].flatOffset[1] = 0;
    dataDesc_88[58].flags = 6;
    *(_QWORD *)dataDesc_88[58].flatOffset = 0;
    dataDesc_88[57].fieldType = FIELD_INTEGER;
    dataDesc_88[58].fieldType = FIELD_INTEGER;
    dataDesc_88[59].flags = 2;
    dataDesc_88[60].flags = 2;
    *(_QWORD *)dataDesc_88[59].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[56].flatGroup = 0;
    dataDesc_88[57].fieldName = "m_iInitialTeamNum";
    dataDesc_88[57].fieldOffset = 752;
    dataDesc_88[57].externalName = "TeamNum";
    dataDesc_88[57].pSaveRestoreOps = nullptr;
    dataDesc_88[57].inputFunc = nullptr;
    dataDesc_88[57].td = nullptr;
    dataDesc_88[57].fieldSizeInBytes = 4;
    dataDesc_88[58].fieldName = "m_iTeamNum";
    dataDesc_88[58].fieldOffset = 756;
    dataDesc_88[58].fieldSize = 1;
    dataDesc_88[58].externalName = "teamnumber";
    dataDesc_88[58].pSaveRestoreOps = nullptr;
    dataDesc_88[58].inputFunc = nullptr;
    dataDesc_88[58].td = nullptr;
    dataDesc_88[58].fieldSizeInBytes = 4;
    dataDesc_88[58].override_field = nullptr;
    dataDesc_88[58].override_count = 0;
    dataDesc_88[58].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[58].flatGroup = 0;
    dataDesc_88[59].fieldType = FIELD_EHANDLE;
    dataDesc_88[59].fieldName = "m_hGroundEntity";
    dataDesc_88[59].fieldOffset = 344;
    dataDesc_88[59].fieldSize = 1;
    dataDesc_88[59].externalName = nullptr;
    dataDesc_88[59].pSaveRestoreOps = nullptr;
    dataDesc_88[59].inputFunc = nullptr;
    dataDesc_88[59].td = nullptr;
    dataDesc_88[59].fieldSizeInBytes = 4;
    dataDesc_88[59].override_field = nullptr;
    dataDesc_88[59].override_count = 0;
    dataDesc_88[59].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[59].flatGroup = 0;
    dataDesc_88[60].fieldType = FIELD_TIME;
    dataDesc_88[60].fieldName = "m_flGroundChangeTime";
    dataDesc_88[60].fieldOffset = 348;
    dataDesc_88[60].fieldSize = 1;
    dataDesc_88[60].externalName = nullptr;
    dataDesc_88[60].pSaveRestoreOps = nullptr;
    dataDesc_88[60].inputFunc = nullptr;
    dataDesc_88[60].td = nullptr;
    dataDesc_88[60].fieldSizeInBytes = 4;
    dataDesc_88[60].override_field = nullptr;
    dataDesc_88[60].override_count = 0;
    dataDesc_88[60].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[60].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[60].flatGroup = 0;
    dataDesc_88[61].fieldType = FIELD_MODELNAME;
    dataDesc_88[61].fieldName = "m_ModelName";
    dataDesc_88[61].fieldOffset = 168;
    dataDesc_88[61].fieldSize = 1;
    dataDesc_88[61].flags = 7;
    dataDesc_88[61].externalName = "model";
    dataDesc_88[61].pSaveRestoreOps = nullptr;
    dataDesc_88[61].inputFunc = nullptr;
    dataDesc_88[61].td = nullptr;
    dataDesc_88[61].fieldSizeInBytes = 4;
    dataDesc_88[61].override_field = nullptr;
    dataDesc_88[61].override_count = 0;
    dataDesc_88[62].flags = 6;
    dataDesc_88[63].fieldType = FIELD_VECTOR;
    dataDesc_88[64].fieldType = FIELD_VECTOR;
    dataDesc_88[64].fieldSize = 1;
    *(_QWORD *)dataDesc_88[61].flatOffset = 0;
    dataDesc_88[64].flags = 2;
    dataDesc_88[62].fieldSize = 1;
    dataDesc_88[63].fieldSize = 1;
    *(_QWORD *)dataDesc_88[62].flatOffset = 0;
    dataDesc_88[65].fieldSize = 1;
    dataDesc_88[63].flags = 6;
    *(_QWORD *)dataDesc_88[63].flatOffset = 0;
    dataDesc_88[65].flags = 6;
    *(_QWORD *)dataDesc_88[64].flatOffset = 0;
    dataDesc_88[61].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[61].flatGroup = 0;
    dataDesc_88[62].fieldType = FIELD_STRING;
    dataDesc_88[62].fieldName = "m_AIAddOn";
    dataDesc_88[62].fieldOffset = 764;
    dataDesc_88[62].externalName = "addon";
    dataDesc_88[62].pSaveRestoreOps = nullptr;
    dataDesc_88[62].inputFunc = nullptr;
    dataDesc_88[62].td = nullptr;
    dataDesc_88[62].fieldSizeInBytes = 4;
    dataDesc_88[62].override_field = nullptr;
    dataDesc_88[62].override_count = 0;
    dataDesc_88[62].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[62].flatGroup = 0;
    dataDesc_88[63].fieldName = "m_vecBaseVelocity";
    dataDesc_88[63].fieldOffset = 352;
    dataDesc_88[63].externalName = "basevelocity";
    dataDesc_88[63].pSaveRestoreOps = nullptr;
    dataDesc_88[63].inputFunc = nullptr;
    dataDesc_88[63].td = nullptr;
    dataDesc_88[63].fieldSizeInBytes = 12;
    dataDesc_88[63].override_field = nullptr;
    dataDesc_88[63].override_count = 0;
    dataDesc_88[63].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[63].flatGroup = 0;
    dataDesc_88[64].fieldName = "m_vecAbsVelocity";
    dataDesc_88[64].fieldOffset = 364;
    dataDesc_88[64].externalName = nullptr;
    dataDesc_88[64].pSaveRestoreOps = nullptr;
    dataDesc_88[64].inputFunc = nullptr;
    dataDesc_88[64].td = nullptr;
    dataDesc_88[64].fieldSizeInBytes = 12;
    dataDesc_88[64].override_field = nullptr;
    dataDesc_88[64].override_count = 0;
    dataDesc_88[64].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[64].flatGroup = 0;
    dataDesc_88[65].fieldType = FIELD_VECTOR;
    dataDesc_88[65].fieldName = "m_vecAngVelocity";
    dataDesc_88[65].fieldOffset = 376;
    dataDesc_88[65].externalName = "avelocity";
    dataDesc_88[65].pSaveRestoreOps = nullptr;
    dataDesc_88[65].inputFunc = nullptr;
    dataDesc_88[65].td = nullptr;
    dataDesc_88[65].fieldSizeInBytes = 12;
    dataDesc_88[65].override_field = nullptr;
    dataDesc_88[65].override_count = 0;
    dataDesc_88[65].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[65].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[65].flatGroup = 0;
    dataDesc_88[66].fieldType = FIELD_FLOAT;
    dataDesc_88[66].fieldName = "m_rgflCoordinateFrame";
    dataDesc_88[66].fieldOffset = 388;
    dataDesc_88[66].fieldSize = 12;
    dataDesc_88[66].flags = 2;
    dataDesc_88[67].fieldSize = 1;
    dataDesc_88[67].flags = 6;
    dataDesc_88[68].fieldSize = 1;
    dataDesc_88[68].flags = 2;
    dataDesc_88[69].fieldSize = 1;
    *(_QWORD *)dataDesc_88[66].flatOffset = 0;
    dataDesc_88[69].flags = 2;
    *(_QWORD *)dataDesc_88[67].flatOffset = 0;
    dataDesc_88[70].fieldSize = 1;
    *(_QWORD *)dataDesc_88[68].flatOffset = 0;
    dataDesc_88[66].externalName = nullptr;
    dataDesc_88[66].pSaveRestoreOps = nullptr;
    dataDesc_88[66].inputFunc = nullptr;
    dataDesc_88[66].td = nullptr;
    dataDesc_88[66].fieldSizeInBytes = 48;
    dataDesc_88[66].override_field = nullptr;
    dataDesc_88[66].override_count = 0;
    dataDesc_88[66].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[66].flatGroup = 0;
    dataDesc_88[67].fieldType = FIELD_CHARACTER;
    dataDesc_88[67].fieldName = "m_nWaterLevel";
    dataDesc_88[67].fieldOffset = 339;
    dataDesc_88[67].externalName = "waterlevel";
    dataDesc_88[67].pSaveRestoreOps = nullptr;
    dataDesc_88[67].inputFunc = nullptr;
    dataDesc_88[67].td = nullptr;
    dataDesc_88[67].fieldSizeInBytes = 1;
    dataDesc_88[67].override_field = nullptr;
    dataDesc_88[67].override_count = 0;
    dataDesc_88[67].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[67].flatGroup = 0;
    dataDesc_88[68].fieldType = FIELD_CHARACTER;
    dataDesc_88[68].fieldName = "m_nWaterType";
    dataDesc_88[68].fieldOffset = 338;
    dataDesc_88[68].externalName = nullptr;
    dataDesc_88[68].pSaveRestoreOps = nullptr;
    dataDesc_88[68].inputFunc = nullptr;
    dataDesc_88[68].td = nullptr;
    dataDesc_88[68].fieldSizeInBytes = 1;
    dataDesc_88[68].override_field = nullptr;
    dataDesc_88[68].override_count = 0;
    dataDesc_88[68].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[68].flatGroup = 0;
    dataDesc_88[69].fieldType = FIELD_EHANDLE;
    dataDesc_88[69].fieldName = "m_pBlocker";
    dataDesc_88[69].fieldOffset = 496;
    dataDesc_88[69].externalName = nullptr;
    dataDesc_88[69].pSaveRestoreOps = nullptr;
    dataDesc_88[69].inputFunc = nullptr;
    dataDesc_88[69].td = nullptr;
    dataDesc_88[69].fieldSizeInBytes = 4;
    dataDesc_88[69].override_field = nullptr;
    dataDesc_88[69].override_count = 0;
    dataDesc_88[69].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[69].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[69].flatGroup = 0;
    dataDesc_88[70].fieldType = FIELD_FLOAT;
    dataDesc_88[70].fieldName = "m_flGravity";
    dataDesc_88[70].fieldOffset = 768;
    dataDesc_88[70].flags = 6;
    dataDesc_88[70].externalName = "gravity";
    dataDesc_88[70].pSaveRestoreOps = nullptr;
    dataDesc_88[70].inputFunc = nullptr;
    dataDesc_88[70].td = nullptr;
    dataDesc_88[70].fieldSizeInBytes = 4;
    dataDesc_88[70].override_field = nullptr;
    dataDesc_88[70].override_count = 0;
    dataDesc_88[71].fieldSize = 1;
    dataDesc_88[71].flags = 6;
    dataDesc_88[72].fieldSize = 1;
    dataDesc_88[72].flags = 6;
    dataDesc_88[73].fieldSize = 1;
    *(_QWORD *)dataDesc_88[70].flatOffset = 0;
    dataDesc_88[73].flags = 2;
    *(_QWORD *)dataDesc_88[71].flatOffset = 0;
    dataDesc_88[74].fieldSize = 1;
    *(_QWORD *)dataDesc_88[72].flatOffset = 0;
    dataDesc_88[74].flags = 2;
    *(_QWORD *)dataDesc_88[73].flatOffset = 0;
    dataDesc_88[70].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[70].flatGroup = 0;
    dataDesc_88[71].fieldType = FIELD_FLOAT;
    dataDesc_88[71].fieldName = "m_flFriction";
    dataDesc_88[71].fieldOffset = 436;
    dataDesc_88[71].externalName = "friction";
    dataDesc_88[71].pSaveRestoreOps = nullptr;
    dataDesc_88[71].inputFunc = nullptr;
    dataDesc_88[71].td = nullptr;
    dataDesc_88[71].fieldSizeInBytes = 4;
    dataDesc_88[71].override_field = nullptr;
    dataDesc_88[71].override_count = 0;
    dataDesc_88[71].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[71].flatGroup = 0;
    dataDesc_88[72].fieldType = FIELD_FLOAT;
    dataDesc_88[72].fieldName = "m_flLocalTime";
    dataDesc_88[72].fieldOffset = 444;
    dataDesc_88[72].externalName = "ltime";
    dataDesc_88[72].pSaveRestoreOps = nullptr;
    dataDesc_88[72].inputFunc = nullptr;
    dataDesc_88[72].td = nullptr;
    dataDesc_88[72].fieldSizeInBytes = 4;
    dataDesc_88[72].override_field = nullptr;
    dataDesc_88[72].override_count = 0;
    dataDesc_88[72].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[72].flatGroup = 0;
    dataDesc_88[73].fieldType = FIELD_FLOAT;
    dataDesc_88[73].fieldName = "m_flVPhysicsUpdateLocalTime";
    dataDesc_88[73].fieldOffset = 448;
    dataDesc_88[73].externalName = nullptr;
    dataDesc_88[73].pSaveRestoreOps = nullptr;
    dataDesc_88[73].inputFunc = nullptr;
    dataDesc_88[73].td = nullptr;
    dataDesc_88[73].fieldSizeInBytes = 4;
    dataDesc_88[73].override_field = nullptr;
    dataDesc_88[73].override_count = 0;
    dataDesc_88[73].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[73].flatGroup = 0;
    dataDesc_88[74].fieldType = FIELD_FLOAT;
    dataDesc_88[74].fieldName = "m_flMoveDoneTime";
    dataDesc_88[74].fieldOffset = 452;
    dataDesc_88[74].externalName = nullptr;
    dataDesc_88[74].pSaveRestoreOps = nullptr;
    dataDesc_88[74].inputFunc = nullptr;
    dataDesc_88[74].td = nullptr;
    dataDesc_88[74].fieldSizeInBytes = 4;
    dataDesc_88[74].override_field = nullptr;
    dataDesc_88[74].override_count = 0;
    dataDesc_88[74].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[74].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[74].flatGroup = 0;
    dataDesc_88[75].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_88[75].fieldName = "m_vecAbsOrigin";
    dataDesc_88[75].fieldOffset = 460;
    dataDesc_88[75].fieldSize = 1;
    dataDesc_88[75].flags = 2;
    dataDesc_88[76].fieldSize = 1;
    dataDesc_88[76].flags = 6;
    dataDesc_88[77].fieldSize = 1;
    dataDesc_88[77].flags = 6;
    dataDesc_88[78].fieldType = FIELD_BOOLEAN;
    dataDesc_88[78].fieldSize = 1;
    *(_QWORD *)dataDesc_88[75].flatOffset = 0;
    dataDesc_88[78].flags = 2;
    *(_QWORD *)dataDesc_88[76].flatOffset = 0;
    dataDesc_88[79].fieldSize = 1;
    *(_QWORD *)dataDesc_88[77].flatOffset = 0;
    dataDesc_88[75].externalName = nullptr;
    dataDesc_88[75].pSaveRestoreOps = nullptr;
    dataDesc_88[75].inputFunc = nullptr;
    dataDesc_88[75].td = nullptr;
    dataDesc_88[75].fieldSizeInBytes = 12;
    dataDesc_88[75].override_field = nullptr;
    dataDesc_88[75].override_count = 0;
    dataDesc_88[75].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[75].flatGroup = 0;
    dataDesc_88[76].fieldType = FIELD_VECTOR;
    dataDesc_88[76].fieldName = "m_vecVelocity";
    dataDesc_88[76].fieldOffset = 484;
    dataDesc_88[76].externalName = "velocity";
    dataDesc_88[76].pSaveRestoreOps = nullptr;
    dataDesc_88[76].inputFunc = nullptr;
    dataDesc_88[76].td = nullptr;
    dataDesc_88[76].fieldSizeInBytes = 12;
    dataDesc_88[76].override_field = nullptr;
    dataDesc_88[76].override_count = 0;
    dataDesc_88[76].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[76].flatGroup = 0;
    dataDesc_88[77].fieldType = FIELD_CHARACTER;
    dataDesc_88[77].fieldName = "m_iTextureFrameIndex";
    dataDesc_88[77].fieldOffset = 500;
    dataDesc_88[77].externalName = "texframeindex";
    dataDesc_88[77].pSaveRestoreOps = nullptr;
    dataDesc_88[77].inputFunc = nullptr;
    dataDesc_88[77].td = nullptr;
    dataDesc_88[77].fieldSizeInBytes = 1;
    dataDesc_88[77].override_field = nullptr;
    dataDesc_88[77].override_count = 0;
    dataDesc_88[77].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[77].flatGroup = 0;
    dataDesc_88[78].fieldName = "m_bSimulatedEveryTick";
    dataDesc_88[78].fieldOffset = 501;
    dataDesc_88[78].externalName = nullptr;
    dataDesc_88[78].pSaveRestoreOps = nullptr;
    dataDesc_88[78].inputFunc = nullptr;
    dataDesc_88[78].td = nullptr;
    dataDesc_88[78].fieldSizeInBytes = 1;
    dataDesc_88[78].override_field = nullptr;
    dataDesc_88[78].override_count = 0;
    dataDesc_88[78].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[78].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[78].flatGroup = 0;
    dataDesc_88[79].fieldType = FIELD_BOOLEAN;
    dataDesc_88[79].fieldName = "m_bAnimatedEveryTick";
    dataDesc_88[79].fieldOffset = 502;
    dataDesc_88[79].flags = 2;
    dataDesc_88[79].externalName = nullptr;
    dataDesc_88[79].pSaveRestoreOps = nullptr;
    dataDesc_88[79].inputFunc = nullptr;
    dataDesc_88[79].td = nullptr;
    dataDesc_88[79].fieldSizeInBytes = 1;
    dataDesc_88[79].override_field = nullptr;
    dataDesc_88[79].override_count = 0;
    dataDesc_88[80].fieldSize = 1;
    dataDesc_88[80].flags = 2;
    dataDesc_88[81].fieldSize = 1;
    dataDesc_88[81].flags = 6;
    dataDesc_88[82].fieldSize = 1;
    *(_QWORD *)dataDesc_88[79].flatOffset = 0;
    dataDesc_88[82].flags = 2;
    *(_QWORD *)dataDesc_88[80].flatOffset = 0;
    dataDesc_88[83].fieldSize = 1;
    *(_QWORD *)dataDesc_88[81].flatOffset = 0;
    dataDesc_88[83].flags = 2;
    *(_QWORD *)dataDesc_88[82].flatOffset = 0;
    dataDesc_88[79].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[79].flatGroup = 0;
    dataDesc_88[80].fieldType = FIELD_BOOLEAN;
    dataDesc_88[80].fieldName = "m_bAlternateSorting";
    dataDesc_88[80].fieldOffset = 503;
    dataDesc_88[80].externalName = nullptr;
    dataDesc_88[80].pSaveRestoreOps = nullptr;
    dataDesc_88[80].inputFunc = nullptr;
    dataDesc_88[80].td = nullptr;
    dataDesc_88[80].fieldSizeInBytes = 1;
    dataDesc_88[80].override_field = nullptr;
    dataDesc_88[80].override_count = 0;
    dataDesc_88[80].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[80].flatGroup = 0;
    dataDesc_88[81].fieldType = FIELD_INTEGER;
    dataDesc_88[81].fieldName = "m_spawnflags";
    dataDesc_88[81].fieldOffset = 760;
    dataDesc_88[81].externalName = "spawnflags";
    dataDesc_88[81].pSaveRestoreOps = nullptr;
    dataDesc_88[81].inputFunc = nullptr;
    dataDesc_88[81].td = nullptr;
    dataDesc_88[81].fieldSizeInBytes = 4;
    dataDesc_88[81].override_field = nullptr;
    dataDesc_88[81].override_count = 0;
    dataDesc_88[81].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[81].flatGroup = 0;
    dataDesc_88[82].fieldType = FIELD_CHARACTER;
    dataDesc_88[82].fieldName = "m_nTransmitStateOwnedCounter";
    dataDesc_88[82].fieldOffset = 212;
    dataDesc_88[82].externalName = nullptr;
    dataDesc_88[82].pSaveRestoreOps = nullptr;
    dataDesc_88[82].inputFunc = nullptr;
    dataDesc_88[82].td = nullptr;
    dataDesc_88[82].fieldSizeInBytes = 1;
    dataDesc_88[82].override_field = nullptr;
    dataDesc_88[82].override_count = 0;
    dataDesc_88[82].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[82].flatGroup = 0;
    dataDesc_88[83].fieldType = FIELD_VECTOR;
    dataDesc_88[83].fieldName = "m_angAbsRotation";
    dataDesc_88[83].fieldOffset = 472;
    dataDesc_88[83].externalName = nullptr;
    dataDesc_88[83].pSaveRestoreOps = nullptr;
    dataDesc_88[83].inputFunc = nullptr;
    dataDesc_88[83].td = nullptr;
    dataDesc_88[83].fieldSizeInBytes = 12;
    dataDesc_88[83].override_field = nullptr;
    dataDesc_88[83].override_count = 0;
    dataDesc_88[83].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[83].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[83].flatGroup = 0;
    dataDesc_88[84].fieldType = FIELD_VECTOR;
    dataDesc_88[84].fieldName = "m_vecOrigin";
    dataDesc_88[84].fieldOffset = 700;
    dataDesc_88[84].fieldSize = 1;
    dataDesc_88[84].flags = 2;
    dataDesc_88[85].fieldSize = 1;
    dataDesc_88[85].flags = 2;
    dataDesc_88[86].fieldSize = 1;
    dataDesc_88[86].flags = 2;
    dataDesc_88[87].fieldSize = 1;
    *(_QWORD *)dataDesc_88[84].flatOffset = 0;
    dataDesc_88[87].flags = 6;
    *(_QWORD *)dataDesc_88[85].flatOffset = 0;
    dataDesc_88[84].fieldSizeInBytes = 12;
    dataDesc_88[85].fieldSizeInBytes = 12;
    dataDesc_88[87].fieldSizeInBytes = 12;
    dataDesc_88[88].fieldSize = 1;
    *(_QWORD *)dataDesc_88[86].flatOffset = 0;
    dataDesc_88[84].externalName = nullptr;
    dataDesc_88[84].pSaveRestoreOps = nullptr;
    dataDesc_88[84].inputFunc = nullptr;
    dataDesc_88[84].td = nullptr;
    dataDesc_88[84].override_field = nullptr;
    dataDesc_88[84].override_count = 0;
    dataDesc_88[84].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[84].flatGroup = 0;
    dataDesc_88[85].fieldType = FIELD_VECTOR;
    dataDesc_88[85].fieldName = "m_angRotation";
    dataDesc_88[85].fieldOffset = 712;
    dataDesc_88[85].externalName = nullptr;
    dataDesc_88[85].pSaveRestoreOps = nullptr;
    dataDesc_88[85].inputFunc = nullptr;
    dataDesc_88[85].td = nullptr;
    dataDesc_88[85].override_field = nullptr;
    dataDesc_88[85].override_count = 0;
    dataDesc_88[85].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[85].flatGroup = 0;
    dataDesc_88[86].fieldType = FIELD_BOOLEAN;
    dataDesc_88[86].fieldName = "m_bClientSideRagdoll";
    dataDesc_88[86].fieldOffset = 552;
    dataDesc_88[86].externalName = nullptr;
    dataDesc_88[86].pSaveRestoreOps = nullptr;
    dataDesc_88[86].inputFunc = nullptr;
    dataDesc_88[86].td = nullptr;
    dataDesc_88[86].fieldSizeInBytes = 1;
    dataDesc_88[86].override_field = nullptr;
    dataDesc_88[86].override_count = 0;
    dataDesc_88[86].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[86].flatGroup = 0;
    dataDesc_88[87].fieldType = FIELD_VECTOR;
    dataDesc_88[87].fieldName = "m_vecViewOffset";
    dataDesc_88[87].fieldOffset = 728;
    dataDesc_88[87].externalName = "view_ofs";
    dataDesc_88[87].pSaveRestoreOps = nullptr;
    dataDesc_88[87].inputFunc = nullptr;
    dataDesc_88[87].td = nullptr;
    dataDesc_88[87].override_field = nullptr;
    dataDesc_88[87].override_count = 0;
    dataDesc_88[87].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[87].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[87].flatGroup = 0;
    dataDesc_88[88].fieldType = FIELD_INTEGER;
    dataDesc_88[88].fieldName = "m_fFlags";
    dataDesc_88[88].fieldOffset = 200;
    dataDesc_88[88].flags = 2;
    dataDesc_88[88].externalName = nullptr;
    dataDesc_88[88].pSaveRestoreOps = nullptr;
    dataDesc_88[88].inputFunc = nullptr;
    dataDesc_88[88].td = nullptr;
    dataDesc_88[88].fieldSizeInBytes = 4;
    dataDesc_88[88].override_field = nullptr;
    dataDesc_88[89].fieldSize = 1;
    dataDesc_88[89].flags = 2;
    dataDesc_88[90].fieldSize = 1;
    dataDesc_88[90].flags = 2;
    dataDesc_88[91].fieldSize = 1;
    dataDesc_88[91].flags = 8;
    *(_QWORD *)dataDesc_88[88].flatOffset = 0;
    dataDesc_88[92].fieldSize = 1;
    *(_QWORD *)dataDesc_88[89].flatOffset = 0;
    dataDesc_88[92].flags = 14;
    *(_QWORD *)dataDesc_88[90].flatOffset = 0;
    dataDesc_88[93].fieldSize = 1;
    *(_QWORD *)&dataDesc_88[91].td = 0;
    *(_QWORD *)&dataDesc_88[91].override_field = 0;
    *(_QWORD *)&dataDesc_88[91].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[91].flatOffset[1] = 0;
    dataDesc_88[88].override_count = 0;
    dataDesc_88[88].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[88].flatGroup = 0;
    dataDesc_88[89].fieldType = FIELD_TICK;
    dataDesc_88[89].fieldName = "m_nSimulationTick";
    dataDesc_88[89].fieldOffset = 188;
    dataDesc_88[89].externalName = nullptr;
    dataDesc_88[89].pSaveRestoreOps = nullptr;
    dataDesc_88[89].inputFunc = nullptr;
    dataDesc_88[89].td = nullptr;
    dataDesc_88[89].fieldSizeInBytes = 4;
    dataDesc_88[89].override_field = nullptr;
    dataDesc_88[89].override_count = 0;
    dataDesc_88[89].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[89].flatGroup = 0;
    dataDesc_88[90].fieldType = FIELD_TIME;
    dataDesc_88[90].fieldName = "m_flNavIgnoreUntilTime";
    dataDesc_88[90].fieldOffset = 340;
    dataDesc_88[90].externalName = nullptr;
    dataDesc_88[90].pSaveRestoreOps = nullptr;
    dataDesc_88[90].inputFunc = nullptr;
    dataDesc_88[90].td = nullptr;
    dataDesc_88[90].fieldSizeInBytes = 4;
    dataDesc_88[90].override_field = nullptr;
    dataDesc_88[90].override_count = 0;
    dataDesc_88[90].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[90].flatGroup = 0;
    dataDesc_88[91].fieldType = FIELD_INTEGER;
    dataDesc_88[91].fieldName = "InputSetTeam";
    dataDesc_88[91].fieldOffset = 0;
    dataDesc_88[91].externalName = "SetTeam";
    dataDesc_88[91].pSaveRestoreOps = nullptr;
    dataDesc_88[91].inputFunc = CBaseEntity::InputSetTeam;
    dataDesc_88[92].fieldType = FIELD_FLOAT;
    dataDesc_88[92].fieldName = "m_fadeMinDist";
    dataDesc_88[92].fieldOffset = 776;
    dataDesc_88[92].externalName = "fademindist";
    dataDesc_88[92].pSaveRestoreOps = nullptr;
    dataDesc_88[92].inputFunc = nullptr;
    dataDesc_88[92].td = nullptr;
    dataDesc_88[92].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_88[92].override_field = 0;
    *(_QWORD *)&dataDesc_88[92].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[92].flatOffset[1] = 0;
    dataDesc_88[93].fieldType = FIELD_FLOAT;
    dataDesc_88[93].fieldName = "m_fadeMaxDist";
    dataDesc_88[93].fieldOffset = 780;
    dataDesc_88[93].flags = 14;
    dataDesc_88[93].externalName = "fademaxdist";
    dataDesc_88[93].pSaveRestoreOps = nullptr;
    dataDesc_88[94].fieldSize = 1;
    dataDesc_88[94].flags = 6;
    dataDesc_88[95].fieldSize = 1;
    dataDesc_88[95].flags = 8;
    dataDesc_88[94].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[94].flatOffset = 0;
    dataDesc_88[96].fieldSize = 1;
    *(_QWORD *)&dataDesc_88[95].td = 0;
    *(_QWORD *)&dataDesc_88[95].override_field = 0;
    *(_QWORD *)&dataDesc_88[95].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[95].flatOffset[1] = 0;
    dataDesc_88[96].flags = 8;
    *(_QWORD *)&dataDesc_88[96].td = 0;
    *(_QWORD *)&dataDesc_88[96].override_field = 0;
    *(_QWORD *)&dataDesc_88[96].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[96].flatOffset[1] = 0;
    dataDesc_88[97].fieldSize = 1;
    dataDesc_88[98].fieldType = FIELD_INTEGER;
    *(_QWORD *)&dataDesc_88[97].td = 0;
    *(_QWORD *)&dataDesc_88[97].override_field = 0;
    *(_QWORD *)&dataDesc_88[97].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[97].flatOffset[1] = 0;
    dataDesc_88[93].inputFunc = nullptr;
    dataDesc_88[93].td = nullptr;
    dataDesc_88[93].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_88[93].override_field = 0;
    *(_QWORD *)&dataDesc_88[93].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[93].flatOffset[1] = 0;
    dataDesc_88[94].fieldType = FIELD_FLOAT;
    dataDesc_88[94].fieldName = "m_flFadeScale";
    dataDesc_88[94].fieldOffset = 784;
    dataDesc_88[94].externalName = "fadescale";
    dataDesc_88[94].pSaveRestoreOps = nullptr;
    dataDesc_88[94].inputFunc = nullptr;
    dataDesc_88[94].td = nullptr;
    dataDesc_88[94].fieldSizeInBytes = 4;
    dataDesc_88[94].override_field = nullptr;
    dataDesc_88[94].override_count = 0;
    *(_DWORD *)&dataDesc_88[94].flatGroup = 0;
    dataDesc_88[95].fieldType = FIELD_VOID;
    dataDesc_88[95].fieldName = "InputKill";
    dataDesc_88[95].fieldOffset = 0;
    dataDesc_88[95].externalName = "Kill";
    dataDesc_88[95].pSaveRestoreOps = nullptr;
    dataDesc_88[95].inputFunc = CBaseEntity::InputKill;
    dataDesc_88[96].fieldType = FIELD_VOID;
    dataDesc_88[96].fieldName = "InputKillHierarchy";
    dataDesc_88[96].fieldOffset = 0;
    dataDesc_88[96].externalName = "KillHierarchy";
    dataDesc_88[96].pSaveRestoreOps = nullptr;
    dataDesc_88[96].inputFunc = CBaseEntity::InputKillHierarchy;
    dataDesc_88[97].fieldType = FIELD_VOID;
    dataDesc_88[97].fieldName = "InputUse";
    dataDesc_88[97].fieldOffset = 0;
    dataDesc_88[97].flags = 8;
    dataDesc_88[97].externalName = "Use";
    dataDesc_88[97].pSaveRestoreOps = nullptr;
    dataDesc_88[97].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::InputUse;
    dataDesc_88[98].fieldName = "InputAlpha";
    dataDesc_88[98].fieldOffset = 0;
    dataDesc_88[98].fieldSize = 1;
    dataDesc_88[98].flags = 8;
    dataDesc_88[98].externalName = "Alpha";
    dataDesc_88[98].pSaveRestoreOps = nullptr;
    dataDesc_88[98].inputFunc = CBaseEntity::InputAlpha;
    *(_QWORD *)&dataDesc_88[98].td = 0;
    *(_QWORD *)&dataDesc_88[98].override_field = 0;
    *(_QWORD *)&dataDesc_88[98].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[98].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[99].td = 0;
    *(_QWORD *)&dataDesc_88[99].override_field = 0;
    *(_QWORD *)&dataDesc_88[99].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[99].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[100].td = 0;
    *(_QWORD *)&dataDesc_88[100].override_field = 0;
    *(_QWORD *)&dataDesc_88[100].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[100].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[101].td = 0;
    *(_QWORD *)&dataDesc_88[101].override_field = 0;
    *(_QWORD *)&dataDesc_88[101].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[101].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[102].td = 0;
    *(_QWORD *)&dataDesc_88[102].override_field = 0;
    *(_QWORD *)&dataDesc_88[102].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[102].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[103].td = 0;
    *(_QWORD *)&dataDesc_88[103].override_field = 0;
    *(_QWORD *)&dataDesc_88[103].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[103].flatOffset[1] = 0;
    dataDesc_88[99].fieldType = FIELD_BOOLEAN;
    dataDesc_88[99].fieldName = "InputAlternativeSorting";
    dataDesc_88[99].fieldOffset = 0;
    dataDesc_88[99].fieldSize = 1;
    dataDesc_88[99].flags = 8;
    dataDesc_88[99].externalName = "AlternativeSorting";
    dataDesc_88[99].pSaveRestoreOps = nullptr;
    dataDesc_88[99].inputFunc = CBaseEntity::InputAlternativeSorting;
    dataDesc_88[100].fieldType = FIELD_COLOR32;
    dataDesc_88[100].fieldName = "InputColor";
    dataDesc_88[100].fieldOffset = 0;
    dataDesc_88[100].fieldSize = 1;
    dataDesc_88[100].flags = 8;
    dataDesc_88[100].externalName = "Color";
    dataDesc_88[100].pSaveRestoreOps = nullptr;
    dataDesc_88[100].inputFunc = CBaseEntity::InputColor;
    dataDesc_88[101].fieldType = FIELD_STRING;
    dataDesc_88[101].fieldName = "InputSetParent";
    dataDesc_88[101].fieldOffset = 0;
    dataDesc_88[101].fieldSize = 1;
    dataDesc_88[101].flags = 8;
    dataDesc_88[101].externalName = "SetParent";
    dataDesc_88[101].pSaveRestoreOps = nullptr;
    dataDesc_88[101].inputFunc = CBaseEntity::InputSetParent;
    dataDesc_88[102].fieldType = FIELD_STRING;
    dataDesc_88[102].fieldName = "InputSetParentAttachment";
    dataDesc_88[102].fieldOffset = 0;
    dataDesc_88[102].fieldSize = 1;
    dataDesc_88[102].flags = 8;
    dataDesc_88[102].externalName = "SetParentAttachment";
    dataDesc_88[102].pSaveRestoreOps = nullptr;
    dataDesc_88[102].inputFunc = CBaseEntity::InputSetParentAttachment;
    dataDesc_88[103].fieldType = FIELD_STRING;
    dataDesc_88[103].fieldName = "InputSetParentAttachmentMaintainOffset";
    dataDesc_88[103].fieldOffset = 0;
    dataDesc_88[103].fieldSize = 1;
    dataDesc_88[103].flags = 8;
    dataDesc_88[103].externalName = "SetParentAttachmentMaintainOffset";
    dataDesc_88[103].pSaveRestoreOps = nullptr;
    dataDesc_88[103].inputFunc = CBaseEntity::InputSetParentAttachmentMaintainOffset;
    dataDesc_88[104].fieldType = FIELD_VOID;
    dataDesc_88[104].fieldName = "InputClearParent";
    dataDesc_88[104].fieldOffset = 0;
    dataDesc_88[104].fieldSize = 1;
    dataDesc_88[104].flags = 8;
    dataDesc_88[104].externalName = "ClearParent";
    dataDesc_88[104].pSaveRestoreOps = nullptr;
    dataDesc_88[104].inputFunc = CBaseEntity::InputClearParent;
    *(_QWORD *)&dataDesc_88[104].td = 0;
    *(_QWORD *)&dataDesc_88[104].override_field = 0;
    *(_QWORD *)&dataDesc_88[104].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[104].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[105].td = 0;
    *(_QWORD *)&dataDesc_88[105].override_field = 0;
    *(_QWORD *)&dataDesc_88[105].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[105].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[106].td = 0;
    *(_QWORD *)&dataDesc_88[106].override_field = 0;
    *(_QWORD *)&dataDesc_88[106].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[106].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[107].td = 0;
    *(_QWORD *)&dataDesc_88[107].override_field = 0;
    *(_QWORD *)&dataDesc_88[107].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[107].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[108].td = 0;
    *(_QWORD *)&dataDesc_88[108].override_field = 0;
    *(_QWORD *)&dataDesc_88[108].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[108].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[109].td = 0;
    *(_QWORD *)&dataDesc_88[109].override_field = 0;
    *(_QWORD *)&dataDesc_88[109].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[109].flatOffset[1] = 0;
    dataDesc_88[105].fieldType = FIELD_STRING;
    dataDesc_88[105].fieldName = "InputSetDamageFilter";
    dataDesc_88[105].fieldOffset = 0;
    dataDesc_88[105].fieldSize = 1;
    dataDesc_88[105].flags = 8;
    dataDesc_88[105].externalName = "SetDamageFilter";
    dataDesc_88[105].pSaveRestoreOps = nullptr;
    dataDesc_88[105].inputFunc = CBaseEntity::InputSetDamageFilter;
    dataDesc_88[106].fieldType = FIELD_VOID;
    dataDesc_88[106].fieldName = "InputEnableDamageForces";
    dataDesc_88[106].fieldOffset = 0;
    dataDesc_88[106].fieldSize = 1;
    dataDesc_88[106].flags = 8;
    dataDesc_88[106].externalName = "EnableDamageForces";
    dataDesc_88[106].pSaveRestoreOps = nullptr;
    dataDesc_88[106].inputFunc = CBaseEntity::InputEnableDamageForces;
    dataDesc_88[107].fieldType = FIELD_VOID;
    dataDesc_88[107].fieldName = "InputDisableDamageForces";
    dataDesc_88[107].fieldOffset = 0;
    dataDesc_88[107].fieldSize = 1;
    dataDesc_88[107].flags = 8;
    dataDesc_88[107].externalName = "DisableDamageForces";
    dataDesc_88[107].pSaveRestoreOps = nullptr;
    dataDesc_88[107].inputFunc = CBaseEntity::InputDisableDamageForces;
    dataDesc_88[108].fieldType = FIELD_STRING;
    dataDesc_88[108].fieldName = "InputDispatchResponse";
    dataDesc_88[108].fieldOffset = 0;
    dataDesc_88[108].fieldSize = 1;
    dataDesc_88[108].flags = 8;
    dataDesc_88[108].externalName = "DispatchResponse";
    dataDesc_88[108].pSaveRestoreOps = nullptr;
    dataDesc_88[108].inputFunc = CBaseEntity::InputDispatchResponse;
    dataDesc_88[109].fieldType = FIELD_STRING;
    dataDesc_88[109].fieldName = "InputAddContext";
    dataDesc_88[109].fieldOffset = 0;
    dataDesc_88[109].fieldSize = 1;
    dataDesc_88[109].flags = 8;
    dataDesc_88[109].externalName = "AddContext";
    dataDesc_88[109].pSaveRestoreOps = nullptr;
    dataDesc_88[109].inputFunc = CBaseEntity::InputAddContext;
    dataDesc_88[110].fieldType = FIELD_STRING;
    dataDesc_88[110].fieldName = "InputRemoveContext";
    dataDesc_88[110].fieldOffset = 0;
    dataDesc_88[110].fieldSize = 1;
    dataDesc_88[110].flags = 8;
    dataDesc_88[110].externalName = "RemoveContext";
    dataDesc_88[110].pSaveRestoreOps = nullptr;
    dataDesc_88[110].inputFunc = CBaseEntity::InputRemoveContext;
    *(_QWORD *)&dataDesc_88[110].td = 0;
    *(_QWORD *)&dataDesc_88[110].override_field = 0;
    *(_QWORD *)&dataDesc_88[110].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[110].flatOffset[1] = 0;
    dataDesc_88[111].fieldType = FIELD_STRING;
    dataDesc_88[111].fieldName = "InputClearContext";
    dataDesc_88[111].fieldOffset = 0;
    *(_QWORD *)&dataDesc_88[111].td = 0;
    *(_QWORD *)&dataDesc_88[111].override_field = 0;
    *(_QWORD *)&dataDesc_88[111].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[111].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[112].td = 0;
    *(_QWORD *)&dataDesc_88[112].override_field = 0;
    *(_QWORD *)&dataDesc_88[112].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[112].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[113].td = 0;
    *(_QWORD *)&dataDesc_88[113].override_field = 0;
    *(_QWORD *)&dataDesc_88[113].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[113].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[114].td = 0;
    *(_QWORD *)&dataDesc_88[114].override_field = 0;
    *(_QWORD *)&dataDesc_88[114].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[114].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[115].td = 0;
    *(_QWORD *)&dataDesc_88[115].override_field = 0;
    *(_QWORD *)&dataDesc_88[115].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[115].flatOffset[1] = 0;
    dataDesc_88[111].fieldSize = 1;
    dataDesc_88[111].flags = 8;
    dataDesc_88[111].externalName = "ClearContext";
    dataDesc_88[111].pSaveRestoreOps = nullptr;
    dataDesc_88[111].inputFunc = CBaseEntity::InputClearContext;
    dataDesc_88[112].fieldType = FIELD_VOID;
    dataDesc_88[112].fieldName = "InputDisableShadow";
    dataDesc_88[112].fieldOffset = 0;
    dataDesc_88[112].fieldSize = 1;
    dataDesc_88[112].flags = 8;
    dataDesc_88[112].externalName = "DisableShadow";
    dataDesc_88[112].pSaveRestoreOps = nullptr;
    dataDesc_88[112].inputFunc = CBaseEntity::InputDisableShadow;
    dataDesc_88[113].fieldType = FIELD_VOID;
    dataDesc_88[113].fieldName = "InputEnableShadow";
    dataDesc_88[113].fieldOffset = 0;
    dataDesc_88[113].fieldSize = 1;
    dataDesc_88[113].flags = 8;
    dataDesc_88[113].externalName = "EnableShadow";
    dataDesc_88[113].pSaveRestoreOps = nullptr;
    dataDesc_88[113].inputFunc = CBaseEntity::InputEnableShadow;
    dataDesc_88[114].fieldType = FIELD_VOID;
    dataDesc_88[114].fieldName = "InputDisableDraw";
    dataDesc_88[114].fieldOffset = 0;
    dataDesc_88[114].fieldSize = 1;
    dataDesc_88[114].flags = 8;
    dataDesc_88[114].externalName = "DisableDraw";
    dataDesc_88[114].pSaveRestoreOps = nullptr;
    dataDesc_88[114].inputFunc = CDynamicProp::InputTurnOff;
    dataDesc_88[115].fieldType = FIELD_VOID;
    dataDesc_88[115].fieldName = "InputEnableDraw";
    dataDesc_88[115].fieldOffset = 0;
    dataDesc_88[115].fieldSize = 1;
    dataDesc_88[115].flags = 8;
    dataDesc_88[115].externalName = "EnableDraw";
    dataDesc_88[115].pSaveRestoreOps = nullptr;
    dataDesc_88[115].inputFunc = CBaseEntity::InputEnableDraw;
    dataDesc_88[116].fieldType = FIELD_VOID;
    dataDesc_88[116].fieldName = "InputDisableReceivingFlashlight";
    dataDesc_88[116].fieldOffset = 0;
    dataDesc_88[116].fieldSize = 1;
    dataDesc_88[116].flags = 8;
    dataDesc_88[116].externalName = "DisableReceivingFlashlight";
    dataDesc_88[116].pSaveRestoreOps = nullptr;
    dataDesc_88[116].inputFunc = CBaseEntity::InputDisableReceivingFlashlight;
    *(_QWORD *)&dataDesc_88[116].td = 0;
    *(_QWORD *)&dataDesc_88[116].override_field = 0;
    *(_QWORD *)&dataDesc_88[116].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[116].flatOffset[1] = 0;
    dataDesc_88[117].fieldType = FIELD_VOID;
    dataDesc_88[117].fieldName = "InputEnableReceivingFlashlight";
    dataDesc_88[117].fieldOffset = 0;
    dataDesc_88[117].fieldSize = 1;
    dataDesc_88[117].flags = 8;
    dataDesc_88[117].externalName = "EnableReceivingFlashlight";
    *(_QWORD *)&dataDesc_88[117].td = 0;
    *(_QWORD *)&dataDesc_88[117].override_field = 0;
    *(_QWORD *)&dataDesc_88[117].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[117].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[118].td = 0;
    *(_QWORD *)&dataDesc_88[118].override_field = 0;
    *(_QWORD *)&dataDesc_88[118].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[118].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[119].td = 0;
    *(_QWORD *)&dataDesc_88[119].override_field = 0;
    *(_QWORD *)&dataDesc_88[119].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[119].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[120].td = 0;
    *(_QWORD *)&dataDesc_88[120].override_field = 0;
    *(_QWORD *)&dataDesc_88[120].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[120].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[121].td = 0;
    *(_QWORD *)&dataDesc_88[121].override_field = 0;
    *(_QWORD *)&dataDesc_88[121].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[121].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_88[122].td = 0;
    *(_QWORD *)&dataDesc_88[122].override_field = 0;
    *(_QWORD *)&dataDesc_88[122].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[122].flatOffset[1] = 0;
    dataDesc_88[117].pSaveRestoreOps = nullptr;
    dataDesc_88[117].inputFunc = CBaseEntity::InputEnableReceivingFlashlight;
    dataDesc_88[118].fieldType = FIELD_VOID;
    dataDesc_88[118].fieldName = "InputDisableDrawInFastReflection";
    dataDesc_88[118].fieldOffset = 0;
    dataDesc_88[118].fieldSize = 1;
    dataDesc_88[118].flags = 8;
    dataDesc_88[118].externalName = "DisableDrawInFastReflection";
    dataDesc_88[118].pSaveRestoreOps = nullptr;
    dataDesc_88[118].inputFunc = CBaseEntity::InputDisableDrawInFastReflection;
    dataDesc_88[119].fieldType = FIELD_VOID;
    dataDesc_88[119].fieldName = "InputEnableDrawInFastReflection";
    dataDesc_88[119].fieldOffset = 0;
    dataDesc_88[119].fieldSize = 1;
    dataDesc_88[119].flags = 8;
    dataDesc_88[119].externalName = "EnableDrawInFastReflection";
    dataDesc_88[119].pSaveRestoreOps = nullptr;
    dataDesc_88[119].inputFunc = CBaseEntity::InputEnableDrawInFastReflection;
    dataDesc_88[120].fieldType = FIELD_STRING;
    dataDesc_88[120].fieldName = "InputAddOutput";
    dataDesc_88[120].fieldOffset = 0;
    dataDesc_88[120].fieldSize = 1;
    dataDesc_88[120].flags = 8;
    dataDesc_88[120].externalName = "AddOutput";
    dataDesc_88[120].pSaveRestoreOps = nullptr;
    dataDesc_88[120].inputFunc = CBaseEntity::InputAddOutput;
    dataDesc_88[121].fieldType = FIELD_STRING;
    dataDesc_88[121].fieldName = "InputFireUser1";
    dataDesc_88[121].fieldOffset = 0;
    dataDesc_88[121].fieldSize = 1;
    dataDesc_88[121].flags = 8;
    dataDesc_88[121].externalName = "FireUser1";
    dataDesc_88[121].pSaveRestoreOps = nullptr;
    dataDesc_88[121].inputFunc = CBaseEntity::InputFireUser1;
    dataDesc_88[122].fieldType = FIELD_STRING;
    dataDesc_88[122].fieldName = "InputFireUser2";
    dataDesc_88[122].fieldOffset = 0;
    dataDesc_88[122].fieldSize = 1;
    dataDesc_88[122].flags = 8;
    dataDesc_88[122].externalName = "FireUser2";
    dataDesc_88[122].pSaveRestoreOps = nullptr;
    dataDesc_88[122].inputFunc = CBaseEntity::InputFireUser2;
    dataDesc_88[123].fieldType = FIELD_STRING;
    dataDesc_88[123].fieldName = "InputFireUser3";
    dataDesc_88[123].fieldOffset = 0;
    dataDesc_88[123].fieldSize = 1;
    dataDesc_88[123].flags = 8;
    dataDesc_88[123].externalName = "FireUser3";
    dataDesc_88[123].pSaveRestoreOps = nullptr;
    dataDesc_88[123].inputFunc = CBaseEntity::InputFireUser3;
    *(_QWORD *)&dataDesc_88[123].td = 0;
    *(_QWORD *)&dataDesc_88[123].override_field = 0;
    *(_QWORD *)&dataDesc_88[123].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[123].flatOffset[1] = 0;
    dataDesc_88[124].fieldType = FIELD_STRING;
    *(_QWORD *)&dataDesc_88[124].td = 0;
    *(_QWORD *)&dataDesc_88[124].override_field = 0;
    *(_QWORD *)&dataDesc_88[124].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[124].flatOffset[1] = 0;
    dataDesc_88[125].fieldType = FIELD_STRING;
    dataDesc_88[126].fieldType = FIELD_STRING;
    dataDesc_88[127].fieldType = FIELD_STRING;
    dataDesc_88[124].fieldSize = 1;
    dataDesc_88[125].fieldSize = 1;
    *(_QWORD *)&dataDesc_88[125].td = 0;
    *(_QWORD *)&dataDesc_88[125].override_field = 0;
    *(_QWORD *)&dataDesc_88[125].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[125].flatOffset[1] = 0;
    dataDesc_88[126].fieldSize = 1;
    dataDesc_88[124].flags = 8;
    dataDesc_88[125].flags = 8;
    dataDesc_88[126].flags = 8;
    dataDesc_88[127].fieldSize = 1;
    *(_QWORD *)&dataDesc_88[126].td = 0;
    *(_QWORD *)&dataDesc_88[126].override_field = 0;
    *(_QWORD *)&dataDesc_88[126].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[126].flatOffset[1] = 0;
    dataDesc_88[127].flags = 8;
    dataDesc_88[128].fieldSize = 1;
    dataDesc_88[128].flags = 22;
    dataDesc_88[129].fieldSize = 1;
    *(_QWORD *)&dataDesc_88[127].td = 0;
    *(_QWORD *)&dataDesc_88[127].override_field = 0;
    *(_QWORD *)&dataDesc_88[127].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[127].flatOffset[1] = 0;
    dataDesc_88[124].fieldName = "InputFireUser4";
    dataDesc_88[124].fieldOffset = 0;
    dataDesc_88[124].externalName = "FireUser4";
    dataDesc_88[124].pSaveRestoreOps = nullptr;
    dataDesc_88[124].inputFunc = CBaseEntity::InputFireUser4;
    dataDesc_88[125].fieldName = "InputRunScriptFile";
    dataDesc_88[125].fieldOffset = 0;
    dataDesc_88[125].externalName = "RunScriptFile";
    dataDesc_88[125].pSaveRestoreOps = nullptr;
    dataDesc_88[125].inputFunc = CBaseEntity::InputRunScriptFile;
    dataDesc_88[126].fieldName = "InputRunScript";
    dataDesc_88[126].fieldOffset = 0;
    dataDesc_88[126].externalName = "RunScriptCode";
    dataDesc_88[126].pSaveRestoreOps = nullptr;
    dataDesc_88[126].inputFunc = CBaseEntity::InputRunScript;
    dataDesc_88[127].fieldName = "InputCallScriptFunction";
    dataDesc_88[127].fieldOffset = 0;
    dataDesc_88[127].externalName = "CallScriptFunction";
    dataDesc_88[127].pSaveRestoreOps = nullptr;
    dataDesc_88[127].inputFunc = CBaseEntity::InputCallScriptFunction;
    dataDesc_88[128].fieldType = FIELD_CUSTOM;
    dataDesc_88[128].fieldName = "m_OnUser1";
    dataDesc_88[128].fieldOffset = 560;
    dataDesc_88[128].externalName = "OnUser1";
    dataDesc_88[128].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_88[128].inputFunc = 0;
    *(_QWORD *)&dataDesc_88[128].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_88[128].override_count = 0;
    *(_QWORD *)dataDesc_88[128].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[128].flatGroup = 0;
    dataDesc_88[129].fieldType = FIELD_CUSTOM;
    dataDesc_88[129].fieldName = "m_OnUser2";
    dataDesc_88[129].fieldOffset = 584;
    dataDesc_88[129].flags = 22;
    dataDesc_88[130].fieldType = FIELD_CUSTOM;
    dataDesc_88[131].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_88[129].inputFunc = 0;
    *(_QWORD *)&dataDesc_88[129].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_88[129].override_count = 0;
    *(_QWORD *)dataDesc_88[129].flatOffset = 0;
    dataDesc_88[130].fieldSize = 1;
    *(_QWORD *)&dataDesc_88[130].inputFunc = 0;
    *(_QWORD *)&dataDesc_88[130].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_88[130].override_count = 0;
    *(_QWORD *)dataDesc_88[130].flatOffset = 0;
    dataDesc_88[131].fieldSize = 1;
    dataDesc_88[129].externalName = "OnUser2";
    dataDesc_88[129].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_88[129].flatGroup = 0;
    dataDesc_88[130].fieldName = "m_OnUser3";
    dataDesc_88[130].fieldOffset = 608;
    dataDesc_88[130].flags = 22;
    dataDesc_88[130].externalName = "OnUser3";
    dataDesc_88[130].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_88[130].flatGroup = 0;
    dataDesc_88[131].fieldName = "m_OnUser4";
    dataDesc_88[131].fieldOffset = 632;
    dataDesc_88[131].flags = 22;
    dataDesc_88[131].externalName = "OnUser4";
    dataDesc_88[131].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_88[131].inputFunc = 0;
    *(_QWORD *)&dataDesc_88[131].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_88[131].override_count = 0;
    *(_QWORD *)dataDesc_88[131].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[131].flatGroup = 0;
    dataDesc_88[132].fieldType = FIELD_VOID;
    dataDesc_88[132].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "SUB_Remove");
    dataDesc_88[132].flags = 32;
    dataDesc_88[132].fieldOffset = 0;
    dataDesc_88[132].fieldSize = 1;
    dataDesc_88[132].externalName = nullptr;
    dataDesc_88[132].pSaveRestoreOps = nullptr;
    dataDesc_88[132].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::SUB_Remove;
    *(_QWORD *)&dataDesc_88[132].td = 0;
    *(_QWORD *)&dataDesc_88[132].override_field = 0;
    *(_QWORD *)&dataDesc_88[132].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[132].flatOffset[1] = 0;
    dataDesc_88[133].fieldType = FIELD_VOID;
    dataDesc_88[133].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "SUB_DoNothing");
    dataDesc_88[133].fieldOffset = 0;
    dataDesc_88[133].fieldSize = 1;
    dataDesc_88[133].flags = 32;
    dataDesc_88[133].externalName = nullptr;
    dataDesc_88[133].pSaveRestoreOps = nullptr;
    dataDesc_88[133].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BaseNPC::OnSetSchedule;
    *(_QWORD *)&dataDesc_88[133].td = 0;
    *(_QWORD *)&dataDesc_88[133].override_field = 0;
    *(_QWORD *)&dataDesc_88[133].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[133].flatOffset[1] = 0;
    dataDesc_88[134].fieldType = FIELD_VOID;
    dataDesc_88[134].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "SUB_StartFadeOut");
    dataDesc_88[134].fieldOffset = 0;
    dataDesc_88[134].fieldSize = 1;
    dataDesc_88[134].flags = 32;
    dataDesc_88[134].externalName = nullptr;
    dataDesc_88[134].pSaveRestoreOps = nullptr;
    dataDesc_88[134].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::SUB_StartFadeOut;
    *(_QWORD *)&dataDesc_88[134].td = 0;
    *(_QWORD *)&dataDesc_88[134].override_field = 0;
    *(_QWORD *)&dataDesc_88[134].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[134].flatOffset[1] = 0;
    dataDesc_88[135].fieldType = FIELD_VOID;
    dataDesc_88[135].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "SUB_StartFadeOutInstant");
    dataDesc_88[135].flags = 32;
    dataDesc_88[135].fieldOffset = 0;
    dataDesc_88[135].fieldSize = 1;
    dataDesc_88[135].externalName = nullptr;
    dataDesc_88[135].pSaveRestoreOps = nullptr;
    dataDesc_88[135].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::SUB_StartFadeOutInstant;
    *(_QWORD *)&dataDesc_88[135].td = 0;
    *(_QWORD *)&dataDesc_88[135].override_field = 0;
    *(_QWORD *)&dataDesc_88[135].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[135].flatOffset[1] = 0;
    dataDesc_88[136].fieldType = FIELD_VOID;
    dataDesc_88[136].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "SUB_FadeOut");
    dataDesc_88[136].fieldOffset = 0;
    dataDesc_88[136].fieldSize = 1;
    dataDesc_88[136].flags = 32;
    dataDesc_88[136].externalName = nullptr;
    dataDesc_88[136].pSaveRestoreOps = nullptr;
    dataDesc_88[136].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::SUB_FadeOut;
    *(_QWORD *)&dataDesc_88[136].td = 0;
    *(_QWORD *)&dataDesc_88[136].override_field = 0;
    *(_QWORD *)&dataDesc_88[136].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[136].flatOffset[1] = 0;
    dataDesc_88[137].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_91, pszIdentifier: "SUB_Vanish");
    dataDesc_88[137].fieldSize = 1;
    dataDesc_88[137].fieldName = Name;
    dataDesc_88[137].fieldOffset = 0;
    dataDesc_88[137].flags = 32;
    dataDesc_88[137].externalName = nullptr;
    dataDesc_88[137].pSaveRestoreOps = nullptr;
    dataDesc_88[137].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::SUB_Vanish;
    *(_QWORD *)&dataDesc_88[137].td = 0;
    *(_QWORD *)&dataDesc_88[137].override_field = 0;
    *(_QWORD *)&dataDesc_88[137].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[137].flatOffset[1] = 0;
    dataDesc_88[138].fieldType = FIELD_VOID;
    dataDesc_88[138].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "SUB_CallUseToggle");
    dataDesc_88[138].fieldOffset = 0;
    dataDesc_88[138].fieldSize = 1;
    dataDesc_88[138].flags = 32;
    dataDesc_88[138].externalName = nullptr;
    dataDesc_88[138].pSaveRestoreOps = nullptr;
    dataDesc_88[138].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::SUB_CallUseToggle;
    *(_QWORD *)&dataDesc_88[138].td = 0;
    *(_QWORD *)&dataDesc_88[138].override_field = 0;
    *(_QWORD *)&dataDesc_88[138].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[138].flatOffset[1] = 0;
    dataDesc_88[139].fieldType = FIELD_VOID;
    dataDesc_88[139].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "ShadowCastDistThink");
    dataDesc_88[139].fieldOffset = 0;
    dataDesc_88[139].fieldSize = 1;
    dataDesc_88[139].flags = 32;
    dataDesc_88[139].externalName = nullptr;
    dataDesc_88[139].pSaveRestoreOps = nullptr;
    dataDesc_88[139].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::ShadowCastDistThink;
    *(_QWORD *)&dataDesc_88[139].td = 0;
    *(_QWORD *)&dataDesc_88[139].override_field = 0;
    *(_QWORD *)&dataDesc_88[139].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[139].flatOffset[1] = 0;
    dataDesc_88[140].fieldType = FIELD_VOID;
    dataDesc_88[140].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_91,
                                   pszIdentifier: "ScriptThink");
    dataDesc_88[140].fieldSize = 1;
    dataDesc_88[141].fieldSize = 1;
    dataDesc_88[141].flags = 2;
    dataDesc_88[140].flags = 32;
    dataDesc_88[142].fieldType = FIELD_BOOLEAN;
    dataDesc_88[143].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)&dataDesc_88[140].td = 0;
    *(_QWORD *)&dataDesc_88[140].override_field = 0;
    *(_QWORD *)&dataDesc_88[140].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_88[140].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_88[141].flatOffset = 0;
    dataDesc_88[140].fieldOffset = 0;
    dataDesc_88[140].externalName = nullptr;
    dataDesc_88[140].pSaveRestoreOps = nullptr;
    dataDesc_88[140].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseEntity::ScriptThink;
    dataDesc_88[141].fieldType = FIELD_EHANDLE;
    dataDesc_88[141].fieldName = "m_hEffectEntity";
    dataDesc_88[141].fieldOffset = 772;
    dataDesc_88[141].externalName = nullptr;
    dataDesc_88[141].pSaveRestoreOps = nullptr;
    dataDesc_88[141].inputFunc = nullptr;
    dataDesc_88[141].td = nullptr;
    dataDesc_88[141].fieldSizeInBytes = 4;
    dataDesc_88[141].override_field = nullptr;
    dataDesc_88[141].override_count = 0;
    dataDesc_88[141].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_88[141].flatGroup = 0;
    dataDesc_88[142].fieldName = "m_bLagCompensate";
    dataDesc_88[142].fieldOffset = 797;
    dataDesc_88[142].fieldSize = 1;
    dataDesc_88[142].flags = 6;
    dataDesc_88[142].externalName = "LagCompensate";
    dataDesc_88[142].pSaveRestoreOps = nullptr;
    dataDesc_88[142].inputFunc = nullptr;
    dataDesc_88[142].td = nullptr;
    dataDesc_88[142].fieldSizeInBytes = 1;
    dataDesc_88[142].override_field = nullptr;
    dataDesc_88[142].override_count = 0;
    dataDesc_88[142].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_88[142].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[142].flatGroup = 0;
    dataDesc_88[143].fieldName = "m_bForcePurgeFixedupStrings";
    dataDesc_88[143].fieldOffset = 798;
    dataDesc_88[143].fieldSize = 1;
    dataDesc_88[143].flags = 2;
    dataDesc_88[143].fieldTolerance = 0.0;
    dataDesc_88[143].externalName = nullptr;
    dataDesc_88[143].pSaveRestoreOps = nullptr;
    dataDesc_88[143].inputFunc = nullptr;
    dataDesc_88[143].td = nullptr;
    dataDesc_88[143].fieldSizeInBytes = 1;
    dataDesc_88[143].override_field = nullptr;
    dataDesc_88[143].override_count = 0;
    *(_QWORD *)dataDesc_88[143].flatOffset = 0;
    *(_DWORD *)&dataDesc_88[143].flatGroup = 0;
  }
  CBaseEntity::m_DataMap.dataNumFields = 143;
  CBaseEntity::m_DataMap.dataDesc = &dataDesc_88[1];
  return &CBaseEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FF8A0
// Name: _dynamic_initializer_for__g_CBaseEntity_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseEntity_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseEntity_ClassReg,
           pNetworkName: "CBaseEntity",
           pTable: &DT_BaseEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF8F0
// Name: _dynamic_initializer_for__autoaim_viewing_client__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autoaim_viewing_client__()
{
  ConVar::ConVar(this: &autoaim_viewing_client, pName: "autoaim_viewing_client", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__autoaim_viewing_client__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF980
// Name: _dynamic_initializer_for__g_CBaseEntity_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CBaseEntity_ScriptDesc__()
{
  InitCBaseEntityScriptDesc();
  g_CBaseEntity_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CBaseEntity_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CBaseEntity_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF9B0
// Name: _dynamic_initializer_for__ai_debug_los__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_los__()
{
  ConVar::ConVar(
    this: &ai_debug_los,
    pName: "ai_debug_los",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "NPC Line-Of-Sight debug mode. If 1, solid entities that block NPC LOC will be highlighted with white bounding boxes."
    " If 2, it'll show non-solid entities that would do it if they were solid.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))CC_AI_LOS_Debug);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_los__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF9E0
// Name: _dynamic_initializer_for__ent_messages_draw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_messages_draw__()
{
  ConVar::ConVar(
    this: &ent_messages_draw,
    pName: "ent_messages_draw",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Visualizes all entity input/output activity.");
  return atexit(func: dynamic_atexit_destructor_for__ent_messages_draw__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFA10
// Name: _dynamic_initializer_for__g_TeleportStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TeleportStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_TeleportStack__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFA20
// Name: _dynamic_initializer_for__g_ModelSoundsCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelSoundsCache__()
{
  CUtlString::CUtlString(this: &g_ModelSoundsCache.m_sRepositoryFileName, pString: "modelsounds.cache");
  *((_BYTE *)&g_ModelSoundsCache + 84) &= 0xE0u;
  g_ModelSoundsCache.m_nVersion = 5;
  g_ModelSoundsCache.m_pfnMetaChecksum = nullptr;
  g_ModelSoundsCache.m_uCurrentMetaChecksum = 0;
  g_ModelSoundsCache.m_fileCheckType = UTL_CACHED_FILE_USE_FILESIZE;
  return atexit(func: dynamic_atexit_destructor_for__g_ModelSoundsCache__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFA70
// Name: _dynamic_initializer_for__g_ModelSoundsSymbolHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelSoundsSymbolHelper__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ModelSoundsSymbolHelper, growSize: 0, initSize: 32, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ModelSoundsSymbolHelper__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFA90
// Name: _dynamic_initializer_for__g_ModelSoundsCacheSaver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelSoundsCacheSaver__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_ModelSoundsCacheSaver, name: "CModelSoundsCacheSaver");
  g_ModelSoundsCacheSaver.__vftable = (CModelSoundsCacheSaver_vtbl *)&CModelSoundsCacheSaver::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_ModelSoundsCacheSaver__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFAC0
// Name: _dynamic_initializer_for__g_ModelPrecacheSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelPrecacheSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_ModelPrecacheSystem, name: "CModelPrecacheSystem");
  g_ModelPrecacheSystem.__vftable = (CModelPrecacheSystem_vtbl *)&CModelPrecacheSystem::`vftable';
  g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
  g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_Elements.m_pMemory = nullptr;
  g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_FirstFree = -1;
  g_ModelPrecacheSystem.m_RepeatCounts.m_Tree.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_ModelPrecacheSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFB20
// Name: _dynamic_initializer_for__ent_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_name__()
{
  ConCommand::ConCommand(
    this: &ent_name,
    pName: "ent_name",
    callback: CC_Ent_Name,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_name__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFB50
// Name: _dynamic_initializer_for__ent_text__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_text__()
{
  ConCommand::ConCommand(
    this: &ent_text,
    pName: "ent_text",
    callback: CC_Ent_Text,
    pHelpString: "Displays text debugging information about the given entity(ies) on top of the entity (See Overlay Text)\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_text__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFB80
// Name: _dynamic_initializer_for__ent_script_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_script_dump__()
{
  ConCommand::ConCommand(
    this: &ent_script_dump,
    pName: "ent_script_dump",
    callback: CC_Ent_Script_Dump,
    pHelpString: "Dumps the names and values of this entity's script scope to the console\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_script_dump__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFBB0
// Name: _dynamic_initializer_for__ent_bbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_bbox__()
{
  ConCommand::ConCommand(
    this: &ent_bbox,
    pName: "ent_bbox",
    callback: CC_Ent_BBox,
    pHelpString: "Displays the movement bounding box for the given entity(ies) in orange.  Some entites will also display entity speci"
    "fic overlays.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_bbox__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFBE0
// Name: _dynamic_initializer_for__ent_absbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_absbox__()
{
  ConCommand::ConCommand(
    this: &ent_absbox,
    pName: "ent_absbox",
    callback: CC_Ent_AbsBox,
    pHelpString: "Displays the total bounding box for the given entity(s) in green.  Some entites will also display entity specific ov"
    "erlays.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_absbox__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFC10
// Name: _dynamic_initializer_for__ent_rbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_rbox__()
{
  ConCommand::ConCommand(
    this: &ent_rbox,
    pName: "ent_rbox",
    callback: CC_Ent_RBox,
    pHelpString: "Displays the total bounding box for the given entity(s) in green.  Some entites will also display entity specific ov"
    "erlays.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_rbox__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFC40
// Name: _dynamic_initializer_for__ent_attachments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_attachments__()
{
  ConCommand::ConCommand(
    this: &ent_attachments,
    pName: "ent_attachments",
    callback: CC_Ent_AttachmentPoints,
    pHelpString: "Displays the attachment points on an entity.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_attachments__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFC70
// Name: _dynamic_initializer_for__ent_viewoffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_viewoffset__()
{
  ConCommand::ConCommand(
    this: &ent_viewoffset,
    pName: "ent_viewoffset",
    callback: CC_Ent_ViewOffset,
    pHelpString: "Displays the eye position for the given entity(ies) in red.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_viewoffset__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFCA0
// Name: _dynamic_initializer_for__ent_remove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_remove__()
{
  ConCommand::ConCommand(
    this: &ent_remove,
    pName: "ent_remove",
    callback: CC_Ent_Remove,
    pHelpString: "Removes the given entity(s)\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_remove__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFCD0
// Name: _dynamic_initializer_for__ent_remove_all__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_remove_all__()
{
  ConCommand::ConCommand(
    this: &ent_remove_all,
    pName: "ent_remove_all",
    callback: CC_Ent_RemoveAll,
    pHelpString: "Removes all entities of the specified type\n\tArguments:   \t{entity_name} / {class_name} ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_remove_all__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFD00
// Name: _dynamic_initializer_for__ent_setname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_setname__()
{
  ConCommand::ConCommand(
    this: &ent_setname,
    pName: "ent_setname",
    callback: CC_Ent_SetName,
    pHelpString: "Sets the targetname of the given entity(s)\n"
    "\tArguments:   \t{new entity name} {entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_setname__);
}

//------------------------------------------------------------------------------
// Address: 0x10419A60
// Name: _ServerClassInit_DT_BaseEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_25;
  for ( i = 36; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419A80
// Name: _dynamic_atexit_destructor_for__autoaim_viewing_client__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autoaim_viewing_client__()
{
  ConVar::~ConVar(this: &autoaim_viewing_client);
}
