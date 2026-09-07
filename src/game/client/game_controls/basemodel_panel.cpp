// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/game_controls/basemodel_panel.cpp
// Functions: 23
// ============================================================

#include "game\client\game_controls\basemodel_panel.h"

//------------------------------------------------------------------------------
// Address: 0x10235E40
// Name: public: static char const __near * CBaseModelPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseModelPanel::GetPanelClassName()
{
  return "CBaseModelPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10235E50
// Name: private: static void __near * CBaseModelPanel::GetVar_m_bStartFramed(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl CBaseModelPanel::GetVar_m_bStartFramed(vgui::Panel *panel)
{
  return &panel[9].m_sNavUpName;
}

//------------------------------------------------------------------------------
// Address: 0x10235E60
// Name: private: static void __near * CBaseModelPanel::GetVar_m_bDisableManipulation(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CBaseModelPanel::GetVar_m_bDisableManipulation(vgui::Panel *panel)
{
  return (char *)&panel[9].m_sNavUpName.m_Storage.m_Memory.m_pMemory + 2;
}

//------------------------------------------------------------------------------
// Address: 0x10235E70
// Name: public: virtual void CBaseModelPanel::SetMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::SetMDL(CBaseModelPanel *this, const char *pMDLName)
{
  CMDLPanel::SetSequence(this, nSequence: 0);
  CMDLPanel::SetMDL(this, pMDLName, pProxyData: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10235E90
// Name: public: virtual void CBaseModelPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::OnMousePressed(CBaseModelPanel *this, ButtonCode_t code)
{
  int v3; // ecx
  int height; // [esp+4h] [ebp-10h] BYREF
  int width; // [esp+8h] [ebp-Ch] BYREF
  int ypos; // [esp+Ch] [ebp-8h] BYREF
  int xpos; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_bAllowRotation )
  {
    this->RequestFocus(this, a2: 0);
    CPotteryWheelPanel::EnableMouseCapture(this, enable: true, mouseCode: code);
    vgui::Panel::GetSize(this, wide: &width, tall: &height);
    xpos = width / 2;
    ypos = height / 2;
    vgui::Panel::LocalToScreen(this, x: &xpos, y: &ypos);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: xpos, a3: ypos);
    v3 = ypos;
    this->m_nManipStartX = xpos;
    this->m_nManipStartY = v3;
    this->m_bMousePressed = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10235F30
// Name: public: virtual void CBaseModelPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::OnMouseReleased(CBaseModelPanel *this, ButtonCode_t code)
{
  if ( this->m_bAllowRotation )
  {
    CPotteryWheelPanel::EnableMouseCapture(this, enable: false, mouseCode: BUTTON_CODE_INVALID);
    this->m_bMousePressed = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10235F50
// Name: public: virtual void CBaseModelPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::OnCursorMoved(CBaseModelPanel *this, int x, int y)
{
  float v4; // xmm0_4
  float v5; // xmm0_4
  int ypos; // [esp+4h] [ebp-8h] BYREF
  int xpos; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_bAllowRotation && this->m_bMousePressed )
  {
    CPotteryWheelPanel::WarpMouse(this, &x, &y);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &xpos, a3: &ypos);
    v4 = (float)(xpos - this->m_nManipStartX) + this->m_angPlayer.y;
    this->m_angPlayer.y = v4;
    if ( v4 <= 360.0 )
    {
      if ( v4 >= -360.0 )
      {
LABEL_8:
        CMDLPanel::SetModelAnglesAndPosition(this, angRot: &this->m_angPlayer, vecPos: &this->m_vecPlayerPos);
        return;
      }
      v5 = v4 + 360.0;
    }
    else
    {
      v5 = v4 - 360.0;
    }
    this->m_angPlayer.y = v5;
    goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236000
// Name: private: int CBaseModelPanel::FindSequenceFromActivity(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseModelPanel::FindSequenceFromActivity(
        CBaseModelPanel *this,
        CStudioHdr *pStudioHdr,
        const char *pszActivity)
{
  int i; // esi
  int v5; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v7; // eax
  mstudioseqdesc_t *v8; // eax

  if ( pStudioHdr == nullptr )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: pStudioHdr)
       : pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( i >= v5 )
      break;
    if ( pStudioHdr->m_pVModel != nullptr )
    {
      v8 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i);
    }
    else
    {
      m_pStudioHdr = pStudioHdr->m_pStudioHdr;
      v7 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v7 + m_pStudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pszActivity) == 0 )
      return i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102360A0
// Name: private: void CBaseModelPanel::LookAtBounds(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CBaseModelPanel::LookAtBounds(
        CBaseModelPanel *this,
        const Vector *vecBoundsMin,
        const Vector *vecBoundsMax)
{
  float z; // eax
  float v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int i; // esi
  __m128 m_flFOV_low; // xmm0
  double v11; // xmm0_8
  float v12; // xmm6_4
  long double v13; // st7
  float v14; // xmm4_4
  int v15; // ecx
  Vector *v16; // eax
  float v17; // xmm7_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float x; // xmm5_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  int j; // eax
  float v34; // xmm5_4
  float y; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm4_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm4_4
  matrix3x4_t matRotation; // [esp+10h] [ebp-178h] BYREF
  Vector aBoundsPoints[8]; // [esp+40h] [ebp-148h] BYREF
  Vector aXFormPoints[8]; // [esp+A0h] [ebp-E8h] BYREF
  Vector vecXFormCenter; // [esp+100h] [ebp-88h] BYREF
  Vector vecModelPos; // [esp+10Ch] [ebp-7Ch] BYREF
  int h; // [esp+118h] [ebp-70h] BYREF
  Vector2D aScreenPoints[8]; // [esp+11Ch] [ebp-6Ch]
  int w; // [esp+15Ch] [ebp-2Ch] BYREF
  float v50; // [esp+160h] [ebp-28h]
  float flTanFOVy; // [esp+164h] [ebp-24h]
  float flW; // [esp+168h] [ebp-20h]
  float flH; // [esp+16Ch] [ebp-1Ch]
  Vector2D vecScreenMax; // [esp+170h] [ebp-18h] BYREF
  float v55; // [esp+178h] [ebp-10h]
  _BYTE v56[12]; // [esp+17Ch] [ebp-Ch] OVERLAPPED
  float flDista; // [esp+190h] [ebp+8h]
  float flDist; // [esp+190h] [ebp+8h]
  float flTanFOVx; // [esp+194h] [ebp+Ch]

  z = vecBoundsMin->z;
  vecScreenMax = *(Vector2D *)&vecBoundsMin->x;
  v55 = z;
  *(_QWORD *)v56 = *(_QWORD *)&vecBoundsMax->x;
  v5 = vecBoundsMax->z;
  v6 = (float)(vecScreenMax.y + *(float *)&v56[4]) * 0.5;
  *(float *)&v56[4] = *(float *)&v56[4] - v6;
  v7 = (float)(z + v5) * 0.5;
  aBoundsPoints[0].y = *(float *)&v56[4];
  v8 = (float)(vecScreenMax.x + *(float *)v56) * 0.5;
  aBoundsPoints[0].z = v5 - v7;
  aBoundsPoints[1].y = *(float *)&v56[4];
  aBoundsPoints[1].x = vecScreenMax.x - v8;
  aBoundsPoints[3].x = vecScreenMax.x - v8;
  aBoundsPoints[5].x = vecScreenMax.x - v8;
  aBoundsPoints[7].x = vecScreenMax.x - v8;
  aBoundsPoints[1].z = v5 - v7;
  aBoundsPoints[2].z = v5 - v7;
  aBoundsPoints[3].z = v5 - v7;
  aBoundsPoints[0].x = *(float *)v56 - v8;
  aBoundsPoints[2].x = *(float *)v56 - v8;
  aBoundsPoints[2].y = vecScreenMax.y - v6;
  aBoundsPoints[3].y = vecScreenMax.y - v6;
  aBoundsPoints[4].x = *(float *)v56 - v8;
  aBoundsPoints[4].y = *(float *)&v56[4];
  aBoundsPoints[4].z = z - v7;
  aBoundsPoints[5].y = *(float *)&v56[4];
  aBoundsPoints[5].z = z - v7;
  aBoundsPoints[6].x = *(float *)v56 - v8;
  aBoundsPoints[6].y = vecScreenMax.y - v6;
  aBoundsPoints[6].z = z - v7;
  aBoundsPoints[7].y = vecScreenMax.y - v6;
  aBoundsPoints[7].z = z - v7;
  *(float *)v56 = -v8;
  *(float *)&v56[4] = -v6;
  *(float *)&v56[8] = -v7;
  AngleMatrix(angles: &this->m_BMPResData.m_angModelPoseRot, matrix: &matRotation);
  for ( i = 0; i < 8; ++i )
    VectorTransform(in1: &aBoundsPoints[i].x, in2: &matRotation, out: &aXFormPoints[i].x);
  LODWORD(vecScreenMax.x) = *(_DWORD *)v56 ^ 0x80000000;
  LODWORD(vecScreenMax.y) = *(_DWORD *)&v56[4] ^ 0x80000000;
  v55 = -*(float *)&v56[8];
  VectorTransform(in1: &vecScreenMax.x, in2: &matRotation, out: &vecXFormCenter.x);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  flW = (float)w;
  flH = (float)h;
  m_flFOV_low = (__m128)LODWORD(this->m_BMPResData.m_flFOV);
  flDista = m_flFOV_low.m128_f32[0] * 0.5;
  m_flFOV_low.m128_f32[0] = (float)(m_flFOV_low.m128_f32[0] * 0.5) * 0.017453292;
  __libm_sse2_tan(X: (__m128i)_mm_cvtps_pd(m_flFOV_low));
  *(float *)&v11 = v11;
  flTanFOVx = *(float *)&v11;
  v50 = 1.0 / flH;
  v12 = 0.0;
  v13 = tan(CalcFovY(flFovX: flDista, flAspect: (float)(1.0 / flH) * flW) * 0.017453292);
  v14 = 1.0 / *(float *)&v11;
  flDist = 0.0;
  v15 = 0;
  v16 = aXFormPoints;
  flTanFOVy = v13;
  v55 = 1.0 / v13;
  v17 = v55;
  do
  {
    v18 = fabs(v16->y * v14) - v16->x;
    v19 = fabs(v17 * v16->z) - v16->x;
    aScreenPoints[v15].x = v18;
    aScreenPoints[v15].y = v19;
    if ( v19 <= v18 )
      v19 = v18;
    if ( v12 <= v19 )
    {
      flDist = v19;
      v12 = v19;
    }
    x = v16[1].x;
    v21 = fabs(v16[1].y * v14) - x;
    v22 = fabs(v16[1].z * v17) - x;
    aScreenPoints[v15 + 1].x = v21;
    aScreenPoints[v15 + 1].y = v22;
    if ( v22 > v21 )
      v21 = v22;
    if ( v12 <= v21 )
    {
      flDist = v21;
      v12 = v21;
    }
    v23 = v16[2].x;
    v24 = fabs(v16[2].y * v14) - v23;
    v25 = fabs(v16[2].z * v17) - v23;
    aScreenPoints[v15 + 2].x = v24;
    aScreenPoints[v15 + 2].y = v25;
    if ( v25 > v24 )
      v24 = v25;
    if ( v12 <= v24 )
    {
      flDist = v24;
      v12 = v24;
    }
    v26 = v16[3].x;
    v27 = fabs(v16[3].y * v14) - v26;
    v28 = fabs(v16[3].z * v17) - v26;
    aScreenPoints[v15 + 3].x = v27;
    aScreenPoints[v15 + 3].y = v28;
    if ( v28 > v27 )
      v27 = v28;
    if ( v12 <= v27 )
    {
      flDist = v27;
      v12 = v27;
    }
    v15 += 4;
    v16 += 4;
  }
  while ( v15 < 8 );
  aScreenPoints[0].y = (float)((float)((float)(aXFormPoints[0].z / (float)((float)(aXFormPoints[0].x + v12) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  aScreenPoints[0].x = (float)((float)((float)(aXFormPoints[0].y / (float)((float)(aXFormPoints[0].x + v12) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  aScreenPoints[1].y = (float)((float)((float)(aXFormPoints[1].z
                                             / (float)((float)(aXFormPoints[1].x + flDist) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  aScreenPoints[1].x = (float)((float)((float)(aXFormPoints[1].y
                                             / (float)((float)(aXFormPoints[1].x + flDist) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  aScreenPoints[2].y = (float)((float)((float)(aXFormPoints[2].z
                                             / (float)((float)(aXFormPoints[2].x + flDist) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  aScreenPoints[2].x = (float)((float)((float)(aXFormPoints[2].y
                                             / (float)((float)(aXFormPoints[2].x + flDist) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  aScreenPoints[3].y = (float)((float)((float)(aXFormPoints[3].z
                                             / (float)((float)(aXFormPoints[3].x + flDist) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  aScreenPoints[3].x = (float)((float)((float)(aXFormPoints[3].y
                                             / (float)((float)(aXFormPoints[3].x + flDist) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  aScreenPoints[4].y = (float)((float)((float)(aXFormPoints[4].z
                                             / (float)((float)(aXFormPoints[4].x + flDist) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  aScreenPoints[4].x = (float)((float)((float)(aXFormPoints[4].y
                                             / (float)((float)(aXFormPoints[4].x + flDist) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  aScreenPoints[5].x = (float)((float)((float)(aXFormPoints[5].y
                                             / (float)((float)(aXFormPoints[5].x + flDist) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  aScreenPoints[5].y = (float)((float)((float)(aXFormPoints[5].z
                                             / (float)((float)(aXFormPoints[5].x + flDist) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  aScreenPoints[6].y = (float)((float)((float)(aXFormPoints[6].z
                                             / (float)((float)(aXFormPoints[6].x + flDist) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  aScreenPoints[6].x = (float)((float)((float)(aXFormPoints[6].y
                                             / (float)((float)(aXFormPoints[6].x + flDist) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  v29 = -99999.0;
  v30 = 99999.0;
  aScreenPoints[7].x = (float)((float)((float)(aXFormPoints[7].y
                                             / (float)((float)(aXFormPoints[7].x + flDist) * flTanFOVx))
                                     + 1.0)
                             * 0.5)
                     * flW;
  aScreenPoints[7].y = (float)((float)((float)(aXFormPoints[7].z
                                             / (float)((float)(aXFormPoints[7].x + flDist) * flTanFOVy))
                                     + 1.0)
                             * 0.5)
                     * flH;
  v31 = 99999.0;
  v32 = -99999.0;
  *(_DWORD *)&v56[4] = 1203982208;
  *(_DWORD *)&v56[8] = 1203982208;
  vecScreenMax.y = -99999.0;
  v55 = -99999.0;
  for ( j = 0; j < 8; j += 4 )
  {
    v34 = aScreenPoints[j].x;
    if ( v34 <= v31 )
      v31 = aScreenPoints[j].x;
    y = aScreenPoints[j].y;
    if ( y <= v30 )
      v30 = aScreenPoints[j].y;
    if ( v32 <= v34 )
      v32 = aScreenPoints[j].x;
    if ( v29 <= y )
      v29 = aScreenPoints[j].y;
    v36 = aScreenPoints[j + 1].x;
    if ( v36 <= v31 )
      v31 = aScreenPoints[j + 1].x;
    v37 = aScreenPoints[j + 1].y;
    if ( v37 <= v30 )
      v30 = aScreenPoints[j + 1].y;
    if ( v32 <= v36 )
      v32 = aScreenPoints[j + 1].x;
    if ( v29 <= v37 )
      v29 = aScreenPoints[j + 1].y;
    v38 = aScreenPoints[j + 2].x;
    if ( v38 <= v31 )
      v31 = aScreenPoints[j + 2].x;
    v39 = aScreenPoints[j + 2].y;
    if ( v39 <= v30 )
      v30 = aScreenPoints[j + 2].y;
    if ( v32 <= v38 )
      v32 = aScreenPoints[j + 2].x;
    if ( v29 <= v39 )
      v29 = aScreenPoints[j + 2].y;
    v40 = aScreenPoints[j + 3].x;
    if ( v40 <= v31 )
      v31 = aScreenPoints[j + 3].x;
    v41 = aScreenPoints[j + 3].y;
    if ( v41 <= v30 )
      v30 = aScreenPoints[j + 3].y;
    if ( v32 <= v40 )
      v32 = aScreenPoints[j + 3].x;
    if ( v29 <= v41 )
      v29 = aScreenPoints[j + 3].y;
  }
  v55 = v29;
  *(float *)&v56[8] = v30;
  LODWORD(vecModelPos.y) = LODWORD(vecXFormCenter.y) ^ _mask__NegFloat_;
  vecScreenMax.y = v32;
  *(float *)&v56[4] = v31;
  vecModelPos.x = flDist - vecXFormCenter.x;
  LODWORD(vecModelPos.z) = LODWORD(vecXFormCenter.z) ^ _mask__NegFloat_;
  CMDLPanel::SetModelAnglesAndPosition(this, angRot: &this->m_BMPResData.m_angModelPoseRot, vecPos: &vecModelPos);
  *(float *)&v56[8] = (float)(v55 + *(float *)&v56[8]) * 0.5;
  v55 = 1.0 / flW;
  *(float *)&v56[4] = (float)((float)((float)((float)((float)(flW * 0.5) * (float)(1.0 / flW)) * 2.0) - 0.5)
                            * (float)(flDist * flTanFOVx))
                    - (float)((float)((float)((float)((float)((float)(vecScreenMax.y + *(float *)&v56[4]) * 0.5)
                                                    * (float)(1.0 / flW))
                                            * 2.0)
                                    - 0.5)
                            * (float)(flDist * flTanFOVx));
  *(float *)&v56[8] = (float)((float)((float)((float)(v50 * (float)(flH * 0.5)) * 2.0) - 0.5)
                            * (float)(flDist * flTanFOVy))
                    - (float)((float)((float)((float)(v50 * *(float *)&v56[8]) * 2.0) - 0.5)
                            * (float)(flDist * flTanFOVy));
  CPotteryWheelPanel::ResetCameraPivot(this);
  vecScreenMax.x = 0.0;
  LODWORD(vecScreenMax.y) = *(_DWORD *)&v56[4] ^ _mask__NegFloat_;
  LODWORD(v55) = *(_DWORD *)&v56[8] ^ _mask__NegFloat_;
  CPotteryWheelPanel::SetCameraOffset(this, vecOffset: (const Vector *)&vecScreenMax);
  CPotteryWheelPanel::UpdateCameraTransform(this);
}

//------------------------------------------------------------------------------
// Address: 0x102369C0
// Name: public: virtual void CBaseModelPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::PerformLayout(CBaseModelPanel *this)
{
  Vector vecBoundsMin; // [esp+4h] [ebp-18h] BYREF
  Vector vecBoundsMax; // [esp+10h] [ebp-Ch] BYREF

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_bForcePos )
  {
    CPotteryWheelPanel::ResetCameraPivot(this);
    memset((void *)&vecBoundsMax, 0, sizeof(vecBoundsMax));
    CPotteryWheelPanel::SetCameraOffset(this, vecOffset: &vecBoundsMax);
    CPotteryWheelPanel::SetCameraPositionAndAngles(this, vecPos: &vec3_origin, angDir: &vec3_angle);
    CMDLPanel::SetModelAnglesAndPosition(this, angRot: &this->m_angPlayer, vecPos: &this->m_vecPlayerPos);
  }
  if ( this->m_bStartFramed && CMDLPanel::GetBoundingBox(this, &vecBoundsMin, &vecBoundsMax) )
    CBaseModelPanel::LookAtBounds(this, &vecBoundsMin, &vecBoundsMax);
}

//------------------------------------------------------------------------------
// Address: 0x10236C90
// Name: public: BMPResData_t::~BMPResData_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BMPResData_t::~BMPResData_t(BMPResData_t *this)
{
  const char *m_pszModelName; // eax
  const char *m_pszModelName_HWM; // eax
  const char *m_pszVCD; // eax

  m_pszModelName = this->m_pszModelName;
  if ( m_pszModelName != nullptr && *m_pszModelName != 0 )
  {
    C_BaseEntity::operator delete(pMem: (void *)this->m_pszModelName);
    this->m_pszModelName = nullptr;
  }
  m_pszModelName_HWM = this->m_pszModelName_HWM;
  if ( m_pszModelName_HWM != nullptr && *m_pszModelName_HWM != 0 )
  {
    C_BaseEntity::operator delete(pMem: (void *)this->m_pszModelName_HWM);
    this->m_pszModelName_HWM = nullptr;
  }
  m_pszVCD = this->m_pszVCD;
  if ( m_pszVCD != nullptr && *m_pszVCD != 0 )
  {
    C_BaseEntity::operator delete(pMem: (void *)this->m_pszVCD);
    this->m_pszVCD = nullptr;
  }
  CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>::RemoveAll(this: &this->m_aAnimations);
  if ( this->m_aAnimations.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aAnimations.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aAnimations.m_Memory.m_pMemory);
      this->m_aAnimations.m_Memory.m_pMemory = nullptr;
    }
    this->m_aAnimations.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aAnimations.m_pElements = this->m_aAnimations.m_Memory.m_pMemory;
  CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int>>::RemoveAll(this: &this->m_aAttachModels);
  if ( this->m_aAttachModels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aAttachModels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aAttachModels.m_Memory.m_pMemory);
      this->m_aAttachModels.m_Memory.m_pMemory = nullptr;
    }
    this->m_aAttachModels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aAttachModels.m_pElements = this->m_aAttachModels.m_Memory.m_pMemory;
  CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int>>::~CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int>>(this: &this->m_aAttachModels);
  CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>::~CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>(this: &this->m_aAnimations);
}

//------------------------------------------------------------------------------
// Address: 0x10236D50
// Name: public: static void CBaseModelPanel::PanelAnimationVar_m_bStartFramed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CBaseModelPanel::PanelAnimationVar_m_bStartFramed::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CBaseModelPanel::PanelAnimationVar_m_bStartFramed::InitVar'::`2'::bAdded )
  {
    `CBaseModelPanel::PanelAnimationVar_m_bStartFramed::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CBaseModelPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "start_framed";
    src.m_pszVariable = "m_bStartFramed";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CBaseModelPanel::GetVar_m_bStartFramed;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236DB0
// Name: public: static void CBaseModelPanel::PanelAnimationVar_m_bDisableManipulation::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CBaseModelPanel::PanelAnimationVar_m_bDisableManipulation::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CBaseModelPanel::PanelAnimationVar_m_bDisableManipulation::InitVar'::`2'::bAdded )
  {
    `CBaseModelPanel::PanelAnimationVar_m_bDisableManipulation::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CBaseModelPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "disable_manipulation";
    src.m_pszVariable = "m_bDisableManipulation";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CBaseModelPanel::GetVar_m_bDisableManipulation;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236E10
// Name: public: CBaseModelPanel::CBaseModelPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseModelPanel *__thiscall CBaseModelPanel::CBaseModelPanel(
        CBaseModelPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CMDLPanel::CMDLPanel(this, pParent, pName);
  this->__vftable = (CBaseModelPanel_vtbl *)&CBaseModelPanel::`vftable';
  if ( `CBaseModelPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseModelPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseModelPanel");
    v4->pfnClassName = CBaseModelPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  }
  if ( `CBaseModelPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseModelPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseModelPanel");
    v5->pfnClassName = CBaseModelPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CMDLPanel");
  }
  if ( `CBaseModelPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseModelPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseModelPanel");
    v6->pfnClassName = CBaseModelPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  }
  this->m_BMPResData.m_aAnimations.m_Memory.m_pMemory = nullptr;
  this->m_BMPResData.m_aAnimations.m_Memory.m_nAllocationCount = 0;
  this->m_BMPResData.m_aAnimations.m_Memory.m_nGrowSize = 0;
  this->m_BMPResData.m_aAnimations.m_Size = 0;
  this->m_BMPResData.m_aAnimations.m_pElements = nullptr;
  this->m_BMPResData.m_aAttachModels.m_Memory.m_pMemory = nullptr;
  this->m_BMPResData.m_aAttachModels.m_Memory.m_nAllocationCount = 0;
  this->m_BMPResData.m_aAttachModels.m_Memory.m_nGrowSize = 0;
  this->m_BMPResData.m_aAttachModels.m_Size = 0;
  this->m_BMPResData.m_aAttachModels.m_pElements = nullptr;
  this->m_BMPResData.m_flFOV = 0.0;
  this->m_BMPResData.m_pszModelName = nullptr;
  this->m_BMPResData.m_pszModelName_HWM = nullptr;
  this->m_BMPResData.m_pszVCD = nullptr;
  this->m_BMPResData.m_angModelPoseRot.x = 0.0;
  this->m_BMPResData.m_angModelPoseRot.y = 0.0;
  this->m_BMPResData.m_angModelPoseRot.z = 0.0;
  this->m_BMPResData.m_vecOriginOffset.x = 0.0;
  this->m_BMPResData.m_vecOriginOffset.y = 0.0;
  this->m_BMPResData.m_vecOriginOffset.z = 0.0;
  this->m_BMPResData.m_vecFramedOriginOffset.x = 0.0;
  this->m_BMPResData.m_vecFramedOriginOffset.y = 0.0;
  this->m_BMPResData.m_vecFramedOriginOffset.z = 0.0;
  this->m_BMPResData.m_vecViewportOffset.x = 0.0;
  this->m_BMPResData.m_vecViewportOffset.y = 0.0;
  this->m_BMPResData.m_nSkin = 0;
  this->m_BMPResData.m_bUseSpotlight = false;
  CBaseModelPanel::PanelAnimationVar_m_bStartFramed::InitVar();
  CBaseModelPanel::PanelAnimationVar_m_bDisableManipulation::InitVar();
  *(_WORD *)&this->m_bForcePos = 0;
  this->m_bAllowRotation = false;
  vgui::Panel::MakeReadyForUse(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10236FB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseModelPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseModelPanel::GetMessageMap(CBaseModelPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseModelPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseModelPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseModelPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseModelPanel");
  `CBaseModelPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10236FE0
// Name: public: virtual struct PanelAnimationMap __near * CBaseModelPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseModelPanel::GetAnimMap(CBaseModelPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseModelPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10237000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseModelPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseModelPanel::GetKBMap(CBaseModelPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseModelPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseModelPanel::GetKBMap'::`2'::s_pMap;
  `CBaseModelPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseModelPanel");
  `CBaseModelPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10237030
// Name: private: void CBaseModelPanel::ParseModelAnimInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::ParseModelAnimInfo(CBaseModelPanel *this, KeyValues *inResourceData)
{
  CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int> > *p_m_aAnimations; // edi
  int v4; // eax
  int v5; // esi
  KeyValues *i; // ebx
  const char *Name; // eax
  KeyValues *inResourceDataa; // [esp+Ch] [ebp+8h]
  KeyValues *inResourceDatab; // [esp+Ch] [ebp+8h]
  KeyValues *inResourceDatac; // [esp+Ch] [ebp+8h]
  KeyValues *inResourceDatad; // [esp+Ch] [ebp+8h]
  KeyValues *inResourceDatae; // [esp+Ch] [ebp+8h]

  if ( inResourceData != nullptr )
  {
    p_m_aAnimations = &this->m_BMPResData.m_aAnimations;
    v4 = CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>::InsertBefore(
           this: &this->m_BMPResData.m_aAnimations,
           elem: this->m_BMPResData.m_aAnimations.m_Size);
    if ( v4 != -1 )
    {
      v5 = v4;
      inResourceDataa = (KeyValues *)&p_m_aAnimations->m_Memory.m_pMemory[v4];
      *(_DWORD *)inResourceDataa = ReadAndAllocStringValue(pSub: inResourceData, pName: "name", pFilename: nullptr);
      inResourceDatab = (KeyValues *)&p_m_aAnimations->m_Memory.m_pMemory[v5];
      inResourceDatab->m_sValue = ReadAndAllocStringValue(pSub: inResourceData, pName: "sequence", pFilename: nullptr);
      inResourceDatac = (KeyValues *)&p_m_aAnimations->m_Memory.m_pMemory[v5];
      inResourceDatac->m_wsValue = (wchar_t *)ReadAndAllocStringValue(
                                                pSub: inResourceData,
                                                pName: "activity",
                                                pFilename: nullptr);
      inResourceDatad = (KeyValues *)&p_m_aAnimations->m_Memory.m_pMemory[v5];
      inResourceDatad->m_iDataType = KeyValues::GetInt(this: inResourceData, keyName: "default", defaultValue: 0) == 1;
      for ( i = KeyValues::GetFirstSubKey(this: inResourceData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "pose_parameters") == 0 )
        {
          inResourceDatae = (KeyValues *)&p_m_aAnimations->m_Memory.m_pMemory[v5];
          inResourceDatae->m_iValue = (int)KeyValues::MakeCopy(this: i);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237130
// Name: Create_CBaseModelPanel
// Source: json
//------------------------------------------------------------------------------
CBaseModelPanel *__cdecl Create_CBaseModelPanel()
{
  CBaseModelPanel *v0; // eax

  v0 = (CBaseModelPanel *)MemAlloc_Alloc(nSize: 0xC74u);
  if ( v0 != nullptr )
    return CBaseModelPanel::CBaseModelPanel(this: v0, pParent: nullptr, pName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10237190
// Name: public: void CBaseModelPanel::SetModelAnim(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::SetModelAnim(CBaseModelPanel *this, const char *pszName)
{
  IMDLCache *v2; // ebx
  const studiohdr_t *v4; // eax
  int SequenceFromActivity; // eax
  CStudioHdr studioHdr; // [esp+8h] [ebp-64h] BYREF

  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v4 = CMDL::GetStudioHdr(this: &this->m_RootMDL.m_MDL);
  if ( v4 != nullptr )
  {
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v4, mdlcache: g_pMDLCache);
    SequenceFromActivity = CBaseModelPanel::FindSequenceFromActivity(this, pStudioHdr: &studioHdr, pszActivity: pszName);
    if ( SequenceFromActivity != -1
      || (SequenceFromActivity = LookupSequence(pstudiohdr: &studioHdr, label: pszName)) != -1 )
    {
      CMDLPanel::SetSequence(this, nSequence: SequenceFromActivity);
    }
    CStudioHdr::Term(this: &studioHdr);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
    v2->EndLock(this: v2);
  }
  else
  {
    v2->EndLock(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10237240
// Name: public: virtual void CBaseModelPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseModelPanel::ApplySettings(CBaseModelPanel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  int CameraFOV; // eax
  float flFOV; // xmm0_4
  KeyValues *i; // edi
  const char *Name; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  KeyValues *FirstSubKey; // ebx
  const char *v12; // eax
  const char *v13; // eax
  int v14; // ecx
  int m_nAllocationCount; // eax
  BMPResAttachData_t *m_pMemory; // edx
  int v17; // eax
  BMPResAttachData_t *v18; // eax
  bool v19; // zf
  BMPResAttachData_t *v20; // eax
  BMPResAttachData_t *v21; // ebx
  int v22; // [esp+10h] [ebp-8h]
  float Float; // [esp+14h] [ebp-4h]
  float v24; // [esp+14h] [ebp-4h]
  float v25; // [esp+14h] [ebp-4h]
  int m_Size; // [esp+14h] [ebp-4h]
  BMPResAttachData_t *v27; // [esp+14h] [ebp-4h]
  float inResourceDatab; // [esp+20h] [ebp+8h]
  float inResourceDatac; // [esp+20h] [ebp+8h]
  float inResourceDatad; // [esp+20h] [ebp+8h]
  KeyValues *inResourceDataa; // [esp+20h] [ebp+8h]

  vgui::EditablePanel::ApplySettings(this, a2, inResourceData);
  CameraFOV = CPotteryWheelPanel::GetCameraFOV(this);
  flFOV = (float)KeyValues::GetInt(this: inResourceData, keyName: "fov", defaultValue: (int)(float)CameraFOV);
  this->m_BMPResData.m_flFOV = flFOV;
  CPotteryWheelPanel::SetCameraFOV(this, flFOV);
  this->m_bAllowRotation = KeyValues::GetInt(this: inResourceData, keyName: "allow_rot", defaultValue: 0) == 1;
  for ( i = KeyValues::GetFirstSubKey(this: inResourceData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: Name, s2: "model") == 0 )
    {
      this->m_bForcePos = KeyValues::GetInt(this: i, keyName: "force_pos", defaultValue: 0) == 1;
      this->m_BMPResData.m_pszModelName = ReadAndAllocStringValue(pSub: i, pName: "modelname", pFilename: nullptr);
      this->m_BMPResData.m_pszModelName_HWM = ReadAndAllocStringValue(
                                                pSub: i,
                                                pName: "modelname_hwm",
                                                pFilename: nullptr);
      this->m_BMPResData.m_pszVCD = ReadAndAllocStringValue(pSub: i, pName: "vcd", pFilename: nullptr);
      inResourceDatab = KeyValues::GetFloat(this: i, keyName: "angles_x", defaultValue: 0.0);
      Float = KeyValues::GetFloat(this: i, keyName: "angles_y", defaultValue: 0.0);
      v8 = KeyValues::GetFloat(this: i, keyName: "angles_z", defaultValue: 0.0);
      this->m_BMPResData.m_angModelPoseRot.x = inResourceDatab;
      this->m_BMPResData.m_angModelPoseRot.y = Float;
      this->m_BMPResData.m_angModelPoseRot.z = v8;
      inResourceDatac = KeyValues::GetFloat(this: i, keyName: "origin_x", defaultValue: 110.0);
      v24 = KeyValues::GetFloat(this: i, keyName: "origin_y", defaultValue: 5.0);
      v9 = KeyValues::GetFloat(this: i, keyName: "origin_z", defaultValue: 5.0);
      this->m_BMPResData.m_vecOriginOffset.x = inResourceDatac;
      this->m_BMPResData.m_vecOriginOffset.y = v24;
      this->m_BMPResData.m_vecOriginOffset.z = v9;
      inResourceDatad = KeyValues::GetFloat(this: i, keyName: "frame_origin_x", defaultValue: 110.0);
      v25 = KeyValues::GetFloat(this: i, keyName: "frame_origin_y", defaultValue: 5.0);
      v10 = KeyValues::GetFloat(this: i, keyName: "frame_origin_z", defaultValue: 5.0);
      this->m_BMPResData.m_vecFramedOriginOffset.x = inResourceDatad;
      this->m_BMPResData.m_vecFramedOriginOffset.y = v25;
      this->m_BMPResData.m_vecFramedOriginOffset.z = v10;
      this->m_BMPResData.m_vecViewportOffset.x = 0.0;
      this->m_BMPResData.m_vecViewportOffset.y = 0.0;
      this->m_BMPResData.m_nSkin = KeyValues::GetInt(this: i, keyName: "skin", defaultValue: -1);
      this->m_BMPResData.m_bUseSpotlight = KeyValues::GetInt(this: i, keyName: "spotlight", defaultValue: 0) == 1;
      this->m_angPlayer.x = this->m_BMPResData.m_angModelPoseRot.x;
      this->m_angPlayer.y = this->m_BMPResData.m_angModelPoseRot.y;
      this->m_angPlayer.z = this->m_BMPResData.m_angModelPoseRot.z;
      this->m_vecPlayerPos.x = this->m_BMPResData.m_vecOriginOffset.x;
      this->m_vecPlayerPos.y = this->m_BMPResData.m_vecOriginOffset.y;
      this->m_vecPlayerPos.z = this->m_BMPResData.m_vecOriginOffset.z;
      FirstSubKey = KeyValues::GetFirstSubKey(this: i);
      inResourceDataa = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          v12 = KeyValues::GetName(this: FirstSubKey);
          if ( _V_stricmp(s1: v12, s2: "animation") != 0 )
          {
            v13 = KeyValues::GetName(this: FirstSubKey);
            if ( _V_stricmp(s1: v13, s2: "attached_model") == 0 )
            {
              m_nAllocationCount = this->m_BMPResData.m_aAttachModels.m_Memory.m_nAllocationCount;
              m_Size = this->m_BMPResData.m_aAttachModels.m_Size;
              v14 = m_Size;
              if ( m_Size + 1 > m_nAllocationCount )
              {
                CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
                  this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_BMPResData.m_aAttachModels,
                  num: m_Size - m_nAllocationCount + 1);
                v14 = m_Size;
              }
              ++this->m_BMPResData.m_aAttachModels.m_Size;
              m_pMemory = this->m_BMPResData.m_aAttachModels.m_Memory.m_pMemory;
              v17 = this->m_BMPResData.m_aAttachModels.m_Size - v14 - 1;
              this->m_BMPResData.m_aAttachModels.m_pElements = m_pMemory;
              if ( v17 > 0 )
              {
                _V_memmove(
                  dest: (unsigned __int8 *)&m_pMemory[v14 + 1],
                  src: (unsigned __int8 *)&m_pMemory[v14],
                  count: 8 * v17);
                v14 = m_Size;
              }
              v18 = this->m_BMPResData.m_aAttachModels.m_Memory.m_pMemory;
              v19 = &v18[v14] == nullptr;
              v20 = &v18[v14];
              v22 = v14;
              if ( !v19 )
              {
                v20->m_pszModelName = nullptr;
                v20->m_nSkin = 0;
              }
              if ( v14 != -1 )
              {
                v27 = &this->m_BMPResData.m_aAttachModels.m_Memory.m_pMemory[v14];
                v27->m_pszModelName = ReadAndAllocStringValue(
                                        pSub: inResourceDataa,
                                        pName: "modelname",
                                        pFilename: nullptr);
                v21 = &this->m_BMPResData.m_aAttachModels.m_Memory.m_pMemory[v22];
                v21->m_nSkin = KeyValues::GetInt(this: inResourceDataa, keyName: "skin", defaultValue: -1);
              }
              FirstSubKey = inResourceDataa;
            }
          }
          else
          {
            CBaseModelPanel::ParseModelAnimInfo(this, inResourceData: FirstSubKey);
          }
          inResourceDataa = KeyValues::GetNextKey(this: FirstSubKey);
          if ( inResourceDataa == nullptr )
            break;
          FirstSubKey = inResourceDataa;
        }
      }
    }
  }
  this->SetMouseInputEnabled(this, a2: this->m_bAllowRotation);
}

//------------------------------------------------------------------------------
// Address: 0x10237660
// Name: public: void CBaseModelPanel::SetModelAnim(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::SetModelAnim(CBaseModelPanel *this, int iAnim)
{
  int m_Size; // edx
  BMPResAnimData_t *v3; // edx
  const char *m_pszActivity; // eax
  const char *m_pszSequence; // edx

  m_Size = this->m_BMPResData.m_aAnimations.m_Size;
  if ( m_Size != 0 && iAnim >= 0 && iAnim < m_Size )
  {
    v3 = &this->m_BMPResData.m_aAnimations.m_Memory.m_pMemory[iAnim];
    m_pszActivity = v3->m_pszActivity;
    if ( m_pszActivity != nullptr && *m_pszActivity != 0 )
    {
      CBaseModelPanel::SetModelAnim(this, pszName: v3->m_pszActivity);
    }
    else
    {
      m_pszSequence = v3->m_pszSequence;
      if ( m_pszSequence != nullptr && *m_pszSequence != 0 )
        CBaseModelPanel::SetModelAnim(this, pszName: m_pszSequence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102376B0
// Name: public: virtual void CBaseModelPanel::SetMDL(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseModelPanel::SetMDL(CBaseModelPanel *this, unsigned __int16 handle)
{
  int m_Size; // edx
  int v4; // eax
  bool *p_m_bDefault; // ecx

  CMDLPanel::SetMDL(this, handle, pProxyData: nullptr);
  m_Size = this->m_BMPResData.m_aAnimations.m_Size;
  if ( m_Size != 0 )
  {
    v4 = 0;
    if ( m_Size > 0 )
    {
      p_m_bDefault = &this->m_BMPResData.m_aAnimations.m_Memory.m_pMemory->m_bDefault;
      while ( !*p_m_bDefault )
      {
        ++v4;
        p_m_bDefault += 20;
        if ( v4 >= m_Size )
          goto LABEL_9;
      }
      if ( v4 != -1 )
        CBaseModelPanel::SetModelAnim(this, iAnim: v4);
    }
  }
LABEL_9:
  this->InvalidateLayout(this, a2: false, a3: false);
}
