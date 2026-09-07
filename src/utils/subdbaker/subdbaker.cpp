// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/subdbaker/subdbaker.cpp
// Functions: 63
// ============================================================

#include "utils\subdbaker\subdbaker.h"

//------------------------------------------------------------------------------
// Address: 0x0040C590
// Name: public: virtual class CJobResult __near * CRayTraceNearCageJob::GetJobResult(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRayTraceNearCageJob::GetJobResult(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040D080
// Name: public: struct OBJ_VERTEX __near * std::allocator<struct OBJ_VERTEX>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
OBJ_VERTEX *__thiscall std::allocator<OBJ_VERTEX>::allocate(std::allocator<OBJ_VERTEX> *this, unsigned int _Count)
{
  OBJ_VERTEX *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x4EC4EC4 || (result = (OBJ_VERTEX *)operator new(nSize: 52 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D0E0
// Name: public: struct CacheEntry __near * __near * std::allocator<struct CacheEntry __near *>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CacheEntry **__thiscall std::allocator<CacheEntry *>::allocate(std::allocator<CacheEntry *> *this, unsigned int _Count)
{
  CacheEntry **result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x3FFFFFFF || (result = (CacheEntry **)operator new(nSize: 4 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D140
// Name: public: class Vector4D __near * std::allocator<class Vector4D>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall std::allocator<Vector4D>::allocate(std::allocator<Vector4D> *this, unsigned int _Count)
{
  Vector4D *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0xFFFFFFF || (result = (Vector4D *)operator new(nSize: 16 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D1A0
// Name: public: class Vector __near * std::allocator<class Vector>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall std::allocator<Vector>::allocate(std::allocator<Vector> *this, unsigned int _Count)
{
  Vector *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x15555555 || (result = (Vector *)operator new(nSize: 12 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D200
// Name: public: class Vector2D __near * std::allocator<class Vector2D>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
Vector2D *__thiscall std::allocator<Vector2D>::allocate(std::allocator<Vector2D> *this, unsigned int _Count)
{
  Vector2D *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x1FFFFFFF || (result = (Vector2D *)operator new(nSize: 8 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E480
// Name: public: void std::vector<unsigned int,class std::allocator<unsigned int>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<unsigned int>::reserve(std::vector<CacheEntry *> *this, unsigned int _Count)
{
  unsigned __int8 *v3; // ebx
  int v4; // edi

  if ( _Count > 0x3FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = (unsigned __int8 *)std::allocator<CacheEntry *>::allocate(this: &this->_Alval, _Count);
    memmove(dst: v3, src: (unsigned __int8 *)this->_Myfirst, count: 4 * (this->_Mylast - this->_Myfirst));
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myfirst = (CacheEntry **)v3;
    this->_Myend = (CacheEntry **)&v3[4 * _Count];
    this->_Mylast = (CacheEntry **)&v3[4 * v4];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ED80
// Name: protected: void std::vector<struct CacheEntry __near *,class std::allocator<struct CacheEntry __near *>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<CacheEntry *>::_Reserve(std::vector<CacheEntry *> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x3FFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x3FFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<unsigned int>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FCB0
// Name: public: void std::vector<struct CacheEntry __near *,class std::allocator<struct CacheEntry __near *>>::push_back(struct CacheEntry __near * __near &&)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<CacheEntry *>::push_back(std::vector<CacheEntry *> *this, CacheEntry **_Val)
{
  CacheEntry **Mylast; // eax
  int v4; // edi
  CacheEntry **v5; // eax
  CacheEntry **v6; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<CacheEntry *>::_Reserve(this, _Count: 1u);
    v6 = this->_Mylast;
    if ( v6 != nullptr )
      *v6 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<CacheEntry *>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      *v5 = this->_Myfirst[v4];
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x004122A0
// Name: public: void std::vector<struct OBJ_VERTEX,class std::allocator<struct OBJ_VERTEX>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<OBJ_VERTEX>::reserve(std::vector<OBJ_VERTEX> *this, unsigned int _Count)
{
  OBJ_VERTEX *v3; // eax
  int v4; // edi
  OBJ_VERTEX *v5; // ecx
  OBJ_VERTEX *v6; // edi
  OBJ_VERTEX *Myfirst; // [esp-18h] [ebp-38h]
  OBJ_VERTEX *Mylast; // [esp-14h] [ebp-34h]
  int v9; // [esp+0h] [ebp-20h] BYREF
  OBJ_VERTEX *_Ptr; // [esp+Ch] [ebp-14h]
  int *v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-4h]

  v11 = &v9;
  if ( _Count > 0x4EC4EC4 )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<OBJ_VERTEX>::allocate(this: &this->_Alval, _Count);
    Mylast = this->_Mylast;
    Myfirst = this->_Myfirst;
    _Ptr = v3;
    v12 = 0;
    std::_Uninit_move<OBJ_VERTEX *,OBJ_VERTEX *,std::allocator<OBJ_VERTEX>,OBJ_VERTEX>(
      _First: Myfirst,
      _Last: Mylast,
      _Dest: v3,
      _Al: &this->_Alval,
      __formal: nullptr,
      __formal: (std::_Nonscalar_ptr_iterator_tag)_Count);
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    v5 = _Ptr;
    v6 = &_Ptr[v4];
    this->_Myend = &_Ptr[_Count];
    this->_Mylast = v6;
    this->_Myfirst = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412390
// Name: public: void std::vector<class Vector4D,class std::allocator<class Vector4D>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector4D>::reserve(std::vector<Vector4D> *this, unsigned int _Count)
{
  Vector4D *v3; // ebx
  int v4; // edi
  Vector4D *Myfirst; // [esp-18h] [ebp-38h]
  Vector4D *Mylast; // [esp-14h] [ebp-34h]
  int v7; // [esp+0h] [ebp-20h] BYREF
  Vector4D *_Ptr; // [esp+Ch] [ebp-14h]
  int *v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-4h]

  v9 = &v7;
  if ( _Count > 0xFFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<Vector4D>::allocate(this: &this->_Alval, _Count);
    Mylast = this->_Mylast;
    Myfirst = this->_Myfirst;
    _Ptr = v3;
    v10 = 0;
    std::_Uninit_move<Vector4D *,Vector4D *,std::allocator<Vector4D>,Vector4D>(
      _First: Myfirst,
      _Last: Mylast,
      _Dest: v3,
      _Al: &this->_Alval,
      __formal: nullptr,
      __formal: (std::_Nonscalar_ptr_iterator_tag)_Count);
    v4 = (char *)this->_Mylast - (char *)this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = (Vector4D *)((char *)v3 + (v4 & 0xFFFFFFF0));
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412460
// Name: public: void std::vector<class Vector,class std::allocator<class Vector>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector>::reserve(std::vector<Vector> *this, unsigned int _Count)
{
  Vector *v3; // eax
  int v4; // edi
  Vector *v5; // eax
  Vector *Myfirst; // [esp-18h] [ebp-38h]
  Vector *Mylast; // [esp-14h] [ebp-34h]
  int v8; // [esp+0h] [ebp-20h] BYREF
  Vector *_Ptr; // [esp+Ch] [ebp-14h]
  int *v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-4h]

  v10 = &v8;
  if ( _Count > 0x15555555 )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<Vector>::allocate(this: &this->_Alval, _Count);
    Mylast = this->_Mylast;
    Myfirst = this->_Myfirst;
    _Ptr = v3;
    v11 = 0;
    std::_Uninit_move<Vector *,Vector *,std::allocator<Vector>,Vector>(
      _First: Myfirst,
      _Last: Mylast,
      _Dest: v3,
      _Al: &this->_Alval,
      __formal: nullptr,
      __formal: (std::_Nonscalar_ptr_iterator_tag)_Count);
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    v5 = _Ptr;
    this->_Myend = &_Ptr[_Count];
    this->_Mylast = &v5[v4];
    this->_Myfirst = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412550
// Name: public: void std::vector<class Vector2D,class std::allocator<class Vector2D>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector2D>::reserve(std::vector<Vector2D> *this, unsigned int _Count)
{
  Vector2D *v3; // ebx
  int v4; // edi
  Vector2D *Myfirst; // [esp-18h] [ebp-38h]
  Vector2D *Mylast; // [esp-14h] [ebp-34h]
  int v7; // [esp+0h] [ebp-20h] BYREF
  Vector2D *_Ptr; // [esp+Ch] [ebp-14h]
  int *v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-4h]

  v9 = &v7;
  if ( _Count > 0x1FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<Vector2D>::allocate(this: &this->_Alval, _Count);
    Mylast = this->_Mylast;
    Myfirst = this->_Myfirst;
    _Ptr = v3;
    v10 = 0;
    std::_Uninit_move<Vector2D *,Vector2D *,std::allocator<Vector2D>,Vector2D>(
      _First: Myfirst,
      _Last: Mylast,
      _Dest: v3,
      _Al: &this->_Alval,
      __formal: nullptr,
      __formal: (std::_Nonscalar_ptr_iterator_tag)_Count);
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413300
// Name: public: std::vector<class IScheduleObject __near *,class std::allocator<class IScheduleObject __near *>>::~vector<class IScheduleObject __near *,class std::allocator<class IScheduleObject __near *>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<IScheduleObject *>::~vector<IScheduleObject *>(std::vector<Vector2D> *this)
{
  if ( this->_Myfirst != nullptr )
    free(pMem: this->_Myfirst);
  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004133C0
// Name: protected: void std::vector<struct OBJ_VERTEX,class std::allocator<struct OBJ_VERTEX>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<OBJ_VERTEX>::_Reserve(std::vector<OBJ_VERTEX> *this, unsigned int _Count)
{
  unsigned int v2; // esi
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax

  v2 = this->_Mylast - this->_Myfirst;
  if ( 82595524 - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 82595524 - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<OBJ_VERTEX>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413450
// Name: protected: void std::vector<class Vector4D,class std::allocator<class Vector4D>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector4D>::_Reserve(std::vector<Vector4D> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0xFFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0xFFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<Vector4D>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004134C0
// Name: protected: void std::vector<class Vector,class std::allocator<class Vector>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector>::_Reserve(std::vector<Vector> *this, unsigned int _Count)
{
  unsigned int v2; // esi
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax

  v2 = this->_Mylast - this->_Myfirst;
  if ( 357913941 - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 357913941 - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<Vector>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413550
// Name: protected: void std::vector<class Vector2D,class std::allocator<class Vector2D>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector2D>::_Reserve(std::vector<Vector2D> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x1FFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x1FFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<Vector2D>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414170
// Name: public: void std::vector<struct OBJ_VERTEX,class std::allocator<struct OBJ_VERTEX>>::push_back(struct OBJ_VERTEX const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<OBJ_VERTEX>::push_back(std::vector<OBJ_VERTEX> *this, const OBJ_VERTEX *_Val)
{
  OBJ_VERTEX *Mylast; // ecx
  int v4; // edi

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<OBJ_VERTEX>::_Reserve(this, _Count: 1u);
    std::_Cons_val<std::allocator<OBJ_VERTEX>,OBJ_VERTEX,OBJ_VERTEX const &>(
      _Alval: &this->_Alval,
      _Pdest: this->_Mylast,
      _Src: _Val);
    ++this->_Mylast;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<OBJ_VERTEX>::_Reserve(this, _Count: 1u);
    std::_Cons_val<std::allocator<OBJ_VERTEX>,OBJ_VERTEX,OBJ_VERTEX const &>(
      _Alval: &this->_Alval,
      _Pdest: this->_Mylast,
      _Src: &this->_Myfirst[v4]);
    ++this->_Mylast;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414400
// Name: public: void std::vector<class Vector4D,class std::allocator<class Vector4D>>::push_back(class Vector4D __near &&)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector4D>::push_back(std::vector<Vector4D> *this, Vector4D *_Val)
{
  Vector4D *v2; // esi
  Vector4D *Mylast; // eax
  int v5; // esi
  Vector4D *v6; // eax

  v2 = _Val;
  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<Vector4D>::_Reserve(this, _Count: 1u);
  }
  else
  {
    v5 = (char *)_Val - (char *)this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<Vector4D>::_Reserve(this, _Count: 1u);
    v2 = (Vector4D *)((char *)this->_Myfirst + (v5 & 0xFFFFFFF0));
  }
  v6 = this->_Mylast;
  if ( v6 != nullptr )
  {
    v6->x = v2->x;
    v6->y = v2->y;
    v6->z = v2->z;
    v6->w = v2->w;
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x00414470
// Name: public: void std::vector<class Vector,class std::allocator<class Vector>>::push_back(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector>::push_back(std::vector<Vector> *this, const Vector *_Val)
{
  Vector *Mylast; // ecx
  int v4; // esi
  Vector *v5; // ecx
  Vector *v6; // eax
  Vector *v7; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<Vector>::_Reserve(this, _Count: 1u);
    v7 = this->_Mylast;
    if ( v7 != nullptr )
      *v7 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<Vector>::_Reserve(this, _Count: 1u);
    v5 = &this->_Myfirst[v4];
    v6 = this->_Mylast;
    if ( v6 != nullptr )
    {
      *(_QWORD *)&v6->x = *(_QWORD *)&v5->x;
      v6->z = v5->z;
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x00414500
// Name: public: void std::vector<class Vector2D,class std::allocator<class Vector2D>>::push_back(class Vector2D __near &&)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Vector2D>::push_back(std::vector<Vector2D> *this, Vector2D *_Val)
{
  Vector2D *Mylast; // eax
  int v4; // edi
  Vector2D *v5; // ecx
  Vector2D *v6; // eax
  Vector2D *v7; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<Vector2D>::_Reserve(this, _Count: 1u);
    v7 = this->_Mylast;
    if ( v7 != nullptr )
      *v7 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<Vector2D>::_Reserve(this, _Count: 1u);
    v5 = &this->_Myfirst[v4];
    v6 = this->_Mylast;
    if ( v6 != nullptr )
    {
      v6->x = v5->x;
      v6->y = v5->y;
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x00414F80
// Name: public: bool CUniformSampler::InitSamples(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUniformSampler::InitSamples(CUniformSampler *this, int SqrtNumSamples, int NumVariations)
{
  int v3; // esi
  int v4; // edi
  Vector *v5; // eax
  CUniformSampler *v6; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // edi
  double v13; // xmm0_8
  Vector *m_pvDirections; // eax
  long double v15; // [esp+0h] [ebp-40h]
  long double v16; // [esp+0h] [ebp-40h]
  long double v17; // [esp+0h] [ebp-40h]
  long double v18; // [esp+0h] [ebp-40h]
  long double v19; // [esp+0h] [ebp-40h]
  int i; // [esp+14h] [ebp-2Ch]
  int v21; // [esp+20h] [ebp-20h]
  int v22; // [esp+24h] [ebp-1Ch]
  int n; // [esp+28h] [ebp-18h]
  float theta; // [esp+2Ch] [ebp-14h]
  float oneoverN; // [esp+38h] [ebp-8h]
  int a; // [esp+4Ch] [ebp+Ch]

  v3 = SqrtNumSamples;
  v4 = SqrtNumSamples * SqrtNumSamples;
  this->m_NumVariations = NumVariations;
  this->m_NumSamples = SqrtNumSamples * SqrtNumSamples;
  v5 = (Vector *)operator new(nSize: 12 * NumVariations * SqrtNumSamples * SqrtNumSamples);
  v6 = this;
  this->m_pvDirections = v5;
  if ( v5 == nullptr )
    return 0;
  v8 = 0;
  oneoverN = 1.0 / (float)SqrtNumSamples;
  n = 0;
  if ( this->m_NumVariations > 0 )
  {
    do
    {
      a = 0;
      if ( v3 > 0 )
      {
        v9 = 12 * v3;
        v10 = 12 * v8;
        v22 = 12 * v3;
        i = v4 + v8;
        while ( 1 )
        {
          v11 = 0;
          v12 = v10;
          v21 = v9 + v10;
          do
          {
            v13 = fsqrt(
                    1.0
                  - (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882) & _mask__AbsFloat_)
                                  + (float)a)
                          * oneoverN));
            __libm_sse2_acos(x: v15);
            *(float *)&v13 = v13;
            theta = *(float *)&v13 * 2.0;
            *(float *)&v13 = (float)((float)(COERCE_FLOAT(
                                               COERCE_UNSIGNED_INT((float)(rand() - 0x3FFF) * 0.000061038882)
                                             & _mask__AbsFloat_)
                                           + (float)v11)
                                   * oneoverN)
                           * 6.283185307179586;
            __libm_sse2_sin(x: v16);
            __libm_sse2_cos(x: v17);
            __libm_sse2_sin(x: v18);
            __libm_sse2_cos(x: v19);
            m_pvDirections = this->m_pvDirections;
            *(float *)((char *)&m_pvDirections->x + v12) = *(float *)&v13 * theta;
            *(float *)((char *)&m_pvDirections->y + v12) = *(float *)&v13 * theta;
            *(float *)((char *)&m_pvDirections->z + v12) = theta;
            ++v11;
            v12 += 12;
          }
          while ( v11 < SqrtNumSamples );
          if ( ++a >= SqrtNumSamples )
            break;
          v9 = v22;
          v10 = v21;
        }
        v4 = SqrtNumSamples * SqrtNumSamples;
        v8 = i;
        v3 = SqrtNumSamples;
        v6 = this;
      }
      ++n;
    }
    while ( n < v6->m_NumVariations );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004151B0
// Name: class Vector CalculateSmoothNormal(struct OBJ_VERTEX,struct OBJ_VERTEX,struct OBJ_VERTEX,class Vector)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl CalculateSmoothNormal(Vector *result, OBJ_VERTEX v0, OBJ_VERTEX v1, OBJ_VERTEX v2, Vector vHit)
{
  Vector *v5; // esi
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v20; // [esp-20h] [ebp-4Ch]
  __int64 v21; // [esp-Ch] [ebp-38h]
  __int64 v22; // [esp-Ch] [ebp-38h]

  if ( v0.nor.x == 0.0 && v0.nor.y == 0.0 && v0.nor.z == 0.0 )
  {
    v5 = result;
    *(float *)&v21 = (float)((float)(v2.pos.y - v0.pos.y) * (float)(v1.pos.z - v0.pos.z))
                   - (float)((float)(v2.pos.z - v0.pos.z) * (float)(v1.pos.y - v0.pos.y));
    *((float *)&v21 + 1) = (float)((float)(v2.pos.z - v0.pos.z) * (float)(v1.pos.x - v0.pos.x))
                         - (float)((float)(v1.pos.z - v0.pos.z) * (float)(v2.pos.x - v0.pos.x));
    *(_QWORD *)&result->x = v21;
    result->z = (float)((float)(v1.pos.y - v0.pos.y) * (float)(v2.pos.x - v0.pos.x))
              - (float)((float)(v2.pos.y - v0.pos.y) * (float)(v1.pos.x - v0.pos.x));
  }
  else
  {
    v6 = (float)((float)(v2.pos.z - v0.pos.z) * (float)(v1.pos.x - v0.pos.x))
       - (float)((float)(v1.pos.z - v0.pos.z) * (float)(v2.pos.x - v0.pos.x));
    v7 = (float)((float)(v1.pos.y - v0.pos.y) * (float)(v2.pos.x - v0.pos.x))
       - (float)((float)(v2.pos.y - v0.pos.y) * (float)(v1.pos.x - v0.pos.x));
    v8 = (float)((float)(v2.pos.y - v0.pos.y) * (float)(v1.pos.z - v0.pos.z))
       - (float)((float)(v2.pos.z - v0.pos.z) * (float)(v1.pos.y - v0.pos.y));
    v20 = fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8));
    v9 = (float)((float)(v2.pos.z - vHit.z) * (float)(v1.pos.x - vHit.x))
       - (float)((float)(v1.pos.z - vHit.z) * (float)(v2.pos.x - vHit.x));
    v10 = (float)(1.0 / v20)
        * fsqrt(
            (float)((float)(v9 * v9)
                  + (float)((float)((float)((float)(v1.pos.y - vHit.y) * (float)(v2.pos.x - vHit.x))
                                  - (float)((float)(v2.pos.y - vHit.y) * (float)(v1.pos.x - vHit.x)))
                          * (float)((float)((float)(v1.pos.y - vHit.y) * (float)(v2.pos.x - vHit.x))
                                  - (float)((float)(v2.pos.y - vHit.y) * (float)(v1.pos.x - vHit.x)))))
          + (float)((float)((float)((float)(v2.pos.y - vHit.y) * (float)(v1.pos.z - vHit.z))
                          - (float)((float)(v2.pos.z - vHit.z) * (float)(v1.pos.y - vHit.y)))
                  * (float)((float)((float)(v2.pos.y - vHit.y) * (float)(v1.pos.z - vHit.z))
                          - (float)((float)(v2.pos.z - vHit.z) * (float)(v1.pos.y - vHit.y)))));
    v11 = (float)((float)(v0.pos.z - vHit.z) * (float)(v2.pos.x - vHit.x))
        - (float)((float)(v2.pos.z - vHit.z) * (float)(v0.pos.x - vHit.x));
    v12 = (float)((float)(v2.pos.y - vHit.y) * (float)(v0.pos.x - vHit.x))
        - (float)((float)(v0.pos.y - vHit.y) * (float)(v2.pos.x - vHit.x));
    v13 = (float)((float)(v11 * v11) + (float)(v12 * v12))
        + (float)((float)((float)((float)(v0.pos.y - vHit.y) * (float)(v2.pos.z - vHit.z))
                        - (float)((float)(v0.pos.z - vHit.z) * (float)(v2.pos.y - vHit.y)))
                * (float)((float)((float)(v0.pos.y - vHit.y) * (float)(v2.pos.z - vHit.z))
                        - (float)((float)(v0.pos.z - vHit.z) * (float)(v2.pos.y - vHit.y))));
    v14 = (float)((float)(v1.pos.z - vHit.z) * (float)(v0.pos.x - vHit.x))
        - (float)((float)(v0.pos.z - vHit.z) * (float)(v1.pos.x - vHit.x));
    v15 = (float)((float)(v0.pos.y - vHit.y) * (float)(v1.pos.x - vHit.x))
        - (float)((float)(v1.pos.y - vHit.y) * (float)(v0.pos.x - vHit.x));
    v16 = (float)((float)(v1.pos.y - vHit.y) * (float)(v0.pos.z - vHit.z))
        - (float)((float)(v1.pos.z - vHit.z) * (float)(v0.pos.y - vHit.y));
    v17 = (float)(1.0 / v20) * fsqrt(v13);
    v18 = (float)(1.0 / v20) * fsqrt((float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v16 * v16));
    v5 = result;
    *(float *)&v22 = (float)((float)(v1.nor.x * v17) + (float)(v0.nor.x * v10)) + (float)(v2.nor.x * v18);
    *((float *)&v22 + 1) = (float)((float)(v0.nor.y * v10) + (float)(v1.nor.y * v17)) + (float)(v2.nor.y * v18);
    *(_QWORD *)&result->x = v22;
    result->z = (float)((float)(v10 * v0.nor.z) + (float)(v1.nor.z * v17)) + (float)(v2.nor.z * v18);
  }
  VectorNormalize(vec: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004155C0
// Name: public: virtual void CToggleSwitchJob::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToggleSwitchJob::Execute(
        CToggleSwitchJob *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  this->m_bToggle = !this->m_bToggle;
}

//------------------------------------------------------------------------------
// Address: 0x00415640
// Name: public: virtual void COSNormalsToTSNormals::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COSNormalsToTSNormals::Execute(
        COSNormalsToTSNormals *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  unsigned int v2; // eax
  bool v4; // zf
  unsigned int v5; // edi
  int v6; // ebx
  unsigned int v7; // ecx
  Vector2D *v8; // eax
  float U; // xmm0_4
  float V; // xmm1_4
  Vector4D *m_pPatchTanStart; // eax
  float y; // xmm3_4
  float z; // xmm4_4
  CSubDMesh *m_pSubDMesh; // ecx
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  unsigned __int8 *m_pOSNormalStart; // eax
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  unsigned __int8 *v24; // eax
  int v25; // [esp-4h] [ebp-70h]
  float vPatchTanU_12; // [esp+28h] [ebp-44h]
  Vector vACCPos; // [esp+2Ch] [ebp-40h] BYREF
  Vector vNormal; // [esp+38h] [ebp-34h] BYREF
  Vector vTangent; // [esp+44h] [ebp-28h] BYREF
  Vector vBiTangent; // [esp+50h] [ebp-1Ch] BYREF
  unsigned int v; // [esp+5Ch] [ebp-10h]
  unsigned int iRowStart; // [esp+60h] [ebp-Ch]
  unsigned int u; // [esp+64h] [ebp-8h]
  unsigned int v34; // [esp+68h] [ebp-4h]

  v2 = 0;
  iRowStart = 0;
  for ( v = 0; v < this->m_RectSizeV; ++v )
  {
    v4 = this->m_RectSizeU == 0;
    u = 0;
    if ( !v4 )
    {
      v5 = 4 * v2;
      v6 = v2;
      v34 = 8 * v2;
      do
      {
        v7 = this->m_pPatchIDStart[v5 / 4];
        if ( v7 != 0 )
        {
          v8 = &this->m_pPatchUVStart[v34 / 8];
          U = v8->x;
          V = v8->y;
          m_pPatchTanStart = this->m_pPatchTanStart;
          y = m_pPatchTanStart[v6].y;
          z = m_pPatchTanStart[v6].z;
          v25 = v7 - 1;
          m_pSubDMesh = this->m_pSubDMesh;
          vPatchTanU_12 = m_pPatchTanStart[v6].w;
          vTangent.x = m_pPatchTanStart[v6].x;
          vTangent.y = y;
          vTangent.z = z;
          CSubDMesh::EvalulateACCPatchAtUV(
            this: m_pSubDMesh,
            iPatchID: v25,
            U,
            V,
            pOutPosition: &vACCPos,
            pOutNormal: &vNormal);
          vBiTangent.x = (float)((float)(vNormal.y * vTangent.z) - (float)(vTangent.y * vNormal.z)) * vPatchTanU_12;
          vBiTangent.y = (float)((float)(vNormal.z * vTangent.x) - (float)(vTangent.z * vNormal.x)) * vPatchTanU_12;
          vBiTangent.z = (float)((float)(vTangent.y * vNormal.x) - (float)(vNormal.y * vTangent.x)) * vPatchTanU_12;
          v15 = (float)((float)(vNormal.y * vTangent.y) + (float)(vNormal.x * vTangent.x))
              + (float)(vTangent.z * vNormal.z);
          vTangent.x = vTangent.x - (float)(vNormal.x * v15);
          vTangent.y = vTangent.y - (float)(vNormal.y * v15);
          vTangent.z = vTangent.z - (float)(vNormal.z * v15);
          VectorNormalize(vec: &vTangent);
          v16 = (float)((float)(vBiTangent.y * vNormal.y) + (float)(vBiTangent.x * vNormal.x))
              + (float)(vBiTangent.z * vNormal.z);
          vBiTangent.x = vBiTangent.x - (float)(v16 * vNormal.x);
          vBiTangent.y = vBiTangent.y - (float)(vNormal.y * v16);
          vBiTangent.z = vBiTangent.z - (float)(v16 * vNormal.z);
          VectorNormalize(vec: &vBiTangent);
          v17 = (float)((float)(vBiTangent.y * vTangent.y) + (float)(vBiTangent.x * vTangent.x))
              + (float)(vBiTangent.z * vTangent.z);
          vBiTangent.x = vBiTangent.x - (float)(v17 * vTangent.x);
          vBiTangent.y = vBiTangent.y - (float)(vTangent.y * v17);
          vBiTangent.z = vBiTangent.z - (float)(v17 * vTangent.z);
          VectorNormalize(vec: &vBiTangent);
          m_pOSNormalStart = this->m_pOSNormalStart;
          v19 = (float)((float)m_pOSNormalStart[v5 + 2] * 0.0078125) - 1.0;
          v20 = (float)((float)m_pOSNormalStart[v5 + 1] * 0.0078125) - 1.0;
          v21 = (float)((float)m_pOSNormalStart[v5] * 0.0078125) - 1.0;
          v22 = (float)((float)(vBiTangent.y * v20) + (float)(vBiTangent.x * v19)) + (float)(vBiTangent.z * v21);
          v23 = (float)((float)(vNormal.y * v20) + (float)(vNormal.x * v19)) + (float)(vNormal.z * v21);
          v24 = &this->m_pTSNormalStart[v5];
          v24[2] = (int)(float)((float)((float)((float)((float)(vTangent.y * v20) + (float)(vTangent.x * v19))
                                              + (float)(vTangent.z * v21))
                                      * 127.0)
                              + 128.0);
          v24[1] = (int)(float)((float)(COERCE_FLOAT(LODWORD(v22) ^ _mask__NegFloat_) * 127.0) + 128.0);
          *v24 = (int)(float)((float)(v23 * 127.0) + 128.0);
          v24[3] = 0;
          v2 = iRowStart;
        }
        v34 += 8;
        ++v6;
        v5 += 4;
        ++u;
      }
      while ( u < this->m_RectSizeU );
    }
    v2 += this->m_PatchPitch;
    iRowStart = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004159E0
// Name: public: CTileBuffers::CTileBuffers(void)
// Source: json
//------------------------------------------------------------------------------
CTileBuffers *__thiscall CTileBuffers::CTileBuffers(CTileBuffers *this)
{
  this->m_pNearCageDistanceBuffers = nullptr;
  this->m_pDisplacementOutputBuffer = nullptr;
  this->m_pAmbientOcclusionBuffer = nullptr;
  this->m_pDirectionAmbientOcclusionBuffer = nullptr;
  this->m_pTSNormalMapBuffer = nullptr;
  this->m_pOSNormalMapBuffer = nullptr;
  this->m_pCavityMapBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415A00
// Name: public: CTileBuffers::~CTileBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileBuffers::~CTileBuffers(CTileBuffers *this)
{
  if ( this->m_pNearCageDistanceBuffers != nullptr )
  {
    free(pMem: this->m_pNearCageDistanceBuffers);
    this->m_pNearCageDistanceBuffers = nullptr;
  }
  if ( this->m_pDisplacementOutputBuffer != nullptr )
  {
    free(pMem: this->m_pDisplacementOutputBuffer);
    this->m_pDisplacementOutputBuffer = nullptr;
  }
  if ( this->m_pAmbientOcclusionBuffer != nullptr )
  {
    free(pMem: this->m_pAmbientOcclusionBuffer);
    this->m_pAmbientOcclusionBuffer = nullptr;
  }
  if ( this->m_pDirectionAmbientOcclusionBuffer != nullptr )
  {
    free(pMem: this->m_pDirectionAmbientOcclusionBuffer);
    this->m_pDirectionAmbientOcclusionBuffer = nullptr;
  }
  if ( this->m_pTSNormalMapBuffer != nullptr )
  {
    free(pMem: this->m_pTSNormalMapBuffer);
    this->m_pTSNormalMapBuffer = nullptr;
  }
  if ( this->m_pOSNormalMapBuffer != nullptr )
  {
    free(pMem: this->m_pOSNormalMapBuffer);
    this->m_pOSNormalMapBuffer = nullptr;
  }
  if ( this->m_pCavityMapBuffer != nullptr )
  {
    free(pMem: this->m_pCavityMapBuffer);
    this->m_pCavityMapBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415A90
// Name: public: CFloatTextureOutput::CFloatTextureOutput(struct IDirect3DDevice9 __near *,float __near *,int,int,enum _D3DXIMAGE_FILEFORMAT,char __near *)
// Source: json
//------------------------------------------------------------------------------
CFloatTextureOutput *__thiscall CFloatTextureOutput::CFloatTextureOutput(
        CFloatTextureOutput *this,
        IDirect3DDevice9 *pDevice,
        float *pBits,
        int Width,
        int Height,
        _D3DXIMAGE_FILEFORMAT fileFormat,
        char *pszFileName)
{
  this->m_pDevice = pDevice;
  this->m_Width = Width;
  this->m_Height = Height;
  this->m_pBits = pBits;
  this->m_iRef = 0;
  this->__vftable = (CFloatTextureOutput_vtbl *)&CFloatTextureOutput::`vftable';
  this->m_FileFormat = fileFormat;
  strcpy_s(_Dst: this->m_szFileName, _SizeInBytes: 0x104u, _Src: pszFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415AE0
// Name: public: CUByte4TextureOutput::CUByte4TextureOutput(struct IDirect3DDevice9 __near *,unsigned char __near *,int,int,enum _D3DXIMAGE_FILEFORMAT,char __near *)
// Source: json
//------------------------------------------------------------------------------
CUByte4TextureOutput *__thiscall CUByte4TextureOutput::CUByte4TextureOutput(
        CUByte4TextureOutput *this,
        IDirect3DDevice9 *pDevice,
        unsigned __int8 *pBits,
        int Width,
        int Height,
        _D3DXIMAGE_FILEFORMAT fileFormat,
        char *pszFileName)
{
  this->m_pDevice = pDevice;
  this->m_Width = Width;
  this->m_Height = Height;
  this->m_pBits = pBits;
  this->m_iRef = 0;
  this->__vftable = (CUByte4TextureOutput_vtbl *)&CUByte4TextureOutput::`vftable';
  this->m_FileFormat = fileFormat;
  strcpy_s(_Dst: this->m_szFileName, _SizeInBytes: 0x104u, _Src: pszFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415B30
// Name: public: CUByteFromFloatTextureOutput::CUByteFromFloatTextureOutput(struct IDirect3DDevice9 __near *,float __near *,int,int,enum _D3DXIMAGE_FILEFORMAT,char __near *)
// Source: json
//------------------------------------------------------------------------------
CUByteFromFloatTextureOutput *__thiscall CUByteFromFloatTextureOutput::CUByteFromFloatTextureOutput(
        CUByteFromFloatTextureOutput *this,
        IDirect3DDevice9 *pDevice,
        float *pBits,
        int Width,
        int Height,
        _D3DXIMAGE_FILEFORMAT fileFormat,
        char *pszFileName)
{
  this->m_pDevice = pDevice;
  this->m_Width = Width;
  this->m_Height = Height;
  this->m_pBits = pBits;
  this->m_iRef = 0;
  this->__vftable = (CUByteFromFloatTextureOutput_vtbl *)&CUByteFromFloatTextureOutput::`vftable';
  this->m_FileFormat = fileFormat;
  strcpy_s(_Dst: this->m_szFileName, _SizeInBytes: 0x104u, _Src: pszFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415B80
// Name: public: COutputDetailOBJJob::COutputDetailOBJJob(class CSubDMesh __near *,class CTileBuffers __near *,int,int,int,char __near *,class RayTracingEnvironment __near *,bool)
// Source: json
//------------------------------------------------------------------------------
COutputDetailOBJJob *__thiscall COutputDetailOBJJob::COutputDetailOBJJob(
        COutputDetailOBJJob *this,
        CSubDMesh *pSubDMesh,
        CTileBuffers *pTileBuffers,
        int Width,
        int Height,
        int NumTilesU,
        char *pszFileName,
        RayTracingEnvironment *prteDetail,
        bool bRemoveRedundancies)
{
  this->m_iRef = 0;
  this->m_pSubDMesh = pSubDMesh;
  this->m_NumTilesU = NumTilesU;
  this->m_pTileBuffers = pTileBuffers;
  this->m_fWidth = (float)Width;
  this->m_prteDetail = prteDetail;
  this->__vftable = (COutputDetailOBJJob_vtbl *)&COutputDetailOBJJob::`vftable';
  this->m_Width = Width;
  this->m_Height = Height;
  this->m_bRemoveRedundancies = bRemoveRedundancies;
  this->m_fHeight = (float)Height;
  _V_memset(dest: this->m_szFileName, fill: 0, count: 260);
  if ( pszFileName != nullptr )
    strcpy_s(_Dst: this->m_szFileName, _SizeInBytes: 0x104u, _Src: pszFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415C40
// Name: public: virtual CJob::~CJob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJob::~CJob(COutputDetailOBJJob *this)
{
  this->__vftable = (COutputDetailOBJJob_vtbl *)&CJob::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00415C50
// Name: public: CCavityMap::CCavityMap(float __near *,float __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
CCavityMap *__thiscall CCavityMap::CCavityMap(
        CCavityMap *this,
        float *pInputHeightBits,
        float *pOutputBits,
        int Width,
        int Height,
        float fRadius)
{
  int v7; // eax
  int v8; // eax
  int m_KernelWidth; // kr00_4
  int v10; // eax
  int v11; // edi
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  long double v17; // [esp+8h] [ebp-24h]
  float i; // [esp+1Ch] [ebp-10h]
  int index; // [esp+34h] [ebp+8h]
  int kv; // [esp+3Ch] [ebp+10h]

  this->m_iRef = 0;
  this->m_pInputHeightBits = pInputHeightBits;
  this->__vftable = (CCavityMap_vtbl *)&CCavityMap::`vftable';
  this->m_pOutputBits = pOutputBits;
  this->m_Width = Width;
  this->m_Height = Height;
  v7 = (int)ceil(X: (float)(fRadius * 6.0));
  v8 = v7 - v7 % 2 + 1;
  this->m_KernelWidth = v8;
  this->m_pWeights = (float *)operator new(nSize: 4 * v8 * v8);
  m_KernelWidth = this->m_KernelWidth;
  v10 = m_KernelWidth / 2;
  index = 0;
  v11 = m_KernelWidth / -2;
  v12 = m_KernelWidth / -2;
  for ( kv = m_KernelWidth / -2; v12 <= v10; kv = v12 )
  {
    if ( v11 <= v10 )
    {
      v13 = (float)(fRadius * 2.0) * fRadius;
      v14 = (float)v12 * (float)v12;
      for ( i = v14; ; v14 = i )
      {
        __libm_sse2_exp(x: v17);
        v15 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)((float)v11 * (float)v11) + v14) / v13) ^ _mask__NegFloat_)
            / (fRadius
             * 6.283185307179586
             * fRadius);
        this->m_pWeights[index] = v15;
        ++v11;
        ++index;
        if ( v11 > m_KernelWidth / 2 )
          break;
        v13 = (float)(fRadius * 2.0) * fRadius;
      }
      v11 = m_KernelWidth / -2;
      v12 = kv;
      v10 = m_KernelWidth / 2;
    }
    ++v12;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415DE0
// Name: public: virtual void CCavityMap::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCavityMap::Execute(
        CCavityMap *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  int v2; // edx
  int m_Width; // esi
  float v4; // xmm1_4
  int v5; // edx
  int v6; // ebx
  int v7; // edi
  float v8; // xmm0_4
  int v9; // eax
  int v10; // edx
  int v11; // ebx
  float v12; // xmm3_4
  float v13; // xmm3_4
  int v14; // ebx
  float v15; // xmm3_4
  int v16; // ebx
  float v17; // xmm3_4
  bool v18; // zf
  int v19; // edx
  int v20; // ebx
  float v21; // xmm3_4
  float v22; // xmm3_4
  float *dstPixel; // [esp+0h] [ebp-30h]
  CCavityMap *v24; // [esp+4h] [ebp-2Ch]
  int v25; // [esp+8h] [ebp-28h]
  unsigned int v26; // [esp+Ch] [ebp-24h]
  int v27; // [esp+Ch] [ebp-24h]
  int v28; // [esp+10h] [ebp-20h]
  int v; // [esp+14h] [ebp-1Ch]
  int v30; // [esp+18h] [ebp-18h]
  int u; // [esp+1Ch] [ebp-14h]
  float *m_pInputHeightBits; // [esp+20h] [ebp-10h]
  int v33; // [esp+24h] [ebp-Ch]
  int v34; // [esp+28h] [ebp-8h]
  int v35; // [esp+2Ch] [ebp-4h]

  v2 = 0;
  v24 = this;
  v = 0;
  if ( this->m_Height > 0 )
  {
    m_Width = this->m_Width;
    do
    {
      dstPixel = &this->m_pOutputBits[v2 * m_Width];
      for ( u = 0; u < m_Width; ++u )
      {
        m_pInputHeightBits = this->m_pInputHeightBits;
        v4 = m_pInputHeightBits[u + v2 * m_Width];
        v5 = this->m_KernelWidth / 2;
        v6 = this->m_KernelWidth / -2;
        v7 = 0;
        v8 = 0.0;
        v30 = v5;
        v28 = v6;
        if ( v6 <= v5 )
        {
          v9 = v6 + v;
          v35 = v6 + v;
          v25 = v5 - v6 + 1;
          do
          {
            if ( v9 > 0 && v9 < this->m_Height )
            {
              v33 = v6;
              if ( v6 <= v30 )
              {
                if ( v30 - v28 + 1 >= 4 )
                {
                  v10 = v6 + u + 1;
                  v34 = v10;
                  v26 = ((unsigned int)(v30 - v6 - 3) >> 2) + 1;
                  v33 = v6 + 4 * v26;
                  do
                  {
                    v11 = v10 - 1;
                    if ( v10 - 1 > 0 && v11 < m_Width )
                    {
                      v12 = m_pInputHeightBits[v11 + m_Width * v9];
                      v9 = v35;
                      v10 = v34;
                      v8 = v8 - (float)((float)(v12 - v4) * this->m_pWeights[v7]);
                    }
                    if ( v10 > 0 && v10 < m_Width )
                    {
                      v13 = m_pInputHeightBits[v10 + m_Width * v9];
                      v9 = v35;
                      v10 = v34;
                      v8 = v8 - (float)((float)(v13 - v4) * this->m_pWeights[v7 + 1]);
                    }
                    v14 = v10 + 1;
                    if ( v10 + 1 > 0 && v14 < m_Width )
                    {
                      v15 = m_pInputHeightBits[v14 + m_Width * v9];
                      v9 = v35;
                      v10 = v34;
                      v8 = v8 - (float)((float)(v15 - v4) * this->m_pWeights[v7 + 2]);
                    }
                    v16 = v10 + 2;
                    if ( v10 + 2 > 0 && v16 < m_Width )
                    {
                      v17 = m_pInputHeightBits[v16 + m_Width * v9];
                      v9 = v35;
                      v10 = v34;
                      v8 = v8 - (float)((float)(v17 - v4) * this->m_pWeights[v7 + 3]);
                    }
                    v10 += 4;
                    v7 += 4;
                    v18 = v26-- == 1;
                    v34 = v10;
                  }
                  while ( !v18 );
                }
                if ( v33 <= v30 )
                {
                  v19 = u + v33;
                  v9 = v35;
                  v20 = v30 - v33 + 1;
                  v27 = v20;
                  do
                  {
                    if ( v19 > 0 && v19 < m_Width )
                    {
                      v21 = m_pInputHeightBits[v19 + m_Width * v9];
                      v20 = v27;
                      v9 = v35;
                      v22 = (float)(v21 - v4) * this->m_pWeights[v7];
                      this = v24;
                      v8 = v8 - v22;
                    }
                    ++v7;
                    ++v19;
                    v27 = --v20;
                  }
                  while ( v20 != 0 );
                }
              }
              v6 = v28;
            }
            ++v9;
            v18 = v25-- == 1;
            v35 = v9;
          }
          while ( !v18 );
        }
        dstPixel[u] = v8;
        m_Width = this->m_Width;
        v2 = v;
      }
      v = ++v2;
    }
    while ( v2 < this->m_Height );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416060
// Name: public: virtual void CNormalize::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNormalize::Execute(
        CNormalize *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  int m_Width; // edi
  float *m_pInputHeightBits; // edx
  float *v6; // ebx
  int v7; // esi
  unsigned int v8; // eax
  float *v9; // edx
  float v10; // xmm2_4
  float v11; // xmm2_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  bool v14; // zf
  int v15; // edi
  float v16; // xmm0_4
  int v17; // edx
  float *v18; // esi
  int i; // eax
  int m_Height; // [esp+0h] [ebp-8h]
  float *v21; // [esp+4h] [ebp-4h]

  v2 = 3.4028235e38;
  v3 = -3.4028235e38;
  if ( this->m_Height > 0 )
  {
    m_Width = this->m_Width;
    m_pInputHeightBits = this->m_pInputHeightBits;
    v21 = m_pInputHeightBits;
    v6 = m_pInputHeightBits + 2;
    m_Height = this->m_Height;
    do
    {
      v7 = 0;
      if ( m_Width >= 4 )
      {
        v8 = ((unsigned int)(m_Width - 4) >> 2) + 1;
        v9 = v6;
        v7 = 4 * v8;
        do
        {
          v10 = *(v9 - 2);
          if ( v2 > v10 )
            v2 = *(v9 - 2);
          if ( v10 > v3 )
            v3 = *(v9 - 2);
          v11 = *(v9 - 1);
          if ( v2 > v11 )
            v2 = *(v9 - 1);
          if ( v11 > v3 )
            v3 = *(v9 - 1);
          if ( v2 > *v9 )
            v2 = *v9;
          if ( *v9 > v3 )
            v3 = *v9;
          v12 = v9[1];
          if ( v2 > v12 )
            v2 = v9[1];
          if ( v12 > v3 )
            v3 = v9[1];
          v9 += 4;
          --v8;
        }
        while ( v8 != 0 );
        m_pInputHeightBits = v21;
      }
      for ( ; v7 < m_Width; ++v7 )
      {
        v13 = m_pInputHeightBits[v7];
        if ( v2 > v13 )
          v2 = m_pInputHeightBits[v7];
        if ( v13 > v3 )
          v3 = m_pInputHeightBits[v7];
      }
      m_pInputHeightBits += m_Width;
      v6 += m_Width;
      v14 = m_Height-- == 1;
      v21 = m_pInputHeightBits;
    }
    while ( !v14 );
  }
  v15 = 0;
  v16 = v3 - v2;
  if ( this->m_Height > 0 )
  {
    v17 = this->m_Width;
    do
    {
      v18 = &this->m_pInputHeightBits[v15 * v17];
      for ( i = 0; i < v17; ++i )
      {
        v18[i] = (float)(v18[i] - v2) * (float)(1.0 / v16);
        v17 = this->m_Width;
      }
      ++v15;
    }
    while ( v15 < this->m_Height );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004161A0
// Name: public: CGutterFloatMap::CGutterFloatMap(float __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
CGutterFloatMap *__thiscall CGutterFloatMap::CGutterFloatMap(
        CGutterFloatMap *this,
        float *pInputHeightBits,
        int Width,
        int Height,
        int GutterSize,
        float fThreshold)
{
  this->m_iRef = 0;
  this->m_pInputHeightBits = pInputHeightBits;
  this->m_Width = Width;
  this->m_Height = Height;
  this->m_GutterSize = GutterSize;
  this->__vftable = (CGutterFloatMap_vtbl *)&CGutterFloatMap::`vftable';
  this->m_fThreshold = fThreshold;
  this->m_pOutputHeightBits = (float *)operator new(nSize: 4 * Height * Width);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416230
// Name: public: bool CGutterFloatMap::IsValidPixel(int,int,float __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGutterFloatMap::IsValidPixel(
        CGutterFloatMap *this,
        int X,
        int Y,
        float *pSrcHeight,
        int SrcPitch,
        int FullWidth,
        int FullHeight,
        float fThreshold)
{
  float v8; // xmm0_4
  int v9; // ebx
  int v10; // ecx
  float v11; // xmm2_4
  float v12; // xmm1_4
  int v13; // edx
  int v14; // eax
  int v15; // ebx
  int v16; // eax

  v8 = 0.0;
  v9 = FullWidth;
  v10 = X - 1;
  v11 = pSrcHeight[X + SrcPitch * Y];
  v12 = 0.0;
  v13 = Y - 1;
  if ( X - 1 >= 0 && v13 >= 0 && v10 < FullWidth && v13 < FullHeight )
  {
    v8 = pSrcHeight[v10 + SrcPitch * v13] - v11;
    v12 = 1.0;
  }
  if ( X >= 0 && v13 >= 0 && X < FullWidth && v13 < FullHeight )
  {
    v9 = FullWidth;
    v8 = v8 + (float)(pSrcHeight[X + SrcPitch * v13] - v11);
    v12 = v12 + 1.0;
  }
  v14 = v10 + 2;
  if ( v10 + 2 >= 0 && v13 >= 0 && v14 < v9 && v13 < FullHeight )
  {
    v9 = FullWidth;
    v8 = v8 + (float)(pSrcHeight[v14 + SrcPitch * v13] - v11);
    v12 = v12 + 1.0;
  }
  if ( v10 >= 0 && Y >= 0 && v10 < v9 && Y < FullHeight )
  {
    v8 = v8 + (float)(pSrcHeight[v10 + SrcPitch * Y] - v11);
    v12 = v12 + 1.0;
  }
  v15 = v10 + 2;
  if ( v10 + 2 >= 0 && Y >= 0 && v15 < FullWidth && Y < FullHeight )
  {
    v8 = v8 + (float)(pSrcHeight[v15 + SrcPitch * Y] - v11);
    v12 = v12 + 1.0;
  }
  v16 = v13 + 2;
  if ( v10 >= 0 && v16 >= 0 && v10 < FullWidth && v16 < FullHeight )
  {
    v8 = v8 + (float)(pSrcHeight[v10 + SrcPitch * v16] - v11);
    v12 = v12 + 1.0;
  }
  if ( X >= 0 && v16 >= 0 && X < FullWidth && v16 < FullHeight )
  {
    v8 = v8 + (float)(pSrcHeight[X + SrcPitch * v16] - v11);
    v12 = v12 + 1.0;
  }
  if ( v15 >= 0 && v16 >= 0 && v15 < FullWidth && v16 < FullHeight )
  {
    v8 = v8 + (float)(pSrcHeight[v15 + SrcPitch * v16] - v11);
    v12 = v12 + 1.0;
  }
  return fThreshold > (float)(COERCE_FLOAT(LODWORD(v8) & _mask__AbsFloat_) / v12);
}

//------------------------------------------------------------------------------
// Address: 0x004163F0
// Name: public: float CGutterFloatMap::GutterPixel(int,int,float __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGutterFloatMap::GutterPixel(
        CGutterFloatMap *this,
        int X,
        int Y,
        float *pSrcHeight,
        int SrcPitch,
        int FullWidth,
        int FullHeight,
        float fThreshold)
{
  float *v8; // ebx
  int v9; // edx
  int v10; // ecx
  int v11; // edi
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // esi
  int v15; // eax
  float fNumFound; // [esp+0h] [ebp-8h]
  float fTotal; // [esp+4h] [ebp-4h]

  v8 = pSrcHeight;
  v9 = Y - 1;
  v10 = X - 1;
  v11 = SrcPitch;
  v12 = 0.0;
  v13 = 0.0;
  fTotal = 0.0;
  fNumFound = 0.0;
  if ( X - 1 >= 0 && v9 >= 0 && v10 < FullWidth && v9 < FullHeight )
  {
    v12 = pSrcHeight[v10 + SrcPitch * v9];
    v13 = 1.0;
    fTotal = v12;
    fNumFound = 1.0;
  }
  if ( X >= 0 && v9 >= 0 && X < FullWidth && v9 < FullHeight )
  {
    v12 = v12 + pSrcHeight[X + SrcPitch * v9];
    v13 = v13 + 1.0;
    fTotal = v12;
    fNumFound = v13;
  }
  v14 = v10 + 2;
  if ( v10 + 2 >= 0 && v9 >= 0 && v14 < FullWidth && v9 < FullHeight )
  {
    v12 = v12 + pSrcHeight[v14 + SrcPitch * v9];
    v13 = v13 + 1.0;
    fTotal = v12;
    fNumFound = v13;
  }
  if ( v10 >= 0 && Y >= 0 && v10 < FullWidth && Y < FullHeight )
  {
    v8 = pSrcHeight;
    v12 = v12 + pSrcHeight[v10 + SrcPitch * Y];
    v11 = SrcPitch;
    v13 = v13 + 1.0;
    fTotal = v12;
    fNumFound = v13;
  }
  if ( v14 >= 0 && Y >= 0 )
  {
    v8 = pSrcHeight;
    if ( v14 < FullWidth && Y < FullHeight )
    {
      v12 = v12 + pSrcHeight[v14 + v11 * Y];
      v13 = v13 + 1.0;
      fTotal = v12;
      fNumFound = v13;
    }
  }
  v15 = v9 + 2;
  if ( v10 >= 0 && v15 >= 0 && v10 < FullWidth && v15 < FullHeight )
  {
    v12 = v12 + v8[v10 + v11 * v15];
    v13 = v13 + 1.0;
    fTotal = v12;
    fNumFound = v13;
  }
  if ( X >= 0 && v15 >= 0 && X < FullWidth && v15 < FullHeight )
  {
    v12 = v12 + v8[X + v11 * v15];
    v13 = v13 + 1.0;
    fTotal = v12;
    fNumFound = v13;
  }
  if ( v14 >= 0 && v15 >= 0 && v14 < FullWidth && v15 < FullHeight )
  {
    v13 = v13 + 1.0;
    fTotal = v8[v14 + v11 * v15] + v12;
    fNumFound = v13;
  }
  if ( v13 <= 0.0 )
    return 0.0;
  else
    return fTotal / fNumFound;
}

//------------------------------------------------------------------------------
// Address: 0x004165C0
// Name: public: virtual void CGutterFloatMap::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGutterFloatMap::Execute(
        CGutterFloatMap *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  int m_Width; // edi
  float *m_pOutputHeightBits; // eax
  int v5; // ebx
  double v6; // st7
  float *v7; // eax
  float *v8; // edx
  float *m_pInputHeightBits; // eax
  int v10; // [esp+10h] [ebp-24h]
  float fThreshold; // [esp+14h] [ebp-20h]
  int g; // [esp+18h] [ebp-1Ch]
  int nSrcPitch; // [esp+1Ch] [ebp-18h]
  float *pScratch; // [esp+20h] [ebp-14h]
  int Index; // [esp+24h] [ebp-10h]
  int y; // [esp+28h] [ebp-Ch]
  float *v17; // [esp+2Ch] [ebp-8h]
  float *pSrc; // [esp+30h] [ebp-4h]

  m_Width = this->m_Width;
  pSrc = this->m_pInputHeightBits;
  m_pOutputHeightBits = this->m_pOutputHeightBits;
  pScratch = m_pOutputHeightBits;
  nSrcPitch = m_Width;
  g = 0;
  if ( this->m_GutterSize > 0 )
  {
    while ( 1 )
    {
      Index = 0;
      for ( y = 0; y < this->m_Height; ++y )
      {
        v5 = 0;
        if ( m_Width > 0 )
        {
          v17 = &m_pOutputHeightBits[Index];
          v10 = (char *)pSrc - (char *)m_pOutputHeightBits;
          do
          {
            fThreshold = this->m_fThreshold;
            if ( CGutterFloatMap::IsValidPixel(
                   this,
                   X: v5,
                   Y: y,
                   pSrcHeight: pSrc,
                   SrcPitch: nSrcPitch,
                   FullWidth: m_Width,
                   FullHeight: this->m_Height,
                   fThreshold) )
            {
              v7 = v17;
              v6 = *(float *)((char *)v17 + v10);
            }
            else
            {
              v6 = CGutterFloatMap::GutterPixel(
                     this,
                     X: v5,
                     Y: y,
                     pSrcHeight: pSrc,
                     SrcPitch: nSrcPitch,
                     FullWidth: m_Width,
                     FullHeight: this->m_Height,
                     fThreshold);
              v7 = v17;
            }
            ++Index;
            *v7 = v6;
            m_Width = this->m_Width;
            ++v17;
            ++v5;
          }
          while ( v5 < m_Width );
          m_pOutputHeightBits = pScratch;
        }
      }
      v8 = pSrc;
      pSrc = m_pOutputHeightBits;
      pScratch = v8;
      if ( ++g >= this->m_GutterSize )
        break;
      m_pOutputHeightBits = v8;
    }
  }
  m_pInputHeightBits = this->m_pInputHeightBits;
  if ( m_pInputHeightBits != pSrc )
    memcpy(
      dst: (unsigned __int8 *)m_pInputHeightBits,
      src: (unsigned __int8 *)pSrc,
      count: 4 * this->m_Width * this->m_Height);
}

//------------------------------------------------------------------------------
// Address: 0x00416730
// Name: enum _D3DXIMAGE_FILEFORMAT GetFileFormatFromFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetFileFormatFromFilename(const char *pszFilename)
{
  char szExtension[16]; // [esp+0h] [ebp-10h] BYREF

  V_ExtractFileExtension(path: pszFilename, dest: szExtension, destSize: 16);
  return V_strncasecmp(s1: szExtension, s2: "pfm", n: 16) != 0 ? 2 : 8;
}

//------------------------------------------------------------------------------
// Address: 0x00416770
// Name: bool ParseCommandLine(int,char __near * __near * const,struct SubDBakerArgs_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseCommandLine(int argc, char **argv, SubDBakerArgs_t *CmdArgs)
{
  int v4; // esi
  const char *v5; // ecx
  const char *v6; // ecx
  const char *v7; // ecx
  const char *v8; // ecx
  const char *v9; // ecx
  const char *v10; // edx
  const char *v11; // ecx
  const char *v12; // edx
  const char *v13; // ecx
  const char *v14; // eax
  const char *v15; // edx
  const char *v16; // ecx
  const char *v17; // eax
  long double v18; // st7
  const char *v19; // edx
  const char *v20; // ecx
  const char *v21; // eax
  char dest[16]; // [esp+14h] [ebp-10h] BYREF

  if ( argc < 1 )
  {
    printf(
      format: "\n"
      "Usage:\n"
      "\n"
      "subdbaker [options] [ cagemesh.obj detailmesh.obj ]\n"
      "\n"
      "options\n"
      " -?                 : display this message\n"
      " -m                 : do a full material transfer (disabled)\n"
      " -d <filename>      : generate displacement map <filename>\n"
      " -tsnorm <filename> : generate tangent-space normal map <filename>\n"
      " -osnorm <filename> : generate object-space normal map <filename>\n"
      " -edge <int> <fn>   : generate edge mask <fn> where edges are <int> pixels wide\n"
      " -ao <filename>     : generate ambient occlusion map <filename>\n"
      " -dao               : generate directional ambient occlusion (disabled)\n"
      " -cav <float> <fn>  : generate cavity map with <float> radius and filename <fn>\n"
      " -highsmooth <int>  : output a high-res smooth mesh with <int> subdivisions\n"
      "                      applied\n"
      " -highdisp <int>    : output a high-res displaced mesh with <int> subdivisions\n"
      "                      applied\n"
      "\n"
      " -w <int>           : output texture width in texels; default is 1024\n"
      " -h <int>           : output texture height in texels; default is 1024\n"
      " -g <int>           : gutter size in texels, default is 4\n"
      " -jrw <int>         : job rect width in texels, default is 16\n"
      " -jrh <int>         : job rect height in texels, default is 16\n"
      " -bias <float>      : ray-trace bias (0..); default is 0.01\n"
      " -samples <int>     : number of samples to use when tracing ambient\n"
      "                      occlusion (1..4096); default is 256\n"
      " -sampvar <int>     : number of sample variations to avoid banding (0..256);\n"
      "                      default is 128\n"
      " -threads <int>     : number of threads to create for parallel work;\n"
      "                      default is the number of processors\n"
      " -divs <int>        : number of subdivision to use for ao / cavity / etc\n"
      "                      calculations when no detail mesh is input; default is 16\n");
    return 0;
  }
  v4 = 1;
  if ( argc <= 1 )
    return 1;
  while ( 1 )
  {
    if ( _V_strcmp(s1: argv[v4], s2: "-?") == 0 || _V_strcmp(s1: argv[v4], s2: "/?") == 0 )
    {
      printf(
        format: "\n"
        "Usage:\n"
        "\n"
        "subdbaker [options] [ cagemesh.obj detailmesh.obj ]\n"
        "\n"
        "options\n"
        " -?                 : display this message\n"
        " -m                 : do a full material transfer (disabled)\n"
        " -d <filename>      : generate displacement map <filename>\n"
        " -tsnorm <filename> : generate tangent-space normal map <filename>\n"
        " -osnorm <filename> : generate object-space normal map <filename>\n"
        " -edge <int> <fn>   : generate edge mask <fn> where edges are <int> pixels wide\n"
        " -ao <filename>     : generate ambient occlusion map <filename>\n"
        " -dao               : generate directional ambient occlusion (disabled)\n"
        " -cav <float> <fn>  : generate cavity map with <float> radius and filename <fn>\n"
        " -highsmooth <int>  : output a high-res smooth mesh with <int> subdivisions\n"
        "                      applied\n"
        " -highdisp <int>    : output a high-res displaced mesh with <int> subdivisions\n"
        "                      applied\n"
        "\n"
        " -w <int>           : output texture width in texels; default is 1024\n"
        " -h <int>           : output texture height in texels; default is 1024\n"
        " -g <int>           : gutter size in texels, default is 4\n"
        " -jrw <int>         : job rect width in texels, default is 16\n"
        " -jrh <int>         : job rect height in texels, default is 16\n"
        " -bias <float>      : ray-trace bias (0..); default is 0.01\n"
        " -samples <int>     : number of samples to use when tracing ambient\n"
        "                      occlusion (1..4096); default is 256\n"
        " -sampvar <int>     : number of sample variations to avoid banding (0..256);\n"
        "                      default is 128\n"
        " -threads <int>     : number of threads to create for parallel work;\n"
        "                      default is the number of processors\n"
        " -divs <int>        : number of subdivision to use for ao / cavity / etc\n"
        "                      calculations when no detail mesh is input; default is 16\n");
      return 0;
    }
    if ( _V_strcmp(s1: argv[v4], s2: "-m") != 0 )
      break;
LABEL_48:
    if ( ++v4 >= argc )
      return 1;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-d") == 0 )
  {
    CmdArgs->m_bGenerateDisplacementMap = true;
    v5 = argv[++v4];
    V_strncpy(pDest: CmdArgs->m_szDispMapOutputFile, pSrc: v5, maxLen: 260);
    V_ExtractFileExtension(path: CmdArgs->m_szDispMapOutputFile, dest, destSize: 16);
    CmdArgs->m_DispFileFormat = V_strncasecmp(s1: dest, s2: "pfm", n: 16) != 0 ? D3DXIFF_TGA : D3DXIFF_PFM;
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-nop4") == 0 )
  {
    CmdArgs->m_bUseP4 = false;
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-tsnorm") == 0 )
  {
    CmdArgs->m_bGenerateTSNormalMap = true;
    v6 = argv[++v4];
    V_strncpy(pDest: CmdArgs->m_szTSNormOutputFile, pSrc: v6, maxLen: 260);
    CmdArgs->m_TSNormalFileFormat = GetFileFormatFromFilename(pszFilename: CmdArgs->m_szTSNormOutputFile);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-osnorm") == 0 )
  {
    CmdArgs->m_bGenerateOSNormalMap = true;
    v7 = argv[++v4];
    V_strncpy(pDest: CmdArgs->m_szOSNormOutputFile, pSrc: v7, maxLen: 260);
    CmdArgs->m_OSNormalFileFormat = GetFileFormatFromFilename(pszFilename: CmdArgs->m_szOSNormOutputFile);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-edge") == 0 )
  {
    CmdArgs->m_bGenerateEdgeMask = true;
    CmdArgs->m_fEdgeWidth = atof(nptr: argv[v4 + 1]);
    v8 = argv[v4 + 2];
    v4 += 2;
    V_strncpy(pDest: CmdArgs->m_szEdgeMaskOutputFile, pSrc: v8, maxLen: 260);
    CmdArgs->m_EdgeMaskFileFormat = GetFileFormatFromFilename(pszFilename: CmdArgs->m_szEdgeMaskOutputFile);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-ao") == 0 )
  {
    CmdArgs->m_bGenerateAmbientOcclusion = true;
    v9 = argv[++v4];
    V_strncpy(pDest: CmdArgs->m_szAOOutputFile, pSrc: v9, maxLen: 260);
    CmdArgs->m_AOMapFileFormat = GetFileFormatFromFilename(pszFilename: CmdArgs->m_szAOOutputFile);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-dao") == 0 )
    goto LABEL_48;
  if ( _V_strcmp(s1: argv[v4], s2: "-cav") == 0 )
  {
    CmdArgs->m_bGenerateCavityMap = true;
    CmdArgs->m_CavityRadius = atof(nptr: argv[v4 + 1]);
    v10 = argv[v4 + 2];
    v4 += 2;
    V_strncpy(pDest: CmdArgs->m_szCavityOutputFile, pSrc: v10, maxLen: 260);
    CmdArgs->m_CavityMapFileFormat = GetFileFormatFromFilename(pszFilename: CmdArgs->m_szCavityOutputFile);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-highsmooth") == 0 )
  {
    CmdArgs->m_bOutputHighResSmoothMesh = true;
    v11 = argv[++v4];
    CmdArgs->m_HighResOutputDivisions = atoi(nptr: v11);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-highdisp") == 0 )
  {
    CmdArgs->m_bOutputHighResDisplacedMesh = true;
LABEL_43:
    v21 = argv[++v4];
    CmdArgs->m_HighResOutputDivisions = atoi(nptr: v21);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-w") == 0 )
  {
    v12 = argv[++v4];
    CmdArgs->m_TextureWidth = atoi(nptr: v12);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-h") == 0 )
  {
    v13 = argv[++v4];
    CmdArgs->m_TextureHeight = atoi(nptr: v13);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-jrw") == 0 )
  {
    v14 = argv[++v4];
    CmdArgs->m_JobRectSizeU = atoi(nptr: v14);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-jrh") == 0 )
  {
    v15 = argv[++v4];
    CmdArgs->m_JobRectSizeV = atoi(nptr: v15);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-bias") == 0 )
  {
    v16 = argv[++v4];
    CmdArgs->m_flTraceBias = atof(nptr: v16);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-samples") == 0 )
  {
    v17 = argv[++v4];
    v18 = atof(nptr: v17);
    CmdArgs->m_SqrtNumSamples = (int)ceil(X: sqrt(v18));
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-sampvar") == 0 )
  {
    v19 = argv[++v4];
    CmdArgs->m_NumSampleVariations = atoi(nptr: v19);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-threads") == 0 )
  {
    v20 = argv[++v4];
    CmdArgs->m_nThreadOverride = atoi(nptr: v20);
    goto LABEL_48;
  }
  if ( _V_strcmp(s1: argv[v4], s2: "-divs") == 0 )
    goto LABEL_43;
  if ( CmdArgs->m_szCageMesh[0] == 0 )
  {
    V_strncpy(pDest: CmdArgs->m_szCageMesh, pSrc: argv[v4], maxLen: 260);
    goto LABEL_48;
  }
  if ( CmdArgs->m_szDetailMesh[0] == 0 )
  {
    V_strncpy(pDest: CmdArgs->m_szDetailMesh, pSrc: argv[v4], maxLen: 260);
    goto LABEL_48;
  }
  printf(format: "Invalid Argument\n\n");
  printf(
    format: "\n"
    "Usage:\n"
    "\n"
    "subdbaker [options] [ cagemesh.obj detailmesh.obj ]\n"
    "\n"
    "options\n"
    " -?                 : display this message\n"
    " -m                 : do a full material transfer (disabled)\n"
    " -d <filename>      : generate displacement map <filename>\n"
    " -tsnorm <filename> : generate tangent-space normal map <filename>\n"
    " -osnorm <filename> : generate object-space normal map <filename>\n"
    " -edge <int> <fn>   : generate edge mask <fn> where edges are <int> pixels wide\n"
    " -ao <filename>     : generate ambient occlusion map <filename>\n"
    " -dao               : generate directional ambient occlusion (disabled)\n"
    " -cav <float> <fn>  : generate cavity map with <float> radius and filename <fn>\n"
    " -highsmooth <int>  : output a high-res smooth mesh with <int> subdivisions\n"
    "                      applied\n"
    " -highdisp <int>    : output a high-res displaced mesh with <int> subdivisions\n"
    "                      applied\n"
    "\n"
    " -w <int>           : output texture width in texels; default is 1024\n"
    " -h <int>           : output texture height in texels; default is 1024\n"
    " -g <int>           : gutter size in texels, default is 4\n"
    " -jrw <int>         : job rect width in texels, default is 16\n"
    " -jrh <int>         : job rect height in texels, default is 16\n"
    " -bias <float>      : ray-trace bias (0..); default is 0.01\n"
    " -samples <int>     : number of samples to use when tracing ambient\n"
    "                      occlusion (1..4096); default is 256\n"
    " -sampvar <int>     : number of sample variations to avoid banding (0..256);\n"
    "                      default is 128\n"
    " -threads <int>     : number of threads to create for parallel work;\n"
    "                      default is the number of processors\n"
    " -divs <int>        : number of subdivision to use for ao / cavity / etc\n"
    "                      calculations when no detail mesh is input; default is 16\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00416CC0
// Name: bool SetupPerforce(bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetupPerforce(bool bUseP4)
{
  struct CSysModule *Module; // eax
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IP4 *v5; // eax
  IP4_vtbl *v6; // esi
  void *(__cdecl *v7)(const char *, int *); // eax

  if ( bUseP4 )
  {
    Module = Sys_LoadModule(pModuleName: "p4lib.dll");
    v2 = Module;
    if ( Module == nullptr )
    {
      printf(format: "Can't load %s.\n", "p4lib.dll");
      return 0;
    }
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory == nullptr )
    {
      printf(format: "Can't get factory from %s.\n", "p4lib.dll");
      Sys_UnloadModule(pModule: v2);
      return 0;
    }
    v5 = (IP4 *)Factory(a1: "VP4002", a2: nullptr);
    p4 = v5;
    if ( v5 != nullptr )
    {
      v6 = v5->__vftable;
      v7 = FileSystem_GetFactory();
      v6->Connect(this: p4, a2: v7);
      p4->Init(this: p4);
      goto LABEL_9;
    }
    printf(format: "Can't get IP4 interface from %s, proceeding with -nop4.\n", "p4lib.dll");
  }
  CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: true);
LABEL_9:
  CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "SubDBaker Auto Checkout");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416D90
// Name: bool NeedsDisplacementCalc(struct SubDBakerArgs_t __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl NeedsDisplacementCalc(SubDBakerArgs_t *CmdArgs)
{
  return CmdArgs->m_bGenerateDisplacementMap
      || CmdArgs->m_bGenerateAmbientOcclusion
      || CmdArgs->m_bGenerateTSNormalMap
      || CmdArgs->m_bGenerateOSNormalMap
      || CmdArgs->m_bGenerateCavityMap;
}

//------------------------------------------------------------------------------
// Address: 0x00416DD0
// Name: public: void CProgressBar::UpdateProgress(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressBar::UpdateProgress(CProgressBar *this, int nRemainingUnits)
{
  __m128i v3; // xmm1
  int m_nTicksShown; // ecx
  int v5; // edi
  int v6; // esi

  v3 = _mm_cvtsi32_si128(this->m_nTotalUnits);
  m_nTicksShown = this->m_nTicksShown;
  v5 = (int)(float)((float)(1.0 - (float)((float)nRemainingUnits / _mm_cvtepi32_ps(v3).m128_f32[0])) * 80.0);
  if ( v5 > m_nTicksShown )
  {
    if ( v5 - m_nTicksShown > 0 )
    {
      v6 = v5 - m_nTicksShown;
      do
      {
        printf(format: "|");
        --v6;
      }
      while ( v6 != 0 );
    }
    this->m_nTicksShown = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416E30
// Name: bool CreateD3DDevice(struct IDirect3D9 __near * __near *,struct IDirect3DDevice9 __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateD3DDevice(IDirect3D9 **ppd3d9, IDirect3DDevice9 **ppd3dDevice)
{
  IDirect3D9 *v2; // eax
  IDirect3D9 *v3; // eax
  _D3DPRESENT_PARAMETERS_ pp; // [esp+8h] [ebp-38h] BYREF

  v2 = Direct3DCreate9(SDKVersion: 0x20u);
  *ppd3d9 = v2;
  if ( v2 == nullptr )
    return false;
  pp.BackBufferWidth = 320;
  pp.BackBufferHeight = 240;
  pp.BackBufferFormat = D3DFMT_X8R8G8B8;
  pp.BackBufferCount = 1;
  pp.MultiSampleType = D3DMULTISAMPLE_NONE;
  pp.MultiSampleQuality = 0;
  pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  pp.Windowed = 1;
  pp.hDeviceWindow = GetShellWindow();
  v3 = *ppd3d9;
  memset(&pp.Flags, 0, 12);
  pp.EnableAutoDepthStencil = 0;
  return v3->CreateDevice(this: v3, a2: 0, a3: D3DDEVTYPE_HAL, a4: nullptr, a5: 68u, a6: &pp, a7: ppd3dDevice) >= 0
      || (*ppd3d9)->CreateDevice(
           this: *ppd3d9,
           a2: 0,
           a3: D3DDEVTYPE_HAL,
           a4: nullptr,
           a5: 36u,
           a6: &pp,
           a7: ppd3dDevice) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00416EE0
// Name: protected: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nBlocks)
{
  int m_nBlocks; // ebx
  int v4; // edi
  CacheOptimizedTriangle **v5; // eax
  int v6; // edi
  unsigned int v7; // ebx

  m_nBlocks = this->m_nBlocks;
  v4 = nBlocks;
  for ( this->m_nBlocks = nBlocks; v4 < m_nBlocks; ++v4 )
    free(pMem: this->m_pMemory[v4]);
  if ( this->m_pMemory != nullptr )
    v5 = (CacheOptimizedTriangle **)_realloc_crt(ptr: this->m_pMemory, size: 4 * this->m_nBlocks);
  else
    v5 = (CacheOptimizedTriangle **)operator new(nSize: 4 * this->m_nBlocks);
  this->m_pMemory = v5;
  if ( v5 == nullptr )
    _Error(a1: "CUtlBlockMemory overflow!\n");
  v6 = m_nBlocks;
  if ( m_nBlocks < this->m_nBlocks )
  {
    v7 = 16 * (3 * ((32 * *((_DWORD *)this + 2)) >> 5) + 3);
    do
      this->m_pMemory[v6++] = (CacheOptimizedTriangle *)operator new(nSize: v7);
    while ( v6 < this->m_nBlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416F80
// Name: public: virtual void CRayTraceDisplacementJob::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CRayTraceDisplacementJob::Execute(
        CRayTraceDisplacementJob *this@<ecx>,
        float a2@<ebp>,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  unsigned int v4; // eax
  int v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // eax
  RTECullMode_t v8; // esi
  bool v9; // zf
  unsigned int v10; // esi
  int v11; // ecx
  float m_flTraceBias; // xmm1_4
  float m_flTraceLength; // xmm6_4
  RayTracingEnvironment *m_pRTE; // ecx
  int v15; // eax
  unsigned __int8 *m_pNormalOutputStart; // ecx
  double v17; // st7
  float v18; // xmm4_4
  unsigned int v19; // esi
  float v20; // xmm1_4
  float v21; // xmm3_4
  std::vector<OBJ_VERTEX> *m_pTriVerts; // edx
  std::vector<unsigned int> *m_pTriIndices; // eax
  int v24; // ecx
  int v25; // eax
  float v26; // edx
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm0_4
  unsigned int v31; // eax
  OBJ_VERTEX *v32; // eax
  float z; // edx
  float w; // xmm0_4
  OBJ_VERTEX *v35; // eax
  float v36; // ecx
  float x; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm0_4
  int v44; // eax
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  float v48; // edx
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  float v52; // xmm3_4
  RayTracingEnvironment *v53; // ecx
  unsigned int v54; // eax
  double v55; // st7
  double v56; // st7
  OBJ_VERTEX v57; // [esp-98h] [ebp-594h] BYREF
  OBJ_VERTEX v58; // [esp-64h] [ebp-560h]
  OBJ_VERTEX v59; // [esp-30h] [ebp-52Ch]
  Vector V; // [esp+4h] [ebp-4F8h]
  _BYTE v61[12]; // [esp+20h] [ebp-4DCh] BYREF
  RayStream ray_trace_stream_ctx; // [esp+2Ch] [ebp-4D0h] BYREF
  Vector vRayEnd; // [esp+3CCh] [ebp-130h] BYREF
  Vector v64; // [esp+3D8h] [ebp-124h] BYREF
  Vector vACCPos; // [esp+3E4h] [ebp-118h] BYREF
  OBJ_VERTEX v0; // [esp+3FCh] [ebp-100h]
  Vector vHit; // [esp+430h] [ebp-CCh]
  OBJ_VERTEX v2; // [esp+43Ch] [ebp-C0h]
  OBJ_VERTEX v1; // [esp+470h] [ebp-8Ch] BYREF
  float v70; // [esp+4A4h] [ebp-58h]
  float v71; // [esp+4A8h] [ebp-54h]
  Vector vRayStart; // [esp+4ACh] [ebp-50h] BYREF
  Vector vACCNorm; // [esp+4B8h] [ebp-44h] BYREF
  unsigned int v74; // [esp+4C4h] [ebp-38h]
  int j; // [esp+4C8h] [ebp-34h]
  RTECullMode_t v76; // [esp+4CCh] [ebp-30h]
  unsigned int u; // [esp+4D0h] [ebp-2Ch]
  int i; // [esp+4D4h] [ebp-28h]
  RTECullMode_t cullMode; // [esp+4D8h] [ebp-24h]
  RTECullMode_t v80; // [esp+4DCh] [ebp-20h]
  unsigned int iRowStart; // [esp+4E0h] [ebp-1Ch]
  unsigned int v; // [esp+4E4h] [ebp-18h]
  unsigned int NumResults; // [esp+4E8h] [ebp-14h]
  int v84; // [esp+4ECh] [ebp-10h]
  float flSignMul; // [esp+4F0h] [ebp-Ch]
  void *v86; // [esp+4F4h] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+4FCh] [ebp+0h]

  flSignMul = a2;
  v86 = retaddr;
  v4 = (this->m_RectSizeU * this->m_RectSizeV) << 6;
  v5 = (unsigned __int64)(this->m_RectSizeU * this->m_RectSizeV) >> 26 != 0;
  memset(&ray_trace_stream_ctx.PendingStreamOutputs[7][1], 0, 32);
  v6 = (unsigned __int8 *)operator new(nSize: v4 | -v5);
  LODWORD(V.y) = (this->m_RectSizeU * this->m_RectSizeV) << 6;
  u = (unsigned int)v6;
  memset(dst: v6, value: 0, count: LODWORD(V.y));
  for ( j = 0; j < 2; ++j )
  {
    HIBYTE(NumResults) = j == 0;
    *(float *)&v = -1.0;
    if ( j == 0 )
      *(float *)&v = 1.0;
    v76 = RTE_CULL_FRONT;
    if ( j != 0 )
      v76 = RTE_CULL_BACK;
    v7 = 0;
    v8 = RTE_CULL_NONE;
    v80 = RTE_CULL_NONE;
    i = 0;
    for ( cullMode = RTE_CULL_NONE; cullMode < this->m_RectSizeV; ++cullMode )
    {
      v9 = this->m_RectSizeU == 0;
      v74 = 0;
      if ( !v9 )
      {
        v84 = 4 * v7;
        iRowStart = 8 * v7;
        v10 = (v8 << 6) + u + 44;
        do
        {
          v11 = *(unsigned int *)((char *)this->m_pPatchIDStart + v84);
          if ( v11 != 0 )
          {
            CSubDMesh::EvalulateACCPatchAtUV(
              this: this->m_pSubDMesh,
              iPatchID: v11 - 1,
              U: *(float *)((char *)&this->m_pPatchUVStart->x + iRowStart),
              V: *(float *)((char *)&this->m_pPatchUVStart->y + iRowStart),
              pOutPosition: &v64,
              pOutNormal: &vRayStart);
            m_flTraceBias = this->m_flTraceBias;
            LODWORD(V.z) = v76;
            LODWORD(V.y) = v10 - 44;
            LODWORD(V.x) = &ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[1];
            m_flTraceLength = this->m_flTraceLength;
            LODWORD(v59.tanU.w) = &v1.tanU.w;
            LODWORD(v59.tanU.z) = v61;
            m_pRTE = this->m_pRTE;
            v1.tanU.w = (float)(vRayStart.x * m_flTraceBias) + v64.x;
            v70 = v64.y + (float)(vRayStart.y * m_flTraceBias);
            v71 = v64.z + (float)(vRayStart.z * m_flTraceBias);
            ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[1] = (float)((float)(vRayStart.x * *(float *)&v)
                                                                                * m_flTraceLength)
                                                                        + v1.tanU.w;
            ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[2] = (float)((float)(vRayStart.y * *(float *)&v)
                                                                                * m_flTraceLength)
                                                                        + v70;
            ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3] = (float)((float)(vRayStart.z * *(float *)&v)
                                                                                * m_flTraceLength)
                                                                        + v71;
            RayTracingEnvironment::AddToRayStream(
              this: m_pRTE,
              s: (RayStream *)v61,
              start: (const Vector *)&v1.tanU.w,
              end: (const Vector *)&ray_trace_stream_ctx.PendingRays[7].direction.z.m128_i16[2],
              rslt_out: (RayTracingSingleResult *)(v10 - 44),
              cullMode: v76);
            v15 = v84;
            *(_DWORD *)(v10 - 20) = (char *)this->m_pDistanceOutputStart + v84;
            m_pNormalOutputStart = this->m_pNormalOutputStart;
            if ( m_pNormalOutputStart != nullptr )
              *(_DWORD *)(v10 - 16) = &m_pNormalOutputStart[v15];
            ++v80;
            *(float *)(v10 - 8) = v1.tanU.w;
            *(float *)(v10 - 4) = v70;
            *(float *)v10 = v71;
            *(Vector *)(v10 + 4) = vRayStart;
            v17 = *(float *)((char *)this->m_pCageHitStart + v15);
            v7 = i;
            *(float *)(v10 - 12) = v17;
            *(_BYTE *)(v10 + 16) = 0;
            v10 += 64;
          }
          iRowStart += 8;
          v84 += 4;
          ++v74;
        }
        while ( v74 < this->m_RectSizeU );
        v8 = v80;
      }
      v7 += this->m_PatchPitch;
      i = v7;
    }
    RayTracingEnvironment::FinishRayStream(this: this->m_pRTE, s: (RayStream *)v61, cullMode: RTE_CULL_NONE);
    if ( v8 == RTE_CULL_NONE )
      continue;
    v18 = *(float *)&v;
    while ( 2 )
    {
      v84 = 0;
      if ( v8 == RTE_CULL_NONE )
        goto LABEL_34;
      v19 = u + 52;
      iRowStart = u + 44;
      cullMode = v80;
      do
      {
        if ( *(int *)(v19 - 40) <= -1 )
        {
          if ( *(_BYTE *)(v19 + 8) != 0 )
            goto LABEL_31;
          v1.tanU.y = (float)(rand() - 0x3FFF) * 0.000061038882;
          v1.tanU.z = (float)(rand() - 0x3FFF) * 0.000061038882;
          v44 = rand();
          v45 = (float)(v1.tanU.y * 0.0099999998) + *(float *)(v19 + 4);
          v46 = *(float *)(v19 - 4) + (float)((float)((float)(v44 - 0x3FFF) * 0.000061038882) * 0.0099999998);
          v47 = *(float *)v19 + (float)(v1.tanU.z * 0.0099999998);
          LODWORD(V.z) = v19 - 4;
          *(float *)LODWORD(V.z) = v46;
          *(float *)v19 = v47;
          *(float *)(v19 + 4) = v45;
          VectorNormalize(vec: (Vector *)LODWORD(V.z));
          v48 = *(float *)(v19 - 8);
          v49 = *(float *)v19;
          v50 = *(float *)(v19 + 4);
          *(_QWORD *)&vACCNorm.x = *(_QWORD *)(v19 - 16);
          v51 = *(float *)(v19 - 4) * *(float *)&v;
          LODWORD(V.z) = v76;
          v52 = this->m_flTraceLength;
          LODWORD(V.y) = iRowStart - 44;
          vACCNorm.z = v48;
          LODWORD(V.x) = &vRayEnd;
          vRayEnd.y = vACCNorm.y + (float)((float)(v49 * *(float *)&v) * v52);
          LODWORD(v59.tanU.w) = &vACCNorm;
          LODWORD(v59.tanU.z) = v61;
          v53 = this->m_pRTE;
          vRayEnd.x = vACCNorm.x + (float)(v51 * v52);
          vRayEnd.z = v48 + (float)((float)(v50 * *(float *)&v) * v52);
          RayTracingEnvironment::AddToRayStream(
            this: v53,
            s: (RayStream *)v61,
            start: &vACCNorm,
            end: &vRayEnd,
            rslt_out: (RayTracingSingleResult *)(iRowStart - 44),
            cullMode: v76);
          v54 = iRowStart;
          *(Vector *)(iRowStart - 8) = vACCNorm;
          v55 = *(float *)(v19 - 4);
          ++v84;
          *(float *)(v54 + 4) = v55;
          v54 += 64;
          *(float *)(v54 - 56) = *(float *)v19;
          iRowStart = v54;
          *(float *)(v54 - 52) = *(float *)(v19 + 4);
          v56 = *(float *)(v19 - 20);
          *(_BYTE *)(v54 - 48) = 1;
          *(float *)(v54 - 76) = v56;
          *(_DWORD *)(v54 - 84) = *(_DWORD *)(v19 - 28);
          *(_DWORD *)(v54 - 80) = *(_DWORD *)(v19 - 24);
          goto LABEL_30;
        }
        v20 = **(float **)(v19 - 28);
        v21 = (float)(this->m_flTraceBias * v18) + *(float *)(v19 - 36);
        if ( fabs(v20) > v21 || v20 == 0.0 )
        {
          **(float **)(v19 - 28) = v21 * v18;
          if ( *(_DWORD *)(v19 - 24) != 0 )
          {
            m_pTriVerts = this->m_pTriVerts;
            if ( m_pTriVerts != nullptr )
            {
              m_pTriIndices = this->m_pTriIndices;
              if ( m_pTriIndices != nullptr )
              {
                v24 = 3 * *(_DWORD *)(v19 - 40);
                v25 = (int)&m_pTriVerts->_Myfirst[m_pTriIndices->_Myfirst[v24]];
                v26 = *(float *)(v25 + 24);
                v27 = *(float *)v25;
                v28 = *(float *)(v25 + 4);
                v29 = *(float *)(v25 + 8);
                v0.pos.x = *(float *)(v25 + 12);
                *(_QWORD *)&v0.pos.y = *(_QWORD *)(v25 + 16);
                v0.nor = *(Vector *)(v25 + 28);
                v0.texUV = *(Vector2D *)(v25 + 40);
                v30 = *(float *)(v25 + 48);
                v31 = this->m_pTriIndices->_Myfirst[v24 + 1];
                v0.tanU.x = v30;
                v0.pos.w = v26;
                v32 = &this->m_pTriVerts->_Myfirst[v31];
                z = v32->nor.z;
                v2.tanU.y = v32->pos.x;
                v2.tanU.z = v32->pos.y;
                v2.tanU.w = v32->pos.z;
                v1.pos.x = v32->pos.w;
                *(_QWORD *)&v1.pos.y = *(_QWORD *)&v32->nor.x;
                v1.nor = *(Vector *)&v32->texUV.x;
                v1.texUV = *(Vector2D *)&v32->tanU.y;
                w = v32->tanU.w;
                v35 = &this->m_pTriVerts->_Myfirst[this->m_pTriIndices->_Myfirst[v24 + 2]];
                v1.tanU.x = w;
                v1.pos.w = z;
                v36 = v35->nor.z;
                vHit.y = v35->pos.y;
                vHit.z = v35->pos.z;
                v2.pos.x = v35->pos.w;
                *(_QWORD *)&v2.pos.y = *(_QWORD *)&v35->nor.x;
                v2.nor.x = v35->texUV.x;
                v2.nor.y = v35->texUV.y;
                x = v35->tanU.x;
                v2.pos.w = v36;
                v2.nor.z = x;
                v38 = *(float *)v19;
                v39 = *(float *)(v19 + 4);
                v2.texUV = *(Vector2D *)&v35->tanU.y;
                v2.tanU.x = v35->tanU.w;
                v40 = v38 * v21;
                v41 = v39 * v21;
                v42 = *(float *)(v19 - 16) + (float)((float)(*(float *)(v19 - 4) * v21) * v18);
                v0.tanU.z = *(float *)(v19 - 12) + (float)(v40 * v18);
                v0.tanU.w = *(float *)(v19 - 8) + (float)(v41 * v18);
                v0.tanU.y = v42;
                *(_QWORD *)&V.x = *(_QWORD *)&v0.tanU.y;
                v43 = v35->pos.x;
                V.z = v0.tanU.w;
                v59.pos.x = v43;
                v59.pos.y = vHit.y;
                v59.pos.z = vHit.z;
                *(Vector4D *)&v59.pos.w = v2.pos;
                v59.texUV.x = v2.nor.x;
                v59.texUV.y = v2.nor.y;
                v59.tanU = *(Vector4D *)&v2.nor.z;
                v58.pos.x = v2.tanU.y;
                v58.pos.y = v2.tanU.z;
                v58.pos.z = v2.tanU.w;
                *(Vector4D *)&v58.pos.w = v1.pos;
                v58.texUV = *(Vector2D *)&v1.nor.x;
                v58.tanU = *(Vector4D *)&v1.nor.z;
                *(Vector4D *)&v57.pos.w = v0.pos;
                v57.pos.x = v27;
                v57.pos.y = v28;
                v57.pos.z = v29;
                v57.texUV = *(Vector2D *)&v0.nor.x;
                v57.tanU = *(Vector4D *)&v0.nor.z;
                i = (int)&v57;
                CalculateSmoothNormal(result: &vACCPos, v0: v57, v1: v58, v2: v59, vHit: V);
                *(_BYTE *)(*(_DWORD *)(v19 - 24) + 2) = (int)(float)((float)(vACCPos.x * 127.0) + 128.0);
                *(_BYTE *)(*(_DWORD *)(v19 - 24) + 1) = (int)(float)((float)(vACCPos.y * 127.0) + 128.0);
                **(_BYTE **)(v19 - 24) = (int)(float)((float)(vACCPos.z * 127.0) + 128.0);
                *(_BYTE *)(*(_DWORD *)(v19 - 24) + 3) = 0;
LABEL_30:
                v18 = *(float *)&v;
              }
            }
          }
        }
LABEL_31:
        v19 += 64;
        --cullMode;
      }
      while ( cullMode != RTE_CULL_NONE );
      if ( v84 != 0 )
      {
        RayTracingEnvironment::FinishRayStream(this: this->m_pRTE, s: (RayStream *)v61, cullMode: RTE_CULL_NONE);
        v18 = *(float *)&v;
      }
LABEL_34:
      v80 = v84;
      if ( v84 != 0 )
      {
        v8 = v80;
        continue;
      }
      break;
    }
  }
  free(pMem: (void *)u);
}

//------------------------------------------------------------------------------
// Address: 0x00417940
// Name: public: virtual void CRayTraceAmbientOcclusionJob::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRayTraceAmbientOcclusionJob::Execute(
        CRayTraceAmbientOcclusionJob *this@<ecx>,
        unsigned int a2@<ebp>,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  CUniformSampler *m_pSampler; // eax
  int m_NumSamples; // ecx
  unsigned int v6; // eax
  unsigned __int8 *v7; // edi
  int v8; // eax
  int v9; // ecx
  bool v10; // zf
  unsigned int v11; // edx
  int v12; // ecx
  Vector2D *v13; // eax
  float U; // xmm0_4
  float V; // xmm1_4
  CSubDMesh *m_pSubDMesh; // ecx
  float v17; // xmm0_4
  int v18; // edi
  float v19; // xmm5_4
  float v20; // xmm4_4
  CUniformSampler *v21; // ecx
  int v22; // eax
  float m_flTraceLength; // xmm3_4
  __int64 v24; // xmm0_8
  RayTracingEnvironment *m_pRTE; // ecx
  unsigned int v26; // eax
  int v27; // eax
  unsigned int v28; // ecx
  unsigned int v29; // edi
  float v30; // xmm0_4
  int *v31; // eax
  unsigned int v32; // ecx
  float **v33; // eax
  unsigned int v34; // edx
  int v35; // edi
  unsigned int v36; // edx
  int v37; // eax
  float *m_pAOOutputStart; // ecx
  float v39; // xmm0_4
  int v40; // [esp-4h] [ebp-450h]
  unsigned int v41; // [esp+8h] [ebp-444h]
  _BYTE v42[12]; // [esp+20h] [ebp-42Ch] BYREF
  RayStream ray_trace_stream_ctx; // [esp+2Ch] [ebp-420h] BYREF
  Vector v44; // [esp+3CCh] [ebp-80h] BYREF
  Vector vACCPos; // [esp+3D8h] [ebp-74h] BYREF
  Vector vRayEnd; // [esp+3E4h] [ebp-68h] BYREF
  Vector vACCNorm; // [esp+3F0h] [ebp-5Ch]
  float v48; // [esp+3FCh] [ebp-50h]
  int v49; // [esp+400h] [ebp-4Ch]
  float v50; // [esp+404h] [ebp-48h] BYREF
  float fDisplaceAmount; // [esp+408h] [ebp-44h]
  float v52; // [esp+40Ch] [ebp-40h]
  Vector vRayStart; // [esp+410h] [ebp-3Ch]
  int NumVariations; // [esp+41Ch] [ebp-30h]
  int iVariation; // [esp+420h] [ebp-2Ch]
  unsigned int v56; // [esp+424h] [ebp-28h]
  unsigned int iRowStart; // [esp+428h] [ebp-24h]
  unsigned int u; // [esp+42Ch] [ebp-20h]
  char *v59; // [esp+430h] [ebp-1Ch]
  unsigned int i; // [esp+434h] [ebp-18h]
  int v61; // [esp+438h] [ebp-14h]
  int v62; // [esp+43Ch] [ebp-10h]
  unsigned int v; // [esp+440h] [ebp-Ch]
  unsigned int NumResults; // [esp+444h] [ebp-8h]
  unsigned int retaddr; // [esp+44Ch] [ebp+0h]

  v = a2;
  NumResults = retaddr;
  m_pSampler = this->m_pSampler;
  memset(&ray_trace_stream_ctx.PendingStreamOutputs[7][1], 0, 32);
  m_NumSamples = m_pSampler->m_NumSamples;
  LODWORD(vRayStart.x) = m_pSampler->m_NumVariations;
  v6 = this->m_RectSizeV * m_NumSamples * this->m_RectSizeU;
  v62 = m_NumSamples;
  v7 = (unsigned __int8 *)operator new(nSize: 32 * v6);
  v41 = 32 * this->m_RectSizeV * v62 * this->m_RectSizeU;
  v59 = (char *)v7;
  v61 = 0;
  memset(dst: v7, value: 0, count: v41);
  v8 = rand();
  v9 = 0;
  NumVariations = 0;
  i = 0;
  for ( LODWORD(vRayStart.y) = v8 % SLODWORD(vRayStart.x); i < this->m_RectSizeV; ++i )
  {
    v10 = this->m_RectSizeU == 0;
    iVariation = 0;
    if ( !v10 )
    {
      v49 = 32 * v62;
      v11 = 4 * v9;
      LODWORD(vRayStart.z) = &v7[32 * v61];
      iRowStart = 4 * v9;
      v56 = 8 * v9;
      do
      {
        v12 = *(unsigned int *)((char *)this->m_pPatchIDStart + v11);
        if ( v12 != 0 )
        {
          v13 = &this->m_pPatchUVStart[v56 / 8];
          U = v13->x;
          V = v13->y;
          v40 = v12 - 1;
          m_pSubDMesh = this->m_pSubDMesh;
          v48 = *(float *)((char *)this->m_pDisplacementStart + v11);
          CSubDMesh::EvalulateACCPatchAtUV(
            this: m_pSubDMesh,
            iPatchID: v40,
            U,
            V,
            pOutPosition: &v44,
            pOutNormal: &vRayEnd);
          v17 = this->m_flTraceBias + v48;
          v18 = 0;
          v19 = v44.y + (float)(vRayEnd.y * v17);
          v20 = v44.z + (float)(vRayEnd.z * v17);
          v50 = (float)(vRayEnd.x * v17) + v44.x;
          fDisplaceAmount = v19;
          v52 = v20;
          if ( v62 > 0 )
          {
            v61 += v62;
            u = LODWORD(vRayStart.z);
            LODWORD(vRayStart.z) += v49;
            while ( 1 )
            {
              v21 = this->m_pSampler;
              v22 = LODWORD(vRayStart.y) * v21->m_NumSamples;
              m_flTraceLength = this->m_flTraceLength;
              v24 = *(_QWORD *)&v21->m_pvDirections[v18 + v22].x;
              vACCNorm.z = v21->m_pvDirections[v18 + v22].z;
              *(_QWORD *)&vACCNorm.x = v24;
              m_pRTE = this->m_pRTE;
              vACCPos.x = (float)(*(float *)&v24 * m_flTraceLength) + v50;
              vACCPos.y = (float)(*((float *)&v24 + 1) * m_flTraceLength) + v19;
              vACCPos.z = (float)(vACCNorm.z * m_flTraceLength) + v20;
              RayTracingEnvironment::AddToRayStream(
                this: m_pRTE,
                s: (RayStream *)v42,
                start: (const Vector *)&v50,
                end: &vACCPos,
                rslt_out: (RayTracingSingleResult *)u,
                cullMode: RTE_CULL_NONE);
              v26 = u;
              *(_DWORD *)(u + 28) = &this->m_pAOOutputStart[iRowStart / 4];
              ++v18;
              u = v26 + 32;
              if ( v18 >= v62 )
                break;
              v20 = v52;
              v19 = fDisplaceAmount;
            }
          }
        }
        v27 = rand();
        v56 += 8;
        ++iVariation;
        LODWORD(vRayStart.y) = v27 % SLODWORD(vRayStart.x);
        v11 = iRowStart + 4;
        iRowStart += 4;
      }
      while ( iVariation < this->m_RectSizeU );
      v9 = NumVariations;
      v7 = (unsigned __int8 *)v59;
    }
    v9 += this->m_PatchPitch;
    NumVariations = v9;
  }
  RayTracingEnvironment::FinishRayStream(this: this->m_pRTE, s: (RayStream *)v42, cullMode: RTE_CULL_NONE);
  v28 = v61;
  v29 = 0;
  v30 = 1.0 / (float)v62;
  if ( v61 >= 4 )
  {
    v31 = (int *)(v59 + 28);
    v32 = ((unsigned int)(v61 - 4) >> 2) + 1;
    v29 = 4 * v32;
    do
    {
      if ( *(v31 - 4) > -1 )
        *(float *)*v31 = *(float *)*v31 + v30;
      if ( v31[4] > -1 )
        *(float *)v31[8] = *(float *)v31[8] + v30;
      if ( v31[12] > -1 )
        *(float *)v31[16] = *(float *)v31[16] + v30;
      if ( v31[20] > -1 )
        *(float *)v31[24] = *(float *)v31[24] + v30;
      v31 += 32;
      --v32;
    }
    while ( v32 != 0 );
    v28 = v61;
  }
  if ( v29 < v28 )
  {
    v33 = (float **)&v59[32 * v29 + 28];
    v34 = v28 - v29;
    do
    {
      if ( (int)*(v33 - 4) > -1 )
        **v33 = v30 + **v33;
      v33 += 8;
      --v34;
    }
    while ( v34 != 0 );
  }
  v35 = 0;
  for ( i = 0; i < this->m_RectSizeV; ++i )
  {
    v36 = 0;
    if ( this->m_RectSizeU != 0 )
    {
      v37 = v35;
      do
      {
        this->m_pAOOutputStart[v37] = 1.0 - this->m_pAOOutputStart[v37];
        m_pAOOutputStart = this->m_pAOOutputStart;
        if ( (float)(m_pAOOutputStart[v37] + 0.5) >= 1.0 )
          v39 = 1.0;
        else
          v39 = m_pAOOutputStart[v37] + 0.5;
        m_pAOOutputStart[v37] = v39;
        ++v36;
        ++v37;
      }
      while ( v36 < this->m_RectSizeU );
    }
    v35 += this->m_PatchPitch;
  }
  free(pMem: v59);
}

//------------------------------------------------------------------------------
// Address: 0x00417D30
// Name: class Vector2D ComputeConsistentDisplacementUVs(class Vector2D,struct OptimizedModel::SubD_Face_t __near &,struct mstudiovertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
Vector2D *__cdecl ComputeConsistentDisplacementUVs(
        Vector2D *result,
        Vector2D UV,
        OptimizedModel::SubD_Face_t *patch,
        mstudiovertex_t *pVertices)
{
  Vector2D *p_m_vecTexCoord; // edx
  float y; // xmm0_4
  Vector2D *v6; // edx
  float v7; // xmm0_4
  Vector2D *v8; // edx
  float v9; // xmm0_4
  Vector2D *v10; // edx
  float v11; // xmm0_4
  Vector2D *v12; // edx
  float v13; // xmm0_4
  Vector2D *v14; // edx
  float v15; // xmm0_4
  Vector2D *v16; // edx
  float v17; // xmm0_4
  Vector2D *v18; // edx
  float v19; // xmm0_4
  Vector2D *v20; // edx
  float v21; // xmm0_4
  int v22; // edx
  Vector2D *v23; // edx
  float v24; // xmm0_4
  Vector2D *v25; // edx
  float v26; // xmm0_4
  Vector2D *v27; // edx
  float v28; // xmm0_4
  Vector2D *v29; // edx
  float v30; // xmm0_4
  int v31; // edx
  float v32; // xmm0_4
  int v33; // eax
  int v34; // edx
  int v35; // ebx
  int v36; // edi
  int v37; // esi
  Vector2D *v38; // eax
  float v39; // xmm1_4
  float v40; // xmm2_4
  int v41; // eax
  float v42; // xmm3_4
  float v43; // xmm4_4
  Vector2D *v44; // eax
  float v45; // xmm4_4
  Vector2D t3[4]; // [esp+Ch] [ebp-80h] BYREF
  Vector2D t2[4]; // [esp+2Ch] [ebp-60h]
  Vector2D t0[4]; // [esp+4Ch] [ebp-40h] BYREF
  Vector2D t1[4]; // [esp+6Ch] [ebp-20h]

  p_m_vecTexCoord = &pVertices[patch->vUV0[0]].m_vecTexCoord;
  t0[0].x = p_m_vecTexCoord->x;
  y = p_m_vecTexCoord->y;
  v6 = &pVertices[patch->vUV1[0]].m_vecTexCoord;
  t0[0].y = y;
  t0[1].x = v6->x;
  v7 = v6->y;
  v8 = &pVertices[patch->vUV2[0]].m_vecTexCoord;
  t0[1].y = v7;
  t0[2].x = v8->x;
  v9 = v8->y;
  v10 = &pVertices[patch->vUV3[0]].m_vecTexCoord;
  t0[2].y = v9;
  t0[3].x = v10->x;
  v11 = v10->y;
  v12 = &pVertices[patch->vUV0[1]].m_vecTexCoord;
  t0[3].y = v11;
  t1[0].x = v12->x;
  v13 = v12->y;
  v14 = &pVertices[patch->vUV1[1]].m_vecTexCoord;
  t1[0].y = v13;
  t1[1].x = v14->x;
  v15 = v14->y;
  v16 = &pVertices[patch->vUV2[1]].m_vecTexCoord;
  t1[1].y = v15;
  t1[2].x = v16->x;
  v17 = v16->y;
  v18 = &pVertices[patch->vUV3[1]].m_vecTexCoord;
  t1[2].y = v17;
  t1[3].x = v18->x;
  v19 = v18->y;
  v20 = &pVertices[patch->vUV0[2]].m_vecTexCoord;
  t1[3].y = v19;
  t2[0].x = v20->x;
  v21 = v20->y;
  v22 = patch->vUV1[2];
  t2[0].y = v21;
  v23 = &pVertices[v22].m_vecTexCoord;
  t2[1].x = v23->x;
  v24 = v23->y;
  v25 = &pVertices[patch->vUV2[2]].m_vecTexCoord;
  t2[1].y = v24;
  t2[2].x = v25->x;
  v26 = v25->y;
  v27 = &pVertices[patch->vUV3[2]].m_vecTexCoord;
  t2[2].y = v26;
  t2[3].x = v27->x;
  v28 = v27->y;
  v29 = &pVertices[patch->vUV0[3]].m_vecTexCoord;
  t2[3].y = v28;
  t3[0].x = v29->x;
  v30 = v29->y;
  v31 = patch->vUV1[3];
  t3[0].y = v30;
  t3[1].x = pVertices[v31].m_vecTexCoord.x;
  v32 = pVertices[v31].m_vecTexCoord.y;
  v33 = patch->vUV3[3];
  v34 = patch->vUV2[3];
  t3[1].y = v32;
  t3[2] = pVertices[v34].m_vecTexCoord;
  t3[3] = pVertices[v33].m_vecTexCoord;
  v35 = (UV.y < 0.0099999998) + 2 * (UV.x < 0.0099999998);
  v36 = (UV.x > 0.99000001) + 2 * (UV.y < 0.0099999998);
  v37 = (UV.y > 0.99000001) + 2 * (UV.x > 0.99000001);
  v38 = &t0[v35];
  v39 = (float)((float)(t1[v36].x - v38->x) * UV.x) + v38->x;
  v40 = (float)((float)(t1[v36].y - t0[v35].y) * UV.x) + v38->y;
  v41 = (UV.x < 0.0099999998) + 2 * (UV.y > 0.99000001);
  v42 = t2[v37].x - t3[v41].x;
  v43 = t2[v37].y - t3[v41].y;
  v44 = &t3[v41];
  v45 = (float)(v43 * UV.x) + v44->y;
  result->x = (float)((float)((float)((float)(v42 * UV.x) + v44->x) - v39) * UV.y) + v39;
  result->y = (float)((float)(v45 - v40) * UV.y) + v40;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004180A0
// Name: public: static bool CSuggestGameDirHelper::SuggestFn(class CFSSteamSetupInfo const __near *,char __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CSuggestGameDirHelper::SuggestFn(
        const CFSSteamSetupInfo *pFsSteamSetupInfo,
        char *pchPathBuffer,
        int nBufferLength,
        bool *pbBubbleDirectories)
{
  if ( g_suggestGameDirHelper.m_pszInputFile == nullptr )
    return 0;
  if ( pbBubbleDirectories != nullptr )
    *pbBubbleDirectories = true;
  V_MakeAbsolutePath(
    pOut: pchPathBuffer,
    outLen: nBufferLength,
    pPath: g_suggestGameDirHelper.m_pszInputFile,
    pStartingDir: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004180E0
// Name: public: virtual void CRayTraceNearCageJob::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRayTraceNearCageJob::Execute(
        CRayTraceNearCageJob *this@<ecx>,
        unsigned int a2@<ebp>,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  unsigned int v4; // eax
  int v5; // ecx
  unsigned __int8 *v6; // eax
  float z; // edi
  float y; // eax
  bool v9; // zf
  char *v10; // edi
  unsigned int v11; // ecx
  float m_flTraceBias; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  RayTracingEnvironment *m_pRTE; // ecx
  float m_flTraceLength; // xmm1_4
  float *v18; // ecx
  float x; // xmm0_4
  unsigned int v20; // ecx
  float **v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // edi
  float **v24; // eax
  unsigned int v25; // [esp+8h] [ebp-414h]
  _BYTE v26[12]; // [esp+20h] [ebp-3FCh] BYREF
  RayStream ray_trace_stream_ctx; // [esp+2Ch] [ebp-3F0h] BYREF
  float v28; // [esp+3CCh] [ebp-50h]
  Vector vRayEnd; // [esp+3D0h] [ebp-4Ch] BYREF
  Vector vACCPos; // [esp+3DCh] [ebp-40h] BYREF
  Vector vRayStart; // [esp+3E8h] [ebp-34h] BYREF
  Vector vACCNorm; // [esp+3F4h] [ebp-28h]
  unsigned int u; // [esp+400h] [ebp-1Ch]
  unsigned int iRowStart; // [esp+404h] [ebp-18h]
  unsigned int NumResults; // [esp+408h] [ebp-14h]
  char *v36; // [esp+40Ch] [ebp-10h]
  unsigned int r; // [esp+410h] [ebp-Ch]
  void *v38; // [esp+414h] [ebp-8h]
  void *retaddr; // [esp+41Ch] [ebp+0h]

  r = a2;
  v38 = retaddr;
  v4 = 52 * this->m_RectSizeU * this->m_RectSizeV;
  v5 = (52 * (unsigned __int64)(this->m_RectSizeU * this->m_RectSizeV)) >> 32 != 0;
  memset(&ray_trace_stream_ctx.PendingStreamOutputs[7][1], 0, 32);
  v6 = (unsigned __int8 *)operator new(nSize: v4 | -v5);
  v25 = 52 * this->m_RectSizeU * this->m_RectSizeV;
  z = 0.0;
  v36 = (char *)v6;
  vACCNorm.z = 0.0;
  memset(dst: v6, value: 0, count: v25);
  y = 0.0;
  vACCNorm.y = 0.0;
  for ( iRowStart = 0; iRowStart < this->m_RectSizeV; ++iRowStart )
  {
    v9 = this->m_RectSizeU == 0;
    vACCNorm.x = 0.0;
    if ( !v9 )
    {
      NumResults = 4 * LODWORD(y);
      u = 8 * LODWORD(y);
      v10 = &v36[52 * LODWORD(z) + 36];
      do
      {
        v11 = this->m_pPatchIDStart[NumResults / 4];
        if ( v11 != 0 )
        {
          CSubDMesh::EvalulateACCPatchAtUV(
            this: this->m_pSubDMesh,
            iPatchID: v11 - 1,
            U: this->m_pPatchUVStart[u / 8].x,
            V: this->m_pPatchUVStart[u / 8].y,
            pOutPosition: &vRayEnd,
            pOutNormal: &vRayStart);
          m_flTraceBias = this->m_flTraceBias;
          v13 = vRayEnd.y + (float)(m_flTraceBias * vRayStart.y);
          v14 = (float)(vRayStart.x * m_flTraceBias) + vRayEnd.x;
          v15 = vRayEnd.z + (float)(vRayStart.z * m_flTraceBias);
          m_pRTE = this->m_pRTE;
          m_flTraceLength = this->m_flTraceLength;
          vACCPos.x = v14;
          vACCPos.y = v13;
          vACCPos.z = v15;
          ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[2] = (float)(vRayStart.x * m_flTraceLength) + v14;
          ray_trace_stream_ctx.PendingRays[7].direction.z.m128_f32[3] = (float)(m_flTraceLength * vRayStart.y) + v13;
          v28 = (float)(vRayStart.z * m_flTraceLength) + v15;
          RayTracingEnvironment::AddToRayStream(
            this: m_pRTE,
            s: (RayStream *)v26,
            start: &vACCPos,
            end: (const Vector *)&ray_trace_stream_ctx.PendingRays[7].direction.z.m128_u16[4],
            rslt_out: (RayTracingSingleResult *)(v10 - 36),
            cullMode: RTE_CULL_FRONT);
          v18 = &this->m_pDistanceOutputStart[NumResults / 4];
          x = vACCPos.x;
          ++LODWORD(vACCNorm.z);
          y = vACCNorm.y;
          *((_DWORD *)v10 - 3) = v18;
          *((float *)v10 - 2) = x;
          *((_DWORD *)v10 - 1) = LODWORD(vACCPos.y);
          *(float *)v10 = vACCPos.z;
          *(Vector *)(v10 + 4) = vRayStart;
          v10 += 52;
        }
        u += 8;
        NumResults += 4;
        ++LODWORD(vACCNorm.x);
      }
      while ( LODWORD(vACCNorm.x) < this->m_RectSizeU );
      z = vACCNorm.z;
    }
    LODWORD(y) += this->m_PatchPitch;
    vACCNorm.y = y;
  }
  RayTracingEnvironment::FinishRayStream(this: this->m_pRTE, s: (RayStream *)v26, cullMode: RTE_CULL_NONE);
  v20 = 0;
  if ( SLODWORD(z) >= 4 )
  {
    v21 = (float **)(v36 + 16);
    v22 = ((unsigned int)(LODWORD(z) - 4) >> 2) + 1;
    iRowStart = 4 * v22;
    do
    {
      if ( (int)*(v21 - 1) > -1 )
        *v21[2] = this->m_flTraceBias + *(float *)v21;
      if ( (int)v21[12] > -1 )
        *v21[15] = *((float *)v21 + 13) + this->m_flTraceBias;
      if ( (int)v21[25] > -1 )
        *v21[28] = *((float *)v21 + 26) + this->m_flTraceBias;
      if ( (int)v21[38] > -1 )
        *v21[41] = *((float *)v21 + 39) + this->m_flTraceBias;
      v21 += 52;
      --v22;
    }
    while ( v22 != 0 );
    v20 = iRowStart;
  }
  if ( v20 < LODWORD(z) )
  {
    v23 = LODWORD(z) - v20;
    v24 = (float **)&v36[52 * v20 + 16];
    do
    {
      if ( (int)*(v24 - 1) > -1 )
        *v24[2] = this->m_flTraceBias + *(float *)v24;
      v24 += 13;
      --v23;
    }
    while ( v23 != 0 );
  }
  free(pMem: v36);
}

//------------------------------------------------------------------------------
// Address: 0x004183E0
// Name: public: virtual void COutputDetailOBJJob::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutputDetailOBJJob::Execute(
        COutputDetailOBJJob *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  _iobuf *v3; // eax
  CSubDMesh *m_pSubDMesh; // eax
  int m_Size; // ecx
  int m_NumPreTessIndices; // edi
  int m_NumPreTessVertices; // edx
  mstudiovertex_t *m_pStudioVertices; // eax
  int v9; // esi
  bool v10; // zf
  int v11; // edi
  int *v12; // eax
  int v13; // edx
  CSubDMesh *v14; // eax
  mstudiovertex_t *v15; // ecx
  float x; // xmm4_4
  float y; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  int v24; // eax
  float *v25; // esi
  CSubDMesh *v26; // ecx
  PreTessPatchVertex_t *m_pPreTessPatchVertices; // edx
  int v28; // eax
  float v29; // xmm1_4
  CTileBuffers *m_pTileBuffers; // eax
  float v31; // xmm0_4
  float v32; // xmm1_4
  int v33; // ecx
  int m_Width; // esi
  int v35; // ecx
  int v36; // edi
  int v37; // ecx
  int v38; // edx
  float z; // xmm2_4
  float v40; // xmm5_4
  float v41; // xmm7_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  float v44; // xmm6_4
  int m_Height; // ecx
  int v46; // esi
  int v47; // ecx
  int v48; // edi
  int v49; // ecx
  int v50; // edx
  unsigned __int8 *v51; // eax
  float v52; // xmm0_4
  int v53; // edx
  int v54; // ecx
  float *v55; // eax
  float v56; // xmm0_4
  float v57; // xmm0_4
  float *v58; // esi
  int j; // edi
  float *v60; // esi
  int k; // edi
  float *v62; // esi
  int m; // edi
  int *v64; // esi
  RayTracingEnvironment *m_prteDetail; // ecx
  int v66; // edi
  int *v67; // esi
  int v68; // edi
  float U[2]; // [esp+8h] [ebp-30Ch] BYREF
  OptimizedModel::SubD_Face_t patch; // [esp+24h] [ebp-2F0h] BYREF
  mstudiovertex_t verts[4]; // [esp+150h] [ebp-1C4h]
  PreTessPatchVertex_t vert; // [esp+210h] [ebp-104h]
  char szOut[100]; // [esp+238h] [ebp-DCh] BYREF
  float v74; // [esp+29Ch] [ebp-78h]
  float v75; // [esp+2A0h] [ebp-74h]
  float v76; // [esp+2A4h] [ebp-70h]
  float v77; // [esp+2A8h] [ebp-6Ch]
  mstudiovertex_t *pStudioVertices; // [esp+2ACh] [ebp-68h]
  Vector2D DispUV; // [esp+2B0h] [ebp-64h] BYREF
  Vector2D UV; // [esp+2B8h] [ebp-5Ch]
  int NumPatchIndices; // [esp+2C0h] [ebp-54h]
  int i; // [esp+2C4h] [ebp-50h]
  Vector vNormal; // [esp+2C8h] [ebp-4Ch] BYREF
  int v84; // [esp+2D4h] [ebp-40h]
  float *v85; // [esp+2D8h] [ebp-3Ch]
  unsigned int v86; // [esp+2DCh] [ebp-38h]
  int v87; // [esp+2E0h] [ebp-34h]
  int p; // [esp+2E4h] [ebp-30h]
  Vector vColor; // [esp+2E8h] [ebp-2Ch] BYREF
  int v90; // [esp+2F4h] [ebp-20h]
  int *pIndices; // [esp+2F8h] [ebp-1Ch]
  int NumVertices; // [esp+2FCh] [ebp-18h]
  _iobuf *fp; // [esp+300h] [ebp-14h]
  int NumPatches; // [esp+304h] [ebp-10h]
  void *pMem; // [esp+308h] [ebp-Ch]
  int NumIndices; // [esp+30Ch] [ebp-8h]
  bool bOutputFile; // [esp+313h] [ebp-1h]

  bOutputFile = this->m_szFileName[0] != 0;
  fp = nullptr;
  if ( bOutputFile )
  {
    v3 = fopen(file: this->m_szFileName, mode: "wb");
    fp = v3;
    if ( v3 == nullptr )
      return;
    fwrite(buffer: "o object1\n", size: 0xAu, count: 1u, stream: v3);
  }
  m_pSubDMesh = this->m_pSubDMesh;
  m_Size = m_pSubDMesh->m_SubDPatches.m_Size;
  m_NumPreTessIndices = m_pSubDMesh->m_NumPreTessIndices;
  m_NumPreTessVertices = m_pSubDMesh->m_NumPreTessVertices;
  m_pStudioVertices = m_pSubDMesh->m_pStudioVertices;
  v9 = m_NumPreTessIndices * m_Size;
  v10 = !this->m_bRemoveRedundancies;
  NumPatchIndices = m_NumPreTessIndices;
  NumPatches = m_Size;
  pStudioVertices = m_pStudioVertices;
  v11 = m_NumPreTessIndices * m_Size;
  if ( !v10 )
    v11 = m_NumPreTessVertices * m_Size;
  pMem = operator new(nSize: 32 * v11);
  if ( pMem != nullptr )
  {
    v12 = (int *)operator new(nSize: 4 * v9);
    v13 = 0;
    pIndices = v12;
    if ( v12 != nullptr )
    {
      NumVertices = 0;
      NumIndices = 0;
      p = 0;
      if ( NumPatches > 0 )
      {
        v86 = 0;
        do
        {
          v14 = this->m_pSubDMesh;
          patch = v14->m_SubDPatches.m_Memory.m_pMemory[v86 / 0x12C];
          v15 = v14->m_pStudioVertices;
          x = v15[patch.vtxIDs[0]].m_vecTexCoord.x;
          y = v15[patch.vtxIDs[0]].m_vecTexCoord.y;
          v18 = v15[patch.vtxIDs[1]].m_vecTexCoord.x;
          v19 = v15[patch.vtxIDs[1]].m_vecTexCoord.y;
          v20 = v15[patch.vtxIDs[2]].m_vecTexCoord.x;
          v21 = v15[patch.vtxIDs[2]].m_vecTexCoord.y;
          v22 = v15[patch.vtxIDs[3]].m_vecTexCoord.x;
          v23 = v15[patch.vtxIDs[3]].m_vecTexCoord.y;
          v24 = 0;
          verts[0].m_vecTexCoord.x = x;
          verts[0].m_vecTexCoord.y = y;
          verts[3].m_vecTexCoord.x = v22;
          verts[3].m_vecTexCoord.y = v23;
          i = 0;
          if ( NumPatchIndices > 0 )
          {
            v25 = (float *)((char *)pMem + 32 * v13 + 20);
            v74 = v18 - x;
            v75 = v19 - y;
            v76 = v20 - v22;
            v77 = v21 - v23;
            v85 = v25;
            do
            {
              v26 = this->m_pSubDMesh;
              m_pPreTessPatchVertices = v26->m_pPreTessPatchVertices;
              v28 = v26->m_pPreTessPatchIndices[v24];
              v29 = m_pPreTessPatchVertices[v28].m_UV.y;
              vert.m_UV.x = m_pPreTessPatchVertices[v28].m_UV.x;
              vert.m_UV.y = v29;
              CSubDMesh::EvalulateACCPatchAtUV(
                this: v26,
                iPatchID: p,
                U: vert.m_UV.x,
                V: v29,
                pOutPosition: &vColor,
                pOutNormal: &vNormal);
              v90 = (int)U;
              UV.x = (float)((float)((float)((float)(v76 * vert.m_UV.x) + verts[3].m_vecTexCoord.x)
                                   - (float)((float)(v74 * vert.m_UV.x) + verts[0].m_vecTexCoord.x))
                           * vert.m_UV.y)
                   + (float)((float)(v74 * vert.m_UV.x) + verts[0].m_vecTexCoord.x);
              UV.y = (float)((float)((float)((float)(v77 * vert.m_UV.x) + verts[3].m_vecTexCoord.y)
                                   - (float)((float)(v75 * vert.m_UV.x) + verts[0].m_vecTexCoord.y))
                           * vert.m_UV.y)
                   + (float)((float)(v75 * vert.m_UV.x) + verts[0].m_vecTexCoord.y);
              ComputeConsistentDisplacementUVs(result: &DispUV, UV: vert.m_UV, &patch, pVertices: pStudioVertices);
              m_pTileBuffers = this->m_pTileBuffers;
              v31 = 1.0 - DispUV.y;
              DispUV.y = 1.0 - DispUV.y;
              if ( m_pTileBuffers != nullptr )
              {
                v33 = this->m_Height + 1;
                v84 = (int)(float)(this->m_fHeight * v31);
                m_Width = this->m_Width;
                v90 = (int)(float)(this->m_fWidth * DispUV.x);
                v35 = this->m_NumTilesU * (v84 / v33);
                v87 = m_Width + 1;
                v36 = v90 / (m_Width + 1) + v35;
                v37 = m_Width * (v84 % this->m_Height);
                v38 = v90 % m_Width;
                m_pTileBuffers = this->m_pTileBuffers;
                v25 = v85;
                v32 = m_pTileBuffers[v36].m_pDisplacementOutputBuffer[v38 + v37];
              }
              else
              {
                v32 = 0.0;
              }
              z = vNormal.z;
              v40 = vNormal.y * v32;
              v41 = vNormal.z * v32;
              v42 = (float)(vNormal.x * v32) + vColor.x;
              v43 = vColor.y + v40;
              v44 = vColor.z + v41;
              vColor.x = v42;
              vColor.y = vColor.y + v40;
              vColor.z = vColor.z + v41;
              if ( m_pTileBuffers != nullptr )
              {
                m_Height = this->m_Height;
                v84 = (int)(float)(this->m_fHeight * v31);
                v46 = this->m_Width;
                v87 = (int)(float)(this->m_fWidth * DispUV.x);
                v47 = this->m_NumTilesU * (v84 / (m_Height + 1));
                v90 = v46 + 1;
                v48 = v87 / (v46 + 1) + v47;
                v49 = v46 * (v84 % this->m_Height);
                v50 = v87 % v46;
                v25 = v85;
                v51 = &this->m_pTileBuffers[v48].m_pOSNormalMapBuffer[4 * v50 + 4 * v49];
                v52 = (float)((float)v51[2] * 0.0078125) - 1.0;
                z = (float)((float)*v51 * 0.0078125) - 1.0;
                vNormal.y = (float)((float)v51[1] * 0.0078125) - 1.0;
                v42 = vColor.x;
                vNormal.x = v52;
                vNormal.z = z;
              }
              v53 = NumVertices;
              if ( !this->m_bRemoveRedundancies )
                goto LABEL_29;
              v54 = 0;
              if ( NumVertices <= 0 )
                goto LABEL_29;
              v55 = (float *)((char *)pMem + 8);
              while ( fabs(*(v55 - 2) - v42) > 0.001
                   || fabs(*(v55 - 1) - v43) > 0.001
                   || fabs(*v55 - v44) > 0.001
                   || fabs(v55[1] - vNormal.x) > 0.001
                   || fabs(v55[2] - vNormal.y) > 0.001
                   || fabs(v55[3] - z) > 0.001
                   || fabs(v55[4] - UV.x) > 0.001
                   || fabs(v55[5] - UV.y) > 0.001 )
              {
                ++v54;
                v55 += 8;
                if ( v54 >= NumVertices )
                  goto LABEL_29;
              }
              if ( v54 > -1 )
              {
                pIndices[NumIndices] = v54;
              }
              else
              {
LABEL_29:
                v56 = vNormal.x;
                pIndices[NumIndices] = NumVertices;
                *(v25 - 5) = v42;
                *(v25 - 4) = v43;
                *(v25 - 3) = v44;
                *(v25 - 2) = v56;
                *(v25 - 1) = vNormal.y;
                v57 = UV.x;
                *v25 = z;
                v25[1] = v57;
                v25[2] = UV.y;
                v25 += 8;
                NumVertices = v53 + 1;
                v85 = v25;
              }
              ++NumIndices;
              v24 = i + 1;
              i = v24;
            }
            while ( v24 < NumPatchIndices );
            v13 = NumVertices;
          }
          v86 += 300;
          ++p;
        }
        while ( p < NumPatches );
      }
      if ( bOutputFile )
      {
        if ( v13 > 0 )
        {
          v58 = (float *)((char *)pMem + 4);
          for ( j = v13; j != 0; --j )
          {
            sprintf_s(string: szOut, sizeInBytes: 0x64u, format: "v %.8f %.8f %.8f\n", *(v58 - 1), *v58, v58[1]);
            fwrite(buffer: szOut, size: strlen(szOut), count: 1u, stream: fp);
            v58 += 8;
          }
          if ( NumVertices > 0 )
          {
            v60 = (float *)((char *)pMem + 24);
            for ( k = NumVertices; k != 0; --k )
            {
              sprintf_s(string: szOut, sizeInBytes: 0x64u, format: "vt %.8f %.8f\n", *v60, v60[1]);
              fwrite(buffer: szOut, size: strlen(szOut), count: 1u, stream: fp);
              v60 += 8;
            }
            if ( NumVertices > 0 )
            {
              v62 = (float *)((char *)pMem + 16);
              for ( m = NumVertices; m != 0; --m )
              {
                sprintf_s(string: szOut, sizeInBytes: 0x64u, format: "vn %.8f %.8f %.8f\n", *(v62 - 1), *v62, v62[1]);
                fwrite(buffer: szOut, size: strlen(szOut), count: 1u, stream: fp);
                v62 += 8;
              }
            }
          }
        }
        if ( NumIndices > 0 )
        {
          v64 = pIndices + 2;
          NumPatches = ((unsigned int)(NumIndices - 1) >> 2) + 1;
          do
          {
            sprintf_s(
              string: szOut,
              sizeInBytes: 0x64u,
              format: "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",
              *(v64 - 2) + 1,
              *(v64 - 2) + 1,
              *(v64 - 2) + 1,
              *(v64 - 1) + 1,
              *(v64 - 1) + 1,
              *(v64 - 1) + 1,
              *v64 + 1,
              *v64 + 1,
              *v64 + 1,
              v64[1] + 1,
              v64[1] + 1,
              v64[1] + 1);
            fwrite(buffer: szOut, size: strlen(szOut), count: 1u, stream: fp);
            v64 += 4;
            --NumPatches;
          }
          while ( NumPatches != 0 );
        }
      }
      m_prteDetail = this->m_prteDetail;
      if ( m_prteDetail != nullptr )
      {
        RayTracingEnvironment::MakeRoomForTriangles(this: m_prteDetail, ntris: NumIndices / 2);
        v66 = 0;
        memset(&vColor, 0, sizeof(vColor));
        if ( NumIndices > 0 )
        {
          v67 = pIndices + 2;
          NumPatches = ((unsigned int)(NumIndices - 1) >> 2) + 1;
          do
          {
            RayTracingEnvironment::AddTriangle(
              this: this->m_prteDetail,
              id: v66,
              v1: (const Vector *)((char *)pMem + 32 * *(v67 - 2)),
              v2: (const Vector *)((char *)pMem + 32 * *(v67 - 1)),
              v3: (const Vector *)((char *)pMem + 32 * *v67),
              color: &vColor);
            v68 = v66 + 1;
            RayTracingEnvironment::AddTriangle(
              this: this->m_prteDetail,
              id: v68,
              v1: (const Vector *)((char *)pMem + 32 * *(v67 - 2)),
              v2: (const Vector *)((char *)pMem + 32 * *v67),
              v3: (const Vector *)((char *)pMem + 32 * v67[1]),
              color: &vColor);
            v66 = v68 + 1;
            v67 += 4;
            --NumPatches;
          }
          while ( NumPatches != 0 );
        }
      }
      free(pMem);
      free(pMem: pIndices);
      if ( bOutputFile )
        fclose(stream: fp);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418C70
// Name: public: CPlainAutoPtr<class CP4File>::~CPlainAutoPtr<class CP4File>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(CP4AutoAddFile *this)
{
  CP4File *m_p; // ecx

  m_p = this->m_spImpl.m_p;
  this->m_spImpl.m_p = nullptr;
  if ( m_p != nullptr )
    ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00418C90
// Name: public: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::Init(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nGrowSize,
        int nInitSize)
{
  int i; // edi
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // eax
  CacheOptimizedTriangle **m_pMemory; // [esp-8h] [ebp-Ch]

  if ( this->m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_nBlocks; ++i )
      free(pMem: this->m_pMemory[i]);
    m_pMemory = this->m_pMemory;
    this->m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_pMemory = nullptr;
  }
  v5 = nGrowSize;
  if ( nGrowSize == 0 )
    v5 = 3;
  v6 = ((((unsigned int)(v5 - 1) >> 1) | (v5 - 1)) >> 2) | ((unsigned int)(v5 - 1) >> 1) | (v5 - 1);
  v7 = (v6 >> 4) | v6;
  v8 = ((v7 >> 8) | v7 | (((v7 >> 8) | v7) >> 16)) + 1;
  v9 = (v7 >> 8) | v7 & 0x7FFFFFF | (((v7 >> 8) | v7) >> 16);
  *((_DWORD *)this + 2) = v9;
  if ( v8 > 1 )
  {
    do
    {
      v8 >>= 1;
      v9 = ((v9 & 0xF8000000) + 0x8000000) ^ v9 & 0x7FFFFFF;
    }
    while ( v8 > 1 );
    *((_DWORD *)this + 2) = v9;
  }
  if ( nInitSize > 0 )
    CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
      this,
      nBlocks: this->m_nBlocks + (((32 * *((_DWORD *)this + 2)) >> 5) + nInitSize) / (((32 * *((_DWORD *)this + 2)) >> 5) + 1));
}

//------------------------------------------------------------------------------
// Address: 0x00418D60
// Name: public: virtual void CUByte4TextureOutput::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUByte4TextureOutput::Execute(
        CUByte4TextureOutput *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  int v2; // ebx
  IDirect3DDevice9 *m_pDevice; // eax
  int m_Width; // edx
  unsigned __int8 *pBits; // edi
  CP4File *v7; // esi
  bool (__thiscall *Add)(CP4File *); // eax
  void (__thiscall *dtr_CP4File)(CP4File *); // eax
  int m_Height; // [esp-1Ch] [ebp-40h]
  _D3DLOCKED_RECT rect; // [esp+8h] [ebp-1Ch] BYREF
  CP4AutoAddFile autop4; // [esp+10h] [ebp-14h]
  IDirect3DTexture9 *pTexture; // [esp+14h] [ebp-10h] BYREF
  int v14; // [esp+20h] [ebp-4h]

  v2 = 0;
  m_pDevice = this->m_pDevice;
  m_Height = this->m_Height;
  m_Width = this->m_Width;
  pTexture = nullptr;
  if ( m_pDevice->CreateTexture(
         this: m_pDevice,
         a2: m_Width,
         a3: m_Height,
         a4: 1u,
         a5: 0,
         a6: D3DFMT_A8R8G8B8,
         a7: D3DPOOL_SYSTEMMEM,
         a8: &pTexture,
         a9: nullptr) >= 0
    && pTexture->LockRect(this: pTexture, a2: 0, a3: &rect, a4: nullptr, a5: 0) >= 0 )
  {
    pBits = (unsigned __int8 *)rect.pBits;
    if ( this->m_Height > 0 )
    {
      do
      {
        memcpy(dst: pBits, src: &this->m_pBits[4 * v2 * this->m_Width], count: 4 * this->m_Width);
        pBits += rect.Pitch;
        ++v2;
      }
      while ( v2 < this->m_Height );
    }
    pTexture->UnlockRect(this: pTexture, a2: 0);
    D3DXSaveTextureToFileA(a1: this->m_szFileName, a2: this->m_FileFormat, a3: (int)pTexture, a4: nullptr);
    v7 = CP4Factory::AccessFile(this: g_p4factory, szFilename: this->m_szFileName);
    autop4.m_spImpl.m_p = v7;
    Add = v7->Add;
    v14 = 0;
    Add(this: v7);
    dtr_CP4File = v7->dtr_CP4File;
    v14 = -1;
    ((void (__thiscall *)(CP4File *, int))dtr_CP4File)(a1: v7, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418E60
// Name: public: virtual void CUByteFromFloatTextureOutput::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUByteFromFloatTextureOutput::Execute(
        CUByteFromFloatTextureOutput *this,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  int v2; // ebx
  IDirect3DDevice9 *m_pDevice; // eax
  int m_Width; // edx
  _BYTE *pBits; // edi
  int v7; // ecx
  float *v8; // edx
  int i; // eax
  CP4File *v10; // esi
  bool (__thiscall *Add)(CP4File *); // edx
  void (__thiscall *dtr_CP4File)(CP4File *); // edx
  int m_Height; // [esp-1Ch] [ebp-40h]
  _D3DLOCKED_RECT rect; // [esp+8h] [ebp-1Ch] BYREF
  CP4AutoAddFile autop4; // [esp+10h] [ebp-14h]
  IDirect3DTexture9 *pTexture; // [esp+14h] [ebp-10h] BYREF
  int v17; // [esp+20h] [ebp-4h]

  v2 = 0;
  m_pDevice = this->m_pDevice;
  m_Height = this->m_Height;
  m_Width = this->m_Width;
  pTexture = nullptr;
  if ( m_pDevice->CreateTexture(
         this: m_pDevice,
         a2: m_Width,
         a3: m_Height,
         a4: 1u,
         a5: 0,
         a6: D3DFMT_L8,
         a7: D3DPOOL_SYSTEMMEM,
         a8: &pTexture,
         a9: nullptr) >= 0
    && pTexture->LockRect(this: pTexture, a2: 0, a3: &rect, a4: nullptr, a5: 0) >= 0 )
  {
    pBits = rect.pBits;
    if ( this->m_Height > 0 )
    {
      v7 = this->m_Width;
      do
      {
        v8 = &this->m_pBits[v2 * v7];
        for ( i = 0; i < v7; ++i )
        {
          pBits[i] = (int)(float)(v8[i] * 255.0);
          v7 = this->m_Width;
        }
        pBits += rect.Pitch;
        ++v2;
      }
      while ( v2 < this->m_Height );
    }
    pTexture->UnlockRect(this: pTexture, a2: 0);
    D3DXSaveTextureToFileA(a1: this->m_szFileName, a2: this->m_FileFormat, a3: (int)pTexture, a4: nullptr);
    v10 = CP4Factory::AccessFile(this: g_p4factory, szFilename: this->m_szFileName);
    autop4.m_spImpl.m_p = v10;
    Add = v10->Add;
    v17 = 0;
    Add(this: v10);
    dtr_CP4File = v10->dtr_CP4File;
    v17 = -1;
    ((void (__thiscall *)(CP4File *, int))dtr_CP4File)(a1: v10, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418F80
// Name: public: virtual void CFloatTextureOutput::Execute(class CUtlVector<class IScheduleObject __near *,class CUtlMemory<class IScheduleObject __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFloatTextureOutput::Execute(
        CFloatTextureOutput *this@<ecx>,
        int a2@<edi>,
        CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *pDependencyArray)
{
  IDirect3DDevice9 *m_pDevice; // eax
  int m_Width; // edx
  float v6; // xmm2_4
  float v7; // xmm1_4
  int v8; // edx
  char *pBits; // edi
  int v10; // eax
  int i; // ecx
  float *m_pBits; // ebx
  int v13; // eax
  float v14; // xmm0_4
  CP4File *v15; // esi
  bool (__thiscall *Add)(CP4File *); // eax
  void (__thiscall *dtr_CP4File)(CP4File *); // eax
  int m_Height; // [esp+3Ch] [ebp-94h]
  char szOutputMessage[80]; // [esp+5Ch] [ebp-74h] BYREF
  _D3DLOCKED_RECT rect; // [esp+ACh] [ebp-24h] BYREF
  CP4AutoAddFile autop4; // [esp+B4h] [ebp-1Ch]
  float flMin; // [esp+B8h] [ebp-18h]
  float flMax; // [esp+BCh] [ebp-14h]
  IDirect3DTexture9 *pFloatTexture; // [esp+C0h] [ebp-10h] BYREF
  int v26; // [esp+CCh] [ebp-4h]

  m_pDevice = this->m_pDevice;
  m_Height = this->m_Height;
  m_Width = this->m_Width;
  pFloatTexture = nullptr;
  if ( m_pDevice->CreateTexture(
         this: m_pDevice,
         a2: m_Width,
         a3: m_Height,
         a4: 1u,
         a5: 0,
         a6: D3DFMT_R32F,
         a7: D3DPOOL_SYSTEMMEM,
         a8: &pFloatTexture,
         a9: nullptr) >= 0
    && pFloatTexture->LockRect(this: pFloatTexture, a2: 0, a3: &rect, a4: nullptr, a5: 0) >= 0 )
  {
    v6 = 3.4028235e38;
    v7 = 1.1754944e-38;
    v8 = 0;
    pBits = (char *)rect.pBits;
    flMin = 3.4028235e38;
    flMax = 1.1754944e-38;
    if ( this->m_Height > 0 )
    {
      v10 = this->m_Width;
      do
      {
        for ( i = 0; i < v10; ++i )
        {
          m_pBits = this->m_pBits;
          v13 = i + v8 * v10;
          v14 = m_pBits[v13];
          if ( v6 > v14 )
            v6 = m_pBits[v13];
          if ( v14 > v7 )
            v7 = m_pBits[v13];
          *(float *)&pBits[v13 * 4] = v14;
          v10 = this->m_Width;
        }
        ++v8;
      }
      while ( v8 < this->m_Height );
      flMax = v7;
      flMin = v6;
    }
    ((void (__stdcall *)(IDirect3DTexture9 *, _DWORD, int))pFloatTexture->UnlockRect)(a1: pFloatTexture, a2: 0, a3: a2);
    D3DXSaveTextureToFileA(a1: this->m_szFileName, a2: this->m_FileFormat, a3: (int)pFloatTexture, a4: nullptr);
    v15 = CP4Factory::AccessFile(this: g_p4factory, szFilename: this->m_szFileName);
    autop4.m_spImpl.m_p = v15;
    Add = v15->Add;
    v26 = 0;
    Add(this: v15);
    dtr_CP4File = v15->dtr_CP4File;
    v26 = -1;
    ((void (__thiscall *)(CP4File *, int))dtr_CP4File)(a1: v15, a2: 1);
    V_snprintf(pDest: szOutputMessage, maxLen: 80, pFormat: "Displacement Range: (%g, %g)\n", flMin, flMax);
    printf(format: szOutputMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419170
// Name: public: RayTracingEnvironment::~RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::~RayTracingEnvironment(RayTracingEnvironment *this)
{
  int *m_pMemory; // eax
  Vector *v3; // eax
  LightDesc_t *v4; // eax
  int *v5; // eax
  CacheOptimizedKDNode *v6; // eax

  this->TriangleMaterials.m_Size = 0;
  if ( this->TriangleMaterials.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->TriangleMaterials.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->TriangleMaterials.m_Memory.m_pMemory);
      this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
    }
    this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->TriangleMaterials.m_Memory.m_pMemory;
  this->TriangleMaterials.m_pElements = m_pMemory;
  if ( this->TriangleMaterials.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
    }
    this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  }
  this->TriangleColors.m_Size = 0;
  if ( this->TriangleColors.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->TriangleColors.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->TriangleColors.m_Memory.m_pMemory);
      this->TriangleColors.m_Memory.m_pMemory = nullptr;
    }
    this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->TriangleColors.m_Memory.m_pMemory;
  this->TriangleColors.m_pElements = v3;
  if ( this->TriangleColors.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3 != nullptr )
    {
      free(pMem: v3);
      this->TriangleColors.m_Memory.m_pMemory = nullptr;
    }
    this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  }
  this->LightList.m_Size = 0;
  if ( this->LightList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->LightList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->LightList.m_Memory.m_pMemory);
      this->LightList.m_Memory.m_pMemory = nullptr;
    }
    this->LightList.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->LightList.m_Memory.m_pMemory;
  this->LightList.m_pElements = v4;
  if ( this->LightList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      free(pMem: v4);
      this->LightList.m_Memory.m_pMemory = nullptr;
    }
    this->LightList.m_Memory.m_nAllocationCount = 0;
  }
  this->TriangleIndexList.m_Size = 0;
  if ( this->TriangleIndexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->TriangleIndexList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->TriangleIndexList.m_Memory.m_pMemory);
      this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
    }
    this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->TriangleIndexList.m_Memory.m_pMemory;
  this->TriangleIndexList.m_pElements = v5;
  if ( this->TriangleIndexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      free(pMem: v5);
      this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
    }
    this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::~CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>(this: &this->OptimizedTriangleList);
  this->OptimizedKDTree.m_Size = 0;
  if ( this->OptimizedKDTree.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->OptimizedKDTree.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->OptimizedKDTree.m_Memory.m_pMemory);
      this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
    }
    this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->OptimizedKDTree.m_Memory.m_pMemory;
  this->OptimizedKDTree.m_pElements = v6;
  if ( this->OptimizedKDTree.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      free(pMem: v6);
      this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
    }
    this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419320
// Name: public: RayTracingEnvironment::RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
RayTracingEnvironment *__thiscall RayTracingEnvironment::RayTracingEnvironment(RayTracingEnvironment *this)
{
  CUtlBlockVector<CacheOptimizedTriangle> *p_OptimizedTriangleList; // ecx
  __m128 v3; // xmm1

  p_OptimizedTriangleList = &this->OptimizedTriangleList;
  this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  this->OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  this->OptimizedKDTree.m_Size = 0;
  this->OptimizedKDTree.m_pElements = nullptr;
  p_OptimizedTriangleList->m_Memory.m_pMemory = nullptr;
  p_OptimizedTriangleList->m_Memory.m_nBlocks = 0;
  *((_DWORD *)&p_OptimizedTriangleList->m_Memory + 2) = 0;
  CUtlBlockMemory<CacheOptimizedTriangle,int>::Init(
    this: &p_OptimizedTriangleList->m_Memory,
    nGrowSize: 1024,
    nInitSize: 0);
  this->OptimizedTriangleList.m_Size = 0;
  this->OptimizedTriangleList.m_pElements = nullptr;
  this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
  this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  this->TriangleIndexList.m_Memory.m_nGrowSize = 0;
  this->TriangleIndexList.m_Size = 0;
  this->TriangleIndexList.m_pElements = nullptr;
  this->LightList.m_Memory.m_pMemory = nullptr;
  this->LightList.m_Memory.m_nAllocationCount = 0;
  this->LightList.m_Memory.m_nGrowSize = 0;
  this->LightList.m_Size = 0;
  this->LightList.m_pElements = nullptr;
  this->TriangleColors.m_Memory.m_pMemory = nullptr;
  this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  this->TriangleColors.m_Memory.m_nGrowSize = 0;
  this->TriangleColors.m_Size = 0;
  this->TriangleColors.m_pElements = nullptr;
  this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
  this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  this->TriangleMaterials.m_Memory.m_nGrowSize = 0;
  this->TriangleMaterials.m_Size = 0;
  this->TriangleMaterials.m_pElements = nullptr;
  this->BackgroundColor.x = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v3 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  this->BackgroundColor.y = v3;
  this->BackgroundColor.z = v3;
  this->Flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00419400
// Name: bool CreateJobsForTile(struct IDirect3DDevice9 __near *,class ISchedulerThreadPool __near *,class CUniformSampler __near *,class CSubDMesh __near &,class CObjLoader __near &,class RayTracingEnvironment __near &,class RayTracingEnvironment __near &,float,class CTileBuffers __near &,int,int,struct SubDBakerArgs_t __near &,class std::vector<class IScheduleObject __near *,class std::allocator<class IScheduleObject __near *>> __near &,class IScheduleObject __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CreateJobsForTile@<al>(
        CacheEntry *a1@<edi>,
        IScheduleObject *a2@<esi>,
        IDirect3DDevice9 *pDevice,
        ISchedulerThreadPool *pThreadPool,
        CUniformSampler *pSampler,
        CSubDMesh *SubDMesh,
        CObjLoader *objDetailLoader,
        RayTracingEnvironment *rteCage,
        RayTracingEnvironment *rteDetail,
        float fDetailTraceLength,
        CTileBuffers *TileBuffers,
        int tu,
        int tv,
        SubDBakerArgs_t *CmdArgs,
        std::vector<CacheEntry *> *JobList,
        IScheduleObject *pFenceScheduleJob)
{
  int v16; // eax
  SubDBakerArgs_t *v17; // edi
  float *v18; // eax
  float *v20; // eax
  unsigned __int8 *v21; // eax
  CGutterFloatMap *v22; // eax
  CGutterFloatMap *v23; // eax
  CFloatTextureOutput *v24; // eax
  CFloatTextureOutput *v25; // eax
  float *v26; // eax
  CUByteFromFloatTextureOutput *v27; // eax
  CUByteFromFloatTextureOutput *v28; // eax
  unsigned __int8 *v29; // eax
  CUByte4TextureOutput *v30; // eax
  CUByte4TextureOutput *v31; // eax
  CUByte4TextureOutput *v32; // eax
  CUByte4TextureOutput *v33; // eax
  float *v34; // eax
  CUByteFromFloatTextureOutput *v35; // eax
  CUByteFromFloatTextureOutput *v36; // eax
  CCavityMap *v37; // eax
  CCavityMap *v38; // eax
  CJob *v39; // eax
  int m_TextureHeight; // ecx
  int v41; // eax
  unsigned int v42; // esi
  int m_JobRectSizeV; // eax
  float *v44; // eax
  float m_flTraceBias; // xmm0_4
  IScheduleObject **Mylast; // eax
  std::vector<CacheEntry *> *v47; // ecx
  signed int v48; // eax
  IScheduleObject *v49; // edx
  CacheEntry **v50; // eax
  float *v51; // ecx
  float v53; // xmm0_4
  unsigned int v54; // edi
  std::vector<unsigned int> *v55; // esi
  CObjLoader *v56; // eax
  IScheduleObject **v57; // eax
  std::vector<CacheEntry *> *v58; // ecx
  signed int v59; // eax
  IScheduleObject *v60; // edx
  CacheEntry **v61; // eax
  _DWORD *v62; // eax
  IScheduleObject **v63; // eax
  std::vector<CacheEntry *> *v64; // ecx
  signed int v65; // eax
  IScheduleObject *v66; // edx
  CacheEntry **v67; // eax
  float *v68; // eax
  float v69; // xmm0_4
  int v70; // eax
  std::vector<CacheEntry *> *v71; // ecx
  IScheduleObject **v72; // eax
  signed int v73; // eax
  IScheduleObject *v74; // edx
  CacheEntry **v75; // eax
  CacheEntry *v76; // [esp+20h] [ebp-ACh]
  IScheduleObject *v77; // [esp+24h] [ebp-A8h]
  IScheduleObject *v78; // [esp+28h] [ebp-A4h]
  float *v79; // [esp+2Ch] [ebp-A0h]
  __int64 v80; // [esp+44h] [ebp-88h]
  Vector4D *v81; // [esp+50h] [ebp-7Ch]
  unsigned __int8 *v82; // [esp+54h] [ebp-78h]
  signed int v83; // [esp+54h] [ebp-78h]
  unsigned __int8 *v84; // [esp+54h] [ebp-78h]
  signed int v85; // [esp+54h] [ebp-78h]
  int v86; // [esp+54h] [ebp-78h]
  signed int v87; // [esp+54h] [ebp-78h]
  float *v88; // [esp+58h] [ebp-74h]
  int m_TextureWidth; // [esp+58h] [ebp-74h]
  float *v90; // [esp+58h] [ebp-74h]
  Vector4D *pTanUs; // [esp+5Ch] [ebp-70h]
  Vector4D *pTanUsa; // [esp+5Ch] [ebp-70h]
  Vector4D *pTanUsb; // [esp+5Ch] [ebp-70h]
  unsigned int pOSNormalMapBuffer; // [esp+60h] [ebp-6Ch]
  IScheduleObject **pOSNormalMapBuffera; // [esp+60h] [ebp-6Ch]
  float v96; // [esp+64h] [ebp-68h]
  int v97; // [esp+68h] [ebp-64h]
  IScheduleObject **ppAOJob; // [esp+6Ch] [ebp-60h]
  int fCageTraceLengtha; // [esp+70h] [ebp-5Ch]
  int fCageTraceLength; // [esp+70h] [ebp-5Ch]
  CacheEntry **NumJobsV; // [esp+74h] [ebp-58h]
  int NumJobsVa; // [esp+74h] [ebp-58h]
  CacheEntry **NumJobsU; // [esp+78h] [ebp-54h]
  int NumJobsUa; // [esp+78h] [ebp-54h]
  CacheEntry **StartIndex; // [esp+7Ch] [ebp-50h]
  unsigned int *jv; // [esp+80h] [ebp-4Ch]
  Vector2D *ju; // [esp+84h] [ebp-48h]
  CacheEntry **ppAOOutputJob; // [esp+88h] [ebp-44h]
  CacheEntry **pPatchIDs; // [esp+8Ch] [ebp-40h]
  CacheEntry **pPatchUVs; // [esp+90h] [ebp-3Ch]
  CacheEntry **ppTSOutputJob; // [esp+94h] [ebp-38h]
  IScheduleObject **ppTSOutputJoba; // [esp+94h] [ebp-38h]
  IScheduleObject **ppDispOutputJob; // [esp+98h] [ebp-34h]
  IScheduleObject **ppOSOutputJob; // [esp+9Ch] [ebp-30h]
  unsigned int RectSizeVb; // [esp+A0h] [ebp-2Ch]
  unsigned int RectSizeV; // [esp+A0h] [ebp-2Ch]
  float *RectSizeVc; // [esp+A0h] [ebp-2Ch]
  IScheduleObject **RectSizeVa; // [esp+A0h] [ebp-2Ch]
  float *RectSizeUc; // [esp+A4h] [ebp-28h]
  unsigned int RectSizeU; // [esp+A4h] [ebp-28h]
  IScheduleObject **RectSizeUa; // [esp+A4h] [ebp-28h]
  IScheduleObject **RectSizeUb; // [esp+A4h] [ebp-28h]
  IScheduleObject **ppCageJob; // [esp+A8h] [ebp-24h]
  char v124; // [esp+AFh] [ebp-1Dh]

  v77 = a2;
  v76 = a1;
  v80 = *(_QWORD *)&SubDMesh->m_vecMaxBounds.x;
  v16 = tu + tv * SubDMesh->m_NumTextureTilesU;
  ju = SubDMesh->m_ppPatchUVTextureTile[v16];
  v96 = fsqrt(
          (float)((float)((float)(*((float *)&v80 + 1) - SubDMesh->m_vecMinBounds.y)
                        * (float)(*((float *)&v80 + 1) - SubDMesh->m_vecMinBounds.y))
                + (float)((float)(SubDMesh->m_vecMaxBounds.z - SubDMesh->m_vecMinBounds.z)
                        * (float)(SubDMesh->m_vecMaxBounds.z - SubDMesh->m_vecMinBounds.z)))
        + (float)((float)(*(float *)&v80 - SubDMesh->m_vecMinBounds.x)
                * (float)(*(float *)&v80 - SubDMesh->m_vecMinBounds.x)))
      * 1.5;
  v17 = CmdArgs;
  jv = SubDMesh->m_ppPatchIDTextureTile[v16];
  v81 = SubDMesh->m_ppPatchTanUTextureTile[v16];
  ppAOJob = (IScheduleObject **)(int)ceil(X: (float)((float)CmdArgs->m_TextureWidth / (float)CmdArgs->m_JobRectSizeU));
  v97 = (int)ceil(X: (float)((float)v17->m_TextureHeight / (float)v17->m_JobRectSizeV));
  ppCageJob = nullptr;
  pPatchIDs = nullptr;
  StartIndex = nullptr;
  ppAOOutputJob = nullptr;
  pPatchUVs = nullptr;
  if ( CmdArgs->m_bGenerateDisplacementMap
    || CmdArgs->m_bGenerateAmbientOcclusion
    || CmdArgs->m_bGenerateTSNormalMap
    || CmdArgs->m_bGenerateOSNormalMap
    || CmdArgs->m_bGenerateCavityMap )
  {
    v124 = 1;
    v18 = (float *)operator new(nSize: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    TileBuffers->m_pNearCageDistanceBuffers = v18;
    if ( v18 == nullptr )
      return 0;
    memset(dst: (unsigned __int8 *)v18, value: 0, count: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    v20 = (float *)operator new(nSize: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    TileBuffers->m_pDisplacementOutputBuffer = v20;
    if ( v20 == nullptr )
      return 0;
    memset(dst: (unsigned __int8 *)v20, value: 0, count: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    v21 = (unsigned __int8 *)operator new(nSize: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    TileBuffers->m_pOSNormalMapBuffer = v21;
    if ( v21 == nullptr )
      return 0;
    memset(dst: v21, value: 0, count: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    ppCageJob = (IScheduleObject **)operator new(nSize: 4u);
    v22 = (CGutterFloatMap *)operator new(nSize: 0x20u);
    if ( v22 != nullptr )
      v23 = CGutterFloatMap::CGutterFloatMap(
              this: v22,
              pInputHeightBits: TileBuffers->m_pDisplacementOutputBuffer,
              Width: CmdArgs->m_TextureWidth,
              Height: CmdArgs->m_TextureHeight,
              GutterSize: 1,
              fThreshold: 0.5);
    else
      v23 = nullptr;
    *ppCageJob = pThreadPool->CreateScheduleJob(this: pThreadPool, a2: v23);
    if ( CmdArgs->m_bGenerateDisplacementMap )
    {
      pPatchIDs = (CacheEntry **)operator new(nSize: 4u);
      v24 = (CFloatTextureOutput *)operator new(nSize: 0x120u);
      if ( v24 != nullptr )
        v25 = CFloatTextureOutput::CFloatTextureOutput(
                this: v24,
                pDevice,
                pBits: TileBuffers->m_pDisplacementOutputBuffer,
                Width: CmdArgs->m_TextureWidth,
                Height: CmdArgs->m_TextureHeight,
                fileFormat: CmdArgs->m_DispFileFormat,
                pszFileName: CmdArgs->m_szDispMapOutputFile);
      else
        v25 = nullptr;
      *pPatchIDs = (CacheEntry *)pThreadPool->CreateScheduleJob(this: pThreadPool, a2: v25);
      std::vector<CacheEntry *>::push_back(this: JobList, _Val: pPatchIDs);
      (*(void (__thiscall **)(CacheEntry *, IScheduleObject *))((*pPatchIDs)->index + 36))(
        a1: *pPatchIDs,
        a2: *ppCageJob);
    }
  }
  else
  {
    v124 = 0;
  }
  if ( CmdArgs->m_bGenerateAmbientOcclusion )
  {
    v26 = (float *)operator new(nSize: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    TileBuffers->m_pAmbientOcclusionBuffer = v26;
    if ( v26 == nullptr )
      return 0;
    memset(dst: (unsigned __int8 *)v26, value: 0, count: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    StartIndex = (CacheEntry **)operator new(nSize: 4u);
    v27 = (CUByteFromFloatTextureOutput *)operator new(nSize: 0x120u);
    if ( v27 != nullptr )
      v28 = CUByteFromFloatTextureOutput::CUByteFromFloatTextureOutput(
              this: v27,
              pDevice,
              pBits: TileBuffers->m_pAmbientOcclusionBuffer,
              Width: CmdArgs->m_TextureWidth,
              Height: CmdArgs->m_TextureHeight,
              fileFormat: CmdArgs->m_AOMapFileFormat,
              pszFileName: CmdArgs->m_szAOOutputFile);
    else
      v28 = nullptr;
    *StartIndex = (CacheEntry *)pThreadPool->CreateScheduleJob(this: pThreadPool, a2: v28);
    std::vector<CacheEntry *>::push_back(this: JobList, _Val: StartIndex);
  }
  if ( CmdArgs->m_bGenerateTSNormalMap )
  {
    v29 = (unsigned __int8 *)operator new(nSize: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    TileBuffers->m_pTSNormalMapBuffer = v29;
    if ( v29 == nullptr )
      return 0;
    memset(dst: v29, value: 0, count: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
    ppAOOutputJob = (CacheEntry **)operator new(nSize: 4u);
    v30 = (CUByte4TextureOutput *)operator new(nSize: 0x120u);
    if ( v30 != nullptr )
      v31 = CUByte4TextureOutput::CUByte4TextureOutput(
              this: v30,
              pDevice,
              pBits: TileBuffers->m_pTSNormalMapBuffer,
              Width: CmdArgs->m_TextureWidth,
              Height: CmdArgs->m_TextureHeight,
              fileFormat: CmdArgs->m_TSNormalFileFormat,
              pszFileName: CmdArgs->m_szTSNormOutputFile);
    else
      v31 = nullptr;
    *ppAOOutputJob = (CacheEntry *)pThreadPool->CreateScheduleJob(this: pThreadPool, a2: v31);
    std::vector<CacheEntry *>::push_back(this: JobList, _Val: ppAOOutputJob);
  }
  if ( CmdArgs->m_bGenerateOSNormalMap )
  {
    pPatchUVs = (CacheEntry **)operator new(nSize: 4u);
    v32 = (CUByte4TextureOutput *)operator new(nSize: 0x120u);
    if ( v32 != nullptr )
      v33 = CUByte4TextureOutput::CUByte4TextureOutput(
              this: v32,
              pDevice,
              pBits: TileBuffers->m_pOSNormalMapBuffer,
              Width: CmdArgs->m_TextureWidth,
              Height: CmdArgs->m_TextureHeight,
              fileFormat: CmdArgs->m_OSNormalFileFormat,
              pszFileName: CmdArgs->m_szOSNormOutputFile);
    else
      v33 = nullptr;
    *pPatchUVs = (CacheEntry *)pThreadPool->CreateScheduleJob(this: pThreadPool, a2: v33);
    std::vector<CacheEntry *>::push_back(this: JobList, _Val: pPatchUVs);
  }
  if ( !CmdArgs->m_bGenerateCavityMap )
    goto LABEL_48;
  v34 = (float *)operator new(nSize: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
  TileBuffers->m_pCavityMapBuffer = v34;
  if ( v34 == nullptr )
    return 0;
  memset(dst: (unsigned __int8 *)v34, value: 0, count: 4 * CmdArgs->m_TextureHeight * CmdArgs->m_TextureWidth);
  NumJobsU = (CacheEntry **)operator new(nSize: 4u);
  v35 = (CUByteFromFloatTextureOutput *)operator new(nSize: 0x120u);
  if ( v35 != nullptr )
    v36 = CUByteFromFloatTextureOutput::CUByteFromFloatTextureOutput(
            this: v35,
            pDevice,
            pBits: TileBuffers->m_pCavityMapBuffer,
            Width: CmdArgs->m_TextureWidth,
            Height: CmdArgs->m_TextureHeight,
            fileFormat: CmdArgs->m_CavityMapFileFormat,
            pszFileName: CmdArgs->m_szCavityOutputFile);
  else
    v36 = nullptr;
  *NumJobsU = (CacheEntry *)((int (__thiscall *)(ISchedulerThreadPool *, CUByteFromFloatTextureOutput *, CacheEntry *, IScheduleObject *))pThreadPool->CreateScheduleJob)(
                              a1: pThreadPool,
                              a2: v36,
                              a3: v76,
                              a4: a2);
  std::vector<CacheEntry *>::push_back(this: JobList, _Val: NumJobsU);
  NumJobsV = (CacheEntry **)operator new(nSize: 4u);
  v37 = (CCavityMap *)operator new(nSize: 0x20u);
  if ( v37 != nullptr )
    v38 = CCavityMap::CCavityMap(
            this: v37,
            pInputHeightBits: TileBuffers->m_pDisplacementOutputBuffer,
            pOutputBits: TileBuffers->m_pCavityMapBuffer,
            Width: CmdArgs->m_TextureWidth,
            Height: CmdArgs->m_TextureHeight,
            fRadius: CmdArgs->m_CavityRadius);
  else
    v38 = nullptr;
  *NumJobsV = (CacheEntry *)((int (__thiscall *)(ISchedulerThreadPool *, CCavityMap *, _DWORD, _DWORD))pThreadPool->CreateScheduleJob)(
                              a1: pThreadPool,
                              a2: v38,
                              a3: 0,
                              a4: 0);
  std::vector<CacheEntry *>::push_back(this: JobList, _Val: NumJobsV);
  ppTSOutputJob = (CacheEntry **)operator new(nSize: 4u);
  v39 = (CJob *)operator new(nSize: 0x14u);
  if ( v39 != nullptr )
  {
    m_TextureHeight = CmdArgs->m_TextureHeight;
    fCageTraceLengtha = CmdArgs->m_TextureWidth;
    v39[1].__vftable = (CJob_vtbl *)TileBuffers->m_pCavityMapBuffer;
    v39->m_iRef = 0;
    v39->__vftable = (CJob_vtbl *)&CNormalize::`vftable';
    v39[1].m_iRef = fCageTraceLengtha;
    v39[2].__vftable = (CJob_vtbl *)m_TextureHeight;
  }
  else
  {
    v39 = nullptr;
  }
  *ppTSOutputJob = (CacheEntry *)pThreadPool->CreateScheduleJob(this: pThreadPool, a2: v39);
  std::vector<CacheEntry *>::push_back(this: JobList, _Val: ppTSOutputJob);
  (*(void (__thiscall **)(CacheEntry *, IScheduleObject *))((*NumJobsV)->index + 36))(a1: *NumJobsV, a2: *ppCageJob);
  (*(void (__thiscall **)(CacheEntry *, CacheEntry *))((*ppTSOutputJob)->index + 36))(a1: *ppTSOutputJob, a2: *NumJobsV);
  (*(void (__thiscall **)(CacheEntry *, CacheEntry *))((*NumJobsU)->index + 36))(a1: *NumJobsU, a2: *ppTSOutputJob);
  pFenceScheduleJob->AddDependency(this: pFenceScheduleJob, a2: (IScheduleObject *)*NumJobsU);
LABEL_48:
  fCageTraceLength = 0;
  NumJobsVa = 0;
  if ( v97 > 0 )
  {
    while ( 1 )
    {
      NumJobsUa = 0;
      if ( (int)ppAOJob > 0 )
        break;
LABEL_124:
      fCageTraceLength += v17->m_JobRectSizeV * v17->m_TextureWidth;
      if ( ++NumJobsVa >= v97 )
        return 1;
    }
    while ( 1 )
    {
      v41 = NumJobsUa * v17->m_JobRectSizeU;
      v42 = v41 + fCageTraceLength;
      pOSNormalMapBuffer = v41 + fCageTraceLength;
      if ( v17->m_JobRectSizeU >= v17->m_TextureWidth - v41 )
        ppDispOutputJob = (IScheduleObject **)(v17->m_TextureWidth - NumJobsUa * v17->m_JobRectSizeU);
      else
        ppDispOutputJob = (IScheduleObject **)v17->m_JobRectSizeU;
      if ( v17->m_JobRectSizeV >= v17->m_TextureHeight - NumJobsVa * v17->m_JobRectSizeV )
        m_JobRectSizeV = v17->m_TextureHeight - NumJobsVa * v17->m_JobRectSizeV;
      else
        m_JobRectSizeV = v17->m_JobRectSizeV;
      ppTSOutputJoba = (IScheduleObject **)m_JobRectSizeV;
      if ( v124 == 0 )
        goto LABEL_91;
      ppOSOutputJob = (IScheduleObject **)operator new(nSize: 4u);
      v44 = (float *)operator new(nSize: 0x30u);
      if ( v44 != nullptr )
      {
        m_flTraceBias = v17->m_flTraceBias;
        RectSizeVb = v17->m_TextureWidth;
        RectSizeUc = &TileBuffers->m_pNearCageDistanceBuffers[v42];
        *((_DWORD *)v44 + 2) = rteCage;
        *((_DWORD *)v44 + 3) = SubDMesh;
        *((_DWORD *)v44 + 6) = &ju[v42];
        *((_DWORD *)v44 + 7) = &jv[v42];
        *((_DWORD *)v44 + 8) = ppDispOutputJob;
        *((_DWORD *)v44 + 9) = ppTSOutputJoba;
        v44[4] = m_flTraceBias;
        v44[1] = 0.0;
        *(_DWORD *)v44 = &CRayTraceNearCageJob::`vftable';
        v44[5] = v96;
        *((_DWORD *)v44 + 10) = RectSizeVb;
        *((_DWORD *)v44 + 11) = RectSizeUc;
      }
      else
      {
        v44 = nullptr;
      }
      *ppOSOutputJob = (IScheduleObject *)((int (__thiscall *)(ISchedulerThreadPool *, float *, CacheEntry *, IScheduleObject *, IScheduleObject *, float *))pThreadPool->CreateScheduleJob)(
                                            a1: pThreadPool,
                                            a2: v44,
                                            a3: v76,
                                            a4: v77,
                                            a5: v78,
                                            a6: v79);
      Mylast = (IScheduleObject **)JobList->_Mylast;
      v47 = JobList;
      if ( ppOSOutputJob >= Mylast || JobList->_Myfirst > (CacheEntry **)ppOSOutputJob )
      {
        if ( Mylast == (IScheduleObject **)JobList->_Myend )
        {
          std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
          v47 = JobList;
        }
        v50 = v47->_Mylast;
        if ( v50 != nullptr )
        {
          v49 = *ppOSOutputJob;
          goto LABEL_70;
        }
      }
      else
      {
        v48 = ((char *)ppOSOutputJob - (char *)JobList->_Myfirst) >> 2;
        RectSizeU = v48;
        if ( JobList->_Mylast == JobList->_Myend )
        {
          std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
          v48 = RectSizeU;
          v47 = JobList;
        }
        if ( v47->_Mylast != nullptr )
        {
          v49 = (IScheduleObject *)v47->_Myfirst[v48];
          v50 = v47->_Mylast;
LABEL_70:
          *v50 = (CacheEntry *)v49;
        }
      }
      ++v47->_Mylast;
      RectSizeV = v42;
      v82 = &TileBuffers->m_pOSNormalMapBuffer[4 * v42];
      RectSizeUa = (IScheduleObject **)operator new(nSize: 4u);
      v51 = (float *)operator new(nSize: 0x40u);
      if ( v51 != nullptr )
      {
        v53 = v17->m_flTraceBias;
        v54 = v42;
        v55 = (((char *)objDetailLoader->m_Indices._Mylast - (char *)objDetailLoader->m_Indices._Myfirst) & 0xFFFFFFFC) != 0
            ? &objDetailLoader->m_Indices
            : nullptr;
        v56 = ((char *)objDetailLoader->m_Vertices._Mylast - (char *)objDetailLoader->m_Vertices._Myfirst) / -52 != 0
            ? objDetailLoader
            : nullptr;
        RectSizeVc = &TileBuffers->m_pNearCageDistanceBuffers[RectSizeV];
        pTanUs = (Vector4D *)CmdArgs->m_TextureWidth;
        v88 = &TileBuffers->m_pDisplacementOutputBuffer[v54];
        *((_DWORD *)v51 + 2) = rteDetail;
        *((_DWORD *)v51 + 4) = v56;
        *((_DWORD *)v51 + 3) = SubDMesh;
        *((_DWORD *)v51 + 5) = v55;
        v42 = pOSNormalMapBuffer;
        *((_DWORD *)v51 + 8) = &ju[pOSNormalMapBuffer];
        *((_DWORD *)v51 + 10) = RectSizeVc;
        *((_DWORD *)v51 + 11) = ppDispOutputJob;
        *((_DWORD *)v51 + 12) = ppTSOutputJoba;
        *((_DWORD *)v51 + 13) = pTanUs;
        v51[6] = v53;
        *((_DWORD *)v51 + 9) = &jv[v54];
        v17 = CmdArgs;
        v51[1] = 0.0;
        *(_DWORD *)v51 = &CRayTraceDisplacementJob::`vftable';
        v51[7] = fDetailTraceLength;
        *((_DWORD *)v51 + 14) = v88;
        *((_DWORD *)v51 + 15) = v82;
      }
      else
      {
        v51 = nullptr;
      }
      v79 = v51;
      *RectSizeUa = (IScheduleObject *)((int (__thiscall *)(ISchedulerThreadPool *))pThreadPool->CreateScheduleJob)(a1: pThreadPool);
      v57 = (IScheduleObject **)JobList->_Mylast;
      v58 = JobList;
      if ( RectSizeUa >= v57 || JobList->_Myfirst > (CacheEntry **)RectSizeUa )
      {
        if ( v57 == (IScheduleObject **)JobList->_Myend )
        {
          std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
          v58 = JobList;
        }
        v61 = v58->_Mylast;
        if ( v61 == nullptr )
          goto LABEL_85;
        v60 = *RectSizeUa;
      }
      else
      {
        v59 = ((char *)RectSizeUa - (char *)JobList->_Myfirst) >> 2;
        v83 = v59;
        if ( JobList->_Mylast == JobList->_Myend )
        {
          std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
          v58 = JobList;
          v59 = v83;
        }
        if ( v58->_Mylast == nullptr )
          goto LABEL_85;
        v60 = (IScheduleObject *)v58->_Myfirst[v59];
        v61 = v58->_Mylast;
      }
      *v61 = (CacheEntry *)v60;
LABEL_85:
      ++v58->_Mylast;
      v78 = *ppOSOutputJob;
      ((void (__thiscall *)(IScheduleObject *))(*RectSizeUa)->AddDependency)(a1: *RectSizeUa);
      v77 = *RectSizeUa;
      ((void (__thiscall *)(IScheduleObject *))(*ppCageJob)->AddDependency)(a1: *ppCageJob);
      if ( v17->m_bGenerateOSNormalMap )
      {
        (*(void (__thiscall **)(CacheEntry *, IScheduleObject *))((*pPatchUVs)->index + 36))(
          a1: *pPatchUVs,
          a2: *RectSizeUa);
        pFenceScheduleJob->AddDependency(this: pFenceScheduleJob, a2: (IScheduleObject *)*pPatchUVs);
      }
      if ( v17->m_bGenerateDisplacementMap )
        v76 = *pPatchIDs;
      else
        v76 = (CacheEntry *)*ppCageJob;
      ((void (__thiscall *)(IScheduleObject *))pFenceScheduleJob->AddDependency)(a1: pFenceScheduleJob);
LABEL_91:
      if ( !v17->m_bGenerateTSNormalMap )
        goto LABEL_107;
      RectSizeUb = (IScheduleObject **)operator new(nSize: 4u);
      v62 = operator new(nSize: 0x2Cu);
      if ( v62 != nullptr )
      {
        pTanUsa = (Vector4D *)&TileBuffers->m_pTSNormalMapBuffer[4 * v42];
        m_TextureWidth = v17->m_TextureWidth;
        v84 = &TileBuffers->m_pOSNormalMapBuffer[4 * v42];
        v62[2] = SubDMesh;
        v62[4] = &jv[v42];
        v62[3] = &ju[v42];
        v62[5] = &v81[v42];
        v62[6] = v84;
        v62[7] = ppDispOutputJob;
        v62[8] = ppTSOutputJoba;
        v62[1] = 0;
        *v62 = &COSNormalsToTSNormals::`vftable';
        v62[9] = m_TextureWidth;
        v62[10] = pTanUsa;
      }
      else
      {
        v62 = nullptr;
      }
      *RectSizeUb = (IScheduleObject *)((int (__thiscall *)(ISchedulerThreadPool *, _DWORD *, CacheEntry *, IScheduleObject *, IScheduleObject *))pThreadPool->CreateScheduleJob)(
                                         a1: pThreadPool,
                                         a2: v62,
                                         a3: v76,
                                         a4: v77,
                                         a5: v78);
      v63 = (IScheduleObject **)JobList->_Mylast;
      v64 = JobList;
      if ( RectSizeUb >= v63 || JobList->_Myfirst > (CacheEntry **)RectSizeUb )
      {
        if ( v63 == (IScheduleObject **)JobList->_Myend )
        {
          std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
          v64 = JobList;
        }
        v67 = v64->_Mylast;
        if ( v67 == nullptr )
          goto LABEL_106;
        v66 = *RectSizeUb;
      }
      else
      {
        v65 = ((char *)RectSizeUb - (char *)JobList->_Myfirst) >> 2;
        v85 = v65;
        if ( JobList->_Mylast == JobList->_Myend )
        {
          std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
          v64 = JobList;
          v65 = v85;
        }
        if ( v64->_Mylast == nullptr )
          goto LABEL_106;
        v66 = (IScheduleObject *)v64->_Myfirst[v65];
        v67 = v64->_Mylast;
      }
      *v67 = (CacheEntry *)v66;
LABEL_106:
      ++v64->_Mylast;
      v78 = *ppCageJob;
      ((void (__thiscall *)(IScheduleObject *))(*RectSizeUb)->AddDependency)(a1: *RectSizeUb);
      v77 = *RectSizeUb;
      (*(void (__thiscall **)(CacheEntry *))((*ppAOOutputJob)->index + 36))(a1: *ppAOOutputJob);
      v76 = *ppAOOutputJob;
      ((void (__thiscall *)(IScheduleObject *))pFenceScheduleJob->AddDependency)(a1: pFenceScheduleJob);
LABEL_107:
      if ( v17->m_bGenerateAmbientOcclusion )
      {
        pOSNormalMapBuffera = (IScheduleObject **)operator new(nSize: 4u);
        v68 = (float *)operator new(nSize: 0x38u);
        if ( v68 != nullptr )
        {
          v69 = v17->m_flTraceBias;
          v86 = v17->m_TextureWidth;
          v90 = &TileBuffers->m_pDisplacementOutputBuffer[v42];
          pTanUsb = (Vector4D *)&TileBuffers->m_pAmbientOcclusionBuffer[v42];
          *((_DWORD *)v68 + 2) = pSampler;
          *((_DWORD *)v68 + 3) = rteDetail;
          *((_DWORD *)v68 + 4) = SubDMesh;
          *((_DWORD *)v68 + 8) = &jv[v42];
          *((_DWORD *)v68 + 7) = &ju[v42];
          *((_DWORD *)v68 + 9) = ppDispOutputJob;
          *((_DWORD *)v68 + 10) = ppTSOutputJoba;
          *((_DWORD *)v68 + 11) = v86;
          v68[5] = v69;
          v68[1] = 0.0;
          *(_DWORD *)v68 = &CRayTraceAmbientOcclusionJob::`vftable';
          v68[6] = fDetailTraceLength;
          *((_DWORD *)v68 + 12) = v90;
          *((_DWORD *)v68 + 13) = pTanUsb;
        }
        else
        {
          v68 = nullptr;
        }
        v70 = ((int (__thiscall *)(ISchedulerThreadPool *, float *, CacheEntry *, IScheduleObject *, IScheduleObject *))pThreadPool->CreateScheduleJob)(
                a1: pThreadPool,
                a2: v68,
                a3: v76,
                a4: v77,
                a5: v78);
        v71 = JobList;
        *pOSNormalMapBuffera = (IScheduleObject *)v70;
        v72 = (IScheduleObject **)JobList->_Mylast;
        RectSizeVa = v72;
        if ( pOSNormalMapBuffera >= v72 || JobList->_Myfirst > (CacheEntry **)pOSNormalMapBuffera )
        {
          if ( v72 == (IScheduleObject **)JobList->_Myend )
          {
            std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
            v71 = JobList;
          }
          v75 = v71->_Mylast;
          if ( v75 != nullptr )
          {
            v74 = *pOSNormalMapBuffera;
LABEL_121:
            *v75 = (CacheEntry *)v74;
          }
        }
        else
        {
          v73 = ((char *)pOSNormalMapBuffera - (char *)JobList->_Myfirst) >> 2;
          v87 = v73;
          if ( RectSizeVa == (IScheduleObject **)JobList->_Myend )
          {
            std::vector<CacheEntry *>::_Reserve(this: JobList, _Count: 1u);
            v71 = JobList;
            v73 = v87;
          }
          if ( v71->_Mylast != nullptr )
          {
            v74 = (IScheduleObject *)v71->_Myfirst[v73];
            v75 = v71->_Mylast;
            goto LABEL_121;
          }
        }
        ++v71->_Mylast;
        v78 = *ppCageJob;
        ((void (__thiscall *)(IScheduleObject *))(*pOSNormalMapBuffera)->AddDependency)(a1: *pOSNormalMapBuffera);
        v77 = *pOSNormalMapBuffera;
        (*(void (__thiscall **)(CacheEntry *))((*StartIndex)->index + 36))(a1: *StartIndex);
        v76 = *StartIndex;
        ((void (__thiscall *)(IScheduleObject *))pFenceScheduleJob->AddDependency)(a1: pFenceScheduleJob);
      }
      if ( ++NumJobsUa >= (int)ppAOJob )
        goto LABEL_124;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A1A0
// Name: public: CObjLoader::~CObjLoader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjLoader::~CObjLoader(CObjLoader *this)
{
  if ( this->m_VertexCache._Myfirst != nullptr )
    free(pMem: this->m_VertexCache._Myfirst);
  this->m_VertexCache._Myfirst = nullptr;
  this->m_VertexCache._Mylast = nullptr;
  this->m_VertexCache._Myend = nullptr;
  if ( this->m_Indices._Myfirst != nullptr )
    free(pMem: this->m_Indices._Myfirst);
  this->m_Indices._Myfirst = nullptr;
  this->m_Indices._Mylast = nullptr;
  this->m_Indices._Myend = nullptr;
  if ( this->m_Vertices._Myfirst != nullptr )
    free(pMem: this->m_Vertices._Myfirst);
  this->m_Vertices._Myfirst = nullptr;
  this->m_Vertices._Mylast = nullptr;
  this->m_Vertices._Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041A200
// Name: _main
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // ebp
  Vector *v5; // esi
  void (__thiscall *v6)(Vector *, int); // eax
  void (__thiscall *v7)(Vector *, int); // eax
  Vector4D *Mylast; // esi
  unsigned int v9; // edi
  const Vector *v10; // esi
  int v11; // esi
  int v12; // ecx
  char *v13; // eax
  IDirect3DDevice9 *v14; // edi
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  unsigned int (__stdcall *Release)(IUnknown *); // eax
  OBJ_VERTEX **v18; // edi
  int v19; // ecx
  unsigned int v20; // esi
  __int128 v21; // xmm1
  __int128 v22; // xmm0
  int v23; // esi
  int v24; // ecx
  int v25; // edx
  IDirect3DDevice9_vtbl *v26; // eax
  int v27; // xmm1_4
  int v28; // xmm2_4
  IDirect3DPixelShader9 *v29; // xmm1_4
  int v30; // xmm2_4
  float v31; // xmm1_4
  IDirect3D9 *v32; // xmm2_4
  int v33; // edi
  ISchedulerThreadPool *ThreadPool; // esi
  ISchedulerThreadPool_vtbl *v35; // edx
  int v36; // eax
  bool (__thiscall *CreateSchedulerThreads)(ISchedulerThreadPool *, int); // eax
  _DWORD *v38; // eax
  ISchedulerThreadPool_vtbl *v39; // edx
  CUniformSampler *v40; // eax
  IScheduleObject *v41; // esi
  IDirect3DDevice9 *v42; // edi
  int *v43; // edi
  Vector *v44; // eax
  float x; // edx
  int v46; // eax
  int v47; // edx
  int v48; // esi
  int v49; // eax
  int v50; // edi
  int v51; // esi
  int v52; // esi
  int v53; // edi
  IDirect3DDevice9 *v54; // esi
  void **v55; // esi
  double v56; // st7
  char v57[12]; // [esp+40h] [ebp-F0Ch] BYREF
  char strScratch[260]; // [esp+4Ch] [ebp-F00h] BYREF
  _BYTE DetailOBJJob_292[2169]; // [esp+278h] [ebp-CD4h] OVERLAPPED BYREF
  RayTracingEnvironment rteDetail; // [esp+AFCh] [ebp-450h] BYREF
  RayTracingEnvironment rteCage; // [esp+BCCh] [ebp-380h] BYREF
  int v62; // [esp+C9Ch] [ebp-2B0h]
  char *v63; // [esp+CA0h] [ebp-2ACh]
  int v64; // [esp+CA4h] [ebp-2A8h]
  int v65; // [esp+CA8h] [ebp-2A4h]
  int v66; // [esp+CACh] [ebp-2A0h]
  int v67; // [esp+CB0h] [ebp-29Ch]
  int v68; // [esp+CB4h] [ebp-298h]
  int v69; // [esp+CB8h] [ebp-294h]
  _BYTE *v70; // [esp+CBCh] [ebp-290h]
  char v71; // [esp+CC0h] [ebp-28Ch] BYREF
  _BYTE v72[3]; // [esp+CC1h] [ebp-28Bh] BYREF
  char strFileName[260]; // [esp+CCCh] [ebp-280h] BYREF
  CSubDMesh SubDMesh; // [esp+DD4h] [ebp-178h] BYREF
  int v75; // [esp+E70h] [ebp-DCh]
  Vector v1; // [esp+E74h] [ebp-D8h] BYREF
  Vector vColor; // [esp+E80h] [ebp-CCh] BYREF
  CObjLoader detailLoader; // [esp+E8Ch] [ebp-C0h] BYREF
  float v79; // [esp+ED8h] [ebp-74h] BYREF
  float v80; // [esp+EDCh] [ebp-70h]
  IDirect3D9 *pd3d9; // [esp+EE0h] [ebp-6Ch]
  Vector v2; // [esp+EE4h] [ebp-68h]
  _BYTE fDetailTraceLength[24]; // [esp+EF0h] [ebp-5Ch] OVERLAPPED BYREF
  int v84; // [esp+F08h] [ebp-44h] BYREF
  Vector *pCageTriangleVerts; // [esp+F0Ch] [ebp-40h]
  int NumTextureTilesV; // [esp+F10h] [ebp-3Ch]
  IDirect3DDevice9 *v87; // [esp+F14h] [ebp-38h]
  CP4AutoAddFile autop4; // [esp+F18h] [ebp-34h]
  int NumTextureTilesU; // [esp+F1Ch] [ebp-30h] BYREF
  void **p_m_pvDirections; // [esp+F20h] [ebp-2Ch]
  int i2; // [esp+F24h] [ebp-28h]
  IDirect3DDevice9 *pd3dDevice; // [esp+F28h] [ebp-24h] BYREF
  unsigned int NumDetailTriangles; // [esp+F2Ch] [ebp-20h]
  int tv; // [esp+F30h] [ebp-1Ch]
  std::vector<OBJ_VERTEX> *pDetailVertices; // [esp+F34h] [ebp-18h]
  unsigned int t; // [esp+F38h] [ebp-14h]
  int v97; // [esp+F3Ch] [ebp-10h]
  _DWORD v98[2]; // [esp+F40h] [ebp-Ch] BYREF
  int v99; // [esp+F48h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+F4Ch] [ebp+0h]

  v98[0] = v3;
  v98[1] = retaddr;
  v97 = -1;
  g_UseGameDir = true;
  v2.z = ((double (__cdecl *)())_Plat_FloatTime)();
  memset(dst: DetailOBJJob_292, value: 0, count: 0x874u);
  *(_DWORD *)&DetailOBJJob_292[520] = 1024;
  *(_DWORD *)&DetailOBJJob_292[524] = 1024;
  *(_DWORD *)&DetailOBJJob_292[532] = 16;
  *(_DWORD *)&DetailOBJJob_292[536] = 16;
  *(_DWORD *)&DetailOBJJob_292[544] = 16;
  *(_DWORD *)&DetailOBJJob_292[560] = 16;
  *(_DWORD *)&DetailOBJJob_292[2144] = 2;
  *(_DWORD *)&DetailOBJJob_292[2148] = 2;
  *(_DWORD *)&DetailOBJJob_292[2152] = 2;
  *(_DWORD *)&DetailOBJJob_292[2156] = 2;
  *(_DWORD *)&DetailOBJJob_292[2160] = 2;
  *(_DWORD *)&DetailOBJJob_292[540] = 1008981770;
  *(_DWORD *)&DetailOBJJob_292[528] = 4;
  *(_DWORD *)&DetailOBJJob_292[548] = 128;
  *(_DWORD *)&DetailOBJJob_292[552] = 1065353216;
  *(_DWORD *)&DetailOBJJob_292[556] = 1065353216;
  DetailOBJJob_292[574] = 1;
  *(_DWORD *)&DetailOBJJob_292[2140] = 8;
  if ( ParseCommandLine(argc, (char **)argv, CmdArgs: (SubDBakerArgs_t *)DetailOBJJob_292) == 0 )
    return 0;
  g_suggestGameDirHelper.m_pszInputFile = DetailOBJJob_292;
  SetSuggestGameInfoDirFn(pfnNewFn: (bool (__cdecl *)(const CFSSteamSetupInfo *, char *, int, bool *))CSuggestGameDirHelper::SuggestFn);
  if ( g_UseGameDir && g_pFileSystem == nullptr )
  {
    FileSystem_Init(pBSPFilename: DetailOBJJob_292, maxMemoryUsage: 0, initType: FS_INIT_FULL, bOnlyUseFilename: false);
    V_FixSlashes(pname: gamedir, separator: 47);
  }
  if ( SetupPerforce(bUseP4: DetailOBJJob_292[574]) == 0 )
  {
    printf(format: "Unable to set up Perforce.  Exiting...\n");
    return 0;
  }
  detailLoader.m_LoadFlags = OBJ_LOAD_TRIANGULATE;
  NumTextureTilesU = 0;
  if ( !CreateD3DDevice(
          ppd3d9: (IDirect3D9 **)&detailLoader.m_LoadFlags,
          ppd3dDevice: (IDirect3DDevice9 **)&NumTextureTilesU) )
    return 1;
  CSubDMesh::CSubDMesh(this: (CSubDMesh *)&strFileName[252]);
  v97 = 0;
  if ( CSubDMesh::Load(this: (CSubDMesh *)&strFileName[252], a2: (int)v98, strOBJFileName: DetailOBJJob_292) == 0 )
  {
    printf(format: "Error Loading Cage Mesh\n");
LABEL_10:
    v97 = -1;
    CSubDMesh::~CSubDMesh(this: (CSubDMesh *)&strFileName[252]);
    return 1;
  }
  printf(format: "Preprocessing Meshes...\n");
  v5 = (Vector *)CP4Factory::AccessFile(this: g_p4factory, szFilename: DetailOBJJob_292);
  pCageTriangleVerts = v5;
  v6 = *(void (__thiscall **)(Vector *, int))(LODWORD(v5->x) + 8);
  LOBYTE(v97) = 1;
  v6(a1: v5, a2: v97);
  v7 = *(void (__thiscall **)(Vector *, int))LODWORD(v5->x);
  LOBYTE(v97) = 0;
  v7(a1: v5, a2: 1);
  CSubDMesh::UpdateSubDPatches(
    this: (CSubDMesh *)&strFileName[252],
    cornerCorrection: false,
    accGeometryTangents: false);
  if ( CSubDMesh::RenderMeshToUVandIDTexture(
         this: (CSubDMesh *)&strFileName[252],
         a2: (int)&v99,
         pd3dDevice: (IDirect3DDevice9 *)NumTextureTilesU,
         Width: *(int *)&DetailOBJJob_292[520],
         Height: *(int *)&DetailOBJJob_292[524],
         GutterSize: *(int *)&DetailOBJJob_292[528]) == 0
    || DetailOBJJob_292[567] != 0
    && CSubDMesh::RenderHardEdgesToTexture(
         this: (CSubDMesh *)&strFileName[252],
         pd3dDevice: (IDirect3DDevice9 *)NumTextureTilesU,
         Width: *(int *)&DetailOBJJob_292[520],
         Height: *(int *)&DetailOBJJob_292[524],
         fLineWidth: *(float *)&DetailOBJJob_292[552],
         pszFileName: &DetailOBJJob_292[1100]) == 0 )
  {
    goto LABEL_10;
  }
  if ( DetailOBJJob_292[260] == 0 && DetailOBJJob_292[0] != 0 || *(_WORD *)&DetailOBJJob_292[571] != 0 )
  {
    if ( CSubDMesh::CreatePreTessPatch(
           this: (CSubDMesh *)&strFileName[252],
           NumDivisionsPerSide: *(int *)&DetailOBJJob_292[560]) == 0 )
      goto LABEL_10;
    if ( DetailOBJJob_292[571] != 0 )
    {
      V_StripExtension(in: DetailOBJJob_292, out: v57, outSize: 260);
      sprintf_s(string: &v71, sizeInBytes: 0x104u, format: "%s_HighSmooth.obj", v57);
      COutputDetailOBJJob::COutputDetailOBJJob(
        this: (COutputDetailOBJJob *)&strScratch[252],
        pSubDMesh: (CSubDMesh *)&strFileName[252],
        pTileBuffers: nullptr,
        Width: 0,
        Height: 0,
        NumTilesU: 0,
        pszFileName: &v71,
        prteDetail: nullptr,
        bRemoveRedundancies: true);
      LOBYTE(v97) = 2;
      COutputDetailOBJJob::Execute(this: (COutputDetailOBJJob *)&strScratch[252], pDependencyArray: nullptr);
    }
  }
  v79 = SubDMesh.m_vecMinBounds.x - *(float *)&SubDMesh.m_tanU._Alval.std::_Allocator_base<Vector4D>;
  v80 = SubDMesh.m_vecMinBounds.y - *(float *)&SubDMesh.m_NumTriangles;
  *(float *)&pd3d9 = SubDMesh.m_vecMinBounds.z - *(float *)&SubDMesh.m_pTriangleVertList;
  printf(format: "Initializing kd Tree for cage mesh...\n");
  RayTracingEnvironment::RayTracingEnvironment(this: (RayTracingEnvironment *)&rteDetail.TriangleMaterials.m_pElements);
  rteDetail.TriangleMaterials.m_pElements = (int *)((int)rteDetail.TriangleMaterials.m_pElements | 6);
  Mylast = SubDMesh.m_tanU._Mylast;
  *(_DWORD *)&fDetailTraceLength[20] = SubDMesh.m_tanU._Myend;
  LOBYTE(v97) = 3;
  pd3dDevice = (IDirect3DDevice9 *)SubDMesh.m_tanU._Mylast;
  RayTracingEnvironment::MakeRoomForTriangles(
    this: (RayTracingEnvironment *)&rteDetail.TriangleMaterials.m_pElements,
    ntris: (int)SubDMesh.m_tanU._Mylast);
  v9 = 0;
  memset(&v1, 0, sizeof(v1));
  if ( Mylast != nullptr )
  {
    v10 = (const Vector *)(*(_DWORD *)&fDetailTraceLength[20] + 12);
    do
    {
      RayTracingEnvironment::AddTriangle(
        this: (RayTracingEnvironment *)&rteDetail.TriangleMaterials.m_pElements,
        id: v9++,
        v1: v10 - 1,
        v2: v10,
        v3: v10 + 1,
        color: &v1);
      v10 += 3;
    }
    while ( v9 < (unsigned int)pd3dDevice );
  }
  RayTracingEnvironment::SetupAccelerationStructure(this: (RayTracingEnvironment *)&rteDetail.TriangleMaterials.m_pElements);
  *(_DWORD *)&fDetailTraceLength[20] = SubDMesh.m_NumHardEdges;
  NumTextureTilesV = (int)SubDMesh.m_pPatchScratchACCV;
  v11 = (int)SubDMesh.m_pPatchScratchACCV * SubDMesh.m_NumHardEdges;
  v12 = (28 * (unsigned __int64)(unsigned int)((int)SubDMesh.m_pPatchScratchACCV * SubDMesh.m_NumHardEdges)) >> 32 != 0
      ? -1
      : 28 * (int)SubDMesh.m_pPatchScratchACCV * SubDMesh.m_NumHardEdges;
  v13 = (char *)operator new(nSize: __CFADD__(v12, 4) ? -1 : v12 + 4);
  pCageTriangleVerts = (Vector *)v13;
  LOBYTE(v97) = 4;
  if ( v13 != nullptr )
  {
    t = (unsigned int)CTileBuffers::~CTileBuffers;
    pDetailVertices = (std::vector<OBJ_VERTEX> *)CTileBuffers::CTileBuffers;
    tv = v11;
    v14 = (IDirect3DDevice9 *)(v13 + 4);
    NumDetailTriangles = 28;
    pd3dDevice = (IDirect3DDevice9 *)(v13 + 4);
    *(_DWORD *)v13 = v11;
    `eh vector constructor iterator'(
      ptr: pd3dDevice,
      size: NumDetailTriangles,
      count: tv,
      pCtor: (void (__thiscall *)(void *))pDetailVertices,
      pDtor: (void (__thiscall *)(void *))t);
    v87 = v14;
  }
  else
  {
    v87 = nullptr;
  }
  memset(&vColor, 0, sizeof(vColor));
  memset(&detailLoader.m_Vertices._Mylast, 0, 12);
  memset(&detailLoader.m_Indices._Mylast, 0, 12);
  RayTracingEnvironment::RayTracingEnvironment(this: (RayTracingEnvironment *)&DetailOBJJob_292[2168]);
  LOBYTE(v97) = 6;
  v2.x = 0.0;
  if ( NeedsDisplacementCalc(CmdArgs: (SubDBakerArgs_t *)DetailOBJJob_292) )
  {
    if ( DetailOBJJob_292[260] != 0 || DetailOBJJob_292[0] == 0 )
    {
      if ( !CObjLoader::LoadObj(
              this: (CObjLoader *)&vColor,
              pszFileName: &DetailOBJJob_292[260],
              LoadFlags: OBJ_LOAD_TRIANGULATE,
              bComputeTangents: false) )
      {
        printf(format: "Error Loading Detail Mesh\n");
        RayTracingEnvironment::~RayTracingEnvironment(this: (RayTracingEnvironment *)&DetailOBJJob_292[2168]);
        CObjLoader::~CObjLoader(this: (CObjLoader *)&vColor);
        RayTracingEnvironment::~RayTracingEnvironment(this: (RayTracingEnvironment *)&rteDetail.TriangleMaterials.m_pElements);
        v97 = -1;
        CSubDMesh::~CSubDMesh(this: (CSubDMesh *)&strFileName[252]);
        return 1;
      }
      pd3dDevice = (IDirect3DDevice9 *)CP4Factory::AccessFile(this: g_p4factory, szFilename: &DetailOBJJob_292[260]);
      Release = pd3dDevice->Release;
      LOBYTE(v97) = 9;
      ((void (__thiscall *)(IDirect3DDevice9 *, int))Release)(a1: pd3dDevice, a2: v97);
      LOBYTE(v97) = 6;
      CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: (CP4AutoAddFile *)&pd3dDevice);
      v18 = (((char *)detailLoader.m_Vertices._Myend - (char *)detailLoader.m_Vertices._Mylast) & 0xFFFFFFFC) != 0
          ? &detailLoader.m_Vertices._Mylast
          : nullptr;
      v19 = (char *)v18[1] - (char *)*v18;
      pd3dDevice = (LODWORD(vColor.y) - LODWORD(vColor.x)) / -52 != 0 ? (IDirect3DDevice9 *)&vColor : nullptr;
      v20 = (v19 >> 2) / 3u;
      p_m_pvDirections = (void **)v20;
      pCageTriangleVerts = (Vector *)v20;
      v84 = 0;
      printf(format: "Initializing kd Tree for detail mesh (%d triangles)...\n", v20);
      v21 = 0;
      *(float *)&v21 = (float)((float)((float)(detailLoader.m_vecMinBounds.x
                                             - *(float *)&detailLoader.m_VertexCache._Mylast)
                                     * (float)(detailLoader.m_vecMinBounds.x
                                             - *(float *)&detailLoader.m_VertexCache._Mylast))
                             + (float)((float)(detailLoader.m_vecMinBounds.y
                                             - *(float *)&detailLoader.m_VertexCache._Myend)
                                     * (float)(detailLoader.m_vecMinBounds.y
                                             - *(float *)&detailLoader.m_VertexCache._Myend)))
                     + (float)((float)(detailLoader.m_vecMinBounds.z
                                     - *(float *)&detailLoader.m_VertexCache._Alval.std::_Allocator_base<CacheEntry *>)
                             * (float)(detailLoader.m_vecMinBounds.z
                                     - *(float *)&detailLoader.m_VertexCache._Alval.std::_Allocator_base<CacheEntry *>));
      v22 = v21;
      *(float *)&v22 = fsqrt(*(float *)&v21);
      *(_OWORD *)fDetailTraceLength = v22;
      v2.x = *(float *)&v22 * 1.5;
      RayTracingEnvironment::MakeRoomForTriangles(this: (RayTracingEnvironment *)&DetailOBJJob_292[2168], ntris: v20);
      NumDetailTriangles = 0;
      if ( v20 != 0 )
      {
        v23 = 0;
        i2 = (int)p_m_pvDirections;
        do
        {
          v24 = 52 * *(_DWORD *)((char *)&(*v18)->pos.x + v23);
          v25 = 52 * *(_DWORD *)((char *)&(*v18)->pos.y + v23);
          autop4.m_spImpl.m_p = *(CP4File **)((char *)&(*v18)->pos.z + v23);
          v26 = pd3dDevice->__vftable;
          v27 = *(int *)((char *)&pd3dDevice->AddRef + v24);
          v28 = *(int *)((char *)&pd3dDevice->Release + v24);
          *(_DWORD *)&fDetailTraceLength[4] = *(HRESULT (__stdcall **)(IUnknown *, const _GUID *, void **))((char *)&pd3dDevice->QueryInterface + v24);
          *(_DWORD *)&fDetailTraceLength[8] = v27;
          *(_DWORD *)&fDetailTraceLength[12] = v28;
          v29 = *(IDirect3DPixelShader9 **)((char *)&v26->AddRef + v25);
          v30 = *(int *)((char *)&v26->Release + v25);
          SubDMesh.m_pVS = *(IDirect3DVertexShader9 **)((char *)&v26->QueryInterface + v25);
          SubDMesh.m_pPS = v29;
          v75 = v30;
          v31 = *((float *)&v26->AddRef + 13 * (int)autop4.m_spImpl.m_p);
          v32 = *((IDirect3D9 **)&v26->Release + 13 * (int)autop4.m_spImpl.m_p);
          v79 = *((float *)&v26->QueryInterface + 13 * (int)autop4.m_spImpl.m_p);
          v80 = v31;
          pd3d9 = v32;
          RayTracingEnvironment::AddTriangle(
            this: (RayTracingEnvironment *)&DetailOBJJob_292[2168],
            id: NumDetailTriangles,
            v1: (const Vector *)&fDetailTraceLength[4],
            v2: (const Vector *)&SubDMesh.m_pVS,
            v3: (const Vector *)&v79,
            color: &v1);
          v23 += 12;
          CProgressBar::UpdateProgress(this: (CProgressBar *)&v84, nRemainingUnits: i2--);
          ++NumDetailTriangles;
        }
        while ( NumDetailTriangles < (unsigned int)p_m_pvDirections );
      }
      printf(format: "|\n");
    }
    else
    {
      printf(format: "Initializing kd Tree for detail mesh...\n");
      v62 = 0;
      v63 = &strFileName[252];
      LOBYTE(v97) = 7;
      *((_DWORD *)&rteCage.TriangleMaterials + 6) = &COutputDetailOBJJob::`vftable';
      v64 = 0;
      v67 = 0;
      v68 = 0;
      v69 = 0;
      v70 = &DetailOBJJob_292[2168];
      v71 = 0;
      v65 = 0;
      v66 = 0;
      _V_memset(dest: v72, fill: 0, count: 260);
      LOBYTE(v97) = 8;
      COutputDetailOBJJob::Execute(
        this: (COutputDetailOBJJob *)((char *)&rteCage.TriangleMaterials + 24),
        pDependencyArray: nullptr);
      v15 = 0;
      *(float *)&v15 = (float)((float)(v79 * v79) + (float)(v80 * v80)) + (float)(*(float *)&pd3d9 * *(float *)&pd3d9);
      v16 = v15;
      *(float *)&v16 = fsqrt(*(float *)&v15);
      *(_OWORD *)fDetailTraceLength = v16;
      v2.x = *(float *)&v16 * 1.5;
      LOBYTE(v97) = 6;
    }
    RayTracingEnvironment::SetupAccelerationStructure(this: (RayTracingEnvironment *)&DetailOBJJob_292[2168]);
  }
  v33 = *(unsigned __int8 *)(_GetCPUInformation(a1: v97) + 6);
  ThreadPool = SchedulerCreateThreadPool();
  v35 = ThreadPool->__vftable;
  v36 = v33;
  if ( *(_DWORD *)&DetailOBJJob_292[576] != 0 )
    v36 = *(_DWORD *)&DetailOBJJob_292[576];
  v97 = v36;
  CreateSchedulerThreads = v35->CreateSchedulerThreads;
  NumDetailTriangles = (unsigned int)ThreadPool;
  CreateSchedulerThreads(this: ThreadPool, a2: v97);
  ThreadPool->SetPullGranularities(this: ThreadPool, a2: 10, a3: 5);
  v38 = operator new(nSize: 0x14u);
  if ( v38 != nullptr )
  {
    v38[1] = 0;
    *v38 = &CToggleSwitchJob::`vftable';
    v38[2] = 0;
    v38[3] = 0;
    *((_BYTE *)v38 + 16) = 0;
  }
  else
  {
    v38 = nullptr;
  }
  v39 = ThreadPool->__vftable;
  LODWORD(v2.y) = v38;
  autop4.m_spImpl.m_p = (CP4File *)v39->CreateScheduleJob(this: ThreadPool, a2: (CJob *)v38);
  p_m_pvDirections = nullptr;
  if ( DetailOBJJob_292[568] != 0 || __PAIR16__(DetailOBJJob_292[569], 0) != DetailOBJJob_292[573] )
  {
    v40 = (CUniformSampler *)operator new(nSize: 0xCu);
    if ( v40 != nullptr )
    {
      v40->m_pvDirections = nullptr;
      v40->m_NumSamples = 0;
      v40->m_NumVariations = 0;
    }
    else
    {
      v40 = nullptr;
    }
    p_m_pvDirections = (void **)&v40->m_pvDirections;
    CUniformSampler::InitSamples(
      this: v40,
      SqrtNumSamples: *(int *)&DetailOBJJob_292[544],
      NumVariations: *(int *)&DetailOBJJob_292[548]);
  }
  memset(fDetailTraceLength, 0, 12);
  LOBYTE(v97) = 10;
  i2 = 0;
  if ( *(int *)&fDetailTraceLength[20] > 0 )
  {
    pCageTriangleVerts = (Vector *)(28 * NumTextureTilesV);
    pd3dDevice = v87;
    do
    {
      v41 = nullptr;
      if ( NumTextureTilesV > 0 )
      {
        v42 = pd3dDevice;
        pd3dDevice = (IDirect3DDevice9 *)((char *)pd3dDevice + (_DWORD)pCageTriangleVerts);
        do
        {
          CreateJobsForTile(
            a1: (CacheEntry *)v42,
            a2: v41,
            pDevice: (IDirect3DDevice9 *)&rteDetail.TriangleMaterials.m_pElements,
            pThreadPool: (ISchedulerThreadPool *)v41,
            pSampler: (CUniformSampler *)&DetailOBJJob_292[2168],
            SubDMesh: (CSubDMesh *)&strFileName[252],
            objDetailLoader: (CObjLoader *)&vColor,
            rteCage: (RayTracingEnvironment *)&rteDetail.TriangleMaterials.m_pElements,
            rteDetail: (RayTracingEnvironment *)&DetailOBJJob_292[2168],
            fDetailTraceLength: v2.x,
            TileBuffers: (CTileBuffers *)v42,
            tu: (int)v41,
            tv: i2,
            CmdArgs: (SubDBakerArgs_t *)DetailOBJJob_292,
            JobList: (std::vector<CacheEntry *> *)fDetailTraceLength,
            pFenceScheduleJob: (IScheduleObject *)autop4.m_spImpl.m_p);
          v41 = (IScheduleObject *)((char *)v41 + 1);
          v42 += 7;
        }
        while ( (int)v41 < NumTextureTilesV );
      }
      ++i2;
    }
    while ( i2 < *(int *)&fDetailTraceLength[20] );
  }
  autop4.m_spImpl.m_p->__vftable[4].Add(this: autop4.m_spImpl.m_p);
  v43 = (int *)NumDetailTriangles;
  v44 = (Vector *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)NumDetailTriangles + 88))(a1: NumDetailTriangles);
  x = v44->x;
  pCageTriangleVerts = v44;
  v46 = (*(int (__thiscall **)(Vector *))(LODWORD(x) + 48))(a1: v44);
  v47 = *v43;
  *(_DWORD *)&fDetailTraceLength[20] = v46;
  v48 = 0;
  (*(void (__thiscall **)(int *))(v47 + 24))(a1: v43);
  printf(format: "Generating texture maps...\n");
  if ( *(_BYTE *)(LODWORD(v2.y) + 16) == 0 )
  {
    *(float *)&fDetailTraceLength[20] = (float)*(int *)&fDetailTraceLength[20];
    do
    {
      v49 = (*(int (__thiscall **)(Vector *))(LODWORD(pCageTriangleVerts->x) + 48))(a1: pCageTriangleVerts);
      v50 = (int)(float)((float)(1.0 - (float)((float)v49 / *(float *)&fDetailTraceLength[20])) * 80.0);
      if ( v50 > v48 )
      {
        if ( v50 - v48 > 0 )
        {
          v51 = v50 - v48;
          do
          {
            printf(format: "|");
            --v51;
          }
          while ( v51 != 0 );
        }
        v48 = v50;
      }
      Sleep(dwMilliseconds: 0x14u);
    }
    while ( *(_BYTE *)(LODWORD(v2.y) + 16) == 0 );
  }
  printf(format: "\n");
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)NumDetailTriangles + 28))(a1: NumDetailTriangles);
  if ( DetailOBJJob_292[572] != 0 )
  {
    V_StripExtension(in: DetailOBJJob_292, out: &v71, outSize: 260);
    sprintf_s(string: v57, sizeInBytes: 0x104u, format: "%s_HighDisp.obj", &v71);
    COutputDetailOBJJob::COutputDetailOBJJob(
      this: (COutputDetailOBJJob *)&strScratch[252],
      pSubDMesh: (CSubDMesh *)&strFileName[252],
      pTileBuffers: (CTileBuffers *)v87,
      Width: *(int *)&DetailOBJJob_292[520],
      Height: *(int *)&DetailOBJJob_292[524],
      NumTilesU: NumTextureTilesV,
      pszFileName: v57,
      prteDetail: nullptr,
      bRemoveRedundancies: true);
    COutputDetailOBJJob::Execute(
      this: (COutputDetailOBJJob *)&strScratch[252],
      pDependencyArray: (CUtlVector<IScheduleObject *,CUtlMemory<IScheduleObject *,int> > *)0xB);
    LOBYTE(v97) = 10;
    *(_DWORD *)&strScratch[252] = &CJob::`vftable';
  }
  v52 = 0;
  v53 = (*(_DWORD *)&fDetailTraceLength[4] - *(_DWORD *)fDetailTraceLength) >> 2;
  if ( v53 > 0 )
  {
    do
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)fDetailTraceLength + 4 * v52) + 4))(a1: *(_DWORD *)(*(_DWORD *)fDetailTraceLength + 4 * v52));
      ++v52;
    }
    while ( v52 < v53 );
  }
  autop4.m_spImpl.m_p->Edit(this: autop4.m_spImpl.m_p);
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)NumDetailTriangles + 4))(a1: NumDetailTriangles);
  if ( v87 != nullptr )
  {
    v54 = v87 - 1;
    `eh vector destructor iterator'(
      ptr: v87,
      size: 0x1Cu,
      count: (int)v87[-1].__vftable,
      pDtor: (void (__thiscall *)(void *))CTileBuffers::~CTileBuffers);
    free(pMem: v54);
  }
  CSubDMesh::Destroy(this: (CSubDMesh *)&strFileName[252]);
  v55 = p_m_pvDirections;
  if ( p_m_pvDirections != nullptr )
  {
    if ( *p_m_pvDirections != nullptr )
      free(pMem: *p_m_pvDirections);
    free(pMem: v55);
  }
  (*(void (__cdecl **)(int))(*(_DWORD *)NumTextureTilesU + 8))(a1: NumTextureTilesU);
  (*(void (__stdcall **)(ObjLoadFlags_t))(*(_DWORD *)detailLoader.m_LoadFlags + 8))(a1: detailLoader.m_LoadFlags);
  if ( p4 != nullptr )
  {
    p4->Shutdown(this: p4);
    p4->Disconnect(this: p4);
  }
  v56 = _Plat_FloatTime(a1: v97, a2: v98[0]);
  v2.z = v56 - v2.z;
  printf(
    format: "Elapsed Time: %d:%02d\n",
    (int)(float)(v2.z * 0.016666668),
    (int)(float)(v2.z - (float)((float)(int)(float)(v2.z * 0.016666668) * 60.0)));
  if ( *(_DWORD *)fDetailTraceLength != 0 )
    free(pMem: *(void **)fDetailTraceLength);
  RayTracingEnvironment::~RayTracingEnvironment(this: (RayTracingEnvironment *)&DetailOBJJob_292[2168]);
  if ( detailLoader.m_Indices._Mylast != nullptr )
    free(pMem: detailLoader.m_Indices._Mylast);
  memset(&detailLoader.m_Indices._Mylast, 0, 12);
  if ( detailLoader.m_Vertices._Mylast != nullptr )
    free(pMem: detailLoader.m_Vertices._Mylast);
  memset(&detailLoader.m_Vertices._Mylast, 0, 12);
  if ( LODWORD(vColor.x) != 0 )
    free(pMem: (void *)LODWORD(vColor.x));
  memset(&vColor, 0, sizeof(vColor));
  RayTracingEnvironment::~RayTracingEnvironment(this: (RayTracingEnvironment *)&rteDetail.TriangleMaterials.m_pElements);
  v97 = -1;
  CSubDMesh::~CSubDMesh(this: (CSubDMesh *)&strFileName[252]);
  return 0;
}
