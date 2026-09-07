// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapoccluder.cpp
// Functions: 12
// ============================================================

#include "hammer\mapoccluder.h"

//------------------------------------------------------------------------------
// Address: 0x10133750
// Name: public: virtual char const __near * CMapOccluder::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapOccluder::GetType(CMapOccluder *this)
{
  return CMapOccluder::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10133760
// Name: public: virtual int CMapOccluder::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapOccluder::IsMapClass(CMapOccluder *this, const char *Type)
{
  return Type == CMapOccluder::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101338D0
// Name: public: virtual class CMapClass __near * CMapOccluder::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapSphere *__thiscall CMapOccluder::Copy(CMapOccluder *this, BOOL bUpdateDependencies)
{
  CMapSphere *v2; // eax
  CMapSphere *v3; // esi

  v2 = (CMapSphere *)operator new(nSize: 0x134u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CMapSphere::CMapSphere(this: v2);
    v3->__vftable = (CMapSphere_vtbl *)&CMapOccluder::`vftable';
    v3->m_szKeyName[0] = 0;
    v3->m_flRadius = 0.0;
    *(_WORD *)&v3->r = 255;
    v3->b = 0;
    CMapClass::SetVisible(this: v3, bVisible: true);
    *((_BYTE *)&v3->CMapClass + 180) |= 1u;
    v3[1].__vftable = (CMapSphere_vtbl *)-1;
    LOBYTE(v3[1].m_nObjectID) = 0;
  }
  else
  {
    v3 = nullptr;
  }
  if ( v3 != nullptr )
    v3->CopyFrom(this: v3, a2: this, a3: bUpdateDependencies);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101339E0
// Name: public: virtual void CMapOccluder::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOccluder::OnParentKeyChanged(CMapOccluder *this, const char *szKey, const char *szValue)
{
  CFoW *m_pFoW; // ecx

  if ( _V_stricmp(s1: szKey, s2: this->m_szKeyName) == 0 )
  {
    this->m_flRadius = atof(nptr: szValue);
    this->PostUpdate(this, a2: Notify_Changed);
    m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
    if ( m_pFoW != nullptr )
      CFoW::UpdateOccluderSize(this: m_pFoW, nID: this->m_FoWHandle, flRadius: this->m_flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133A50
// Name: public: virtual void CMapOccluder::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOccluder::OnRemoveFromWorld(CMapOccluder *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  CFoW *m_pFoW; // ecx

  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr && this->m_FoWHandle != -1 )
    CFoW::RemoveOccluder(this: m_pFoW, nID: this->m_FoWHandle);
  this->m_FoWHandle = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10133A90
// Name: public: virtual void CMapOccluder::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOccluder::Render2D(CMapOccluder *this, CRender2D *pRender)
{
  float v4; // xmm0_4
  CFoW *m_pFoW; // ecx
  double LocationVisibilityDegree; // st7
  float flRadius_4; // [esp+4h] [ebp-2Ch]
  Vector2D fRadius; // [esp+14h] [ebp-1Ch] BYREF
  Vector v9; // [esp+1Ch] [ebp-14h] BYREF
  float v10; // [esp+28h] [ebp-8h]
  __int64 vWorld; // [esp+2Ch] [ebp-4h]
  char v12; // [esp+3Bh] [ebp+Bh]

  if ( this->m_flRadius > 0.0 )
  {
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
    v9.x = this->m_flRadius;
    v9.y = v9.x;
    v9.z = v9.x;
    CRender::TransformNormal(this: pRender, vClient: &fRadius, vWorld: &v9);
    flRadius_4 = this->m_flRadius;
    LODWORD(vWorld) = (int)fRadius.x;
    CRender2D::DrawCircle(
      this: pRender,
      a2: (unsigned int)&this->m_Origin,
      a3: (unsigned int)this,
      vCenter: &this->m_Origin,
      fRadius: flRadius_4);
    v12 = CRender::BeginClientSpace(this: pRender, a2: (int)pRender);
    CRender::SetHandleStyle(this: pRender, size: 4, type: 1);
    CRender::SetHandleColor(this: pRender, r: 0xFFu, g: 0, b: 0);
    if ( this->IsSelected(this) )
    {
      v9.y = 0.0;
      v4 = (float)(-6 - vWorld);
      this->m_bWasSelected = true;
      v10 = v4;
      v9.z = v4;
      CRender::DrawHandle(this: pRender, vCenter: &this->m_Origin, vOffset: (const Vector2D *)&v9.y);
      v9.y = 0.0;
      *(float *)&vWorld = (float)(vWorld + 6);
      LODWORD(v9.z) = vWorld;
      CRender::DrawHandle(this: pRender, vCenter: &this->m_Origin, vOffset: (const Vector2D *)&v9.y);
      v9.y = v10;
      v9.z = 0.0;
      CRender::DrawHandle(this: pRender, vCenter: &this->m_Origin, vOffset: (const Vector2D *)&v9.y);
      LODWORD(v9.y) = vWorld;
      v9.z = 0.0;
      CRender::DrawHandle(this: pRender, vCenter: &this->m_Origin, vOffset: (const Vector2D *)&v9.y);
    }
    CRender::DrawHandle(this: pRender, vCenter: &this->m_Origin, vOffset: &vec2_origin_183);
    if ( v12 != 0 )
      CRender::EndClientSpace(this: pRender);
    m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
    if ( m_pFoW != nullptr && this->m_bWasSelected )
    {
      LocationVisibilityDegree = CFoW::GetLocationVisibilityDegree(
                                   this: m_pFoW,
                                   nViewerTeam: 0,
                                   vLocation: &this->m_Origin,
                                   flRadius: this->m_flRadius);
      _Msg(a1: "Visibility = %g\n", LocationVisibilityDegree);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133C40
// Name: public: virtual void CMapOccluder::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOccluder::Render3D(CMapOccluder *this, CRender3D *pRender)
{
  float m_flRadius; // xmm0_4

  m_flRadius = this->m_flRadius;
  if ( m_flRadius > 0.0 )
    CRender3D::RenderWireframeSphere(
      this: pRender,
      vCenter: &this->m_Origin,
      flRadius: m_flRadius,
      nTheta: 12,
      nPhi: 12,
      chRed: 0xFFu,
      chGreen: 0,
      chBlue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10133C80
// Name: public: virtual void CMapOccluder::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOccluder::SetOrigin(CMapOccluder *this, Vector *vecOrigin)
{
  CFoW *m_pFoW; // ecx

  CMapClass::SetOrigin(this, origin: vecOrigin);
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    CFoW::UpdateOccluderLocation(this: m_pFoW, nID: this->m_FoWHandle, vLocation: vecOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x10133CD0
// Name: protected: virtual void CMapOccluder::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOccluder::DoTransform(CMapOccluder *this, const VMatrix *matrix)
{
  CFoW *m_pFoW; // ecx

  CMapClass::DoTransform(this, matrix);
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    CFoW::UpdateOccluderLocation(this: m_pFoW, nID: this->m_FoWHandle, vLocation: &this->m_Origin);
}

//------------------------------------------------------------------------------
// Address: 0x10133D10
// Name: protected: virtual void CMapOccluder::SetRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOccluder::SetRadius(CMapOccluder *this, float flRadius)
{
  CFoW *m_pFoW; // ecx

  CMapSphere::SetRadius(this, flRadius);
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    CFoW::UpdateOccluderSize(this: m_pFoW, nID: this->m_FoWHandle, flRadius: this->m_flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x10133D60
// Name: class CMapClass __near * CMapOccluder_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapSphere *__cdecl CMapOccluder_CreateObject()
{
  CMapSphere *v0; // eax
  CMapSphere *v1; // esi
  CFoW *m_pFoW; // ecx

  v0 = (CMapSphere *)operator new(nSize: 0x134u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapSphere::CMapSphere(this: v0);
  v1->__vftable = (CMapSphere_vtbl *)&CMapOccluder::`vftable';
  v1->m_szKeyName[0] = 0;
  v1->m_flRadius = 0.0;
  *(_WORD *)&v1->r = 255;
  v1->b = 0;
  CMapClass::SetVisible(this: v1, bVisible: true);
  *((_BYTE *)&v1->CMapClass + 180) |= 1u;
  v1[1].__vftable = (CMapSphere_vtbl *)-1;
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    v1[1].__vftable = (CMapSphere_vtbl *)CFoW::AddOccluder(this: m_pFoW, nPermanent: false);
  LOBYTE(v1[1].m_nObjectID) = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10133ED0
// Name: public: static class CMapClass __near * CMapOccluder::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSphere *__cdecl CMapOccluder::Create(CHelperInfo *pHelperInfo)
{
  CMapSphere *v1; // eax
  CMapSphere *v2; // esi
  CFoW *m_pFoW; // ecx
  char *v4; // eax
  int v5; // edx
  char v6; // cl
  char **m_pMemory; // edx
  char **v8; // ecx
  CMapSphere *chRed; // [esp+Ch] [ebp-18h]
  char chGreen; // [esp+10h] [ebp-14h]
  char chBlue; // [esp+14h] [ebp-10h]

  v1 = (CMapSphere *)operator new(nSize: 0x134u);
  v2 = v1;
  chRed = v1;
  if ( v1 != nullptr )
  {
    CMapSphere::CMapSphere(this: v1);
    v2->__vftable = (CMapSphere_vtbl *)&CMapOccluder::`vftable';
    v2->m_szKeyName[0] = 0;
    v2->m_flRadius = 0.0;
    *(_WORD *)&v2->r = 255;
    v2->b = 0;
    CMapClass::SetVisible(this: v2, bVisible: true);
    *((_BYTE *)&v2->CMapClass + 180) |= 1u;
    v2[1].__vftable = (CMapSphere_vtbl *)-1;
    m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
    if ( m_pFoW != nullptr )
      v2[1].__vftable = (CMapSphere_vtbl *)CFoW::AddOccluder(this: m_pFoW, nPermanent: false);
    LOBYTE(v2[1].m_nObjectID) = 0;
  }
  else
  {
    v2 = nullptr;
  }
  if ( v2 != nullptr )
  {
    if ( pHelperInfo->m_Parameters.m_Size > 0 && (v4 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) != nullptr )
    {
      v5 = v2->m_szKeyName - v4;
      do
      {
        v6 = *v4;
        v4[v5] = *v4;
        ++v4;
      }
      while ( v6 != 0 );
    }
    else
    {
      strcpy(v2->m_szKeyName, "radius");
    }
    LOBYTE(chRed) = -1;
    chGreen = -1;
    chBlue = -1;
    if ( pHelperInfo->m_Parameters.m_Size > 1 )
    {
      m_pMemory = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( m_pMemory[1] != nullptr )
        LOBYTE(chRed) = atoi(nptr: m_pMemory[1]);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 2 && *((_DWORD *)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 2) != 0 )
      chGreen = atoi(nptr: *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 2));
    if ( pHelperInfo->m_Parameters.m_Size > 3 )
    {
      v8 = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( v8[3] != nullptr )
        chBlue = atoi(nptr: v8[3]);
    }
    v2->SetRenderColor_2(this: v2, a2: (unsigned __int8)chRed, a3: chGreen, a4: chBlue);
  }
  return v2;
}
