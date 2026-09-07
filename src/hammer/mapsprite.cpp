// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapsprite.cpp
// Functions: 18
// ============================================================

#include "hammer\mapsprite.h"

//------------------------------------------------------------------------------
// Address: 0x10144FF0
// Name: public: virtual char const __near * CMapSprite::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapSprite::GetType(CMapSprite *this)
{
  return CMapSprite::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10145000
// Name: public: virtual int CMapSprite::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapSprite::IsMapClass(CMapSprite *this, const char *Type)
{
  return Type == CMapSprite::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10145020
// Name: public: virtual char const __near * CMapSprite::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapSprite::GetDescription(CMapSprite *this)
{
  return "Sprite";
}

//------------------------------------------------------------------------------
// Address: 0x10145030
// Name: protected: void CMapSprite::SetRenderMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::SetRenderMode(CMapSprite *this, int eRenderMode)
{
  CSpriteModel *m_pSpriteInfo; // ecx

  this->m_eRenderMode = eRenderMode;
  m_pSpriteInfo = this->m_pSpriteInfo;
  if ( m_pSpriteInfo != nullptr )
    CSpriteModel::SetRenderMode(this: m_pSpriteInfo, mode: eRenderMode);
}

//------------------------------------------------------------------------------
// Address: 0x10145050
// Name: public: virtual class CMapClass __near * CMapSprite::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapSprite *__thiscall CMapSprite::CopyFrom(CMapSprite *this, CVisGroup *pObject, bool bUpdateDependencies)
{
  char *v4; // edi
  CSpriteModel *m_pSpriteInfo; // ecx
  int v6; // eax

  v4 = (char *)__RTDynamicCast(
                 inptr: pObject,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapSprite `RTTI Type Descriptor',
                 isReference: 0);
  if ( pObject != nullptr )
  {
    CMapClass::CopyFrom(this, pFrom: pObject, bUpdateDependencies);
    this->m_Angles.x = *((float *)v4 + 54);
    this->m_Angles.y = *((float *)v4 + 55);
    this->m_Angles.z = *((float *)v4 + 56);
    this->m_pSpriteInfo = *((CSpriteModel **)v4 + 57);
    CSpriteCache::AddRef(pSprite: *((CSpriteModel **)v4 + 57));
    m_pSpriteInfo = this->m_pSpriteInfo;
    this->m_nCurrentFrame = *((_DWORD *)v4 + 58);
    this->m_fSecondsPerFrame = *((float *)v4 + 59);
    this->m_fElapsedTimeThisFrame = *((float *)v4 + 60);
    this->m_fScale = *((float *)v4 + 61);
    v6 = *((_DWORD *)v4 + 62);
    this->m_eRenderMode = v6;
    if ( m_pSpriteInfo != nullptr )
      CSpriteModel::SetRenderMode(this: m_pSpriteInfo, mode: v6);
    *(_QWORD *)&this->m_RenderColor.r = *(_QWORD *)(v4 + 252);
    *(_QWORD *)&this->m_RenderColor.b = *(_QWORD *)(v4 + 260);
    this->m_bIsIcon = v4[268];
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10145150
// Name: protected: int CMapSprite::GetNextSpriteFrame(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSprite::GetNextSpriteFrame(CMapSprite *this, CRender3D *pRender)
{
  int FrameCount; // edi
  float v4; // xmm0_4
  float m_fSecondsPerFrame; // xmm1_4
  int m_nCurrentFrame; // eax
  int v7; // edx
  float fElapsedTime; // [esp+10h] [ebp+8h]

  FrameCount = CSpriteModel::GetFrameCount(this: this->m_pSpriteInfo);
  if ( FrameCount <= 1 )
    return this->m_nCurrentFrame;
  fElapsedTime = CRender3D::GetElapsedTime(this: pRender);
  v4 = fElapsedTime + this->m_fElapsedTimeThisFrame;
  m_fSecondsPerFrame = this->m_fSecondsPerFrame;
  this->m_fElapsedTimeThisFrame = v4;
  if ( v4 > m_fSecondsPerFrame )
  {
    m_nCurrentFrame = this->m_nCurrentFrame;
    do
    {
      ++m_nCurrentFrame;
      v4 = v4 - m_fSecondsPerFrame;
      this->m_nCurrentFrame = m_nCurrentFrame;
      this->m_fElapsedTimeThisFrame = v4;
    }
    while ( v4 > this->m_fSecondsPerFrame );
  }
  v7 = this->m_nCurrentFrame % FrameCount;
  this->m_nCurrentFrame = v7;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101451F0
// Name: protected: virtual void CMapSprite::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::DoTransform(CMapSprite *this, const VMatrix *matrix)
{
  QAngle *v2; // esi
  matrix3x4_t fMatrixNew; // [esp+8h] [ebp-60h] BYREF
  matrix3x4_t fCurrentMatrix; // [esp+38h] [ebp-30h] BYREF

  v2 = (QAngle *)this;
  CMapClass::DoTransform(this, matrix);
  v2 += 18;
  AngleMatrix(angles: v2, matrix: &fCurrentMatrix);
  ConcatTransforms(in1: (const matrix3x4_t *)matrix, in2: &fCurrentMatrix, out: &fMatrixNew);
  MatrixAngles(src: (const VMatrix *)&fMatrixNew, vAngles: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10145240
// Name: protected: void CMapSprite::SpriteColor(unsigned char __near *,int,struct colorVec,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::SpriteColor(
        CMapSprite *this,
        unsigned __int8 *pColor,
        int eRenderMode,
        colorVec RenderColor,
        int alpha)
{
  int v5; // eax
  int v6; // eax

  if ( eRenderMode == 5 || eRenderMode == 3 || (v5 = 256, eRenderMode == 9) )
    v5 = alpha;
  if ( RenderColor.r != 0 || RenderColor.g != 0 || RenderColor.b != 0 )
  {
    *pColor = (unsigned __int16)(v5 * LOWORD(RenderColor.r)) >> 8;
    pColor[1] = (unsigned __int16)(v5 * LOWORD(RenderColor.g)) >> 8;
    pColor[2] = (unsigned __int16)(v5 * LOWORD(RenderColor.b)) >> 8;
  }
  else
  {
    v6 = (255 * v5) >> 8;
    pColor[2] = v6;
    pColor[1] = v6;
    *pColor = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101452C0
// Name: public: virtual void CMapSprite::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::OnParentKeyChanged(CMapSprite *this, const char *szKey, const char *szValue)
{
  long double v4; // st7
  long double v5; // st7
  float szKeya; // [esp+18h] [ebp+Ch]

  if ( _V_stricmp(s1: szKey, s2: "framerate") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "scale") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "rendermode") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "_light") != 0 )
        {
          if ( _V_stricmp(s1: szKey, s2: "angles") == 0 )
          {
            sscanf(string: szValue, format: "%f %f %f", &this->m_Angles, &this->m_Angles.y, &this->m_Angles.z);
            this->PostUpdate(this, a2: Notify_Changed);
          }
        }
        else
        {
          sscanf(
            string: szValue,
            format: "%d %d %d",
            &this->m_RenderColor,
            &this->m_RenderColor.g,
            &this->m_RenderColor.b);
        }
      }
      else
      {
        switch ( atoi(nptr: szValue) )
        {
          case 0:
          case 2:
          case 4:
            CMapSprite::SetRenderMode(this, eRenderMode: 0);
            break;
          case 1:
            CMapSprite::SetRenderMode(this, eRenderMode: 1);
            break;
          case 3:
            CMapSprite::SetRenderMode(this, eRenderMode: 3);
            break;
          case 5:
            CMapSprite::SetRenderMode(this, eRenderMode: 5);
            break;
          case 7:
            CMapSprite::SetRenderMode(this, eRenderMode: 7);
            break;
          case 9:
            CMapSprite::SetRenderMode(this, eRenderMode: 9);
            break;
          default:
            return;
        }
      }
    }
    else
    {
      v5 = atof(nptr: szValue);
      this->m_fScale = v5;
      if ( v5 == 0.0 )
        this->m_fScale = 1.0;
      CSpriteModel::SetScale(this: this->m_pSpriteInfo, fScale: this->m_fScale);
      this->PostUpdate(this, a2: Notify_Changed);
    }
  }
  else
  {
    v4 = atof(nptr: szValue);
    if ( fabs(v4) > 0.001 )
    {
      szKeya = v4;
      this->m_fSecondsPerFrame = 1.0 / szKeya;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101454C0
// Name: public: virtual void CMapSprite::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::Render2D(CMapSprite *this, CRender2D *pRender)
{
  Vector vCenter; // [esp+8h] [ebp-34h] BYREF
  Vector vecMins; // [esp+14h] [ebp-28h] BYREF
  Vector vecMaxs; // [esp+20h] [ebp-1Ch] BYREF
  Vector2D pt2; // [esp+2Ch] [ebp-10h] BYREF
  Vector2D pt; // [esp+34h] [ebp-8h] BYREF

  CMapClass::GetRender2DBox(this, mins: &vecMins, maxs: &vecMaxs);
  CRender::TransformPoint(this: pRender, vClient: &pt, vWorld: &vecMins);
  CRender::TransformPoint(this: pRender, vClient: &pt2, vWorld: &vecMaxs);
  if ( this->IsSelected(this) )
  {
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
    CRender::SetHandleColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
  }
  else
  {
    CRender::SetDrawColor(this: pRender, r: this->r, g: this->g, b: this->b);
    CRender::SetHandleColor(this: pRender, r: this->r, g: this->g, b: this->b);
  }
  pRender->DrawBox(this: pRender, a2: &vecMins, a3: &vecMaxs, a4: false);
  if ( CRender::IsActiveView(this: pRender)
    && (int)(float)(fabs(pt.x - pt2.x) + 1.0) > 6
    && (int)(float)(fabs(pt.y - pt2.y) + 1.0) > 6 )
  {
    CRender::SetHandleStyle(this: pRender, size: 4, type: 4);
    vCenter.x = (float)(vecMaxs.x + vecMins.x) * 0.5;
    vCenter.y = (float)(vecMins.y + vecMaxs.y) * 0.5;
    vCenter.z = (float)(vecMaxs.z + vecMins.z) * 0.5;
    CRender::DrawHandle(this: pRender, &vCenter, vOffset: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145630
// Name: public: CMapSprite::CMapSprite(void)
// Source: json
//------------------------------------------------------------------------------
CMapSprite *__thiscall CMapSprite::CMapSprite(CMapSprite *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapSprite_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapSprite_vtbl *)&CMapSprite::`vftable';
  this->m_Angles.x = 0.0;
  this->m_Angles.y = 0.0;
  this->m_Angles.z = 0.0;
  this->m_fElapsedTimeThisFrame = 0.0;
  this->m_eRenderMode = 0;
  this->m_RenderColor.r = 255;
  this->m_RenderColor.g = 255;
  this->m_RenderColor.b = 255;
  this->m_fSecondsPerFrame = 1.0;
  this->m_nCurrentFrame = 0;
  this->m_fScale = 0.25;
  this->m_bIsIcon = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10145760
// Name: public: virtual void CMapSprite::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::CalcBounds(CMapSprite *this, int bFullUpdate)
{
  CSpriteModel *m_pSpriteInfo; // eax
  float v4; // xmm0_4
  int v5; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  Vector Mins; // [esp+4h] [ebp-18h] BYREF
  Vector Maxs; // [esp+10h] [ebp-Ch] BYREF
  float fRadius; // [esp+24h] [ebp+8h]

  CMapClass::CalcBounds(this, bFullUpdate);
  m_pSpriteInfo = this->m_pSpriteInfo;
  v4 = 8.0;
  fRadius = 8.0;
  if ( m_pSpriteInfo != nullptr )
  {
    v5 = m_pSpriteInfo->m_Width <= m_pSpriteInfo->m_Height ? m_pSpriteInfo->m_Height : m_pSpriteInfo->m_Width;
    v4 = (float)((float)v5 * this->m_fScale) * 0.5;
    fRadius = v4;
    if ( v4 == 0.0 )
    {
      v4 = 8.0;
      fRadius = 8.0;
    }
  }
  x = this->m_Origin.x;
  Mins.x = x - v4;
  y = this->m_Origin.y;
  Mins.y = y - v4;
  z = this->m_Origin.z;
  Mins.z = z - v4;
  Maxs.x = x + v4;
  Maxs.y = y + v4;
  Maxs.z = z + v4;
  BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &Mins, maxs: &Maxs);
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
  if ( this->m_bIsIcon )
    v9 = fRadius;
  else
    v9 = 2.0;
  v10 = this->m_Origin.y - v9;
  v11 = this->m_Origin.z - v9;
  v12 = this->m_Origin.x + v9;
  v13 = this->m_Origin.y + v9;
  v14 = this->m_Origin.z + v9;
  Mins.x = this->m_Origin.x - v9;
  Mins.y = v10;
  Mins.z = v11;
  Maxs.x = v12;
  Maxs.y = v13;
  Maxs.z = v14;
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &Mins, maxs: &Maxs);
}

//------------------------------------------------------------------------------
// Address: 0x101458D0
// Name: public: virtual class CMapClass __near * CMapSprite::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapSprite *__thiscall CMapSprite::Copy(CMapSprite *this, BOOL bUpdateDependencies)
{
  CMapSprite *v3; // eax
  CMapSprite *v4; // esi

  v3 = (CMapSprite *)operator new(nSize: 0x110u);
  if ( v3 != nullptr )
    v4 = CMapSprite::CMapSprite(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10145950
// Name: public: virtual void CMapSprite::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::Render3D(CMapSprite *this, CRender3D *pRender)
{
  SelectionState_t v2; // eax
  long double v3; // rdi
  int NextSpriteFrame; // eax
  int i; // ebx
  float v6; // xmm0_4
  double v7; // xmm0_8
  int v8; // eax
  bool v9; // zf
  __int16 v10; // ax
  SelectionState_t v11; // eax
  float v12; // [esp+0h] [ebp-24h]
  __int64 v13; // [esp+10h] [ebp-14h]
  __int64 v14; // [esp+18h] [ebp-Ch]
  int v15; // [esp+20h] [ebp-4h]

  HIDWORD(v3) = this;
  v2 = this->GetSelectionState(this);
  LODWORD(v3) = pRender;
  if ( v2 == SELECT_NONE || *(_BYTE *)(HIDWORD(v3) + 268) != 0 )
    v15 = 1;
  else
    v15 = CRender3D::NeedsOverlay(this: pRender) + 2;
  if ( *(_DWORD *)(HIDWORD(v3) + 228) != 0 )
  {
    if ( *(_BYTE *)(HIDWORD(v3) + 268) != 0 )
      CRender3D::BeginRenderHitTarget(this: (CRender3D *)LODWORD(v3), pObject: (CMapInstance *)HIDWORD(v3), uHandle: 0);
    CSpriteModel::SetOrigin(this: *(CSpriteModel **)(HIDWORD(v3) + 228), v: (const Vector *)(HIDWORD(v3) + 20));
    CSpriteModel::SetAngles(this: *(CSpriteModel **)(HIDWORD(v3) + 228), pfAngles: (const QAngle *)(HIDWORD(v3) + 216));
    NextSpriteFrame = CMapSprite::GetNextSpriteFrame(this: (CMapSprite *)HIDWORD(v3), pRender: (CRender3D *)LODWORD(v3));
    CSpriteModel::Bind(
      this: *(CSpriteModel **)(HIDWORD(v3) + 228),
      pRender: (CRender *)LODWORD(v3),
      frame: NextSpriteFrame);
    for ( i = 0; i < v15; ++i )
    {
      if ( i != 0 )
      {
        if ( i == v15 - 1 )
          CRender::PushRenderMode(this: (CRender *)LODWORD(v3), eRenderMode: RENDER_MODE_WIREFRAME);
        else
          CRender::PushRenderMode(this: (CRender *)LODWORD(v3), eRenderMode: RENDER_MODE_SELECTION_OVERLAY);
      }
      else if ( *(_DWORD *)(LODWORD(v3) + 700) == 11 )
      {
        CRender::PushRenderMode(this: (CRender *)LODWORD(v3), eRenderMode: RENDER_MODE_TEXTURED);
      }
      else
      {
        CRender::PushRenderMode(this: (CRender *)LODWORD(v3), eRenderMode: RENDER_MODE_CURRENT);
      }
      v6 = *(float *)(HIDWORD(v3) + 244);
      if ( v6 <= 0.0 )
        v7 = 1.0;
      else
        v7 = v6;
      v12 = v7;
      CSpriteModel::SetScale(this: *(CSpriteModel **)(HIDWORD(v3) + 228), fScale: v12);
      v8 = *(_DWORD *)(HIDWORD(v3) + 248);
      v13 = *(_QWORD *)(HIDWORD(v3) + 252);
      v14 = *(_QWORD *)(HIDWORD(v3) + 260);
      if ( v8 == 5 || v8 == 3 || (v9 = v8 == 9, v10 = 256, v9) )
        v10 = 255;
      if ( (_DWORD)v13 != 0 || __PAIR64__(HIDWORD(v13), 0) != (unsigned int)v14 )
      {
        LOBYTE(pRender) = (unsigned __int16)(v10 * v13) >> 8;
        BYTE1(pRender) = (unsigned __int16)(v10 * WORD2(v13)) >> 8;
        BYTE2(pRender) = (unsigned __int16)(v10 * v14) >> 8;
      }
      else
      {
        BYTE2(pRender) = (unsigned __int16)(255 * v10) >> 8;
        BYTE1(pRender) = BYTE2(pRender);
        LOBYTE(pRender) = BYTE2(pRender);
      }
      if ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v3) + 8))(a1: HIDWORD(v3)) != 0 )
      {
        if ( *(_BYTE *)(HIDWORD(v3) + 268) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, int, int, int, int, _DWORD))(*(_DWORD *)LODWORD(v3) + 40))(
            a1: LODWORD(v3),
            a2: HIDWORD(v3) + 100,
            a3: HIDWORD(v3) + 112,
            a4: 255,
            a5: 255,
            a6: 0);
        }
        else
        {
          LOBYTE(pRender) = -1;
          *(_WORD *)((char *)&pRender + 1) = 0;
        }
        if ( i > 0 )
        {
          LOWORD(pRender) = -1;
          BYTE2(pRender) = 0;
        }
      }
      CSpriteModel::SetMaterialPrimitiveType(
        this: *(CSpriteModel **)(HIDWORD(v3) + 228),
        type: (MaterialPrimitiveType_t)((i <= 0) + 5));
      CSpriteModel::DrawSprite3D(
        this: *(CSpriteModel **)(HIDWORD(v3) + 228),
        a2: v3,
        pRender: (CRender3D *)LODWORD(v3),
        color: (unsigned __int8 *)&pRender);
      CRender::PopRenderMode(this: (CRender *)LODWORD(v3));
    }
    if ( *(_BYTE *)(HIDWORD(v3) + 268) != 0 )
      CRender3D::EndRenderHitTarget(this: (CRender3D *)LODWORD(v3), a2: SLODWORD(v3));
  }
  else if ( *(_BYTE *)(HIDWORD(v3) + 268) != 0 )
  {
    CRender3D::BeginRenderHitTarget(this: (CRender3D *)LODWORD(v3), pObject: (CMapInstance *)HIDWORD(v3), uHandle: 0);
    v11 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v3) + 8))(a1: HIDWORD(v3));
    CRender3D::RenderBox(
      this: (CRender3D *)LODWORD(v3),
      Mins: (const Vector *)(HIDWORD(v3) + 100),
      Maxs: (const Vector *)(HIDWORD(v3) + 112),
      chRed: *(_BYTE *)(HIDWORD(v3) + 16),
      chGreen: *(_BYTE *)(HIDWORD(v3) + 17),
      chBlue: *(_BYTE *)(HIDWORD(v3) + 18),
      eBoxSelectionState: v11);
    CRender3D::EndRenderHitTarget(this: (CRender3D *)LODWORD(v3), a2: SLODWORD(v3));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145BC0
// Name: class CMapClass __near * CMapSprite_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapSprite *__cdecl CMapSprite_CreateObject()
{
  CMapSprite *v0; // eax

  v0 = (CMapSprite *)operator new(nSize: 0x110u);
  if ( v0 != nullptr )
    return CMapSprite::CMapSprite(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10145C20
// Name: public: static class CMapSprite __near * CMapSprite::CreateMapSprite(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSprite *__cdecl CMapSprite::CreateMapSprite(const char *pszSpritePath)
{
  CMapSprite *v1; // eax
  CMapSprite *v2; // esi
  _BYTE *v3; // eax
  CSpriteModel *Sprite; // eax
  char szPath[260]; // [esp+8h] [ebp-114h] BYREF
  CMapSprite *v7; // [esp+10Ch] [ebp-10h]
  int v8; // [esp+118h] [ebp-4h]

  v1 = (CMapSprite *)operator new(nSize: 0x110u);
  v7 = v1;
  v8 = 0;
  if ( v1 != nullptr )
    v2 = CMapSprite::CMapSprite(this: v1);
  else
    v2 = nullptr;
  v8 = -1;
  if ( v2 != nullptr )
  {
    v2->m_Angles.x = 0.0;
    v2->m_Angles.y = 0.0;
    v2->m_Angles.z = 0.0;
    v2->m_RenderColor.r = 255;
    v2->m_RenderColor.g = 255;
    v2->m_RenderColor.b = 255;
    v2->m_fElapsedTimeThisFrame = 0.0;
    v2->m_eRenderMode = 0;
    v2->m_fSecondsPerFrame = 1.0;
    v2->m_nCurrentFrame = 0;
    v2->m_fScale = 0.25;
    v2->m_bIsIcon = false;
    strcpy(szPath, pszSpritePath);
    strrchr(string: (unsigned __int8 *)szPath, chr: 0x2Eu);
    if ( v3 != nullptr )
      *v3 = 0;
    Sprite = CSpriteCache::CreateSprite(pszSpritePath: szPath);
    v2->m_pSpriteInfo = Sprite;
    if ( Sprite != nullptr )
      v2->CalcBounds(this: v2, a2: 0);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10145D50
// Name: public: void CMapSprite::RenderLogicalAt(class CRender2D __near *,class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSprite::RenderLogicalAt(
        CMapSprite *this,
        CRender2D *pRender,
        const Vector2D *vecMins,
        const Vector2D *vecMaxs)
{
  CSpriteModel *m_pSpriteInfo; // ecx
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  IMesh *v8; // edi
  float *m_pCurrPosition; // eax
  float y; // xmm1_4
  unsigned __int8 v11; // si
  int v12; // ecx
  int v13; // edx
  float *v14; // eax
  unsigned int v15; // esi
  float v16; // xmm1_4
  float *v17; // eax
  float *v18; // eax
  float v19; // xmm1_4
  float *v20; // eax
  float *v21; // eax
  float *v22; // eax
  float v23; // xmm1_4
  float *v24; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *v26; // esi
  int m_eRenderMode; // [esp-18h] [ebp-224h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-200h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-18h]
  IMatRenderContext *v30; // [esp+1F8h] [ebp-14h]
  unsigned __int8 color[4]; // [esp+1FCh] [ebp-10h] BYREF
  int v32; // [esp+208h] [ebp-4h]
  colorVec m_RenderColor; // 0:^8.16

  m_pSpriteInfo = this->m_pSpriteInfo;
  if ( m_pSpriteInfo != nullptr )
  {
    CSpriteModel::Bind(this: m_pSpriteInfo, pRender, frame: 0);
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TEXTURED);
    m_RenderColor = this->m_RenderColor;
    m_eRenderMode = this->m_eRenderMode;
    *(_WORD *)color = -1;
    color[2] = -1;
    CMapSprite::SpriteColor(this, pColor: color, eRenderMode: m_eRenderMode, RenderColor: m_RenderColor, alpha: 255);
    if ( this->GetSelectionState(this) != SELECT_NONE )
    {
      color[0] = -1;
      *(_WORD *)&color[1] = 0;
    }
    v6 = materials->GetRenderContext(this: materials);
    v7 = v6;
    v30 = v6;
    pRenderContext.m_pObject = v6;
    v32 = 0;
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    v32 = 1;
    v8 = v7->GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    LOBYTE(v32) = 2;
    meshBuilder.m_pMesh = v8;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_POLYGON;
    v8->SetPrimitiveType(this: v8, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v8, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    y = vecMins->y;
    v11 = color[0];
    v12 = color[1];
    v13 = color[2];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vecMins->x;
    m_pCurrPosition[1] = y;
    m_pCurrPosition[2] = 0.0;
    v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v14[1] = 1.0;
    v15 = v13 | ((v12 | ((*(_DWORD *)&v11 | 0xFFFFFF00) << 8)) << 8);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v15;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v16 = vecMaxs->y;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vecMins->x;
    v17[1] = v16;
    v17[2] = 0.0;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v18[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v15;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v19 = vecMaxs->y;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vecMaxs->x;
    v20[1] = v19;
    v20[2] = 0.0;
    v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v21[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v15;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v23 = vecMins->y;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vecMaxs->x;
    v22[1] = v23;
    v22[2] = 0.0;
    v24 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v24[1] = 1.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v15;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v8->Draw_2(this: v8, a2: -1, a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v32) = 1;
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    v32 = 3;
    v26 = v30;
    v30->EndRender(this: v30);
    v32 = -1;
    v26->Release(this: v26);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146120
// Name: public: static class CMapClass __near * CMapSprite::CreateMapSprite(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSprite *__cdecl CMapSprite::CreateMapSprite(CHelperInfo *pHelperInfo, CMapEntity *pParent)
{
  char *Value; // esi
  char v3; // al
  CMapSprite *result; // eax
  CMapSprite *MapSprite; // esi
  int v6; // eax
  CSpriteModel *m_pSpriteInfo; // ecx

  if ( (pHelperInfo->m_Parameters.m_Size > 0 && (Value = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) != nullptr
     || (Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                           this: &pParent->m_KeyValues,
                           pszKey: "model",
                           piIndex: nullptr)) != nullptr)
    && V_strncasecmp(s1: Value, s2: "materials", n: 9) == 0 )
  {
    v3 = Value[9];
    if ( v3 == 47 || v3 == 92 )
      Value += 10;
  }
  result = nullptr;
  if ( Value != nullptr )
  {
    MapSprite = CMapSprite::CreateMapSprite(pszSpritePath: Value);
    if ( MapSprite != nullptr )
    {
      v6 = _V_stricmp(s1: pHelperInfo->m_szName, s2: "iconsprite");
      m_pSpriteInfo = MapSprite->m_pSpriteInfo;
      if ( v6 == 0 )
      {
        MapSprite->m_eRenderMode = 4;
        if ( m_pSpriteInfo != nullptr )
          CSpriteModel::SetRenderMode(this: m_pSpriteInfo, mode: 4);
        MapSprite->m_bIsIcon = true;
        return MapSprite;
      }
      if ( m_pSpriteInfo != nullptr )
        CSpriteModel::SetRenderMode(this: m_pSpriteInfo, mode: MapSprite->m_eRenderMode);
    }
    return MapSprite;
  }
  return result;
}
