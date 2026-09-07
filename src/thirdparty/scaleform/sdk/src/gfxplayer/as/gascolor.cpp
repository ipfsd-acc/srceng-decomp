// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gascolor.cpp
// Functions: 10
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gascolor.h"

//------------------------------------------------------------------------------
// Address: 0x100B3E20
// Name: protected: virtual void GASColorObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASColorObject::Finalize_GC(
        GPtr<GFxAmpServer::SourceFileInfo> *this,
        GFxAmpMessageCurrentState *result)
{
  _DWORD *v2; // eax

  v2 = *((_DWORD **)this + 13);
  if ( v2 != nullptr && (*v2)-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x1010C470
// Name: public: virtual enum GASObjectInterface::ObjectType GASColorObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASColorObject::GetObjectType()
{
  return 21;
}

//------------------------------------------------------------------------------
// Address: 0x1010C5C0
// Name: public: void GASColorObject::SetTarget(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASColorObject::SetTarget(GASColorObject *this, GRefCountWeakSupportImpl *a2)
{
  struct GWeakPtrProxy *WeakProxy; // edi
  _DWORD *v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax

  if ( a2 != nullptr )
  {
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: a2);
    v4 = *((_DWORD **)this + 13);
    if ( v4 != nullptr )
    {
      v5 = (*v4)-- == 1;
      if ( v5 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    }
    *((_DWORD *)this + 13) = WeakProxy;
  }
  else
  {
    v6 = *((_DWORD **)this + 13);
    if ( v6 != nullptr )
    {
      v5 = (*v6)-- == 1;
      if ( v5 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    }
    *((_DWORD *)this + 13) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C620
// Name: public: static void GASColorProto::SetTransform(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASColorProto::SetTransform(double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  int *p_cxItem; // esi
  _DWORD *v4; // eax
  GRefCountNTSImpl *v5; // edi
  GRefCountNTSImpl *v6; // eax
  struct GASValue *v8; // eax
  _SERVICE_STATUS *v9; // eax
  GASObjectInterface *v10; // ebx
  struct GASStringContext *v11; // esi
  GRefCountNTSImpl *v12; // esi
  _SERVICE_STATUS *v13; // [esp-Ch] [ebp-48h]
  struct GRenderer::Cxform v14; // [esp+4h] [ebp-38h] BYREF
  GASValue v15[4]; // [esp+24h] [ebp-18h] BYREF
  float v16; // [esp+34h] [ebp-8h]
  GRefCountNTSImpl *v17; // [esp+38h] [ebp-4h]

  if ( !GASFnCall::CheckThisPtr(this: a2, type: 0x15u) )
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Color", a3: nullptr, a4: 0);
    return;
  }
  v2 = a2[2];
  if ( v2 != nullptr )
  {
    p_cxItem = &v2[-1].cxItem;
    if ( p_cxItem != nullptr )
    {
      v4 = (_DWORD *)p_cxItem[13];
      v5 = nullptr;
      v17 = nullptr;
      if ( v4 != nullptr )
      {
        if ( v4[1] != 0 )
        {
          v6 = (GRefCountNTSImpl *)v4[1];
          v17 = v6;
          if ( v6 != nullptr )
          {
            ++v6->RefCount;
            ++v6->RefCount;
            GRefCountNTSImpl::Release(this: v6);
            v5 = v17;
          }
          else
          {
            v5 = nullptr;
          }
        }
        else
        {
          if ( (*v4)-- == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
          p_cxItem[13] = 0;
        }
      }
      if ( (int)a2[7] < 1 )
      {
        if ( v5 == nullptr )
          return;
      }
      else
      {
        if ( v5 == nullptr )
          return;
        v13 = (_SERVICE_STATUS *)a2[6];
        v8 = GASFnCall::Arg(this: a2, a2: 0);
        v9 = GASValue::ToObjectInterface(a1: (int)v8, a2: (int)v5, result: v13);
        v10 = (GASObjectInterface *)v9;
        if ( v9 != nullptr )
        {
          v14 = *(struct GRenderer::Cxform *)&v5[4].RefCount;
          v11 = (struct GASStringContext *)&a2[6][3];
          LOBYTE(v15[0]) = 0;
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: (GASObjectInterface *)v9,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ba",
                 psc_8: (struct GASValue *)v15) != 0 )
          {
            v16 = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
            a1 = v16 / 100.0;
            v14.M_[2][0] = a1;
          }
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: v10,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ga",
                 psc_8: (struct GASValue *)v15) != 0 )
          {
            v16 = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
            a1 = v16 / 100.0;
            v14.M_[1][0] = a1;
          }
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: v10,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ra",
                 psc_8: (struct GASValue *)v15) != 0 )
          {
            v16 = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
            a1 = v16 / 100.0;
            v14.M_[0][0] = a1;
          }
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: v10,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"aa",
                 psc_8: (struct GASValue *)v15) != 0 )
          {
            v16 = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
            a1 = v16 / 100.0;
            v14.M_[3][0] = a1;
          }
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: v10,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"bb",
                 psc_8: (struct GASValue *)v15) != 0 )
          {
            a1 = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
            v14.M_[2][1] = a1;
          }
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: v10,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"gb",
                 psc_8: (struct GASValue *)v15) != 0 )
          {
            a1 = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
            v14.M_[1][1] = a1;
          }
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: v10,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"rb",
                 psc_8: (struct GASValue *)v15) != 0 )
          {
            a1 = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
            v14.M_[0][1] = a1;
          }
          if ( GASObjectInterface::GetConstMemberRaw(
                 this: v10,
                 psc: v11,
                 psc_4: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ab",
                 psc_8: (struct GASValue *)v15) != 0 )
            v14.M_[3][1] = GASValue::ToNumber(this: v15, (int)a2, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
          v12 = v17;
          GFxCharacter::SetCxform(this: (GFxCharacter *)v17, a2: &v14);
          ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v12->__vftable[8].dtr_GRefCountImplCore)(a1: v12, a2: 0);
          GASValue::~GASValue(this: v15, (int)a2);
          GRefCountNTSImpl::Release(this: v12);
          return;
        }
      }
      GRefCountNTSImpl::Release(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C890
// Name: public: static void GASColorProto::SetRGB(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASColorProto::SetRGB(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  int *p_cxItem; // esi
  _DWORD *v4; // eax
  GRefCountNTSImpl *v5; // ebx
  GASValue *v6; // eax
  double v7; // st7
  GRefCountNTSImpl_vtbl *v8; // edx
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountNTSImpl *); // eax
  _SERVICE_STATUS *v11; // [esp-Ch] [ebp-3Ch]
  float v12[8]; // [esp+4h] [ebp-2Ch] BYREF
  __int64 v13; // [esp+24h] [ebp-Ch]
  unsigned __int16 v14; // [esp+2Eh] [ebp-2h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x15u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = &v2[-1].cxItem;
      if ( p_cxItem != nullptr )
      {
        v4 = (_DWORD *)p_cxItem[13];
        v5 = nullptr;
        if ( v4 != nullptr )
        {
          if ( v4[1] != 0 )
          {
            v5 = (GRefCountNTSImpl *)v4[1];
            if ( v5 != nullptr )
            {
              ++v5->RefCount;
              ++v5->RefCount;
              GRefCountNTSImpl::Release(this: v5);
            }
          }
          else
          {
            if ( (*v4)-- == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
            p_cxItem[13] = 0;
          }
        }
        if ( (int)a2[7] < 1 )
        {
          if ( v5 != nullptr )
            GRefCountNTSImpl::Release(this: v5);
        }
        else if ( v5 != nullptr )
        {
          v11 = (_SERVICE_STATUS *)a2[6];
          v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
          v7 = GASValue::ToNumber(this: v6, (int)a2, a3: a1, result: v11);
          HIDWORD(v13) = v14 | 0xC00;
          v8 = v5->__vftable;
          qmemcpy(v12, (const void *)&v5[4].RefCount, sizeof(v12));
          v13 = (__int64)v7;
          HIDWORD(v13) = (unsigned __int8)((unsigned int)(__int64)v7 >> 16);
          v12[4] = 0.0;
          v12[2] = 0.0;
          v12[0] = 0.0;
          v12[1] = (float)SHIDWORD(v13);
          HIDWORD(v13) = (unsigned __int8)(__int64)v7;
          dtr_GRefCountImplCore = v8[1].dtr_GRefCountImplCore;
          v12[3] = (float)(unsigned __int8)((unsigned __int16)(__int64)v7 >> 8);
          v12[5] = (float)SHIDWORD(v13);
          qmemcpy((void *)&v5[4].RefCount, v12, 32);
          dtr_GRefCountImplCore(this: v5);
          ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))v5->__vftable[8].dtr_GRefCountImplCore)(a1: v5, a2: 0);
          GRefCountNTSImpl::Release(this: v5);
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Color", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C9F0
// Name: public: static void GASColorProto::GetRGB(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASColorProto::GetRGB(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int *p_cxItem; // esi
  _DWORD *v3; // eax
  GRefCountNTSImpl *v4; // ebx
  GASFnCall v5; // edi
  int v6; // esi
  float v8[8]; // [esp+4h] [ebp-2Ch] BYREF
  __int64 v9; // [esp+24h] [ebp-Ch]
  unsigned __int16 v10; // [esp+2Eh] [ebp-2h]

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x15u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = &v1[-1].cxItem;
      if ( v1 != (GASFnCall)16 )
      {
        v3 = (_DWORD *)p_cxItem[13];
        if ( v3 != nullptr )
        {
          if ( v3[1] != 0 )
          {
            v4 = (GRefCountNTSImpl *)v3[1];
            if ( v4 != nullptr )
            {
              ++v4->RefCount;
              ++v4->RefCount;
              GRefCountNTSImpl::Release(this: v4);
              qmemcpy(v8, (const void *)&v4[4].RefCount, sizeof(v8));
              v9 = (__int64)v8[3];
              HIDWORD(v9) = v10 | 0xC00;
              v5 = a1[1];
              v9 = (__int64)v8[5];
              v6 = (unsigned __int8)v9
                 | (((unsigned __int8)(__int64)v8[3] | ((unsigned __int8)(__int64)v8[1] << 8)) << 8);
              if ( LOBYTE(v5->cbSize) >= 5u )
                GASValue::DropRefs(this: (GASValue *)v5, a2: (int)v5);
              LOBYTE(v5->cbSize) = 4;
              v5->cItems = v6;
              GRefCountNTSImpl::Release(this: v4);
            }
          }
          else
          {
            if ( (*v3)-- == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
            p_cxItem[13] = 0;
          }
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Color", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010CBE0
// Name: public: static void GASColorProto::GetTransform(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASColorProto::GetTransform(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  _DWORD *v4; // eax
  GRefCountNTSImpl *v5; // ebx
  int v6; // ecx
  int (__thiscall *v7)(int, int, struct GASObject **); // eax
  GASObject *v8; // eax
  tagWNDCLASSW *v10; // esi
  struct GASObject *v11; // edi
  struct GASObject *v12; // esi
  GASValue v14; // [esp+4h] [ebp-A8h] BYREF
  double v15; // [esp+8h] [ebp-A4h]
  GASValue v16; // [esp+14h] [ebp-98h] BYREF
  double v17; // [esp+18h] [ebp-94h]
  GASValue v18; // [esp+24h] [ebp-88h] BYREF
  double v19; // [esp+28h] [ebp-84h]
  GASValue v20; // [esp+34h] [ebp-78h] BYREF
  double v21; // [esp+38h] [ebp-74h]
  GASValue v22; // [esp+44h] [ebp-68h] BYREF
  double v23; // [esp+48h] [ebp-64h]
  GASValue v24; // [esp+54h] [ebp-58h] BYREF
  double v25; // [esp+58h] [ebp-54h]
  GASValue v26; // [esp+64h] [ebp-48h] BYREF
  double v27; // [esp+68h] [ebp-44h]
  GASValue v28; // [esp+74h] [ebp-38h] BYREF
  double v29; // [esp+78h] [ebp-34h]
  float v30[8]; // [esp+84h] [ebp-28h] BYREF
  struct GASObject *v31; // [esp+A4h] [ebp-8h] BYREF
  float v32; // [esp+A8h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x15u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
    {
      p_cxItem = &v2[-1].cxItem;
      if ( v2 != (GASFnCall)16 )
      {
        v4 = (_DWORD *)p_cxItem[13];
        if ( v4 != nullptr )
        {
          if ( v4[1] != 0 )
          {
            v5 = (GRefCountNTSImpl *)v4[1];
            if ( v5 != nullptr )
            {
              ++v5->RefCount;
              ++v5->RefCount;
              GRefCountNTSImpl::Release(this: v5);
              qmemcpy(v30, (const void *)&v5[4].RefCount, sizeof(v30));
              v6 = *(_DWORD *)(a2[6][3].cbSize + 656);
              v7 = *(int (__thiscall **)(int, int, struct GASObject **))(*(_DWORD *)v6 + 40);
              v31 = (struct GASObject *)323;
              v8 = (GASObject *)v7(a1: v6, a2: 52, a3: &v31);
              if ( v8 != nullptr )
                v31 = GASObject::GASObject(this: v8, a2: (struct GASEnvironment *)a2[6]);
              else
                v31 = nullptr;
              v10 = (tagWNDCLASSW *)a2[6];
              v32 = v30[4] * 100.0;
              v10 += 3;
              v11 = v31 + 2;
              v17 = v32;
              LOBYTE(v16) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: &v31[2],
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ba",
                a4: (int)&v16);
              GASValue::~GASValue(this: &v16, a2: (int)v11);
              v32 = v30[2] * 100.0;
              v15 = v32;
              LOBYTE(v14) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: v11,
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ga",
                a4: (int)&v14);
              GASValue::~GASValue(this: &v14, a2: (int)v11);
              v32 = v30[0] * 100.0;
              v25 = v32;
              LOBYTE(v24) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: v11,
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ra",
                a4: (int)&v24);
              GASValue::~GASValue(this: &v24, a2: (int)v11);
              v32 = v30[6] * 100.0;
              v29 = v32;
              LOBYTE(v28) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: v11,
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"aa",
                a4: (int)&v28);
              GASValue::~GASValue(this: &v28, a2: (int)v11);
              v21 = v30[5];
              LOBYTE(v20) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: v11,
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"bb",
                a4: (int)&v20);
              GASValue::~GASValue(this: &v20, a2: (int)v11);
              v27 = v30[3];
              LOBYTE(v26) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: v11,
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"gb",
                a4: (int)&v26);
              GASValue::~GASValue(this: &v26, a2: (int)v11);
              v23 = v30[1];
              LOBYTE(v22) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: v11,
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"rb",
                a4: (int)&v22);
              GASValue::~GASValue(this: &v22, a2: (int)v11);
              v19 = v30[7];
              LOBYTE(v18) = 3;
              GASObjectInterface::SetConstMemberRaw(
                this: v11,
                result: v10,
                a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ab",
                a4: (int)&v18);
              GASValue::~GASValue(this: &v18, a2: (int)v11);
              v12 = v31;
              GASValue::SetAsObject(this: (GASValue *)a2[1], a2: v31);
              if ( v12 != nullptr )
                GRefCountBaseGC<323>::Release(a1: (int)v12, a2: a1);
              GRefCountNTSImpl::Release(this: v5);
            }
          }
          else
          {
            if ( (*v4)-- == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
            p_cxItem[13] = 0;
          }
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Color", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010CE60
// Name: public: static void GASColorCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASColorCtorFunction::GlobalCtor(GASFnCall *a1)
{
  GASFnCall *v1; // edi
  bool v2; // cc
  struct GASValue *v3; // eax
  GASFnCall v4; // eax
  int *p_cxItem; // ecx
  int v6; // esi
  int v7; // ecx
  int (__thiscall *v8)(int, int, int *); // edx
  GASObject *v9; // eax
  GASFnCall v10; // edi
  GRefCountWeakSupportImpl *v11; // ecx
  struct GWeakPtrProxy *WeakProxy; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  int v14; // [esp+8h] [ebp-8h] BYREF
  GRefCountWeakSupportImpl *TargetByValue; // [esp+Ch] [ebp-4h]

  v1 = a1;
  v2 = (int)a1[7] < 1;
  TargetByValue = nullptr;
  if ( !v2 )
  {
    v3 = GASFnCall::Arg(this: a1, a2: 0);
    TargetByValue = (GRefCountWeakSupportImpl *)GASEnvironment::FindTargetByValue(
                                                  this: (GASEnvironment *)a1[6],
                                                  path: (__vc_attributes::event_receiverAttribute::type_e)v3);
  }
  if ( a1[2] != nullptr && (*(int (__thiscall **)(GASFnCall))(a1[2]->cbSize + 8))(a1: a1[2]) == 21 )
  {
    v4 = a1[2];
    if ( v4 != nullptr )
    {
      p_cxItem = &v4[-1].cxItem;
      if ( v4 != (GASFnCall)16 )
        p_cxItem[2] = (p_cxItem[2] + 1) & 0x8FFFFFFF;
      v6 = (int)&v4[-1].cxItem;
      GASColorObject::SetTarget(this: (GASColorObject *)p_cxItem, a2: TargetByValue);
    }
    else
    {
      v6 = 0;
      GASColorObject::SetTarget(this: nullptr, a2: TargetByValue);
    }
  }
  else
  {
    v7 = *(_DWORD *)(a1[6][3].cbSize + 656);
    v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
    v14 = 323;
    v9 = (GASObject *)v8(a1: v7, a2: 56, a3: &v14);
    v6 = (int)v9;
    if ( v9 != nullptr )
    {
      v10 = a1[6];
      GASObject::GASObject(this: v9, a2: (struct GASEnvironment *)v10);
      v11 = TargetByValue;
      *(_DWORD *)v6 = &GASColorObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(v6 + 16) = &GASColorObject::`vftable'{for `GASObjectInterface'};
      if ( v11 != nullptr )
        WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: v11);
      else
        WeakProxy = nullptr;
      *(_DWORD *)(v6 + 52) = WeakProxy;
      Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                        this: (vc_attributes::PreRangeAttribute *)v10[3].cbSize,
                                                        result: (vc_attributes::InvalidCheckAttribute *)0xB);
      GASObject::Set__proto__(
        this: (CTSQueue<CFunctor *,0,1> *)(v6 + 16),
        psc: (CTSQueue<CFunctor *,0,1>::Node_t *)&v10[3],
        psc_4: Prototype);
      v1 = a1;
    }
    else
    {
      v6 = 0;
    }
  }
  GASValue::SetAsObject(this: (GASValue *)v1[1], a2: (struct GASObject *)v6);
  if ( v6 != 0 )
    GRefCountBaseGC<323>::Release(a1: v6, a2: (int)v1);
}

//------------------------------------------------------------------------------
// Address: 0x1010CF70
// Name: public: virtual class GASObject __near * GASColorCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASColorCtorFunction::CreateNewObject(
        GHashSet<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeAltHashF,GAllocatorLH<unsigned __int64,2>,GHashsetCachedNodeEntry<GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >,GHashNode<unsigned __int64,GPtr<GFxAmpServer::SourceFileInfo>,GFixedSizeHash<unsigned __int64> >::NodeHashF> > *this@<ecx>,
        int penv,
        int a3)
{
  struct GASEnvironment *v3; // ebx
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  vc_attributes::PreRangeAttribute **v6; // edi
  GASObject *v7; // eax
  GASObject *v8; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v3 = (struct GASEnvironment *)penv;
  v4 = *(_DWORD *)(*(_DWORD *)(penv + 120) + 656);
  v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
  v6 = (vc_attributes::PreRangeAttribute **)(penv + 120);
  penv = 323;
  v7 = (GASObject *)v5(a1: v4, a2: 56, a3: &penv);
  v8 = v7;
  if ( v7 != nullptr )
  {
    GASObject::GASObject(this: v7, a2: v3);
    v8->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASColorObject::`vftable'{for `GASRefCountBase<GASObject>'};
    v8[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASColorObject::`vftable'{for `GASObjectInterface'};
    v8[6].sequence = 0;
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: *v6,
                                                      result: (vc_attributes::InvalidCheckAttribute *)0xB);
    GASObject::Set__proto__(
      this: (CTSQueue<CFunctor *,0,1> *)&v8[2],
      psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v6,
      psc_4: Prototype);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D0C0
// Name: public: static class GASFunctionRef GASColorCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASColorCtorFunction::Register(void *pgc, struct GASFunctionRef *a2, _KCRM_MARSHAL_HEADER *pgca)
{
  vc_attributes::PreRangeAttribute *v3; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v5)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v6; // eax
  GASCFunctionObject *v7; // ebx
  GASCFunctionObject *v8; // eax
  struct GASFunctionRef *v9; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, struct GASFunctionRef **); // edx
  int v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v14; // eax
  int p_MinVal; // edi
  GASValue v16[4]; // [esp+Ch] [ebp-20h] BYREF
  vc_attributes::PreRangeAttribute *psc[2]; // [esp+1Ch] [ebp-10h] BYREF
  void (__thiscall **psc_8)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *psc_12; // [esp+28h] [ebp-4h]

  v3 = (vc_attributes::PreRangeAttribute *)pgca;
  VersionMajor = pgca[41].VersionMajor;
  psc[0] = (vc_attributes::PreRangeAttribute *)pgca;
  LOBYTE(psc[1]) = 8;
  v5 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v6 = (GASCFunctionObject *)v5(a1: VersionMajor, a2: 56, a3: &pgca);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v6,
      func: (_REASON_CONTEXT *)psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASColorCtorFunction::GlobalCtor);
    v7->dwSize = (unsigned int)&GASColorCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v7->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = a2;
  *(_DWORD *)a2 = v8;
  *((_BYTE *)v9 + 8) = 0;
  *((_DWORD *)v9 + 1) = 0;
  MaxVal = v3[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a2 = (struct GASFunctionRef *)323;
  v12 = v11(a1: MaxVal, a2: 88, a3: &a2);
  if ( v12 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v3,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASColorObject,GASEnvironment>::GASPrototype<GASColorObject,GASEnvironment>(
      this: (FontVertex_t *)v12,
      (const FontVertex_t *)psc,
      psc_4: Prototype,
      psc_8: (unsigned int)v9);
    *(_DWORD *)v12 = &GASColorProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v12 + 16) = &GASColorProto::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v12 + 56) = &GASColorProto::`vftable';
    HIBYTE(pgca) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v12 + 56),
      a2: v12,
      flags: psc,
      flags_4: (const struct GASNameFunction *)&GAS_ColorFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgca + 3));
  }
  else
  {
    v12 = 0;
  }
  if ( v12 != 0 )
    *(_DWORD *)(v12 + 8) = (*(_DWORD *)(v12 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, a2: (int)v3, a3: 11, a4: v12);
  psc_12 = v3[56].MaxVal + 16;
  HIBYTE(pgca) = 0;
  psc_8 = (void (__thiscall **)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *))(*psc_12 + 40);
  v14 = GASValue::GASValue(this: v16, a2: (int)v3, a3: v9);
  p_MinVal = (int)&v3[4].MinVal;
  (*psc_8)(a1: psc_12, a2: psc, a3: p_MinVal, a4: v14, a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: v16, a2: p_MinVal);
  if ( v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2: p_MinVal);
}
