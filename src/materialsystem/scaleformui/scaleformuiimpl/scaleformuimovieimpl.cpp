// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuimovieimpl.cpp
// Functions: 21
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuimovieimpl.h"

//------------------------------------------------------------------------------
// Address: 0x100124B0
// Name: public: virtual void ScaleformUIImpl::MovieView_Advance(void __near *,float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::MovieView_Advance(
        ScaleformUIImpl *this,
        void *movieView,
        float time,
        unsigned int frameCatchUpCount)
{
  (*(void (__stdcall **)(_DWORD, unsigned int))(*(_DWORD *)movieView + 148))(a1: LODWORD(time), a2: frameCatchUpCount);
}

//------------------------------------------------------------------------------
// Address: 0x100124E0
// Name: public: virtual void ScaleformUIImpl::MovieView_SetBackgroundAlpha(void __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::MovieView_SetBackgroundAlpha(ScaleformUIImpl *this, void *movieView, float alpha)
{
  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)movieView + 172))(a1: LODWORD(alpha));
}

//------------------------------------------------------------------------------
// Address: 0x10012500
// Name: public: virtual void ScaleformUIImpl::MovieView_SetViewport(void __near *,int,int,int,int,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::MovieView_SetViewport(
        ScaleformUIImpl *this,
        void *movieView,
        int bufw,
        int bufh,
        int left,
        int top,
        int w,
        int h,
        unsigned int flags)
{
  void (__thiscall *v9)(void *, _DWORD *); // edx
  _DWORD v10[13]; // [esp+0h] [ebp-34h] BYREF

  v10[0] = bufw;
  v10[3] = top;
  v10[1] = bufh;
  v10[2] = left;
  v10[12] = flags;
  v10[4] = w;
  v10[5] = h;
  v9 = *(void (__thiscall **)(void *, _DWORD *))(*(_DWORD *)movieView + 100);
  memset(&v10[6], 0, 16);
  v10[11] = 1065353216;
  v10[10] = 1065353216;
  v9(a1: movieView, a2: v10);
}

//------------------------------------------------------------------------------
// Address: 0x10012570
// Name: public: virtual void ScaleformUIImpl::MovieView_Display(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::MovieView_Display(ScaleformUIImpl *this, void *movieView)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)movieView + 152))(a1: movieView);
}

//------------------------------------------------------------------------------
// Address: 0x10012590
// Name: public: virtual void ScaleformUIImpl::MovieView_SetViewScaleMode(void __near *,enum IScaleformUI::ScaleModeType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::MovieView_SetViewScaleMode(
        ScaleformUIImpl *this,
        void *movieView,
        IScaleformUI::ScaleModeType type)
{
  (*(void (__thiscall **)(void *, IScaleformUI::ScaleModeType))(*(_DWORD *)movieView + 108))(a1: movieView, a2: type);
}

//------------------------------------------------------------------------------
// Address: 0x100125B0
// Name: public: virtual enum IScaleformUI::ScaleModeType ScaleformUIImpl::MovieView_GetViewScaleMode(void __near *)
// Source: json
//------------------------------------------------------------------------------
IScaleformUI::ScaleModeType __thiscall ScaleformUIImpl::MovieView_GetViewScaleMode(
        ScaleformUIImpl *this,
        void *movieView)
{
  return (*(IScaleformUI::ScaleModeType (__thiscall **)(void *))(*(_DWORD *)movieView + 112))(a1: movieView);
}

//------------------------------------------------------------------------------
// Address: 0x100125D0
// Name: public: virtual void ScaleformUIImpl::MovieView_SetViewAlignment(void __near *,enum IScaleformUI::AlignType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::MovieView_SetViewAlignment(
        ScaleformUIImpl *this,
        void *movieView,
        IScaleformUI::AlignType type)
{
  (*(void (__thiscall **)(void *, IScaleformUI::AlignType))(*(_DWORD *)movieView + 116))(a1: movieView, a2: type);
}

//------------------------------------------------------------------------------
// Address: 0x100125F0
// Name: public: virtual enum IScaleformUI::AlignType ScaleformUIImpl::MovieView_GetViewAlignment(void __near *)
// Source: json
//------------------------------------------------------------------------------
IScaleformUI::AlignType __thiscall ScaleformUIImpl::MovieView_GetViewAlignment(ScaleformUIImpl *this, void *movieView)
{
  return (*(IScaleformUI::AlignType (__thiscall **)(void *))(*(_DWORD *)movieView + 120))(a1: movieView);
}

//------------------------------------------------------------------------------
// Address: 0x10012610
// Name: public: virtual void __near * ScaleformUIImpl::MovieView_CreateString(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::MovieView_CreateString(ScaleformUIImpl *this, void *movieView, const char *str)
{
  GFxValue *GFxValue; // esi

  GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
  (*(void (__thiscall **)(void *, GFxValue *, const char *))(*(_DWORD *)movieView + 44))(
    a1: movieView,
    a2: GFxValue,
    a3: str);
  return GFxValue;
}

//------------------------------------------------------------------------------
// Address: 0x10012640
// Name: public: virtual void __near * ScaleformUIImpl::MovieView_CreateStringW(void __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::MovieView_CreateStringW(
        ScaleformUIImpl *this,
        void *movieView,
        const wchar_t *str)
{
  GFxValue *GFxValue; // esi

  GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
  (*(void (__thiscall **)(void *, GFxValue *, const wchar_t *))(*(_DWORD *)movieView + 48))(
    a1: movieView,
    a2: GFxValue,
    a3: str);
  return GFxValue;
}

//------------------------------------------------------------------------------
// Address: 0x10012670
// Name: public: virtual void __near * ScaleformUIImpl::MovieView_CreateObject(void __near *,char const __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::MovieView_CreateObject(
        ScaleformUIImpl *this,
        void *movieView,
        const char *className,
        void *args,
        unsigned int numArgs)
{
  GFxValue *GFxValue; // esi

  GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
  (*(void (__thiscall **)(void *, GFxValue *, const char *, void *, unsigned int))(*(_DWORD *)movieView + 52))(
    a1: movieView,
    a2: GFxValue,
    a3: className,
    a4: args,
    a5: numArgs);
  return GFxValue;
}

//------------------------------------------------------------------------------
// Address: 0x100126A0
// Name: public: virtual void __near * ScaleformUIImpl::MovieView_CreateArray(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::MovieView_CreateArray(ScaleformUIImpl *this, void *movieView, unsigned int size)
{
  GFxValue *GFxValue; // esi

  GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
  (*(void (__thiscall **)(void *, GFxValue *))(*(_DWORD *)movieView + 56))(a1: movieView, a2: GFxValue);
  if ( size != -1 )
    GFxValue::ObjectInterface::SetArraySize(
      this: GFxValue->pObjectInterface,
      a2: GFxValue->Value.pStringManaged,
      a3: size);
  return GFxValue;
}

//------------------------------------------------------------------------------
// Address: 0x100126E0
// Name: public: virtual unsigned int ScaleformUIImpl::MovieView_HandleMouseEvent(void __near *,enum IScaleformUI::EventType,unsigned int,float,float,float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ScaleformUIImpl::MovieView_HandleMouseEvent(
        ScaleformUIImpl *this,
        void *movieView,
        IScaleformUI::EventType type,
        unsigned int button,
        float xpos,
        float ypos,
        float scrollVal,
        unsigned int mouseIdx)
{
  unsigned int (__thiscall *v8)(void *, GFxMouseEvent *); // eax
  GFxMouseEvent mevent; // [esp+0h] [ebp-18h] BYREF

  mevent.Button = button;
  mevent.Type = type;
  v8 = *(unsigned int (__thiscall **)(void *, GFxMouseEvent *))(*(_DWORD *)movieView + 180);
  mevent.x = xpos;
  mevent.MouseIndex = mouseIdx;
  mevent.y = ypos;
  mevent.ScrollDelta = scrollVal;
  return v8(a1: movieView, a2: &mevent);
}

//------------------------------------------------------------------------------
// Address: 0x10012730
// Name: public: virtual unsigned int ScaleformUIImpl::MovieView_HandleCharEvent(void __near *,unsigned int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ScaleformUIImpl::MovieView_HandleCharEvent(
        ScaleformUIImpl *this,
        void *movieView,
        unsigned int wcharCode,
        unsigned __int8 keyboardIndex)
{
  unsigned int (__thiscall *v4)(void *, GFxCharEvent *); // edx
  GFxCharEvent cevent; // [esp+0h] [ebp-Ch] BYREF

  cevent.KeyboardIndex = keyboardIndex;
  v4 = *(unsigned int (__thiscall **)(void *, GFxCharEvent *))(*(_DWORD *)movieView + 180);
  cevent.WcharCode = wcharCode;
  cevent.Type = CharEvent;
  return v4(a1: movieView, a2: &cevent);
}

//------------------------------------------------------------------------------
// Address: 0x10012760
// Name: public: virtual unsigned int ScaleformUIImpl::MovieView_HandleKeyEvent(void __near *,enum IScaleformUI::KeyCode,bool,unsigned int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ScaleformUIImpl::MovieView_HandleKeyEvent(
        ScaleformUIImpl *this,
        void *movieView,
        IScaleformUI::KeyCode keyCode,
        bool down,
        unsigned int mods,
        unsigned __int8 asciiCode)
{
  GFxKeyEvent keyEvent; // [esp+4h] [ebp-14h] BYREF

  if ( movieView != nullptr
    && (memset(&keyEvent, 0, 9),
        keyEvent.WcharCode = 0,
        *(_WORD *)&keyEvent.SpecialKeysState.States = 0,
        ScaleformUIImpl::InitKeyEvent(this, &keyEvent, (GFxKey::Code)keyCode, down, mods, asciiCode) != 0) )
  {
    return (*(unsigned int (__thiscall **)(void *, GFxKeyEvent *))(*(_DWORD *)movieView + 180))(
             a1: movieView,
             a2: &keyEvent);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100127C0
// Name: public: virtual bool ScaleformUIImpl::MovieView_HitTest(void __near *,float,float,enum IScaleformUI::HitTestType,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::MovieView_HitTest(
        ScaleformUIImpl *this,
        void *movieView,
        float x,
        float y,
        IScaleformUI::HitTestType testCond,
        unsigned int controllerIdx)
{
  return (*(bool (__thiscall **)(void *, _DWORD, _DWORD, IScaleformUI::HitTestType, unsigned int))(*(_DWORD *)movieView
                                                                                                 + 192))(
           a1: movieView,
           a2: LODWORD(x),
           a3: LODWORD(y),
           a4: testCond,
           a5: controllerIdx);
}

//------------------------------------------------------------------------------
// Address: 0x10012800
// Name: public: virtual void __near * ScaleformUIImpl::MovieView_GetVariable(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::MovieView_GetVariable(
        ScaleformUIImpl *this,
        void *movieView,
        const char *variablePath)
{
  unsigned __int8 (__thiscall *v4)(void *, GFxValue *, const char *); // eax
  GFxValue *v5; // esi
  GFxValue var; // [esp+8h] [ebp-1Ch] BYREF
  int v8; // [esp+20h] [ebp-4h]

  var.pObjectInterface = nullptr;
  var.Type = VT_Undefined;
  v4 = *(unsigned __int8 (__thiscall **)(void *, GFxValue *, const char *))(*(_DWORD *)movieView + 68);
  v8 = 0;
  v5 = nullptr;
  if ( v4(a1: movieView, a2: &var, a3: variablePath) != 0 )
    v5 = ScaleformUIImpl::CreateGFxValue(this, pValue: &var);
  v8 = -1;
  if ( (var.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)var.pObjectInterface, val: (StringPoolCase_t)&var);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10012890
// Name: public: virtual void ScaleformUIImpl::ReleaseMovieDef(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ReleaseMovieDef(ScaleformUIImpl *this, IShaderDevice *movieDef)
{
  tagMETAFILEPICT *MaterialPage; // esi
  int m_Size; // ecx
  int v5; // esi
  GFxMovieDef **i; // eax
  int v7; // eax
  int v8; // ecx
  tagMETAFILEPICT *v9; // [esp+0h] [ebp-Ch]

  MaterialPage = CMaterialSubRect::GetMaterialPage(result: v9);
  GFxResource::Release(this: movieDef);
  if ( MaterialPage == (tagMETAFILEPICT *)1 )
  {
    m_Size = this->m_MovieDefCache.m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_MovieDefCache.m_Memory.m_pMemory; *i != (GFxMovieDef *)movieDef; ++i )
      {
        if ( ++v5 >= m_Size )
          return;
      }
      free(pMem: (void *)this->m_MovieDefNameCache.m_Memory.m_pMemory[v5]);
      v7 = this->m_MovieDefCache.m_Size;
      if ( v7 > 0 )
      {
        if ( v5 != v7 - 1 )
          this->m_MovieDefCache.m_Memory.m_pMemory[v5] = this->m_MovieDefCache.m_Memory.m_pMemory[v7 - 1];
        --this->m_MovieDefCache.m_Size;
      }
      v8 = this->m_MovieDefNameCache.m_Size;
      if ( v8 > 0 )
      {
        if ( v5 != v8 - 1 )
          this->m_MovieDefNameCache.m_Memory.m_pMemory[v5] = this->m_MovieDefNameCache.m_Memory.m_pMemory[v8 - 1];
        --this->m_MovieDefNameCache.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012990
// Name: public: virtual void ScaleformUIImpl::ReleaseMovieView(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ReleaseMovieView(ScaleformUIImpl *this, void *movieView)
{
  void *v2; // esi

  v2 = movieView;
  if ( movieView != nullptr )
  {
    CUtlVector<GFxMovieView *,CUtlMemory<GFxMovieView *,int>>::FindAndFastRemove(
      this: &this->m_MovieViews,
      src: (GFxMovieView *const *)&movieView);
    (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 276))(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100129C0
// Name: public: virtual void __near * ScaleformUIImpl::CreateMovieDef(char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IShaderDevice *__thiscall ScaleformUIImpl::CreateMovieDef(
        ScaleformUIImpl *this,
        char *pfilename,
        unsigned int loadConstants,
        GFxMovieDef *memoryArena)
{
  int v5; // esi
  IShaderDevice *v6; // esi
  int m_Size; // ebx
  GFxMovieDef *v8; // eax
  int m_nAllocationCount; // eax
  GFxMovieDef **m_pMemory; // ecx
  int v11; // eax
  GFxMovieDef **v12; // ebx
  int v13; // eax
  char *v14; // ebx
  int v15; // eax
  CUtlMemory<S3RGBA,int> *p_m_MovieDefNameCache; // esi
  int v17; // edi
  S3RGBA *v18; // ecx
  int v19; // eax
  IShaderDevice *result; // eax
  char **v21; // edi
  VertexShaderHandle_t__ *v22; // [esp+0h] [ebp-8h]
  GFxMovieDef *presult; // [esp+18h] [ebp+10h]

  v5 = 0;
  if ( this->m_MovieDefNameCache.m_Size > 0 )
  {
    while ( _V_stricmp(s1: this->m_MovieDefNameCache.m_Memory.m_pMemory[v5], s2: pfilename) != 0 )
    {
      if ( ++v5 >= this->m_MovieDefNameCache.m_Size )
        goto LABEL_6;
    }
    v6 = (IShaderDevice *)this->m_MovieDefCache.m_Memory.m_pMemory[v5];
    GRefCountImpl::AddRef(this: v6, a2: v22);
    if ( v6 != nullptr )
      return v6;
  }
LABEL_6:
  GFxLoader::CreateMovie(this: (CMatRenderContextBase *)this->m_pLoader, (ITexture *)pfilename, loadConstants);
  m_Size = this->m_MovieDefCache.m_Size;
  presult = v8;
  m_nAllocationCount = this->m_MovieDefCache.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IMaterialVar *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_MovieDefCache,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_MovieDefCache.m_Size;
  m_pMemory = this->m_MovieDefCache.m_Memory.m_pMemory;
  v11 = this->m_MovieDefCache.m_Size - m_Size - 1;
  this->m_MovieDefCache.m_pElements = m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_MovieDefCache.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = presult;
  v13 = _V_strlen(str: pfilename);
  v14 = (char *)MemAlloc_Alloc(nSize: v13 + 1);
  _V_strcpy(dest: v14, src: pfilename);
  v15 = this->m_MovieDefNameCache.m_Memory.m_nAllocationCount;
  p_m_MovieDefNameCache = (CUtlMemory<S3RGBA,int> *)&this->m_MovieDefNameCache;
  v17 = this->m_MovieDefNameCache.m_Size;
  if ( v17 + 1 > v15 )
    CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_MovieDefNameCache, num: v17 - v15 + 1);
  ++p_m_MovieDefNameCache[1].m_pMemory;
  v18 = p_m_MovieDefNameCache->m_pMemory;
  v19 = (int)p_m_MovieDefNameCache[1].m_pMemory - v17 - 1;
  p_m_MovieDefNameCache[1].m_nAllocationCount = (int)p_m_MovieDefNameCache->m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &v18[v17 + 1], src: &v18[v17], count: 4 * v19);
  result = (IShaderDevice *)presult;
  v21 = (char **)&p_m_MovieDefNameCache->m_pMemory[v17];
  if ( v21 != nullptr )
    *v21 = v14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012B20
// Name: public: virtual void __near * ScaleformUIImpl::MovieDef_CreateInstance(void __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxMovieView *__userpurge ScaleformUIImpl::MovieDef_CreateInstance@<eax>(
        ScaleformUIImpl *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        void *movieDef,
        int initFirstFrame,
        unsigned int memoryArena)
{
  int (__thiscall *v8)(void *, _DWORD *, int, int, int, int); // edx
  GFxMovieView *result; // eax
  GFxMovieView *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  GFxMovieView **m_pMemory; // ecx
  int v14; // eax
  GFxMovieView **v15; // eax
  _DWORD v17[11]; // [esp+0h] [ebp-2Ch] BYREF

  v17[2] = 0x2000;
  v17[3] = 0x2000;
  v17[4] = -1;
  v17[9] = -1;
  v17[10] = -1;
  v17[7] = memoryArena;
  v8 = *(int (__thiscall **)(void *, _DWORD *, int, int, int, int))(*(_DWORD *)movieDef + 96);
  v17[0] = 0;
  v17[1] = 16;
  v17[5] = 0;
  v17[6] = 0;
  v17[8] = 1048576000;
  result = (GFxMovieView *)v8(a1: movieDef, a2: v17, a3: initFirstFrame, a4: a3, a5: a4, a6: a2);
  v10 = result;
  if ( result != nullptr )
  {
    m_Size = this->m_MovieViews.m_Size;
    m_nAllocationCount = this->m_MovieViews.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IMaterialVar *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_MovieViews,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_MovieViews.m_Size;
    m_pMemory = this->m_MovieViews.m_Memory.m_pMemory;
    v14 = this->m_MovieViews.m_Size - m_Size - 1;
    this->m_MovieViews.m_pElements = m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
    v15 = &this->m_MovieViews.m_Memory.m_pMemory[m_Size];
    if ( v15 != nullptr )
      *v15 = v10;
    return v10;
  }
  return result;
}
