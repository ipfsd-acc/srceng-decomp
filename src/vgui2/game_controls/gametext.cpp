// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gametext.cpp
// Functions: 24
// ============================================================

#include "vgui2\game_controls\gametext.h"

//------------------------------------------------------------------------------
// Address: 0x0041AF10
// Name: public: void CGameText::SetFont(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::SetFont(CGameText *this, const char *pFontName)
{
  CUtlString *p_m_FontName; // ebx
  unsigned __int8 *v4; // edi
  int (__thiscall **v5)(unsigned __int8 *, const char *, int); // esi
  const char *v6; // eax

  p_m_FontName = &this->m_FontName;
  CUtlString::operator=(this: &this->m_FontName, src: pFontName);
  if ( CUtlString::Length(this: p_m_FontName) != 0 )
  {
    v4 = CVTFTexture::LowResImageData(this: (CVTFTexture *)g_pGameUISystemMgrImpl);
    v5 = (int (__thiscall **)(unsigned __int8 *, const char *, int))(*(_DWORD *)v4 + 8);
    v6 = CUtlString::operator char const *(this: p_m_FontName);
    this->m_Font = (*v5)(a1: v4, a2: v6, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AF70
// Name: public: virtual void CGameText::DrawExtents(class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::DrawExtents(
        CGameText *this,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  CGeometry::DrawExtents(
    this: &this->m_Geometry,
    renderGeometryLists,
    firstListIndex,
    extentLineColor: (color32_s)-59136);
}

//------------------------------------------------------------------------------
// Address: 0x0041AFA0
// Name: private: int CGameText::GetTextRenderWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameText::GetTextRenderWidth(CGameText *this)
{
  wchar_t *m_UnicodeText; // eax
  int v3; // ebp
  wchar_t *v4; // edx
  __int16 v5; // cx
  int v6; // ebx
  int i; // edi
  wchar_t v8; // ax

  m_UnicodeText = this->m_UnicodeText;
  v3 = 0;
  v4 = m_UnicodeText + 1;
  do
    v5 = *m_UnicodeText++;
  while ( v5 != 0 );
  v6 = m_UnicodeText - v4;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_UnicodeText[i];
    if ( this->m_bAllCaps )
      v8 = towupper(c: this->m_UnicodeText[i]);
    if ( v8 != 38 || this->m_UnicodeText[i + 1] == 0 )
      v3 += g_pGameUISystemSurface->GetCharacterWidth(this: g_pGameUISystemSurface, a2: this->m_Font, a3: v8);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041B030
// Name: public: virtual bool CGameText::HitTest(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameText::HitTest(CGameText *this, int x, int y)
{
  Vector2D v4; // [esp-8h] [ebp-20h]
  Vector2D v5; // [esp+0h] [ebp-18h]
  Vector2D m_BottomRight; // [esp+8h] [ebp-10h]
  Vector2D m_TopLeft; // [esp+10h] [ebp-8h]
  float xa; // [esp+1Ch] [ebp+4h]
  float ya; // [esp+20h] [ebp+8h]

  if ( !this->m_Geometry.m_bVisible )
    return false;
  v4.x = (float)x;
  xa = (float)x;
  v4.y = (float)y;
  m_TopLeft = this->m_Geometry.m_Extents.m_TopLeft;
  m_BottomRight = this->m_Geometry.m_Extents.m_BottomRight;
  v5.x = this->m_Geometry.m_Extents.m_TopLeft.x;
  v5.y = this->m_Geometry.m_Extents.m_BottomRight.y;
  ya = (float)y;
  return PointTriangleHitTest(
           tringleVert0: m_TopLeft,
           tringleVert1: (Vector2D)__PAIR64__(LODWORD(m_TopLeft.y), LODWORD(m_BottomRight.x)),
           tringleVert2: m_BottomRight,
           point: v4)
      || PointTriangleHitTest(
           tringleVert0: m_TopLeft,
           tringleVert1: m_BottomRight,
           tringleVert2: v5,
           point: (Vector2D)__PAIR64__(LODWORD(ya), LODWORD(xa)));
}

//------------------------------------------------------------------------------
// Address: 0x0041B170
// Name: private: void CGameText::GetStartingTextPosition(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::GetStartingTextPosition(CGameText *this, int *x, int *y)
{
  *x = 0;
  *y = g_pGameUISystemSurface->GetFontTall(this: g_pGameUISystemSurface, a2: this->m_Font) / -2;
  if ( this->m_Justification == 1 )
  {
    *x = CGameText::GetTextRenderWidth(this) / -2;
  }
  else if ( this->m_Justification == 2 )
  {
    *x = -CGameText::GetTextRenderWidth(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B1E0
// Name: public: virtual void CGameText::UpdateGeometry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::UpdateGeometry(CGameText *this)
{
  const char *v2; // eax
  DmeTime_t result; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_CurrentState != -1 )
  {
    CGameGraphic::GetAnimationTimePassed(this, &result);
    CTypedLog<color32_s>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_ColorAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Color);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_CenterPosAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Center);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_ScaleAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Scale);
    CTypedLog<float>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_RotationAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Rotation);
    CTypedLog<CUtlString>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_FontAnim,
      time: result,
      pOutValue: &this->m_FontName);
    v2 = CUtlString::operator char const *(this: &this->m_FontName);
    CGameText::SetFont(this, pFontName: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B2C0
// Name: public: virtual CGameText::~CGameText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::~CGameText(CGameText *this)
{
  wchar_t *m_UnicodeText; // eax
  bool v3; // sf

  m_UnicodeText = this->m_UnicodeText;
  this->__vftable = (CGameText_vtbl *)&CGameText::`vftable';
  if ( m_UnicodeText != nullptr )
  {
    free(pMem: m_UnicodeText);
    this->m_UnicodeText = nullptr;
  }
  v3 = this->m_FontName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_FontName.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_FontName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FontName.m_Storage.m_Memory.m_pMemory);
      this->m_FontName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FontName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_CharText.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_CharText.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_CharText.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CharText.m_Storage.m_Memory.m_pMemory);
      this->m_CharText.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_CharText.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CGameGraphic::~CGameGraphic(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041B360
// Name: public: virtual void CGameGraphic::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::SetVisible(CGameGraphic *this, bool bVisible)
{
  this->m_Geometry.m_bVisible = bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x0041B370
// Name: public: virtual bool CGameGraphic::MaintainAspectRatio(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameGraphic::MaintainAspectRatio(CGameGraphic *this)
{
  return this->m_Geometry.m_bMaintainAspectRatio;
}

//------------------------------------------------------------------------------
// Address: 0x0041B380
// Name: public: virtual void CGameGraphic::SetCenter(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::SetCenter(CGameGraphic *this, float x, float y)
{
  this->m_Geometry.m_Center.x = x;
  this->m_Geometry.m_Center.y = y;
}

//------------------------------------------------------------------------------
// Address: 0x0041B3A0
// Name: public: virtual void CGameGraphic::SetScale(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::SetScale(CGameGraphic *this, float xScale, float yScale)
{
  this->m_Geometry.m_Scale.x = xScale;
  this->m_Geometry.m_Scale.y = yScale;
}

//------------------------------------------------------------------------------
// Address: 0x0041B460
// Name: private: void CGameText::SetupVertexColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::SetupVertexColors(CGameText *this)
{
  CUtlMemory<S3RGBA,int> *p_m_VertexColors; // esi
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v4; // ecx
  int v5; // eax
  bool v6; // zf
  S3RGBA *v7; // eax
  S3RGBA *v8; // edi
  int v9; // eax
  S3RGBA *v10; // ecx
  int v11; // eax
  S3RGBA *v12; // eax
  S3RGBA *v13; // edi
  int v14; // eax
  S3RGBA *v15; // ecx
  int v16; // eax
  S3RGBA *v17; // eax
  S3RGBA *v18; // edi
  int v19; // eax
  S3RGBA *v20; // ecx
  int v21; // eax
  S3RGBA *v22; // eax
  wchar_t *m_UnicodeText; // [esp+8h] [ebp-4h]

  if ( this->m_UnicodeText != nullptr )
  {
    p_m_VertexColors = (CUtlMemory<S3RGBA,int> *)&this->m_Geometry.m_VertexColors;
    this->m_Geometry.m_VertexColors.m_Size = 0;
    m_UnicodeText = this->m_UnicodeText;
    if ( *m_UnicodeText != 0 )
    {
      do
      {
        m_pMemory = p_m_VertexColors[1].m_pMemory;
        m_nAllocationCount = p_m_VertexColors->m_nAllocationCount;
        if ( (int)&m_pMemory->g > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: p_m_VertexColors,
            num: (int)(&m_pMemory->g - m_nAllocationCount));
        ++p_m_VertexColors[1].m_pMemory;
        v4 = p_m_VertexColors->m_pMemory;
        v5 = (char *)p_m_VertexColors[1].m_pMemory - (char *)m_pMemory - 1;
        v6 = (char *)p_m_VertexColors[1].m_pMemory - (char *)m_pMemory == 1;
        p_m_VertexColors[1].m_nAllocationCount = (int)p_m_VertexColors->m_pMemory;
        if ( v5 >= 0 && !v6 )
          _V_memmove(dest: &v4[(_DWORD)m_pMemory + 1], src: &v4[(_DWORD)m_pMemory], count: 4 * v5);
        v7 = &p_m_VertexColors->m_pMemory[(_DWORD)m_pMemory];
        if ( v7 != nullptr )
          *v7 = (S3RGBA)-1;
        v8 = p_m_VertexColors[1].m_pMemory;
        v9 = p_m_VertexColors->m_nAllocationCount;
        if ( (int)&v8->g > v9 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_VertexColors, num: (int)(&v8->g - v9));
        ++p_m_VertexColors[1].m_pMemory;
        v10 = p_m_VertexColors->m_pMemory;
        v11 = (char *)p_m_VertexColors[1].m_pMemory - (char *)v8 - 1;
        v6 = (char *)p_m_VertexColors[1].m_pMemory - (char *)v8 == 1;
        p_m_VertexColors[1].m_nAllocationCount = (int)p_m_VertexColors->m_pMemory;
        if ( v11 >= 0 && !v6 )
          _V_memmove(dest: &v10[(_DWORD)v8 + 1], src: &v10[(_DWORD)v8], count: 4 * v11);
        v12 = &p_m_VertexColors->m_pMemory[(_DWORD)v8];
        if ( v12 != nullptr )
          *v12 = (S3RGBA)-1;
        v13 = p_m_VertexColors[1].m_pMemory;
        v14 = p_m_VertexColors->m_nAllocationCount;
        if ( (int)&v13->g > v14 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_VertexColors, num: (int)(&v13->g - v14));
        ++p_m_VertexColors[1].m_pMemory;
        v15 = p_m_VertexColors->m_pMemory;
        v16 = (char *)p_m_VertexColors[1].m_pMemory - (char *)v13 - 1;
        v6 = (char *)p_m_VertexColors[1].m_pMemory - (char *)v13 == 1;
        p_m_VertexColors[1].m_nAllocationCount = (int)p_m_VertexColors->m_pMemory;
        if ( v16 >= 0 && !v6 )
          _V_memmove(dest: &v15[(_DWORD)v13 + 1], src: &v15[(_DWORD)v13], count: 4 * v16);
        v17 = &p_m_VertexColors->m_pMemory[(_DWORD)v13];
        if ( v17 != nullptr )
          *v17 = (S3RGBA)-1;
        v18 = p_m_VertexColors[1].m_pMemory;
        v19 = p_m_VertexColors->m_nAllocationCount;
        if ( (int)&v18->g > v19 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_VertexColors, num: (int)(&v18->g - v19));
        ++p_m_VertexColors[1].m_pMemory;
        v20 = p_m_VertexColors->m_pMemory;
        v21 = (char *)p_m_VertexColors[1].m_pMemory - (char *)v18 - 1;
        v6 = (char *)p_m_VertexColors[1].m_pMemory - (char *)v18 == 1;
        p_m_VertexColors[1].m_nAllocationCount = (int)p_m_VertexColors->m_pMemory;
        if ( v21 >= 0 && !v6 )
          _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
        v22 = &p_m_VertexColors->m_pMemory[(_DWORD)v18];
        if ( v22 != nullptr )
          *v22 = (S3RGBA)-1;
        v6 = m_UnicodeText[1] == 0;
        ++m_UnicodeText;
      }
      while ( !v6 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B610
// Name: public: virtual void CGameText::SetColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::SetColor(CGameText *this, color32_s c)
{
  this->m_Geometry.m_TopColor = c;
  this->m_Geometry.m_BottomColor = c;
  this->m_Geometry.m_VertexColors.m_Size = 0;
  CGameText::SetupVertexColors(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041B630
// Name: private: void CGameText::SetText(wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::SetText(CGameText *this, const wchar_t *unicode, bool bClearUnlocalizedSymbol)
{
  const unsigned __int16 *v4; // ebp
  __int16 v5; // kr00_2
  wchar_t *m_UnicodeText; // edx
  const unsigned __int16 *v7; // ecx
  unsigned __int16 v8; // ax

  if ( bClearUnlocalizedSymbol )
    this->m_UnlocalizedTextSymbol = -1;
  v4 = unicode;
  if ( unicode == nullptr )
    v4 = &firstValue;
  v5 = wcslen(v4);
  if ( v5 >= this->m_TextBufferLen )
  {
    if ( this->m_UnicodeText != nullptr )
    {
      free(pMem: this->m_UnicodeText);
      this->m_UnicodeText = nullptr;
    }
    this->m_TextBufferLen = v5 + 1;
    this->m_UnicodeText = (wchar_t *)MemAlloc_Alloc(
                                       nSize: (unsigned __int64)(unsigned int)(__int16)(v5 + 1) >> 31 != 0
                                     ? -1
                                     : 2 * (__int16)(v5 + 1));
  }
  m_UnicodeText = this->m_UnicodeText;
  v7 = v4;
  do
  {
    v8 = *v7;
    *m_UnicodeText++ = *v7++;
  }
  while ( v8 != 0 );
  CGameText::SetupVertexColors(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041B6F0
// Name: public: void CGameText::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::SetText(CGameText *this, const char *text)
{
  const char *v2; // edi
  const wchar_t *v4; // eax
  unsigned int v5; // eax
  wchar_t unicode[1024]; // [esp+8h] [ebp-804h] BYREF

  v2 = text;
  if ( text != nullptr )
  {
    if ( *text == 35 )
    {
      v5 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: text + 1);
      this->m_UnlocalizedTextSymbol = v5;
      if ( v5 != -1 )
      {
        v4 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v5);
        goto LABEL_4;
      }
    }
  }
  else
  {
    v2 = defaultValue;
  }
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v2, a3: &unicode[2], a4: 2048);
  v4 = &unicode[2];
LABEL_4:
  CGameText::SetText(this, unicode: v4, bClearUnlocalizedSymbol: false);
}

//------------------------------------------------------------------------------
// Address: 0x0041B770
// Name: public: CGameText::CGameText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameText *__thiscall CGameText::CGameText(CGameText *this, const char *pName)
{
  const char *v3; // eax
  const char *v4; // eax

  CGameGraphic::CGameGraphic(this);
  this->__vftable = (CGameText_vtbl *)&CGameText::`vftable';
  CUtlString::CUtlString(this: &this->m_CharText);
  CUtlString::CUtlString(this: &this->m_FontName);
  this->m_UnicodeText = nullptr;
  this->m_TextBufferLen = 0;
  this->m_UnlocalizedTextSymbol = -1;
  this->m_Font = 0;
  this->m_bCanAcceptInput = false;
  CUtlString::operator=(this: &this->m_pName, src: pName);
  this->m_Geometry.m_Center.x = 0.0;
  this->m_Geometry.m_Center.y = 0.0;
  this->m_Geometry.m_Scale.x = 1.0;
  this->m_Geometry.m_Scale.y = 1.0;
  this->m_Geometry.m_Rotation = 0.0;
  this->m_Geometry.m_bMaintainAspectRatio = true;
  this->m_Geometry.m_Sublayer = 0;
  this->m_Geometry.m_bVisible = true;
  this->m_CurrentState = -1;
  CUtlString::operator=(this: &this->m_CharText, src: "NONE");
  this->m_bAllCaps = false;
  CUtlString::operator=(this: &this->m_FontName, src: "Default");
  this->m_Justification = 0;
  this->m_Geometry.m_Color.r = -1;
  this->m_Geometry.m_Color.g = -1;
  this->m_Geometry.m_Color.b = -1;
  this->m_Geometry.m_Color.a = -1;
  this->m_Geometry.m_TopColor.r = -1;
  this->m_Geometry.m_TopColor.g = -1;
  this->m_Geometry.m_TopColor.b = -1;
  this->m_Geometry.m_TopColor.a = -1;
  this->m_Geometry.m_BottomColor.r = -1;
  this->m_Geometry.m_BottomColor.g = -1;
  this->m_Geometry.m_BottomColor.b = -1;
  this->m_Geometry.m_BottomColor.a = -1;
  this->m_Geometry.m_bHorizontalGradient = false;
  v3 = CUtlString::operator char const *(this: &this->m_CharText);
  CGameText::SetText(this, text: v3);
  v4 = CUtlString::operator char const *(this: &this->m_FontName);
  CGameText::SetFont(this, pFontName: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041B8B0
// Name: public: bool CGameText::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameText::Unserialize(CGameText *this, CDmxElement *pGraphic)
{
  CDmxElement *v2; // esi
  CDmxAttribute *Attribute; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v5; // eax
  int m_Size; // ebp
  int v7; // esi
  CAnimData *v8; // eax
  CDmxElement *v9; // ebx
  const char *v10; // eax
  const char *v11; // eax
  unsigned __int8 *v12; // ebp
  int (__thiscall **v13)(unsigned __int8 *, const char *, int); // esi
  const char *v14; // eax
  CDmxElement *v16; // [esp-Ch] [ebp-18h]
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v17; // [esp+8h] [ebp-4h]

  v2 = pGraphic;
  CDmxElement::UnpackIntoStructure(this: pGraphic, pData: this, pUnpack: s_GameTextUnpack);
  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: v2, pAttributeName: "imageanims");
  if ( Attribute == nullptr || Attribute->m_Type != AT_FIRST_ARRAY_TYPE )
    return 0;
  v5 = CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
  m_Size = v5->m_Size;
  v7 = 0;
  v17 = v5;
  if ( m_Size <= 0 )
  {
LABEL_9:
    v10 = CUtlString::operator char const *(this: &this->m_CharText);
    CGameText::SetText(this, text: v10);
    v11 = CUtlString::operator char const *(this: &this->m_FontName);
    CUtlString::operator=(this: &this->m_FontName, src: v11);
    if ( CUtlString::Length(this: &this->m_FontName) != 0 )
    {
      v12 = CVTFTexture::LowResImageData(this: (CVTFTexture *)g_pGameUISystemMgrImpl);
      v13 = (int (__thiscall **)(unsigned __int8 *, const char *, int))(*(_DWORD *)v12 + 8);
      v14 = CUtlString::operator char const *(this: &this->m_FontName);
      this->m_Font = (*v13)(a1: v12, a2: v14, a3: 1);
    }
    this->SetState(this, a2: "default", a3: true);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v8 = (CAnimData *)MemAlloc_Alloc(nSize: 0x140u);
      v9 = v8 != nullptr ? (CDmxElement *)CAnimData::CAnimData(this: v8) : nullptr;
      v16 = v17->m_Memory.m_pMemory[v7];
      pGraphic = v9;
      if ( !CAnimData::Unserialize(this: (CAnimData *)v9, pElement: v16) )
        break;
      CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Anims,
        elem: this->m_Anims.m_Size,
        src: (vgui::TreeNode **)&pGraphic);
      if ( ++v7 >= m_Size )
        goto LABEL_9;
    }
    if ( v9 != nullptr )
    {
      CAnimData::~CAnimData(this: (CAnimData *)v9);
      free(pMem: v9);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BA00
// Name: public: virtual class KeyValues __near * CGameText::HandleScriptCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CGameText::HandleScriptCommand(CGameText *this, int args)
{
  KeyValues *v2; // edi
  const char *Name; // ebx
  const char *String; // eax
  const char *v7; // eax
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // al
  KeyValues *v11; // edi
  const char *v12; // eax
  Color v13; // [esp+Ch] [ebp-4h] BYREF

  v2 = (KeyValues *)args;
  Name = KeyValues::GetName(this: (KeyValues *)args);
  if ( _V_stricmp(s1: "SetText", s2: Name) == 0 )
  {
    String = KeyValues::GetString(this: v2, keyName: "text", defaultValue: defaultValue);
    CGameText::SetText(this, text: String);
    return nullptr;
  }
  if ( _V_stricmp(s1: "SetAllCaps", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "SetFont", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "SetJustification", s2: Name) != 0 )
      {
        if ( _V_stricmp(s1: "SetTopColor", s2: Name) != 0 )
        {
          if ( _V_stricmp(s1: "SetBottomColor", s2: Name) != 0 )
          {
            if ( _V_stricmp(s1: "GetFont", s2: Name) != 0 )
            {
              return CGameGraphic::HandleScriptCommand(this, args: v2);
            }
            else
            {
              v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v11 == nullptr )
                return nullptr;
              v12 = CUtlString::Get(this: &this->m_FontName);
              return KeyValues::KeyValues(this: v11, setName: defaultValue, firstKey: "font", firstValue: v12);
            }
          }
          else
          {
            args = -1;
            KeyValues::GetColor(this: v2, result: &v13, keyName: "color", defaultColor: (const Color *)&args);
            this->m_Geometry.m_BottomColor = (color32_s)v13;
            return nullptr;
          }
        }
        else
        {
          args = -1;
          KeyValues::GetColor(this: v2, result: &v13, keyName: "color", defaultColor: (const Color *)&args);
          v8 = v13._color[1];
          v9 = v13._color[3];
          this->m_Geometry.m_TopColor.r = v13._color[0];
          v10 = v13._color[2];
          this->m_Geometry.m_TopColor.g = v8;
          this->m_Geometry.m_TopColor.b = v10;
          this->m_Geometry.m_TopColor.a = v9;
          return nullptr;
        }
      }
      else
      {
        this->m_Justification = KeyValues::GetInt(this: v2, keyName: "justfication", defaultValue: 0);
        return nullptr;
      }
    }
    else
    {
      v7 = KeyValues::GetString(this: v2, keyName: "fontname", defaultValue: defaultValue);
      CGameText::SetFont(this, pFontName: v7);
      return nullptr;
    }
  }
  else
  {
    this->m_bAllCaps = KeyValues::GetInt(this: v2, keyName: "allcaps", defaultValue: 0) != 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BC10
// Name: private: class CRenderGeometry __near * CGameText::GetGeometryEntry(class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
CRenderGeometry *__thiscall CGameText::GetGeometryEntry(
        CGameText *this,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex,
        int fontTextureID)
{
  int v4; // eax
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *m_pMemory; // ecx
  int v6; // ebx
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v7; // edx
  int m_Size; // esi
  int v9; // esi
  int v10; // eax
  CRenderGeometry *result; // eax

  v4 = firstListIndex;
  m_pMemory = renderGeometryLists->m_Memory.m_pMemory;
  v6 = firstListIndex;
  v7 = &renderGeometryLists->m_Memory.m_pMemory[firstListIndex];
  if ( v7->m_Size != 0 )
  {
    m_Size = renderGeometryLists->m_Size;
    if ( firstListIndex < m_Size )
    {
      while ( fontTextureID != v7->m_Memory.m_pMemory->m_SheetSequenceNumber )
      {
        ++v4;
        ++v7;
        if ( v4 >= m_Size )
          goto LABEL_7;
      }
      v9 = v4;
      v10 = CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
              this: &m_pMemory[v4],
              elem: m_pMemory[v4].m_Size);
      m_pMemory = renderGeometryLists->m_Memory.m_pMemory;
      result = &renderGeometryLists->m_Memory.m_pMemory[v9].m_Memory.m_pMemory[v10];
      if ( result != nullptr )
        return result;
LABEL_7:
      v6 = firstListIndex;
      v4 = firstListIndex;
    }
  }
  if ( m_pMemory[v6].m_Size != 0 )
    v4 = CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,int>>::InsertBefore(
           this: renderGeometryLists,
           elem: renderGeometryLists->m_Size);
  return &renderGeometryLists->m_Memory.m_pMemory[v4].m_Memory.m_pMemory[CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
                                                                           this: &renderGeometryLists->m_Memory.m_pMemory[v4],
                                                                           elem: renderGeometryLists->m_Memory.m_pMemory[v4].m_Size)];
}

//------------------------------------------------------------------------------
// Address: 0x0041BCB0
// Name: public: virtual void CGameText::UpdateRenderData(struct color32_s,class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameText::UpdateRenderData(
        CGameText *this,
        color32_s parentColor,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  CGeometry *p_m_Geometry; // ebx
  wchar_t *m_UnicodeText; // eax
  bool v7; // zf
  int v8; // eax
  CRenderGeometry *GeometryEntry; // esi
  __m128 v10; // xmm1
  __m128 x_low; // xmm0
  __m128 v12; // xmm2
  __m128 y_low; // xmm0
  __m128 v14; // xmm2
  int v15; // edx
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm2
  int v24; // edx
  __m128 v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  int v29; // edx
  wchar_t *v30; // eax
  int m_Size; // [esp+4h] [ebp-F0h]
  int v32; // [esp+4h] [ebp-F0h]
  int v33; // [esp+4h] [ebp-F0h]
  int v34; // [esp+4h] [ebp-F0h]
  int v35; // [esp+4h] [ebp-F0h]
  int v36; // [esp+4h] [ebp-F0h]
  int v37; // [esp+4h] [ebp-F0h]
  int v38; // [esp+4h] [ebp-F0h]
  int v39; // [esp+4h] [ebp-F0h]
  int v40; // [esp+18h] [ebp-DCh]
  float *texCoords; // [esp+1Ch] [ebp-D8h] BYREF
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *p_m_RelativePositions; // [esp+20h] [ebp-D4h]
  Vector relativePosition; // [esp+24h] [ebp-D0h] BYREF
  int x; // [esp+30h] [ebp-C4h] BYREF
  Vector screenPosition; // [esp+34h] [ebp-C0h] BYREF
  wchar_t *wsz; // [esp+40h] [ebp-B4h]
  int y; // [esp+44h] [ebp-B0h] BYREF
  Vector2D v48; // [esp+48h] [ebp-ACh] BYREF
  Vector2D v49; // [esp+50h] [ebp-A4h] BYREF
  Vector2D v50; // [esp+58h] [ebp-9Ch] BYREF
  Vector2D v51; // [esp+60h] [ebp-94h] BYREF
  Vector2D v52; // [esp+68h] [ebp-8Ch] BYREF
  Vector2D v53; // [esp+70h] [ebp-84h] BYREF
  Vector2D v54; // [esp+78h] [ebp-7Ch] BYREF
  Vector2D v55; // [esp+80h] [ebp-74h] BYREF
  Vector2D src; // [esp+88h] [ebp-6Ch] BYREF
  Vector2D v57; // [esp+90h] [ebp-64h] BYREF
  Vector2D v58; // [esp+98h] [ebp-5Ch] BYREF
  Vector2D v59; // [esp+A0h] [ebp-54h] BYREF
  Vector2D relPositions[4]; // [esp+A8h] [ebp-4Ch] BYREF
  FontCharRenderInfo info; // [esp+C8h] [ebp-2Ch] BYREF

  if ( this->m_Geometry.m_bVisible && this->m_UnicodeText != nullptr && this->m_Font != 0 )
  {
    p_m_Geometry = &this->m_Geometry;
    p_m_RelativePositions = &this->m_Geometry.m_RelativePositions;
    CGeometry::SetResultantColor(this: &this->m_Geometry, parentColor);
    CGameText::GetStartingTextPosition(this, &x, &y);
    info.currentFont = this->m_Font;
    this->m_Geometry.m_RelativePositions.m_Size = 0;
    m_UnicodeText = this->m_UnicodeText;
    info.drawType = FONT_DRAW_DEFAULT;
    v7 = *m_UnicodeText == 0;
    wsz = m_UnicodeText;
    if ( !v7 )
    {
      v40 = 0;
      while ( 1 )
      {
        v7 = !this->m_bAllCaps;
        info.x = x;
        info.y = y;
        info.ch = *m_UnicodeText;
        if ( !v7 )
          info.ch = towupper(c: info.ch);
        g_pGameUISystemSurface->GetUnicodeCharRenderPositions(this: g_pGameUISystemSurface, a2: &info, a3: relPositions);
        texCoords = nullptr;
        g_pGameUISystemSurface->GetTextureForChar(this: g_pGameUISystemSurface, a2: &info, a3: &texCoords);
        v8 = g_pGameUISystemSurface->GetCharacterWidth(this: g_pGameUISystemSurface, a2: this->m_Font, a3: info.ch);
        x += v8;
        GeometryEntry = CGameText::GetGeometryEntry(
                          this,
                          renderGeometryLists,
                          firstListIndex,
                          fontTextureID: info.textureId);
        GeometryEntry->m_SheetSequenceNumber = info.textureId;
        m_Size = p_m_Geometry->m_RelativePositions.m_Size;
        relativePosition.x = relPositions[0].x;
        relativePosition.y = relPositions[0].y;
        relativePosition.z = 0.0;
        src = relPositions[0];
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &p_m_Geometry->m_RelativePositions,
          elem: m_Size,
          &src);
        VectorTransform(in1: &relativePosition.x, in2: &this->m_Geometry.m_RenderToScreen, out: &screenPosition.x);
        v10.m128_i32[0] = LODWORD(screenPosition.x) & 0x80000000;
        x_low = (__m128)LODWORD(screenPosition.x);
        x_low.m128_f32[0] = (float)(screenPosition.x + COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000))
                          - COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000);
        v12 = x_low;
        v12.m128_f32[0] = x_low.m128_f32[0] - screenPosition.x;
        v12.m128_f32[0] = _mm_cmpgt_ss(v12, v10).m128_f32[0];
        v10.m128_i32[0] = LODWORD(screenPosition.y) & 0x80000000;
        v55.x = x_low.m128_f32[0] - COERCE_FLOAT(v12.m128_i32[0] & 0x3F800000);
        y_low = (__m128)LODWORD(screenPosition.y);
        y_low.m128_f32[0] = (float)(screenPosition.y + COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000))
                          - COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000);
        v14 = y_low;
        v14.m128_f32[0] = y_low.m128_f32[0] - screenPosition.y;
        v32 = GeometryEntry->m_Positions.m_Size;
        v55.y = y_low.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v10).m128_u32[0] & 0x3F800000);
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_Positions,
          elem: v32,
          src: &v55);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&GeometryEntry->m_VertexColors,
          elem: GeometryEntry->m_VertexColors.m_Size,
          src: (vgui::TreeNode **)&this->m_Geometry.m_VertexColors.m_Memory.m_pMemory[v40]);
        v15 = GeometryEntry->m_TextureCoords.m_Size;
        v57 = *(Vector2D *)texCoords;
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_TextureCoords,
          elem: v15,
          src: &v57);
        v33 = p_m_RelativePositions->m_Size;
        relativePosition.x = relPositions[1].x;
        relativePosition.y = relPositions[1].y;
        relativePosition.z = 0.0;
        v50 = relPositions[1];
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(this: p_m_RelativePositions, elem: v33, src: &v50);
        VectorTransform(in1: &relativePosition.x, in2: &this->m_Geometry.m_RenderToScreen, out: &screenPosition.x);
        v10.m128_i32[0] = LODWORD(screenPosition.x) & 0x80000000;
        v16 = (__m128)LODWORD(screenPosition.x);
        v16.m128_f32[0] = (float)(screenPosition.x + COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000))
                        - COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000);
        v17 = v16;
        v17.m128_f32[0] = v16.m128_f32[0] - screenPosition.x;
        v48.x = v16.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v17, v10).m128_f32[0]) & 0x3F800000);
        v10.m128_i32[0] = LODWORD(screenPosition.y) & 0x80000000;
        v18 = (__m128)LODWORD(screenPosition.y);
        v18.m128_f32[0] = (float)(screenPosition.y + COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000))
                        - COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000);
        v19 = v18;
        v19.m128_f32[0] = v18.m128_f32[0] - screenPosition.y;
        v34 = GeometryEntry->m_Positions.m_Size;
        v48.y = v18.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v19, v10).m128_u32[0] & 0x3F800000);
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_Positions,
          elem: v34,
          src: &v48);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&GeometryEntry->m_VertexColors,
          elem: GeometryEntry->m_VertexColors.m_Size,
          src: (vgui::TreeNode **)&this->m_Geometry.m_VertexColors.m_Memory.m_pMemory[v40 + 1]);
        v52.x = texCoords[2];
        v35 = GeometryEntry->m_TextureCoords.m_Size;
        v52.y = texCoords[1];
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_TextureCoords,
          elem: v35,
          src: &v52);
        v36 = p_m_RelativePositions->m_Size;
        relativePosition.x = relPositions[2].x;
        relativePosition.y = relPositions[2].y;
        relativePosition.z = 0.0;
        v59 = relPositions[2];
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(this: p_m_RelativePositions, elem: v36, src: &v59);
        VectorTransform(in1: &relativePosition.x, in2: &this->m_Geometry.m_RenderToScreen, out: &screenPosition.x);
        v10.m128_i32[0] = LODWORD(screenPosition.x) & 0x80000000;
        v20 = (__m128)LODWORD(screenPosition.x);
        v20.m128_f32[0] = (float)(screenPosition.x + COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000))
                        - COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000);
        v21 = v20;
        v21.m128_f32[0] = v20.m128_f32[0] - screenPosition.x;
        v54.x = v20.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v21, v10).m128_f32[0]) & 0x3F800000);
        v10.m128_i32[0] = LODWORD(screenPosition.y) & 0x80000000;
        v22 = (__m128)LODWORD(screenPosition.y);
        v22.m128_f32[0] = (float)(screenPosition.y + COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000))
                        - COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000);
        v23 = v22;
        v23.m128_f32[0] = v22.m128_f32[0] - screenPosition.y;
        v37 = GeometryEntry->m_Positions.m_Size;
        v54.y = v22.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v23, v10).m128_u32[0] & 0x3F800000);
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_Positions,
          elem: v37,
          src: &v54);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&GeometryEntry->m_VertexColors,
          elem: GeometryEntry->m_VertexColors.m_Size,
          src: (vgui::TreeNode **)&this->m_Geometry.m_VertexColors.m_Memory.m_pMemory[v40 + 2]);
        v24 = GeometryEntry->m_TextureCoords.m_Size;
        v58 = *((Vector2D *)texCoords + 1);
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_TextureCoords,
          elem: v24,
          src: &v58);
        v38 = p_m_RelativePositions->m_Size;
        relativePosition.x = relPositions[3].x;
        relativePosition.y = relPositions[3].y;
        relativePosition.z = 0.0;
        v49 = relPositions[3];
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(this: p_m_RelativePositions, elem: v38, src: &v49);
        VectorTransform(in1: &relativePosition.x, in2: &this->m_Geometry.m_RenderToScreen, out: &screenPosition.x);
        v10.m128_i32[0] = LODWORD(screenPosition.x) & 0x80000000;
        v25 = (__m128)LODWORD(screenPosition.x);
        v25.m128_f32[0] = (float)(screenPosition.x + COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000))
                        - COERCE_FLOAT(LODWORD(screenPosition.x) & 0x80000000 | 0x4B000000);
        v26 = v25;
        v26.m128_f32[0] = v25.m128_f32[0] - screenPosition.x;
        v51.x = v25.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v26, v10).m128_f32[0]) & 0x3F800000);
        v10.m128_i32[0] = LODWORD(screenPosition.y) & 0x80000000;
        v27 = (__m128)LODWORD(screenPosition.y);
        v27.m128_f32[0] = (float)(screenPosition.y + COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000))
                        - COERCE_FLOAT(v10.m128_i32[0] | 0x4B000000);
        v28 = v27;
        v28.m128_f32[0] = v27.m128_f32[0] - screenPosition.y;
        v39 = GeometryEntry->m_Positions.m_Size;
        v51.y = v27.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v28, v10).m128_u32[0] & 0x3F800000);
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_Positions,
          elem: v39,
          src: &v51);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&GeometryEntry->m_VertexColors,
          elem: GeometryEntry->m_VertexColors.m_Size,
          src: (vgui::TreeNode **)&this->m_Geometry.m_VertexColors.m_Memory.m_pMemory[v40 + 3]);
        v29 = GeometryEntry->m_TextureCoords.m_Size;
        v53.x = *texCoords;
        v53.y = texCoords[3];
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &GeometryEntry->m_TextureCoords,
          elem: v29,
          src: &v53);
        v40 += 4;
        GeometryEntry->m_AnimationRate = this->m_Geometry.m_AnimationRate;
        p_m_Geometry = (CGeometry *)p_m_RelativePositions;
        GeometryEntry->m_AnimStartTime.m_tms = this->m_Geometry.m_AnimStartTime.m_tms;
        v30 = wsz + 1;
        GeometryEntry->m_bAnimate = this->m_Geometry.m_bAnimate;
        GeometryEntry->m_pImageAlias = nullptr;
        v7 = *v30 == 0;
        wsz = v30;
        if ( v7 )
          break;
        m_UnicodeText = wsz;
      }
    }
    CGeometry::CalculateExtents(this: p_m_Geometry);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C350
// Name: public: virtual class CGameGraphic __near * CGameTextClassFactory::CreateNewGraphicClass(class KeyValues __near *,class CGameUIDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
CGameText *__thiscall CGameTextClassFactory::CreateNewGraphicClass(
        CGameTextClassFactory *this,
        KeyValues *kvRequest,
        CGameUIDefinition *pMenu)
{
  CGameText *v3; // edi
  const char *String; // esi
  CGameText *v5; // eax
  KeyValues *i; // esi

  v3 = nullptr;
  String = KeyValues::GetString(this: kvRequest, keyName: "name", defaultValue: nullptr);
  if ( String != nullptr )
  {
    v5 = (CGameText *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v5 != nullptr )
      v3 = CGameText::CGameText(this: v5, pName: String);
    else
      v3 = nullptr;
    CGameUIDefinition::AddGraphicToLayer(this: pMenu, pGraphic: v3, nLayerType: 2);
    for ( i = KeyValues::GetFirstSubKey(this: kvRequest); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      v3->HandleScriptCommand(this: v3, a2: i);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005335A0
// Name: CGameText_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CGameText_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CGameText>();
  s_pUnpack_2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005335B0
// Name: _dynamic_initializer_for__s_GameTextUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_GameTextUnpack__()
{
  s_GameTextUnpack = s_pUnpack_2;
  return s_pUnpack_2;
}

//------------------------------------------------------------------------------
// Address: 0x005335C0
// Name: _dynamic_initializer_for__g_mapScriptHandles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_mapScriptHandles__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_mapScriptHandles__);
}
