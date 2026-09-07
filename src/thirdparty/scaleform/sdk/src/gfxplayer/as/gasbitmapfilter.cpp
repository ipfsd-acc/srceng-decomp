// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasbitmapfilter.cpp
// Functions: 5
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasbitmapfilter.h"

//------------------------------------------------------------------------------
// Address: 0x101064D0
// Name: protected: virtual GASBitmapFilterObject::~GASBitmapFilterObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASBitmapFilterObject::~GASBitmapFilterObject(GASObject *this)
{
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASBitmapFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBitmapFilterObject::`vftable'{for `GASObjectInterface'};
  GASObject::~GASObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x101064F0
// Name: public: virtual enum GASObjectInterface::ObjectType GASBitmapFilterObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASBitmapFilterObject::GetObjectType()
{
  return 37;
}

//------------------------------------------------------------------------------
// Address: 0x10106550
// Name: public: GASBitmapFilterObject::GASBitmapFilterObject(class GASEnvironment __near *,enum GFxFilterDesc::FilterType,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GASBitmapFilterObject *__thiscall GASBitmapFilterObject::GASBitmapFilterObject(
        GASBitmapFilterObject *this,
        struct GASEnvironment *a2,
        enum FilterType a3,
        struct GFxSocketImplFactory *blurMode)
{
  GASObject::GASObject((GASObject *)this, a2);
  *this = (GASBitmapFilterObject)&GASBitmapFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(this + 4) = (GASBitmapFilterObject)&GASBitmapFilterObject::`vftable'{for `GASObjectInterface'};
  *((float *)this + 16) = 5.0;
  *((float *)this + 17) = 5.0;
  *(this + 15) = nullptr;
  *(this + 18) = (GASBitmapFilterObject)1;
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 23) = 1.0;
  GRenderer::Cxform::Cxform(this: (float *)this + 24);
  *((_BYTE *)this + 52) = a3;
  *(this + 15) = blurMode;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101065B0
// Name: public: static class GASBitmapFilterObject __near * GASBitmapFilterObject::CreateFromDesc(class GASEnvironment __near *,struct GFxFilterDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASBitmapFilterObject::CreateFromDesc(
        const GFxAmpCurrentState *penv,
        __vc_attributes::idl_quoteAttribute *a2,
        _BYTE *a3)
{
  char v3; // al
  int v4; // edx
  struct GASObject *v5; // eax

  v3 = *a3 & 0xF;
  if ( v3 == 1 )
  {
    v4 = 40;
  }
  else if ( v3 != 0 )
  {
    switch ( v3 )
    {
      case 2:
        v4 = 39;
        break;
      case 3:
        v4 = 41;
        break;
      case 6:
        v4 = 42;
        break;
      default:
        return;
    }
  }
  else
  {
    v4 = 38;
  }
  v5 = GASEnvironment::OperatorNew(
         this: a2,
         a2: (int)a3,
         a3: *((struct GASObject **)a2[30].text + 169),
         a4: (const struct GASString *)&a2[30].text[4 * v4 + 8],
         nargs: 0,
         argsTopOff: -1);
  if ( v5 != nullptr )
    GFxFilterDesc::operator=(this: &v5[6].sequence, a2: (int)a3);
}

//------------------------------------------------------------------------------
// Address: 0x101067C0
// Name: public: static class GASFunctionRef GASBitmapFilterCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASBitmapFilterCtorFunction::Register(
        struct GASFunctionRef *a1,
        _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  GASCFunctionObject *v7; // eax
  struct GASFunctionRef *v8; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, struct GASFunctionRef **); // edx
  int v11; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  const char *MinVal; // edx
  GASValue *v14; // eax
  GASValue v16[4]; // [esp+Ch] [ebp-1Ch] BYREF
  _KCRM_MARSHAL_HEADER *v17; // [esp+1Ch] [ebp-Ch] BYREF
  char v18; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v17 = pgc;
  v18 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(this: v5, func: (_REASON_CONTEXT *)&v17, a3: nullptr);
    v6->dwSize = (unsigned int)&GASSelectionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  v8 = a1;
  *(_DWORD *)a1 = v7;
  *((_BYTE *)v8 + 8) = 0;
  *((_DWORD *)v8 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a1 = (struct GASFunctionRef *)323;
  v11 = v10(a1: MaxVal, a2: 240, a3: &a1);
  if ( v11 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASBitmapFilterObject,GASEnvironment>::GASPrototype<GASBitmapFilterObject,GASEnvironment>(
      this: (D3DXMATRIX *)v11,
      psc: (struct GASStringContext *)&v17,
      psc_4: Prototype,
      psc_8: (unsigned int)v8);
    *(_DWORD *)v11 = &GASPrototype<GASBitmapFilterObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v11 + 16) = &GASPrototype<GASBitmapFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v11 + 208) = &GASPrototype<GASBitmapFilterObject,GASEnvironment>::`vftable';
  }
  else
  {
    v11 = 0;
  }
  if ( v11 != 0 )
    *(_DWORD *)(v11 + 8) = (*(_DWORD *)(v11 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 37, a4: v11);
  MinVal = v2[56].MinVal;
  HIBYTE(pgc) = 0;
  v19 = *((_DWORD *)MinVal + 4);
  v14 = GASValue::GASValue(this: v16, a2: (int)v2, a3: v8);
  (*(void (__thiscall **)(const char *, _KCRM_MARSHAL_HEADER **, vc_attributes::PreRangeAttribute *, GASValue *, char *))(v19 + 40))(
    a1: v2[56].MinVal + 16,
    a2: &v17,
    a3: v2 + 13,
    a4: v14,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v16, a2: (int)v2);
  if ( v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2: (int)v2);
  return v8;
}
