// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/props_shared.cpp
// Functions: 29
// ============================================================

#include "game\shared\props_shared.h"

//------------------------------------------------------------------------------
// Address: 0x101566B0
// Name: public: virtual void CPropData::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropData::LevelShutdownPostEntity(CPropData *this)
{
  KeyValues *m_pKVPropData; // ecx

  m_pKVPropData = this->m_pKVPropData;
  if ( m_pKVPropData != nullptr )
  {
    KeyValues::deleteThis(this: m_pKVPropData);
    this->m_pKVPropData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101566D0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10156700
// Name: public: float KeyValues::GetFloat(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall KeyValues::GetFloat(KeyValues *this, int keySymbol, float defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10156740
// Name: AlignBoxes
// Source: json
//------------------------------------------------------------------------------
void __usercall AlignBoxes(const Vector *boxExtents1@<ecx>, const Vector *boxExtents2@<eax>, matrix3x4_t *pInOutMatrix)
{
  __int64 v3; // xmm0_8
  float z; // ecx
  float v5; // edx
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  float y; // xmm1_4
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  int v14; // edi
  int column[2]; // [esp+0h] [ebp-3Ch]
  AlignBoxes::__l2::<unnamed_type_rotations> rotations[2]; // [esp+8h] [ebp-34h]
  Vector out; // [esp+18h] [ebp-24h] BYREF
  Vector ext1; // [esp+24h] [ebp-18h] BYREF
  Vector ext2; // [esp+30h] [ebp-Ch] BYREF

  v3 = *(_QWORD *)&boxExtents1->x;
  z = boxExtents1->z;
  v5 = boxExtents2->z;
  *(_QWORD *)&ext1.x = v3;
  *(_QWORD *)&ext2.x = *(_QWORD *)&boxExtents2->x;
  v6 = 0;
  ext1.z = z;
  ext2.z = v5;
  if ( *(float *)&v3 <= *((float *)&v3 + 1) )
  {
    v7 = 1;
    if ( *((float *)&v3 + 1) > ext1.z )
      goto LABEL_6;
  }
  else if ( *(float *)&v3 > ext1.z )
  {
    v7 = 0;
    goto LABEL_6;
  }
  v7 = 2;
LABEL_6:
  if ( ext2.x <= ext2.y )
  {
    v8 = 1;
    if ( ext2.y > ext2.z )
      goto LABEL_11;
  }
  else if ( ext2.x > ext2.z )
  {
    v8 = 0;
    goto LABEL_11;
  }
  v8 = 2;
LABEL_11:
  if ( v7 != v8 )
  {
    v9 = *(&ext2.x + v7);
    rotations[0].axis0 = v7;
    *(&ext2.x + v8) = v9;
    rotations[0].axis1 = v8;
    v6 = 1;
  }
  *((_DWORD *)&ext1.x + v7) = 0;
  y = ext1.y;
  *((_DWORD *)&ext2.x + v7) = 0;
  if ( ext1.x <= y )
  {
    v11 = 1;
    if ( y > ext1.z )
      goto LABEL_18;
  }
  else if ( ext1.x > ext1.z )
  {
    v11 = 0;
    goto LABEL_18;
  }
  v11 = 2;
LABEL_18:
  if ( ext2.x <= ext2.y )
  {
    v12 = 1;
    if ( ext2.y > ext2.z )
      goto LABEL_23;
  }
  else if ( ext2.x > ext2.z )
  {
    v12 = 0;
    goto LABEL_23;
  }
  v12 = 2;
LABEL_23:
  if ( v11 != v12 )
  {
    rotations[v6].axis0 = v11;
    rotations[v6++].axis1 = v12;
  }
  while ( v6 > 0 )
  {
    v13 = column[2 * v6];
    v14 = column[2 * v6-- + 1];
    MatrixGetColumn(in: pInOutMatrix, column: v13, out: &ext1);
    MatrixGetColumn(in: pInOutMatrix, column: v14, &out);
    MatrixSetColumn(in: &out, column: v13, out: pInOutMatrix);
    ext2.x = -ext1.x;
    ext2.y = -ext1.y;
    ext2.z = -ext1.z;
    MatrixSetColumn(in: &ext2, column: v14, out: pInOutMatrix);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101568D0
// Name: FixupModelName
// Source: json
//------------------------------------------------------------------------------
char *__usercall FixupModelName@<eax>(char *pOut@<esi>, unsigned int sizeOut@<edi>, const char *pModelNameIn@<eax>)
{
  int v3; // eax
  char tmp[1024]; // [esp+0h] [ebp-400h] BYREF

  V_strncpy(pDest: tmp, pSrc: pModelNameIn, maxLen: 1024);
  if ( V_strnicmp(s1: tmp, s2: "models/", n: 7) != 0 )
    V_snprintf(pDest: pOut, maxLen: sizeOut, pFormat: "models/%s", tmp);
  else
    V_strncpy(pDest: pOut, pSrc: tmp, maxLen: sizeOut);
  v3 = _V_strlen(str: pOut);
  if ( v3 < 4 || _V_stricmp(s1: &pOut[v3 - 4], s2: ".mdl") != 0 )
    V_strncat(pDest: pOut, pSrc: ".mdl", destBufferSize: sizeOut, max_chars_to_copy: -1);
  return pOut;
}

//------------------------------------------------------------------------------
// Address: 0x10156970
// Name: public: virtual void CBreakParser::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakParser::ParseKeyValue(CBreakParser *this, void *pData, const char *pKey, char *pValue)
{
  if ( _V_stricmp(s1: pKey, s2: "model") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "ragdoll") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "motiondisabled") != 0 )
      {
        if ( _V_stricmp(s1: pKey, s2: "offset") != 0 )
        {
          if ( _V_stricmp(s1: pKey, s2: "health") != 0 )
          {
            if ( _V_stricmp(s1: pKey, s2: "fadetime") != 0 )
            {
              if ( _V_stricmp(s1: pKey, s2: "fademindist") != 0 )
              {
                if ( _V_stricmp(s1: pKey, s2: "fademaxdist") != 0 )
                {
                  if ( _V_stricmp(s1: pKey, s2: "debris") != 0 )
                  {
                    if ( _V_stricmp(s1: pKey, s2: "burst") != 0 )
                    {
                      if ( _V_stricmp(s1: pKey, s2: "placementbone") != 0 )
                      {
                        if ( _V_stricmp(s1: pKey, s2: "placementattachment") != 0 )
                        {
                          if ( _V_stricmp(s1: pKey, s2: "multiplayer_break") == 0 )
                          {
                            if ( _V_stricmp(s1: pValue, s2: "server") != 0 )
                            {
                              if ( _V_stricmp(s1: pValue, s2: "client") == 0 )
                                *((_DWORD *)pData + 266) = 2;
                            }
                            else
                            {
                              *((_DWORD *)pData + 266) = 1;
                            }
                          }
                        }
                        else
                        {
                          V_strncpy(pDest: (char *)pData + 524, pSrc: pValue, maxLen: 512);
                          *((_BYTE *)pData + 1061) = 0;
                        }
                      }
                      else
                      {
                        V_strncpy(pDest: (char *)pData + 524, pSrc: pValue, maxLen: 512);
                        *((_BYTE *)pData + 1061) = 1;
                      }
                    }
                    else
                    {
                      *((float *)pData + 263) = atof(nptr: pValue);
                    }
                  }
                  else
                  {
                    *((_DWORD *)pData + 264) = atoi(nptr: pValue) <= 0 ? 4 : 1;
                    this->m_wroteCollisionGroup = true;
                  }
                }
                else
                {
                  *((float *)pData + 261) = atof(nptr: pValue);
                }
              }
              else
              {
                *((float *)pData + 260) = atof(nptr: pValue);
              }
            }
            else
            {
              *((float *)pData + 259) = atof(nptr: pValue);
              if ( !this->m_wroteCollisionGroup )
                *((_DWORD *)pData + 264) = 1;
            }
          }
          else
          {
            *((float *)pData + 262) = atof(nptr: pValue);
          }
        }
        else
        {
          UTIL_StringToVector(pVector: (float *)pData, pString: pValue);
        }
      }
      else
      {
        *((_BYTE *)pData + 1062) = 1;
      }
    }
    else
    {
      FixupModelName(pOut: (char *)pData + 12, sizeOut: 0x200u, pModelNameIn: pValue);
      *((_BYTE *)pData + 1060) = 1;
    }
  }
  else
  {
    FixupModelName(pOut: (char *)pData + 12, sizeOut: 0x200u, pModelNameIn: pValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156C30
// Name: public: virtual void CBreakParser::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakParser::SetDefaults(CBreakParser *this, char *pData)
{
  pData[12] = 0;
  *(Vector *)pData = vec3_origin;
  *((_DWORD *)pData + 262) = 1065353216;
  *((_DWORD *)pData + 259) = 1101004800;
  *((_DWORD *)pData + 260) = 0;
  *((_DWORD *)pData + 261) = 0;
  *((float *)pData + 263) = this->m_defaultBurstScale;
  *((_DWORD *)pData + 264) = this->m_defaultCollisionGroup;
  pData[1060] = 0;
  pData[524] = 0;
  *(_WORD *)(pData + 1061) = 0;
  *((_DWORD *)pData + 266) = 0;
  this->m_wroteCollisionGroup = false;
}

//------------------------------------------------------------------------------
// Address: 0x10156CD0
// Name: int GetAutoMultiplayerPhysicsMode(class Vector,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAutoMultiplayerPhysicsMode(Vector size, float mass)
{
  int result; // eax

  if ( (float)((float)(sv_pushaway_clientside_size.m_pParent->m_Value.m_fValue
                     * sv_pushaway_clientside_size.m_pParent->m_Value.m_fValue)
             * sv_pushaway_clientside_size.m_pParent->m_Value.m_fValue) > (float)((float)(size.y * size.x) * size.z) )
    return 3;
  result = 2;
  if ( mass >= 8.0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10156DC0
// Name: public: int CPropData::ParsePropFromKV(class C_BaseEntity __near *,class IBreakableWithPropData __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge CPropData::ParsePropFromKV@<eax>(
        CPropData *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        C_BaseEntity *pProp,
        IBreakableWithPropData *pBreakableInterface,
        KeyValues *pSection,
        KeyValues *pInteractionSection)
{
  unsigned int result; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  KeyValues *v25; // ebx
  KeyValues *Key; // eax
  const char *v27; // eax
  KeyValues *v28; // eax
  float v29; // xmm0_4
  KeyValues *v30; // eax
  float v31; // xmm0_4
  KeyValues *v32; // eax
  const char *String; // eax
  const char *v34; // edi
  KeyValues *v35; // eax
  IBreakableWithPropData_vtbl *v36; // edi
  const char *v37; // eax
  int v38; // edi
  KeyValues *v39; // eax
  int Int; // eax
  KeyValues *v41; // eax
  const char *v42; // eax
  const char *v43; // edi
  mp_break_t v44; // ebx
  KeyValues *v45; // eax
  float v46; // xmm0_4
  KeyValues *v47; // eax
  float v48; // xmm0_4
  KeyValues *v49; // eax
  float v50; // xmm0_4
  C_BaseEntity_vtbl *v51; // edi
  int v52; // eax
  int v53; // eax
  IBreakableWithPropData_vtbl *v54; // edi
  IBreakableWithPropData_vtbl *v55; // edi
  KeyValues *v56; // eax
  const char *v57; // eax
  const char *v58; // edi
  KeyValues *v59; // eax
  IBreakableWithPropData_vtbl *v60; // edi
  const char *v61; // eax
  int v62; // edi
  KeyValues *v63; // eax
  int v64; // eax
  int v65; // edi
  KeyValues *v66; // eax
  int v67; // eax
  Vector *v68; // eax
  float z; // ecx
  int v70; // eax
  __m128d v71; // xmm1
  __m128 y_low; // xmm0
  __m128d v73; // xmm2
  __m128d v74; // xmm3
  int *p_m_keyKeyName; // edi
  KeyValues *v76; // eax
  KeyValues *v77; // eax
  const char *v78; // eax
  KeyValues *v79; // eax
  float v81; // [esp+B0h] [ebp-18h]
  float Float; // [esp+B0h] [ebp-18h]
  float v83; // [esp+B0h] [ebp-18h]
  float v84; // [esp+B0h] [ebp-18h]
  Vector vecSize; // [esp+B8h] [ebp-10h]
  CPropData *v86; // [esp+C4h] [ebp-4h]
  propdata_interactions_t i; // [esp+D0h] [ebp+8h]
  int iBaseResult; // [esp+D4h] [ebp+Ch]
  float pSectiona; // [esp+D8h] [ebp+10h]
  float pSectiond; // [esp+D8h] [ebp+10h]
  float pSectionb; // [esp+D8h] [ebp+10h]
  float pSectione; // [esp+D8h] [ebp+10h]
  float pSectionc; // [esp+D8h] [ebp+10h]
  float pSectionf; // [esp+D8h] [ebp+10h]

  v86 = this;
  if ( pBreakableInterface == nullptr )
    return 3;
  iBaseResult = 0;
  if ( (_S5_112 & 1) == 0 )
  {
    _S5_112 |= 1u;
    v9 = _KeyValuesSystem(a1: this);
    keyBase = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 12))(a1: v9, a2: "base", a3: 1);
  }
  if ( (_S5_112 & 2) == 0 )
  {
    _S5_112 |= 2u;
    v10 = _KeyValuesSystem(a1: this);
    keyBlockLOS = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v10 + 12))(a1: v10, a2: "blockLOS", a3: 1);
  }
  if ( (_S5_112 & 4) == 0 )
  {
    _S5_112 |= 4u;
    v11 = _KeyValuesSystem(a1: this);
    keyAIWalkable = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 12))(
                      a1: v11,
                      a2: "AIWalkable",
                      a3: 1);
  }
  if ( (_S5_112 & 8) == 0 )
  {
    _S5_112 |= 8u;
    v12 = _KeyValuesSystem(a1: this);
    keyDamageTable = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v12 + 12))(
                       a1: v12,
                       a2: "damage_table",
                       a3: 1);
  }
  if ( (_S5_112 & 0x10) == 0 )
  {
    _S5_112 |= 0x10u;
    v13 = _KeyValuesSystem(a1: this);
    keyPhysicsMode = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 12))(
                       a1: v13,
                       a2: "physicsmode",
                       a3: 1);
  }
  if ( (_S5_112 & 0x20) == 0 )
  {
    _S5_112 |= 0x20u;
    v14 = _KeyValuesSystem(a1: this);
    keyMultiplayerBreak = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v14 + 12))(
                            a1: v14,
                            a2: "multiplayer_break",
                            a3: 1);
  }
  if ( (_S5_112 & 0x40) == 0 )
  {
    _S5_112 |= 0x40u;
    v15 = _KeyValuesSystem(a1: this);
    keyDmgBullets = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 12))(
                      a1: v15,
                      a2: "dmg.bullets",
                      a3: 1);
  }
  if ( (_S5_112 & 0x80u) == 0 )
  {
    _S5_112 |= 0x80u;
    v16 = _KeyValuesSystem(a1: this);
    keyDmgClub = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v16 + 12))(a1: v16, a2: "dmg.club", a3: 1);
  }
  if ( (_S5_112 & 0x100) == 0 )
  {
    _S5_112 |= 0x100u;
    v17 = _KeyValuesSystem(a1: this);
    keyDmgExplosive = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v17 + 12))(
                        a1: v17,
                        a2: "dmg.explosive",
                        a3: 1);
  }
  if ( (_S5_112 & 0x200) == 0 )
  {
    _S5_112 |= 0x200u;
    v18 = _KeyValuesSystem(a1: this);
    keyHealth = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v18 + 12))(a1: v18, a2: "health", a3: 1);
  }
  if ( (_S5_112 & 0x400) == 0 )
  {
    _S5_112 |= 0x400u;
    v19 = _KeyValuesSystem(a1: this);
    keyBreakableModel = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v19 + 12))(
                          a1: v19,
                          a2: "breakable_model",
                          a3: 1);
  }
  if ( (_S5_112 & 0x800) == 0 )
  {
    _S5_112 |= 0x800u;
    v20 = _KeyValuesSystem(a1: this);
    keyBreakableSkin = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v20 + 12))(
                         a1: v20,
                         a2: "breakable_skin",
                         a3: 1);
  }
  if ( (_S5_112 & 0x1000) == 0 )
  {
    _S5_112 |= 0x1000u;
    v21 = _KeyValuesSystem(a1: this);
    keyBreakableCount = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v21 + 12))(
                          a1: v21,
                          a2: "breakable_count",
                          a3: 1);
  }
  if ( (_S5_112 & 0x2000) == 0 )
  {
    _S5_112 |= 0x2000u;
    v22 = _KeyValuesSystem(a1: this);
    keyExplosiveDamage = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v22 + 12))(
                           a1: v22,
                           a2: "explosive_damage",
                           a3: 1);
  }
  if ( (_S5_112 & 0x4000) == 0 )
  {
    _S5_112 |= 0x4000u;
    v23 = _KeyValuesSystem(a1: this);
    keyExplosiveRadius = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v23 + 12))(
                           a1: v23,
                           a2: "explosive_radius",
                           a3: 1);
  }
  if ( (_S5_112 & 0x8000) == 0 )
  {
    _S5_112 |= 0x8000u;
    v24 = _KeyValuesSystem(a1: this);
    keyAllowStatic = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v24 + 12))(
                       a1: v24,
                       a2: "allowstatic",
                       a3: 1);
  }
  v25 = pSection;
  Key = KeyValues::FindKey(this: pSection, keySymbol: keyBase);
  if ( Key == nullptr
    || (v27 = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: prType)) == nullptr
    || *v27 == 0
    || (result = CPropData::ParsePropFromBase(this: v86, pProp, pBreakableInterface, pszPropData: v27),
        iBaseResult = result,
        result <= 1) )
  {
    v28 = KeyValues::FindKey(this: pSection, keySymbol: keyBlockLOS);
    v29 = -1.0;
    if ( v28 != nullptr )
    {
      *(float *)&v86 = KeyValues::GetFloat(this: v28, keyName: nullptr, defaultValue: -1.0);
      v29 = *(float *)&v86;
    }
    if ( (int)v29 != -1 )
      pBreakableInterface->SetPropDataBlocksLOS(this: pBreakableInterface, a2: (int)v29 != 0);
    v30 = KeyValues::FindKey(this: pSection, keySymbol: keyAIWalkable);
    v31 = -1.0;
    if ( v30 != nullptr )
    {
      *(float *)&v86 = KeyValues::GetFloat(this: v30, keyName: nullptr, defaultValue: -1.0);
      v31 = *(float *)&v86;
    }
    if ( (int)v31 != -1 )
      pBreakableInterface->SetPropDataIsAIWalkable(this: pBreakableInterface, a2: (int)v31 != 0);
    if ( ((int (__thiscall *)(IBreakableWithPropData *, int, int))pBreakableInterface->GetPhysicsDamageTable)(
           a1: pBreakableInterface,
           a2,
           a3) != 0 )
    {
      v34 = pBreakableInterface->GetPhysicsDamageTable(this: pBreakableInterface);
      v35 = KeyValues::FindKey(this: pSection, keySymbol: keyDamageTable);
      if ( v35 != nullptr )
        String = KeyValues::GetString(this: v35, keyName: nullptr, defaultValue: v34);
      else
        String = v34;
    }
    else
    {
      v32 = KeyValues::FindKey(this: pSection, keySymbol: keyDamageTable);
      if ( v32 == nullptr )
        goto LABEL_56;
      String = KeyValues::GetString(this: v32, keyName: nullptr, defaultValue: nullptr);
    }
    if ( String != nullptr && *String != 0 )
    {
      v36 = pBreakableInterface->__vftable;
      v37 = AllocPooledString(pszValue: String);
      v36->SetPhysicsDamageTable(this: pBreakableInterface, a2: v37);
      goto LABEL_57;
    }
LABEL_56:
    pBreakableInterface->SetPhysicsDamageTable(this: pBreakableInterface, a2: nullptr);
LABEL_57:
    v38 = pBreakableInterface->GetPhysicsMode(this: pBreakableInterface);
    v39 = KeyValues::FindKey(this: pSection, keySymbol: keyPhysicsMode);
    if ( v39 != nullptr )
      Int = KeyValues::GetInt(this: v39, keyName: nullptr, defaultValue: v38);
    else
      Int = v38;
    pBreakableInterface->SetPhysicsMode(this: pBreakableInterface, a2: Int);
    v41 = KeyValues::FindKey(this: pSection, keySymbol: keyMultiplayerBreak);
    if ( v41 != nullptr )
    {
      v42 = KeyValues::GetString(this: v41, keyName: nullptr, defaultValue: nullptr);
      v43 = v42;
      if ( v42 != nullptr )
      {
        v44 = MULTIPLAYER_BREAK_DEFAULT;
        if ( _V_stricmp(s1: v42, s2: "server") != 0 )
        {
          if ( _V_stricmp(s1: v43, s2: "client") != 0 )
          {
            if ( _V_stricmp(s1: v43, s2: "both") == 0 )
              v44 = MULTIPLAYER_BREAK_BOTH;
          }
          else
          {
            v44 = MULTIPLAYER_BREAK_CLIENTSIDE;
          }
        }
        else
        {
          v44 = MULTIPLAYER_BREAK_SERVERSIDE;
        }
        pBreakableInterface->SetMultiplayerBreakMode(this: pBreakableInterface, a2: v44);
        v25 = pSection;
      }
    }
    pSectiona = pBreakableInterface->GetDmgModBullet(this: pBreakableInterface);
    v45 = KeyValues::FindKey(this: v25, keySymbol: keyDmgBullets);
    v46 = pSectiona;
    if ( v45 != nullptr )
    {
      pSectiond = KeyValues::GetFloat(this: v45, keyName: nullptr, defaultValue: pSectiona);
      v46 = pSectiond;
    }
    ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))pBreakableInterface->SetDmgModBullet)(
      a1: pBreakableInterface,
      a2: LODWORD(v46));
    pSectionb = pBreakableInterface->GetDmgModClub(this: pBreakableInterface);
    v47 = KeyValues::FindKey(this: v25, keySymbol: keyDmgClub);
    v48 = pSectionb;
    if ( v47 != nullptr )
    {
      pSectione = KeyValues::GetFloat(this: v47, keyName: nullptr, defaultValue: pSectionb);
      v48 = pSectione;
    }
    ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))pBreakableInterface->SetDmgModClub)(
      a1: pBreakableInterface,
      a2: LODWORD(v48));
    pSectionc = pBreakableInterface->GetDmgModExplosive(this: pBreakableInterface);
    v49 = KeyValues::FindKey(this: v25, keySymbol: keyDmgExplosive);
    v50 = pSectionc;
    if ( v49 != nullptr )
    {
      pSectionf = KeyValues::GetFloat(this: v49, keyName: nullptr, defaultValue: pSectionc);
      v50 = pSectionf;
    }
    ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))pBreakableInterface->SetDmgModExplosive)(
      a1: pBreakableInterface,
      a2: LODWORD(v50));
    if ( !FClassnameIs(pEntity: pProp, szClassname: "prop_physics_override")
      && !FClassnameIs(pEntity: pProp, szClassname: "prop_dynamic_override") )
    {
      v51 = pProp->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v52 = pProp->GetHealth(this: pProp);
      v53 = KeyValues::GetInt(this: v25, keySymbol: keyHealth, defaultValue: v52);
      v51->SetHealth(this: pProp, a2: v53);
      v54 = pBreakableInterface->__vftable;
      v81 = pBreakableInterface->GetExplosiveDamage(this: pBreakableInterface);
      Float = KeyValues::GetFloat(this: v25, keySymbol: keyExplosiveDamage, defaultValue: v81);
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v54->SetExplosiveDamage)(
        a1: pBreakableInterface,
        a2: LODWORD(Float));
      v55 = pBreakableInterface->__vftable;
      v83 = pBreakableInterface->GetExplosiveRadius(this: pBreakableInterface);
      v84 = KeyValues::GetFloat(this: v25, keySymbol: keyExplosiveRadius, defaultValue: v83);
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v55->SetExplosiveRadius)(
        a1: pBreakableInterface,
        a2: LODWORD(v84));
    }
    if ( pBreakableInterface->GetBreakableModel(this: pBreakableInterface) != nullptr )
    {
      v58 = pBreakableInterface->GetBreakableModel(this: pBreakableInterface);
      v59 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableModel);
      if ( v59 != nullptr )
        v57 = KeyValues::GetString(this: v59, keyName: nullptr, defaultValue: v58);
      else
        v57 = v58;
    }
    else
    {
      v56 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableModel);
      if ( v56 == nullptr )
        goto LABEL_87;
      v57 = KeyValues::GetString(this: v56, keyName: nullptr, defaultValue: nullptr);
    }
    if ( v57 != nullptr && *v57 != 0 )
    {
      v60 = pBreakableInterface->__vftable;
      v61 = AllocPooledString(pszValue: v57);
      v60->SetBreakableModel(this: pBreakableInterface, a2: v61);
      goto LABEL_88;
    }
LABEL_87:
    pBreakableInterface->SetBreakableModel(this: pBreakableInterface, a2: nullptr);
LABEL_88:
    v62 = pBreakableInterface->GetBreakableSkin(this: pBreakableInterface);
    v63 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableSkin);
    if ( v63 != nullptr )
      v64 = KeyValues::GetInt(this: v63, keyName: nullptr, defaultValue: v62);
    else
      v64 = v62;
    pBreakableInterface->SetBreakableSkin(this: pBreakableInterface, a2: v64);
    v65 = pBreakableInterface->GetBreakableCount(this: pBreakableInterface);
    v66 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableCount);
    if ( v66 != nullptr )
      v67 = KeyValues::GetInt(this: v66, keyName: nullptr, defaultValue: v65);
    else
      v67 = v65;
    pBreakableInterface->SetBreakableCount(this: pBreakableInterface, a2: v67);
    v68 = AllocTempVector();
    v68->x = pProp->m_Collision.m_vecMaxs.m_Value.x - pProp->m_Collision.m_vecMins.m_Value.x;
    v68->y = pProp->m_Collision.m_vecMaxs.m_Value.y - pProp->m_Collision.m_vecMins.m_Value.y;
    v68->z = pProp->m_Collision.m_vecMaxs.m_Value.z - pProp->m_Collision.m_vecMins.m_Value.z;
    z = v68->z;
    *(_QWORD *)&vecSize.x = *(_QWORD *)&v68->x;
    vecSize.z = z;
    if ( vecSize.y <= vecSize.x )
    {
      v70 = 1;
      if ( vecSize.z > vecSize.y )
        goto LABEL_99;
    }
    else if ( vecSize.z > vecSize.x )
    {
      v70 = 0;
      goto LABEL_99;
    }
    v70 = 2;
LABEL_99:
    v71.m128d_f64[0] = 4.503599627370496e15;
    *((_DWORD *)&vecSize.x + v70) = 1065353216;
    y_low = (__m128)LODWORD(vecSize.y);
    y_low.m128_f32[0] = (float)((float)(vecSize.y * vecSize.x) * vecSize.z) * 0.0009765625;
    v73 = _mm_cvtps_pd(y_low);
    v74 = _mm_and_pd((__m128d)0x8000000000000000uLL, v73);
    *(double *)y_low.m128_u64 = _mm_cmplt_sd(_mm_xor_pd(v73, v74), v71).m128d_f64[0];
    *(double *)y_low.m128_u64 = v73.m128d_f64[0]
                              + COERCE_DOUBLE(y_low.m128_u64[0] & 0x4330000000000000LL | *(_QWORD *)&v74.m128d_f64[0])
                              - COERCE_DOUBLE(y_low.m128_u64[0] & 0x4330000000000000LL | *(_QWORD *)&v74.m128d_f64[0]);
    v71.m128d_f64[1] = v73.m128d_f64[1];
    v71.m128d_f64[0] = *(double *)y_low.m128_u64 - v73.m128d_f64[0];
    pBreakableInterface->SetMaxBreakableSize(
      this: pBreakableInterface,
      a2: (int)(*(double *)y_low.m128_u64
          - COERCE_DOUBLE(*(_QWORD *)&_mm_cmpgt_sd(v71, v74).m128d_f64[0] & 0x3FF0000000000000LL)));
    i = PROPINTER_PHYSGUN_WORLD_STICK;
    p_m_keyKeyName = &sPropdataInteractionSections[0].m_keyKeyName;
    do
    {
      if ( *(p_m_keyKeyName - 4) != 0 )
      {
        v76 = KeyValues::FindKey(this: pInteractionSection, keySymbol: *(p_m_keyKeyName - 1));
        if ( v76 != nullptr )
        {
          v77 = KeyValues::FindKey(this: v76, keySymbol: *p_m_keyKeyName);
          if ( v77 != nullptr )
          {
            v78 = KeyValues::GetString(this: v77, keyName: nullptr, defaultValue: prType);
            if ( v78 != nullptr && *v78 != 0 && _V_stricmp(s1: v78, s2: (const char *)*(p_m_keyKeyName - 2)) == 0 )
              pBreakableInterface->SetInteraction(this: pBreakableInterface, a2: i);
          }
        }
      }
      result = 1;
      ++i;
      p_m_keyKeyName += 5;
    }
    while ( (int)p_m_keyKeyName < (int)&aCbreakparser[4] );
    if ( iBaseResult != 1 )
    {
      v79 = KeyValues::FindKey(this: v25, keySymbol: keyAllowStatic);
      return v79 != nullptr && KeyValues::GetInt(this: v79, keyName: nullptr, defaultValue: 0) != 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101576B0
// Name: public: int CPropData::ParsePropFromBase(class C_BaseEntity __near *,class IBreakableWithPropData __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPropData::ParsePropFromBase(
        CPropData *this,
        C_BaseEntity *pProp,
        IBreakableWithPropData *pBreakableInterface,
        const char *pszPropData)
{
  KeyValues *m_pKVPropData; // ecx
  KeyValues *Key; // esi
  char *Classname; // eax
  const char *v9; // eax
  const char *ModelName; // [esp-14h] [ebp-18h]
  IBreakableWithPropData *pBreakableInterfacea; // [esp+10h] [ebp+Ch]

  if ( !this->m_bPropDataLoaded )
    return 2;
  if ( pBreakableInterface == nullptr )
    return 3;
  m_pKVPropData = this->m_pKVPropData;
  if ( m_pKVPropData == nullptr )
    return 3;
  Key = KeyValues::FindKey(this: m_pKVPropData, keyName: pszPropData, bCreate: false);
  if ( Key != nullptr )
  {
    if ( pBreakableInterface->GetBasePropData(this: pBreakableInterface) == nullptr )
    {
      pBreakableInterfacea = (IBreakableWithPropData *)pBreakableInterface->__vftable;
      v9 = AllocPooledString(pszValue: pszPropData);
      ((void (__thiscall *)(IBreakableWithPropData *, const char *))pBreakableInterfacea[29].__vftable)(
        a1: pBreakableInterface,
        a2: v9);
    }
    return CPropData::ParsePropFromKV(
             this,
             a2: (int)pszPropData,
             a3: (int)pBreakableInterface,
             pProp,
             pBreakableInterface,
             pSection: Key,
             pInteractionSection: Key);
  }
  else
  {
    ModelName = C_BaseEntity::GetModelName(this: pProp);
    Classname = C_BaseEntity::GetClassname(this: pProp);
    _Warning(
      a1: "%s '%s' has a base specified as '%s', but there is no matching entry in propdata.txt.\n",
      Classname,
      ModelName,
      pszPropData);
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10157770
// Name: public: char const __near * CPropData::GetRandomChunkModel(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPropData::GetRandomChunkModel(
        CPropData *this,
        const char *pszBreakableSection,
        IUniformRandomStream *iMaxSize)
{
  int m_Size; // eax
  int v6; // esi
  int v7; // edi
  int v8; // esi
  int v9; // eax
  int iCount; // [esp+8h] [ebp-4h]

  if ( !this->m_bPropDataLoaded )
    return nullptr;
  m_Size = this->m_BreakableChunks.m_Size;
  v6 = 0;
  iCount = m_Size;
  if ( m_Size > 0 )
  {
    v7 = 0;
    do
    {
      if ( V_strncmp(
             s1: this->m_BreakableChunks.m_Memory.m_pMemory[v7].iszChunkType,
             s2: pszBreakableSection,
             count: strlen(pszBreakableSection)) == 0 )
        break;
      ++v6;
      ++v7;
    }
    while ( v6 < iCount );
    m_Size = iCount;
  }
  if ( v6 == m_Size )
    return nullptr;
  v8 = v6;
  if ( iMaxSize == (IUniformRandomStream *)-1 )
  {
    v9 = this->m_BreakableChunks.m_Memory.m_pMemory[v8].iszChunkModels.m_Size - 1;
  }
  else
  {
    v9 = this->m_BreakableChunks.m_Memory.m_pMemory[v8].iszChunkModels.m_Size - 1;
    if ( (int)iMaxSize < v9 )
      v9 = (int)iMaxSize;
  }
  return this->m_BreakableChunks.m_Memory.m_pMemory[v8].iszChunkModels.m_Memory.m_pMemory[_RandomInt(
                                                                                            this: iMaxSize,
                                                                                            a2: 0,
                                                                                            a3: v9)];
}

//------------------------------------------------------------------------------
// Address: 0x10157890
// Name: void BreakModelList(class CUtlVector<struct breakmodel_t,class CUtlMemory<struct breakmodel_t,int>> __near &,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BreakModelList(
        int a1@<ebx>,
        CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > *list,
        int modelindex,
        float defBurstScale,
        int defCollisionGroup)
{
  vcollide_t *v5; // eax
  int v6; // ebx
  int (__thiscall *v7)(int); // eax
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  breakmodel_t *m_pMemory; // ecx
  int v12; // eax
  CBreakParser breakParser; // [esp+0h] [ebp-10h] BYREF

  v5 = modelinfo->GetVCollide(this: modelinfo, a2: modelindex);
  if ( v5 != nullptr )
  {
    v6 = ((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, int))physcollision->VPhysicsKeyParserCreate)(
           a1: physcollision,
           a2: v5,
           a3: a1);
    while ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6) == 0 )
    {
      v7 = *(int (__thiscall **)(int))(*(_DWORD *)v6 + 4);
      breakParser.m_defaultCollisionGroup = defCollisionGroup;
      breakParser.__vftable = (CBreakParser_vtbl *)&CBreakParser::`vftable';
      breakParser.m_defaultBurstScale = defBurstScale;
      v8 = (const char *)v7(a1: v6);
      if ( _V_stricmp(s1: v8, s2: "break") != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6);
      }
      else
      {
        m_Size = list->m_Size;
        m_nAllocationCount = list->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<breakmodel_t,int>::Grow(this: &list->m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++list->m_Size;
        m_pMemory = list->m_Memory.m_pMemory;
        v12 = list->m_Size - m_Size - 1;
        list->m_pElements = list->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 1068 * v12);
        (*(void (__thiscall **)(int, breakmodel_t *, CBreakParser *))(*(_DWORD *)v6 + 28))(
          a1: v6,
          a2: &list->m_Memory.m_pMemory[m_Size],
          a3: &breakParser);
      }
    }
    ((void (__thiscall *)(IPhysicsCollision *))physcollision->VPhysicsKeyParserDestroy)(a1: physcollision);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101579B0
// Name: void PropBreakableCreateAll(int,class IPhysicsObject __near *,struct breakablepropparams_t const __near &,class C_BaseEntity __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall PropBreakableCreateAll(
        int a1@<ebx>,
        int a2@<esi>,
        int modelindex,
        IPhysicsObject *pPhysics,
        const breakablepropparams_t *params,
        C_BaseEntity *pEntity,
        int iPrecomputedBreakableCount,
        bool bIgnoreGibLimit,
        bool defaultLocation)
{
  int v9; // eax
  int m_nValue; // eax
  C_BaseEntity *v11; // eax
  C_BaseAnimating *v12; // esi
  C_BaseAnimating *v13; // eax
  const struct model_t *v14; // eax
  const studiohdr_t *v15; // eax
  int v16; // eax
  int v17; // eax
  const char *v18; // esi
  int v19; // edi
  const struct model_t *v20; // eax
  const studiohdr_t *v21; // eax
  Vector *angles; // eax
  C_BaseAnimating *v23; // esi
  mp_break_t *v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // eax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  Vector *velocity; // eoff
  int v32; // eax
  C_BaseEntity *v33; // edi
  C_ClientRagdoll *v34; // eax
  C_BaseEntity *v35; // esi
  mp_break_t *v36; // edi
  float *v37; // eax
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // ecx
  unsigned __int8 r; // cl
  unsigned __int8 g; // dl
  int *v44; // eax
  int *v45; // edi
  int (__thiscall *v46)(int *); // eax
  const char *v47; // eax
  char *RandomChunkModel; // eax
  IUniformRandomStream *v49; // ecx
  Vector *v50; // eax
  float v51; // edx
  int v52; // eax
  const Vector *origin; // eax
  float v54; // xmm0_4
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // eax
  int v56; // eax
  int v57; // edx
  float v58; // ecx
  int (__thiscall *v59)(int *); // eax
  int v60; // eax
  C_ClientRagdoll *v61; // esi
  Vector *v62; // eax
  float v63; // ecx
  IPhysicsObject *v64; // ecx
  unsigned __int8 v65; // cl
  unsigned __int8 v66; // dl
  int (__thiscall *v67)(int *); // eax
  int v68; // esi
  IMDLCache *v69; // [esp-8h] [ebp-660h]
  const char *v70; // [esp-8h] [ebp-660h]
  int defBurstScale; // [esp+0h] [ebp-658h]
  IMDLCache *v72; // [esp+Ch] [ebp-64Ch]
  breakmodel_t breakModel; // [esp+28h] [ebp-630h] BYREF
  CStudioHdr studioHdr; // [esp+454h] [ebp-204h] BYREF
  CStudioHdr parentStudioHdr; // [esp+4B8h] [ebp-1A0h] BYREF
  matrix3x4_t burstCenterTransform; // [esp+51Ch] [ebp-13Ch] BYREF
  matrix3x4_t matrix; // [esp+54Ch] [ebp-10Ch] BYREF
  matrix3x4_t localToWorld; // [esp+57Ch] [ebp-DCh] BYREF
  Vector pos; // [esp+5ACh] [ebp-ACh] BYREF
  Vector vecBreakableObbSize; // [esp+5B8h] [ebp-A0h] BYREF
  CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > list; // [esp+5C4h] [ebp-94h] BYREF
  Vector vecVelocity; // [esp+5D8h] [ebp-80h] BYREF
  int nSkin; // [esp+5E4h] [ebp-74h]
  C_BaseAnimating *pOwnerAnim; // [esp+5E8h] [ebp-70h]
  Vector vecMaxs; // [esp+5ECh] [ebp-6Ch] BYREF
  Vector parentOrigin; // [esp+5F8h] [ebp-60h] BYREF
  int nPropCount; // [esp+604h] [ebp-54h]
  Vector vecMins; // [esp+608h] [ebp-50h] BYREF
  Vector burstCenter; // [esp+614h] [ebp-44h] BYREF
  C_BaseEntity *pOwnerEntity; // [esp+620h] [ebp-38h]
  Vector position; // [esp+624h] [ebp-34h] BYREF
  Vector vecObbSize; // [esp+630h] [ebp-28h] BYREF
  QAngle vecAngles; // [esp+63Ch] [ebp-1Ch] BYREF
  int i; // [esp+648h] [ebp-10h]
  color24 renderColor; // [esp+64Ch] [ebp-Ch]
  mp_break_t *p_mpBreakMode; // [esp+654h] [ebp-4h]

  if ( props_break_max_pieces_perframe.m_pParent != nullptr )
  {
    nPropCount = props_break_max_pieces_perframe.m_pParent->m_Value.m_nValue;
    if ( nPropCount == -1 )
      goto LABEL_6;
  }
  else
  {
    nPropCount = 0;
  }
  v9 = *(_DWORD *)(gpGlobals.m_Index + 4);
  if ( nFrameNumber != v9 )
  {
    nPropBreakablesPerFrameCount = 0;
    nFrameNumber = v9;
  }
  if ( nPropBreakablesPerFrameCount < nPropCount )
  {
LABEL_6:
    if ( !bIgnoreGibLimit )
    {
      if ( props_break_max_pieces.m_pParent == nullptr )
      {
        m_nValue = 0;
        goto LABEL_9;
      }
      m_nValue = props_break_max_pieces.m_pParent->m_Value.m_nValue;
      if ( m_nValue != -1 )
      {
LABEL_9:
        if ( iPrecomputedBreakableCount == -1 || m_nValue < iPrecomputedBreakableCount )
          iPrecomputedBreakableCount = m_nValue;
      }
    }
    if ( ((int (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->GetVCollide)(
           a1: modelinfo,
           a2: modelindex,
           a3: a1) == 0 )
      return;
    v11 = pEntity;
    v12 = nullptr;
    nSkin = 0;
    pOwnerEntity = pEntity;
    pOwnerAnim = nullptr;
    if ( pPhysics != nullptr )
    {
      v11 = (C_BaseEntity *)((int (__thiscall *)(IPhysicsObject *, int))pPhysics->GetGameData)(a1: pPhysics, a2);
      pOwnerEntity = v11;
    }
    if ( v11 != nullptr )
    {
      v13 = v11->GetBaseAnimating(this: v11);
      v12 = v13;
      pOwnerAnim = v13;
      if ( v13 != nullptr )
        nSkin = v13->GetSkin(this: &v13->IClientRenderable);
    }
    CStudioHdr::CStudioHdr(this: &parentStudioHdr);
    v14 = modelinfo->GetModel(this: modelinfo, a2: modelindex);
    if ( v14 != nullptr )
    {
      v72 = (IMDLCache *)v14;
      v15 = (const studiohdr_t *)((int (__thiscall *)(IVModelInfoClient *))modelinfo->GetStudiomodel)(a1: modelinfo);
      CStudioHdr::Init(this: &parentStudioHdr, pStudioHdr: v15, mdlcache: v72);
    }
    parentOrigin = vec3_origin;
    v16 = Studio_FindAttachment(pStudioHdr: &parentStudioHdr, pAttachmentName: "placementOrigin") + 1;
    if ( v16 <= 0 )
    {
      AngleMatrix(angles: &vec3_angle, matrix: &localToWorld);
    }
    else
    {
      GetAttachmentLocalSpace(pstudiohdr: &parentStudioHdr, attachIndex: v16 - 1, pLocalToWorld: &localToWorld);
      MatrixGetColumn(in: &localToWorld, column: 3, out: &parentOrigin);
    }
    AngleMatrix(angles: params->angles, position: params->origin, &matrix);
    burstCenter = *params->origin;
    v17 = Studio_FindAttachment(pStudioHdr: &parentStudioHdr, pAttachmentName: "burstCenter") + 1;
    if ( v17 > 0 )
    {
      if ( v12 != nullptr )
      {
        v12->GetAttachment(this: &v12->IClientRenderable, a2: v17, a3: &burstCenterTransform);
        MatrixGetColumn(in: &burstCenterTransform, column: 3, out: &burstCenter);
      }
      else
      {
        GetAttachmentLocalSpace(pstudiohdr: &parentStudioHdr, attachIndex: v17 - 1, pLocalToWorld: &localToWorld);
        MatrixGetColumn(in: &localToWorld, column: 3, out: &burstCenter);
        vecMins.x = burstCenter.x - parentOrigin.x;
        vecMins.y = burstCenter.y - parentOrigin.y;
        vecMins.z = burstCenter.z - parentOrigin.z;
        VectorTransform(in1: &vecMins.x, in2: &matrix, out: &burstCenter.x);
      }
    }
    memset(&list, 0, sizeof(list));
    CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int>>::EnsureCapacity(this: &list, num: 20);
    BreakModelList(
      a1: (int)params,
      &list,
      modelindex,
      defBurstScale: params->defBurstScale,
      defCollisionGroup: params->defCollisionGroup);
    if ( list.m_Size != 0 )
    {
      i = 0;
      if ( list.m_Size > 0 )
      {
        p_mpBreakMode = &list.m_Memory.m_pMemory->mpBreakMode;
        while ( 1 )
        {
          v18 = (const char *)(p_mpBreakMode - 263);
          v19 = modelinfo->GetModelIndex(this: modelinfo, a2: (const char *)(p_mpBreakMode - 263));
          if ( v19 > 0 )
          {
            if ( *(int *)(gpGlobals.m_Index + 20) <= 1
              || *p_mpBreakMode != MULTIPLAYER_BREAK_SERVERSIDE
              && (defaultLocation || *p_mpBreakMode != MULTIPLAYER_BREAK_DEFAULT) )
            {
              if ( nPropCount != -1 && nPropBreakablesPerFrameCount > nPropCount
                || iPrecomputedBreakableCount != -1 && i >= iPrecomputedBreakableCount )
              {
                goto LABEL_95;
              }
              CStudioHdr::CStudioHdr(this: &studioHdr);
              v20 = modelinfo->GetModel(this: modelinfo, a2: v19);
              if ( v20 != nullptr )
              {
                v69 = (IMDLCache *)v20;
                v21 = (const studiohdr_t *)((int (__thiscall *)(IVModelInfoClient *))modelinfo->GetStudiomodel)(a1: modelinfo);
                CStudioHdr::Init(this: &studioHdr, pStudioHdr: v21, mdlcache: v69);
              }
              angles = (Vector *)params->angles;
              v23 = pOwnerAnim;
              ++nPropBreakablesPerFrameCount;
              v24 = p_mpBreakMode;
              position = vec3_origin;
              vecMaxs = *angles;
              if ( pOwnerAnim != nullptr && *((_BYTE *)p_mpBreakMode - 540) != 0 )
              {
                v70 = (const char *)(p_mpBreakMode - 135);
                if ( *((_BYTE *)p_mpBreakMode - 3) != 0 )
                {
                  v25 = C_BaseAnimating::LookupBone(this: pOwnerAnim, szName: v70);
                  if ( v25 >= 0 )
                  {
                    C_BaseAnimating::GetBonePosition(
                      this: v23,
                      iBone: v25,
                      origin: &position,
                      angles: (QAngle *)&vecMaxs);
                    AngleMatrix(angles: (const QAngle *)&vecMaxs, &position, &matrix);
                  }
                }
                else
                {
                  v26 = Studio_FindAttachment(pStudioHdr: &studioHdr, pAttachmentName: v70) + 1;
                  if ( v26 > 0 )
                  {
                    v23->GetAttachment(this: &v23->IClientRenderable, a2: v26, a3: &matrix);
                    MatrixAngles(a1: (int)&matrix, src: (const VMatrix *)&matrix, vAngles: (QAngle *)&vecMaxs);
                  }
                }
              }
              else
              {
                v27 = Studio_FindAttachment(pStudioHdr: &studioHdr, pAttachmentName: "placementOrigin") + 1;
                vecAngles = (QAngle)parentOrigin;
                if ( v27 <= 0 )
                {
                  z = vecAngles.z;
                  y = vecAngles.y;
                  x = vecAngles.x;
                }
                else
                {
                  GetAttachmentLocalSpace(pstudiohdr: &studioHdr, attachIndex: v27 - 1, pLocalToWorld: &localToWorld);
                  MatrixGetColumn(in: &localToWorld, column: 3, out: (Vector *)&vecAngles);
                  x = vecAngles.x - parentOrigin.x;
                  y = vecAngles.y - parentOrigin.y;
                  z = vecAngles.z - parentOrigin.z;
                  vecAngles.x = vecAngles.x - parentOrigin.x;
                  vecAngles.y = vecAngles.y - parentOrigin.y;
                  vecAngles.z = vecAngles.z - parentOrigin.z;
                }
                vecMins.x = *((float *)v24 - 266) - x;
                vecMins.y = *((float *)v24 - 265) - y;
                vecMins.z = *((float *)v24 - 264) - z;
                VectorTransform(in1: &vecMins.x, in2: &matrix, out: &position.x);
              }
              velocity = params->velocity;
              vecBreakableObbSize = *velocity;
              if ( pPhysics != nullptr )
                pPhysics->GetVelocityAtPoint(this: pPhysics, a2: &position, a3: &vecBreakableObbSize);
              v32 = nSkin;
              if ( nSkin > studioHdr.m_pStudioHdr->numskinfamilies )
                v32 = 0;
              v33 = pOwnerEntity;
              v34 = BreakModelCreateSingle(
                      pOwner: pOwnerEntity,
                      pModel: (breakmodel_t *)(p_mpBreakMode - 266),
                      &position,
                      angles: (const QAngle *)&vecMaxs,
                      velocity: &vecBreakableObbSize,
                      angVelocity: params->angularVelocity,
                      nSkin: v32);
              v35 = v34;
              if ( v34 != nullptr )
              {
                if ( v33 != nullptr && (v33->m_fEffects & 0x10) != 0 )
                  C_BaseEntity::AddEffects(this: v34, nEffects: 16);
                v36 = p_mpBreakMode;
                if ( *((float *)p_mpBreakMode - 3) != 0.0 )
                {
                  vecObbSize.x = position.x - burstCenter.x;
                  vecObbSize.y = position.y - burstCenter.y;
                  vecObbSize.z = position.z - burstCenter.z;
                  if ( Vector::operator==(this: (QAngle *)&vecObbSize, src: (const QAngle *)&vec3_origin) )
                  {
                    v37 = (float *)v35->WorldSpaceCenter(this: v35);
                    v38 = v37[1] - burstCenter.y;
                    v39 = v37[2] - burstCenter.z;
                    vecObbSize.x = *v37 - burstCenter.x;
                    vecObbSize.y = v38;
                    vecObbSize.z = v39;
                  }
                  VectorNormalize(vec: &vecObbSize);
                  v40 = *((float *)v36 - 3);
                  vecVelocity.x = vecObbSize.x * v40;
                  vecVelocity.y = vecObbSize.y * v40;
                  vecVelocity.z = vecObbSize.z * v40;
                  C_BaseEntity::ApplyAbsVelocityImpulse(this: v35, vecImpulse: &vecVelocity);
                }
                if ( *((_BYTE *)v36 - 2) != 0 )
                {
                  m_pPhysicsObject = v35->m_pPhysicsObject;
                  if ( m_pPhysicsObject != nullptr )
                    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: false);
                }
                if ( pEntity != nullptr )
                {
                  r = pEntity->m_clrRender.m_Value.r;
                  g = pEntity->m_clrRender.m_Value.g;
                  renderColor.b = pEntity->m_clrRender.m_Value.b;
                  renderColor.r = r;
                  renderColor.g = g;
                  C_BaseEntity::SetRenderColor(this: v35, r, g, b: renderColor.b);
                }
              }
              CStudioHdr::Term(this: &studioHdr);
              CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
              CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
              CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
            }
          }
          else
          {
            _Warning(a1: "Unable to create non-precached breakmodel %s\n", v18);
          }
          p_mpBreakMode += 267;
          if ( ++i >= list.m_Size )
            goto LABEL_95;
        }
      }
      goto LABEL_95;
    }
    if ( pEntity == nullptr
      || (v44 = (int *)__RTDynamicCast(
                         inptr: pEntity,
                         VfDelta: 0,
                         SrcType: &C_BaseEntity `RTTI Type Descriptor',
                         TargetType: &IBreakableWithPropData `RTTI Type Descriptor',
                         isReference: 0),
          v45 = v44,
          v44 == nullptr)
      || (*(int (__thiscall **)(int *))(*v44 + 56))(a1: v44) == 0
      || (*(int (__thiscall **)(int *))(*v45 + 72))(a1: v45) == 0
      || (v46 = *(int (__thiscall **)(int *))(*v45 + 72), i = 0, v46(a1: v45) <= 0) )
    {
LABEL_95:
      if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      CStudioHdr::Term(this: &parentStudioHdr);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&parentStudioHdr.m_boneParent);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&parentStudioHdr.m_boneFlags);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&parentStudioHdr.m_pStudioHdrCache);
      return;
    }
    while ( 1 )
    {
      if ( iPrecomputedBreakableCount != -1 && i >= iPrecomputedBreakableCount )
        goto LABEL_95;
      defBurstScale = (*(int (__thiscall **)(int *))(*v45 + 80))(a1: v45);
      v47 = (const char *)(*(int (__thiscall **)(int *))(*v45 + 56))(a1: v45);
      RandomChunkModel = (char *)CPropData::GetRandomChunkModel(
                                   this: &g_PropDataSystem,
                                   pszBreakableSection: v47,
                                   iMaxSize: defBurstScale);
      V_strncpy(pDest: breakModel.modelName, pSrc: RandomChunkModel, maxLen: 512);
      breakModel.health = 1.0;
      breakModel.fadeTime = _RandomFloat(this: v49, a2: 5.0, a3: 10.0);
      breakModel.fadeMinDist = 0.0;
      breakModel.fadeMaxDist = 0.0;
      breakModel.burstScale = params->defBurstScale;
      breakModel.collisionGroup = 1;
      breakModel.isRagdoll = false;
      breakModel.placementName[0] = 0;
      *(_WORD *)&breakModel.placementIsBone = 0;
      v50 = AllocTempVector();
      v50->x = pEntity->m_Collision.m_vecMaxs.m_Value.x - pEntity->m_Collision.m_vecMins.m_Value.x;
      v50->y = pEntity->m_Collision.m_vecMaxs.m_Value.y - pEntity->m_Collision.m_vecMins.m_Value.y;
      v50->z = pEntity->m_Collision.m_vecMaxs.m_Value.z - pEntity->m_Collision.m_vecMins.m_Value.z;
      v51 = v50->z;
      *(_QWORD *)&vecObbSize.x = *(_QWORD *)&v50->x;
      vecObbSize.z = v51;
      if ( vecObbSize.y <= vecObbSize.x )
      {
        v52 = 1;
        if ( vecObbSize.z <= vecObbSize.y )
LABEL_86:
          v52 = 2;
      }
      else
      {
        if ( vecObbSize.z <= vecObbSize.x )
          goto LABEL_86;
        v52 = 0;
      }
      memset((void *)&vecMins, 0, sizeof(vecMins));
      vecMaxs.x = 1.0;
      vecMaxs.y = 1.0;
      vecMaxs.z = 1.0;
      *((_DWORD *)&vecMins.x + v52) = 1056964608;
      *((_DWORD *)&vecMaxs.x + v52) = 1056964608;
      CCollisionProperty::RandomPointInBounds(
        this: &pEntity->m_Collision,
        vecNormalizedMins: &vecMins,
        vecNormalizedMaxs: &vecMaxs,
        pPoint: &breakModel.offset);
      origin = params->origin;
      position.x = breakModel.offset.x - params->origin->x;
      position.y = breakModel.offset.y - origin->y;
      position.z = breakModel.offset.z - origin->z;
      VectorNormalize(vec: &position);
      v54 = params->defBurstScale;
      vecVelocity.x = position.x * v54;
      GetAbsAngles = pEntity->GetAbsAngles;
      vecVelocity.y = position.y * v54;
      vecVelocity.z = position.z * v54;
      v56 = (int)GetAbsAngles(this: pEntity);
      v57 = *v45;
      *(_QWORD *)&vecAngles.x = *(_QWORD *)v56;
      v58 = *(float *)(v56 + 8);
      v59 = *(int (__thiscall **)(int *))(v57 + 64);
      vecAngles.z = v58;
      v60 = v59(a1: v45);
      v61 = BreakModelCreateSingle(
              pOwner: pOwnerEntity,
              pModel: &breakModel,
              position: &breakModel.offset,
              angles: &vecAngles,
              velocity: &vecVelocity,
              angVelocity: &vec3_origin,
              nSkin: v60);
      if ( v61 != nullptr )
      {
        v62 = AllocTempVector();
        v62->x = v61->m_Collision.m_vecMaxs.m_Value.x - v61->m_Collision.m_vecMins.m_Value.x;
        v62->y = v61->m_Collision.m_vecMaxs.m_Value.y - v61->m_Collision.m_vecMins.m_Value.y;
        v62->z = v61->m_Collision.m_vecMaxs.m_Value.z - v61->m_Collision.m_vecMins.m_Value.z;
        v63 = v62->z;
        *(_QWORD *)&vecBreakableObbSize.x = *(_QWORD *)&v62->x;
        vecBreakableObbSize.z = v63;
        AngleMatrix(angles: &vecAngles, matrix: &burstCenterTransform);
        AlignBoxes(boxExtents1: &vecObbSize, boxExtents2: &vecBreakableObbSize, pInOutMatrix: &burstCenterTransform);
        MatrixAngles(a1: (int)v61, src: (const VMatrix *)&burstCenterTransform, vAngles: &vecAngles);
        v64 = v61->m_pPhysicsObject;
        if ( v64 != nullptr )
        {
          v64->GetPosition(this: v64, a2: &pos, a3: nullptr);
          v61->m_pPhysicsObject->SetPosition(this: v61->m_pPhysicsObject, a2: &pos, a3: &vecAngles, a4: true);
        }
        C_BaseEntity::SetAbsAngles(this: v61, absAngles: &vecAngles);
        if ( (pOwnerEntity->m_fEffects & 0x10) != 0 )
          C_BaseEntity::AddEffects(this: v61, nEffects: 16);
        v65 = pEntity->m_clrRender.m_Value.r;
        v66 = pEntity->m_clrRender.m_Value.g;
        renderColor.b = pEntity->m_clrRender.m_Value.b;
        renderColor.r = v65;
        renderColor.g = v66;
        C_BaseEntity::SetRenderColor(this: v61, r: v65, g: v66, b: renderColor.b);
      }
      else
      {
        DevWarning(a1: "PropBreakableCreateAll: Could not create model %s\n", breakModel.modelName);
      }
      v67 = *(int (__thiscall **)(int *))(*v45 + 72);
      v68 = ++i;
      if ( v68 >= v67(a1: v45) )
        goto LABEL_95;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101585F0
// Name: public: void CPropData::ParsePropDataFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropData::ParsePropDataFile(CPropData *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // ecx
  bool v5; // al
  KeyValues *m_pKVPropData; // ecx
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *p_m_BreakableChunks; // edi
  const char *Name; // eax
  KeyValues *NextKey; // ebx
  char *v12; // esi
  const char *v13; // eax
  const char *v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  const char **v19; // edi
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *v20; // [esp+4h] [ebp-Ch]
  char *pooledName; // [esp+8h] [ebp-8h]
  const char *pooledNamea; // [esp+8h] [ebp-8h]
  KeyValues *pChunkSection; // [esp+Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "PropDatafile");
  else
    v3 = nullptr;
  this->m_pKVPropData = v3;
  if ( filesystem != nullptr )
    v4 = &filesystem->IBaseFileSystem;
  else
    v4 = nullptr;
  v5 = KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "scripts/propdata.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr);
  m_pKVPropData = this->m_pKVPropData;
  if ( v5 )
  {
    this->m_bPropDataLoaded = true;
    Key = KeyValues::FindKey(this: m_pKVPropData, keyName: "BreakableModels", bCreate: false);
    if ( Key != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
      pChunkSection = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        p_m_BreakableChunks = (CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *)&this->m_BreakableChunks;
        v20 = p_m_BreakableChunks;
        while ( 1 )
        {
          pooledName = (char *)&p_m_BreakableChunks->m_Memory.m_pMemory[CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int>>::InsertBefore(
                                                                          this: p_m_BreakableChunks,
                                                                          elem: p_m_BreakableChunks->m_Size)];
          Name = KeyValues::GetName(this: FirstSubKey);
          *(_DWORD *)pooledName = AllocPooledString(pszValue: Name);
          NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
          if ( NextKey != nullptr )
          {
            v12 = pooledName;
            do
            {
              v13 = KeyValues::GetName(this: NextKey);
              v14 = AllocPooledString(pszValue: v13);
              v15 = *((_DWORD *)v12 + 4);
              pooledNamea = v14;
              v16 = *((_DWORD *)v12 + 2);
              if ( v15 + 1 > v16 )
                CUtlMemory<CChoreoActor *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)(v12 + 4),
                  num: v15 - v16 + 1);
              ++*((_DWORD *)v12 + 4);
              v17 = *((_DWORD *)v12 + 1);
              v18 = *((_DWORD *)v12 + 4) - v15 - 1;
              *((_DWORD *)v12 + 5) = v17;
              if ( v18 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)(v17 + 4 * v15 + 4),
                  src: (unsigned __int8 *)(v17 + 4 * v15),
                  count: 4 * v18);
              v19 = (const char **)(*((_DWORD *)v12 + 1) + 4 * v15);
              if ( v19 != nullptr )
                *v19 = pooledNamea;
              C_BaseEntity::PrecacheModel(name: pooledNamea);
              NextKey = KeyValues::GetNextKey(this: NextKey);
            }
            while ( NextKey != nullptr );
            FirstSubKey = pChunkSection;
            p_m_BreakableChunks = v20;
          }
          pChunkSection = KeyValues::GetNextKey(this: FirstSubKey);
          if ( pChunkSection == nullptr )
            break;
          FirstSubKey = pChunkSection;
        }
      }
    }
  }
  else
  {
    KeyValues::deleteThis(this: m_pKVPropData);
    this->m_pKVPropData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101587D0
// Name: public: CPropData::CPropData(void)
// Source: json
//------------------------------------------------------------------------------
CPropData *__thiscall CPropData::CPropData(CPropData *this)
{
  int v2; // ecx
  int *p_m_keySection; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // eax

  CAutoGameSystem::CAutoGameSystem(this, name: "CPropData");
  this->__vftable = (CPropData_vtbl *)&CPropData::`vftable';
  this->m_BreakableChunks.m_Memory.m_pMemory = nullptr;
  this->m_BreakableChunks.m_Memory.m_nAllocationCount = 0;
  this->m_BreakableChunks.m_Memory.m_nGrowSize = 0;
  this->m_BreakableChunks.m_Size = 0;
  this->m_BreakableChunks.m_pElements = nullptr;
  this->m_bPropDataLoaded = false;
  this->m_pKVPropData = nullptr;
  p_m_keySection = &sPropdataInteractionSections[0].m_keySection;
  do
  {
    v4 = _KeyValuesSystem(a1: v2);
    *p_m_keySection = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v4 + 12))(
                        a1: v4,
                        a2: *(p_m_keySection - 3),
                        a3: 1);
    v6 = _KeyValuesSystem(a1: v5);
    p_m_keySection[1] = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v6 + 12))(
                          a1: v6,
                          a2: *(p_m_keySection - 2),
                          a3: 1);
    p_m_keySection += 5;
  }
  while ( (int)p_m_keySection < (int)aCbreakparser );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10158870
// Name: public: virtual void CPropData::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropData::LevelInitPreEntity(CPropData *this)
{
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(this: (CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *)&this->m_BreakableChunks);
  CPropData::ParsePropDataFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x103638E0
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10363A40
// Name: public: float KeyValues::GetFloat(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall KeyValues::GetFloat(KeyValues *this, char *keyName, float defaultValue)
{
  KeyValues *Key; // eax
  double result; // st7

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atof(nptr: Key->m_sValue);
      break;
    case 2:
      result = (double)Key->m_iValue;
      break;
    case 3:
      result = Key->m_flValue;
      break;
    case 5:
      result = _wtof(nptr: Key->m_wsValue);
      break;
    case 7:
      result = (double)*(unsigned __int64 *)Key->m_sValue;
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10389F80
// Name: public: class KeyValues __near * vgui::EditablePanel::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::EditablePanel::GetDialogVariables(vgui::EditablePanel *this)
{
  KeyValues *result; // eax
  KeyValues *v3; // eax

  result = this->m_pDialogVariables;
  if ( result == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      result = KeyValues::KeyValues(this: v3, setName: "DialogVariables");
      this->m_pDialogVariables = result;
    }
    else
    {
      this->m_pDialogVariables = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A0BA0
// Name: public: class KeyValues __near * vgui::ComboBox::GetActiveItemUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetActiveItemUserData(vgui::ComboBox *this)
{
  int v2; // eax

  v2 = this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x103A0BD0
// Name: public: class KeyValues __near * vgui::ComboBox::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetItemUserData(vgui::ComboBox *this, int itemID)
{
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x103A3E80
// Name: public: virtual class KeyValues __near * vgui::ListPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListPanel::GetItem(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->kv;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA890
// Name: public: virtual class KeyValues __near * vgui::ListViewPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListViewPanel::GetItem(vgui::ListViewPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ADB20
// Name: public: class KeyValues __near * vgui::Menu::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Menu::GetItemUserData(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx
  vgui::MenuItem *m_Element; // esi

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID)
    && (m_Element = m_pMemory[v3].m_Element) != nullptr
    && m_Element->IsEnabled(this: m_Element) )
  {
    return vgui::MenuItem::GetUserData(this: m_Element);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2080
// Name: public: class KeyValues __near * vgui::MenuItem::GetUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::MenuItem::GetUserData(vgui::MenuItem *this)
{
  int v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    return this->m_pUserData;
  v2 = this->m_pCascadeMenu->GetActiveItem(this: this->m_pCascadeMenu);
  return vgui::Menu::GetItemUserData(this: this->m_pCascadeMenu, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x103B8760
// Name: public: virtual class KeyValues __near * vgui::TreeView::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::TreeView::GetItemData(vgui::TreeView *this, int itemIndex)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemIndex >= 0
    && itemIndex < this->m_NodeList.m_Memory.m_nAllocationCount
    && itemIndex <= this->m_NodeList.m_LastAlloc.index
    && ((m_pMemory = this->m_NodeList.m_Memory.m_pMemory, v3 = itemIndex, m_pMemory[itemIndex].m_Previous != itemIndex)
     || m_pMemory[v3].m_Next == itemIndex) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8BC0
// Name: public: virtual class KeyValues __near * vgui::SectionedListPanel::GetItemData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::SectionedListPanel::GetItemData(vgui::SectionedListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_Items.m_Memory.m_nAllocationCount
    && itemID <= this->m_Items.m_LastAlloc.index
    && ((m_pMemory = this->m_Items.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CEAD0
// Name: public: class KeyValues __near * vgui::BuildGroup::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildGroup::GetDialogVariables(vgui::BuildGroup *this)
{
  vgui::EditablePanel *v1; // eax

  v1 = (vgui::EditablePanel *)__RTDynamicCast(
                                inptr: this->m_pParentPanel,
                                VfDelta: 0,
                                SrcType: &vgui::Panel `RTTI Type Descriptor',
                                TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
                                isReference: 0);
  if ( v1 != nullptr )
    return vgui::EditablePanel::GetDialogVariables(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D1F70
// Name: public: virtual class KeyValues __near * vgui::BuildModeDialog::StoreSettings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildModeDialog::StoreSettings(vgui::BuildModeDialog *this)
{
  KeyValues *v2; // esi
  const char *v3; // eax
  vgui::BuildModeDialog::PanelList *m_pPanelList; // eax
  int v5; // esi
  PanelItem_t *m_pMemory; // ecx
  PanelItem_t *v7; // eax
  char *m_szName; // ebx
  void *m_EditPanel; // ecx
  int v10; // eax
  char buf[512]; // [esp+Ch] [ebp-208h] BYREF
  int i; // [esp+20Ch] [ebp-8h]
  KeyValues *storedSettings; // [esp+210h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = this->m_pCurrentPanel->GetName(this: this->m_pCurrentPanel);
    storedSettings = KeyValues::KeyValues(this: v2, setName: v3);
  }
  else
  {
    storedSettings = nullptr;
  }
  m_pPanelList = this->m_pPanelList;
  i = 0;
  if ( m_pPanelList->m_PanelList.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      v7 = m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      m_szName = m_pMemory[v5].m_szName;
      if ( m_pMemory[v5].m_EditPanel != nullptr )
        m_EditPanel = v7[v5].m_EditPanel;
      else
        m_EditPanel = v7[v5].m_EditButton;
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)m_EditPanel + 856))(a1: m_EditPanel, a2: buf, a3: 512);
      if ( (unsigned int)(this->m_pPanelList->m_PanelList.m_Memory.m_pMemory[v5].m_iType - 4) > 1 )
      {
        KeyValues::SetString(this: storedSettings, keyName: m_szName, value: buf);
      }
      else
      {
        v10 = atoi(nptr: buf);
        KeyValues::SetInt(this: storedSettings, keyName: m_szName, value: v10);
      }
      m_pPanelList = this->m_pPanelList;
      ++v5;
      ++i;
    }
    while ( i < m_pPanelList->m_PanelList.m_Size );
  }
  return storedSettings;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101EE760
// Name: public: virtual void CPropData::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropData::LevelShutdownPostEntity(CPropData *this)
{
  KeyValues *m_pKVPropData; // ecx

  m_pKVPropData = this->m_pKVPropData;
  if ( m_pKVPropData != nullptr )
  {
    KeyValues::deleteThis(this: m_pKVPropData);
    this->m_pKVPropData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE780
// Name: char const __near * GetMassEquivalent(float)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetMassEquivalent(float flMass)
{
  int v1; // eax

  v1 = 0;
  while ( masstext[v1].flMass <= flMass )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return off_105B214C[0];
  }
  return (&off_105B209C)[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x101EE7C0
// Name: private: virtual struct datamap_t __near * CGameGibManager::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGameGibManager::GetDataDescMap(CGameGibManager *this)
{
  return &CGameGibManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101EE7D0
// Name: private: void CGameGibManager::InputSetMaxPiecesDX8(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGibManager::InputSetMaxPiecesDX8(CGameGibManager *this, inputdata_t *inputdata)
{
  this->m_iCurrentMaxPieces = this->m_iMaxPieces;
}

//------------------------------------------------------------------------------
// Address: 0x101EE880
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101EE8B0
// Name: public: float KeyValues::GetFloat(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall KeyValues::GetFloat(KeyValues *this, int keySymbol, float defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101EE8F0
// Name: AlignBoxes
// Source: json
//------------------------------------------------------------------------------
void __usercall AlignBoxes(const Vector *boxExtents1@<ecx>, const Vector *boxExtents2@<eax>, matrix3x4_t *pInOutMatrix)
{
  __int64 v3; // xmm0_8
  float z; // ecx
  float v5; // edx
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  float y; // xmm1_4
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  int v14; // edi
  int column[2]; // [esp+0h] [ebp-3Ch]
  AlignBoxes::__l2::<unnamed_type_rotations> rotations[2]; // [esp+8h] [ebp-34h]
  Vector out; // [esp+18h] [ebp-24h] BYREF
  Vector ext1; // [esp+24h] [ebp-18h] BYREF
  Vector ext2; // [esp+30h] [ebp-Ch] BYREF

  v3 = *(_QWORD *)&boxExtents1->x;
  z = boxExtents1->z;
  v5 = boxExtents2->z;
  *(_QWORD *)&ext1.x = v3;
  *(_QWORD *)&ext2.x = *(_QWORD *)&boxExtents2->x;
  v6 = 0;
  ext1.z = z;
  ext2.z = v5;
  if ( *(float *)&v3 <= *((float *)&v3 + 1) )
  {
    v7 = 1;
    if ( *((float *)&v3 + 1) > ext1.z )
      goto LABEL_6;
  }
  else if ( *(float *)&v3 > ext1.z )
  {
    v7 = 0;
    goto LABEL_6;
  }
  v7 = 2;
LABEL_6:
  if ( ext2.x <= ext2.y )
  {
    v8 = 1;
    if ( ext2.y > ext2.z )
      goto LABEL_11;
  }
  else if ( ext2.x > ext2.z )
  {
    v8 = 0;
    goto LABEL_11;
  }
  v8 = 2;
LABEL_11:
  if ( v7 != v8 )
  {
    v9 = *(&ext2.x + v7);
    rotations[0].axis0 = v7;
    *(&ext2.x + v8) = v9;
    rotations[0].axis1 = v8;
    v6 = 1;
  }
  *((_DWORD *)&ext1.x + v7) = 0;
  y = ext1.y;
  *((_DWORD *)&ext2.x + v7) = 0;
  if ( ext1.x <= y )
  {
    v11 = 1;
    if ( y > ext1.z )
      goto LABEL_18;
  }
  else if ( ext1.x > ext1.z )
  {
    v11 = 0;
    goto LABEL_18;
  }
  v11 = 2;
LABEL_18:
  if ( ext2.x <= ext2.y )
  {
    v12 = 1;
    if ( ext2.y > ext2.z )
      goto LABEL_23;
  }
  else if ( ext2.x > ext2.z )
  {
    v12 = 0;
    goto LABEL_23;
  }
  v12 = 2;
LABEL_23:
  if ( v11 != v12 )
  {
    rotations[v6].axis0 = v11;
    rotations[v6++].axis1 = v12;
  }
  while ( v6 > 0 )
  {
    v13 = column[2 * v6];
    v14 = column[2 * v6-- + 1];
    MatrixGetColumn(in: pInOutMatrix, column: v13, out: &ext1);
    MatrixGetColumn(in: pInOutMatrix, column: v14, &out);
    MatrixSetColumn(in: &out, column: v13, out: pInOutMatrix);
    ext2.x = -ext1.x;
    ext2.y = -ext1.y;
    ext2.z = -ext1.z;
    MatrixSetColumn(in: &ext2, column: v14, out: pInOutMatrix);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEA80
// Name: FixupModelName
// Source: json
//------------------------------------------------------------------------------
char *__usercall FixupModelName@<eax>(char *pOut@<esi>, unsigned int sizeOut@<edi>, const char *pModelNameIn@<eax>)
{
  int v3; // eax
  char tmp[1024]; // [esp+0h] [ebp-400h] BYREF

  V_strncpy(pDest: tmp, pSrc: pModelNameIn, maxLen: 1024);
  if ( V_strnicmp(s1: tmp, s2: "models/", n: 7) != 0 )
    V_snprintf(pDest: pOut, maxLen: sizeOut, pFormat: "models/%s", tmp);
  else
    V_strncpy(pDest: pOut, pSrc: tmp, maxLen: sizeOut);
  v3 = _V_strlen(str: pOut);
  if ( v3 < 4 || _V_stricmp(s1: &pOut[v3 - 4], s2: ".mdl") != 0 )
    V_strncat(pDest: pOut, pSrc: ".mdl", destBufferSize: sizeOut, max_chars_to_copy: -1);
  return pOut;
}

//------------------------------------------------------------------------------
// Address: 0x101EEB20
// Name: public: virtual void CBreakParser::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakParser::SetDefaults(CBreakParser *this, char *pData)
{
  pData[12] = 0;
  *(Vector *)pData = vec3_origin;
  *((_DWORD *)pData + 262) = 1065353216;
  *((_DWORD *)pData + 259) = 1101004800;
  *((_DWORD *)pData + 260) = 0;
  *((_DWORD *)pData + 261) = 0;
  *((float *)pData + 263) = this->m_defaultBurstScale;
  *((_DWORD *)pData + 264) = this->m_defaultCollisionGroup;
  pData[1060] = 0;
  pData[524] = 0;
  *(_WORD *)(pData + 1061) = 0;
  *((_DWORD *)pData + 266) = 0;
  this->m_wroteCollisionGroup = false;
}

//------------------------------------------------------------------------------
// Address: 0x101EEBC0
// Name: public: virtual void CBreakParser::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakParser::ParseKeyValue(CBreakParser *this, void *pData, const char *pKey, const char *pValue)
{
  if ( _V_stricmp(s1: pKey, s2: "model") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "ragdoll") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "motiondisabled") != 0 )
      {
        if ( _V_stricmp(s1: pKey, s2: "offset") != 0 )
        {
          if ( _V_stricmp(s1: pKey, s2: "health") != 0 )
          {
            if ( _V_stricmp(s1: pKey, s2: "fadetime") != 0 )
            {
              if ( _V_stricmp(s1: pKey, s2: "fademindist") != 0 )
              {
                if ( _V_stricmp(s1: pKey, s2: "fademaxdist") != 0 )
                {
                  if ( _V_stricmp(s1: pKey, s2: "debris") != 0 )
                  {
                    if ( _V_stricmp(s1: pKey, s2: "burst") != 0 )
                    {
                      if ( _V_stricmp(s1: pKey, s2: "placementbone") != 0 )
                      {
                        if ( _V_stricmp(s1: pKey, s2: "placementattachment") != 0 )
                        {
                          if ( _V_stricmp(s1: pKey, s2: "multiplayer_break") == 0 )
                          {
                            if ( FStrEq(sz1: pValue, sz2: "server") )
                            {
                              *((_DWORD *)pData + 266) = 1;
                            }
                            else if ( FStrEq(sz1: pValue, sz2: "client") )
                            {
                              *((_DWORD *)pData + 266) = 2;
                            }
                          }
                        }
                        else
                        {
                          V_strncpy(pDest: (char *)pData + 524, pSrc: pValue, maxLen: 512);
                          *((_BYTE *)pData + 1061) = 0;
                        }
                      }
                      else
                      {
                        V_strncpy(pDest: (char *)pData + 524, pSrc: pValue, maxLen: 512);
                        *((_BYTE *)pData + 1061) = 1;
                      }
                    }
                    else
                    {
                      *((float *)pData + 263) = atof(nptr: pValue);
                    }
                  }
                  else
                  {
                    *((_DWORD *)pData + 264) = atoi(nptr: pValue) <= 0 ? 4 : 1;
                    this->m_wroteCollisionGroup = true;
                  }
                }
                else
                {
                  *((float *)pData + 261) = atof(nptr: pValue);
                }
              }
              else
              {
                *((float *)pData + 260) = atof(nptr: pValue);
              }
            }
            else
            {
              *((float *)pData + 259) = atof(nptr: pValue);
              if ( !this->m_wroteCollisionGroup )
                *((_DWORD *)pData + 264) = 1;
            }
          }
          else
          {
            *((float *)pData + 262) = atof(nptr: pValue);
          }
        }
        else
        {
          UTIL_StringToVector(pVector: (float *)pData, pString: pValue);
        }
      }
      else
      {
        *((_BYTE *)pData + 1062) = 1;
      }
    }
    else
    {
      FixupModelName(pOut: (char *)pData + 12, sizeOut: 0x200u, pModelNameIn: pValue);
      *((_BYTE *)pData + 1060) = 1;
    }
  }
  else
  {
    FixupModelName(pOut: (char *)pData + 12, sizeOut: 0x200u, pModelNameIn: pValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEE80
// Name: int GetAutoMultiplayerPhysicsMode(class Vector,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAutoMultiplayerPhysicsMode(Vector size, float mass)
{
  int result; // eax

  if ( (float)((float)(sv_pushaway_clientside_size.m_pParent->m_Value.m_fValue
                     * sv_pushaway_clientside_size.m_pParent->m_Value.m_fValue)
             * sv_pushaway_clientside_size.m_pParent->m_Value.m_fValue) > (float)((float)(size.y * size.x) * size.z) )
    return 3;
  result = 2;
  if ( mass >= 8.0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EEED0
// Name: public: bool CGameGibManager::AllowedToSpawnGib(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameGibManager::AllowedToSpawnGib(CGameGibManager *this)
{
  int m_iCurrentMaxPieces; // eax
  bool result; // al

  result = true;
  if ( !this->m_bAllowNewGibs )
  {
    m_iCurrentMaxPieces = this->m_iCurrentMaxPieces;
    if ( m_iCurrentMaxPieces >= 0
      && (m_iCurrentMaxPieces == 0
       || this->m_iLastFrame == gpGlobals->framecount && this->m_LRU.m_ElementCount >= m_iCurrentMaxPieces) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EEF10
// Name: private: void CGameGibManager::InputSetMaxPieces(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGibManager::InputSetMaxPieces(CGameGibManager *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( inputdata->value.fieldType == FIELD_INTEGER )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    this->m_iCurrentMaxPieces = (int)pszValue;
    this->m_iMaxPieces = (int)pszValue;
  }
  else
  {
    this->m_iCurrentMaxPieces = 0;
    this->m_iMaxPieces = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEF50
// Name: public: bool CPhysicsProp::GetPropDataAngles(char const __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsProp::GetPropDataAngles(CPhysicsProp *this, const char *pKeyName, QAngle *vecAngles)
{
  IVModelInfo_vtbl *v3; // esi
  model_t *Model; // eax
  KeyValues *v5; // esi
  int v6; // eax
  KeyValues *Key; // eax
  const char *String; // eax

  v3 = modelinfo->__vftable;
  Model = CBaseEntity::GetModel(this);
  v5 = v3->GetModelKeyValues(this: modelinfo, a2: Model);
  if ( v5 == nullptr )
    return 0;
  if ( (_S4_50 & 1) == 0 )
  {
    _S4_50 |= 1u;
    v6 = _KeyValuesSystem();
    keyPhysgunInteractions = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v6 + 12))(
                               a1: v6,
                               a2: "physgun_interactions",
                               a3: 1);
  }
  Key = KeyValues::FindKey(this: v5, keySymbol: keyPhysgunInteractions);
  if ( Key == nullptr )
    return 0;
  String = KeyValues::GetString(this: Key, keyName: pKeyName, defaultValue: locale);
  if ( String == nullptr || *String == 0 )
    return 0;
  UTIL_StringToVector(pVector: &vecAngles->x, pString: String);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EEFF0
// Name: public: char const __near * CPropData::GetRandomChunkModel(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPropData::GetRandomChunkModel(
        CPropData *this,
        const char *pszBreakableSection,
        IUniformRandomStream *iMaxSize)
{
  const char *result; // eax
  int m_Size; // eax
  int v6; // esi
  int v7; // ebx
  int v8; // eax
  const char *pszValue; // ecx
  IUniformRandomStream *m_pMemory; // ecx
  unsigned int v11; // esi
  int v12; // eax
  int iCount; // [esp+4h] [ebp-4h]

  if ( !this->m_bPropDataLoaded )
    return nullptr;
  m_Size = this->m_BreakableChunks.m_Size;
  v6 = 0;
  iCount = m_Size;
  if ( m_Size > 0 )
  {
    v7 = 0;
    do
    {
      v8 = strlen(pszBreakableSection);
      pszValue = this->m_BreakableChunks.m_Memory.m_pMemory[v7].iszChunkType.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      if ( V_strncmp(s1: pszValue, s2: pszBreakableSection, count: v8) == 0 )
        break;
      ++v6;
      ++v7;
    }
    while ( v6 < iCount );
    m_Size = iCount;
  }
  if ( v6 == m_Size )
    return nullptr;
  m_pMemory = iMaxSize;
  v11 = 24 * v6;
  if ( iMaxSize == (IUniformRandomStream *)-1 )
  {
    m_pMemory = (IUniformRandomStream *)this->m_BreakableChunks.m_Memory.m_pMemory;
    v12 = (int)&m_pMemory[v11 / 4 + 4].__vftable[-1].RandomFloatExp + 3;
  }
  else
  {
    v12 = this->m_BreakableChunks.m_Memory.m_pMemory[v11 / 0x18].iszChunkModels.m_Size - 1;
    if ( (int)iMaxSize < v12 )
      v12 = (int)iMaxSize;
  }
  result = this->m_BreakableChunks.m_Memory.m_pMemory[v11 / 0x18].iszChunkModels.m_Memory.m_pMemory[_RandomInt(this: m_pMemory, a2: 0, a3: v12)].pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF310
// Name: public: CGameGibManager::CGameGibManager(void)
// Source: json
//------------------------------------------------------------------------------
CGameGibManager *__thiscall CGameGibManager::CGameGibManager(CGameGibManager *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CGameGibManager_vtbl *)&CGameGibManager::`vftable';
  this->m_LRU.m_Memory.m_pMemory = nullptr;
  this->m_LRU.m_Memory.m_nAllocationCount = 0;
  this->m_LRU.m_Memory.m_nGrowSize = 0;
  this->m_LRU.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_LRU.m_FirstFree = 0xFFFF;
  this->m_LRU.m_pElements = this->m_LRU.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LRU.m_Head = -1;
  this->m_LRU.m_NumAlloced = 0;
  this->m_iCurrentMaxPieces = -1;
  this->m_iMaxPieces = -1;
  g_pGibManager = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EF390
// Name: public: virtual CGameGibManager::~CGameGibManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGibManager::~CGameGibManager(CGameGibManager *this)
{
  this->__vftable = (CGameGibManager_vtbl *)&CGameGibManager::`vftable';
  if ( g_pGibManager == this )
    g_pGibManager = nullptr;
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_LRU);
  if ( this->m_LRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LRU.m_Memory.m_pMemory);
      this->m_LRU.m_Memory.m_pMemory = nullptr;
    }
    this->m_LRU.m_Memory.m_nAllocationCount = 0;
  }
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EF400
// Name: public: virtual void CGameGibManager::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGibManager::Activate(CGameGibManager *this)
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_LRU);
  if ( this->m_LRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LRU.m_Memory.m_pMemory);
      this->m_LRU.m_Memory.m_pMemory = nullptr;
    }
    this->m_LRU.m_Memory.m_nAllocationCount = 0;
  }
  this->m_LRU.m_FirstFree = -1;
  this->m_LRU.m_pElements = this->m_LRU.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LRU.m_NumAlloced = -65536;
  this->m_iCurrentMaxPieces = this->m_iMaxPieces;
  CBaseEntity::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EF480
// Name: public: int CPropData::ParsePropFromKV(class CBaseEntity __near *,class IBreakableWithPropData __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge CPropData::ParsePropFromKV@<eax>(
        CPropData *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CBaseEntity *pProp,
        float pBreakableInterface,
        KeyValues *pSection,
        KeyValues *pInteractionSection)
{
  IBreakableWithPropData *v7; // esi
  unsigned int result; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  KeyValues *v25; // ebx
  KeyValues *Key; // eax
  const char *v27; // eax
  KeyValues *v28; // eax
  float v29; // xmm0_4
  KeyValues *v30; // eax
  float v31; // xmm0_4
  KeyValues *v32; // eax
  const char *String; // eax
  const char *v34; // edi
  KeyValues *v35; // eax
  IBreakableWithPropData_vtbl *v36; // edi
  int v37; // edx
  int v38; // edi
  KeyValues *v39; // eax
  int Int; // eax
  KeyValues *v41; // eax
  const char *v42; // eax
  const char *v43; // edi
  int v44; // ebx
  KeyValues *v45; // eax
  IBreakableWithPropData *v46; // xmm0_4
  KeyValues *v47; // eax
  IBreakableWithPropData *v48; // xmm0_4
  KeyValues *v49; // eax
  IBreakableWithPropData *v50; // xmm0_4
  CBaseEntity_vtbl *v51; // edi
  int v52; // eax
  IBreakableWithPropData_vtbl *v53; // edi
  IBreakableWithPropData_vtbl *v54; // edi
  KeyValues *v55; // eax
  const char *v56; // eax
  const char *v57; // edi
  KeyValues *v58; // eax
  IBreakableWithPropData_vtbl *v59; // edi
  int v60; // edx
  int v61; // edi
  KeyValues *v62; // eax
  int v63; // eax
  int v64; // edi
  KeyValues *v65; // eax
  int v66; // eax
  Vector *v67; // eax
  float z; // ecx
  int v69; // eax
  __m128d v70; // xmm1
  __m128 y_low; // xmm0
  __m128d v72; // xmm2
  __m128d v73; // xmm3
  propdata_interactions_t v74; // ebx
  int *p_m_keyKeyName; // edi
  KeyValues *v76; // eax
  KeyValues *v77; // eax
  const char *v78; // eax
  KeyValues *v79; // eax
  KeyValues *i; // esi
  const char *Name; // edi
  const char *v82; // eax
  const char *v83; // eax
  KeyValues *v84; // eax
  float v86; // [esp+B4h] [ebp-1Ch]
  float Float; // [esp+B4h] [ebp-1Ch]
  float v88; // [esp+B4h] [ebp-1Ch]
  float v89; // [esp+B4h] [ebp-1Ch]
  Vector vecSize; // [esp+BCh] [ebp-14h]
  CPropData *v91; // [esp+C8h] [ebp-8h] BYREF
  int iBaseResult; // [esp+CCh] [ebp-4h]

  v7 = (IBreakableWithPropData *)LODWORD(pBreakableInterface);
  v91 = this;
  if ( pBreakableInterface == 0.0 )
    return 3;
  iBaseResult = 0;
  if ( (_S2_190 & 1) == 0 )
  {
    _S2_190 |= 1u;
    v9 = _KeyValuesSystem();
    keyBase = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 12))(a1: v9, a2: "base", a3: 1);
  }
  if ( (_S2_190 & 2) == 0 )
  {
    _S2_190 |= 2u;
    v10 = _KeyValuesSystem();
    keyBlockLOS = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v10 + 12))(a1: v10, a2: "blockLOS", a3: 1);
  }
  if ( (_S2_190 & 4) == 0 )
  {
    _S2_190 |= 4u;
    v11 = _KeyValuesSystem();
    keyAIWalkable = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 12))(
                      a1: v11,
                      a2: "AIWalkable",
                      a3: 1);
  }
  if ( (_S2_190 & 8) == 0 )
  {
    _S2_190 |= 8u;
    v12 = _KeyValuesSystem();
    keyDamageTable = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v12 + 12))(
                       a1: v12,
                       a2: "damage_table",
                       a3: 1);
  }
  if ( (_S2_190 & 0x10) == 0 )
  {
    _S2_190 |= 0x10u;
    v13 = _KeyValuesSystem();
    keyPhysicsMode = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 12))(
                       a1: v13,
                       a2: "physicsmode",
                       a3: 1);
  }
  if ( (_S2_190 & 0x20) == 0 )
  {
    _S2_190 |= 0x20u;
    v14 = _KeyValuesSystem();
    keyMultiplayerBreak = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v14 + 12))(
                            a1: v14,
                            a2: "multiplayer_break",
                            a3: 1);
  }
  if ( (_S2_190 & 0x40) == 0 )
  {
    _S2_190 |= 0x40u;
    v15 = _KeyValuesSystem();
    keyDmgBullets = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 12))(
                      a1: v15,
                      a2: "dmg.bullets",
                      a3: 1);
  }
  if ( (_S2_190 & 0x80u) == 0 )
  {
    _S2_190 |= 0x80u;
    v16 = _KeyValuesSystem();
    keyDmgClub = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v16 + 12))(a1: v16, a2: "dmg.club", a3: 1);
  }
  if ( (_S2_190 & 0x100) == 0 )
  {
    _S2_190 |= 0x100u;
    v17 = _KeyValuesSystem();
    keyDmgExplosive = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v17 + 12))(
                        a1: v17,
                        a2: "dmg.explosive",
                        a3: 1);
  }
  if ( (_S2_190 & 0x200) == 0 )
  {
    _S2_190 |= 0x200u;
    v18 = _KeyValuesSystem();
    keyHealth = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v18 + 12))(a1: v18, a2: "health", a3: 1);
  }
  if ( (_S2_190 & 0x400) == 0 )
  {
    _S2_190 |= 0x400u;
    v19 = _KeyValuesSystem();
    keyBreakableModel = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v19 + 12))(
                          a1: v19,
                          a2: "breakable_model",
                          a3: 1);
  }
  if ( (_S2_190 & 0x800) == 0 )
  {
    _S2_190 |= 0x800u;
    v20 = _KeyValuesSystem();
    keyBreakableSkin = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v20 + 12))(
                         a1: v20,
                         a2: "breakable_skin",
                         a3: 1);
  }
  if ( (_S2_190 & 0x1000) == 0 )
  {
    _S2_190 |= 0x1000u;
    v21 = _KeyValuesSystem();
    keyBreakableCount = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v21 + 12))(
                          a1: v21,
                          a2: "breakable_count",
                          a3: 1);
  }
  if ( (_S2_190 & 0x2000) == 0 )
  {
    _S2_190 |= 0x2000u;
    v22 = _KeyValuesSystem();
    keyExplosiveDamage = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v22 + 12))(
                           a1: v22,
                           a2: "explosive_damage",
                           a3: 1);
  }
  if ( (_S2_190 & 0x4000) == 0 )
  {
    _S2_190 |= 0x4000u;
    v23 = _KeyValuesSystem();
    keyExplosiveRadius = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v23 + 12))(
                           a1: v23,
                           a2: "explosive_radius",
                           a3: 1);
  }
  if ( (_S2_190 & 0x8000) == 0 )
  {
    _S2_190 |= 0x8000u;
    v24 = _KeyValuesSystem();
    keyAllowStatic = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v24 + 12))(
                       a1: v24,
                       a2: "allowstatic",
                       a3: 1);
  }
  v25 = pSection;
  Key = KeyValues::FindKey(this: pSection, keySymbol: keyBase);
  if ( Key == nullptr
    || (v27 = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: locale)) == nullptr
    || *v27 == 0
    || (result = CPropData::ParsePropFromBase(this: v91, pProp, pBreakableInterface: v7, pszPropData: v27),
        iBaseResult = result,
        result <= 1) )
  {
    v28 = KeyValues::FindKey(this: v25, keySymbol: keyBlockLOS);
    v29 = -1.0;
    if ( v28 != nullptr )
    {
      pBreakableInterface = KeyValues::GetFloat(this: v28, keyName: nullptr, defaultValue: -1.0);
      v29 = pBreakableInterface;
    }
    if ( (int)v29 != -1 )
      v7->SetPropDataBlocksLOS(this: v7, a2: (int)v29 != 0);
    v30 = KeyValues::FindKey(this: v25, keySymbol: keyAIWalkable);
    v31 = -1.0;
    if ( v30 != nullptr )
    {
      pBreakableInterface = KeyValues::GetFloat(this: v30, keyName: nullptr, defaultValue: -1.0);
      v31 = pBreakableInterface;
    }
    if ( (int)v31 != -1 )
      v7->SetPropDataIsAIWalkable(this: v7, a2: (int)v31 != 0);
    if ( *(_DWORD *)((int (__thiscall *)(IBreakableWithPropData *, float *, int, int))v7->GetPhysicsDamageTable)(
                      a1: v7,
                      a2: &pBreakableInterface,
                      a3: a2,
                      a4: a3) != 0 )
    {
      v34 = *(const char **)((int (__thiscall *)(IBreakableWithPropData *, float *))v7->GetPhysicsDamageTable)(
                              a1: v7,
                              a2: &pBreakableInterface);
      if ( v34 == nullptr )
        v34 = locale;
      v35 = KeyValues::FindKey(this: v25, keySymbol: keyDamageTable);
      if ( v35 != nullptr )
        String = KeyValues::GetString(this: v35, keyName: nullptr, defaultValue: v34);
      else
        String = v34;
    }
    else
    {
      v32 = KeyValues::FindKey(this: v25, keySymbol: keyDamageTable);
      if ( v32 == nullptr )
        goto LABEL_58;
      String = KeyValues::GetString(this: v32, keyName: nullptr, defaultValue: nullptr);
    }
    if ( String != nullptr && *String != 0 )
    {
      v36 = v7->__vftable;
      v37 = *(_DWORD *)AllocPooledString(pszValue: (char *)&v91, pszValuea: String).pszValue;
      ((void (__thiscall *)(IBreakableWithPropData *, int))v36->SetPhysicsDamageTable)(a1: v7, a2: v37);
      goto LABEL_59;
    }
LABEL_58:
    ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v7->SetPhysicsDamageTable)(a1: v7, a2: 0);
LABEL_59:
    v38 = v7->GetPhysicsMode(this: v7);
    v39 = KeyValues::FindKey(this: v25, keySymbol: keyPhysicsMode);
    if ( v39 != nullptr )
      Int = KeyValues::GetInt(this: v39, keyName: nullptr, defaultValue: v38);
    else
      Int = v38;
    v7->SetPhysicsMode(this: v7, a2: Int);
    v41 = KeyValues::FindKey(this: v25, keySymbol: keyMultiplayerBreak);
    if ( v41 != nullptr )
    {
      v42 = KeyValues::GetString(this: v41, keyName: nullptr, defaultValue: nullptr);
      v43 = v42;
      if ( v42 != nullptr )
      {
        v44 = 0;
        if ( v42 != "server" && _V_stricmp(s1: v42, s2: "server") != 0 )
        {
          if ( FStrEq(sz1: v43, sz2: "client") )
          {
            v44 = 2;
          }
          else if ( FStrEq(sz1: v43, sz2: "both") )
          {
            v44 = 3;
          }
        }
        else
        {
          v44 = 1;
        }
        v7->SetMultiplayerBreakMode(this: v7, a2: (mp_break_t)v44);
        v25 = pSection;
      }
    }
    pBreakableInterface = v7->GetDmgModBullet(this: v7);
    v45 = KeyValues::FindKey(this: v25, keySymbol: keyDmgBullets);
    v46 = (IBreakableWithPropData *)LODWORD(pBreakableInterface);
    if ( v45 != nullptr )
    {
      pBreakableInterface = KeyValues::GetFloat(this: v45, keyName: nullptr, defaultValue: pBreakableInterface);
      v46 = (IBreakableWithPropData *)LODWORD(pBreakableInterface);
    }
    ((void (__thiscall *)(IBreakableWithPropData *, IBreakableWithPropData *))v7->SetDmgModBullet)(a1: v7, a2: v46);
    pBreakableInterface = v7->GetDmgModClub(this: v7);
    v47 = KeyValues::FindKey(this: v25, keySymbol: keyDmgClub);
    v48 = (IBreakableWithPropData *)LODWORD(pBreakableInterface);
    if ( v47 != nullptr )
    {
      pBreakableInterface = KeyValues::GetFloat(this: v47, keyName: nullptr, defaultValue: pBreakableInterface);
      v48 = (IBreakableWithPropData *)LODWORD(pBreakableInterface);
    }
    ((void (__thiscall *)(IBreakableWithPropData *, IBreakableWithPropData *))v7->SetDmgModClub)(a1: v7, a2: v48);
    pBreakableInterface = v7->GetDmgModExplosive(this: v7);
    v49 = KeyValues::FindKey(this: v25, keySymbol: keyDmgExplosive);
    v50 = (IBreakableWithPropData *)LODWORD(pBreakableInterface);
    if ( v49 != nullptr )
    {
      pBreakableInterface = KeyValues::GetFloat(this: v49, keyName: nullptr, defaultValue: pBreakableInterface);
      v50 = (IBreakableWithPropData *)LODWORD(pBreakableInterface);
    }
    ((void (__thiscall *)(IBreakableWithPropData *, IBreakableWithPropData *))v7->SetDmgModExplosive)(a1: v7, a2: v50);
    if ( pProp == nullptr
      || pProp->m_iClassname.pszValue != "prop_physics_override"
      && CBaseEntity::ClassMatchesComplex(this: pProp, pszClassOrWildcard: "prop_physics_override") == 0
      && pProp->m_iClassname.pszValue != "prop_dynamic_override"
      && CBaseEntity::ClassMatchesComplex(this: pProp, pszClassOrWildcard: "prop_dynamic_override") == 0 )
    {
      v51 = pProp->__vftable;
      v52 = KeyValues::GetInt(this: v25, keySymbol: keyHealth, defaultValue: pProp->m_iHealth.m_Value);
      v51->SetHealth(this: pProp, a2: v52);
      v53 = v7->__vftable;
      v86 = v7->GetExplosiveDamage(this: v7);
      Float = KeyValues::GetFloat(this: v25, keySymbol: keyExplosiveDamage, defaultValue: v86);
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v53->SetExplosiveDamage)(a1: v7, a2: LODWORD(Float));
      v54 = v7->__vftable;
      v88 = v7->GetExplosiveRadius(this: v7);
      v89 = KeyValues::GetFloat(this: v25, keySymbol: keyExplosiveRadius, defaultValue: v88);
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v54->SetExplosiveRadius)(a1: v7, a2: LODWORD(v89));
      if ( pProp->m_iHealth.m_Value != 0 )
        CBaseEntity::RemoveSpawnFlags(this: pProp, nFlags: 2);
    }
    if ( *(_DWORD *)((int (__thiscall *)(IBreakableWithPropData *, float *))v7->GetBreakableModel)(
                      a1: v7,
                      a2: &pBreakableInterface) != 0 )
    {
      v57 = *(const char **)((int (__thiscall *)(IBreakableWithPropData *, float *))v7->GetBreakableModel)(
                              a1: v7,
                              a2: &pBreakableInterface);
      if ( v57 == nullptr )
        v57 = locale;
      v58 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableModel);
      if ( v58 != nullptr )
        v56 = KeyValues::GetString(this: v58, keyName: nullptr, defaultValue: v57);
      else
        v56 = v57;
    }
    else
    {
      v55 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableModel);
      if ( v55 == nullptr )
        goto LABEL_96;
      v56 = KeyValues::GetString(this: v55, keyName: nullptr, defaultValue: nullptr);
    }
    if ( v56 != nullptr && *v56 != 0 )
    {
      v59 = v7->__vftable;
      v60 = *(_DWORD *)AllocPooledString(pszValue: (char *)&v91, pszValuea: v56).pszValue;
      ((void (__thiscall *)(IBreakableWithPropData *, int))v59->SetBreakableModel)(a1: v7, a2: v60);
      goto LABEL_97;
    }
LABEL_96:
    ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v7->SetBreakableModel)(a1: v7, a2: 0);
LABEL_97:
    v61 = v7->GetBreakableSkin(this: v7);
    v62 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableSkin);
    if ( v62 != nullptr )
      v63 = KeyValues::GetInt(this: v62, keyName: nullptr, defaultValue: v61);
    else
      v63 = v61;
    v7->SetBreakableSkin(this: v7, a2: v63);
    v64 = v7->GetBreakableCount(this: v7);
    v65 = KeyValues::FindKey(this: v25, keySymbol: keyBreakableCount);
    if ( v65 != nullptr )
      v66 = KeyValues::GetInt(this: v65, keyName: nullptr, defaultValue: v64);
    else
      v66 = v64;
    v7->SetBreakableCount(this: v7, a2: v66);
    v67 = AllocTempVector();
    v67->x = pProp->m_Collision.m_vecMaxs.m_Value.x - pProp->m_Collision.m_vecMins.m_Value.x;
    v67->y = pProp->m_Collision.m_vecMaxs.m_Value.y - pProp->m_Collision.m_vecMins.m_Value.y;
    v67->z = pProp->m_Collision.m_vecMaxs.m_Value.z - pProp->m_Collision.m_vecMins.m_Value.z;
    z = v67->z;
    *(_QWORD *)&vecSize.x = *(_QWORD *)&v67->x;
    vecSize.z = z;
    if ( vecSize.y <= vecSize.x )
    {
      v69 = 1;
      if ( vecSize.z > vecSize.y )
        goto LABEL_108;
    }
    else if ( vecSize.z > vecSize.x )
    {
      v69 = 0;
      goto LABEL_108;
    }
    v69 = 2;
LABEL_108:
    v70.m128d_f64[0] = 4.503599627370496e15;
    *((_DWORD *)&vecSize.x + v69) = 1065353216;
    y_low = (__m128)LODWORD(vecSize.y);
    y_low.m128_f32[0] = (float)((float)(vecSize.y * vecSize.x) * vecSize.z) * 0.0009765625;
    v72 = _mm_cvtps_pd(y_low);
    v73 = _mm_and_pd((__m128d)0x8000000000000000uLL, v72);
    *(double *)y_low.m128_u64 = _mm_cmplt_sd(_mm_xor_pd(v72, v73), v70).m128d_f64[0];
    *(double *)y_low.m128_u64 = v72.m128d_f64[0]
                              + COERCE_DOUBLE(y_low.m128_u64[0] & 0x4330000000000000LL | *(_QWORD *)&v73.m128d_f64[0])
                              - COERCE_DOUBLE(y_low.m128_u64[0] & 0x4330000000000000LL | *(_QWORD *)&v73.m128d_f64[0]);
    v70.m128d_f64[1] = v72.m128d_f64[1];
    v70.m128d_f64[0] = *(double *)y_low.m128_u64 - v72.m128d_f64[0];
    v7->SetMaxBreakableSize(
      this: v7,
      a2: (int)(*(double *)y_low.m128_u64
          - COERCE_DOUBLE(*(_QWORD *)&_mm_cmpgt_sd(v70, v73).m128d_f64[0] & 0x3FF0000000000000LL)));
    v74 = PROPINTER_PHYSGUN_WORLD_STICK;
    p_m_keyKeyName = &sPropdataInteractionSections[0].m_keyKeyName;
    do
    {
      if ( *(p_m_keyKeyName - 4) != 0 )
      {
        v76 = KeyValues::FindKey(this: pInteractionSection, keySymbol: *(p_m_keyKeyName - 1));
        if ( v76 != nullptr )
        {
          v77 = KeyValues::FindKey(this: v76, keySymbol: *p_m_keyKeyName);
          if ( v77 != nullptr )
          {
            v78 = KeyValues::GetString(this: v77, keyName: nullptr, defaultValue: locale);
            if ( v78 != nullptr && *v78 != 0 && _V_stricmp(s1: v78, s2: (const char *)*(p_m_keyKeyName - 2)) == 0 )
              v7->SetInteraction(this: v7, a2: v74);
          }
        }
      }
      p_m_keyKeyName += 5;
      ++v74;
    }
    while ( (int)p_m_keyKeyName < (int)&CGameGibManager::m_DataMap.m_nPackedSize );
    v79 = KeyValues::FindKey(this: pInteractionSection, keyName: "prop_contexts", bCreate: false);
    if ( v79 != nullptr )
    {
      for ( i = KeyValues::GetFirstSubKey(this: v79); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        v82 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
        if ( Name != nullptr && v82 != nullptr )
        {
          v83 = UTIL_VarArgs(format: "%s:%s", Name, v82);
          CBaseEntity::AddContext(this: pProp, contextName: v83);
        }
      }
    }
    result = true;
    if ( iBaseResult != 1 )
    {
      v84 = KeyValues::FindKey(this: pSection, keySymbol: keyAllowStatic);
      if ( v84 == nullptr || KeyValues::GetInt(this: v84, keyName: nullptr, defaultValue: 0) == 0 )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EFE40
// Name: public: int CPropData::ParsePropFromBase(class CBaseEntity __near *,class IBreakableWithPropData __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPropData::ParsePropFromBase(
        CPropData *this,
        CBaseEntity *pProp,
        IBreakableWithPropData *pBreakableInterface,
        const char *pszPropData)
{
  CPropData *v4; // ebx
  IBreakableWithPropData *v6; // esi
  KeyValues *m_pKVPropData; // ecx
  KeyValues *Key; // edi
  CBaseEntity *v9; // esi
  const char *v10; // eax
  const char *pszValue; // esi
  IBreakableWithPropData_vtbl *v12; // ebx
  string_t v13; // eax

  v4 = this;
  if ( !this->m_bPropDataLoaded )
    return 2;
  v6 = pBreakableInterface;
  if ( pBreakableInterface == nullptr )
    return 3;
  m_pKVPropData = this->m_pKVPropData;
  if ( m_pKVPropData == nullptr )
    return 3;
  Key = KeyValues::FindKey(this: m_pKVPropData, keyName: pszPropData, bCreate: false);
  if ( Key != nullptr )
  {
    if ( *(_DWORD *)((int (__thiscall *)(IBreakableWithPropData *, IBreakableWithPropData **))v6->GetBasePropData)(
                      a1: v6,
                      a2: &pBreakableInterface) == 0 )
    {
      v12 = v6->__vftable;
      v13.pszValue = AllocPooledString(pszValue: (char *)&pszPropData, pszValuea: pszPropData).pszValue;
      ((void (__thiscall *)(IBreakableWithPropData *, _DWORD))v12->SetBasePropData)(a1: v6, a2: *(_DWORD *)v13.pszValue);
      v4 = this;
    }
    return CPropData::ParsePropFromKV(
             this: v4,
             a2: (int)v4,
             a3: (int)Key,
             pProp,
             pBreakableInterface: *(float *)&v6,
             pSection: Key,
             pInteractionSection: Key);
  }
  else
  {
    v9 = pProp;
    v10 = *(const char **)((int (__thiscall *)(CBaseEntity *, CBaseEntity **))pProp->GetModelName)(
                            a1: pProp,
                            a2: &pProp);
    if ( v10 == nullptr )
      v10 = locale;
    pszValue = v9->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(
      a1: "%s '%s' has a base specified as '%s', but there is no matching entry in propdata.txt.\n",
      pszValue,
      v10,
      pszPropData);
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EFF20
// Name: void BreakModelList(class CUtlVector<struct breakmodel_t,class CUtlMemory<struct breakmodel_t,int>> __near &,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BreakModelList(
        int a1@<ebx>,
        CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > *list,
        int modelindex,
        float defBurstScale,
        int defCollisionGroup)
{
  vcollide_t *v5; // eax
  int v6; // ebx
  int (__thiscall *v7)(int); // eax
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  breakmodel_t *m_pMemory; // ecx
  int v12; // eax
  CBreakParser breakParser; // [esp+0h] [ebp-10h] BYREF

  v5 = modelinfo->GetVCollide(this: modelinfo, a2: modelindex);
  if ( v5 != nullptr )
  {
    v6 = ((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, int))physcollision->VPhysicsKeyParserCreate)(
           a1: physcollision,
           a2: v5,
           a3: a1);
    while ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6) == 0 )
    {
      v7 = *(int (__thiscall **)(int))(*(_DWORD *)v6 + 4);
      breakParser.m_defaultCollisionGroup = defCollisionGroup;
      breakParser.__vftable = (CBreakParser_vtbl *)&CBreakParser::`vftable';
      breakParser.m_defaultBurstScale = defBurstScale;
      v8 = (const char *)v7(a1: v6);
      if ( _V_stricmp(s1: v8, s2: "break") != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6);
      }
      else
      {
        m_Size = list->m_Size;
        m_nAllocationCount = list->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<breakmodel_t,int>::Grow(this: &list->m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++list->m_Size;
        m_pMemory = list->m_Memory.m_pMemory;
        v12 = list->m_Size - m_Size - 1;
        list->m_pElements = list->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 1068 * v12);
        (*(void (__thiscall **)(int, breakmodel_t *, CBreakParser *))(*(_DWORD *)v6 + 28))(
          a1: v6,
          a2: &list->m_Memory.m_pMemory[m_Size],
          a3: &breakParser);
      }
    }
    ((void (__thiscall *)(IPhysicsCollision *))physcollision->VPhysicsKeyParserDestroy)(a1: physcollision);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F01B0
// Name: public: void CGameGibManager::AddGibToLRU(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGibManager::AddGibToLRU(CGameGibManager *this, CBaseAnimating *pEntity)
{
  unsigned __int16 m_Head; // bx
  CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *p_m_LRU; // edi
  int v4; // esi
  CBaseCombatWeapon *m_Element; // eax
  int m_iCurrentMaxPieces; // eax
  CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *v7; // edi
  unsigned __int16 v8; // bx
  int v9; // esi
  CBaseCombatWeapon *v10; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int m_Index; // ebx
  unsigned __int16 v13; // ax
  int v14; // edi
  UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short> *v15; // eax
  int next; // [esp+0h] [ebp-8h]
  CGameGibManager *v17; // [esp+4h] [ebp-4h]

  v17 = this;
  if ( pEntity != nullptr )
  {
    m_Head = this->m_LRU.m_Head;
    if ( m_Head != 0xFFFF )
    {
      p_m_LRU = (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_LRU;
      do
      {
        v4 = m_Head;
        m_Element = p_m_LRU->m_Memory.m_pMemory[v4].m_Element;
        next = p_m_LRU->m_Memory.m_pMemory[v4].m_Next;
        if ( m_Element == (CBaseCombatWeapon *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Element].m_SerialNumber != (unsigned int)m_Element >> 16
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Element].m_pEntity == nullptr )
        {
          CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
            this: p_m_LRU,
            elem: m_Head);
          p_m_LRU->m_Memory.m_pMemory[v4].m_Next = p_m_LRU->m_FirstFree;
          p_m_LRU->m_FirstFree = m_Head;
        }
        m_Head = next;
      }
      while ( next < 0xFFFF );
      this = v17;
    }
    m_iCurrentMaxPieces = this->m_iCurrentMaxPieces;
    if ( m_iCurrentMaxPieces > 0 )
    {
      if ( this->m_LRU.m_ElementCount >= m_iCurrentMaxPieces )
      {
        v7 = (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_LRU;
        while ( 1 )
        {
          v8 = this->m_LRU.m_Head;
          v9 = v8;
          v10 = v7->m_Memory.m_pMemory[v9].m_Element;
          if ( v10 == (CBaseCombatWeapon *)-1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != (unsigned int)v10 >> 16 )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
          }
          UTIL_Remove(oldObj: m_pEntity);
          CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
            this: v7,
            elem: v8);
          v7->m_Memory.m_pMemory[v9].m_Next = v7->m_FirstFree;
          v7->m_FirstFree = v8;
          if ( v17->m_LRU.m_ElementCount < v17->m_iCurrentMaxPieces )
            break;
          this = v17;
        }
      }
      m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
      v13 = CUtlLinkedList<CHandle<CBaseAnimating>,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CHandle<CBaseAnimating>,unsigned short>,unsigned short>>::AllocInternal(
              this: &v17->m_LRU,
              multilist: false);
      v14 = v13;
      if ( v13 != 0xFFFF )
      {
        CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
          this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&v17->m_LRU,
          before: 0xFFFFu,
          elem: v13);
        v15 = &v17->m_LRU.m_Memory.m_pMemory[v14];
        if ( v15 != nullptr )
          v15->m_Element.m_Index = m_Index;
      }
      v17->m_iLastFrame = gpGlobals->framecount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0340
// Name: void PropBreakableCreateAll(int,class IPhysicsObject __near *,struct breakablepropparams_t const __near &,class CBaseEntity __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall PropBreakableCreateAll(
        int a1@<ebx>,
        int a2@<esi>,
        int modelindex,
        IPhysicsObject *pPhysics,
        const breakablepropparams_t *params,
        CBaseEntity *pEntity,
        int iPrecomputedBreakableCount,
        bool bIgnoreGibLimit,
        bool defaultLocation)
{
  CBaseAnimating *v9; // edi
  int m_nValue; // eax
  int framecount; // ecx
  int v12; // eax
  CBaseEntity *v13; // eax
  CBaseAnimating *v14; // eax
  const struct model_t *v15; // eax
  const studiohdr_t *v16; // eax
  int v17; // eax
  const breakablepropparams_t *v18; // ebx
  int v19; // eax
  int v20; // edi
  char *modelName; // esi
  int v22; // ebx
  mp_break_t mpBreakMode; // eax
  const struct model_t *v24; // eax
  const studiohdr_t *v25; // eax
  Vector *angles; // eax
  CBaseAnimating *v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // eax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  Vector *velocity; // eoff
  int v35; // esi
  CBaseEntity *v36; // ebx
  CBreakableProp *v37; // esi
  CGameGibManager *v38; // ebx
  CBaseAnimating *v39; // eax
  float *v40; // eax
  float v41; // xmm1_4
  float v42; // xmm2_4
  float burstScale; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // ecx
  unsigned __int8 g; // dl
  unsigned __int8 b; // al
  int *v47; // edi
  int (__thiscall *v48)(int *); // edx
  const char *v49; // esi
  IUniformRandomStream *v50; // eax
  const char *RandomChunkModel; // eax
  IUniformRandomStream *v52; // ecx
  Vector *v53; // eax
  float v54; // ecx
  int v55; // eax
  float *p_x; // eax
  float defBurstScale; // xmm0_4
  QAngle *AbsAngles; // eax
  int v59; // edx
  int v60; // esi
  CBreakableProp *v61; // esi
  CGameGibManager *v62; // ebx
  CBaseAnimating *v63; // eax
  Vector *v64; // eax
  float v65; // ecx
  IPhysicsObject *v66; // ecx
  unsigned __int8 v67; // dl
  unsigned __int8 v68; // al
  int (__thiscall *v69)(int *); // edx
  int v70; // esi
  IMDLCache *v71; // [esp+0h] [ebp-65Ch]
  char *placementName; // [esp+0h] [ebp-65Ch]
  IMDLCache *v73; // [esp+14h] [ebp-648h]
  breakmodel_t breakModel; // [esp+30h] [ebp-62Ch] BYREF
  CStudioHdr studioHdr; // [esp+45Ch] [ebp-200h] BYREF
  matrix3x4_t burstCenterTransform; // [esp+4C0h] [ebp-19Ch] BYREF
  matrix3x4_t matrix; // [esp+4F0h] [ebp-16Ch] BYREF
  CStudioHdr parentStudioHdr; // [esp+520h] [ebp-13Ch] BYREF
  matrix3x4_t localToWorld; // [esp+584h] [ebp-D8h] BYREF
  Vector pos; // [esp+5B4h] [ebp-A8h] BYREF
  Vector vecBreakableObbSize; // [esp+5C0h] [ebp-9Ch] BYREF
  Vector vecVelocity; // [esp+5CCh] [ebp-90h] BYREF
  int nPropCount; // [esp+5D8h] [ebp-84h]
  CBaseAnimating *pOwnerAnim; // [esp+5DCh] [ebp-80h]
  Vector parentOrigin; // [esp+5E0h] [ebp-7Ch] BYREF
  Vector vecMaxs; // [esp+5ECh] [ebp-70h] BYREF
  CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > list; // [esp+5F8h] [ebp-64h] BYREF
  Vector vecMins; // [esp+60Ch] [ebp-50h] BYREF
  Vector burstCenter; // [esp+618h] [ebp-44h] BYREF
  int nSkin; // [esp+624h] [ebp-38h] BYREF
  Vector position; // [esp+628h] [ebp-34h] BYREF
  Vector vecObbSize; // [esp+634h] [ebp-28h] BYREF
  CBaseEntity *pOwnerEntity; // [esp+640h] [ebp-1Ch]
  QAngle vecAngles; // [esp+644h] [ebp-18h] BYREF
  color24 renderColor; // [esp+650h] [ebp-Ch]
  int i; // [esp+658h] [ebp-4h]

  v9 = nullptr;
  if ( props_break_max_pieces_perframe.m_pParent != nullptr )
  {
    m_nValue = props_break_max_pieces_perframe.m_pParent->m_Value.m_nValue;
    nPropCount = m_nValue;
    if ( m_nValue == -1 )
      goto LABEL_6;
  }
  else
  {
    m_nValue = 0;
    nPropCount = 0;
  }
  framecount = gpGlobals->framecount;
  if ( nFrameNumber != framecount )
  {
    nPropBreakablesPerFrameCount = 0;
    nFrameNumber = framecount;
  }
  if ( nPropBreakablesPerFrameCount < m_nValue )
  {
LABEL_6:
    if ( !bIgnoreGibLimit )
    {
      if ( props_break_max_pieces.m_pParent == nullptr )
      {
        v12 = 0;
        goto LABEL_9;
      }
      v12 = props_break_max_pieces.m_pParent->m_Value.m_nValue;
      if ( v12 != -1 )
      {
LABEL_9:
        if ( iPrecomputedBreakableCount == -1 || v12 < iPrecomputedBreakableCount )
          iPrecomputedBreakableCount = v12;
      }
    }
    if ( ((int (__thiscall *)(IVModelInfo *, int, int))modelinfo->GetVCollide)(a1: modelinfo, a2: modelindex, a3: a1) == 0 )
      return;
    nSkin = 0;
    v13 = pEntity;
    pOwnerEntity = pEntity;
    pOwnerAnim = nullptr;
    if ( pPhysics != nullptr )
    {
      v13 = (CBaseEntity *)((int (__thiscall *)(IPhysicsObject *, int))pPhysics->GetGameData)(a1: pPhysics, a2);
      pOwnerEntity = v13;
    }
    if ( v13 != nullptr )
    {
      v14 = v13->GetBaseAnimating(this: v13);
      v9 = v14;
      pOwnerAnim = v14;
      if ( v14 != nullptr )
        nSkin = v14->m_nSkin.m_Value;
    }
    CStudioHdr::CStudioHdr(this: &parentStudioHdr);
    v15 = modelinfo->GetModel(this: modelinfo, a2: modelindex);
    if ( v15 != nullptr )
    {
      v73 = (IMDLCache *)v15;
      v16 = (const studiohdr_t *)((int (__thiscall *)(IVModelInfo *))modelinfo->GetStudiomodel)(a1: modelinfo);
      CStudioHdr::Init(this: &parentStudioHdr, pStudioHdr: v16, mdlcache: v73);
    }
    parentOrigin = vec3_origin;
    v17 = Studio_FindAttachment(pStudioHdr: &parentStudioHdr, pAttachmentName: "placementOrigin") + 1;
    if ( v17 <= 0 )
    {
      AngleMatrix(angles: &vec3_angle, matrix: &localToWorld);
    }
    else
    {
      GetAttachmentLocalSpace(pstudiohdr: &parentStudioHdr, attachIndex: v17 - 1, pLocalToWorld: &localToWorld);
      MatrixGetColumn(in: &localToWorld, column: 3, out: &parentOrigin);
    }
    v18 = params;
    AngleMatrix(angles: params->angles, position: params->origin, &matrix);
    burstCenter = *params->origin;
    v19 = Studio_FindAttachment(pStudioHdr: &parentStudioHdr, pAttachmentName: "burstCenter") + 1;
    if ( v19 > 0 )
    {
      if ( v9 != nullptr )
      {
        v9->GetAttachment(this: v9, a2: v19, a3: &burstCenterTransform);
        MatrixGetColumn(in: &burstCenterTransform, column: 3, out: &burstCenter);
      }
      else
      {
        GetAttachmentLocalSpace(pstudiohdr: &parentStudioHdr, attachIndex: v19 - 1, pLocalToWorld: &localToWorld);
        MatrixGetColumn(in: &localToWorld, column: 3, out: &burstCenter);
        vecMins.x = burstCenter.x - parentOrigin.x;
        vecMins.y = burstCenter.y - parentOrigin.y;
        vecMins.z = burstCenter.z - parentOrigin.z;
        VectorTransform(in1: &vecMins.x, in2: &matrix, out: &burstCenter.x);
      }
    }
    memset(&list, 0, sizeof(list));
    CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int>>::EnsureCapacity(this: &list, num: 20);
    BreakModelList(
      a1: (int)params,
      &list,
      modelindex,
      defBurstScale: params->defBurstScale,
      defCollisionGroup: params->defCollisionGroup);
    if ( list.m_Size != 0 )
    {
      if ( PropBreakableCapEdictsOnCreateAll(&list, pPhysics, params, pEntity, iPrecomputedBreakableCount) )
      {
        i = 0;
        if ( list.m_Size > 0 )
        {
          v20 = 0;
          while ( 1 )
          {
            modelName = list.m_Memory.m_pMemory[v20].modelName;
            v22 = modelinfo->GetModelIndex(this: modelinfo, a2: modelName);
            if ( v22 > 0 )
            {
              if ( gpGlobals->maxClients <= 1
                || breakable_multiplayer.m_pParent == nullptr
                || breakable_multiplayer.m_pParent->m_Value.m_nValue == 0
                || (mpBreakMode = list.m_Memory.m_pMemory[v20].mpBreakMode) != MULTIPLAYER_BREAK_CLIENTSIDE
                && (defaultLocation || mpBreakMode != MULTIPLAYER_BREAK_DEFAULT) )
              {
                if ( nPropCount != -1 && nPropBreakablesPerFrameCount > nPropCount
                  || iPrecomputedBreakableCount != -1 && i >= iPrecomputedBreakableCount )
                {
                  goto LABEL_109;
                }
                CStudioHdr::CStudioHdr(this: &studioHdr);
                v24 = modelinfo->GetModel(this: modelinfo, a2: v22);
                if ( v24 != nullptr )
                {
                  v71 = (IMDLCache *)v24;
                  v25 = (const studiohdr_t *)((int (__thiscall *)(IVModelInfo *))modelinfo->GetStudiomodel)(a1: modelinfo);
                  CStudioHdr::Init(this: &studioHdr, pStudioHdr: v25, mdlcache: v71);
                }
                angles = (Vector *)params->angles;
                v27 = pOwnerAnim;
                ++nPropBreakablesPerFrameCount;
                position = vec3_origin;
                vecMaxs = *angles;
                if ( pOwnerAnim != nullptr && list.m_Memory.m_pMemory[v20].placementName[0] != 0 )
                {
                  placementName = list.m_Memory.m_pMemory[v20].placementName;
                  if ( list.m_Memory.m_pMemory[v20].placementIsBone )
                  {
                    v28 = CBaseAnimating::LookupBone(this: pOwnerAnim, szName: placementName);
                    if ( v28 >= 0 )
                    {
                      CBaseAnimating::GetBonePosition(
                        this: v27,
                        iBone: v28,
                        origin: &position,
                        angles: (QAngle *)&vecMaxs);
                      AngleMatrix(angles: (const QAngle *)&vecMaxs, &position, &matrix);
                    }
                  }
                  else
                  {
                    v29 = Studio_FindAttachment(pStudioHdr: &studioHdr, pAttachmentName: placementName) + 1;
                    if ( v29 > 0 )
                    {
                      v27->GetAttachment(this: v27, a2: v29, a3: &matrix);
                      MatrixAngles(a1: (int)v27, src: (const VMatrix *)&matrix, vAngles: (QAngle *)&vecMaxs);
                    }
                  }
                }
                else
                {
                  v30 = Studio_FindAttachment(pStudioHdr: &studioHdr, pAttachmentName: "placementOrigin") + 1;
                  vecAngles = (QAngle)parentOrigin;
                  if ( v30 <= 0 )
                  {
                    z = vecAngles.z;
                    y = vecAngles.y;
                    x = vecAngles.x;
                  }
                  else
                  {
                    GetAttachmentLocalSpace(pstudiohdr: &studioHdr, attachIndex: v30 - 1, pLocalToWorld: &localToWorld);
                    MatrixGetColumn(in: &localToWorld, column: 3, out: (Vector *)&vecAngles);
                    x = vecAngles.x - parentOrigin.x;
                    y = vecAngles.y - parentOrigin.y;
                    z = vecAngles.z - parentOrigin.z;
                    vecAngles.x = vecAngles.x - parentOrigin.x;
                    vecAngles.y = vecAngles.y - parentOrigin.y;
                    vecAngles.z = vecAngles.z - parentOrigin.z;
                  }
                  vecMins.x = list.m_Memory.m_pMemory[v20].offset.x - x;
                  vecMins.y = list.m_Memory.m_pMemory[v20].offset.y - y;
                  vecMins.z = list.m_Memory.m_pMemory[v20].offset.z - z;
                  VectorTransform(in1: &vecMins.x, in2: &matrix, out: &position.x);
                }
                velocity = params->velocity;
                vecBreakableObbSize = *velocity;
                if ( pPhysics != nullptr )
                  pPhysics->GetVelocityAtPoint(this: pPhysics, a2: &position, a3: &vecBreakableObbSize);
                v35 = nSkin;
                if ( nSkin > studioHdr.m_pStudioHdr->numskinfamilies )
                  v35 = 0;
                if ( g_pGibManager == nullptr || CGameGibManager::AllowedToSpawnGib(this: g_pGibManager) )
                {
                  v36 = pOwnerEntity;
                  v37 = BreakModelCreateSingle(
                          pOwner: pOwnerEntity,
                          pModel: &list.m_Memory.m_pMemory[v20],
                          &position,
                          angles: (const QAngle *)&vecMaxs,
                          velocity: &vecBreakableObbSize,
                          angVelocity: params->angularVelocity,
                          nSkin: v35,
                          params);
                  if ( v37 != nullptr )
                  {
                    if ( g_pGibManager != nullptr )
                    {
                      v38 = g_pGibManager;
                      v39 = v37->GetBaseAnimating(this: v37);
                      CGameGibManager::AddGibToLRU(this: v38, pEntity: v39);
                      v36 = pOwnerEntity;
                    }
                    if ( v36 != nullptr && (v36->m_fEffects.m_Value & 0x10) != 0 )
                      CBaseEntity::AddEffects(this: v37, nEffects: 16);
                    if ( list.m_Memory.m_pMemory[v20].burstScale != 0.0 )
                    {
                      vecObbSize.x = position.x - burstCenter.x;
                      vecObbSize.y = position.y - burstCenter.y;
                      vecObbSize.z = position.z - burstCenter.z;
                      if ( Vector::operator==(this: &vecObbSize, src: &vec3_origin) )
                      {
                        v40 = (float *)v37->WorldSpaceCenter(this: v37);
                        v41 = v40[1] - burstCenter.y;
                        v42 = v40[2] - burstCenter.z;
                        vecObbSize.x = *v40 - burstCenter.x;
                        vecObbSize.y = v41;
                        vecObbSize.z = v42;
                      }
                      VectorNormalize(vec: &vecObbSize);
                      burstScale = list.m_Memory.m_pMemory[v20].burstScale;
                      vecVelocity.x = vecObbSize.x * burstScale;
                      vecVelocity.y = vecObbSize.y * burstScale;
                      vecVelocity.z = vecObbSize.z * burstScale;
                      CBaseEntity::ApplyAbsVelocityImpulse(this: v37, vecImpulse: &vecVelocity);
                    }
                    if ( list.m_Memory.m_pMemory[v20].isMotionDisabled )
                    {
                      m_pPhysicsObject = v37->m_pPhysicsObject;
                      if ( m_pPhysicsObject != nullptr )
                        m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: false);
                    }
                    if ( pEntity != nullptr )
                    {
                      g = pEntity->m_clrRender.m_Value.g;
                      b = pEntity->m_clrRender.m_Value.b;
                      renderColor.r = pEntity->m_clrRender.m_Value.r;
                      renderColor.g = g;
                      CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
                        this: &v37->m_clrRender,
                        rVal: renderColor.r,
                        gVal: g,
                        bVal: b);
                    }
                  }
                }
                CStudioHdr::Term(this: &studioHdr);
                CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
                CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
                CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
              }
            }
            else
            {
              _Warning(a1: "Unable to create non-precached breakmodel %s\n", modelName);
            }
            ++v20;
            if ( ++i >= list.m_Size )
              goto LABEL_109;
          }
        }
      }
      else
      {
        DevMsg(a1: "Failed to create PropBreakable: would exceed MAX_EDICTS\n");
      }
      goto LABEL_109;
    }
    if ( pEntity == nullptr
      || (v47 = (int *)__RTDynamicCast(
                         inptr: pEntity,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &IBreakableWithPropData `RTTI Type Descriptor',
                         isReference: 0)) == nullptr
      || *(_DWORD *)(*(int (__thiscall **)(int *, int *))(*v47 + 56))(a1: v47, a2: &nSkin) == 0
      || (*(int (__thiscall **)(int *))(*v47 + 72))(a1: v47) == 0
      || (v48 = *(int (__thiscall **)(int *))(*v47 + 72), i = 0, v48(a1: v47) <= 0) )
    {
LABEL_109:
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
      CStudioHdr::Term(this: &parentStudioHdr);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&parentStudioHdr.m_boneParent);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&parentStudioHdr.m_boneFlags);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&parentStudioHdr.m_pStudioHdrCache);
      return;
    }
    while ( 1 )
    {
      if ( iPrecomputedBreakableCount != -1 && i >= iPrecomputedBreakableCount )
        goto LABEL_109;
      v49 = *(const char **)(*(int (__thiscall **)(int *, int *))(*v47 + 56))(a1: v47, a2: &nSkin);
      if ( v49 == nullptr )
        v49 = locale;
      v50 = (IUniformRandomStream *)(*(int (__thiscall **)(int *))(*v47 + 80))(a1: v47);
      RandomChunkModel = CPropData::GetRandomChunkModel(
                           this: &g_PropDataSystem,
                           pszBreakableSection: v49,
                           iMaxSize: v50);
      V_strncpy(pDest: breakModel.modelName, pSrc: RandomChunkModel, maxLen: 512);
      breakModel.health = 1.0;
      breakModel.fadeTime = _RandomFloat(this: v52, a2: 5.0, a3: 10.0);
      breakModel.fadeMinDist = 0.0;
      breakModel.fadeMaxDist = 0.0;
      breakModel.burstScale = v18->defBurstScale;
      breakModel.collisionGroup = 1;
      breakModel.isRagdoll = false;
      breakModel.placementName[0] = 0;
      *(_WORD *)&breakModel.placementIsBone = 0;
      v53 = AllocTempVector();
      v53->x = pEntity->m_Collision.m_vecMaxs.m_Value.x - pEntity->m_Collision.m_vecMins.m_Value.x;
      v53->y = pEntity->m_Collision.m_vecMaxs.m_Value.y - pEntity->m_Collision.m_vecMins.m_Value.y;
      v53->z = pEntity->m_Collision.m_vecMaxs.m_Value.z - pEntity->m_Collision.m_vecMins.m_Value.z;
      v54 = v53->z;
      *(_QWORD *)&vecObbSize.x = *(_QWORD *)&v53->x;
      vecObbSize.z = v54;
      if ( vecObbSize.y <= vecObbSize.x )
      {
        v55 = 1;
        if ( vecObbSize.z > vecObbSize.y )
          goto LABEL_97;
      }
      else if ( vecObbSize.z > vecObbSize.x )
      {
        v55 = 0;
        goto LABEL_97;
      }
      v55 = 2;
LABEL_97:
      memset((void *)&vecMins, 0, sizeof(vecMins));
      vecMaxs.x = 1.0;
      vecMaxs.y = 1.0;
      vecMaxs.z = 1.0;
      *((_DWORD *)&vecMins.x + v55) = 1056964608;
      *((_DWORD *)&vecMaxs.x + v55) = 1056964608;
      CCollisionProperty::RandomPointInBounds(
        this: &pEntity->m_Collision,
        vecNormalizedMins: &vecMins,
        vecNormalizedMaxs: &vecMaxs,
        pPoint: &breakModel.offset);
      p_x = &v18->origin->x;
      position.x = breakModel.offset.x - v18->origin->x;
      position.y = breakModel.offset.y - p_x[1];
      position.z = breakModel.offset.z - p_x[2];
      VectorNormalize(vec: &position);
      defBurstScale = v18->defBurstScale;
      vecVelocity.x = position.x * defBurstScale;
      vecVelocity.y = position.y * defBurstScale;
      vecVelocity.z = position.z * defBurstScale;
      AbsAngles = CBaseEntity::GetAbsAngles(this: pEntity);
      v59 = *v47;
      vecAngles = *AbsAngles;
      v60 = (*(int (__thiscall **)(int *))(v59 + 64))(a1: v47);
      if ( g_pGibManager == nullptr || CGameGibManager::AllowedToSpawnGib(this: g_pGibManager) )
      {
        v61 = BreakModelCreateSingle(
                pOwner: pOwnerEntity,
                pModel: &breakModel,
                position: &breakModel.offset,
                angles: &vecAngles,
                velocity: &vecVelocity,
                angVelocity: &vec3_origin,
                nSkin: v60,
                params: v18);
        if ( v61 != nullptr )
        {
          if ( g_pGibManager != nullptr )
          {
            v62 = g_pGibManager;
            v63 = v61->GetBaseAnimating(this: v61);
            CGameGibManager::AddGibToLRU(this: v62, pEntity: v63);
            v18 = params;
          }
          v64 = AllocTempVector();
          v64->x = v61->m_Collision.m_vecMaxs.m_Value.x - v61->m_Collision.m_vecMins.m_Value.x;
          v64->y = v61->m_Collision.m_vecMaxs.m_Value.y - v61->m_Collision.m_vecMins.m_Value.y;
          v64->z = v61->m_Collision.m_vecMaxs.m_Value.z - v61->m_Collision.m_vecMins.m_Value.z;
          v65 = v64->z;
          *(_QWORD *)&vecBreakableObbSize.x = *(_QWORD *)&v64->x;
          vecBreakableObbSize.z = v65;
          AngleMatrix(angles: &vecAngles, matrix: &burstCenterTransform);
          AlignBoxes(boxExtents1: &vecObbSize, boxExtents2: &vecBreakableObbSize, pInOutMatrix: &burstCenterTransform);
          MatrixAngles(a1: (int)v61, src: (const VMatrix *)&burstCenterTransform, vAngles: &vecAngles);
          v66 = v61->m_pPhysicsObject;
          if ( v66 != nullptr )
          {
            v66->GetPosition(this: v66, a2: &pos, a3: nullptr);
            v61->m_pPhysicsObject->SetPosition(this: v61->m_pPhysicsObject, a2: &pos, a3: &vecAngles, a4: true);
          }
          CBaseEntity::SetAbsAngles(this: v61, absAngles: &vecAngles);
          if ( (pOwnerEntity->m_fEffects.m_Value & 0x10) != 0 )
            CBaseEntity::AddEffects(this: v61, nEffects: 16);
          v67 = pEntity->m_clrRender.m_Value.g;
          v68 = pEntity->m_clrRender.m_Value.b;
          renderColor.r = pEntity->m_clrRender.m_Value.r;
          renderColor.g = v67;
          CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
            this: &v61->m_clrRender,
            rVal: renderColor.r,
            gVal: v67,
            bVal: v68);
        }
        else
        {
          DevWarning(a1: "PropBreakableCreateAll: Could not create model %s\n", breakModel.modelName);
        }
      }
      v69 = *(int (__thiscall **)(int *))(*v47 + 72);
      v70 = ++i;
      if ( v70 >= v69(a1: v47) )
        goto LABEL_109;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0FB0
// Name: void PropBreakableCreateAll(int,class IPhysicsObject __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,float,int,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall PropBreakableCreateAll(
        int a1@<ebx>,
        int a2@<esi>,
        int modelindex,
        IPhysicsObject *pPhysics,
        const Vector *origin,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angularVelocity,
        float impactEnergyScale,
        unsigned int defBurstScale,
        unsigned int defCollisionGroup,
        CBaseEntity *pEntity,
        bool defaultLocation)
{
  breakablepropparams_t params; // [esp+0h] [ebp-1Ch] BYREF

  params.velocity = velocity;
  params.origin = origin;
  params.angles = angles;
  params.angularVelocity = angularVelocity;
  params.impactEnergyScale = impactEnergyScale;
  *(_QWORD *)&params.defBurstScale = __PAIR64__(defCollisionGroup, defBurstScale);
  PropBreakableCreateAll(
    a1,
    a2,
    modelindex,
    pPhysics,
    &params,
    pEntity,
    iPrecomputedBreakableCount: -1,
    bIgnoreGibLimit: false,
    defaultLocation);
}

//------------------------------------------------------------------------------
// Address: 0x101F1010
// Name: public: void CPropData::ParsePropDataFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropData::ParsePropDataFile(CPropData *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // ecx
  bool v5; // al
  KeyValues *m_pKVPropData; // ecx
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // edi
  CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int> > *p_m_BreakableChunks; // esi
  CPropData::propdata_breakablechunk_t *v10; // ebx
  const char *Name; // eax
  KeyValues *NextKey; // ebx
  CPropData::propdata_breakablechunk_t *v13; // esi
  const char *v14; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  string_t *m_pMemory; // ecx
  int v18; // eax
  bool (__cdecl *v19)(const char *); // edi
  const char *v20; // eax
  char pszValue[4]; // [esp+4h] [ebp-14h] BYREF
  CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int> > *v22; // [esp+8h] [ebp-10h]
  CPropData::propdata_breakablechunk_t *pBreakableChunk; // [esp+Ch] [ebp-Ch]
  string_t pooledName; // [esp+10h] [ebp-8h] BYREF
  KeyValues *pChunkSection; // [esp+14h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "PropDatafile");
  else
    v3 = nullptr;
  this->m_pKVPropData = v3;
  if ( filesystem != nullptr )
    v4 = &filesystem->IBaseFileSystem;
  else
    v4 = nullptr;
  v5 = KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "scripts/propdata.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr);
  m_pKVPropData = this->m_pKVPropData;
  if ( v5 )
  {
    this->m_bPropDataLoaded = true;
    Key = KeyValues::FindKey(this: m_pKVPropData, keyName: "BreakableModels", bCreate: false);
    if ( Key != nullptr )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
      pChunkSection = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        p_m_BreakableChunks = &this->m_BreakableChunks;
        v22 = p_m_BreakableChunks;
        while ( 1 )
        {
          v10 = &p_m_BreakableChunks->m_Memory.m_pMemory[CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int>>::InsertBefore(
                                                           this: p_m_BreakableChunks,
                                                           elem: p_m_BreakableChunks->m_Size)];
          pBreakableChunk = v10;
          Name = KeyValues::GetName(this: FirstSubKey);
          v10->iszChunkType.pszValue = *(const char **)AllocPooledString(pszValue, pszValuea: Name).pszValue;
          NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
          if ( NextKey != nullptr )
          {
            v13 = pBreakableChunk;
            do
            {
              v14 = KeyValues::GetName(this: NextKey);
              AllocPooledString(pszValue: (char *)&pooledName, pszValuea: v14);
              m_Size = v13->iszChunkModels.m_Size;
              m_nAllocationCount = v13->iszChunkModels.m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<CNavLadder *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&v13->iszChunkModels,
                  num: m_Size - m_nAllocationCount + 1);
              ++v13->iszChunkModels.m_Size;
              m_pMemory = v13->iszChunkModels.m_Memory.m_pMemory;
              v18 = v13->iszChunkModels.m_Size - m_Size - 1;
              v13->iszChunkModels.m_pElements = m_pMemory;
              if ( v18 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
              v19 = (bool (__cdecl *)(const char *))&v13->iszChunkModels.m_Memory.m_pMemory[m_Size];
              if ( v19 != nullptr )
                *(string_t *)v19 = pooledName;
              v20 = pooledName.pszValue;
              if ( pooledName.pszValue == nullptr )
                v20 = locale;
              CBaseEntity::PrecacheModel(a1: v19, name: v20, bPreload: true);
              NextKey = KeyValues::GetNextKey(this: NextKey);
            }
            while ( NextKey != nullptr );
            p_m_BreakableChunks = v22;
            FirstSubKey = pChunkSection;
          }
          pChunkSection = KeyValues::GetNextKey(this: FirstSubKey);
          if ( pChunkSection == nullptr )
            break;
          FirstSubKey = pChunkSection;
        }
      }
    }
  }
  else
  {
    KeyValues::deleteThis(this: m_pKVPropData);
    this->m_pKVPropData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F11B0
// Name: public: CPropData::CPropData(void)
// Source: json
//------------------------------------------------------------------------------
CPropData *__thiscall CPropData::CPropData(CPropData *this)
{
  int *p_m_keySection; // esi
  int v3; // eax
  int v4; // eax

  CAutoGameSystem::CAutoGameSystem(this, name: "CPropData");
  this->__vftable = (CPropData_vtbl *)&CPropData::`vftable';
  this->m_BreakableChunks.m_Memory.m_pMemory = nullptr;
  this->m_BreakableChunks.m_Memory.m_nAllocationCount = 0;
  this->m_BreakableChunks.m_Memory.m_nGrowSize = 0;
  this->m_BreakableChunks.m_Size = 0;
  this->m_BreakableChunks.m_pElements = nullptr;
  this->m_bPropDataLoaded = false;
  this->m_pKVPropData = nullptr;
  p_m_keySection = &sPropdataInteractionSections[0].m_keySection;
  do
  {
    v3 = _KeyValuesSystem();
    *p_m_keySection = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v3 + 12))(
                        a1: v3,
                        a2: *(p_m_keySection - 3),
                        a3: 1);
    v4 = _KeyValuesSystem();
    p_m_keySection[1] = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v4 + 12))(
                          a1: v4,
                          a2: *(p_m_keySection - 2),
                          a3: 1);
    p_m_keySection += 5;
  }
  while ( (int)p_m_keySection < (int)&CGameGibManager::m_DataMap.baseMap );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F1250
// Name: public: virtual void CPropData::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropData::LevelInitPreEntity(CPropData *this)
{
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(this: (CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *)&this->m_BreakableChunks);
  CPropData::ParsePropDataFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x10374640
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103747A0
// Name: public: float KeyValues::GetFloat(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall KeyValues::GetFloat(KeyValues *this, const char *keyName, float defaultValue)
{
  KeyValues *Key; // eax
  double result; // st7

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atof(nptr: Key->m_sValue);
      break;
    case 2:
      result = (double)Key->m_iValue;
      break;
    case 3:
      result = Key->m_flValue;
      break;
    case 5:
      result = _wtof(nptr: Key->m_wsValue);
      break;
    case 7:
      result = (double)*(unsigned __int64 *)Key->m_sValue;
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037F7B0
// Name: public: virtual class KeyValues __near * vgui::Button::GetCommand(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Button::GetCommand(vgui::Button *this)
{
  return this->_actionMessage;
}

//------------------------------------------------------------------------------
// Address: 0x10382220
// Name: public: class KeyValues __near * vgui::EditablePanel::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::EditablePanel::GetDialogVariables(vgui::EditablePanel *this)
{
  KeyValues *result; // eax
  KeyValues *v3; // eax

  result = this->m_pDialogVariables;
  if ( result == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      result = KeyValues::KeyValues(this: v3, setName: "DialogVariables");
      this->m_pDialogVariables = result;
    }
    else
    {
      this->m_pDialogVariables = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398FE0
// Name: public: class KeyValues __near * vgui::ComboBox::GetActiveItemUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetActiveItemUserData(vgui::ComboBox *this)
{
  int v2; // eax

  v2 = this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1039C2B0
// Name: public: virtual class KeyValues __near * vgui::ListPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListPanel::GetItem(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->kv;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A2C90
// Name: public: virtual class KeyValues __near * vgui::ListViewPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListViewPanel::GetItem(vgui::ListViewPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A5ED0
// Name: public: class KeyValues __near * vgui::Menu::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Menu::GetItemUserData(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx
  vgui::MenuItem *m_Element; // esi

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID)
    && (m_Element = m_pMemory[v3].m_Element) != nullptr
    && m_Element->IsEnabled(this: m_Element) )
  {
    return vgui::MenuItem::GetUserData(this: m_Element);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA430
// Name: public: class KeyValues __near * vgui::MenuItem::GetUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::MenuItem::GetUserData(vgui::MenuItem *this)
{
  int v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    return this->m_pUserData;
  v2 = this->m_pCascadeMenu->GetActiveItem(this: this->m_pCascadeMenu);
  return vgui::Menu::GetItemUserData(this: this->m_pCascadeMenu, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x103BB450
// Name: public: virtual class KeyValues __near * vgui::TreeView::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::TreeView::GetItemData(vgui::TreeView *this, int itemIndex)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemIndex >= 0
    && itemIndex < this->m_NodeList.m_Memory.m_nAllocationCount
    && itemIndex <= this->m_NodeList.m_LastAlloc.index
    && ((m_pMemory = this->m_NodeList.m_Memory.m_pMemory, v3 = itemIndex, m_pMemory[itemIndex].m_Previous != itemIndex)
     || m_pMemory[v3].m_Next == itemIndex) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C36A0
// Name: public: class KeyValues __near * vgui::BuildGroup::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildGroup::GetDialogVariables(vgui::BuildGroup *this)
{
  vgui::EditablePanel *v1; // eax

  v1 = (vgui::EditablePanel *)__RTDynamicCast(
                                inptr: this->m_pParentPanel,
                                VfDelta: 0,
                                SrcType: &vgui::Panel `RTTI Type Descriptor',
                                TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
                                isReference: 0);
  if ( v1 != nullptr )
    return vgui::EditablePanel::GetDialogVariables(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C6B70
// Name: public: virtual class KeyValues __near * vgui::BuildModeDialog::StoreSettings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildModeDialog::StoreSettings(vgui::BuildModeDialog *this)
{
  KeyValues *v2; // esi
  const char *v3; // eax
  vgui::BuildModeDialog::PanelList *m_pPanelList; // eax
  int v5; // esi
  PanelItem_t *m_pMemory; // ecx
  PanelItem_t *v7; // eax
  const char *m_szName; // ebx
  void *m_EditPanel; // ecx
  int v10; // eax
  char buf[512]; // [esp+Ch] [ebp-208h] BYREF
  int i; // [esp+20Ch] [ebp-8h]
  KeyValues *storedSettings; // [esp+210h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = this->m_pCurrentPanel->GetName(this: this->m_pCurrentPanel);
    storedSettings = KeyValues::KeyValues(this: v2, setName: v3);
  }
  else
  {
    storedSettings = nullptr;
  }
  m_pPanelList = this->m_pPanelList;
  i = 0;
  if ( m_pPanelList->m_PanelList.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      v7 = m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      m_szName = m_pMemory[v5].m_szName;
      if ( m_pMemory[v5].m_EditPanel != nullptr )
        m_EditPanel = v7[v5].m_EditPanel;
      else
        m_EditPanel = v7[v5].m_EditButton;
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)m_EditPanel + 856))(a1: m_EditPanel, a2: buf, a3: 512);
      if ( (unsigned int)(this->m_pPanelList->m_PanelList.m_Memory.m_pMemory[v5].m_iType - 4) > 1 )
      {
        KeyValues::SetString(this: storedSettings, keyName: m_szName, value: buf);
      }
      else
      {
        v10 = atoi(nptr: buf);
        KeyValues::SetInt(this: storedSettings, keyName: m_szName, value: v10);
      }
      m_pPanelList = this->m_pPanelList;
      ++v5;
      ++i;
    }
    while ( i < m_pPanelList->m_PanelList.m_Size );
  }
  return storedSettings;
}

//------------------------------------------------------------------------------
// Address: 0x104093B0
// Name: CGameGibManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGameGibManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGameGibManager>();
  CGameGibManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

} // namespace server
