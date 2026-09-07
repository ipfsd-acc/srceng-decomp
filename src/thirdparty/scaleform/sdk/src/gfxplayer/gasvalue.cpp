// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gasvalue.cpp
// Functions: 77
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gasvalue.h"

//------------------------------------------------------------------------------
// Address: 0x1007FC50
// Name: public: bool GASString::operator<(class GASString const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASString::operator<(const char ***this, _IMAGE_SYMBOL_EX *result)
{
  int v2; // kr00_4

  v2 = strcmp(**this, *(const char **)result->N.Name.Short);
  return v2 != 0 && -(v2 < 0) - ((v2 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007FCA0
// Name: public: bool GASString::operator>(class GASString const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASString::operator>(const char ***this, _IMAGE_SYMBOL_EX *result)
{
  int v2; // kr00_4

  v2 = strcmp(**this, *(const char **)result->N.Name.Short);
  return v2 != 0 && -(v2 < 0) - ((v2 < 0) - 1) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007FCF0
// Name: public: static bool GASNumberUtil::IsNaNOrInfinity(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberUtil::IsNaNOrInfinity(GViewport *v, int va, int v_4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1007FD20
// Name: public: bool GASValue::IsFunction(void)const
// Source: json
//------------------------------------------------------------------------------
_SERVICE_PREFERRED_NODE_INFO __thiscall GASValue::IsFunction(_BYTE *this)
{
  return (_SERVICE_PREFERRED_NODE_INFO)(*this == 8 || *this == 11);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD40
// Name: public: bool GASValue::IsUndefined(void)const
// Source: json
//------------------------------------------------------------------------------
_SERVICE_PREFERRED_NODE_INFO __thiscall GASValue::IsUndefined(_BYTE *this)
{
  return (_SERVICE_PREFERRED_NODE_INFO)(*this == 0 || *this == 10);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD60
// Name: public: bool GASValue::IsNumber(void)const
// Source: json
//------------------------------------------------------------------------------
_SERVICE_PREFERRED_NODE_INFO __thiscall GASValue::IsNumber(_BYTE *this)
{
  return (_SERVICE_PREFERRED_NODE_INFO)(*this == 3 || *this == 4);
}

//------------------------------------------------------------------------------
// Address: 0x1007FD80
// Name: public: bool GASValue::IsPrimitive(void)const
// Source: json
//------------------------------------------------------------------------------
_SERVICE_PREFERRED_NODE_INFO __thiscall GASValue::IsPrimitive(char *this)
{
  char v1; // al

  v1 = *this;
  return (_SERVICE_PREFERRED_NODE_INFO)(*this == 5 || v1 == 2 || v1 == 1 || v1 == 3 || v1 == 4);
}

//------------------------------------------------------------------------------
// Address: 0x1007FDA0
// Name: StringToNumber
// Source: json
//------------------------------------------------------------------------------
bool __usercall StringToNumber@<al>(int a1@<esi>, long double a2@<st0>, long double *a3)
{
  unsigned int v3; // ebx
  int v4; // eax
  int v5; // eax
  char *v6; // edi
  int v7; // eax
  int sign; // [esp+0h] [ebp-8h]
  char *tail; // [esp+4h] [ebp-4h] BYREF

  tail = nullptr;
  v3 = strlen((const char *)a1);
  if ( *(_BYTE *)a1 == 48 )
  {
    v4 = *(char *)(a1 + 1);
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    if ( v4 == 120 )
    {
      *a3 = (double)(int)strtoul(nptr: (const char *)a1, endptr: &tail, ibase: 0);
      return tail != (char *)a1 && *tail == 0;
    }
  }
  strcspn(string: (unsigned __int8 *)a1, control: ".Ee");
  if ( v5 != v3 )
  {
    G_strtod(_Src: (char *)a1, endptr: &tail);
    *a3 = a2;
    return tail != (char *)a1 && *tail == 0;
  }
  v6 = (char *)a1;
  sign = 1;
  if ( *(_BYTE *)a1 == 45 )
  {
    sign = -1;
  }
  else if ( *(_BYTE *)a1 != 43 )
  {
LABEL_12:
    if ( *v6 == 48 && (strspn(string: (unsigned __int8 *)v6, control: "01234567"), v7 == v3) )
    {
      *a3 = (double)(int)(sign * strtoul(nptr: v6, endptr: &tail, ibase: 8));
    }
    else
    {
      G_strtod(_Src: v6, endptr: &tail);
      *a3 = a2 * (double)sign;
    }
    return tail != (char *)a1 && *tail == 0;
  }
  --v3;
  v6 = (char *)(a1 + 1);
  goto LABEL_12;
}

//------------------------------------------------------------------------------
// Address: 0x1007FEB0
// Name: public: class GFxASCharacter __near * GASValue::ToASCharacter(class GASEnvironment const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::ToASCharacter(GASValue *this, const struct GASEnvironment *penv)
{
  GFxMovieRoot *MovieRoot; // eax

  if ( *(_BYTE *)this == 7 && penv != nullptr && *((_DWORD *)this + 1) != 0 )
  {
    MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)penv);
    GFxCharacterHandle::ResolveCharacter(
      this: *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
      + 1),
      a2: MovieRoot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FEF0
// Name: public: class GASString const __near & GASValue::GetCharacterNamePath(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
tagRID_DEVICE_INFO_KEYBOARD *__thiscall GASValue::GetCharacterNamePath(
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **this,
        tagRID_DEVICE_INFO_KEYBOARD *result)
{
  GFxMovieRoot *MovieRoot; // eax
  int v4; // eax

  if ( *(this + 1) != nullptr
    && (MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result),
        GFxCharacterHandle::ResolveCharacter(this: *(this + 1), a2: MovieRoot),
        v4 != 0) )
  {
    return (tagRID_DEVICE_INFO_KEYBOARD *)&(*(this + 1))->m_iRefs;
  }
  else
  {
    return (tagRID_DEVICE_INFO_KEYBOARD *)(result[5].dwType + 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FF30
// Name: public: class GFxLog __near * GASFnCall::GetLog(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxLog *__thiscall GASFnCall::GetLog(GASFnCall *this)
{
  return GASEnvironment::GetLog(this: (GASEnvironment *)*(this + 6));
}

//------------------------------------------------------------------------------
// Address: 0x1007FF40
// Name: public: virtual bool GASFnCall::IsVerboseActionErrors(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GASFnCall::IsVerboseActionErrors(_DWORD **this)
{
  return (*(unsigned int (__thiscall **)(_DWORD))(**(this + 6) + 4))(a1: *(this + 6));
}

//------------------------------------------------------------------------------
// Address: 0x1007FF50
// Name: public: bool GASFnCall::CheckThisPtr(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASFnCall::CheckThisPtr(_DWORD *this, unsigned int type)
{
  return *(this + 2) != 0 && (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*(this + 2) + 8))(a1: *(this + 2)) == type;
}

//------------------------------------------------------------------------------
// Address: 0x1007FF80
// Name: public: void GASFnCall::ThisPtrError(char const __near *,char const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASFnCall::ThisPtrError(GASFnCall *this, const char *a2, const char *a3, int a4)
{
  GASEnvironment::LogScriptError(
    this: (GASEnvironment *)*(this + 6),
    a2: "Error: Null or invalid 'this' is used for a method of %s class.\n",
    a2);
}

//------------------------------------------------------------------------------
// Address: 0x1007FFD0
// Name: public: GASValue::GASValue(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
tagAXISINFOA *__thiscall GASValue::GASValue(_DWORD *this, tagAXISINFOA *result)
{
  _DWORD *axMaxValue; // eax

  *(_BYTE *)this = 7;
  if ( result != nullptr )
  {
    axMaxValue = (_DWORD *)result[6].axMaxValue;
    if ( axMaxValue == nullptr )
      GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)result);
    *(this + 1) = axMaxValue;
    if ( axMaxValue != nullptr )
      ++*axMaxValue;
    return (tagAXISINFOA *)this;
  }
  else
  {
    *(this + 1) = 0;
    return (tagAXISINFOA *)this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080010
// Name: public: GASValue::GASValue(class GASStringContext __near *,void (*)(class GASFnCall const __near &))
// Source: json
//------------------------------------------------------------------------------
GASValue *__thiscall GASValue::GASValue(GASValue *this, int func, void (__cdecl *a3)(const struct GASFnCall *))
{
  _REASON_CONTEXT *v3; // edi
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // edx
  GASCFunctionObject *v7; // eax
  GASCFunctionObject *v8; // eax

  v3 = (_REASON_CONTEXT *)func;
  *(_BYTE *)this = 8;
  v5 = *(_DWORD *)(v3->Version + 656);
  v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
  func = 323;
  v7 = (GASCFunctionObject *)v6(a1: v5, a2: 56, a3: &func);
  if ( v7 != nullptr )
    v8 = GASCFunctionObject::GASCFunctionObject(this: v7, func: v3, a3);
  else
    v8 = nullptr;
  *((_DWORD *)this + 1) = v8;
  *((_BYTE *)this + 12) = 0;
  *((_DWORD *)this + 2) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10080070
// Name: public: bool GASValue::ToBool(class GASEnvironment const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASValue::ToBool@<al>(char *a1@<ecx>, long double a2@<st0>, tagPOLYTEXTW *result)
{
  char v3; // al
  int *v4; // ecx
  GViewport *v6; // ecx
  char v7; // al
  int v8; // eax
  long double num; // [esp+Ch] [ebp-8h] BYREF

  v3 = *a1;
  if ( *a1 == 5 )
  {
    v4 = *((int **)a1 + 1);
    if ( v4[4] == 0 )
      return 0;
    if ( LOBYTE(result[3].y) <= 6u )
    {
      if ( !StringToNumber(a1: *v4, a2, a3: &num) )
        return 0;
      GASNumberUtil::IsNaN(v: v6, u: SLODWORD(num), u_4: SHIDWORD(num));
      if ( v7 != 0 )
        return 0;
      return 0.0 != num;
    }
    return 1;
  }
  else
  {
    switch ( v3 )
    {
      case 3:
        num = *(double *)(a1 + 4);
        if ( (HIDWORD(num) & 0x7FF00000) == 0x7FF00000 && (HIDWORD(num) & 0xFFFFF | LODWORD(num)) != 0 )
          return 0;
        return 0.0 != *(double *)(a1 + 4);
      case 4:
        return *((_DWORD *)a1 + 1) != 0;
      case 2:
        return a1[4];
      case 6:
        return *((_DWORD *)a1 + 1) != 0;
      case 7:
        GASValue::ToASCharacter(this: (GASValue *)a1, penv: (const struct GASEnvironment *)result);
        return v8 != 0;
      case 8:
        return *((_DWORD *)a1 + 1) != 0;
      default:
        return v3 == 11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080190
// Name: public: GASValue::GASValue(class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASValue *__userpurge GASValue::GASValue@<eax>(GASValue *this@<ecx>, int a2@<edi>, const struct GASFunctionRef *a3)
{
  GASValue *v4; // ecx
  GASValue v5; // eax
  tagIMECHARPOSITION *v6; // eax

  *(_BYTE *)this = 8;
  v4 = this + 1;
  *((_BYTE *)v4 + 8) = 0;
  v5 = *(GASValue *)a3;
  *v4 = *(GASValue *)a3;
  if ( v5 != nullptr )
    v5->m_nGrowSize = (v5->m_nGrowSize + 1) & 0x8FFFFFFF;
  *((_DWORD *)v4 + 1) = 0;
  v6 = *((tagIMECHARPOSITION **)a3 + 1);
  if ( v6 != nullptr )
    GASFunctionRefBase::SetLocalFrame(a1: (int)v4, a2, result: v6, internal: *((_BYTE *)a3 + 8) & 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100801E0
// Name: public: class GASValue __near & GASFnCall::Arg(int)const
// Source: json
//------------------------------------------------------------------------------
struct GASValue *__thiscall GASFnCall::Arg(GASFnCall *this, int a2)
{
  int v2; // edx
  _DWORD *v3; // ecx
  unsigned int v4; // edx
  struct GASValue *result; // eax

  v2 = (int)*(this + 8);
  v3 = *(this + 6);
  v4 = v2 - a2;
  result = nullptr;
  if ( v4 <= 32 * (v3[7] - 1) + ((v3[2] - v3[3]) >> 4) )
    return (struct GASValue *)(*(_DWORD *)(v3[6] + 4 * (v4 >> 5)) + 16 * (v4 & 0x1F));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080220
// Name: public: void GASValue::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(int *this)
{
  char v1; // dl
  int v2; // eax
  int v3; // ecx
  void (__thiscall **v4)(int, int); // edx
  int v5; // ecx
  int v6; // eax
  void (__stdcall **v7)(int); // edx

  v1 = *(_BYTE *)this;
  if ( *(_BYTE *)this == 8 )
  {
    GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: this + 1);
  }
  else if ( v1 == 6 && (v2 = *(this + 1)) != 0 )
  {
    v3 = ++*(_DWORD *)(v2 + 8);
    if ( (v3 & 0x70000000) != 0 )
    {
      v4 = *(void (__thiscall ***)(int, int))v2;
      *(_DWORD *)(v2 + 8) = v3 & 0x8FFFFFFF;
      (*v4)(a1: v2, a2: 2);
    }
  }
  else if ( v1 == 9 )
  {
    v5 = *(this + 1);
    v6 = ++*(_DWORD *)(v5 + 8);
    if ( (v6 & 0x70000000) != 0 )
    {
      v7 = *(void (__stdcall ***)(int))v5;
      *(_DWORD *)(v5 + 8) = v6 & 0x8FFFFFFF;
      (*v7)(a1: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080290
// Name: public: void GASValue::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(int *this)
{
  char v1; // dl
  int v2; // eax
  void (__thiscall **v3)(int, int); // edx
  int v4; // ecx

  v1 = *(_BYTE *)this;
  if ( *(_BYTE *)this == 8 )
  {
    GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: this + 1);
  }
  else if ( v1 == 6 && (v2 = *(this + 1)) != 0 )
  {
    if ( (--*(_DWORD *)(v2 + 8) & 0x70000000) != 0x10000000 )
    {
      v3 = *(void (__thiscall ***)(int, int))v2;
      *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 0x8FFFFFFF | 0x10000000;
      (*v3)(a1: v2, a2: 1);
    }
  }
  else if ( v1 == 9 )
  {
    v4 = *(this + 1);
    if ( (--*(_DWORD *)(v4 + 8) & 0x70000000) != 0x10000000 )
    {
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(v4 + 8) & 0x8FFFFFFF | 0x10000000;
      (**(void (__thiscall ***)(int, int))v4)(a1: v4, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080310
// Name: public: void GASValue::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(int *this)
{
  char v2; // dl
  int v3; // ecx
  int v4; // eax

  v2 = *(_BYTE *)this;
  if ( *(_BYTE *)this == 8 )
  {
    GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: this + 1);
    return;
  }
  if ( v2 != 6 || (v3 = *(this + 1)) == 0 )
  {
    if ( v2 != 9 )
      return;
    v3 = *(this + 1);
  }
  v4 = *(_DWORD *)(v3 + 8);
  if ( (v4 & 0x70000000) == 0x10000000 )
  {
    if ( (v4 & 0xFFFFFFF) != 0 )
    {
      *(_DWORD *)(v3 + 8) = v4 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v3)(a1: v3, a2: 2);
    }
    else
    {
      *(_DWORD *)(v3 + 8) = v4 & 0x8FFFFFFF | 0x20000000;
      (**(void (__thiscall ***)(int, int))v3)(a1: v3, a2: 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080380
// Name: public: void GASValue::DropRefs(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASValue::DropRefs(GASValue *this@<ecx>, int a2@<edi>)
{
  int v3; // ecx
  bool v4; // zf
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  GFxCharacterHandle *v8; // edi

  switch ( *(_BYTE *)this )
  {
    case 5:
    case 0xB:
      v3 = *((_DWORD *)this + 1);
      v4 = (*(_DWORD *)(v3 + 8))-- == 1;
      if ( v4 )
        GASStringNode::ReleaseNode(a1: v3);
      break;
    case 6:
    case 9:
      v7 = *((_DWORD *)this + 1);
      if ( v7 != 0 )
      {
        GRefCountBaseGC<323>::Release(a1: v7, a2);
        *((_DWORD *)this + 1) = 0;
      }
      break;
    case 7:
      v8 = *((GFxCharacterHandle **)this + 1);
      if ( v8 != nullptr )
      {
        *v8 = (GFxCharacterHandle)((char *)*v8 - 1);
        if ( (int)*v8 <= 0 )
        {
          GFxCharacterHandle::~GFxCharacterHandle(this: v8);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
        }
        *((_DWORD *)this + 1) = 0;
      }
      break;
    case 8:
    case 0xC:
      if ( *((_DWORD *)this + 1) != 0 )
      {
        if ( (*(_BYTE *)(this + 3) & 2) == 0 )
        {
          v5 = *((_DWORD *)this + 1);
          if ( v5 != 0 )
            GRefCountBaseGC<323>::Release(a1: v5, a2);
        }
        v4 = (*(_BYTE *)(this + 3) & 1) == 0;
        *((_DWORD *)this + 1) = 0;
        if ( v4 )
        {
          v6 = *((_DWORD *)this + 2);
          if ( v6 != 0 )
            GRefCountBaseGC<323>::Release(a1: v6, a2);
        }
        *((_DWORD *)this + 2) = 0;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080450
// Name: public: void GASValue::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __usercall GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>@<al>(int *a1@<ecx>, int a2@<edi>)
{
  char *v2; // eax
  char v3; // dl
  int v4; // ecx

  v2 = (char *)a1;
  v3 = *(_BYTE *)a1;
  if ( *(_BYTE *)a1 == 8 )
  {
    LOBYTE(v2) = GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: a1 + 1, a2);
  }
  else
  {
    if ( v3 != 6 || (v4 = a1[1]) == 0 )
    {
      if ( v3 != 9 )
        return (char)v2;
      v4 = *((_DWORD *)v2 + 1);
    }
    LOBYTE(v2) = GRefCountBaseGC<323>::Release(a1: v4, a2);
  }
  return (char)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10080480
// Name: public: void GASValue::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(_DWORD *this)
{
  _DWORD *v1; // eax
  char v2; // dl
  _DWORD *v3; // ecx

  v1 = this;
  v2 = *(_BYTE *)this;
  if ( *(_BYTE *)this == 8 )
  {
    LOBYTE(v1) = GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: this + 1);
  }
  else if ( v2 == 6 && (v3 = (_DWORD *)*(this + 1)) != nullptr )
  {
    LOBYTE(v1) = GRefCountBaseGC<323>::CollectGarbage(this: v3);
  }
  else if ( v2 == 9 )
  {
    LOBYTE(v1) = GRefCountBaseGC<323>::CollectGarbage(this: (_DWORD *)v1[1]);
  }
  return (char)v1;
}

//------------------------------------------------------------------------------
// Address: 0x100804B0
// Name: public: GASValueProperty::GASValueProperty(class GASRefCountCollector __near *,class GASFunctionRef const __near &,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASValueProperty::GASValueProperty@<eax>(
        int a1@<ecx>,
        unsigned int a2@<edi>,
        int pCC,
        int *pCC_4,
        int a5)
{
  int v6; // ecx
  int v7; // eax
  tagIMECHARPOSITION *v8; // eax
  int v9; // eax
  tagIMECHARPOSITION *v10; // eax

  *(_DWORD *)(a1 + 4) = pCC;
  *(_DWORD *)(a1 + 8) = 1;
  *(_DWORD *)a1 = &GASValueProperty::`vftable';
  v6 = a1 + 16;
  *(_BYTE *)(v6 + 8) = 0;
  v7 = *pCC_4;
  *(_DWORD *)v6 = *pCC_4;
  if ( v7 != 0 )
  {
    a2 = (*(_DWORD *)(v7 + 8) + 1) & 0x8FFFFFFF;
    *(_DWORD *)(v7 + 8) = a2;
  }
  *(_DWORD *)(v6 + 4) = 0;
  v8 = (tagIMECHARPOSITION *)pCC_4[1];
  if ( v8 != nullptr )
    GASFunctionRefBase::SetLocalFrame(a1: v6, a2, result: v8, internal: pCC_4[2] & 1);
  *(_BYTE *)(a1 + 36) = 0;
  v9 = *(_DWORD *)a5;
  *(_DWORD *)(a1 + 28) = *(_DWORD *)a5;
  if ( v9 != 0 )
    *(_DWORD *)(v9 + 8) = (*(_DWORD *)(v9 + 8) + 1) & 0x8FFFFFFF;
  *(_DWORD *)(a1 + 32) = 0;
  v10 = *(tagIMECHARPOSITION **)(a5 + 4);
  if ( v10 != nullptr )
    GASFunctionRefBase::SetLocalFrame(a1: a1 + 28, a2: a5, result: v10, internal: *(_BYTE *)(a5 + 8) & 1);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10080550
// Name: public: virtual void GASValueProperty::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASValueProperty::ExecuteForEachChild_GC(int a1@<ecx>, int a2@<edi>, int operation)
{
  switch ( operation )
  {
    case 0:
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: (int *)(a1 + 16), a2);
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: (int *)(a1 + 28), a2);
      break;
    case 1:
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)(a1 + 16));
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)(a1 + 28));
      break;
    case 2:
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)(a1 + 16));
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)(a1 + 28));
      break;
    case 3:
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: (_DWORD *)(a1 + 16));
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: (_DWORD *)(a1 + 28));
      break;
    case 4:
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)(a1 + 16));
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)(a1 + 28));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100805F0
// Name: public: virtual GASValueProperty::~GASValueProperty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValueProperty::~GASValueProperty(GASValueProperty *this)
{
  int v2; // ecx
  bool v3; // zf
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx

  if ( (this->Hash[7] & 2) == 0 )
  {
    v2 = this->Hash[5];
    if ( v2 != 0 )
      GRefCountBaseGC<323>::Release(a1: v2, a2: 0);
  }
  v3 = (this->Hash[7] & 1) == 0;
  this->Hash[5] = 0;
  if ( v3 )
  {
    v4 = this->Hash[6];
    if ( v4 != 0 )
      GRefCountBaseGC<323>::Release(a1: v4, a2: 0);
  }
  this->Hash[6] = 0;
  if ( (this->Hash[4] & 2) == 0 )
  {
    v5 = this->Hash[2];
    if ( v5 != 0 )
      GRefCountBaseGC<323>::Release(a1: v5, a2: 0);
  }
  v3 = (this->Hash[4] & 1) == 0;
  this->Hash[2] = 0;
  if ( v3 )
  {
    v6 = this->Hash[3];
    if ( v6 != 0 )
      GRefCountBaseGC<323>::Release(a1: v6, a2: 0);
  }
  this->Hash[3] = 0;
  this->SidCount = (unsigned int)&GRefCountBaseGC<323>::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10080660
// Name: public: GASValue::GASValue(class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
GASValue *__thiscall GASValue::GASValue(GASValue *this, tagWNDCLASSW *v)
{
  GASValue *result; // eax
  int (__stdcall *lpfnWndProc)(HWND__ *, unsigned int, unsigned int, int); // esi
  int (__stdcall *v5)(HWND__ *, unsigned int, unsigned int, int); // eax
  int v6; // eax
  GASValue v7; // edx
  tagIMECHARPOSITION *v8; // edx
  int (__stdcall *v9)(HWND__ *, unsigned int, unsigned int, int); // esi
  int (__stdcall *v10)(HWND__ *, unsigned int, unsigned int, int); // esi
  GASValue *v11; // ecx
  int (__stdcall *v12)(HWND__ *, unsigned int, unsigned int, int); // eax
  tagIMECHARPOSITION *cbClsExtra; // eax
  int (__stdcall *v14)(HWND__ *, unsigned int, unsigned int, int); // esi
  int v15; // [esp+8h] [ebp-Ch] BYREF
  int v16; // [esp+Ch] [ebp-8h]
  char v17; // [esp+10h] [ebp-4h]

  *(_BYTE *)this = v->style;
  switch ( LOBYTE(v->style) )
  {
    case 2:
      *((_BYTE *)this + 4) = v->lpfnWndProc;
      result = this;
      break;
    case 3:
      *(double *)(this + 1) = *(double *)&v->lpfnWndProc;
      result = this;
      break;
    case 4:
      *(this + 1) = (GASValue)v->lpfnWndProc;
      result = this;
      break;
    case 5:
    case 0xB:
      lpfnWndProc = v->lpfnWndProc;
      *((_DWORD *)this + 1) = lpfnWndProc;
      ++*((_DWORD *)lpfnWndProc + 2);
      result = this;
      break;
    case 6:
      v5 = v->lpfnWndProc;
      if ( v5 != nullptr )
      {
        if ( (*(int (__thiscall **)(int))(*((_DWORD *)v5 + 4) + 8))(a1: (int)v5 + 16) == 23 )
        {
          *(_BYTE *)this = 8;
          v6 = (*(int (__thiscall **)(int, int *))(*((_DWORD *)v->lpfnWndProc + 4) + 48))(
                 a1: (int)v->lpfnWndProc + 16,
                 a2: &v15);
          *((_BYTE *)this + 12) = 0;
          v7 = *(GASValue *)v6;
          *(this + 1) = *(GASValue *)v6;
          if ( v7 != nullptr )
            v7->m_nGrowSize = (v7->m_nGrowSize + 1) & 0x8FFFFFFF;
          *((_DWORD *)this + 2) = 0;
          v8 = *(tagIMECHARPOSITION **)(v6 + 4);
          if ( v8 != nullptr )
            GASFunctionRefBase::SetLocalFrame(
              a1: (int)(this + 1),
              a2: (int)this,
              result: v8,
              internal: *(_BYTE *)(v6 + 8) & 1);
          if ( (v17 & 2) == 0 && v15 != 0 )
            GRefCountBaseGC<323>::Release(a1: v15, a2: (int)this);
          v15 = 0;
          if ( (v17 & 1) != 0 || v16 == 0 )
            goto LABEL_27;
          GRefCountBaseGC<323>::Release(a1: v16, a2: (int)this);
          result = this;
        }
        else
        {
          v9 = v->lpfnWndProc;
          *((_DWORD *)this + 1) = v9;
          *((_DWORD *)v9 + 2) = (*((_DWORD *)v9 + 2) + 1) & 0x8FFFFFFF;
          result = this;
        }
      }
      else
      {
        *((_DWORD *)this + 1) = 0;
        result = this;
      }
      break;
    case 7:
      v10 = v->lpfnWndProc;
      *((_DWORD *)this + 1) = v10;
      if ( v10 == nullptr )
        goto LABEL_27;
      ++*(_DWORD *)v10;
      result = this;
      break;
    case 8:
    case 0xC:
      v11 = this + 1;
      *((_BYTE *)this + 12) = 0;
      v12 = v->lpfnWndProc;
      *((_DWORD *)this + 1) = v12;
      if ( v12 != nullptr )
        *((_DWORD *)v12 + 2) = (*((_DWORD *)v12 + 2) + 1) & 0x8FFFFFFF;
      *((_DWORD *)this + 2) = 0;
      cbClsExtra = (tagIMECHARPOSITION *)v->cbClsExtra;
      if ( cbClsExtra == nullptr )
        goto LABEL_27;
      GASFunctionRefBase::SetLocalFrame(a1: (int)v11, a2: (int)this, result: cbClsExtra, internal: v->cbWndExtra & 1);
      result = this;
      break;
    case 9:
      v14 = v->lpfnWndProc;
      *((_DWORD *)this + 1) = v14;
      *((_DWORD *)v14 + 2) = (*((_DWORD *)v14 + 2) + 1) & 0x8FFFFFFF;
      goto LABEL_27;
    default:
LABEL_27:
      result = this;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080850
// Name: public: void GASValue::operator=(class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASValue::operator=(int this, tagWNDCLASSW *v)
{
  int (__stdcall *cbClsExtra)(HWND__ *, unsigned int, unsigned int, int); // eax
  int (__stdcall *lpfnWndProc)(HWND__ *, unsigned int, unsigned int, int); // esi
  int v5; // edx
  tagIMECHARPOSITION *v6; // edx
  int (__stdcall *v7)(HWND__ *, unsigned int, unsigned int, int); // esi
  int (__stdcall *v8)(HWND__ *, unsigned int, unsigned int, int); // esi
  int (__stdcall *v9)(HWND__ *, unsigned int, unsigned int, int); // eax
  int (__stdcall *v10)(HWND__ *, unsigned int, unsigned int, int); // esi
  int v12; // [esp+8h] [ebp-Ch] BYREF
  int v13; // [esp+Ch] [ebp-8h]
  char v14; // [esp+10h] [ebp-4h]

  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this, a2: this);
  *(_BYTE *)this = v->style;
  LOBYTE(cbClsExtra) = LOBYTE(v->style) - 2;
  switch ( LOBYTE(v->style) )
  {
    case 2:
      *(_BYTE *)(this + 4) = v->lpfnWndProc;
      break;
    case 3:
      *(double *)(this + 4) = *(double *)&v->lpfnWndProc;
      break;
    case 4:
      *(_DWORD *)(this + 4) = v->lpfnWndProc;
      break;
    case 5:
    case 0xB:
      lpfnWndProc = v->lpfnWndProc;
      *(_DWORD *)(this + 4) = lpfnWndProc;
      ++*((_DWORD *)lpfnWndProc + 2);
      break;
    case 6:
      cbClsExtra = v->lpfnWndProc;
      if ( cbClsExtra != nullptr )
      {
        cbClsExtra = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))(*(int (__thiscall **)(int))(*((_DWORD *)cbClsExtra + 4) + 8))(a1: (int)cbClsExtra + 16);
        if ( cbClsExtra == (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))23 )
        {
          *(_BYTE *)this = 8;
          cbClsExtra = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))(*(int (__thiscall **)(char *, int *))(*((_DWORD *)v->lpfnWndProc + 4) + 48))(
                                                                                       a1: (char *)v->lpfnWndProc + 16,
                                                                                       a2: &v12);
          *(_BYTE *)(this + 12) = 0;
          v5 = *(_DWORD *)cbClsExtra;
          *(_DWORD *)(this + 4) = *(_DWORD *)cbClsExtra;
          if ( v5 != 0 )
            *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
          *(_DWORD *)(this + 8) = 0;
          v6 = *((tagIMECHARPOSITION **)cbClsExtra + 1);
          if ( v6 != nullptr )
            LOBYTE(cbClsExtra) = (unsigned __int8)GASFunctionRefBase::SetLocalFrame(
                                                    a1: this + 4,
                                                    a2: this,
                                                    result: v6,
                                                    internal: *((_BYTE *)cbClsExtra + 8) & 1);
          if ( (v14 & 2) == 0 && v12 != 0 )
            LOBYTE(cbClsExtra) = GRefCountBaseGC<323>::Release(a1: v12, a2: this);
          v12 = 0;
          if ( (v14 & 1) == 0 && v13 != 0 )
            LOBYTE(cbClsExtra) = GRefCountBaseGC<323>::Release(a1: v13, a2: this);
        }
        else
        {
          v7 = v->lpfnWndProc;
          *(_DWORD *)(this + 4) = v7;
          *((_DWORD *)v7 + 2) = (*((_DWORD *)v7 + 2) + 1) & 0x8FFFFFFF;
        }
      }
      else
      {
        *(_DWORD *)(this + 4) = 0;
      }
      break;
    case 7:
      v8 = v->lpfnWndProc;
      *(_DWORD *)(this + 4) = v8;
      if ( v8 != nullptr )
        ++*(_DWORD *)v8;
      break;
    case 8:
    case 0xC:
      *(_BYTE *)(this + 12) = 0;
      v9 = v->lpfnWndProc;
      *(_DWORD *)(this + 4) = v9;
      if ( v9 != nullptr )
        *((_DWORD *)v9 + 2) = (*((_DWORD *)v9 + 2) + 1) & 0x8FFFFFFF;
      *(_DWORD *)(this + 8) = 0;
      cbClsExtra = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))v->cbClsExtra;
      if ( cbClsExtra != nullptr )
        LOBYTE(cbClsExtra) = (unsigned __int8)GASFunctionRefBase::SetLocalFrame(
                                                a1: this + 4,
                                                a2: this,
                                                result: (tagIMECHARPOSITION *)cbClsExtra,
                                                internal: v->cbWndExtra & 1);
      break;
    case 9:
      v10 = v->lpfnWndProc;
      *(_DWORD *)(this + 4) = v10;
      cbClsExtra = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))((*((_DWORD *)v10 + 2) + 1) & 0x8FFFFFFF);
      *((_DWORD *)v10 + 2) = cbClsExtra;
      break;
    default:
      return (char)cbClsExtra;
  }
  return (char)cbClsExtra;
}

//------------------------------------------------------------------------------
// Address: 0x10080A30
// Name: public: GASValue::GASValue(class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
GASValue *__thiscall GASValue::GASValue(GASValue *this, struct GASObject *a2)
{
  int v3; // eax
  GASValue v4; // edx
  tagIMECHARPOSITION *v5; // edx
  GASValue *result; // eax
  int v7; // [esp+Ch] [ebp-Ch] BYREF
  int v8; // [esp+10h] [ebp-8h]
  char v9; // [esp+14h] [ebp-4h]

  if ( a2 != nullptr && ((int (__thiscall *)(struct GASObject *))a2[2].pNode[1].pNext)(a1: &a2[2]) == 23 )
  {
    *(_BYTE *)this = 8;
    v3 = ((int (__thiscall *)(struct GASObject *, int *))a2[2].pNode[6].pNext)(a1: &a2[2], a2: &v7);
    *((_BYTE *)this + 12) = 0;
    v4 = *(GASValue *)v3;
    *(this + 1) = *(GASValue *)v3;
    if ( v4 != nullptr )
      v4->m_nGrowSize = (v4->m_nGrowSize + 1) & 0x8FFFFFFF;
    *((_DWORD *)this + 2) = 0;
    v5 = *(tagIMECHARPOSITION **)(v3 + 4);
    if ( v5 != nullptr )
      GASFunctionRefBase::SetLocalFrame(
        a1: (int)(this + 1),
        a2: (int)this,
        result: v5,
        internal: *(_BYTE *)(v3 + 8) & 1);
    if ( (v9 & 2) == 0 && v7 != 0 )
      GRefCountBaseGC<323>::Release(a1: v7, a2: (int)this);
    v7 = 0;
    if ( (v9 & 1) == 0 && v8 != 0 )
      GRefCountBaseGC<323>::Release(a1: v8, a2: (int)this);
    return this;
  }
  else
  {
    *(_BYTE *)this = 6;
    *((_DWORD *)this + 1) = a2;
    result = this;
    if ( a2 != nullptr )
      a2[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&a2[1].pNode->pNext + 1) & 0x8FFFFFFF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080B00
// Name: public: GASValue::GASValue(class GASFunctionRef const __near &,class GASFunctionRef const __near &,class GMemoryHeap __near *,class GASRefCountCollector __near *)
// Source: json
//------------------------------------------------------------------------------
GASValue *__userpurge GASValue::GASValue@<eax>(
        GASValue *this@<ecx>,
        unsigned int a2@<edi>,
        const struct GASFunctionRef *a3,
        const struct GASFunctionRef *a4,
        struct GMemoryHeap *a5,
        struct GASRefCountCollector *pCC)
{
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  int v8; // eax
  int v10; // [esp+4h] [ebp-4h] BYREF

  *(_BYTE *)this = 9;
  Alloc_2 = a5->Alloc_2;
  v10 = 323;
  v8 = (int)Alloc_2(this: a5, a2: 40u, a3: (const GAllocDebugInfo *)&v10);
  if ( v8 != 0 )
    *((_DWORD *)this + 1) = GASValueProperty::GASValueProperty(a1: v8, a2, (int)pCC, pCC_4: (int *)a3, a5: (int)a4);
  else
    *((_DWORD *)this + 1) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10080B60
// Name: public: GASValue::~GASValue(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASValue::~GASValue(GASValue *this@<ecx>, int a2@<edi>)
{
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10080B70
// Name: public: void GASValue::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASValue::Finalize_GC(GASValue *this@<ecx>, int a2@<edi>)
{
  unsigned __int8 v2; // al

  v2 = *(_BYTE *)this;
  if ( *(_BYTE *)this != 8 && v2 >= 5u && v2 != 6 && v2 != 9 )
    GASValue::DropRefs(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10080B90
// Name: public: class GASFunctionRef GASValue::ToResolveHandler(void)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASValue::ToResolveHandler@<eax>(int a1@<ecx>, int a2@<edi>, int a3)
{
  int v3; // eax
  tagIMECHARPOSITION *v4; // eax

  if ( *(_BYTE *)a1 == 12 )
  {
    *(_BYTE *)(a3 + 8) = 0;
    v3 = *(_DWORD *)(a1 + 4);
    *(_DWORD *)a3 = v3;
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 8) = (*(_DWORD *)(v3 + 8) + 1) & 0x8FFFFFFF;
    *(_DWORD *)(a3 + 4) = 0;
    v4 = *(tagIMECHARPOSITION **)(a1 + 8);
    if ( v4 != nullptr )
      GASFunctionRefBase::SetLocalFrame(a1: a3, a2, result: v4, internal: *(_BYTE *)(a1 + 12) & 1);
    return a3;
  }
  else
  {
    *(_BYTE *)(a3 + 8) = 0;
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = 0;
    return a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080BF0
// Name: public: void GASValue::SetAsCharacterHandle(class GFxCharacterHandle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetAsCharacterHandle(GASValue *this, struct GFxCharacterHandle *a2)
{
  if ( *(_BYTE *)this != 7 || *((struct GFxCharacterHandle **)this + 1) != a2 )
  {
    GASValue::DropRefs(this, (int)a2);
    *(_BYTE *)this = 7;
    *((_DWORD *)this + 1) = a2;
    if ( a2 != nullptr )
      ++*(_DWORD *)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080C20
// Name: public: void GASValue::SetAsCharacter(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetAsCharacter(int this, tagBITMAPCOREHEADER *result)
{
  _DWORD *v3; // esi
  _DWORD *v4; // eax

  if ( result != nullptr )
  {
    v3 = *(_DWORD **)&result[12].bcWidth;
    if ( v3 == nullptr )
    {
      GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)result);
      v3 = v4;
    }
  }
  else
  {
    v3 = nullptr;
  }
  if ( *(_BYTE *)this != 7 || *(_DWORD **)(this + 4) != v3 )
  {
    GASValue::DropRefs((GASValue *)this, a2: this);
    *(_BYTE *)this = 7;
    *(_DWORD *)(this + 4) = v3;
    if ( v3 != nullptr )
      ++*v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080C70
// Name: public: void GASValue::SetAsFunction(class GASFunctionRefBase const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetAsFunction(GASValue *this, const struct GASFunctionRefBase *func)
{
  GASValue v3; // eax
  tagIMECHARPOSITION *v4; // eax

  if ( *(_BYTE *)this != 8 || *((_DWORD *)this + 1) != *(_DWORD *)func )
  {
    GASValue::DropRefs(this, a2: (int)func);
    *(_BYTE *)this = 8;
    *((_BYTE *)this + 12) = 0;
    v3 = *(GASValue *)func;
    *(this + 1) = *(GASValue *)func;
    if ( v3 != nullptr )
      v3->m_nGrowSize = (v3->m_nGrowSize + 1) & 0x8FFFFFFF;
    *((_DWORD *)this + 2) = 0;
    v4 = *((tagIMECHARPOSITION **)func + 1);
    if ( v4 != nullptr )
      GASFunctionRefBase::SetLocalFrame(
        a1: (int)(this + 1),
        a2: (int)func,
        result: v4,
        internal: *((_BYTE *)func + 8) & 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080CD0
// Name: public: void GASValue::SetAsResolveHandler(class GASFunctionRefBase const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASValue::SetAsResolveHandler(
        GASValue *this@<ecx>,
        int a2@<edi>,
        const struct GASFunctionRefBase *func)
{
  GASValue v4; // eax
  tagIMECHARPOSITION *v5; // eax

  GASValue::DropRefs(this, a2);
  *(_BYTE *)this = 12;
  *((_BYTE *)this + 12) = 0;
  v4 = *(GASValue *)func;
  *(this + 1) = *(GASValue *)func;
  if ( v4 != nullptr )
    v4->m_nGrowSize = (v4->m_nGrowSize + 1) & 0x8FFFFFFF;
  *((_DWORD *)this + 2) = 0;
  v5 = *((tagIMECHARPOSITION **)func + 1);
  if ( v5 != nullptr )
    GASFunctionRefBase::SetLocalFrame(a1: (int)(this + 1), a2, result: v5, internal: *((_BYTE *)func + 8) & 1);
}

//------------------------------------------------------------------------------
// Address: 0x10080D20
// Name: public: bool GASValue::GetPropertyValue(class GASEnvironment __near *,class GASObjectInterface __near *,class GASValue __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASValue::GetPropertyValue@<al>(
        GASValue *this@<ecx>,
        int a2@<edi>,
        struct GASEnvironment *a3,
        struct GASObjectInterface *a4,
        struct GASValue *a5)
{
  int v5; // eax
  _DWORD v7[5]; // [esp+4h] [ebp-34h] BYREF
  char v8; // [esp+18h] [ebp-20h]
  struct GASEnvironment *v9; // [esp+1Ch] [ebp-1Ch]
  int v10; // [esp+20h] [ebp-18h]
  int v11; // [esp+24h] [ebp-14h]
  GASValue v12[4]; // [esp+28h] [ebp-10h] BYREF

  if ( *(_BYTE *)this != 9 || a3 == nullptr )
    return 0;
  v5 = *((_DWORD *)this + 1);
  if ( *(_DWORD *)(v5 + 16) == 0 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(struct GASEnvironment *))(*(_DWORD *)a3 + 4))(a1: a3) != 0 )
      GASEnvironment::LogScriptError(this: (GASEnvironment *)a3, a2: "Error: getter method is null.");
    return 0;
  }
  v7[1] = v12;
  LOBYTE(v12[0]) = 0;
  v8 = 0;
  v7[3] = 0;
  v7[4] = 0;
  v10 = 0;
  v11 = 0;
  v7[0] = &GASFnCall::`vftable';
  v7[2] = a4;
  v9 = a3;
  (*(void (__thiscall **)(_DWORD, _DWORD *, _DWORD, _DWORD))(**(_DWORD **)(v5 + 16) + 40))(
    a1: *(_DWORD *)(v5 + 16),
    a2: v7,
    a3: *(_DWORD *)(v5 + 20),
    a4: 0);
  GASFnCall::~GASFnCall(this: v7);
  GASValue::operator=(this: (int)a5, v: (tagWNDCLASSW *)v12);
  if ( LOBYTE(v12[0]) >= 5u )
    GASValue::DropRefs(this: v12, a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10080DD0
// Name: protected: class GASFunctionRef GASValue::ResolveFunctionName(class GASEnvironment const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASValue::ResolveFunctionName(_DWORD *this, int a2, int a3)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  bool v6; // zf
  vc_attributes::PreRangeAttribute *v7; // ecx
  struct GASFunctionObject *v8; // eax
  int v9; // eax

  v3 = a3;
  if ( a3 != 0 && *(_BYTE *)this == 11 )
  {
    a3 = *(_DWORD *)(*(_DWORD *)(a3 + 120) + 8);
    ++*(_DWORD *)(a3 + 8);
    v4 = *(this + 1);
    ++*(_DWORD *)(v4 + 8);
    v5 = a3;
    v6 = (*(_DWORD *)(a3 + 8))-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode(a1: v5);
    v7 = *(vc_attributes::PreRangeAttribute **)(v3 + 120);
    a3 = v4;
    v8 = GASGlobalContext::ResolveFunctionName(this: v7, a2: (const struct GASString *)&a3);
    if ( v8 != nullptr )
      *((_DWORD *)v8 + 2) = (*((_DWORD *)v8 + 2) + 1) & 0x8FFFFFFF;
    *(_BYTE *)(a2 + 8) = 0;
    *(_DWORD *)a2 = v8;
    if ( v8 != nullptr )
      *((_DWORD *)v8 + 2) = (*((_DWORD *)v8 + 2) + 1) & 0x8FFFFFFF;
    *(_DWORD *)(a2 + 4) = 0;
    if ( v8 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v8, a2: v3);
    v9 = a3;
    v6 = (*(_DWORD *)(a3 + 8))-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode(a1: v9);
    return a2;
  }
  else
  {
    *(_BYTE *)(a2 + 8) = 0;
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 0;
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080E90
// Name: public: GASValueGuard::GASValueGuard(class GASEnvironment const __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *__thiscall GASValueGuard::GASValueGuard(
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *this,
        int (__stdcall *penv)(HINSTANCE__ *, const char *, char *, int),
        tagWNDCLASSW *val)
{
  GFxMovieRoot *MovieRoot; // eax
  int v5; // eax

  this->m_pMemory = (struct UtlRBTreeNode_t<char const *,unsigned short> *)penv;
  GASValue::GASValue(this: (GASValue *)&this->m_nAllocationCount, v: val);
  if ( LOBYTE(val->style) == 7 )
  {
    if ( this->m_pMemory != nullptr && val->lpfnWndProc != nullptr )
    {
      MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)this->m_pMemory);
      GFxCharacterHandle::ResolveCharacter(
        this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)val->lpfnWndProc,
        a2: MovieRoot);
    }
    else
    {
      v5 = 0;
    }
    *((_DWORD *)this + 5) = v5;
    if ( v5 != 0 )
    {
      ++*(_DWORD *)(v5 + 4);
      return this;
    }
  }
  else
  {
    *((_DWORD *)this + 5) = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10080EF0
// Name: public: GASValueGuard::~GASValueGuard(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASValueGuard::~GASValueGuard(
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *this@<ecx>,
        int a2@<edi>)
{
  GRefCountNTSImpl *v3; // ecx

  v3 = *((GRefCountNTSImpl **)this + 5);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  if ( LOBYTE(this->m_nAllocationCount) >= 5u )
    GASValue::DropRefs(this: (GASValue *)&this->m_nAllocationCount, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10080F40
// Name: public: class GASObject __near * GASValue::ToObject(class GASEnvironment const __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__userpurge GASValue::ToObject@<eax>(
        GASValue *this@<ecx>,
        int a2@<edi>,
        const struct GASEnvironment *a3)
{
  struct GASObject *result; // eax
  struct GASObject *v4; // esi
  GRefCountNTSImpl *v5; // esi
  struct GASObject *v6; // edi
  GASValue v7[4]; // [esp+8h] [ebp-1Ch] BYREF
  struct GASObject *v8; // [esp+18h] [ebp-Ch] BYREF
  int v9; // [esp+1Ch] [ebp-8h]
  char v10; // [esp+20h] [ebp-4h]

  switch ( *(_BYTE *)this )
  {
    case 6:
      result = *((struct GASObject **)this + 1);
      break;
    case 8:
      result = *((struct GASObject **)this + 1);
      if ( result == nullptr )
        goto LABEL_24;
      break;
    case 9:
      if ( *(_BYTE *)this != 9 )
        goto LABEL_24;
      v5 = *((GRefCountNTSImpl **)a3 + 29);
      if ( v5 == nullptr )
        goto LABEL_24;
      ++v5->RefCount;
      LOBYTE(v7[0]) = 0;
      if ( GASValue::GetPropertyValue(
             this,
             a2: (int)a3,
             a3,
             a4: (struct GASObjectInterface *)&v5[15],
             a5: (struct GASValue *)v7) == 0 )
      {
        if ( LOBYTE(v7[0]) >= 5u )
          GASValue::DropRefs(this: v7, a2: (int)a3);
        GRefCountNTSImpl::Release(this: v5);
        goto LABEL_24;
      }
      v6 = GASValue::ToObject(this: v7, a2: a3);
      if ( LOBYTE(v7[0]) >= 5u )
        GASValue::DropRefs(this: v7, a2: (int)v6);
      GRefCountNTSImpl::Release(this: v5);
      result = v6;
      break;
    case 0xB:
      GASValue::ResolveFunctionName(this, a2: (int)&v8, (int)a3);
      if ( v8 != nullptr )
      {
        v4 = v8;
        if ( (v10 & 2) == 0 )
          GRefCountBaseGC<323>::Release(a1: (int)v8, a2);
        v8 = nullptr;
        if ( (v10 & 1) == 0 && v9 != 0 )
          GRefCountBaseGC<323>::Release(a1: v9, a2);
        result = v4;
      }
      else
      {
        v8 = nullptr;
        if ( (v10 & 1) != 0 || v9 == 0 )
          goto LABEL_24;
        GRefCountBaseGC<323>::Release(a1: v9, a2);
        result = nullptr;
      }
      break;
    default:
LABEL_24:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081070
// Name: public: class GASObjectInterface __near * GASValue::ToObjectInterface(class GASEnvironment const __near *)const
// Source: json
//------------------------------------------------------------------------------
_SERVICE_STATUS *__userpurge GASValue::ToObjectInterface@<eax>(int a1@<ecx>, int a2@<edi>, _SERVICE_STATUS *result)
{
  GFxMovieRoot *MovieRoot; // eax
  int v5; // eax
  struct GASObject *v7; // eax

  if ( *(_BYTE *)a1 == 7 )
  {
    if ( result != nullptr && *(_DWORD *)(a1 + 4) != 0 )
    {
      MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result);
      GFxCharacterHandle::ResolveCharacter(
        this: *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(a1 + 4),
        a2: MovieRoot);
      if ( v5 != 0 )
        return (_SERVICE_STATUS *)(v5 + 120);
    }
  }
  else
  {
    v7 = GASValue::ToObject(this: (GASValue *)a1, a2, a3: (const struct GASEnvironment *)result);
    if ( v7 != nullptr )
      return (_SERVICE_STATUS *)&v7[2];
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100810C0
// Name: public: class GASFunctionRef GASValue::ToFunction(class GASEnvironment const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASValue::ToFunction@<eax>(int a1@<ecx>, int a2@<edi>, int a3, int a4)
{
  int v5; // eax
  tagIMECHARPOSITION *v6; // eax

  if ( *(_BYTE *)a1 == 8 )
  {
    *(_BYTE *)(a3 + 8) = 0;
    v5 = *(_DWORD *)(a1 + 4);
    *(_DWORD *)a3 = v5;
    if ( v5 != 0 )
      *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
    *(_DWORD *)(a3 + 4) = 0;
    v6 = *(tagIMECHARPOSITION **)(a1 + 8);
    if ( v6 != nullptr )
      GASFunctionRefBase::SetLocalFrame(a1: a3, a2, result: v6, internal: *(_BYTE *)(a1 + 12) & 1);
    return a3;
  }
  else if ( *(_BYTE *)a1 == 11 )
  {
    GASValue::ResolveFunctionName(this: (_DWORD *)a1, a2: a3, a3: a4);
    return a3;
  }
  else
  {
    *(_BYTE *)(a3 + 8) = 0;
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = 0;
    return a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081140
// Name: public: void GASValue::SetAsObject(class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetAsObject(GASValue *this, struct GASObject *a2)
{
  const struct GASFunctionRefBase *v3; // eax
  int v4; // [esp+Ch] [ebp-Ch] BYREF
  int v5; // [esp+10h] [ebp-8h]
  char v6; // [esp+14h] [ebp-4h]

  if ( a2 != nullptr && ((int (__thiscall *)(struct GASObject *))a2[2].pNode[1].pNext)(a1: &a2[2]) == 23 )
  {
    v3 = (const struct GASFunctionRefBase *)((int (__thiscall *)(struct GASObject *, int *))a2[2].pNode[6].pNext)(
                                              a1: &a2[2],
                                              a2: &v4);
    GASValue::SetAsFunction(this, func: v3);
    if ( (v6 & 2) == 0 && v4 != 0 )
      GRefCountBaseGC<323>::Release(a1: v4, (int)a2);
    v4 = 0;
    if ( (v6 & 1) == 0 && v5 != 0 )
      GRefCountBaseGC<323>::Release(a1: v5, (int)a2);
  }
  else if ( *(_BYTE *)this != 6 || *((struct GASObject **)this + 1) != a2 )
  {
    GASValue::DropRefs(this, (int)a2);
    *(_BYTE *)this = 6;
    *((_DWORD *)this + 1) = a2;
    if ( a2 != nullptr )
      a2[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&a2[1].pNode->pNext + 1) & 0x8FFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100811E0
// Name: public: void GASValue::SetAsObjectInterface(class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetAsObjectInterface(GASValue *this, struct GASObjectInterface *a2)
{
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v3; // ecx
  _DWORD *v4; // esi
  _DWORD *v5; // eax

  if ( (unsigned int)((*(int (__thiscall **)(struct GASObjectInterface *))(*(_DWORD *)a2 + 8))(a1: a2) - 2) > 3 )
  {
    GASValue::SetAsObject(this, a2: (struct GASObject *)a2 - 2);
  }
  else
  {
    v3 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)((char *)a2 - 120);
    if ( a2 == (struct GASObjectInterface *)120 )
    {
      v4 = nullptr;
    }
    else
    {
      v4 = (_DWORD *)DWORD1(v3[6].m_pfnProxied);
      if ( v4 == nullptr )
      {
        GFxASCharacter::CreateCharacterHandle(this: v3);
        v4 = v5;
      }
    }
    if ( *(_BYTE *)this != 7 || *((_DWORD **)this + 1) != v4 )
    {
      GASValue::DropRefs(this, a2: (int)this);
      *(_BYTE *)this = 7;
      *((_DWORD *)this + 1) = v4;
      if ( v4 != nullptr )
        ++*v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081250
// Name: public: class GASString GASValue::ToStringImpl(class GASEnvironment __near *,int,bool)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GASValue::ToStringImpl(
        unsigned __int8 *this,
        int *a2,
        tagRID_DEVICE_INFO_KEYBOARD *a3,
        int precision,
        bool debug)
{
  int v5; // eax
  int v6; // edi
  int v8; // eax
  int v9; // ebx
  int v10; // ecx
  bool v11; // zf
  int v12; // eax
  char *v13; // eax
  struct GASStringNode *ConstStringNode; // eax
  int v15; // edi
  int v16; // ecx
  int v17; // edi
  _SERVICE_STATUS *v18; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v19; // ebx
  unsigned __int16 dwSubType; // ax
  int v21; // eax
  int v22; // ecx
  int v23; // edi
  int v24; // eax
  unsigned int dwType; // edi
  int v26; // ecx
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v27; // eax
  unsigned int v28; // eax
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  GASValue toStringFunc[4]; // [esp+20h] [ebp-7Ch] BYREF
  GASValue v34[4]; // [esp+30h] [ebp-6Ch] BYREF
  tagALTTABINFO *fnCall; // [esp+40h] [ebp-5Ch]
  int v36; // [esp+44h] [ebp-58h] BYREF
  int v37; // [esp+48h] [ebp-54h] BYREF
  int v38; // [esp+4Ch] [ebp-50h]
  char v39; // [esp+50h] [ebp-4Ch]
  tagRID_DEVICE_INFO_KEYBOARD *v40; // [esp+54h] [ebp-48h]
  char v41[28]; // [esp+58h] [ebp-44h] BYREF
  _DWORD v42[5]; // [esp+74h] [ebp-28h] BYREF
  char v43; // [esp+88h] [ebp-14h]
  tagRID_DEVICE_INFO_KEYBOARD *v44; // [esp+8Ch] [ebp-10h]
  int v45; // [esp+90h] [ebp-Ch]
  int v46; // [esp+94h] [ebp-8h]

  v5 = *(_DWORD *)(a3[5].dwType + 8);
  v6 = (int)&a3[5];
  *a2 = v5;
  ++*(_DWORD *)(v5 + 8);
  v8 = *this;
  v40 = a3;
  switch ( v8 )
  {
    case 0:
    case 10:
      v17 = *(_DWORD *)(*(_DWORD *)v6 + 212);
      goto LABEL_62;
    case 1:
      v17 = *(_DWORD *)(*(_DWORD *)v6 + 216);
      goto LABEL_62;
    case 2:
      v17 = *(_DWORD *)(*(_DWORD *)v6 + 4 * (*(this + 4) == 0) + 220);
      goto LABEL_62;
    case 3:
      if ( precision >= 0 )
        v12 = -precision;
      else
        v12 = 10;
      v13 = (char *)GASNumberUtil::ToString(value: *(double *)(this + 4), destStr: v41, destStrSize: 0x40u, ival: v12);
      goto LABEL_9;
    case 4:
      v13 = (char *)GASNumberUtil::IntToString(a1: *((_DWORD *)this + 1), a2: v41, a3: 0x40u);
LABEL_9:
      GASStringManager::CreateStringNode(
        this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v13);
      goto LABEL_10;
    case 5:
      v9 = *((_DWORD *)this + 1);
      ++*(_DWORD *)(v9 + 8);
      v10 = *a2;
      v11 = (*(_DWORD *)(*a2 + 8))-- == 1;
      if ( v11 )
        GASStringNode::ReleaseNode(a1: v10);
      *a2 = v9;
      return a2;
    case 6:
    case 7:
      LOBYTE(toStringFunc[0]) = 0;
      v18 = GASValue::ToObjectInterface(a1: (int)this, a2: v6, result: (_SERVICE_STATUS *)a3);
      fnCall = (tagALTTABINFO *)v18;
      if ( !debug
        && v18 != nullptr
        && (*(unsigned __int8 (__thiscall **)(_SERVICE_STATUS *, int, int, GASValue *))(v18->dwServiceType + 44))(
             a1: v18,
             a2: v6,
             a3: *(_DWORD *)v6 + 352,
             a4: toStringFunc) != 0 )
      {
        v19 = v40;
        dwSubType = v40[8].dwSubType;
        LOWORD(v40[8].dwSubType) = dwSubType + 1;
        if ( dwSubType < 0xFFu )
        {
          LOBYTE(v34[0]) = 0;
          GASValue::ToFunction(a1: (int)toStringFunc, a2: v6, a3: (int)&v37, a4: (int)v19);
          if ( v37 != 0 )
          {
            v42[2] = fnCall;
            v42[1] = v34;
            v42[0] = &GASFnCall::`vftable';
            v43 = 0;
            v42[3] = 0;
            v42[4] = 0;
            v44 = v19;
            v45 = 0;
            v46 = 0;
            (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v37 + 40))(a1: v37, a2: v42, a3: v38, a4: 0);
            GASFnCall::~GASFnCall(this: v42);
          }
          GASValue::ToStringImpl(a1: v34, a2: &v36, a3: v40, a4: -1, a5: 0);
          v21 = v36;
          ++*(_DWORD *)(v36 + 8);
          v22 = *a2;
          v11 = (*(_DWORD *)(*a2 + 8))-- == 1;
          v23 = v21;
          if ( v11 )
            GASStringNode::ReleaseNode(a1: v22);
          v24 = v36;
          *a2 = v23;
          v11 = (*(_DWORD *)(v24 + 8))-- == 1;
          if ( v11 )
            GASStringNode::ReleaseNode(a1: v24);
          if ( (v39 & 2) == 0 && v37 != 0 )
            GRefCountBaseGC<323>::Release(a1: v37, a2: v23);
          dwType = 0;
          v37 = 0;
          if ( (v39 & 1) == 0 && v38 != 0 )
            GRefCountBaseGC<323>::Release(a1: v38, a2: 0);
          v38 = 0;
          if ( LOBYTE(v34[0]) >= 5u )
            GASValue::DropRefs(this: v34, a2: 0);
          v19 = v40;
LABEL_37:
          --LOWORD(v19[8].dwSubType);
          goto LABEL_56;
        }
        dwType = *(_DWORD *)(*(_DWORD *)v6 + 344);
        ++*(_DWORD *)(dwType + 8);
        v26 = *a2;
        v11 = (*(_DWORD *)(*a2 + 8))-- == 1;
        if ( v11 )
          GASStringNode::ReleaseNode(a1: v26);
        *a2 = dwType;
        if ( (*(unsigned __int8 (__thiscall **)(tagRID_DEVICE_INFO_KEYBOARD *))(v19->dwType + 4))(a1: v19) == 0 )
          goto LABEL_37;
        GASEnvironment::LogScriptError(this: (GASEnvironment *)v19, a2: (const char *)&stru_1029DE50.m_pElements);
        --LOWORD(v19[8].dwSubType);
      }
      else if ( *this == 6
             && *((_DWORD *)this + 1) != 0
             && (v27 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*(int (__thiscall **)(int, tagRID_DEVICE_INFO_KEYBOARD *))(*(_DWORD *)(*((_DWORD *)this + 1) + 16) + 4))(
                                                                                                   a1: *((_DWORD *)this + 1)
                                                                                                 + 16,
                                                                                                   a2: v40)) != nullptr )
      {
        GASStringManager::CreateStringNode(this: *(GASStringManager **)(*(_DWORD *)v6 + 636), result: v27);
        dwType = v28;
        *(_DWORD *)(v28 + 8) += 2;
        v29 = *a2;
        v11 = (*(_DWORD *)(*a2 + 8))-- == 1;
        if ( v11 )
          GASStringNode::ReleaseNode(a1: v29);
        *a2 = dwType;
        v11 = (*(_DWORD *)(dwType + 8))-- == 1;
        if ( v11 )
          GASStringNode::ReleaseNode(a1: dwType);
      }
      else
      {
        if ( *this == 7 && *((_DWORD *)this + 1) != 0 )
          dwType = GASValue::GetCharacterNamePath(
                     (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this,
                     result: v40)->dwType;
        else
          dwType = *(_DWORD *)(*(_DWORD *)v6 + 348);
        ++*(_DWORD *)(dwType + 8);
        v30 = *a2;
        v11 = (*(_DWORD *)(*a2 + 8))-- == 1;
        if ( v11 )
          GASStringNode::ReleaseNode(a1: v30);
        *a2 = dwType;
      }
LABEL_56:
      if ( LOBYTE(toStringFunc[0]) >= 5u )
        GASValue::DropRefs(this: toStringFunc, a2: dwType);
      return a2;
    case 8:
    case 11:
      v17 = *(_DWORD *)(*(_DWORD *)v6 + 340);
      goto LABEL_62;
    case 9:
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DE50,
                          a3: 0xAu,
                          a4: 0);
      goto LABEL_10;
    case 12:
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DE3C,
                          a3: 0x10u,
                          a4: 0);
LABEL_10:
      v15 = (int)ConstStringNode;
      *((_DWORD *)ConstStringNode + 2) += 2;
      v16 = *a2;
      v11 = (*(_DWORD *)(*a2 + 8))-- == 1;
      if ( v11 )
        GASStringNode::ReleaseNode(a1: v16);
      *a2 = v15;
      v11 = (*(_DWORD *)(v15 + 8))-- == 1;
      if ( v11 )
        GASStringNode::ReleaseNode(a1: v15);
      return a2;
    default:
      v17 = *(_DWORD *)(*(_DWORD *)v6 + 196);
LABEL_62:
      ++*(_DWORD *)(v17 + 8);
      v31 = *a2;
      v11 = (*(_DWORD *)(*a2 + 8))-- == 1;
      if ( v11 )
        GASStringNode::ReleaseNode(a1: v31);
      *a2 = v17;
      return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081620
// Name: public: class GASString GASValue::ToDebugString(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GASValue::ToDebugString(unsigned __int8 *this, int *a2, tagRID_DEVICE_INFO_KEYBOARD *a3)
{
  GASValue::ToStringImpl(this, a2, a3, precision: -1, debug: true);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10081640
// Name: public: class GASString GASValue::ToStringVersioned(class GASEnvironment __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GASValue::ToStringVersioned(
        unsigned __int8 *this,
        int *a2,
        tagRID_DEVICE_INFO_KEYBOARD *a3,
        unsigned int version)
{
  int v4; // ecx

  if ( *this != 0 && *this != 10 )
  {
    GASValue::ToStringImpl(this, a2, a3, precision: -1, debug: false);
    return a2;
  }
  else
  {
    if ( version - 1 > 5 )
      v4 = *(_DWORD *)(a3[5].dwType + 212);
    else
      v4 = *(_DWORD *)(a3[5].dwType + 8);
    *a2 = v4;
    ++*(_DWORD *)(v4 + 8);
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100816A0
// Name: public: double GASValue::ToNumber(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
double __userpurge GASValue::ToNumber@<st0>(
        GASValue *this@<ecx>,
        int a2@<edi>,
        long double a3@<st0>,
        _SERVICE_STATUS *result)
{
  char v5; // al
  _SERVICE_STATUS *v7; // eax
  int v8; // edi
  unsigned __int16 dwServiceType; // ax
  double v10; // st7
  double v11; // st7
  const char *v12; // eax
  _DWORD v13[5]; // [esp+4h] [ebp-58h] BYREF
  char v14; // [esp+18h] [ebp-44h]
  _SERVICE_STATUS *v15; // [esp+1Ch] [ebp-40h]
  int v16; // [esp+20h] [ebp-3Ch]
  int v17; // [esp+24h] [ebp-38h]
  GASValue v18[4]; // [esp+28h] [ebp-34h] BYREF
  GASValue v19[4]; // [esp+38h] [ebp-24h] BYREF
  int v20; // [esp+48h] [ebp-14h] BYREF
  int v21; // [esp+4Ch] [ebp-10h]
  char v22; // [esp+50h] [ebp-Ch]
  double v23; // [esp+54h] [ebp-8h] BYREF

  v5 = *(_BYTE *)this;
  if ( *(_BYTE *)this == 3 )
    return *(double *)(this + 1);
  switch ( v5 )
  {
    case 4:
      return (double)*((int *)this + 1);
    case 5:
      if ( StringToNumber(a1: **((_DWORD **)this + 1), a2: a3, a3: &v23) )
        return v23;
      return GASNumberUtil::NaN();
    case 1:
      if ( LOBYTE(result[4].dwWin32ExitCode) <= 6u )
        return 0.0;
      return GASNumberUtil::NaN();
    case 2:
      if ( *((_BYTE *)this + 4) != 0 )
        return 1.0;
      return 0.0;
    case 7:
      return GASNumberUtil::NaN();
    default:
      break;
  }
  if ( (v5 != 6 || *((_DWORD *)this + 1) == 0) && v5 != 8 )
  {
    if ( LOBYTE(GASValue::IsUndefined(this).usPreferredNode) == 0
      || (unsigned int)LOBYTE(result[4].dwWin32ExitCode) - 1 <= 5 )
    {
      return 0.0;
    }
    return GASNumberUtil::NaN();
  }
  LOBYTE(v19[0]) = 0;
  v7 = GASValue::ToObjectInterface(a1: (int)this, a2, result);
  v8 = (int)v7;
  if ( result != nullptr
    && (*(unsigned __int8 (__thiscall **)(_SERVICE_STATUS *, unsigned int *, unsigned int, GASValue *))(v7->dwServiceType + 44))(
         a1: v7,
         a2: &result[4].dwControlsAccepted,
         a3: result[4].dwControlsAccepted + 356,
         a4: v19) != 0 )
  {
    dwServiceType = result[7].dwServiceType;
    LOWORD(result[7].dwServiceType) = dwServiceType + 1;
    if ( dwServiceType >= 0xFFu )
    {
      v23 = GASNumberUtil::NaN();
      if ( (*(unsigned __int8 (__thiscall **)(_SERVICE_STATUS *))(result->dwServiceType + 4))(a1: result) != 0 )
        GASEnvironment::LogScriptError(
          this: (GASEnvironment *)result,
          a2: "Error: Stack overflow, max level of 255 nested calls of valueOf is reached.\n");
    }
    else
    {
      LOBYTE(v18[0]) = 0;
      GASValue::ToFunction(a1: (int)v19, a2: v8, a3: (int)&v20, a4: (int)result);
      if ( v20 != 0 )
      {
        v13[1] = v18;
        v13[0] = &GASFnCall::`vftable';
        v13[2] = v8;
        v14 = 0;
        v13[3] = 0;
        v13[4] = 0;
        v15 = result;
        v16 = 0;
        v17 = 0;
        (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v20 + 40))(a1: v20, a2: v13, a3: v21, a4: 0);
        GASFnCall::~GASFnCall(this: v13);
      }
      if ( LOBYTE(GASValue::IsPrimitive(this: (char *)v18).usPreferredNode) != 0 )
        v10 = GASValue::ToNumber(this: v18, a2: (struct GASEnvironment *)result);
      else
        v10 = GASNumberUtil::NaN();
      v23 = v10;
      if ( (v22 & 2) == 0 && v20 != 0 )
        GRefCountBaseGC<323>::Release(a1: v20, a2: v8);
      v20 = 0;
      if ( (v22 & 1) == 0 && v21 != 0 )
        GRefCountBaseGC<323>::Release(a1: v21, a2: v8);
      v21 = 0;
      if ( LOBYTE(v18[0]) >= 5u )
      {
        GASValue::DropRefs(this: v18, a2: v8);
        --LOWORD(result[7].dwServiceType);
LABEL_42:
        if ( LOBYTE(v19[0]) >= 5u )
          GASValue::DropRefs(this: v19, a2: v8);
        return v23;
      }
    }
    --LOWORD(result[7].dwServiceType);
    goto LABEL_42;
  }
  if ( *(_BYTE *)this == 7 )
  {
    v11 = GASNumberUtil::NaN();
LABEL_41:
    v23 = v11;
    goto LABEL_42;
  }
  v12 = (const char *)(*(int (__thiscall **)(int, _SERVICE_STATUS *))(*(_DWORD *)v8 + 4))(a1: v8, a2: result);
  if ( v12 != nullptr )
  {
    v11 = atof(nptr: v12);
    goto LABEL_41;
  }
  if ( LOBYTE(v19[0]) >= 5u )
    GASValue::DropRefs(this: v19, a2: v8);
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10081900
// Name: public: long GASValue::ToInt32(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASValue::ToInt32@<eax>(GASValue *this@<ecx>, int a2@<edi>, long double a3@<st0>, _SERVICE_STATUS *a4)
{
  double v5; // st7
  int v6; // ecx
  double v; // [esp+8h] [ebp-10h]
  double v8; // [esp+10h] [ebp-8h]

  if ( *(_BYTE *)this == 4 )
    return *((_DWORD *)this + 1);
  v5 = GASValue::ToNumber(this, a2, a3, result: a4);
  v = v5;
  if ( 0.0 == v5 )
    return 0;
  v8 = v5;
  if ( (HIDWORD(v8) & 0x7FF00000) == 0x7FF00000 )
    return 0;
  if ( v5 >= -2147483648.0 && v5 <= 2147483647.0 )
    return (int)v5;
  v6 = (__int64)fmod(floor(X: fabs(v5)), 4294967296.0);
  if ( v < 0.0 )
    return -v6;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100819D0
// Name: public: unsigned long GASValue::ToUInt32(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASValue::ToUInt32@<eax>(GASValue *this@<ecx>, int a2@<edi>, long double a3@<st0>, _SERVICE_STATUS *a4)
{
  double v5; // st7
  int v6; // ecx
  double v7; // [esp+8h] [ebp-10h]
  double v8; // [esp+10h] [ebp-8h]

  if ( *(_BYTE *)this == 4 )
    return *((_DWORD *)this + 1);
  v5 = GASValue::ToNumber(this, a2, a3, result: a4);
  v7 = v5;
  if ( 0.0 == v5 )
    return 0;
  v8 = v5;
  if ( (HIDWORD(v8) & 0x7FF00000) == 0x7FF00000 )
    return 0;
  if ( v5 >= 0.0 && *(double *)&UINT32MAX.__vftable >= v5 )
    return (__int64)v5;
  v6 = (__int64)fmod(floor(X: fabs(v5)), 4294967296.0);
  if ( v7 < 0.0 )
    return -v6;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10081AC0
// Name: public: void GASValue::ConvertToNumber(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASValue::ConvertToNumber(int a1@<ecx>, int a2@<edi>, long double a3@<st0>, _SERVICE_STATUS *result)
{
  double v5; // [esp+4h] [ebp-8h]

  v5 = GASValue::ToNumber(this: (GASValue *)a1, a2, a3, result);
  if ( *(_BYTE *)a1 >= 5u )
    GASValue::DropRefs(this: (GASValue *)a1, a2);
  *(_BYTE *)a1 = 3;
  *(double *)(a1 + 4) = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10081B00
// Name: public: void GASValue::ConvertToStringVersioned(class GASEnvironment __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::ConvertToStringVersioned(GASValue *this, tagRID_DEVICE_INFO_KEYBOARD *a2, unsigned int a3)
{
  struct GASEnvironment *v4; // esi
  bool v5; // zf

  if ( *(_BYTE *)this != 0 && *(_BYTE *)this != 10 )
  {
    GASValue::ToStringImpl((unsigned __int8 *)this, (int *)&a2, a3: a2, precision: -1, debug: false);
    v4 = (struct GASEnvironment *)a2;
  }
  else
  {
    if ( a3 - 1 > 5 )
      v4 = *(struct GASEnvironment **)(a2[5].dwType + 212);
    else
      v4 = *(struct GASEnvironment **)(a2[5].dwType + 8);
    ++*((_DWORD *)v4 + 2);
  }
  GASValue::DropRefs(this, a2: (int)this);
  *(_BYTE *)this = 5;
  *((_DWORD *)this + 1) = v4;
  v5 = ++*((_DWORD *)v4 + 2) == 1;
  --*((_DWORD *)v4 + 2);
  if ( v5 )
    GASStringNode::ReleaseNode(a1: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10081B70
// Name: public: void GASValue::Div(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASValue::Div(unsigned int this@<ecx>, long double a2@<st0>, _SERVICE_STATUS *penv, tagWNDCLASSW *v)
{
  double v5; // st7
  long double v6; // st7
  long double res; // [esp+8h] [ebp-8h]

  res = GASValue::ToNumber((GASValue *)this, a2: (int)penv, a3: a2, result: penv);
  v5 = GASValue::ToNumber(this: (GASValue *)v, a2: (int)penv, a3: res, result: penv);
  if ( 0.0 == v5 )
  {
    if ( 0.0 == res )
    {
      v6 = GASNumberUtil::NaN();
    }
    else if ( res < 0.0 )
    {
      v6 = GASNumberUtil::NEGATIVE_INFINITY();
    }
    else
    {
      v6 = GASNumberUtil::POSITIVE_INFINITY();
    }
  }
  else
  {
    v6 = res / v5;
  }
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs((GASValue *)this, a2: (int)penv);
  *(long double *)(this + 4) = v6;
  *(_BYTE *)this = 3;
}

//------------------------------------------------------------------------------
// Address: 0x10081C00
// Name: public: void GASValue::StringConcat(class GASEnvironment __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASValue::StringConcat(
        GASValue *this@<ecx>,
        int a2@<edi>,
        tagRID_DEVICE_INFO_KEYBOARD *a3,
        _IMAGE_SYMBOL_EX *str)
{
  struct GASEnvironment *v5; // eax
  bool v6; // zf
  int v7; // eax
  int v8; // eax
  int v9; // [esp+4h] [ebp-4h] BYREF

  GASValue::ToStringImpl((unsigned __int8 *)this, a2: (int *)&a3, a3, precision: -1, debug: false);
  GASString::operator+(this: (char ***)&a3, a2: (unsigned __int8 ***)&v9, str);
  v5 = (struct GASEnvironment *)a3;
  v6 = a3->dwKeyboardMode-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode(a1: (int)v5);
  GASValue::DropRefs(this, a2);
  v7 = v9;
  *((_DWORD *)this + 1) = v9;
  *(_BYTE *)this = 5;
  ++*(_DWORD *)(v7 + 8);
  v8 = v9;
  v6 = (*(_DWORD *)(v9 + 8))-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode(a1: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10081C70
// Name: public: class GASValue GASValue::ToPrimitive(class GASEnvironment __near *,enum GASValue::Hint)const
// Source: json
//------------------------------------------------------------------------------
GASValue *__thiscall GASValue::ToPrimitive(GASValue *this, GASValue *a2, GASEnvironment *a3, int __formal)
{
  int v4; // edi
  char v5; // al
  GASEnvironment *v7; // esi
  GFxMovieRoot *MovieRoot; // eax
  struct GASObject *v9; // eax
  struct GASObject *v10; // ebx
  struct GASObject *v11; // eax
  unsigned __int16 v12; // ax
  int v13; // ecx
  GASValue *v14; // esi
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **p_ret; // ecx
  GFxMovieRoot *v16; // eax
  int v17; // eax
  int v18; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v19; // eax
  int v20; // eax
  bool v21; // zf
  GASEnvironment *v22; // ecx
  tagALTTABINFO *fnCall; // [esp+8h] [ebp-54h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **v24; // [esp+Ch] [ebp-50h]
  struct GASObject *v25; // [esp+10h] [ebp-4Ch]
  int v26; // [esp+14h] [ebp-48h]
  int v27; // [esp+18h] [ebp-44h]
  char v28; // [esp+1Ch] [ebp-40h]
  GASEnvironment *v29; // [esp+20h] [ebp-3Ch]
  int v30; // [esp+24h] [ebp-38h]
  int v31; // [esp+28h] [ebp-34h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v32; // [esp+2Ch] [ebp-30h] BYREF
  GASValue toValueFunc[4]; // [esp+3Ch] [ebp-20h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *ret; // [esp+4Ch] [ebp-10h] BYREF
  GASEnvironment *v35; // [esp+50h] [ebp-Ch] BYREF
  int v36; // [esp+54h] [ebp-8h]
  char v37; // [esp+58h] [ebp-4h]

  v4 = (int)this;
  v5 = *(_BYTE *)this;
  if ( *(_BYTE *)this != 6 && v5 != 7 && v5 != 8 )
  {
    if ( v5 == 11 )
    {
      GASValue::ResolveFunctionName(this, a2: (int)&v35, (int)a3);
      if ( v35 != nullptr )
      {
        GASValue::GASValue(this: a2, (int)a2, a3: (const struct GASFunctionRef *)&v35);
        if ( (v37 & 2) == 0 && v35 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v35, (int)a2);
        v35 = nullptr;
        if ( (v37 & 1) == 0 && v36 != 0 )
          GRefCountBaseGC<323>::Release(a1: v36, (int)a2);
        return a2;
      }
      v35 = nullptr;
      if ( (v37 & 1) == 0 && v36 != 0 )
        GRefCountBaseGC<323>::Release(a1: v36, a2: v4);
    }
    GASValue::GASValue(this: a2, v: (tagWNDCLASSW *)v4);
    return a2;
  }
  v7 = a3;
  LOBYTE(toValueFunc[0]) = 0;
  if ( v5 != 7 )
  {
    v11 = GASValue::ToObject(this, a2: (int)this, (const struct GASEnvironment *)a3);
    if ( v11 != nullptr )
    {
      v10 = v11 + 2;
      goto LABEL_25;
    }
LABEL_24:
    v10 = nullptr;
    goto LABEL_25;
  }
  if ( a3 == nullptr )
    goto LABEL_24;
  if ( *((_DWORD *)this + 1) == 0 )
    goto LABEL_24;
  MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: a3);
  GFxCharacterHandle::ResolveCharacter(
    this: *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v4 + 4),
    a2: MovieRoot);
  if ( v9 == nullptr )
    goto LABEL_24;
  v10 = v9 + 15;
LABEL_25:
  if ( v7 != nullptr
    && v10 != nullptr
    && ((unsigned __int8 (__thiscall *)(struct GASObject *, GASEnvironment *, int, GASValue *))v10->pNode[5].elem)(
         a1: v10,
         a2: v7 + 30,
         a3: *((_DWORD *)v7 + 30) + 356,
         a4: toValueFunc) != 0 )
  {
    v12 = *((_WORD *)v7 + 98);
    LOBYTE(v32) = 0;
    *((_WORD *)v7 + 98) = v12 + 1;
    if ( v12 >= 0xFFu )
    {
      if ( (*(unsigned __int8 (__thiscall **)(GASEnvironment *))(*v7 + 4))(a1: v7) != 0 )
        GASEnvironment::LogScriptError(
          this: v7,
          a2: "Error: Stack overflow, max level of 255 nested calls of valueOf is reached.\n");
    }
    else
    {
      GASValue::ToFunction(a1: (int)toValueFunc, a2: v4, a3: (int)&v35, a4: (int)v7);
      v13 = (int)v35;
      v4 = 0;
      if ( v35 != nullptr )
      {
        v24 = &v32;
        fnCall = (tagALTTABINFO *)&GASFnCall::`vftable';
        v25 = v10;
        v28 = 0;
        v26 = 0;
        v27 = 0;
        v29 = v7;
        v30 = 0;
        v31 = 0;
        (*(void (__thiscall **)(GASEnvironment *, tagALTTABINFO **, int, _DWORD))(*v35 + 40))(
          a1: v35,
          a2: &fnCall,
          a3: v36,
          a4: 0);
        GASFnCall::~GASFnCall(this: &fnCall);
        v13 = (int)v35;
      }
      if ( (v37 & 2) == 0 && v13 != 0 )
        GRefCountBaseGC<323>::Release(a1: v13, a2: 0);
      v35 = nullptr;
      if ( (v37 & 1) == 0 && v36 != 0 )
        GRefCountBaseGC<323>::Release(a1: v36, a2: 0);
    }
    --*((_WORD *)v7 + 98);
    v14 = a2;
    GASValue::GASValue(this: a2, v: (tagWNDCLASSW *)&v32);
    if ( (unsigned __int8)v32 < 5u )
      goto LABEL_57;
    p_ret = &v32;
    goto LABEL_56;
  }
  if ( *(_BYTE *)v4 == 7 && *(_DWORD *)(v4 + 4) != 0 )
  {
    v16 = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: v7);
    GFxCharacterHandle::ResolveCharacter(
      this: *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v4 + 4),
      a2: v16);
    if ( v17 != 0 )
      v18 = *(_DWORD *)(*(_DWORD *)(v4 + 4) + 12);
    else
      v18 = *(_DWORD *)(*((_DWORD *)v7 + 30) + 8);
    ++*(_DWORD *)(v18 + 8);
    LOBYTE(ret) = 5;
    v35 = (GASEnvironment *)v18;
  }
  else
  {
    if ( *(_BYTE *)v4 == 6
      && *(_DWORD *)(v4 + 4) != 0
      && (v19 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*(int (__thiscall **)(int, GASEnvironment *))(*(_DWORD *)(*(_DWORD *)(v4 + 4) + 16) + 4))(
                                                                                            a1: *(_DWORD *)(v4 + 4) + 16,
                                                                                            a2: v7)) != nullptr )
    {
      GASStringManager::CreateStringNode(this: *(GASStringManager **)(*((_DWORD *)v7 + 30) + 636), result: v19);
      ++*(_DWORD *)(v20 + 8);
      v21 = ++*(_DWORD *)(v20 + 8) == 1;
      --*(_DWORD *)(v20 + 8);
      LOBYTE(ret) = 5;
      v35 = (GASEnvironment *)v20;
      if ( !v21 )
        goto LABEL_54;
      v22 = (GASEnvironment *)v20;
    }
    else
    {
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)v4,
        a2: (int *)&a3,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v7,
        precision: -1,
        debug: false);
      v22 = a3;
      ++*((_DWORD *)a3 + 2);
      v21 = (*((_DWORD *)v22 + 2))-- == 1;
      LOBYTE(ret) = 5;
      v35 = v22;
      if ( !v21 )
        goto LABEL_54;
    }
    GASStringNode::ReleaseNode(a1: (int)v22);
  }
LABEL_54:
  v14 = a2;
  GASValue::GASValue(this: a2, v: (tagWNDCLASSW *)&ret);
  if ( (unsigned __int8)ret >= 5u )
  {
    p_ret = &ret;
LABEL_56:
    GASValue::DropRefs(this: p_ret, a2: v4);
  }
LABEL_57:
  if ( LOBYTE(toValueFunc[0]) >= 5u )
    GASValue::DropRefs(this: toValueFunc, a2: v4);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10081F60
// Name: public: void GASValue::SetPropertyValue(class GASEnvironment __near *,class GASObjectInterface __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall GASValue::SetPropertyValue(
        GASValue *this,
        int a2,
        __vc_attributes::iid_isAttribute *a3,
        tagWNDCLASSW *val,
        tagWNDCLASSW *a5)
{
  bool v5; // zf
  const char *limited_expression; // eax
  GASValue *v7; // eax
  int v8; // eax
  GASValue *v9; // ecx
  _DWORD v10[5]; // [esp+0h] [ebp-38h] BYREF
  char v11; // [esp+14h] [ebp-24h]
  __vc_attributes::iid_isAttribute *v12; // [esp+18h] [ebp-20h]
  int v13; // [esp+1Ch] [ebp-1Ch]
  int v14; // [esp+20h] [ebp-18h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *result; // [esp+24h] [ebp-14h] BYREF
  GASValue *v16; // [esp+34h] [ebp-4h]

  v5 = *(_BYTE *)this == 9;
  v16 = this;
  if ( v5 && a3 != nullptr )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 1) + 28) != 0 )
    {
      a3[2].limited_expression += 16;
      limited_expression = a3[2].limited_expression;
      LOBYTE(result) = 0;
      if ( limited_expression >= a3[4].limited_expression )
      {
        GASPagedStack<GASValue,32>::PushPage(this: a3 + 2);
        this = v16;
      }
      v7 = (GASValue *)a3[2].limited_expression;
      if ( v7 != nullptr )
      {
        GASValue::GASValue(this: v7, v: a5);
        this = v16;
      }
      v14 = ((a3[2].limited_expression - a3[3].limited_expression) >> 4) + 32 * (int)a3[7].limited_expression - 32;
      v8 = *((_DWORD *)this + 1);
      v10[1] = &result;
      v10[2] = val;
      v10[0] = &GASFnCall::`vftable';
      v11 = 0;
      v10[3] = 0;
      v10[4] = 0;
      v12 = a3;
      v13 = 1;
      (*(void (__thiscall **)(_DWORD, _DWORD *, _DWORD, _DWORD))(**(_DWORD **)(v8 + 28) + 40))(
        a1: *(_DWORD *)(v8 + 28),
        a2: v10,
        a3: *(_DWORD *)(v8 + 32),
        a4: 0);
      GASFnCall::~GASFnCall(this: v10);
      v9 = (GASValue *)a3[2].limited_expression;
      if ( *(_BYTE *)v9 >= 5u )
        GASValue::DropRefs(this: v9, a2: (int)a3);
      a3[2].limited_expression -= 16;
      if ( a3[2].limited_expression < a3[3].limited_expression )
        GASPagedStack<GASValue,32>::PopPage(this: a3 + 2);
      if ( (unsigned __int8)result >= 5u )
        GASValue::DropRefs(this: &result, a2: (int)a3);
    }
    else if ( (*((unsigned __int8 (__thiscall **)(__vc_attributes::iid_isAttribute *))a3->limited_expression + 1))(a1: a3) != 0 )
    {
      GASEnvironment::LogScriptError(this: (GASEnvironment *)a3, a2: UINT32MAX._M_d_name);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082080
// Name: public: void GASValue::Add(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASValue::Add(
        unsigned int this@<ecx>,
        int a2@<edi>,
        long double a3@<st0>,
        unsigned int penv,
        tagWNDCLASSW *v)
{
  unsigned int v5; // esi
  tagWNDCLASSW *v7; // eax
  tagWNDCLASSW *v8; // eax
  double v9; // st7
  bool v10; // cf
  double v11; // st7
  unsigned int v12; // edi
  unsigned int v13; // eax
  _OVERLAPPED *v14; // eax
  bool v15; // zf
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // [esp-4h] [ebp-3Ch]
  GASValue pv2[4]; // [esp+8h] [ebp-30h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *pv1; // [esp+18h] [ebp-20h] BYREF
  int v22; // [esp+1Ch] [ebp-1Ch]
  GASValue v23[2]; // [esp+28h] [ebp-10h] BYREF
  int v24[2]; // [esp+30h] [ebp-8h] BYREF

  v5 = penv;
  LOBYTE(pv1) = 0;
  LOBYTE(pv2[0]) = 0;
  v7 = (tagWNDCLASSW *)GASValue::ToPrimitive((GASValue *)this, a2: v23, a3: (GASEnvironment *)penv, __formal: 0);
  GASValue::operator=(this: (int)&pv1, v: v7);
  if ( LOBYTE(v23[0]) >= 5u )
    GASValue::DropRefs(this: v23, a2);
  v8 = (tagWNDCLASSW *)GASValue::ToPrimitive(this: (GASValue *)v, a2: v23, a3: (GASEnvironment *)v5, __formal: 0);
  GASValue::operator=(this: (int)pv2, v: v8);
  if ( LOBYTE(v23[0]) >= 5u )
    GASValue::DropRefs(this: v23, a2);
  if ( (_BYTE)pv1 == 5 || LOBYTE(pv2[0]) == 5 )
  {
    v19 = a2;
    v12 = *(unsigned __int8 *)(v5 + 124);
    GASValue::ConvertToStringVersioned(this: &pv1, a2: (tagRID_DEVICE_INFO_KEYBOARD *)v5, a3: v12);
    if ( LOBYTE(pv2[0]) != 0 && LOBYTE(pv2[0]) != 10 )
    {
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)pv2,
        a2: (int *)&penv,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v5,
        precision: -1,
        debug: false);
    }
    else
    {
      if ( v12 - 1 > 5 )
        v13 = *(_DWORD *)(*(_DWORD *)(v5 + 120) + 212);
      else
        v13 = *(_DWORD *)(*(_DWORD *)(v5 + 120) + 8);
      penv = v13;
      ++*(_DWORD *)(v13 + 8);
    }
    GASValue::ToStringImpl(
      this: (unsigned __int8 *)&pv1,
      a2: (int *)&v,
      a3: (tagRID_DEVICE_INFO_KEYBOARD *)v5,
      precision: -1,
      debug: false);
    GASString::operator+(this: (char ***)&v, a2: (unsigned __int8 ***)&v24[1], str: (_IMAGE_SYMBOL_EX *)&penv);
    v14 = (_OVERLAPPED *)v;
    v15 = v->cbClsExtra-- == 1;
    if ( v15 )
      GASStringNode::ReleaseNode(a1: (int)v14);
    GASValue::DropRefs(this: &pv1, a2: -1);
    v22 = v24[1];
    LOBYTE(pv1) = 5;
    ++*(_DWORD *)(v24[1] + 8);
    v16 = v24[1];
    v15 = (*(_DWORD *)(v24[1] + 8))-- == 1;
    if ( v15 )
      GASStringNode::ReleaseNode(a1: v16);
    v17 = penv;
    v15 = (*(_DWORD *)(penv + 8))-- == 1;
    if ( v15 )
      GASStringNode::ReleaseNode(a1: v17);
    GASValue::ToStringImpl(
      this: (unsigned __int8 *)&pv1,
      a2: (int *)&penv,
      a3: (tagRID_DEVICE_INFO_KEYBOARD *)v5,
      precision: -1,
      debug: false);
    if ( *(_BYTE *)this >= 5u )
      GASValue::DropRefs((GASValue *)this, a2: -1);
    v18 = penv;
    *(_BYTE *)this = 5;
    *(_DWORD *)(this + 4) = v18;
    v15 = ++*(_DWORD *)(v18 + 8) == 1;
    --*(_DWORD *)(v18 + 8);
    a2 = v19;
    if ( v15 )
      GASStringNode::ReleaseNode(a1: v18);
  }
  else
  {
    *(double *)v24 = GASValue::ToNumber(this: pv2, a2, a3, result: (_SERVICE_STATUS *)v5);
    v9 = GASValue::ToNumber(this: &pv1, a2, a3: *(long double *)v24, result: (_SERVICE_STATUS *)v5);
    v10 = *(_BYTE *)this < 5u;
    *(double *)v24 = v9 + *(double *)v24;
    if ( !v10 )
      GASValue::DropRefs((GASValue *)this, a2);
    v11 = *(double *)v24;
    *(_BYTE *)this = 3;
    *(double *)(this + 4) = v11;
  }
  if ( LOBYTE(pv2[0]) >= 5u )
    GASValue::DropRefs(this: pv2, a2);
  if ( (unsigned __int8)pv1 >= 5u )
    GASValue::DropRefs(this: &pv1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10082230
// Name: public: void GASValue::Add(class GASEnvironment __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASValue::Add(
        GASValue *this@<ecx>,
        int a2@<edi>,
        long double a3@<st0>,
        struct GASEnvironment *a4,
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v2)
{
  struct GASEnvironment *v5; // esi
  tagWNDCLASSW *v7; // eax
  unsigned int v8; // edi
  _IMAGE_SYMBOL_EX *v9; // edi
  int v10; // eax
  bool v11; // zf
  struct GASEnvironment *v12; // eax
  int v13; // eax
  int v14; // ecx
  double v15; // st7
  bool v16; // cf
  double v17; // st7
  int v18; // [esp-4h] [ebp-34h]
  GASValue v19[4]; // [esp+8h] [ebp-28h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *pv1; // [esp+18h] [ebp-18h] BYREF
  struct GASEnvironment *v21; // [esp+1Ch] [ebp-14h]
  double v22; // [esp+28h] [ebp-8h] BYREF

  v5 = a4;
  LOBYTE(pv1) = 0;
  v7 = (tagWNDCLASSW *)GASValue::ToPrimitive(this, a2: v19, a3: (GASEnvironment *)a4, __formal: 0);
  GASValue::operator=(this: (int)&pv1, v: v7);
  if ( LOBYTE(v19[0]) >= 5u )
    GASValue::DropRefs(this: v19, a2);
  if ( (_BYTE)pv1 == 5 )
  {
    v18 = a2;
    v8 = *((unsigned __int8 *)v5 + 124);
    GASValue::ConvertToStringVersioned(this: &pv1, a2: (tagRID_DEVICE_INFO_KEYBOARD *)v5, a3: v8);
    v19[1] = v2;
    LOBYTE(v19[0]) = 4;
    v9 = (_IMAGE_SYMBOL_EX *)GASValue::ToStringVersioned(
                               this: (unsigned __int8 *)v19,
                               a2: (int *)&v22 + 1,
                               a3: (tagRID_DEVICE_INFO_KEYBOARD *)v5,
                               version: v8);
    GASValue::ToStringImpl(
      this: (unsigned __int8 *)&pv1,
      a2: (int *)&v2,
      a3: (tagRID_DEVICE_INFO_KEYBOARD *)v5,
      precision: -1,
      debug: false);
    GASString::operator+(this: (char ***)&v2, a2: (unsigned __int8 ***)&a4, str: v9);
    v10 = (int)v2;
    v11 = v2->m_nGrowSize-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode(a1: v10);
    GASValue::DropRefs(this: &pv1, a2: -1);
    v21 = a4;
    LOBYTE(pv1) = 5;
    ++*((_DWORD *)a4 + 2);
    v12 = a4;
    v11 = (*((_DWORD *)a4 + 2))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode(a1: (int)v12);
    v13 = HIDWORD(v22);
    v11 = (*(_DWORD *)(HIDWORD(v22) + 8))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode(a1: v13);
    if ( LOBYTE(v19[0]) >= 5u )
      GASValue::DropRefs(this: v19, a2: -1);
    GASValue::ToStringImpl(
      this: (unsigned __int8 *)&pv1,
      a2: (int *)&v2,
      a3: (tagRID_DEVICE_INFO_KEYBOARD *)v5,
      precision: -1,
      debug: false);
    if ( *(_BYTE *)this >= 5u )
      GASValue::DropRefs(this, a2: -1);
    v14 = (int)v2;
    *(_BYTE *)this = 5;
    *((_DWORD *)this + 1) = v14;
    v11 = ++*(_DWORD *)(v14 + 8) == 1;
    --*(_DWORD *)(v14 + 8);
    a2 = v18;
    if ( v11 )
      GASStringNode::ReleaseNode(a1: v14);
  }
  else
  {
    v15 = GASValue::ToNumber(this: &pv1, a2, a3, result: (_SERVICE_STATUS *)v5);
    v16 = *(_BYTE *)this < 5u;
    v22 = v15 + (double)(int)v2;
    if ( !v16 )
      GASValue::DropRefs(this, a2);
    v17 = v22;
    *(_BYTE *)this = 3;
    *(double *)(this + 1) = v17;
  }
  if ( (unsigned __int8)pv1 >= 5u )
    GASValue::DropRefs(this: &pv1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10082380
// Name: public: bool GASValue::IsEqual(class GASEnvironment __near *,class GASValue const __near &)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge GASValue::IsEqual@<al>(
        GASValue *this@<ecx>,
        long double a2@<st0>,
        tagRID_DEVICE_INFO_KEYBOARD *result,
        GASValue *v)
{
  char v5; // al
  char v6; // dl
  GASValue *v7; // esi
  char v8; // bl
  char v9; // cl
  tagRID_DEVICE_INFO_KEYBOARD *v10; // ebx
  bool v11; // bl
  char v12; // al
  tagRID_DEVICE_INFO_KEYBOARD *v13; // ebx
  bool v14; // bl
  tagRID_DEVICE_INFO_KEYBOARD *v15; // ecx
  tagRID_DEVICE_INFO_KEYBOARD *v16; // esi
  unsigned int dwKeyboardMode; // eax
  bool v18; // bl
  tagRID_DEVICE_INFO_KEYBOARD *v20; // ebx
  bool v21; // bl
  GViewport *v22; // ecx
  double v23; // st7
  GViewport *v24; // ecx
  char v25; // al
  char v26; // bl
  char v27; // al
  char v28; // al
  tagRID_DEVICE_INFO_KEYBOARD *v29; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v30; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v31; // ebx
  bool IsEqual; // bl
  tagRID_DEVICE_INFO_KEYBOARD *v33; // ebx
  int v34; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v35; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *CharacterNamePath; // esi
  GASValue v37; // [esp+14h] [ebp-40h] BYREF
  double v38; // [esp+18h] [ebp-3Ch]
  GASValue v39; // [esp+24h] [ebp-30h] BYREF
  double v40; // [esp+28h] [ebp-2Ch]
  GASValue v41; // [esp+34h] [ebp-20h] BYREF
  double v42; // [esp+38h] [ebp-1Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *primVal; // [esp+44h] [ebp-10h] BYREF
  _BYTE v44[12]; // [esp+48h] [ebp-Ch] OVERLAPPED

  v5 = *(_BYTE *)this;
  v6 = *(_BYTE *)this == 0 || v5 == 10 || v5 == 1;
  v7 = v;
  v8 = *(_BYTE *)v;
  v9 = *(_BYTE *)v == 0 || v8 == 10 || v8 == 1;
  if ( v6 != 0 || v9 != 0 )
    return v6 == v9;
  switch ( v5 )
  {
    case 2:
      v31 = result;
      v38 = GASValue::ToNumber(this, a2: (int)this, a3: a2, (_SERVICE_STATUS *)result);
      LOBYTE(v37) = 3;
      IsEqual = GASValue::IsEqual(this: &v37, result: v31, a3: (const struct GASValue *)v7);
      if ( (unsigned __int8)v37 >= 5u )
        GASValue::DropRefs(this: &v37, a2: (int)this);
      v12 = IsEqual;
      break;
    case 3:
      if ( v8 == 2 )
      {
        v23 = GASValue::ToNumber(this: v, a2: (int)this, a3: a2, (_SERVICE_STATUS *)result);
      }
      else
      {
        if ( LOBYTE(GASValue::IsFunction(this: v).usPreferredNode) != 0 || v8 == 6 )
        {
          v29 = result;
          GASValue::ToPrimitive(this: v7, a2: &primVal, a3: (GASEnvironment *)result, __formal: 0);
          if ( LOBYTE(GASValue::IsPrimitive(this: (char *)&primVal).usPreferredNode) == 0 )
            goto LABEL_33;
          v21 = GASValue::IsEqual(this, result: v29, a3: (const struct GASValue *)&primVal);
          if ( (unsigned __int8)primVal < 5u )
            goto LABEL_32;
          goto LABEL_75;
        }
        v23 = GASValue::ToNumber(this: v7, a2: (int)this, a3: a2, (_SERVICE_STATUS *)result);
      }
      *(double *)&v44[4] = v23;
      GASNumberUtil::IsNaN(
        v: v22,
        u: COERCE_UNSIGNED_INT64(*(double *)(this + 1)),
        u_4: HIDWORD(COERCE_UNSIGNED_INT64(*(double *)(this + 1))));
      v26 = v25;
      if ( v25 != 0 )
      {
        GASNumberUtil::IsNaN(v: v24, u: *(int *)&v44[4], u_4: *(int *)&v44[8]);
        if ( v27 != 0 )
          return 1;
        if ( v26 != 0 )
          goto LABEL_35;
      }
      GASNumberUtil::IsNaN(v: v24, u: *(int *)&v44[4], u_4: *(int *)&v44[8]);
      if ( v28 != 0 )
        goto LABEL_35;
      v12 = *(double *)&v44[4] == *(double *)(this + 1);
      break;
    case 4:
      if ( v8 == 3 )
      {
        *(double *)v44 = (double)*((int *)this + 1);
        LOBYTE(primVal) = 3;
        v21 = GASValue::IsEqual(this: &primVal, result, a3: (const struct GASValue *)v);
        if ( (unsigned __int8)primVal < 5u )
          goto LABEL_32;
        goto LABEL_75;
      }
      if ( v8 == 2 )
      {
        v12 = *((_DWORD *)this + 1) == GASValue::ToInt32(this: v, a2: (int)this, a3: a2, a4: (_SERVICE_STATUS *)result);
      }
      else
      {
        if ( LOBYTE(GASValue::IsFunction(this: v).usPreferredNode) != 0 || v8 == 6 )
        {
          v30 = result;
          GASValue::ToPrimitive(this: v7, a2: &primVal, a3: (GASEnvironment *)result, __formal: 0);
          if ( LOBYTE(GASValue::IsPrimitive(this: (char *)&primVal).usPreferredNode) == 0 )
            goto LABEL_33;
          v21 = GASValue::IsEqual(this, result: v30, a3: (const struct GASValue *)&primVal);
          if ( (unsigned __int8)primVal < 5u )
            goto LABEL_32;
          goto LABEL_75;
        }
        v12 = *((_DWORD *)this + 1) == GASValue::ToInt32(this: v7, a2: (int)this, a3: a2, a4: (_SERVICE_STATUS *)result);
      }
      break;
    case 5:
      if ( LOBYTE(GASValue::IsNumber(this: v).usPreferredNode) != 0 )
      {
        v10 = result;
        v42 = GASValue::ToNumber(this, a2: (int)this, a3: a2, (_SERVICE_STATUS *)result);
        LOBYTE(v41) = 3;
        v11 = GASValue::IsEqual(this: &v41, result: v10, a3: (const struct GASValue *)v7);
        if ( (unsigned __int8)v41 >= 5u )
          GASValue::DropRefs(this: &v41, a2: (int)this);
        v12 = v11;
      }
      else if ( v8 == 2 )
      {
        v13 = result;
        v40 = GASValue::ToNumber(this: v7, a2: (int)this, a3: a2, (_SERVICE_STATUS *)result);
        LOBYTE(v39) = 3;
        v14 = GASValue::IsEqual(this, result: v13, a3: (const struct GASValue *)&v39);
        if ( (unsigned __int8)v39 >= 5u )
          GASValue::DropRefs(this: &v39, a2: (int)this);
        v12 = v14;
      }
      else
      {
        if ( LOBYTE(GASValue::IsFunction(this: v7).usPreferredNode) != 0 || v8 == 6 )
        {
          v20 = result;
          GASValue::ToPrimitive(this: v7, a2: &primVal, a3: (GASEnvironment *)result, __formal: 0);
          if ( LOBYTE(GASValue::IsPrimitive(this: (char *)&primVal).usPreferredNode) == 0 )
            goto LABEL_33;
          v21 = GASValue::IsEqual(this, result: v20, a3: (const struct GASValue *)&primVal);
          if ( (unsigned __int8)primVal >= 5u )
            GASValue::DropRefs(this: &primVal, a2: (int)this);
          goto LABEL_32;
        }
        GASValue::ToStringImpl(this: (unsigned __int8 *)v7, a2: (int *)&result, a3: result, precision: -1, debug: false);
        v15 = *((tagRID_DEVICE_INFO_KEYBOARD **)this + 1);
        v16 = result;
        dwKeyboardMode = v15->dwKeyboardMode;
        v18 = v15 == result;
        v15->dwKeyboardMode = dwKeyboardMode;
        if ( dwKeyboardMode == 0 )
          GASStringNode::ReleaseNode(a1: (int)v15);
        if ( v16->dwKeyboardMode-- == 1 )
          GASStringNode::ReleaseNode(a1: (int)v16);
        v12 = v18;
      }
      break;
    case 6:
    case 8:
      if ( LOBYTE(GASValue::IsNumber(this: v).usPreferredNode) != 0 || v8 == 5 || v8 == 2 )
      {
        v33 = result;
        GASValue::ToPrimitive(this, a2: &primVal, a3: (GASEnvironment *)result, __formal: 0);
        if ( LOBYTE(GASValue::IsPrimitive(this: (char *)&primVal).usPreferredNode) == 0 )
        {
LABEL_33:
          if ( (unsigned __int8)primVal >= 5u )
            GASValue::DropRefs(this: &primVal, a2: (int)this);
          goto LABEL_35;
        }
        v21 = GASValue::IsEqual(this: &primVal, result: v33, a3: (const struct GASValue *)v7);
        if ( (unsigned __int8)primVal < 5u )
        {
LABEL_32:
          v12 = v21;
        }
        else
        {
LABEL_75:
          GASValue::DropRefs(this: &primVal, a2: (int)this);
          v12 = v21;
        }
      }
      else if ( *(_BYTE *)this == 6 && v8 == 6 )
      {
        v12 = *((_DWORD *)this + 1) == *((_DWORD *)v7 + 1);
      }
      else
      {
        if ( *(_BYTE *)this != 8 || v8 != 8 )
          goto LABEL_35;
        v12 = *((_DWORD *)this + 1) == *((_DWORD *)v7 + 1);
      }
      break;
    case 7:
      if ( v8 == 7 )
      {
        v34 = *((_DWORD *)this + 1);
        if ( v34 != 0 && *((_DWORD *)v + 1) != 0 )
        {
          v35 = result;
          CharacterNamePath = GASValue::GetCharacterNamePath(
                                this: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)v,
                                result);
          v12 = GASValue::GetCharacterNamePath(
                  (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this,
                  result: v35)->dwType == CharacterNamePath->dwType;
        }
        else
        {
          v12 = v34 == *((_DWORD *)v + 1);
        }
      }
      else
      {
LABEL_35:
        v12 = 0;
      }
      break;
    default:
      v12 = v5 == v8;
      break;
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10082830
// Name: public: class GASValue GASValue::Compare(class GASEnvironment __near *,class GASValue const __near &,int)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__userpurge GASValue::Compare@<eax>(
        GASValue *a1@<ecx>,
        long double a2@<st0>,
        _BYTE *a3,
        tagRID_DEVICE_INFO_KEYBOARD *a4,
        _IMAGE_SYMBOL_EX a5)
{
  signed int Long; // edi
  char IsEqual; // cl
  tagRID_DEVICE_INFO_KEYBOARD *v8; // esi
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // al
  bool v11; // al
  tagRID_DEVICE_INFO_KEYBOARD *v12; // ecx
  bool v13; // zf
  _BYTE *v14; // esi
  unsigned int Short; // ecx
  bool v16; // cf
  double v17; // st7
  GViewport *v18; // ecx
  GViewport *v19; // ecx
  char v20; // al
  GViewport *v21; // ecx
  char v22; // al
  char v23; // al
  GViewport *v24; // ecx
  char v25; // al
  char v26; // al
  GViewport *v27; // ecx
  char v28; // al
  GViewport *v29; // ecx
  char v30; // al
  GViewport *v31; // ecx
  char v32; // al
  char v33; // al
  GASValue v34[4]; // [esp+14h] [ebp-38h] BYREF
  GASValue v35[4]; // [esp+24h] [ebp-28h] BYREF
  double v36; // [esp+34h] [ebp-18h]
  double v37; // [esp+3Ch] [ebp-10h]
  double v38; // [esp+44h] [ebp-8h]

  Long = a5.N.Name.Long;
  if ( a5.N.Name.Long == 0 )
  {
    IsEqual = GASValue::IsEqual(this: a1, a2, result: a4, v: (GASValue *)a5.N.Name.Short);
    *a3 = 2;
    a3[4] = IsEqual;
    return a3;
  }
  v8 = a4;
  GASValue::ToPrimitive(this: a1, a2: v35, a3: (GASEnvironment *)a4, __formal: 0);
  GASValue::ToPrimitive(this: (GASValue *)a5.N.Name.Short, a2: v34, a3: (GASEnvironment *)v8, __formal: 0);
  v9 = (unsigned __int8)v35[0];
  v10 = (unsigned __int8)v34[0];
  if ( LOBYTE(v35[0]) == 5 && LOBYTE(v34[0]) == 5 )
  {
    if ( Long >= 0 )
    {
      Long = -1;
      GASValue::ToStringImpl(this: (unsigned __int8 *)v34, a2: (int *)&a5, a3: v8, precision: -1, debug: false);
      GASValue::ToStringImpl(this: (unsigned __int8 *)v35, a2: (int *)&a4, a3: v8, precision: -1, debug: false);
      v11 = GASString::operator>(this: (const char ***)&a4, result: &a5);
    }
    else
    {
      Long = -1;
      GASValue::ToStringImpl(this: (unsigned __int8 *)v34, a2: (int *)&a5, a3: v8, precision: -1, debug: false);
      GASValue::ToStringImpl(this: (unsigned __int8 *)v35, a2: (int *)&a4, a3: v8, precision: -1, debug: false);
      v11 = GASString::operator<(this: (const char ***)&a4, result: &a5);
    }
    v12 = a4;
    v13 = a4->dwKeyboardMode-- == 1;
    v14 = a3;
    a3[4] = v11;
    *a3 = 2;
    if ( v13 )
      GASStringNode::ReleaseNode(a1: (int)v12);
    Short = a5.N.Name.Short;
    v13 = (*(_DWORD *)(a5.N.Name.Short + 8))-- == 1;
    if ( v13 )
      GASStringNode::ReleaseNode(a1: Short);
    goto LABEL_41;
  }
  if ( LOBYTE(v8[5].dwSubType) > 6u
    && (LOBYTE(v35[0]) == 0 || LOBYTE(v35[0]) == 10 || LOBYTE(v34[0]) == 0 || LOBYTE(v34[0]) == 10) )
  {
    v14 = a3;
    *a3 = 0;
    if ( v10 >= 5u )
    {
      GASValue::DropRefs(this: v34, a2: Long);
      v9 = (unsigned __int8)v35[0];
    }
    v16 = v9 < 5u;
    goto LABEL_44;
  }
  v17 = GASValue::ToNumber(this: v35, a2: Long, a3: a2, result: (_SERVICE_STATUS *)v8);
  if ( Long >= 0 )
  {
    v38 = v17;
    v37 = GASValue::ToNumber(this: v34, a2: Long, a3: v17, result: (_SERVICE_STATUS *)v8);
  }
  else
  {
    v37 = v17;
    v38 = GASValue::ToNumber(this: v34, a2: Long, a3: v17, result: (_SERVICE_STATUS *)v8);
  }
  v36 = v37;
  v18 = (GViewport *)HIDWORD(v36);
  if ( (HIDWORD(v36) & 0x7FF00000) == 0x7FF00000
    && (v18 = (GViewport *)(HIDWORD(v36) & 0xFFFFF), (HIDWORD(v36) & 0xFFFFF | LODWORD(v36)) != 0)
    || (GASNumberUtil::IsNaN(v: v18, u: SLODWORD(v38), u_4: SHIDWORD(v38)), v20 != 0) )
  {
    v14 = a3;
    *a3 = 0;
    goto LABEL_41;
  }
  if ( v38 != v37 )
  {
    GASNumberUtil::IsNEGATIVE_ZERO(v: v19);
    if ( v22 == 0 || (GASNumberUtil::IsPOSITIVE_ZERO(v: v21), v23 == 0) )
    {
      GASNumberUtil::IsNEGATIVE_ZERO(v: v21);
      if ( v25 == 0 || (GASNumberUtil::IsPOSITIVE_ZERO(v: v24), v26 == 0) )
      {
        GASNumberUtil::IsPOSITIVE_INFINITY(v: v24, va: SLODWORD(v37), v_4: SHIDWORD(v37));
        if ( v28 == 0 )
        {
          GASNumberUtil::IsPOSITIVE_INFINITY(v: v27, va: SLODWORD(v38), v_4: SHIDWORD(v38));
          if ( v30 != 0 )
          {
            v14 = a3;
            *a3 = 2;
            a3[4] = 1;
            goto LABEL_41;
          }
          GASNumberUtil::IsNEGATIVE_INFINITY(v: v29, u: SLODWORD(v38), u_4: SHIDWORD(v38));
          if ( v32 == 0 )
          {
            GASNumberUtil::IsNEGATIVE_INFINITY(v: v31, u: SLODWORD(v37), u_4: SHIDWORD(v37));
            if ( v33 != 0 )
            {
              v14 = a3;
              *a3 = 2;
              a3[4] = 1;
              goto LABEL_41;
            }
            if ( v38 > v37 )
            {
              v14 = a3;
              *a3 = 2;
              a3[4] = 1;
              goto LABEL_41;
            }
          }
        }
      }
    }
  }
  v14 = a3;
  *a3 = 2;
  a3[4] = 0;
LABEL_41:
  if ( LOBYTE(v34[0]) >= 5u )
    GASValue::DropRefs(this: v34, a2: Long);
  v16 = LOBYTE(v35[0]) < 5u;
LABEL_44:
  if ( !v16 )
    GASValue::DropRefs(this: v35, a2: Long);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x1028A370
// Name: _dynamic_initializer_for__VALUE_BANK__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__VALUE_BANK__()
{
  `eh vector constructor iterator'(
    ptr: VALUE_BANK,
    size: 0x10u,
    count: 32,
    pCtor: (void (__thiscall *)(void *))GFxResourceKey::GFxResourceKey,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
  return atexit(func: dynamic_atexit_destructor_for__VALUE_BANK__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A3A0
// Name: _dynamic_initializer_for__VALUE_ARRAY_BANK__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__VALUE_ARRAY_BANK__()
{
  `eh vector constructor iterator'(
    ptr: VALUE_ARRAY_BANK,
    size: 0x10u,
    count: 9,
    pCtor: (void (__thiscall *)(void *))GFxResourceKey::GFxResourceKey,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
  return atexit(func: dynamic_atexit_destructor_for__VALUE_ARRAY_BANK__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C090
// Name: _dynamic_atexit_destructor_for__VALUE_BANK__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__VALUE_BANK__()
{
  `eh vector destructor iterator'(
    ptr: VALUE_BANK,
    size: 0x10u,
    count: 32,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
}

//------------------------------------------------------------------------------
// Address: 0x1028C0B0
// Name: _dynamic_atexit_destructor_for__VALUE_ARRAY_BANK__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__VALUE_ARRAY_BANK__()
{
  `eh vector destructor iterator'(
    ptr: VALUE_ARRAY_BANK,
    size: 0x10u,
    count: 9,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
}

//------------------------------------------------------------------------------
// Address: 0x1028A3D0
// Name: _dynamic_initializer_for__g_ColorCorrectionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ColorCorrectionSystem__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ColorCorrectionSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A3E0
// Name: _dynamic_initializer_for____g_CreateCColorCorrectionSystemIColorCorrectionSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCColorCorrectionSystemIColorCorrectionSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCColorCorrectionSystemIColorCorrectionSystem_reg,
           fn: (void *(__cdecl *)())_CreateCColorCorrectionSystemIColorCorrectionSystem_interface,
           pName: "COLORCORRECTION_VERSION_1");
}

//------------------------------------------------------------------------------
// Address: 0x1028A400
// Name: _dynamic_initializer_for__mat_processtoolvars__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_processtoolvars__()
{
  ConVar::ConVar(this: &mat_processtoolvars, pName: "mat_processtoolvars", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_processtoolvars__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A430
// Name: _dynamic_initializer_for__EditorRenderStateList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__EditorRenderStateList_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &EditorRenderStateList_t::s_Allocator,
    blockSize: 2304,
    numElements: 256,
    growMode: 1,
    pszAllocOwner: "EditorRenderStateList_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__EditorRenderStateList_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A460
// Name: _dynamic_initializer_for__StandardRenderStateList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__StandardRenderStateList_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &StandardRenderStateList_t::s_Allocator,
    blockSize: 288,
    numElements: 256,
    growMode: 1,
    pszAllocOwner: "StandardRenderStateList_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__StandardRenderStateList_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C0D0
// Name: _dynamic_atexit_destructor_for__g_ColorCorrectionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ColorCorrectionSystem__()
{
  ColorCorrectionLookup_t **m_pMemory; // eax

  m_pMemory = g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_pMemory;
  g_ColorCorrectionSystem.m_ColorCorrectionList.m_Size = 0;
  if ( g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_pMemory = nullptr;
    }
    g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_nAllocationCount = 0;
  }
  g_ColorCorrectionSystem.m_ColorCorrectionList.m_pElements = m_pMemory;
  if ( g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_pMemory = nullptr;
    }
    g_ColorCorrectionSystem.m_ColorCorrectionList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C170
// Name: _dynamic_atexit_destructor_for__mat_processtoolvars__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_processtoolvars__()
{
  ConVar::~ConVar(this: &mat_processtoolvars);
}

//------------------------------------------------------------------------------
// Address: 0x1028C180
// Name: _dynamic_atexit_destructor_for__EditorRenderStateList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__EditorRenderStateList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &EditorRenderStateList_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1028C190
// Name: _dynamic_atexit_destructor_for__StandardRenderStateList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__StandardRenderStateList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &StandardRenderStateList_t::s_Allocator);
}
