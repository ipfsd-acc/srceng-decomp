// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxbutton.cpp
// Functions: 212
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxbutton.h"

//------------------------------------------------------------------------------
// Address: 0x1006B9C0
// Name: public: static void GConstructorMov<class GPtr<class GFxResource>>::DestructArray(class GPtr<class GFxResource> __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GConstructorMov<GPtr<GFxResource>>::DestructArray(int a1, int a2)
{
  int result; // eax
  int *v3; // edi
  int i; // ebx
  int v5; // esi
  int v6; // ecx

  result = a2;
  v3 = (int *)(a1 + 4 * a2 - 4);
  if ( a2 != 0 )
  {
    for ( i = a2; i != 0; --i )
    {
      v5 = *v3;
      if ( *v3 != 0 )
      {
        result = InterlockedExchangeAdd(Addend: (volatile LONG *)(v5 + 4), Value: -1) - 1;
        if ( result == 0 )
        {
          v6 = *(_DWORD *)(v5 + 8);
          if ( v6 != 0 )
          {
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 4))(a1: v6, a2: v5);
            *(_DWORD *)(v5 + 8) = 0;
          }
          result = (**(int (__thiscall ***)(int, int))v5)(a1: v5, a2: 1);
        }
      }
      --v3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100755B0
// Name: public: static void GConstructorMov<class GPtr<class GFxResource>>::ConstructArray(void __near *,unsigned int,class GPtr<class GFxResource> const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderDevice *__cdecl GConstructorMov<GPtr<GFxResource>>::ConstructArray(
        IShaderDevice **a1,
        IShaderDevice *a2,
        IShaderDevice **a3)
{
  IShaderDevice *result; // eax
  IShaderDevice *i; // ebx

  result = a2;
  if ( a2 != nullptr )
  {
    for ( i = a2; i != nullptr; i = (IShaderDevice *)((char *)i - 1) )
    {
      if ( a1 != nullptr )
      {
        if ( *a3 != nullptr )
          GRefCountImpl::AddRef(this: *a3);
        result = *a3;
        *a1 = *a3;
      }
      ++a3;
      ++a1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075890
// Name: public: static void GConstructorMov<class GString>::DestructArray(class GString __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GConstructorMov<GString>::DestructArray(int a1, int a2)
{
  int result; // eax
  _DWORD *i; // edi
  unsigned int v4; // esi

  result = a2;
  for ( i = (_DWORD *)(a1 + 4 * a2 - 4); a2 != 0; --a2 )
  {
    v4 = *i & 0xFFFFFFFC;
    result = InterlockedExchangeAdd(Addend: (volatile LONG *)(v4 + 4), Value: -1) - 1;
    if ( result == 0 )
      result = ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                 a1: GMemory::pGlobalHeap,
                 a2: v4);
    --i;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10085300
// Name: public: static void GConstructorMov<struct GFxFilterDesc>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IDirect3DStateBlock9 *__cdecl GConstructorMov<GFxFilterDesc>::ConstructArray(
        IDirect3DStateBlock9 *result,
        unsigned int count)
{
  unsigned int v2; // edi
  double v3; // st7
  double v4; // st6
  IDirect3DStateBlock9 *v5; // esi
  IDirect3DStateBlock9 *v6; // eax

  v2 = count;
  if ( count != 0 )
  {
    v3 = 5.0;
    v4 = 0.0;
    v5 = result + 3;
    do
    {
      v6 = v5 - 3;
      if ( v5 != (IDirect3DStateBlock9 *)12 )
      {
        v5[-1].__vftable = nullptr;
        *(float *)&v5->__vftable = v3;
        v5[2].__vftable = (IDirect3DStateBlock9_vtbl *)1;
        *(float *)&v5[1].__vftable = v3;
        *(float *)&v5[3].__vftable = v4;
        *(float *)&v5[4].__vftable = v4;
        *(float *)&v5[7].__vftable = 1.0;
        v6 = (IDirect3DStateBlock9 *)GRenderer::Cxform::Cxform(this: (float *)&v5[8]);
        v3 = 5.0;
        v4 = 0.0;
      }
      v5 += 39;
      --v2;
    }
    while ( v2 != 0 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10085400
// Name: public: static void GConstructorMov<struct GFxFilterDesc>::ConstructArray(void __near *,unsigned int,struct GFxFilterDesc const __near *)
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl GConstructorMov<GFxFilterDesc>::ConstructArray(_BYTE *a1, int a2, _BYTE *a3)
{
  _BYTE *result; // eax
  unsigned int v4; // esi
  unsigned int v5; // ecx
  _BYTE *v6; // ebx
  _BYTE *v7; // edx
  _BYTE *v8; // edx
  unsigned int v9; // ebx
  int v10; // [esp+Ch] [ebp-8h]
  unsigned int v11; // [esp+10h] [ebp-4h]
  float v12; // [esp+1Ch] [ebp+8h]
  float v13; // [esp+1Ch] [ebp+8h]
  float v14; // [esp+1Ch] [ebp+8h]
  float v15; // [esp+1Ch] [ebp+8h]
  float v16; // [esp+1Ch] [ebp+8h]
  int v17; // [esp+20h] [ebp+Ch]

  result = a1;
  v4 = a2;
  v5 = 0;
  v6 = a1;
  if ( a2 >= 4 )
  {
    result = a1 + 340;
    v7 = a3 + 340;
    v11 = ((unsigned int)(a2 - 4) >> 2) + 1;
    v10 = 4 * v11;
    do
    {
      if ( v6 != nullptr )
      {
        *v6 = *a3;
        *((_WORD *)result - 169) = *((_WORD *)v7 - 169);
        *((_WORD *)result - 168) = *((_WORD *)v7 - 168);
        *((_DWORD *)result - 83) = *((_DWORD *)v7 - 83);
        *((float *)result - 82) = *((float *)v7 - 82);
        *((float *)result - 81) = *((float *)v7 - 81);
        *((_DWORD *)result - 80) = *((_DWORD *)v7 - 80);
        v12 = *((float *)v7 - 78);
        *((float *)result - 79) = *((float *)v7 - 79);
        *((float *)result - 78) = v12;
        *((_DWORD *)result - 77) = *((_DWORD *)v7 - 77);
        *((_DWORD *)result - 76) = *((_DWORD *)v7 - 76);
        *((float *)result - 75) = *((float *)v7 - 75);
        qmemcpy(result - 296, v7 - 296, 0x20u);
        qmemcpy(result - 264, v7 - 264, 0x50u);
      }
      if ( result != (_BYTE *)184 )
      {
        *(result - 184) = *(v7 - 184);
        *((_WORD *)result - 91) = *((_WORD *)v7 - 91);
        *((_WORD *)result - 90) = *((_WORD *)v7 - 90);
        *((_DWORD *)result - 44) = *((_DWORD *)v7 - 44);
        *((float *)result - 43) = *((float *)v7 - 43);
        *((float *)result - 42) = *((float *)v7 - 42);
        *((_DWORD *)result - 41) = *((_DWORD *)v7 - 41);
        v13 = *((float *)v7 - 39);
        *((float *)result - 40) = *((float *)v7 - 40);
        *((float *)result - 39) = v13;
        *((_DWORD *)result - 38) = *((_DWORD *)v7 - 38);
        *((_DWORD *)result - 37) = *((_DWORD *)v7 - 37);
        *((float *)result - 36) = *((float *)v7 - 36);
        qmemcpy(result - 140, v7 - 140, 0x20u);
        qmemcpy(result - 108, v7 - 108, 0x50u);
      }
      if ( result != (_BYTE *)28 )
      {
        *(result - 28) = *(v7 - 28);
        *((_WORD *)result - 13) = *((_WORD *)v7 - 13);
        *((_WORD *)result - 12) = *((_WORD *)v7 - 12);
        *((_DWORD *)result - 5) = *((_DWORD *)v7 - 5);
        *((float *)result - 4) = *((float *)v7 - 4);
        *((float *)result - 3) = *((float *)v7 - 3);
        *((_DWORD *)result - 2) = *((_DWORD *)v7 - 2);
        v14 = *(float *)v7;
        *((float *)result - 1) = *((float *)v7 - 1);
        *(float *)result = v14;
        *((_DWORD *)result + 1) = *((_DWORD *)v7 + 1);
        *((_DWORD *)result + 2) = *((_DWORD *)v7 + 2);
        *((float *)result + 3) = *((float *)v7 + 3);
        qmemcpy(result + 16, v7 + 16, 0x20u);
        qmemcpy(result + 48, v7 + 48, 0x50u);
      }
      if ( result != (_BYTE *)-128 )
      {
        result[128] = v7[128];
        *((_WORD *)result + 65) = *((_WORD *)v7 + 65);
        *((_WORD *)result + 66) = *((_WORD *)v7 + 66);
        *((_DWORD *)result + 34) = *((_DWORD *)v7 + 34);
        *((float *)result + 35) = *((float *)v7 + 35);
        *((float *)result + 36) = *((float *)v7 + 36);
        *((_DWORD *)result + 37) = *((_DWORD *)v7 + 37);
        v15 = *((float *)v7 + 39);
        *((float *)result + 38) = *((float *)v7 + 38);
        *((float *)result + 39) = v15;
        *((_DWORD *)result + 40) = *((_DWORD *)v7 + 40);
        *((_DWORD *)result + 41) = *((_DWORD *)v7 + 41);
        *((float *)result + 42) = *((float *)v7 + 42);
        qmemcpy(result + 172, v7 + 172, 0x20u);
        qmemcpy(result + 204, v7 + 204, 0x50u);
      }
      a3 += 624;
      v7 += 624;
      v6 += 624;
      result += 624;
      --v11;
    }
    while ( v11 != 0 );
    v5 = v10;
    v4 = a2;
  }
  if ( v5 < v4 )
  {
    v8 = v6 + 12;
    v17 = v6 - a3 - 12;
    result = a3 + 12;
    v9 = v4 - v5;
    do
    {
      if ( &result[v17] != nullptr )
      {
        result[v17] = *(result - 12);
        *((_WORD *)v8 - 5) = *((_WORD *)result - 5);
        *((_WORD *)v8 - 4) = *((_WORD *)result - 4);
        *((_DWORD *)v8 - 1) = *((_DWORD *)result - 1);
        *(float *)v8 = *(float *)result;
        *((float *)v8 + 1) = *((float *)result + 1);
        *((_DWORD *)v8 + 2) = *((_DWORD *)result + 2);
        v16 = *((float *)result + 4);
        *((float *)v8 + 3) = *((float *)result + 3);
        *((float *)v8 + 4) = v16;
        *((_DWORD *)v8 + 5) = *((_DWORD *)result + 5);
        *((_DWORD *)v8 + 6) = *((_DWORD *)result + 6);
        *((float *)v8 + 7) = *((float *)result + 7);
        qmemcpy(v8 + 32, result + 32, 0x20u);
        qmemcpy(v8 + 64, result + 64, 0x50u);
      }
      v8 += 156;
      result += 156;
      --v9;
    }
    while ( v9 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A7E50
// Name: public: GASPrototype<class GASArrayObject,class GASEnvironment>::GASPrototype<class GASArrayObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
IDirect3DVertexShader9 *__stdcall GASPrototype<GASArrayObject,GASEnvironment>::GASPrototype<GASArrayObject,GASEnvironment>(
        IDirect3DVertexShader9 *this,
        IDirect3DDevice9 **psc,
        unsigned int psc_8)
{
  GASObject *v3; // ecx
  GASObject *v4; // esi
  __int128 v6; // [esp-8h] [ebp-14h]

  v4 = v3;
  GASObject::GASObject(this: v3, a2: (struct GASStringContext *)this);
  v4->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASArrayObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v4[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASArrayObject::`vftable'{for `GASObjectInterface'};
  v4[6].sequence = 0;
  v4[7].pNode = nullptr;
  v4[7].sequence = 0;
  v4[8].pNode = nullptr;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&v4[8].sequence);
  v4[9].pNode = nullptr;
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v4[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)this,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)psc);
  v4[9].sequence = (int)&GASPrototypeBase::`vftable';
  LOBYTE(v4[11].pNode) = 0;
  v4[10].pNode = nullptr;
  v4[10].sequence = 0;
  LOBYTE(v4[12].sequence) = 0;
  v4[11].sequence = 0;
  v4[12].pNode = nullptr;
  v4[13].pNode = nullptr;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)this);
  v4->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASArrayProto::`vftable'{for `GASRefCountBase<GASObject>'};
  v4[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASArrayProto::`vftable'{for `GASObjectInterface'};
  v4[9].sequence = (int)&GASArrayProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)&v4[9].sequence,
    pthis: (CMaterialVar *)v4,
    psc: v6);
  return (IDirect3DVertexShader9 *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A7EE0
// Name: public: virtual void GASPrototype<class GASArrayObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASArrayObject,GASEnvironment>::AddInterface(
        IDirect3DVertexShader9 *this,
        const IDirect3DVertexShader9 *psc)
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x100A7EF0
// Name: public: virtual bool GASPrototype<class GASArrayObject,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASArrayObject,GASEnvironment>::DoesImplement(
        IDirect3DVertexShader9 *this,
        unsigned int penv,
        IDirect3DVertexShader9 *prototype)
{
  if ( this != prototype )
    GASPrototypeBase::DoesImplement(
      this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 19),
      penv);
}

//------------------------------------------------------------------------------
// Address: 0x100A7F30
// Name: public: virtual bool GASPrototype<class GASArrayObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASArrayObject,GASEnvironment>::GetMemberRaw(
        GASPrototypeBase *this,
        _IMAGE_SYMBOL_EX *psc,
        _IMAGE_SYMBOL_EX *name,
        GASValue *val)
{
  unsigned int Short; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  unsigned int v9; // esi
  bool v10; // zf
  const char *v11; // [esp+0h] [ebp-10h]
  int v12; // [esp+4h] [ebp-Ch]
  GASPrototypeBase *v13; // [esp+Ch] [ebp-4h]
  bool namea; // [esp+1Ch] [ebp+Ch]

  Short = psc->N.Name.Short;
  v7 = name->N.Name.Short;
  v13 = this;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v13;
    }
    v7 = name->N.Name.Short;
    v8 = *(_DWORD *)(*(_DWORD *)(Short + 328) + 4) == *(_DWORD *)(name->N.Name.Short + 4);
  }
  else
  {
    v8 = *(_DWORD *)(Short + 328) == v7;
  }
  namea = v8;
  if ( v8 )
    goto LABEL_14;
  v9 = psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v13;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 324) + 4) == *(_DWORD *)(name->N.Name.Short + 4);
  }
  else
  {
    v10 = *(_DWORD *)(v9 + 324) == v7;
  }
  if ( v10 )
LABEL_14:
    GASPrototypeBase::GetMemberRawConstructor(
      this: this + 15,
      a2: (struct GASObject *)this - 2,
      name: psc,
      key: name,
      a5: val,
      a6: namea);
  else
    GASArrayObject::GetMemberRaw(psc, (GMemAddressStub *)name, (int)val, a4: v11, a5: v12);
}

//------------------------------------------------------------------------------
// Address: 0x100A7FF0
// Name: protected: void GASPrototype<class GASArrayObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(
        ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // esi
  int result; // eax
  unsigned int v5; // ebx
  unsigned int j; // esi
  int v7; // edx
  int v8; // ecx
  unsigned __int64 v9; // [esp+0h] [ebp-Ch]
  GFxFontPackParams *v10; // [esp+0h] [ebp-Ch]

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this, a2: v9);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 14) + 4 * i) != 0 )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(result: v10);
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)this + 20);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)this + 23);
  result = *((_DWORD *)this + 26);
  if ( result != 0 )
  {
    v5 = *(_DWORD *)(result + 4);
    for ( j = 0; j < v5; ++j )
    {
      v7 = **((_DWORD **)this + 26);
      v8 = *(_DWORD *)(v7 + 4 * j);
      result = v7 + 4 * j;
      if ( v8 != 0 )
      {
        result = --*(_DWORD *)(v8 + 8);
        if ( (result & 0x70000000) != 0x10000000 )
        {
          *(_DWORD *)(v8 + 8) = result & 0x8FFFFFFF | 0x10000000;
          result = (**(int (__thiscall ***)(int, int))v8)(a1: v8, a2: 1);
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8080
// Name: protected: void GASPrototype<class GASArrayObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(
        ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // esi
  int result; // eax
  unsigned int v5; // ebx
  unsigned int j; // esi
  int v7; // edx
  int v8; // ecx
  unsigned __int64 v9; // [esp+0h] [ebp-Ch]
  GFxFontPackParams *v10; // [esp+0h] [ebp-Ch]

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this, a2: v9);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 14) + 4 * i) != 0 )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(result: v10);
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)this + 20);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)this + 23);
  result = *((_DWORD *)this + 26);
  if ( result != 0 )
  {
    v5 = *(_DWORD *)(result + 4);
    for ( j = 0; j < v5; ++j )
    {
      v7 = **((_DWORD **)this + 26);
      v8 = *(_DWORD *)(v7 + 4 * j);
      result = v7 + 4 * j;
      if ( v8 != 0 )
      {
        result = ++*(_DWORD *)(v8 + 8);
        if ( (result & 0x70000000) != 0 )
        {
          *(_DWORD *)(v8 + 8) = result & 0x8FFFFFFF;
          result = (**(int (__thiscall ***)(int, int))v8)(a1: v8, a2: 2);
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8100
// Name: protected: void GASPrototype<class GASArrayObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(
        ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // esi
  int result; // eax
  unsigned int v5; // ebx
  unsigned int j; // esi
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // [esp-4h] [ebp-10h]
  unsigned __int64 v11; // [esp+0h] [ebp-Ch]
  GFxFontPackParams *v12; // [esp+0h] [ebp-Ch]

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this, a2: v11);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 14) + 4 * i) != 0 )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(result: v12);
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)this + 20);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)this + 23);
  result = *((_DWORD *)this + 26);
  if ( result != 0 )
  {
    v5 = *(_DWORD *)(result + 4);
    for ( j = 0; j < v5; ++j )
    {
      v7 = **((_DWORD **)this + 26);
      v8 = *(_DWORD *)(v7 + 4 * j);
      result = v7 + 4 * j;
      if ( v8 != 0 )
      {
        result = *(_DWORD *)(v8 + 8);
        if ( (result & 0x70000000) == 0x10000000 )
        {
          if ( (result & 0xFFFFFFF) != 0 )
          {
            v9 = result & 0x8FFFFFFF;
            v10 = 2;
          }
          else
          {
            v9 = result & 0x8FFFFFFF | 0x20000000;
            v10 = 4;
          }
          *(_DWORD *)(v8 + 8) = v9;
          result = (**(int (__thiscall ***)(int, int))v8)(a1: v8, a2: v10);
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A81A0
// Name: protected: void GASPrototype<class GASArrayObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(
        ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // edi
  int v4; // eax
  unsigned int v5; // ebx
  unsigned int j; // edi
  int v7; // edx
  _DWORD *v8; // ecx
  unsigned __int64 v10; // [esp+0h] [ebp-Ch]
  GFxFontPackParams *v11; // [esp+0h] [ebp-Ch]

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this, a2: v10);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 14) + 4 * i) != 0 )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(result: v11);
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: (_DWORD *)this + 20);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: (_DWORD *)this + 23);
  v4 = *((_DWORD *)this + 26);
  if ( v4 != 0 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    for ( j = 0; j < v5; ++j )
    {
      v7 = **((_DWORD **)this + 26);
      v8 = *(_DWORD **)(v7 + 4 * j);
      LOBYTE(v4) = v7 + 4 * j;
      if ( v8 != nullptr )
        LOBYTE(v4) = GRefCountBaseGC<323>::CollectGarbage(this: v8);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A8210
// Name: protected: void GASPrototype<class GASArrayObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(
        ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // edi
  int v4; // eax
  unsigned int v5; // ebx
  unsigned int j; // edi
  int v7; // edx
  int v8; // ecx
  unsigned __int64 v10; // [esp+0h] [ebp-Ch]
  GFxFontPackParams *v11; // [esp+0h] [ebp-Ch]

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this, a2: v10);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 14) + 4 * i) != 0 )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(result: v11);
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: (int *)this + 20, a2: i);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: (int *)this + 23, a2: i);
  v4 = *((_DWORD *)this + 26);
  if ( v4 != 0 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    for ( j = 0; j < v5; ++j )
    {
      v7 = **((_DWORD **)this + 26);
      v8 = *(_DWORD *)(v7 + 4 * j);
      LOBYTE(v4) = v7 + 4 * j;
      if ( v8 != 0 )
        LOBYTE(v4) = GRefCountBaseGC<323>::Release(a1: v8, a2: j);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A8280
// Name: protected: virtual void GASPrototype<class GASArrayObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASArrayObject,GASEnvironment>::Finalize_GC(GAtomicOpsRaw<4> *this)
{
  void **v2; // eax

  v2 = *((void ***)this + 26);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 26));
  }
  GASArrayObject::Finalize_GC();
}

//------------------------------------------------------------------------------
// Address: 0x100A82C0
// Name: public: virtual GASPrototype<class GASArrayObject,class GASEnvironment>::~GASPrototype<class GASArrayObject,class GASEnvironment>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASArrayObject,GASEnvironment>::~GASPrototype<GASArrayObject,GASEnvironment>(
        GAtomicOpsRaw<4> *this)
{
  GASPrototypeBase *v2; // ecx
  volatile LONG *v3; // edi
  GMemoryHeap *v4; // [esp+0h] [ebp-8h]

  v2 = (GASPrototypeBase *)(this + 76);
  *(_DWORD *)&this->GAtomicOpsRawBase = &GASArrayProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASArrayProto::`vftable'{for `GASObjectInterface'};
  v2->__vftable = (IUnknown_vtbl *)&GASArrayProto::`vftable';
  GASPrototypeBase::~GASPrototypeBase(this: v2);
  *(_DWORD *)&this->GAtomicOpsRawBase = &GASArrayObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASArrayObject::`vftable'{for `GASObjectInterface'};
  GASArrayObject::Resize(size: nullptr, a2: v4);
  v3 = (volatile LONG *)(*((_DWORD *)this + 17) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 14));
  GASObject::~GASObject((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100A8A10
// Name: protected: virtual void GASPrototype<class GASArrayObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASPrototype<GASArrayObject,GASEnvironment>::ExecuteForEachChild_GC(
        ISteamUserStats *this,
        int operation)
{
  char result; // al

  result = operation;
  switch ( operation )
  {
    case 0:
      result = GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
      break;
    case 1:
      result = GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
      break;
    case 2:
      result = GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
      break;
    case 3:
      result = GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
      break;
    case 4:
      result = GASPrototype<GASArrayObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8A70
// Name: public: static void GConstructorMov<class GASArraySortFunctor>::DestructArray(class GASArraySortFunctor __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GConstructorMov<GASArraySortFunctor>::DestructArray(int a1, int a2)
{
  char result; // al
  int v3; // esi
  int i; // edi
  int v5; // ecx
  bool v6; // zf

  result = a2;
  if ( a2 != 0 )
  {
    v3 = a1 + 28 * a2 - 28 + 12;
    for ( i = a2; i != 0; --i )
    {
      if ( (*(_BYTE *)(v3 + 4) & 2) == 0 )
      {
        v5 = *(_DWORD *)(v3 - 4);
        if ( v5 != 0 )
          result = GRefCountBaseGC<323>::Release(a1: v5, a2: i);
      }
      v6 = (*(_BYTE *)(v3 + 4) & 1) == 0;
      *(_DWORD *)(v3 - 4) = 0;
      if ( v6 && *(_DWORD *)v3 != 0 )
        result = GRefCountBaseGC<323>::Release(a1: *(_DWORD *)v3, a2: i);
      *(_DWORD *)v3 = 0;
      v3 -= 28;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8AD0
// Name: public: static void GConstructorMov<class GASArraySortFunctor>::ConstructArray(void __near *,unsigned int,class GASArraySortFunctor const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GConstructorMov<GASArraySortFunctor>::ConstructArray(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // esi
  int v5; // edi
  int i; // ebx
  int v7; // eax

  result = a2;
  if ( a2 != 0 )
  {
    v4 = a1 + 12;
    v5 = a3 + 12;
    for ( i = a2; i != 0; --i )
    {
      result = v4 - 12;
      if ( v4 != 12 )
      {
        *(_DWORD *)(v4 - 12) = *(_DWORD *)(v5 - 12);
        *(_DWORD *)(v4 - 8) = *(_DWORD *)(v5 - 8);
        *(_BYTE *)(v4 + 4) = 0;
        v7 = *(_DWORD *)(v5 - 4);
        *(_DWORD *)(v4 - 4) = v7;
        if ( v7 != 0 )
          *(_DWORD *)(v7 + 8) = (*(_DWORD *)(v7 + 8) + 1) & 0x8FFFFFFF;
        *(_DWORD *)v4 = 0;
        if ( *(_DWORD *)v5 != 0 )
          GASFunctionRefBase::SetLocalFrame(
            a1: v4 - 4,
            a2: v5,
            result: *(tagIMECHARPOSITION **)v5,
            internal: *(_BYTE *)(v5 + 4) & 1);
        result = *(_DWORD *)(v5 + 8);
        *(_DWORD *)(v4 + 8) = result;
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(v5 + 12);
      }
      v4 += 28;
      v5 += 28;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AD580
// Name: public: virtual struct GFxScale9Grid const __near * GFxButtonCharacter::GetScale9Grid(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxButtonCharacter::GetScale9Grid(GFxTestStream *this)
{
  return *((_DWORD *)this + 47);
}

//------------------------------------------------------------------------------
// Address: 0x100B3FE0
// Name: protected: virtual void GASPrototype<class GASMovieClipObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASMovieClipObject,GASEnvironment>::Finalize_GC(GASObject *this)
{
  void **v2; // eax
  _DWORD *v3; // eax

  v2 = *((void ***)this + 22);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 22));
  }
  v3 = *((_DWORD **)this + 13);
  if ( v3 != nullptr && (*v3)-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8640
// Name: protected: virtual void GASPrototype<class GASMovieClipObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
D3DXVECTOR2 *__thiscall GASPrototype<GASMovieClipObject,GASEnvironment>::ExecuteForEachChild_GC(
        GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *this,
        D3DXVECTOR2 *result)
{
  D3DXVECTOR2 *v2; // eax

  v2 = result;
  switch ( (unsigned int)result )
  {
    case 0u:
      v2 = (D3DXVECTOR2 *)GASPrototype<GASBitmapData,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
      break;
    case 1u:
      v2 = (D3DXVECTOR2 *)GASPrototype<GASSharedObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
      break;
    case 2u:
      v2 = (D3DXVECTOR2 *)GASPrototype<GASBitmapData,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
      break;
    case 3u:
      v2 = (D3DXVECTOR2 *)GASPrototype<GASTextFieldObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
      break;
    case 4u:
      v2 = (D3DXVECTOR2 *)GASPrototype<GASSharedObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
      break;
    default:
      return v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100B8F70
// Name: public: GASPrototype<class GASMovieClipObject,class GASEnvironment>::GASPrototype<class GASMovieClipObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
const ScaleformFileOpener *__thiscall GASPrototype<GASMovieClipObject,GASEnvironment>::GASPrototype<GASMovieClipObject,GASEnvironment>(
        int this,
        ScaleformFileOpener *result,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)result);
  *(_DWORD *)this = &GASButtonObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASMovieClipObject::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 52) = 0;
  GASMovieClipObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
    a3: psc_4);
  *(_BYTE *)(this + 58) = 0;
  *(_WORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 72) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_BYTE *)(this + 84) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)result);
  *(_DWORD *)this = &GASMovieClipProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASMovieClipProto::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 60) = &stru_102A09D0.m_Memory.m_nGrowSize;
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 60),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return (const ScaleformFileOpener *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100DF400
// Name: public: static void GConstructorMov<class GFxTextureGlyph>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GFxTextureGlyph>::ConstructArray(int a1, int a2)
{
  int v2; // ecx
  float *v3; // eax

  v2 = a2;
  if ( a2 != 0 )
  {
    v3 = (float *)(a1 + 20);
    do
    {
      if ( v3 != (float *)20 )
      {
        *((_DWORD *)v3 - 5) = &GRefCountImplCore::`vftable';
        *((_DWORD *)v3 - 4) = 1;
        *((_DWORD *)v3 - 5) = &GFxTextureGlyph::`vftable';
        *(v3 - 3) = 0.0;
        *(v3 - 2) = 0.0;
        *(v3 - 1) = 0.0;
        *v3 = 0.0;
        v3[1] = 0.0;
        v3[2] = 0.0;
      }
      v3 += 10;
      --v2;
    }
    while ( v2 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E68B0
// Name: public: virtual GASPrototype<class GASTextFieldObject,class GASEnvironment>::~GASPrototype<class GASTextFieldObject,class GASEnvironment>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTextFieldObject,GASEnvironment>::~GASPrototype<GASTextFieldObject,GASEnvironment>(
        GASPrototypeBase *this,
        IVguiMatInfoVar *result)
{
  GASPrototypeBase *v3; // ecx
  void *v4; // edx
  _DWORD *v5; // eax

  v3 = this + 15;
  this->__vftable = (IUnknown_vtbl *)&GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  v3->__vftable = (IUnknown_vtbl *)&GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable';
  GASPrototypeBase::~GASPrototypeBase(this: v3);
  v4 = *((void **)this + 14);
  this->__vftable = (IUnknown_vtbl *)&GASTextFieldObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASTextFieldObject::`vftable'{for `GASObjectInterface'};
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  v5 = *((_DWORD **)this + 13);
  if ( v5 != nullptr && (*v5)-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
  JUMPOUT(0x10091A30);
}

//------------------------------------------------------------------------------
// Address: 0x100E6910
// Name: public: virtual bool GASPrototype<class GASBitmapData,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASBitmapData,GASEnvironment>::DoesImplement(
        vgui::ISurface *this,
        ScaleformFileOpener *penv,
        vgui::ISurface *prototype)
{
  if ( this != prototype )
    GASPrototypeBase::DoesImplement(
      this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 15),
      (unsigned int)penv);
}

//------------------------------------------------------------------------------
// Address: 0x100E69A0
// Name: public: virtual class GFxASCharacter __near * GASButtonObject::GetASCharacter(void)
// Source: json
//------------------------------------------------------------------------------
GRefCountNTSImpl *__thiscall GASButtonObject::GetASCharacter(GASButtonObject *this)
{
  _DWORD *v2; // eax
  GRefCountNTSImpl *v3; // esi

  v2 = *((_DWORD **)this + 13);
  if ( v2 == nullptr )
    return nullptr;
  if ( v2[1] == 0 )
  {
    if ( (*v2)-- == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    *((_DWORD *)this + 13) = 0;
    return nullptr;
  }
  v3 = (GRefCountNTSImpl *)v2[1];
  if ( v3 != nullptr )
  {
    ++v3->RefCount;
    ++v3->RefCount;
    GRefCountNTSImpl::Release(this: v3);
    GRefCountNTSImpl::Release(this: v3);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100E7B20
// Name: protected: virtual void GASPrototype<class GASTextFieldObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTextFieldObject,GASEnvironment>::Finalize_GC(int this, IVguiMatInfoVar *result)
{
  void **v3; // eax
  _DWORD *v4; // eax

  v3 = *(void ***)(this + 88);
  if ( v3 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 88));
  }
  v4 = *(_DWORD **)(this + 52);
  if ( v4 != nullptr && (*v4)-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 56));
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x100E98E0
// Name: public: GASPrototype<class GASTextFieldObject,class GASEnvironment>::GASPrototype<class GASTextFieldObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
const IVguiMatInfo *__thiscall GASPrototype<GASTextFieldObject,GASEnvironment>::GASPrototype<GASTextFieldObject,GASEnvironment>(
        int this,
        IVguiMatInfo *result,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)result);
  *(_DWORD *)this = &GASTextFieldObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASTextFieldObject::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
    psc_4);
  *(_DWORD *)(this + 60) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 72) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_BYTE *)(this + 84) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)result);
  *(_DWORD *)this = &GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 60) = &GASPrototype<GASTextFieldObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 60),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return (const IVguiMatInfo *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100F0480
// Name: public: static void GConstructorMov<class GRangeData<struct GFxEditTextCharacter::CSSHolder::UrlZone>>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GRangeData<GFxEditTextCharacter::CSSHolder::UrlZone>>::ConstructArray(int a1, int a2)
{
  int v2; // ecx
  _DWORD *v3; // eax

  v2 = a2;
  if ( a2 != 0 )
  {
    v3 = (_DWORD *)(a1 + 16);
    do
    {
      if ( v3 != (_DWORD *)16 )
      {
        *(v3 - 4) = 0;
        *(v3 - 3) = 0;
        *(v3 - 2) = 0;
        *(v3 - 1) = 0;
        *v3 = 0;
      }
      v3 += 5;
      --v2;
    }
    while ( v2 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF450
// Name: public: static void GConstructorMov<struct GFxAmpMemSegment>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GFxAmpMemSegment>::ConstructArray(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax

  v2 = a2;
  if ( a2 != 0 )
  {
    v3 = a1 + 16;
    do
    {
      if ( v3 != 16 )
      {
        *(_DWORD *)(v3 - 16) = 0;
        *(_DWORD *)(v3 - 12) = 0;
        *(_DWORD *)(v3 - 8) = 0;
        *(_DWORD *)(v3 - 4) = 0;
        *(_BYTE *)v3 = 0;
        *(_DWORD *)(v3 + 8) = 0;
        *(_DWORD *)(v3 + 12) = 0;
      }
      v3 += 32;
      --v2;
    }
    while ( v2 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106630
// Name: public: GASPrototype<class GASBitmapFilterObject,class GASEnvironment>::GASPrototype<class GASBitmapFilterObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
D3DXMATRIX *__thiscall GASPrototype<GASBitmapFilterObject,GASEnvironment>::GASPrototype<GASBitmapFilterObject,GASEnvironment>(
        D3DXMATRIX *this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  LODWORD(this->_11) = &GASBitmapFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(this->_21) = &GASBitmapFilterObject::`vftable'{for `GASObjectInterface'};
  *((float *)this + 16) = 5.0;
  *((float *)this + 17) = 5.0;
  this->_44 = 0.0;
  *((_DWORD *)this + 18) = 1;
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 23) = 1.0;
  GRenderer::Cxform::Cxform(this: (float *)this + 24);
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)this->m[1], (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *((_DWORD *)this + 52) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 220) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_BYTE *)this + 232) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_DWORD *)this + 57) = 0;
  *((_DWORD *)this + 59) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  LODWORD(this->_11) = &GASPrototype<GASBitmapFilterObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(this->_21) = &GASPrototype<GASBitmapFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 52) = &GASPrototype<GASBitmapFilterObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 208),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10106760
// Name: protected: virtual void GASPrototype<class GASBitmapFilterObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
const D3DXMATRIX *__stdcall GASPrototype<GASBitmapFilterObject,GASEnvironment>::ExecuteForEachChild_GC(
        const D3DXMATRIX *result)
{
  const D3DXMATRIX *v1; // eax

  v1 = result;
  switch ( (unsigned int)result )
  {
    case 0u:
      v1 = (const D3DXMATRIX *)GASPrototype<GASBevelFilterObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>();
      break;
    case 1u:
      v1 = (const D3DXMATRIX *)GASPrototype<GASBlurFilterObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>();
      break;
    case 2u:
      v1 = (const D3DXMATRIX *)GASPrototype<GASDropShadowFilterObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>();
      break;
    case 3u:
      v1 = (const D3DXMATRIX *)GASPrototype<GASBevelFilterObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>();
      break;
    case 4u:
      v1 = (const D3DXMATRIX *)GASPrototype<GASGlowFilterObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>();
      break;
    default:
      return v1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101092B0
// Name: public: virtual bool GASPrototype<class GASStringObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASPrototype<GASStringObject,GASEnvironment>::GetMemberRaw(
        int this,
        _IMAGE_SYMBOL_EX *result,
        _IMAGE_SYMBOL_EX *isConstructor2,
        GASValue *a4)
{
  GFile_vtbl *Short; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  GFile_vtbl *v9; // esi
  bool v10; // zf
  int v12; // [esp+Ch] [ebp-4h]
  bool isConstructor2a; // [esp+1Ch] [ebp+Ch]

  Short = (GFile_vtbl *)result->N.Name.Short;
  v7 = isConstructor2->N.Name.Short;
  v12 = this;
  if ( result->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v7 = isConstructor2->N.Name.Short;
    v8 = *((_DWORD *)Short[4].GetLength + 1) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v8 = Short[4].GetLength == (int (__thiscall *)(GFile *))v7;
  }
  isConstructor2a = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(this + 40),
             a2: (struct GASObject *)(this - 16),
             name: result,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  v9 = (GFile_vtbl *)result->N.Name.Short;
  if ( result->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v10 = *((_DWORD *)v9[4].LTell + 1) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v10 = v9[4].LTell == (__int64 (__thiscall *)(GFile *))v7;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(this + 40),
             a2: (struct GASObject *)(this - 16),
             name: result,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  else
    return GASStringObject::GetMemberRaw(
             (GASStringObject *)this,
             psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
             a3: (const struct GASString *)isConstructor2,
             (struct GASValue *)a4);
}

//------------------------------------------------------------------------------
// Address: 0x10109370
// Name: public: virtual bool GASPrototype<class GASMovieClipLoader,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASMovieClipLoader,GASEnvironment>::DoesImplement(
        int this,
        FontVertex_t *result,
        int prototype)
{
  if ( this == prototype )
    return 1;
  else
    return (unsigned __int8)GASPrototypeBase::DoesImplement(
                              this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 56),
                              penv: (unsigned int)result);
}

//------------------------------------------------------------------------------
// Address: 0x10109A70
// Name: protected: virtual void GASPrototype<class GASStringObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASStringObject,GASEnvironment>::Finalize_GC(GImage *this)
{
  void **v2; // eax
  int v3; // ecx

  v2 = *((void ***)this + 21);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 21));
  }
  v3 = *((_DWORD *)this + 13);
  if ( (*(_DWORD *)(v3 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10109BD0
// Name: protected: void GASPrototype<class GASBooleanObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10109C40
// Name: protected: void GASPrototype<class GASStringObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10109F10
// Name: public: GASPrototype<class GASStringObject,class GASEnvironment>::GASPrototype<class GASStringObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GImage *__thiscall GASPrototype<GASStringObject,GASEnvironment>::GASPrototype<GASStringObject,GASEnvironment>(
        int this,
        GImage *result,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  void (__thiscall *dtr_GRefCountImplCore)(struct GImage *); // eax
  __int128 v7; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)result);
  *(_DWORD *)this = &GASStringObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASStringObject::`vftable'{for `GASObjectInterface'};
  dtr_GRefCountImplCore = result->__vftable[2].dtr_GRefCountImplCore;
  *(_DWORD *)(this + 52) = dtr_GRefCountImplCore;
  ++*((_DWORD *)dtr_GRefCountImplCore + 2);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
    psc_4);
  *(_DWORD *)(this + 56) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 68) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_BYTE *)(this + 80) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 84) = 0;
  *(_QWORD *)&v7 = __PAIR64__(psc_8, (unsigned int)result);
  *(_DWORD *)this = &GASPrototype<GASStringObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASStringProto::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 56) = &GASStringProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 56),
    pthis: (CMaterialVar *)this,
    psc: v7);
  return (GImage *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1010B460
// Name: public: GASPrototype<class GASIme,class GASEnvironment>::GASPrototype<class GASIme,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASPrototype<GASIme,GASEnvironment>::GASPrototype<GASIme,GASEnvironment>(
        D3DXCOLOR *this@<ecx>,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *pprototype,
        unsigned int constructor,
        float psc_12)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  LODWORD(this->r) = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A45C0;
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 1),
    (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    psc_4: pprototype);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v6 = __PAIR64__(constructor, (unsigned int)psc);
  LODWORD(this->r) = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 52),
    pthis: (CMaterialVar *)this,
    psc: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1010B9C0
// Name: public: virtual void GASPrototype<class GASTransformObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTransformObject,GASEnvironment>::AddInterface(
        GPtr<GFxFileOpenerBase> *this,
        GFxFileOpenerBase *psc)
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x1010BBD0
// Name: protected: virtual void GASPrototype<class GASNumberObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASNumberObject,GASEnvironment>::Finalize_GC(GPtr<GFxFileOpenerBase> *this)
{
  void **v2; // eax
  volatile LONG *v3; // esi

  v2 = *((void ***)this + 25);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 25));
  }
  v3 = (volatile LONG *)(*(_DWORD *)(this + 16) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1010BC30
// Name: protected: void GASPrototype<class GASNumberObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1010BCB0
// Name: protected: void GASPrototype<class GASTextSnapshotObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1010BD20
// Name: public: GASPrototype<class GASNumberObject,class GASEnvironment>::GASPrototype<class GASNumberObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
const GFxFileOpenerBase *__thiscall GASPrototype<GASNumberObject,GASEnvironment>::GASPrototype<GASNumberObject,GASEnvironment>(
        int this,
        GFxFileOpenerBase *result,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)result);
  *(double *)(this + 56) = 0.0;
  *(_DWORD *)this = &GASNumberObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASNumberObject::`vftable'{for `GASObjectInterface'};
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(this + 64));
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
    psc_4);
  *(_DWORD *)(this + 72) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 84) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_BYTE *)(this + 96) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)result);
  *(_DWORD *)this = &GASNumberProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASPrototype<GASNumberObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 72) = &GASPrototype<GASNumberObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 72),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return (const GFxFileOpenerBase *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1010C1D0
// Name: protected: virtual void GASPrototype<class GASBooleanObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASBooleanObject,GASEnvironment>::Finalize_GC(GASObject *this)
{
  void **v2; // eax

  v2 = *((void ***)this + 21);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 21));
  }
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010C210
// Name: public: GASPrototype<class GASBooleanObject,class GASEnvironment>::GASPrototype<class GASBooleanObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASPrototype<GASBooleanObject,GASEnvironment>::GASPrototype<GASBooleanObject,GASEnvironment>(
        int this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  *(_DWORD *)this = &GASBooleanObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASBooleanObject::`vftable'{for `GASObjectInterface'};
  *(_BYTE *)(this + 52) = 0;
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 16), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *(_DWORD *)(this + 56) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 68) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_BYTE *)(this + 80) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 84) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  *(_DWORD *)this = &GASPrototype<GASBooleanObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASBooleanProto::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 56) = &GASBooleanProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 56),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010C480
// Name: public: virtual bool GASPrototype<class GASColorObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASColorObject,GASEnvironment>::GetMemberRaw(
        int this,
        _IMAGE_SYMBOL_EX *result,
        _IMAGE_SYMBOL_EX *isConstructor2,
        GASValue *a4)
{
  float v4; // esi
  unsigned int Short; // ecx
  bool v8; // zf
  float v9; // esi
  bool v10; // zf
  int v12; // [esp+Ch] [ebp-4h]
  bool isConstructor2a; // [esp+1Ch] [ebp+Ch]

  v4 = *(float *)&result->N.Name.Short;
  Short = isConstructor2->N.Name.Short;
  v12 = this;
  if ( result->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    Short = isConstructor2->N.Name.Short;
    v8 = *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 328) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v8 = *(_DWORD *)(LODWORD(v4) + 328) == Short;
  }
  isConstructor2a = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(this + 40),
             a2: (struct GASObject *)(this - 16),
             name: result,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  v9 = *(float *)&result->N.Name.Short;
  if ( result->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(LODWORD(v9) + 324) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v10 = *(_DWORD *)(LODWORD(v9) + 324) == Short;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(this + 40),
             a2: (struct GASObject *)(this - 16),
             name: result,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  else
    return (unsigned __int8)GASObject::GetMemberRaw(
                              (CTSQueue<CFunctor *,0,1> *)this,
                              psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result);
}

//------------------------------------------------------------------------------
// Address: 0x1010CB30
// Name: protected: virtual void GASPrototype<class GASButtonObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASButtonObject,GASEnvironment>::Finalize_GC(GASObject *this)
{
  void **v2; // eax
  _DWORD *v3; // eax

  v2 = *((void ***)this + 21);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 21));
  }
  v3 = *((_DWORD **)this + 13);
  if ( v3 != nullptr && (*v3)-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010CFE0
// Name: public: GASPrototype<class GASColorObject,class GASEnvironment>::GASPrototype<class GASColorObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASColorObject,GASEnvironment>::GASPrototype<GASColorObject,GASEnvironment>(
        FontVertex_t *this,
        const FontVertex_t *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v5; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)psc);
  LODWORD(this->m_Position.x) = &GASColorObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASColorObject::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = 0;
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 1), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *((_DWORD *)this + 14) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 68) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_BYTE *)this + 80) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 21) = 0;
  *(_QWORD *)&v5 = __PAIR64__(psc_8, (unsigned int)psc);
  LODWORD(this->m_Position.x) = &GASColorProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASColorProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 14) = &GASColorProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 56),
    pthis: (CMaterialVar *)this,
    psc: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1010D060
// Name: protected: virtual void GASPrototype<class GASButtonObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1010D200
// Name: SkipButtonSoundDef
// Source: json
//------------------------------------------------------------------------------
int __cdecl SkipButtonSoundDef(HBITMAP__ p)
{
  int unused; // ebx
  int v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  __int16 v7; // dx
  int result; // eax
  bool v9; // bl
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned __int8 v14; // cl
  int j; // ebx
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  _cpinfo *v19; // [esp+0h] [ebp-14h]
  int i; // [esp+Ch] [ebp-8h]
  bool HasEnvelope; // [esp+12h] [ebp-2h]
  bool HasLoops; // [esp+13h] [ebp-1h]

  unused = p.unused;
  v2 = *(_DWORD *)(p.unused + 804);
  if ( v2 == 0 )
    v2 = p.unused + 40;
  for ( i = 4; i != 0; --i )
  {
    v3 = *(_DWORD *)(unused + 804);
    if ( v3 == 0 )
      v3 = unused + 40;
    v4 = *(_DWORD *)(v3 + 48) - *(_DWORD *)(v3 + 44);
    *(_BYTE *)(v3 + 21) = 0;
    if ( v4 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v5 = *(_DWORD *)(v3 + 44);
    v6 = *(_DWORD *)(v3 + 60);
    v7 = *(unsigned __int8 *)(v6 + v5 + 1);
    LOWORD(v6) = *(unsigned __int8 *)(v6 + v5);
    result = v5 + 2;
    *(_DWORD *)(v3 + 44) = result;
    if ( ((unsigned __int16)v6 | (unsigned __int16)(v7 << 8)) != 0 )
    {
      GFxStream::ReadUInt(this: (GFxStream *)v2, a2: 2u);
      GFxStream::ReadUInt(this: (GFxStream *)v2, a2: 1u);
      GFxStream::ReadUInt(this: (GFxStream *)v2, a2: 1u);
      HasEnvelope = GFxStream::ReadUInt(this: (GFxStream *)v2, a2: 1u) != 0;
      HasLoops = GFxStream::ReadUInt(this: (GFxStream *)v2, a2: 1u) != 0;
      v9 = GFxStream::ReadUInt(this: (GFxStream *)v2, a2: 1u) != 0;
      result = GFxStream::ReadUInt(this: (GFxStream *)v2, a2: 1u);
      if ( result != 0 )
      {
        v10 = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
        *(_BYTE *)(v2 + 21) = 0;
        if ( v10 < 4 )
          result = (int)GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
        *(_DWORD *)(v2 + 44) += 4;
      }
      if ( v9 )
      {
        result = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
        *(_BYTE *)(v2 + 21) = 0;
        if ( result < 4 )
          result = (int)GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
        *(_DWORD *)(v2 + 44) += 4;
      }
      if ( HasLoops )
      {
        v11 = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
        *(_BYTE *)(v2 + 21) = 0;
        if ( v11 < 2 )
          result = (int)GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        *(_DWORD *)(v2 + 44) += 2;
      }
      if ( HasEnvelope )
      {
        v12 = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
        *(_BYTE *)(v2 + 21) = 0;
        if ( v12 < 1 )
          GFxStream::PopulateBuffer1(result: v19);
        v13 = *(_DWORD *)(v2 + 44);
        v14 = *(_BYTE *)(v13 + *(_DWORD *)(v2 + 60));
        *(_DWORD *)(v2 + 44) = v13 + 1;
        result = v14;
        if ( v14 != 0 )
        {
          for ( j = v14; j != 0; --j )
          {
            v16 = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
            *(_BYTE *)(v2 + 21) = 0;
            if ( v16 < 4 )
              result = (int)GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
            *(_DWORD *)(v2 + 44) += 4;
            v17 = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
            *(_BYTE *)(v2 + 21) = 0;
            if ( v17 < 2 )
              result = (int)GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
            *(_DWORD *)(v2 + 44) += 2;
            v18 = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
            *(_BYTE *)(v2 + 21) = 0;
            if ( v18 < 2 )
              result = (int)GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
            *(_DWORD *)(v2 + 44) += 2;
          }
        }
      }
      unused = p.unused;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D3C0
// Name: public: void GFxButtonCharacter::SetScale9Grid(struct GFxScale9Grid const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxButtonCharacter::SetScale9Grid(CUtlMemory<ResourceEntryInfo,int> *this@<ecx>, int gr, int a3)
{
  void *v4; // eax
  ResourceEntryInfo *v5; // edi
  bool v6; // bl
  unsigned int *v7; // eax
  int v8; // eax

  v4 = *((void **)this + 47);
  v5 = (ResourceEntryInfo *)gr;
  v6 = (gr != 0) != (v4 != nullptr);
  if ( gr != 0 )
  {
    if ( v4 == nullptr )
    {
      gr = 265;
      *((_DWORD *)this + 47) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 16,
                                 a4: &gr);
    }
    v7 = *((unsigned int **)this + 47);
    *v7 = v5->eType;
    v7[1] = v5->resData;
    v7[2] = v5[1].eType;
    v7[3] = v5[1].resData;
    *((_WORD *)this + 59) |= 1u;
  }
  else
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    *((_WORD *)this + 59) &= ~1u;
    *((_DWORD *)this + 47) = 0;
  }
  v8 = ((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[10].resData)(a1: this);
  *(_DWORD *)(v8 + 9332) |= 0x400u;
  if ( v6 )
    ((void (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[10].eType)(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x1010D480
// Name: public: void GFxButtonCharacter::UnloadCharacterAtIndex(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::UnloadCharacterAtIndex(CUtlMemory<ResourceEntryInfo,int> *this, unsigned int i)
{
  _BYTE *v3; // esi
  char v4; // al
  int v5; // esi
  GRefCountNTSImpl *v6; // ecx

  v3 = *(_BYTE **)(4 * i + *((_DWORD *)this + 48));
  if ( v3 != nullptr )
  {
    if ( (v3[118] >> 7 != 0 ? (unsigned int)v3 : 0) != 0 )
    {
      v4 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v3 + 140))(a1: v3);
      *((_WORD *)v3 + 59) |= 0x100u;
      if ( v4 != 0 )
        (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v3 + 136))(a1: v3);
    }
    v5 = *((_DWORD *)this + 48);
    v6 = *(GRefCountNTSImpl **)(v5 + 4 * i);
    if ( v6 != nullptr )
      GRefCountNTSImpl::Release(this: v6);
    *(_DWORD *)(v5 + 4 * i) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D640
// Name: protected: void GASPrototype<class GASColorObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1010D6C0
// Name: void GFx_GenerateMouseButtonEvents(unsigned int,class GFxMouseState __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_GenerateMouseButtonEvents(char a1, struct GFxMouseState *a2, unsigned int a3)
{
  _DWORD *v3; // eax
  GRefCountNTSImpl *v4; // edi
  GRefCountWeakSupportImpl *v5; // esi
  _DWORD *v6; // eax
  int v7; // eax
  unsigned __int8 v8; // bl
  char v9; // cl
  bool v10; // dl
  struct GFxMouseState *v11; // ecx
  int v12; // eax
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountWeakSupportImpl *); // edx
  bool v14; // zf
  void (__thiscall *v15)(struct GRefCountWeakSupportImpl *); // edx
  GRefCountWeakSupportImpl_vtbl *v16; // eax
  char v17; // cl
  GRefCountWeakSupportImpl_vtbl *v18; // eax
  void (__thiscall *v19)(struct GRefCountWeakSupportImpl *); // edx
  char v20; // al
  char v21; // al
  void (__thiscall *v22)(struct GRefCountWeakSupportImpl *); // edx
  char v23; // cl
  GRefCountNTSImpl_vtbl *v24; // eax
  char v25; // al
  char v26; // al
  GRefCountWeakSupportImpl_vtbl *v27; // eax
  void (__thiscall *v28)(struct GRefCountWeakSupportImpl *); // edx
  char v29; // cl
  GRefCountNTSImpl_vtbl *v30; // eax
  void (__thiscall *v31)(struct GRefCountNTSImpl *); // edx
  struct GWeakPtrProxy *WeakProxy; // ebx
  _DWORD *v33; // eax
  _DWORD *v34; // eax
  _DWORD v35[2]; // [esp+Ch] [ebp-8Ch] BYREF
  __int16 v36; // [esp+14h] [ebp-84h]
  char v37; // [esp+16h] [ebp-82h]
  char v38; // [esp+17h] [ebp-81h]
  char v39; // [esp+18h] [ebp-80h]
  char v40; // [esp+19h] [ebp-7Fh]
  _DWORD v41[2]; // [esp+1Ch] [ebp-7Ch] BYREF
  __int16 v42; // [esp+24h] [ebp-74h]
  unsigned __int8 v43; // [esp+26h] [ebp-72h]
  char v44; // [esp+27h] [ebp-71h]
  __int16 v45; // [esp+28h] [ebp-70h]
  _DWORD v46[2]; // [esp+2Ch] [ebp-6Ch] BYREF
  __int16 v47; // [esp+34h] [ebp-64h]
  char v48; // [esp+36h] [ebp-62h]
  char v49; // [esp+37h] [ebp-61h]
  char v50; // [esp+38h] [ebp-60h]
  char v51; // [esp+39h] [ebp-5Fh]
  unsigned int v52; // [esp+3Ch] [ebp-5Ch]
  _DWORD v53[2]; // [esp+40h] [ebp-58h] BYREF
  __int16 v54; // [esp+48h] [ebp-50h]
  unsigned __int8 v55; // [esp+4Ah] [ebp-4Eh]
  char v56; // [esp+4Bh] [ebp-4Dh]
  char v57; // [esp+4Ch] [ebp-4Ch]
  char v58; // [esp+4Dh] [ebp-4Bh]
  _DWORD v59[2]; // [esp+50h] [ebp-48h] BYREF
  __int16 v60; // [esp+58h] [ebp-40h]
  unsigned __int8 v61; // [esp+5Ah] [ebp-3Eh]
  char v62; // [esp+5Bh] [ebp-3Dh]
  __int16 v63; // [esp+5Ch] [ebp-3Ch]
  _DWORD v64[2]; // [esp+60h] [ebp-38h] BYREF
  __int16 v65; // [esp+68h] [ebp-30h]
  unsigned __int8 v66; // [esp+6Ah] [ebp-2Eh]
  char v67; // [esp+6Bh] [ebp-2Dh]
  char v68; // [esp+6Ch] [ebp-2Ch]
  char v69; // [esp+6Dh] [ebp-2Bh]
  _DWORD v70[2]; // [esp+70h] [ebp-28h] BYREF
  __int16 v71; // [esp+78h] [ebp-20h]
  unsigned __int8 v72; // [esp+7Ah] [ebp-1Eh]
  char v73; // [esp+7Bh] [ebp-1Dh]
  char v74; // [esp+7Ch] [ebp-1Ch]
  char v75; // [esp+7Dh] [ebp-1Bh]
  _DWORD v76[2]; // [esp+80h] [ebp-18h] BYREF
  __int16 v77; // [esp+88h] [ebp-10h]
  unsigned __int8 v78; // [esp+8Ah] [ebp-Eh]
  char v79; // [esp+8Bh] [ebp-Dh]
  __int16 v80; // [esp+8Ch] [ebp-Ch]
  int v81; // [esp+90h] [ebp-8h]
  char v82; // [esp+94h] [ebp-4h]
  unsigned __int8 v83; // [esp+95h] [ebp-3h]
  bool v84; // [esp+96h] [ebp-2h]
  bool v85; // [esp+97h] [ebp-1h]

  v3 = *((_DWORD **)a2 + 2);
  v4 = nullptr;
  v5 = nullptr;
  if ( v3 != nullptr )
  {
    if ( v3[1] != 0 )
    {
      v5 = (GRefCountWeakSupportImpl *)v3[1];
      if ( v5 == nullptr )
        goto LABEL_7;
      ++v5->RefCount;
      ++v5->RefCount;
    }
    else
    {
      v14 = (*v3)-- == 1;
      if ( v14 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
      *((_DWORD *)a2 + 2) = 0;
    }
  }
  if ( v5 != nullptr )
    GRefCountNTSImpl::Release(this: v5);
LABEL_7:
  v6 = *(_DWORD **)a2;
  if ( *(_DWORD *)a2 != 0 )
  {
    if ( v6[1] != 0 )
    {
      v4 = (GRefCountNTSImpl *)v6[1];
      if ( v4 != nullptr )
      {
        ++v4->RefCount;
        ++v4->RefCount;
        GRefCountNTSImpl::Release(this: v4);
      }
    }
    else
    {
      v14 = (*v6)-- == 1;
      if ( v14 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
      *(_DWORD *)a2 = 0;
    }
  }
  v7 = *((_DWORD *)a2 + 4) ^ *((_DWORD *)a2 + 3);
  v85 = (*((_BYTE *)a2 + 32) & 4) != 0;
  v8 = 0;
  v52 = v7;
  v82 = 0;
  if ( a3 != 0 )
  {
    v9 = 0;
    v81 = 0;
    do
    {
      v10 = v8 != 0;
      v84 = v8 != 0;
      v83 = 1 << v9;
      v11 = a2;
      if ( ((v52 >> v81) & 1) != 0 )
      {
        v12 = v83;
        v81 = v83;
        if ( (v83 & *((_DWORD *)a2 + 4)) != 0 )
        {
          if ( (v83 & *((_DWORD *)a2 + 3)) == 0 && v5 != nullptr )
          {
            if ( (*((_BYTE *)a2 + 32) & 4) != 0 )
            {
              v77 = 0;
              v80 = 0;
              dtr_GRefCountImplCore = v5->__vftable[66].dtr_GRefCountImplCore;
              v79 = a1;
              v76[0] = v8 != 0 ? 0x100000 : 2048;
              v76[1] = 0;
              v78 = v8;
              ((void (__thiscall *)(GRefCountWeakSupportImpl *, _DWORD *))dtr_GRefCountImplCore)(a1: v5, a2: v76);
              v12 = v81;
              v10 = v84;
            }
            else
            {
              if ( (v5[13].RefCount & 0x2000) == 0 )
              {
                v59[0] = v8 != 0 ? 0x200000 : 4096;
                v15 = v5->__vftable[66].dtr_GRefCountImplCore;
                v60 = 0;
                v63 = 0;
                v62 = a1;
                v59[1] = 0;
                v61 = v8;
                ((void (__thiscall *)(GRefCountWeakSupportImpl *, _DWORD *))v15)(a1: v5, a2: v59);
                v12 = v81;
                v10 = v84;
              }
              v82 = 1;
            }
            v11 = a2;
          }
          if ( (v12 & *((_DWORD *)v11 + 4)) != 0 )
            goto LABEL_55;
        }
        if ( (v12 & *((_DWORD *)v11 + 3)) == 0 )
          goto LABEL_55;
        if ( v5 != nullptr )
        {
          v42 = 0;
          v45 = 0;
          v41[0] = v10 ? 0x80000 : 1024;
          v16 = v5->__vftable;
          v41[1] = 0;
          v43 = v8;
          v44 = a1;
          ((void (__thiscall *)(GRefCountWeakSupportImpl *, _DWORD *))v16[66].dtr_GRefCountImplCore)(a1: v5, a2: v41);
        }
      }
      else
      {
        if ( (v83 & *((_BYTE *)a2 + 12)) == 0 )
          goto LABEL_55;
        if ( (*((_BYTE *)a2 + 32) & 4) != 0 )
        {
          if ( v4 != v5 )
          {
            if ( v5 != nullptr )
            {
              v20 = BYTE1(v5[14].__vftable);
              if ( v20 != 0 )
              {
                v21 = v20 - 1;
                BYTE1(v5[14].__vftable) = v21;
              }
              else
              {
                v21 = -1;
              }
              v64[0] = v8 != 0 ? 0x800000 : 0x10000;
              v65 = 0;
              v69 = 0;
              v22 = v5->__vftable[66].dtr_GRefCountImplCore;
              v68 = v21;
              v67 = a1;
              v64[1] = 0;
              v66 = v8;
              ((void (__thiscall *)(GRefCountWeakSupportImpl *, _DWORD *))v22)(a1: v5, a2: v64);
              v10 = v84;
            }
            v85 = false;
          }
        }
        else if ( v4 == v5 )
        {
          if ( v5 != nullptr )
          {
            v17 = BYTE1(v5[14].__vftable);
            BYTE1(v5[14].__vftable) = v17 + 1;
            v70[0] = v8 != 0 ? 0x400000 : 0x8000;
            v74 = v17;
            v71 = 0;
            v75 = 0;
            v18 = v5->__vftable;
            v73 = a1;
            v19 = v18[66].dtr_GRefCountImplCore;
            v70[1] = 0;
            v72 = v8;
            ((void (__thiscall *)(GRefCountWeakSupportImpl *, _DWORD *))v19)(a1: v5, a2: v70);
            v10 = v84;
          }
          v85 = true;
        }
        if ( v5 != nullptr && (v5[13].RefCount & 0x2000) == 0
          || v4 == nullptr
          || v4 == v5
          || ((int)v4[20].__vftable & 0x2000) == 0 )
        {
          goto LABEL_55;
        }
        ++v4->RefCount;
        if ( v5 != nullptr )
        {
          GRefCountNTSImpl::Release(this: v5);
          v10 = v84;
        }
        v23 = BYTE1(v4[21].__vftable);
        BYTE1(v4[21].__vftable) = v23 + 1;
        v57 = v23;
        v53[0] = v10 ? 0x400000 : 0x8000;
        v54 = 0;
        v58 = 0;
        v24 = v4->__vftable;
        v5 = (GRefCountWeakSupportImpl *)v4;
        v53[1] = 0;
        v55 = v8;
        v56 = a1;
        ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD *))v24[66].dtr_GRefCountImplCore)(a1: v4, a2: v53);
      }
      v85 = true;
LABEL_55:
      v9 = ++v8;
      v81 = v8;
    }
    while ( v8 < a3 );
  }
  if ( *((_DWORD *)a2 + 3) == 0 && v4 != v5 )
  {
    if ( v82 == 0 && v5 != nullptr )
    {
      v25 = BYTE1(v5[14].__vftable);
      if ( v25 != 0 )
      {
        v26 = v25 - 1;
        BYTE1(v5[14].__vftable) = v26;
      }
      else
      {
        v26 = -1;
      }
      v47 = 0;
      v51 = 0;
      v48 = 0;
      v50 = v26;
      v27 = v5->__vftable;
      v49 = a1;
      v28 = v27[66].dtr_GRefCountImplCore;
      v46[0] = 0x4000;
      v46[1] = 0;
      ((void (__thiscall *)(GRefCountWeakSupportImpl *, _DWORD *))v28)(a1: v5, a2: v46);
    }
    if ( v4 != nullptr )
      ++v4->RefCount;
    if ( v5 != nullptr )
      GRefCountNTSImpl::Release(this: v5);
    v5 = (GRefCountWeakSupportImpl *)v4;
    if ( v4 != nullptr )
    {
      v29 = BYTE1(v4[21].__vftable);
      BYTE1(v4[21].__vftable) = v29 + 1;
      v39 = v29;
      v36 = 0;
      v40 = 0;
      v37 = 0;
      v30 = v4->__vftable;
      v38 = a1;
      v31 = v30[66].dtr_GRefCountImplCore;
      v35[0] = 0x2000;
      v35[1] = 0;
      ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD *))v31)(a1: v4, a2: v35);
    }
    v85 = true;
  }
  *((_BYTE *)a2 + 32) ^= (*((_BYTE *)a2 + 32) ^ (4 * v85)) & 4;
  if ( v5 != nullptr )
  {
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: v5);
    v33 = *((_DWORD **)a2 + 2);
    if ( v33 != nullptr )
    {
      v14 = (*v33)-- == 1;
      if ( v14 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v33);
    }
    *((_DWORD *)a2 + 2) = WeakProxy;
  }
  else
  {
    v34 = *((_DWORD **)a2 + 2);
    if ( v34 != nullptr )
    {
      v14 = (*v34)-- == 1;
      if ( v14 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v34);
    }
    *((_DWORD *)a2 + 2) = 0;
  }
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  if ( v5 != nullptr )
    GRefCountNTSImpl::Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1010DBC0
// Name: public: GFxButtonAction::~GFxButtonAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonAction::~GFxButtonAction(CSchemaClassBindingBase *this)
{
  const CResourceStructIntrospection *m_pIntrospection; // ebx
  unsigned int v3; // esi
  void **p_m_pClassName; // esi

  m_pIntrospection = this->m_pIntrospection;
  v3 = 0;
  if ( m_pIntrospection != nullptr )
  {
    do
      GRefCountImpl::Release(this: *(IShaderAPI **)&this->m_pClassName[4 * v3++]);
    while ( v3 < (unsigned int)m_pIntrospection );
  }
  p_m_pClassName = (void **)&this->m_pClassName;
  if ( this->m_pIntrospection != nullptr )
  {
    if ( ((int)this->m_pNextBinding & 0xFFFFFFFE) != 0 )
    {
      if ( *p_m_pClassName != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *p_m_pClassName);
        *p_m_pClassName = nullptr;
      }
      this->m_pNextBinding = nullptr;
    }
  }
  else if ( this->m_pNextBinding == nullptr )
  {
    GArrayDataBase<GFxStaticTextRecord *,GAllocatorLH<GFxStaticTextRecord *,258>,GArrayDefaultPolicy>::Reserve(
      this: (void **)&this->m_pClassName,
      result: (const GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)&this->m_pClassName,
      newCapacity: 0);
  }
  this->m_pIntrospection = nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *p_m_pClassName);
}

//------------------------------------------------------------------------------
// Address: 0x1010DC40
// Name: public: void GFxButtonAction::Read(class GFxStream __near *,enum GFxTagType,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonAction::Read(_DWORD *this, tagBITMAPINFOHEADER *result, int a3, unsigned int a)
{
  unsigned int v4; // ebx
  int v6; // eax
  CSchemaClassBindingBase *biWidth; // eax
  int v8; // edx
  void *v9; // ecx
  int v10; // esi
  GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *v11; // edi
  unsigned int v12; // esi
  _DWORD *p_HeapTypeBits; // eax
  GASActionBufferData *aa; // [esp+18h] [ebp+10h]

  v4 = a;
  if ( a != 0 )
  {
    if ( a3 == 7 )
    {
      *this = 8;
    }
    else
    {
      v6 = result[1].biHeight - result[1].biWidth;
      BYTE1(result->biSizeImage) = 0;
      if ( v6 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      biWidth = (CSchemaClassBindingBase *)result[1].biWidth;
      v8 = (unsigned __int16)(*((unsigned __int8 *)&biWidth->__vftable + result[1].biSizeImage)
                            | (*((unsigned __int8 *)&biWidth->__vftable + result[1].biSizeImage + 1) << 8));
      result[1].biWidth = (int)&biWidth->__vftable + 2;
      *this = v8;
      v4 = a - 2;
    }
    GFxLogBase<GFxStream>::LogParse(this: result, a2: (int)"-- action conditions %X\n", *this);
    GFxLogBase<GFxStream>::LogParseAction(this: result, a2: (int)"-- actions in button\n");
    aa = GASActionBufferData::CreateNew(this: v9);
    GASActionBufferData::Read(this: aa, a2: (struct GFxStream *)result, a3: v4);
    v10 = *(this + 2);
    v11 = (GArrayDataBase<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)(this + 1);
    v12 = v10 + 1;
    if ( v12 >= v11->Size )
    {
      if ( v12 >= v11->Policy.Capacity )
        GArrayDataBase<GFxStaticTextRecord *,GAllocatorLH<GFxStaticTextRecord *,258>,GArrayDefaultPolicy>::Reserve(
          this: (void **)&v11->Data,
          result: v11,
          newCapacity: v12 + (v12 >> 2));
    }
    else if ( v12 < v11->Policy.Capacity >> 1 )
    {
      GArrayDataBase<GFxStaticTextRecord *,GAllocatorLH<GFxStaticTextRecord *,258>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v11->Data,
        result: v11,
        newCapacity: v12);
    }
    p_HeapTypeBits = &v11->Data[v12 - 1].HeapTypeBits;
    v11->Size = v12;
    if ( p_HeapTypeBits != nullptr )
      *p_HeapTypeBits = aa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010DD20
// Name: public: virtual class GASObject __near * GASButtonCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASObject *__stdcall GASButtonCtorFunction::CreateNewObject(int result)
{
  struct GASEnvironment *v1; // ebx
  bool (__thiscall *v2)(GFxAmpMessage *); // ecx
  int (__thiscall *v3)(bool (__thiscall *)(GFxAmpMessage *), int, int *); // edx
  vc_attributes::PreRangeAttribute **v4; // edi
  GASObject *v5; // eax
  GASObject *v6; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v1 = (struct GASEnvironment *)result;
  v2 = *(bool (__thiscall **)(GFxAmpMessage *))(*(_DWORD *)(result + 120) + 656);
  v3 = *(int (__thiscall **)(bool (__thiscall *)(GFxAmpMessage *), int, int *))(*(_DWORD *)v2 + 40);
  v4 = (vc_attributes::PreRangeAttribute **)(result + 120);
  result = 323;
  v5 = (GASObject *)v3(a1: v2, a2: 56, a3: &result);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v5, a2: v1);
  v6->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASButtonObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v6[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASButtonObject::`vftable'{for `GASObjectInterface'};
  v6[6].sequence = 0;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *v4,
                                                    result: (vc_attributes::InvalidCheckAttribute *)9);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v6[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v4,
    psc_4: Prototype);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1010DD90
// Name: public: GASPrototype<class GASButtonObject,class GASEnvironment>::GASPrototype<class GASButtonObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
ID3DXFont *__stdcall GASPrototype<GASButtonObject,GASEnvironment>::GASPrototype<GASButtonObject,GASEnvironment>(
        ID3DXFont *this,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        const char *pprototype,
        int constructor,
        tagRECT *psc_16,
        unsigned int psc_20,
        unsigned int psc_24)
{
  GASObject *v7; // ecx
  GASObject *v8; // esi
  __int128 v10; // [esp-8h] [ebp-14h]

  v8 = v7;
  GASObject::GASObject(this: v7, a2: (struct GASStringContext *)this);
  v8->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASButtonObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v8[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASButtonObject::`vftable'{for `GASObjectInterface'};
  v8[6].sequence = 0;
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v8[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)this,
    psc_4: psc);
  v8[7].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASPrototypeBase::`vftable';
  LOBYTE(v8[8].sequence) = 0;
  v8[7].sequence = 0;
  v8[8].pNode = nullptr;
  LOBYTE(v8[10].pNode) = 0;
  v8[9].pNode = nullptr;
  v8[9].sequence = 0;
  v8[10].sequence = 0;
  *(_QWORD *)&v10 = __PAIR64__((unsigned int)pprototype, (unsigned int)this);
  v8->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASPrototype<GASButtonObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  v8[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASButtonProto::`vftable'{for `GASObjectInterface'};
  v8[7].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASButtonProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)&v8[7],
    pthis: (CMaterialVar *)v8,
    psc: v10);
  return (ID3DXFont *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x1010DE10
// Name: public: static void GConstructorMov<class GFxButtonRecord>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
float *__cdecl GConstructorMov<GFxButtonRecord>::ConstructArray(char *p, unsigned int count)
{
  unsigned int v2; // edi
  char *v3; // esi
  float *result; // eax

  v2 = count;
  if ( count != 0 )
  {
    v3 = p + 8;
    do
    {
      result = (float *)(v3 - 8);
      if ( v3 != (char *)8 )
      {
        *((_DWORD *)v3 - 2) = 0;
        *((_DWORD *)v3 - 1) = 0;
        *(_DWORD *)v3 = 0;
        GMatrix2D::SetIdentity(this: (float *)v3 + 1);
        result = GRenderer::Cxform::Cxform(this: (float *)v3 + 7);
        *((_DWORD *)v3 + 15) = 0x40000;
        v3[72] = 0;
      }
      v3 += 84;
      --v2;
    }
    while ( v2 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010DE60
// Name: public: void GFxButtonCharacter::RecreateCharacters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::RecreateCharacters(CUtlMemory<ResourceEntryInfo,int> *this)
{
  CUtlMemory<ResourceEntryInfo,int> *v1; // esi
  int m_nAllocationCount; // eax
  unsigned int v3; // ecx
  int v4; // edi
  int v5; // ebx
  int m_nGrowSize; // eax
  bool v7; // zf
  float *v8; // edi
  int v9; // eax
  GRefCountNTSImpl **v10; // esi
  GRefCountNTSImpl *v11; // ebx
  CMatQueuedIndexBuffer *v12; // esi
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountNTSImpl *); // eax
  GRefCountNTSImpl_vtbl *v14; // esi
  void (__thiscall *v15)(struct GRefCountNTSImpl *); // eax
  int v16; // edi
  CUtlMemory<ResourceEntryInfo,int> *v17; // esi
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v18; // eax
  int v19; // edx
  const CMatQueuedIndexBuffer *v20; // edx
  CMatQueuedIndexBuffer *v21; // eax
  int v22; // eax
  _IMAGE_SYMBOL_EX *v23; // eax
  unsigned int v24; // eax
  const GPoint3<float> *inserted; // esi
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  int v28; // ecx
  float v29; // edx
  float v30; // eax
  float v31; // ecx
  const GPoint3<float> *v32; // eax
  _DWORD *p_x; // esi
  GRefCountNTSImpl *v34; // ecx
  GRefCountNTSImpl *v35; // ecx
  const GPoint3<float> *v36; // eax
  GPtr<IDirect3DPixelShader9> *v37; // esi
  GRefCountNTSImpl *v38; // ecx
  GRefCountNTSImpl *pObject; // ecx
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v40; // esi
  int v41; // eax
  int v42; // eax
  bool v43; // zf
  int v44; // [esp-8h] [ebp-78h]
  const CMatQueuedIndexBuffer *v45; // [esp-4h] [ebp-74h]
  GASValue v46[4]; // [esp+Ch] [ebp-64h] BYREF
  int v47; // [esp+1Ch] [ebp-54h]
  float v48; // [esp+20h] [ebp-50h]
  __int64 v49; // [esp+24h] [ebp-4Ch]
  GPtr<IDirect3DPixelShader9> v50; // [esp+2Ch] [ebp-44h] BYREF
  int v51; // [esp+30h] [ebp-40h]
  int v52; // [esp+34h] [ebp-3Ch]
  int v53; // [esp+38h] [ebp-38h] BYREF
  int v54; // [esp+3Ch] [ebp-34h]
  char v55; // [esp+40h] [ebp-30h]
  int rid[2]; // [esp+44h] [ebp-2Ch] BYREF
  int v57; // [esp+4Ch] [ebp-24h]
  GASGlobalContext *v58; // [esp+50h] [ebp-20h]
  CMatQueuedIndexBuffer *NameOfExportedResource; // [esp+54h] [ebp-1Ch]
  int v60; // [esp+58h] [ebp-18h]
  unsigned int v61; // [esp+5Ch] [ebp-14h]
  CUtlMemory<ResourceEntryInfo,int> *v62; // [esp+60h] [ebp-10h]
  int v63; // [esp+64h] [ebp-Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *StringNode; // [esp+68h] [ebp-8h] BYREF
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result; // [esp+6Ch] [ebp-4h]

  v1 = this;
  m_nAllocationCount = *((_DWORD *)this + 46);
  v3 = 0;
  v62 = v1;
  v61 = 0;
  if ( *(_DWORD *)(m_nAllocationCount + 28) != 0 )
  {
    v4 = 0;
    v60 = 0;
    while ( 1 )
    {
      v5 = v4 + *(_DWORD *)(m_nAllocationCount + 24);
      v7 = *((_DWORD *)&v1[16].m_pMemory->___u0 + v3) == 0;
      result = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(4 * v3);
      m_nGrowSize = v1[17].m_nGrowSize;
      v63 = v5;
      if ( v7 )
        break;
      if ( m_nGrowSize != 0 )
      {
        if ( m_nGrowSize == 1 )
        {
          v43 = (*(_BYTE *)(v5 + 80) & 2) == 0;
        }
        else
        {
          if ( m_nGrowSize != 2 )
            goto LABEL_72;
          v43 = (*(_BYTE *)(v5 + 80) & 4) == 0;
        }
      }
      else
      {
        v43 = (*(_BYTE *)(v5 + 80) & 8) == 0;
      }
      if ( v43 )
      {
LABEL_72:
        if ( (*(_BYTE *)(v5 + 80) & 1) == 0 )
          GFxButtonCharacter::UnloadCharacterAtIndex(this: v1, i: v3);
      }
LABEL_74:
      m_nAllocationCount = v1[15].m_nAllocationCount;
      v3 = v61 + 1;
      v4 += 84;
      v61 = v3;
      v60 = v4;
      if ( v3 >= *(_DWORD *)(m_nAllocationCount + 28) )
        return;
    }
    if ( m_nGrowSize != 0 )
    {
      if ( m_nGrowSize == 1 )
      {
        v7 = (*(_BYTE *)(v5 + 80) & 2) == 0;
      }
      else
      {
        if ( m_nGrowSize != 2 )
          goto LABEL_11;
        v7 = (*(_BYTE *)(v5 + 80) & 4) == 0;
      }
    }
    else
    {
      v7 = (*(_BYTE *)(v5 + 80) & 8) == 0;
    }
    if ( !v7 )
      goto LABEL_12;
LABEL_11:
    if ( (*(_BYTE *)(v5 + 80) & 1) != 0 )
    {
LABEL_12:
      GFxMovieDefImpl::GetCharacterCreateInfo(
        this: (CMatQueuedIndexBuffer *)v1[12].m_pMemory,
        (_RATE_QUOTA_LIMIT *)rid,
        rh: *(const IndexDesc_t **)(v5 + 68));
      if ( rid[0] != 0 )
      {
        v8 = (float *)(*(_DWORD *)(v1[15].m_nAllocationCount + 24) + v4);
        v44 = *(_DWORD *)(v5 + 68);
        NameOfExportedResource = (CMatQueuedIndexBuffer *)(v8 + 9);
        v9 = (*(int (__thiscall **)(int, CUtlMemory<ResourceEntryInfo,int> *, int, int))(*(_DWORD *)rid[0] + 36))(
               a1: rid[0],
               a2: v1,
               a3: v44,
               a4: rid[1]);
        v10 = (GRefCountNTSImpl **)((char *)result + (unsigned int)v1[16].m_pMemory);
        v11 = (GRefCountNTSImpl *)v9;
        if ( v9 != 0 )
          ++*(_DWORD *)(v9 + 4);
        if ( *v10 != nullptr )
          GRefCountNTSImpl::Release(this: *v10);
        *v10 = v11;
        v12 = NameOfExportedResource;
        v11[8].RefCount = (volatile int)v8[3];
        v11[9].__vftable = (GRefCountNTSImpl_vtbl *)v8[4];
        v11[9].RefCount = (volatile int)v8[5];
        v11[10].__vftable = (GRefCountNTSImpl_vtbl *)v8[6];
        v11[10].RefCount = (volatile int)v8[7];
        v11[11].__vftable = (GRefCountNTSImpl_vtbl *)v8[8];
        dtr_GRefCountImplCore = v11->__vftable[1].dtr_GRefCountImplCore;
        qmemcpy((void *)&v11[4].RefCount, v12, 0x20u);
        dtr_GRefCountImplCore(this: v11);
        ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v11->__vftable[9].dtr_GRefCountImplCore)(
          a1: v11,
          a2: *(_DWORD *)(v63 + 76));
        v14 = v11[4].__vftable;
        HIWORD(v11[14].RefCount) &= ~1u;
        if ( v14 != nullptr )
        {
          while ( (*((int (__thiscall **)(GRefCountNTSImpl_vtbl *))v14->dtr_GRefCountImplCore + 19))(a1: v14) == 0 )
          {
            v14 = (GRefCountNTSImpl_vtbl *)v14[8].dtr_GRefCountImplCore;
            if ( v14 == nullptr )
              goto LABEL_22;
          }
          v15 = v11->__vftable[20].dtr_GRefCountImplCore;
          HIWORD(v11[14].RefCount) |= 1u;
          v15(this: v11);
        }
LABEL_22:
        v16 = BYTE2(v11[14].RefCount) >> 7 != 0 ? (unsigned int)v11 : 0;
        if ( v16 != 0 )
        {
          v17 = v62;
          v18 = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))v62->m_pMemory[10].resData)(a1: v62);
          v19 = *(_DWORD *)(v16 + 120);
          result = v18;
          if ( (*(int (__thiscall **)(int))(v19 + 8))(a1: v16 + 120) == 2 )
          {
            v58 = (GASGlobalContext *)((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))v17->m_pMemory[26].eType)(a1: v17);
            v20 = *(const CMatQueuedIndexBuffer **)(v63 + 68);
            v53 = 0;
            v54 = 0;
            v55 = 0;
            v45 = v20;
            v21 = (CMatQueuedIndexBuffer *)((int (__thiscall *)(GRefCountNTSImpl *))v11->__vftable[23].dtr_GRefCountImplCore)(a1: v11);
            NameOfExportedResource = GFxMovieDefImpl::GetNameOfExportedResource(this: v21, rid: v45);
            if ( NameOfExportedResource != nullptr )
            {
              v22 = ((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))v17->m_pMemory[14].eType)(a1: v17);
              StringNode = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)GASStringManager::CreateStringNode(this: *(GASStringManager **)(*(_DWORD *)(v22 + 120) + 636), result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)NameOfExportedResource->__vftable & 0xFFFFFFFC) + 8), length: *(_DWORD *)((int)NameOfExportedResource->__vftable & 0xFFFFFFFC) & 0x7FFFFFFF);
              ++StringNode->m_nGrowSize;
              v23 = (_IMAGE_SYMBOL_EX *)((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))v17->m_pMemory[14].eType)(a1: v17);
              if ( GASGlobalContext::FindRegisteredClass(
                     this: (GFxMeshCacheManager *)v58,
                     className: v23 + 6,
                     key: (_IMAGE_SYMBOL_EX *)&StringNode,
                     a4: (struct GASFunctionRef *)&v53) != 0 )
              {
                if ( v53 != 0 )
                  v24 = v53 + 16;
                else
                  v24 = 0;
                GFxASCharacter::SetProtoToPrototypeOf(
                  this: (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v16,
                  psrcObj: v24);
                inserted = GFxMovieRoot::ActionQueueType::InsertEntry(
                             this: (int)&result[384].m_pfnProxied + 8,
                             result: (const GPoint3<float> *)3);
                if ( inserted != nullptr )
                {
                  LODWORD(inserted->y) = 2;
                  v47 = 0x40000;
                  v48 = 0.0;
                  LOWORD(v49) = 0;
                  *(_DWORD *)((char *)&v49 + 2) = 65280;
                  ++*(_DWORD *)(v16 + 4);
                  z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
                  if ( z_low != nullptr )
                    GRefCountNTSImpl::Release(this: z_low);
                  LODWORD(inserted->z) = v16;
                  x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
                  if ( x_low != nullptr )
                    GRefCountNTSImpl::Release(this: x_low);
                  v28 = v47;
                  v29 = v48;
                  v30 = *(float *)&v49;
                  inserted[1].x = 0.0;
                  LODWORD(inserted[1].y) = v28;
                  v31 = *((float *)&v49 + 1);
                  inserted[1].z = v29;
                  inserted[2].x = v30;
                  inserted[2].y = v31;
                }
                v32 = GFxMovieRoot::ActionQueueType::InsertEntry(
                        this: (int)&result[384].m_pfnProxied + 8,
                        result: (const GPoint3<float> *)3);
                p_x = (_DWORD *)&v32->x;
                if ( v32 != nullptr )
                {
                  LODWORD(v32->y) = 3;
                  ++*(_DWORD *)(v16 + 4);
                  v34 = (GRefCountNTSImpl *)LODWORD(v32->z);
                  if ( v34 != nullptr )
                    GRefCountNTSImpl::Release(this: v34);
                  p_x[2] = v16;
                  v35 = (GRefCountNTSImpl *)p_x[3];
                  if ( v35 != nullptr )
                    GRefCountNTSImpl::Release(this: v35);
                  p_x[3] = 0;
                  GASFunctionRefBase::Assign(
                    this: (GASFunctionRefBase *)(p_x + 8),
                    orig: (const struct GASFunctionRefBase *)&v53);
                }
              }
              else
              {
                v46[1] = StringNode;
                LOBYTE(v46[0]) = 5;
                ++StringNode->m_nGrowSize;
                v50.pObject = nullptr;
                v51 = 0;
                v52 = 0;
                GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
                  this: &v50,
                  pheapAddr: (ButtonCode_t)&v50,
                  newSize: 1u);
                if ( &v50.pObject[4 * v51] != (IDirect3DPixelShader9 *)16 )
                  GASValue::GASValue(this: (GASValue *)&v50.pObject[4 * v51 - 4], a2: (const struct GASValue *)v46);
                GASValue::~GASValue(this: v46);
                v36 = GFxMovieRoot::ActionQueueType::InsertEntry(
                        this: (int)&result[384].m_pfnProxied + 8,
                        result: (const GPoint3<float> *)3);
                v37 = (GPtr<IDirect3DPixelShader9> *)v36;
                if ( v36 != nullptr )
                {
                  LODWORD(v36->y) = 4;
                  ++*(_DWORD *)(v16 + 4);
                  v38 = (GRefCountNTSImpl *)LODWORD(v36->z);
                  if ( v38 != nullptr )
                    GRefCountNTSImpl::Release(this: v38);
                  v37[2].pObject = (IDirect3DPixelShader9 *)v16;
                  pObject = (GRefCountNTSImpl *)v37[3].pObject;
                  if ( pObject != nullptr )
                    GRefCountNTSImpl::Release(this: pObject);
                  v37[3].pObject = nullptr;
                  v37[11].pObject = (IDirect3DPixelShader9 *)GFx_FindClassAndInitializeClassInstance;
                  GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
                    this: v37 + 12,
                    a2: &v50);
                }
                GArray<GASValue,2,GArrayDefaultPolicy>::~GArray<GASValue,2,GArrayDefaultPolicy>(this: &v50);
              }
              v7 = StringNode->m_nGrowSize-- == 1;
              if ( v7 )
                GASStringNode::ReleaseNode();
            }
            if ( (v55 & 2) == 0 && v53 != 0 )
              GRefCountBaseGC<323>::Release(a1: v53, a2: v16);
            v53 = 0;
            if ( (v55 & 1) == 0 && v54 != 0 )
              GRefCountBaseGC<323>::Release(a1: v54, a2: v16);
            v54 = 0;
          }
          v40 = result;
          GFxASCharacter::AddToPlayList(this: (_DWORD *)v16, result);
          v41 = *(_DWORD *)v16;
          LOBYTE(v57) = (*(_DWORD *)(v16 + 160) & 0x80000) != 0;
          v42 = (*(int (__thiscall **)(int, int))(v41 + 292))(a1: v16, a2: v57);
          if ( v42 == -1 )
          {
            GFxASCharacter::RemoveFromOptimizedPlaylist(this: (CMatQueuedMesh **)v16, result: v40);
          }
          else if ( v42 == 1 )
          {
            GFxASCharacter::AddToOptimizedPlayList(this: v16, result: v40);
          }
          v11->__vftable[33].dtr_GRefCountImplCore(this: v11);
        }
        GRefCountNTSImpl::Release(this: v11);
        v4 = v60;
        v1 = v62;
      }
      goto LABEL_74;
    }
    goto LABEL_74;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E320
// Name: public: GASButtonProto::GASButtonProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
_EXCEPTION_RECORD *__thiscall GASButtonProto::GASButtonProto(
        _EXCEPTION_RECORD *this,
        ID3DXFont *psc,
        _CONTEXT *prototype,
        const char *constructor)
{
  _EXCEPTION_REGISTRATION_RECORD *v5; // eax
  bool v6; // zf
  _EXCEPTION_REGISTRATION_RECORD *v7; // eax
  _EXCEPTION_REGISTRATION_RECORD *v8; // eax
  _EXCEPTION_REGISTRATION_RECORD *v9; // eax
  _EXCEPTION_REGISTRATION_RECORD *v10; // eax
  const struct GASString *p_GetDescA; // [esp-Ch] [ebp-28h]
  int v13; // [esp+0h] [ebp-1Ch]
  tagRECT *v14; // [esp+4h] [ebp-18h]
  unsigned int v15; // [esp+8h] [ebp-14h]
  GASValue v16; // [esp+Ch] [ebp-10h] BYREF
  char v17; // [esp+10h] [ebp-Ch]

  GASPrototype<GASButtonObject,GASEnvironment>::GASPrototype<GASButtonObject,GASEnvironment>(
    this: psc,
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)prototype,
    pprototype: constructor,
    constructor: v13,
    psc_16: v14,
    psc_20: v15,
    psc_24: (unsigned int)v16);
  this->ExceptionCode = (unsigned int)&GASPrototype<GASButtonObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  this->NumberParameters = (unsigned int)&GASButtonProto::`vftable'{for `GASObjectInterface'};
  this->ExceptionInformation[9] = (unsigned int)&GASButtonProto::`vftable';
  HIBYTE(constructor) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)&this->ExceptionInformation[9],
    a2: (struct GASObject *)this,
    a3: (struct GASStringContext *)psc,
    a4: (const struct GASNameFunction *)GAS_ButtonFunctionTable,
    a5: (const struct GASPropFlags *)((char *)&constructor + 3));
  p_GetDescA = (const struct GASString *)&psc->__vftable[7].GetDescA;
  HIBYTE(constructor) = 2;
  LOBYTE(v16) = 2;
  v17 = 1;
  GASObject::SetMemberRaw(
    this: (GASObject *)&this->NumberParameters,
    a2: (struct GASStringContext *)psc,
    a3: p_GetDescA,
    a4: &v16,
    a5: (const struct GASPropFlags *)((char *)&constructor + 3));
  GASValue::~GASValue(this: &v16);
  v5 = (_EXCEPTION_REGISTRATION_RECORD *)psc->__vftable;
  HIBYTE(constructor) = 2;
  LOBYTE(v16) = 10;
  prototype = (_CONTEXT *)GASStringManager::CreateConstStringNode(
                            this: (GASStringManager *)v5[79].Handler,
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E460,
                            a3: 9u,
                            a4: 0);
  ++prototype->Dr1;
  (*(void (__thiscall **)(unsigned int *, ID3DXFont *, _CONTEXT **, GASValue *, char *))(this->NumberParameters + 40))(
    a1: &this->NumberParameters,
    a2: psc,
    a3: &prototype,
    a4: &v16,
    a5: (char *)&constructor + 3);
  v6 = prototype->Dr1-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: &v16);
  v7 = (_EXCEPTION_REGISTRATION_RECORD *)psc->__vftable;
  HIBYTE(constructor) = 2;
  LOBYTE(v16) = 10;
  prototype = (_CONTEXT *)GASStringManager::CreateConstStringNode(
                            this: (GASStringManager *)v7[79].Handler,
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E434.m_Size,
                            a3: 7u,
                            a4: 0);
  ++prototype->Dr1;
  (*(void (__thiscall **)(unsigned int *, ID3DXFont *, _CONTEXT **, GASValue *, char *))(this->NumberParameters + 40))(
    a1: &this->NumberParameters,
    a2: psc,
    a3: &prototype,
    a4: &v16,
    a5: (char *)&constructor + 3);
  v6 = prototype->Dr1-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: &v16);
  v8 = (_EXCEPTION_REGISTRATION_RECORD *)psc->__vftable;
  HIBYTE(constructor) = 2;
  LOBYTE(v16) = 10;
  prototype = (_CONTEXT *)GASStringManager::CreateConstStringNode(
                            this: (GASStringManager *)v8[79].Handler,
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E3C4,
                            a3: 0xAu,
                            a4: 0);
  ++prototype->Dr1;
  (*(void (__thiscall **)(unsigned int *, ID3DXFont *, _CONTEXT **, GASValue *, char *))(this->NumberParameters + 40))(
    a1: &this->NumberParameters,
    a2: psc,
    a3: &prototype,
    a4: &v16,
    a5: (char *)&constructor + 3);
  v6 = prototype->Dr1-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: &v16);
  v9 = (_EXCEPTION_REGISTRATION_RECORD *)psc->__vftable;
  HIBYTE(constructor) = 2;
  LOBYTE(v16) = 10;
  prototype = (_CONTEXT *)GASStringManager::CreateConstStringNode(
                            this: (GASStringManager *)v9[79].Handler,
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E410,
                            a3: 8u,
                            a4: 0);
  ++prototype->Dr1;
  (*(void (__thiscall **)(unsigned int *, ID3DXFont *, _CONTEXT **, GASValue *, char *))(this->NumberParameters + 40))(
    a1: &this->NumberParameters,
    a2: psc,
    a3: &prototype,
    a4: &v16,
    a5: (char *)&constructor + 3);
  v6 = prototype->Dr1-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: &v16);
  v10 = (_EXCEPTION_REGISTRATION_RECORD *)psc->__vftable;
  HIBYTE(constructor) = 2;
  LOBYTE(v16) = 10;
  prototype = (_CONTEXT *)GASStringManager::CreateConstStringNode(
                            this: (GASStringManager *)v10[79].Handler,
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E434,
                            a3: 0xBu,
                            a4: 0);
  ++prototype->Dr1;
  (*(void (__thiscall **)(unsigned int *, ID3DXFont *, _CONTEXT **, GASValue *, char *))(this->NumberParameters + 40))(
    a1: &this->NumberParameters,
    a2: psc,
    a3: &prototype,
    a4: &v16,
    a5: (char *)&constructor + 3);
  v6 = prototype->Dr1-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: &v16);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010E5A0
// Name: public: GFxButtonCharacter::GFxButtonCharacter(class GFxButtonCharacterDef __near *,class GFxMovieDefImpl __near *,class GFxASCharacter __near *,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<ResourceEntryInfo,int> *__thiscall GFxButtonCharacter::GFxButtonCharacter(
        CUtlMemory<ResourceEntryInfo,int> *this,
        struct GFxButtonCharacterDef *a2,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingDefImpl,
        struct GFxASCharacter *a4,
        struct GFxResourceId a5)
{
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // ebx
  _DWORD *i; // eax
  struct GASEnvironment *v10; // eax
  vc_attributes::PreRangeAttribute *v11; // eax
  int ActualPrototype; // eax
  int v13; // edi
  int v14; // ecx
  struct GASEnvironment *v16; // [esp-8h] [ebp-14h]
  int v17; // [esp+0h] [ebp-Ch]
  const MorphWeight_t *v18; // [esp+0h] [ebp-Ch]
  struct GFxASCharacter *v19; // [esp+1Ch] [ebp+10h]

  GFxASCharacter::GFxASCharacter((GFxASCharacter *)this, pbindingDefImpl, a3: a4, a4: a5);
  *((_DWORD *)this + 46) = a2;
  this->m_pMemory = (ResourceEntryInfo *)&GFxButtonCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxButtonCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxButtonCharacter::`vftable';
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  GFxButtonCharacter::SetScale9Grid(this, gr: *((_DWORD *)a2 + 12), a3: v17);
  v6 = *((_DWORD *)this + 46);
  if ( *(_BYTE *)(v6 + 20) != 0 )
    *((_DWORD *)this + 40) |= 0x2000u;
  else
    *((_DWORD *)this + 40) &= ~0x2000u;
  v7 = *(_DWORD *)(v6 + 28);
  v19 = *((struct GFxASCharacter **)this + 49);
  GArrayDataBase<GFxDisplayList::DisplayEntry,GAllocatorLH<GFxDisplayList::DisplayEntry,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (CMatNullRenderContext *)(this + 16),
    pheapAddr: (IMorph *)this + 48,
    newSize: v7,
    a4: v18);
  if ( v7 > (unsigned int)v19 )
  {
    v8 = v7 - (_DWORD)v19;
    for ( i = (_DWORD *)(*((_DWORD *)this + 48) + 4 * (_DWORD)v19); v8 != 0; --v8 )
    {
      if ( i != nullptr )
        *i = 0;
      ++i;
    }
  }
  GFxCharacter::GetASEnvironment((CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this);
  v16 = v10;
  GFxASCharacter::GetGC((CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this);
  ActualPrototype = GASGlobalContext::GetActualPrototype(this: v11, a2: v16, a3: 9);
  v13 = ActualPrototype;
  if ( ActualPrototype != 0 )
    *(_DWORD *)(ActualPrototype + 8) = (*(_DWORD *)(ActualPrototype + 8) + 1) & 0x8FFFFFFF;
  v14 = *((_DWORD *)this + 32);
  if ( v14 != 0 )
    GRefCountBaseGC<323>::Release(a1: v14, a2: ActualPrototype);
  *((_DWORD *)this + 32) = v13;
  GFxButtonCharacter::RecreateCharacters(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010E6C0
// Name: public: virtual void GFxButtonCharacter::PropagateMouseEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxButtonCharacter::PropagateMouseEvent(
        CUtlMemory<ResourceEntryInfo,int> *this,
        const CMaterialDict::MissingMaterial_t *event)
{
  if ( *(_DWORD *)&event->m_Name.m_Id == 8 )
    GFxASCharacter::DoMouseDrag((GFxASCharacter *)this, a2: event);
  return ((bool (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *, const CMaterialDict::MissingMaterial_t *))this->m_pMemory[16].eType)(
           a1: this,
           a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x1010E6F0
// Name: public: virtual unsigned long GFxButtonCharacter::GetStandardMemberBitMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxButtonCharacter::GetStandardMemberBitMask(CUtlMemory<ResourceEntryInfo,int> *this)
{
  return -268455985;
}

//------------------------------------------------------------------------------
// Address: 0x1010E730
// Name: public: virtual void GFxButtonCharacter::PropagateScale9GridExists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::PropagateScale9GridExists(GFxButtonCharacter *this)
{
  int v2; // eax
  bool v3; // bl
  unsigned int i; // edi
  _WORD *v5; // ecx

  v2 = (*(int (__thiscall **)(GFxButtonCharacter *))(*(_DWORD *)this + 76))(a1: this);
  v3 = v2 != 0;
  if ( (*((_BYTE *)this + 118) & 1) != 0 || v2 == 0 )
  {
    for ( i = 0; i < *((_DWORD *)this + 49); ++i )
    {
      v5 = *(_WORD **)(*((_DWORD *)this + 48) + 4 * i);
      if ( v5 != nullptr )
      {
        if ( (*((_BYTE *)this + 118) & 1) != 0 || v3 )
          v5[59] |= 1u;
        else
          v5[59] &= ~1u;
        (*(void (__thiscall **)(_WORD *))(*(_DWORD *)v5 + 80))(a1: v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E790
// Name: public: virtual void GFxButtonCharacter::PropagateNoAdvanceGlobalFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::PropagateNoAdvanceGlobalFlag(GFxButtonCharacter *this)
{
  unsigned int i; // ebx
  int v3; // eax
  CMatQueuedMesh **v4; // esi
  int v5; // eax
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result; // [esp+8h] [ebp-8h]
  bool v7; // [esp+Fh] [ebp-1h]

  v7 = (*((_DWORD *)this + 40) & 8) != 0;
  result = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(int (__thiscall **)(GFxButtonCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( result != nullptr )
  {
    for ( i = 0; i < *((_DWORD *)this + 49); ++i )
    {
      v3 = *(_DWORD *)(*((_DWORD *)this + 48) + 4 * i);
      if ( v3 != 0 )
      {
        v4 = *(_BYTE *)(v3 + 118) >> 7 != 0 ? (CMatQueuedMesh **)v3 : nullptr;
        if ( v4 != nullptr )
        {
          if ( (*((_DWORD *)this + 40) & 8) != 0 || v7 )
            v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] | 8);
          else
            v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] & 0xFFFFFFF7);
          (*(void (__thiscall **)(CMatQueuedMesh **))&(*v4)[3].m_VertexSize)(a1: v4);
          v5 = ((int (__thiscall *)(CMatQueuedMesh **, bool))(*v4)[3].m_nIndices)(
                 a1: v4,
                 a2: ((unsigned int)v4[40] & 0x80000) != 0);
          if ( v5 == -1 )
          {
            GFxASCharacter::RemoveFromOptimizedPlaylist(this: v4, result);
          }
          else if ( v5 == 1 )
          {
            GFxASCharacter::AddToOptimizedPlayList(this: (int)v4, result);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E880
// Name: public: virtual void GFxButtonCharacter::PropagateNoAdvanceLocalFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::PropagateNoAdvanceLocalFlag(GFxButtonCharacter *this)
{
  unsigned int i; // ebx
  int v3; // eax
  CMatQueuedMesh **v4; // esi
  int v5; // eax
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result; // [esp+8h] [ebp-8h]
  bool v7; // [esp+Fh] [ebp-1h]

  v7 = (*((_DWORD *)this + 40) & 4) != 0;
  result = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(int (__thiscall **)(GFxButtonCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( result != nullptr )
  {
    for ( i = 0; i < *((_DWORD *)this + 49); ++i )
    {
      v3 = *(_DWORD *)(*((_DWORD *)this + 48) + 4 * i);
      if ( v3 != 0 )
      {
        v4 = *(_BYTE *)(v3 + 118) >> 7 != 0 ? (CMatQueuedMesh **)v3 : nullptr;
        if ( v4 != nullptr )
        {
          if ( (*((_DWORD *)this + 40) & 4) != 0 || v7 )
            v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] | 4);
          else
            v4[40] = (CMatQueuedMesh *)((unsigned int)v4[40] & 0xFFFFFFFB);
          (*(void (__thiscall **)(CMatQueuedMesh **))&(*v4)[3].m_bExternalIB)(a1: v4);
          v5 = ((int (__thiscall *)(CMatQueuedMesh **, bool))(*v4)[3].m_nIndices)(
                 a1: v4,
                 a2: ((unsigned int)v4[40] & 0x80000) != 0);
          if ( v5 == -1 )
          {
            GFxASCharacter::RemoveFromOptimizedPlaylist(this: v4, result);
          }
          else if ( v5 == 1 )
          {
            GFxASCharacter::AddToOptimizedPlayList(this: (int)v4, result);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E970
// Name: public: virtual void GFxButtonCharacter::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxButtonCharacter::SetVisible(CUtlMemory<ResourceEntryInfo,int> *this@<ecx>, bool visible, int a3)
{
  int v4; // eax
  bool v5; // cl
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  int v9; // eax

  if ( visible )
    *((_DWORD *)this + 40) |= 1u;
  else
    *((_DWORD *)this + 40) &= ~1u;
  v4 = ((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[10].resData)(a1: this);
  if ( v4 != 0 )
  {
    v5 = !visible && (*(_DWORD *)(v4 + 9332) & 0x800) != 0;
    v6 = *((_DWORD *)this + 40);
    if ( v5 != ((v6 & 8) != 0) )
    {
      if ( v5 )
        v7 = v6 | 8;
      else
        v7 = v6 & 0xFFFFFFF7;
      *((_DWORD *)this + 40) = v7;
      v8 = *((_DWORD *)this + 8);
      if ( v8 != 0 && (*(_DWORD *)(v8 + 160) & 8) == 0 )
        ((void (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[37].eType)(a1: this);
    }
    v9 = ((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[10].resData)(a1: this);
    *(_DWORD *)(v9 + 9332) |= 0x400u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EA10
// Name: public: virtual void GFxButtonCharacter::Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::Restart(GFxButtonCharacter *this)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi
  int v4; // ecx
  int v5; // eax

  v2 = *((_DWORD *)this + 49);
  v3 = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 53) = 0;
  for ( *((_BYTE *)this + 169) = 0; v3 < v2; ++v3 )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 48) + 4 * v3);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 120))(a1: v4);
  }
  v5 = (*(int (__thiscall **)(GFxButtonCharacter *))(*(_DWORD *)this + 84))(a1: this);
  *(_DWORD *)(v5 + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x1010EA70
// Name: public: virtual bool GFxButtonCharacter::IsTabable(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxButtonCharacter::IsTabable(GFxButtonCharacter *this)
{
  char result; // al
  int v3; // ebx
  tagPOLYTEXTW *v4; // edi
  char v5; // bl
  unsigned __int8 v7; // bl
  GASValue val[4]; // [esp+4h] [ebp-14h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+14h] [ebp-4h] BYREF

  result = (*(int (__thiscall **)(GFxButtonCharacter *))(*(_DWORD *)this + 16))(a1: this);
  if ( result != 0 )
  {
    if ( (*((_DWORD *)this + 40) & 0x60) != 0 )
    {
      return (*((_DWORD *)this + 40) & 0x60) == 96;
    }
    else
    {
      v3 = *((_DWORD *)this + 32);
      if ( v3 != 0 )
      {
        LOBYTE(val[0]) = 0;
        v4 = (tagPOLYTEXTW *)(*(int (__thiscall **)(GFxButtonCharacter *))(*(_DWORD *)this + 108))(a1: this);
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(v4[3].x + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E410.m_Size,
                            a3: 0xAu,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        v5 = (*(int (__thiscall **)(int, tagPOLYTEXTW *, struct GASStringNode **, GASValue *))(*(_DWORD *)(v3 + 16) + 44))(
               a1: v3 + 16,
               a2: v4 + 3,
               a3: &ConstStringNode,
               a4: val);
        if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
          GASStringNode::ReleaseNode();
        if ( v5 != 0 && LOBYTE(val[0]) != 0 && LOBYTE(val[0]) != 10 )
        {
          v7 = (unsigned __int8)GASValue::ToBool(result: v4);
          GASValue::~GASValue(this: val);
          return v7;
        }
        GASValue::~GASValue(this: val);
      }
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010EB50
// Name: public: virtual bool GFxButtonCharacter::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxButtonCharacter::GetMember(
        GFxButtonCharacter *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *result,
        struct GASValue *a4)
{
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *StandardMemberConstant; // eax
  int v7; // eax
  int v9; // ebx
  int v10; // esi
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *v12; // [esp+18h] [ebp+Ch]

  if ( (*(_DWORD *)(result->N.Name.Short + 12) & 0x20000000) != 0 )
  {
    v12 = *((CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> **)this
          - 30);
    StandardMemberConstant = GFxASCharacter::GetStandardMemberConstant(this: (char *)this - 120, result);
    if ( ((unsigned __int8 (__thiscall *)(char *, CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, struct GASValue *, _DWORD))LODWORD(v12[12].m_pfnProxied))(
           a1: (char *)this - 120,
           a2: StandardMemberConstant,
           a3: a4,
           a4: 0) != 0 )
      return true;
  }
  v7 = *((_DWORD *)this + 24);
  if ( v7 != 0 )
    return (*(bool (__thiscall **)(int, struct GASEnvironment *, _IMAGE_SYMBOL_EX *, struct GASValue *))(*(_DWORD *)(v7 + 16) + 16))(
             a1: v7 + 16,
             a2,
             a3: result,
             a4);
  if ( a2 != nullptr && result->N.Name.Short == *(_DWORD *)(*((_DWORD *)a2 + 30) + 320) )
  {
    GASValue::SetAsObject(this: (GASValue *)a4, a2: *((struct GASObject **)this + 2));
    return true;
  }
  v9 = *((_DWORD *)this + 2);
  if ( v9 != 0
    && (*(unsigned __int8 (__thiscall **)(int, struct GASEnvironment *, _IMAGE_SYMBOL_EX *, struct GASValue *))(*(_DWORD *)(v9 + 16) + 16))(
         a1: v9 + 16,
         a2,
         a3: result,
         a4) != 0 )
  {
    return true;
  }
  if ( a2 == nullptr )
    return false;
  v10 = *((_DWORD *)a2 + 30);
  if ( result->N.Name.Short != *(_DWORD *)(v10 + 260) )
    return false;
  GASValue::SetAsObject(this: (GASValue *)a4, a2: *(struct GASObject **)(v10 + 680));
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1010EC30
// Name: public: virtual void GFxButtonCharacter::SetStateChangeFlags(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::SetStateChangeFlags(
        CUtlMemory<ResourceEntryInfo,int> *this,
        CUtlMemory<ResourceEntryInfo,int> *flags)
{
  unsigned int v3; // ebx
  unsigned int i; // edi
  int v5; // ecx

  v3 = *((_DWORD *)this + 49);
  *((_DWORD *)this + 40) ^= (*((_DWORD *)this + 40) ^ ((unsigned __int8)flags << 16)) & 0x30000;
  for ( i = 0; i < v3; ++i )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 48) + 4 * i);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int, CUtlMemory<ResourceEntryInfo,int> *))(*(_DWORD *)v5 + 184))(a1: v5, a2: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EC90
// Name: public: virtual unsigned int GFxButtonCharacter::GetCursorType(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::GetCursorType(CUtlMemory<ResourceEntryInfo,int> *this)
{
  tagPOLYTEXTW *v2; // edi
  CUtlMemory<ResourceEntryInfo,int> *v3; // ecx
  int v4; // esi
  GASValue vala[4]; // [esp+8h] [ebp-10h] BYREF

  v2 = (tagPOLYTEXTW *)((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[13].resData)(a1: this);
  LOBYTE(vala[0]) = 0;
  if ( v2 != nullptr && (*((_DWORD *)this + 40) & 0x10) != 0 )
  {
    if ( *((_DWORD *)this + 54) != 0 )
    {
      v3 = this + 10;
    }
    else
    {
      v4 = *((_DWORD *)this + 32);
      if ( v4 == 0 )
      {
LABEL_8:
        GASValue::ToBool(result: v2);
        goto LABEL_9;
      }
      v3 = (CUtlMemory<ResourceEntryInfo,int> *)(v4 + 16);
    }
    ((void (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *, tagPOLYTEXTW *, int, GASValue *))v3->m_pMemory[5].resData)(
      a1: v3,
      a2: &v2[3],
      a3: v2[3].x + 520,
      a4: vala);
    goto LABEL_8;
  }
LABEL_9:
  GASValue::~GASValue(this: vala);
}

//------------------------------------------------------------------------------
// Address: 0x1010ED20
// Name: public: virtual void GFxButtonCharacter::OnEventUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacter::OnEventUnload(GFxASCharacter *this)
{
  unsigned int v2; // eax
  int v3; // edi
  _BYTE *v4; // esi
  char v5; // al
  int v6; // esi
  GRefCountNTSImpl *v7; // ecx
  unsigned int i; // [esp+4h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < *(_DWORD *)(*((_DWORD *)this + 46) + 28); i = v2 )
  {
    v3 = 4 * v2;
    v4 = *(_BYTE **)(4 * v2 + *((_DWORD *)this + 48));
    if ( v4 != nullptr )
    {
      if ( (v4[118] >> 7 != 0 ? (unsigned int)v4 : 0) != 0 )
      {
        v5 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 140))(a1: v4);
        *((_WORD *)v4 + 59) |= 0x100u;
        if ( v5 != 0 )
          (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 136))(a1: v4);
      }
      v6 = *((_DWORD *)this + 48);
      v7 = *(GRefCountNTSImpl **)(v6 + v3);
      if ( v7 != nullptr )
        GRefCountNTSImpl::Release(this: v7);
      v2 = i;
      *(_DWORD *)(v6 + v3) = 0;
    }
    ++v2;
  }
  GFxASCharacter::OnEventUnload(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010EDD0
// Name: public: virtual bool GFxButtonCharacter::PointTestLocal(class GPoint<float> const __near &,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxButtonCharacter::PointTestLocal@<al>(int a1@<ecx>, int a2@<ebx>, float *hitTestMask, int a4)
{
  int v5; // eax
  float *v7; // ecx
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // [esp-4h] [ebp-44h]
  _BYTE v13[8]; // [esp+8h] [ebp-38h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v14; // [esp+10h] [ebp-30h] BYREF
  int v15; // [esp+1Ch] [ebp-24h]
  char v16; // [esp+23h] [ebp-1Dh]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v17; // [esp+24h] [ebp-1Ch] BYREF
  float v18; // [esp+38h] [ebp-8h]

  v5 = *(_DWORD *)(a1 + 160) >> 11;
  *(_DWORD *)&v14.nReferenceCount = hitTestMask;
  if ( (v5 & 1) != 0 )
    return 0;
  v12 = a2;
  v16 = a4 & 2;
  if ( (a4 & 2) != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)a1 + 16))(a1) == 0 )
    return 0;
  if ( (*(_BYTE *)(a1 + 118) & 1) == 0 )
  {
    GMatrix2D::SetIdentity(this: (float *)&v17);
    v7 = (float *)(*(int (__thiscall **)(int, _BYTE *, CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *))(*(_DWORD *)a1 + 52))(
                    a1,
                    a2: v13,
                    a3: &v17);
    if ( v7[2] < (double)*hitTestMask
      || *v7 > (double)*hitTestMask
      || v7[3] < (double)hitTestMask[1]
      || v7[1] > (double)hitTestMask[1] )
    {
      return 0;
    }
    if ( (a4 & 1) == 0 )
      return 1;
  }
  v8 = *(_DWORD *)(a1 + 184);
  v9 = 0;
  if ( *(_DWORD *)(v8 + 28) != 0 )
  {
    v15 = 0;
    while ( 1 )
    {
      v10 = v15 + *(_DWORD *)(v8 + 24);
      if ( *(_DWORD *)(v10 + 68) != 0x40000 && (*(_BYTE *)(v10 + 80) & 1) != 0 )
      {
        v11 = *(_DWORD *)(*(_DWORD *)(a1 + 192) + 4 * v9);
        if ( v11 != 0 && (v16 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 16))(a1: v11) != 0) )
        {
          v17.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v11 + 68);
          v17.m_Memory.m_nAllocationCount = *(int *)(v11 + 72);
          v17.m_Memory.m_nGrowSize = *(int *)(v11 + 76);
          v17.m_Size = *(int *)(v11 + 80);
          v17.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v11 + 84);
          v18 = *(float *)(v11 + 88);
          GMatrix2D::TransformByInverse(this: &v17, result: &v14, p: *(float **)&v14.nReferenceCount, p_4: v12);
          if ( (*(unsigned __int8 (__thiscall **)(int, CCountedStringPoolBase<unsigned int>::hash_item_t *, int))(*(_DWORD *)v11 + 68))(
                 a1: v11,
                 a2: &v14,
                 a3: a4) != 0 )
            break;
        }
      }
      v8 = *(_DWORD *)(a1 + 184);
      v15 += 84;
      if ( (unsigned int)++v9 >= *(_DWORD *)(v8 + 28) )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010EF70
// Name: public: virtual class GFxASCharacter __near * GFxButtonCharacter::GetTopMostMouseEntity(class GPoint<float> const __near &,struct GFxCharacter::TopMostParams const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *__thiscall GFxButtonCharacter::GetTopMostMouseEntity(
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *this,
        CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result,
        _DWORD *a3)
{
  int Perspective3D; // edi
  int View3D; // ebx
  int v6; // eax
  int v7; // eax
  unsigned int v8; // ebx
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v15; // [esp+0h] [ebp-A4h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v16; // [esp+Ch] [ebp-98h] BYREF
  float v17[2]; // [esp+1Ch] [ebp-88h] BYREF
  int v18; // [esp+24h] [ebp-80h]
  unsigned int i; // [esp+28h] [ebp-7Ch]
  int v20; // [esp+2Ch] [ebp-78h]
  GMatrix3D pmat; // [esp+30h] [ebp-74h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v22; // [esp+70h] [ebp-34h] BYREF
  float v23; // [esp+84h] [ebp-20h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v24; // [esp+88h] [ebp-1Ch] BYREF
  float v25; // [esp+9Ch] [ebp-8h]

  if ( (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 16))(a1: this) == 0
    || (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)a3[1] == this
    || (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *, _DWORD, _DWORD))(LODWORD(this->m_pfnProxied) + 196))(
         a1: this,
         a2: *a3,
         a3: a3[2]) == 0 )
  {
    return nullptr;
  }
  v22.m_Memory.m_pMemory = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)this + 17);
  v22.m_Memory.m_nAllocationCount = *((int *)this + 18);
  v22.m_Memory.m_nGrowSize = *((int *)this + 19);
  v22.m_Size = *((int *)this + 20);
  v22.m_pElements = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)this + 21);
  v23 = *((float *)this + 22);
  if ( GFxCharacter::Is3D(
         this,
         result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
  {
    Perspective3D = GFxCharacter::GetPerspective3D(this, checkAncestors: true);
    View3D = GFxCharacter::GetView3D(this, checkAncestors: true);
    if ( Perspective3D != 0 )
      *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this)
                + 224) = Perspective3D;
    if ( View3D != 0 )
      *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this)
                + 228) = View3D;
    GMatrix3D::SetIdentity(this: &pmat);
    GFxCharacter::GetWorldMatrix3D(this, (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
    *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this)
              + 232) = &pmat;
    v6 = (*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *, unsigned __int8 *))(LODWORD(this->m_pfnProxied) + 84))(
           a1: this,
           a2: &v16.nReferenceCount);
    GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v6 + 208));
  }
  else
  {
    GMatrix2D::TransformByInverse(
      this: &v22,
      result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v16.nReferenceCount,
      p: (float *)result,
      p_4: v15);
  }
  v7 = *((_DWORD *)this + 46);
  v8 = 0;
  i = 0;
  if ( *(_DWORD *)(v7 + 28) == 0 )
    return nullptr;
  v20 = 0;
  while ( 1 )
  {
    v9 = v20 + *(_DWORD *)(v7 + 24);
    if ( *(_DWORD *)(v9 + 68) != 0x40000 && (*(_BYTE *)(v9 + 80) & 1) != 0 && v8 < *((_DWORD *)this + 49) )
    {
      v10 = *(_DWORD *)(*((_DWORD *)this + 48) + 4 * v8);
      if ( v10 != 0 )
      {
        v24.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v10 + 68);
        v24.m_Memory.m_nAllocationCount = *(int *)(v10 + 72);
        v24.m_Memory.m_nGrowSize = *(int *)(v10 + 76);
        v24.m_Size = *(int *)(v10 + 80);
        v24.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v10 + 84);
        v25 = *(float *)(v10 + 88);
        if ( GFxCharacter::Is3D(
               this: (_DWORD *)v10,
               result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
        {
          v11 = GFxCharacter::GetPerspective3D(this: (_DWORD *)v10, checkAncestors: true);
          v18 = GFxCharacter::GetView3D(this: (_DWORD *)v10, checkAncestors: true);
          if ( v11 != 0 )
            *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this)
                      + 224) = v11;
          if ( v18 != 0 )
          {
            v12 = (*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this);
            *(_DWORD *)(v12 + 228) = v18;
          }
          GMatrix3D::SetIdentity(this: &pmat);
          GFxCharacter::GetWorldMatrix3D(
            this: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v10,
            (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
          *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this)
                    + 232) = &pmat;
          v13 = (*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *, float *))(LODWORD(this->m_pfnProxied) + 84))(
                  a1: this,
                  a2: v17);
          GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v13 + 208));
          v8 = i;
        }
        else
        {
          GMatrix2D::TransformByInverse(this: &v24, result: &v16, p: (float *)&v16.nReferenceCount, p_4: v15);
          v17[0] = *(float *)&v16.pString;
          v17[1] = *(float *)&v16.nNextElement;
        }
        if ( (*(unsigned __int8 (__thiscall **)(int, float *, int))(*(_DWORD *)v10 + 68))(a1: v10, a2: v17, a3: 1) != 0 )
          break;
      }
    }
    v7 = *((_DWORD *)this + 46);
    v20 += 84;
    i = ++v8;
    if ( v8 >= *(_DWORD *)(v7 + 28) )
      return nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010F220
// Name: public: virtual class GRect<float> GFxButtonCharacter::GetBoundsOfRecord(class GMatrix2D const __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxButtonCharacter::GetBoundsOfRecord(_DWORD *this, float *a2, float *a3, unsigned int recNumber)
{
  int v5; // eax
  int v6; // ecx
  float *v7; // eax
  _BYTE v9[16]; // [esp+Ch] [ebp-38h] BYREF
  float v10; // [esp+1Ch] [ebp-28h]
  float v11; // [esp+20h] [ebp-24h]
  float v12; // [esp+24h] [ebp-20h]
  GMatrix2D v13; // [esp+28h] [ebp-1Ch] BYREF

  *a2 = 0.0;
  a2[1] = 0.0;
  a2[2] = 0.0;
  a2[3] = 0.0;
  v12 = *(float *)&recNumber;
  GMatrix2D::SetIdentity(this: (float *)&v13);
  v5 = *(this + 48) + 4 * recNumber;
  if ( *(_DWORD *)v5 != 0 )
  {
    v13.M_[0][0] = *a3;
    v13.M_[0][1] = a3[1];
    v13.M_[0][2] = a3[2];
    v13.M_[1][0] = a3[3];
    v13.M_[1][1] = a3[4];
    v13.M_[1][2] = a3[5];
    GMatrix2D::Prepend(this: &v13, a2: (const struct GMatrix2D *)(*(_DWORD *)v5 + 68));
    v6 = *(_DWORD *)(*(this + 48) + 4 * LODWORD(v12));
    v7 = (float *)(*(int (__thiscall **)(int, _BYTE *, GMatrix2D *))(*(_DWORD *)v6 + 52))(a1: v6, a2: v9, a3: &v13);
    v12 = v7[1];
    v10 = v7[2];
    v11 = v7[3];
    *a2 = *v7;
    a2[1] = v12;
    a2[2] = v10;
    a2[3] = v11;
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1010F3E0
// Name: public: virtual class GRect<float> GFxButtonCharacter::GetFocusRect(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxButtonCharacter::GetFocusRect(void *this, float *a2)
{
  int v3; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _BYTE v12[16]; // [esp+8h] [ebp-3Ch] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> tempRect; // [esp+18h] [ebp-2Ch]
  float v14; // [esp+24h] [ebp-20h]
  float v15[6]; // [esp+28h] [ebp-1Ch] BYREF

  GMatrix2D::SetIdentity(this: v15);
  v3 = (*(int (__thiscall **)(void *, _BYTE *, float *, int))(*(_DWORD *)this + 356))(a1: this, a2: v12, a3: v15, a4: 3);
  tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v3;
  tempRect.m_nAllocationCount = *(int *)(v3 + 4);
  tempRect.m_nGrowSize = *(int *)(v3 + 8);
  v14 = *(float *)(v3 + 12);
  v4 = *(float *)&tempRect.m_nGrowSize;
  v5 = *(float *)&tempRect.m_pMemory;
  v6 = v14;
  v7 = *(float *)&tempRect.m_nAllocationCount;
  if ( *(float *)&tempRect.m_pMemory != *(float *)&tempRect.m_nGrowSize )
    goto LABEL_3;
  if ( v7 != v6 )
    goto LABEL_3;
  v9 = (*(int (__thiscall **)(void *, _BYTE *, float *, int))(*(_DWORD *)this + 356))(a1: this, a2: v12, a3: v15, a4: 2);
  tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v9;
  tempRect.m_nAllocationCount = *(int *)(v9 + 4);
  tempRect.m_nGrowSize = *(int *)(v9 + 8);
  v14 = *(float *)(v9 + 12);
  v4 = *(float *)&tempRect.m_nGrowSize;
  v5 = *(float *)&tempRect.m_pMemory;
  v6 = v14;
  v7 = *(float *)&tempRect.m_nAllocationCount;
  if ( *(float *)&tempRect.m_pMemory != *(float *)&tempRect.m_nGrowSize )
    goto LABEL_3;
  if ( v7 != v6 )
    goto LABEL_3;
  v10 = (*(int (__thiscall **)(void *, _BYTE *, float *, int))(*(_DWORD *)this + 356))(
          a1: this,
          a2: v12,
          a3: v15,
          a4: 1);
  tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v10;
  tempRect.m_nAllocationCount = *(int *)(v10 + 4);
  tempRect.m_nGrowSize = *(int *)(v10 + 8);
  v14 = *(float *)(v10 + 12);
  v4 = *(float *)&tempRect.m_nGrowSize;
  v5 = *(float *)&tempRect.m_pMemory;
  v6 = v14;
  v7 = *(float *)&tempRect.m_nAllocationCount;
  if ( *(float *)&tempRect.m_pMemory != *(float *)&tempRect.m_nGrowSize )
    goto LABEL_3;
  if ( v7 != v6 )
    goto LABEL_3;
  v11 = (*(int (__thiscall **)(void *, _BYTE *, float *, _DWORD))(*(_DWORD *)this + 356))(
          a1: this,
          a2: v12,
          a3: v15,
          a4: 0);
  tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v11;
  tempRect.m_nAllocationCount = *(int *)(v11 + 4);
  tempRect.m_nGrowSize = *(int *)(v11 + 8);
  v14 = *(float *)(v11 + 12);
  v4 = *(float *)&tempRect.m_nGrowSize;
  v5 = *(float *)&tempRect.m_pMemory;
  v6 = v14;
  v7 = *(float *)&tempRect.m_nAllocationCount;
  if ( *(float *)&tempRect.m_pMemory != *(float *)&tempRect.m_nGrowSize )
    goto LABEL_3;
  if ( v7 == v6 )
  {
    (*(void (__thiscall **)(void *, float *, float *))(*(_DWORD *)this + 52))(a1: this, a2, a3: v15);
    return a2;
  }
  else
  {
LABEL_3:
    *a2 = v5;
    a2[1] = v7;
    a2[2] = v4;
    a2[3] = v6;
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F5D0
// Name: public: virtual void GFxButtonCharacter::OnGettingKeyboardFocus(unsigned int)
// Source: json
//------------------------------------------------------------------------------
ResourceEntryInfo *__thiscall GFxButtonCharacter::OnGettingKeyboardFocus(
        CUtlMemory<ResourceEntryInfo,int> *this,
        unsigned int __formal)
{
  ResourceEntryInfo *result; // eax
  ResourceEntryInfo *(__thiscall *eType)(CUtlMemory<ResourceEntryInfo,int> *, _DWORD *); // edx
  _DWORD v5[2]; // [esp+4h] [ebp-10h] BYREF
  __int16 v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+Eh] [ebp-6h]

  result = (ResourceEntryInfo *)((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[10].resData)(a1: this);
  if ( result != nullptr )
  {
    result = (ResourceEntryInfo *)((result[1166].resData >> 28) & 3);
    if ( result != (ResourceEntryInfo *)1 )
    {
      eType = (ResourceEntryInfo *(__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *, _DWORD *))this->m_pMemory[33].eType;
      v6 = 0;
      v5[1] = 0;
      v5[0] = 0x2000;
      v7 = 65280;
      return eType(a1: this, a2: v5);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F630
// Name: public: virtual bool GFxButtonCharacter::OnLosingKeyboardFocus(class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxButtonCharacter::OnLosingKeyboardFocus(void *this, int a2, int a3, int a4)
{
  int v5; // eax
  void (__thiscall *v6)(void *, _DWORD *); // edx
  _DWORD v8[2]; // [esp+4h] [ebp-10h] BYREF
  __int16 v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+Eh] [ebp-6h]

  v5 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 84))(a1: this);
  if ( *(_BYTE *)(52 * *(unsigned __int8 *)(v5 + a3 + 10228) + v5 + 9440) != 0
    && ((*(_DWORD *)(v5 + 9332) >> 28) & 3) != 1 )
  {
    v6 = *(void (__thiscall **)(void *, _DWORD *))(*(_DWORD *)this + 264);
    v9 = 0;
    v8[1] = 0;
    v8[0] = 0x4000;
    v10 = 65280;
    v6(a1: this, a2: v8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010F6A0
// Name: public: virtual class GRect<float> GFxButtonCharacter::GetBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
const CUtlMemory<ResourceEntryInfo,int>::Iterator_t *__thiscall GFxButtonCharacter::GetBounds(
        CUtlMemory<ResourceEntryInfo,int> *this,
        const CUtlMemory<ResourceEntryInfo,int>::Iterator_t *transform,
        int a3)
{
  int v5; // eax
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  double v10; // st7
  double v11; // st5
  double v12; // rt0
  double v13; // st4
  double v14; // st6
  double v15; // st7
  double v16; // st5
  _BYTE v18[16]; // [esp+Ch] [ebp-34h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> tempRect; // [esp+1Ch] [ebp-24h]
  float v20; // [esp+28h] [ebp-18h]
  float v21; // [esp+2Ch] [ebp-14h]
  float v22; // [esp+30h] [ebp-10h]
  float v23; // [esp+34h] [ebp-Ch]
  float v24; // [esp+38h] [ebp-8h]
  int v25; // [esp+3Ch] [ebp-4h]
  bool boundsInit; // [esp+4Bh] [ebp+Bh]

  *(float *)transform = 0.0;
  *((float *)transform + 1) = 0.0;
  v5 = *((_DWORD *)this + 46);
  *((float *)transform + 2) = 0.0;
  v6 = 0;
  *((float *)transform + 3) = 0.0;
  boundsInit = false;
  if ( *(_DWORD *)(v5 + 28) != 0 )
  {
    v25 = 0;
    do
    {
      v7 = *((_DWORD *)this + 53);
      v8 = v25 + *(_DWORD *)(v5 + 24);
      if ( v7 != 0 )
      {
        if ( v7 == 1 )
        {
          if ( (*(_BYTE *)(v8 + 80) & 2) != 0 )
            goto LABEL_11;
        }
        else if ( v7 == 2 && (*(_BYTE *)(v8 + 80) & 4) != 0 )
        {
LABEL_11:
          v9 = ((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *, _BYTE *, int, unsigned int))this->m_pMemory[44].eType)(
                 a1: this,
                 a2: v18,
                 a3,
                 a4: v6);
          tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v9;
          tempRect.m_nAllocationCount = *(int *)(v9 + 4);
          tempRect.m_nGrowSize = *(int *)(v9 + 8);
          v20 = *(float *)(v9 + 12);
          v10 = *(float *)&tempRect.m_nGrowSize;
          v11 = v20;
          if ( *(float *)&tempRect.m_pMemory != *(float *)&tempRect.m_nGrowSize
            || *(float *)&tempRect.m_nAllocationCount != v11 )
          {
            if ( boundsInit )
            {
              if ( *(float *)transform <= (double)*(float *)&tempRect.m_pMemory )
              {
                v14 = *(float *)&tempRect.m_nAllocationCount;
                v13 = *(float *)transform;
              }
              else
              {
                v13 = *(float *)&tempRect.m_pMemory;
                v14 = *(float *)&tempRect.m_nAllocationCount;
              }
              v21 = v13;
              if ( *((float *)transform + 2) <= v10 )
              {
                v16 = *(float *)&tempRect.m_nGrowSize;
                v15 = v20;
              }
              else
              {
                v15 = v20;
                v16 = *((float *)transform + 2);
              }
              v23 = v16;
              if ( *((float *)transform + 1) <= v14 )
                v14 = *((float *)transform + 1);
              v22 = v14;
              if ( *((float *)transform + 3) > v15 )
                v15 = *((float *)transform + 3);
              v24 = v15;
              *(float *)transform = v21;
              *((float *)transform + 1) = v22;
              *((float *)transform + 2) = v23;
              *((float *)transform + 3) = v24;
            }
            else
            {
              v12 = *(float *)&tempRect.m_nAllocationCount;
              boundsInit = true;
              *(float *)transform = *(float *)&tempRect.m_pMemory;
              *((float *)transform + 1) = v12;
              *((float *)transform + 2) = v10;
              *((float *)transform + 3) = v11;
            }
          }
        }
      }
      else if ( (*(_BYTE *)(v8 + 80) & 8) != 0 )
      {
        goto LABEL_11;
      }
      v5 = *((_DWORD *)this + 46);
      v25 += 84;
      ++v6;
    }
    while ( v6 < *(_DWORD *)(v5 + 28) );
  }
  return transform;
}

//------------------------------------------------------------------------------
// Address: 0x1010F820
// Name: public: virtual class GRect<float> GFxButtonCharacter::GetRectBounds(class GMatrix2D const __near &)const
// Source: rtti_class
//------------------------------------------------------------------------------
const CUtlMemory<ResourceEntryInfo,int>::Iterator_t *__thiscall GFxButtonCharacter::GetRectBounds(
        CUtlMemory<ResourceEntryInfo,int> *this,
        const CUtlMemory<ResourceEntryInfo,int>::Iterator_t *transform,
        int a3)
{
  int v5; // eax
  unsigned int v6; // edi
  int RectBounds; // eax
  double v8; // st7
  double v9; // st5
  double v10; // rt0
  double v11; // st4
  double v12; // st6
  double v13; // st7
  double v14; // st5
  _BYTE v16[16]; // [esp+Ch] [ebp-30h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> tempRect; // [esp+1Ch] [ebp-20h]
  float v18; // [esp+28h] [ebp-14h]
  float v19; // [esp+2Ch] [ebp-10h]
  float v20; // [esp+30h] [ebp-Ch]
  float v21; // [esp+34h] [ebp-8h]
  float v22; // [esp+38h] [ebp-4h]
  bool boundsInit; // [esp+47h] [ebp+Bh]

  *(float *)transform = 0.0;
  v5 = *((_DWORD *)this + 46);
  *((float *)transform + 1) = 0.0;
  *((float *)transform + 2) = 0.0;
  v6 = 0;
  *((float *)transform + 3) = 0.0;
  boundsInit = false;
  if ( *(_DWORD *)(v5 + 28) != 0 )
  {
    do
    {
      RectBounds = GFxButtonCharacter::GetRectBounds(a1: this, a2: v16, a3, a4: v6);
      tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)RectBounds;
      tempRect.m_nAllocationCount = *(int *)(RectBounds + 4);
      tempRect.m_nGrowSize = *(int *)(RectBounds + 8);
      v18 = *(float *)(RectBounds + 12);
      v8 = *(float *)&tempRect.m_nGrowSize;
      v9 = v18;
      if ( *(float *)&tempRect.m_pMemory != *(float *)&tempRect.m_nGrowSize
        || *(float *)&tempRect.m_nAllocationCount != v9 )
      {
        if ( boundsInit )
        {
          if ( *(float *)transform <= (double)*(float *)&tempRect.m_pMemory )
          {
            v12 = *(float *)&tempRect.m_nAllocationCount;
            v11 = *(float *)transform;
          }
          else
          {
            v11 = *(float *)&tempRect.m_pMemory;
            v12 = *(float *)&tempRect.m_nAllocationCount;
          }
          v19 = v11;
          if ( *((float *)transform + 2) <= v8 )
          {
            v14 = *(float *)&tempRect.m_nGrowSize;
            v13 = v18;
          }
          else
          {
            v13 = v18;
            v14 = *((float *)transform + 2);
          }
          v21 = v14;
          if ( *((float *)transform + 1) <= v12 )
            v12 = *((float *)transform + 1);
          v20 = v12;
          if ( *((float *)transform + 3) > v13 )
            v13 = *((float *)transform + 3);
          v22 = v13;
          *(float *)transform = v19;
          *((float *)transform + 1) = v20;
          *((float *)transform + 2) = v21;
          *((float *)transform + 3) = v22;
        }
        else
        {
          v10 = *(float *)&tempRect.m_nAllocationCount;
          boundsInit = true;
          *(float *)transform = *(float *)&tempRect.m_pMemory;
          *((float *)transform + 1) = v10;
          *((float *)transform + 2) = v8;
          *((float *)transform + 3) = v9;
        }
      }
      ++v6;
    }
    while ( v6 < *(_DWORD *)(*((_DWORD *)this + 46) + 28) );
  }
  return transform;
}

//------------------------------------------------------------------------------
// Address: 0x1010F960
// Name: public: virtual class GRect<float> GFxButtonCharacter::GetBoundsOfState(class GMatrix2D const __near &,enum GFxButtonCharacter::ButtonState)const
// Source: json
//------------------------------------------------------------------------------
const ResourceEntryInfo *__thiscall GFxButtonCharacter::GetBoundsOfState(
        CUtlMemory<ResourceEntryInfo,int> *this,
        float *transform,
        int a3,
        int a4)
{
  int v6; // eax
  unsigned int v7; // ebx
  int v8; // eax
  int v9; // eax
  double v10; // st7
  double v11; // st5
  double v12; // rt0
  double v13; // st4
  double v14; // st6
  double v15; // st7
  double v16; // st5
  _BYTE v18[16]; // [esp+Ch] [ebp-30h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> tempRect; // [esp+1Ch] [ebp-20h]
  float v20; // [esp+28h] [ebp-14h]
  float v21; // [esp+2Ch] [ebp-10h]
  float v22; // [esp+30h] [ebp-Ch]
  float v23; // [esp+34h] [ebp-8h]
  float v24; // [esp+38h] [ebp-4h]
  int transforma; // [esp+44h] [ebp+8h]

  *transform = 0.0;
  transform[1] = 0.0;
  v6 = *((_DWORD *)this + 46);
  transform[2] = 0.0;
  v7 = 0;
  transform[3] = 0.0;
  if ( *(_DWORD *)(v6 + 28) != 0 )
  {
    transforma = 0;
    do
    {
      v8 = transforma + *(_DWORD *)(v6 + 24);
      switch ( a4 )
      {
        case 3:
          if ( (*(_BYTE *)(v8 + 80) & 1) != 0 )
            goto LABEL_14;
          break;
        case 2:
          if ( (*(_BYTE *)(v8 + 80) & 2) != 0 )
            goto LABEL_14;
          break;
        case 1:
          if ( (*(_BYTE *)(v8 + 80) & 4) != 0 )
            goto LABEL_14;
          break;
        default:
          if ( a4 == 0 && (*(_BYTE *)(v8 + 80) & 8) != 0 )
          {
LABEL_14:
            v9 = ((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *, _BYTE *, int, unsigned int))this->m_pMemory[44].eType)(
                   a1: this,
                   a2: v18,
                   a3,
                   a4: v7);
            tempRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v9;
            tempRect.m_nAllocationCount = *(int *)(v9 + 4);
            tempRect.m_nGrowSize = *(int *)(v9 + 8);
            v20 = *(float *)(v9 + 12);
            v10 = *(float *)&tempRect.m_nGrowSize;
            v11 = v20;
            if ( *(float *)&tempRect.m_pMemory != *(float *)&tempRect.m_nGrowSize
              || *(float *)&tempRect.m_nAllocationCount != v11 )
            {
              if ( *transform == transform[2] && transform[1] == transform[3] )
              {
                v12 = *(float *)&tempRect.m_nAllocationCount;
                *transform = *(float *)&tempRect.m_pMemory;
                transform[1] = v12;
                transform[2] = v10;
                transform[3] = v11;
              }
              else
              {
                if ( *transform <= (double)*(float *)&tempRect.m_pMemory )
                {
                  v14 = *(float *)&tempRect.m_nAllocationCount;
                  v13 = *transform;
                }
                else
                {
                  v13 = *(float *)&tempRect.m_pMemory;
                  v14 = *(float *)&tempRect.m_nAllocationCount;
                }
                v21 = v13;
                if ( transform[2] <= v10 )
                {
                  v16 = *(float *)&tempRect.m_nGrowSize;
                  v15 = v20;
                }
                else
                {
                  v15 = v20;
                  v16 = transform[2];
                }
                v23 = v16;
                if ( transform[1] <= v14 )
                  v14 = transform[1];
                v22 = v14;
                if ( transform[3] > v15 )
                  v15 = transform[3];
                v24 = v15;
                *transform = v21;
                transform[1] = v22;
                transform[2] = v23;
                transform[3] = v24;
              }
            }
          }
          break;
      }
      v6 = *((_DWORD *)this + 46);
      transforma += 84;
      ++v7;
    }
    while ( v7 < *(_DWORD *)(v6 + 28) );
  }
  return (const ResourceEntryInfo *)transform;
}

//------------------------------------------------------------------------------
// Address: 0x1010FB00
// Name: public: virtual bool GFxButtonCharacter::OnKeyEvent(class GFxEventId const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxButtonCharacter::OnKeyEvent(GRefCountNTSImpl *this, ISteamRemoteStorage *a2, int *a3)
{
  int v4; // eax
  int v6; // ebx
  ISteamRemoteStorage_vtbl *v7; // eax
  const GPoint3<float> *inserted; // ebx
  ISteamRemoteStorage_vtbl *v9; // ecx
  ISteamRemoteStorage_vtbl *v10; // eax
  ISteamRemoteStorage_vtbl *v11; // edx
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  ISteamRemoteStorage_vtbl *v14; // eax
  float v15; // ecx
  float v16; // edx
  float v17; // eax
  char v18; // dl
  GRefCountNTSImpl_vtbl *v19; // eax
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountNTSImpl *); // edx
  __int16 v21; // ax
  char v22; // dl
  GRefCountNTSImpl_vtbl *v23; // eax
  void (__thiscall *v24)(struct GRefCountNTSImpl *); // edx
  char v25; // cl
  void (__thiscall *v26)(struct GRefCountNTSImpl *); // edx
  unsigned __int64 v29; // [esp+14h] [ebp-6Ch]
  unsigned __int64 v30; // [esp+14h] [ebp-6Ch]
  void *v31; // [esp+1Ch] [ebp-64h]
  int v32; // [esp+20h] [ebp-60h]
  GASValue v33[4]; // [esp+28h] [ebp-58h] BYREF
  _DWORD v34[2]; // [esp+38h] [ebp-48h] BYREF
  __int16 v35; // [esp+40h] [ebp-40h]
  char v36; // [esp+42h] [ebp-3Eh]
  char v37; // [esp+43h] [ebp-3Dh]
  __int16 v38; // [esp+44h] [ebp-3Ch]
  _DWORD v39[2]; // [esp+48h] [ebp-38h] BYREF
  __int16 v40; // [esp+50h] [ebp-30h]
  char v41; // [esp+52h] [ebp-2Eh]
  char v42; // [esp+53h] [ebp-2Dh]
  __int16 v43; // [esp+54h] [ebp-2Ch]
  _DWORD v44[2]; // [esp+58h] [ebp-28h] BYREF
  __int16 v45; // [esp+60h] [ebp-20h]
  char v46; // [esp+62h] [ebp-1Eh]
  char v47; // [esp+63h] [ebp-1Dh]
  __int16 v48; // [esp+64h] [ebp-1Ch]
  ISteamRemoteStorage_vtbl *v49; // [esp+68h] [ebp-18h]
  ISteamRemoteStorage_vtbl *v50; // [esp+6Ch] [ebp-14h]
  ISteamRemoteStorage_vtbl *v51; // [esp+70h] [ebp-10h]
  ISteamRemoteStorage_vtbl *v52; // [esp+74h] [ebp-Ch]
  int v53; // [esp+78h] [ebp-8h]
  int v54; // [esp+7Ch] [ebp-4h] BYREF
  ISteamRemoteStorage *v55; // [esp+88h] [ebp+8h]

  v4 = ((int (__thiscall *)(GRefCountNTSImpl *))this->__vftable[28].dtr_GRefCountImplCore)(a1: this);
  v6 = v4 + 120;
  v53 = v4;
  GFxEventId::GetFunctionName(this: (unsigned int *)a2, a2: &v54, psc: (_DWORD *)(v4 + 120));
  v55 = (ISteamRemoteStorage *)((int (__thiscall *)(GRefCountNTSImpl *))this->__vftable[21].dtr_GRefCountImplCore)(a1: this);
  if ( *(_DWORD *)(v54 + 16) != 0 )
  {
    v7 = a2->__vftable;
    LOBYTE(v33[0]) = 0;
    if ( (v7 == (ISteamRemoteStorage_vtbl *)64 || v7 == (ISteamRemoteStorage_vtbl *)128)
      && (*(unsigned __int8 (__thiscall **)(GRefCountNTSImpl *, int, int *, GASValue *))(*((_DWORD *)this + 30) + 44))(
           a1: this + 15,
           a2: v6,
           a3: &v54,
           a4: v33) != 0
      && *(_BYTE *)(v53 + 124) >= 6u )
    {
      HIDWORD(v29) = SHIBYTE(a2[2].__vftable);
      LODWORD(v29) = this;
      if ( GFxMovieRoot::IsKeyboardFocused(this: v55, ch: v29, controllerIdx: v31, a4: v32) )
      {
        inserted = GFxMovieRoot::ActionQueueType::InsertEntry(this: (int)&v55[2306], result: (const GPoint3<float> *)4);
        if ( inserted != nullptr )
        {
          v9 = a2[2].__vftable;
          v10 = a2[1].__vftable;
          v49 = a2->__vftable;
          v11 = a2[3].__vftable;
          LODWORD(inserted->y) = 2;
          ++this->RefCount;
          v51 = v9;
          z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
          v50 = v10;
          v52 = v11;
          if ( z_low != nullptr )
            GRefCountNTSImpl::Release(this: z_low);
          LODWORD(inserted->z) = this;
          x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
          if ( x_low != nullptr )
            GRefCountNTSImpl::Release(this: x_low);
          v14 = v49;
          v15 = *(float *)&v50;
          v16 = *(float *)&v51;
          inserted[1].x = 0.0;
          LODWORD(inserted[1].y) = v14;
          v17 = *(float *)&v52;
          inserted[1].z = v15;
          inserted[2].x = v16;
          inserted[2].y = v17;
        }
      }
    }
    GASValue::~GASValue(this: v33);
  }
  if ( a2->__vftable == (ISteamRemoteStorage_vtbl *)64 )
  {
    if ( (*a3 & 0x10000) == 0 )
    {
      v18 = BYTE2(a2[2].__vftable);
      v19 = this->__vftable;
      v45 = (__int16)a2[2].__vftable;
      v46 = v18;
      dtr_GRefCountImplCore = v19[66].dtr_GRefCountImplCore;
      v44[0] = 0x20000;
      v44[1] = 0;
      v48 = 0;
      v47 = 0;
      if ( ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *, _DWORD *))dtr_GRefCountImplCore)(a1: this, a2: v44) != 0 )
        *a3 |= 0x10000u;
    }
    HIDWORD(v30) = SHIBYTE(a2[2].__vftable);
    LODWORD(v30) = this;
    if ( GFxMovieRoot::IsKeyboardFocused(this: v55, ch: v30, controllerIdx: v31, a4: v32) )
    {
      v21 = (__int16)a2[2].__vftable;
      if ( (v21 == 13 || v21 == 32)
        && (((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *))this->__vftable[54].dtr_GRefCountImplCore)(a1: this) != 0
         || (((unsigned int)v55[2333].__vftable >> 26) & 3) == 1) )
      {
        v22 = HIBYTE(a2[2].__vftable);
        v23 = this->__vftable;
        v40 = 13;
        v42 = v22;
        v24 = v23[66].dtr_GRefCountImplCore;
        v39[0] = 1024;
        v39[1] = 0;
        v41 = 0;
        v43 = 0;
        ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD *))v24)(a1: this, a2: v39);
        ++this->RefCount;
        ((void (__thiscall *)(ISteamRemoteStorage *, _DWORD, _DWORD))v55->__vftable[1].IsCloudEnabledForApp)(
          a1: v55,
          a2: 0.0,
          a3: 0);
        v25 = HIBYTE(a2[2].__vftable);
        v26 = this->__vftable[66].dtr_GRefCountImplCore;
        v35 = 13;
        v37 = v25;
        v34[0] = 2048;
        v34[1] = 0;
        v36 = 0;
        v38 = 0;
        ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD *))v26)(a1: this, a2: v34);
        GRefCountNTSImpl::Release(this);
      }
    }
  }
  if ( (*(_DWORD *)(v54 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010FD60
// Name: public: GASButtonObject::GASButtonObject(class GASGlobalContext __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
GASButtonObject *__thiscall GASButtonObject::GASButtonObject(
        GASButtonObject *this,
        _KCRM_MARSHAL_HEADER *gCtxt,
        GRefCountWeakSupportImpl *a3)
{
  _EVENTLOGRECORD *GC; // eax
  struct GWeakPtrProxy *WeakProxy; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v6; // eax

  GC = (_EVENTLOGRECORD *)GASGlobalContext::GetGC(this: (GASGlobalContext *)gCtxt);
  GASObject::GASObject(result: GC);
  *(_DWORD *)this = &GASButtonObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASButtonObject::`vftable'{for `GASObjectInterface'};
  if ( a3 != nullptr )
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: a3);
  else
    WeakProxy = nullptr;
  *((_DWORD *)this + 13) = WeakProxy;
  v6 = (CTSQueue<CFunctor *,0,1>::Node_t *)((int (__thiscall *)(GRefCountWeakSupportImpl *))a3->__vftable[28].dtr_GRefCountImplCore)(a1: a3);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16),
    psc: v6 + 15,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)a3[10].pWeakProxy);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010FDC0
// Name: public: virtual void GFxButtonCharacter::Display(class GFxDisplayContext __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge GFxButtonCharacter::Display(
        CUtlMemory<ResourceEntryInfo,int> *this@<ecx>,
        int a2@<edi>,
        int *context,
        int psave)
{
  CUtlMemory<ResourceEntryInfo,int> *v4; // ebx
  bool v5; // zf
  int v6; // eax
  _RATE_QUOTA_LIMIT *v7; // ecx
  int (__thiscall *resData)(CUtlMemory<ResourceEntryInfo,int> *); // eax
  int v9; // edi
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int m_nAllocationCount; // eax
  unsigned int v17; // ecx
  int v18; // eax
  int v19; // edi
  int m_nGrowSize; // edx
  void (__thiscall **v21)(int, int); // ebx
  int v22; // eax
  char v23; // al
  bool v24; // bl
  void (__thiscall ***v25)(_DWORD, int); // esi
  CUtlVector<void *,CUtlMemory<void *,int> > oldFilters; // [esp+8h] [ebp-E0h] BYREF
  float v28; // [esp+1Ch] [ebp-CCh]
  float v29; // [esp+20h] [ebp-C8h]
  int v30; // [esp+34h] [ebp-B4h]
  int oldXform; // [esp+38h] [ebp-B0h] OVERLAPPED BYREF
  int v32; // [esp+3Ch] [ebp-ACh]
  int v33; // [esp+40h] [ebp-A8h]
  int v34; // [esp+44h] [ebp-A4h]
  int v35; // [esp+48h] [ebp-A0h]
  char v36; // [esp+4Ch] [ebp-9Ch]
  _RATE_QUOTA_LIMIT *psavea; // [esp+50h] [ebp-98h]
  CUtlMemory<ResourceEntryInfo,int> *v38; // [esp+54h] [ebp-94h]
  unsigned int i; // [esp+58h] [ebp-90h]
  int v40; // [esp+5Ch] [ebp-8Ch]
  int v41; // [esp+60h] [ebp-88h]
  int v42; // [esp+64h] [ebp-84h]
  bool useFilters; // [esp+6Bh] [ebp-7Dh]
  GMatrix3D v44; // [esp+6Ch] [ebp-7Ch] BYREF
  struct GRenderer::Cxform v45; // [esp+ACh] [ebp-3Ch] BYREF
  GMatrix2D v46; // [esp+CCh] [ebp-1Ch] BYREF

  v4 = this;
  v5 = *(_DWORD *)(*((_DWORD *)this + 46) + 28) == 0;
  v38 = this;
  if ( !v5 )
  {
    v6 = *(_DWORD *)(*((_DWORD *)this + 36) + 28);
    v7 = (_RATE_QUOTA_LIMIT *)context[28];
    context[28] = v6 + 24;
    resData = (int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))v4->m_pMemory[10].resData;
    psavea = v7;
    v9 = resData(a1: v4);
    if ( v9 != 0 )
    {
      v10 = *(_DWORD *)(context[18] + 12);
      *(float *)&oldFilters.m_Size = 0.0;
      v11 = context[1];
      *(float *)&oldFilters.m_pElements = 0.0;
      v41 = v10;
      v28 = 0.0;
      v12 = context[2];
      v29 = 0.0;
      LOBYTE(oldFilters.m_Memory.m_pMemory) = 0;
      v30 = 0;
      oldFilters.m_Memory.m_nGrowSize = 0;
      oldFilters.m_Memory.m_nAllocationCount = 0;
      v13 = *context;
      v32 = v11;
      v14 = context[4];
      oldXform = v13;
      v15 = context[3];
      v33 = v12;
      LOBYTE(v12) = *((_BYTE *)context + 20);
      v35 = v14;
      v34 = v15;
      v36 = v12;
      GRenderer::Cxform::Cxform(this: (float *)&v45);
      GMatrix2D::SetIdentity(this: (float *)&v46);
      GMatrix3D::SetIdentity(this: &v44);
      m_nAllocationCount = v4[15].m_nAllocationCount;
      useFilters = (*(_DWORD *)(*(_DWORD *)(v9 + 264) + 28) & 0x20) != 0;
      v17 = 0;
      i = 0;
      if ( *(_DWORD *)(m_nAllocationCount + 28) != 0 )
      {
        v42 = 0;
        do
        {
          v18 = v42 + *(_DWORD *)(m_nAllocationCount + 24);
          v19 = *((_DWORD *)&v4[16].m_pMemory->___u0 + v17);
          v40 = v18;
          if ( v19 != 0 )
          {
            m_nGrowSize = v4[17].m_nGrowSize;
            if ( m_nGrowSize != 0 )
            {
              if ( m_nGrowSize == 1 )
              {
                if ( (*(_BYTE *)(v18 + 80) & 2) != 0 )
                  goto LABEL_14;
              }
              else if ( m_nGrowSize == 2 && (*(_BYTE *)(v18 + 80) & 4) != 0 )
              {
LABEL_14:
                GFxDisplayContext::PreDisplay(
                  this: (GFxDisplayContext *)context,
                  a2: (struct GFxDisplayContextTransforms *)&oldXform,
                  a3: (const struct GFxCharacter *)v4,
                  a4: &v46,
                  a5: &v44,
                  a6: &v45);
                v21 = (void (__thiscall **)(int, int))(*(_DWORD *)v41 + 68);
                v22 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v19 + 20))(a1: v19, a2);
                (*v21)(a1: v41, a2: v22);
                v24 = false;
                if ( useFilters )
                {
                  GFxDisplayContext::BeginFilters(
                    this: (CUtlVector<void *,CUtlMemory<void *,int> > *)context,
                    oldFilters: (void *const *)&oldFilters.m_Memory.m_pMemory,
                    ch: v19);
                  if ( v23 != 0 )
                    v24 = true;
                }
                a2 = (int)context;
                (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 116))(a1: v19);
                if ( v24 )
                  GFxDisplayContext::EndFilters(
                    this: (CUtlVector<void *,CUtlMemory<void *,int> > *)context,
                    &oldFilters);
                (*(void (__thiscall **)(int))(*(_DWORD *)v41 + 72))(a1: v41);
                v17 = i;
                v4 = v38;
              }
            }
            else if ( (*(_BYTE *)(v18 + 80) & 8) != 0 )
            {
              goto LABEL_14;
            }
          }
          m_nAllocationCount = v4[15].m_nAllocationCount;
          v42 += 84;
          i = ++v17;
        }
        while ( v17 < *(_DWORD *)(m_nAllocationCount + 28) );
      }
      context[28] = (int)psavea;
      GFxDisplayContext::PostDisplay(this: (CUtlVector<void *,CUtlMemory<void *,int> > *)context, (int)&oldXform);
      ((void (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))v4->m_pMemory[34].resData)(a1: v4);
      if ( v30 != 0 )
      {
        v25 = (void (__thiscall ***)(_DWORD, int))v30;
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(v30 + 4), Value: -1) == 1 )
          (**v25)(a1: v25, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110060
// Name: public: class GASButtonObject __near * GFxButtonCharacter::GetButtonASObject(void)
// Source: json
//------------------------------------------------------------------------------
ResourceEntryInfo *__thiscall GFxButtonCharacter::GetButtonASObject(CUtlMemory<ResourceEntryInfo,int> *this)
{
  GASButtonObject *v2; // edi
  _KCRM_MARSHAL_HEADER *v3; // eax
  GASButtonObject *v4; // edi
  int v5; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 54) != 0 )
    return *((ResourceEntryInfo **)this + 54);
  v7 = 323;
  v2 = (GASButtonObject *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 56, a4: &v7);
  if ( v2 != nullptr )
  {
    v3 = (_KCRM_MARSHAL_HEADER *)((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[26].eType)(a1: this);
    v4 = GASButtonObject::GASButtonObject(this: v2, gCtxt: v3, a3: (GRefCountWeakSupportImpl *)this);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = *((_DWORD *)this + 54);
  if ( v5 != 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2: (int)v4);
  *((_DWORD *)this + 54) = v4;
  return (ResourceEntryInfo *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x101100E0
// Name: public: virtual class GASObject __near * GFxButtonCharacter::GetASObject(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall GFxButtonCharacter::GetASObject(CUtlMemory<ResourceEntryInfo,int> *this)
{
  GFxButtonCharacter::GetButtonASObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x101100F0
// Name: public: virtual bool GFxButtonCharacter::GetStandardMember(enum GFxASCharacter::StandardMember,class GASValue __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxButtonCharacter::GetStandardMember@<al>(
        CUtlMemory<ResourceEntryInfo,int> *this@<ecx>,
        double a2@<st0>,
        int a3,
        GASValue *a4,
        int opcodeFlag)
{
  bool v6; // bl
  unsigned int v8; // ebx
  int v9; // ecx
  int (__thiscall *v10)(int, int, int *); // edx
  GASRectangleObject *v11; // eax
  struct GASObject *v12; // edi
  float *v13; // eax
  double v14; // st6
  double v15; // st5
  double v16; // st7
  int v17; // [esp+0h] [ebp-2Ch]
  double v18[4]; // [esp+Ch] [ebp-20h] BYREF

  if ( GFxASCharacter::GetStandardMember(a1: (int)this, a2, a3, a4, opcodeFlag) != 0 )
    return 1;
  if ( a3 != 36 )
  {
    if ( a3 == 69
      && *(_BYTE *)(*(_DWORD *)(((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[13].resData)(a1: this)
                              + 120)
                  + 684) == 1 )
    {
      v6 = (*((_DWORD *)this + 40) & 0x800) != 0;
      GASValue::DropRefs(this: a4);
      *((_BYTE *)a4 + 4) = v6;
      *(_BYTE *)a4 = 2;
      return 1;
    }
    return 0;
  }
  if ( *(_BYTE *)(((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[13].resData)(a1: this) + 124) >= 8u )
  {
    if ( *((_DWORD *)this + 47) != 0 )
    {
      v8 = ((int (__thiscall *)(CUtlMemory<ResourceEntryInfo,int> *))this->m_pMemory[13].resData)(a1: this);
      v9 = *(_DWORD *)(*(_DWORD *)(v8 + 120) + 656);
      v10 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v9 + 40);
      opcodeFlag = 323;
      v11 = (GASRectangleObject *)v10(a1: v9, a2: 52, a3: &opcodeFlag);
      if ( v11 != nullptr )
        v12 = (struct GASObject *)GASRectangleObject::GASRectangleObject(this: v11, a2: (struct GASEnvironment *)v8);
      else
        v12 = nullptr;
      v13 = *((float **)this + 47);
      *(float *)&opcodeFlag = v13[1] / 20.0;
      v14 = *(float *)&opcodeFlag;
      *(float *)&opcodeFlag = v13[2] + *v13;
      *(float *)&opcodeFlag = *(float *)&opcodeFlag / 20.0;
      v15 = *(float *)&opcodeFlag;
      *(float *)&opcodeFlag = v13[3] + v13[1];
      *(float *)&opcodeFlag = *(float *)&opcodeFlag / 20.0;
      v16 = *(float *)&opcodeFlag;
      *(float *)&opcodeFlag = *v13 / 20.0;
      v18[0] = *(float *)&opcodeFlag;
      v18[1] = v14;
      v18[2] = v15;
      v18[3] = v16;
      GASRectangleObject::SetProperties(penv: v8, r: (GMemoryHeap *)v18, a3: v17);
      GASValue::SetAsObject(this: a4, a2: v12);
      if ( v12 != nullptr )
      {
        GRefCountBaseGC<323>::Release(a1: (int)v12, a2: (int)v12);
        return 1;
      }
    }
    else
    {
      GASValue::DropRefs(this: a4);
      *(_BYTE *)a4 = 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10110260
// Name: public: virtual bool GFxButtonCharacter::SetStandardMember(enum GFxASCharacter::StandardMember,class GASValue const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxButtonCharacter::SetStandardMember(
        int this,
        CUtlMemory<ResourceEntryInfo,int> *result,
        tagWNDCLASSW *origVal,
        bool opcodeFlag)
{
  int v5; // eax
  CUtlMemory<ResourceEntryInfo,int> *v6; // ebx
  int v7; // edi
  int v8; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v9; // edx
  unsigned __int8 v10; // bl
  tagPOLYTEXTW *v12; // eax
  const struct GASEnvironment *v14; // ebx
  struct GASObject *v15; // eax
  bool v16; // bl
  int (__thiscall *v17)(int); // eax
  int v18; // eax
  int v19; // [esp+0h] [ebp-4Ch]
  int v20; // [esp+0h] [ebp-4Ch]
  const char *v21; // [esp+4h] [ebp-48h]
  int v22; // [esp+8h] [ebp-44h]
  double v23; // [esp+Ch] [ebp-40h] BYREF
  double v24; // [esp+14h] [ebp-38h]
  double v25; // [esp+1Ch] [ebp-30h]
  double v26; // [esp+24h] [ebp-28h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),CFuncMemPolicyNone> *sg; // [esp+2Ch] [ebp-20h] BYREF
  float v28; // [esp+30h] [ebp-1Ch]
  float v29; // [esp+34h] [ebp-18h]
  float v30; // [esp+38h] [ebp-14h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *val; // [esp+3Ch] [ebp-10h] BYREF
  float v32; // [esp+54h] [ebp+8h]
  float v33; // [esp+54h] [ebp+8h]
  float v34; // [esp+54h] [ebp+8h]
  float v35; // [esp+54h] [ebp+8h]
  tagWNDCLASSW *origVala; // [esp+58h] [ebp+Ch]

  GASValue::GASValue(this: &val, a2: (const struct GASValue *)origVal);
  v5 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 112))(a1: this);
  v6 = result;
  v7 = v5;
  if ( (int)result > 21
    && v5 != 0
    && GFxButtonCharacter::GetButtonASObject((CUtlMemory<ResourceEntryInfo,int> *)this) != nullptr
    && *(_DWORD *)(*(_DWORD *)(this + 216) + 44) != 0 )
  {
    v8 = *(_DWORD *)(v7 + 120);
    v9 = *(&GFxASCharacter::MemberTable + 3 * (_DWORD)result);
    LOBYTE(sg) = 0;
    origVala = (tagWNDCLASSW *)GASStringManager::CreateConstStringNode(
                                 this: *(GASStringManager **)(v8 + 636),
                                 result: v9,
                                 a3: strlen((const char *)v9),
                                 a4: 0);
    ++origVala->cbClsExtra;
    v10 = (unsigned __int8)GASObject::InvokeWatchpoint();
    if ( origVala->cbClsExtra-- == 1 )
      GASStringNode::ReleaseNode();
    if ( v10 != 0 )
      GASValue::operator=(v: (tagWNDCLASSW *)&sg);
    GASValue::~GASValue(this: (GASValue *)&sg);
    v6 = result;
  }
  if ( GFxASCharacter::SetStandardMember(
         (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)this,
         member: (signed int)v6,
         (tagWNDCLASSW *)&val,
         opcodeFlag) != 0 )
    goto LABEL_16;
  if ( v6 != (CUtlMemory<ResourceEntryInfo,int> *)36 )
  {
    if ( v6 == (CUtlMemory<ResourceEntryInfo,int> *)69
      && *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)this + 112))(a1: this) + 120) + 684) == 1 )
    {
      v12 = (tagPOLYTEXTW *)(*(int (__thiscall **)(int))(*(_DWORD *)this + 112))(a1: this);
      if ( (unsigned __int8)GASValue::ToBool(result: v12) != 0 )
        *(_DWORD *)(this + 160) |= 0x800u;
      else
        *(_DWORD *)(this + 160) &= ~0x800u;
LABEL_16:
      GASValue::~GASValue(this: &val);
      return 1;
    }
  }
  else if ( *(_BYTE *)((*(int (__thiscall **)(int))(*(_DWORD *)this + 112))(a1: this) + 124) >= 8u )
  {
    v14 = (const struct GASEnvironment *)(*(int (__thiscall **)(int))(*(_DWORD *)this + 112))(a1: this);
    v15 = GASValue::ToObject(this: &val, a2: v14);
    if ( v15 == nullptr || ((int (__thiscall *)(struct GASObject *))v15[2].pNode[1].pNext)(a1: &v15[2]) != 17 )
    {
      v16 = *(_DWORD *)(this + 188) != 0;
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 188));
      v17 = *(int (__thiscall **)(int))(*(_DWORD *)this + 84);
      *(_WORD *)(this + 118) &= ~1u;
      *(_DWORD *)(this + 188) = 0;
      v18 = v17(a1: this);
      *(_DWORD *)(v18 + 9332) |= 0x400u;
      if ( v16 )
        (*(void (__thiscall **)(int))(*(_DWORD *)this + 80))(a1: this);
      goto LABEL_16;
    }
    v23 = 0.0;
    v24 = 0.0;
    v25 = 0.0;
    v26 = 0.0;
    GASRectangleObject::GetProperties(penv: (unsigned int)v14, r: (GMemoryHeap *)&v23, params: v19, a4: v21, a5: v22);
    v32 = v23;
    *(float *)&sg = v32 * 20.0;
    v33 = v24;
    v28 = v33 * 20.0;
    v34 = v25 - v23;
    v29 = v34 * 20.0;
    v35 = v26 - v24;
    v30 = 20.0 * v35;
    GFxButtonCharacter::SetScale9Grid((CUtlMemory<ResourceEntryInfo,int> *)this, gr: (int)&sg, a3: v20);
    GASValue::~GASValue(this: &val);
    return 1;
  }
  GASValue::~GASValue(this: &val);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101104F0
// Name: public: virtual GFxButtonCharacter::~GFxButtonCharacter(void)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxButtonCharacter::~GFxButtonCharacter(
        GFxMovie *this@<ecx>,
        int a2@<edi>,
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *a3)
{
  void *v4; // edx
  int v5; // ecx
  int v6; // eax
  GRefCountNTSImpl **v7; // edi
  int v8; // ebx

  v4 = *((void **)this + 47);
  this->__vftable = (GFxMovie_vtbl *)&GFxButtonCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxButtonCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxButtonCharacter::`vftable';
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  v5 = *((_DWORD *)this + 54);
  if ( v5 != 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2);
  v6 = *((_DWORD *)this + 49);
  v7 = (GRefCountNTSImpl **)(*((_DWORD *)this + 48) + 4 * v6 - 4);
  if ( v6 != 0 )
  {
    v8 = *((_DWORD *)this + 49);
    do
    {
      if ( *v7 != nullptr )
        GRefCountNTSImpl::Release(this: *v7);
      --v7;
      --v8;
    }
    while ( v8 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 48));
  GFxASCharacter::~GFxASCharacter((GFxASCharacter *)this, a2: this, a3);
}

//------------------------------------------------------------------------------
// Address: 0x101105B0
// Name: public: virtual bool GFxButtonCharacter::OnButtonEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GFxButtonCharacter::OnButtonEvent@<al>(float a1@<ecx>, _TAPE_WMI_OPERATIONS *a2@<edi>, GFxEventId *a3)
{
  __int16 v4; // ax
  int v5; // ecx
  unsigned int *v6; // ebx
  bool v7; // zf
  GFxEventId v8; // eax
  int v9; // ecx
  GFxEventId v10; // eax
  int v11; // eax
  GFxEventId v12; // eax
  _TAPE_WMI_OPERATIONS *v13; // edi
  int v14; // eax
  _NETRESOURCEW *v15; // ebx
  unsigned int v16; // eax
  int v17; // edi
  int v18; // eax
  int v19; // ecx
  int (__thiscall *v20)(int, int, int *); // eax
  _DWORD *v21; // eax
  GRefCountNTSImpl *v22; // edi
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  _TAPE_WMI_OPERATIONS *v26; // eax
  unsigned __int8 (__thiscall *v27)(int, int, _TAPE_WMI_OPERATIONS **, GASValue *); // edx
  int (__thiscall *v28)(_DWORD); // edx
  int v29; // eax
  const GPoint3<float> *inserted; // edi
  GFxEventId v31; // ecx
  GFxEventId v32; // edx
  GFxEventId v33; // eax
  unsigned int v34; // ebx
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  float v37; // ecx
  float v38; // edx
  float v39; // eax
  GASValue method[5]; // [esp+4h] [ebp-44h] BYREF
  GFxEventId v42; // [esp+18h] [ebp-30h]
  GFxEventId v43; // [esp+1Ch] [ebp-2Ch]
  GFxEventId v44; // [esp+20h] [ebp-28h]
  ICommandCompletionCallback n; // [esp+24h] [ebp-24h]
  int v46; // [esp+28h] [ebp-20h] BYREF
  unsigned int i; // [esp+2Ch] [ebp-1Ch]
  unsigned int j; // [esp+30h] [ebp-18h]
  int kc; // [esp+34h] [ebp-14h]
  _TAPE_WMI_OPERATIONS *v50; // [esp+38h] [ebp-10h] BYREF
  int v51; // [esp+3Ch] [ebp-Ch]
  int c; // [esp+40h] [ebp-8h]
  bool handlerFound; // [esp+47h] [ebp-1h]

  v4 = *(_WORD *)(LODWORD(a1) + 118);
  if ( (v4 & 0x100) != 0 )
    return false;
  if ( *(int *)(LODWORD(a1) + 20) < -1 )
    return false;
  if ( (v4 & 0x10) != 0 )
    return false;
  v5 = *(_DWORD *)(LODWORD(a1) + 160);
  if ( (*(_DWORD *)(LODWORD(a1) + 160) & 0x10) == 0 )
    return false;
  v6 = (unsigned int *)a3;
  v7 = *((_BYTE *)a3 + 12) == 0;
  handlerFound = false;
  if ( v7 )
  {
    v8 = *a3;
    if ( (unsigned int)*a3 > 0x2000 )
    {
      if ( v8 == (GFxEventId)0x4000 )
      {
LABEL_11:
        *(_DWORD *)(LODWORD(a1) + 212) = 0;
        goto LABEL_12;
      }
      if ( v8 != (GFxEventId)0x8000 )
      {
        if ( v8 == (GFxEventId)0x10000 )
          *(_DWORD *)(LODWORD(a1) + 212) = 2 * ((v5 & 0x2000) == 0);
LABEL_12:
        v9 = *(_DWORD *)(LODWORD(a1) + 184);
        if ( *(_DWORD *)(v9 + 16) == 0 )
        {
LABEL_30:
          v12 = *a3;
          c = 0;
          kc = 0;
          if ( v12 == (GFxEventId)0x2000 )
          {
            c = 1;
          }
          else if ( v12 == (GFxEventId)0x4000 )
          {
            c = 2;
          }
          else if ( v12 == (GFxEventId)1024 )
          {
            c = 4;
          }
          else if ( v12 == (GFxEventId)2048 )
          {
            c = 8;
          }
          else if ( v12 == (GFxEventId)0x10000 )
          {
            c = 16;
          }
          else if ( v12 == (GFxEventId)0x8000 )
          {
            c = 32;
          }
          else if ( v12 == (GFxEventId)4096 )
          {
            c = 64;
          }
          else if ( v12 == (GFxEventId)0x20000 )
          {
            kc = GFxEventId::ConvertToButtonKeyCode(this: a3);
          }
          GFxButtonCharacter::RecreateCharacters(this: (CUtlMemory<ResourceEntryInfo,int> *)LODWORD(a1));
          if ( *(_DWORD *)(LODWORD(a1) + 32) != 0 )
          {
            v13 = GASObjectInterface::ToSprite(result: a2);
            v50 = v13;
            if ( v13 != nullptr )
            {
              v7 = *(_DWORD *)(*(_DWORD *)(LODWORD(a1) + 184) + 40) == 0;
              i = 0;
              if ( !v7 )
              {
                v51 = 0;
                do
                {
                  v14 = *(_DWORD *)(v51 + *(_DWORD *)(*(_DWORD *)(LODWORD(a1) + 184) + 36));
                  if ( (v14 & c & 0xFFFF01FF) != 0 || kc > 0 && ((v14 >> 9) & 0x7F) == kc )
                  {
                    v15 = (_NETRESOURCEW *)((*(int (__thiscall **)(_TAPE_WMI_OPERATIONS *))(v13->Method + 112))(a1: v13)
                                          + 120);
                    v16 = 0;
                    n.__vftable = *(ICommandCompletionCallback_vtbl **)(*(_DWORD *)(*(_DWORD *)(LODWORD(a1) + 184) + 36)
                                                                      + v51
                                                                      + 8);
                    j = 0;
                    if ( n.__vftable != nullptr )
                    {
                      do
                      {
                        v17 = 4 * v16;
                        v18 = *(_DWORD *)(4 * v16
                                        + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(a1) + 184) + 36) + v51 + 4));
                        if ( *(_DWORD *)(v18 + 12) != 0 && **(_BYTE **)(v18 + 8) != 0 )
                        {
                          v19 = *(_DWORD *)(v15->dwScope + 656);
                          v20 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v19 + 40);
                          v46 = 323;
                          v21 = (_DWORD *)v20(a1: v19, a2: 32, a3: &v46);
                          v22 = v21 != nullptr
                              ? (GRefCountNTSImpl *)GASActionBuffer::GASActionBuffer(
                                                      this: v21,
                                                      result: v15,
                                                      pbufferData_4: *(IShaderDevice **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(a1) + 184)
                                                                                                + 36)
                                                                                    + v51
                                                                                    + 4)
                                                                        + v17))
                              : nullptr;
                          GFxSprite::AddActionBuffer(this: v50, a: (int)v22, a_4: (const GPoint3<float> *)4);
                          if ( v22 != nullptr )
                            GRefCountNTSImpl::Release(this: v22);
                        }
                        v16 = j + 1;
                        j = v16;
                      }
                      while ( v16 < (unsigned int)n.__vftable );
                      v13 = v50;
                      handlerFound = true;
                    }
                    v6 = (unsigned int *)a3;
                  }
                  v23 = *(_DWORD *)(LODWORD(a1) + 184);
                  v51 += 16;
                  ++i;
                }
                while ( i < *(_DWORD *)(v23 + 40) );
              }
            }
          }
          goto LABEL_66;
        }
        v10 = *a3;
        if ( (unsigned int)*a3 > 0x2000 )
        {
          if ( v10 == (GFxEventId)0x4000 )
          {
            v11 = 0;
            goto LABEL_29;
          }
        }
        else
        {
          if ( *a3 == (GFxEventId)0x2000 )
          {
            v11 = 1;
            goto LABEL_29;
          }
          if ( v10 == (GFxEventId)1024 )
          {
            v11 = 2;
            goto LABEL_29;
          }
          if ( v10 == (GFxEventId)2048 )
          {
            v11 = 3;
LABEL_29:
            (*(void (__thiscall **)(_DWORD, float, int))(**(_DWORD **)(v9 + 16) + 4))(
              a1: *(_DWORD *)(v9 + 16),
              a2: COERCE_FLOAT(LODWORD(a1)),
              a3: v11);
            goto LABEL_30;
          }
        }
        v11 = -1;
        goto LABEL_29;
      }
    }
    else
    {
      if ( *a3 == (GFxEventId)0x2000 )
      {
LABEL_18:
        *(_DWORD *)(LODWORD(a1) + 212) = 2;
        goto LABEL_12;
      }
      if ( v8 != (GFxEventId)1024 )
      {
        if ( v8 != (GFxEventId)2048 )
        {
          if ( v8 != (GFxEventId)4096 )
            goto LABEL_12;
          goto LABEL_11;
        }
        goto LABEL_18;
      }
    }
    *(_DWORD *)(LODWORD(a1) + 212) = 1;
    goto LABEL_12;
  }
LABEL_66:
  v24 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(a1) + 112))(a1: COERCE_FLOAT(LODWORD(a1)));
  if ( v24 != 0 )
  {
    v25 = v24 + 120;
    GFxEventId::GetFunctionName(this: v6, a2: &v50, psc: (_DWORD *)(v24 + 120));
    v26 = v50;
    if ( v50[1].DataBufferSize != 0 )
    {
      v27 = *(unsigned __int8 (__thiscall **)(int, int, _TAPE_WMI_OPERATIONS **, GASValue *))(*(_DWORD *)(LODWORD(a1) + 120)
                                                                                            + 44);
      LOBYTE(method[0]) = 0;
      if ( v27(a1: LODWORD(a1) + 120, a2: v25, a3: &v50, a4: method) != 0 )
      {
        v28 = *(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(a1) + 84);
        handlerFound = true;
        v29 = v28(a1: LODWORD(a1));
        inserted = GFxMovieRoot::ActionQueueType::InsertEntry(this: v29 + 9224, result: (const GPoint3<float> *)4);
        if ( inserted != nullptr )
        {
          v31 = a3[1];
          v32 = a3[2];
          v33 = a3[3];
          v34 = *v6;
          LODWORD(inserted->y) = 2;
          ++*(_DWORD *)(LODWORD(a1) + 4);
          v42 = v31;
          z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
          v43 = v32;
          v44 = v33;
          if ( z_low != nullptr )
            GRefCountNTSImpl::Release(this: z_low);
          inserted->z = a1;
          x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
          if ( x_low != nullptr )
            GRefCountNTSImpl::Release(this: x_low);
          v37 = *(float *)&v42;
          v38 = *(float *)&v43;
          v39 = *(float *)&v44;
          inserted[1].x = 0.0;
          LODWORD(inserted[1].y) = v34;
          inserted[1].z = v37;
          inserted[2].x = v38;
          inserted[2].y = v39;
        }
      }
      GASValue::~GASValue(this: method);
      v26 = v50;
    }
    v7 = v26->DataBuffer-- == (void *)1;
    if ( v7 )
      GASStringNode::ReleaseNode();
  }
  return handlerFound;
}

//------------------------------------------------------------------------------
// Address: 0x101109B0
// Name: public: virtual class GFxCharacter __near * GFxButtonCharacterDef::CreateCharacterInstance(class GFxASCharacter __near *,class GFxResourceId,class GFxMovieDefImpl __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<ResourceEntryInfo,int> *__thiscall GFxButtonCharacterDef::CreateCharacterInstance(
        struct GFxButtonCharacterDef *this,
        const GFxAmpMessageCurrentState *result,
        struct GFxResourceId a3,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingImpl)
{
  CUtlMemory<ResourceEntryInfo,int> *v5; // eax
  int v7; // [esp+8h] [ebp-4h] BYREF

  v7 = 322;
  v5 = (CUtlMemory<ResourceEntryInfo,int> *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                              this: GMemory::pGlobalHeap,
                                              a2: result,
                                              a3: 220,
                                              a4: &v7);
  if ( v5 != nullptr )
    return GFxButtonCharacter::GFxButtonCharacter(
             this: v5,
             a2: this,
             pbindingDefImpl: pbindingImpl,
             a4: (struct GFxASCharacter *)result,
             a5: a3);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10110A10
// Name: public: bool GFxButtonRecord::Read(class GFxLoadProcess __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxButtonRecord::Read(int this, int a2, int a3)
{
  int v3; // edi
  int v5; // eax
  int v6; // eax
  char v7; // cl
  int v9; // edi
  int v10; // esi
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // esi
  int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  char *v18; // esi
  tagSTATSTG *v19; // esi
  int v20; // eax
  int v21; // ecx
  unsigned __int8 v22; // al
  _cpinfo *v23; // [esp+0h] [ebp-28Ch]
  unsigned int v24; // [esp+0h] [ebp-28Ch]
  int v25; // [esp+Ch] [ebp-280h]
  int v26; // [esp+10h] [ebp-27Ch]
  char v27; // [esp+14h] [ebp-278h]
  IStream v28; // [esp+18h] [ebp-274h] BYREF
  char v29; // [esp+24h] [ebp-268h] BYREF

  v3 = *(_DWORD *)(a2 + 804);
  if ( v3 == 0 )
    v3 = a2 + 40;
  v5 = *(_DWORD *)(v3 + 48) - *(_DWORD *)(v3 + 44);
  *(_BYTE *)(v3 + 21) = 0;
  if ( v5 < 1 )
    GFxStream::PopulateBuffer1(result: v23);
  v6 = *(_DWORD *)(v3 + 44);
  v7 = *(_BYTE *)(v6 + *(_DWORD *)(v3 + 60));
  *(_DWORD *)(v3 + 44) = v6 + 1;
  v27 = v7;
  if ( v7 == 0 )
    return 0;
  v9 = *(_DWORD *)(a2 + 804);
  if ( v9 == 0 )
    v9 = a2 + 40;
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"-- action record:  ");
  *(_BYTE *)(this + 80) = 0;
  if ( (v27 & 8) != 0 )
  {
    *(_BYTE *)(this + 80) = 1;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"HitTest ");
  }
  if ( (v27 & 4) != 0 )
  {
    *(_BYTE *)(this + 80) |= 2u;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"Down ");
  }
  if ( (v27 & 2) != 0 )
  {
    *(_BYTE *)(this + 80) |= 4u;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"Over ");
  }
  if ( (v27 & 1) != 0 )
  {
    *(_BYTE *)(this + 80) |= 8u;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"Up ");
  }
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"\n");
  if ( *(_DWORD *)(a2 + 804) != 0 )
    v10 = *(_DWORD *)(a2 + 804);
  else
    v10 = a2 + 40;
  v11 = *(_DWORD *)(v10 + 48) - *(_DWORD *)(v10 + 44);
  *(_BYTE *)(v10 + 21) = 0;
  if ( v11 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v12 = *(_DWORD *)(v10 + 44);
  v13 = *(unsigned __int16 *)(*(_DWORD *)(v10 + 60) + v12);
  *(_DWORD *)(v10 + 44) = v12 + 2;
  v25 = v13;
  *(_DWORD *)(this + 68) = v13;
  if ( *(_DWORD *)(a2 + 804) != 0 )
    v14 = *(_DWORD *)(a2 + 804);
  else
    v14 = a2 + 40;
  v15 = *(_DWORD *)(v14 + 48) - *(_DWORD *)(v14 + 44);
  *(_BYTE *)(v14 + 21) = 0;
  if ( v15 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v16 = *(_DWORD *)(v14 + 44);
  v17 = *(_WORD *)(*(_DWORD *)(v14 + 60) + v16);
  *(_DWORD *)(v14 + 44) = v16 + 2;
  *(_WORD *)(this + 72) = v17;
  GFxStream::ReadMatrix(this: (GFxStream *)v9, a2: (struct GMatrix2D *)(this + 12));
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)v9,
    a2: (int)"   CharId = %d, ButtonLayer = %d\n",
    v25,
    *(unsigned __int16 *)(this + 72));
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"   mat:\n");
  GFxStream::LogParseClass(result: (_MAT2 *)(this + 12));
  if ( a3 == 34 )
  {
    GFxStream::ReadCxformRgba(this: (GFxStream *)v9, a2: (struct GRenderer::Cxform *)(this + 36));
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"   cxform:\n");
    GFxStream::LogParseClass(this: (GFxStream *)v9, a2: (const struct GRenderer::Cxform *)(this + 36));
  }
  if ( (v27 & 0x10) != 0 )
  {
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"   HasFilters\n");
    v26 = 3;
    v18 = &v29;
    do
    {
      *((_DWORD *)v18 - 1) = 0;
      *((_DWORD *)v18 + 2) = 1;
      *(float *)v18 = 5.0;
      *((float *)v18 + 1) = 5.0;
      *((float *)v18 + 3) = 0.0;
      *((float *)v18 + 4) = 0.0;
      *((float *)v18 + 7) = 1.0;
      GRenderer::Cxform::Cxform(this: (float *)v18 + 8);
      v18 += 156;
      --v26;
    }
    while ( v26 >= 0 );
    v19 = (tagSTATSTG *)GFx_LoadFilters<GFxStream>();
    if ( v19 != nullptr )
    {
      GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::Clear(this: (ITypeInfo *)v23);
      GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::Append(
        a1: (CMatQueuedMesh *)this,
        this: &v28,
        other: v19,
        count: v24);
    }
  }
  if ( (v27 & 0x20) != 0 )
  {
    v20 = *(_DWORD *)(v9 + 48) - *(_DWORD *)(v9 + 44);
    *(_BYTE *)(v9 + 21) = 0;
    if ( v20 < 1 )
      GFxStream::PopulateBuffer1(result: v23);
    v21 = *(_DWORD *)(v9 + 44);
    v22 = *(_BYTE *)(v21 + *(_DWORD *)(v9 + 60));
    *(_DWORD *)(v9 + 44) = v21 + 1;
    if ( v22 == 0 || v22 > 0xEu )
      v22 = 1;
    *(_DWORD *)(this + 76) = v22;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v9, a2: (int)"   HasBlending, %d\n", v22);
  }
  else
  {
    *(_DWORD *)(this + 76) = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10110ED0
// Name: public: virtual GFxButtonCharacterDef::~GFxButtonCharacterDef(void)
// Source: json
//------------------------------------------------------------------------------
GFxAmpMessageCurrentState *__thiscall GFxButtonCharacterDef::~GFxButtonCharacterDef(void *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  CSchemaClassBindingBase *v3; // edi
  int v4; // ebx
  GFxAmpMessageCurrentState *v5; // eax

  v2 = *((void (__thiscall ****)(_DWORD, int))this + 4);
  *(_DWORD *)this = &GFxButtonCharacterDef::`vftable';
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 12));
  v3 = (CSchemaClassBindingBase *)(*((_DWORD *)this + 9) + 16 * *((_DWORD *)this + 10) - 16);
  if ( *((_DWORD *)this + 10) != 0 )
  {
    v4 = *((_DWORD *)this + 10);
    do
    {
      GFxButtonAction::~GFxButtonAction(this: v3--);
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 9));
  v5 = (GFxAmpMessageCurrentState *)GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>::~GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>(this: (_DWORD *)this + 6);
  *(_DWORD *)this = &GFxResource::`vftable';
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10110F40
// Name: public: virtual unsigned int GFxButtonCharacterDef::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacterDef::GetResourceTypeCode(GFxAmpMessageCurrentState *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10110F50
// Name: public: GFxButtonCharacterDef::GFxButtonCharacterDef(void)
// Source: json
//------------------------------------------------------------------------------
GFxButtonCharacterDef *__thiscall GFxButtonCharacterDef::GFxButtonCharacterDef(GFxButtonCharacterDef *this)
{
  *(_DWORD *)this = &GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0x40000;
  *(_DWORD *)this = &GFxButtonCharacterDef::`vftable';
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10110FC0
// Name: public: void GFxButtonCharacterDef::Read(class GFxLoadProcess __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxButtonCharacterDef::Read(int this, GFxAmpMsgHandler *a2, int a3)
{
  GFxAmpMsgHandler *v3; // ebx
  int v4; // esi
  unsigned int v5; // ecx
  _WORD *v6; // eax
  unsigned int v7; // eax
  int v8; // edi
  unsigned int v9; // ebx
  void **v10; // edi
  int v11; // esi
  unsigned int m; // ebx
  int v13; // eax
  int v14; // ebx
  unsigned int v15; // esi
  unsigned int v16; // edi
  CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *v17; // ecx
  unsigned int v18; // esi
  int v19; // eax
  _DWORD *v20; // ecx
  int n; // edx
  IShaderDeviceMgr *v22; // ecx
  int v23; // eax
  tagBITMAPINFOHEADER *v24; // edx
  _DWORD *v25; // ecx
  int v26; // ecx
  int v27; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v28; // ecx
  char v29; // al
  int U16; // ecx
  _DWORD *RefCount; // eax
  int v32; // esi
  int v33; // esi
  unsigned int v34; // ebx
  _WORD *v35; // eax
  unsigned int v36; // ecx
  int v37; // esi
  unsigned int v38; // edi
  void **v39; // esi
  int v40; // eax
  int v41; // ebx
  unsigned int v42; // esi
  unsigned int v43; // edi
  IShaderDeviceMgr *v44; // ecx
  GFxAmpMsgHandler *v45; // esi
  int v46; // ecx
  volatile int v47; // eax
  unsigned __int16 v48; // dx
  int v49; // edx
  unsigned int v50; // edi
  int v51; // eax
  int v52; // edx
  _DWORD *v53; // ecx
  unsigned int v54; // esi
  IShaderDeviceMgr *v55; // ecx
  int v56; // eax
  tagBITMAPINFOHEADER *Stream; // eax
  IShaderDeviceMgr *v58; // eax
  int v59; // eax
  IShaderDeviceMgr *v60; // eax
  _BYTE *v61; // [esp-Ch] [ebp-88h]
  _BYTE *v62; // [esp-Ch] [ebp-88h]
  unsigned __int64 v63; // [esp-8h] [ebp-84h]
  unsigned __int64 v64; // [esp-8h] [ebp-84h]
  char v65; // [esp-4h] [ebp-80h]
  ShaderDisplayMode_t *v66; // [esp+0h] [ebp-7Ch]
  int v67; // [esp+0h] [ebp-7Ch]
  ShaderDisplayMode_t *v68; // [esp+0h] [ebp-7Ch]
  int v69; // [esp+0h] [ebp-7Ch]
  unsigned int v70; // [esp+4h] [ebp-78h]
  int v71; // [esp+4h] [ebp-78h]
  char *v72; // [esp+8h] [ebp-74h]
  int v73; // [esp+Ch] [ebp-70h]
  unsigned int pos; // [esp+14h] [ebp-68h]
  int posa; // [esp+14h] [ebp-68h]
  int posb; // [esp+14h] [ebp-68h]
  unsigned int v78; // [esp+1Ch] [ebp-60h]
  int v79; // [esp+1Ch] [ebp-60h]
  unsigned int v80; // [esp+1Ch] [ebp-60h]
  int v81; // [esp+1Ch] [ebp-60h]
  int k; // [esp+20h] [ebp-5Ch]
  _BYTE *v83; // [esp+20h] [ebp-5Ch]
  _DWORD *v84; // [esp+20h] [ebp-5Ch]
  int i; // [esp+20h] [ebp-5Ch]
  _BYTE *v86; // [esp+20h] [ebp-5Ch]
  int v87; // [esp+20h] [ebp-5Ch]
  void *v88; // [esp+24h] [ebp-58h] BYREF
  int v89; // [esp+28h] [ebp-54h]
  int v90; // [esp+2Ch] [ebp-50h]
  float v91; // [esp+30h] [ebp-4Ch] BYREF
  float v92; // [esp+34h] [ebp-48h]
  float v93; // [esp+38h] [ebp-44h]
  float v94; // [esp+3Ch] [ebp-40h]
  float v95; // [esp+40h] [ebp-3Ch]
  float v96; // [esp+44h] [ebp-38h]
  float v97[10]; // [esp+48h] [ebp-34h] BYREF
  int v98; // [esp+70h] [ebp-Ch]
  char j; // [esp+74h] [ebp-8h]

  v3 = a2;
  v4 = this;
  if ( a3 != 7 )
  {
    if ( a3 == 17 )
    {
      v26 = *(_DWORD *)(a2->RecvName.HeapTypeBits + 52);
      if ( v26 != 0 )
      {
        v27 = (*(int (__thiscall **)(int))(*(_DWORD *)v26 + 8))(a1: v26);
        *(_DWORD *)(v4 + 16) = (*(int (__thiscall **)(int, GFxAmpMsgHandler *))(*(_DWORD *)v27 + 4))(a1: v27, a2);
      }
      else
      {
        SkipButtonSoundDef(p: (HBITMAP__)a2);
        GFxLogBase<GFxLoadProcess>::LogScriptWarning(
          this: v28,
          pfmt: (unsigned int)&a2[1],
          a3: (int)"GFxButtonCharacterDef::Read: Audio library is not set. Skipping sound definitions.",
          a4: v65);
      }
      return;
    }
    if ( a3 != 34 )
      return;
    GFxLoadProcess::ReadU8(this: a2, a2: (unsigned int)v66, a3: v70, a4: v72);
    *(_BYTE *)(v4 + 20) = v29 != 0;
    U16 = (unsigned __int16)GFxLoadProcess::ReadU16(this: a2);
    RefCount = (_DWORD *)a2[40].RefCount;
    v73 = U16;
    if ( RefCount == nullptr )
      RefCount = &a2[2].__vftable;
    v32 = RefCount[13] - RefCount[12];
    v88 = nullptr;
    v33 = RefCount[11] + v32;
    v89 = 0;
    posa = v33 + U16 - 2;
    v90 = 0;
    GMatrix2D::SetIdentity(this: &v91);
    GRenderer::Cxform::Cxform(this: v97);
    LODWORD(v97[8]) = 0x40000;
    j = 0;
    if ( GFxButtonRecord::Read(this: (int)&v88, (int)a2, a3: 34) == 0 )
    {
LABEL_75:
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v88);
      if ( v73 > 0 )
      {
        v44 = (IShaderDeviceMgr *)a2[40].RefCount;
        if ( v44 == nullptr )
          v44 = (IShaderDeviceMgr *)&a2[2];
        GFxStream::SetPosition(this: v44, pos: posa, a3: v67);
        while ( 1 )
        {
          v45 = (GFxAmpMsgHandler *)a2[40].RefCount;
          if ( v45 == nullptr )
            v45 = a2 + 2;
          v46 = v45[2].RecvPort - v45[2].RefCount;
          BYTE1(v45[1].__vftable) = 0;
          if ( v46 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v47 = v45[2].RefCount;
          v48 = *(_WORD *)((char *)&v45[3].dtr_GRefCountImplCore + v47);
          v45[2].RefCount = v47 + 2;
          v87 = v48;
          v49 = GFxLoadProcess::Tell(this: (GFxLoadProcess *)a2) + v48 - 2;
          v50 = *(_DWORD *)(this + 40);
          posb = v49;
          GArrayDataBase<GFxButtonAction,GAllocatorLH<GFxButtonAction,258>,GArrayDefaultPolicy>::ResizeNoConstruct(
            this: (CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *)(this + 36),
            (const char *)a2,
            pheapAddr: (const CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *)(this + 36),
            newSize: v50 + 1);
          if ( v50 + 1 > v50 )
          {
            v51 = *(_DWORD *)(this + 36) + 16 * v50;
            v52 = 1;
            v53 = (_DWORD *)(v51 + 12);
            do
            {
              if ( v51 != 0 )
              {
                *(v53 - 2) = 0;
                *(v53 - 1) = 0;
                *v53 = 0;
              }
              v51 += 16;
              v53 += 4;
              --v52;
            }
            while ( v52 != 0 );
          }
          if ( v87 != 0 )
          {
            v54 = v87 - 2;
          }
          else
          {
            v55 = (IShaderDeviceMgr *)a2[40].RefCount;
            if ( v55 == nullptr )
              v55 = (IShaderDeviceMgr *)&a2[2];
            GFxStream::GetTagEndPosition(this: v55, a2: v68, a3: v71);
            v54 = v56 - GFxLoadProcess::Tell(this: (GFxLoadProcess *)a2);
          }
          Stream = (tagBITMAPINFOHEADER *)GFxLoadProcess::GetStream(this: (GFxLoadProcess **)a2);
          GFxButtonAction::Read(
            this: (_DWORD *)(*(_DWORD *)(this + 36) + 16 * *(_DWORD *)(this + 40) - 16),
            result: Stream,
            a3: 34,
            a: v54);
          if ( v87 == 0 )
            break;
          v58 = (IShaderDeviceMgr *)a2[40].RefCount;
          if ( v58 == nullptr )
            v58 = (IShaderDeviceMgr *)&a2[2];
          GFxStream::GetTagEndPosition(this: v58, a2: v68, a3: v71);
          if ( GFxLoadProcess::Tell(this: (GFxLoadProcess *)a2) >= v59 )
            break;
          v60 = (IShaderDeviceMgr *)a2[40].RefCount;
          if ( v60 == nullptr )
            v60 = (IShaderDeviceMgr *)&a2[2];
          GFxStream::SetPosition(this: v60, pos: posb, a3: v69);
        }
      }
      return;
    }
    while ( 1 )
    {
      v34 = 0;
      if ( *(_DWORD *)(this + 28) != 0 )
      {
        v35 = (_WORD *)(*(_DWORD *)(this + 24) + 72);
        do
        {
          if ( *v35 > LOWORD(v97[9]) )
            break;
          ++v34;
          v35 += 42;
        }
        while ( v34 < *(_DWORD *)(this + 28) );
      }
      v36 = *(_DWORD *)(this + 28);
      v37 = this + 24;
      v38 = v36 + 1;
      v80 = v36;
      if ( v36 + 1 < v36 )
        break;
      if ( v38 >= *(_DWORD *)(this + 32) )
      {
        GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>::Reserve(
          this: (CUtlNoEscConversion *)v37,
          pheapAddr: (const CUtlNoEscConversion *)v37,
          newCapacity: v38 + (v38 >> 2));
LABEL_63:
        v36 = v80;
      }
LABEL_64:
      *(_DWORD *)(v37 + 4) = v38;
      if ( v38 > v36 )
        GConstructorMov<GFxButtonRecord>::ConstructArray(p: (char *)(*(_DWORD *)v37 + 84 * v80), count: v38 - v80);
      v40 = *(_DWORD *)(v37 + 4);
      if ( v34 < v40 - 1 )
        memmove(
          dst: (unsigned __int8 *)(84 * v34 + *(_DWORD *)v37 + 84),
          src: (unsigned __int8 *)(84 * v34 + *(_DWORD *)v37),
          count: 84 * (v40 - v34 - 1));
      v41 = *(_DWORD *)(this + 24) + 84 * v34;
      if ( v41 != 0 )
      {
        *(_DWORD *)v41 = 0;
        *(_DWORD *)(v41 + 4) = 0;
        *(_DWORD *)(v41 + 8) = 0;
        v81 = v89;
        v86 = v88;
        if ( v89 != 0 )
        {
          v42 = *(_DWORD *)(v41 + 4);
          v43 = v42 + v89;
          if ( v42 + v89 >= v42 )
          {
            HIDWORD(v64) = v43 + (v43 >> 2);
            LODWORD(v64) = v41;
            GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(
              this: (CMatQueuedMesh *)v41,
              pheapAddr: v64);
          }
          v62 = (_BYTE *)(*(_DWORD *)v41 + 156 * v42);
          *(_DWORD *)(v41 + 4) = v43;
          GConstructorMov<GFxFilterDesc>::ConstructArray(a1: v62, a2: v81, a3: v86);
        }
        *(float *)(v41 + 12) = v91;
        *(float *)(v41 + 16) = v92;
        *(float *)(v41 + 20) = v93;
        *(float *)(v41 + 24) = v94;
        *(float *)(v41 + 28) = v95;
        *(float *)(v41 + 32) = v96;
        qmemcpy((void *)(v41 + 36), v97, 38);
        *(_DWORD *)(v41 + 76) = v98;
        *(_BYTE *)(v41 + 80) = j;
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v88);
      v88 = nullptr;
      v89 = 0;
      v90 = 0;
      GMatrix2D::SetIdentity(this: &v91);
      GRenderer::Cxform::Cxform(this: v97);
      LODWORD(v97[8]) = 0x40000;
      j = 0;
      if ( GFxButtonRecord::Read(this: (int)&v88, (int)a2, a3: 34) == 0 )
        goto LABEL_75;
    }
    v39 = (void **)(84 * v36 + *(_DWORD *)v37 - 84);
    if ( v36 != v38 )
    {
      for ( i = -1; i != 0; --i )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v39);
        v39 -= 21;
      }
      v36 = v80;
    }
    v37 = this + 24;
    if ( v38 >= *(_DWORD *)(this + 32) >> 1 )
      goto LABEL_64;
    GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>::Reserve(
      this: (CUtlNoEscConversion *)v37,
      pheapAddr: (const CUtlNoEscConversion *)v37,
      newCapacity: v38);
    goto LABEL_63;
  }
  v88 = nullptr;
  v89 = 0;
  v90 = 0;
  GMatrix2D::SetIdentity(this: &v91);
  GRenderer::Cxform::Cxform(this: v97);
  LODWORD(v97[8]) = 0x40000;
  for ( j = 0; GFxButtonRecord::Read(this: (int)&v88, (int)a2, a3: 7) != 0; v4 = this )
  {
    v5 = 0;
    pos = 0;
    if ( *(_DWORD *)(v4 + 28) != 0 )
    {
      v6 = (_WORD *)(*(_DWORD *)(v4 + 24) + 72);
      do
      {
        if ( *v6 > LOWORD(v97[9]) )
          break;
        ++v5;
        v6 += 42;
      }
      while ( v5 < *(_DWORD *)(v4 + 28) );
      pos = v5;
    }
    v7 = *(_DWORD *)(v4 + 28);
    v8 = v4 + 24;
    v9 = v7 + 1;
    v78 = v7;
    if ( v7 + 1 >= v7 )
    {
      if ( v9 < *(_DWORD *)(v4 + 32) )
        goto LABEL_16;
      GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>::Reserve(
        this: (CUtlNoEscConversion *)v8,
        pheapAddr: (const CUtlNoEscConversion *)v8,
        newCapacity: v9 + (v9 >> 2));
    }
    else
    {
      v10 = (void **)(84 * v7 + *(_DWORD *)v8 - 84);
      for ( k = -1; k != 0; --k )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v10);
        v10 -= 21;
      }
      v8 = v4 + 24;
      if ( v9 < *(_DWORD *)(v4 + 32) >> 1 )
        GArrayDataBase<GFxButtonRecord,GAllocatorLH<GFxButtonRecord,258>,GArrayDefaultPolicy>::Reserve(
          this: (CUtlNoEscConversion *)v8,
          pheapAddr: (const CUtlNoEscConversion *)v8,
          newCapacity: v9);
    }
    v7 = v78;
LABEL_16:
    *(_DWORD *)(v8 + 4) = v9;
    if ( v9 > v7 )
    {
      v11 = *(_DWORD *)v8 + 84 * v78;
      for ( m = v9 - v78; m != 0; --m )
      {
        if ( v11 != 0 )
        {
          *(_DWORD *)v11 = 0;
          *(_DWORD *)(v11 + 4) = 0;
          *(_DWORD *)(v11 + 8) = 0;
          GMatrix2D::SetIdentity(this: (float *)(v11 + 12));
          GRenderer::Cxform::Cxform(this: (float *)(v11 + 36));
          *(_DWORD *)(v11 + 68) = 0x40000;
          *(_BYTE *)(v11 + 80) = 0;
        }
        v11 += 84;
      }
    }
    v13 = *(_DWORD *)(this + 28);
    if ( pos < v13 - 1 )
      memmove(
        dst: (unsigned __int8 *)(*(_DWORD *)(this + 24) + 84 * pos + 84),
        src: (unsigned __int8 *)(*(_DWORD *)(this + 24) + 84 * pos),
        count: 84 * (v13 - pos - 1));
    v14 = *(_DWORD *)(this + 24) + 84 * pos;
    if ( v14 != 0 )
    {
      *(_DWORD *)v14 = 0;
      *(_DWORD *)(v14 + 4) = 0;
      *(_DWORD *)(v14 + 8) = 0;
      v79 = v89;
      v83 = v88;
      if ( v89 != 0 )
      {
        v15 = *(_DWORD *)(v14 + 4);
        v16 = v15 + v89;
        if ( v15 + v89 >= v15 )
        {
          HIDWORD(v63) = v16 + (v16 >> 2);
          LODWORD(v63) = v14;
          GArrayDataBase<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::Reserve(
            this: (CMatQueuedMesh *)v14,
            pheapAddr: v63);
        }
        v61 = (_BYTE *)(*(_DWORD *)v14 + 156 * v15);
        *(_DWORD *)(v14 + 4) = v16;
        GConstructorMov<GFxFilterDesc>::ConstructArray(a1: v61, a2: v79, a3: v83);
      }
      *(float *)(v14 + 12) = v91;
      *(float *)(v14 + 16) = v92;
      *(float *)(v14 + 20) = v93;
      *(float *)(v14 + 24) = v94;
      *(float *)(v14 + 28) = v95;
      *(float *)(v14 + 32) = v96;
      qmemcpy((void *)(v14 + 36), v97, 38);
      *(_DWORD *)(v14 + 76) = v98;
      *(_BYTE *)(v14 + 80) = j;
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v88);
    v88 = nullptr;
    v89 = 0;
    v90 = 0;
    GMatrix2D::SetIdentity(this: &v91);
    GRenderer::Cxform::Cxform(this: v97);
    v3 = a2;
    LODWORD(v97[8]) = 0x40000;
    j = 0;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v88);
  v17 = (CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *)(v4 + 36);
  v18 = *(_DWORD *)(v4 + 40);
  v84 = &v17->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable;
  GArrayDataBase<GFxButtonAction,GAllocatorLH<GFxButtonAction,258>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: v17,
    a2: (const char *)v3,
    pheapAddr: v17,
    newSize: v18 + 1);
  if ( v18 + 1 > v18 )
  {
    v19 = *v84 + 16 * v18;
    v20 = (_DWORD *)(v19 + 12);
    for ( n = 1; n != 0; --n )
    {
      if ( v19 != 0 )
      {
        *(v20 - 2) = 0;
        *(v20 - 1) = 0;
        *v20 = 0;
      }
      v19 += 16;
      v20 += 4;
    }
  }
  v22 = (IShaderDeviceMgr *)v3[40].RefCount;
  if ( v22 == nullptr )
    v22 = (IShaderDeviceMgr *)&v3[2];
  GFxStream::GetTagEndPosition(this: v22, a2: v66, a3: v70);
  v24 = (tagBITMAPINFOHEADER *)v3[40].RefCount;
  v25 = &v3[2].__vftable;
  if ( v24 != nullptr )
    v25 = (_DWORD *)v3[40].RefCount;
  else
    v24 = (tagBITMAPINFOHEADER *)&v3[2];
  GFxButtonAction::Read(
    this: (_DWORD *)(*v84 + 16 * v84[1] - 16),
    result: v24,
    a3: 7,
    a: v23 + v25[12] - v25[13] - v25[11]);
}

//------------------------------------------------------------------------------
// Address: 0x101116F0
// Name: public: static class GASFunctionRef GASButtonCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
GString *__thiscall GASButtonCtorFunction::Register(GString *result, _BYTE *constructor, _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v3; // esi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v5)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v6; // eax
  GASCFunctionObject *v7; // edi
  GASCFunctionObject *v8; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  _EXCEPTION_RECORD *v12; // ebx
  _CONTEXT *Prototype; // eax
  _EXCEPTION_RECORD *v14; // eax
  _DWORD *v15; // eax
  int v16; // ebx
  GASValue *v17; // eax
  GASValue v19[4]; // [esp+Ch] [ebp-1Ch] BYREF
  _EXCEPTION_REGISTRATION_RECORD psc; // [esp+1Ch] [ebp-Ch] BYREF
  _DWORD *v21; // [esp+24h] [ebp-4h]
  _EXCEPTION_RECORD *constructora; // [esp+30h] [ebp+8h]

  v3 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  psc.Next = (_EXCEPTION_REGISTRATION_RECORD *)pgc;
  LOBYTE(psc.Handler) = 8;
  v5 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v6 = (GASCFunctionObject *)v5(a1: VersionMajor, a2: 56, a3: &pgc);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v6,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))CDummyMaterialSystem::EndBatch);
    v7->dwSize = (unsigned int)&GASButtonCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v7->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  *(_DWORD *)constructor = v8;
  constructor[8] = 0;
  *((_DWORD *)constructor + 1) = 0;
  MaxVal = v3[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v12 = (_EXCEPTION_RECORD *)v11(a1: MaxVal, a2: 88, a3: &pgc);
  if ( v12 != nullptr )
  {
    Prototype = (_CONTEXT *)GASGlobalContext::GetPrototype(this: v3, result: (vc_attributes::InvalidCheckAttribute *)1);
    v14 = GASButtonProto::GASButtonProto(this: v12, (ID3DXFont *)&psc, prototype: Prototype, constructor);
    constructora = v14;
  }
  else
  {
    constructora = nullptr;
    v14 = nullptr;
  }
  if ( v14 != nullptr )
    v14->ExceptionRecord = (_EXCEPTION_RECORD *)(((int)&v14->ExceptionRecord->ExceptionCode + 1) & 0x8FFFFFFF);
  GASGlobalContext::SetPrototype(a1: 9, a2: v14);
  v15 = v3[56].MaxVal + 16;
  HIBYTE(pgc) = 0;
  v16 = *v15;
  v21 = v15;
  v17 = GASValue::GASValue(this: v19, a2: (const struct GASFunctionRef *)constructor);
  (*(void (__thiscall **)(_DWORD *, _EXCEPTION_REGISTRATION_RECORD *, const char **, GASValue *, char *))(v16 + 40))(
    a1: v21,
    a2: &psc,
    a3: &v3[3].MaxVal,
    a4: v17,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v19);
  if ( constructora != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)constructora, a2: (int)constructor);
  return (GString *)constructor;
}

//------------------------------------------------------------------------------
// Address: 0x10112750
// Name: public: GASPrototype<class GASMovieClipLoader,class GASEnvironment>::GASPrototype<class GASMovieClipLoader,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASMovieClipLoader,GASEnvironment>::GASPrototype<GASMovieClipLoader,GASEnvironment>(
        GRenderer *this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v5; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  this->__vftable = (GRenderer_vtbl *)&GASMovieClipLoader::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(this->S3DParams.DisplayWidthCm) = &GASMovieClipLoader::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = 0;
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&this->S3DParams,
    (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    psc_4);
  *((_DWORD *)this + 14) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 68) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_BYTE *)this + 80) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 21) = 0;
  *(_QWORD *)&v5 = __PAIR64__(psc_8, (unsigned int)psc);
  this->__vftable = (GRenderer_vtbl *)&GASMovieClipLoaderProto::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(this->S3DParams.DisplayWidthCm) = &GASPrototype<GASMovieClipLoader,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 14) = &GASPrototype<GASMovieClipLoader,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 56),
    pthis: (CMaterialVar *)this,
    psc: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101127D0
// Name: public: virtual void GASPrototype<class GASBooleanObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASBooleanObject,GASEnvironment>::AddInterface(
        FontVertex_t *this,
        const Vector2D *psc,
        const Vector2D *index)
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x101127E0
// Name: protected: void GASPrototype<class GASMovieClipLoader,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10112860
// Name: protected: void GASPrototype<class GASButtonObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10112900
// Name: protected: virtual void GASPrototype<class GASMovieClipLoader,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASMovieClipLoader,GASEnvironment>::Finalize_GC(GASObject *this)
{
  void **v2; // eax

  v2 = *((void ***)this + 21);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 21));
  }
  GHashSetBase<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GASMovieClipLoader::ProgressDesc,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::Clear(this: (void **)this + 13);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10113210
// Name: protected: virtual void GASPrototype<class GASLoadVarsObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASLoadVarsObject,GASEnvironment>::Finalize_GC(
        GRenderer::BlurFilterParams *this,
        const GRenderer::BlurFilterParams *a2)
{
  void **v3; // eax

  v3 = *((void ***)this + 25);
  if ( v3 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 25));
  }
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x10113530
// Name: protected: void GASPrototype<class GASLoadVarsObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10113730
// Name: public: GASPrototype<class GASLoadVarsObject,class GASEnvironment>::GASPrototype<class GASLoadVarsObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GRenderer::DistanceFieldParams *__thiscall GASPrototype<GASLoadVarsObject,GASEnvironment>::GASPrototype<GASLoadVarsObject,GASEnvironment>(
        int this,
        GRenderer::DistanceFieldParams *result,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)result);
  *(_DWORD *)this = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASLoadVarsObject::`vftable'{for `GASObjectInterface'};
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
    psc_4);
  *(double *)(this + 56) = -1.0;
  *(double *)(this + 64) = -1.0;
  *(_DWORD *)(this + 72) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 84) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_BYTE *)(this + 96) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)result);
  *(_DWORD *)this = &GASLoadVarsProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASLoadVarsProto::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 72) = &GASLoadVarsProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 72),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return (GRenderer::DistanceFieldParams *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10113A60
// Name: protected: virtual void GASPrototype<class GASTextSnapshotObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
int __stdcall GASPrototype<GASTextSnapshotObject,GASEnvironment>::ExecuteForEachChild_GC(int a1)
{
  int result; // eax

  result = a1;
  switch ( a1 )
  {
    case 0:
      result = GASPrototype<GASLoadVarsObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>();
      break;
    case 1:
      result = GASPrototype<GASNumberObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>();
      break;
    case 2:
      result = GASPrototype<GASTextSnapshotObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>();
      break;
    case 3:
      result = GASPrototype<GASLoadVarsObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>();
      break;
    case 4:
      result = GASPrototype<GASLoadVarsObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>();
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101146D0
// Name: public: GASPrototype<class GASStageObject,class GASEnvironment>::GASPrototype<class GASStageObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::IHTMLEvents *__thiscall GASPrototype<GASStageObject,GASEnvironment>::GASPrototype<GASStageObject,GASEnvironment>(
        vgui::IHTMLEvents *this,
        vgui::IHTMLEvents *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)psc);
  this->__vftable = (vgui::IHTMLEvents_vtbl *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASStageObject::`vftable'{for `GASObjectInterface'};
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 4), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  this->__vftable = (vgui::IHTMLEvents_vtbl *)&GASPrototype<GASStageObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASStageObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPrototype<GASStageObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 13),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10117690
// Name: public: GASPrototype<class GASAsBroadcaster,class GASEnvironment>::GASPrototype<class GASAsBroadcaster,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall GASPrototype<GASAsBroadcaster,GASEnvironment>::GASPrototype<GASAsBroadcaster,GASEnvironment>(
        CMaterialVar *pthis,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *a3,
        unsigned int a4)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject(this: (GASObject *)pthis, a2: (struct GASStringContext *)psc);
  pthis->__vftable = (CMaterialVar_vtbl *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(pthis->m_VecVal.y) = &GASAsBroadcaster::`vftable'{for `GASObjectInterface'};
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)&pthis->m_VecVal.y, psc, psc_4: a3);
  *((_DWORD *)pthis + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)pthis + 64) = 0;
  *((_DWORD *)pthis + 14) = 0;
  *((_DWORD *)pthis + 15) = 0;
  *((_BYTE *)pthis + 76) = 0;
  *((_DWORD *)pthis + 17) = 0;
  *((_DWORD *)pthis + 18) = 0;
  *((_DWORD *)pthis + 20) = 0;
  *(_QWORD *)&v6 = __PAIR64__(a4, (unsigned int)psc);
  pthis->__vftable = (CMaterialVar_vtbl *)&GASAsBroadcasterProto::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(pthis->m_VecVal.y) = &GASPrototype<GASAsBroadcaster,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)pthis + 13) = &GASPrototype<GASAsBroadcaster,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)pthis + 52),
    pthis,
    psc: v6);
  return pthis;
}

//------------------------------------------------------------------------------
// Address: 0x10119E10
// Name: public: virtual bool GASPrototype<class GASTextFormatObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASTextFormatObject,GASEnvironment>::GetMemberRaw(
        D3DXVECTOR3 *this,
        _IMAGE_SYMBOL_EX *psc,
        _IMAGE_SYMBOL_EX *isConstructor2,
        GASValue *a4)
{
  float v4; // esi
  unsigned int Short; // ecx
  bool v8; // zf
  float v9; // esi
  bool v10; // zf
  D3DXVECTOR3 *v12; // [esp+Ch] [ebp-4h]
  bool isConstructor2a; // [esp+1Ch] [ebp+Ch]

  v4 = *(float *)&psc->N.Name.Short;
  Short = isConstructor2->N.Name.Short;
  v12 = this;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    Short = isConstructor2->N.Name.Short;
    v8 = *(_DWORD *)(*(_DWORD *)(LODWORD(v4) + 328) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v8 = *(_DWORD *)(LODWORD(v4) + 328) == Short;
  }
  isConstructor2a = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 26,
             a2: (struct GASObject *)this - 2,
             name: psc,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  v9 = *(float *)&psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(LODWORD(v9) + 324) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v10 = *(_DWORD *)(LODWORD(v9) + 324) == Short;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 26,
             a2: (struct GASObject *)this - 2,
             name: psc,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  else
    return (unsigned __int8)GASObject::GetMemberRaw(
                              (CTSQueue<CFunctor *,0,1> *)this,
                              (CTSQueue<CFunctor *,0,1>::Node_t *)psc);
}

//------------------------------------------------------------------------------
// Address: 0x10119ED0
// Name: public: virtual void GASPrototype<class GASTextFormatObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTextFormatObject,GASEnvironment>::AddInterface(
        int this,
        IMaterialVar *const *a2,
        int a3,
        int a4)
{
  GASPrototypeBase::AddInterface(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 104),
    psc: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10119EE0
// Name: public: virtual bool GASPrototype<class GASTextFormatObject,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASTextFormatObject,GASEnvironment>::DoesImplement(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *this,
        unsigned int penv,
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *prototype)
{
  if ( this == prototype )
    return 1;
  else
    return (unsigned __int8)GASPrototypeBase::DoesImplement(this: this + 5, penv);
}

//------------------------------------------------------------------------------
// Address: 0x10119F20
// Name: protected: virtual void GASPrototype<class GASTextFormatObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTextFormatObject,GASEnvironment>::Finalize_GC(D3DXVECTOR3 *this)
{
  void **v2; // eax

  v2 = *((void ***)this + 37);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 37));
  }
  (**((void (__thiscall ***)(char *, _DWORD))this + 13))(a1: (char *)this + 52, a2: 0);
  (**((void (__thiscall ***)(D3DXVECTOR3 *, _DWORD))this + 24))(a1: this + 8, a2: 0);
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10119F80
// Name: protected: void GASPrototype<class GASTextFormatObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011A000
// Name: protected: void GASPrototype<class GASTextFormatObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011A070
// Name: protected: void GASPrototype<class GASTextFormatObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011A100
// Name: protected: void GASPrototype<class GASTextFormatObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011A150
// Name: protected: void GASPrototype<class GASTextFormatObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011C400
// Name: protected: virtual void GASPrototype<class GASTextFormatObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
int __stdcall GASPrototype<GASTextFormatObject,GASEnvironment>::ExecuteForEachChild_GC(int operation)
{
  int result; // eax

  result = operation;
  switch ( operation )
  {
    case 0:
      result = GASPrototype<GASTextFormatObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>();
      break;
    case 1:
      result = GASPrototype<GASTextFormatObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>();
      break;
    case 2:
      result = GASPrototype<GASTextFormatObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>();
      break;
    case 3:
      result = GASPrototype<GASTextFormatObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>();
      break;
    case 4:
      result = GASPrototype<GASTextFormatObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>();
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011D760
// Name: public: virtual bool GASPrototype<class GASNumberObject,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASNumberObject,GASEnvironment>::DoesImplement(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *this,
        const GRenderer::DistanceFieldParams *result,
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *prototype)
{
  if ( this == prototype )
    return 1;
  else
    return (unsigned __int8)GASPrototypeBase::DoesImplement(this: this + 3, penv: (unsigned int)result);
}

//------------------------------------------------------------------------------
// Address: 0x1011D790
// Name: protected: void GASPrototype<class GASLoadVarsObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011D7E0
// Name: protected: void GASPrototype<class GASLoadVarsObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011D870
// Name: public: GASPrototype<class GASTextSnapshotObject,class GASEnvironment>::GASPrototype<class GASTextSnapshotObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
D3DXQUATERNION *__thiscall GASPrototype<GASTextSnapshotObject,GASEnvironment>::GASPrototype<GASTextSnapshotObject,GASEnvironment>(
        D3DXQUATERNION *this,
        D3DXQUATERNION *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)psc);
  LODWORD(this->x) = &GASTextSnapshotObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A6058;
  GFxStaticTextSnapshotData::GFxStaticTextSnapshotData(
    this: (GPtr<GFxAmpViewStats> *)this + 13,
    a2: (GFxAmpViewStats *)DWORD2(v6));
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 1), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *((_DWORD *)this + 18) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 84) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_BYTE *)this + 96) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 25) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  LODWORD(this->x) = &GASTextSnapshotProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASTextSnapshotProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 18) = &GASTextSnapshotProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)this
  + 3,
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011D990
// Name: protected: virtual void GASPrototype<class GASTextSnapshotObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTextSnapshotObject,GASEnvironment>::Finalize_GC(GASObject *this)
{
  void **v2; // eax
  unsigned int v3; // [esp+0h] [ebp-4h]

  v2 = *((void ***)this + 25);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 25));
  }
  GFxStaticTextSnapshotData::~GFxStaticTextSnapshotData(this: (GPtr<GFxAmpViewStats> *)this + 13, a2: v3);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011F900
// Name: public: virtual bool GASPrototype<class GASDate,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASDate,GASEnvironment>::GetMemberRaw(
        CTSQueue<CFunctor *,0,1> *this,
        _IMAGE_SYMBOL_EX *name,
        _IMAGE_SYMBOL_EX *isConstructor2,
        GASValue *a4)
{
  unsigned int Short; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  unsigned int v9; // esi
  bool v10; // zf
  CTSQueue<CFunctor *,0,1> *v12; // [esp+Ch] [ebp-4h]
  bool isConstructor2a; // [esp+1Ch] [ebp+Ch]

  Short = name->N.Name.Short;
  v7 = isConstructor2->N.Name.Short;
  v12 = this;
  if ( name->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v7 = isConstructor2->N.Name.Short;
    v8 = *(_DWORD *)(*(_DWORD *)(Short + 328) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v8 = *(_DWORD *)(Short + 328) == v7;
  }
  isConstructor2a = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 22,
             a2: (struct GASObject *)this - 2,
             name,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  v9 = name->N.Name.Short;
  if ( name->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 324) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v10 = *(_DWORD *)(v9 + 324) == v7;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 22,
             a2: (struct GASObject *)this - 2,
             name,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  else
    return (unsigned __int8)GASObject::GetMemberRaw(this, psc: (CTSQueue<CFunctor *,0,1>::Node_t *)name);
}

//------------------------------------------------------------------------------
// Address: 0x1011F9C0
// Name: public: virtual void GASPrototype<class GASDate,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASDate,GASEnvironment>::AddInterface(vgui::IPanel *this, int psc, const char *index)
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x1011F9D0
// Name: public: virtual bool GASPrototype<class GASDate,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASDate,GASEnvironment>::DoesImplement(
        int this,
        unsigned int penv,
        int prototype)
{
  if ( this == prototype )
    return 1;
  else
    return (unsigned __int8)GASPrototypeBase::DoesImplement(
                              this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 104),
                              penv);
}

//------------------------------------------------------------------------------
// Address: 0x1011FDA0
// Name: protected: virtual void GASPrototype<class GASDate,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASDate,GASEnvironment>::Finalize_GC(
        vgui::IPanel *this,
        unsigned int a2,
        bool a3,
        bool a4)
{
  void **v5; // eax

  v5 = *((void ***)this + 33);
  if ( v5 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v5);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 33));
  }
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x1011FDE0
// Name: protected: void GASPrototype<class GASDate,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011FE60
// Name: protected: void GASPrototype<class GASDate,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011FED0
// Name: protected: void GASPrototype<class GASDate,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1011FF60
// Name: protected: void GASPrototype<class GASDate,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101200F0
// Name: protected: void GASPrototype<class GASDate,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101207F0
// Name: public: GASPrototype<class GASDate,class GASEnvironment>::GASPrototype<class GASDate,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::IPanel *__thiscall GASPrototype<GASDate,GASEnvironment>::GASPrototype<GASDate,GASEnvironment>(
        vgui::IPanel *this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  this->__vftable = (vgui::IPanel_vtbl *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASDate::`vftable'{for `GASObjectInterface'};
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 4), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *((_DWORD *)this + 26) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 116) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_BYTE *)this + 128) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 33) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  this->__vftable = (vgui::IPanel_vtbl *)&GASDateProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASDate,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 26) = &GASDateProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 26),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101208E0
// Name: protected: virtual void GASPrototype<class GASDate,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASPrototype<GASDate,GASEnvironment>::ExecuteForEachChild_GC(
        vgui::IPanel *this@<ecx>,
        unsigned int operation,
        KeyValues *operation_4,
        unsigned int operation_8)
{
  switch ( operation )
  {
    case 0u:
      GASPrototype<GASDate,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: this);
      break;
    case 1u:
      GASPrototype<GASDate,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(a1: this);
      break;
    case 2u:
      GASPrototype<GASDate,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(a1: this);
      break;
    case 3u:
      GASPrototype<GASDate,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(a1: this);
      break;
    case 4u:
      GASPrototype<GASDate,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(a1: this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120D90
// Name: public: virtual GASPrototype<class GASSharedObject,class GASEnvironment>::~GASPrototype<class GASSharedObject,class GASEnvironment>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASSharedObject,GASEnvironment>::~GASPrototype<GASSharedObject,GASEnvironment>(
        GASObject *this)
{
  GASPrototypeBase *v2; // ecx
  volatile LONG *v3; // edi
  volatile LONG *v4; // edi

  v2 = (GASPrototypeBase *)this + 15;
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASSharedObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASSharedObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  v2->__vftable = (IUnknown_vtbl *)&GASSharedObjectProto::`vftable';
  GASPrototypeBase::~GASPrototypeBase(this: v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 7) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = (volatile LONG *)(*((_DWORD *)this + 13) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  GASObject::~GASObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x101211D0
// Name: protected: virtual void GASPrototype<class GASSharedObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASSharedObject,GASEnvironment>::Finalize_GC(GASObject *this)
{
  void **v2; // eax
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi

  v2 = *((void ***)this + 22);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 22));
  }
  v3 = (volatile LONG *)(*((_DWORD *)this + 13) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = (volatile LONG *)(*(_DWORD *)(this + 7) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10121250
// Name: protected: void GASPrototype<class GASBitmapData,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10121400
// Name: protected: void GASPrototype<class GASTextFieldObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10121CD0
// Name: public: GASPrototype<class GASSharedObject,class GASEnvironment>::GASPrototype<class GASSharedObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
D3DXVECTOR2 *__thiscall GASPrototype<GASSharedObject,GASEnvironment>::GASPrototype<GASSharedObject,GASEnvironment>(
        D3DXVECTOR2 *this,
        D3DXVECTOR2 *result,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)result);
  LODWORD(this->x) = &GASSharedObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASSharedObject::`vftable'{for `GASObjectInterface'};
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 52));
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)(this + 7));
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 2),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
    psc_4: psc);
  *((_DWORD *)this + 15) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 72) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_BYTE *)this + 84) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 22) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)result);
  LODWORD(this->x) = &GASSharedObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASSharedObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 15) = &GASSharedObjectProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 60),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10123570
// Name: protected: void GASPrototype<class GASPointObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10124410
// Name: public: GASPrototype<class GASTransformObject,class GASEnvironment>::GASPrototype<class GASTransformObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASPrototype<GASTransformObject,GASEnvironment>::GASPrototype<GASTransformObject,GASEnvironment>(
        int this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  *(_DWORD *)this = &GASTransformObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASTransformObject::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 68) = 0;
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 16), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *(_DWORD *)(this + 72) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 84) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_BYTE *)(this + 96) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  *(_DWORD *)this = &stru_102A69F0.m_pElements;
  *(_DWORD *)(this + 16) = &GASTransformProto::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 72) = &stru_102A69F0.m_Size;
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 72),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101244A0
// Name: public: virtual bool GASPrototype<class GASTransformObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASPrototype<GASTransformObject,GASEnvironment>::GetMemberRaw(
        vgui::ISurface *this@<ecx>,
        _IMAGE_SYMBOL_EX *psc,
        _IMAGE_SYMBOL_EX *name,
        GASValue *val,
        int isConstructor2,
        int a6,
        Color a7,
        Color a8,
        bool a9,
        int a10,
        int a11,
        int a12)
{
  unsigned int Short; // esi
  unsigned int v15; // ecx
  bool v16; // zf
  unsigned int v17; // esi
  bool v18; // zf
  vgui::ISurface *v19; // [esp+Ch] [ebp-4h]
  bool isConstructor2a; // [esp+1Ch] [ebp+Ch]

  Short = psc->N.Name.Short;
  v15 = name->N.Name.Short;
  v19 = this;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v15 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v19;
    }
    v15 = name->N.Name.Short;
    v16 = *(_DWORD *)(*(_DWORD *)(Short + 328) + 4) == *(_DWORD *)(name->N.Name.Short + 4);
  }
  else
  {
    v16 = *(_DWORD *)(Short + 328) == v15;
  }
  isConstructor2a = v16;
  if ( v16 )
    goto LABEL_14;
  v17 = psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v15 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v19;
    }
    v18 = *(_DWORD *)(*(_DWORD *)(v17 + 324) + 4) == *(_DWORD *)(name->N.Name.Short + 4);
  }
  else
  {
    v18 = *(_DWORD *)(v17 + 324) == v15;
  }
  if ( v18 )
LABEL_14:
    GASPrototypeBase::GetMemberRawConstructor(
      this: (GASPrototypeBase *)this + 14,
      a2: (struct GASObject *)this - 2,
      name: psc,
      key: name,
      a5: val,
      a6: isConstructor2a);
  else
    GASObject::GetMemberRaw((CTSQueue<CFunctor *,0,1> *)this, (CTSQueue<CFunctor *,0,1>::Node_t *)psc);
}

//------------------------------------------------------------------------------
// Address: 0x10124560
// Name: protected: void GASPrototype<class GASTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(
        GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *this)
{
  int v2; // eax
  unsigned int v3; // ebx
  unsigned int i; // esi
  int v5; // ecx
  int v6; // eax
  void (__stdcall **v7)(int); // edx

  GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>();
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)this + 19);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)this + 22);
  v2 = *((_DWORD *)this + 25);
  if ( v2 != 0 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    for ( i = 0; i < v3; ++i )
    {
      v5 = *(_DWORD *)(**((_DWORD **)this + 25) + 4 * i);
      if ( v5 != 0 )
      {
        v6 = ++*(_DWORD *)(v5 + 8);
        if ( (v6 & 0x70000000) != 0 )
        {
          v7 = *(void (__stdcall ***)(int))v5;
          *(_DWORD *)(v5 + 8) = v6 & 0x8FFFFFFF;
          (*v7)(a1: 2);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101245D0
// Name: protected: void GASPrototype<class GASTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(
        GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *this)
{
  int v2; // eax
  unsigned int v3; // ebx
  unsigned int i; // esi
  int v5; // ecx

  GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>();
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)this + 19);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)this + 22);
  v2 = *((_DWORD *)this + 25);
  if ( v2 != 0 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    for ( i = 0; i < v3; ++i )
    {
      v5 = *(_DWORD *)(**((_DWORD **)this + 25) + 4 * i);
      if ( v5 != 0 && (--*(_DWORD *)(v5 + 8) & 0x70000000) != 0x10000000 )
      {
        *(_DWORD *)(v5 + 8) = *(_DWORD *)(v5 + 8) & 0x8FFFFFFF | 0x10000000;
        (**(void (__thiscall ***)(int, int))v5)(a1: v5, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124650
// Name: protected: void GASPrototype<class GASTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(
        GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *this)
{
  int v2; // eax
  unsigned int v3; // ebx
  unsigned int i; // esi
  int v5; // ecx
  int v6; // eax
  unsigned int v7; // eax
  int v8; // [esp-Ch] [ebp-10h]

  GASTransformObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>();
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)this + 19);
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)this + 22);
  v2 = *((_DWORD *)this + 25);
  if ( v2 != 0 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    for ( i = 0; i < v3; ++i )
    {
      v5 = *(_DWORD *)(**((_DWORD **)this + 25) + 4 * i);
      if ( v5 != 0 )
      {
        v6 = *(_DWORD *)(v5 + 8);
        if ( (v6 & 0x70000000) == 0x10000000 )
        {
          if ( (v6 & 0xFFFFFFF) != 0 )
          {
            v7 = v6 & 0x8FFFFFFF;
            v8 = 2;
          }
          else
          {
            v7 = v6 & 0x8FFFFFFF | 0x20000000;
            v8 = 4;
          }
          *(_DWORD *)(v5 + 8) = v7;
          (**(void (__thiscall ***)(int, int))v5)(a1: v5, a2: v8);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101246D0
// Name: protected: virtual void GASPrototype<class GASTransformObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTransformObject,GASEnvironment>::Finalize_GC(vgui::ISurface *this)
{
  void **v2; // eax
  GFxCharacterHandle *v3; // esi

  v2 = *((void ***)this + 25);
  if ( v2 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 25));
  }
  *((_DWORD *)this + 13) = 0;
  v3 = *((GFxCharacterHandle **)this + 14);
  if ( v3 != nullptr )
  {
    *v3 = (GFxCharacterHandle)((char *)*v3 - 1);
    if ( (int)*v3 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v3);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    }
  }
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10124730
// Name: protected: void GASPrototype<class GASTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101247A0
// Name: protected: void GASPrototype<class GASTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10124810
// Name: public: virtual GASPrototype<class GASTransformObject,class GASEnvironment>::~GASPrototype<class GASTransformObject,class GASEnvironment>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASPrototype<GASTransformObject,GASEnvironment>::~GASPrototype<GASTransformObject,GASEnvironment>(
        vgui::ISurface *this@<ecx>,
        int a2@<edi>)
{
  GASPrototypeBase *v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  GFxCharacterHandle *v7; // edi

  v3 = (GASPrototypeBase *)(this + 18);
  this->__vftable = (vgui::ISurface_vtbl *)&stru_102A69F0.m_pElements;
  *((_DWORD *)this + 4) = &GASTransformProto::`vftable'{for `GASObjectInterface'};
  v3->__vftable = (IUnknown_vtbl *)&stru_102A69F0.m_Size;
  GASPrototypeBase::~GASPrototypeBase(this: v3);
  v4 = *((_DWORD *)this + 17);
  if ( v4 != 0 )
    GRefCountBaseGC<323>::Release(a1: v4, a2);
  v5 = *((_DWORD *)this + 16);
  if ( v5 != 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2);
  v6 = *((_DWORD *)this + 15);
  if ( v6 != 0 )
    GRefCountBaseGC<323>::Release(a1: v6, a2);
  v7 = *((GFxCharacterHandle **)this + 14);
  if ( v7 != nullptr )
  {
    *v7 = (GFxCharacterHandle)((char *)*v7 - 1);
    if ( (int)*v7 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v7);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
    }
  }
  GASObject::~GASObject((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10124AE0
// Name: protected: virtual void GASPrototype<class GASTransformObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASTransformObject,GASEnvironment>::ExecuteForEachChild_GC(
        GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *this,
        const FontVertex_t *result)
{
  switch ( (unsigned int)result )
  {
    case 0u:
      GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
      break;
    case 1u:
      GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
      break;
    case 2u:
      GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
      break;
    case 3u:
      GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
      break;
    case 4u:
      GASPrototype<GASTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126A80
// Name: public: GASPrototype<class GASMatrixObject,class GASEnvironment>::GASPrototype<class GASMatrixObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASMatrixObject,GASEnvironment>::GASPrototype<GASMatrixObject,GASEnvironment>(
        FlashArrayVisitor *this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v5; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  this->__vftable = (FlashArrayVisitor_vtbl *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASMatrixObject::`vftable'{for `GASObjectInterface'};
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16),
    (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    psc_4);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v5 = __PAIR64__(psc_8, (unsigned int)psc);
  this->__vftable = (FlashArrayVisitor_vtbl *)&GASMatrixProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMatrixObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPrototype<GASMatrixObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 52),
    pthis: (CMaterialVar *)this,
    psc: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101274B0
// Name: protected: virtual void GASPrototype<class GASObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASObject,GASEnvironment>::Finalize_GC(_D3DXMATRIXA16 *this, _D3DCOLORVALUE *result)
{
  void **v3; // eax

  v3 = *((void ***)this + 20);
  if ( v3 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 20));
  }
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x101274F0
// Name: protected: void GASPrototype<class GASRectangleObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10127FA0
// Name: public: GASPrototype<class GASPointObject,class GASEnvironment>::GASPrototype<class GASPointObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::ISurface *__thiscall GASPrototype<GASPointObject,GASEnvironment>::GASPrototype<GASPointObject,GASEnvironment>(
        vgui::ISurface *this,
        vgui::ISurface *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)psc);
  this->__vftable = (vgui::ISurface_vtbl *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPointObject::`vftable'{for `GASObjectInterface'};
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 4), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  this->__vftable = (vgui::ISurface_vtbl *)&GASPointProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPointProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPointProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 13),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10128140
// Name: protected: virtual void GASPrototype<class GASAmpMarker,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void **__thiscall GASPrototype<GASAmpMarker,GASEnvironment>::ExecuteForEachChild_GC(
        vgui::IHTMLEvents *this,
        void **operation)
{
  void **result; // eax

  result = operation;
  switch ( (unsigned int)operation )
  {
    case 0u:
      result = (void **)GASPrototype<GASStageObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>();
      break;
    case 1u:
      result = (void **)GASPrototype<GASPointObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>();
      break;
    case 2u:
      result = (void **)GASPrototype<GASMatrixObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>();
      break;
    case 3u:
      result = (void **)GASPrototype<GASMath,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>();
      break;
    case 4u:
      result = (void **)GASPrototype<GASRectangleObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>();
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101282E0
// Name: public: virtual void GASPrototype<class GASIme,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GASPrototype<GASIme,GASEnvironment>::AddInterface(vgui::IHTML *result, int psc)
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x1012AC00
// Name: public: GASPrototype<class GASRectangleObject,class GASEnvironment>::GASPrototype<class GASRectangleObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::ISurface *__thiscall GASPrototype<GASRectangleObject,GASEnvironment>::GASPrototype<GASRectangleObject,GASEnvironment>(
        vgui::ISurface *this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  this->__vftable = (vgui::ISurface_vtbl *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A6FF8;
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 4), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  this->__vftable = (vgui::ISurface_vtbl *)&GASRectangleProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASRectangleProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASRectangleProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 13),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012B590
// Name: public: virtual bool GASPrototype<class GASColorTransformObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASColorTransformObject,GASEnvironment>::GetMemberRaw(
        CTSQueue<CFunctor *,0,1> *this,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        _IMAGE_SYMBOL_EX *key,
        GASValue *a4)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // esi
  unsigned int Short; // ecx
  bool v8; // zf
  CTSQueue<CFunctor *,0,1>::Node_t *v9; // esi
  bool v10; // zf
  CTSQueue<CFunctor *,0,1> *v12; // [esp+Ch] [ebp-4h]
  bool keya; // [esp+1Ch] [ebp+Ch]

  pNext = psc->pNext;
  Short = key->N.Name.Short;
  v12 = this;
  if ( LOBYTE(psc->elem) <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    Short = key->N.Name.Short;
    v8 = pNext[41].pNext->elem == *(CFunctor **)(key->N.Name.Short + 4);
  }
  else
  {
    v8 = pNext[41].pNext == (CTSQueue<CFunctor *,0,1>::Node_t *)Short;
  }
  keya = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 17,
             a2: (struct GASObject *)this - 2,
             name: (_IMAGE_SYMBOL_EX *)psc,
             key,
             a5: a4,
             a6: keya);
  v9 = psc->pNext;
  if ( LOBYTE(psc->elem) <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v10 = v9[40].elem->m_nUserID == *(_DWORD *)(key->N.Name.Short + 4);
  }
  else
  {
    v10 = v9[40].elem == (CFunctor *)Short;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 17,
             a2: (struct GASObject *)this - 2,
             name: (_IMAGE_SYMBOL_EX *)psc,
             key,
             a5: a4,
             a6: keya);
  else
    return (unsigned __int8)GASObject::GetMemberRaw(this, psc);
}

//------------------------------------------------------------------------------
// Address: 0x1012B650
// Name: public: virtual void GASPrototype<class GASColorTransformObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASColorTransformObject,GASEnvironment>::AddInterface(
        vgui::ISurface *this,
        vgui::IHTMLEvents *psc,
        unsigned int index)
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x1012B660
// Name: public: virtual bool GASPrototype<class GASColorTransformObject,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASColorTransformObject,GASEnvironment>::DoesImplement(
        int this,
        unsigned int penv,
        int a3)
{
  if ( this == a3 )
    return 1;
  else
    return (unsigned __int8)GASPrototypeBase::DoesImplement(
                              this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 84),
                              penv);
}

//------------------------------------------------------------------------------
// Address: 0x1012BA20
// Name: protected: virtual void GASPrototype<class GASColorTransformObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASColorTransformObject,GASEnvironment>::Finalize_GC(vgui::ISurface *this, int a2, int a3)
{
  void **v4; // eax

  v4 = *((void ***)this + 28);
  if ( v4 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v4);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 28));
  }
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x1012BE30
// Name: protected: void GASPrototype<class GASColorTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012BEB0
// Name: protected: void GASPrototype<class GASColorTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012BF20
// Name: protected: void GASPrototype<class GASColorTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012BFA0
// Name: protected: void GASPrototype<class GASColorTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012BFF0
// Name: protected: void GASPrototype<class GASColorTransformObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012C240
// Name: public: GASPrototype<class GASColorTransformObject,class GASEnvironment>::GASPrototype<class GASColorTransformObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASPrototype<GASColorTransformObject,GASEnvironment>::GASPrototype<GASColorTransformObject,GASEnvironment>(
        int this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  *(_DWORD *)this = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASColorTransformObject::`vftable'{for `GASObjectInterface'};
  GRenderer::Cxform::Cxform(this: (float *)(this + 52));
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 16), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *(_DWORD *)(this + 84) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 96) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_BYTE *)(this + 108) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 112) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  *(_DWORD *)this = &GASColorTransformProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASPrototype<GASColorTransformObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 84) = &GASPrototype<GASColorTransformObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 84),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012C630
// Name: protected: virtual void GASPrototype<class GASColorTransformObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASColorTransformObject,GASEnvironment>::ExecuteForEachChild_GC(
        vgui::ISurface *this,
        unsigned int operation)
{
  const GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *savedregs; // [esp+0h] [ebp+0h]

  switch ( operation )
  {
    case 0u:
      GASPrototype<GASColorTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(
        (GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *)this,
        a2: savedregs);
      break;
    case 1u:
      GASPrototype<GASColorTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(
        (GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *)this,
        a2: savedregs);
      break;
    case 2u:
      GASPrototype<GASColorTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(
        (GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *)this,
        a2: savedregs);
      break;
    case 3u:
      GASPrototype<GASColorTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(
        (GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *)this,
        a2: savedregs);
      break;
    case 4u:
      GASPrototype<GASColorTransformObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(
        (GArrayDataBase<GTexture::ChangeHandler *,GAllocatorGH<GTexture::ChangeHandler *,2>,GArrayDefaultPolicy> *)this,
        a2: savedregs);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DC90
// Name: public: virtual bool GASPrototype<class GASSelection,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASSelection,GASEnvironment>::DoesImplement(
        D3DXVECTOR2_16F *this,
        const D3DXCOLOR *penv,
        D3DXVECTOR2_16F *prototype)
{
  if ( this != prototype )
    GASPrototypeBase::DoesImplement(
      this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 13),
      (unsigned int)penv);
}

//------------------------------------------------------------------------------
// Address: 0x1012E1A0
// Name: public: virtual bool GASPrototype<class GASObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASObject,GASEnvironment>::GetMemberRaw(
        int this,
        _IMAGE_SYMBOL_EX *result,
        _IMAGE_SYMBOL_EX *isConstructor2,
        int *val)
{
  unsigned int Short; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  unsigned int v9; // esi
  bool v10; // zf
  int v12; // [esp+Ch] [ebp-4h]
  bool isConstructor2a; // [esp+1Ch] [ebp+Ch]

  Short = result->N.Name.Short;
  v7 = isConstructor2->N.Name.Short;
  v12 = this;
  if ( result->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v7 = isConstructor2->N.Name.Short;
    v8 = *(_DWORD *)(*(_DWORD *)(Short + 328) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v8 = *(_DWORD *)(Short + 328) == v7;
  }
  isConstructor2a = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(this + 36),
             a2: (struct GASObject *)(this - 16),
             name: result,
             key: isConstructor2,
             a5: (GASValue *)val,
             a6: isConstructor2a);
  v9 = result->N.Name.Short;
  if ( result->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 324) + 4) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v10 = *(_DWORD *)(v9 + 324) == v7;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(this + 36),
             a2: (struct GASObject *)(this - 16),
             name: result,
             key: isConstructor2,
             a5: (GASValue *)val,
             a6: isConstructor2a);
  else
    return (unsigned __int8)GASObject::GetMemberRaw(
                              (CTSQueue<CFunctor *,0,1> *)this,
                              psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result);
}

//------------------------------------------------------------------------------
// Address: 0x1012E610
// Name: protected: void GASPrototype<class GASMatrixObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012E680
// Name: protected: void GASPrototype<class GASMath,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012E6D0
// Name: protected: void GASPrototype<class GASStageObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012EDC0
// Name: public: virtual bool GASPrototype<class GASMovieClipObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASMovieClipObject,GASEnvironment>::GetMemberRaw(
        vgui::ISurface *this,
        _IMAGE_SYMBOL_EX *psc,
        _IMAGE_SYMBOL_EX *name,
        GASValue *a4)
{
  unsigned int Short; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  unsigned int v9; // esi
  bool v10; // zf
  vgui::ISurface *v11; // [esp+Ch] [ebp-4h]
  bool isConstructor2; // [esp+1Ch] [ebp+Ch]

  Short = psc->N.Name.Short;
  v7 = name->N.Name.Short;
  v11 = this;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v11;
    }
    v7 = name->N.Name.Short;
    v8 = *(_DWORD *)(*(_DWORD *)(Short + 328) + 4) == *(_DWORD *)(name->N.Name.Short + 4);
  }
  else
  {
    v8 = *(_DWORD *)(Short + 328) == v7;
  }
  isConstructor2 = v8;
  if ( v8 )
    goto LABEL_14;
  v9 = psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v11;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 324) + 4) == *(_DWORD *)(name->N.Name.Short + 4);
  }
  else
  {
    v10 = *(_DWORD *)(v9 + 324) == v7;
  }
  if ( v10 )
LABEL_14:
    GASPrototypeBase::GetMemberRawConstructor(
      this: (GASPrototypeBase *)this + 11,
      a2: (struct GASObject *)this - 2,
      name: psc,
      key: name,
      a5: a4,
      a6: isConstructor2);
  else
    GASObject::GetMemberRaw((CTSQueue<CFunctor *,0,1> *)this, (CTSQueue<CFunctor *,0,1>::Node_t *)psc);
}

//------------------------------------------------------------------------------
// Address: 0x1012EE80
// Name: public: virtual void GASPrototype<class GASMovieClipObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void GASPrototype<GASMovieClipObject,GASEnvironment>::AddInterface()
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x1012EEA0
// Name: protected: virtual void GASPrototype<class GASBitmapData,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASBitmapData,GASEnvironment>::Finalize_GC(
        vgui::ISurface *this,
        int a2,
        const unsigned __int8 *a3,
        int a4,
        int a5,
        ImageFormat a6)
{
  void **v7; // eax
  IShaderDevice *v8; // ecx
  IShaderDevice *v9; // ecx

  v7 = *((void ***)this + 22);
  if ( v7 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v7);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 22));
  }
  v8 = *((IShaderDevice **)this + 13);
  if ( v8 != nullptr )
    GFxResource::Release(this: v8);
  *((_DWORD *)this + 13) = 0;
  v9 = *((IShaderDevice **)this + 14);
  if ( v9 != nullptr )
    GFxResource::Release(this: v9);
  *((_DWORD *)this + 14) = 0;
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x1012EF40
// Name: protected: void GASPrototype<class GASSharedObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012EFC0
// Name: protected: void GASPrototype<class GASSharedObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012F040
// Name: protected: void GASPrototype<class GASBitmapData,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1012F2D0
// Name: public: GASPrototype<class GASBitmapData,class GASEnvironment>::GASPrototype<class GASBitmapData,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASPrototype<GASBitmapData,GASEnvironment>::GASPrototype<GASBitmapData,GASEnvironment>(
        int this,
        struct GASStringContext *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: psc);
  *(_DWORD *)this = &GASBitmapData::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASBitmapData::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 16), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  *(_DWORD *)(this + 60) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 72) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_BYTE *)(this + 84) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)psc);
  *(_DWORD *)this = &GASBitmapDataProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASBitmapDataProto::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 60) = &GASBitmapDataProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 60),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012FEF0
// Name: public: virtual bool GASPrototype<class GASBevelFilterObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASBevelFilterObject,GASEnvironment>::GetMemberRaw(
        ID3DXInclude *this,
        _IMAGE_SYMBOL_EX *psc,
        _IMAGE_SYMBOL_EX *isConstructor2,
        GASValue *a4)
{
  ID3DXInclude_vtbl *Short; // esi
  unsigned int v7; // ecx
  bool v8; // zf
  ID3DXInclude_vtbl *v9; // esi
  bool v10; // zf
  ID3DXInclude *v12; // [esp+Ch] [ebp-4h]
  bool isConstructor2a; // [esp+1Ch] [ebp+Ch]

  Short = (ID3DXInclude_vtbl *)psc->N.Name.Short;
  v7 = isConstructor2->N.Name.Short;
  v12 = this;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v7 = isConstructor2->N.Name.Short;
    v8 = *((_DWORD *)Short[41].Open + 1) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v8 = Short[41].Open == (HRESULT (__stdcall *)(ID3DXInclude *, _D3DXINCLUDE_TYPE, const char *, const void *, const void **, unsigned int *))v7;
  }
  isConstructor2a = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 48,
             a2: (struct GASObject *)this - 2,
             name: psc,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  v9 = (ID3DXInclude_vtbl *)psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      this = v12;
    }
    v10 = *((_DWORD *)v9[40].Close + 1) == *(_DWORD *)(isConstructor2->N.Name.Short + 4);
  }
  else
  {
    v10 = v9[40].Close == (HRESULT (__stdcall *)(ID3DXInclude *, const void *))v7;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)this + 48,
             a2: (struct GASObject *)this - 2,
             name: psc,
             key: isConstructor2,
             a5: a4,
             a6: isConstructor2a);
  else
    return (unsigned __int8)GASObject::GetMemberRaw(
                              (CTSQueue<CFunctor *,0,1> *)this,
                              (CTSQueue<CFunctor *,0,1>::Node_t *)psc);
}

//------------------------------------------------------------------------------
// Address: 0x10131520
// Name: protected: virtual void GASPrototype<class GASBlurFilterObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASPrototype<GASBlurFilterObject,GASEnvironment>::Finalize_GC(ID3DXSprite *this)
{
  int v1; // ecx
  int v2; // esi
  void **v3; // eax

  v2 = v1;
  v3 = *(void ***)(v1 + 236);
  if ( v3 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(v2 + 236));
  }
  GASObject::Finalize_GC(this: (GASObject *)v2);
}

//------------------------------------------------------------------------------
// Address: 0x10131560
// Name: protected: void GASPrototype<class GASBevelFilterObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10132150
// Name: public: virtual void GASPrototype<class GASBlurFilterObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASBlurFilterObject,GASEnvironment>::AddInterface(
        ID3DXSprite *this,
        const ID3DXSprite *psc)
{
  JUMPOUT(0x10092B50);
}

//------------------------------------------------------------------------------
// Address: 0x101327F0
// Name: public: virtual bool GASPrototype<class GASBevelFilterObject,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASBevelFilterObject,GASEnvironment>::DoesImplement(
        ID3DXSprite *this,
        ID3DXBuffer *this_0,
        ID3DXSprite *prototype)
{
  if ( this != prototype )
    GASPrototypeBase::DoesImplement(
      this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 52),
      penv: (unsigned int)this_0);
}

//------------------------------------------------------------------------------
// Address: 0x10133020
// Name: protected: void GASPrototype<class GASBlurFilterObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101330A0
// Name: protected: void GASPrototype<class GASDropShadowFilterObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10133110
// Name: protected: void GASPrototype<class GASGlowFilterObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101331A0
// Name: protected: void GASPrototype<class GASBevelFilterObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101352C0
// Name: public: GASPrototype<class GASKeyObject,class GASEnvironment>::GASPrototype<class GASKeyObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
const GRefCountBaseStatImpl<GRefCountNTSImpl,2> *__thiscall GASPrototype<GASKeyObject,GASEnvironment>::GASPrototype<GASKeyObject,GASEnvironment>(
        int this,
        GRefCountBaseStatImpl<GRefCountNTSImpl,2> *result,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject((GASObject *)this, a2: (struct GASStringContext *)result);
  *(_DWORD *)this = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASKeyObject::`vftable'{for `GASObjectInterface'};
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)result,
    psc_4);
  *(_DWORD *)(this + 52) = &GASPrototypeBase::`vftable';
  *(_BYTE *)(this + 64) = 0;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_BYTE *)(this + 76) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_QWORD *)&v6 = __PAIR64__(psc_8, (unsigned int)result);
  *(_DWORD *)this = &GASKeyProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASPrototype<GASKeyObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(this + 52) = &GASPrototype<GASKeyObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 52),
    pthis: (CMaterialVar *)this,
    psc: v6);
  return (const GRefCountBaseStatImpl<GRefCountNTSImpl,2> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1015B950
// Name: public: static void GConstructorMov<class GFxMesh>::DestructArray(class GFxMesh __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GConstructorMov<GFxMesh>::DestructArray(int a1, int a2)
{
  int result; // eax
  _DWORD *v3; // esi
  int i; // edi

  result = a2;
  if ( a2 != 0 )
  {
    v3 = (_DWORD *)(a1 + 40 * a2 - 40 + 32);
    for ( i = a2; i != 0; --i )
    {
      if ( *v3 != 0 )
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)*v3 + 112))(a1: *v3, a2: v3, a3: 2);
      *v3 = 0;
      v3[1] = 0;
      result = ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
                 a1: GMemory::pGlobalHeap,
                 a2: *(v3 - 3));
      v3 -= 10;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B9B0
// Name: public: static void GConstructorMov<class GFxMesh>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GFxMesh>::ConstructArray(int a1, int a2)
{
  int v2; // edx
  _DWORD *v3; // eax

  v2 = a2;
  if ( a2 != 0 )
  {
    v3 = (_DWORD *)(a1 + 28);
    do
    {
      if ( v3 != (_DWORD *)28 )
      {
        *(v3 - 2) = 0;
        *(v3 - 1) = 0;
        *v3 = 0;
        v3[1] = 0;
        v3[2] = 0;
        *(v3 - 7) = 0;
        *(v3 - 6) = -1;
        *(v3 - 5) = -1;
        *(v3 - 4) = -1;
        *(v3 - 3) = 0;
      }
      v3 += 10;
      --v2;
    }
    while ( v2 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D250
// Name: public: static void GConstructorMov<class GFxCachedStroke>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxVertexArray *__cdecl GConstructorMov<GFxCachedStroke>::ConstructArray(int a1, int a2)
{
  int v2; // edi
  int v3; // esi
  GFxVertexArray *result; // eax

  v2 = a2;
  if ( a2 != 0 )
  {
    v3 = a1 + 12;
    do
    {
      result = (GFxVertexArray *)(v3 - 12);
      if ( v3 != 12 )
      {
        *(_DWORD *)(v3 - 8) = 0;
        *(_DWORD *)(v3 - 4) = 0;
        *(_DWORD *)v3 = 0;
        *(_DWORD *)(v3 + 4) = 0;
        *(_DWORD *)(v3 + 8) = 0;
        *(_DWORD *)(v3 + 12) = 0;
        *(_DWORD *)(v3 + 16) = 0;
        *(_DWORD *)(v3 + 20) = 0;
        result = GFxVertexArray::GFxVertexArray(this: (GFxVertexArray *)(v3 + 48), a2: nullptr, a3: Vertex_None, a4: 0);
        *(_DWORD *)(v3 + 68) = 0;
        *(_DWORD *)(v3 + 72) = 0;
        *(float *)(v3 + 28) = -4.0;
        *(_DWORD *)(v3 - 12) = -1;
        *(float *)(v3 + 40) = 0.0;
        *(_DWORD *)(v3 + 24) = 0;
        *(float *)(v3 + 44) = 0.0;
        *(_WORD *)(v3 + 35) = 0;
        *(_WORD *)(v3 + 32) = 0;
        *(_BYTE *)(v3 + 34) = 0;
      }
      v3 += 88;
      --v2;
    }
    while ( v2 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160610
// Name: public: static void GConstructorMov<class GRangeData<class GPtr<class GFxTextFormat>>>::ConstructArray(void __near *,unsigned int,class GRangeData<class GPtr<class GFxTextFormat>> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GRangeData<GPtr<GFxTextFormat>>>::ConstructArray(_DWORD *a1, int a2, int a3)
{
  IShaderDevice **v4; // esi
  int i; // ebx
  int v6; // eax

  if ( a2 != 0 )
  {
    v4 = (IShaderDevice **)(a3 + 8);
    for ( i = a2; i != 0; --i )
    {
      if ( a1 != nullptr )
      {
        v6 = (int)*(v4 - 1);
        *a1 = *(v4 - 2);
        a1[1] = v6;
        if ( *v4 != nullptr )
          GRefCountImpl::AddRef(this: *v4);
        a1[2] = *v4;
      }
      a1 += 3;
      v4 += 3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162AB0
// Name: public: static void GConstructorMov<struct GFxSGMLStackElemDesc<wchar_t>>::DestructArray(struct GFxSGMLStackElemDesc<wchar_t> __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__usercall GConstructorMov<GFxSGMLStackElemDesc<wchar_t>>::DestructArray@<eax>(
        MaterialVarFlags_t a1@<esi>,
        int a2,
        int a3)
{
  int v3; // edi
  char *result; // eax
  CMaterial *v5; // esi
  MaterialVarFlags_t v6; // [esp-4h] [ebp-8h]
  bool v7; // [esp+0h] [ebp-4h]

  v3 = a3;
  result = (char *)(a2 + 84 * a3 - 84);
  if ( a3 != 0 )
  {
    v6 = a1;
    v5 = (CMaterial *)(result + 60);
    do
    {
      v5->__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
      GFxTextParagraphFormat::FreeTabStops(this: v5, a2: v6, a3: v7);
      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)v5);
      result = (char *)GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v5[-1].m_Reflectivity);
      v5 = (CMaterial *)((char *)v5 - 84);
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10178AC0
// Name: public: virtual bool GASPrototype<class GASStyleSheetObject,class GASEnvironment>::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASStyleSheetObject,GASEnvironment>::GetMemberRaw(
        int ecx0,
        IDirect3DVolumeTexture9 *this,
        _IMAGE_SYMBOL_EX *psc,
        GASValue *a4)
{
  IDirect3DVolumeTexture9_vtbl *v4; // esi
  unsigned int Short; // ecx
  bool v8; // zf
  IDirect3DVolumeTexture9_vtbl *v9; // esi
  bool v10; // zf
  int v12; // [esp+Ch] [ebp-4h]
  bool isConstructor2; // [esp+1Ch] [ebp+Ch]

  v4 = this->__vftable;
  Short = psc->N.Name.Short;
  v12 = ecx0;
  if ( *((_BYTE *)this + 4) <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      ecx0 = v12;
    }
    Short = psc->N.Name.Short;
    v8 = *((_DWORD *)v4[3].GenerateMipSubLevels + 1) == *(_DWORD *)(psc->N.Name.Short + 4);
  }
  else
  {
    v8 = v4[3].GenerateMipSubLevels == (void (__stdcall *)(IDirect3DBaseTexture9 *))Short;
  }
  isConstructor2 = v8;
  if ( v8 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(ecx0 + 52),
             a2: (struct GASObject *)(ecx0 - 16),
             name: (_IMAGE_SYMBOL_EX *)this,
             key: psc,
             a5: a4,
             a6: isConstructor2);
  v9 = this->__vftable;
  if ( *((_BYTE *)this + 4) <= 6u )
  {
    if ( *(_DWORD *)(Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      ecx0 = v12;
    }
    v10 = *((_DWORD *)v9[3].GetAutoGenFilterType + 1) == *(_DWORD *)(psc->N.Name.Short + 4);
  }
  else
  {
    v10 = v9[3].GetAutoGenFilterType == (_D3DTEXTUREFILTERTYPE (__stdcall *)(IDirect3DBaseTexture9 *))Short;
  }
  if ( v10 )
    return GASPrototypeBase::GetMemberRawConstructor(
             this: (GASPrototypeBase *)(ecx0 + 52),
             a2: (struct GASObject *)(ecx0 - 16),
             name: (_IMAGE_SYMBOL_EX *)this,
             key: psc,
             a5: a4,
             a6: isConstructor2);
  else
    return (unsigned __int8)GASObject::GetMemberRaw(
                              this: (CTSQueue<CFunctor *,0,1> *)ecx0,
                              psc: (CTSQueue<CFunctor *,0,1>::Node_t *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10178B80
// Name: public: virtual void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASStyleSheetObject,GASEnvironment>::AddInterface(
        int this,
        IMaterialVar *const *a2,
        int a3,
        int a4)
{
  GASPrototypeBase::AddInterface(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 52),
    psc: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10178B90
// Name: public: virtual bool GASPrototype<class GASStyleSheetObject,class GASEnvironment>::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPrototype<GASStyleSheetObject,GASEnvironment>::DoesImplement(
        int ecx0,
        IDirect3DVolumeTexture9 *this,
        const _D3DBOX *penv)
{
  if ( (const _D3DBOX *)ecx0 == penv )
    return 1;
  else
    return (unsigned __int8)GASPrototypeBase::DoesImplement(
                              this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(ecx0 + 68),
                              penv: (unsigned int)this);
}

//------------------------------------------------------------------------------
// Address: 0x101795B0
// Name: protected: virtual void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASPrototype<GASStyleSheetObject,GASEnvironment>::Finalize_GC(IDirect3DVolumeTexture9 *this)
{
  GASObject *v1; // ecx
  GASObject *v2; // esi
  void **p_pNext; // eax

  v2 = v1;
  p_pNext = (void **)&v1[12].pNode->pNext;
  if ( p_pNext != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *p_pNext);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2[12].pNode);
  }
  GFxTextStyleManager::~GFxTextStyleManager(this: (GFxTextStyleManager *)&v2[6].sequence);
  GASObject::Finalize_GC(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10179620
// Name: protected: void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101796A0
// Name: protected: void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10179710
// Name: protected: void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10179900
// Name: protected: void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10179990
// Name: protected: void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1017A760
// Name: protected: virtual void GASPrototype<class GASStyleSheetObject,class GASEnvironment>::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototype<GASStyleSheetObject,GASEnvironment>::ExecuteForEachChild_GC(
        ISteamUserStats *ecx0,
        IDirect3DVolumeTexture9 *this)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  switch ( (unsigned int)this )
  {
    case 0u:
      GASPrototype<GASStyleSheetObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(
        this: ecx0,
        a2: savedregs);
      break;
    case 1u:
      GASPrototype<GASStyleSheetObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(
        this: ecx0,
        a2: savedregs);
      break;
    case 2u:
      GASPrototype<GASStyleSheetObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(
        this: ecx0,
        a2: savedregs);
      break;
    case 3u:
      GASPrototype<GASStyleSheetObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(
        this: ecx0,
        a2: savedregs);
      break;
    case 4u:
      GASPrototype<GASStyleSheetObject,GASEnvironment>::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(
        this: ecx0,
        a2: savedregs);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017AA60
// Name: public: GASPrototype<class GASStyleSheetObject,class GASEnvironment>::GASPrototype<class GASStyleSheetObject,class GASEnvironment>(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall GASPrototype<GASStyleSheetObject,GASEnvironment>::GASPrototype<GASStyleSheetObject,GASEnvironment>(
        CMaterialVar *pthis,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *a3,
        unsigned int a4)
{
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject(this: (GASObject *)pthis, a2: (struct GASStringContext *)psc);
  pthis->__vftable = (CMaterialVar_vtbl *)&GASStyleSheetObject::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(pthis->m_VecVal.y) = &GASStyleSheetObject::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)pthis + 13) = 0;
  *((_DWORD *)pthis + 14) = 2;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)pthis + 60));
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)&pthis->m_VecVal.y, psc, psc_4: a3);
  *((_DWORD *)pthis + 17) = &GASPrototypeBase::`vftable';
  *((_BYTE *)pthis + 80) = 0;
  *((_DWORD *)pthis + 18) = 0;
  *((_DWORD *)pthis + 19) = 0;
  *((_BYTE *)pthis + 92) = 0;
  *((_DWORD *)pthis + 21) = 0;
  *((_DWORD *)pthis + 22) = 0;
  *((_DWORD *)pthis + 24) = 0;
  *(_QWORD *)&v6 = __PAIR64__(a4, (unsigned int)psc);
  pthis->__vftable = (CMaterialVar_vtbl *)&GASPrototype<GASStyleSheetObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  LODWORD(pthis->m_VecVal.y) = &GASStyleSheetProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)pthis + 17) = &GASStyleSheetProto::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)pthis + 68),
    pthis,
    psc: v6);
  return pthis;
}

//------------------------------------------------------------------------------
// Address: 0x1017B370
// Name: public: static void GConstructorMov<struct GFxTextHighlightDesc>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GFxTextHighlightDesc>::ConstructArray(int a1, int a2)
{
  int v2; // edx
  int v3; // eax

  v2 = a2;
  if ( a2 != 0 )
  {
    v3 = a1 + 28;
    do
    {
      if ( v3 != 28 )
      {
        *(_DWORD *)(v3 - 28) = -1;
        *(_DWORD *)(v3 - 24) = 0;
        *(_DWORD *)(v3 - 20) = -1;
        *(_DWORD *)(v3 - 16) = 0;
        *(_DWORD *)(v3 - 12) = 0;
        *(_DWORD *)(v3 - 8) = 0;
        *(_DWORD *)(v3 + 4) = 0;
        *(_DWORD *)v3 = 0;
        *(_DWORD *)(v3 - 4) = 0;
        *(_BYTE *)(v3 + 8) = 0;
      }
      v3 += 40;
      --v2;
    }
    while ( v2 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F300
// Name: public: class GRect<float> GFxButtonCharacter::GetRectBounds(class GMatrix2D const __near &,unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float *__thiscall GFxButtonCharacter::GetRectBounds(_DWORD *this, float *a2, float *a3, unsigned int recNumber)
{
  int v5; // eax
  int v6; // ecx
  float *v7; // eax
  _BYTE v9[16]; // [esp+Ch] [ebp-38h] BYREF
  float v10; // [esp+1Ch] [ebp-28h]
  float v11; // [esp+20h] [ebp-24h]
  float v12; // [esp+24h] [ebp-20h]
  GMatrix2D v13; // [esp+28h] [ebp-1Ch] BYREF

  *a2 = 0.0;
  a2[1] = 0.0;
  a2[2] = 0.0;
  a2[3] = 0.0;
  v12 = *(float *)&recNumber;
  GMatrix2D::SetIdentity(this: (float *)&v13);
  v5 = *(this + 48) + 4 * recNumber;
  if ( *(_DWORD *)v5 != 0 )
  {
    v13.M_[0][0] = *a3;
    v13.M_[0][1] = a3[1];
    v13.M_[0][2] = a3[2];
    v13.M_[1][0] = a3[3];
    v13.M_[1][1] = a3[4];
    v13.M_[1][2] = a3[5];
    GMatrix2D::Prepend(this: &v13, a2: (const struct GMatrix2D *)(*(_DWORD *)v5 + 68));
    v6 = *(_DWORD *)(*(this + 48) + 4 * LODWORD(v12));
    v7 = (float *)(*(int (__thiscall **)(int, _BYTE *, GMatrix2D *))(*(_DWORD *)v6 + 64))(a1: v6, a2: v9, a3: &v13);
    v12 = v7[1];
    v10 = v7[2];
    v11 = v7[3];
    *a2 = *v7;
    a2[1] = v12;
    a2[2] = v10;
    a2[3] = v11;
  }
  return a2;
}
