// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasobject.cpp
// Functions: 60
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasobject.h"

//------------------------------------------------------------------------------
// Address: 0x1008EC60
// Name: public: class GFxASCharacter __near * GASObjectInterface::ToASCharacter(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxASCharacter *__thiscall GASObjectInterface::ToASCharacter(GASObjectInterface *this)
{
  if ( (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)this + 8))(a1: this) - 2) > 3 )
    return nullptr;
  else
    return (GASObjectInterface *)((char *)this - 120);
}

//------------------------------------------------------------------------------
// Address: 0x1008EC80
// Name: public: class GASObject __near * GASObjectInterface::ToASObject(void)
// Source: json
//------------------------------------------------------------------------------
PROCESSOR_IDLESTATE_POLICY *__thiscall GASObjectInterface::ToASObject(char *this)
{
  if ( (unsigned int)((*(int (__thiscall **)(char *))(*(_DWORD *)this + 8))(a1: this) - 6) > 0x26 )
    return nullptr;
  else
    return (PROCESSOR_IDLESTATE_POLICY *)(this - 16);
}

//------------------------------------------------------------------------------
// Address: 0x1008ECA0
// Name: public: class GFxSprite __near * GASObjectInterface::ToSprite(void)
// Source: json
//------------------------------------------------------------------------------
_TAPE_WMI_OPERATIONS *__thiscall GASObjectInterface::ToSprite(char *this)
{
  if ( (*(int (__thiscall **)(char *))(*(_DWORD *)this + 8))(a1: this) == 2 )
    return (_TAPE_WMI_OPERATIONS *)(this - 120);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008ECC0
// Name: public: virtual class GASValue GASObject::GetValue(void)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__stdcall GASObject::GetValue(_BYTE *a1)
{
  *a1 = 0;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1008ECD0
// Name: public: static void GASObjectProto::HasOwnProperty(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASObjectProto::HasOwnProperty(GASFnCall *a1)
{
  GASFnCall *v1; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v2; // edi
  unsigned __int8 *v3; // eax
  char v4; // al
  GASFnCall v5; // esi
  char v6; // bl
  GASFnCall *v7; // eax
  bool v8; // zf

  v1 = a1;
  v2 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
  v3 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
  GASValue::ToStringImpl(this: v3, a2: (int *)&a1, a3: v2, precision: -1, debug: false);
  v4 = (*(int (__thiscall **)(GASFnCall, GASFnCall, GASFnCall **, _DWORD))(v1[2]->cbSize + 36))(
         a1: v1[2],
         a2: v1[6] + 3,
         a3: &a1,
         a4: 0);
  v5 = v1[1];
  v6 = v4;
  GASValue::DropRefs(this: (GASValue *)v5, a2: (int)&a1);
  LOBYTE(v5->cItems) = v6;
  LOBYTE(v5->cbSize) = 2;
  v7 = a1;
  v8 = a1[2] == (GASFnCall)1;
  a1[2] = (GASFnCall)((char *)a1[2] - 1);
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v7);
}

//------------------------------------------------------------------------------
// Address: 0x1008ED40
// Name: public: static void GASObjectProto::Unwatch(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASObjectProto::Unwatch(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  char v5; // al
  GASFnCall v6; // esi
  char v7; // bl
  GASFnCall *v8; // eax
  bool v9; // zf
  GASFnCall v10; // esi

  v2 = a2;
  if ( (int)a2[7] < 1 )
  {
    v10 = a2[1];
    GASValue::DropRefs(this: (GASValue *)v10, a2: a1);
    LOBYTE(v10->cbSize) = 2;
    LOBYTE(v10->cItems) = 0;
  }
  else
  {
    v3 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
    v4 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
    GASValue::ToStringImpl(this: v4, (int *)&a2, a3: v3, precision: -1, debug: false);
    v5 = (*(int (__thiscall **)(GASFnCall, GASFnCall, GASFnCall **))(v2[2]->cbSize + 80))(
           a1: v2[2],
           a2: v2[6] + 3,
           a3: &a2);
    v6 = v2[1];
    v7 = v5;
    GASValue::DropRefs(this: (GASValue *)v6, (int)&a2);
    LOBYTE(v6->cItems) = v7;
    LOBYTE(v6->cbSize) = 2;
    v8 = a2;
    v9 = a2[2] == (GASFnCall)1;
    a2[2] = (GASFnCall)((char *)a2[2] - 1);
    if ( v9 )
      GASStringNode::ReleaseNode(a1: (int)v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EDC0
// Name: public: static void GASObjectProto::IsPropertyEnumerable(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASObjectProto::IsPropertyEnumerable(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  char v5; // bl
  GASFnCall v6; // ecx
  GASFnCall v7; // eax
  GASFnCall v8; // esi
  GASFnCall *v9; // eax
  bool v10; // zf
  GASFnCall v11; // esi
  GASValue v12[4]; // [esp+4h] [ebp-10h] BYREF

  v2 = a2;
  if ( (int)a2[7] < 1 )
  {
    v11 = a2[1];
    GASValue::DropRefs(this: (GASValue *)v11, a2: a1);
    LOBYTE(v11->cbSize) = 2;
    LOBYTE(v11->cItems) = 0;
  }
  else
  {
    v3 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
    v4 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
    GASValue::ToStringImpl(this: v4, (int *)&a2, a3: v3, precision: -1, debug: false);
    v5 = (*(int (__thiscall **)(GASFnCall, GASFnCall, GASFnCall **, _DWORD))(v2[2]->cbSize + 36))(
           a1: v2[2],
           a2: v2[6] + 3,
           a3: &a2,
           a4: 0);
    if ( v5 != 0 )
    {
      v6 = v2[2];
      v7 = v2[6];
      LOWORD(v12[0]) = 0;
      (*(void (__thiscall **)(GASFnCall, GASFnCall, GASFnCall **, GASValue *))(v6->cbSize + 20))(
        a1: v6,
        a2: v7 + 3,
        a3: &a2,
        a4: v12);
      if ( (BYTE1(v12[0]) & 1) != 0 )
        v5 = 0;
      GASValue::~GASValue(this: v12, (int)&a2);
    }
    v8 = v2[1];
    GASValue::DropRefs(this: (GASValue *)v8, (int)&a2);
    LOBYTE(v8->cItems) = v5;
    LOBYTE(v8->cbSize) = 2;
    v9 = a2;
    v10 = a2[2] == (GASFnCall)1;
    a2[2] = (GASFnCall)((char *)a2[2] - 1);
    if ( v10 )
      GASStringNode::ReleaseNode(a1: (int)v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EE80
// Name: public: static void GASObjectProto::IsPrototypeOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASObjectProto::IsPrototypeOf(int p_cxItem@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  struct GASValue *v3; // eax
  _SERVICE_STATUS *v4; // eax
  char v5; // al
  GASFnCall v6; // esi
  char v7; // bl
  GASFnCall v8; // esi
  _SERVICE_STATUS *v9; // [esp-4h] [ebp-Ch]

  if ( (int)a2[7] >= 1
    && (unsigned int)((*(int (__thiscall **)(GASFnCall))(a2[2]->cbSize + 8))(a1: a2[2]) - 2) > 3
    && ((v2 = a2[2]) == nullptr ? (p_cxItem = 0) : (p_cxItem = (int)&v2[-1].cxItem),
        v9 = (_SERVICE_STATUS *)a2[6],
        v3 = GASFnCall::Arg(this: a2, a2: 0),
        (v4 = GASValue::ToObjectInterface(a1: (int)v3, a2: p_cxItem, result: v9)) != nullptr) )
  {
    v5 = (*(int (__thiscall **)(_SERVICE_STATUS *, GASFnCall, int, _DWORD))(v4->dwServiceType + 72))(
           a1: v4,
           a2: a2[6],
           a3: p_cxItem,
           a4: 0);
    v6 = a2[1];
    v7 = v5;
    GASValue::DropRefs(this: (GASValue *)v6, a2: p_cxItem);
    LOBYTE(v6->cItems) = v7;
    LOBYTE(v6->cbSize) = 2;
  }
  else
  {
    v8 = a2[1];
    GASValue::DropRefs(this: (GASValue *)v8, a2: p_cxItem);
    LOBYTE(v8->cItems) = 0;
    LOBYTE(v8->cbSize) = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EF10
// Name: public: static void GASObjectProto::ToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASObjectProto::ToString(const struct GASFnCall *a1)
{
  int v1; // esi
  int v2; // edi
  int v3; // eax
  int v4; // eax
  tagAXISINFOA *v5; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **v6; // eax
  tagRID_DEVICE_INFO_KEYBOARD *CharacterNamePath; // eax
  int v8; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v9; // edi
  unsigned int dwType; // eax
  int v11; // esi
  int v12; // edi
  int v13; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v14; // [esp-4h] [ebp-1Ch]
  GASValue v15[4]; // [esp+8h] [ebp-10h] BYREF

  if ( (*(int (__thiscall **)(_DWORD))(**((_DWORD **)a1 + 2) + 8))(a1: *((_DWORD *)a1 + 2)) == 23 )
  {
    v1 = *((_DWORD *)a1 + 1);
    v2 = *(_DWORD *)(*((_DWORD *)a1 + 6) + 120);
    if ( *(_BYTE *)v1 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v1, a2: v2);
    *(_BYTE *)v1 = 5;
    v3 = *(_DWORD *)(v2 + 340);
    *(_DWORD *)(v1 + 4) = v3;
    ++*(_DWORD *)(v3 + 8);
  }
  else if ( (unsigned int)((*(int (__thiscall **)(_DWORD))(**((_DWORD **)a1 + 2) + 8))(a1: *((_DWORD *)a1 + 2)) - 2) > 3 )
  {
    v11 = *((_DWORD *)a1 + 1);
    v12 = *(_DWORD *)(*((_DWORD *)a1 + 6) + 120);
    if ( *(_BYTE *)v11 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v11, a2: v12);
    *(_BYTE *)v11 = 5;
    v13 = *(_DWORD *)(v12 + 348);
    *(_DWORD *)(v11 + 4) = v13;
    ++*(_DWORD *)(v13 + 8);
  }
  else
  {
    v4 = *((_DWORD *)a1 + 2);
    if ( v4 != 0 )
      v5 = (tagAXISINFOA *)(v4 - 120);
    else
      v5 = nullptr;
    v14 = *((tagRID_DEVICE_INFO_KEYBOARD **)a1 + 6);
    v6 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)GASValue::GASValue(this: v15, result: v5);
    CharacterNamePath = GASValue::GetCharacterNamePath(this: v6, result: v14);
    v8 = *((_DWORD *)a1 + 1);
    v9 = CharacterNamePath;
    if ( *(_BYTE *)v8 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v8, a2: (int)CharacterNamePath);
    *(_BYTE *)v8 = 5;
    dwType = v9->dwType;
    *(_DWORD *)(v8 + 4) = v9->dwType;
    ++*(_DWORD *)(dwType + 8);
    GASValue::~GASValue(this: v15, a2: (int)v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EFE0
// Name: public: static void GASObjectProto::ValueOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASObjectProto::ValueOf(const struct GASFnCall *a1)
{
  GASValue::SetAsObjectInterface(this: *((GASValue **)a1 + 1), a2: *((struct GASObjectInterface **)a1 + 2));
}

//------------------------------------------------------------------------------
// Address: 0x1008F030
// Name: public: class GASObject __near * GASObjectInterface::FindOwner(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
_JOB_SET_ARRAY *__thiscall GASObjectInterface::FindOwner(_DWORD *this, _IMAGE_SYMBOL_EX *result, int a3)
{
  _DWORD *v3; // esi
  int v4; // esi

  v3 = this;
  if ( this == nullptr )
    return nullptr;
  while ( (*(unsigned __int8 (__thiscall **)(_DWORD *, _IMAGE_SYMBOL_EX *, int, _DWORD))(*v3 + 36))(
            a1: v3,
            a2: result,
            a3,
            a4: 0) == 0 )
  {
    v4 = v3[2];
    if ( v4 != 0 )
    {
      v3 = (_DWORD *)(v4 + 16);
      if ( v3 != nullptr )
        continue;
    }
    return nullptr;
  }
  return (_JOB_SET_ARRAY *)(v3 - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1008F080
// Name: public: void GASObjectInterface::SetUserData(class GFxMovieView __near *,class GFxASUserData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObjectInterface::SetUserData(GASObjectInterface *this, struct GFxMovieView *a2, GFxASUserData *a3)
{
  void *v4; // eax
  _DWORD *v5; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  v4 = *((void **)this + 1);
  if ( v4 != nullptr )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  v6 = 323;
  v5 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 8, a4: &v6);
  if ( v5 != nullptr )
  {
    *v5 = a2;
    v5[1] = a3;
    *((_DWORD *)this + 1) = v5;
  }
  else
  {
    *((_DWORD *)this + 1) = 0;
  }
  GFxASUserData::SetLastObjectValue(this: a3, a2: (struct GFxValue::ObjectInterface *)a2[1].RefCount, pdata: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008F0F0
// Name: public: virtual bool GASObject::InstanceOf(class GASEnvironment __near *,class GASObject const __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::InstanceOf(
        CTSQueue<CFunctor *,0,1> *this,
        CFunctor *const *penv,
        _DWORD *inclInterfaces,
        char a4)
{
  _DWORD *v4; // esi

  v4 = (_DWORD *)this - 4;
  if ( this != (CTSQueue<CFunctor *,0,1> *)16 )
  {
    do
    {
      if ( a4 != 0 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CFunctor *const *, _DWORD *))(*v4 + 20))(
               a1: v4,
               a2: penv,
               a3: inclInterfaces) != 0 )
          return;
      }
      else if ( v4 == inclInterfaces )
      {
        return;
      }
      v4 = (_DWORD *)v4[6];
    }
    while ( v4 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F140
// Name: public: virtual class GASObject __near * GASFunctionCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASCFunctionObject *__stdcall GASFunctionCtorFunction::CreateNewObject(IDirect3DCubeTexture9 *this)
{
  int v1; // ecx
  int (__thiscall *v2)(int, int, IDirect3DCubeTexture9 **); // edx
  struct GASStringContext *v3; // esi
  GASCFunctionObject *v4; // eax

  v1 = *(_DWORD *)(*((_DWORD *)this + 30) + 656);
  v2 = *(int (__thiscall **)(int, int, IDirect3DCubeTexture9 **))(*(_DWORD *)v1 + 40);
  v3 = (struct GASStringContext *)(this + 30);
  this = (IDirect3DCubeTexture9 *)323;
  v4 = (GASCFunctionObject *)v2(a1: v1, a2: 56, a3: &this);
  if ( v4 != nullptr )
    return GASCFunctionObject::GASCFunctionObject(this: v4, psc: v3);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008F450
// Name: protected: void GASObject::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(ISteamUserStats *this)
{
  ISteamUserStats *v1; // ebx
  ISteamUserStats *v2; // ecx
  unsigned int v3; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // edi
  signed int v7; // esi
  ISteamUserStats_vtbl *v8; // eax
  bool (__thiscall *GetStat)(ISteamUserStats *, const char *, float *); // eax
  bool (__thiscall **v10)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v11; // esi
  ISteamUserStats_vtbl *RequestCurrentStats; // ecx
  unsigned int v13; // eax
  bool (__thiscall *v14)(ISteamUserStats *, const char *, float *); // edx
  bool (__thiscall **p_GetStat_2)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v16; // ebx
  signed int v17; // esi
  bool (__thiscall *v18)(ISteamUserStats *); // eax
  int *v19; // edi
  unsigned int v20; // eax
  _DWORD *v21; // ecx
  ISteamUserStats_vtbl *v22; // ecx
  ISteamUserStats *v23; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = *((ISteamUserStats **)this + 7);
  v23 = v1;
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    v3 = 0;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      ++v3;
      v5 += 6;
    }
    while ( v3 <= (unsigned int)v4 );
    v2 = v1 + 7;
  }
  else
  {
    v3 = 0;
  }
  v6 = v2;
  v7 = v3;
  while ( v6 != nullptr )
  {
    v8 = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)v8->GetStat )
      break;
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)&v8->SetStat_2 + 6 * v7);
    GetStat = v6->GetStat;
    if ( v7 <= (int)GetStat && ++v7 <= (unsigned int)GetStat )
    {
      v10 = &v6->GetStat_2 + 6 * v7;
      do
      {
        if ( *v10 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v10 += 6;
      }
      while ( v7 <= (unsigned int)GetStat );
    }
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)&v1[8]);
  v11 = v1[11].__vftable;
  if ( v11 != nullptr )
  {
    RequestCurrentStats = (ISteamUserStats_vtbl *)v11->RequestCurrentStats;
    if ( v11->RequestCurrentStats != nullptr )
    {
      v14 = RequestCurrentStats->GetStat;
      v13 = 0;
      p_GetStat_2 = &RequestCurrentStats->GetStat_2;
      do
      {
        if ( *p_GetStat_2 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v13;
        p_GetStat_2 += 9;
      }
      while ( v13 <= (unsigned int)v14 );
      RequestCurrentStats = v1[11].__vftable;
    }
    else
    {
      v13 = 0;
    }
    v16 = RequestCurrentStats;
    v17 = v13;
    while ( v16 != nullptr )
    {
      v18 = v16->RequestCurrentStats;
      if ( v16->RequestCurrentStats == nullptr || v17 > *((_DWORD *)v18 + 1) )
        break;
      v19 = (int *)((char *)v18 + 36 * v17 + 16);
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: v19);
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: v19 + 3);
      v20 = *((_DWORD *)v16->RequestCurrentStats + 1);
      if ( v17 <= (int)v20 && ++v17 <= v20 )
      {
        v21 = (_DWORD *)((char *)v16->RequestCurrentStats + 36 * v17 + 8);
        do
        {
          if ( *v21 != -2 )
            break;
          ++v17;
          v21 += 9;
        }
        while ( v17 <= v20 );
      }
    }
    v1 = v23;
  }
  v22 = v1[6].__vftable;
  if ( v22 != nullptr && ((int)--v22->GetStat_2 & 0x70000000) != 0x10000000 )
  {
    v22->GetStat_2 = (bool (__thiscall *)(ISteamUserStats *, const char *, int *))((int)v22->GetStat_2 & 0x8FFFFFFF
                                                                                 | 0x10000000);
    (*(void (__thiscall **)(ISteamUserStats_vtbl *, int))v22->RequestCurrentStats)(a1: v22, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F580
// Name: protected: void GASObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(ISteamUserStats *this)
{
  ISteamUserStats *v1; // ebx
  ISteamUserStats *v2; // ecx
  unsigned int v3; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // edi
  signed int v7; // esi
  ISteamUserStats_vtbl *v8; // eax
  bool (__thiscall *GetStat)(ISteamUserStats *, const char *, float *); // eax
  bool (__thiscall **v10)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v11; // esi
  ISteamUserStats_vtbl *RequestCurrentStats; // ecx
  unsigned int v13; // eax
  bool (__thiscall *v14)(ISteamUserStats *, const char *, float *); // edx
  bool (__thiscall **p_GetStat_2)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v16; // ebx
  signed int v17; // esi
  bool (__thiscall *v18)(ISteamUserStats *); // eax
  int *v19; // edi
  unsigned int v20; // eax
  _DWORD *v21; // ecx
  ISteamUserStats_vtbl *v22; // ecx
  bool (__thiscall *v23)(ISteamUserStats *, const char *, int *); // eax
  ISteamUserStats *v24; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = *((ISteamUserStats **)this + 7);
  v24 = v1;
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    v3 = 0;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      ++v3;
      v5 += 6;
    }
    while ( v3 <= (unsigned int)v4 );
    v2 = v1 + 7;
  }
  else
  {
    v3 = 0;
  }
  v6 = v2;
  v7 = v3;
  while ( v6 != nullptr )
  {
    v8 = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)v8->GetStat )
      break;
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)&v8->SetStat_2 + 6 * v7);
    GetStat = v6->GetStat;
    if ( v7 <= (int)GetStat && ++v7 <= (unsigned int)GetStat )
    {
      v10 = &v6->GetStat_2 + 6 * v7;
      do
      {
        if ( *v10 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v10 += 6;
      }
      while ( v7 <= (unsigned int)GetStat );
    }
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)&v1[8]);
  v11 = v1[11].__vftable;
  if ( v11 != nullptr )
  {
    RequestCurrentStats = (ISteamUserStats_vtbl *)v11->RequestCurrentStats;
    if ( v11->RequestCurrentStats != nullptr )
    {
      v14 = RequestCurrentStats->GetStat;
      v13 = 0;
      p_GetStat_2 = &RequestCurrentStats->GetStat_2;
      do
      {
        if ( *p_GetStat_2 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v13;
        p_GetStat_2 += 9;
      }
      while ( v13 <= (unsigned int)v14 );
      RequestCurrentStats = v1[11].__vftable;
    }
    else
    {
      v13 = 0;
    }
    v16 = RequestCurrentStats;
    v17 = v13;
    while ( v16 != nullptr )
    {
      v18 = v16->RequestCurrentStats;
      if ( v16->RequestCurrentStats == nullptr || v17 > *((_DWORD *)v18 + 1) )
        break;
      v19 = (int *)((char *)v18 + 36 * v17 + 16);
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: v19);
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: v19 + 3);
      v20 = *((_DWORD *)v16->RequestCurrentStats + 1);
      if ( v17 <= (int)v20 && ++v17 <= v20 )
      {
        v21 = (_DWORD *)((char *)v16->RequestCurrentStats + 36 * v17 + 8);
        do
        {
          if ( *v21 != -2 )
            break;
          ++v17;
          v21 += 9;
        }
        while ( v17 <= v20 );
      }
    }
    v1 = v24;
  }
  v22 = v1[6].__vftable;
  if ( v22 != nullptr )
  {
    v23 = ++v22->GetStat_2;
    if ( ((unsigned int)v23 & 0x70000000) != 0 )
    {
      v22->GetStat_2 = (bool (__thiscall *)(ISteamUserStats *, const char *, int *))((unsigned int)v23 & 0x8FFFFFFF);
      (*(void (__thiscall **)(ISteamUserStats_vtbl *, int))v22->RequestCurrentStats)(a1: v22, a2: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F6A0
// Name: protected: void GASObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(ISteamUserStats *this)
{
  ISteamUserStats *v1; // ebx
  ISteamUserStats *v2; // ecx
  unsigned int v3; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // edi
  signed int v7; // esi
  ISteamUserStats_vtbl *v8; // eax
  bool (__thiscall *GetStat)(ISteamUserStats *, const char *, float *); // eax
  bool (__thiscall **v10)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v11; // esi
  ISteamUserStats_vtbl *RequestCurrentStats; // ecx
  unsigned int v13; // eax
  bool (__thiscall *v14)(ISteamUserStats *, const char *, float *); // edx
  bool (__thiscall **p_GetStat_2)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v16; // ebx
  signed int v17; // esi
  bool (__thiscall *v18)(ISteamUserStats *); // eax
  int *v19; // edi
  unsigned int v20; // eax
  _DWORD *v21; // ecx
  ISteamUserStats_vtbl *v22; // ecx
  bool (__thiscall *GetStat_2)(ISteamUserStats *, const char *, int *); // eax
  ISteamUserStats *v24; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = *((ISteamUserStats **)this + 7);
  v24 = v1;
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    v3 = 0;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      ++v3;
      v5 += 6;
    }
    while ( v3 <= (unsigned int)v4 );
    v2 = v1 + 7;
  }
  else
  {
    v3 = 0;
  }
  v6 = v2;
  v7 = v3;
  while ( v6 != nullptr )
  {
    v8 = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)v8->GetStat )
      break;
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)&v8->SetStat_2 + 6 * v7);
    GetStat = v6->GetStat;
    if ( v7 <= (int)GetStat && ++v7 <= (unsigned int)GetStat )
    {
      v10 = &v6->GetStat_2 + 6 * v7;
      do
      {
        if ( *v10 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v10 += 6;
      }
      while ( v7 <= (unsigned int)GetStat );
    }
  }
  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)&v1[8]);
  v11 = v1[11].__vftable;
  if ( v11 != nullptr )
  {
    RequestCurrentStats = (ISteamUserStats_vtbl *)v11->RequestCurrentStats;
    if ( v11->RequestCurrentStats != nullptr )
    {
      v14 = RequestCurrentStats->GetStat;
      v13 = 0;
      p_GetStat_2 = &RequestCurrentStats->GetStat_2;
      do
      {
        if ( *p_GetStat_2 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v13;
        p_GetStat_2 += 9;
      }
      while ( v13 <= (unsigned int)v14 );
      RequestCurrentStats = v1[11].__vftable;
    }
    else
    {
      v13 = 0;
    }
    v16 = RequestCurrentStats;
    v17 = v13;
    while ( v16 != nullptr )
    {
      v18 = v16->RequestCurrentStats;
      if ( v16->RequestCurrentStats == nullptr || v17 > *((_DWORD *)v18 + 1) )
        break;
      v19 = (int *)((char *)v18 + 36 * v17 + 16);
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: v19);
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: v19 + 3);
      v20 = *((_DWORD *)v16->RequestCurrentStats + 1);
      if ( v17 <= (int)v20 && ++v17 <= v20 )
      {
        v21 = (_DWORD *)((char *)v16->RequestCurrentStats + 36 * v17 + 8);
        do
        {
          if ( *v21 != -2 )
            break;
          ++v17;
          v21 += 9;
        }
        while ( v17 <= v20 );
      }
    }
    v1 = v24;
  }
  v22 = v1[6].__vftable;
  if ( v22 != nullptr )
  {
    GetStat_2 = v22->GetStat_2;
    if ( ((unsigned int)GetStat_2 & 0x70000000) == 0x10000000 )
    {
      if ( ((unsigned int)GetStat_2 & 0xFFFFFFF) != 0 )
      {
        v22->GetStat_2 = (bool (__thiscall *)(ISteamUserStats *, const char *, int *))((unsigned int)GetStat_2
                                                                                     & 0x8FFFFFFF);
        (*(void (__thiscall **)(ISteamUserStats_vtbl *, int))v22->RequestCurrentStats)(a1: v22, a2: 2);
      }
      else
      {
        v22->GetStat_2 = (bool (__thiscall *)(ISteamUserStats *, const char *, int *))((unsigned int)GetStat_2
                                                                                     & 0x8FFFFFFF
                                                                                     | 0x20000000);
        (*(void (__thiscall **)(ISteamUserStats_vtbl *, int))v22->RequestCurrentStats)(a1: v22, a2: 4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FA30
// Name: public: virtual void GASObject::VisitMembers(class GASStringContext __near *,struct GASObjectInterface::MemberVisitor __near *,unsigned int,class GASObjectInterface const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::VisitMembers(
        GASObject *this,
        struct GASStringContext *a2,
        struct GASObjectInterface::MemberVisitor *a3,
        unsigned int a4,
        const struct GASObjectInterface *a5)
{
  char *v5; // edi
  char *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // esi
  _DWORD *v9; // ecx
  struct GASObjectInterface::MemberVisitor *v10; // ebx
  char *v11; // edx
  signed int v12; // esi
  int v13; // eax
  int v14; // edi
  void (__thiscall *v15)(struct GASObjectInterface::MemberVisitor *, int, int, int); // edx
  const struct GASObjectInterface *v16; // ecx
  unsigned int v17; // eax
  _DWORD *v18; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ecx
  const struct GASObjectInterface *v20; // eax
  GASValue v21[4]; // [esp+Ch] [ebp-20h] BYREF
  char *v22; // [esp+1Ch] [ebp-10h]
  GASObject *v23; // [esp+24h] [ebp-8h]
  int v24; // [esp+28h] [ebp-4h]

  v5 = (char *)this + 12;
  v23 = this;
  v6 = *((char **)this + 3);
  if ( v6 != nullptr )
  {
    v8 = *((_DWORD *)v6 + 1);
    v7 = 0;
    v9 = v6 + 8;
    do
    {
      if ( *v9 != -2 )
        break;
      ++v7;
      v9 += 6;
    }
    while ( v7 <= v8 );
    v6 = v5;
  }
  else
  {
    v7 = 0;
  }
  v10 = a3;
  v11 = v6;
  v22 = v6;
  v12 = v7;
  while ( v11 != nullptr )
  {
    v13 = *(_DWORD *)v11;
    if ( *(_DWORD *)v11 == 0 || v12 > *(_DWORD *)(v13 + 4) )
      break;
    v14 = 24 * v12;
    LOBYTE(v24) = *(_BYTE *)(24 * v12 + v13 + 17);
    if ( (v24 & 1) == 0 || (a4 & 4) != 0 )
    {
      if ( *(_BYTE *)(v14 + v13 + 16) == 10 )
      {
        LOBYTE(v21[0]) = 0;
        if ( (a4 & 8) == 0 )
        {
          v16 = a5;
          if ( a5 == nullptr )
            v16 = v23 != (GASObject *)16 ? (const struct GASObjectInterface *)v23 : nullptr;
          (*(void (__thiscall **)(const struct GASObjectInterface *, struct GASStringContext *, int, GASValue *))(*(_DWORD *)v16 + 44))(
            a1: v16,
            a2,
            a3: v14 + v13 + 12,
            a4: v21);
          v10 = a3;
          v11 = v22;
        }
        (*(void (__thiscall **)(struct GASObjectInterface::MemberVisitor *, int, GASValue *, int))(v10->UmsVersion + 4))(
          a1: v10,
          a2: *(_DWORD *)v11 + v14 + 12,
          a3: v21,
          a4: v24);
        GASValue::~GASValue(this: v21, a2: v14);
      }
      else
      {
        v15 = *(void (__thiscall **)(struct GASObjectInterface::MemberVisitor *, int, int, int))(v10->UmsVersion + 4);
        v10 = a3;
        v15(a1: a3, a2: v14 + v13 + 12, a3: v14 + v13 + 16, a4: v24);
      }
      v11 = v22;
    }
    v17 = *(_DWORD *)(*(_DWORD *)v11 + 4);
    if ( v12 <= (int)v17 && ++v12 <= v17 )
    {
      v18 = (_DWORD *)(*(_DWORD *)v11 + 24 * v12 + 8);
      do
      {
        if ( *v18 != -2 )
          break;
        ++v12;
        v18 += 6;
      }
      while ( v12 <= v17 );
    }
  }
  if ( (a4 & 1) != 0 )
  {
    pNode = v23[1].pNode;
    if ( pNode != nullptr )
    {
      v20 = a5;
      if ( a5 == nullptr )
        v20 = v23 != (GASObject *)16 ? (const struct GASObjectInterface *)v23 : nullptr;
      ((void (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, struct GASStringContext *, struct GASObjectInterface::MemberVisitor *, unsigned int, const struct GASObjectInterface *))pNode[2].pNext[4].pNext)(
        a1: &pNode[2],
        a2,
        a3: v10,
        a4,
        a5: v20);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FBA0
// Name: protected: void GASObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(ISteamUserStats *this)
{
  ISteamUserStats *v1; // ebx
  int *v2; // ecx
  unsigned int v3; // eax
  unsigned int v4; // edx
  _DWORD *v5; // ecx
  int *v6; // edi
  signed int v7; // esi
  int v8; // eax
  unsigned int v9; // eax
  _DWORD *v10; // ecx
  bool (__thiscall *v11)(ISteamUserStats *); // eax
  ISteamUserStats_vtbl *v12; // esi
  ISteamUserStats_vtbl *RequestCurrentStats; // ecx
  bool (__thiscall *GetStat)(ISteamUserStats *, const char *, float *); // edx
  bool (__thiscall **p_GetStat_2)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v16; // ebx
  signed int v17; // esi
  _DWORD *v18; // ecx
  int v19; // ecx
  ISteamUserStats *v21; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = *((int **)this + 7);
  v21 = v1;
  if ( v2 != nullptr )
  {
    v4 = v2[1];
    v3 = 0;
    v5 = v2 + 2;
    do
    {
      if ( *v5 != -2 )
        break;
      ++v3;
      v5 += 6;
    }
    while ( v3 <= v4 );
    v2 = (int *)&v1[7];
  }
  else
  {
    v3 = 0;
  }
  v6 = v2;
  v7 = v3;
  while ( v6 != nullptr )
  {
    v8 = *v6;
    if ( *v6 == 0 || v7 > *(_DWORD *)(v8 + 4) )
      break;
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: (int *)(v8 + 24 * v7 + 16), a2: (int)v6);
    v9 = *(_DWORD *)(*v6 + 4);
    if ( v7 <= (int)v9 && ++v7 <= v9 )
    {
      v10 = (_DWORD *)(*v6 + 24 * v7 + 8);
      do
      {
        if ( *v10 != -2 )
          break;
        ++v7;
        v10 += 6;
      }
      while ( v7 <= v9 );
    }
  }
  LOBYTE(v11) = GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(
                  a1: (int *)&v1[8],
                  a2: (int)v6);
  v12 = v1[11].__vftable;
  if ( v12 != nullptr )
  {
    RequestCurrentStats = (ISteamUserStats_vtbl *)v12->RequestCurrentStats;
    if ( v12->RequestCurrentStats != nullptr )
    {
      GetStat = RequestCurrentStats->GetStat;
      v11 = nullptr;
      p_GetStat_2 = &RequestCurrentStats->GetStat_2;
      do
      {
        if ( *p_GetStat_2 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        v11 = (bool (__thiscall *)(ISteamUserStats *))((char *)v11 + 1);
        p_GetStat_2 += 9;
      }
      while ( (unsigned int)v11 <= (unsigned int)GetStat );
      RequestCurrentStats = v1[11].__vftable;
    }
    else
    {
      v11 = nullptr;
    }
    v16 = RequestCurrentStats;
    v17 = (signed int)v11;
    while ( v16 != nullptr )
    {
      v11 = v16->RequestCurrentStats;
      if ( v16->RequestCurrentStats == nullptr || v17 > *((_DWORD *)v11 + 1) )
        break;
      v6 = (int *)((char *)v11 + 36 * v17 + 16);
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: v6, a2: (int)v6);
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: v6 + 3, a2: (int)v6);
      v11 = *((bool (__thiscall **)(ISteamUserStats *))v16->RequestCurrentStats + 1);
      if ( v17 <= (int)v11 && ++v17 <= (unsigned int)v11 )
      {
        v18 = (_DWORD *)((char *)v16->RequestCurrentStats + 36 * v17 + 8);
        do
        {
          if ( *v18 != -2 )
            break;
          ++v17;
          v18 += 9;
        }
        while ( v17 <= (unsigned int)v11 );
      }
    }
    v1 = v21;
  }
  v19 = (int)v1[6].__vftable;
  if ( v19 != 0 )
    LOBYTE(v11) = GRefCountBaseGC<323>::Release(a1: v19, a2: (int)v6);
  return (char)v11;
}

//------------------------------------------------------------------------------
// Address: 0x1008FCB0
// Name: protected: void GASObject::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(ISteamUserStats *this)
{
  ISteamUserStats *v1; // ebx
  ISteamUserStats *v2; // ecx
  unsigned int v3; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // edi
  signed int v7; // esi
  ISteamUserStats_vtbl *v8; // eax
  bool (__thiscall *GetStat)(ISteamUserStats *, const char *, float *); // eax
  bool (__thiscall **v10)(ISteamUserStats *, const char *, int *); // ecx
  bool (__thiscall *v11)(ISteamUserStats *); // eax
  ISteamUserStats_vtbl *v12; // esi
  ISteamUserStats_vtbl *RequestCurrentStats; // ecx
  bool (__thiscall *v14)(ISteamUserStats *, const char *, float *); // edx
  bool (__thiscall **p_GetStat_2)(ISteamUserStats *, const char *, int *); // ecx
  ISteamUserStats_vtbl *v16; // ebx
  signed int v17; // esi
  _DWORD *v18; // edi
  _DWORD *v19; // ecx
  ISteamUserStats_vtbl *v20; // ecx
  ISteamUserStats *v22; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = *((ISteamUserStats **)this + 7);
  v22 = v1;
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    v3 = 0;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      ++v3;
      v5 += 6;
    }
    while ( v3 <= (unsigned int)v4 );
    v2 = v1 + 7;
  }
  else
  {
    v3 = 0;
  }
  v6 = v2;
  v7 = v3;
  while ( v6 != nullptr )
  {
    v8 = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)v8->GetStat )
      break;
    GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: (_DWORD *)&v8->SetStat_2 + 6 * v7);
    GetStat = v6->GetStat;
    if ( v7 <= (int)GetStat && ++v7 <= (unsigned int)GetStat )
    {
      v10 = &v6->GetStat_2 + 6 * v7;
      do
      {
        if ( *v10 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v10 += 6;
      }
      while ( v7 <= (unsigned int)GetStat );
    }
  }
  LOBYTE(v11) = GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: &v1[8].__vftable);
  v12 = v1[11].__vftable;
  if ( v12 != nullptr )
  {
    RequestCurrentStats = (ISteamUserStats_vtbl *)v12->RequestCurrentStats;
    if ( v12->RequestCurrentStats != nullptr )
    {
      v14 = RequestCurrentStats->GetStat;
      v11 = nullptr;
      p_GetStat_2 = &RequestCurrentStats->GetStat_2;
      do
      {
        if ( *p_GetStat_2 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        v11 = (bool (__thiscall *)(ISteamUserStats *))((char *)v11 + 1);
        p_GetStat_2 += 9;
      }
      while ( (unsigned int)v11 <= (unsigned int)v14 );
      RequestCurrentStats = v1[11].__vftable;
    }
    else
    {
      v11 = nullptr;
    }
    v16 = RequestCurrentStats;
    v17 = (signed int)v11;
    while ( v16 != nullptr )
    {
      v11 = v16->RequestCurrentStats;
      if ( v16->RequestCurrentStats == nullptr || v17 > *((_DWORD *)v11 + 1) )
        break;
      v18 = (_DWORD *)((char *)v11 + 36 * v17 + 16);
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: v18);
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: v18 + 3);
      v11 = *((bool (__thiscall **)(ISteamUserStats *))v16->RequestCurrentStats + 1);
      if ( v17 <= (int)v11 && ++v17 <= (unsigned int)v11 )
      {
        v19 = (_DWORD *)((char *)v16->RequestCurrentStats + 36 * v17 + 8);
        do
        {
          if ( *v19 != -2 )
            break;
          ++v17;
          v19 += 9;
        }
        while ( v17 <= (unsigned int)v11 );
      }
    }
    v1 = v22;
  }
  v20 = v1[6].__vftable;
  if ( v20 != nullptr )
    LOBYTE(v11) = GRefCountBaseGC<323>::CollectGarbage(this: v20);
  return (char)v11;
}

//------------------------------------------------------------------------------
// Address: 0x1008FF50
// Name: public: GASObjectInterface::GASObjectInterface(void)
// Source: json
//------------------------------------------------------------------------------
GASObjectInterface *__thiscall GASObjectInterface::GASObjectInterface(GASObjectInterface *this)
{
  *(_DWORD *)this = &GASObjectInterface::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008FF80
// Name: public: virtual GASObjectInterface::~GASObjectInterface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObjectInterface::~GASObjectInterface(GASObjectInterface *this)
{
  int v2; // edi
  int v3; // ecx

  v2 = *((_DWORD *)this + 1);
  *(_DWORD *)this = &GASObjectInterface::`vftable';
  if ( v2 != 0 )
  {
    GFxASUserData::SetLastObjectValue(this: *(GFxASUserData **)(v2 + 4), a2: nullptr, pdata: nullptr);
    if ( *(_DWORD *)(v2 + 4) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD, GASObjectInterface *))(**(_DWORD **)(v2 + 4) + 4))(
        a1: *(_DWORD *)(v2 + 4),
        a2: *(_DWORD *)v2,
        a3: this);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 1));
  }
  v3 = *((_DWORD *)this + 2);
  if ( v3 != 0 )
    GRefCountBaseGC<323>::Release(a1: v3, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1008FFE0
// Name: public: virtual class GASFunctionRef GASObjectInterface::ToFunction(void)
// Source: json
//------------------------------------------------------------------------------
_SYSTEM_ALARM_OBJECT_ACE *__stdcall GASObjectInterface::ToFunction(_SYSTEM_ALARM_OBJECT_ACE *result)
{
  LOBYTE(result->Flags) = 0;
  result->Header = 0;
  result->Mask = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090000
// Name: protected: virtual void GASObject::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::ExecuteForEachChild_GC(ISteamUserStats *this, int a2)
{
  switch ( a2 )
  {
    case 0:
      GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
      break;
    case 1:
      GASObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
      break;
    case 2:
      GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
      break;
    case 3:
      GASObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
      break;
    case 4:
      GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090060
// Name: protected: void GASPrototypeBase::InitFunctionMembers(class GASObject __near *,class GASStringContext __near *,struct GASNameFunction const __near *,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASPrototypeBase::InitFunctionMembers(
        GASPrototypeBase *this,
        int a2,
        vc_attributes::PreRangeAttribute **flags,
        const struct GASNameFunction *flags_4,
        const struct GASPropFlags *flags_8)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v5; // ebx
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v7; // edi
  const struct GASNameFunction *v8; // esi
  bool v9; // zf
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v11; // eax
  GASCFunctionObject *v12; // eax
  GASCFunctionObject *v13; // eax
  struct GASStringNode *ConstStringNode; // eax
  struct GASObject *v15; // ecx
  struct GASStringContext *v16; // eax
  GASValue v18[4]; // [esp+Ch] [ebp-28h] BYREF
  GASCFunctionObject *v19; // [esp+1Ch] [ebp-18h] BYREF
  int v20; // [esp+20h] [ebp-14h]
  char v21; // [esp+24h] [ebp-10h]
  struct GASObject *v22; // [esp+28h] [ebp-Ch]
  CTSQueue<CFunctor *,0,1>::Node_t *v23; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  v5 = (CTSQueue<CFunctor *,0,1>::Node_t *)flags;
  Prototype = GASGlobalContext::GetPrototype(this: *flags, result: (vc_attributes::InvalidCheckAttribute *)7);
  v7 = (CTSQueue<CFunctor *,0,1>::Node_t *)Prototype;
  v23 = (CTSQueue<CFunctor *,0,1>::Node_t *)Prototype;
  if ( Prototype != nullptr )
  {
    Prototype = (vc_attributes::InvalidCheckAttribute *)((Prototype[2].Value + 1) & 0x8FFFFFFF);
    v7[1].pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)Prototype;
  }
  v8 = flags_4;
  v9 = *(_DWORD *)flags_4 == 0;
  i = 0;
  if ( !v9 )
  {
    v22 = (struct GASObject *)(a2 + 16);
    do
    {
      pNext = v5->pNext[82].pNext;
      v11 = pNext->pNext[5].pNext;
      a2 = 323;
      v12 = (GASCFunctionObject *)((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, int, int *))v11)(
                                    a1: pNext,
                                    a2: 56,
                                    a3: &a2);
      if ( v12 != nullptr )
        v13 = GASCFunctionObject::GASCFunctionObject(
                this: v12,
                psc: v5,
                a3: v7,
                a4: *((void (__cdecl **)(const struct GASFnCall *))v8 + 1));
      else
        v13 = nullptr;
      v21 = 0;
      v19 = v13;
      v20 = 0;
      GASValue::GASValue(this: v18, a2: (int)v7, a3: (const struct GASFunctionRef *)&v19);
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: (GASStringManager *)v5->pNext[79].elem,
                          result: *(CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > **)v8,
                          a3: strlen(*(const char **)v8),
                          a4: 0);
      v15 = v22;
      flags = (vc_attributes::PreRangeAttribute **)ConstStringNode;
      ++*((_DWORD *)ConstStringNode + 2);
      ((void (__thiscall *)(struct GASObject *, CTSQueue<CFunctor *,0,1>::Node_t *, vc_attributes::PreRangeAttribute ***, GASValue *, const struct GASPropFlags *))v15->pNode[5].pNext)(
        a1: v15,
        a2: v5,
        a3: &flags,
        a4: v18,
        a5: flags_8);
      v16 = (struct GASStringContext *)flags;
      v9 = flags[2] == (vc_attributes::PreRangeAttribute *)1;
      flags[2] = (vc_attributes::PreRangeAttribute *)((char *)flags[2] - 1);
      if ( v9 )
        GASStringNode::ReleaseNode(a1: (int)v16);
      GASValue::~GASValue(this: v18, a2: 0);
      if ( (v21 & 2) == 0 && v19 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v19, a2: 0);
      v19 = nullptr;
      if ( (v21 & 1) == 0 && v20 != 0 )
        GRefCountBaseGC<323>::Release(a1: v20, a2: 0);
      LOBYTE(Prototype) = i + 1;
      v9 = *((_DWORD *)flags_4 + 2 * i + 2) == 0;
      v8 = (const struct GASNameFunction *)((char *)flags_4 + 8 * i + 8);
      v20 = 0;
      v7 = v23;
      ++i;
    }
    while ( !v9 );
  }
  if ( v7 != nullptr )
    LOBYTE(Prototype) = GRefCountBaseGC<323>::Release(a1: (int)v7, a2: (int)v7);
  return (char)Prototype;
}

//------------------------------------------------------------------------------
// Address: 0x100901A0
// Name: protected: bool GASPrototypeBase::SetConstructor(class GASObject __near *,class GASStringContext __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASPrototypeBase::SetConstructor@<al>(
        GASPrototypeBase *this@<ecx>,
        int a2@<edi>,
        struct GASObject *a3,
        struct GASStringContext *a4,
        const struct GASValue *a5)
{
  const struct GASFunctionRefBase *v6; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  int v9; // [esp-Ch] [ebp-20h]
  GASValue v10; // [esp+4h] [ebp-10h] BYREF
  int v11; // [esp+8h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-8h]
  char v13; // [esp+10h] [ebp-4h]

  v6 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: (int)a5, a2, a3: (int)&v11, a4: 0);
  GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(this + 1), orig: v6);
  if ( (v13 & 2) == 0 && v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2);
  v11 = 0;
  if ( (v13 & 1) == 0 && v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2);
  pNext = a3[2].pNode[5].pNext;
  v9 = *(_DWORD *)a4 + 324;
  HIBYTE(a5) = 3;
  LOBYTE(v10) = 10;
  ((void (__thiscall *)(struct GASObject *, struct GASStringContext *, int, GASValue *, char *))pNext)(
    a1: &a3[2],
    a2: a4,
    a3: v9,
    a4: &v10,
    a5: (char *)&a5 + 3);
  GASValue::~GASValue(this: &v10, a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090230
// Name: protected: bool GASPrototypeBase::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASPrototypeBase::DoesImplement(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *this,
        unsigned int penv,
        int prototype)
{
  int v4; // eax
  unsigned int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int *v9; // ecx
  int v10; // esi
  unsigned int n; // [esp+Ch] [ebp-4h]

  v4 = *((_DWORD *)this + 7);
  if ( v4 == 0 )
    return 0;
  v5 = *(_DWORD *)(v4 + 4);
  v6 = 0;
  n = v5;
  if ( v5 == 0 )
    return 0;
  while ( 1 )
  {
    v7 = **((_DWORD **)this + 7);
    v8 = *(_DWORD *)(v7 + 4 * v6);
    v9 = (int *)(v7 + 4 * v6);
    if ( v8 != 0 )
      *(_DWORD *)(v8 + 8) = (*(_DWORD *)(v8 + 8) + 1) & 0x8FFFFFFF;
    v10 = *v9;
    if ( *v9 != 0 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)(v10 + 16) + 72))(
             a1: v10 + 16,
             a2: penv,
             a3: prototype,
             a4: 1) != 0 )
        break;
      GRefCountBaseGC<323>::Release(a1: v10, a2: v6);
      v5 = n;
    }
    if ( ++v6 >= v5 )
      return 0;
  }
  GRefCountBaseGC<323>::Release(a1: v10, a2: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100902C0
// Name: public: static void GASObjectProto::AddProperty(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASObjectProto::AddProperty(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  struct GASValue *v5; // eax
  bool v6; // cc
  char v7; // al
  struct GASValue *v8; // eax
  const struct GASFunctionRefBase *v9; // eax
  GASFnCall v10; // ecx
  __vc_attributes::objectAttribute *Collector; // eax
  GASFnCall v12; // ecx
  GASFnCall v13; // edx
  GASFnCall v14; // esi
  GASFnCall v15; // esi
  int v16; // eax
  GASFnCall v18; // esi
  int v19; // [esp-Ch] [ebp-48h]
  int v20; // [esp-Ch] [ebp-48h]
  GASValue v21[4]; // [esp+4h] [ebp-38h] BYREF
  int v22; // [esp+14h] [ebp-28h] BYREF
  int v23; // [esp+18h] [ebp-24h]
  char v24; // [esp+1Ch] [ebp-20h]
  int v25; // [esp+20h] [ebp-1Ch] BYREF
  int v26; // [esp+24h] [ebp-18h]
  char v27; // [esp+28h] [ebp-14h]
  int v28; // [esp+2Ch] [ebp-10h] BYREF
  int v29; // [esp+30h] [ebp-Ch]
  char v30; // [esp+34h] [ebp-8h]
  int v31; // [esp+38h] [ebp-4h] BYREF

  v2 = a2;
  if ( (int)a2[7] < 2 )
  {
    v18 = a2[1];
    GASValue::DropRefs(this: (GASValue *)v18, a2: a1);
    LOBYTE(v18->cbSize) = 2;
    LOBYTE(v18->cItems) = 0;
  }
  else
  {
    v3 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
    v4 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
    GASValue::ToStringImpl(this: v4, a2: &v31, a3: v3, precision: -1, debug: false);
    v19 = (int)v2[6];
    v5 = GASFnCall::Arg(this: v2, a2: 1);
    GASValue::ToFunction(a1: (int)v5, a2: (int)v3, a3: (int)&v25, a4: v19);
    if ( v25 != 0 )
    {
      v6 = (int)v2[7] < 3;
      v30 = 0;
      v28 = 0;
      v29 = 0;
      if ( !v6 )
      {
        v7 = *(_BYTE *)GASFnCall::Arg(this: v2, a2: 2);
        if ( v7 == 8 || v7 == 11 )
        {
          v20 = (int)v2[6];
          v8 = GASFnCall::Arg(this: v2, a2: 2);
          v9 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: (int)v8, a2: (int)v3, a3: (int)&v22, a4: v20);
          GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)&v28, orig: v9);
          if ( (v24 & 2) == 0 && v22 != 0 )
            GRefCountBaseGC<323>::Release(a1: v22, a2: (int)v3);
          v22 = 0;
          if ( (v24 & 1) == 0 && v23 != 0 )
            GRefCountBaseGC<323>::Release(a1: v23, a2: (int)v3);
        }
      }
      v10 = v2[6];
      v3 = *(tagRID_DEVICE_INFO_KEYBOARD **)(v10[3].cbSize + 656);
      Collector = GASEnvironment::GetCollector(this: v10);
      GASValue::GASValue(
        this: v21,
        a2: (unsigned int)v3,
        a3: (const struct GASFunctionRef *)&v25,
        a4: (const struct GASFunctionRef *)&v28,
        a5: (struct GMemoryHeap *)v3,
        pCC: (struct GASRefCountCollector *)Collector);
      v12 = v2[2];
      v13 = v2[6];
      HIBYTE(a2) = 0;
      (*(void (__thiscall **)(GASFnCall, GASFnCall, int *, GASValue *, char *))(v12->cbSize + 40))(
        a1: v12,
        a2: v13 + 3,
        a3: &v31,
        a4: v21,
        a5: (char *)&a2 + 3);
      v14 = v2[1];
      GASValue::DropRefs(this: (GASValue *)v14, a2: (int)v3);
      LOBYTE(v14->cbSize) = 2;
      LOBYTE(v14->cItems) = 1;
      GASValue::~GASValue(this: v21, a2: (int)v3);
      if ( (v30 & 2) == 0 && v28 != 0 )
        GRefCountBaseGC<323>::Release(a1: v28, a2: (int)v3);
      v28 = 0;
      if ( (v30 & 1) == 0 && v29 != 0 )
        GRefCountBaseGC<323>::Release(a1: v29, a2: (int)v3);
    }
    else
    {
      v15 = v2[1];
      GASValue::DropRefs(this: (GASValue *)v15, a2: (int)v3);
      LOBYTE(v15->cbSize) = 2;
      LOBYTE(v15->cItems) = 0;
    }
    if ( (v27 & 2) == 0 && v25 != 0 )
      GRefCountBaseGC<323>::Release(a1: v25, a2: (int)v3);
    v25 = 0;
    if ( (v27 & 1) == 0 && v26 != 0 )
      GRefCountBaseGC<323>::Release(a1: v26, a2: (int)v3);
    v16 = v31;
    v26 = 0;
    if ( (*(_DWORD *)(v31 + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090470
// Name: public: static void GASObjectProto::Watch(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASObjectProto::Watch(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  struct GASValue *v3; // eax
  bool v4; // cc
  tagWNDCLASSW *v5; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v6; // edi
  unsigned __int8 *v7; // eax
  char v8; // al
  GASFnCall v9; // esi
  char v10; // bl
  GASFnCall *v11; // eax
  bool v12; // zf
  GASFnCall v13; // esi
  GASFnCall v14; // esi
  int v15; // [esp-8h] [ebp-28h]
  GASFnCall v16; // [esp-4h] [ebp-24h]
  GASValue v17[4]; // [esp+4h] [ebp-1Ch] BYREF
  int v18; // [esp+14h] [ebp-Ch] BYREF
  int v19; // [esp+18h] [ebp-8h]
  char v20; // [esp+1Ch] [ebp-4h]

  v2 = a2;
  if ( (int)a2[7] < 2 )
  {
    v14 = a2[1];
    GASValue::DropRefs(this: (GASValue *)v14, a2: a1);
    LOBYTE(v14->cbSize) = 2;
    LOBYTE(v14->cItems) = 0;
  }
  else
  {
    v16 = a2[6];
    v3 = GASFnCall::Arg(this: a2, a2: 1);
    GASValue::ToFunction(a1: (int)v3, a2: a1, a3: (int)&v18, a4: (int)v16);
    if ( v18 != 0 )
    {
      v4 = (int)v2[7] < 3;
      LOBYTE(v17[0]) = 0;
      if ( !v4 )
      {
        v5 = (tagWNDCLASSW *)GASFnCall::Arg(this: v2, a2: 2);
        GASValue::operator=(this: (int)v17, v: v5);
      }
      v15 = a1;
      v6 = (tagRID_DEVICE_INFO_KEYBOARD *)v2[6];
      v7 = (unsigned __int8 *)GASFnCall::Arg(this: v2, a2: 0);
      GASValue::ToStringImpl(this: v7, (int *)&a2, a3: v6, precision: -1, debug: false);
      v8 = (*(int (__thiscall **)(GASFnCall, GASFnCall, GASFnCall **, int *, GASValue *))(v2[2]->cbSize + 76))(
             a1: v2[2],
             a2: v2[6] + 3,
             a3: &a2,
             a4: &v18,
             a5: v17);
      v9 = v2[1];
      v10 = v8;
      GASValue::DropRefs(this: (GASValue *)v9, (int)&a2);
      LOBYTE(v9->cItems) = v10;
      LOBYTE(v9->cbSize) = 2;
      v11 = a2;
      v12 = a2[2] == (GASFnCall)1;
      a2[2] = (GASFnCall)((char *)a2[2] - 1);
      a1 = v15;
      if ( v12 )
        GASStringNode::ReleaseNode(a1: (int)v11);
      GASValue::~GASValue(this: v17, a2: v15);
    }
    else
    {
      v13 = v2[1];
      GASValue::DropRefs(this: (GASValue *)v13, a2: a1);
      LOBYTE(v13->cbSize) = 2;
      LOBYTE(v13->cItems) = 0;
    }
    if ( (v20 & 2) == 0 && v18 != 0 )
      GRefCountBaseGC<323>::Release(a1: v18, a2: a1);
    v18 = 0;
    if ( (v20 & 1) == 0 && v19 != 0 )
      GRefCountBaseGC<323>::Release(a1: v19, a2: a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090590
// Name: private: static void GASObjectCtorFunction::RegisterClassA(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASObjectCtorFunction::RegisterClassA(_IMAGE_SYMBOL_EX a1)
{
  unsigned int Short; // esi
  int v2; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  vc_attributes::PostAttribute *dwType; // ebx
  unsigned __int8 *v5; // eax
  char v6; // al
  struct GASValue *v7; // eax
  int v8; // esi
  char v9; // al
  char v10; // bl
  char v11; // al
  int v12; // esi
  char v13; // bl
  tagRID_DEVICE_INFO_KEYBOARD *v14; // edi
  unsigned __int8 *v15; // eax
  int v16; // eax
  bool v17; // zf
  unsigned int v18; // eax
  int v19; // [esp-8h] [ebp-20h]
  int v20; // [esp+8h] [ebp-10h] BYREF
  int v21; // [esp+Ch] [ebp-Ch]
  char v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+14h] [ebp-4h] BYREF

  Short = a1.N.Name.Short;
  v2 = *(_DWORD *)(a1.N.Name.Short + 4);
  GASValue::DropRefs(this: (GASValue *)v2, a2: v2);
  *(_BYTE *)v2 = 2;
  *(_BYTE *)(v2 + 4) = 0;
  if ( *(int *)(Short + 28) >= 2 )
  {
    v3 = *(tagRID_DEVICE_INFO_KEYBOARD **)(Short + 24);
    dwType = (vc_attributes::PostAttribute *)v3[5].dwType;
    v5 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)Short, a2: 0);
    GASValue::ToStringImpl(this: v5, a2: (int *)&a1, a3: v3, precision: -1, debug: false);
    v6 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)Short, a2: 1);
    if ( v6 == 8 || v6 == 11 )
    {
      v19 = *(_DWORD *)(Short + 24);
      v7 = GASFnCall::Arg(this: (GASFnCall *)Short, a2: 1);
      GASValue::ToFunction(a1: (int)v7, a2: (int)v3, a3: (int)&v20, a4: v19);
      GASGlobalContext::RegisterClassA(
        this: dwType,
        className: (_IMAGE_SYMBOL_EX *)(*(_DWORD *)(Short + 24) + 120),
        a3: (unsigned int)&a1,
        a4: (struct GASFunctionRefBase *)&v20);
      v8 = *(_DWORD *)(Short + 4);
      v10 = v9;
      GASValue::DropRefs(this: (GASValue *)v8, a2: (int)v3);
      *(_BYTE *)v8 = 2;
      *(_BYTE *)(v8 + 4) = v10;
      if ( (v22 & 2) == 0 && v20 != 0 )
        GRefCountBaseGC<323>::Release(a1: v20, a2: (int)v3);
      v20 = 0;
      if ( (v22 & 1) == 0 && v21 != 0 )
        GRefCountBaseGC<323>::Release(a1: v21, a2: (int)v3);
    }
    else if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)Short, a2: 1) == 1 )
    {
      v11 = GASGlobalContext::UnregisterClassA(
              this: (GFxMeshCacheManager *)dwType,
              a2: (struct GASStringContext *)(*(_DWORD *)(Short + 24) + 120),
              key: &a1);
      v12 = *(_DWORD *)(Short + 4);
      v13 = v11;
      GASValue::DropRefs(this: (GASValue *)v12, a2: (int)v3);
      *(_BYTE *)v12 = 2;
      *(_BYTE *)(v12 + 4) = v13;
    }
    else
    {
      v14 = *(tagRID_DEVICE_INFO_KEYBOARD **)(Short + 24);
      v15 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)Short, a2: 1);
      GASValue::ToStringImpl(this: v15, a2: &v23, a3: v14, precision: -1, debug: false);
      GASEnvironment::LogScriptError(
        this: *(GASEnvironment **)(Short + 24),
        a2: "Error: Second parameter of Object.registerClass(%s, %s) should be function or null\n",
        *(const char **)a1.N.Name.Short,
        *(const char **)v23);
      v16 = v23;
      v17 = (*(_DWORD *)(v23 + 8))-- == 1;
      if ( v17 )
        GASStringNode::ReleaseNode(a1: v16);
    }
    v18 = a1.N.Name.Short;
    v17 = (*(_DWORD *)(a1.N.Name.Short + 8))-- == 1;
    if ( v17 )
      GASStringNode::ReleaseNode(a1: v18);
  }
  else
  {
    GASEnvironment::LogScriptError(
      this: *(GASEnvironment **)(Short + 24),
      a2: "Error: Too few parameters for Object.registerClass (%d)",
      *(_DWORD *)(Short + 28));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090980
// Name: protected: GASObject::GASObject(class GASRefCountCollector __near *)
// Source: json
//------------------------------------------------------------------------------
_EVENTLOGRECORD *__userpurge GASObject::GASObject@<eax>(int a1@<ecx>, int a2@<edi>, _EVENTLOGRECORD *result)
{
  int v4; // ecx

  *(_DWORD *)(a1 + 4) = result;
  *(_DWORD *)(a1 + 8) = 1;
  *(_DWORD *)(a1 + 16) = &GASObjectInterface::`vftable';
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)a1 = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(a1 + 16) = &off_102A45C0;
  *(_DWORD *)(a1 + 28) = 0;
  *(_BYTE *)(a1 + 40) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  *(_WORD *)(a1 + 48) = 0;
  v4 = *(_DWORD *)(a1 + 24);
  if ( v4 != 0 )
    GRefCountBaseGC<323>::Release(a1: v4, a2);
  *(_DWORD *)(a1 + 24) = 0;
  return (_EVENTLOGRECORD *)a1;
}

//------------------------------------------------------------------------------
// Address: 0x100909E0
// Name: public: virtual enum GASObjectInterface::ObjectType GASObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASObject::GetObjectType(CTSQueue<CFunctor *,0,1> *this)
{
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x100909F0
// Name: public: GASObject::GASObject(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASObject *__userpurge GASObject::GASObject@<eax>(GASObject *this@<ecx>, int a2@<edi>, GASGlobalContext **psc)
{
  struct GASRefCountCollector *GC; // eax
  int v5; // ecx

  if ( *psc != nullptr )
    GC = GASGlobalContext::GetGC(this: *psc);
  else
    GC = nullptr;
  this->sequence = (int)GC;
  *((_DWORD *)this + 2) = 1;
  *((_DWORD *)this + 4) = &GASObjectInterface::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A45C0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 40) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_WORD *)this + 24) = 0;
  v5 = *((_DWORD *)this + 6);
  if ( v5 != 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2);
  *((_DWORD *)this + 6) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090A60
// Name: public: GASObject::GASObject(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
GASObject *__thiscall GASObject::GASObject(
        GASObject *this,
        GASGlobalContext **psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4)
{
  struct GASRefCountCollector *GC; // eax

  if ( *psc != nullptr )
    GC = GASGlobalContext::GetGC(this: *psc);
  else
    GC = nullptr;
  this->sequence = (int)GC;
  *((_DWORD *)this + 2) = 1;
  *((_DWORD *)this + 4) = &GASObjectInterface::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A45C0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 40) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_WORD *)this + 24) = 0;
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 2), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090AD0
// Name: public: GASObject::GASObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GASObject *__thiscall GASObject::GASObject(GASObject *this, struct GASEnvironment *a2)
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  this->sequence = (int)GASEnvironment::GetCollector(this: (_DWORD **)a2);
  *((_DWORD *)this + 2) = 1;
  *((_DWORD *)this + 4) = &GASObjectInterface::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A45C0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 40) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_WORD *)this + 24) = 0;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *((vc_attributes::PreRangeAttribute **)a2 + 30),
                                                    result: (vc_attributes::InvalidCheckAttribute *)1);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 2),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)a2 + 15,
    psc_4: Prototype);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090B40
// Name: public: virtual bool GASObject::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASObject::GetMemberRaw(
        CTSQueue<CFunctor *,0,1> *this,
        _IMAGE_SYMBOL_EX *psc,
        _EXIT_THREAD_DEBUG_INFO *ikey,
        GASValue *a4)
{
  CTSQueue<CFunctor *,0,1> *Next; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *v5; // eax
  int v6; // ebx
  int Index; // eax
  const struct GASFunctionRefBase *v9; // edi
  GASValue *v10; // esi
  bool v11; // zf
  tagWNDCLASSW *v12; // eax
  _EXIT_THREAD_DEBUG_INFO *v13; // ebx
  int *dwExitCode; // ecx
  CFunctor *v15; // ecx
  int DepthAndSequence; // eax
  int *p_DepthAndSequence; // esi
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  bool resolveHandlerSet; // [esp+13h] [ebp-1h]

  Next = (CTSQueue<CFunctor *,0,1> *)((char *)this - 16);
  resolveHandlerSet = false;
  if ( psc->N.ShortName[4] <= 6u )
  {
    v13 = ikey;
    if ( *(_DWORD *)(ikey->dwExitCode + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)ikey->dwExitCode);
    dwExitCode = (int *)v13->dwExitCode;
    v11 = *(_DWORD *)(v13->dwExitCode + 4) == 0;
    ikey = v13;
    if ( v11 )
      GASStringNode::ResolveLowercase_Impl(a1: dwExitCode);
    if ( Next != nullptr )
    {
      while ( 1 )
      {
        v15 = *(CFunctor **)(v13->dwExitCode + 4);
        if ( *(CFunctor **)(*(_DWORD *)(psc->N.Name.Short + 320) + 4) == v15 )
          goto LABEL_14;
        if ( *(CFunctor **)(*(_DWORD *)(psc->N.Name.Short + 336) + 4) == v15 )
        {
LABEL_17:
          v9 = (const struct GASFunctionRefBase *)&Next[1];
          if ( *(_DWORD *)v9 == 0 )
            goto LABEL_16;
          GASValue::SetAsFunction(this: a4, func: v9);
          return 1;
        }
        DepthAndSequence = Next->m_FreeNodes.m_Head.value32.DepthAndSequence;
        p_DepthAndSequence = &Next->m_FreeNodes.m_Head.value32.DepthAndSequence;
        if ( DepthAndSequence != 0 )
        {
          v18 = GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString::NoCaseKey>(
                  this: &Next->m_FreeNodes.m_Head.value32.DepthAndSequence,
                  a2: (int *)&ikey,
                  a3: *(_DWORD *)(v13->dwExitCode + 12) & *(_DWORD *)(DepthAndSequence + 4));
          if ( v18 >= 0 && Next != (CTSQueue<CFunctor *,0,1> *)-28 )
          {
            v19 = *p_DepthAndSequence;
            if ( *p_DepthAndSequence != 0 && v18 <= *(_DWORD *)(v19 + 4) )
            {
              v20 = 3 * v18;
              v11 = *(_BYTE *)(v19 + 8 * v20 + 16) == 10;
              v12 = (tagWNDCLASSW *)(v19 + 8 * v20 + 16);
              if ( v11 && Next != (CTSQueue<CFunctor *,0,1> *)((char *)this - 16) )
                return (unsigned __int8)(*(CTSQueue<CFunctor *,0,1>::Node_t *(__thiscall **)(CInterlockedIntT<int> *, _IMAGE_SYMBOL_EX *, _EXIT_THREAD_DEBUG_INFO *, GASValue *))(Next->m_Count.m_value + 44))(
                                          a1: &Next->m_Count,
                                          a2: psc,
                                          a3: v13,
                                          a4);
LABEL_22:
              GASValue::operator=(this: (int)a4, v: v12);
              return 1;
            }
          }
        }
        if ( !resolveHandlerSet && Next[1].m_Head.value.pNode != nullptr )
        {
          GASValue::SetAsResolveHandler(this: a4, a2: (int)Next, func: (const struct GASFunctionRefBase *)&Next[1]);
          resolveHandlerSet = true;
        }
        Next = (CTSQueue<CFunctor *,0,1> *)Next->m_FreeNodes.m_Head.value.Next;
        if ( Next == nullptr )
          return 0;
      }
    }
    return 0;
  }
  if ( this == (CTSQueue<CFunctor *,0,1> *)16 )
    return 0;
  while ( 1 )
  {
    v5 = (CTSQueue<CFunctor *,0,1>::Node_t *)ikey->dwExitCode;
    if ( ikey->dwExitCode == *(_DWORD *)(psc->N.Name.Short + 320) )
      break;
    if ( v5 == *(CTSQueue<CFunctor *,0,1>::Node_t **)(psc->N.Name.Short + 336) )
      goto LABEL_17;
    v6 = Next->m_FreeNodes.m_Head.value32.DepthAndSequence;
    if ( v6 != 0 )
    {
      Index = GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
                this: &Next->m_FreeNodes.m_Head.value32.DepthAndSequence,
                a2: ikey,
                a3: *(_DWORD *)(v6 + 4) & (int)v5[1].elem);
      if ( Index >= 0 && Next != (CTSQueue<CFunctor *,0,1> *)-28 && Index <= *(_DWORD *)(v6 + 4) )
      {
        v11 = *(_BYTE *)(v6 + 24 * Index + 16) == 10;
        v12 = (tagWNDCLASSW *)(v6 + 24 * Index + 16);
        if ( v11 && Next != (CTSQueue<CFunctor *,0,1> *)((char *)this - 16) )
          return (unsigned __int8)(*(CTSQueue<CFunctor *,0,1>::Node_t *(__thiscall **)(CInterlockedIntT<int> *, _IMAGE_SYMBOL_EX *, _EXIT_THREAD_DEBUG_INFO *, GASValue *))(Next->m_Count.m_value + 44))(
                                    a1: &Next->m_Count,
                                    a2: psc,
                                    a3: ikey,
                                    a4);
        goto LABEL_22;
      }
    }
    if ( !resolveHandlerSet && Next[1].m_Head.value.pNode != nullptr )
    {
      GASValue::SetAsResolveHandler(this: a4, a2: (int)Next, func: (const struct GASFunctionRefBase *)&Next[1]);
      resolveHandlerSet = true;
    }
    Next = (CTSQueue<CFunctor *,0,1> *)Next->m_FreeNodes.m_Head.value.Next;
    if ( Next == nullptr )
      return 0;
  }
LABEL_14:
  v9 = (const struct GASFunctionRefBase *)Next->m_FreeNodes.m_Head.value.Next;
  if ( v9 != nullptr )
  {
    GASValue::SetAsObject(this: a4, a2: (struct GASObject *)v9);
    return 1;
  }
  else
  {
LABEL_16:
    v10 = a4;
    GASValue::DropRefs(this: a4, a2: (int)v9);
    *(_BYTE *)v10 = 0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090D70
// Name: public: virtual bool GASObject::HasMember(class GASStringContext __near *,class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::HasMember(
        CTSQueue<CFunctor *,0,1> *this,
        _IMAGE_SYMBOL_EX *psc,
        CTSQueue<CFunctor *,0,1>::NodeLink_t *name,
        bool inclPrototypes)
{
  int sequence; // esi
  int *p_sequence; // ecx
  int Index; // eax
  int v8; // eax
  int v9; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // eax
  _LARGE_INTEGER member; // [esp+Ch] [ebp-10h] BYREF

  sequence = this->m_Tail.value.sequence;
  p_sequence = &this->m_Tail.value.sequence;
  LOWORD(member.LowPart) = 0;
  if ( sequence != 0
    && (Index = GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
                  this: p_sequence,
                  a2: name,
                  a3: *(_DWORD *)(sequence + 4) & (int)name->value.pNode[1].elem)) >= 0
    && (v8 = sequence + 24 * Index + 12) != 0 )
  {
    v9 = v8 + 4;
    GASValue::operator=(this: (int)&member, v: (tagWNDCLASSW *)(v8 + 4));
    BYTE1(member.LowPart) = *(_BYTE *)(v9 + 1);
    GASValue::~GASValue(this: (GASValue *)&member, a2: (int)name);
  }
  else if ( inclPrototypes && (pNode = this->m_Tail.value.pNode) != nullptr )
  {
    ((void (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, _IMAGE_SYMBOL_EX *, CTSQueue<CFunctor *,0,1>::NodeLink_t *, int))pNode[2].pNext[4].elem)(
      a1: &pNode[2],
      a2: psc,
      a3: name,
      a4: 1);
    GASValue::~GASValue(this: (GASValue *)&member, a2: (int)name);
  }
  else
  {
    GASValue::~GASValue(this: (GASValue *)&member, a2: (int)name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090E20
// Name: protected: void GASPrototypeBase::Init(class GASObject __near *,class GASStringContext __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASPrototypeBase::Init(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *this@<ecx>,
        int a2@<edi>,
        CMaterialVar *pthis,
        __int128 psc)
{
  int v5; // ebx
  int *v6; // eax
  int v7; // esi
  int v8; // edi
  GASValue *v9; // eax
  GASValue v10[4]; // [esp+Ch] [ebp-10h] BYREF

  GASValue::GASValue(this: v10, a2, a3: (const struct GASFunctionRef *)DWORD1(psc));
  v5 = psc;
  GASPrototypeBase::SetConstructor(
    (GASPrototypeBase *)this,
    a2,
    a3: (struct GASObject *)pthis,
    a4: (struct GASStringContext *)psc,
    a5: (const struct GASValue *)v10);
  GASValue::~GASValue(this: v10, a2);
  v6 = (int *)DWORD1(this->m_pfnProxied);
  v7 = *(_DWORD *)psc;
  v6 += 4;
  BYTE7(psc) = 3;
  v8 = *v6;
  LODWORD(psc) = v6;
  v9 = GASValue::GASValue(this: v10, a2: (struct GASObject *)pthis);
  (*(void (__thiscall **)(_DWORD, int, int, GASValue *, char *))(v8 + 40))(
    a1: psc,
    a2: v5,
    a3: v7 + 316,
    a4: v9,
    a5: (char *)&psc + 7);
  GASValue::~GASValue(this: v10, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10090EA0
// Name: public: static void GASObjectProto::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASObjectProto::GlobalCtor(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  GASValue *v3; // ecx
  char v4; // al
  GASFnCall *v5; // eax
  bool v6; // zf
  GASFnCall v7; // eax
  GASObject *p_cxItem; // eax
  int v9; // ecx
  int (__thiscall *v10)(int, int, GASFnCall **); // edx
  GASObject *v11; // eax
  __vc_attributes::async_uuidAttribute *v12; // ecx
  struct GASObject *v13; // ebx
  tagALTTABINFO *v14; // edi
  tagWNDCLASSW v15; // [esp+8h] [ebp-30h] BYREF
  char v16; // [esp+30h] [ebp-8h]
  struct GASObject *v17; // [esp+34h] [ebp-4h]

  v2 = a2;
  if ( (int)a2[7] < 1 )
    goto LABEL_18;
  v3 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
  LOBYTE(v15.hInstance) = 0;
  v4 = *(_BYTE *)v3;
  if ( *(_BYTE *)v3 == 3 || v4 == 4 )
  {
    *(double *)&v15.lpfnWndProc = GASValue::ToNumber(this: v3, a2: 1, a3: a1, result: (_SERVICE_STATUS *)v2[6]);
    LOBYTE(v15.style) = 3;
    GASValue::operator=(this: (int)&v15.hInstance, v: &v15);
LABEL_7:
    GASValue::~GASValue(this: (GASValue *)&v15, a2: 1);
    goto LABEL_14;
  }
  switch ( v4 )
  {
    case 2:
      LOBYTE(v15.lpfnWndProc) = GASValue::ToBool(a1: (char *)v3, a2: a1, result: (tagPOLYTEXTW *)v2[6]);
      LOBYTE(v15.style) = 2;
      GASValue::operator=(this: (int)&v15.hInstance, v: &v15);
      goto LABEL_7;
    case 5:
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)v3,
        (int *)&a2,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v2[6],
        precision: -1,
        debug: false);
      LOBYTE(v15.style) = 5;
      v15.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))a2;
      a2[2] = (GASFnCall)((char *)a2[2] + 1);
      GASValue::operator=(this: (int)&v15.hInstance, v: &v15);
      GASValue::~GASValue(this: (GASValue *)&v15, a2: 1);
      v5 = a2;
      v6 = a2[2] == (GASFnCall)1;
      a2[2] = (GASFnCall)((char *)a2[2] - 1);
      if ( v6 )
        GASStringNode::ReleaseNode(a1: (int)v5);
LABEL_14:
      if ( LOBYTE(v15.hInstance) != 0 && LOBYTE(v15.hInstance) != 10 )
      {
        GASValue::operator=(this: (int)v2[1], v: (tagWNDCLASSW *)&v15.hInstance);
        GASValue::~GASValue(this: (GASValue *)&v15.hInstance, a2: 1);
        return;
      }
      break;
    case 6:
    case 7:
      GASValue::operator=(this: (int)&v15.hInstance, v: (tagWNDCLASSW *)v3);
      goto LABEL_14;
    default:
      break;
  }
  GASValue::~GASValue(this: (GASValue *)&v15.hInstance, a2: 1);
LABEL_18:
  v7 = v2[2];
  if ( v7 != nullptr )
  {
    p_cxItem = (GASObject *)&v7[-1].cxItem;
    if ( p_cxItem != nullptr )
      p_cxItem[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&p_cxItem[1].pNode->pNext + 1) & 0x8FFFFFFF);
  }
  else
  {
    v9 = *(_DWORD *)(v2[6][3].cbSize + 656);
    v10 = *(int (__thiscall **)(int, int, GASFnCall **))(*(_DWORD *)v9 + 40);
    a2 = (GASFnCall *)323;
    v11 = (GASObject *)v10(a1: v9, a2: 52, a3: &a2);
    if ( v11 != nullptr )
      p_cxItem = GASObject::GASObject(this: v11, a2: (struct GASEnvironment *)v2[6]);
    else
      p_cxItem = nullptr;
  }
  v12 = (__vc_attributes::async_uuidAttribute *)v2[6];
  v17 = p_cxItem;
  GASEnvironment::GetConstructor(this: v12, className: (const char *)&v15.lpszMenuName, a3: 1);
  v13 = v17;
  v14 = v2[6] + 3;
  HIBYTE(a2) = 3;
  GASValue::GASValue(this: (GASValue *)&v15, a2: (int)v14, a3: (const struct GASFunctionRef *)&v15.lpszMenuName);
  ((void (__thiscall *)(struct GASObject *, tagALTTABINFO *, unsigned int, tagWNDCLASSW *, char *))v13[2].pNode[5].pNext)(
    a1: &v13[2],
    a2: v14,
    a3: v14->cbSize + 324,
    a4: &v15,
    a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: (GASValue *)&v15, a2: (int)v14);
  GASValue::SetAsObject(this: (GASValue *)v2[1], a2: v13);
  if ( (v16 & 2) == 0 && v15.lpszMenuName != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v15.lpszMenuName, a2: (int)v13);
  v15.lpszMenuName = nullptr;
  if ( (v16 & 1) == 0 && v15.lpszClassName != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v15.lpszClassName, a2: (int)v13);
  v15.lpszClassName = nullptr;
  if ( v13 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v13, a2: (int)v13);
}

//------------------------------------------------------------------------------
// Address: 0x10091080
// Name: public: GASObjectCtorFunction::GASObjectCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASObjectCtorFunction *__thiscall GASObjectCtorFunction::GASObjectCtorFunction(
        GASObjectCtorFunction *this,
        _REASON_CONTEXT *psc)
{
  void *v3; // ecx

  GASCFunctionObject::GASCFunctionObject(
    (GASCFunctionObject *)this,
    func: psc,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASObjectProto::GlobalCtor);
  this->cbSize = (unsigned int)&GASObjectCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  this->rcMonitor.bottom = (int)&GASObjectCtorFunction::`vftable'{for `GASObjectInterface'};
  GASNameFunction::AddConstMembers(
    pobj: v3,
    psc: (int)&this->rcMonitor.bottom,
    psca: (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    a4: (struct GASObject **)GASObjectCtorFunction::StaticFunctionTable,
    a5: 7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100914D0
// Name: protected: virtual void GASObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::Finalize_GC(GASObject *this)
{
  int *v2; // ecx
  int v3; // edi

  GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>(this: (ISteamMatchmakingServerListResponse *)this + 7);
  v2 = *((int **)this + 11);
  if ( v2 != nullptr )
  {
    GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>(this: v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 11));
  }
  v3 = *((_DWORD *)this + 5);
  if ( v3 != 0 )
  {
    GFxASUserData::SetLastObjectValue(this: *(GFxASUserData **)(v3 + 4), a2: nullptr, pdata: nullptr);
    if ( *(_DWORD *)(v3 + 4) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD, GASObject *))(**(_DWORD **)(v3 + 4) + 4))(
        a1: *(_DWORD *)(v3 + 4),
        a2: *(_DWORD *)v3,
        a3: this + 2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 5));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091540
// Name: public: virtual bool GASObject::DeleteMember(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::DeleteMember(GASObject *this, _IMAGE_SYMBOL_EX *name, _IMAGE_SYMBOL_EX *a3)
{
  _DWORD *v3; // esi
  int **v4; // eax
  int *v5; // ecx
  int *v6; // eax
  int v7; // ecx
  int v9; // [esp+Ch] [ebp-8h] BYREF

  v3 = (_DWORD *)this + 3;
  v4 = (int **)GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::FindCaseCheck(
                 this: (char *)this + 12,
                 a2: &v9,
                 key: a3,
                 caseSensitive: name->N.ShortName[4] > 6u);
  v5 = *v4;
  v6 = v4[1];
  if ( v5 == nullptr )
    return 0;
  v7 = *v5;
  if ( v7 == 0 || (int)v6 > *(_DWORD *)(v7 + 4) || (*(_BYTE *)(v7 + 24 * (_DWORD)v6 + 17) & 2) != 0 )
    return 0;
  if ( a3->N.Name.Short == *(_DWORD *)(name->N.Name.Short + 416) )
    GASStringContext::InvalidateOptAdvanceList(this: (GASStringContext *)name);
  GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::RemoveAlt<GASString>(
    this: v3,
    a2: (int *)a3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091A30
// Name: public: virtual GASObject::~GASObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::~GASObject(GASObject *this)
{
  int *v2; // edi
  GASObject *v3; // ebx
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  int sequence; // edi
  int pNode; // ebx

  v2 = *((int **)this + 11);
  v3 = this + 2;
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &off_102A45C0;
  if ( v2 != nullptr )
  {
    GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>(this: v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  }
  if ( (*(_BYTE *)(this + 5) & 2) == 0 )
  {
    v4 = *((_DWORD *)this + 8);
    if ( v4 != 0 )
      GRefCountBaseGC<323>::Release(a1: v4, a2: (int)v2);
  }
  v5 = (*(_BYTE *)(this + 5) & 1) == 0;
  *((_DWORD *)this + 8) = 0;
  if ( v5 )
  {
    v6 = *((_DWORD *)this + 9);
    if ( v6 != 0 )
      GRefCountBaseGC<323>::Release(a1: v6, a2: (int)v2);
  }
  *((_DWORD *)this + 9) = 0;
  GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>(this: (ISteamMatchmakingServerListResponse *)this + 7);
  sequence = v3->sequence;
  v3->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASObjectInterface::`vftable';
  if ( sequence != 0 )
  {
    GFxASUserData::SetLastObjectValue(this: *(GFxASUserData **)(sequence + 4), a2: nullptr, pdata: nullptr);
    if ( *(_DWORD *)(sequence + 4) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD, GASObject *))(**(_DWORD **)(sequence + 4) + 4))(
        a1: *(_DWORD *)(sequence + 4),
        a2: *(_DWORD *)sequence,
        a3: v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3->sequence);
  }
  pNode = (int)v3[1].pNode;
  if ( pNode != 0 )
    GRefCountBaseGC<323>::Release(a1: pNode, a2: sequence);
  this->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GRefCountBaseGC<323>::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10091AF0
// Name: public: virtual bool GASObject::FindMember(class GASStringContext __near *,class GASString const __near &,class GASMember __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctor *,0,1>::Node_t *__stdcall GASObject::FindMember(
        _IMAGE_SYMBOL_EX *result,
        _IMAGE_SYMBOL_EX *key,
        int pmember)
{
  return (CTSQueue<CFunctor *,0,1>::Node_t *)GASStringHashBase<GASMember,GHashUncachedLH_GC<GASString,GASMember,GASStringHashFunctor,323>>::GetCaseCheck(
                                               key,
                                               caseSensitive: pmember,
                                               a3: result->N.ShortName[4] > 6u);
}

//------------------------------------------------------------------------------
// Address: 0x10091B20
// Name: public: bool GASObject::InvokeWatchpoint(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::InvokeWatchpoint(char *this, int a2, _IMAGE_SYMBOL_EX *prop, tagWNDCLASSW *newVal, int a5)
{
  void (__stdcall *v6)(int, _IMAGE_SYMBOL_EX *, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **); // eax
  bool v7; // cf
  bool v8; // zf
  int v9; // edi
  __vc_attributes::iid_isAttribute *v10; // esi
  int v11; // eax
  GRefCountNTSImpl *v12; // ebx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  int i; // edi
  _DWORD v19[5]; // [esp+Ch] [ebp-5Ch] BYREF
  char v20; // [esp+20h] [ebp-48h]
  int v21; // [esp+24h] [ebp-44h]
  int v22; // [esp+28h] [ebp-40h]
  int v23; // [esp+2Ch] [ebp-3Ch]
  char v24; // [esp+30h] [ebp-38h] BYREF
  unsigned int Short; // [esp+34h] [ebp-34h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *oldVal; // [esp+40h] [ebp-28h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v27; // [esp+50h] [ebp-18h] BYREF
  char *v28; // [esp+60h] [ebp-8h]
  int v29; // [esp+64h] [ebp-4h]

  v6 = *(void (__stdcall **)(int, _IMAGE_SYMBOL_EX *, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*((_DWORD *)this + 4) + 16);
  LOBYTE(oldVal) = 0;
  v28 = this + 16;
  v6(a1: a2, a2: prop, a3: &oldVal);
  v7 = *(_BYTE *)(a2 + 124) < 6u;
  v8 = *(_BYTE *)(a2 + 124) == 6;
  LOBYTE(v27) = 0;
  LOBYTE(v29) = !v7 && !v8;
  v9 = GASStringHashBase<GASObject::Watchpoint,GHashUncachedLH_GC<GASString,GASObject::Watchpoint,GASStringHashFunctor,323>>::GetCaseCheck(
         this: *((int **)this + 11),
         a2: (int)prop,
         a3: v29);
  if ( v9 != 0 && *((_DWORD *)this + 11) != 0 )
  {
    *(_DWORD *)(a2 + 8) += 16;
    v10 = (__vc_attributes::iid_isAttribute *)(a2 + 8);
    if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
      GASPagedStack<GASValue,32>::PushPage(this: v10);
    if ( v10->limited_expression != nullptr )
      GASValue::GASValue(this: (GASValue *)v10->limited_expression, v: (tagWNDCLASSW *)(v9 + 12));
    v10->limited_expression += 16;
    if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
      GASPagedStack<GASValue,32>::PushPage(this: v10);
    if ( v10->limited_expression != nullptr )
      GASValue::GASValue(this: (GASValue *)v10->limited_expression, v: newVal);
    v10->limited_expression += 16;
    if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
      GASPagedStack<GASValue,32>::PushPage(this: v10);
    if ( v10->limited_expression != nullptr )
      GASValue::GASValue(this: (GASValue *)v10->limited_expression, v: (tagWNDCLASSW *)&oldVal);
    Short = prop->N.Name.Short;
    v24 = 5;
    ++*(_DWORD *)(Short + 8);
    v10->limited_expression += 16;
    if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
      GASPagedStack<GASValue,32>::PushPage(this: v10);
    if ( v10->limited_expression != nullptr )
      GASValue::GASValue(this: (GASValue *)v10->limited_expression, v: (tagWNDCLASSW *)&v24);
    GASValue::~GASValue(this: (GASValue *)&v24, a2: v9);
    v11 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 28))(a1: this);
    v12 = (GRefCountNTSImpl *)v11;
    if ( v11 != 0 )
    {
      ++*(_DWORD *)(v11 + 4);
      v13 = v11 + 120;
    }
    else
    {
      v13 = (int)v28;
    }
    v14 = ((*(_DWORD *)(a2 + 8) - *(_DWORD *)(a2 + 12)) >> 4) + 32 * *(_DWORD *)(a2 + 28) - 32;
    v19[1] = &v27;
    v19[2] = v13;
    v19[3] = 0;
    v19[4] = 0;
    v15 = *(_DWORD *)(v9 + 4);
    v21 = a2;
    v16 = *(_DWORD *)v9;
    v23 = v14;
    v19[0] = &GASFnCall::`vftable';
    v20 = 0;
    v22 = 4;
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v16 + 40))(a1: v16, a2: v19, a3: v15, a4: 0);
    GASFnCall::~GASFnCall(this: v19);
    for ( i = 4; i != 0; --i )
    {
      GASValue::~GASValue(this: (GASValue *)v10->limited_expression, a2: i);
      v10->limited_expression -= 16;
      if ( *(_DWORD *)(a2 + 8) < *(_DWORD *)(a2 + 12) )
        GASPagedStack<GASValue,32>::PopPage(this: v10);
    }
    GASValue::operator=(this: a5, v: (tagWNDCLASSW *)&v27);
    if ( v12 != nullptr )
      GRefCountNTSImpl::Release(this: v12);
    GASValue::~GASValue(this: &v27, a2: 0);
    GASValue::~GASValue(this: &oldVal, a2: 0);
    return 1;
  }
  else
  {
    GASValue::~GASValue(this: &v27, a2: v9);
    GASValue::~GASValue(this: &oldVal, a2: v9);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091D00
// Name: protected: bool GASPrototypeBase::GetMemberRawConstructor(class GASObject __near *,class GASStringContext __near *,class GASString const __near &,class GASValue __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASPrototypeBase::GetMemberRawConstructor(
        GASPrototypeBase *this,
        struct GASObject *a2,
        _IMAGE_SYMBOL_EX *name,
        _IMAGE_SYMBOL_EX *key,
        GASValue *a5,
        bool isConstructor2)
{
  int v8; // eax
  tagIMECHARPOSITION *v9; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // eax
  char v11; // bl
  _LARGE_INTEGER m; // [esp+Ch] [ebp-38h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *lval; // [esp+1Ch] [ebp-28h] BYREF
  int v15; // [esp+2Ch] [ebp-18h] BYREF
  int v16; // [esp+30h] [ebp-14h]
  char v17; // [esp+34h] [ebp-10h]
  int v18; // [esp+38h] [ebp-Ch] BYREF
  int v19; // [esp+3Ch] [ebp-8h]
  char v20; // [esp+40h] [ebp-4h]
  char namea; // [esp+50h] [ebp+Ch]

  namea = name->N.ShortName[4] > 6u;
  LOWORD(m.LowPart) = 0;
  LOBYTE(lval) = 10;
  if ( (unsigned __int8)GASStringHashBase<GASMember,GHashUncachedLH_GC<GASString,GASMember,GASStringHashFunctor,323>>::GetCaseCheck(
                          key,
                          caseSensitive: (int)&m,
                          a3: namea) != 0 )
    GASValue::operator=(this: (int)&lval, v: (tagWNDCLASSW *)&m);
  if ( (_BYTE)lval != 10 )
  {
    GASValue::operator=(this: (int)a5, v: (tagWNDCLASSW *)&lval);
LABEL_33:
    GASValue::~GASValue(this: &lval, a2: (int)name);
    GASValue::~GASValue(this: (GASValue *)&m, a2: (int)name);
    return 1;
  }
  v20 = 0;
  v18 = 0;
  v19 = 0;
  if ( isConstructor2 )
  {
    GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)&v18, orig: (const struct GASFunctionRefBase *)(this + 4));
  }
  else
  {
    v8 = *((_DWORD *)this + 1);
    v17 = 0;
    v15 = v8;
    if ( v8 != 0 )
    {
      ++*(_DWORD *)(v8 + 8);
      *(_DWORD *)(v8 + 8) &= 0x8FFFFFFF;
    }
    v9 = *((tagIMECHARPOSITION **)this + 2);
    v16 = 0;
    if ( v9 != nullptr )
      GASFunctionRefBase::SetLocalFrame(a1: (int)&v15, a2: (int)name, result: v9, internal: *(_BYTE *)(this + 3) & 1);
    GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)&v18, orig: (const struct GASFunctionRefBase *)&v15);
    if ( (v17 & 2) == 0 && v15 != 0 )
      GRefCountBaseGC<323>::Release(a1: v15, a2: (int)name);
    v15 = 0;
    if ( (v17 & 1) == 0 && v16 != 0 )
      GRefCountBaseGC<323>::Release(a1: v16, a2: (int)name);
  }
  if ( v18 != 0 )
  {
    GASValue::SetAsFunction(this: a5, func: (const struct GASFunctionRefBase *)&v18);
LABEL_27:
    if ( (v20 & 2) == 0 && v18 != 0 )
      GRefCountBaseGC<323>::Release(a1: v18, a2: (int)name);
    v18 = 0;
    if ( (v20 & 1) == 0 && v19 != 0 )
      GRefCountBaseGC<323>::Release(a1: v19, a2: (int)name);
    goto LABEL_33;
  }
  GASValue::DropRefs(this: a5, a2: (int)name);
  *(_BYTE *)a5 = 0;
  pNode = a2[3].pNode;
  if ( pNode == nullptr )
    goto LABEL_27;
  v11 = ((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, _IMAGE_SYMBOL_EX *, _IMAGE_SYMBOL_EX *, GASValue *))pNode[2].pNext[5].elem)(
          a1: &pNode[2],
          a2: name,
          a3: key,
          a4: a5);
  if ( (v20 & 2) == 0 && v18 != 0 )
    GRefCountBaseGC<323>::Release(a1: v18, a2: (int)name);
  v18 = 0;
  if ( (v20 & 1) == 0 && v19 != 0 )
    GRefCountBaseGC<323>::Release(a1: v19, a2: (int)name);
  v19 = 0;
  GASValue::~GASValue(this: &lval, a2: (int)name);
  GASValue::~GASValue(this: (GASValue *)&m, a2: (int)name);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x100920C0
// Name: public: virtual bool GASObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::SetMember(
        CTSQueue<CFunctor *,0,1> *this,
        GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *name,
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **pval,
        char *pmember)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ebx
  CFunctor **p_elem; // esi
  int Index; // eax
  CFunctor ***v9; // ecx
  int *Short; // ecx
  bool v11; // zf
  int v12; // eax
  CFunctor **v13; // eax
  CFunctor **v14; // esi
  CFunctor *v15; // eax
  tagWNDCLASSW *v16; // ebx
  char v17; // al
  int v18; // eax
  GRefCountNTSImpl *v19; // esi
  tagWNDCLASSW *v20; // eax
  char v21; // cl
  int *v22; // ecx
  GASValue *v23; // esi
  _DWORD *v24; // eax
  int v25; // edi
  GASEnvironment *v26; // ebx
  const struct GASFunctionRefBase *v27; // eax
  int v28; // ecx
  int v29; // ecx
  struct GASObject *v30; // eax
  const struct GASFunctionRefBase *v31; // eax
  bool v32; // [esp-4h] [ebp-6Ch]
  int v33; // [esp-4h] [ebp-6Ch]
  int v34; // [esp-4h] [ebp-6Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *propVal; // [esp+Ch] [ebp-5Ch] BYREF
  GASValue newVal[4]; // [esp+1Ch] [ebp-4Ch] BYREF
  int v37[2]; // [esp+2Ch] [ebp-3Ch] BYREF
  char v38; // [esp+34h] [ebp-34h]
  int v39[2]; // [esp+38h] [ebp-30h] BYREF
  char v40; // [esp+40h] [ebp-28h]
  _DWORD v41[2]; // [esp+44h] [ebp-24h] BYREF
  CFunctor **v42; // [esp+4Ch] [ebp-1Ch] BYREF
  int v43; // [esp+50h] [ebp-18h]
  CFunctor **v44; // [esp+54h] [ebp-14h] BYREF
  CFunctor **v45; // [esp+58h] [ebp-10h]
  _IMAGE_SYMBOL_EX *v46; // [esp+5Ch] [ebp-Ch] BYREF
  int *v47; // [esp+60h] [ebp-8h]
  char v48; // [esp+64h] [ebp-4h]
  char v49; // [esp+65h] [ebp-3h]
  char v50; // [esp+66h] [ebp-2h]
  char v51; // [esp+67h] [ebp-1h] BYREF
  int pmembera; // [esp+7Ch] [ebp+14h]

  v47 = (int *)this;
  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    LOBYTE(notsetVal_0[0]) = 10;
    atexit(func: GASObject::SetMember_::_2_::_dynamic_atexit_destructor_for__notsetVal__);
  }
  v32 = *((_BYTE *)a2 + 124) > 6u;
  v51 = 0;
  GASStringHashBase<GASValue,GHashUncachedLH_GC<GASString,GASValue,GASStringHashFunctor,323>>::FindCaseCheck(
    this: (char *)&this->m_Tail.value64 + 4,
    a2: &v44,
    key: name,
    caseSensitive: v32);
  if ( v44 == nullptr || *v44 == nullptr || (int)v45 > (signed int)(*v44)->m_nUserID )
  {
    pNode = this->m_Tail.value.pNode;
    if ( pNode != nullptr )
    {
      while ( 1 )
      {
        if ( LOBYTE(pNode[6].pNext) != 0 )
        {
          p_elem = &pNode[3].elem;
          if ( *((_BYTE *)a2 + 124) <= 6u )
          {
            Short = (int *)name->N.Name.Short;
            v11 = *(_DWORD *)(name->N.Name.Short + 4) == 0;
            v46 = name;
            if ( v11 )
              GASStringNode::ResolveLowercase_Impl(a1: Short);
            if ( *p_elem != nullptr
              && (v34 = (*p_elem)->m_nUserID & *(_DWORD *)(name->N.Name.Short + 12),
                  v49 = 0,
                  v48 = 0,
                  (v12 = GHashSetBase<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASValue,GASStringHashFunctor>,GHashNode<GASString,GASValue,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString::NoCaseKey>(
                           this: (int *)&pNode[3].elem,
                           a2: (int *)&v46,
                           a3: v34)) >= 0) )
            {
              v41[0] = (char *)pNode + 28;
            }
            else
            {
              v12 = 0;
              v41[0] = 0;
            }
            v41[1] = v12;
            v9 = (CFunctor ***)v41;
          }
          else if ( *p_elem != nullptr
                 && (v33 = (*p_elem)->m_nUserID & *(_DWORD *)(name->N.Name.Short + 12),
                     v50 = 0,
                     (Index = GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
                                this: (int *)&pNode[3].elem,
                                a2: name,
                                a3: v33)) >= 0) )
          {
            v42 = &pNode[3].elem;
            v43 = Index;
            v9 = &v42;
          }
          else
          {
            v42 = nullptr;
            v43 = 0;
            v9 = &v42;
          }
          v13 = *v9;
          v14 = v9[1];
          if ( *v9 != nullptr && *v13 != nullptr && (int)v14 <= (signed int)(*v13)->m_nUserID )
            break;
        }
        pNode = pNode[3].pNext;
        if ( pNode == nullptr )
          goto LABEL_27;
      }
      if ( LOBYTE((*v13)[3 * (int)v14 + 2].__vftable) == 9 )
      {
        v44 = *v9;
        v45 = v14;
      }
    }
  }
LABEL_27:
  if ( v44 == nullptr || *v44 == nullptr || (v15 = *v44, (int)v45 > (signed int)(*v44)->m_nUserID) )
  {
    v21 = *pmember;
    pmembera = 0;
    v16 = nullptr;
    v51 = v21;
    goto LABEL_40;
  }
  v16 = (tagWNDCLASSW *)&v15[3 * (int)v45 + 2];
  v17 = BYTE1(v15[3 * (int)v45 + 2].__vftable);
  v51 = v17;
  pmembera = (int)v16;
  if ( LOBYTE(v16->style) != 9 )
  {
    if ( (v17 & 4) != 0 )
      return;
LABEL_40:
    v22 = v47;
    v11 = v47[7] == 0;
    v23 = pval;
    LOBYTE(newVal[0]) = 0;
    if ( !v11 )
    {
      if ( GASObject::InvokeWatchpoint(
             this: (char *)v47 - 16,
             (int)a2,
             prop: name,
             newVal: (tagWNDCLASSW *)pval,
             a5: (int)newVal) != 0 )
        pval = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)newVal;
      v22 = v47;
    }
    if ( v16 == nullptr )
    {
      (*(void (__thiscall **)(int *, GASEnvironment *, _IMAGE_SYMBOL_EX *, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **, char *))(*v22 + 40))(
        a1: v22,
        a2: a2 + 30,
        a3: name,
        a4: pval,
        a5: &v51);
      GASValue::~GASValue(this: newVal, a2: (int)name);
      return;
    }
    if ( *(_BYTE *)v23 == 9 )
      *((_BYTE *)v22 + 32) = 1;
    if ( *((_BYTE *)a2 + 124) <= 6u )
    {
      if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
        GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
      v24 = *((_DWORD **)a2 + 30);
      v25 = name->N.Name.Short;
      v29 = *(_DWORD *)(name->N.Name.Short + 4);
      v26 = a2 + 30;
      if ( *(_DWORD *)(v24[80] + 4) != v29 )
      {
        if ( *(_DWORD *)(v24[84] + 4) == v29 )
        {
          if ( *(_BYTE *)v23 == 10 )
            goto LABEL_72;
          v31 = (const struct GASFunctionRefBase *)GASValue::ToFunction(
                                                     a1: (int)v23,
                                                     a2: v25,
                                                     a3: (int)v37,
                                                     a4: (int)a2);
          GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(v47 + 4), orig: v31);
          if ( (v38 & 2) == 0 && v37[0] != 0 )
            GRefCountBaseGC<323>::Release(a1: v37[0], a2: v25);
          v37[0] = 0;
          if ( (v38 & 1) != 0 )
            goto LABEL_72;
          v28 = v37[1];
          goto LABEL_70;
        }
LABEL_73:
        if ( v25 == v24[104] )
          GASEnvironment::InvalidateOptAdvanceList(this: a2);
        goto LABEL_75;
      }
    }
    else
    {
      v24 = *((_DWORD **)a2 + 30);
      v25 = name->N.Name.Short;
      v26 = a2 + 30;
      if ( name->N.Name.Short != v24[80] )
      {
        if ( v25 == v24[84] )
        {
          if ( *(_BYTE *)v23 != 10 )
          {
            v27 = (const struct GASFunctionRefBase *)GASValue::ToFunction(
                                                       a1: (int)v23,
                                                       a2: v25,
                                                       a3: (int)v39,
                                                       a4: (int)a2);
            GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(v47 + 4), orig: v27);
            if ( (v40 & 2) == 0 && v39[0] != 0 )
              GRefCountBaseGC<323>::Release(a1: v39[0], a2: v25);
            v39[0] = 0;
            if ( (v40 & 1) != 0 )
              goto LABEL_72;
            v28 = v39[1];
LABEL_70:
            if ( v28 != 0 )
              GRefCountBaseGC<323>::Release(a1: v28, a2: v25);
          }
LABEL_72:
          pval = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)notsetVal_0;
LABEL_75:
          GASValue::operator=(this: pmembera, v: (tagWNDCLASSW *)pval);
          GASValue::~GASValue(this: newVal, a2: v25);
          return;
        }
        goto LABEL_73;
      }
    }
    if ( *(_BYTE *)v23 != 10 )
    {
      v25 = *v47;
      v30 = GASValue::ToObject(this: v23, a2: *v47, a3: (const struct GASEnvironment *)a2);
      (*(void (__thiscall **)(int *, GASEnvironment *, struct GASObject *))(v25 + 52))(a1: v47, a2: v26, a3: v30);
      GASEnvironment::InvalidateOptAdvanceList(this: a2);
    }
    pval = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)notsetVal_0;
    goto LABEL_75;
  }
  GASValue::GASValue(this: &propVal, v: v16);
  v18 = (*(int (__thiscall **)(int *))(*(v47 - 4) + 28))(a1: v47 - 4);
  v19 = (GRefCountNTSImpl *)v18;
  if ( v18 != 0 )
  {
    ++*(_DWORD *)(v18 + 4);
    v20 = (tagWNDCLASSW *)(v18 + 120);
  }
  else
  {
    v20 = v47 != (int *)16 ? (tagWNDCLASSW *)v47 : nullptr;
  }
  GASValue::SetPropertyValue(
    this: &propVal,
    (int)a2,
    a3: (__vc_attributes::iid_isAttribute *)a2,
    val: v20,
    a5: (tagWNDCLASSW *)pval);
  if ( v19 != nullptr )
    GRefCountNTSImpl::Release(this: v19);
  GASValue::~GASValue(this: &propVal, a2: (int)name);
}

//------------------------------------------------------------------------------
// Address: 0x10092490
// Name: public: virtual bool GASObject::SetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::SetMemberRaw(
        GASObject *this,
        struct GASStringContext *a2,
        _EXIT_THREAD_DEBUG_INFO *a3,
        GASValue *a4,
        const struct GASPropFlags *a5)
{
  GASValue *v5; // edx
  bool v7; // zf
  struct GASStringContext *v8; // ebx
  const struct GASString *v9; // edi
  struct GASObject *v10; // eax
  int v11; // eax
  int *v12; // ecx
  int v13; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v14; // edi
  struct GASObject *v15; // eax
  const struct GASFunctionRefBase *v16; // eax
  int v17; // eax
  ISteamMatchmakingServerListResponse *v18; // edi
  int Index; // eax
  char *v20; // ecx
  int v21; // ebx
  int *v22; // edx
  int v23; // eax
  int v24; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // edi
  struct GASObject *v26; // eax
  int v27; // edi
  const struct GASFunctionRefBase *v28; // eax
  _JOBOBJECT_END_OF_JOB_TIME_INFORMATION v29; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *Instance; // eax
  char v31; // al
  int v32; // ecx
  int v33; // esi
  int v34; // eax
  char v36; // bl
  GASValue v37; // [esp+Ch] [ebp-24h] BYREF
  int v38; // [esp+10h] [ebp-20h] BYREF
  int v39; // [esp+14h] [ebp-1Ch]
  char v40; // [esp+18h] [ebp-18h]
  int *v41; // [esp+1Ch] [ebp-14h] BYREF
  int v42[2]; // [esp+24h] [ebp-Ch] BYREF
  tagWNDCLASSW *v; // [esp+2Ch] [ebp-4h]

  v5 = a4;
  v7 = *((_BYTE *)this + 33) == 0;
  v = (tagWNDCLASSW *)a4;
  if ( v7 && *(_BYTE *)a4 == 6 )
  {
    v8 = a2;
    v9 = (const struct GASString *)a3;
    if ( a3->dwExitCode == *(_DWORD *)(*(_DWORD *)a2 + 332) )
    {
      v10 = GASValue::ToObject(this: a4, a2: (int)a3, a3: nullptr);
      if ( v10 != nullptr )
      {
        v11 = ((int (__thiscall *)(struct GASObject *))v10[2].pNode[1].pNext)(a1: &v10[2]);
        v5 = a4;
        if ( v11 == 7 )
          *((_BYTE *)this + 33) = 1;
      }
      else
      {
        v5 = a4;
      }
    }
  }
  else
  {
    v8 = a2;
    v9 = (const struct GASString *)a3;
  }
  v12 = *(int **)v9;
  if ( *((_BYTE *)v8 + 4) <= 6u )
  {
    if ( v12[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v12);
    v22 = *(int **)v9;
    v23 = *(_DWORD *)v8;
    v24 = *(_DWORD *)(*(_DWORD *)v9 + 4);
    if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v8 + 320) + 4) == v24 )
    {
      if ( *(_BYTE *)a4 != 10 )
      {
        pNode = this->pNode;
        v26 = GASValue::ToObject(this: a4, a2: (int)this->pNode, a3: nullptr);
        ((void (__thiscall *)(GASObject *, struct GASStringContext *, struct GASObject *))pNode[6].elem)(
          a1: this,
          a2: v8,
          a3: v26);
        GASStringContext::InvalidateOptAdvanceList(this: v8);
      }
      v = (tagWNDCLASSW *)&notsetVal;
    }
    else
    {
      v27 = *(_DWORD *)(v23 + 336);
      if ( *(_DWORD *)(v27 + 4) == v24 )
      {
        if ( *(_BYTE *)a4 != 10 )
        {
          v28 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: (int)a4, a2: v27, a3: (int)&v38, a4: 0);
          GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(this + 2), orig: v28);
          if ( (v40 & 2) == 0 && v38 != 0 )
            GRefCountBaseGC<323>::Release(a1: v38, a2: v27);
          v38 = 0;
          if ( (v40 & 1) == 0 && v39 != 0 )
            GRefCountBaseGC<323>::Release(a1: v39, a2: v27);
        }
        v = (tagWNDCLASSW *)&notsetVal;
      }
      else if ( v22 == *(int **)(v23 + 416) )
      {
        GASStringContext::InvalidateOptAdvanceList(this: v8);
      }
    }
    v18 = (ISteamMatchmakingServerListResponse *)this + 3;
    v29.EndOfJobTimeAction = GASStringHashBase<GASMember,GHashUncachedLH_GC<GASString,GASMember,GASStringHashFunctor,323>>::FindCaseInsensitive(
                               this: (int *)this + 3,
                               a2: &v41,
                               ikey: a3).EndOfJobTimeAction;
    v21 = *(_DWORD *)(v29.EndOfJobTimeAction + 4);
    v42[0] = *(_DWORD *)v29.EndOfJobTimeAction;
  }
  else
  {
    v13 = *(_DWORD *)v8;
    if ( v12 == *(int **)(*(_DWORD *)v8 + 320) )
    {
      if ( *(_BYTE *)v5 != 10 )
      {
        v14 = this->pNode;
        v15 = GASValue::ToObject(this: a4, a2: (int)this->pNode, a3: nullptr);
        ((void (__thiscall *)(GASObject *, struct GASStringContext *, struct GASObject *))v14[6].elem)(
          a1: this,
          a2: v8,
          a3: v15);
        GASStringContext::InvalidateOptAdvanceList(this: v8);
      }
      v = (tagWNDCLASSW *)&notsetVal;
    }
    else if ( v12 == *(int **)(v13 + 336) )
    {
      if ( *(_BYTE *)v5 != 10 )
      {
        v16 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: (int)v5, a2: (int)v9, a3: (int)&v38, a4: 0);
        GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(this + 2), orig: v16);
        if ( (v40 & 2) == 0 && v38 != 0 )
          GRefCountBaseGC<323>::Release(a1: v38, a2: (int)v9);
        v38 = 0;
        if ( (v40 & 1) == 0 && v39 != 0 )
          GRefCountBaseGC<323>::Release(a1: v39, a2: (int)v9);
      }
      v = (tagWNDCLASSW *)&notsetVal;
    }
    else if ( v12 == *(int **)(v13 + 416) )
    {
      GASStringContext::InvalidateOptAdvanceList(this: v8);
    }
    v17 = *((_DWORD *)this + 3);
    v18 = (ISteamMatchmakingServerListResponse *)this + 3;
    if ( v17 != 0
      && (Index = GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
                    this: (int *)this + 3,
                    a2: a3,
                    a3: *(_DWORD *)(v17 + 4) & *(_DWORD *)(a3->dwExitCode + 12))) >= 0 )
    {
      v20 = (char *)this + 12;
      v42[0] = (int)this + 12;
      v21 = Index;
    }
    else
    {
      v20 = nullptr;
      v42[0] = 0;
      v21 = 0;
    }
  }
  if ( *(_BYTE *)a4 == 9 )
    *((_BYTE *)this + 32) = 1;
  Instance = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxAmpServer::GetInstance(this: v20);
  GFxAmpServer::IsState(
    this: Instance,
    state: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float,float),float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)2);
  if ( v31 == 0 && *(_DWORD *)(a3->dwExitCode + 16) != 0 )
  {
    GASValue::ToFunction(a1: (int)v, a2: (int)v18, a3: (int)&v38, a4: 0);
    v32 = v38;
    if ( v38 != 0 )
    {
      v33 = v38;
      if ( (*(unsigned __int8 (**)(void))(*(_DWORD *)v38 + 56))() != 0 )
        GFxAmpViewStats::RegisterScriptFunction(
          this: *(GFxAmpViewStats **)(*(_DWORD *)(*(_DWORD *)a2 + 652) + 10308),
          swdHandle: *(IShaderAPI **)(*(_DWORD *)(*(_DWORD *)(v33 + 60) + 8) + 16),
          swfOffset: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v33 + 60) + 8) + 20) + *(_DWORD *)(v33 + 76),
          a4: *(char **)a3->dwExitCode,
          byteCodeLength: *(IShaderAPI_vtbl **)(v33 + 80));
      v32 = v38;
    }
    if ( (v40 & 2) == 0 && v32 != 0 )
      GRefCountBaseGC<323>::Release(a1: v32, a2: (int)v18);
    v38 = 0;
    if ( (v40 & 1) == 0 && v39 != 0 )
      GRefCountBaseGC<323>::Release(a1: v39, a2: (int)v18);
  }
  if ( v42[0] != 0 && (v34 = *(_DWORD *)v42[0], *(_DWORD *)v42[0] != 0) && v21 <= *(_DWORD *)(v34 + 4) )
  {
    GASValue::operator=(this: v34 + 24 * v21 + 16, v);
    return 1;
  }
  else
  {
    v36 = *(_BYTE *)a5;
    GASValue::GASValue(this: &v37, v);
    BYTE1(v37) = v36;
    v42[0] = (int)a3;
    v42[1] = (int)&v37;
    GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::Set<GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeRef>(
      this: v18,
      result: v18,
      a3: (int **)v42);
    GASValue::~GASValue(this: &v37, a2: (int)v18);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100927C0
// Name: public: virtual bool GASObject::SetMemberFlags(class GASStringContext __near *,class GASString const __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::SetMemberFlags(
        ISteamMatchmakingServerListResponse *this,
        _IMAGE_SYMBOL_EX *name,
        int a3,
        char flags)
{
  void (__thiscall *RefreshComplete)(ISteamMatchmakingServerListResponse *, void *, EMatchMakingServerResponse); // eax
  _LARGE_INTEGER member; // [esp+8h] [ebp-18h] BYREF
  int v8[2]; // [esp+18h] [ebp-8h] BYREF

  RefreshComplete = this->__vftable[1].RefreshComplete;
  LOWORD(member.LowPart) = 0;
  if ( ((unsigned __int8 (__thiscall *)(ISteamMatchmakingServerListResponse *, _IMAGE_SYMBOL_EX *, int, _LARGE_INTEGER *))RefreshComplete)(
         a1: this,
         a2: name,
         a3,
         a4: &member) != 0 )
  {
    BYTE1(member.LowPart) = flags;
    v8[0] = a3;
    v8[1] = (int)&member;
    GHashSetBase<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASMember,GASStringHashFunctor>,GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeHashF>>::Set<GHashNode<GASString,GASMember,GASStringHashFunctor>::NodeRef>(
      this: this + 3,
      result: this + 3,
      a3: (int **)v8);
    GASValue::~GASValue(this: (GASValue *)&member, a2: a3);
    return 1;
  }
  else
  {
    GASValue::~GASValue(this: (GASValue *)&member, a2: a3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092980
// Name: public: GASPrototypeBase::InterfacesArray::InterfacesArray(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototypeBase::InterfacesArray::InterfacesArray(IMDLCache *this, unsigned int size)
{
  unsigned int v3; // ebx
  int v4; // edi
  bool (__thiscall **v5)(IAppSystem *, void *(__cdecl *)(const char *, int *)); // eax

  *((_DWORD *)this + 1) = 0;
  this->__vftable = nullptr;
  *((_DWORD *)this + 2) = 0;
  v3 = *((_DWORD *)this + 1);
  GArrayDataBase<GPtr<GASObject>,GAllocatorLH<GPtr<GASObject>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    (GRenderer::CachedData *)this,
    pheapAddr: (ButtonCode_t)this,
    newSize: size);
  if ( size > v3 )
  {
    v4 = size - v3;
    v5 = &this->Connect + v3;
    if ( size != v3 )
    {
      do
      {
        if ( v5 != nullptr )
          *v5 = nullptr;
        ++v5;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100929D0
// Name: public: virtual bool GASObject::Unwatch(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::Unwatch(GASObject *this, _IMAGE_SYMBOL_EX *prop, const struct GASString *a3)
{
  int *v4; // ecx
  _IMAGE_SYMBOL_EX *v5; // edi
  const struct GASString *v6; // esi
  _IMAGE_SYMBOL_EX *v7; // eax
  int *v8; // ecx
  bool v9; // zf
  _DWORD *v10; // esi
  _IMAGE_SYMBOL_EX *propa; // [esp+14h] [ebp+8h]

  v4 = *((int **)this + 7);
  if ( v4 == nullptr )
    return 0;
  v5 = prop;
  v6 = a3;
  LOBYTE(prop) = prop->N.ShortName[4] > 6u;
  if ( GASStringHashBase<GASObject::Watchpoint,GHashUncachedLH_GC<GASString,GASObject::Watchpoint,GASStringHashFunctor,323>>::GetCaseCheck(
         this: v4,
         a2: (int)a3,
         a3: (int)prop) == 0 )
    return 0;
  v7 = *((_IMAGE_SYMBOL_EX **)this + 7);
  propa = v7;
  if ( v5->N.ShortName[4] <= 6u )
  {
    v8 = *(int **)v6;
    v9 = *(_DWORD *)(*(_DWORD *)v6 + 4) == 0;
    a3 = v6;
    if ( v9 )
    {
      GASStringNode::ResolveLowercase_Impl(a1: v8);
      v7 = propa;
    }
    GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::RemoveAlt<GASString::NoCaseKey>(
      this: v7,
      a2: (int *)&a3);
  }
  else
  {
    GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::RemoveAlt<GASString>(
      this: v7,
      a2: (int *)v6);
  }
  v10 = *((_DWORD **)this + 7);
  if ( *v10 == 0 || *(_DWORD *)*v10 == 0 )
  {
    if ( v10 != nullptr )
    {
      GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>,GHashNode<GASString,GASObject::Watchpoint,GASStringHashFunctor>::NodeHashF>>(this: *((int **)this + 7));
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    }
    *((_DWORD *)this + 7) = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092A80
// Name: public: virtual GASPrototypeBase::~GASPrototypeBase(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASPrototypeBase::~GASPrototypeBase(GASPrototypeBase *this@<ecx>, int a2@<edi>)
{
  int v3; // ebx
  int v4; // eax
  int *v5; // edi
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+8h] [ebp-4h]

  v3 = *((_DWORD *)this + 7);
  this->__vftable = (IUnknown_vtbl *)&GASPrototypeBase::`vftable';
  if ( v3 != 0 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    v11 = a2;
    v5 = (int *)(*(_DWORD *)v3 + 4 * v4 - 4);
    if ( v4 != 0 )
    {
      v12 = *(_DWORD *)(v3 + 4);
      do
      {
        if ( *v5 != 0 )
          GRefCountBaseGC<323>::Release(a1: *v5, a2: (int)v5);
        --v5;
        --v12;
      }
      while ( v12 != 0 );
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
    a2 = v11;
  }
  if ( (*(_BYTE *)(this + 6) & 2) == 0 )
  {
    v6 = *((_DWORD *)this + 4);
    if ( v6 != 0 )
      GRefCountBaseGC<323>::Release(a1: v6, a2);
  }
  v7 = (*(_BYTE *)(this + 6) & 1) == 0;
  *((_DWORD *)this + 4) = 0;
  if ( v7 )
  {
    v8 = *((_DWORD *)this + 5);
    if ( v8 != 0 )
      GRefCountBaseGC<323>::Release(a1: v8, a2);
  }
  *((_DWORD *)this + 5) = 0;
  if ( (*(_BYTE *)(this + 3) & 2) == 0 )
  {
    v9 = *((_DWORD *)this + 1);
    if ( v9 != 0 )
      GRefCountBaseGC<323>::Release(a1: v9, a2);
  }
  v7 = (*(_BYTE *)(this + 3) & 1) == 0;
  *((_DWORD *)this + 1) = 0;
  if ( v7 && (v10 = *((_DWORD *)this + 2)) != 0 )
  {
    GRefCountBaseGC<323>::Release(a1: v10, a2);
    *((_DWORD *)this + 2) = 0;
  }
  else
  {
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092B50
// Name: protected: void GASPrototypeBase::AddInterface(class GASStringContext __near *,int,class GASFunctionObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPrototypeBase::AddInterface(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *this,
        int psc,
        unsigned int a3,
        int a4)
{
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *v4; // edi
  float v5; // ecx
  int (__thiscall *v6)(_DWORD, int, int *); // edx
  IMDLCache *v7; // eax
  int v8; // eax
  unsigned __int8 (__thiscall *v9)(int, int, char *, GASValue *); // edx
  struct GASObject *v10; // eax
  int v11; // esi
  char *v12; // [esp-10h] [ebp-24h]
  GASValue prototypeVal[4]; // [esp+4h] [ebp-10h] BYREF

  v4 = this;
  if ( *((_DWORD *)this + 7) != 0 || a4 != 0 )
  {
    v12 = (char *)(*(_DWORD *)psc + 316);
    v9 = *(unsigned __int8 (__thiscall **)(int, int, char *, GASValue *))(*(_DWORD *)(a4 + 16) + 44);
    LOBYTE(prototypeVal[0]) = 0;
    if ( v9(a1: a4 + 16, a2: psc, a3: v12, a4: prototypeVal) != 0 )
    {
      v10 = GASValue::ToObject(this: prototypeVal, a2: (int)v4, a3: nullptr);
      v11 = (int)v10;
      if ( v10 != nullptr )
        v10[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v10[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v4 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(*(_DWORD *)DWORD1(v4[1].m_pfnProxied) + 4 * a3);
      if ( v10 != nullptr )
        v10[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v10[1].pNode->pNext + 1) & 0x8FFFFFFF);
      if ( LODWORD(v4->m_pfnProxied) != 0 )
        GRefCountBaseGC<323>::Release(a1: v4->m_pfnProxied, a2: (int)v4);
      LODWORD(v4->m_pfnProxied) = v11;
      if ( v11 != 0 )
        GRefCountBaseGC<323>::Release(a1: v11, a2: (int)v4);
    }
    GASValue::~GASValue(this: prototypeVal, a2: (int)v4);
  }
  else
  {
    v5 = *(float *)(*(_DWORD *)psc + 656);
    v6 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(v5) + 40);
    psc = 2;
    v7 = (IMDLCache *)v6(a1: LODWORD(v5), a2: 12, a3: &psc);
    if ( v7 != nullptr )
    {
      GASPrototypeBase::InterfacesArray::InterfacesArray(this: v7, size: a3);
      DWORD1(v4[1].m_pfnProxied) = v8;
    }
    else
    {
      DWORD1(v4[1].m_pfnProxied) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092C30
// Name: public: bool GASString::CompareBuiltIn_CaseCheck(class GASString const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASString::CompareBuiltIn_CaseCheck(GASString *this, _IMAGE_SYMBOL_EX *str, bool caseSensitive)
{
  if ( caseSensitive )
    return *(_DWORD *)this == str->N.Name.Short;
  if ( *(_DWORD *)(str->N.Name.Short + 4) == 0 )
    GASStringNode::ResolveLowercase_Impl(a1: (int *)str->N.Name.Short);
  return *(_DWORD *)(*(_DWORD *)this + 4) == *(_DWORD *)(str->N.Name.Short + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10092CB0
// Name: public: GASObjectProto::GASObjectProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASObjectProto *__thiscall GASObjectProto::GASObjectProto(GASObjectProto *this, __int64 psc, const struct GASFunctionRef *psc_8)
{
  const struct GASFunctionRef *v4; // ecx
  __int128 v6; // [esp-8h] [ebp-14h]

  GASObject::GASObject(
    (GASObject *)this,
    (GASGlobalContext **)psc,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)HIDWORD(psc));
  v4 = psc_8;
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v6 = __PAIR64__((unsigned int)v4, psc);
  *(_DWORD *)this = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 52),
    a2: (int)this,
    pthis: (CMaterialVar *)this,
    psc: v6);
  *(_DWORD *)this = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASMouseProto::`vftable';
  HIBYTE(psc) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 13,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)&GAS_ObjectFunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc + 7));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092D40
// Name: public: GASObjectProto::GASObjectProto(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
GPtr<GImage> *__thiscall GASObjectProto::GASObjectProto(
        GPtr<GImage> *this,
        GASGlobalContext **psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4)
{
  GASObject::GASObject((GASObject *)this, psc, psc_4);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  this->pObject = (GImage *)&GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASMouseProto::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092D90
// Name: public: GASObjectProto::GASObjectProto(class GASStringContext __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GPtr<GImage> *__userpurge GASObjectProto::GASObjectProto@<eax>(
        GPtr<GImage> *this@<ecx>,
        _TIME_DYNAMIC_ZONE_INFORMATION psc)
{
  vc_attributes::PreRangeAttribute **Bias; // ebx
  __int128 v5; // [esp-8h] [ebp-14h]

  Bias = (vc_attributes::PreRangeAttribute **)psc.Bias;
  GASObject::GASObject((GASObject *)this, a2: (int)this, psc: (GASGlobalContext **)psc.Bias);
  *((_DWORD *)this + 13) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 20) = 0;
  *(_QWORD *)&v5 = __PAIR64__(*(unsigned int *)psc.StandardName, (unsigned int)Bias);
  this->pObject = (GImage *)&GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)(this + 13),
    a2: (int)this,
    pthis: (CMaterialVar *)this,
    psc: v5);
  this->pObject = (GImage *)&GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASMouseProto::`vftable';
  HIBYTE(psc.Bias) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 13,
    a2: (int)this,
    flags: Bias,
    flags_4: (const struct GASNameFunction *)&GAS_ObjectFunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc.Bias + 3));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092EA0
// Name: public: virtual bool GASObject::Watch(class GASStringContext __near *,class GASString const __near &,class GASFunctionRef const __near &,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObject::Watch(
        CTSQueue<CFunctor *,0,1> *this,
        _IMAGE_SYMBOL_EX *prop,
        int a3,
        struct GASFunctionRefBase *a4,
        tagWNDCLASSW *userData)
{
  int v6; // ecx
  int (__thiscall *v7)(int, int, struct GASFunctionRefBase **); // eax
  _DWORD *v8; // eax
  CBaseIntHandle<unsigned short> *wp; // [esp+Ch] [ebp-1Ch] BYREF
  int v11; // [esp+10h] [ebp-18h]
  char v12; // [esp+14h] [ebp-14h]
  GASValue v13[4]; // [esp+18h] [ebp-10h] BYREF

  v12 = 0;
  wp = nullptr;
  v11 = 0;
  LOBYTE(v13[0]) = 0;
  GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)&wp, orig: a4);
  GASValue::operator=(this: (int)v13, v: userData);
  if ( this->m_FreeNodes.m_Head.value32.DepthAndSequence == 0 )
  {
    v6 = *(_DWORD *)(prop->N.Name.Short + 656);
    v7 = *(int (__thiscall **)(int, int, struct GASFunctionRefBase **))(*(_DWORD *)v6 + 40);
    a4 = (struct GASFunctionRefBase *)323;
    v8 = (_DWORD *)v7(a1: v6, a2: 4, a3: &a4);
    if ( v8 != nullptr )
      *v8 = 0;
    else
      v8 = nullptr;
    this->m_FreeNodes.m_Head.value32.DepthAndSequence = (int)v8;
  }
  GASStringHashBase<GASObject::Watchpoint,GHashUncachedLH_GC<GASString,GASObject::Watchpoint,GASStringHashFunctor,323>>::SetCaseCheck(
    this: (void *)this->m_FreeNodes.m_Head.value32.DepthAndSequence,
    a2: a3,
    a3: (struct GASFunctionRefBase *)&wp,
    a4: prop->N.ShortName[4] > 6u);
  GASValue::~GASValue(this: v13, a2: (int)prop);
  if ( (v12 & 2) == 0 && wp != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)wp, a2: (int)prop);
  wp = nullptr;
  if ( (v12 & 1) == 0 && v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2: (int)prop);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AB8C0
// Name: public: virtual class GASObject __near * GASObjectCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASObjectCtorFunction::CreateNewObject(GASObjectCtorFunction *this, int a2)
{
  struct GASEnvironment *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GASObject *v5; // eax

  v2 = (struct GASEnvironment *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASObject *)v4(a1: v3, a2: 52, a3: &a2);
  if ( v5 != nullptr )
    return GASObject::GASObject(this: v5, a2: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010B9A0
// Name: public: virtual bool GASObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
D3DXQUATERNION *__thiscall GASObject::GetMember(
        D3DXQUATERNION *this,
        ID3DXFont *result,
        _IMAGE_SYMBOL_EX *penv,
        int *val)
{
  return (*(D3DXQUATERNION *(__thiscall **)(D3DXQUATERNION *, ID3DXFont *, _IMAGE_SYMBOL_EX *, int *))(LODWORD(this->x) + 44))(
           a1: this,
           a2: result + 30,
           a3: penv,
           a4: val);
}
