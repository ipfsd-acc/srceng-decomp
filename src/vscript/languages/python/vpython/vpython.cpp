// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/python/vpython/vpython.cpp
// Functions: 363
// ============================================================

#include "vscript\languages\python\vpython\vpython.h"

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: VectorRelease
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorRelease(_object *pSelf)
{
  if ( pSelf[1].ob_type != nullptr )
  {
    free(pMem: pSelf[1].ob_type);
    --DEBUG_VECCOUNT;
  }
  pSelf->ob_type->tp_free(a1: pSelf);
}

//------------------------------------------------------------------------------
// Address: 0x10001130
// Name: VectorConstructNew
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorConstructNew(_object *pSelf, _object *pArgs)
{
  _typeobject *v2; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float z; // [esp+4h] [ebp-Ch] BYREF
  float x; // [esp+8h] [ebp-8h] BYREF
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  z = 0.0;
  x = 0.0;
  if ( pArgs != nullptr )
    _PyArg_ParseTuple(a1: pArgs, a2: "|fff", a3: &v8, a4: &z, a5: &x);
  v2 = (_typeobject *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
  {
    v3 = z;
    v4 = x;
    v2->ob_refcnt = v8;
    *(float *)&v2->ob_type = v3;
    *(float *)&v2->ob_size = v4;
  }
  else
  {
    v2 = nullptr;
  }
  ++DEBUG_VECCOUNT;
  pSelf[1].ob_type = v2;
  pSelf[1].ob_refcnt = 91919191;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: VectorGet
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorGet(_object *pSelf, _object *pname)
{
  _typeobject *ob_type; // eax
  _object *result; // eax
  _typeobject *v4; // esi
  char *v5; // eax
  int v6; // eax

  ob_type = pname->ob_type;
  if ( ob_type == (_typeobject *)_PyString_Type.ob_refcnt
    || (result = (_object *)_PyType_IsSubtype(a1: ob_type, a2: _PyString_Type.ob_refcnt)) != nullptr )
  {
    v4 = pSelf[1].ob_type;
    if ( v4 != nullptr )
    {
      v5 = (char *)_PyString_AsString(a1: pname);
      if ( v5 != nullptr && *v5 != 0 && v5[1] == 0 && (unsigned int)(v6 = *v5 - 120) <= 2 )
        return (_object *)_PyFloat_FromDouble(
                            a1: COERCE_UNSIGNED_INT64(*((float *)&v4->ob_refcnt + v6)),
                            a2: HIDWORD(COERCE_UNSIGNED_INT64(*((float *)&v4->ob_refcnt + v6))));
      else
        return (_object *)_PyObject_GenericGetAttr(a1: pSelf, a2: pname);
    }
    else
    {
      _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: VectorSet
// Source: json
//------------------------------------------------------------------------------
int __cdecl VectorSet(_object *pSelf, _object *pname, _object *pval)
{
  _typeobject *ob_type; // eax
  _typeobject *v5; // edi
  char *v6; // eax
  unsigned int v7; // esi

  ob_type = pname->ob_type;
  if ( ob_type != (_typeobject *)_PyString_Type.ob_refcnt
    && _PyType_IsSubtype(a1: ob_type, a2: _PyString_Type.ob_refcnt) == 0 )
  {
    return -1;
  }
  v5 = pSelf[1].ob_type;
  if ( v5 == nullptr )
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return -1;
  }
  v6 = (char *)_PyString_AsString(a1: pname);
  if ( v6 == nullptr )
    return -1;
  if ( *v6 == 0 )
    return -1;
  if ( v6[1] != 0 )
    return -1;
  v7 = *v6 - 120;
  if ( v7 > 2 )
    return -1;
  *((float *)&v5->ob_refcnt + v7) = _PyFloat_AsDouble(a1: pval);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100012F0
// Name: VectorLength
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorLength(_object *pSelf)
{
  float *p_ob_refcnt; // eax
  double v3; // xmm0_8

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt != nullptr )
  {
    v3 = fsqrt(
           (float)((float)(*p_ob_refcnt * *p_ob_refcnt) + (float)(p_ob_refcnt[1] * p_ob_refcnt[1]))
         + (float)(p_ob_refcnt[2] * p_ob_refcnt[2]));
    return (_object *)_PyFloat_FromDouble(a1: LODWORD(v3), a2: HIDWORD(v3));
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001380
// Name: VectorLengthSqr
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorLengthSqr(_object *pSelf)
{
  float *p_ob_refcnt; // eax
  double v3; // xmm0_8

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt != nullptr )
  {
    v3 = (float)((float)((float)(*p_ob_refcnt * *p_ob_refcnt) + (float)(p_ob_refcnt[1] * p_ob_refcnt[1]))
               + (float)(p_ob_refcnt[2] * p_ob_refcnt[2]));
    return (_object *)_PyFloat_FromDouble(a1: LODWORD(v3), a2: HIDWORD(v3));
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100013F0
// Name: VectorLength2D
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorLength2D(_object *pSelf)
{
  float *p_ob_refcnt; // eax
  double v3; // xmm0_8

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt != nullptr )
  {
    v3 = fsqrt((float)(*p_ob_refcnt * *p_ob_refcnt) + (float)(p_ob_refcnt[1] * p_ob_refcnt[1]));
    return (_object *)_PyFloat_FromDouble(a1: LODWORD(v3), a2: HIDWORD(v3));
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001470
// Name: VectorLength2DSqr
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorLength2DSqr(_object *pSelf)
{
  float *p_ob_refcnt; // eax
  double v3; // xmm0_8

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt != nullptr )
  {
    v3 = (float)((float)(*p_ob_refcnt * *p_ob_refcnt) + (float)(p_ob_refcnt[1] * p_ob_refcnt[1]));
    return (_object *)_PyFloat_FromDouble(a1: LODWORD(v3), a2: HIDWORD(v3));
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100014D0
// Name: VectorDot
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorDot(_object *pSelf, _object *pOther)
{
  float *p_ob_refcnt; // ecx
  float *v3; // eax
  double v4; // xmm0_8

  p_ob_refcnt = (float *)&pOther[1].ob_type->ob_refcnt;
  v3 = (float *)&pSelf[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt != nullptr && v3 != nullptr )
  {
    v4 = (float)((float)((float)(p_ob_refcnt[2] * v3[2]) + (float)(p_ob_refcnt[1] * v3[1])) + (float)(*p_ob_refcnt * *v3));
    return (_object *)_PyFloat_FromDouble(a1: LODWORD(v4), a2: HIDWORD(v4));
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001540
// Name: VectorNorm
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorNorm(_object *pSelf)
{
  unsigned __int64 v2; // st7

  if ( pSelf[1].ob_type != nullptr )
  {
    *(double *)&v2 = VectorNormalize(vec: (Vector *)pSelf[1].ob_type);
    return (_object *)_PyFloat_FromDouble(a1: v2, a2: HIDWORD(v2));
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: struct _object __near * CreatePyVector(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl CreatePyVector(Vector *pVector)
{
  int v1; // esi
  Vector *v2; // eax

  v1 = _PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
  v2 = pVector;
  if ( pVector == nullptr )
  {
    v2 = (Vector *)operator new(nSize: 0xCu);
    if ( v2 != nullptr )
    {
      v2->x = 0.0;
      v2->y = 0.0;
      v2->z = 0.0;
    }
    else
    {
      v2 = nullptr;
    }
    ++DEBUG_VECCOUNT;
  }
  *(_DWORD *)(v1 + 12) = v2;
  *(_DWORD *)(v1 + 8) = 91919191;
  return (_object *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10001600
// Name: bool RegisterVector(struct _object __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RegisterVector(_object *pmodule)
{
  if ( _PyType_Ready(a1: &PyTypeVector) < 0 )
    return 0;
  ++PyTypeVector.ob_refcnt;
  _PyModule_AddObject(a1: pmodule, a2: "Vector", a3: &PyTypeVector);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001640
// Name: vprint
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl vprint(_object *self, _object *args)
{
  int v2; // ecx
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = v2;
  if ( ((int (__cdecl *)(_object *, const char *, int *))_PyArg_ParseTuple)(a1: args, a2: "s", a3: &v4) != 0 )
    _Msg(a1: v4);
  else
    DevMsg(a1: "vpython.cpp, vprint error: bad argument?");
  return _Py_BuildValue(a1: "i", a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100016A0
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // edi
  _DWORD *v1; // ebx
  int (__thiscall **v2)(_DWORD *, const char *, int); // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v0 = _CommandLine();
  v1 = (_DWORD *)_CommandLine();
  v2 = (int (__thiscall **)(_DWORD *, const char *, int))(*v1 + 32);
  v3 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v0 + 32))(
         a1: v0,
         a2: "-defaultgamedir",
         a3: "hl2");
  v4 = (const char *)(*v2)(a1: v1, a2: "-game", a3: v3);
  V_strncpy(pDest: modDir, pSrc: v4, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v6 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v7 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v4[v7], maxLen: 260 - v7);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x10001770
// Name: char const __near * COM_GetGamePath(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall COM_GetGamePath(void *this)
{
  char *ModDirectory; // eax
  void *pSrc; // [esp+4h] [ebp-4h] BYREF

  pSrc = this;
  if ( _V_strlen(str: gamePath) == 0 )
  {
    LOWORD(pSrc) = 92;
    V_GetCurrentDirectory(pOut: gamePath, maxLen: 260);
    V_strncat(pDest: gamePath, (const char *)&pSrc, destBufferSize: 0x104u, max_chars_to_copy: -1);
    ModDirectory = COM_GetModDirectory();
    V_strncat(pDest: gamePath, pSrc: ModDirectory, destBufferSize: 0x104u, max_chars_to_copy: -1);
  }
  return gamePath;
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: gamepath
// Source: json
//------------------------------------------------------------------------------
_object *__thiscall gamepath(void *this)
{
  char *GamePath; // eax

  GamePath = COM_GetGamePath(this);
  return _PyString_FromString(a1: GamePath);
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: ReplaceClosures
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl ReplaceClosures(_object *self, _object *args)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // eax
  _DWORD *v6; // edi
  const char *pszModuleName; // [esp+4h] [ebp-Ch] BYREF
  _object *pSelf; // [esp+8h] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( _PyArg_ParseTuple(a1: args, a2: "OsO", a3: v10, a4: &pSelf, a5: &pszModuleName) != 0 )
  {
    v3 = _PyImport_AddModule(a1: pSelf);
    v4 = (_DWORD *)v3;
    if ( v3 != 0 )
    {
      v5 = _PyImport_ReloadModule(a1: v3);
      v6 = (_DWORD *)v5;
      if ( v5 != 0 )
      {
        if ( pszModuleName != nullptr && v4 != (_DWORD *)v5 )
        {
          if ( (*v4)-- == 1 )
            (*(void (__cdecl **)(_DWORD *))(v4[1] + 24))(a1: v4);
          *((_DWORD *)pszModuleName + 1) = v6;
          if ( v6 != nullptr )
            ++*v6;
        }
        return _Py_BuildValue(a1: "i", a2: 0);
      }
      else
      {
        DevMsg(a1: "vpython.cpp, ReplaceClosures error: module failed to reload!");
        return _Py_BuildValue(a1: "i", a2: 0);
      }
    }
    else
    {
      DevMsg(a1: "vpython.cpp, ReplaceClosures error: module was never previously loaded!");
      return _Py_BuildValue(a1: "i", a2: 0);
    }
  }
  else
  {
    DevMsg(a1: "vpython.cpp, ReplaceClosures argument error!");
    return _Py_BuildValue(a1: "i", a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100018E0
// Name: VectorFromAngles
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorFromAngles(_object *self, _object *args)
{
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // eax
  float fyaw; // [esp+Ch] [ebp-24h] BYREF
  float froll; // [esp+10h] [ebp-20h] BYREF
  QAngle angles; // [esp+14h] [ebp-1Ch] BYREF
  Vector forward; // [esp+20h] [ebp-10h] BYREF
  int v10; // [esp+2Ch] [ebp-4h]

  if ( _PyArg_ParseTuple(a1: args, a2: "|fff", a3: &fyaw, a4: &froll, a5: &angles) != 0 )
  {
    v3 = _PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
    v4 = operator new(nSize: 0xCu);
    if ( v4 != nullptr )
    {
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    ++DEBUG_VECCOUNT;
    *(_DWORD *)(v3 + 12) = v4;
    *(_DWORD *)(v3 + 8) = 91919191;
    angles.y = fyaw;
    angles.z = froll;
    forward.x = angles.x;
    AngleVectors(angles: (QAngle *)&angles.y, forward: (Vector *)&forward.y);
    v5 = *(_DWORD *)(v3 + 12);
    *(float *)v5 = forward.y;
    *(float *)(v5 + 4) = forward.z;
    *(_DWORD *)(v5 + 8) = v10;
    return (_object *)v3;
  }
  else
  {
    DevMsg(a1: "vpython.cpp: invalid params to VectorFromAngles, expected 3 floats!");
    return _Py_BuildValue(a1: "i", a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A00
// Name: AnglesFromVector
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl AnglesFromVector(_object *self, _object *args)
{
  int v3; // eoff
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  _DWORD *v6; // edi
  int v7; // ebp
  bool v8; // zf
  QAngle angles; // [esp+18h] [ebp-1Ch] BYREF
  Vector forward; // [esp+24h] [ebp-10h] BYREF
  int v11; // [esp+30h] [ebp-4h]

  if ( ((int (__cdecl *)(_object *, const char *, QAngle *))_PyArg_ParseTuple)(a1: args, a2: "|O", a3: &angles) != 0 )
  {
    v3 = *(_DWORD *)(LODWORD(angles.x) + 12);
    *(_QWORD *)&forward.y = *(_QWORD *)v3;
    v11 = *(_DWORD *)(v3 + 8);
    VectorAngles(forward: (Vector *)&forward.y, angles: (QAngle *)&angles.y);
    v4 = (_DWORD *)_PyFloat_FromDouble(
                     a1: COERCE_UNSIGNED_INT64(angles.y),
                     a2: HIDWORD(COERCE_UNSIGNED_INT64(angles.y)));
    v5 = (_DWORD *)_PyFloat_FromDouble(
                     a1: COERCE_UNSIGNED_INT64(angles.z),
                     a2: HIDWORD(COERCE_UNSIGNED_INT64(angles.z)));
    v6 = (_DWORD *)_PyFloat_FromDouble(
                     a1: COERCE_UNSIGNED_INT64(forward.x),
                     a2: HIDWORD(COERCE_UNSIGNED_INT64(forward.x)));
    v7 = _PyTuple_Pack(a1: 3, a2: v4, a3: v5, a4: v6);
    if ( v4 != nullptr )
    {
      v8 = (*v4)-- == 1;
      if ( v8 )
        (*(void (__cdecl **)(_DWORD *))(v4[1] + 24))(a1: v4);
    }
    if ( v5 != nullptr )
    {
      v8 = (*v5)-- == 1;
      if ( v8 )
        (*(void (__cdecl **)(_DWORD *))(v5[1] + 24))(a1: v5);
    }
    if ( v6 != nullptr )
    {
      v8 = (*v6)-- == 1;
      if ( v8 )
        (*(void (__cdecl **)(_DWORD *))(v6[1] + 24))(a1: v6);
    }
    return (_object *)v7;
  }
  else
  {
    DevMsg(a1: "vpython.cpp: invalid params to AnglesFromVector, expected 1 vector");
    return _Py_BuildValue(a1: "i", a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B00
// Name: VectorsFromAngles
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorsFromAngles(_object *self, _object *args)
{
  _DWORD *v3; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  int v14; // ebp
  float fyaw; // [esp+Ch] [ebp-3Ch] BYREF
  float froll; // [esp+10h] [ebp-38h] BYREF
  QAngle angles; // [esp+14h] [ebp-34h] BYREF
  Vector forward; // [esp+20h] [ebp-28h] BYREF
  Vector right; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector up; // [esp+38h] [ebp-10h] BYREF
  int v21; // [esp+44h] [ebp-4h]

  if ( _PyArg_ParseTuple(a1: args, a2: "|fff", a3: &fyaw, a4: &froll, a5: &angles) != 0 )
  {
    v3 = (_DWORD *)_PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
    v4 = operator new(nSize: 0xCu);
    if ( v4 != nullptr )
    {
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    ++DEBUG_VECCOUNT;
    v3[3] = v4;
    v3[2] = 91919191;
    v5 = (_DWORD *)_PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
    v6 = operator new(nSize: 0xCu);
    if ( v6 != nullptr )
    {
      *v6 = 0;
      v6[1] = 0;
      v6[2] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    ++DEBUG_VECCOUNT;
    v5[3] = v6;
    v5[2] = 91919191;
    v7 = (_DWORD *)_PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
    v8 = operator new(nSize: 0xCu);
    if ( v8 != nullptr )
    {
      *v8 = 0;
      v8[1] = 0;
      v8[2] = 0;
    }
    else
    {
      v8 = nullptr;
    }
    ++DEBUG_VECCOUNT;
    v7[3] = v8;
    v7[2] = 91919191;
    angles.y = fyaw;
    angles.z = froll;
    forward.x = angles.x;
    AngleVectors(
      angles: (QAngle *)&angles.y,
      forward: (Vector *)&forward.y,
      right: (Vector *)&right.y,
      up: (Vector *)&up.y);
    v9 = (float *)v3[3];
    *v9 = forward.y;
    v9[1] = forward.z;
    v9[2] = right.x;
    v10 = (float *)v5[3];
    *v10 = right.y;
    v10[1] = right.z;
    v10[2] = up.x;
    v11 = v7[3];
    *(float *)v11 = up.y;
    *(float *)(v11 + 4) = up.z;
    *(_DWORD *)(v11 + 8) = v21;
    v12 = _PyTuple_Pack(a1: 3, a2: v3, a3: v5, a4: v7);
    v13 = (*v3)-- == 1;
    v14 = v12;
    if ( v13 )
      (*(void (__cdecl **)(_DWORD *))(v3[1] + 24))(a1: v3);
    v13 = (*v5)-- == 1;
    if ( v13 )
      (*(void (__cdecl **)(_DWORD *))(v5[1] + 24))(a1: v5);
    v13 = (*v7)-- == 1;
    if ( v13 )
      (*(void (__cdecl **)(_DWORD *))(v7[1] + 24))(a1: v7);
    return (_object *)v14;
  }
  else
  {
    DevMsg(a1: "vpython.cpp: invalid params to VectorFromAngles, expected 3 floats!");
    return _Py_BuildValue(a1: "i", a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D70
// Name: CatmullRomSpline
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl CatmullRomSpline(_object *self, _object *args)
{
  _typeobject *ob_type; // eax
  float *p_ob_refcnt; // eax
  float *v5; // eax
  float *v6; // eax
  int v7; // esi
  _DWORD *v8; // eax
  int v9; // xmm0_4
  int v10; // xmm1_4
  float *v11; // eax
  _object *pyv2; // [esp+Ch] [ebp-5Ch] BYREF
  _object *pyv3; // [esp+10h] [ebp-58h] BYREF
  _object *pyv4; // [esp+14h] [ebp-54h] BYREF
  int v15; // [esp+18h] [ebp-50h]
  int v16; // [esp+1Ch] [ebp-4Ch]
  int v17; // [esp+20h] [ebp-48h]
  float t; // [esp+24h] [ebp-44h]
  Vector output; // [esp+28h] [ebp-40h] BYREF
  Vector p4; // [esp+34h] [ebp-34h] BYREF
  Vector p3; // [esp+40h] [ebp-28h] BYREF
  Vector p2; // [esp+4Ch] [ebp-1Ch] BYREF
  Vector p1; // [esp+58h] [ebp-10h] BYREF
  int ob_size; // [esp+64h] [ebp-4h]

  if ( _PyArg_ParseTuple(a1: args, a2: "|OOOOf", a3: &pyv2, a4: &pyv3, a5: &pyv4) != 0 )
  {
    ob_type = pyv2[1].ob_type;
    LODWORD(p1.y) = ob_type->ob_refcnt;
    LODWORD(p1.z) = ob_type->ob_type;
    ob_size = ob_type->ob_size;
    p_ob_refcnt = (float *)&pyv3[1].ob_type->ob_refcnt;
    p2.y = *p_ob_refcnt;
    p2.z = p_ob_refcnt[1];
    p1.x = p_ob_refcnt[2];
    v5 = (float *)&pyv4[1].ob_type->ob_refcnt;
    p3.y = *v5;
    p3.z = v5[1];
    p2.x = v5[2];
    v6 = *(float **)(v15 + 12);
    p4.y = *v6;
    p4.z = v6[1];
    p3.x = v6[2];
    v7 = _PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
    t = 0.0;
    v16 = 0;
    v17 = 0;
    v8 = operator new(nSize: 0xCu);
    if ( v8 != nullptr )
    {
      v9 = v16;
      v10 = v17;
      *v8 = LODWORD(t);
      v8[1] = v9;
      v8[2] = v10;
    }
    else
    {
      v8 = nullptr;
    }
    ++DEBUG_VECCOUNT;
    *(_DWORD *)(v7 + 12) = v8;
    *(_DWORD *)(v7 + 8) = 91919191;
    output.y = 0.0;
    output.z = 0.0;
    p4.x = 0.0;
    Catmull_Rom_Spline(
      p1: (Vector *)&p1.y,
      p2: (Vector *)&p2.y,
      p3: (Vector *)&p3.y,
      p4: (Vector *)&p4.y,
      t: output.x,
      output: (Vector *)&output.y);
    v11 = *(float **)(v7 + 12);
    *v11 = output.y;
    v11[1] = output.z;
    v11[2] = p4.x;
    return (_object *)v7;
  }
  else
  {
    DevMsg(a1: "vpython.cpp: invalid params to Catmull_Rom_Spline, expected 4 vectors and 1 float!");
    return _Py_BuildValue(a1: "i", a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: HermiteSpline
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl HermiteSpline(_object *self, _object *args)
{
  _typeobject *ob_type; // eax
  float *p_ob_refcnt; // eax
  float *v5; // eax
  float *v6; // eax
  int v7; // esi
  _DWORD *v8; // eax
  int v9; // xmm0_4
  int v10; // xmm1_4
  float *v11; // eax
  _object *pyv2; // [esp+Ch] [ebp-5Ch] BYREF
  _object *pyv3; // [esp+10h] [ebp-58h] BYREF
  _object *pyv4; // [esp+14h] [ebp-54h] BYREF
  int v15; // [esp+18h] [ebp-50h]
  int v16; // [esp+1Ch] [ebp-4Ch]
  int v17; // [esp+20h] [ebp-48h]
  float t; // [esp+24h] [ebp-44h]
  Vector output; // [esp+28h] [ebp-40h] BYREF
  Vector d2; // [esp+34h] [ebp-34h] BYREF
  Vector d1; // [esp+40h] [ebp-28h] BYREF
  Vector p2; // [esp+4Ch] [ebp-1Ch] BYREF
  Vector p1; // [esp+58h] [ebp-10h] BYREF
  int ob_size; // [esp+64h] [ebp-4h]

  if ( _PyArg_ParseTuple(a1: args, a2: "|OOOOf", a3: &pyv2, a4: &pyv3, a5: &pyv4) != 0 )
  {
    ob_type = pyv2[1].ob_type;
    LODWORD(p1.y) = ob_type->ob_refcnt;
    LODWORD(p1.z) = ob_type->ob_type;
    ob_size = ob_type->ob_size;
    p_ob_refcnt = (float *)&pyv3[1].ob_type->ob_refcnt;
    p2.y = *p_ob_refcnt;
    p2.z = p_ob_refcnt[1];
    p1.x = p_ob_refcnt[2];
    v5 = (float *)&pyv4[1].ob_type->ob_refcnt;
    d1.y = *v5;
    d1.z = v5[1];
    p2.x = v5[2];
    v6 = *(float **)(v15 + 12);
    d2.y = *v6;
    d2.z = v6[1];
    d1.x = v6[2];
    v7 = _PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
    t = 0.0;
    v16 = 0;
    v17 = 0;
    v8 = operator new(nSize: 0xCu);
    if ( v8 != nullptr )
    {
      v9 = v16;
      v10 = v17;
      *v8 = LODWORD(t);
      v8[1] = v9;
      v8[2] = v10;
    }
    else
    {
      v8 = nullptr;
    }
    ++DEBUG_VECCOUNT;
    *(_DWORD *)(v7 + 12) = v8;
    *(_DWORD *)(v7 + 8) = 91919191;
    output.y = 0.0;
    output.z = 0.0;
    d2.x = 0.0;
    Hermite_Spline(
      p1: (Vector *)&p1.y,
      p2: (Vector *)&p2.y,
      d1: (Vector *)&d1.y,
      d2: (Vector *)&d2.y,
      t: output.x,
      output: (Vector *)&output.y);
    v11 = *(float **)(v7 + 12);
    *v11 = output.y;
    v11[1] = output.z;
    v11[2] = d2.x;
    return (_object *)v7;
  }
  else
  {
    DevMsg(a1: "vpython.cpp: invalid params to HermiteSpline, expected 4 vectors and 1 float!");
    return _Py_BuildValue(a1: "i", a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100020F0
// Name: HermiteSplineFloat
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl HermiteSplineFloat(_object *self, _object *args)
{
  double v3; // st7
  float d2; // [esp+14h] [ebp-14h]
  float d1; // [esp+18h] [ebp-10h]
  float p2; // [esp+1Ch] [ebp-Ch] BYREF
  float p1; // [esp+20h] [ebp-8h] BYREF
  float v8; // [esp+24h] [ebp-4h] BYREF

  if ( _PyArg_ParseTuple(a1: args, a2: "|fffff", a3: &v8, a4: &p1, a5: &p2) != 0 )
  {
    v3 = Hermite_Spline(p1: v8, p2: p1, d1: p2, d2: d1, t: d2);
    return _Py_BuildValue(a1: "f", a2: LODWORD(v3));
  }
  else
  {
    DevMsg(a1: "vpython.cpp: invalid params to HermiteSplineFloat, expected 5 floats!");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002180
// Name: ExactTime
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl ExactTime()
{
  unsigned __int64 v0; // st7

  *(double *)&v0 = _Plat_FloatTime();
  return (_object *)_PyFloat_FromDouble(a1: v0, a2: HIDWORD(v0));
}

//------------------------------------------------------------------------------
// Address: 0x100021A0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x100021B0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pBlocks; // eax
  bool v6; // zf

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)operator new(nSize: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v6 = this->m_pBlocks == nullptr;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( v6 )
    {
      this->m_pBlocks = v4;
    }
    else
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002240
// Name: VectorAdd
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorAdd(_object *pSelf, _object *pOther)
{
  float *p_ob_refcnt; // edi
  float *v3; // esi
  _object *result; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float *v7; // ecx

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  v3 = (float *)&pOther[1].ob_type->ob_refcnt;
  if ( v3 != nullptr && p_ob_refcnt != nullptr )
  {
    if ( pOther->ob_type == &PyTypeVector )
    {
      result = CreatePyVector(pVector: nullptr);
      v5 = v3[1] + p_ob_refcnt[1];
      v6 = v3[2] + p_ob_refcnt[2];
      v7 = (float *)&result[1].ob_type->ob_refcnt;
      *v7 = *v3 + *p_ob_refcnt;
      v7[1] = v5;
      v7[2] = v6;
    }
    else
    {
      _PyErr_SetString(a1: _PyExc_ValueError, a2: "can't add vector to non vector type");
      return nullptr;
    }
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100022E0
// Name: VectorSubtract
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorSubtract(_object *pSelf, _object *pOther)
{
  float *p_ob_refcnt; // edi
  float *v3; // esi
  _object *result; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float *v7; // ecx

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  v3 = (float *)&pOther[1].ob_type->ob_refcnt;
  if ( v3 != nullptr && p_ob_refcnt != nullptr )
  {
    if ( pOther->ob_type == &PyTypeVector )
    {
      result = CreatePyVector(pVector: nullptr);
      v5 = p_ob_refcnt[1] - v3[1];
      v6 = p_ob_refcnt[2] - v3[2];
      v7 = (float *)&result[1].ob_type->ob_refcnt;
      *v7 = *p_ob_refcnt - *v3;
      v7[1] = v5;
      v7[2] = v6;
    }
    else
    {
      _PyErr_SetString(a1: _PyExc_ValueError, a2: "can't sub non vector type from vector");
      return nullptr;
    }
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002380
// Name: VectorScale
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorScale(_object *pSelf, _object *pScale)
{
  _object *v2; // esi
  _object *v3; // eax
  float *p_ob_refcnt; // edi
  _typeobject *ob_type; // eax
  int v7; // esi
  float *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // [esp+10h] [ebp-4h]

  v2 = pSelf;
  if ( pSelf[1].ob_refcnt == 91919191 )
  {
    v3 = pSelf;
    v2 = pScale;
  }
  else
  {
    v3 = pScale;
  }
  p_ob_refcnt = (float *)&v3[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt != nullptr )
  {
    ob_type = v2->ob_type;
    if ( ob_type == (_typeobject *)_PyFloat_Type.ob_refcnt
      || _PyType_IsSubtype(a1: ob_type, a2: _PyFloat_Type.ob_refcnt) != 0 )
    {
      v11 = _PyFloat_AsDouble(a1: v2);
      v7 = _PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
      v8 = (float *)operator new(nSize: 0xCu);
      if ( v8 != nullptr )
      {
        *v8 = 0.0;
        v8[1] = 0.0;
        v8[2] = 0.0;
      }
      else
      {
        v8 = nullptr;
      }
      ++DEBUG_VECCOUNT;
      *(_DWORD *)(v7 + 12) = v8;
      *(_DWORD *)(v7 + 8) = 91919191;
      v9 = p_ob_refcnt[1] * v11;
      v10 = p_ob_refcnt[2] * v11;
      *v8 = *p_ob_refcnt * v11;
      v8[1] = v9;
      v8[2] = v10;
      return (_object *)v7;
    }
    else
    {
      _PyErr_SetString(a1: _PyExc_ValueError, a2: "can't scale vector by non float type");
      return nullptr;
    }
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100024B0
// Name: VectorCross
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorCross(_object *pSelf, _object *pOther)
{
  float *p_ob_refcnt; // esi
  float *v3; // edi
  int v4; // ebx
  float *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm0_4

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  v3 = (float *)&pOther[1].ob_type->ob_refcnt;
  if ( v3 != nullptr && p_ob_refcnt != nullptr )
  {
    v4 = _PyType_GenericNew(a1: &PyTypeVector, a2: 0, a3: 0);
    v5 = (float *)operator new(nSize: 0xCu);
    if ( v5 != nullptr )
    {
      *v5 = 0.0;
      v5[1] = 0.0;
      v5[2] = 0.0;
    }
    else
    {
      v5 = nullptr;
    }
    ++DEBUG_VECCOUNT;
    *(_DWORD *)(v4 + 12) = v5;
    *(_DWORD *)(v4 + 8) = 91919191;
    v6 = v3[2];
    v7 = v3[1];
    v8 = (float)(*v3 * p_ob_refcnt[2]) - (float)(*p_ob_refcnt * v6);
    v9 = (float)(*p_ob_refcnt * v7) - (float)(*v3 * p_ob_refcnt[1]);
    *v5 = (float)(p_ob_refcnt[1] * v6) - (float)(p_ob_refcnt[2] * v7);
    v5[1] = v8;
    v5[2] = v9;
    return (_object *)v4;
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100025C0
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+14h] [ebp+Ch] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  LOBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this);
  v4 = (_BYTE)this == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10002630
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::First(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::First(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *result)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v4; // 0:^0.8

  if ( this->m_pBlocks != nullptr )
  {
    v4.m_pBlockHeader = this->m_pBlocks;
    v4.m_nIndex = 0;
  }
  else
  {
    v4.m_pBlockHeader = nullptr;
    v4.m_nIndex = -1;
  }
  *(CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *)result = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002670
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100026F0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10002770
// Name: VectorToString
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorToString(_object *pSelf)
{
  float *p_ob_refcnt; // eax
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+18h] [ebp-10Ch] BYREF

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt == nullptr )
    return _PyString_FromString(a1: "<Vector : null>");
  v3 = CFmtStrN<256>::CFmtStrN<256>(
         this: &v4,
         pszFormat: "<Vector: %f %f %f>",
         *p_ob_refcnt,
         p_ob_refcnt[1],
         p_ob_refcnt[2]);
  return _PyString_FromString(a1: v3->m_szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x100027E0
// Name: VectorToKeyValueString
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl VectorToKeyValueString(_object *pSelf)
{
  float *p_ob_refcnt; // eax
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+18h] [ebp-10Ch] BYREF

  p_ob_refcnt = (float *)&pSelf[1].ob_type->ob_refcnt;
  if ( p_ob_refcnt != nullptr )
  {
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "%f %f %f", *p_ob_refcnt, p_ob_refcnt[1], p_ob_refcnt[2]);
    return _PyString_FromString(a1: v3->m_szBuf);
  }
  else
  {
    _PyErr_SetString(a1: _PyExc_ValueError, a2: "null vector");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002860
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  bool v4; // zf
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Next(
                this: &this->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      v4 = i->m_pBlockHeader == nullptr;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( v4 )
      {
        if ( m_nIndex == -1 )
          break;
      }
      else if ( m_nIndex >= 0
             && m_nIndex < m_pBlockHeader->m_nBlockSize
             && &m_pBlockHeader[2 * m_nIndex] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::IsIdxAfter(
                   this: &this->m_Memory,
                   i: (unsigned int)&m_pBlockHeader[2 * m_nIndex + 1],
                   it: &this->m_LastAlloc)
             && (m_pBlockHeader[2 * m_nIndex + 2].m_pNext != &m_pBlockHeader[2 * m_nIndex + 1]
              || (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize == &m_pBlockHeader[2 * m_nIndex + 1]) )
      {
        m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
        m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = this->m_FirstFree;
        this->m_FirstFree = (int)&m_pBlockHeader[2 * m_nIndex + 1];
      }
      if ( m_pBlockHeader == this->m_LastAlloc.m_pBlockHeader && m_nIndex == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002930
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::Purge(
        CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pBlocks; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *v3; // eax

  CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      free(pMem: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10002970
// Name: public: CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *__thiscall CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>(
        CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *this)
{
  CUtlFixedLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *> > *p_m_aDataPool; // edi
  bool v3; // sf

  this->m_aBuckets.m_Memory.m_pMemory = nullptr;
  this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  this->m_aBuckets.m_Memory.m_nGrowSize = 0;
  this->m_aBuckets.m_pElements = nullptr;
  p_m_aDataPool = &this->m_aDataPool;
  this->m_aDataPool.m_Memory.m_pBlocks = nullptr;
  this->m_aDataPool.m_Memory.m_nAllocationCount = 0;
  this->m_aDataPool.m_Memory.m_nGrowSize = 0;
  this->m_aDataPool.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_aDataPool.m_LastAlloc.m_nIndex = -1;
  this->m_aDataPool.m_Head = 0;
  this->m_aDataPool.m_Tail = 0;
  this->m_aDataPool.m_FirstFree = 0;
  this->m_aDataPool.m_ElementCount = 0;
  this->m_aDataPool.m_NumAlloced = 0;
  this->m_aDataPool.m_pElements = nullptr;
  v3 = this->m_aBuckets.m_Memory.m_nGrowSize < 0;
  this->m_aBuckets.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_aBuckets.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aBuckets.m_Memory.m_pMemory);
      this->m_aBuckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aBuckets.m_pElements = this->m_aBuckets.m_Memory.m_pMemory;
  CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::Purge(this: p_m_aDataPool);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100029E0
// Name: public: CPythonVM::CPythonVM(void)
// Source: json
//------------------------------------------------------------------------------
CPythonVM *__thiscall CPythonVM::CPythonVM(CPythonVM *this)
{
  this->__vftable = (CPythonVM_vtbl *)&CPythonVM::`vftable';
  this->m_iUniqueIdSerialNumber = 0;
  ConVarRef::ConVarRef(this: &this->developer, pName: "developer");
  CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>(this: (CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *)&this->m_TypeMap);
  CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>(this: &this->m_ClassMap);
  this->m_bInitialized = false;
  this->m_pRootScope = nullptr;
  this->m_pValveScope = nullptr;
  this->m_iMethodDef = 0;
  this->m_iClassDef = 0;
  this->m_debugObjCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002A40
// Name: InstanceToString
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl InstanceToString(_object *pSelf)
{
  return _PyString_FromFormat(a1: "<%s at %p>", pSelf->ob_type->tp_name, pSelf);
}

//------------------------------------------------------------------------------
// Address: 0x10002A60
// Name: public: CPyScope::~CPyScope(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPyScope::~CPyScope(CPyScope *this)
{
  _object *m_pTempDict; // eax
  _object *m_pPyModule; // eax
  scriptClassInstance_t *m_pPySelf; // esi

  if ( this->m_pTempDict != nullptr )
  {
    --this->m_pTempDict->ob_refcnt;
    m_pTempDict = this->m_pTempDict;
    if ( m_pTempDict->ob_refcnt == 0 )
      m_pTempDict->ob_type->tp_dealloc(a1: this->m_pTempDict);
  }
  if ( this->m_pPyModule != nullptr )
  {
    --this->m_pPyModule->ob_refcnt;
    m_pPyModule = this->m_pPyModule;
    if ( m_pPyModule->ob_refcnt == 0 )
      m_pPyModule->ob_type->tp_dealloc(a1: this->m_pPyModule);
  }
  if ( this->m_pPySelf != nullptr )
  {
    --this->m_pPySelf->ob_refcnt;
    m_pPySelf = this->m_pPySelf;
    if ( m_pPySelf->ob_refcnt == 0 )
      m_pPySelf->ob_type->tp_dealloc(a1: (_object *)m_pPySelf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002AD0
// Name: public: virtual enum ScriptLanguage_t CPythonVM::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPythonVM::GetLanguage(CPythonVM *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10002AE0
// Name: public: virtual char const __near * CPythonVM::GetLanguageName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPythonVM::GetLanguageName(CPythonVM *this)
{
  return "Python";
}

//------------------------------------------------------------------------------
// Address: 0x10002AF0
// Name: public: virtual void CPythonVM::ReleaseScript(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::ReleaseScript(CPythonVM *this, HSCRIPT__ *hScript)
{
  int v2; // eax

  v2 = *((_DWORD *)hScript + 1);
  if ( v2 != _PyString_Type.ob_refcnt )
    _PyType_IsSubtype(a1: v2, a2: _PyString_Type.ob_refcnt);
  if ( (*(_DWORD *)hScript)-- == 1 )
    (*(void (__cdecl **)(HSCRIPT__ *))(*((_DWORD *)hScript + 1) + 24))(a1: hScript);
}

//------------------------------------------------------------------------------
// Address: 0x10002B30
// Name: public: virtual struct HSCRIPT__ __near * CPythonVM::CreateScope(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CPythonVM::CreateScope(CPythonVM *this, const char *pszScope, HSCRIPT__ *hParent)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi

  v3 = operator new(nSize: 0x10u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v3[1] = 0;
    *v3 = 0;
    v3[2] = _PyDict_New();
    v4[3] = 81818181;
  }
  else
  {
    v4 = nullptr;
  }
  if ( hParent != nullptr )
    DevMsg(a1: "Warning, Python script language ignoring hParent parameter for CreateScope!");
  return (HSCRIPT__ *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10002B80
// Name: public: virtual void CPythonVM::ReleaseFunction(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::ReleaseFunction(CPythonVM *this, HSCRIPT__ *hScript)
{
  if ( hScript != nullptr && (*(_DWORD *)hScript)-- == 1 )
    (*(void (__cdecl **)(HSCRIPT__ *))(*((_DWORD *)hScript + 1) + 24))(a1: hScript);
  --DEBUG_FUNCCOUNT;
}

//------------------------------------------------------------------------------
// Address: 0x10002BB0
// Name: public: bool CPythonVM::IsClassDerivedFrom(struct ScriptClassDesc_t const __near *,struct ScriptClassDesc_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPythonVM::IsClassDerivedFrom(
        CPythonVM *this,
        const ScriptClassDesc_t *pDerivedClass,
        const ScriptClassDesc_t *pBaseClass)
{
  ScriptClassDesc_t *m_pBaseDesc; // eax

  m_pBaseDesc = pDerivedClass->m_pBaseDesc;
  if ( m_pBaseDesc == nullptr )
    return 0;
  while ( m_pBaseDesc != pBaseClass )
  {
    m_pBaseDesc = m_pBaseDesc->m_pBaseDesc;
    if ( m_pBaseDesc == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002BE0
// Name: public: virtual bool CPythonVM::GenerateUniqueKey(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPythonVM::GenerateUniqueKey(CPythonVM *this, const char *pszRoot, char *pBuf, int nBufSize)
{
  unsigned int m_iUniqueIdSerialNumber_high; // edx
  unsigned int m_iUniqueIdSerialNumber; // esi
  int v6; // eax
  unsigned __int64 v8; // [esp-Ch] [ebp-14h]

  m_iUniqueIdSerialNumber_high = HIDWORD(this->m_iUniqueIdSerialNumber);
  m_iUniqueIdSerialNumber = this->m_iUniqueIdSerialNumber;
  LODWORD(this->m_iUniqueIdSerialNumber) = m_iUniqueIdSerialNumber + 1;
  v8 = __PAIR64__(m_iUniqueIdSerialNumber_high, m_iUniqueIdSerialNumber);
  HIDWORD(this->m_iUniqueIdSerialNumber) = __CFADD__(m_iUniqueIdSerialNumber, 1) + m_iUniqueIdSerialNumber_high;
  v6 = _RandomInt(a1: 0, a2: 4095);
  V_snprintf(pDest: pBuf, maxLen: nBufSize, pFormat: "%x%I64x%s", v6, v8, pszRoot);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002C40
// Name: public: virtual bool CPythonVM::ClearValue(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPythonVM::ClearValue(CPythonVM *this, HSCRIPT__ *hScope, const char *pszKey)
{
  CPyScope *m_pValveScope; // eax
  int v5; // ebx
  _object *m_pPyModule; // eax
  int Dict; // edi
  _object *v8; // eax
  _object *v9; // esi
  int v10; // edi
  bool v11; // zf

  m_pValveScope = (CPyScope *)hScope;
  if ( hScope == (HSCRIPT__ *)-1 )
    return false;
  v5 = 0;
  if ( hScope != nullptr )
  {
    if ( *(_DWORD *)hScope != 0 )
      v5 = *(_DWORD *)(*(_DWORD *)hScope + 8);
    else
      v5 = 0;
  }
  else
  {
    m_pValveScope = this->m_pValveScope;
  }
  m_pPyModule = m_pValveScope->m_pPyModule;
  if ( m_pPyModule != nullptr )
    Dict = _PyModule_GetDict(a1: m_pPyModule);
  else
    Dict = 0;
  v8 = _PyString_FromString(a1: pszKey);
  v9 = v8;
  if ( v5 != 0 && _PyDict_Contains(a1: v5, a2: v8) != 0 )
  {
    v10 = _PyDict_DelItemString(a1: v5, a2: pszKey);
    if ( v9 != nullptr )
    {
      v11 = v9->ob_refcnt-- == 1;
      if ( v11 )
      {
        v9->ob_type->tp_dealloc(a1: v9);
        return v10 != -1;
      }
    }
    return v10 != -1;
  }
  if ( Dict != 0 && _PyDict_Contains(a1: Dict, a2: v9) != 0 )
  {
    v10 = _PyDict_DelItemString(a1: Dict, a2: pszKey);
    if ( v9 != nullptr )
    {
      v11 = v9->ob_refcnt-- == 1;
      if ( v11 )
        v9->ob_type->tp_dealloc(a1: v9);
    }
    return v10 != -1;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10002D20
// Name: public: virtual void CPythonVM::ReleaseValue(struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::ReleaseValue(CPythonVM *this, ScriptVariant_t *value)
{
  __int16 v2; // ax
  __int16 m_type; // cx

  v2 = value->m_flags & 1;
  if ( v2 != 0 )
    --DEBUG_VARIANTCOUNT;
  m_type = value->m_type;
  if ( m_type == 33 )
  {
    if ( value->m_int != 0 && --*(_DWORD *)value->m_int == 0 )
    {
      (*(void (__cdecl **)(int))(*(_DWORD *)(value->m_int + 4) + 24))(a1: value->m_int);
      value->m_type = 0;
      return;
    }
  }
  else if ( v2 != 0 && (m_type == 3 || m_type == 32) )
  {
    free(pMem: value->m_hScript);
  }
  value->m_type = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002D90
// Name: public: virtual bool CPythonVM::RaiseException(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPythonVM::RaiseException(CPythonVM *this, const char *pszExceptionText)
{
  _PyErr_SetString(a1: _PyExc_Exception, a2: pszExceptionText);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002DB0
// Name: public: virtual void CPythonVM::ReadState(class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::ReadState(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10002DC0
// Name: private: bool CPythonVM::PyPrintError(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPythonVM::PyPrintError(CPythonVM *this)
{
  if ( _PyErr_Occurred(a1: this) == 0 )
    return 0;
  _PyErr_Print();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002DE0
// Name: private: struct _object __near * CPythonVM::ConvertToPyObject(struct ScriptVariant_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
_object *__thiscall CPythonVM::ConvertToPyObject(
        CPythonVM *this,
        const ScriptVariant_t *value,
        __int16 bAllocNewVector)
{
  __int16 m_type; // ax
  _object *result; // eax
  void *v5; // esi
  unsigned int v6; // eax
  Vector *v7; // edx
  int m_int; // ecx
  float *p_ob_refcnt; // edx

  m_type = value->m_type;
  switch ( m_type )
  {
    case 1:
      result = (_object *)_PyFloat_FromDouble(
                            a1: COERCE_UNSIGNED_INT64(value->m_float),
                            a2: HIDWORD(COERCE_UNSIGNED_INT64(value->m_float)));
      break;
    case 3:
      if ( (_BYTE)bAllocNewVector != 0 )
      {
        result = CreatePyVector(pVector: nullptr);
        m_int = value->m_int;
        p_ob_refcnt = (float *)&result[1].ob_type->ob_refcnt;
        *p_ob_refcnt = *(float *)value->m_int;
        p_ob_refcnt[1] = *(float *)(m_int + 4);
        p_ob_refcnt[2] = *(float *)(m_int + 8);
      }
      else
      {
        v7 = (Vector *)value->m_int;
        ++DEBUG_VECCOUNT;
        result = CreatePyVector(pVector: v7);
      }
      break;
    case 5:
      result = _PyInt_FromLong(a1: value->m_int);
      break;
    case 6:
      result = _PyBool_FromLong(a1: (unsigned __int8)value->m_char);
      break;
    case 8:
      bAllocNewVector = (unsigned __int8)value->m_char;
      result = _PyString_FromStringAndSize(a1: &bAllocNewVector, a2: 1);
      break;
    case 32:
      if ( m_type == 0 )
        goto $LN1;
      v5 = (void *)value->m_int;
      v6 = strlen(value->m_pszString);
      if ( value->m_int == 0 )
        v5 = &unk_1001DB62;
      result = _PyString_FromStringAndSize(a1: v5, a2: v6);
      break;
    case 33:
      result = (_object *)value->m_int;
      if ( value->m_int == 0 )
        goto $LN1;
      ++result->ob_refcnt;
      break;
    default:
$LN1:
      result = (_object *)++__Py_NoneStruct.ob_refcnt;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002F40
// Name: private: bool CPythonVM::ConvertToVariant(struct _object __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPythonVM::ConvertToVariant(CPythonVM *this, _object *object, ScriptVariant_t *pReturn)
{
  _object *v3; // esi
  _typeobject *ob_type; // eax
  int v6; // eax
  ScriptVariant_t *v7; // ecx
  ScriptVariant_t *v8; // eax
  ScriptVariant_t *v9; // eax
  float v10; // xmm0_4
  ScriptVariant_t *v11; // eax
  _typeobject *v12; // esi
  ScriptVariant_t *v13; // edi
  _DWORD *v14; // eax
  ScriptVariant_t *v15; // eax
  ScriptVariant_t *v16; // esi
  char *v17; // edi
  void *v18; // eax
  void *v19; // [esp-18h] [ebp-28h]
  char *v20; // [esp-10h] [ebp-20h]
  void *src; // [esp+Ch] [ebp-4h] BYREF

  v3 = object;
  if ( object == (_object *)__Py_NoneStruct.ob_refcnt )
  {
    pReturn->m_type = 0;
    return 1;
  }
  else
  {
    ob_type = object->ob_type;
    if ( ob_type == (_typeobject *)_PyLong_Type.ob_refcnt )
    {
      v6 = _PyLong_AsLong(a1: object);
      v7 = pReturn;
      pReturn->m_int = v6;
      v7->m_type = 5;
      return 1;
    }
    else if ( ob_type == (_typeobject *)_PyInt_Type.ob_refcnt )
    {
      v8 = pReturn;
      pReturn->m_int = object[1].ob_refcnt;
      v8->m_type = 5;
      return 1;
    }
    else if ( ob_type == (_typeobject *)_PyFloat_Type.ob_refcnt )
    {
      v9 = pReturn;
      v10 = *(double *)&object[1].ob_refcnt;
      pReturn->m_type = 1;
      v9->m_float = v10;
      return 1;
    }
    else if ( ob_type == (_typeobject *)_PyBool_Type.ob_refcnt )
    {
      v11 = pReturn;
      pReturn->m_type = 6;
      v11->m_char = v3 == (_object *)__Py_TrueStruct.ob_refcnt;
      return 1;
    }
    else if ( ob_type == (_typeobject *)_PyString_Type.ob_refcnt
           || _PyType_IsSubtype(a1: ob_type, a2: _PyString_Type.ob_refcnt) != 0 )
    {
      _PyString_AsStringAndSize(a1: v3, a2: &src, a3: &object);
      v16 = pReturn;
      v17 = (char *)&object->ob_refcnt + 1;
      v20 = (char *)&object->ob_refcnt + 1;
      pReturn->m_type = 32;
      v18 = operator new(nSize: (unsigned int)v20);
      v19 = src;
      v16->m_int = (int)v18;
      _V_memcpy(dest: v18, src: v19, count: (int)v17);
      v16->m_flags |= 1u;
      ++DEBUG_VARIANTCOUNT;
      return 1;
    }
    else if ( v3->ob_type == &PyTypeVector )
    {
      v12 = v3[1].ob_type;
      v13 = pReturn;
      pReturn->m_type = 3;
      v14 = operator new(nSize: 0xCu);
      if ( v14 != nullptr )
      {
        *(_QWORD *)v14 = *(_QWORD *)&v12->ob_refcnt;
        v14[2] = v12->ob_size;
        v13->m_flags |= 1u;
        ++DEBUG_VARIANTCOUNT;
        v13->m_int = (int)v14;
      }
      else
      {
        v13->m_flags |= 1u;
        ++DEBUG_VARIANTCOUNT;
        v13->m_int = 0;
      }
      return 1;
    }
    else
    {
      v15 = pReturn;
      pReturn->m_int = (int)v3;
      v15->m_type = 33;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030F0
// Name: private: void CPythonVM::debugRemoveTrackedObject(struct _object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::debugRemoveTrackedObject(CPythonVM *this, _object *pobj)
{
  int v2; // edx
  _object **m_debugObjects; // eax

  v2 = 0;
  if ( this->m_debugObjCount > 0 )
  {
    m_debugObjects = this->m_debugObjects;
    do
    {
      if ( *m_debugObjects == pobj )
        *m_debugObjects = nullptr;
      ++v2;
      ++m_debugObjects;
    }
    while ( v2 < this->m_debugObjCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003130
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<int,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int *m_pMemory; // ecx
  bool v7; // zf

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
        m_nAllocationCount = 8;
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
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (int *)operator new(nSize: 4 * m_nAllocationCount);
    else
      this->m_pMemory = (int *)_realloc_crt(ptr: m_pMemory, size: 4 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100031C0
// Name: public: virtual enum ScriptStatus_t CPythonVM::Run(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPythonVM::Run(CPythonVM *this, const char *pszScript, bool bWait)
{
  int Dict; // edi
  CPyScope *m_pRootScope; // esi
  int m_pPyModule; // eax
  _DWORD *v7; // esi
  int v8; // ecx

  if ( this->m_pRootScope->m_pPyModule != nullptr )
    Dict = _PyModule_GetDict(a1: this->m_pRootScope->m_pPyModule);
  else
    Dict = 0;
  m_pRootScope = this->m_pRootScope;
  m_pPyModule = (int)m_pRootScope->m_pPyModule;
  if ( m_pPyModule != 0 )
    m_pPyModule = _PyModule_GetDict(a1: m_pRootScope->m_pPyModule);
  v7 = (_DWORD *)_PyRun_StringFlags(a1: pszScript, a2: 257, a3: m_pPyModule, a4: Dict, a5: 0);
  if ( _PyErr_Occurred(a1: v8) != 0 )
    _PyErr_Print();
  if ( v7 == nullptr )
    return -1;
  if ( (*v7)-- == 1 )
    (*(void (__cdecl **)(_DWORD *))(v7[1] + 24))(a1: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003240
// Name: public: virtual struct HSCRIPT__ __near * CPythonVM::CompileScript(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
_object *__thiscall CPythonVM::CompileScript(CPythonVM *this, const char *pszScript, const char *pszId)
{
  const char *v4; // esi
  char *v5; // eax
  char *v6; // edi
  int v7; // esi
  int v8; // ecx
  char buffer[1028]; // [esp+0h] [ebp-404h] BYREF

  if ( pszId != nullptr )
  {
    V_StripExtension(in: pszId, out: &buffer[4], outSize: 1024);
    return _PyString_FromString(a1: &buffer[4]);
  }
  else
  {
    v4 = pszScript;
    if ( pszScript != nullptr && *pszScript != 0 )
    {
      v5 = (char *)_PyMem_Malloc(a1: strlen(pszScript) + 2);
      v6 = v5;
      if ( v5 != nullptr )
      {
        if ( *pszScript != 0 )
        {
          do
          {
            if ( *v4 == 13 )
            {
              *v5++ = 10;
              if ( v4[1] == 10 )
                ++v4;
            }
            else
            {
              *v5++ = *v4;
            }
            ++v4;
          }
          while ( *v4 != 0 );
        }
        *v5 = 10;
        v5[1] = 0;
        v7 = _Py_CompileStringFlags(a1: v6, a2: "unnamed", a3: 257, a4: 0);
        if ( _PyErr_Occurred(a1: v8) != 0 )
          _PyErr_Print();
        _PyMem_Free(a1: v6);
        return (_object *)v7;
      }
      else
      {
        _PyErr_SetString(a1: _PyExc_MemoryError, a2: "Python Source Compile - no memory to allocate conversion buffer!");
        return nullptr;
      }
    }
    else
    {
      DevWarning(a1: "Vscript: no script text passed to CompileScript - ignoring compilation!");
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003370
// Name: public: virtual void CPythonVM::ReleaseScope(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::ReleaseScope(CPythonVM *this, HSCRIPT__ *hScript)
{
  if ( hScript != nullptr )
  {
    CPyScope::~CPyScope(this: (CPyScope *)hScript);
    free(pMem: hScript);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003390
// Name: public: virtual struct HSCRIPT__ __near * CPythonVM::LookupFunction(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CPythonVM::LookupFunction(CPythonVM *this, const char *pszFunction, HSCRIPT__ *hScope)
{
  CPyScope *m_pValveScope; // eax
  _object *m_pPyModule; // eax
  int Dict; // eax
  _DWORD *ItemString; // esi
  int v8; // ecx

  m_pValveScope = (CPyScope *)hScope;
  if ( hScope == (HSCRIPT__ *)-1 )
    return nullptr;
  if ( hScope == nullptr )
    m_pValveScope = this->m_pValveScope;
  m_pPyModule = m_pValveScope->m_pPyModule;
  if ( m_pPyModule == nullptr || (Dict = _PyModule_GetDict(a1: m_pPyModule)) == 0 )
  {
    DevWarning(a1: "Vscript, vpython.cpp: LookupFunction - must first compile and run the script before you can lookup a function!");
    return nullptr;
  }
  ItemString = (_DWORD *)_PyDict_GetItemString(a1: Dict, a2: pszFunction);
  if ( _PyErr_Occurred(a1: v8) != 0 )
    _PyErr_Print();
  if ( ItemString == nullptr || _PyCallable_Check(a1: ItemString) == 0 )
    return nullptr;
  ++*ItemString;
  ++DEBUG_FUNCCOUNT;
  return (HSCRIPT__ *)ItemString;
}

//------------------------------------------------------------------------------
// Address: 0x10003420
// Name: public: virtual enum ScriptStatus_t CPythonVM::ExecuteFunction(struct HSCRIPT__ __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPythonVM::ExecuteFunction(
        CPythonVM *this,
        HSCRIPT__ *hFunction,
        ScriptVariant_t *pArgs,
        int nArgs,
        ScriptVariant_t *pReturn,
        HSCRIPT__ *hScope,
        bool bWait)
{
  HSCRIPT__ *v7; // ebx
  _object *m_pPyModule; // eax
  int v9; // eax
  _object *v10; // eax
  int v11; // esi
  const ScriptVariant_t *v12; // ebx
  int v13; // esi
  int v14; // ecx
  _object *i; // edi
  _object *v16; // eax
  _object *v17; // eax
  bool v19; // zf
  _DWORD *v20; // ebx
  _DWORD *ob_refcnt; // eax
  int v22; // esi
  const ScriptVariant_t *v23; // edi
  _object *v24; // eax
  int v25; // eax
  int v26; // ecx
  _object *v27; // esi
  int v28; // ebp
  _DWORD *v29; // eax
  int v30; // ecx
  _DWORD *v31; // esi
  _object *rgpyArgs[31]; // [esp+Ch] [ebp-80h] BYREF

  if ( hScope == (HSCRIPT__ *)-1 )
    return -1;
  v7 = hFunction;
  if ( hFunction == nullptr )
    return -1;
  if ( hScope != nullptr )
  {
    m_pPyModule = *((_object **)hScope + 1);
    if ( m_pPyModule == nullptr )
      goto LABEL_8;
    goto LABEL_7;
  }
  m_pPyModule = this->m_pRootScope->m_pPyModule;
  if ( m_pPyModule != nullptr )
LABEL_7:
    m_pPyModule = (_object *)_PyModule_GetDict(a1: m_pPyModule);
LABEL_8:
  rgpyArgs[0] = m_pPyModule;
  v9 = *((_DWORD *)hFunction + 1);
  if ( v9 == _PyString_Type.ob_refcnt || _PyType_IsSubtype(a1: v9, a2: _PyString_Type.ob_refcnt) != 0 )
  {
    v28 = 0;
    v29 = (_DWORD *)_PyImport_Import(a1: hFunction);
    v31 = v29;
    if ( hScope != nullptr )
    {
      *((_DWORD *)hScope + 1) = v29;
      if ( v29 == nullptr )
      {
LABEL_55:
        if ( _PyErr_Occurred(a1: v30) != 0 )
          _PyErr_Print();
        if ( v31 == nullptr )
          return -1;
        return v28;
      }
      ++*v29;
    }
    if ( v29 != nullptr )
    {
      v19 = (*v29)-- == 1;
      if ( v19 )
        (*(void (__cdecl **)(_DWORD *))(v29[1] + 24))(a1: v29);
    }
    goto LABEL_55;
  }
  if ( *((_DWORD *)hFunction + 1) == _PyFunction_Type.ob_refcnt || _PyCallable_Check(a1: hFunction) != 0 )
  {
    v20 = (_DWORD *)_PyTuple_New(a1: nArgs + 1);
    if ( hScope != nullptr && (ob_refcnt = *(_DWORD **)hScope, *(_DWORD *)hScope != 0)
      || (ob_refcnt = (_DWORD *)__Py_NoneStruct.ob_refcnt, __Py_NoneStruct.ob_refcnt != 0) )
    {
      ++*ob_refcnt;
    }
    _PyTuple_SetItem(a1: v20, a2: 0, a3: ob_refcnt);
    v22 = 0;
    if ( nArgs > 0 )
    {
      v23 = pArgs;
      do
      {
        v24 = CPythonVM::ConvertToPyObject(this, value: v23, bAllocNewVector: 1);
        _PyTuple_SetItem(a1: v20, a2: ++v22, a3: v24);
        ++v23;
      }
      while ( v22 < nArgs );
    }
    v25 = _PyObject_CallObject(a1: hFunction, a2: v20);
    v19 = (*v20)-- == 1;
    v27 = (_object *)v25;
    if ( v19 )
      (*(void (__cdecl **)(_DWORD *))(v20[1] + 24))(a1: v20);
    if ( _PyErr_Occurred(a1: v26) != 0 )
      _PyErr_Print();
    if ( v27 == nullptr )
      return -1;
    if ( pReturn != nullptr )
      CPythonVM::ConvertToVariant(this, object: v27, pReturn);
    v19 = v27->ob_refcnt-- == 1;
    if ( v19 )
      v27->ob_type->tp_dealloc(a1: v27);
  }
  else
  {
    v10 = *(_object **)hScope;
    if ( *(_DWORD *)hScope != 0 || (v10 = (_object *)__Py_NoneStruct.ob_refcnt, __Py_NoneStruct.ob_refcnt != 0) )
      ++v10->ob_refcnt;
    v11 = 0;
    rgpyArgs[1] = v10;
    if ( nArgs > 0 )
    {
      v12 = pArgs;
      do
        rgpyArgs[v11++ + 2] = CPythonVM::ConvertToPyObject(this, value: v12++, bAllocNewVector: 1);
      while ( v11 < nArgs );
      v7 = hFunction;
    }
    v13 = 0;
    for ( i = (_object *)_PyEval_EvalCodeEx(
                           a1: v7,
                           a2: rgpyArgs[0],
                           a3: rgpyArgs[0],
                           a4: &rgpyArgs[1],
                           a5: nArgs,
                           a6: 0,
                           a7: 0,
                           a8: 0,
                           a9: 0,
                           a10: 0); v13 < nArgs; ++v13 )
    {
      v16 = rgpyArgs[v13 + 1];
      if ( v16 != nullptr )
      {
        --v16->ob_refcnt;
        v17 = rgpyArgs[v13 + 1];
        if ( v17->ob_refcnt == 0 )
          v17->ob_type->tp_dealloc(a1: rgpyArgs[v13 + 1]);
      }
    }
    if ( i == nullptr )
    {
      if ( _PyErr_Occurred(a1: v14) != 0 )
        _PyErr_Print();
      return -1;
    }
    if ( pReturn != nullptr )
      CPythonVM::ConvertToVariant(this, object: i, pReturn);
    v19 = i->ob_refcnt-- == 1;
    if ( v19 )
      i->ob_type->tp_dealloc(a1: i);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100036F0
// Name: public: virtual bool CPythonVM::ValueExists(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPythonVM::ValueExists(CPythonVM *this, HSCRIPT__ *hScope, const char *pszKey)
{
  int v4; // eax

  return hScope != (HSCRIPT__ *)-1
      && hScope != nullptr
      && *(_DWORD *)hScope != 0
      && (v4 = *(_DWORD *)(*(_DWORD *)hScope + 8)) != 0
      && _PyObject_HasAttrString(a1: v4, a2: pszKey) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003730
// Name: public: bool CPythonVM::SetValueInternal(struct HSCRIPT__ __near *,char const __near *,struct ScriptVariant_t const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPythonVM::SetValueInternal(
        CPythonVM *this,
        HSCRIPT__ *hScope,
        const char *pszKey,
        const ScriptVariant_t *value,
        const char *pszValue)
{
  HSCRIPT__ *v5; // edi
  _object *v8; // ebx
  _object *v9; // eax
  bool v10; // zf
  _object *v11; // eax
  int m_debugObjCount; // eax
  CPyScope *m_pValveScope; // esi
  int Dict; // eax

  v5 = hScope;
  if ( hScope == (HSCRIPT__ *)-1 )
    return false;
  if ( pszValue != nullptr )
  {
    v8 = _PyString_FromString(a1: pszValue);
  }
  else
  {
    if ( value->m_type == 33 && _V_strcmp(s1: pszKey, s2: "self") == 0 )
    {
      v9 = CPythonVM::ConvertToPyObject(this, value, bAllocNewVector: 1);
      *(_DWORD *)hScope = v9;
      if ( v9 != nullptr )
      {
        v10 = ++v9->ob_refcnt == 1;
        --v9->ob_refcnt;
        if ( v10 )
          v9->ob_type->tp_dealloc(a1: v9);
      }
      _PyDict_Merge(a1: *(_DWORD *)(*(_DWORD *)hScope + 8), a2: *((_DWORD *)hScope + 2), a3: 0);
      return true;
    }
    v11 = CPythonVM::ConvertToPyObject(this, value, bAllocNewVector: 1);
    v8 = v11;
    if ( value->m_type == 33 )
    {
      if ( v11 != nullptr )
      {
        v10 = v11->ob_refcnt-- == 1;
        if ( v10 )
          v11->ob_type->tp_dealloc(a1: v11);
      }
      m_debugObjCount = this->m_debugObjCount;
      if ( m_debugObjCount < 1000 )
      {
        this->m_debugObjects[m_debugObjCount] = v8;
        ++this->m_debugObjCount;
      }
    }
    v5 = hScope;
  }
  if ( v5 != nullptr )
  {
    Dict = *(_DWORD *)v5;
    if ( *(_DWORD *)v5 != 0 )
      Dict = *(_DWORD *)(Dict + 8);
  }
  else
  {
    m_pValveScope = this->m_pValveScope;
    if ( m_pValveScope->m_pPyModule == nullptr )
    {
LABEL_24:
      _PyDict_SetItemString(a1: *((_DWORD *)v5 + 2), a2: pszKey, a3: v8);
      return true;
    }
    Dict = _PyModule_GetDict(a1: m_pValveScope->m_pPyModule);
  }
  if ( Dict == 0 )
    goto LABEL_24;
  return _PyDict_SetItemString(a1: Dict, a2: pszKey, a3: v8) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10003870
// Name: public: virtual void CPythonVM::CreateTable(struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::CreateTable(CPythonVM *this, ScriptVariant_t *Table)
{
  _object *v3; // eax

  v3 = (_object *)_PyDict_New();
  CPythonVM::ConvertToVariant(this, object: v3, pReturn: Table);
}

//------------------------------------------------------------------------------
// Address: 0x10003890
// Name: public: virtual int CPythonVM::GetNumTableEntries(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPythonVM::GetNumTableEntries(CPythonVM *this, HSCRIPT__ *hScope)
{
  if ( hScope == (HSCRIPT__ *)-1 )
    return 0;
  if ( hScope != nullptr && *(_DWORD *)hScope != 0 )
    return _PyDict_Size(a1: *(_DWORD *)(*(_DWORD *)hScope + 8));
  return _PyDict_Size(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100038D0
// Name: public: virtual int CPythonVM::GetKeyValue(struct HSCRIPT__ __near *,int,struct ScriptVariant_t __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPythonVM::GetKeyValue(
        CPythonVM *this,
        HSCRIPT__ *hScope,
        _object *nIterator,
        ScriptVariant_t *pKey,
        ScriptVariant_t *pValue)
{
  HSCRIPT__ *v5; // eax
  _object *object; // [esp+4h] [ebp-4h] BYREF

  v5 = hScope;
  if ( hScope == (HSCRIPT__ *)-1 )
    return -1;
  if ( hScope != nullptr )
  {
    v5 = *(HSCRIPT__ **)hScope;
    if ( *(_DWORD *)hScope != 0 )
      v5 = *((HSCRIPT__ **)v5 + 2);
  }
  hScope = (HSCRIPT__ *)nIterator;
  if ( _PyDict_Next(a1: v5, a2: &hScope, a3: &nIterator, a4: &object) == 0 )
    return -1;
  CPythonVM::ConvertToVariant(this, object: nIterator, pReturn: pKey);
  CPythonVM::ConvertToVariant(this, object, pReturn: pValue);
  return (int)hScope;
}

//------------------------------------------------------------------------------
// Address: 0x10003950
// Name: public: virtual bool CPythonVM::GetValue(struct HSCRIPT__ __near *,char const __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPythonVM::GetValue(CPythonVM *this, HSCRIPT__ *hScope, const char *pszKey, ScriptVariant_t *pValue)
{
  HSCRIPT__ *v4; // eax
  _object *ItemString; // esi
  int v7; // ecx

  v4 = hScope;
  if ( hScope == (HSCRIPT__ *)-1 )
  {
    ItemString = nullptr;
  }
  else
  {
    if ( hScope != nullptr )
    {
      v4 = *(HSCRIPT__ **)hScope;
      if ( *(_DWORD *)hScope != 0 )
        v4 = *((HSCRIPT__ **)v4 + 2);
    }
    ItemString = (_object *)_PyDict_GetItemString(a1: v4, a2: pszKey);
    if ( _PyErr_Occurred(a1: v7) != 0 )
      _PyErr_Print();
  }
  return CPythonVM::ConvertToVariant(this, object: ItemString, pReturn: pValue) != 0
      && ItemString != (_object *)__Py_NoneStruct.ob_refcnt;
}

//------------------------------------------------------------------------------
// Address: 0x100039C0
// Name: private: void CPythonVM::RegisterFunctionGuts(struct ScriptFunctionBinding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::RegisterFunctionGuts(CPythonVM *this, ScriptFunctionBinding_t *pScriptFunction)
{
  int Dict; // eax
  const char **v4; // eax
  int v5; // edx
  int v6; // ecx
  _object *(__cdecl *pfn)(_object *, _object *); // ecx

  if ( this->m_pValveScope->m_pPyModule != nullptr )
    Dict = _PyModule_GetDict(a1: this->m_pValveScope->m_pPyModule);
  else
    Dict = 0;
  if ( _PyDict_GetItemString(a1: Dict, a2: pScriptFunction->m_desc.m_pszScriptName) == 0 )
  {
    v4 = (const char **)operator new(nSize: 0x20u);
    this->m_rgpMethodDefs[this->m_iMethodDef++] = v4;
    v4[4] = nullptr;
    v4[5] = nullptr;
    v4[6] = nullptr;
    v4[7] = nullptr;
    *v4 = pScriptFunction->m_desc.m_pszScriptName;
    v4[2] = (const char *)1;
    v4[3] = pScriptFunction->m_desc.m_pszDescription;
    v5 = g_proxyid;
    v6 = g_proxyid;
    g_proxies[g_proxyid].pBinding = pScriptFunction;
    pfn = g_proxies[v6].pfn;
    g_proxyid = v5 + 1;
    v4[1] = (const char *)pfn;
    _Py_InitModule4(a1: "valve", a2: v4, a3: "Import module for access to all exported Valve methods.", a4: 0, a5: 1013);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003A70
// Name: public: virtual enum ScriptStatus_t CPythonVM::Run(struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPythonVM::Run(CPythonVM *this, HSCRIPT__ *hScript, HSCRIPT__ *hScope, bool bWait)
{
  return CPythonVM::ExecuteFunction(this, hFunction: hScript, pArgs: nullptr, nArgs: 0, pReturn: nullptr, hScope, bWait);
}

//------------------------------------------------------------------------------
// Address: 0x10003A90
// Name: public: virtual enum ScriptStatus_t CPythonVM::Run(struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPythonVM::Run(CPythonVM *this, HSCRIPT__ *hScript, bool bWait)
{
  return CPythonVM::ExecuteFunction(
           this,
           hFunction: hScript,
           pArgs: nullptr,
           nArgs: 0,
           pReturn: nullptr,
           hScope: nullptr,
           bWait);
}

//------------------------------------------------------------------------------
// Address: 0x10003AB0
// Name: public: virtual void CPythonVM::RegisterFunction(struct ScriptFunctionBinding_t __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPythonVM::RegisterFunction(CPythonVM *this, ScriptFunctionBinding_t *pScriptFunction)
{
  CPythonVM::RegisterFunctionGuts(this, pScriptFunction);
}

//------------------------------------------------------------------------------
// Address: 0x10003AC0
// Name: public: virtual bool CPythonVM::SetValue(struct HSCRIPT__ __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPythonVM::SetValue(CPythonVM *this, HSCRIPT__ *hScope, const char *pszKey, const char *pszValue)
{
  ScriptVariant_t value; // [esp+0h] [ebp-8h] BYREF

  value.m_flags = 0;
  value.m_int = 0;
  value.m_type = 5;
  return CPythonVM::SetValueInternal(this, hScope, pszKey, &value, pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x10003B00
// Name: public: virtual bool CPythonVM::SetValue(struct HSCRIPT__ __near *,char const __near *,struct ScriptVariant_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPythonVM::SetValue(
        CPythonVM *this,
        HSCRIPT__ *hScope,
        const char *pszKey,
        const ScriptVariant_t *value)
{
  return CPythonVM::SetValueInternal(this, hScope, pszKey, value, pszValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10003B20
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct _typeobject __near *>,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_33:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *)this,
           result: &v15,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = &v15;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_pBlockHeader == nullptr;
  v10 = v7->m_nIndex;
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *)CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Next((CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *)this, result: &v14, it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *)&v16);
    }
    v8 = v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_0 < 10 )
      {
        ++_executeCount_0;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v10] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v13 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount >= 10 )
    return nullptr;
  ++_executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003CA0
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_33:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Next(
           this: &this->m_Memory,
           result: &v15,
           it: &this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = &v15;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_pBlockHeader == nullptr;
  v10 = v7->m_nIndex;
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *)CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::Next(this: &this->m_Memory, result: &v14, it: &this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::First(
              this: &this->m_Memory,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_2 < 10 )
      {
        ++_executeCount_2;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v10] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v13 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_1 >= 10 )
    return nullptr;
  ++_executeCount_1;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003E20
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003E90
// Name: public: int CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::Find(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(
        CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *this,
        unsigned int uiKey)
{
  int result; // eax

  result = this->m_aBuckets.m_Memory.m_pMemory[this->m_uiBucketMask
                                             & (HIBYTE(uiKey)
                                              + 33
                                              * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)))];
  if ( result == 0 )
    return -1;
  while ( *(_DWORD *)result != uiKey )
  {
    result = *(_DWORD *)(result + 12);
    if ( result == 0 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003F00
// Name: public: void CUtlLinkedList<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::HashFastData_t_<struct ScriptClassDesc_t __near *>,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::Unlink(
        CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > > *this,
        unsigned int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 8) != elem )
  {
    v3 = *(_DWORD *)(elem + 8);
    v4 = *(_DWORD *)(elem + 12);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 12) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 8) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 12) = elem;
    *(_DWORD *)(elem + 8) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003F60
// Name: public: int CUtlVector<struct ScriptVariant_t,class CUtlMemoryFixed<struct ScriptVariant_t,14,0>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0>>::InsertMultipleBefore(
        CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int v6; // eax
  char *v7; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  this->m_Size += num;
  v6 = this->m_Size - elem - num;
  this->m_pElements = (ScriptVariant_t *)this;
  if ( v6 <= 0 )
    goto LABEL_6;
  if ( num > 0 )
  {
    _V_memmove(dest: (char *)this + 8 * elem + 8 * num, src: (char *)this + 8 * elem, count: 8 * v6);
LABEL_6:
    if ( num > 0 )
    {
      v7 = &this->m_Memory.m_Memory[8 * elem];
      do
      {
        if ( v7 != nullptr )
        {
          *((_WORD *)v7 + 2) = 0;
          *((_WORD *)v7 + 3) = 0;
          *(_DWORD *)v7 = 0;
        }
        v7 += 8;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003FE0
// Name: private: static int CPythonVM::InitInstance(struct scriptClassInstance_t __near *,struct _object __near *,struct _object __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CPythonVM::InitInstance(scriptClassInstance_t *pSelf)
{
  _object *v1; // eax
  CPythonVM *v2; // ecx
  int v3; // eax
  ScriptClassDesc_t *v4; // eax
  int (*m_pfnConstruct)(void); // eax

  pSelf->instanceContext.pInstance = nullptr;
  pSelf->instanceContext.pClassDesc = nullptr;
  pSelf->instanceContext.pPyName = nullptr;
  v1 = (_object *)_PyDict_New();
  v2 = g_pVm;
  pSelf->pDict = v1;
  v3 = CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(
         this: &v2->m_ClassMap,
         uiKey: (unsigned int)pSelf->ob_type);
  if ( v3 == -1 )
    return -1;
  v4 = *(ScriptClassDesc_t **)(v3 + 4);
  if ( v4 == nullptr )
    return -1;
  pSelf->instanceContext.pClassDesc = v4;
  m_pfnConstruct = (int (*)(void))v4->m_pfnConstruct;
  if ( m_pfnConstruct != nullptr )
    pSelf->instanceContext.pInstance = (void *)m_pfnConstruct();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004040
// Name: private: static void CPythonVM::FreeInstance(struct scriptClassInstance_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CPythonVM::FreeInstance(scriptClassInstance_t *pSelf)
{
  int v1; // eax
  int v2; // eax
  void (__cdecl *v3)(void *); // eax
  _object *pPyName; // eax
  _object *v5; // eax
  _object *pDict; // ecx

  if ( pSelf != nullptr )
  {
    v1 = CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(
           this: &g_pVm->m_ClassMap,
           uiKey: (unsigned int)pSelf->ob_type);
    if ( v1 != -1 )
    {
      v2 = *(_DWORD *)(v1 + 4);
      if ( v2 != 0 )
      {
        v3 = *(void (__cdecl **)(void *))(v2 + 40);
        if ( v3 != nullptr )
          v3(a1: pSelf->instanceContext.pInstance);
      }
    }
  }
  pPyName = pSelf->instanceContext.pPyName;
  pSelf->instanceContext.pInstance = nullptr;
  if ( pPyName != nullptr )
  {
    --pPyName->ob_refcnt;
    v5 = pSelf->instanceContext.pPyName;
    if ( v5->ob_refcnt == 0 )
      v5->ob_type->tp_dealloc(a1: pSelf->instanceContext.pPyName);
  }
  if ( pSelf->pDict != nullptr )
  {
    --pSelf->pDict->ob_refcnt;
    pDict = pSelf->pDict;
    if ( pDict->ob_refcnt == 0 )
      pDict->ob_type->tp_dealloc(a1: pSelf->pDict);
  }
  pSelf->ob_type->tp_free(a1: pSelf);
}

//------------------------------------------------------------------------------
// Address: 0x100040E0
// Name: public: struct _typeobject __near * CPythonVM::CreateClass(struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
_typeobject *__thiscall CPythonVM::CreateClass(CPythonVM *this, ScriptClassDesc_t *pDesc)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebp
  ScriptClassDesc_t *v6; // ecx
  int Dict; // eax
  int v8; // eax
  int v9; // eax
  int m_Size; // esi
  const char **v11; // eax
  int v12; // ecx
  const char **v13; // edx
  int v14; // eax
  int v15; // edi
  ScriptFunctionBinding_t *m_pMemory; // ecx
  const char *m_pszScriptName; // esi
  ScriptFunctionBinding_t *v18; // ecx
  const char **v19; // ecx
  PyMethodDef *pmethods; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int v22; // [esp+18h] [ebp-4h]

  if ( (`CPythonVM::CreateClass'::`2'::`local static guard' & 1) == 0 )
  {
    `CPythonVM::CreateClass'::`2'::`local static guard' |= 1u;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_getattro = (_object *(__cdecl *)(_object *, _object *))_PyObject_GenericGetAttr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_setattro = (int (__cdecl *)(_object *, _object *, _object *))_PyObject_GenericSetAttr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_as_buffer = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_flags = 131563;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_doc = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_traverse = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_clear = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_richcompare = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_weaklistoffset = 0;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_iter = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_iternext = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_methods = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_members = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_getset = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_base = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_dict = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_descr_get = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_descr_set = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_dictoffset = 8;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_init = nullptr;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_alloc = (_object *(__cdecl *)(_typeobject *, int))_PyType_GenericAlloc;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_new = (_object *(__cdecl *)(_typeobject *, _object *, _object *))_PyType_GenericNew;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_free = (void (__cdecl *)(void *))_PyObject_Free;
    *(_QWORD *)&`CPythonVM::CreateClass'::`2'::scriptClassType.tp_is_gc = 0;
    *(_QWORD *)&`CPythonVM::CreateClass'::`2'::scriptClassType.tp_mro = 0;
    *(_QWORD *)&`CPythonVM::CreateClass'::`2'::scriptClassType.tp_subclasses = 0;
    `CPythonVM::CreateClass'::`2'::scriptClassType.tp_del = nullptr;
  }
  v3 = (_DWORD *)_PyMem_Malloc(a1: 192);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  this->m_rgpClassDefs[this->m_iClassDef++] = v3;
  _V_memcpy(dest: v3, src: &`CPythonVM::CreateClass'::`2'::scriptClassType, count: 192);
  v6 = pDesc;
  v4[22] = pDesc->m_pszDescription;
  v4[3] = pDesc->m_pszScriptName;
  if ( pDesc->m_pBaseDesc != nullptr )
  {
    if ( this->m_pValveScope->m_pPyModule != nullptr )
    {
      Dict = _PyModule_GetDict(a1: this->m_pValveScope->m_pPyModule);
      v6 = pDesc;
    }
    else
    {
      Dict = 0;
    }
    if ( _PyDict_GetItemString(a1: Dict, a2: v6->m_pBaseDesc->m_pszScriptName) == 0 )
      return nullptr;
    if ( pDesc->m_pBaseDesc == nullptr )
      return nullptr;
    v8 = CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(
           this: (CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *)&g_pVm->m_TypeMap,
           uiKey: (unsigned int)pDesc->m_pBaseDesc);
    if ( v8 == -1 )
      return nullptr;
    v9 = *(_DWORD *)(v8 + 4);
    if ( v9 == 0 )
      return nullptr;
    v6 = pDesc;
    v4[32] = v9;
  }
  v4[39] = _PyType_GenericNew;
  v4[37] = CPythonVM::InitInstance;
  v4[38] = _PyType_GenericAlloc;
  v4[40] = _PyObject_Free;
  v4[6] = CPythonVM::FreeInstance;
  m_Size = v6->m_FunctionBindings.m_Size;
  if ( m_Size != 0 )
  {
    v11 = (const char **)_PyMem_Malloc(a1: 16 * (m_Size + 1));
    i = (int)v11;
    if ( v11 != nullptr )
    {
      this->m_rgpMethodDefs[this->m_iMethodDef++] = v11;
      v12 = 0;
      if ( m_Size > 0 )
      {
        v13 = v11 + 3;
        v14 = g_proxyid;
        v15 = 0;
        pmethods = (PyMethodDef *)m_Size;
        v22 = m_Size;
        do
        {
          m_pMemory = pDesc->m_FunctionBindings.m_Memory.m_pMemory;
          m_pszScriptName = m_pMemory[v15].m_desc.m_pszScriptName;
          v18 = &m_pMemory[v15];
          *(v13 - 3) = m_pszScriptName;
          *(v13 - 1) = (const char *)1;
          *v13 = v18->m_desc.m_pszDescription;
          g_proxies[v14].pBinding = v18;
          *(v13 - 2) = (const char *)g_proxies[v14++].pfn;
          ++v15;
          v13 += 4;
          pmethods = (PyMethodDef *)((char *)pmethods - 1);
        }
        while ( pmethods != nullptr );
        v12 = v22;
        g_proxyid = v14;
        v11 = (const char **)i;
      }
      v19 = &v11[4 * v12];
      *v19 = nullptr;
      v19[1] = nullptr;
      v19[2] = nullptr;
      v19[3] = nullptr;
      v4[29] = v11;
      return (_typeobject *)v4;
    }
    return nullptr;
  }
  return (_typeobject *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10004380
// Name: public: virtual void CPythonVM::SetInstanceUniqeId(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::SetInstanceUniqeId(CPythonVM *this, HSCRIPT__ *hInstance, const char *pszId)
{
  int v3; // eax

  if ( pszId != nullptr && hInstance != nullptr )
  {
    v3 = CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(
           this: &g_pVm->m_ClassMap,
           uiKey: *((_DWORD *)hInstance + 1));
    if ( v3 != -1 && *(_DWORD *)(v3 + 4) != 0 )
      *((_DWORD *)hInstance + 6) = _PyString_FromString(a1: pszId);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100043D0
// Name: public: virtual void CPythonVM::RemoveInstance(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPythonVM::RemoveInstance(CPythonVM *this, _object *hInstance)
{
  unsigned int ob_type; // edi
  int v4; // eax

  if ( hInstance != nullptr )
  {
    ob_type = (unsigned int)hInstance->ob_type;
    v4 = CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(this: &g_pVm->m_ClassMap, uiKey: ob_type);
    if ( v4 != -1 && *(_DWORD *)(v4 + 4) != 0 )
    {
      if ( hInstance->ob_refcnt-- == 1 )
        (*(void (__cdecl **)(_object *))(ob_type + 24))(a1: hInstance);
      CPythonVM::debugRemoveTrackedObject(this, pobj: hInstance);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004420
// Name: public: virtual void __near * CPythonVM::GetInstanceValue(struct HSCRIPT__ __near *,struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CPythonVM::GetInstanceValue(CPythonVM *this, HSCRIPT__ *hInstance, ScriptClassDesc_t *pExpectedType)
{
  int v4; // eax
  const ScriptClassDesc_t *v5; // eax

  if ( hInstance != nullptr
    && (v4 = CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(
               this: &g_pVm->m_ClassMap,
               uiKey: *((_DWORD *)hInstance + 1))) != -1
    && *(_DWORD *)(v4 + 4) != 0
    && (pExpectedType == nullptr
     || (v5 = *((const ScriptClassDesc_t **)hInstance + 5)) == pExpectedType
     || CPythonVM::IsClassDerivedFrom(this, pDerivedClass: v5, pBaseClass: pExpectedType) != 0) )
  {
    return *((void **)hInstance + 4);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004480
// Name: public: int CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::FastInsert(unsigned int,struct _typeobject __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *__thiscall CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::FastInsert(
        CUtlHashFast<_typeobject *,CUtlHashFastGenericHash> *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *uiKey,
        _typeobject *const *data)
{
  CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > > *p_m_aDataPool; // ebp
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *v5; // esi
  unsigned int v7; // edi
  int v8; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *m_Tail; // eax

  p_m_aDataPool = (CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> > > *)&this->m_aDataPool;
  v5 = CUtlLinkedList<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int>>>::AllocInternal(
         this: &this->m_aDataPool,
         multilist: true);
  if ( v5 == nullptr )
    return (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)-1;
  v5->m_pNext = uiKey;
  v5->m_nBlockSize = (int)*data;
  v7 = this->m_uiBucketMask
     & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
  v8 = this->m_aBuckets.m_Memory.m_pMemory[v7];
  CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::Unlink(
    this: p_m_aDataPool,
    elem: (unsigned int)v5);
  v5[1].m_nBlockSize = v8;
  if ( v8 != 0 )
  {
    m_Tail = *(CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t **)(v8 + 8);
    v5[1].m_pNext = m_Tail;
    *(_DWORD *)(v8 + 8) = v5;
  }
  else
  {
    m_Tail = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)p_m_aDataPool->m_Tail;
    v5[1].m_pNext = m_Tail;
    p_m_aDataPool->m_Tail = (int)v5;
  }
  if ( m_Tail != nullptr )
    m_Tail[1].m_nBlockSize = (int)v5;
  else
    p_m_aDataPool->m_Head = (int)v5;
  ++p_m_aDataPool->m_ElementCount;
  this->m_aBuckets.m_Memory.m_pMemory[v7] = (int)v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10004540
// Name: public: int CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::FastInsert(unsigned int,struct ScriptClassDesc_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *__thiscall CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::FastInsert(
        CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *uiKey,
        ScriptClassDesc_t *const *data)
{
  CUtlFixedLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *> > *p_m_aDataPool; // ebp
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *v5; // esi
  unsigned int v7; // edi
  int v8; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_Tail; // eax

  p_m_aDataPool = &this->m_aDataPool;
  v5 = CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::AllocInternal(
         this: &this->m_aDataPool,
         multilist: true);
  if ( v5 == nullptr )
    return (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)-1;
  v5->m_pNext = uiKey;
  v5->m_nBlockSize = (int)*data;
  v7 = this->m_uiBucketMask
     & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
  v8 = this->m_aBuckets.m_Memory.m_pMemory[v7];
  CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::Unlink(
    this: p_m_aDataPool,
    elem: (unsigned int)v5);
  v5[1].m_nBlockSize = v8;
  if ( v8 != 0 )
  {
    m_Tail = *(CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t **)(v8 + 8);
    v5[1].m_pNext = m_Tail;
    *(_DWORD *)(v8 + 8) = v5;
  }
  else
  {
    m_Tail = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)p_m_aDataPool->m_Tail;
    v5[1].m_pNext = m_Tail;
    p_m_aDataPool->m_Tail = (int)v5;
  }
  if ( m_Tail != nullptr )
    m_Tail[1].m_nBlockSize = (int)v5;
  else
    p_m_aDataPool->m_Head = (int)v5;
  ++p_m_aDataPool->m_ElementCount;
  this->m_aBuckets.m_Memory.m_pMemory[v7] = (int)v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10004600
// Name: public: virtual void CPythonVM::DisconnectDebugger(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CPythonVM::DisconnectDebugger()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10004610
// Name: public: int CUtlHashFast<struct _typeobject __near *,class CUtlHashFastGenericHash>::Insert(unsigned int,struct _typeobject __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *__thiscall CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Insert(
        CUtlHashFast<_typeobject *,CUtlHashFastGenericHash> *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *uiKey,
        _typeobject *const *data)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *result; // eax

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find((CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *)this, (unsigned int)uiKey);
  if ( result == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)-1 )
    return CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::FastInsert(this, uiKey, data);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004640
// Name: public: bool CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::Init(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::Init(
        CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *this,
        int nBucketCount)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_aBuckets; // edi
  int i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *v7; // eax

  if ( ((nBucketCount - 1) & nBucketCount) != 0 )
    return 0;
  p_m_aBuckets = &this->m_aBuckets;
  this->m_aBuckets.m_Size = 0;
  CUtlVector<int,CUtlMemory<int,int>>::InsertMultipleBefore(this: &this->m_aBuckets, elem: 0, num: nBucketCount);
  for ( i = 0; i < nBucketCount; ++i )
    p_m_aBuckets->m_Memory.m_pMemory[i] = 0;
  this->m_uiBucketMask = nBucketCount - 1;
  CUtlLinkedList<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int>>>::RemoveAll(this: &this->m_aDataPool);
  m_pBlocks = this->m_aDataPool.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v7 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      free(pMem: v7);
    }
    while ( m_pBlocks != nullptr );
    this->m_aDataPool.m_Memory.m_pBlocks = nullptr;
    this->m_aDataPool.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aDataPool.m_Memory.m_nGrowSize = 2 * nBucketCount;
  this->m_aDataPool.m_pElements = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100046D0
// Name: public: int CUtlHashFast<struct ScriptClassDesc_t __near *,class CUtlHashFastGenericHash>::Insert(unsigned int,struct ScriptClassDesc_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *__thiscall CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::Insert(
        CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *uiKey,
        ScriptClassDesc_t *const *data)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *result; // eax

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(this, (unsigned int)uiKey);
  if ( result == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)-1 )
    return CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::FastInsert(this, uiKey, data);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004700
// Name: public: virtual bool CPythonVM::RegisterClass(struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPythonVM::RegisterClass(CPythonVM *this, ScriptClassDesc_t *pClassDesc)
{
  _object *m_pPyModule; // ecx
  int Dict; // ebp
  ScriptClassDesc_t *v5; // edi
  int v7; // eax
  _typeobject *Class; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *v9; // esi
  _typeobject *pnewtype; // [esp+Ch] [ebp-8h]
  _typeobject *data; // [esp+10h] [ebp-4h] BYREF

  m_pPyModule = this->m_pValveScope->m_pPyModule;
  pnewtype = (_typeobject *)m_pPyModule;
  if ( m_pPyModule != nullptr )
    Dict = _PyModule_GetDict(a1: m_pPyModule);
  else
    Dict = 0;
  v5 = pClassDesc;
  if ( _PyDict_GetItemString(a1: Dict, a2: pClassDesc->m_pszScriptName) != 0 )
    return 1;
  v7 = CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Find(
         this: (CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *)&g_pVm->m_TypeMap,
         uiKey: (unsigned int)v5);
  if ( v7 != -1 && *(_DWORD *)(v7 + 4) != 0 )
    return 1;
  if ( v5->m_pBaseDesc != nullptr )
    CPythonVM::RegisterClass(this, pClassDesc: v5->m_pBaseDesc);
  Class = CPythonVM::CreateClass(this, pDesc: v5);
  v9 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::HashFastData_t_<ScriptClassDesc_t *>,int> >::BlockHeader_t *)Class;
  data = Class;
  if ( Class == nullptr )
    return 0;
  if ( _PyType_Ready(a1: Class) < 0 )
    return 0;
  ++v9->m_pNext;
  _PyModule_AddObject(a1: pnewtype, a2: v5->m_pszScriptName, a3: v9);
  CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::Insert(
    this: &this->m_TypeMap,
    uiKey: (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<_typeobject *,CUtlHashFastGenericHash>::HashFastData_t_<_typeobject *>,int> >::BlockHeader_t *)v5,
    &data);
  CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::Insert(
    this: &this->m_ClassMap,
    uiKey: v9,
    data: &pClassDesc);
  if ( _PyDict_GetItemString(a1: Dict, a2: v5->m_pszScriptName) == 0 )
    return 0;
  CPythonVM::PyPrintError(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004800
// Name: public: virtual struct HSCRIPT__ __near * CPythonVM::RegisterInstance(struct ScriptClassDesc_t __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CPythonVM::RegisterInstance(CPythonVM *this, ScriptClassDesc_t *pDesc, void *pInstance)
{
  _object *m_pPyModule; // eax
  int v6; // ecx
  int ItemString; // edi
  _DWORD *v8; // esi
  int v9; // edx

  if ( CPythonVM::RegisterClass(this, pClassDesc: pDesc) == 0 )
    return nullptr;
  m_pPyModule = this->m_pValveScope->m_pPyModule;
  if ( m_pPyModule != nullptr )
    m_pPyModule = (_object *)_PyModule_GetDict(a1: this->m_pValveScope->m_pPyModule);
  ItemString = _PyDict_GetItemString(a1: m_pPyModule, a2: pDesc->m_pszScriptName);
  v8 = nullptr;
  if ( ItemString != 0 && _PyCallable_Check(a1: ItemString) != 0 )
  {
    v8 = (_DWORD *)_PyObject_CallObject(a1: ItemString, a2: 0);
    v9 = v8[1];
    v8[3] = 71717171;
    if ( *(const char **)(v9 + 12) != pDesc->m_pszScriptName )
      return nullptr;
    v8[4] = pInstance;
    v8[6] = 0;
    v8[5] = pDesc;
    v8[2] = _PyDict_New();
  }
  if ( _PyErr_Occurred(a1: v6) != 0 )
    _PyErr_Print();
  return (HSCRIPT__ *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x100048B0
// Name: public: static struct _object __near * CPythonVM::TranslateCall(struct ScriptFunctionBinding_t __near *,struct scriptClassInstance_t __near *,struct _object __near *)
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
_object *__cdecl CPythonVM::TranslateCall(
        ScriptFunctionBinding_t *pVMScriptFunction,
        scriptClassInstance_t *pSelf,
        _object *pArgs)
{
  int v3; // eax
  ScriptFunctionBinding_t *v4; // ebp
  int m_Size; // edi
  int v6; // esi
  int *m_pMemory; // ebx
  int v8; // esi
  int Item; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  _typeobject *v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char v17; // al
  InstanceContext_t *p_instanceContext; // ecx
  _object *result; // eax
  int pInstance; // eax
  ScriptClassDesc_t *pClassDesc; // edx
  ScriptVariant_t returnValue; // [esp+10h] [ebp-84h] BYREF
  CUtlVectorFixed<ScriptVariant_t,14> params; // [esp+18h] [ebp-7Ch] BYREF
  char *v24; // [esp+90h] [ebp-4h]

  v3 = _PyTuple_Size(a1: pArgs);
  v4 = pVMScriptFunction;
  m_Size = pVMScriptFunction->m_desc.m_Parameters.m_Size;
  v6 = v3;
  v24 = &params.m_Memory.m_Memory[4];
  *(_WORD *)params.m_Memory.m_Memory = 0;
  *(_WORD *)&params.m_Memory.m_Memory[2] = 0;
  *(_DWORD *)&returnValue.m_type = 0;
  params.m_pElements = nullptr;
  CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0>>::InsertMultipleBefore(
    this: (CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0> > *)&params.m_Memory.m_Memory[4],
    elem: 0,
    num: m_Size);
  if ( v6 == 0 )
    goto LABEL_34;
  returnValue.m_int = v6;
  if ( v6 >= m_Size )
    returnValue.m_int = m_Size;
  m_pMemory = pVMScriptFunction->m_desc.m_Parameters.m_Memory.m_pMemory;
  v8 = 0;
  if ( returnValue.m_int <= 0 )
  {
LABEL_34:
    if ( (v4->m_flags & 1) != 0 )
    {
      p_instanceContext = &pSelf->instanceContext;
      if ( pSelf == (scriptClassInstance_t *)-16 )
        goto LABEL_36;
      pInstance = (int)p_instanceContext->pInstance;
      if ( p_instanceContext->pInstance == nullptr )
        goto LABEL_36;
      pClassDesc = pSelf->instanceContext.pClassDesc;
      if ( pClassDesc->pHelper != nullptr )
        pInstance = (int)pClassDesc->pHelper->GetProxied(this: pClassDesc->pHelper, a2: (void *)pInstance);
      if ( pInstance == 0 )
      {
LABEL_36:
        _PyErr_SetString(a1: _PyExc_ValueError, a2: "Accessed null instance");
        return nullptr;
      }
    }
    else
    {
      pInstance = 0;
    }
    v4->m_pfnBinding(
      a1: v4->m_pFunction,
      a2: (void *)pInstance,
      a3: (ScriptVariant_t *)&params.m_Memory.m_Memory[4],
      a4: (int)params.m_pElements,
      a5: v4->m_desc.m_ReturnType != 0 ? (ScriptVariant_t *)&returnValue.m_type : nullptr);
    if ( v4->m_desc.m_ReturnType == 0 )
      return (_object *)++__Py_NoneStruct.ob_refcnt;
    result = CPythonVM::ConvertToPyObject(
               this: g_pVm,
               value: (const ScriptVariant_t *)&returnValue.m_type,
               bAllocNewVector: 0);
    if ( result == nullptr )
      return (_object *)++__Py_NoneStruct.ob_refcnt;
    return result;
  }
  while ( 2 )
  {
    Item = _PyTuple_GetItem(a1: pArgs, a2: v8);
    switch ( *m_pMemory )
    {
      case 1:
        v10 = *(_DWORD *)(Item + 4);
        if ( v10 == _PyFloat_Type.ob_refcnt || _PyType_IsSubtype(a1: v10, a2: _PyFloat_Type.ob_refcnt) != 0 )
        {
          *(float *)&params.m_Memory.m_Memory[8 * v8 + 4] = _PyFloat_AsDouble(a1: Item);
          *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 1;
          goto LABEL_32;
        }
        _PyErr_SetString(a1: _PyExc_ValueError, a2: "expected float argument");
        return nullptr;
      case 3:
        v13 = *(_typeobject **)(Item + 4);
        if ( v13 == &PyTypeVector
          || v13 == (_typeobject *)_PyString_Type.ob_refcnt
          || _PyType_IsSubtype(a1: v13, a2: _PyString_Type.ob_refcnt) != 0 )
        {
          Item = *(_DWORD *)(Item + 12);
          if ( Item == 0 )
            goto LABEL_32;
          *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 3;
          goto LABEL_31;
        }
        _PyErr_SetString(a1: _PyExc_ValueError, a2: "expected vector argument");
        return nullptr;
      case 5:
        v14 = *(_DWORD *)(Item + 4);
        if ( v14 == _PyInt_Type.ob_refcnt || _PyType_IsSubtype(a1: v14, a2: _PyInt_Type.ob_refcnt) != 0 )
        {
          v15 = _PyInt_AsLong(a1: Item);
          *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 5;
          *(_DWORD *)&params.m_Memory.m_Memory[8 * v8 + 4] = v15;
          goto LABEL_32;
        }
        _PyErr_SetString(a1: _PyExc_ValueError, a2: "expected integer argument");
        return nullptr;
      case 6:
        if ( Item == __Py_ZeroStruct.ob_refcnt )
        {
          *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 6;
          params.m_Memory.m_Memory[8 * v8 + 4] = 0;
          goto LABEL_32;
        }
        if ( Item == __Py_TrueStruct.ob_refcnt )
        {
          *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 6;
          params.m_Memory.m_Memory[8 * v8 + 4] = 1;
          goto LABEL_32;
        }
        _PyErr_SetString(a1: _PyExc_ValueError, a2: "expected boolean argument");
        return nullptr;
      case 8:
        v16 = *(_DWORD *)(Item + 4);
        if ( v16 != _PyString_Type.ob_refcnt && _PyType_IsSubtype(a1: v16, a2: _PyString_Type.ob_refcnt) == 0 )
          goto LABEL_38;
        v17 = *(_BYTE *)_PyString_AsString(a1: Item);
        *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 8;
        params.m_Memory.m_Memory[8 * v8 + 4] = v17;
        goto $LN373;
      case 32:
        v11 = *(_DWORD *)(Item + 4);
        if ( v11 != _PyString_Type.ob_refcnt && _PyType_IsSubtype(a1: v11, a2: _PyString_Type.ob_refcnt) == 0 )
        {
LABEL_38:
          _PyErr_SetString(a1: _PyExc_ValueError, a2: "expected string argument");
          return nullptr;
        }
        v12 = _PyString_AsString(a1: Item);
        *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 32;
        *(_DWORD *)&params.m_Memory.m_Memory[8 * v8 + 4] = v12;
        goto LABEL_32;
      case 33:
$LN373:
        if ( Item == __Py_NoneStruct.ob_refcnt )
        {
          *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 33;
          *(_DWORD *)&params.m_Memory.m_Memory[8 * v8 + 4] = 0;
LABEL_32:
          ++v8;
          ++m_pMemory;
          if ( v8 >= returnValue.m_int )
          {
            v4 = pVMScriptFunction;
            goto LABEL_34;
          }
          continue;
        }
        if ( *(_DWORD *)(Item + 12) == 71717171 )
        {
          *(_WORD *)&params.m_Memory.m_Memory[8 * v8 + 8] = 33;
LABEL_31:
          *(_DWORD *)&params.m_Memory.m_Memory[8 * v8 + 4] = Item;
          goto LABEL_32;
        }
        _PyErr_SetString(a1: _PyExc_ValueError, a2: "expected HSCRIPT instance object argument");
        return nullptr;
      default:
        goto LABEL_32;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004CB0
// Name: class IScriptVM __near * ScriptCreatePythonVM(void)
// Source: json
//------------------------------------------------------------------------------
CPythonVM *__cdecl ScriptCreatePythonVM()
{
  CPythonVM *result; // eax
  CPythonVM *v1; // eax

  result = g_pVm;
  if ( g_pVm != nullptr )
  {
    g_pVm->m_bInitialized = true;
  }
  else
  {
    v1 = (CPythonVM *)operator new(nSize: 0x1980u);
    if ( v1 != nullptr )
    {
      result = CPythonVM::CPythonVM(this: v1);
      g_pVm = result;
    }
    else
    {
      g_pVm = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004CF0
// Name: Translate_0
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_0(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[0].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004D10
// Name: Translate_1
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_1(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[1].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004D30
// Name: Translate_2
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_2(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[2].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004D50
// Name: Translate_3
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_3(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[3].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004D70
// Name: Translate_4
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_4(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[4].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004D90
// Name: Translate_5
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_5(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[5].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004DB0
// Name: Translate_6
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_6(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[6].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004DD0
// Name: Translate_7
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_7(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[7].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004DF0
// Name: Translate_8
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_8(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[8].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004E10
// Name: Translate_9
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_9(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[9].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004E30
// Name: Translate_10
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_10(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[10].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004E50
// Name: Translate_11
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_11(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[11].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004E70
// Name: Translate_12
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_12(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[12].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004E90
// Name: Translate_13
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_13(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[13].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004EB0
// Name: Translate_14
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_14(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[14].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004ED0
// Name: Translate_15
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_15(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[15].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004EF0
// Name: Translate_16
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_16(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[16].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004F10
// Name: Translate_17
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_17(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[17].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004F30
// Name: Translate_18
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_18(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[18].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004F50
// Name: Translate_19
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_19(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[19].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004F70
// Name: Translate_20
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_20(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[20].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004F90
// Name: Translate_21
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_21(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[21].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004FB0
// Name: Translate_22
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_22(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[22].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004FD0
// Name: Translate_23
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_23(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[23].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10004FF0
// Name: Translate_24
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_24(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[24].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005010
// Name: Translate_25
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_25(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[25].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005030
// Name: Translate_26
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_26(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[26].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005050
// Name: Translate_27
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_27(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[27].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005070
// Name: Translate_28
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_28(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[28].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005090
// Name: Translate_29
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_29(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[29].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100050B0
// Name: Translate_30
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_30(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[30].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100050D0
// Name: Translate_31
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_31(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[31].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100050F0
// Name: Translate_32
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_32(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[32].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005110
// Name: Translate_33
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_33(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[33].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005130
// Name: Translate_34
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_34(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[34].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005150
// Name: Translate_35
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_35(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[35].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005170
// Name: Translate_36
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_36(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[36].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005190
// Name: Translate_37
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_37(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[37].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100051B0
// Name: Translate_38
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_38(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[38].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100051D0
// Name: Translate_39
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_39(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[39].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100051F0
// Name: Translate_40
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_40(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[40].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005210
// Name: Translate_41
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_41(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[41].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005230
// Name: Translate_42
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_42(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[42].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005250
// Name: Translate_43
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_43(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[43].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005270
// Name: Translate_44
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_44(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[44].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005290
// Name: Translate_45
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_45(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[45].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100052B0
// Name: Translate_46
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_46(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[46].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100052D0
// Name: Translate_47
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_47(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[47].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100052F0
// Name: Translate_48
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_48(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[48].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005310
// Name: Translate_49
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_49(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[49].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005330
// Name: Translate_50
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_50(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[50].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005350
// Name: Translate_51
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_51(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[51].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005370
// Name: Translate_52
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_52(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[52].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005390
// Name: Translate_53
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_53(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[53].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100053B0
// Name: Translate_54
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_54(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[54].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100053D0
// Name: Translate_55
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_55(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[55].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100053F0
// Name: Translate_56
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_56(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[56].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005410
// Name: Translate_57
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_57(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[57].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005430
// Name: Translate_58
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_58(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[58].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005450
// Name: Translate_59
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_59(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[59].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005470
// Name: Translate_60
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_60(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[60].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005490
// Name: Translate_61
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_61(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[61].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100054B0
// Name: Translate_62
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_62(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[62].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100054D0
// Name: Translate_63
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_63(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[63].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100054F0
// Name: Translate_64
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_64(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[64].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005510
// Name: Translate_65
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_65(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[65].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005530
// Name: Translate_66
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_66(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[66].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005550
// Name: Translate_67
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_67(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[67].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005570
// Name: Translate_68
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_68(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[68].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005590
// Name: Translate_69
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_69(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[69].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100055B0
// Name: Translate_70
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_70(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[70].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100055D0
// Name: Translate_71
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_71(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[71].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100055F0
// Name: Translate_72
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_72(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[72].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005610
// Name: Translate_73
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_73(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[73].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005630
// Name: Translate_74
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_74(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[74].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005650
// Name: Translate_75
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_75(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[75].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005670
// Name: Translate_76
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_76(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[76].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005690
// Name: Translate_77
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_77(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[77].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100056B0
// Name: Translate_78
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_78(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[78].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100056D0
// Name: Translate_79
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_79(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[79].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100056F0
// Name: Translate_80
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_80(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[80].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005710
// Name: Translate_81
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_81(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[81].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005730
// Name: Translate_82
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_82(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[82].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005750
// Name: Translate_83
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_83(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[83].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005770
// Name: Translate_84
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_84(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[84].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005790
// Name: Translate_85
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_85(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[85].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100057B0
// Name: Translate_86
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_86(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[86].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100057D0
// Name: Translate_87
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_87(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[87].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100057F0
// Name: Translate_88
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_88(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[88].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005810
// Name: Translate_89
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_89(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[89].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005830
// Name: Translate_90
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_90(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[90].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005850
// Name: Translate_91
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_91(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[91].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005870
// Name: Translate_92
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_92(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[92].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005890
// Name: Translate_93
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_93(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[93].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100058B0
// Name: Translate_94
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_94(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[94].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100058D0
// Name: Translate_95
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_95(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[95].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100058F0
// Name: Translate_96
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_96(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[96].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005910
// Name: Translate_97
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_97(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[97].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005930
// Name: Translate_98
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_98(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[98].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005950
// Name: Translate_99
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_99(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[99].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005970
// Name: Translate_100
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_100(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[100].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005990
// Name: Translate_101
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_101(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[101].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100059B0
// Name: Translate_102
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_102(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[102].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100059D0
// Name: Translate_103
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_103(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[103].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100059F0
// Name: Translate_104
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_104(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[104].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005A10
// Name: Translate_105
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_105(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[105].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005A30
// Name: Translate_106
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_106(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[106].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005A50
// Name: Translate_107
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_107(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[107].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005A70
// Name: Translate_108
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_108(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[108].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005A90
// Name: Translate_109
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_109(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[109].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005AB0
// Name: Translate_110
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_110(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[110].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005AD0
// Name: Translate_111
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_111(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[111].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005AF0
// Name: Translate_112
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_112(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[112].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005B10
// Name: Translate_113
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_113(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[113].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005B30
// Name: Translate_114
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_114(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[114].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005B50
// Name: Translate_115
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_115(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[115].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005B70
// Name: Translate_116
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_116(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[116].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005B90
// Name: Translate_117
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_117(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[117].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005BB0
// Name: Translate_118
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_118(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[118].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005BD0
// Name: Translate_119
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_119(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[119].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005BF0
// Name: Translate_120
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_120(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[120].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005C10
// Name: Translate_121
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_121(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[121].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005C30
// Name: Translate_122
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_122(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[122].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005C50
// Name: Translate_123
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_123(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[123].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005C70
// Name: Translate_124
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_124(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[124].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005C90
// Name: Translate_125
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_125(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[125].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005CB0
// Name: Translate_126
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_126(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[126].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005CD0
// Name: Translate_127
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_127(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[127].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005CF0
// Name: Translate_128
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_128(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[128].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005D10
// Name: Translate_129
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_129(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[129].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005D30
// Name: Translate_130
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_130(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[130].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005D50
// Name: Translate_131
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_131(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[131].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005D70
// Name: Translate_132
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_132(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[132].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005D90
// Name: Translate_133
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_133(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[133].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005DB0
// Name: Translate_134
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_134(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[134].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005DD0
// Name: Translate_135
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_135(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[135].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005DF0
// Name: Translate_136
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_136(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[136].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005E10
// Name: Translate_137
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_137(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[137].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005E30
// Name: Translate_138
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_138(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[138].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005E50
// Name: Translate_139
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_139(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[139].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005E70
// Name: Translate_140
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_140(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[140].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005E90
// Name: Translate_141
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_141(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[141].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005EB0
// Name: Translate_142
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_142(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[142].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005ED0
// Name: Translate_143
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_143(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[143].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005EF0
// Name: Translate_144
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_144(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[144].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005F10
// Name: Translate_145
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_145(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[145].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005F30
// Name: Translate_146
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_146(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[146].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005F50
// Name: Translate_147
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_147(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[147].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005F70
// Name: Translate_148
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_148(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[148].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005F90
// Name: Translate_149
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_149(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[149].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005FB0
// Name: Translate_150
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_150(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[150].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005FD0
// Name: Translate_151
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_151(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[151].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10005FF0
// Name: Translate_152
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_152(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[152].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006010
// Name: Translate_153
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_153(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[153].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006030
// Name: Translate_154
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_154(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[154].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006050
// Name: Translate_155
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_155(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[155].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006070
// Name: Translate_156
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_156(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[156].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006090
// Name: Translate_157
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_157(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[157].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100060B0
// Name: Translate_158
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_158(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[158].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100060D0
// Name: Translate_159
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_159(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[159].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100060F0
// Name: Translate_160
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_160(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[160].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006110
// Name: Translate_161
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_161(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[161].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006130
// Name: Translate_162
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_162(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[162].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006150
// Name: Translate_163
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_163(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[163].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006170
// Name: Translate_164
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_164(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[164].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006190
// Name: Translate_165
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_165(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[165].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100061B0
// Name: Translate_166
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_166(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[166].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100061D0
// Name: Translate_167
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_167(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[167].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100061F0
// Name: Translate_168
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_168(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[168].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006210
// Name: Translate_169
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_169(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[169].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006230
// Name: Translate_170
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_170(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[170].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006250
// Name: Translate_171
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_171(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[171].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006270
// Name: Translate_172
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_172(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[172].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006290
// Name: Translate_173
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_173(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[173].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100062B0
// Name: Translate_174
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_174(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[174].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100062D0
// Name: Translate_175
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_175(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[175].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100062F0
// Name: Translate_176
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_176(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[176].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006310
// Name: Translate_177
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_177(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[177].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006330
// Name: Translate_178
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_178(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[178].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006350
// Name: Translate_179
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_179(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[179].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006370
// Name: Translate_180
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_180(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[180].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006390
// Name: Translate_181
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_181(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[181].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100063B0
// Name: Translate_182
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_182(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[182].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100063D0
// Name: Translate_183
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_183(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[183].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100063F0
// Name: Translate_184
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_184(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[184].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006410
// Name: Translate_185
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_185(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[185].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006430
// Name: Translate_186
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_186(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[186].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006450
// Name: Translate_187
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_187(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[187].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006470
// Name: Translate_188
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_188(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[188].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006490
// Name: Translate_189
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_189(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[189].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100064B0
// Name: Translate_190
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_190(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[190].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100064D0
// Name: Translate_191
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_191(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[191].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100064F0
// Name: Translate_192
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_192(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[192].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006510
// Name: Translate_193
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_193(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[193].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006530
// Name: Translate_194
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_194(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[194].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006550
// Name: Translate_195
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_195(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[195].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006570
// Name: Translate_196
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_196(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[196].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006590
// Name: Translate_197
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_197(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[197].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100065B0
// Name: Translate_198
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_198(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[198].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100065D0
// Name: Translate_199
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_199(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[199].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100065F0
// Name: Translate_200
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_200(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[200].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006610
// Name: Translate_201
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_201(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[201].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006630
// Name: Translate_202
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_202(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[202].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006650
// Name: Translate_203
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_203(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[203].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006670
// Name: Translate_204
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_204(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[204].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006690
// Name: Translate_205
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_205(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[205].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100066B0
// Name: Translate_206
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_206(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[206].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100066D0
// Name: Translate_207
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_207(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[207].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100066F0
// Name: Translate_208
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_208(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[208].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006710
// Name: Translate_209
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_209(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[209].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006730
// Name: Translate_210
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_210(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[210].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006750
// Name: Translate_211
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_211(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[211].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006770
// Name: Translate_212
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_212(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[212].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006790
// Name: Translate_213
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_213(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[213].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100067B0
// Name: Translate_214
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_214(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[214].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100067D0
// Name: Translate_215
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_215(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[215].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100067F0
// Name: Translate_216
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_216(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[216].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006810
// Name: Translate_217
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_217(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[217].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006830
// Name: Translate_218
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_218(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[218].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006850
// Name: Translate_219
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_219(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[219].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006870
// Name: Translate_220
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_220(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[220].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006890
// Name: Translate_221
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_221(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[221].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100068B0
// Name: Translate_222
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_222(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[222].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100068D0
// Name: Translate_223
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_223(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[223].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100068F0
// Name: Translate_224
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_224(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[224].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006910
// Name: Translate_225
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_225(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[225].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: Translate_226
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_226(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[226].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006950
// Name: Translate_227
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_227(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[227].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006970
// Name: Translate_228
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_228(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[228].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006990
// Name: Translate_229
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_229(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[229].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100069B0
// Name: Translate_230
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_230(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[230].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100069D0
// Name: Translate_231
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_231(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[231].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100069F0
// Name: Translate_232
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_232(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[232].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006A10
// Name: Translate_233
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_233(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[233].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006A30
// Name: Translate_234
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_234(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[234].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006A50
// Name: Translate_235
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_235(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[235].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006A70
// Name: Translate_236
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_236(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[236].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006A90
// Name: Translate_237
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_237(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[237].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006AB0
// Name: Translate_238
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_238(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[238].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006AD0
// Name: Translate_239
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_239(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[239].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006AF0
// Name: Translate_240
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_240(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[240].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006B10
// Name: Translate_241
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_241(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[241].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006B30
// Name: Translate_242
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_242(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[242].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006B50
// Name: Translate_243
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_243(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[243].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006B70
// Name: Translate_244
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_244(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[244].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006B90
// Name: Translate_245
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_245(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[245].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006BB0
// Name: Translate_246
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_246(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[246].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006BD0
// Name: Translate_247
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_247(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[247].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006BF0
// Name: Translate_248
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_248(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[248].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006C10
// Name: Translate_249
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_249(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[249].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006C30
// Name: Translate_250
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_250(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[250].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006C50
// Name: Translate_251
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_251(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[251].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006C70
// Name: Translate_252
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_252(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[252].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006C90
// Name: Translate_253
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_253(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[253].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006CB0
// Name: Translate_254
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_254(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[254].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006CD0
// Name: Translate_255
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_255(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[255].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006CF0
// Name: Translate_256
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_256(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[256].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006D10
// Name: Translate_257
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_257(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[257].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006D30
// Name: Translate_258
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_258(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[258].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006D50
// Name: Translate_259
// Source: json
//------------------------------------------------------------------------------
_object *__cdecl Translate_259(_object *pSelf, _object *pArgs)
{
  return CPythonVM::TranslateCall(pVMScriptFunction: g_proxies[259].pBinding, (scriptClassInstance_t *)pSelf, pArgs);
}

//------------------------------------------------------------------------------
// Address: 0x10006D70
// Name: InitProxyTable
// Source: json
//------------------------------------------------------------------------------
void InitProxyTable()
{
  g_proxyid = 0;
  g_proxies[0].pfn = Translate_0;
  g_proxies[1].pfn = Translate_1;
  g_proxies[2].pfn = Translate_2;
  g_proxies[3].pfn = Translate_3;
  g_proxies[4].pfn = Translate_4;
  g_proxies[5].pfn = Translate_5;
  g_proxies[6].pfn = Translate_6;
  g_proxies[7].pfn = Translate_7;
  g_proxies[8].pfn = Translate_8;
  g_proxies[9].pfn = Translate_9;
  g_proxies[10].pfn = Translate_10;
  g_proxies[11].pfn = Translate_11;
  g_proxies[12].pfn = Translate_12;
  g_proxies[13].pfn = Translate_13;
  g_proxies[14].pfn = Translate_14;
  g_proxies[15].pfn = Translate_15;
  g_proxies[16].pfn = Translate_16;
  g_proxies[17].pfn = Translate_17;
  g_proxies[18].pfn = Translate_18;
  g_proxies[19].pfn = Translate_19;
  g_proxies[20].pfn = Translate_20;
  g_proxies[21].pfn = Translate_21;
  g_proxies[22].pfn = Translate_22;
  g_proxies[23].pfn = Translate_23;
  g_proxies[24].pfn = Translate_24;
  g_proxies[25].pfn = Translate_25;
  g_proxies[26].pfn = Translate_26;
  g_proxies[27].pfn = Translate_27;
  g_proxies[28].pfn = Translate_28;
  g_proxies[29].pfn = Translate_29;
  g_proxies[30].pfn = Translate_30;
  g_proxies[31].pfn = Translate_31;
  g_proxies[32].pfn = Translate_32;
  g_proxies[33].pfn = Translate_33;
  g_proxies[34].pfn = Translate_34;
  g_proxies[35].pfn = Translate_35;
  g_proxies[36].pfn = Translate_36;
  g_proxies[37].pfn = Translate_37;
  g_proxies[38].pfn = Translate_38;
  g_proxies[39].pfn = Translate_39;
  g_proxies[40].pfn = Translate_40;
  g_proxies[41].pfn = Translate_41;
  g_proxies[42].pfn = Translate_42;
  g_proxies[43].pfn = Translate_43;
  g_proxies[44].pfn = Translate_44;
  g_proxies[45].pfn = Translate_45;
  g_proxies[46].pfn = Translate_46;
  g_proxies[47].pfn = Translate_47;
  g_proxies[48].pfn = Translate_48;
  g_proxies[49].pfn = Translate_49;
  g_proxies[50].pfn = Translate_50;
  g_proxies[51].pfn = Translate_51;
  g_proxies[52].pfn = Translate_52;
  g_proxies[53].pfn = Translate_53;
  g_proxies[54].pfn = Translate_54;
  g_proxies[55].pfn = Translate_55;
  g_proxies[56].pfn = Translate_56;
  g_proxies[57].pfn = Translate_57;
  g_proxies[58].pfn = Translate_58;
  g_proxies[59].pfn = Translate_59;
  g_proxies[60].pfn = Translate_60;
  g_proxies[61].pfn = Translate_61;
  g_proxies[62].pfn = Translate_62;
  g_proxies[63].pfn = Translate_63;
  g_proxies[64].pfn = Translate_64;
  g_proxies[65].pfn = Translate_65;
  g_proxies[66].pfn = Translate_66;
  g_proxies[67].pfn = Translate_67;
  g_proxies[68].pfn = Translate_68;
  g_proxies[69].pfn = Translate_69;
  g_proxies[70].pfn = Translate_70;
  g_proxies[71].pfn = Translate_71;
  g_proxies[72].pfn = Translate_72;
  g_proxies[73].pfn = Translate_73;
  g_proxies[74].pfn = Translate_74;
  g_proxies[75].pfn = Translate_75;
  g_proxies[76].pfn = Translate_76;
  g_proxies[77].pfn = Translate_77;
  g_proxies[78].pfn = Translate_78;
  g_proxies[79].pfn = Translate_79;
  g_proxies[80].pfn = Translate_80;
  g_proxies[81].pfn = Translate_81;
  g_proxies[82].pfn = Translate_82;
  g_proxies[83].pfn = Translate_83;
  g_proxies[84].pfn = Translate_84;
  g_proxies[85].pfn = Translate_85;
  g_proxies[86].pfn = Translate_86;
  g_proxies[87].pfn = Translate_87;
  g_proxies[88].pfn = Translate_88;
  g_proxies[89].pfn = Translate_89;
  g_proxies[90].pfn = Translate_90;
  g_proxies[91].pfn = Translate_91;
  g_proxies[92].pfn = Translate_92;
  g_proxies[93].pfn = Translate_93;
  g_proxies[94].pfn = Translate_94;
  g_proxies[95].pfn = Translate_95;
  g_proxies[96].pfn = Translate_96;
  g_proxies[97].pfn = Translate_97;
  g_proxies[98].pfn = Translate_98;
  g_proxies[99].pfn = Translate_99;
  g_proxies[100].pfn = Translate_100;
  g_proxies[101].pfn = Translate_101;
  g_proxies[102].pfn = Translate_102;
  g_proxies[103].pfn = Translate_103;
  g_proxies[104].pfn = Translate_104;
  g_proxies[105].pfn = Translate_105;
  g_proxies[106].pfn = Translate_106;
  g_proxies[107].pfn = Translate_107;
  g_proxies[108].pfn = Translate_108;
  g_proxies[109].pfn = Translate_109;
  g_proxies[110].pfn = Translate_110;
  g_proxies[111].pfn = Translate_111;
  g_proxies[112].pfn = Translate_112;
  g_proxies[113].pfn = Translate_113;
  g_proxies[114].pfn = Translate_114;
  g_proxies[115].pfn = Translate_115;
  g_proxies[116].pfn = Translate_116;
  g_proxies[117].pfn = Translate_117;
  g_proxies[118].pfn = Translate_118;
  g_proxies[119].pfn = Translate_119;
  g_proxies[120].pfn = Translate_120;
  g_proxies[121].pfn = Translate_121;
  g_proxies[122].pfn = Translate_122;
  g_proxies[123].pfn = Translate_123;
  g_proxies[124].pfn = Translate_124;
  g_proxies[125].pfn = Translate_125;
  g_proxies[126].pfn = Translate_126;
  g_proxies[127].pfn = Translate_127;
  g_proxies[128].pfn = Translate_128;
  g_proxies[129].pfn = Translate_129;
  g_proxies[130].pfn = Translate_130;
  g_proxies[131].pfn = Translate_131;
  g_proxies[132].pfn = Translate_132;
  g_proxies[133].pfn = Translate_133;
  g_proxies[134].pfn = Translate_134;
  g_proxies[135].pfn = Translate_135;
  g_proxies[136].pfn = Translate_136;
  g_proxies[137].pfn = Translate_137;
  g_proxies[138].pfn = Translate_138;
  g_proxies[139].pfn = Translate_139;
  g_proxies[140].pfn = Translate_140;
  g_proxies[141].pfn = Translate_141;
  g_proxies[142].pfn = Translate_142;
  g_proxies[143].pfn = Translate_143;
  g_proxies[144].pfn = Translate_144;
  g_proxies[145].pfn = Translate_145;
  g_proxies[146].pfn = Translate_146;
  g_proxies[147].pfn = Translate_147;
  g_proxies[148].pfn = Translate_148;
  g_proxies[149].pfn = Translate_149;
  g_proxies[150].pfn = Translate_150;
  g_proxies[151].pfn = Translate_151;
  g_proxies[152].pfn = Translate_152;
  g_proxies[153].pfn = Translate_153;
  g_proxies[154].pfn = Translate_154;
  g_proxies[155].pfn = Translate_155;
  g_proxies[156].pfn = Translate_156;
  g_proxies[157].pfn = Translate_157;
  g_proxies[158].pfn = Translate_158;
  g_proxies[159].pfn = Translate_159;
  g_proxies[160].pfn = Translate_160;
  g_proxies[161].pfn = Translate_161;
  g_proxies[162].pfn = Translate_162;
  g_proxies[163].pfn = Translate_163;
  g_proxies[164].pfn = Translate_164;
  g_proxies[165].pfn = Translate_165;
  g_proxies[166].pfn = Translate_166;
  g_proxies[167].pfn = Translate_167;
  g_proxies[168].pfn = Translate_168;
  g_proxies[169].pfn = Translate_169;
  g_proxies[170].pfn = Translate_170;
  g_proxies[171].pfn = Translate_171;
  g_proxies[172].pfn = Translate_172;
  g_proxies[173].pfn = Translate_173;
  g_proxies[174].pfn = Translate_174;
  g_proxies[175].pfn = Translate_175;
  g_proxies[176].pfn = Translate_176;
  g_proxies[177].pfn = Translate_177;
  g_proxies[178].pfn = Translate_178;
  g_proxies[179].pfn = Translate_179;
  g_proxies[180].pfn = Translate_180;
  g_proxies[181].pfn = Translate_181;
  g_proxies[182].pfn = Translate_182;
  g_proxies[183].pfn = Translate_183;
  g_proxies[184].pfn = Translate_184;
  g_proxies[185].pfn = Translate_185;
  g_proxies[186].pfn = Translate_186;
  g_proxies[187].pfn = Translate_187;
  g_proxies[188].pfn = Translate_188;
  g_proxies[189].pfn = Translate_189;
  g_proxies[190].pfn = Translate_190;
  g_proxies[191].pfn = Translate_191;
  g_proxies[192].pfn = Translate_192;
  g_proxies[193].pfn = Translate_193;
  g_proxies[194].pfn = Translate_194;
  g_proxies[195].pfn = Translate_195;
  g_proxies[196].pfn = Translate_196;
  g_proxies[197].pfn = Translate_197;
  g_proxies[198].pfn = Translate_198;
  g_proxies[199].pfn = Translate_199;
  g_proxies[200].pfn = Translate_200;
  g_proxies[201].pfn = Translate_201;
  g_proxies[202].pfn = Translate_202;
  g_proxies[203].pfn = Translate_203;
  g_proxies[204].pfn = Translate_204;
  g_proxies[205].pfn = Translate_205;
  g_proxies[206].pfn = Translate_206;
  g_proxies[207].pfn = Translate_207;
  g_proxies[208].pfn = Translate_208;
  g_proxies[209].pfn = Translate_209;
  g_proxies[210].pfn = Translate_210;
  g_proxies[211].pfn = Translate_211;
  g_proxies[212].pfn = Translate_212;
  g_proxies[213].pfn = Translate_213;
  g_proxies[214].pfn = Translate_214;
  g_proxies[215].pfn = Translate_215;
  g_proxies[216].pfn = Translate_216;
  g_proxies[217].pfn = Translate_217;
  g_proxies[218].pfn = Translate_218;
  g_proxies[219].pfn = Translate_219;
  g_proxies[220].pfn = Translate_220;
  g_proxies[221].pfn = Translate_221;
  g_proxies[222].pfn = Translate_222;
  g_proxies[223].pfn = Translate_223;
  g_proxies[224].pfn = Translate_224;
  g_proxies[225].pfn = Translate_225;
  g_proxies[226].pfn = Translate_226;
  g_proxies[227].pfn = Translate_227;
  g_proxies[228].pfn = Translate_228;
  g_proxies[229].pfn = Translate_229;
  g_proxies[230].pfn = Translate_230;
  g_proxies[231].pfn = Translate_231;
  g_proxies[232].pfn = Translate_232;
  g_proxies[233].pfn = Translate_233;
  g_proxies[234].pfn = Translate_234;
  g_proxies[235].pfn = Translate_235;
  g_proxies[236].pfn = Translate_236;
  g_proxies[237].pfn = Translate_237;
  g_proxies[238].pfn = Translate_238;
  g_proxies[239].pfn = Translate_239;
  g_proxies[240].pfn = Translate_240;
  g_proxies[241].pfn = Translate_241;
  g_proxies[242].pfn = Translate_242;
  g_proxies[243].pfn = Translate_243;
  g_proxies[244].pfn = Translate_244;
  g_proxies[245].pfn = Translate_245;
  g_proxies[246].pfn = Translate_246;
  g_proxies[247].pfn = Translate_247;
  g_proxies[248].pfn = Translate_248;
  g_proxies[249].pfn = Translate_249;
  g_proxies[250].pfn = Translate_250;
  g_proxies[251].pfn = Translate_251;
  g_proxies[252].pfn = Translate_252;
  g_proxies[253].pfn = Translate_253;
  g_proxies[254].pfn = Translate_254;
  g_proxies[255].pfn = Translate_255;
  g_proxies[256].pfn = Translate_256;
  g_proxies[257].pfn = Translate_257;
  g_proxies[258].pfn = Translate_258;
  g_proxies[259].pfn = Translate_259;
}

//------------------------------------------------------------------------------
// Address: 0x100077B0
// Name: public: virtual bool CPythonVM::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPythonVM::Init(CPythonVM *this)
{
  const char *Version; // esi
  _object *v4; // edi
  void *v5; // ecx
  char *GamePath; // eax
  CPyScope *v7; // eax
  CPyScope *v8; // esi
  _object *v9; // edi
  CPyScope *v10; // eax
  CPyScope *v11; // esi
  _object *v12; // esi
  int v13; // ecx
  int v14; // edi
  int v16; // ecx
  char buffer[68]; // [esp+20h] [ebp-44h] BYREF

  if ( g_pVm->m_bInitialized )
    return 1;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  InitProxyTable();
  _Py_Initialize();
  if ( _Py_IsInitialized() != 0 )
  {
    Version = (const char *)_Py_GetVersion();
    V_strncpy(pDest: &buffer[4], pSrc: Version, maxLen: 6);
    buffer[9] = 0;
    if ( V_strncmp(s1: Version, s2: &buffer[4], count: 5) != 0 )
      DevWarning(a1: "Python25v.dll version mismatch: version %s loaded. Should be 2.5.1!\n", &buffer[4]);
    v4 = (_object *)_PyImport_AddModule(a1: "valve");
    _PyModule_AddStringConstant(a1: v4, a2: "__file__", a3: "<synthetic>");
    _Py_InitModule4(a1: "valve", a2: valvemethods, a3: 0, a4: 0, a5: 1013);
    GamePath = COM_GetGamePath(this: v5);
    V_snprintf(pDest: this->m_szScriptPath, maxLen: 260, pFormat: "%s%cscripts%cvscripts", GamePath, 92, 92);
    _PyRun_SimpleStringFlags(
      a1: "import sys\n"
      "import os\n"
      "import valve\n"
      "p = os.path.join(valve.gamepath(),'scripts','vscripts')\n"
      "sys.path.append( p )\n",
      a2: 0);
    _PyRun_SimpleStringFlags(
      a1: "import valve\n"
      "import sys\n"
      "class StdoutCatcher:\n"
      "\tdef write(self, str):\n"
      "\t\tvalve.vprint(str)\n"
      "class StderrCatcher:\n"
      "\tdef write(self, str):\n"
      "\t\tvalve.vprint(str)\n"
      "sys.stdout = StdoutCatcher()\n"
      "sys.stderr = StderrCatcher()\n",
      a2: 0);
    _PyRun_SimpleStringFlags(a1: "import sys\nprint 'Python path is: ',sys.path\n", a2: 0);
    v7 = (CPyScope *)operator new(nSize: 0x10u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v7->m_pPyModule = nullptr;
      v7->m_pPySelf = nullptr;
      v7->m_pTempDict = (_object *)_PyDict_New();
      v8->m_typeTag = 81818181;
    }
    else
    {
      v8 = nullptr;
    }
    this->m_pValveScope = v8;
    v8->m_pPyModule = v4;
    if ( v4 != nullptr )
      ++v4->ob_refcnt;
    v9 = (_object *)_PyImport_AddModule(a1: "__main__");
    v10 = (CPyScope *)operator new(nSize: 0x10u);
    v11 = v10;
    if ( v10 != nullptr )
    {
      v10->m_pPyModule = nullptr;
      v10->m_pPySelf = nullptr;
      v10->m_pTempDict = (_object *)_PyDict_New();
      v11->m_typeTag = 81818181;
    }
    else
    {
      v11 = nullptr;
    }
    this->m_pRootScope = v11;
    v11->m_pPyModule = v9;
    if ( v9 != nullptr )
      ++v9->ob_refcnt;
    v12 = _PyString_FromString(a1: "init");
    v14 = _PyImport_Import(a1: v12);
    if ( v12 != nullptr && v12->ob_refcnt-- == 1 )
      v12->ob_type->tp_dealloc(a1: v12);
    if ( _PyErr_Occurred(a1: v13) != 0 )
      _PyErr_Print();
    if ( v14 != 0 )
    {
      CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::Init(
        this: (CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash> *)&this->m_TypeMap,
        nBucketCount: 256);
      CUtlHashFast<ScriptClassDesc_t *,CUtlHashFastGenericHash>::Init(this: &this->m_ClassMap, nBucketCount: 256);
      RegisterVector(pmodule: this->m_pValveScope->m_pPyModule);
      if ( _PyErr_Occurred(a1: v16) != 0 )
        _PyErr_Print();
      return 1;
    }
    else
    {
      DevWarning(a1: "CPythonVM.Init(): unable to load main module init.py - module not on PYTHONPATH (sys.path)?");
      return 0;
    }
  }
  else
  {
    DevWarning(a1: "CPythonVM.Init(): python interperter failed to initialize!");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100085D0
// Name: public: void CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008740
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100087B0
// Name: public: int CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::InsertBefore(int,void (*const __near &)(class IConVar __near *,char const __near *,float))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::InsertBefore(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this,
        int elem,
        void (__cdecl **src)(IConVar *, const char *, float))
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // ecx
  int v7; // eax
  bool v8; // zf
  void (__cdecl **v9)(IConVar *, const char *, float); // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008990
// Name: public: virtual bool CPythonVM::Frame(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPythonVM::Frame(CEmptyConVar *this, int nFlags)
{
  return false;
}
