// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_lcd.cpp
// Functions: 48
// ============================================================

#include "game\client\hud_lcd.h"

//------------------------------------------------------------------------------
// Address: 0x10104850
// Name: public: virtual void CLCDItemIcon::Create(class IG15 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCDItemIcon::Create(CLCDItemIcon *this, IG15 *lcd)
{
  void *v4; // eax
  int x; // ecx
  int y; // [esp-4h] [ebp-Ch]

  v4 = lcd->AddIcon(this: lcd, a2: this->m_icon, a3: this->w, a4: this->h);
  y = this->y;
  x = this->x;
  this->m_Handle = v4;
  lcd->SetOrigin(this: lcd, a2: v4, a3: x, a4: y);
  lcd->SetVisible(this: lcd, a2: this->m_Handle, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101048A0
// Name: public: virtual void CLCDItemText::Create(class IG15 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCDItemText::Create(CLCDItemText *this, IG15 *lcd)
{
  void *v4; // eax
  int x; // ecx
  IG15_vtbl *v6; // ebx
  const char *v7; // eax
  int y; // [esp-4h] [ebp-10h]

  v4 = lcd->AddText(this: lcd, a2: 1, a3: this->m_iSize, a4: this->m_iAlign, a5: this->w);
  y = this->y;
  x = this->x;
  this->m_Handle = v4;
  lcd->SetOrigin(this: lcd, a2: v4, a3: x, a4: y);
  v6 = lcd->__vftable;
  v7 = CUtlString::operator char const *(this: &this->m_OriginalText);
  v6->SetText(this: lcd, a2: this->m_Handle, a3: v7);
  lcd->SetVisible(this: lcd, a2: this->m_Handle, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10104910
// Name: FindByName
// Source: json
//------------------------------------------------------------------------------
typedescription_t *__usercall FindByName@<eax>(datamap_t *pMap@<eax>, const char *fn)
{
  datamap_t *v2; // edi
  int v3; // ebx
  const char *fieldName; // eax
  typedescription_t *v5; // esi
  int i; // [esp+Ch] [ebp-4h]

  v2 = pMap;
  if ( pMap == nullptr )
    return nullptr;
  while ( 1 )
  {
    i = 0;
    if ( v2->dataNumFields > 0 )
      break;
LABEL_7:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v3 = 0;
  while ( 1 )
  {
    fieldName = v2->dataDesc[v3].fieldName;
    v5 = &v2->dataDesc[v3];
    if ( fieldName != nullptr && _V_stricmp(s1: fieldName, s2: fn) == 0 )
      return v5;
    ++v3;
    if ( ++i >= v2->dataNumFields )
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104980
// Name: private: void CDescribeData::Describe(struct datamap_t const __near *,struct typedescription_t const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDescribeData::Describe(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        char *fmt,
        ...)
{
  const char *fieldName; // esi
  char pDest[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list params; // [esp+101Ch] [ebp+18h] BYREF

  va_start(params, fmt);
  fieldName = pField->fieldName;
  if ( fieldName == nullptr )
    fieldName = "null";
  V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: fmt, params);
  _Msg(a1: "%s::%s%s", dmap->dataClassName, fieldName, pDest);
}

//------------------------------------------------------------------------------
// Address: 0x101049E0
// Name: public: void CDescribeData::DescribeShort(struct datamap_t const __near *,struct typedescription_t const __near *,short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DescribeShort(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        const __int16 *invalue,
        int count)
{
  int i; // esi
  int v7; // [esp-8h] [ebp-10h]

  for ( i = 0; i < count; ++i )
  {
    v7 = invalue[i];
    if ( count == 1 )
      CDescribeData::Describe(this, dmap, pField, fmt: " short (%i)\n", v7);
    else
      CDescribeData::Describe(this, dmap, pField, fmt: "[%i] short (%i)\n", i, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104A40
// Name: public: void CDescribeData::DescribeInt(struct datamap_t const __near *,struct typedescription_t const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DescribeInt(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        const int *invalue,
        int count)
{
  int i; // esi
  int v7; // [esp-8h] [ebp-10h]

  for ( i = 0; i < count; ++i )
  {
    v7 = invalue[i];
    if ( count == 1 )
      CDescribeData::Describe(this, dmap, pField, fmt: " integer (%i)\n", v7);
    else
      CDescribeData::Describe(this, dmap, pField, fmt: "[%i] integer (%i)\n", i, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104AA0
// Name: public: void CDescribeData::DescribeBool(struct datamap_t const __near *,struct typedescription_t const __near *,bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DescribeBool(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        const bool *invalue,
        int count)
{
  int v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  CDescribeData *v8; // [esp+4h] [ebp-4h]

  v5 = 0;
  v8 = this;
  if ( count > 0 )
  {
    while ( 1 )
    {
      if ( count == 1 )
      {
        v6 = "true";
        if ( !invalue[v5] )
          v6 = "false";
        CDescribeData::Describe(this, dmap, pField, fmt: " bool (%s)\n", v6);
      }
      else
      {
        v7 = "true";
        if ( !invalue[v5] )
          v7 = "false";
        CDescribeData::Describe(this, dmap, pField, fmt: "[%i] bool (%s)\n", v5, v7);
      }
      if ( ++v5 >= count )
        break;
      this = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104B30
// Name: public: void CDescribeData::DescribeFloat(struct datamap_t const __near *,struct typedescription_t const __near *,float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DescribeFloat(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        const float *invalue,
        int count)
{
  int i; // esi
  double v7; // [esp+0h] [ebp-14h]

  for ( i = 0; i < count; ++i )
  {
    v7 = invalue[i];
    if ( count == 1 )
      CDescribeData::Describe(this, dmap, pField, fmt: " float (%f)\n", v7);
    else
      CDescribeData::Describe(this, dmap, pField, fmt: "[%i] float (%f)\n", i, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104BA0
// Name: public: void CDescribeData::DescribeString(struct datamap_t const __near *,struct typedescription_t const __near *,char const __near * const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DescribeString(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        const char *const *instring,
        int count)
{
  int i; // esi
  const char *v7; // eax
  const char *v8; // eax

  for ( i = 0; i < count; ++i )
  {
    if ( count == 1 )
    {
      v7 = instring[i];
      if ( v7 == nullptr )
        v7 = prType;
      CDescribeData::Describe(this, dmap, pField, fmt: " string (%s)\n", v7);
    }
    else
    {
      v8 = instring[i];
      if ( v8 == nullptr )
        v8 = prType;
      CDescribeData::Describe(this, dmap, pField, fmt: "[%i] string (%s)\n", i, v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104C10
// Name: public: void CDescribeData::DescribeColor(struct datamap_t const __near *,struct typedescription_t const __near *,class Color const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DescribeColor(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        const Color *invalue,
        int count)
{
  int v5; // edi
  unsigned __int8 *v6; // esi
  CDescribeData *v7; // [esp+4h] [ebp-4h]

  v5 = 0;
  v7 = this;
  if ( count > 0 )
  {
    v6 = (unsigned __int8 *)invalue + 2;
    while ( 1 )
    {
      if ( count == 1 )
        CDescribeData::Describe(this, dmap, pField, fmt: " color (%i %i %i %i)\n", *(v6 - 2), *(v6 - 1), *v6, v6[1]);
      else
        CDescribeData::Describe(
          this,
          dmap,
          pField,
          fmt: "[%i] color (%i %i %i %i)\n",
          v5,
          *(v6 - 2),
          *(v6 - 1),
          *v6,
          v6[1]);
      ++v5;
      v6 += 4;
      if ( v5 >= count )
        break;
      this = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104CA0
// Name: public: void CDescribeData::DescribeVector(struct datamap_t const __near *,struct typedescription_t const __near *,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DescribeVector(
        CDescribeData *this,
        const datamap_t *dmap,
        const typedescription_t *pField,
        const Vector *inValue,
        int count)
{
  int v5; // edi
  float *p_y; // esi
  double v7; // [esp+0h] [ebp-28h]
  double v8; // [esp+8h] [ebp-20h]
  double v9; // [esp+10h] [ebp-18h]
  CDescribeData *v10; // [esp+24h] [ebp-4h]

  v5 = 0;
  v10 = this;
  if ( count > 0 )
  {
    p_y = &inValue->y;
    while ( 1 )
    {
      v9 = p_y[1];
      v8 = *p_y;
      v7 = *(p_y - 1);
      if ( count == 1 )
        CDescribeData::Describe(this, dmap, pField, fmt: " vector (%f %f %f)\n", v7, v8, v9);
      else
        CDescribeData::Describe(this, dmap, pField, fmt: "[%i] vector (%f %f %f)\n", v5, v7, v8, v9);
      ++v5;
      p_y += 3;
      if ( v5 >= count )
        break;
      this = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104D30
// Name: private: bool CLCD::ExtractArrayIndex(char __near *,unsigned int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLCD::ExtractArrayIndex(CLCD *this, char *str, int bufsize, int *index)
{
  int v4; // eax
  int v5; // esi
  int v7; // eax
  int v8; // edi
  char v9[2048]; // [esp+8h] [ebp-1020h] BYREF
  char pDest[2048]; // [esp+808h] [ebp-820h] BYREF
  char stra[32]; // [esp+1008h] [ebp-20h] BYREF

  *index = 0;
  V_strncpy(pDest, pSrc: str, maxLen: 2048);
  _V_strstr(s1: pDest, search: "[");
  v5 = v4;
  if ( v4 == 0 )
    return 0;
  _V_strstr(s1: pDest, search: "]");
  v8 = v7;
  if ( v7 == 0 )
    return 0;
  V_strncpy(pDest: stra, pSrc: (char *)(v5 + 1), maxLen: v7 - v5);
  *index = V_atoi(str: stra);
  V_strncpy(pDest: v9, pSrc: pDest, maxLen: v5 - (_DWORD)pDest + 1);
  V_strncat(pDest: v9, pSrc: (const char *)(v8 + 1), destBufferSize: 0x800u, max_chars_to_copy: -1);
  V_strncpy(pDest: str, pSrc: v9, maxLen: bufsize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10104E20
// Name: private: void CLCD::LookupToken(char const __near *,class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::LookupToken(CLCD *this, int in, CUtlString *value)
{
  C_BasePlayer *LocalPlayer; // ebx
  char *v4; // esi
  C_PlayerResource *v5; // edi
  bool v6; // zf
  char v7; // al
  char *v8; // ecx
  char *v9; // ecx
  datamap_t *v10; // esi
  int v11; // eax
  typedescription_t *v12; // eax
  int fieldOffset; // ecx
  char *v14; // ecx
  const char **v15; // eax
  float v16; // eax
  const char *v17; // eax
  const char *v18; // [esp+14h] [ebp-724h]
  char outbuf[1024]; // [esp+24h] [ebp-714h] BYREF
  char token[512]; // [esp+424h] [ebp-314h] BYREF
  char sz[256]; // [esp+624h] [ebp-114h] BYREF
  Vector v; // [esp+724h] [ebp-14h]
  CLCD *v23; // [esp+730h] [ebp-8h]
  char *o; // [esp+734h] [ebp-4h]

  v23 = this;
  CUtlString::operator=(this: value, src: prType);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v4 = (char *)in;
    v5 = nullptr;
    v6 = *(_BYTE *)in == 0;
    o = outbuf;
    if ( !v6 )
    {
      do
      {
        if ( *v4 == 40 )
        {
          v7 = *++v4;
          v8 = token;
          if ( v7 != 0 )
          {
            while ( v7 != 41 )
            {
              ++v4;
              *v8 = v7;
              v7 = *v4;
              ++v8;
              if ( *v4 == 0 )
                goto LABEL_10;
            }
            if ( *v4 != 0 )
              ++v4;
          }
LABEL_10:
          *v8 = 0;
          if ( _V_stricmp(s1: token, s2: "localplayer") != 0 )
          {
            if ( _V_stricmp(s1: token, s2: "localteam") != 0 )
            {
              if ( _V_stricmp(s1: token, s2: "localplayerweapon") != 0 )
              {
                if ( _V_stricmp(s1: token, s2: "playerresource") == 0 )
                  v5 = g_PR;
              }
              else
              {
                v5 = (C_PlayerResource *)LocalPlayer->GetActiveWeapon(this: LocalPlayer);
              }
            }
            else
            {
              v5 = (C_PlayerResource *)LocalPlayer->GetTeam(this: LocalPlayer);
            }
          }
          else
          {
            v5 = (C_PlayerResource *)LocalPlayer;
          }
        }
        else
        {
          v9 = o;
          *o = *v4;
          o = v9 + 1;
          ++v4;
        }
      }
      while ( *v4 != 0 );
    }
    *o = 0;
    if ( v5 != nullptr )
    {
      in = 0;
      CLCD::ExtractArrayIndex(this: v23, str: outbuf, bufsize: 1024, index: &in);
      v10 = v5->GetPredDescMap(this: v5);
      _V_strstr(s1: outbuf, search: ".");
      if ( v11 == 0 )
      {
        v12 = FindByName(pMap: v10, fn: outbuf);
        if ( v12 != nullptr && v12->flags >= 0 )
        {
          fieldOffset = v12->fieldOffset;
          sz[0] = 0;
          v14 = (char *)v5 + fieldOffset;
          switch ( v12->fieldType )
          {
            case FIELD_FLOAT:
              V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%.2f", *(float *)&v14[4 * in]);
              break;
            case FIELD_STRING:
              v15 = (const char **)&v14[4 * in];
              if ( v15 != nullptr )
                v18 = *v15;
              else
                v18 = prType;
              goto LABEL_37;
            case FIELD_VECTOR:
              v16 = *(float *)&v14[12 * in + 8];
              *(_QWORD *)&v.x = *(_QWORD *)&v14[12 * in];
              v.z = v16;
              V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%.2f %.2f %.2f", v.x, v.y, v16);
              break;
            case FIELD_INTEGER:
              V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%i", *(_DWORD *)&v14[4 * in]);
              break;
            case FIELD_BOOLEAN:
              v17 = "true";
              if ( v14[in] == 0 )
                v17 = "false";
              V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%s", v17);
              break;
            case FIELD_SHORT:
              V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%i", *(__int16 *)&v14[2 * in]);
              break;
            case FIELD_CHARACTER:
              v18 = &v14[in];
LABEL_37:
              V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%s", v18);
              break;
            case FIELD_COLOR32:
              V_snprintf(
                pDest: sz,
                maxLen: 0x100u,
                pFormat: "%d %d %d %d",
                (unsigned __int8)*(_DWORD *)&v14[4 * in],
                BYTE1(*(_DWORD *)&v14[4 * in]),
                (unsigned __int8)BYTE2(*(_DWORD *)&v14[4 * in]),
                HIBYTE(*(_DWORD *)&v14[4 * in]));
              break;
            default:
              break;
          }
          CUtlString::operator=(this: value, src: sz);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105180
// Name: private: bool CLCD::Replace(class CUtlString __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLCD::Replace(CLCD *this, CUtlString *str, char *search, char *replace)
{
  CUtlString *v4; // ebx
  char *v5; // eax
  int v6; // eax
  char *v8; // eax
  unsigned int v9; // esi
  int v10; // eax
  char *v11; // ebx
  int v12; // esi
  char v13[4096]; // [esp+8h] [ebp-1804h] BYREF
  char pDest[2051]; // [esp+1008h] [ebp-804h] BYREF
  char v15; // [esp+180Bh] [ebp-1h]

  v4 = str;
  v15 = 0;
  v5 = (char *)CUtlString::operator char const *(this: str);
  _V_strstr(s1: v5, search);
  if ( v6 == 0 )
    return 0;
  v8 = (char *)CUtlString::operator char const *(this: str);
  V_strncpy(pDest, pSrc: v8, maxLen: 2048);
  v9 = _V_strlen(str: search);
  _V_strstr(s1: pDest, search);
  if ( v10 != 0 )
  {
    v11 = &v13[v9 + 4095];
    v15 = 1;
    do
    {
      v12 = v10 - (_DWORD)pDest + 1;
      V_strncpy(pDest: v13, pSrc: pDest, maxLen: v12);
      V_strncat(pDest: v13, pSrc: replace, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncat(pDest: v13, pSrc: &v11[v12], destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncpy(pDest, pSrc: v13, maxLen: 2048);
      _V_strstr(s1: pDest, search);
    }
    while ( v10 != 0 );
    v4 = str;
  }
  CUtlString::operator=(this: v4, src: pDest);
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x101052A0
// Name: private: void CLCD::ReduceParentheses(class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::ReduceParentheses(CLCD *this, CUtlString *str)
{
  char *v2; // eax
  char *v3; // eax
  char *v4; // esi
  int v5; // eax
  int v6; // edi
  char *v7; // eax
  char pSrc[4096]; // [esp+8h] [ebp-1800h] BYREF
  char pDest[2048]; // [esp+1008h] [ebp-800h] BYREF

  v2 = (char *)CUtlString::operator char const *(this: str);
  V_strncpy(pDest, pSrc: v2, maxLen: 2048);
  _V_strstr(s1: pDest, search: "(");
  v4 = v3;
  if ( v3 != nullptr )
  {
    do
    {
      _V_strstr(s1: v4, search: ")");
      v6 = v5;
      if ( v5 == 0 )
        break;
      V_strncpy(pDest: pSrc, pSrc: pDest, maxLen: v4 - pDest + 1);
      V_strncat(pDest: pSrc, pSrc: (const char *)(v6 + 1), destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncpy(pDest, pSrc, maxLen: 2048);
      _V_strstr(s1: pDest, search: "(");
      v4 = v7;
    }
    while ( v7 != nullptr );
  }
  CUtlString::operator=(this: str, src: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10105380
// Name: private: void CLCD::ParseReplacements(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::ParseReplacements(CLCD *this, KeyValues *kv)
{
  KeyValues *i; // esi
  const char *Name; // ebx
  const char *String; // eax

  for ( i = KeyValues::GetFirstSubKey(this: kv); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
    this->SetGlobalStat(this, a2: Name, a3: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105570
// Name: private: virtual void CSharedVarSaveDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedVarSaveDataOps::Save(
        CSharedVarSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  (**(void (__thiscall ***)(void *, ISave *))fieldInfo->pField)(a1: fieldInfo->pField, a2: pSave);
}

//------------------------------------------------------------------------------
// Address: 0x10105590
// Name: private: virtual void CSharedVarSaveDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedVarSaveDataOps::Restore(
        CSharedVarSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  (*(void (__thiscall **)(void *, IRestore *))(*(_DWORD *)fieldInfo->pField + 4))(a1: fieldInfo->pField, a2: pRestore);
}

//------------------------------------------------------------------------------
// Address: 0x101055B0
// Name: private: virtual bool CSharedVarSaveDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSharedVarSaveDataOps::IsEmpty(CSharedVarSaveDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  return (*(bool (__thiscall **)(void *))(*(_DWORD *)fieldInfo->pField + 8))(a1: fieldInfo->pField);
}

//------------------------------------------------------------------------------
// Address: 0x101055D0
// Name: private: virtual void CSharedVarSaveDataOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedVarSaveDataOps::MakeEmpty(CSharedVarSaveDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)fieldInfo->pField + 12))(a1: fieldInfo->pField);
}

//------------------------------------------------------------------------------
// Address: 0x101055F0
// Name: public: void CDescribeData::DumpDescription(struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescribeData::DumpDescription(CDescribeData *this, datamap_t *pMap)
{
  int v4; // edx
  optimized_datamap_t *m_pOptimizedDataMap; // ecx
  int v6; // eax
  optimized_datamap_t *v7; // ecx
  const typedescription_t *v8; // eax
  const Vector *v9; // ecx
  const char *v10; // [esp+0h] [ebp-18h]
  optimized_datamap_t *v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  datamap_t *pMapa; // [esp+20h] [ebp+8h]

  CPredictionCopy::PrepareDataMap(dmap: pMap);
  v4 = 0;
  v12 = 0;
  do
  {
    m_pOptimizedDataMap = pMap->m_pOptimizedDataMap;
    v6 = *(int *)((char *)&m_pOptimizedDataMap->m_Info[0].m_Flat.m_Flattened.m_Size + v4);
    v7 = (optimized_datamap_t *)((char *)m_pOptimizedDataMap + v4);
    v11 = v7;
    if ( v6 > 0 )
    {
      pMapa = nullptr;
      v13 = v6;
      while ( 1 )
      {
        v8 = (const typedescription_t *)((char *)pMapa
                                       + (unsigned int)v7->m_Info[0].m_Flat.m_Flattened.m_Memory.m_pMemory);
        if ( v8->flags >= 0 )
        {
          v9 = (const Vector *)&this->m_pSrc[v8->flatOffset[0]];
          switch ( v8->fieldType )
          {
            case FIELD_FLOAT:
              CDescribeData::DescribeFloat(this, dmap: pMap, pField: v8, invalue: &v9->x, count: v8->fieldSize);
              break;
            case FIELD_STRING:
              CDescribeData::DescribeString(
                this,
                dmap: pMap,
                pField: v8,
                instring: (const char *const *)v9,
                count: v8->fieldSize);
              break;
            case FIELD_VECTOR:
              CDescribeData::DescribeVector(this, dmap: pMap, pField: v8, inValue: v9, count: v8->fieldSize);
              break;
            case FIELD_INTEGER:
              CDescribeData::DescribeInt(this, dmap: pMap, pField: v8, invalue: (const int *)v9, count: v8->fieldSize);
              break;
            case FIELD_BOOLEAN:
              CDescribeData::DescribeBool(this, dmap: pMap, pField: v8, invalue: (const bool *)v9, count: v8->fieldSize);
              break;
            case FIELD_SHORT:
              CDescribeData::DescribeShort(
                this,
                dmap: pMap,
                pField: v8,
                invalue: (const __int16 *)v9,
                count: v8->fieldSize);
              break;
            case FIELD_CHARACTER:
              if ( v9 == nullptr )
                v9 = (const Vector *)prType;
              CDescribeData::Describe(this, dmap: pMap, pField: v8, fmt: "%s\n", (const char *)v9);
              break;
            case FIELD_COLOR32:
              CDescribeData::DescribeColor(
                this,
                dmap: pMap,
                pField: v8,
                invalue: (const Color *)v9,
                count: v8->fieldSize);
              break;
            case FIELD_EMBEDDED:
              _Error(this: (ISceneTokenProcessor *)&stru_1047D38C, a2: v10);
              break;
            default:
              break;
          }
        }
        pMapa = (datamap_t *)((char *)pMapa + 60);
        if ( --v13 == 0 )
          break;
        v7 = v11;
      }
      v4 = v12;
    }
    v4 += 48;
    v12 = v4;
  }
  while ( v4 < 96 );
}

//------------------------------------------------------------------------------
// Address: 0x10105740
// Name: private: void CLCD::UpdateChat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::UpdateChat(CLCD *this)
{
  int v2; // edi
  int v3; // ebx
  const char *v4; // eax
  char name[32]; // [esp+8h] [ebp-24h] BYREF
  unsigned int v6; // [esp+28h] [ebp-4h]

  v2 = 0;
  if ( this->m_nMaxChatHistory > 0 )
  {
    v6 = 0;
    do
    {
      v3 = v2 + 1;
      V_snprintf(pDest: name, maxLen: 0x20u, pFormat: "chat_%d", v2 + 1);
      if ( v2 >= this->m_ChatHistory.m_Size )
        v4 = " ";
      else
        v4 = CUtlString::operator char const *(this: &this->m_ChatHistory.m_Memory.m_pMemory[v6 / 0x10]);
      this->SetGlobalStat(this, a2: name, a3: v4);
      v6 += 16;
      ++v2;
    }
    while ( v3 < this->m_nMaxChatHistory );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101057B0
// Name: cl_dumpplayer
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_dumpplayer(const CCommand *args)
{
  int v1; // eax
  const unsigned __int8 *v2; // esi
  unsigned __int8 v3; // al
  int (__thiscall *v4)(const unsigned __int8 *); // eax
  datamap_t *v5; // eax
  Vector absMins; // [esp+40h] [ebp-20h] BYREF
  Vector absMaxs; // [esp+4Ch] [ebp-14h] BYREF
  CDescribeData helper; // [esp+58h] [ebp-8h] BYREF

  if ( args->m_nArgc == 2 )
  {
    v1 = V_atoi(str: args->m_ppArgv[1]);
    v2 = (const unsigned __int8 *)C_BaseEntity::Instance(iEnt: v1);
    if ( v2 != nullptr
      && (*(unsigned __int8 (__thiscall **)(const unsigned __int8 *))(*(_DWORD *)v2 + 584))(a1: v2) != 0 )
    {
      (*(void (__thiscall **)(const unsigned __int8 *, Vector *, Vector *))(*((_DWORD *)v2 + 1) + 72))(
        a1: v2 + 4,
        a2: &absMins,
        a3: &absMaxs);
      _Msg(a1: "Effects: %x\n", *((_DWORD *)v2 + 58));
      v3 = (*(int (__thiscall **)(const unsigned __int8 *))(*((_DWORD *)v2 + 2) + 36))(a1: v2 + 8);
      _Msg(a1: "Dormant: %d\n", v3);
      _Msg(
        a1: "Worldspace Render Bounds: [%.2f %.2f %.2f] -> [%.2f %.2f %.2f]\n",
        absMins.x,
        absMins.y,
        absMins.z,
        absMaxs.x,
        absMaxs.y,
        absMaxs.z);
      v4 = *(int (__thiscall **)(const unsigned __int8 *))(*(_DWORD *)v2 + 68);
      helper.m_pSrc = v2;
      helper.m_nSrcOffsetIndex = 0;
      v5 = (datamap_t *)v4(a1: v2);
      CDescribeData::DumpDescription(this: &helper, pMap: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106560
// Name: private: void CLCD::BuildUpdatedText(char const __near *,class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::BuildUpdatedText(CLCD *this, const char *in, CUtlString *out)
{
  const char *v3; // esi
  char *v4; // edi
  char v5; // al
  char *v6; // ecx
  const char *v7; // eax
  char v8; // cl
  int v9; // eax
  char outbuf[1024]; // [esp+Ch] [ebp-614h] BYREF
  char token[512]; // [esp+40Ch] [ebp-214h] BYREF
  CLCD *v12; // [esp+60Ch] [ebp-14h]
  CUtlString value; // [esp+610h] [ebp-10h] BYREF

  v3 = in;
  v12 = this;
  v4 = outbuf;
  while ( *v3 != 0 )
  {
    if ( *v3 == 37 )
    {
      v5 = *++v3;
      v6 = token;
      if ( v5 != 0 )
      {
        while ( v5 != 37 )
        {
          ++v3;
          *v6 = v5;
          v5 = *v3;
          ++v6;
          if ( *v3 == 0 )
            goto LABEL_9;
        }
        if ( *v3 != 0 )
          ++v3;
      }
LABEL_9:
      *v6 = 0;
      CUtlString::CUtlString(this: &value);
      CLCD::LookupToken(this: v12, in: (int)token, &value);
      v7 = CUtlString::operator char const *(this: &value);
      v8 = *v7;
      if ( *v7 != 0 )
      {
        v9 = v7 - v4;
        do
        {
          *v4 = v8;
          v8 = (v4++)[v9 + 1];
        }
        while ( v8 != 0 );
      }
      value.m_Storage.m_nActualLength = 0;
      if ( value.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( value.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Storage.m_Memory.m_pMemory);
          value.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        value.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    else
    {
      *v4++ = *v3++;
    }
  }
  *v4 = 0;
  CUtlString::operator=(this: out, src: outbuf);
}

//------------------------------------------------------------------------------
// Address: 0x10107590
// Name: public: virtual void CLCDItem::Wipe(class IG15 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCDItem::Wipe(CLCDItem *this, IG15 *lcd)
{
  int i; // edi
  CLCDItem *v4; // ecx
  CLCDItem *v5; // ecx
  CLCDItem *v6; // ecx
  bool v7; // sf
  CLCDItem **m_pMemory; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    v4 = this->m_Children.m_Memory.m_pMemory[i];
    if ( v4->m_Handle != nullptr )
      lcd->RemoveAndDestroyObject(this: lcd, a2: v4->m_Handle);
    v5 = this->m_Children.m_Memory.m_pMemory[i];
    v5->Wipe(this: v5, a2: lcd);
    v6 = this->m_Children.m_Memory.m_pMemory[i];
    if ( v6 != nullptr )
      ((void (__thiscall *)(CLCDItem *, int))v6->dtr_CLCDItem)(a1: v6, a2: 1);
  }
  v7 = this->m_Children.m_Memory.m_nGrowSize < 0;
  this->m_Children.m_Size = 0;
  if ( v7 )
  {
    this->m_Children.m_pElements = this->m_Children.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Children.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Children.m_Memory.m_pMemory);
      this->m_Children.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Children.m_Memory.m_pMemory;
    this->m_Children.m_Memory.m_nAllocationCount = 0;
    this->m_Children.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107630
// Name: public: virtual void CLCDItemAggregate::Wipe(class IG15 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCDItemAggregate::Wipe(CLCDItemAggregate *this, IG15 *lcd)
{
  int i; // edi
  CLCDItem *v4; // ecx
  CLCDItem *v5; // ecx
  bool v6; // sf
  CLCDItem **m_pMemory; // ecx

  CLCDItem::Wipe(this, lcd);
  for ( i = 0; i < this->m_Definition.m_Size; ++i )
  {
    v4 = this->m_Definition.m_Memory.m_pMemory[i];
    v4->Wipe(this: v4, a2: lcd);
    v5 = this->m_Definition.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
      ((void (__thiscall *)(CLCDItem *, int))v5->dtr_CLCDItem)(a1: v5, a2: 1);
  }
  v6 = this->m_Definition.m_Memory.m_nGrowSize < 0;
  this->m_Definition.m_Size = 0;
  if ( v6 )
  {
    this->m_Definition.m_pElements = this->m_Definition.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Definition.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Definition.m_Memory.m_pMemory);
      this->m_Definition.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Definition.m_Memory.m_pMemory;
    this->m_Definition.m_Memory.m_nAllocationCount = 0;
    this->m_Definition.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107830
// Name: public: CLCDItemText::CLCDItemText(void)
// Source: json
//------------------------------------------------------------------------------
CLCDItemText *__thiscall CLCDItemText::CLCDItemText(CLCDItemText *this)
{
  this->m_bActive = true;
  this->m_Type = 0;
  this->m_Handle = nullptr;
  this->x = 0;
  this->y = 0;
  this->w = 0;
  this->h = 0;
  this->m_nSubPage = 0;
  this->m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Children.m_Memory.m_nAllocationCount = 0;
  this->m_Children.m_Memory.m_nGrowSize = 0;
  this->m_Children.m_Size = 0;
  this->m_Children.m_pElements = nullptr;
  this->__vftable = (CLCDItemText_vtbl *)&CLCDItemText::`vftable';
  CUtlString::CUtlString(this: &this->m_OriginalText);
  this->m_bHasWildcard = false;
  this->m_iSize = 0;
  this->m_iAlign = 0;
  this->m_Type = 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10107890
// Name: public: CLCDItemIcon::CLCDItemIcon(void)
// Source: json
//------------------------------------------------------------------------------
CLCDItemIcon *__thiscall CLCDItemIcon::CLCDItemIcon(CLCDItemIcon *this)
{
  this->m_bActive = true;
  this->m_Type = 0;
  this->m_Handle = nullptr;
  this->x = 0;
  this->y = 0;
  this->w = 0;
  this->h = 0;
  this->m_nSubPage = 0;
  this->m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Children.m_Memory.m_nAllocationCount = 0;
  this->m_Children.m_Memory.m_nGrowSize = 0;
  this->m_Children.m_Size = 0;
  this->m_Children.m_pElements = nullptr;
  this->__vftable = (CLCDItemIcon_vtbl *)&CLCDItemIcon::`vftable';
  CUtlString::CUtlString(this: &this->m_IconName);
  this->m_icon = nullptr;
  this->m_Type = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10107A20
// Name: public: void CUtlDict<struct CLCD::IconInfo_t,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CLCD::IconInfo_t,int>::RemoveAll(CUtlDict<CLCD::IconInfo_t,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10107C20
// Name: private: class CLCDItemIcon __near * CLCD::ParseItemIcon(class CLCDPage __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CLCDItemIcon *__thiscall CLCD::ParseItemIcon(CLCD *this, CLCDPage *page, bool bCreateHandles, KeyValues *sub)
{
  CLCDItemIcon *v4; // eax
  CLCDItemIcon *v5; // eax
  CLCDItemIcon *v6; // esi
  const char *String; // eax
  int v8; // eax
  const char *v9; // eax
  CLCD *v10; // edi
  int v11; // eax
  CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t search; // [esp+8h] [ebp-Ch] BYREF
  CLCD *v14; // [esp+10h] [ebp-4h]

  v14 = this;
  v4 = (CLCDItemIcon *)MemAlloc_Alloc(nSize: 0x4Cu);
  if ( v4 != nullptr && (v5 = CLCDItemIcon::CLCDItemIcon(this: v4)) != nullptr )
    v6 = v5;
  else
    v6 = nullptr;
  String = KeyValues::GetString(this: sub, keyName: "name", defaultValue: prType);
  CUtlString::operator=(this: &v6->m_IconName, src: String);
  if ( KeyValues::GetInt(this: sub, keyName: "header", defaultValue: 0) != 0 )
    v8 = -1;
  else
    v8 = page->m_nSubPageCount - 1;
  v6->m_nSubPage = v8;
  v6->w = KeyValues::GetInt(this: sub, keyName: "w", defaultValue: 24);
  v6->h = KeyValues::GetInt(this: sub, keyName: "h", defaultValue: 24);
  v6->x = KeyValues::GetInt(this: sub, keyName: "x", defaultValue: 0);
  v6->y = KeyValues::GetInt(this: sub, keyName: "y", defaultValue: 0);
  v9 = CUtlString::operator char const *(this: &v6->m_IconName);
  v10 = v14;
  if ( v9 != nullptr )
  {
    search.key = v9;
    v11 = CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::Find(
            this: &v14->m_Icons.m_Elements.m_Tree,
            &search);
  }
  else
  {
    v11 = -1;
  }
  v6->m_icon = nullptr;
  if ( v11 != -1 )
    v6->m_icon = v10->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[v11].m_Data.elem.m_handle;
  if ( bCreateHandles )
    v6->Create(this: v6, a2: v10->m_lcd);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10107D30
// Name: private: class CLCDItemText __near * CLCD::ParseItemText(class CLCDPage __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CLCDItemText *__thiscall CLCD::ParseItemText(CLCD *this, CLCDPage *page, bool bCreateHandles, KeyValues *sub)
{
  CLCDItemText *v5; // eax
  CLCDItemText *v6; // eax
  CLCDItemText *v7; // esi
  int v9; // eax
  int v10; // eax
  const char *String; // eax
  int v12; // eax
  const char *v13; // eax
  int v14; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF
  char *initialText; // [esp+20h] [ebp+10h]

  v5 = (CLCDItemText *)MemAlloc_Alloc(nSize: 0x54u);
  if ( v5 != nullptr && (v6 = CLCDItemText::CLCDItemText(this: v5)) != nullptr )
    v7 = v6;
  else
    v7 = nullptr;
  initialText = (char *)KeyValues::GetString(this: sub, keyName: "text", defaultValue: prType);
  _V_strstr(s1: initialText, search: "%");
  v7->m_bHasWildcard = v9 != 0;
  if ( KeyValues::GetInt(this: sub, keyName: "header", defaultValue: 0) != 0 )
    v10 = -1;
  else
    v10 = page->m_nSubPageCount - 1;
  v7->m_nSubPage = v10;
  v7->w = KeyValues::GetInt(this: sub, keyName: "w", defaultValue: 150);
  v7->x = KeyValues::GetInt(this: sub, keyName: "x", defaultValue: 0);
  v7->y = KeyValues::GetInt(this: sub, keyName: "y", defaultValue: 0);
  String = KeyValues::GetString(this: sub, keyName: "size", defaultValue: "small");
  v7->m_iSize = 0;
  if ( String != nullptr )
  {
    search.key = String;
    v12 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
            this: &this->m_TextSizes.m_Elements.m_Tree,
            &search);
    if ( v12 != -1 )
      v7->m_iSize = this->m_TextSizes.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem;
  }
  v13 = KeyValues::GetString(this: sub, keyName: "align", defaultValue: "left");
  v7->m_iAlign = 0;
  if ( v13 != nullptr )
  {
    search.key = v13;
    v14 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
            this: &this->m_TextAlignments.m_Elements.m_Tree,
            &search);
    if ( v14 != -1 )
      v7->m_iAlign = this->m_TextAlignments.m_Elements.m_Tree.m_Elements.m_pMemory[v14].m_Data.elem;
  }
  CUtlString::operator=(this: &v7->m_OriginalText, src: initialText);
  if ( bCreateHandles )
    v7->Create(this: v7, a2: this->m_lcd);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10107E90
// Name: private: void CLCD::ParseItems_R(class CLCDPage __near *,bool,class KeyValues __near *,class CUtlVector<class CLCDItem __near *,class CUtlMemory<class CLCDItem __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::ParseItems_R(
        CLCD *this,
        CLCDPage *page,
        bool bCreateHandles,
        KeyValues *kv,
        CUtlMemory<vgui::TreeNode *,int> *list)
{
  const char *Name; // edi
  CLCDItemIcon *v6; // eax
  int v7; // edi
  CLCDItemIcon *v8; // ebx
  int v9; // eax
  CLCDItem **v10; // ecx
  int v11; // eax
  CLCDItem **v12; // edi
  int v13; // ebx
  _BYTE *v14; // eax
  _BYTE *v15; // edi
  int i; // eax
  int v17; // edx
  int m_pMemory; // ebx
  int m_nAllocationCount; // eax
  CLCDItem **v20; // ecx
  int v21; // eax
  CLCDItem **v22; // eax
  KeyValues *sub; // [esp+14h] [ebp+10h]

  for ( sub = KeyValues::GetFirstSubKey(this: kv); sub != nullptr; sub = KeyValues::GetNextKey(this: sub) )
  {
    Name = KeyValues::GetName(this: sub);
    if ( _V_stricmp(s1: Name, s2: "iterate_players") == 0 || _V_stricmp(s1: Name, s2: "iterate_team") == 0 )
    {
      v13 = 0;
      if ( _V_stricmp(s1: Name, s2: "iterate_players") != 0 )
      {
        if ( _V_stricmp(s1: Name, s2: "iterate_team") == 0 )
          v13 = 2;
      }
      else
      {
        v13 = 1;
      }
      v14 = MemAlloc_Alloc(nSize: 0x58u);
      if ( v14 != nullptr )
      {
        v14[4] = 1;
        *((_DWORD *)v14 + 3) = 0;
        *((_DWORD *)v14 + 4) = 0;
        *((_DWORD *)v14 + 5) = 0;
        *((_DWORD *)v14 + 6) = 0;
        *((_DWORD *)v14 + 7) = 0;
        *((_DWORD *)v14 + 8) = 0;
        *((_DWORD *)v14 + 9) = 0;
        *((_DWORD *)v14 + 10) = 0;
        *((_DWORD *)v14 + 11) = 0;
        *((_DWORD *)v14 + 12) = 0;
        *((_DWORD *)v14 + 13) = 0;
        *(_DWORD *)v14 = &CLCDItemAggregate::`vftable';
        *((_DWORD *)v14 + 14) = 0;
        *((_DWORD *)v14 + 15) = 0;
        *((_DWORD *)v14 + 16) = 0;
        *((_DWORD *)v14 + 17) = 0;
        *((_DWORD *)v14 + 18) = 0;
        *((_DWORD *)v14 + 19) = 0;
        *((_DWORD *)v14 + 20) = 0;
        *((_DWORD *)v14 + 21) = 0;
        *((_DWORD *)v14 + 2) = 4;
        v15 = v14;
      }
      else
      {
        v15 = nullptr;
      }
      *((_DWORD *)v15 + 15) = v13;
      *((_DWORD *)v15 + 4) = KeyValues::GetInt(this: sub, keyName: "x", defaultValue: 0);
      *((_DWORD *)v15 + 5) = KeyValues::GetInt(this: sub, keyName: "y", defaultValue: 0);
      *((_DWORD *)v15 + 16) = KeyValues::GetInt(this: sub, keyName: "y_increment", defaultValue: 10);
      CLCD::ParseItems_R(
        this,
        page,
        bCreateHandles: false,
        kv: sub,
        list: (CUtlVector<CLCDItem *,CUtlMemory<CLCDItem *,int> > *)(v15 + 68));
      for ( i = 0; i < *((_DWORD *)v15 + 20); *(_BYTE *)(v17 + 4) = 0 )
        v17 = *(_DWORD *)(*((_DWORD *)v15 + 17) + 4 * i++);
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v20 = (CLCDItem **)list->m_pMemory;
      v21 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v21 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v20[m_pMemory + 1],
          src: (unsigned __int8 *)&v20[m_pMemory],
          count: 4 * v21);
      v22 = (CLCDItem **)&list->m_pMemory[m_pMemory];
      if ( v22 != nullptr )
        *v22 = (CLCDItem *)v15;
      continue;
    }
    if ( _V_stricmp(s1: Name, s2: "static_icon") != 0 )
    {
      if ( _V_stricmp(s1: Name, s2: "static_text") != 0 )
      {
        if ( _V_stricmp(s1: Name, s2: "newsubpage") == 0 )
          ++page->m_nSubPageCount;
        continue;
      }
      v6 = (CLCDItemIcon *)CLCD::ParseItemText(this, page, bCreateHandles: true, sub);
    }
    else
    {
      v6 = CLCD::ParseItemIcon(this, page, bCreateHandles: true, sub);
    }
    v7 = (int)list[1].m_pMemory;
    v8 = v6;
    v9 = list->m_nAllocationCount;
    if ( v7 + 1 > v9 )
      CUtlMemory<CChoreoActor *,int>::Grow(this: list, num: v7 - v9 + 1);
    ++list[1].m_pMemory;
    v10 = (CLCDItem **)list->m_pMemory;
    v11 = (int)list[1].m_pMemory - v7 - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v10[v7 + 1], src: (unsigned __int8 *)&v10[v7], count: 4 * v11);
    v12 = (CLCDItem **)&list->m_pMemory[v7];
    if ( v12 != nullptr )
      *v12 = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108100
// Name: private: void CLCD::ParsePage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::ParsePage(CLCD *this, KeyValues *kv)
{
  CLCDPage *v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CLCDPage **m_pMemory; // ecx
  int v7; // eax
  CLCDPage **v8; // edi
  CLCDPage *newPage; // [esp+10h] [ebp-4h]

  v3 = (CLCDPage *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v3 != nullptr )
  {
    v3->m_bActive = true;
    v3->m_Handle = nullptr;
    v3->x = 0;
    v3->y = 0;
    v3->w = 0;
    v3->h = 0;
    v3->m_nSubPage = 0;
    v3->m_Children.m_Memory.m_pMemory = nullptr;
    v3->m_Children.m_Memory.m_nAllocationCount = 0;
    v3->m_Children.m_Memory.m_nGrowSize = 0;
    v3->m_Children.m_Size = 0;
    v3->m_Children.m_pElements = nullptr;
    v3->__vftable = (CLCDPage_vtbl *)&CLCDPage::`vftable';
    *(_WORD *)&v3->m_bSubItem = 0;
    v3->m_bRequiresPlayer = false;
    v3->m_nSubPageCount = 1;
    v3->m_Type = 1;
    newPage = v3;
  }
  else
  {
    newPage = nullptr;
  }
  m_Size = this->m_Pages.m_Size;
  m_nAllocationCount = this->m_Pages.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Pages,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Pages.m_Size;
  m_pMemory = this->m_Pages.m_Memory.m_pMemory;
  v7 = this->m_Pages.m_Size - m_Size - 1;
  this->m_Pages.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &this->m_Pages.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = newPage;
  newPage->m_bTitlePage = KeyValues::GetInt(this: kv, keyName: "titlepage", defaultValue: 0) != 0;
  newPage->m_bRequiresPlayer = KeyValues::GetInt(this: kv, keyName: "requiresplayer", defaultValue: 0) != 0;
  CLCD::ParseItems_R(
    this,
    page: newPage,
    bCreateHandles: true,
    kv,
    list: (CUtlMemory<vgui::TreeNode *,int> *)&newPage->m_Children);
}

//------------------------------------------------------------------------------
// Address: 0x10108200
// Name: public: void CLCD::DumpPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::DumpPlayer(CLCD *this)
{
  CLCD *v1; // ebx
  const unsigned __int8 *LocalPlayer; // esi
  int (__thiscall *v3)(const unsigned __int8 *); // edx
  datamap_t *v4; // eax
  const unsigned __int8 *v5; // eax
  int v6; // edx
  const unsigned __int8 *v7; // ecx
  int (__thiscall *v8)(const unsigned __int8 *); // eax
  datamap_t *v9; // eax
  int (*GetPredDescMap)(void); // eax
  datamap_t *v11; // eax
  const unsigned __int8 *v12; // eax
  int v13; // edx
  const unsigned __int8 *v14; // ecx
  int (__thiscall *v15)(const unsigned __int8 *); // eax
  datamap_t *v16; // eax
  int i; // esi
  char *v18; // ebx
  const wchar_t *v19; // eax
  const char *v20; // [esp-8h] [ebp-21Ch]
  char ansi[512]; // [esp+8h] [ebp-20Ch] BYREF
  CLCD *v22; // [esp+208h] [ebp-Ch]
  CDescribeData helper; // [esp+20Ch] [ebp-8h] BYREF

  v1 = this;
  v22 = this;
  LocalPlayer = (const unsigned __int8 *)C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    _Msg(a1: "(localplayer)\n\n");
    v3 = *(int (__thiscall **)(const unsigned __int8 *))(*(_DWORD *)LocalPlayer + 68);
    helper.m_pSrc = LocalPlayer;
    helper.m_nSrcOffsetIndex = 0;
    v4 = (datamap_t *)v3(a1: LocalPlayer);
    CDescribeData::DumpDescription(this: &helper, pMap: v4);
    _Msg(a1: "(localteam)\n\n");
    v5 = (const unsigned __int8 *)(*(int (__thiscall **)(const unsigned __int8 *))(*(_DWORD *)LocalPlayer + 328))(a1: LocalPlayer);
    if ( v5 != nullptr )
    {
      v6 = *(_DWORD *)v5;
      helper.m_pSrc = v5;
      v7 = v5;
      v8 = *(int (__thiscall **)(const unsigned __int8 *))(v6 + 68);
      helper.m_nSrcOffsetIndex = 0;
      v9 = (datamap_t *)v8(a1: v7);
      CDescribeData::DumpDescription(this: &helper, pMap: v9);
    }
    _Msg(a1: "(playerresource)\n\n");
    if ( g_PR != nullptr )
    {
      GetPredDescMap = (int (*)(void))g_PR->GetPredDescMap;
      helper.m_pSrc = (const unsigned __int8 *)g_PR;
      helper.m_nSrcOffsetIndex = 0;
      v11 = (datamap_t *)GetPredDescMap();
      CDescribeData::DumpDescription(this: &helper, pMap: v11);
    }
    _Msg(a1: "(localplayerweapon)\n\n");
    v12 = (const unsigned __int8 *)(*(int (__thiscall **)(const unsigned __int8 *))(*(_DWORD *)LocalPlayer + 948))(a1: LocalPlayer);
    if ( v12 != nullptr )
    {
      v13 = *(_DWORD *)v12;
      helper.m_pSrc = v12;
      v14 = v12;
      v15 = *(int (__thiscall **)(const unsigned __int8 *))(v13 + 68);
      helper.m_nSrcOffsetIndex = 0;
      v16 = (datamap_t *)v15(a1: v14);
      CDescribeData::DumpDescription(this: &helper, pMap: v16);
    }
    _Msg(a1: "Other replacements:\n\n");
    for ( i = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::FirstInorder(this: &v1->m_GlobalStats.m_Elements.m_Tree);
          i != -1;
          i = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::NextInorder(
                this: &v1->m_GlobalStats.m_Elements.m_Tree,
                i) )
    {
      v18 = (char *)CUtlString::operator char const *(this: &v1->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem);
      ansi[0] = 0;
      if ( *v18 == 35 )
      {
        v19 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v18);
        if ( v19 != nullptr )
        {
          v18 = ansi;
          g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v19, a3: ansi, a4: 512);
        }
      }
      v20 = v18;
      v1 = v22;
      _Msg(a1: "'%s' = '%s'\n", v22->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key, v20);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101083A0
// Name: public: virtual void CLCD::AddChatLine(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::AddChatLine(CLCD *this, const char *txt)
{
  CUtlString *m_pMemory; // esi
  int v4; // eax
  const CUtlString *v5; // eax
  CUtlString v6; // [esp+8h] [ebp-10h] BYREF

  if ( this->m_lcd != nullptr )
  {
    for ( ; this->m_ChatHistory.m_Size >= this->m_nMaxChatHistory; --this->m_ChatHistory.m_Size )
    {
      m_pMemory = this->m_ChatHistory.m_Memory.m_pMemory;
      m_pMemory->m_Storage.m_nActualLength = 0;
      if ( m_pMemory->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory->m_Storage.m_Memory.m_pMemory);
          m_pMemory->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        m_pMemory->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v4 = this->m_ChatHistory.m_Size - 1;
      if ( v4 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)this->m_ChatHistory.m_Memory.m_pMemory,
          src: (unsigned __int8 *)&this->m_ChatHistory.m_Memory.m_pMemory[1],
          count: 16 * v4);
    }
    v5 = CUtlString::CUtlString(this: &v6, pString: txt);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: &this->m_ChatHistory,
      elem: this->m_ChatHistory.m_Size,
      src: v5);
    v6.m_Storage.m_nActualLength = 0;
    if ( v6.m_Storage.m_Memory.m_nGrowSize >= 0 && v6.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6.m_Storage.m_Memory.m_pMemory);
    CLCD::UpdateChat(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108470
// Name: private: void CLCD::DoGlobalReplacements(class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::DoGlobalReplacements(CLCD *this, CUtlString *str)
{
  int Inorder; // ebx
  char *v3; // edi
  const wchar_t *v4; // eax
  char ansi[512]; // [esp+Ch] [ebp-20Ch] BYREF
  int maxChanges; // [esp+20Ch] [ebp-Ch]
  CLCD *v7; // [esp+210h] [ebp-8h]
  bool changed; // [esp+217h] [ebp-1h]

  v7 = this;
  for ( maxChanges = 16; maxChanges >= 0; --maxChanges )
  {
    changed = false;
    Inorder = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::FirstInorder(this: &v7->m_GlobalStats.m_Elements.m_Tree);
    if ( Inorder == -1 )
      break;
    do
    {
      v3 = (char *)CUtlString::operator char const *(this: &v7->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem);
      ansi[0] = 0;
      if ( *v3 == 35 )
      {
        v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v3);
        if ( v4 != nullptr )
        {
          v3 = ansi;
          g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: ansi, a4: 512);
        }
      }
      if ( CLCD::Replace(
             this: v7,
             str,
             search: (char *)v7->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key,
             replace: v3) != 0 )
        changed = true;
      Inorder = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::NextInorder(
                  this: &v7->m_GlobalStats.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    if ( !changed )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108630
// Name: g15_dumpplayer
// Source: json
//------------------------------------------------------------------------------
void __cdecl g15_dumpplayer()
{
  int v0; // eax

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-g15") != 0 )
    CLCD::DumpPlayer(this: &gLCD);
  else
    _Msg(a1: "Must run with -g15 to enable support for the LCD Keyboard\n");
}

//------------------------------------------------------------------------------
// Address: 0x10108670
// Name: public: class CLCDItem __near & CLCDItem::operator=(class CLCDItem const __near &)
// Source: json
//------------------------------------------------------------------------------
CLCDItem *__thiscall CLCDItem::operator=(CLCDItem *this, const CLCDItem *__that)
{
  int i; // eax
  const CLCDItem *__thata; // [esp+14h] [ebp+8h]

  this->m_bActive = __that->m_bActive;
  this->m_Type = __that->m_Type;
  this->m_Handle = __that->m_Handle;
  this->x = __that->x;
  this->y = __that->y;
  this->w = __that->w;
  this->h = __that->h;
  this->m_nSubPage = __that->m_nSubPage;
  __thata = (const CLCDItem *)__that->m_Children.m_Size;
  this->m_Children.m_Size = 0;
  CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&this->m_Children,
    elem: 0,
    num: (int)__thata);
  for ( i = 0; i < (int)__thata; ++i )
    this->m_Children.m_Memory.m_pMemory[i] = __that->m_Children.m_Memory.m_pMemory[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101087E0
// Name: public: void CLCD::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::Shutdown(CLCD *this)
{
  int i; // ebx
  CLCDPage *v3; // edi
  IG15 *m_lcd; // ecx
  int j; // edi
  int k; // edi
  int m; // edi
  struct CSysModule *m_pG15Module; // eax

  for ( i = 0; i < this->m_Pages.m_Size; ++i )
  {
    v3 = this->m_Pages.m_Memory.m_pMemory[i];
    v3->Wipe(this: v3, a2: this->m_lcd);
    ((void (__thiscall *)(CLCDPage *, int))v3->dtr_CLCDItem)(a1: v3, a2: 1);
  }
  this->m_Pages.m_Size = 0;
  if ( this->m_Pages.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Pages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Pages.m_Memory.m_pMemory);
      this->m_Pages.m_Memory.m_pMemory = nullptr;
    }
    this->m_Pages.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Pages.m_pElements = this->m_Pages.m_Memory.m_pMemory;
  m_lcd = this->m_lcd;
  if ( m_lcd != nullptr )
  {
    m_lcd->Shutdown(this: m_lcd);
    this->m_lcd = nullptr;
  }
  for ( j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_TextSizes.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_TextSizes.m_Elements.m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_TextSizes.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_TextSizes.m_Elements.m_Tree);
  for ( k = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_TextAlignments.m_Elements.m_Tree);
        k != -1;
        k = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_TextAlignments.m_Elements.m_Tree,
              i: k) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_TextAlignments.m_Elements.m_Tree.m_Elements.m_pMemory[k].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_TextAlignments.m_Elements.m_Tree);
  for ( m = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_GlobalStats.m_Elements.m_Tree);
        m != -1;
        m = CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_GlobalStats.m_Elements.m_Tree,
              i: m) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory[m].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_GlobalStats.m_Elements.m_Tree);
  m_pG15Module = this->m_pG15Module;
  this->m_G15Factory = nullptr;
  if ( m_pG15Module != nullptr )
  {
    Sys_UnloadModule(pModule: m_pG15Module);
    this->m_pG15Module = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108960
// Name: private: void CLCD::ShowItems_R(class CLCDPage __near *,unsigned int,class CUtlVector<class CLCDItem __near *,class CUtlMemory<class CLCDItem __near *,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::ShowItems_R(
        CLCD *this,
        CLCDPage *page,
        unsigned int dwCurTime,
        CUtlVector<CLCDItem *,CUtlMemory<CLCDItem *,int> > *list,
        bool bShowItems)
{
  int m_Size; // ecx
  int m_nSubPage; // eax
  CLCDItem *v8; // edi
  int x; // eax
  int y; // ecx
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // eax
  int v15; // edi
  int *m_pMemory; // ecx
  int v17; // eax
  int *v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // eax
  int *v22; // edi
  int v23; // edi
  int v24; // eax
  CLCDItem *v25; // ecx
  int v26; // edi
  char *v27; // eax
  char *v28; // esi
  int v29; // eax
  CLCD *v30; // edi
  void (__thiscall *v31)(char *, IG15 *); // edx
  CLCDItemText *v32; // eax
  CLCDItemText *v33; // eax
  CLCDItemText *v34; // esi
  CLCDItemText *v35; // eax
  CLCDItemText *v36; // esi
  CLCD *v37; // edi
  CUtlMemory<vgui::TreeNode *,int> *v38; // edi
  vgui::TreeNode **v39; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v41; // ecx
  int v42; // eax
  CLCDItem **v43; // esi
  int v44; // edx
  const char *v45; // eax
  const char *v46; // eax
  int v47; // eax
  const char *v48; // eax
  const char *v49; // eax
  char s2[512]; // [esp+8h] [ebp-6B8h] BYREF
  char s1[512]; // [esp+208h] [ebp-4B8h] BYREF
  char prefix[256]; // [esp+408h] [ebp-2B8h] BYREF
  char altprefix[256]; // [esp+508h] [ebp-1B8h] BYREF
  char itemNumber[32]; // [esp+608h] [ebp-B8h] BYREF
  CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t search; // [esp+628h] [ebp-98h] BYREF
  CUtlString str; // [esp+630h] [ebp-90h] BYREF
  CUtlString v57; // [esp+640h] [ebp-80h] BYREF
  int itemCount; // [esp+650h] [ebp-70h]
  CUtlString out; // [esp+654h] [ebp-6Ch] BYREF
  CUtlString updated; // [esp+664h] [ebp-5Ch] BYREF
  int curx; // [esp+674h] [ebp-4Ch]
  CUtlString s; // [esp+678h] [ebp-48h] BYREF
  int j; // [esp+688h] [ebp-38h]
  CLCDItem *newItem; // [esp+68Ch] [ebp-34h]
  CLCD *v65; // [esp+690h] [ebp-30h]
  int spItems; // [esp+694h] [ebp-2Ch]
  int e; // [esp+698h] [ebp-28h]
  int r; // [esp+69Ch] [ebp-24h]
  CUtlVector<int,CUtlMemory<int,int> > validIndices; // [esp+6A0h] [ebp-20h] BYREF
  int cury; // [esp+6B4h] [ebp-Ch]
  CLCDItem *item; // [esp+6B8h] [ebp-8h]
  int pl; // [esp+6BCh] [ebp-4h]

  m_Size = list->m_Size;
  m_nSubPage = 0;
  v65 = this;
  itemCount = m_Size;
  j = 0;
  if ( m_Size <= 0 )
    return;
  do
  {
    v8 = list->m_Memory.m_pMemory[m_nSubPage];
    item = v8;
    if ( !v8->m_bActive )
      goto LABEL_102;
    if ( !bShowItems )
      goto LABEL_100;
    if ( v8->m_Type == 2 )
    {
      CUtlString::CUtlString(this: &updated);
      CUtlString::CUtlString(this: &str, string: (const CUtlString *)&v8[1]);
      v48 = CUtlString::operator char const *(this: &str);
      CLCD::BuildUpdatedText(this, in: v48, out: &updated);
      CLCD::DoGlobalReplacements(this, str: &updated);
      CLCD::ReduceParentheses(this, str: &updated);
      v49 = CUtlString::operator char const *(this: &updated);
      this->m_lcd->SetText(this: this->m_lcd, a2: v8->m_Handle, a3: v49);
      str.m_Storage.m_nActualLength = 0;
      if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( str.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
          str.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        str.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      updated.m_Storage.m_nActualLength = 0;
      if ( updated.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( updated.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: updated.m_Storage.m_Memory.m_pMemory);
          updated.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        updated.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      goto LABEL_97;
    }
    if ( v8->m_Type == 3 )
    {
      CUtlString::CUtlString(this: &out);
      CUtlString::CUtlString(this: &v57, string: (const CUtlString *)&v8[1]);
      v45 = CUtlString::operator char const *(this: &v57);
      CLCD::BuildUpdatedText(this, in: v45, &out);
      CLCD::DoGlobalReplacements(this, str: &out);
      CLCD::ReduceParentheses(this, str: &out);
      v46 = CUtlString::operator char const *(this: &out);
      if ( v46 != nullptr )
      {
        search.key = v46;
        v47 = CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::Find(
                this: &this->m_Icons.m_Elements.m_Tree,
                &search);
        if ( v47 != -1 )
          v8[1].x = (int)this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory[v47].m_Data.elem.m_handle;
      }
      if ( v8->m_Handle != nullptr )
      {
        this->m_lcd->RemoveAndDestroyObject(this: this->m_lcd, a2: v8->m_Handle);
        v8->m_Handle = nullptr;
      }
      v8->Create(this: v8, a2: this->m_lcd);
      v57.m_Storage.m_nActualLength = 0;
      if ( v57.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v57.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57.m_Storage.m_Memory.m_pMemory);
          v57.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v57.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      out.m_Storage.m_nActualLength = 0;
      if ( out.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( out.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: out.m_Storage.m_Memory.m_pMemory);
          out.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        out.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      goto LABEL_97;
    }
    if ( v8->m_Type != 4 || v8[1].__vftable > (CLCDItem_vtbl *)dwCurTime )
      goto LABEL_97;
    v8[1].__vftable = (CLCDItem_vtbl *)(dwCurTime + 1000);
    CLCDItem::Wipe(this: v8, lcd: this->m_lcd);
    x = v8->x;
    y = v8->y;
    v11 = *(_DWORD *)&v8[1].m_bActive - 1;
    memset(&validIndices, 0, sizeof(validIndices));
    prefix[0] = 0;
    altprefix[0] = 0;
    curx = x;
    cury = y;
    if ( v11 != 0 )
    {
      if ( v11 != 1 )
        goto LABEL_35;
      r = (int)C_BasePlayer::GetLocalPlayer(nSlot: -1);
      if ( r != 0 )
      {
        v12 = 1;
        for ( pl = 1; v12 <= *(_DWORD *)(gpGlobals.m_Index + 20); pl = v12 )
        {
          if ( g_PR != nullptr && g_PR->IsConnected(this: &g_PR->IGameResources, a2: v12) )
          {
            v13 = g_PR->GetTeam(this: &g_PR->IGameResources, a2: v12);
            if ( (*(int (__thiscall **)(int))(*(_DWORD *)r + 332))(a1: r) == v13 )
            {
              v14 = validIndices.m_Size;
              v15 = validIndices.m_Size;
              if ( validIndices.m_Size + 1 > validIndices.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CChoreoActor *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&validIndices,
                  num: validIndices.m_Size - validIndices.m_Memory.m_nAllocationCount + 1);
                v14 = validIndices.m_Size;
              }
              m_pMemory = validIndices.m_Memory.m_pMemory;
              validIndices.m_Size = v14 + 1;
              v17 = v14 - v15;
              validIndices.m_pElements = validIndices.m_Memory.m_pMemory;
              if ( v17 > 0 )
              {
                _V_memmove(
                  dest: (unsigned __int8 *)&validIndices.m_Memory.m_pMemory[v15 + 1],
                  src: (unsigned __int8 *)&validIndices.m_Memory.m_pMemory[v15],
                  count: 4 * v17);
                m_pMemory = validIndices.m_Memory.m_pMemory;
              }
              v18 = &m_pMemory[v15];
              v12 = pl;
              if ( v18 != nullptr )
                *v18 = pl;
            }
            else
            {
              v12 = pl;
            }
          }
          ++v12;
        }
      }
    }
    else
    {
      for ( pl = 1; pl <= *(_DWORD *)(gpGlobals.m_Index + 20); ++pl )
      {
        if ( g_PR != nullptr && g_PR->IsConnected(this: &g_PR->IGameResources, a2: pl) )
        {
          v19 = validIndices.m_Size;
          v20 = validIndices.m_Size;
          if ( validIndices.m_Size + 1 > validIndices.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&validIndices,
              num: validIndices.m_Size - validIndices.m_Memory.m_nAllocationCount + 1);
            v19 = validIndices.m_Size;
          }
          validIndices.m_Size = v19 + 1;
          v21 = v19 - v20;
          validIndices.m_pElements = validIndices.m_Memory.m_pMemory;
          if ( v21 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&validIndices.m_Memory.m_pMemory[v20 + 1],
              src: (unsigned __int8 *)&validIndices.m_Memory.m_pMemory[v20],
              count: 4 * v21);
          v22 = &validIndices.m_Memory.m_pMemory[v20];
          if ( v22 != nullptr )
            *v22 = pl;
        }
      }
    }
    V_strncpy(pDest: prefix, pSrc: "(playerindex)", maxLen: 256);
    V_strncpy(pDest: altprefix, pSrc: "(playerindexplusone)", maxLen: 256);
LABEL_35:
    pl = 0;
    spItems = 0;
    e = 0;
    if ( validIndices.m_Size <= 0 )
      goto LABEL_72;
    do
    {
      v23 = validIndices.m_Memory.m_pMemory[e];
      V_snprintf(pDest: s1, maxLen: 0x200u, pFormat: "%d", v23);
      V_snprintf(pDest: s2, maxLen: 0x200u, pFormat: "%d", v23 + 1);
      v24 = 0;
      r = 0;
      v25 = item;
      if ( item[1].w > 0 )
      {
        while ( 1 )
        {
          v26 = *((_DWORD *)v25[1].m_Handle + v24);
          if ( *(_DWORD *)(v26 + 8) == 2 )
            break;
          if ( *(_DWORD *)(v26 + 8) == 3 )
          {
            v27 = (char *)MemAlloc_Alloc(nSize: 0x4Cu);
            v28 = v27;
            if ( v27 != nullptr )
            {
              v27[4] = 1;
              *((_DWORD *)v27 + 2) = 0;
              *((_DWORD *)v27 + 3) = 0;
              *((_DWORD *)v27 + 4) = 0;
              *((_DWORD *)v27 + 5) = 0;
              *((_DWORD *)v27 + 6) = 0;
              *((_DWORD *)v27 + 7) = 0;
              *((_DWORD *)v27 + 8) = 0;
              *((_DWORD *)v27 + 9) = 0;
              *((_DWORD *)v27 + 10) = 0;
              *((_DWORD *)v27 + 11) = 0;
              *((_DWORD *)v27 + 12) = 0;
              *((_DWORD *)v27 + 13) = 0;
              *(_DWORD *)v27 = &CLCDItemIcon::`vftable';
              CUtlString::CUtlString(this: (CUtlString *)(v27 + 56));
              *((_DWORD *)v28 + 18) = 0;
              *((_DWORD *)v28 + 2) = 3;
            }
            else
            {
              v28 = nullptr;
            }
            CLCDItem::operator=(this: (CLCDItem *)v28, __that: (const CLCDItem *)v26);
            CUtlString::operator=(this: (CUtlString *)(v28 + 56), src: (const CUtlString *)(v26 + 56));
            v29 = *(_DWORD *)(v26 + 72);
            v30 = v65;
            v31 = *(void (__thiscall **)(char *, IG15 *))(*(_DWORD *)v28 + 4);
            *((_DWORD *)v28 + 18) = v29;
            v28[4] = 1;
            v31(a1: v28, a2: v30->m_lcd);
            v30->m_lcd->SetOrigin(
              this: v30->m_lcd,
              a2: *((void **)v28 + 3),
              a3: curx + *((_DWORD *)v28 + 4),
              a4: cury + *((_DWORD *)v28 + 5));
            newItem = (CLCDItem *)v28;
LABEL_59:
            if ( newItem != nullptr )
            {
              v38 = (CUtlMemory<vgui::TreeNode *,int> *)item;
              ++spItems;
              newItem->m_nSubPage = pl;
              v39 = v38[4].m_pMemory;
              m_nAllocationCount = v38[3].m_nAllocationCount;
              if ( (int)v39 + 1 > m_nAllocationCount )
                CUtlMemory<CChoreoActor *,int>::Grow(this: v38 + 3, num: (int)v39 - m_nAllocationCount + 1);
              ++v38[4].m_pMemory;
              v41 = v38[3].m_pMemory;
              v42 = (char *)v38[4].m_pMemory - (char *)v39 - 1;
              v38[4].m_nAllocationCount = (int)v41;
              if ( v42 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&v41[(_DWORD)v39 + 1],
                  src: (unsigned __int8 *)&v41[(_DWORD)v39],
                  count: 4 * v42);
              v43 = (CLCDItem **)&v38[3].m_pMemory[(_DWORD)v39];
              if ( v43 != nullptr )
                *v43 = newItem;
            }
          }
          v25 = item;
          this = v65;
          v24 = r + 1;
          r = v24;
          if ( v24 >= item[1].w )
            goto LABEL_67;
        }
        CUtlString::CUtlString(this: &s);
        CUtlString::operator=(this: &s, src: (const CUtlString *)(v26 + 56));
        CLCD::Replace(this, str: &s, search: prefix, replace: s1);
        CLCD::Replace(this, str: &s, search: altprefix, replace: s2);
        V_snprintf(pDest: itemNumber, maxLen: 0x20u, pFormat: "%d", e + 1);
        CLCD::Replace(this, str: &s, search: "(itemnumber)", replace: itemNumber);
        CLCD::DoGlobalReplacements(this, str: &s);
        switch ( *(_DWORD *)(v26 + 8) )
        {
          case 2:
            v35 = (CLCDItemText *)MemAlloc_Alloc(nSize: 0x54u);
            if ( v35 == nullptr )
              goto LABEL_54;
            v32 = CLCDItemText::CLCDItemText(this: v35);
            break;
          case 3:
            v33 = (CLCDItemText *)MemAlloc_Alloc(nSize: 0x4Cu);
            v34 = v33;
            if ( v33 == nullptr )
              goto LABEL_54;
            v33->m_bActive = true;
            v33->m_Type = 0;
            v33->m_Handle = nullptr;
            v33->x = 0;
            v33->y = 0;
            v33->w = 0;
            v33->h = 0;
            v33->m_nSubPage = 0;
            v33->m_Children.m_Memory.m_pMemory = nullptr;
            v33->m_Children.m_Memory.m_nAllocationCount = 0;
            v33->m_Children.m_Memory.m_nGrowSize = 0;
            v33->m_Children.m_Size = 0;
            v33->m_Children.m_pElements = nullptr;
            v33->__vftable = (CLCDItemText_vtbl *)&CLCDItemIcon::`vftable';
            CUtlString::CUtlString(this: &v33->m_OriginalText);
            *(_DWORD *)&v34->m_bHasWildcard = 0;
            v34->m_Type = 3;
            v32 = v34;
            break;
          case 4:
            v32 = (CLCDItemText *)MemAlloc_Alloc(nSize: 0x58u);
            if ( v32 == nullptr )
              goto LABEL_54;
            v32->m_bActive = true;
            v32->m_Handle = nullptr;
            v32->x = 0;
            v32->y = 0;
            v32->w = 0;
            v32->h = 0;
            v32->m_nSubPage = 0;
            v32->m_Children.m_Memory.m_pMemory = nullptr;
            v32->m_Children.m_Memory.m_nAllocationCount = 0;
            v32->m_Children.m_Memory.m_nGrowSize = 0;
            v32->m_Children.m_Size = 0;
            v32->m_Children.m_pElements = nullptr;
            v32->__vftable = (CLCDItemText_vtbl *)&CLCDItemAggregate::`vftable';
            v32->m_OriginalText.m_Storage.m_Memory.m_pMemory = nullptr;
            v32->m_OriginalText.m_Storage.m_Memory.m_nAllocationCount = 0;
            v32->m_OriginalText.m_Storage.m_Memory.m_nGrowSize = 0;
            v32->m_OriginalText.m_Storage.m_nActualLength = 0;
            *(_DWORD *)&v32->m_bHasWildcard = 0;
            v32->m_iSize = 0;
            v32->m_iAlign = 0;
            v32[1].__vftable = nullptr;
            v32->m_Type = 4;
            break;
          default:
            goto LABEL_54;
        }
        if ( v32 != nullptr )
        {
          v36 = v32;
          goto LABEL_55;
        }
LABEL_54:
        v36 = nullptr;
LABEL_55:
        CLCDItem::operator=(this: v36, __that: (const CLCDItem *)v26);
        CUtlString::operator=(this: &v36->m_OriginalText, src: (const CUtlString *)(v26 + 56));
        v36->m_bHasWildcard = *(_BYTE *)(v26 + 72);
        v36->m_iSize = *(_DWORD *)(v26 + 76);
        v36->m_iAlign = *(_DWORD *)(v26 + 80);
        v36->m_bActive = true;
        CUtlString::operator=(this: &v36->m_OriginalText, src: &s);
        v37 = v65;
        v36->Create(this: v36, a2: v65->m_lcd);
        v37->m_lcd->SetOrigin(this: v37->m_lcd, a2: v36->m_Handle, a3: curx + v36->x, a4: cury + v36->y);
        newItem = v36;
        s.m_Storage.m_nActualLength = 0;
        if ( s.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( s.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s.m_Storage.m_Memory.m_pMemory);
            s.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          s.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        goto LABEL_59;
      }
LABEL_67:
      cury += v25[1].m_Type;
      if ( cury + 10 > this->m_Size[1] )
      {
        v44 = v25->y;
        ++pl;
        spItems = 0;
        cury = v44;
      }
      ++e;
    }
    while ( e < validIndices.m_Size );
    if ( spItems > 0 )
    {
      page->m_nSubPageCount = pl + 1;
      goto LABEL_73;
    }
LABEL_72:
    page->m_nSubPageCount = pl;
LABEL_73:
    if ( validIndices.m_Memory.m_nGrowSize >= 0 && validIndices.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validIndices.m_Memory.m_pMemory);
LABEL_97:
    v8 = item;
    m_nSubPage = item->m_nSubPage;
    if ( m_nSubPage == -1 || m_nSubPage == this->m_nSubPage )
    {
      LOBYTE(m_nSubPage) = 1;
      goto LABEL_101;
    }
LABEL_100:
    LOBYTE(m_nSubPage) = 0;
LABEL_101:
    this->m_lcd->SetVisible(this: this->m_lcd, a2: v8->m_Handle, a3: m_nSubPage);
    CLCD::ShowItems_R(this, page, dwCurTime, list: &v8->m_Children, bShowItems);
    m_nSubPage = j;
    m_Size = itemCount;
LABEL_102:
    j = ++m_nSubPage;
  }
  while ( m_nSubPage < m_Size );
}

//------------------------------------------------------------------------------
// Address: 0x101091F0
// Name: private: void CLCD::DisplayCurrentPage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::DisplayCurrentPage(CLCD *this, unsigned int dwCurTime)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_Pages.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CLCD::ShowItems_R(
      this,
      page: this->m_Pages.m_Memory.m_pMemory[i],
      dwCurTime,
      list: &this->m_Pages.m_Memory.m_pMemory[i]->m_Children,
      bShowItems: i == this->m_nCurrentPage);
}

//------------------------------------------------------------------------------
// Address: 0x10109230
// Name: private: void CLCD::ParseIconMappings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::ParseIconMappings(CLCD *this, KeyValues *kv)
{
  KeyValues *FirstSubKey; // eax
  CUtlDict<CLCD::IconInfo_t,int> *p_m_Icons; // edi
  const char *Name; // ebx
  IFileSystem_vtbl *v6; // esi
  const char *String; // eax
  const char *v8; // eax
  const char *v9; // esi
  const char *v10; // ecx
  int v11; // eax
  char v12; // dl
  const char *v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int> *m_pMemory; // ecx
  int v19; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int> *v20; // edx
  CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t *p_m_Data; // esi
  char fullpath[512]; // [esp+4h] [ebp-210h] BYREF
  CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t insert; // [esp+204h] [ebp-10h] BYREF
  int parent; // [esp+20Ch] [ebp-8h] BYREF
  KeyValues *icon; // [esp+210h] [ebp-4h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: kv);
  icon = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    p_m_Icons = &this->m_Icons;
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      v6 = filesystem->IAppSystem::__vftable;
      String = KeyValues::GetString(this: icon, keyName: nullptr, defaultValue: prType);
      v6->RelativePathToFullPath(
        this: filesystem,
        a2: String,
        a3: "GAME",
        a4: fullpath,
        a5: 512,
        a6: FILTER_NONE,
        a7: nullptr);
      kv = (KeyValues *)LoadImageA(hInst: nullptr, name: fullpath, type: 1u, cx: 32, cy: 32, fuLoad: 0x10u);
      if ( Name != nullptr
        && (v8 = (const char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(Name) + 1), v9 = v8, v8 != nullptr) )
      {
        v10 = Name;
        v11 = v8 - Name;
        do
        {
          v12 = *v10;
          v10[v11] = *v10;
          ++v10;
        }
        while ( v12 != 0 );
        v13 = v9;
      }
      else
      {
        v13 = nullptr;
      }
      insert.key = v13;
      insert.elem.m_handle = kv;
      parent = -1;
      HIBYTE(kv) = 0;
      CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::FindInsertionPosition(
        this: &p_m_Icons->m_Elements.m_Tree,
        &insert,
        &parent,
        leftchild: (bool *)&kv + 3);
      v14 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
              this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)p_m_Icons,
              a2: (const char *)p_m_Icons);
      v15 = parent;
      v16 = v14;
      v17 = &p_m_Icons->m_Elements.m_Tree.m_Elements.m_pMemory[v14];
      v17->m_Parent = parent;
      v17->m_Right = -1;
      v17->m_Left = -1;
      v17->m_Tag = 0;
      if ( v15 == -1 )
      {
        p_m_Icons->m_Elements.m_Tree.m_Root = v14;
      }
      else
      {
        m_pMemory = p_m_Icons->m_Elements.m_Tree.m_Elements.m_pMemory;
        v19 = v15;
        if ( HIBYTE(kv) != 0 )
          m_pMemory[v19].m_Left = v14;
        else
          m_pMemory[v19].m_Right = v14;
      }
      CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::InsertRebalance(
        this: &p_m_Icons->m_Elements.m_Tree,
        elem: v14);
      v20 = p_m_Icons->m_Elements.m_Tree.m_Elements.m_pMemory;
      ++p_m_Icons->m_Elements.m_Tree.m_NumElements;
      p_m_Data = &v20[v16].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      icon = KeyValues::GetNextKey(this: icon);
      if ( icon == nullptr )
        break;
      FirstSubKey = icon;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101093B0
// Name: public: virtual void CLCD::SetGlobalStat(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::SetGlobalStat(CLCD *this, const char *name, const char *value)
{
  int v4; // eax

  if ( this->m_lcd != nullptr )
  {
    v4 = CUtlDict<CUtlString,int>::Find(this: &this->m_GlobalStats, pName: name);
    if ( v4 == -1 )
      v4 = CUtlDict<CUtlString,int>::Insert(this: &this->m_GlobalStats, pName: name);
    CUtlString::operator=(this: &this->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem, src: value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109400
// Name: public: CLCD::CLCD(void)
// Source: json
//------------------------------------------------------------------------------
CLCD *__thiscall CLCD::CLCD(CLCD *this)
{
  this->__vftable = (CLCD_vtbl *)&CLCD::`vftable';
  this->m_lcd = nullptr;
  CUtlString::CUtlString(this: &this->m_Title);
  this->m_Pages.m_Memory.m_pMemory = nullptr;
  this->m_Pages.m_Memory.m_nAllocationCount = 0;
  this->m_Pages.m_Memory.m_nGrowSize = 0;
  this->m_Pages.m_Size = 0;
  this->m_Pages.m_pElements = nullptr;
  this->m_nCurrentPage = 0;
  this->m_nSubPage = 0;
  this->m_nMaxChatHistory = 4;
  this->m_TextSizes.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_TextSizes.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_TextSizes.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_TextSizes.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_TextSizes.m_Elements.m_Tree.m_Root = -1;
  this->m_TextSizes.m_Elements.m_Tree.m_NumElements = 0;
  this->m_TextSizes.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_TextSizes.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_TextSizes.m_Elements.m_Tree.m_pElements = this->m_TextSizes.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_TextSizes.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_TextSizes.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_TextAlignments.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_TextAlignments.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_TextAlignments.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_TextAlignments.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_TextAlignments.m_Elements.m_Tree.m_Root = -1;
  this->m_TextAlignments.m_Elements.m_Tree.m_NumElements = 0;
  this->m_TextAlignments.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_TextAlignments.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_TextAlignments.m_Elements.m_Tree.m_pElements = this->m_TextAlignments.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_TextAlignments.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_TextAlignments.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_Icons.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Icons.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Icons.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Icons.m_Elements.m_Tree.m_Root = -1;
  this->m_Icons.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Icons.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Icons.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Icons.m_Elements.m_Tree.m_pElements = this->m_Icons.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Icons.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Icons.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_bHadPlayer = false;
  this->m_GlobalStats.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_GlobalStats.m_Elements.m_Tree.m_Root = -1;
  this->m_GlobalStats.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_GlobalStats.m_Elements.m_Tree.m_NumElements = 0;
  this->m_GlobalStats.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_GlobalStats.m_Elements.m_Tree.m_pElements = this->m_GlobalStats.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_GlobalStats.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_GlobalStats.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_ChatHistory.m_Memory.m_pMemory = nullptr;
  this->m_ChatHistory.m_Memory.m_nAllocationCount = 0;
  this->m_ChatHistory.m_Memory.m_nGrowSize = 0;
  this->m_ChatHistory.m_Size = 0;
  this->m_ChatHistory.m_pElements = nullptr;
  this->m_dwNextUpdateTime = 0;
  this->m_pG15Module = nullptr;
  this->m_G15Factory = nullptr;
  this->m_Size[1] = 0;
  this->m_Size[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10109570
// Name: public: CLCD::~CLCD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::~CLCD(CLCD *this)
{
  this->__vftable = (CLCD_vtbl *)&CLCD::`vftable';
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_ChatHistory);
  CUtlDict<CUtlString,int>::RemoveAll(this: &this->m_GlobalStats);
  CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CUtlString,int>::Node_t,int,CUtlMap<char const *,CUtlString,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,int>::Node_t,int>,int>>(this: &this->m_GlobalStats.m_Elements.m_Tree);
  CUtlDict<CLCD::IconInfo_t,int>::RemoveAll(this: &this->m_Icons);
  CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int,CUtlMap<char const *,CLCD::IconInfo_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CLCD::IconInfo_t,int>::Node_t,int>,int>>(this: &this->m_Icons.m_Elements.m_Tree);
  CUtlDict<int,int>::RemoveAll(this: &this->m_TextAlignments);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_TextAlignments.m_Elements.m_Tree);
  CUtlDict<int,int>::RemoveAll(this: &this->m_TextSizes);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_TextSizes.m_Elements.m_Tree);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Pages);
  this->m_Title.m_Storage.m_nActualLength = 0;
  if ( this->m_Title.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Title.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Title.m_Storage.m_Memory.m_pMemory);
      this->m_Title.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Title.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109610
// Name: public: void CLCD::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLCD::Init(CLCD *this)
{
  int v2; // eax
  KeyValues *v3; // ebx
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IG15 *v6; // eax
  KeyValues *v7; // eax
  IBaseFileSystem *v8; // eax
  int Int; // eax
  const char *v10; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // ebx
  const char *title; // [esp+4h] [ebp-8h]
  KeyValues *kv; // [esp+8h] [ebp-4h] BYREF

  v2 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-g15") != 0 )
  {
    v3 = nullptr;
    if ( this->m_lcd == nullptr )
    {
      Module = (struct CSysModule *)Sys_LoadModule(pModuleName: "bin/g15.dll");
      this->m_pG15Module = Module;
      if ( Module != nullptr )
      {
        Factory = Sys_GetFactory(pModule: Module);
        this->m_G15Factory = Factory;
        if ( Factory != nullptr
          && (v6 = (IG15 *)Factory(a1: "G15_INTERFACE_VERSION001", a2: nullptr), this->m_lcd = v6, v6 != nullptr) )
        {
          v6->GetLCDSize(this: v6, a2: this->m_Size, a3: &this->m_Size[1]);
          this->m_nCurrentPage = 0;
          this->m_nSubPage = 0;
          kv = nullptr;
          CUtlDict<int,int>::Insert(this: &this->m_TextSizes, pName: "small", element: (const int *)&kv);
          kv = (KeyValues *)1;
          CUtlDict<int,int>::Insert(this: &this->m_TextSizes, pName: "medium", element: (const int *)&kv);
          kv = (KeyValues *)2;
          CUtlDict<int,int>::Insert(this: &this->m_TextSizes, pName: "big", element: (const int *)&kv);
          kv = nullptr;
          CUtlDict<int,int>::Insert(this: &this->m_TextAlignments, pName: "left", element: (const int *)&kv);
          kv = (KeyValues *)1;
          CUtlDict<int,int>::Insert(this: &this->m_TextAlignments, pName: "center", element: (const int *)&kv);
          kv = (KeyValues *)2;
          CUtlDict<int,int>::Insert(this: &this->m_TextAlignments, pName: "right", element: (const int *)&kv);
          v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v7 != nullptr )
            v3 = KeyValues::KeyValues(this: v7, setName: "G15");
          kv = v3;
          if ( filesystem != nullptr )
            v8 = &filesystem->IBaseFileSystem;
          else
            v8 = nullptr;
          if ( KeyValues::LoadFromFile(
                 this: v3,
                 filesystem: v8,
                 resourceName: "resource/g15.res",
                 pathID: "MOD",
                 pfnEvaluateSymbolProc: nullptr) )
          {
            title = KeyValues::GetString(this: v3, keyName: "game", defaultValue: "Source Engine");
            Int = KeyValues::GetInt(this: v3, keyName: "chatlines", defaultValue: this->m_nMaxChatHistory);
            if ( Int <= 1 )
              Int = 1;
            this->m_nMaxChatHistory = Int;
            CUtlString::operator=(this: &this->m_Title, src: title);
            v10 = CUtlString::operator char const *(this: &this->m_Title);
            this->m_lcd->Init(this: this->m_lcd, a2: v10);
            FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
            if ( FirstSubKey != nullptr )
            {
              do
              {
                Name = KeyValues::GetName(this: FirstSubKey);
                if ( _V_stricmp(s1: Name, s2: "game") != 0 )
                {
                  if ( _V_stricmp(s1: Name, s2: "icons") != 0 )
                  {
                    if ( _V_stricmp(s1: Name, s2: "replace") != 0 )
                    {
                      if ( _V_stricmp(s1: Name, s2: "page") == 0 )
                        CLCD::ParsePage(this, kv: FirstSubKey);
                    }
                    else
                    {
                      CLCD::ParseReplacements(this, kv: FirstSubKey);
                    }
                  }
                  else
                  {
                    CLCD::ParseIconMappings(this, kv: FirstSubKey);
                  }
                }
                FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
              }
              while ( FirstSubKey != nullptr );
              v3 = kv;
            }
          }
          KeyValues::deleteThis(this: v3);
          CLCD::UpdateChat(this);
          _Msg(a1: "Logitech LCD Keyboard initialized\n");
        }
        else
        {
          CLCD::Shutdown(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109880
// Name: public: void CLCD::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLCD::Update(CLCD *this@<ecx>, int a2@<edi>)
{
  C_BasePlayer *LocalPlayer; // eax
  int m_Size; // edi
  int m_nCurrentPage; // ebx
  C_BasePlayer *v6; // edx
  bool v7; // al
  bool v8; // cl
  char v9; // bl
  CLCDPage *v10; // eax
  int v11; // ebx
  CLCDPage **m_pMemory; // ecx
  int v13; // edx
  CLCDPage *v14; // edx
  bool v15; // bl
  unsigned int v16; // edi
  int m_nValue; // eax
  int v18; // [esp-8h] [ebp-18h]
  int dwCurTime_4; // [esp+8h] [ebp-8h]
  C_BasePlayer *player; // [esp+Ch] [ebp-4h]

  if ( this->m_lcd != nullptr )
  {
    v18 = a2;
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    m_Size = this->m_Pages.m_Size;
    m_nCurrentPage = this->m_nCurrentPage;
    v6 = LocalPlayer;
    v7 = LocalPlayer != nullptr;
    player = v6;
    v8 = v7 != this->m_bHadPlayer;
    this->m_bHadPlayer = v7;
    dwCurTime_4 = m_nCurrentPage;
    if ( m_Size <= 0 )
    {
      this->m_nCurrentPage = -1;
      this->m_nSubPage = 0;
    }
    else
    {
      v9 = 0;
      if ( v8 && v7 )
      {
        v9 = 1;
        this->m_nCurrentPage = 0;
        this->m_nSubPage = 0;
      }
      v10 = this->m_Pages.m_Memory.m_pMemory[this->m_nCurrentPage];
      if ( v10->m_bTitlePage && v6 != nullptr || v10->m_bRequiresPlayer && v6 == nullptr )
        v9 = 1;
      if ( ((unsigned __int8 (__thiscall *)(IG15 *, _DWORD, int))this->m_lcd->ButtonTriggered)(
             a1: this->m_lcd,
             a2: 0,
             a3: v18) != 0
        || v9 != 0 )
      {
        v11 = 0;
        this->m_nSubPage = 0;
        m_pMemory = this->m_Pages.m_Memory.m_pMemory;
        do
        {
          v13 = (this->m_nCurrentPage + 1) % m_Size;
          this->m_nCurrentPage = v13;
          v14 = m_pMemory[v13];
          if ( (!v14->m_bTitlePage || player == nullptr) && (!v14->m_bRequiresPlayer || player != nullptr) )
            break;
          ++v11;
        }
        while ( v11 < m_Size );
      }
      if ( this->m_lcd->ButtonTriggered(this: this->m_lcd, a2: 1) )
        this->m_nSubPage = (this->m_nSubPage + 1)
                         % this->m_Pages.m_Memory.m_pMemory[this->m_nCurrentPage]->m_nSubPageCount;
    }
    v15 = dwCurTime_4 != this->m_nCurrentPage;
    v16 = (__int64)(*(float *)gpGlobals.m_Index * 1000.0);
    if ( ((unsigned __int8 (__thiscall *)(IG15 *, int))this->m_lcd->IsConnected)(a1: this->m_lcd, a2: v18) != 0
      && (v16 >= this->m_dwNextUpdateTime || v15) )
    {
      if ( g15_update_msec.m_pParent != nullptr )
        m_nValue = g15_update_msec.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      this->m_dwNextUpdateTime = v16 + m_nValue;
      CLCD::DisplayCurrentPage(this, dwCurTime: v16);
    }
    ((void (__thiscall *)(IG15 *))this->m_lcd->UpdateLCD)(a1: this->m_lcd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109A00
// Name: g15_reload
// Source: json
//------------------------------------------------------------------------------
void __cdecl g15_reload()
{
  int v0; // eax

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-g15") != 0 )
  {
    CLCD::Shutdown(this: &gLCD);
    _Msg(a1: "Reloading G15 config\n");
    CLCD::Init(this: &gLCD);
  }
  else
  {
    _Msg(a1: "Must run with -g15 to enable support for the LCD Keyboard\n");
  }
}
