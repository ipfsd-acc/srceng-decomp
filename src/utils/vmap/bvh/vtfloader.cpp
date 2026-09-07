// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/vtfloader.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040DCB0
// Name: class IVTFTexture __near * LoadBasetexture(char __near *,int __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__cdecl LoadBasetexture(char *pszFileName, int *pFileSize, char *pVTFName)
{
  IVTFTexture *VTFTexture; // esi
  bool v5; // sf
  char szPath[260]; // [esp+4h] [ebp-134h] BYREF
  CUtlBuffer temp; // [esp+108h] [ebp-30h] BYREF

  if ( V_GetFileExtension(path: pszFileName) != nullptr )
    V_snprintf(pDest: szPath, maxLen: 260, pFormat: "materials/%s", pszFileName);
  else
    V_snprintf(pDest: szPath, maxLen: 260, pFormat: "materials/%s.vtf", pszFileName);
  CUtlBuffer::CUtlBuffer(this: &temp, growSize: 0, initSize: 0, nFlags: 0);
  if ( !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: szPath,
          a3: "GAME",
          a4: &temp,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    _Msg(a1: "Cannot load %s\n", szPath);
LABEL_6:
    if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
    return nullptr;
  }
  if ( pVTFName != nullptr )
    V_strncpy(pDest: pVTFName, pSrc: szPath, maxLen: 128);
  VTFTexture = CreateVTFTexture();
  if ( !VTFTexture->Unserialize(this: VTFTexture, a2: &temp, a3: false, a4: 0) )
  {
    _Error(a1: "Invalid or corrupt background texture %s\n", szPath);
    goto LABEL_6;
  }
  v5 = temp.m_Memory.m_nGrowSize < 0;
  *pFileSize = temp.m_Memory.m_nAllocationCount;
  if ( !v5 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
  return VTFTexture;
}

//------------------------------------------------------------------------------
// Address: 0x0040DDF0
// Name: struct IDirect3DTexture9 __near * LoadBaseVTFIntoTexture(struct IDirect3DDevice9 __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
IDirect3DTexture9 *__usercall LoadBaseVTFIntoTexture@<eax>(
        int a1@<ebx>,
        IDirect3DDevice9 *pd3dDevice,
        char *pszFileName)
{
  IVTFTexture *v3; // eax
  IVTFTexture *v4; // esi
  ImageFormat v6; // eax
  _D3DFORMAT v7; // eax
  IVTFTexture_vtbl *v8; // edx
  IDirect3DDevice9_vtbl *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int (__thiscall *MipCount)(IVTFTexture *); // eax
  unsigned int v14; // ebx
  _D3DFORMAT v15; // edi
  unsigned int v16; // ebx
  int v17; // ebx
  int v18; // eax
  unsigned __int8 *pBits; // edi
  int v20; // edi
  int (__thiscall *v21)(IVTFTexture *); // edx
  _D3DLOCKED_RECT rect; // [esp+8h] [ebp-28h] BYREF
  int MipD; // [esp+10h] [ebp-20h] BYREF
  int MipW; // [esp+14h] [ebp-1Ch] BYREF
  int h; // [esp+18h] [ebp-18h]
  _D3DFORMAT fmt; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *pSrcData; // [esp+20h] [ebp-10h]
  IDirect3DTexture9 *pTexture; // [esp+24h] [ebp-Ch] BYREF
  int i; // [esp+28h] [ebp-8h]
  int MipH; // [esp+2Ch] [ebp-4h] BYREF

  pTexture = nullptr;
  v3 = LoadBasetexture(pszFileName, pFileSize: &MipW, pVTFName: nullptr);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v6 = v3->Format(this: v3);
    v7 = ImageLoader::ImageFormatToD3DFormat(format: v6);
    v8 = v4->__vftable;
    v9 = pd3dDevice->__vftable;
    fmt = v7;
    v10 = ((int (__thiscall *)(IVTFTexture *, _DWORD, _D3DFORMAT, int, IDirect3DTexture9 **, _DWORD))v8->MipCount)(
            a1: v4,
            a2: 0,
            a3: v7,
            a4: 1,
            a5: &pTexture,
            a6: 0);
    v11 = ((int (__thiscall *)(IVTFTexture *, int))v4->Height)(a1: v4, a2: v10);
    v12 = ((int (__thiscall *)(IVTFTexture *, int))v4->Width)(a1: v4, a2: v11);
    if ( ((int (__stdcall *)(IDirect3DDevice9 *, int))v9->CreateTexture)(a1: pd3dDevice, a2: v12) >= 0 )
    {
      MipCount = v4->MipCount;
      v14 = 0;
      i = 0;
      if ( MipCount(this: v4) > 0 )
      {
        while ( 1 )
        {
          v15 = fmt;
          ((void (__thiscall *)(IVTFTexture *, unsigned int, int *, int *, int *, int))v4->ComputeMipLevelDimensions)(
            a1: v4,
            a2: v14,
            a3: &MipW,
            a4: &MipH,
            a5: &MipD,
            a6: a1);
          pTexture->LockRect(this: pTexture, a2: v14, a3: &rect, a4: nullptr, a5: 0);
          v16 = v4->RowSizeInBytes(this: v4, a2: v14);
          if ( v16 == 0
            && (v15 == D3DFMT_DXT1
             || v15 == D3DFMT_DXT2
             || v15 == D3DFMT_DXT3
             || v15 == D3DFMT_DXT4
             || v15 == D3DFMT_DXT5) )
          {
            v17 = 0;
            if ( MipW > 0 )
            {
              v17 = 1;
              if ( MipW / 4 >= 1 )
                v17 = MipW / 4;
            }
            v18 = 0;
            if ( MipH > 0 )
            {
              v18 = MipH / 4;
              if ( MipH / 4 < 1 )
                v18 = 1;
            }
            MipH = v18;
            v16 = (8 * (v15 != D3DFMT_DXT1) + 8) * v17;
          }
          pBits = (unsigned __int8 *)rect.pBits;
          pSrcData = v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: i);
          for ( h = 0; h < MipH; ++h )
          {
            memcpy(dst: pBits, src: pSrcData, count: v16);
            pSrcData += v16;
            pBits += rect.Pitch;
          }
          v20 = i;
          a1 = i;
          ((void (__stdcall *)(IDirect3DTexture9 *))pTexture->UnlockRect)(a1: pTexture);
          v21 = v4->MipCount;
          i = v20 + 1;
          if ( v20 + 1 >= v21(this: v4) )
            break;
          v14 = i;
        }
      }
      DestroyVTFTexture(pTexture: v4);
      return pTexture;
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    _Msg(a1: "Cannot load vtf: %s\n", pszFileName);
    return nullptr;
  }
}
