// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/sfuiavatarimage.cpp
// Functions: 13
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\sfuiavatarimage.h"

//------------------------------------------------------------------------------
// Address: 0x10017240
// Name: public: bool ScaleformUIAvatarImage::LoadAvatarImage(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIAvatarImage::LoadAvatarImage(ScaleformUIAvatarImage *this)
{
  ISteamFriends *m_pSteamFriends; // ecx
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  unsigned __int8 *m_pMemory; // edi
  ScaleformTexture *m_pTexture; // ecx
  unsigned int v10; // [esp-10h] [ebp-2Ch]
  unsigned int v11; // [esp-Ch] [ebp-28h]
  int v12; // [esp+Ch] [ebp-10h]
  unsigned int tall; // [esp+10h] [ebp-Ch] BYREF
  unsigned int wide; // [esp+14h] [ebp-8h] BYREF
  bool bUseSteamImage; // [esp+1Bh] [ebp-1h]

  m_pSteamFriends = steamapicontext->m_pSteamFriends;
  if ( m_pSteamFriends != nullptr && steamapicontext->m_pSteamUtils != nullptr )
  {
    v12 = ((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))m_pSteamFriends->GetMediumFriendAvatar)(
            a1: m_pSteamFriends,
            a2: this->m_xXUID,
            a3: HIDWORD(this->m_xXUID));
    if ( steamapicontext->m_pSteamUtils->GetImageSize(
           this: steamapicontext->m_pSteamUtils,
           a2: v12,
           a3: &wide,
           a4: &tall) )
    {
      v3 = wide;
      bUseSteamImage = true;
      if ( wide == 0 || (v4 = tall, tall == 0) )
      {
        v4 = 64;
        v3 = 64;
        bUseSteamImage = false;
        tall = 64;
        wide = 64;
      }
      v5 = 4 * v4 * v3;
      CUtlBuffer::EnsureCapacity(this: &this->m_bufRgbaBuffer, num: v5);
      memset(dst: this->m_bufRgbaBuffer.m_Memory.m_pMemory, value: 0xFFu, count: v5);
      if ( bUseSteamImage )
        steamapicontext->m_pSteamUtils->GetImageRGBA(
          this: steamapicontext->m_pSteamUtils,
          a2: v12,
          a3: this->m_bufRgbaBuffer.m_Memory.m_pMemory,
          a4: v5);
      v6 = wide;
      m_pMemory = this->m_bufRgbaBuffer.m_Memory.m_pMemory;
      v11 = tall;
      v10 = wide;
      this->m_nHeight = tall;
      m_pTexture = this->m_pTexture;
      this->m_nWidth = v6;
      this->m_format = IMAGE_FORMAT_RGBA8888;
      this->m_dstFormat = IMAGE_FORMAT_BGRA8888;
      this->m_bValid = ScaleformTexture::InitTexture(
                         this: m_pTexture,
                         rgba: m_pMemory,
                         width: v10,
                         height: v11,
                         srcImageFormat: IMAGE_FORMAT_RGBA8888,
                         dstImageFormat: IMAGE_FORMAT_BGRA8888);
    }
  }
  return this->m_bValid;
}

//------------------------------------------------------------------------------
// Address: 0x10017340
// Name: public: class ScaleformTexture __near * ScaleformUIAvatarImage::GetTexture(void)
// Source: json
//------------------------------------------------------------------------------
ScaleformTexture *__thiscall ScaleformUIAvatarImage::GetTexture(ScaleformUIAvatarImage *this)
{
  unsigned __int8 *m_pMemory; // ebx
  int m_nWidth; // edi
  int m_nHeight; // edx

  if ( !this->m_pTexture->IsDataValid(this: this->m_pTexture) )
  {
    m_pMemory = this->m_bufRgbaBuffer.m_Memory.m_pMemory;
    if ( m_pMemory != nullptr )
    {
      m_nWidth = this->m_nWidth;
      if ( m_nWidth != 0 )
      {
        m_nHeight = this->m_nHeight;
        if ( m_nHeight != 0 )
          this->m_bValid = ScaleformTexture::InitTexture(
                             this: this->m_pTexture,
                             rgba: m_pMemory,
                             width: m_nWidth,
                             height: m_nHeight,
                             srcImageFormat: this->m_format,
                             dstImageFormat: this->m_dstFormat);
      }
    }
  }
  return this->m_pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10017390
// Name: private: void ScaleformUIAvatarImage::Steam_OnAvatarImageLoaded(struct AvatarImageLoaded_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIAvatarImage::Steam_OnAvatarImageLoaded(
        ScaleformUIAvatarImage *this,
        AvatarImageLoaded_t *pParam)
{
  int m_unAll64Bits_high; // edx
  unsigned int v3; // eax

  m_unAll64Bits_high = HIDWORD(pParam->m_steamID.m_steamid.m_unAll64Bits);
  v3 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  if ( (v3 == 0
     || v3 >= 0xB
     || m_unAll64Bits_high >> 24 <= 0
     || m_unAll64Bits_high >> 24 >= 6
     || v3 == 1 && (pParam->m_steamID.m_steamid.m_comp == 0 || (m_unAll64Bits_high & 0xFFFFF) != 1)
     || v3 == 7 && (pParam->m_steamID.m_steamid.m_comp == 0 || (m_unAll64Bits_high & 0xFFFFF) != 0))
    && pParam->m_steamID.m_steamid.m_comp == LODWORD(this->m_xXUID)
    && m_unAll64Bits_high == HIDWORD(this->m_xXUID) )
  {
    ScaleformUIAvatarImage::LoadAvatarImage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017400
// Name: private: void ScaleformUIAvatarImage::Steam_OnPersonaStateChanged(struct PersonaStateChange_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIAvatarImage::Steam_OnPersonaStateChanged(
        ScaleformUIAvatarImage *this,
        PersonaStateChange_t *pParam)
{
  if ( LODWORD(pParam->m_ulSteamID) == LODWORD(this->m_xXUID)
    && HIDWORD(pParam->m_ulSteamID) == HIDWORD(this->m_xXUID)
    && (pParam->m_nChangeFlags & 0x40) != 0 )
  {
    ScaleformUIAvatarImage::LoadAvatarImage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017430
// Name: public: CCallback<class ScaleformUIAvatarImage,struct PersonaStateChange_t,0>::~CCallback<class ScaleformUIAvatarImage,struct PersonaStateChange_t,0>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>::~CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>(
        CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0> *this)
{
  bool v1; // zf

  v1 = (this->m_nCallbackFlags & 1) == 0;
  this->__vftable = (CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>_vtbl *)&CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>::`vftable';
  if ( !v1 )
    _SteamAPI_UnregisterCallback(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x10017450
// Name: private: virtual void CCallback<class ScaleformUIAvatarImage,struct AvatarImageLoaded_t,0>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>::Run(
        CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0> *this,
        void *pvParam)
{
  ((void (__thiscall *)(ScaleformUIAvatarImage *, void *))LODWORD(this->m_Func))(a1: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x10017460
// Name: private: virtual int CCallback<class ScaleformUIAvatarImage,struct PersonaStateChange_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>::GetCallbackSizeBytes(
        GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10017470
// Name: public: CCallback<class ScaleformUIAvatarImage,struct AvatarImageLoaded_t,0>::~CCallback<class ScaleformUIAvatarImage,struct AvatarImageLoaded_t,0>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>::~CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>(
        CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0> *this)
{
  bool v1; // zf

  v1 = (this->m_nCallbackFlags & 1) == 0;
  this->__vftable = (CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>_vtbl *)&CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>::`vftable';
  if ( !v1 )
    _SteamAPI_UnregisterCallback(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x10017490
// Name: private: virtual void CCallback<class ScaleformUIAvatarImage,struct PersonaStateChange_t,0>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>::Run(
        CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0> *this,
        void *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  ((void (__thiscall *)(ScaleformUIAvatarImage *, void *))LODWORD(this->m_Func))(a1: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x100174B0
// Name: public: ScaleformUIAvatarImage::~ScaleformUIAvatarImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIAvatarImage::~ScaleformUIAvatarImage(ScaleformUIAvatarImage *this)
{
  ScaleformTexture *m_pTexture; // edi
  bool v3; // zf

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr )
  {
    if ( InterlockedExchangeAdd(Addend: &m_pTexture->RefCount.Value, Value: -1) == 1 )
      ((void (__thiscall *)(ScaleformTexture *, int))m_pTexture->dtr_GTexture)(a1: m_pTexture, a2: 1);
    this->m_pTexture = nullptr;
  }
  v3 = (BYTE4(this->m_CallbackPersonaStateChanged.m_Func) & 1) == 0;
  LODWORD(this->m_CallbackPersonaStateChanged.m_Func) = &CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>::`vftable';
  if ( !v3 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackPersonaStateChanged.m_Func);
  v3 = ((int)this->m_CallbackPersonaStateChanged.__vftable & 1) == 0;
  *((_DWORD *)&this->m_pTexture + 1) = &CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>::`vftable';
  if ( !v3 )
    _SteamAPI_UnregisterCallback(a1: &this->m_pTexture + 1);
  if ( this->m_bufRgbaBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufRgbaBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufRgbaBuffer.m_Memory.m_pMemory);
      this->m_bufRgbaBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufRgbaBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017580
// Name: public: ScaleformUIAvatarImage::ScaleformUIAvatarImage(class ScaleformRenderer __near *,unsigned __int64,unsigned char const __near *,enum ImageFormat,int,int)
// Source: json
//------------------------------------------------------------------------------
ScaleformUIAvatarImage *__thiscall ScaleformUIAvatarImage::ScaleformUIAvatarImage(
        ScaleformUIAvatarImage *this,
        ScaleformRenderer *pRenderer,
        unsigned __int64 xuid,
        const unsigned __int8 *defaultRgba,
        ImageFormat defaultFormat,
        int defaultWidth,
        int defaultHeight)
{
  ScaleformTexture *v8; // eax

  LODWORD(this->m_xXUID) = xuid;
  this->m_nWidth = defaultWidth;
  this->m_nHeight = defaultHeight;
  HIDWORD(this->m_xXUID) = HIDWORD(xuid);
  CUtlBuffer::CUtlBuffer(this: &this->m_bufRgbaBuffer, growSize: 0, initSize: 0, nFlags: 0);
  LOBYTE(this->m_CallbackPersonaStateChanged.__vftable) = 0;
  *(_DWORD *)&this->m_CallbackPersonaStateChanged.m_nCallbackFlags = 0;
  *((_DWORD *)&this->m_pTexture + 1) = &CCallback<ScaleformUIAvatarImage,PersonaStateChange_t,0>::`vftable';
  this->m_CallbackPersonaStateChanged.m_iCallback = (int)this;
  this->m_CallbackPersonaStateChanged.m_pObj = (ScaleformUIAvatarImage *)ScaleformUIAvatarImage::Steam_OnPersonaStateChanged;
  if ( ScaleformUIAvatarImage::Steam_OnPersonaStateChanged != nullptr )
  {
    this->m_CallbackPersonaStateChanged.m_iCallback = (int)this;
    this->m_CallbackPersonaStateChanged.m_pObj = (ScaleformUIAvatarImage *)ScaleformUIAvatarImage::Steam_OnPersonaStateChanged;
    _SteamAPI_RegisterCallback(a1: &this->m_pTexture + 1, a2: 304);
  }
  BYTE4(this->m_CallbackPersonaStateChanged.m_Func) = 0;
  DWORD2(this->m_CallbackPersonaStateChanged.m_Func) = 0;
  LODWORD(this->m_CallbackPersonaStateChanged.m_Func) = &CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>::`vftable';
  HIDWORD(this->m_CallbackPersonaStateChanged.m_Func) = this;
  this->m_CallbackAvatarImageLoaded.__vftable = (CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>_vtbl *)ScaleformUIAvatarImage::Steam_OnAvatarImageLoaded;
  if ( ScaleformUIAvatarImage::Steam_OnAvatarImageLoaded != nullptr )
  {
    HIDWORD(this->m_CallbackPersonaStateChanged.m_Func) = this;
    this->m_CallbackAvatarImageLoaded.__vftable = (CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>_vtbl *)ScaleformUIAvatarImage::Steam_OnAvatarImageLoaded;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackPersonaStateChanged.m_Func, a2: 334);
  }
  this->m_nRefcount = 0;
  v8 = (ScaleformTexture *)pRenderer->CreateTexture(this: pRenderer);
  this->m_pTexture = v8;
  if ( defaultRgba != nullptr )
  {
    this->m_format = defaultFormat;
    this->m_nWidth = defaultWidth;
    this->m_nHeight = defaultHeight;
    this->m_dstFormat = IMAGE_FORMAT_DEFAULT;
    ScaleformTexture::InitTexture(
      this: v8,
      rgba: defaultRgba,
      width: defaultWidth,
      height: defaultHeight,
      srcImageFormat: defaultFormat,
      dstImageFormat: IMAGE_FORMAT_DEFAULT);
  }
  this->m_bValid = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017690
// Name: public: void ScaleformUIAvatarImage::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIAvatarImage::OnFinalRelease(ScaleformUIAvatarImage *this)
{
  if ( this != nullptr )
  {
    ScaleformUIAvatarImage::~ScaleformUIAvatarImage(this);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123A60
// Name: private: virtual int CCallback<class ScaleformUIAvatarImage,struct AvatarImageLoaded_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0>::GetCallbackSizeBytes(
        CCallback<ScaleformUIAvatarImage,AvatarImageLoaded_t,0> *this)
{
  return 20;
}
