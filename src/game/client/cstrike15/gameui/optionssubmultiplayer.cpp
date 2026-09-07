// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubmultiplayer.cpp
// Functions: 115
// ============================================================

#include "game\client\cstrike15\gameui\optionssubmultiplayer.h"

//------------------------------------------------------------------------------
// Address: 0x101DC0D0
// Name: public: static char const __near * COptionsSubMultiplayer::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubMultiplayer::GetPanelClassName()
{
  return "COptionsSubMultiplayer";
}

//------------------------------------------------------------------------------
// Address: 0x101DC0E0
// Name: public: void CrosshairImagePanel::UpdateCrosshair(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CrosshairImagePanel::UpdateCrosshair(CrosshairImagePanel *this, int r, int g, int b, int size)
{
  int v5; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edi

  v5 = r;
  v7 = g;
  this->m_B = b;
  this->m_R = v5;
  this->m_G = v7;
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &r, a3: &g);
  v8 = size;
  v9 = r;
  if ( size == 0 )
  {
    if ( r > 640 )
      v8 = (r >= 1024) + 2;
    else
      v8 = 1;
  }
  v10 = v8 - 2;
  if ( v10 != 0 )
  {
    if ( v10 == 1 )
      v11 = 640;
    else
      v11 = 1024;
  }
  else
  {
    v11 = 800;
  }
  this->m_barSize = 9 * r / v11;
  this->m_barGap = 5 * v9 / v11;
}

//------------------------------------------------------------------------------
// Address: 0x101DC180
// Name: public: static char const __near * vgui::ImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ImagePanel::GetPanelClassName()
{
  return "ImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x101DC190
// Name: public: void AdvancedCrosshairImagePanel::UpdateCrosshair(int,int,int,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge AdvancedCrosshairImagePanel::UpdateCrosshair(
        AdvancedCrosshairImagePanel *this@<ecx>,
        int a2@<esi>,
        int r,
        int g,
        int b,
        float scale,
        const char *crosshairname)
{
  IVguiMatInfo *v8; // eax
  IVguiMatInfoVar *v9; // eax
  IVguiMatInfo *m_pAdvCrosshair; // ecx
  long double v11; // st7

  this->m_B = b;
  this->m_R = r;
  this->m_G = g;
  this->m_flScale = scale;
  ((void (__thiscall *)(vgui::ISurface *, int, const char *, int, _DWORD, int))g_pVGuiSurface->DrawSetTextureFile)(
    a1: g_pVGuiSurface,
    a2: this->m_iCrosshairTextureID,
    a3: crosshairname,
    a4: 1,
    a5: 0,
    a6: a2);
  if ( this->m_pAdvCrosshair != nullptr )
    C_BaseEntity::operator delete(pMem: this->m_pAdvCrosshair);
  v8 = g_pVGuiSurface->DrawGetTextureMatInfoFactory(this: g_pVGuiSurface, a2: this->m_iCrosshairTextureID);
  this->m_pAdvCrosshair = v8;
  v9 = (IVguiMatInfoVar *)v8->FindVarFactory(this: v8, a2: "$frame", a3: nullptr);
  m_pAdvCrosshair = this->m_pAdvCrosshair;
  this->m_pFrameVar = v9;
  this->m_nNumFrames = m_pAdvCrosshair->GetNumAnimationFrames(this: m_pAdvCrosshair);
  v11 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  this->m_bAscending = true;
  this->m_flNextFrameChange = v11 + 0.2;
}

//------------------------------------------------------------------------------
// Address: 0x101DC260
// Name: public: virtual void AdvancedCrosshairImagePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AdvancedCrosshairImagePanel::Paint(AdvancedCrosshairImagePanel *this)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // ebx
  int v4; // eax
  long double v5; // st7
  IVguiMatInfoVar *m_pFrameVar; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  void (__thiscall *DrawSetColor_2)(vgui::ISurface *, int, int, int, int); // edx
  int m_R; // [esp-10h] [ebp-40h]
  int m_G; // [esp-Ch] [ebp-3Ch]
  int m_B; // [esp-8h] [ebp-38h]
  int iClipX0; // [esp+Ch] [ebp-24h] BYREF
  int iClipY0; // [esp+10h] [ebp-20h] BYREF
  int iClipX1; // [esp+14h] [ebp-1Ch] BYREF
  int iClipY1; // [esp+18h] [ebp-18h] BYREF
  float x; // [esp+1Ch] [ebp-14h]
  float flDrawWidth; // [esp+20h] [ebp-10h]
  int tall; // [esp+24h] [ebp-Ch] BYREF
  int wide; // [esp+28h] [ebp-8h] BYREF
  float curtime; // [esp+2Ch] [ebp-4h]

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  vgui::Panel::GetSize(this, &wide, &tall);
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  v4 = ((int (__thiscall *)(AdvancedCrosshairImagePanel *, int *, int *, int *, int *))this->GetVPanel)(
         a1: this,
         a2: &iClipX0,
         a3: &iClipY0,
         a4: &iClipX1,
         a5: &iClipY1);
  ((void (__thiscall *)(vgui::IPanel *, int))v3->GetClipRect)(a1: v2, a2: v4);
  if ( this->m_pFrameVar != nullptr )
  {
    v5 = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
    curtime = v5;
    if ( v5 >= this->m_flNextFrameChange )
    {
      m_pFrameVar = this->m_pFrameVar;
      this->m_flNextFrameChange = curtime + 0.2;
      v7 = m_pFrameVar->GetIntValue(this: m_pFrameVar);
      if ( this->m_bAscending )
      {
        v8 = v7 + 1;
        if ( v8 >= this->m_nNumFrames )
        {
          this->m_bAscending = false;
          --v8;
        }
      }
      else
      {
        v8 = v7 - 1;
        if ( v8 < 0 )
        {
          this->m_bAscending = true;
          ++v8;
        }
      }
      this->m_pFrameVar->SetIntValue(this: this->m_pFrameVar, a2: v8);
    }
  }
  flDrawWidth = (float)(this->m_flScale * 0.020833334) * (float)wide;
  v9 = (int)(float)(flDrawWidth * 0.5);
  DrawSetColor_2 = g_pVGuiSurface->DrawSetColor_2;
  x = (float)(wide / 2 - v9);
  m_B = this->m_B;
  m_G = this->m_G;
  m_R = this->m_R;
  curtime = (float)(tall / 2 - v9);
  DrawSetColor_2(this: g_pVGuiSurface, a2: m_R, a3: m_G, a4: m_B, a5: 255);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iCrosshairTextureID);
  g_pVGuiSurface->DrawTexturedRect(
    this: g_pVGuiSurface,
    a2: (int)x,
    a3: (int)curtime,
    a4: (int)(float)(x + flDrawWidth),
    a5: (int)(float)(curtime + flDrawWidth));
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101DC420
// Name: ValveJpegErrorHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn ValveJpegErrorHandler(jpeg_common_struct *cinfo)
{
  jpeg_error_mgr *err; // esi
  char buffer[200]; // [esp+4h] [ebp-C8h] BYREF

  err = cinfo->err;
  cinfo->err->format_message(a1: cinfo, a2: buffer);
  _Warning(a1: "%s\n", buffer);
  longjmp(Buf: (int *)&err[1], Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101DC460
// Name: ReadTGAHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall ReadTGAHeader(_iobuf *infile@<esi>, TGAHeader *header@<eax>)
{
  if ( infile != nullptr )
  {
    fread(buffer: &header->identsize, elementSize: 1u, count: 1u, stream: infile);
    fread(buffer: &header->colourmaptype, elementSize: 1u, count: 1u, stream: infile);
    fread(buffer: &header->imagetype, elementSize: 1u, count: 1u, stream: infile);
    fread(buffer: (unsigned __int8 *)&header->colourmapstart, elementSize: 2u, count: 1u, stream: infile);
    fread(buffer: (unsigned __int8 *)&header->colourmaplength, elementSize: 2u, count: 1u, stream: infile);
    fread(buffer: &header->colourmapbits, elementSize: 1u, count: 1u, stream: infile);
    fread(buffer: (unsigned __int8 *)&header->xstart, elementSize: 2u, count: 1u, stream: infile);
    fread(buffer: (unsigned __int8 *)&header->ystart, elementSize: 2u, count: 1u, stream: infile);
    fread(buffer: (unsigned __int8 *)&header->width, elementSize: 2u, count: 1u, stream: infile);
    fread(buffer: (unsigned __int8 *)&header->height, elementSize: 2u, count: 1u, stream: infile);
    fread(buffer: &header->bits, elementSize: 1u, count: 1u, stream: infile);
    fread(buffer: &header->descriptor, elementSize: 1u, count: 1u, stream: infile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC520
// Name: WriteTGAHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteTGAHeader(_iobuf *outfile@<esi>, TGAHeader *header@<eax>)
{
  if ( outfile != nullptr )
  {
    fwrite(buffer: &header->identsize, size: 1u, count: 1u, stream: outfile);
    fwrite(buffer: &header->colourmaptype, size: 1u, count: 1u, stream: outfile);
    fwrite(buffer: &header->imagetype, size: 1u, count: 1u, stream: outfile);
    fwrite(buffer: (unsigned __int8 *)&header->colourmapstart, size: 2u, count: 1u, stream: outfile);
    fwrite(buffer: (unsigned __int8 *)&header->colourmaplength, size: 2u, count: 1u, stream: outfile);
    fwrite(buffer: &header->colourmapbits, size: 1u, count: 1u, stream: outfile);
    fwrite(buffer: (unsigned __int8 *)&header->xstart, size: 2u, count: 1u, stream: outfile);
    fwrite(buffer: (unsigned __int8 *)&header->ystart, size: 2u, count: 1u, stream: outfile);
    fwrite(buffer: (unsigned __int8 *)&header->width, size: 2u, count: 1u, stream: outfile);
    fwrite(buffer: (unsigned __int8 *)&header->height, size: 2u, count: 1u, stream: outfile);
    fwrite(buffer: &header->bits, size: 1u, count: 1u, stream: outfile);
    fwrite(buffer: &header->descriptor, size: 1u, count: 1u, stream: outfile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC5E0
// Name: private: unsigned char __near * COptionsSubMultiplayer::ReadTGAAsRGBA(char const __near *,int __near &,int __near &,enum ConversionErrorType __near &,struct TGAHeader __near &)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__userpurge COptionsSubMultiplayer::ReadTGAAsRGBA@<eax>(
        COptionsSubMultiplayer *this@<ecx>,
        int a2@<ebx>,
        char *tgaPath,
        int *width,
        int *height,
        ConversionErrorType *errcode,
        TGAHeader *tgaHeader)
{
  _iobuf *result; // eax
  _iobuf *v8; // esi
  int v9; // kr00_4
  unsigned __int8 *v10; // ebx
  unsigned __int8 bits; // al
  int v12; // esi
  int v13; // eax
  _BYTE *v14; // eax
  _BYTE *v15; // ecx
  unsigned __int8 *retBuf; // [esp+Ch] [ebp+8h]
  unsigned __int8 *retBufa; // [esp+Ch] [ebp+8h]

  result = fopen(file: (_iobuf *)tgaPath, mode: "rb");
  v8 = result;
  retBuf = (unsigned __int8 *)result;
  if ( result != nullptr )
  {
    ReadTGAHeader(infile: result, header: tgaHeader);
    if ( tgaHeader->imagetype == 2 )
    {
      v9 = tgaHeader->height * tgaHeader->bits * tgaHeader->width;
      v10 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v9 / 8);
      if ( v10 != nullptr )
      {
        fread(buffer: v10, elementSize: 1u, count: v9 / 8, stream: (_iobuf *)retBuf);
        fclose(stream: (_iobuf *)retBuf);
        *width = tgaHeader->width;
        *height = tgaHeader->height;
        bits = tgaHeader->bits;
        if ( bits == 24 )
        {
          v12 = tgaHeader->height * tgaHeader->width;
          v13 = ((int (__thiscall *)(IMemAlloc *, int, int))_g_pMemAlloc->Alloc_2)(
                  a1: _g_pMemAlloc,
                  a2: 4 * v12,
                  a3: a2);
          retBufa = (unsigned __int8 *)v13;
          if ( v13 != 0 )
          {
            if ( v12 > 0 )
            {
              v14 = (_BYTE *)(v13 + 2);
              v15 = v10 + 2;
              do
              {
                *(v14 - 2) = *(v15 - 2);
                *(v14 - 1) = *(v15 - 1);
                *v14 = *v15;
                v14[1] = -1;
                v15 += 3;
                v14 += 4;
                --v12;
              }
              while ( v12 != 0 );
            }
            ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
            tgaHeader->bits = 32;
            *errcode = CE_SUCCESS;
            return (_iobuf *)retBufa;
          }
          else
          {
            ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
            *errcode = CE_MEMORY_ERROR;
            return nullptr;
          }
        }
        else if ( bits == 32 )
        {
          *errcode = CE_SUCCESS;
          return (_iobuf *)v10;
        }
        else
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
          *errcode = CE_SOURCE_FILE_FORMAT_NOT_SUPPORTED;
          return nullptr;
        }
      }
      else
      {
        fclose(stream: (_iobuf *)retBuf);
        *errcode = CE_MEMORY_ERROR;
        return nullptr;
      }
    }
    else
    {
      fclose(stream: v8);
      *errcode = CE_SOURCE_FILE_FORMAT_NOT_SUPPORTED;
      return nullptr;
    }
  }
  else
  {
    *errcode = CE_CANT_OPEN_SOURCE_FILE;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DC790
// Name: private: enum ConversionErrorType COptionsSubMultiplayer::StretchRGBAImage(unsigned char const __near *,int,int,unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsSubMultiplayer::StretchRGBAImage(
        COptionsSubMultiplayer *this,
        const unsigned __int8 *srcBuf,
        int srcWidth,
        int srcHeight,
        unsigned __int8 *destBuf,
        int destWidth,
        int destHeight)
{
  int v8; // ecx
  int v9; // ebx
  float v10; // xmm6_4
  int v11; // edx
  float v12; // xmm0_4
  int v13; // edi
  float v14; // xmm4_4
  unsigned __int8 *v15; // edx
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm6_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm4_4
  int v28; // ecx
  float v29; // xmm1_4
  int v30; // eax
  int v31; // ebx
  const unsigned __int8 *v32; // eax
  float v33; // xmm0_4
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int destRow; // [esp+8h] [ebp-2Ch]
  float srcCenterY; // [esp+10h] [ebp-24h]
  float v41; // [esp+14h] [ebp-20h]
  float v42; // [esp+18h] [ebp-1Ch]
  float srcCurrentY; // [esp+1Ch] [ebp-18h]
  float srcCurrentEndY; // [esp+20h] [ebp-14h]
  float srcStartX; // [esp+24h] [ebp-10h]
  float srcStartY; // [esp+28h] [ebp-Ch]
  unsigned __int8 *v47; // [esp+2Ch] [ebp-8h]
  float srcEndY; // [esp+3Ch] [ebp+8h]
  float destAlpha; // [esp+48h] [ebp+14h]

  if ( srcBuf == nullptr || destBuf == nullptr )
    return 2;
  v8 = destWidth;
  v9 = srcWidth;
  v10 = (float)srcWidth / (float)destWidth;
  v11 = 0;
  v12 = (float)srcHeight / (float)destHeight;
  destRow = 0;
  if ( destHeight > 0 )
  {
    v47 = destBuf + 2;
    do
    {
      v13 = 0;
      if ( v8 > 0 )
      {
        v14 = (float)v11;
        v15 = v47;
        v16 = (float)(v14 + 0.5) * v12;
        v17 = v10 * 0.5;
        v18 = v12 * 0.5;
        srcCenterY = v16;
        v42 = v10 * 0.5;
        v41 = v18;
        do
        {
          v19 = (float)((float)v13 + 0.5) * v10;
          v20 = v19 - v17;
          srcStartX = v19 - v17;
          if ( (float)(v19 - v17) < 0.0 )
          {
            v20 = 0.0;
            srcStartX = 0.0;
          }
          v21 = v16 - v18;
          srcStartY = v16 - v18;
          if ( (float)(v16 - v18) < 0.0 )
          {
            v21 = 0.0;
            srcStartY = 0.0;
          }
          v22 = v17 + v19;
          if ( v22 > (float)v9 )
            v22 = (float)v9;
          v23 = v18 + v16;
          srcEndY = v23;
          if ( v23 > (float)srcHeight )
          {
            v23 = (float)srcHeight;
            srcEndY = (float)srcHeight;
          }
          srcCurrentY = v21;
          v24 = 0.0;
          v25 = 0.0;
          v26 = 0.0;
          destAlpha = 0.0;
          if ( v23 > srcStartY )
          {
            while ( 1 )
            {
              v27 = (float)((int)srcCurrentY + 1);
              srcCurrentEndY = v27;
              if ( v27 > v23 )
              {
                v27 = v23;
                srcCurrentEndY = v23;
              }
              if ( v22 > v20 )
              {
                v28 = v9 * (int)srcCurrentY;
                do
                {
                  v29 = (float)((int)v20 + 1);
                  if ( v29 > v22 )
                    v29 = v22;
                  v30 = v28 + (int)v20;
                  v31 = srcBuf[4 * v30];
                  v32 = &srcBuf[4 * v30];
                  v33 = (float)((float)(v29 - v20) * (float)(1.0 / (float)((float)srcWidth / (float)destWidth)))
                      * (float)((float)(v27 - srcCurrentY) / (float)((float)srcHeight / (float)destHeight));
                  v24 = v24 + (float)((float)v31 * v33);
                  v25 = v25 + (float)((float)v32[1] * v33);
                  v26 = v26 + (float)((float)v32[2] * v33);
                  destAlpha = (float)((float)v32[3] * v33) + destAlpha;
                  v20 = v29;
                }
                while ( v22 > v29 );
                v27 = srcCurrentEndY;
                v9 = srcWidth;
              }
              v23 = srcEndY;
              srcCurrentY = v27;
              if ( srcEndY <= v27 )
                break;
              v20 = srcStartX;
            }
            v8 = destWidth;
          }
          v16 = srcCenterY;
          v18 = v41;
          v17 = v42;
          v34 = (int)(float)(v24 + 0.5);
          if ( v34 >= 255 )
            LOBYTE(v34) = -1;
          *(v15 - 2) = v34;
          v35 = (int)(float)(v25 + 0.5);
          if ( v35 >= 255 )
            LOBYTE(v35) = -1;
          *(v15 - 1) = v35;
          v36 = (int)(float)(v26 + 0.5);
          if ( v36 >= 255 )
            LOBYTE(v36) = -1;
          *v15 = v36;
          v37 = (int)(float)(destAlpha + 0.5);
          if ( v37 >= 255 )
            LOBYTE(v37) = -1;
          v10 = (float)srcWidth / (float)destWidth;
          v15[1] = v37;
          ++v13;
          v15 += 4;
        }
        while ( v13 < v8 );
        v12 = (float)srcHeight / (float)destHeight;
        v11 = destRow;
      }
      ++v11;
      v47 += 4 * v8;
      destRow = v11;
    }
    while ( v11 < destHeight );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DCA90
// Name: private: enum ConversionErrorType COptionsSubMultiplayer::PadRGBAImage(unsigned char const __near *,int,int,unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsSubMultiplayer::PadRGBAImage(
        COptionsSubMultiplayer *this,
        unsigned __int8 *srcBuf,
        int srcWidth,
        int srcHeight,
        unsigned __int8 *destBuf,
        int destWidth,
        int destHeight)
{
  int v8; // eax
  unsigned int v9; // ebx
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // esi
  unsigned __int8 *destBufa; // [esp+14h] [ebp+14h]

  if ( srcBuf == nullptr || destBuf == nullptr )
    return 2;
  memset(dst: (int)destBuf, value: nullptr, count: 4 * destHeight * destWidth);
  if ( destWidth < srcWidth || destHeight < srcHeight )
    return 3;
  if ( srcWidth == destWidth )
  {
    if ( srcHeight == destHeight )
    {
      memcpy(dst: destBuf, src: srcBuf, count: 4 * destHeight * destWidth);
      return 0;
    }
    memcpy(dst: &destBuf[4 * destWidth * ((destHeight - srcHeight) / 2)], src: srcBuf, count: 4 * srcHeight * srcWidth);
    return 0;
  }
  else
  {
    v8 = (destHeight - srcHeight) / 2;
    if ( v8 >= v8 + srcHeight )
      return 0;
    v9 = 4 * srcWidth;
    v10 = &destBuf[4 * ((destWidth - srcWidth) / 2) + 4 * destWidth * v8];
    v11 = srcBuf;
    destBufa = (unsigned __int8 *)srcHeight;
    do
    {
      memcpy(dst: v10, src: v11, count: v9);
      v10 += 4 * destWidth;
      v11 += v9;
      --destBufa;
    }
    while ( destBufa != nullptr );
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCBB0
// Name: private: enum ConversionErrorType COptionsSubMultiplayer::WriteSprayVMT(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsSubMultiplayer::WriteSprayVMT(COptionsSubMultiplayer *this, char *vtfPath)
{
  char *i; // esi
  char v4; // al
  char v5; // al
  int v6; // ecx
  char *v7; // edx
  _iobuf *v8; // eax
  _iobuf *v9; // esi
  char vmtPath[1040]; // [esp+0h] [ebp-514h] BYREF
  char filename[260]; // [esp+410h] [ebp-104h] BYREF

  if ( vtfPath == nullptr )
    return 5;
  V_strncpy(pDest: vmtPath, pSrc: vtfPath, maxLen: 1040);
  for ( i = &vmtPath[strlen(vmtPath)]; i > vmtPath; --i )
  {
    if ( *(i - 1) == 46 )
      break;
  }
  V_strncpy(pDest: i, pSrc: "vmt", maxLen: filename - i);
  for ( ; i > vmtPath; --i )
  {
    v4 = *(i - 1);
    if ( v4 == 47 )
      break;
    if ( v4 == 92 )
      break;
  }
  v5 = *i;
  v6 = 0;
  if ( *i != 0 )
  {
    v7 = (char *)(filename - i);
    do
    {
      if ( v5 == 46 )
        break;
      i[(_DWORD)v7] = v5;
      v5 = *++i;
      ++v6;
    }
    while ( v5 != 0 );
  }
  filename[v6] = 0;
  v8 = fopen(file: (_iobuf *)vmtPath, mode: "w");
  v9 = v8;
  if ( v8 == nullptr )
    return 5;
  fprintf(
    str: v8,
    format: "LightmappedGeneric\n"
    "{\n"
    "\t\"$basetexture\"\t\"vgui\\logos\\%s\"\n"
    "\t\"$translucent\" \"1\"\n"
    "\t\"$decal\" \"1\"\n"
    "\t\"$decalscale\" \"0.250\"\n"
    "}\n",
    filename);
  fclose(stream: v9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DCCD0
// Name: private: void COptionsSubMultiplayer::InitLogoList(class CLabeledCommandComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COptionsSubMultiplayer::InitLogoList(
        COptionsSubMultiplayer *this@<ecx>,
        int a2@<edi>,
        CLabeledCommandComboBox *cb)
{
  char *v4; // edi
  unsigned int v5; // eax
  char v6; // cl
  void (__thiscall *AddItem_3)(CLabeledCommandComboBox *, const char *, const char *); // edx
  char directory[512]; // [esp+0h] [ebp-414h] BYREF
  char filename[512]; // [esp+200h] [ebp-214h] BYREF
  ConVarRef cl_logofile; // [esp+400h] [ebp-14h] BYREF
  const char *logofile; // [esp+408h] [ebp-Ch]
  int initialItem; // [esp+40Ch] [ebp-8h]
  int fh; // [esp+410h] [ebp-4h] BYREF
  int i; // [esp+41Ch] [ebp+8h]

  ConVarRef::ConVarRef(this: &cl_logofile, pName: "cl_logofile");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cl_logofile) )
  {
    ((void (__thiscall *)(CLabeledCommandComboBox *, int))cb->DeleteAllItems)(a1: cb, a2);
    logofile = cl_logofile.m_pConVarState->m_Value.m_pszString;
    V_snprintf(pDest: directory, maxLen: 0x200u, pFormat: "materials/vgui/logos/*.vtf");
    v4 = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: directory, a3: &fh);
    i = 0;
    for ( initialItem = 0; v4 != nullptr; v4 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: fh) )
    {
      V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "materials/vgui/logos/%s", v4);
      v5 = &filename[strlen(filename) + 1] - &filename[1];
      if ( v5 >= 4 )
      {
        directory[v5 + 508] = v6;
        V_strncat(pDest: filename, pSrc: ".vmt", destBufferSize: 0x200u, max_chars_to_copy: -1);
        if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: nullptr) )
        {
          V_strncpy(pDest: filename, pSrc: v4, maxLen: 512);
          AddItem_3 = cb->AddItem_3;
          directory[&filename[strlen(filename) + 1] - &filename[1] + 508] = 0;
          AddItem_3(this: cb, a2: filename, a3: prType);
          V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "materials/vgui/logos/%s", v4);
          if ( _V_stricmp(s1: filename, s2: logofile) == 0 )
            initialItem = i;
          ++i;
        }
      }
    }
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: fh);
    CLabeledCommandComboBox::SetInitialItem(this: cb, index: initialItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCE80
// Name: private: void COptionsSubMultiplayer::SelectLogo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::SelectLogo(COptionsSubMultiplayer *this, const char *logoName)
{
  int v3; // ebx
  int v4; // esi
  wchar_t itemText[260]; // [esp+Ch] [ebp-410h] BYREF
  wchar_t itemToSelectText[260]; // [esp+214h] [ebp-208h] BYREF

  v3 = this->m_pLogoList->GetItemCount(this: this->m_pLogoList);
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: logoName, a3: itemToSelectText, a4: 520);
  v4 = 0;
  if ( v3 > 0 )
  {
    while ( 1 )
    {
      vgui::ComboBox::GetItemText(this: this->m_pLogoList, itemID: v4, text: itemText, bufLenInBytes: 520);
      if ( wcscmp(itemText, itemToSelectText) == 0 )
        break;
      if ( ++v4 >= v3 )
        return;
    }
    if ( v4 < v3 )
      this->m_pLogoList->ActivateItem(this: this->m_pLogoList, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCF50
// Name: void StripStringOutOfString(char const __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StripStringOutOfString(const char *pPattern, const char *pIn, char *pOut)
{
  signed int v3; // ecx
  signed int v4; // eax
  char *v5; // esi
  int v6; // edi

  v3 = strlen(pPattern);
  v4 = strlen(pIn);
  if ( v3 >= v4 )
  {
    *pOut = 0;
  }
  else
  {
    v5 = &pOut[-v3];
    v6 = v4 - v3;
    do
    {
      v5[v3] = pIn[v3];
      ++v3;
    }
    while ( v3 < v4 );
    pOut[v6] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCFC0
// Name: void FindVMTFilesInFolder(char const __near *,char const __near *,class CLabeledCommandComboBox __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindVMTFilesInFolder(
        const char *pFolder,
        const char *pFolderName,
        CLabeledCommandComboBox *cb,
        int *iCount,
        int *iInitialItem)
{
  char *v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  char v8; // cl
  void (__thiscall *AddItem_3)(CLabeledCommandComboBox *, const char *, const char *); // edx
  char realname[512]; // [esp+0h] [ebp-C10h] BYREF
  char directory[512]; // [esp+200h] [ebp-A10h] BYREF
  char texturepath[512]; // [esp+400h] [ebp-810h] BYREF
  char folderpath[512]; // [esp+600h] [ebp-610h] BYREF
  char displayname[512]; // [esp+800h] [ebp-410h] BYREF
  char filename[512]; // [esp+A00h] [ebp-210h] BYREF
  ConVarRef cl_modelfile; // [esp+C00h] [ebp-10h] BYREF
  const char *modelfile; // [esp+C08h] [ebp-8h]
  int fh; // [esp+C0Ch] [ebp-4h] BYREF

  ConVarRef::ConVarRef(this: &cl_modelfile, pName: "cl_playermodel");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cl_modelfile) )
  {
    V_snprintf(pDest: directory, maxLen: 512, pFormat: "%s/*.*", pFolder);
    v5 = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: directory, a3: &fh);
    for ( modelfile = cl_modelfile.m_pConVarState->m_Value.m_pszString;
          v5 != nullptr;
          v5 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: fh) )
    {
      if ( _V_stricmp(s1: v5, s2: ".") != 0 && _V_stricmp(s1: v5, s2: "..") != 0 )
      {
        if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: fh) )
        {
          V_snprintf(pDest: folderpath, maxLen: 512, pFormat: "%s/%s", pFolder, v5);
          FindVMTFilesInFolder(pFolder: folderpath, pFolderName: v5, cb, iCount, iInitialItem);
        }
        else
        {
          strstr(str1: (unsigned __int8 *)v5, str2: ".vmt");
          if ( v6 != 0 )
          {
            V_snprintf(pDest: filename, maxLen: 512, pFormat: "%s/%s", pFolder, v5);
            v7 = &filename[strlen(filename) + 1] - &filename[1];
            if ( v7 >= 4 )
            {
              displayname[v7 + 508] = v8;
              V_strncat(pDest: filename, pSrc: ".vmt", destBufferSize: 0x200u, max_chars_to_copy: -1);
              if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: nullptr) )
              {
                V_strncpy(pDest: displayname, pSrc: v5, maxLen: 512);
                StripStringOutOfString(pPattern: "materials/vgui/playermodels/", pIn: filename, pOut: texturepath);
                AddItem_3 = cb->AddItem_3;
                folderpath[strlen(displayname) + 508] = 0;
                AddItem_3(this: cb, a2: displayname, a3: &texturepath[1]);
                V_FileBase(in: modelfile, out: realname, maxlen: 512);
                V_FileBase(in: filename, out: filename, maxlen: 512);
                if ( _V_stricmp(s1: filename, s2: realname) == 0 )
                  *iInitialItem = *iCount;
                ++*iCount;
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD220
// Name: private: void COptionsSubMultiplayer::InitCrosshairSizeList(class CLabeledCommandComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::InitCrosshairSizeList(
        COptionsSubMultiplayer *this,
        CLabeledCommandComboBox *cb)
{
  int v2; // edi
  int m_nValue; // eax
  ConVarRef cl_crosshairscale; // [esp+4h] [ebp-8h] BYREF

  if ( cb != nullptr )
  {
    CLabeledCommandComboBox::Reset(this: cb);
    cb->AddItem_3(this: cb, a2: "#GameUI_Auto", a3: "cl_crosshairscale 0");
    cb->AddItem_3(this: cb, a2: "#GameUI_Small", a3: "cl_crosshairscale 1200");
    cb->AddItem_3(this: cb, a2: "#GameUI_Medium", a3: "cl_crosshairscale 768");
    cb->AddItem_3(this: cb, a2: "#GameUI_Large", a3: "cl_crosshairscale 600");
    v2 = 0;
    ConVarRef::ConVarRef(this: &cl_crosshairscale, pName: "cl_crosshairscale");
    if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cl_crosshairscale) )
    {
      m_nValue = cl_crosshairscale.m_pConVarState->m_Value.m_nValue;
      if ( m_nValue <= 0 )
      {
        CLabeledCommandComboBox::SetInitialItem(this: cb, index: 0);
        return;
      }
      if ( m_nValue <= 600 )
      {
        CLabeledCommandComboBox::SetInitialItem(this: cb, index: 3);
        return;
      }
      v2 = (m_nValue <= 768) + 1;
    }
    CLabeledCommandComboBox::SetInitialItem(this: cb, index: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD300
// Name: private: void COptionsSubMultiplayer::InitAdvCrosshairStyleList(class CLabeledCommandComboBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COptionsSubMultiplayer::InitAdvCrosshairStyleList(
        COptionsSubMultiplayer *this@<ecx>,
        int a2@<edi>,
        CLabeledCommandComboBox *cb)
{
  char *v4; // edi
  unsigned int v5; // eax
  char v6; // cl
  void (__thiscall *AddItem_3)(CLabeledCommandComboBox *, const char *, const char *); // edx
  char directory[512]; // [esp+0h] [ebp-510h] BYREF
  char crosshairfile[256]; // [esp+200h] [ebp-310h] BYREF
  char filename[512]; // [esp+300h] [ebp-210h] BYREF
  ConVarRef cl_crosshair_file; // [esp+500h] [ebp-10h] BYREF
  int initialItem; // [esp+508h] [ebp-8h]
  int fh; // [esp+50Ch] [ebp-4h] BYREF
  int i; // [esp+518h] [ebp+8h]

  ConVarRef::ConVarRef(this: &cl_crosshair_file, pName: "cl_crosshair_file");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cl_crosshair_file) )
  {
    ((void (__thiscall *)(CLabeledCommandComboBox *, int))cb->DeleteAllItems)(a1: cb, a2);
    V_snprintf(
      pDest: crosshairfile,
      maxLen: 0x100u,
      pFormat: "materials/vgui/crosshairs/%s.vtf",
      cl_crosshair_file.m_pConVarState->m_Value.m_pszString);
    V_snprintf(pDest: directory, maxLen: 0x200u, pFormat: "materials/vgui/crosshairs/*.vtf");
    v4 = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: directory, a3: &fh);
    i = 0;
    for ( initialItem = 0; v4 != nullptr; v4 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: fh) )
    {
      V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "materials/vgui/crosshairs/%s", v4);
      v5 = &filename[strlen(filename) + 1] - &filename[1];
      if ( v5 >= 4 )
      {
        crosshairfile[v5 + 252] = v6;
        V_strncat(pDest: filename, pSrc: ".vmt", destBufferSize: 0x200u, max_chars_to_copy: -1);
        if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: nullptr) )
        {
          V_strncpy(pDest: filename, pSrc: v4, maxLen: 512);
          AddItem_3 = cb->AddItem_3;
          crosshairfile[&filename[strlen(filename) + 1] - &filename[1] + 252] = 0;
          AddItem_3(this: cb, a2: filename, a3: prType);
          V_snprintf(pDest: filename, maxLen: 0x200u, pFormat: "materials/vgui/crosshairs/%s", v4);
          if ( _V_stricmp(s1: filename, s2: crosshairfile) == 0 )
            initialItem = i;
          ++i;
        }
      }
    }
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: fh);
    CLabeledCommandComboBox::SetInitialItem(this: cb, index: initialItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD4D0
// Name: private: void COptionsSubMultiplayer::RemapLogo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COptionsSubMultiplayer::RemapLogo(COptionsSubMultiplayer *this@<ecx>, int a2@<esi>)
{
  void *v3; // esi
  char data[1024]; // [esp+4h] [ebp-700h] BYREF
  char fullLogoName[512]; // [esp+404h] [ebp-300h] BYREF
  char logoname[256]; // [esp+604h] [ebp-100h] BYREF

  this->m_pLogoList->GetText_2(this: this->m_pLogoList, a2: logoname, a3: 256);
  if ( logoname[0] != 0 )
  {
    ((void (__thiscall *)(IFileSystem *, const char *, const char *, int))g_pFullFileSystem->CreateDirHierarchy)(
      a1: g_pFullFileSystem,
      a2: "materials/VGUI/logos/UI",
      a3: "GAME",
      a4: a2);
    V_snprintf(pDest: fullLogoName, maxLen: 0x200u, pFormat: "materials/VGUI/logos/UI/%s.vmt", logoname);
    if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: fullLogoName, a3: nullptr) )
    {
      v3 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *))g_pFullFileSystem->Open)(
                     a1: &g_pFullFileSystem->IBaseFileSystem,
                     a2: fullLogoName,
                     a3: "wb");
      if ( v3 == nullptr )
        return;
      V_snprintf(
        pDest: data,
        maxLen: 0x400u,
        pFormat: "\"UnlitGeneric\"\n"
        "{\n"
        "\t// Original shader: BaseTimesVertexColorAlphaBlendNoOverbright\n"
        "\t\"$translucent\" 1\n"
        "\t\"$basetexture\" \"VGUI\\logos\\%s\"\n"
        "\t\"$vertexcolor\" 1\n"
        "\t\"$vertexalpha\" 1\n"
        "\t\"$no_fullbright\" 1\n"
        "\t\"$ignorez\" 1\n"
        "}\n",
        logoname);
      ((void (__thiscall *)(IBaseFileSystem *, char *, unsigned int, void *, _DWORD))g_pFullFileSystem->Write)(
        a1: &g_pFullFileSystem->IBaseFileSystem,
        a2: data,
        a3: strlen(data),
        a4: v3,
        a5: 0);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3);
    }
    V_snprintf(pDest: fullLogoName, maxLen: 0x200u, pFormat: "logos/UI/%s", logoname);
    this->m_pLogoImage->SetImage(this: this->m_pLogoImage, a2: fullLogoName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD630
// Name: private: void COptionsSubMultiplayer::RemapModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::RemapModel(COptionsSubMultiplayer *this)
{
  char *ActiveItemCommand; // eax
  _BYTE v3[4]; // [esp+0h] [ebp-104h]
  char texture[256]; // [esp+4h] [ebp-100h] BYREF

  ActiveItemCommand = CLabeledCommandComboBox::GetActiveItemCommand(this: this->m_pModelList);
  if ( ActiveItemCommand != nullptr )
  {
    V_snprintf(pDest: texture, maxLen: 0x100u, pFormat: "vgui/playermodels/%s", ActiveItemCommand);
    v3[strlen(texture)] = 0;
    this->m_pModelImage->setTexture(this: this->m_pModelImage, a2: texture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD6A0
// Name: private: virtual void COptionsSubMultiplayer::OnApplyButtonEnable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::OnApplyButtonEnable(COptionsSubMultiplayer *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  COptionsSubMultiplayer_vtbl *v4; // edi
  int v5; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ApplyButtonEnable");
  else
    v3 = nullptr;
  v4 = this->__vftable;
  v5 = ((int (__thiscall *)(COptionsSubMultiplayer *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v3, a3: 0);
  ((void (__thiscall *)(COptionsSubMultiplayer *, int))v4->PostMessage)(a1: this, a2: v5);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101DD700
// Name: protected: virtual void COptionsSubMultiplayer::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::OnResetData(COptionsSubMultiplayer *this)
{
  BOOL v2; // [esp-4h] [ebp-10h]
  ConVarRef cl_downloadfilter; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_pDownloadFilterCombo != nullptr )
  {
    ConVarRef::ConVarRef(this: &cl_downloadfilter, pName: "cl_downloadfilter");
    if ( _V_stricmp(s1: cl_downloadfilter.m_pConVarState->m_Value.m_pszString, s2: "none") != 0 )
    {
      v2 = _V_stricmp(s1: cl_downloadfilter.m_pConVarState->m_Value.m_pszString, s2: "nosounds") == 0;
      this->m_pDownloadFilterCombo->ActivateItem(this: this->m_pDownloadFilterCombo, a2: v2);
    }
    else
    {
      this->m_pDownloadFilterCombo->ActivateItem(this: this->m_pDownloadFilterCombo, a2: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD780
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ImagePanel::GetMessageMap(vgui::ImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ImagePanel");
  `vgui::ImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DD7C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ImagePanel::GetKBMap(vgui::ImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ImagePanel::GetKBMap'::`2'::s_pMap;
  `vgui::ImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ImagePanel");
  `vgui::ImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DD7F0
// Name: public: CrosshairImagePanel::CrosshairImagePanel(class vgui::Panel __near *,char const __near *,class CCvarToggleCheckButton __near *)
// Source: json
//------------------------------------------------------------------------------
CrosshairImagePanel *__thiscall CrosshairImagePanel::CrosshairImagePanel(
        CrosshairImagePanel *this,
        vgui::Panel *parent,
        const char *name,
        CCvarToggleCheckButton *pAdditive)
{
  const char *v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // eax

  vgui::ImagePanel::ImagePanel(this, parent, name);
  this->m_pAdditive = pAdditive;
  this->m_R = 50;
  this->m_B = 50;
  this->__vftable = (CrosshairImagePanel_vtbl *)&CrosshairImagePanel::`vftable';
  this->m_G = 250;
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: (int *)&name, a3: (int *)&parent);
  v5 = name;
  if ( (int)name > 640 )
    v6 = ((int)name >= 1024) + 2;
  else
    v6 = 1;
  v7 = v6 - 2;
  if ( v7 != 0 )
  {
    if ( v7 == 1 )
      v8 = 640;
    else
      v8 = 1024;
  }
  else
  {
    v8 = 800;
  }
  this->m_barSize = 9 * (int)name / v8;
  this->m_barGap = 5 * (int)v5 / v8;
  v9 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  this->m_iCrosshairTextureID = v9;
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v9, a3: "vgui/white_additive", a4: 1, a5: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DD8E0
// Name: public: virtual void CrosshairImagePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CrosshairImagePanel::Paint(CrosshairImagePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  char v4; // bl
  int m_nValue; // edi
  vgui::ISurface_vtbl *v6; // edx
  vgui::ISurface_vtbl *v7; // edx
  int v8; // eax
  IConVar *v9; // edi
  int v10; // kr08_4
  vgui::ISurface_vtbl *v11; // edx
  int m_barSize; // ecx
  int v13; // edi
  vgui::ISurface_vtbl *v14; // esi
  int v15; // [esp-10h] [ebp-24h]
  int v16; // [esp-Ch] [ebp-20h]
  int v17; // [esp-8h] [ebp-1Ch]
  int v18; // [esp-4h] [ebp-18h]
  int v19; // [esp+0h] [ebp-14h]
  int v20; // [esp+0h] [ebp-14h]
  ConVarRef cl_crosshairalpha; // [esp+4h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( this->m_pAdditive != nullptr )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v4 = ((int (__thiscall *)(CCvarToggleCheckButton *, int, int))this->m_pAdditive->IsSelected)(
           a1: this->m_pAdditive,
           a2: a3,
           a3: a2);
    m_nValue = 200;
    if ( v4 == 0 )
    {
      ConVarRef::ConVarRef(this: &cl_crosshairalpha, pName: "cl_crosshairalpha");
      if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cl_crosshairalpha) )
      {
        m_nValue = cl_crosshairalpha.m_pConVarState->m_Value.m_nValue;
        if ( m_nValue >= 0 )
        {
          if ( m_nValue > 255 )
            m_nValue = 255;
        }
        else
        {
          m_nValue = 0;
        }
      }
    }
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: this->m_R, a3: this->m_G, a4: this->m_B, a5: m_nValue);
    if ( v4 != 0 )
      g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iCrosshairTextureID);
    v6 = g_pVGuiSurface->__vftable;
    v18 = tall / 2 + 1;
    v17 = wide / 2 - this->m_barSize - this->m_barGap + 1 + this->m_barSize;
    v16 = tall / 2;
    v15 = wide / 2 - this->m_barSize - this->m_barGap + 1;
    if ( v4 != 0 )
      ((void (__stdcall *)(int, int, int, int, int, IConVar *, ConVar *, int))v6->DrawTexturedRect)(
        a1: v15,
        a2: v16,
        a3: v17,
        a4: v18,
        a5: v19,
        a6: cl_crosshairalpha.m_pConVar,
        a7: cl_crosshairalpha.m_pConVarState,
        a8: wide);
    else
      ((void (__stdcall *)(int, int, int, int, int, IConVar *, ConVar *, int))v6->DrawFilledRect)(
        a1: v15,
        a2: v16,
        a3: v17,
        a4: v18,
        a5: v19,
        a6: cl_crosshairalpha.m_pConVar,
        a7: cl_crosshairalpha.m_pConVarState,
        a8: wide);
    v7 = g_pVGuiSurface->__vftable;
    v8 = this->m_barGap + wide / 2;
    wide = tall / 2 + 1;
    cl_crosshairalpha.m_pConVarState = (ConVar *)(v8 + this->m_barSize);
    cl_crosshairalpha.m_pConVar = (IConVar *)(tall / 2);
    if ( v4 != 0 )
      ((void (__stdcall *)(int, IConVar *, ConVar *, int))v7->DrawTexturedRect)(
        a1: v8,
        a2: cl_crosshairalpha.m_pConVar,
        a3: cl_crosshairalpha.m_pConVarState,
        a4: wide);
    else
      ((void (__stdcall *)(int, IConVar *, ConVar *, int))v7->DrawFilledRect)(
        a1: v8,
        a2: cl_crosshairalpha.m_pConVar,
        a3: cl_crosshairalpha.m_pConVarState,
        a4: wide);
    v9 = (IConVar *)(tall / 2 - this->m_barSize - this->m_barGap);
    v10 = wide;
    v11 = g_pVGuiSurface->__vftable;
    wide = tall / 2 - this->m_barGap;
    cl_crosshairalpha.m_pConVarState = (ConVar *)(v10 / 2 + 1);
    cl_crosshairalpha.m_pConVar = v9;
    v20 = v10 / 2;
    if ( v4 != 0 )
      ((void (__stdcall *)(int, IConVar *))v11->DrawTexturedRect)(a1: v20, a2: cl_crosshairalpha.m_pConVar);
    else
      ((void (__stdcall *)(int, IConVar *))v11->DrawFilledRect)(a1: v20, a2: cl_crosshairalpha.m_pConVar);
    m_barSize = this->m_barSize;
    v13 = this->m_barGap + tall / 2;
    v14 = g_pVGuiSurface->__vftable;
    cl_crosshairalpha.m_pConVar = (IConVar *)(v13 + m_barSize);
    if ( v4 != 0 )
      ((void (__thiscall *)(vgui::ISurface *))v14->DrawTexturedRect)(a1: g_pVGuiSurface);
    else
      ((void (__thiscall *)(vgui::ISurface *))v14->DrawFilledRect)(a1: g_pVGuiSurface);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDAD0
// Name: public: AdvancedCrosshairImagePanel::AdvancedCrosshairImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
AdvancedCrosshairImagePanel *__thiscall AdvancedCrosshairImagePanel::AdvancedCrosshairImagePanel(
        AdvancedCrosshairImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  CModInfo *v4; // eax

  vgui::ImagePanel::ImagePanel(this, parent, name);
  this->__vftable = (AdvancedCrosshairImagePanel_vtbl *)&AdvancedCrosshairImagePanel::`vftable';
  this->m_pAdvCrosshair = nullptr;
  this->m_pFrameVar = nullptr;
  v4 = ModInfo();
  if ( CModInfo::AdvCrosshair(this: v4) )
  {
    this->m_iCrosshairTextureID = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    AdvancedCrosshairImagePanel::UpdateCrosshair(
      this,
      a2: (int)this,
      r: 50,
      g: 250,
      b: 50,
      scale: 32.0,
      crosshairname: "vgui/crosshairs/crosshair1");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DDBD0
// Name: protected: virtual void COptionsSubMultiplayer::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::OnCommand(COptionsSubMultiplayer *this, const char *command)
{
  CMultiplayerAdvancedDialog *v3; // eax
  CMultiplayerAdvancedDialog *v4; // eax
  vgui::Panel *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax

  if ( _V_stricmp(s1: command, s2: "Advanced") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "ImportSprayImage") == 0 )
    {
      if ( this->m_hImportSprayDialog == nullptr )
      {
        v6 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
        if ( v6 != nullptr )
          v7 = vgui::FileOpenDialog::FileOpenDialog(
                 this: v6,
                 parent: nullptr,
                 title: "#GameUI_ImportSprayImage",
                 bOpenOnly: true,
                 pContextKeyValues: nullptr);
        else
          v7 = nullptr;
        this->m_hImportSprayDialog = v7;
        vgui::FileOpenDialog::AddFilter(
          this: v7,
          filter: "*.tga,*.jpg,*.bmp,*.vtf",
          filterName: "#GameUI_All_Images",
          bActive: true,
          pFilterInfo: nullptr);
        vgui::FileOpenDialog::AddFilter(
          this: this->m_hImportSprayDialog,
          filter: "*.tga",
          filterName: "#GameUI_TGA_Images",
          bActive: false,
          pFilterInfo: nullptr);
        vgui::FileOpenDialog::AddFilter(
          this: this->m_hImportSprayDialog,
          filter: "*.jpg",
          filterName: "#GameUI_JPEG_Images",
          bActive: false,
          pFilterInfo: nullptr);
        vgui::FileOpenDialog::AddFilter(
          this: this->m_hImportSprayDialog,
          filter: "*.bmp",
          filterName: "#GameUI_BMP_Images",
          bActive: false,
          pFilterInfo: nullptr);
        vgui::FileOpenDialog::AddFilter(
          this: this->m_hImportSprayDialog,
          filter: "*.vtf",
          filterName: "#GameUI_VTF_Images",
          bActive: false,
          pFilterInfo: nullptr);
        this->m_hImportSprayDialog->AddActionSignalTarget_2(this: this->m_hImportSprayDialog, a2: this);
      }
      vgui::FileOpenDialog::DoModal(this: this->m_hImportSprayDialog, bUnused: false);
      this->m_hImportSprayDialog->Activate(this: this->m_hImportSprayDialog);
    }
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    if ( vgui::PHandle::Get(this: &this->m_hMultiplayerAdvancedDialog) == nullptr )
    {
      v3 = (CMultiplayerAdvancedDialog *)MemAlloc_Alloc(nSize: 0x220u);
      if ( v3 != nullptr )
        v4 = CMultiplayerAdvancedDialog::CMultiplayerAdvancedDialog(this: v3, parent: this);
      else
        v4 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hMultiplayerAdvancedDialog, pPanel: v4);
    }
    v5 = vgui::PHandle::Get(this: &this->m_hMultiplayerAdvancedDialog);
    v5->__vftable[1].OnTick(this: v5);
    vgui::Panel::OnCommand(this, command);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDD50
// Name: private: enum ConversionErrorType COptionsSubMultiplayer::ConvertTGA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge COptionsSubMultiplayer::ConvertTGA@<eax>(
        COptionsSubMultiplayer *this@<ecx>,
        int a2@<ebx>,
        char *tgaPath)
{
  _iobuf *v3; // edi
  int v5; // eax
  char v6; // cl
  int v7; // esi
  char v8; // cl
  float v9; // xmm0_4
  float v10; // xmm1_4
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  unsigned __int8 *v12; // ebx
  unsigned int v13; // edi
  _iobuf *v14; // ecx
  void *v15; // edi
  unsigned int v16; // [esp-8h] [ebp-3Ch]
  TGAHeader tgaHeader; // [esp+8h] [ebp-2Ch] BYREF
  COptionsSubMultiplayer *v18; // [esp+1Ch] [ebp-18h]
  int tgaWidth; // [esp+20h] [ebp-14h] BYREF
  int tgaHeight; // [esp+24h] [ebp-10h] BYREF
  int finalWidth; // [esp+28h] [ebp-Ch] BYREF
  int finalHeight; // [esp+2Ch] [ebp-8h]
  int paddedImageWidth; // [esp+30h] [ebp-4h]
  _iobuf *outfile; // [esp+3Ch] [ebp+8h]

  v18 = this;
  tgaWidth = 0;
  tgaHeight = 0;
  v3 = COptionsSubMultiplayer::ReadTGAAsRGBA(
         this,
         a2,
         tgaPath,
         width: &tgaWidth,
         height: &tgaHeight,
         errcode: (ConversionErrorType *)&finalWidth,
         &tgaHeader);
  if ( v3 == nullptr )
    return finalWidth;
  if ( tgaWidth <= 0 || tgaHeight <= 0 )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    return 3;
  }
  else
  {
    v5 = tgaWidth;
    paddedImageWidth = tgaWidth;
    if ( ((tgaWidth - 1) & tgaWidth) != 0 )
    {
      v6 = 1;
      if ( tgaWidth > 1 )
      {
        do
        {
          v5 >>= 1;
          ++v6;
        }
        while ( v5 > 1 );
      }
      v5 <<= v6;
      paddedImageWidth = v5;
    }
    if ( v5 > 256 )
    {
      paddedImageWidth = 256;
      v5 = 256;
    }
    v7 = tgaHeight;
    if ( ((tgaHeight - 1) & tgaHeight) != 0 )
    {
      v8 = 1;
      if ( tgaHeight > 1 )
      {
        do
        {
          v7 >>= 1;
          ++v8;
        }
        while ( v7 > 1 );
      }
      v7 <<= v8;
    }
    if ( v7 > 256 )
      v7 = 256;
    v9 = (float)v5 / (float)tgaWidth;
    v10 = (float)v7 / (float)tgaHeight;
    if ( v10 <= v9 )
    {
      finalHeight = v7;
      if ( v9 > v10 )
        v5 = (int)(float)((float)((float)tgaWidth * v10) + 0.5);
    }
    else
    {
      finalHeight = (int)(float)((float)((float)tgaHeight * v9) + 0.5);
    }
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    finalWidth = v5;
    v12 = (unsigned __int8 *)((int (__thiscall *)(IMemAlloc *, int, int))Alloc_2)(
                               a1: _g_pMemAlloc,
                               a2: 4 * v5 * finalHeight,
                               a3: a2);
    COptionsSubMultiplayer::StretchRGBAImage(
      this: v18,
      srcBuf: (const unsigned __int8 *)v3,
      srcWidth: tgaWidth,
      srcHeight: tgaHeight,
      destBuf: v12,
      destWidth: finalWidth,
      destHeight: finalHeight);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    v13 = 4 * paddedImageWidth * v7;
    tgaWidth = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v13);
    COptionsSubMultiplayer::PadRGBAImage(
      this: v18,
      srcBuf: v12,
      srcWidth: finalWidth,
      srcHeight: finalHeight,
      destBuf: (unsigned __int8 *)tgaWidth,
      destWidth: paddedImageWidth,
      destHeight: v7);
    v14 = fopen(file: (_iobuf *)tgaPath, mode: "wb");
    outfile = v14;
    if ( v14 != nullptr )
    {
      tgaHeader.width = paddedImageWidth;
      tgaHeader.height = v7;
      WriteTGAHeader(outfile: v14, header: &tgaHeader);
      v16 = v13;
      v15 = (void *)tgaWidth;
      fwrite(buffer: (unsigned __int8 *)tgaWidth, size: 1u, count: v16, stream: outfile);
      fclose(stream: outfile);
      ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      return 0;
    }
    else
    {
      ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)tgaWidth);
      return 5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDFA0
// Name: private: void COptionsSubMultiplayer::RedrawCrosshairImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::RedrawCrosshairImage(COptionsSubMultiplayer *this)
{
  vgui::ComboBox *m_pCrosshairColorComboBox; // ecx
  KeyValues *ActiveItemUserData; // eax
  vgui::ComboBox *v4; // ecx
  int ActiveItem; // esi
  int m_nValue; // ebx
  CLabeledCommandComboBox *m_pCrosshairSize; // ecx
  int v8; // eax
  ConVarRef cl_crosshaircolor; // [esp+4h] [ebp-8h] BYREF

  m_pCrosshairColorComboBox = this->m_pCrosshairColorComboBox;
  if ( m_pCrosshairColorComboBox != nullptr )
  {
    ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: m_pCrosshairColorComboBox);
    KeyValues::GetInt(this: ActiveItemUserData, keyName: "color", defaultValue: 0);
    v4 = this->m_pCrosshairColorComboBox;
    ActiveItem = 0;
    m_nValue = 0;
    if ( v4 != nullptr )
      ActiveItem = vgui::ComboBox::GetActiveItem(this: v4);
    ConVarRef::ConVarRef(this: &cl_crosshaircolor, pName: "cl_crosshaircolor");
    if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cl_crosshaircolor) )
    {
      m_nValue = cl_crosshaircolor.m_pConVarState->m_Value.m_nValue;
      if ( m_nValue >= 0 )
      {
        if ( m_nValue > 5 )
          m_nValue = 5;
      }
      else
      {
        m_nValue = 0;
      }
    }
    if ( ActiveItem != m_nValue )
      this->OnApplyButtonEnable(this);
    if ( this->m_pCrosshairImage != nullptr )
    {
      m_pCrosshairSize = this->m_pCrosshairSize;
      if ( m_pCrosshairSize != nullptr )
      {
        v8 = vgui::ComboBox::GetActiveItem(this: m_pCrosshairSize);
        CrosshairImagePanel::UpdateCrosshair(
          this: this->m_pCrosshairImage,
          r: s_crosshairColors[ActiveItem].r,
          g: s_crosshairColors[ActiveItem].g,
          b: s_crosshairColors[ActiveItem].b,
          size: v8);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE070
// Name: private: void COptionsSubMultiplayer::RedrawAdvCrosshairImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::RedrawAdvCrosshairImage(COptionsSubMultiplayer *this)
{
  CModInfo *v2; // eax
  double SliderValue; // st7
  float v4; // xmm0_4
  int v5; // ebx
  double v6; // st7
  float v7; // xmm0_4
  int v8; // edi
  double v9; // st7
  float v10; // xmm0_4
  char texture[256]; // [esp+1Ch] [ebp-208h] BYREF
  char crosshairname[256]; // [esp+11Ch] [ebp-108h] BYREF
  float scale; // [esp+21Ch] [ebp-8h]
  float v14; // [esp+220h] [ebp-4h]

  v2 = ModInfo();
  if ( !CModInfo::AdvCrosshair(this: v2) )
    return;
  SliderValue = CCvarSlider::GetSliderValue(this: this->m_pAdvCrosshairRedSlider);
  v14 = SliderValue;
  if ( SliderValue >= 0.0 )
  {
    v4 = v14;
    if ( v14 > 255.0 )
      v4 = 255.0;
  }
  else
  {
    v4 = 0.0;
  }
  v5 = (int)v4;
  v6 = CCvarSlider::GetSliderValue(this: this->m_pAdvCrosshairGreenSlider);
  v14 = v6;
  if ( v6 >= 0.0 )
  {
    v7 = v14;
    if ( v14 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  v8 = (int)v7;
  v9 = CCvarSlider::GetSliderValue(this: this->m_pAdvCrosshairBlueSlider);
  v14 = v9;
  if ( v9 < 0.0 )
  {
    v10 = 0.0;
LABEL_12:
    v14 = v10;
    goto LABEL_13;
  }
  v10 = v14;
  if ( v14 <= 255.0 )
    goto LABEL_12;
  v14 = 255.0;
LABEL_13:
  scale = CCvarSlider::GetSliderValue(this: this->m_pAdvCrosshairScaleSlider);
  if ( this->m_pAdvCrosshairImage != nullptr && this->m_pAdvCrosshairStyle != nullptr )
  {
    this->m_pAdvCrosshairStyle->GetText_2(this: this->m_pAdvCrosshairStyle, a2: crosshairname, a3: 256);
    V_snprintf(pDest: texture, maxLen: 0x100u, pFormat: "vgui/crosshairs/%s", crosshairname);
    AdvancedCrosshairImagePanel::UpdateCrosshair(
      this: this->m_pAdvCrosshairImage,
      r: v5,
      g: v8,
      b: (int)v14,
      scale,
      crosshairname: texture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE1D0
// Name: private: virtual void COptionsSubMultiplayer::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::OnTextChanged(COptionsSubMultiplayer *this, vgui::Panel *panel)
{
  COptionsSubMultiplayer::RemapModel(this);
  COptionsSubMultiplayer::RemapLogo(this, a2: (int)this);
  COptionsSubMultiplayer::RedrawCrosshairImage(this);
  COptionsSubMultiplayer::RedrawAdvCrosshairImage(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DE200
// Name: private: virtual void COptionsSubMultiplayer::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::OnSliderMoved(COptionsSubMultiplayer *this, KeyValues *data)
{
  int SliderValue; // eax
  CCvarSlider *m_pSecondaryColorSlider; // ecx

  SliderValue = (int)CCvarSlider::GetSliderValue(this: this->m_pPrimaryColorSlider);
  m_pSecondaryColorSlider = this->m_pSecondaryColorSlider;
  this->m_nTopColor = SliderValue;
  this->m_nBottomColor = (int)CCvarSlider::GetSliderValue(this: m_pSecondaryColorSlider);
  COptionsSubMultiplayer::RemapModel(this);
  COptionsSubMultiplayer::RedrawAdvCrosshairImage(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DE250
// Name: private: void COptionsSubMultiplayer::InitCrosshairColorEntries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::InitCrosshairColorEntries(COptionsSubMultiplayer *this)
{
  COptionsSubMultiplayer *v1; // esi
  int v2; // ebx
  int m_nValue; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  ColorItem_t *v6; // esi
  ConVarRef cl_crosshaircolor; // [esp+8h] [ebp-10h] BYREF
  COptionsSubMultiplayer *v8; // [esp+10h] [ebp-8h]
  int index; // [esp+14h] [ebp-4h]

  v1 = this;
  v8 = this;
  ConVarRef::ConVarRef(this: &cl_crosshaircolor, pName: "cl_crosshaircolor");
  v2 = 0;
  index = 0;
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cl_crosshaircolor) )
  {
    m_nValue = cl_crosshaircolor.m_pConVarState->m_Value.m_nValue;
    if ( m_nValue >= 0 )
    {
      index = 5;
      if ( m_nValue <= 5 )
        index = m_nValue;
    }
    else
    {
      index = 0;
    }
  }
  if ( v1->m_pCrosshairColorComboBox != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "data");
    else
      v5 = nullptr;
    KeyValues::Clear(this: v5);
    v6 = s_crosshairColors;
    do
    {
      KeyValues::SetInt(this: v5, keyName: "color", value: v2);
      v8->m_pCrosshairColorComboBox->AddItem_2(this: v8->m_pCrosshairColorComboBox, a2: v6->name, a3: v5);
      ++v6;
      ++v2;
    }
    while ( (int)v6 < (int)&vec2_invalid_54 );
    vgui::ComboBox::ActivateItemByRow(this: v8->m_pCrosshairColorComboBox, row: index);
    KeyValues::deleteThis(this: v5);
    v1 = v8;
  }
  COptionsSubMultiplayer::RedrawCrosshairImage(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101DE330
// Name: protected: virtual void COptionsSubMultiplayer::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMultiplayer::OnApplyChanges(COptionsSubMultiplayer *this)
{
  int i; // ebx
  CCvarToggleCheckButton *v3; // edi
  CModInfo *v4; // eax
  CLabeledCommandComboBox *m_pCrosshairSize; // ecx
  CCvarToggleCheckButton *m_pCrosshairTranslucencyCheckbox; // ecx
  vgui::ComboBox *m_pCrosshairColorComboBox; // ecx
  int ActiveItem; // eax
  CModInfo *v9; // eax
  CLabeledCommandComboBox *m_pModelList; // ecx
  char *ActiveItemCommand; // eax
  int v12; // eax
  void (__thiscall *SetValue_4)(IConVar *, const char *); // edx
  char pDest[512]; // [esp+Ch] [ebp-508h] BYREF
  char cmd[512]; // [esp+20Ch] [ebp-308h] BYREF
  char crosshair[256]; // [esp+40Ch] [ebp-108h] BYREF
  ConVarRef cl_downloadfilter; // [esp+50Ch] [ebp-8h] BYREF

  CCvarSlider::ApplyChanges(this: this->m_pPrimaryColorSlider);
  CCvarSlider::ApplyChanges(this: this->m_pSecondaryColorSlider);
  CLabeledCommandComboBox::ApplyChanges(this: this->m_pLogoList);
  this->m_pLogoList->GetText_2(this: this->m_pLogoList, a2: this->m_LogoName, a3: 128);
  CCvarToggleCheckButton::ApplyChanges(this: this->m_pHighQualityModelCheckBox);
  for ( i = 0; i < this->m_cvarToggleCheckButtons.m_Size; ++i )
  {
    v3 = this->m_cvarToggleCheckButtons.m_Memory.m_pMemory[i];
    if ( v3->IsVisible(this: v3) && v3->IsEnabled(this: v3) )
      CCvarToggleCheckButton::ApplyChanges(this: v3);
  }
  v4 = ModInfo();
  if ( !CModInfo::NoCrosshair(this: v4) )
  {
    m_pCrosshairSize = this->m_pCrosshairSize;
    if ( m_pCrosshairSize != nullptr )
      CLabeledCommandComboBox::ApplyChanges(this: m_pCrosshairSize);
    m_pCrosshairTranslucencyCheckbox = this->m_pCrosshairTranslucencyCheckbox;
    if ( m_pCrosshairTranslucencyCheckbox != nullptr )
      CCvarToggleCheckButton::ApplyChanges(this: m_pCrosshairTranslucencyCheckbox);
    m_pCrosshairColorComboBox = this->m_pCrosshairColorComboBox;
    crosshair[0] = 0;
    if ( m_pCrosshairColorComboBox != nullptr )
    {
      ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pCrosshairColorComboBox);
      V_snprintf(pDest: crosshair, maxLen: 0x100u, pFormat: "cl_crosshaircolor %d\n", ActiveItem);
      engine->ClientCmd_Unrestricted(this: engine, a2: crosshair);
    }
  }
  v9 = ModInfo();
  if ( CModInfo::AdvCrosshair(this: v9) )
  {
    CCvarSlider::ApplyChanges(this: this->m_pAdvCrosshairRedSlider);
    CCvarSlider::ApplyChanges(this: this->m_pAdvCrosshairGreenSlider);
    CCvarSlider::ApplyChanges(this: this->m_pAdvCrosshairBlueSlider);
    CCvarSlider::ApplyChanges(this: this->m_pAdvCrosshairScaleSlider);
    CLabeledCommandComboBox::ApplyChanges(this: this->m_pAdvCrosshairStyle);
    this->m_pAdvCrosshairStyle->GetText_2(this: this->m_pAdvCrosshairStyle, a2: crosshair, a3: 256);
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "cl_crosshair_file %s\n", crosshair);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
  }
  if ( this->m_LogoName[0] != 0 )
    V_snprintf(pDest: cmd, maxLen: 0x200u, pFormat: "cl_logofile materials/vgui/logos/%s.vtf\n", this->m_LogoName);
  else
    V_strncpy(pDest: cmd, pSrc: "cl_logofile \"\"\n", maxLen: 512);
  engine->ClientCmd_Unrestricted(this: engine, a2: cmd);
  m_pModelList = this->m_pModelList;
  if ( m_pModelList != nullptr
    && m_pModelList->IsVisible(this: m_pModelList)
    && CLabeledCommandComboBox::GetActiveItemCommand(this: this->m_pModelList) != nullptr )
  {
    ActiveItemCommand = CLabeledCommandComboBox::GetActiveItemCommand(this: this->m_pModelList);
    V_strncpy(pDest: this->m_ModelName, pSrc: ActiveItemCommand, maxLen: 128);
    V_StripExtension(in: this->m_ModelName, out: this->m_ModelName, outSize: 128);
    V_snprintf(pDest: cmd, maxLen: 0x200u, pFormat: "cl_playermodel models/%s.mdl\n", this->m_ModelName);
    engine->ClientCmd_Unrestricted(this: engine, a2: cmd);
  }
  else
  {
    this->m_ModelName[0] = 0;
  }
  if ( this->m_pDownloadFilterCombo != nullptr )
  {
    ConVarRef::ConVarRef(this: &cl_downloadfilter, pName: "cl_downloadfilter");
    v12 = vgui::ComboBox::GetActiveItem(this: this->m_pDownloadFilterCombo) - 1;
    if ( v12 != 0 )
    {
      SetValue_4 = cl_downloadfilter.m_pConVar->SetValue_4;
      if ( v12 == 1 )
        ((void (__stdcall *)(const char *))SetValue_4)(a1: "none");
      else
        ((void (__stdcall *)(const char *))SetValue_4)(a1: "all");
    }
    else
    {
      cl_downloadfilter.m_pConVar->SetValue_4(this: cl_downloadfilter.m_pConVar, a2: "nosounds");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE620
// Name: private: enum ConversionErrorType COptionsSubMultiplayer::ConvertBMPToTGA(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsSubMultiplayer::ConvertBMPToTGA(
        COptionsSubMultiplayer *this,
        tagBITMAPINFO *bmpPath,
        const char *tgaPath)
{
  HBITMAP__ *ImageA; // ebx
  tagBITMAPINFO *v4; // edi
  HDC CompatibleDC; // esi
  int DIBits; // edi
  unsigned int v8; // edi
  unsigned __int8 *v9; // esi
  int biBitCount; // eax
  int bmWidth; // ecx
  int v12; // edi
  int v13; // ecx
  unsigned __int8 *v14; // eax
  int i; // edi
  unsigned __int8 v16; // cl
  int v17; // edi
  int v18; // edx
  int v19; // ecx
  int j; // edi
  int k; // ecx
  unsigned __int8 v22; // dl
  int v23; // eax
  int v24; // ebx
  int v25; // ecx
  int v26; // edi
  unsigned __int8 *v27; // edi
  unsigned __int8 v28; // bl
  unsigned int v29; // edi
  int v30; // ebx
  bool v31; // bl
  CUtlBuffer outBuf; // [esp+Ch] [ebp-5Ch] BYREF
  tagBITMAP bitmap; // [esp+3Ch] [ebp-2Ch] BYREF
  HBITMAP__ *hBitmap; // [esp+54h] [ebp-14h]
  int m; // [esp+5Ch] [ebp-Ch]
  int y; // [esp+60h] [ebp-8h]
  int bitMask; // [esp+64h] [ebp-4h]
  tagBITMAPINFO *bitmapInfo; // [esp+70h] [ebp+8h]
  unsigned __int8 *bitmapInfoa; // [esp+70h] [ebp+8h]

  ImageA = (HBITMAP__ *)LoadImageA(hInst: nullptr, name: (LPCSTR)bmpPath, type: 0, cx: 0, cy: 0, fuLoad: 0x2050u);
  hBitmap = ImageA;
  GetObjectA(h: ImageA, c: 24, pv: &bitmap);
  if ( bitmap.bmBitsPixel == 24 )
  {
    v4 = (tagBITMAPINFO *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
    bitmapInfo = v4;
  }
  else
  {
    bitmapInfo = (tagBITMAPINFO *)_g_pMemAlloc->Alloc_2(
                                    this: _g_pMemAlloc,
                                    a2: 4 * (1 << SLOBYTE(bitmap.bmBitsPixel)) + 44);
    v4 = bitmapInfo;
  }
  memset(dst: (int)v4, value: nullptr, count: sizeof(tagBITMAPINFO));
  v4->bmiHeader.biSize = 40;
  if ( bitmap.bmBitsPixel != 24 )
    v4->bmiHeader.biBitCount = bitmap.bmBitsPixel;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  DIBits = GetDIBits(
             hdc: CompatibleDC,
             hbm: ImageA,
             start: 0,
             cLines: bitmap.bmHeight,
             lpvBits: nullptr,
             lpbmi: v4,
             usage: 0);
  DeleteDC(hdc: CompatibleDC);
  if ( DIBits == 0 )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bitmapInfo);
    return 3;
  }
  v8 = 3 * bitmap.bmHeight * bitmap.bmWidth;
  v9 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v8);
  if ( v9 == nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bitmapInfo);
    return 1;
  }
  biBitCount = bitmapInfo->bmiHeader.biBitCount;
  switch ( biBitCount )
  {
    case 24:
      bmWidth = bitmap.bmWidth;
      if ( 3 * bitmap.bmWidth == bitmap.bmWidthBytes )
      {
        memcpy(dst: v9, src: (unsigned __int8 *)bitmap.bmBits, count: v8);
      }
      else
      {
        v12 = 0;
        if ( bitmap.bmHeight <= 0 )
          goto LABEL_18;
        while ( 1 )
        {
          memcpy(
            dst: &v9[2 * bmWidth * v12 + bmWidth * v12],
            src: (unsigned __int8 *)bitmap.bmBits + bitmap.bmWidthBytes * v12,
            count: 3 * bmWidth);
          if ( ++v12 >= bitmap.bmHeight )
            break;
          bmWidth = bitmap.bmWidth;
        }
      }
      bmWidth = bitmap.bmWidth;
LABEL_18:
      v13 = bitmap.bmHeight * bmWidth;
      if ( v13 > 0 )
      {
        v14 = v9;
        for ( i = v13; i != 0; --i )
        {
          v16 = *v14;
          *v14 = v14[2];
          v14[2] = v16;
          v14 += 3;
        }
      }
      break;
    case 8:
      v17 = 0;
      if ( bitmap.bmHeight > 0 )
      {
        v18 = bitmap.bmWidth;
        do
        {
          v19 = 0;
          if ( v18 > 0 )
          {
            do
            {
              y = (int)&bitmapInfo->bmiColors[*((unsigned __int8 *)bitmap.bmBits + v19 + bitmap.bmWidthBytes * v17)];
              v9[2 * v19 + 2 * v18 * v17 + v19 + v18 * v17] = *(_BYTE *)(y + 2);
              v9[2 * v19 + 1 + 2 * bitmap.bmWidth * v17 + v19 + bitmap.bmWidth * v17] = *(_BYTE *)(y + 1);
              v9[2 * v19 + 2 + 2 * bitmap.bmWidth * v17 + v19 + bitmap.bmWidth * v17] = *(_BYTE *)y;
              v18 = bitmap.bmWidth;
              ++v19;
            }
            while ( v19 < bitmap.bmWidth );
          }
          ++v17;
        }
        while ( v17 < bitmap.bmHeight );
      }
      break;
    case 4:
      for ( j = 0; j < bitmap.bmHeight; ++j )
      {
        for ( k = 0; k < bitmap.bmWidth; v9[2 * v23 + 5 + v23] = *(_BYTE *)bitMask )
        {
          bitMask = (int)&bitmapInfo->bmiColors[*((unsigned __int8 *)bitmap.bmBits + k / 2 + bitmap.bmWidthBytes * j) >> 4];
          v22 = *(_BYTE *)(bitMask + 2);
          y = k / 2 + bitmap.bmWidthBytes * j;
          v9[2 * k + 2 * bitmap.bmWidth * j + k + bitmap.bmWidth * j] = v22;
          v9[2 * k + 1 + 2 * bitmap.bmWidth * j + k + bitmap.bmWidth * j] = *(_BYTE *)(bitMask + 1);
          v9[2 * k + 2 + 2 * bitmap.bmWidth * j + k + bitmap.bmWidth * j] = *(_BYTE *)bitMask;
          if ( k + 1 > bitmap.bmWidth )
            break;
          bitMask = (int)&bitmapInfo->bmiColors[*((_BYTE *)bitmap.bmBits + y) & 0xF];
          v9[2 * bitmap.bmWidth * j + 3 + 2 * k + bitmap.bmWidth * j + k] = *(_BYTE *)(bitMask + 2);
          v9[2 * k + 4 + 2 * bitmap.bmWidth * j + k + bitmap.bmWidth * j] = *(_BYTE *)(bitMask + 1);
          v23 = k + bitmap.bmWidth * j;
          k += 2;
        }
      }
      break;
    case 1:
      v24 = 0;
      for ( y = 0; v24 < bitmap.bmHeight; y = v24 )
      {
        v25 = 0;
        if ( bitmap.bmWidth > 0 )
        {
LABEL_39:
          v26 = v25 / 8 + bitmap.bmWidthBytes * v24;
          bitMask = 128;
          for ( m = v26; ; v26 = m )
          {
            v27 = ((unsigned __int8)bitMask & *((_BYTE *)bitmap.bmBits + v26)) != 0
                ? (unsigned __int8 *)&bitmapInfo[1]
                : (unsigned __int8 *)bitmapInfo->bmiColors;
            v9[2 * v25 + 2 * bitmap.bmWidth * v24 + v25 + bitmap.bmWidth * v24] = v27[2];
            v28 = v27[1];
            bitMask >>= 1;
            v9[2 * v25 + 1 + 2 * bitmap.bmWidth * y + v25 + bitmap.bmWidth * y] = v28;
            v9[2 * v25 + 2 + 2 * bitmap.bmWidth * y + v25 + bitmap.bmWidth * y] = *v27;
            v24 = y;
            if ( ++v25 >= bitmap.bmWidth )
              break;
            if ( bitMask <= 0 )
              goto LABEL_39;
          }
        }
        ++v24;
      }
      break;
    default:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bitmapInfo);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      DeleteObject(ho: ImageA);
      return 4;
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bitmapInfo);
  v29 = 3 * bitmap.bmWidth;
  y = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3 * bitmap.bmWidth);
  v30 = 0;
  if ( bitmap.bmHeight / 2 > 0 )
  {
    bitmapInfoa = v9;
    do
    {
      memcpy(dst: (unsigned __int8 *)y, src: bitmapInfoa, count: v29);
      memcpy(dst: bitmapInfoa, src: &v9[v29 * (bitmap.bmHeight - v30 - 1)], count: v29);
      memcpy(dst: &v9[v29 * (bitmap.bmHeight - v30 - 1)], src: (unsigned __int8 *)y, count: v29);
      bitmapInfoa += v29;
      ++v30;
    }
    while ( v30 < bitmap.bmHeight / 2 );
  }
  CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
  v31 = TGAWriter::WriteToBuffer(
          pImageData: v9,
          buffer: &outBuf,
          width: bitmap.bmWidth,
          height: bitmap.bmHeight,
          srcFormat: IMAGE_FORMAT_RGB888,
          dstFormat: IMAGE_FORMAT_RGB888);
  if ( v31
    && !g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: tgaPath, a3: nullptr, a4: &outBuf) )
  {
    v31 = false;
  }
  DeleteObject(ho: hBitmap);
  if ( outBuf.m_Memory.m_nGrowSize >= 0 && outBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuf.m_Memory.m_pMemory);
  return v31 ? 0 : 5;
}

//------------------------------------------------------------------------------
// Address: 0x101DEB50
// Name: private: enum ConversionErrorType COptionsSubMultiplayer::ConvertTGAToVTF(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COptionsSubMultiplayer::ConvertTGAToVTF(COptionsSubMultiplayer *this, _iobuf *tgaPath)
{
  _iobuf *v2; // esi
  int v4; // edi
  unsigned int v5; // edi
  struct CSysModule *Module; // eax
  struct CSysModule *v7; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  int v9; // eax
  CUtlBuffer inbuf; // [esp+4h] [ebp-54h] BYREF
  TGAHeader header; // [esp+34h] [ebp-24h] BYREF
  char *vtfParams[4]; // [esp+48h] [ebp-10h] BYREF

  v2 = fopen(file: tgaPath, mode: "rb");
  if ( v2 == nullptr )
    return 2;
  ReadTGAHeader(infile: v2, &header);
  if ( ((header.width - 1) & header.width) != 0
    || ((header.height - 1) & header.height) != 0
    || header.width > 256
    || header.height > 256 )
  {
    fclose(stream: v2);
    return 4;
  }
  else
  {
    v4 = header.width * header.height * header.bits / 8;
    CUtlBuffer::CUtlBuffer(this: &inbuf, growSize: 0, initSize: v4, nFlags: 0);
    v5 = fread(buffer: inbuf.m_Memory.m_pMemory, elementSize: v4, count: 1u, stream: v2);
    fclose(stream: v2);
    CUtlBuffer::SeekPut(this: &inbuf, type: SEEK_HEAD, offset: v5);
    Module = (struct CSysModule *)Sys_LoadModule(pModuleName: "vtex_dll");
    v7 = Module;
    if ( Module == nullptr )
    {
LABEL_11:
      CUtlBuffer::~CUtlBuffer(this: &inbuf);
      return 6;
    }
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory == nullptr || (v9 = (int)Factory(a1: "VTEX_003", a2: nullptr)) == 0 )
    {
      Sys_UnloadModule(pModule: v7);
      goto LABEL_11;
    }
    vtfParams[3] = (char *)tgaPath;
    vtfParams[0] = (char *)prType;
    vtfParams[1] = "-quiet";
    vtfParams[2] = "-dontusegamedir";
    (*(void (__thiscall **)(int, int, char **))(*(_DWORD *)v9 + 4))(a1: v9, a2: 4, a3: vtfParams);
    Sys_UnloadModule(pModule: v7);
    CUtlBuffer::~CUtlBuffer(this: &inbuf);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DECB0
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubMultiplayer::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubMultiplayer::GetMessageMap(COptionsSubMultiplayer *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubMultiplayer::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubMultiplayer::GetMessageMap'::`2'::s_pMap;
  `COptionsSubMultiplayer::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubMultiplayer");
  `COptionsSubMultiplayer::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DECE0
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubMultiplayer::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubMultiplayer::GetAnimMap(COptionsSubMultiplayer *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubMultiplayer");
}

//------------------------------------------------------------------------------
// Address: 0x101DECF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubMultiplayer::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubMultiplayer::GetKBMap(COptionsSubMultiplayer *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubMultiplayer::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubMultiplayer::GetKBMap'::`2'::s_pMap;
  `COptionsSubMultiplayer::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubMultiplayer");
  `COptionsSubMultiplayer::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DED20
// Name: private: enum ConversionErrorType COptionsSubMultiplayer::ConvertJPEGToTGA(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge COptionsSubMultiplayer::ConvertJPEGToTGA@<eax>(
        COptionsSubMultiplayer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        _iobuf *jpegpath,
        const char *tgaPath)
{
  _iobuf *v7; // ebx
  unsigned int v8; // edi
  char *v9; // esi
  int v10; // ebx
  bool v11; // bl
  _EXCEPTION_REGISTRATION_RECORD *v12; // [esp-10h] [ebp-2D8h]
  int v13; // [esp-Ch] [ebp-2D4h]
  ValveJpegErrorHandler_t jerr; // [esp+Ch] [ebp-2BCh] BYREF
  jpeg_decompress_struct jpegInfo; // [esp+D0h] [ebp-1F8h] BYREF
  CUtlBuffer outBuf; // [esp+280h] [ebp-48h] BYREF
  int image_width; // [esp+2B0h] [ebp-18h]
  unsigned __int8 *row_pointer[1]; // [esp+2B4h] [ebp-14h] BYREF
  int image_height; // [esp+2B8h] [ebp-10h]
  int cur_row; // [esp+2BCh] [ebp-Ch]
  _iobuf *infile; // [esp+2C0h] [ebp-8h]
  bool working; // [esp+2C7h] [ebp-1h]
  int savedregs; // [esp+2C8h] [ebp+0h] BYREF

  cur_row = 0;
  infile = fopen(file: jpegpath, mode: "rb");
  if ( infile == nullptr )
    return 2;
  jpegInfo.err = jpeg_std_error(err: &jerr.m_Base);
  jpegInfo.err->error_exit = (void (__cdecl *)(jpeg_common_struct *))ValveJpegErrorHandler;
  jpeg_CreateDecompress(cinfo: (jpeg_common_struct *)&jpegInfo, version: 62, structsize: 0x1B0u);
  if ( _setjmp3(a1: a2, a2: (int)&savedregs, a3, a4, a5: jerr.m_ErrorContext, a6: 0, a7: v12, a8: v13) != 0 )
    goto LABEL_19;
  v7 = infile;
  jpeg_stdio_src(cinfo: (jpeg_common_struct *)&jpegInfo, infile);
  if ( jpeg_read_header(cinfo: (jpeg_common_struct *)&jpegInfo, require_image: 1u) != 1 )
  {
    fclose(stream: v7);
    return 3;
  }
  if ( jpeg_start_decompress(cinfo: &jpegInfo) != 1 )
  {
    jpeg_destroy_decompress(cinfo: (jpeg_common_struct *)&jpegInfo);
    fclose(stream: v7);
    return 3;
  }
  if ( ((jpegInfo.image_height - 1) & jpegInfo.image_height) != 0
    || ((jpegInfo.image_width - 1) & jpegInfo.image_width) != 0 )
  {
    jpeg_destroy_decompress(cinfo: (jpeg_common_struct *)&jpegInfo);
    fclose(stream: v7);
    return 4;
  }
  else
  {
    v8 = jpegInfo.output_width * jpegInfo.output_components;
    image_height = jpegInfo.image_height;
    image_width = jpegInfo.image_width;
    v9 = (char *)MemAlloc_Alloc(nSize: jpegInfo.image_height * jpegInfo.image_width * jpegInfo.output_components);
    if ( v9 == nullptr )
    {
      jpeg_destroy_decompress(cinfo: (jpeg_common_struct *)&jpegInfo);
      fclose(stream: v7);
      return 1;
    }
    v10 = cur_row;
    working = true;
    do
    {
      if ( jpegInfo.output_scanline >= jpegInfo.output_height )
        break;
      row_pointer[0] = (unsigned __int8 *)&v9[v10 * v8];
      if ( jpeg_read_scanlines(cinfo: (unsigned int)&jpegInfo, scanlines: row_pointer, max_lines: 1u) != 1 )
        working = false;
      cur_row = ++v10;
    }
    while ( working );
    if ( !working )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
LABEL_19:
      jpeg_destroy_decompress(cinfo: (jpeg_common_struct *)&jpegInfo);
      fclose(stream: infile);
      return 3;
    }
    jpeg_finish_decompress(cinfo: (jpeg_common_struct *)&jpegInfo);
    fclose(stream: infile);
    CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
    v11 = TGAWriter::WriteToBuffer(
            pImageData: (unsigned __int8 *)v9,
            buffer: &outBuf,
            width: image_width,
            height: image_height,
            srcFormat: IMAGE_FORMAT_RGB888,
            dstFormat: IMAGE_FORMAT_RGB888);
    if ( v11
      && !g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: tgaPath, a3: nullptr, a4: &outBuf) )
    {
      v11 = false;
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
    CUtlBuffer::~CUtlBuffer(this: &outBuf);
    return v11 ? 0 : 5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DEFC0
// Name: public: static void COptionsSubMultiplayer::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubMultiplayer::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubMultiplayer::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COptionsSubMultiplayer::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubMultiplayer");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF060
// Name: public: static void COptionsSubMultiplayer::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubMultiplayer::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubMultiplayer::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `COptionsSubMultiplayer::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubMultiplayer");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF0F0
// Name: public: static void COptionsSubMultiplayer::PanelMessageFunc_OnApplyButtonEnable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubMultiplayer::PanelMessageFunc_OnApplyButtonEnable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubMultiplayer::PanelMessageFunc_OnApplyButtonEnable::InitVar'::`2'::bAdded )
  {
    `COptionsSubMultiplayer::PanelMessageFunc_OnApplyButtonEnable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubMultiplayer");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF180
// Name: public: static void COptionsSubMultiplayer::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubMultiplayer::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsSubMultiplayer::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `COptionsSubMultiplayer::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubMultiplayer");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "fullpath";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF220
// Name: public: COptionsSubMultiplayer::COptionsSubMultiplayer(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubMultiplayer *__thiscall COptionsSubMultiplayer::COptionsSubMultiplayer(
        COptionsSubMultiplayer *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  CCvarSlider *v16; // eax
  CCvarSlider *v17; // eax
  CCvarSlider *v18; // eax
  CCvarSlider *v19; // eax
  CCvarToggleCheckButton *v20; // eax
  CCvarToggleCheckButton *v21; // eax
  CLabeledCommandComboBox *v22; // eax
  CLabeledCommandComboBox *v23; // edi
  void (__thiscall *DeleteAllItems)(CLabeledCommandComboBox *); // eax
  CLabeledCommandComboBox *v25; // eax
  CLabeledCommandComboBox *v26; // eax
  CBitmapImagePanel *v27; // eax
  CBitmapImagePanel *v28; // eax
  vgui::ImagePanel *v29; // eax
  vgui::ImagePanel *v30; // eax
  vgui::ComboBox *v31; // eax
  vgui::ComboBox *v32; // eax
  CLabeledCommandComboBox *v33; // eax
  CLabeledCommandComboBox *v34; // eax
  CCvarToggleCheckButton *v35; // eax
  CCvarToggleCheckButton *v36; // eax
  CrosshairImagePanel *v37; // eax
  CrosshairImagePanel *v38; // eax
  CCvarSlider *v39; // eax
  CCvarSlider *v40; // eax
  CCvarSlider *v41; // eax
  CCvarSlider *v42; // eax
  CCvarSlider *v43; // eax
  CCvarSlider *v44; // eax
  CCvarSlider *v45; // eax
  CCvarSlider *v46; // eax
  CCvarSlider *m_pAdvCrosshairRedSlider; // ecx
  CLabeledCommandComboBox *v48; // eax
  CLabeledCommandComboBox *v49; // eax
  AdvancedCrosshairImagePanel *v50; // eax
  AdvancedCrosshairImagePanel *v51; // eax
  vgui::ComboBox *v52; // eax
  vgui::ComboBox *v53; // eax
  CModInfo *v54; // eax
  vgui::Panel *ChildByName; // eax
  CModInfo *v56; // eax
  CBitmapImagePanel *m_pModelImage; // ecx
  CLabeledCommandComboBox *m_pModelList; // ecx
  CCvarSlider *m_pPrimaryColorSlider; // ecx
  CCvarSlider *m_pSecondaryColorSlider; // ecx
  vgui::Panel *v61; // eax
  vgui::Panel *v62; // eax
  CModInfo *v63; // eax
  CCvarToggleCheckButton *m_pHighQualityModelCheckBox; // ecx
  CModInfo *v65; // eax
  vgui::Panel *v66; // eax
  CLabeledCommandComboBox *m_pAdvCrosshairStyle; // [esp+28h] [ebp-14h]
  int iCount; // [esp+38h] [ebp-4h] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: "OptionsSubMultiplayer");
  this->__vftable = (COptionsSubMultiplayer_vtbl *)&COptionsSubMultiplayer::`vftable';
  if ( `COptionsSubMultiplayer::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubMultiplayer::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubMultiplayer");
    v3->pfnClassName = COptionsSubMultiplayer::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubMultiplayer::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubMultiplayer::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubMultiplayer");
    v4->pfnClassName = COptionsSubMultiplayer::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubMultiplayer::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubMultiplayer::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubMultiplayer");
    v5->pfnClassName = COptionsSubMultiplayer::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubMultiplayer::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  COptionsSubMultiplayer::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  COptionsSubMultiplayer::PanelMessageFunc_OnApplyButtonEnable::InitVar();
  COptionsSubMultiplayer::PanelMessageFunc_OnFileSelected::InitVar();
  this->m_cvarToggleCheckButtons.m_Memory.m_pMemory = nullptr;
  this->m_cvarToggleCheckButtons.m_Memory.m_nAllocationCount = 0;
  this->m_cvarToggleCheckButtons.m_Memory.m_nGrowSize = 0;
  this->m_cvarToggleCheckButtons.m_Size = 0;
  this->m_cvarToggleCheckButtons.m_pElements = nullptr;
  this->m_hMultiplayerAdvancedDialog.m_iPanelID = -1;
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "Cancel",
           text: "#GameUI_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  v7->SetCommand(this: v7, a2: "Close");
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "OK",
           text: "#GameUI_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  v9->SetCommand(this: v9, a2: "Ok");
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "Apply",
            text: "#GameUI_Apply",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  v11->SetCommand(this: v11, a2: "Apply");
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "Advanced",
            text: "#GameUI_AdvancedEllipsis",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  v13->SetCommand(this: v13, a2: "Advanced");
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "ImportSprayImage",
            text: "#GameUI_ImportSprayEllipsis",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  v15->SetCommand(this: v15, a2: "ImportSprayImage");
  this->m_hImportSprayDialog = nullptr;
  v16 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v16 != nullptr )
    v17 = CCvarSlider::CCvarSlider(
            this: v16,
            parent: this,
            panelName: "Primary Color Slider",
            caption: "#GameUI_PrimaryColor",
            minValue: 0.0,
            maxValue: 255.0,
            cvarname: "topcolor",
            bAllowOutOfRange: false);
  else
    v17 = nullptr;
  this->m_pPrimaryColorSlider = v17;
  v18 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = CCvarSlider::CCvarSlider(
            this: v18,
            parent: this,
            panelName: "Secondary Color Slider",
            caption: "#GameUI_SecondaryColor",
            minValue: 0.0,
            maxValue: 255.0,
            cvarname: "bottomcolor",
            bAllowOutOfRange: false);
  else
    v19 = nullptr;
  this->m_pSecondaryColorSlider = v19;
  v20 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v20 != nullptr )
    v21 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v20,
            parent: this,
            panelName: "High Quality Models",
            text: "#GameUI_HighModels",
            cvarname: "cl_himodels");
  else
    v21 = nullptr;
  this->m_pHighQualityModelCheckBox = v21;
  v22 = (CLabeledCommandComboBox *)MemAlloc_Alloc(nSize: 0x478u);
  if ( v22 != nullptr )
    v23 = CLabeledCommandComboBox::CLabeledCommandComboBox(this: v22, parent: this, panelName: "Player model");
  else
    v23 = nullptr;
  this->m_pModelList = v23;
  this->m_ModelName[0] = 0;
  DeleteAllItems = v23->DeleteAllItems;
  iCount = 0;
  parent = nullptr;
  DeleteAllItems(this: v23);
  FindVMTFilesInFolder(
    pFolder: "materials/vgui/playermodels/",
    pFolderName: prType,
    cb: v23,
    &iCount,
    iInitialItem: (int *)&parent);
  CLabeledCommandComboBox::SetInitialItem(this: v23, index: (int)parent);
  v25 = (CLabeledCommandComboBox *)MemAlloc_Alloc(nSize: 0x478u);
  if ( v25 != nullptr )
    v26 = CLabeledCommandComboBox::CLabeledCommandComboBox(this: v25, parent: this, panelName: "SpraypaintList");
  else
    v26 = nullptr;
  this->m_pLogoList = v26;
  this->m_LogoName[0] = 0;
  COptionsSubMultiplayer::InitLogoList(this, a2: (int)v23, cb: v26);
  v27 = (CBitmapImagePanel *)MemAlloc_Alloc(nSize: 0x1D4u);
  if ( v27 != nullptr )
    v28 = CBitmapImagePanel::CBitmapImagePanel(this: v27, parent: this, panelName: "ModelImage", filename: nullptr);
  else
    v28 = nullptr;
  this->m_pModelImage = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  v29 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v29 != nullptr )
    v30 = vgui::ImagePanel::ImagePanel(this: v29, parent: this, name: "LogoImage");
  else
    v30 = nullptr;
  this->m_pLogoImage = v30;
  v30->AddActionSignalTarget_2(this: v30, a2: this);
  this->m_nTopColor = 30;
  this->m_nBottomColor = 6;
  this->m_nLogoR = 255;
  this->m_nLogoG = 255;
  this->m_nLogoB = 255;
  v31 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v31 != nullptr )
    v32 = vgui::ComboBox::ComboBox(
            this: v31,
            parent: this,
            panelName: "CrosshairColorComboBox",
            numLines: 6,
            allowEdit: false);
  else
    v32 = nullptr;
  this->m_pCrosshairColorComboBox = v32;
  v33 = (CLabeledCommandComboBox *)MemAlloc_Alloc(nSize: 0x478u);
  if ( v33 != nullptr )
    v34 = CLabeledCommandComboBox::CLabeledCommandComboBox(this: v33, parent: this, panelName: "CrosshairSizeComboBox");
  else
    v34 = nullptr;
  this->m_pCrosshairSize = v34;
  v35 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v35 != nullptr )
    v36 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v35,
            parent: this,
            panelName: "CrosshairTranslucencyCheckbox",
            text: "#GameUI_Translucent",
            cvarname: "cl_crosshairusealpha");
  else
    v36 = nullptr;
  this->m_pCrosshairTranslucencyCheckbox = v36;
  v37 = (CrosshairImagePanel *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v37 != nullptr )
    v38 = CrosshairImagePanel::CrosshairImagePanel(
            this: v37,
            parent: this,
            name: "CrosshairImage",
            pAdditive: this->m_pCrosshairTranslucencyCheckbox);
  else
    v38 = nullptr;
  this->m_pCrosshairImage = v38;
  v39 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v39 != nullptr )
    v40 = CCvarSlider::CCvarSlider(
            this: v39,
            parent: this,
            panelName: "Red Color Slider",
            caption: "#GameUI_CrosshairColor_Red",
            minValue: 0.0,
            maxValue: 255.0,
            cvarname: "cl_crosshair_red",
            bAllowOutOfRange: false);
  else
    v40 = nullptr;
  this->m_pAdvCrosshairRedSlider = v40;
  v41 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v41 != nullptr )
    v42 = CCvarSlider::CCvarSlider(
            this: v41,
            parent: this,
            panelName: "Green Color Slider",
            caption: "#GameUI_CrosshairColor_Green",
            minValue: 0.0,
            maxValue: 255.0,
            cvarname: "cl_crosshair_green",
            bAllowOutOfRange: false);
  else
    v42 = nullptr;
  this->m_pAdvCrosshairGreenSlider = v42;
  v43 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v43 != nullptr )
    v44 = CCvarSlider::CCvarSlider(
            this: v43,
            parent: this,
            panelName: "Blue Color Slider",
            caption: "#GameUI_CrosshairColor_Blue",
            minValue: 0.0,
            maxValue: 255.0,
            cvarname: "cl_crosshair_blue",
            bAllowOutOfRange: false);
  else
    v44 = nullptr;
  this->m_pAdvCrosshairBlueSlider = v44;
  v45 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v45 != nullptr )
    v46 = CCvarSlider::CCvarSlider(
            this: v45,
            parent: this,
            panelName: "Scale Slider",
            caption: "#GameUI_CrosshairScale",
            minValue: 16.0,
            maxValue: 48.0,
            cvarname: "cl_crosshair_scale",
            bAllowOutOfRange: false);
  else
    v46 = nullptr;
  m_pAdvCrosshairRedSlider = this->m_pAdvCrosshairRedSlider;
  this->m_pAdvCrosshairScaleSlider = v46;
  m_pAdvCrosshairRedSlider->AddActionSignalTarget_2(this: m_pAdvCrosshairRedSlider, a2: this);
  this->m_pAdvCrosshairGreenSlider->AddActionSignalTarget_2(this: this->m_pAdvCrosshairGreenSlider, a2: this);
  this->m_pAdvCrosshairBlueSlider->AddActionSignalTarget_2(this: this->m_pAdvCrosshairBlueSlider, a2: this);
  this->m_pAdvCrosshairScaleSlider->AddActionSignalTarget_2(this: this->m_pAdvCrosshairScaleSlider, a2: this);
  v48 = (CLabeledCommandComboBox *)MemAlloc_Alloc(nSize: 0x478u);
  if ( v48 != nullptr )
    v49 = CLabeledCommandComboBox::CLabeledCommandComboBox(this: v48, parent: this, panelName: "AdvCrosshairList");
  else
    v49 = nullptr;
  this->m_pAdvCrosshairStyle = v49;
  v50 = (AdvancedCrosshairImagePanel *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v50 != nullptr )
    v51 = AdvancedCrosshairImagePanel::AdvancedCrosshairImagePanel(this: v50, parent: this, name: "AdvCrosshairImage");
  else
    v51 = nullptr;
  m_pAdvCrosshairStyle = this->m_pAdvCrosshairStyle;
  this->m_pAdvCrosshairImage = v51;
  COptionsSubMultiplayer::InitAdvCrosshairStyleList(this, a2: (int)v23, cb: m_pAdvCrosshairStyle);
  COptionsSubMultiplayer::RedrawAdvCrosshairImage(this);
  v52 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v52 != nullptr )
    v53 = vgui::ComboBox::ComboBox(
            this: v52,
            parent: this,
            panelName: "DownloadFilterCheck",
            numLines: 3,
            allowEdit: false);
  else
    v53 = nullptr;
  this->m_pDownloadFilterCombo = v53;
  v53->AddItem_2(this: v53, a2: "#GameUI_DownloadFilter_ALL", a3: nullptr);
  this->m_pDownloadFilterCombo->AddItem_2(
    this: this->m_pDownloadFilterCombo,
    a2: "#GameUI_DownloadFilter_NoSounds",
    a3: nullptr);
  this->m_pDownloadFilterCombo->AddItem_2(
    this: this->m_pDownloadFilterCombo,
    a2: "#GameUI_DownloadFilter_None",
    a3: nullptr);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/OptionsSubMultiplayer.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  COptionsSubMultiplayer::InitCrosshairColorEntries(this);
  COptionsSubMultiplayer::InitCrosshairSizeList(this, cb: this->m_pCrosshairSize);
  COptionsSubMultiplayer::RedrawCrosshairImage(this);
  v54 = ModInfo();
  if ( CModInfo::NoCrosshair(this: v54) )
  {
    this->m_pCrosshairColorComboBox->SetVisible(this: this->m_pCrosshairColorComboBox, a2: false);
    this->m_pCrosshairSize->SetVisible(this: this->m_pCrosshairSize, a2: false);
    this->m_pCrosshairTranslucencyCheckbox->SetVisible(this: this->m_pCrosshairTranslucencyCheckbox, a2: false);
    this->m_pCrosshairImage->SetVisible(this: this->m_pCrosshairImage, a2: false);
    ChildByName = vgui::Panel::FindChildByName(this, childName: "CrosshairLabel", recurseDown: false);
    if ( ChildByName != nullptr )
      ChildByName->SetVisible(this: ChildByName, a2: false);
  }
  v56 = ModInfo();
  if ( CModInfo::NoModels(this: v56) )
  {
    m_pModelImage = this->m_pModelImage;
    if ( m_pModelImage != nullptr )
      m_pModelImage->SetVisible(this: m_pModelImage, a2: false);
    m_pModelList = this->m_pModelList;
    if ( m_pModelList != nullptr )
      m_pModelList->SetVisible(this: m_pModelList, a2: false);
    m_pPrimaryColorSlider = this->m_pPrimaryColorSlider;
    if ( m_pPrimaryColorSlider != nullptr )
      m_pPrimaryColorSlider->SetVisible(this: m_pPrimaryColorSlider, a2: false);
    m_pSecondaryColorSlider = this->m_pSecondaryColorSlider;
    if ( m_pSecondaryColorSlider != nullptr )
      m_pSecondaryColorSlider->SetVisible(this: m_pSecondaryColorSlider, a2: false);
    v61 = vgui::Panel::FindChildByName(this, childName: "Label1", recurseDown: false);
    if ( v61 != nullptr )
      v61->SetVisible(this: v61, a2: false);
    v62 = vgui::Panel::FindChildByName(this, childName: "Colors", recurseDown: false);
    if ( v62 != nullptr )
      v62->SetVisible(this: v62, a2: false);
  }
  v63 = ModInfo();
  if ( CModInfo::NoHiModel(this: v63) )
  {
    m_pHighQualityModelCheckBox = this->m_pHighQualityModelCheckBox;
    if ( m_pHighQualityModelCheckBox != nullptr )
      m_pHighQualityModelCheckBox->SetVisible(this: m_pHighQualityModelCheckBox, a2: false);
  }
  v65 = ModInfo();
  if ( !CModInfo::AdvCrosshair(this: v65) )
  {
    this->m_pAdvCrosshairImage->SetVisible(this: this->m_pAdvCrosshairImage, a2: false);
    this->m_pAdvCrosshairRedSlider->SetVisible(this: this->m_pAdvCrosshairRedSlider, a2: false);
    this->m_pAdvCrosshairBlueSlider->SetVisible(this: this->m_pAdvCrosshairBlueSlider, a2: false);
    this->m_pAdvCrosshairGreenSlider->SetVisible(this: this->m_pAdvCrosshairGreenSlider, a2: false);
    this->m_pAdvCrosshairScaleSlider->SetVisible(this: this->m_pAdvCrosshairScaleSlider, a2: false);
    this->m_pAdvCrosshairStyle->SetVisible(this: this->m_pAdvCrosshairStyle, a2: false);
    v66 = vgui::Panel::FindChildByName(this, childName: "AdvCrosshairLabel", recurseDown: false);
    if ( v66 != nullptr )
      v66->SetVisible(this: v66, a2: false);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DFB80
// Name: private: virtual void COptionsSubMultiplayer::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COptionsSubMultiplayer::OnFileSelected(
        COptionsSubMultiplayer *this@<ecx>,
        int a2@<esi>,
        char *fullpath)
{
  char *i; // eax
  char *j; // eax
  char v6; // cl
  int v7; // esi
  int v8; // eax
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // eax
  vgui::MessageBox *v11; // eax
  vgui::MessageBox *v12; // eax
  vgui::MessageBox *v13; // eax
  vgui::MessageBox *v14; // eax
  int v15; // eax
  vgui::MessageBox *v16; // eax
  COptionsSubMultiplayer *v17; // esi
  vgui::MessageBox *v18; // eax
  int v19; // eax
  vgui::MessageBox *v20; // eax
  char *k; // eax
  unsigned int v22; // eax
  char *m; // esi
  char v24; // al
  char *v25; // eax
  char *n; // eax
  COptionsSubMultiplayer *v27; // edi
  vgui::MessageBox *v28; // eax
  vgui::MessageBox *v29; // eax
  char *ii; // eax
  char rootFilename[260]; // [esp+8h] [ebp-92Ch] BYREF
  char pDest[260]; // [esp+10Ch] [ebp-828h] BYREF
  char finalPath[520]; // [esp+210h] [ebp-724h] BYREF
  char extension[260]; // [esp+418h] [ebp-51Ch] BYREF
  char tgaPath[520]; // [esp+51Ch] [ebp-418h] BYREF
  char vtfPath[520]; // [esp+724h] [ebp-210h] BYREF
  COptionsSubMultiplayer *v38; // [esp+92Ch] [ebp-8h] BYREF
  bool deleteIntermediateVTF; // [esp+932h] [ebp-2h]
  bool deleteIntermediateTGA; // [esp+933h] [ebp-1h]
  char failed_3; // [esp+93Fh] [ebp+Bh]

  v38 = this;
  if ( fullpath == nullptr || *fullpath == 0 )
    return;
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 4u);
  for ( i = &fullpath[strlen(fullpath)]; i > fullpath; --i )
  {
    if ( *(i - 1) == 46 )
      break;
  }
  V_strncpy(pDest: extension, pSrc: i, maxLen: 260);
  deleteIntermediateTGA = false;
  deleteIntermediateVTF = false;
  failed_3 = 0;
  V_strncpy(pDest: tgaPath, pSrc: fullpath, maxLen: 520);
  if ( _V_stricmp(s1: extension, s2: "tga") != 0 )
  {
    for ( j = &tgaPath[strlen(tgaPath)]; j > tgaPath; --j )
    {
      v6 = *(j - 1);
      if ( v6 == 92 )
        break;
      if ( v6 == 47 )
        break;
    }
    *j = 0;
    V_strncpy(pDest: rootFilename, pSrc: tgaPath, maxLen: 520);
    v7 = 0;
    do
      V_snprintf(pDest: tgaPath, maxLen: 0x208u, pFormat: "%stemp%d.tga", rootFilename, v7++);
    while ( _access(path: tgaPath, amode: 0) != -1 );
    if ( _V_stricmp(s1: extension, s2: "jpg") != 0 && _V_stricmp(s1: extension, s2: "jpeg") != 0 )
    {
      if ( _V_stricmp(s1: extension, s2: "bmp") != 0 )
      {
        if ( _V_stricmp(s1: extension, s2: "vtf") == 0 )
          goto LABEL_62;
        goto LABEL_43;
      }
      v8 = COptionsSubMultiplayer::ConvertBMPToTGA(this: v38, bmpPath: (tagBITMAPINFO *)fullpath, tgaPath);
      if ( v8 != 0 )
      {
        failed_3 = 1;
        switch ( v8 )
        {
          case 1:
            goto LABEL_18;
          case 2:
            goto LABEL_21;
          case 3:
LABEL_24:
            v12 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
            if ( v12 == nullptr )
              goto LABEL_62;
            v10 = vgui::MessageBox::MessageBox(
                    this: v12,
                    title: "#GameUI_Spray_Import_Error_Title",
                    text: "#GameUI_Spray_Import_Error_Image_File_Corrupt",
                    parent: nullptr);
            goto LABEL_60;
          case 4:
            v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
            if ( v13 == nullptr )
              goto LABEL_62;
            v10 = vgui::MessageBox::MessageBox(
                    this: v13,
                    title: "#GameUI_Spray_Import_Error_Title",
                    text: "#GameUI_Spray_Import_Error_BMP_Format_Not_Supported",
                    parent: nullptr);
            goto LABEL_60;
          default:
            break;
        }
        goto LABEL_29;
      }
    }
    else
    {
      v15 = COptionsSubMultiplayer::ConvertJPEGToTGA(
              this: v38,
              a2: 0,
              a3: (int)fullpath,
              a4: v7,
              jpegpath: (_iobuf *)fullpath,
              tgaPath);
      if ( v15 != 0 )
      {
        failed_3 = 1;
        if ( v15 != 1 )
        {
          if ( v15 != 2 )
          {
            if ( v15 == 3 )
              goto LABEL_24;
            if ( v15 != 5 )
            {
              if ( v15 != 4 )
                goto LABEL_62;
              v16 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
              if ( v16 == nullptr )
                goto LABEL_62;
              v10 = vgui::MessageBox::MessageBox(
                      this: v16,
                      title: "#GameUI_Spray_Import_Error_Title",
                      text: "#GameUI_Spray_Import_Image_Wrong_Size",
                      parent: nullptr);
              goto LABEL_60;
            }
LABEL_30:
            v14 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
            if ( v14 == nullptr )
              goto LABEL_62;
            v10 = vgui::MessageBox::MessageBox(
                    this: v14,
                    title: "#GameUI_Spray_Import_Error_Title",
                    text: "#GameUI_Spray_Import_Error_Writing_Temp_Output",
                    parent: nullptr);
            goto LABEL_60;
          }
          goto LABEL_21;
        }
        goto LABEL_18;
      }
    }
    deleteIntermediateTGA = true;
  }
LABEL_43:
  v17 = v38;
  v8 = COptionsSubMultiplayer::ConvertTGA(this: v38, a2: 0, tgaPath);
  if ( v8 == 0 )
  {
    V_strncpy(pDest: rootFilename, pSrc: tgaPath, maxLen: 520);
    v19 = COptionsSubMultiplayer::ConvertTGAToVTF(this: v17, tgaPath: (_iobuf *)rootFilename);
    if ( v19 == 0 )
    {
      deleteIntermediateVTF = true;
      goto LABEL_62;
    }
    failed_3 = 1;
    if ( v19 == 1 )
      goto LABEL_18;
    if ( v19 != 2 )
    {
      if ( v19 == 3 )
        goto LABEL_24;
      if ( v19 != 4 )
      {
        if ( v19 != 5 )
        {
          if ( v19 != 6 )
            goto LABEL_62;
          v20 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
          if ( v20 == nullptr )
            goto LABEL_62;
          v10 = vgui::MessageBox::MessageBox(
                  this: v20,
                  title: "#GameUI_Spray_Import_Error_Title",
                  text: "#GameUI_Spray_Import_Error_Cant_Load_VTEX_DLL",
                  parent: nullptr);
          goto LABEL_60;
        }
        goto LABEL_30;
      }
      goto LABEL_48;
    }
LABEL_21:
    v11 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v11 == nullptr )
      goto LABEL_62;
    v10 = vgui::MessageBox::MessageBox(
            this: v11,
            title: "#GameUI_Spray_Import_Error_Title",
            text: "#GameUI_Spray_Import_Error_Reading_Image",
            parent: nullptr);
LABEL_60:
    if ( v10 != nullptr )
      v10->DoModal_2(this: v10, a2: nullptr);
    goto LABEL_62;
  }
  failed_3 = 1;
  if ( v8 != 1 )
  {
    if ( v8 != 2 )
    {
      if ( v8 == 3 )
        goto LABEL_24;
      if ( v8 != 4 )
      {
LABEL_29:
        if ( v8 != 5 )
          goto LABEL_62;
        goto LABEL_30;
      }
LABEL_48:
      v18 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v18 == nullptr )
        goto LABEL_62;
      v10 = vgui::MessageBox::MessageBox(
              this: v18,
              title: "#GameUI_Spray_Import_Error_Title",
              text: "#GameUI_Spray_Import_Error_TGA_Format_Not_Supported",
              parent: nullptr);
      goto LABEL_60;
    }
    goto LABEL_21;
  }
LABEL_18:
  v9 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v9 != nullptr )
  {
    v10 = vgui::MessageBox::MessageBox(
            this: v9,
            title: "#GameUI_Spray_Import_Error_Title",
            text: "#GameUI_Spray_Import_Error_Memory",
            parent: nullptr);
    goto LABEL_60;
  }
LABEL_62:
  finalPath[0] = 0;
  vtfPath[0] = 0;
  if ( failed_3 == 0 )
  {
    V_strncpy(pDest: vtfPath, pSrc: tgaPath, maxLen: 520);
    for ( k = &vtfPath[strlen(vtfPath)]; k > vtfPath; --k )
    {
      if ( *(k - 1) == 46 )
        break;
    }
    *k = 0;
    V_strncat(pDest: vtfPath, pSrc: "vtf", destBufferSize: 0x208u, max_chars_to_copy: -1);
    v22 = strlen(fullpath);
    for ( m = &fullpath[v22]; m > fullpath; --m )
    {
      v24 = *(m - 1);
      if ( v24 == 92 )
        break;
      if ( v24 == 47 )
        break;
    }
    v25 = (char *)((int (__thiscall *)(IVEngineClient *, int))engine->GetGameDirectory)(a1: engine, a2: 520);
    V_strncpy(pDest: finalPath, pSrc: v25, maxLen: a2);
    V_strncat(pDest: finalPath, pSrc: "\\materials\\VGUI\\logos\\", destBufferSize: 0x208u, max_chars_to_copy: -1);
    V_strncat(pDest: finalPath, pSrc: m, destBufferSize: 0x208u, max_chars_to_copy: -1);
    for ( n = &finalPath[strlen(finalPath)]; n > finalPath; --n )
    {
      if ( *(n - 1) == 46 )
        break;
    }
    *n = 0;
    V_strncat(pDest: finalPath, pSrc: "vtf", destBufferSize: 0x208u, max_chars_to_copy: -1);
    ((void (__thiscall *)(IFileSystem *, const char *))g_pFullFileSystem->CreateDirHierarchy)(
      a1: g_pFullFileSystem,
      a2: "materials/VGUI/logos/");
    v27 = v38;
    if ( COptionsSubMultiplayer::WriteSprayVMT(this: v38, vtfPath: finalPath) != 0 )
    {
      v28 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v28 != nullptr )
      {
        v29 = vgui::MessageBox::MessageBox(
                this: v28,
                title: "#GameUI_Spray_Import_Error_Title",
                text: "#GameUI_Spray_Import_Error_Writing_Output",
                parent: nullptr);
        v29->DoModal_2(this: v29, a2: nullptr);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
      }
    }
    else
    {
      CopyFileA(lpExistingFileName: vtfPath, lpNewFileName: finalPath, bFailIfExists: true);
      COptionsSubMultiplayer::InitLogoList(this: v27, a2: (int)v27, cb: v27->m_pLogoList);
      V_strncpy(pDest, pSrc: m, maxLen: 260);
      rootFilename[strlen(pDest) + 256] = 0;
      COptionsSubMultiplayer::SelectLogo(this: v27, logoName: pDest);
    }
  }
  if ( deleteIntermediateVTF )
  {
    DeleteFileA(lpFileName: vtfPath);
    for ( ii = &vtfPath[strlen(vtfPath)]; ii > vtfPath; --ii )
    {
      if ( *(ii - 1) == 46 )
        break;
    }
    V_strncpy(pDest: ii, pSrc: "txt", maxLen: (char *)&v38 - ii);
    DeleteFileA(lpFileName: vtfPath);
  }
  if ( deleteIntermediateTGA )
    DeleteFileA(lpFileName: tgaPath);
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101E0220
// Name: public: virtual class vgui::Panel __near * COptionsSubMultiplayer::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCvarToggleCheckButton *__thiscall COptionsSubMultiplayer::CreateControlByName(
        COptionsSubMultiplayer *this,
        const char *controlName)
{
  CCvarToggleCheckButton *v3; // eax
  CCvarToggleCheckButton *v4; // esi

  if ( _V_stricmp(s1: "CCvarToggleCheckButton", s2: controlName) != 0 )
    return (CCvarToggleCheckButton *)vgui::EditablePanel::CreateControlByName(this, controlName);
  v3 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v3 != nullptr )
  {
    v4 = CCvarToggleCheckButton::CCvarToggleCheckButton(
           this: v3,
           parent: this,
           panelName: controlName,
           text: prType,
           cvarname: prType);
    vgui::Dar<unsigned long>::AddElement(
      this: (vgui::Dar<unsigned long> *)&this->m_cvarToggleCheckButtons,
      elem: (unsigned int)v4);
    return v4;
  }
  else
  {
    vgui::Dar<unsigned long>::AddElement(this: (vgui::Dar<unsigned long> *)&this->m_cvarToggleCheckButtons, elem: 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BC360
// Name: public: virtual class vgui::IImage __near * vgui::ImagePanel::GetImage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::TreeView *__thiscall vgui::ImagePanel::GetImage(vgui::CTreeViewListControl *this)
{
  return this->m_pTree;
}

//------------------------------------------------------------------------------
// Address: 0x10418690
// Name: _dynamic_initializer_for__option_duck_method_default__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__option_duck_method_default__()
{
  ConVar::ConVar(this: &option_duck_method_default, pName: "option_duck_method_default", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__option_duck_method_default__);
}

//------------------------------------------------------------------------------
// Address: 0x104186C0
// Name: _dynamic_initializer_for__option_speed_method_default__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__option_speed_method_default__()
{
  ConVar::ConVar(
    this: &option_speed_method_default,
    pName: "option_speed_method_default",
    pDefaultValue: "1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__option_speed_method_default__);
}

//------------------------------------------------------------------------------
// Address: 0x10418C60
// Name: _dynamic_initializer_for__option_duck_method__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__option_duck_method__()
{
  ConVar::ConVar(this: &option_duck_method, pName: "option_duck_method", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__option_duck_method__);
}

//------------------------------------------------------------------------------
// Address: 0x10418C90
// Name: _dynamic_initializer_for__option_speed_method__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__option_speed_method__()
{
  ConVar::ConVar(this: &option_speed_method, pName: "option_speed_method", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__option_speed_method__);
}

//------------------------------------------------------------------------------
// Address: 0x104323D0
// Name: _dynamic_atexit_destructor_for__option_duck_method_default__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__option_duck_method_default__()
{
  ConVar::~ConVar(this: &option_duck_method_default);
}

//------------------------------------------------------------------------------
// Address: 0x104323E0
// Name: _dynamic_atexit_destructor_for__option_speed_method_default__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__option_speed_method_default__()
{
  ConVar::~ConVar(this: &option_speed_method_default);
}

//------------------------------------------------------------------------------
// Address: 0x104325C0
// Name: _dynamic_atexit_destructor_for__option_duck_method__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__option_duck_method__()
{
  ConVar::~ConVar(this: &option_duck_method);
}

//------------------------------------------------------------------------------
// Address: 0x104325D0
// Name: _dynamic_atexit_destructor_for__option_speed_method__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__option_speed_method__()
{
  ConVar::~ConVar(this: &option_speed_method);
}

//------------------------------------------------------------------------------
// Address: 0x104186F0
// Name: _dynamic_initializer_for__joy_yawsensitivity_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_yawsensitivity_default__()
{
  ConVar::ConVar(
    this: &joy_yawsensitivity_default,
    pName: "joy_yawsensitivity_default",
    pDefaultValue: "-1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_yawsensitivity_default__);
}

//------------------------------------------------------------------------------
// Address: 0x10418720
// Name: _dynamic_initializer_for__joy_pitchsensitivity_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_pitchsensitivity_default__()
{
  ConVar::ConVar(
    this: &joy_pitchsensitivity_default,
    pName: "joy_pitchsensitivity_default",
    pDefaultValue: "-1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_pitchsensitivity_default__);
}

//------------------------------------------------------------------------------
// Address: 0x10418750
// Name: _dynamic_initializer_for__sv_stickysprint_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_stickysprint_default__()
{
  ConVar::ConVar(this: &sv_stickysprint_default, pName: "sv_stickysprint_default", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_stickysprint_default__);
}

//------------------------------------------------------------------------------
// Address: 0x10418780
// Name: _dynamic_initializer_for__joy_lookspin_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_lookspin_default__()
{
  ConVar::ConVar(this: &joy_lookspin_default, pName: "joy_lookspin_default", pDefaultValue: "0.35", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_lookspin_default__);
}

//------------------------------------------------------------------------------
// Address: 0x104187B0
// Name: _dynamic_initializer_for__joy_cfg_preset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_cfg_preset__()
{
  ConVar::ConVar(this: &joy_cfg_preset, pName: "joy_cfg_preset", pDefaultValue: "1", flags: 16809984);
  return atexit(func: dynamic_atexit_destructor_for__joy_cfg_preset__);
}

//------------------------------------------------------------------------------
// Address: 0x104187E0
// Name: _dynamic_initializer_for__joy_movement_stick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_movement_stick__()
{
  ConVar::ConVar(
    this: &joy_movement_stick,
    pName: "joy_movement_stick",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Which stick controls movement (0 is left stick)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))joy_movement_stick_Callback);
  return atexit(func: dynamic_atexit_destructor_for__joy_movement_stick__);
}

//------------------------------------------------------------------------------
// Address: 0x10418810
// Name: _dynamic_initializer_for__joy_xcontroller_cfg_loaded__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_xcontroller_cfg_loaded__()
{
  ConVar::ConVar(
    this: &joy_xcontroller_cfg_loaded,
    pName: "joy_xcontroller_cfg_loaded",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If 0, the 360controller.cfg file will be executed on startup & option changes.");
  return atexit(func: dynamic_atexit_destructor_for__joy_xcontroller_cfg_loaded__);
}

//------------------------------------------------------------------------------
// Address: 0x10418840
// Name: _dynamic_initializer_for__joy_no_accel_jump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_no_accel_jump__()
{
  ConVar::ConVar(this: &joy_no_accel_jump, pName: "joy_no_accel_jump", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_no_accel_jump__);
}

//------------------------------------------------------------------------------
// Address: 0x10418870
// Name: _dynamic_initializer_for__joy_pegged__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_pegged__()
{
  ConVar::ConVar(this: &joy_pegged, pName: "joy_pegged", pDefaultValue: "0.75", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_pegged__);
}

//------------------------------------------------------------------------------
// Address: 0x104188A0
// Name: _dynamic_initializer_for__joy_virtual_peg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_virtual_peg__()
{
  ConVar::ConVar(this: &joy_virtual_peg, pName: "joy_virtual_peg", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_virtual_peg__);
}

//------------------------------------------------------------------------------
// Address: 0x104188D0
// Name: _dynamic_initializer_for__joy_accel_filter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_accel_filter__()
{
  ConVar::ConVar(this: &joy_accel_filter, pName: "joy_accel_filter", pDefaultValue: "0.2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_accel_filter__);
}

//------------------------------------------------------------------------------
// Address: 0x10418900
// Name: _dynamic_initializer_for__joy_useNewAcecelMethod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_useNewAcecelMethod__()
{
  ConVar::ConVar(this: &joy_useNewAcecelMethod, pName: "joy_useNewAcecelMethod", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_useNewAcecelMethod__);
}

//------------------------------------------------------------------------------
// Address: 0x10418930
// Name: _dynamic_initializer_for__m_allowGameMouse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__m_allowGameMouse__()
{
  ConVar::ConVar(this: &m_allowGameMouse, pName: "m_allowGameMouse", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__m_allowGameMouse__);
}

//------------------------------------------------------------------------------
// Address: 0x10418960
// Name: _dynamic_initializer_for__cl_anglespeedkey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_anglespeedkey__()
{
  ConVar::ConVar(this: &cl_anglespeedkey, pName: "cl_anglespeedkey", pDefaultValue: "0.67", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_anglespeedkey__);
}

//------------------------------------------------------------------------------
// Address: 0x10418990
// Name: _dynamic_initializer_for__cl_yawspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_yawspeed__()
{
  ConVar::ConVar(this: &cl_yawspeed, pName: "cl_yawspeed", pDefaultValue: "210", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_yawspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x104189C0
// Name: _dynamic_initializer_for__cl_pitchspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pitchspeed__()
{
  ConVar::ConVar(this: &cl_pitchspeed, pName: "cl_pitchspeed", pDefaultValue: "225", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_pitchspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x104189F0
// Name: _dynamic_initializer_for__cl_pitchdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pitchdown__()
{
  ConVar::ConVar(this: &cl_pitchdown, pName: "cl_pitchdown", pDefaultValue: "89", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_pitchdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10418A20
// Name: _dynamic_initializer_for__cl_pitchup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pitchup__()
{
  ConVar::ConVar(this: &cl_pitchup, pName: "cl_pitchup", pDefaultValue: "89", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_pitchup__);
}

//------------------------------------------------------------------------------
// Address: 0x10418A50
// Name: _dynamic_initializer_for__cl_upspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_upspeed__()
{
  ConVar::ConVar(this: &cl_upspeed, pName: "cl_upspeed", pDefaultValue: "320", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_upspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10418A80
// Name: _dynamic_initializer_for__lookspring__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lookspring__()
{
  ConVar::ConVar(this: &lookspring, pName: "lookspring", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__lookspring__);
}

//------------------------------------------------------------------------------
// Address: 0x10418AB0
// Name: _dynamic_initializer_for__lookstrafe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lookstrafe__()
{
  ConVar::ConVar(this: &lookstrafe, pName: "lookstrafe", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__lookstrafe__);
}

//------------------------------------------------------------------------------
// Address: 0x10418AE0
// Name: _dynamic_initializer_for__cl_sidespeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_sidespeed__()
{
  ConVar::ConVar(this: &cl_sidespeed, pName: "cl_sidespeed", pDefaultValue: "450", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_sidespeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10418B10
// Name: _dynamic_initializer_for__cl_forwardspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_forwardspeed__()
{
  ConVar::ConVar(this: &cl_forwardspeed, pName: "cl_forwardspeed", pDefaultValue: "450", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_forwardspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10418B40
// Name: _dynamic_initializer_for__cl_backspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_backspeed__()
{
  ConVar::ConVar(this: &cl_backspeed, pName: "cl_backspeed", pDefaultValue: "450", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_backspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10418B70
// Name: _dynamic_initializer_for__in_joystick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__in_joystick__()
{
  ConVar::ConVar(
    this: &in_joystick,
    pName: "joystick",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "True if the joystick is enabled, false otherwise.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))IN_JoystickChangedCallback_f);
  return atexit(func: dynamic_atexit_destructor_for__in_joystick__);
}

//------------------------------------------------------------------------------
// Address: 0x10418BA0
// Name: _dynamic_initializer_for__thirdperson_platformer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__thirdperson_platformer__()
{
  ConVar::ConVar(
    this: &thirdperson_platformer,
    pName: "thirdperson_platformer",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Player will aim in the direction they are moving.");
  return atexit(func: dynamic_atexit_destructor_for__thirdperson_platformer__);
}

//------------------------------------------------------------------------------
// Address: 0x10418BD0
// Name: _dynamic_initializer_for__thirdperson_screenspace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__thirdperson_screenspace__()
{
  ConVar::ConVar(
    this: &thirdperson_screenspace,
    pName: "thirdperson_screenspace",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Movement will be relative to the camera, eg: left means screen-left");
  return atexit(func: dynamic_atexit_destructor_for__thirdperson_screenspace__);
}

//------------------------------------------------------------------------------
// Address: 0x10418C00
// Name: _dynamic_initializer_for__sv_noclipduringpause__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_noclipduringpause__()
{
  ConVar::ConVar(
    this: &sv_noclipduringpause,
    pName: "sv_noclipduringpause",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "If cheats are enabled, then you can noclip with the game paused (for doing screenshots, etc.).");
  return atexit(func: dynamic_atexit_destructor_for__sv_noclipduringpause__);
}

//------------------------------------------------------------------------------
// Address: 0x10418C30
// Name: _dynamic_initializer_for__cl_lagcomp_errorcheck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_lagcomp_errorcheck__()
{
  ConVar::ConVar(
    this: &cl_lagcomp_errorcheck,
    pName: "cl_lagcomp_errorcheck",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Player index of other player to check for position errors.");
  return atexit(func: dynamic_atexit_destructor_for__cl_lagcomp_errorcheck__);
}

//------------------------------------------------------------------------------
// Address: 0x104323F0
// Name: _dynamic_atexit_destructor_for__joy_yawsensitivity_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_yawsensitivity_default__()
{
  ConVar::~ConVar(this: &joy_yawsensitivity_default);
}

//------------------------------------------------------------------------------
// Address: 0x10432400
// Name: _dynamic_atexit_destructor_for__joy_pitchsensitivity_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_pitchsensitivity_default__()
{
  ConVar::~ConVar(this: &joy_pitchsensitivity_default);
}

//------------------------------------------------------------------------------
// Address: 0x10432410
// Name: _dynamic_atexit_destructor_for__sv_stickysprint_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_stickysprint_default__()
{
  ConVar::~ConVar(this: &sv_stickysprint_default);
}

//------------------------------------------------------------------------------
// Address: 0x10432420
// Name: _dynamic_atexit_destructor_for__joy_lookspin_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_lookspin_default__()
{
  ConVar::~ConVar(this: &joy_lookspin_default);
}

//------------------------------------------------------------------------------
// Address: 0x10432430
// Name: _dynamic_atexit_destructor_for__joy_cfg_preset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_cfg_preset__()
{
  ConVar::~ConVar(this: &joy_cfg_preset);
}

//------------------------------------------------------------------------------
// Address: 0x10432440
// Name: _dynamic_atexit_destructor_for__joy_movement_stick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_movement_stick__()
{
  ConVar::~ConVar(this: &joy_movement_stick);
}

//------------------------------------------------------------------------------
// Address: 0x10432450
// Name: _dynamic_atexit_destructor_for__joy_xcontroller_cfg_loaded__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_xcontroller_cfg_loaded__()
{
  ConVar::~ConVar(this: &joy_xcontroller_cfg_loaded);
}

//------------------------------------------------------------------------------
// Address: 0x10432460
// Name: _dynamic_atexit_destructor_for__joy_no_accel_jump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_no_accel_jump__()
{
  ConVar::~ConVar(this: &joy_no_accel_jump);
}

//------------------------------------------------------------------------------
// Address: 0x10432470
// Name: _dynamic_atexit_destructor_for__joy_pegged__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_pegged__()
{
  ConVar::~ConVar(this: &joy_pegged);
}

//------------------------------------------------------------------------------
// Address: 0x10432480
// Name: _dynamic_atexit_destructor_for__joy_virtual_peg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_virtual_peg__()
{
  ConVar::~ConVar(this: &joy_virtual_peg);
}

//------------------------------------------------------------------------------
// Address: 0x10432490
// Name: _dynamic_atexit_destructor_for__joy_accel_filter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_accel_filter__()
{
  ConVar::~ConVar(this: &joy_accel_filter);
}

//------------------------------------------------------------------------------
// Address: 0x104324A0
// Name: _dynamic_atexit_destructor_for__joy_useNewAcecelMethod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joy_useNewAcecelMethod__()
{
  ConVar::~ConVar(this: &joy_useNewAcecelMethod);
}

//------------------------------------------------------------------------------
// Address: 0x104324B0
// Name: _dynamic_atexit_destructor_for__m_allowGameMouse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_allowGameMouse__()
{
  ConVar::~ConVar(this: &m_allowGameMouse);
}

//------------------------------------------------------------------------------
// Address: 0x104324C0
// Name: _dynamic_atexit_destructor_for__cl_anglespeedkey__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_anglespeedkey__()
{
  ConVar::~ConVar(this: &cl_anglespeedkey);
}

//------------------------------------------------------------------------------
// Address: 0x104324D0
// Name: _dynamic_atexit_destructor_for__cl_yawspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_yawspeed__()
{
  ConVar::~ConVar(this: &cl_yawspeed);
}

//------------------------------------------------------------------------------
// Address: 0x104324E0
// Name: _dynamic_atexit_destructor_for__cl_pitchspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pitchspeed__()
{
  ConVar::~ConVar(this: &cl_pitchspeed);
}

//------------------------------------------------------------------------------
// Address: 0x104324F0
// Name: _dynamic_atexit_destructor_for__cl_pitchdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pitchdown__()
{
  ConVar::~ConVar(this: &cl_pitchdown);
}

//------------------------------------------------------------------------------
// Address: 0x10432500
// Name: _dynamic_atexit_destructor_for__cl_pitchup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_pitchup__()
{
  ConVar::~ConVar(this: &cl_pitchup);
}

//------------------------------------------------------------------------------
// Address: 0x10432510
// Name: _dynamic_atexit_destructor_for__cl_upspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_upspeed__()
{
  ConVar::~ConVar(this: &cl_upspeed);
}

//------------------------------------------------------------------------------
// Address: 0x10432520
// Name: _dynamic_atexit_destructor_for__lookspring__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lookspring__()
{
  ConVar::~ConVar(this: &lookspring);
}

//------------------------------------------------------------------------------
// Address: 0x10432530
// Name: _dynamic_atexit_destructor_for__lookstrafe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lookstrafe__()
{
  ConVar::~ConVar(this: &lookstrafe);
}

//------------------------------------------------------------------------------
// Address: 0x10432540
// Name: _dynamic_atexit_destructor_for__cl_sidespeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_sidespeed__()
{
  ConVar::~ConVar(this: &cl_sidespeed);
}

//------------------------------------------------------------------------------
// Address: 0x10432550
// Name: _dynamic_atexit_destructor_for__cl_forwardspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_forwardspeed__()
{
  ConVar::~ConVar(this: &cl_forwardspeed);
}

//------------------------------------------------------------------------------
// Address: 0x10432560
// Name: _dynamic_atexit_destructor_for__cl_backspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_backspeed__()
{
  ConVar::~ConVar(this: &cl_backspeed);
}

//------------------------------------------------------------------------------
// Address: 0x10432570
// Name: _dynamic_atexit_destructor_for__in_joystick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__in_joystick__()
{
  ConVar::~ConVar(this: &in_joystick);
}

//------------------------------------------------------------------------------
// Address: 0x10432580
// Name: _dynamic_atexit_destructor_for__thirdperson_platformer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thirdperson_platformer__()
{
  ConVar::~ConVar(this: &thirdperson_platformer);
}

//------------------------------------------------------------------------------
// Address: 0x10432590
// Name: _dynamic_atexit_destructor_for__thirdperson_screenspace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thirdperson_screenspace__()
{
  ConVar::~ConVar(this: &thirdperson_screenspace);
}

//------------------------------------------------------------------------------
// Address: 0x104325A0
// Name: _dynamic_atexit_destructor_for__sv_noclipduringpause__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_noclipduringpause__()
{
  ConVar::~ConVar(this: &sv_noclipduringpause);
}

//------------------------------------------------------------------------------
// Address: 0x104325B0
// Name: _dynamic_atexit_destructor_for__cl_lagcomp_errorcheck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_lagcomp_errorcheck__()
{
  ConVar::~ConVar(this: &cl_lagcomp_errorcheck);
}
