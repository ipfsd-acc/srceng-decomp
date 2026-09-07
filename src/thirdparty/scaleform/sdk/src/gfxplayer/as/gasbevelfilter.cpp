// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasbevelfilter.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasbevelfilter.h"

//------------------------------------------------------------------------------
// Address: 0x101327E0
// Name: public: virtual enum GASObjectInterface::ObjectType GASBevelFilterObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASBevelFilterObject::GetObjectType(GFxAmpServer::SwdInfo *this)
{
  return 41;
}

//------------------------------------------------------------------------------
// Address: 0x10132870
// Name: public: virtual bool GASBevelFilterObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASBevelFilterObject::GetMember(
        D3DXQUATERNION *this,
        float result,
        const char ***name,
        GASValue *a4)
{
  const char ***v4; // ebx
  GASValue *v6; // esi
  unsigned int v7; // edx
  int v8; // edi
  double v10; // st7
  GASValue *v11; // esi
  double v12; // st7
  unsigned __int8 v13; // al
  double v14; // st7
  unsigned __int8 v15; // al
  GASValue *v16; // esi
  bool v17; // bl
  GASStringManager *v18; // ecx
  float v19; // eax
  int v20; // esi

  v4 = name;
  if ( strcmp(**name, (const char *)&stru_102A7C68.m_Size) != 0 )
  {
    if ( strcmp(**name, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
    {
      v10 = *((float *)this + 12);
    }
    else
    {
      if ( strcmp(**name, (const char *)&stru_1029E0D4) != 0 )
      {
        if ( GASString::operator==(this: name, a2: (const char *)&stru_102A6D0C) )
        {
          GASValue::SetInt(this: (int)a4, result: (tagCOMPAREITEMSTRUCT *)(*((__int16 *)this + 20) / 20));
          return 1;
        }
        if ( GASString::operator==(this: v4, a2: (const char *)&stru_102A8124.m_pElements) )
        {
          v13 = *((_BYTE *)this + 71);
          if ( v13 != 0 )
          {
            LODWORD(result) = v13;
            v14 = (double)v13 / 255.0;
          }
          else
          {
            v14 = 0.0;
          }
        }
        else
        {
          if ( GASString::operator==(this: v4, a2: (const char *)&stru_102A8124) )
          {
            GASValue::SetInt(this: (int)a4, result: (tagCOMPAREITEMSTRUCT *)(*((_DWORD *)this + 17) & 0xFFFFFF));
            return 1;
          }
          if ( !GASString::operator==(this: v4, a2: (const char *)&stru_1029E08C) )
          {
            if ( GASString::operator==(this: v4, a2: (const char *)&stru_1029E260) )
            {
              GASValue::SetInt(this: (int)a4, result: (tagCOMPAREITEMSTRUCT *)(*((_DWORD *)this + 18) & 0xFFFFFF));
              return 1;
            }
            if ( GASString::operator==(this: v4, a2: (const char *)&stru_102A7C54) )
            {
              v16 = a4;
              v17 = (*((_BYTE *)this + 36) & 0x20) != 0;
              GASValue::DropRefs(this: a4, a2: (int)this);
              *((_BYTE *)v16 + 4) = v17;
              *(_BYTE *)v16 = 2;
              return 1;
            }
            if ( GASString::operator==(this: v4, a2: (const char *)&stru_102A7C40.m_Size) )
            {
              GASValue::SetInt(this: (int)a4, result: *((tagCOMPAREITEMSTRUCT **)this + 14));
              return 1;
            }
            if ( !GASString::operator==(this: v4, a2: (const char *)&stru_1029E2B4) )
            {
              if ( !GASString::operator==(this: v4, a2: (const char *)&stru_102A7C40) )
                return (unsigned __int8)GASObject::GetMember(
                                          this,
                                          result: (ID3DXFont *)LODWORD(result),
                                          penv: (_IMAGE_SYMBOL_EX *)v4,
                                          val: (int *)a4);
              GASValue::SetNumber(this: a4, a2: *((float *)this + 19));
              return 1;
            }
            v18 = *(GASStringManager **)(*(_DWORD *)(LODWORD(result) + 120) + 636);
            if ( (*((_DWORD *)this + 11) & 0x200) != 0 )
              GASStringManager::CreateStringNode(
                this: v18,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C54.m_Size);
            else
              GASStringManager::CreateStringNode(
                this: v18,
                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"outer");
            v20 = LODWORD(v19);
            ++*(_DWORD *)(LODWORD(v19) + 8);
            result = v19;
            GASValue::SetString(this: a4, str: (_IMAGE_SYMBOL_EX *)&result);
            if ( (*(_DWORD *)(v20 + 8))-- == 1 )
            {
              GASStringNode::ReleaseNode(a1: v20);
              return 1;
            }
            return 1;
          }
          v15 = *((_BYTE *)this + 75);
          if ( v15 != 0 )
          {
            LODWORD(result) = v15;
            v14 = (double)v15 / 255.0;
          }
          else
          {
            v14 = 0.0;
          }
        }
        result = v14;
        GASValue::SetNumber(this: a4, a2: result);
        return 1;
      }
      v10 = *((float *)this + 13);
    }
    v11 = a4;
    result = v10;
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: (int)this);
    v12 = result;
    *(_BYTE *)v11 = 3;
    *(double *)(v11 + 1) = v12;
    return 1;
  }
  v6 = a4;
  v7 = (int)((unsigned __int64)(1717986919LL * *((__int16 *)this + 19)) >> 32) >> 2;
  v8 = (__int16)(v7 + (v7 >> 31));
  if ( *(_BYTE *)a4 >= 5u )
    GASValue::DropRefs(this: a4, a2: v8);
  *((_DWORD *)v6 + 1) = v8;
  *(_BYTE *)v6 = 4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10132B90
// Name: public: virtual class GASObject __near * GASBevelFilterCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASBitmapFilterObject *__thiscall GASBevelFilterCtorFunction::CreateNewObject(GASBevelFilterCtorFunction *this, int a2)
{
  struct GASEnvironment *v2; // edi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GASBitmapFilterObject *v5; // eax
  GASBitmapFilterObject *v6; // esi

  v2 = (struct GASEnvironment *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASBitmapFilterObject *)v4(a1: v3, a2: 208, a3: &a2);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  GASBitmapFilterObject::GASBitmapFilterObject(
    this: v5,
    a2: v2,
    a3: FILTERSPECV6_FLOW,
    blurMode: (struct GFxSocketImplFactory *)6);
  *v6 = (GASBitmapFilterObject)&GASBevelFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v6[4] = (GASBitmapFilterObject)&GASBevelFilterObject::`vftable'{for `GASObjectInterface'};
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10132BF0
// Name: public: virtual bool GASBevelFilterObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASBevelFilterObject::SetMember(
        CTSQueue<CFunctor *,0,1> *this@<ecx>,
        long double a2@<st0>,
        tagPOLYTEXTW *result,
        const char ***a4,
        GASValue *a5,
        const struct GASPropFlags *a6)
{
  const char *v6; // edi
  __int16 v8; // ax
  double v9; // st7
  __int16 v10; // dx
  int v11; // eax
  char v12; // cl
  int v13; // eax
  char v14; // cl
  GASValue *v15; // eax
  double v17; // [esp+Ch] [ebp-10h]
  double v18; // [esp+Ch] [ebp-10h]
  float v19; // [esp+14h] [ebp-8h]
  float v20; // [esp+18h] [ebp-4h]
  tagPOLYTEXTW *v21; // [esp+24h] [ebp+8h]
  float v22; // [esp+24h] [ebp+8h]
  float v23; // [esp+24h] [ebp+8h]

  v6 = **a4;
  if ( strcmp(v6, (const char *)&stru_102A7C68.m_Size) == 0 )
  {
    v8 = GASValue::ToInt32(this: a5, a2: (int)v6, a3: a2, a4: (_SERVICE_STATUS *)result);
    a5 = (GASValue *)(__int16)(10 * v8);
    *((_WORD *)this + 19) = 10 * v8;
    v21 = (tagPOLYTEXTW *)*((__int16 *)this + 20);
    *(float *)&a5 = (double)(int)a5 * 3.141592741012573 / 1800.0;
    v17 = (double)(int)v21;
    v22 = cos(*(float *)&a5);
    v19 = v22 * v17 * 0.05000000074505806;
    *(float *)&a5 = sin(*(float *)&a5);
    v9 = *(float *)&a5 * v17;
LABEL_3:
    v20 = v9 * 0.05000000074505806;
    *((float *)this + 15) = v19;
    *((float *)this + 16) = v20;
    return;
  }
  if ( strcmp(**a4, (const char *)&stru_1029E0D4.m_Memory.m_nGrowSize) == 0 )
  {
    *((float *)this + 12) = GASValue::ToNumber(this: a5, a2: (int)v6, a3: a2, (_SERVICE_STATUS *)result);
    return;
  }
  if ( strcmp(**a4, (const char *)&stru_1029E0D4) == 0 )
  {
    *((float *)this + 13) = GASValue::ToNumber(this: a5, a2: (int)v6, a3: a2, (_SERVICE_STATUS *)result);
    return;
  }
  if ( GASString::operator==(this: a4, a2: (const char *)&stru_102A6D0C) )
  {
    v10 = 20 * GASValue::ToInt32(this: a5, a2: (int)v6, a3: a2, a4: (_SERVICE_STATUS *)result);
    *((_WORD *)this + 20) = v10;
    *(float *)&a5 = (double)*((__int16 *)this + 19) * 3.141592741012573 / 1800.0;
    v18 = (double)v10;
    v23 = cos(*(float *)&a5);
    v19 = v23 * v18 * 0.05000000074505806;
    *(float *)&a5 = sin(*(float *)&a5);
    v9 = *(float *)&a5 * v18;
    goto LABEL_3;
  }
  if ( GASString::operator==(this: a4, a2: (const char *)&stru_102A8124.m_pElements) )
  {
    *(float *)&a5 = GASValue::ToNumber(this: a5, a2: (int)v6, a3: a2, (_SERVICE_STATUS *)result);
    *((_BYTE *)this + 71) = (int)(*(float *)&a5 * 255.0);
  }
  else if ( GASString::operator==(this: a4, a2: (const char *)&stru_102A8124) )
  {
    v11 = GASValue::ToUInt32(this: a5, a2: (int)v6, a3: a2, a4: (_SERVICE_STATUS *)result);
    v12 = *((_BYTE *)this + 71);
    *((_DWORD *)this + 17) = v11;
    *((_BYTE *)this + 71) = v12;
  }
  else if ( GASString::operator==(this: a4, a2: (const char *)&stru_1029E08C) )
  {
    *(float *)&a5 = GASValue::ToNumber(this: a5, a2: (int)v6, a3: a2, (_SERVICE_STATUS *)result);
    *((_BYTE *)this + 75) = (int)(*(float *)&a5 * 255.0);
  }
  else if ( GASString::operator==(this: a4, a2: (const char *)&stru_1029E260) )
  {
    v13 = GASValue::ToUInt32(this: a5, a2: (int)v6, a3: a2, a4: (_SERVICE_STATUS *)result);
    v14 = *((_BYTE *)this + 75);
    *((_DWORD *)this + 18) = v13;
    *((_BYTE *)this + 75) = v14;
  }
  else if ( GASString::operator==(this: a4, a2: (const char *)&stru_102A7C54) )
  {
    if ( GASValue::ToBool(a1: (char *)a5, a2, result) != 0 )
    {
      *((_BYTE *)this + 36) |= 0x20u;
      *((_DWORD *)this + 11) |= 0x100u;
    }
    else
    {
      *((_BYTE *)this + 36) &= ~0x20u;
      *((_DWORD *)this + 11) &= ~0x100u;
    }
  }
  else if ( GASString::operator==(this: a4, a2: (const char *)&stru_102A7C40.m_Size) )
  {
    *((_DWORD *)this + 14) = (__int64)GASValue::ToNumber(this: a5, a2: (int)v6, a3: a2, (_SERVICE_STATUS *)result);
  }
  else if ( GASString::operator==(this: a4, a2: (const char *)&stru_1029E2B4) )
  {
    GASValue::ToStringImpl(
      this: (unsigned __int8 *)a5,
      a2: (int *)&a5,
      a3: (tagRID_DEVICE_INFO_KEYBOARD *)result,
      precision: -1,
      debug: false);
    if ( GASString::operator==(this: (const char ***)&a5, a2: (const char *)&stru_102A7C54.m_Size) )
      *((_DWORD *)this + 11) |= 0x200u;
    else
      *((_DWORD *)this + 11) &= ~0x200u;
    v15 = a5;
    if ( (*((_DWORD *)a5 + 2))-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)v15);
  }
  else if ( GASString::operator==(this: a4, a2: (const char *)&stru_102A7C40) )
  {
    *((float *)this + 19) = GASValue::ToNumber(this: a5, a2: (int)v6, a3: a2, (_SERVICE_STATUS *)result);
  }
  else
  {
    GASObject::SetMember(
      this,
      a2: (GASEnvironment *)result,
      name: (_IMAGE_SYMBOL_EX *)a4,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)a5,
      pmember: (char *)a6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133200
// Name: protected: GASBevelFilterObject::GASBevelFilterObject(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASBevelFilterObject::GASBevelFilterObject(
        GFxAmpServer::SwdInfo *this@<ecx>,
        int a2@<edi>,
        GASGlobalContext **psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4)
{
  GASObject::GASObject((GASObject *)this, a2, psc);
  this->__vftable = (GFxAmpServer::SwdInfo_vtbl *)&GASBitmapFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBitmapFilterObject::`vftable'{for `GASObjectInterface'};
  *((float *)this + 16) = 5.0;
  *((float *)this + 17) = 5.0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 18) = 1;
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 23) = 1.0;
  GRenderer::Cxform::Cxform(this: (float *)this + 24);
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 1), (CTSQueue<CFunctor *,0,1>::Node_t *)psc, psc_4);
  this->__vftable = (GFxAmpServer::SwdInfo_vtbl *)&GASBevelFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBevelFilterObject::`vftable'{for `GASObjectInterface'};
}

//------------------------------------------------------------------------------
// Address: 0x10133270
// Name: public: static void GASBevelFilterProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASBevelFilterProto::Clone(GASFnCall *a1)
{
  GASFnCall v1; // ebx
  int *p_cxItem; // ebx
  struct GASObject *v3; // esi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x29u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = &v1[-1].cxItem;
      if ( p_cxItem != nullptr )
      {
        v3 = GASEnvironment::OperatorNew(
               this: (__vc_attributes::idl_quoteAttribute *)a1[6],
               a2: (int)a1,
               a3: *(struct GASObject **)(a1[6][3].cbSize + 676),
               a4: (const struct GASString *)(a1[6][3].cbSize + 172),
               nargs: 0,
               argsTopOff: -1);
        GFxFilterDesc::operator=(this: &v3[6].sequence, a2: (int)(p_cxItem + 13));
        GASValue::SetAsObject(this: (GASValue *)a1[1], a2: v3);
        if ( v3 != nullptr )
          GRefCountBaseGC<323>::Release(a1: (int)v3, a2: (int)a1);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "BevelFilter", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101332F0
// Name: public: static void GASBevelFilterCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASBevelFilterCtorFunction::GlobalCtor(int fn)
{
  const struct GASFnCall *v1; // edi
  int v2; // eax
  int v3; // esi
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // eax
  GASBitmapFilterObject *v6; // eax
  double v7; // st7
  GASValue *v8; // eax
  __int16 v9; // ax
  long double v10; // st7
  GASValue *v11; // eax
  __int16 v12; // ax
  long double v13; // st7
  GASValue *v14; // eax
  int v15; // eax
  long double v16; // st7
  char v17; // cl
  GASValue *v18; // eax
  long double v19; // st7
  GASValue *v20; // eax
  int v21; // eax
  long double v22; // st7
  char v23; // cl
  GASValue *v24; // eax
  long double v25; // st7
  GASValue *v26; // eax
  double v27; // st7
  GASValue *v28; // eax
  double v29; // st7
  GASValue *v30; // eax
  double v31; // st7
  GASValue *v32; // eax
  double v33; // st7
  tagRID_DEVICE_INFO_KEYBOARD *v34; // ebx
  unsigned __int8 *v35; // eax
  char *v36; // eax
  const struct GASFnCall *v37; // eax
  bool v38; // zf
  int v39; // edi
  int v40; // eax
  int *v41; // edi
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // eax
  _SERVICE_STATUS *v63; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v64; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v65; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v66; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v67; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v68; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v69; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v70; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v71; // [esp-4h] [ebp-28h]
  _SERVICE_STATUS *v72; // [esp-4h] [ebp-28h]
  tagPOLYTEXTW *v73; // [esp-4h] [ebp-28h]
  GASValue v74[2]; // [esp+8h] [ebp-1Ch] BYREF
  double v75; // [esp+10h] [ebp-14h]
  int v76; // [esp+18h] [ebp-Ch] BYREF
  float v77; // [esp+1Ch] [ebp-8h]
  float v78; // [esp+20h] [ebp-4h] BYREF

  v1 = (const struct GASFnCall *)fn;
  if ( *(_DWORD *)(fn + 8) == 0
    || (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fn + 8) + 8))(a1: *(_DWORD *)(fn + 8)) != 41 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 6) + 120) + 656);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    v76 = 323;
    v6 = (GASBitmapFilterObject *)v5(a1: v4, a2: 208, a3: &v76);
    v3 = (int)v6;
    if ( v6 != nullptr )
    {
      GASBitmapFilterObject::GASBitmapFilterObject(
        this: v6,
        a2: *((struct GASEnvironment **)v1 + 6),
        a3: FILTERSPECV6_FLOW,
        blurMode: (struct GFxSocketImplFactory *)6);
      *(_DWORD *)v3 = &GASBevelFilterObject::`vftable'{for `GASRefCountBase<GASObject>'};
      *(_DWORD *)(v3 + 16) = &GASBevelFilterObject::`vftable'{for `GASObjectInterface'};
      goto LABEL_9;
    }
LABEL_8:
    v3 = 0;
    goto LABEL_9;
  }
  v2 = *((_DWORD *)v1 + 2);
  if ( v2 == 0 )
    goto LABEL_8;
  v3 = v2 - 16;
  if ( v2 != 16 )
    *(_DWORD *)(v3 + 8) = (*(_DWORD *)(v3 + 8) + 1) & 0x8FFFFFFF;
LABEL_9:
  GASValue::SetAsObject(this: *((GASValue **)v1 + 1), a2: (struct GASObject *)v3);
  *(_WORD *)(v3 + 56) = 80;
  *(_DWORD *)(v3 + 72) = 1;
  *(float *)&fn = (double)*(__int16 *)(v3 + 54) * 3.141592741012573 / 1800.0;
  v75 = (double)80;
  v78 = cos(*(float *)&fn);
  v77 = v78 * v75 * 0.05000000074505806;
  *(float *)&fn = sin(*(float *)&fn);
  v7 = *(float *)&fn * v75;
  fn = 450;
  v78 = v7 * 0.05000000074505806;
  *(float *)(v3 + 76) = v77;
  *(float *)(v3 + 80) = v78;
  *(_WORD *)(v3 + 54) = 450;
  LODWORD(v78) = *(__int16 *)(v3 + 56);
  *(float *)&fn = (double)fn * 3.141592741012573 / 1800.0;
  v75 = (double)SLODWORD(v78);
  v78 = cos(*(float *)&fn);
  v77 = v78 * v75 * 0.05000000074505806;
  *(float *)&fn = sin(*(float *)&fn);
  v78 = *(float *)&fn * v75 * 0.05000000074505806;
  *(float *)(v3 + 76) = v77;
  *(float *)(v3 + 80) = v78;
  *(_DWORD *)(v3 + 84) = 0;
  *(_BYTE *)(v3 + 87) = -1;
  *(_DWORD *)(v3 + 88) = 0xFFFFFF;
  *(float *)(v3 + 64) = 4.0;
  *(_BYTE *)(v3 + 52) &= 0x9Fu;
  *(float *)(v3 + 68) = 4.0;
  *(_DWORD *)(v3 + 60) &= 0xFFFFFAFF;
  *(float *)(v3 + 92) = 1.0;
  *(_BYTE *)(v3 + 91) = -1;
  if ( *((int *)v1 + 7) > 0 )
  {
    v63 = *((_SERVICE_STATUS **)v1 + 6);
    v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 0);
    v9 = 20 * GASValue::ToInt32(this: v8, a2: (int)v1, a3: 1.0, a4: v63);
    *(_WORD *)(v3 + 56) = v9;
    *(float *)&fn = (double)*(__int16 *)(v3 + 54) * 3.141592741012573 / 1800.0;
    v75 = (double)v9;
    v78 = cos(*(float *)&fn);
    v77 = v78 * v75 * 0.05000000074505806;
    *(float *)&fn = sin(*(float *)&fn);
    v78 = *(float *)&fn * v75 * 0.05000000074505806;
    *(float *)(v3 + 76) = v77;
    v10 = v78;
    *(float *)(v3 + 80) = v78;
    if ( *((int *)v1 + 7) > 1 )
    {
      v64 = *((_SERVICE_STATUS **)v1 + 6);
      v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 1);
      v12 = GASValue::ToInt32(this: v11, a2: (int)v1, a3: v10, a4: v64);
      fn = (__int16)(10 * v12);
      *(_WORD *)(v3 + 54) = 10 * v12;
      LODWORD(v78) = *(__int16 *)(v3 + 56);
      *(float *)&fn = (double)fn * 3.141592741012573 / 1800.0;
      v75 = (double)SLODWORD(v78);
      v78 = cos(*(float *)&fn);
      v77 = v78 * v75 * 0.05000000074505806;
      *(float *)&fn = sin(*(float *)&fn);
      v78 = *(float *)&fn * v75 * 0.05000000074505806;
      *(float *)(v3 + 76) = v77;
      v13 = v78;
      *(float *)(v3 + 80) = v78;
      if ( *((int *)v1 + 7) > 2 )
      {
        v65 = *((_SERVICE_STATUS **)v1 + 6);
        v14 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 2);
        v15 = GASValue::ToUInt32(this: v14, a2: (int)v1, a3: v13, a4: v65);
        v17 = *(_BYTE *)(v3 + 87);
        *(_DWORD *)(v3 + 84) = v15;
        *(_BYTE *)(v3 + 87) = v17;
        if ( *((int *)v1 + 7) > 3 )
        {
          v66 = *((_SERVICE_STATUS **)v1 + 6);
          v18 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 3);
          *(float *)&fn = GASValue::ToNumber(this: v18, a2: (int)v1, a3: v16, result: v66);
          v19 = *(float *)&fn * 255.0;
          LODWORD(v78) = (int)v19;
          *(_BYTE *)(v3 + 87) = (int)v19;
          if ( *((int *)v1 + 7) > 4 )
          {
            v67 = *((_SERVICE_STATUS **)v1 + 6);
            v20 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 4);
            v21 = GASValue::ToUInt32(this: v20, a2: (int)v1, a3: v19, a4: v67);
            v23 = *(_BYTE *)(v3 + 91);
            *(_DWORD *)(v3 + 88) = v21;
            *(_BYTE *)(v3 + 91) = v23;
            if ( *((int *)v1 + 7) > 5 )
            {
              v68 = *((_SERVICE_STATUS **)v1 + 6);
              v24 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 5);
              *(float *)&fn = GASValue::ToNumber(this: v24, a2: (int)v1, a3: v22, result: v68);
              v25 = *(float *)&fn * 255.0;
              LODWORD(v78) = (int)v25;
              *(_BYTE *)(v3 + 91) = (int)v25;
              if ( *((int *)v1 + 7) > 6 )
              {
                v69 = *((_SERVICE_STATUS **)v1 + 6);
                v26 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 6);
                v27 = GASValue::ToNumber(this: v26, a2: (int)v1, a3: v25, result: v69);
                *(float *)(v3 + 64) = v27;
                if ( *((int *)v1 + 7) > 7 )
                {
                  v70 = *((_SERVICE_STATUS **)v1 + 6);
                  v28 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 7);
                  v29 = GASValue::ToNumber(this: v28, a2: (int)v1, a3: v27, result: v70);
                  *(float *)(v3 + 68) = v29;
                  if ( *((int *)v1 + 7) > 8 )
                  {
                    v71 = *((_SERVICE_STATUS **)v1 + 6);
                    v30 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 8);
                    v31 = GASValue::ToNumber(this: v30, a2: (int)v1, a3: v29, result: v71);
                    *(float *)(v3 + 92) = v31;
                    if ( *((int *)v1 + 7) > 9 )
                    {
                      v72 = *((_SERVICE_STATUS **)v1 + 6);
                      v32 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 9);
                      v33 = GASValue::ToNumber(this: v32, a2: (int)v1, a3: v31, result: v72);
                      LODWORD(v78) = HIWORD(fn) | 0xC00;
                      *(_QWORD *)&v75 = (__int64)v33;
                      *(_DWORD *)(v3 + 72) = (__int64)v33;
                      if ( *((int *)v1 + 7) > 10 )
                      {
                        v34 = *((tagRID_DEVICE_INFO_KEYBOARD **)v1 + 6);
                        v35 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 10);
                        GASValue::ToStringImpl(this: v35, a2: &fn, a3: v34, precision: -1, debug: false);
                        if ( GASString::operator==(this: (const char ***)&fn, a2: (const char *)&stru_102A7C54.m_Size) )
                          *(_DWORD *)(v3 + 60) |= 0x200u;
                        else
                          *(_DWORD *)(v3 + 60) &= ~0x200u;
                        if ( *((int *)v1 + 7) > 11 )
                        {
                          v73 = *((tagPOLYTEXTW **)v1 + 6);
                          v36 = (char *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 11);
                          if ( GASValue::ToBool(a1: v36, a2: v33, result: v73) != 0 )
                          {
                            *(_BYTE *)(v3 + 52) |= 0x20u;
                            *(_DWORD *)(v3 + 60) |= 0x100u;
                          }
                          else
                          {
                            *(_BYTE *)(v3 + 52) &= ~0x20u;
                            *(_DWORD *)(v3 + 60) &= ~0x100u;
                          }
                        }
                        v37 = (const struct GASFnCall *)fn;
                        v38 = (*(_DWORD *)(fn + 8))-- == 1;
                        if ( v38 )
                          GASStringNode::ReleaseNode(a1: (int)v37);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v39 = *((_DWORD *)v1 + 6);
  v40 = *(_DWORD *)(v39 + 120);
  v41 = (int *)(v39 + 120);
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v40 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E260,
            a3: 0xBu,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v42 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v42);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v43 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v43 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E08C,
            a3: 0xBu,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v44 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v44);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v45 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v45 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A8124,
            a3: 0xEu,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v46 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v46);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v47 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v47 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A8124.m_pElements,
            a3: 0xEu,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v48 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v48);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v49 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v49 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4.m_Memory.m_nGrowSize,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v50 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v50);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v51 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v51 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E0D4,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v52 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v52);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v53 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v53 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C40,
            a3: 8u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v54 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v54);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v55 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v55 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C54,
            a3: 8u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v56 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v56);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v57 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v57 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C54.m_Size,
            a3: 5u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v58 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v58);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v59 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v59 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E2B4,
            a3: 4u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *, char *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74,
    a5: (char *)&fn + 3);
  v60 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v60);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  v61 = *v41;
  LOBYTE(v74[0]) = 10;
  HIBYTE(fn) = 0;
  v78 = COERCE_FLOAT(
          GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v61 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7C40.m_Size,
            a3: 7u,
            a4: 0));
  ++*(_DWORD *)(LODWORD(v78) + 8);
  (*(void (__thiscall **)(int, int *, float *, GASValue *))(*(_DWORD *)(v3 + 16) + 40))(
    a1: v3 + 16,
    a2: v41,
    a3: &v78,
    a4: v74);
  v62 = LODWORD(v78);
  v38 = (*(_DWORD *)(LODWORD(v78) + 8))-- == 1;
  if ( v38 )
    GASStringNode::ReleaseNode(a1: v62);
  GASValue::~GASValue(this: v74, a2: (int)v41);
  GRefCountBaseGC<323>::Release(a1: v3, a2: (int)v41);
}

//------------------------------------------------------------------------------
// Address: 0x10133B60
// Name: public: GASBevelFilterProto::GASBevelFilterProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASBevelFilterProto *__thiscall GASBevelFilterProto::GASBevelFilterProto(
        GASBevelFilterProto *this,
        __int64 psc,
        const struct GASFunctionRef *psc_8)
{
  const struct GASFunctionRef *v4; // edx
  __int128 v6; // [esp-8h] [ebp-14h]

  GASBevelFilterObject::GASBevelFilterObject(
    (GFxAmpServer::SwdInfo *)this,
    a2: (int)this,
    (GASGlobalContext **)psc,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)HIDWORD(psc));
  v4 = psc_8;
  *((_DWORD *)this + 52) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 220) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_BYTE *)this + 232) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_DWORD *)this + 57) = 0;
  *((_DWORD *)this + 59) = 0;
  *(_QWORD *)&v6 = __PAIR64__((unsigned int)v4, psc);
  *(_DWORD *)this = &GASBevelFilterProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASBevelFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 52) = &GASPrototype<GASBevelFilterObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)((char *)this + 208),
    a2: (int)this,
    pthis: (CMaterialVar *)this,
    psc: v6);
  *(_DWORD *)this = &GASBevelFilterProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASBevelFilterObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 52) = &GASPrototype<GASBevelFilterObject,GASEnvironment>::`vftable';
  HIBYTE(psc) = 0;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 52,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)GASBevelFilterProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc + 7));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10133CA0
// Name: public: static class GASFunctionRef GASBevelFilterCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASBevelFilterCtorFunction::Register(
        int a1@<edi>,
        struct GASFunctionRef *a2,
        _KCRM_MARSHAL_HEADER *pgca)
{
  vc_attributes::PreRangeAttribute *v4; // esi
  int v5; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v7)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASCFunctionObject *v8; // edi
  GASCFunctionObject *v9; // eax
  const char *v11; // ecx
  int (__thiscall *v12)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASBevelFilterProto *v13; // ebx
  GASBevelFilterProto *v14; // ebx
  const char *MinVal; // edx
  GASValue *v16; // eax
  __int64 v17; // [esp-Ch] [ebp-30h]
  unsigned int Unused; // [esp-4h] [ebp-28h]
  GASValue v19; // [esp+Ch] [ebp-18h] BYREF
  int v20; // [esp+10h] [ebp-14h] BYREF
  int v21; // [esp+14h] [ebp-10h]
  char v22; // [esp+18h] [ebp-Ch]
  vc_attributes::PreRangeAttribute *v23; // [esp+1Ch] [ebp-8h] BYREF
  char v24; // [esp+20h] [ebp-4h]
  struct GASFunctionRef *v25; // [esp+2Ch] [ebp+8h]

  v4 = (vc_attributes::PreRangeAttribute *)pgca;
  Unused = pgca[9].Unused;
  ++*(_DWORD *)(Unused + 8);
  GASGlobalContext::GetBuiltinClassRegistrar(this: v4, a2: Unused);
  if ( v5 == 0 )
  {
    GASBitmapFilterCtorFunction::Register(a1: (struct GASFunctionRef *)&v20, pgc: (_KCRM_MARSHAL_HEADER *)v4);
    if ( (v22 & 2) == 0 && v20 != 0 )
      GRefCountBaseGC<323>::Release(a1: v20, a2: a1);
    v20 = 0;
    if ( (v22 & 1) == 0 && v21 != 0 )
      GRefCountBaseGC<323>::Release(a1: v21, a2: a1);
  }
  MaxVal = v4[54].MaxVal;
  v23 = v4;
  v24 = 8;
  v7 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v8 = (GASCFunctionObject *)v7(a1: MaxVal, a2: 56, a3: &pgca);
  if ( v8 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v8,
      func: (_REASON_CONTEXT *)&v23,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASBevelFilterCtorFunction::GlobalCtor);
    v8->dwSize = (unsigned int)&GASBevelFilterCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v8->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  *(_DWORD *)a2 = v9;
  *((_BYTE *)a2 + 8) = 0;
  *((_DWORD *)a2 + 1) = 0;
  v11 = v4[54].MaxVal;
  v12 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)v11 + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v13 = (GASBevelFilterProto *)v12(a1: v11, a2: 240, a3: &pgca);
  if ( v13 != nullptr )
  {
    HIDWORD(v17) = GASGlobalContext::GetPrototype(this: v4, result: (vc_attributes::InvalidCheckAttribute *)0x25);
    LODWORD(v17) = &v23;
    v14 = GASBevelFilterProto::GASBevelFilterProto(this: v13, psc: v17, psc_8: a2);
  }
  else
  {
    v14 = nullptr;
  }
  if ( v14 != nullptr )
    *((_DWORD *)v14 + 2) = (*((_DWORD *)v14 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v4, (int)a2, a3: 41, a4: (int)v14);
  MinVal = v4[56].MinVal;
  HIBYTE(pgca) = 0;
  v25 = *((struct GASFunctionRef **)MinVal + 4);
  v16 = GASValue::GASValue(this: &v19, (int)a2, a3: a2);
  (*((void (__thiscall **)(const char *, vc_attributes::PreRangeAttribute **, const char **, GASValue *, char *))v25 + 10))(
    a1: v4[56].MinVal + 16,
    a2: &v23,
    a3: &v4[14].MinVal,
    a4: v16,
    a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: &v19, (int)a2);
  if ( v14 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v14, (int)a2);
}
