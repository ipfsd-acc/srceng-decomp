// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importsfmv1.cpp
// Functions: 4
// ============================================================

#include "dmserializers\importsfmv1.h"

//------------------------------------------------------------------------------
// Address: 0x004576F0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x00457710
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &defaultValue;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = &defaultValue;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457880
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: &array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &defaultValue;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457960
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0046D0F0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x0046D110
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = var;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = var;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D280
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = var;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D360
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004A9BE0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x004A9C00
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (const int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = defaultValue;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A9D70
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A9E50
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104B9AB0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x104B9AD0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &var;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = &var;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B9C40
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &var;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x104B9D20
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportSFMV1::DoFixup@<al>(
        CImportSFMV1 *this@<ecx>,
        const char *a2@<edi>,
        CDmElement *pElementInternal)
{
  CImportSFMV1 *v3; // ebx
  const char *m_pAsString; // esi
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // edi
  __int16 v7; // ax
  CDmaVar<enum DmElementHandle_t> *v8; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v13; // edi
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v18; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v3 = this;
  v18 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v3->m_fixedElements,
      a2,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v3, pElementInternal);
      }
    }
    else
    {
      v5 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v3, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v3, pElementInternal: v5, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v3, pElementInternal: v5, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v7 = Attribute->m_nFlags & 0x1F;
        if ( v7 == 1 )
        {
          v8 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8->m_Storage.m_Handle);
          v10 = v9;
          if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmElement::m_classType) )
            v10 = nullptr;
          v3->DoFixup(this: v3, a2: v10);
        }
        else if ( v7 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v13 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v13]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              v18->DoFixup(this: v18, a2: v15);
              if ( ++v13 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v3 = v18;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0048FEA0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x0048FEC0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = WindowName;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = WindowName;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490030
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  const CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = WindowName;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490110
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  int v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  int v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v7->m_Storage.m_Handle);
          v9 = (CDmElement *)v8;
          if ( v8 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v9 = nullptr;
          }
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = (CDmElement *)v13;
              if ( v13 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v13 + 16))(
                     a1: v13,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v14 = nullptr;
              }
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00513AA0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x00513AC0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDefaultValue;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = pDefaultValue;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = pDefaultValue;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00513C30
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: &array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDefaultValue;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = pDefaultValue;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00513D10
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportSFMV1::DoFixup@<al>(
        CImportSFMV1 *this@<ecx>,
        const char *a2@<edi>,
        CDmElement *pElementInternal)
{
  CImportSFMV1 *v3; // ebx
  const char *m_pAsString; // esi
  CDmElement *v5; // esi
  CDmAttribute *v6; // edi
  __int16 v7; // ax
  CDmaVar<enum DmElementHandle_t> *v8; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v13; // edi
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v18; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v3 = this;
  v18 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v3->m_fixedElements,
      a2,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v3, pElementInternal);
      }
    }
    else
    {
      v5 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v3, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v3, pElementInternal: v5, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v3, pElementInternal: v5, pOldName: "offset", pNewName: "offsetTime");
    }
    v6 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElementInternal);
    pAttribute = v6;
    if ( v6 != nullptr )
    {
      while ( 1 )
      {
        v7 = v6->m_nFlags & 0x1F;
        if ( v7 == 1 )
        {
          v8 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v6);
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8->m_Storage.m_Handle);
          v10 = v9;
          if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmElement::m_classType) )
            v10 = nullptr;
          v3->DoFixup(this: v3, a2: v10);
        }
        else if ( v7 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (v6->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = v6;
            m_pData = (DmElementArray_t *)v6->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v13 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v13]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              v18->DoFixup(this: v18, a2: v15);
              if ( ++v13 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v3 = v18;
          v6 = pAttribute;
        }
        pAttribute = v6->m_pNext;
        if ( pAttribute == nullptr )
          break;
        v6 = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D40A0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x004D40C0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = pDeltaStateName;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = pDeltaStateName;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D4230
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = pDeltaStateName;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D4310
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  int v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  int v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v7->m_Storage.m_Handle);
          v9 = (CDmElement *)v8;
          if ( v8 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v9 = nullptr;
          }
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = (CDmElement *)v13;
              if ( v13 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v13 + 16))(
                     a1: v13,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v14 = nullptr;
              }
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x004591C0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x004591E0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (const int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = defaultValue;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459350
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: &array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459430
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0045ACC0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x0045ACE0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = *CDmAttribute::GetValue<float>(this: Attribute);
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = str;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = str;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AE50
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = str;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AF30
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00465CB0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x00465CD0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  const char *v4; // edi
  CDmAttribute *Attribute; // eax
  const char *v6; // ebp
  const char *v7; // eax
  const char *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // edi
  const char *v11; // eax
  float m_Storage; // [esp+18h] [ebp-4h]

  m_Storage = 0.0;
  v4 = pOldName;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  v6 = pNewName;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      m_Storage = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: v4);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      v8 = CUtlString::operator char const *(this: &pElementInternal->m_Name.m_Storage);
      _Warning(a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n", v8, v4);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v7 = CUtlString::operator char const *(this: &pElementInternal->m_Name.m_Storage);
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v7, v4);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", v6);
  }
  v9 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: v6);
  if ( v9 != nullptr )
    v10 = (v9->m_nFlags & 0x1F) == 2 ? v9 : nullptr;
  else
    v10 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v6, type: AT_INT);
  if ( v10 != nullptr )
  {
    pOldName = (const char *)(int)floor(X: m_Storage * 10000.0 + 0.5);
    CDmAttribute::SetValue<int>(this: v10, value: (int *)&pOldName);
  }
  else
  {
    v11 = CUtlString::operator char const *(this: &pElementInternal->m_Name.m_Storage);
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v11, v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465DF0
// Name: private: void CImportSFMV1::FixupTimeframe(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupTimeframe(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1::ConvertTimeAttribute(this, pElementInternal, pOldName: "start", pNewName: "startTime");
  CImportSFMV1::ConvertTimeAttribute(this, pElementInternal, pOldName: "duration", pNewName: "durationTime");
  CImportSFMV1::ConvertTimeAttribute(this, pElementInternal, pOldName: "offset", pNewName: "offsetTime");
}

//------------------------------------------------------------------------------
// Address: 0x00465E40
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // eax
  const char *v6; // eax
  int m_nFlags; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-Ch] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array.m_pAttribute,
        pAttribute: v4);
      m_nFlags = array.m_pAttribute->m_nFlags;
      for ( i = 0; i < m_nFlags; ++i )
      {
        pElementInternal = (CDmElement *)(10 * *((_DWORD *)&array.m_pAttribute->m_pNext->m_pNext + i));
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&array.m_pAttribute,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      v6 = CUtlString::operator char const *(this: &v2->m_Name.m_Storage);
      _Warning(a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n", v6, "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = CUtlString::operator char const *(this: &v2->m_Name.m_Storage);
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465F20
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportSFMV1::DoFixup@<al>(CImportSFMV1 *this@<ecx>, int a2@<edi>, CDmElement *pElementInternal)
{
  const char *v4; // ebx
  CDmAttribute *i; // ebp
  int v6; // eax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  int v8; // esi
  CDmAttribute *m_pData; // eax
  int m_nFlags; // ebx
  int v11; // edi
  int v12; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmAttribute *v16; // [esp+14h] [ebp-4h]

  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &this->m_fixedElements,
      insert: &pElementInternal);
    v4 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: pElementInternal->m_Type);
    if ( strcmp(v4, "DmeTimeFrame") == 0 )
    {
      CImportSFMV1::FixupTimeframe(this, pElementInternal);
    }
    else if ( strcmp(v4, "DmeLog") == 0
           || V_strcmp(s1: v4, s2: "DmeIntLog") == 0
           || V_strcmp(s1: v4, s2: "DmeFloatLog") == 0
           || V_strcmp(s1: v4, s2: "DmeBoolLog") == 0
           || V_strcmp(s1: v4, s2: "DmeColorLog") == 0
           || V_strcmp(s1: v4, s2: "DmeVector2Log") == 0
           || V_strcmp(s1: v4, s2: "DmeVector3Log") == 0
           || V_strcmp(s1: v4, s2: "DmeVector4Log") == 0
           || V_strcmp(s1: v4, s2: "DmeQAngleLog") == 0
           || V_strcmp(s1: v4, s2: "DmeQuaternionLog") == 0
           || V_strcmp(s1: v4, s2: "DmeVMatrixLog") == 0 )
    {
      CImportSFMV1::FixupLog(this, pElementInternal);
    }
    for ( i = (CDmAttribute *)KeyValues::GetFirstSubKey(this: (KeyValues *)pElementInternal); i != nullptr; i = i->m_pNext )
    {
      v6 = i->m_nFlags & 0x1F;
      if ( v6 == 1 )
      {
        v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: i);
        v8 = ((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(
               a1: g_pDataModel,
               a2: v7->m_Storage.m_Handle,
               a3: a2);
        if ( v8 == 0
          || (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 20))(
               a1: v8,
               a2: CDmElement::m_classType.m_Id) == 0 )
        {
          v8 = 0;
        }
        a2 = v8;
        ((void (__thiscall *)(CDmAttribute *))array.m_pAttribute->m_pNext->m_nFlags)(a1: array.m_pAttribute);
      }
      else if ( v6 == 15 )
      {
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
        if ( (i->m_nFlags & 0x1F) == 0xF )
        {
          v16 = i;
          m_pData = (CDmAttribute *)i->m_pData;
        }
        else
        {
          v16 = nullptr;
          m_pData = nullptr;
        }
        array.m_pAttribute = m_pData;
        m_nFlags = m_pData->m_nFlags;
        v11 = 0;
        if ( m_nFlags > 0 )
        {
          while ( 1 )
          {
            v12 = ((int (__thiscall *)(IDataModel *, _DWORD, int))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: *((_DWORD *)&m_pData->m_pNext->m_pNext + v11),
                    a3: a2);
            if ( v12 == 0
              || (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v12 + 20))(
                   a1: v12,
                   a2: CDmElement::m_classType.m_Id) == 0 )
            {
              v12 = 0;
            }
            a2 = v12;
            ((void (__thiscall *)(CDmAttribute *))array.m_pAttribute->m_pNext->m_nFlags)(a1: array.m_pAttribute);
            if ( ++v11 >= m_nFlags )
              break;
            m_pData = array.m_pAttribute;
          }
        }
      }
    }
  }
  return 1;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00459160
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x00459180
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = *CDmAttribute::GetValue<float>(this: Attribute);
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &defaultValue;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = &defaultValue;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004592F0
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: &array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (const int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &defaultValue;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004593D0
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0045E0E0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x0045E100
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &pParentName;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = &pParentName;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E270
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (const int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = &pParentName;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E350
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B4220
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x004B4240
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = *CDmAttribute::GetValue<float>(this: Attribute);
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (const int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = defaultValue;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B43B0
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  const CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (const int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B4490
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  int v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  int v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v7->m_Storage.m_Handle);
          v9 = (CDmElement *)v8;
          if ( v8 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v9 = nullptr;
          }
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = (CDmElement *)v13;
              if ( v13 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v13 + 16))(
                     a1: v13,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v14 = nullptr;
              }
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0045EC90
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x0045ECB0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // edi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = *CDmAttribute::GetValue<float>(this: Attribute);
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      _Warning(a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n");
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n");
  }
  v5 = pNewName;
  v6 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v6 != nullptr )
    v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6;
  else
    v7 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v5, type: AT_INT);
  if ( v7 != nullptr )
  {
    v8 = (__m128)LODWORD(time);
    v8.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v9.m128_i32[0] = 1258291200;
    v10 = _mm_and_ps((__m128)0x80000000, v8);
    v9.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v8, v10), v9).m128_f32[0]) & 0x4B000000
                   | v10.m128_i32[0];
    v11 = v8;
    v11.m128_f32[0] = (float)(v8.m128_f32[0] + v9.m128_f32[0]) - v9.m128_f32[0];
    v12 = v11;
    v12.m128_f32[0] = v11.m128_f32[0] - v8.m128_f32[0];
    pNewName = (const char *)(int)(float)(v11.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v12, v10).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v7, value: (int *)&pNewName);
  }
  else
  {
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EE20
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // esi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v3 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v3);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (const int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      _Warning(a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EF00
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004CD650
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x004CD670
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = pDeltaStateName;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = pDeltaStateName;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD7E0
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = pDeltaStateName;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD8C0
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  int v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  int v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: v7->m_Storage.m_Handle);
          v9 = (CDmElement *)v8;
          if ( v8 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v9 = nullptr;
          }
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = (CDmElement *)v13;
              if ( v13 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v13 + 16))(
                     a1: v13,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v14 = nullptr;
              }
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00469530
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x00469550
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = *CDmAttribute::GetValue<float>(this: Attribute);
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = Ptr;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (const int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = Ptr;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004696C0
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  const CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (const int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = Ptr;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004697A0
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    Attribute = CDmElement::FirstAttribute(this: pElementInternal);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        v6 = Attribute->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( pAttribute == nullptr )
          break;
        Attribute = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00560DC0
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x00560DE0
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = var;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = var;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00560F50
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = var;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00561030
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *v5; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    v5 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElementInternal);
    pAttribute = v5;
    if ( v5 != nullptr )
    {
      while ( 1 )
      {
        v6 = v5->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v5);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (v5->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = v5;
            m_pData = (DmElementArray_t *)v5->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          v5 = pAttribute;
        }
        pAttribute = v5->m_pNext;
        if ( pAttribute == nullptr )
          break;
        v5 = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1008BC30
// Name: void InstallSFMV1Importer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallSFMV1Importer(IDataModel *pFactory)
{
  pFactory->AddLegacyUpdater(this: pFactory, a2: &s_ImportDmxV1);
}

//------------------------------------------------------------------------------
// Address: 0x1008BC50
// Name: private: void CImportSFMV1::ConvertTimeAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::ConvertTimeAttribute(
        CImportSFMV1 *this,
        CDmElement *pElementInternal,
        const char *pOldName,
        const char *pNewName)
{
  CDmAttribute *Attribute; // eax
  const char *v5; // eax
  const char *m_pAsString; // eax
  const char *v7; // edi
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // esi
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float time; // [esp+0h] [ebp-4h]

  time = 0.0;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pOldName);
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      time = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CDmElement::RemoveAttribute(this: pElementInternal, pAttributeName: pOldName);
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = pElementInternal->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** TimeFrame \"%s\" has attribute \"%s\" with an unexpected type (expected float)!\n",
        m_pAsString,
        pOldName);
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** TimeFrame \"%s\" is missing attribute \"%s\"!\n", v5, pOldName);
    _Warning(a1: "*** Setting new attribute \"%s\" to 0\n", pNewName);
  }
  v7 = pNewName;
  v8 = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: pNewName);
  if ( v8 != nullptr )
    v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8;
  else
    v9 = CDmElement::CreateAttribute(this: pElementInternal, pAttributeName: v7, type: AT_INT);
  if ( v9 != nullptr )
  {
    v11 = (__m128)LODWORD(time);
    v11.m128_f32[0] = (float)(time * 10000.0) + 0.5;
    v12.m128_i32[0] = 1258291200;
    v13 = _mm_and_ps((__m128)0x80000000, v11);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v13), v12).m128_f32[0]) & 0x4B000000
                    | v13.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v12.m128_f32[0]) - v12.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    pNewName = (const char *)(int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & 0x3F800000));
    CDmAttribute::SetValue<int>(this: v9, value: (int *)&pNewName);
  }
  else
  {
    v10 = pElementInternal->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = defaultValue;
    _Warning(a1: "*** Converter error - element \"%s\" already has a non-int attribute \"%s\"!\n", v10, v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BDC0
// Name: private: void CImportSFMV1::FixupLog(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportSFMV1::FixupLog(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  const char *v5; // edi
  const char *m_pAsString; // edi
  int m_Size; // edi
  int i; // esi
  CDmrArray<int> array; // [esp+8h] [ebp-8h] BYREF

  v2 = pElementInternal;
  Attribute = CDmElement::FindAttribute(this: pElementInternal, pAttributeName: "times");
  v4 = Attribute;
  if ( Attribute != nullptr )
  {
    if ( (Attribute->m_nFlags & 0x1F) == 0x10 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
      CDmrDecorator<int,CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: &array,
        pAttribute: v4);
      m_Size = array.m_pStorage->m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        pElementInternal = (CDmElement *)(10 * array.m_pStorage->m_Memory.m_pMemory[i]);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: &array,
          i,
          value: (int *)&pElementInternal);
      }
    }
    else
    {
      _Warning(a1: "*** Problem in file encountered!\n");
      m_pAsString = v2->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      _Warning(
        a1: "*** Log \"%s\" has attribute \"%s\" with an unexpected type (expected int array)!\n",
        m_pAsString,
        "times");
    }
  }
  else
  {
    _Warning(a1: "*** Problem in file encountered!\n");
    v5 = v2->m_Name.m_Storage.u.m_pAsString;
    if ( v5 == (const char *)-1 )
      v5 = defaultValue;
    _Warning(a1: "*** Log \"%s\" is missing attribute \"%s\"!\n", v5, "times");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BEA0
// Name: private: virtual bool CImportSFMV1::DoFixup(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportSFMV1::DoFixup(CImportSFMV1 *this, CDmElement *pElementInternal)
{
  CImportSFMV1 *v2; // ebx
  const char *m_pAsString; // esi
  CDmElement *v4; // esi
  CDmAttribute *v5; // edi
  __int16 v6; // ax
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v12; // edi
  CDmElement *v13; // eax
  CDmElement *v14; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-10h] BYREF
  CImportSFMV1 *v17; // [esp+14h] [ebp-8h]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( pElementInternal != nullptr
    && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
         this: &this->m_fixedElements,
         search: &pElementInternal) == -1 )
  {
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
      this: &v2->m_fixedElements,
      insert: &pElementInternal);
    m_pAsString = pElementInternal->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_strcmp(s1: m_pAsString, s2: "DmeTimeFrame") != 0 )
    {
      if ( _V_strcmp(s1: m_pAsString, s2: "DmeLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeIntLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeFloatLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeBoolLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeColorLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector2Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector3Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVector4Log") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQAngleLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeQuaternionLog") == 0
        || _V_strcmp(s1: m_pAsString, s2: "DmeVMatrixLog") == 0 )
      {
        CImportSFMV1::FixupLog(this: v2, pElementInternal);
      }
    }
    else
    {
      v4 = pElementInternal;
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal, pOldName: "start", pNewName: "startTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "duration", pNewName: "durationTime");
      CImportSFMV1::ConvertTimeAttribute(this: v2, pElementInternal: v4, pOldName: "offset", pNewName: "offsetTime");
    }
    v5 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElementInternal);
    pAttribute = v5;
    if ( v5 != nullptr )
    {
      while ( 1 )
      {
        v6 = v5->m_nFlags & 0x1F;
        if ( v6 == 1 )
        {
          v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v5);
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
          v9 = v8;
          if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
            v9 = nullptr;
          v2->DoFixup(this: v2, a2: v9);
        }
        else if ( v6 == 15 )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (v5->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = v5;
            m_pData = (DmElementArray_t *)v5->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v12 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType) )
                v14 = nullptr;
              v17->DoFixup(this: v17, a2: v14);
              if ( ++v12 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = v17;
          v5 = pAttribute;
        }
        pAttribute = v5->m_pNext;
        if ( pAttribute == nullptr )
          break;
        v5 = pAttribute;
      }
    }
  }
  return 1;
}

} // namespace vtex_dll
