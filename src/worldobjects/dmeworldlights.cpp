// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: worldobjects/dmeworldlights.cpp
// Functions: 102
// ============================================================

#include "worldobjects\dmeworldlights.h"

//------------------------------------------------------------------------------
// Address: 0x00657D10
// Name: protected: void CDmeWorldPointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldPointLight::OnConstruction(CDmeWorldPointLight *this)
{
  this->m_lightName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "lightName",
                                     type: AT_STRING,
                                     pMemory: &this->m_lightName);
  this->m_vOrigin.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "origin",
                                   type: AT_VECTOR3,
                                   pMemory: &this->m_vOrigin);
  this->m_vColor.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "color",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vColor);
  this->m_flRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "radius",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flRadius);
  this->m_vAttenuation.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "attenuation",
                                        type: AT_VECTOR3,
                                        pMemory: &this->m_vAttenuation);
}

//------------------------------------------------------------------------------
// Address: 0x00657D80
// Name: protected: void CDmeWorldHemiLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldHemiLight::OnConstruction(CDmeWorldHemiLight *this)
{
  this->m_lightName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "lightName",
                                     type: AT_STRING,
                                     pMemory: &this->m_lightName);
  this->m_vTransform0.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform0",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform0);
  this->m_vTransform1.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform1",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform1);
  this->m_vTransform2.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform2",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform2);
  this->m_vColor.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "color",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vColor);
  this->m_flRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "radius",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flRadius);
  this->m_vAttenuation.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "attenuation",
                                        type: AT_VECTOR3,
                                        pMemory: &this->m_vAttenuation);
}

//------------------------------------------------------------------------------
// Address: 0x00657E30
// Name: protected: void CDmeWorldSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldSpotLight::OnConstruction(CDmeWorldSpotLight *this)
{
  this->m_lightName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "lightName",
                                     type: AT_STRING,
                                     pMemory: &this->m_lightName);
  this->m_vTransform0.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform0",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform0);
  this->m_vTransform1.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform1",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform1);
  this->m_vTransform2.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform2",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform2);
  this->m_vColor.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "color",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vColor);
  this->m_flRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "radius",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flRadius);
  this->m_vAttenuation.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "attenuation",
                                        type: AT_VECTOR3,
                                        pMemory: &this->m_vAttenuation);
  this->m_flCosSpot.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "cosSpot",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flCosSpot);
}

//------------------------------------------------------------------------------
// Address: 0x00657F80
// Name: public: virtual bool CDmeWorldPointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeWorldPointLight::IsA(CDmeWorldPointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeWorldPointLight::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657FB0
// Name: public: virtual int CDmeWorldPointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldPointLight::GetInheritanceDepth(CDmeWorldPointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeWorldPointLight::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657FF0
// Name: protected: virtual int CDmeWorldPointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldPointLight::AllocatedSize(CDmeWorldPointLight *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x00658000
// Name: protected: virtual void CDmeWorldPointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldPointLight::PerformConstruction(CDmeWorldPointLight *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeWorldPointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00658110
// Name: protected: CDmeWorldHemiLight::CDmeWorldHemiLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeWorldHemiLight *__thiscall CDmeWorldHemiLight::CDmeWorldHemiLight(
        CDmeWorldHemiLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeWorldHemiLight_vtbl *)&CDmeWorldHemiLight::`vftable';
  this->m_lightName.m_Storage.u.m_Id = -1;
  this->m_lightName.m_pAttribute = nullptr;
  this->m_vTransform0.m_pAttribute = nullptr;
  this->m_vTransform0.m_Storage.x = 0.0;
  this->m_vTransform0.m_Storage.y = 0.0;
  this->m_vTransform0.m_Storage.z = 0.0;
  this->m_vTransform0.m_Storage.w = 0.0;
  this->m_vTransform1.m_pAttribute = nullptr;
  this->m_vTransform1.m_Storage.x = 0.0;
  this->m_vTransform1.m_Storage.y = 0.0;
  this->m_vTransform1.m_Storage.z = 0.0;
  this->m_vTransform1.m_Storage.w = 0.0;
  this->m_vTransform2.m_pAttribute = nullptr;
  this->m_vTransform2.m_Storage.x = 0.0;
  this->m_vTransform2.m_Storage.y = 0.0;
  this->m_vTransform2.m_Storage.z = 0.0;
  this->m_vTransform2.m_Storage.w = 0.0;
  this->m_vColor.m_pAttribute = nullptr;
  this->m_vColor.m_Storage.x = 0.0;
  this->m_vColor.m_Storage.y = 0.0;
  this->m_vColor.m_Storage.z = 0.0;
  this->m_flRadius = 0;
  this->m_vAttenuation.m_pAttribute = nullptr;
  this->m_vAttenuation.m_Storage.x = 0.0;
  this->m_vAttenuation.m_Storage.y = 0.0;
  this->m_vAttenuation.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00658220
// Name: public: virtual bool CDmeWorldHemiLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeWorldHemiLight::IsA(CDmeWorldHemiLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeWorldHemiLight::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00658250
// Name: public: virtual int CDmeWorldHemiLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldHemiLight::GetInheritanceDepth(CDmeWorldHemiLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeWorldHemiLight::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006582D0
// Name: protected: virtual void CDmeWorldHemiLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldHemiLight::PerformConstruction(CDmeWorldHemiLight *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeWorldHemiLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00658340
// Name: protected: CDmeWorldSpotLight::CDmeWorldSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeWorldSpotLight *__thiscall CDmeWorldSpotLight::CDmeWorldSpotLight(
        CDmeWorldSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeWorldSpotLight_vtbl *)&CDmeWorldSpotLight::`vftable';
  this->m_lightName.m_Storage.u.m_Id = -1;
  this->m_lightName.m_pAttribute = nullptr;
  this->m_vTransform0.m_pAttribute = nullptr;
  this->m_vTransform0.m_Storage.x = 0.0;
  this->m_vTransform0.m_Storage.y = 0.0;
  this->m_vTransform0.m_Storage.z = 0.0;
  this->m_vTransform0.m_Storage.w = 0.0;
  this->m_vTransform1.m_pAttribute = nullptr;
  this->m_vTransform1.m_Storage.x = 0.0;
  this->m_vTransform1.m_Storage.y = 0.0;
  this->m_vTransform1.m_Storage.z = 0.0;
  this->m_vTransform1.m_Storage.w = 0.0;
  this->m_vTransform2.m_pAttribute = nullptr;
  this->m_vTransform2.m_Storage.x = 0.0;
  this->m_vTransform2.m_Storage.y = 0.0;
  this->m_vTransform2.m_Storage.z = 0.0;
  this->m_vTransform2.m_Storage.w = 0.0;
  this->m_vColor.m_pAttribute = nullptr;
  this->m_vColor.m_Storage.x = 0.0;
  this->m_vColor.m_Storage.y = 0.0;
  this->m_vColor.m_Storage.z = 0.0;
  this->m_flRadius = 0;
  this->m_vAttenuation.m_pAttribute = nullptr;
  this->m_vAttenuation.m_Storage.x = 0.0;
  this->m_vAttenuation.m_Storage.y = 0.0;
  this->m_vAttenuation.m_Storage.z = 0.0;
  this->m_flCosSpot = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00658450
// Name: public: virtual bool CDmeWorldSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeWorldSpotLight::IsA(CDmeWorldSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeWorldSpotLight::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00658480
// Name: public: virtual int CDmeWorldSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldSpotLight::GetInheritanceDepth(CDmeWorldSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeWorldSpotLight::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00658510
// Name: protected: virtual void CDmeWorldSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldSpotLight::PerformConstruction(CDmeWorldSpotLight *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeWorldSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BB3F0
// Name: _dynamic_initializer_for__CDmeWorldPointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeWorldPointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeWorldPointLight::s_Allocator,
    blockSize: 0x84u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeWorldPointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeWorldPointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB450
// Name: _dynamic_initializer_for__CDmeWorldHemiLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeWorldHemiLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeWorldHemiLight::s_Allocator,
    blockSize: 0xB0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeWorldHemiLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeWorldHemiLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB4B0
// Name: _dynamic_initializer_for__CDmeWorldSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeWorldSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeWorldSpotLight::s_Allocator,
    blockSize: 0xB8u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeWorldSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeWorldSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC50
// Name: _dynamic_atexit_destructor_for__CDmeWorldPointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeWorldPointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeWorldPointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC60
// Name: _dynamic_atexit_destructor_for__CDmeWorldHemiLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeWorldHemiLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeWorldHemiLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC70
// Name: _dynamic_atexit_destructor_for__CDmeWorldSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeWorldSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeWorldSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006585A0
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x65BCD6);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00658630
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006586AA
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00658731
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006587DC
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x006587EF
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x00658805
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x00658933
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0065894A
// Name: ___libm_sse2_tanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float __usercall __libm_sse2_tanf@<st0>(__m128i a1@<xmm0>)
{
  double v1; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 1) & 0x7FFF) - 128) >= 18176
    && (_mm_cvtsi128_si32(a1) & 0x7F800000) != 0x7F800000 )
  {
    return tan(X: *(float *)a1.m128i_i32);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00658AEA
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: *data, str: (int)stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = _fileno(stream);
  v11 = _write(fh: v10, buf: (char *)data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x00658C41
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fwrite(unsigned __int8 *buffer, unsigned int size, unsigned int count, _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( size == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fwrite_nolock(buffer, size, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00658D10
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x00658D50
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd(v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00658E30
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00658E39
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x00658E4C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00658E66
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00658EE0
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(__m128i *dst, const __m128i *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  __m128i *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = (unsigned __int8 *)src;
  v4 = dst;
  if ( dst > src && dst < (__m128i *)&src->m128i_i8[count] )
  {
    v6 = &src->m128i_u8[count - 4];
    v7 = &dst->m128i_u8[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = (unsigned __int8 *)src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(a1: count, a2: dst, a3: src);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 00658F39 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *((_DWORD *)&v4[-1] + v5 - 3) = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *((_DWORD *)&v4[-1] + v5 - 2) = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *((_DWORD *)&v4[-1] + v5 - 1) = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        v4[-1].m128i_i32[v5] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        v4->m128i_i32[v5 - 3] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        v4->m128i_i32[v5 - 2] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        v4->m128i_i32[v5 - 1] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            v4->m128i_i8[0] = *v3;
            break;
          case 2u:
TrailUp2:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            v4->m128i_i8[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00659250
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x6662E8);
  }
  JUMPOUT(0x6592DF);
}

//------------------------------------------------------------------------------
// Address: 0x00659290
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(int a1, int a2)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v3 = _mm_getcsr() & 0x7F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIacos_pentium4();
  else
__CIacos:
    _CIacos_default(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x006592CB
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00659396
// Name: _srand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl srand(unsigned int seed)
{
  _getptd()->_holdrand = seed;
}

//------------------------------------------------------------------------------
// Address: 0x006593A8
// Name: _rand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl rand()
{
  _tiddata *v0; // ecx
  unsigned int v1; // eax

  v0 = _getptd();
  v1 = 214013 * v0->_holdrand + 2531011;
  v0->_holdrand = v1;
  return HIWORD(v1) & 0x7FFF;
}

//------------------------------------------------------------------------------
// Address: 0x006593C9
// Name: ___libm_sse2_cosf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float __usercall __libm_sse2_cosf@<st0>(__m128i a1@<xmm0>)
{
  double v1; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 1) & 0x7FFF) - 128) >= 17792
    && (_mm_cvtsi128_si32(a1) & 0x7F800000) != 0x7F800000 )
  {
    return cos(X: *(float *)a1.m128i_i32);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00659520
// Name: ___libm_sse2_sinf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float __usercall __libm_sse2_sinf@<st0>(__m128i a1@<xmm0>)
{
  double v1; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 1) & 0x7FFF) - 128) >= 17792
    && (_mm_cvtsi128_si32(a1) & 0x7F800000) != 0x7F800000 )
  {
    return sin(X: *(float *)a1.m128i_i32);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0065966F
// Name: ___libm_sse2_acosf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_acosf()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00659A4C
// Name: ___libm_sse2_tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_tan@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 14368) > 2216
    && COERCE_DOUBLE(*(_QWORD *)sign_mask & X.m128i_i64[0] ^ X.m128i_i64[0]) != *(double *)INF )
  {
    return tan(X: *(double *)X.m128i_i64);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00659CA1
// Name: ___libm_sse2_cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_cos@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return cos(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00659E4C
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00659EBA
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(
           string,
           inputfn: (int (__cdecl *)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *))_input_l,
           format,
           plocinfo: nullptr,
           arglist);
}

//------------------------------------------------------------------------------
// Address: 0x00659EDC
// Name: _sscanf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf_s(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_s_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x00659F00
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x00659F40
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldiv(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v3; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = v6 / v5;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    return v8;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % (unsigned int)a2;
    return v3 / (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00659FA8
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065A015
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065A089
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned __int8 *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  unsigned __int8 *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: (unsigned __int8 *)stream->_ptr, count: v9);
            stream->_cnt -= v9;
            stream->_ptr += v9;
            data += v9;
            v7 -= v9;
            dataSize -= v9;
            v6 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v7 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_41;
        v17 = v12;
        v13 = _fileno(stream);
        v14 = _read(fh: v13, buf: (char *)data, cnt: v17);
        if ( v14 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v6 - v7) / elementSize;
        }
        if ( v14 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_39:
        if ( v7 == 0 )
          return num;
      }
      v15 = _filbuf(str: stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize != 0 )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(dst: (int)buffer, value: nullptr, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x0065A245
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0065A2D3
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(unsigned __int8 *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x0065A2F0
// Name: __fseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseeki64_nolock(_iobuf *str, __int64 offset, unsigned int whence)
{
  int flag; // eax
  DWORD v4; // edi
  __int64 v5; // rax
  int v6; // eax
  int v7; // eax
  doubleint v8; // rax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 && (v4 = whence, whence <= 2) )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      LODWORD(v5) = _ftelli64_nolock(str);
      offset += v5;
      v4 = 0;
    }
    _flush(str);
    v6 = str->_flag;
    if ( (v6 & 0x80u) == 0 )
    {
      if ( (v6 & 1) != 0 && (v6 & 8) != 0 && (v6 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v6 & 0xFFFFFFFC;
    }
    v7 = _fileno(stream: str);
    v8.bigint = _lseeki64(fh: v7, pos: offset, mthd: v4).bigint;
    if ( (v8.twoints.upperhalf & v8.twoints.lowerhalf) != -1 )
      return 0;
  }
  else
  {
    *_errno() = 22;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0065A38C
// Name: __fseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseeki64(_iobuf *stream, __int64 offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseeki64_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065A40B
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: (int)&ms_exc.registration, a3: 0xFFFFFFFE);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0065A4C7
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x0065A4DE
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, (int)&str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065A570
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x0065A59B
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = _fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065A6B0
// Name: shortsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edx
  char *v5; // edi
  unsigned int v6; // ecx
  char *v7; // esi
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(a1: v7, a2: v8) > 0 )
            v8 = v7;
          v7 += width;
        }
        while ( v7 <= v5 );
        v6 = width;
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 != 0 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          *v10++ = v12;
          --v9;
        }
        while ( v9 != 0 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065A740
// Name: _qsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edi
  unsigned int v5; // ebx
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // ebx
  unsigned int v9; // edx
  char *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  char *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  char *v19; // eax
  int v20; // ecx
  char *v21; // eax
  char *v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  char *v26; // edx
  char *v27; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v30; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v4 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v5 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(hi: v6, lo: v4, width: v5, comp);
        goto LABEL_57;
      }
      v8 = &v4[(v7 >> 1) * v5];
      if ( comp(a1: v4, a2: v8) > 0 )
      {
        v9 = width;
        v10 = v8;
        if ( v4 != v8 )
        {
          v11 = v4 - v8;
          do
          {
            v30 = v9 - 1;
            base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = base_3;
            v9 = v30;
            ++v10;
          }
          while ( v30 != 0 );
        }
      }
      if ( comp(a1: v4, a2: v6) > 0 )
      {
        v12 = width;
        v13 = v6;
        if ( v4 != v6 )
        {
          v14 = v4 - v6;
          do
          {
            base_3a = v13[v14];
            v13[v14] = *v13;
            *v13++ = base_3a;
            --v12;
          }
          while ( v12 != 0 );
          v4 = lo;
        }
      }
      if ( comp(a1: v8, a2: v6) > 0 )
      {
        v15 = width;
        v16 = v6;
        if ( v8 != v6 )
        {
          v17 = v8 - v6;
          do
          {
            base_3b = v16[v17];
            v16[v17] = *v16;
            *v16++ = base_3b;
            --v15;
          }
          while ( v15 != 0 );
          v4 = lo;
        }
      }
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += width;
            if ( v4 >= v8 )
              break;
            if ( comp(a1: v4, a2: v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_32;
              goto LABEL_30;
            }
          }
        }
        do
LABEL_30:
          v4 += width;
        while ( v4 <= hi && comp(a1: v4, a2: v8) <= 0 );
        do
LABEL_32:
          v6 -= width;
        while ( v6 > v8 && comp(a1: v6, a2: v8) > 0 );
        if ( v4 > v6 )
          break;
        v18 = width;
        v19 = v6;
        if ( v4 != v6 )
        {
          v20 = v4 - v6;
          do
          {
            v30 = v18 - 1;
            base_3c = v19[v20];
            v19[v20] = *v19;
            *v19 = base_3c;
            v18 = v30;
            ++v19;
          }
          while ( v30 != 0 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += width;
      if ( v8 >= v6 )
        goto LABEL_44;
      do
      {
        v6 -= width;
        if ( v6 <= v8 )
          goto LABEL_44;
      }
      while ( comp(a1: v6, a2: v8) == 0 );
      if ( v8 < v6 )
      {
LABEL_46:
        v21 = lo;
      }
      else
      {
LABEL_44:
        while ( 1 )
        {
          v6 -= width;
          v21 = lo;
          if ( v6 <= lo )
            break;
          if ( comp(a1: v6, a2: v8) != 0 )
            goto LABEL_46;
        }
      }
      v22 = hi;
      if ( v6 - v21 < hi - v4 )
      {
        if ( v4 < hi )
        {
          v24 = stkptr;
          lostk[stkptr] = v4;
          histk[v24] = v22;
          stkptr = v24 + 1;
        }
        if ( v21 >= v6 )
          goto LABEL_56;
        v4 = lo;
        v5 = width;
        hi = v6;
      }
      else
      {
        if ( v21 < v6 )
        {
          v23 = stkptr;
          lostk[stkptr] = v21;
          histk[v23] = v6;
          stkptr = v23 + 1;
        }
        if ( v4 >= v22 )
        {
LABEL_56:
          v5 = width;
LABEL_57:
          v25 = --stkptr;
          if ( stkptr < 0 )
            return;
          v26 = lostk[v25];
          v27 = histk[v25];
          lo = v26;
          hi = v27;
          v6 = v27;
          v4 = v26;
        }
        else
        {
          v6 = hi;
          v5 = width;
          lo = v4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065A9D0
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( ((unsigned int)&unk_FF0000 & v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x0065AB00
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _alloca_probe_16@<eax>(int a1@<eax>, int a2@<ecx>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a1) & 0xF;
  return _chkstk(a1: __CFADD__(v3, a1) ? -1 : v3 + a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0065AB2C
// Name: _strtok
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strtok(char *string, const char *control)
{
  char v3; // dl
  char *token; // edx
  char *v5; // ebx
  _tiddata *ptd; // [esp+10h] [ebp-28h]
  unsigned __int8 map[32]; // [esp+14h] [ebp-24h] BYREF

  ptd = _getptd();
  memset(map, 0, sizeof(map));
  do
  {
    v3 = *control;
    map[*(unsigned __int8 *)control >> 3] |= 1 << (*control & 7);
    ++control;
  }
  while ( v3 != 0 );
  token = string;
  if ( string == nullptr )
    token = ptd->_token;
  while ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 && *token != 0 )
    ++token;
  v5 = token;
  while ( *token != 0 )
  {
    if ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 )
    {
      *token++ = 0;
      break;
    }
    ++token;
  }
  ptd->_token = token;
  return token != v5 ? v5 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0065ABF0
// Name: _floor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _floor_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _floor_pentium4(X);
  else
    return _floor_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x0065AC30
// Name: __floor_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _floor_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmplt_pd(v9, v8).m128d_f64[0];
    if ( v3 < 3071 )
    {
      a1.m128i_i64[0] = (*(_QWORD *)&_mm_cmplt_pd(v9, *(__m128d *)&NegZero_0).m128d_f64[0] | NegZero_0) & NegOne;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 3122 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] - COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
  else
  {
    if ( v3 >= 1023 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 1074 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065AD11
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: &v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065ADB8
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x0065AE00
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(__m128i *dst, const __m128i *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  __m128i *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = (unsigned __int8 *)src;
  v4 = dst;
  if ( dst > src && dst < (__m128i *)&src->m128i_i8[count] )
  {
    v6 = &src->m128i_u8[count - 4];
    v7 = &dst->m128i_u8[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = (unsigned __int8 *)src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(a1: count, a2: dst, a3: src);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 0065AE59 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *((_DWORD *)&v4[-1] + v5 - 3) = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *((_DWORD *)&v4[-1] + v5 - 2) = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *((_DWORD *)&v4[-1] + v5 - 1) = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        v4[-1].m128i_i32[v5] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        v4->m128i_i32[v5 - 3] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        v4->m128i_i32[v5 - 2] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        v4->m128i_i32[v5 - 1] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 = (__m128i *)((char *)v4 + 4 * v5);
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            v4->m128i_i8[0] = *v3;
            break;
          case 2u:
TrailUp2_0:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            v4->m128i_i8[0] = *v3;
            v4->m128i_i8[1] = v3[1];
            v4->m128i_i8[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065B161
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0065B20D
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x006BB420
// Name: _dynamic_initializer_for__g_CDmeWorldPointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeWorldPointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeWorldPointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB430
// Name: _dynamic_initializer_for__g_CDmeWorldPointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeWorldPointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeWorldPointLight_Helper,
           classname: "DmeWorldPointLight",
           pFactory: &g_CDmeWorldPointLight_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BB480
// Name: _dynamic_initializer_for__g_CDmeWorldHemiLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeWorldHemiLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeWorldHemiLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB490
// Name: _dynamic_initializer_for__g_CDmeWorldHemiLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeWorldHemiLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeWorldHemiLight_Helper,
           classname: "DmeWorldHemiLight",
           pFactory: &g_CDmeWorldHemiLight_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BB4E0
// Name: _dynamic_initializer_for__g_CDmeWorldSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeWorldSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeWorldSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB4F0
// Name: _dynamic_initializer_for__g_CDmeWorldSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeWorldSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeWorldSpotLight_Helper,
           classname: "DmeWorldSpotLight",
           pFactory: &g_CDmeWorldSpotLight_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BB510
// Name: sub_6BB510
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_6BB510()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_7453C5C = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x006BB530
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuaternionPool__()
{
  if ( ((unsigned __int8)&g_QuaternionPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_QuaternionPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_QuaternionPool__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB560
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VectorPool__()
{
  if ( ((unsigned __int8)&g_VectorPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_VectorPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_VectorPool__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB590
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatrixPool__()
{
  if ( ((unsigned __int8)&g_MatrixPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_MatrixPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_MatrixPool__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB5C0
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB600
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB630
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB660
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC80
// Name: _dynamic_atexit_destructor_for__g_CDmeWorldHemiLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeWorldHemiLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeWorldHemiLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC90
// Name: _dynamic_atexit_destructor_for__g_CDmeWorldSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeWorldSpotLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeWorldSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDCA0
// Name: _dynamic_atexit_destructor_for__g_CDmeWorldPointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeWorldPointLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeWorldPointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDCB0
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x006BDCC0
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x006BDCD0
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x006BDCE0
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x006BDD10
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x006BDD20
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x006BDD30
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}
