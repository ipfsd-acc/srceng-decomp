// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fow/fow_viewer.cpp
// Functions: 6
// ============================================================

#include "fow\fow_viewer.h"

//------------------------------------------------------------------------------
// Address: 0x101FBDB0
// Name: public: CFoW_Viewer::CFoW_Viewer(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CFoW_Viewer *__thiscall CFoW_Viewer::CFoW_Viewer(CFoW_Viewer *this, int nID, unsigned int nViewerTeam)
{
  this->m_nID = nID;
  this->m_nViewerTeam = nViewerTeam;
  this->m_vLocation.x = 0.0;
  this->m_vLocation.y = 0.0;
  this->m_vLocation.z = 0.0;
  this->m_flRadius = 0.0;
  this->m_pVisibility = nullptr;
  this->m_pVisibilityRadius = nullptr;
  this->m_nRadiusUnits = 0;
  this->m_nAllocatedMemory = 0;
  *(_WORD *)&this->m_bDirty = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FBDF0
// Name: public: CFoW_Viewer::~CFoW_Viewer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_Viewer::~CFoW_Viewer(CFoW_Viewer *this)
{
  unsigned __int8 *m_pVisibility; // eax

  m_pVisibility = this->m_pVisibility;
  if ( m_pVisibility != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pVisibility);
    this->m_pVisibility = nullptr;
  }
  if ( this->m_pVisibilityRadius != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pVisibilityRadius);
    this->m_pVisibilityRadius = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBE40
// Name: public: void CFoW_Viewer::UpdateSize(class CFoW __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_Viewer::UpdateSize(CFoW_Viewer *this, CFoW *pFoW, float flRadius)
{
  unsigned __int8 *m_pVisibility; // eax
  float m_flRadius; // xmm1_4
  int m_nHorizontalGridSize; // edi
  int v7; // eax
  unsigned __int8 *v8; // eax
  float v9; // xmm1_4
  double v10; // xmm1_8
  int *v11; // eax

  m_pVisibility = this->m_pVisibility;
  this->m_flRadius = flRadius;
  if ( m_pVisibility != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pVisibility);
  if ( this->m_pVisibilityRadius != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pVisibilityRadius);
  m_flRadius = this->m_flRadius;
  this->m_nAllocatedMemory = 0;
  m_nHorizontalGridSize = pFoW->m_nHorizontalGridSize;
  v7 = (int)(float)((float)((float)((float)(m_flRadius * 2.0) + (float)m_nHorizontalGridSize) - 1.0)
                  / (float)m_nHorizontalGridSize)
     | 1;
  this->m_nGridUnits = v7;
  v8 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 * v7);
  v9 = this->m_flRadius;
  this->m_pVisibility = v8;
  this->m_nAllocatedMemory += this->m_nGridUnits * this->m_nGridUnits;
  v10 = (v9 * 6.283185307179586 + (double)m_nHorizontalGridSize - 1.0) / (double)m_nHorizontalGridSize;
  this->m_nRadiusUnits = (int)v10;
  v11 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (int)v10);
  this->m_nAllocatedMemory += 4 * this->m_nRadiusUnits;
  this->m_pVisibilityRadius = v11;
  this->m_pVisibilityTable = CFoW::FindRadiusTable(this: pFoW, flRadius);
  this->m_bDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x101FBF50
// Name: public: bool CFoW_Viewer::UpdateLocation(class CFoW __near *,class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoW_Viewer::UpdateLocation(
        CFoW_Viewer *this,
        CFoW *pFoW,
        const Vector *vLocation,
        Vector *pvOldLocation)
{
  __int64 v4; // xmm0_8
  float z; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float v10; // xmm0_4
  Vector vNewLocation; // [esp+0h] [ebp-Ch] BYREF

  v4 = *(_QWORD *)&vLocation->x;
  z = vLocation->z;
  this->m_vRealLocation.x = vLocation->x;
  this->m_vRealLocation.y = vLocation->y;
  vNewLocation.z = z;
  this->m_vRealLocation.z = vLocation->z;
  *(_QWORD *)&vNewLocation.x = v4;
  CFoW::CenterCoordToGrid(this: pFoW, vCoords: &vNewLocation);
  x = vNewLocation.x;
  y = vNewLocation.y;
  if ( vNewLocation.x == this->m_vLocation.x && vNewLocation.y == this->m_vLocation.y )
    return 0;
  this->m_bDirty = true;
  if ( pvOldLocation != nullptr )
    *pvOldLocation = this->m_vLocation;
  this->m_vLocation.x = x;
  v10 = vNewLocation.z;
  this->m_vLocation.y = y;
  this->m_vLocation.z = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FBFF0
// Name: private: void CFoW_Viewer::ResolveRadius(class CFoW __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_Viewer::ResolveRadius(CFoW_Viewer *this, CFoW *pFoW)
{
  int m_nHorizontalGridSize; // ebx
  int m_nGridUnits; // esi
  int v4; // eax
  unsigned __int8 *m_pVisibility; // edi
  int v6; // edx
  int nGridSize; // [esp+Ch] [ebp-14h]
  int v8; // [esp+10h] [ebp-10h]
  int x; // [esp+14h] [ebp-Ch]
  int *pVisibilityTable; // [esp+18h] [ebp-8h]
  unsigned __int8 *pVisibility; // [esp+1Ch] [ebp-4h]
  int xPos; // [esp+28h] [ebp+8h]

  m_nHorizontalGridSize = pFoW->m_nHorizontalGridSize;
  m_nGridUnits = this->m_nGridUnits;
  v4 = -(m_nHorizontalGridSize * (m_nGridUnits / 2));
  m_pVisibility = this->m_pVisibility;
  nGridSize = m_nHorizontalGridSize;
  pVisibility = m_pVisibility;
  pVisibilityTable = this->m_pVisibilityTable;
  x = 0;
  v8 = v4;
  xPos = v4;
  if ( m_nGridUnits > 0 )
  {
    while ( 1 )
    {
      v6 = 0;
      if ( m_nGridUnits > 0 )
      {
        do
        {
          if ( *pVisibilityTable == -1
            || (m_pVisibility = pVisibility,
                (float)this->m_pVisibilityRadius[*pVisibilityTable] < (float)(xPos * xPos + v4 * v4)) )
          {
            *m_pVisibility = 0;
          }
          else
          {
            *pVisibility = 32;
          }
          m_nHorizontalGridSize = nGridSize;
          ++pVisibilityTable;
          ++v6;
          ++m_pVisibility;
          v4 += nGridSize;
          pVisibility = m_pVisibility;
        }
        while ( v6 < this->m_nGridUnits );
      }
      m_nGridUnits = this->m_nGridUnits;
      xPos += m_nHorizontalGridSize;
      if ( ++x >= m_nGridUnits )
        break;
      v4 = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FC0B0
// Name: public: void CFoW_Viewer::CalcLocalizedVisibility(class CFoW __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_Viewer::CalcLocalizedVisibility(CFoW_Viewer *this, CFoW *pFoW)
{
  int v3; // eax
  float i; // xmm0_4
  int HorizontalSlice; // eax

  if ( this->m_bDirty )
  {
    v3 = 0;
    for ( i = this->m_flRadius * this->m_flRadius; v3 < this->m_nRadiusUnits; ++v3 )
      this->m_pVisibilityRadius[v3] = (int)i;
    CFoW::ObstructOccludersNearViewer(this: pFoW, nViewerID: this->m_nID);
    HorizontalSlice = CFoW::GetHorizontalSlice(this: pFoW, flZPos: this->m_vLocation.z);
    if ( HorizontalSlice != -1 )
      CFoW_HorizontalSlice::ObstructViewer(this: pFoW->m_pHorizontalSlices[HorizontalSlice], pFoW, pViewer: this);
    CFoW_Viewer::ResolveRadius(this, pFoW);
    this->m_bDirty = false;
  }
}
