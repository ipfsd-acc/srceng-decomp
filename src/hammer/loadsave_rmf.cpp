// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/loadsave_rmf.cpp
// Functions: 8
// ============================================================

#include "hammer\loadsave_rmf.h"

//------------------------------------------------------------------------------
// Address: 0x1004CB20
// Name: float GetFileVersion(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetFileVersion()
{
  return fThisVersion;
}

//------------------------------------------------------------------------------
// Address: 0x1004CC50
// Name: public: int CMapFace::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFace::SerializeRMF(CMapFace *this, std::fstream *file, int fIsStoring)
{
  float x; // xmm0_4
  unsigned int q2surface; // eax
  unsigned __int8 material; // dl
  unsigned __int8 smooth; // cl
  float rotate; // xmm0_4
  unsigned int q2contents; // ecx
  float v10; // xmm0_4
  int nLightmapScale; // edx
  float v12; // xmm0_4
  std::ostream *v13; // esi
  Vector *Points; // edx
  float *p_y; // eax
  float *p_z; // ecx
  int v17; // edx
  int i; // edi
  double v19; // st7
  float v20; // xmm0_4
  unsigned __int8 v21; // al
  unsigned int v22; // edx
  unsigned __int8 v23; // cl
  float v24; // xmm0_4
  unsigned int v25; // eax
  float v26; // xmm0_4
  int v27; // eax
  float v28; // eax
  unsigned __int8 v29; // dl
  float v30; // xmm0_4
  float v31; // ecx
  unsigned int v32; // ecx
  unsigned int v33; // edx
  float v34; // xmm0_4
  signed int j; // eax
  TEXTURE *p_texture; // eax
  char v37; // cl
  int v38; // eax
  int v39; // edi
  char *v40; // eax
  char v41; // cl
  int v42; // edx
  float v43; // xmm1_4
  int v44; // eax
  int k; // ecx
  float v46; // xmm0_4
  double v47; // st7
  CEditDispMgr *v48; // eax
  int v49; // esi
  CEditDispMgr *v50; // eax
  CEditDispMgr *v51; // eax
  CMapDisp *v52; // esi
  float version[4]; // [esp+10h] [ebp-1AACh] BYREF
  Vector v55; // [esp+C10h] [ebp-EACh] BYREF
  float v56; // [esp+C1Ch] [ebp-EA0h]
  Vector pPoints; // [esp+C20h] [ebp-E9Ch]
  float y; // [esp+C2Ch] [ebp-E90h]
  float z; // [esp+C30h] [ebp-E8Ch]
  char v60[320]; // [esp+1810h] [ebp-2ACh] BYREF
  char v61[320]; // [esp+1950h] [ebp-16Ch] BYREF
  _DWORD v62[9]; // [esp+1A90h] [ebp-2Ch] BYREF
  char v63[4]; // [esp+1AB4h] [ebp-8h] BYREF
  char v64[4]; // [esp+1AB8h] [ebp-4h] BYREF

  if ( fIsStoring != 0 )
  {
    memset(dst: (unsigned __int8 *)v61, value: 0, count: sizeof(v61));
    x = this->texture.UAxis.x;
    q2surface = this->texture.q2surface;
    material = this->texture.material;
    qmemcpy(v61, &this->texture, 0x104u);
    smooth = this->texture.smooth;
    *(float *)&v61[260] = x;
    *(float *)&v61[264] = this->texture.UAxis.y;
    *(float *)&v61[268] = this->texture.UAxis.z;
    *(float *)&v61[272] = this->texture.UAxis.w;
    *(float *)&v61[276] = this->texture.VAxis.x;
    *(float *)&v61[280] = this->texture.VAxis.y;
    *(float *)&v61[284] = this->texture.VAxis.z;
    *(float *)&v61[288] = this->texture.VAxis.w;
    rotate = this->texture.rotate;
    v61[304] = smooth;
    q2contents = this->texture.q2contents;
    *(float *)&v61[292] = rotate;
    v10 = this->texture.scale[0];
    *(_DWORD *)&v61[308] = q2surface;
    v61[305] = material;
    nLightmapScale = this->texture.nLightmapScale;
    *(float *)&v61[296] = v10;
    v12 = this->texture.scale[1];
    *(_DWORD *)&v61[312] = q2contents;
    v13 = (std::ostream *)file->gap10;
    *(float *)&v61[300] = v12;
    *(_DWORD *)&v61[316] = nLightmapScale;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: v61, _Count: 320);
    *(_DWORD *)v64 = this->nPoints;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: v64, _Count: 4);
    if ( *(int *)v64 > 0 )
    {
      Points = this->Points;
      p_y = &v55.y;
      p_z = &Points->z;
      v17 = (char *)Points - (char *)&v55.y;
      for ( i = *(_DWORD *)v64; i != 0; --i )
      {
        v19 = *(float *)((char *)p_y + v17);
        p_y += 3;
        *(p_y - 4) = v19;
        p_z += 3;
        *(p_y - 3) = *(p_z - 4);
        *(p_y - 2) = *(p_z - 3);
      }
    }
    std::ostream::write(this: v13, _Str: (const char *)&v55, _Count: (unsigned int)(12 * this->nPoints));
    v55 = this->plane.planepts[0];
    v56 = this->plane.planepts[1].x;
    pPoints = *(Vector *)&this->plane.planepts[1].y;
    y = this->plane.planepts[2].y;
    z = this->plane.planepts[2].z;
    std::ostream::write(this: v13, _Str: (const char *)&v55, _Count: 36);
    return -((*(_DWORD *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4) + 12] & 4) != 0);
  }
  memset(dst: (unsigned __int8 *)&v61[24], value: 0, count: 0x128u);
  if ( fThisVersion >= 0.89999998 )
  {
    if ( fThisVersion >= 1.2 )
    {
      if ( fThisVersion >= 1.7 )
      {
        if ( fThisVersion >= 1.8 )
        {
          if ( fThisVersion >= 2.2 )
          {
            memset(dst: (unsigned __int8 *)v60, value: 0, count: sizeof(v60));
            std::istream::read(this: file, _Str: v60, _Count: 320);
            v20 = *(float *)&v60[260];
            v21 = v60[304];
            v22 = *(_DWORD *)&v60[308];
            qmemcpy(&this->texture, v60, 260);
            this->texture.UAxis.x = v20;
            this->texture.UAxis.y = *(float *)&v60[264];
            v23 = v60[305];
            this->texture.UAxis.z = *(float *)&v60[268];
            this->texture.UAxis.w = *(float *)&v60[272];
            this->texture.VAxis.x = *(float *)&v60[276];
            this->texture.VAxis.y = *(float *)&v60[280];
            this->texture.VAxis.z = *(float *)&v60[284];
            this->texture.VAxis.w = *(float *)&v60[288];
            v24 = *(float *)&v60[292];
            this->texture.smooth = v21;
            v25 = *(_DWORD *)&v60[312];
            this->texture.rotate = v24;
            v26 = *(float *)&v60[296];
            this->texture.q2contents = v25;
            v27 = *(_DWORD *)&v60[316];
            this->texture.scale[0] = v26;
            this->texture.scale[1] = *(float *)&v60[300];
            this->texture.material = v23;
            this->texture.q2surface = v22;
            this->texture.nLightmapScale = v27;
            if ( v27 == 0 )
              this->texture.nLightmapScale = g_pGameConfig->m_nDefaultLightmapScale;
          }
          else
          {
            std::istream::read(this: file, _Str: &v61[24], _Count: 296);
          }
        }
        else
        {
          std::istream::read(this: file, _Str: &v61[24], _Count: 40);
          std::istream::read(this: file, _Str: &v61[284], _Count: 36);
        }
      }
      else
      {
        std::istream::read(this: file, _Str: &v61[24], _Count: 40);
        std::istream::read(this: file, _Str: &v61[284], _Count: 24);
      }
    }
    else
    {
      std::istream::read(this: file, _Str: &v61[24], _Count: 40);
      std::istream::read(this: file, _Str: &v61[24], _Count: 20);
    }
  }
  else
  {
    std::istream::read(this: file, _Str: &v61[24], _Count: 16);
    v61[40] = 0;
    std::istream::read(this: file, _Str: &v61[284], _Count: 20);
  }
  if ( fThisVersion < 2.2 )
  {
    v28 = *(float *)&v61[296];
    v29 = v61[304];
    v30 = *(float *)&v61[284];
    qmemcpy(&this->texture, &v61[24], 260);
    v31 = *(float *)&v61[300];
    this->texture.scale[0] = v28;
    LOBYTE(v28) = v61[305];
    this->texture.scale[1] = v31;
    v32 = *(_DWORD *)&v61[308];
    this->texture.smooth = v29;
    v33 = *(_DWORD *)&v61[312];
    this->texture.rotate = v30;
    v34 = *(float *)&v61[288];
    this->texture.material = LOBYTE(v28);
    this->texture.q2surface = v32;
    this->texture.q2contents = v33;
    this->texture.UAxis.w = v34;
    this->texture.VAxis.w = *(float *)&v61[292];
  }
  if ( fThisVersion < 1.8 )
    this->texture.texture[40] = 0;
  if ( g_pGameConfig->textureformat != tfVMT )
  {
    for ( j = strlen(this->texture.texture) - 1; j >= 0; --j )
    {
      if ( this->texture.texture[j] == 47 )
        this->texture.texture[j] = 92;
    }
  }
  if ( this->texture.texture[1] == 58 )
  {
    p_texture = &this->texture;
    do
    {
      v37 = p_texture->texture[0];
      p_texture->texture[&v60[60] - (char *)&this->texture] = p_texture->texture[0];
      p_texture = (TEXTURE *)((char *)p_texture + 1);
    }
    while ( v37 != 0 );
    strstr(str1: (unsigned __int8 *)&v60[60], str2: "textures\\");
    v39 = v38;
    if ( v38 != 0 )
    {
      memset(dst: (unsigned __int8 *)&this->texture, value: 0, count: 0x104u);
      v40 = (char *)(v39 + 9);
      do
      {
        v41 = *v40;
        v40[(_DWORD)((char *)&this->m_pParent - v39 + 3)] = *v40;
        ++v40;
      }
      while ( v41 != 0 );
    }
  }
  if ( fThisVersion < 0.60000002 )
    std::istream::read(this: file, _Str: (char *)&fIsStoring, _Count: 4);
  std::istream::read(this: file, _Str: v64, _Count: 4);
  std::istream::read(this: file, _Str: (char *)version, _Count: (unsigned int)(12 * *(_DWORD *)v64));
  v42 = *(_DWORD *)v64;
  v43 = fThisVersion;
  if ( *(int *)v64 > 0 )
  {
    v44 = 0;
    for ( k = *(_DWORD *)v64; k != 0; --k )
    {
      v46 = version[v44 + 2];
      *(float *)((char *)&v55.x + v44 * 4) = version[v44];
      v47 = version[v44 + 1];
      *(float *)((char *)&v55.z + v44 * 4) = v46;
      *(float *)((char *)&v55.y + v44 * 4) = v47;
      if ( v43 < 0.5 )
        *(float *)((char *)&v55.z + v44 * 4) = -v46;
      v44 += 3;
    }
  }
  if ( v43 < 2.2 )
  {
    CMapFace::CreateFace(this, pPoints: &v55, _nPoints: v42, bIsCordonFace: false);
    v43 = fThisVersion;
  }
  if ( v43 < 0.69999999 )
    goto LABEL_45;
  std::istream::read(this: file, _Str: (char *)v62, _Count: 36);
  qmemcpy(this->plane.planepts, v62, sizeof(this->plane.planepts));
  CMapFace::CalcPlane(this);
  v43 = fThisVersion;
  if ( fThisVersion < 2.2 )
  {
    CMapFace::InitializeTextureAxes(this, eAlignment: TEXTURE_ALIGN_QUAKE, dwFlags: 3u);
    v43 = fThisVersion;
LABEL_45:
    if ( v43 < 2.2 )
    {
      CMapFace::SetTexture(this, pszNewTex: this->texture.texture, bRescaleTextureCoordinates: false);
      v43 = fThisVersion;
    }
  }
  if ( v43 >= 3.4000001 && v43 <= 3.5999999 )
  {
    if ( v43 < 3.5 )
    {
      std::istream::read(this: file, _Str: (char *)&fIsStoring + 3, _Count: 1);
    }
    else
    {
      std::istream::read(this: file, _Str: v63, _Count: 4);
      HIBYTE(fIsStoring) = *(_DWORD *)v63 != 0;
    }
    if ( HIBYTE(fIsStoring) != 0 )
    {
      v48 = EditDispMgr();
      v49 = v48->Create(this: v48);
      if ( this->m_DispHandle != 0xFFFF )
      {
        v50 = EditDispMgr();
        v50->Destroy(this: v50, a2: this->m_DispHandle);
      }
      this->m_DispHandle = v49;
      v51 = EditDispMgr();
      v52 = v51->GetDisp(this: v51, a2: v49);
      v52->SetParent(this: v52, a2: this);
      CMapDisp::SerializedLoadRMF(this: v52, file, pFace: this, version: fThisVersion);
    }
    v43 = fThisVersion;
  }
  if ( v43 >= 2.2 )
  {
    CMapFace::CreateFace(this, pPoints: &v55, _nPoints: *(int *)v64, bIsCordonFace: false);
    CMapFace::SetTexture(this, pszNewTex: this->texture.texture, bRescaleTextureCoordinates: false);
  }
  return -((*(_DWORD *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4) + 12] & 4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004D4E0
// Name: public: int MDkeyvalue::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MDkeyvalue::SerializeRMF(MDkeyvalue *this, std::fstream *file, int fIsStoring)
{
  std::fstream *v4; // ebx
  char *szValue; // edi

  v4 = file;
  if ( fIsStoring != 0 )
  {
    HIBYTE(fIsStoring) = strlen(this->szKey) + 1;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&fIsStoring + 3, _Count: 1);
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: this->szKey, _Count: HIBYTE(fIsStoring));
    szValue = this->szValue;
    HIBYTE(file) = strlen(szValue) + 1;
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)&file + 3, _Count: 1);
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: szValue, _Count: HIBYTE(file));
  }
  else
  {
    std::istream::read(this: file, _Str: (char *)&file + 3, _Count: 1);
    std::istream::read(this: v4, _Str: this->szKey, _Count: HIBYTE(file));
    std::istream::read(this: v4, _Str: (char *)&file + 3, _Count: 1);
    std::istream::read(this: v4, _Str: this->szValue, _Count: HIBYTE(file));
  }
  return -((*(_DWORD *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4) + 12] & 4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004D5C0
// Name: public: int CEditGameClass::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditGameClass::SerializeRMF(CEditGameClass *this, std::fstream *file, int fIsStoring)
{
  CEditGameClass *v3; // esi
  std::ostream *v4; // ebx
  unsigned __int16 i; // ax
  int Inorder; // eax
  int v7; // esi
  int v9; // edi
  MDkeyvalue KeyValue; // [esp+Ch] [ebp-2FCh] BYREF
  char buf[128]; // [esp+25Ch] [ebp-ACh] BYREF
  int nSpawnFlags; // [esp+2DCh] [ebp-2Ch] BYREF
  int nTime; // [esp+2E0h] [ebp-28h] BYREF
  CEditGameClass *v14; // [esp+2E4h] [ebp-24h]
  int bTimeline; // [esp+2E8h] [ebp-20h] BYREF
  int iAngle; // [esp+2ECh] [ebp-1Ch] BYREF
  int z; // [esp+2F0h] [ebp-18h]
  int iSize; // [esp+2F4h] [ebp-14h] BYREF
  char _Str; // [esp+2FBh] [ebp-Dh] BYREF
  int v20; // [esp+304h] [ebp-4h]

  v3 = this;
  v14 = this;
  iAngle = 0;
  if ( fIsStoring != 0 )
  {
    _Str = strlen(this->m_szClass) + 1;
    v4 = (std::ostream *)file->gap10;
    std::ostream::write(this: (std::ostream *)file->gap10, &_Str, _Count: 1);
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: v3->m_szClass, _Count: (unsigned __int8)_Str);
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&iAngle, _Count: 4);
    nSpawnFlags = (int)CEditGameClass::GetSpawnFlags(this: v3);
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&nSpawnFlags, _Count: 4);
    iSize = 0;
    for ( i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
          i != 0xFFFF;
          i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                i) )
    {
      ++iSize;
    }
    std::ostream::write(this: v4, _Str: (const char *)&iSize, _Count: 4);
    Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
    z = Inorder;
    if ( (unsigned __int16)Inorder == 0xFFFF )
    {
LABEL_5:
      bTimeline = 0;
      nTime = 0;
      std::ostream::write(this: v4, _Str: (const char *)&bTimeline, _Count: 4);
      std::ostream::write(this: v4, _Str: (const char *)&nTime, _Count: 4);
      std::ostream::write(this: v4, _Str: (const char *)&nTime, _Count: 4);
      return -((*(_DWORD *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4) + 12] & 4) != 0);
    }
    while ( 1 )
    {
      KeyValue = v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem;
      v20 = 0;
      v7 = MDkeyvalue::SerializeRMF(this: &KeyValue, file, fIsStoring);
      if ( v7 < 0 )
        break;
      v20 = -1;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
      z = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                              this: &v14->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                              i: z);
      if ( z == 0xFFFF )
        goto LABEL_5;
      v3 = v14;
      LOWORD(Inorder) = z;
    }
    v20 = -1;
    CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
    return v7;
  }
  else
  {
    std::istream::read(this: file, _Str: (char *)&fIsStoring + 3, _Count: 1);
    std::istream::read(this: file, _Str: buf, _Count: HIBYTE(fIsStoring));
    std::istream::read(this: file, _Str: (char *)&iAngle, _Count: 4);
    std::istream::read(this: file, _Str: (char *)&bTimeline, _Count: 4);
    CEditGameClass::SetClass(this: v3, pszClass: buf, bLoading: true);
    std::istream::read(this: file, _Str: (char *)&iSize, _Count: 4);
    fIsStoring = 0;
    if ( iSize <= 0 )
    {
LABEL_14:
      CEditGameClass::SetSpawnFlags(this: v3, nSpawnFlags: bTimeline);
      WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v3->m_KeyValues, pszKey: "classname", pszValue: buf);
      if ( iAngle != 0 )
        CEditGameClass::ImportAngle(this: v3, nAngle: iAngle);
      if ( fThisVersion >= 1.5 )
      {
        std::istream::read(this: file, _Str: (char *)&nSpawnFlags, _Count: 4);
        std::istream::read(this: file, _Str: (char *)&fIsStoring, _Count: 4);
        std::istream::read(this: file, _Str: (char *)&fIsStoring, _Count: 4);
      }
      return -((*(_DWORD *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4) + 12] & 4) != 0);
    }
    while ( 1 )
    {
      KeyValue.szKey[0] = 0;
      KeyValue.szValue[0] = 0;
      v20 = 1;
      v9 = MDkeyvalue::SerializeRMF(this: &KeyValue, file, fIsStoring: 0);
      if ( v9 < 0 )
        break;
      WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &v3->m_KeyValues, pszKey: KeyValue.szKey, pszValue: KeyValue.szValue);
      v20 = -1;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
      if ( ++fIsStoring >= iSize )
        goto LABEL_14;
    }
    v20 = -1;
    CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&KeyValue);
    return v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D920
// Name: public: virtual int CMapClass::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapClass::SerializeRMF(CMapClass *this, signed int file, int fIsStoring)
{
  std::istream *v4; // ebx
  int v5; // edx
  CMapClass *m_pObject; // ecx
  int v7; // edx
  int result; // eax
  CMapClass *v9; // edi
  CMapClass *Object; // edi
  char buf[128]; // [esp+Ch] [ebp-94h] BYREF
  char *v12; // [esp+8Ch] [ebp-14h]
  unsigned int dwID; // [esp+90h] [ebp-10h] BYREF
  int nChildCount; // [esp+94h] [ebp-Ch] BYREF
  int iSize; // [esp+98h] [ebp-8h] BYREF
  char _Str; // [esp+9Fh] [ebp-1h] BYREF

  if ( fIsStoring != 0 )
  {
    v12 = (char *)this->GetType(this);
    v4 = (std::istream *)file;
    _Str = strlen(v12) + 1;
    std::ostream::write(this: (std::ostream *)(file + 16), &_Str, _Count: 1);
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: v12, _Count: (unsigned __int8)_Str);
    dwID = 0;
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)&dwID, _Count: 4);
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)&this->r, _Count: 1);
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)&this->g, _Count: 1);
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)&this->b, _Count: 1);
    v5 = 0;
    nChildCount = 0;
    for ( file = 0; v5 < this->m_Children.m_Size; file = v5 )
    {
      m_pObject = this->m_Children.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][file & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject->ShouldSerialize(this: m_pObject) )
        ++nChildCount;
      v5 = file + 1;
    }
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)&nChildCount, _Count: 4);
    v7 = 0;
    file = 0;
    if ( this->m_Children.m_Size <= 0 )
      return -((*(_DWORD *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4) + 12] & 4) != 0);
    while ( 1 )
    {
      v9 = this->m_Children.m_Memory.m_pMemory[v7 >> (*((int *)&this->m_Children.m_Memory + 2) >> 27)][v7 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( v9->ShouldSerialize(this: v9) )
      {
        result = v9->SerializeRMF(this: v9, a2: (std::fstream *)v4, a3: fIsStoring);
        if ( result < 0 )
          break;
      }
      if ( ++file >= this->m_Children.m_Size )
        return -((*(_DWORD *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4) + 12] & 4) != 0);
      v7 = file;
    }
  }
  else
  {
    v4 = (std::istream *)file;
    if ( fThisVersion >= 1.0 )
    {
      std::istream::read(this: (std::istream *)file, _Str: (char *)&file, _Count: 4);
    }
    else
    {
      std::istream::read(this: (std::istream *)file, _Str: (char *)&iSize, _Count: 4);
      std::istream::seekg(this: v4, _Off: iSize, _Way: 1);
    }
    std::istream::read(this: v4, _Str: (char *)&this->r, _Count: 1);
    std::istream::read(this: v4, _Str: (char *)&this->g, _Count: 1);
    std::istream::read(this: v4, _Str: (char *)&this->b, _Count: 1);
    std::istream::read(this: v4, _Str: (char *)&iSize, _Count: 4);
    fIsStoring = 0;
    if ( iSize <= 0 )
      return -((*(_DWORD *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4) + 12] & 4) != 0);
    while ( 1 )
    {
      std::istream::read(this: v4, _Str: (char *)&file + 3, _Count: 1);
      std::istream::read(this: v4, _Str: buf, _Count: HIBYTE(file));
      Object = CMapClassManager::CreateObject(Type: buf);
      if ( Object == nullptr )
        break;
      result = Object->SerializeRMF(this: Object, a2: (std::fstream *)v4, a3: 0);
      if ( result < 0 )
        return result;
      this->AddChild(this, a2: Object);
      if ( ++fIsStoring >= iSize )
        return -((*(_DWORD *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4) + 12] & 4) != 0);
    }
    bCorrupt = 1;
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004DBD0
// Name: public: virtual int CMapEntity::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapEntity::SerializeRMF(CMapEntity *this, std::fstream *file, int fIsStoring)
{
  int v3; // edi
  unsigned __int16 *p_flags; // edi
  GDclass *m_pClass; // eax
  unsigned __int16 v7; // ax
  void (__thiscall *CalcBounds)(CMapClass *, int); // edx
  Vector v10; // [esp+Ch] [ebp-18h] BYREF
  Vector Origin; // [esp+18h] [ebp-Ch] BYREF

  v3 = fIsStoring;
  CMapClass::SerializeRMF(this, (signed int)file, fIsStoring);
  CEditGameClass::SerializeRMF(this: &this->CEditGameClass, file, fIsStoring: v3);
  if ( v3 != 0 )
  {
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&this->flags, _Count: 2);
    this->GetOrigin(this, a2: &Origin);
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&Origin, _Count: 12);
    fIsStoring = 0;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&fIsStoring, _Count: 4);
    return -((*(_DWORD *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4) + 12] & 4) != 0);
  }
  p_flags = &this->flags;
  std::istream::read(this: file, _Str: (char *)&this->flags, _Count: 2);
  std::istream::read(this: file, _Str: (char *)&Origin, _Count: 12);
  this->SetOrigin(this, a2: &Origin);
  if ( this->m_pClass == nullptr )
  {
    if ( this->m_Children.m_Size > 0 )
    {
      v7 = *p_flags & 0xFFFE;
      goto LABEL_10;
    }
LABEL_9:
    v7 = *p_flags | 1;
    goto LABEL_10;
  }
  m_pClass = this->m_pClass;
  if ( m_pClass == nullptr || !m_pClass->m_bSolid )
    goto LABEL_9;
  v7 = *p_flags & 0xFFFE;
LABEL_10:
  *p_flags = v7;
  if ( (v7 & 1) == 0 )
  {
    memset(&v10, 0, sizeof(v10));
    CMapPoint::SetOrigin(this, Origin: &v10);
  }
  this->GetOrigin(this, a2: &Origin);
  if ( fThisVersion < 0.5 )
    LODWORD(Origin.z) ^= _mask__NegFloat_;
  std::istream::read(this: file, _Str: (char *)&fIsStoring, _Count: 4);
  this->SetOrigin(this, a2: &Origin);
  CalcBounds = this->CalcBounds;
  this->m_szClass[0] = 0;
  CalcBounds(this, a2: 1);
  return -((*(_DWORD *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4) + 12] & 4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004DD50
// Name: public: virtual int CMapWorld::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapWorld::SerializeRMF(CMapWorld *this, std::fstream *file, const char *fIsStoring)
{
  std::fstream *v4; // edi
  int i; // esi
  std::fstream *v7; // ebx
  float v8; // xmm0_4
  int j; // esi
  int v10; // esi
  CMapPath *v11; // eax
  std::fstream *v12; // edi
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  _DWORD *v18; // eax
  CAfxStringMgr *v19; // eax
  std::fstream *v20; // esi
  const char *v21; // esi
  int *v22; // eax
  const char *v23; // eax
  std::fstream *v24; // esi
  char *v25; // eax
  bool v26; // cc
  _iobuf *v27; // eax
  _iobuf *v28; // esi
  CAfxStringMgr *StringManager; // eax
  char filea[28]; // [esp+1Ch] [ebp-1B0h] BYREF
  char _Str[28]; // [esp+94h] [ebp-138h] BYREF
  COldVisGroup oldVisGroup; // [esp+B0h] [ebp-11Ch] BYREF
  char buf[128]; // [esp+13Ch] [ebp-90h] BYREF
  float unused[3]; // [esp+1BCh] [ebp-10h] BYREF
  void *p; // [esp+1C8h] [ebp-4h]

  *(_DWORD *)&buf[124] = this;
  *(_DWORD *)&buf[120] = 1080872141;
  pLoadingWorld = this;
  bCorrupt = 0;
  if ( fIsStoring != nullptr )
  {
    v4 = file;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: &buf[120], _Count: 4);
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: "RMF", _Count: 3);
    unused[0] = 0.0;
    std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)unused, _Count: 4);
    if ( CMapClass::SerializeRMF(this, file: (signed int)v4, (int)fIsStoring) != -1
      && CEditGameClass::SerializeRMF(this: &this->CEditGameClass, file: v4, (int)fIsStoring) != -1 )
    {
      unused[0] = *(float *)&this->m_Paths.m_Size;
      std::ostream::write(this: (std::ostream *)v4->gap10, _Str: (const char *)unused, _Count: 4);
      for ( i = 0; i < this->m_Paths.m_Size; ++i )
        CMapPath::SerializeRMF(this: this->m_Paths.m_Memory.m_pMemory[i], file: v4, fIsStoring: 1);
      if ( (*(_DWORD *)&v4->gap0[*(_DWORD *)(*(_DWORD *)v4->gap0 + 4) + 12] & 4) == 0 )
        return 0;
    }
    goto FatalError_0;
  }
  v7 = file;
  std::istream::read(this: file, _Str: (char *)&fThisVersion, _Count: 4);
  v8 = fThisVersion;
  if ( fThisVersion < 0.30000001 || fThisVersion > *(float *)&buf[120] )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    fIsStoring = (const char *)&StringManager->GetNilString(this: StringManager)[1];
    p = (void *)1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&fIsStoring,
      pszFormat: "Oops! SerializeRMF() v%1.1f tried to load a file v%1.1f. Aborting.",
      *(float *)&buf[120],
      fThisVersion);
    v20 = (std::fstream *)fIsStoring;
    AfxMessageBox(lpszText: fIsStoring, nType: 0, nIDHelp: 0);
    goto LABEL_53;
  }
  if ( fThisVersion >= 0.80000001 )
  {
    std::istream::read(this: v7, _Str: &oldVisGroup.m_szName[112], _Count: 3);
    if ( strncmp(first: &oldVisGroup.m_szName[112], last: "RMF", count: 3u) != 0 )
    {
LABEL_12:
      AfxMessageBox(lpszText: "Invalid file type.", nType: 0, nIDHelp: 0);
      return -1;
    }
    v8 = fThisVersion;
  }
  if ( v8 >= 1.0 )
  {
    std::istream::read(this: v7, _Str: (char *)unused, _Count: 4);
    for ( j = 0; j < SLODWORD(unused[0]); ++j )
      std::istream::read(this: v7, _Str, _Count: 140);
  }
  v10 = *(_DWORD *)&buf[124];
  BoundBox::ResetBounds(this: (BoundBox *)(*(_DWORD *)&buf[124] + 96));
  std::istream::read(this: v7, _Str: (char *)&file + 3, _Count: 1);
  std::istream::read(this: v7, _Str: &oldVisGroup.m_szName[112], _Count: HIBYTE(file));
  if ( strcmp(&oldVisGroup.m_szName[112], (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 200))(a1: v10)) != 0 )
    goto LABEL_12;
  if ( CMapClass::SerializeRMF(this: (CMapClass *)v10, file: (signed int)v7, fIsStoring: 0) == -1
    || CEditGameClass::SerializeRMF(this: (CEditGameClass *)(v10 + 216), file: v7, fIsStoring: 0) == -1 )
  {
    goto FatalError_0;
  }
  if ( fThisVersion < 1.0 )
  {
    std::istream::read(this: v7, _Str: (char *)unused, _Count: 4);
    std::istream::seekg(this: v7, _Off: 134 * LODWORD(unused[0]), _Way: 1);
  }
  if ( fThisVersion >= 1.1 )
  {
    std::istream::read(this: v7, _Str: (char *)unused, _Count: 4);
    *(_DWORD *)&buf[116] = 0;
    if ( SLODWORD(unused[0]) > 0 )
    {
      do
      {
        v11 = (CMapPath *)operator new(nSize: 0x118u);
        *(_DWORD *)&buf[112] = v11;
        p = (void *)3;
        if ( v11 != nullptr )
        {
          v12 = (std::fstream *)CMapPath::CMapPath(this: v11);
          file = v12;
        }
        else
        {
          file = nullptr;
          v12 = nullptr;
        }
        p = (void *)-1;
        CMapPath::SerializeRMF(this: (CMapPath *)v12, file: v7, fIsStoring: 0);
        if ( HIDWORD(v12->_Chcount) != 0 )
        {
          v13 = *(_DWORD *)(v10 + 372);
          v14 = *(_DWORD *)(v10 + 364);
          if ( v13 + 1 > v14 )
            CUtlMemory<CVisGroup *,int>::Grow(this: (CUtlMemory<CCullTreeNode *,int> *)(v10 + 360), num: v13 - v14 + 1);
          ++*(_DWORD *)(v10 + 372);
          v15 = *(_DWORD *)(v10 + 360);
          v16 = *(_DWORD *)(v10 + 372) - v13 - 1;
          *(_DWORD *)(v10 + 376) = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (void *)(v15 + 4 * v13 + 4), src: (const void *)(v15 + 4 * v13), count: 4 * v16);
          v17 = *(_DWORD *)(v10 + 360);
          v10 = *(_DWORD *)&buf[124];
          v18 = (_DWORD *)(v17 + 4 * v13);
          if ( v18 != nullptr )
            *v18 = file;
        }
        else
        {
          CMapPath::~CMapPath(this: (CMapPath *)v12);
          operator delete(p: v12);
        }
        ++*(_DWORD *)&buf[116];
      }
      while ( *(int *)&buf[116] < SLODWORD(unused[0]) );
    }
  }
  if ( fThisVersion < 1.4 )
  {
    std::istream::read(this: v7, _Str: &buf[100], _Count: 12);
    std::istream::read(this: v7, _Str: &buf[100], _Count: 12);
  }
  if ( (*(_DWORD *)&v7->gap0[*(_DWORD *)(*(_DWORD *)v7->gap0 + 4) + 12] & 4) != 0 )
  {
FatalError_0:
    v19 = AfxGetStringManager();
    if ( v19 == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    file = (std::fstream *)&v19->GetNilString(this: v19)[1];
    p = (void *)5;
    if ( bCorrupt == 0 )
    {
      v21 = "saving";
      if ( fIsStoring == nullptr )
        v21 = "loading";
      v22 = _errno();
      v23 = strerror(errnum: *v22);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&file,
        pszFormat: "The OS reported an error %s the file: %s",
        v21,
        v23);
      v24 = file;
      AfxMessageBox(lpszText: file->gap0, nType: 0, nIDHelp: 0);
      p = (void *)-1;
      v25 = &v24[-1].gap70[56];
      v26 = _InterlockedDecrement((volatile signed __int32 *)&v24[-1].gap70[68]) <= 0;
      goto LABEL_54;
    }
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&file,
      pszFormat: "The file is corrupt.");
    v20 = file;
    AfxMessageBox(lpszText: file->gap0, nType: 0, nIDHelp: 0);
LABEL_53:
    p = (void *)-1;
    v25 = &v20[-1].gap70[56];
    v26 = _InterlockedDecrement((volatile signed __int32 *)&v20[-1].gap70[68]) <= 0;
LABEL_54:
    if ( v26 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v25 + 4))(a1: v25);
    return -1;
  }
  CMapWorld::PostloadWorld(this: (CMapWorld *)v10);
  if ( g_pGameConfig->textureformat == tfVMT )
  {
    V_snprintf(pDest: filea, maxLen: 260, pFormat: "materials/trans.txt");
    v27 = fopen(file: filea, mode: "r");
    v28 = v27;
    if ( v27 != nullptr )
    {
      CMapDoc::BatchReplaceTextures(this: CMapDoc::m_pMapDoc, fp: v27);
      g_pFileSystem->Close(this: g_pFileSystem, a2: v28);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004E330
// Name: public: virtual int CMapSolid::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSolid::SerializeRMF(CMapSolid *this, std::fstream *file, int fIsStoring)
{
  std::fstream *v3; // ebx
  CMapSolid *v4; // edi
  const char *v5; // esi
  int v6; // ecx
  unsigned int v7; // ebx
  int result; // eax
  BlockArray<CMapFace,6,86> *p_Faces; // ebx
  const char *v10; // esi
  int v11; // ecx
  unsigned int v12; // edi
  int v13; // edi
  __int16 nCount; // ax
  int v15; // eax
  int iSize; // [esp+10h] [ebp-4h] BYREF
  int fIsStoringa; // [esp+20h] [ebp+Ch]

  v3 = file;
  v4 = this;
  CMapClass::SerializeRMF(this, (signed int)file, fIsStoring);
  if ( fIsStoring != 0 )
  {
    iSize = v4->Faces.nCount;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&iSize, _Count: 4);
    v5 = nullptr;
    if ( iSize > 0 )
    {
      while ( 1 )
      {
        if ( (int)v5 >= v4->Faces.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v5, v4->Faces.nCount);
          v6 = (int)(v5 + 1);
          if ( v5 + 1 != (const char *)v4->Faces.nCount )
          {
            v7 = v6 / 6;
            if ( 6 * (v6 / 6) < v6 )
              ++v7;
            if ( v7 != v4->Faces.nBlocks )
            {
              if ( v7 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &v4->Faces, nNewBlocks: v7);
            }
            v3 = file;
            v4->Faces.nCount = (_WORD)v5 + 1;
          }
        }
        result = CMapFace::SerializeRMF(this: &v4->Faces.Blocks[(int)v5 / 6][(int)v5 % 6], file: v3, fIsStoring);
        if ( result < 0 )
          break;
        if ( (int)++v5 >= iSize )
          return -((*(_DWORD *)&v3->gap0[*(_DWORD *)(*(_DWORD *)v3->gap0 + 4) + 12] & 4) != 0);
      }
      return result;
    }
    return -((*(_DWORD *)&v3->gap0[*(_DWORD *)(*(_DWORD *)v3->gap0 + 4) + 12] & 4) != 0);
  }
  if ( v4->r == 0 && v4->g == 0 || v4->b == 0 )
    CMapSolid::PickRandomColor(this: v4);
  std::istream::read(this: file, _Str: (char *)&iSize, _Count: 4);
  p_Faces = &v4->Faces;
  BlockArray<CMapFace,6,86>::SetCount(this: &v4->Faces, nObjects: iSize);
  v10 = nullptr;
  if ( iSize <= 0 )
  {
LABEL_36:
    v4->CalcBounds(this: v4, a2: 0);
    nCount = p_Faces->nCount;
    if ( nCount <= 0 )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nullptr, nCount);
      if ( p_Faces->nCount != 1 )
      {
        if ( p_Faces->nBlocks != 1 )
          BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: 1);
        p_Faces->nCount = 1;
      }
    }
    v15 = CMapSolid::HL1SolidTypeFromTextureName(this: v4, pszTexture: p_Faces->Blocks[0]->texture.texture);
    v3 = file;
    v4->m_eSolidType = v15;
    return -((*(_DWORD *)&v3->gap0[*(_DWORD *)(*(_DWORD *)v3->gap0 + 4) + 12] & 4) != 0);
  }
  while ( 1 )
  {
    if ( (int)v10 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v10, p_Faces->nCount);
      v11 = (int)(v10 + 1);
      if ( v10 + 1 != (const char *)p_Faces->nCount )
      {
        v12 = v11 / 6;
        if ( 6 * (v11 / 6) < v11 )
          ++v12;
        if ( v12 != p_Faces->nBlocks )
        {
          if ( v12 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v12);
        }
        p_Faces->nCount = (_WORD)v10 + 1;
      }
    }
    v13 = (int)v10 / 6;
    fIsStoringa = (int)v10 % 6;
    result = CMapFace::SerializeRMF(this: &p_Faces->Blocks[(int)v10 / 6][fIsStoringa], file, fIsStoring: 0);
    if ( result < 0 )
      return result;
    if ( (int)v10 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v10, p_Faces->nCount);
      BlockArray<CMapFace,6,86>::SetCount(this: p_Faces, nObjects: (int)(v10 + 1));
    }
    p_Faces->Blocks[v13][fIsStoringa].SetRenderColor_2(
      this: &p_Faces->Blocks[v13][fIsStoringa],
      a2: this->r,
      a3: this->g,
      a4: this->b);
    if ( (int)v10 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v10, p_Faces->nCount);
      BlockArray<CMapFace,6,86>::SetCount(this: p_Faces, nObjects: (int)(v10 + 1));
    }
    p_Faces->Blocks[v13][fIsStoringa].SetParent(this: &p_Faces->Blocks[v13][fIsStoringa], a2: this);
    if ( (int)++v10 >= iSize )
    {
      v4 = this;
      goto LABEL_36;
    }
  }
}
