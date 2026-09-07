// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/bvhbuilder.cpp
// Functions: 59
// ============================================================

#include "utils\vmap\bvh\bvhbuilder.h"

//------------------------------------------------------------------------------
// Address: 0x00403DC0
// Name: public: void Vector::Init(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector::Init(Vector *this, float ix, float iy, float iz)
{
  this->x = ix;
  this->y = iy;
  this->z = iz;
}

//------------------------------------------------------------------------------
// Address: 0x00403DF0
// Name: public: class Vector Vector::operator+(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator+(Vector *this, Vector *result, const Vector *v)
{
  result->x = v->x + this->x;
  result->y = v->y + this->y;
  result->z = v->z + this->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403E30
// Name: public: class Vector Vector::operator-(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator-(Vector *this, Vector *result, const Vector *v)
{
  result->x = this->x - v->x;
  result->y = this->y - v->y;
  result->z = this->z - v->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403E70
// Name: void VectorMin(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorMin(const Vector *a, const Vector *b, Vector *result)
{
  double x; // xmm0_8
  float v4; // xmm0_4
  double y; // xmm0_8
  float v6; // xmm0_4
  double z; // xmm0_8

  x = a->x;
  if ( x > b->x )
    x = b->x;
  v4 = x;
  result->x = v4;
  y = a->y;
  if ( y > b->y )
    y = b->y;
  v6 = y;
  result->y = v6;
  z = a->z;
  if ( z > b->z )
    z = b->z;
  result->z = z;
}

//------------------------------------------------------------------------------
// Address: 0x00403EF0
// Name: void VectorMax(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorMax(const Vector *a, const Vector *b, Vector *result)
{
  double x; // xmm0_8
  float v4; // xmm0_4
  double y; // xmm0_8
  float v6; // xmm0_4
  double z; // xmm0_8

  x = a->x;
  if ( x < b->x )
    x = b->x;
  v4 = x;
  result->x = v4;
  y = a->y;
  if ( y < b->y )
    y = b->y;
  v6 = y;
  result->y = v6;
  z = a->z;
  if ( z < b->z )
    z = b->z;
  result->z = z;
}

//------------------------------------------------------------------------------
// Address: 0x00403F70
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    ((void (__stdcall *)(bool))g_pDataModel->SetUndoEnabled)(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403FD0
// Name: void QuickDepthSort(int __near *,float __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl QuickDepthSort(int *indices, float *depths, int lo, int hi)
{
  int v4; // esi
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  int v9; // eax

  while ( 1 )
  {
    v4 = lo;
    v5 = hi;
    v6 = depths[(lo + hi) / 2];
    do
    {
      if ( depths[v4] > v6 )
      {
        do
          v7 = depths[++v4];
        while ( v7 > v6 );
      }
      for ( ; v6 > depths[v5]; --v5 )
        ;
      if ( v4 > v5 )
        break;
      v8 = depths[v4];
      depths[v4] = depths[v5];
      depths[v5] = v8;
      v9 = indices[v4];
      indices[v4] = indices[v5];
      indices[v5] = v9;
      ++v4;
      --v5;
    }
    while ( v4 <= v5 );
    if ( lo < v5 )
      QuickDepthSort(indices, depths, lo, hi: v5);
    if ( v4 >= hi )
      break;
    lo = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404070
// Name: class IVTFTexture __near * CompressTexture(struct IDirect3DDevice9 __near *,struct IDirect3DTexture9 __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__usercall CompressTexture@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        IDirect3DDevice9 *pd3dDevice,
        IDirect3DTexture9 *pInputTex,
        ImageFormat format)
{
  int v6; // eax
  int v7; // eax
  unsigned int Width; // edi
  signed int Height; // ebx
  IVTFTexture *VTFTexture; // esi
  char *pBits; // edi
  unsigned __int8 *v12; // ebx
  bool v13; // zf
  ID3DXBuffer *v14; // [esp-34h] [ebp-74h]
  _D3DFORMAT v15; // [esp-20h] [ebp-60h]
  _D3DSURFACE_DESC desc; // [esp+4h] [ebp-3Ch] BYREF
  _D3DLOCKED_RECT rect; // [esp+24h] [ebp-1Ch] BYREF
  int nResX; // [esp+2Ch] [ebp-14h]
  unsigned __int8 *pSrcData; // [esp+30h] [ebp-10h]
  int count; // [esp+34h] [ebp-Ch]
  IDirect3DTexture9 *pOutputTex; // [esp+38h] [ebp-8h] BYREF
  ID3DXBuffer *pMemBuffer; // [esp+3Ch] [ebp-4h] BYREF

  pMemBuffer = nullptr;
  if ( D3DXSaveTextureToFileInMemory(a1: &pMemBuffer, a2: D3DXIFF_DDS, a3: (int)pInputTex, a4: nullptr) >= 0 )
  {
    v15 = ImageLoader::ImageFormatToD3DFormat(format: IMAGE_FORMAT_BGRA8888);
    pOutputTex = nullptr;
    v14 = pMemBuffer;
    v6 = ((int (*)(void))pMemBuffer->GetBufferSize)();
    v7 = ((int (__stdcall *)(ID3DXBuffer *, int))pMemBuffer->GetBufferPointer)(a1: pMemBuffer, a2: v6);
    if ( (int)D3DXCreateTextureFromFileInMemoryEx(
                a1: pd3dDevice,
                a2: v7,
                a3: v14,
                a4: -1,
                a5: -1,
                a6: 1,
                a7: 0,
                a8: v15,
                a9: 2,
                a10: -1,
                a11: -1,
                a12: 0,
                a13: 0,
                a14: 0,
                a15: &pOutputTex) >= 0 )
    {
      ((void (__stdcall *)(ID3DXBuffer *, int, int))pMemBuffer->Release)(a1: pMemBuffer, a2, a3: a1);
      pMemBuffer = nullptr;
      pOutputTex->GetLevelDesc(this: pOutputTex, a2: 0, a3: &desc);
      Width = desc.Width;
      Height = desc.Height;
      nResX = desc.Width;
      VTFTexture = CreateVTFTexture();
      VTFTexture->Init(this: VTFTexture, a2: Width, a3: Height, a4: 1, a5: IMAGE_FORMAT_BGRA8888, a6: 0, a7: 1, a8: -1);
      pSrcData = VTFTexture->ImageData_3(this: VTFTexture);
      pOutputTex->LockRect(this: pOutputTex, a2: 0, a3: &rect, a4: nullptr, a5: 0);
      pBits = (char *)rect.pBits;
      if ( Height > 0 )
      {
        count = 4 * nResX;
        nResX = Height;
        do
        {
          v12 = pSrcData;
          _V_memcpy(dest: pSrcData, src: pBits, count);
          pBits += rect.Pitch;
          v13 = nResX-- == 1;
          pSrcData = &v12[count];
        }
        while ( !v13 );
      }
      ((void (__cdecl *)(IDirect3DTexture9 *, _DWORD))pOutputTex->UnlockRect)(a1: pOutputTex, a2: 0);
      pOutputTex->Release(this: pOutputTex);
      VTFTexture->GenerateMipmaps(this: VTFTexture);
      VTFTexture->ConvertImageFormat(this: VTFTexture, a2: format, a3: false, a4: false);
      return VTFTexture;
    }
    else
    {
      _Msg(a1: "Failed to compress texture");
      return nullptr;
    }
  }
  else
  {
    _Msg(a1: "Failed to save texture");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004041F0
// Name: bool CreateQuickD3DDevice(struct IDirect3D9 __near * __near *,struct IDirect3DDevice9 __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateQuickD3DDevice(IDirect3D9 **ppd3d9, IDirect3DDevice9 **ppd3dDevice)
{
  IDirect3D9 *v2; // eax
  IDirect3D9 *v3; // eax
  _D3DPRESENT_PARAMETERS_ pp; // [esp+8h] [ebp-38h] BYREF

  v2 = Direct3DCreate9(SDKVersion: 0x20u);
  *ppd3d9 = v2;
  if ( v2 == nullptr )
    return false;
  pp.BackBufferWidth = 320;
  pp.BackBufferHeight = 240;
  pp.BackBufferFormat = D3DFMT_X8R8G8B8;
  pp.BackBufferCount = 1;
  pp.MultiSampleType = D3DMULTISAMPLE_NONE;
  pp.MultiSampleQuality = 0;
  pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  pp.Windowed = 1;
  pp.hDeviceWindow = GetShellWindow();
  v3 = *ppd3d9;
  memset(&pp.Flags, 0, 12);
  pp.EnableAutoDepthStencil = 0;
  return v3->CreateDevice(this: v3, a2: 0, a3: D3DDEVTYPE_HAL, a4: nullptr, a5: 68u, a6: &pp, a7: ppd3dDevice) >= 0
      || (*ppd3d9)->CreateDevice(
           this: *ppd3d9,
           a2: 0,
           a3: D3DDEVTYPE_HAL,
           a4: nullptr,
           a5: 36u,
           a6: &pp,
           a7: ppd3dDevice) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404340
// Name: public: CDisableUndoScopeGuard::CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
CDisableUndoScopeGuard *__thiscall CDisableUndoScopeGuard::CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  *(_WORD *)&this->m_bReleased = 0;
  this->m_pNotify = nullptr;
  this->m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404380
// Name: private: bool CBVHNodeBuilder::DrawTexture(struct IDirect3DDevice9 __near *,struct TextureData_t __near *,class Vector2D,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBVHNodeBuilder::DrawTexture(
        CBVHNodeBuilder *this,
        IDirect3DDevice9 *pd3dDevice,
        TextureData_t *pTexture,
        Vector2D TextureSize,
        float flGutterSize)
{
  int v6; // eax
  float x; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  int i; // ebx
  int v17; // esi
  float v18; // xmm4_4
  float y; // xmm5_4
  IDirect3DDevice9_vtbl *v20; // edx
  HRESULT (__stdcall *DrawPrimitiveUP)(IDirect3DDevice9 *, _D3DPRIMITIVETYPE, unsigned int, const void *, unsigned int); // ecx
  HRESULT (__stdcall *v22)(IDirect3DDevice9 *, _D3DPRIMITIVETYPE, unsigned int, const void *, unsigned int); // ecx
  char *m_szFileName; // [esp-4h] [ebp-23Ch]
  char szPath[260]; // [esp+Ch] [ebp-22Ch] BYREF
  Vector2D vStep[8]; // [esp+110h] [ebp-128h]
  Vector2D vStart[8]; // [esp+150h] [ebp-E8h]
  float v27; // [esp+190h] [ebp-A8h]
  float v28; // [esp+198h] [ebp-A0h]
  float v29; // [esp+19Ch] [ebp-9Ch]
  float v30; // [esp+1A0h] [ebp-98h]
  float v31; // [esp+1A4h] [ebp-94h]
  TEXVERT ShiftedVerts[4]; // [esp+1A8h] [ebp-90h] BYREF
  float v33; // [esp+1E8h] [ebp-50h]
  float v34; // [esp+1ECh] [ebp-4Ch]
  TEXVERT Verts[4]; // [esp+1F0h] [ebp-48h]
  Vector2D vShift; // [esp+230h] [ebp-8h]
  float pd3dDevicea; // [esp+240h] [ebp+8h]
  float pTexturea; // [esp+244h] [ebp+Ch]

  if ( pTexture->m_pHWTexture == nullptr )
  {
    strstr(str1: (unsigned __int8 *)pTexture->m_szFileName, str2: ".dds");
    m_szFileName = pTexture->m_szFileName;
    if ( v6 != 0 )
    {
      V_snprintf(pDest: szPath, maxLen: 260, pFormat: "..\\%s", m_szFileName);
      D3DXCreateTextureFromFileA(a1: (int)pd3dDevice, lpWideCharStr: (LPCWCH)szPath, a3: (int)pTexture);
    }
    else
    {
      pTexture->m_pHWTexture = LoadBaseVTFIntoTexture(pd3dDevice, pszFileName: m_szFileName);
    }
    if ( pTexture->m_pHWTexture == nullptr )
      D3DXCreateTextureFromFileInMemory(a1: pd3dDevice, a2: g_pDefaultTextureDDS, a3: 11064, a4: pTexture);
  }
  pd3dDevice->SetTexture(this: pd3dDevice, a2: 0, a3: pTexture->m_pHWTexture);
  vShift.x = 1.0 / TextureSize.x;
  vShift.y = 1.0 / TextureSize.y;
  x = pTexture->m_vAtlasMin.x;
  v8 = (float)(1.0 / TextureSize.x) * flGutterSize;
  v9 = (float)(1.0 / TextureSize.y) * flGutterSize;
  if ( x == 0.0 && pTexture->m_vAtlasMin.y == 0.0 && pTexture->m_vAtlasMax.x == 0.0 && pTexture->m_vAtlasMax.y == 0.0 )
    return 0;
  v11 = pTexture->m_vMinUsedBounds.x;
  Verts[1].pos.y = pTexture->m_vAtlasMax.y - v9;
  v27 = x + v8;
  v12 = pTexture->m_vAtlasMin.y + v9;
  Verts[1].uv.x = v11;
  Verts[2].pos.x = pTexture->m_vAtlasMax.x - v8;
  Verts[2].pos.y = pTexture->m_vAtlasMin.y + v9;
  Verts[2].uv.x = pTexture->m_vMaxUsedBounds.x;
  v33 = pTexture->m_vAtlasMax.x - v8;
  v34 = pTexture->m_vAtlasMax.y - v9;
  v13 = pTexture->m_vAtlasMin.x;
  Verts[3].uv.x = pTexture->m_vMaxUsedBounds.x;
  v14 = 1.0 - v12;
  Verts[0].uv.y = 1.0 - pTexture->m_vMinUsedBounds.y;
  Verts[1].pos.y = 1.0 - Verts[1].pos.y;
  Verts[1].uv.y = 1.0 - pTexture->m_vMaxUsedBounds.y;
  Verts[2].pos.y = 1.0 - Verts[2].pos.y;
  Verts[2].uv.y = 1.0 - pTexture->m_vMinUsedBounds.y;
  Verts[3].pos.y = 1.0 - v34;
  Verts[3].uv.y = 1.0 - pTexture->m_vMaxUsedBounds.y;
  LODWORD(vStart[0].x) = LODWORD(v8) ^ _mask__NegFloat_;
  Verts[0].uv.x = v11;
  v15 = v13 + v8;
  LODWORD(vStart[0].y) = LODWORD(v9) ^ _mask__NegFloat_;
  vStart[1].y = (float)(1.0 / TextureSize.y) * flGutterSize;
  vStart[2].y = vStart[1].y;
  LODWORD(vStart[3].y) = LODWORD(v9) ^ _mask__NegFloat_;
  LODWORD(vStart[6].y) = LODWORD(v9) ^ _mask__NegFloat_;
  vStart[7].y = vStart[1].y;
  vStart[1].x = (float)(1.0 / TextureSize.x) * flGutterSize;
  vStart[3].x = vStart[1].x;
  vStart[5].x = vStart[1].x;
  Verts[1].pos.x = v15;
  Verts[0].pos.y = 1.0 - v12;
  LODWORD(vStart[2].x) = LODWORD(v8) ^ _mask__NegFloat_;
  LODWORD(vStart[4].x) = LODWORD(v8) ^ _mask__NegFloat_;
  vStart[4].y = 0.0;
  vStart[5].y = 0.0;
  vStart[6].x = 0.0;
  vStart[7].x = 0.0;
  vStep[0] = vShift;
  LODWORD(vStep[1].x) = LODWORD(vShift.x) ^ _mask__NegFloat_;
  LODWORD(vStep[3].x) = LODWORD(vShift.x) ^ _mask__NegFloat_;
  LODWORD(vStep[5].x) = LODWORD(vShift.x) ^ _mask__NegFloat_;
  LODWORD(vStep[1].y) = LODWORD(vShift.y) ^ _mask__NegFloat_;
  vStep[2].x = vShift.x;
  LODWORD(vStep[2].y) = LODWORD(vShift.y) ^ _mask__NegFloat_;
  vStep[3].y = vShift.y;
  vStep[4].x = vShift.x;
  vStep[4].y = 0.0;
  vStep[5].y = 0.0;
  vStep[6].x = 0.0;
  vStep[6].y = vShift.y;
  vStep[7].x = 0.0;
  LODWORD(vStep[7].y) = LODWORD(vShift.y) ^ _mask__NegFloat_;
  for ( i = 0; i < 8; ++i )
  {
    v17 = (int)flGutterSize;
    v18 = vStart[i].x;
    y = vStart[i].y;
    vShift.x = v18;
    vShift.y = y;
    if ( (int)flGutterSize > 0 )
    {
      pTexturea = 1.0 - Verts[0].uv.y;
      pd3dDevicea = 1.0 - Verts[1].uv.y;
      v29 = 1.0 - Verts[2].uv.y;
      v30 = 1.0 - Verts[3].uv.y;
      v31 = vStep[i].x;
      v28 = vStep[i].y;
      do
      {
        ShiftedVerts[0].uv.x = Verts[0].uv.x;
        v20 = pd3dDevice->__vftable;
        ShiftedVerts[0].pos.x = (float)((float)(v18 + v27) * 2.0) - 1.0;
        ShiftedVerts[0].uv.y = pTexturea;
        ShiftedVerts[1].uv.x = Verts[1].uv.x;
        DrawPrimitiveUP = v20->DrawPrimitiveUP;
        ShiftedVerts[1].pos.x = (float)((float)(v18 + v15) * 2.0) - 1.0;
        ShiftedVerts[1].uv.y = pd3dDevicea;
        ShiftedVerts[2].uv.x = Verts[2].uv.x;
        ShiftedVerts[0].pos.y = (float)((float)(y + v14) * 2.0) - 1.0;
        ShiftedVerts[1].pos.y = (float)((float)(y + Verts[1].pos.y) * 2.0) - 1.0;
        ShiftedVerts[2].pos.x = (float)((float)(v18 + Verts[2].pos.x) * 2.0) - 1.0;
        ShiftedVerts[2].uv.y = v29;
        ShiftedVerts[2].pos.y = (float)((float)(y + Verts[2].pos.y) * 2.0) - 1.0;
        ShiftedVerts[3].uv.x = Verts[3].uv.x;
        ShiftedVerts[3].pos.x = (float)((float)(v18 + v33) * 2.0) - 1.0;
        ShiftedVerts[3].pos.y = (float)((float)(Verts[3].pos.y + y) * 2.0) - 1.0;
        ShiftedVerts[3].uv.y = v30;
        DrawPrimitiveUP(this: pd3dDevice, a2: D3DPT_TRIANGLESTRIP, a3: 2u, a4: ShiftedVerts, a5: 16u);
        --v17;
        v18 = v31 + vShift.x;
        y = v28 + vShift.y;
        v15 = Verts[1].pos.x;
        v14 = Verts[0].pos.y;
        vShift.x = v31 + vShift.x;
        vShift.y = v28 + vShift.y;
      }
      while ( v17 != 0 );
    }
  }
  ShiftedVerts[0].uv.x = Verts[0].uv.x;
  ShiftedVerts[0].pos.x = (float)(v27 * 2.0) - 1.0;
  ShiftedVerts[0].uv.y = 1.0 - Verts[0].uv.y;
  ShiftedVerts[1].uv.x = Verts[1].uv.x;
  ShiftedVerts[1].pos.y = (float)(Verts[1].pos.y * 2.0) - 1.0;
  v22 = pd3dDevice->DrawPrimitiveUP;
  ShiftedVerts[1].uv.y = 1.0 - Verts[1].uv.y;
  ShiftedVerts[2].uv.x = Verts[2].uv.x;
  ShiftedVerts[2].pos.x = (float)(Verts[2].pos.x * 2.0) - 1.0;
  ShiftedVerts[2].pos.y = (float)(Verts[2].pos.y * 2.0) - 1.0;
  ShiftedVerts[2].uv.y = 1.0 - Verts[2].uv.y;
  ShiftedVerts[3].uv.x = Verts[3].uv.x;
  ShiftedVerts[3].pos.x = (float)(v33 * 2.0) - 1.0;
  ShiftedVerts[0].pos.y = (float)(v14 * 2.0) - 1.0;
  ShiftedVerts[1].pos.x = (float)(v15 * 2.0) - 1.0;
  ShiftedVerts[3].pos.y = (float)(Verts[3].pos.y * 2.0) - 1.0;
  ShiftedVerts[3].uv.y = 1.0 - Verts[3].uv.y;
  v22(this: pd3dDevice, a2: D3DPT_TRIANGLESTRIP, a3: 2u, a4: ShiftedVerts, a5: 16u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404B60
// Name: public: int CBVHNodeBuilder::GetNumTotalFaces(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBVHNodeBuilder::GetNumTotalFaces(CBVHNodeBuilder *this)
{
  int m_Size; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int *p_m_Size; // eax
  unsigned int v6; // edx
  int nFaces; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Meshes.m_Size;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  nFaces = 0;
  if ( m_Size >= 2 )
  {
    p_m_Size = &this->m_Meshes.m_Memory.m_pMemory[1].m_worldPerUV.m_Size;
    v6 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    v2 = 2 * v6;
    do
    {
      v3 += *(p_m_Size - 93);
      v4 += *p_m_Size;
      p_m_Size += 186;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v2 < this->m_Meshes.m_Size )
    nFaces = this->m_Meshes.m_Memory.m_pMemory[v2].m_worldPerUV.m_Size;
  return nFaces + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x00404BD0
// Name: public: int CBVHNodeBuilder::GetNumTotalIndices(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBVHNodeBuilder::GetNumTotalIndices(CBVHNodeBuilder *this)
{
  int m_Size; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int *p_m_nIndexCount; // eax
  unsigned int v6; // edx
  int nIndices; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Meshes.m_Size;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  nIndices = 0;
  if ( m_Size >= 2 )
  {
    p_m_nIndexCount = &this->m_Meshes.m_Memory.m_pMemory[1].m_mesh.m_nIndexCount;
    v6 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    v2 = 2 * v6;
    do
    {
      v3 += *(p_m_nIndexCount - 93);
      v4 += *p_m_nIndexCount;
      p_m_nIndexCount += 186;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v2 < this->m_Meshes.m_Size )
    nIndices = this->m_Meshes.m_Memory.m_pMemory[v2].m_mesh.m_nIndexCount;
  return nIndices + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x00404C40
// Name: public: int CBVHNodeBuilder::GetNumTotalVertexBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBVHNodeBuilder::GetNumTotalVertexBytes(CBVHNodeBuilder *this)
{
  CBVHNodeBuilder *v1; // eax
  int m_Size; // edx
  int v3; // ecx
  int v4; // esi
  int v5; // edi
  int v6; // ebx
  int *p_m_nVertexCount; // eax
  unsigned int v8; // edx
  int v9; // ecx
  CBVHNodeBuilder *v11; // [esp+Ch] [ebp-8h]

  v1 = this;
  m_Size = this->m_Meshes.m_Size;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v11 = v1;
  if ( m_Size >= 2 )
  {
    p_m_nVertexCount = &v1->m_Meshes.m_Memory.m_pMemory->m_mesh.m_nVertexCount;
    v8 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    v6 = 2 * v8;
    do
    {
      v4 += 4 * *p_m_nVertexCount * p_m_nVertexCount[1];
      v9 = p_m_nVertexCount[93] * p_m_nVertexCount[94];
      p_m_nVertexCount += 186;
      --v8;
      v5 += 4 * v9;
    }
    while ( v8 != 0 );
    v3 = 0;
    v1 = v11;
  }
  if ( v6 < v1->m_Meshes.m_Size )
    v3 = 4
       * v1->m_Meshes.m_Memory.m_pMemory[v6].m_mesh.m_nVertexCount
       * v1->m_Meshes.m_Memory.m_pMemory[v6].m_mesh.m_nVertexStrideFloats;
  return v3 + v5 + v4;
}

//------------------------------------------------------------------------------
// Address: 0x00404CD0
// Name: public: void CBVHNodeBuilder::InitTextureData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::InitTextureData(CBVHNodeBuilder *this)
{
  int m_Size; // edi
  int v3; // esi

  m_Size = this->m_Meshes.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      CBuilderMesh::InitTextureData(this: &this->m_Meshes.m_Memory.m_pMemory[v3++]);
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404D00
// Name: public: void CBVHNodeBuilder::ExpandMeshesToMaterialFormats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::ExpandMeshesToMaterialFormats(CBVHNodeBuilder *this)
{
  int m_Size; // eax
  int v2; // ebx
  CBuilderMesh *v3; // esi
  VertexElement_t v4; // eax
  int **v5; // ebx
  int *v6; // eax
  CBuilderMesh *v7; // esi
  CMeshVertexAttribute pAttributes; // [esp+Ch] [ebp-20h] BYREF
  CMeshVertexAttribute tangentAttrib; // [esp+14h] [ebp-18h] BYREF
  int m; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  CBVHNodeBuilder *v12; // [esp+24h] [ebp-8h]
  int v13; // [esp+28h] [ebp-4h]

  m_Size = this->m_Meshes.m_Size;
  v12 = this;
  if ( m_Size > 0 )
  {
    v2 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v3 = &this->m_Meshes.m_Memory.m_pMemory[v2];
      if ( v3->m_Material.m_Material.m_bNormalMap
        && CMesh::FindFirstAttributeOffset(this: &v3->m_mesh, nType: VERTEX_ELEMENT_TEXCOORD4D_7) == -1 )
      {
        tangentAttrib.m_nOffsetFloats = v3->m_mesh.m_nVertexStrideFloats;
        tangentAttrib.m_nType = VERTEX_ELEMENT_TEXCOORD4D_7;
        CMesh::AddAttributes(this: &v3->m_mesh, pAttributes: &tangentAttrib, nAttributeCount: 1);
        v3->m_Combo.m_nInputLayout = 1;
      }
      this = v12;
      ++v2;
    }
  }
  v4 = this->m_InstanceContainers.m_Size;
  if ( v4 > VERTEX_ELEMENT_POSITION )
  {
    i = 0;
    tangentAttrib.m_nType = v4;
    do
    {
      v5 = (int **)((char *)this->m_InstanceContainers.m_Memory.m_pMemory + i);
      m = 0;
      v6 = *v5;
      if ( **v5 > 0 )
      {
        v13 = 0;
        do
        {
          v7 = (CBuilderMesh *)(v13 + v6[1]);
          if ( v7->m_Material.m_Material.m_bNormalMap
            && CMesh::FindFirstAttributeOffset(this: &v7->m_mesh, nType: VERTEX_ELEMENT_TEXCOORD4D_7) == -1 )
          {
            pAttributes.m_nOffsetFloats = v7->m_mesh.m_nVertexStrideFloats;
            pAttributes.m_nType = VERTEX_ELEMENT_TEXCOORD4D_7;
            CMesh::AddAttributes(this: &v7->m_mesh, &pAttributes, nAttributeCount: 1);
            v7->m_Combo.m_nInputLayout = 1;
            CBuilderMesh::ComputeTangentFrame(this: v7);
          }
          v6 = *v5;
          v13 += 372;
          ++m;
        }
        while ( m < *v6 );
        this = v12;
      }
      i += 16;
      --tangentAttrib.m_nType;
    }
    while ( tangentAttrib.m_nType != VERTEX_ELEMENT_POSITION );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404E10
// Name: private: void CBVHNodeBuilder::ComputeTextureSizes(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::ComputeTextureSizes(
        CBVHNodeBuilder *this,
        float flMinDistToCamera,
        float flHorzFOV,
        float flHalfScreenWidth,
        float flGutterSize)
{
  CBuilderMesh *v6; // edi
  int m_MaxTextureSide; // ebx
  int v8; // eax
  int m; // [esp+1Ch] [ebp-8h]
  int v10; // [esp+20h] [ebp-4h]

  this->m_MaxTextureSide = 0;
  m = 0;
  if ( this->m_Meshes.m_Size > 0 )
  {
    v10 = 0;
    do
    {
      v6 = &this->m_Meshes.m_Memory.m_pMemory[v10];
      m_MaxTextureSide = this->m_MaxTextureSide;
      if ( m_MaxTextureSide <= CBuilderMesh::ComputeTextureSizes(
                                 this: v6,
                                 flMinDistToCamera,
                                 flHorzFOV,
                                 flHalfScreenWidth,
                                 flGutterSize) )
        v8 = CBuilderMesh::ComputeTextureSizes(this: v6, flMinDistToCamera, flHorzFOV, flHalfScreenWidth, flGutterSize);
      else
        v8 = m_MaxTextureSide;
      ++v10;
      this->m_MaxTextureSide = v8;
      ++m;
    }
    while ( m < this->m_Meshes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404ED0
// Name: private: struct AABB_t CBVHNodeBuilder::CalculateBounds(void)
// Source: json
//------------------------------------------------------------------------------
AABB_t *__thiscall CBVHNodeBuilder::CalculateBounds(CBVHNodeBuilder *this, AABB_t *result)
{
  BVHNodeHeader_t *m_pHeader; // eax
  BVHNodeHeader_t *v4; // eax
  int v5; // esi
  int m_Size; // ebx
  BVHNodeHeader_t *v7; // eax
  double x; // xmm0_8
  float v9; // xmm0_4
  double y; // xmm0_8
  float v11; // xmm0_4
  double z; // xmm0_8
  float v13; // xmm0_4
  BVHNodeHeader_t *v14; // eax
  double v15; // xmm0_8
  float v16; // xmm0_4
  double v17; // xmm0_8
  float v18; // xmm0_4
  double v19; // xmm0_8
  int v20; // eax
  InstanceContainer_t *v21; // esi
  InstanceGeometry_t *m_pInstanceGeometry; // eax
  bool v23; // zf
  int v24; // eax
  matrix3x4_t *v25; // eax
  Vector *v26; // esi
  int j; // ebx
  BVHNodeHeader_t *v28; // eax
  double v29; // xmm0_8
  float v30; // xmm0_4
  double v31; // xmm0_8
  float v32; // xmm0_4
  double v33; // xmm0_8
  float v34; // xmm0_4
  BVHNodeHeader_t *v35; // eax
  double v36; // xmm0_8
  float v37; // xmm0_4
  double v38; // xmm0_8
  float v39; // xmm0_4
  double v40; // xmm0_8
  matrix3x4_t xform; // [esp+0h] [ebp-D4h] BYREF
  Vector vCorners[8]; // [esp+30h] [ebp-A4h] BYREF
  AABB_t localBounds; // [esp+90h] [ebp-44h] BYREF
  InstanceContainer_t *inst; // [esp+A8h] [ebp-2Ch]
  Vector vOut; // [esp+ACh] [ebp-28h] BYREF
  float out; // [esp+B8h] [ebp-1Ch] BYREF
  float v48; // [esp+BCh] [ebp-18h]
  float v49; // [esp+C0h] [ebp-14h]
  int i; // [esp+C4h] [ebp-10h]
  int v51; // [esp+C8h] [ebp-Ch]
  unsigned int v52; // [esp+CCh] [ebp-8h]
  unsigned int v53; // [esp+D0h] [ebp-4h]

  m_pHeader = this->m_pHeader;
  m_pHeader->m_Bounds.m_vMinBounds.x = 3.4028235e38;
  m_pHeader->m_Bounds.m_vMinBounds.y = 3.4028235e38;
  m_pHeader->m_Bounds.m_vMinBounds.z = 3.4028235e38;
  v4 = this->m_pHeader;
  v4->m_Bounds.m_vMaxBounds.x = -3.4028235e38;
  v4->m_Bounds.m_vMaxBounds.y = -3.4028235e38;
  v4->m_Bounds.m_vMaxBounds.z = -3.4028235e38;
  if ( this->m_Meshes.m_Size > 0 )
  {
    v5 = 0;
    m_Size = this->m_Meshes.m_Size;
    do
    {
      CBuilderMesh::CalculateBounds(
        this: &this->m_Meshes.m_Memory.m_pMemory[v5],
        result: (AABB_t *)&vOut,
        nVertStart: 0,
        nVertCount: 0);
      v7 = this->m_pHeader;
      x = vOut.x;
      if ( vOut.x > (double)this->m_pHeader->m_Bounds.m_vMinBounds.x )
        x = this->m_pHeader->m_Bounds.m_vMinBounds.x;
      v9 = x;
      v7->m_Bounds.m_vMinBounds.x = v9;
      y = vOut.y;
      if ( vOut.y > (double)v7->m_Bounds.m_vMinBounds.y )
        y = v7->m_Bounds.m_vMinBounds.y;
      v11 = y;
      v7->m_Bounds.m_vMinBounds.y = v11;
      z = vOut.z;
      if ( vOut.z > (double)v7->m_Bounds.m_vMinBounds.z )
        z = v7->m_Bounds.m_vMinBounds.z;
      v13 = z;
      v7->m_Bounds.m_vMinBounds.z = v13;
      v14 = this->m_pHeader;
      v15 = out;
      if ( out < (double)this->m_pHeader->m_Bounds.m_vMaxBounds.x )
        v15 = this->m_pHeader->m_Bounds.m_vMaxBounds.x;
      v16 = v15;
      v14->m_Bounds.m_vMaxBounds.x = v16;
      v17 = v48;
      if ( v48 < (double)v14->m_Bounds.m_vMaxBounds.y )
        v17 = v14->m_Bounds.m_vMaxBounds.y;
      v18 = v17;
      v14->m_Bounds.m_vMaxBounds.y = v18;
      v19 = v49;
      if ( v49 < (double)v14->m_Bounds.m_vMaxBounds.z )
        v19 = v14->m_Bounds.m_vMaxBounds.z;
      ++v5;
      --m_Size;
      v14->m_Bounds.m_vMaxBounds.z = v19;
    }
    while ( m_Size != 0 );
  }
  v20 = this->m_InstanceContainers.m_Size;
  if ( v20 > 0 )
  {
    v52 = 0;
    for ( i = v20; i != 0; --i )
    {
      v21 = &this->m_InstanceContainers.m_Memory.m_pMemory[v52 / 0x10];
      m_pInstanceGeometry = v21->m_pInstanceGeometry;
      v23 = v21->m_pInstanceGeometry->m_nMeshes == 0;
      inst = v21;
      if ( !v23 )
      {
        CBuilderMesh::CalculateBounds(
          this: m_pInstanceGeometry->m_pMeshes,
          result: &localBounds,
          nVertStart: 0,
          nVertCount: 0);
        vCorners[0] = localBounds.m_vMinBounds;
        vCorners[1].x = localBounds.m_vMinBounds.x;
        vCorners[2].x = localBounds.m_vMinBounds.x;
        vCorners[3].x = localBounds.m_vMinBounds.x;
        vCorners[1].y = localBounds.m_vMinBounds.y;
        vCorners[1].z = localBounds.m_vMaxBounds.z;
        vCorners[2].y = localBounds.m_vMaxBounds.y;
        vCorners[2].z = localBounds.m_vMinBounds.z;
        vCorners[3].y = localBounds.m_vMaxBounds.y;
        vCorners[3].z = localBounds.m_vMaxBounds.z;
        vCorners[4].x = localBounds.m_vMaxBounds.x;
        vCorners[4].y = localBounds.m_vMinBounds.y;
        vCorners[4].z = localBounds.m_vMinBounds.z;
        vCorners[5].x = localBounds.m_vMaxBounds.x;
        vCorners[5].y = localBounds.m_vMinBounds.y;
        vCorners[5].z = localBounds.m_vMaxBounds.z;
        vCorners[6].x = localBounds.m_vMaxBounds.x;
        vCorners[6].y = localBounds.m_vMaxBounds.y;
        vCorners[6].z = localBounds.m_vMinBounds.z;
        vCorners[7] = localBounds.m_vMaxBounds;
        v24 = v21->m_pTransforms->m_Size;
        if ( v24 > 0 )
        {
          v53 = 0;
          v51 = v24;
          while ( 1 )
          {
            v25 = &v21->m_pTransforms->m_Memory.m_pMemory[v53 / 0x30];
            v26 = vCorners;
            xform = *v25;
            for ( j = 8; j != 0; --j )
            {
              VectorTransform(in1: &v26->x, in2: &xform, &out);
              v28 = this->m_pHeader;
              v29 = out;
              if ( out > (double)this->m_pHeader->m_Bounds.m_vMinBounds.x )
                v29 = this->m_pHeader->m_Bounds.m_vMinBounds.x;
              v30 = v29;
              v28->m_Bounds.m_vMinBounds.x = v30;
              v31 = v48;
              if ( v48 > (double)v28->m_Bounds.m_vMinBounds.y )
                v31 = v28->m_Bounds.m_vMinBounds.y;
              v32 = v31;
              v28->m_Bounds.m_vMinBounds.y = v32;
              v33 = v49;
              if ( v49 > (double)v28->m_Bounds.m_vMinBounds.z )
                v33 = v28->m_Bounds.m_vMinBounds.z;
              v34 = v33;
              v28->m_Bounds.m_vMinBounds.z = v34;
              v35 = this->m_pHeader;
              v36 = out;
              if ( out < (double)this->m_pHeader->m_Bounds.m_vMaxBounds.x )
                v36 = this->m_pHeader->m_Bounds.m_vMaxBounds.x;
              v37 = v36;
              v35->m_Bounds.m_vMaxBounds.x = v37;
              v38 = v48;
              if ( v48 < (double)v35->m_Bounds.m_vMaxBounds.y )
                v38 = v35->m_Bounds.m_vMaxBounds.y;
              v39 = v38;
              v35->m_Bounds.m_vMaxBounds.y = v39;
              v40 = v49;
              if ( v49 < (double)v35->m_Bounds.m_vMaxBounds.z )
                v40 = v35->m_Bounds.m_vMaxBounds.z;
              ++v26;
              v35->m_Bounds.m_vMaxBounds.z = v40;
            }
            v53 += 48;
            if ( --v51 == 0 )
              break;
            v21 = inst;
          }
        }
      }
      v52 += 16;
    }
  }
  *result = this->m_pHeader->m_Bounds;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004052C0
// Name: private: struct AABB_t CBVHNodeBuilder::CalculateBoundsForInstances(class CBuilderMesh __near *,class CUtlVector<struct matrix3x4_t,class CUtlMemory<struct matrix3x4_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
AABB_t *__thiscall CBVHNodeBuilder::CalculateBoundsForInstances(
        CBVHNodeBuilder *this,
        AABB_t *result,
        CBuilderMesh *pInstMesh,
        CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *pTransforms)
{
  int m_Size; // eax
  Vector *v6; // edi
  int i; // ebx
  float x; // xmm4_4
  double v9; // xmm0_8
  float y; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  double v13; // xmm0_8
  double v14; // xmm1_8
  float z; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  double v18; // xmm0_8
  double v19; // xmm1_8
  float v20; // xmm0_4
  double v21; // xmm0_8
  float v22; // xmm0_4
  double v23; // xmm0_8
  float v24; // xmm0_4
  double v25; // xmm0_8
  matrix3x4_t xform; // [esp+0h] [ebp-B4h] BYREF
  Vector vCorners[8]; // [esp+30h] [ebp-84h] BYREF
  AABB_t localBounds; // [esp+90h] [ebp-24h] BYREF
  Vector vOut; // [esp+A8h] [ebp-Ch] BYREF
  AABB_t *v31; // [esp+BCh] [ebp+8h]
  CBuilderMesh *pInstMesha; // [esp+C0h] [ebp+Ch]

  result->m_vMinBounds.x = 3.4028235e38;
  result->m_vMinBounds.y = 3.4028235e38;
  result->m_vMinBounds.z = 3.4028235e38;
  result->m_vMaxBounds.x = -3.4028235e38;
  result->m_vMaxBounds.y = -3.4028235e38;
  result->m_vMaxBounds.z = -3.4028235e38;
  CBuilderMesh::CalculateBounds(this: pInstMesh, result: &localBounds, nVertStart: 0, nVertCount: 0);
  m_Size = pTransforms->m_Size;
  vCorners[0] = localBounds.m_vMinBounds;
  vCorners[1].x = localBounds.m_vMinBounds.x;
  vCorners[2].x = localBounds.m_vMinBounds.x;
  vCorners[3].x = localBounds.m_vMinBounds.x;
  vCorners[1].y = localBounds.m_vMinBounds.y;
  vCorners[1].z = localBounds.m_vMaxBounds.z;
  vCorners[2].y = localBounds.m_vMaxBounds.y;
  vCorners[2].z = localBounds.m_vMinBounds.z;
  vCorners[3].y = localBounds.m_vMaxBounds.y;
  vCorners[3].z = localBounds.m_vMaxBounds.z;
  vCorners[4].x = localBounds.m_vMaxBounds.x;
  vCorners[4].y = localBounds.m_vMinBounds.y;
  vCorners[4].z = localBounds.m_vMinBounds.z;
  vCorners[5].x = localBounds.m_vMaxBounds.x;
  vCorners[5].y = localBounds.m_vMinBounds.y;
  vCorners[5].z = localBounds.m_vMaxBounds.z;
  vCorners[6].x = localBounds.m_vMaxBounds.x;
  vCorners[6].y = localBounds.m_vMaxBounds.y;
  vCorners[6].z = localBounds.m_vMinBounds.z;
  vCorners[7] = localBounds.m_vMaxBounds;
  if ( m_Size > 0 )
  {
    v31 = nullptr;
    for ( pInstMesha = (CBuilderMesh *)m_Size; pInstMesha != nullptr; pInstMesha = (CBuilderMesh *)((char *)pInstMesha
                                                                                                  - 1) )
    {
      v6 = vCorners;
      xform = *(matrix3x4_t *)((char *)&v31->m_vMinBounds.x + (unsigned int)pTransforms->m_Memory.m_pMemory);
      for ( i = 8; i != 0; --i )
      {
        VectorTransform(in1: &v6->x, in2: &xform, out: &vOut.x);
        x = vOut.x;
        v9 = vOut.x;
        if ( vOut.x > (double)result->m_vMinBounds.x )
          v9 = result->m_vMinBounds.x;
        y = vOut.y;
        v11 = result->m_vMinBounds.y;
        v12 = v9;
        result->m_vMinBounds.x = v12;
        v13 = y;
        v14 = v11;
        if ( y > v14 )
          v13 = v14;
        z = vOut.z;
        v16 = result->m_vMinBounds.z;
        v17 = v13;
        result->m_vMinBounds.y = v17;
        v18 = z;
        v19 = v16;
        if ( z > v19 )
          v18 = v19;
        v20 = v18;
        result->m_vMinBounds.z = v20;
        v21 = x;
        if ( x < (double)result->m_vMaxBounds.x )
          v21 = result->m_vMaxBounds.x;
        v22 = v21;
        result->m_vMaxBounds.x = v22;
        v23 = y;
        if ( y < (double)result->m_vMaxBounds.y )
          v23 = result->m_vMaxBounds.y;
        v24 = v23;
        result->m_vMaxBounds.y = v24;
        v25 = z;
        if ( z < (double)result->m_vMaxBounds.z )
          v25 = result->m_vMaxBounds.z;
        ++v6;
        result->m_vMaxBounds.z = v25;
      }
      v31 += 2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405530
// Name: private: void CBVHNodeBuilder::CalculateNumVBsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::CalculateNumVBsNeeded(CBVHNodeBuilder *this)
{
  int *m_pVBsOfType; // edi
  int v3; // ecx
  int m_Size; // edx

  m_pVBsOfType = this->m_pVBsOfType;
  this->m_nVBsNeeded = 0;
  _V_memset(dest: this->m_pVBsOfType, fill: 0, count: 16);
  _V_memset(dest: this->m_pVBIndex, fill: 0, count: 16);
  if ( this->m_Meshes.m_Size > 0 )
  {
    v3 = 0;
    m_Size = this->m_Meshes.m_Size;
    do
    {
      ++this->m_pVBsOfType[this->m_Meshes.m_Memory.m_pMemory[v3++].m_Combo.m_nInputLayout];
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  if ( *m_pVBsOfType > 0 )
    this->m_pVBIndex[0] = this->m_nVBsNeeded++;
  if ( this->m_pVBsOfType[1] > 0 )
    this->m_pVBIndex[1] = this->m_nVBsNeeded++;
  if ( this->m_pVBsOfType[2] > 0 )
    this->m_pVBIndex[2] = this->m_nVBsNeeded++;
  if ( this->m_pVBsOfType[3] > 0 )
    this->m_pVBIndex[3] = this->m_nVBsNeeded++;
}

//------------------------------------------------------------------------------
// Address: 0x00405600
// Name: public: unsigned __int64 CBVHNodeBuilder::CalculateMaxAtomicResourceSize(class CResourceDictionaryBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBVHNodeBuilder::CalculateMaxAtomicResourceSize(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary)
{
  int *m_pMemory; // edi
  int m_Size; // ebx
  unsigned __int64 v4; // rax
  char *v5; // ecx
  unsigned int v6; // esi
  unsigned int v7; // ecx
  CResourceDictionaryBuilder *Dictionarya; // [esp+10h] [ebp+8h]

  if ( this->m_ResourceEntryList.m_Size <= 0 )
  {
    LODWORD(v4) = 0;
  }
  else
  {
    m_pMemory = this->m_ResourceEntryList.m_Memory.m_pMemory;
    Dictionarya = (CResourceDictionaryBuilder *)Dictionary->m_EntryList.m_Memory.m_pMemory;
    m_Size = this->m_ResourceEntryList.m_Size;
    v4 = 0;
    do
    {
      v5 = (char *)Dictionarya + 104 * *m_pMemory;
      v6 = *((_DWORD *)v5 + 4);
      v7 = *((_DWORD *)v5 + 5);
      if ( v4 <= __PAIR64__(v7, v6) )
        v4 = __PAIR64__(v7, v6);
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00405670
// Name: private: int CBVHNodeBuilder::CalculateTotalUniqueTextures(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBVHNodeBuilder::CalculateTotalUniqueTextures(CBVHNodeBuilder *this)
{
  int m_Size; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int *p_m_nTextures; // eax
  unsigned int v6; // edx
  int nTextures; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Meshes.m_Size;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  nTextures = 0;
  if ( m_Size >= 2 )
  {
    p_m_nTextures = &this->m_Meshes.m_Memory.m_pMemory[1].m_Material.m_nTextures;
    v6 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    v2 = 2 * v6;
    do
    {
      v3 += *(p_m_nTextures - 93);
      v4 += *p_m_nTextures;
      p_m_nTextures += 186;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v2 < this->m_Meshes.m_Size )
    nTextures = this->m_Meshes.m_Memory.m_pMemory[v2].m_Material.m_nTextures;
  return nTextures + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x004056E0
// Name: private: void CBVHNodeBuilder::PerNodeOps(float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::PerNodeOps(
        CBVHNodeBuilder *this,
        float flMinDistToCamera,
        float flHorzFOV,
        float flHalfScreenWidth,
        float flGutterSize,
        bool bWrapInAtlas)
{
  int v7; // ebx
  CBuilderMesh *v8; // esi
  AABB_t result; // [esp+18h] [ebp-1Ch] BYREF
  unsigned int v10; // [esp+30h] [ebp-4h]

  if ( flMinDistToCamera < 0.000001 )
    flMinDistToCamera = 0.000001;
  v7 = 0;
  if ( this->m_Meshes.m_Size > 0 )
  {
    v10 = 0;
    do
    {
      v8 = &this->m_Meshes.m_Memory.m_pMemory[v10 / 0x174];
      CBuilderMesh::RationalizeUVs(this: v8);
      CBuilderMesh::CalculateFaceData(this: v8);
      CBuilderMesh::ComputeTangentSpaces(this: v8);
      CBuilderMesh::ZeroTextureSizes(this: v8);
      CBuilderMesh::ComputeTextureBounds(this: v8, bWrapInAtlas);
      v10 += 372;
      ++v7;
    }
    while ( v7 < this->m_Meshes.m_Size );
  }
  CBVHNodeBuilder::ComputeTextureSizes(this, flMinDistToCamera, flHorzFOV, flHalfScreenWidth, flGutterSize);
  CBVHNodeBuilder::CalculateBounds(this, &result);
}

//------------------------------------------------------------------------------
// Address: 0x00405790
// Name: public: unsigned __int64 CBVHNodeBuilder::Serialize(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBVHNodeBuilder::Serialize(CBVHNodeBuilder *this, _iobuf *fp)
{
  BVHNodeHeader_t *m_pHeader; // eax
  CBVHNodeBuilder *m_pParentNode; // eax
  BVHNodeHeader_t *v5; // eax
  unsigned int v6; // edi
  unsigned __int64 v7; // kr00_8
  unsigned int v8; // ebx
  BVHNodeHeader_t *v9; // ecx
  BVHNodeHeader_t *v10; // edx
  const void **v11; // edi
  BVHNodeHeader_t *v12; // ecx
  unsigned int v13; // et0
  BVHNodeHeader_t *v14; // edx
  BVHNodeHeader_t *v15; // ecx
  unsigned int nBytes_4; // [esp+4h] [ebp-Ch]
  int nChildID; // [esp+8h] [ebp-8h] BYREF
  int c; // [esp+Ch] [ebp-4h]

  this->m_pHeader->m_nResources = this->m_ResourceEntryList.m_Size;
  this->m_pHeader->m_nDrawCalls = this->m_BuilderDrawCalls.m_Size;
  this->m_pHeader->m_Origin.m_vTile.x = 0;
  this->m_pHeader->m_Origin.m_vTile.y = 0;
  this->m_pHeader->m_Origin.m_vTile.z = 0;
  m_pHeader = this->m_pHeader;
  m_pHeader->m_Origin.m_vLocal.x = 0.0;
  m_pHeader->m_Origin.m_vLocal.y = 0.0;
  m_pHeader->m_Origin.m_vLocal.z = 0.0;
  m_pParentNode = this->m_pParentNode;
  if ( m_pParentNode != nullptr )
    this->m_pHeader->m_nParent = m_pParentNode->m_pHeader->m_nID;
  else
    this->m_pHeader->m_nParent = -1;
  fwrite(buffer: this->m_pHeader, size: 0x4Cu, count: 1u, stream: fp);
  fwrite(
    buffer: this->m_ResourceEntryList.m_Memory.m_pMemory,
    size: 4 * this->m_pHeader->m_nResources,
    count: 1u,
    stream: fp);
  v5 = this->m_pHeader;
  v7 = (unsigned int)(4 * this->m_pHeader->m_nResources) + 76LL;
  v6 = HIDWORD(v7);
  nBytes_4 = HIDWORD(v7);
  v8 = v7;
  nChildID = 0;
  if ( v5->m_nDrawCalls > 0 )
  {
    c = 0;
    do
    {
      fwrite(buffer: (char *)this->m_BuilderDrawCalls.m_Memory.m_pMemory + c, size: 0x48u, count: 1u, stream: fp);
      v9 = this->m_pHeader;
      v6 = (__PAIR64__(v6, v8) + 72) >> 32;
      v8 += 72;
      c += 80;
      ++nChildID;
    }
    while ( nChildID < v9->m_nDrawCalls );
    nBytes_4 = v6;
  }
  v10 = this->m_pHeader;
  nChildID = 0;
  if ( v10->m_nDrawCalls > 0 )
  {
    c = 0;
    do
    {
      v11 = (const void **)((char *)this->m_BuilderDrawCalls.m_Memory.m_pMemory + c);
      fwrite(buffer: v11[16], size: 16 * (_DWORD)v11[8], count: 1u, stream: fp);
      v12 = this->m_pHeader;
      v13 = ((unsigned int)(16 * (_DWORD)v11[8]) + __PAIR64__(nBytes_4, v8)) >> 32;
      v8 += 16 * (_DWORD)v11[8];
      nBytes_4 = v13;
      c += 80;
      ++nChildID;
    }
    while ( nChildID < v12->m_nDrawCalls );
  }
  v14 = this->m_pHeader;
  c = 0;
  if ( v14->m_nChildren > 0 )
  {
    do
    {
      nChildID = this->m_ChildNodeArray.m_Memory.m_pMemory[c]->m_pHeader->m_nID;
      fwrite(buffer: &nChildID, size: 4u, count: 1u, stream: fp);
      v15 = this->m_pHeader;
      v8 += 4;
      ++c;
    }
    while ( c < v15->m_nChildren );
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00405970
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004059A0
// Name: public: void CBVHNodeBuilder::SaveToDmeWorldNode(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::SaveToDmeWorldNode(CBVHNodeBuilder *this, const char *pMapName)
{
  DmFileId_t v3; // edi
  DmElementHandle_t (__thiscall *CreateElement_2)(IDataModel *, CUtlSymbolLarge, const char *, DmFileId_t, const UniqueId_t *); // eax
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  bool v8; // al
  DmElementHandle_t v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmAttribute *Attribute; // eax
  int i; // edi
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  float x; // xmm1_4
  CDmAttribute *v18; // ecx
  float y; // xmm1_4
  CDmAttribute *v20; // ecx
  float z; // xmm1_4
  CDmAttribute *m_fileId; // ecx
  int m_Size; // eax
  InstanceContainer_t *v24; // eax
  int v25; // ecx
  InstanceGeometry_t *m_pInstanceGeometry; // edx
  Vector4D *v27; // esi
  DmElementHandle_t v28; // eax
  CDmElement *v29; // eax
  CDmElement *v30; // edi
  CDmAttribute *v31; // ecx
  CDmAttribute *v32; // ecx
  CDmAttribute *v33; // ecx
  const char *v34; // esi
  int v35; // [esp-4h] [ebp-74h]
  Vector4D v36; // [esp+Ch] [ebp-64h] BYREF
  Vector4D v37; // [esp+1Ch] [ebp-54h] BYREF
  Vector4D v38; // [esp+2Ch] [ebp-44h] BYREF
  CDisableUndoScopeGuard guard; // [esp+3Ch] [ebp-34h]
  char *m_pDmeNodeName; // [esp+44h] [ebp-2Ch]
  DmElementHandle_t src; // [esp+48h] [ebp-28h] BYREF
  CUtlSymbolLarge v42; // [esp+4Ch] [ebp-24h] BYREF
  const char *m_pDMXFileName; // [esp+50h] [ebp-20h]
  InstanceContainer_t *container; // [esp+54h] [ebp-1Ch]
  int value; // [esp+58h] [ebp-18h] BYREF
  int v46; // [esp+5Ch] [ebp-14h]
  DmFileId_t dmFileId; // [esp+60h] [ebp-10h]
  CDmElement *v48; // [esp+64h] [ebp-Ch]
  int nChildren; // [esp+68h] [ebp-8h] BYREF
  unsigned int v50; // [esp+6Ch] [ebp-4h]
  const char *pMapNamea; // [esp+78h] [ebp+8h]

  guard.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v35 = g_nWorldNodeCounter++;
  m_pDmeNodeName = this->m_pDmeNodeName;
  V_snprintf(pDest: this->m_pDmeNodeName, maxLen: 260, pFormat: "maps/%s/worldnode%04d.wnd", pMapName, v35);
  v3 = g_pDataModel->FindOrCreateFileId(this: g_pDataModel, a2: this->m_pDmeNodeName);
  CreateElement_2 = g_pDataModel->CreateElement_2;
  dmFileId = v3;
  v5 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: "root",
         a4: v3,
         a5: nullptr);
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  v7 = v6;
  if ( v6 == nullptr || (v8 = v6->IsA(this: v6, a2: CDmElement::m_classType), v48 = v7, !v8) )
    v48 = nullptr;
  v9 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeWorldNode::m_classType.u.m_Id,
         a3: "worldnode",
         a4: v3,
         a5: nullptr);
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmeWorldNode::m_classType) )
  {
    pMapNamea = (const char *)v11;
    nChildren = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v11);
  }
  else
  {
    pMapNamea = nullptr;
    v11 = nullptr;
    nChildren = -1;
  }
  Attribute = CDmElement::FindAttribute(this: v48, pAttributeName: "worldnode");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v48, pAttributeName: "worldnode", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (const DmElementHandle_t *)&nChildren);
  }
  CDmAttribute::SetValue<int>(this: *(CDmAttribute **)v11[1].m_Id.m_Value, value: &this->m_pHeader->m_nID);
  CDmAttribute::SetValue<int>(this: *(CDmAttribute **)&v11[1].m_Id.m_Value[8], value: &this->m_pHeader->m_Flags);
  CDmAttribute::SetValue<int>(this: (CDmAttribute *)v11[1].m_Name.m_Storage.u.m_Id, value: &this->m_pHeader->m_nParent);
  CDmAttribute::SetValue<Vector>(
    this: *((CDmAttribute **)&v11[1].m_ref + 2),
    value: &this->m_pHeader->m_Origin.m_vLocal);
  CDmAttribute::SetValue<Vector>(
    this: (CDmAttribute *)v11[1].m_Type.u.m_Id,
    value: &this->m_pHeader->m_Bounds.m_vMinBounds);
  CDmAttribute::SetValue<Vector>(this: (CDmAttribute *)v11[2].__vftable, value: &this->m_pHeader->m_Bounds.m_vMaxBounds);
  CDmAttribute::SetValue<float>(
    this: *(CDmAttribute **)&v11[2].m_Id.m_Value[4],
    value: &this->m_pHeader->m_flMinimumDistance);
  nChildren = this->m_ChildNodeArray.m_Size;
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
    this: (CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v11[2].m_Id.m_Value[8],
    num: nChildren);
  for ( i = 0; i < nChildren; ++i )
  {
    value = this->m_ChildNodeArray.m_Memory.m_pMemory[i]->m_pHeader->m_nID;
    CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
      this: (CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v11[2].m_Id.m_Value[8],
      i,
      &value);
  }
  if ( this->m_pDMXName[0] != 0 )
  {
    v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeSceneObject::m_classType.u.m_Id,
            a3: "sceneobject",
            a4: dmFileId,
            a5: nullptr);
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
    v16 = v15;
    if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmeSceneObject::m_classType) )
      v16 = nullptr;
    x = this->m_pHeader->m_Origin.m_vLocal.x;
    v18 = *(CDmAttribute **)&v16[1].m_Id.m_Value[12];
    v38.x = 1.0;
    v38.y = 0.0;
    v38.z = 0.0;
    v38.w = x;
    CDmAttribute::SetValue<Vector4D>(this: v18, value: &v38);
    y = this->m_pHeader->m_Origin.m_vLocal.y;
    v20 = *((CDmAttribute **)&v16[1].m_ref + 2);
    v38.x = 0.0;
    v38.y = 1.0;
    v38.z = 0.0;
    v38.w = y;
    CDmAttribute::SetValue<Vector4D>(this: v20, value: &v38);
    z = this->m_pHeader->m_Origin.m_vLocal.z;
    m_fileId = (CDmAttribute *)v16[1].m_fileId;
    v38.x = 0.0;
    v38.y = 0.0;
    v38.z = 1.0;
    v38.w = z;
    CDmAttribute::SetValue<Vector4D>(this: m_fileId, value: &v38);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&value, a3: this->m_pDMXName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: *((CDmAttribute **)&v16[1] + 16), (const CUtlSymbolLarge *)&value);
    value = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v16);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)((char *)&v11[2].m_ref + 8),
      src: (const DmElementHandle_t *)&value);
  }
  if ( (this->m_pHeader->m_Flags & 0x11) == 0 )
  {
    m_Size = this->m_InstanceContainers.m_Size;
    if ( m_Size > 0 )
    {
      nChildren = 0;
      for ( value = m_Size; value != 0; --value )
      {
        v24 = (InstanceContainer_t *)((char *)this->m_InstanceContainers.m_Memory.m_pMemory + nChildren);
        v25 = v24->m_pTransforms->m_Size;
        m_pInstanceGeometry = v24->m_pInstanceGeometry;
        container = v24;
        if ( v25 > 0 )
        {
          m_pDMXFileName = m_pInstanceGeometry->m_pDMXFileName;
          v50 = 0;
          v46 = v25;
          while ( 1 )
          {
            v27 = (Vector4D *)&v24->m_pTransforms->m_Memory.m_pMemory[v50 / 0x30];
            v28 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                    a1: g_pDataModel,
                    a2: (CUtlSymbolLarge)CDmeSceneObject::m_classType.u.m_Id,
                    a3: "sceneobject",
                    a4: dmFileId,
                    a5: nullptr);
            v29 = g_pDataModel->GetElement(this: g_pDataModel, a2: v28);
            v30 = v29;
            if ( v29 == nullptr || !v29->IsA(this: v29, a2: CDmeSceneObject::m_classType) )
              v30 = nullptr;
            v38.x = v27->x;
            v38.y = v27->y;
            v38.z = v27->z;
            v31 = *(CDmAttribute **)&v30[1].m_Id.m_Value[12];
            v38.w = v27->w;
            CDmAttribute::SetValue<Vector4D>(this: v31, value: &v38);
            v32 = *((CDmAttribute **)&v30[1].m_ref + 2);
            v37 = v27[1];
            CDmAttribute::SetValue<Vector4D>(this: v32, value: &v37);
            v33 = (CDmAttribute *)v30[1].m_fileId;
            v36 = v27[2];
            CDmAttribute::SetValue<Vector4D>(this: v33, value: &v36);
            g_pDataModel->GetSymbol(this: g_pDataModel, result: &v42, a3: m_pDMXFileName);
            CDmAttribute::SetValue<CUtlSymbolLarge>(this: *((CDmAttribute **)&v30[1] + 16), value: &v42);
            src = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v30);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)(pMapNamea + 172),
              &src);
            v50 += 48;
            if ( --v46 == 0 )
              break;
            v24 = container;
          }
        }
        nChildren += 16;
      }
    }
  }
  v34 = m_pDmeNodeName;
  if ( !g_pDataModel->SaveToFile(
          this: g_pDataModel,
          a2: m_pDmeNodeName,
          a3: nullptr,
          a4: nullptr,
          a5: "worldnode",
          a6: v48) )
    _Warning(a1: "SaveMeshesToDMX: SaveToFile \"%s\" failed!\n", v34);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
}

//------------------------------------------------------------------------------
// Address: 0x004062C0
// Name: public: void CBVHNodeBuilder::AddChild(class CBVHNodeBuilder __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::AddChild(CBVHNodeBuilder *this, CBVHNodeBuilder *pChild)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CBVHNodeBuilder **m_pMemory; // ecx
  int v6; // eax
  CBVHNodeBuilder **v7; // eax

  m_nAllocationCount = this->m_ChildNodeArray.m_Memory.m_nAllocationCount;
  m_Size = this->m_ChildNodeArray.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_ChildNodeArray,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ChildNodeArray.m_Size;
  m_pMemory = this->m_ChildNodeArray.m_Memory.m_pMemory;
  v6 = this->m_ChildNodeArray.m_Size - m_Size - 1;
  this->m_ChildNodeArray.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_ChildNodeArray.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pChild;
  ++this->m_pHeader->m_nChildren;
  pChild->m_pParentNode = this;
}

//------------------------------------------------------------------------------
// Address: 0x00406340
// Name: public: CBVHNodeBuilder::CBVHNodeBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CBVHNodeBuilder *__thiscall CBVHNodeBuilder::CBVHNodeBuilder(CBVHNodeBuilder *this)
{
  BVHNodeHeader_t *v2; // eax

  this->m_InstanceContainers.m_Memory.m_pMemory = nullptr;
  this->m_InstanceContainers.m_Memory.m_nAllocationCount = 0;
  this->m_InstanceContainers.m_Memory.m_nGrowSize = 0;
  this->m_InstanceContainers.m_Size = 0;
  this->m_InstanceContainers.m_pElements = nullptr;
  this->m_Meshes.m_Memory.m_pMemory = nullptr;
  this->m_Meshes.m_Memory.m_nAllocationCount = 0;
  this->m_Meshes.m_Memory.m_nGrowSize = 0;
  this->m_Meshes.m_Size = 0;
  this->m_Meshes.m_pElements = nullptr;
  this->m_nAtlasTables = 0;
  this->m_pAtlasTable = nullptr;
  this->m_ResourceEntryList.m_Memory.m_pMemory = nullptr;
  this->m_ResourceEntryList.m_Memory.m_nAllocationCount = 0;
  this->m_ResourceEntryList.m_Memory.m_nGrowSize = 0;
  this->m_ResourceEntryList.m_Size = 0;
  this->m_ResourceEntryList.m_pElements = nullptr;
  this->m_BuilderDrawCalls.m_Memory.m_pMemory = nullptr;
  this->m_BuilderDrawCalls.m_Memory.m_nAllocationCount = 0;
  this->m_BuilderDrawCalls.m_Memory.m_nGrowSize = 0;
  this->m_BuilderDrawCalls.m_Size = 0;
  this->m_BuilderDrawCalls.m_pElements = nullptr;
  this->m_TexScales.m_Memory.m_pMemory = nullptr;
  this->m_TexScales.m_Memory.m_nAllocationCount = 0;
  this->m_TexScales.m_Memory.m_nGrowSize = 0;
  this->m_TexScales.m_Size = 0;
  this->m_TexScales.m_pElements = nullptr;
  this->m_pParentNode = nullptr;
  this->m_ChildNodeArray.m_Memory.m_pMemory = nullptr;
  this->m_ChildNodeArray.m_Memory.m_nAllocationCount = 0;
  this->m_ChildNodeArray.m_Memory.m_nGrowSize = 0;
  this->m_ChildNodeArray.m_Size = 0;
  this->m_ChildNodeArray.m_pElements = nullptr;
  this->m_pointLights.m_Memory.m_pMemory = nullptr;
  this->m_pointLights.m_Memory.m_nAllocationCount = 0;
  this->m_pointLights.m_Memory.m_nGrowSize = 0;
  this->m_pointLights.m_Size = 0;
  this->m_pointLights.m_pElements = nullptr;
  this->m_hemiLights.m_Memory.m_pMemory = nullptr;
  this->m_hemiLights.m_Memory.m_nAllocationCount = 0;
  this->m_hemiLights.m_Memory.m_nGrowSize = 0;
  this->m_hemiLights.m_Size = 0;
  this->m_hemiLights.m_pElements = nullptr;
  this->m_spotLights.m_Memory.m_pMemory = nullptr;
  this->m_spotLights.m_Memory.m_nAllocationCount = 0;
  this->m_spotLights.m_Memory.m_nGrowSize = 0;
  this->m_spotLights.m_Size = 0;
  this->m_spotLights.m_pElements = nullptr;
  v2 = (BVHNodeHeader_t *)MemAlloc_Alloc(nSize: 0x4Cu);
  this->m_pHeader = v2;
  _V_memset(dest: v2, fill: 0, count: 76);
  _V_memset(dest: this->m_pDMXName, fill: 0, count: 260);
  _V_memset(dest: this->m_pDmeNodeName, fill: 0, count: 260);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406450
// Name: public: CBVHNodeBuilder::~CBVHNodeBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::~CBVHNodeBuilder(CBVHNodeBuilder *this)
{
  if ( this->m_pHeader != nullptr )
  {
    free(pMem: this->m_pHeader);
    this->m_pHeader = nullptr;
  }
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_spotLights);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_hemiLights);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_pointLights);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ChildNodeArray);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_TexScales);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_BuilderDrawCalls);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ResourceEntryList);
  CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int>>::Purge(this: &this->m_Meshes);
  if ( this->m_Meshes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Meshes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Meshes.m_Memory.m_pMemory);
      this->m_Meshes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Meshes.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_InstanceContainers);
}

//------------------------------------------------------------------------------
// Address: 0x004064F0
// Name: public: void CBVHNodeBuilder::AddMesh(int,int,float __near *,unsigned int __near *,int,struct BuilderMaterial_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::AddMesh(
        CBVHNodeBuilder *this,
        int *nVertexLayout,
        int nIndicesPerFace,
        float *pVertices,
        unsigned int *pIndices,
        int nIndices,
        BuilderMaterial_t *material,
        bool bFlipWinding)
{
  unsigned int StrideForInputLayout; // ebx
  CMeshVertexAttribute *AttributesForInputLayout; // eax
  unsigned int v11; // esi
  int j; // edi
  CBVHNodeBuilder *v13; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBuilderMesh *m_pMemory; // ecx
  int v17; // eax
  CBuilderMesh *v18; // ecx
  int AttributeCountForInputLayout; // [esp-4h] [ebp-188h]
  CBuilderMesh Mesh; // [esp+Ch] [ebp-178h] BYREF
  CBVHNodeBuilder *v21; // [esp+180h] [ebp-4h]
  int *pWinding; // [esp+18Ch] [ebp+8h]
  int i; // [esp+1A4h] [ebp+20h]

  v21 = this;
  StrideForInputLayout = GetStrideForInputLayout(nLayout: (int)nVertexLayout);
  CBuilderMesh::CBuilderMesh(this: &Mesh);
  Mesh.m_Combo.m_nInputLayout = (int)nVertexLayout;
  Mesh.m_Combo.m_nIndicesPerFace = nIndicesPerFace;
  BuilderMaterial_t::operator=(this: &Mesh.m_Material, __that: material);
  CUtlString::operator=(this: &Mesh.m_mesh.m_materialName, src: &material->m_originalMaterialName);
  pWinding = spWinding1;
  if ( bFlipWinding )
    pWinding = spWinding2;
  AttributeCountForInputLayout = GetAttributeCountForInputLayout(nLayout: (int)nVertexLayout);
  AttributesForInputLayout = GetAttributesForInputLayout(nLayout: (int)nVertexLayout);
  CMesh::AllocateMesh(
    this: &Mesh.m_mesh,
    nVertexCount: nIndices,
    nIndexCount: nIndices,
    nVertexStride: StrideForInputLayout >> 2,
    pAttributes: AttributesForInputLayout,
    nAtrributeCount: AttributeCountForInputLayout);
  v11 = 0;
  for ( i = 0; i < nIndices; i += 3 )
  {
    for ( j = 0; j < 3; ++j )
    {
      _V_memcpy(
        dest: &Mesh.m_mesh.m_pVerts[v11 * Mesh.m_mesh.m_nVertexStrideFloats],
        src: (char *)pVertices + StrideForInputLayout * pIndices[i + pWinding[j]],
        count: StrideForInputLayout);
      Mesh.m_mesh.m_pIndices[v11] = v11;
      ++v11;
    }
  }
  if ( Mesh.m_mesh.m_nIndexCount > 0 )
  {
    v13 = v21;
    m_Size = v21->m_Meshes.m_Size;
    m_nAllocationCount = v21->m_Meshes.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CBuilderMesh,int>::Grow(this: &v21->m_Meshes.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++v13->m_Meshes.m_Size;
    m_pMemory = v13->m_Meshes.m_Memory.m_pMemory;
    v17 = v13->m_Meshes.m_Size - m_Size - 1;
    v13->m_Meshes.m_pElements = m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 372 * v17);
    v18 = &v13->m_Meshes.m_Memory.m_pMemory[m_Size];
    if ( v18 != nullptr )
      CBuilderMesh::CBuilderMesh(this: v18, Other: &Mesh);
  }
  CBuilderMesh::~CBuilderMesh(this: &Mesh);
}

//------------------------------------------------------------------------------
// Address: 0x00406670
// Name: public: void CBVHNodeBuilder::AddInstances(struct InstanceGeometry_t __near *,int,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::AddInstances(
        CBVHNodeBuilder *this,
        InstanceGeometry_t *pInstanceGeometry,
        int nTransforms,
        matrix3x4_t *pTransforms)
{
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *v5; // eax
  int m_Size; // [esp-Ch] [ebp-24h]
  int v7; // [esp-8h] [ebp-20h]
  InstanceContainer_t Container; // [esp+8h] [ebp-10h] BYREF

  Container.m_pInstanceGeometry = pInstanceGeometry;
  v5 = (CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v5 != nullptr )
  {
    v5->m_Memory.m_pMemory = nullptr;
    v5->m_Memory.m_nAllocationCount = 0;
    v5->m_Memory.m_nGrowSize = 0;
    v5->m_Size = 0;
    v5->m_pElements = nullptr;
  }
  else
  {
    v5 = nullptr;
  }
  m_Size = v5->m_Size;
  Container.m_pTransforms = v5;
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
    this: v5,
    elem: m_Size,
    num: nTransforms,
    pToInsert: pTransforms);
  v7 = this->m_InstanceContainers.m_Size;
  Container.m_nPerDrawTransformSets = 0;
  Container.m_pPerDrawTransforms = nullptr;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
    this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)&this->m_InstanceContainers,
    elem: v7,
    src: (const Quaternion *)&Container);
}

//------------------------------------------------------------------------------
// Address: 0x004066E0
// Name: public: void CBVHNodeBuilder::AddInstancesAndClip(struct InstanceGeometry_t __near *,int,struct matrix3x4_t __near *,class Vector4D)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::AddInstancesAndClip(
        CBVHNodeBuilder *this,
        InstanceGeometry_t *pInstanceGeometry,
        int nTransforms,
        matrix3x4_t *pTransforms,
        Vector4D vClipPlane)
{
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *v5; // eax
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *v6; // ebx
  int v7; // edi
  float *v8; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  InstanceContainer_t *m_pMemory; // ecx
  int v12; // eax
  InstanceContainer_t *v13; // edi
  __int64 Container; // [esp+Ch] [ebp-14h]
  __int64 Container_8; // [esp+14h] [ebp-Ch]

  LODWORD(Container) = pInstanceGeometry;
  v5 = (CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v5 != nullptr )
  {
    v5->m_Memory.m_pMemory = nullptr;
    v5->m_Memory.m_nAllocationCount = 0;
    v5->m_Memory.m_nGrowSize = 0;
    v5->m_Size = 0;
    v5->m_pElements = nullptr;
    v6 = v5;
  }
  else
  {
    v6 = nullptr;
  }
  v7 = nTransforms;
  HIDWORD(Container) = v6;
  if ( nTransforms > 0 )
  {
    v8 = &pTransforms->m_flMatVal[1][3];
    do
    {
      if ( (float)((float)((float)((float)(vClipPlane.y * *v8) + (float)(vClipPlane.x * *(v8 - 4)))
                         + (float)(vClipPlane.z * v8[4]))
                 + vClipPlane.w) < 0.0 )
        CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertBefore(
          this: v6,
          elem: v6->m_Size,
          src: (const matrix3x4_t *)(v8 - 7));
      v8 += 12;
      --v7;
    }
    while ( v7 != 0 );
  }
  if ( v6->m_Size >= 1 )
  {
    m_Size = this->m_InstanceContainers.m_Size;
    m_nAllocationCount = this->m_InstanceContainers.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&this->m_InstanceContainers,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_InstanceContainers.m_Size;
    m_pMemory = this->m_InstanceContainers.m_Memory.m_pMemory;
    v12 = this->m_InstanceContainers.m_Size - m_Size - 1;
    this->m_InstanceContainers.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v12);
    v13 = &this->m_InstanceContainers.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
    {
      *(_QWORD *)&v13->m_pInstanceGeometry = Container;
      *(_QWORD *)&v13->m_nPerDrawTransformSets = Container_8;
    }
  }
  else
  {
    CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)v6);
    free(pMem: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406810
// Name: public: void CBVHNodeBuilder::AbsorbGrandchildren(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::AbsorbGrandchildren(CBVHNodeBuilder *this, int nAndFlags)
{
  CBVHNodeBuilder *v2; // edx
  int v3; // edi
  int v4; // eax
  CBVHNodeBuilder *v5; // ebx
  BVHNodeHeader_t *m_pHeader; // eax
  int m_Size; // ecx
  int v8; // eax
  CBVHNodeBuilder **m_pMemory; // esi
  int v10; // ecx
  int v11; // esi
  CBVHNodeBuilder **v12; // ebx
  CBVHNodeBuilder **v13; // esi
  int v14; // eax
  CBVHNodeBuilder *v15; // ebx
  CUtlMemory<S3RGBA,int> *p_m_ChildNodeArray; // esi
  S3RGBA *v17; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v19; // ecx
  int v20; // eax
  int *v21; // edi
  int v22; // esi
  int v23; // edi
  CUtlVector<CBVHNodeBuilder *,CUtlMemory<CBVHNodeBuilder *,int> > RemoveList; // [esp+Ch] [ebp-24h] BYREF
  CBVHNodeBuilder *pChild; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  int c; // [esp+28h] [ebp-8h]
  CBVHNodeBuilder *v28; // [esp+2Ch] [ebp-4h]
  int nAndFlagsa; // [esp+38h] [ebp+8h]

  v2 = this;
  v3 = 0;
  v4 = this->m_pHeader->m_nChildren - 1;
  v28 = this;
  memset(&RemoveList, 0, sizeof(RemoveList));
  for ( c = v4; c >= 0; --c )
  {
    v5 = v2->m_ChildNodeArray.m_Memory.m_pMemory[v4];
    m_pHeader = v5->m_pHeader;
    pChild = v5;
    if ( (nAndFlags & m_pHeader->m_Flags) != 0 )
    {
      m_Size = v2->m_ChildNodeArray.m_Size;
      v8 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = v2->m_ChildNodeArray.m_Memory.m_pMemory;
        while ( *m_pMemory != v5 )
        {
          ++v8;
          ++m_pMemory;
          if ( v8 >= m_Size )
            goto LABEL_12;
        }
        if ( v8 != -1 )
        {
          v10 = m_Size - v8 - 1;
          if ( v10 > 0 )
          {
            _V_memmove(
              dest: &v2->m_ChildNodeArray.m_Memory.m_pMemory[v8],
              src: &v2->m_ChildNodeArray.m_Memory.m_pMemory[v8 + 1],
              count: 4 * v10);
            v2 = v28;
            v3 = RemoveList.m_Size;
          }
          --v2->m_ChildNodeArray.m_Size;
        }
      }
LABEL_12:
      --v2->m_pHeader->m_nChildren;
      v11 = v3;
      if ( v3 + 1 > RemoveList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&RemoveList,
          num: v3 - RemoveList.m_Memory.m_nAllocationCount + 1);
        v3 = RemoveList.m_Size;
        v2 = v28;
      }
      v12 = RemoveList.m_Memory.m_pMemory;
      RemoveList.m_Size = ++v3;
      RemoveList.m_pElements = RemoveList.m_Memory.m_pMemory;
      if ( v3 - v11 - 1 > 0 )
      {
        _V_memmove(
          dest: &RemoveList.m_Memory.m_pMemory[v11 + 1],
          src: &RemoveList.m_Memory.m_pMemory[v11],
          count: 4 * (v3 - v11 - 1));
        v2 = v28;
      }
      v13 = &v12[v11];
      if ( v13 != nullptr )
        *v13 = pChild;
    }
    v4 = c - 1;
  }
  v14 = 0;
  for ( i = 0; v14 < v3; i = v14 )
  {
    v15 = RemoveList.m_Memory.m_pMemory[v14];
    nAndFlagsa = 0;
    if ( v15->m_pHeader->m_nChildren > 0 )
    {
      p_m_ChildNodeArray = (CUtlMemory<S3RGBA,int> *)&v2->m_ChildNodeArray;
      do
      {
        v17 = p_m_ChildNodeArray[1].m_pMemory;
        m_nAllocationCount = p_m_ChildNodeArray->m_nAllocationCount;
        c = (int)v15->m_ChildNodeArray.m_Memory.m_pMemory[nAndFlagsa];
        if ( (int)&v17->g > m_nAllocationCount )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_ChildNodeArray, num: (int)(&v17->g - m_nAllocationCount));
          v2 = v28;
        }
        ++p_m_ChildNodeArray[1].m_pMemory;
        v19 = p_m_ChildNodeArray->m_pMemory;
        v20 = (char *)p_m_ChildNodeArray[1].m_pMemory - (char *)v17 - 1;
        p_m_ChildNodeArray[1].m_nAllocationCount = (int)p_m_ChildNodeArray->m_pMemory;
        if ( v20 > 0 )
        {
          _V_memmove(dest: &v19[(_DWORD)v17 + 1], src: &v19[(_DWORD)v17], count: 4 * v20);
          v2 = v28;
        }
        v21 = (int *)&p_m_ChildNodeArray->m_pMemory[(_DWORD)v17];
        if ( v21 != nullptr )
          *v21 = c;
        ++v2->m_pHeader->m_nChildren;
        *(_DWORD *)(c + 116) = v2;
        ++nAndFlagsa;
      }
      while ( nAndFlagsa < v15->m_pHeader->m_nChildren );
      v3 = RemoveList.m_Size;
    }
    v22 = 0;
    if ( v15->m_Meshes.m_Size > 0 )
    {
      v23 = 0;
      do
      {
        CMesh::FreeAllMemory(this: &v15->m_Meshes.m_Memory.m_pMemory[v23].m_mesh);
        ++v22;
        ++v23;
      }
      while ( v22 < v15->m_Meshes.m_Size );
      v2 = v28;
      v3 = RemoveList.m_Size;
    }
    v14 = i + 1;
  }
  if ( RemoveList.m_Memory.m_nGrowSize >= 0 && RemoveList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: RemoveList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406A30
// Name: public: void CBVHNodeBuilder::CleanupMeshes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::CleanupMeshes(CBVHNodeBuilder *this)
{
  int *m_pMemory; // edi
  int m_Size; // edx
  char *v4; // eax
  int v5; // ecx
  char *v6; // eax
  int i; // esi
  int v8; // esi
  int *v9; // eax
  int v10; // eax
  int v11; // edi
  bool v12; // sf
  CUtlVector<int,CUtlMemory<int,int> > DeleteList; // [esp+Ch] [ebp-24h] BYREF
  int nMeshes; // [esp+20h] [ebp-10h]
  int d; // [esp+24h] [ebp-Ch]
  int m; // [esp+28h] [ebp-8h]
  bool bDeleteMesh; // [esp+2Fh] [ebp-1h]

  m_pMemory = nullptr;
  m_Size = 0;
  nMeshes = this->m_Meshes.m_Size;
  memset(&DeleteList, 0, sizeof(DeleteList));
  m = 0;
  if ( nMeshes > 0 )
  {
    d = 0;
    do
    {
      v4 = (char *)this->m_Meshes.m_Memory.m_pMemory + d;
      bDeleteMesh = false;
      v5 = *((_DWORD *)v4 + 65);
      if ( v5 > 0 )
      {
        v6 = v4 + 264;
        for ( i = v5; i != 0; --i )
        {
          if ( *(_DWORD *)(*(_DWORD *)v6 + 4) == 0 )
            bDeleteMesh = true;
          v6 += 4;
        }
        if ( bDeleteMesh )
        {
          v8 = m_Size;
          if ( m_Size + 1 > DeleteList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&DeleteList,
              num: m_Size - DeleteList.m_Memory.m_nAllocationCount + 1);
            m_pMemory = DeleteList.m_Memory.m_pMemory;
            m_Size = DeleteList.m_Size;
          }
          DeleteList.m_Size = ++m_Size;
          DeleteList.m_pElements = m_pMemory;
          if ( m_Size - v8 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * (m_Size - v8 - 1));
            m_Size = DeleteList.m_Size;
          }
          v9 = &m_pMemory[v8];
          if ( v9 != nullptr )
            *v9 = m;
        }
      }
      d += 372;
      ++m;
    }
    while ( m < nMeshes );
  }
  v10 = m_Size - 1;
  d = m_Size - 1;
  if ( m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      v11 = m_pMemory[v10];
      CBuilderMesh::~CBuilderMesh(this: &this->m_Meshes.m_Memory.m_pMemory[v11]);
      if ( this->m_Meshes.m_Size - v11 - 1 > 0 )
        _V_memmove(
          dest: &this->m_Meshes.m_Memory.m_pMemory[v11],
          src: &this->m_Meshes.m_Memory.m_pMemory[v11 + 1],
          count: 372 * (this->m_Meshes.m_Size - v11 - 1));
      --this->m_Meshes.m_Size;
      v12 = --d < 0;
      m_pMemory = DeleteList.m_Memory.m_pMemory;
      if ( v12 )
        break;
      v10 = d;
    }
  }
  if ( DeleteList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406B80
// Name: private: void CBVHNodeBuilder::SplitNode(class CBVHNodeBuilder __near *,class CBVHNodeBuilder __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::SplitNode(
        CBVHNodeBuilder *this,
        CBVHNodeBuilder *pChild1,
        CBVHNodeBuilder *pChild2,
        bool bSplitInHalf)
{
  float z; // xmm3_4
  CBVHNodeBuilder *v5; // edi
  int NumTotalFaces; // esi
  float *p_m_nID; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float w; // xmm0_4
  float y; // xmm4_4
  float v13; // xmm2_4
  int *v14; // ebx
  int v15; // eax
  char *v16; // esi
  int v17; // ecx
  float *v18; // edi
  int *v19; // ecx
  int v20; // ebx
  int v21; // edx
  float v22; // xmm0_4
  float v23; // xmm1_4
  int v24; // ebx
  bool v25; // zf
  char *v26; // ecx
  int *v27; // edx
  int v28; // edi
  int v29; // ebx
  CBuilderMesh *v30; // eax
  int m_nIndicesPerFace; // esi
  int m_nInputLayout; // edi
  BuilderMaterial_t *p_m_Material; // ebx
  TextureData_t *v34; // eax
  int m_nTextures; // edx
  TextureData_t *v36; // ecx
  TextureData_t *v37; // eax
  TextureData_t *v38; // edx
  TextureData_t *v39; // ecx
  TextureData_t *v40; // eax
  TextureData_t *v41; // edx
  TextureData_t *v42; // ecx
  TextureData_t *v43; // eax
  TextureData_t *v44; // edx
  TextureData_t *v45; // ecx
  TextureData_t *v46; // eax
  TextureData_t *v47; // edx
  TextureData_t *v48; // ecx
  TextureData_t *v49; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBuilderMesh *m_pMemory; // ecx
  int v53; // eax
  int v54; // edi
  CBuilderMesh *v55; // ecx
  int v56; // esi
  int v57; // edi
  TextureData_t *v58; // eax
  TextureData_t *v59; // edx
  TextureData_t *v60; // ecx
  TextureData_t *v61; // eax
  TextureData_t *v62; // edx
  TextureData_t *v63; // ecx
  TextureData_t *v64; // eax
  TextureData_t *v65; // edx
  TextureData_t *v66; // ecx
  TextureData_t *v67; // eax
  TextureData_t *v68; // edx
  TextureData_t *v69; // ecx
  TextureData_t *v70; // eax
  TextureData_t *v71; // edx
  TextureData_t *v72; // ecx
  TextureData_t *v73; // edx
  int v74; // edi
  int v75; // eax
  CBuilderMesh *v76; // ecx
  int v77; // eax
  int v78; // edi
  CBuilderMesh *v79; // ecx
  CBuilderMesh *v80; // ebx
  unsigned int v81; // edi
  int v82; // edi
  int v83; // edi
  int v84; // ebx
  int v85; // ebx
  InstanceContainer_t *v86; // esi
  CBuilderMesh v87; // [esp+0h] [ebp-330h] BYREF
  CBuilderMesh Other; // [esp+174h] [ebp-1BCh] BYREF
  Vector4D vNegSplitPlane; // [esp+2E8h] [ebp-48h]
  int nFaces; // [esp+2F8h] [ebp-38h]
  char *v91; // [esp+2FCh] [ebp-34h]
  int v92; // [esp+300h] [ebp-30h]
  float *pDistances; // [esp+304h] [ebp-2Ch]
  unsigned int v94; // [esp+308h] [ebp-28h]
  int nTotalFaces; // [esp+30Ch] [ebp-24h]
  CBuilderMesh *v96; // [esp+310h] [ebp-20h]
  CBuilderMesh *mesh; // [esp+314h] [ebp-1Ch]
  int *pIndices; // [esp+318h] [ebp-18h]
  CBVHNodeBuilder *v99; // [esp+31Ch] [ebp-14h]
  Vector4D vSplitPlane; // [esp+320h] [ebp-10h] BYREF
  int f; // [esp+340h] [ebp+10h]
  int fa; // [esp+340h] [ebp+10h]
  int fb; // [esp+340h] [ebp+10h]

  z = 0.0;
  v5 = this;
  v99 = this;
  memset(&vSplitPlane, 0, sizeof(vSplitPlane));
  NumTotalFaces = CBVHNodeBuilder::GetNumTotalFaces(this);
  nTotalFaces = NumTotalFaces;
  if ( NumTotalFaces != 0 )
  {
    p_m_nID = (float *)&v5->m_pHeader->m_nID;
    v8 = v5->m_pHeader->m_Bounds.m_vMaxBounds.x - v5->m_pHeader->m_Bounds.m_vMinBounds.x;
    v9 = v5->m_pHeader->m_Bounds.m_vMaxBounds.y - v5->m_pHeader->m_Bounds.m_vMinBounds.y;
    v10 = v5->m_pHeader->m_Bounds.m_vMaxBounds.z - v5->m_pHeader->m_Bounds.m_vMinBounds.z;
    if ( v8 <= v9 || v8 <= v10 )
    {
      if ( v9 <= v8 || v9 <= v10 )
      {
        v13 = (float)(v10 * 0.5) + p_m_nID[11];
        vSplitPlane.x = 0.0;
        y = 0.0;
        z = 1.0;
        w = -v13;
      }
      else
      {
        y = 1.0;
        w = -(float)((float)(v9 * 0.5) + p_m_nID[10]);
        vSplitPlane.x = 0.0;
      }
    }
    else
    {
      w = -(float)((float)(v8 * 0.5) + p_m_nID[9]);
      vSplitPlane.x = 1.0;
      y = 0.0;
    }
    vSplitPlane.y = y;
    vSplitPlane.z = z;
    vSplitPlane.w = w;
    if ( !bSplitInHalf )
    {
      pDistances = (float *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)NumTotalFaces >> 30 != 0 ? -1 : 4 * NumTotalFaces);
      v14 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)NumTotalFaces >> 30 != 0 ? -1 : 4 * NumTotalFaces);
      v15 = 0;
      pIndices = v14;
      mesh = nullptr;
      if ( v5->m_Meshes.m_Size > 0 )
      {
        v96 = nullptr;
        do
        {
          v16 = (char *)v96 + (unsigned int)v5->m_Meshes.m_Memory.m_pMemory;
          v17 = *((_DWORD *)v16 + 22);
          nFaces = v17;
          f = 0;
          if ( v17 >= 4 )
          {
            v92 = 0;
            v18 = &pDistances[v15 + 3];
            v91 = (char *)((char *)pDistances - (char *)v14);
            v94 = ((unsigned int)(nFaces - 4) >> 2) + 1;
            v19 = &v14[v15 + 1];
            v20 = 0;
            f = 4 * v94;
            do
            {
              *(v18 - 3) = (float)((float)(*(float *)(*((_DWORD *)v16 + 19) + v20 + 4) * vSplitPlane.y)
                                 + (float)(*(float *)(*((_DWORD *)v16 + 19) + v20) * vSplitPlane.x))
                         + (float)(*(float *)(*((_DWORD *)v16 + 19) + v20 + 8) * vSplitPlane.z);
              *(v19 - 1) = v15;
              *(float *)((char *)v19 + (_DWORD)v91) = (float)((float)(*(float *)(v20 + *((_DWORD *)v16 + 19) + 16)
                                                                    * vSplitPlane.y)
                                                            + (float)(*(float *)(v20 + *((_DWORD *)v16 + 19) + 12)
                                                                    * vSplitPlane.x))
                                                    + (float)(*(float *)(v20 + *((_DWORD *)v16 + 19) + 20)
                                                            * vSplitPlane.z);
              *v19 = v15 + 1;
              *(v18 - 1) = (float)((float)(*(float *)(v20 + *((_DWORD *)v16 + 19) + 28) * vSplitPlane.y)
                                 + (float)(*(float *)(v20 + *((_DWORD *)v16 + 19) + 24) * vSplitPlane.x))
                         + (float)(*(float *)(v20 + *((_DWORD *)v16 + 19) + 32) * vSplitPlane.z);
              v19[1] = v15 + 2;
              v21 = *((_DWORD *)v16 + 19);
              v22 = (float)(*(float *)(v21 + v20 + 40) * vSplitPlane.y)
                  + (float)(*(float *)(v21 + v20 + 36) * vSplitPlane.x);
              v23 = *(float *)(v21 + v20 + 44) * vSplitPlane.z;
              v24 = v92;
              *v18 = v22 + v23;
              v19[2] = v15 + 3;
              v20 = v24 + 48;
              v15 += 4;
              v19 += 4;
              v18 += 4;
              v25 = v94-- == 1;
              v92 = v20;
            }
            while ( !v25 );
            v5 = v99;
            v17 = nFaces;
            v14 = pIndices;
          }
          if ( f < v17 )
          {
            v26 = (char *)((char *)pDistances - (char *)v14);
            v27 = &v14[v15];
            v28 = 12 * f;
            v29 = nFaces - f;
            v91 = v26;
            do
            {
              *(float *)&v91[(_DWORD)v27] = (float)((float)(*(float *)(*((_DWORD *)v16 + 19) + v28 + 4) * vSplitPlane.y)
                                                  + (float)(*(float *)(*((_DWORD *)v16 + 19) + v28) * vSplitPlane.x))
                                          + (float)(*(float *)(*((_DWORD *)v16 + 19) + v28 + 8) * vSplitPlane.z);
              *v27 = v15++;
              v28 += 12;
              ++v27;
              --v29;
            }
            while ( v29 != 0 );
            v14 = pIndices;
            v5 = v99;
          }
          ++v96;
          mesh = (CBuilderMesh *)((char *)mesh + 1);
        }
        while ( (int)mesh < v5->m_Meshes.m_Size );
        NumTotalFaces = nTotalFaces;
      }
      QuickDepthSort(indices: v14, depths: pDistances, lo: 0, hi: NumTotalFaces - 1);
      LODWORD(vSplitPlane.w) = LODWORD(pDistances[NumTotalFaces / 2]) ^ _mask__NegFloat_;
      free(pMem: pDistances);
      free(pMem: v14);
      w = vSplitPlane.w;
      z = vSplitPlane.z;
      y = vSplitPlane.y;
    }
    pIndices = nullptr;
    if ( v5->m_Meshes.m_Size > 0 )
    {
      fa = 0;
      do
      {
        v30 = &v5->m_Meshes.m_Memory.m_pMemory[fa];
        m_nIndicesPerFace = v30->m_Combo.m_nIndicesPerFace;
        m_nInputLayout = v30->m_Combo.m_nInputLayout;
        mesh = v30;
        p_m_Material = &v30->m_Material;
        CBuilderMesh::CBuilderMesh(this: &Other);
        v34 = p_m_Material->m_ppTextures[0];
        m_nTextures = p_m_Material->m_nTextures;
        Other.m_Combo.m_nInputLayout = m_nInputLayout;
        Other.m_Combo.m_nIndicesPerFace = m_nIndicesPerFace;
        Other.m_Material.m_Material = p_m_Material->m_Material;
        v36 = p_m_Material->m_ppTextures[1];
        Other.m_Material.m_ppTextures[0] = v34;
        Other.m_Material.m_ppTextures[3] = p_m_Material->m_ppTextures[3];
        v37 = p_m_Material->m_ppTextures[6];
        Other.m_Material.m_nTextures = m_nTextures;
        v38 = p_m_Material->m_ppTextures[2];
        Other.m_Material.m_ppTextures[1] = v36;
        v39 = p_m_Material->m_ppTextures[4];
        Other.m_Material.m_ppTextures[6] = v37;
        v40 = p_m_Material->m_ppTextures[9];
        Other.m_Material.m_ppTextures[2] = v38;
        v41 = p_m_Material->m_ppTextures[5];
        Other.m_Material.m_ppTextures[4] = v39;
        v42 = p_m_Material->m_ppTextures[7];
        Other.m_Material.m_ppTextures[9] = v40;
        v43 = p_m_Material->m_ppTextures[12];
        Other.m_Material.m_ppTextures[5] = v41;
        v44 = p_m_Material->m_ppTextures[8];
        Other.m_Material.m_ppTextures[7] = v42;
        v45 = p_m_Material->m_ppTextures[10];
        Other.m_Material.m_ppTextures[12] = v43;
        v46 = p_m_Material->m_ppTextures[15];
        Other.m_Material.m_ppTextures[8] = v44;
        v47 = p_m_Material->m_ppTextures[11];
        Other.m_Material.m_ppTextures[10] = v45;
        v48 = p_m_Material->m_ppTextures[13];
        Other.m_Material.m_ppTextures[15] = v46;
        Other.m_Material.m_ppTextures[11] = v47;
        v49 = p_m_Material->m_ppTextures[14];
        Other.m_Material.m_ppTextures[13] = v48;
        Other.m_Material.m_ppTextures[14] = v49;
        nTotalFaces = (int)&p_m_Material->m_originalMaterialName;
        CUtlString::operator=(
          this: &Other.m_Material.m_originalMaterialName,
          src: &p_m_Material->m_originalMaterialName);
        m_Size = pChild1->m_Meshes.m_Size;
        m_nAllocationCount = pChild1->m_Meshes.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CBuilderMesh,int>::Grow(this: &pChild1->m_Meshes.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++pChild1->m_Meshes.m_Size;
        m_pMemory = pChild1->m_Meshes.m_Memory.m_pMemory;
        v53 = pChild1->m_Meshes.m_Size - m_Size - 1;
        pChild1->m_Meshes.m_pElements = m_pMemory;
        if ( v53 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 372 * v53);
        v54 = m_Size;
        v55 = &pChild1->m_Meshes.m_Memory.m_pMemory[v54];
        if ( v55 != nullptr )
          CBuilderMesh::CBuilderMesh(this: v55, &Other);
        v94 = (unsigned int)&pChild1->m_Meshes.m_Memory.m_pMemory[v54];
        CBuilderMesh::~CBuilderMesh(this: &Other);
        v56 = mesh->m_Combo.m_nIndicesPerFace;
        v57 = mesh->m_Combo.m_nInputLayout;
        CBuilderMesh::CBuilderMesh(this: &v87);
        v58 = p_m_Material->m_ppTextures[1];
        v59 = p_m_Material->m_ppTextures[0];
        v87.m_Combo.m_nInputLayout = v57;
        v87.m_Combo.m_nIndicesPerFace = v56;
        qmemcpy(&v87.m_Material, p_m_Material, 0xA8u);
        v60 = p_m_Material->m_ppTextures[2];
        v87.m_Material.m_ppTextures[1] = v58;
        v61 = p_m_Material->m_ppTextures[4];
        v87.m_Material.m_ppTextures[0] = v59;
        v62 = p_m_Material->m_ppTextures[3];
        v87.m_Material.m_ppTextures[2] = v60;
        v63 = p_m_Material->m_ppTextures[5];
        v87.m_Material.m_ppTextures[4] = v61;
        v64 = p_m_Material->m_ppTextures[7];
        v87.m_Material.m_ppTextures[3] = v62;
        v65 = p_m_Material->m_ppTextures[6];
        v87.m_Material.m_ppTextures[5] = v63;
        v66 = p_m_Material->m_ppTextures[8];
        v87.m_Material.m_ppTextures[7] = v64;
        v67 = p_m_Material->m_ppTextures[10];
        v87.m_Material.m_ppTextures[6] = v65;
        v68 = p_m_Material->m_ppTextures[9];
        v87.m_Material.m_ppTextures[8] = v66;
        v69 = p_m_Material->m_ppTextures[11];
        v87.m_Material.m_ppTextures[10] = v67;
        v70 = p_m_Material->m_ppTextures[13];
        v87.m_Material.m_ppTextures[9] = v68;
        v71 = p_m_Material->m_ppTextures[12];
        v87.m_Material.m_ppTextures[11] = v69;
        v72 = p_m_Material->m_ppTextures[14];
        v87.m_Material.m_ppTextures[13] = v70;
        v87.m_Material.m_ppTextures[12] = v71;
        v73 = p_m_Material->m_ppTextures[15];
        v87.m_Material.m_ppTextures[14] = v72;
        v87.m_Material.m_ppTextures[15] = v73;
        CUtlString::operator=(this: &v87.m_Material.m_originalMaterialName, src: (const CUtlString *)nTotalFaces);
        v74 = pChild2->m_Meshes.m_Size;
        v75 = pChild2->m_Meshes.m_Memory.m_nAllocationCount;
        if ( v74 + 1 > v75 )
          CUtlMemory<CBuilderMesh,int>::Grow(this: &pChild2->m_Meshes.m_Memory, num: v74 - v75 + 1);
        ++pChild2->m_Meshes.m_Size;
        v76 = pChild2->m_Meshes.m_Memory.m_pMemory;
        v77 = pChild2->m_Meshes.m_Size - v74 - 1;
        pChild2->m_Meshes.m_pElements = v76;
        if ( v77 > 0 )
          _V_memmove(dest: &v76[v74 + 1], src: &v76[v74], count: 372 * v77);
        v78 = v74;
        v79 = &pChild2->m_Meshes.m_Memory.m_pMemory[v78];
        if ( v79 != nullptr )
          CBuilderMesh::CBuilderMesh(this: v79, Other: &v87);
        v96 = &pChild2->m_Meshes.m_Memory.m_pMemory[v78];
        v80 = v96;
        CBuilderMesh::~CBuilderMesh(this: &v87);
        v81 = v94;
        ClipMeshToHalfSpace(
          pMeshBack: (CMesh *)(v94 + 8),
          pMeshFront: &v80->m_mesh,
          inputMesh: &mesh->m_mesh,
          vClipPlane: &vSplitPlane);
        if ( *(_DWORD *)(v81 + 20) == 0 )
        {
          v82 = pChild1->m_Meshes.m_Size - 1;
          nTotalFaces = v82;
          if ( v82 != -1 )
          {
            v83 = v82;
            CBuilderMesh::~CBuilderMesh(this: &pChild1->m_Meshes.m_Memory.m_pMemory[v83]);
            if ( pChild1->m_Meshes.m_Size - nTotalFaces - 1 > 0 )
              _V_memmove(
                dest: &pChild1->m_Meshes.m_Memory.m_pMemory[v83],
                src: &pChild1->m_Meshes.m_Memory.m_pMemory[v83 + 1],
                count: 372 * (pChild1->m_Meshes.m_Size - nTotalFaces - 1));
            --pChild1->m_Meshes.m_Size;
            v80 = v96;
          }
        }
        if ( v80->m_mesh.m_nVertexCount == 0 )
        {
          v84 = pChild2->m_Meshes.m_Size - 1;
          if ( pChild2->m_Meshes.m_Size != 0 )
          {
            CBuilderMesh::~CBuilderMesh(this: &pChild2->m_Meshes.m_Memory.m_pMemory[v84]);
            if ( pChild2->m_Meshes.m_Size - v84 - 1 > 0 )
              _V_memmove(
                dest: &pChild2->m_Meshes.m_Memory.m_pMemory[v84],
                src: &pChild2->m_Meshes.m_Memory.m_pMemory[v84 + 1],
                count: 372 * (pChild2->m_Meshes.m_Size - v84 - 1));
            --pChild2->m_Meshes.m_Size;
          }
        }
        ++fa;
        pIndices = (int *)((char *)pIndices + 1);
        v5 = v99;
      }
      while ( (int)pIndices < v99->m_Meshes.m_Size );
      w = vSplitPlane.w;
      z = vSplitPlane.z;
      y = vSplitPlane.y;
    }
    v85 = 0;
    vNegSplitPlane.x = -vSplitPlane.x;
    vNegSplitPlane.y = -y;
    vNegSplitPlane.z = -z;
    vNegSplitPlane.w = -w;
    if ( v5->m_InstanceContainers.m_Size > 0 )
    {
      fb = 0;
      do
      {
        v86 = &v5->m_InstanceContainers.m_Memory.m_pMemory[fb];
        CBVHNodeBuilder::AddInstancesAndClip(
          this: pChild1,
          pInstanceGeometry: v86->m_pInstanceGeometry,
          nTransforms: v86->m_pTransforms->m_Size,
          pTransforms: v86->m_pTransforms->m_Memory.m_pMemory,
          vClipPlane: vSplitPlane);
        CBVHNodeBuilder::AddInstancesAndClip(
          this: pChild2,
          pInstanceGeometry: v86->m_pInstanceGeometry,
          nTransforms: v86->m_pTransforms->m_Size,
          pTransforms: v86->m_pTransforms->m_Memory.m_pMemory,
          vClipPlane: vNegSplitPlane);
        ++fb;
        ++v85;
      }
      while ( v85 < v5->m_InstanceContainers.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004073F0
// Name: private: int CBVHNodeBuilder::CreateFullDetailDrawCalls(class CResourceDictionaryBuilder __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBVHNodeBuilder::CreateFullDetailDrawCalls(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary,
        int nLastResource)
{
  CBVHNodeBuilder *v3; // edi
  int m_Size; // ebx
  CBuilderMesh *v5; // ebx
  int m_nInputLayout; // edx
  int m_nVertexCount; // eax
  int m_nTextures; // esi
  BVHResourceBinding_t *m_pResourceBindings; // eax
  int v10; // esi
  int v11; // ecx
  int v12; // esi
  int v13; // edi
  int v14; // edx
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v15; // eax
  int v16; // ecx
  int m_nPerDrawIndexSets; // ecx
  int v18; // edi
  int v19; // edi
  AABB_t *v20; // eax
  CBVHNodeBuilder *v21; // esi
  int v22; // edi
  float z; // xmm0_4
  int v24; // eax
  CBVHDrawCallBuilder *v25; // ecx
  int v26; // eax
  CBVHDrawCallBuilder *v27; // edi
  bool v28; // cc
  BVHResourceBinding_t *v29; // edi
  BVHResourceBinding_t *v30; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v31; // ecx
  int v32; // edx
  int v33; // eax
  int v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm5_4
  int m_nVertexStrideFloats; // esi
  float *m_pVerts; // edi
  unsigned int *m_pMemory; // ecx
  int v43; // edx
  __int64 v44; // xmm0_8
  float v45; // edx
  float v46; // xmm4_4
  double v47; // xmm0_8
  double v48; // xmm1_8
  float v49; // xmm0_4
  double v50; // xmm0_8
  float v51; // xmm0_4
  double v52; // xmm0_8
  double v53; // xmm0_8
  double v54; // xmm0_8
  double v55; // xmm0_8
  CBVHNodeBuilder *v56; // esi
  int v57; // edi
  int m_nAllocationCount; // eax
  CBVHDrawCallBuilder *v59; // ecx
  int v60; // eax
  CBVHDrawCallBuilder *v61; // edi
  int v62; // edx
  int v63; // eax
  AABB_t v65; // [esp+Ch] [ebp-124h] BYREF
  int pCurrentVBByteOffset[4]; // [esp+24h] [ebp-10Ch] BYREF
  CBVHDrawCallBuilder DrawCall; // [esp+34h] [ebp-FCh]
  __int64 v68; // [esp+84h] [ebp-ACh]
  float v69; // [esp+8Ch] [ebp-A4h]
  float v70; // [esp+90h] [ebp-A0h]
  float v71; // [esp+94h] [ebp-9Ch]
  float v72; // [esp+A4h] [ebp-8Ch]
  __int64 v73; // [esp+A8h] [ebp-88h]
  __int64 v74; // [esp+B0h] [ebp-80h]
  __int64 v75; // [esp+B8h] [ebp-78h]
  __int64 v76; // [esp+C0h] [ebp-70h]
  __int64 v77; // [esp+C8h] [ebp-68h]
  __int64 v78; // [esp+D0h] [ebp-60h]
  __int64 v79; // [esp+D8h] [ebp-58h]
  __int64 v80; // [esp+E0h] [ebp-50h]
  __int64 v81; // [esp+E8h] [ebp-48h]
  __int64 v82; // [esp+F0h] [ebp-40h]
  int r; // [esp+F8h] [ebp-38h]
  int nIBStart; // [esp+FCh] [ebp-34h]
  int nTextureStart; // [esp+100h] [ebp-30h]
  int nTotalTextures; // [esp+104h] [ebp-2Ch]
  int nCurrentTexture; // [esp+108h] [ebp-28h]
  int *nCurrentVBByteOffset; // [esp+10Ch] [ebp-24h]
  int d; // [esp+110h] [ebp-20h]
  unsigned int v90; // [esp+114h] [ebp-1Ch]
  int nMeshes; // [esp+118h] [ebp-18h]
  int m; // [esp+11Ch] [ebp-14h]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *perDrawIndices; // [esp+120h] [ebp-10h]
  CBVHNodeBuilder *v94; // [esp+124h] [ebp-Ch]
  int nCurrentIBCountOffset; // [esp+128h] [ebp-8h]
  int t; // [esp+12Ch] [ebp-4h]

  v3 = this;
  m_Size = this->m_Meshes.m_Size;
  v94 = this;
  nMeshes = m_Size;
  nTotalTextures = CBVHNodeBuilder::CalculateTotalUniqueTextures(this);
  memset(pCurrentVBByteOffset, 0, sizeof(pCurrentVBByteOffset));
  nCurrentTexture = 0;
  nCurrentIBCountOffset = 0;
  m = 0;
  if ( m_Size > 0 )
  {
    v90 = 0;
    nTextureStart = nLastResource + m_Size;
    do
    {
      v5 = &v3->m_Meshes.m_Memory.m_pMemory[v90 / 0x174];
      if ( v5->m_Combo.m_nIndicesPerFace == 3 )
        DrawCall.m_nPrimitiveType = RENDER_PRIM_TRIANGLES;
      else
        _Msg(a1: "Only works on triangles for now!");
      m_nInputLayout = v5->m_Combo.m_nInputLayout;
      m_nVertexCount = v5->m_mesh.m_nVertexCount;
      DrawCall.m_nMeshID = m;
      DrawCall.m_nInstanceCount = 0;
      DrawCall.m_nStartInstance = 0;
      DrawCall.m_nBaseVertex = 0;
      m_nTextures = v5->m_Material.m_nTextures;
      DrawCall.m_nStartIndex = nCurrentIBCountOffset;
      DrawCall.m_nInputLayout = m_nInputLayout;
      DrawCall.m_nVertexCount = m_nVertexCount;
      DrawCall.m_Flags = 64;
      DrawCall.m_nResourceBindings = m_nTextures + 3;
      m_pResourceBindings = (BVHResourceBinding_t *)MemAlloc_Alloc(
                                                      nSize: (unsigned __int64)(unsigned int)DrawCall.m_nResourceBindings >> 28 != 0
                                                    ? -1
                                                    : 16 * DrawCall.m_nResourceBindings);
      v10 = nMeshes + nTotalTextures + v94->m_nVBsNeeded;
      v11 = nLastResource + nMeshes + nTotalTextures + v94->m_pVBIndex[v5->m_Combo.m_nInputLayout];
      nCurrentVBByteOffset = &pCurrentVBByteOffset[v5->m_Combo.m_nInputLayout];
      v77 = (unsigned int)(nLastResource + m);
      *(_QWORD *)&m_pResourceBindings->m_nResourceIndex = v77;
      v12 = nLastResource + v10;
      WORD2(v78) = 0;
      LODWORD(v78) = 0;
      *(_QWORD *)&m_pResourceBindings->m_nElementStride = v78;
      DrawCall.m_pResourceBindings = m_pResourceBindings;
      nIBStart = v12;
      v13 = 1;
      t = 0;
      if ( v5->m_Material.m_nTextures > 0 )
      {
        perDrawIndices = (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&m_pResourceBindings[1];
        do
        {
          v14 = nCurrentTexture;
          v75 = (unsigned int)(nCurrentTexture + nTextureStart);
          BYTE5(v76) = t;
          LODWORD(v76) = 0;
          v15 = perDrawIndices;
          *(_QWORD *)&perDrawIndices->m_Memory.m_pMemory = v75;
          BYTE4(v76) = 1;
          *(_QWORD *)&v15->m_Memory.m_nGrowSize = v76;
          perDrawIndices = (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&v15->m_pElements;
          ++v13;
          nCurrentTexture = v14 + 1;
          ++t;
        }
        while ( t < v5->m_Material.m_nTextures );
        m_pResourceBindings = DrawCall.m_pResourceBindings;
      }
      LODWORD(v81) = v11;
      HIDWORD(v81) = *nCurrentVBByteOffset;
      LODWORD(v82) = 4 * v5->m_mesh.m_nVertexStrideFloats;
      v16 = v13;
      *(_QWORD *)&m_pResourceBindings[v16].m_nResourceIndex = v81;
      WORD2(v82) = 2;
      *(_QWORD *)&m_pResourceBindings[v16].m_nElementStride = v82;
      m_nPerDrawIndexSets = v5->m_nPerDrawIndexSets;
      v18 = v13 + 1;
      r = v18;
      if ( m_nPerDrawIndexSets >= 1 )
      {
        d = 0;
        t = 0;
        do
        {
          v28 = *(int *)((char *)&v5->m_pPerDrawIndices->m_Size + t) < 3;
          perDrawIndices = (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)((char *)v5->m_pPerDrawIndices + t);
          if ( !v28 )
          {
            v29 = m_pResourceBindings;
            v30 = (BVHResourceBinding_t *)MemAlloc_Alloc(
                                            nSize: (unsigned __int64)(unsigned int)DrawCall.m_nResourceBindings >> 28 != 0
                                          ? -1
                                          : 16 * DrawCall.m_nResourceBindings);
            DrawCall.m_pResourceBindings = v30;
            _V_memcpy(dest: v30, src: v29, count: 16 * DrawCall.m_nResourceBindings);
            v31 = perDrawIndices;
            v32 = perDrawIndices->m_Size;
            DrawCall.m_nStartIndex = nCurrentIBCountOffset;
            DrawCall.m_nIndexCount = v32;
            v33 = r;
            v79 = (unsigned int)nIBStart;
            *(_QWORD *)&v30[v33].m_nResourceIndex = (unsigned int)nIBStart;
            WORD2(v80) = 2;
            LODWORD(v80) = 4;
            *(_QWORD *)&v30[v33].m_nElementStride = v80;
            v34 = v31->m_Size;
            v35 = 3.4028235e38;
            v36 = 3.4028235e38;
            v37 = 3.4028235e38;
            v38 = -3.4028235e38;
            v39 = -3.4028235e38;
            v72 = -3.4028235e38;
            if ( v34 > 0 )
            {
              m_nVertexStrideFloats = v5->m_mesh.m_nVertexStrideFloats;
              m_pVerts = v5->m_mesh.m_pVerts;
              m_pMemory = v31->m_Memory.m_pMemory;
              do
              {
                v43 = m_nVertexStrideFloats * *m_pMemory;
                v44 = *(_QWORD *)&m_pVerts[v43];
                v45 = m_pVerts[v43 + 2];
                v68 = v44;
                v46 = *(float *)&v44;
                v47 = *(float *)&v44;
                v48 = v35;
                v69 = v45;
                if ( v47 > v48 )
                  v47 = v48;
                v49 = v47;
                v70 = v49;
                v50 = *((float *)&v68 + 1);
                if ( *((float *)&v68 + 1) > (double)v36 )
                  v50 = v36;
                v51 = v50;
                v71 = v51;
                v52 = v69;
                if ( v69 > (double)v37 )
                  v52 = v37;
                v37 = v52;
                v53 = v46;
                if ( v46 < (double)v38 )
                  v53 = v38;
                v38 = v53;
                v54 = *((float *)&v68 + 1);
                if ( *((float *)&v68 + 1) < (double)v39 )
                  v54 = v39;
                v39 = v54;
                v55 = v69;
                if ( v69 < (double)v72 )
                  v55 = v72;
                v36 = v71;
                v35 = v70;
                ++m_pMemory;
                --v34;
                v72 = v55;
              }
              while ( v34 != 0 );
            }
            v56 = v94;
            v57 = v94->m_BuilderDrawCalls.m_Size;
            m_nAllocationCount = v94->m_BuilderDrawCalls.m_Memory.m_nAllocationCount;
            DrawCall.m_Bounds.m_vMinBounds.x = v35;
            DrawCall.m_Bounds.m_vMinBounds.y = v36;
            DrawCall.m_Bounds.m_vMinBounds.z = v37;
            DrawCall.m_Bounds.m_vMaxBounds.x = v38;
            DrawCall.m_Bounds.m_vMaxBounds.y = v39;
            DrawCall.m_Bounds.m_vMaxBounds.z = v72;
            if ( v57 + 1 > m_nAllocationCount )
              CUtlMemory<CDispMultiBlend,int>::Grow(
                this: &v94->m_BuilderDrawCalls.m_Memory,
                num: v57 - m_nAllocationCount + 1);
            ++v56->m_BuilderDrawCalls.m_Size;
            v59 = v56->m_BuilderDrawCalls.m_Memory.m_pMemory;
            v60 = v56->m_BuilderDrawCalls.m_Size - v57 - 1;
            v56->m_BuilderDrawCalls.m_pElements = v59;
            if ( v60 > 0 )
              _V_memmove(dest: &v59[v57 + 1], src: &v59[v57], count: 80 * v60);
            v61 = &v56->m_BuilderDrawCalls.m_Memory.m_pMemory[v57];
            if ( v61 != nullptr )
              *v61 = DrawCall;
            nCurrentIBCountOffset += perDrawIndices->m_Size;
            m_pResourceBindings = DrawCall.m_pResourceBindings;
          }
          t += 20;
          ++d;
        }
        while ( d < v5->m_nPerDrawIndexSets );
      }
      else
      {
        v19 = v18;
        v73 = (unsigned int)v12;
        *(_QWORD *)&m_pResourceBindings[v19].m_nResourceIndex = (unsigned int)v12;
        WORD2(v74) = 2;
        LODWORD(v74) = 4;
        *(_QWORD *)&m_pResourceBindings[v19].m_nElementStride = v74;
        v20 = CBuilderMesh::CalculateBounds(this: v5, result: &v65, nVertStart: 0, nVertCount: 0);
        v21 = v94;
        v22 = v94->m_BuilderDrawCalls.m_Size;
        DrawCall.m_Bounds.m_vMinBounds = v20->m_vMinBounds;
        DrawCall.m_Bounds.m_vMaxBounds.x = v20->m_vMaxBounds.x;
        DrawCall.m_Bounds.m_vMaxBounds.y = v20->m_vMaxBounds.y;
        z = v20->m_vMaxBounds.z;
        DrawCall.m_nIndexCount = v5->m_mesh.m_nIndexCount;
        v24 = v94->m_BuilderDrawCalls.m_Memory.m_nAllocationCount;
        DrawCall.m_Bounds.m_vMaxBounds.z = z;
        if ( v22 + 1 > v24 )
          CUtlMemory<CDispMultiBlend,int>::Grow(this: &v94->m_BuilderDrawCalls.m_Memory, num: v22 - v24 + 1);
        ++v21->m_BuilderDrawCalls.m_Size;
        v25 = v21->m_BuilderDrawCalls.m_Memory.m_pMemory;
        v26 = v21->m_BuilderDrawCalls.m_Size - v22 - 1;
        v21->m_BuilderDrawCalls.m_pElements = v25;
        if ( v26 > 0 )
          _V_memmove(dest: &v25[v22 + 1], src: &v25[v22], count: 80 * v26);
        v27 = &v21->m_BuilderDrawCalls.m_Memory.m_pMemory[v22];
        if ( v27 != nullptr )
          *v27 = DrawCall;
        nCurrentIBCountOffset += v5->m_mesh.m_nIndexCount;
      }
      v62 = v5->m_mesh.m_nVertexCount * v5->m_mesh.m_nVertexStrideFloats;
      v63 = *nCurrentVBByteOffset;
      v90 += 372;
      v3 = v94;
      *nCurrentVBByteOffset = v63 + 4 * v62;
      ++m;
    }
    while ( m < nMeshes );
    m_Size = nMeshes;
  }
  return m_Size + nTotalTextures + v3->m_nVBsNeeded + nLastResource + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407A00
// Name: private: int CBVHNodeBuilder::CreateSimplifiedDrawCalls(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBVHNodeBuilder::CreateSimplifiedDrawCalls(
        CBVHNodeBuilder *this,
        int nMaxTexScaleSlots,
        int nLastResource)
{
  CBuilderMesh *m_pMemory; // esi
  int v4; // edi
  BVHResourceBinding_t *v5; // eax
  CBVHNodeBuilder *v6; // edx
  int m_nTextures; // edi
  int v8; // eax
  int v9; // ecx
  BVHResourceBinding_t *v10; // edx
  int v11; // edi
  int m_nVertexStrideFloats; // ecx
  BVHResourceBinding_t *v13; // eax
  int m_nIndexCount; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<CBVHDrawCallBuilder,int> *p_m_Memory; // esi
  CBVHDrawCallBuilder *v18; // ecx
  int v19; // eax
  CBVHDrawCallBuilder *v20; // edi
  __int64 v32; // [esp+64h] [ebp-10h]
  int nLastResourcea; // [esp+80h] [ebp+Ch]
  CBVHDrawCallBuilder DrawCall; // 0:^18.80

  m_pMemory = this->m_Meshes.m_Memory.m_pMemory;
  if ( m_pMemory->m_Combo.m_nIndicesPerFace == 3 )
  {
    DrawCall.m_nPrimitiveType = RENDER_PRIM_TRIANGLES;
    DrawCall.m_nMeshID = 0;
    DrawCall.m_Flags = 0;
    DrawCall.m_nInputLayout = m_pMemory->m_Combo.m_nInputLayout;
    *(_QWORD *)&DrawCall.m_nStartInstance = 0;
    v4 = 1;
    if ( (this->m_pHeader->m_Flags & 2) != 0 )
      v4 = m_pMemory->m_Material.m_nTextures + 1;
    DrawCall.m_nResourceBindings = v4 + 2;
    v5 = (BVHResourceBinding_t *)MemAlloc_Alloc(
                                   nSize: (unsigned __int64)(unsigned int)DrawCall.m_nResourceBindings >> 28 != 0
                                 ? -1
                                 : 16 * DrawCall.m_nResourceBindings);
    v6 = this;
    m_nTextures = 0;
    DrawCall.m_pResourceBindings = v5;
    if ( (this->m_pHeader->m_Flags & 2) != 0 )
      m_nTextures = m_pMemory->m_Material.m_nTextures;
    *(_QWORD *)&v5->m_nResourceIndex = (unsigned int)nLastResource;
    WORD2(v32) = 0;
    LODWORD(v32) = 0;
    *(_QWORD *)&v5->m_nElementStride = v32;
    v8 = 1;
    if ( (this->m_pHeader->m_Flags & 2) != 0 )
    {
      v9 = 0;
      if ( m_nTextures > 0 )
      {
        v10 = DrawCall.m_pResourceBindings + 1;
        v8 = m_nTextures + 1;
        do
        {
          *(_QWORD *)&v10->m_nResourceIndex = (unsigned int)(nLastResource + v9 + 1);
          BYTE5(v32) = v9;
          BYTE4(v32) = 1;
          LODWORD(v32) = 0;
          *(_QWORD *)&v10->m_nElementStride = v32;
          ++v9;
          ++v10;
        }
        while ( v9 < m_nTextures );
        v6 = this;
      }
    }
    v11 = m_nTextures + nLastResource + 1;
    m_nVertexStrideFloats = m_pMemory->m_mesh.m_nVertexStrideFloats;
    v13 = &DrawCall.m_pResourceBindings[v8];
    *(_QWORD *)&v13->m_nResourceIndex = (unsigned int)v11;
    LODWORD(v32) = 4 * m_nVertexStrideFloats;
    WORD2(v32) = 2;
    *(_QWORD *)&v13->m_nElementStride = v32;
    nLastResourcea = v11;
    *(_QWORD *)&v13[1].m_nResourceIndex = (unsigned int)(v11 + 1);
    WORD2(v32) = 2;
    LODWORD(v32) = 4;
    *(_QWORD *)&v13[1].m_nElementStride = v32;
    m_nIndexCount = m_pMemory->m_mesh.m_nIndexCount;
    m_Size = v6->m_BuilderDrawCalls.m_Size;
    *(_QWORD *)&DrawCall.m_nVertexCount = (unsigned int)m_pMemory->m_mesh.m_nVertexCount;
    m_nAllocationCount = v6->m_BuilderDrawCalls.m_Memory.m_nAllocationCount;
    DrawCall.m_Bounds = v6->m_pHeader->m_Bounds;
    p_m_Memory = &v6->m_BuilderDrawCalls.m_Memory;
    DrawCall.m_nBaseVertex = 0;
    DrawCall.m_nIndexCount = m_nIndexCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CDispMultiBlend,int>::Grow(this: p_m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Memory[1].m_pMemory;
    v18 = p_m_Memory->m_pMemory;
    v19 = (int)p_m_Memory[1].m_pMemory - m_Size - 1;
    p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[m_Size + 1], src: &v18[m_Size], count: 80 * v19);
    v20 = &p_m_Memory->m_pMemory[m_Size];
    if ( v20 != nullptr )
      *v20 = DrawCall;
    return nLastResourcea + 2;
  }
  else
  {
    _Msg(a1: "Only works on triangles for now!");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407C50
// Name: private: void CBVHNodeBuilder::CreateInstancedDrawCalls(class CResourceDictionaryBuilder __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::CreateInstancedDrawCalls(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary,
        int nLastResource)
{
  int m_Size; // eax
  int v4; // edi
  InstanceContainer_t *v5; // eax
  InstanceGeometry_t *m_pInstanceGeometry; // edx
  int m_nMeshes; // esi
  CBuilderMesh *v8; // esi
  bool v9; // zf
  int v10; // eax
  _QWORD *v11; // eax
  int m_nIndexCount; // edx
  int v13; // ecx
  _QWORD *v14; // ebx
  int m_nVertexCount; // eax
  int v16; // edi
  int v17; // eax
  _QWORD *v18; // edx
  int v19; // ecx
  int v20; // edx
  InstanceContainer_t *v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // edx
  int v25; // eax
  int m_nPerDrawTransformSets; // eax
  CBVHNodeBuilder *v27; // esi
  int v28; // ecx
  BVHNodeHeader_t *m_pHeader; // eax
  int v30; // ebx
  __int64 v31; // xmm0_8
  int v32; // eax
  CBVHDrawCallBuilder *v33; // ecx
  int v34; // eax
  CBVHDrawCallBuilder *v35; // ebx
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *v36; // edi
  bool v37; // cc
  int v38; // edx
  int v39; // eax
  CBVHNodeBuilder *v40; // esi
  AABB_t *v41; // eax
  int v42; // edi
  float z; // xmm0_4
  int m_nAllocationCount; // eax
  CBVHDrawCallBuilder *m_pMemory; // ecx
  int v46; // eax
  CBVHDrawCallBuilder *v47; // edi
  CBuilderMesh *v48; // [esp-14h] [ebp-134h]
  AABB_t result; // [esp+0h] [ebp-120h] BYREF
  CBVHDrawCallBuilder DrawCall; // [esp+18h] [ebp-108h]
  AABB_t v51; // [esp+68h] [ebp-B8h]
  __int64 v52; // [esp+80h] [ebp-A0h]
  __int64 v53; // [esp+88h] [ebp-98h]
  __int64 v54; // [esp+90h] [ebp-90h]
  __int64 v55; // [esp+98h] [ebp-88h]
  __int64 v56; // [esp+A0h] [ebp-80h]
  __int64 v57; // [esp+A8h] [ebp-78h]
  __int64 v58; // [esp+B0h] [ebp-70h]
  __int64 v59; // [esp+B8h] [ebp-68h]
  __int64 v60; // [esp+C0h] [ebp-60h]
  __int64 v61; // [esp+C8h] [ebp-58h]
  __int64 v62; // [esp+D0h] [ebp-50h]
  __int64 v63; // [esp+D8h] [ebp-48h]
  CBuilderMesh *mesh; // [esp+E0h] [ebp-40h]
  InstanceGeometry_t *pInstanceLOD; // [esp+E4h] [ebp-3Ch]
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *perDrawTransforms; // [esp+E8h] [ebp-38h]
  int v67; // [esp+ECh] [ebp-34h]
  BVHResourceBinding_t *pOldBindings; // [esp+F0h] [ebp-30h]
  int i; // [esp+F4h] [ebp-2Ch]
  int nMaterialStart; // [esp+F8h] [ebp-28h]
  int v71; // [esp+FCh] [ebp-24h]
  int d; // [esp+100h] [ebp-20h]
  unsigned int v73; // [esp+104h] [ebp-1Ch]
  unsigned int v74; // [esp+108h] [ebp-18h]
  int nSubInstances; // [esp+10Ch] [ebp-14h]
  unsigned int v76; // [esp+110h] [ebp-10h]
  CBVHNodeBuilder *v77; // [esp+114h] [ebp-Ch]
  int nCurrentInstances; // [esp+118h] [ebp-8h]
  InstanceContainer_t *container; // [esp+11Ch] [ebp-4h]

  m_Size = this->m_InstanceContainers.m_Size;
  v77 = this;
  if ( m_Size < 1 )
    return;
  v4 = nLastResource + 1;
  DrawCall.m_nMeshID = 0;
  nCurrentInstances = 0;
  v76 = 0;
  for ( i = m_Size; i != 0; --i )
  {
    v5 = &this->m_InstanceContainers.m_Memory.m_pMemory[v76 / 0x10];
    m_pInstanceGeometry = v5->m_pInstanceGeometry;
    m_nMeshes = v5->m_pInstanceGeometry->m_nMeshes;
    container = v5;
    pInstanceLOD = m_pInstanceGeometry;
    if ( m_nMeshes <= 0 )
      goto LABEL_34;
    v74 = 0;
    v71 = m_nMeshes;
    while ( 1 )
    {
      v8 = &m_pInstanceGeometry->m_pMeshes[v74 / 0x174];
      DrawCall.m_Flags = 64;
      v9 = v8->m_Combo.m_nInputLayout == 1;
      mesh = v8;
      DrawCall.m_nPrimitiveType = RENDER_PRIM_TRIANGLES;
      v10 = 2;
      if ( v9 )
        v10 = 3;
      DrawCall.m_nInputLayout = v10;
      DrawCall.m_nResourceBindings = v8->m_Material.m_nTextures + 4;
      DrawCall.m_nStartInstance = 0;
      v11 = MemAlloc_Alloc(
              nSize: (unsigned __int64)(unsigned int)DrawCall.m_nResourceBindings >> 28 != 0
            ? -1
            : 16 * DrawCall.m_nResourceBindings);
      m_nIndexCount = v8->m_mesh.m_nIndexCount;
      v13 = 0;
      v14 = v11;
      m_nVertexCount = v8->m_mesh.m_nVertexCount;
      v56 = (unsigned int)v4;
      *v14 = (unsigned int)v4;
      WORD2(v57) = 0;
      LODWORD(v57) = 0;
      v14[1] = v57;
      v16 = v4 + 1;
      DrawCall.m_nVertexCount = m_nVertexCount;
      DrawCall.m_pResourceBindings = (BVHResourceBinding_t *)v14;
      DrawCall.m_nBaseVertex = 0;
      DrawCall.m_nStartIndex = 0;
      DrawCall.m_nIndexCount = m_nIndexCount;
      v17 = 1;
      if ( v8->m_Material.m_nTextures > 0 )
      {
        v18 = v14 + 2;
        do
        {
          v54 = (unsigned int)v16;
          *v18 = (unsigned int)v16;
          BYTE5(v55) = v13;
          BYTE4(v55) = 1;
          LODWORD(v55) = 0;
          v18[1] = v55;
          ++v13;
          ++v17;
          v18 += 2;
          ++v16;
        }
        while ( v13 < v8->m_Material.m_nTextures );
      }
      v19 = 4 * v8->m_mesh.m_nVertexStrideFloats;
      v20 = 2 * v17;
      v62 = (unsigned int)v16;
      v14[v20] = (unsigned int)v16;
      LODWORD(v63) = v19;
      v21 = container;
      WORD2(v63) = 2;
      v14[v20 + 1] = v63;
      v22 = v17 + 1;
      v23 = v16 + 1;
      if ( v21->m_nPerDrawTransformSets < 1 )
      {
        LODWORD(v52) = nLastResource;
        HIDWORD(v52) = 48 * nCurrentInstances;
        v24 = 2 * v22;
        v14[v24] = v52;
        WORD2(v53) = 258;
        LODWORD(v53) = 48;
        v14[v24 + 1] = v53;
      }
      v25 = 2 * v22;
      v60 = (unsigned int)v23;
      v14[v25 + 2] = (unsigned int)v23;
      WORD2(v61) = 2;
      LODWORD(v61) = 4;
      v67 = v25 * 8;
      v14[v25 + 3] = v61;
      m_nPerDrawTransformSets = v21->m_nPerDrawTransformSets;
      v4 = v23 + 1;
      nMaterialStart = v4;
      if ( m_nPerDrawTransformSets >= 1 )
      {
        nSubInstances = 0;
        d = 0;
        v73 = 0;
        while ( 1 )
        {
          v36 = &v21->m_pPerDrawTransforms[v73 / 0x14];
          v37 = v36->m_Size < 1;
          perDrawTransforms = v36;
          if ( !v37 )
          {
            pOldBindings = (BVHResourceBinding_t *)v14;
            v14 = MemAlloc_Alloc(
                    nSize: (unsigned __int64)(unsigned int)DrawCall.m_nResourceBindings >> 28 != 0
                  ? -1
                  : 16 * DrawCall.m_nResourceBindings);
            DrawCall.m_pResourceBindings = (BVHResourceBinding_t *)v14;
            _V_memcpy(dest: v14, src: pOldBindings, count: 16 * DrawCall.m_nResourceBindings);
            v38 = v36->m_Size;
            LODWORD(v58) = nLastResource;
            HIDWORD(v58) = 48 * (nCurrentInstances + nSubInstances);
            v39 = v67;
            v48 = v8;
            v40 = v77;
            *(_QWORD *)((char *)v14 + v67) = v58;
            WORD2(v59) = 258;
            LODWORD(v59) = 48;
            DrawCall.m_nInstanceCount = v38;
            *(_QWORD *)((char *)v14 + v39 + 8) = v59;
            v41 = CBVHNodeBuilder::CalculateBoundsForInstances(this: v40, &result, pInstMesh: v48, pTransforms: v36);
            v42 = v40->m_BuilderDrawCalls.m_Size;
            DrawCall.m_Bounds.m_vMinBounds = v41->m_vMinBounds;
            DrawCall.m_Bounds.m_vMaxBounds.x = v41->m_vMaxBounds.x;
            DrawCall.m_Bounds.m_vMaxBounds.y = v41->m_vMaxBounds.y;
            z = v41->m_vMaxBounds.z;
            m_nAllocationCount = v40->m_BuilderDrawCalls.m_Memory.m_nAllocationCount;
            DrawCall.m_Bounds.m_vMaxBounds.z = z;
            if ( v42 + 1 > m_nAllocationCount )
              CUtlMemory<CDispMultiBlend,int>::Grow(
                this: &v40->m_BuilderDrawCalls.m_Memory,
                num: v42 - m_nAllocationCount + 1);
            ++v40->m_BuilderDrawCalls.m_Size;
            m_pMemory = v40->m_BuilderDrawCalls.m_Memory.m_pMemory;
            v46 = v40->m_BuilderDrawCalls.m_Size - v42 - 1;
            v40->m_BuilderDrawCalls.m_pElements = m_pMemory;
            if ( v46 > 0 )
              _V_memmove(dest: &m_pMemory[v42 + 1], src: &m_pMemory[v42], count: 80 * v46);
            v47 = &v40->m_BuilderDrawCalls.m_Memory.m_pMemory[v42];
            if ( v47 != nullptr )
              *v47 = DrawCall;
            nSubInstances += perDrawTransforms->m_Size;
            v8 = mesh;
          }
          v73 += 20;
          if ( ++d >= container->m_nPerDrawTransformSets )
            break;
          v21 = container;
        }
        goto LABEL_31;
      }
      v27 = v77;
      v28 = v21->m_pTransforms->m_Size;
      m_pHeader = v77->m_pHeader;
      v30 = v77->m_BuilderDrawCalls.m_Size;
      *(_QWORD *)&v51.m_vMinBounds.x = *(_QWORD *)&v77->m_pHeader->m_Bounds.m_vMinBounds.x;
      *(_QWORD *)&v51.m_vMinBounds.z = *(_QWORD *)&m_pHeader->m_Bounds.m_vMinBounds.z;
      v31 = *(_QWORD *)&m_pHeader->m_Bounds.m_vMaxBounds.y;
      v32 = v77->m_BuilderDrawCalls.m_Memory.m_nAllocationCount;
      *(_QWORD *)&v51.m_vMaxBounds.y = v31;
      DrawCall.m_Bounds = v51;
      DrawCall.m_nInstanceCount = v28;
      if ( v30 + 1 > v32 )
        CUtlMemory<CDispMultiBlend,int>::Grow(this: &v77->m_BuilderDrawCalls.m_Memory, num: v30 - v32 + 1);
      ++v27->m_BuilderDrawCalls.m_Size;
      v33 = v27->m_BuilderDrawCalls.m_Memory.m_pMemory;
      v34 = v27->m_BuilderDrawCalls.m_Size - v30 - 1;
      v27->m_BuilderDrawCalls.m_pElements = v33;
      if ( v34 > 0 )
        _V_memmove(dest: &v33[v30 + 1], src: &v33[v30], count: 80 * v34);
      v35 = &v27->m_BuilderDrawCalls.m_Memory.m_pMemory[v30];
      if ( v35 != nullptr )
      {
        *v35 = DrawCall;
LABEL_31:
        v4 = nMaterialStart;
      }
      v74 += 372;
      if ( --v71 == 0 )
        break;
      m_pInstanceGeometry = pInstanceLOD;
    }
    this = v77;
    v5 = container;
LABEL_34:
    nCurrentInstances += v5->m_pTransforms->m_Size;
    v76 += 16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408160
// Name: private: void CBVHNodeBuilder::SplitDrawCalls(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::SplitDrawCalls(CBVHNodeBuilder *this, float flSplitSize)
{
  BVHNodeHeader_t *m_pHeader; // eax
  float v3; // xmm3_4
  float v4; // xmm1_4
  int v5; // ecx
  float v6; // xmm2_4
  int v7; // eax
  int v8; // edx
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  int m_Size; // edi
  AABB_t *m_pMemory; // ebx
  float v15; // xmm1_4
  float v16; // xmm2_4
  int v17; // esi
  _QWORD *p_x; // eax
  InstanceContainer_t *v19; // eax
  int v20; // ebx
  CBuilderMesh *v21; // edi
  int v22; // ecx
  int *v23; // eax
  int v24; // ecx
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v25; // edx
  _DWORD *i; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v27; // eax
  int v28; // edx
  unsigned int *m_pIndices; // ecx
  AABB_t *v30; // ecx
  CUtlMemory<S3RGBA,int> *v31; // esi
  unsigned int *v32; // ebx
  int v33; // eax
  float *v34; // eax
  float v35; // xmm0_4
  float v36; // xmm0_4
  S3RGBA *v37; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v39; // ecx
  int v40; // eax
  S3RGBA *v41; // edi
  S3RGBA *v42; // edi
  int v43; // eax
  S3RGBA *v44; // ecx
  int v45; // eax
  S3RGBA *v46; // edi
  S3RGBA *v47; // edi
  int v48; // eax
  S3RGBA *v49; // ecx
  int v50; // eax
  unsigned int *v51; // edi
  bool v52; // zf
  CBuilderMesh *v53; // eax
  int v54; // edi
  InstanceContainer_t *v55; // esi
  int v56; // eax
  int v57; // ecx
  int *v58; // eax
  int v59; // ecx
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *v60; // edx
  _DWORD *k; // eax
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *m_pTransforms; // ecx
  AABB_t *v63; // edi
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *v64; // esi
  bool v65; // cc
  int v66; // ebx
  matrix3x4_t *v67; // eax
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm2_4
  const matrix3x4_t *v71; // eax
  int v72; // esi
  int v73; // edx
  float *p_z; // eax
  unsigned int v75; // ecx
  float *v76; // eax
  int v77; // ecx
  float v78; // [esp+10h] [ebp-90h]
  __int64 newbounds_8; // [esp+20h] [ebp-80h]
  unsigned __int64 newbounds_16; // [esp+28h] [ebp-78h]
  int j; // [esp+30h] [ebp-70h]
  float vStep; // [esp+34h] [ebp-6Ch]
  float vStep_4; // [esp+38h] [ebp-68h]
  float vStep_8; // [esp+3Ch] [ebp-64h]
  int nFaces; // [esp+40h] [ebp-60h]
  float vStart_4; // [esp+48h] [ebp-58h]
  float vStart_8; // [esp+4Ch] [ebp-54h]
  AABB_t bounds; // [esp+50h] [ebp-50h] BYREF
  CBVHNodeBuilder *v89; // [esp+68h] [ebp-38h]
  CUtlVector<AABB_t,CUtlMemory<AABB_t,int> > splitVolumes; // [esp+6Ch] [ebp-34h] BYREF
  int v91; // [esp+80h] [ebp-20h]
  InstanceContainer_t *container; // [esp+84h] [ebp-1Ch]
  unsigned int *pIndices; // [esp+88h] [ebp-18h]
  CBuilderMesh *mesh; // [esp+8Ch] [ebp-14h]
  int y; // [esp+90h] [ebp-10h]
  int nAdds; // [esp+94h] [ebp-Ch]
  int nTransforms; // [esp+98h] [ebp-8h]
  bool bSplitNonInstances; // [esp+9Fh] [ebp-1h]
  CBuilderMesh *x; // [esp+A8h] [ebp+8h]
  AABB_t *xa; // [esp+A8h] [ebp+8h]
  int xb; // [esp+A8h] [ebp+8h]

  m_pHeader = this->m_pHeader;
  v89 = this;
  bSplitNonInstances = (m_pHeader->m_Flags & 0x15) == 0;
  bounds = m_pHeader->m_Bounds;
  v3 = bounds.m_vMaxBounds.z - bounds.m_vMinBounds.z;
  v4 = bounds.m_vMaxBounds.x - bounds.m_vMinBounds.x;
  v5 = (int)(float)((float)(1.0 / flSplitSize) * (float)(bounds.m_vMaxBounds.x - bounds.m_vMinBounds.x));
  v6 = bounds.m_vMaxBounds.y - bounds.m_vMinBounds.y;
  v7 = (int)(float)((float)(1.0 / flSplitSize) * (float)(bounds.m_vMaxBounds.z - bounds.m_vMinBounds.z));
  v8 = (int)(float)((float)(1.0 / flSplitSize) * (float)(bounds.m_vMaxBounds.y - bounds.m_vMinBounds.y));
  bounds.m_vMinBounds.x = bounds.m_vMinBounds.x - 0.1;
  bounds.m_vMinBounds.y = bounds.m_vMinBounds.y - 0.1;
  bounds.m_vMaxBounds.x = bounds.m_vMaxBounds.x + 0.1;
  mesh = (CBuilderMesh *)v5;
  nAdds = v8;
  pIndices = (unsigned int *)v7;
  bounds.m_vMinBounds.z = bounds.m_vMinBounds.z - 0.1;
  bounds.m_vMaxBounds.y = bounds.m_vMaxBounds.y + 0.1;
  bounds.m_vMaxBounds.z = bounds.m_vMaxBounds.z + 0.1;
  memset(&splitVolumes, 0, sizeof(splitVolumes));
  if ( v5 * v8 * v7 >= 2 )
  {
    v9 = v3 / (float)v7;
    v10 = v6 / (float)v8;
    vStep_8 = v9;
    vStep_4 = v10;
    vStep = v4 / (float)v5;
    vStart_8 = bounds.m_vMinBounds.z;
    nTransforms = 0;
    if ( v7 > 0 )
    {
      do
      {
        v11 = bounds.m_vMinBounds.y;
        vStart_4 = bounds.m_vMinBounds.y;
        for ( y = 0; y < nAdds; ++y )
        {
          v12 = bounds.m_vMinBounds.x;
          x = nullptr;
          if ( (int)mesh > 0 )
          {
            m_Size = splitVolumes.m_Size;
            m_pMemory = splitVolumes.m_Memory.m_pMemory;
            v15 = v11 + v10;
            v16 = vStart_8 + v9;
            v78 = v15;
            while ( 1 )
            {
              *(float *)&newbounds_8 = vStart_8;
              *(float *)&container = v12 + vStep;
              *((float *)&newbounds_8 + 1) = v12 + vStep;
              newbounds_16 = __PAIR64__(LODWORD(v16), LODWORD(v15));
              if ( x == (CBuilderMesh *)((char *)&mesh[-1].m_pPerDrawIndices + 3) )
                HIDWORD(newbounds_8) = LODWORD(bounds.m_vMaxBounds.x);
              if ( y == nAdds - 1 )
                *(float *)&newbounds_16 = bounds.m_vMaxBounds.y;
              if ( (unsigned int *)nTransforms == (unsigned int *)((char *)pIndices - 1) )
                HIDWORD(newbounds_16) = LODWORD(bounds.m_vMaxBounds.z);
              v17 = m_Size;
              if ( m_Size + 1 > splitVolumes.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
                  this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)&splitVolumes,
                  num: m_Size - splitVolumes.m_Memory.m_nAllocationCount + 1);
                m_Size = splitVolumes.m_Size;
                m_pMemory = splitVolumes.m_Memory.m_pMemory;
              }
              splitVolumes.m_Size = ++m_Size;
              splitVolumes.m_pElements = m_pMemory;
              if ( m_Size - v17 - 1 > 0 )
                _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 24 * (m_Size - v17 - 1));
              p_x = (_QWORD *)&m_pMemory[v17].m_vMinBounds.x;
              if ( p_x != nullptr )
              {
                *p_x = __PAIR64__(LODWORD(v11), LODWORD(v12));
                p_x[1] = newbounds_8;
                p_x[2] = newbounds_16;
              }
              LODWORD(v12) = container;
              v11 = vStart_4;
              x = (CBuilderMesh *)((char *)x + 1);
              if ( (int)x >= (int)mesh )
                break;
              v15 = v78;
              v16 = vStart_8 + v9;
            }
            v10 = vStep_4;
            v9 = vStep_8;
          }
          v11 = v11 + v10;
          vStart_4 = v11;
        }
        vStart_8 = vStart_8 + v9;
        ++nTransforms;
      }
      while ( nTransforms < (int)pIndices );
    }
  }
  else
  {
    CUtlVector<AABB_t,CUtlMemory<AABB_t,int>>::InsertBefore(this: &splitVolumes, elem: 0, src: &bounds);
  }
  if ( bSplitNonInstances )
  {
    v19 = (InstanceContainer_t *)v89->m_Meshes.m_Size;
    if ( (int)v19 > 0 )
    {
      v20 = splitVolumes.m_Size;
      nAdds = 0;
      container = v19;
      do
      {
        v21 = (CBuilderMesh *)((char *)v89->m_Meshes.m_Memory.m_pMemory + nAdds);
        mesh = v21;
        v21->m_nPerDrawIndexSets = v20;
        v22 = (20 * (unsigned __int64)(unsigned int)v20) >> 32 != 0 ? -1 : 20 * v20;
        v23 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v22, 4) ? -1 : v22 + 4);
        if ( v23 != nullptr )
        {
          v24 = v20 - 1;
          v25 = (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)(v23 + 1);
          *v23 = v20;
          for ( i = v23 + 1; v24 >= 0; --v24 )
          {
            *i = 0;
            i[1] = 0;
            i[2] = 0;
            i[3] = 0;
            i[4] = 0;
            i += 5;
          }
          v27 = v25;
        }
        else
        {
          v27 = nullptr;
        }
        v28 = v21->m_faceCenters.m_Size;
        m_pIndices = v21->m_mesh.m_pIndices;
        v21->m_pPerDrawIndices = v27;
        nFaces = v28;
        pIndices = m_pIndices;
        if ( v20 > 0 )
        {
          v30 = splitVolumes.m_Memory.m_pMemory;
          nTransforms = 0;
          xa = splitVolumes.m_Memory.m_pMemory;
          v91 = v20;
          do
          {
            v31 = (CUtlMemory<S3RGBA,int> *)((char *)v21->m_pPerDrawIndices + nTransforms);
            if ( v28 > 0 )
            {
              v32 = pIndices + 2;
              v33 = -8 - (_DWORD)pIndices;
              y = v28;
              for ( j = -8 - (_DWORD)pIndices; ; v33 = j )
              {
                v34 = (float *)((char *)&v21->m_faceCenters.m_Memory.m_pMemory->x + (unsigned int)v32 + v33);
                if ( *v34 > v30->m_vMinBounds.x && v30->m_vMaxBounds.x >= *v34 )
                {
                  v35 = v34[1];
                  if ( v35 > v30->m_vMinBounds.y && v30->m_vMaxBounds.y >= v35 )
                  {
                    v36 = v34[2];
                    if ( v36 > v30->m_vMinBounds.z && v30->m_vMaxBounds.z >= v36 )
                    {
                      v37 = v31[1].m_pMemory;
                      m_nAllocationCount = v31->m_nAllocationCount;
                      if ( (int)&v37->g > m_nAllocationCount )
                        CUtlMemory<HemiLightData_t *,int>::Grow(this: v31, num: (int)(&v37->g - m_nAllocationCount));
                      ++v31[1].m_pMemory;
                      v39 = v31->m_pMemory;
                      v40 = (char *)v31[1].m_pMemory - (char *)v37 - 1;
                      v31[1].m_nAllocationCount = (int)v31->m_pMemory;
                      if ( v40 > 0 )
                        _V_memmove(dest: &v39[(_DWORD)v37 + 1], src: &v39[(_DWORD)v37], count: 4 * v40);
                      v41 = &v31->m_pMemory[(_DWORD)v37];
                      if ( v41 != nullptr )
                        *v41 = (S3RGBA)*(v32 - 2);
                      v42 = v31[1].m_pMemory;
                      v43 = v31->m_nAllocationCount;
                      if ( (int)&v42->g > v43 )
                        CUtlMemory<HemiLightData_t *,int>::Grow(this: v31, num: (int)(&v42->g - v43));
                      ++v31[1].m_pMemory;
                      v44 = v31->m_pMemory;
                      v45 = (char *)v31[1].m_pMemory - (char *)v42 - 1;
                      v31[1].m_nAllocationCount = (int)v31->m_pMemory;
                      if ( v45 > 0 )
                        _V_memmove(dest: &v44[(_DWORD)v42 + 1], src: &v44[(_DWORD)v42], count: 4 * v45);
                      v46 = &v31->m_pMemory[(_DWORD)v42];
                      if ( v46 != nullptr )
                        *v46 = (S3RGBA)*(v32 - 1);
                      v47 = v31[1].m_pMemory;
                      v48 = v31->m_nAllocationCount;
                      if ( (int)&v47->g > v48 )
                        CUtlMemory<HemiLightData_t *,int>::Grow(this: v31, num: (int)(&v47->g - v48));
                      ++v31[1].m_pMemory;
                      v49 = v31->m_pMemory;
                      v50 = (char *)v31[1].m_pMemory - (char *)v47 - 1;
                      v31[1].m_nAllocationCount = (int)v31->m_pMemory;
                      if ( v50 > 0 )
                        _V_memmove(dest: &v49[(_DWORD)v47 + 1], src: &v49[(_DWORD)v47], count: 4 * v50);
                      v51 = (unsigned int *)&v31->m_pMemory[(_DWORD)v47];
                      if ( v51 != nullptr )
                        *v51 = *v32;
                    }
                  }
                }
                v30 = xa;
                v21 = mesh;
                v32 += 3;
                if ( --y == 0 )
                  break;
              }
              v20 = splitVolumes.m_Size;
              v28 = nFaces;
            }
            nTransforms += 20;
            ++v30;
            v52 = v91-- == 1;
            xa = v30;
          }
          while ( !v52 );
        }
        nAdds += 372;
        container = (InstanceContainer_t *)((char *)container - 1);
      }
      while ( *(float *)&container != 0.0 );
    }
  }
  v53 = (CBuilderMesh *)v89->m_InstanceContainers.m_Size;
  if ( (int)v53 > 0 )
  {
    y = 0;
    for ( mesh = v53; mesh != nullptr; mesh = (CBuilderMesh *)((char *)mesh - 1) )
    {
      v54 = splitVolumes.m_Size;
      v55 = (InstanceContainer_t *)((char *)v89->m_InstanceContainers.m_Memory.m_pMemory + y);
      v56 = 20 * splitVolumes.m_Size;
      v57 = (20 * (unsigned __int64)(unsigned int)splitVolumes.m_Size) >> 32 != 0;
      container = v55;
      v55->m_nPerDrawTransformSets = splitVolumes.m_Size;
      v58 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v56 | -v57, 4) ? -1 : (v56 | -v57) + 4);
      if ( v58 != nullptr )
      {
        v59 = v54 - 1;
        v60 = (CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *)(v58 + 1);
        *v58 = v54;
        for ( k = v58 + 1; v59 >= 0; --v59 )
        {
          *k = 0;
          k[1] = 0;
          k[2] = 0;
          k[3] = 0;
          k[4] = 0;
          k += 5;
        }
      }
      else
      {
        v60 = nullptr;
      }
      m_pTransforms = v55->m_pTransforms;
      v55->m_pPerDrawTransforms = v60;
      nTransforms = m_pTransforms->m_Size;
      if ( nTransforms != 0 )
      {
        while ( 1 )
        {
          nAdds = 0;
          if ( splitVolumes.m_Size > 0 )
          {
            v63 = splitVolumes.m_Memory.m_pMemory;
            xb = 0;
            for ( pIndices = (unsigned int *)splitVolumes.m_Size;
                  pIndices != nullptr;
                  pIndices = (unsigned int *)((char *)pIndices - 1) )
            {
              v64 = &container->m_pPerDrawTransforms[xb];
              v65 = nTransforms <= 0;
              v64->m_Size = 0;
              if ( !v65 )
              {
                v66 = 0;
                v91 = nTransforms;
                do
                {
                  v67 = container->m_pTransforms->m_Memory.m_pMemory;
                  v68 = v67[v66].m_flMatVal[0][3];
                  v69 = v67[v66].m_flMatVal[1][3];
                  v70 = v67[v66].m_flMatVal[2][3];
                  v71 = &v67[v66];
                  if ( v68 > v63->m_vMinBounds.x
                    && v63->m_vMaxBounds.x >= v68
                    && v69 > v63->m_vMinBounds.y
                    && v63->m_vMaxBounds.y >= v69
                    && v70 > v63->m_vMinBounds.z
                    && v63->m_vMaxBounds.z >= v70 )
                  {
                    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertBefore(
                      this: v64,
                      elem: v64->m_Size,
                      src: v71);
                    ++nAdds;
                  }
                  ++v66;
                  --v91;
                }
                while ( v91 != 0 );
              }
              ++xb;
              ++v63;
            }
          }
          if ( nAdds == nTransforms )
            break;
          _Warning(a1: "Missed a transform when splitting instance draw calls!  Growing bounding volumes and trying again\n");
          v72 = splitVolumes.m_Size;
          v73 = 0;
          if ( splitVolumes.m_Size >= 4 )
          {
            p_z = &splitVolumes.m_Memory.m_pMemory->m_vMaxBounds.z;
            v75 = ((unsigned int)(splitVolumes.m_Size - 4) >> 2) + 1;
            v73 = 4 * v75;
            do
            {
              *(p_z - 5) = *(p_z - 5) - 0.5;
              *(p_z - 4) = *(p_z - 4) - 0.5;
              *(p_z - 3) = *(p_z - 3) - 0.5;
              *(p_z - 2) = *(p_z - 2) + 0.5;
              *(p_z - 1) = *(p_z - 1) + 0.5;
              *p_z = *p_z + 0.5;
              p_z[1] = p_z[1] - 0.5;
              p_z[2] = p_z[2] - 0.5;
              p_z[3] = p_z[3] - 0.5;
              p_z[4] = p_z[4] + 0.5;
              p_z[5] = p_z[5] + 0.5;
              p_z[6] = p_z[6] + 0.5;
              p_z[7] = p_z[7] - 0.5;
              p_z[8] = p_z[8] - 0.5;
              p_z[9] = p_z[9] - 0.5;
              p_z[10] = p_z[10] + 0.5;
              p_z[11] = p_z[11] + 0.5;
              p_z[12] = p_z[12] + 0.5;
              p_z[13] = p_z[13] - 0.5;
              p_z[14] = p_z[14] - 0.5;
              p_z[15] = p_z[15] - 0.5;
              p_z[16] = p_z[16] + 0.5;
              p_z[17] = p_z[17] + 0.5;
              p_z[18] = p_z[18] + 0.5;
              p_z += 24;
              --v75;
            }
            while ( v75 != 0 );
          }
          if ( v73 < v72 )
          {
            v76 = &splitVolumes.m_Memory.m_pMemory[v73].m_vMaxBounds.z;
            v77 = splitVolumes.m_Size - v73;
            do
            {
              *(v76 - 5) = *(v76 - 5) - 0.5;
              *(v76 - 4) = *(v76 - 4) - 0.5;
              *(v76 - 3) = *(v76 - 3) - 0.5;
              *(v76 - 2) = *(v76 - 2) + 0.5;
              *(v76 - 1) = *(v76 - 1) + 0.5;
              *v76 = *v76 + 0.5;
              v76 += 6;
              --v77;
            }
            while ( v77 != 0 );
          }
        }
      }
      y += 16;
    }
  }
  if ( splitVolumes.m_Memory.m_nGrowSize >= 0 && splitVolumes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: splitVolumes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408A80
// Name: private: void CBVHNodeBuilder::BakeInstances(struct InstanceContainer_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BakeInstances(CBVHNodeBuilder *this, InstanceContainer_t *container)
{
  InstanceGeometry_t *m_pInstanceGeometry; // ebx
  InstanceGeometry_t *m_pNextLOD; // eax
  int v4; // edi
  CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int> > *p_m_Meshes; // esi
  CBuilderMesh *m_pMeshes; // eax
  int v7; // ecx
  int v8; // edx
  CBuilderMesh *v9; // esi
  char *v10; // eax
  int v11; // ecx
  CMesh *p_m_mesh; // ebx
  CBuilderMesh *v13; // eax
  int FirstAttributeOffset; // eax
  int v15; // ecx
  int v16; // eax
  float *v17; // esi
  float *v18; // edi
  CBuilderMesh *mesh; // [esp+Ch] [ebp-54h]
  int nTangentOffset; // [esp+10h] [ebp-50h]
  int nNormalOffset; // [esp+14h] [ebp-4Ch]
  int nPositionOffset; // [esp+18h] [ebp-48h]
  int nVertStrideBytes; // [esp+1Ch] [ebp-44h]
  unsigned int *pOutIndices; // [esp+20h] [ebp-40h]
  unsigned int *pIndices; // [esp+24h] [ebp-3Ch]
  CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int> > *v26; // [esp+28h] [ebp-38h]
  int m; // [esp+2Ch] [ebp-34h]
  int nCurrentMesh; // [esp+30h] [ebp-30h]
  int nCurrentMesha; // [esp+30h] [ebp-30h]
  int nMeshIndex; // [esp+34h] [ebp-2Ch]
  int nTransforms; // [esp+38h] [ebp-28h]
  int v32; // [esp+3Ch] [ebp-24h]
  int v33; // [esp+40h] [ebp-20h]
  int v34; // [esp+44h] [ebp-1Ch]
  int nVertices; // [esp+48h] [ebp-18h]
  int v; // [esp+4Ch] [ebp-14h]
  int va; // [esp+4Ch] [ebp-14h]
  matrix3x4_t *xform; // [esp+50h] [ebp-10h]
  int nIndices; // [esp+54h] [ebp-Ch]
  int nMeshVert; // [esp+58h] [ebp-8h]
  InstanceGeometry_t *pFinalLOD; // [esp+5Ch] [ebp-4h]

  m_pInstanceGeometry = container->m_pInstanceGeometry;
  m_pNextLOD = container->m_pInstanceGeometry->m_pNextLOD;
  v4 = 0;
  pFinalLOD = container->m_pInstanceGeometry;
  if ( m_pNextLOD != nullptr )
  {
    do
    {
      pFinalLOD = m_pNextLOD;
      m_pNextLOD = m_pNextLOD->m_pNextLOD;
    }
    while ( m_pNextLOD != nullptr );
    m_pInstanceGeometry = pFinalLOD;
  }
  p_m_Meshes = &this->m_Meshes;
  nTransforms = container->m_pTransforms->m_Size;
  nCurrentMesh = this->m_Meshes.m_Size;
  v26 = &this->m_Meshes;
  CUtlVector<CBuilderMesh,CUtlMemory<CBuilderMesh,int>>::InsertMultipleBefore(
    this: &this->m_Meshes,
    elem: nCurrentMesh,
    num: m_pInstanceGeometry->m_nMeshes);
  m = 0;
  if ( m_pInstanceGeometry->m_nMeshes > 0 )
  {
    v32 = 0;
    v33 = nCurrentMesh;
    while ( 1 )
    {
      m_pMeshes = m_pInstanceGeometry->m_pMeshes;
      v7 = *(int *)((char *)&m_pMeshes->m_mesh.m_nVertexCount + v4);
      v8 = *(int *)((char *)&m_pMeshes->m_mesh.m_nIndexCount + v4);
      v9 = &p_m_Meshes->m_Memory.m_pMemory[v33];
      v10 = (char *)m_pMeshes + v4;
      nVertices = v7;
      v11 = *((_DWORD *)v10 + 6);
      nIndices = v8;
      nVertStrideBytes = 4 * v11;
      p_m_mesh = &v9->m_mesh;
      mesh = v9;
      CMesh::AllocateMesh(
        this: &v9->m_mesh,
        nVertexCount: nTransforms * nVertices,
        nIndexCount: nTransforms * v8,
        nVertexStride: v11,
        pAttributes: *((CMeshVertexAttribute **)v10 + 3),
        nAtrributeCount: *((_DWORD *)v10 + 7));
      v13 = pFinalLOD->m_pMeshes;
      v9->m_Combo.m_nInputLayout = *(int *)((char *)&v13->m_Combo.m_nInputLayout + v4);
      v9->m_Combo.m_nIndicesPerFace = *(int *)((char *)&v13->m_Combo.m_nIndicesPerFace + v4);
      _V_memcpy(dest: &v9->m_Material, src: &pFinalLOD->m_pMeshes->m_Material.m_Material.m_szShaderVS[v4], count: 248);
      v9->m_Material.m_Material.m_bInstanced = false;
      nPositionOffset = CMesh::FindFirstAttributeOffset(this: &v9->m_mesh, nType: VERTEX_ELEMENT_POSITION);
      nNormalOffset = CMesh::FindFirstAttributeOffset(this: &v9->m_mesh, nType: VERTEX_ELEMENT_NORMAL);
      FirstAttributeOffset = CMesh::FindFirstAttributeOffset(this: &v9->m_mesh, nType: VERTEX_ELEMENT_TEXCOORD4D_7);
      v15 = 0;
      nTangentOffset = FirstAttributeOffset;
      nMeshVert = 0;
      nMeshIndex = 0;
      if ( nTransforms > 0 )
      {
        v34 = 0;
        for ( nCurrentMesha = nTransforms; nCurrentMesha != 0; --nCurrentMesha )
        {
          xform = &container->m_pTransforms->m_Memory.m_pMemory[v34];
          pOutIndices = v9->m_mesh.m_pIndices;
          v16 = 0;
          pIndices = *(unsigned int **)((char *)&pFinalLOD->m_pMeshes->m_mesh.m_pIndices + v4);
          v = 0;
          if ( nIndices > 0 )
          {
            do
            {
              pOutIndices[v15] = nMeshVert + pIndices[v16];
              v16 = v + 1;
              ++v15;
              v = v16;
            }
            while ( v16 < nIndices );
            nMeshIndex = v15;
          }
          va = 0;
          if ( nVertices > 0 )
          {
            do
            {
              v17 = &p_m_mesh->m_pVerts[nMeshVert * p_m_mesh->m_nVertexStrideFloats];
              v18 = &(*(float **)((char *)&pFinalLOD->m_pMeshes->m_mesh.m_pVerts + v4))[va
                                                                                      * *(int *)((char *)&pFinalLOD->m_pMeshes->m_mesh.m_nVertexStrideFloats
                                                                                               + v4)];
              _V_memcpy(dest: v17, src: v18, count: nVertStrideBytes);
              if ( nPositionOffset != -1 )
                VectorTransform(in1: &v18[nPositionOffset], in2: xform, out: &v17[nPositionOffset]);
              if ( nNormalOffset != -1 )
                VectorRotate(in1: &v18[nNormalOffset], in2: xform, out: &v17[nNormalOffset]);
              if ( nTangentOffset != -1 )
                VectorRotate(in1: &v18[nTangentOffset], in2: xform, out: &v17[nTangentOffset]);
              ++nMeshVert;
              v4 = v32;
              ++va;
            }
            while ( va < nVertices );
            v9 = mesh;
            v15 = nMeshIndex;
          }
          ++v34;
        }
      }
      ++v33;
      v4 += 372;
      ++m;
      v32 = v4;
      if ( m >= pFinalLOD->m_nMeshes )
        break;
      p_m_Meshes = v26;
      m_pInstanceGeometry = pFinalLOD;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408CF0
// Name: private: void CBVHNodeBuilder::BakeInstances(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BakeInstances(CBVHNodeBuilder *this, float flMinDistance)
{
  int v3; // ebx
  float v4; // xmm0_4
  int v5; // edx
  InstanceContainer_t *m_pMemory; // esi
  int v7; // ecx
  int v8; // eax
  InstanceContainer_t *v9; // esi
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *m_pTransforms; // esi
  int v11; // [esp+8h] [ebp-4h]

  v3 = this->m_InstanceContainers.m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = flMinDistance;
    v5 = 16 * v3;
    v11 = 16 * v3;
    do
    {
      m_pMemory = this->m_InstanceContainers.m_Memory.m_pMemory;
      v7 = *(int *)((char *)&m_pMemory->m_pInstanceGeometry + v5);
      v8 = *(_DWORD *)(v7 + 20);
      v9 = (InstanceContainer_t *)((char *)m_pMemory + v5);
      if ( v8 != 0 )
      {
        while ( v4 > *(float *)(v7 + 16) )
        {
          v7 = v8;
          v8 = *(_DWORD *)(v8 + 20);
          if ( v8 == 0 )
            goto LABEL_6;
        }
      }
      else
      {
LABEL_6:
        if ( v4 > *(float *)(v7 + 16) )
        {
          CBVHNodeBuilder::BakeInstances(this, container: v9);
          m_pTransforms = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)v9->m_pTransforms;
          if ( m_pTransforms != nullptr )
          {
            CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: m_pTransforms);
            free(pMem: m_pTransforms);
          }
          if ( this->m_InstanceContainers.m_Size - v3 - 1 > 0 )
            _V_memmove(
              dest: (char *)this->m_InstanceContainers.m_Memory.m_pMemory + v11,
              src: (char *)&this->m_InstanceContainers.m_Memory.m_pMemory[1] + v11,
              count: 16 * (this->m_InstanceContainers.m_Size - v3 - 1));
          --this->m_InstanceContainers.m_Size;
          v4 = flMinDistance;
          v5 = v11;
        }
      }
      v5 -= 16;
      --v3;
      v11 = v5;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408DA0
// Name: private: void CBVHNodeBuilder::BakeFromChildren(struct D3DParams_t __near &,char const __near *,int,int,float,class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BakeFromChildren(
        CBVHNodeBuilder *this,
        D3DParams_t *params,
        const char *pMapName,
        int nWidth,
        int nHeight,
        float flGutterSize,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp)
{
  int v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v13; // eax
  int *v14; // edi
  int v15; // edi
  int v16; // eax
  int *v17; // ecx
  int v18; // eax
  int *v19; // edi
  char pNormalName[260]; // [esp+Ch] [ebp-208h] BYREF
  char pAlbedoName[260]; // [esp+110h] [ebp-104h] BYREF
  int nEntryAlbedo; // [esp+220h] [ebp+Ch]
  int nEntryNormal; // [esp+234h] [ebp+20h]

  V_snprintf(
    pDest: pAlbedoName,
    maxLen: 260,
    pFormat: "materials\\%s\\node%04d_bakedalbedo.vtf",
    pMapName,
    g_nNodeCounter);
  V_snprintf(
    pDest: pNormalName,
    maxLen: 260,
    pFormat: "materials\\%s\\node%04d_bakednormal.vtf",
    pMapName,
    g_nNodeCounter);
  nEntryAlbedo = CResourceDictionaryBuilder::AddTextureToDictionary(
                   this: Dictionary,
                   pTextureName: pAlbedoName,
                   pVTFTexture: nullptr,
                   fp);
  v9 = CResourceDictionaryBuilder::AddTextureToDictionary(
         this: Dictionary,
         pTextureName: pNormalName,
         pVTFTexture: nullptr,
         fp);
  m_Size = this->m_ResourceEntryList.m_Size;
  nEntryNormal = v9;
  m_nAllocationCount = this->m_ResourceEntryList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_ResourceEntryList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ResourceEntryList.m_Size;
  m_pMemory = this->m_ResourceEntryList.m_Memory.m_pMemory;
  v13 = this->m_ResourceEntryList.m_Size - m_Size - 1;
  this->m_ResourceEntryList.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
  v14 = &this->m_ResourceEntryList.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = nEntryAlbedo;
  v15 = this->m_ResourceEntryList.m_Size;
  v16 = this->m_ResourceEntryList.m_Memory.m_nAllocationCount;
  if ( v15 + 1 > v16 )
    CUtlMemory<HemiLightData_t *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_ResourceEntryList,
      num: v15 - v16 + 1);
  ++this->m_ResourceEntryList.m_Size;
  v17 = this->m_ResourceEntryList.m_Memory.m_pMemory;
  v18 = this->m_ResourceEntryList.m_Size - v15 - 1;
  this->m_ResourceEntryList.m_pElements = v17;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v15 + 1], src: &v17[v15], count: 4 * v18);
  v19 = &this->m_ResourceEntryList.m_Memory.m_pMemory[v15];
  if ( v19 != nullptr )
    *v19 = nEntryNormal;
}

//------------------------------------------------------------------------------
// Address: 0x00408EE0
// Name: private: void CBVHNodeBuilder::AddUniqueTextures(class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::AddUniqueTextures(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp)
{
  CBuilderMesh *v3; // ebx
  CUtlMemory<S3RGBA,int> *p_m_ResourceEntryList; // esi
  TextureData_t **m_ppTextures; // ebx
  int v6; // eax
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v9; // ecx
  int v10; // eax
  int *v11; // eax
  CBVHNodeBuilder *v12; // [esp+0h] [ebp-18h]
  CBuilderMesh *mesh; // [esp+4h] [ebp-14h]
  int nEntry; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int t; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]

  v12 = this;
  if ( this->m_Meshes.m_Size > 0 )
  {
    v17 = 0;
    m_Size = this->m_Meshes.m_Size;
    do
    {
      v3 = &this->m_Meshes.m_Memory.m_pMemory[v17];
      t = 0;
      mesh = v3;
      if ( v3->m_Material.m_nTextures > 0 )
      {
        p_m_ResourceEntryList = (CUtlMemory<S3RGBA,int> *)&this->m_ResourceEntryList;
        m_ppTextures = v3->m_Material.m_ppTextures;
        do
        {
          v6 = CResourceDictionaryBuilder::AddTextureToDictionary(
                 this: Dictionary,
                 pTextureName: (*m_ppTextures)->m_szVTFName,
                 pVTFTexture: nullptr,
                 fp);
          m_pMemory = p_m_ResourceEntryList[1].m_pMemory;
          nEntry = v6;
          m_nAllocationCount = p_m_ResourceEntryList->m_nAllocationCount;
          if ( (int)&m_pMemory->g > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: p_m_ResourceEntryList,
              num: (int)(&m_pMemory->g - m_nAllocationCount));
          ++p_m_ResourceEntryList[1].m_pMemory;
          v9 = p_m_ResourceEntryList->m_pMemory;
          v10 = (char *)p_m_ResourceEntryList[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_ResourceEntryList[1].m_nAllocationCount = (int)p_m_ResourceEntryList->m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 4 * v10);
          v11 = (int *)&p_m_ResourceEntryList->m_pMemory[(_DWORD)m_pMemory];
          if ( v11 != nullptr )
            *v11 = nEntry;
          ++m_ppTextures;
          ++t;
        }
        while ( t < mesh->m_Material.m_nTextures );
        this = v12;
      }
      ++v17;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408FD0
// Name: private: void CBVHNodeBuilder::BuildTextures(struct D3DParams_t __near &,char const __near *,int,int,float,class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildTextures(
        CBVHNodeBuilder *this,
        D3DParams_t *params,
        const char *pMapName,
        unsigned int Width,
        unsigned int Height,
        float flGutterSize,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp)
{
  CBVHNodeBuilder *v9; // edi
  HRESULT (__stdcall *SetRenderTarget)(IDirect3DDevice9 *, unsigned int, IDirect3DSurface9 *); // eax
  IDirect3DDevice9 *v11; // eax
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v12; // ebx
  bool v13; // cc
  CBuilderAtlas *v14; // ebx
  int v15; // edi
  IVTFTexture *v16; // edi
  int v17; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v21; // eax
  int *v22; // ebx
  IDirect3DDevice9 *m_pd3dDevice; // [esp+C0h] [ebp-150h]
  IDirect3DSurface9 *m_pRTSurface; // [esp+C8h] [ebp-148h]
  char pTexName[260]; // [esp+D8h] [ebp-138h] BYREF
  _D3DVIEWPORT9 vp; // [esp+1DCh] [ebp-34h] BYREF
  Vector2D TextureSize; // [esp+1F4h] [ebp-1Ch]
  IVTFTexture *pVTFTexture; // [esp+1FCh] [ebp-14h]
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *pAtlasVector; // [esp+200h] [ebp-10h]
  int s; // [esp+204h] [ebp-Ch]
  int nTextures; // [esp+208h] [ebp-8h]
  CBVHNodeBuilder *v32; // [esp+20Ch] [ebp-4h]
  int a; // [esp+218h] [ebp+8h]
  int Widtha; // [esp+220h] [ebp+10h]
  int nAtlasTextures; // [esp+224h] [ebp+14h]

  m_pRTSurface = params->m_pRTSurface;
  v9 = this;
  m_pd3dDevice = params->m_pd3dDevice;
  SetRenderTarget = params->m_pd3dDevice->SetRenderTarget;
  v32 = this;
  SetRenderTarget(this: m_pd3dDevice, a2: 0, a3: m_pRTSurface);
  params->m_pd3dDevice->SetDepthStencilSurface(this: params->m_pd3dDevice, a2: nullptr);
  params->m_pd3dDevice->SetVertexShader(this: params->m_pd3dDevice, a2: params->m_pVS);
  params->m_pd3dDevice->SetPixelShader(this: params->m_pd3dDevice, a2: params->m_pPS);
  v11 = params->m_pd3dDevice;
  vp.X = 0;
  vp.Y = 0;
  vp.Height = Height;
  vp.MinZ = 0.0;
  vp.Width = Width;
  vp.MaxZ = 1.0;
  v11->SetViewport(this: v11, a2: &vp);
  params->m_pd3dDevice->SetRenderState(this: params->m_pd3dDevice, a2: D3DRS_ZENABLE, a3: 0);
  params->m_pd3dDevice->SetRenderState(this: params->m_pd3dDevice, a2: D3DRS_ZFUNC, a3: 8u);
  params->m_pd3dDevice->SetRenderState(this: params->m_pd3dDevice, a2: D3DRS_CULLMODE, a3: 1u);
  params->m_pd3dDevice->SetVertexDeclaration(this: params->m_pd3dDevice, a2: params->m_pDecl);
  params->m_pd3dDevice->SetSamplerState(this: params->m_pd3dDevice, a2: 0, a3: D3DSAMP_ADDRESSU, a4: 1u);
  params->m_pd3dDevice->SetSamplerState(this: params->m_pd3dDevice, a2: 0, a3: D3DSAMP_ADDRESSV, a4: 1u);
  params->m_pd3dDevice->SetSamplerState(this: params->m_pd3dDevice, a2: 0, a3: D3DSAMP_MAGFILTER, a4: 2u);
  params->m_pd3dDevice->SetSamplerState(this: params->m_pd3dDevice, a2: 0, a3: D3DSAMP_MINFILTER, a4: 2u);
  params->m_pd3dDevice->SetSamplerState(this: params->m_pd3dDevice, a2: 0, a3: D3DSAMP_MIPFILTER, a4: 2u);
  params->m_pd3dDevice->BeginScene(this: params->m_pd3dDevice);
  TextureSize.x = (float)(int)Width;
  TextureSize.y = (float)(int)Height;
  nAtlasTextures = 0;
  s = 0;
  if ( v9->m_nAtlasTables > 0 )
  {
    Widtha = 0;
    do
    {
      v12 = &v9->m_pAtlasTable[Widtha];
      a = 0;
      v13 = v12->m_Size <= 0;
      pAtlasVector = v12;
      if ( !v13 )
      {
        while ( 1 )
        {
          ((void (__stdcall *)(IDirect3DDevice9 *, _DWORD, _DWORD, int, void *, int, _DWORD))params->m_pd3dDevice->Clear)(
            a1: params->m_pd3dDevice,
            a2: 0,
            a3: 0,
            a4: 1,
            a5: &unk_FF0000,
            a6: 1065353216,
            a7: 0);
          v14 = v12->m_Memory.m_pMemory[a];
          if ( v14->m_format == IMAGE_FORMAT_UNKNOWN )
            _Msg(a1: "Node: %d, flags %d, Unknown format!\n", v9->m_pHeader->m_nID, v9->m_pHeader->m_Flags);
          v15 = 0;
          nTextures = v14->m_ContributingTextures.m_Size;
          if ( nTextures > 0 )
          {
            do
              CBVHNodeBuilder::DrawTexture(
                this: v32,
                pd3dDevice: params->m_pd3dDevice,
                pTexture: v14->m_ContributingTextures.m_Memory.m_pMemory[v15++],
                TextureSize,
                flGutterSize);
            while ( v15 < nTextures );
          }
          v16 = CompressTexture(
                  a1: v14->m_format,
                  a2: v15,
                  pd3dDevice: params->m_pd3dDevice,
                  pInputTex: params->m_pRenderTarget,
                  format: v14->m_format);
          pVTFTexture = v16;
          V_snprintf(
            pDest: pTexName,
            maxLen: 260,
            pFormat: "materials\\%s\\node%04d_atlas%02d.vtf",
            pMapName,
            g_nNodeCounter,
            nAtlasTextures);
          v17 = CResourceDictionaryBuilder::AddTextureToDictionary(
                  this: Dictionary,
                  pTextureName: pTexName,
                  pVTFTexture: v16,
                  fp);
          v9 = v32;
          m_Size = v32->m_ResourceEntryList.m_Size;
          nTextures = v17;
          m_nAllocationCount = v32->m_ResourceEntryList.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v32->m_ResourceEntryList,
              num: m_Size - m_nAllocationCount + 1);
          ++v9->m_ResourceEntryList.m_Size;
          m_pMemory = v9->m_ResourceEntryList.m_Memory.m_pMemory;
          v21 = v9->m_ResourceEntryList.m_Size - m_Size - 1;
          v9->m_ResourceEntryList.m_pElements = m_pMemory;
          if ( v21 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v21);
          v22 = &v9->m_ResourceEntryList.m_Memory.m_pMemory[m_Size];
          if ( v22 != nullptr )
            *v22 = nTextures;
          DestroyVTFTexture(pTexture: pVTFTexture);
          ++nAtlasTextures;
          if ( ++a >= pAtlasVector->m_Size )
            break;
          v12 = pAtlasVector;
        }
      }
      ++Widtha;
      ++s;
    }
    while ( s < v9->m_nAtlasTables );
  }
  params->m_pd3dDevice->EndScene(this: params->m_pd3dDevice);
}

//------------------------------------------------------------------------------
// Address: 0x004092F0
// Name: private: void CBVHNodeBuilder::BuildMaterials(class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildMaterials(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp)
{
  CUtlMemory<S3RGBA,int> *p_m_ResourceEntryList; // esi
  int v4; // ebx
  BuilderMaterial_t *p_m_Material; // edi
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v8; // ecx
  int v9; // eax
  int *v10; // eax
  int iEntry; // [esp+0h] [ebp-10h]
  CBVHNodeBuilder *v12; // [esp+4h] [ebp-Ch]
  int m_Size; // [esp+8h] [ebp-8h]
  bool bWriteOut; // [esp+Fh] [ebp-1h] BYREF

  v12 = this;
  if ( this->m_Meshes.m_Size > 0 )
  {
    p_m_ResourceEntryList = (CUtlMemory<S3RGBA,int> *)&this->m_ResourceEntryList;
    v4 = 0;
    m_Size = this->m_Meshes.m_Size;
    while ( 1 )
    {
      p_m_Material = &this->m_Meshes.m_Memory.m_pMemory[v4].m_Material;
      bWriteOut = false;
      iEntry = CResourceDictionaryBuilder::AddUniqueMaterial(
                 this: Dictionary,
                 pWriteOut: &bWriteOut,
                 material: &p_m_Material->m_Material,
                 nFlags: 2u,
                 nSizeBytes: 0xA4u,
                 pName: "material");
      if ( bWriteOut )
        fwrite(buffer: p_m_Material, size: 0xA4u, count: 1u, stream: fp);
      m_pMemory = p_m_ResourceEntryList[1].m_pMemory;
      m_nAllocationCount = p_m_ResourceEntryList->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: p_m_ResourceEntryList,
          num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++p_m_ResourceEntryList[1].m_pMemory;
      v8 = p_m_ResourceEntryList->m_pMemory;
      v9 = (char *)p_m_ResourceEntryList[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_ResourceEntryList[1].m_nAllocationCount = (int)p_m_ResourceEntryList->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
      v10 = (int *)&p_m_ResourceEntryList->m_pMemory[(_DWORD)m_pMemory];
      if ( v10 != nullptr )
        *v10 = iEntry;
      ++v4;
      if ( --m_Size == 0 )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004093D0
// Name: private: void CBVHNodeBuilder::BuildLights(class CWorldLighting __near *,class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildLights(
        CBVHNodeBuilder *this,
        CWorldLighting *pWorldLighting,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp)
{
  BVHNodeHeader_t *m_pHeader; // eax
  bool v5; // zf
  CWorldLighting *v6; // edx
  int m_Size; // edi
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  char *v11; // ebx
  float v12; // eax
  float x; // xmm4_4
  int v14; // xmm0_4
  float y; // xmm3_4
  float z; // xmm2_4
  int v17; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_pointLights; // esi
  S3RGBA *m_pMemory; // ecx
  int v21; // eax
  S3RGBA *v22; // edi
  double v23; // xmm1_8
  float v24; // xmm6_4
  float v25; // xmm1_4
  double v26; // xmm1_8
  float v27; // xmm1_4
  double v28; // xmm1_8
  float v29; // xmm3_4
  float v30; // xmm2_4
  double v31; // xmm0_8
  float v32; // xmm0_4
  double v33; // xmm0_8
  double v34; // xmm0_8
  CHemiLight *v35; // edx
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  int v39; // xmm0_4
  CBVHNodeBuilder *v40; // esi
  int v41; // edi
  int v42; // eax
  HemiLightData_t *v43; // ebx
  HemiLightData_t **v44; // ecx
  int v45; // eax
  HemiLightData_t **v46; // edi
  double v47; // xmm2_8
  float v48; // xmm6_4
  float v49; // xmm2_4
  double v50; // xmm2_8
  float v51; // xmm2_4
  double v52; // xmm2_8
  float v53; // xmm3_4
  float v54; // xmm4_4
  double v55; // xmm0_8
  float v56; // xmm0_4
  double v57; // xmm0_8
  double v58; // xmm0_8
  float *v59; // eax
  float v60; // xmm1_4
  float v61; // xmm3_4
  float v62; // xmm4_4
  int v63; // xmm0_4
  CBVHNodeBuilder *v64; // esi
  int v65; // edi
  int v66; // eax
  SpotLightData_t *v67; // ebx
  SpotLightData_t **v68; // ecx
  int v69; // eax
  SpotLightData_t **v70; // edi
  double v71; // xmm2_8
  float v72; // xmm6_4
  float v73; // xmm2_4
  double v74; // xmm2_8
  float v75; // xmm2_4
  double v76; // xmm2_8
  float v77; // xmm3_4
  float v78; // xmm4_4
  double v79; // xmm0_8
  float v80; // xmm0_4
  double v81; // xmm0_8
  double v82; // xmm0_8
  BVHNodeHeader_t *v83; // eax
  double v84; // xmm0_8
  float v85; // xmm0_4
  double v86; // xmm0_8
  float v87; // xmm0_4
  double v88; // xmm0_8
  float v89; // xmm0_4
  BVHNodeHeader_t *v90; // eax
  double v91; // xmm0_8
  float v92; // xmm0_4
  double v93; // xmm0_8
  float v94; // xmm0_4
  double v95; // xmm0_8
  CBVHNodeBuilder *v96; // ebx
  int v97; // edx
  int v98; // eax
  int v99; // eax
  int v100; // edi
  int v101; // eax
  int *v102; // ecx
  int v103; // eax
  int *v104; // edi
  int j; // esi
  int v106; // eax
  int v107; // edi
  int v108; // eax
  int *v109; // ecx
  int v110; // eax
  int *v111; // edi
  int k; // esi
  int v113; // eax
  int v114; // edi
  int v115; // eax
  int *v116; // ecx
  int v117; // eax
  int *v118; // edi
  int m; // esi
  CUtlBuffer outBuffer; // [esp+0h] [ebp-88h] BYREF
  AABB_t localBounds; // [esp+30h] [ebp-58h]
  int nPointLights; // [esp+48h] [ebp-40h] BYREF
  CBVHNodeBuilder *v123; // [esp+4Ch] [ebp-3Ch]
  AABB_t lightBounds; // [esp+50h] [ebp-38h]
  int nSpotLights; // [esp+68h] [ebp-20h] BYREF
  int nHemiLights; // [esp+6Ch] [ebp-1Ch] BYREF
  int i; // [esp+70h] [ebp-18h]
  int flRadius; // [esp+74h] [ebp-14h]
  Vector vOrigin; // [esp+78h] [ebp-10h]
  int v130; // [esp+84h] [ebp-4h]
  int nEntry; // [esp+90h] [ebp+8h]
  int nEntrya; // [esp+90h] [ebp+8h]
  int nEntryb; // [esp+90h] [ebp+8h]

  m_pHeader = this->m_pHeader;
  v5 = (this->m_pHeader->m_Flags & 0x10) == 0;
  v123 = this;
  if ( v5 )
  {
    v6 = pWorldLighting;
    nHemiLights = pWorldLighting->m_hemiLights.m_Size;
    m_Size = pWorldLighting->m_pointLights.m_Size;
    nSpotLights = pWorldLighting->m_spotLights.m_Size;
    nPointLights = m_Size;
    localBounds = m_pHeader->m_Bounds;
    v8 = 3.4028235e38;
    lightBounds.m_vMinBounds.x = 3.4028235e38;
    lightBounds.m_vMinBounds.y = 3.4028235e38;
    v9 = -3.4028235e38;
    v10 = -3.4028235e38;
    lightBounds.m_vMinBounds.z = 3.4028235e38;
    lightBounds.m_vMaxBounds.x = -3.4028235e38;
    lightBounds.m_vMaxBounds.y = -3.4028235e38;
    lightBounds.m_vMaxBounds.z = -3.4028235e38;
    *(float *)&i = 0.0;
    if ( m_Size > 0 )
    {
      v130 = 0;
      do
      {
        v11 = (char *)v6->m_pointLights.m_Memory.m_pMemory + v130;
        v12 = *((float *)v11 + 2);
        *(_QWORD *)&vOrigin.x = *(_QWORD *)v11;
        x = vOrigin.x;
        v14 = *((int *)v11 + 6);
        vOrigin.z = v12;
        flRadius = v14;
        if ( vOrigin.x > localBounds.m_vMinBounds.x )
        {
          y = vOrigin.y;
          if ( vOrigin.y > localBounds.m_vMinBounds.y )
          {
            z = vOrigin.z;
            if ( vOrigin.z > localBounds.m_vMinBounds.z
              && localBounds.m_vMaxBounds.x >= vOrigin.x
              && localBounds.m_vMaxBounds.y >= vOrigin.y
              && localBounds.m_vMaxBounds.z >= vOrigin.z )
            {
              v17 = this->m_pointLights.m_Size;
              m_nAllocationCount = this->m_pointLights.m_Memory.m_nAllocationCount;
              p_m_pointLights = (CUtlMemory<S3RGBA,int> *)&this->m_pointLights;
              if ( v17 + 1 > m_nAllocationCount )
              {
                CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_pointLights, num: v17 - m_nAllocationCount + 1);
                z = vOrigin.z;
                y = vOrigin.y;
                x = vOrigin.x;
                v14 = flRadius;
              }
              ++p_m_pointLights[1].m_pMemory;
              m_pMemory = p_m_pointLights->m_pMemory;
              v21 = (int)p_m_pointLights[1].m_pMemory - v17 - 1;
              p_m_pointLights[1].m_nAllocationCount = (int)p_m_pointLights->m_pMemory;
              if ( v21 > 0 )
              {
                _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 4 * v21);
                z = vOrigin.z;
                y = vOrigin.y;
                x = vOrigin.x;
                v14 = flRadius;
              }
              v22 = &p_m_pointLights->m_pMemory[v17];
              if ( v22 != nullptr )
                *v22 = (S3RGBA)v11;
              v23 = (float)(x - *(float *)&v14);
              v24 = z - *(float *)&v14;
              if ( v23 > lightBounds.m_vMinBounds.x )
                v23 = lightBounds.m_vMinBounds.x;
              v25 = v23;
              lightBounds.m_vMinBounds.x = v25;
              v26 = (float)(y - *(float *)&v14);
              if ( v26 > lightBounds.m_vMinBounds.y )
                v26 = lightBounds.m_vMinBounds.y;
              v27 = v26;
              lightBounds.m_vMinBounds.y = v27;
              v28 = v24;
              if ( v24 > (double)lightBounds.m_vMinBounds.z )
                v28 = lightBounds.m_vMinBounds.z;
              v8 = v28;
              v29 = y + *(float *)&v14;
              v30 = z + *(float *)&v14;
              v31 = (float)(x + *(float *)&v14);
              lightBounds.m_vMinBounds.z = v8;
              if ( v31 < lightBounds.m_vMaxBounds.x )
                v31 = lightBounds.m_vMaxBounds.x;
              v32 = v31;
              lightBounds.m_vMaxBounds.x = v32;
              v33 = v29;
              if ( v29 < (double)lightBounds.m_vMaxBounds.y )
                v33 = lightBounds.m_vMaxBounds.y;
              v9 = v33;
              v34 = v30;
              lightBounds.m_vMaxBounds.y = v9;
              if ( v30 < (double)lightBounds.m_vMaxBounds.z )
                v34 = lightBounds.m_vMaxBounds.z;
              m_Size = nPointLights;
              v6 = pWorldLighting;
              this = v123;
              v10 = v34;
              lightBounds.m_vMaxBounds.z = v10;
            }
          }
        }
        v130 += 56;
        ++i;
      }
      while ( i < m_Size );
    }
    *(float *)&flRadius = 0.0;
    if ( nHemiLights > 0 )
    {
      v130 = 0;
      do
      {
        v35 = v6->m_hemiLights.m_Memory.m_pMemory;
        v37 = *(float *)((char *)&v35->m_instData.m_vTransform1.w + v130);
        v38 = *(float *)((char *)&v35->m_instData.m_vTransform2.w + v130);
        v39 = *(int *)((char *)&v35->m_instData.m_vColorNRadius.w + v130);
        vOrigin.x = *(float *)((char *)&v35->m_instData.m_vTransform0.w + v130);
        v36 = vOrigin.x;
        vOrigin.y = v37;
        vOrigin.z = v38;
        i = v39;
        if ( vOrigin.x > localBounds.m_vMinBounds.x
          && v37 > localBounds.m_vMinBounds.y
          && v38 > localBounds.m_vMinBounds.z
          && localBounds.m_vMaxBounds.x >= vOrigin.x
          && localBounds.m_vMaxBounds.y >= v37
          && localBounds.m_vMaxBounds.z >= v38 )
        {
          v40 = v123;
          v41 = v123->m_hemiLights.m_Size;
          v42 = v123->m_hemiLights.m_Memory.m_nAllocationCount;
          v43 = (HemiLightData_t *)((char *)&pWorldLighting->m_hemiLights.m_Memory.m_pMemory->m_instData + v130);
          if ( v41 + 1 > v42 )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v123->m_hemiLights,
              num: v41 - v42 + 1);
            v36 = vOrigin.x;
            v39 = i;
            v37 = vOrigin.y;
            v38 = vOrigin.z;
          }
          ++v123->m_hemiLights.m_Size;
          v44 = v40->m_hemiLights.m_Memory.m_pMemory;
          v45 = v40->m_hemiLights.m_Size - v41 - 1;
          v40->m_hemiLights.m_pElements = v44;
          if ( v45 > 0 )
          {
            _V_memmove(dest: &v44[v41 + 1], src: &v44[v41], count: 4 * v45);
            v36 = vOrigin.x;
            v39 = i;
            v37 = vOrigin.y;
            v38 = vOrigin.z;
          }
          v46 = &v40->m_hemiLights.m_Memory.m_pMemory[v41];
          if ( v46 != nullptr )
            *v46 = v43;
          v47 = (float)(v36 - *(float *)&v39);
          v48 = v38 - *(float *)&v39;
          if ( v47 > lightBounds.m_vMinBounds.x )
            v47 = lightBounds.m_vMinBounds.x;
          v49 = v47;
          lightBounds.m_vMinBounds.x = v49;
          v50 = (float)(v37 - *(float *)&v39);
          if ( v50 > lightBounds.m_vMinBounds.y )
            v50 = lightBounds.m_vMinBounds.y;
          v51 = v50;
          lightBounds.m_vMinBounds.y = v51;
          v52 = v48;
          if ( v48 > (double)lightBounds.m_vMinBounds.z )
            v52 = lightBounds.m_vMinBounds.z;
          v53 = v37 + *(float *)&v39;
          v54 = v38 + *(float *)&v39;
          v55 = (float)(v36 + *(float *)&v39);
          v8 = v52;
          lightBounds.m_vMinBounds.z = v8;
          if ( v55 < lightBounds.m_vMaxBounds.x )
            v55 = lightBounds.m_vMaxBounds.x;
          v56 = v55;
          lightBounds.m_vMaxBounds.x = v56;
          v57 = v53;
          if ( v53 < (double)lightBounds.m_vMaxBounds.y )
            v57 = lightBounds.m_vMaxBounds.y;
          v9 = v57;
          v58 = v54;
          lightBounds.m_vMaxBounds.y = v9;
          if ( v54 < (double)lightBounds.m_vMaxBounds.z )
            v58 = lightBounds.m_vMaxBounds.z;
          v10 = v58;
          lightBounds.m_vMaxBounds.z = v10;
        }
        v130 += 76;
        v6 = pWorldLighting;
        ++flRadius;
      }
      while ( flRadius < nHemiLights );
      this = v123;
    }
    *(float *)&flRadius = 0.0;
    if ( nSpotLights > 0 )
    {
      v130 = 0;
      while ( 1 )
      {
        v59 = (float *)((char *)&v6->m_spotLights.m_Memory.m_pMemory->m_instData.m_vTransform0.x + v130);
        v61 = v59[7];
        v62 = v59[11];
        v63 = *((int *)v59 + 15);
        vOrigin.x = v59[3];
        v60 = vOrigin.x;
        vOrigin.y = v61;
        vOrigin.z = v62;
        i = v63;
        if ( vOrigin.x > localBounds.m_vMinBounds.x
          && v61 > localBounds.m_vMinBounds.y
          && v62 > localBounds.m_vMinBounds.z
          && localBounds.m_vMaxBounds.x >= vOrigin.x
          && localBounds.m_vMaxBounds.y >= v61
          && localBounds.m_vMaxBounds.z >= v62 )
        {
          v64 = v123;
          v65 = v123->m_spotLights.m_Size;
          v66 = v123->m_spotLights.m_Memory.m_nAllocationCount;
          v67 = (SpotLightData_t *)((char *)&pWorldLighting->m_spotLights.m_Memory.m_pMemory->m_instData + v130);
          if ( v65 + 1 > v66 )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v123->m_spotLights,
              num: v65 - v66 + 1);
            v60 = vOrigin.x;
            v61 = vOrigin.y;
            v63 = i;
            v62 = vOrigin.z;
          }
          ++v123->m_spotLights.m_Size;
          v68 = v64->m_spotLights.m_Memory.m_pMemory;
          v69 = v64->m_spotLights.m_Size - v65 - 1;
          v64->m_spotLights.m_pElements = v68;
          if ( v69 > 0 )
          {
            _V_memmove(dest: &v68[v65 + 1], src: &v68[v65], count: 4 * v69);
            v60 = vOrigin.x;
            v61 = vOrigin.y;
            v63 = i;
            v62 = vOrigin.z;
          }
          v70 = &v64->m_spotLights.m_Memory.m_pMemory[v65];
          if ( v70 != nullptr )
            *v70 = v67;
          v71 = (float)(v60 - *(float *)&v63);
          v72 = v62 - *(float *)&v63;
          if ( v71 > lightBounds.m_vMinBounds.x )
            v71 = lightBounds.m_vMinBounds.x;
          v73 = v71;
          lightBounds.m_vMinBounds.x = v73;
          v74 = (float)(v61 - *(float *)&v63);
          if ( v74 > lightBounds.m_vMinBounds.y )
            v74 = lightBounds.m_vMinBounds.y;
          v75 = v74;
          lightBounds.m_vMinBounds.y = v75;
          v76 = v72;
          if ( v72 > (double)lightBounds.m_vMinBounds.z )
            v76 = lightBounds.m_vMinBounds.z;
          v77 = v61 + *(float *)&v63;
          v78 = v62 + *(float *)&v63;
          v79 = (float)(v60 + *(float *)&v63);
          v8 = v76;
          lightBounds.m_vMinBounds.z = v8;
          if ( v79 < lightBounds.m_vMaxBounds.x )
            v79 = lightBounds.m_vMaxBounds.x;
          v80 = v79;
          lightBounds.m_vMaxBounds.x = v80;
          v81 = v77;
          if ( v77 < (double)lightBounds.m_vMaxBounds.y )
            v81 = lightBounds.m_vMaxBounds.y;
          v9 = v81;
          v82 = v78;
          lightBounds.m_vMaxBounds.y = v9;
          if ( v78 < (double)lightBounds.m_vMaxBounds.z )
            v82 = lightBounds.m_vMaxBounds.z;
          v10 = v82;
          lightBounds.m_vMaxBounds.z = v10;
        }
        v130 += 84;
        if ( ++flRadius >= nSpotLights )
          break;
        v6 = pWorldLighting;
      }
      this = v123;
    }
    v83 = this->m_pHeader;
    v84 = lightBounds.m_vMinBounds.x;
    if ( lightBounds.m_vMinBounds.x > (double)this->m_pHeader->m_Bounds.m_vMinBounds.x )
      v84 = this->m_pHeader->m_Bounds.m_vMinBounds.x;
    v85 = v84;
    v83->m_Bounds.m_vMinBounds.x = v85;
    v86 = lightBounds.m_vMinBounds.y;
    if ( lightBounds.m_vMinBounds.y > (double)v83->m_Bounds.m_vMinBounds.y )
      v86 = v83->m_Bounds.m_vMinBounds.y;
    v87 = v86;
    v83->m_Bounds.m_vMinBounds.y = v87;
    v88 = v8;
    if ( v8 > (double)v83->m_Bounds.m_vMinBounds.z )
      v88 = v83->m_Bounds.m_vMinBounds.z;
    v89 = v88;
    v83->m_Bounds.m_vMinBounds.z = v89;
    v90 = this->m_pHeader;
    v91 = lightBounds.m_vMaxBounds.x;
    if ( lightBounds.m_vMaxBounds.x < (double)this->m_pHeader->m_Bounds.m_vMaxBounds.x )
      v91 = this->m_pHeader->m_Bounds.m_vMaxBounds.x;
    v92 = v91;
    v90->m_Bounds.m_vMaxBounds.x = v92;
    v93 = v9;
    if ( v9 < (double)v90->m_Bounds.m_vMaxBounds.y )
      v93 = v90->m_Bounds.m_vMaxBounds.y;
    v94 = v93;
    v90->m_Bounds.m_vMaxBounds.y = v94;
    v95 = v10;
    if ( v10 < (double)v90->m_Bounds.m_vMaxBounds.z )
      v95 = v90->m_Bounds.m_vMaxBounds.z;
    v96 = v123;
    v90->m_Bounds.m_vMaxBounds.z = v95;
    v97 = v96->m_pointLights.m_Size;
    v98 = v96->m_hemiLights.m_Size;
    nSpotLights = v96->m_spotLights.m_Size;
    nPointLights = v97;
    nHemiLights = v98;
    CUtlBuffer::CUtlBuffer(this: &outBuffer, growSize: 0, initSize: 0, nFlags: 0);
    if ( nPointLights > 0 )
    {
      v99 = CResourceDictionaryBuilder::AddEntry(
              this: Dictionary,
              nFlags: 2u,
              nSizeBytes: (unsigned int)(40 * nPointLights + 4),
              nResourceType: 19,
              pName: "_lightworld_points_",
              bInstanced: false);
      v100 = v96->m_ResourceEntryList.m_Size;
      nEntry = v99;
      v101 = v96->m_ResourceEntryList.m_Memory.m_nAllocationCount;
      if ( v100 + 1 > v101 )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v96->m_ResourceEntryList,
          num: v100 - v101 + 1);
      ++v96->m_ResourceEntryList.m_Size;
      v102 = v96->m_ResourceEntryList.m_Memory.m_pMemory;
      v103 = v96->m_ResourceEntryList.m_Size - v100 - 1;
      v96->m_ResourceEntryList.m_pElements = v102;
      if ( v103 > 0 )
        _V_memmove(dest: &v102[v100 + 1], src: &v102[v100], count: 4 * v103);
      v104 = &v96->m_ResourceEntryList.m_Memory.m_pMemory[v100];
      if ( v104 != nullptr )
        *v104 = nEntry;
      CUtlBuffer::Put(this: &outBuffer, pMem: &nPointLights, size: 4);
      for ( j = 0; j < nPointLights; ++j )
        CUtlBuffer::Put(this: &outBuffer, pMem: v96->m_pointLights.m_Memory.m_pMemory[j], size: 40);
    }
    if ( nHemiLights > 0 )
    {
      v106 = CResourceDictionaryBuilder::AddEntry(
               this: Dictionary,
               nFlags: 2u,
               nSizeBytes: (unsigned int)(76 * nHemiLights + 4),
               nResourceType: 20,
               pName: "_lightworld_hemis_",
               bInstanced: false);
      v107 = v96->m_ResourceEntryList.m_Size;
      nEntrya = v106;
      v108 = v96->m_ResourceEntryList.m_Memory.m_nAllocationCount;
      if ( v107 + 1 > v108 )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v96->m_ResourceEntryList,
          num: v107 - v108 + 1);
      ++v96->m_ResourceEntryList.m_Size;
      v109 = v96->m_ResourceEntryList.m_Memory.m_pMemory;
      v110 = v96->m_ResourceEntryList.m_Size - v107 - 1;
      v96->m_ResourceEntryList.m_pElements = v109;
      if ( v110 > 0 )
        _V_memmove(dest: &v109[v107 + 1], src: &v109[v107], count: 4 * v110);
      v111 = &v96->m_ResourceEntryList.m_Memory.m_pMemory[v107];
      if ( v111 != nullptr )
        *v111 = nEntrya;
      CUtlBuffer::Put(this: &outBuffer, pMem: &nHemiLights, size: 4);
      for ( k = 0; k < nHemiLights; ++k )
        CUtlBuffer::Put(this: &outBuffer, pMem: v96->m_hemiLights.m_Memory.m_pMemory[k], size: 76);
    }
    if ( nSpotLights > 0 )
    {
      v113 = CResourceDictionaryBuilder::AddEntry(
               this: Dictionary,
               nFlags: 2u,
               nSizeBytes: (unsigned int)(80 * nSpotLights + 4),
               nResourceType: 21,
               pName: "_lightworld_spots_",
               bInstanced: false);
      v114 = v96->m_ResourceEntryList.m_Size;
      nEntryb = v113;
      v115 = v96->m_ResourceEntryList.m_Memory.m_nAllocationCount;
      if ( v114 + 1 > v115 )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v96->m_ResourceEntryList,
          num: v114 - v115 + 1);
      ++v96->m_ResourceEntryList.m_Size;
      v116 = v96->m_ResourceEntryList.m_Memory.m_pMemory;
      v117 = v96->m_ResourceEntryList.m_Size - v114 - 1;
      v96->m_ResourceEntryList.m_pElements = v116;
      if ( v117 > 0 )
        _V_memmove(dest: &v116[v114 + 1], src: &v116[v114], count: 4 * v117);
      v118 = &v96->m_ResourceEntryList.m_Memory.m_pMemory[v114];
      if ( v118 != nullptr )
        *v118 = nEntryb;
      CUtlBuffer::Put(this: &outBuffer, pMem: &nSpotLights, size: 4);
      for ( m = 0; m < nSpotLights; ++m )
        CUtlBuffer::Put(this: &outBuffer, pMem: v96->m_spotLights.m_Memory.m_pMemory[m], size: 80);
    }
    fwrite(buffer: outBuffer.m_Memory.m_pMemory, size: outBuffer.m_Put, count: 1u, stream: fp);
    if ( outBuffer.m_Memory.m_nGrowSize >= 0 && outBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuffer.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409E40
// Name: private: void CBVHNodeBuilder::BuildVB(class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildVB(CBVHNodeBuilder *this, CResourceDictionaryBuilder *Dictionary, _iobuf *fp)
{
  CBVHNodeBuilder *v3; // eax
  int m_Size; // esi
  int v5; // edi
  int v6; // ecx
  CBuilderMesh *m_pMemory; // edx
  int *p_m_nVertexCount; // eax
  int v9; // ecx
  int v10; // ebx
  const void **v11; // eax
  int v12; // eax
  CBVHNodeBuilder *v13; // esi
  int v14; // edi
  int v15; // ebx
  int m_nAllocationCount; // eax
  int *v17; // ecx
  int v18; // eax
  int *v19; // eax
  BVHBufferDesc_t BufferDesc; // [esp+4h] [ebp-18h] BYREF
  int nMeshes; // [esp+10h] [ebp-Ch]
  CBVHNodeBuilder *v22; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v3 = this;
  m_Size = this->m_Meshes.m_Size;
  v22 = this;
  nMeshes = m_Size;
  if ( m_Size >= 1 )
  {
    i = 0;
    while ( 1 )
    {
      v5 = 0;
      v6 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = v3->m_Meshes.m_Memory.m_pMemory;
        p_m_nVertexCount = &m_pMemory->m_mesh.m_nVertexCount;
        do
        {
          if ( m_pMemory->m_Combo.m_nInputLayout == i )
          {
            v9 = p_m_nVertexCount[1];
            v5 += 4 * v9 * *p_m_nVertexCount;
            v6 = 4 * v9;
          }
          ++m_pMemory;
          p_m_nVertexCount += 93;
          --m_Size;
        }
        while ( m_Size != 0 );
        if ( v6 > 0 && v5 > 0 )
        {
          BufferDesc.m_nElementSizeInBytes = v6;
          BufferDesc.m_nBufferType = RENDER_BUFFER_TYPE_STATIC;
          BufferDesc.m_nElementCount = v5 / v6;
          fwrite(buffer: &BufferDesc, size: 0xCu, count: 1u, stream: fp);
          v10 = nMeshes;
          do
          {
            v11 = (const void **)((char *)v22->m_Meshes.m_Memory.m_pMemory + m_Size);
            if ( *v11 == (const void *)i )
              fwrite(buffer: v11[2], size: 4 * (_DWORD)v11[5] * (_DWORD)v11[6], count: 1u, stream: fp);
            m_Size += 372;
            --v10;
          }
          while ( v10 != 0 );
          v12 = CResourceDictionaryBuilder::AddEntry(
                  this: Dictionary,
                  nFlags: 8u,
                  nSizeBytes: (unsigned int)(v5 + 12),
                  nResourceType: 0,
                  pName: "uniquedatavb",
                  bInstanced: false);
          v13 = v22;
          v14 = v22->m_ResourceEntryList.m_Size;
          v15 = v12;
          m_nAllocationCount = v22->m_ResourceEntryList.m_Memory.m_nAllocationCount;
          if ( v14 + 1 > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v22->m_ResourceEntryList,
              num: v14 - m_nAllocationCount + 1);
          ++v13->m_ResourceEntryList.m_Size;
          v17 = v13->m_ResourceEntryList.m_Memory.m_pMemory;
          v18 = v13->m_ResourceEntryList.m_Size - v14 - 1;
          v13->m_ResourceEntryList.m_pElements = v17;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
          v19 = &v13->m_ResourceEntryList.m_Memory.m_pMemory[v14];
          if ( v19 != nullptr )
            *v19 = v15;
        }
      }
      if ( ++i >= 4 )
        break;
      m_Size = nMeshes;
      v3 = v22;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409FA0
// Name: private: void CBVHNodeBuilder::BuildIB(class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildIB(CBVHNodeBuilder *this, CResourceDictionaryBuilder *Dictionary, _iobuf *fp)
{
  CBVHNodeBuilder *v3; // ebx
  int m_Size; // esi
  CBuilderMesh *m_pMemory; // eax
  int m_nPerDrawIndexSets; // ebx
  int v7; // edi
  int v8; // edx
  int v9; // esi
  int *p_m_Size; // eax
  unsigned int v11; // ecx
  bool v12; // zf
  int v13; // esi
  int v14; // edi
  int v15; // ebx
  int v16; // eax
  int v17; // edi
  int m_nAllocationCount; // eax
  int *v19; // ecx
  int v20; // eax
  int *v21; // edi
  BVHBufferDesc_t BufferDesc; // [esp+Ch] [ebp-24h] BYREF
  int nMeshes; // [esp+18h] [ebp-18h]
  CBVHNodeBuilder *v24; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  CBuilderMesh *v26; // [esp+24h] [ebp-Ch]
  int nPerDrawIndices; // [esp+28h] [ebp-8h]
  int nIndices; // [esp+2Ch] [ebp-4h]
  int iEntry; // [esp+3Ch] [ebp+Ch]

  v3 = this;
  m_Size = this->m_Meshes.m_Size;
  v24 = this;
  nIndices = 0;
  nMeshes = m_Size;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Meshes.m_Memory.m_pMemory;
    v26 = m_pMemory;
    i = m_Size;
    do
    {
      m_nPerDrawIndexSets = m_pMemory->m_nPerDrawIndexSets;
      v7 = 0;
      if ( m_nPerDrawIndexSets <= 0 )
      {
        nIndices += m_pMemory->m_mesh.m_nIndexCount;
      }
      else
      {
        v8 = 0;
        v9 = 0;
        nPerDrawIndices = 0;
        if ( m_nPerDrawIndexSets >= 2 )
        {
          p_m_Size = &m_pMemory->m_pPerDrawIndices[1].m_Size;
          v11 = ((unsigned int)(m_nPerDrawIndexSets - 2) >> 1) + 1;
          v7 = 2 * v11;
          do
          {
            v8 += *(p_m_Size - 5);
            v9 += *p_m_Size;
            p_m_Size += 10;
            --v11;
          }
          while ( v11 != 0 );
          m_pMemory = v26;
        }
        if ( v7 < m_nPerDrawIndexSets )
          nPerDrawIndices = m_pMemory->m_pPerDrawIndices[v7].m_Size;
        nIndices += nPerDrawIndices + v8 + v9;
        m_Size = nMeshes;
      }
      ++m_pMemory;
      v12 = i-- == 1;
      v26 = m_pMemory;
    }
    while ( !v12 );
    v3 = v24;
  }
  BufferDesc.m_nBufferType = RENDER_BUFFER_TYPE_STATIC;
  BufferDesc.m_nElementCount = nIndices;
  BufferDesc.m_nElementSizeInBytes = 4;
  fwrite(buffer: &BufferDesc, size: 0xCu, count: 1u, stream: fp);
  if ( m_Size > 0 )
  {
    nPerDrawIndices = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v13 = (int)v3->m_Meshes.m_Memory.m_pMemory + nPerDrawIndices;
      if ( *(int *)(v13 + 364) <= 0 )
      {
        fwrite(buffer: *(const void **)(v13 + 16), size: 4 * *(_DWORD *)(v13 + 32), count: 1u, stream: fp);
      }
      else
      {
        v14 = 0;
        v15 = 0;
        do
        {
          fwrite(
            buffer: *(const void **)(*(_DWORD *)(v13 + 368) + v15),
            size: 4 * *(_DWORD *)(*(_DWORD *)(v13 + 368) + v15 + 12),
            count: 1u,
            stream: fp);
          ++v14;
          v15 += 20;
        }
        while ( v14 < *(_DWORD *)(v13 + 364) );
        v3 = v24;
      }
      nPerDrawIndices += 372;
    }
  }
  v16 = CResourceDictionaryBuilder::AddEntry(
          this: Dictionary,
          nFlags: 8u,
          nSizeBytes: (unsigned int)(4 * nIndices + 12),
          nResourceType: 2,
          pName: "uniquedataib",
          bInstanced: false);
  v17 = v3->m_ResourceEntryList.m_Size;
  iEntry = v16;
  m_nAllocationCount = v3->m_ResourceEntryList.m_Memory.m_nAllocationCount;
  if ( v17 + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&v3->m_ResourceEntryList,
      num: v17 - m_nAllocationCount + 1);
  ++v3->m_ResourceEntryList.m_Size;
  v19 = v3->m_ResourceEntryList.m_Memory.m_pMemory;
  v20 = v3->m_ResourceEntryList.m_Size - v17 - 1;
  v3->m_ResourceEntryList.m_pElements = v19;
  if ( v20 > 0 )
    _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
  v21 = &v3->m_ResourceEntryList.m_Memory.m_pMemory[v17];
  if ( v21 != nullptr )
    *v21 = iEntry;
}

//------------------------------------------------------------------------------
// Address: 0x0040A180
// Name: private: void CBVHNodeBuilder::BuildScalingTextures(char const __near *,class CResourceDictionaryBuilder __near &,struct _iobuf __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildScalingTextures(
        CBVHNodeBuilder *this,
        const char *pMapName,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp,
        int nMaxTexScales)
{
  CBVHNodeBuilder *v5; // esi
  int m_Size; // eax
  IVTFTexture *VTFTexture; // edi
  int v8; // eax
  CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *v9; // ecx
  int v10; // ebx
  _WORD *v11; // esi
  float *p_x; // ecx
  float x; // xmm2_4
  float y; // xmm4_4
  float z; // xmm3_4
  float w; // xmm0_4
  CBVHNodeBuilder *v17; // ecx
  int v18; // ebx
  int v19; // esi
  CBVHNodeBuilder *v20; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v23; // eax
  int *v24; // esi
  char pTexName[260]; // [esp+48h] [ebp-124h] BYREF
  int nTexScales; // [esp+14Ch] [ebp-20h]
  Vector4D vScaling; // [esp+150h] [ebp-1Ch]
  unsigned int v28; // [esp+160h] [ebp-Ch]
  CBVHNodeBuilder *v29; // [esp+164h] [ebp-8h]
  int t; // [esp+168h] [ebp-4h]

  v5 = this;
  m_Size = this->m_TexScales.m_Size;
  v29 = this;
  nTexScales = m_Size;
  t = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      VTFTexture = CreateVTFTexture();
      VTFTexture->Init(
        this: VTFTexture,
        a2: 1,
        a3: nMaxTexScales,
        a4: 1,
        a5: IMAGE_FORMAT_RGBA16161616,
        a6: 0,
        a7: 1,
        a8: 1);
      v8 = (int)VTFTexture->ImageData_3(this: VTFTexture);
      v9 = v5->m_TexScales.m_Memory.m_pMemory[t];
      v10 = 0;
      if ( v9->m_Size > 0 )
      {
        v28 = 0;
        v11 = (_WORD *)(v8 + 4);
        do
        {
          p_x = &v9->m_Memory.m_pMemory[v28 / 0x10].x;
          y = p_x[1];
          z = p_x[2];
          w = p_x[3];
          vScaling.x = *p_x;
          x = vScaling.x;
          vScaling.y = y;
          vScaling.z = z;
          vScaling.w = w;
          if ( vScaling.x > 1.0 || y > 1.0 || z > 1.0 || w > 1.0 )
          {
            _Warning(a1: "Scaling vector is out of range: <%f,%f,%f,%f>!\n", vScaling.x, y, z, w);
            x = vScaling.x;
            if ( vScaling.x >= 1.0 )
              x = 1.0;
            y = vScaling.y;
            if ( vScaling.y >= 1.0 )
              y = 1.0;
            z = vScaling.z;
            if ( vScaling.z >= 1.0 )
              z = 1.0;
            w = vScaling.w;
            if ( vScaling.w >= 1.0 )
              w = 1.0;
          }
          v28 += 16;
          *(v11 - 2) = (int)(float)(x * 65535.0);
          *(v11 - 1) = (int)(float)(y * 65535.0);
          v17 = v29;
          *v11 = (int)(float)(z * 65535.0);
          v11[1] = (int)(float)(w * 65535.0);
          v9 = v17->m_TexScales.m_Memory.m_pMemory[t];
          ++v10;
          v11 += 4;
        }
        while ( v10 < v9->m_Size );
        v5 = v29;
      }
      V_snprintf(
        pDest: pTexName,
        maxLen: 260,
        pFormat: "materials\\%s\\node%04d_scale%02d.vtf",
        pMapName,
        g_nNodeCounter,
        t);
      v18 = CResourceDictionaryBuilder::AddTextureToDictionary(
              this: Dictionary,
              pTextureName: pTexName,
              pVTFTexture: VTFTexture,
              fp);
      DestroyVTFTexture(pTexture: VTFTexture);
      v19 = v5->m_ResourceEntryList.m_Size;
      v20 = v29;
      m_nAllocationCount = v29->m_ResourceEntryList.m_Memory.m_nAllocationCount;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v29->m_ResourceEntryList,
          num: v19 - m_nAllocationCount + 1);
      ++v20->m_ResourceEntryList.m_Size;
      m_pMemory = v20->m_ResourceEntryList.m_Memory.m_pMemory;
      v23 = v20->m_ResourceEntryList.m_Size - v19 - 1;
      v20->m_ResourceEntryList.m_pElements = m_pMemory;
      if ( v23 > 0 )
        _V_memmove(dest: &m_pMemory[v19 + 1], src: &m_pMemory[v19], count: 4 * v23);
      v24 = &v20->m_ResourceEntryList.m_Memory.m_pMemory[v19];
      if ( v24 != nullptr )
        *v24 = v18;
      if ( ++t >= nTexScales )
        break;
      v5 = v20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A3C0
// Name: private: void CBVHNodeBuilder::BuildInstanceData(class CResourceDictionaryBuilder __near &,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildInstanceData(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp)
{
  CBVHNodeBuilder *v3; // esi
  int m_Size; // eax
  int v5; // edi
  InstanceContainer_t *v6; // ebx
  int m_nPerDrawTransformSets; // ecx
  int v8; // edi
  int v9; // edx
  int v10; // esi
  int *v11; // eax
  int *p_m_Size; // eax
  unsigned int v13; // ecx
  int v14; // edi
  int v15; // ebx
  InstanceContainer_t *v16; // esi
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *m_pPerDrawTransforms; // eax
  int v18; // edi
  bool v19; // zf
  int v20; // eax
  int v21; // ebx
  int v22; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v25; // eax
  int *v26; // ebx
  InstanceGeometry_t *v27; // eax
  _BYTE *m_nMeshes; // ecx
  int v29; // edx
  int v30; // ebx
  int v31; // edi
  int v32; // eax
  int *v33; // ecx
  int v34; // eax
  int *v35; // eax
  BVHBufferDesc_t BufferDesc; // [esp+4h] [ebp-28h] BYREF
  int *pEntries; // [esp+10h] [ebp-1Ch]
  InstanceGeometry_t *pInstanceLOD; // [esp+14h] [ebp-18h]
  int nPerDrawTransforms; // [esp+18h] [ebp-14h]
  int nMeshes; // [esp+1Ch] [ebp-10h]
  unsigned int v41; // [esp+20h] [ebp-Ch]
  CBVHNodeBuilder *v42; // [esp+24h] [ebp-8h]
  int nTotalTransforms; // [esp+28h] [ebp-4h]
  CResourceDictionaryBuilder *Dictionarya; // [esp+34h] [ebp+8h]
  int m; // [esp+38h] [ebp+Ch]

  v3 = this;
  m_Size = this->m_InstanceContainers.m_Size;
  v42 = this;
  pInstanceLOD = (InstanceGeometry_t *)m_Size;
  if ( m_Size >= 1 )
  {
    v5 = 0;
    nTotalTransforms = 0;
    v41 = 0;
    for ( nMeshes = m_Size; nMeshes != 0; --nMeshes )
    {
      v6 = &v3->m_InstanceContainers.m_Memory.m_pMemory[v41 / 0x10];
      m_nPerDrawTransformSets = v6->m_nPerDrawTransformSets;
      if ( m_nPerDrawTransformSets <= 0 )
      {
        v5 += v6->m_pTransforms->m_Size;
        nTotalTransforms = v5;
      }
      else
      {
        v8 = 0;
        v9 = 0;
        v10 = 0;
        v11 = nullptr;
        nPerDrawTransforms = 0;
        if ( m_nPerDrawTransformSets >= 2 )
        {
          p_m_Size = &v6->m_pPerDrawTransforms[1].m_Size;
          v13 = ((unsigned int)(m_nPerDrawTransformSets - 2) >> 1) + 1;
          pEntries = (int *)(2 * v13);
          do
          {
            v9 += *(p_m_Size - 5);
            v10 += *p_m_Size;
            p_m_Size += 10;
            --v13;
          }
          while ( v13 != 0 );
          v8 = nPerDrawTransforms;
          v11 = pEntries;
        }
        if ( (int)v11 < v6->m_nPerDrawTransformSets )
          v8 = v6->m_pPerDrawTransforms[(_DWORD)v11].m_Size;
        v14 = v9 + v10 + v8;
        if ( v14 != v6->m_pTransforms->m_Size )
          _Warning(a1: "Invalid per-draw transform count.. We must have missed an instance transform when splitting draw calls!\n");
        nTotalTransforms += v14;
        v5 = nTotalTransforms;
        v3 = v42;
      }
      v41 += 16;
    }
    v15 = 0;
    BufferDesc.m_nBufferType = RENDER_BUFFER_TYPE_STATIC;
    BufferDesc.m_nElementCount = v5;
    BufferDesc.m_nElementSizeInBytes = 48;
    fwrite(buffer: &BufferDesc, size: 0xCu, count: 1u, stream: fp);
    if ( (int)pInstanceLOD > 0 )
    {
      v41 = 0;
      nPerDrawTransforms = (int)pInstanceLOD;
      do
      {
        v16 = &v3->m_InstanceContainers.m_Memory.m_pMemory[v41 / 0x10];
        if ( v16->m_nPerDrawTransformSets <= 0 )
        {
          fwrite(
            buffer: v16->m_pTransforms->m_Memory.m_pMemory,
            size: 48 * v16->m_pTransforms->m_Size,
            count: 1u,
            stream: fp);
          v15 += v16->m_pTransforms->m_Size;
        }
        else
        {
          m_pPerDrawTransforms = v16->m_pPerDrawTransforms;
          nMeshes = 0;
          v18 = 0;
          do
          {
            if ( m_pPerDrawTransforms[v18].m_Size > 0 )
            {
              fwrite(
                buffer: v16->m_pPerDrawTransforms[v18].m_Memory.m_pMemory,
                size: 48 * v16->m_pPerDrawTransforms[v18].m_Size,
                count: 1u,
                stream: fp);
              m_pPerDrawTransforms = v16->m_pPerDrawTransforms;
              v15 += m_pPerDrawTransforms[v18].m_Size;
            }
            ++v18;
            ++nMeshes;
          }
          while ( nMeshes < v16->m_nPerDrawTransformSets );
          v5 = nTotalTransforms;
        }
        v41 += 16;
        v19 = nPerDrawTransforms-- == 1;
        v3 = v42;
      }
      while ( !v19 );
    }
    if ( v15 != v5 )
      _Msg(a1: "Error: Invalid transform count!\n");
    v20 = CResourceDictionaryBuilder::AddEntry(
            this: Dictionary,
            nFlags: 4u,
            nSizeBytes: (unsigned int)(48 * v5 + 12),
            nResourceType: 0,
            pName: "instancedata",
            bInstanced: false);
    v21 = v3->m_ResourceEntryList.m_Size;
    v22 = v20;
    m_nAllocationCount = v3->m_ResourceEntryList.m_Memory.m_nAllocationCount;
    if ( v21 + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v3->m_ResourceEntryList,
        num: v21 - m_nAllocationCount + 1);
    ++v3->m_ResourceEntryList.m_Size;
    m_pMemory = v3->m_ResourceEntryList.m_Memory.m_pMemory;
    v25 = v3->m_ResourceEntryList.m_Size - v21 - 1;
    v3->m_ResourceEntryList.m_pElements = m_pMemory;
    if ( v25 > 0 )
      _V_memmove(dest: &m_pMemory[v21 + 1], src: &m_pMemory[v21], count: 4 * v25);
    v26 = &v3->m_ResourceEntryList.m_Memory.m_pMemory[v21];
    if ( v26 != nullptr )
      *v26 = v22;
    if ( (int)pInstanceLOD > 0 )
    {
      Dictionarya = nullptr;
      for ( nPerDrawTransforms = (int)pInstanceLOD; nPerDrawTransforms != 0; --nPerDrawTransforms )
      {
        v27 = *(InstanceGeometry_t **)((char *)&Dictionarya->__vftable
                                     + (unsigned int)v42->m_InstanceContainers.m_Memory.m_pMemory);
        m_nMeshes = (_BYTE *)v27->m_nMeshes;
        v29 = 0;
        pInstanceLOD = v27;
        nMeshes = (int)m_nMeshes;
        for ( m = 0; v29 < (int)m_nMeshes; m = v29 )
        {
          pEntries = v27->m_ppEntries[v29];
          v30 = 0;
          if ( v27->m_pEntryCounts[v29] > 0 )
          {
            do
            {
              v31 = v3->m_ResourceEntryList.m_Size;
              v32 = v3->m_ResourceEntryList.m_Memory.m_nAllocationCount;
              if ( v31 + 1 > v32 )
              {
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&v3->m_ResourceEntryList,
                  num: v31 - v32 + 1);
                v29 = m;
              }
              ++v3->m_ResourceEntryList.m_Size;
              v33 = v3->m_ResourceEntryList.m_Memory.m_pMemory;
              v34 = v3->m_ResourceEntryList.m_Size - v31 - 1;
              v3->m_ResourceEntryList.m_pElements = v33;
              if ( v34 > 0 )
              {
                _V_memmove(dest: &v33[v31 + 1], src: &v33[v31], count: 4 * v34);
                v29 = m;
              }
              v35 = &v3->m_ResourceEntryList.m_Memory.m_pMemory[v31];
              if ( v35 != nullptr )
                *v35 = pEntries[v30];
              v27 = pInstanceLOD;
              ++v30;
            }
            while ( v30 < pInstanceLOD->m_pEntryCounts[v29] );
            m_nMeshes = (_BYTE *)nMeshes;
          }
          ++v29;
        }
        Dictionarya = (CResourceDictionaryBuilder *)((char *)Dictionarya + 16);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A6A0
// Name: public: unsigned __int64 CBVHNodeBuilder::CreateKDTree(class CResourceDictionaryBuilder __near &,struct _iobuf __near *,class RayTracingEnvironment __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CBVHNodeBuilder::CreateKDTree(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp,
        RayTracingEnvironment *rteTree)
{
  RayTracingEnvironment *v4; // esi
  CBVHNodeBuilder *v5; // edi
  int m_Size; // eax
  CBuilderMesh *v7; // edi
  int m_nIndexCount; // eax
  _DWORD *v9; // esi
  unsigned int v10; // ebx
  bool v11; // zf
  unsigned int SerializationNumBytes; // ebx
  int v13; // eax
  CUtlMemory<S3RGBA,int> *p_m_ResourceEntryList; // esi
  int v15; // edi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v18; // eax
  int *v19; // edi
  CUtlBuffer treeBuffer; // [esp+0h] [ebp-4Ch] BYREF
  Vector vColor; // [esp+30h] [ebp-1Ch] BYREF
  int v23; // [esp+3Ch] [ebp-10h]
  CBVHNodeBuilder *v24; // [esp+40h] [ebp-Ch]
  unsigned int v25; // [esp+44h] [ebp-8h]
  int nTriangle; // [esp+48h] [ebp-4h]
  int nEntry; // [esp+5Ch] [ebp+10h]

  v4 = rteTree;
  rteTree->Flags |= 6u;
  v5 = this;
  m_Size = this->m_Meshes.m_Size;
  v24 = this;
  memset(&vColor, 0, sizeof(vColor));
  nTriangle = 0;
  if ( m_Size > 0 )
  {
    v25 = 0;
    v23 = m_Size;
    do
    {
      v7 = &v5->m_Meshes.m_Memory.m_pMemory[v25 / 0x174];
      if ( v7->m_Combo.m_nIndicesPerFace == 3 )
      {
        m_nIndexCount = v7->m_mesh.m_nIndexCount;
        if ( m_nIndexCount > 0 )
        {
          v9 = v7->m_mesh.m_pIndices + 1;
          v10 = (m_nIndexCount - 1) / 3u + 1;
          do
          {
            RayTracingEnvironment::AddTriangle(
              this: rteTree,
              id: nTriangle++,
              v1: (const Vector *)&v7->m_mesh.m_pVerts[v7->m_mesh.m_nVertexStrideFloats * *(v9 - 1)],
              v2: (const Vector *)&v7->m_mesh.m_pVerts[v7->m_mesh.m_nVertexStrideFloats * *v9],
              v3: (const Vector *)&v7->m_mesh.m_pVerts[v7->m_mesh.m_nVertexStrideFloats * v9[1]],
              color: &vColor);
            v9 += 3;
            --v10;
          }
          while ( v10 != 0 );
          v4 = rteTree;
        }
      }
      else
      {
        _Msg(a1: "Quads not supported yet!\n");
      }
      v25 += 372;
      v11 = v23-- == 1;
      v5 = v24;
    }
    while ( !v11 );
  }
  RayTracingEnvironment::SetupAccelerationStructure(this: v4);
  SerializationNumBytes = RayTracingEnvironment::GetSerializationNumBytes(this: v4, nSerializationFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &treeBuffer, growSize: 0, initSize: 0, nFlags: 0);
  RayTracingEnvironment::Serialize(this: v4, outbuf: &treeBuffer, nSerializationFlags: 0);
  fwrite(buffer: treeBuffer.m_Memory.m_pMemory, size: SerializationNumBytes, count: 1u, stream: fp);
  v13 = CResourceDictionaryBuilder::AddEntry(
          this: Dictionary,
          nFlags: 8u,
          nSizeBytes: SerializationNumBytes,
          nResourceType: 18,
          pName: "kdtree",
          bInstanced: false);
  p_m_ResourceEntryList = (CUtlMemory<S3RGBA,int> *)&v5->m_ResourceEntryList;
  v15 = v5->m_ResourceEntryList.m_Size;
  nEntry = v13;
  m_nAllocationCount = p_m_ResourceEntryList->m_nAllocationCount;
  if ( v15 + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_ResourceEntryList, num: v15 - m_nAllocationCount + 1);
  ++p_m_ResourceEntryList[1].m_pMemory;
  m_pMemory = p_m_ResourceEntryList->m_pMemory;
  v18 = (int)p_m_ResourceEntryList[1].m_pMemory - v15 - 1;
  p_m_ResourceEntryList[1].m_nAllocationCount = (int)p_m_ResourceEntryList->m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: 4 * v18);
  v19 = (int *)&p_m_ResourceEntryList->m_pMemory[v15];
  if ( v19 != nullptr )
    *v19 = nEntry;
  v24->m_pHeader->m_Flags |= 8u;
  if ( treeBuffer.m_Memory.m_nGrowSize >= 0 && treeBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: treeBuffer.m_Memory.m_pMemory);
  return SerializationNumBytes;
}

//------------------------------------------------------------------------------
// Address: 0x0040A860
// Name: private: int CBVHNodeBuilder::CreateAtlasedDrawCalls(int,int)
// Source: json
//------------------------------------------------------------------------------
bool *__thiscall CBVHNodeBuilder::CreateAtlasedDrawCalls(
        CBVHNodeBuilder *this,
        int nMaxTexScaleSlots,
        int nLastResource)
{
  int m_Size; // esi
  int v4; // ebx
  int *v5; // edx
  int v6; // eax
  CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *v7; // eax
  CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *v8; // esi
  CBuilderMesh *m_pMemory; // edx
  CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *v10; // ecx
  int v11; // edi
  CBuilderAtlas *v12; // ebx
  int v13; // eax
  CBuilderAtlas **v14; // ecx
  int m_nAllocationCount; // eax
  CBuilderAtlas **v16; // ecx
  int v17; // eax
  CBuilderAtlas **v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // eax
  CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo **v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // eax
  int *v26; // eax
  int v27; // edi
  int v28; // eax
  int *v29; // ecx
  int v30; // eax
  int *v31; // eax
  int v32; // eax
  int v33; // eax
  CBuilderMesh *v34; // edi
  int v35; // ebx
  CBuilderMesh *v36; // esi
  int v37; // edi
  int v38; // ebx
  CBVHNodeBuilder *v39; // esi
  int j; // ebx
  CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *v41; // esi
  int *v42; // eax
  CBuilderAtlas **v43; // eax
  CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *v44; // esi
  CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *v45; // eax
  CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *v46; // ebx
  int v47; // eax
  int v48; // edx
  CBuilderMesh *v49; // esi
  int m_nBinds; // eax
  bool v51; // zf
  int m_nInputLayout; // ecx
  int m_nTextures; // esi
  _QWORD *v54; // eax
  char *v55; // ecx
  char *v56; // esi
  char *v57; // ecx
  char *v58; // esi
  int v59; // edi
  CBuilderMesh *v60; // edx
  bool v61; // cc
  int v62; // edx
  float *v63; // eax
  int v64; // edx
  CBuilderMesh *v65; // edx
  BVHResourceBinding_t *m_pResourceBindings; // ecx
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // edi
  BuilderDrawData_t *v71; // eax
  int m_nBaseVertex; // edx
  __int64 v73; // xmm0_8
  BVHResourceBinding_t *v74; // eax
  int m_nVertexCount; // ecx
  CBuilderMesh *v76; // ecx
  AABB_t *v77; // eax
  CBVHNodeBuilder *v78; // esi
  int v79; // edi
  int v80; // eax
  CBVHDrawCallBuilder *v81; // ecx
  int v82; // eax
  CBVHDrawCallBuilder *v83; // edi
  CBVHNodeBuilder *v84; // esi
  int v85; // edi
  int v86; // eax
  CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > **v87; // ecx
  int v88; // eax
  CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> **v89; // eax
  CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *v90; // eax
  int m_VertexCount; // edx
  int m_IndexCount; // eax
  CBuilderMesh *v93; // esi
  int v94; // eax
  BuilderDrawData_t *v95; // edi
  int m_VertexStart; // ecx
  float v97; // xmm0_4
  BuilderDrawData_t *p_z; // edx
  ActiveLayer_t<CUtlSymbolLarge> *v99; // esi
  int v100; // eax
  ActiveLayer_t<CUtlSymbolLarge> *v101; // ecx
  int v102; // eax
  float *v103; // esi
  bool *v104; // esi
  int v105; // edx
  int v106; // edi
  _DWORD *v107; // esi
  int v108; // edx
  int FirstAttributeOffset; // eax
  int v110; // ecx
  float v111; // xmm0_4
  float *v112; // edx
  ActiveLayer_t<CUtlSymbolLarge> *v113; // esi
  int v114; // eax
  ActiveLayer_t<CUtlSymbolLarge> *v115; // ecx
  int v116; // eax
  float *p_priority; // esi
  char v118; // dl
  int v119; // edi
  AABB_t *v120; // eax
  CBVHNodeBuilder *v121; // edi
  int v122; // esi
  float z; // xmm0_4
  int v124; // eax
  CBVHDrawCallBuilder *v125; // ecx
  int v126; // eax
  CBVHDrawCallBuilder *v127; // eax
  CBVHNodeBuilder *v128; // esi
  int v129; // edi
  int v130; // eax
  CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > **v131; // ecx
  int v132; // eax
  CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> **v133; // eax
  CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *v134; // eax
  CBuilderMesh *v135; // eax
  int v136; // esi
  int v137; // ecx
  ActiveLayer_t<CUtlSymbolLarge> *v138; // eax
  int v140; // [esp-8h] [ebp-178h]
  int v141; // [esp-4h] [ebp-174h]
  int v142; // [esp-4h] [ebp-174h]
  AABB_t v143; // [esp+Ch] [ebp-164h] BYREF
  int pCurrentVBByteOffset[4]; // [esp+24h] [ebp-14Ch] BYREF
  __int64 v145; // [esp+34h] [ebp-13Ch]
  __int64 v146; // [esp+3Ch] [ebp-134h]
  __int64 v147; // [esp+44h] [ebp-12Ch]
  __int64 v148; // [esp+4Ch] [ebp-124h]
  __int64 v149; // [esp+54h] [ebp-11Ch]
  __int64 v150; // [esp+5Ch] [ebp-114h]
  __int64 v151; // [esp+64h] [ebp-10Ch]
  __int64 v152; // [esp+6Ch] [ebp-104h]
  __int64 v153; // [esp+74h] [ebp-FCh]
  __int64 v154; // [esp+7Ch] [ebp-F4h]
  __int64 v155; // [esp+84h] [ebp-ECh]
  __int64 v156; // [esp+8Ch] [ebp-E4h]
  __int64 v157; // [esp+94h] [ebp-DCh]
  __int64 v158; // [esp+9Ch] [ebp-D4h]
  int nTotalAtlases; // [esp+A4h] [ebp-CCh]
  int nTextureStart; // [esp+A8h] [ebp-C8h]
  CBVHDrawCallBuilder DrawCall; // [esp+ACh] [ebp-C4h]
  int v162; // [esp+FCh] [ebp-74h]
  CUtlVector<int,CUtlMemory<int,int> > UniqueHashes; // [esp+100h] [ebp-70h] BYREF
  int nTexScaleSlot; // [esp+114h] [ebp-5Ch]
  CUtlVector<`CBVHNodeBuilder::CreateAtlasedDrawCalls'::`2'::UniqueCombo *,CUtlMemory<`CBVHNodeBuilder::CreateAtlasedDrawCalls'::`2'::UniqueCombo *,int> > UniqueAtlasCombos; // [esp+118h] [ebp-58h] BYREF
  int nDrawDataCount; // [esp+12Ch] [ebp-44h]
  int i; // [esp+130h] [ebp-40h]
  int *nCurrentVBByteOffset; // [esp+134h] [ebp-3Ch]
  int nTotalIndices; // [esp+138h] [ebp-38h]
  int nCurrentIBCountOffset; // [esp+13Ch] [ebp-34h]
  CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *pCombo; // [esp+140h] [ebp-30h]
  int nDrawTextures; // [esp+144h] [ebp-2Ch]
  int r; // [esp+148h] [ebp-28h]
  BuilderDrawData_t *DrawData; // [esp+14Ch] [ebp-24h]
  float *v175; // [esp+150h] [ebp-20h]
  int n; // [esp+154h] [ebp-1Ch]
  int nSlot; // [esp+158h] [ebp-18h]
  int m; // [esp+15Ch] [ebp-14h]
  bool *pbRemoveList; // [esp+160h] [ebp-10h]
  CBuilderMesh *mesh; // [esp+164h] [ebp-Ch]
  CBVHNodeBuilder *v181; // [esp+168h] [ebp-8h]
  int nTexScaleIndex; // [esp+16Ch] [ebp-4h]

  m_Size = this->m_Meshes.m_Size;
  v181 = this;
  r = m_Size;
  pbRemoveList = (bool *)MemAlloc_Alloc(nSize: m_Size);
  _V_memset(dest: pbRemoveList, fill: 0, count: m_Size);
  memset(&UniqueAtlasCombos, 0, sizeof(UniqueAtlasCombos));
  memset(&UniqueHashes, 0, sizeof(UniqueHashes));
  nTexScaleIndex = 0;
  if ( m_Size > 0 )
  {
    nSlot = 0;
    do
    {
      v4 = nSlot;
      v5 = (int *)CBuilderMesh::ComputeAtlasHash(this: (CBuilderMesh *)((char *)v181->m_Meshes.m_Memory.m_pMemory + nSlot));
      v6 = 0;
      nCurrentVBByteOffset = v5;
      if ( UniqueHashes.m_Size <= 0 )
        goto LABEL_8;
      while ( (int *)UniqueHashes.m_Memory.m_pMemory[v6] != v5 )
      {
        if ( ++v6 >= UniqueHashes.m_Size )
          goto LABEL_8;
      }
      if ( (v6 & 0x8000u) == 0 )
      {
        v8 = UniqueAtlasCombos.m_Memory.m_pMemory[(__int16)v6];
      }
      else
      {
LABEL_8:
        v7 = (CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *)MemAlloc_Alloc(nSize: 0x28u);
        if ( v7 != nullptr )
        {
          v7->m_Atlases.m_Memory.m_pMemory = nullptr;
          v7->m_Atlases.m_Memory.m_nAllocationCount = 0;
          v7->m_Atlases.m_Memory.m_nGrowSize = 0;
          v7->m_Atlases.m_Size = 0;
          v7->m_Atlases.m_pElements = nullptr;
          v7->m_MeshIndices.m_Memory.m_pMemory = nullptr;
          v7->m_MeshIndices.m_Memory.m_nAllocationCount = 0;
          v7->m_MeshIndices.m_Memory.m_nGrowSize = 0;
          v7->m_MeshIndices.m_Size = 0;
          v7->m_MeshIndices.m_pElements = nullptr;
          v8 = v7;
        }
        else
        {
          v8 = nullptr;
        }
        m_pMemory = v181->m_Meshes.m_Memory.m_pMemory;
        v10 = *(CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo **)((char *)&m_pMemory->m_Material.m_nTextures
                                                                             + v4);
        if ( (int)v10 > 0 )
        {
          m = (int)m_pMemory->m_Material.m_ppTextures + v4;
          for ( pCombo = v10;
                pCombo != nullptr;
                pCombo = (CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *)((char *)pCombo - 1) )
          {
            v11 = v8->m_Atlases.m_Size;
            v12 = *(CBuilderAtlas **)(*(_DWORD *)m + 336);
            v13 = 0;
            if ( v11 <= 0 )
              goto LABEL_19;
            v14 = v8->m_Atlases.m_Memory.m_pMemory;
            while ( *v14 != v12 )
            {
              ++v13;
              ++v14;
              if ( v13 >= v11 )
                goto LABEL_19;
            }
            if ( v13 < 0 )
            {
LABEL_19:
              m_nAllocationCount = v8->m_Atlases.m_Memory.m_nAllocationCount;
              if ( v11 + 1 > m_nAllocationCount )
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)v8,
                  num: v11 - m_nAllocationCount + 1);
              ++v8->m_Atlases.m_Size;
              v16 = v8->m_Atlases.m_Memory.m_pMemory;
              v17 = v8->m_Atlases.m_Size - v11 - 1;
              v8->m_Atlases.m_pElements = v8->m_Atlases.m_Memory.m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &v16[v11 + 1], src: &v16[v11], count: 4 * v17);
              v18 = &v8->m_Atlases.m_Memory.m_pMemory[v11];
              if ( v18 != nullptr )
                *v18 = v12;
            }
            m += 4;
          }
        }
        v19 = UniqueAtlasCombos.m_Size;
        v20 = UniqueAtlasCombos.m_Size;
        if ( UniqueAtlasCombos.m_Size + 1 > UniqueAtlasCombos.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&UniqueAtlasCombos,
            num: UniqueAtlasCombos.m_Size - UniqueAtlasCombos.m_Memory.m_nAllocationCount + 1);
          v19 = UniqueAtlasCombos.m_Size;
        }
        UniqueAtlasCombos.m_Size = v19 + 1;
        v21 = v19 - v20;
        UniqueAtlasCombos.m_pElements = UniqueAtlasCombos.m_Memory.m_pMemory;
        if ( v21 > 0 )
          _V_memmove(
            dest: &UniqueAtlasCombos.m_Memory.m_pMemory[v20 + 1],
            src: &UniqueAtlasCombos.m_Memory.m_pMemory[v20],
            count: 4 * v21);
        v22 = &UniqueAtlasCombos.m_Memory.m_pMemory[v20];
        if ( v22 != nullptr )
          *v22 = v8;
        v23 = UniqueHashes.m_Size;
        v24 = UniqueHashes.m_Size;
        if ( UniqueHashes.m_Size + 1 > UniqueHashes.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&UniqueHashes,
            num: UniqueHashes.m_Size - UniqueHashes.m_Memory.m_nAllocationCount + 1);
          v23 = UniqueHashes.m_Size;
        }
        UniqueHashes.m_Size = v23 + 1;
        v25 = v23 - v24;
        UniqueHashes.m_pElements = UniqueHashes.m_Memory.m_pMemory;
        if ( v25 > 0 )
          _V_memmove(
            dest: &UniqueHashes.m_Memory.m_pMemory[v24 + 1],
            src: &UniqueHashes.m_Memory.m_pMemory[v24],
            count: 4 * v25);
        v26 = &UniqueHashes.m_Memory.m_pMemory[v24];
        if ( v26 != nullptr )
          *v26 = (int)nCurrentVBByteOffset;
      }
      v27 = v8->m_MeshIndices.m_Size;
      v28 = v8->m_MeshIndices.m_Memory.m_nAllocationCount;
      if ( v27 + 1 > v28 )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v8->m_MeshIndices, num: v27 - v28 + 1);
      ++v8->m_MeshIndices.m_Size;
      v29 = v8->m_MeshIndices.m_Memory.m_pMemory;
      v30 = v8->m_MeshIndices.m_Size - v27 - 1;
      v8->m_MeshIndices.m_pElements = v29;
      if ( v30 > 0 )
        _V_memmove(dest: &v29[v27 + 1], src: &v29[v27], count: 4 * v30);
      v31 = &v8->m_MeshIndices.m_Memory.m_pMemory[v27];
      if ( v31 != nullptr )
        *v31 = nTexScaleIndex;
      nSlot += 372;
      ++nTexScaleIndex;
    }
    while ( nTexScaleIndex < r );
  }
  for ( nDrawTextures = 0; nDrawTextures < UniqueAtlasCombos.m_Size; ++nDrawTextures )
  {
    pCombo = UniqueAtlasCombos.m_Memory.m_pMemory[nDrawTextures];
    v32 = pCombo->m_MeshIndices.m_Size;
    nTexScaleIndex = v32;
    if ( v32 > 0 )
    {
      nCurrentIBCountOffset = 1;
      nSlot = 0;
      for ( i = v32; i != 0; --i )
      {
        v33 = *(int *)((char *)pCombo->m_MeshIndices.m_Memory.m_pMemory + nSlot);
        if ( !pbRemoveList[v33] )
        {
          v34 = &v181->m_Meshes.m_Memory.m_pMemory[v33];
          for ( m = nCurrentIBCountOffset; m < nTexScaleIndex; ++m )
          {
            v35 = pCombo->m_MeshIndices.m_Memory.m_pMemory[m];
            if ( !pbRemoveList[v35] )
            {
              v36 = &v181->m_Meshes.m_Memory.m_pMemory[v35];
              if ( v34->m_Combo.m_nInputLayout == v36->m_Combo.m_nInputLayout
                && v34->m_Combo.m_nIndicesPerFace == v36->m_Combo.m_nIndicesPerFace
                && _V_memcmp(m1: &v34->m_Material, m2: &v36->m_Material, count: 164) == 0
                && v34->m_Material.m_nTextures == v36->m_Material.m_nTextures )
              {
                CBuilderMesh::Concatenate(this: v34, Other: v36);
                pbRemoveList[v35] = true;
              }
            }
          }
        }
        nSlot += 4;
        ++nCurrentIBCountOffset;
      }
    }
  }
  v37 = v181->m_Meshes.m_Size - 1;
  if ( v37 >= 0 )
  {
    v38 = v37;
    do
    {
      if ( pbRemoveList[v37] )
      {
        v39 = v181;
        CBuilderMesh::~CBuilderMesh(this: &v181->m_Meshes.m_Memory.m_pMemory[v38]);
        if ( v39->m_Meshes.m_Size - v37 - 1 > 0 )
          _V_memmove(
            dest: &v39->m_Meshes.m_Memory.m_pMemory[v38],
            src: &v39->m_Meshes.m_Memory.m_pMemory[v38 + 1],
            count: 372 * (v39->m_Meshes.m_Size - v37 - 1));
        --v39->m_Meshes.m_Size;
      }
      --v38;
      --v37;
    }
    while ( v37 >= 0 );
  }
  free(pMem: pbRemoveList);
  for ( j = 0; j < UniqueAtlasCombos.m_Size; ++j )
  {
    v41 = UniqueAtlasCombos.m_Memory.m_pMemory[j];
    if ( v41 != nullptr )
    {
      v41->m_MeshIndices.m_Size = 0;
      if ( v41->m_MeshIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v41->m_MeshIndices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41->m_MeshIndices.m_Memory.m_pMemory);
          v41->m_MeshIndices.m_Memory.m_pMemory = nullptr;
        }
        v41->m_MeshIndices.m_Memory.m_nAllocationCount = 0;
      }
      v42 = v41->m_MeshIndices.m_Memory.m_pMemory;
      v41->m_MeshIndices.m_pElements = v42;
      if ( v41->m_MeshIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v42 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42);
          v41->m_MeshIndices.m_Memory.m_pMemory = nullptr;
        }
        v41->m_MeshIndices.m_Memory.m_nAllocationCount = 0;
      }
      v41->m_Atlases.m_Size = 0;
      if ( v41->m_Atlases.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v41->m_Atlases.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41->m_Atlases.m_Memory.m_pMemory);
          v41->m_Atlases.m_Memory.m_pMemory = nullptr;
        }
        v41->m_Atlases.m_Memory.m_nAllocationCount = 0;
      }
      v43 = v41->m_Atlases.m_Memory.m_pMemory;
      v41->m_Atlases.m_pElements = v41->m_Atlases.m_Memory.m_pMemory;
      if ( v41->m_Atlases.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v43 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43);
          v41->m_Atlases.m_Memory.m_pMemory = nullptr;
        }
        v41->m_Atlases.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v41);
    }
  }
  v44 = (CBVHNodeBuilder::CreateAtlasedDrawCalls::__l2::UniqueCombo *)v181->m_Meshes.m_Size;
  pCombo = v44;
  v45 = (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v45 != nullptr )
  {
    v45->m_pMemory = nullptr;
    v45->m_nAllocationCount = 0;
    v45->m_nGrowSize = 0;
    v45[1].m_pMemory = nullptr;
    v45[1].m_nAllocationCount = 0;
    v46 = v45;
  }
  else
  {
    v46 = nullptr;
  }
  v47 = CalculateTotalAtlases(pAtlasTable: v181->m_pAtlasTable, nAtlasTables: v181->m_nAtlasTables);
  v48 = v47 + v181->m_nVBsNeeded;
  nTotalAtlases = v47;
  pbRemoveList = (bool *)&v44->m_Atlases.m_Memory.m_pMemory + v48 + nLastResource + 1;
  memset(pCurrentVBByteOffset, 0, sizeof(pCurrentVBByteOffset));
  nCurrentIBCountOffset = 0;
  m = 0;
  if ( (int)v44 > 0 )
  {
    nTextureStart = (int)v44 + nLastResource;
    i = 0;
    do
    {
      v49 = (CBuilderMesh *)((char *)v181->m_Meshes.m_Memory.m_pMemory + i);
      nTexScaleSlot = v49->m_Material.m_nTextures;
      m_nBinds = v49->m_Material.m_Material.m_nBinds;
      *(_WORD *)(&v49->m_Material.m_Material.m_Binds[0].m_cBindStage + 2 * m_nBinds + m_nBinds) = 772;
      *(&v49->m_Material.m_Material.m_Binds[0].m_cBindSampler + 2 * m_nBinds + m_nBinds) = 1;
      ++v49->m_Material.m_Material.m_nBinds;
      v51 = v49->m_Combo.m_nIndicesPerFace == 3;
      mesh = v49;
      v49->m_Material.m_Material.m_bInstanced = false;
      *(_WORD *)&v49->m_Material.m_Material.m_bUseAtlas = 1;
      if ( v51 )
        DrawCall.m_nPrimitiveType = RENDER_PRIM_TRIANGLES;
      else
        _Msg(a1: "Only works on triangles for now!");
      m_nInputLayout = v49->m_Combo.m_nInputLayout;
      m_nTextures = v49->m_Material.m_nTextures;
      DrawCall.m_nMeshID = m;
      DrawCall.m_nInputLayout = m_nInputLayout;
      DrawCall.m_nInstanceCount = 0;
      DrawCall.m_nStartInstance = 0;
      DrawCall.m_Flags = 64;
      DrawCall.m_nResourceBindings = m_nTextures + 4;
      v54 = MemAlloc_Alloc(
              nSize: (unsigned __int64)(unsigned int)DrawCall.m_nResourceBindings >> 28 != 0
            ? -1
            : 16 * DrawCall.m_nResourceBindings);
      nCurrentVBByteOffset = (int *)mesh->m_Combo.m_nInputLayout;
      v55 = (char *)pCombo + nTotalAtlases + v181->m_pVBIndex[(_DWORD)nCurrentVBByteOffset];
      v56 = (char *)pCombo + nTotalAtlases + v181->m_nVBsNeeded;
      nCurrentVBByteOffset = &pCurrentVBByteOffset[(_DWORD)nCurrentVBByteOffset];
      v57 = &v55[nLastResource];
      v58 = &v56[nLastResource];
      v147 = (unsigned int)(nLastResource + m);
      *v54 = v147;
      LODWORD(v148) = 0;
      WORD2(v148) = 0;
      v59 = 1;
      n = 0;
      v60 = mesh;
      v54[1] = v148;
      v61 = v60->m_Material.m_nTextures <= 0;
      DrawCall.m_pResourceBindings = (BVHResourceBinding_t *)v54;
      if ( !v61 )
      {
        v175 = (float *)(v54 + 2);
        nTexScaleIndex = (int)v60->m_Material.m_ppTextures;
        do
        {
          v62 = nTextureStart + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)nTexScaleIndex + 336) + 32);
          nTexScaleIndex += 4;
          LODWORD(v150) = 0;
          v63 = v175;
          v149 = (unsigned int)v62;
          v64 = n;
          *(_QWORD *)v175 = v149;
          BYTE5(v150) = v64;
          BYTE4(v150) = 1;
          *((_QWORD *)v63 + 1) = v150;
          v175 = v63 + 4;
          ++v59;
          n = v64 + 1;
        }
        while ( v64 + 1 < mesh->m_Material.m_nTextures );
      }
      v65 = mesh;
      LODWORD(v145) = v57;
      m_pResourceBindings = DrawCall.m_pResourceBindings;
      HIDWORD(v145) = *nCurrentVBByteOffset;
      LODWORD(v146) = 4 * mesh->m_mesh.m_nVertexStrideFloats;
      v67 = v59;
      *(_QWORD *)&DrawCall.m_pResourceBindings[v67].m_nResourceIndex = v145;
      WORD2(v146) = 2;
      *(_QWORD *)&m_pResourceBindings[v67].m_nElementStride = v146;
      v157 = (unsigned int)v58;
      v68 = v59 + 1;
      *(_QWORD *)&m_pResourceBindings[v68].m_nResourceIndex = (unsigned int)v58;
      WORD2(v158) = 2;
      LODWORD(v158) = 4;
      *(_QWORD *)&m_pResourceBindings[v68].m_nElementStride = v158;
      v69 = v65->m_DrawData.m_Size;
      nDrawTextures = v65->m_Material.m_nTextures;
      v70 = v59 + 2;
      r = v70;
      nDrawDataCount = v69;
      n = 0;
      nTexScaleIndex = 0;
      if ( v69 * nDrawTextures <= nMaxTexScaleSlots )
      {
        DrawData = nullptr;
        if ( v69 > 0 )
        {
          nTotalIndices = 0;
          do
          {
            v107 = (int *)((char *)&mesh->m_DrawData.m_Memory.m_pMemory->m_VertexStart + nTotalIndices);
            v108 = v107[3];
            DrawData = (BuilderDrawData_t *)((char *)DrawData + v107[1]);
            nTexScaleIndex += v108;
            FirstAttributeOffset = CMesh::FindFirstAttributeOffset(
                                     this: &mesh->m_mesh,
                                     nType: VERTEX_ELEMENT_TEXCOORD2D_0);
            r = FirstAttributeOffset;
            if ( FirstAttributeOffset == -1 )
            {
              FirstAttributeOffset = CMesh::FindFirstAttributeOffset(
                                       this: &mesh->m_mesh,
                                       nType: VERTEX_ELEMENT_TEXCOORD3D_0);
              r = FirstAttributeOffset;
            }
            v110 = *v107;
            if ( *v107 < *v107 + v107[1] )
            {
              v111 = (float)n;
              while ( 1 )
              {
                mesh->m_mesh.m_pVerts[FirstAttributeOffset + 2 + v110 * mesh->m_mesh.m_nVertexStrideFloats] = v111;
                if ( ++v110 >= *v107 + v107[1] )
                  break;
                FirstAttributeOffset = r;
              }
            }
            if ( nDrawTextures > 0 )
            {
              v112 = (float *)(v107 + 6);
              v175 = (float *)(v107 + 6);
              r = nDrawTextures;
              do
              {
                v113 = v46[1].m_pMemory;
                v114 = v46->m_nAllocationCount;
                if ( (int)&v113->priority + 1 > v114 )
                {
                  CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: v46, num: (int)&v113->priority - v114 + 1);
                  v112 = v175;
                }
                ++v46[1].m_pMemory;
                v115 = v46->m_pMemory;
                v116 = (char *)v46[1].m_pMemory - (char *)v113 - 1;
                v46[1].m_nAllocationCount = (int)v46->m_pMemory;
                if ( v116 > 0 )
                {
                  _V_memmove(dest: &v115[(int)v113 + 1], src: &v115[(_DWORD)v113], count: 16 * v116);
                  v112 = v175;
                }
                p_priority = (float *)&v46->m_pMemory[(_DWORD)v113].priority;
                if ( p_priority != nullptr )
                {
                  *p_priority = *(v112 - 2);
                  p_priority[1] = *(v112 - 1);
                  p_priority[2] = *v112;
                  p_priority[3] = v112[1];
                }
                v112 += 4;
                v51 = r-- == 1;
                v175 = v112;
              }
              while ( !v51 );
            }
            nTotalIndices += 272;
            ++n;
          }
          while ( n < nDrawDataCount );
          m_pResourceBindings = DrawCall.m_pResourceBindings;
        }
        v104 = pbRemoveList;
        DrawCall.m_nVertexCount = (int)DrawData;
        DrawCall.m_nIndexCount = nTexScaleIndex;
        DrawCall.m_nStartIndex = nCurrentIBCountOffset;
        v118 = nTexScaleSlot;
        v119 = v70;
        v155 = (unsigned int)pbRemoveList;
        *(_QWORD *)&m_pResourceBindings[v119].m_nResourceIndex = (unsigned int)pbRemoveList;
        BYTE5(v156) = v118;
        BYTE4(v156) = 1;
        LODWORD(v156) = 0;
        v142 = 0;
        DrawCall.m_nBaseVertex = 0;
        *(_QWORD *)&m_pResourceBindings[v119].m_nElementStride = v156;
        v140 = 0;
      }
      else
      {
        nTotalIndices = 0;
        DrawCall.m_nBaseVertex = 0;
        DrawCall.m_nVertexCount = 0;
        DrawCall.m_nStartIndex = nCurrentIBCountOffset;
        DrawCall.m_nIndexCount = 0;
        nSlot = 0;
        if ( v69 > 0 )
        {
          v175 = nullptr;
          for ( nDrawDataCount = v69; nDrawDataCount != 0; --nDrawDataCount )
          {
            v71 = (BuilderDrawData_t *)((char *)v175 + (unsigned int)mesh->m_DrawData.m_Memory.m_pMemory);
            DrawData = v71;
            if ( nDrawTextures + nSlot <= nMaxTexScaleSlots )
            {
              m_VertexCount = v71->m_VertexCount;
              m_IndexCount = v71->m_IndexCount;
              DrawCall.m_nVertexCount += m_VertexCount;
              DrawCall.m_nIndexCount += m_IndexCount;
            }
            else
            {
              m_nBaseVertex = DrawCall.m_nBaseVertex;
              BYTE5(v154) = nTexScaleSlot;
              LODWORD(v154) = 0;
              v153 = (unsigned int)pbRemoveList;
              v73 = (unsigned int)pbRemoveList;
              v74 = &DrawCall.m_pResourceBindings[r];
              ++pbRemoveList;
              m_nVertexCount = DrawCall.m_nVertexCount;
              *(_QWORD *)&v74->m_nResourceIndex = v73;
              v141 = m_nVertexCount;
              v76 = mesh;
              BYTE4(v154) = 1;
              *(_QWORD *)&v74->m_nElementStride = v154;
              v77 = CBuilderMesh::CalculateBounds(this: v76, result: &v143, nVertStart: m_nBaseVertex, nVertCount: v141);
              v78 = v181;
              v79 = v181->m_BuilderDrawCalls.m_Size;
              DrawCall.m_Bounds.m_vMinBounds = v77->m_vMinBounds;
              DrawCall.m_Bounds.m_vMaxBounds.x = v77->m_vMaxBounds.x;
              DrawCall.m_Bounds.m_vMaxBounds.y = v77->m_vMaxBounds.y;
              *(float *)&v73 = v77->m_vMaxBounds.z;
              v80 = v181->m_BuilderDrawCalls.m_Memory.m_nAllocationCount;
              LODWORD(DrawCall.m_Bounds.m_vMaxBounds.z) = v73;
              if ( v79 + 1 > v80 )
                CUtlMemory<CDispMultiBlend,int>::Grow(this: &v181->m_BuilderDrawCalls.m_Memory, num: v79 - v80 + 1);
              ++v78->m_BuilderDrawCalls.m_Size;
              v81 = v78->m_BuilderDrawCalls.m_Memory.m_pMemory;
              v82 = v78->m_BuilderDrawCalls.m_Size - v79 - 1;
              v78->m_BuilderDrawCalls.m_pElements = v81;
              if ( v82 > 0 )
                _V_memmove(dest: &v81[v79 + 1], src: &v81[v79], count: 80 * v82);
              v83 = &v78->m_BuilderDrawCalls.m_Memory.m_pMemory[v79];
              if ( v83 != nullptr )
                *v83 = DrawCall;
              v84 = v181;
              v85 = v181->m_TexScales.m_Size;
              v86 = v181->m_TexScales.m_Memory.m_nAllocationCount;
              if ( v85 + 1 > v86 )
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&v181->m_TexScales,
                  num: v85 - v86 + 1);
              ++v84->m_TexScales.m_Size;
              v87 = v84->m_TexScales.m_Memory.m_pMemory;
              v88 = v84->m_TexScales.m_Size - v85 - 1;
              v84->m_TexScales.m_pElements = v87;
              if ( v88 > 0 )
                _V_memmove(dest: &v87[v85 + 1], src: &v87[v85], count: 4 * v88);
              v89 = (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> **)&v84->m_TexScales.m_Memory.m_pMemory[v85];
              if ( v89 != nullptr )
                *v89 = v46;
              DrawCall.m_nBaseVertex = n;
              DrawCall.m_nVertexCount = 0;
              DrawCall.m_nStartIndex = nCurrentIBCountOffset + nTotalIndices;
              DrawCall.m_nIndexCount = 0;
              v90 = (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)MemAlloc_Alloc(nSize: 0x14u);
              if ( v90 != nullptr )
              {
                v90->m_pMemory = nullptr;
                v90->m_nAllocationCount = 0;
                v90->m_nGrowSize = 0;
                v90[1].m_pMemory = nullptr;
                v90[1].m_nAllocationCount = 0;
                v46 = v90;
              }
              else
              {
                v46 = nullptr;
              }
              nSlot = 0;
              nTexScaleIndex = 0;
            }
            v93 = mesh;
            v94 = CMesh::FindFirstAttributeOffset(this: &mesh->m_mesh, nType: VERTEX_ELEMENT_TEXCOORD2D_0);
            if ( v94 == -1 )
              v94 = CMesh::FindFirstAttributeOffset(this: &v93->m_mesh, nType: VERTEX_ELEMENT_TEXCOORD3D_0);
            v95 = DrawData;
            m_VertexStart = DrawData->m_VertexStart;
            if ( DrawData->m_VertexStart < DrawData->m_VertexStart + DrawData->m_VertexCount )
            {
              v97 = (float)nTexScaleIndex;
              do
              {
                v93->m_mesh.m_pVerts[v94 + 2 + m_VertexStart * v93->m_mesh.m_nVertexStrideFloats] = v97;
                v95 = DrawData;
                ++m_VertexStart;
              }
              while ( m_VertexStart < DrawData->m_VertexCount + DrawData->m_VertexStart );
            }
            if ( nDrawTextures > 0 )
            {
              p_z = (BuilderDrawData_t *)&v95->m_vTextureScales[0].z;
              DrawData = (BuilderDrawData_t *)&v95->m_vTextureScales[0].z;
              v162 = nDrawTextures;
              do
              {
                v99 = v46[1].m_pMemory;
                v100 = v46->m_nAllocationCount;
                if ( (int)&v99->priority + 1 > v100 )
                {
                  CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: v46, num: (int)&v99->priority - v100 + 1);
                  p_z = DrawData;
                }
                ++v46[1].m_pMemory;
                v101 = v46->m_pMemory;
                v102 = (char *)v46[1].m_pMemory - (char *)v99 - 1;
                v46[1].m_nAllocationCount = (int)v46->m_pMemory;
                if ( v102 > 0 )
                {
                  _V_memmove(dest: &v101[(int)v99 + 1], src: &v101[(_DWORD)v99], count: 16 * v102);
                  p_z = DrawData;
                }
                v103 = (float *)&v46->m_pMemory[(_DWORD)v99].priority;
                if ( v103 != nullptr )
                {
                  *v103 = p_z[-1].m_vTextureScales[15].z;
                  v103[1] = p_z[-1].m_vTextureScales[15].w;
                  v103[2] = *(float *)&p_z->m_VertexStart;
                  v103[3] = *(float *)&p_z->m_VertexCount;
                }
                p_z = (BuilderDrawData_t *)((char *)p_z + 16);
                v51 = v162-- == 1;
                DrawData = p_z;
              }
              while ( !v51 );
            }
            nTotalIndices += v95->m_IndexCount;
            n += v95->m_VertexCount;
            nSlot += nDrawTextures;
            v175 += 68;
            ++nTexScaleIndex;
          }
          v70 = r;
          m_pResourceBindings = DrawCall.m_pResourceBindings;
        }
        v104 = pbRemoveList;
        v105 = DrawCall.m_nBaseVertex;
        BYTE5(v152) = nTexScaleSlot;
        v106 = v70;
        v151 = (unsigned int)pbRemoveList;
        *(_QWORD *)&m_pResourceBindings[v106].m_nResourceIndex = (unsigned int)pbRemoveList;
        BYTE4(v152) = 1;
        LODWORD(v152) = 0;
        *(_QWORD *)&m_pResourceBindings[v106].m_nElementStride = v152;
        v142 = DrawCall.m_nVertexCount;
        v140 = v105;
      }
      pbRemoveList = v104 + 1;
      v120 = CBuilderMesh::CalculateBounds(this: mesh, result: &v143, nVertStart: v140, nVertCount: v142);
      v121 = v181;
      v122 = v181->m_BuilderDrawCalls.m_Size;
      DrawCall.m_Bounds.m_vMinBounds = v120->m_vMinBounds;
      DrawCall.m_Bounds.m_vMaxBounds.x = v120->m_vMaxBounds.x;
      DrawCall.m_Bounds.m_vMaxBounds.y = v120->m_vMaxBounds.y;
      z = v120->m_vMaxBounds.z;
      v124 = v181->m_BuilderDrawCalls.m_Memory.m_nAllocationCount;
      DrawCall.m_Bounds.m_vMaxBounds.z = z;
      if ( v122 + 1 > v124 )
        CUtlMemory<CDispMultiBlend,int>::Grow(this: &v181->m_BuilderDrawCalls.m_Memory, num: v122 - v124 + 1);
      ++v121->m_BuilderDrawCalls.m_Size;
      v125 = v121->m_BuilderDrawCalls.m_Memory.m_pMemory;
      v126 = v121->m_BuilderDrawCalls.m_Size - v122 - 1;
      v121->m_BuilderDrawCalls.m_pElements = v125;
      if ( v126 > 0 )
        _V_memmove(dest: &v125[v122 + 1], src: &v125[v122], count: 80 * v126);
      v127 = &v121->m_BuilderDrawCalls.m_Memory.m_pMemory[v122];
      if ( v127 != nullptr )
        *v127 = DrawCall;
      v128 = v181;
      v129 = v181->m_TexScales.m_Size;
      v130 = v181->m_TexScales.m_Memory.m_nAllocationCount;
      if ( v129 + 1 > v130 )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v181->m_TexScales,
          num: v129 - v130 + 1);
      ++v128->m_TexScales.m_Size;
      v131 = v128->m_TexScales.m_Memory.m_pMemory;
      v132 = v128->m_TexScales.m_Size - v129 - 1;
      v128->m_TexScales.m_pElements = v131;
      if ( v132 > 0 )
        _V_memmove(dest: &v131[v129 + 1], src: &v131[v129], count: 4 * v132);
      v133 = (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> **)&v128->m_TexScales.m_Memory.m_pMemory[v129];
      if ( v133 != nullptr )
        *v133 = v46;
      v134 = (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)MemAlloc_Alloc(nSize: 0x14u);
      v46 = nullptr;
      if ( v134 != nullptr )
      {
        v134->m_pMemory = nullptr;
        v134->m_nAllocationCount = 0;
        v134->m_nGrowSize = 0;
        v134[1].m_pMemory = nullptr;
        v134[1].m_nAllocationCount = 0;
        v46 = v134;
      }
      v135 = mesh;
      v136 = mesh->m_mesh.m_nVertexCount * mesh->m_mesh.m_nVertexStrideFloats;
      v137 = *nCurrentVBByteOffset;
      i += 372;
      *nCurrentVBByteOffset = v137 + 4 * v136;
      nCurrentIBCountOffset += v135->m_mesh.m_nIndexCount;
      ++m;
    }
    while ( m < (int)pCombo );
  }
  if ( v46 != nullptr )
  {
    v46[1].m_pMemory = nullptr;
    if ( v46->m_nGrowSize >= 0 )
    {
      if ( v46->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v46->m_pMemory);
        v46->m_pMemory = nullptr;
      }
      v46->m_nAllocationCount = 0;
    }
    v138 = v46->m_pMemory;
    v46[1].m_nAllocationCount = (int)v46->m_pMemory;
    if ( v46->m_nGrowSize >= 0 )
    {
      if ( v138 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v138);
        v46->m_pMemory = nullptr;
      }
      v46->m_nAllocationCount = 0;
    }
    free(pMem: v46);
  }
  if ( UniqueHashes.m_Memory.m_nGrowSize >= 0 && UniqueHashes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: UniqueHashes.m_Memory.m_pMemory);
  if ( UniqueAtlasCombos.m_Memory.m_nGrowSize >= 0 && UniqueAtlasCombos.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: UniqueAtlasCombos.m_Memory.m_pMemory);
  return pbRemoveList;
}

//------------------------------------------------------------------------------
// Address: 0x0040B760
// Name: private: void CBVHNodeBuilder::CreateDrawCalls(class CResourceDictionaryBuilder __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::CreateDrawCalls(
        CBVHNodeBuilder *this,
        CResourceDictionaryBuilder *Dictionary,
        int nMaxTexScaleSlots)
{
  BVHNodeHeader_t *m_pHeader; // ecx
  int m_Flags; // edx
  bool *AtlasedDrawCalls; // eax
  BOOL v7; // [esp-8h] [ebp-Ch]

  m_pHeader = this->m_pHeader;
  m_Flags = m_pHeader->m_Flags;
  if ( (m_Flags & 1) != 0 )
  {
    CBVHNodeBuilder::CreateSimplifiedDrawCalls(this, nMaxTexScaleSlots, nLastResource: (m_Flags & 8) != 0);
  }
  else
  {
    v7 = (m_Flags & 8) != 0;
    if ( m_pHeader->m_nChildren != 0 )
      AtlasedDrawCalls = CBVHNodeBuilder::CreateAtlasedDrawCalls(this, nMaxTexScaleSlots, nLastResource: v7);
    else
      AtlasedDrawCalls = (bool *)CBVHNodeBuilder::CreateFullDetailDrawCalls(this, Dictionary, nLastResource: v7);
    CBVHNodeBuilder::CreateInstancedDrawCalls(this, Dictionary, nLastResource: (int)AtlasedDrawCalls);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B7D0
// Name: private: void CBVHNodeBuilder::CreateNodeGeometry(struct IDirect3DDevice9 __near *,struct BVHBuilderParams_t __near &,class CResourceDictionaryBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::CreateNodeGeometry(
        CBVHNodeBuilder *this,
        IDirect3DDevice9 *pd3dDevice,
        BVHBuilderParams_t *params,
        CResourceDictionaryBuilder *Dictionary)
{
  int m_nAtlasTextureSizeY; // edx
  int m_nAtlasTextureSizeX; // eax
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v7; // eax
  int v8; // edi
  int m_nCompressedAtlasSize; // eax
  int v10; // ecx
  int NumTotalIndices; // edi
  int NumTotalVertexBytes; // eax
  BVHNodeHeader_t *m_pHeader; // edx
  int v14; // edi
  int v15; // eax
  int m_Size; // esi
  CMesh **v17; // edi
  int v18; // eax
  int v19; // ecx
  CMeshVertexAttribute *AttributesForInputLayout; // eax
  int v21; // esi
  int v22; // edi
  BVHNodeHeader_t *v23; // eax
  int v24; // ecx
  int v25; // edx
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v27; // ecx
  int v28; // edi
  int m_nAllocationCount; // eax
  CBuilderMesh *v30; // ecx
  int v31; // eax
  CBuilderMesh *v32; // ecx
  int flGutterSize; // [esp+14h] [ebp-2ACh]
  int flMinDistance; // [esp+18h] [ebp-2A8h]
  unsigned int flMinDistancea; // [esp+18h] [ebp-2A8h]
  CBuilderMesh CollapsedMesh; // [esp+28h] [ebp-298h] BYREF
  AABB_t Bounds; // [esp+19Ch] [ebp-124h] BYREF
  BuilderMaterial_t material; // [esp+1B4h] [ebp-10Ch] BYREF
  int nPreviousAtlasCount; // [esp+2ACh] [ebp-14h]
  float flDistanceScale; // [esp+2B0h] [ebp-10h] BYREF
  int nAtlases; // [esp+2B4h] [ebp-Ch]
  int nTargetGeometryBytes; // [esp+2B8h] [ebp-8h]
  bool bUVMapped; // [esp+2BEh] [ebp-2h] BYREF
  bool bDone; // [esp+2BFh] [ebp-1h]

  if ( this->m_pHeader->m_nChildren != 0 )
  {
    nPreviousAtlasCount = 0;
    bDone = false;
    while ( 1 )
    {
      CBVHNodeBuilder::BakeInstances(this, flMinDistance: this->m_pHeader->m_flMinimumDistance);
      CBVHNodeBuilder::PerNodeOps(
        this,
        flMinDistToCamera: this->m_pHeader->m_flMinimumDistance,
        flHorzFOV: params->m_flHorzFOV,
        flHalfScreenWidth: params->m_flHalfScreenWidth,
        flGutterSize: params->m_flGutterSize,
        bWrapInAtlas: params->m_bWrapInAtlas);
      m_nAtlasTextureSizeY = params->m_nAtlasTextureSizeY;
      m_nAtlasTextureSizeX = params->m_nAtlasTextureSizeX;
      flDistanceScale = 1.0;
      v7 = CBVHNodeBuilder::CreateTextureAtlases(
             this,
             nAtlasTextureSizeX: m_nAtlasTextureSizeX,
             nAtlasTextureSizeY: m_nAtlasTextureSizeY,
             bEnforceCreation: true,
             flGutterSize: params->m_flGutterSize,
             pflDistanceScale: &flDistanceScale);
      flMinDistance = this->m_nAtlasTables;
      this->m_pAtlasTable = v7;
      v8 = CalculateTotalAtlases(pAtlasTable: v7, nAtlasTables: flMinDistance);
      m_nCompressedAtlasSize = params->m_nCompressedAtlasSize;
      this->m_pHeader->m_Flags |= 4u;
      v10 = params->m_nSizeBytesPerVoxel - v8 * m_nCompressedAtlasSize;
      nAtlases = v8;
      nTargetGeometryBytes = v10;
      if ( v10 > 10000 || nPreviousAtlasCount == v8 )
        break;
      this->m_pHeader->m_flMinimumDistance = this->m_pHeader->m_flMinimumDistance * 2.0;
      DestroyAtlasTable(pAtlasTable: this->m_pAtlasTable, nAtlasTables: this->m_nAtlasTables);
      this->m_pAtlasTable = nullptr;
      this->m_nAtlasTables = 0;
LABEL_37:
      nPreviousAtlasCount = v8;
      if ( bDone )
        return;
    }
    NumTotalIndices = CBVHNodeBuilder::GetNumTotalIndices(this);
    NumTotalVertexBytes = CBVHNodeBuilder::GetNumTotalVertexBytes(this);
    if ( NumTotalVertexBytes + 4 * NumTotalIndices <= nTargetGeometryBytes )
    {
      DestroyAtlasTable(pAtlasTable: this->m_pAtlasTable, nAtlasTables: this->m_nAtlasTables);
      m_pHeader = this->m_pHeader;
      this->m_pAtlasTable = nullptr;
      this->m_nAtlasTables = 0;
      CBVHNodeBuilder::PerNodeOps(
        this,
        flMinDistToCamera: m_pHeader->m_flMinimumDistance,
        flHorzFOV: params->m_flHorzFOV,
        flHalfScreenWidth: params->m_flHalfScreenWidth,
        flGutterSize: params->m_flGutterSize,
        bWrapInAtlas: params->m_bWrapInAtlas);
      this->m_pAtlasTable = CBVHNodeBuilder::CreateTextureAtlases(
                              this,
                              nAtlasTextureSizeX: params->m_nAtlasTextureSizeX,
                              nAtlasTextureSizeY: params->m_nAtlasTextureSizeY,
                              bEnforceCreation: true,
                              flGutterSize: params->m_flGutterSize,
                              pflDistanceScale: &flDistanceScale);
      this->m_pHeader->m_flMinimumDistance = this->m_pHeader->m_flMinimumDistance * flDistanceScale;
LABEL_36:
      v8 = nAtlases;
      bDone = true;
      goto LABEL_37;
    }
    CBVHNodeBuilder::BakeInstances(this, flMinDistance: 0.0);
    v14 = 0;
    if ( this->m_Meshes.m_Size > 0 )
    {
      nTargetGeometryBytes = 0;
      do
      {
        CBuilderMesh::ZeroFaceData(this: (CBuilderMesh *)((char *)this->m_Meshes.m_Memory.m_pMemory
                                                        + nTargetGeometryBytes));
        nTargetGeometryBytes += 372;
        ++v14;
      }
      while ( v14 < this->m_Meshes.m_Size );
    }
    v15 = params->m_nSizeBytesPerVoxel - params->m_nCompressedAtlasSize;
    nAtlases = 1;
    nTargetGeometryBytes = v15;
    CBuilderMesh::CBuilderMesh(this: &CollapsedMesh);
    m_Size = this->m_Meshes.m_Size;
    CollapsedMesh.m_Combo.m_nInputLayout = 0;
    CollapsedMesh.m_Combo.m_nIndicesPerFace = 3;
    v17 = (CMesh **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_Size >> 30 != 0 ? -1 : 4 * m_Size);
    v18 = 0;
    if ( m_Size > 0 )
    {
      v19 = 0;
      do
        v17[v18++] = &this->m_Meshes.m_Memory.m_pMemory[v19++].m_mesh;
      while ( v18 < m_Size );
    }
    flMinDistancea = (unsigned int)GetStrideForInputLayout(nLayout: 0) >> 2;
    flGutterSize = GetAttributeCountForInputLayout(nLayout: 0);
    AttributesForInputLayout = GetAttributesForInputLayout(nLayout: 0);
    ConcatMeshes(
      pMeshOut: &CollapsedMesh.m_mesh,
      ppMeshIn: v17,
      nInputMeshes: m_Size,
      pAttributeOverride: AttributesForInputLayout,
      nAttributeOverrideCount: flGutterSize,
      nStrideOverride: flMinDistancea);
    free(pMem: v17);
    v21 = this->m_Meshes.m_Size - 1;
    if ( v21 >= 0 )
    {
      v22 = v21;
      do
      {
        CBuilderMesh::~CBuilderMesh(this: &this->m_Meshes.m_Memory.m_pMemory[v22--]);
        --v21;
      }
      while ( v21 >= 0 );
    }
    this->m_Meshes.m_Size = 0;
    if ( this->m_Meshes.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_Meshes.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Meshes.m_Memory.m_pMemory);
        this->m_Meshes.m_Memory.m_pMemory = nullptr;
      }
      this->m_Meshes.m_Memory.m_nAllocationCount = 0;
    }
    this->m_Meshes.m_pElements = this->m_Meshes.m_Memory.m_pMemory;
    v23 = this->m_pHeader;
    bUVMapped = false;
    *(_QWORD *)&Bounds.m_vMinBounds.x = *(_QWORD *)&v23->m_Bounds.m_vMinBounds.x;
    *(_QWORD *)&Bounds.m_vMinBounds.z = *(_QWORD *)&v23->m_Bounds.m_vMinBounds.z;
    v24 = params->m_nAtlasTextureSizeY;
    v25 = params->m_nAtlasTextureSizeX;
    *(_QWORD *)&Bounds.m_vMaxBounds.y = *(_QWORD *)&v23->m_Bounds.m_vMaxBounds.y;
    CBuilderMesh::Simplify(
      this: &CollapsedMesh,
      &Bounds,
      nTargetGeometrySizeBytes: nTargetGeometryBytes,
      flBoundsEpsilon: 0.0099999998,
      nAtlasTextureSizeX: v25,
      nAtlasTextureSizeY: v24,
      flGutterSize: params->m_flGutterSize,
      flUVMapThreshold: params->m_flUVMapThreshold,
      &bUVMapped);
    this->m_pHeader->m_Flags &= ~4u;
    this->m_pHeader->m_Flags |= 1u;
    if ( bUVMapped )
    {
      this->m_pHeader->m_Flags |= 2u;
      CUtlString::CUtlString(this: &material.m_originalMaterialName);
      _V_memset(dest: &material, fill: 0, count: 248);
      material.m_Material.m_nBinds = 2;
      *(_WORD *)&material.m_Material.m_Binds[0].m_cBindStage = 4;
      material.m_Material.m_Binds[0].m_cBindSampler = 0;
      *(_WORD *)&material.m_Material.m_Binds[1].m_cBindStage = 260;
      material.m_Material.m_Binds[1].m_cBindSampler = 0;
      V_strncpy(pDest: material.m_Material.m_szShaderVS, pSrc: "maps\\worldgenericvs", maxLen: 48);
      V_strncpy(pDest: material.m_Material.m_szShaderPS, pSrc: "maps\\worldgenericps", maxLen: 48);
      material.m_ppTextures[0] = nullptr;
      material.m_ppTextures[1] = nullptr;
      material.m_nTextures = 2;
      CollapsedMesh.m_Material.m_Material = material.m_Material;
      CollapsedMesh.m_Material.m_ppTextures[0] = nullptr;
      CollapsedMesh.m_Material.m_ppTextures[1] = nullptr;
      CollapsedMesh.m_Material.m_ppTextures[4] = material.m_ppTextures[4];
      CollapsedMesh.m_Material.m_ppTextures[2] = material.m_ppTextures[2];
      CollapsedMesh.m_Material.m_ppTextures[3] = material.m_ppTextures[3];
      CollapsedMesh.m_Material.m_ppTextures[7] = material.m_ppTextures[7];
      CollapsedMesh.m_Material.m_ppTextures[5] = material.m_ppTextures[5];
      CollapsedMesh.m_Material.m_ppTextures[6] = material.m_ppTextures[6];
      CollapsedMesh.m_Material.m_ppTextures[10] = material.m_ppTextures[10];
      CollapsedMesh.m_Material.m_ppTextures[8] = material.m_ppTextures[8];
      CollapsedMesh.m_Material.m_ppTextures[9] = material.m_ppTextures[9];
      CollapsedMesh.m_Material.m_ppTextures[13] = material.m_ppTextures[13];
      CollapsedMesh.m_Material.m_ppTextures[11] = material.m_ppTextures[11];
      CollapsedMesh.m_Material.m_ppTextures[12] = material.m_ppTextures[12];
      CollapsedMesh.m_Material.m_nTextures = 2;
      CollapsedMesh.m_Material.m_ppTextures[14] = material.m_ppTextures[14];
      CollapsedMesh.m_Material.m_ppTextures[15] = material.m_ppTextures[15];
      CUtlString::operator=(
        this: &CollapsedMesh.m_Material.m_originalMaterialName,
        src: &material.m_originalMaterialName);
      material.m_originalMaterialName.m_Storage.m_nActualLength = 0;
      if ( material.m_originalMaterialName.m_Storage.m_Memory.m_nGrowSize < 0 )
        goto LABEL_29;
      m_pMemory = material.m_originalMaterialName.m_Storage.m_Memory.m_pMemory;
      if ( material.m_originalMaterialName.m_Storage.m_Memory.m_pMemory == nullptr )
        goto LABEL_29;
      v27 = _g_pMemAlloc;
    }
    else
    {
      CUtlString::CUtlString(this: &material.m_originalMaterialName);
      _V_memset(dest: &material, fill: 0, count: 248);
      material.m_Material.m_nBinds = 0;
      V_strncpy(pDest: material.m_Material.m_szShaderVS, pSrc: "maps\\worldgenericvs", maxLen: 48);
      V_strncpy(pDest: material.m_Material.m_szShaderPS, pSrc: "maps\\worldgenericps", maxLen: 48);
      material.m_nTextures = 0;
      material.m_Material.m_bVertexColor = true;
      CollapsedMesh.m_Material.m_Material = material.m_Material;
      qmemcpy(
        CollapsedMesh.m_Material.m_ppTextures,
        material.m_ppTextures,
        sizeof(CollapsedMesh.m_Material.m_ppTextures));
      CollapsedMesh.m_Material.m_nTextures = 0;
      CUtlString::operator=(
        this: &CollapsedMesh.m_Material.m_originalMaterialName,
        src: &material.m_originalMaterialName);
      material.m_originalMaterialName.m_Storage.m_nActualLength = 0;
      if ( material.m_originalMaterialName.m_Storage.m_Memory.m_nGrowSize < 0 )
        goto LABEL_29;
      m_pMemory = material.m_originalMaterialName.m_Storage.m_Memory.m_pMemory;
      if ( material.m_originalMaterialName.m_Storage.m_Memory.m_pMemory == nullptr )
        goto LABEL_29;
      v27 = _g_pMemAlloc;
    }
    v27->Free_2(this: v27, a2: m_pMemory);
LABEL_29:
    v28 = this->m_Meshes.m_Size;
    m_nAllocationCount = this->m_Meshes.m_Memory.m_nAllocationCount;
    if ( v28 + 1 > m_nAllocationCount )
      CUtlMemory<CBuilderMesh,int>::Grow(this: &this->m_Meshes.m_Memory, num: v28 - m_nAllocationCount + 1);
    ++this->m_Meshes.m_Size;
    v30 = this->m_Meshes.m_Memory.m_pMemory;
    v31 = this->m_Meshes.m_Size - v28 - 1;
    this->m_Meshes.m_pElements = v30;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 372 * v31);
    v32 = &this->m_Meshes.m_Memory.m_pMemory[v28];
    if ( v32 != nullptr )
      CBuilderMesh::CBuilderMesh(this: v32, Other: &CollapsedMesh);
    CBuilderMesh::~CBuilderMesh(this: &CollapsedMesh);
    goto LABEL_36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BE60
// Name: private: void CBVHNodeBuilder::SaveToDMXFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::SaveToDMXFile(CBVHNodeBuilder *this, const char *pMapName)
{
  char *m_pDMXName; // ebx
  int m_Size; // eax
  int v5; // esi
  int v6; // ebx
  CMesh **m_pMemory; // eax
  int v8; // [esp-4h] [ebp-28h]
  CUtlVector<CMesh *,CUtlMemory<CMesh *,int> > saveMeshes; // [esp+Ch] [ebp-18h] BYREF
  char *v10; // [esp+20h] [ebp-4h]

  v8 = g_nNodeCounter++;
  m_pDMXName = this->m_pDMXName;
  v10 = this->m_pDMXName;
  V_snprintf(pDest: this->m_pDMXName, maxLen: 260, pFormat: "maps/%s/nodegeometry%04d.dmx", pMapName, v8);
  m_Size = this->m_Meshes.m_Size;
  v5 = 0;
  memset(&saveMeshes, 0, sizeof(saveMeshes));
  if ( m_Size > 0 )
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&saveMeshes,
      elem: 0,
      num: m_Size);
  if ( this->m_Meshes.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      saveMeshes.m_Memory.m_pMemory[v5] = &this->m_Meshes.m_Memory.m_pMemory[v6].m_mesh;
      CUtlString::operator=(this: &saveMeshes.m_Memory.m_pMemory[v5++]->m_materialName, src: var);
      ++v6;
    }
    while ( v5 < this->m_Meshes.m_Size );
    m_pDMXName = v10;
  }
  if ( !SaveMeshesToDMX(inputMeshes: &saveMeshes, pDMXFile: m_pDMXName, bForce2DTexcoords: true) )
    _Warning(a1: "Cannot save mesh to dmx!\n");
  m_pMemory = saveMeshes.m_Memory.m_pMemory;
  saveMeshes.m_Size = 0;
  if ( saveMeshes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( saveMeshes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: saveMeshes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      saveMeshes.m_Memory.m_pMemory = nullptr;
    }
    saveMeshes.m_Memory.m_nAllocationCount = 0;
  }
  saveMeshes.m_pElements = m_pMemory;
  if ( saveMeshes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040BF60
// Name: private: void CBVHNodeBuilder::BuildOutResources(char const __near *,struct D3DParams_t __near &,struct BVHBuilderParams_t __near &,class CResourceDictionaryBuilder __near &,struct _iobuf __near *,class CWorldLighting __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBVHNodeBuilder::BuildOutResources(
        CBVHNodeBuilder *this,
        const char *pMapName,
        D3DParams_t *d3dparams,
        BVHBuilderParams_t *params,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp,
        CWorldLighting *pWorldLighting)
{
  int v9; // edi
  CBuilderMesh *v10; // ecx
  float flGutterSize; // xmm0_4
  int m_Flags; // edx
  int v13; // edi
  int v14; // ebx
  CResourceDictionaryBuilder *Dictionarya; // [esp+2Ch] [ebp+14h]

  CBVHNodeBuilder::CalculateNumVBsNeeded(this);
  CBVHNodeBuilder::SplitDrawCalls(this, flSplitSize: params->m_flMinDrawVolumeSize);
  CBVHNodeBuilder::CreateDrawCalls(this, Dictionary, nMaxTexScaleSlots: params->m_nMaxTexScaleSlots);
  if ( this->m_Meshes.m_Size > 0 )
  {
    v9 = 0;
    Dictionarya = (CResourceDictionaryBuilder *)this->m_Meshes.m_Size;
    do
    {
      v10 = &this->m_Meshes.m_Memory.m_pMemory[v9];
      if ( v10->m_Material.m_Material.m_bNormalMap )
        CBuilderMesh::ComputeTangentFrame(this: v10);
      ++v9;
      Dictionarya = (CResourceDictionaryBuilder *)((char *)Dictionarya - 1);
    }
    while ( Dictionarya != nullptr );
  }
  CBVHNodeBuilder::BuildMaterials(this, Dictionary, fp);
  flGutterSize = params->m_flGutterSize;
  m_Flags = this->m_pHeader->m_Flags;
  if ( (m_Flags & 1) != 0 )
  {
    if ( (m_Flags & 2) != 0 )
      CBVHNodeBuilder::BakeFromChildren(
        this,
        params: d3dparams,
        pMapName,
        nWidth: params->m_nUniqueTextureSizeX,
        nHeight: params->m_nUniqueTextureSizeY,
        flGutterSize,
        Dictionary,
        fp);
  }
  else if ( this->m_pHeader->m_nChildren != 0 )
  {
    CBVHNodeBuilder::BuildTextures(
      this,
      params: d3dparams,
      pMapName,
      Width: params->m_nAtlasTextureSizeX,
      Height: params->m_nAtlasTextureSizeY,
      flGutterSize,
      Dictionary,
      fp);
  }
  else
  {
    CBVHNodeBuilder::AddUniqueTextures(this, Dictionary, fp);
  }
  CBVHNodeBuilder::BuildVB(this, Dictionary, fp);
  CBVHNodeBuilder::BuildIB(this, Dictionary, fp);
  CBVHNodeBuilder::BuildScalingTextures(this, pMapName, Dictionary, fp, nMaxTexScales: params->m_nMaxTexScaleSlots);
  CBVHNodeBuilder::BuildInstanceData(this, Dictionary, fp);
  CBVHNodeBuilder::BuildLights(this, pWorldLighting, Dictionary, fp);
  CBVHNodeBuilder::SaveToDMXFile(this, pMapName);
  v13 = 0;
  if ( this->m_Meshes.m_Size > 0 )
  {
    v14 = 0;
    do
    {
      CMesh::FreeAllMemory(this: &this->m_Meshes.m_Memory.m_pMemory[v14].m_mesh);
      ++v13;
      ++v14;
    }
    while ( v13 < this->m_Meshes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C0B0
// Name: public: int CBVHNodeBuilder::CreateTree(char const __near *,struct D3DParams_t __near &,struct BVHBuilderParams_t __near &,class CResourceDictionaryBuilder __near &,struct _iobuf __near *,class CWorldLighting __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBVHNodeBuilder *__thiscall CBVHNodeBuilder::CreateTree(
        CBVHNodeBuilder *this,
        const char *pMapName,
        D3DParams_t *d3dparams,
        BVHBuilderParams_t *params,
        CResourceDictionaryBuilder *Dictionary,
        _iobuf *fp,
        CWorldLighting *pWorldLighting,
        bool bAttemptSplit)
{
  BVHBuilderParams_t *v8; // ebx
  bool m_bWrapInAtlas; // al
  float flMinDistToCamera; // xmm0_4
  int v11; // edi
  int NumTotalIndices; // edi
  int NumTotalVertexBytes; // eax
  int m_nSizeBytesPerVoxel; // ecx
  int v16; // edi
  int v17; // eax
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v18; // eax
  char *v19; // eax
  CBVHNodeBuilder *v20; // edi
  CBVHNodeBuilder *v21; // edi
  int v22; // eax
  int v23; // eax
  int v24; // ecx
  CBVHNodeBuilder *v25; // edi
  _DWORD *v26; // eax
  CBVHNodeBuilder *v27; // edi
  int v28; // eax
  int v29; // eax
  char *v30; // eax
  CBVHNodeBuilder *v31; // edi
  int v32; // edi
  float m_flMinimumDistance; // xmm0_4
  CBVHNodeBuilder **v34; // eax
  int v35; // eax
  CBVHNodeBuilder *v36; // edx
  CBVHNodeBuilder *m_Size; // eax
  char *v38; // eax
  CBVHNodeBuilder *v39; // eax
  char *v40; // eax
  int v41; // ecx
  const matrix3x4_t *v42; // ebx
  float v43; // edx
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *v44; // eax
  int v45; // ebx
  int m_nAllocationCount; // eax
  InstanceContainer_t *m_pMemory; // ecx
  int v48; // eax
  InstanceContainer_t *v49; // ebx
  CBVHNodeBuilder *Tree; // eax
  BVHNodeHeader_t *m_pHeader; // edx
  BVHNodeHeader_t *v52; // edx
  int m_nChildren; // ecx
  int v54; // eax
  CBVHNodeBuilder **v55; // edi
  int v56; // ecx
  int v57; // edi
  CBVHNodeBuilder *v59; // edi
  int v60; // ecx
  int v61; // eax
  CBVHNodeBuilder **v62; // edx
  int v63; // ecx
  CUtlMemory<S3RGBA,int> *v64; // ecx
  S3RGBA *v65; // ebx
  int v66; // eax
  CUtlMemory<S3RGBA,int> *v67; // edi
  S3RGBA *v68; // edx
  int v69; // eax
  CResourceDictionaryBuilder **v70; // ebx
  int v71; // edi
  int v72; // ebx
  CBVHNodeBuilder *m_pParentNode; // edi
  int v74; // ecx
  int v75; // eax
  CBVHNodeBuilder **v76; // edx
  int v77; // ecx
  CUtlMemory<S3RGBA,int> *v78; // ecx
  S3RGBA *v79; // ebx
  int v80; // eax
  CUtlMemory<S3RGBA,int> *v81; // edi
  S3RGBA *v82; // edx
  int v83; // eax
  CResourceDictionaryBuilder **v84; // ebx
  int v85; // edi
  int v86; // ebx
  BVHNodeHeader_t *v87; // eax
  int m_Flags; // ecx
  float m_flMinSimplifiedDist; // xmm0_4
  float flHorzFOV; // [esp+4h] [ebp-50h]
  float flHalfScreenWidth; // [esp+8h] [ebp-4Ch]
  int flHalfScreenWidtha; // [esp+8h] [ebp-4Ch]
  float flGutterSize; // [esp+Ch] [ebp-48h]
  int m_nAtlasTables; // [esp+10h] [ebp-44h]
  AABB_t v95; // [esp+20h] [ebp-34h] BYREF
  void *pMem; // [esp+38h] [ebp-1Ch]
  CBVHNodeBuilder *v97; // [esp+3Ch] [ebp-18h]
  float flDistanceScale; // [esp+40h] [ebp-14h] BYREF
  int nTotalLocal; // [esp+44h] [ebp-10h]
  CBVHNodeBuilder *pChild1; // [esp+48h] [ebp-Ch]
  CBVHNodeBuilder *pChild; // [esp+4Ch] [ebp-8h]
  bool bSplit; // [esp+53h] [ebp-1h]
  D3DParams_t *d3dparamsa; // [esp+60h] [ebp+Ch]
  D3DParams_t *d3dparamsb; // [esp+60h] [ebp+Ch]
  float flMaxMinCameraDistance; // [esp+64h] [ebp+10h]
  CResourceDictionaryBuilder *Dictionarya; // [esp+68h] [ebp+14h]
  CResourceDictionaryBuilder *Dictionaryb; // [esp+68h] [ebp+14h]
  int c2; // [esp+74h] [ebp+20h]
  int c2a; // [esp+74h] [ebp+20h]

  v8 = params;
  m_bWrapInAtlas = params->m_bWrapInAtlas;
  flGutterSize = params->m_flGutterSize;
  flHalfScreenWidth = params->m_flHalfScreenWidth;
  flHorzFOV = params->m_flHorzFOV;
  flMinDistToCamera = params->m_flMinDistToCamera;
  v11 = 0;
  pChild = nullptr;
  bSplit = false;
  CBVHNodeBuilder::PerNodeOps(
    this,
    flMinDistToCamera,
    flHorzFOV,
    flHalfScreenWidth,
    flGutterSize,
    bWrapInAtlas: m_bWrapInAtlas);
  if ( this->m_Meshes.m_Size > 0 )
  {
    nTotalLocal = 0;
    do
    {
      CBuilderMesh::RemoveRedundantVerts(this: (CBuilderMesh *)((char *)this->m_Meshes.m_Memory.m_pMemory + nTotalLocal));
      nTotalLocal += 372;
      ++v11;
    }
    while ( v11 < this->m_Meshes.m_Size );
  }
  if ( !bAttemptSplit )
  {
    this->m_pHeader->m_Flags |= 0x80u;
    goto LABEL_60;
  }
  NumTotalIndices = CBVHNodeBuilder::GetNumTotalIndices(this);
  NumTotalVertexBytes = CBVHNodeBuilder::GetNumTotalVertexBytes(this);
  m_nSizeBytesPerVoxel = params->m_nSizeBytesPerVoxel;
  v16 = NumTotalVertexBytes + 4 * NumTotalIndices;
  v17 = 0;
  flDistanceScale = 1.0;
  if ( v16 >= m_nSizeBytesPerVoxel )
  {
    bSplit = true;
  }
  else
  {
    v18 = CBVHNodeBuilder::CreateTextureAtlases(
            this,
            nAtlasTextureSizeX: params->m_nAtlasTextureSizeX,
            nAtlasTextureSizeY: params->m_nAtlasTextureSizeY,
            bEnforceCreation: true,
            flGutterSize: params->m_flGutterSize,
            pflDistanceScale: &flDistanceScale);
    m_nAtlasTables = this->m_nAtlasTables;
    this->m_pAtlasTable = v18;
    v17 = CalculateTotalAtlases(pAtlasTable: v18, nAtlasTables: m_nAtlasTables);
    m_nSizeBytesPerVoxel = v16 + v17 * params->m_nCompressedAtlasSize;
  }
  if ( m_nSizeBytesPerVoxel <= params->m_nSizeBytesPerVoxel && v17 >= 1 )
  {
    if ( !bSplit )
    {
LABEL_33:
      this->m_pHeader->m_flMinimumDistance = params->m_flMinDistToCamera;
      v30 = (char *)MemAlloc_Alloc(nSize: 0x2FCu);
      if ( v30 != nullptr )
      {
        v31 = (CBVHNodeBuilder *)(v30 + 4);
        *(_DWORD *)v30 = 1;
        CBVHNodeBuilder::CBVHNodeBuilder(this: (CBVHNodeBuilder *)(v30 + 4));
      }
      else
      {
        v31 = nullptr;
      }
      pChild = v31;
      CBVHNodeBuilder::AddChild(this, pChild: v31);
      m_Size = (CBVHNodeBuilder *)this->m_Meshes.m_Size;
      if ( (int)m_Size > 0 )
      {
        nTotalLocal = 0;
        for ( pChild1 = m_Size; pChild1 != nullptr; pChild1 = (CBVHNodeBuilder *)((char *)pChild1 - 1) )
        {
          v38 = (char *)this->m_Meshes.m_Memory.m_pMemory + nTotalLocal;
          CBVHNodeBuilder::AddMesh(
            this: v31,
            nVertexLayout: *(int **)v38,
            nIndicesPerFace: *((_DWORD *)v38 + 1),
            pVertices: *((float **)v38 + 2),
            pIndices: *((unsigned int **)v38 + 4),
            nIndices: *((_DWORD *)v38 + 8),
            material: (BuilderMaterial_t *)(v38 + 96),
            bFlipWinding: false);
          nTotalLocal += 372;
        }
      }
      v39 = (CBVHNodeBuilder *)this->m_InstanceContainers.m_Size;
      if ( (int)v39 > 0 )
      {
        v95.m_vMaxBounds.y = 0.0;
        v95.m_vMaxBounds.z = 0.0;
        nTotalLocal = 0;
        for ( pChild1 = v39; pChild1 != nullptr; pChild1 = (CBVHNodeBuilder *)((char *)pChild1 - 1) )
        {
          v40 = (char *)this->m_InstanceContainers.m_Memory.m_pMemory + nTotalLocal;
          v41 = *((_DWORD *)v40 + 1);
          v42 = *(const matrix3x4_t **)v41;
          v43 = *(float *)v40;
          pMem = *(void **)(v41 + 12);
          v95.m_vMinBounds.z = v43;
          v44 = (CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *)MemAlloc_Alloc(nSize: 0x14u);
          if ( v44 != nullptr )
          {
            v44->m_Memory.m_pMemory = nullptr;
            v44->m_Memory.m_nAllocationCount = 0;
            v44->m_Memory.m_nGrowSize = 0;
            v44->m_Size = 0;
            v44->m_pElements = nullptr;
          }
          else
          {
            v44 = nullptr;
          }
          flHalfScreenWidtha = v44->m_Size;
          LODWORD(v95.m_vMaxBounds.x) = v44;
          CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
            this: v44,
            elem: flHalfScreenWidtha,
            num: (int)pMem,
            pToInsert: v42);
          v45 = v31->m_InstanceContainers.m_Size;
          m_nAllocationCount = v31->m_InstanceContainers.m_Memory.m_nAllocationCount;
          if ( v45 + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&v31->m_InstanceContainers,
              num: v45 - m_nAllocationCount + 1);
          ++v31->m_InstanceContainers.m_Size;
          m_pMemory = v31->m_InstanceContainers.m_Memory.m_pMemory;
          v48 = v31->m_InstanceContainers.m_Size - v45 - 1;
          v31->m_InstanceContainers.m_pElements = m_pMemory;
          if ( v48 > 0 )
            _V_memmove(dest: &m_pMemory[v45 + 1], src: &m_pMemory[v45], count: 16 * v48);
          v49 = &v31->m_InstanceContainers.m_Memory.m_pMemory[v45];
          if ( v49 != nullptr )
          {
            *(_QWORD *)&v49->m_pInstanceGeometry = *(_QWORD *)&v95.m_vMinBounds.z;
            *(_QWORD *)&v49->m_nPerDrawTransformSets = *(_QWORD *)&v95.m_vMaxBounds.y;
          }
          nTotalLocal += 16;
        }
        v31 = pChild;
        v8 = params;
      }
      Tree = (CBVHNodeBuilder *)CBVHNodeBuilder::CreateTree(
                                  this: v31,
                                  pMapName,
                                  d3dparams,
                                  params: v8,
                                  Dictionary,
                                  fp,
                                  pWorldLighting,
                                  bAttemptSplit: false);
      m_pHeader = v31->m_pHeader;
      pChild = Tree;
      m_pHeader->m_flMinimumDistance = 0.0;
      goto LABEL_60;
    }
  }
  else
  {
    bSplit = true;
  }
  DestroyAtlasTable(pAtlasTable: this->m_pAtlasTable, nAtlasTables: this->m_nAtlasTables);
  this->m_pAtlasTable = nullptr;
  this->m_nAtlasTables = 0;
  v19 = (char *)MemAlloc_Alloc(nSize: 0x5F4u);
  if ( v19 != nullptr )
  {
    v20 = (CBVHNodeBuilder *)(v19 + 4);
    *(_DWORD *)v19 = 2;
    pChild1 = (CBVHNodeBuilder *)(v19 + 4);
    for ( nTotalLocal = 1; nTotalLocal >= 0; --nTotalLocal )
      CBVHNodeBuilder::CBVHNodeBuilder(this: v20++);
    v21 = pChild1;
  }
  else
  {
    v21 = nullptr;
  }
  pChild1 = v21 + 1;
  CBVHNodeBuilder::SplitNode(this, pChild1: v21, pChild2: v21 + 1, bSplitInHalf: false);
  nTotalLocal = CBVHNodeBuilder::GetNumTotalIndices(this);
  v22 = CBVHNodeBuilder::GetNumTotalIndices(this: v21);
  if ( v22 > nTotalLocal || (v23 = CBVHNodeBuilder::GetNumTotalIndices(this: pChild1)) > nTotalLocal )
  {
    if ( v21 != nullptr )
    {
      v24 = *(_DWORD *)&v21[-1].m_pDmeNodeName[256];
      pMem = &v21[-1].m_pDmeNodeName[256];
      v97 = &v21[v24];
      pChild1 = (CBVHNodeBuilder *)(v24 - 1);
      if ( v24 - 1 >= 0 )
      {
        v25 = &v21[v24];
        do
        {
          CBVHNodeBuilder::~CBVHNodeBuilder(this: --v25);
          pChild1 = (CBVHNodeBuilder *)((char *)pChild1 - 1);
        }
        while ( (int)pChild1 >= 0 );
      }
      free(pMem);
    }
    v26 = MemAlloc_Alloc(nSize: 0x5F4u);
    if ( v26 != nullptr )
    {
      v27 = (CBVHNodeBuilder *)(v26 + 1);
      *v26 = 2;
      pMem = v26 + 1;
      for ( pChild1 = (CBVHNodeBuilder *)1; (int)pChild1 >= 0; pChild1 = (CBVHNodeBuilder *)((char *)pChild1 - 1) )
        CBVHNodeBuilder::CBVHNodeBuilder(this: v27++);
      v21 = (CBVHNodeBuilder *)pMem;
    }
    else
    {
      v21 = nullptr;
    }
    pChild1 = v21 + 1;
    CBVHNodeBuilder::SplitNode(this, pChild1: v21, pChild2: v21 + 1, bSplitInHalf: true);
    _Msg(a1: "split node failed\n");
  }
  v28 = CBVHNodeBuilder::GetNumTotalIndices(this: v21);
  if ( v28 >= nTotalLocal )
  {
    v29 = CBVHNodeBuilder::GetNumTotalIndices(this: pChild1);
    if ( v29 >= nTotalLocal )
    {
      bSplit = false;
      goto LABEL_33;
    }
  }
  CBVHNodeBuilder::CalculateBounds(this: v21, result: &v95);
  CBVHNodeBuilder::CalculateBounds(this: pChild1, result: &v95);
  CBVHNodeBuilder::AddChild(this, pChild: v21);
  CBVHNodeBuilder::AddChild(this, pChild: pChild1);
  v32 = this->m_pHeader->m_nChildren - 1;
  m_flMinimumDistance = -3.4028235e38;
  flMaxMinCameraDistance = -3.4028235e38;
  if ( v32 >= 0 )
  {
    v34 = this->m_ChildNodeArray.m_Memory.m_pMemory;
    do
    {
      v35 = CBVHNodeBuilder::CreateTree(
              this: v34[v32],
              pMapName,
              d3dparams,
              params: v8,
              Dictionary,
              fp,
              pWorldLighting,
              bAttemptSplit: true);
      pChild = (CBVHNodeBuilder *)((char *)pChild + v35);
      v34 = this->m_ChildNodeArray.m_Memory.m_pMemory;
      v36 = v34[v32];
      m_flMinimumDistance = flMaxMinCameraDistance;
      if ( v36->m_pHeader->m_flMinimumDistance > flMaxMinCameraDistance )
      {
        m_flMinimumDistance = v36->m_pHeader->m_flMinimumDistance;
        flMaxMinCameraDistance = m_flMinimumDistance;
      }
      --v32;
    }
    while ( v32 >= 0 );
  }
  this->m_pHeader->m_flMinimumDistance = m_flMinimumDistance * 2.0;
LABEL_60:
  v52 = this->m_pHeader;
  m_nChildren = this->m_pHeader->m_nChildren;
  v54 = 0;
  if ( m_nChildren <= 0 )
  {
LABEL_66:
    if ( bSplit || !bAttemptSplit )
    {
      CBVHNodeBuilder::CreateNodeGeometry(this, pd3dDevice: d3dparams->m_pd3dDevice, params: v8, Dictionary);
      CBVHNodeBuilder::CalculateBounds(this, result: &v95);
      v87 = this->m_pHeader;
      m_Flags = this->m_pHeader->m_Flags;
      if ( (m_Flags & 1) != 0 )
      {
        m_flMinSimplifiedDist = v87->m_flMinimumDistance;
        if ( m_flMinSimplifiedDist <= v8->m_flMinSimplifiedDist )
          m_flMinSimplifiedDist = v8->m_flMinSimplifiedDist;
        v87->m_flMinimumDistance = m_flMinSimplifiedDist;
      }
      if ( (m_Flags & 4) != 0 && v8->m_flMinAtlasDist > this->m_pHeader->m_flMinimumDistance )
        CBVHNodeBuilder::AbsorbGrandchildren(this, nAndFlags: 4);
      CBVHNodeBuilder::BuildOutResources(this, pMapName, d3dparams, params: v8, Dictionary, fp, pWorldLighting);
      return (CBVHNodeBuilder *)((char *)pChild + 1);
    }
    else
    {
      if ( m_nChildren != 1 )
        _Warning(a1: "We didn't split, but we only have one child!\n");
      v57 = 0;
      if ( this->m_pHeader->m_nChildren > 0 )
      {
        while ( SLOBYTE(this->m_ChildNodeArray.m_Memory.m_pMemory[v57]->m_pHeader->m_Flags) >= 0 )
        {
          _Warning(a1: "Child is not most detailed child!\n");
          if ( ++v57 >= this->m_pHeader->m_nChildren )
            return pChild;
        }
        m_pParentNode = this->m_pParentNode;
        if ( m_pParentNode != nullptr )
        {
          v74 = m_pParentNode->m_ChildNodeArray.m_Size;
          v75 = 0;
          if ( v74 > 0 )
          {
            v76 = m_pParentNode->m_ChildNodeArray.m_Memory.m_pMemory;
            while ( *v76 != this )
            {
              ++v75;
              ++v76;
              if ( v75 >= v74 )
                goto LABEL_108;
            }
            if ( v75 != -1 )
            {
              v77 = v74 - v75 - 1;
              if ( v77 > 0 )
                _V_memmove(
                  dest: &m_pParentNode->m_ChildNodeArray.m_Memory.m_pMemory[v75],
                  src: &m_pParentNode->m_ChildNodeArray.m_Memory.m_pMemory[v75 + 1],
                  count: 4 * v77);
              --m_pParentNode->m_ChildNodeArray.m_Size;
            }
          }
LABEL_108:
          --m_pParentNode->m_pHeader->m_nChildren;
          for ( c2a = 0; c2a < this->m_pHeader->m_nChildren; ++c2a )
          {
            v78 = (CUtlMemory<S3RGBA,int> *)this->m_pParentNode;
            v79 = v78[11].m_pMemory;
            v80 = v78[10].m_nAllocationCount;
            v81 = v78 + 10;
            Dictionaryb = (CResourceDictionaryBuilder *)this->m_ChildNodeArray.m_Memory.m_pMemory[c2a];
            d3dparamsb = (D3DParams_t *)v78;
            if ( (int)&v79->g > v80 )
            {
              CUtlMemory<HemiLightData_t *,int>::Grow(this: v78 + 10, num: (int)(&v79->g - v80));
              v78 = (CUtlMemory<S3RGBA,int> *)d3dparamsb;
            }
            ++v81[1].m_pMemory;
            v82 = v81->m_pMemory;
            v83 = (char *)v81[1].m_pMemory - (char *)v79 - 1;
            v81[1].m_nAllocationCount = (int)v81->m_pMemory;
            if ( v83 > 0 )
            {
              _V_memmove(dest: &v82[(_DWORD)v79 + 1], src: &v82[(_DWORD)v79], count: 4 * v83);
              v78 = (CUtlMemory<S3RGBA,int> *)d3dparamsb;
            }
            v84 = (CResourceDictionaryBuilder **)&v81->m_pMemory[(_DWORD)v79];
            if ( v84 != nullptr )
              *v84 = Dictionaryb;
            ++*(_DWORD *)&v78->m_pMemory[16];
            *(_DWORD *)&Dictionaryb->m_pPageFile[60] = v78;
          }
        }
        else
        {
          _Warning(a1: "Root node points directly to an atlas node!\n");
        }
        v85 = 0;
        if ( this->m_Meshes.m_Size > 0 )
        {
          v86 = 0;
          do
          {
            CMesh::FreeAllMemory(this: &this->m_Meshes.m_Memory.m_pMemory[v86].m_mesh);
            ++v85;
            ++v86;
          }
          while ( v85 < this->m_Meshes.m_Size );
          return pChild;
        }
      }
    }
    return pChild;
  }
  v55 = this->m_ChildNodeArray.m_Memory.m_pMemory;
  while ( 1 )
  {
    v56 = (*v55)->m_pHeader->m_Flags;
    if ( (v56 & 1) != 0 && (v56 & 2) == 0 )
      break;
    ++v54;
    ++v55;
    if ( v54 >= v52->m_nChildren )
    {
      m_nChildren = v52->m_nChildren;
      goto LABEL_66;
    }
  }
  v59 = this->m_pParentNode;
  if ( v59 != nullptr )
  {
    v60 = v59->m_ChildNodeArray.m_Size;
    v61 = 0;
    if ( v60 > 0 )
    {
      v62 = v59->m_ChildNodeArray.m_Memory.m_pMemory;
      while ( *v62 != this )
      {
        ++v61;
        ++v62;
        if ( v61 >= v60 )
          goto LABEL_84;
      }
      if ( v61 != -1 )
      {
        v63 = v60 - v61 - 1;
        if ( v63 > 0 )
          _V_memmove(
            dest: &v59->m_ChildNodeArray.m_Memory.m_pMemory[v61],
            src: &v59->m_ChildNodeArray.m_Memory.m_pMemory[v61 + 1],
            count: 4 * v63);
        --v59->m_ChildNodeArray.m_Size;
      }
    }
LABEL_84:
    --v59->m_pHeader->m_nChildren;
    for ( c2 = 0; c2 < this->m_pHeader->m_nChildren; ++c2 )
    {
      v64 = (CUtlMemory<S3RGBA,int> *)this->m_pParentNode;
      v65 = v64[11].m_pMemory;
      v66 = v64[10].m_nAllocationCount;
      v67 = v64 + 10;
      Dictionarya = (CResourceDictionaryBuilder *)this->m_ChildNodeArray.m_Memory.m_pMemory[c2];
      d3dparamsa = (D3DParams_t *)v64;
      if ( (int)&v65->g > v66 )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(this: v64 + 10, num: (int)(&v65->g - v66));
        v64 = (CUtlMemory<S3RGBA,int> *)d3dparamsa;
      }
      ++v67[1].m_pMemory;
      v68 = v67->m_pMemory;
      v69 = (char *)v67[1].m_pMemory - (char *)v65 - 1;
      v67[1].m_nAllocationCount = (int)v67->m_pMemory;
      if ( v69 > 0 )
      {
        _V_memmove(dest: &v68[(_DWORD)v65 + 1], src: &v68[(_DWORD)v65], count: 4 * v69);
        v64 = (CUtlMemory<S3RGBA,int> *)d3dparamsa;
      }
      v70 = (CResourceDictionaryBuilder **)&v67->m_pMemory[(_DWORD)v65];
      if ( v70 != nullptr )
        *v70 = Dictionarya;
      ++*(_DWORD *)&v64->m_pMemory[16];
      *(_DWORD *)&Dictionarya->m_pPageFile[60] = v64;
    }
  }
  else
  {
    v52->m_Flags &= 0xFFFFFFF8;
    this->m_pHeader->m_Flags |= 0x10u;
  }
  v71 = 0;
  if ( this->m_Meshes.m_Size <= 0 )
    return pChild;
  v72 = 0;
  do
  {
    CMesh::FreeAllMemory(this: &this->m_Meshes.m_Memory.m_pMemory[v72].m_mesh);
    ++v71;
    ++v72;
  }
  while ( v71 < this->m_Meshes.m_Size );
  return pChild;
}

//------------------------------------------------------------------------------
// Address: 0x004049E0
// Name: class CDmElement __near * GetElement<class CDmElement>(enum DmElementHandle_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl GetElement<CDmElement>(DmElementHandle_t hElement)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: hElement);
  v2 = v1;
  if ( v1 != nullptr && v1->IsA(this: v1, a2: CDmElement::m_classType) )
    return v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405910
// Name: class CDmElement __near * CreateElement<class CDmElement>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl CreateElement<CDmElement>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
    return v5;
  else
    return nullptr;
}
