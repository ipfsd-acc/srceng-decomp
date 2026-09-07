// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/vcollide_parse.cpp
// Functions: 46
// ============================================================

#include "vphysics\vcollide_parse.h"

//------------------------------------------------------------------------------
// Address: 0x100300C0
// Name: char const __near * nexttoken(char __near *,char const __near *,char)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl nexttoken(char *token, char *str, char sep)
{
  char *result; // eax
  char v4; // cl
  char *v5; // esi

  result = str;
  if ( str != nullptr && (v4 = *str, *str != 0) )
  {
    v5 = token;
    if ( v4 != sep )
    {
      do
      {
        if ( v4 == 0 )
          break;
        ++result;
        *v5 = v4;
        v4 = *result;
        ++v5;
      }
      while ( *result != sep );
    }
    *v5 = 0;
    if ( *result != 0 )
      ++result;
  }
  else
  {
    *token = 0;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030110
// Name: public: virtual char const __near * CVPhysicsParse::GetCurrentBlockName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVPhysicsParse::GetCurrentBlockName(CVPhysicsParse *this)
{
  if ( this->m_pText != nullptr )
    return this->m_blockName;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10030120
// Name: public: virtual bool CVPhysicsParse::Finished(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVPhysicsParse::Finished(CVPhysicsParse *this)
{
  return this->m_pText == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10030130
// Name: void SetMassCenterPointer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMassCenterPointer(_DWORD *pData)
{
  pData[389] = pData + 384;
}

//------------------------------------------------------------------------------
// Address: 0x10030150
// Name: void SetSelfCollisions(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSelfCollisions(_DWORD *pData)
{
  _DWORD *v1; // eax

  v1 = (_DWORD *)pData[3];
  if ( v1 != nullptr )
    *v1 = pData[2];
}

//------------------------------------------------------------------------------
// Address: 0x10030170
// Name: void SetCollisionPair(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetCollisionPair(__int16 *pData)
{
  int v1; // ecx

  v1 = *((_DWORD *)pData + 3);
  if ( v1 != 0 && *(_DWORD *)v1 != 0 )
    (***(void (__thiscall ****)(_DWORD, _DWORD, _DWORD))(v1 + 4))(a1: *(_DWORD *)(v1 + 4), a2: pData[2], a3: pData[3]);
}

//------------------------------------------------------------------------------
// Address: 0x100301A0
// Name: public: virtual char const __near * CVPhysicsPackedParser::GetCurrentBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVPhysicsPackedParser::GetCurrentBlockName(CVPhysicsPackedParser *this)
{
  kventry_t *v1; // edx
  unsigned int blockIndex; // eax

  v1 = &this->m_pKeys[this->m_iCurrentBlock];
  blockIndex = v1->blockIndex;
  if ( blockIndex >= 6 )
    return &this->m_pStrings[this->m_pStringOffset[v1->key]];
  if ( v1->type != 0 )
    return g_ParseBlocks[blockIndex].pBlockName;
  return (const char *)(&off_100F6EEC)[3 * blockIndex][6 * v1->key];
}

//------------------------------------------------------------------------------
// Address: 0x100301F0
// Name: public: virtual bool CVPhysicsPackedParser::Finished(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVPhysicsPackedParser::Finished(CVPhysicsPackedParser *this)
{
  return this->m_iCurrentKey >= this->m_pPacked->keyCount;
}

//------------------------------------------------------------------------------
// Address: 0x10030200
// Name: public: virtual void CVPhysicsPackedParser::ParseSurfaceTable(int __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseSurfaceTable(
        CVPhysicsPackedParser *this,
        int *table,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  int m_iCurrentKey; // ebx
  kventry_t *m_pKeys; // edx
  int type; // ecx
  kventry_t *v7; // eax
  unsigned int blockIndex; // ecx
  const char *pBlockName; // eax
  int v10; // edi
  int v11; // eax
  packedkv_t *m_pPacked; // ecx
  kventry_t *v13; // ecx
  int v14; // eax

  m_iCurrentKey = this->m_iCurrentKey;
  if ( m_iCurrentKey >= this->m_pPacked->keyCount )
    return;
  while ( 1 )
  {
    m_pKeys = this->m_pKeys;
    type = m_pKeys[m_iCurrentKey].type;
    v7 = &m_pKeys[m_iCurrentKey];
    if ( (_WORD)type == 0 )
    {
      blockIndex = v7->blockIndex;
      if ( blockIndex < 6 )
      {
        if ( v7->type != 0 )
          pBlockName = g_ParseBlocks[blockIndex].pBlockName;
        else
          pBlockName = (const char *)(&off_100F6EEC)[3 * blockIndex][6 * v7->key];
      }
      else
      {
        pBlockName = &this->m_pStrings[this->m_pStringOffset[v7->key]];
      }
      v10 = physprops->GetSurfaceIndex(this: physprops, a2: pBlockName);
      v11 = atoi(nptr: &this->m_pStrings[this->m_pStringOffset[this->m_pKeys[m_iCurrentKey].value]]);
      if ( v11 < 128 )
        table[v11] = v10;
      goto LABEL_11;
    }
    if ( type == 2 )
      break;
LABEL_11:
    if ( ++m_iCurrentKey >= this->m_pPacked->keyCount )
      return;
  }
  m_pPacked = this->m_pPacked;
  this->m_iCurrentKey = m_iCurrentKey + 1;
  if ( m_iCurrentKey + 1 < m_pPacked->keyCount )
  {
    v13 = this->m_pKeys;
    while ( 1 )
    {
      v14 = this->m_iCurrentKey;
      if ( v13[v14].type == 1 )
        break;
      this->m_iCurrentKey = v14 + 1;
      if ( this->m_iCurrentKey >= this->m_pPacked->keyCount )
        return;
    }
    this->m_iCurrentBlock = v14;
    this->m_iCurrentKey = v14 + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030310
// Name: private: void CVPhysicsPackedParser::NextBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::NextBlock(CVPhysicsPackedParser *this)
{
  kventry_t *m_pKeys; // edx
  int m_iCurrentKey; // eax

  if ( this->m_iCurrentKey < this->m_pPacked->keyCount )
  {
    m_pKeys = this->m_pKeys;
    while ( 1 )
    {
      m_iCurrentKey = this->m_iCurrentKey;
      if ( m_pKeys[m_iCurrentKey].type == 1 )
        break;
      this->m_iCurrentKey = m_iCurrentKey + 1;
      if ( this->m_iCurrentKey >= this->m_pPacked->keyCount )
        return;
    }
    this->m_iCurrentBlock = m_iCurrentKey;
    this->m_iCurrentKey = m_iCurrentKey + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030350
// Name: char const __near * ParseKeyvalue(char const __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ParseKeyvalue(const char *pBuffer, char *key, char *value)
{
  const char *v3; // esi
  const char *v5; // edi
  char com_token[1024]; // [esp+8h] [ebp-400h] BYREF

  v3 = ParseFile(pFileBytes: pBuffer, pToken: com_token, pWasQuoted: nullptr, pCharSet: nullptr);
  if ( _V_strlen(str: com_token) < 1024 )
  {
    V_strncpy(pDest: key, pSrc: com_token, maxLen: 1024);
    _V_strlower(start: key);
  }
  if ( _V_strcmp(s1: key, s2: "}") != 0 )
  {
    v5 = ParseFile(pFileBytes: v3, pToken: com_token, pWasQuoted: nullptr, pCharSet: nullptr);
    if ( _V_strlen(str: com_token) < 1024 )
    {
      V_strncpy(pDest: value, pSrc: com_token, maxLen: 1024);
      _V_strlower(start: value);
    }
    return v5;
  }
  else
  {
    *value = 0;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030420
// Name: ReadVector
// Source: json
//------------------------------------------------------------------------------
void __usercall ReadVector(Vector *out@<esi>, const char *pString)
{
  float z; // [esp+0h] [ebp-Ch] BYREF
  float y; // [esp+4h] [ebp-8h] BYREF
  float x; // [esp+8h] [ebp-4h] BYREF

  sscanf(string: pString, format: "%f %f %f", &x, &y, &z);
  out->x = x;
  out->y = y;
  out->z = z;
}

//------------------------------------------------------------------------------
// Address: 0x10030470
// Name: ReadVector4D
// Source: json
//------------------------------------------------------------------------------
void __usercall ReadVector4D(Vector4D *out@<esi>, const char *pString)
{
  float w; // [esp+0h] [ebp-10h] BYREF
  float z; // [esp+4h] [ebp-Ch] BYREF
  float y; // [esp+8h] [ebp-8h] BYREF
  float x; // [esp+Ch] [ebp-4h] BYREF

  sscanf(string: pString, format: "%f %f %f %f", &x, &y, &z, &w);
  out->x = x;
  out->y = y;
  out->z = z;
  out->w = w;
}

//------------------------------------------------------------------------------
// Address: 0x100304D0
// Name: public: void CVPhysicsParse::NextBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::NextBlock(CVPhysicsParse *this)
{
  const char *v2; // esi
  char key[1024]; // [esp+4h] [ebp-C00h] BYREF
  char value[1024]; // [esp+404h] [ebp-800h] BYREF
  char pToken[1024]; // [esp+804h] [ebp-400h] BYREF

  if ( this->m_pText != nullptr )
  {
    while ( 1 )
    {
      v2 = ParseFile(pFileBytes: this->m_pText, pToken, pWasQuoted: nullptr, pCharSet: nullptr);
      if ( _V_strlen(str: pToken) < 1024 )
      {
        V_strncpy(pDest: key, pSrc: pToken, maxLen: 1024);
        _V_strlower(start: key);
      }
      if ( _V_strcmp(s1: key, s2: "}") != 0 )
      {
        v2 = ParseFile(pFileBytes: v2, pToken, pWasQuoted: nullptr, pCharSet: nullptr);
        if ( _V_strlen(str: pToken) < 1024 )
        {
          V_strncpy(pDest: value, pSrc: pToken, maxLen: 1024);
          _V_strlower(start: value);
        }
      }
      else
      {
        value[0] = 0;
      }
      this->m_pText = v2;
      if ( _V_strcmp(s1: value, s2: "{") == 0 )
        break;
      if ( this->m_pText == nullptr )
        return;
    }
    _V_strcpy(dest: this->m_blockName, src: key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100305F0
// Name: public: virtual void CVPhysicsParse::ParseSolid(struct solid_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseSolid(
        CVPhysicsParse *this,
        solid_t *pSolid,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  IVPhysicsKeyHandler *v3; // esi
  solid_t *v4; // edi
  const char *v6; // eax
  bool v7; // zf
  char value[1024]; // [esp+Ch] [ebp-808h] BYREF
  char key[1024]; // [esp+40Ch] [ebp-408h] BYREF
  float v10; // [esp+80Ch] [ebp-8h] BYREF
  float v11; // [esp+810h] [ebp-4h] BYREF

  v3 = unknownKeyHandler;
  v4 = pSolid;
  key[0] = 0;
  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pSolid);
  else
    memset(dst: (unsigned __int8 *)pSolid, value: 0, count: sizeof(solid_t));
  v4->params.enableCollisions = false;
  if ( this->m_pText != nullptr )
  {
    while ( 1 )
    {
      v6 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v7 = key[0] == 125;
      this->m_pText = v6;
      if ( v7 )
        break;
      if ( _V_stricmp(s1: key, s2: "index") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "name") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "parent") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "surfaceprop") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "mass") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "massCenterOverride") != 0 )
                {
                  if ( _V_stricmp(s1: key, s2: "inertia") != 0 )
                  {
                    if ( _V_stricmp(s1: key, s2: "damping") != 0 )
                    {
                      if ( _V_stricmp(s1: key, s2: "rotdamping") != 0 )
                      {
                        if ( _V_stricmp(s1: key, s2: "volume") != 0 )
                        {
                          if ( _V_stricmp(s1: key, s2: "drag") != 0 )
                          {
                            if ( _V_stricmp(s1: key, s2: "rollingdrag") != 0 && v3 != nullptr )
                              v3->ParseKeyValue(this: v3, a2: v4, a3: key, a4: value);
                          }
                          else
                          {
                            v4->params.dragCoefficient = atof(nptr: value);
                          }
                        }
                        else
                        {
                          v4->params.volume = atof(nptr: value);
                        }
                      }
                      else
                      {
                        v4->params.rotdamping = atof(nptr: value);
                      }
                    }
                    else
                    {
                      v4->params.damping = atof(nptr: value);
                    }
                  }
                  else
                  {
                    v4->params.inertia = atof(nptr: value);
                  }
                }
                else
                {
                  sscanf(string: value, format: "%f %f %f", &pSolid, &v10, &v11);
                  LODWORD(v4->massCenterOverride.x) = pSolid;
                  v4->massCenterOverride.y = v10;
                  v4->massCenterOverride.z = v11;
                  v4->params.massCenterOverride = &v4->massCenterOverride;
                  v3 = unknownKeyHandler;
                }
              }
              else
              {
                v4->params.mass = atof(nptr: value);
              }
            }
            else
            {
              V_strncpy(pDest: v4->surfaceprop, pSrc: value, maxLen: 512);
            }
          }
          else
          {
            V_strncpy(pDest: v4->parent, pSrc: value, maxLen: 512);
          }
        }
        else
        {
          V_strncpy(pDest: v4->name, pSrc: value, maxLen: 512);
        }
      }
      else
      {
        v4->index = atoi(nptr: value);
      }
      if ( this->m_pText == nullptr )
        return;
    }
    CVPhysicsParse::NextBlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030930
// Name: public: virtual void CVPhysicsParse::ParseRagdollConstraint(struct constraint_ragdollparams_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseRagdollConstraint(
        CVPhysicsParse *this,
        constraint_ragdollparams_t *pConstraint,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  const char *v4; // eax
  bool v5; // zf
  char value[1024]; // [esp+Ch] [ebp-800h] BYREF
  char key[1024]; // [esp+40Ch] [ebp-400h] BYREF

  key[0] = 0;
  if ( unknownKeyHandler != nullptr )
  {
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: (void *)pConstraint);
  }
  else
  {
    memset(dst: (unsigned __int8 *)pConstraint, value: 0, count: sizeof(constraint_ragdollparams_t));
    pConstraint->childIndex = -1;
    pConstraint->parentIndex = -1;
  }
  pConstraint->useClockwiseRotations = true;
  if ( this->m_pText != nullptr )
  {
    while ( 1 )
    {
      v4 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v5 = key[0] == 125;
      this->m_pText = v4;
      if ( v5 )
        break;
      if ( _V_stricmp(s1: key, s2: "parent") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "child") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "xmin") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "xmax") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "xfriction") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "ymin") != 0 )
                {
                  if ( _V_stricmp(s1: key, s2: "ymax") != 0 )
                  {
                    if ( _V_stricmp(s1: key, s2: "yfriction") != 0 )
                    {
                      if ( _V_stricmp(s1: key, s2: "zmin") != 0 )
                      {
                        if ( _V_stricmp(s1: key, s2: "zmax") != 0 )
                        {
                          if ( _V_stricmp(s1: key, s2: "zfriction") != 0 )
                          {
                            if ( unknownKeyHandler != nullptr )
                              unknownKeyHandler->ParseKeyValue(
                                this: unknownKeyHandler,
                                a2: (void *)pConstraint,
                                a3: key,
                                a4: value);
                          }
                          else
                          {
                            pConstraint->axes[2].angularVelocity = 0.0;
                            pConstraint->axes[2].torque = atof(nptr: value);
                          }
                        }
                        else
                        {
                          pConstraint->axes[2].maxRotation = atof(nptr: value);
                        }
                      }
                      else
                      {
                        pConstraint->axes[2].minRotation = atof(nptr: value);
                      }
                    }
                    else
                    {
                      pConstraint->axes[1].angularVelocity = 0.0;
                      pConstraint->axes[1].torque = atof(nptr: value);
                    }
                  }
                  else
                  {
                    pConstraint->axes[1].maxRotation = atof(nptr: value);
                  }
                }
                else
                {
                  pConstraint->axes[1].minRotation = atof(nptr: value);
                }
              }
              else
              {
                pConstraint->axes[0].angularVelocity = 0.0;
                pConstraint->axes[0].torque = atof(nptr: value);
              }
            }
            else
            {
              pConstraint->axes[0].maxRotation = atof(nptr: value);
            }
          }
          else
          {
            pConstraint->axes[0].minRotation = atof(nptr: value);
          }
        }
        else
        {
          pConstraint->childIndex = atoi(nptr: value);
        }
      }
      else
      {
        pConstraint->parentIndex = atoi(nptr: value);
      }
      if ( this->m_pText == nullptr )
        return;
    }
    CVPhysicsParse::NextBlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030C30
// Name: public: virtual void CVPhysicsParse::ParseFluid(struct fluid_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseFluid(
        CVPhysicsParse *this,
        fluid_t *pFluid,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  fluid_t *v3; // esi
  IVPhysicsKeyHandler *v4; // edi
  const char *v6; // eax
  bool v7; // zf
  char value[1024]; // [esp+Ch] [ebp-814h] BYREF
  char key[1024]; // [esp+40Ch] [ebp-414h] BYREF
  float v10; // [esp+80Ch] [ebp-14h] BYREF
  float v11; // [esp+810h] [ebp-10h] BYREF
  float v12; // [esp+814h] [ebp-Ch] BYREF
  float v13; // [esp+818h] [ebp-8h] BYREF
  float v14; // [esp+81Ch] [ebp-4h] BYREF

  v3 = pFluid;
  v4 = unknownKeyHandler;
  key[0] = 0;
  pFluid->index = -1;
  if ( v4 != nullptr )
  {
    v4->SetDefaults(this: v4, a2: v3);
  }
  else
  {
    memset(dst: (unsigned __int8 *)v3, value: 0, count: sizeof(fluid_t));
    strcpy(v3->surfaceprop, "water");
  }
  if ( this->m_pText != nullptr )
  {
    while ( 1 )
    {
      v6 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v7 = key[0] == 125;
      this->m_pText = v6;
      if ( v7 )
        break;
      if ( _V_stricmp(s1: key, s2: "index") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "damping") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "surfaceplane") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "currentvelocity") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "contents") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "surfaceprop") != 0 )
                {
                  if ( v4 != nullptr )
                    v4->ParseKeyValue(this: v4, a2: v3, a3: key, a4: value);
                }
                else
                {
                  V_strncpy(pDest: v3->surfaceprop, pSrc: value, maxLen: 512);
                }
              }
              else
              {
                v3->params.contents = atoi(nptr: value);
              }
            }
            else
            {
              sscanf(string: value, format: "%f %f %f", &v11, &v14, &v12);
              v3->params.currentVelocity.x = v11;
              v3->params.currentVelocity.y = v14;
              v3->params.currentVelocity.z = v12;
            }
          }
          else
          {
            sscanf(string: value, format: "%f %f %f %f", &pFluid, &unknownKeyHandler, &v13, &v10);
            LODWORD(v3->params.surfacePlane.x) = pFluid;
            LODWORD(v3->params.surfacePlane.y) = unknownKeyHandler;
            v3->params.surfacePlane.z = v13;
            v3->params.surfacePlane.w = v10;
          }
        }
        else
        {
          v3->params.damping = atof(nptr: value);
        }
      }
      else
      {
        v3->index = atoi(nptr: value);
      }
      if ( this->m_pText == nullptr )
        return;
    }
    CVPhysicsParse::NextBlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030EA0
// Name: public: virtual void CVPhysicsParse::ParseSurfaceTable(int __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseSurfaceTable(
        CVPhysicsParse *this,
        int *table,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  bool v4; // zf
  const char *v5; // eax
  int v6; // esi
  int v7; // eax
  char value[1024]; // [esp+4h] [ebp-800h] BYREF
  char key[1024]; // [esp+404h] [ebp-400h] BYREF

  v4 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v4 )
  {
    while ( 1 )
    {
      v5 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v4 = key[0] == 125;
      this->m_pText = v5;
      if ( v4 )
        break;
      v6 = physprops->GetSurfaceIndex(this: physprops, a2: key);
      v7 = atoi(nptr: value);
      if ( v7 < 128 )
        table[v7] = v6;
      if ( this->m_pText == nullptr )
        return;
    }
    CVPhysicsParse::NextBlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030F40
// Name: private: void CVPhysicsParse::ParseVehicleWheel(struct vehicle_wheelparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicleWheel(CVPhysicsParse *this, vehicle_wheelparams_t *wheel)
{
  bool v3; // zf
  const char *v4; // eax
  char value[1024]; // [esp+4h] [ebp-800h] BYREF
  char key[1024]; // [esp+404h] [ebp-400h] BYREF

  v3 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v3 )
  {
    do
    {
      v4 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v3 = key[0] == 125;
      this->m_pText = v4;
      if ( v3 )
        break;
      if ( _V_stricmp(s1: key, s2: "radius") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "mass") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "inertia") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "damping") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "rotdamping") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "frictionscale") != 0 )
                {
                  if ( _V_stricmp(s1: key, s2: "material") != 0 )
                  {
                    if ( _V_stricmp(s1: key, s2: "skidmaterial") != 0 )
                    {
                      if ( _V_stricmp(s1: key, s2: "brakematerial") == 0 )
                        wheel->brakeMaterialIndex = physprops->GetSurfaceIndex(this: physprops, a2: value);
                    }
                    else
                    {
                      wheel->skidMaterialIndex = physprops->GetSurfaceIndex(this: physprops, a2: value);
                    }
                  }
                  else
                  {
                    wheel->materialIndex = physprops->GetSurfaceIndex(this: physprops, a2: value);
                  }
                }
                else
                {
                  wheel->frictionScale = atof(nptr: value);
                }
              }
              else
              {
                wheel->rotdamping = atof(nptr: value);
              }
            }
            else
            {
              wheel->damping = atof(nptr: value);
            }
          }
          else
          {
            wheel->inertia = atof(nptr: value);
          }
        }
        else
        {
          wheel->mass = atof(nptr: value);
        }
      }
      else
      {
        wheel->radius = atof(nptr: value);
      }
    }
    while ( this->m_pText != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031150
// Name: private: void CVPhysicsParse::ParseVehicleSuspension(struct vehicle_suspensionparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicleSuspension(CVPhysicsParse *this, vehicle_suspensionparams_t *suspension)
{
  bool v3; // zf
  const char *v4; // esi
  char pToken[1024]; // [esp+4h] [ebp-C00h] BYREF
  char value[1024]; // [esp+404h] [ebp-800h] BYREF
  char key[1024]; // [esp+804h] [ebp-400h] BYREF

  v3 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v3 )
  {
    do
    {
      v4 = ParseFile(pFileBytes: this->m_pText, pToken, pWasQuoted: nullptr, pCharSet: nullptr);
      if ( _V_strlen(str: pToken) < 1024 )
      {
        V_strncpy(pDest: key, pSrc: pToken, maxLen: 1024);
        _V_strlower(start: key);
      }
      if ( _V_strcmp(s1: key, s2: "}") != 0 )
      {
        v4 = ParseFile(pFileBytes: v4, pToken, pWasQuoted: nullptr, pCharSet: nullptr);
        if ( _V_strlen(str: pToken) < 1024 )
        {
          V_strncpy(pDest: value, pSrc: pToken, maxLen: 1024);
          _V_strlower(start: value);
        }
      }
      else
      {
        value[0] = 0;
      }
      v3 = key[0] == 125;
      this->m_pText = v4;
      if ( v3 )
        break;
      if ( _V_stricmp(s1: key, s2: "springconstant") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "springdamping") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "stabilizerconstant") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "springdampingcompression") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "maxbodyforce") == 0 )
                suspension->maxBodyForce = atof(nptr: value);
            }
            else
            {
              suspension->springDampingCompression = atof(nptr: value);
            }
          }
          else
          {
            suspension->stabilizerConstant = atof(nptr: value);
          }
        }
        else
        {
          suspension->springDamping = atof(nptr: value);
        }
      }
      else
      {
        suspension->springConstant = atof(nptr: value);
      }
    }
    while ( this->m_pText != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031330
// Name: private: void CVPhysicsParse::ParseVehicleBody(struct vehicle_bodyparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicleBody(CVPhysicsParse *this, vehicle_bodyparams_t *body)
{
  bool v3; // zf
  vehicle_bodyparams_t *v4; // esi
  const char *v5; // eax
  char value[1024]; // [esp+4h] [ebp-808h] BYREF
  char key[1024]; // [esp+404h] [ebp-408h] BYREF
  float v8; // [esp+804h] [ebp-8h] BYREF
  float v9; // [esp+808h] [ebp-4h] BYREF

  v3 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v3 )
  {
    v4 = body;
    do
    {
      v5 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v3 = key[0] == 125;
      this->m_pText = v5;
      if ( v3 )
        break;
      if ( _V_stricmp(s1: key, s2: "massCenterOverride") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "addgravity") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "maxAngularVelocity") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "massOverride") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "tiltforce") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "tiltforceheight") != 0 )
                {
                  if ( _V_stricmp(s1: key, s2: "countertorquefactor") != 0 )
                  {
                    if ( _V_stricmp(s1: key, s2: "keepuprighttorque") == 0 )
                      v4->keepUprightTorque = atof(nptr: value);
                  }
                  else
                  {
                    v4->counterTorqueFactor = atof(nptr: value);
                  }
                }
                else
                {
                  v4->tiltForceHeight = atof(nptr: value);
                }
              }
              else
              {
                v4->tiltForce = atof(nptr: value);
              }
            }
            else
            {
              v4->massOverride = atof(nptr: value);
            }
          }
          else
          {
            v4->maxAngularVelocity = atof(nptr: value);
          }
        }
        else
        {
          v4->addGravity = atof(nptr: value);
        }
      }
      else
      {
        sscanf(string: value, format: "%f %f %f", &body, &v8, &v9);
        LODWORD(v4->massCenterOverride.x) = body;
        v4->massCenterOverride.y = v8;
        v4->massCenterOverride.z = v9;
      }
    }
    while ( this->m_pText != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031510
// Name: private: void CVPhysicsParse::ParseVehicleEngineBoost(struct vehicle_engineparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicleEngineBoost(CVPhysicsParse *this, vehicle_engineparams_t *engine)
{
  bool v3; // zf
  const char *v4; // esi
  char pToken[1024]; // [esp+4h] [ebp-C00h] BYREF
  char value[1024]; // [esp+404h] [ebp-800h] BYREF
  char key[1024]; // [esp+804h] [ebp-400h] BYREF

  v3 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v3 )
  {
    do
    {
      v4 = ParseFile(pFileBytes: this->m_pText, pToken, pWasQuoted: nullptr, pCharSet: nullptr);
      if ( _V_strlen(str: pToken) < 1024 )
      {
        V_strncpy(pDest: key, pSrc: pToken, maxLen: 1024);
        _V_strlower(start: key);
      }
      if ( _V_strcmp(s1: key, s2: "}") != 0 )
      {
        v4 = ParseFile(pFileBytes: v4, pToken, pWasQuoted: nullptr, pCharSet: nullptr);
        if ( _V_strlen(str: pToken) < 1024 )
        {
          V_strncpy(pDest: value, pSrc: pToken, maxLen: 1024);
          _V_strlower(start: value);
        }
      }
      else
      {
        value[0] = 0;
      }
      v3 = key[0] == 125;
      this->m_pText = v4;
      if ( v3 )
        break;
      if ( _V_stricmp(s1: key, s2: "force") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "duration") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "delay") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "maxspeed") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "torqueboost") == 0 )
                engine->torqueBoost = atoi(nptr: value) != 0;
            }
            else
            {
              engine->boostMaxSpeed = atof(nptr: value);
            }
          }
          else
          {
            engine->boostDelay = atof(nptr: value);
          }
        }
        else
        {
          engine->boostDuration = atof(nptr: value);
        }
      }
      else
      {
        engine->boostForce = atof(nptr: value);
      }
    }
    while ( this->m_pText != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031700
// Name: private: void CVPhysicsParse::ParseVehicleEngine(struct vehicle_engineparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicleEngine(CVPhysicsParse *this, vehicle_engineparams_t *engine)
{
  bool v3; // zf
  const char *v4; // eax
  char value[1024]; // [esp+4h] [ebp-800h] BYREF
  char key[1024]; // [esp+404h] [ebp-400h] BYREF

  v3 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v3 )
  {
    do
    {
      v4 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v3 = key[0] == 125;
      this->m_pText = v4;
      if ( v3 )
        break;
      if ( value[0] == 123 )
      {
        if ( _V_stricmp(s1: key, s2: "boost") != 0 )
          this->SkipBlock(this);
        else
          CVPhysicsParse::ParseVehicleEngineBoost(this, engine);
      }
      else if ( _V_stricmp(s1: key, s2: "gear") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "horsepower") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "maxSpeed") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "maxReverseSpeed") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "axleratio") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "maxRPM") != 0 )
                {
                  if ( _V_stricmp(s1: key, s2: "throttleTime") != 0 )
                  {
                    if ( _V_stricmp(s1: key, s2: "AutoTransmission") != 0 )
                    {
                      if ( _V_stricmp(s1: key, s2: "shiftUpRPM") != 0 )
                      {
                        if ( _V_stricmp(s1: key, s2: "shiftDownRPM") != 0 )
                        {
                          if ( _V_stricmp(s1: key, s2: "autobrakeSpeedGain") != 0 )
                          {
                            if ( _V_stricmp(s1: key, s2: "autobrakeSpeedFactor") == 0 )
                              engine->autobrakeSpeedFactor = atof(nptr: value);
                          }
                          else
                          {
                            engine->autobrakeSpeedGain = atof(nptr: value);
                          }
                        }
                        else
                        {
                          engine->shiftDownRPM = atof(nptr: value);
                        }
                      }
                      else
                      {
                        engine->shiftUpRPM = atof(nptr: value);
                      }
                    }
                    else
                    {
                      engine->isAutoTransmission = atoi(nptr: value) != 0;
                    }
                  }
                  else
                  {
                    engine->throttleTime = atof(nptr: value);
                  }
                }
                else
                {
                  engine->maxRPM = atof(nptr: value);
                }
              }
              else
              {
                engine->axleRatio = atof(nptr: value);
              }
            }
            else
            {
              engine->maxRevSpeed = atof(nptr: value);
            }
          }
          else
          {
            engine->maxSpeed = atof(nptr: value);
          }
        }
        else
        {
          engine->horsepower = atof(nptr: value);
        }
      }
      else
      {
        engine->gearRatio[engine->gearCount++] = atof(nptr: value);
      }
    }
    while ( this->m_pText != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100319B0
// Name: private: void CVPhysicsParse::ParseVehicleSteering(struct vehicle_steeringparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicleSteering(CVPhysicsParse *this, vehicle_steeringparams_t *steering)
{
  bool v3; // zf
  const char *v4; // eax
  char value[1024]; // [esp+4h] [ebp-800h] BYREF
  char key[1024]; // [esp+404h] [ebp-400h] BYREF

  v3 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v3 )
  {
    do
    {
      v4 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v3 = key[0] == 125;
      this->m_pText = v4;
      if ( v3 )
        break;
      if ( _V_stricmp(s1: key, s2: "degreesSlow") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "degreesFast") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "degreesBoost") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "fastcarspeed") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "slowcarspeed") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "slowsteeringrate") != 0 )
                {
                  if ( _V_stricmp(s1: key, s2: "faststeeringrate") != 0 )
                  {
                    if ( _V_stricmp(s1: key, s2: "steeringRestRateSlow") != 0 )
                    {
                      if ( _V_stricmp(s1: key, s2: "steeringRestRateFast") != 0 )
                      {
                        if ( _V_stricmp(s1: key, s2: "throttleSteeringRestRateFactor") != 0 )
                        {
                          if ( _V_stricmp(s1: key, s2: "boostSteeringRestRateFactor") != 0 )
                          {
                            if ( _V_stricmp(s1: key, s2: "boostSteeringRateFactor") != 0 )
                            {
                              if ( _V_stricmp(s1: key, s2: "steeringExponent") != 0 )
                              {
                                if ( _V_stricmp(s1: key, s2: "turnThrottleReduceSlow") != 0 )
                                {
                                  if ( _V_stricmp(s1: key, s2: "turnThrottleReduceFast") != 0 )
                                  {
                                    if ( _V_stricmp(s1: key, s2: "brakeSteeringRateFactor") != 0 )
                                    {
                                      if ( _V_stricmp(s1: key, s2: "powerSlideAccel") != 0 )
                                      {
                                        if ( _V_stricmp(s1: key, s2: "skidallowed") != 0 )
                                        {
                                          if ( _V_stricmp(s1: key, s2: "dustcloud") == 0 )
                                            steering->dustCloud = atoi(nptr: value) != 0;
                                        }
                                        else
                                        {
                                          steering->isSkidAllowed = atoi(nptr: value) != 0;
                                        }
                                      }
                                      else
                                      {
                                        steering->powerSlideAccel = atof(nptr: value);
                                      }
                                    }
                                    else
                                    {
                                      steering->brakeSteeringRateFactor = atof(nptr: value);
                                    }
                                  }
                                  else
                                  {
                                    steering->turnThrottleReduceFast = atof(nptr: value);
                                  }
                                }
                                else
                                {
                                  steering->turnThrottleReduceSlow = atof(nptr: value);
                                }
                              }
                              else
                              {
                                steering->steeringExponent = atof(nptr: value);
                              }
                            }
                            else
                            {
                              steering->boostSteeringRateFactor = atof(nptr: value);
                            }
                          }
                          else
                          {
                            steering->boostSteeringRestRateFactor = atof(nptr: value);
                          }
                        }
                        else
                        {
                          steering->throttleSteeringRestRateFactor = atof(nptr: value);
                        }
                      }
                      else
                      {
                        steering->steeringRestRateFast = atof(nptr: value);
                      }
                    }
                    else
                    {
                      steering->steeringRestRateSlow = atof(nptr: value);
                    }
                  }
                  else
                  {
                    steering->steeringRateFast = atof(nptr: value);
                  }
                }
                else
                {
                  steering->steeringRateSlow = atof(nptr: value);
                }
              }
              else
              {
                steering->speedSlow = atof(nptr: value);
              }
            }
            else
            {
              steering->speedFast = atof(nptr: value);
            }
          }
          else
          {
            steering->degreesBoost = atof(nptr: value);
          }
        }
        else
        {
          steering->degreesFast = atof(nptr: value);
        }
      }
      else
      {
        steering->degreesSlow = atof(nptr: value);
      }
    }
    while ( this->m_pText != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031D90
// Name: public: virtual void CVPhysicsParse::ParseCustom(void __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseCustom(
        CVPhysicsParse *this,
        void *pCustom,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  int v3; // ebx
  const char *v5; // eax
  char value[1024]; // [esp+Ch] [ebp-800h] BYREF
  char key[1024]; // [esp+40Ch] [ebp-400h] BYREF

  v3 = 0;
  key[0] = 0;
  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pCustom);
  while ( this->m_pText != nullptr )
  {
    v5 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
    this->m_pText = v5;
    if ( v5 != nullptr )
    {
      if ( key[0] == 123 )
      {
        ++v3;
      }
      else
      {
        if ( value[0] == 123 )
        {
          ++v3;
LABEL_9:
          if ( unknownKeyHandler != nullptr )
            unknownKeyHandler->ParseKeyValue(this: unknownKeyHandler, a2: pCustom, a3: key, a4: value);
          continue;
        }
        if ( key[0] != 125 )
          goto LABEL_9;
        if ( --v3 < 0 )
        {
          CVPhysicsParse::NextBlock(this);
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031E40
// Name: public: virtual void CVPhysicsParse::ParseCollisionRules(struct ragdollcollisionrules_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseCollisionRules(
        CVPhysicsParse *this,
        ragdollcollisionrules_t *pRules,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  CVPhysicsParse *v3; // esi
  const char *v4; // eax
  bool v5; // zf
  char v6; // al
  char *v7; // ecx
  char *v8; // edx
  char *v9; // esi
  int v10; // edi
  char *v11; // edx
  char *v12; // ecx
  char v13; // al
  int v14; // eax
  char value[1024]; // [esp+8h] [ebp-904h] BYREF
  char key[1024]; // [esp+408h] [ebp-504h] BYREF
  char szToken[256]; // [esp+808h] [ebp-104h] BYREF
  CVPhysicsParse *v18; // [esp+908h] [ebp-4h]

  v3 = this;
  v18 = this;
  key[0] = 0;
  if ( this->m_pText != nullptr )
  {
    while ( 1 )
    {
      v4 = ParseKeyvalue(pBuffer: v3->m_pText, key, value);
      v5 = key[0] == 125;
      v3->m_pText = v4;
      if ( v5 )
        break;
      if ( _V_stricmp(s1: key, s2: "selfcollisions") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "collisionpair") != 0 )
        {
          if ( unknownKeyHandler != nullptr )
            unknownKeyHandler->ParseKeyValue(this: unknownKeyHandler, a2: pRules, a3: key, a4: value);
        }
        else if ( pRules->bSelfCollisions != 0 )
        {
          v6 = value[0];
          v7 = value;
          v8 = szToken;
          if ( value[0] != 0 )
          {
            if ( value[0] != 44 )
            {
              do
              {
                if ( v6 == 0 )
                  break;
                ++v7;
                *v8 = v6;
                v6 = *v7;
                ++v8;
              }
              while ( *v7 != 44 );
            }
            *v8 = 0;
            if ( *v7 != 0 )
              v9 = v7 + 1;
            else
              v9 = v7;
          }
          else
          {
            szToken[0] = 0;
            v9 = nullptr;
          }
          v10 = atoi(nptr: szToken);
          v11 = v9;
          v12 = szToken;
          if ( v9 != nullptr && (v13 = *v9, *v9 != 0) )
          {
            if ( v13 != 44 )
            {
              do
              {
                if ( v13 == 0 )
                  break;
                ++v11;
                *v12 = v13;
                v13 = *v11;
                ++v12;
              }
              while ( *v11 != 44 );
            }
            *v12 = 0;
          }
          else
          {
            szToken[0] = 0;
          }
          v14 = atoi(nptr: szToken);
          pRules->pCollisionSet->EnableCollisions(this: pRules->pCollisionSet, a2: v10, a3: v14);
          v3 = v18;
        }
      }
      else
      {
        pRules->bSelfCollisions = 0;
      }
      if ( v3->m_pText == nullptr )
        return;
    }
    CVPhysicsParse::NextBlock(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031FC0
// Name: public: virtual void CVPhysicsParse::ParseRagdollAnimatedFriction(struct ragdollanimatedfriction_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseRagdollAnimatedFriction(
        CVPhysicsParse *this,
        ragdollanimatedfriction_t *pFriction,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  bool v4; // zf
  const char *v5; // eax
  char value[1024]; // [esp+Ch] [ebp-800h] BYREF
  char key[1024]; // [esp+40Ch] [ebp-400h] BYREF

  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pFriction);
  else
    _V_memset(dest: pFriction, fill: 0, count: 20);
  v4 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v4 )
  {
    while ( 1 )
    {
      v5 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v4 = key[0] == 125;
      this->m_pText = v5;
      if ( v4 )
        break;
      if ( _V_stricmp(s1: key, s2: "animfrictionmin") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "animfrictionmax") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "animfrictiontimein") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "animfrictiontimeout") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "animfrictiontimehold") != 0 )
              {
                if ( unknownKeyHandler != nullptr )
                  unknownKeyHandler->ParseKeyValue(this: unknownKeyHandler, a2: pFriction, a3: key, a4: value);
              }
              else
              {
                pFriction->timeHold = atof(nptr: value);
              }
            }
            else
            {
              pFriction->timeOut = atof(nptr: value);
            }
          }
          else
          {
            pFriction->timeIn = atof(nptr: value);
          }
        }
        else
        {
          pFriction->maxFriction = atof(nptr: value);
        }
      }
      else
      {
        pFriction->minFriction = atof(nptr: value);
      }
      if ( this->m_pText == nullptr )
        return;
    }
    CVPhysicsParse::NextBlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032150
// Name: public: virtual void collision_rules_t::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall collision_rules_t::ParseKeyValue(
        collision_rules_t *this,
        void *pData,
        const char *pKey,
        const char *pValue)
{
  this->pKeyHandler->ParseKeyValue(this: this->pKeyHandler, a2: this->pRules, a3: pKey, a4: pValue);
}

//------------------------------------------------------------------------------
// Address: 0x10032170
// Name: StoreField
// Source: json
//------------------------------------------------------------------------------
int __usercall StoreField@<eax>(parsefield_t *field@<ecx>, char *pValue@<eax>, unsigned int *pOut@<edi>)
{
  int result; // eax
  char *v4; // esi
  __int16 v5; // bx
  __int16 v6; // ax
  char szToken[256]; // [esp+0h] [ebp-110h] BYREF
  Vector4D out; // [esp+100h] [ebp-10h] BYREF

  if ( (field->flags & 3) != 0 )
    return 0;
  switch ( field->type )
  {
    case 1:
      *pOut = atoi(nptr: pValue);
      result = 1;
      break;
    case 2:
      *(float *)pOut = atof(nptr: pValue);
      result = 1;
      break;
    case 3:
      ReadVector(out: (Vector *)&out.y, pString: pValue);
      *pOut = LODWORD(out.y);
      pOut[1] = LODWORD(out.z);
      pOut[2] = LODWORD(out.w);
      result = 3;
      break;
    case 5:
      v4 = nexttoken(token: szToken, str: pValue, sep: 44);
      v5 = atoi(nptr: szToken);
      nexttoken(token: szToken, str: v4, sep: 44);
      v6 = atoi(nptr: szToken);
      *(_WORD *)pOut = v5;
      *((_WORD *)pOut + 1) = v6;
      result = 1;
      break;
    case 6:
      ReadVector4D(&out, pString: pValue);
      *(Vector4D *)pOut = out;
      result = 4;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100322B0
// Name: private: class Vector4D CVPhysicsPackedParser::ValueVector4D(struct kventry_t __near &)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall CVPhysicsPackedParser::ValueVector4D(
        CVPhysicsPackedParser *this,
        Vector4D *result,
        kventry_t *keyEntry)
{
  *result = *(Vector4D *)((char *)&this->m_pPacked->id + this->m_pPacked->heapOffset + keyEntry->value);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100322F0
// Name: public: void CVPhysicsPackedParser::ParseFields(unsigned char __near *,struct parsefield_t __near *,int,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseFields(
        CVPhysicsPackedParser *this,
        unsigned __int8 *pBase,
        parsefield_t *pFields,
        int fieldCount,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  int keyCount; // ecx
  int m_iCurrentKey; // edx
  kventry_t *m_pKeys; // eax
  int type; // ecx
  kventry_t *v10; // eax
  unsigned int blockIndex; // ecx
  struct parsefield_t **v12; // edi
  int value; // eax
  struct parsefield_t *v14; // edi
  char *v15; // edx
  __int64 v16; // xmm0_8
  int v17; // eax
  Vector4D *v18; // eax
  struct parsefield_t *v19; // edi
  float *v20; // edi
  unsigned int v21; // ecx
  const char *pBlockName; // ecx
  int v23; // ecx
  int v24; // eax
  packedkv_t *m_pPacked; // edx
  kventry_t *v26; // ecx
  int v27; // eax
  Vector4D result; // [esp+4h] [ebp-20h] BYREF
  __int64 v29; // [esp+14h] [ebp-10h]
  int v30; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  keyCount = this->m_pPacked->keyCount;
  m_iCurrentKey = this->m_iCurrentKey;
  i = m_iCurrentKey;
  if ( m_iCurrentKey >= keyCount )
    return;
  while ( 1 )
  {
    m_pKeys = this->m_pKeys;
    type = m_pKeys[m_iCurrentKey].type;
    v10 = &m_pKeys[m_iCurrentKey];
    if ( (_WORD)type == 0 )
    {
      blockIndex = v10->blockIndex;
      if ( blockIndex >= 6 || ((_BYTE)(v12 = &(&off_100F6EEC)[3 * blockIndex][6 * v10->key])[3] & 3) != 0 )
      {
        v21 = v10->blockIndex;
        if ( v21 < 6 )
        {
          if ( v10->type != 0 )
            pBlockName = g_ParseBlocks[v21].pBlockName;
          else
            pBlockName = (const char *)(&off_100F6EEC)[3 * v21][6 * v10->key];
        }
        else
        {
          pBlockName = &this->m_pStrings[this->m_pStringOffset[v10->key]];
        }
        if ( unknownKeyHandler != nullptr )
          unknownKeyHandler->ParseKeyValue(
            this: unknownKeyHandler,
            a2: pBase,
            a3: pBlockName,
            a4: &this->m_pStrings[this->m_pStringOffset[v10->value]]);
      }
      else
      {
        switch ( (unsigned int)v12[2] )
        {
          case 1u:
            *(const char **)((char *)&v12[1]->pName + (_DWORD)pBase) = *(const char **)((char *)&this->m_pPacked->id
                                                                                      + v10->value
                                                                                      + this->m_pPacked->heapOffset);
            break;
          case 2u:
            *(const char **)((char *)&v12[1]->pName + (_DWORD)pBase) = *(const char **)((char *)&this->m_pPacked->id
                                                                                      + v10->value
                                                                                      + this->m_pPacked->heapOffset);
            break;
          case 3u:
            value = v10->value;
            v14 = v12[1];
            v15 = (char *)this->m_pPacked + this->m_pPacked->heapOffset;
            v16 = *(_QWORD *)&v15[value];
            v17 = *(_DWORD *)&v15[value + 8];
            v29 = v16;
            *(_DWORD *)&pBase[(_DWORD)v14] = v16;
            v30 = v17;
            *(_DWORD *)&pBase[(_DWORD)v14 + 4] = HIDWORD(v29);
            *(_DWORD *)&pBase[(_DWORD)v14 + 8] = v30;
            break;
          case 4u:
            V_strncpy(
              pDest: (char *)v12[1] + (_DWORD)pBase,
              pSrc: &this->m_pStrings[this->m_pStringOffset[v10->value]],
              maxLen: (int)v12[4]);
            break;
          case 5u:
            *(const char **)((char *)&v12[1]->pName + (_DWORD)pBase) = *(const char **)((char *)&this->m_pPacked->id
                                                                                      + v10->value
                                                                                      + this->m_pPacked->heapOffset);
            break;
          case 6u:
            v18 = CVPhysicsPackedParser::ValueVector4D(this, &result, keyEntry: v10);
            v19 = v12[1];
            *(float *)&pBase[(_DWORD)v19] = v18->x;
            v20 = (float *)((char *)v19 + (_DWORD)pBase);
            v20[1] = v18->y;
            v20[2] = v18->z;
            v20[3] = v18->w;
            break;
          default:
            goto LABEL_20;
        }
      }
      goto LABEL_20;
    }
    if ( type == 2 )
      break;
LABEL_20:
    v23 = this->m_pPacked->keyCount;
    m_iCurrentKey = i + 1;
    i = m_iCurrentKey;
    if ( m_iCurrentKey >= v23 )
      return;
  }
  v24 = m_iCurrentKey + 1;
  m_pPacked = this->m_pPacked;
  this->m_iCurrentKey = v24;
  if ( v24 < m_pPacked->keyCount )
  {
    v26 = this->m_pKeys;
    while ( 1 )
    {
      v27 = this->m_iCurrentKey;
      if ( v26[v27].type == 1 )
        break;
      this->m_iCurrentKey = v27 + 1;
      if ( this->m_iCurrentKey >= this->m_pPacked->keyCount )
        return;
    }
    this->m_iCurrentBlock = v27;
    this->m_iCurrentKey = v27 + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032540
// Name: public: CVPhysicsPackedParser::CVPhysicsPackedParser(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVPhysicsPackedParser *__thiscall CVPhysicsPackedParser::CVPhysicsPackedParser(
        CVPhysicsPackedParser *this,
        char *pKeyData)
{
  kventry_t *m_pKeys; // ecx
  int m_iCurrentKey; // eax

  this->__vftable = (CVPhysicsPackedParser_vtbl *)&CVPhysicsPackedParser::`vftable';
  this->m_iCurrentKey = 0;
  this->m_pPacked = (packedkv_t *)pKeyData;
  this->m_pKeys = (kventry_t *)(pKeyData + 12);
  this->m_pStringOffset = (unsigned __int16 *)&pKeyData[8 * *((unsigned __int16 *)pKeyData + 2) + 12];
  this->m_pStrings = &pKeyData[8 * *((unsigned __int16 *)pKeyData + 2) + 12 + 2 * *((unsigned __int16 *)pKeyData + 3)];
  if ( *(_DWORD *)pKeyData != 256 )
    _Error(a1: "Bad packed vcollide!\n");
  if ( this->m_iCurrentKey < this->m_pPacked->keyCount )
  {
    m_pKeys = this->m_pKeys;
    while ( 1 )
    {
      m_iCurrentKey = this->m_iCurrentKey;
      if ( m_pKeys[m_iCurrentKey].type == 1 )
        break;
      this->m_iCurrentKey = m_iCurrentKey + 1;
      if ( this->m_iCurrentKey >= this->m_pPacked->keyCount )
        return this;
    }
    this->m_iCurrentBlock = m_iCurrentKey;
    this->m_iCurrentKey = m_iCurrentKey + 1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10032600
// Name: public: virtual void CVPhysicsPackedParser::ParseSolid(struct solid_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseSolid(
        CVPhysicsPackedParser *this,
        solid_t *pSolid,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pSolid);
  else
    memset(dst: (unsigned __int8 *)pSolid, value: 0, count: sizeof(solid_t));
  pSolid->params.enableCollisions = false;
  CVPhysicsPackedParser::ParseFields(
    this,
    pBase: (unsigned __int8 *)pSolid,
    pFields: g_SolidBlock,
    fieldCount: 14,
    unknownKeyHandler);
}

//------------------------------------------------------------------------------
// Address: 0x10032650
// Name: public: virtual void CVPhysicsPackedParser::ParseFluid(struct fluid_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseFluid(
        CVPhysicsPackedParser *this,
        fluid_t *pFluid,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pFluid);
  else
    memset(dst: (unsigned __int8 *)pFluid, value: 0, count: sizeof(fluid_t));
  CVPhysicsPackedParser::ParseFields(
    this,
    pBase: (unsigned __int8 *)pFluid,
    pFields: g_FluidBlock,
    fieldCount: 6,
    unknownKeyHandler);
}

//------------------------------------------------------------------------------
// Address: 0x100326A0
// Name: public: virtual void CVPhysicsPackedParser::ParseRagdollConstraint(struct constraint_ragdollparams_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseRagdollConstraint(
        CVPhysicsPackedParser *this,
        constraint_ragdollparams_t *pConstraint,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  if ( unknownKeyHandler != nullptr )
  {
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: (void *)pConstraint);
  }
  else
  {
    memset(dst: (unsigned __int8 *)pConstraint, value: 0, count: sizeof(constraint_ragdollparams_t));
    pConstraint->childIndex = -1;
    pConstraint->parentIndex = -1;
  }
  pConstraint->useClockwiseRotations = true;
  CVPhysicsPackedParser::ParseFields(
    this,
    pBase: (unsigned __int8 *)pConstraint,
    pFields: g_RagdollConstraintBlock,
    fieldCount: 11,
    unknownKeyHandler);
}

//------------------------------------------------------------------------------
// Address: 0x10032700
// Name: CreateStringFromValue
// Source: json
//------------------------------------------------------------------------------
const char *__fastcall CreateStringFromValue(
        kventry_t *keyEntry,
        int outSize,
        packedkv_t *pPacked,
        int parseType,
        char *pOut)
{
  const char *result; // eax
  int v6; // ecx
  char *v7; // edi

  switch ( parseType )
  {
    case 1:
      V_snprintf(
        pDest: pOut,
        maxLen: outSize,
        pFormat: "%d",
        *(unsigned int *)((char *)&pPacked->id + pPacked->heapOffset + keyEntry->value));
      result = pOut;
      break;
    case 2:
      V_snprintf(
        pDest: pOut,
        maxLen: outSize,
        pFormat: "%f",
        *(float *)((char *)&pPacked->id + pPacked->heapOffset + keyEntry->value));
      result = pOut;
      break;
    case 3:
      V_snprintf(
        pDest: pOut,
        maxLen: outSize,
        pFormat: "%f %f %f ",
        *(float *)((char *)&pPacked->id + pPacked->heapOffset + keyEntry->value),
        *(float *)((char *)&pPacked->keyCount + pPacked->heapOffset + keyEntry->value),
        *(float *)((char *)&pPacked->heapSize + pPacked->heapOffset + keyEntry->value));
      result = pOut;
      break;
    case 5:
      v6 = *(unsigned int *)((char *)&pPacked->id + pPacked->heapOffset + keyEntry->value);
      V_snprintf(pDest: pOut, maxLen: outSize, pFormat: "%d,%d", (__int16)v6, SHIWORD(v6));
      result = pOut;
      break;
    case 6:
      v7 = (char *)pPacked + pPacked->heapOffset;
      V_snprintf(
        pDest: pOut,
        maxLen: outSize,
        pFormat: "%f %f %f %f ",
        *(float *)&v7[keyEntry->value],
        *(float *)&v7[keyEntry->value + 4],
        *(float *)&v7[keyEntry->value + 8],
        *(float *)&v7[keyEntry->value + 12]);
      result = pOut;
      break;
    default:
      result = (char *)&pPacked[1]
             + 8 * pPacked->keyCount
             + 2 * pPacked->stringCount
             + *((unsigned __int16 *)&pPacked[1].id + 4 * pPacked->keyCount + keyEntry->value);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100328B0
// Name: public: virtual void CVPhysicsPackedParser::ParseCustom(void __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseCustom(
        CVPhysicsPackedParser *this,
        void *pCustom,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  int keyCount; // ecx
  int m_iCurrentKey; // edx
  kventry_t *m_pKeys; // ecx
  unsigned int v8; // edi
  int type; // eax
  kventry_t *v10; // ecx
  struct parsefield_t **v11; // edx
  const char *StringFromValue; // eax
  kventry_t *v13; // ecx
  unsigned int blockIndex; // edx
  kventry_t *v15; // ecx
  const char *pBlockName; // ecx
  unsigned int v17; // eax
  const char *v18; // eax
  int v19; // ecx
  char tmpStr[512]; // [esp+Ch] [ebp-204h] BYREF
  int i; // [esp+20Ch] [ebp-4h]
  int indent; // [esp+21Ch] [ebp+Ch]

  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pCustom);
  keyCount = this->m_pPacked->keyCount;
  m_iCurrentKey = this->m_iCurrentKey;
  indent = 0;
  i = m_iCurrentKey;
  if ( m_iCurrentKey >= keyCount )
  {
LABEL_27:
    this->m_iCurrentKey = this->m_pPacked->keyCount;
    return;
  }
  while ( 1 )
  {
    m_pKeys = this->m_pKeys;
    v8 = m_iCurrentKey;
    type = m_pKeys[m_iCurrentKey].type;
    v10 = &m_pKeys[m_iCurrentKey];
    if ( (_WORD)type == 0 )
    {
      if ( unknownKeyHandler != nullptr )
      {
        if ( v10->blockIndex >= 6u
          || ((int)(v11 = (&off_100F6EEC)[3 * v10->blockIndex])[6 * v10->key + 3] & 3) != 0
          || (StringFromValue = CreateStringFromValue(
                                  keyEntry: v10,
                                  outSize: 512,
                                  pPacked: this->m_pPacked,
                                  parseType: (int)v11[6 * v10->key + 2],
                                  pOut: tmpStr)) == nullptr )
        {
          StringFromValue = &this->m_pStrings[this->m_pStringOffset[this->m_pKeys[v8].value]];
        }
        v13 = this->m_pKeys;
        blockIndex = v13[v8].blockIndex;
        v15 = &v13[v8];
        if ( blockIndex < 6 )
        {
          if ( v15->type != 0 )
            pBlockName = g_ParseBlocks[blockIndex].pBlockName;
          else
            pBlockName = (const char *)(&off_100F6EEC)[3 * blockIndex][6 * v15->key];
        }
        else
        {
          pBlockName = &this->m_pStrings[this->m_pStringOffset[v15->key]];
        }
        unknownKeyHandler->ParseKeyValue(this: unknownKeyHandler, a2: pCustom, a3: pBlockName, a4: StringFromValue);
        m_iCurrentKey = i;
      }
      goto LABEL_26;
    }
    if ( (_WORD)type == 1 )
    {
      ++indent;
      if ( unknownKeyHandler != nullptr )
      {
        v17 = v10->blockIndex;
        if ( v17 < 6 )
        {
          if ( v10->type != 0 )
            v18 = g_ParseBlocks[v17].pBlockName;
          else
            v18 = (const char *)(&off_100F6EEC)[3 * v17][6 * v10->key];
        }
        else
        {
          v18 = &this->m_pStrings[this->m_pStringOffset[v10->key]];
        }
        unknownKeyHandler->ParseKeyValue(this: unknownKeyHandler, a2: pCustom, a3: v18, a4: "{");
        m_iCurrentKey = i;
      }
      goto LABEL_26;
    }
    if ( type == 2 && --indent < 0 )
      break;
LABEL_26:
    v19 = this->m_pPacked->keyCount;
    i = ++m_iCurrentKey;
    if ( m_iCurrentKey >= v19 )
      goto LABEL_27;
  }
  this->m_iCurrentKey = m_iCurrentKey + 1;
  CVPhysicsPackedParser::NextBlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x10032A70
// Name: public: virtual void CVPhysicsPackedParser::ParseCollisionRules(struct ragdollcollisionrules_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseCollisionRules(
        CVPhysicsPackedParser *this,
        ragdollcollisionrules_t *pRules,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  collision_rules_t tmp; // [esp+Ch] [ebp-14h] BYREF

  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pRules);
  tmp.__vftable = (collision_rules_t_vtbl *)&collision_rules_t::`vftable';
  tmp.pKeyHandler = unknownKeyHandler;
  tmp.pRules = pRules;
  CVPhysicsPackedParser::ParseFields(
    this,
    pBase: (unsigned __int8 *)&tmp,
    pFields: g_CollisionRulesBlock,
    fieldCount: 2,
    unknownKeyHandler: &tmp);
}

//------------------------------------------------------------------------------
// Address: 0x10032AC0
// Name: public: virtual void CVPhysicsPackedParser::ParseRagdollAnimatedFriction(struct ragdollanimatedfriction_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsPackedParser::ParseRagdollAnimatedFriction(
        CVPhysicsPackedParser *this,
        ragdollanimatedfriction_t *pFriction,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: pFriction);
  else
    _V_memset(dest: pFriction, fill: 0, count: 20);
  CVPhysicsPackedParser::ParseFields(
    this,
    pBase: (unsigned __int8 *)pFriction,
    pFields: g_RagdollAnimatedFrictionBlock,
    fieldCount: 5,
    unknownKeyHandler);
}

//------------------------------------------------------------------------------
// Address: 0x10032B10
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032BA0
// Name: public: virtual void CVPhysicsParse::SkipBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::SkipBlock(CVPhysicsParse *this)
{
  this->ParseCustom(this, a2: nullptr, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10032BB0
// Name: private: void CVPhysicsParse::ParseVehicleAxle(struct vehicle_axleparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicleAxle(CVPhysicsParse *this, vehicle_axleparams_t *axle)
{
  vehicle_axleparams_t *v2; // esi
  bool v4; // zf
  const char *v5; // eax
  char value[1024]; // [esp+8h] [ebp-814h] BYREF
  char key[1024]; // [esp+408h] [ebp-414h] BYREF
  float v8; // [esp+808h] [ebp-14h] BYREF
  float v9; // [esp+80Ch] [ebp-10h] BYREF
  float v10; // [esp+810h] [ebp-Ch] BYREF
  float v11; // [esp+814h] [ebp-8h] BYREF
  float v12; // [esp+818h] [ebp-4h] BYREF

  v2 = axle;
  memset(dst: (unsigned __int8 *)axle, value: 0, count: sizeof(vehicle_axleparams_t));
  v4 = this->m_pText == nullptr;
  key[0] = 0;
  if ( !v4 )
  {
    do
    {
      v5 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v4 = key[0] == 125;
      this->m_pText = v5;
      if ( v4 )
        break;
      if ( value[0] == 123 )
      {
        if ( _V_stricmp(s1: key, s2: "wheel") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "suspension") != 0 )
            this->SkipBlock(this);
          else
            CVPhysicsParse::ParseVehicleSuspension(this, suspension: &v2->suspension);
        }
        else
        {
          CVPhysicsParse::ParseVehicleWheel(this, wheel: &v2->wheels);
        }
      }
      else if ( _V_stricmp(s1: key, s2: "offset") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "wheeloffset") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "torquefactor") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "brakefactor") == 0 )
              v2->brakeFactor = atof(nptr: value);
          }
          else
          {
            v2->torqueFactor = atof(nptr: value);
          }
        }
        else
        {
          sscanf(string: value, format: "%f %f %f", &v9, &v12, &v10);
          v2->wheelOffset.x = v9;
          v2->wheelOffset.y = v12;
          v2->wheelOffset.z = v10;
        }
      }
      else
      {
        sscanf(string: value, format: "%f %f %f", &axle, &v11, &v8);
        LODWORD(v2->offset.x) = axle;
        v2->offset.y = v11;
        v2->offset.z = v8;
      }
    }
    while ( this->m_pText != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032D90
// Name: public: virtual void CVPhysicsParse::ParseVehicle(struct vehicleparams_t __near *,class IVPhysicsKeyHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsParse::ParseVehicle(
        CVPhysicsParse *this,
        vehicleparams_t *pVehicle,
        IVPhysicsKeyHandler *unknownKeyHandler)
{
  const char *v4; // eax
  bool v5; // zf
  char value[1024]; // [esp+8h] [ebp-800h] BYREF
  char key[1024]; // [esp+408h] [ebp-400h] BYREF

  key[0] = 0;
  if ( unknownKeyHandler != nullptr )
    unknownKeyHandler->SetDefaults(this: unknownKeyHandler, a2: (void *)pVehicle);
  else
    memset(dst: (unsigned __int8 *)pVehicle, value: 0, count: sizeof(vehicleparams_t));
  if ( this->m_pText != nullptr )
  {
    while ( 1 )
    {
      v4 = ParseKeyvalue(pBuffer: this->m_pText, key, value);
      v5 = key[0] == 125;
      this->m_pText = v4;
      if ( v5 )
        break;
      if ( value[0] == 123 )
      {
        if ( _V_stricmp(s1: key, s2: "axle") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "body") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "engine") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "steering") != 0 )
                this->SkipBlock(this);
              else
                CVPhysicsParse::ParseVehicleSteering(this, steering: &pVehicle->steering);
            }
            else
            {
              CVPhysicsParse::ParseVehicleEngine(this, engine: &pVehicle->engine);
            }
          }
          else
          {
            CVPhysicsParse::ParseVehicleBody(this, body: &pVehicle->body);
          }
        }
        else
        {
          CVPhysicsParse::ParseVehicleAxle(this, axle: &pVehicle->axles[pVehicle->axleCount]);
          ++pVehicle->axleCount;
        }
      }
      else if ( _V_stricmp(s1: key, s2: "wheelsperaxle") == 0 )
      {
        pVehicle->wheelsPerAxle = atoi(nptr: value);
      }
      if ( this->m_pText == nullptr )
        return;
    }
    CVPhysicsParse::NextBlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032F00
// Name: class IVPhysicsKeyParser __near * CreateVPhysicsKeyParser(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVPhysicsPackedParser *__cdecl CreateVPhysicsKeyParser(char *pKeyData, bool bIsPacked)
{
  CVPhysicsPackedParser *v2; // eax
  CVPhysicsParse *v4; // eax
  CVPhysicsParse *v5; // esi

  if ( bIsPacked )
  {
    v2 = (CVPhysicsPackedParser *)p_malloc(size: 0x1Cu);
    if ( v2 != nullptr )
      return CVPhysicsPackedParser::CVPhysicsPackedParser(this: v2, pKeyData);
    else
      return nullptr;
  }
  else
  {
    v4 = (CVPhysicsParse *)p_malloc(size: 0x408u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v4->__vftable = (CVPhysicsParse_vtbl *)&CVPhysicsParse::`vftable';
      v4->m_pText = pKeyData;
      CVPhysicsParse::NextBlock(this: v4);
      return (CVPhysicsPackedParser *)v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032F60
// Name: public: int CStringTable::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStringTable::AddString(CStringTable *this, const char *pString)
{
  int v3; // edi
  int v4; // eax
  int m_Size; // ebx
  int v6; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v9; // eax
  unsigned __int16 *v10; // ebx
  int v11; // ecx
  int v12; // eax
  char *v13; // edx
  int v14; // eax
  char *v15; // ebx
  int v17; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( this->stringOffset.m_Size <= 0 )
  {
LABEL_4:
    v4 = _V_strlen(str: pString);
    m_Size = this->stringOffset.m_Size;
    v6 = v4 + 1;
    i = this->stringData.m_Size;
    m_nAllocationCount = this->stringOffset.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlSymbol,int>::Grow((CUtlMemory<CUtlSymbol,int> *)this, num: m_Size - m_nAllocationCount + 1);
    ++this->stringOffset.m_Size;
    m_pMemory = this->stringOffset.m_Memory.m_pMemory;
    v9 = this->stringOffset.m_Size - m_Size - 1;
    this->stringOffset.m_pElements = this->stringOffset.m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v9);
    v10 = &this->stringOffset.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = i;
    v11 = this->stringData.m_Size;
    v17 = v11;
    if ( v6 != 0 )
    {
      v12 = this->stringData.m_Memory.m_nAllocationCount;
      if ( v11 + v6 > v12 )
      {
        CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->stringData, num: v6 + v11 - v12);
        v11 = v17;
      }
      this->stringData.m_Size += v6;
      v13 = this->stringData.m_Memory.m_pMemory;
      v14 = this->stringData.m_Size - v11 - v6;
      this->stringData.m_pElements = v13;
      if ( v14 > 0 && v6 > 0 )
        _V_memmove(dest: &v13[v11 + v6], src: &v13[v11], count: v14);
    }
    v15 = &this->stringData.m_Memory.m_pMemory[i];
    for ( ia = 0; ia < v6; ++ia )
      *v15++ = tolower(c: pString[ia]);
    return this->stringOffset.m_Size - 1;
  }
  else
  {
    while ( _V_stricmp(s1: &this->stringData.m_Memory.m_pMemory[this->stringOffset.m_Memory.m_pMemory[v3]], s2: pString) != 0 )
    {
      if ( ++v3 >= this->stringOffset.m_Size )
        goto LABEL_4;
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100330A0
// Name: char const __near * PackVCollideText(char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl PackVCollideText(const char *pTextIn, int textSize, int *pSizeOut)
{
  int v4; // esi
  int m_Size; // edi
  int v6; // ebx
  unsigned __int16 v7; // dx
  int v8; // ebx
  kventry_t *m_pMemory; // ecx
  int v10; // eax
  kventry_t *v11; // ebx
  unsigned __int16 v12; // di
  unsigned __int16 v13; // cx
  int v14; // eax
  int v15; // esi
  kventry_t *v16; // edi
  int v17; // eax
  kventry_t *v18; // eax
  bool v19; // zf
  unsigned int v20; // eax
  int v21; // edi
  int v22; // ebx
  struct parsefield_t **v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // edi
  int v27; // eax
  unsigned int *v28; // ebx
  int v29; // esi
  int v30; // edi
  unsigned int *v31; // eax
  int v32; // esi
  unsigned int *v33; // esi
  unsigned __int16 v34; // ax
  int v35; // ebx
  kventry_t *v36; // ecx
  int v37; // eax
  int v38; // ecx
  int v39; // edi
  unsigned int v40; // edi
  _WORD *v41; // eax
  kventry_t *v42; // ecx
  _WORD *v43; // esi
  int v44; // eax
  char *v45; // ebx
  bool v46; // sf
  unsigned int *v48; // [esp-30h] [ebp-8F8h]
  int v49; // [esp-2Ch] [ebp-8F4h]
  char *v50; // [esp-1Ch] [ebp-8E4h]
  unsigned __int16 *v51; // [esp-18h] [ebp-8E0h]
  char value[1024]; // [esp+Ch] [ebp-8BCh] BYREF
  char key[1024]; // [esp+40Ch] [ebp-4BCh] BYREF
  int blockIndex[16]; // [esp+80Ch] [ebp-BCh]
  unsigned int storage[4]; // [esp+84Ch] [ebp-7Ch] BYREF
  CStringTable table; // [esp+85Ch] [ebp-6Ch] BYREF
  int index; // [esp+884h] [ebp-44h]
  int storageSize; // [esp+888h] [ebp-40h]
  int k; // [esp+88Ch] [ebp-3Ch]
  int block; // [esp+890h] [ebp-38h]
  const char *heapSize; // [esp+894h] [ebp-34h]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > heap; // [esp+898h] [ebp-30h] BYREF
  CUtlVector<kventry_t,CUtlMemory<kventry_t,int> > list; // [esp+8ACh] [ebp-1Ch] BYREF
  kventry_t entry; // [esp+8C0h] [ebp-8h]
  int subBlock; // [esp+8D0h] [ebp+8h]
  unsigned __int16 subBlocka; // [esp+8D0h] [ebp+8h]

  v4 = 0;
  m_Size = 0;
  v6 = 0;
  key[0] = 0;
  subBlock = 0;
  memset(&list, 0, sizeof(list));
  memset(&table, 0, sizeof(table));
  memset(&heap, 0, sizeof(heap));
  blockIndex[0] = 0xFFFF;
  if ( pTextIn != nullptr )
  {
    while ( 1 )
    {
      heapSize = ParseKeyvalue(pBuffer: pTextIn, key, value);
      if ( key[0] != 125 )
        break;
      v7 = blockIndex[subBlock];
      entry.type = 2;
      entry.blockIndex = v7;
      *(_DWORD *)&entry.key = 0;
      v8 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>::Grow(
          this: (CUtlMemory<CUtlMultiList<void *,unsigned short>::ListElem_t,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      v10 = ++m_Size - v8 - 1;
      list.m_Size = m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( v10 > 0 )
      {
        _V_memmove(dest: &list.m_Memory.m_pMemory[v8 + 1], src: &list.m_Memory.m_pMemory[v8], count: 8 * v10);
        m_pMemory = list.m_Memory.m_pMemory;
      }
      v11 = &m_pMemory[v8];
      if ( v11 != nullptr )
        *v11 = entry;
      if ( --subBlock < 0 )
      {
LABEL_70:
        v6 = table.stringOffset.m_Size;
        goto LABEL_71;
      }
LABEL_69:
      if ( heapSize == nullptr )
        goto LABEL_70;
      pTextIn = heapSize;
    }
    if ( value[0] == 123 )
    {
      ++subBlock;
      entry.type = 1;
      v12 = 0;
      while ( _V_stricmp(s1: key, s2: *(const char **)((char *)&g_ParseBlocks[0].pBlockName + v4)) != 0 )
      {
        v4 += 12;
        ++v12;
        if ( (unsigned int)v4 >= 0x48 )
        {
          v13 = -1;
          goto LABEL_18;
        }
      }
      v13 = v12;
LABEL_18:
      blockIndex[subBlock] = v13;
      *(_DWORD *)&entry.key = 0;
      entry.blockIndex = v13;
      if ( v13 == 0xFFFF )
        entry.key = CStringTable::AddString(this: &table, pString: key);
      v14 = list.m_Size;
      v15 = list.m_Size;
      if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>::Grow(
          this: (CUtlMemory<CUtlMultiList<void *,unsigned short>::ListElem_t,int> *)&list,
          num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
        v14 = list.m_Size;
      }
      v16 = list.m_Memory.m_pMemory;
      list.m_Size = v14 + 1;
      v17 = v14 - v15;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( v17 > 0 )
        _V_memmove(dest: &list.m_Memory.m_pMemory[v15 + 1], src: &list.m_Memory.m_pMemory[v15], count: 8 * v17);
      v18 = &v16[v15];
      m_Size = list.m_Size;
      v4 = 0;
      v19 = v18 == nullptr;
      goto LABEL_67;
    }
    if ( key[0] == 0 )
      goto LABEL_69;
    entry.type = 0;
    v20 = blockIndex[subBlock];
    block = v20;
    entry.blockIndex = -1;
    if ( v20 >= 6 )
      goto LABEL_60;
    v21 = 3 * v20;
    if ( dword_100F6EF0[3 * v20] <= 0 )
    {
LABEL_59:
      m_Size = list.m_Size;
      v4 = 0;
LABEL_60:
      entry.key = CStringTable::AddString(this: &table, pString: key);
      entry.value = CStringTable::AddString(this: &table, pString: value);
LABEL_62:
      v35 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>::Grow(
          this: (CUtlMemory<CUtlMultiList<void *,unsigned short>::ListElem_t,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      v36 = list.m_Memory.m_pMemory;
      v37 = ++m_Size - v35 - 1;
      list.m_Size = m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( v37 > 0 )
      {
        _V_memmove(dest: &list.m_Memory.m_pMemory[v35 + 1], src: &list.m_Memory.m_pMemory[v35], count: 8 * v37);
        v36 = list.m_Memory.m_pMemory;
      }
      v18 = &v36[v35];
      v19 = v18 == nullptr;
LABEL_67:
      if ( !v19 )
      {
        v38 = *(_DWORD *)&entry.type;
        *(_DWORD *)&v18->key = *(_DWORD *)&entry.key;
        *(_DWORD *)&v18->type = v38;
      }
      goto LABEL_69;
    }
    v22 = 0;
    while ( _V_stricmp(s1: key, s2: (const char *)(&off_100F6EEC)[v21][v22]) != 0 )
    {
      ++v4;
      v22 += 6;
      if ( v4 >= dword_100F6EF0[v21] )
        goto LABEL_59;
    }
    v23 = (&off_100F6EEC)[v21];
    entry.blockIndex = block;
    entry.key = v4;
    v24 = StoreField(field: (parsefield_t *)&v23[6 * v4], pValue: value, pOut: storage);
    v25 = v24;
    storageSize = v24;
    if ( v24 <= 0 )
    {
      v34 = CStringTable::AddString(this: &table, pString: value);
LABEL_58:
      entry.value = v34;
      if ( (_WORD)block != 0xFFFF )
      {
        m_Size = list.m_Size;
        v4 = 0;
        goto LABEL_62;
      }
      goto LABEL_59;
    }
    v26 = heap.m_Size;
    if ( v24 == 1 && (v27 = 0, heap.m_Size > 0) )
    {
      while ( 1 )
      {
        v28 = heap.m_Memory.m_pMemory;
        if ( heap.m_Memory.m_pMemory[v27] == storage[0] )
          break;
        if ( ++v27 >= heap.m_Size )
          goto LABEL_42;
      }
      index = v27;
      if ( v27 >= 0 )
        goto LABEL_56;
    }
    else
    {
      v28 = heap.m_Memory.m_pMemory;
    }
LABEL_42:
    v29 = heap.m_Size;
    if ( heap.m_Size + 1 > heap.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&heap,
        num: heap.m_Size - heap.m_Memory.m_nAllocationCount + 1);
      v26 = heap.m_Size;
      v28 = heap.m_Memory.m_pMemory;
      v25 = storageSize;
    }
    v30 = v26 + 1;
    heap.m_Size = v30;
    heap.m_pElements = v28;
    if ( v30 - v29 - 1 > 0 )
    {
      _V_memmove(dest: &v28[v29 + 1], src: &v28[v29], count: 4 * (v30 - v29 - 1));
      v25 = storageSize;
    }
    v31 = &v28[v29];
    if ( v31 != nullptr )
      *v31 = storage[0];
    index = v29;
    k = 1;
    if ( v25 > 1 )
    {
      do
      {
        v32 = v30;
        if ( v30 + 1 > heap.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&heap,
            num: v30 - heap.m_Memory.m_nAllocationCount + 1);
          v30 = heap.m_Size;
          v28 = heap.m_Memory.m_pMemory;
        }
        heap.m_Size = ++v30;
        heap.m_pElements = v28;
        if ( v30 - v32 - 1 > 0 )
          _V_memmove(dest: &v28[v32 + 1], src: &v28[v32], count: 4 * (v30 - v32 - 1));
        v33 = &v28[v32];
        if ( v33 != nullptr )
          *v33 = storage[k];
        ++k;
      }
      while ( k < storageSize );
    }
LABEL_56:
    v34 = 4 * index;
    goto LABEL_58;
  }
LABEL_71:
  v39 = table.stringData.m_Size + 2 * (v6 + 4 * m_Size) + 12;
  if ( (v39 & 3) != 0 )
    v39 += 4 - (v39 & 3);
  subBlocka = v39;
  heapSize = (const char *)(unsigned __int16)(4 * LOWORD(heap.m_Size));
  v40 = (unsigned __int16)heapSize + v39;
  block = (unsigned __int16)heapSize;
  v41 = p_malloc(size: v40);
  v42 = list.m_Memory.m_pMemory;
  v43 = v41;
  v44 = list.m_Size;
  v43[2] = list.m_Size;
  *(_DWORD *)v43 = 256;
  _V_memcpy(dest: v43 + 6, src: v42, count: 8 * v44);
  v51 = table.stringOffset.m_Memory.m_pMemory;
  v50 = (char *)&v43[4 * (unsigned __int16)v43[2] + 6];
  v43[3] = v6;
  _V_memcpy(dest: v50, src: v51, count: 2 * v6);
  v45 = table.stringData.m_Memory.m_pMemory;
  _V_memcpy(
    dest: &v43[4 * (unsigned __int16)v43[2] + 6 + (unsigned __int16)v43[3]],
    src: table.stringData.m_Memory.m_pMemory,
    count: table.stringData.m_Size);
  v49 = block;
  v43[4] = (_WORD)heapSize;
  v48 = heap.m_Memory.m_pMemory;
  v43[5] = subBlocka;
  _V_memcpy(dest: (char *)v43 + subBlocka, src: v48, count: v49);
  v46 = heap.m_Memory.m_nGrowSize < 0;
  *pSizeOut = v40;
  if ( !v46 && heap.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: heap.m_Memory.m_pMemory);
  if ( table.stringData.m_Memory.m_nGrowSize >= 0 && v45 != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v45);
    table.stringData.m_Memory.m_pMemory = nullptr;
  }
  if ( table.stringOffset.m_Memory.m_nGrowSize >= 0 && table.stringOffset.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: table.stringOffset.m_Memory.m_pMemory);
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
  return (const char *)v43;
}
