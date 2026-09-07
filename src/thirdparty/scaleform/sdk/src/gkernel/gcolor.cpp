// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gcolor.cpp
// Functions: 4
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gcolor.h"

//------------------------------------------------------------------------------
// Address: 0x10063630
// Name: public: class GColor GRenderer::Cxform::Transform(class GColor)const
// Source: json
//------------------------------------------------------------------------------
CBaseAutoPtr<CFunctor> *__thiscall GRenderer::Cxform::Transform(
        float *this,
        CBaseAutoPtr<CFunctor> *result,
        unsigned int a3)
{
  double v4; // st7
  double v5; // st5
  double v6; // st7
  double v7; // st7
  float v9; // [esp+4h] [ebp-Ch]
  float v10; // [esp+8h] [ebp-8h]
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+1Ch] [ebp+Ch]
  float v13; // [esp+1Ch] [ebp+Ch]
  float v14; // [esp+1Ch] [ebp+Ch]
  float v15; // [esp+1Ch] [ebp+Ch]
  float v16; // [esp+1Ch] [ebp+Ch]

  v12 = (double)HIBYTE(a3) * *(this + 6) + *(this + 7);
  if ( v12 >= 255.0 )
  {
    v4 = 0.0;
    v12 = 255.0;
  }
  else
  {
    v4 = 0.0;
    if ( v12 < 0.0 )
    {
      v5 = 0.0;
      v6 = 255.0;
      v9 = 0.0;
      goto LABEL_6;
    }
  }
  v9 = v12;
  v5 = v4;
  v6 = 255.0;
LABEL_6:
  v13 = *(this + 4) * (double)(unsigned __int8)a3 + *(this + 5);
  if ( v13 >= 255.0 )
  {
    v13 = v6;
  }
  else if ( v13 < v5 )
  {
    v10 = v5;
    goto LABEL_11;
  }
  v10 = v13;
LABEL_11:
  v14 = (double)BYTE1(a3) * *(this + 2) + *(this + 3);
  if ( v14 >= 255.0 )
  {
    v14 = v6;
  }
  else if ( v14 < v5 )
  {
    v11 = v5;
    goto LABEL_16;
  }
  v11 = v14;
LABEL_16:
  v15 = (double)BYTE2(a3) * *this + *(this + 1);
  if ( v15 >= 255.0 )
  {
    v15 = v6;
    goto LABEL_18;
  }
  v7 = v5;
  if ( v15 >= v5 )
LABEL_18:
    v7 = v15;
  v16 = v7;
  BYTE2(result->m_pObject) = (int)v16;
  BYTE1(result->m_pObject) = (int)v11;
  LOBYTE(result->m_pObject) = (int)v10;
  HIBYTE(result->m_pObject) = (int)v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015E610
// Name: public: static class GColor GColor::Blend(class GColor,class GColor,float)
// Source: json
//------------------------------------------------------------------------------
const CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *__stdcall GColor::Blend(
        const CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *result,
        unsigned int a2,
        unsigned int a3,
        float f)
{
  float v7; // [esp+0h] [ebp-4h]
  float v8; // [esp+10h] [ebp+Ch]
  float v9; // [esp+10h] [ebp+Ch]
  float v10; // [esp+10h] [ebp+Ch]
  float v11; // [esp+10h] [ebp+Ch]
  float v12; // [esp+14h] [ebp+10h]
  float v13; // [esp+14h] [ebp+10h]
  float v14; // [esp+14h] [ebp+10h]

  v7 = (float)BYTE2(a2);
  v8 = v7 + ((double)BYTE2(a3) - v7) * f;
  BYTE2(result->m_pBlockHeader) = (int)(v8 + 0.5);
  v12 = (float)BYTE1(a2);
  v9 = ((double)BYTE1(a3) - v12) * f + v12;
  BYTE1(result->m_pBlockHeader) = (int)(v9 + 0.5);
  v13 = (float)(unsigned __int8)a2;
  v10 = ((double)(unsigned __int8)a3 - v13) * f + v13;
  LOBYTE(result->m_pBlockHeader) = (int)(v10 + 0.5);
  v14 = (float)HIBYTE(a2);
  v11 = f * ((double)HIBYTE(a3) - v14) + v14;
  HIBYTE(result->m_pBlockHeader) = (int)(v11 + 0.5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015E770
// Name: unsigned int G_Format<int,int,int,int>(class GMsgFormat::Sink const __near &,char const __near *,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_Format<int,int,int,int>(
        struct GMsgFormat::Sink *a1,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2,
        CUtlSymbolTable::StringPool_t *a3,
        CUtlSymbolTable::StringPool_t *a4,
        CUtlSymbolTable::StringPool_t *a5,
        CUtlSymbolTable::StringPool_t *a6)
{
  int v6; // esi
  unsigned __int16 v8; // [esp+0h] [ebp-318h]
  unsigned __int16 v9; // [esp+0h] [ebp-318h]
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *parsed_format; // [esp+14h] [ebp-304h] BYREF
  int v11; // [esp+20h] [ebp-2F8h]

  GMsgFormat::GMsgFormat(this: &parsed_format, a2: a1);
  GMsgFormat::Parse(result: a2);
  GMsgFormat::FormatD1<int>(this: (int)&parsed_format, result: a3);
  GMsgFormat::FormatD1<int>(this: (int)&parsed_format, result: a4);
  GMsgFormat::FormatD1<int>(this: (int)&parsed_format, result: a5);
  GMsgFormat::FormatD1<int>(this: (int)&parsed_format, result: a6);
  GMsgFormat::FinishFormatD(
    this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parsed_format,
    a2: v8);
  v6 = v11;
  GMsgFormat::~GMsgFormat(
    this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parsed_format,
    data_size: v9);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1015E830
// Name: public: void GColor::Format(char __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GColor::Format(GColor *this, char *pbuffer)
{
  int Blue; // edx
  int Green; // eax
  int Red; // ecx
  _DWORD v6[3]; // [esp+0h] [ebp-1Ch] BYREF
  CUtlSymbolTable::StringPool_t v7; // [esp+Ch] [ebp-10h] BYREF
  int Alpha; // [esp+18h] [ebp-4h] BYREF

  Blue = this->Channels.Blue;
  Alpha = this->Channels.Alpha;
  Green = this->Channels.Green;
  Red = this->Channels.Red;
  v7.m_SpaceUsed = Green;
  *(_DWORD *)v7.m_Data = Blue;
  v7.m_TotalLen = Red;
  v6[1] = pbuffer;
  v6[0] = 2;
  v6[2] = 512;
  return G_Format<int,int,int,int>(
           a1: (struct GMsgFormat::Sink *)v6,
           a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"RGBA: {0} {1} {2} {3}\n",
           a3: &v7,
           a4: (CUtlSymbolTable::StringPool_t *)&v7.m_SpaceUsed,
           a5: (CUtlSymbolTable::StringPool_t *)v7.m_Data,
           a6: (CUtlSymbolTable::StringPool_t *)&Alpha);
}
