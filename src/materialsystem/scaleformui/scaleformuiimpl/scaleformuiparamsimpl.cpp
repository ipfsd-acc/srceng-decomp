// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuiparamsimpl.cpp
// Functions: 19
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuiparamsimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10013740
// Name: public: virtual void __near * ScaleformUIImpl::Params_GetArgs(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformUIImpl::Params_GetArgs(ScaleformUIImpl *this, _DWORD *params)
{
  return (void *)params[4];
}

//------------------------------------------------------------------------------
// Address: 0x10013750
// Name: public: virtual unsigned int ScaleformUIImpl::Params_GetNumArgs(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ScaleformUIImpl::Params_GetNumArgs(ScaleformUIImpl *this, _DWORD *params)
{
  return params[5];
}

//------------------------------------------------------------------------------
// Address: 0x10013760
// Name: public: virtual void __near * ScaleformUIImpl::Params_GetArg(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::Params_GetArg(ScaleformUIImpl *this, _DWORD *params, int index)
{
  return params[4] + 16 * index;
}

//------------------------------------------------------------------------------
// Address: 0x10013780
// Name: public: virtual enum IScaleformUI::ValueType ScaleformUIImpl::Params_GetArgType(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::Params_GetArgType(ScaleformUIImpl *this, _DWORD *params, int index)
{
  return *(_DWORD *)(params[4] + 16 * index + 4) & 0x8F;
}

//------------------------------------------------------------------------------
// Address: 0x100137A0
// Name: public: virtual bool ScaleformUIImpl::Params_ArgIs(void __near *,unsigned int,enum IScaleformUI::ValueType)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::Params_ArgIs(
        ScaleformUIImpl *this,
        _DWORD *params,
        unsigned int index,
        IScaleformUI::ValueType v)
{
  return index < params[5] && (*(_DWORD *)(params[4] + 16 * index + 4) & 0x8F) == v;
}

//------------------------------------------------------------------------------
// Address: 0x100137D0
// Name: public: virtual double ScaleformUIImpl::Params_GetArgAsNumber(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall ScaleformUIImpl::Params_GetArgAsNumber(ScaleformUIImpl *this, _DWORD *params, int index)
{
  return *(double *)(params[4] + 16 * index + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100137F0
// Name: public: virtual bool ScaleformUIImpl::Params_GetArgAsBool(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::Params_GetArgAsBool(ScaleformUIImpl *this, _DWORD *params, int index)
{
  return *(_BYTE *)(params[4] + 16 * index + 8);
}

//------------------------------------------------------------------------------
// Address: 0x10013810
// Name: public: virtual wchar_t const __near * ScaleformUIImpl::Params_GetArgAsStringW(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall ScaleformUIImpl::Params_GetArgAsStringW(ScaleformUIImpl *this, _DWORD *params, int index)
{
  return *(const wchar_t **)(params[4] + 16 * index + 8);
}

//------------------------------------------------------------------------------
// Address: 0x10013830
// Name: public: virtual void __near * ScaleformUIImpl::Params_CreateNewObject(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformUIImpl::Params_CreateNewObject(ScaleformUIImpl *this, void **params)
{
  return this->MovieView_CreateObject(this, a2: params[1], a3: nullptr, a4: nullptr, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10013850
// Name: public: virtual void __near * ScaleformUIImpl::Params_CreateNewArray(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformUIImpl::Params_CreateNewArray(ScaleformUIImpl *this, void **params, int size)
{
  return this->MovieView_CreateArray(this, a2: params[1], a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10013870
// Name: public: virtual void __near * ScaleformUIImpl::Params_CreateNewString(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformUIImpl::Params_CreateNewString(ScaleformUIImpl *this, void **params, const char *value)
{
  return this->MovieView_CreateString(this, a2: params[1], a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x10013890
// Name: public: virtual void __near * ScaleformUIImpl::Params_CreateNewString(void __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformUIImpl::Params_CreateNewString(ScaleformUIImpl *this, void **params, const wchar_t *value)
{
  return this->MovieView_CreateStringW(this, a2: params[1], a3: value);
}

//------------------------------------------------------------------------------
// Address: 0x100138B0
// Name: public: virtual char const __near * ScaleformUIImpl::Params_GetArgAsString(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ScaleformUIImpl::Params_GetArgAsString(ScaleformUIImpl *this, _DWORD *params, int index)
{
  int v3; // eax
  int v4; // edx
  const char *result; // eax

  v3 = params[4] + 16 * index;
  v4 = *(_DWORD *)(v3 + 4);
  result = *(const char **)(v3 + 8);
  if ( (v4 & 0x40) != 0 )
    return *(const char **)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100138E0
// Name: public: virtual void ScaleformUIImpl::Params_SetResult(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Params_SetResult(ScaleformUIImpl *this, void **params, CStringPool **value)
{
  CStringPool **v3; // esi
  CStringPool *v4; // ecx

  v3 = (CStringPool **)*params;
  if ( *params != value )
  {
    if ( ((unsigned int)v3[1] & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: *v3, val: (StringPoolCase_t)v3);
      *v3 = nullptr;
    }
    v3[1] = value[1];
    v3[2] = value[2];
    v3[3] = value[3];
    if ( ((unsigned int)value[1] & 0x40) != 0 )
    {
      v4 = *value;
      *v3 = *value;
      GFxValue::ObjectInterface::ObjectAddRef(this: v4, val: (StringPoolCase_t)v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013940
// Name: public: virtual void ScaleformUIImpl::Params_SetResult(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Params_SetResult(ScaleformUIImpl *this, StringPoolCase_t *params, int value)
{
  StringPoolCase_t v3; // esi

  v3 = *params;
  if ( (*(_DWORD *)(*params + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v3, val: v3);
    *(_DWORD *)v3 = 0;
  }
  *(_DWORD *)(v3 + 4) = 3;
  *(double *)(v3 + 8) = (double)value;
}

//------------------------------------------------------------------------------
// Address: 0x10013980
// Name: public: virtual void ScaleformUIImpl::Params_SetResult(void __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Params_SetResult(ScaleformUIImpl *this, StringPoolCase_t *params, float value)
{
  StringPoolCase_t v3; // esi

  v3 = *params;
  if ( (*(_DWORD *)(*params + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v3, val: v3);
    *(_DWORD *)v3 = 0;
  }
  *(_DWORD *)(v3 + 4) = 3;
  *(double *)(v3 + 8) = value;
}

//------------------------------------------------------------------------------
// Address: 0x100139C0
// Name: public: virtual void ScaleformUIImpl::Params_SetResult(void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Params_SetResult(ScaleformUIImpl *this, StringPoolCase_t *params, bool value)
{
  StringPoolCase_t v3; // esi

  v3 = *params;
  if ( (*(_DWORD *)(*params + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v3, val: v3);
    *(_DWORD *)v3 = 0;
  }
  *(_BYTE *)(v3 + 8) = value;
  *(_DWORD *)(v3 + 4) = 2;
}

//------------------------------------------------------------------------------
// Address: 0x10013A10
// Name: public: virtual void ScaleformUIImpl::Params_SetResult(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Params_SetResult(ScaleformUIImpl *this, StringPoolCase_t *params, const char *value)
{
  StringPoolCase_t v3; // esi

  v3 = *params;
  if ( (*(_DWORD *)(*params + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v3, val: v3);
    *(_DWORD *)v3 = 0;
  }
  *(_DWORD *)(v3 + 8) = value;
  *(_DWORD *)(v3 + 4) = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10013A60
// Name: public: virtual void ScaleformUIImpl::Params_SetResult(void __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Params_SetResult(
        ScaleformUIImpl *this,
        StringPoolCase_t *params,
        const wchar_t *value)
{
  StringPoolCase_t v3; // esi

  v3 = *params;
  if ( (*(_DWORD *)(*params + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v3, val: v3);
    *(_DWORD *)v3 = 0;
  }
  *(_DWORD *)(v3 + 8) = value;
  *(_DWORD *)(v3 + 4) = 5;
}
