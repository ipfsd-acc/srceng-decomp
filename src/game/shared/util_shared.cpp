// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/util_shared.cpp
// Functions: 108
// ============================================================

#include "game\shared\util_shared.h"

//------------------------------------------------------------------------------
// Address: 0x10130110
// Name: private: float CountdownTimer::Now(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CountdownTimer::Now(CEffectsClient *this)
{
  return *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x1017D550
// Name: void UTIL_StringToFloatArray(float __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_StringToFloatArray(float *pVector, int count, const char *pString)
{
  char *v3; // eax
  int v4; // ebx
  char *i; // esi
  long double v6; // st7
  char v7; // al
  char v8; // al
  int v9; // ebx
  char tempString[128]; // [esp+Ch] [ebp-80h] BYREF

  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v3 = tempString;
  v4 = 0;
  for ( i = tempString; v4 < count; v3 = i )
  {
    v6 = atof(nptr: v3);
    v7 = *i;
    pVector[v4] = v6;
    if ( v7 == 0 )
      break;
    while ( v7 <= 32 )
    {
      v7 = *++i;
      if ( v7 == 0 )
        goto LABEL_12;
    }
    v8 = *i;
    if ( *i == 0 )
      break;
    while ( v8 > 32 )
    {
      v8 = *++i;
      if ( v8 == 0 )
        goto LABEL_12;
    }
    if ( *i == 0 )
      break;
    ++i;
    ++v4;
  }
LABEL_12:
  v9 = v4 + 1;
  if ( v9 < count )
    memset(&pVector[v9], 0, 4 * (count - v9));
}

//------------------------------------------------------------------------------
// Address: 0x1017D5F0
// Name: void UTIL_StringToVector(float __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_StringToVector(float *pVector, const char *pString)
{
  UTIL_StringToFloatArray(pVector, count: 3, pString);
}

//------------------------------------------------------------------------------
// Address: 0x1017D610
// Name: void UTIL_DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_DecodeICE(unsigned __int8 *buffer, int size, const unsigned __int8 *key)
{
  signed int Filter; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  unsigned __int8 *v6; // eax
  int v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  unsigned __int8 *temp; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  int bytesLeft; // [esp+30h] [ebp+10h]

  if ( key != nullptr )
  {
    IceKey::IceKey(this: &ice, n: 0);
    IceKey::set(this: &ice, key);
    Filter = C_INIT_CreationNoise::GetFilter(this: (CParticleOperatorDefinition<C_OP_RemapCPtoScalar> *)&ice);
    v4 = alloca(Filter * ((Filter + size - 1) / Filter));
    v5 = buffer;
    v6 = v8;
    temp = v8;
    bytesLeft = size;
    if ( size >= Filter )
    {
      v7 = v8 - buffer;
      for ( i = v8 - buffer; ; v7 = i )
      {
        IceKey::decrypt(this: &ice, ctext: v5, ptext: &v5[v7]);
        v5 += Filter;
        bytesLeft -= Filter;
        if ( bytesLeft < Filter )
          break;
      }
      v5 = buffer;
      v6 = temp;
    }
    _V_memcpy(dest: v5, src: v6, count: size - bytesLeft);
    IceKey::~IceKey(this: &ice);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D7A0
// Name: public: virtual struct datamap_t __near * CountdownTimer::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CountdownTimer::GetPredDescMap(CountdownTimer *this)
{
  return &CountdownTimer::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017D7B0
// Name: unsigned short UTIL_GetAchievementEventMask(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl UTIL_GetAchievementEventMask()
{
  const char *v0; // eax
  int v1; // eax
  char lowercase[256]; // [esp+0h] [ebp-104h] BYREF
  unsigned int mapCRC; // [esp+100h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &mapCRC);
  v0 = engine->GetLevelName(this: engine);
  V_FileBase(in: v0, out: lowercase, maxlen: 256);
  _V_strlower(start: lowercase);
  v1 = _V_strlen(str: lowercase);
  CRC32_ProcessBuffer(pulCRC: &mapCRC, pBuffer: lowercase, nBuffer: v1);
  CRC32_Final(pulCRC: &mapCRC);
  return mapCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1017D830
// Name: char __near * ReadAndAllocStringValue(class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ReadAndAllocStringValue(KeyValues *pSub, const char *pName, const char *pFilename)
{
  const char *String; // eax
  char *v4; // edi
  int v6; // esi
  char *v7; // ebx

  String = KeyValues::GetString(this: pSub, keyName: pName, defaultValue: nullptr);
  v4 = (char *)String;
  if ( String != nullptr )
  {
    v6 = _V_strlen(str: String) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    V_strncpy(pDest: v7, pSrc: v4, maxLen: v6);
    return v7;
  }
  else
  {
    if ( pFilename != nullptr )
      DevWarning(a1: "Can't get key value\t'%s' from file '%s'.\n", pName, pFilename);
    return (char *)prType;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D890
// Name: int UTIL_CountNumBitsSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_CountNumBitsSet(unsigned int nVar)
{
  unsigned int v1; // ecx
  int result; // eax
  int v3; // edx

  v1 = nVar;
  for ( result = 0; v1 != 0; result += v3 )
  {
    v3 = s_NumBitsInNibble[v1 & 0xF];
    v1 >>= 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D8C0
// Name: bool UTIL_GetModDir(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_GetModDir(char *lpszTextOut, unsigned int nSize)
{
  int v2; // ecx
  int v3; // eax
  const char *v4; // ebx
  int v6; // edi
  int v7; // eax

  v3 = _CommandLine(a1: v2);
  v4 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v3 + 32))(
                       a1: v3,
                       a2: "-game",
                       a3: "hl2");
  if ( strlen(v4) > nSize )
    return 0;
  V_strncpy(pDest: lpszTextOut, pSrc: v4, maxLen: nSize);
  if ( V_strnchr(pStr: lpszTextOut, c: 47, n: nSize) != nullptr
    || V_strnchr(pStr: lpszTextOut, c: 92, n: nSize) != nullptr )
  {
    V_StripLastDir(dirName: lpszTextOut, maxlen: nSize);
    v6 = _V_strlen(str: lpszTextOut);
    v7 = _V_strlen(str: v4);
    V_strncpy(pDest: lpszTextOut, pSrc: &v4[v6], maxLen: 1 - v6 + v7);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017D960
// Name: class Vector UTIL_YawToVector(float)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl UTIL_YawToVector(Vector *result, float yaw)
{
  result->z = 0.0;
  result->x = cos((float)(yaw * 0.017453292));
  result->y = sin((float)(yaw * 0.017453292));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D9A0
// Name: float SharedRandomFloat(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
float __cdecl SharedRandomFloat(char *sharedname, float flMinVal, float flMaxVal, int additionalSeed)
{
  int v4; // eax
  IUniformRandomStream *v5; // ecx
  int v8; // [esp+Ch] [ebp-8h] BYREF
  int pBuffer; // [esp+10h] [ebp-4h] BYREF

  v8 = additionalSeed;
  pBuffer = C_BaseEntity::m_nPredictionRandomSeed;
  CRC32_Init(pulCRC: (unsigned int *)&additionalSeed);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, &pBuffer, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: &v8, nBuffer: 4);
  v4 = _V_strlen(str: sharedname);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: sharedname, nBuffer: v4);
  CRC32_Final(pulCRC: (unsigned int *)&additionalSeed);
  _RandomSeed(a1: additionalSeed);
  return _RandomFloat(this: v5, a2: flMinVal, a3: flMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x1017DA30
// Name: int SharedRandomInt(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SharedRandomInt(char *sharedname, int iMinVal, IUniformRandomStream *iMaxVal, int additionalSeed)
{
  int v4; // eax
  int v6; // [esp+4h] [ebp-8h] BYREF
  int pBuffer; // [esp+8h] [ebp-4h] BYREF

  v6 = additionalSeed;
  pBuffer = C_BaseEntity::m_nPredictionRandomSeed;
  CRC32_Init(pulCRC: (unsigned int *)&additionalSeed);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, &pBuffer, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: &v6, nBuffer: 4);
  v4 = _V_strlen(str: sharedname);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: sharedname, nBuffer: v4);
  CRC32_Final(pulCRC: (unsigned int *)&additionalSeed);
  _RandomSeed(a1: additionalSeed);
  return _RandomInt(this: iMaxVal, a2: iMinVal, a3: (int)iMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x1017DAB0
// Name: void UTIL_Tracer(class Vector const __near &,class Vector const __near &,int,int,float,bool,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_Tracer(
        const Vector *vecStart,
        const Vector *vecEnd,
        int iEntIndex,
        int iAttachment,
        float flVelocity,
        bool bWhiz,
        const char *pCustomTracerName,
        int iParticleID)
{
  float z; // xmm0_4
  unsigned int v9; // eax
  int v10; // eax
  CEffectData data; // [esp+4h] [ebp-64h] BYREF
  int vecStarta; // [esp+70h] [ebp+8h]

  memset((void *)&data.m_vNormal, 0, 28);
  memset(&data.m_flMagnitude, 0, 14);
  data.m_vStart = *vecStart;
  data.m_vOrigin.x = vecEnd->x;
  data.m_vOrigin.y = vecEnd->y;
  z = vecEnd->z;
  data.m_hEntity.m_Index = -1;
  data.m_flScale = 1.0;
  memset(&data.m_nMaterial, 0, 17);
  data.m_vOrigin.z = z;
  if ( iEntIndex >= -1 )
  {
    if ( iEntIndex >= 0 && (v10 = *(_DWORD *)(cl_entitylist.m_Index + 16 * iEntIndex + 4)) != 0 )
      vecStarta = *(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
    else
      vecStarta = -1;
    v9 = vecStarta;
  }
  else
  {
    v9 = -1;
  }
  data.m_hEntity.m_Index = v9;
  data.m_flScale = flVelocity;
  data.m_nHitBox = iParticleID;
  if ( bWhiz )
    data.m_fFlags |= 1u;
  if ( iAttachment != -1 )
  {
    data.m_fFlags |= 2u;
    data.m_nAttachmentIndex = iAttachment;
  }
  if ( pCustomTracerName != nullptr )
    DispatchEffect(pName: pCustomTracerName, &data);
  else
    DispatchEffect(pName: "Tracer", &data);
}

//------------------------------------------------------------------------------
// Address: 0x1017DBF0
// Name: void UTIL_BloodImpact(class Vector const __near &,class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodImpact(const Vector *pos, const Vector *dir, unsigned __int8 color, int amount)
{
  CEffectData data; // [esp+0h] [ebp-64h] BYREF

  memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
  memset((void *)&data.m_vAngles, 0, 16);
  memset(&data.m_flMagnitude, 0, 14);
  memset(&data.m_nMaterial, 0, 16);
  data.m_vOrigin = *pos;
  data.m_vNormal = *dir;
  data.m_hEntity.m_Index = -1;
  data.m_flScale = (float)amount;
  data.m_nColor = color;
  DispatchEffect(pName: "bloodimpact", &data);
}

//------------------------------------------------------------------------------
// Address: 0x1017DCB0
// Name: class C_BasePlayer __near * UTIL_PlayerByIndex(int)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__cdecl UTIL_PlayerByIndex(int entindex)
{
  C_BaseEntity *BaseEntity; // eax
  C_BaseEntity *v2; // esi

  if ( entindex < 1 || entindex > *(_DWORD *)(gpGlobals.m_Index + 20) )
    return nullptr;
  BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: entindex);
  v2 = BaseEntity;
  if ( BaseEntity != nullptr && BaseEntity->IsPlayer(this: BaseEntity) )
    return (C_BasePlayer *)v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017DD00
// Name: public: CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(class C_BaseEntity __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CFlaggedEntitiesEnum *__thiscall CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(
        CFlaggedEntitiesEnum *this,
        C_BaseEntity **pList,
        int listMax,
        int flagMask)
{
  this->m_pList = pList;
  this->__vftable = (CFlaggedEntitiesEnum_vtbl *)&CFlaggedEntitiesEnum::`vftable';
  this->m_listMax = listMax;
  this->m_flagMask = flagMask;
  this->m_count = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017DD30
// Name: public: virtual enum IterationRetval_t CFlaggedEntitiesEnum::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFlaggedEntitiesEnum::EnumElement(CFlaggedEntitiesEnum *this, IHandleEntity *pHandleEntity)
{
  const CBaseHandle *v3; // eax
  int v4; // eax
  C_BaseEntity *v5; // eax
  int m_flagMask; // ecx
  int m_count; // ecx

  v3 = pHandleEntity->GetRefEHandle(this: pHandleEntity);
  v4 = (*(int (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 16))(
         a1: cl_entitylist.m_Index + 131092,
         a2: v3->m_Index);
  if ( v4 == 0 )
    return 0;
  v5 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 28))(a1: v4);
  if ( v5 == nullptr )
    return 0;
  m_flagMask = this->m_flagMask;
  if ( m_flagMask != 0 && (m_flagMask & v5->m_fFlags) == 0 )
    return 0;
  m_count = this->m_count;
  if ( m_count < this->m_listMax )
  {
    this->m_pList[m_count] = v5;
    ++this->m_count;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017DDA0
// Name: bool PassServerEntityFilter(class IHandleEntity const __near *,class IHandleEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PassServerEntityFilter(const IHandleEntity *pTouch, const IHandleEntity *pPass)
{
  C_BaseEntity *v3; // edi
  C_BaseEntity *v4; // eax
  C_BaseEntity *v5; // esi

  if ( pPass == nullptr )
    return true;
  if ( pTouch == pPass )
    return false;
  v3 = (C_BaseEntity *)((int (__thiscall *)(const IHandleEntity *))pTouch->__vftable[2].SetRefEHandle)(a1: pTouch);
  v4 = (C_BaseEntity *)((int (__thiscall *)(const IHandleEntity *))pPass->__vftable[2].SetRefEHandle)(a1: pPass);
  v5 = v4;
  if ( v3 == nullptr || v4 == nullptr )
    return true;
  if ( C_BaseEntity::GetOwnerEntity(this: v3) == v4 )
    return false;
  return C_BaseEntity::GetOwnerEntity(this: v5) != v3;
}

//------------------------------------------------------------------------------
// Address: 0x1017DE00
// Name: bool StandardFilterRules(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __usercall StandardFilterRules@<al>(int a1@<esi>, IHandleEntity *pHandleEntity, int fContentsMask)
{
  C_BaseEntity *v3; // edi
  int v5; // ebx
  const struct model_t *v6; // eax
  __int16 v7; // bx
  C_BaseEntity *OwnerEntity; // eax

  v3 = (C_BaseEntity *)((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].SetRefEHandle)(a1: pHandleEntity);
  if ( v3 == nullptr )
    return true;
  v5 = v3->GetSolid(this: v3);
  v6 = v3->GetModel(this: &v3->IClientRenderable);
  if ( modelinfo->GetModelType(this: modelinfo, a2: v6) == 1 && (v5 == 1 || v5 == 6) )
  {
    v7 = fContentsMask;
  }
  else
  {
    v7 = fContentsMask;
    if ( (fContentsMask & 0x2000000) == 0 )
      return false;
  }
  if ( (v7 & 2) == 0 )
  {
    if ( *(_WORD *)((int (__thiscall *)(IClientRenderable *, int))v3->RenderHandle)(a1: &v3->IClientRenderable, a2: a1) == 0xFFFF )
    {
      OwnerEntity = C_BaseEntity::GetOwnerEntity(this: v3);
      if ( OwnerEntity != nullptr )
        OwnerEntity->RenderHandle(this: &OwnerEntity->IClientRenderable);
    }
    if ( ((int (__thiscall *)(IClientLeafSystem *))g_pClientLeafSystem->GetTranslucencyType)(a1: g_pClientLeafSystem) == 1 )
      return false;
  }
  return (v7 & 0x4000) != 0 || v3->m_MoveType != 7;
}

//------------------------------------------------------------------------------
// Address: 0x1017DED0
// Name: public: CTraceFilterSimple::CTraceFilterSimple(class IHandleEntity const __near *,int,bool (*)(class IHandleEntity __near *,int))
// Source: json
//------------------------------------------------------------------------------
CTraceFilterSimple *__thiscall CTraceFilterSimple::CTraceFilterSimple(
        CTraceFilterSimple *this,
        const IHandleEntity *passedict,
        int collisionGroup,
        bool (__cdecl *pExtraShouldHitFunc)(IHandleEntity *, int))
{
  this->m_pPassEnt = passedict;
  this->__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterSimple::`vftable';
  this->m_collisionGroup = collisionGroup;
  this->m_pExtraShouldHitCheckFunction = pExtraShouldHitFunc;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017DF00
// Name: public: virtual bool CTraceFilterSimple::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CTraceFilterSimple::ShouldHitEntity@<al>(
        CTraceFilterSimple *this@<ecx>,
        int a2@<esi>,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  bool result; // al
  int *v6; // esi
  bool (__cdecl *m_pExtraShouldHitCheckFunction)(IHandleEntity *, int); // edi

  if ( !StandardFilterRules(a1: a2, pHandleEntity, fContentsMask: contentsMask)
    || this->m_pPassEnt != nullptr && !PassServerEntityFilter(pTouch: pHandleEntity, pPass: this->m_pPassEnt) )
  {
    return false;
  }
  v6 = (int *)((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].SetRefEHandle)(a1: pHandleEntity);
  result = false;
  if ( v6 != nullptr
    && (*(unsigned __int8 (__thiscall **)(int *, int, int))(*v6 + 640))(
         a1: v6,
         a2: this->m_collisionGroup,
         a3: contentsMask) != 0
    && g_pGameRules->ShouldCollide(this: g_pGameRules, a2: this->m_collisionGroup, a3: v6[281]) )
  {
    m_pExtraShouldHitCheckFunction = this->m_pExtraShouldHitCheckFunction;
    if ( m_pExtraShouldHitCheckFunction == nullptr
      || m_pExtraShouldHitCheckFunction(a1: pHandleEntity, a2: contentsMask) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017DFB0
// Name: public: virtual bool CTraceFilterNoNPCsOrPlayer::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterNoNPCsOrPlayer::ShouldHitEntity(
        CTraceFilterNoNPCsOrPlayer *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  int v3; // eax
  int v4; // esi

  if ( !CTraceFilterSimple::ShouldHitEntity(this, a2: (int)pHandleEntity, pHandleEntity, contentsMask) )
    return false;
  v3 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].SetRefEHandle)(a1: pHandleEntity);
  v4 = v3;
  if ( v3 == 0 )
    return false;
  return (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 596))(a1: v3) == 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 584))(a1: v4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017E010
// Name: public: CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(class IHandleEntity const __near *,class IHandleEntity const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterSkipTwoEntities *__thiscall CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
        CTraceFilterSkipTwoEntities *this,
        const IHandleEntity *passentity,
        const IHandleEntity *passentity2,
        int collisionGroup)
{
  this->m_pPassEnt = passentity;
  this->m_collisionGroup = collisionGroup;
  this->m_pExtraShouldHitCheckFunction = nullptr;
  this->__vftable = (CTraceFilterSkipTwoEntities_vtbl *)&CTraceFilterSkipTwoEntities::`vftable';
  this->m_pPassEnt2 = passentity2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017E040
// Name: public: virtual bool CTraceFilterSkipTwoEntities::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterSkipTwoEntities::ShouldHitEntity(
        CTraceFilterSkipTwoEntities *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  bool result; // al

  result = PassServerEntityFilter(pTouch: pHandleEntity, pPass: this->m_pPassEnt2);
  if ( result )
    return CTraceFilterSimple::ShouldHitEntity(this, a2: (int)this, pHandleEntity, contentsMask);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E080
// Name: void UTIL_TraceModel(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class C_BaseEntity __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceModel(
        int a1@<ebp>,
        const Vector *vecStart,
        const Vector *vecEnd,
        const Vector *hullMin,
        const Vector *hullMax,
        C_BaseEntity *pentModel,
        int collisionGroup,
        CGameTrace *ptr)
{
  _BYTE v8[12]; // [esp-Ch] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  if ( pentModel != nullptr && pentModel->ShouldCollide(this: pentModel, a2: collisionGroup, a3: -1) )
  {
    ray.m_Extents.y = 0.0;
    Ray_t::Init(this: (Ray_t *)v8, start: vecStart, end: vecEnd, mins: hullMin, maxs: hullMax);
    enginetrace->ClipRayToEntity(this: enginetrace, a2: (const Ray_t *)v8, a3: -1u, a4: pentModel, a5: ptr);
  }
  else
  {
    memset(dst: (int)ptr, value: nullptr, count: sizeof(CGameTrace));
    ptr->fraction = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E120
// Name: bool UTIL_EntityHasMatchingRootParent(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_EntityHasMatchingRootParent(C_BaseEntity *pRootParent, C_BaseEntity *pEntity)
{
  bool result; // al
  unsigned int m_Index; // ecx
  C_BaseEntity *OwnerEntity; // eax

  result = false;
  if ( pRootParent != nullptr )
  {
    if ( pRootParent == C_BaseEntity::GetRootMoveParent(this: pEntity) )
      return true;
    m_Index = pEntity->m_hOwnerEntity.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      OwnerEntity = C_BaseEntity::GetOwnerEntity(this: pEntity);
      if ( pRootParent == C_BaseEntity::GetRootMoveParent(this: OwnerEntity) )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E190
// Name: public: virtual bool CTraceFilterEntity::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterEntity::ShouldHitEntity(
        CTraceFilterEntity *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  C_BaseEntity *v4; // edi

  v4 = (C_BaseEntity *)((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].SetRefEHandle)(a1: pHandleEntity);
  return v4 != nullptr
      && !UTIL_EntityHasMatchingRootParent(pRootParent: this->m_pRootParent, pEntity: v4)
      && (!this->m_checkHash
       || !g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: this->m_pEntity, a3: v4))
      && CTraceFilterSimple::ShouldHitEntity(this, a2: (int)this, pHandleEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x1017E200
// Name: public: virtual bool CTraceFilterEntityIgnoreOther::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterEntityIgnoreOther::ShouldHitEntity(
        CTraceFilterEntityIgnoreOther *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  return pHandleEntity != this->m_pIgnoreOther && CTraceFilterEntity::ShouldHitEntity(this, pHandleEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x1017E220
// Name: void UTIL_TraceEntity(class C_BaseEntity __near *,class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_TraceEntity(
        C_BaseEntity *pEntity,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        const IHandleEntity *pIgnore,
        int nCollisionGroup,
        CGameTrace *ptr)
{
  ICollideable *v7; // edi
  IEngineTrace_vtbl *v8; // esi
  int v9; // eax
  CTraceFilterEntityIgnoreOther traceFilter; // [esp+8h] [ebp-20h] BYREF

  v7 = pEntity->GetCollideable(this: pEntity);
  traceFilter.m_pPassEnt = pEntity;
  traceFilter.m_collisionGroup = nCollisionGroup;
  traceFilter.m_pExtraShouldHitCheckFunction = nullptr;
  traceFilter.__vftable = (CTraceFilterEntityIgnoreOther_vtbl *)&CTraceFilterEntity::`vftable';
  traceFilter.m_pRootParent = C_BaseEntity::GetRootMoveParent(this: pEntity);
  traceFilter.m_pEntity = pEntity;
  traceFilter.m_checkHash = g_EntityCollisionHash->IsObjectInHash(this: g_EntityCollisionHash, a2: pEntity);
  traceFilter.m_pIgnoreOther = pIgnore;
  traceFilter.__vftable = (CTraceFilterEntityIgnoreOther_vtbl *)&CTraceFilterEntityIgnoreOther::`vftable';
  v8 = enginetrace->__vftable;
  v9 = ((int (__thiscall *)(ICollideable *, unsigned int, CTraceFilterEntityIgnoreOther *, CGameTrace *))v7->GetCollisionAngles)(
         a1: v7,
         a2: mask,
         a3: &traceFilter,
         a4: ptr);
  ((void (__thiscall *)(IEngineTrace *, ICollideable *, const Vector *, const Vector *, int))v8->SweepCollideable)(
    a1: enginetrace,
    a2: v7,
    a3: vecAbsStart,
    a4: vecAbsEnd,
    a5: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1017E2B0
// Name: void UTIL_ParticleTracer(char const __near *,class Vector const __near &,class Vector const __near &,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ParticleTracer(
        const char *pszTracerEffectName,
        const Vector *vecStart,
        const Vector *vecEnd,
        int iEntIndex,
        int iAttachment,
        bool bWhiz)
{
  int ParticleSystemIndex; // eax

  ParticleSystemIndex = GetParticleSystemIndex(pParticleSystemName: pszTracerEffectName);
  UTIL_Tracer(
    vecStart,
    vecEnd,
    iEntIndex,
    iAttachment,
    flVelocity: 0.0,
    bWhiz,
    pCustomTracerName: "ParticleTracer",
    iParticleID: ParticleSystemIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1017E2F0
// Name: bool UTIL_IsLowViolence(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_IsLowViolence()
{
  return violence_hblood.m_pParent == nullptr
      || violence_hblood.m_pParent->m_Value.m_nValue == 0
      || violence_ablood.m_pParent == nullptr
      || violence_ablood.m_pParent->m_Value.m_nValue == 0
      || violence_hgibs.m_pParent == nullptr
      || violence_hgibs.m_pParent->m_Value.m_nValue == 0
      || violence_agibs.m_pParent == nullptr
      || violence_agibs.m_pParent->m_Value.m_nValue == 0
      || engine->IsLowViolence(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x1017E340
// Name: void UTIL_BloodDecalTrace(class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodDecalTrace(CGameTrace *pTrace, int bloodColor)
{
  int m_nValue; // eax
  float fraction; // xmm0_4
  struct CBaseEntity *v4; // ecx
  struct CBaseEntity *m_pEnt; // ecx
  struct CBaseEntity *v6; // ecx

  if ( bloodColor == -1 )
    return;
  if ( bloodColor != 0 )
  {
    if ( violence_ablood.m_pParent != nullptr )
    {
      m_nValue = violence_ablood.m_pParent->m_Value.m_nValue;
      goto LABEL_8;
    }
  }
  else if ( violence_hblood.m_pParent != nullptr )
  {
    m_nValue = violence_hblood.m_pParent->m_Value.m_nValue;
    goto LABEL_8;
  }
  m_nValue = 0;
LABEL_8:
  if ( m_nValue != 0 )
  {
    fraction = pTrace->fraction;
    if ( bloodColor != 0 )
    {
      if ( bloodColor == 4 )
      {
        if ( fraction != 1.0 )
        {
          m_pEnt = pTrace->m_pEnt;
          if ( m_pEnt != nullptr )
            (*(void (__thiscall **)(struct CBaseEntity *, CGameTrace *, const char *))(*(_DWORD *)m_pEnt + 516))(
              a1: m_pEnt,
              a2: pTrace,
              a3: "GreenBlood");
        }
      }
      else if ( fraction != 1.0 )
      {
        v6 = pTrace->m_pEnt;
        if ( v6 != nullptr )
          (*(void (__thiscall **)(struct CBaseEntity *, CGameTrace *, const char *))(*(_DWORD *)v6 + 516))(
            a1: v6,
            a2: pTrace,
            a3: "YellowBlood");
      }
    }
    else if ( fraction != 1.0 )
    {
      v4 = pTrace->m_pEnt;
      if ( v4 != nullptr )
        (*(void (__thiscall **)(struct CBaseEntity *, CGameTrace *, const char *))(*(_DWORD *)v4 + 516))(
          a1: v4,
          a2: pTrace,
          a3: "Blood");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E580
// Name: public: virtual bool CTraceFilterSimpleList::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CTraceFilterSimpleList::ShouldHitEntity@<al>(
        CTraceFilterSimpleList *this@<ecx>,
        IHandleEntity **m_pMemory@<esi>,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  int m_Size; // edx
  int v5; // eax

  m_Size = this->m_PassEntities.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return CTraceFilterSimple::ShouldHitEntity(this, a2: (int)m_pMemory, pHandleEntity, contentsMask);
  m_pMemory = this->m_PassEntities.m_Memory.m_pMemory;
  while ( *m_pMemory != pHandleEntity )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      return CTraceFilterSimple::ShouldHitEntity(this, a2: (int)m_pMemory, pHandleEntity, contentsMask);
  }
  return v5 == -1 && CTraceFilterSimple::ShouldHitEntity(this, a2: (int)m_pMemory, pHandleEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x1017E5C0
// Name: void UTIL_BloodDrips(class Vector const __near &,class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodDrips(const Vector *origin, const Vector *direction, int color, int amount)
{
  int m_nValue; // eax
  int v5; // esi
  float scale; // xmm0_4

  if ( color == -1 )
    return;
  if ( color != 0 )
  {
    if ( violence_ablood.m_pParent != nullptr )
    {
      m_nValue = violence_ablood.m_pParent->m_Value.m_nValue;
      goto LABEL_8;
    }
LABEL_7:
    m_nValue = 0;
    goto LABEL_8;
  }
  if ( violence_hblood.m_pParent == nullptr )
    goto LABEL_7;
  m_nValue = violence_hblood.m_pParent->m_Value.m_nValue;
LABEL_8:
  if ( m_nValue != 0 )
  {
    v5 = amount;
    if ( amount != 0 )
    {
      if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
        v5 = 5 * amount;
      if ( v5 > 255 )
        v5 = 255;
      if ( color == 3 )
      {
        g_pEffects->Sparks(this: g_pEffects, a2: origin, a3: 1, a4: 1, a5: nullptr);
        if ( ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
               a1: random,
               a2: 0,
               a3: 0x40000000) >= 1.0 )
        {
          scale = (float)random->RandomInt(this: random, a2: 10, a3: 15);
          UTIL_Smoke(origin, scale, framerate: 10.0);
        }
      }
      else
      {
        UTIL_BloodImpact(pos: origin, dir: direction, color, amount: v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E6F0
// Name: public: CTraceFilterSimpleList::CTraceFilterSimpleList(int)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterSimpleList *__thiscall CTraceFilterSimpleList::CTraceFilterSimpleList(
        CTraceFilterSimpleList *this,
        int collisionGroup)
{
  this->m_pPassEnt = nullptr;
  this->m_collisionGroup = collisionGroup;
  this->m_pExtraShouldHitCheckFunction = nullptr;
  this->__vftable = (CTraceFilterSimpleList_vtbl *)&CTraceFilterSimpleList::`vftable';
  this->m_PassEntities.m_Memory.m_pMemory = nullptr;
  this->m_PassEntities.m_Memory.m_nAllocationCount = 0;
  this->m_PassEntities.m_Memory.m_nGrowSize = 0;
  this->m_PassEntities.m_Size = 0;
  this->m_PassEntities.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017E720
// Name: void UTIL_ClipTraceToPlayers(class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall UTIL_ClipTraceToPlayers(
        int a1@<ebp>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        ITraceFilter *filter,
        CGameTrace *tr)
{
  float x; // xmm3_4
  int y_low; // xmm4_4
  float y; // xmm1_4
  float z; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  int v12; // eax
  int v13; // esi
  C_BaseEntity *BaseEntity; // eax
  IHandleEntity *v15; // edi
  float *v16; // esi
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  const Vector *v25; // eax
  float v26; // xmm1_4
  __int128 v27; // xmm0
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  _BYTE v32[12]; // [esp-Ch] [ebp-F4h] BYREF
  CGameTrace playerTrace; // [esp+0h] [ebp-E8h] BYREF
  float v34; // [esp+54h] [ebp-94h]
  Ray_t ray_4; // [esp+5Ch] [ebp-8Ch] OVERLAPPED BYREF
  float v36; // [esp+B8h] [ebp-30h]
  float v37; // [esp+BCh] [ebp-2Ch]
  float v38; // [esp+C0h] [ebp-28h]
  float v39; // [esp+C4h] [ebp-24h]
  Vector v40; // [esp+C8h] [ebp-20h] BYREF
  float fraction; // [esp+D4h] [ebp-14h]
  int v42; // [esp+D8h] [ebp-10h]
  int v43; // [esp+DCh] [ebp-Ch]
  float smallestFraction; // [esp+E0h] [ebp-8h]
  float retaddr; // [esp+E8h] [ebp+0h]

  v43 = a1;
  smallestFraction = retaddr;
  x = vecAbsStart->x;
  y_low = SLODWORD(vecAbsStart->y);
  y = vecAbsEnd->y;
  z = vecAbsStart->z;
  v10 = vecAbsEnd->z;
  fraction = tr->fraction;
  v11 = vecAbsEnd->x - x;
  ray_4.m_Start.y = y - *(float *)&y_low;
  ray_4.m_Start.x = v11;
  ray_4.m_Start.z = v10 - z;
  BYTE1(ray_4.m_Extents.y) = (float)((float)((float)(ray_4.m_Start.y * ray_4.m_Start.y) + (float)(v11 * v11))
                                   + (float)(ray_4.m_Start.z * ray_4.m_Start.z)) != 0.0;
  memset(&ray_4.m_StartOffset, 0, 12);
  ray_4.m_Extents.x = 0.0;
  LOBYTE(ray_4.m_Extents.y) = 1;
  memset(&ray_4.m_Delta, 0, 12);
  *(float *)&playerTrace.m_pEnt = x;
  playerTrace.hitbox = y_low;
  v34 = z;
  v12 = *(_DWORD *)(gpGlobals.m_Index + 20);
  v13 = 1;
  v42 = 1;
  if ( v12 >= 1 )
  {
    while ( 1 )
    {
      if ( v13 >= 1 && v13 <= v12 )
      {
        BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v13);
        v15 = BaseEntity;
        if ( BaseEntity != nullptr
          && BaseEntity->IsPlayer(this: BaseEntity)
          && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v15->__vftable[48].dtr_IHandleEntity)(a1: v15) != 0
          && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v15[2].__vftable[3].dtr_IHandleEntity)(a1: &v15[2]) == 0
          && (filter == nullptr || filter->ShouldHitEntity(this: filter, a2: v15, a3: mask) != 0) )
        {
          break;
        }
      }
LABEL_21:
      v12 = *(_DWORD *)(gpGlobals.m_Index + 20);
      v42 = ++v13;
      if ( v13 > v12 )
        return;
    }
    v16 = (float *)((int (__thiscall *)(IHandleEntity *))v15->__vftable[25].dtr_IHandleEntity)(a1: v15);
    v17 = vecAbsStart->x;
    v18 = v16[1];
    v19 = v16[2];
    v36 = *v16 - vecAbsStart->x;
    v20 = vecAbsStart->y;
    v37 = v18 - v20;
    v21 = vecAbsStart->z;
    v38 = v19 - v21;
    v22 = vecAbsEnd->x - v17;
    v40.y = vecAbsEnd->y - v20;
    v23 = vecAbsEnd->z - v21;
    v40.x = v22;
    v40.z = v23;
    v39 = VectorNormalize(vec: &v40);
    v24 = (float)((float)(v40.y * v37) + (float)(v40.x * v36)) + (float)(v40.z * v38);
    if ( v24 >= 0.0 )
    {
      if ( v24 <= v39 )
      {
        v28 = v40.y * v24;
        v29 = vecAbsStart->z + (float)(v24 * v40.z);
        v30 = *v16 - (float)(vecAbsStart->x + (float)(v40.x * v24));
        v31 = (float)((float)((float)(v16[1] - (float)(vecAbsStart->y + v28))
                            * (float)(v16[1] - (float)(vecAbsStart->y + v28)))
                    + (float)((float)(v16[2] - v29) * (float)(v16[2] - v29)))
            + (float)(v30 * v30);
        v27 = 0;
        *(float *)&v27 = fsqrt(v31);
        *(_OWORD *)&ray_4.m_pWorldAxisTransform = v27;
LABEL_16:
        if ( *(float *)&v27 >= 0.0 && *(float *)&v27 <= 60.0 )
        {
          enginetrace->ClipRayToEntity(
            this: enginetrace,
            a2: (const Ray_t *)&playerTrace.m_pEnt,
            a3: mask | 0x40000000,
            a4: v15,
            a5: (CGameTrace *)v32);
          if ( fraction > playerTrace.plane.normal.z )
          {
            CGameTrace::operator=(this: tr, __that: (const CGameTrace *)v32);
            fraction = playerTrace.plane.normal.z;
          }
        }
        v13 = v42;
        goto LABEL_21;
      }
      v25 = vecAbsEnd;
    }
    else
    {
      v25 = vecAbsStart;
    }
    v26 = v16[1] - v25->y;
    v27 = 0;
    *(float *)&v27 = fsqrt(
                       (float)((float)(v26 * v26) + (float)((float)(v16[2] - v25->z) * (float)(v16[2] - v25->z)))
                     + (float)((float)(*v16 - v25->x) * (float)(*v16 - v25->x)));
    *(_OWORD *)&ray_4.m_pWorldAxisTransform = v27;
    *(float *)&v27 = -*(float *)&v27;
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EAA0
// Name: public: void CTraceFilterSimpleList::AddEntityToIgnore(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceFilterSimpleList::AddEntityToIgnore(CTraceFilterSimpleList *this, IHandleEntity *pEntity)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_PassEntities; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_PassEntities.m_Memory.m_nAllocationCount;
  p_m_PassEntities = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PassEntities;
  m_Size = this->m_PassEntities.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_PassEntities, num: m_Size - m_nAllocationCount + 1);
  ++p_m_PassEntities[1].m_pMemory;
  m_pMemory = p_m_PassEntities->m_pMemory;
  v6 = (int)p_m_PassEntities[1].m_pMemory - m_Size - 1;
  p_m_PassEntities[1].m_nAllocationCount = (int)p_m_PassEntities->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_PassEntities->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1041D120
// Name: IntervalTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *IntervalTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<IntervalTimer>();
  IntervalTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D130
// Name: DT_IntervalTimer::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_IntervalTimer::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_IntervalTimer::g_RecvTable);
  return atexit(func: DT_IntervalTimer::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D150
// Name: DT_IntervalTimer::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_IntervalTimer::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_IntervalTimer::ignored>();
  DT_IntervalTimer::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D160
// Name: IntervalTimer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void IntervalTimer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  IntervalTimer::m_PredMap.dataNumFields = 1;
  IntervalTimer::m_PredMap.dataDesc = (typedescription_t *)&unk_105AB9F4;
}

//------------------------------------------------------------------------------
// Address: 0x1041D180
// Name: DT_CountdownTimer::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CountdownTimer::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CountdownTimer::g_RecvTable);
  return atexit(func: DT_CountdownTimer::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D1A0
// Name: DT_CountdownTimer::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CountdownTimer::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CountdownTimer::ignored>();
  DT_CountdownTimer::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D1B0
// Name: CountdownTimer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void CountdownTimer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  CountdownTimer::m_PredMap.dataNumFields = 2;
  CountdownTimer::m_PredMap.dataDesc = (typedescription_t *)&unk_105ABA6C;
}

//------------------------------------------------------------------------------
// Address: 0x1041D1D0
// Name: CTimeline_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTimeline_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTimeline>();
  CTimeline_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D1E0
// Name: DT_Timeline::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Timeline::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Timeline::g_RecvTable);
  return atexit(func: DT_Timeline::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D200
// Name: DT_Timeline::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Timeline::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Timeline::ignored>();
  DT_Timeline::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433E10
// Name: DT_IntervalTimer::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_IntervalTimer::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_IntervalTimer::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10433E20
// Name: DT_CountdownTimer::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CountdownTimer::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CountdownTimer::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10433E30
// Name: DT_Timeline::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Timeline::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Timeline::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1017EB00
// Name: struct datamap_t __near * DataMapInit<class IntervalTimer>(class IntervalTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<IntervalTimer>()
{
  if ( (_S6_44 & 1) == 0 )
  {
    _S6_44 |= 1u;
    nameHolder_33.m_pszBase = "IntervalTimer";
    nameHolder_33.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_33.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_33.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_33.m_Names.m_Size = 0;
    nameHolder_33.m_Names.m_pElements = nullptr;
    nameHolder_33.m_nLenBase = 13;
    atexit(func: DataMapInit_IntervalTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  IntervalTimer::m_DataMap.baseMap = nullptr;
  IntervalTimer::m_DataMap.dataNumFields = 1;
  IntervalTimer::m_DataMap.dataDesc = dataDesc_39;
  return &IntervalTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017EB80
// Name: struct datamap_t __near * DataMapInit<class CTimeline>(class CTimeline __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTimeline>()
{
  if ( (_S9_5 & 1) == 0 )
  {
    _S9_5 |= 1u;
    nameHolder_34.m_pszBase = "CTimeline";
    nameHolder_34.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_34.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_34.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_34.m_Names.m_Size = 0;
    nameHolder_34.m_Names.m_pElements = nullptr;
    nameHolder_34.m_nLenBase = 9;
    atexit(func: DataMapInit_CTimeline__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTimeline::m_DataMap.baseMap = &IntervalTimer::m_DataMap;
  CTimeline::m_DataMap.dataNumFields = 7;
  CTimeline::m_DataMap.dataDesc = &dataDesc_32[1];
  return &CTimeline::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10433E40
// Name: _DataMapInit_IntervalTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_IntervalTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_33);
}

//------------------------------------------------------------------------------
// Address: 0x10433E50
// Name: _DataMapInit_CTimeline__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTimeline__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_34);
}

//------------------------------------------------------------------------------
// Address: 0x10433E60
// Name: _DataMapInit_ViewSmoothingData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ViewSmoothingData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_35);
}

//------------------------------------------------------------------------------
// Address: 0x10433E70
// Name: _dynamic_atexit_destructor_for__scr_centertime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scr_centertime__()
{
  ConVar::~ConVar(this: &scr_centertime);
}

//------------------------------------------------------------------------------
// Address: 0x10433E80
// Name: _dynamic_atexit_destructor_for__cl_showfps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showfps__()
{
  ConVar::~ConVar(this: &cl_showfps);
}

//------------------------------------------------------------------------------
// Address: 0x10433E90
// Name: _dynamic_atexit_destructor_for__cl_showpos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showpos__()
{
  ConVar::~ConVar(this: &cl_showpos);
}

//------------------------------------------------------------------------------
// Address: 0x10433EA0
// Name: _dynamic_atexit_destructor_for__cl_showbattery__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showbattery__()
{
  ConVar::~ConVar(this: &cl_showbattery);
}

//------------------------------------------------------------------------------
// Address: 0x10433EB0
// Name: _dynamic_atexit_destructor_for__g_ViewportClientSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ViewportClientSystem__()
{
  IGameSystem::~IGameSystem(this: &g_ViewportClientSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10433EC0
// Name: _dynamic_atexit_destructor_for__ss_pipsplit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_pipsplit__()
{
  ConVar::~ConVar(this: &ss_pipsplit);
}

//------------------------------------------------------------------------------
// Address: 0x10433ED0
// Name: _dynamic_atexit_destructor_for__ss_pipscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_pipscale__()
{
  ConVar::~ConVar(this: &ss_pipscale);
}

//------------------------------------------------------------------------------
// Address: 0x10433EE0
// Name: _dynamic_atexit_destructor_for__ss_pip_right_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_pip_right_offset__()
{
  ConVar::~ConVar(this: &ss_pip_right_offset);
}

//------------------------------------------------------------------------------
// Address: 0x10433EF0
// Name: _dynamic_atexit_destructor_for__ss_pip_bottom_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_pip_bottom_offset__()
{
  ConVar::~ConVar(this: &ss_pip_bottom_offset);
}

//------------------------------------------------------------------------------
// Address: 0x10433F00
// Name: _dynamic_atexit_destructor_for__ss_force_primary_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_force_primary_fullscreen__()
{
  ConVar::~ConVar(this: &ss_force_primary_fullscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10433F10
// Name: _dynamic_atexit_destructor_for__ss_verticalsplit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_verticalsplit__()
{
  ConVar::~ConVar(this: &ss_verticalsplit_0);
}

//------------------------------------------------------------------------------
// Address: 0x10433F20
// Name: _dynamic_atexit_destructor_for__ss_splitmode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_splitmode__()
{
  ConVar::~ConVar(this: &ss_splitmode);
}

//------------------------------------------------------------------------------
// Address: 0x10433F30
// Name: _dynamic_atexit_destructor_for__ss_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_enable__()
{
  ConVar::~ConVar(this: &ss_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10433F40
// Name: _dynamic_atexit_destructor_for__ss_reloadletterbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_reloadletterbox_command__()
{
  ConCommand::~ConCommand(this: &ss_reloadletterbox_command);
}

//------------------------------------------------------------------------------
// Address: 0x10433F50
// Name: _dynamic_atexit_destructor_for__cl_showpausedimage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showpausedimage__()
{
  ConVar::~ConVar(this: &cl_showpausedimage);
}

//------------------------------------------------------------------------------
// Address: 0x10433F60
// Name: _dynamic_atexit_destructor_for__cl_panelanimation_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_panelanimation_command__()
{
  ConCommand::~ConCommand(this: &cl_panelanimation_command);
}

//------------------------------------------------------------------------------
// Address: 0x10433F70
// Name: _dynamic_atexit_destructor_for__cl_enable_remote_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_enable_remote_splitscreen__()
{
  ConVar::~ConVar(this: &cl_enable_remote_splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10433F80
// Name: _dynamic_atexit_destructor_for__s_IterateNetworkedSplitScreenSlotsPushedValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_IterateNetworkedSplitScreenSlotsPushedValues__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_IterateNetworkedSplitScreenSlotsPushedValues);
}

//------------------------------------------------------------------------------
// Address: 0x10433F90
// Name: _dynamic_atexit_destructor_for__g_MovieDisplays__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MovieDisplays__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_MovieDisplays);
}

//------------------------------------------------------------------------------
// Address: 0x10433FA0
// Name: _dynamic_atexit_destructor_for__net_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_scale__()
{
  ConVar::~ConVar(this: &net_scale);
}

//------------------------------------------------------------------------------
// Address: 0x10433FB0
// Name: _dynamic_atexit_destructor_for__net_graphpos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphpos__()
{
  ConVar::~ConVar(this: &net_graphpos);
}

//------------------------------------------------------------------------------
// Address: 0x10433FC0
// Name: _dynamic_atexit_destructor_for__net_graphsolid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphsolid__()
{
  ConVar::~ConVar(this: &net_graphsolid);
}

//------------------------------------------------------------------------------
// Address: 0x10433FD0
// Name: _dynamic_atexit_destructor_for__net_graphtext__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphtext__()
{
  ConVar::~ConVar(this: &net_graphtext);
}

//------------------------------------------------------------------------------
// Address: 0x10433FE0
// Name: _dynamic_atexit_destructor_for__net_graphmsecs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphmsecs__()
{
  ConVar::~ConVar(this: &net_graphmsecs);
}

//------------------------------------------------------------------------------
// Address: 0x10433FF0
// Name: _dynamic_atexit_destructor_for__net_graphshowlatency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphshowlatency__()
{
  ConVar::~ConVar(this: &net_graphshowlatency);
}

//------------------------------------------------------------------------------
// Address: 0x10434000
// Name: _dynamic_atexit_destructor_for__net_graphshowinterp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphshowinterp__()
{
  ConVar::~ConVar(this: &net_graphshowinterp);
}

//------------------------------------------------------------------------------
// Address: 0x10434010
// Name: _dynamic_atexit_destructor_for__net_graph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graph__()
{
  ConVar::~ConVar(this: &net_graph);
}

//------------------------------------------------------------------------------
// Address: 0x10434020
// Name: _dynamic_atexit_destructor_for__net_graphheight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphheight__()
{
  ConVar::~ConVar(this: &net_graphheight);
}

//------------------------------------------------------------------------------
// Address: 0x10434030
// Name: _dynamic_atexit_destructor_for__net_graphproportionalfont__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_graphproportionalfont__()
{
  ConVar::~ConVar(this: &net_graphproportionalfont);
}

//------------------------------------------------------------------------------
// Address: 0x10434040
// Name: _dynamic_atexit_destructor_for__bink_preload_videopanel_movies__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bink_preload_videopanel_movies__()
{
  ConVar::~ConVar(this: &bink_preload_videopanel_movies);
}

//------------------------------------------------------------------------------
// Address: 0x10434050
// Name: _dynamic_atexit_destructor_for__playvideo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playvideo_command__()
{
  ConCommand::~ConCommand(this: &playvideo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434060
// Name: _dynamic_atexit_destructor_for__playvideo_nointerrupt_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playvideo_nointerrupt_command__()
{
  ConCommand::~ConCommand(this: &playvideo_nointerrupt_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434070
// Name: _dynamic_atexit_destructor_for__playvideo_end_level_transition_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playvideo_end_level_transition_command__()
{
  ConCommand::~ConCommand(this: &playvideo_end_level_transition_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434080
// Name: _dynamic_atexit_destructor_for__playvideo_exitcommand_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playvideo_exitcommand_command__()
{
  ConCommand::~ConCommand(this: &playvideo_exitcommand_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434090
// Name: _dynamic_atexit_destructor_for__playvideo_exitcommand_nointerrupt_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playvideo_exitcommand_nointerrupt_command__()
{
  ConCommand::~ConCommand(this: &playvideo_exitcommand_nointerrupt_command);
}

//------------------------------------------------------------------------------
// Address: 0x104340A0
// Name: _dynamic_atexit_destructor_for__stopvideos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stopvideos_command__()
{
  ConCommand::~ConCommand(this: &stopvideos_command);
}

//------------------------------------------------------------------------------
// Address: 0x104340B0
// Name: _dynamic_atexit_destructor_for__stopvideos_fadeout_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stopvideos_fadeout_command__()
{
  ConCommand::~ConCommand(this: &stopvideos_fadeout_command);
}

//------------------------------------------------------------------------------
// Address: 0x104340C0
// Name: _dynamic_atexit_destructor_for__stop_transition_videos_fadeout_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stop_transition_videos_fadeout_command__()
{
  ConCommand::~ConCommand(this: &stop_transition_videos_fadeout_command);
}

//------------------------------------------------------------------------------
// Address: 0x104340D0
// Name: _dynamic_atexit_destructor_for__g_vecVideoPanels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_vecVideoPanels__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_vecVideoPanels);
}

//------------------------------------------------------------------------------
// Address: 0x104340E0
// Name: _dynamic_atexit_destructor_for__zoom_sensitivity_ratio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__zoom_sensitivity_ratio__()
{
  ConVar::~ConVar(this: &zoom_sensitivity_ratio);
}

//------------------------------------------------------------------------------
// Address: 0x104340F0
// Name: _dynamic_atexit_destructor_for__v_centermove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__v_centermove__()
{
  ConVar::~ConVar(this: &v_centermove);
}

//------------------------------------------------------------------------------
// Address: 0x10434100
// Name: _dynamic_atexit_destructor_for__v_centerspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__v_centerspeed__()
{
  ConVar::~ConVar(this: &v_centerspeed);
}

//------------------------------------------------------------------------------
// Address: 0x10434110
// Name: _dynamic_atexit_destructor_for__v_viewmodel_fov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__v_viewmodel_fov__()
{
  ConVar::~ConVar(this: &v_viewmodel_fov);
}

//------------------------------------------------------------------------------
// Address: 0x10434120
// Name: _dynamic_atexit_destructor_for__mat_viewportscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_viewportscale__()
{
  ConVar::~ConVar(this: &mat_viewportscale);
}

//------------------------------------------------------------------------------
// Address: 0x10434130
// Name: _dynamic_atexit_destructor_for__cl_leveloverview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_leveloverview__()
{
  ConVar::~ConVar(this: &cl_leveloverview);
}

//------------------------------------------------------------------------------
// Address: 0x10434140
// Name: _dynamic_atexit_destructor_for__r_mapextents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_mapextents__()
{
  ConVar::~ConVar(this: &r_mapextents);
}

//------------------------------------------------------------------------------
// Address: 0x10434150
// Name: _dynamic_atexit_destructor_for__cl_camera_follow_bone_index__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_camera_follow_bone_index__()
{
  ConVar::~ConVar(this: &cl_camera_follow_bone_index);
}

//------------------------------------------------------------------------------
// Address: 0x10434160
// Name: _dynamic_atexit_destructor_for__gl_clear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gl_clear__()
{
  ConVar::~ConVar(this: &gl_clear);
}

//------------------------------------------------------------------------------
// Address: 0x10434170
// Name: _dynamic_atexit_destructor_for__gl_clear_randomcolor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gl_clear_randomcolor__()
{
  ConVar::~ConVar(this: &gl_clear_randomcolor);
}

//------------------------------------------------------------------------------
// Address: 0x10434180
// Name: _dynamic_atexit_destructor_for__r_farz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_farz__()
{
  ConVar::~ConVar(this: &r_farz);
}

//------------------------------------------------------------------------------
// Address: 0x10434190
// Name: _dynamic_atexit_destructor_for__cl_demoviewoverride__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_demoviewoverride__()
{
  ConVar::~ConVar(this: &cl_demoviewoverride);
}

//------------------------------------------------------------------------------
// Address: 0x104341A0
// Name: _dynamic_atexit_destructor_for__centerview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__centerview__()
{
  ConCommand::~ConCommand(this: &centerview);
}

//------------------------------------------------------------------------------
// Address: 0x104341B0
// Name: _dynamic_atexit_destructor_for__ss_debug_draw_player__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_debug_draw_player__()
{
  ConVar::~ConVar(this: &ss_debug_draw_player);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1010A750
// Name: protected: float IntervalTimer::Now(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall IntervalTimer::Now(CEffectsServer *this)
{
  return gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10250C60
// Name: void UTIL_TraceEntity(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_TraceEntity(
        CBaseEntity *pEntity,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        ITraceFilter *pFilter,
        CGameTrace *ptr)
{
  ICollideable *v6; // esi
  IEngineTrace_vtbl *v7; // edi
  int v8; // eax

  v6 = pEntity->GetCollideable(this: pEntity);
  v7 = enginetrace->__vftable;
  v8 = ((int (__thiscall *)(ICollideable *, unsigned int, ITraceFilter *, CGameTrace *))v6->GetCollisionAngles)(
         a1: v6,
         a2: mask,
         a3: pFilter,
         a4: ptr);
  ((void (__thiscall *)(IEngineTrace *, ICollideable *, const Vector *, const Vector *, int))v7->SweepCollideable)(
    a1: enginetrace,
    a2: v6,
    a3: vecAbsStart,
    a4: vecAbsEnd,
    a5: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10250CB0
// Name: void UTIL_DecalTrace(class CGameTrace __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_DecalTrace(CGameTrace *pTrace, const char *decalName)
{
  CBaseEntity *m_pEnt; // ecx

  if ( pTrace->fraction != 1.0 )
  {
    m_pEnt = pTrace->m_pEnt;
    if ( m_pEnt != nullptr )
      m_pEnt->DecalTrace(this: m_pEnt, a2: pTrace, a3: decalName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250CF0
// Name: void UTIL_StringToFloatArray(float __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_StringToFloatArray(float *pVector, int count, const char *pString)
{
  char *v3; // eax
  int v4; // ebx
  char *i; // esi
  long double v6; // st7
  char v7; // al
  char v8; // al
  int v9; // ebx
  char tempString[128]; // [esp+Ch] [ebp-80h] BYREF

  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v3 = tempString;
  v4 = 0;
  for ( i = tempString; v4 < count; v3 = i )
  {
    v6 = atof(nptr: v3);
    v7 = *i;
    pVector[v4] = v6;
    if ( v7 == 0 )
      break;
    while ( v7 <= 32 )
    {
      v7 = *++i;
      if ( v7 == 0 )
        goto LABEL_12;
    }
    v8 = *i;
    if ( *i == 0 )
      break;
    while ( v8 > 32 )
    {
      v8 = *++i;
      if ( v8 == 0 )
        goto LABEL_12;
    }
    if ( *i == 0 )
      break;
    ++i;
    ++v4;
  }
LABEL_12:
  v9 = v4 + 1;
  if ( v9 < count )
    memset(&pVector[v9], 0, 4 * (count - v9));
}

//------------------------------------------------------------------------------
// Address: 0x10250D90
// Name: void UTIL_StringToVector(float __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_StringToVector(float *pVector, const char *pString)
{
  UTIL_StringToFloatArray(pVector, count: 3, pString);
}

//------------------------------------------------------------------------------
// Address: 0x10250DB0
// Name: void UTIL_DecodeICE(unsigned char __near *,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_DecodeICE(unsigned __int8 *buffer, int size, const unsigned __int8 *key)
{
  int updated; // esi
  void *v4; // esp
  unsigned __int8 *v5; // edi
  unsigned __int8 *v6; // eax
  int v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-20h] BYREF
  IceKey ice; // [esp+Ch] [ebp-14h] BYREF
  unsigned __int8 *temp; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  int bytesLeft; // [esp+30h] [ebp+10h]

  if ( key != nullptr )
  {
    IceKey::IceKey(this: &ice, n: 0);
    IceKey::set(this: &ice, key);
    updated = CInferno::UpdateTransmitState(this: &ice);
    v4 = alloca(updated * ((updated + size - 1) / updated));
    v5 = buffer;
    v6 = v8;
    temp = v8;
    bytesLeft = size;
    if ( size >= updated )
    {
      v7 = v8 - buffer;
      for ( i = v8 - buffer; ; v7 = i )
      {
        IceKey::decrypt(this: &ice, ctext: v5, ptext: &v5[v7]);
        v5 += updated;
        bytesLeft -= updated;
        if ( bytesLeft < updated )
          break;
      }
      v5 = buffer;
      v6 = temp;
    }
    _V_memcpy(dest: v5, src: v6, count: size - bytesLeft);
    IceKey::~IceKey(this: &ice);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250E60
// Name: public: virtual struct datamap_t __near * IntervalTimer::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall IntervalTimer::GetDataDescMap(IntervalTimer *this)
{
  return &IntervalTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10250E70
// Name: bool UTIL_GetModDir(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_GetModDir(char *lpszTextOut, unsigned int nSize)
{
  CResponseRulesToEngineInterface *v2; // ecx
  ICommandLine *v3; // eax
  const char *v4; // ebx
  int v6; // edi
  int v7; // eax

  v3 = _CommandLine(this: v2);
  v4 = v3->ParmValue_3(this: v3, a2: "-game", a3: "hl2");
  if ( strlen(v4) > nSize )
    return 0;
  V_strncpy(pDest: lpszTextOut, pSrc: v4, maxLen: nSize);
  if ( V_strnchr(pStr: lpszTextOut, c: 47, n: nSize) != nullptr
    || V_strnchr(pStr: lpszTextOut, c: 92, n: nSize) != nullptr )
  {
    V_StripLastDir(dirName: lpszTextOut, maxlen: nSize);
    v6 = _V_strlen(str: lpszTextOut);
    v7 = _V_strlen(str: v4);
    V_strncpy(pDest: lpszTextOut, pSrc: &v4[v6], maxLen: 1 - v6 + v7);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10250F10
// Name: float UTIL_VecToYaw(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl UTIL_VecToYaw(const Vector *vec)
{
  float y; // xmm0_4
  float v3; // xmm0_4
  float yaw; // [esp+8h] [ebp+8h]

  y = vec->y;
  if ( y == 0.0 && vec->x == 0.0 )
    return 0.0;
  __libm_sse2_atan2();
  v3 = y * 57.29578;
  yaw = v3;
  if ( v3 < 0.0 )
    return (float)(v3 + 360.0);
  return yaw;
}

//------------------------------------------------------------------------------
// Address: 0x10250F80
// Name: class Vector UTIL_YawToVector(float)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl UTIL_YawToVector(Vector *result, float yaw)
{
  result->z = 0.0;
  result->x = cos((float)(yaw * 0.017453292));
  result->y = sin((float)(yaw * 0.017453292));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10250FC0
// Name: float SharedRandomFloat(char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
float __cdecl SharedRandomFloat(const char *sharedname, float flMinVal, float flMaxVal, int additionalSeed)
{
  int v4; // eax
  IUniformRandomStream *v5; // ecx
  int v8; // [esp+Ch] [ebp-8h] BYREF
  int pBuffer; // [esp+10h] [ebp-4h] BYREF

  v8 = additionalSeed;
  pBuffer = CBaseEntity::m_nPredictionRandomSeed;
  CRC32_Init(pulCRC: (unsigned int *)&additionalSeed);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, &pBuffer, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: &v8, nBuffer: 4);
  v4 = _V_strlen(str: sharedname);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: sharedname, nBuffer: v4);
  CRC32_Final(pulCRC: (unsigned int *)&additionalSeed);
  _RandomSeed(a1: additionalSeed);
  return _RandomFloat(this: v5, a2: flMinVal, a3: flMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x10251050
// Name: int SharedRandomInt(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SharedRandomInt(const char *sharedname, int iMinVal, IUniformRandomStream *iMaxVal, int additionalSeed)
{
  int v4; // eax
  int v6; // [esp+4h] [ebp-8h] BYREF
  int pBuffer; // [esp+8h] [ebp-4h] BYREF

  v6 = additionalSeed;
  pBuffer = CBaseEntity::m_nPredictionRandomSeed;
  CRC32_Init(pulCRC: (unsigned int *)&additionalSeed);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, &pBuffer, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: &v6, nBuffer: 4);
  v4 = _V_strlen(str: sharedname);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&additionalSeed, pBuffer: sharedname, nBuffer: v4);
  CRC32_Final(pulCRC: (unsigned int *)&additionalSeed);
  _RandomSeed(a1: additionalSeed);
  return _RandomInt(this: iMaxVal, a2: iMinVal, a3: (int)iMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x102510D0
// Name: void UTIL_Tracer(class Vector const __near &,class Vector const __near &,int,int,float,bool,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_Tracer(
        const Vector *vecStart,
        const Vector *vecEnd,
        int iEntIndex,
        int iAttachment,
        float flVelocity,
        bool bWhiz,
        const char *pCustomTracerName,
        int iParticleID)
{
  CEffectData data; // [esp+0h] [ebp-64h] BYREF

  memset((void *)&data.m_vNormal, 0, 24);
  memset(&data.m_flMagnitude, 0, 14);
  data.m_vStart = *vecStart;
  data.m_vOrigin = *vecEnd;
  data.m_nMaterial = 0;
  data.m_nDamageType = 0;
  data.m_nColor = 0;
  data.m_nOtherEntIndex = 0;
  data.m_nEntIndex = iEntIndex;
  data.m_flScale = flVelocity;
  data.m_nHitBox = iParticleID;
  data.m_fFlags = bWhiz;
  if ( iAttachment != -1 )
  {
    data.m_fFlags |= 2u;
    data.m_nAttachmentIndex = iAttachment;
  }
  if ( pCustomTracerName != nullptr )
    DispatchEffect(pName: pCustomTracerName, &data);
  else
    DispatchEffect(pName: "Tracer", &data);
}

//------------------------------------------------------------------------------
// Address: 0x102511C0
// Name: void UTIL_BloodImpact(class Vector const __near &,class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodImpact(const Vector *pos, const Vector *dir, unsigned __int8 color, int amount)
{
  CEffectData data; // [esp+0h] [ebp-64h] BYREF

  memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
  memset((void *)&data.m_vAngles, 0, 20);
  memset(&data.m_flMagnitude, 0, 14);
  memset(&data.m_nMaterial, 0, 16);
  data.m_vOrigin = *pos;
  data.m_vNormal = *dir;
  data.m_flScale = (float)amount;
  data.m_nColor = color;
  DispatchEffect(pName: "bloodimpact", &data);
}

//------------------------------------------------------------------------------
// Address: 0x10251280
// Name: float UTIL_WaterLevel(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl UTIL_WaterLevel(const Vector *position, float minz, float maxz)
{
  float z; // xmm1_4
  float i; // xmm0_4
  Vector midUp; // [esp+0h] [ebp-Ch] BYREF

  *(_QWORD *)&midUp.x = *(_QWORD *)&position->x;
  midUp.z = minz;
  if ( (enginetrace->GetPointContents(this: enginetrace, a2: &midUp, a3: 16432, a4: nullptr) & 0x4030) == 0 )
    return minz;
  midUp.z = maxz;
  if ( (enginetrace->GetPointContents(this: enginetrace, a2: &midUp, a3: 16432, a4: nullptr) & 0x4030) != 0 )
    return maxz;
  z = minz;
  for ( i = maxz - minz; (float)(maxz - z) > 1.0; i = maxz - z )
  {
    midUp.z = (float)(i * 0.5) + z;
    if ( (enginetrace->GetPointContents(this: enginetrace, a2: &midUp, a3: 16432, a4: nullptr) & 0x4030) != 0 )
    {
      z = midUp.z;
      minz = midUp.z;
    }
    else
    {
      z = minz;
      maxz = midUp.z;
    }
  }
  return midUp.z;
}

//------------------------------------------------------------------------------
// Address: 0x10251660
// Name: unsigned short UTIL_GetAchievementEventMask(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl UTIL_GetAchievementEventMask()
{
  const char *pszValue; // eax
  int v1; // eax
  char lowercase[256]; // [esp+0h] [ebp-104h] BYREF
  unsigned int mapCRC; // [esp+100h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &mapCRC);
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_strncpy(pDest: lowercase, pSrc: pszValue, maxLen: 256);
  _V_strlower(start: lowercase);
  v1 = _V_strlen(str: lowercase);
  CRC32_ProcessBuffer(pulCRC: &mapCRC, pBuffer: lowercase, nBuffer: v1);
  CRC32_Final(pulCRC: &mapCRC);
  return mapCRC;
}

//------------------------------------------------------------------------------
// Address: 0x102516E0
// Name: public: CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(class CBaseEntity __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CFlaggedEntitiesEnum *__thiscall CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(
        CFlaggedEntitiesEnum *this,
        CBaseEntity **pList,
        int listMax,
        int flagMask)
{
  this->m_pList = pList;
  this->__vftable = (CFlaggedEntitiesEnum_vtbl *)&CFlaggedEntitiesEnum::`vftable';
  this->m_listMax = listMax;
  this->m_flagMask = flagMask;
  this->m_count = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10251710
// Name: bool PassServerEntityFilter(class IHandleEntity const __near *,class IHandleEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall PassServerEntityFilter@<al>(int a1@<ebx>, const IHandleEntity *pTouch, IHandleEntity *pPass)
{
  CBaseEntity *v4; // ebx
  CBaseEntity *v5; // esi

  if ( pPass == nullptr )
    return true;
  if ( pTouch == pPass )
    return false;
  if ( ((unsigned __int8 (__thiscall *)(IStaticPropMgrServer *, const IHandleEntity *, int))staticpropmgr->IsStaticProp_2)(
         a1: staticpropmgr,
         a2: pTouch,
         a3: a1) != 0 )
    v4 = nullptr;
  else
    v4 = (CBaseEntity *)pTouch->__vftable[1].GetRefEHandle(this: pTouch);
  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pPass) )
    v5 = nullptr;
  else
    v5 = (CBaseEntity *)pPass->__vftable[1].GetRefEHandle(this: pPass);
  if ( v4 == nullptr || v5 == nullptr )
    return true;
  if ( CBaseEntity::GetOwnerEntity(this: v4) == v5 )
    return false;
  return CBaseEntity::GetOwnerEntity(this: v5) != v4;
}

//------------------------------------------------------------------------------
// Address: 0x102517B0
// Name: bool StandardFilterRules(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StandardFilterRules(IHandleEntity *pHandleEntity, int fContentsMask)
{
  const CBaseHandle *v2; // eax
  CBaseEntity *v3; // edi
  bool result; // al
  int v5; // ebx
  const struct model_t *Model; // esi
  bool v7; // bl
  bool v8; // al

  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
    return true;
  v2 = pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
  v3 = (CBaseEntity *)v2;
  if ( v2 == nullptr )
    return true;
  v5 = (*(int (__thiscall **)(const CBaseHandle *))(v2[57].m_Index + 44))(a1: v2 + 57);
  Model = CBaseEntity::GetModel(this: v3);
  result = false;
  if ( modelinfo->GetModelType(this: modelinfo, a2: Model) == 1 && (v5 == 1 || v5 == 6)
    || (fContentsMask & 0x2000000) != 0 )
  {
    if ( (fContentsMask & 2) != 0
      || (v7 = modelinfo->IsTranslucent(this: modelinfo, a2: Model),
          v8 = modelinfo->IsTranslucentTwoPass(this: modelinfo, a2: Model),
          !v7)
      || v8 )
    {
      if ( (fContentsMask & 0x4000) != 0 || v3->m_MoveType.m_Value != 7 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251870
// Name: public: CTraceFilterSimple::CTraceFilterSimple(class IHandleEntity const __near *,int,bool (*)(class IHandleEntity __near *,int))
// Source: json
//------------------------------------------------------------------------------
CTraceFilterSimple *__thiscall CTraceFilterSimple::CTraceFilterSimple(
        CTraceFilterSimple *this,
        const IHandleEntity *passedict,
        int collisionGroup,
        bool (__cdecl *pExtraShouldHitFunc)(IHandleEntity *, int))
{
  this->m_pPassEnt = passedict;
  this->__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterSimple::`vftable';
  this->m_collisionGroup = collisionGroup;
  this->m_pExtraShouldHitCheckFunction = pExtraShouldHitFunc;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102518A0
// Name: public: virtual bool CTraceFilterSimple::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterSimple::ShouldHitEntity(
        CTraceFilterSimple *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  const CBaseHandle *v5; // esi
  bool (__cdecl *m_pExtraShouldHitCheckFunction)(IHandleEntity *, int); // edi

  if ( !StandardFilterRules(pHandleEntity, fContentsMask: contentsMask)
    || this->m_pPassEnt != nullptr
    && !PassServerEntityFilter(a1: (int)pHandleEntity, pTouch: pHandleEntity, pPass: (IHandleEntity *)this->m_pPassEnt) )
  {
    return 0;
  }
  if ( !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
  {
    v5 = pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
    if ( v5 != nullptr
      && (*(unsigned __int8 (__thiscall **)(const CBaseHandle *, int, int))(v5->m_Index + 68))(
           a1: v5,
           a2: this->m_collisionGroup,
           a3: contentsMask) != 0
      && g_pGameRules->ShouldCollide(this: g_pGameRules, a2: this->m_collisionGroup, a3: v5[81].m_Index) )
    {
      m_pExtraShouldHitCheckFunction = this->m_pExtraShouldHitCheckFunction;
      if ( m_pExtraShouldHitCheckFunction == nullptr
        || m_pExtraShouldHitCheckFunction(a1: pHandleEntity, a2: contentsMask) )
      {
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10251960
// Name: public: virtual bool CTraceFilterNoNPCsOrPlayer::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterNoNPCsOrPlayer::ShouldHitEntity(
        CTraceFilterNoNPCsOrPlayer *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  const CBaseHandle *v3; // eax
  const CBaseHandle *v4; // esi

  if ( CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask) == 0 )
    return false;
  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
    return false;
  v3 = pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
  v4 = v3;
  if ( v3 == nullptr || (*(int (__thiscall **)(const CBaseHandle *))(v3->m_Index + 228))(a1: v3) == 2 )
    return false;
  return (*(unsigned __int8 (__thiscall **)(const CBaseHandle *))(v4->m_Index + 292))(a1: v4) == 0
      && (*(unsigned __int8 (__thiscall **)(const CBaseHandle *))(v4->m_Index + 336))(a1: v4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102519E0
// Name: public: CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(class IHandleEntity const __near *,class IHandleEntity const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterSkipTwoEntities *__thiscall CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
        CTraceFilterSkipTwoEntities *this,
        const IHandleEntity *passentity,
        const IHandleEntity *passentity2,
        int collisionGroup)
{
  this->m_pPassEnt = passentity;
  this->m_collisionGroup = collisionGroup;
  this->m_pExtraShouldHitCheckFunction = nullptr;
  this->__vftable = (CTraceFilterSkipTwoEntities_vtbl *)&CTraceFilterSkipTwoEntities::`vftable';
  this->m_pPassEnt2 = passentity2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10251A10
// Name: public: virtual bool CTraceFilterSkipTwoEntities::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CTraceFilterSkipTwoEntities::ShouldHitEntity@<al>(
        CTraceFilterSkipTwoEntities *this@<ecx>,
        int a2@<ebx>,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  char result; // al

  result = PassServerEntityFilter(a1: a2, pTouch: pHandleEntity, pPass: (IHandleEntity *)this->m_pPassEnt2);
  if ( result != 0 )
    return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251A50
// Name: public: CTraceFilterLOS::CTraceFilterLOS(class IHandleEntity __near *,int,class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterLOS *__thiscall CTraceFilterLOS::CTraceFilterLOS(
        CTraceFilterLOS *this,
        IHandleEntity *pHandleEntity,
        int collisionGroup,
        IHandleEntity *pHandleEntity2)
{
  this->m_pPassEnt = pHandleEntity;
  this->m_collisionGroup = collisionGroup;
  this->m_pExtraShouldHitCheckFunction = nullptr;
  this->m_pPassEnt2 = pHandleEntity2;
  this->__vftable = (CTraceFilterLOS_vtbl *)&CTraceFilterLOS::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10251A80
// Name: public: virtual bool CTraceFilterLOS::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterLOS::ShouldHitEntity(CTraceFilterLOS *this, IHandleEntity *pHandleEntity, int contentsMask)
{
  CBaseEntity *v4; // eax
  char result; // al

  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
    v4 = nullptr;
  else
    v4 = (CBaseEntity *)pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
  result = CBaseEntity::BlocksLOS(this: v4);
  if ( result != 0 )
    return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251AD0
// Name: void UTIL_TraceModel(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class CBaseEntity __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceModel(
        int a1@<ebp>,
        const Vector *vecStart,
        const Vector *vecEnd,
        const Vector *hullMin,
        const Vector *hullMax,
        CBaseEntity *pentModel,
        int collisionGroup,
        CGameTrace *ptr)
{
  _BYTE v8[12]; // [esp-Ch] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  if ( pentModel != nullptr && pentModel->ShouldCollide(this: pentModel, a2: collisionGroup, a3: -1) )
  {
    ray.m_Extents.y = 0.0;
    Ray_t::Init(this: (Ray_t *)v8, start: vecStart, end: vecEnd, mins: hullMin, maxs: hullMax);
    enginetrace->ClipRayToEntity(this: enginetrace, a2: (const Ray_t *)v8, a3: -1u, a4: pentModel, a5: ptr);
  }
  else
  {
    memset(dst: (int)ptr, value: nullptr, count: sizeof(CGameTrace));
    ptr->fraction = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251B70
// Name: bool UTIL_EntityHasMatchingRootParent(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_EntityHasMatchingRootParent(CBaseEntity *pRootParent, CBaseEntity *pEntity)
{
  bool result; // al
  unsigned int m_Index; // ecx
  CBaseEntity *OwnerEntity; // eax

  result = false;
  if ( pRootParent != nullptr )
  {
    if ( pRootParent == CBaseEntity::GetRootMoveParent(this: pEntity) )
      return true;
    m_Index = pEntity->m_hOwnerEntity.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      OwnerEntity = CBaseEntity::GetOwnerEntity(this: pEntity);
      if ( pRootParent == CBaseEntity::GetRootMoveParent(this: OwnerEntity) )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251BE0
// Name: public: virtual bool CTraceFilterEntity::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterEntity::ShouldHitEntity(
        CTraceFilterEntity *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  CBaseEntity *v4; // edi

  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity) )
    return 0;
  v4 = (CBaseEntity *)pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity);
  if ( v4 == nullptr
    || UTIL_EntityHasMatchingRootParent(pRootParent: this->m_pRootParent, pEntity: v4)
    || this->m_checkHash
    && g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: this->m_pEntity, a3: v4) )
  {
    return 0;
  }
  if ( this->m_pEntity->IsNPC(this: this->m_pEntity) && NPC_CheckBrushExclude(pEntity: this->m_pEntity, pBrush: v4) )
    return 0;
  else
    return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x10251C80
// Name: public: virtual bool CTraceFilterEntityIgnoreOther::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterEntityIgnoreOther::ShouldHitEntity(
        CTraceFilterEntityIgnoreOther *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  if ( pHandleEntity == this->m_pIgnoreOther )
    return 0;
  else
    return CTraceFilterEntity::ShouldHitEntity(this, pHandleEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x10251CA0
// Name: void UTIL_TraceEntity(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,unsigned int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_TraceEntity(
        CBaseEntity *pEntity,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        CGameTrace *ptr)
{
  ICollideable *v5; // edi
  int v6; // eax
  IEngineTrace_vtbl *v7; // esi
  int v8; // eax
  CTraceFilterEntity traceFilter; // [esp+8h] [ebp-1Ch] BYREF

  v5 = pEntity->GetCollideable(this: pEntity);
  v6 = v5->GetCollisionGroup(this: v5);
  traceFilter.m_pPassEnt = pEntity;
  traceFilter.m_collisionGroup = v6;
  traceFilter.m_pExtraShouldHitCheckFunction = nullptr;
  traceFilter.__vftable = (CTraceFilterEntity_vtbl *)&CTraceFilterEntity::`vftable';
  traceFilter.m_pRootParent = CBaseEntity::GetRootMoveParent(this: pEntity);
  traceFilter.m_pEntity = pEntity;
  traceFilter.m_checkHash = g_EntityCollisionHash->IsObjectInHash(this: g_EntityCollisionHash, a2: pEntity);
  v7 = enginetrace->__vftable;
  v8 = ((int (__thiscall *)(ICollideable *, unsigned int, CTraceFilterEntity *, CGameTrace *))v5->GetCollisionAngles)(
         a1: v5,
         a2: mask,
         a3: &traceFilter,
         a4: ptr);
  ((void (__thiscall *)(IEngineTrace *, ICollideable *, const Vector *, const Vector *, int))v7->SweepCollideable)(
    a1: enginetrace,
    a2: v5,
    a3: vecAbsStart,
    a4: vecAbsEnd,
    a5: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10251D30
// Name: void UTIL_TraceEntity(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_TraceEntity(
        CBaseEntity *pEntity,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        const IHandleEntity *pIgnore,
        int nCollisionGroup,
        CGameTrace *ptr)
{
  ICollideable *v7; // edi
  IEngineTrace_vtbl *v8; // esi
  int v9; // eax
  CTraceFilterEntityIgnoreOther traceFilter; // [esp+8h] [ebp-20h] BYREF

  v7 = pEntity->GetCollideable(this: pEntity);
  traceFilter.m_pPassEnt = pEntity;
  traceFilter.m_collisionGroup = nCollisionGroup;
  traceFilter.m_pExtraShouldHitCheckFunction = nullptr;
  traceFilter.__vftable = (CTraceFilterEntityIgnoreOther_vtbl *)&CTraceFilterEntity::`vftable';
  traceFilter.m_pRootParent = CBaseEntity::GetRootMoveParent(this: pEntity);
  traceFilter.m_pEntity = pEntity;
  traceFilter.m_checkHash = g_EntityCollisionHash->IsObjectInHash(this: g_EntityCollisionHash, a2: pEntity);
  traceFilter.m_pIgnoreOther = pIgnore;
  traceFilter.__vftable = (CTraceFilterEntityIgnoreOther_vtbl *)&CTraceFilterEntityIgnoreOther::`vftable';
  v8 = enginetrace->__vftable;
  v9 = ((int (__thiscall *)(ICollideable *, unsigned int, CTraceFilterEntityIgnoreOther *, CGameTrace *))v7->GetCollisionAngles)(
         a1: v7,
         a2: mask,
         a3: &traceFilter,
         a4: ptr);
  ((void (__thiscall *)(IEngineTrace *, ICollideable *, const Vector *, const Vector *, int))v8->SweepCollideable)(
    a1: enginetrace,
    a2: v7,
    a3: vecAbsStart,
    a4: vecAbsEnd,
    a5: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10251DC0
// Name: void UTIL_TraceLineFilterEntity(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,unsigned int,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_TraceLineFilterEntity(
        CBaseEntity *pEntity,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        int nCollisionGroup,
        CGameTrace *ptr)
{
  CTraceFilterEntity traceFilter; // [esp+4h] [ebp-1Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  traceFilter.m_pPassEnt = pEntity;
  traceFilter.m_collisionGroup = nCollisionGroup;
  traceFilter.m_pExtraShouldHitCheckFunction = nullptr;
  traceFilter.__vftable = (CTraceFilterEntity_vtbl *)&CTraceFilterEntity::`vftable';
  traceFilter.m_pRootParent = CBaseEntity::GetRootMoveParent(this: pEntity);
  traceFilter.m_pEntity = pEntity;
  traceFilter.m_checkHash = g_EntityCollisionHash->IsObjectInHash(this: g_EntityCollisionHash, a2: pEntity);
  UTIL_TraceLine(a1: (int)&savedregs, a2: (int)pEntity, vecAbsStart, vecAbsEnd, mask, pFilter: &traceFilter, ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10251E20
// Name: void UTIL_ParticleTracer(char const __near *,class Vector const __near &,class Vector const __near &,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_ParticleTracer(
        const char *pszTracerEffectName,
        const Vector *vecStart,
        const Vector *vecEnd,
        int iEntIndex,
        int iAttachment,
        bool bWhiz)
{
  int ParticleSystemIndex; // eax

  ParticleSystemIndex = GetParticleSystemIndex(pParticleSystemName: pszTracerEffectName);
  UTIL_Tracer(
    vecStart,
    vecEnd,
    iEntIndex,
    iAttachment,
    flVelocity: 0.0,
    bWhiz,
    pCustomTracerName: "ParticleTracer",
    iParticleID: ParticleSystemIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10251E60
// Name: bool UTIL_IsLowViolence(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_IsLowViolence()
{
  return violence_hblood.m_pParent == nullptr
      || violence_hblood.m_pParent->m_Value.m_nValue == 0
      || violence_ablood.m_pParent == nullptr
      || violence_ablood.m_pParent->m_Value.m_nValue == 0
      || violence_hgibs.m_pParent == nullptr
      || violence_hgibs.m_pParent->m_Value.m_nValue == 0
      || violence_agibs.m_pParent == nullptr
      || violence_agibs.m_pParent->m_Value.m_nValue == 0
      || engine->IsLowViolence(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x10251EB0
// Name: bool UTIL_ShouldShowBlood(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_ShouldShowBlood(int color)
{
  if ( color == -1 )
    return false;
  if ( color != 0 )
    return violence_ablood.m_pParent != nullptr && violence_ablood.m_pParent->m_Value.m_nValue != 0;
  else
    return violence_hblood.m_pParent != nullptr && violence_hblood.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10251F10
// Name: void UTIL_BloodDecalTrace(class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodDecalTrace(CGameTrace *pTrace, int bloodColor)
{
  int m_nValue; // eax
  float fraction; // xmm0_4
  CBaseEntity *v4; // ecx
  CBaseEntity *m_pEnt; // ecx
  CBaseEntity *v6; // ecx

  if ( bloodColor == -1 )
    return;
  if ( bloodColor != 0 )
  {
    if ( violence_ablood.m_pParent != nullptr )
    {
      m_nValue = violence_ablood.m_pParent->m_Value.m_nValue;
      goto LABEL_8;
    }
  }
  else if ( violence_hblood.m_pParent != nullptr )
  {
    m_nValue = violence_hblood.m_pParent->m_Value.m_nValue;
    goto LABEL_8;
  }
  m_nValue = 0;
LABEL_8:
  if ( m_nValue != 0 )
  {
    fraction = pTrace->fraction;
    if ( bloodColor != 0 )
    {
      if ( bloodColor == 4 )
      {
        if ( fraction != 1.0 )
        {
          m_pEnt = pTrace->m_pEnt;
          if ( m_pEnt != nullptr )
            m_pEnt->DecalTrace(this: m_pEnt, a2: pTrace, a3: "GreenBlood");
        }
      }
      else if ( fraction != 1.0 )
      {
        v6 = pTrace->m_pEnt;
        if ( v6 != nullptr )
          v6->DecalTrace(this: v6, a2: pTrace, a3: "YellowBlood");
      }
    }
    else if ( fraction != 1.0 )
    {
      v4 = pTrace->m_pEnt;
      if ( v4 != nullptr )
        v4->DecalTrace(this: v4, a2: pTrace, a3: "Blood");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252080
// Name: public: virtual enum IterationRetval_t CFlaggedEntitiesEnum::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFlaggedEntitiesEnum::EnumElement(CFlaggedEntitiesEnum *this, IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v6; // eax
  int m_flagMask; // ecx
  int m_count; // ecx

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    return 0;
  v4 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index];
  if ( v4->m_SerialNumber != HIWORD(m_Index) )
    return 0;
  m_pEntity = v4->m_pEntity;
  if ( m_pEntity == nullptr )
    return 0;
  v6 = (CBaseEntity *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  if ( v6 == nullptr )
    return 0;
  m_flagMask = this->m_flagMask;
  if ( m_flagMask != 0 && (m_flagMask & v6->m_fFlags.m_Value) == 0 )
    return 0;
  m_count = this->m_count;
  if ( m_count < this->m_listMax )
  {
    this->m_pList[m_count] = v6;
    ++this->m_count;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10252100
// Name: public: virtual bool CTraceFilterSimpleList::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterSimpleList::ShouldHitEntity(
        CTraceFilterSimpleList *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  int m_Size; // edx
  int v4; // eax
  IHandleEntity **i; // esi

  m_Size = this->m_PassEntities.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
  for ( i = this->m_PassEntities.m_Memory.m_pMemory; *i != pHandleEntity; ++i )
  {
    if ( ++v4 >= m_Size )
      return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
  }
  if ( v4 == -1 )
    return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10252140
// Name: void UTIL_BloodDrips(class Vector const __near &,class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodDrips(const Vector *origin, const Vector *direction, int color, int amount)
{
  int m_nValue; // eax
  int v5; // esi
  float scale; // xmm0_4

  if ( color == -1 )
    return;
  if ( color != 0 )
  {
    if ( violence_ablood.m_pParent != nullptr )
    {
      m_nValue = violence_ablood.m_pParent->m_Value.m_nValue;
      goto LABEL_8;
    }
LABEL_7:
    m_nValue = 0;
    goto LABEL_8;
  }
  if ( violence_hblood.m_pParent == nullptr )
    goto LABEL_7;
  m_nValue = violence_hblood.m_pParent->m_Value.m_nValue;
LABEL_8:
  if ( m_nValue != 0 )
  {
    v5 = amount;
    if ( amount != 0 )
    {
      if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
        v5 = 5 * amount;
      if ( v5 > 255 )
        v5 = 255;
      if ( color == 3 )
      {
        g_pEffects->Sparks(this: g_pEffects, a2: origin, a3: 1, a4: 1, a5: nullptr);
        if ( ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
               a1: random,
               a2: 0,
               a3: 0x40000000) >= 1.0 )
        {
          scale = (float)random->RandomInt(this: random, a2: 10, a3: 15);
          UTIL_Smoke(origin, scale, framerate: 10.0);
        }
      }
      else
      {
        UTIL_BloodImpact(pos: origin, dir: direction, color, amount: v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252270
// Name: bool UTIL_IsSpaceEmpty(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_IsSpaceEmpty(CBaseEntity *pMainEnt, const Vector *vMin, const Vector *vMax)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  unsigned int v9; // eax
  bool result; // al
  CGameTrace trace; // [esp+0h] [ebp-78h] BYREF
  Vector hullMin; // [esp+54h] [ebp-24h] BYREF
  Vector vCenter; // [esp+60h] [ebp-18h] BYREF
  Vector vHalfDims; // [esp+6Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+78h] [ebp+0h] BYREF

  x = vMin->x;
  y = vMin->y;
  z = vMin->z;
  v6 = (float)(vMax->x - vMin->x) * 0.5;
  v7 = (float)(vMax->y - y) * 0.5;
  v8 = (float)(vMax->z - z) * 0.5;
  vHalfDims.x = v6;
  vHalfDims.y = v7;
  vHalfDims.z = v8;
  vCenter.x = x + v6;
  vCenter.y = y + v7;
  vCenter.z = z + v8;
  if ( pMainEnt != nullptr )
  {
    v9 = pMainEnt->PhysicsSolidMaskForEntity(this: pMainEnt);
    v6 = vHalfDims.x;
    v7 = vHalfDims.y;
    v8 = vHalfDims.z;
  }
  else
  {
    v9 = 33570827;
  }
  hullMin.x = -v6;
  hullMin.y = -v7;
  hullMin.z = -v8;
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)pMainEnt,
    vecAbsStart: &vCenter,
    vecAbsEnd: &vCenter,
    &hullMin,
    hullMax: &vHalfDims,
    mask: v9,
    ignore: pMainEnt,
    collisionGroup: 0,
    ptr: &trace);
  if ( trace.fraction != 1.0 )
    return false;
  result = true;
  if ( trace.allsolid || trace.startsolid )
    return false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252370
// Name: public: CTraceFilterSimpleList::CTraceFilterSimpleList(int)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterSimpleList *__thiscall CTraceFilterSimpleList::CTraceFilterSimpleList(
        CTraceFilterSimpleList *this,
        int collisionGroup)
{
  this->m_pPassEnt = nullptr;
  this->m_collisionGroup = collisionGroup;
  this->m_pExtraShouldHitCheckFunction = nullptr;
  this->__vftable = (CTraceFilterSimpleList_vtbl *)&CTraceFilterSimpleList::`vftable';
  this->m_PassEntities.m_Memory.m_pMemory = nullptr;
  this->m_PassEntities.m_Memory.m_nAllocationCount = 0;
  this->m_PassEntities.m_Memory.m_nGrowSize = 0;
  this->m_PassEntities.m_Size = 0;
  this->m_PassEntities.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102523A0
// Name: void UTIL_ClipTraceToPlayers(class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall UTIL_ClipTraceToPlayers(
        int a1@<ebp>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask,
        ITraceFilter *filter,
        CGameTrace *tr)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float x; // xmm0_4
  float v9; // xmm3_4
  int y_low; // xmm4_4
  float v11; // xmm5_4
  CBasePlayer *v12; // esi
  float *v13; // esi
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  __int128 v21; // xmm0
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  _BYTE v27[12]; // [esp-Ch] [ebp-F4h] BYREF
  CGameTrace playerTrace; // [esp+0h] [ebp-E8h] BYREF
  float v29; // [esp+54h] [ebp-94h]
  Ray_t ray_4; // [esp+5Ch] [ebp-8Ch] OVERLAPPED BYREF
  IHandleEntity *v31; // [esp+B4h] [ebp-34h]
  float v32; // [esp+B8h] [ebp-30h]
  float v33; // [esp+BCh] [ebp-2Ch]
  CBasePlayer *player; // [esp+C0h] [ebp-28h]
  float v35; // [esp+C4h] [ebp-24h]
  Vector v36; // [esp+C8h] [ebp-20h] BYREF
  float fraction; // [esp+D4h] [ebp-14h]
  int i; // [esp+D8h] [ebp-10h]
  int v39; // [esp+DCh] [ebp-Ch]
  float smallestFraction; // [esp+E0h] [ebp-8h]
  float retaddr; // [esp+E8h] [ebp+0h]

  v39 = a1;
  smallestFraction = retaddr;
  y = vecAbsEnd->y;
  z = vecAbsEnd->z;
  fraction = tr->fraction;
  x = vecAbsEnd->x;
  v9 = vecAbsStart->x;
  y_low = SLODWORD(vecAbsStart->y);
  v11 = vecAbsStart->z;
  ray_4.m_Start.y = y - *(float *)&y_low;
  ray_4.m_Start.x = x - v9;
  ray_4.m_Start.z = z - v11;
  BYTE1(ray_4.m_Extents.y) = (float)((float)((float)(ray_4.m_Start.y * ray_4.m_Start.y)
                                           + (float)(ray_4.m_Start.x * ray_4.m_Start.x))
                                   + (float)(ray_4.m_Start.z * ray_4.m_Start.z)) != 0.0;
  memset(&ray_4.m_StartOffset, 0, 12);
  ray_4.m_Extents.x = 0.0;
  LOBYTE(ray_4.m_Extents.y) = 1;
  memset(&ray_4.m_Delta, 0, 12);
  *(float *)&playerTrace.m_pEnt = v9;
  playerTrace.hitbox = y_low;
  v29 = v11;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v12 = UTIL_PlayerByIndex(playerIndex: i);
    v31 = v12;
    if ( v12 != nullptr
      && v12->IsAlive(this: v12)
      && (filter == nullptr || filter->ShouldHitEntity(this: filter, a2: v12, a3: mask) != 0) )
    {
      v13 = (float *)v12->WorldSpaceCenter(this: v12);
      v14 = vecAbsEnd->y - vecAbsStart->y;
      v15 = *v13 - vecAbsStart->x;
      v16 = v13[1] - vecAbsStart->y;
      v35 = v13[2] - vecAbsStart->z;
      v17 = vecAbsEnd->x - vecAbsStart->x;
      v36.y = v14;
      v18 = vecAbsEnd->z - vecAbsStart->z;
      v33 = v15;
      *(float *)&player = v16;
      v36.x = v17;
      v36.z = v18;
      v32 = VectorNormalize(vec: &v36);
      v19 = (float)((float)(v36.y * *(float *)&player) + (float)(v36.x * v33)) + (float)(v36.z * v35);
      if ( v19 >= 0.0 )
      {
        if ( v19 <= v32 )
        {
          v23 = v36.y * v19;
          v24 = vecAbsStart->z + (float)(v19 * v36.z);
          v25 = *v13 - (float)(vecAbsStart->x + (float)(v36.x * v19));
          v26 = (float)((float)((float)(v13[1] - (float)(vecAbsStart->y + v23))
                              * (float)(v13[1] - (float)(vecAbsStart->y + v23)))
                      + (float)((float)(v13[2] - v24) * (float)(v13[2] - v24)))
              + (float)(v25 * v25);
          v21 = 0;
          *(float *)&v21 = fsqrt(v26);
          *(_OWORD *)&ray_4.m_pWorldAxisTransform = v21;
        }
        else
        {
          v22 = v13[1] - vecAbsEnd->y;
          v21 = 0;
          *(float *)&v21 = fsqrt(
                             (float)((float)(v22 * v22)
                                   + (float)((float)(v13[2] - vecAbsEnd->z) * (float)(v13[2] - vecAbsEnd->z)))
                           + (float)((float)(*v13 - vecAbsEnd->x) * (float)(*v13 - vecAbsEnd->x)));
          *(_OWORD *)&ray_4.m_pWorldAxisTransform = v21;
          *(float *)&v21 = -*(float *)&v21;
        }
      }
      else
      {
        v20 = v13[1] - vecAbsStart->y;
        v21 = 0;
        *(float *)&v21 = fsqrt(
                           (float)((float)(v20 * v20)
                                 + (float)((float)(v13[2] - vecAbsStart->z) * (float)(v13[2] - vecAbsStart->z)))
                         + (float)((float)(*v13 - vecAbsStart->x) * (float)(*v13 - vecAbsStart->x)));
        *(_OWORD *)&ray_4.m_pWorldAxisTransform = v21;
        *(float *)&v21 = -*(float *)&v21;
      }
      if ( *(float *)&v21 >= 0.0 && *(float *)&v21 <= 60.0 )
      {
        enginetrace->ClipRayToEntity(
          this: enginetrace,
          a2: (const Ray_t *)&playerTrace.m_pEnt,
          a3: mask | 0x40000000,
          a4: v31,
          a5: (CGameTrace *)v27);
        if ( fraction > playerTrace.plane.normal.z )
        {
          CGameTrace::operator=(this: tr, __that: (const CGameTrace *)v27);
          fraction = playerTrace.plane.normal.z;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252720
// Name: public: void CTraceFilterSimpleList::AddEntityToIgnore(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceFilterSimpleList::AddEntityToIgnore(CTraceFilterSimpleList *this, IHandleEntity *pEntity)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_PassEntities; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_PassEntities.m_Memory.m_nAllocationCount;
  p_m_PassEntities = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PassEntities;
  m_Size = this->m_PassEntities.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_PassEntities, num: m_Size - m_nAllocationCount + 1);
  ++p_m_PassEntities[1].m_pMemory;
  m_pMemory = p_m_PassEntities->m_pMemory;
  v6 = (int)p_m_PassEntities[1].m_pMemory - m_Size - 1;
  p_m_PassEntities[1].m_nAllocationCount = (int)p_m_PassEntities->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_PassEntities->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1040C400
// Name: IntervalTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *IntervalTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<IntervalTimer>(__formal: nullptr);
  IntervalTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C410
// Name: DT_IntervalTimer::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_IntervalTimer::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_IntervalTimer::g_SendTable);
  return atexit(func: DT_IntervalTimer::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C430
// Name: DT_IntervalTimer::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_IntervalTimer::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_IntervalTimer::ignored>();
  DT_IntervalTimer::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C440
// Name: DT_CountdownTimer::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CountdownTimer::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CountdownTimer::g_SendTable);
  return atexit(func: DT_CountdownTimer::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C460
// Name: DT_CountdownTimer::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CountdownTimer::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CountdownTimer::ignored>();
  DT_CountdownTimer::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C470
// Name: CTimeline_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTimeline_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTimeline>(__formal: nullptr);
  CTimeline_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C480
// Name: DT_Timeline::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Timeline::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Timeline::g_SendTable);
  return atexit(func: DT_Timeline::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C4A0
// Name: DT_Timeline::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Timeline::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Timeline::ignored>();
  DT_Timeline::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041ED80
// Name: DT_IntervalTimer::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_IntervalTimer::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_IntervalTimer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED90
// Name: DT_CountdownTimer::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CountdownTimer::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CountdownTimer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041EDC0
// Name: DT_Timeline::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Timeline::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Timeline::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10252780
// Name: struct datamap_t __near * DataMapInit<class IntervalTimer>(class IntervalTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<IntervalTimer>()
{
  if ( (_S3_137 & 1) == 0 )
  {
    _S3_137 |= 1u;
    nameHolder_451.m_pszBase = "IntervalTimer";
    nameHolder_451.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_451.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_451.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_451.m_Names.m_Size = 0;
    nameHolder_451.m_Names.m_pElements = nullptr;
    nameHolder_451.m_nLenBase = 13;
    atexit(func: DataMapInit_IntervalTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  IntervalTimer::m_DataMap.baseMap = nullptr;
  IntervalTimer::m_DataMap.dataNumFields = 1;
  IntervalTimer::m_DataMap.dataDesc = dataDesc_495;
  return &IntervalTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10252800
// Name: struct datamap_t __near * DataMapInit<class CTimeline>(class CTimeline __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTimeline>()
{
  if ( (_S6_26 & 1) == 0 )
  {
    _S6_26 |= 1u;
    nameHolder_452.m_pszBase = "CTimeline";
    nameHolder_452.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_452.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_452.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_452.m_Names.m_Size = 0;
    nameHolder_452.m_Names.m_pElements = nullptr;
    nameHolder_452.m_nLenBase = 9;
    atexit(func: DataMapInit_CTimeline__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTimeline::m_DataMap.baseMap = &IntervalTimer::m_DataMap;
  CTimeline::m_DataMap.dataNumFields = 7;
  CTimeline::m_DataMap.dataDesc = &dataDesc_423[1];
  return &CTimeline::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040C4B0
// Name: _dynamic_initializer_for__g_debug_vehiclebase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_vehiclebase__()
{
  ConVar::ConVar(this: &g_debug_vehiclebase, pName: "g_debug_vehiclebase", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_vehiclebase__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EDA0
// Name: _ServerClassInit_DT_CountdownTimer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CountdownTimer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_34;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EDD0
// Name: _ServerClassInit_DT_Timeline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Timeline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S7_18;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EDF0
// Name: _ServerClassInit_DT_IntervalTimer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_IntervalTimer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_64;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE10
// Name: _DataMapInit_IntervalTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_IntervalTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_451);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE20
// Name: _DataMapInit_CTimeline__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTimeline__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_452);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE30
// Name: _dynamic_atexit_destructor_for__g_debug_vehiclebase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_vehiclebase__()
{
  ConVar::~ConVar(this: &g_debug_vehiclebase);
}

} // namespace server
