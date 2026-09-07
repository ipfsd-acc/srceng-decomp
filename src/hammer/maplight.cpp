// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/maplight.cpp
// Functions: 4
// ============================================================

#include "hammer\maplight.h"

//------------------------------------------------------------------------------
// Address: 0x10130F80
// Name: public: virtual char const __near * CMapLight::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLight::GetType(CMapLight *this)
{
  return CMapLight::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10130F90
// Name: public: virtual int CMapLight::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapLight::IsMapClass(CMapLight *this, const char *Type)
{
  return Type == CMapLight::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10131010
// Name: public: static class CMapClass __near * CMapLight::CreateMapLight(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapLight::CreateMapLight()
{
  CMapClass *v0; // eax
  _DWORD *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0xD8u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  *v1 = &CMapHelper::`vftable';
  *v1 = &CMapLight::`vftable';
  return (CMapClass *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101310A0
// Name: public: virtual class CMapClass __near * CMapLight::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapLight::Copy(CMapLight *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0xD8u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapLight::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}
