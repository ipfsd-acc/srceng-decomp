// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gastextformat.cpp
// Functions: 16
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gastextformat.h"

//------------------------------------------------------------------------------
// Address: 0x10119190
// Name: public: void GFxTextFormat::SetAlpha(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFormat::SetAlpha(GFxTextFormat *this, unsigned __int8 alpha)
{
  *((_DWORD *)this + 8) = *((_DWORD *)this + 8) & 0xFFFFFF | (alpha << 24);
  *((_WORD *)this + 21) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x101191C0
// Name: public: void GFxTextFormat::ClearUrl(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextFormat::ClearUrl(
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *this)
{
  GString::Clear(this: (GString *)this + 4);
  *((_WORD *)this + 21) &= ~0x100u;
  return 65279;
}

//------------------------------------------------------------------------------
// Address: 0x101191E0
// Name: public: void GFxTextParagraphFormat::SetBullet(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextParagraphFormat::SetBullet(GFxTextParagraphFormat *this, bool bullet)
{
  if ( bullet )
    *((_WORD *)this + 11) |= 0x8000u;
  else
    *((_WORD *)this + 11) &= ~0x8000u;
  *((_WORD *)this + 11) |= 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x10119210
// Name: public: bool GFxTextParagraphFormat::IsBullet(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxTextParagraphFormat::IsBullet(GFxTextParagraphFormat *this)
{
  return (*((_WORD *)this + 11) & 0x80u) != 0 && (*((_WORD *)this + 11) & 0x8000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10119230
// Name: public: void GFxTextFormat::SetFontSize(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextFormat::SetFontSize(
        _WORD *this,
        const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *result)
{
  int v2; // eax

  *(this + 21) |= 8u;
  if ( *(float *)&result >= 3276.8 )
  {
    *(this + 19) = -1;
    return 0xFFFF;
  }
  else
  {
    v2 = (unsigned __int16)(int)(*(float *)&result * 20.0);
    *(this + 19) = v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10119290
// Name: public: virtual bool GASTextFormatObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASTextFormatObject::SetMember@<al>(
        int a1@<ecx>,
        long double a2@<st0>,
        tagRID_DEVICE_INFO_KEYBOARD *result,
        const char ***name,
        tagWNDCLASSW *v,
        char *flags)
{
  const char **v8; // edi
  bool v9; // zf
  char style; // al
  int v11; // esi
  char v12; // al
  int v13; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  __int16 v17; // cx
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int v21; // esi
  _WORD *v22; // ecx
  struct GASObject *v23; // eax
  struct GASObject *v24; // edi
  signed int v25; // esi
  double v26; // st7
  unsigned int v27; // ebx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **v28; // eax
  char v29; // al
  char v30; // bl
  int v32; // edi
  int v33; // esi
  char v34; // al
  char v35; // bl
  float v36; // [esp+0h] [ebp-5Ch]
  MaterialVarFlags_t v37; // [esp+4h] [ebp-58h]
  bool v38; // [esp+8h] [ebp-54h]
  GASValue v39[4]; // [esp+10h] [ebp-4Ch] BYREF
  GASValue v40; // [esp+20h] [ebp-3Ch] BYREF
  long double v41; // [esp+24h] [ebp-38h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *valset; // [esp+30h] [ebp-2Ch] BYREF
  double v43; // [esp+34h] [ebp-28h]
  int n; // [esp+40h] [ebp-1Ch]
  __int64 v45; // [esp+44h] [ebp-18h]
  CTSQueue<CFunctor *,0,1> *v46; // [esp+4Ch] [ebp-10h]
  unsigned int *v47; // [esp+50h] [ebp-Ch] BYREF
  unsigned int *v48; // [esp+54h] [ebp-8h] BYREF
  const char **v49; // [esp+58h] [ebp-4h] BYREF
  char vc; // [esp+6Ch] [ebp+10h]
  char vd; // [esp+6Ch] [ebp+10h]
  char ve; // [esp+6Ch] [ebp+10h]
  char vf; // [esp+6Ch] [ebp+10h]
  int va; // [esp+6Ch] [ebp+10h]
  char vg; // [esp+6Ch] [ebp+10h]
  int vb; // [esp+6Ch] [ebp+10h]

  v46 = (CTSQueue<CFunctor *,0,1> *)a1;
  GASValue::GASValue(this: &valset, v);
  v8 = (const char **)**name;
  if ( strcmp((const char *)v8, (const char *)&stru_102A53D8) == 0 )
  {
    GASValue::ToStringImpl(this: (unsigned __int8 *)v, a2: (int *)&v49, a3: result, precision: -1, debug: false);
    v8 = v49;
    if ( strcmp(*v49, "left") == 0 )
    {
      *(_WORD *)(a1 + 102) = *(_WORD *)(a1 + 102) & 0xF9FE | 1;
    }
    else if ( strcmp(*v49, "right") == 0 )
    {
      *(_WORD *)(a1 + 102) = *(_WORD *)(a1 + 102) & 0xF9FE | 0x201;
    }
    else if ( GASString::operator==(this: &v49, a2: "center") )
    {
      *(_WORD *)(a1 + 102) |= 0x601u;
    }
    else if ( GASString::operator==(this: &v49, a2: "justify") )
    {
      *(_WORD *)(a1 + 102) = *(_WORD *)(a1 + 102) & 0xF9FE | 0x401;
    }
    else
    {
      *(_WORD *)(a1 + 102) &= 0xF9FEu;
      GASValue::DropRefs(this: &valset, a2: (int)v8);
      v8 = v49;
      LOBYTE(valset) = 1;
    }
    v9 = v8[2]-- == (const char *)1;
    if ( v9 )
      GASStringNode::ReleaseNode(a1: (int)v8);
    goto LABEL_160;
  }
  if ( strcmp(**name, "blockIndent") == 0 )
  {
    style = v->style;
    if ( LOBYTE(v->style) != 1 && style != 0 && style != 10 )
    {
      v11 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)v8, a3: a2, a4: (_SERVICE_STATUS *)result);
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)v8);
      LOBYTE(valset) = 3;
      v43 = (double)v11;
      if ( v11 >= 0 )
      {
        if ( v11 > 720 )
          LOWORD(v11) = 720;
        *(_WORD *)(a1 + 102) |= 2u;
        *(_WORD *)(a1 + 92) = v11;
      }
      else
      {
        *(_WORD *)(a1 + 102) |= 2u;
        *(_WORD *)(a1 + 92) = 0;
      }
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 102) &= ~2u;
    *(_WORD *)(a1 + 92) = 0;
    goto LABEL_159;
  }
  if ( strcmp(**name, (const char *)&stru_102904EC.m_Memory.m_nGrowSize) == 0 )
  {
    v12 = v->style;
    if ( LOBYTE(v->style) != 1 && v12 != 0 && v12 != 10 )
    {
      vc = GASValue::ToBool(a1: (char *)v, a2, (tagPOLYTEXTW *)result);
      GASValue::DropRefs(this: &valset, a2: (int)v8);
      LOBYTE(valset) = 2;
      LOBYTE(v43) = vc;
      GFxTextFormat::SetBold(this: (GFxTextFormat *)(a1 + 36), a2: vc);
LABEL_160:
      GASObject::SetMember(
        this: (CTSQueue<CFunctor *,0,1> *)a1,
        a2: (GASEnvironment *)result,
        (_IMAGE_SYMBOL_EX *)name,
        pval: &valset,
        pmember: flags);
      v35 = v34;
      GASValue::~GASValue(this: &valset, a2: (int)v8);
      return v35;
    }
    *(_BYTE *)(a1 + 76) &= ~1u;
    *(_WORD *)(a1 + 78) &= ~0x10u;
    goto LABEL_159;
  }
  v8 = (const char **)name;
  if ( GASString::operator==(this: name, a2: "bullet") )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      vd = GASValue::ToBool(a1: (char *)v, a2, (tagPOLYTEXTW *)result);
      GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 2;
      LOBYTE(v43) = vd;
      GFxTextParagraphFormat::SetBullet(this: (GFxTextParagraphFormat *)(a1 + 80), bullet: vd);
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 102) &= 0x7F7Fu;
LABEL_159:
    GASValue::DropRefs(this: &valset, a2: (int)v8);
    LOBYTE(valset) = 1;
    goto LABEL_160;
  }
  if ( GASString::operator==(this: name, a2: "color") )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      v13 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)name, a3: a2, a4: (_SERVICE_STATUS *)result);
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 3;
      v14 = *(_DWORD *)(a1 + 68);
      v43 = (double)(unsigned int)v13;
      *(_DWORD *)(a1 + 68) ^= (v13 ^ v14) & 0xFFFFFF;
      *(_WORD *)(a1 + 78) |= 1u;
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 78) &= ~1u;
    *(_DWORD *)(a1 + 68) = -16777216;
    goto LABEL_159;
  }
  if ( GASString::operator==(this: name, a2: (const char *)&stru_1029050C) )
  {
    if ( LOBYTE(v->style) == 1 || LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) != 0 )
    {
      *(_WORD *)(a1 + 78) &= 0xEFFBu;
      goto LABEL_159;
    }
    GASValue::ToStringImpl(this: (unsigned __int8 *)v, a2: (int *)&v48, a3: result, precision: -1, debug: false);
    GASValue::SetString(this: &valset, str: (_IMAGE_SYMBOL_EX *)&v48);
    GFxTextFormat::SetFontList(
      this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)(a1 + 36),
      pfontList: *v48);
    v15 = (int)v48;
LABEL_47:
    v9 = (*(_DWORD *)(v15 + 8))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode(a1: v15);
    goto LABEL_160;
  }
  if ( GASString::operator==(this: name, a2: "indent") )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      v16 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)name, a3: a2, a4: (_SERVICE_STATUS *)result);
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 3;
      v43 = (double)v16;
      if ( v16 >= -720 )
      {
        if ( v16 > 720 )
          LOWORD(v16) = 720;
        *(_WORD *)(a1 + 102) |= 4u;
        *(_WORD *)(a1 + 94) = v16;
      }
      else
      {
        *(_WORD *)(a1 + 102) |= 4u;
        *(_WORD *)(a1 + 94) = -720;
      }
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 102) &= ~4u;
    *(_WORD *)(a1 + 94) = 0;
    goto LABEL_159;
  }
  if ( GASString::operator==(this: name, a2: (const char *)&stru_102904EC) )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      ve = GASValue::ToBool(a1: (char *)v, a2, (tagPOLYTEXTW *)result);
      GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 2;
      LOBYTE(v43) = ve;
      GFxTextFormat::SetItalic(this: (GFxTextFormat *)(a1 + 36), a2: ve);
      goto LABEL_160;
    }
    *(_BYTE *)(a1 + 76) &= ~2u;
    v17 = -33;
    goto LABEL_158;
  }
  if ( GASString::operator==(this: name, a2: (const char *)&stru_102A2E68) )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      v18 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)name, a3: a2, a4: (_SERVICE_STATUS *)result);
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 3;
      v43 = (double)v18;
      if ( v18 >= -720 )
      {
        if ( v18 > 720 )
          LOWORD(v18) = 720;
        *(_WORD *)(a1 + 102) |= 8u;
        *(_WORD *)(a1 + 96) = v18;
      }
      else
      {
        *(_WORD *)(a1 + 102) |= 8u;
        *(_WORD *)(a1 + 96) = -720;
      }
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 102) &= ~8u;
    *(_WORD *)(a1 + 96) = 0;
    goto LABEL_159;
  }
  if ( GASString::operator==(this: name, a2: "leftMargin") )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      v19 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)name, a3: a2, a4: (_SERVICE_STATUS *)result);
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 3;
      v43 = (double)v19;
      if ( v19 >= 0 )
      {
        if ( v19 > 720 )
          LOWORD(v19) = 720;
        *(_WORD *)(a1 + 102) |= 0x10u;
        *(_WORD *)(a1 + 98) = v19;
      }
      else
      {
        *(_WORD *)(a1 + 102) |= 0x10u;
        *(_WORD *)(a1 + 98) = 0;
      }
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 102) &= ~0x10u;
    *(_WORD *)(a1 + 98) = 0;
    goto LABEL_159;
  }
  if ( GASString::operator==(this: name, a2: "rightMargin") )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      v20 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)name, a3: a2, a4: (_SERVICE_STATUS *)result);
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 3;
      v43 = (double)v20;
      if ( v20 >= 0 )
      {
        if ( v20 > 720 )
          LOWORD(v20) = 720;
        *(_WORD *)(a1 + 102) |= 0x20u;
        *(_WORD *)(a1 + 100) = v20;
      }
      else
      {
        *(_WORD *)(a1 + 102) |= 0x20u;
        *(_WORD *)(a1 + 100) = 0;
      }
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 102) &= ~0x20u;
    *(_WORD *)(a1 + 100) = 0;
    goto LABEL_159;
  }
  if ( GASString::operator==(this: name, a2: "size") )
  {
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      v21 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)name, a3: a2, a4: (_SERVICE_STATUS *)result);
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)name);
      LOBYTE(valset) = 3;
      v43 = (double)v21;
      if ( v21 >= 0 )
      {
        v22 = (_WORD *)(a1 + 36);
        if ( v21 >= 128 )
        {
          GFxTextFormat::SetFontSize(
            this: v22,
            result: COERCE_CONST_CMEMBERFUNCPROXYBASE_IMATERIALINTERNAL_VOID_THISCALL_IMATERIAL_VOID_CFUNCMEMPOLICYNONE_(127.0));
        }
        else
        {
          v36 = (float)(unsigned int)v21;
          GFxTextFormat::SetFontSize(
            this: v22,
            result: (const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)LODWORD(v36));
        }
      }
      goto LABEL_160;
    }
    *(_WORD *)(a1 + 74) = 0;
    v17 = -9;
LABEL_158:
    *(_WORD *)(a1 + 78) &= v17;
    goto LABEL_159;
  }
  if ( !GASString::operator==(this: name, a2: (const char *)&stru_102A5CE0.m_pElements) )
  {
    if ( GASString::operator==(this: name, a2: (const char *)&stru_102A5CE0.m_Memory.m_nAllocationCount) )
    {
      if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
      {
        vf = GASValue::ToBool(a1: (char *)v, a2, (tagPOLYTEXTW *)result);
        GASValue::DropRefs(this: &valset, a2: (int)name);
        LOBYTE(valset) = 2;
        LOBYTE(v43) = vf;
        GFxTextFormat::SetUnderline(this: (GFxTextFormat *)(a1 + 36), a2: vf);
        goto LABEL_160;
      }
      *(_BYTE *)(a1 + 76) &= ~4u;
      v17 = -65;
      goto LABEL_158;
    }
    if ( GASString::operator==(this: name, a2: (const char *)&stru_102A5CE0) )
    {
      if ( LOBYTE(v->style) == 1 || LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) != 0 )
      {
        GFxTextFormat::ClearUrl(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)(a1 + 36));
        goto LABEL_159;
      }
      GASValue::ToStringImpl(this: (unsigned __int8 *)v, a2: (int *)&v47, a3: result, precision: -1, debug: false);
      GASValue::SetString(this: &valset, str: (_IMAGE_SYMBOL_EX *)&v47);
      GFxTextFormat::SetUrl(
        this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(void),CFuncMemPolicyNone> *)(a1 + 36),
        purl: *v47);
      v15 = (int)v47;
      goto LABEL_47;
    }
    if ( LOBYTE(result[5].dwSubType) < 8u )
      goto LABEL_146;
    if ( GASString::operator==(this: name, a2: (const char *)&stru_102A5CC8.m_Memory.m_nGrowSize) )
    {
      if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
      {
        v32 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)name, a3: a2, a4: (_SERVICE_STATUS *)result);
        va = v32;
        if ( (unsigned __int8)valset >= 5u )
          GASValue::DropRefs(this: &valset, a2: v32);
        LOBYTE(valset) = 3;
        v43 = (double)v32;
        if ( v32 >= -720 )
        {
          if ( v32 > 720 )
            va = 720;
        }
        else
        {
          va = -720;
        }
        a2 = (double)va * 20.0;
        *(_WORD *)(a1 + 78) |= 2u;
        v8 = (const char **)name;
        *(_WORD *)(a1 + 72) = (int)a2;
        goto LABEL_146;
      }
      *(_WORD *)(a1 + 78) &= ~2u;
      *(_WORD *)(a1 + 72) = 0;
    }
    else
    {
      if ( !GASString::operator==(this: name, a2: (const char *)&stru_102A5CC8) )
        goto LABEL_146;
      if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
      {
        vg = GASValue::ToBool(a1: (char *)v, a2, (tagPOLYTEXTW *)result);
        GASValue::DropRefs(this: &valset, a2: (int)name);
        LOBYTE(valset) = 2;
        LOBYTE(v43) = vg;
        GFxTextFormat::SetKerning(this: (GFxTextFormat *)(a1 + 36), a2: vg);
        goto LABEL_146;
      }
      *(_BYTE *)(a1 + 76) &= ~8u;
      *(_WORD *)(a1 + 78) &= ~0x80u;
    }
    GASValue::DropRefs(this: &valset, a2: (int)name);
    LOBYTE(valset) = 1;
LABEL_146:
    if ( *(_BYTE *)(result[5].dwType + 684) != 1
      || !GASString::operator==(this: (const char ***)v8, a2: (const char *)&stru_1029DF5C) )
    {
      goto LABEL_160;
    }
    if ( LOBYTE(v->style) != 1 && LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) == 0 )
    {
      v33 = GASValue::ToInt32(this: (GASValue *)v, a2: (int)v8, a3: a2, a4: (_SERVICE_STATUS *)result);
      vb = v33;
      if ( (unsigned __int8)valset >= 5u )
        GASValue::DropRefs(this: &valset, a2: (int)v8);
      LOBYTE(valset) = 3;
      v43 = (double)v33;
      if ( v33 >= 0 )
      {
        if ( v33 > 100 )
          vb = 100;
      }
      else
      {
        vb = 0;
      }
      n = (int)((double)vb * 255.0 / 100.0);
      GFxTextFormat::SetAlpha(this: (GFxTextFormat *)(a1 + 36), alpha: n);
      goto LABEL_160;
    }
    *(_DWORD *)(a1 + 68) |= 0xFF000000;
    v17 = -1025;
    goto LABEL_158;
  }
  if ( LOBYTE(v->style) == 1 || LOBYTE(GASValue::IsUndefined(this: v).usPreferredNode) != 0 )
  {
    GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)(a1 + 80), a2: v37, a3: v38);
    *(_WORD *)(a1 + 102) &= ~0x40u;
    goto LABEL_159;
  }
  if ( LOBYTE(v->style) != 6 )
    goto LABEL_160;
  v23 = GASValue::ToObject(this: (GASValue *)v, a2: (int)name, a3: (const struct GASEnvironment *)result);
  if ( ((int (__thiscall *)(struct GASObject *))v23[2].pNode[1].pNext)(a1: &v23[2]) != 7 )
    goto LABEL_160;
  v24 = GASValue::ToObject(this: (GASValue *)v, a2: (int)name, a3: (const struct GASEnvironment *)result);
  GFxTextParagraphFormat::AllocTabStops(result: (CMemberFunctor2<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),enum MaterialVarFlags_t,bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v24[7].sequence);
  *(_WORD *)(a1 + 102) |= 0x40u;
  v25 = 0;
  n = v24[7].sequence;
  if ( n > 0 )
  {
    do
    {
      v26 = GASValue::ToNumber(
              this: (GASValue *)*((_DWORD *)&v24[7].pNode->pNext + v25),
              a2: (int)v24,
              a3: a2,
              (_SERVICE_STATUS *)result);
      LOBYTE(v40) = 3;
      v45 = (__int64)v26;
      v27 = (__int64)v26;
      a2 = (double)v27;
      v41 = a2;
      GASArrayObject::SetElement(this: (GASArrayObject *)v24, a2: v25, v: (tagWNDCLASSW *)&v40);
      GASValue::~GASValue(this: &v40, a2: (int)v24);
      GFxTextParagraphFormat::SetTabStopsElement(this: (GFxTextParagraphFormat *)&v46[2].m_Count, idx: v25++, a3: v27);
    }
    while ( v25 < n );
  }
  v28 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)GASValue::GASValue(
                                                                                      this: v39,
                                                                                      a2: v24);
  GASObject::SetMember(this: v46, a2: (GASEnvironment *)result, (_IMAGE_SYMBOL_EX *)name, pval: v28, pmember: flags);
  v30 = v29;
  GASValue::~GASValue(this: v39, a2: (int)v24);
  GASValue::~GASValue(this: &valset, a2: (int)v24);
  return v30;
}

//------------------------------------------------------------------------------
// Address: 0x10119DE0
// Name: protected: virtual void GASTextFormatObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTextFormatObject::Finalize_GC(GASObject *this)
{
  (**((void (__thiscall ***)(char *, _DWORD))this + 13))(a1: (char *)this + 52, a2: 0);
  (**((void (__thiscall ***)(GASObject *, _DWORD))this + 24))(a1: this + 12, a2: 0);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011A1A0
// Name: protected: GASTextFormatObject::GASTextFormatObject(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
GASTextFormatObject *__thiscall GASTextFormatObject::GASTextFormatObject(
        GASTextFormatObject *this,
        GASGlobalContext **psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4)
{
  struct GMemoryHeap *v5; // eax
  struct GMemoryHeap *psca; // [esp+14h] [ebp+8h]

  GASObject::GASObject((GASObject *)this, a2: (int)psc, psc);
  *(_DWORD *)this = &GASTextFormatObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASTextFormatObject::`vftable'{for `GASObjectInterface'};
  v5 = *((struct GMemoryHeap **)*psc + 164);
  *((_DWORD *)this + 13) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 14) = 1;
  psca = v5;
  *((_DWORD *)this + 13) = &GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: (GStringDH *)((char *)this + 60), a2: v5);
  GStringDH::GStringDH(this: (GStringDH *)((char *)this + 68), a2: psca);
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_BYTE *)this + 92) = 0;
  *((_DWORD *)this + 21) = -16777216;
  *((_DWORD *)this + 22) = 0;
  *((_WORD *)this + 47) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 24) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 25) = 1;
  *((_DWORD *)this + 24) = &GFxTextParagraphFormat::`vftable';
  *((_DWORD *)this + 28) = 0;
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16),
    (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    psc_4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011A2B0
// Name: public: GASTextFormatObject::GASTextFormatObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GASTextFormatObject *__userpurge GASTextFormatObject::GASTextFormatObject@<eax>(
        GASTextFormatObject *this@<ecx>,
        int a2@<edi>,
        struct GASEnvironment *a3)
{
  struct GMemoryHeap *v4; // eax
  char *v5; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  int v7; // eax
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  int v11; // eax
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
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  GASValue v47[4]; // [esp+Ch] [ebp-194h] BYREF
  GASValue v48[4]; // [esp+1Ch] [ebp-184h] BYREF
  GASValue v49[4]; // [esp+2Ch] [ebp-174h] BYREF
  GASValue v50[4]; // [esp+3Ch] [ebp-164h] BYREF
  GASValue v51[4]; // [esp+4Ch] [ebp-154h] BYREF
  GASValue v52[4]; // [esp+5Ch] [ebp-144h] BYREF
  GASValue v53[4]; // [esp+6Ch] [ebp-134h] BYREF
  GASValue v54[4]; // [esp+7Ch] [ebp-124h] BYREF
  GASValue v55[4]; // [esp+8Ch] [ebp-114h] BYREF
  GASValue v56[4]; // [esp+9Ch] [ebp-104h] BYREF
  GASValue v57[4]; // [esp+ACh] [ebp-F4h] BYREF
  GASValue v58[4]; // [esp+BCh] [ebp-E4h] BYREF
  GASValue v59[4]; // [esp+CCh] [ebp-D4h] BYREF
  GASValue v60[4]; // [esp+DCh] [ebp-C4h] BYREF
  GASValue v61[4]; // [esp+ECh] [ebp-B4h] BYREF
  GASValue v62[4]; // [esp+FCh] [ebp-A4h] BYREF
  GASValue v63[4]; // [esp+10Ch] [ebp-94h] BYREF
  GASValue v64[4]; // [esp+11Ch] [ebp-84h] BYREF
  GASValue v65[4]; // [esp+12Ch] [ebp-74h] BYREF
  struct GMemoryHeap *v66; // [esp+13Ch] [ebp-64h]
  struct GASStringNode *v67; // [esp+140h] [ebp-60h] BYREF
  struct GASStringNode *v68; // [esp+144h] [ebp-5Ch] BYREF
  struct GASStringNode *v69; // [esp+148h] [ebp-58h] BYREF
  struct GASStringNode *v70; // [esp+14Ch] [ebp-54h] BYREF
  struct GASStringNode *v71; // [esp+150h] [ebp-50h] BYREF
  struct GASStringNode *v72; // [esp+154h] [ebp-4Ch] BYREF
  struct GASStringNode *v73; // [esp+158h] [ebp-48h] BYREF
  struct GASStringNode *v74; // [esp+15Ch] [ebp-44h] BYREF
  struct GASStringNode *v75; // [esp+160h] [ebp-40h] BYREF
  struct GASStringNode *v76; // [esp+164h] [ebp-3Ch] BYREF
  struct GASStringNode *v77; // [esp+168h] [ebp-38h] BYREF
  struct GASStringNode *v78; // [esp+16Ch] [ebp-34h] BYREF
  struct GASStringNode *v79; // [esp+170h] [ebp-30h] BYREF
  struct GASStringNode *v80; // [esp+174h] [ebp-2Ch] BYREF
  struct GASStringNode *v81; // [esp+178h] [ebp-28h] BYREF
  struct GASStringNode *v82; // [esp+17Ch] [ebp-24h] BYREF
  struct GASStringNode *v83; // [esp+180h] [ebp-20h] BYREF
  struct GASStringNode *ConstStringNode; // [esp+184h] [ebp-1Ch] BYREF
  struct GASStringNode *v85; // [esp+188h] [ebp-18h] BYREF
  char v86; // [esp+18Dh] [ebp-13h] BYREF
  char v87; // [esp+18Eh] [ebp-12h] BYREF
  char v88; // [esp+18Fh] [ebp-11h] BYREF
  char v89; // [esp+190h] [ebp-10h] BYREF
  char v90; // [esp+191h] [ebp-Fh] BYREF
  char v91; // [esp+192h] [ebp-Eh] BYREF
  char v92; // [esp+193h] [ebp-Dh] BYREF
  char v93; // [esp+194h] [ebp-Ch] BYREF
  char v94; // [esp+195h] [ebp-Bh] BYREF
  char v95; // [esp+196h] [ebp-Ah] BYREF
  char v96; // [esp+197h] [ebp-9h] BYREF
  char v97; // [esp+198h] [ebp-8h] BYREF
  char v98; // [esp+199h] [ebp-7h] BYREF
  char v99; // [esp+19Ah] [ebp-6h] BYREF
  char v100; // [esp+19Bh] [ebp-5h] BYREF
  char v101; // [esp+19Ch] [ebp-4h] BYREF
  char v102; // [esp+19Dh] [ebp-3h] BYREF
  char v103; // [esp+19Eh] [ebp-2h] BYREF
  char v104; // [esp+19Fh] [ebp-1h] BYREF

  GASObject::GASObject((GASObject *)this, a2: a3);
  *(_DWORD *)this = &GASTextFormatObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASTextFormatObject::`vftable'{for `GASObjectInterface'};
  v4 = *(struct GMemoryHeap **)(*((_DWORD *)a3 + 30) + 656);
  v5 = (char *)a3 + 120;
  *((_DWORD *)this + 13) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 14) = 1;
  v66 = v4;
  *((_DWORD *)this + 13) = &GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: (GStringDH *)((char *)this + 60), a2: v4);
  GStringDH::GStringDH(this: (GStringDH *)((char *)this + 68), a2: v66);
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = -16777216;
  *((_BYTE *)this + 92) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_WORD *)this + 47) = 0;
  *((_DWORD *)this + 24) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 25) = 1;
  *((_DWORD *)this + 24) = &GFxTextParagraphFormat::`vftable';
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *((vc_attributes::PreRangeAttribute **)a3 + 30),
                                                    result: (vc_attributes::InvalidCheckAttribute *)0x20);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)a3 + 15,
    psc_4: Prototype);
  v7 = *((_DWORD *)a3 + 30);
  v103 = 2;
  LOBYTE(v64[0]) = 1;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(v7 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8,
                      a3: 5u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: (char *)a3 + 120,
    a3: &ConstStringNode,
    a4: v64,
    a5: &v103);
  v8 = (int)ConstStringNode;
  v9 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v8);
  GASValue::~GASValue(this: v64, a2);
  v10 = *(_DWORD *)v5;
  v87 = 2;
  LOBYTE(v48[0]) = 1;
  v68 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v10 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"blockIndent",
          a3: 0xBu,
          a4: 0);
  ++*((_DWORD *)v68 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v68,
    a4: v48,
    a5: &v87);
  v11 = (int)v68;
  v9 = (*((_DWORD *)v68 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v11);
  GASValue::~GASValue(this: v48, a2);
  v12 = *(_DWORD *)v5;
  v101 = 2;
  LOBYTE(v62[0]) = 1;
  v82 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v12 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC.m_Memory.m_nGrowSize,
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v82 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v82,
    a4: v62,
    a5: &v101);
  v13 = (int)v82;
  v9 = (*((_DWORD *)v82 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v13);
  GASValue::~GASValue(this: v62, a2);
  v14 = *(_DWORD *)v5;
  v93 = 2;
  LOBYTE(v54[0]) = 1;
  v74 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v14 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"bullet",
          a3: 6u,
          a4: 0);
  ++*((_DWORD *)v74 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v74,
    a4: v54,
    a5: &v93);
  v15 = (int)v74;
  v9 = (*((_DWORD *)v74 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v15);
  GASValue::~GASValue(this: v54, a2);
  v16 = *(_DWORD *)v5;
  v99 = 2;
  LOBYTE(v60[0]) = 1;
  v80 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v16 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color",
          a3: 5u,
          a4: 0);
  ++*((_DWORD *)v80 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v80,
    a4: v60,
    a5: &v99);
  v17 = (int)v80;
  v9 = (*((_DWORD *)v80 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v17);
  GASValue::~GASValue(this: v60, a2);
  v18 = *(_DWORD *)v5;
  v89 = 2;
  LOBYTE(v50[0]) = 1;
  v70 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v18 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029050C,
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v70 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v70,
    a4: v50,
    a5: &v89);
  v19 = (int)v70;
  v9 = (*((_DWORD *)v70 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v19);
  GASValue::~GASValue(this: v50, a2);
  v20 = *(_DWORD *)v5;
  v97 = 2;
  LOBYTE(v58[0]) = 1;
  v78 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v20 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"indent",
          a3: 6u,
          a4: 0);
  ++*((_DWORD *)v78 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v78,
    a4: v58,
    a5: &v97);
  v21 = (int)v78;
  v9 = (*((_DWORD *)v78 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v21);
  GASValue::~GASValue(this: v58, a2);
  v22 = *(_DWORD *)v5;
  v91 = 2;
  LOBYTE(v52[0]) = 1;
  v72 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v22 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC,
          a3: 6u,
          a4: 0);
  ++*((_DWORD *)v72 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v72,
    a4: v52,
    a5: &v91);
  v23 = (int)v72;
  v9 = (*((_DWORD *)v72 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v23);
  GASValue::~GASValue(this: v52, a2);
  v24 = *(_DWORD *)v5;
  v95 = 2;
  LOBYTE(v56[0]) = 1;
  v76 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v24 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68,
          a3: 7u,
          a4: 0);
  ++*((_DWORD *)v76 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v76,
    a4: v56,
    a5: &v95);
  v25 = (int)v76;
  v9 = (*((_DWORD *)v76 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v25);
  GASValue::~GASValue(this: v56, a2);
  v26 = *(_DWORD *)v5;
  v104 = 2;
  LOBYTE(v65[0]) = 1;
  v85 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v26 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"leftMargin",
          a3: 0xAu,
          a4: 0);
  ++*((_DWORD *)v85 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v85,
    a4: v65,
    a5: &v104);
  v27 = (int)v85;
  v9 = (*((_DWORD *)v85 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v27);
  GASValue::~GASValue(this: v65, a2);
  v28 = *(_DWORD *)v5;
  v102 = 2;
  LOBYTE(v63[0]) = 1;
  v83 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v28 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"rightMargin",
          a3: 0xBu,
          a4: 0);
  ++*((_DWORD *)v83 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v83,
    a4: v63,
    a5: &v102);
  v29 = (int)v83;
  v9 = (*((_DWORD *)v83 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v29);
  GASValue::~GASValue(this: v63, a2);
  v30 = *(_DWORD *)v5;
  v100 = 2;
  LOBYTE(v61[0]) = 1;
  v81 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v30 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"size",
          a3: 4u,
          a4: 0);
  ++*((_DWORD *)v81 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v81,
    a4: v61,
    a5: &v100);
  v31 = (int)v81;
  v9 = (*((_DWORD *)v81 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v31);
  GASValue::~GASValue(this: v61, a2);
  v32 = *(_DWORD *)v5;
  v98 = 2;
  LOBYTE(v59[0]) = 1;
  v79 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v32 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0.m_pElements,
          a3: 8u,
          a4: 0);
  ++*((_DWORD *)v79 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v79,
    a4: v59,
    a5: &v98);
  v33 = (int)v79;
  v9 = (*((_DWORD *)v79 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v33);
  GASValue::~GASValue(this: v59, a2);
  v34 = *(_DWORD *)v5;
  v96 = 2;
  LOBYTE(v57[0]) = 1;
  v77 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v34 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5E40,
          a3: 6u,
          a4: 0);
  ++*((_DWORD *)v77 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v77,
    a4: v57,
    a5: &v96);
  v35 = (int)v77;
  v9 = (*((_DWORD *)v77 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v35);
  GASValue::~GASValue(this: v57, a2);
  v36 = *(_DWORD *)v5;
  v94 = 2;
  LOBYTE(v55[0]) = 1;
  v75 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v36 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0.m_Memory.m_nAllocationCount,
          a3: 9u,
          a4: 0);
  ++*((_DWORD *)v75 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v75,
    a4: v55,
    a5: &v94);
  v37 = (int)v75;
  v9 = (*((_DWORD *)v75 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v37);
  GASValue::~GASValue(this: v55, a2);
  v38 = *(_DWORD *)v5;
  v92 = 2;
  LOBYTE(v53[0]) = 1;
  v73 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v38 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0,
          a3: 3u,
          a4: 0);
  ++*((_DWORD *)v73 + 2);
  (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: v5,
    a3: &v73,
    a4: v53,
    a5: &v92);
  v39 = (int)v73;
  v9 = (*((_DWORD *)v73 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v39);
  GASValue::~GASValue(this: v53, a2);
  if ( *((_BYTE *)a3 + 124) >= 8u )
  {
    v40 = *(_DWORD *)v5;
    v90 = 2;
    LOBYTE(v51[0]) = 1;
    v71 = GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v40 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CC8,
            a3: 7u,
            a4: 0);
    ++*((_DWORD *)v71 + 2);
    (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
      a1: (char *)this + 16,
      a2: v5,
      a3: &v71,
      a4: v51,
      a5: &v90);
    v41 = (int)v71;
    v9 = (*((_DWORD *)v71 + 2))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode(a1: v41);
    GASValue::~GASValue(this: v51, a2);
    v42 = *(_DWORD *)v5;
    v88 = 2;
    LOBYTE(v49[0]) = 1;
    v69 = GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v42 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CC8.m_Memory.m_nGrowSize,
            a3: 0xDu,
            a4: 0);
    ++*((_DWORD *)v69 + 2);
    (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
      a1: (char *)this + 16,
      a2: v5,
      a3: &v69,
      a4: v49,
      a5: &v88);
    v43 = (int)v69;
    v9 = (*((_DWORD *)v69 + 2))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode(a1: v43);
    GASValue::~GASValue(this: v49, a2);
  }
  v44 = *(_DWORD *)v5;
  if ( *(_BYTE *)(*(_DWORD *)v5 + 684) == 1 )
  {
    v86 = 2;
    LOBYTE(v47[0]) = 1;
    v67 = GASStringManager::CreateConstStringNode(
            this: *(GASStringManager **)(v44 + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DF5C,
            a3: 5u,
            a4: 0);
    ++*((_DWORD *)v67 + 2);
    (*(void (__thiscall **)(char *, char *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
      a1: (char *)this + 16,
      a2: v5,
      a3: &v67,
      a4: v47,
      a5: &v86);
    v45 = (int)v67;
    v9 = (*((_DWORD *)v67 + 2))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode(a1: v45);
    GASValue::~GASValue(this: v47, a2);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011AA50
// Name: public: void GASTextFormatObject::SetTextFormat(class GASStringContext __near *,class GFxTextFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTextFormatObject::SetTextFormat(
        GPtr<GFxAmpCurrentState> *this,
        CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> psc)
{
  IMaterialInternal *m_pObject; // edi
  char v4; // al
  int v5; // ebx
  char v6; // cl
  GPtr<GFxAmpCurrentState> *v7; // edi
  tagWNDCLASSW *m_pfnProxied; // esi
  int v9; // ecx
  struct GASStringNode *ConstStringNode; // eax
  GASValue *v11; // ecx
  int v12; // eax
  bool v13; // zf
  int v14; // ebx
  bool v15; // dl
  GASValue *v16; // eax
  unsigned int style; // edx
  GASStringManager *v18; // ecx
  struct GASStringNode *v19; // eax
  int v20; // eax
  int v21; // ebx
  bool v22; // dl
  GASValue *v23; // eax
  unsigned int v24; // edx
  GASStringManager *v25; // ecx
  struct GASStringNode *v26; // eax
  int v27; // eax
  int v28; // ebx
  GASValue *v29; // eax
  unsigned int v30; // edx
  GASStringManager *v31; // ecx
  struct GASStringNode *v32; // eax
  int v33; // eax
  int v34; // ebx
  _DWORD *v35; // eax
  struct GASStringNode *StringNode; // eax
  GASValue *v37; // eax
  unsigned int v38; // edx
  GASStringManager *v39; // ecx
  struct GASStringNode *v40; // eax
  int v41; // eax
  int v42; // ecx
  int v43; // ebx
  unsigned int v44; // eax
  struct GASStringNode *v45; // eax
  GASValue *v46; // ecx
  int v47; // eax
  int v48; // ebx
  GASValue *v49; // eax
  unsigned int v50; // edx
  GASStringManager *v51; // ecx
  struct GASStringNode *v52; // eax
  int v53; // eax
  int v54; // ebx
  bool v55; // dl
  GASValue *v56; // eax
  unsigned int v57; // edx
  GASStringManager *v58; // ecx
  struct GASStringNode *v59; // eax
  int v60; // eax
  int v61; // ebx
  struct GASStringNode *v62; // eax
  GASValue *v63; // eax
  unsigned int v64; // edx
  GASStringManager *v65; // ecx
  struct GASStringNode *v66; // eax
  int v67; // eax
  int v68; // ecx
  int v69; // ebx
  GASValue *v70; // eax
  GASValue *v71; // [esp-8h] [ebp-54h]
  GASValue *v72; // [esp-8h] [ebp-54h]
  GASValue *v73; // [esp-8h] [ebp-54h]
  GASValue *v74; // [esp-8h] [ebp-54h]
  GASValue *v75; // [esp-8h] [ebp-54h]
  GASValue *v76; // [esp-8h] [ebp-54h]
  GASValue *v77; // [esp-8h] [ebp-54h]
  GASValue v78[4]; // [esp+Ch] [ebp-40h] BYREF
  GASValue v79; // [esp+1Ch] [ebp-30h] BYREF
  double v80; // [esp+20h] [ebp-2Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *nullVal; // [esp+2Ch] [ebp-20h] BYREF
  struct GASStringNode *v82; // [esp+3Ch] [ebp-10h]
  GASValue *v83; // [esp+40h] [ebp-Ch] BYREF
  GASValue *v84; // [esp+44h] [ebp-8h] BYREF
  char v85; // [esp+4Bh] [ebp-1h] BYREF

  m_pObject = psc.m_pObject;
  v82 = nullptr;
  GFxTextFormat::operator=(this: (int)(this + 13), __that: (int)psc.m_pObject);
  v4 = BYTE2(m_pObject[10].__vftable) >> 4;
  LOBYTE(nullVal) = 1;
  if ( (v4 & 1) != 0 )
  {
    v5 = 1;
    v6 = (int)m_pObject[10].__vftable & 1;
    LOBYTE(v79) = 2;
    LOBYTE(v80) = v6;
    v84 = &v79;
  }
  else
  {
    v5 = 2;
    v84 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  v7 = this + 4;
  m_pfnProxied = (tagWNDCLASSW *)psc.m_pfnProxied;
  v9 = *(_DWORD *)psc.m_pfnProxied;
  v85 = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(v9 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC.m_Memory.m_nGrowSize,
                      a3: 4u,
                      a4: 0);
  v11 = v84;
  psc.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &psc,
    a4: v11,
    a5: &v85);
  v12 = (int)psc.m_pfnProxied;
  v13 = (*((_DWORD *)psc.m_pfnProxied + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v12);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v5 & 1) != 0 )
  {
    v5 &= ~1u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (BYTE2(psc.m_pObject[10].__vftable) & 0x20) != 0 )
  {
    v14 = v5 | 4;
    v15 = ((int)psc.m_pObject[10].__vftable & 2) != 0;
    LOBYTE(v79) = 2;
    LOBYTE(v80) = v15;
    v16 = &v79;
  }
  else
  {
    v14 = v5 | 8;
    v16 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  style = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v18 = *(GASStringManager **)(style + 636);
  v84 = v16;
  v19 = GASStringManager::CreateConstStringNode(
          this: v18,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC,
          a3: 6u,
          a4: 0);
  v71 = v84;
  v83 = (GASValue *)v19;
  ++*((_DWORD *)v19 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v83,
    a4: v71,
    a5: (char *)&psc.m_pfnProxied + 3);
  v20 = (int)v83;
  v13 = (*((_DWORD *)v83 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v20);
  if ( (v14 & 8) != 0 )
  {
    v14 &= ~8u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v14 & 4) != 0 )
  {
    v14 &= ~4u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (BYTE2(psc.m_pObject[10].__vftable) & 0x40) != 0 )
  {
    v21 = v14 | 0x10;
    v22 = ((int)psc.m_pObject[10].__vftable & 4) != 0;
    LOBYTE(v79) = 2;
    LOBYTE(v80) = v22;
    v23 = &v79;
  }
  else
  {
    v21 = v14 | 0x20;
    v23 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  v24 = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v25 = *(GASStringManager **)(v24 + 636);
  v83 = v23;
  v26 = GASStringManager::CreateConstStringNode(
          this: v25,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0.m_Memory.m_nAllocationCount,
          a3: 9u,
          a4: 0);
  v72 = v83;
  v84 = (GASValue *)v26;
  ++*((_DWORD *)v26 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v84,
    a4: v72,
    a5: (char *)&psc.m_pfnProxied + 3);
  v27 = (int)v84;
  v13 = (*((_DWORD *)v84 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v27);
  if ( (v21 & 0x20) != 0 )
  {
    v21 &= ~0x20u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v21 & 0x10) != 0 )
  {
    v21 &= ~0x10u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (BYTE2(psc.m_pObject[10].__vftable) & 8) != 0 )
  {
    psc.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))HIWORD(psc.m_pObject[9].__vftable);
    v28 = v21 | 0x40;
    LOBYTE(v79) = 3;
    v29 = &v79;
    *(float *)&psc.m_pfnProxied = (double)(int)psc.m_pfnProxied / 20.0;
    v80 = *(float *)&psc.m_pfnProxied;
  }
  else
  {
    v28 = v21 | 0x80;
    v29 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  v30 = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v31 = *(GASStringManager **)(v30 + 636);
  v83 = v29;
  v32 = GASStringManager::CreateConstStringNode(
          this: v31,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"size",
          a3: 4u,
          a4: 0);
  v73 = v83;
  v84 = (GASValue *)v32;
  ++*((_DWORD *)v32 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v84,
    a4: v73,
    a5: (char *)&psc.m_pfnProxied + 3);
  v33 = (int)v84;
  v13 = (*((_DWORD *)v84 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v33);
  if ( (v28 & 0x80u) != 0 )
  {
    v28 &= ~0x80u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v28 & 0x40) != 0 )
  {
    v28 &= ~0x40u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (BYTE2(psc.m_pObject[10].__vftable) & 4) != 0 )
  {
    v34 = v28 | 0x300;
    LOBYTE(v35) = GFxTextFormat::GetFontList();
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(m_pfnProxied->style + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*v35 & 0xFFFFFFFC) + 8),
                   length: *(_DWORD *)(*v35 & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)StringNode + 2);
    LODWORD(v80) = StringNode;
    LOBYTE(v79) = 5;
    ++*((_DWORD *)StringNode + 2);
    v82 = StringNode;
    v37 = &v79;
  }
  else
  {
    v34 = v28 | 0x400;
    v37 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  v38 = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v39 = *(GASStringManager **)(v38 + 636);
  v83 = v37;
  v40 = GASStringManager::CreateConstStringNode(
          this: v39,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029050C,
          a3: 4u,
          a4: 0);
  v74 = v83;
  v84 = (GASValue *)v40;
  ++*((_DWORD *)v40 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v84,
    a4: v74,
    a5: (char *)&psc.m_pfnProxied + 3);
  v41 = (int)v84;
  v13 = (*((_DWORD *)v84 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v41);
  if ( (v34 & 0x400) != 0 )
  {
    v34 &= ~0x400u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v34 & 0x200) != 0 )
  {
    v34 &= ~0x200u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (v34 & 0x100) != 0 )
  {
    v42 = (int)v82;
    v34 &= ~0x100u;
    v13 = (*((_DWORD *)v82 + 2))-- == 1;
    if ( v13 )
      GASStringNode::ReleaseNode(a1: v42);
  }
  if ( (BYTE2(psc.m_pObject[10].__vftable) & 1) != 0 )
  {
    v43 = v34 | 0x800;
    psc.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))((int)psc.m_pObject[8].__vftable & 0xFFFFFF);
    LOBYTE(v79) = 3;
    v80 = (double)(int)psc.m_pfnProxied;
    v83 = &v79;
  }
  else
  {
    v43 = v34 | 0x1000;
    v83 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  v44 = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v45 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(v44 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color",
          a3: 5u,
          a4: 0);
  v46 = v83;
  v84 = (GASValue *)v45;
  ++*((_DWORD *)v45 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v84,
    a4: v46,
    a5: (char *)&psc.m_pfnProxied + 3);
  v47 = (int)v84;
  v13 = (*((_DWORD *)v84 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v47);
  if ( (v43 & 0x1000) != 0 )
  {
    v43 &= ~0x1000u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v43 & 0x800) != 0 )
  {
    v43 &= ~0x800u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (BYTE2(psc.m_pObject[10].__vftable) & 2) != 0 )
  {
    psc.m_pfnProxied = (void (__thiscall *)(IMaterial *, float))SLOWORD(psc.m_pObject[9].__vftable);
    v48 = v43 | 0x2000;
    LOBYTE(v79) = 3;
    v49 = &v79;
    *(float *)&psc.m_pfnProxied = (double)(int)psc.m_pfnProxied / 20.0;
    v80 = *(float *)&psc.m_pfnProxied;
  }
  else
  {
    v48 = v43 | 0x4000;
    v49 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  v50 = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v51 = *(GASStringManager **)(v50 + 636);
  v83 = v49;
  v52 = GASStringManager::CreateConstStringNode(
          this: v51,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CC8.m_Memory.m_nGrowSize,
          a3: 0xDu,
          a4: 0);
  v75 = v83;
  v84 = (GASValue *)v52;
  ++*((_DWORD *)v52 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v84,
    a4: v75,
    a5: (char *)&psc.m_pfnProxied + 3);
  v53 = (int)v84;
  v13 = (*((_DWORD *)v84 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v53);
  if ( (v48 & 0x4000) != 0 )
  {
    v48 &= ~0x4000u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v48 & 0x2000) != 0 )
  {
    v48 &= ~0x2000u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( SBYTE2(psc.m_pObject[10].__vftable) >= 0 )
  {
    v54 = v48 | 0x10000;
    v56 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  else
  {
    v54 = v48 | 0x8000;
    v55 = ((int)psc.m_pObject[10].__vftable & 8) != 0;
    LOBYTE(v79) = 2;
    LOBYTE(v80) = v55;
    v56 = &v79;
  }
  v57 = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v58 = *(GASStringManager **)(v57 + 636);
  v83 = v56;
  v59 = GASStringManager::CreateConstStringNode(
          this: v58,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CC8,
          a3: 7u,
          a4: 0);
  v76 = v83;
  v84 = (GASValue *)v59;
  ++*((_DWORD *)v59 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v84,
    a4: v76,
    a5: (char *)&psc.m_pfnProxied + 3);
  v60 = (int)v84;
  v13 = (*((_DWORD *)v84 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v60);
  if ( (v54 & 0x10000) != 0 )
  {
    v54 &= ~0x10000u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v54 & 0x8000) != 0 )
  {
    v54 &= ~0x8000u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (HIWORD(psc.m_pObject[10].__vftable) & 0x100) != 0 && GString::GetLength(this: (GString *)&psc.m_pObject[4]) != 0 )
  {
    v61 = v54 | 0x60000;
    v62 = GASStringManager::CreateStringNode(
            this: *(GASStringManager **)(m_pfnProxied->style + 636),
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)psc.m_pObject[4].__vftable
                                                                                      & 0xFFFFFFFC)
                                                                                     + 8),
            length: *(_DWORD *)((int)psc.m_pObject[4].__vftable & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)v62 + 2);
    LODWORD(v80) = v62;
    LOBYTE(v79) = 5;
    ++*((_DWORD *)v62 + 2);
    v82 = v62;
    v63 = &v79;
  }
  else
  {
    v61 = v54 | 0x80000;
    v63 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
  }
  v64 = m_pfnProxied->style;
  HIBYTE(psc.m_pfnProxied) = 0;
  v65 = *(GASStringManager **)(v64 + 636);
  v83 = v63;
  v66 = GASStringManager::CreateConstStringNode(
          this: v65,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0,
          a3: 3u,
          a4: 0);
  v77 = v83;
  v84 = (GASValue *)v66;
  ++*((_DWORD *)v66 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, GASValue **, GASValue *, char *))v7->pObject->Locales.Data.Policy.Capacity)(
    a1: v7,
    a2: m_pfnProxied,
    a3: &v84,
    a4: v77,
    a5: (char *)&psc.m_pfnProxied + 3);
  v67 = (int)v84;
  v13 = (*((_DWORD *)v84 + 2))-- == 1;
  if ( v13 )
    GASStringNode::ReleaseNode(a1: v67);
  if ( (v61 & 0x80000) != 0 )
  {
    v61 &= ~0x80000u;
    GASValue::~GASValue(this: v78, a2: (int)v7);
  }
  if ( (v61 & 0x40000) != 0 )
  {
    v61 &= ~0x40000u;
    GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  if ( (v61 & 0x20000) != 0 )
  {
    v68 = (int)v82;
    v61 &= ~0x20000u;
    v13 = (*((_DWORD *)v82 + 2))-- == 1;
    if ( v13 )
      GASStringNode::ReleaseNode(a1: v68);
  }
  if ( *(_BYTE *)(m_pfnProxied->style + 684) == 1 )
  {
    if ( (BYTE2(psc.m_pObject[10].__vftable) & 1) != 0 )
    {
      psc.m_pObject = (IMaterialInternal *)HIBYTE(psc.m_pObject[8].__vftable);
      v69 = v61 | 0x100000;
      LOBYTE(v79) = 3;
      v70 = &v79;
      v80 = (double)(int)psc.m_pObject * 100.0 / 255.0;
    }
    else
    {
      v69 = v61 | 0x200000;
      v70 = GASValue::GASValue(this: v78, v: (tagWNDCLASSW *)&nullVal);
    }
    GASObjectInterface::SetConstMemberRaw(
      this: v7,
      result: m_pfnProxied,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029DF5C,
      a4: (int)v70);
    if ( (v69 & 0x200000) != 0 )
    {
      v69 &= ~0x200000u;
      GASValue::~GASValue(this: v78, a2: (int)v7);
    }
    if ( (v69 & 0x100000) != 0 )
      GASValue::~GASValue(this: &v79, a2: (int)v7);
  }
  GASValue::~GASValue(this: &nullVal, a2: (int)v7);
}

//------------------------------------------------------------------------------
// Address: 0x1011B1B0
// Name: public: void GASTextFormatObject::SetParagraphFormat(class GASStringContext __near *,class GFxTextParagraphFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASTextFormatObject::SetParagraphFormat(
        GPtr<GFxAmpCurrentState> *this,
        int psc,
        CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *psc_4)
{
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ebx
  bool v5; // zf
  char *v6; // edx
  tagWNDCLASSW *v7; // esi
  int v8; // eax
  int v9; // ebx
  GPtr<GFxAmpCurrentState> *v10; // edi
  __int16 v11; // ax
  __int16 v12; // bx
  unsigned int style; // ecx
  struct GASStringNode *ConstStringNode; // eax
  unsigned int v15; // ecx
  CMaterialSystem *v16; // eax
  __int16 v17; // bx
  CMaterialSystem *v18; // eax
  unsigned int v19; // edx
  GASStringManager *v20; // ecx
  struct GASStringNode *v21; // eax
  unsigned int v22; // eax
  __int16 v23; // bx
  CMaterialSystem *v24; // eax
  unsigned int v25; // edx
  GASStringManager *v26; // ecx
  struct GASStringNode *v27; // eax
  unsigned int v28; // eax
  __int16 v29; // bx
  CMaterialSystem *v30; // eax
  unsigned int v31; // edx
  GASStringManager *v32; // ecx
  struct GASStringNode *v33; // eax
  unsigned int v34; // eax
  __int16 v35; // bx
  CMaterialSystem *v36; // eax
  unsigned int v37; // edx
  GASStringManager *v38; // ecx
  struct GASStringNode *v39; // eax
  unsigned int v40; // eax
  __int16 v41; // bx
  CMaterialSystem *v42; // eax
  unsigned int v43; // edx
  GASStringManager *v44; // ecx
  struct GASStringNode *v45; // eax
  unsigned int v46; // eax
  unsigned int v47; // ebx
  CMaterialSystem *v48; // eax
  int v49; // ecx
  int (__thiscall *v50)(int, int, CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **); // edx
  int v51; // eax
  double v52; // st7
  GASValue *v53; // eax
  unsigned int v54; // edx
  GASValue *v55; // ebx
  CMaterialSystem *v56; // eax
  CMaterialSystem *v57; // [esp-8h] [ebp-4Ch]
  CMaterialSystem *v58; // [esp-8h] [ebp-4Ch]
  CMaterialSystem *v59; // [esp-8h] [ebp-4Ch]
  CMaterialSystem *v60; // [esp-8h] [ebp-4Ch]
  CMaterialSystem *v61; // [esp-8h] [ebp-4Ch]
  GMemAddressStub *v62; // [esp+0h] [ebp-44h]
  const char *v63; // [esp+4h] [ebp-40h]
  int v64; // [esp+8h] [ebp-3Ch]
  GASValue v65[4]; // [esp+Ch] [ebp-38h] BYREF
  char v66; // [esp+1Ch] [ebp-28h] BYREF
  double v67; // [esp+20h] [ebp-24h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *nullVal; // [esp+2Ch] [ebp-18h] BYREF
  CMaterialSystem *ptabStops; // [esp+3Ch] [ebp-8h] BYREF
  unsigned int num; // [esp+40h] [ebp-4h] BYREF

  ptabStops = nullptr;
  v3 = psc_4;
  GFxTextParagraphFormat::operator=(result: psc_4);
  v5 = (BYTE6(v3->m_Proxy.m_pfnProxied) & 1) == 0;
  LOBYTE(nullVal) = 1;
  if ( v5 )
  {
    v7 = (tagWNDCLASSW *)psc;
    v10 = this + 4;
    GASObjectInterface::SetConstMemberRaw(
      this: v10,
      result: (tagWNDCLASSW *)psc,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8,
      a4: (int)&nullVal);
  }
  else
  {
    v6 = "left";
    switch ( (WORD3(v3->m_Proxy.m_pfnProxied) >> 9) & 3 )
    {
      case 1:
        v6 = "right";
        break;
      case 2:
        v6 = "justify";
        break;
      case 3:
        v6 = "center";
        break;
      default:
        break;
    }
    v7 = (tagWNDCLASSW *)psc;
    GASStringManager::CreateStringNode(
      this: *(GASStringManager **)(*(_DWORD *)psc + 636),
      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v6);
    v9 = v8;
    ++*(_DWORD *)(v8 + 8);
    v10 = this + 4;
    v66 = 5;
    LODWORD(v67) = v8;
    ++*(_DWORD *)(v8 + 8);
    GASObjectInterface::SetConstMemberRaw(
      this: v10,
      result: v7,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8,
      a4: (int)&v66);
    GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
    v5 = (*(_DWORD *)(v9 + 8))-- == 1;
    if ( v5 )
      GASStringNode::ReleaseNode(a1: v9);
    v3 = psc_4;
  }
  v11 = WORD3(v3->m_Proxy.m_pfnProxied);
  if ( (v11 & 0x80u) == 0 )
  {
    v12 = 2;
    num = (unsigned int)GASValue::GASValue(this: v65, v: (tagWNDCLASSW *)&nullVal);
  }
  else
  {
    v12 = 1;
    v66 = 2;
    LOBYTE(v67) = v11 < 0;
    num = (unsigned int)&v66;
  }
  style = v7->style;
  HIBYTE(psc) = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(style + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"bullet",
                      a3: 6u,
                      a4: 0);
  v15 = num;
  ptabStops = (CMaterialSystem *)ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, CMaterialSystem **, unsigned int, char *))v10->pObject->Locales.Data.Policy.Capacity)(
    a1: v10,
    a2: v7,
    a3: &ptabStops,
    a4: v15,
    a5: (char *)&psc + 3);
  v16 = ptabStops;
  v5 = (*(_DWORD *)&ptabStops->m_bStereoBoolsInitialized)-- == 1;
  if ( v5 )
    GASStringNode::ReleaseNode(a1: (int)v16);
  if ( (v12 & 2) != 0 )
  {
    v12 &= ~2u;
    GASValue::~GASValue(this: v65, a2: (int)v10);
  }
  if ( (v12 & 1) != 0 )
  {
    v12 &= ~1u;
    GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
  }
  if ( (BYTE6(psc_4->m_Proxy.m_pfnProxied) & 2) != 0 )
  {
    psc = LOWORD(psc_4->m_iRefs);
    v17 = v12 | 4;
    v66 = 3;
    v18 = (CMaterialSystem *)&v66;
    v67 = (double)psc;
  }
  else
  {
    v17 = v12 | 8;
    v18 = (CMaterialSystem *)GASValue::GASValue(this: v65, v: (tagWNDCLASSW *)&nullVal);
  }
  v19 = v7->style;
  HIBYTE(psc) = 0;
  v20 = *(GASStringManager **)(v19 + 636);
  ptabStops = v18;
  v21 = GASStringManager::CreateConstStringNode(
          this: v20,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"blockIndent",
          a3: 0xBu,
          a4: 0);
  v57 = ptabStops;
  num = (unsigned int)v21;
  ++*((_DWORD *)v21 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, unsigned int *, CMaterialSystem *, char *))v10->pObject->Locales.Data.Policy.Capacity)(
    a1: v10,
    a2: v7,
    a3: &num,
    a4: v57,
    a5: (char *)&psc + 3);
  v22 = num;
  v5 = (*(_DWORD *)(num + 8))-- == 1;
  if ( v5 )
    GASStringNode::ReleaseNode(a1: v22);
  if ( (v17 & 8) != 0 )
  {
    v17 &= ~8u;
    GASValue::~GASValue(this: v65, a2: (int)v10);
  }
  if ( (v17 & 4) != 0 )
  {
    v17 &= ~4u;
    GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
  }
  if ( (BYTE6(psc_4->m_Proxy.m_pfnProxied) & 4) != 0 )
  {
    psc = SHIWORD(psc_4->m_iRefs);
    v23 = v17 | 0x10;
    v66 = 3;
    v24 = (CMaterialSystem *)&v66;
    v67 = (double)psc;
  }
  else
  {
    v23 = v17 | 0x20;
    v24 = (CMaterialSystem *)GASValue::GASValue(this: v65, v: (tagWNDCLASSW *)&nullVal);
  }
  v25 = v7->style;
  HIBYTE(psc) = 0;
  v26 = *(GASStringManager **)(v25 + 636);
  ptabStops = v24;
  v27 = GASStringManager::CreateConstStringNode(
          this: v26,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"indent",
          a3: 6u,
          a4: 0);
  v58 = ptabStops;
  num = (unsigned int)v27;
  ++*((_DWORD *)v27 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, unsigned int *, CMaterialSystem *, char *))v10->pObject->Locales.Data.Policy.Capacity)(
    a1: v10,
    a2: v7,
    a3: &num,
    a4: v58,
    a5: (char *)&psc + 3);
  v28 = num;
  v5 = (*(_DWORD *)(num + 8))-- == 1;
  if ( v5 )
    GASStringNode::ReleaseNode(a1: v28);
  if ( (v23 & 0x20) != 0 )
  {
    v23 &= ~0x20u;
    GASValue::~GASValue(this: v65, a2: (int)v10);
  }
  if ( (v23 & 0x10) != 0 )
  {
    v23 &= ~0x10u;
    GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
  }
  if ( (BYTE6(psc_4->m_Proxy.m_pfnProxied) & 8) != 0 )
  {
    psc = SLOWORD(psc_4->m_Proxy.m_pfnProxied);
    v29 = v23 | 0x40;
    v66 = 3;
    v30 = (CMaterialSystem *)&v66;
    v67 = (double)psc;
  }
  else
  {
    v29 = v23 | 0x80;
    v30 = (CMaterialSystem *)GASValue::GASValue(this: v65, v: (tagWNDCLASSW *)&nullVal);
  }
  v31 = v7->style;
  HIBYTE(psc) = 0;
  v32 = *(GASStringManager **)(v31 + 636);
  ptabStops = v30;
  v33 = GASStringManager::CreateConstStringNode(
          this: v32,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68,
          a3: 7u,
          a4: 0);
  v59 = ptabStops;
  num = (unsigned int)v33;
  ++*((_DWORD *)v33 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, unsigned int *, CMaterialSystem *, char *))v10->pObject->Locales.Data.Policy.Capacity)(
    a1: v10,
    a2: v7,
    a3: &num,
    a4: v59,
    a5: (char *)&psc + 3);
  v34 = num;
  v5 = (*(_DWORD *)(num + 8))-- == 1;
  if ( v5 )
    GASStringNode::ReleaseNode(a1: v34);
  if ( (v29 & 0x80u) != 0 )
  {
    v29 &= ~0x80u;
    GASValue::~GASValue(this: v65, a2: (int)v10);
  }
  if ( (v29 & 0x40) != 0 )
  {
    v29 &= ~0x40u;
    GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
  }
  if ( (BYTE6(psc_4->m_Proxy.m_pfnProxied) & 0x10) != 0 )
  {
    psc = WORD1(psc_4->m_Proxy.m_pfnProxied);
    v35 = v29 | 0x100;
    v66 = 3;
    v36 = (CMaterialSystem *)&v66;
    v67 = (double)psc;
  }
  else
  {
    v35 = v29 | 0x200;
    v36 = (CMaterialSystem *)GASValue::GASValue(this: v65, v: (tagWNDCLASSW *)&nullVal);
  }
  v37 = v7->style;
  HIBYTE(psc) = 0;
  v38 = *(GASStringManager **)(v37 + 636);
  ptabStops = v36;
  v39 = GASStringManager::CreateConstStringNode(
          this: v38,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"leftMargin",
          a3: 0xAu,
          a4: 0);
  v60 = ptabStops;
  num = (unsigned int)v39;
  ++*((_DWORD *)v39 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, unsigned int *, CMaterialSystem *, char *))v10->pObject->Locales.Data.Policy.Capacity)(
    a1: v10,
    a2: v7,
    a3: &num,
    a4: v60,
    a5: (char *)&psc + 3);
  v40 = num;
  v5 = (*(_DWORD *)(num + 8))-- == 1;
  if ( v5 )
    GASStringNode::ReleaseNode(a1: v40);
  if ( (v35 & 0x200) != 0 )
  {
    v35 &= ~0x200u;
    GASValue::~GASValue(this: v65, a2: (int)v10);
  }
  if ( (v35 & 0x100) != 0 )
  {
    v35 &= ~0x100u;
    GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
  }
  if ( (BYTE6(psc_4->m_Proxy.m_pfnProxied) & 0x20) != 0 )
  {
    psc = WORD2(psc_4->m_Proxy.m_pfnProxied);
    v41 = v35 | 0x400;
    v66 = 3;
    v42 = (CMaterialSystem *)&v66;
    v67 = (double)psc;
  }
  else
  {
    v41 = v35 | 0x800;
    v42 = (CMaterialSystem *)GASValue::GASValue(this: v65, v: (tagWNDCLASSW *)&nullVal);
  }
  v43 = v7->style;
  HIBYTE(psc) = 0;
  v44 = *(GASStringManager **)(v43 + 636);
  ptabStops = v42;
  v45 = GASStringManager::CreateConstStringNode(
          this: v44,
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"rightMargin",
          a3: 0xBu,
          a4: 0);
  v61 = ptabStops;
  num = (unsigned int)v45;
  ++*((_DWORD *)v45 + 2);
  ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, unsigned int *, CMaterialSystem *, char *))v10->pObject->Locales.Data.Policy.Capacity)(
    a1: v10,
    a2: v7,
    a3: &num,
    a4: v61,
    a5: (char *)&psc + 3);
  v46 = num;
  v5 = (*(_DWORD *)(num + 8))-- == 1;
  if ( v5 )
    GASStringNode::ReleaseNode(a1: v46);
  if ( (v41 & 0x800) != 0 )
  {
    v41 &= ~0x800u;
    GASValue::~GASValue(this: v65, a2: (int)v10);
  }
  if ( (v41 & 0x400) != 0 )
    GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
  if ( (BYTE6(psc_4->m_Proxy.m_pfnProxied) & 0x40) != 0 )
  {
    v47 = 0;
    num = 0;
    GFxTextParagraphFormat::GetTabStops(
      this: psc_4,
      pnum: (const CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&num);
    ptabStops = v48;
    v49 = *(_DWORD *)(v7->style + 656);
    v50 = *(int (__thiscall **)(int, int, CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **))(*(_DWORD *)v49 + 40);
    wcscpy((wchar_t *)&psc_4, L"Ń");
    v51 = v50(a1: v49, a2: 76, a3: &psc_4);
    if ( v51 != 0 )
      psc = GASArrayObject::GASArrayObject(a1: v51, psc: (GASGlobalContext **)v7, psc_4: v62, psc_8: v63, psc_12: v64);
    else
      psc = 0;
    GASArrayObject::Resize(a1: (GRenderer::CachedData *)psc, size: num, a3: (GMemoryHeap *)v62);
    if ( num != 0 )
    {
      do
      {
        v52 = (double)*((unsigned int *)&ptabStops->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable
                      + v47);
        v66 = 3;
        v67 = v52;
        GASArrayObject::SetElement(this: (GASArrayObject *)psc, a2: v47, v: (tagWNDCLASSW *)&v66);
        GASValue::~GASValue(this: (GASValue *)&v66, a2: (int)v10);
        ++v47;
      }
      while ( v47 < num );
    }
    v53 = GASValue::GASValue(this: v65, a2: (struct GASObject *)psc);
    v54 = v7->style;
    HIBYTE(psc_4) = 0;
    v55 = v53;
    ptabStops = (CMaterialSystem *)GASStringManager::CreateConstStringNode(
                                     this: *(GASStringManager **)(v54 + 636),
                                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0.m_pElements,
                                     a3: 8u,
                                     a4: 0);
    ++*(_DWORD *)&ptabStops->m_bStereoBoolsInitialized;
    ((void (__thiscall *)(GPtr<GFxAmpCurrentState> *, tagWNDCLASSW *, CMaterialSystem **, GASValue *, char *))v10->pObject->Locales.Data.Policy.Capacity)(
      a1: v10,
      a2: v7,
      a3: &ptabStops,
      a4: v55,
      a5: (char *)&psc_4 + 3);
    v56 = ptabStops;
    v5 = (*(_DWORD *)&ptabStops->m_bStereoBoolsInitialized)-- == 1;
    if ( v5 )
      GASStringNode::ReleaseNode(a1: (int)v56);
    GASValue::~GASValue(this: v65, a2: (int)v10);
    if ( psc != 0 )
    {
      GRefCountBaseGC<323>::Release(a1: psc, a2: (int)v10);
      GASValue::~GASValue(this: &nullVal, a2: (int)v10);
      return;
    }
  }
  else
  {
    GASObjectInterface::SetConstMemberRaw(
      this: v10,
      result: v7,
      a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0.m_pElements,
      a4: (int)&nullVal);
  }
  GASValue::~GASValue(this: &nullVal, a2: (int)v10);
}

//------------------------------------------------------------------------------
// Address: 0x1011B780
// Name: public: static void GASTextFormatProto::GetTextExtent(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextFormatProto::GetTextExtent(int a1@<ebx>, long double a2@<st0>, int a3)
{
  const struct GASFnCall *v3; // edi
  GASValue *v4; // esi
  int v5; // ebx
  int v6; // ebx
  GRefCountNTSImpl *v7; // esi
  int v8; // ecx
  int (__thiscall *v9)(int, int, int *, int); // eax
  GASObject *v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // ecx
  int (__thiscall *v13)(int, int); // edx
  struct GFxMovieRoot *MovieRoot; // eax
  GFxValue *TextAllocator; // eax
  GFxTextDocView *v16; // esi
  GASValue *v17; // eax
  int v18; // eax
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v19; // eax
  long double v20; // st7
  void *v21; // ebx
  long double v22; // st7
  long double v23; // st7
  _DWORD *v24; // eax
  struct GFxFontHandle *FontHandle; // eax
  double v26; // st6
  int v27; // eax
  double v28; // st6
  double v29; // st5
  tagWNDCLASSW *v30; // ecx
  tagWNDCLASSW *v31; // ecx
  int v32; // ebx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v33; // edi
  bool v34; // zf
  int v35; // eax
  tagWNDCLASSW *v36; // [esp-10h] [ebp-134h]
  tagWNDCLASSW *v37; // [esp-10h] [ebp-134h]
  tagWNDCLASSW *v38; // [esp-10h] [ebp-134h]
  tagWNDCLASSW *v39; // [esp-10h] [ebp-134h]
  struct GFxFontManager *v40; // [esp-Ch] [ebp-130h]
  _SERVICE_STATUS *v41; // [esp-8h] [ebp-12Ch]
  MaterialVarFlags_t v43; // [esp-4h] [ebp-128h]
  unsigned int v44; // [esp-4h] [ebp-128h]
  unsigned int v45; // [esp-4h] [ebp-128h]
  unsigned int v46; // [esp-4h] [ebp-128h]
  unsigned int v47; // [esp-4h] [ebp-128h]
  MaterialVarFlags_t v48; // [esp-4h] [ebp-128h]
  bool v49; // [esp+0h] [ebp-124h]
  bool v50; // [esp+0h] [ebp-124h]
  bool v51; // [esp+0h] [ebp-124h]
  CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> v52; // [esp+8h] [ebp-11Ch] BYREF
  CMaterial v53; // [esp+34h] [ebp-F0h] BYREF
  long double v54; // [esp+CCh] [ebp-58h]
  GRefCountNTSImpl *v55; // [esp+D8h] [ebp-4Ch]
  int v56[2]; // [esp+DCh] [ebp-48h] BYREF
  double v57; // [esp+E4h] [ebp-40h]
  CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v58; // [esp+ECh] [ebp-38h] BYREF
  GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *v59[2]; // [esp+114h] [ebp-10h]
  MaterialVarFlags_t v60; // [esp+11Ch] [ebp-8h] BYREF
  char v61; // [esp+123h] [ebp-1h]

  v3 = (const struct GASFnCall *)a3;
  v4 = *(GASValue **)(a3 + 4);
  GASValue::DropRefs(this: v4, a2: a3);
  *(_BYTE *)v4 = 0;
  if ( *((_DWORD *)v3 + 7) != 0 )
  {
    if ( !GASFnCall::CheckThisPtr(this: v3, type: 0x1Eu) )
    {
      GASFnCall::ThisPtrError(this: (GASFnCall *)v3, a2: "TextFormat", a3: nullptr, a4: 0);
      return;
    }
    v5 = *((_DWORD *)v3 + 2);
    v6 = v5 != 0 ? v5 - 16 : 0;
    v7 = *(GRefCountNTSImpl **)(*((_DWORD *)v3 + 6) + 116);
    v55 = v7;
    if ( v7 != nullptr )
    {
      ++v7->RefCount;
      v8 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 6) + 120) + 656);
      v9 = *(int (__thiscall **)(int, int, int *, int))(*(_DWORD *)v8 + 40);
      a3 = 323;
      v10 = (GASObject *)v9(a1: v8, a2: 52, &a3, a4: a1);
      if ( v10 != nullptr )
        *((_DWORD *)&v58.m_Proxy.m_pObject + 1) = GASObject::GASObject(
                                                    this: v10,
                                                    a2: *((struct GASEnvironment **)v3 + 6));
      else
        *((_DWORD *)&v58.m_Proxy.m_pObject + 1) = 0;
      v60 = *((_DWORD *)v3 + 6);
      v11 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 0);
      GASValue::ToStringImpl(
        this: v11,
        a2: (int *)&v58.m_Proxy.m_pfnProxied + 2,
        a3: (tagRID_DEVICE_INFO_KEYBOARD *)v60,
        precision: -1,
        debug: false);
      v12 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 6) + 120) + 656);
      v13 = *(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 40);
      v60 = MATERIAL_VAR_NO_DRAW|MATERIAL_VAR_SELFILLUM|MATERIAL_VAR_ALPHATEST;
      v59[1] = (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v13(a1: v12, a2: 340);
      if ( v59[1] != nullptr )
      {
        v40 = (struct GFxFontManager *)((int (__thiscall *)(GRefCountNTSImpl *))v7->__vftable[24].dtr_GRefCountImplCore)(a1: v7);
        MovieRoot = GASEnvironment::GetMovieRoot(this: *((GASEnvironment **)v3 + 6));
        TextAllocator = (GFxValue *)GFxMovieRoot::GetTextAllocator(this: (int)MovieRoot);
        v16 = GFxTextDocView::GFxTextDocView(this: v59[1], pallocator: TextAllocator, a3: v40, a4: nullptr);
      }
      else
      {
        v16 = nullptr;
      }
      *(_BYTE *)(*((_DWORD *)v16 + 2) + 32) |= 2u;
      GFxTextDocView::SetAutoSizeX(this: v16);
      GFxTextDocView::SetAutoSizeY(this: v16);
      if ( *(_BYTE *)(*((_DWORD *)v3 + 6) + 124) >= 7u && *((int *)v3 + 7) >= 2 )
      {
        v41 = *((_SERVICE_STATUS **)v3 + 6);
        v17 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 1);
        *(double *)((char *)&v58.m_Proxy.m_pfnProxied + 12) = GASValue::ToNumber(
                                                                this: v17,
                                                                a2: (int)v3,
                                                                a3: a2,
                                                                result: v41);
        *((_BYTE *)v16 + 334) &= ~1u;
        GFxTextDocView::SetWordWrap(this: v16);
        *(float *)&v59[1] = *(double *)((char *)&v58.m_Proxy.m_pfnProxied + 12);
        *((float *)&v58.m_Proxy.m_pfnProxied + 3) = *(float *)&v59[1] * 20.0;
        *(float *)v56 = 0.0;
        *(float *)&v56[1] = 0.0;
        *(float *)&v57 = *((float *)&v58.m_Proxy.m_pfnProxied + 3) + 0.0;
        a2 = 0.0 + 0.0;
        *((float *)&v57 + 1) = 0.0 + 0.0;
        GFxTextDocView::SetViewRect(this: v16, a2: (int)v56, a3: 1);
      }
      *((_BYTE *)v16 + 334) |= 4u;
      GFxTextFormat::GFxTextFormat(
        this: (GFxTextFormat *)&v53.m_Name,
        a2: *(struct GMemoryHeap **)(*(_DWORD *)(*((_DWORD *)v3 + 6) + 120) + 656));
      v58.m_nUserID = 1;
      v58.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&GFxTextParagraphFormat::`vftable';
      memset(&v58.CRefCountServiceDestruct<CRefST>, 0, 16);
      GFxTextFormat::InitByDefaultValues(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v53.m_Name);
      GFxTextParagraphFormat::InitByDefaultValues(this: (CMaterial *)&v58, a2: (MaterialVarFlags_t)&v60, a3: v49);
      v18 = GFxTextFormat::Merge(a1: &v53.m_Name, a2: &v52, a3: v6 + 52);
      GFxTextFormat::operator=(this: (int)&v53.m_Name, __that: v18);
      GFxTextFormat::~GFxTextFormat(this: &v52);
      GFxTextParagraphFormat::Merge(this: &v58);
      GFxTextParagraphFormat::operator=(result: v19);
      v53.__vftable = (CMaterial_vtbl *)&GFxTextParagraphFormat::`vftable';
      GFxTextParagraphFormat::FreeTabStops(this: &v53, a2: v43, a3: v50);
      GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v53);
      GFxStyledText::SetDefaultTextFormat(this: *((CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)v16 + 2));
      GFxStyledText::SetDefaultParagraphFormat(this: *((CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > **)v16 + 2));
      GFxTextDocView::SetText(this: v16, putf8String: *(const char **)DWORD2(v58.m_Proxy.m_pfnProxied), a3: 0xFFFFFFFF);
      GFxTextDocView::Format(this: v16);
      GFxTextDocView::GetTextWidth(
        this: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v16,
        a2: v44);
      v20 = (a2 + 80.0) / 20.0;
      v21 = (void *)(*((_DWORD *)&v58.m_Proxy.m_pObject + 1) + 16);
      v36 = (tagWNDCLASSW *)(*((_DWORD *)v3 + 6) + 120);
      LOBYTE(v53.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.z) = 3;
      v54 = v20;
      GASObjectInterface::SetConstMemberRaw(
        this: (void *)(*((_DWORD *)&v58.m_Proxy.m_pObject + 1) + 16),
        result: v36,
        a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"textFieldWidth",
        a4: (int)&v53.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.z);
      GASValue::~GASValue(
        this: (GASValue *)&v53.m_QueueFriendlyVersion.m_vColorModulationOnQueueCompletion.z,
        a2: (int)v3);
      GFxTextDocView::GetTextHeight(
        this: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v16,
        a2: v45);
      v22 = (v20 + 80.0) / 20.0;
      v37 = (tagWNDCLASSW *)(*((_DWORD *)v3 + 6) + 120);
      LOBYTE(v53.m_Reflectivity.z) = 3;
      *(double *)&v53.m_ChangeID = v22;
      GASObjectInterface::SetConstMemberRaw(
        this: v21,
        result: v37,
        a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5E40.m_pElements,
        a4: (int)&v53.m_Reflectivity.z);
      GASValue::~GASValue(this: (GASValue *)&v53.m_Reflectivity.z, a2: (int)v3);
      GFxTextDocView::GetTextWidth(
        this: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v16,
        a2: v46);
      v23 = v22 / 20.0;
      v38 = (tagWNDCLASSW *)(*((_DWORD *)v3 + 6) + 120);
      BYTE4(v53.m_ShaderRenderState.m_VertexUsage) = 3;
      *(double *)&v53.m_ShaderRenderState.m_pSnapshots = v23;
      GASObjectInterface::SetConstMemberRaw(
        this: v21,
        result: v38,
        a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_pElements,
        a4: (int)&v53.m_ShaderRenderState.m_VertexUsage + 4);
      GASValue::~GASValue(this: (GASValue *)&v53.m_ShaderRenderState.m_VertexUsage + 1, a2: (int)v3);
      GFxTextDocView::GetTextHeight(
        this: (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)v16,
        a2: v47);
      v39 = (tagWNDCLASSW *)(*((_DWORD *)v3 + 6) + 120);
      v53.m_bShouldReloadFromWhitelist = 3;
      *(double *)&v53.m_representativeTexture = v23 / 20.0;
      GASObjectInterface::SetConstMemberRaw(
        this: v21,
        result: v39,
        a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68.m_Memory.m_nGrowSize,
        a4: (int)&v53.m_bShouldReloadFromWhitelist);
      GASValue::~GASValue(this: (GASValue *)&v53.m_bShouldReloadFromWhitelist, a2: (int)v3);
      HIBYTE(a3) = (v53.m_ShaderRenderState.m_VertexUsage & 2) != 0;
      v61 = v53.m_ShaderRenderState.m_VertexUsage & 1;
      LOBYTE(v24) = GFxTextFormat::GetFontList();
      FontHandle = GFxFontManager::CreateFontHandle(
                     this: *((CDefaultClientRenderable **)v16 + 3),
                     string: (unsigned __int8 *)((*v24 & 0xFFFFFFFC) + 8),
                     matchFontFlags: (v61 != 0 ? 2 : 0) | (HIBYTE(a3) != 0) | 0x10,
                     allowListOfFonts: true,
                     searchInfo: 0);
      v26 = 0.0;
      v60 = (MaterialVarFlags_t)FontHandle;
      *(double *)((char *)&v58.m_Proxy.m_pfnProxied + 12) = 0.0;
      if ( FontHandle != nullptr )
      {
        v27 = *(_DWORD *)(*((_DWORD *)FontHandle + 7) + 12);
        v28 = *(float *)(v27 + 8);
        v29 = *(float *)(v27 + 12);
        *(double *)((char *)&v58.m_Proxy.m_pfnProxied + 12) = v29;
        if ( 0.0 != v28 )
        {
LABEL_21:
          if ( v29 == 0.0 )
            *(double *)((char *)&v58.m_Proxy.m_pfnProxied + 12) = 1024.0 - v28;
          LOBYTE(v53.m_VMTIncludes.m_Memory.m_nAllocationCount) = 3;
          *(float *)&a3 = (double)HIWORD(v53.m_ShaderRenderState.m_VertexFormat) / 20.0;
          v57 = *(float *)&a3 * 20.0 * 0.0009765625;
          *(_QWORD *)v59 = (__int64)(v28 * v57 / 20.0);
          v30 = *((tagWNDCLASSW **)v3 + 6);
          *(double *)&v53.m_VMTIncludes.m_Memory.m_nGrowSize = (double)(unsigned int)v59[0];
          GASObjectInterface::SetConstMemberRaw(
            this: v21,
            result: v30 + 3,
            a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"ascent",
            a4: (int)&v53.m_VMTIncludes.m_Memory.m_nAllocationCount);
          GASValue::~GASValue(this: (GASValue *)&v53.m_VMTIncludes.m_Memory.m_nAllocationCount, a2: (int)v3);
          LOBYTE(v53.m_QueueFriendlyVersion.m_pRealTimeVersion) = 3;
          v59[1] = (GArrayBase<GArrayData<unsigned long,GAllocatorLH<unsigned long,2>,GArrayDefaultPolicy> > *)(HIWORD(a3) | 0xC00);
          *(_QWORD *)&v57 = (__int64)(v57 * *(double *)((char *)&v58.m_Proxy.m_pfnProxied + 12) / 20.0);
          v31 = *((tagWNDCLASSW **)v3 + 6);
          *(double *)&v53.m_QueueFriendlyVersion.m_fAlphaModulationOnQueueCompletion = (double)LODWORD(v57);
          GASObjectInterface::SetConstMemberRaw(
            this: v21,
            result: v31 + 3,
            a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"descent",
            a4: (int)&v53.m_QueueFriendlyVersion.m_pRealTimeVersion);
          GASValue::~GASValue(this: (GASValue *)&v53.m_QueueFriendlyVersion.m_pRealTimeVersion, a2: (int)v3);
          v32 = *((_DWORD *)&v58.m_Proxy.m_pObject + 1);
          GASValue::SetAsObject(this: *((GASValue **)v3 + 1), a2: *((struct GASObject **)&v58.m_Proxy.m_pObject + 1));
          v33 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v60;
          if ( v60 != 0 )
          {
            v34 = (*(_DWORD *)v60)-- == 1;
            if ( v34 )
            {
              GFxFontHandle::~GFxFontHandle(this: v33);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v33);
            }
          }
          v58.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor0<CMaterial *,void (__thiscall CMaterial::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&GFxTextParagraphFormat::`vftable';
          GFxTextParagraphFormat::FreeTabStops(this: (CMaterial *)&v58, a2: v48, a3: v51);
          GRefCountImplCore::~GRefCountImplCore(this: (IShaderAPI *)&v58);
          GFxTextFormat::~GFxTextFormat(this: (CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *)&v53.m_Name);
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v16);
          v35 = DWORD2(v58.m_Proxy.m_pfnProxied);
          v34 = (*(_DWORD *)(DWORD2(v58.m_Proxy.m_pfnProxied) + 8))-- == 1;
          if ( v34 )
            GASStringNode::ReleaseNode(a1: v35);
          if ( v32 != 0 )
            GRefCountBaseGC<323>::Release(a1: v32, a2: (int)v33);
          GRefCountNTSImpl::Release(this: v55);
          return;
        }
        v26 = v29;
      }
      v29 = v26;
      v28 = 960.0;
      goto LABEL_21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011BD00
// Name: public: static void GASTextFormatCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASTextFormatCtorFunction::GlobalCtor(int a1@<edi>, int fn)
{
  int v2; // esi
  int v3; // eax
  struct GASObject *v4; // edi
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // eax
  GASTextFormatObject *v7; // eax
  GASTextFormatObject *v8; // eax
  int v9; // ebx
  int v10; // edx
  struct GASObject *v11; // edi
  struct GASValue *v12; // eax
  int v13; // eax
  bool v14; // zf
  int v15; // eax
  struct GASValue *v16; // eax
  int v17; // eax
  int v18; // ecx
  struct GASValue *v19; // eax
  int v20; // eax
  int v21; // ecx
  struct GASValue *v22; // eax
  int v23; // eax
  int v24; // ecx
  struct GASValue *v25; // eax
  int v26; // eax
  int v27; // ecx
  struct GASValue *v28; // eax
  int v29; // eax
  int v30; // ecx
  struct GASValue *v31; // eax
  int v32; // eax
  int v33; // ecx
  struct GASValue *v34; // eax
  int v35; // eax
  int v36; // ecx
  struct GASValue *v37; // eax
  int v38; // eax
  int v39; // ecx
  struct GASValue *v40; // eax
  int v41; // eax
  int v42; // ecx
  struct GASValue *v43; // eax
  int v44; // eax
  int v45; // ecx
  struct GASValue *v46; // eax
  int v47; // eax
  int v48; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ebx
  struct GASValue *v50; // eax
  int v51; // eax
  CFunctor **p_elem; // [esp+8h] [ebp-Ch]
  CFunctor **v53; // [esp+8h] [ebp-Ch]
  CFunctor **v54; // [esp+8h] [ebp-Ch]
  CFunctor **v55; // [esp+8h] [ebp-Ch]
  CFunctor **v56; // [esp+8h] [ebp-Ch]
  CFunctor **v57; // [esp+8h] [ebp-Ch]
  CFunctor **v58; // [esp+8h] [ebp-Ch]
  CFunctor **v59; // [esp+8h] [ebp-Ch]
  CFunctor **v60; // [esp+8h] [ebp-Ch]
  CFunctor **v61; // [esp+8h] [ebp-Ch]
  CFunctor **v62; // [esp+8h] [ebp-Ch]
  CFunctor **v63; // [esp+8h] [ebp-Ch]
  struct GASStringNode *ConstStringNode; // [esp+Ch] [ebp-8h] BYREF
  struct GASObject *v65; // [esp+10h] [ebp-4h]

  v2 = fn;
  if ( *(_DWORD *)(fn + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fn + 8) + 8))(a1: *(_DWORD *)(fn + 8)) == 30
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v2 + 8) + 64))(a1: *(_DWORD *)(v2 + 8)) == 0 )
  {
    v3 = *(_DWORD *)(v2 + 8);
    if ( v3 != 0 )
    {
      v4 = (struct GASObject *)(v3 - 16);
      if ( v3 != 16 )
        v4[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v4[1].pNode->pNext + 1) & 0x8FFFFFFF);
      v65 = (struct GASObject *)(v3 - 16);
    }
    else
    {
      v4 = nullptr;
      v65 = nullptr;
    }
  }
  else
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 24) + 120) + 656);
    v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
    fn = 323;
    v7 = (GASTextFormatObject *)v6(a1: v5, a2: 120, a3: &fn);
    if ( v7 != nullptr )
      v8 = GASTextFormatObject::GASTextFormatObject(this: v7, a2: a1, a3: *(struct GASEnvironment **)(v2 + 24));
    else
      v8 = nullptr;
    v65 = (struct GASObject *)v8;
    v4 = (struct GASObject *)v8;
  }
  if ( *(int *)(v2 + 28) >= 1 )
  {
    v9 = *(_DWORD *)(v2 + 24);
    v10 = *(_DWORD *)(v9 + 120);
    HIBYTE(fn) = 0;
    v11 = v4 + 2;
    ConstStringNode = GASStringManager::CreateConstStringNode(
                        this: *(GASStringManager **)(v10 + 636),
                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029050C,
                        a3: 4u,
                        a4: 0);
    ++*((_DWORD *)ConstStringNode + 2);
    p_elem = &v11->pNode[1].elem;
    v12 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
    ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*p_elem)(
      a1: v11,
      a2: *(_DWORD *)(v2 + 24),
      a3: &ConstStringNode,
      a4: v12,
      a5: (char *)&fn + 3);
    v13 = (int)ConstStringNode;
    v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
    if ( v14 )
      GASStringNode::ReleaseNode(a1: v13);
    if ( *(int *)(v2 + 28) >= 2 )
    {
      v15 = *(_DWORD *)(v9 + 120);
      HIBYTE(fn) = 0;
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(v15 + 636),
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"size",
                          a3: 4u,
                          a4: 0);
      ++*((_DWORD *)ConstStringNode + 2);
      v53 = &v11->pNode[1].elem;
      v16 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 1);
      ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v53)(
        a1: v11,
        a2: *(_DWORD *)(v2 + 24),
        a3: &ConstStringNode,
        a4: v16,
        a5: (char *)&fn + 3);
      v17 = (int)ConstStringNode;
      v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
      if ( v14 )
        GASStringNode::ReleaseNode(a1: v17);
      if ( *(int *)(v2 + 28) >= 3 )
      {
        v18 = *(_DWORD *)(v9 + 120);
        HIBYTE(fn) = 0;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(v18 + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color",
                            a3: 5u,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        v54 = &v11->pNode[1].elem;
        v19 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 2);
        ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v54)(
          a1: v11,
          a2: *(_DWORD *)(v2 + 24),
          a3: &ConstStringNode,
          a4: v19,
          a5: (char *)&fn + 3);
        v20 = (int)ConstStringNode;
        v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
        if ( v14 )
          GASStringNode::ReleaseNode(a1: v20);
        if ( *(int *)(v2 + 28) >= 4 )
        {
          v21 = *(_DWORD *)(v9 + 120);
          HIBYTE(fn) = 0;
          ConstStringNode = GASStringManager::CreateConstStringNode(
                              this: *(GASStringManager **)(v21 + 636),
                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC.m_Memory.m_nGrowSize,
                              a3: 4u,
                              a4: 0);
          ++*((_DWORD *)ConstStringNode + 2);
          v55 = &v11->pNode[1].elem;
          v22 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 3);
          ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v55)(
            a1: v11,
            a2: *(_DWORD *)(v2 + 24),
            a3: &ConstStringNode,
            a4: v22,
            a5: (char *)&fn + 3);
          v23 = (int)ConstStringNode;
          v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
          if ( v14 )
            GASStringNode::ReleaseNode(a1: v23);
          if ( *(int *)(v2 + 28) >= 5 )
          {
            v24 = *(_DWORD *)(v9 + 120);
            HIBYTE(fn) = 0;
            ConstStringNode = GASStringManager::CreateConstStringNode(
                                this: *(GASStringManager **)(v24 + 636),
                                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102904EC,
                                a3: 6u,
                                a4: 0);
            ++*((_DWORD *)ConstStringNode + 2);
            v56 = &v11->pNode[1].elem;
            v25 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 4);
            ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v56)(
              a1: v11,
              a2: *(_DWORD *)(v2 + 24),
              a3: &ConstStringNode,
              a4: v25,
              a5: (char *)&fn + 3);
            v26 = (int)ConstStringNode;
            v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
            if ( v14 )
              GASStringNode::ReleaseNode(a1: v26);
            if ( *(int *)(v2 + 28) >= 6 )
            {
              v27 = *(_DWORD *)(v9 + 120);
              HIBYTE(fn) = 0;
              ConstStringNode = GASStringManager::CreateConstStringNode(
                                  this: *(GASStringManager **)(v27 + 636),
                                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0.m_Memory.m_nAllocationCount,
                                  a3: 9u,
                                  a4: 0);
              ++*((_DWORD *)ConstStringNode + 2);
              v57 = &v11->pNode[1].elem;
              v28 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 5);
              ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v57)(
                a1: v11,
                a2: *(_DWORD *)(v2 + 24),
                a3: &ConstStringNode,
                a4: v28,
                a5: (char *)&fn + 3);
              v29 = (int)ConstStringNode;
              v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
              if ( v14 )
                GASStringNode::ReleaseNode(a1: v29);
              if ( *(int *)(v2 + 28) >= 7 )
              {
                v30 = *(_DWORD *)(v9 + 120);
                HIBYTE(fn) = 0;
                ConstStringNode = GASStringManager::CreateConstStringNode(
                                    this: *(GASStringManager **)(v30 + 636),
                                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5CE0,
                                    a3: 3u,
                                    a4: 0);
                ++*((_DWORD *)ConstStringNode + 2);
                v58 = &v11->pNode[1].elem;
                v31 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 6);
                ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v58)(
                  a1: v11,
                  a2: *(_DWORD *)(v2 + 24),
                  a3: &ConstStringNode,
                  a4: v31,
                  a5: (char *)&fn + 3);
                v32 = (int)ConstStringNode;
                v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
                if ( v14 )
                  GASStringNode::ReleaseNode(a1: v32);
                if ( *(int *)(v2 + 28) >= 8 )
                {
                  v33 = *(_DWORD *)(v9 + 120);
                  HIBYTE(fn) = 0;
                  ConstStringNode = GASStringManager::CreateConstStringNode(
                                      this: *(GASStringManager **)(v33 + 636),
                                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5E40,
                                      a3: 6u,
                                      a4: 0);
                  ++*((_DWORD *)ConstStringNode + 2);
                  v59 = &v11->pNode[1].elem;
                  v34 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 7);
                  ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v59)(
                    a1: v11,
                    a2: *(_DWORD *)(v2 + 24),
                    a3: &ConstStringNode,
                    a4: v34,
                    a5: (char *)&fn + 3);
                  v35 = (int)ConstStringNode;
                  v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
                  if ( v14 )
                    GASStringNode::ReleaseNode(a1: v35);
                  if ( *(int *)(v2 + 28) >= 9 )
                  {
                    v36 = *(_DWORD *)(v9 + 120);
                    HIBYTE(fn) = 0;
                    ConstStringNode = GASStringManager::CreateConstStringNode(
                                        this: *(GASStringManager **)(v36 + 636),
                                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8,
                                        a3: 5u,
                                        a4: 0);
                    ++*((_DWORD *)ConstStringNode + 2);
                    v60 = &v11->pNode[1].elem;
                    v37 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 8);
                    ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v60)(
                      a1: v11,
                      a2: *(_DWORD *)(v2 + 24),
                      a3: &ConstStringNode,
                      a4: v37,
                      a5: (char *)&fn + 3);
                    v38 = (int)ConstStringNode;
                    v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
                    if ( v14 )
                      GASStringNode::ReleaseNode(a1: v38);
                    if ( *(int *)(v2 + 28) >= 10 )
                    {
                      v39 = *(_DWORD *)(v9 + 120);
                      HIBYTE(fn) = 0;
                      ConstStringNode = GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v39 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"leftMargin",
                                          a3: 0xAu,
                                          a4: 0);
                      ++*((_DWORD *)ConstStringNode + 2);
                      v61 = &v11->pNode[1].elem;
                      v40 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 9);
                      ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v61)(
                        a1: v11,
                        a2: *(_DWORD *)(v2 + 24),
                        a3: &ConstStringNode,
                        a4: v40,
                        a5: (char *)&fn + 3);
                      v41 = (int)ConstStringNode;
                      v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
                      if ( v14 )
                        GASStringNode::ReleaseNode(a1: v41);
                      if ( *(int *)(v2 + 28) >= 11 )
                      {
                        v42 = *(_DWORD *)(v9 + 120);
                        HIBYTE(fn) = 0;
                        ConstStringNode = GASStringManager::CreateConstStringNode(
                                            this: *(GASStringManager **)(v42 + 636),
                                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"rightMargin",
                                            a3: 0xBu,
                                            a4: 0);
                        ++*((_DWORD *)ConstStringNode + 2);
                        v62 = &v11->pNode[1].elem;
                        v43 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 10);
                        ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v62)(
                          a1: v11,
                          a2: *(_DWORD *)(v2 + 24),
                          a3: &ConstStringNode,
                          a4: v43,
                          a5: (char *)&fn + 3);
                        v44 = (int)ConstStringNode;
                        v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
                        if ( v14 )
                          GASStringNode::ReleaseNode(a1: v44);
                        if ( *(int *)(v2 + 28) >= 12 )
                        {
                          v45 = *(_DWORD *)(v9 + 120);
                          HIBYTE(fn) = 0;
                          ConstStringNode = GASStringManager::CreateConstStringNode(
                                              this: *(GASStringManager **)(v45 + 636),
                                              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"indent",
                                              a3: 6u,
                                              a4: 0);
                          ++*((_DWORD *)ConstStringNode + 2);
                          v63 = &v11->pNode[1].elem;
                          v46 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 11);
                          ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))*v63)(
                            a1: v11,
                            a2: *(_DWORD *)(v2 + 24),
                            a3: &ConstStringNode,
                            a4: v46,
                            a5: (char *)&fn + 3);
                          v47 = (int)ConstStringNode;
                          v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
                          if ( v14 )
                            GASStringNode::ReleaseNode(a1: v47);
                          if ( *(int *)(v2 + 28) >= 13 )
                          {
                            v48 = *(_DWORD *)(v9 + 120);
                            HIBYTE(fn) = 0;
                            ConstStringNode = GASStringManager::CreateConstStringNode(
                                                this: *(GASStringManager **)(v48 + 636),
                                                result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A2E68,
                                                a3: 7u,
                                                a4: 0);
                            ++*((_DWORD *)ConstStringNode + 2);
                            pNode = v11->pNode;
                            v50 = GASFnCall::Arg(this: (GASFnCall *)v2, a2: 12);
                            ((void (__thiscall *)(struct GASObject *, _DWORD, struct GASStringNode **, struct GASValue *, char *))pNode[1].elem)(
                              a1: v11,
                              a2: *(_DWORD *)(v2 + 24),
                              a3: &ConstStringNode,
                              a4: v50,
                              a5: (char *)&fn + 3);
                            v51 = (int)ConstStringNode;
                            v14 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
                            if ( v14 )
                              GASStringNode::ReleaseNode(a1: v51);
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
    }
    v4 = v65;
  }
  GASValue::SetAsObject(this: *(GASValue **)(v2 + 4), a2: v4);
  if ( v4 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v4, a2: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x1011C2A0
// Name: public: virtual class GASObject __near * GASTextFormatCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
CD3D11_QUERY_DESC *__userpurge GASTextFormatCtorFunction::CreateNewObject@<eax>(int a1@<edi>, int result)
{
  struct GASEnvironment *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GASTextFormatObject *v5; // eax

  v2 = (struct GASEnvironment *)result;
  v3 = *(_DWORD *)(*(_DWORD *)(result + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  result = 323;
  v5 = (GASTextFormatObject *)v4(a1: v3, a2: 120, a3: &result);
  if ( v5 != nullptr )
    return (CD3D11_QUERY_DESC *)GASTextFormatObject::GASTextFormatObject(this: v5, a2: a1, a3: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011C2E0
// Name: public: GASTextFormatProto::GASTextFormatProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASTextFormatProto *__thiscall GASTextFormatProto::GASTextFormatProto(
        GASTextFormatProto *this,
        __int64 psc,
        const struct GASFunctionRef *psc_8)
{
  const struct GASFunctionRef *v4; // ecx
  __int128 v6; // [esp-8h] [ebp-14h]

  GASTextFormatObject::GASTextFormatObject(
    this,
    (GASGlobalContext **)psc,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)HIDWORD(psc));
  v4 = psc_8;
  *((_DWORD *)this + 30) = &GASPrototypeBase::`vftable';
  *((_BYTE *)this + 132) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_BYTE *)this + 144) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 37) = 0;
  *(_QWORD *)&v6 = __PAIR64__((unsigned int)v4, psc);
  *(_DWORD *)this = &GASTextFormatProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASTextFormatObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 30) = &GASPrototype<GASTextFormatObject,GASEnvironment>::`vftable';
  GASPrototypeBase::Init(
    this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterialVar *),IMaterialVar *,CFuncMemPolicyNone> *)this
  + 5,
    a2: (int)this,
    pthis: (CMaterialVar *)this,
    psc: v6);
  *(_DWORD *)this = &GASTextFormatProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASTextFormatObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 30) = &GASPrototype<GASTextFormatObject,GASEnvironment>::`vftable';
  HIBYTE(psc) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 30,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)GAS_TextFormatFunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&psc + 7));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011C460
// Name: public: static class GASFunctionRef GASTextFormatCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASTextFormatCtorFunction::Register(struct GASFunctionRef *a1, int a2)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  GASCFunctionObject *v7; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, int *); // edx
  GASTextFormatProto *v11; // ebx
  GASTextFormatProto *v12; // eax
  _DWORD *v13; // eax
  int v14; // ebx
  GASValue *v15; // eax
  __int64 v17; // [esp-Ch] [ebp-34h]
  GASValue v18[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v19; // [esp+1Ch] [ebp-Ch] BYREF
  char v20; // [esp+20h] [ebp-8h]
  _DWORD *v21; // [esp+24h] [ebp-4h]
  struct GASFunctionRef *v22; // [esp+30h] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)a2;
  v3 = *(_DWORD *)(a2 + 656);
  v19 = a2;
  v20 = 8;
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASCFunctionObject *)v4(a1: v3, a2: 56, a3: &a2);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v19,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASTextFormatCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASTextFormatCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  *(_DWORD *)a1 = v7;
  *((_BYTE *)a1 + 8) = 0;
  *((_DWORD *)a1 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  a2 = 323;
  v11 = (GASTextFormatProto *)v10(a1: MaxVal, a2: 152, a3: &a2);
  if ( v11 != nullptr )
  {
    HIDWORD(v17) = GASGlobalContext::GetPrototype(this: v2, result: (vc_attributes::InvalidCheckAttribute *)1);
    LODWORD(v17) = &v19;
    v12 = GASTextFormatProto::GASTextFormatProto(this: v11, psc: v17, psc_8: a1);
    v22 = v12;
  }
  else
  {
    v22 = nullptr;
    v12 = nullptr;
  }
  if ( v12 != nullptr )
    *((_DWORD *)v12 + 2) = (*((_DWORD *)v12 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)a1, a3: 32, a4: (int)v12);
  v13 = v2[56].MaxVal + 16;
  HIBYTE(a2) = 0;
  v14 = *v13;
  v21 = v13;
  v15 = GASValue::GASValue(this: v18, a2: (int)a1, a3: a1);
  (*(void (__thiscall **)(_DWORD *, int *, const char **, GASValue *, char *))(v14 + 40))(
    a1: v21,
    a2: &v19,
    a3: &v2[11].MinVal,
    a4: v15,
    a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v18, a2: (int)a1);
  if ( v22 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v22, a2: (int)a1);
  return a1;
}
