// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasasbroadcaster.cpp
// Functions: 16
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasasbroadcaster.h"

//------------------------------------------------------------------------------
// Address: 0x10117070
// Name: public: static bool GASAsBroadcaster::InitializeProto(class GASStringContext __near *,class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
static char __cdecl GASAsBroadcaster::InitializeProto(tagMSG pobj)
{
  if ( pobj.message == 0 )
    return 0;
  GASNameFunction::AddConstMembers(
    pobj: pobj.hwnd,
    psc: pobj.message,
    psca: (CTSQueue<CFunctor *,0,1>::Node_t *)pobj.hwnd,
    a4: (struct GASObject **)&GAS_AsBcFunctionTable,
    a5: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101170A0
// Name: public: virtual enum GASObjectInterface::ObjectType GASAsBroadcaster::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASAsBroadcaster::GetObjectType()
{
  return 36;
}

//------------------------------------------------------------------------------
// Address: 0x101170B0
// Name: public: virtual class GASObject __near * GASAsBroadcasterCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASObject *__stdcall GASAsBroadcasterCtorFunction::CreateNewObject(struct GASEnvironment *a1)
{
  struct GASEnvironment *v1; // edi
  int v2; // ecx
  int (__thiscall *v3)(int, int, struct GASEnvironment **); // edx
  vc_attributes::PreRangeAttribute **v4; // ebx
  GASObject *v5; // eax
  GASObject *v6; // esi
  vc_attributes::InvalidCheckAttribute *Prototype; // eax

  v1 = a1;
  v2 = *(_DWORD *)(*((_DWORD *)a1 + 30) + 656);
  v3 = *(int (__thiscall **)(int, int, struct GASEnvironment **))(*(_DWORD *)v2 + 40);
  v4 = (vc_attributes::PreRangeAttribute **)((char *)a1 + 120);
  a1 = (struct GASEnvironment *)323;
  v5 = (GASObject *)v3(a1: v2, a2: 52, a3: &a1);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v5, a2: v1);
  v6->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v6[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASAsBroadcaster::`vftable'{for `GASObjectInterface'};
  Prototype = GASGlobalContext::GetPrototype(this: *v4, result: (vc_attributes::InvalidCheckAttribute *)0x13);
  ((void (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t **, vc_attributes::PreRangeAttribute **, vc_attributes::InvalidCheckAttribute *))v6[2].pNode[6].elem)(
    a1: &v6[2].pNode,
    a2: v4,
    a3: Prototype);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10117120
// Name: public: static bool GASAsBroadcaster::InitializeInstance(class GASStringContext __near *,class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
static char __usercall GASAsBroadcaster::InitializeInstance@<al>(
        int a1@<edi>,
        int a2@<esi>,
        GASGlobalContext **pobj,
        struct GASObjectInterface *pobj_4)
{
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *, int, int); // edx
  int v7; // eax
  struct GASObject *v8; // edi
  GASGlobalContext *v9; // esi
  int v10; // ebx
  GMemAddressStub *v11; // [esp+0h] [ebp-1Ch]
  GASValue v12[4]; // [esp+4h] [ebp-18h] BYREF
  int v13; // [esp+14h] [ebp-8h] BYREF
  char v14; // [esp+1Bh] [ebp-1h]

  if ( pobj_4 == nullptr )
    return 0;
  v5 = *((_DWORD *)*pobj + 164);
  v6 = *(int (__thiscall **)(int, int, int *, int, int))(*(_DWORD *)v5 + 40);
  v13 = 323;
  v7 = v6(a1: v5, a2: 76, a3: &v13, a4: a1, a5: a2);
  if ( v7 != 0 )
    v8 = (struct GASObject *)GASArrayObject::GASArrayObject(
                               a1: v7,
                               psc: pobj,
                               psc_4: v11,
                               psc_8: (const char *)v12[0],
                               psc_12: (int)v12[1]);
  else
    v8 = nullptr;
  v9 = *pobj;
  v10 = *(_DWORD *)pobj_4;
  v14 = 1;
  GASValue::GASValue(this: v12, a2: v8);
  (*(void (__thiscall **)(struct GASObjectInterface *, GASGlobalContext **, int))(v10 + 40))(
    a1: pobj_4,
    a2: pobj,
    a3: (int)v9 + 332);
  GASValue::~GASValue(this: v12, a2: (int)v8);
  if ( v8 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v8, a2: (int)v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101171B0
// Name: public: static bool GASAsBroadcaster::AddListener(class GASEnvironment __near *,class GASObjectInterface __near *,class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASAsBroadcaster::AddListener(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        _SERVICE_STATUS *result,
        int *plistener,
        struct GASObjectInterface *plistener_4)
{
  int v7; // edi
  unsigned __int8 (__stdcall *v8)(unsigned int *, int, GASValue *, int, int, int); // eax
  struct GASObject *v9; // eax
  struct GASObject *v10; // esi
  unsigned int sequence; // ebx
  int v12; // ecx
  int v13; // [esp-14h] [ebp-34h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *val; // [esp+0h] [ebp-20h] BYREF
  GASValue listenersVal[4]; // [esp+10h] [ebp-10h] BYREF

  if ( plistener == nullptr || plistener_4 == nullptr )
    return;
  v7 = *plistener;
  v13 = result[4].dwControlsAccepted + 332;
  v8 = *(unsigned __int8 (__stdcall **)(unsigned int *, int, GASValue *, int, int, int))(*plistener + 44);
  LOBYTE(listenersVal[0]) = 0;
  if ( v8(a1: &result[4].dwControlsAccepted, a2: v13, a3: listenersVal, a4: a2, a5: a3, a6: a1) == 0
    || (v9 = GASValue::ToObject(this: listenersVal, a2: v7, a3: (const struct GASEnvironment *)result),
        v10 = v9,
        v9 == nullptr)
    || ((int (__thiscall *)(struct GASObject *))v9[2].pNode[1].pNext)(a1: &v9[2]) != 7 )
  {
LABEL_11:
    GASValue::~GASValue(this: listenersVal, a2: v7);
    return;
  }
  sequence = v10[7].sequence;
  v7 = 0;
  v10[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v10[1].pNode->pNext + 1) & 0x8FFFFFFF);
  if ( sequence == 0 )
  {
LABEL_10:
    LOBYTE(val) = 0;
    GASValue::SetAsObjectInterface(this: &val, a2: plistener_4);
    GASArrayObject::PushBack(this: (GASArrayObject *)v10, (tagWNDCLASSW *)&val);
    GASValue::~GASValue(this: &val, a2: v7);
    GRefCountBaseGC<323>::Release(a1: (int)v10, a2: v7);
    goto LABEL_11;
  }
  while ( 1 )
  {
    v12 = *((_DWORD *)&v10[7].pNode->pNext + v7);
    if ( v12 != 0 && GASValue::ToObjectInterface(a1: v12, a2: v7, result) == (_SERVICE_STATUS *)plistener_4 )
      break;
    if ( ++v7 >= sequence )
      goto LABEL_10;
  }
  GRefCountBaseGC<323>::Release(a1: (int)v10, a2: v7);
  GASValue::~GASValue(this: listenersVal, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101172A0
// Name: public: static bool GASAsBroadcaster::RemoveListener(class GASEnvironment __near *,class GASObjectInterface __near *,class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASAsBroadcaster::RemoveListener(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        _SERVICE_STATUS *result,
        int plistener,
        _SERVICE_STATUS *plistener_4)
{
  int v7; // edi
  unsigned __int8 (__stdcall *v8)(unsigned int *, int, GASValue *, int, int, int); // eax
  struct GASObject *v9; // eax
  ISteamApps *v10; // esi
  int v11; // ecx
  int v12; // [esp-14h] [ebp-24h]
  GASValue listenersVal[4]; // [esp+0h] [ebp-10h] BYREF

  if ( plistener == 0 || plistener_4 == nullptr )
    return;
  v7 = (int)listenersVal;
  v12 = result[4].dwControlsAccepted + 332;
  v8 = *(unsigned __int8 (__stdcall **)(unsigned int *, int, GASValue *, int, int, int))(*(_DWORD *)plistener + 44);
  LOBYTE(listenersVal[0]) = 0;
  if ( v8(a1: &result[4].dwControlsAccepted, a2: v12, a3: listenersVal, a4: a2, a5: a3, a6: a1) == 0
    || (v9 = GASValue::ToObject(this: listenersVal, a2: (int)listenersVal, a3: (const struct GASEnvironment *)result),
        v10 = (ISteamApps *)v9,
        v9 == nullptr)
    || ((int (__thiscall *)(struct GASObject *))v9[2].pNode[1].pNext)(a1: &v9[2]) != 7 )
  {
LABEL_11:
    GASValue::~GASValue(this: listenersVal, a2: v7);
    return;
  }
  v7 = (int)&v10[15].__vftable[-1].BIsSubscribedFromFreeWeekend + 3;
  v10[2].__vftable = (ISteamApps_vtbl *)(((int)&v10[2].BIsSubscribed + 1) & 0x8FFFFFFF);
  if ( v7 < 0 )
  {
LABEL_10:
    GRefCountBaseGC<323>::Release(a1: (int)v10, a2: v7);
    goto LABEL_11;
  }
  while ( 1 )
  {
    v11 = *((_DWORD *)&v10[14].BIsSubscribed + v7);
    if ( v11 != 0 && GASValue::ToObjectInterface(a1: v11, a2: v7, result) == plistener_4 )
      break;
    if ( --v7 < 0 )
      goto LABEL_10;
  }
  GASArrayObject::RemoveElements(this: v10, start: v7, count: 1);
  GRefCountBaseGC<323>::Release(a1: (int)v10, a2: v7);
  GASValue::~GASValue(this: listenersVal, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10117370
// Name: _GASAsBroadcaster::BroadcastMessage_::_4_::LocalInvokeCallback::Invoke
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASAsBroadcaster::BroadcastMessage_::_4_::LocalInvokeCallback::Invoke(
        int a1@<ecx>,
        int a2@<edi>,
        int a3,
        int a4,
        int *a5)
{
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  _DWORD v9[3]; // [esp+4h] [ebp-34h] BYREF
  int v10; // [esp+10h] [ebp-28h]
  int v11; // [esp+14h] [ebp-24h]
  char v12; // [esp+18h] [ebp-20h]
  int v13; // [esp+1Ch] [ebp-1Ch]
  int v14; // [esp+20h] [ebp-18h]
  int v15; // [esp+24h] [ebp-14h]
  GASValue v16[4]; // [esp+28h] [ebp-10h] BYREF

  v5 = *(_DWORD *)(a1 + 8);
  v6 = *(_DWORD *)(a1 + 4);
  v15 = v5;
  v9[1] = v16;
  v9[2] = a4;
  v14 = v6;
  v7 = *a5;
  v8 = a5[1];
  v13 = a3;
  LOBYTE(v16[0]) = 0;
  v9[0] = &GASFnCall::`vftable';
  v12 = 0;
  v10 = 0;
  v11 = 0;
  (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v7 + 40))(a1: v7, a2: v9, a3: v8, a4: 0);
  v9[0] = &GASFnCall::`vftable';
  if ( (v12 & 2) == 0 && v10 != 0 )
    GRefCountBaseGC<323>::Release(a1: v10, a2);
  v10 = 0;
  if ( (v12 & 1) == 0 && v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2);
  GASValue::~GASValue(this: v16, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10117400
// Name: public: static bool GASAsBroadcaster::BroadcastMessageWithCallback(class GASEnvironment __near *,class GASObjectInterface __near *,class GASString const __near &,class GASAsBroadcaster::InvokeCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASAsBroadcaster::BroadcastMessageWithCallback(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned int penva,
        _IMAGE_SYMBOL_EX *eventName,
        int a6,
        int a7)
{
  unsigned int v8; // esi
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **p_listenersVal; // edi
  unsigned __int8 (__thiscall *v10)(_IMAGE_SYMBOL_EX *, unsigned int, int, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **, int, int, int); // eax
  struct GASObject *v11; // eax
  bool v12; // cc
  int v13; // ecx
  int (__thiscall *v14)(int, int, int *); // eax
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  GASValue *v18; // esi
  _SERVICE_STATUS *v19; // edi
  bool v20; // zf
  GStat::StatValue *v21; // eax
  int v22; // esi
  struct GASObject *v23; // eax
  unsigned __int8 (__thiscall *v24)(_SERVICE_STATUS *, unsigned int, int, GASValue *); // edx
  int v25; // ecx
  int v26; // [esp-14h] [ebp-58h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *listenersVal; // [esp+0h] [ebp-44h] BYREF
  const char *v30; // [esp+4h] [ebp-40h]
  int v31; // [esp+8h] [ebp-3Ch]
  GASValue methodVal[4]; // [esp+10h] [ebp-34h] BYREF
  int v33; // [esp+20h] [ebp-24h] BYREF
  int v34; // [esp+24h] [ebp-20h]
  char v35; // [esp+28h] [ebp-1Ch]
  unsigned int n; // [esp+2Ch] [ebp-18h]
  int v37; // [esp+30h] [ebp-14h]
  int v38; // [esp+34h] [ebp-10h] BYREF
  unsigned int i; // [esp+38h] [ebp-Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **v40; // [esp+3Ch] [ebp-8h]
  GStat::StatValue *charHolder; // [esp+40h] [ebp-4h]
  ISteamApps *eventNamea; // [esp+50h] [ebp+Ch]

  if ( eventName != nullptr )
  {
    v8 = penva + 120;
    p_listenersVal = &listenersVal;
    v26 = *(_DWORD *)(penva + 120) + 332;
    v10 = *(unsigned __int8 (__thiscall **)(_IMAGE_SYMBOL_EX *, unsigned int, int, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **, int, int, int))(eventName->N.Name.Short + 44);
    LOBYTE(listenersVal) = 0;
    if ( v10(a1: eventName, a2: penva + 120, a3: v26, a4: &listenersVal, a5: a2, a6: a3, a7: a1) != 0 )
    {
      v11 = GASValue::ToObject(this: &listenersVal, a2: (int)&listenersVal, a3: (const struct GASEnvironment *)penva);
      p_listenersVal = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)v11;
      v40 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)v11;
      if ( v11 != nullptr && ((int (__thiscall *)(struct GASObject *))v11[2].pNode[1].pNext)(a1: &v11[2]) == 7 )
      {
        v12 = (int)p_listenersVal[15] <= 0;
        p_listenersVal[2] = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)(((unsigned int)&p_listenersVal[2]->m_pMemory + 1) & 0x8FFFFFFF);
        if ( !v12 )
        {
          v13 = *(_DWORD *)(*(_DWORD *)v8 + 656);
          v14 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v13 + 40);
          v38 = 323;
          v15 = v14(a1: v13, a2: 76, a3: &v38);
          if ( v15 != 0 )
            eventNamea = (ISteamApps *)GASArrayObject::GASArrayObject(
                                         a1: v15,
                                         penv: penva,
                                         a3: (GMemoryHeap *)listenersVal,
                                         a4: v30,
                                         a5: v31);
          else
            eventNamea = nullptr;
          GASArrayObject::MakeDeepCopyFrom(
            this: eventNamea,
            pheap: *(_DWORD *)(*(_DWORD *)v8 + 656),
            a3: (int)p_listenersVal);
          v16 = (unsigned int)eventNamea[15].__vftable;
          v17 = 0;
          i = 0;
          for ( n = v16; v17 < n; i = v17 )
          {
            v18 = *((GASValue **)&eventNamea[14].BIsSubscribed + v17);
            if ( v18 != nullptr )
            {
              v19 = GASValue::ToObjectInterface(a1: (int)v18, a2: (int)p_listenersVal, result: (_SERVICE_STATUS *)penva);
              if ( v19 != nullptr )
              {
                v20 = *(_BYTE *)v18 == 7;
                v37 = 0;
                charHolder = nullptr;
                if ( v20 )
                {
                  GASValue::ToASCharacter(this: v18, penv: (const struct GASEnvironment *)penva);
                  if ( v21 != nullptr )
                    ++v21->pName;
                  v22 = v37;
                  charHolder = v21;
                }
                else
                {
                  v23 = GASValue::ToObject(this: v18, a2: (int)v19, a3: (const struct GASEnvironment *)penva);
                  if ( v23 != nullptr )
                    v23[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v23[1].pNode->pNext + 1) & 0x8FFFFFFF);
                  v22 = (int)v23;
                }
                v24 = *(unsigned __int8 (__thiscall **)(_SERVICE_STATUS *, unsigned int, int, GASValue *))(v19->dwServiceType + 44);
                LOBYTE(methodVal[0]) = 0;
                if ( v24(a1: v19, a2: penva + 120, a3: a6, a4: methodVal) != 0 )
                {
                  GASValue::ToFunction(a1: (int)methodVal, a2: (int)v19, a3: (int)&v33, a4: penva);
                  v25 = v33;
                  if ( v33 != 0 )
                  {
                    (*(void (__thiscall **)(int, unsigned int, _SERVICE_STATUS *, int *))(*(_DWORD *)a7 + 4))(
                      a1: a7,
                      a2: penva,
                      a3: v19,
                      a4: &v33);
                    v25 = v33;
                  }
                  if ( (v35 & 2) == 0 && v25 != 0 )
                    GRefCountBaseGC<323>::Release(a1: v25, a2: (int)v19);
                  v33 = 0;
                  if ( (v35 & 1) == 0 && v34 != 0 )
                    GRefCountBaseGC<323>::Release(a1: v34, a2: (int)v19);
                  v34 = 0;
                }
                GASValue::~GASValue(this: methodVal, a2: (int)v19);
                if ( charHolder != nullptr )
                  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)charHolder);
                if ( v22 != 0 )
                  GRefCountBaseGC<323>::Release(a1: v22, a2: (int)v19);
              }
              p_listenersVal = v40;
            }
            v17 = i + 1;
          }
          GRefCountBaseGC<323>::Release(a1: (int)eventNamea, a2: (int)p_listenersVal);
        }
        GRefCountBaseGC<323>::Release(a1: (int)p_listenersVal, a2: (int)p_listenersVal);
      }
    }
    GASValue::~GASValue(this: &listenersVal, a2: (int)p_listenersVal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117610
// Name: public: static void GASAsBroadcasterCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASAsBroadcasterCtorFunction::GlobalCtor(const struct GASFnCall *a1)
{
  int v1; // eax
  struct GASObject *v2; // esi
  GASValue *v3; // edi

  if ( *((_DWORD *)a1 + 2) != 0
    && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)a1 + 2) + 8))(a1: *((_DWORD *)a1 + 2)) == 36
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)a1 + 2) + 64))(a1: *((_DWORD *)a1 + 2)) == 0 )
  {
    v1 = *((_DWORD *)a1 + 2);
    if ( v1 != 0 )
    {
      v2 = (struct GASObject *)(v1 - 16);
      if ( v1 != 16 )
        v2[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v2[1].pNode->pNext + 1) & 0x8FFFFFFF);
    }
    else
    {
      v2 = nullptr;
    }
    GASValue::SetAsObject(this: *((GASValue **)a1 + 1), a2: v2);
    if ( v2 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v2, a2: (int)a1);
  }
  else
  {
    v3 = *((GASValue **)a1 + 1);
    GASValue::DropRefs(this: v3, a2: (int)v3);
    *(_BYTE *)v3 = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117710
// Name: public: static void GASAsBroadcasterProto::AddListener(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASAsBroadcasterProto::AddListener(int a1@<ebx>, int a2@<edi>, GASFnCall *a3)
{
  struct GASValue *v3; // eax
  _SERVICE_STATUS *v4; // eax
  GASFnCall v5; // esi
  _SERVICE_STATUS *v6; // [esp-4h] [ebp-8h]

  if ( (int)a3[7] >= 1 )
  {
    v6 = (_SERVICE_STATUS *)a3[6];
    v3 = GASFnCall::Arg(this: a3, a2: 0);
    v4 = GASValue::ToObjectInterface(a1: (int)v3, a2, result: v6);
    GASAsBroadcaster::AddListener(
      a1,
      a2,
      (int)a3,
      result: (_SERVICE_STATUS *)a3[6],
      plistener: (int *)a3[2],
      plistener_4: (struct GASObjectInterface *)v4);
    v5 = a3[1];
    GASValue::DropRefs(this: (GASValue *)v5, a2);
    LOBYTE(v5->cbSize) = 2;
    LOBYTE(v5->cItems) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117760
// Name: public: static void GASAsBroadcasterProto::RemoveListener(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASAsBroadcasterProto::RemoveListener(int a1@<ebx>, int a2@<edi>, GASFnCall *a3)
{
  struct GASValue *v3; // eax
  _SERVICE_STATUS *v4; // eax
  GASFnCall v5; // esi
  char v6; // al
  char v7; // bl
  _SERVICE_STATUS *v8; // [esp-8h] [ebp-Ch]

  if ( (int)a3[7] >= 1 )
  {
    v8 = (_SERVICE_STATUS *)a3[6];
    v3 = GASFnCall::Arg(this: a3, a2: 0);
    v4 = GASValue::ToObjectInterface(a1: (int)v3, a2, result: v8);
    GASAsBroadcaster::RemoveListener(
      a1,
      a2,
      (int)a3,
      result: (_SERVICE_STATUS *)a3[6],
      plistener: (int)a3[2],
      plistener_4: v4);
    v5 = a3[1];
    v7 = v6;
    GASValue::DropRefs(this: (GASValue *)v5, a2);
    LOBYTE(v5->cItems) = v7;
    LOBYTE(v5->cbSize) = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117820
// Name: public: static bool GASAsBroadcaster::Initialize(class GASStringContext __near *,class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
static char __cdecl GASAsBroadcaster::Initialize(tagMSG pobj)
{
  void *v1; // ecx

  if ( pobj.message != 0 )
    GASNameFunction::AddConstMembers(
      pobj: v1,
      psc: pobj.message,
      psca: (CTSQueue<CFunctor *,0,1>::Node_t *)pobj.hwnd,
      a4: (struct GASObject **)&GAS_AsBcFunctionTable,
      a5: 1);
  return GASAsBroadcaster::InitializeInstance(
           a1: (int)pobj.hwnd,
           a2: pobj.message,
           pobj: (GASGlobalContext **)pobj.hwnd,
           pobj_4: (struct GASObjectInterface *)pobj.message);
}

//------------------------------------------------------------------------------
// Address: 0x10117850
// Name: public: static bool GASAsBroadcaster::BroadcastMessage(class GASEnvironment __near *,class GASObjectInterface __near *,class GASString const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
static char __usercall GASAsBroadcaster::BroadcastMessage@<al>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        struct GASEnvironment *a4,
        _IMAGE_SYMBOL_EX *eventName,
        const struct GASString *a6,
        int nArgs,
        int firstArgBottomIndex)
{
  _DWORD v9[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( eventName == nullptr )
    return 0;
  v9[1] = nArgs;
  v9[2] = firstArgBottomIndex;
  v9[0] = &`GASAsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
  GASAsBroadcaster::BroadcastMessageWithCallback(a1, a2, a3, penva: (unsigned int)a4, eventName, (int)a6, a7: (int)v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101178A0
// Name: public: static void GASAsBroadcasterProto::BroadcastMessage(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASAsBroadcasterProto::BroadcastMessage(int a1@<ebx>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  _IMAGE_SYMBOL_EX *v5; // ecx
  _DWORD *v6; // eax
  int v7; // edi
  GASValue *v8; // esi
  GASFnCall *v9; // eax
  bool v10; // zf
  _DWORD v11[3]; // [esp+4h] [ebp-Ch] BYREF

  v2 = a2;
  if ( (int)a2[7] >= 1 )
  {
    v3 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
    v4 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
    GASValue::ToStringImpl(this: v4, (int *)&a2, a3: v3, precision: -1, debug: false);
    v5 = (_IMAGE_SYMBOL_EX *)v2[2];
    v6 = v2[6];
    if ( v5 != nullptr )
    {
      v7 = v6[7];
      v11[1] = (char *)v2[7] - 1;
      v3 = (tagRID_DEVICE_INFO_KEYBOARD *)(32 * v7);
      v11[2] = (char *)v3 + ((v6[2] - v6[3]) >> 4) - 36;
      v11[0] = &`GASAsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
      GASAsBroadcaster::BroadcastMessageWithCallback(
        a1,
        a2: (int)v3,
        a3: (int)v2,
        penva: (unsigned int)v6,
        eventName: v5,
        a6: (int)&a2,
        a7: (int)v11);
    }
    v8 = (GASValue *)v2[1];
    GASValue::DropRefs(this: v8, a2: (int)v3);
    *(_BYTE *)v8 = 0;
    v9 = a2;
    v10 = a2[2] == (GASFnCall)1;
    a2[2] = (GASFnCall)((char *)a2[2] - 1);
    if ( v10 )
      GASStringNode::ReleaseNode(a1: (int)v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117930
// Name: private: static void GASAsBroadcasterCtorFunction::Initialize(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASAsBroadcasterCtorFunction::Initialize(int a1@<edi>, GASFnCall *a2)
{
  struct GASValue *v2; // eax
  _SERVICE_STATUS *v3; // eax
  GASValue *v4; // ebx
  struct GASObjectInterface *v5; // edi
  void *v6; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v7; // esi
  _SERVICE_STATUS *v8; // [esp-Ch] [ebp-10h]

  if ( (int)a2[7] >= 1 )
  {
    v8 = (_SERVICE_STATUS *)a2[6];
    v2 = GASFnCall::Arg(this: a2, a2: 0);
    v3 = GASValue::ToObjectInterface(a1: (int)v2, a2: a1, result: v8);
    v4 = (GASValue *)a2[1];
    v5 = (struct GASObjectInterface *)v3;
    GASValue::DropRefs(this: v4, a2: (int)v3);
    *(_BYTE *)v4 = 0;
    v7 = (CTSQueue<CFunctor *,0,1>::Node_t *)&a2[6][3];
    if ( v5 != nullptr )
      GASNameFunction::AddConstMembers(
        pobj: v6,
        psc: (int)v5,
        psca: v7,
        a4: (struct GASObject **)&GAS_AsBcFunctionTable,
        a5: 1);
    GASAsBroadcaster::InitializeInstance(a1: (int)v5, a2: (int)v7, pobj: (GASGlobalContext **)v7, pobj_4: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117990
// Name: public: static class GASFunctionRef GASAsBroadcasterCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASAsBroadcasterCtorFunction::Register(struct GASFunctionRef *a1, int a2)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  void *v7; // ecx
  GASCFunctionObject *v8; // eax
  struct GASFunctionRef *v9; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, struct GASFunctionRef **); // eax
  int v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v14; // eax
  int v15; // edi
  GASValue v17[4]; // [esp+Ch] [ebp-20h] BYREF
  CTSQueue<CFunctor *,0,1>::Node_t psc; // [esp+1Ch] [ebp-10h] BYREF
  void (__thiscall **v19)(_DWORD *, CTSQueue<CFunctor *,0,1>::Node_t *, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v20; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)a2;
  v3 = *(CTSQueue<CFunctor *,0,1>::Node_t **)(a2 + 656);
  psc.pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)a2;
  LOBYTE(psc.elem) = 8;
  pNext = v3->pNext[5].pNext;
  a2 = 323;
  v5 = (GASCFunctionObject *)((int (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t *, int, int *))pNext)(
                               a1: v3,
                               a2: 56,
                               a3: &a2);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASAsBroadcasterCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASAsBroadcasterCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    GASNameFunction::AddConstMembers(
      pobj: v7,
      psc: (int)&v6->cLineHeight,
      psca: &psc,
      a4: (struct GASObject **)GASAsBroadcasterCtorFunction::StaticFunctionTable,
      a5: 7);
    v8 = v6;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = a1;
  *(_DWORD *)a1 = v8;
  *((_BYTE *)v9 + 8) = 0;
  *((_DWORD *)v9 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a1 = (struct GASFunctionRef *)323;
  v12 = v11(a1: MaxVal, a2: 84, a3: &a1);
  if ( v12 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASAsBroadcaster,GASEnvironment>::GASPrototype<GASAsBroadcaster,GASEnvironment>(
      pthis: (CMaterialVar *)v12,
      &psc,
      a3: Prototype,
      a4: (unsigned int)v9);
    *(_DWORD *)v12 = &GASAsBroadcasterProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v12 + 16) = &GASPrototype<GASAsBroadcaster,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v12 + 52) = &GASPrototype<GASAsBroadcaster,GASEnvironment>::`vftable';
    HIBYTE(a2) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v12 + 52),
      a2: v12,
      flags: (vc_attributes::PreRangeAttribute **)&psc,
      flags_4: (const struct GASNameFunction *)&GAS_AsBcFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&a2 + 3));
  }
  else
  {
    v12 = 0;
  }
  if ( v12 != 0 )
    *(_DWORD *)(v12 + 8) = (*(_DWORD *)(v12 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 19, a4: v12);
  v20 = v2[56].MaxVal + 16;
  HIBYTE(a2) = 0;
  v19 = (void (__thiscall **)(_DWORD *, CTSQueue<CFunctor *,0,1>::Node_t *, int, GASValue *, char *))(*v20 + 40);
  v14 = GASValue::GASValue(this: v17, a2: (int)v2, a3: v9);
  v15 = (int)&v2[7];
  (*v19)(a1: v20, a2: &psc, a3: v15, a4: v14, a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v17, a2: v15);
  if ( v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2: v15);
  return v9;
}
