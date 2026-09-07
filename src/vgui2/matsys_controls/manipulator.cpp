// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/manipulator.cpp
// Functions: 10
// ============================================================

#include "vgui2\matsys_controls\manipulator.h"

//------------------------------------------------------------------------------
// Address: 0x004CF7F0
// Name: public: virtual void CPotteryWheelManip::OnBeginManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnBeginManipulation(CPotteryWheelManip *this)
{
  long double v2; // st7

  this->m_prevZoom = this->m_zoom;
  this->m_prevAltitude = this->m_altitude;
  this->m_prevAzimuth = this->m_azimuth;
  v2 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_flLastTickTime = v2;
  this->m_flLastMouseTime = v2;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x004CF830
// Name: public: virtual void CPotteryWheelManip::OnAcceptManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnAcceptManipulation(CPotteryWheelManip *this)
{
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x004CF840
// Name: public: virtual void CPotteryWheelManip::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMousePressed(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_lastx = x;
  this->m_lasty = y;
  this->m_bSpin = false;
  this->m_flSpin = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004CF880
// Name: public: virtual void CPotteryWheelManip::OnMouseReleased(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseReleased(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  if ( code == MOUSE_MIDDLE )
  {
    this->m_bSpin = COERCE_FLOAT(LODWORD(this->m_flSpin) & _mask__AbsFloat_) > 1.0;
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF900
// Name: public: CTransformManipulator::CTransformManipulator(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTransformManipulator *__thiscall CTransformManipulator::CTransformManipulator(
        CTransformManipulator *this,
        matrix3x4_t *pTransform)
{
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CTransformManipulator_vtbl *)&CTransformManipulator::`vftable';
  this->m_pTransform = pTransform;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CF920
// Name: public: CPotteryWheelManip::CPotteryWheelManip(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelManip *__thiscall CPotteryWheelManip::CPotteryWheelManip(
        CPotteryWheelManip *this,
        matrix3x4_t *pTransform)
{
  this->m_pTransform = pTransform;
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CPotteryWheelManip_vtbl *)&CPotteryWheelManip::`vftable';
  this->m_lastx = -1;
  this->m_lasty = -1;
  this->m_zoom = 100.0;
  this->m_altitude = 0.0;
  this->m_azimuth = 0.0;
  this->m_prevZoom = 100.0;
  this->m_prevAltitude = 0.0;
  this->m_prevAzimuth = 0.0;
  this->m_flLastMouseTime = 0.0;
  this->m_flLastTickTime = 0.0;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CF990
// Name: public: virtual void CPotteryWheelManip::OnCancelManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnCancelManipulation(CPotteryWheelManip *this)
{
  float m_prevAzimuth; // xmm1_4
  matrix3x4_t *m_pTransform; // esi
  __m128 m_prevAltitude_low; // xmm0
  double v4; // xmm0_8
  double v5; // xmm0_8
  long double v6; // [esp-4h] [ebp-2Ch] BYREF
  float angles_4; // [esp+4h] [ebp-24h]
  int angles_8; // [esp+8h] [ebp-20h]
  Vector position; // [esp+Ch] [ebp-1Ch] BYREF
  float v10; // [esp+18h] [ebp-10h]
  float v11; // [esp+1Ch] [ebp-Ch]
  float m_prevZoom; // [esp+20h] [ebp-8h]
  float v13; // [esp+24h] [ebp-4h]

  m_prevAzimuth = this->m_prevAzimuth;
  m_pTransform = this->m_pTransform;
  m_prevZoom = this->m_prevZoom;
  this->m_zoom = m_prevZoom;
  m_prevAltitude_low = (__m128)LODWORD(this->m_prevAltitude);
  v13 = m_prevAzimuth;
  this->m_azimuth = m_prevAzimuth;
  v10 = m_prevAltitude_low.m128_f32[0];
  LODWORD(this->m_altitude) = m_prevAltitude_low.m128_i32[0];
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  if ( m_pTransform != nullptr )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(m_prevAltitude_low));
    *(float *)&v4 = v4;
    v11 = *(float *)&v4 * m_prevZoom;
    __libm_sse2_sin(x: v6);
    position.x = v13 * (float)(*(float *)&v4 * m_prevZoom);
    __libm_sse2_sin(x: v6);
    position.y = v10 * m_prevZoom;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v13)));
    *(float *)&v5 = v5;
    position.z = *(float *)&v5 * v11;
    HIDWORD(v6) = LODWORD(v10) ^ _mask__NegFloat_;
    angles_4 = v13;
    angles_8 = 0;
    AngleMatrix(angles: (const RadianEuler *)((char *)&v6 + 4), &position, matrix: m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFA80
// Name: public: virtual void CPotteryWheelManip::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPotteryWheelManip::OnTick(CPotteryWheelManip *this@<ecx>, int a2@<edi>)
{
  long double v3; // st7
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  double v6; // xmm0_8
  double v7; // xmm0_8
  long double v8; // [esp-4h] [ebp-30h]
  long double v9; // [esp-4h] [ebp-30h]
  RadianEuler angles; // [esp+4h] [ebp-28h] BYREF
  Vector position; // [esp+10h] [ebp-1Ch] BYREF
  float m_altitude; // [esp+1Ch] [ebp-10h]
  float v13; // [esp+20h] [ebp-Ch]
  float v14; // [esp+24h] [ebp-8h]
  float v15; // [esp+28h] [ebp-4h]

  v3 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  m_altitude = v3 - this->m_flLastTickTime;
  this->m_flLastTickTime = v3;
  if ( this->m_bSpin )
  {
    LODWORD(v8) = a2;
    m_pTransform = this->m_pTransform;
    v15 = (float)(this->m_flSpin * m_altitude) + this->m_azimuth;
    this->m_azimuth = v15;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      m_altitude = this->m_altitude;
      v14 = m_zoom;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_altitude)));
      *(float *)&v6 = v6;
      v13 = *(float *)&v6 * m_zoom;
      __libm_sse2_sin(x: v8);
      position.x = v15 * (float)(*(float *)&v6 * m_zoom);
      __libm_sse2_sin(x: v9);
      position.y = m_altitude * m_zoom;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v15)));
      *(float *)&v7 = v7;
      position.z = *(float *)&v7 * v13;
      LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
      angles.y = v15;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFB90
// Name: public: virtual void CPotteryWheelManip::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelManip::OnCursorMoved(CPotteryWheelManip *this@<ecx>, int a2@<edi>, int x, int y)
{
  long double v5; // st7
  float v6; // xmm0_4
  int v7; // ecx
  int v8; // edx
  float m_altitude; // xmm0_4
  float v10; // xmm0_4
  double v11; // xmm0_8
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  double v14; // xmm0_8
  double v15; // xmm0_8
  long double v16; // [esp-4h] [ebp-28h]
  long double v17; // [esp-4h] [ebp-28h]
  RadianEuler angles; // [esp+4h] [ebp-20h] BYREF
  Vector position; // [esp+10h] [ebp-14h] BYREF
  int dy; // [esp+1Ch] [ebp-8h]
  float v21; // [esp+20h] [ebp-4h]
  float ya; // [esp+30h] [ebp+Ch]

  v5 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  v21 = v5 - this->m_flLastMouseTime;
  this->m_flLastMouseTime = v5;
  if ( this->m_bSpin )
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    LODWORD(v16) = a2;
    v6 = 0.0;
    if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_MIDDLE) )
    {
      v7 = x - this->m_lastx;
      dy = y - this->m_lasty;
      if ( (int)abs32(v7) >= (int)(2 * abs32(dy)) )
      {
        if ( v21 != 0.0 )
          v6 = (float)((float)v7 * 0.0020000001) / v21;
        this->m_flSpin = v6;
        this->m_azimuth = (float)((float)v7 * 0.0020000001) + this->m_azimuth;
      }
      else
      {
        __libm_sse2_pow();
        this->m_zoom = (float)1.009999990463257 * this->m_zoom;
      }
    }
    else
    {
      v8 = y - this->m_lasty;
      m_altitude = this->m_altitude;
      this->m_azimuth = (float)((float)(x - this->m_lastx) * 0.0020000001) + this->m_azimuth;
      v10 = m_altitude - (float)((float)v8 * 0.0020000001);
      this->m_altitude = v10;
      if ( v10 > 1.570796326794897 || v10 >= -1.570796326794897 )
      {
        if ( v10 <= 1.570796326794897 )
          v11 = v10;
        else
          v11 = 1.570796326794897;
      }
      else
      {
        v11 = -1.570796326794897;
      }
      this->m_altitude = v11;
    }
    m_pTransform = this->m_pTransform;
    this->m_lastx = x;
    this->m_lasty = y;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      v21 = this->m_altitude;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v21)));
      *(float *)&v14 = v14;
      ya = *(float *)&v14 * m_zoom;
      dy = SLODWORD(this->m_azimuth);
      __libm_sse2_sin(x: v16);
      position.x = *(float *)&dy * (float)(*(float *)&v14 * m_zoom);
      __libm_sse2_sin(x: v17);
      position.y = v21 * m_zoom;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)dy));
      *(float *)&v15 = v15;
      position.z = *(float *)&v15 * ya;
      LODWORD(angles.x) = LODWORD(v21) ^ _mask__NegFloat_;
      LODWORD(angles.y) = dy;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFDE0
// Name: public: virtual void CPotteryWheelManip::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseWheeled(CPotteryWheelManip *this, int delta)
{
  matrix3x4_t *m_pTransform; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  long double v6; // [esp+0h] [ebp-2Ch]
  long double v7; // [esp+0h] [ebp-2Ch]
  RadianEuler angles; // [esp+8h] [ebp-24h] BYREF
  Vector position; // [esp+14h] [ebp-18h] BYREF
  float m_azimuth; // [esp+20h] [ebp-Ch]
  float m_altitude; // [esp+24h] [ebp-8h]
  float v12; // [esp+28h] [ebp-4h]
  float deltaa; // [esp+34h] [ebp+8h]

  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  __libm_sse2_pow();
  m_pTransform = this->m_pTransform;
  deltaa = (float)1.009999990463257 * this->m_zoom;
  this->m_zoom = deltaa;
  if ( m_pTransform != nullptr )
  {
    m_altitude = this->m_altitude;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_altitude)));
    *(float *)&v4 = v4;
    v12 = *(float *)&v4 * deltaa;
    m_azimuth = this->m_azimuth;
    __libm_sse2_sin(x: v6);
    position.x = m_azimuth * (float)(*(float *)&v4 * deltaa);
    __libm_sse2_sin(x: v7);
    position.y = m_altitude * deltaa;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_azimuth)));
    *(float *)&v5 = v5;
    position.z = *(float *)&v5 * v12;
    LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
    angles.y = m_azimuth;
    angles.z = 0.0;
    AngleMatrix(&angles, &position, matrix: m_pTransform);
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102167E0
// Name: public: virtual void CPotteryWheelManip::OnBeginManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnBeginManipulation(CPotteryWheelManip *this)
{
  long double v2; // st7

  this->m_prevZoom = this->m_zoom;
  this->m_prevAltitude = this->m_altitude;
  this->m_prevAzimuth = this->m_azimuth;
  v2 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_flLastTickTime = v2;
  this->m_flLastMouseTime = v2;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x10216820
// Name: public: virtual void CPotteryWheelManip::OnAcceptManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnAcceptManipulation(CPotteryWheelManip *this)
{
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x10216830
// Name: public: virtual void CPotteryWheelManip::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMousePressed(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_lastx = x;
  this->m_lasty = y;
  this->m_bSpin = false;
  this->m_flSpin = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10216870
// Name: public: virtual void CPotteryWheelManip::OnMouseReleased(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseReleased(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  if ( code == MOUSE_MIDDLE )
  {
    this->m_bSpin = COERCE_FLOAT(LODWORD(this->m_flSpin) & _mask__AbsFloat_) > 1.0;
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102168F0
// Name: public: CTransformManipulator::CTransformManipulator(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTransformManipulator *__thiscall CTransformManipulator::CTransformManipulator(
        CTransformManipulator *this,
        matrix3x4_t *pTransform)
{
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CTransformManipulator_vtbl *)&CTransformManipulator::`vftable';
  this->m_pTransform = pTransform;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10216910
// Name: public: CPotteryWheelManip::CPotteryWheelManip(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelManip *__thiscall CPotteryWheelManip::CPotteryWheelManip(
        CPotteryWheelManip *this,
        matrix3x4_t *pTransform)
{
  this->m_pTransform = pTransform;
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CPotteryWheelManip_vtbl *)&CPotteryWheelManip::`vftable';
  this->m_lastx = -1;
  this->m_lasty = -1;
  this->m_zoom = 100.0;
  this->m_altitude = 0.0;
  this->m_azimuth = 0.0;
  this->m_prevZoom = 100.0;
  this->m_prevAltitude = 0.0;
  this->m_prevAzimuth = 0.0;
  this->m_flLastMouseTime = 0.0;
  this->m_flLastTickTime = 0.0;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10216980
// Name: public: virtual void CPotteryWheelManip::OnCancelManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnCancelManipulation(CPotteryWheelManip *this)
{
  float m_prevAzimuth; // xmm1_4
  matrix3x4_t *m_pTransform; // esi
  float m_prevAltitude; // xmm0_4
  long double v4; // [esp-4h] [ebp-2Ch] BYREF
  float angles_4; // [esp+4h] [ebp-24h]
  int angles_8; // [esp+8h] [ebp-20h]
  Vector position; // [esp+Ch] [ebp-1Ch] BYREF
  float v8; // [esp+18h] [ebp-10h]
  float v9; // [esp+1Ch] [ebp-Ch]
  float m_prevZoom; // [esp+20h] [ebp-8h]
  float v11; // [esp+24h] [ebp-4h]

  m_prevAzimuth = this->m_prevAzimuth;
  m_pTransform = this->m_pTransform;
  m_prevZoom = this->m_prevZoom;
  this->m_zoom = m_prevZoom;
  m_prevAltitude = this->m_prevAltitude;
  v11 = m_prevAzimuth;
  this->m_azimuth = m_prevAzimuth;
  v8 = m_prevAltitude;
  this->m_altitude = m_prevAltitude;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  if ( m_pTransform != nullptr )
  {
    __libm_sse2_cos(x: v4);
    v9 = m_prevAltitude * m_prevZoom;
    __libm_sse2_sin(x: v4);
    position.x = v11 * (float)(m_prevAltitude * m_prevZoom);
    __libm_sse2_sin(x: v4);
    position.y = v8 * m_prevZoom;
    __libm_sse2_cos(x: v4);
    position.z = position.x;
    HIDWORD(v4) = LODWORD(v8) ^ _mask__NegFloat_;
    angles_4 = v11;
    angles_8 = 0;
    AngleMatrix(angles: (const RadianEuler *)((char *)&v4 + 4), &position, matrix: m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216A70
// Name: public: virtual void CPotteryWheelManip::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPotteryWheelManip::OnTick(CPotteryWheelManip *this@<ecx>, int a2@<edi>)
{
  long double v3; // st7
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  long double v6; // [esp-4h] [ebp-30h]
  long double v7; // [esp-4h] [ebp-30h]
  long double v8; // [esp-4h] [ebp-30h]
  long double v9; // [esp-4h] [ebp-30h]
  RadianEuler angles; // [esp+4h] [ebp-28h] BYREF
  Vector position; // [esp+10h] [ebp-1Ch] BYREF
  float m_altitude; // [esp+1Ch] [ebp-10h]
  float v13; // [esp+20h] [ebp-Ch]
  float v14; // [esp+24h] [ebp-8h]
  float v15; // [esp+28h] [ebp-4h]

  v3 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  m_altitude = v3 - this->m_flLastTickTime;
  this->m_flLastTickTime = v3;
  if ( this->m_bSpin )
  {
    LODWORD(v6) = a2;
    m_pTransform = this->m_pTransform;
    v15 = (float)(this->m_flSpin * m_altitude) + this->m_azimuth;
    this->m_azimuth = v15;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      m_altitude = this->m_altitude;
      v14 = m_zoom;
      __libm_sse2_cos(x: v6);
      v13 = m_altitude * m_zoom;
      __libm_sse2_sin(x: v7);
      position.x = v15 * (float)(m_altitude * m_zoom);
      __libm_sse2_sin(x: v8);
      position.y = m_altitude * m_zoom;
      __libm_sse2_cos(x: v9);
      position.z = position.x;
      LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
      angles.y = v15;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216B80
// Name: public: virtual void CPotteryWheelManip::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelManip::OnCursorMoved(CPotteryWheelManip *this@<ecx>, int a2@<edi>, int x, int y)
{
  long double v5; // st7
  float v6; // xmm0_4
  int v7; // ecx
  int v8; // edx
  float m_altitude; // xmm0_4
  float v10; // xmm0_4
  double v11; // xmm0_8
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  long double v14; // [esp-4h] [ebp-28h]
  long double v15; // [esp-4h] [ebp-28h]
  long double v16; // [esp-4h] [ebp-28h]
  long double v17; // [esp-4h] [ebp-28h]
  RadianEuler angles; // [esp+4h] [ebp-20h] BYREF
  Vector position; // [esp+10h] [ebp-14h] BYREF
  int dy; // [esp+1Ch] [ebp-8h]
  float v21; // [esp+20h] [ebp-4h]

  v5 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  v21 = v5 - this->m_flLastMouseTime;
  this->m_flLastMouseTime = v5;
  if ( this->m_bSpin )
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    LODWORD(v14) = a2;
    v6 = 0.0;
    if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_MIDDLE) )
    {
      v7 = x - this->m_lastx;
      dy = y - this->m_lasty;
      if ( (int)abs32(v7) >= (int)(2 * abs32(dy)) )
      {
        if ( v21 != 0.0 )
          v6 = (float)((float)v7 * 0.0020000001) / v21;
        this->m_flSpin = v6;
        this->m_azimuth = (float)((float)v7 * 0.0020000001) + this->m_azimuth;
      }
      else
      {
        __libm_sse2_pow(x: v14, y: *(long double *)&angles.x);
        this->m_zoom = (float)1.009999990463257 * this->m_zoom;
      }
    }
    else
    {
      v8 = y - this->m_lasty;
      m_altitude = this->m_altitude;
      this->m_azimuth = (float)((float)(x - this->m_lastx) * 0.0020000001) + this->m_azimuth;
      v10 = m_altitude - (float)((float)v8 * 0.0020000001);
      this->m_altitude = v10;
      if ( v10 > 1.570796326794897 || v10 >= -1.570796326794897 )
      {
        if ( v10 <= 1.570796326794897 )
          v11 = v10;
        else
          v11 = 1.570796326794897;
      }
      else
      {
        v11 = -1.570796326794897;
      }
      this->m_altitude = v11;
    }
    m_pTransform = this->m_pTransform;
    this->m_lastx = x;
    this->m_lasty = y;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      v21 = this->m_altitude;
      __libm_sse2_cos(x: v14);
      dy = SLODWORD(this->m_azimuth);
      __libm_sse2_sin(x: v15);
      position.x = *(float *)&dy * (float)(v21 * m_zoom);
      __libm_sse2_sin(x: v16);
      position.y = v21 * m_zoom;
      __libm_sse2_cos(x: v17);
      position.z = position.x;
      LODWORD(angles.x) = LODWORD(v21) ^ _mask__NegFloat_;
      LODWORD(angles.y) = dy;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216DD0
// Name: public: virtual void CPotteryWheelManip::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseWheeled(CPotteryWheelManip *this, int delta)
{
  matrix3x4_t *m_pTransform; // edi
  long double v4; // [esp+0h] [ebp-2Ch]
  long double v5; // [esp+0h] [ebp-2Ch]
  long double v6; // [esp+0h] [ebp-2Ch]
  long double v7; // [esp+0h] [ebp-2Ch]
  long double v8; // [esp+0h] [ebp-2Ch]
  RadianEuler angles; // [esp+8h] [ebp-24h] BYREF
  Vector position; // [esp+14h] [ebp-18h] BYREF
  float m_azimuth; // [esp+20h] [ebp-Ch]
  float m_altitude; // [esp+24h] [ebp-8h]
  float v13; // [esp+28h] [ebp-4h]
  float deltaa; // [esp+34h] [ebp+8h]

  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  __libm_sse2_pow(x: v4, y: *(long double *)&angles.x);
  m_pTransform = this->m_pTransform;
  deltaa = (float)1.009999990463257 * this->m_zoom;
  this->m_zoom = deltaa;
  if ( m_pTransform != nullptr )
  {
    m_altitude = this->m_altitude;
    __libm_sse2_cos(x: v5);
    v13 = m_altitude * deltaa;
    m_azimuth = this->m_azimuth;
    __libm_sse2_sin(x: v6);
    position.x = m_azimuth * (float)(m_altitude * deltaa);
    __libm_sse2_sin(x: v7);
    position.y = m_altitude * deltaa;
    __libm_sse2_cos(x: v8);
    position.z = position.x;
    LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
    angles.y = m_azimuth;
    angles.z = 0.0;
    AngleMatrix(&angles, &position, matrix: m_pTransform);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00416D20
// Name: public: virtual void CPotteryWheelManip::OnBeginManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnBeginManipulation(CPotteryWheelManip *this)
{
  long double v2; // st7

  this->m_prevZoom = this->m_zoom;
  this->m_prevAltitude = this->m_altitude;
  this->m_prevAzimuth = this->m_azimuth;
  v2 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_flLastTickTime = v2;
  this->m_flLastMouseTime = v2;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x00416D60
// Name: public: virtual void CPotteryWheelManip::OnAcceptManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnAcceptManipulation(CPotteryWheelManip *this)
{
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x00416D70
// Name: public: virtual void CPotteryWheelManip::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMousePressed(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_lastx = x;
  this->m_lasty = y;
  this->m_bSpin = false;
  this->m_flSpin = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00416DB0
// Name: public: virtual void CPotteryWheelManip::OnMouseReleased(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseReleased(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  if ( code == MOUSE_MIDDLE )
  {
    this->m_bSpin = COERCE_FLOAT(LODWORD(this->m_flSpin) & _mask__AbsFloat_) > 1.0;
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416E30
// Name: public: CTransformManipulator::CTransformManipulator(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTransformManipulator *__thiscall CTransformManipulator::CTransformManipulator(
        CTransformManipulator *this,
        matrix3x4_t *pTransform)
{
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CTransformManipulator_vtbl *)&CTransformManipulator::`vftable';
  this->m_pTransform = pTransform;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416E50
// Name: public: CPotteryWheelManip::CPotteryWheelManip(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelManip *__thiscall CPotteryWheelManip::CPotteryWheelManip(
        CPotteryWheelManip *this,
        matrix3x4_t *pTransform)
{
  this->m_pTransform = pTransform;
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CPotteryWheelManip_vtbl *)&CPotteryWheelManip::`vftable';
  this->m_lastx = -1;
  this->m_lasty = -1;
  this->m_zoom = 100.0;
  this->m_altitude = 0.0;
  this->m_azimuth = 0.0;
  this->m_prevZoom = 100.0;
  this->m_prevAltitude = 0.0;
  this->m_prevAzimuth = 0.0;
  this->m_flLastMouseTime = 0.0;
  this->m_flLastTickTime = 0.0;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416EC0
// Name: public: virtual void CPotteryWheelManip::OnCancelManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnCancelManipulation(CPotteryWheelManip *this)
{
  float m_prevAzimuth; // xmm1_4
  matrix3x4_t *m_pTransform; // esi
  float m_prevAltitude; // xmm0_4
  long double v4; // [esp-4h] [ebp-2Ch] BYREF
  float angles_4; // [esp+4h] [ebp-24h]
  int angles_8; // [esp+8h] [ebp-20h]
  Vector position; // [esp+Ch] [ebp-1Ch] BYREF
  float v8; // [esp+18h] [ebp-10h]
  float v9; // [esp+1Ch] [ebp-Ch]
  float m_prevZoom; // [esp+20h] [ebp-8h]
  float v11; // [esp+24h] [ebp-4h]

  m_prevAzimuth = this->m_prevAzimuth;
  m_pTransform = this->m_pTransform;
  m_prevZoom = this->m_prevZoom;
  this->m_zoom = m_prevZoom;
  m_prevAltitude = this->m_prevAltitude;
  v11 = m_prevAzimuth;
  this->m_azimuth = m_prevAzimuth;
  v8 = m_prevAltitude;
  this->m_altitude = m_prevAltitude;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  if ( m_pTransform != nullptr )
  {
    __libm_sse2_cos(x: v4);
    v9 = m_prevAltitude * m_prevZoom;
    __libm_sse2_sin(x: v4);
    position.x = v11 * (float)(m_prevAltitude * m_prevZoom);
    __libm_sse2_sin(x: v4);
    position.y = v8 * m_prevZoom;
    __libm_sse2_cos(x: v4);
    position.z = position.x;
    HIDWORD(v4) = LODWORD(v8) ^ _mask__NegFloat_;
    angles_4 = v11;
    angles_8 = 0;
    AngleMatrix(angles: (const RadianEuler *)((char *)&v4 + 4), &position, matrix: m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416FB0
// Name: public: virtual void CPotteryWheelManip::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPotteryWheelManip::OnTick(CPotteryWheelManip *this@<ecx>, int a2@<edi>)
{
  long double v3; // st7
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  long double v6; // [esp-4h] [ebp-30h]
  long double v7; // [esp-4h] [ebp-30h]
  long double v8; // [esp-4h] [ebp-30h]
  long double v9; // [esp-4h] [ebp-30h]
  RadianEuler angles; // [esp+4h] [ebp-28h] BYREF
  Vector position; // [esp+10h] [ebp-1Ch] BYREF
  float m_altitude; // [esp+1Ch] [ebp-10h]
  float v13; // [esp+20h] [ebp-Ch]
  float v14; // [esp+24h] [ebp-8h]
  float v15; // [esp+28h] [ebp-4h]

  v3 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  m_altitude = v3 - this->m_flLastTickTime;
  this->m_flLastTickTime = v3;
  if ( this->m_bSpin )
  {
    LODWORD(v6) = a2;
    m_pTransform = this->m_pTransform;
    v15 = (float)(this->m_flSpin * m_altitude) + this->m_azimuth;
    this->m_azimuth = v15;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      m_altitude = this->m_altitude;
      v14 = m_zoom;
      __libm_sse2_cos(x: v6);
      v13 = m_altitude * m_zoom;
      __libm_sse2_sin(x: v7);
      position.x = v15 * (float)(m_altitude * m_zoom);
      __libm_sse2_sin(x: v8);
      position.y = m_altitude * m_zoom;
      __libm_sse2_cos(x: v9);
      position.z = position.x;
      LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
      angles.y = v15;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004170C0
// Name: public: virtual void CPotteryWheelManip::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelManip::OnCursorMoved(CPotteryWheelManip *this@<ecx>, int a2@<edi>, int x, int y)
{
  long double v5; // st7
  float v6; // xmm0_4
  int v7; // ecx
  int v8; // edx
  float m_altitude; // xmm0_4
  float v10; // xmm0_4
  double v11; // xmm0_8
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  long double v14; // [esp-4h] [ebp-28h]
  long double v15; // [esp-4h] [ebp-28h]
  long double v16; // [esp-4h] [ebp-28h]
  long double v17; // [esp-4h] [ebp-28h]
  RadianEuler angles; // [esp+4h] [ebp-20h] BYREF
  Vector position; // [esp+10h] [ebp-14h] BYREF
  int dy; // [esp+1Ch] [ebp-8h]
  float v21; // [esp+20h] [ebp-4h]

  v5 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  v21 = v5 - this->m_flLastMouseTime;
  this->m_flLastMouseTime = v5;
  if ( this->m_bSpin )
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    LODWORD(v14) = a2;
    v6 = 0.0;
    if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_MIDDLE) )
    {
      v7 = x - this->m_lastx;
      dy = y - this->m_lasty;
      if ( (int)abs32(v7) >= (int)(2 * abs32(dy)) )
      {
        if ( v21 != 0.0 )
          v6 = (float)((float)v7 * 0.0020000001) / v21;
        this->m_flSpin = v6;
        this->m_azimuth = (float)((float)v7 * 0.0020000001) + this->m_azimuth;
      }
      else
      {
        __libm_sse2_pow(x: v14, y: *(long double *)&angles.x);
        this->m_zoom = (float)1.009999990463257 * this->m_zoom;
      }
    }
    else
    {
      v8 = y - this->m_lasty;
      m_altitude = this->m_altitude;
      this->m_azimuth = (float)((float)(x - this->m_lastx) * 0.0020000001) + this->m_azimuth;
      v10 = m_altitude - (float)((float)v8 * 0.0020000001);
      this->m_altitude = v10;
      if ( v10 > 1.570796326794897 || v10 >= -1.570796326794897 )
      {
        if ( v10 <= 1.570796326794897 )
          v11 = v10;
        else
          v11 = 1.570796326794897;
      }
      else
      {
        v11 = -1.570796326794897;
      }
      this->m_altitude = v11;
    }
    m_pTransform = this->m_pTransform;
    this->m_lastx = x;
    this->m_lasty = y;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      v21 = this->m_altitude;
      __libm_sse2_cos(x: v14);
      dy = SLODWORD(this->m_azimuth);
      __libm_sse2_sin(x: v15);
      position.x = *(float *)&dy * (float)(v21 * m_zoom);
      __libm_sse2_sin(x: v16);
      position.y = v21 * m_zoom;
      __libm_sse2_cos(x: v17);
      position.z = position.x;
      LODWORD(angles.x) = LODWORD(v21) ^ _mask__NegFloat_;
      LODWORD(angles.y) = dy;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417310
// Name: public: virtual void CPotteryWheelManip::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseWheeled(CPotteryWheelManip *this, int delta)
{
  matrix3x4_t *m_pTransform; // edi
  long double v4; // [esp+0h] [ebp-2Ch]
  long double v5; // [esp+0h] [ebp-2Ch]
  long double v6; // [esp+0h] [ebp-2Ch]
  long double v7; // [esp+0h] [ebp-2Ch]
  long double v8; // [esp+0h] [ebp-2Ch]
  RadianEuler angles; // [esp+8h] [ebp-24h] BYREF
  Vector position; // [esp+14h] [ebp-18h] BYREF
  float m_azimuth; // [esp+20h] [ebp-Ch]
  float m_altitude; // [esp+24h] [ebp-8h]
  float v13; // [esp+28h] [ebp-4h]
  float deltaa; // [esp+34h] [ebp+8h]

  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  __libm_sse2_pow(x: v4, y: *(long double *)&angles.x);
  m_pTransform = this->m_pTransform;
  deltaa = (float)1.009999990463257 * this->m_zoom;
  this->m_zoom = deltaa;
  if ( m_pTransform != nullptr )
  {
    m_altitude = this->m_altitude;
    __libm_sse2_cos(x: v5);
    v13 = m_altitude * deltaa;
    m_azimuth = this->m_azimuth;
    __libm_sse2_sin(x: v6);
    position.x = m_azimuth * (float)(m_altitude * deltaa);
    __libm_sse2_sin(x: v7);
    position.y = m_altitude * deltaa;
    __libm_sse2_cos(x: v8);
    position.z = position.x;
    LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
    angles.y = m_azimuth;
    angles.z = 0.0;
    AngleMatrix(&angles, &position, matrix: m_pTransform);
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004E51D0
// Name: public: virtual void CPotteryWheelManip::OnBeginManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnBeginManipulation(CPotteryWheelManip *this)
{
  long double v2; // st7

  this->m_prevZoom = this->m_zoom;
  this->m_prevAltitude = this->m_altitude;
  this->m_prevAzimuth = this->m_azimuth;
  v2 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_flLastTickTime = v2;
  this->m_flLastMouseTime = v2;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x004E5210
// Name: public: virtual void CPotteryWheelManip::OnAcceptManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnAcceptManipulation(CPotteryWheelManip *this)
{
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x004E5220
// Name: public: virtual void CPotteryWheelManip::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMousePressed(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_lastx = x;
  this->m_lasty = y;
  this->m_bSpin = false;
  this->m_flSpin = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004E5260
// Name: public: virtual void CPotteryWheelManip::OnMouseReleased(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseReleased(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  if ( code == MOUSE_MIDDLE )
  {
    this->m_bSpin = COERCE_FLOAT(LODWORD(this->m_flSpin) & _mask__AbsFloat_) > 1.0;
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E52E0
// Name: public: CTransformManipulator::CTransformManipulator(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTransformManipulator *__thiscall CTransformManipulator::CTransformManipulator(
        CTransformManipulator *this,
        matrix3x4_t *pTransform)
{
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CTransformManipulator_vtbl *)&CTransformManipulator::`vftable';
  this->m_pTransform = pTransform;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E5300
// Name: public: CPotteryWheelManip::CPotteryWheelManip(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelManip *__thiscall CPotteryWheelManip::CPotteryWheelManip(
        CPotteryWheelManip *this,
        matrix3x4_t *pTransform)
{
  this->m_pTransform = pTransform;
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CPotteryWheelManip_vtbl *)&CPotteryWheelManip::`vftable';
  this->m_lastx = -1;
  this->m_lasty = -1;
  this->m_zoom = 100.0;
  this->m_altitude = 0.0;
  this->m_azimuth = 0.0;
  this->m_prevZoom = 100.0;
  this->m_prevAltitude = 0.0;
  this->m_prevAzimuth = 0.0;
  this->m_flLastMouseTime = 0.0;
  this->m_flLastTickTime = 0.0;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E5370
// Name: public: virtual void CPotteryWheelManip::OnCancelManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnCancelManipulation(CPotteryWheelManip *this)
{
  float m_prevAzimuth; // xmm1_4
  matrix3x4_t *m_pTransform; // esi
  float m_prevAltitude; // xmm0_4
  long double v4; // [esp-4h] [ebp-2Ch] BYREF
  float angles_4; // [esp+4h] [ebp-24h]
  int angles_8; // [esp+8h] [ebp-20h]
  Vector position; // [esp+Ch] [ebp-1Ch] BYREF
  float v8; // [esp+18h] [ebp-10h]
  float v9; // [esp+1Ch] [ebp-Ch]
  float m_prevZoom; // [esp+20h] [ebp-8h]
  float v11; // [esp+24h] [ebp-4h]

  m_prevAzimuth = this->m_prevAzimuth;
  m_pTransform = this->m_pTransform;
  m_prevZoom = this->m_prevZoom;
  this->m_zoom = m_prevZoom;
  m_prevAltitude = this->m_prevAltitude;
  v11 = m_prevAzimuth;
  this->m_azimuth = m_prevAzimuth;
  v8 = m_prevAltitude;
  this->m_altitude = m_prevAltitude;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  if ( m_pTransform != nullptr )
  {
    __libm_sse2_cos(x: v4);
    v9 = m_prevAltitude * m_prevZoom;
    __libm_sse2_sin(x: v4);
    position.x = v11 * (float)(m_prevAltitude * m_prevZoom);
    __libm_sse2_sin(x: v4);
    position.y = v8 * m_prevZoom;
    __libm_sse2_cos(x: v4);
    position.z = position.x;
    HIDWORD(v4) = LODWORD(v8) ^ _mask__NegFloat_;
    angles_4 = v11;
    angles_8 = 0;
    AngleMatrix(angles: (const RadianEuler *)((char *)&v4 + 4), &position, matrix: m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E5460
// Name: public: virtual void CPotteryWheelManip::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPotteryWheelManip::OnTick(CPotteryWheelManip *this@<ecx>, int a2@<edi>)
{
  long double v3; // st7
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  long double v6; // [esp-4h] [ebp-30h]
  long double v7; // [esp-4h] [ebp-30h]
  long double v8; // [esp-4h] [ebp-30h]
  long double v9; // [esp-4h] [ebp-30h]
  RadianEuler angles; // [esp+4h] [ebp-28h] BYREF
  Vector position; // [esp+10h] [ebp-1Ch] BYREF
  float m_altitude; // [esp+1Ch] [ebp-10h]
  float v13; // [esp+20h] [ebp-Ch]
  float v14; // [esp+24h] [ebp-8h]
  float v15; // [esp+28h] [ebp-4h]

  v3 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  m_altitude = v3 - this->m_flLastTickTime;
  this->m_flLastTickTime = v3;
  if ( this->m_bSpin )
  {
    LODWORD(v6) = a2;
    m_pTransform = this->m_pTransform;
    v15 = (float)(this->m_flSpin * m_altitude) + this->m_azimuth;
    this->m_azimuth = v15;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      m_altitude = this->m_altitude;
      v14 = m_zoom;
      __libm_sse2_cos(x: v6);
      v13 = m_altitude * m_zoom;
      __libm_sse2_sin(x: v7);
      position.x = v15 * (float)(m_altitude * m_zoom);
      __libm_sse2_sin(x: v8);
      position.y = m_altitude * m_zoom;
      __libm_sse2_cos(x: v9);
      position.z = position.x;
      LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
      angles.y = v15;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E5570
// Name: public: virtual void CPotteryWheelManip::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPotteryWheelManip::OnCursorMoved(CPotteryWheelManip *this@<ecx>, int a2@<edi>, int x, int y)
{
  long double v5; // st7
  float v6; // xmm0_4
  int v7; // ecx
  int v8; // edx
  float m_altitude; // xmm0_4
  float v10; // xmm0_4
  double v11; // xmm0_8
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  long double v14; // [esp-4h] [ebp-28h]
  long double v15; // [esp-4h] [ebp-28h]
  long double v16; // [esp-4h] [ebp-28h]
  long double v17; // [esp-4h] [ebp-28h]
  RadianEuler angles; // [esp+4h] [ebp-20h] BYREF
  Vector position; // [esp+10h] [ebp-14h] BYREF
  int dy; // [esp+1Ch] [ebp-8h]
  float v21; // [esp+20h] [ebp-4h]

  v5 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  v21 = v5 - this->m_flLastMouseTime;
  this->m_flLastMouseTime = v5;
  if ( this->m_bSpin )
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    LODWORD(v14) = a2;
    v6 = 0.0;
    if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_MIDDLE) )
    {
      v7 = x - this->m_lastx;
      dy = y - this->m_lasty;
      if ( (int)abs32(v7) >= (int)(2 * abs32(dy)) )
      {
        if ( v21 != 0.0 )
          v6 = (float)((float)v7 * 0.0020000001) / v21;
        this->m_flSpin = v6;
        this->m_azimuth = (float)((float)v7 * 0.0020000001) + this->m_azimuth;
      }
      else
      {
        __libm_sse2_pow(x: v14, y: *(long double *)&angles.x);
        this->m_zoom = (float)1.009999990463257 * this->m_zoom;
      }
    }
    else
    {
      v8 = y - this->m_lasty;
      m_altitude = this->m_altitude;
      this->m_azimuth = (float)((float)(x - this->m_lastx) * 0.0020000001) + this->m_azimuth;
      v10 = m_altitude - (float)((float)v8 * 0.0020000001);
      this->m_altitude = v10;
      if ( v10 > 1.570796326794897 || v10 >= -1.570796326794897 )
      {
        if ( v10 <= 1.570796326794897 )
          v11 = v10;
        else
          v11 = 1.570796326794897;
      }
      else
      {
        v11 = -1.570796326794897;
      }
      this->m_altitude = v11;
    }
    m_pTransform = this->m_pTransform;
    this->m_lastx = x;
    this->m_lasty = y;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      v21 = this->m_altitude;
      __libm_sse2_cos(x: v14);
      dy = SLODWORD(this->m_azimuth);
      __libm_sse2_sin(x: v15);
      position.x = *(float *)&dy * (float)(v21 * m_zoom);
      __libm_sse2_sin(x: v16);
      position.y = v21 * m_zoom;
      __libm_sse2_cos(x: v17);
      position.z = position.x;
      LODWORD(angles.x) = LODWORD(v21) ^ _mask__NegFloat_;
      LODWORD(angles.y) = dy;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E57C0
// Name: public: virtual void CPotteryWheelManip::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseWheeled(CPotteryWheelManip *this, int delta)
{
  matrix3x4_t *m_pTransform; // edi
  long double v4; // [esp+0h] [ebp-2Ch]
  long double v5; // [esp+0h] [ebp-2Ch]
  long double v6; // [esp+0h] [ebp-2Ch]
  long double v7; // [esp+0h] [ebp-2Ch]
  long double v8; // [esp+0h] [ebp-2Ch]
  RadianEuler angles; // [esp+8h] [ebp-24h] BYREF
  Vector position; // [esp+14h] [ebp-18h] BYREF
  float m_azimuth; // [esp+20h] [ebp-Ch]
  float m_altitude; // [esp+24h] [ebp-8h]
  float v13; // [esp+28h] [ebp-4h]
  float deltaa; // [esp+34h] [ebp+8h]

  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  __libm_sse2_pow(x: v4, y: *(long double *)&angles.x);
  m_pTransform = this->m_pTransform;
  deltaa = (float)1.009999990463257 * this->m_zoom;
  this->m_zoom = deltaa;
  if ( m_pTransform != nullptr )
  {
    m_altitude = this->m_altitude;
    __libm_sse2_cos(x: v5);
    v13 = m_altitude * deltaa;
    m_azimuth = this->m_azimuth;
    __libm_sse2_sin(x: v6);
    position.x = m_azimuth * (float)(m_altitude * deltaa);
    __libm_sse2_sin(x: v7);
    position.y = m_altitude * deltaa;
    __libm_sse2_cos(x: v8);
    position.z = position.x;
    LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
    angles.y = m_azimuth;
    angles.z = 0.0;
    AngleMatrix(&angles, &position, matrix: m_pTransform);
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102CE630
// Name: public: virtual void CPotteryWheelManip::OnBeginManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnBeginManipulation(CPotteryWheelManip *this)
{
  long double v2; // st7

  this->m_prevZoom = this->m_zoom;
  this->m_prevAltitude = this->m_altitude;
  this->m_prevAzimuth = this->m_azimuth;
  v2 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_flLastTickTime = v2;
  this->m_flLastMouseTime = v2;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x102CE670
// Name: public: virtual void CPotteryWheelManip::OnAcceptManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnAcceptManipulation(CPotteryWheelManip *this)
{
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
}

//------------------------------------------------------------------------------
// Address: 0x102CE680
// Name: public: virtual void CPotteryWheelManip::OnMousePressed(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMousePressed(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_lastx = x;
  this->m_lasty = y;
  this->m_bSpin = false;
  this->m_flSpin = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102CE6C0
// Name: public: virtual void CPotteryWheelManip::OnMouseReleased(enum ButtonCode_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseReleased(CPotteryWheelManip *this, ButtonCode_t code, int x, int y)
{
  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  if ( code == MOUSE_MIDDLE )
  {
    this->m_bSpin = COERCE_FLOAT(LODWORD(this->m_flSpin) & _mask__AbsFloat_) > 1.0;
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE740
// Name: public: CTransformManipulator::CTransformManipulator(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTransformManipulator *__thiscall CTransformManipulator::CTransformManipulator(
        CTransformManipulator *this,
        matrix3x4_t *pTransform)
{
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CTransformManipulator_vtbl *)&CTransformManipulator::`vftable';
  this->m_pTransform = pTransform;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CE760
// Name: public: CPotteryWheelManip::CPotteryWheelManip(struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPotteryWheelManip *__thiscall CPotteryWheelManip::CPotteryWheelManip(
        CPotteryWheelManip *this,
        matrix3x4_t *pTransform)
{
  this->m_pTransform = pTransform;
  this->m_nViewport[1] = 0;
  this->m_nViewport[0] = 0;
  this->__vftable = (CPotteryWheelManip_vtbl *)&CPotteryWheelManip::`vftable';
  this->m_lastx = -1;
  this->m_lasty = -1;
  this->m_zoom = 100.0;
  this->m_altitude = 0.0;
  this->m_azimuth = 0.0;
  this->m_prevZoom = 100.0;
  this->m_prevAltitude = 0.0;
  this->m_prevAzimuth = 0.0;
  this->m_flLastMouseTime = 0.0;
  this->m_flLastTickTime = 0.0;
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CE7D0
// Name: public: virtual void CPotteryWheelManip::OnCancelManipulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnCancelManipulation(CPotteryWheelManip *this)
{
  float m_prevAzimuth; // xmm1_4
  matrix3x4_t *m_pTransform; // esi
  __m128 m_prevAltitude_low; // xmm0
  double v4; // xmm0_8
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  RadianEuler angles; // [esp+0h] [ebp-28h] BYREF
  Vector position; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+18h] [ebp-10h]
  float v11; // [esp+1Ch] [ebp-Ch]
  float m_prevZoom; // [esp+20h] [ebp-8h]
  float v13; // [esp+24h] [ebp-4h]

  m_prevAzimuth = this->m_prevAzimuth;
  m_pTransform = this->m_pTransform;
  m_prevZoom = this->m_prevZoom;
  this->m_zoom = m_prevZoom;
  m_prevAltitude_low = (__m128)LODWORD(this->m_prevAltitude);
  v13 = m_prevAzimuth;
  this->m_azimuth = m_prevAzimuth;
  v10 = m_prevAltitude_low.m128_i32[0];
  LODWORD(this->m_altitude) = m_prevAltitude_low.m128_i32[0];
  this->m_flSpin = 0.0;
  this->m_bSpin = false;
  if ( m_pTransform != nullptr )
  {
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(m_prevAltitude_low));
    *(float *)&v4 = v4;
    v11 = *(float *)&v4 * m_prevZoom;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v13)));
    *(float *)&v5 = v5;
    position.x = *(float *)&v5 * v11;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)v10));
    *(float *)&v6 = v6;
    position.y = *(float *)&v6 * m_prevZoom;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v13)));
    *(float *)&v7 = v7;
    position.z = *(float *)&v7 * v11;
    LODWORD(angles.x) = v10 ^ _mask__NegFloat_;
    angles.y = v13;
    angles.z = 0.0;
    AngleMatrix(&angles, &position, matrix: m_pTransform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE8C0
// Name: public: virtual void CPotteryWheelManip::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnTick(CPotteryWheelManip *this)
{
  long double v2; // st7
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  double v8; // xmm0_8
  RadianEuler angles; // [esp+4h] [ebp-28h] BYREF
  Vector position; // [esp+10h] [ebp-1Ch] BYREF
  float m_altitude; // [esp+1Ch] [ebp-10h]
  float v12; // [esp+20h] [ebp-Ch]
  float v13; // [esp+24h] [ebp-8h]
  float v14; // [esp+28h] [ebp-4h]

  v2 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  m_altitude = v2 - this->m_flLastTickTime;
  this->m_flLastTickTime = v2;
  if ( this->m_bSpin )
  {
    m_pTransform = this->m_pTransform;
    v14 = (float)(this->m_flSpin * m_altitude) + this->m_azimuth;
    this->m_azimuth = v14;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      m_altitude = this->m_altitude;
      v13 = m_zoom;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_altitude)));
      *(float *)&v5 = v5;
      v12 = *(float *)&v5 * m_zoom;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v14)));
      *(float *)&v6 = v6;
      position.x = *(float *)&v6 * v12;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_altitude)));
      *(float *)&v7 = v7;
      position.y = *(float *)&v7 * m_zoom;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v14)));
      *(float *)&v8 = v8;
      position.z = *(float *)&v8 * v12;
      LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
      angles.y = v14;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE9D0
// Name: public: virtual void CPotteryWheelManip::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnCursorMoved(CPotteryWheelManip *this, int x, int y)
{
  long double v4; // st7
  float v5; // xmm0_4
  int v6; // ecx
  int v7; // edx
  float m_altitude; // xmm0_4
  float v9; // xmm0_4
  double v10; // xmm0_8
  matrix3x4_t *m_pTransform; // edi
  float m_zoom; // xmm1_4
  double v13; // xmm0_8
  double v14; // xmm0_8
  double v15; // xmm0_8
  double v16; // xmm0_8
  RadianEuler angles; // [esp+4h] [ebp-20h] BYREF
  Vector position; // [esp+10h] [ebp-14h] BYREF
  int dy; // [esp+1Ch] [ebp-8h]
  float v20; // [esp+20h] [ebp-4h]
  float ya; // [esp+30h] [ebp+Ch]

  v4 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  v20 = v4 - this->m_flLastMouseTime;
  this->m_flLastMouseTime = v4;
  if ( this->m_bSpin )
  {
    this->m_lastx = x;
    this->m_lasty = y;
  }
  else
  {
    v5 = 0.0;
    if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_MIDDLE) )
    {
      v6 = x - this->m_lastx;
      dy = y - this->m_lasty;
      if ( (int)abs32(v6) >= (int)(2 * abs32(dy)) )
      {
        if ( v20 != 0.0 )
          v5 = (float)((float)v6 * 0.0020000001) / v20;
        this->m_flSpin = v5;
        this->m_azimuth = (float)((float)v6 * 0.0020000001) + this->m_azimuth;
      }
      else
      {
        __libm_sse2_pow();
        this->m_zoom = (float)1.009999990463257 * this->m_zoom;
      }
    }
    else
    {
      v7 = y - this->m_lasty;
      m_altitude = this->m_altitude;
      this->m_azimuth = (float)((float)(x - this->m_lastx) * 0.0020000001) + this->m_azimuth;
      v9 = m_altitude - (float)((float)v7 * 0.0020000001);
      this->m_altitude = v9;
      if ( v9 > 1.570796326794897 || v9 >= -1.570796326794897 )
      {
        if ( v9 <= 1.570796326794897 )
          v10 = v9;
        else
          v10 = 1.570796326794897;
      }
      else
      {
        v10 = -1.570796326794897;
      }
      this->m_altitude = v10;
    }
    m_pTransform = this->m_pTransform;
    this->m_lastx = x;
    this->m_lasty = y;
    if ( m_pTransform != nullptr )
    {
      m_zoom = this->m_zoom;
      v20 = this->m_altitude;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v20)));
      *(float *)&v13 = v13;
      ya = *(float *)&v13 * m_zoom;
      dy = LODWORD(this->m_azimuth);
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)dy));
      *(float *)&v14 = v14;
      position.x = *(float *)&v14 * ya;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v20)));
      *(float *)&v15 = v15;
      position.y = *(float *)&v15 * m_zoom;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)dy));
      *(float *)&v16 = v16;
      position.z = *(float *)&v16 * ya;
      LODWORD(angles.x) = LODWORD(v20) ^ _mask__NegFloat_;
      LODWORD(angles.y) = dy;
      angles.z = 0.0;
      AngleMatrix(&angles, &position, matrix: m_pTransform);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CEC20
// Name: public: virtual void CPotteryWheelManip::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPotteryWheelManip::OnMouseWheeled(CPotteryWheelManip *this, int delta)
{
  matrix3x4_t *m_pTransform; // edi
  double v4; // xmm0_8
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  RadianEuler angles; // [esp+8h] [ebp-24h] BYREF
  Vector position; // [esp+14h] [ebp-18h] BYREF
  float m_azimuth; // [esp+20h] [ebp-Ch]
  float m_altitude; // [esp+24h] [ebp-8h]
  float v12; // [esp+28h] [ebp-4h]
  float deltaa; // [esp+34h] [ebp+8h]

  this->m_flLastMouseTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  __libm_sse2_pow();
  m_pTransform = this->m_pTransform;
  deltaa = (float)1.009999990463257 * this->m_zoom;
  this->m_zoom = deltaa;
  if ( m_pTransform != nullptr )
  {
    m_altitude = this->m_altitude;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_altitude)));
    *(float *)&v4 = v4;
    v12 = *(float *)&v4 * deltaa;
    m_azimuth = this->m_azimuth;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_azimuth)));
    *(float *)&v5 = v5;
    position.x = *(float *)&v5 * v12;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_altitude)));
    *(float *)&v6 = v6;
    position.y = *(float *)&v6 * deltaa;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_azimuth)));
    *(float *)&v7 = v7;
    position.z = *(float *)&v7 * v12;
    LODWORD(angles.x) = LODWORD(m_altitude) ^ _mask__NegFloat_;
    angles.y = m_azimuth;
    angles.z = 0.0;
    AngleMatrix(&angles, &position, matrix: m_pTransform);
  }
}

} // namespace client
