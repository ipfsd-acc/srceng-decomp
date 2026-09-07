// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/baseanimating.cpp
// Functions: 168
// ============================================================

#include "game\server\baseanimating.h"

//------------------------------------------------------------------------------
// Address: 0x10012C90
// Name: public: float CBaseAnimating::SetPoseParameter(int,float)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CBaseAnimating::SetPoseParameter(CBaseAnimating *this, int iParameter, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return CBaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter, flValue);
}

//------------------------------------------------------------------------------
// Address: 0x1002DBF0
// Name: public: virtual void CBaseAnimating::SetLightingOrigin(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetLightingOrigin(CBaseAnimating *this, CBaseEntity *pLightingOrigin)
{
  CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOrigin>::Set(
    this: &this->m_hLightingOrigin,
    val: pLightingOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x10097D20
// Name: void MatrixAngles(struct matrix3x4_t const __near &,class QAngle __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixAngles(const matrix3x4_t *matrix, QAngle *angles, Vector *position)
{
  MatrixAngles(src: (const VMatrix *)matrix, vAngles: angles);
  position->x = matrix->m_flMatVal[0][3];
  position->y = matrix->m_flMatVal[1][3];
  position->z = matrix->m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x10097D50
// Name: public: virtual struct datamap_t __near * CBaseAnimating::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseAnimating::GetDataDescMap(CBaseAnimating *this)
{
  return &CBaseAnimating::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10097D60
// Name: public: virtual class ServerClass __near * CBaseAnimating::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseAnimating::GetServerClass(CBaseAnimating *this)
{
  return &g_CBaseAnimating_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10097D70
// Name: public: virtual struct ScriptClassDesc_t __near * CBaseAnimating::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CBaseAnimating::GetScriptDesc(CBaseAnimating *this)
{
  return GetScriptDesc(__formal: this);
}

//------------------------------------------------------------------------------
// Address: 0x10097DA0
// Name: public: virtual float CBaseAnimating::GetIdealAccel(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetIdealAccel(CBaseAnimating *this)
{
  return ((double (__thiscall *)(CBaseAnimating *))this->GetIdealSpeed)(a1: this) + 50.0;
}

//------------------------------------------------------------------------------
// Address: 0x10097DC0
// Name: public: bool CBaseAnimating::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::GetAttachment(
        CBaseAnimating *this,
        int iAttachment,
        Vector *absOrigin,
        QAngle *absAngles)
{
  bool v4; // bl
  matrix3x4_t attachmentToWorld; // [esp+4h] [ebp-30h] BYREF

  v4 = this->GetAttachment(this, a2: iAttachment, a3: &attachmentToWorld);
  MatrixAngles(src: (const VMatrix *)&attachmentToWorld, vAngles: absAngles);
  absOrigin->x = attachmentToWorld.m_flMatVal[0][3];
  absOrigin->y = attachmentToWorld.m_flMatVal[1][3];
  absOrigin->z = attachmentToWorld.m_flMatVal[2][3];
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10097E20
// Name: public: class Vector const __near & CBaseAnimating::ScriptGetAttachmentOrigin(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseAnimating::ScriptGetAttachmentOrigin(CBaseAnimating *this, int iAttachment)
{
  unsigned int v2; // eax
  _BYTE v4[12]; // [esp+0h] [ebp-30h] BYREF
  float v5; // [esp+Ch] [ebp-24h]
  float v6; // [esp+1Ch] [ebp-14h]
  float v7; // [esp+2Ch] [ebp-4h]

  v2 = _S5_4;
  if ( (_S5_4 & 1) == 0 )
  {
    v2 = _S5_4 | 1;
    _S5_4 |= 1u;
  }
  if ( (v2 & 2) == 0 )
    _S5_4 = v2 | 2;
  this->GetAttachment(this, a2: iAttachment, a3: (matrix3x4_t *)v4);
  MatrixAngles(src: (const VMatrix *)v4, vAngles: &qa);
  absOrigin.x = v5;
  absOrigin.y = v6;
  absOrigin.z = v7;
  return &absOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10097EA0
// Name: public: class Vector const __near & CBaseAnimating::ScriptGetAttachmentAngles(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseAnimating::ScriptGetAttachmentAngles(CBaseAnimating *this, int iAttachment)
{
  unsigned int v2; // eax
  _BYTE v4[12]; // [esp+0h] [ebp-30h] BYREF
  float v5; // [esp+Ch] [ebp-24h]
  float v6; // [esp+1Ch] [ebp-14h]
  float v7; // [esp+2Ch] [ebp-4h]

  v2 = _S6_2;
  if ( (_S6_2 & 1) == 0 )
  {
    v2 = _S6_2 | 1;
    _S6_2 |= 1u;
  }
  if ( (v2 & 2) == 0 )
  {
    v2 |= 2u;
    _S6_2 = v2;
  }
  if ( (v2 & 4) == 0 )
    _S6_2 = v2 | 4;
  this->GetAttachment(this, a2: iAttachment, a3: (matrix3x4_t *)v4);
  MatrixAngles(src: (const VMatrix *)v4, vAngles: &qa_0);
  absOrigin_0.x = v5;
  absOrigin_0.y = v6;
  absOrigin_0.z = v7;
  absAngles = (Vector)qa_0;
  return &absAngles;
}

//------------------------------------------------------------------------------
// Address: 0x10097F60
// Name: public: bool CBaseAnimating::GetAttachment(int,class Vector __near &,class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::GetAttachment(
        CBaseAnimating *this,
        int iAttachment,
        Vector *absOrigin,
        Vector *forward,
        Vector *right,
        Vector *up)
{
  bool v6; // bl
  matrix3x4_t attachmentToWorld; // [esp+4h] [ebp-30h] BYREF

  v6 = this->GetAttachment(this, a2: iAttachment, a3: &attachmentToWorld);
  absOrigin->x = attachmentToWorld.m_flMatVal[0][3];
  absOrigin->y = attachmentToWorld.m_flMatVal[1][3];
  absOrigin->z = attachmentToWorld.m_flMatVal[2][3];
  if ( forward != nullptr )
    MatrixGetColumn(in: &attachmentToWorld, column: 0, out: forward);
  if ( right != nullptr )
    MatrixGetColumn(in: &attachmentToWorld, column: 1, out: right);
  if ( up != nullptr )
    MatrixGetColumn(in: &attachmentToWorld, column: 2, out: up);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10097FF0
// Name: public: virtual void CBaseAnimating::InvalidateBoneCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::InvalidateBoneCache(CBaseAnimating *this)
{
  Studio_InvalidateBoneCacheIfNotMatching(cacheHandle: this->m_boneCacheHandle, flTimeValid: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10098010
// Name: public: virtual void CBaseAnimating::ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::ModifyOrAppendCriteria(CBaseAnimating *this, ResponseRules::CriteriaSet *set)
{
  CBaseEntity::ModifyOrAppendCriteria(this, set);
}

//------------------------------------------------------------------------------
// Address: 0x10098020
// Name: public: void CBaseAnimating::InputIgnite(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::InputIgnite(CBaseAnimating *this, inputdata_t *inputdata)
{
  ((void (__stdcall *)(int, _DWORD, _DWORD, int))this->Ignite)(a1: 1106247680, a2: 0, a3: 0, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10098050
// Name: public: struct matrix3x4_t __near & CBaseEntity::EntityToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__thiscall CBaseEntity::EntityToWorldTransform(CBaseEntity *this)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  return &this->m_rgflCoordinateFrame;
}

//------------------------------------------------------------------------------
// Address: 0x100984C0
// Name: class IScriptInstanceHelper __near * GetScriptInstanceHelper_CBaseAnimating(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
IScriptInstanceHelper *__cdecl GetScriptInstanceHelper_CBaseAnimating()
{
  return GetScriptInstanceHelper_CBaseEntity();
}

//------------------------------------------------------------------------------
// Address: 0x100984D0
// Name: public: virtual void CBaseAnimating::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::Precache(CBaseAnimating *this)
{
  PrecacheParticleSystem(pParticleSystemName: "burning_character");
}

//------------------------------------------------------------------------------
// Address: 0x100984E0
// Name: public: float CBaseAnimating::GetAnimTimeInterval(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetAnimTimeInterval(CBaseAnimating *this)
{
  float m_Value; // xmm0_4
  float curtime; // xmm1_4
  float v3; // xmm1_4
  float v4; // xmm0_4

  m_Value = this->m_flAnimTime.m_Value;
  curtime = gpGlobals->curtime;
  if ( curtime <= m_Value )
  {
    v4 = m_Value - this->m_flPrevAnimTime;
    v3 = 0.0;
    if ( v4 < 0.0 )
      return v3;
    v3 = 0.2;
    if ( v4 > 0.2 )
      return v3;
  }
  else
  {
    v3 = curtime - m_Value;
    v4 = 0.0;
    if ( v3 >= 0.0 )
    {
      v4 = 0.2;
      if ( v3 <= 0.2 )
        return v3;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10098550
// Name: public: void CBaseAnimating::SetLightingOriginRelative(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetLightingOriginRelative(CBaseAnimating *this, string_t strLightingOriginRelative)
{
  CBaseEntity *EntityByName; // eax
  const char *pszValue; // esi

  if ( strLightingOriginRelative.pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: strLightingOriginRelative.pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      this->SetLightingOriginRelative(this, a2: EntityByName);
      this->m_iszLightingOriginRelative = strLightingOriginRelative;
    }
    else
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      DevWarning(a1: "%s: Could not find info_lighting_relative '%s'!\n", pszValue, strLightingOriginRelative.pszValue);
    }
  }
  else
  {
    this->SetLightingOriginRelative(this, a2: nullptr);
    this->m_iszLightingOriginRelative.pszValue = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100985E0
// Name: public: void CBaseAnimating::SetLightingOrigin(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetLightingOrigin(CBaseAnimating *this, string_t strLightingOrigin)
{
  CBaseEntity *EntityByName; // eax
  const char *pszValue; // esi

  if ( strLightingOrigin.pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: strLightingOrigin.pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      this->SetLightingOrigin(this, a2: EntityByName);
      this->m_iszLightingOrigin = strLightingOrigin;
    }
    else
    {
      pszValue = this->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      DevWarning(a1: "%s: Could not find lighting origin entity named '%s'!\n", pszValue, strLightingOrigin.pszValue);
    }
  }
  else
  {
    this->SetLightingOrigin(this, a2: nullptr);
    this->m_iszLightingOrigin.pszValue = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098670
// Name: private: void CBaseAnimating::InputSetLightingOriginRelative(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::InputSetLightingOriginRelative(CBaseAnimating *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  CBaseAnimating::SetLightingOriginRelative(this, strLightingOriginRelative: (string_t)iVal);
}

//------------------------------------------------------------------------------
// Address: 0x100986B0
// Name: private: void CBaseAnimating::InputSetLightingOrigin(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::InputSetLightingOrigin(CBaseAnimating *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
    {
LABEL_7:
      iVal = nullptr;
      goto LABEL_8;
    }
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  if ( iVal == nullptr || *iVal == 0 )
    goto LABEL_7;
LABEL_8:
  CBaseAnimating::SetLightingOrigin(this, strLightingOrigin: (string_t)iVal);
}

//------------------------------------------------------------------------------
// Address: 0x100986F0
// Name: public: virtual void CBaseAnimating::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::HandleAnimEvent(CBaseAnimating *this, animevent_t *pEvent)
{
  int type; // edx
  int event_lowword; // edi
  const char *v5; // eax
  const char *pszValue; // ecx
  const char *v7; // eax

  type = pEvent->type;
  if ( (type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( (pEvent->type & 0x400) == 0 )
    goto LABEL_11;
  if ( (type & 1) != 0 )
  {
    if ( event_lowword == 16 )
    {
      CBaseEntity::EmitSound(this, soundname: pEvent->options, soundtime: 0.0, duration: nullptr);
      return;
    }
    if ( event_lowword == 36 )
    {
      this->BecomeRagdollOnClient(this, a2: &vec3_origin);
      return;
    }
  }
  if ( (type & 1) != 0 )
  {
LABEL_11:
    if ( !pEvent->m_bHandledByScript )
    {
      v5 = EventList_NameForIndex(eventIndex: event_lowword);
      if ( v5 != nullptr )
      {
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        _DevWarning(a1: 1, a2: "Unhandled animation event %s for %s\n", v5, pszValue);
      }
      else
      {
        v7 = this->m_iClassname.pszValue;
        if ( v7 == nullptr )
          v7 = locale;
        _DevWarning(a1: 1, a2: "Unhandled animation event %d for %s\n", event_lowword, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100987C0
// Name: public: int CBaseAnimating::LookupPoseParameter(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::LookupPoseParameter(CBaseAnimating *this, CStudioHdr *pStudioHdr, const char *szName)
{
  int v4; // esi
  const mstudioposeparamdesc_t *v5; // eax

  if ( pStudioHdr == nullptr || !CStudioHdr::SequencesAvailable(this: pStudioHdr) )
    return 0;
  v4 = 0;
  if ( CStudioHdr::GetNumPoseParameters(this: pStudioHdr) <= 0 )
    return -1;
  while ( 1 )
  {
    v5 = CStudioHdr::pPoseParameter(this: pStudioHdr, i: v4);
    if ( _V_stricmp(s1: (const char *)v5 + v5->sznameindex, s2: szName) == 0 )
      break;
    if ( ++v4 >= CStudioHdr::GetNumPoseParameters(this: pStudioHdr) )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10098830
// Name: public: virtual bool CTraceFilterSkipNPCs::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterSkipNPCs::ShouldHitEntity(
        CTraceFilterSkipNPCs *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  const CBaseHandle *v3; // eax

  if ( !CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity: pServerEntity, contentsMask) )
    return false;
  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pServerEntity) )
    v3 = nullptr;
  else
    v3 = pServerEntity->__vftable[1].GetRefEHandle(this: pServerEntity);
  return (*(unsigned __int8 (__thiscall **)(const CBaseHandle *))(v3->m_Index + 292))(a1: v3) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10098890
// Name: public: virtual void CBaseAnimating::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::Teleport(
        CBaseAnimating *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        bool bUseSlowHighAccuracyContacts)
{
  CIKContext *m_pIk; // ecx
  unsigned int v7; // ecx
  double z; // st7

  CBaseEntity::Teleport(this, newPosition, newAngles, newVelocity, bUseSlowHighAccuracyContacts);
  m_pIk = this->m_pIk;
  if ( m_pIk != nullptr )
    CIKContext::ClearTargets(this: m_pIk);
  v7 = (unsigned int)this->m_iEFlags >> 11;
  this->m_flIKGroundContactTime = 0.0;
  this->m_flIKGroundMinHeight = 0.0;
  this->m_flIKGroundMaxHeight = 0.0;
  if ( (v7 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  z = this->m_vecAbsOrigin.z;
  this->m_flEstIkOffset = 0.0;
  this->m_flEstIkFloor = z;
}

//------------------------------------------------------------------------------
// Address: 0x10098910
// Name: public: bool CBaseAnimating::CanSkipAnimation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::CanSkipAnimation(CBaseAnimating *this)
{
  CAI_BaseNPC *v2; // eax

  return sv_pvsskipanimation.m_pParent != nullptr
      && sv_pvsskipanimation.m_pParent->m_Value.m_nValue != 0
      && (v2 = this->MyNPCPointer(this)) != nullptr
      && !CAI_BaseNPC::HasCondition(this: v2, iCondition: 1)
      && (this->m_fBoneCacheFlags & 3) == 0
      && !CBaseEntity::DoesHavePlayerChild(this);
}

//------------------------------------------------------------------------------
// Address: 0x10098960
// Name: private: void CBaseAnimating::LockStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::LockStudioHdr(CBaseAnimating *this)
{
  CThreadFastMutex *p_m_StudioHdrInitLock; // esi
  DWORD CurrentThreadId; // ecx
  const struct model_t *Model; // eax
  unsigned __int16 v5; // ax
  const studiohdr_t *v6; // edi
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr *v8; // eax
  CThreadFastMutex *generated_id_1; // [esp+Ch] [ebp-4h]

  p_m_StudioHdrInitLock = &this->m_StudioHdrInitLock;
  generated_id_1 = &this->m_StudioHdrInitLock;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_StudioHdrInitLock->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_StudioHdrInitLock, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_StudioHdrInitLock, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_StudioHdrInitLock->m_depth;
  }
  Model = CBaseEntity::GetModel(this);
  if ( Model != nullptr )
  {
    v5 = modelinfo->GetCacheHandle(this: modelinfo, a2: Model);
    if ( v5 != 0xFFFF )
    {
      v6 = mdlcache->LockStudioHdr(this: mdlcache, a2: v5);
      m_pStudioHdr = nullptr;
      if ( this->m_pStudioHdr != nullptr )
      {
        m_pStudioHdr = this->m_pStudioHdr;
      }
      else
      {
        if ( v6 == nullptr )
        {
LABEL_16:
          this->m_pStudioHdr = m_pStudioHdr;
          p_m_StudioHdrInitLock = generated_id_1;
          goto LABEL_17;
        }
        v8 = (CStudioHdr *)operator new(nSize: 0x64u);
        if ( v8 != nullptr )
        {
          m_pStudioHdr = CStudioHdr::CStudioHdr(this: v8);
          CStudioHdr::Init(this: m_pStudioHdr, pStudioHdr: v6, mdlcache: mdlcache);
        }
        else
        {
          m_pStudioHdr = nullptr;
          CStudioHdr::Init(this: nullptr, pStudioHdr: v6, mdlcache: mdlcache);
        }
      }
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pVModel != nullptr )
        ((void (__stdcall *)(_DWORD))mdlcache->LockStudioHdr)(a1: LOWORD(m_pStudioHdr->m_pStudioHdr->virtualModel));
      goto LABEL_16;
    }
  }
LABEL_17:
  if ( p_m_StudioHdrInitLock->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_StudioHdrInitLock, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10098A80
// Name: private: void CBaseAnimating::UnlockStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::UnlockStudioHdr(CBaseAnimating *this)
{
  const struct model_t *Model; // eax
  IMDLCache_vtbl *v3; // edi
  unsigned __int16 v4; // ax
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr != nullptr )
  {
    Model = CBaseEntity::GetModel(this);
    if ( Model != nullptr )
    {
      v3 = mdlcache->__vftable;
      v4 = modelinfo->GetCacheHandle(this: modelinfo, a2: Model);
      v3->UnlockStudioHdr(this: mdlcache, a2: v4);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr->m_pVModel != nullptr )
        mdlcache->UnlockStudioHdr(this: mdlcache, a2: (unsigned __int16)m_pStudioHdr->m_pStudioHdr->virtualModel);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098AF0
// Name: public: int CBaseAnimating::GetHitboxSet(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::GetHitboxSet(CBaseAnimating *this)
{
  return this->m_nHitboxSet.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10098B00
// Name: public: void CBaseAnimating::InputIgniteLifetime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::InputIgniteLifetime(CBaseAnimating *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    ((void (__stdcall *)(int))this->IgniteLifetime)(a1: inputdata->value.iVal);
  else
    ((void (__stdcall *)(_DWORD))this->IgniteLifetime)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10098BD0
// Name: public: static bool CMemberScriptBinding2<class CBaseAnimating __near *,void (CBaseAnimating::*)(int,int),void,int,int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding2<CBaseAnimating *,void (__thiscall CBaseAnimating::*)(int,int),void,int,int>::Call(
        void (__stdcall *pFunction)(int, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 2 || pReturn != nullptr || pContext == nullptr )
    return 0;
  pFunction(a1: pArguments->m_int, a2: pArguments[1].m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10098C00
// Name: public: class CBaseEntity __near * CBaseEntity::GetEffectEntity(void)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetEffectEntity(CBaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hEffectEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10098C30
// Name: public: void CBaseAnimating::NetworkVar_m_flPoseParameter::Set(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::NetworkVar_m_flPoseParameter::Set(
        CBaseAnimating::NetworkVar_m_flPoseParameter *this,
        int i,
        const float *val)
{
  char *v4; // eax
  CBaseEdict *v5; // ecx

  if ( LODWORD(this->m_Value[i]) != *(_DWORD *)val )
  {
    v4 = (char *)this - 948;
    if ( *((_BYTE *)this - 864) != 0 )
    {
      v4[88] |= 1u;
      this->m_Value[i] = *val;
    }
    else
    {
      v5 = *((CBaseEdict **)v4 + 6);
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: (_WORD)this + 4 * i - (_WORD)v4);
      this->m_Value[i] = *val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098C90
// Name: public: virtual bool CClassPtrSaveRestoreOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClassPtrSaveRestoreOps::IsEmpty(
        CClassPtrSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  int v2; // eax

  v2 = 0;
  if ( fieldInfo->pTypeDesc->fieldSize == 0 )
    return 1;
  while ( *((_DWORD *)fieldInfo->pField + v2) == 0 )
  {
    if ( ++v2 >= fieldInfo->pTypeDesc->fieldSize )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10098D90
// Name: public: virtual void CBaseAnimating::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetTransmit(CBaseAnimating *this, CCheckTransmitInfo *pInfo, BOOL bAlways)
{
  edict_t *m_pPev; // eax
  unsigned int m_Index; // ecx
  CBaseEntityList *v6; // edx
  int v7; // eax
  CEntInfo *v8; // esi
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v14; // ecx
  int v15; // eax
  CEntInfo *v16; // esi
  unsigned int v17; // ecx
  int v18; // eax
  CEntInfo *v19; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseEntity::SetTransmit(this, pInfo, bAlways);
    m_Index = this->m_hLightingOrigin.m_Value.m_Index;
    v6 = g_pEntityList;
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
        ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))m_pEntity->__vftable[7].SetRefEHandle)(
          a1: m_pEntity,
          a2: pInfo,
          a3: bAlways);
        v6 = g_pEntityList;
      }
    }
    v14 = this->m_hLightingOriginRelative.m_Value.m_Index;
    if ( v14 != -1 )
    {
      v15 = (unsigned __int16)v14;
      v16 = &v6->m_EntPtrArray[(unsigned __int16)v14];
      v17 = HIWORD(v14);
      if ( v16->m_SerialNumber == v17 && v16->m_pEntity != nullptr )
      {
        v18 = v15;
        v11 = v6->m_EntPtrArray[v18].m_SerialNumber == v17;
        v19 = &v6->m_EntPtrArray[v18];
        if ( v11 )
          ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))v19->m_pEntity->__vftable[7].SetRefEHandle)(
            a1: v19->m_pEntity,
            a2: pInfo,
            a3: bAlways);
        else
          (*(void (__stdcall **)(CCheckTransmitInfo *, BOOL))(MEMORY[0] + 88))(a1: pInfo, a2: bAlways);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098E90
// Name: public: virtual int CBaseAnimating::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::Restore(CBaseAnimating *this, IRestore *restore)
{
  int v3; // edi

  v3 = CBaseEntity::Restore(this, restore);
  CBaseAnimating::LockStudioHdr(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10098EC0
// Name: public: int CBaseAnimating::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::SelectWeightedSequence(CBaseAnimating *this, Activity activity)
{
  int m_Value; // edi
  CStudioHdr *m_pStudioHdr; // esi

  m_Value = this->m_nSequence.m_Value;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return SelectWeightedSequence(pstudiohdr: m_pStudioHdr, activity, curSequence: m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x10098F10
// Name: public: int CBaseAnimating::SelectWeightedSequence(enum Activity,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::SelectWeightedSequence(CBaseAnimating *this, Activity activity, int curSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return SelectWeightedSequence(pstudiohdr: m_pStudioHdr, activity, curSequence);
}

//------------------------------------------------------------------------------
// Address: 0x10098F60
// Name: public: void CBaseAnimating::ResetActivityIndexes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::ResetActivityIndexes(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  ResetActivityIndexes(pstudiohdr: m_pStudioHdr);
}

//------------------------------------------------------------------------------
// Address: 0x10098FA0
// Name: public: void CBaseAnimating::ResetEventIndexes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::ResetEventIndexes(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  ResetEventIndexes(pstudiohdr: m_pStudioHdr);
}

//------------------------------------------------------------------------------
// Address: 0x10098FE0
// Name: public: int CBaseAnimating::SelectHeaviestSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::SelectHeaviestSequence(CBaseAnimating *this, Activity activity)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return SelectHeaviestSequence(pstudiohdr: m_pStudioHdr, activity);
}

//------------------------------------------------------------------------------
// Address: 0x10099030
// Name: public: int CBaseAnimating::LookupActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::LookupActivity(CBaseAnimating *this, const char *label)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return LookupActivity(pstudiohdr: m_pStudioHdr, label);
}

//------------------------------------------------------------------------------
// Address: 0x10099080
// Name: public: int CBaseAnimating::LookupSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::LookupSequence(CBaseAnimating *this, const char *label)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return LookupSequence(pstudiohdr: m_pStudioHdr, label);
}

//------------------------------------------------------------------------------
// Address: 0x100990D0
// Name: public: class KeyValues __near * CBaseAnimating::GetSequenceKeyValues(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CBaseAnimating::GetSequenceKeyValues(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const char *KeyValueText; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IVModelInfo_vtbl *v7; // edi
  model_t *Model; // eax
  const char *v9; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  KeyValueText = Studio_GetKeyValueText(pStudioHdr: m_pStudioHdr, iSequence);
  if ( KeyValueText != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: locale);
    else
      v6 = nullptr;
    v7 = modelinfo->__vftable;
    Model = CBaseEntity::GetModel(this);
    v9 = v7->GetModelName(this: modelinfo, a2: Model);
    if ( KeyValues::LoadFromBuffer(
           this: v6,
           resourceName: v9,
           pBuffer: KeyValueText,
           pFileSystem: nullptr,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      return v6;
    }
    KeyValues::deleteThis(this: v6);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10099190
// Name: public: float CBaseAnimating::GetSequenceMoveYaw(int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CBaseAnimating::GetSequenceMoveYaw@<st0>(CBaseAnimating *this@<ecx>, float a2@<ebp>, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  Vector v6; // [esp-Ch] [ebp-1Ch] BYREF
  Vector vecReturn; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  vecReturn.y = a2;
  vecReturn.z = retaddr;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  GetSequenceLinearMotion(
    pstudiohdr: m_pStudioHdr,
    iSequence,
    poseParameter: this->m_flPoseParameter.m_Value,
    pVec: &v6);
  vecReturn.x = v6.x * v6.x;
  if ( fsqrt((float)((float)(v6.x * v6.x) + (float)(v6.y * v6.y)) + (float)(v6.z * v6.z)) <= 0.0 )
    return 99999.0;
  else
    return UTIL_VecToYaw(vec: &v6);
}

//------------------------------------------------------------------------------
// Address: 0x10099260
// Name: public: void CBaseAnimating::GetSequenceLinearMotion(int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::GetSequenceLinearMotion(CBaseAnimating *this, int iSequence, Vector *pVec)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  GetSequenceLinearMotion(pstudiohdr: m_pStudioHdr, iSequence, poseParameter: this->m_flPoseParameter.m_Value, pVec);
}

//------------------------------------------------------------------------------
// Address: 0x100992B0
// Name: public: char const __near * CBaseAnimating::GetSequenceName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAnimating::GetSequenceName(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( iSequence == -1 )
    return "Not Found!";
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return GetSequenceName(pstudiohdr: m_pStudioHdr, iSequence);
  else
    return "No model!";
}

//------------------------------------------------------------------------------
// Address: 0x10099310
// Name: public: char const __near * CBaseAnimating::GetSequenceActivityName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAnimating::GetSequenceActivityName(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( iSequence == -1 )
    return "Not Found!";
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return GetSequenceActivityName(pstudiohdr: m_pStudioHdr, iSequence);
  else
    return "No model!";
}

//------------------------------------------------------------------------------
// Address: 0x10099370
// Name: public: virtual bool CBaseAnimating::CanBecomeRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimating::CanBecomeRagdoll(CBaseAnimating *this)
{
  IMDLCache *v1; // edi
  int m_Value; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  bool v5; // zf
  void (__thiscall *EndLock)(IMDLCache *); // edx

  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  m_Value = this->m_nSequence.m_Value;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v5 = SelectWeightedSequence(pstudiohdr: m_pStudioHdr, activity: 24, curSequence: m_Value) == -1;
  EndLock = v1->EndLock;
  if ( v5 || (this->m_fFlags.m_Value & 0x40000000) != 0 )
  {
    ((void (__fastcall *)(IMDLCache *))EndLock)(a1: v1);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(IMDLCache *))EndLock)(a1: v1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100993F0
// Name: public: bool CBaseAnimating::IsValidSequence(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::IsValidSequence(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // ecx
  int v4; // eax
  bool result; // al

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  result = false;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr && iSequence >= 0 )
  {
    v4 = m_pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
       : m_pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( iSequence < v4 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100994F0
// Name: public: float CBaseAnimating::GetSequenceCycleRate(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetSequenceCycleRate(CBaseAnimating *this, CStudioHdr *pStudioHdr, int iSequence)
{
  double v3; // st7

  v3 = CBaseAnimating::SequenceDuration(this, pStudioHdr, iSequence);
  if ( v3 <= 0.0 )
    return 10.0;
  else
    return 1.0 / v3;
}

//------------------------------------------------------------------------------
// Address: 0x10099520
// Name: public: virtual float CBaseAnimating::GetSequenceGroundSpeed(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CBaseAnimating::GetSequenceGroundSpeed@<st0>(
        CBaseAnimating *this@<ecx>,
        int a2@<ebp>,
        CStudioHdr *pStudioHdr,
        int iSequence)
{
  double v5; // st7
  double v6; // st6
  double result; // st7
  Vector v8; // [esp-1Ch] [ebp-28h] BYREF
  float v9; // [esp-8h] [ebp-14h]
  int v10; // [esp+0h] [ebp-Ch]
  float t; // [esp+4h] [ebp-8h]
  float retaddr; // [esp+Ch] [ebp+0h]

  v10 = a2;
  t = retaddr;
  v5 = CBaseAnimating::SequenceDuration(this, pStudioHdr, iSequence);
  v9 = v5;
  v6 = v5;
  result = 0.0;
  if ( v6 > 0.0 )
  {
    GetSequenceLinearMotion(
      pstudiohdr: pStudioHdr,
      iSequence,
      poseParameter: this->m_flPoseParameter.m_Value,
      pVec: &v8);
    return fsqrt((float)((float)(v8.x * v8.x) + (float)(v8.y * v8.y)) + (float)(v8.z * v8.z)) / v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100995C0
// Name: public: bool CBaseAnimating::HasAnimEvent(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimating::HasAnimEvent(CBaseAnimating *this, int nSequence, int nEvent)
{
  CStudioHdr *m_pStudioHdr; // esi
  int AnimationEvent; // eax
  int event_lowword; // ecx
  animevent_t event; // [esp+14h] [ebp-1Ch] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  AnimationEvent = GetAnimationEvent(
                     pstudiohdr: m_pStudioHdr,
                     sequence: nSequence,
                     pNPCEvent: &event,
                     flStart: 0.0,
                     flEnd: 1.0,
                     index: 0);
  if ( AnimationEvent == 0 )
    return 0;
  while ( 1 )
  {
    event_lowword = event._event_lowword;
    if ( (event.type & 0x400) == 0 )
      event_lowword = *(_DWORD *)&event._event_highword;
    if ( event_lowword == nEvent )
      break;
    AnimationEvent = GetAnimationEvent(
                       pstudiohdr: m_pStudioHdr,
                       sequence: nSequence,
                       pNPCEvent: &event,
                       flStart: 0.0,
                       flEnd: 1.0,
                       index: AnimationEvent);
    if ( AnimationEvent == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10099690
// Name: public: float CBaseAnimating::SetPoseParameter(class CStudioHdr __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::SetPoseParameter(
        CBaseAnimating *this,
        CStudioHdr *pStudioHdr,
        int iParameter,
        float flValue)
{
  int v5; // esi

  if ( pStudioHdr != nullptr )
  {
    v5 = iParameter;
    if ( iParameter >= 0 )
    {
      flValue = Studio_SetPoseParameter(pStudioHdr, iParameter, flValue, ctlValue: (float *)&pStudioHdr);
      CBaseAnimating::NetworkVar_m_flPoseParameter::Set(
        this: &this->m_flPoseParameter,
        i: v5,
        val: (const float *)&pStudioHdr);
    }
  }
  return flValue;
}

//------------------------------------------------------------------------------
// Address: 0x100996E0
// Name: public: float CBaseAnimating::GetPoseParameter(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetPoseParameter(CBaseAnimating *this, int iParameter)
{
  CStudioHdr *m_pStudioHdr; // esi

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && CStudioHdr::SequencesAvailable(this: this->m_pStudioHdr)
    && iParameter >= 0 )
  {
    return Studio_GetPoseParameter(
             pStudioHdr: m_pStudioHdr,
             iParameter,
             ctlValue: this->m_flPoseParameter.m_Value[iParameter]);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099750
// Name: public: bool CBaseAnimating::GetPoseParameterRange(int,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimating::GetPoseParameterRange(
        CBaseAnimating *this,
        int index,
        float *minValue,
        float *maxValue)
{
  CStudioHdr *m_pStudioHdr; // esi
  const mstudioposeparamdesc_t *v6; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && index >= 0
    && index < CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr) )
  {
    v6 = CStudioHdr::pPoseParameter(this: m_pStudioHdr, i: index);
    *minValue = v6->start;
    *maxValue = v6->end;
    return 1;
  }
  else
  {
    *minValue = 0.0;
    *maxValue = 1.0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100997E0
// Name: public: bool CBaseAnimating::HasPoseParameter(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::HasPoseParameter(CBaseAnimating *this, int iSequence, int iParameter)
{
  CStudioHdr *m_pStudioHdr; // esi
  int v6; // eax
  mstudioseqdesc_t *v7; // ebx

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr
    || m_pStudioHdr->m_pStudioHdr == nullptr
    || !CStudioHdr::SequencesAvailable(this: m_pStudioHdr) )
  {
    return false;
  }
  if ( iSequence < 0 )
    return false;
  v6 = m_pStudioHdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
     : m_pStudioHdr->m_pStudioHdr->numlocalseq;
  if ( iSequence >= v6 )
    return false;
  v7 = CStudioHdr::pSeqdesc(this: m_pStudioHdr, iSequence);
  return CStudioHdr::GetSharedPoseParameter(this: m_pStudioHdr, iSequence, iLocalPose: v7->paramindex[0]) == iParameter
      || CStudioHdr::GetSharedPoseParameter(this: m_pStudioHdr, iSequence, iLocalPose: v7->paramindex[1]) == iParameter;
}

//------------------------------------------------------------------------------
// Address: 0x10099890
// Name: public: float CBaseAnimating::EdgeLimitPoseParameter(int,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::EdgeLimitPoseParameter(
        CBaseAnimating *this,
        int iParameter,
        float flValue,
        float flBase)
{
  CStudioHdr *m_pStudioHdr; // esi
  const mstudioposeparamdesc_t *v7; // ecx
  float flMin; // xmm0_4
  float flMax; // xmm1_4

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return flValue;
  if ( iParameter < 0 )
    return flValue;
  if ( iParameter >= CStudioHdr::GetNumPoseParameters(this: m_pStudioHdr) )
    return flValue;
  v7 = CStudioHdr::pPoseParameter(this: m_pStudioHdr, i: iParameter);
  if ( v7->loop != 0.0 )
    return flValue;
  flMin = v7->start;
  flMax = v7->end;
  if ( flMin == flMax )
    return flValue;
  return RangeCompressor(flValue, flMin, flMax, flBase);
}

//------------------------------------------------------------------------------
// Address: 0x10099950
// Name: public: int CBaseAnimating::LookupBone(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::LookupBone(CBaseAnimating *this, const char *szName)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return Studio_BoneIndexByName(pStudioHdr: m_pStudioHdr, pName: szName);
}

//------------------------------------------------------------------------------
// Address: 0x100999A0
// Name: public: void CBaseAnimating::GetBonePosition(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::GetBonePosition(CBaseAnimating *this, int iBone, Vector *origin, QAngle *angles)
{
  CStudioHdr *m_pStudioHdr; // eax
  matrix3x4_t bonetoworld; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && iBone >= 0
    && iBone < m_pStudioHdr->m_pStudioHdr->numbones )
  {
    this->GetBoneTransform(this, a2: iBone, a3: &bonetoworld);
    MatrixAngles(src: (const VMatrix *)&bonetoworld, vAngles: angles);
    origin->x = bonetoworld.m_flMatVal[0][3];
    origin->y = bonetoworld.m_flMatVal[1][3];
    origin->z = bonetoworld.m_flMatVal[2][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099A30
// Name: public: void CBaseAnimating::UpdateStepOrigin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::UpdateStepOrigin(CBaseAnimating *this)
{
  float v2; // xmm0_4
  float m_flIKGroundContactTime; // xmm0_4
  CBaseEntity *GroundEntity; // eax
  CAI_BaseNPC *v5; // eax
  float m_flIKGroundMinHeight; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  double v9; // st7
  double z; // st7
  float maxVal; // [esp+4h] [ebp-10h] BYREF
  float val; // [esp+8h] [ebp-Ch] BYREF
  int minVal; // [esp+Ch] [ebp-8h] BYREF
  float height; // [esp+10h] [ebp-4h] BYREF

  if ( npc_height_adjust.m_pParent == nullptr || npc_height_adjust.m_pParent->m_Value.m_nValue == 0 )
  {
    v2 = 0.0;
LABEL_15:
    z = this->m_vecOrigin.m_Value.z;
    this->m_flEstIkOffset = v2;
    this->m_flEstIkFloor = z;
    return;
  }
  m_flIKGroundContactTime = this->m_flIKGroundContactTime;
  if ( m_flIKGroundContactTime <= 0.2
    || m_flIKGroundContactTime <= gpGlobals->curtime - 0.2
    || (this->m_fFlags.m_Value & 0x1800) != 0
    || CBaseEntity::GetMoveParent(this) != nullptr
    || CBaseEntity::GetGroundEntity(this) == nullptr
    || (GroundEntity = CBaseEntity::GetGroundEntity(this), GroundEntity->IsMoving(this: GroundEntity))
    || (float)(CBaseEntity::GetAbsOrigin(this)->z - this->m_vecOrigin.m_Value.z) != 0.0 )
  {
    v2 = this->m_flEstIkOffset * 0.5;
    goto LABEL_15;
  }
  v5 = this->MyNPCPointer(this);
  height = 18.0;
  if ( v5 != nullptr )
    height = v5->StepHeight(this: v5);
  m_flIKGroundMinHeight = this->m_flIKGroundMinHeight;
  v7 = m_flIKGroundMinHeight * 0.8 + this->m_flEstIkFloor * 0.2;
  this->m_flEstIkFloor = v7;
  v8 = (float)(this->m_flIKGroundMaxHeight - m_flIKGroundMinHeight) - height;
  *(float *)&minVal = 0.0;
  val = v8;
  maxVal = 0.0;
  v9 = clamp<float,int,float>(&val, &minVal, maxVal: &height);
  val = v9 - height;
  *(float *)&minVal = this->m_flEstIkFloor - CBaseEntity::GetAbsOrigin(this)->z;
  this->m_flEstIkOffset = clamp<float,float,float>(val: (const float *)&minVal, minVal: &val, &maxVal);
}

//------------------------------------------------------------------------------
// Address: 0x10099C00
// Name: public: virtual class Vector CBaseAnimating::GetStepOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseAnimating::GetStepOrigin(CBaseAnimating *this, Vector *result)
{
  float z; // edx
  float m_flEstIkOffset; // xmm0_4

  z = this->m_vecOrigin.m_Value.z;
  *(_QWORD *)&result->x = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
  m_flEstIkOffset = this->m_flEstIkOffset;
  result->z = z;
  result->z = m_flEstIkOffset + result->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099C40
// Name: public: virtual class QAngle CBaseAnimating::GetStepAngles(void)const
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CBaseAnimating::GetStepAngles(CBaseAnimating *this, QAngle *result)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_angRotation.m_Value.x;
  z = this->m_angRotation.m_Value.z;
  *(_QWORD *)&result->x = v2;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099C60
// Name: public: void CBaseAnimating::BuildMatricesWithBoneMerge(class CStudioHdr const __near *,class QAngle const __near &,class Vector const __near &,class Vector const __near * const,class Quaternion const __near * const,struct matrix3x4_t __near * const,class CBaseAnimating __near *,class CBoneCache __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::BuildMatricesWithBoneMerge(
        CBaseAnimating *this,
        const CStudioHdr *pStudioHdr,
        const QAngle *angles,
        const Vector *origin,
        const Vector *pos,
        const Quaternion *q,
        matrix3x4_t *bonetoworld,
        CBaseAnimating *pParent,
        CBoneCache *pParentCache)
{
  int v9; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const char *v11; // esi
  matrix3x4_t *v12; // ebx
  int v13; // eax
  matrix3x4a_t *CachedBone; // eax
  int v15; // eax
  matrix3x4_t *p_rotationmatrix; // edx
  matrix3x4_t rotationmatrix; // [esp+Ch] [ebp-64h] BYREF
  matrix3x4_t bonematrix; // [esp+3Ch] [ebp-34h] BYREF
  CStudioHdr *fhdr; // [esp+6Ch] [ebp-4h]

  v9 = 0;
  if ( pParent->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: pParent) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pParent);
  m_pStudioHdr = pParent->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || (fhdr = pParent->m_pStudioHdr, m_pStudioHdr->m_pStudioHdr == nullptr) )
    fhdr = nullptr;
  v11 = (char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->boneindex;
  AngleMatrix(angles, position: origin, matrix: &rotationmatrix);
  if ( pStudioHdr->m_pStudioHdr->numbones > 0 )
  {
    v12 = bonetoworld;
    do
    {
      v13 = Studio_BoneIndexByName(pStudioHdr: fhdr, pName: &v11[*(_DWORD *)v11]);
      if ( v13 >= 0 && (CachedBone = CBoneCache::GetCachedBone(this: pParentCache, studioIndex: v13)) != nullptr )
      {
        MatrixCopy(in: CachedBone, out: v12);
      }
      else
      {
        QuaternionMatrix(q, pos, matrix: &bonematrix);
        v15 = *((_DWORD *)v11 + 1);
        if ( v15 == -1 )
          p_rotationmatrix = &rotationmatrix;
        else
          p_rotationmatrix = &bonetoworld[v15];
        ConcatTransforms(in1: p_rotationmatrix, in2: &bonematrix, out: v12);
      }
      ++pos;
      ++q;
      ++v9;
      ++v12;
      v11 += 216;
    }
    while ( v9 < pStudioHdr->m_pStudioHdr->numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099D80
// Name: public: int CBaseAnimating::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::LookupAttachment(CBaseAnimating *this, const char *szName)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return Studio_FindAttachment(pStudioHdr: m_pStudioHdr, pAttachmentName: szName) + 1;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10099DD0
// Name: public: bool CBaseAnimating::GetAttachment(char const __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::GetAttachment(
        CBaseAnimating *this,
        const char *szName,
        Vector *absOrigin,
        QAngle *absAngles)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v6; // eax
  bool v7; // bl
  _BYTE v9[12]; // [esp+8h] [ebp-30h] BYREF
  float v10; // [esp+14h] [ebp-24h]
  float v11; // [esp+24h] [ebp-14h]
  float v12; // [esp+34h] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    v6 = Studio_FindAttachment(pStudioHdr: m_pStudioHdr, pAttachmentName: szName) + 1;
  else
    v6 = 0;
  v7 = this->GetAttachment(this, a2: v6, a3: (matrix3x4_t *)v9);
  MatrixAngles(src: (const VMatrix *)v9, vAngles: absAngles);
  absOrigin->x = v10;
  absOrigin->y = v11;
  absOrigin->z = v12;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10099E70
// Name: public: virtual bool CBaseAnimating::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimating::GetAttachment(CBaseAnimating *this, int iAttachment, matrix3x4_t *attachmentToWorld)
{
  CStudioHdr *m_pStudioHdr; // edi
  int v6; // ebx
  int AttachmentBone; // eax
  matrix3x4_t bonetoworld; // [esp+8h] [ebp-48h] BYREF
  Vector vecWorldBonePos; // [esp+38h] [ebp-18h] BYREF
  Vector vecLocalBonePos; // [esp+44h] [ebp-Ch] BYREF
  const mstudioattachment_t *pattachment; // [esp+58h] [ebp+8h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    if ( iAttachment < 1 || iAttachment > CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      MatrixCopy(in: &this->m_rgflCoordinateFrame, out: attachmentToWorld);
      return 0;
    }
    else
    {
      v6 = iAttachment - 1;
      pattachment = CStudioHdr::pAttachment(this: m_pStudioHdr, i: iAttachment - 1);
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: v6);
      this->GetBoneTransform(this, a2: AttachmentBone, a3: &bonetoworld);
      if ( (pattachment->flags & 0x10000) != 0 )
      {
        MatrixGetColumn(in: &pattachment->local, column: 3, out: &vecLocalBonePos);
        VectorTransform(in1: &vecLocalBonePos.x, in2: &bonetoworld, out: &vecWorldBonePos.x);
        SetIdentityMatrix(matrix: attachmentToWorld);
        MatrixSetColumn(in: &vecWorldBonePos, column: 3, out: attachmentToWorld);
      }
      else
      {
        ConcatTransforms(in1: &bonetoworld, in2: &pattachment->local, out: attachmentToWorld);
      }
      return 1;
    }
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    MatrixCopy(in: &this->m_rgflCoordinateFrame, out: attachmentToWorld);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099FC0
// Name: public: int CBaseAnimating::GetAttachmentBone(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::GetAttachmentBone(CBaseAnimating *this, int iAttachment)
{
  CStudioHdr *m_pStudioHdr; // esi

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && iAttachment >= 1
    && iAttachment <= CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
  {
    return CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: iAttachment - 1);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A020
// Name: public: bool CBaseAnimating::GetAttachment(char const __near *,class Vector __near &,class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::GetAttachment(
        CBaseAnimating *this,
        const char *szName,
        Vector *absOrigin,
        Vector *forward,
        Vector *right,
        Vector *up)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v8; // eax
  bool v9; // bl
  matrix3x4_t in; // [esp+8h] [ebp-30h] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    v8 = Studio_FindAttachment(pStudioHdr: m_pStudioHdr, pAttachmentName: szName) + 1;
  else
    v8 = 0;
  v9 = this->GetAttachment(this, a2: v8, a3: &in);
  absOrigin->x = in.m_flMatVal[0][3];
  absOrigin->y = in.m_flMatVal[1][3];
  absOrigin->z = in.m_flMatVal[2][3];
  if ( forward != nullptr )
    MatrixGetColumn(&in, column: 0, out: forward);
  if ( right != nullptr )
    MatrixGetColumn(&in, column: 1, out: right);
  if ( up != nullptr )
    MatrixGetColumn(&in, column: 2, out: up);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1009A0F0
// Name: public: bool CBaseAnimating::GetAttachmentLocal(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::GetAttachmentLocal(
        CBaseAnimating *this,
        int iAttachment,
        Vector *origin,
        QAngle *angles)
{
  bool v5; // bl
  matrix3x4_t out; // [esp+8h] [ebp-90h] BYREF
  matrix3x4_t in2; // [esp+38h] [ebp-60h] BYREF
  matrix3x4_t attachmentToEntity; // [esp+68h] [ebp-30h] BYREF

  v5 = this->GetAttachment(this, a2: iAttachment, a3: &in2);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  MatrixInvert(in: &this->m_rgflCoordinateFrame, &out);
  ConcatTransforms(in1: &out, &in2, out: &attachmentToEntity);
  MatrixAngles(src: (const VMatrix *)&attachmentToEntity, vAngles: angles);
  origin->x = attachmentToEntity.m_flMatVal[0][3];
  origin->y = attachmentToEntity.m_flMatVal[1][3];
  origin->z = attachmentToEntity.m_flMatVal[2][3];
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1009A190
// Name: public: int CBaseAnimating::FindTransitionSequence(int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::FindTransitionSequence(
        CBaseAnimating *this,
        int iCurrentSequence,
        int iGoalSequence,
        int piDir)
{
  int *v4; // edi
  bool v6; // zf
  CStudioHdr *v7; // esi
  int result; // eax
  CStudioHdr *m_pStudioHdr; // esi

  v4 = (int *)piDir;
  if ( piDir != 0 )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    return FindTransitionSequence(pstudiohdr: m_pStudioHdr, iCurrentSequence, iGoalSequence, piDir: v4);
  }
  else
  {
    v6 = this->m_pStudioHdr == nullptr;
    piDir = 1;
    if ( v6 && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    v7 = this->m_pStudioHdr;
    if ( v7 == nullptr || v7->m_pStudioHdr == nullptr )
      v7 = nullptr;
    result = FindTransitionSequence(pstudiohdr: v7, iCurrentSequence, iGoalSequence, &piDir);
    if ( piDir != 1 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A240
// Name: public: bool CBaseAnimating::GotoSequence(int,float,float,int,int __near &,float __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::GotoSequence(
        CBaseAnimating *this,
        int iCurrentSequence,
        float flCurrentCycle,
        float flCurrentRate,
        int iGoalSequence,
        int *nNextSequence,
        float *flNextCycle,
        int *iNextDir)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return GotoSequence(
           pstudiohdr: m_pStudioHdr,
           iCurrentSequence,
           flCurrentCycle,
           flCurrentRate,
           iGoalSequence,
           nNextSequence,
           flNextCycle,
           iNextDir);
}

//------------------------------------------------------------------------------
// Address: 0x1009A2B0
// Name: public: int CBaseAnimating::ExtractBbox(int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::ExtractBbox(CBaseAnimating *this, int sequence, Vector *mins, Vector *maxs)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return ExtractBbox(pstudiohdr: m_pStudioHdr, sequence, mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x1009A300
// Name: public: void CBaseAnimating::SetSequenceBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetSequenceBox(CBaseAnimating *this)
{
  bool v2; // zf
  int m_Value; // esi
  CStudioHdr *m_pStudioHdr; // eax
  double v5; // xmm0_8
  double v6; // xmm0_8
  float v7; // xmm4_4
  float x; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *p_y; // esi
  int i; // edi
  float v15; // xmm0_4
  float *p_z; // ecx
  int j; // edx
  int k; // eax
  float v19; // xmm0_4
  long double v20; // [esp+0h] [ebp-68h]
  long double v21; // [esp+0h] [ebp-68h]
  Vector bounds[2]; // [esp+8h] [ebp-60h] BYREF
  Vector xvector; // [esp+20h] [ebp-48h]
  Vector maxs; // [esp+2Ch] [ebp-3Ch] BYREF
  Vector mins; // [esp+38h] [ebp-30h] BYREF
  Vector rmin; // [esp+44h] [ebp-24h] BYREF
  Vector rmax; // [esp+50h] [ebp-18h] BYREF
  CBaseEntity *pEnt; // [esp+5Ch] [ebp-Ch]
  int yaw; // [esp+60h] [ebp-8h]
  Vector *v30; // [esp+64h] [ebp-4h]

  v2 = this->m_pStudioHdr == nullptr;
  m_Value = this->m_nSequence.m_Value;
  pEnt = this;
  if ( v2 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  if ( ExtractBbox(pstudiohdr: m_pStudioHdr, sequence: m_Value, &mins, &maxs) != 0 )
  {
    *(float *)&yaw = this->m_angRotation.m_Value.y * 0.0174532925199433;
    v5 = *(float *)&yaw;
    __libm_sse2_cos(x: v20);
    *(float *)&v5 = v5;
    v30 = (Vector *)LODWORD(v5);
    xvector.x = *(float *)&v5;
    v6 = *(float *)&yaw;
    __libm_sse2_sin(x: v21);
    v7 = *(float *)&v30;
    x = xvector.x;
    *(float *)&v6 = v6;
    v9 = *(float *)&v6;
    LODWORD(v10) = LODWORD(v6) ^ _mask__NegFloat_;
    bounds[0] = mins;
    bounds[1] = maxs;
    rmin.x = 9999.0;
    rmin.y = 9999.0;
    rmin.z = 9999.0;
    rmax.x = -9999.0;
    rmax.y = -9999.0;
    rmax.z = -9999.0;
    *(float *)&v30 = COERCE_FLOAT(bounds);
    yaw = 2;
    do
    {
      v11 = v30->x * x;
      v12 = v30->x * v9;
      p_y = &bounds[0].y;
      for ( i = 2; i != 0; --i )
      {
        v15 = (float)(*p_y * v7) + v12;
        xvector.x = (float)(*p_y * v10) + v11;
        xvector.y = v15;
        p_z = &bounds[0].z;
        for ( j = 2; j != 0; --j )
        {
          xvector.z = *p_z;
          for ( k = 0; k < 12; k += 4 )
          {
            v19 = *(float *)((char *)&xvector.x + k);
            if ( *(float *)((char *)&rmin.x + k) > v19 )
              *(float *)((char *)&rmin.x + k) = v19;
            if ( v19 > *(float *)((char *)&rmax.x + k) )
              *(float *)((char *)&rmax.x + k) = v19;
          }
          p_z += 3;
        }
        p_y += 3;
      }
      ++v30;
      --yaw;
    }
    while ( *(float *)&yaw != 0.0 );
    rmin.z = 0.0;
    rmax.z = 1.0;
    UTIL_SetSize(pEnt, vecMin: &rmin, vecMax: &rmax);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A510
// Name: public: enum LocalFlexController_t CBaseAnimating::GetNumFlexControllers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::GetNumFlexControllers(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return m_pStudioHdr->m_pStudioHdr->numflexcontrollers;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A550
// Name: public: char const __near * CBaseAnimating::GetFlexControllerName(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAnimating::GetFlexControllerName(
        CBaseAnimating *this,
        LocalFlexController_t iFlexController)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return (char *)m_pStudioHdr->m_pStudioHdr
         + 20 * iFlexController
         + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex
         + *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->version
                  + 20 * iFlexController
                  + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009A5B0
// Name: public: char const __near * CBaseAnimating::GetFlexControllerType(enum LocalFlexController_t)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAnimating::GetFlexControllerType(
        CBaseAnimating *this,
        LocalFlexController_t iFlexController)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return (char *)m_pStudioHdr->m_pStudioHdr
         + 20 * iFlexController
         + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex
         + *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->id
                  + 20 * iFlexController
                  + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009A600
// Name: public: virtual class Vector CBaseAnimating::GetGroundSpeedVelocity(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseAnimating::GetGroundSpeedVelocity(CBaseAnimating *this, Vector *result)
{
  CStudioHdr *m_pStudioHdr; // eax
  float m_flGroundSpeed; // xmm0_4
  float v6; // xmm3_4
  QAngle vecAngles; // [esp+4h] [ebp-18h] BYREF
  Vector vecVelocity; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    vecAngles.y = CBaseAnimating::GetSequenceMoveYaw(
                    this,
                    a2: COERCE_FLOAT(&savedregs),
                    iSequence: this->m_nSequence.m_Value)
                + this->m_angRotation.m_Value.y;
    vecAngles.x = 0.0;
    vecAngles.z = 0.0;
    AngleVectors(angles: &vecAngles, forward: &vecVelocity);
    m_flGroundSpeed = this->m_flGroundSpeed;
    v6 = vecVelocity.z * m_flGroundSpeed;
    vecVelocity.x = vecVelocity.x * m_flGroundSpeed;
    vecVelocity.y = m_flGroundSpeed * vecVelocity.y;
    *(_QWORD *)&result->x = *(_QWORD *)&vecVelocity.x;
    result->z = v6;
    return result;
  }
  else
  {
    *result = vec3_origin;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A6D0
// Name: public: float CBaseAnimating::GetEntryVelocity(int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CBaseAnimating::GetEntryVelocity@<st0>(CBaseAnimating *this@<ecx>, int a2@<ebp>, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  Vector v6; // [esp+20h] [ebp-28h] BYREF
  int v7; // [esp+3Ch] [ebp-Ch]
  void *v8; // [esp+40h] [ebp-8h]
  void *retaddr; // [esp+48h] [ebp+0h]

  v7 = a2;
  v8 = retaddr;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0.0;
  Studio_SeqVelocity(
    pStudioHdr: m_pStudioHdr,
    iSequence,
    flCycle: 0.0,
    poseParameter: this->m_flPoseParameter.m_Value,
    vecVelocity: &v6);
  return fsqrt((float)((float)(v6.x * v6.x) + (float)(v6.y * v6.y)) + (float)(v6.z * v6.z));
}

//------------------------------------------------------------------------------
// Address: 0x1009A790
// Name: public: bool CBaseAnimating::GetSequenceMovement(int,float,float,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::GetSequenceMovement(
        CBaseAnimating *this,
        int nSequence,
        float fromCycle,
        float toCycle,
        Vector *deltaPosition,
        QAngle *deltaAngles)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  return m_pStudioHdr != nullptr
      && m_pStudioHdr->m_pStudioHdr != nullptr
      && Studio_SeqMovement(
           pStudioHdr: m_pStudioHdr,
           iSequence: nSequence,
           flCycleFrom: fromCycle,
           flCycleTo: toCycle,
           poseParameter: this->m_flPoseParameter.m_Value,
           deltaPos: deltaPosition,
           deltaAngles);
}

//------------------------------------------------------------------------------
// Address: 0x1009A800
// Name: public: float CBaseAnimating::GetMovementFrame(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetMovementFrame(CBaseAnimating *this, float flDist)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return Studio_FindSeqDistance(
             pStudioHdr: m_pStudioHdr,
             iSequence: this->m_nSequence.m_Value,
             poseParameter: this->m_flPoseParameter.m_Value,
             flDist);
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A860
// Name: public: bool CBaseAnimating::HasMovement(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::HasMovement(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  Vector deltaPos; // [esp+18h] [ebp-18h] BYREF
  QAngle deltaAngles; // [esp+24h] [ebp-Ch] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  return m_pStudioHdr != nullptr
      && m_pStudioHdr->m_pStudioHdr != nullptr
      && Studio_SeqMovement(
           pStudioHdr: m_pStudioHdr,
           iSequence,
           flCycleFrom: 0.0,
           flCycleTo: 1.0,
           poseParameter: this->m_flPoseParameter.m_Value,
           &deltaPos,
           &deltaAngles);
}

//------------------------------------------------------------------------------
// Address: 0x1009A8E0
// Name: public: class CBoneCache __near * CBaseAnimating::GetBoneCache(void)
// Source: json
//------------------------------------------------------------------------------
CBoneCache *__usercall CBaseAnimating::GetBoneCache@<eax>(CBaseAnimating *this@<ecx>, int a2@<ebp>)
{
  void *v2; // esp
  CStudioHdr *m_pStudioHdr; // eax
  bool v5; // zf
  CBoneCache *BoneCache; // eax
  CBoneCache *v7; // esi
  memhandle_t__ *v9; // eax
  matrix3x4a_t v10[256]; // [esp+1Ch] [ebp-302Ch] BYREF
  bonecacheparams_t v11; // [esp+3028h] [ebp-20h] BYREF
  CStudioHdr *v12; // [esp+3038h] [ebp-10h]
  int v13; // [esp+303Ch] [ebp-Ch]
  void *v14; // [esp+3040h] [ebp-8h]
  void *retaddr; // [esp+3048h] [ebp+0h]

  v13 = a2;
  v14 = retaddr;
  v2 = alloca(12328);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || (v5 = m_pStudioHdr->m_pStudioHdr == nullptr, v12 = this->m_pStudioHdr, v5) )
    v12 = nullptr;
  BoneCache = Studio_GetBoneCache(cacheHandle: this->m_boneCacheHandle, bLock: false);
  v7 = BoneCache;
  if ( BoneCache != nullptr )
  {
    if ( CBoneCache::IsValid(this: BoneCache, curtime: gpGlobals->curtime, dt: 0.1)
      && (v7->m_boneMask & 0x300) == 0x300
      && gpGlobals->curtime >= v7->m_timeValid )
    {
      return v7;
    }
    if ( (v7->m_boneMask & 0x300) != 0x300 )
    {
      Studio_DestroyBoneCache(cacheHandle: this->m_boneCacheHandle);
      v7 = nullptr;
      this->m_boneCacheHandle = nullptr;
    }
  }
  this->SetupBones(this, a2: v10, a3: 768);
  if ( v7 != nullptr )
  {
    CBoneCache::UpdateBones(
      this: v7,
      pBoneToWorld: v10,
      numbones: v12->m_pStudioHdr->numbones,
      curtime: gpGlobals->curtime);
    return v7;
  }
  v11.pStudioHdr = v12;
  v11.pBoneToWorld = v10;
  v11.curtime = gpGlobals->curtime;
  v11.boneMask = 768;
  v9 = Studio_CreateBoneCache(params: &v11);
  this->m_boneCacheHandle = v9;
  return Studio_GetBoneCache(cacheHandle: v9, bLock: false);
}

//------------------------------------------------------------------------------
// Address: 0x1009AA70
// Name: public: float CBaseAnimating::SetBoneController(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::SetBoneController(CBaseAnimating *this, int iController, float flValue)
{
  CStudioHdr *m_pStudioHdr; // eax
  double result; // st7
  float v6; // edx
  CBaseAnimating::NetworkVar_m_flEncodedController *p_m_flEncodedController; // esi
  char *v8; // eax
  CBaseEdict *v9; // ecx
  float newValue; // [esp+10h] [ebp-4h] BYREF
  float retVal; // [esp+20h] [ebp+Ch]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  result = Studio_SetController(pStudioHdr: m_pStudioHdr, iController, flValue, ctlValue: &newValue);
  v6 = this->m_flEncodedController.m_Value[iController];
  p_m_flEncodedController = &this->m_flEncodedController;
  if ( LODWORD(v6) != LODWORD(newValue) )
  {
    v8 = (char *)&p_m_flEncodedController[-66].m_Value[3];
    if ( LOBYTE(p_m_flEncodedController[-60].m_Value[0]) != 0 )
    {
      v8[88] |= 1u;
      p_m_flEncodedController->m_Value[iController] = newValue;
    }
    else
    {
      v9 = *((CBaseEdict **)v8 + 6);
      if ( v9 != nullptr )
      {
        CBaseEdict::StateChanged(this: v9, offset: 4 * iController + 1044);
        retVal = result;
        result = retVal;
      }
      p_m_flEncodedController->m_Value[iController] = newValue;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009AB30
// Name: public: virtual void CBaseAnimating::GetVelocity(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::GetVelocity(CBaseAnimating *this, Vector *vVelocity, Vector *vAngVelocity)
{
  float z; // ecx
  matrix3x4_t fRotateMatrix; // [esp+4h] [ebp-3Ch] BYREF
  QAngle tmp; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_MoveType.m_Value == 6 || (this->m_fFlags.m_Value & 1) == 0 )
  {
    CBaseEntity::GetVelocity(this, vVelocity, vAngVelocity);
  }
  else
  {
    if ( vVelocity != nullptr )
    {
      CBaseAnimating::GetSequenceLinearMotion(this, iSequence: this->m_nSequence.m_Value, pVec: (Vector *)&tmp);
      AngleMatrix(angles: &this->m_angRotation.m_Value, matrix: &fRotateMatrix);
      VectorRotate(in1: &tmp.x, in2: &fRotateMatrix, out: &vVelocity->x);
    }
    if ( vAngVelocity != nullptr )
    {
      z = this->m_vecAngVelocity.z;
      *(_QWORD *)&tmp.x = *(_QWORD *)&this->m_vecAngVelocity.x;
      vAngVelocity->x = z;
      *(_QWORD *)&vAngVelocity->y = *(_QWORD *)&tmp.x;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AC00
// Name: public: virtual int CBaseAnimating::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::DrawDebugTextOverlays(CBaseAnimating *this)
{
  int v2; // eax
  bool v3; // zf
  int v4; // edi
  int m_Value; // ebx
  const char *SequenceName; // eax
  int v7; // edi
  const char *SequenceActivityName; // eax
  CStudioHdr *m_pStudioHdr; // ebx
  int v10; // edi
  const mstudioattachment_t *v11; // eax
  char tempstr[1024]; // [esp+20h] [ebp-588h] BYREF
  char pDest[256]; // [esp+420h] [ebp-188h] BYREF
  matrix3x4_t in; // [esp+520h] [ebp-88h] BYREF
  Vector vecForward; // [esp+550h] [ebp-58h] BYREF
  Vector target; // [esp+55Ch] [ebp-4Ch] BYREF
  Vector vecRight; // [esp+568h] [ebp-40h] BYREF
  Vector v19; // [esp+574h] [ebp-34h] BYREF
  Vector vecUp; // [esp+580h] [ebp-28h] BYREF
  Vector v21; // [esp+58Ch] [ebp-1Ch] BYREF
  int text_offset; // [esp+598h] [ebp-10h]
  Vector vecPos; // [esp+59Ch] [ebp-Ch] BYREF

  v2 = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = (this->m_debugOverlays & 1) == 0;
  v4 = v2;
  text_offset = v2;
  if ( !v3 )
  {
    m_Value = this->m_nSequence.m_Value;
    SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: m_Value);
    V_snprintf(pDest: tempstr, maxLen: 1024, pFormat: "Sequence: (%3d) %s", m_Value, SequenceName);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 0, a: 255);
    v7 = v4 + 1;
    SequenceActivityName = CBaseAnimating::GetSequenceActivityName(this, iSequence: this->m_nSequence.m_Value);
    if ( SequenceActivityName != nullptr && strlen(SequenceActivityName) != 0 )
    {
      V_snprintf(pDest: tempstr, maxLen: 1024, pFormat: "Activity %s", SequenceActivityName);
      CBaseEntity::EntityText(this, text_offset: v7++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 0, a: 255);
    }
    V_snprintf(
      pDest: tempstr,
      maxLen: 1024,
      pFormat: "Cycle: %.5f (%.5f)",
      this->m_flCycle.m_Value,
      this->m_flAnimTime.m_Value);
    CBaseEntity::EntityText(this, text_offset: v7, text: tempstr, duration: 0.0, r: 255, g: 255, b: 0, a: 255);
    v4 = v7 + 1;
    text_offset = v4;
  }
  if ( (this->m_debugOverlays & 0x100) == 0 )
    return v4;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return v4;
  v10 = 1;
  if ( CStudioHdr::GetNumAttachments(this: this->m_pStudioHdr) >= 1 )
  {
    do
    {
      this->GetAttachment(this, a2: v10, a3: &in);
      vecPos.x = in.m_flMatVal[0][3];
      vecPos.y = in.m_flMatVal[1][3];
      vecPos.z = in.m_flMatVal[2][3];
      MatrixGetColumn(&in, column: 0, out: &vecForward);
      MatrixGetColumn(&in, column: 1, out: &vecRight);
      MatrixGetColumn(&in, column: 2, out: &vecUp);
      target.y = vecPos.y + (float)(vecForward.y * 4.0);
      target.z = vecPos.z + (float)(vecForward.z * 4.0);
      target.x = vecPos.x + (float)(vecForward.x * 4.0);
      NDebugOverlay::Line(origin: &vecPos, &target, r: 255, g: 0, b: 0, noDepthTest: true, duration: 0.050000001);
      v21.x = (float)(vecRight.x * 4.0) + vecPos.x;
      v21.y = (float)(vecRight.y * 4.0) + vecPos.y;
      v21.z = (float)(vecRight.z * 4.0) + vecPos.z;
      NDebugOverlay::Line(origin: &vecPos, target: &v21, r: 0, g: 255, b: 0, noDepthTest: true, duration: 0.050000001);
      v19.x = (float)(vecUp.x * 4.0) + vecPos.x;
      v19.y = (float)(vecUp.y * 4.0) + vecPos.y;
      v19.z = (float)(vecUp.z * 4.0) + vecPos.z;
      NDebugOverlay::Line(origin: &vecPos, target: &v19, r: 0, g: 0, b: 255, noDepthTest: true, duration: 0.050000001);
      v11 = CStudioHdr::pAttachment(this: m_pStudioHdr, i: v10 - 1);
      V_snprintf(pDest, maxLen: 256, pFormat: " < %s (%d)", (const char *)v11 + v11->sznameindex, v10);
      NDebugOverlay::Text(origin: &vecPos, text: pDest, bViewCheck: true, duration: 0.050000001);
      ++v10;
    }
    while ( v10 <= CStudioHdr::GetNumAttachments(this: m_pStudioHdr) );
  }
  return text_offset;
}

//------------------------------------------------------------------------------
// Address: 0x1009AFD0
// Name: public: void CBaseAnimating::DrawRawSkeleton(struct matrix3x4_t __near * const,int,bool,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::DrawRawSkeleton(
        CBaseAnimating *this,
        matrix3x4_t *boneToWorld,
        int boneMask,
        bool noDepthTest,
        float duration,
        bool monocolor)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v8; // eax
  int v9; // edi
  int v10; // esi
  float *v11; // ebx
  float *v12; // eax
  Vector p1; // [esp+10h] [ebp-1Ch] BYREF
  Vector p2; // [esp+1Ch] [ebp-10h] BYREF
  CStudioHdr *v15; // [esp+28h] [ebp-4h]
  int i; // [esp+44h] [ebp+18h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  v15 = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v8 = m_pStudioHdr->m_pStudioHdr;
    v9 = (unsigned __int8)-monocolor;
    i = 0;
    if ( v8->numbones > 0 )
    {
      v10 = 0;
      v11 = &boneToWorld->m_flMatVal[1][3];
      do
      {
        if ( (boneMask & *(int *)((_BYTE *)&v8->boneindex + v10 + v8->boneindex)) != 0 )
        {
          p1.x = *(v11 - 4);
          p1.y = *v11;
          p1.z = v11[4];
          if ( *(int *)((char *)&v8->version + v10 + v8->boneindex) != -1 )
          {
            v12 = (float *)&boneToWorld[*(int *)((char *)&v8->version + v10 + v8->boneindex)];
            p2.x = v12[3];
            p2.y = v12[7];
            p2.z = v12[11];
            NDebugOverlay::Line(origin: &p1, target: &p2, r: 255, g: 255, b: v9, noDepthTest, duration);
          }
        }
        v8 = v15->m_pStudioHdr;
        v11 += 12;
        v10 += 216;
        ++i;
      }
      while ( i < v15->m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B110
// Name: public: int CBaseAnimating::GetHitboxBone(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::GetHitboxBone(CBaseAnimating *this, int hitboxIndex)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v4; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && (v4 = (int)m_pStudioHdr->m_pStudioHdr
           + 12 * this->m_nHitboxSet.m_Value
           + m_pStudioHdr->m_pStudioHdr->hitboxsetindex) != 0
    && hitboxIndex < *(_DWORD *)(v4 + 4) )
  {
    return *(_DWORD *)(*(_DWORD *)(v4 + 8) + 68 * hitboxIndex + v4);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B180
// Name: public: int CBaseAnimating::GetPhysicsBone(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::GetPhysicsBone(CBaseAnimating *this, int boneIndex)
{
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v4; // ecx

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && boneIndex >= 0
    && (v4 = m_pStudioHdr->m_pStudioHdr, boneIndex < v4->numbones) )
  {
    return *(int *)((char *)&v4->numhitboxsets + 216 * boneIndex + v4->boneindex);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B1E0
// Name: public: int CBaseAnimating::GetHitboxesFrontside(int __near *,int,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::GetHitboxesFrontside(
        CBaseAnimating *this,
        int *boxList,
        int boxMax,
        const Vector *normal,
        float dist)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  int v10; // edx
  float *v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // eax
  matrix3x4_t matrix; // [esp+8h] [ebp-54h] BYREF
  Vector centerWs; // [esp+38h] [ebp-24h] BYREF
  Vector center; // [esp+44h] [ebp-18h] BYREF
  CBaseAnimating *v19; // [esp+50h] [ebp-Ch]
  int count; // [esp+54h] [ebp-8h]
  int v21; // [esp+58h] [ebp-4h]

  v19 = this;
  count = 0;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  v7 = (int)m_pStudioHdr->m_pStudioHdr + 12 * this->m_nHitboxSet.m_Value + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
  if ( v7 == 0 )
    return 0;
  v8 = 0;
  if ( *(int *)(v7 + 4) <= 0 )
    return 0;
  v21 = 0;
  do
  {
    v9 = v21 + *(_DWORD *)(v7 + 8);
    v10 = *(_DWORD *)(v9 + v7);
    v11 = (float *)(v7 + v9);
    v19->GetBoneTransform(this: v19, a2: v10, a3: &matrix);
    v12 = (float)(v11[3] + v11[6]) * 0.5;
    v13 = (float)(v11[4] + v11[7]) * 0.5;
    center.x = (float)(v11[5] + v11[2]) * 0.5;
    center.y = v12;
    center.z = v13;
    VectorTransform(in1: &center.x, in2: &matrix, out: &centerWs.x);
    if ( (float)((float)((float)(normal->y * centerWs.y) + (float)(normal->x * centerWs.x))
               + (float)(normal->z * centerWs.z)) >= dist )
    {
      v14 = count;
      if ( count < boxMax )
      {
        boxList[count] = v8;
        count = v14 + 1;
      }
    }
    v21 += 68;
    ++v8;
  }
  while ( v8 < *(_DWORD *)(v7 + 4) );
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x1009B340
// Name: public: enum Activity CBaseAnimating::GetSequenceActivity(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimating::GetSequenceActivity(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( iSequence == -1 )
    return -1;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    return GetSequenceActivity(pstudiohdr: m_pStudioHdr, sequence: iSequence, pweight: nullptr);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1009B3A0
// Name: public: float CBaseAnimating::GetModelHierarchyScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetModelHierarchyScale(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  if ( this->m_ScaleType.m_Value == HIERARCHICAL_MODEL_SCALE
    || m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr->numbones == 1 )
  {
    return this->m_flModelScale.m_Value;
  }
  else
  {
    return 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B420
// Name: public: virtual void CBaseAnimating::Ignite(float,bool,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::Ignite(
        CBaseAnimating *this,
        float flFlameLifetime,
        bool bNPCOnly,
        float flSize,
        bool bCalledByLevelDesigner)
{
  bool v6; // al
  CAI_BaseNPC *v7; // eax
  CEntityFlame *v8; // edi

  if ( (this->m_fFlags.m_Value & 0x10000000) == 0 )
  {
    v6 = this->IsNPC(this);
    if ( (!bNPCOnly || v6)
      && (!v6 || bCalledByLevelDesigner || (v7 = this->MyNPCPointer(this)) == nullptr || v7->AllowedToIgnite(this: v7)) )
    {
      v8 = CEntityFlame::Create(pTarget: this, flLifetime: flFlameLifetime, flSize, bUseHitboxes: true);
      CBaseEntity::AddFlag(this, flags: 0x10000000);
      CBaseEntity::SetEffectEntity(this, pEffectEnt: v8);
      COutputEvent::FireOutput(this: &this->m_OnIgnite, pActivator: this, pCaller: this, fDelay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B4D0
// Name: public: virtual void CBaseAnimating::IgniteLifetime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::IgniteLifetime(CBaseAnimating *this, float flFlameLifetime)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  CEntityFlame *v5; // eax

  if ( (this->m_fFlags.m_Value & 0x10000000) == 0 )
    ((void (__cdecl *)(int, _DWORD, _DWORD, int))this->Ignite)(a1: 1106247680, a2: 0, a3: 0, a4: 1);
  m_Index = this->m_hEffectEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = (CEntityFlame *)__RTDynamicCast(
                         inptr: m_pEntity,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CEntityFlame `RTTI Type Descriptor',
                         isReference: 0);
  if ( v5 != nullptr )
    CEntityFlame::SetLifetime(this: v5, lifetime: flFlameLifetime);
}

//------------------------------------------------------------------------------
// Address: 0x1009B570
// Name: public: virtual void CBaseAnimating::IgniteUseCheapEffect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::IgniteUseCheapEffect(CBaseAnimating *this, bool bUseCheapEffect)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  CEntityFlame *v5; // eax

  if ( (this->m_fFlags.m_Value & 0x10000000) == 0 )
    ((void (__cdecl *)(int, _DWORD, _DWORD, int))this->Ignite)(a1: 1106247680, a2: 0, a3: 0, a4: 1);
  m_Index = this->m_hEffectEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = (CEntityFlame *)__RTDynamicCast(
                         inptr: m_pEntity,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CEntityFlame `RTTI Type Descriptor',
                         isReference: 0);
  if ( v5 != nullptr )
    CEntityFlame::UseCheapEffect(this: v5, bCheap: bUseCheapEffect);
}

//------------------------------------------------------------------------------
// Address: 0x1009B600
// Name: public: float CBaseAnimating::GetSequenceCycleRate(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetSequenceCycleRate(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  double v4; // st7
  float iSequencea; // [esp+Ch] [ebp+8h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v4 = CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence);
  if ( v4 <= 0.0 )
    return 10.0;
  iSequencea = v4;
  return (float)(1.0 / iSequencea);
}

//------------------------------------------------------------------------------
// Address: 0x1009B680
// Name: private: virtual void CIKSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIKSaveRestoreOps::Save(CIKSaveRestoreOps *this, const SaveRestoreFieldInfo_t *fieldInfo, ISave *pSave)
{
  void (__thiscall *WriteBool_2)(ISave *, const bool *, int); // eax

  WriteBool_2 = pSave->WriteBool_2;
  HIBYTE(fieldInfo) = *(_DWORD *)fieldInfo->pField != 0;
  ((void (__stdcall *)(char *, int))WriteBool_2)(a1: (char *)&fieldInfo + 3, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009B6B0
// Name: private: virtual void CIKSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIKSaveRestoreOps::Restore(
        CIKSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  _DWORD *pField; // esi
  CIKContext *v4; // eax

  pField = fieldInfo->pField;
  pRestore->ReadBool(this: pRestore, a2: (bool *)&fieldInfo + 3, a3: 1, a4: 0);
  if ( HIBYTE(fieldInfo) != 0 && (v4 = (CIKContext *)operator new(nSize: 0x1070u)) != nullptr )
    *pField = CIKContext::CIKContext(this: v4);
  else
    *pField = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009B700
// Name: public: float CBaseAnimating::GetLastVisibleCycle(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetLastVisibleCycle(CBaseAnimating *this, CStudioHdr *pStudioHdr, int iSequence)
{
  const char *pszValue; // eax
  const studiohdr_t *m_pStudioHdr; // edi
  int v8; // eax
  mstudioseqdesc_t *v9; // edi
  float v10; // xmm0_4
  float iSequencea; // [esp+14h] [ebp+Ch]
  float iSequenceb; // [esp+14h] [ebp+Ch]

  if ( pStudioHdr != nullptr )
  {
    if ( (GetSequenceFlags(pstudiohdr: pStudioHdr, sequence: iSequence) & 1) != 0 )
    {
      return 1.0;
    }
    else
    {
      if ( pStudioHdr->m_pVModel != nullptr )
      {
        v9 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: iSequence);
      }
      else
      {
        m_pStudioHdr = pStudioHdr->m_pStudioHdr;
        v8 = iSequence;
        if ( iSequence < 0 || iSequence >= m_pStudioHdr->numlocalseq )
          v8 = 0;
        v9 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v8 + m_pStudioHdr->localseqindex);
      }
      v10 = 1.0 - this->m_flFrozen.m_Value;
      if ( v10 >= 0.0 )
      {
        if ( v10 <= 1.0 )
          iSequencea = 1.0 - this->m_flFrozen.m_Value;
        else
          iSequencea = 1.0;
      }
      else
      {
        iSequencea = 0.0;
      }
      iSequenceb = this->m_flPlaybackRate.m_Value * iSequencea;
      return 1.0 - CBaseAnimating::GetSequenceCycleRate(this, iSequence) * v9->fadeouttime * iSequenceb;
    }
  }
  else
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevWarning(a1: 2, a2: "CBaseAnimating::LastVisibleCycle( %d ) NULL pstudiohdr on %s!\n", iSequence, pszValue);
    return 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B7E0
// Name: public: virtual void CBaseAnimating::DispatchAnimEvents(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAnimating::DispatchAnimEvents(
        CBaseAnimating *this@<ecx>,
        animevent_t *p_event@<edi>,
        CBaseAnimating *eventHandler)
{
  float v4; // xmm0_4
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *v6; // ebx
  int m_Value; // eax
  const studiohdr_t *v8; // ecx
  mstudioseqdesc_t *v9; // eax
  double PlaybackRate; // st7
  bool v11; // zf
  float m_flLastEventCheck; // xmm1_4
  float v13; // xmm0_4
  int v14; // eax
  int AnimationEvent; // edi
  float v16; // xmm1_4
  double AnimTimeInterval; // st7
  CStudioHdr *v18; // eax
  const char *DebugName; // eax
  int v20; // [esp+14h] [ebp-40h]
  animevent_t event; // [esp+24h] [ebp-30h] BYREF
  float flStart; // [esp+40h] [ebp-14h]
  float v24; // [esp+44h] [ebp-10h]
  float flEnd; // [esp+48h] [ebp-Ch]
  float flCycleRate; // [esp+4Ch] [ebp-8h]
  float flCycle; // [esp+50h] [ebp-4h]

  v4 = 1.0 - this->m_flFrozen.m_Value;
  if ( v4 >= 0.0 )
  {
    if ( v4 > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  if ( (float)(this->m_flPlaybackRate.m_Value * v4) != 0.0 )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v6 = this->m_pStudioHdr;
      if ( CStudioHdr::SequencesAvailable(this: m_pStudioHdr) )
      {
        m_Value = this->m_nSequence.m_Value;
        if ( v6->m_pVModel != nullptr )
        {
          v9 = CStudioHdr::pSeqdesc_Internal(this: v6, i: this->m_nSequence.m_Value);
        }
        else
        {
          v8 = v6->m_pStudioHdr;
          if ( m_Value < 0 || m_Value >= v8->numlocalseq )
            m_Value = 0;
          v9 = (mstudioseqdesc_t *)((char *)v8 + 212 * m_Value + v8->localseqindex);
        }
        if ( v9->numevents != 0 )
        {
          flEnd = CBaseAnimating::GetSequenceCycleRate(this, iSequence: this->m_nSequence.m_Value);
          PlaybackRate = CBaseAnimating::GetPlaybackRate(this);
          v11 = !this->m_bSequenceLoops;
          m_flLastEventCheck = this->m_flLastEventCheck;
          v13 = this->m_flCycle.m_Value;
          flCycleRate = PlaybackRate * flEnd;
          flStart = m_flLastEventCheck;
          flEnd = v13;
          if ( v11 && this->m_bSequenceFinished )
          {
            v13 = 1.01;
            flEnd = 1.01;
          }
          v14 = this->m_nSequence.m_Value;
          this->m_flLastEventCheck = v13;
          AnimationEvent = GetAnimationEvent(
                             pstudiohdr: v6,
                             sequence: v14,
                             pNPCEvent: &event,
                             flStart: m_flLastEventCheck,
                             flEnd: v13,
                             index: 0);
          if ( AnimationEvent != 0 )
          {
            while ( 1 )
            {
              event.pSource = this;
              if ( flCycleRate > 0.0 )
              {
                v16 = this->m_flCycle.m_Value;
                flCycle = event.cycle;
                v24 = v16;
                if ( event.cycle > v16 )
                  flCycle = event.cycle - 1.0;
                AnimTimeInterval = CBaseAnimating::GetAnimTimeInterval(this);
                event.eventtime = AnimTimeInterval + (flCycle - v24) / flCycleRate + this->m_flAnimTime.m_Value;
              }
              event.m_bHandledByScript = ((int (__thiscall *)(CBaseAnimating *, animevent_t *, animevent_t *))eventHandler->HandleScriptedAnimEvent)(
                                           a1: eventHandler,
                                           a2: &event,
                                           a3: p_event);
              if ( eventHandler->HandleBehaviorAnimEvent(this: eventHandler, a2: &event) )
                event.m_bHandledByScript = true;
              p_event = &event;
              ((void (__thiscall *)(CBaseAnimating *))eventHandler->HandleAnimEvent)(a1: eventHandler);
              v18 = this->m_pStudioHdr;
              if ( v18 == nullptr )
              {
                if ( CBaseEntity::GetModel(this) != nullptr )
                  CBaseAnimating::LockStudioHdr(this);
                v18 = this->m_pStudioHdr;
                if ( v18 == nullptr )
                  goto LABEL_34;
              }
              if ( v18->m_pStudioHdr == nullptr )
LABEL_34:
                v18 = nullptr;
              if ( v18 != v6 )
                break;
              AnimationEvent = GetAnimationEvent(
                                 pstudiohdr: v6,
                                 sequence: this->m_nSequence.m_Value,
                                 pNPCEvent: &event,
                                 flStart,
                                 flEnd,
                                 index: AnimationEvent);
              if ( AnimationEvent == 0 )
                return;
            }
            v20 = this->m_nSequence.m_Value;
            DebugName = CBaseEntity::GetDebugName(this);
            _Warning(
              a1: "%s has changed its model while processing AnimEvents on sequence %d. Aborting dispatch.\n",
              DebugName,
              v20);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BA70
// Name: public: virtual void CBaseAnimating::GetBoneTransform(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::GetBoneTransform(CBaseAnimating *this, int iBone, matrix3x4_t *pBoneToWorld)
{
  CStudioHdr *m_pStudioHdr; // eax
  CBoneCache *BoneCache; // eax
  matrix3x4a_t *CachedBone; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && iBone >= 0
    && iBone < m_pStudioHdr->m_pStudioHdr->numbones )
  {
    BoneCache = CBaseAnimating::GetBoneCache(this, a2: (int)&savedregs);
    CachedBone = CBoneCache::GetCachedBone(this: BoneCache, studioIndex: iBone);
    if ( CachedBone != nullptr )
    {
      MatrixCopy(in: CachedBone, out: pBoneToWorld);
    }
    else
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      MatrixCopy(in: &this->m_rgflCoordinateFrame, out: pBoneToWorld);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BB10
// Name: public: float CBaseAnimating::GetInstantaneousVelocity(float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CBaseAnimating::GetInstantaneousVelocity@<st0>(
        CBaseAnimating *this@<ecx>,
        int a2@<ebp>,
        float flInterval)
{
  CStudioHdr *m_pStudioHdr; // edi
  int m_Value; // eax
  float v7; // xmm0_4
  double SequenceCycleRate; // st7
  int v9; // edx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  Vector v13; // [esp+20h] [ebp-28h] BYREF
  Vector vecVelocity; // [esp+2Ch] [ebp-1Ch]
  float v15; // [esp+38h] [ebp-10h]
  int v16; // [esp+3Ch] [ebp-Ch]
  float flNextCycle; // [esp+40h] [ebp-8h]
  float retaddr; // [esp+48h] [ebp+0h]

  v16 = a2;
  flNextCycle = retaddr;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0.0;
  m_Value = this->m_nSequence.m_Value;
  vecVelocity.z = this->m_flCycle.m_Value;
  v7 = 1.0 - this->m_flFrozen.m_Value;
  if ( v7 >= 0.0 )
  {
    if ( v7 <= 1.0 )
      v15 = 1.0 - this->m_flFrozen.m_Value;
    else
      v15 = 1.0;
  }
  else
  {
    v15 = 0.0;
  }
  v15 = this->m_flPlaybackRate.m_Value * v15;
  SequenceCycleRate = CBaseAnimating::GetSequenceCycleRate(this, iSequence: m_Value);
  v9 = this->m_nSequence.m_Value;
  vecVelocity.z = SequenceCycleRate * flInterval * v15 + vecVelocity.z;
  Studio_SeqVelocity(
    pStudioHdr: m_pStudioHdr,
    iSequence: v9,
    flCycle: vecVelocity.z,
    poseParameter: this->m_flPoseParameter.m_Value,
    vecVelocity: &v13);
  v10 = 1.0;
  v11 = 1.0 - this->m_flFrozen.m_Value;
  if ( v11 >= 0.0 )
  {
    if ( v11 <= 1.0 )
      v10 = 1.0 - this->m_flFrozen.m_Value;
  }
  else
  {
    v10 = 0.0;
  }
  v12 = this->m_flPlaybackRate.m_Value * v10;
  return fsqrt(
           (float)((float)((float)(v12 * v13.y) * (float)(v12 * v13.y))
                 + (float)((float)(v13.z * v12) * (float)(v13.z * v12)))
         + (float)((float)(v13.x * v12) * (float)(v13.x * v12)));
}

//------------------------------------------------------------------------------
// Address: 0x1009BC80
// Name: public: bool CBaseAnimating::GetIntervalMovement(float,bool __near &,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimating::GetIntervalMovement(
        CBaseAnimating *this,
        float flIntervalUsed,
        bool *bMoveSeqFinished,
        Vector *newPosition,
        QAngle *newAngles)
{
  CStudioHdr *m_pStudioHdr; // edi
  float v7; // xmm1_4
  float v8; // xmm0_4
  float flCycleTo; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  QAngle deltaAngles; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector deltaPos; // [esp+28h] [ebp-10h] BYREF
  float flComputedCycleRate; // [esp+34h] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && CStudioHdr::SequencesAvailable(this: this->m_pStudioHdr) )
  {
    flComputedCycleRate = CBaseAnimating::GetSequenceCycleRate(this, iSequence: this->m_nSequence.m_Value);
    v7 = 0.0;
    v8 = 1.0 - this->m_flFrozen.m_Value;
    if ( v8 >= 0.0 )
    {
      if ( v8 <= 1.0 )
        v7 = 1.0 - this->m_flFrozen.m_Value;
      else
        v7 = 1.0;
    }
    flCycleTo = (float)((float)(this->m_flPlaybackRate.m_Value * v7) * (float)(flComputedCycleRate * flIntervalUsed))
              + this->m_flCycle.m_Value;
    if ( this->m_bSequenceLoops || flCycleTo <= 1.0 )
    {
      *bMoveSeqFinished = false;
    }
    else
    {
      flCycleTo = 1.0;
      *bMoveSeqFinished = true;
    }
    if ( Studio_SeqMovement(
           pStudioHdr: m_pStudioHdr,
           iSequence: this->m_nSequence.m_Value,
           flCycleFrom: this->m_flCycle.m_Value,
           flCycleTo,
           poseParameter: this->m_flPoseParameter.m_Value,
           &deltaPos,
           &deltaAngles) )
    {
      VectorYawRotate(in: &deltaPos, flYaw: this->m_angRotation.m_Value.y, out: &deltaPos);
      v10 = this->m_vecOrigin.m_Value.y + deltaPos.y;
      v11 = this->m_vecOrigin.m_Value.z + deltaPos.z;
      newPosition->x = this->m_vecOrigin.m_Value.x + deltaPos.x;
      newPosition->y = v10;
      newPosition->z = v11;
      newAngles->y = 0.0;
      newAngles->x = 0.0;
      newAngles->z = 0.0;
      newAngles->y = this->m_angRotation.m_Value.y + deltaAngles.y;
      return 1;
    }
    *newPosition = this->m_vecOrigin.m_Value;
    *newAngles = this->m_angRotation.m_Value;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009BE50
// Name: public: virtual bool CBaseAnimating::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::TestCollision(
        CBaseAnimating *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  const struct CPhysCollide *v6; // eax
  CGameTrace *v7; // esi
  Vector vecPosition; // [esp+8h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+14h] [ebp-Ch] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( CBaseAnimating::GetModelHierarchyScale(this) == 1.0 || m_pPhysicsObject == nullptr )
  {
    if ( (this->m_Collision.m_usSolidFlags.m_Value & 1) == 0 )
      return false;
    v7 = tr;
    if ( !this->TestHitboxes(this, a2: ray, a3: fContentsMask, a4: tr) )
      return true;
  }
  else
  {
    m_pPhysicsObject->GetPosition(this: m_pPhysicsObject, a2: &vecPosition, a3: &vecAngles);
    v6 = m_pPhysicsObject->GetCollide(this: m_pPhysicsObject);
    v7 = tr;
    physcollision->TraceBox_2(this: physcollision, a2: ray, a3: v6, a4: &vecPosition, a5: &vecAngles, a6: tr);
  }
  return v7->fraction < 1.0 || v7->allsolid || v7->startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x1009BF20
// Name: public: virtual bool CBaseAnimating::TestHitboxes(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimating::TestHitboxes(
        CBaseAnimating *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  CStudioHdr *m_pStudioHdr; // ebx
  mstudiohitboxset_t *v7; // esi
  CBoneCache *BoneCache; // eax
  CStudioHdr *v9; // edi
  const studiohdr_t *v10; // ecx
  int v11; // eax
  Vector *p_m_vecAbsOrigin; // [esp-4h] [ebp-41Ch]
  float flScale; // [esp+0h] [ebp-418h]
  matrix3x4_t *hitboxbones[256]; // [esp+14h] [ebp-404h] BYREF
  CStudioHdr *pStudioHdr; // [esp+414h] [ebp-4h]
  int savedregs; // [esp+418h] [ebp+0h] BYREF

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  pStudioHdr = m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  v7 = (mstudiohitboxset_t *)((char *)m_pStudioHdr->m_pStudioHdr
                            + 12 * this->m_nHitboxSet.m_Value
                            + m_pStudioHdr->m_pStudioHdr->hitboxsetindex);
  if ( v7 == nullptr || v7->numhitboxes == 0 )
    return 0;
  BoneCache = CBaseAnimating::GetBoneCache(this, a2: (int)&savedregs);
  CBoneCache::ReadCachedBonePointers(
    this: BoneCache,
    bones: hitboxbones,
    numbones: m_pStudioHdr->m_pStudioHdr->numbones);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  flScale = CBaseAnimating::GetModelHierarchyScale(this);
  p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
  v9 = pStudioHdr;
  if ( TraceToStudio(
         pProps: physprops,
         ray,
         pStudioHdr,
         set: v7,
         hitboxbones,
         fContentsMask,
         vecOrigin: p_m_vecAbsOrigin,
         flScale,
         tr) )
  {
    v10 = v9->m_pStudioHdr;
    v11 = v9->m_pStudioHdr->boneindex + 216 * *(int *)((char *)&v7->sznameindex + 68 * tr->hitbox + v7->hitboxindex);
    tr->surface.name = "**studio**";
    tr->surface.flags = 0x8000;
    tr->surface.surfaceProps = *(_WORD *)((char *)&v10->localanimindex + v11);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009C050
// Name: public: virtual void CBaseAnimating::InitBoneControllers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::InitBoneControllers(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  int numbonecontrollers; // edi
  int v4; // esi
  int i; // esi
  CStudioHdr *v6; // eax
  edict_t *m_pPev; // ecx
  float ctlValue; // [esp+14h] [ebp-8h] BYREF
  CStudioHdr *pStudioHdr; // [esp+18h] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    numbonecontrollers = m_pStudioHdr->m_pStudioHdr->numbonecontrollers;
    pStudioHdr = this->m_pStudioHdr;
    if ( numbonecontrollers > 4 )
      numbonecontrollers = 4;
    v4 = 0;
    if ( numbonecontrollers > 0 )
    {
      do
        CBaseAnimating::SetBoneController(this, iController: v4++, flValue: 0.0);
      while ( v4 < numbonecontrollers );
      m_pStudioHdr = pStudioHdr;
    }
    if ( CStudioHdr::SequencesAvailable(this: m_pStudioHdr) )
    {
      for ( i = 0; i < CStudioHdr::GetNumPoseParameters(this: pStudioHdr); ++i )
      {
        v6 = this->m_pStudioHdr;
        if ( v6 == nullptr )
        {
          if ( CBaseEntity::GetModel(this) != nullptr )
            CBaseAnimating::LockStudioHdr(this);
          v6 = this->m_pStudioHdr;
          if ( v6 == nullptr )
            continue;
        }
        if ( v6->m_pStudioHdr != nullptr && i >= 0 )
        {
          Studio_SetPoseParameter(pStudioHdr: v6, iParameter: i, flValue: 0.0, &ctlValue);
          if ( LODWORD(this->m_flPoseParameter.m_Value[i]) != LODWORD(ctlValue) )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 4 * i + 948);
            }
            this->m_flPoseParameter.m_Value[i] = ctlValue;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C190
// Name: public: void CBaseAnimating::DrawServerHitboxes(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::DrawServerHitboxes(CBaseAnimating *this, float duration, bool monocolor)
{
  IMDLCache *m_pCache; // esi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // ecx
  int v8; // eax
  bool v9; // zf
  mstudiohitboxset_t *v10; // eax
  int v11; // esi
  int v12; // ebx
  char *v13; // esi
  CStudioHdr *v14; // eax
  int v15; // eax
  int v16; // ecx
  float z; // xmm1_4
  CStudioHdr *v18; // eax
  CStudioHdr *v19; // ecx
  float m_Value; // xmm0_4
  float v21; // xmm0_4
  VMatrix src; // [esp+18h] [ebp-7Ch] BYREF
  float v23; // [esp+58h] [ebp-3Ch]
  float v24; // [esp+5Ch] [ebp-38h]
  Vector mins; // [esp+60h] [ebp-34h] BYREF
  Vector maxs; // [esp+6Ch] [ebp-28h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+78h] [ebp-1Ch]
  mstudiohitboxset_t *set; // [esp+7Ch] [ebp-18h]
  int i; // [esp+80h] [ebp-14h]
  int r; // [esp+84h] [ebp-10h]
  int g; // [esp+88h] [ebp-Ch]
  int b; // [esp+8Ch] [ebp-8h]
  int v33; // [esp+90h] [ebp-4h]

  m_pCache = mdlcache;
  BeginLock = mdlcache->BeginLock;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && (v7 = m_pStudioHdr->m_pStudioHdr,
        v8 = m_pStudioHdr->m_pStudioHdr->hitboxsetindex + 12 * this->m_nHitboxSet.m_Value,
        v9 = (const studiohdr_t *)((char *)v7 + v8) == nullptr,
        v10 = (mstudiohitboxset_t *)((char *)v7 + v8),
        set = v10,
        !v9) )
  {
    r = 0;
    g = 0;
    b = 255;
    i = 0;
    if ( v10->numhitboxes > 0 )
    {
      v33 = 0;
      while ( 1 )
      {
        v11 = v33 + v10->hitboxindex;
        v12 = *(int *)((char *)&v10->sznameindex + v11);
        v13 = (char *)v10 + v11;
        v14 = this->m_pStudioHdr;
        if ( v14 != nullptr )
          goto LABEL_17;
        if ( CBaseEntity::GetModel(this) != nullptr )
          CBaseAnimating::LockStudioHdr(this);
        v14 = this->m_pStudioHdr;
        if ( v14 != nullptr )
        {
LABEL_17:
          if ( v14->m_pStudioHdr != nullptr && v12 >= 0 && v12 < v14->m_pStudioHdr->numbones )
          {
            this->GetBoneTransform(this, a2: v12, a3: (matrix3x4_t *)&src);
            MatrixAngles(&src, vAngles: (QAngle *)src.m[3]);
            src.m[3][3] = src.m[0][3];
            v23 = src.m[1][3];
            v24 = src.m[2][3];
          }
        }
        if ( !monocolor )
        {
          v15 = *((_DWORD *)v13 + 1) % 8;
          v16 = (int)(float)(hullcolor[v15].y * 255.0);
          z = hullcolor[v15].z;
          r = (int)(float)(hullcolor[v15].x * 255.0);
          g = v16;
          b = (int)(float)(z * 255.0);
        }
        v18 = this->m_pStudioHdr;
        if ( v18 == nullptr )
        {
          if ( CBaseEntity::GetModel(this) != nullptr )
            CBaseAnimating::LockStudioHdr(this);
          v18 = this->m_pStudioHdr;
          if ( v18 == nullptr )
            goto LABEL_27;
        }
        if ( v18->m_pStudioHdr != nullptr )
          v19 = v18;
        else
LABEL_27:
          v19 = nullptr;
        if ( this->m_ScaleType.m_Value == HIERARCHICAL_MODEL_SCALE || v19 != nullptr && v19->m_pStudioHdr->numbones == 1 )
          m_Value = this->m_flModelScale.m_Value;
        else
          m_Value = 1.0;
        maxs.x = *((float *)v13 + 5) * m_Value;
        maxs.y = *((float *)v13 + 6) * m_Value;
        maxs.z = *((float *)v13 + 7) * m_Value;
        if ( v18 == nullptr )
        {
          if ( CBaseEntity::GetModel(this) != nullptr )
            CBaseAnimating::LockStudioHdr(this);
          v18 = this->m_pStudioHdr;
          if ( v18 == nullptr )
            goto LABEL_38;
        }
        if ( v18->m_pStudioHdr == nullptr )
LABEL_38:
          v18 = nullptr;
        v21 = this->m_ScaleType.m_Value == HIERARCHICAL_MODEL_SCALE
           || v18 != nullptr && v18->m_pStudioHdr->numbones == 1
            ? this->m_flModelScale.m_Value
            : 1.0;
        mins.x = *((float *)v13 + 2) * v21;
        mins.y = *((float *)v13 + 3) * v21;
        mins.z = *((float *)v13 + 4) * v21;
        NDebugOverlay::BoxAngles(
          origin: (const Vector *)&src.m[3][3],
          &mins,
          &maxs,
          angles: (const QAngle *)src.m[3],
          r,
          g,
          b,
          a: 0,
          duration);
        v33 += 68;
        if ( ++i >= set->numhitboxes )
          break;
        v10 = set;
      }
      m_pCache = cacheCriticalSection.m_pCache;
    }
    m_pCache->EndLock(this: m_pCache);
  }
  else
  {
    m_pCache->EndLock(this: m_pCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C470
// Name: public: bool CBaseAnimating::ComputeHitboxSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimating::ComputeHitboxSurroundingBox(
        CBaseAnimating *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v6; // edi
  int v7; // esi
  int v8; // eax
  float *v9; // esi
  matrix3x4a_t *CachedBone; // ebx
  double ModelHierarchyScale; // st7
  double v12; // st7
  double x; // xmm0_8
  float y; // xmm1_4
  float v15; // xmm0_4
  double v16; // xmm0_8
  double v17; // xmm1_8
  float z; // xmm1_4
  float v19; // xmm0_4
  double v20; // xmm0_8
  double v21; // xmm1_8
  float v22; // xmm1_4
  float v23; // xmm0_4
  double v24; // xmm0_8
  double v25; // xmm1_8
  float v26; // xmm1_4
  float v27; // xmm0_4
  double v28; // xmm0_8
  double v29; // xmm1_8
  float v30; // xmm1_4
  float v31; // xmm0_4
  double v32; // xmm0_8
  double v33; // xmm1_8
  Vector vecBoxAbsMaxs; // [esp+8h] [ebp-40h] BYREF
  Vector vecBoxAbsMins; // [esp+14h] [ebp-34h] BYREF
  Vector vecMinsIn; // [esp+20h] [ebp-28h] BYREF
  Vector vecMaxsIn; // [esp+2Ch] [ebp-1Ch] BYREF
  CBoneCache *pCache; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]
  CBaseAnimating *v40; // [esp+40h] [ebp-8h]
  int v41; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  v40 = this;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  v6 = (int)m_pStudioHdr->m_pStudioHdr + 12 * this->m_nHitboxSet.m_Value + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
  if ( v6 == 0 || *(_DWORD *)(v6 + 4) == 0 )
    return 0;
  pCache = CBaseAnimating::GetBoneCache(this, a2: (int)&savedregs);
  pVecWorldMins->x = 3.4028235e38;
  pVecWorldMins->y = 3.4028235e38;
  pVecWorldMins->z = 3.4028235e38;
  pVecWorldMaxs->x = -3.4028235e38;
  pVecWorldMaxs->y = -3.4028235e38;
  pVecWorldMaxs->z = -3.4028235e38;
  i = 0;
  if ( *(int *)(v6 + 4) > 0 )
  {
    v41 = 0;
    do
    {
      v7 = v41 + *(_DWORD *)(v6 + 8);
      v8 = *(_DWORD *)(v7 + v6);
      v9 = (float *)(v6 + v7);
      CachedBone = CBoneCache::GetCachedBone(this: pCache, studioIndex: v8);
      if ( CachedBone != nullptr )
      {
        ModelHierarchyScale = CBaseAnimating::GetModelHierarchyScale(this: v40);
        vecMaxsIn.x = v9[5] * ModelHierarchyScale;
        vecMaxsIn.y = v9[6] * ModelHierarchyScale;
        vecMaxsIn.z = ModelHierarchyScale * v9[7];
        v12 = CBaseAnimating::GetModelHierarchyScale(this: v40);
        vecMinsIn.x = v9[2] * v12;
        vecMinsIn.y = v9[3] * v12;
        vecMinsIn.z = v12 * v9[4];
        TransformAABB(
          transform: CachedBone,
          &vecMinsIn,
          &vecMaxsIn,
          vecMinsOut: &vecBoxAbsMins,
          vecMaxsOut: &vecBoxAbsMaxs);
        x = pVecWorldMins->x;
        if ( x > vecBoxAbsMins.x )
          x = vecBoxAbsMins.x;
        y = vecBoxAbsMins.y;
        v15 = x;
        pVecWorldMins->x = v15;
        v16 = pVecWorldMins->y;
        v17 = y;
        if ( v16 > v17 )
          v16 = v17;
        z = vecBoxAbsMins.z;
        v19 = v16;
        pVecWorldMins->y = v19;
        v20 = pVecWorldMins->z;
        v21 = z;
        if ( v20 > v21 )
          v20 = v21;
        v22 = vecBoxAbsMaxs.x;
        v23 = v20;
        pVecWorldMins->z = v23;
        v24 = pVecWorldMaxs->x;
        v25 = v22;
        if ( v24 < v25 )
          v24 = v25;
        v26 = vecBoxAbsMaxs.y;
        v27 = v24;
        pVecWorldMaxs->x = v27;
        v28 = pVecWorldMaxs->y;
        v29 = v26;
        if ( v28 < v29 )
          v28 = v29;
        v30 = vecBoxAbsMaxs.z;
        v31 = v28;
        pVecWorldMaxs->y = v31;
        v32 = pVecWorldMaxs->z;
        v33 = v30;
        if ( v32 < v33 )
          v32 = v33;
        pVecWorldMaxs->z = v32;
      }
      v41 += 68;
      ++i;
    }
    while ( i < *(_DWORD *)(v6 + 4) );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009C6A0
// Name: public: void CEntityDissolve::SetDissolverOrigin(class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDissolve::SetDissolverOrigin(CEntityDissolve *this, Vector vOrigin)
{
  CNetworkVectorBase<Vector,CEntityDissolve::NetworkVar_m_vDissolverOrigin> *p_m_vDissolverOrigin; // esi
  edict_t *m_pPev; // ecx

  p_m_vDissolverOrigin = &this->m_vDissolverOrigin;
  if ( vOrigin.x != this->m_vDissolverOrigin.m_Value.x
    || vOrigin.y != this->m_vDissolverOrigin.m_Value.y
    || vOrigin.z != this->m_vDissolverOrigin.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
    }
    p_m_vDissolverOrigin->m_Value = vOrigin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C730
// Name: public: void CEntityDissolve::SetMagnitude(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDissolve::SetMagnitude(CEntityDissolve *this, int iMagnitude)
{
  CNetworkVarBase<int,CEntityDissolve::NetworkVar_m_nMagnitude> *p_m_nMagnitude; // esi
  edict_t *m_pPev; // ecx

  p_m_nMagnitude = &this->m_nMagnitude;
  if ( this->m_nMagnitude.m_Value != iMagnitude )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nMagnitude->m_Value = iMagnitude;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
      p_m_nMagnitude->m_Value = iMagnitude;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C780
// Name: public: CBaseAnimating::CBaseAnimating(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimating *__thiscall CBaseAnimating::CBaseAnimating(CBaseAnimating *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  unsigned int v5; // eax
  double z; // st7
  edict_t *v7; // ecx
  CGlobalVars *v8; // ebx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  edict_t *v13; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CBaseAnimating_vtbl *)&CBaseAnimating::`vftable';
  this->m_hLightingOrigin.m_Value.m_Index = -1;
  this->m_hLightingOriginRelative.m_Value.m_Index = -1;
  this->m_OnIgnite.m_Value.iVal = 0;
  this->m_OnIgnite.m_Value.eVal.m_Index = -1;
  this->m_OnIgnite.m_Value.fieldType = FIELD_VOID;
  this->m_StudioHdrInitLock.m_ownerID = 0;
  this->m_StudioHdrInitLock.m_depth = 0;
  this->m_BoneSetupMutex.m_ownerID = 0;
  this->m_BoneSetupMutex.m_depth = 0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
  }
  this->m_vecForce.m_Value.x = 0.0;
  this->m_vecForce.m_Value.y = 0.0;
  this->m_vecForce.m_Value.z = 0.0;
  if ( this->m_nForceBone.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x35Cu);
    }
    this->m_nForceBone.m_Value = 0;
  }
  if ( this->m_bClientSideAnimation.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x424u);
    }
    this->m_bClientSideAnimation.m_Value = false;
  }
  v5 = (unsigned int)this->m_iEFlags >> 11;
  this->m_pIk = nullptr;
  this->m_iIKCounter = 0;
  this->m_flIKGroundContactTime = 0.0;
  this->m_flIKGroundMinHeight = 0.0;
  this->m_flIKGroundMaxHeight = 0.0;
  if ( (v5 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this);
  z = this->m_vecAbsOrigin.z;
  this->m_flEstIkOffset = 0.0;
  this->m_flEstIkFloor = z;
  if ( this->m_flModelScale.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x378u);
    }
    this->m_flModelScale.m_Value = 1.0;
  }
  v8 = gpGlobals;
  if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x64u);
    }
    this->m_flAnimTime.m_Value = v8->curtime;
  }
  this->m_flPrevAnimTime = gpGlobals->curtime;
  if ( this->m_nNewSequenceParity.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x428u);
    }
    this->m_nNewSequenceParity.m_Value = 0;
  }
  if ( this->m_nResetEventsParity.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x42Cu);
    }
    this->m_nResetEventsParity.m_Value = 0;
  }
  this->m_boneCacheHandle = nullptr;
  this->m_pStudioHdr = nullptr;
  CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 1.0);
  this->m_fBoneCacheFlags = 0;
  if ( this->m_bForceRTTShadows.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x380u);
    }
    this->m_bForceRTTShadows.m_Value = false;
  }
  if ( this->m_ScaleType.m_Value != HIERARCHICAL_MODEL_SCALE )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x384u);
    }
    this->m_ScaleType.m_Value = HIERARCHICAL_MODEL_SCALE;
  }
  CBaseEntity::AddEffects(this, nEffects: 4096);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009CA70
// Name: public: virtual bool CBaseAnimating::IsActivityFinished(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::IsActivityFinished(CBaseAnimating *this)
{
  return this->m_bSequenceFinished;
}

//------------------------------------------------------------------------------
// Address: 0x1009CA80
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseAnimating::NetworkVar_m_hLightingOriginRelative>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOriginRelative>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOriginRelative> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOriginRelative> *v5; // eax
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
    v5 = this - 270;
    if ( *((_BYTE *)this - 996) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x438u);
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
// Address: 0x1009CB10
// Name: public: virtual void CBaseAnimating::SetLightingOriginRelative(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetLightingOriginRelative(CBaseAnimating *this, CBaseEntity *pLightingOriginRelative)
{
  CNetworkHandleBase<CBaseEntity,CBaseAnimating::NetworkVar_m_hLightingOriginRelative>::Set(
    this: &this->m_hLightingOriginRelative,
    val: pLightingOriginRelative);
}

//------------------------------------------------------------------------------
// Address: 0x1009CB20
// Name: public: virtual void CBaseAnimating::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::OnRestore(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  edict_t *m_pPev; // ecx
  void (__thiscall *PopulatePoseParameters)(CBaseAnimating *); // edx

  CBaseEntity::OnRestore(this);
  if ( this->m_nSequence.m_Value != -1 )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr
      && m_pStudioHdr->m_pStudioHdr != nullptr
      && !CBaseAnimating::IsValidSequence(this, iSequence: this->m_nSequence.m_Value) )
    {
      CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 32);
      if ( this->m_nSequence.m_Value != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3B0u);
        }
        this->m_nSequence.m_Value = 0;
      }
    }
  }
  PopulatePoseParameters = this->PopulatePoseParameters;
  this->m_flEstIkFloor = this->m_vecOrigin.m_Value.z;
  PopulatePoseParameters(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009CBD0
// Name: protected: void CBaseAnimating::CheckIfEntityShouldForceRTTShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::CheckIfEntityShouldForceRTTShadows(CBaseAnimating *this)
{
  int v2; // edi
  edict_t *m_pPev; // ecx

  v2 = 0;
  while ( this == nullptr
       || this->m_iClassname.pszValue != g_pszForceRTTClassnames[v2]
       && !CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: g_pszForceRTTClassnames[v2]) )
  {
    if ( (unsigned int)++v2 >= 5 )
      return;
  }
  if ( !this->m_bForceRTTShadows.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bForceRTTShadows.m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
      this->m_bForceRTTShadows.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CC40
// Name: public: void CBaseAnimating::UseClientSideAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::UseClientSideAnimation(CBaseAnimating *this)
{
  CNetworkVarBase<bool,CBaseAnimating::NetworkVar_m_bClientSideAnimation> *p_m_bClientSideAnimation; // esi
  edict_t *m_pPev; // ecx

  p_m_bClientSideAnimation = &this->m_bClientSideAnimation;
  if ( !this->m_bClientSideAnimation.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bClientSideAnimation->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x424u);
      p_m_bClientSideAnimation->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CC80
// Name: private: void CBaseAnimating::StudioFrameAdvanceInternal(class CStudioHdr __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::StudioFrameAdvanceInternal(
        CBaseAnimating *this,
        CStudioHdr *pStudioHdr,
        float flCycleDelta)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  edict_t *m_pPev; // ecx
  float flNewCycle; // [esp+20h] [ebp+Ch]

  v4 = flCycleDelta + this->m_flCycle.m_Value;
  flNewCycle = v4;
  if ( v4 < 0.0 )
  {
    if ( v4 < 1.0 )
      goto LABEL_7;
  }
  else if ( v4 < 1.0 )
  {
    if ( v4 <= CBaseAnimating::GetLastVisibleCycle(this, pStudioHdr, iSequence: this->m_nSequence.m_Value) )
      goto LABEL_14;
    goto LABEL_13;
  }
  this->ReachedEndOfSequence(this);
LABEL_7:
  if ( this->m_bSequenceLoops )
  {
    v5 = v4 - (double)(int)v4;
LABEL_12:
    flNewCycle = v5;
    goto LABEL_13;
  }
  if ( v4 >= 0.0 )
  {
    v5 = 1.0;
    goto LABEL_12;
  }
  flNewCycle = 0.0;
LABEL_13:
  this->m_bSequenceFinished = true;
LABEL_14:
  if ( this->m_flCycle.m_Value != flNewCycle )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flCycle.m_Value = flNewCycle;
  }
  this->m_flGroundSpeed = this->GetSequenceGroundSpeed(this, a2: pStudioHdr, a3: this->m_nSequence.m_Value);
  CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 8);
  Studio_InvalidateBoneCacheIfNotMatching(cacheHandle: this->m_boneCacheHandle, flTimeValid: gpGlobals->curtime);
}

//------------------------------------------------------------------------------
// Address: 0x1009CDB0
// Name: public: virtual bool CBaseAnimating::BecomeRagdollOnClient(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBaseAnimating::BecomeRagdollOnClient@<al>(
        CBaseAnimating *this@<ecx>,
        int a2@<edi>,
        const Vector *force)
{
  edict_t *m_pPev; // ecx
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // eax
  CBaseEntity *v7; // eax
  CBaseEntity *v8; // esi
  Vector vecClampedForce; // [esp+24h] [ebp-Ch] BYREF

  if ( !this->CanBecomeRagdoll(this) )
    return 0;
  ((void (__thiscall *)(CBaseAnimating *, int))this->VPhysicsDestroyObject)(a1: this, a2);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( !this->m_bClientSideRagdoll.m_Value )
  {
    this->NetworkStateChanged_m_bClientSideRagdoll(this, a2: &this->m_bClientSideRagdoll);
    this->m_bClientSideRagdoll.m_Value = true;
  }
  this->ClampRagdollForce(this, a2: force, a3: &vecClampedForce);
  if ( vecClampedForce.x != this->m_vecForce.m_Value.x
    || vecClampedForce.y != this->m_vecForce.m_Value.y
    || vecClampedForce.z != this->m_vecForce.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
    }
    this->m_vecForce.m_Value = vecClampedForce;
  }
  ((void (__thiscall *)(CBaseAnimating *, _DWORD))this->SetParent)(a1: this, a2: 0);
  CBaseEntity::AddFlag(this, flags: 0x40000000);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 2.0, szContext: nullptr);
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  m_Index = this->m_hEffectEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v7 = (CBaseEntity *)__RTDynamicCast(
                        inptr: m_pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CEntityFlame `RTTI Type Descriptor',
                        isReference: 0);
  v8 = v7;
  if ( v7 != nullptr )
  {
    CBaseEntity::ThinkSet(this: v7, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this: v8, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009CFC0
// Name: public: void CBaseAnimating::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetSequence(CBaseAnimating *this, int nSequence)
{
  int m_Value; // ebx
  edict_t *m_pPev; // ecx

  m_Value = this->m_nSequence.m_Value;
  if ( m_Value != nSequence )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3B0u);
    }
    this->m_nSequence.m_Value = nSequence;
  }
  if ( m_Value != this->m_nSequence.m_Value )
  {
    CBaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 32);
    this->OnSequenceSet(this, a2: m_Value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D030
// Name: public: virtual void CBaseAnimating::CalculateIKLocks(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAnimating::CalculateIKLocks(CBaseAnimating *this@<ecx>, float a2@<ebp>, float currentTime)
{
  void (__thiscall *GetVectors)(CBaseEntity *, Vector *, Vector *, Vector *); // edx
  CIKContext *m_pIk; // eax
  CIKTarget *v6; // edi
  float v7; // xmm1_4
  int v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  int m_iEFlags; // eax
  float z; // xmm7_4
  float floor; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float height; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  float radius; // xmm0_4
  float v23; // xmm0_4
  int m_Value; // [esp-24h] [ebp-194h]
  _BYTE v25[12]; // [esp-Ch] [ebp-17Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-170h] BYREF
  CGameTrace trace; // [esp+58h] [ebp-118h] BYREF
  float v28; // [esp+ACh] [ebp-C4h]
  float v29; // [esp+BCh] [ebp-B4h]
  _DWORD v30[3]; // [esp+C0h] [ebp-B0h] BYREF
  CTraceFilterSkipNPCs traceFilter; // [esp+CCh] [ebp-A4h] BYREF
  Vector v32; // [esp+DCh] [ebp-94h] BYREF
  Vector v33; // [esp+E8h] [ebp-88h] BYREF
  Vector v34; // [esp+F4h] [ebp-7Ch] BYREF
  Vector v35; // [esp+100h] [ebp-70h] BYREF
  Vector v36; // [esp+10Ch] [ebp-64h] BYREF
  float v37; // [esp+118h] [ebp-58h]
  float v38; // [esp+11Ch] [ebp-54h]
  float v39; // [esp+120h] [ebp-50h]
  float v40; // [esp+124h] [ebp-4Ch]
  float v41; // [esp+128h] [ebp-48h]
  float v42; // [esp+12Ch] [ebp-44h]
  Vector startpos; // [esp+130h] [ebp-40h] BYREF
  Vector p1; // [esp+13Ch] [ebp-34h] BYREF
  Vector p2; // [esp+148h] [ebp-28h] BYREF
  float v46; // [esp+154h] [ebp-1Ch]
  int i; // [esp+158h] [ebp-18h]
  Vector up; // [esp+15Ch] [ebp-14h] BYREF
  void *v49; // [esp+168h] [ebp-8h]
  void *retaddr; // [esp+170h] [ebp+0h]

  up.z = a2;
  v49 = retaddr;
  if ( this->m_pIk != nullptr )
  {
    m_Value = this->m_CollisionGroup.m_Value;
    ray.m_Extents.y = 0.0;
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)v30,
      passedict: this,
      collisionGroup: m_Value,
      pExtraShouldHitFunc: nullptr);
    GetVectors = this->GetVectors;
    v30[0] = &CTraceFilterSkipNPCs::`vftable';
    GetVectors(this, a2: nullptr, a3: nullptr, a4: (Vector *)&p2.z);
    m_pIk = this->m_pIk;
    p2.y = 0.0;
    if ( m_pIk->m_target.m_Size > 0 )
    {
      up.x = 0.0;
      do
      {
        v6 = (CIKTarget *)&m_pIk->m_target.m_Memory.m_Memory[LODWORD(up.x)];
        if ( CIKTarget::IsActive(this: (CIKTarget *)&m_pIk->m_target.m_Memory.m_Memory[LODWORD(up.x)]) && v6->type == 3 )
        {
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this);
          v7 = v46;
          v8 = i;
          v9 = v6->est.pos.y - this->m_vecAbsOrigin.y;
          v10 = v6->est.pos.z - this->m_vecAbsOrigin.z;
          v11 = v6->est.pos.x - this->m_vecAbsOrigin.x;
          m_iEFlags = this->m_iEFlags;
          v29 = *(float *)&i * v10;
          z = p2.z;
          v28 = (float)(v46 * v9) * v46;
          v41 = v9 - v28;
          v40 = v11 - (float)((float)(p2.z * v11) * p2.z);
          floor = v6->est.floor;
          v42 = v10 - (float)((float)(*(float *)&i * v10) * *(float *)&i);
          v38 = v46 * floor;
          v15 = p2.z * floor;
          v37 = p2.z * floor;
          v39 = *(float *)&i * floor;
          if ( (m_iEFlags & 0x800) != 0 )
          {
            CBaseEntity::CalcAbsolutePosition(this);
            v8 = i;
            v7 = v46;
            z = p2.z;
            v15 = v37;
          }
          v16 = (float)(this->m_vecAbsOrigin.y + v41) + v38;
          v17 = (float)(this->m_vecAbsOrigin.z + v42) + v39;
          v18 = v15 + (float)(this->m_vecAbsOrigin.x + v40);
          height = v6->est.height;
          startpos.x = (float)(height * z) + v18;
          startpos.y = (float)(v7 * height) + v16;
          v20 = *(float *)&v8 * height;
          LODWORD(v21) = LODWORD(height) ^ _mask__NegFloat_;
          startpos.z = v20 + v17;
          p1.y = (float)(v7 * v21) + v16;
          p1.z = (float)(*(float *)&v8 * v21) + v17;
          radius = v6->est.radius;
          p1.x = (float)(v21 * z) + v18;
          if ( radius <= 1.0 )
            radius = 1.0;
          up.y = radius;
          v36.x = radius;
          v36.y = radius;
          v36.z = 1.0;
          p2.x = -radius;
          *(float *)&traceFilter.m_pPassEnt = -radius;
          *(float *)&traceFilter.m_collisionGroup = -radius;
          traceFilter.m_pExtraShouldHitCheckFunction = nullptr;
          Ray_t::Init(
            this: (Ray_t *)v25,
            start: &startpos,
            end: &p1,
            mins: (const Vector *)&traceFilter.m_pPassEnt,
            maxs: &v36);
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)v25,
            a3: 33570827u,
            a4: (ITraceFilter *)v30,
            a5: (CGameTrace *)(&ray.m_IsSwept + 7));
          if ( trace.plane.pad[1] == 0 )
            goto LABEL_22;
          v32.x = up.y;
          v32.y = up.y;
          v32.z = 1.0;
          v33.x = p2.x;
          v33.y = p2.x;
          v33.z = 0.0;
          Ray_t::Init(this: (Ray_t *)v25, start: &v6->trace.hip, end: &v6->est.pos, mins: &v33, maxs: &v32);
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)v25,
            a3: 33570827u,
            a4: (ITraceFilter *)v30,
            a5: (CGameTrace *)(&ray.m_IsSwept + 7));
          LODWORD(v23) = LODWORD(v6->est.height) ^ _mask__NegFloat_;
          startpos = trace.startpos;
          p1.y = (float)(v46 * v23) + trace.startpos.y;
          v34.x = up.y;
          v34.y = up.y;
          v34.z = 1.0;
          v35.x = p2.x;
          v35.y = p2.x;
          p1.x = (float)(v23 * p2.z) + trace.startpos.x;
          p1.z = (float)(*(float *)&i * v23) + trace.startpos.z;
          v35.z = 0.0;
          Ray_t::Init(this: (Ray_t *)v25, start: &startpos, end: &p1, mins: &v35, maxs: &v34);
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)v25,
            a3: 33570827u,
            a4: (ITraceFilter *)v30,
            a5: (CGameTrace *)(&ray.m_IsSwept + 7));
          if ( trace.plane.pad[1] == 0 )
          {
LABEL_22:
            if ( CGameTrace::DidHitWorld(this: (CGameTrace *)(&ray.m_IsSwept + 7)) )
            {
              CIKTarget::SetPosWithNormalOffset(this: v6, pos: &trace.startpos, normal: &trace.endpos);
              CIKTarget::SetNormal(this: v6, a2: COERCE_FLOAT((Vector *)&up.z), normal: &trace.endpos);
            }
            else
            {
              CIKTarget::SetPos(this: v6, pos: &trace.startpos);
              if ( (this->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this);
              CIKTarget::SetAngles(this: v6, angles: &this->m_angAbsRotation);
            }
          }
        }
        m_pIk = this->m_pIk;
        LODWORD(up.x) += 340;
        ++LODWORD(p2.y);
      }
      while ( SLODWORD(p2.y) < m_pIk->m_target.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D500
// Name: public: void CBaseAnimating::SetBodygroup(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetBodygroup(CBaseAnimating *this, int iGroup, int iValue)
{
  bool v4; // zf
  CNetworkVarBase<int,CBaseAnimating::NetworkVar_m_nBody> *p_m_nBody; // edi
  CStudioHdr *m_pStudioHdr; // esi
  CNetworkVarBase<int,CBaseAnimating::NetworkVar_m_nBody> *v7; // eax
  CBaseEdict *m_Value; // ecx
  int newBody; // [esp+8h] [ebp-4h] BYREF

  v4 = this->m_pStudioHdr == nullptr;
  p_m_nBody = &this->m_nBody;
  newBody = this->m_nBody.m_Value;
  if ( v4 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  SetBodygroup(pstudiohdr: m_pStudioHdr, body: &newBody, iGroup, iValue);
  if ( p_m_nBody->m_Value != newBody )
  {
    v7 = p_m_nBody - 220;
    if ( LOBYTE(p_m_nBody[-199].m_Value) != 0 )
    {
      LOBYTE(v7[22].m_Value) |= 1u;
      p_m_nBody->m_Value = newBody;
    }
    else
    {
      m_Value = (CBaseEdict *)v7[6].m_Value;
      if ( m_Value != nullptr )
        CBaseEdict::StateChanged(this: m_Value, offset: 0x370u);
      p_m_nBody->m_Value = newBody;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D5A0
// Name: public: void CBaseAnimating::ResetClientsideFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::ResetClientsideFrame(CBaseAnimating *this)
{
  CNetworkVarBase<bool,CBaseAnimating::NetworkVar_m_bClientSideFrameReset> *p_m_bClientSideFrameReset; // esi
  bool v2; // bl
  edict_t *m_pPev; // ecx

  p_m_bClientSideFrameReset = &this->m_bClientSideFrameReset;
  v2 = !this->m_bClientSideFrameReset.m_Value;
  if ( this->m_bClientSideFrameReset.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bClientSideFrameReset->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x425u);
      p_m_bClientSideFrameReset->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D5F0
// Name: public: void CBaseAnimating::CopyAnimationDataFrom(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::CopyAnimationDataFrom(CBaseAnimating *this, CBaseAnimating *pSource)
{
  CBaseAnimating *v2; // edi
  CBaseAnimating_vtbl *v4; // ebx
  int v5; // eax
  CBaseAnimating *v6; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx

  v2 = pSource;
  this->m_ModelName.pszValue = *(const char **)((int (__thiscall *)(CBaseAnimating *, CBaseAnimating **))pSource->GetModelName)(
                                                 a1: pSource,
                                                 a2: &pSource);
  CBaseEntity::DispatchUpdateTransmitState(this);
  v4 = this->__vftable;
  v5 = v2->GetModelIndex(this: v2);
  v4->SetModelIndex(this, a2: v5);
  m_Value = this->m_flCycle.m_Value;
  pSource = (CBaseAnimating *)LODWORD(v2->m_flCycle.m_Value);
  v6 = pSource;
  if ( m_Value != *(float *)&pSource )
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
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
        v6 = pSource;
      }
    }
    LODWORD(this->m_flCycle.m_Value) = v6;
  }
  CBaseEntity::SetEffects(this, nEffects: v2->m_fEffects.m_Value | 8);
  CBaseAnimating::SetSequence(this, nSequence: v2->m_nSequence.m_Value);
  this->m_flAnimTime.m_Value = v2->m_flAnimTime.m_Value;
  this->m_nBody.m_Value = v2->m_nBody.m_Value;
  this->m_nSkin.m_Value = v2->m_nSkin.m_Value;
  CBaseAnimating::LockStudioHdr(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D6D0
// Name: public: void CBaseAnimating::DoMuzzleFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::DoMuzzleFlash(CBaseAnimating *this)
{
  CNetworkVarBase<unsigned char,CBaseAnimating::NetworkVar_m_nMuzzleFlashParity> *p_m_nMuzzleFlashParity; // esi
  unsigned __int8 v2; // bl
  edict_t *m_pPev; // ecx

  p_m_nMuzzleFlashParity = &this->m_nMuzzleFlashParity;
  v2 = (this->m_nMuzzleFlashParity.m_Value + 1) & 3;
  if ( this->m_nMuzzleFlashParity.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nMuzzleFlashParity->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x431u);
      p_m_nMuzzleFlashParity->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D720
// Name: public: void CBaseAnimating::UpdateModelScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::UpdateModelScale(CBaseAnimating *this)
{
  float *DataObject; // esi
  int v3; // xmm1_4
  float v4; // xmm0_4
  edict_t *v5; // ecx
  float v6; // xmm1_4
  edict_t *m_pPev; // ecx

  DataObject = (float *)CBaseEntity::GetDataObject(this, type: 3);
  if ( DataObject != nullptr )
  {
    v3 = 0;
    v4 = (float)(gpGlobals->curtime - DataObject[3]) / (float)(DataObject[2] - DataObject[3]);
    if ( v4 < 0.0 || (v3 = 1065353216, v4 > 1.0) )
      v4 = *(float *)&v3;
    if ( gpGlobals->curtime < DataObject[2] )
    {
      v6 = (float)((float)(DataObject[1] - *DataObject) * v4) + *DataObject;
      if ( this->m_flModelScale.m_Value != v6 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flModelScale.m_Value = v6;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
          this->m_flModelScale.m_Value = v6;
        }
      }
    }
    else
    {
      if ( this->m_flModelScale.m_Value != DataObject[1] )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v5 = this->m_Network.m_pPev;
          if ( v5 != nullptr )
            CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x378u);
        }
        this->m_flModelScale.m_Value = DataObject[1];
      }
      CBaseEntity::DestroyDataObject(this, type: 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D840
// Name: public: virtual bool CBaseAnimating::Dissolve(char const __near *,float,bool,int,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimating::Dissolve(
        CBaseAnimating *this,
        const char *pMaterialName,
        float flStartTime,
        int bNPCOnly,
        int nDissolveType,
        Vector vDissolverOrigin,
        int iMagnitude)
{
  CEntityDissolve *v9; // eax
  CEntityDissolve *v10; // edi
  float z; // ecx
  IGameEvent *v12; // edi
  edict_t *m_pPev; // esi
  Vector v14; // [esp+0h] [ebp-14h]

  if ( (_BYTE)bNPCOnly != 0 && (this->m_fFlags.m_Value & 0x4000) == 0 || (this->m_fFlags.m_Value & 0x20000000) != 0 )
    return false;
  HIBYTE(bNPCOnly) = 0;
  v9 = CEntityDissolve::Create(
         pTarget: this,
         pMaterialName,
         flStartTime,
         nDissolveType,
         pRagdollCreated: (bool *)&bNPCOnly + 3);
  v10 = v9;
  if ( v9 != nullptr )
  {
    CBaseEntity::SetEffectEntity(this, pEffectEnt: v9);
    CBaseEntity::AddFlag(this, flags: 0x20000000);
    z = vDissolverOrigin.z;
    this->m_flDissolveStartTime = flStartTime;
    *(_QWORD *)&v14.x = *(_QWORD *)&vDissolverOrigin.x;
    v14.z = z;
    CEntityDissolve::SetDissolverOrigin(this: v10, vOrigin: v14);
    CEntityDissolve::SetMagnitude(this: v10, iMagnitude);
  }
  if ( this->Classify(this) == CLASS_NONE
    && (this->m_iClassname.pszValue == "prop_ragdoll"
     || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "prop_ragdoll")) )
  {
    v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "ragdoll_dissolved", a3: 0, a4: 0);
    if ( v12 != nullptr )
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      v12->SetInt(this: v12, a2: "entindex", a3: (int)m_pPev);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v12, a3: false);
    }
  }
  return HIBYTE(bNPCOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1009D960
// Name: public: virtual void CBaseAnimating::Unfreeze(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::Unfreeze(CBaseAnimating *this)
{
  CNetworkVarBase<float,CBaseAnimating::NetworkVar_m_flFrozen> *p_m_flFrozen; // esi
  edict_t *m_pPev; // ecx

  if ( this->m_flFrozenThawRate < 0.0 )
  {
    p_m_flFrozen = &this->m_flFrozen;
    if ( this->m_flFrozen.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_flFrozen->m_Value = 0.0;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x44Cu);
        p_m_flFrozen->m_Value = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D9C0
// Name: public: virtual void CBaseAnimating::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::Activate(CBaseAnimating *this)
{
  CBaseEntity::Activate(this);
  CBaseAnimating::SetLightingOrigin(this, strLightingOrigin: this->m_iszLightingOrigin);
  CBaseAnimating::SetLightingOriginRelative(this, strLightingOriginRelative: this->m_iszLightingOriginRelative);
  CBaseAnimating::CheckIfEntityShouldForceRTTShadows(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D9F0
// Name: public: void CBaseAnimating::StudioFrameAdvanceManual(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::StudioFrameAdvanceManual(CBaseAnimating *this, float flInterval)
{
  CStudioHdr *m_pStudioHdr; // eax
  CGlobalVars *v4; // ebx
  edict_t *m_pPev; // ecx
  double v6; // st7
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  CStudioHdr *v10; // eax
  int m_Value; // [esp-8h] [ebp-14h]
  CStudioHdr *flCycleRate; // [esp+8h] [ebp-4h]
  float flCycleRatea; // [esp+8h] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  flCycleRate = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    CBaseAnimating::UpdateModelScale(this);
    v4 = gpGlobals;
    if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
      }
      this->m_flAnimTime.m_Value = v4->curtime;
    }
    m_Value = this->m_nSequence.m_Value;
    this->m_flPrevAnimTime = this->m_flAnimTime.m_Value - flInterval;
    v6 = CBaseAnimating::SequenceDuration(this, pStudioHdr: flCycleRate, iSequence: m_Value);
    if ( v6 <= 0.0 )
    {
      v7 = 10.0;
    }
    else
    {
      flCycleRatea = v6;
      v7 = 1.0 / flCycleRatea;
    }
    v8 = 1.0 - this->m_flFrozen.m_Value;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = 0.0;
    }
    v9 = (float)(this->m_flPlaybackRate.m_Value * v8) * v7;
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    v10 = this->m_pStudioHdr;
    if ( v10 == nullptr || v10->m_pStudioHdr == nullptr )
      v10 = nullptr;
    CBaseAnimating::StudioFrameAdvanceInternal(this, pStudioHdr: v10, flCycleDelta: v9 * flInterval);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DB40
// Name: public: virtual void CBaseAnimating::StudioFrameAdvance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::StudioFrameAdvance(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // ecx
  int v3; // xmm1_4
  float m_Value; // xmm2_4
  float v5; // xmm0_4
  CGlobalVars *v6; // ebx
  edict_t *m_pPev; // ecx
  CStudioHdr *v8; // edi
  double v9; // st7
  float v10; // xmm0_4
  const char *pszValue; // edi
  const char *SequenceName; // eax
  double v13; // [esp+10h] [ebp-18h]
  float flCycleDelta; // [esp+14h] [ebp-14h]
  CStudioHdr *pStudioHdr; // [esp+20h] [ebp-8h]
  float pStudioHdra; // [esp+20h] [ebp-8h]
  float v17; // [esp+24h] [ebp-4h]

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  pStudioHdr = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && CStudioHdr::SequencesAvailable(this: m_pStudioHdr) )
  {
    CBaseAnimating::UpdateModelScale(this);
    v3 = 0;
    if ( this->m_flPrevAnimTime == 0.0 )
      this->m_flPrevAnimTime = this->m_flAnimTime.m_Value;
    m_Value = this->m_flAnimTime.m_Value;
    v5 = gpGlobals->curtime - m_Value;
    if ( v5 < 0.0 || (v3 = 1045220557, v5 > 0.2) )
      v5 = *(float *)&v3;
    v17 = v5;
    if ( v5 > 0.001 )
    {
      this->m_flPrevAnimTime = m_Value;
      v6 = gpGlobals;
      if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
        }
        this->m_flAnimTime.m_Value = v6->curtime;
      }
      v8 = pStudioHdr;
      v9 = CBaseAnimating::SequenceDuration(this, pStudioHdr, iSequence: this->m_nSequence.m_Value);
      if ( v9 <= 0.0 )
      {
        v10 = 10.0;
      }
      else
      {
        pStudioHdra = v9;
        v10 = 1.0 / pStudioHdra;
      }
      flCycleDelta = CBaseAnimating::GetPlaybackRate(this) * v10 * v17;
      CBaseAnimating::StudioFrameAdvanceInternal(this, pStudioHdr: v8, flCycleDelta);
      if ( ai_sequence_debug.m_pParent != nullptr
        && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
        && (this->m_debugOverlays & 0x1000) != 0 )
      {
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        v13 = this->m_flCycle.m_Value;
        SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: this->m_nSequence.m_Value);
        _Msg(a1: "%5.2f : %s : %s : %5.3f\n", gpGlobals->curtime, pszValue, SequenceName, v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DD00
// Name: public: void CBaseAnimating::ResetSequenceInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::ResetSequenceInfo(CBaseAnimating *this)
{
  CStudioHdr *m_pStudioHdr; // edi
  edict_t *m_pPev; // ecx
  int v4; // edi
  edict_t *v5; // ecx
  int v6; // edi
  edict_t *v7; // ecx
  int m_Value; // esi
  const studiohdr_t *v9; // ecx
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  CStudioHdr *pStudioHdr; // [esp+4h] [ebp-4h]

  if ( ai_sequence_debug.m_pParent != nullptr
    && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
    && (this->m_debugOverlays & 0x1000) != 0 )
  {
    DevMsg(a1: "ResetSequenceInfo");
  }
  if ( this->m_nSequence.m_Value == -1 )
    CBaseAnimating::SetSequence(this, nSequence: 0);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    pStudioHdr = this->m_pStudioHdr;
  }
  else
  {
    pStudioHdr = nullptr;
    m_pStudioHdr = nullptr;
  }
  this->m_flGroundSpeed = this->GetSequenceGroundSpeed(this, a2: m_pStudioHdr, a3: this->m_nSequence.m_Value);
  this->m_bSequenceLoops = GetSequenceFlags(pstudiohdr: m_pStudioHdr, sequence: this->m_nSequence.m_Value) & 1;
  if ( this->m_flPlaybackRate.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 1.0;
  }
  v4 = ((unsigned __int8)this->m_nNewSequenceParity.m_Value + 1) & 7;
  this->m_bSequenceFinished = false;
  this->m_flLastEventCheck = 0.0;
  if ( this->m_nNewSequenceParity.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x428u);
    }
    this->m_nNewSequenceParity.m_Value = v4;
  }
  v6 = ((unsigned __int8)this->m_nResetEventsParity.m_Value + 1) & 7;
  if ( this->m_nResetEventsParity.m_Value != v6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x42Cu);
    }
    this->m_nResetEventsParity.m_Value = v6;
  }
  if ( pStudioHdr != nullptr )
  {
    m_Value = this->m_nSequence.m_Value;
    if ( pStudioHdr->m_pVModel != nullptr )
    {
      v11 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: m_Value);
      SetEventIndexForSequence(seqdesc: v11);
    }
    else
    {
      v9 = pStudioHdr->m_pStudioHdr;
      v10 = m_Value;
      if ( m_Value < 0 || m_Value >= v9->numlocalseq )
        v10 = 0;
      SetEventIndexForSequence(seqdesc: (mstudioseqdesc_t *)((char *)v9 + 212 * v10 + v9->localseqindex));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DEE0
// Name: public: virtual void CBaseAnimating::SetupBones(class matrix3x4a_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CBaseAnimating::SetupBones(
        CBaseAnimating *this@<ecx>,
        int a2@<ebp>,
        matrix3x4a_t *pBoneToWorld,
        CBoneCache *boneMask)
{
  void *v4; // esp
  CThreadFastMutex *p_m_BoneSetupMutex; // edi
  DWORD CurrentThreadId; // ecx
  void (*BeginLock)(void); // edx
  CStudioHdr *m_pStudioHdr; // edi
  unsigned int v10; // eax
  CAI_BaseNPC *v11; // eax
  unsigned int m_iEFlags; // ecx
  IBoneSetup v13; // ecx
  matrix3x4a_t *m_iIKCounter; // eax
  unsigned int m_Index; // eax
  CBaseEntity *MoveParent; // eax
  CBaseAnimating *v17; // eax
  matrix3x4a_t *v18; // edi
  CBoneCache *BoneCache; // eax
  const QAngle *AbsAngles; // eax
  CThreadFastMutex *v21; // eax
  Quaternion v23[256]; // [esp+48h] [ebp-1C5Ch] BYREF
  Vector v24[256]; // [esp+1048h] [ebp-C5Ch] BYREF
  CBoneBitList v25; // [esp+1C48h] [ebp-5Ch] BYREF
  float m_flEstIkOffset; // [esp+1C78h] [ebp-2Ch]
  Vector v27; // [esp+1C7Ch] [ebp-28h] BYREF
  IBoneSetup flTime; // [esp+1C88h] [ebp-1Ch] BYREF
  CBaseAnimating *duration; // [esp+1C8Ch] [ebp-18h]
  CThreadFastMutex *v30; // [esp+1C90h] [ebp-14h]
  CStudioHdr *v31; // [esp+1C94h] [ebp-10h]
  _DWORD v32[3]; // [esp+1C98h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+1CA4h] [ebp+0h]

  v32[0] = a2;
  v32[1] = retaddr;
  v4 = alloca(7256);
  p_m_BoneSetupMutex = &this->m_BoneSetupMutex;
  v30 = &this->m_BoneSetupMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_BoneSetupMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_BoneSetupMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_BoneSetupMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_BoneSetupMutex->m_depth;
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseAnimating::SetupBones",
    a3: 0,
    a4: "Server Animation",
    a5: false,
    a6: 4);
  BeginLock = (void (*)(void))mdlcache->BeginLock;
  duration = (CBaseAnimating *)mdlcache;
  BeginLock();
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  v31 = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    this->m_iEFlags |= 8u;
    v10 = (unsigned int)this->m_iEFlags >> 11;
    m_flEstIkOffset = this->m_flEstIkOffset;
    if ( (v10 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v27.x = this->m_vecAbsOrigin.x;
    v27.y = this->m_vecAbsOrigin.y;
    v27.z = this->m_vecAbsOrigin.z + m_flEstIkOffset;
    if ( sv_pvsskipanimation.m_pParent == nullptr
      || sv_pvsskipanimation.m_pParent->m_Value.m_nValue == 0
      || (v11 = this->MyNPCPointer(this)) == nullptr
      || CAI_BaseNPC::HasCondition(this: v11, iCondition: 1)
      || (this->m_fBoneCacheFlags & 3) != 0
      || CBaseEntity::DoesHavePlayerChild(this) )
    {
      if ( this->m_pIk != nullptr )
      {
        m_iEFlags = this->m_iEFlags;
        ++this->m_iIKCounter;
        v13.m_pBoneSetup = (CBoneSetup *)(m_iEFlags >> 11);
        memset(&v25, 0, sizeof(v25));
        if ( ((int)v13.m_pBoneSetup & 1) != 0 )
          CBaseEntity::CalcAbsolutePosition(this);
        m_iIKCounter = (matrix3x4a_t *)this->m_iIKCounter;
        v30 = (CThreadFastMutex *)boneMask;
        duration = (CBaseAnimating *)m_iIKCounter;
        flTime.m_pBoneSetup = v13.m_pBoneSetup;
        CIKContext::Init(
          this: this->m_pIk,
          pStudioHdr: m_pStudioHdr,
          angles: &this->m_angAbsRotation,
          pos: &v27,
          flTime: gpGlobals->curtime,
          iFramecounter: (int)m_iIKCounter,
          (int)boneMask);
        this->GetSkeleton(this, a2: m_pStudioHdr, a3: v24, a4: (QuaternionAligned *)v23, a5: (int)boneMask);
        CIKContext::UpdateTargets(
          this: this->m_pIk,
          a2: COERCE_FLOAT(v32),
          pos: v24,
          q: v23,
          boneToWorld: pBoneToWorld,
          boneComputed: &v25);
        ((void (__thiscall *)(CBaseAnimating *, _DWORD))this->CalculateIKLocks)(
          a1: this,
          a2: LODWORD(gpGlobals->curtime));
        CIKContext::SolveDependencies(
          this: this->m_pIk,
          a2: (int)v32,
          pos: v24,
          q: v23,
          boneToWorld: pBoneToWorld,
          boneComputed: &v25);
      }
      else
      {
        this->GetSkeleton(this, a2: m_pStudioHdr, a3: v24, a4: (QuaternionAligned *)v23, a5: (int)boneMask);
      }
    }
    else
    {
      IBoneSetup::IBoneSetup(
        this: &flTime,
        pStudioHdr: m_pStudioHdr,
        (int)boneMask,
        poseParameter: this->m_flPoseParameter.m_Value,
        pPoseDebugger: nullptr);
      IBoneSetup::InitPose(this: &flTime, pos: v24, q: (QuaternionAligned *)v23);
      IBoneSetup::~IBoneSetup(this: &flTime);
    }
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      && (this->m_fEffects.m_Value & 1) != 0 )
    {
      MoveParent = CBaseEntity::GetMoveParent(this);
      v17 = MoveParent->GetBaseAnimating(this: MoveParent);
      v18 = (matrix3x4a_t *)v17;
      if ( v17 != nullptr )
      {
        BoneCache = CBaseAnimating::GetBoneCache(this: v17, a2: (int)v32);
        if ( BoneCache != nullptr )
        {
          v30 = (CThreadFastMutex *)BoneCache;
          duration = (CBaseAnimating *)v18;
          flTime.m_pBoneSetup = (CBoneSetup *)pBoneToWorld;
          LODWORD(v27.z) = v23;
          LODWORD(v27.y) = v24;
          LODWORD(v27.x) = &v27;
          AbsAngles = CBaseEntity::GetAbsAngles(this);
          CBaseAnimating::BuildMatricesWithBoneMerge(
            this,
            pStudioHdr: v31,
            angles: AbsAngles,
            origin: (const Vector *)LODWORD(v27.x),
            pos: (const Vector *)LODWORD(v27.y),
            q: (const Quaternion *)LODWORD(v27.z),
            bonetoworld: (matrix3x4_t *)flTime.m_pBoneSetup,
            pParent: duration,
            pParentCache: (CBoneCache *)v30);
          this->m_iEFlags &= ~8u;
          if ( ai_setupbones_debug.m_pParent != nullptr && ai_setupbones_debug.m_pParent->m_Value.m_nValue != 0 )
            CBaseAnimating::DrawRawSkeleton(
              this,
              boneToWorld: pBoneToWorld,
              (int)boneMask,
              noDepthTest: true,
              duration: 0.11,
              monocolor: false);
          goto LABEL_40;
        }
      }
      m_pStudioHdr = v31;
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this);
    v30 = (CThreadFastMutex *)boneMask;
    duration = (CBaseAnimating *)pBoneToWorld;
    *(float *)&flTime.m_pBoneSetup = CBaseAnimating::GetModelHierarchyScale(this);
    Studio_BuildMatrices(
      pStudioHdr: m_pStudioHdr,
      angles: &this->m_angAbsRotation,
      origin: &v27,
      pos: v24,
      q: v23,
      iBone: -1,
      flScale: *(float *)&flTime.m_pBoneSetup,
      bonetoworld: (matrix3x4a_t *)duration,
      boneMask: (int)v30);
    if ( ai_setupbones_debug.m_pParent != nullptr && ai_setupbones_debug.m_pParent->m_Value.m_nValue != 0 )
      CBaseAnimating::DrawRawSkeleton(
        this,
        boneToWorld: pBoneToWorld,
        (int)boneMask,
        noDepthTest: true,
        duration: 0.11,
        monocolor: false);
    this->m_iEFlags &= ~8u;
  }
LABEL_40:
  ((void (__thiscall *)(CBaseAnimating *))duration->KeyValue)(a1: duration);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  v21 = v30;
  if ( v30->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v21, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1009E300
// Name: public: void CBaseAnimating::ResetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::ResetSequence(CBaseAnimating *this, int nSequence)
{
  int m_Value; // ebx
  const char *pszValue; // edi
  const char *v5; // eax
  edict_t *m_pPev; // ecx
  int v7; // edi
  const char *SequenceName; // [esp-4h] [ebp-10h]

  if ( ai_sequence_debug.m_pParent != nullptr
    && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
    && (this->m_debugOverlays & 0x1000) != 0 )
  {
    m_Value = this->m_nSequence.m_Value;
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: nSequence);
    v5 = CBaseAnimating::GetSequenceName(this, iSequence: m_Value);
    DevMsg(a1: "ResetSequence : %s: %s -> %s\n", pszValue, v5, SequenceName);
  }
  if ( !this->m_bSequenceLoops && this->m_flCycle.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flCycle.m_Value = 0.0;
  }
  v7 = this->m_nSequence.m_Value;
  CBaseAnimating::SetSequence(this, nSequence);
  if ( nSequence != v7 || !this->m_bSequenceLoops )
    CBaseAnimating::ResetSequenceInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009E3E0
// Name: public: void CBaseAnimating::SetFadeDistance(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetFadeDistance(CBaseAnimating *this, float minFadeDist, float maxFadeDist)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  if ( this->m_fadeMinDist.m_Value != minFadeDist )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x308u);
    }
    this->m_fadeMinDist.m_Value = minFadeDist;
  }
  if ( this->m_fadeMaxDist.m_Value != maxFadeDist )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_fadeMaxDist.m_Value = maxFadeDist;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x30Cu);
      this->m_fadeMaxDist.m_Value = maxFadeDist;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E950
// Name: public: virtual void CBaseAnimating::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::SetModel(CBaseAnimating *this, const char *szModelName)
{
  int v3; // eax
  const struct model_t *v4; // edi
  int v5; // eax
  CStudioHdr *m_pStudioHdr; // edi
  CStudioHdr *v7; // eax
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-4h]

  cacheCriticalSection = mdlcache;
  ((void (*)(void))mdlcache->BeginLock)();
  CBaseAnimating::UnlockStudioHdr(this);
  if ( *szModelName != 0 )
  {
    v3 = modelinfo->GetModelIndex(this: modelinfo, a2: szModelName);
    v4 = modelinfo->GetModel(this: modelinfo, a2: v3);
    if ( v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) != 3 )
    {
      v5 = modelinfo->GetModelType(this: modelinfo, a2: v4);
      _Msg(a1: "Setting CBaseAnimating to non-studio model %s  (type:%i)\n", szModelName, v5);
    }
  }
  Studio_DestroyBoneCache(cacheHandle: this->m_boneCacheHandle);
  this->m_boneCacheHandle = nullptr;
  UTIL_SetModel(pEntity: this, pModelName: szModelName);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    CStudioHdr::Term(this: this->m_pStudioHdr);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneParent);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneFlags);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
    free(pMem: m_pStudioHdr);
    this->m_pStudioHdr = nullptr;
  }
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v7 = this->m_pStudioHdr;
  if ( v7 != nullptr && v7->m_pStudioHdr != nullptr )
  {
    this->InitBoneControllers(this);
    CBaseAnimating::SetSequence(this, nSequence: 0);
  }
  this->PopulatePoseParameters(this);
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1009EBC0
// Name: void InitCBaseAnimatingScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCBaseAnimatingScriptDesc()
{
  ScriptFunctionBinding_t *v0; // esi
  ScriptFunctionBinding_t *v1; // esi
  ScriptFunctionBinding_t *v2; // esi
  ScriptFunctionBinding_t *v3; // eax
  ScriptFunctionBinding_t *v4; // esi

  if ( !bInitialized )
  {
    bInitialized = true;
    g_CBaseAnimating_ScriptDesc.m_pszDescription = "Animating models";
    g_CBaseAnimating_ScriptDesc.m_pszScriptName = "CBaseAnimating";
    g_CBaseAnimating_ScriptDesc.m_pszClassname = "CBaseAnimating";
    g_CBaseAnimating_ScriptDesc.m_pBaseDesc = GetScriptDesc(__formal: nullptr);
    g_CBaseAnimating_ScriptDesc.pHelper = GetScriptInstanceHelper_CBaseEntity();
    v0 = &g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                              this: &g_CBaseAnimating_ScriptDesc.m_FunctionBindings,
                                                                              elem: g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "Get the named attachement id";
    v0->m_desc.m_pszScriptName = "LookupAttachment";
    v0->m_desc.m_pszFunction = "LookupAttachment";
    ScriptDeduceFunctionSignature<CScriptKeyValues *,CScriptKeyValues,int,char const *>(
      pDesc: &v0->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseAnimating::LookupAttachment);
    v0->m_pfnBinding = CMemberScriptBinding1<CScriptKeyValues *,int (__thiscall CScriptKeyValues::*)(char const *),int,char const *>::Call;
    v0->m_pFunction = CBaseAnimating::LookupAttachment;
    v0->m_flags = 1;
    v1 = &g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                              this: &g_CBaseAnimating_ScriptDesc.m_FunctionBindings,
                                                                              elem: g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "Get the attachement id's origin vector";
    v1->m_desc.m_pszScriptName = "GetAttachmentOrigin";
    v1->m_desc.m_pszFunction = "ScriptGetAttachmentOrigin";
    ScriptDeduceFunctionSignature<CBaseAnimating *,CBaseAnimating,Vector const &,int>(
      pDesc: &v1->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseAnimating::ScriptGetAttachmentOrigin);
    v1->m_pfnBinding = CMemberScriptBinding1<CBaseAnimating *,Vector const & (__thiscall CBaseAnimating::*)(int),Vector const &,int>::Call;
    v1->m_pFunction = CBaseAnimating::ScriptGetAttachmentOrigin;
    v1->m_flags = 1;
    v2 = &g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                              this: &g_CBaseAnimating_ScriptDesc.m_FunctionBindings,
                                                                              elem: g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = "Get the attachement id's angles as a p,y,r vector";
    v2->m_desc.m_pszScriptName = "GetAttachmentAngles";
    v2->m_desc.m_pszFunction = "ScriptGetAttachmentAngles";
    ScriptDeduceFunctionSignature<CBaseAnimating *,CBaseAnimating,Vector const &,int>(
      pDesc: &v2->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseAnimating::ScriptGetAttachmentAngles);
    v2->m_pfnBinding = CMemberScriptBinding1<CBaseAnimating *,Vector const & (__thiscall CBaseAnimating::*)(int),Vector const &,int>::Call;
    v2->m_pFunction = CBaseAnimating::ScriptGetAttachmentAngles;
    v2->m_flags = 1;
    v3 = &g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                              this: &g_CBaseAnimating_ScriptDesc.m_FunctionBindings,
                                                                              elem: g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Size)];
    v3->m_desc.m_pszDescription = "Ask whether the main sequence is done playing";
    v3->m_desc.m_pszScriptName = "IsSequenceFinished";
    v3->m_desc.m_pszFunction = "IsSequenceFinished";
    v3->m_desc.m_ReturnType = 6;
    v3->m_pfnBinding = CMemberScriptBinding0<CBasePlayer *,bool (__thiscall CBasePlayer::*)(void),bool>::Call;
    v3->m_pFunction = CBaseAnimating::IsActivityFinished;
    v3->m_flags = 1;
    v4 = &g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                              this: &g_CBaseAnimating_ScriptDesc.m_FunctionBindings,
                                                                              elem: g_CBaseAnimating_ScriptDesc.m_FunctionBindings.m_Size)];
    v4->m_desc.m_pszDescription = "Sets a bodygroup";
    v4->m_desc.m_pszScriptName = "SetBodygroup";
    v4->m_desc.m_pszFunction = "SetBodygroup";
    ScriptDeduceFunctionSignature<CBaseAnimating *,CBaseAnimating,void,int,int>(
      pDesc: &v4->m_desc,
      pObject: nullptr,
      pfnProxied: CBaseAnimating::SetBodygroup);
    v4->m_flags = 1;
    v4->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CBaseAnimating *,void (__thiscall CBaseAnimating::*)(int,int),void,int,int>::Call;
    v4->m_pFunction = CBaseAnimating::SetBodygroup;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EDA0
// Name: public: virtual void CBaseAnimating::GetSkeleton(class CStudioHdr __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAnimating::GetSkeleton(
        CBaseAnimating *this@<ecx>,
        CBoneSetup *a2@<ebp>,
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        int boneMask)
{
  void *v6; // esp
  CIKContext v8; // [esp+20h] [ebp-108Ch] BYREF
  IBoneSetup v9[4]; // [esp+109Ch] [ebp-10h] BYREF
  CBoneSetup *retaddr; // [esp+10ACh] [ebp+0h]

  v9[1].m_pBoneSetup = a2;
  v9[2].m_pBoneSetup = retaddr;
  v6 = alloca(4232);
  if ( pStudioHdr != nullptr )
  {
    IBoneSetup::IBoneSetup(
      this: v9,
      pStudioHdr,
      boneMask,
      poseParameter: this->m_flPoseParameter.m_Value,
      pPoseDebugger: nullptr);
    IBoneSetup::InitPose(this: v9, pos, q);
    IBoneSetup::AccumulatePose(
      this: v9,
      pos,
      q,
      sequence: this->m_nSequence.m_Value,
      cycle: this->m_flCycle.m_Value,
      flWeight: 1.0,
      flTime: gpGlobals->curtime,
      pIKContext: this->m_pIk);
    if ( this->m_pIk != nullptr )
    {
      CIKContext::CIKContext(this: &v8);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this);
      CIKContext::Init(
        this: &v8,
        pStudioHdr,
        angles: &this->m_angAbsRotation,
        pos: &this->m_vecAbsOrigin,
        flTime: gpGlobals->curtime,
        iFramecounter: 0,
        boneMask);
      IBoneSetup::CalcAutoplaySequences(this: v9, pos, q, flRealTime: gpGlobals->curtime, pIKContext: &v8);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v8.m_ikLock);
      CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &v8.m_ikChainRule);
    }
    else
    {
      IBoneSetup::CalcAutoplaySequences(this: v9, pos, q, flRealTime: gpGlobals->curtime, pIKContext: nullptr);
    }
    IBoneSetup::CalcBoneAdj(this: v9, pos, q, controllers: this->m_flEncodedController.m_Value);
    IBoneSetup::~IBoneSetup(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EFA0
// Name: public: virtual CBaseAnimating::~CBaseAnimating(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::~CBaseAnimating(CBaseAnimating *this)
{
  CIKContext *m_pIk; // edi
  CStudioHdr *m_pStudioHdr; // edi
  memhandle_t__ *m_boneCacheHandle; // [esp-4h] [ebp-Ch]

  m_boneCacheHandle = this->m_boneCacheHandle;
  this->__vftable = (CBaseAnimating_vtbl *)&CBaseAnimating::`vftable';
  Studio_DestroyBoneCache(cacheHandle: m_boneCacheHandle);
  m_pIk = this->m_pIk;
  if ( m_pIk != nullptr )
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pIk->m_ikLock);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &m_pIk->m_ikChainRule);
    m_pIk->m_target.m_Size = 0;
    m_pIk->m_target.m_pElements = (CIKTarget *)m_pIk;
    free(pMem: m_pIk);
  }
  CBaseAnimating::UnlockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    CStudioHdr::Term(this: this->m_pStudioHdr);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneParent);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneFlags);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
    free(pMem: m_pStudioHdr);
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnIgnite);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017D3A0
// Name: public: virtual float CBaseAnimating::GetIdealSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::GetIdealSpeed(CBaseAnimating *this)
{
  return this->m_flGroundSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x101DDA90
// Name: public: void CBaseAnimating::InputBecomeRagdoll(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimating::InputBecomeRagdoll(CBaseAnimating *this, inputdata_t *inputdata)
{
  this->BecomeRagdollOnClient(this, a2: &vec3_origin);
}

//------------------------------------------------------------------------------
// Address: 0x103577E0
// Name: void MatrixAngles(struct matrix3x4_t const __near &,class Quaternion __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixAngles(const matrix3x4_t *matrix, Quaternion *q, Vector *pos)
{
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  Quaternion *v7; // edx
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4

  v3 = matrix->m_flMatVal[0][0];
  v4 = matrix->m_flMatVal[1][1];
  v5 = matrix->m_flMatVal[2][2];
  v6 = (float)((float)(matrix->m_flMatVal[0][0] + v4) + v5) + 1.0;
  if ( v6 <= 1.0000001 )
  {
    if ( v3 <= v4 || v3 <= v5 )
    {
      v7 = q;
      if ( v4 <= v5 )
      {
        v10 = (float)((float)(v5 + 1.0) - matrix->m_flMatVal[0][0]) - v4;
        q->x = matrix->m_flMatVal[2][0] + matrix->m_flMatVal[0][2];
        q->y = matrix->m_flMatVal[2][1] + matrix->m_flMatVal[1][2];
        q->z = v10;
        v8 = matrix->m_flMatVal[1][0] - matrix->m_flMatVal[0][1];
      }
      else
      {
        v9 = (float)((float)(v4 + 1.0) - matrix->m_flMatVal[0][0]) - v5;
        q->x = matrix->m_flMatVal[1][0] + matrix->m_flMatVal[0][1];
        q->y = v9;
        q->z = matrix->m_flMatVal[2][1] + matrix->m_flMatVal[1][2];
        v8 = matrix->m_flMatVal[0][2] - matrix->m_flMatVal[2][0];
      }
    }
    else
    {
      v7 = q;
      q->x = (float)((float)(matrix->m_flMatVal[0][0] + 1.0) - v4) - v5;
      q->y = matrix->m_flMatVal[1][0] + matrix->m_flMatVal[0][1];
      q->z = matrix->m_flMatVal[2][0] + matrix->m_flMatVal[0][2];
      v8 = matrix->m_flMatVal[2][1] - matrix->m_flMatVal[1][2];
    }
    v7->w = v8;
  }
  else
  {
    v7 = q;
    q->x = matrix->m_flMatVal[2][1] - matrix->m_flMatVal[1][2];
    q->y = matrix->m_flMatVal[0][2] - matrix->m_flMatVal[2][0];
    q->z = matrix->m_flMatVal[1][0] - matrix->m_flMatVal[0][1];
    q->w = v6;
  }
  v11 = (float)((float)((float)(v7->x * v7->x) + (float)(v7->y * v7->y)) + (float)(v7->z * v7->z))
      + (float)(v7->w * v7->w);
  if ( v11 != 0.0 )
  {
    v12 = 1.0 / fsqrt(v11);
    v7->w = v7->w * v12;
    v7->z = v7->z * v12;
    v7->y = v7->y * v12;
    v7->x = v7->x * v12;
  }
  pos->x = matrix->m_flMatVal[0][3];
  pos->y = matrix->m_flMatVal[1][3];
  pos->z = matrix->m_flMatVal[2][3];
}

//------------------------------------------------------------------------------
// Address: 0x103598D0
// Name: void MatrixAngles(struct matrix3x4_t const __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall MatrixAngles(int a1@<esi>, const VMatrix *src, QAngle *vAngles)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  long double v5; // [esp-4h] [ebp-28h]
  long double v6; // [esp-4h] [ebp-28h]
  long double v7; // [esp-4h] [ebp-28h]
  long double v8; // [esp-4h] [ebp-28h]
  long double up_4; // [esp+4h] [ebp-20h]
  long double up_4a; // [esp+4h] [ebp-20h]
  long double up_4b; // [esp+4h] [ebp-20h]
  long double up_4c; // [esp+4h] [ebp-20h]
  float left_8; // [esp+14h] [ebp-10h]
  float forward_8; // [esp+20h] [ebp-4h]

  v3 = src->m[1][0];
  left_8 = src->m[2][1];
  HIDWORD(up_4) = LODWORD(src->m[2][2]);
  forward_8 = src->m[2][0];
  v4 = src->m[0][1];
  LODWORD(v5) = a1;
  if ( fsqrt((float)(v3 * v3) + (float)(src->m[0][0] * src->m[0][0])) <= 0.001 )
  {
    __libm_sse2_atan2(y: v5, x: up_4);
    vAngles->y = COERCE_FLOAT(LODWORD(v4) ^ _mask__NegFloat_) * 57.29578;
    __libm_sse2_atan2(y: v8, x: up_4c);
    vAngles->x = COERCE_FLOAT(LODWORD(forward_8) ^ _mask__NegFloat_) * 57.29578;
    vAngles->z = 0.0;
  }
  else
  {
    __libm_sse2_atan2(y: v5, x: up_4);
    vAngles->y = v3 * 57.29578;
    __libm_sse2_atan2(y: v6, x: up_4a);
    vAngles->x = COERCE_FLOAT(LODWORD(forward_8) ^ _mask__NegFloat_) * 57.29578;
    __libm_sse2_atan2(y: v7, x: up_4b);
    vAngles->z = left_8 * 57.29578;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF190
// Name: CBaseAnimating_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseAnimating_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseAnimating>(__formal: nullptr);
  CBaseAnimating_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF1A0
// Name: DT_ServerAnimationData::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ServerAnimationData::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ServerAnimationData::g_SendTable);
  return atexit(func: DT_ServerAnimationData::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF1C0
// Name: DT_ServerAnimationData::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ServerAnimationData::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ServerAnimationData::ignored>(__formal: nullptr);
  DT_ServerAnimationData::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF1F0
// Name: DT_BaseAnimating::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimating::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseAnimating::g_SendTable);
  return atexit(func: DT_BaseAnimating::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF210
// Name: DT_BaseAnimating::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimating::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseAnimating::ignored>(__formal: nullptr);
  DT_BaseAnimating::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419680
// Name: DT_ServerAnimationData::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ServerAnimationData::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ServerAnimationData::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419690
// Name: DT_BaseAnimating::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseAnimating::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseAnimating::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1009E490
// Name: void ScriptDeduceFunctionSignature<class CBaseAnimating __near *,class CBaseAnimating,class Vector const __near &,int>(struct ScriptFuncDescriptor_t __near *,class CBaseAnimating __near *,class Vector const __near & (CBaseAnimating::*)(int))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseAnimating *,CBaseAnimating,Vector const &,int>(
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
  pDesc->m_ReturnType = 3;
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
// Address: 0x1009E540
// Name: void ScriptDeduceFunctionSignature<class CBaseAnimating __near *,class CBaseAnimating,void,int,int>(struct ScriptFuncDescriptor_t __near *,class CBaseAnimating __near *,void (CBaseAnimating::*)(int,int))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CBaseAnimating *,CBaseAnimating,void,int,int>(ScriptFuncDescriptor_t *pDesc)
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
    *v8 = 5;
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
// Address: 0x1009E640
// Name: struct datamap_t __near * DataMapInit<class CBaseAnimating>(class CBaseAnimating __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseAnimating>()
{
  if ( (_S2_45 & 1) == 0 )
  {
    _S2_45 |= 1u;
    nameHolder_83.m_pszBase = "CBaseAnimating";
    nameHolder_83.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_83.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_83.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_83.m_Names.m_Size = 0;
    nameHolder_83.m_Names.m_pElements = nullptr;
    nameHolder_83.m_nLenBase = 14;
    atexit(func: DataMapInit_CBaseAnimating__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseAnimating::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_45 & 2) == 0 )
  {
    _S2_45 |= 2u;
    dataDesc_80[36].pSaveRestoreOps = eventFuncs;
    dataDesc_80[37].fieldSize = 1;
    dataDesc_80[38].fieldSize = 1;
    *(_QWORD *)dataDesc_80[37].flatOffset = 0;
    dataDesc_80[37].flags = 2;
    dataDesc_80[38].flags = 2;
    *(_QWORD *)dataDesc_80[38].flatOffset = 0;
    dataDesc_80[37].fieldSizeInBytes = 4;
    dataDesc_80[38].fieldSizeInBytes = 4;
    dataDesc_80[39].fieldSize = 1;
    dataDesc_80[39].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_80[36].inputFunc = 0;
    *(_QWORD *)&dataDesc_80[36].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_80[36].override_count = 0;
    *(_QWORD *)dataDesc_80[36].flatOffset = 0;
    *(_QWORD *)dataDesc_80[39].flatOffset = 0;
    *(_DWORD *)&dataDesc_80[36].flatGroup = 0;
    dataDesc_80[37].fieldType = FIELD_FLOAT;
    dataDesc_80[37].fieldName = "m_flFrozen";
    dataDesc_80[37].fieldOffset = 1100;
    dataDesc_80[37].externalName = nullptr;
    dataDesc_80[37].pSaveRestoreOps = nullptr;
    dataDesc_80[37].inputFunc = nullptr;
    dataDesc_80[37].td = nullptr;
    dataDesc_80[37].override_field = nullptr;
    dataDesc_80[37].override_count = 0;
    dataDesc_80[37].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_80[37].flatGroup = 0;
    dataDesc_80[38].fieldType = FIELD_FLOAT;
    dataDesc_80[38].fieldName = "m_flFrozenThawRate";
    dataDesc_80[38].fieldOffset = 1112;
    dataDesc_80[38].externalName = nullptr;
    dataDesc_80[38].pSaveRestoreOps = nullptr;
    dataDesc_80[38].inputFunc = nullptr;
    dataDesc_80[38].td = nullptr;
    dataDesc_80[38].override_field = nullptr;
    dataDesc_80[38].override_count = 0;
    dataDesc_80[38].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_80[38].flatGroup = 0;
    dataDesc_80[39].fieldType = FIELD_FLOAT;
    dataDesc_80[39].fieldName = "m_flFrozenMax";
    dataDesc_80[39].fieldOffset = 1116;
    dataDesc_80[39].flags = 2;
    dataDesc_80[39].externalName = nullptr;
    dataDesc_80[39].pSaveRestoreOps = nullptr;
    dataDesc_80[39].inputFunc = nullptr;
    dataDesc_80[39].td = nullptr;
    dataDesc_80[39].override_field = nullptr;
    dataDesc_80[39].override_count = 0;
    dataDesc_80[39].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_80[39].flatGroup = 0;
    dataDesc_80[40].fieldType = FIELD_SHORT;
    dataDesc_80[40].fieldName = "m_fBoneCacheFlags";
    dataDesc_80[40].fieldOffset = 1096;
    *(_DWORD *)&dataDesc_80[40].fieldSize = 131073;
    dataDesc_80[40].externalName = nullptr;
    dataDesc_80[40].pSaveRestoreOps = nullptr;
    dataDesc_80[40].inputFunc = nullptr;
    dataDesc_80[40].td = nullptr;
    dataDesc_80[40].fieldSizeInBytes = 2;
    dataDesc_80[40].override_field = nullptr;
    dataDesc_80[40].override_count = 0;
    dataDesc_80[40].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_80[40].flatOffset = 0;
    *(_DWORD *)&dataDesc_80[40].flatGroup = 0;
    dataDesc_80[41].fieldTolerance = 0.0;
    dataDesc_80[41].fieldType = FIELD_BOOLEAN;
    dataDesc_80[41].fieldName = "m_bSuppressAnimSounds";
    dataDesc_80[41].fieldOffset = 1072;
    dataDesc_80[41].fieldSize = 1;
    dataDesc_80[41].flags = 6;
    dataDesc_80[41].externalName = "SuppressAnimSounds";
    dataDesc_80[41].pSaveRestoreOps = nullptr;
    dataDesc_80[41].inputFunc = nullptr;
    dataDesc_80[41].td = nullptr;
    dataDesc_80[41].fieldSizeInBytes = 1;
    dataDesc_80[41].override_field = nullptr;
    dataDesc_80[41].override_count = 0;
    *(_QWORD *)dataDesc_80[41].flatOffset = 0;
    *(_DWORD *)&dataDesc_80[41].flatGroup = 0;
  }
  CBaseAnimating::m_DataMap.dataNumFields = 41;
  CBaseAnimating::m_DataMap.dataDesc = &dataDesc_80[1];
  return &CBaseAnimating::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017D3E0
// Name: class CPathCorner __near * _CreateEntityTemplate<class CPathCorner>(class CPathCorner __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPathCorner *__cdecl _CreateEntityTemplate<CPathCorner>(CPathCorner *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPathCorner::`vftable';
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPathCorner *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D450
// Name: class CPathCornerCrash __near * _CreateEntityTemplate<class CPathCornerCrash>(class CPathCornerCrash __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPathCornerCrash *__cdecl _CreateEntityTemplate<CPathCornerCrash>(CPathCornerCrash *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[214] = 0;
    v3[217] = -1;
    v3[218] = 0;
    *v3 = &CPathCornerCrash::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPathCornerCrash *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF1D0
// Name: _dynamic_initializer_for__g_CBaseAnimating_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseAnimating_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseAnimating_ClassReg,
           pNetworkName: "CBaseAnimating",
           pTable: &DT_BaseAnimating::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF220
// Name: _dynamic_initializer_for__g_CBaseAnimating_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CBaseAnimating_ScriptDesc__()
{
  InitCBaseAnimatingScriptDesc();
  g_CBaseAnimating_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CBaseAnimating_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CBaseAnimating_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF250
// Name: _dynamic_initializer_for__npc_height_adjust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__npc_height_adjust__()
{
  ConVar::ConVar(
    this: &npc_height_adjust,
    pName: "npc_height_adjust",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Enable test mode for ik height adjustment");
  return atexit(func: dynamic_atexit_destructor_for__npc_height_adjust__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF280
// Name: _dynamic_initializer_for__sv_pvsskipanimation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pvsskipanimation__()
{
  ConVar::ConVar(
    this: &sv_pvsskipanimation,
    pName: "sv_pvsskipanimation",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Skips SetupBones when npc's are outside the PVS");
  return atexit(func: dynamic_atexit_destructor_for__sv_pvsskipanimation__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF2B0
// Name: _dynamic_initializer_for__ai_setupbones_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_setupbones_debug__()
{
  ConVar::ConVar(
    this: &ai_setupbones_debug,
    pName: "ai_setupbones_debug",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Shows that bones that are setup every think");
  return atexit(func: dynamic_atexit_destructor_for__ai_setupbones_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x104196A0
// Name: _ServerClassInit_DT_BaseAnimating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseAnimating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_9;
  for ( i = 23; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104196C0
// Name: _dynamic_atexit_destructor_for__npc_height_adjust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__npc_height_adjust__()
{
  ConVar::~ConVar(this: &npc_height_adjust);
}

//------------------------------------------------------------------------------
// Address: 0x104196D0
// Name: _dynamic_atexit_destructor_for__sv_pvsskipanimation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pvsskipanimation__()
{
  ConVar::~ConVar(this: &sv_pvsskipanimation);
}

//------------------------------------------------------------------------------
// Address: 0x104196E0
// Name: _dynamic_atexit_destructor_for__ai_setupbones_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_setupbones_debug__()
{
  ConVar::~ConVar(this: &ai_setupbones_debug);
}

//------------------------------------------------------------------------------
// Address: 0x104196F0
// Name: _ServerClassInit_DT_ServerAnimationData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ServerAnimationData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_21;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419710
// Name: _DataMapInit_CBaseAnimating__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseAnimating__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_83);
}

//------------------------------------------------------------------------------
// Address: 0x10419720
// Name: _dynamic_atexit_destructor_for__g_CBaseAnimating_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CBaseAnimating_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CBaseAnimating_ScriptDesc.m_FunctionBindings);
}
