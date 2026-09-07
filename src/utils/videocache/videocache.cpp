// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/videocache/videocache.cpp
// Functions: 116
// ============================================================

#include "utils\videocache\videocache.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: CVidCacheCmdAck::CVidCacheCmdAck(bool)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdAck *__thiscall CVidCacheCmdAck::CVidCacheCmdAck(CVidCacheCmdAck *this, unsigned __int8 success)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_Success = success;
  this->m_Command = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: public: CVidCacheCmdAck::CVidCacheCmdAck(enum eVidCacheError_t)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdAck *__thiscall CVidCacheCmdAck::CVidCacheCmdAck(CVidCacheCmdAck *this, eVidCacheError_t err)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_LastError = err;
  this->m_Command = 3;
  this->m_Success = err == cVCE_NoErr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401060
// Name: public: CVidCacheCmdBeginCacheSessionResult::CVidCacheCmdBeginCacheSessionResult(int,unsigned char,bool,enum eVidCacheError_t)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdBeginCacheSessionResult *__thiscall CVidCacheCmdBeginCacheSessionResult::CVidCacheCmdBeginCacheSessionResult(
        CVidCacheCmdBeginCacheSessionResult *this,
        int localId,
        unsigned __int8 id,
        unsigned __int8 success,
        eVidCacheError_t err)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_Success = success;
  this->m_iData[0] = localId;
  this->m_Command = 10;
  this->m_LastError = err;
  this->m_SessionID = id;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004010A0
// Name: public: CVidCacheCmdCacheFileResult::CVidCacheCmdCacheFileResult(int,bool,enum eVidCacheError_t,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdCacheFileResult *__thiscall CVidCacheCmdCacheFileResult::CVidCacheCmdCacheFileResult(
        CVidCacheCmdCacheFileResult *this,
        int localId,
        unsigned __int8 success,
        eVidCacheError_t err,
        unsigned int serverHandle)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_Success = success;
  this->m_iData[1] = serverHandle;
  this->m_Command = 18;
  this->m_LastError = err;
  this->m_iData[0] = localId;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004010E0
// Name: public: CVidCacheCmdRequestFrameResult::CVidCacheCmdRequestFrameResult(unsigned int,float,bool)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdRequestFrameResult *__thiscall CVidCacheCmdRequestFrameResult::CVidCacheCmdRequestFrameResult(
        CVidCacheCmdRequestFrameResult *this,
        unsigned int serverHandle,
        float frameTime,
        unsigned __int8 success)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_Success = success;
  this->m_Command = 34;
  this->m_iData[0] = serverHandle;
  this->m_fData[1] = frameTime;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401120
// Name: public: CVidCacheCmdBeginEncodingResult::CVidCacheCmdBeginEncodingResult(int,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdBeginEncodingResult *__thiscall CVidCacheCmdBeginEncodingResult::CVidCacheCmdBeginEncodingResult(
        CVidCacheCmdBeginEncodingResult *this,
        int localId,
        unsigned __int8 success,
        unsigned int serverHandle)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_Success = success;
  this->m_Command = 50;
  this->m_iData[0] = localId;
  this->m_iData[1] = serverHandle;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: public: CVidCacheCmdEncodeFrameResult::CVidCacheCmdEncodeFrameResult(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdEncodeFrameResult *__thiscall CVidCacheCmdEncodeFrameResult::CVidCacheCmdEncodeFrameResult(
        CVidCacheCmdEncodeFrameResult *this,
        unsigned int serverHandle,
        int frameNum,
        unsigned __int8 success)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_Success = success;
  this->m_Command = 56;
  this->m_iData[0] = serverHandle;
  this->m_iData[1] = frameNum;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401180
// Name: public: CVidCacheCmdEndEncodingResult::CVidCacheCmdEndEncodingResult(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
CVidCacheCmdEndEncodingResult *__thiscall CVidCacheCmdEndEncodingResult::CVidCacheCmdEndEncodingResult(
        CVidCacheCmdEndEncodingResult *this,
        unsigned int serverHandle,
        bool success)
{
  _V_memset(dest: this, fill: 0, count: 16);
  this->m_iData[0] = serverHandle;
  this->m_Command = 59;
  this->m_iData[1] = success;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: ServerVideoHandleLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ServerVideoHandleLessFunc(const unsigned int *nArg0, const unsigned int *nArg1)
{
  return *nArg0 < *nArg1;
}

//------------------------------------------------------------------------------
// Address: 0x004011D0
// Name: void PrintArgSummary(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintArgSummary()
{
  printf(format: "VideoCache command line summary\n\n");
  printf(format: "    -server\t        Runs SFM VideoCaching server (normal usage)\n");
  printf(format: "    -decodetest        Runs QuickTime H.264 Movie Frame Extraction Test\n");
  printf(format: "    -encodetest        Runs QuickTime H.264 Movie Creation from frame sequence Test\n");
  printf(format: "    -logdecode [path]  Output .BMP of decoded frames [to specifed path]\n");
  printf(format: "    -logencode [path]  Output .BMP of encoded frames [to specifed path]\n");
  printf(format: "    -v                 Display verbose event information\n");
  printf(format: "    -?                 Prints this summary\n");
}

//------------------------------------------------------------------------------
// Address: 0x00401230
// Name: enum eVidCacheError_t CheckSessionId(struct CVidCmd __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CheckSessionId(CVidCmd *pCmd)
{
  if ( g_SessionID != 0 )
    return g_SessionID == pCmd->m_SessionID ? 0 : 3;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401260
// Name: bool CheckVideoFrameSize(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckVideoFrameSize(int width, int height)
{
  return (unsigned int)(width - 16) <= 0x7F0 && (unsigned int)(height - 16) <= 0x7F0;
}

//------------------------------------------------------------------------------
// Address: 0x00401290
// Name: bool SetupQuicktime(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SetupQuicktime()
{
  __int16 v0; // ax

  v0 = InitializeQTML(a1: 0);
  if ( v0 == -2093 )
  {
    _Plat_MessageBox(
      a1: "VideoCache ERROR",
      a2: "ERROR: QuickTime is not installed on this system.  It is needed in order for the SFM Video Cache service to run");
    return false;
  }
  else
  {
    if ( v0 == 0 )
      v0 = EnterMovies();
    return v0 == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012E0
// Name: private: void CCachedQTVideoFile::OpenQTMovie(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedQTVideoFile::OpenQTMovie(CCachedQTVideoFile *this, const char *theQTMovieFileName)
{
  int NativeWindowPort; // eax
  int v4; // eax
  char *v5; // eax
  int MovieDuration; // eax
  int v7; // edx
  int right; // ecx
  unsigned int m_BitMapDataSize; // eax
  int v10; // edx
  FSSpec sfFile; // [esp+Ch] [ebp-20Ch] BYREF
  char fullPath[256]; // [esp+114h] [ebp-104h] BYREF
  int theFile; // [esp+214h] [ebp-4h] BYREF

  theFile = 0;
  NativeWindowPort = GetNativeWindowPort(a1: 0);
  SetGWorld(a1: NativeWindowPort);
  if ( this->m_pFileName != nullptr )
  {
    operator delete(p: this->m_pFileName);
    this->m_pFileName = nullptr;
  }
  if ( theQTMovieFileName != nullptr )
  {
    v4 = _V_strlen(str: theQTMovieFileName);
    v5 = (char *)operator new(size: v4 + 1);
    this->m_pFileName = v5;
    _V_strcpy(dest: v5, src: theQTMovieFileName);
  }
  strcpy(fullPath, theQTMovieFileName);
  c2pstr(a1: fullPath);
  FSMakeFSSpec(a1: 0, a2: 0, a3: fullPath, a4: &sfFile);
  if ( (unsigned __int16)OpenMovieFile(a1: &sfFile, a2: &theFile, a3: 1) != 0 )
  {
    CloseMovieFile(a1: theFile);
    if ( this->m_pFileName != nullptr )
    {
      operator delete(p: this->m_pFileName);
      this->m_pFileName = nullptr;
    }
    this->m_QTMovieDurationinSec = 0.0;
    this->m_pFileName = nullptr;
    this->m_QTMovie = nullptr;
    this->m_MovieGWorld = nullptr;
    this->m_QTMovieDuration = 0;
    this->m_QTMovieRect = 0;
    memset(dst: (unsigned __int8 *)&this->m_BitmapInfo, value: 0, count: sizeof(this->m_BitmapInfo));
    this->m_BitMapData = nullptr;
    this->m_BitMapDataSize = 0;
    this->m_bIsErrorFrame = false;
    this->m_bActive = false;
    this->m_nLastFrameTime = -11.1;
  }
  else
  {
    NewMovieFromFile(a1: &this->m_QTMovie, a2: theFile, a3: 0, a4: 0, a5: 1, a6: 0);
    CloseMovieFile(a1: theFile);
    MovieDuration = GetMovieDuration(a1: this->m_QTMovie);
    this->m_QTMovieRect.left = 0;
    this->m_QTMovieDuration = MovieDuration;
    this->m_QTMovieDurationinSec = (double)MovieDuration * 0.001666666666666667;
    this->m_QTMovieRect.top = 0;
    LOWORD(MovieDuration) = g_SessionFrameInfo.m_nFrameWidth;
    this->m_QTMovieRect.right = g_SessionFrameInfo.m_nFrameWidth;
    v7 = 4 * (__int16)MovieDuration * SLOWORD(g_SessionFrameInfo.m_nFrameHeight);
    this->m_QTMovieRect.bottom = g_SessionFrameInfo.m_nFrameHeight;
    this->m_BitMapDataSize = v7;
    memset(dst: (unsigned __int8 *)&this->m_BitmapInfo, value: 0, count: sizeof(this->m_BitmapInfo));
    right = this->m_QTMovieRect.right;
    m_BitMapDataSize = this->m_BitMapDataSize;
    v10 = -this->m_QTMovieRect.bottom;
    this->m_BitmapInfo.bmiHeader.biSizeImage = m_BitMapDataSize;
    this->m_BitmapInfo.bmiHeader.biSize = 40;
    this->m_BitmapInfo.bmiHeader.biWidth = right;
    this->m_BitmapInfo.bmiHeader.biHeight = v10;
    *(_DWORD *)&this->m_BitmapInfo.bmiHeader.biPlanes = 2097153;
    this->m_BitmapInfo.bmiHeader.biCompression = 0;
    this->m_BitMapData = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_BitMapDataSize);
    QTNewGWorld(a1: &this->m_MovieGWorld, a2: 1111970369, a3: &this->m_QTMovieRect, a4: 0, a5: 0, a6: 0);
    SetMovieGWorld(a1: this->m_QTMovie, a2: this->m_MovieGWorld, a3: 0);
    this->m_bActive = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004014F0
// Name: bool WriteBufferToBMPFile(char const __near *,void __near *,int,struct tagBITMAPINFOHEADER __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl WriteBufferToBMPFile(
        const char *fileName,
        void *pixeBuffer,
        DWORD pixelBufferSize,
        tagBITMAPINFOHEADER *infoHeader)
{
  bool v4; // bl
  HANDLE FileA; // esi
  tagBITMAPFILEHEADER hdr; // [esp+8h] [ebp-18h] BYREF
  unsigned int bytesWritten; // [esp+18h] [ebp-8h] BYREF
  bool success; // [esp+1Fh] [ebp-1h]

  v4 = false;
  success = false;
  FileA = CreateFileA(
            lpFileName: fileName,
            dwDesiredAccess: 0xC0000000,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 2u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  if ( FileA != (HANDLE)-1 )
  {
    hdr.bfSize = pixelBufferSize + 54;
    *(_DWORD *)&hdr.bfReserved1 = 0;
    bytesWritten = 0;
    hdr.bfType = 19778;
    hdr.bfOffBits = 54;
    if ( !WriteFile(
            hFile: FileA,
            lpBuffer: &hdr,
            nNumberOfBytesToWrite: 0xEu,
            lpNumberOfBytesWritten: &bytesWritten,
            lpOverlapped: nullptr)
      || !WriteFile(
            hFile: FileA,
            lpBuffer: infoHeader,
            nNumberOfBytesToWrite: 0x28u,
            lpNumberOfBytesWritten: &bytesWritten,
            lpOverlapped: nullptr)
      || (v4 = true,
          !WriteFile(
             hFile: FileA,
             lpBuffer: pixeBuffer,
             nNumberOfBytesToWrite: pixelBufferSize,
             lpNumberOfBytesWritten: &bytesWritten,
             lpOverlapped: nullptr)) )
    {
      v4 = success;
    }
    CloseHandle(hObject: FileA);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004015A0
// Name: private: void CCachedQTVideoFile::GetErrorFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedQTVideoFile::GetErrorFrame(CCachedQTVideoFile *this)
{
  _DWORD *m_BitMapData; // edx
  int v2; // eax

  if ( !this->m_bIsErrorFrame )
  {
    m_BitMapData = this->m_BitMapData;
    v2 = 0;
    if ( this->m_BitMapDataSize >= 0 && (this->m_BitMapDataSize & 0xFFFFFFFC) != 0 )
    {
      do
        m_BitMapData[v2++] = -65281;
      while ( v2 < this->m_BitMapDataSize >> 2 );
    }
    this->m_bIsErrorFrame = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015D0
// Name: public: CQTVideoFileComposer::CQTVideoFileComposer(void)
// Source: json
//------------------------------------------------------------------------------
CQTVideoFileComposer *__thiscall CQTVideoFileComposer::CQTVideoFileComposer(CQTVideoFileComposer *this)
{
  *(_DWORD *)&this->m_bMovieCreated = 0;
  this->m_bMovieCompleted = false;
  this->m_MovieFrameWidth = 0;
  this->m_MovieFrameHeight = 0;
  this->m_MovieRecordFPS = 0;
  this->m_FileName = nullptr;
  this->m_SrcImageWidth = 0;
  this->m_SrcImageHeight = 0;
  this->m_ScrImageMaxCompressedSize = 0;
  this->m_SrcImageBuffer = nullptr;
  this->m_SrcImageCompressedBuffer = nullptr;
  this->m_SrcPixelFormat = 0;
  this->m_theSrcGWorld = nullptr;
  this->m_ResRefNum = 0;
  this->m_theMovie = nullptr;
  this->m_theTrack = nullptr;
  this->m_theMedia = nullptr;
  MacSetRect(a1: &this->m_SrcImgRect, a2: 0, a3: 0, a4: 0, a5: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401620
// Name: public: bool CQTVideoFileComposer::CreateNewMovie(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQTVideoFileComposer::CreateNewMovie(CQTVideoFileComposer *this, const char *fileName)
{
  bool result; // al
  HANDLE FileA; // eax
  FSSpec sfFile; // [esp+4h] [ebp-208h] BYREF
  char fullPath[256]; // [esp+10Ch] [ebp-100h] BYREF

  if ( this->m_bMovieCreated )
    return false;
  FileA = CreateFileA(
            lpFileName: fileName,
            dwDesiredAccess: 0xC0000000,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 2u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  if ( FileA == (HANDLE)-1 )
    return false;
  CloseHandle(hObject: FileA);
  Sleep(dwMilliseconds: 0xAu);
  _V_memset(dest: fullPath, fill: 0, count: 256);
  strcpy(fullPath, fileName);
  c2pstr(a1: fullPath);
  FSMakeFSSpec(a1: 0, a2: 0, a3: fullPath, a4: &sfFile);
  result = (unsigned __int16)CreateMovieFile(
                               a1: &sfFile,
                               a2: 1414942532,
                               a3: -2,
                               a4: -1879048192,
                               a5: &this->m_ResRefNum,
                               a6: &this->m_theMovie) == 0;
  this->m_bMovieCreated = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401700
// Name: public: void CQTVideoFileComposer::SetMovieValues(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQTVideoFileComposer::SetMovieValues(
        CQTVideoFileComposer *this,
        int width,
        int height,
        int timeIntervalFPS)
{
  int fixed; // eax

  if ( this->m_bMovieCreated
    && !this->m_bMovieConfigured
    && width >= 16
    && height >= 16
    && timeIntervalFPS >= 1
    && width <= 4096
    && height <= 4096 )
  {
    this->m_MovieFrameWidth = width;
    this->m_MovieFrameHeight = height;
    this->m_MovieRecordFPS = timeIntervalFPS;
    FixRatio(a1: height, a2: 1);
    fixed = FixRatio(a1: width, a2: 1);
    this->m_theTrack = (struct TrackType **)NewMovieTrack(a1: this->m_theMovie, a2: fixed);
    if ( (unsigned __int16)GetMoviesError() == 0 )
    {
      this->m_theMedia = (struct MediaType **)NewTrackMedia(
                                                a1: this->m_theTrack,
                                                a2: 1986618469,
                                                a3: this->m_MovieRecordFPS,
                                                a4: 0,
                                                a5: 0);
      if ( (unsigned __int16)GetMoviesError() == 0 )
        this->m_bMovieConfigured = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017C0
// Name: public: void CQTVideoFileComposer::SetSourceImageValues(int,int,enum eVideoFrameFormat_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQTVideoFileComposer::SetSourceImageValues(
        CQTVideoFileComposer *this,
        int srcWidth,
        int srcHeight,
        eVideoFrameFormat_t srcImageFormat)
{
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int GWorldPixMap; // ebx
  unsigned __int8 *v9; // eax
  int m_ScrImageMaxCompressedSize; // [esp-Ch] [ebp-10h]

  if ( this->m_bMovieCreated
    && !this->m_bSourceConfigured
    && srcWidth >= 16
    && srcHeight >= 16
    && srcWidth <= 4096
    && srcHeight <= 4096
    && (unsigned int)(srcImageFormat - 1) <= 1 )
  {
    if ( srcImageFormat == cVFF_R8G8B8A8_32Bit )
      v5 = 1111970369;
    else
      v5 = srcImageFormat != cVFF_R8G8B8_24Bit ? 0 : 0x32344247;
    this->m_SrcPixelFormat = v5;
    if ( srcImageFormat == cVFF_R8G8B8A8_32Bit )
      v6 = 4;
    else
      v6 = srcImageFormat != cVFF_R8G8B8_24Bit ? 0 : 3;
    this->m_SrcBytesPerPixel = v6;
    v7 = srcHeight * srcWidth * v6;
    this->m_SrcImageWidth = srcWidth;
    this->m_SrcImageHeight = srcHeight;
    this->m_SrcImageSize = v7;
    if ( v7 > 0 )
    {
      MacSetRect(
        a1: &this->m_SrcImgRect,
        a2: 0,
        a3: 0,
        a4: LOWORD(this->m_SrcImageWidth),
        a5: (unsigned __int16)srcHeight);
      QTNewGWorld(a1: &this->m_theSrcGWorld, a2: this->m_SrcPixelFormat, a3: &this->m_SrcImgRect, a4: 0, a5: 0, a6: 0);
      GWorldPixMap = GetGWorldPixMap(a1: this->m_theSrcGWorld);
      QTSetPixMapHandleGammaLevel(a1: GWorldPixMap, a2: cEncodeGamma);
      if ( (unsigned __int16)GetMaxCompressionSize(
                               a1: GWorldPixMap,
                               a2: &this->m_SrcImgRect,
                               a3: 0,
                               a4: 1023,
                               a5: 1635148593,
                               a6: 0,
                               a7: &this->m_ScrImageMaxCompressedSize) == 0
        && this->m_ScrImageMaxCompressedSize > 0 )
      {
        v9 = (unsigned __int8 *)operator new(size: this->m_SrcImageSize);
        m_ScrImageMaxCompressedSize = this->m_ScrImageMaxCompressedSize;
        this->m_SrcImageBuffer = v9;
        this->m_SrcImageCompressedBuffer = (char **)NewHandle(a1: m_ScrImageMaxCompressedSize);
        this->m_bSourceConfigured = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: void CQTVideoFileComposer::BeginMovieCreation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQTVideoFileComposer::BeginMovieCreation(CQTVideoFileComposer *this)
{
  if ( this->m_bMovieCreated
    && this->m_bMovieConfigured
    && this->m_bSourceConfigured
    && !this->m_bComposingMovie
    && (unsigned __int16)BeginMediaEdits(a1: this->m_theMedia) == 0 )
  {
    this->m_bComposingMovie = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401940
// Name: public: void CQTVideoFileComposer::AppendVideoFrameToMedia(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQTVideoFileComposer::AppendVideoFrameToMedia(
        CQTVideoFileComposer *this,
        int frameNo,
        char *ImageBuffer)
{
  int m_MovieFrameHeight; // edx
  __int16 v5; // cx
  PixMap **GWorldPixMap; // edi
  void *PortHBITMAP; // eax
  int m_SrcImageWidth; // eax
  int m_SrcImageHeight; // ecx
  int m_SrcBytesPerPixel; // ebx
  unsigned int v11; // ebx
  int v12; // edi
  int v13; // eax
  PixMap **v14; // ebx
  int v15; // edi
  DWORD m_SrcImageSize; // [esp-18h] [ebp-268h]
  char fileName2[260]; // [esp+4h] [ebp-24Ch] BYREF
  char basefileName[260]; // [esp+108h] [ebp-148h] BYREF
  tagBITMAPINFOHEADER theHeader; // [esp+20Ch] [ebp-44h] BYREF
  tagBITMAP bmp; // [esp+234h] [ebp-1Ch] BYREF
  PixMap **thePixMap; // [esp+24Ch] [ebp-4h]

  if ( this->m_bComposingMovie && !this->m_bMovieCompleted && ImageBuffer != nullptr )
  {
    if ( g_LogEncodedFrames )
    {
      V_FileBase(in: this->m_FileName, out: basefileName, maxlen: 260);
      if ( g_EncodedFrameOutDir != nullptr )
        V_snprintf(
          pDest: fileName2,
          maxLen: 260,
          pFormat: "%s\\%s-ENCframe%4.4d.bmp",
          g_EncodedFrameOutDir,
          basefileName,
          g_EncodedFrameSequenceCount);
      else
        V_snprintf(
          pDest: fileName2,
          maxLen: 260,
          pFormat: "%s-ENCframe%4.4d.bmp",
          basefileName,
          g_EncodedFrameSequenceCount);
      ++g_EncodedFrameSequenceCount;
      _V_memset(dest: &theHeader, fill: 0, count: 40);
      m_MovieFrameHeight = this->m_MovieFrameHeight;
      theHeader.biWidth = this->m_MovieFrameWidth;
      v5 = 2 * LOWORD(this->m_SrcBytesPerPixel);
      theHeader.biHeight = -m_MovieFrameHeight;
      theHeader.biPlanes = 1;
      m_SrcImageSize = this->m_SrcImageSize;
      theHeader.biBitCount = 4 * v5;
      theHeader.biSize = 40;
      theHeader.biCompression = 0;
      WriteBufferToBMPFile(
        fileName: fileName2,
        pixeBuffer: ImageBuffer,
        pixelBufferSize: m_SrcImageSize,
        infoHeader: &theHeader);
    }
    GWorldPixMap = (PixMap **)GetGWorldPixMap(a1: this->m_theSrcGWorld);
    thePixMap = GWorldPixMap;
    QTSetPixMapHandleGammaLevel(a1: GWorldPixMap, a2: cEncodeGamma);
    LockPixels(a1: GWorldPixMap);
    PortHBITMAP = (void *)GetPortHBITMAP(a1: this->m_theSrcGWorld);
    GetObjectA(h: PortHBITMAP, c: 24, pv: &bmp);
    m_SrcImageWidth = this->m_SrcImageWidth;
    if ( bmp.bmWidth == m_SrcImageWidth )
    {
      m_SrcImageHeight = this->m_SrcImageHeight;
      if ( bmp.bmHeight == m_SrcImageHeight )
      {
        m_SrcBytesPerPixel = this->m_SrcBytesPerPixel;
        if ( bmp.bmBitsPixel == 8 * m_SrcBytesPerPixel )
        {
          v11 = m_SrcImageWidth * m_SrcBytesPerPixel;
          v12 = 0;
          if ( m_SrcImageHeight > 0 )
          {
            do
            {
              memcpy(
                dst: (unsigned __int8 *)bmp.bmBits + v12 * bmp.bmWidthBytes,
                src: (unsigned __int8 *)ImageBuffer,
                count: v11);
              ImageBuffer += v11;
              ++v12;
            }
            while ( v12 < this->m_SrcImageHeight );
          }
          v13 = NewHandle(a1: 4);
          v14 = thePixMap;
          v15 = v13;
          if ( (unsigned __int16)CompressImage(
                                   a1: thePixMap,
                                   a2: &this->m_SrcImgRect,
                                   a3: 1023,
                                   a4: 1635148593,
                                   a5: v13,
                                   a6: *this->m_SrcImageCompressedBuffer) == 0 )
          {
            AddMediaSample(
              a1: this->m_theMedia,
              a2: this->m_SrcImageCompressedBuffer,
              a3: 0,
              a4: *(_DWORD *)(*(_DWORD *)v15 + 44),
              a5: 1,
              a6: v15,
              a7: 1,
              a8: 0,
              a9: 0);
            UnlockPixels(a1: v14);
            DisposeHandle(a1: v15);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B50
// Name: public: void CQTVideoFileComposer::EndMovieCreation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQTVideoFileComposer::EndMovieCreation(CQTVideoFileComposer *this)
{
  int MediaDuration; // eax
  CGrafPort *m_theSrcGWorld; // [esp-2Ch] [ebp-34h]
  struct MovieType **m_theMovie; // [esp-24h] [ebp-2Ch]
  int m_ResRefNum; // [esp-20h] [ebp-28h]
  int resID; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bComposingMovie && !this->m_bMovieCompleted )
  {
    MediaDuration = GetMediaDuration(a1: this->m_theMedia);
    InsertMediaIntoTrack(a1: this->m_theTrack, a2: 0, a3: 0, a4: MediaDuration);
    m_ResRefNum = (unsigned __int16)this->m_ResRefNum;
    m_theMovie = this->m_theMovie;
    resID = -1;
    AddMovieResource(a1: m_theMovie, a2: m_ResRefNum, a3: &resID, a4: 0);
    DisposeHandle(a1: this->m_SrcImageCompressedBuffer);
    m_theSrcGWorld = this->m_theSrcGWorld;
    this->m_SrcImageCompressedBuffer = nullptr;
    DisposeGWorld(a1: m_theSrcGWorld);
    this->m_theSrcGWorld = nullptr;
    this->m_bMovieCompleted = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401BD0
// Name: public: void CQTVideoFileComposer::SaveMovieToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQTVideoFileComposer::SaveMovieToFile(CQTVideoFileComposer *this)
{
  if ( this->m_bMovieCompleted )
  {
    if ( this->m_ResRefNum != 0 )
    {
      CloseMovieFile(a1: (unsigned __int16)this->m_ResRefNum);
      this->m_ResRefNum = 0;
    }
    this->m_bComposingMovie = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C00
// Name: public: void CCachedQTVideoFile::WriteCurrentFrameToBMPFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedQTVideoFile::WriteCurrentFrameToBMPFile(CCachedQTVideoFile *this, const char *theBMPFileName)
{
  WriteBufferToBMPFile(
    fileName: theBMPFileName,
    pixeBuffer: this->m_BitMapData,
    pixelBufferSize: this->m_BitMapDataSize,
    infoHeader: &this->m_BitmapInfo.bmiHeader);
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: public: CQTVideoFileComposer::~CQTVideoFileComposer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQTVideoFileComposer::~CQTVideoFileComposer(CQTVideoFileComposer *this)
{
  if ( this->m_bComposingMovie )
    CQTVideoFileComposer::EndMovieCreation(this);
  if ( this->m_FileName != nullptr )
  {
    operator delete(p: this->m_FileName);
    this->m_FileName = nullptr;
  }
  if ( this->m_SrcImageBuffer != nullptr )
  {
    operator delete(p: this->m_SrcImageBuffer);
    this->m_SrcImageBuffer = nullptr;
  }
  if ( this->m_SrcImageCompressedBuffer != nullptr )
  {
    DisposeHandle(a1: this->m_SrcImageCompressedBuffer);
    this->m_SrcImageCompressedBuffer = nullptr;
  }
  if ( this->m_theSrcGWorld != nullptr )
  {
    DisposeGWorld(a1: this->m_theSrcGWorld);
    this->m_theSrcGWorld = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C80
// Name: void GenerateTestFrame(unsigned long __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall GenerateTestFrame(
        long double a1@<esi:edi>,
        unsigned int *vBuffer,
        int vWidth,
        int vHeight,
        int frame,
        float theTime)
{
  int v6; // edi
  unsigned int *v8; // ebx
  signed int v9; // edx
  int v10; // edx
  int v11; // ebx
  int v12; // edi
  int v13; // ebx
  int v14; // eax
  int v15; // ecx
  unsigned int *v16; // esi
  long double v18; // [esp-Ch] [ebp-10h]
  Color_t col; // [esp+0h] [ebp-4h]
  int vWidtha; // [esp+10h] [ebp+Ch]
  int vWidthb; // [esp+10h] [ebp+Ch]
  int vHeighta; // [esp+14h] [ebp+10h]
  int theTimea; // [esp+1Ch] [ebp+18h]
  int theTimeb; // [esp+1Ch] [ebp+18h]

  v6 = vHeight;
  col = VTLeft[(int)(float)(theTime * 0.5) % 8];
  if ( vHeight > 0 )
  {
    v8 = vBuffer;
    v9 = vWidth / 2;
    for ( vWidtha = vHeight; vWidtha != 0; --vWidtha )
    {
      if ( v9 > 0 )
      {
        memset32(v8, *(_DWORD *)&col, v9);
        v6 = vHeight;
      }
      v8 += vWidth;
    }
  }
  __libm_sse2_sin(x: a1);
  LOBYTE(vWidthb) = (int)(float)((float)(theTime * 127.0) + 128.0);
  __libm_sse2_cos(x: v18);
  BYTE1(vWidthb) = (int)(float)(theTime * 255.0);
  HIWORD(vWidthb) = (unsigned __int8)(int)(float)(128.0 - (float)(theTime * 127.0));
  if ( v6 > 0 )
  {
    v10 = vWidth / 2;
    v11 = 0;
    for ( theTimea = v6; theTimea != 0; --theTimea )
    {
      if ( v10 < vWidth )
        memset32(&vBuffer[v11 + v10], vWidthb, vWidth - v10);
      v11 += vWidth;
    }
  }
  v12 = (int)(float)((float)vWidth * 0.125);
  v13 = v12 + 2 * frame % (vWidth - 2 * v12);
  v14 = vHeight / 2;
  v15 = vHeight / 2 - (int)(float)((float)vHeight * -0.25);
  if ( vHeight / 2 <= v15 )
  {
    theTimeb = 4 * vWidth;
    v16 = &vBuffer[v13 + vWidth * v14];
    vHeighta = v15 - v14 + 1;
    do
    {
      if ( v13 <= v12 + v13 )
        memset32(v16, -16711936, v12 + 1);
      v16 = (unsigned int *)((char *)v16 + theTimeb);
      --vHeighta;
    }
    while ( vHeighta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401E20
// Name: protected: enum CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::NodeColor_t CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::Color(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Color(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( i == -1 )
    return dword_434B68;
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x00401E80
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F90
// Name: public: CCachedQTVideoFile::CCachedQTVideoFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCachedQTVideoFile *__thiscall CCachedQTVideoFile::CCachedQTVideoFile(
        CCachedQTVideoFile *this,
        const char *theQTMovieFileName)
{
  this->m_QTMovieDurationinSec = 0.0;
  this->m_bActive = false;
  this->m_pFileName = nullptr;
  this->m_QTMovie = nullptr;
  this->m_MovieGWorld = nullptr;
  this->m_QTMovieDuration = 0;
  this->m_QTMovieRect = 0;
  memset(dst: (unsigned __int8 *)&this->m_BitmapInfo, value: 0, count: sizeof(this->m_BitmapInfo));
  this->m_BitMapData = nullptr;
  this->m_BitMapDataSize = 0;
  this->m_bIsErrorFrame = false;
  this->m_nLastFrameTime = -11.1;
  CCachedQTVideoFile::OpenQTMovie(this, theQTMovieFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401FF0
// Name: public: bool CCachedQTVideoFile::GetQTMovieSingleFrame(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCachedQTVideoFile::GetQTMovieSingleFrame(CCachedQTVideoFile *this, float targetTime)
{
  int GWorldPixMap; // eax
  HDC PortHDC; // ebx
  HBITMAP PortHBITMAP; // edi
  _DWORD *m_BitMapData; // ecx
  int v8; // eax
  int v9; // [esp-Ch] [ebp-25Ch]
  char fileName2[260]; // [esp+4h] [ebp-24Ch] BYREF
  char basefileName[260]; // [esp+108h] [ebp-148h] BYREF
  tagBITMAPINFO tempInfo; // [esp+20Ch] [ebp-44h] BYREF
  tagBITMAP bmp; // [esp+238h] [ebp-18h] BYREF

  if ( !this->m_bActive )
    return 0;
  if ( targetTime < 0.0 || targetTime >= (float)(this->m_QTMovieDurationinSec + 0.0016666667) )
  {
    if ( !this->m_bIsErrorFrame )
    {
      m_BitMapData = this->m_BitMapData;
      v8 = 0;
      if ( this->m_BitMapDataSize >= 0 && (this->m_BitMapDataSize & 0xFFFFFFFC) != 0 )
      {
        do
          m_BitMapData[v8++] = -65281;
        while ( v8 < this->m_BitMapDataSize >> 2 );
      }
      this->m_bIsErrorFrame = true;
    }
    return 0;
  }
  if ( targetTime == this->m_nLastFrameTime )
    return 1;
  GWorldPixMap = GetGWorldPixMap(a1: this->m_MovieGWorld);
  QTSetPixMapHandleRequestedGammaLevel(a1: GWorldPixMap, a2: cDecodeGamma);
  SetMovieTimeValue(a1: this->m_QTMovie, a2: (int)(float)((float)(targetTime * 600.0) + 0.49000001));
  MoviesTask(a1: this->m_QTMovie, a2: 0);
  PortHDC = (HDC)GetPortHDC(a1: this->m_MovieGWorld);
  PortHBITMAP = (HBITMAP)GetPortHBITMAP(a1: this->m_MovieGWorld);
  if ( GetObjectA(h: PortHBITMAP, c: 24, pv: &bmp) == 0 )
  {
    CCachedQTVideoFile::GetErrorFrame(this);
    return 0;
  }
  _V_memcpy(dest: &tempInfo, src: &this->m_BitmapInfo, count: 44);
  if ( GetDIBits(
         hdc: PortHDC,
         hbm: PortHBITMAP,
         start: 0,
         cLines: LOWORD(bmp.bmHeight),
         lpvBits: this->m_BitMapData,
         lpbmi: &tempInfo,
         usage: 0) == 0 )
    return 0;
  if ( g_LogDecodedFrames )
  {
    V_FileBase(in: this->m_pFileName, out: basefileName, maxlen: 260);
    v9 = (int)(float)((float)(targetTime * 24.0) + 0.49000001);
    if ( g_DecodedFrameOutDir != nullptr )
      V_snprintf(
        pDest: fileName2,
        maxLen: 260,
        pFormat: "%s\\%s-frame%4.4d.bmp",
        g_DecodedFrameOutDir,
        basefileName,
        v9);
    else
      V_snprintf(pDest: fileName2, maxLen: 260, pFormat: "%s-frame%4.4d.bmp", basefileName, v9);
    CCachedQTVideoFile::WriteCurrentFrameToBMPFile(this, theBMPFileName: fileName2);
  }
  this->m_bIsErrorFrame = false;
  this->m_nLastFrameTime = targetTime;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004021E0
// Name: public: bool CCachedQTVideoFile::SendFrameToRemoteConnection(struct CConnectionInfo __near *,float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCachedQTVideoFile::SendFrameToRemoteConnection(
        CCachedQTVideoFile *this,
        CConnectionInfo *theConnection,
        float targetTime,
        unsigned int serverHandle)
{
  int right; // eax
  int m_BitMapDataSize; // edi
  int bottom; // ecx
  int v9; // eax
  CSocketMessageBuilder *m_theDataPump; // ecx
  unsigned int v11; // edi
  CVideoFrameInfo theHdr; // [esp+8h] [ebp-28h] BYREF
  CVidCacheCmdRequestFrameResult AckMsg; // [esp+1Ch] [ebp-14h] BYREF
  float startTime; // [esp+2Ch] [ebp-4h]

  startTime = _Plat_FloatTime();
  if ( CCachedQTVideoFile::GetQTMovieSingleFrame(this, targetTime) != 0 )
  {
    g_QTTimeUsed = _Plat_FloatTime() - startTime;
    _V_memset(dest: &AckMsg, fill: 0, count: 16);
    right = this->m_QTMovieRect.right;
    m_BitMapDataSize = this->m_BitMapDataSize;
    *(_QWORD *)AckMsg.m_data1 = __PAIR64__(LODWORD(targetTime), serverHandle);
    bottom = this->m_QTMovieRect.bottom;
    theHdr.m_nBitMapWidth = right;
    v9 = 2 * bottom * right;
    theHdr.m_nBitmapHeight = bottom;
    m_theDataPump = theConnection->m_theDataPump;
    v11 = m_BitMapDataSize + 36;
    *(_WORD *)&AckMsg.m_Command = 290;
    theHdr.m_nBitmapImageBytes = 2 * v9;
    theHdr.m_nImageTime = targetTime;
    CSocketMessageBuilder::BeginSendPartialDataPacket(
      this: m_theDataPump,
      totalSize: v11,
      data: &AckMsg,
      dataLength: 16);
    CSocketMessageBuilder::SendDataPacket(this: theConnection->m_theDataPump, data: &theHdr, dataLength: 20);
    CSocketMessageBuilder::SendDataPacket(
      this: theConnection->m_theDataPump,
      data: this->m_BitMapData,
      dataLength: this->m_BitMapDataSize);
    if ( g_bVerbose )
      printf(format: "Image Sent: %dx%d (%d bytes)\n", this->m_QTMovieRect.right, this->m_QTMovieRect.bottom, v11);
    return 1;
  }
  else
  {
    if ( g_bShowErrs )
      printf(format: " error in SendFrameToRemoteConnection->GetQTMovieSingleFrame\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004022E0
// Name: void TestQuickTimeMovieDecoding(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestQuickTimeMovieDecoding()
{
  __int16 v0; // ax
  bool v1; // zf
  CCachedQTVideoFile *v2; // eax
  CCachedQTVideoFile *v3; // esi

  v0 = InitializeQTML(a1: 0);
  if ( v0 == -2093 )
  {
    _Plat_MessageBox(
      a1: "VideoCache ERROR",
      a2: "ERROR: QuickTime is not installed on this system.  It is needed in order for the SFM Video Cache service to run");
  }
  else
  {
    v1 = v0 == 0;
    if ( v0 == 0 )
      v1 = (unsigned __int16)EnterMovies() == 0;
    if ( v1 )
    {
      v2 = (CCachedQTVideoFile *)operator new(size: 0x5Cu);
      if ( v2 != nullptr )
        v3 = CCachedQTVideoFile::CCachedQTVideoFile(
               this: v2,
               theQTMovieFileName: "D:\\sfm\\main\\content\\tf_movies\\elements\\sessions\\mtt_spy.cache\\40e9c337-8037-4d95-bf83-7396801ac607.mov");
      else
        v3 = nullptr;
      CCachedQTVideoFile::GetQTMovieSingleFrame(this: v3, targetTime: 0.0);
      WriteBufferToBMPFile(
        fileName: "d:\\testQT-001.bmp",
        pixeBuffer: v3->m_BitMapData,
        pixelBufferSize: v3->m_BitMapDataSize,
        infoHeader: &v3->m_BitmapInfo.bmiHeader);
      CCachedQTVideoFile::GetQTMovieSingleFrame(this: v3, targetTime: v3->m_QTMovieDurationinSec * 0.5);
      WriteBufferToBMPFile(
        fileName: "d:\\testQT-002.bmp",
        pixeBuffer: v3->m_BitMapData,
        pixelBufferSize: v3->m_BitMapDataSize,
        infoHeader: &v3->m_BitmapInfo.bmiHeader);
      CCachedQTVideoFile::GetQTMovieSingleFrame(this: v3, targetTime: v3->m_QTMovieDurationinSec);
      WriteBufferToBMPFile(
        fileName: "d:\\testQT-003.bmp",
        pixeBuffer: v3->m_BitMapData,
        pixelBufferSize: v3->m_BitMapDataSize,
        infoHeader: &v3->m_BitmapInfo.bmiHeader);
      CCachedQTVideoFile::GetQTMovieSingleFrame(this: v3, targetTime: v3->m_QTMovieDurationinSec * 0.66666669);
      WriteBufferToBMPFile(
        fileName: "d:\\testQT-004.bmp",
        pixeBuffer: v3->m_BitMapData,
        pixelBufferSize: v3->m_BitMapDataSize,
        infoHeader: &v3->m_BitmapInfo.bmiHeader);
      CCachedQTVideoFile::GetQTMovieSingleFrame(this: v3, targetTime: v3->m_QTMovieDurationinSec * 0.33333331);
      WriteBufferToBMPFile(
        fileName: "d:\\testQT-005.bmp",
        pixeBuffer: v3->m_BitMapData,
        pixelBufferSize: v3->m_BitMapDataSize,
        infoHeader: &v3->m_BitmapInfo.bmiHeader);
      if ( v3->m_BitMapData != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_BitMapData);
      if ( v3->m_QTMovie != nullptr )
      {
        DisposeMovie(a1: v3->m_QTMovie);
        v3->m_QTMovie = nullptr;
      }
      if ( v3->m_pFileName != nullptr )
      {
        operator delete(p: v3->m_pFileName);
        v3->m_pFileName = nullptr;
      }
      operator delete(p: v3);
      ExitMovies();
      TerminateQTML();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402480
// Name: void TestQuickTimeMovieEncoding(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestQuickTimeMovieEncoding()
{
  __int16 v0; // ax
  bool v1; // zf
  unsigned int *v2; // ebx
  CQTVideoFileComposer *v3; // eax
  long double v4; // rdi

  if ( g_bVerbose )
    printf(format: "Running H.264 Encoding test\n");
  v0 = InitializeQTML(a1: 0);
  if ( v0 == -2093 )
  {
    _Plat_MessageBox(
      a1: "VideoCache ERROR",
      a2: "ERROR: QuickTime is not installed on this system.  It is needed in order for the SFM Video Cache service to run");
  }
  else
  {
    v1 = v0 == 0;
    if ( v0 == 0 )
      v1 = (unsigned __int16)EnterMovies() == 0;
    if ( v1 )
    {
      v2 = (unsigned int *)operator new(size: 0x384000u);
      v3 = (CQTVideoFileComposer *)operator new(size: 0x54u);
      if ( v3 != nullptr )
        LODWORD(v4) = CQTVideoFileComposer::CQTVideoFileComposer(this: v3);
      else
        LODWORD(v4) = 0;
      if ( g_bVerbose )
        printf(
          format: "Creating test movie file %s \n"
          "Source Resolution = %d x %d\n"
          "Movie Resolution = %d x %d\n"
          "Duration %d seconds at %d FPS  ( %d frames)\n",
          "d:\\testmovie2.mov",
          1280,
          720,
          1280,
          720,
          10,
          24,
          240);
      CQTVideoFileComposer::CreateNewMovie(this: (CQTVideoFileComposer *)LODWORD(v4), fileName: "d:\\testmovie2.mov");
      CQTVideoFileComposer::SetMovieValues(
        this: (CQTVideoFileComposer *)LODWORD(v4),
        width: 1280,
        height: 720,
        timeIntervalFPS: 24);
      CQTVideoFileComposer::SetSourceImageValues(
        this: (CQTVideoFileComposer *)LODWORD(v4),
        srcWidth: 1280,
        srcHeight: 720,
        srcImageFormat: cVFF_R8G8B8A8_32Bit);
      if ( *(_BYTE *)LODWORD(v4) != 0
        && *(_BYTE *)(LODWORD(v4) + 1) != 0
        && *(_BYTE *)(LODWORD(v4) + 2) != 0
        && *(_BYTE *)(LODWORD(v4) + 3) == 0
        && (unsigned __int16)BeginMediaEdits(a1: *(_DWORD *)(LODWORD(v4) + 80)) == 0 )
      {
        *(_BYTE *)(LODWORD(v4) + 3) = 1;
      }
      HIDWORD(v4) = 0;
      do
      {
        if ( g_bVerbose )
          printf(format: ".");
        GenerateTestFrame(
          a1: v4,
          vBuffer: v2,
          vWidth: 1280,
          vHeight: 720,
          frame: SHIDWORD(v4),
          theTime: (float)SHIDWORD(v4) * 0.041666668);
        CQTVideoFileComposer::AppendVideoFrameToMedia(
          this: (CQTVideoFileComposer *)LODWORD(v4),
          frameNo: SHIDWORD(v4),
          ImageBuffer: (char *)v2);
        ++HIDWORD(v4);
      }
      while ( SHIDWORD(v4) < 240 );
      if ( g_bVerbose )
        printf(format: "!");
      CQTVideoFileComposer::EndMovieCreation(this: (CQTVideoFileComposer *)LODWORD(v4));
      if ( *(_BYTE *)(LODWORD(v4) + 4) != 0 )
      {
        if ( *(_WORD *)(LODWORD(v4) + 68) != 0 )
        {
          CloseMovieFile(a1: *(unsigned __int16 *)(LODWORD(v4) + 68));
          *(_WORD *)(LODWORD(v4) + 68) = 0;
        }
        *(_BYTE *)(LODWORD(v4) + 3) = 0;
      }
      CQTVideoFileComposer::~CQTVideoFileComposer(this: (CQTVideoFileComposer *)LODWORD(v4));
      operator delete(p: (void *)LODWORD(v4));
      if ( g_bVerbose )
        printf(format: "\n");
      ExitMovies();
      TerminateQTML();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402680
// Name: public: int CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( i == -1 )
    return dword_434B64;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004026E0
// Name: public: int CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00402740
// Name: public: int CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( i == -1 )
    return dword_434B60;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004027A0
// Name: public: bool CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( m_Parent == -1 )
    return dword_434B60 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00402850
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        const CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402940
// Name: public: int CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402A00
// Name: public: bool CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00402AB0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_434B60 = -1;
      dword_434B64 = -1;
      dword_434B68 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00402C60
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00402DD0
// Name: public: int CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::Find(struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        const CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00402EC0
// Name: public: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402F80
// Name: public: int CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_434B60 = -1;
      dword_434B64 = -1;
      dword_434B68 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_434B60 = -1;
      dword_434B64 = -1;
      dword_434B68 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403020
// Name: public: int CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_434B60 = -1;
    dword_434B64 = -1;
    dword_434B68 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403190
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004035F0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::RemoveRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RemoveRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v6; // ecx
  int m_Parent; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v9; // ecx
  int m_Right; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v11; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v12; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v13; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v14; // edx
  int m_Left; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v16; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v17; // edx
  int v18; // edx
  int *v19; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v20; // edx
  int v21; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v22; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v26; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v27; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v28; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v29; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v30; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v31; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v32; // edx
  int v33; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v34; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v35; // edx
  int v36; // edx
  int *v37; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v38; // edx
  int v39; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v40; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v41; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v42; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v43; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v44; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v45; // ecx

  v2 = elem;
  if ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    do
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      if ( v5->m_Tag != 1 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( v2 == -1 )
        v6 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v6 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v6->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_434B60 = -1;
        dword_434B64 = -1;
        dword_434B68 = 1;
      }
      if ( m_Parent == -1 )
      {
        v8 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      }
      else
      {
        v8 = &this->m_Elements.m_pMemory[m_Parent];
        v2 = elem;
      }
      if ( v2 == v8->m_Left )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Parent == -1 )
          v9 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v9 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v9->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v11 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v11 = &this->m_Elements.m_pMemory[m_Right];
        if ( v11->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( elem == -1 )
            v12 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v12 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v12->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Parent == -1 )
            v13 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v13 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v13->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_Right];
        m_Left = v14->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Left == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Left];
        if ( v16->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Right == -1 )
            v17 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v17 = &this->m_Elements.m_pMemory[m_Right];
          v18 = v17->m_Right;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          v19 = v18 == -1
              ? &`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v18];
          if ( v19[3] == 1 )
            goto LABEL_146;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_Right];
        v21 = v20->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( v21 == -1 )
          v22 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v22 = &this->m_Elements.m_pMemory[v21];
        if ( v22->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Right == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v23->m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( elem == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Parent == -1 )
            v25 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v25 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v25->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Parent == -1 )
          v26 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v26->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v27 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v27 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v27->m_Right].m_Tag = 1;
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: m_Parent);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Parent == -1 )
          v28 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v28->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v29 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v29 = &this->m_Elements.m_pMemory[m_Right];
        if ( v29->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( elem == -1 )
            v30 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v30->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Parent == -1 )
            v31 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v31->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v32 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v32 = &this->m_Elements.m_pMemory[m_Right];
        v33 = v32->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( v33 == -1 )
          v34 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v34 = &this->m_Elements.m_pMemory[v33];
        if ( v34->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Right == -1 )
            v35 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v35 = &this->m_Elements.m_pMemory[m_Right];
          v36 = v35->m_Left;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          v37 = v36 == -1
              ? &`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v36];
          if ( v37[3] == 1 )
          {
LABEL_146:
            if ( m_Right != -1 )
            {
              this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
              v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            }
            elem = m_Parent;
            goto LABEL_188;
          }
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v38 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v38 = &this->m_Elements.m_pMemory[m_Right];
        v39 = v38->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( v39 == -1 )
          v40 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v40 = &this->m_Elements.m_pMemory[v39];
        if ( v40->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Right == -1 )
            v41 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v41 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v41->m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( elem == -1 )
            v42 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v42 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v42->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Parent == -1 )
            v43 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v43 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v43->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Parent == -1 )
          v44 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v44 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v44->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_434B60 = -1;
          dword_434B64 = -1;
          dword_434B68 = 1;
        }
        if ( m_Right == -1 )
          v45 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v45 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v45->m_Left].m_Tag = 1;
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: m_Parent);
      }
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      elem = this->m_Root;
LABEL_188:
      v2 = elem;
    }
    while ( elem != this->m_Root );
  }
  this->m_Elements.m_pMemory[v2].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404010
// Name: public: CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404070
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004040E0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int,class CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Node_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Unlink(
        CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Left; // edi
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *v7; // eax
  int v8; // ebx
  int v9; // ebx
  CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int> >::NodeColor_t ycolor; // [esp+Ch] [ebp-8h]
  int x; // [esp+10h] [ebp-4h]

  m_Left = elem;
  if ( elem != -1 )
  {
    v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_434B60 = -1;
      dword_434B64 = -1;
      dword_434B68 = 1;
    }
    if ( this->m_Elements.m_pMemory[elem].m_Left != -1 )
    {
      if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
             this,
             i: elem) == -1 )
      {
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      }
      else
      {
        v5 = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
               this,
               i: elem);
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
        m_Left = v5;
        while ( 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          v6 = m_Left == -1
             ? &`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
             : (int *)&this->m_Elements.m_pMemory[m_Left];
          if ( *v6 == -1 )
            break;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_434B60 = -1;
            dword_434B64 = -1;
            dword_434B68 = 1;
          }
          if ( m_Left == -1 )
            m_Left = `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
        }
      }
    }
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
      `CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_434B60 = -1;
      dword_434B64 = -1;
      dword_434B68 = 1;
    }
    if ( m_Left == -1 )
      v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v7 = &this->m_Elements.m_pMemory[m_Left];
    if ( v7->m_Left == -1 )
    {
      x = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
            this,
            i: m_Left);
      v8 = x;
    }
    else
    {
      v8 = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::LeftChild(
             this,
             i: m_Left);
      x = v8;
    }
    if ( v8 != -1 )
      this->m_Elements.m_pMemory[v8].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                                  this,
                                                  i: m_Left);
    if ( m_Left == this->m_Root )
    {
      this->m_Root = v8;
    }
    else if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsLeftChild(
                this,
                i: m_Left) )
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Left = v8;
    }
    else
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Right = v8;
    }
    ycolor = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Color(
               this,
               i: m_Left);
    if ( m_Left != elem )
    {
      v9 = m_Left;
      this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                                      this,
                                                      i: elem);
      this->m_Elements.m_pMemory[v9].m_Right = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
                                                 this,
                                                 i: elem);
      this->m_Elements.m_pMemory[v9].m_Left = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::LeftChild(
                                                this,
                                                i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = m_Left;
      }
      else if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::IsLeftChild(
                  this,
                  i: elem) )
      {
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Left = m_Left;
      }
      else
      {
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Right = m_Left;
      }
      if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::LeftChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::LeftChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RightChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      this->m_Elements.m_pMemory[v9].m_Tag = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Color(
                                               this,
                                               i: elem);
      v8 = x;
    }
    if ( v8 != -1 && ycolor == BLACK )
      CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RemoveRebalance(
        this,
        elem: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004043A0
// Name: bool InitVideoServerMode(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitVideoServerMode()
{
  CSocketConnection *v1; // eax
  CSocketConnection *v2; // eax
  const char *LastErrorString; // eax

  if ( g_bVerbose )
    printf(format: "InitVideoServerMode called\n");
  SocketLibInit();
  if ( g_IPCConnection != nullptr )
    return 0;
  v1 = (CSocketConnection *)operator new(size: 0x50u);
  if ( v1 != nullptr )
    v2 = CSocketConnection::CSocketConnection(this: v1);
  else
    v2 = nullptr;
  g_IPCConnection = v2;
  CSocketConnection::Init(this: v2, connectionType: CT_SERVER, socketProtocol: SP_TCP);
  if ( g_bVerbose )
    printf(format: "Listening for connection on port %d \n", 26832);
  if ( CSocketConnection::Listen(this: g_IPCConnection, localPort: 0x68D0u, numAllowedConnections: 2) != SOCKET_SUCCESS )
    return 0;
  if ( g_bVerbose )
  {
    LastErrorString = CSocketConnection::GetLastErrorString(this: g_IPCConnection);
    printf(format: "Listen returned code '%s' \n", LastErrorString);
  }
  CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::RemoveAll(this: &g_VideoMap.m_Tree);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404450
// Name: public: int CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Insert(unsigned int const __near &,class CCachedQTVideoFile __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Insert(
        CUtlMap<unsigned int,CCachedQTVideoFile *,int> *this,
        unsigned int *key,
        int insert)
{
  CCachedQTVideoFile *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CCachedQTVideoFile **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004044D0
// Name: public: bool CUtlMap<unsigned int,class CCachedQTVideoFile __near *,int>::Remove(unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Remove(
        CUtlMap<unsigned int,CCachedQTVideoFile *,int> *this,
        unsigned int *key)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t dummyNode; // [esp+8h] [ebp-8h] BYREF

  dummyNode.key = *key;
  v3 = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  v4 = v3;
  if ( v3 == -1 )
    return 0;
  CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Unlink(
    this: &this->m_Tree,
    elem: v3);
  v5 = v4;
  this->m_Tree.m_Elements.m_pMemory[v5].m_Left = v4;
  this->m_Tree.m_Elements.m_pMemory[v5].m_Right = this->m_Tree.m_FirstFree;
  --this->m_Tree.m_NumElements;
  this->m_Tree.m_FirstFree = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404530
// Name: void ProcessNetworkMessage(struct MessageHeader_t const __near &,unsigned char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessNetworkMessage(unsigned int header, unsigned __int8 *message, float userContext)
{
  const MessageHeader_t *v3; // edi
  bool v4; // bl
  unsigned __int8 *v5; // esi
  CSocketMessageBuilder *v6; // ecx
  bool v7; // bl
  eVidCacheError_t v8; // edx
  eVidCacheError_t v9; // esi
  int v10; // edi
  CCachedQTVideoFile *elem; // edi
  int Inorder; // esi
  CCachedQTVideoFile *v13; // eax
  bool v14; // bl
  unsigned int v15; // eax
  CConnectionInfo *v16; // esi
  int bottom; // ecx
  CCachedQTVideoFile *m_QTMovieDurationinSec_low; // xmm0_4
  int m_EndPointIndex; // eax
  CSocketMessageBuilder *m_theDataPump; // ecx
  bool v21; // zf
  unsigned int v22; // esi
  CCachedQTVideoFile *v23; // esi
  float v24; // xmm0_4
  unsigned int v25; // esi
  int v26; // eax
  float v27; // edi
  int v28; // eax
  _DWORD *v29; // edi
  const char *v30; // esi
  CQTVideoFileComposer *v31; // eax
  char v32; // bl
  CQTVideoFileComposer *v33; // esi
  CCachedQTVideoFile *v34; // eax
  int v35; // ebx
  int m_SrcImageSize; // edx
  unsigned int v37; // esi
  CSocketConnection *m_theConnection; // [esp+0h] [ebp-4Ch]
  CVidCacheCmdEndEncodingResult AckMsg; // [esp+1Ch] [ebp-30h] BYREF
  int data; // [esp+2Ch] [ebp-20h] BYREF
  int localHandle; // [esp+30h] [ebp-1Ch] BYREF
  int v42; // [esp+34h] [ebp-18h]
  CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t search; // [esp+38h] [ebp-14h] BYREF
  eVidCacheError_t err; // [esp+40h] [ebp-Ch]
  CCachedQTVideoFile *pVidFile; // [esp+44h] [ebp-8h] BYREF
  bool success[4]; // [esp+48h] [ebp-4h]

  v3 = *(const MessageHeader_t **)header;
  header = (unsigned int)v3;
  if ( (unsigned int)v3 < 0x10 )
  {
    if ( g_bVerbose )
      printf(format: "Error - unable to identify incoming msg packet, size = %d bytes\n", v3);
    return;
  }
  v4 = g_bVerbose;
  if ( g_bVerbose )
  {
    printf(format: "Remote Command Received: ");
    v4 = g_bVerbose;
  }
  v5 = message;
  switch ( *message )
  {
    case 1u:
      if ( v4 )
        printf(format: "PING\n");
      _V_memset(dest: &localHandle, fill: 0, count: 16);
      v6 = *(CSocketMessageBuilder **)(LODWORD(userContext) + 8);
      LOWORD(localHandle) = 259;
      CSocketMessageBuilder::SendDataPacket(this: v6, data: &localHandle, dataLength: 16);
      goto LABEL_137;
    case 2u:
      if ( v4 )
        printf(format: "QUIT\n");
      g_bRunning = false;
      goto LABEL_137;
    case 3u:
      if ( v4 )
        printf(format: "ACK\n");
      goto LABEL_137;
    case 9u:
      if ( v4 )
        printf(format: "Begin Video Cache Session\n");
      v7 = g_SessionID == 0;
      LOBYTE(header) = g_SessionID == 0;
      if ( g_SessionID != 0 )
      {
        LOBYTE(err) = 0;
      }
      else
      {
        g_SessionID = 1;
        LOBYTE(err) = 1;
      }
      v8 = v7 ? cVCE_NoErr : cVCE_CacheSessionOpen;
      if ( v7
        && (!CheckVideoFrameSize(width: *((_DWORD *)v5 + 4), height: *((_DWORD *)v5 + 5))
         || (unsigned int)(*((_DWORD *)v5 + 6) - 1) > 1) )
      {
        v7 = false;
        LOBYTE(header) = 0;
        v8 = cVCE_BadFormatData;
      }
      CVidCacheCmdBeginCacheSessionResult::CVidCacheCmdBeginCacheSessionResult(
        this: (CVidCacheCmdBeginCacheSessionResult *)&localHandle,
        localId: *((_DWORD *)v5 + 1),
        id: err,
        success: header,
        err: v8);
      CSocketMessageBuilder::SendDataPacket(
        this: *(CSocketMessageBuilder **)(LODWORD(userContext) + 8),
        pConnection: *(CSocketConnection **)LODWORD(userContext),
        endpoint: *(_DWORD *)(LODWORD(userContext) + 4),
        data: &localHandle,
        dataLength: 16);
      if ( v7 )
        g_SessionFrameInfo = *(CVideoCacheSessionInfo *)(v5 + 16);
      goto LABEL_137;
    case 0xAu:
      if ( v4 )
        printf(format: "*cVCC_BeginCacheSessionResult*\n");
      goto LABEL_137;
    case 0xCu:
      if ( v4 )
        printf(format: "End Video Cache Session\n");
      v9 = CheckSessionId(pCmd: (CVidCmd *)v5);
      if ( v9 == cVCE_NoErr )
      {
        g_SessionID = 0;
        _V_memset(dest: &g_SessionFrameInfo, fill: 0, count: 12);
      }
      CVidCacheCmdAck::CVidCacheCmdAck(this: (CVidCacheCmdAck *)&localHandle, err: v9);
      CSocketMessageBuilder::SendDataPacket(
        this: *(CSocketMessageBuilder **)(LODWORD(userContext) + 8),
        pConnection: *(CSocketConnection **)LODWORD(userContext),
        endpoint: *(_DWORD *)(LODWORD(userContext) + 4),
        data: &localHandle,
        dataLength: 16);
      goto LABEL_137;
    case 0x11u:
      if ( v4 )
      {
        printf(format: "CACHE VIDEO FILE\n");
        v4 = g_bVerbose;
      }
      v10 = *((_DWORD *)v5 + 2);
      search.elem = *((CCachedQTVideoFile **)v5 + 1);
      err = CheckSessionId(pCmd: (CVidCmd *)v5);
      if ( err == cVCE_NoErr && (v10 < 2 || header != v10 + 16) )
      {
        if ( g_bShowErrs )
        {
          printf(format: "Error in length of file name to cache\n ");
          v4 = g_bVerbose;
        }
        err = cVCE_InvalidFileName;
      }
      elem = nullptr;
      pVidFile = (CCachedQTVideoFile *)(v5 + 16);
      success[0] = false;
      header = 0;
      if ( err != cVCE_NoErr )
        goto LABEL_54;
      Inorder = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::FirstInorder(this: &g_VideoMap.m_Tree);
      if ( Inorder != -1 )
      {
        while ( 1 )
        {
          elem = g_VideoMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
          if ( elem != nullptr && _V_stricmp(s1: elem->m_pFileName, s2: (const char *)&pVidFile->m_bActive) == 0 )
            break;
          Inorder = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::NextInorder(
                      this: &g_VideoMap.m_Tree,
                      i: Inorder);
          if ( Inorder == -1 )
          {
            v4 = g_bVerbose;
            goto LABEL_47;
          }
        }
        header = g_VideoMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key;
        if ( g_bVerbose )
          printf(format: "Video File Already in Cache\n");
        goto LABEL_53;
      }
LABEL_47:
      if ( v4 )
        printf(format: "Caching Video file: %s\n", (const char *)&pVidFile->m_bActive);
      v13 = (CCachedQTVideoFile *)operator new(size: 0x5Cu);
      if ( v13 != nullptr )
        elem = CCachedQTVideoFile::CCachedQTVideoFile(this: v13, theQTMovieFileName: (const char *)&pVidFile->m_bActive);
      else
        elem = nullptr;
      v21 = !elem->m_bActive;
      pVidFile = elem;
      if ( !v21 )
      {
        header = ++g_LastServerHandleIssued;
        CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Insert(this: &g_VideoMap, key: &header, insert: (int)&pVidFile);
        if ( g_bVerbose )
          printf(format: "File Successfully Cached\n");
LABEL_53:
        success[0] = true;
        goto LABEL_54;
      }
      CCachedQTVideoFile::`scalar deleting destructor'(this: elem, a2: 1u);
      elem = nullptr;
      if ( g_bVerbose )
        printf(format: "Cache File Request Failed\n");
      success[0] = false;
LABEL_54:
      CVidCacheCmdCacheFileResult::CVidCacheCmdCacheFileResult(
        this: (CVidCacheCmdCacheFileResult *)&AckMsg,
        localId: (int)search.elem,
        success: success[0],
        err,
        serverHandle: header);
      v14 = success[0];
      v15 = 16;
      if ( success[0] )
        v15 = 36;
      v16 = (CConnectionInfo *)LODWORD(userContext);
      CSocketMessageBuilder::BeginSendPartialDataPacket(
        this: *(CSocketMessageBuilder **)(LODWORD(userContext) + 8),
        pConnection: *(CSocketConnection **)LODWORD(userContext),
        endpoint: *(_DWORD *)(LODWORD(userContext) + 4),
        totalSize: v15,
        data: &AckMsg,
        dataLength: 16);
      if ( v14 )
      {
        bottom = elem->m_QTMovieRect.bottom;
        m_QTMovieDurationinSec_low = (CCachedQTVideoFile *)LODWORD(elem->m_QTMovieDurationinSec);
        data = elem->m_QTMovieRect.right;
        v42 = 4 * bottom * data;
        m_EndPointIndex = v16->m_EndPointIndex;
        localHandle = bottom;
        m_theConnection = v16->m_theConnection;
        m_theDataPump = v16->m_theDataPump;
        search.elem = m_QTMovieDurationinSec_low;
        CSocketMessageBuilder::SendDataPacket(
          this: m_theDataPump,
          pConnection: m_theConnection,
          endpoint: m_EndPointIndex,
          &data,
          dataLength: 20);
        if ( g_bVerbose )
          printf(format: "Video file Server Handle Returned = %d\n", header);
      }
LABEL_137:
      userContext = _Plat_FloatTime() - g_fStrobeStart;
      if ( g_bVerbose )
        printf(
          format: "Total Time to process command  = %.2f ms   (%.2f QuickTime,  %.2f non-QT)\n",
          (float)(userContext * 1000.0),
          (float)(g_QTTimeUsed * 1000.0),
          (float)((float)(userContext - g_QTTimeUsed) * 1000.0));
      return;
    case 0x12u:
      if ( v4 )
        printf(format: "*cVCC_CacheFileResult* Unexpected\n");
      goto LABEL_137;
    case 0x17u:
      if ( v4 )
        printf(format: "*cVCC_UnCacheFile*\n");
      v22 = *((_DWORD *)v5 + 1);
      search.key = v22;
      if ( CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Find(
             this: &g_VideoMap.m_Tree,
             &search) == -1 )
      {
        v23 = g_VideoMap.m_Tree.m_Elements.m_pMemory[-1].m_Data.elem;
        header = -1;
        CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Remove(this: &g_VideoMap, key: &header);
        if ( v23 != nullptr )
          CCachedQTVideoFile::`scalar deleting destructor'(this: v23, a2: 1u);
      }
      else if ( g_bShowErrs )
      {
        printf(format: "Recevied Command to unchache unknown video file, handle = %d\n", v22);
      }
      CVidCacheCmdAck::CVidCacheCmdAck(this: (CVidCacheCmdAck *)&AckMsg, success: 0);
      CSocketMessageBuilder::SendDataPacket(
        this: *(CSocketMessageBuilder **)(LODWORD(userContext) + 8),
        data: &AckMsg,
        dataLength: 16);
      goto LABEL_137;
    case 0x18u:
      if ( v4 )
        printf(format: "*cVCC_UnCacheFile*\n");
      goto LABEL_137;
    case 0x21u:
      if ( v4 )
      {
        printf(format: "cVCC_RequestFrame\n");
        v4 = g_bVerbose;
      }
      v24 = *((float *)v5 + 2);
      v25 = *((_DWORD *)v5 + 1);
      header = LODWORD(v24);
      if ( v4 )
        printf(format: "Requests Frame: Video # %d, Time T=%f\n", v25, v24);
      search.key = v25;
      v26 = CUtlRBTree<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int,CUtlMap<unsigned int,CCachedQTVideoFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CCachedQTVideoFile *,int>::Node_t,int>,int>>::Find(
              this: &g_VideoMap.m_Tree,
              &search);
      v27 = userContext;
      if ( v26 == -1
        || CCachedQTVideoFile::SendFrameToRemoteConnection(
             this: g_VideoMap.m_Tree.m_Elements.m_pMemory[v26].m_Data.elem,
             theConnection: (CConnectionInfo *)LODWORD(userContext),
             targetTime: *(float *)&header,
             serverHandle: v25) == 0 )
      {
        CVidCacheCmdRequestFrameResult::CVidCacheCmdRequestFrameResult(
          this: (CVidCacheCmdRequestFrameResult *)&AckMsg,
          serverHandle: v25,
          frameTime: *(float *)&header,
          success: 0);
        CSocketMessageBuilder::SendDataPacket(
          this: *(CSocketMessageBuilder **)(LODWORD(v27) + 8),
          pConnection: *(CSocketConnection **)LODWORD(v27),
          endpoint: *(_DWORD *)(LODWORD(v27) + 4),
          data: &AckMsg,
          dataLength: 16);
      }
      goto LABEL_137;
    case 0x22u:
      if ( v4 )
        printf(format: "*cVCC_RequestFrameResult*  ?? \n");
      goto LABEL_137;
    case 0x31u:
      if ( v4 )
        printf(format: "ENCODE VIDEO TO A FILE\n");
      v28 = *((_DWORD *)v5 + 2);
      search.elem = *((CCachedQTVideoFile **)v5 + 1);
      if ( v28 >= 2 && v3 == (const MessageHeader_t *)(v28 + 52) )
      {
        v29 = v5 + 16;
        v30 = (const char *)(v5 + 52);
        if ( g_pCurEncoder != nullptr )
        {
          if ( g_bShowErrs )
            printf(format: "Error - Already encoding a movie\n ");
        }
        else
        {
          v31 = (CQTVideoFileComposer *)operator new(size: 0x54u);
          if ( v31 != nullptr )
            g_pCurEncoder = CQTVideoFileComposer::CQTVideoFileComposer(this: v31);
          else
            g_pCurEncoder = nullptr;
          _V_memcpy(dest: &g_EncodeSessionParams, src: v29, count: 36);
          v32 = 0;
          LOBYTE(header) = 0;
          if ( CQTVideoFileComposer::CreateNewMovie(this: g_pCurEncoder, fileName: v30) )
          {
            CQTVideoFileComposer::SetMovieValues(
              this: g_pCurEncoder,
              width: v29[2],
              height: v29[3],
              timeIntervalFPS: *v29);
            CQTVideoFileComposer::SetSourceImageValues(
              this: g_pCurEncoder,
              srcWidth: v29[2],
              srcHeight: v29[3],
              srcImageFormat: (eVideoFrameFormat_t)v29[4]);
            CQTVideoFileComposer::BeginMovieCreation(this: g_pCurEncoder);
            v32 = 1;
            LOBYTE(header) = 1;
            g_hEncodeSession = ++g_LastServerHandleIssued;
          }
          CVidCacheCmdBeginEncodingResult::CVidCacheCmdBeginEncodingResult(
            this: (CVidCacheCmdBeginEncodingResult *)&AckMsg,
            localId: (int)search.elem,
            success: header,
            serverHandle: g_hEncodeSession);
          CSocketMessageBuilder::SendDataPacket(
            this: *(CSocketMessageBuilder **)(LODWORD(userContext) + 8),
            pConnection: *(CSocketConnection **)LODWORD(userContext),
            endpoint: *(_DWORD *)(LODWORD(userContext) + 4),
            data: &AckMsg,
            dataLength: 16);
          if ( g_bVerbose )
            printf(format: "Video file Encoding Session Handle Returned = %d\n", 0);
          if ( v32 == 0 )
          {
            if ( g_pCurEncoder != nullptr )
            {
              v33 = g_pCurEncoder;
              CQTVideoFileComposer::~CQTVideoFileComposer(this: g_pCurEncoder);
              operator delete(p: v33);
              g_pCurEncoder = nullptr;
            }
            g_hEncodeSession = 0;
          }
        }
      }
      else if ( g_bShowErrs )
      {
        printf(format: "Error in length of cache file name\n ");
      }
      goto LABEL_137;
    case 0x32u:
      if ( v4 )
        printf(format: "*cVCC_BeginEncodingResult*\n");
      goto LABEL_137;
    case 0x37u:
      if ( v4 )
        printf(format: "Append Frame to Movie being Encoded\n");
      v34 = *((CCachedQTVideoFile **)v5 + 1);
      v35 = *((_DWORD *)v5 + 2);
      search.elem = v34;
      LOBYTE(header) = 0;
      if ( g_pCurEncoder != nullptr )
      {
        if ( (CCachedQTVideoFile *)g_hEncodeSession == v34 )
        {
          m_SrcImageSize = g_pCurEncoder->m_SrcImageSize;
          if ( &v3[-4] == (const MessageHeader_t *)m_SrcImageSize )
          {
            CQTVideoFileComposer::AppendVideoFrameToMedia(
              this: g_pCurEncoder,
              frameNo: v35,
              ImageBuffer: (char *)v5 + 16);
            LOBYTE(header) = 1;
          }
          else if ( g_bShowErrs )
          {
            printf(
              format: "ERROR - Expected Image data buffer of %d bytes, received %d bytes instead\n",
              m_SrcImageSize,
              &v3[-4]);
          }
        }
        else if ( g_bShowErrs )
        {
          printf(format: "Recevied command had wrong encode session handle\n");
        }
      }
      else if ( g_bShowErrs )
      {
        printf(format: "Received command to append frame to video while no encoding session was active");
      }
      CVidCacheCmdEncodeFrameResult::CVidCacheCmdEncodeFrameResult(
        this: (CVidCacheCmdEncodeFrameResult *)&AckMsg,
        serverHandle: (unsigned int)search.elem,
        frameNum: v35,
        success: header);
      CSocketMessageBuilder::SendDataPacket(
        this: *(CSocketMessageBuilder **)(LODWORD(userContext) + 8),
        data: &AckMsg,
        dataLength: 16);
      goto LABEL_137;
    case 0x38u:
      if ( v4 )
        printf(format: "*cVCC_EncodeFrameResult*\n");
      goto LABEL_137;
    case 0x3Au:
      if ( v4 )
        printf(format: "End Encoding session\n");
      v37 = *((_DWORD *)v5 + 1);
      if ( g_pCurEncoder != nullptr )
      {
        if ( g_hEncodeSession == v37 )
        {
          CQTVideoFileComposer::EndMovieCreation(this: g_pCurEncoder);
          CQTVideoFileComposer::SaveMovieToFile(this: g_pCurEncoder);
          CVidCacheCmdEndEncodingResult::CVidCacheCmdEndEncodingResult(this: &AckMsg, serverHandle: v37, success: true);
          CSocketMessageBuilder::SendDataPacket(
            this: *(CSocketMessageBuilder **)(LODWORD(userContext) + 8),
            data: &AckMsg,
            dataLength: 16);
          v4 = g_bVerbose;
          goto $LN5;
        }
        if ( g_bShowErrs )
          printf(format: "Recevied command had wrong encode session handle\n");
      }
      else if ( g_bShowErrs )
      {
        printf(format: "Received command to end encoding sessions when no encoding session was active");
      }
      goto LABEL_137;
    case 0x3Bu:
$LN5:
      if ( v4 )
        printf(format: "*cVCC_EndEncodingResult*\n");
      goto LABEL_137;
    default:
      if ( g_bShowErrs )
        printf(format: "  Unknown Message received.  type = %d  overall size = %d \n", *message, v3);
      goto LABEL_137;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404F70
// Name: void mainServerLoop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mainServerLoop()
{
  SocketErrorCode_t v0; // eax
  CSocketConnection *v1; // esi
  int i; // edi
  CSocketConnection *v3; // esi
  const char *v4; // eax
  unsigned __int8 *v5; // esi
  CSocketConnection *v6; // esi
  const char *v7; // eax
  const char *LastErrorString; // [esp-10h] [ebp-8Ch]
  const char *v9; // [esp-10h] [ebp-8Ch]
  const char *LastSystemErrorString; // [esp-Ch] [ebp-88h]
  const char *v11; // [esp-Ch] [ebp-88h]
  const char *v12; // [esp-Ch] [ebp-88h]
  const char *v13; // [esp-Ch] [ebp-88h]
  CSocketMessageBuilder DataPump; // [esp+4h] [ebp-78h] BYREF
  CConnectionInfo ConInfo; // [esp+60h] [ebp-1Ch] BYREF
  unsigned __int8 *pRecvBuf; // [esp+6Ch] [ebp-10h]
  int nEndpointIdx; // [esp+70h] [ebp-Ch] BYREF
  int nBytesReceved; // [esp+74h] [ebp-8h] BYREF
  bool bCanRead; // [esp+7Bh] [ebp-1h] BYREF

  g_bRunning = true;
  nBytesReceved = 0;
  pRecvBuf = (unsigned __int8 *)operator new(size: 0x4000u);
  if ( g_bVerbose )
    printf(format: " main app loop started \n ");
  CSocketMessageBuilder::CSocketMessageBuilder(this: &DataPump, initialSize: 0, growSize: 0);
  CThreadEvent::Set(this: &g_AppStateEvent);
  while ( g_bRunning )
  {
    _ThreadSleep(a1: 5);
    nEndpointIdx = -1;
    v0 = CSocketConnection::TryAcceptIncomingConnection(this: g_IPCConnection, newEndpointIndex: &nEndpointIdx);
    if ( v0 != SOCKET_ERR_NO_INCOMING_CONNECTIONS )
    {
      if ( v0 != SOCKET_SUCCESS )
      {
        ++nErrorMessagesEmitted;
        v1 = g_IPCConnection;
        if ( v0 == SOCKET_ERR_NO_AVAILABLE_ENDPOINTS )
        {
          if ( (nMaxErrorMessages < 0 || nErrorMessagesEmitted <= nMaxErrorMessages) && g_bShowErrs )
          {
            LastSystemErrorString = CSocketConnection::GetLastSystemErrorString(this: g_IPCConnection);
            LastErrorString = CSocketConnection::GetLastErrorString(this: v1);
            printf(
              format: "ERR - The Function %s returned %s - %s \n",
              "TryAcceptIncomingConnection - out of endpoints?",
              LastErrorString,
              LastSystemErrorString);
          }
        }
        else if ( (nMaxErrorMessages < 0 || nErrorMessagesEmitted <= nMaxErrorMessages) && g_bShowErrs )
        {
          v11 = CSocketConnection::GetLastSystemErrorString(this: g_IPCConnection);
          v9 = CSocketConnection::GetLastErrorString(this: v1);
          printf(format: "ERR - The Function %s returned %s - %s \n", "TryAcceptIncomingConnection", v9, v11);
        }
      }
      else if ( g_bVerbose )
      {
        printf(format: "* Connection Established on Endpoint %d\n", nEndpointIdx);
      }
    }
    for ( i = 0; i < 2; ++i )
    {
      g_fStrobeStart = _Plat_FloatTime();
      g_QTTimeUsed = 0.0;
      if ( CSocketConnection::GetEndpointSocketState(this: g_IPCConnection, endpointIndex: i) == SSTATE_CONNECTED )
      {
        bCanRead = false;
        if ( CSocketConnection::CanReadFromEndpoint(this: g_IPCConnection, endpointIndex: i, canRead: &bCanRead) != SOCKET_SUCCESS )
        {
          ++nErrorMessagesEmitted;
          v3 = g_IPCConnection;
          if ( (nMaxErrorMessages < 0 || nErrorMessagesEmitted <= nMaxErrorMessages) && g_bShowErrs )
          {
            v12 = CSocketConnection::GetLastSystemErrorString(this: g_IPCConnection);
            v4 = CSocketConnection::GetLastErrorString(this: v3);
            printf(format: "ERR - The Function %s returned %s - %s \n", "CanReadFromEndpoint", v4, v12);
          }
        }
        if ( bCanRead )
        {
          v5 = pRecvBuf;
          nBytesReceved = 0;
          if ( CSocketConnection::ReadFromEndpoint(
                 this: g_IPCConnection,
                 endpointIndex: i,
                 destinationBuffer: pRecvBuf,
                 bufferSize: 0x4000,
                 bytesRead: &nBytesReceved) != SOCKET_SUCCESS )
          {
            ++nErrorMessagesEmitted;
            v6 = g_IPCConnection;
            if ( (nMaxErrorMessages < 0 || nErrorMessagesEmitted <= nMaxErrorMessages) && g_bShowErrs )
            {
              v13 = CSocketConnection::GetLastSystemErrorString(this: g_IPCConnection);
              v7 = CSocketConnection::GetLastErrorString(this: v6);
              printf(format: "ERR - The Function %s returned %s - %s \n", "ReadFromEndpoint", v7, v13);
            }
          }
          else if ( nBytesReceved <= 0 )
          {
            if ( g_bShowErrs )
              printf(format: "error, empty data received\n");
          }
          else
          {
            ConInfo.m_theConnection = g_IPCConnection;
            ConInfo.m_EndPointIndex = i;
            ConInfo.m_theDataPump = &DataPump;
            CSocketMessageBuilder::FeedData(
              this: &DataPump,
              data: v5,
              dataLength: nBytesReceved,
              networkMessageHandlerFunc: (void (__cdecl *)(const MessageHeader_t *, const unsigned __int8 *, void *))ProcessNetworkMessage,
              userContext: &ConInfo);
          }
        }
      }
    }
  }
  CThreadEvent::Reset(this: &g_AppStateEvent);
  CSocketMessageBuilder::~CSocketMessageBuilder(this: &DataPump);
}

//------------------------------------------------------------------------------
// Address: 0x00405210
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4; // eax
  bool v5; // bl
  int v6; // esi
  const char *v7; // edi
  char v8; // bl
  bool bRunServer; // [esp+1h] [ebp-3h]
  bool bDecodeTest; // [esp+2h] [ebp-2h]
  bool bEncodeTest; // [esp+3h] [ebp-1h]

  if ( CSingleAppInstance::CheckForOtherRunningInstances(
         this: &g_ThisAppInstance,
         exitOnNotUnique: false,
         displayMsgIfNotUnique: true) )
  {
    _Plat_MessageBox(a1: "SFM VideoCache", a2: "Another Instance of the SFM VideoCache is already running!");
    return 0;
  }
  InitCommandLineProgram(&argc, (char ***)&argv);
  v4 = argc;
  v5 = false;
  v6 = 1;
  bRunServer = false;
  bDecodeTest = false;
  bEncodeTest = false;
  if ( argc <= 1 )
    goto LABEL_28;
  do
  {
    if ( v6 >= v4 - 1 )
    {
      v7 = nullptr;
    }
    else
    {
      v7 = argv[v6 + 1];
      if ( v7 != nullptr && *v7 != 45 )
      {
        v8 = 1;
        goto LABEL_10;
      }
    }
    v8 = 0;
LABEL_10:
    if ( _V_stricmp(s1: argv[v6], s2: "-decodetest") == 0 )
      bDecodeTest = true;
    if ( _V_stricmp(s1: argv[v6], s2: "-encodetest") == 0 )
      bEncodeTest = true;
    if ( _V_stricmp(s1: argv[v6], s2: "-server") == 0 )
      bRunServer = true;
    if ( _V_stricmp(s1: argv[v6], s2: "-v") == 0 )
      g_bVerbose = true;
    if ( _V_stricmp(s1: argv[v6], s2: "-?") == 0 )
    {
      printf(format: "VideoCache command line summary\n\n");
      printf(format: "    -server\t        Runs SFM VideoCaching server (normal usage)\n");
      printf(format: "    -decodetest        Runs QuickTime H.264 Movie Frame Extraction Test\n");
      printf(format: "    -encodetest        Runs QuickTime H.264 Movie Creation from frame sequence Test\n");
      printf(format: "    -logdecode [path]  Output .BMP of decoded frames [to specifed path]\n");
      printf(format: "    -logencode [path]  Output .BMP of encoded frames [to specifed path]\n");
      printf(format: "    -v                 Display verbose event information\n");
      printf(format: "    -?                 Prints this summary\n");
    }
    if ( _V_stricmp(s1: argv[v6], s2: "-logdecode") == 0 )
    {
      g_LogDecodedFrames = true;
      g_DecodedFrameOutDir = v8 != 0 ? (char *)v7 : nullptr;
    }
    if ( _V_stricmp(s1: argv[v6], s2: "-logencode") == 0 )
    {
      g_LogEncodedFrames = true;
      g_EncodedFrameOutDir = v8 != 0 ? (char *)v7 : nullptr;
    }
    ++v6;
    if ( v8 != 0 )
      ++v6;
    v4 = argc;
  }
  while ( v6 < argc );
  v5 = bDecodeTest;
LABEL_28:
  argc = 1 - v6 + v4;
  argv = &argv[v6 - 1];
  if ( v5 )
    TestQuickTimeMovieDecoding();
  if ( bEncodeTest )
    TestQuickTimeMovieEncoding();
  if ( bRunServer )
  {
    if ( g_VideoMap.m_Tree.m_LessFunc.m_LessFunc == nullptr )
      g_VideoMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))ServerVideoHandleLessFunc;
    if ( SetupQuicktime() && InitVideoServerMode() != 0 )
      mainServerLoop();
    SocketLibShutdown();
    ExitMovies();
    TerminateQTML();
  }
  else if ( !v5 && !bEncodeTest )
  {
    PrintArgSummary();
    printf(format: " the Argument is %s\n", argv[1]);
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405480
// Name: _EnterMovies
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int EnterMovies()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004054A0
// Name: _ExitMovies
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int ExitMovies()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004054C0
// Name: _GetMoviesError
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetMoviesError()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004054E0
// Name: _MoviesTask
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int MoviesTask()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405500
// Name: _SetMovieGWorld
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int SetMovieGWorld()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405520
// Name: _DisposeMovie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int DisposeMovie()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405540
// Name: _GetMovieDuration
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetMovieDuration()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405560
// Name: _SetMovieTimeValue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int SetMovieTimeValue()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405580
// Name: _GetMediaDuration
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetMediaDuration()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004055A0
// Name: _BeginMediaEdits
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int BeginMediaEdits()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004055C0
// Name: _AddMediaSample
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int AddMediaSample()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004055E0
// Name: _CloseMovieFile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int CloseMovieFile()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405600
// Name: _AddMovieResource
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int AddMovieResource()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405620
// Name: _NewMovieFromFile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int NewMovieFromFile()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405640
// Name: _InsertMediaIntoTrack
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int InsertMediaIntoTrack()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405660
// Name: _NewMovieTrack
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int NewMovieTrack()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405680
// Name: _NewTrackMedia
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int NewTrackMedia()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004056A0
// Name: _CreateMovieFile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int CreateMovieFile()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004056C0
// Name: _OpenMovieFile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int OpenMovieFile()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004056E0
// Name: _GetNativeWindowPort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetNativeWindowPort()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405700
// Name: _QTMLInitInternals
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int QTMLInitInternals()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405720
// Name: _QTMLTermInternals
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int QTMLTermInternals()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405740
// Name: _InsideInitializeQTML
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int InsideInitializeQTML()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405760
// Name: _GetPortHDC
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetPortHDC()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405780
// Name: _GetPortHBITMAP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetPortHBITMAP()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004057A0
// Name: _NewHandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int NewHandle()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004057C0
// Name: _DisposeHandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int DisposeHandle()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x004057E0
// Name: _callQTMLInitInternals
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int callQTMLInitInternals()
{
  return QTMLInitInternals();
}

//------------------------------------------------------------------------------
// Address: 0x004057F0
// Name: _callQTMLTermInternals
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int callQTMLTermInternals()
{
  return QTMLTermInternals();
}

//------------------------------------------------------------------------------
// Address: 0x00405800
// Name: _callInsideInitializeQTML
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int callInsideInitializeQTML()
{
  return InsideInitializeQTML();
}

//------------------------------------------------------------------------------
// Address: 0x00405810
// Name: _BogusDispatcher
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 BogusDispatcher()
{
  return -2095;
}

//------------------------------------------------------------------------------
// Address: 0x00405820
// Name: sub_405820
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HGLOBAL __usercall sub_405820@<eax>(_DWORD *a1@<ebx>, LPCSTR lptstrFilename, _DWORD *a3)
{
  HGLOBAL result; // eax
  DWORD v4; // esi
  HGLOBAL v5; // edi
  _DWORD *v6; // ecx
  LPVOID lpBuffer; // [esp+8h] [ebp-Ch] BYREF
  unsigned int dwHandle; // [esp+Ch] [ebp-8h] BYREF
  unsigned int puLen; // [esp+10h] [ebp-4h] BYREF

  if ( a1 != nullptr )
    *a1 = 0;
  if ( a3 != nullptr )
    *a3 = 0;
  result = (HGLOBAL)GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle: &dwHandle);
  v4 = (DWORD)result;
  if ( result != nullptr )
  {
    v5 = GlobalAlloc(uFlags: 0x40u, dwBytes: (SIZE_T)result);
    if ( GetFileVersionInfoA(lptstrFilename, dwHandle: 0, dwLen: v4, lpData: v5)
      && VerQueryValueA(pBlock: v5, lpSubBlock: "\\", lplpBuffer: &lpBuffer, &puLen) )
    {
      v6 = lpBuffer;
      if ( a1 != nullptr )
        *a1 = *((_DWORD *)lpBuffer + 2);
      if ( a3 != nullptr )
        *a3 = v6[3];
    }
    return GlobalFree(hMem: v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004058B0
// Name: sub_4058B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_4058B0()
{
  HMODULE v0; // esi
  int v1; // edi
  unsigned __int16 v2; // cx
  unsigned __int16 v3; // dx
  int v5; // [esp+10h] [ebp-110h] BYREF
  int v6; // [esp+14h] [ebp-10Ch] BYREF
  char Filename[264]; // [esp+18h] [ebp-108h] BYREF

  v0 = QTMLInstance;
  memset(Filename, 0, 261);
  v1 = 0;
  if ( dword_434B7C == 0 )
  {
    if ( QTMLInstance == nullptr )
    {
      v0 = (HMODULE)QTLoadLibrary(a1: "QuickTime.qts");
      if ( v0 == nullptr )
        return dword_434B80;
      v1 = 1;
    }
    if ( GetModuleFileNameA(hModule: v0, lpFilename: Filename, nSize: 0x105u) != 0 )
    {
      v6 = 0;
      v5 = 0;
      sub_405820(a1: &v6, lptstrFilename: Filename, a3: &v5);
      LOBYTE(v2) = 0;
      HIBYTE(v2) = v6;
      LOBYTE(v3) = 0;
      HIBYTE(v3) = BYTE2(v5);
      if ( ((unsigned __int8)v5 | v3 | ((v6 & 0xFFFF0000 | v2) << 8)) >= 0x7000200 )
        dword_434B80 = 1;
    }
    if ( v1 != 0 )
      FreeLibrary(hLibModule: v0);
    dword_434B7C = 1;
  }
  return dword_434B80;
}

//------------------------------------------------------------------------------
// Address: 0x004059A0
// Name: sub_4059A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 sub_4059A0()
{
  _CallComponentFunctionWithStorageAddr = GetProcAddress(
                                            hModule: QTMLInstance,
                                            lpProcName: "_CallComponentFunctionWithStorage");
  if ( _CallComponentFunctionWithStorageAddr == nullptr )
    return -2094;
  _CallComponentAddr[0] = GetProcAddress(hModule: QTMLInstance, lpProcName: "_CallComponent");
  if ( _CallComponentAddr[0] == nullptr )
    return -2094;
  theQTMLDispatcherAddr = GetProcAddress(hModule: QTMLInstance, lpProcName: "theQuickTimeDispatcher");
  if ( theQTMLDispatcherAddr == nullptr )
    return -2094;
  autoPatchThoseAddressesAddr = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405A00
// Name: _InitializeQTML
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 InitializeQTML()
{
  __int16 v0; // si
  DWORD CurrentProcessId; // eax
  HANDLE MutexA; // eax
  void *v3; // edi
  char Name[256]; // [esp+8h] [ebp-100h] BYREF

  v0 = 0;
  CurrentProcessId = GetCurrentProcessId();
  _wsprintfA(a1: Name, a2: "QTMLInitTermMutex%lx", CurrentProcessId);
  MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: Name);
  v3 = MutexA;
  if ( MutexA != nullptr )
    WaitForSingleObject(hHandle: MutexA, dwMilliseconds: 0xFFFFFFFF);
  if ( dword_434B74 > 0 )
  {
    ++dword_434B74;
    goto LABEL_10;
  }
  QTMLInstance = (HMODULE)QTLoadLibrary(a1: "QuickTime.qts");
  if ( QTMLInstance != nullptr )
  {
    v0 = sub_4059A0();
    if ( v0 == 0 )
    {
      v0 = callQTMLInitInternals();
      if ( v0 == 0 )
      {
        ++dword_434B74;
        goto LABEL_10;
      }
    }
  }
  else
  {
    GetLastError();
    v0 = -2093;
  }
  if ( QTMLInstance != nullptr )
  {
    FreeLibrary(hLibModule: QTMLInstance);
    QTMLInstance = nullptr;
  }
  autoPatchThoseAddressesAddr = (_DWORD (*)())sub_4059A0;
  _CallComponentAddr[0] = (int (*)())BogusDispatcher;
  _CallComponentFunctionWithStorageAddr = (int (*)())BogusDispatcher;
  theQTMLDispatcherAddr = (_DWORD (*)())BogusDispatcher;
LABEL_10:
  if ( v3 != nullptr )
  {
    ReleaseMutex(hMutex: v3);
    CloseHandle(hObject: v3);
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x00405B00
// Name: _TerminateQTML
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int TerminateQTML()
{
  DWORD CurrentProcessId; // eax
  HANDLE MutexA; // eax
  void *v2; // esi
  int result; // eax
  char Name[256]; // [esp+4h] [ebp-100h] BYREF

  CurrentProcessId = GetCurrentProcessId();
  _wsprintfA(a1: Name, a2: "QTMLInitTermMutex%lx", CurrentProcessId);
  MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: Name);
  v2 = MutexA;
  if ( MutexA != nullptr )
    WaitForSingleObject(hHandle: MutexA, dwMilliseconds: 0xFFFFFFFF);
  result = dword_434B74;
  if ( dword_434B74 > 0 )
  {
    result = dword_434B74 - 1;
    dword_434B74 = result;
    if ( result <= 0 )
    {
      callQTMLTermInternals();
      autoPatchThoseAddressesAddr = (_DWORD (*)())sub_4059A0;
      _CallComponentAddr[0] = (int (*)())BogusDispatcher;
      _CallComponentFunctionWithStorageAddr = (int (*)())BogusDispatcher;
      theQTMLDispatcherAddr = (_DWORD (*)())BogusDispatcher;
      result = FreeLibrary(hLibModule: QTMLInstance);
    }
  }
  else
  {
    dword_434B74 = 0;
  }
  if ( v2 != nullptr )
  {
    ReleaseMutex(hMutex: v2);
    return CloseHandle(hObject: v2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405BB0
// Name: sub_405BB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 sub_405BB0()
{
  int v0; // esi
  HMODULE v1; // eax

  v0 = 0;
  if ( QTMLInstance == nullptr )
  {
    v1 = (HMODULE)QTLoadLibrary(a1: "QuickTime.qts");
    QTMLInstance = v1;
    if ( v1 == nullptr )
      return (__int16)v1;
    v0 = 1;
  }
  LOWORD(v1) = sub_4059A0();
  if ( v0 != 0 )
  {
    v1 = (HMODULE)sub_4058B0();
    if ( v1 != nullptr )
    {
      LOWORD(v1) = callInsideInitializeQTML();
      if ( (_BYTE)v1 != 0 )
      {
        LOWORD(v1) = FreeLibrary(hLibModule: QTMLInstance);
        QTMLInstance = nullptr;
      }
    }
  }
  return (__int16)v1;
}

//------------------------------------------------------------------------------
// Address: 0x00405C20
// Name: _GetMaxCompressionSize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 GetMaxCompressionSize()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405C40
// Name: _CompressImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 CompressImage()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405C60
// Name: _QTNewGWorld
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 QTNewGWorld()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405C80
// Name: _QTSetPixMapHandleGammaLevel
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 QTSetPixMapHandleGammaLevel()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405CA0
// Name: _QTSetPixMapHandleRequestedGammaLevel
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 QTSetPixMapHandleRequestedGammaLevel()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405CC0
// Name: _FSMakeFSSpec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 FSMakeFSSpec()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405CE0
// Name: _c2pstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 c2pstr()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405D00
// Name: _LockPixels
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 LockPixels()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405D20
// Name: _UnlockPixels
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 UnlockPixels()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405D40
// Name: _DisposeGWorld
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 DisposeGWorld()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405D60
// Name: _SetGWorld
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 SetGWorld()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405D80
// Name: _GetGWorldPixMap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 GetGWorldPixMap()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405DA0
// Name: _MacSetRect
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 MacSetRect()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405DC0
// Name: _FixRatio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 FixRatio()
{
  if ( autoPatchThoseAddressesAddr != nullptr )
    autoPatchThoseAddressesAddr();
  return theQTMLDispatcherAddr();
}

//------------------------------------------------------------------------------
// Address: 0x00405DDA
// Name: VerQueryValueA(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall VerQueryValueA(LPCVOID pBlock, LPCSTR lpSubBlock, LPVOID *lplpBuffer, PUINT puLen)
{
  return __imp__VerQueryValueA@16(pBlock, lpSubBlock, lplpBuffer, puLen);
}

//------------------------------------------------------------------------------
// Address: 0x00405DE0
// Name: GetFileVersionInfoA(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall GetFileVersionInfoA(LPCSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
  return __imp__GetFileVersionInfoA@16(lptstrFilename, dwHandle, dwLen, lpData);
}

//------------------------------------------------------------------------------
// Address: 0x00405DE6
// Name: GetFileVersionInfoSizeA(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall GetFileVersionInfoSizeA(LPCSTR lptstrFilename, LPDWORD lpdwHandle)
{
  return __imp__GetFileVersionInfoSizeA@8(lptstrFilename, lpdwHandle);
}

//------------------------------------------------------------------------------
// Address: 0x00405DF0
// Name: _GetQTFolderFromRegistry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HKEY __cdecl GetQTFolderFromRegistry(LPCSTR lpSubKey, LPCSTR lpValueName, char *lpData, unsigned int cbData)
{
  HKEY result; // eax
  HKEY phkResult; // [esp+4h] [ebp-4h] BYREF

  phkResult = nullptr;
  *lpData = 0;
  if ( RegOpenKeyExA(hKey: HKEY_LOCAL_MACHINE, lpSubKey, ulOptions: 0, samDesired: 1u, &phkResult) == 0 )
  {
    result = phkResult;
    if ( phkResult == nullptr )
      return result;
    if ( RegQueryValueExA(
           hKey: phkResult,
           lpValueName,
           lpReserved: nullptr,
           lpType: nullptr,
           (LPBYTE)lpData,
           lpcbData: &cbData) == 0
      && *lpData != 0
      && lpData[strlen(lpData) - 1] != 92
      && lpData[strlen(lpData) - 1] != 47 )
    {
      strcat(lpData, "\\");
    }
  }
  result = phkResult;
  if ( phkResult != nullptr )
    return (HKEY)RegCloseKey(hKey: phkResult);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405EA0
// Name: _GetPathToQuickTimeFolder
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl GetPathToQuickTimeFolder(unsigned __int8 *dest, UINT uSize, _DWORD *a3)
{
  BOOL result; // eax
  HMODULE ModuleHandleA; // eax
  unsigned int v5; // kr00_4
  unsigned int v6; // edi
  char Filename[260]; // [esp+4h] [ebp-104h] BYREF

  result = 0;
  if ( dest != nullptr )
  {
    *dest = 0;
    if ( a3 != nullptr )
      *a3 = 0;
    ModuleHandleA = GetModuleHandleA(lpModuleName: "QuickTime.qts");
    if ( ModuleHandleA != nullptr
      && GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: Filename, nSize: 0x104u) != 0
      && (v5 = strlen(Filename), v6 = v5 - 13, v5 != 13)
      && uSize > v6 + 1 )
    {
      strncpy(dest, source: (unsigned __int8 *)Filename, count: v5 - 13);
      dest[v6] = 0;
    }
    else
    {
      if ( *dest != 0 )
        goto LABEL_22;
      GetQTFolderFromRegistry(
        lpSubKey: "Software\\Apple Computer, Inc.\\QuickTime",
        lpValueName: "QTSysDir",
        lpData: (char *)dest,
        cbData: uSize);
      if ( *dest == 0 || _access(path: (const char *)dest, amode: 0) != 0 )
        *dest = 0;
      if ( *dest != 0 )
        goto LABEL_22;
      GetQTFolderFromRegistry(
        lpSubKey: "Software\\Apple Computer, Inc.\\QuickTime",
        lpValueName: "QuickTime.qts folder",
        lpData: (char *)dest,
        cbData: uSize);
      if ( *dest == 0 || _access(path: (const char *)dest, amode: 0) != 0 )
        *dest = 0;
      if ( *dest != 0 )
        goto LABEL_22;
      if ( GetSystemDirectoryA(lpBuffer: (LPSTR)dest, uSize) == 0 || _access(path: (const char *)dest, amode: 0) != 0 )
        *dest = 0;
    }
    if ( *dest == 0 )
      return *dest != 0;
LABEL_22:
    if ( dest[strlen((const char *)dest) - 1] != 92 && dest[strlen((const char *)dest) - 1] != 47 )
      strcat((char *)dest, "\\");
    return *dest != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406020
// Name: _GetQTExtensionDirectoryA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl GetQTExtensionDirectoryA(char *lpData, unsigned int cbData)
{
  char *v2; // edi
  char v3; // al
  char v5; // [esp+7h] [ebp-209h] BYREF
  char Buffer[260]; // [esp+8h] [ebp-208h] BYREF
  unsigned __int8 dest[260]; // [esp+10Ch] [ebp-104h] BYREF

  GetQTFolderFromRegistry(
    lpSubKey: "Software\\Apple Computer, Inc.\\QuickTime",
    lpValueName: "QTExtDir",
    lpData,
    cbData);
  if ( *lpData == 0 )
  {
    GetSystemDirectoryA(lpBuffer: Buffer, uSize: cbData - 10);
    GetPathToQuickTimeFolder(dest, uSize: cbData - 10, a3: nullptr);
    if ( dest[0] != 0 )
    {
      if ( Buffer[strlen(Buffer) - 1] != 92 && Buffer[strlen(Buffer) - 1] != 47 )
      {
        v2 = &v5;
        do
          v3 = *++v2;
        while ( v3 != 0 );
        strcpy(v2, "\\");
      }
      strcpy(lpData, (const char *)dest);
      if ( strcmp(Buffer, (const char *)dest) == 0 )
        strcat(lpData, "QuickTime\\");
    }
  }
  return strlen(lpData);
}

//------------------------------------------------------------------------------
// Address: 0x00406180
// Name: _QTLoadLibrary
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __cdecl QTLoadLibrary(const char *a1)
{
  unsigned int v1; // kr00_4
  int v2; // eax
  unsigned __int8 v3; // cl
  unsigned int v4; // eax
  char *v5; // edi
  char v6; // cl
  HMODULE LibraryA; // esi
  int v8; // eax
  unsigned __int8 v9; // cl
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  char v14; // [esp+Bh] [ebp-209h] BYREF
  char LibFileName[260]; // [esp+Ch] [ebp-208h] BYREF
  char dest[260]; // [esp+110h] [ebp-104h] BYREF

  dest[0] = 0;
  v1 = strlen(a1);
  if ( !GetPathToQuickTimeFolder((unsigned __int8 *)dest, uSize: 260 - v1, a3: nullptr) )
    return nullptr;
  v2 = 0;
  do
  {
    v3 = dest[v2];
    LibFileName[v2++] = v3;
  }
  while ( v3 != 0 );
  v4 = strlen(a1) + 1;
  v5 = &v14;
  do
    v6 = *++v5;
  while ( v6 != 0 );
  qmemcpy(v5, a1, v4);
  LibraryA = LoadLibraryA(lpLibFileName: LibFileName);
  if ( LibraryA != nullptr )
    return LibraryA;
  GetLastError();
  if ( GetQTExtensionDirectoryA(lpData: dest, cbData: 260 - v1) == 0 )
    return LibraryA;
  v8 = 0;
  do
  {
    v9 = dest[v8];
    LibFileName[v8++] = v9;
  }
  while ( v9 != 0 );
  v10 = strlen(a1) + 1;
  v11 = &v14;
  do
    v12 = *++v11;
  while ( v12 != 0 );
  qmemcpy(v11, a1, v10);
  return LoadLibraryA(lpLibFileName: LibFileName);
}
