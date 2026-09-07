// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/precache.cpp
// Functions: 8
// ============================================================

#include "engine\precache.h"

//------------------------------------------------------------------------------
// Address: 0x101CC3C0
// Name: char const __near * GetFlagString(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetFlagString(int flags)
{
  char v1; // al

  ret[0] = 0;
  v1 = 1;
  if ( flags == 0 )
    return "None";
  if ( (flags & 1) != 0 )
  {
    V_strncat(pDest: ret, pSrc: "RES_FATALIFMISSING", destBufferSize: 0x200u, max_chars_to_copy: -1);
    v1 = 0;
  }
  if ( (flags & 2) != 0 )
  {
    if ( v1 == 0 )
      V_strncat(pDest: ret, pSrc: " | ", destBufferSize: 0x200u, max_chars_to_copy: -1);
    V_strncat(pDest: ret, pSrc: "RES_PRELOAD", destBufferSize: 0x200u, max_chars_to_copy: -1);
  }
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x101CC440
// Name: public: class CSfxTable __near * CPrecacheItem::GetSound(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPrecacheItem::GetSound(CPrecacheItem *this)
{
  const char *result; // eax

  result = this->u.generic;
  if ( result != nullptr )
    *(_DWORD *)this = *(_DWORD *)this & 7 ^ ((*(_DWORD *)this & 0xFFFFFFF8) + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CC460
// Name: public: void CPrecacheItem::SetModel(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetModel(CPrecacheItem *this, const model_t *pmodel)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 1;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)pmodel;
  if ( pmodel != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC480
// Name: public: void CPrecacheItem::SetGeneric(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetGeneric(CPrecacheItem *this, const char *pname)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 3;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)pname;
  if ( pname != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC4A0
// Name: public: void CPrecacheItem::SetSound(class CSfxTable const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetSound(CPrecacheItem *this, const char *name)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 2;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)name;
  if ( name != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC4C0
// Name: public: void CPrecacheItem::SetDecal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetDecal(CPrecacheItem *this, const char *decalname)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 4;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)decalname;
  if ( decalname != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC4F0
// Name: public: unsigned int CPrecacheItem::GetReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPrecacheItem::GetReferenceCount(CPrecacheItem *this)
{
  return *(_DWORD *)this >> 3;
}

//------------------------------------------------------------------------------
// Address: 0x101CC500
// Name: public: CPrecacheItem::CPrecacheItem(void)
// Source: json
//------------------------------------------------------------------------------
CPrecacheItem *__thiscall CPrecacheItem::CPrecacheItem(CPrecacheItem *this)
{
  this->u.model = nullptr;
  *(_DWORD *)this = 0;
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101CC790
// Name: char const __near * GetFlagString(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetFlagString(int flags)
{
  char v1; // al

  ret[0] = 0;
  v1 = 1;
  if ( flags == 0 )
    return "None";
  if ( (flags & 1) != 0 )
  {
    V_strncat(pDest: ret, pSrc: "RES_FATALIFMISSING", destBufferSize: 0x200u, max_chars_to_copy: -1);
    v1 = 0;
  }
  if ( (flags & 2) != 0 )
  {
    if ( v1 == 0 )
      V_strncat(pDest: ret, pSrc: " | ", destBufferSize: 0x200u, max_chars_to_copy: -1);
    V_strncat(pDest: ret, pSrc: "RES_PRELOAD", destBufferSize: 0x200u, max_chars_to_copy: -1);
  }
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x101CC810
// Name: public: class CSfxTable __near * CPrecacheItem::GetSound(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPrecacheItem::GetSound(CPrecacheItem *this)
{
  const char *result; // eax

  result = this->u.generic;
  if ( result != nullptr )
    *(_DWORD *)this = *(_DWORD *)this & 7 ^ ((*(_DWORD *)this & 0xFFFFFFF8) + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CC830
// Name: public: void CPrecacheItem::SetModel(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetModel(CPrecacheItem *this, const model_t *pmodel)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 1;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)pmodel;
  if ( pmodel != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC850
// Name: public: void CPrecacheItem::SetGeneric(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetGeneric(CPrecacheItem *this, const char *pname)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 3;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)pname;
  if ( pname != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC870
// Name: public: void CPrecacheItem::SetSound(class CSfxTable const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetSound(CPrecacheItem *this, const char *name)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 2;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)name;
  if ( name != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC890
// Name: public: void CPrecacheItem::SetDecal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheItem::SetDecal(CPrecacheItem *this, const char *decalname)
{
  unsigned int v2; // eax

  v2 = *(_DWORD *)this & 0xFFFFFFF8 | 4;
  *(_DWORD *)this = v2;
  this->u.model = (model_t *)decalname;
  if ( decalname != nullptr )
    *(_DWORD *)this = v2 & 7;
}

//------------------------------------------------------------------------------
// Address: 0x101CC8B0
// Name: public: unsigned int CPrecacheItem::GetReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPrecacheItem::GetReferenceCount(CPrecacheItem *this)
{
  return *(_DWORD *)this >> 3;
}

//------------------------------------------------------------------------------
// Address: 0x101CC8C0
// Name: public: CPrecacheItem::CPrecacheItem(void)
// Source: json
//------------------------------------------------------------------------------
CPrecacheItem *__thiscall CPrecacheItem::CPrecacheItem(CPrecacheItem *this)
{
  this->u.model = nullptr;
  *(_DWORD *)this = 0;
  return this;
}

} // namespace engine_xlsp
