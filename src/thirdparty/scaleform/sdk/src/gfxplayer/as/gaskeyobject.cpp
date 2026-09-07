// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gaskeyobject.cpp
// Functions: 12
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gaskeyobject.h"

//------------------------------------------------------------------------------
// Address: 0x10134940
// Name: protected: virtual void GASKeyCtorFunction::Update(int,unsigned char,unsigned long,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASKeyCtorFunction::Update(
        GASKeyCtorFunction *this,
        int a2,
        char a3,
        unsigned int a4,
        unsigned __int8 a5)
{
  char *v5; // eax

  v5 = (char *)this + 12 * a5;
  *((_DWORD *)v5 + 1) = a2;
  v5[8] = a3;
  *((_DWORD *)v5 + 3) = a4;
}

//------------------------------------------------------------------------------
// Address: 0x10134970
// Name: public: static void GASKeyCtorFunction::KeyGetAscii(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASKeyCtorFunction::KeyGetAscii(long double a1@<st0>, GASFnCall *result)
{
  GFxAmpStatusChangedCallback *v2; // eax
  int v3; // edi
  int v4; // eax
  GASValue *v5; // eax
  GFxAmpStatusChangedCallback *v6; // esi
  int v7; // edi
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-Ch]

  v2 = (GFxAmpStatusChangedCallback *)result[2];
  if ( v2 != nullptr )
    v3 = (int)v2 - 16;
  else
    v3 = 0;
  v4 = 0;
  if ( *(_BYTE *)(result[6][3].cbSize + 684) == 1 && (int)result[7] >= 1 )
  {
    v8 = (_SERVICE_STATUS *)result[6];
    v5 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
    v4 = GASValue::ToUInt32(this: v5, a2: v3, a3: a1, a4: v8);
  }
  v6 = (GFxAmpStatusChangedCallback *)result[1];
  v7 = *(unsigned __int8 *)(v3 + 12 * v4 + 64);
  if ( *(_BYTE *)v6 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v6, a2: v7);
  *((_DWORD *)v6 + 1) = v7;
  *(_BYTE *)v6 = 4;
}

//------------------------------------------------------------------------------
// Address: 0x101349E0
// Name: public: static void GASKeyCtorFunction::KeyGetCode(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASKeyCtorFunction::KeyGetCode(long double a1@<st0>, GASFnCall *result)
{
  GFxAmpStatusChangedCallback *v2; // eax
  int v3; // edi
  int v4; // eax
  GASValue *v5; // eax
  GFxAmpStatusChangedCallback *v6; // esi
  int v7; // edi
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-Ch]

  v2 = (GFxAmpStatusChangedCallback *)result[2];
  if ( v2 != nullptr )
    v3 = (int)v2 - 16;
  else
    v3 = 0;
  v4 = 0;
  if ( *(_BYTE *)(result[6][3].cbSize + 684) == 1 && (int)result[7] >= 1 )
  {
    v8 = (_SERVICE_STATUS *)result[6];
    v5 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
    v4 = GASValue::ToUInt32(this: v5, a2: v3, a3: a1, a4: v8);
  }
  v6 = (GFxAmpStatusChangedCallback *)result[1];
  v7 = *(_DWORD *)(v3 + 4 * (3 * v4 + 15));
  if ( *(_BYTE *)v6 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v6, a2: v7);
  *((_DWORD *)v6 + 1) = v7;
  *(_BYTE *)v6 = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10134A50
// Name: public: static void GASKeyCtorFunction::KeyIsDown(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASKeyCtorFunction::KeyIsDown(int a1@<edi>, long double a2@<st0>, GASFnCall *result)
{
  GASValue *v3; // eax
  int v4; // edi
  long double v5; // st7
  unsigned int v6; // eax
  GASValue *v7; // eax
  GFxAmpStatusChangedCallback *v8; // ecx
  char *v9; // ecx
  GFxKeyboardState *v10; // ecx
  bool v11; // bl
  GFxAmpStatusChangedCallback *v12; // esi
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-10h]
  _SERVICE_STATUS *v14; // [esp-8h] [ebp-10h]

  if ( (int)result[7] >= 1 )
  {
    v13 = (_SERVICE_STATUS *)result[6];
    v3 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
    v4 = GASValue::ToInt32(this: v3, a2: a1, a3: a2, a4: v13);
    v6 = 0;
    if ( *(_BYTE *)(result[6][3].cbSize + 684) == 1 && (int)result[7] >= 2 )
    {
      v14 = (_SERVICE_STATUS *)result[6];
      v7 = (GASValue *)GASFnCall::Arg(this: result, a2: 1);
      v6 = GASValue::ToUInt32(this: v7, a2: v4, a3: v5, a4: v14);
    }
    v8 = (GFxAmpStatusChangedCallback *)result[2];
    if ( v8 != nullptr )
      v9 = (char *)v8 - 16;
    else
      v9 = nullptr;
    v11 = v6 < 4
       && (v10 = (GFxKeyboardState *)(1660 * v6 + *((_DWORD *)v9 + 63) + 2516)) != nullptr
       && GFxKeyboardState::IsKeyDown(this: v10, code: v4);
    v12 = (GFxAmpStatusChangedCallback *)result[1];
    GASValue::DropRefs(this: (GASValue *)v12, a2: v4);
    *((_BYTE *)v12 + 4) = v11;
    *(_BYTE *)v12 = 2;
  }
  else
  {
    GASEnvironment::LogScriptError(
      this: (GASEnvironment *)result[6],
      a2: "Error: KeyIsDown needs one Argument (the key code)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134B00
// Name: public: static void GASKeyCtorFunction::KeyIsToggled(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASKeyCtorFunction::KeyIsToggled(int a1@<edi>, long double a2@<st0>, GASFnCall *result)
{
  GASValue *v3; // eax
  int v4; // edi
  long double v5; // st7
  unsigned int v6; // eax
  GASValue *v7; // eax
  GFxAmpStatusChangedCallback *v8; // ecx
  char *v9; // ecx
  GFxKeyboardState *v10; // ecx
  bool v11; // bl
  GFxAmpStatusChangedCallback *v12; // esi
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-10h]
  _SERVICE_STATUS *v14; // [esp-8h] [ebp-10h]

  if ( (int)result[7] >= 1 )
  {
    v13 = (_SERVICE_STATUS *)result[6];
    v3 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
    v4 = GASValue::ToInt32(this: v3, a2: a1, a3: a2, a4: v13);
    v6 = 0;
    if ( *(_BYTE *)(result[6][3].cbSize + 684) == 1 && (int)result[7] >= 2 )
    {
      v14 = (_SERVICE_STATUS *)result[6];
      v7 = (GASValue *)GASFnCall::Arg(this: result, a2: 1);
      v6 = GASValue::ToUInt32(this: v7, a2: v4, a3: v5, a4: v14);
    }
    v8 = (GFxAmpStatusChangedCallback *)result[2];
    if ( v8 != nullptr )
      v9 = (char *)v8 - 16;
    else
      v9 = nullptr;
    v11 = v6 < 4
       && (v10 = (GFxKeyboardState *)(1660 * v6 + *((_DWORD *)v9 + 63) + 2516)) != nullptr
       && GFxKeyboardState::IsKeyToggled(this: v10, code: v4);
    v12 = (GFxAmpStatusChangedCallback *)result[1];
    GASValue::DropRefs(this: (GASValue *)v12, a2: v4);
    *((_BYTE *)v12 + 4) = v11;
    *(_BYTE *)v12 = 2;
  }
  else
  {
    GASEnvironment::LogScriptError(
      this: (GASEnvironment *)result[6],
      a2: "Error: KeyIsToggled needs one Argument (the key code)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134BB0
// Name: protected: virtual enum GASObjectInterface::ObjectType GASKeyObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASKeyObject::GetObjectType()
{
  return 22;
}

//------------------------------------------------------------------------------
// Address: 0x10134BC0
// Name: public: GASKeyCtorFunction::GASKeyCtorFunction(class GASStringContext __near *,class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
GASKeyCtorFunction *__thiscall GASKeyCtorFunction::GASKeyCtorFunction(GASKeyCtorFunction *this, _REASON_CONTEXT *func, struct GFxMovieRoot *a3)
{
  HWND__ *v3; // edi
  char *v5; // esi
  char *v6; // eax
  int i; // ecx
  int v8; // edx
  struct GASStringNode *ConstStringNode; // eax
  int v10; // eax
  bool v11; // zf
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  void *v46; // ecx
  tagMSG v48; // [esp-8h] [ebp-2Ch] BYREF
  struct GASStringNode *v49; // [esp+1Ch] [ebp-8h] BYREF
  GASKeyCtorFunction *v50; // [esp+20h] [ebp-4h]

  v3 = (HWND__ *)func;
  v50 = this;
  GASCFunctionObject::GASCFunctionObject(
    (GASCFunctionObject *)this,
    func,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GlobalCtor);
  *((_DWORD *)this + 14) = &GFxKeyboardState::IListener::`vftable';
  v5 = (char *)this + 16;
  *(_DWORD *)this = &GASKeyCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 14) = &GASKeyCtorFunction::`vftable';
  v6 = (char *)this + 60;
  *((_DWORD *)this + 4) = &off_102A8488;
  for ( i = 15; i >= 0; --i )
  {
    *(_DWORD *)v6 = 0;
    v6[4] = 0;
    *((_DWORD *)v6 + 2) = 0;
    v6 += 12;
  }
  v48.message = (unsigned int)this + 16;
  v48.hwnd = v3;
  *((_DWORD *)v50 + 63) = a3;
  GASAsBroadcaster::Initialize(pobj: v48);
  v8 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 8;
  HIBYTE(func) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(v8 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"BACKSPACE",
                      a3: 9u,
                      a4: 0);
  v48.message = (unsigned int)&func + 3;
  v48.hwnd = (HWND__ *)&v48.pt;
  v49 = ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, HWND__ *, unsigned int))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: v48.hwnd,
    a5: v48.message);
  v10 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v10);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v12 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 20;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v12 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"CAPSLOCK",
          a3: 8u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v13 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v13);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v14 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 17;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v14 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"CONTROL",
          a3: 7u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v15 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v15);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v16 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 46;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v16 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"DELETEKEY",
          a3: 9u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v17 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v17);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v18 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 40;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v18 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"DOWN",
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v19 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v19);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v20 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 35;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v20 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_102A844C,
          a3: 3u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v21 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v21);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v22 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 13;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v22 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ENTER",
          a3: 5u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v23 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v23);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v24 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 27;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v24 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ESCAPE",
          a3: 6u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v25 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v25);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v26 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 36;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v26 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"HOME",
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v27 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v27);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v28 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 45;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v28 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"INSERT",
          a3: 6u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v29 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v29);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v30 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 37;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v30 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3F10.m_Memory.m_nGrowSize,
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v31 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v31);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v32 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 34;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v32 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"PGDN",
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v33 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v33);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v34 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 33;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v34 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"PGUP",
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v35 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v35);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v36 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 39;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v36 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3F10,
          a3: 5u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v37 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v37);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v38 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 16;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v38 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A8404.m_pElements,
          a3: 5u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v39 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v39);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v40 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 32;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v40 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A8404.m_Memory.m_nGrowSize,
          a3: 5u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v41 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v41);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v42 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 9;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v42 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A8404.m_Memory.m_nAllocationCount,
          a3: 3u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v43 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v43);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  v44 = *(_DWORD *)v3;
  LOBYTE(v48.pt.x) = 4;
  v48.pt.y = 38;
  HIBYTE(func) = 0;
  v49 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v44 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A8404,
          a3: 2u,
          a4: 0);
  ++*((_DWORD *)v49 + 2);
  (*(void (__thiscall **)(char *, HWND__ *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v5 + 40))(
    a1: v5,
    a2: v3,
    a3: &v49,
    a4: &v48.pt,
    a5: (char *)&func + 3);
  v45 = (int)v49;
  v11 = (*((_DWORD *)v49 + 2))-- == 1;
  if ( v11 )
    GASStringNode::ReleaseNode(a1: v45);
  GASValue::~GASValue(this: (GASValue *)&v48.pt, a2: (int)v3);
  GASNameFunction::AddConstMembers(
    pobj: v46,
    psc: (int)v5,
    psca: (CTSQueue<CFunctor *,0,1>::Node_t *)v3,
    a4: (struct GASObject **)&GASKeyCtorFunction::StaticFunctionTable,
    a5: 0);
  GFxMovieRoot::SetKeyboardListener(this: a3, l: (tagWNDCLASSEXA *)((char *)v50 + 56));
  return v50;
}

//------------------------------------------------------------------------------
// Address: 0x10135260
// Name: protected: virtual void GASKeyCtorFunction::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASKeyCtorFunction::Finalize_GC(
        GPtr<GFxAmpStatusChangedCallback> *this,
        GFxAmpStatusChangedCallback *a2)
{
  *((_DWORD *)this + 63) = 0;
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x10135340
// Name: public: GASKeyProto::GASKeyProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASKeyProto::GASKeyProto(
        GASPrototypeBase *this,
        GRefCountBaseStatImpl<GRefCountNTSImpl,2> *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4,
        unsigned int psc_8)
{
  GASPrototype<GASKeyObject,GASEnvironment>::GASPrototype<GASKeyObject,GASEnvironment>(
    (int)this,
    result: psc,
    psc_4,
    psc_8);
  this->__vftable = (IUnknown_vtbl *)&GASKeyProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASKeyObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPrototype<GASKeyObject,GASEnvironment>::`vftable';
  HIBYTE(psc_8) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: this + 13,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)&GAS_KeyFunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc_8 + 3));
}

//------------------------------------------------------------------------------
// Address: 0x10135400
// Name: public: void GASKeyCtorFunction::NotifyListeners(class GASStringContext __near *,int,unsigned char,unsigned long,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASKeyCtorFunction::NotifyListeners(
        GASKeyCtorFunction *this,
        struct GASStringContext *a2,
        int a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned __int8 a6,
        int a7)
{
  int v7; // esi
  char *v9; // eax
  GFxMovieRoot *v10; // edi
  struct GFxSprite *LevelMovie; // eax
  __vc_attributes::iid_isAttribute *v12; // eax
  int v13; // ebx
  int v14; // edi
  int v15; // edi
  int v16; // eax
  unsigned int v18[2]; // [esp+8h] [ebp-14h] BYREF
  __int16 v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+12h] [ebp-Ah]
  GASKeyCtorFunction *v21; // [esp+18h] [ebp-4h]

  v7 = (unsigned __int8)a7;
  *((_DWORD *)this + 3 * (unsigned __int8)a7 + 15) = a3;
  v9 = (char *)this + 12 * v7;
  v9[64] = a4;
  *((_DWORD *)v9 + 17) = a5;
  v18[0] = a6;
  v19 = 0;
  v21 = this;
  v18[1] = 0;
  v20 = 65280;
  GFxEventId::GetFunctionName(this: v18, a2: &a7, psc: a2);
  v10 = *((GFxMovieRoot **)this + 63);
  if ( v10 != nullptr )
  {
    LevelMovie = GFxMovieRoot::GetLevelMovie(this: v10, level: 0);
    if ( LevelMovie != nullptr )
    {
      v12 = (__vc_attributes::iid_isAttribute *)(*(int (__thiscall **)(struct GFxSprite *))(*(_DWORD *)LevelMovie + 112))(a1: LevelMovie);
      v13 = (int)v12;
      if ( v12 != nullptr )
      {
        v14 = 0;
        if ( *((_BYTE *)v12[30].limited_expression + 684) == 1 )
        {
          v12[2].limited_expression += 16;
          if ( v12[2].limited_expression >= v12[4].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: v12 + 2);
          v15 = *(_DWORD *)(v13 + 8);
          if ( v15 != 0 )
          {
            *(_BYTE *)v15 = 4;
            *(_DWORD *)(v15 + 4) = v7;
          }
          v14 = 1;
        }
        GASAsBroadcaster::BroadcastMessage(
          a1: v13,
          a2: v14,
          a3: v7,
          a4: (struct GASEnvironment *)v13,
          eventName: (_IMAGE_SYMBOL_EX *)((char *)v21 + 16),
          a6: (const struct GASString *)&a7,
          nArgs: v14,
          firstArgBottomIndex: ((*(_DWORD *)(v13 + 8) - *(_DWORD *)(v13 + 12)) >> 4) + 32 * *(_DWORD *)(v13 + 28) - 32);
        for ( ; v14 != 0; --v14 )
        {
          GASValue::~GASValue(this: *(GASValue **)(v13 + 8), a2: v14);
          *(_DWORD *)(v13 + 8) -= 16;
          if ( *(_DWORD *)(v13 + 8) < *(_DWORD *)(v13 + 12) )
            GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v13 + 8));
        }
      }
    }
  }
  v16 = a7;
  if ( (*(_DWORD *)(a7 + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v16);
}

//------------------------------------------------------------------------------
// Address: 0x10135530
// Name: protected: virtual void GASKeyCtorFunction::OnKeyDown(class GASStringContext __near *,int,unsigned char,unsigned long,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASKeyCtorFunction::OnKeyDown(
        GASKeyCtorFunction *this,
        struct GASStringContext *code,
        int a3,
        unsigned __int8 ascii,
        unsigned int wcharCode,
        int keyboardIndex)
{
  GASKeyCtorFunction::NotifyListeners(
    this: (GASKeyCtorFunction *)((char *)this - 56),
    a2: code,
    a3,
    a4: ascii,
    a5: wcharCode,
    a6: 0x40u,
    a7: keyboardIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10135560
// Name: protected: virtual void GASKeyCtorFunction::OnKeyUp(class GASStringContext __near *,int,unsigned char,unsigned long,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASKeyCtorFunction::OnKeyUp(
        GASKeyCtorFunction *this,
        struct GASStringContext *code,
        int a3,
        unsigned __int8 ascii,
        unsigned int wcharCode,
        int keyboardIndex)
{
  GASKeyCtorFunction::NotifyListeners(
    this: (GASKeyCtorFunction *)((char *)this - 56),
    a2: code,
    a3,
    a4: ascii,
    a5: wcharCode,
    a6: 0x80u,
    a7: keyboardIndex);
}
